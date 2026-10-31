//! Software mixer: 1 looping BGM voice + any number of concurrent SE voices.
//!
//! The mixer is completely independent of any audio device. `render(frames)` produces the next
//! chunk of interleaved f32 output, so it can be unit-tested offline and also drives the cpal
//! callback. Sample-rate conversion is done per voice with linear interpolation, so sources whose
//! sample rate differs from the output device mix correctly.
//!
//! Contract (pinned by `tests/mixer_contract.rs`):
//! * per-voice volume and the master BGM/SE volumes multiply, and both are clamped to 0..=1;
//! * BGM is a single replaceable voice; a non-looping voice ends and is dropped;
//! * a BGM started with a fade-in ramps monotonically from near-silence up to full gain and
//!   then stays there; an SE started with a delay stays silent (and does not advance its
//!   source cursor) until the delay elapses;
//! * a fading BGM ramps monotonically to silence and is then dropped;
//! * once a voice reports `done` inside a render chunk it contributes silence for the rest of
//!   that chunk (a finished one-shot SE must not hold its last sample as a DC tail);
//! * output samples are clamped to [-1.0, 1.0]; mono sources fan out to all output channels.

use std::sync::Arc;

use crate::decode::DecodedAudio;

/// The rate at which WOLF RPG Editor advances game frames. Used to translate `SoundCmd.frames`
/// (a fade length in game frames) into output samples.
pub const GAME_FPS: f32 = 60.0;

/// Translate a length in game frames (60 fps) to output frames at `out_rate` Hz.
///
/// Returns at least 1 so a non-zero fade/delay is always observable.
fn game_frames_to_output(game_frames: u32, out_rate: u32) -> u32 {
    let total = ((game_frames as f64 * out_rate as f64) / GAME_FPS as f64).round() as u32;
    total.max(1)
}

struct FadeOut {
    frames_left: u32,
    frames_total: u32,
}

impl FadeOut {
    /// Consume one output frame, returning the gain to apply to it.
    fn next_gain(&mut self) -> f32 {
        if self.frames_total == 0 {
            return 0.0;
        }
        let gain = self.frames_left as f32 / self.frames_total as f32;
        if self.frames_left > 0 {
            self.frames_left -= 1;
        }
        gain
    }

    fn is_done(&self) -> bool {
        self.frames_left == 0
    }
}

/// Linear fade-in envelope for a BGM voice. One step per output frame so it reaches full
/// gain exactly after `frames_total` output frames (a SoundCmd fade length in game frames,
/// converted by the mixer when the voice is created).
struct FadeIn {
    frames_left: u32,
    frames_total: u32,
}

impl FadeIn {
    /// Consume one output frame, returning the gain to apply to it. The first sample is
    /// `1/total` and the value climbs to `1.0` on the final sample, so the envelope is
    /// strictly monotonic and never exceeds unity.
    fn next_gain(&mut self) -> f32 {
        if self.frames_total == 0 {
            return 1.0;
        }
        let gain = (self.frames_total - self.frames_left + 1) as f32 / self.frames_total as f32;
        if self.frames_left > 0 {
            self.frames_left -= 1;
        }
        gain
    }

    fn is_done(&self) -> bool {
        self.frames_left == 0
    }
}

struct Voice {
    audio: Arc<DecodedAudio>,
    /// Playback position in source frames (fractional for resampling).
    pos: f64,
    looping: bool,
    volume: f32,
    fade: Option<FadeOut>,
    /// BGM fade-in envelope (None = play at full gain immediately).
    fade_in: Option<FadeIn>,
    /// SE start delay in output frames: the voice emits silence and does not advance while
    /// this is non-zero (0 = start immediately).
    delay_left: u32,
    done: bool,
}

impl Voice {
    fn new(audio: DecodedAudio, looping: bool, volume: f32) -> Self {
        Voice {
            audio: Arc::new(audio),
            pos: 0.0,
            looping,
            volume: volume.clamp(0.0, 1.0),
            fade: None,
            fade_in: None,
            delay_left: 0,
            done: false,
        }
    }

    /// Read the interpolated sample at the current position for output channel `out_ch`.
    fn sample(&self, out_ch: usize) -> f32 {
        let audio = &*self.audio;
        let total = audio.frames();
        if total == 0 {
            return 0.0;
        }
        let pos = self.pos.max(0.0);
        let i0 = (pos.floor() as usize).min(total - 1);
        let frac = (pos - i0 as f64) as f32;
        let i1 = (i0 + 1).min(total - 1);
        let s0 = audio.sample(i0, out_ch);
        let s1 = audio.sample(i1, out_ch);
        s0 + (s1 - s0) * frac
    }

    /// Advance the playback cursor. Returns `false` when a non-looping voice has finished.
    fn advance(&mut self, out_rate: u32) -> bool {
        let step = if out_rate == 0 {
            1.0
        } else {
            self.audio.sample_rate as f64 / out_rate as f64
        };
        self.pos += step;
        let total = self.audio.frames() as f64;
        if total <= 0.0 {
            return false;
        }

        if self.looping {
            match (self.audio.loop_start, self.audio.loop_end) {
                (Some(start), Some(end)) if end > start => {
                    let start = start as f64;
                    let end = (end as f64).min(total);
                    if end > start {
                        while self.pos >= end {
                            self.pos -= end - start;
                        }
                    } else if self.pos >= total {
                        self.pos -= total;
                    }
                }
                _ => {
                    while self.pos >= total {
                        self.pos -= total;
                    }
                }
            }
            true
        } else if self.pos >= total {
            false
        } else {
            true
        }
    }
}

/// Software mixer. Output is always interleaved f32.
pub struct Mixer {
    out_rate: u32,
    out_channels: u16,
    bgm: Option<Voice>,
    ses: Vec<Voice>,
    bgm_volume: f32,
    se_volume: f32,
}

impl Mixer {
    /// Create a mixer targeting `out_rate` Hz and `out_channels` channels.
    pub fn new(out_rate: u32, out_channels: u16) -> Self {
        Mixer {
            out_rate,
            out_channels: out_channels.max(1),
            bgm: None,
            ses: Vec::new(),
            bgm_volume: 1.0,
            se_volume: 1.0,
        }
    }

    pub fn out_rate(&self) -> u32 {
        self.out_rate
    }

    pub fn out_channels(&self) -> u16 {
        self.out_channels
    }

    /// Start (or replace) the single BGM voice at full gain immediately.
    pub fn play_bgm(&mut self, audio: DecodedAudio, looping: bool, volume: f32) {
        self.play_bgm_with_fade(audio, looping, volume, 0);
    }

    /// Start (or replace) the single BGM voice with an optional linear fade-in.
    ///
    /// `fade_frames` is a length in game frames (60 fps), matching `SoundCmd.frames`; 0 plays
    /// at full gain immediately (the historical behaviour).
    pub fn play_bgm_with_fade(
        &mut self,
        audio: DecodedAudio,
        looping: bool,
        volume: f32,
        fade_frames: u32,
    ) {
        let mut voice = Voice::new(audio, looping, volume);
        if fade_frames > 0 {
            let total = game_frames_to_output(fade_frames, self.out_rate);
            voice.fade_in = Some(FadeIn {
                frames_left: total,
                frames_total: total,
            });
        }
        self.bgm = Some(voice);
    }

    /// Start a new SE voice; multiple SE voices play concurrently.
    pub fn play_se(&mut self, audio: DecodedAudio, volume: f32) {
        self.play_se_delayed(audio, volume, 0);
    }

    /// Start a new SE voice that stays silent for `delay_frames` game frames before it begins.
    ///
    /// `delay_frames` is the `SoundCmd.frames` start delay in game frames (60 fps); 0 starts
    /// immediately (the historical behaviour). The source cursor is not advanced while the
    /// voice is still delayed, so no audio is skipped.
    pub fn play_se_delayed(&mut self, audio: DecodedAudio, volume: f32, delay_frames: u32) {
        let mut voice = Voice::new(audio, false, volume);
        if delay_frames > 0 {
            voice.delay_left = game_frames_to_output(delay_frames, self.out_rate);
        }
        self.ses.push(voice);
    }

    /// Stop the BGM. `fade_frames` is a length in game frames (60 fps); 0 stops immediately.
    pub fn stop_bgm(&mut self, fade_frames: u32) {
        if fade_frames == 0 {
            self.bgm = None;
            return;
        }
        if let Some(voice) = self.bgm.as_mut() {
            let total =
                ((fade_frames as f64 * self.out_rate as f64) / GAME_FPS as f64).round() as u32;
            voice.fade = Some(FadeOut {
                frames_left: total.max(1),
                frames_total: total.max(1),
            });
        }
    }

    /// Immediately stop every SE voice.
    ///
    /// Retail opcode 140 SE stops decode to `State::FreeAll` with no file name or voice
    /// id, so they clear the whole SE bus; there is no per-file stop in the data to model.
    pub fn stop_all_se(&mut self) {
        self.ses.clear();
    }

    pub fn set_bgm_volume(&mut self, volume: f32) {
        self.bgm_volume = volume.clamp(0.0, 1.0);
    }

    pub fn set_se_volume(&mut self, volume: f32) {
        self.se_volume = volume.clamp(0.0, 1.0);
    }

    pub fn bgm_volume(&self) -> f32 {
        self.bgm_volume
    }

    pub fn se_volume(&self) -> f32 {
        self.se_volume
    }

    pub fn bgm_playing(&self) -> bool {
        self.bgm.is_some()
    }

    pub fn se_count(&self) -> usize {
        self.ses.len()
    }

    /// Render the next `frames` frames of interleaved output. Length is exactly
    /// `frames * out_channels`. Mixed samples are clamped to [-1.0, 1.0].
    pub fn render(&mut self, frames: usize) -> Vec<f32> {
        let ch = self.out_channels as usize;
        let mut out = vec![0.0f32; frames * ch];
        let out_rate = self.out_rate;
        let bgm_volume = self.bgm_volume;
        let se_volume = self.se_volume;

        for f in 0..frames {
            let base = f * ch;

            if let Some(voice) = self.bgm.as_mut() {
                if !voice.done {
                    let fade_gain = match voice.fade.as_mut() {
                        Some(fade) => fade.next_gain(),
                        None => 1.0,
                    };
                    let mut fade_in_gain = 1.0f32;
                    if let Some(fade_in) = voice.fade_in.as_mut() {
                        fade_in_gain = fade_in.next_gain();
                    }
                    if voice.fade_in.as_ref().is_some_and(|fade| fade.is_done()) {
                        voice.fade_in = None;
                    }
                    let gain = voice.volume * bgm_volume * fade_gain * fade_in_gain;
                    for c in 0..ch {
                        out[base + c] += voice.sample(c) * gain;
                    }
                    if !voice.advance(out_rate) {
                        voice.done = true;
                    }
                    if voice.fade.as_ref().is_some_and(|fade| fade.is_done()) {
                        voice.done = true;
                    }
                }
            }

            for voice in self.ses.iter_mut() {
                // A voice that ended earlier in this chunk must not hold its clamped last
                // sample for the rest of the buffer: that would emit a DC tail (up to a
                // whole callback) after a one-shot SE has finished.
                if voice.done {
                    continue;
                }
                // A delayed SE stays silent and does not move its source cursor.
                if voice.delay_left > 0 {
                    voice.delay_left -= 1;
                    continue;
                }
                let gain = voice.volume * se_volume;
                for c in 0..ch {
                    out[base + c] += voice.sample(c) * gain;
                }
                if !voice.advance(out_rate) {
                    voice.done = true;
                }
            }

            for c in 0..ch {
                out[base + c] = out[base + c].clamp(-1.0, 1.0);
            }
        }

        if self.bgm.as_ref().is_some_and(|v| v.done) {
            self.bgm = None;
        }
        self.ses.retain(|v| !v.done);
        out
    }
}
