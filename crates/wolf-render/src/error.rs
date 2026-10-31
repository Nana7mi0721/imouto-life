//! Renderer error type.
//!
//! `Renderer::new` is a *synchronous* constructor (see docs/ARCHITECTURE.md §3.4): every
//! async wgpu entry point is driven to completion by a bounded executor, so failures
//! surface as values instead of being threaded through an `async` signature. The
//! deadline matters: a wedged driver must not hang a headless capture forever (see
//! [`RenderError::InitTimeout`]). That keeps the caller (the winit `resumed`
//! callback, which is sync) free of executor plumbing.
//!
//! wgpu's own error types are `#[non_exhaustive]` and change shape between minors, so the
//! public API only ever exposes strings and our own variants.

use std::fmt;

/// Everything that can go wrong while bringing the renderer up or feeding it a frame.
#[derive(Debug)]
pub enum RenderError {
    /// No adapter matched the requested options (no GPU, or headless with no backend).
    NoAdapter {
        /// Which backends were asked for, for the log line.
        backends: String,
    },
    /// `Adapter::request_device` failed.
    DeviceRequest(String),
    /// An async wgpu bring-up step did not finish inside its deadline.
    ///
    /// Adapter enumeration and device creation are driver calls that can block
    /// indefinitely on a wedged or memory-starved GPU (this machine has seen a
    /// headless capture hang at exactly that point). The constructor drives them
    /// with a bounded executor instead of `block_on`, so a stuck driver becomes
    /// this error instead of a hung process. `stage` names the step ("adapter",
    /// "device") and `millis` is the deadline that expired.
    InitTimeout {
        /// Which async step timed out.
        stage: &'static str,
        /// The deadline in milliseconds.
        millis: u64,
    },
    /// `Instance::create_surface` failed (usually: the window has no usable handle).
    CreateSurface(String),
    /// The surface reports no compatible default configuration for this adapter.
    UnsupportedSurface,
    /// `set_atlas` got a byte slice that is not `width * height * 4` long.
    AtlasSizeMismatch {
        /// `width * height * 4`.
        expected: usize,
        /// `rgba.len()`.
        actual: usize,
    },
    /// A zero width or height reached the GPU side (surfaces must be `>= 1x1`).
    ZeroSizedSurface,
    /// Copying the offscreen frame back to CPU memory failed.
    ReadbackFailed(String),
    /// The text pass failed (font loading, glyph layout or the glyph draw).
    ///
    /// Wrapped instead of flattened to a string so a caller can match on
    /// `TextError::NoFont` and keep drawing sprites.
    Text(crate::text::TextError),
}

impl fmt::Display for RenderError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::NoAdapter { backends } => {
                write!(f, "no compatible GPU adapter found (backends: {backends})")
            }
            Self::DeviceRequest(e) => write!(f, "failed to request a wgpu device: {e}"),
            Self::InitTimeout { stage, millis } => write!(
                f,
                "GPU {stage} request did not finish within {millis} ms; the driver may be wedged \
                 (set WOLF_RENDER_TIMEOUT_MS to wait longer)"
            ),
            Self::CreateSurface(e) => write!(f, "failed to create a window surface: {e}"),
            Self::UnsupportedSurface => {
                write!(f, "adapter reports no default surface configuration")
            }
            Self::AtlasSizeMismatch { expected, actual } => write!(
                f,
                "atlas buffer is {actual} bytes but width * height * 4 == {expected}"
            ),
            Self::ZeroSizedSurface => write!(f, "surface size must be at least 1x1"),
            Self::ReadbackFailed(e) => write!(f, "failed to read the frame back: {e}"),
            Self::Text(e) => write!(f, "text pass: {e}"),
        }
    }
}

impl std::error::Error for RenderError {}
