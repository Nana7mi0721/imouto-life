//! Output engine: owns a cpal output stream (or a silent null backend) and a [`Mixer`].
//!
//! `Engine::new()` never fails. If no audio device is available it logs a line and falls back to
//! a null backend whose [`Engine::render_offline`] still produces mixed samples, so a headless CI
//! run and a desktop run share the same code path.

use std::collections::HashSet;
use std::path::{Path, PathBuf};
use std::sync::{Arc, Mutex, MutexGuard};

use cpal::traits::{DeviceTrait, HostTrait, StreamTrait};
use cpal::{FromSample, SampleFormat, SizedSample, Stream, StreamConfig};

use wolf_vm::{SoundAction, SoundChannel, SoundCmd};

use crate::decode::{decode_file, DecodedAudio};
use crate::mixer::Mixer;
use crate::AudioError;

enum Backend {
    Cpal,
    Null,
}

/// The M4 audio engine.
pub struct Engine {
    mixer: Arc<Mutex<Mixer>>,
    sample_rate: u32,
    channels: u16,
    backend: Backend,
    asset_root: PathBuf,
    /// Optional mod roots, highest priority last (a later overlay wins a name clash).
    overlays: Vec<PathBuf>,
    _stream: Option<Stream>,
    warned: HashSet<String>,
    /// Path of the track currently on the BGM bus (for same-track no-restart).
    bgm_file: Option<String>,
    /// Path of the track currently on the BGS bus.
    bgs_file: Option<String>,
}

impl Engine {
    /// Create an engine for the current working directory, using the default output device when
    /// available and a silent null backend otherwise.
    pub fn new() -> Self {
        let root = std::env::current_dir().unwrap_or_else(|_| PathBuf::from("."));
        Self::with_asset_root(root)
    }

    /// Create an engine rooted at `root` (the directory that contains `BGM/` and `SE/`).
    pub fn with_asset_root(root: impl Into<PathBuf>) -> Self {
        Self::with_overlays(root, Vec::new())
    }

    /// Create an engine rooted at `root` with zero or more mod overlay roots.
    ///
    /// Overlays mirror the data tree (`overlay/BGM/theme.ogg`, `overlay/SE/click.ogg`);
    /// a later overlay has priority over an earlier one, and all overlays have priority
    /// over the base root. The first existing file wins.
    pub fn with_overlays(root: impl Into<PathBuf>, overlays: Vec<PathBuf>) -> Self {
        let root = root.into();
        match Self::try_cpal(root.clone(), overlays.clone()) {
            Ok(engine) => engine,
            Err(err) => {
                eprintln!(
                    "[wolf-audio] audio output unavailable ({err}); using silent null backend"
                );
                Self::null_with_root_and(48_000, 2, root, overlays)
            }
        }
    }

    /// Create an engine that never touches the audio device (useful for tests / headless).
    pub fn null() -> Self {
        Self::null_with(48_000, 2)
    }

    pub fn null_with(sample_rate: u32, channels: u16) -> Self {
        Self::null_with_root_and(sample_rate, channels, PathBuf::from("."), Vec::new())
    }

    /// A silent engine rooted at `root` with mod overlays; deterministic for tests.
    pub fn null_with_overlays(root: impl Into<PathBuf>, overlays: Vec<PathBuf>) -> Self {
        Self::null_with_root_and(48_000, 2, root.into(), overlays)
    }

    fn null_with_root_and(
        sample_rate: u32,
        channels: u16,
        root: PathBuf,
        overlays: Vec<PathBuf>,
    ) -> Self {
        Engine {
            mixer: Arc::new(Mutex::new(Mixer::new(sample_rate, channels))),
            sample_rate,
            channels,
            backend: Backend::Null,
            asset_root: root,
            overlays,
            _stream: None,
            warned: HashSet::new(),
            bgm_file: None,
            bgs_file: None,
        }
    }

    fn try_cpal(root: PathBuf, overlays: Vec<PathBuf>) -> Result<Self, String> {
        let host = cpal::default_host();
        let device = host
            .default_output_device()
            .ok_or_else(|| "no default output device".to_string())?;
        let supported = device
            .default_output_config()
            .map_err(|e| format!("default_output_config: {e}"))?;
        let sample_format = supported.sample_format();
        let config: StreamConfig = supported.into();
        let sample_rate = config.sample_rate;
        let channels = config.channels;

        let mixer = Arc::new(Mutex::new(Mixer::new(sample_rate, channels)));
        let stream = build_stream(&device, &config, mixer.clone(), sample_format)?;
        stream.play().map_err(|e| format!("play: {e}"))?;

        Ok(Engine {
            mixer,
            sample_rate,
            channels,
            backend: Backend::Cpal,
            asset_root: root,
            overlays,
            _stream: Some(stream),
            warned: HashSet::new(),
            bgm_file: None,
            bgs_file: None,
        })
    }

    // --- configuration -------------------------------------------------------

    /// Change the directory used to resolve relative audio paths (`BGM/foo.ogg`).
    pub fn set_asset_root(&mut self, root: impl Into<PathBuf>) {
        self.asset_root = root.into();
    }

    pub fn asset_root(&self) -> &Path {
        &self.asset_root
    }

    /// The mod overlay roots, lowest priority first.
    pub fn overlays(&self) -> &[PathBuf] {
        &self.overlays
    }

    /// Output sample rate in Hz.
    pub fn sample_rate(&self) -> u32 {
        self.sample_rate
    }

    /// Output channel count.
    pub fn channels(&self) -> u16 {
        self.channels
    }

    /// True when running on the silent null backend.
    pub fn is_silent(&self) -> bool {
        matches!(self.backend, Backend::Null)
    }

    // --- BGM ----------------------------------------------------------------

    /// Start (replace) the BGM from a path relative to the asset root (or absolute).
    pub fn play_bgm(&mut self, file: &str, looping: bool) -> Result<(), AudioError> {
        self.play_bgm_with_volume(file, looping, 1.0)
    }

    pub fn play_bgm_with_volume(
        &mut self,
        file: &str,
        looping: bool,
        volume: f32,
    ) -> Result<(), AudioError> {
        // Retail scripts re-issue the same BGM command from several update branches.
        // Restarting the voice each time produced an audible retrigger (BUG-17); only a
        // genuinely different track replaces the current one. Volume-only repeats still
        // take effect.
        if self.mixer.lock().unwrap().bgm_playing() && self.bgm_file.as_deref() == Some(file) {
            self.lock().set_bgm_volume(volume);
            return Ok(());
        }
        let audio = self.load(file)?;
        self.lock().play_bgm(audio, looping, volume);
        self.bgm_file = Some(file.to_owned());
        Ok(())
    }

    /// Play an already-decoded BGM buffer.
    pub fn play_bgm_audio(&mut self, audio: DecodedAudio, looping: bool, volume: f32) {
        self.lock().play_bgm(audio, looping, volume);
        // A decoded buffer has no path to compare against; force the next path play.
        self.bgm_file = None;
    }

    /// Start (replace) the BGM from a path with a linear fade-in of `fade_frames` game frames
    /// (0 = immediate, the historical behaviour).
    pub fn play_bgm_with_fade(
        &mut self,
        file: &str,
        looping: bool,
        volume: f32,
        fade_frames: u32,
    ) -> Result<(), AudioError> {
        if self.mixer.lock().unwrap().bgm_playing() && self.bgm_file.as_deref() == Some(file) {
            self.lock().set_bgm_volume(volume);
            return Ok(());
        }
        let audio = self.load(file)?;
        self.lock()
            .play_bgm_with_fade(audio, looping, volume, fade_frames);
        self.bgm_file = Some(file.to_owned());
        Ok(())
    }

    /// Play an already-decoded BGM buffer with a linear fade-in of `fade_frames` game frames.
    pub fn play_bgm_audio_with_fade(
        &mut self,
        audio: DecodedAudio,
        looping: bool,
        volume: f32,
        fade_frames: u32,
    ) {
        self.lock()
            .play_bgm_with_fade(audio, looping, volume, fade_frames);
        self.bgm_file = None;
    }

    /// Stop the BGM. `fade_frames` is in game frames (60 fps); 0 stops immediately.
    pub fn stop_bgm(&mut self, fade_frames: u32) {
        self.lock().stop_bgm(fade_frames);
        self.bgm_file = None;
    }

    pub fn set_bgm_volume(&mut self, volume: f32) {
        self.lock().set_bgm_volume(volume);
    }

    // --- BGS ----------------------------------------------------------------

    /// Start (replace) the BGS ambience from a path with an optional linear fade-in.
    pub fn play_bgs_with_fade(
        &mut self,
        file: &str,
        looping: bool,
        volume: f32,
        fade_frames: u32,
    ) -> Result<(), AudioError> {
        if self.mixer.lock().unwrap().bgs_playing() && self.bgs_file.as_deref() == Some(file) {
            return Ok(());
        }
        let audio = self.load(file)?;
        self.lock()
            .play_bgs_with_fade(audio, looping, volume, fade_frames);
        self.bgs_file = Some(file.to_owned());
        Ok(())
    }

    /// Stop the BGS. `fade_frames` is in game frames (60 fps); 0 stops immediately.
    pub fn stop_bgs(&mut self, fade_frames: u32) {
        self.lock().stop_bgs(fade_frames);
        self.bgs_file = None;
    }

    // --- SE ----------------------------------------------------------------

    /// Play a one-shot SE from a path relative to the asset root (or absolute).
    pub fn play_se(&mut self, file: &str) -> Result<(), AudioError> {
        self.play_se_with_volume(file, 1.0)
    }

    pub fn play_se_with_volume(&mut self, file: &str, volume: f32) -> Result<(), AudioError> {
        let audio = self.load(file)?;
        self.lock().play_se(audio, volume);
        Ok(())
    }

    /// Play an already-decoded SE buffer.
    pub fn play_se_audio(&mut self, audio: DecodedAudio, volume: f32) {
        self.lock().play_se(audio, volume);
    }

    /// Start a one-shot SE from a path after a `delay_frames` game-frame start delay
    /// (0 = immediate, the historical behaviour).
    pub fn play_se_with_delay(
        &mut self,
        file: &str,
        volume: f32,
        delay_frames: u32,
    ) -> Result<(), AudioError> {
        let audio = self.load(file)?;
        self.lock().play_se_delayed(audio, volume, delay_frames);
        Ok(())
    }

    /// Play an already-decoded SE buffer after a `delay_frames` game-frame start delay.
    pub fn play_se_audio_with_delay(
        &mut self,
        audio: DecodedAudio,
        volume: f32,
        delay_frames: u32,
    ) {
        self.lock().play_se_delayed(audio, volume, delay_frames);
    }

    pub fn stop_all_se(&mut self) {
        self.lock().stop_all_se();
    }

    pub fn set_se_volume(&mut self, volume: f32) {
        self.lock().set_se_volume(volume);
    }

    // --- introspection / offline rendering ---------------------------------

    pub fn bgm_playing(&self) -> bool {
        self.lock().bgm_playing()
    }

    pub fn se_count(&self) -> usize {
        self.lock().se_count()
    }

    /// Pull mixed samples without an audio device (used by tests and headless runs).
    pub fn render_offline(&self, frames: usize) -> Vec<f32> {
        self.lock().render(frames)
    }

    // --- SoundCmd adapter ---------------------------------------------------

    /// Translate a VM [`SoundCmd`] (opcode 140 `Sound`) into play/stop calls.
    ///
    /// * BGM Play  -> `play_bgm_with_fade(file, looping = true, frames)`
    /// * BGM Stop  -> `stop_bgm(frames)` (fade-out length in game frames)
    /// * SE  Play  -> `play_se_with_delay(file, frames)` (concurrent; frames = start delay)
    /// * SE  Stop  -> `stop_all_se()` (stop-all by design, see below)
    ///
    /// `SoundCmd.frames` (opcode 140 intArgs[1], the "fade time / delay" slot) is honoured
    /// on Play as well as Stop: a BGM Play fades in linearly over that many game frames, an
    /// SE Play stays silent for that many game frames first, and a BGM Stop fades out over
    /// them. `frames == 0` reproduces the old immediate-start behaviour. An SE Stop ignores
    /// `frames`: retail encodes opcode 140 stops as `SoundFreeAll` / `SoundFreeAllVariable`,
    /// which carry no file name or voice id (all 73 stops in the shipped data have empty
    /// string lists), so a stop clears every concurrent SE on the channel.
    pub fn apply_sound_cmd(&mut self, cmd: &SoundCmd) {
        let volume = (cmd.volume.clamp(0, 100) as f32) / 100.0;
        let frames = cmd.frames.max(0) as u32;
        match (cmd.channel, cmd.action) {
            (SoundChannel::Bgm, SoundAction::Play) => {
                if let Err(err) = self.play_bgm_with_fade(&cmd.file, true, volume, frames) {
                    self.warn_once(&cmd.file, &err);
                }
            }
            (SoundChannel::Bgm, SoundAction::Stop) => {
                self.stop_bgm(frames);
            }
            (SoundChannel::Bgs, SoundAction::Play) => {
                if let Err(err) = self.play_bgs_with_fade(&cmd.file, true, volume, frames) {
                    self.warn_once(&cmd.file, &err);
                }
            }
            (SoundChannel::Bgs, SoundAction::Stop) => {
                self.stop_bgs(frames);
            }
            (SoundChannel::Se, SoundAction::Play) => {
                if let Err(err) = self.play_se_with_delay(&cmd.file, volume, frames) {
                    self.warn_once(&cmd.file, &err);
                }
            }
            (SoundChannel::Se, SoundAction::Stop) => {
                self.stop_all_se();
            }
        }
    }

    // --- internals ----------------------------------------------------------

    fn lock(&self) -> MutexGuard<'_, Mixer> {
        self.mixer
            .lock()
            .unwrap_or_else(|poisoned| poisoned.into_inner())
    }

    fn warn_once(&mut self, file: &str, err: &AudioError) {
        if self.warned.insert(file.to_string()) {
            eprintln!("[wolf-audio] cannot play {file}: {err}");
        }
    }

    /// Resolve a WOLF-relative audio path against the mod overlays and the asset root.
    ///
    /// Overlays are searched newest first, then the current directory, then the base
    /// root and `root/Data`. An absolute path is used as-is.
    pub fn resolve(&self, file: &str) -> Option<PathBuf> {
        let normalised = file.replace('\\', "/");
        let p = Path::new(&normalised);
        if p.is_absolute() {
            return p.is_file().then(|| p.to_path_buf());
        }
        let mut candidates: Vec<PathBuf> = Vec::new();
        for overlay in self.overlays.iter().rev() {
            candidates.push(overlay.join(p));
            candidates.push(overlay.join("Data").join(p));
        }
        candidates.push(p.to_path_buf());
        candidates.push(self.asset_root.join(p));
        candidates.push(self.asset_root.join("Data").join(p));
        candidates.into_iter().find(|candidate| candidate.is_file())
    }

    fn load(&self, file: &str) -> Result<DecodedAudio, AudioError> {
        let path = self.resolve(file).ok_or_else(|| {
            AudioError::Io(format!(
                "audio file not found: {file} (asset root {})",
                self.asset_root.display()
            ))
        })?;
        decode_file(&path)
    }
}

impl Default for Engine {
    fn default() -> Self {
        Self::new()
    }
}

fn build_stream(
    device: &cpal::Device,
    config: &StreamConfig,
    mixer: Arc<Mutex<Mixer>>,
    sample_format: SampleFormat,
) -> Result<Stream, String> {
    match sample_format {
        SampleFormat::F32 => build_generic::<f32>(device, config.clone(), mixer),
        SampleFormat::I16 => build_generic::<i16>(device, config.clone(), mixer),
        SampleFormat::U16 => build_generic::<u16>(device, config.clone(), mixer),
        SampleFormat::I32 => build_generic::<i32>(device, config.clone(), mixer),
        SampleFormat::U32 => build_generic::<u32>(device, config.clone(), mixer),
        SampleFormat::I8 => build_generic::<i8>(device, config.clone(), mixer),
        SampleFormat::U8 => build_generic::<u8>(device, config.clone(), mixer),
        SampleFormat::F64 => build_generic::<f64>(device, config.clone(), mixer),
        other => Err(format!("unsupported output sample format: {other}")),
    }
}

fn build_generic<T>(
    device: &cpal::Device,
    config: StreamConfig,
    mixer: Arc<Mutex<Mixer>>,
) -> Result<Stream, String>
where
    T: SizedSample + FromSample<f32>,
{
    let channels = config.channels as usize;
    let stream = device
        .build_output_stream::<T, _, _>(
            config,
            move |data: &mut [T], _info: &cpal::OutputCallbackInfo| {
                if channels == 0 {
                    return;
                }
                let frames = data.len() / channels;
                let mut guard = mixer
                    .lock()
                    .unwrap_or_else(|poisoned| poisoned.into_inner());
                let rendered = guard.render(frames);
                for (dst, src) in data.iter_mut().zip(rendered.into_iter()) {
                    *dst = T::from_sample(src);
                }
            },
            |err: cpal::Error| eprintln!("[wolf-audio] stream error: {err}"),
            None,
        )
        .map_err(|e| format!("build_output_stream: {e}"))?;
    Ok(stream)
}
