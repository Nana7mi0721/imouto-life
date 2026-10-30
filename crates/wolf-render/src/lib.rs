//! GPU renderer for the 1024x576 logical framebuffer.
//!
//! The crate is deliberately narrow: it knows about quads, one atlas page and an
//! integer upscale, and nothing about tiles, WOLF layer bands or the script VM.
//! That keeps the wgpu churn isolated -- this is the part of the workspace most
//! likely to need a rewrite when wgpu breaks its API again, so nothing else
//! depends on the GPU stack directly.
//!
//! Typical frame:
//!
//! ```no_run
//! use std::sync::Arc;
//! use wolf_render::{Renderer, SpriteInstance};
//!
//! fn frame(window: Arc<winit::window::Window>) -> Result<(), Box<dyn std::error::Error>> {
//!     let mut renderer = Renderer::new(window)?;
//!     renderer.set_atlas(&vec![0u8; 2048 * 2048 * 4], 2048, 2048)?;
//!     renderer.draw(&[SpriteInstance::new(
//!         [0.0, 0.0, 1024.0, 576.0],
//!         [0.0, 0.0, 0.5, 0.5],
//!     )]);
//!     renderer.present();
//!     Ok(())
//! }
//! ```
//!
//! Design notes for the pieces below live in docs/ARCHITECTURE.md sections 3.4
//! (integer scaling), 3.5 (layer bands) and 3.7 (tile batching).

#![forbid(unsafe_code)]
#![warn(missing_docs)]

mod diff;
mod error;
mod renderer;
mod scaler;
mod sprite;
mod text;

pub use diff::{compare, diff_image, rgba_at, DiffReport, WorstPixel, DIFF_GAIN, WORST_LIMIT};
pub use error::RenderError;
pub use renderer::{Renderer, FRAME_FORMAT};
pub use scaler::{integer_scale, Scaler, LOGICAL_H, LOGICAL_W};
pub use sprite::SpriteInstance;
pub use text::{
    layout_box, missing_glyphs, substitute_missing, LayoutBox, Outline, TextAlign, TextError,
    TextItem, TextRenderer, TextStats, AUTO_BOX_THRESHOLD, LINE_HEIGHT_FACTOR, MAX_SIZE_PX,
    MIN_SIZE_PX, REPLACEMENT_CHAR,
};
