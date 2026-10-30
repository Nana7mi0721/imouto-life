//! Integer nearest-neighbour upscale from the 1024x576 logical frame to the window.
//!
//! Why integer-only (docs/ARCHITECTURE.md §3.4): every pixel of a WOLF screen is authored
//! at a fixed size, and the `150` Picture command stores absolute coordinates written
//! against a 1024-wide screen. Scaling by 1.5 or 2.25 leaves some source pixels 1 screen
//! pixel wide and their neighbours 2, so any scrolling background shimmers with a visible
//! seam that walks across the screen. Restricting the factor to an integer keeps every
//! source pixel a perfect square block; the cost is black bars, which we fill on purpose.
//!
//! The remaining choice is *who* scales: letting Windows/the driver stretch the window
//! (or a swapchain `scaling: Stretch`) goes through the compositor's bilinear filter and
//! breaks the pixel grid, and winit 0.30 hands us *physical* pixels whose relation to the
//! logical 1024x576 canvas depends on per-monitor DPI. So we never hand the blit to the OS:
//! the scale factor is computed here, on the CPU, in physical pixels.

/// Width of the logical game canvas, in pixels.
pub const LOGICAL_W: u32 = 1024;
/// Height of the logical game canvas, in pixels.
pub const LOGICAL_H: u32 = 576;

/// The integer scale factor and the centred placement it implies.
///
/// All values are in *physical* window pixels.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Scaler {
    /// Integer magnification, always `>= 1`.
    pub scale: u32,
    /// Top-left corner of the scaled image, relative to the window's top-left.
    ///
    /// Negative when the window is smaller than 1024x576 on one axis: the image then
    /// overflows and the GPU clips the overhang, which is what we want (the alternative,
    /// squashing to fit, would break the pixel grid).
    pub offset: [i32; 2],
    /// Size of the scaled image in physical pixels, i.e. `(1024, 576) * scale`.
    pub used: [u32; 2],
}

/// `(1024, 576) * scale` fitted into `win`, centred, with the largest integer factor.
///
/// `scale = max(1, min(win_w / 1024, win_h / 576))`.
#[must_use]
pub fn integer_scale(win_w: u32, win_h: u32) -> Scaler {
    let by_w = win_w / LOGICAL_W;
    let by_h = win_h / LOGICAL_H;
    let scale = by_w.min(by_h).max(1);
    let used = [LOGICAL_W * scale, LOGICAL_H * scale];
    let offset = [
        (win_w as i32 - used[0] as i32) / 2,
        (win_h as i32 - used[1] as i32) / 2,
    ];
    Scaler {
        scale,
        offset,
        used,
    }
}

impl Scaler {
    /// Computes the scaler for a physical window size.
    #[must_use]
    pub fn new(win_w: u32, win_h: u32) -> Self {
        integer_scale(win_w, win_h)
    }

    /// The scaled image as a clip-space quad: `(centre, half_extent)`, both in NDC.
    ///
    /// Returning NDC rather than pixels means the blit vertex shader performs no arithmetic
    /// at all — it interpolates a corner over this quad — so the mapping is defined in one
    /// place (here) and covered by the unit tests below.
    ///
    /// NDC has +Y up while window pixels have +Y down, so the Y offset is negated.
    #[must_use]
    pub fn ndc_quad(&self, win_w: u32, win_h: u32) -> (glam::Vec2, glam::Vec2) {
        let w = win_w.max(1) as f32;
        let h = win_h.max(1) as f32;
        let cx = self.offset[0] as f32 + self.used[0] as f32 * 0.5;
        let cy = self.offset[1] as f32 + self.used[1] as f32 * 0.5;
        let centre = glam::vec2(cx / w * 2.0 - 1.0, 1.0 - cy / h * 2.0);
        let half = glam::vec2(
            self.used[0] as f32 * 0.5 / w * 2.0,
            self.used[1] as f32 * 0.5 / h * 2.0,
        );
        (centre, half)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    /// One table row: window size, then the scaler values we expect from it.
    type Case = (u32, u32, u32, [i32; 2], [u32; 2]);

    /// `(window w, window h, expected scale, expected offset, expected used size)`.
    const CASES: &[Case] = &[
        // Exact 1:1 -> no bars at all.
        (1024, 576, 1, [0, 0], [1024, 576]),
        // 1080p is 1.875x, which is not an integer: we refuse to stretch and centre 1x
        // inside the window instead, leaving symmetric bars.
        (1920, 1080, 1, [448, 252], [1024, 576]),
        // Exact 2.5x -> 2x with bars.
        (2560, 1440, 2, [256, 144], [2048, 1152]),
        // Narrower and shorter-than-2x windows: min() still yields 1, and the width
        // offset goes negative so the overhang is clipped evenly on both sides.
        (1000, 700, 1, [-12, 62], [1024, 576]),
        // Exact 3.75x -> 3x.
        (3840, 2160, 3, [384, 216], [3072, 1728]),
    ];

    #[test]
    fn scale_and_centring_match_the_contract() {
        for &(w, h, scale, offset, used) in CASES {
            let s = integer_scale(w, h);
            assert_eq!(s.scale, scale, "scale for {w}x{h}");
            assert_eq!(s.offset, offset, "offset for {w}x{h}");
            assert_eq!(s.used, used, "used for {w}x{h}");
        }
    }

    #[test]
    fn scale_is_never_zero_and_the_image_always_fits_or_overflows_evenly() {
        for w in [1, 512, 1024, 1025, 2047, 2560, 3000] {
            for h in [1, 300, 576, 577, 1151, 1440, 2000] {
                let s = integer_scale(w, h);
                assert!(s.scale >= 1, "{w}x{h}");
                // Offsets differ from an exact centring by at most one pixel (integer div).
                let dx = w as i32 - s.used[0] as i32 - 2 * s.offset[0];
                let dy = h as i32 - s.used[1] as i32 - 2 * s.offset[1];
                assert!((-1..=1).contains(&dx), "x remainder {dx} at {w}x{h}");
                assert!((-1..=1).contains(&dy), "y remainder {dy} at {w}x{h}");
            }
        }
    }

    #[test]
    fn ndc_quad_is_the_unit_square_at_one_to_one() {
        let s = integer_scale(1024, 576);
        let (centre, half) = s.ndc_quad(1024, 576);
        assert_eq!(centre, glam::Vec2::ZERO);
        assert_eq!(half, glam::Vec2::ONE);
    }

    #[test]
    fn ndc_quad_stays_inside_the_viewport_when_letterboxed() {
        let s = integer_scale(1920, 1080);
        let (centre, half) = s.ndc_quad(1920, 1080);
        // 1024 / 1920 in NDC half-width, 576 / 1080 in NDC half-height.
        assert!((half.x - 1024.0 / 1920.0).abs() < 1e-6, "{half:?}");
        assert!((half.y - 576.0 / 1080.0).abs() < 1e-6, "{half:?}");
        // Horizontally centred (448 px left bar == right bar), so x centre is 0.
        assert!(centre.x.abs() < 1e-6, "{centre:?}");
        assert!(centre.y.abs() < 1e-6, "{centre:?}");
    }
}
