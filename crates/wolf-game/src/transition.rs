//! Whole-screen transition mask driven by opcodes 160/161/162.
//!
//! WOLF's transition opcodes select a fade mask (156/160 install it, 161 freezes
//! the drawn screen, 162 runs the animation and blocks the script for the
//! configured number of frames). The only shipped call in this game is CE48
//! `[-1, 0x0001_000A]`: `kind -1` is a hard cut with no mask, so it stays a
//! cut and this store stays inactive.
//!
//! A real mask (SystemFile/[Transition]Fade.png, an 8-bit grey 640x480 wipe) is
//! not reproduced here. What a visible, deterministic transition in a headless
//! renderer needs is the *effect*: the screen dims through black over the frame
//! count and comes back. That is what this store models, exactly like
//! [`crate::tint::ScreenTint`] models a 151 ramp: the host ticks it once per
//! frame and the renderer multiplies the whole screen (tile layer *and* picture
//! layer) by [`ScreenTransition::brightness`].
//!
//! Keeping it in the same overlay path as the tint means both `capture` and
//! `capture --map` composite the fade over the tiles and the pictures they draw.

/// Whole-screen fade used by opcodes 160/161/162.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct ScreenTransition {
    /// Frames advanced so far.
    elapsed: u32,
    /// Total animation length in frames (>= 1 while active).
    duration: u32,
    /// True between the 162 execute and the end of the animation.
    active: bool,
}

impl Default for ScreenTransition {
    fn default() -> Self {
        Self {
            elapsed: 0,
            duration: 0,
            active: false,
        }
    }
}

impl ScreenTransition {
    /// An inactive (no-op) transition.
    #[must_use]
    pub fn new() -> Self {
        Self::default()
    }

    /// Installs a 160/162 request.
    ///
    /// `kind < 0` is the shipped hard cut: no mask, nothing to draw, the store
    /// stays inactive. For `kind >= 0` the animation runs over `frames` frames
    /// (a zero duration is treated as one frame, matching `TransitionState`).
    pub fn start(&mut self, kind: i32, frames: u32) {
        if kind < 0 {
            self.cancel();
            return;
        }
        self.elapsed = 0;
        self.duration = frames.max(1);
        self.active = true;
    }

    /// Drops the transition to a hard cut / neutral screen.
    pub fn cancel(&mut self) {
        self.elapsed = 0;
        self.duration = 0;
        self.active = false;
    }

    /// Advances the animation one frame.
    pub fn tick(&mut self) {
        if self.active && self.elapsed < self.duration {
            self.elapsed += 1;
        }
    }

    /// True while the fade is running.
    #[must_use]
    pub fn is_active(&self) -> bool {
        self.active
    }

    /// Fraction of the animation completed, in `[0, 1]`.
    #[must_use]
    pub fn progress(&self) -> f32 {
        if !self.active || self.duration == 0 {
            return 0.0;
        }
        (self.elapsed as f32 / self.duration as f32).min(1.0)
    }

    /// Whole-screen brightness multiplier for the current frame.
    ///
    /// `1.0` leaves the frame untouched. While active it is a triangle wave:
    /// 1.0 at the start, 0.0 at the midpoint (fully black) and 1.0 again at the
    /// end, i.e. the screen fades out through black and back in over `frames`.
    #[must_use]
    pub fn brightness(&self) -> f32 {
        if !self.active || self.duration == 0 {
            return 1.0;
        }
        let t = self.progress();
        (2.0 * t - 1.0).abs()
    }

    /// Opacity of the black overlay (`1 - brightness`); 0 at the ends, 1 at the midpoint.
    #[must_use]
    pub fn alpha(&self) -> f32 {
        1.0 - self.brightness()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn inactive_is_neutral() {
        let t = ScreenTransition::new();
        assert!(!t.is_active());
        assert_eq!(t.brightness(), 1.0);
        assert_eq!(t.alpha(), 0.0);
    }

    #[test]
    fn hard_cut_stays_neutral() {
        let mut t = ScreenTransition::new();
        t.start(-1, 10);
        assert!(!t.is_active());
        assert_eq!(t.brightness(), 1.0);
        for _ in 0..20 {
            t.tick();
        }
        assert_eq!(t.brightness(), 1.0);
    }

    #[test]
    fn fade_dims_at_midpoint_and_returns() {
        let mut t = ScreenTransition::new();
        t.start(0, 10);
        assert!(t.is_active());
        assert!((t.brightness() - 1.0).abs() < 1e-6, "starts bright");
        // Advance to the midpoint.
        for _ in 0..5 {
            t.tick();
        }
        assert!(t.progress() >= 0.5 - 1e-6);
        assert!(
            t.brightness() < 0.05,
            "midpoint is black, got {}",
            t.brightness()
        );
        assert!(t.alpha() > 0.95, "overlay alpha ramps to opaque");
        // Run it out; the screen comes back.
        for _ in 0..5 {
            t.tick();
        }
        assert!((t.brightness() - 1.0).abs() < 1e-6, "ends bright");
        assert!((t.alpha()).abs() < 1e-6);
    }

    #[test]
    fn zero_frames_is_one_frame() {
        let mut t = ScreenTransition::new();
        t.start(3, 0);
        assert_eq!(t.duration, 1);
        t.tick();
        assert!(t.brightness() <= 1.0);
    }
}
