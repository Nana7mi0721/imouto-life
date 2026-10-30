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
    _stream: Option<Stream>,
    warned: HashSet<String>,
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
        let root = root.into();
        match Self::try_cpal(root.clone()) {
            Ok(engine) => engine,
            Err(err) => {
                eprintln!(
                    "[wolf-audio] audio output unavailable ({err}); using silent null backend"
                );
                Self::null_with_root(root)
            }
        }
    }

    /// Create an engine that never touches the audio device (useful for tests / headless).
    pub fn null() -> Self {
        Self::null_with(48_000, 2)
    }

    pub fn null_with(sample_rate: u32, channels: u16) -> Self {
        Self::null_with_root_and(sample_rate, channels, PathBuf::from("."))
    }

    fn null_with_root(root: PathBuf) -> Self {
        Self::null_with_root_and(48_000, 2, root)
    }

    fn null_with_root_and(sample_rate: u32, channels: u16, root: PathBuf) -> Self {
        Engine {
            mixer: Arc::new(Mutex::new(Mixer::new(sample_rate, channels))),
            sample_rate,
            channels,
            backend: Backend::Null,
            asset_root: root,
            _stream: None,
            warned: HashSet::new(),
        }
    }

    fn try_cpal(root: PathBuf) -> Result<Self, String> {
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
            _stream: Some(stream),
            warned: HashSet::new(),
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
        let audio = self.load(file)?;
        self.lock().play_bgm(audio, looping, volume);
        Ok(())
    }

    /// Play an already-decoded BGM buffer.
    pub fn play_bgm_audio(&mut self, audio: DecodedAudio, looping: bool, volume: f32) {
        self.lock().play_bgm(audio, looping, volume);
    }

    /// Stop the BGM. `fade_frames` is in game frames (60 fps); 0 stops immediately.
    pub fn stop_bgm(&mut self, fade_frames: u32) {
        self.lock().stop_bgm(fade_frames);
    }

    pub fn set_bgm_volume(&mut self, volume: f32) {
        self.lock().set_bgm_volume(volume);
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
    /// * BGM Play  -> `play_bgm(file, looping = true)`
    /// * BGM Stop  -> `stop_bgm(frames)` (fade length in game frames)
    /// * SE  Play  -> `play_se(file)` (concurrent)
    /// * SE  Stop  -> `stop_all_se()`
    pub fn apply_sound_cmd(&mut self, cmd: &SoundCmd) {
        let volume = (cmd.volume.clamp(0, 100) as f32) / 100.0;
        match (cmd.channel, cmd.action) {
            (SoundChannel::Bgm, SoundAction::Play) => {
                if let Err(err) = self.play_bgm_with_volume(&cmd.file, true, volume) {
                    self.warn_once(&cmd.file, &err);
                }
            }
            (SoundChannel::Bgm, SoundAction::Stop) => {
                self.stop_bgm(cmd.frames.max(0) as u32);
            }
            (SoundChannel::Se, SoundAction::Play) => {
                if let Err(err) = self.play_se_with_volume(&cmd.file, volume) {
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
        self.mixer.lock().unwrap_or_else(|poisoned| poisoned.into_inner())
    }

    fn warn_once(&mut self, file: &str, err: &AudioError) {
        if self.warned.insert(file.to_string()) {
            eprintln!("[wolf-audio] cannot play {file}: {err}");
        }
    }

    /// Resolve a WOLF-relative audio path against the asset root.
    pub fn resolve(&self, file: &str) -> Option<PathBuf> {
        let normalised = file.replace('\\', "/");
        let p = Path::new(&normalised);
        let candidates = [
            p.to_path_buf(),
            self.asset_root.join(p),
            self.asset_root.join("Data").join(p),
        ];
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
                let mut guard = mixer.lock().unwrap_or_else(|poisoned| poisoned.into_inner());
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
