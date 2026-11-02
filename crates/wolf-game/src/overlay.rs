//! Whole-screen overlays composited over the scene.
//!
//! Two 151/160-family effects draw *after* the scene instead of tinting the
//! sprites that make it up (docs/re/TRANSITION.md section 4):
//!
//! * a 151 flash queues a solid colour quad covering the whole screen whose
//!   alpha decays linearly (FUN_004c25f0 -> DrawBox over the frame),
//! * a 160/161/162 transition draws the frame frozen by 161 over the freshly
//!   drawn scene, fading it out linearly (FUN_004c28d0 -> DrawGraph of the old
//!   frame with SetDrawBlendMode(ALPHA, 255 * elapsed / duration)).
//!
//! Both are drawn with SetDrawBright reset to neutral, so they cover the HUD as
//! well and are never multiplied into a sprite tint. Keeping them out of
//! SpriteQuad is what makes that ordering explicit.

/// What one overlay draws.
#[derive(Clone, Copy, Debug, PartialEq)]
pub enum OverlayLayer {
    /// A solid colour quad covering the logical 1024x576 screen (a 151 flash).
    Colour([u8; 3]),
    /// The screen frozen by a 161 transition, drawn with the dissolve alpha.
    FrozenFrame,
}

/// One whole-screen overlay, listed bottom to top.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct ScreenOverlay {
    /// What to draw.
    pub layer: OverlayLayer,
    /// Opacity in [0, 1]; 1.0 is opaque.
    pub alpha: f32,
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn overlays_are_copy_and_comparable() {
        let a = ScreenOverlay {
            layer: OverlayLayer::Colour([255, 255, 255]),
            alpha: 0.5,
        };
        assert_eq!(a, a);
        assert_ne!(a.layer, OverlayLayer::FrozenFrame);
    }
}
