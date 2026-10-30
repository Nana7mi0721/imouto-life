//! Renderer error type.
//!
//! `Renderer::new` is a *synchronous* constructor (see docs/ARCHITECTURE.md §3.4): every
//! async wgpu entry point is driven to completion with `pollster::block_on`, so failures
//! surface as values instead of being threaded through an `async` signature. That keeps
//! the caller (the winit `resumed` callback, which is sync) free of executor plumbing.
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
