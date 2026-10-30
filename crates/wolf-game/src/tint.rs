//! Whole-screen colour multiplier driven by opcode 151 ChangeColor.
//!
//! WOLF's screen colour tone command tints the screen layers -- the map and every
//! picture whose number is negative -- without touching the HUD (pictures 0 and
//! above). The value is a per-channel multiplier expressed as a percentage: 100 is
//! neutral, 150 brightens, 40 darkens. The top byte of the packed operand is the
//! flash flag: a flash ramps to the colour and straight back to where it started,
//! so a one-shot 151 leaves the screen as it found it.
//!
//! The store keeps from/to, a frame clock and the flash flag. The host ticks it
//! once per frame; ScreenTint::rgb hands the renderer the multiplier that frame's
//! sprites must be drawn with.

/// Screen-wide colour multiplier (a 151 ChangeColor ramp).
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct ScreenTint {
    /// Colour the ramp started from, [1, 1, 1] when neutral.
    from: [f32; 3],
    /// Colour the ramp is heading for.
    to: [f32; 3],
    /// Frames advanced so far.
    elapsed: u32,
    /// Total ramp length in frames (0 = instant).
    duration: u32,
    /// True when the ramp returns to from after peaking at to.
    flash: bool,
}

impl Default for ScreenTint {
    fn default() -> Self {
        Self {
            from: [1.0; 3],
            to: [1.0; 3],
            elapsed: 0,
            duration: 0,
            flash: false,
        }
    }
}

impl ScreenTint {
    /// A neutral tint ([1, 1, 1]).
    #[must_use]
    pub fn new() -> Self {
        Self::default()
    }

    /// Installs a 151 ChangeColor request.
    ///
    /// colour packs R/G/B in bits 16/8/0 as percentages (100 = neutral) and the
    /// flash flag in bit 24. frames is the ramp length; 0 (or negative) applies
    /// the colour at once. The current multiplier becomes the new ramp's origin,
    /// so overlapping requests blend rather than jump.
    pub fn set(&mut self, colour: i32, frames: i32) {
        self.from = self.rgb();
        self.to = [channel(colour, 16), channel(colour, 8), channel(colour, 0)];
        self.flash = (colour & 0x0100_0000) != 0;
        self.duration = u32::try_from(frames.max(0)).unwrap_or(0);
        self.elapsed = 0;
    }

    /// Current multiplier. [1, 1, 1] leaves the screen untouched.
    #[must_use]
    pub fn rgb(&self) -> [f32; 3] {
        if self.duration == 0 || self.elapsed >= self.duration {
            return if self.flash { self.from } else { self.to };
        }
        let t = self.elapsed as f32 / self.duration as f32;
        // A flash is a triangle wave over the same duration: out to to at the
        // halfway point, then back to from.
        let f = if self.flash {
            if t < 0.5 {
                t * 2.0
            } else {
                (1.0 - t) * 2.0
            }
        } else {
            t
        };
        lerp(self.from, self.to, f)
    }

    /// Advances the ramp one frame.
    pub fn tick(&mut self) {
        if self.elapsed < self.duration {
            self.elapsed += 1;
        }
    }

    /// True when the multiplier is [1, 1, 1], i.e. drawing can skip it.
    #[must_use]
    pub fn is_neutral(&self) -> bool {
        self.rgb() == [1.0, 1.0, 1.0]
    }
}

/// Extracts one channel of a packed 151 colour as a multiplier (100 -> 1.0).
fn channel(colour: i32, shift: u32) -> f32 {
    let byte = ((colour >> shift) & 0xFF) as u32;
    byte as f32 / 100.0
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
    }

    #[test]
    fn non_flash_ramps_to_the_colour_and_holds() {
        // Dungeon event 3 pc4: R40 G30 B30, 15 frames (2629150 = 0x281E1E).
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
        assert!((done[0] - 0.40).abs() < 1e-5);
        assert!((done[1] - 0.30).abs() < 1e-5);
        assert!((done[2] - 0.30).abs() < 1e-5);
    }

    #[test]
    fn flash_peaks_at_the_colour_and_returns() {
        // Dungeon event 1 pc4: flash R150 G200 B150, 20 frames (0x0196C896).
        let mut tint = ScreenTint::new();
        tint.set(0x0196_C896, 20);
        assert_eq!(tint.rgb(), [1.0, 1.0, 1.0]);
        for _ in 0..10 {
            tint.tick();
        }
        let peak = tint.rgb();
        assert!((peak[0] - 1.50).abs() < 1e-5, "peak red {}", peak[0]);
        assert!((peak[1] - 2.00).abs() < 1e-5, "peak green {}", peak[1]);
        assert!((peak[2] - 1.50).abs() < 1e-5, "peak blue {}", peak[2]);
        for _ in 0..10 {
            tint.tick();
        }
        assert_eq!(tint.rgb(), [1.0, 1.0, 1.0], "flash ends where it began");
    }

    #[test]
    fn zero_frames_applies_immediately() {
        let mut tint = ScreenTint::new();
        tint.set(0x00_64_64_64, 0); // 100/100/100 neutral, no flash
        assert_eq!(tint.rgb(), [1.0, 1.0, 1.0]);
        tint.set(0x00_32_32_32, 0); // 50/50/50 instantly
        assert!((tint.rgb()[0] - 0.5).abs() < 1e-6);
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
}
