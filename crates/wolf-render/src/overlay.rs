//! Whole-screen overlays composited after the sprite batch and the text pass.
//!
//! Two effects in the game need a quad that covers all 1024x576 logical pixels
//! and is *not* part of the tile/picture layer stack:
//!
//! * opcode 151's screen flash -- a flat colour over everything;
//! * opcodes 160/161/162 -- the drawn screen freezes while the transition runs,
//!   and the frozen image is then faded (a snapshot drawn at a falling alpha).
//!
//! Both are the same primitive, a full-screen textured quad whose per-instance
//! tint supplies the alpha, so they reuse the sprite pipeline and its
//! `ALPHA_BLENDING` state instead of adding a second shader: with `alpha = 1` the
//! overlay replaces the frame byte for byte, with `alpha = 0` it is a no-op.
//!
//! The types here are plain data (no wgpu), which is what lets
//! [`overlay_instances`] be tested without a GPU.

use crate::scaler::{LOGICAL_H, LOGICAL_W};
use crate::sprite::SpriteInstance;

/// Instances the overlay batch starts with.
///
/// Eight covers every effect the engine has (a flash, a frozen frame and a
/// black fade can coexist on one transition frame); the buffer still grows by
/// powers of two if a caller queues more.
pub const INITIAL_OVERLAY_CAPACITY: usize = 8;

/// Destination rect of a whole-screen overlay, in logical pixels.
pub const OVERLAY_RECT: [f32; 4] = [0.0, 0.0, LOGICAL_W as f32, LOGICAL_H as f32];

/// Source rect of a whole-screen overlay: the entire bound texture.
pub const OVERLAY_UV: [f32; 4] = [0.0, 0.0, 1.0, 1.0];

/// What a [`ScreenOverlay`] samples.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum OverlayKind {
    /// A flat colour from a 1x1 white texture, tinted by
    /// [`ScreenOverlay::colour`]. Used for 151's flash and for a plain fade to
    /// black.
    Colour,
    /// A snapshot of the logical frame taken by [`crate::Renderer::freeze`].
    /// Used for the frozen old screen that 160/161/162 fade out or the new
    /// screen fades in over.
    Frozen,
}

/// One whole-screen overlay: what to sample, its colour and its opacity.
///
/// Overlays are drawn in slice order after the sprite batch and the text pass,
/// so the last one in the list ends up fully on top.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct ScreenOverlay {
    /// Texture the quad samples (see [`OverlayKind`]).
    pub kind: OverlayKind,
    /// RGB multiplied into the texel; `[255, 255, 255]` is a no-op.
    ///
    /// This tints [`OverlayKind::Frozen`] as well as [`OverlayKind::Colour`]
    /// (it is the sprite shader's tint, applied to whatever is sampled), so use
    /// white for an unmodified frozen frame and black for a fade-through-black.
    pub colour: [u8; 3],
    /// Opacity in `[0, 1]`: 1 draws the overlay opaquely, 0 draws nothing.
    pub alpha: f32,
}

impl ScreenOverlay {
    /// A flat colour at `alpha` (151's flash, or a black fade with `[0, 0, 0]`).
    #[must_use]
    pub const fn colour(rgb: [u8; 3], alpha: f32) -> Self {
        Self {
            kind: OverlayKind::Colour,
            colour: rgb,
            alpha,
        }
    }

    /// The frozen frame at `alpha`, untinted (white `colour`).
    ///
    /// Meaningful only after [`crate::Renderer::freeze`]; without a frozen
    /// frame the renderer skips it (there is nothing to show).
    #[must_use]
    pub const fn frozen(alpha: f32) -> Self {
        Self {
            kind: OverlayKind::Frozen,
            colour: [255, 255, 255],
            alpha,
        }
    }

    /// The instance this overlay draws: the full logical canvas, whole texture,
    /// tint = colour / 255 and `alpha`.
    #[must_use]
    pub fn instance(self) -> SpriteInstance {
        let [r, g, b] = self.colour;
        SpriteInstance {
            rect: OVERLAY_RECT,
            uv: OVERLAY_UV,
            tint: [
                f32::from(r) / 255.0,
                f32::from(g) / 255.0,
                f32::from(b) / 255.0,
                self.alpha,
            ],
        }
    }
}

/// Instances for a whole overlay list, in draw order.
///
/// Kept separate from the renderer so the geometry / colour / alpha mapping is
/// testable without a device.
#[must_use]
pub fn overlay_instances(overlays: &[ScreenOverlay]) -> Vec<SpriteInstance> {
    overlays
        .iter()
        .copied()
        .map(ScreenOverlay::instance)
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn a_colour_overlay_maps_bytes_to_unit_range() {
        let instance = ScreenOverlay::colour([255, 128, 0], 0.75).instance();
        assert_eq!(instance.rect, [0.0, 0.0, 1024.0, 576.0]);
        assert_eq!(instance.uv, [0.0, 0.0, 1.0, 1.0]);
        assert_eq!(instance.tint[0], 1.0);
        assert_eq!(instance.tint[1], 128.0 / 255.0);
        assert_eq!(instance.tint[2], 0.0);
        assert_eq!(instance.tint[3], 0.75);
    }

    #[test]
    fn a_frozen_overlay_is_untinted_at_its_alpha() {
        let instance = ScreenOverlay::frozen(0.25).instance();
        assert_eq!(instance.rect, OVERLAY_RECT);
        assert_eq!(instance.uv, OVERLAY_UV);
        assert_eq!(instance.tint, [1.0, 1.0, 1.0, 0.25]);
    }

    #[test]
    fn the_alpha_extremes_are_opaque_and_invisible() {
        // 1.0 must write the source through unchanged; 0.0 must leave the frame
        // alone. The sprite blend (SrcAlpha / OneMinusSrcAlpha) gives exactly
        // that at these two values, which is why no special case is needed.
        let opaque = ScreenOverlay::colour([0, 0, 0], 1.0).instance();
        assert_eq!(opaque.tint[3], 1.0);
        let invisible = ScreenOverlay::colour([0, 0, 0], 0.0).instance();
        assert_eq!(invisible.tint[3], 0.0);
    }

    #[test]
    fn instances_follow_the_input_order_and_count() {
        let overlays = [
            ScreenOverlay::colour([255, 0, 0], 0.5),
            ScreenOverlay::frozen(0.5),
            ScreenOverlay::colour([0, 0, 255], 0.25),
        ];
        let instances = overlay_instances(&overlays);
        assert_eq!(instances.len(), overlays.len());
        assert_eq!(instances[0].tint, [1.0, 0.0, 0.0, 0.5]);
        assert_eq!(instances[1].tint, [1.0, 1.0, 1.0, 0.5]);
        assert_eq!(instances[2].tint, [0.0, 0.0, 1.0, 0.25]);
        assert!(overlay_instances(&[]).is_empty());
    }

    #[test]
    fn a_colour_tints_a_frozen_frame_too() {
        // The tint is the sprite shader's, so it applies to whatever is sampled.
        // Pinned here because 160/161/162 use it to fade through black.
        let dimmed = ScreenOverlay {
            kind: OverlayKind::Frozen,
            colour: [128, 128, 128],
            alpha: 1.0,
        };
        assert_eq!(
            dimmed.instance().tint,
            [128.0 / 255.0, 128.0 / 255.0, 128.0 / 255.0, 1.0]
        );
    }

    #[test]
    fn the_initial_capacity_covers_the_known_effects() {
        assert_eq!(INITIAL_OVERLAY_CAPACITY, 8);
    }
}
