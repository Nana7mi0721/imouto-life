//! Whole-screen colour state driven by opcode 151 ChangeColor.
//!
//! In the retail engine 151 feeds two independent stores (docs/re/TRANSITION.md
//! section 4, FUN_0045ca90 / FUN_004a57d0 / FUN_004bf5b0 / FUN_004a5870 /
//! FUN_004c25f0):
//!
//! * An ordinary 151 ramps a per-channel "brightness" from its current value to
//!   255 + (p - 100) * 255 / 100 (clamped to 0..=255) over the given frames, and
//!   that value is pushed to DxLib's SetDrawBright, which multiplies every
//!   sprite drawn afterwards. Because the result clamps at 255 = neutral, a
//!   channel above 100 does **not** brighten: 150 and 200 are both neutral. This
//!   is a luminance scale, not an RGB multiplier that can overflow.
//! * A flash (bit 24 of the packed colour) never touches the brightness store.
//!   It queues a full-screen DrawBox whose colour is the same clamp(p) per
//!   channel and whose alpha is remaining / total, decaying linearly to zero.
//!   The shipped 150/200/150 flash is therefore a solid white frame fading out
//!   over 20 frames, not a coloured pulse.
//!
//! The 151 tint only affects the map and the negative-numbered screen pictures
//! (the HUD is drawn with a reset brightness); the flash overlay covers the
//! whole composited frame.

/// Screen-wide colour state held between frames: a brightness ramp plus, when
/// a flash was requested, a full-screen colour overlay.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct ScreenTint {
    /// Multiplier the ramp started from, [1, 1, 1] when neutral.
    from: [f32; 3],
    /// Multiplier the ramp is heading for.
    to: [f32; 3],
    /// Frames advanced so far.
    elapsed: u32,
    /// Total ramp length in frames (0 = instant).
    duration: u32,
    /// A flash overlay that is fading out, if one was requested.
    flash: Option<Flash>,
}

/// One 151 flash: a full-screen colour quad fading out linearly.
#[derive(Clone, Copy, Debug, PartialEq)]
struct Flash {
    /// Clamped colour of the quad, 0..=255 per channel.
    colour: [u8; 3],
    /// Frames left; the quad's alpha is remaining / duration.
    remaining: u32,
    /// Total fade length in frames.
    duration: u32,
}

impl Default for ScreenTint {
    fn default() -> Self {
        Self {
            from: [1.0; 3],
            to: [1.0; 3],
            elapsed: 0,
            duration: 0,
            flash: None,
        }
    }
}

impl ScreenTint {
    /// A neutral tint ([1, 1, 1], no flash).
    #[must_use]
    pub fn new() -> Self {
        Self::default()
    }

    /// Installs a 151 ChangeColor request.
    ///
    /// The packed colour holds R/G/B in bits 16/8/0 as percentages (100 =
    /// neutral) and the flash flag in bit 24. frames is the ramp length; 0
    /// applies the value at once. An ordinary request ramps from the current
    /// multiplier so overlapping requests blend rather than jump; a flash
    /// queues its overlay and leaves the brightness ramp alone.
    pub fn set(&mut self, colour: i32, frames: i32) {
        let frames = u32::try_from(frames.max(0)).unwrap_or(0);
        if colour & 0x0100_0000 != 0 {
            let duration = frames.max(1);
            self.flash = Some(Flash {
                colour: [
                    flash_byte(colour, 16),
                    flash_byte(colour, 8),
                    flash_byte(colour, 0),
                ],
                remaining: duration,
                duration,
            });
            return;
        }
        self.from = self.rgb();
        self.to = [
            brightness(colour, 16),
            brightness(colour, 8),
            brightness(colour, 0),
        ];
        self.duration = frames;
        self.elapsed = 0;
    }

    /// Current brightness multiplier for the map and screen pictures.
    ///
    /// [1, 1, 1] leaves the frame untouched; a channel clamped at neutral
    /// cannot exceed 1.
    #[must_use]
    pub fn rgb(&self) -> [f32; 3] {
        if self.duration == 0 || self.elapsed >= self.duration {
            return self.to;
        }
        let t = self.elapsed as f32 / self.duration as f32;
        lerp(self.from, self.to, t)
    }

    /// The flash overlay to composite over the frame, if one is still fading.
    ///
    /// Returns the clamped colour and the alpha (1.0 on the first frame, 0
    /// once faded out).
    #[must_use]
    pub fn flash_overlay(&self) -> Option<([u8; 3], f32)> {
        let flash = self.flash?;
        if flash.remaining == 0 {
            return None;
        }
        let alpha = flash.remaining as f32 / flash.duration as f32;
        Some((flash.colour, alpha))
    }

    /// Advances the ramp and the flash one frame.
    pub fn tick(&mut self) {
        if self.elapsed < self.duration {
            self.elapsed += 1;
        }
        if let Some(flash) = &mut self.flash {
            flash.remaining = flash.remaining.saturating_sub(1);
            if flash.remaining == 0 {
                self.flash = None;
            }
        }
    }

    /// True when nothing is tinting the screen, i.e. drawing can skip it.
    #[must_use]
    pub fn is_neutral(&self) -> bool {
        self.rgb() == [1.0, 1.0, 1.0] && self.flash.is_none()
    }
}

/// Clamps a 151 channel percentage to DxLib's SetDrawBright range.
///
/// The retail conversion is the integer expression
/// ((p - 100) * 255) / 100 + 255, truncated toward zero like the C original,
/// then clamped to 0..=255. 100 maps to 255 (neutral) and anything at or above
/// 100 also clamps to 255.
fn brightness_int(colour: i32, shift: u32) -> i32 {
    let percent = (colour >> shift) & 0xFF;
    ((percent - 100) * 255 / 100 + 255).clamp(0, 255)
}

/// Brightness multiplier (100 -> 1.0, 40 -> 102/255).
fn brightness(colour: i32, shift: u32) -> f32 {
    brightness_int(colour, shift) as f32 / 255.0
}

/// Flash quad colour byte: the same conversion, clamped to 0..=255.
fn flash_byte(colour: i32, shift: u32) -> u8 {
    brightness_int(colour, shift) as u8
}

fn lerp(a: [f32; 3], b: [f32; 3], t: f32) -> [f32; 3] {
    [
        a[0] + (b[0] - a[0]) * t,
        a[1] + (b[1] - a[1]) * t,
        a[2] + (b[2] - a[2]) * t,
    ]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn default_is_neutral() {
        let tint = ScreenTint::new();
        assert_eq!(tint.rgb(), [1.0, 1.0, 1.0]);
        assert!(tint.is_neutral());
        assert_eq!(tint.flash_overlay(), None);
    }

    #[test]
    fn ordinary_ramps_to_the_colour_and_holds() {
        // Dungeon event 3: R40 G30 B30, 15 frames (2629150 = 0x281E1E).
        let mut tint = ScreenTint::new();
        tint.set(2_629_150, 15);
        assert_eq!(tint.rgb(), [1.0, 1.0, 1.0], "starts at the old value");
        tint.tick();
        let early = tint.rgb();
        assert!(early[0] < 1.0 && early[0] > 0.40);
        for _ in 0..14 {
            tint.tick();
        }
        let done = tint.rgb();
        // 40% -> 102/255, 30% -> 77/255, exactly like the retail shorts.
        assert!((done[0] - 102.0 / 255.0).abs() < 1e-6);
        assert!((done[1] - 77.0 / 255.0).abs() < 1e-6);
        assert!((done[2] - 77.0 / 255.0).abs() < 1e-6);
    }

    #[test]
    fn brightness_above_100_is_neutral_not_a_multiplier() {
        // A 150% channel clamps to 255 = neutral; the old code multiplied by 1.5.
        let mut tint = ScreenTint::new();
        tint.set(0x00_96_96_96, 5);
        for _ in 0..5 {
            tint.tick();
        }
        assert_eq!(tint.rgb(), [1.0, 1.0, 1.0]);
        assert!(tint.is_neutral());
    }

    #[test]
    fn flash_is_a_white_quad_that_fades_out() {
        // Dungeon event 1: flash R150 G200 B150, 20 frames (0x0196C896).
        // All three channels clamp to 255: a solid white flash.
        let mut tint = ScreenTint::new();
        tint.set(0x0196_C896, 20);
        assert_eq!(tint.rgb(), [1.0, 1.0, 1.0], "flash leaves brightness alone");
        assert_eq!(tint.flash_overlay(), Some(([255, 255, 255], 1.0)));
        for _ in 0..10 {
            tint.tick();
        }
        let (colour, alpha) = tint.flash_overlay().expect("still fading");
        assert_eq!(colour, [255, 255, 255]);
        assert!((alpha - 0.5).abs() < 1e-6, "alpha {alpha}");
        for _ in 0..9 {
            tint.tick();
        }
        assert!(tint.flash_overlay().is_some(), "last frame still visible");
        tint.tick();
        assert_eq!(tint.flash_overlay(), None, "fades out after 20 ticks");
        assert!(tint.is_neutral());
    }

    #[test]
    fn dark_flash_uses_the_unclamped_colour() {
        // 40% flash -> 102 per channel, not white.
        let mut tint = ScreenTint::new();
        tint.set(0x01_28_28_28, 4);
        assert_eq!(tint.flash_overlay(), Some(([102, 102, 102], 1.0)));
    }

    #[test]
    fn zero_frames_applies_immediately() {
        let mut tint = ScreenTint::new();
        tint.set(0x00_64_64_64, 0); // 100/100/100 neutral, no flash
        assert_eq!(tint.rgb(), [1.0, 1.0, 1.0]);
        tint.set(0x00_32_32_32, 0); // 50/50/50 instantly
        assert!((tint.rgb()[0] - 128.0 / 255.0).abs() < 1e-6);
    }

    #[test]
    fn neutral_reset_after_darkening() {
        // Dungeon event 3 issues 151 dark, then later 151 0x646464 to restore.
        let mut tint = ScreenTint::new();
        tint.set(2_629_150, 15);
        for _ in 0..15 {
            tint.tick();
        }
        assert!(!tint.is_neutral());
        tint.set(0x00_64_64_64, 15);
        for _ in 0..15 {
            tint.tick();
        }
        assert!(tint.is_neutral());
    }

    #[test]
    fn flash_and_brightness_are_independent() {
        let mut tint = ScreenTint::new();
        tint.set(0x00_28_28_28, 2); // dark ramp
        tint.set(0x01_FF_FF_FF, 4); // white flash on top
        for _ in 0..2 {
            tint.tick();
        }
        assert!(!tint.is_neutral(), "ramp still dark");
        assert!(tint.flash_overlay().is_some(), "flash still fading");
        for _ in 0..2 {
            tint.tick();
        }
        assert_eq!(tint.flash_overlay(), None);
        assert!(
            (tint.rgb()[0] - 102.0 / 255.0).abs() < 1e-6,
            "the ramp is unaffected by the flash"
        );
    }
}
