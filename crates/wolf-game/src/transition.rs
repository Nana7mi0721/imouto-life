//! Whole-screen transition driven by opcodes 160/161/162.
//!
//! The retail engine's transition is a **cross-dissolve of the frozen previous
//! frame**, not a fade through black (docs/re/TRANSITION.md):
//!
//! * 160 installs the setting -- kind in arg0, duration in flags & 0xffff, the
//!   "wait" bit at 0x1_0000 -- and loads the mask picture; it draws nothing and
//!   does not block the script.
//! * 161 copies the composited screen into the engine's "old frame" graph.
//! * 162 starts the animation and blocks the script for duration frames.
//!
//! Each frame the engine draws the old frame over the freshly drawn scene with
//! SetDrawBlendMode(ALPHA, 255 * elapsed / duration), elapsed counting down
//! from duration to 0 (FUN_004c28d0, ticked by FUN_004c2a80). The old frame
//! therefore starts fully opaque and fades out linearly, revealing the new
//! scene: a 10-frame dissolve for this game's only shipped call, CE48
//! [-1, 0x0001_000A].
//!
//! The masked branch (kind >= 0, e.g. [Transition]Fade.png) feathers the same
//! dissolve through a grey mask; this game never issues one, so no mask is
//! loaded and the dissolve is uniform.
//!
//! ScreenTransition models exactly that: execute() starts the ramp, tick()
//! counts the frames down, and alpha() is the opacity the renderer draws the
//! frozen frame with.

/// Whole-screen cross-dissolve used by opcodes 160/161/162.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct ScreenTransition {
    /// Transition type from 160; negative means "no mask".
    kind: i32,
    /// Raw 160 flags: duration in the low 16 bits, wait bit at 0x1_0000.
    flags: i32,
    /// Animation length in frames (>= 1).
    duration: u32,
    /// Frames left before the old frame is fully gone; counts down to 0.
    remaining: u32,
    /// True between 162 and the end of the animation.
    active: bool,
    /// Set by 161: the host must copy the current frame before drawing again.
    freeze_requested: bool,
}

impl Default for ScreenTransition {
    fn default() -> Self {
        Self {
            kind: 0,
            flags: 0,
            duration: 1,
            remaining: 0,
            active: false,
            freeze_requested: false,
        }
    }
}

impl ScreenTransition {
    /// An inactive (no-op) transition.
    #[must_use]
    pub fn new() -> Self {
        Self::default()
    }

    /// 160 InstallTransition: stores the setting and loads the mask.
    ///
    /// The duration is flags & 0xffff (the retail engine masks the operand,
    /// not just the low byte); a zero duration still runs for one frame.
    /// Installing does not start the animation and does not cancel a running
    /// one -- only 162 moves the screen.
    pub fn install(&mut self, kind: i32, flags: i32) {
        self.kind = kind;
        self.flags = flags;
        self.duration = u32::try_from(flags & 0xFFFF).unwrap_or(1).max(1);
    }

    /// 161 PrepareTransition: freeze the screen that is currently drawn.
    pub fn prepare(&mut self) {
        self.freeze_requested = true;
    }

    /// 162 ExecuteTransition: start the dissolve, blocking for duration frames.
    ///
    /// The retail engine ignores an execute while a transition is already
    /// running (FUN_0045ceb0: DAT_00a14062 != 0 -> return false), keeping the
    /// remaining frames of the one in flight.
    pub fn execute(&mut self) {
        if self.active {
            return;
        }
        self.remaining = self.duration.max(1);
        self.active = true;
        // 162 implicitly prepares when 161 was skipped (FUN_0045ceb0 does the
        // same), but the host must still capture the frame it is replacing.
        self.freeze_requested = true;
    }

    /// Takes the pending freeze request, if any.
    pub fn take_freeze_request(&mut self) -> bool {
        std::mem::take(&mut self.freeze_requested)
    }

    /// Drops the transition and any pending freeze.
    pub fn cancel(&mut self) {
        self.remaining = 0;
        self.active = false;
        self.freeze_requested = false;
    }

    /// Advances the animation one frame.
    ///
    /// The retail tick subtracts one (its frame step is DAT_0084b244 = 1 at
    /// 60 Hz) and lets the counter overshoot to -10 before stopping; clamping
    /// at zero is invisible because the overlay alpha is already zero there.
    pub fn tick(&mut self) {
        if !self.active {
            return;
        }
        self.remaining = self.remaining.saturating_sub(1);
        if self.remaining == 0 {
            self.active = false;
        }
    }

    /// True while the dissolve is running.
    #[must_use]
    pub fn is_active(&self) -> bool {
        self.active
    }

    /// Opacity of the frozen old frame for the current frame, in [0, 1].
    ///
    /// 1.0 on the first frame (only the old screen is visible), 0.0 once the
    /// animation has run out (only the new scene is visible).
    #[must_use]
    pub fn alpha(&self) -> f32 {
        if !self.active || self.duration == 0 {
            return 0.0;
        }
        self.remaining as f32 / self.duration as f32
    }

    /// Fraction of the dissolve completed, in [0, 1].
    #[must_use]
    pub fn progress(&self) -> f32 {
        1.0 - self.alpha()
    }

    /// Installed transition type (-1 = no mask).
    #[must_use]
    pub fn kind(&self) -> i32 {
        self.kind
    }

    /// Raw 160 flags, including the wait bit.
    #[must_use]
    pub fn flags(&self) -> i32 {
        self.flags
    }

    /// Animation length in frames.
    #[must_use]
    pub fn duration(&self) -> u32 {
        self.duration
    }

    /// True when the installed kind wants a mask this build does not draw.
    #[must_use]
    pub fn wants_mask(&self) -> bool {
        self.kind >= 0
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn inactive_is_transparent() {
        let mut t = ScreenTransition::new();
        assert!(!t.is_active());
        assert_eq!(t.alpha(), 0.0);
        assert_eq!(t.progress(), 1.0);
        assert!(!t.take_freeze_request());
    }

    #[test]
    fn install_alone_draws_nothing() {
        // CE48 pc145 is the only 160 in the game: no 161/162 follows it, so a
        // boot-time transition must stay invisible.
        let mut t = ScreenTransition::new();
        t.install(-1, 0x0001_000A);
        assert_eq!(t.duration(), 10);
        assert_eq!(t.kind(), -1);
        assert!(!t.is_active());
        assert_eq!(t.alpha(), 0.0);
        assert!(!t.take_freeze_request(), "160 does not freeze the screen");
        for _ in 0..20 {
            t.tick();
        }
        assert_eq!(t.alpha(), 0.0);
    }

    #[test]
    fn prepare_requests_one_freeze() {
        let mut t = ScreenTransition::new();
        t.install(-1, 0x000A);
        t.prepare();
        assert!(t.take_freeze_request());
        assert!(!t.take_freeze_request(), "the request is consumed once");
    }

    #[test]
    fn execute_dissolves_the_frozen_frame_linearly() {
        let mut t = ScreenTransition::new();
        t.install(-1, 0x000A);
        t.prepare();
        t.execute();
        assert!(t.is_active());
        assert!((t.alpha() - 1.0).abs() < 1e-6, "old frame fully opaque");
        t.tick();
        assert!((t.alpha() - 0.9).abs() < 1e-6);
        for _ in 0..9 {
            t.tick();
        }
        assert_eq!(t.alpha(), 0.0, "new frame fully visible");
        assert!(!t.is_active());
    }

    #[test]
    fn execute_while_active_keeps_the_one_in_flight() {
        let mut t = ScreenTransition::new();
        t.install(-1, 0x000A);
        t.execute();
        for _ in 0..4 {
            t.tick();
        }
        let before = t.alpha();
        t.execute();
        assert_eq!(t.alpha(), before, "a second 162 is ignored");
    }

    #[test]
    fn duration_comes_from_the_low_16_bits() {
        let mut t = ScreenTransition::new();
        // 0x0001_0100 = wait + 256 frames; the low byte alone would read zero.
        t.install(-1, 0x0001_0100);
        assert_eq!(t.duration(), 0x0100);
    }

    #[test]
    fn zero_duration_is_one_frame() {
        let mut t = ScreenTransition::new();
        t.install(-1, 0);
        assert_eq!(t.duration(), 1);
        t.execute();
        assert!((t.alpha() - 1.0).abs() < 1e-6);
        t.tick();
        assert!(!t.is_active());
    }

    #[test]
    fn masked_kind_runs_the_same_uniform_dissolve() {
        // kind >= 0 wants [Transition]Fade.png; this build has no mask, so the
        // dissolve is uniform but still 10 frames long.
        let mut t = ScreenTransition::new();
        t.install(3, 0x000A);
        assert!(t.wants_mask());
        t.execute();
        assert!(t.is_active());
        assert!((t.alpha() - 1.0).abs() < 1e-6);
    }

    #[test]
    fn cancel_returns_to_neutral() {
        let mut t = ScreenTransition::new();
        t.install(-1, 0x000A);
        t.prepare();
        t.execute();
        t.tick();
        t.cancel();
        assert!(!t.is_active());
        assert_eq!(t.alpha(), 0.0);
        assert!(!t.take_freeze_request());
    }
}
