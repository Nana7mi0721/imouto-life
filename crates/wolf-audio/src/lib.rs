//! Audio backend for the WOLF RPG Editor reimplementation (milestone M4).
//!
//! Layers:
//! * [`decode`] — decode ogg-vorbis / mp3 / wav files into interleaved f32 PCM.
//! * [`mixer`] — offline-testable software mixer (1 BGM + N SE, resampling, looping, fades).
//! * [`engine`] — output engine backed by cpal, with a silent null backend fallback.
//!
//! See `docs/AUDIO.md` for the design and the `Game::sound` wiring instructions.

pub mod decode;
pub mod engine;
pub mod mixer;

pub use decode::{decode_bytes, decode_file, AudioSource, DecodedAudio};
pub use engine::Engine;
pub use mixer::Mixer;

use std::fmt;

/// Errors produced by the audio backend.
#[derive(Debug)]
pub enum AudioError {
    /// I/O error opening or reading a media file.
    Io(String),
    /// The container/codec could not be decoded (missing support or malformed data).
    Unsupported(String),
    /// The file decoded, but contained no usable audio frames.
    Empty(String),
}

impl fmt::Display for AudioError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            AudioError::Io(m) => write!(f, "audio io error: {m}"),
            AudioError::Unsupported(m) => write!(f, "unsupported audio: {m}"),
            AudioError::Empty(m) => write!(f, "empty audio: {m}"),
        }
    }
}

impl std::error::Error for AudioError {}

impl From<std::io::Error> for AudioError {
    fn from(e: std::io::Error) -> Self {
        AudioError::Io(e.to_string())
    }
}
