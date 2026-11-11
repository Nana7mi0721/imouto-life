//! The `150` Picture layer system.
//!
//! WOLF's pictures are not "one image on screen": every picture number is a persistent
//! slot with its own position, scale, opacity, blend mode and animation state, mutated in
//! place by later `150` instructions. The title screen alone issues 3,261 picture
//! operations in 200 frames (measured with `wolf-cli run --event 42`), and `150` is
//! the third most common opcode in the game (16,716 sites), so this store - not the
//! interpreter - is where most of the visual work lands.
//!
//! # Field layout (measured, not quoted)
//!
//! docs/OPCODE_SPEC.md section 5.20 describes the editor's argument order. Dumping the real
//! instructions out of work/full/BasicData/CommonEvent.dat shows a different but consistent
//! order for the long form (argc >= 11, after the type/number words):
//!
//! | args[..] | meaning | evidence |
//! |---|---|---|
//! | 0 | unknown flag word (0 everywhere except the title background, which uses 30) | ev42 pc20 |
//! | 1,2 | window width/height - only meaningful for the window picture kinds | ev42 draws a 300x200 window at (855,200) |
//! | 3 | constant 1 in every sample | |
//! | 4 | opacity, 0..255 | always 255 on the title path |
//! | 5 | x | pc43 feeds self-variables here |
//! | 6 | y | |
//! | 7 | uniform scale in percent, 100 = 1.0 | picture 12501 draws text at 100 |
//! | 8 | blend mode | 0 everywhere on the title path |
//! | 9.. | per-kind extras (window decoration flags, animation patterns, ...) | kept verbatim |
//!
//! The decisive sample is ev42 pc37: [0, -2, 0, 1, 1, 1, 255, 0, 0, 100, 0]
//! -> type 0 (file), number -2, window 1x1, opacity 255, x=0, y=0, scale=100, blend=0.
//! Reading x/y from args[0]/args[1] instead (as the editor docs suggest for short forms)
//! would put the 1024x576 title image at scale 1% - a 10x6 pixel dot.
//!
//! # The head word carries an anchor code in bits 12..14
//!
//! Grouping the 13,637 long-form draws of this game by that nibble shows the x/y values
//! are not free coordinates but are measured from an anchor:
//!
//! | bits | count | x seen | y seen | reading |
//! |---|---|---|---|---|
//! | 0x0000 | 8,911 | x=0 (5,782x) | y=0 (5,047x) | top-left, x/y is the corner |
//! | 0x1000 | 4,393 | x=512 (788x) | y=288 (216x) | centred on x/y |
//! | 0x2000 | 84 | x=384 (57x) | y=570 | unverified |
//! | 0x3000 | 105 | x=1000 | y=60 | unverified |
//! | 0x4000 | 67 | x=1024 | y=570 | unverified |
//! | 0x5000 | 8 | x=512 | y=0/100 | unverified |
//! | 0x6000 | 69 | x=800 | y=576 | unverified |
//!
//! 512 is exactly 1024/2 and 288 is exactly 576/2, i.e. the logical screen centre. The
//! decisive check is the retail title screen: TitleMap event 2 draws SystemFile/Button01.png
//! (606x35) with the 0x1000 flag at (512, 520). Anchored at the corner that banner would
//! cover x 512..1118 (clipped at the right edge) and y 520..555; the real screenshot shows
//! its ink at x 232..794, y 504..535 - which is the banner centred on (512, 520), with the
//! transparent margin of the PNG accounting for the remaining pixels. So 0x1000 anchors
//! BOTH axes on the centre.
//!
//! Only 0x0000 and 0x1000 are implemented; the other nibbles keep the corner behaviour and
//! are listed as unverified in docs/UNVERIFIED.md, because no title-screen instruction uses
//! them and guessing would move live pictures to the wrong place.
//!
//! # A move with a frame count slides instead of popping
//!
//! The long form of `150` can carry a frame count after the flag word: docs/OPCODE_SPEC.md
//! section 5.19 documents slots `[13..]` as 动画参数 and its worked example (`ev63 pc94`)
//! ends on `3`, the number of frames. The interpreter hands that tail over as
//! `PictureCmd::animate` (`args[11..]`, see crates/wolf-vm/src/exec.rs decode_picture), so
//! `animate[0]` is the duration and the slots after it are editor leftovers.
//!
//! Of the 3,365 moves in this game, 2,817 carry no tail at all and must keep teleporting, 168
//! carry a literal 0, 52 carry a self-variable reference that is not a frame count, and 328
//! carry a usable 2..=16 frames. The shape that matters is a PAIR: common event 63 parks its
//! message window with `... -1000000 -1000000 0 16777216` (pc93, no duration) and then repeats
//! the same command with `3` appended (pc94) to slide it into place over three frames;
//! pc102/pc103 do the same at opacity 255 with 2 frames, and event 64 repeats the pattern
//! with 2 and 4. The first command of every pair writes the state the picture is LEAVING, so a
//! slide has to start from the picture's own current x/y/scale/opacity - never from the
//! -1000000 UNCHANGED sentinels in slots 5/6/9/10, which mean "leave this field as it is".
//!
//! `Screen::advance` is the clock for those slides while `Screen::tick` stays the fade-in and
//! colour-effect clock; the host calls both once per frame. A finished slide is dropped and the
//! picture then draws exactly the fields the command asked for.
//!
//! # Negative numbers are fixed-screen layers
//!
//! Picture numbers below zero are the screen-fixed pictures: their x/y are not affected by
//! the map camera. They are *not* implicitly 1024x576. Retail data refutes the old
//! "whole-screen layer" shortcut (H-PIC-1 in docs/UNVERIFIED.md): slot -5 is the 48x64
//! save icon at (10,510) and slot -4 the data icon at (925,507), while the title and CG
//! backdrops happen to be 1024x576 at (0,0). Every negative picture therefore uses the same
//! native-size/scale/anchor placement law as a positive one; only its panning is fixed.

use std::collections::BTreeMap;

use wolf_vm::{PictureAction, PictureCmd};

/// The sentinel WOLF stores in a `150 Move` argument that must not change.
///
/// Only ever seen at the fields listed in the module docs (146/127/474/166 occurrences in
/// this game), never as a real coordinate.
pub const UNCHANGED: i32 = -1_000_000;

/// Logical screen width used when a picture is a whole-screen layer.
pub const SCREEN_W: u32 = 1024;
/// Logical screen height used when a picture is a whole-screen layer.
pub const SCREEN_H: u32 = 576;

/// Anchor code 0: x/y name the picture top-left corner.
pub const ANCHOR_TOP_LEFT: u8 = 0;
/// Anchor code 1 (head bit 0x1000): x/y name the picture centre.
pub const ANCHOR_CENTRE: u8 = 1;
/// Scale field value that means "no scaling" (percent).
pub const SCALE_ONE: i32 = 100;

/// Which argument slot of the long erase form carries the other end of the range.
///
/// The erase form is `150 [head, number, fade, fade, 0, other]`: after the head word the
/// interpreter hands the picture layer `[fade, fade, 0, other]`, so slot 3 is the second
/// picture number. 329 of the 1,115 erase instructions in this game use that form; the
/// remaining 751 are the short `[fade]` form and 35 carry a stray short tail.
pub const ERASE_SPAN: usize = 3;

/// Longest slide a `150` move may ask for, in frames.
///
/// The measured durations are 2..=16 and the fade-in ramp clamps at 600 for the same reason: a
/// larger word in the slot is a misread argument, and honouring one would park a picture in a
/// ten-second crawl instead of a two-frame nudge.
pub const MAX_TRANSITION_FRAMES: u32 = 600;

/// Field indices inside PictureCmd::args, from the table in the module docs.
pub mod field {
    /// Unknown flag word; 0 except for the title background (30).
    pub const FLAG: usize = 0;
    /// Fade-in length in frames, same slot as FLAG. 0 means the picture appears at once.
    /// Evidence: every splash draw in the boot chain carries 20 here and the retail
    /// disclaimer frame is exactly trunc(255 * age / 20) of the source art.
    pub const FADE_IN: usize = 0;
    /// Window width, for the window picture kinds.
    pub const WINDOW_W: usize = 1;
    /// Window height, for the window picture kinds.
    pub const WINDOW_H: usize = 2;
    /// Sprite-sheet cell number for file pictures, one-based; constant 1 in every
    /// plain draw. A `150` draw and a save record agree: retail save 90's 6 x 2
    /// `stand_imouto_paja2.png` carries pattern 2 here, and save 92's 7 x 1 eye strip
    /// carries pattern 7, which only fits a one-based count.
    pub const RESERVED: usize = 3;
    /// Opacity, 0..=255.
    pub const OPACITY: usize = 4;
    /// X position, in logical pixels.
    pub const X: usize = 5;
    /// Y position, in logical pixels.
    pub const Y: usize = 6;
    /// Uniform scale in percent (100 = 1.0).
    pub const SCALE: usize = 7;
    /// Blend mode.
    pub const BLEND: usize = 8;
    /// First field that is kind-specific.
    pub const EXTRAS: usize = 9;
    /// Red channel of the base tone, percent (100 = neutral).
    ///
    /// docs/OPCODE_290.md section 3.1 numbers these slots 15..17 in the raw
    /// instruction; PictureCmd::args starts at raw arg 2, so they land at 13..15
    /// here. Only the long form (raw argc 18 or more) carries them at all.
    pub const TONE_R: usize = 13;
    /// Green channel of the base tone, percent.
    pub const TONE_G: usize = 14;
    /// Blue channel of the base tone, percent.
    pub const TONE_B: usize = 15;
}

/// The five picture kinds, decoded from `(arg0 >> 4) & 7` by the interpreter.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum PictureKind {
    /// 0: a file named literally.
    File,
    /// 1: a file name read out of a string variable.
    FileString,
    /// 2: text drawn straight into the picture.
    Text,
    /// 3: a window/frame graphic named literally.
    WindowFile,
    /// 4: a window/frame graphic whose name comes from a string variable.
    ///
    /// The editor calls it "window text", but all 53 type-4 commands in this game name a
    /// FILE through that variable - common event 63 the window skin, common event 64 the face
    /// graphic - so it is drawn as a panel, never as text.
    WindowString,
}

impl PictureKind {
    /// Maps the interpreter's already-masked type code (0..=4) onto a kind.
    ///
    /// Unknown codes fall back to PictureKind::File rather than failing: an unrecognised
    /// picture must still occupy its slot, otherwise later `150 Move` instructions
    /// would silently target nothing.
    #[must_use]
    pub fn from_code(code: u8) -> Self {
        match code {
            1 => Self::FileString,
            2 => Self::Text,
            3 => Self::WindowFile,
            4 => Self::WindowString,
            _ => Self::File,
        }
    }

    /// True when the picture draws text rather than a texture.
    ///
    /// Only type 2: type 4 carries a string-variable FILE name (see [Self::WindowString]),
    /// and counting it as text emptied the picture the moment common event 63 created it.
    #[must_use]
    pub fn is_text(self) -> bool {
        matches!(self, Self::Text)
    }

    /// True for the two window/frame kinds, which are painted as panels, not as sprites.
    #[must_use]
    pub fn is_window(self) -> bool {
        matches!(self, Self::WindowFile | Self::WindowString)
    }
}

/// Per-channel draw brightness in percent: 100 is neutral, 0 is black.
///
/// This is the shape DxLib SetDrawBright takes, and the measurements in docs/OPCODE_290.md
/// force it: the retail title banner is its own artwork times 222/255 on every channel,
/// independent of the pixels behind it.
pub type Tone = [i32; 3];

/// The tone a picture has before any effect touches it.
pub const TONE_NEUTRAL: Tone = [SCALE_ONE, SCALE_ONE, SCALE_ONE];

/// Effect kind 0 (head nibble): single flash, the colour jumps to the target and decays back.
pub const EFFECT_FLASH: u8 = 0;
/// Effect kind 1: colour correction, an offset added to the base tone and kept until replaced.
///
/// This used to be read as "cancel the running flash". docs/OPCODE_290.md section 5.2 shows
/// the other reading is the right one: common event 8 highlights a menu row with
/// `290 [16, 1, 3200, 3200, 25, 25, 25]` and immediately clears the previous row with
/// `290 [16, 1, 3201, 3201, 0, 0, 0]`. An accumulating correction could never be cleared by
/// adding zero, and the game has no "clear all effects" instruction anywhere, so the
/// three args have to ASSIGN the offset.
pub const EFFECT_COLOR_CORRECT: u8 = 1;
/// Effect kind 2: drawing-coordinate shift, final value, kept until another shift replaces it.
pub const EFFECT_SHIFT: u8 = 2;
/// Effect kind 3: shake, a square wave alternating between +offset and -offset.
pub const EFFECT_SHAKE: u8 = 3;
/// Effect kind 4: zoom about a fixed point of the logical screen.
pub const EFFECT_ZOOM: u8 = 4;
/// Effect kind 5: automatic flash, the same ramp repeated for as long as the picture lives.
pub const EFFECT_BLINK: u8 = 5;
/// Effect kind 7: automatic expand and contract in percent, one excursion then a rest.
pub const EFFECT_BREATH: u8 = 7;
/// Effect kind 8: pattern switching, one pass then back to the command's own pattern.
pub const EFFECT_PATTERN_ONCE: u8 = 8;
/// Effect kind 9: pattern switching, looping back to the first pattern.
pub const EFFECT_PATTERN_LOOP: u8 = 9;
/// Effect kind 10: pattern switching, walking back and forth between the two ends.
pub const EFFECT_PATTERN_PINGPONG: u8 = 10;

/// A shake asking for at least this many repetitions is the author's way of writing
/// "until something else stops it", and never ages out.
///
/// docs/OPCODE_290.md section 5.3 measures the real counts: 99999 appears 124 times, 999
/// 52 times, 3 36 times, and 999999 twice. Nothing in the data sits near 100000 without
/// carrying that meaning, which is why the threshold is where the editor's own summary
/// text puts it.
pub const SHAKE_ENDLESS: u32 = 100_000;

/// One running `290` colour effect on a picture.
///
/// The official documentation insists an effect is processed "independently of what the
/// picture command specified", which is why this lives in a list beside the `150` fields
/// instead of mutating them: when the effect ends the picture has to fall back to its own
/// base tone, not to neutral. Keeping the base tone on Picture and only the phase here is
/// the same split, and it is also what makes the boot banner testable.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct PictureEffect {
    /// Effect type: the high nibble of the head word.
    pub kind: u8,
    /// Frames in one cycle, never zero because the ramp divides by it.
    pub duration: u32,
    /// Per-channel target offset in percent, straight from args 4..6.
    pub target: Tone,
    /// Frames elapsed, i.e. the phase inside the cycle.
    pub age: u32,
}

impl PictureEffect {
    /// Builds an effect at phase zero.
    #[must_use]
    pub fn new(kind: u8, duration: i32, target: Tone) -> Self {
        Self {
            kind,
            duration: duration.max(1) as u32,
            target,
            age: 0,
        }
    }

    /// Builds an effect from the interpreter raw `290` argument list.
    ///
    /// The list is head, duration, picture A, picture B, then the three channel targets, so
    /// the targets are simply args 4..6. The interpreter hands over the whole instruction,
    /// which is why this module never has to look at the opcode encoding itself.
    #[must_use]
    pub fn from_args(kind: u8, duration: i32, args: &[i32]) -> Self {
        let channel = |index: usize| args.get(index).copied().unwrap_or(0);
        Self::new(kind, duration, [channel(4), channel(5), channel(6)])
    }

    /// True when the effect asks for no colour change at all.
    #[must_use]
    pub fn is_neutral(&self) -> bool {
        self.target == [0, 0, 0]
    }

    /// True once a one-shot effect has run its course; type 5 never finishes.
    #[must_use]
    pub fn is_finished(&self) -> bool {
        self.kind != EFFECT_BLINK && self.age >= self.duration
    }

    /// The channel multiplier at the current phase, scaled by the cycle length.
    ///
    /// Returned as percent-times-duration so the caller divides exactly once and the whole
    /// chain stays in integers, which keeps the result reproducible frame for frame. The
    /// ramp is the one docs/OPCODE_290.md section 5.2 derives from the measurements: the
    /// colour changes with no wait, then walks linearly back to neutral over `duration`.
    #[must_use]
    pub fn percent_times_duration(&self, channel: usize) -> i64 {
        let from = i64::from(SCALE_ONE + self.target[channel]);
        let span = i64::from(self.duration);
        let phase = i64::from(self.age % self.duration);
        from * (span - phase) + i64::from(SCALE_ONE) * phase
    }
}
/// A `290` type 4 zoom: the picture grows about a fixed point of the logical screen.
///
/// docs/OPCODE_290.md section 5.4 records the field order the editor writes. args 4 and 5
/// are the centre in logical pixels and args 6 is the percentage, not a duration. All 49
/// zoom instructions in this game keep args 4 at 512 (half of 1024) and args 6 at 100 or
/// 105 - the "zoom in a little, later zoom back out" pair - which only makes sense as a
/// centre plus a scale. The action time ramps the percentage so the move does not pop.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Zoom {
    /// Point the picture scales about, in logical pixels.
    pub centre: (i32, i32),
    /// Percentage the ramp started from.
    pub from: i32,
    /// Percentage the ramp heads for, and stays at until another zoom replaces it.
    pub to: i32,
    /// Ramp length in frames; zero jumps straight to `to`.
    pub duration: u32,
    /// Frames elapsed in the ramp.
    pub elapsed: u32,
}

impl Zoom {
    /// Starts a ramp from the percentage already on screen.
    #[must_use]
    pub fn new(centre: (i32, i32), from: i32, to: i32, duration: i32) -> Self {
        Self {
            centre,
            from,
            to,
            duration: duration.max(0) as u32,
            elapsed: 0,
        }
    }

    /// The percentage to scale by on the current frame.
    #[must_use]
    pub fn percent(&self) -> i32 {
        if self.duration == 0 || self.elapsed >= self.duration {
            return self.to;
        }
        let step = f64::from(self.elapsed) / f64::from(self.duration);
        let value = f64::from(self.from) + f64::from(self.to - self.from) * step;
        value.round() as i32
    }

    /// Advances the ramp by one frame, stopping at its end.
    fn advance(&mut self) {
        if self.elapsed < self.duration {
            self.elapsed = self.elapsed.saturating_add(1);
        }
    }
}

/// A `290` type 3 shake: the picture is drawn at +offset for one period, then at -offset
/// for the next, for `count` periods.
///
/// docs/OPCODE_290.md section 5.3 derives the field order: args 4 and 5 are the X and Y
/// displacement in pixels, args 6 is the REPEAT count, and the action time is one period.
/// The waveform is the square wave that section recommends. Alternating signs are what make
/// a shake read as a shake instead of a drift, and a random waveform would need a seed the
/// instruction does not carry, so it cannot be what the engine does. The staircase in
/// common event 241 - (6,0,3) then (8,0,3) then (7,0,3) - is three separate instructions,
/// each bringing its own amplitude, which fits a stateless square wave exactly.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Shake {
    /// Displacement applied on the positive half of the wave, logical pixels.
    pub offset: (i32, i32),
    /// Frames in one half of the wave; the sign flips exactly here.
    pub period: u32,
    /// Number of repetitions; [`SHAKE_ENDLESS`] or more never stops.
    pub count: u32,
    /// Frames elapsed since the shake started.
    pub elapsed: u32,
}

impl Shake {
    /// Starts a shake at phase zero.
    #[must_use]
    pub fn new(offset: (i32, i32), count: i32, period: i32) -> Self {
        Self {
            offset,
            period: period.max(1) as u32,
            count: count.max(0) as u32,
            elapsed: 0,
        }
    }

    /// The displacement to add to the destination on the current frame.
    #[must_use]
    pub fn displacement(&self) -> (i32, i32) {
        if self.period == 0 || self.is_over() {
            return (0, 0);
        }
        // Integer division is the whole waveform: the sign flips at every period boundary.
        if (self.elapsed / self.period) % 2 == 0 {
            self.offset
        } else {
            (-self.offset.0, -self.offset.1)
        }
    }

    /// True once a finite shake has used up its repetitions.
    #[must_use]
    pub fn is_over(&self) -> bool {
        self.period == 0 || (self.count < SHAKE_ENDLESS && self.elapsed / self.period >= self.count)
    }

    /// Advances the shake by one frame.
    fn advance(&mut self) {
        self.elapsed = self.elapsed.saturating_add(1);
    }
}

/// A `290` type 7 automatic expansion: the picture grows by `amp` percent over one
/// excursion, snaps back, and rests for `rest` frames before repeating.
///
/// docs/OPCODE_290.md section 5.7 measures args 4 and 5 as the horizontal and vertical
/// amplitude in percent (equal in all 25 instructions of this game), args 6 as the rest
/// frames, and the action time as the length of one excursion. That section lists the
/// waveform as unconfirmed and recommends the single excursion used here. A triangle would
/// need the data to carry a full period, and the author's own rest frames only make sense
/// if the return to size is instant.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Breath {
    /// Amplitude in percent of the picture size, horizontal then vertical.
    pub amp: (i32, i32),
    /// Frames one excursion takes.
    pub period: u32,
    /// Frames the picture rests at its natural size before the next excursion.
    pub rest: u32,
    /// Frames elapsed since the effect started.
    pub elapsed: u32,
}

impl Breath {
    /// Starts an expansion cycle at rest.
    #[must_use]
    pub fn new(amp: (i32, i32), period: i32, rest: i32) -> Self {
        Self {
            amp,
            period: period.max(1) as u32,
            rest: rest.max(0) as u32,
            elapsed: 0,
        }
    }

    /// Growth in percent on the current frame: zero at rest, `amp` at the top.
    #[must_use]
    pub fn growth(&self) -> (i32, i32) {
        let cycle = self.period.saturating_add(self.rest);
        if cycle == 0 {
            return (0, 0);
        }
        let phase = self.elapsed % cycle;
        if phase >= self.period {
            return (0, 0);
        }
        let step = f64::from(phase) / f64::from(self.period);
        (
            (f64::from(self.amp.0) * step).round() as i32,
            (f64::from(self.amp.1) * step).round() as i32,
        )
    }

    /// Advances the expansion cycle by one frame.
    fn advance(&mut self) {
        self.elapsed = self.elapsed.saturating_add(1);
    }
}

/// A `290` types 8, 9 and 10 pattern animation: which animation pattern the picture shows.
///
/// docs/OPCODE_290.md section 5.8 measures the field order. args 4 and 5 are the first and
/// last pattern, the action time is the hold per pattern, and args 6 is unused - the
/// editor's own summary string for these types carries two placeholders, not three. The
/// three types differ only in what happens at the far end: 8 stops and hands the picture
/// back to the pattern its `150` command asked for, 9 wraps to the first pattern, and 10
/// turns around and walks back.
///
/// [`Picture::pattern_now`] is what the draw path reads: `picture_frame` treats the
/// returned value as a one-based cell of the picture's [`Picture::split`] grid, so the
/// state machine drives real animation frames instead of only bookkeeping.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct PatternFx {
    /// One of [`EFFECT_PATTERN_ONCE`], [`EFFECT_PATTERN_LOOP`], [`EFFECT_PATTERN_PINGPONG`].
    pub kind: u8,
    /// First pattern of the sequence.
    pub from: i32,
    /// Last pattern of the sequence.
    pub to: i32,
    /// Frames each pattern is held, never zero.
    pub interval: u32,
    /// The pattern shown right now.
    pub current: i32,
    /// +1 while walking towards `to`, -1 while walking back towards `from`.
    pub direction: i32,
    /// Frames the current pattern has been held.
    pub elapsed: u32,
    /// Pattern the `150` command asked for, restored when a one-shot finishes.
    pub base: i32,
    /// True once a one-shot has handed the picture back to `base`.
    pub done: bool,
}

impl PatternFx {
    /// Starts a sequence at its first pattern.
    #[must_use]
    pub fn new(kind: u8, from: i32, to: i32, interval: i32, base: i32) -> Self {
        Self {
            kind,
            from,
            to,
            interval: interval.max(1) as u32,
            current: from,
            direction: 1,
            elapsed: 0,
            base,
            done: false,
        }
    }

    /// True while the animation still owns the pattern field.
    #[must_use]
    pub fn is_running(&self) -> bool {
        !self.done
    }

    /// Advances the hold timer, stepping the pattern when it expires.
    fn advance(&mut self) {
        if self.done {
            return;
        }
        self.elapsed = self.elapsed.saturating_add(1);
        if self.elapsed < self.interval {
            return;
        }
        self.elapsed = 0;
        if self.from == self.to {
            // A one-pattern range has nothing to walk, but the editor emits it anyway.
            if self.kind == EFFECT_PATTERN_ONCE {
                self.current = self.base;
                self.done = true;
            }
            return;
        }
        // The sequence runs from `from` to `to` in whichever direction, so `order` is the
        // step in pattern space and `direction` says whether the animation walks forward.
        let order = if self.to > self.from { 1 } else { -1 };
        let mut next = self.current + self.direction * order;
        let past_far = if order > 0 {
            next > self.to
        } else {
            next < self.to
        };
        let past_near = if order > 0 {
            next < self.from
        } else {
            next > self.from
        };
        if past_far || past_near {
            match self.kind {
                EFFECT_PATTERN_ONCE => {
                    self.current = self.base;
                    self.done = true;
                    return;
                }
                EFFECT_PATTERN_LOOP => next = self.from,
                // Ping-pong turns around and steps back the way it came. That is the reading
                // the doc's "往復" name demands, and the only one that gives the direction
                // field something to mean.
                _ => {
                    self.direction = -self.direction;
                    next = self.current + self.direction * order;
                }
            }
        }
        self.current = next;
    }
}

/// The four picture fields a `150` slide moves, as the whole numbers the layer stores.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Pose {
    /// Left edge / centre x, logical pixels.
    pub x: i32,
    /// Top edge / centre y, logical pixels.
    pub y: i32,
    /// Uniform scale in percent.
    pub scale: i32,
    /// Opacity, 0..=255.
    pub opacity: i32,
}

impl Pose {
    /// The pose a picture holds right now.
    fn of(picture: &Picture) -> Self {
        Self {
            x: picture.x,
            y: picture.y,
            scale: picture.scale,
            opacity: picture.opacity,
        }
    }
}

/// An in-flight `150` move: where the picture started, where it is heading and how far it got.
///
/// Whole numbers on both ends keep `Picture: Eq` - the store is compared in tests and a
/// renderer may hash a frame - while the in-between frames are computed in `f64` and rounded,
/// so a three-frame slide still passes through whole pixels only.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Transition {
    /// The pose the picture left when the move arrived.
    pub from: Pose,
    /// The pose the move asks for; the picture fields get it back when the slide lands.
    pub to: Pose,
    /// Length of the slide in frames, 1..=[`MAX_TRANSITION_FRAMES`].
    pub duration: u32,
    /// Frames elapsed: 0 on the frame the move was applied.
    pub age: u32,
}

impl Transition {
    /// How far along the slide is, 0.0 at the origin and 1.0 on arrival.
    #[must_use]
    pub fn progress(&self) -> f32 {
        if self.age >= self.duration {
            1.0
        } else {
            self.age as f32 / self.duration as f32
        }
    }

    /// The slide a move asks for, or None when the instruction carries no usable frame count.
    ///
    /// `animate` is the instruction tail the interpreter copies out of `args[11..]`, so slot 0
    /// is the frame count. A missing tail, a literal 0 (168 moves), a self-variable reference
    /// (1,600,0xx, 52 moves) and anything past [`MAX_TRANSITION_FRAMES`] all mean "no
    /// duration": the move teleports, which is what the 2,817 duration-less moves already do.
    fn from_command(cmd: &PictureCmd, from: Pose, to: Pose) -> Option<Self> {
        let frames = u32::try_from(*cmd.animate.first()?).ok()?;
        if frames == 0 || frames > MAX_TRANSITION_FRAMES {
            return None;
        }
        Some(Self {
            from,
            to,
            duration: frames,
            age: 0,
        })
    }
}

/// One live picture slot.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Picture {
    /// Slot number; negative values are whole-screen layers.
    pub number: i32,
    /// What the picture draws.
    pub kind: PictureKind,
    /// Asset path, already escape-expanded. Empty for text kinds.
    pub file: String,
    /// Text content, already escape-expanded. Empty for image kinds.
    pub text: String,
    /// Left edge, logical pixels.
    pub x: i32,
    /// Top edge, logical pixels.
    pub y: i32,
    /// How many sprite-sheet cells the source image is split into, as (columns, rows).
    ///
    /// A `150` draw of a standing character names one PNG that holds a whole wardrobe:
    /// `Picture/stand_imouto_paja2.png` is 2400x1300 and every save record for it carries
    /// (6, 2), so the file is a 6 x 2 grid of 400x650 cells. (1, 1) means "draw the whole
    /// image", which is what every ordinary picture and every window uses.
    pub split: (u32, u32),
    /// One-based cell number inside [`Picture::split`]; 1 is the top-left cell.
    ///
    /// Retail save 92 proves the indexing: `stand_eye_a.png` is a 7 x 1 strip and its
    /// record says pattern 7, which only fits a one-based count. The default 1 keeps every
    /// ordinary picture on the whole image.
    pub pattern_index: u32,
    /// Uniform scale in percent.
    pub scale: i32,
    /// Opacity, 0..=255.
    pub opacity: i32,
    /// Blend mode, passed to the renderer unchanged.
    pub blend: i32,
    /// Window size for the window kinds.
    pub window: Option<(i32, i32)>,
    /// Anchor code from the head word bits 12..14: 0 top-left, 1 centre.
    pub anchor: u8,
    /// Kind-specific trailing arguments, kept verbatim for the animation layer.
    pub extras: Vec<i32>,
    /// Fade-in length in frames (0 = instant).
    pub fade: u32,
    /// Frames since the picture first appeared, for animation timing.
    pub age: u32,
    /// Base per-channel brightness in percent, from the 150 colour slots.
    pub tone: Tone,
    /// Running 290 colour effects, applied on top of tone.
    pub effects: Vec<PictureEffect>,
    /// Colour offset from a `290` type 1, in percent, ASSIGNED by each instruction.
    ///
    /// Kept apart from `effects` because the two do not share a clock: a correction is a
    /// persistent state that later instructions overwrite, while a flash ramps and expires.
    pub color_corr: Tone,
    /// Drawing-coordinate shift from a `290` type 2, in logical pixels.
    ///
    /// The type is named "final value": WOLF stores the offset the picture should end up
    /// with, so a later instruction replaces it instead of adding to it, and (0, 0) is how
    /// the game puts a picture back.
    pub shift: (i32, i32),
    /// Running `290` type 3 shake, if any.
    pub shake: Option<Shake>,
    /// Running `290` type 4 zoom, if any.
    pub zoom: Option<Zoom>,
    /// Running `290` type 7 automatic expansion, if any.
    pub breath: Option<Breath>,
    /// Running `290` types 8, 9 or 10 pattern animation, if any.
    pub pattern: Option<PatternFx>,
    /// True while a `150` hide command keeps the slot alive but unpainted.
    ///
    /// Common event 63 hides its message window between messages ("hide the window when the
    /// fade is not 1") and expects the next draw to bring it back, so the slot - and every
    /// field in it - has to survive being hidden.
    pub hidden: bool,
    /// The slide this picture is in the middle of, if any.
    ///
    /// x/y/scale/opacity hold the CURRENT frame of a slide, not its destination: a capture
    /// taken mid-slide, the renderer's `destination` and a later command that re-bases the
    /// picture all have to agree on where it is. The destination travels in `to` and only
    /// reaches the fields when the slide lands.
    pub transition: Option<Transition>,
    /// Raw save `md1` text stream and the text it decoded to, when this picture came
    /// from a save record. The loader keeps the original bytes so an unchanged picture
    /// is written back byte-for-byte - the canonical encoder cannot reproduce every
    /// retail escape spelling (e.g. the `01 02 20` control escape). `picture_to_record`
    /// only reuses them while `text` still equals the retained decoding; an event that
    /// rewrites the text falls back to the encoder.
    pub(crate) retained_text: Option<(String, Vec<u8>)>,
    /// The save record this picture was decoded from, kept so an untouched picture is
    /// written back with the numeric payload the retail record carried.
    ///
    /// `picture_to_record` rebuilds a record from the live fields, but the format stores
    /// far more than the renderer needs: `var2`/`var3`, `vals1`, `vars19_36`,
    /// `vars55_60`, `vars61_63`, the per-kind trailing tables and the second scale
    /// word. Those are script state, not picture geometry, so a canonical encoder
    /// cannot invent them. Keeping the decoded record lets `picture_to_record` hand
    /// back the original bytes while every field it *does* own still matches; as soon
    /// as an event repaints the picture it falls back to the canonical encoder (see
    /// `savegame::picture_to_record`).
    pub(crate) retained_record: Option<wolf_save::part5::SavePart5_1>,
}

impl Picture {
    /// A picture at the WOLF defaults: origin at the top-left, 100% scale, opaque.
    #[must_use]
    pub fn new(number: i32) -> Self {
        Self {
            number,
            kind: PictureKind::File,
            file: String::new(),
            text: String::new(),
            x: 0,
            y: 0,
            split: (1, 1),
            pattern_index: 1,
            scale: SCALE_ONE,
            opacity: 255,
            blend: 0,
            window: None,
            anchor: ANCHOR_TOP_LEFT,
            extras: Vec::new(),
            fade: 0,
            age: 0,
            tone: TONE_NEUTRAL,
            effects: Vec::new(),
            color_corr: [0, 0, 0],
            shift: (0, 0),
            shake: None,
            zoom: None,
            breath: None,
            pattern: None,
            hidden: false,
            transition: None,
            retained_text: None,
            retained_record: None,
        }
    }

    /// Which skin a window picture is drawn with.
    ///
    /// A `150` window command may name its own skin - common event 63 passes
    /// SystemFile/WindowBase.png, the grey panel - and the engine default is the same
    /// grey SystemFile/WindowBase.png used by the choice window. SystemGraphic/
    /// WindowBase.png is an unused navy sample asset, not the default. Anything that is
    /// not a plausible asset path (an empty name, or a `<SQUARE>`-style built-in drawing)
    /// falls back to the default.
    #[must_use]
    pub fn window_skin(&self) -> &str {
        let names_an_asset = !self.file.is_empty()
            && !self.file.starts_with('<')
            && crate::sysgraphic::parse(&self.file).is_none();
        if names_an_asset {
            self.file.as_str()
        } else {
            crate::window::SKIN
        }
    }

    /// True for the whole-screen layers (picture numbers below zero).
    #[must_use]
    pub fn is_screen_layer(&self) -> bool {
        self.number < 0
    }

    /// True while a `150` move is still sliding this picture.
    #[must_use]
    pub fn is_moving(&self) -> bool {
        self.transition.is_some()
    }

    /// Steps an in-flight move by exactly one frame, landing on its target at the end.
    ///
    /// A slide writes the current frame back into the fields every step so the whole store
    /// stays consistent - `destination`, `quads`, `alpha` and any opcode that reads a picture
    /// field all see the same numbers, with no second copy of the state to keep in sync. The
    /// arrival frame assigns the stored target rather than a rounded interpolation, so a slide
    /// cannot leave the picture a pixel short of where the script put it.
    pub fn advance(&mut self) {
        let Some(mut transition) = self.transition else {
            return;
        };
        transition.age = transition.age.saturating_add(1);
        if transition.age >= transition.duration {
            self.x = transition.to.x;
            self.y = transition.to.y;
            self.scale = transition.to.scale;
            self.opacity = transition.to.opacity;
            self.transition = None;
            return;
        }
        self.x = blend(
            transition.from.x,
            transition.to.x,
            transition.age,
            transition.duration,
        );
        self.y = blend(
            transition.from.y,
            transition.to.y,
            transition.age,
            transition.duration,
        );
        self.scale = blend(
            transition.from.scale,
            transition.to.scale,
            transition.age,
            transition.duration,
        );
        self.opacity = blend(
            transition.from.opacity,
            transition.to.opacity,
            transition.age,
            transition.duration,
        );
        self.transition = Some(transition);
    }

    /// Opacity as 0.0..=1.0, clamped the way the renderer wants it.
    ///
    /// A picture with a fade-in ramp is multiplied by its progress through that ramp, which
    /// is how the boot chain's splashes appear: the retail disclaimer frame is 63/255 of the
    /// source art at age 5 of a 20-frame fade, and 5/20 * 255 = 63.75.
    #[must_use]
    pub fn alpha(&self) -> f32 {
        let opacity = (self.opacity.clamp(0, 255) as f32) / 255.0;
        if self.fade == 0 {
            return opacity;
        }
        let progress = (self.age as f32 / self.fade as f32).min(1.0);
        opacity * progress
    }
    /// The per-channel draw brightness this picture currently asks for, 0..=255.
    ///
    /// Three layers, in this order: the base tone from the 150 colour slots, the type 1
    /// colour correction added to it and clamped to 0..200, then every live colour effect
    /// adjusting the result. Flash effects multiply the result (docs/OPCODE_290.md section
    /// 5.2 pins that order); a type 5 blink instead adds its target to the base and walks
    /// back to the base, because CE94's save cursor is black at rest and must pulse up. DxLib
    /// expresses the result as SetDrawBright, which scales the colour channels of whatever
    /// is drawn and never the alpha, so alpha() stays independent of this and the banner
    /// still blends at its own opacity.
    #[must_use]
    pub fn tone_byte(&self) -> [u8; 3] {
        let mut out = [0u8; 3];
        for (channel, slot) in out.iter_mut().enumerate() {
            // The correction is an offset on the base tone, and the clamp to 0..200 has to
            // happen BEFORE the percentage is turned into a byte: 100 is neutral and the
            // official documentation clamps the final colour to that same range. With a zero
            // correction this is bit for bit the expression the retail banner pinned.
            let base = (self.tone[channel] + self.color_corr[channel]).clamp(0, 200);
            let mut value = i64::from(percent_to_byte(base));
            for effect in &self.effects {
                let numerator = effect.percent_times_duration(channel);
                let denominator = i64::from(SCALE_ONE) * i64::from(effect.duration);
                if effect.kind == EFFECT_BLINK {
                    // A blink ramps the base tone itself, it does not scale it. CE94's
                    // save-slot cursor proves it: the four cursor windows are drawn at
                    // tone 0 (black) and only the selected one gets `290 type 5` with
                    // target +100, i.e. it must pulse 100% -> 0% over its 15 frames.
                    // Multiplying the black base by any percentage can only produce
                    // black, which left the grid with no visible cursor; adding the
                    // target to the base and walking back to the base gives the pulse.
                    // The title banner (base 100, target -50) is unchanged: it still
                    // ramps 50% -> 100%.
                    let span = i64::from(effect.duration);
                    let rest = i64::from(effect.age % effect.duration);
                    let percent =
                        i64::from(base) * span + i64::from(effect.target[channel]) * (span - rest);
                    value = (255 * percent + 50 * span) / (100 * span);
                    continue;
                }
                value = (value * numerator + denominator / 2) / denominator;
            }
            *slot = value.clamp(0, 255) as u8;
        }
        out
    }

    /// Starts a colour effect, replacing whatever colour effect was already running.
    ///
    /// WOLF keeps one colour state per picture rather than a stack, so a second flash takes
    /// over from the first instead of multiplying with it.
    fn start_effect(&mut self, effect: PictureEffect) {
        self.stop_effects();
        self.effects.push(effect);
    }

    /// Cancels the colour effects, leaving the 150 base tone in charge again.
    fn stop_effects(&mut self) {
        self.effects
            .retain(|effect| !matches!(effect.kind, EFFECT_FLASH | EFFECT_BLINK));
    }
}

/// Converts a percentage tone into the 0..=255 byte the draw call wants.
///
/// Rounds half up and clamps: a tone above 100 percent asks for more than a channel can
/// hold, and DxLib saturates there rather than scaling the whole picture down.
fn percent_to_byte(percent: i32) -> i32 {
    let scaled = i64::from(percent.clamp(0, 200)) * 255;
    ((scaled + 50) / 100).clamp(0, 255) as i32
}
/// A draw request for one picture, already flattened into logical-pixel coordinates.
///
/// The renderer only has to place a textured quad; every WOLF-specific rule (sentinel
/// merging, whole-screen layers, percent scaling) has been applied by Screen::quads.
#[derive(Clone, Debug, PartialEq)]
pub struct ScreenQuad {
    /// Picture slot this came from (useful for tracing).
    pub number: i32,
    /// What it draws.
    pub kind: PictureKind,
    /// Asset path for image kinds.
    pub file: String,
    /// Text for text kinds.
    pub text: String,
    /// Source rectangle inside the texture: [x, y, w, h].
    pub src: [u32; 4],
    /// Destination rectangle in logical pixels: [x, y, w, h].
    pub dst: [f32; 4],
    /// Opacity 0.0..=1.0.
    pub alpha: f32,
    /// Per-channel draw brightness, 0..=255, alpha excluded.
    pub tone: [u8; 3],
    /// Blend mode, verbatim.
    pub blend: i32,
}

/// The set of live pictures, keyed by number.
///
/// A BTreeMap is the right container twice over: WOLF composites pictures in ascending
/// number order (so iteration order *is* the draw order, with no sort per frame), and
/// lookups by number are the only access pattern the interpreter has.
#[derive(Clone, Debug, Default)]
pub struct Screen {
    pictures: BTreeMap<i32, Picture>,
}

impl Screen {
    /// An empty screen.
    #[must_use]
    pub fn new() -> Self {
        Self::default()
    }

    /// Number of live pictures.
    #[must_use]
    pub fn len(&self) -> usize {
        self.pictures.len()
    }

    /// True when nothing is drawn.
    #[must_use]
    pub fn is_empty(&self) -> bool {
        self.pictures.is_empty()
    }

    /// Looks up one picture by slot number.
    #[must_use]
    pub fn get(&self, number: i32) -> Option<&Picture> {
        self.pictures.get(&number)
    }

    /// Iterates live pictures in draw order (ascending number).
    pub fn iter(&self) -> impl Iterator<Item = &Picture> {
        self.pictures.values()
    }

    /// The coordinate scale for one UI block, 1.0 or 10.0.
    ///
    /// Most of the game draws in pixels. The settings screen (CE95) instead builds its
    /// whole panel from tenth-of-a-character-cell units: it sizes the window as
    /// 180x195 cells, draws every row at one base coordinate and separates rows with
    /// `290` shifts in the same unit, and only its `/10` on the left edge brings the
    /// base back to pixels. A block is recognised by a window box more than twice the
    /// logical screen; built-in system graphics are exempt because the full-screen
    /// gradient belongs to the same block but is a real 1024x576 drawing.
    #[must_use]
    pub(crate) fn ui_scale_for(&self, number: i32) -> f32 {
        let Some(picture) = self.pictures.get(&number) else {
            return 1.0;
        };
        if !(picture.kind.is_text() || picture.kind.is_window())
            || crate::sysgraphic::parse(&picture.file).is_some()
        {
            return 1.0;
        }
        let block = number.div_euclid(1000);
        let oversized = self.pictures.values().any(|other| {
            // A widget the engine parks far off screen keeps an oversized window box
            // (the message window parks at y = 3840 between lines), but it is not a
            // tenths UI block: dividing its parked position by ten drags it back on
            // screen as a stray dark panel. Only an on-screen anchor marks a tenths
            // block, so skip anything parked outside the extended logical screen.
            let parked = other.x.abs() > SCREEN_W as i32 * 2 || other.y.abs() > SCREEN_H as i32 * 2;
            other.number.div_euclid(1000) == block
                && !parked
                && other.kind.is_window()
                && crate::sysgraphic::parse(&other.file).is_none()
                && other
                    .window
                    .map(|(w, h)| w > SCREEN_W as i32 * 2 || h > SCREEN_H as i32 * 2)
                    .unwrap_or(false)
        });
        if oversized {
            10.0
        } else {
            1.0
        }
    }

    /// Inserts a fully built picture, replacing any slot with the same number.
    ///
    /// Loading a save rebuilds every picture from the save's Part5 records, and those
    /// records carry fields (anchor, window box, scale, fade) that no single `150`
    /// command would reproduce on its own.
    pub fn insert(&mut self, picture: Picture) {
        self.pictures.insert(picture.number, picture);
    }

    /// Drops every picture. Used when returning to the title or loading a save.
    pub fn clear(&mut self) {
        self.pictures.clear();
    }

    /// Drops only the whole-screen (negative numbered) layers, keeping ordinary
    /// numbered pictures. Map changes rebuild the screen layers from the new map's
    /// event scripts, and the old map's overlays must not bleed through.
    pub fn clear_screen_layers(&mut self) {
        self.pictures.retain(|number, _| *number >= 0);
    }

    /// Advances the animation clock by one frame.
    pub fn tick(&mut self) {
        for picture in self.pictures.values_mut() {
            picture.age = picture.age.saturating_add(1);
            for effect in &mut picture.effects {
                effect.age = effect.age.saturating_add(1);
            }
            // One-shot effects narrate themselves out of existence; type 5 repeats.
            picture.effects.retain(|effect| !effect.is_finished());
            // The positional effects run on the same frame clock as the fade ramp, so a host
            // that ticks once per frame gets the rate the data asked for.
            picture.tick_fx();
        }
    }

    /// Steps every in-flight `150` move by exactly one frame and drops the ones that arrive.
    ///
    /// Deliberately separate from [`Screen::tick`]: the fade-in ramp and the colour effects are
    /// clocked by `tick`, the slides by this, and a host calls both once per frame. Keeping the
    /// two clocks apart means a test can age a slide without touching the fade ramp, and a
    /// capture taken between them shows the frame the script actually asked for.
    pub fn advance(&mut self) {
        for picture in self.pictures.values_mut() {
            picture.advance();
        }
    }

    /// Applies one `150` picture command.
    ///
    /// The four actions are not symmetric: Draw and Set build a fresh slot (so UNCHANGED
    /// fields take their defaults), while Move patches an existing one and keeps every
    /// field the command leaves at UNCHANGED. Erase removes the slot.
    ///
    /// Tolerance, matching the interpreter's house rules: a Move for a slot that does not
    /// exist creates it rather than being dropped, because losing the mutation would make
    /// every later move target nothing and the picture would never appear.
    pub fn apply(&mut self, cmd: &PictureCmd) {
        match cmd.action {
            PictureAction::Erase => {
                // The long erase form clears a RANGE of slots. Common event 221 parks the
                // whole loading screen with `150 [16777218, 50000, 5, 5, 0, 50003]`: one
                // command removes the black backdrop (50000), the eyecatch (50001), the
                // NOW LOADING text (50002) and the progress bar (50003). Treating it as a
                // single-slot erase is what left the eyecatch and the loading text on
                // screen forever, because no other instruction in the game names them.
                //
                // The two endpoints are not ordered - Map003.mps:ev1 pc24 passes -1 then
                // -2 - so the range is between them, not below and above the first.
                match cmd.args.get(ERASE_SPAN) {
                    Some(other) => {
                        let (lo, hi) = (cmd.number.min(*other), cmd.number.max(*other));
                        self.pictures
                            .retain(|number, _| *number < lo || *number > hi);
                    }
                    None => {
                        self.pictures.remove(&cmd.number);
                    }
                }
            }
            PictureAction::Hide => {
                // Hide is not erase and not a redraw: the slot keeps its skin name, box and
                // position so the next draw restores exactly the same window.
                if let Some(picture) = self.pictures.get_mut(&cmd.number) {
                    picture.hidden = true;
                }
            }
            PictureAction::Draw | PictureAction::Set => {
                // A draw replaces the slot, which is also how a hidden window comes back:
                // Picture::new starts visible and nothing else in the data unhides.
                //
                // Bit 0x400000 asks the redraw to keep the slot's current draw-coordinate
                // shift. Common event 95 uses it for the settings help text: a 290 leaves
                // (2880, 5040) on the slot, then the final draw carries x=y=0 and relies on
                // that shift to land inside the help box. Resetting it would park the text
                // at the screen origin.
                let inherited_shift = if cmd.keep_shift {
                    self.pictures.get(&cmd.number).map(|picture| picture.shift)
                } else {
                    None
                };
                // A relative draw offsets x/y from where the slot already sits. Common
                // event 238 hides the status panel at x=-305 and then re-draws it with
                // head 0x10000 and x=305, meaning "move 305 to the right of where it is",
                // which is x=0 on screen rather than x=305.
                let (base_x, base_y) = if cmd.relative {
                    self.pictures
                        .get(&cmd.number)
                        .map_or((0, 0), |picture| (picture.x, picture.y))
                } else {
                    (0, 0)
                };
                let mut picture = Picture::new(cmd.number);
                picture.kind = PictureKind::from_code(cmd.kind);
                picture.file = cmd.file.clone();
                picture.text = cmd.text.clone();
                picture.anchor = cmd.anchor;
                let args = picture_args(cmd, base_x, base_y);
                merge_args(&mut picture, &args);
                if let Some(shift) = inherited_shift {
                    picture.shift = shift;
                }
                self.pictures.insert(cmd.number, picture);
            }
            PictureAction::Move => {
                let picture = self.pictures.entry(cmd.number).or_insert_with(|| {
                    let mut fresh = Picture::new(cmd.number);
                    fresh.kind = PictureKind::from_code(cmd.kind);
                    fresh
                });
                // A Move that carries a file name is how the script swaps the image in place.
                if !cmd.file.is_empty() {
                    picture.file.clone_from(&cmd.file);
                }
                if !cmd.text.is_empty() {
                    picture.text.clone_from(&cmd.text);
                }
                // An anchor of 0 on a Move means UNCHANGED, not top-left. Common event 63
                // proves it: it draws its message window centred at (512, 672) - parked
                // below the screen - then slides it to (512, 480) and back, and the retail
                // frame is visible, which only works if the moves keep the centre anchor.
                // Reads taken literally put the 960x168 window at x = 512..1472. The 56
                // moves that really do re-anchor carry the 0x1000 flag explicitly.
                if cmd.anchor != ANCHOR_TOP_LEFT {
                    picture.anchor = cmd.anchor;
                }
                // A slide starts from where the picture is DRAWN right now - its own fields, not
                // the destination a previous move has not reached yet, and certainly not the
                // -1000000 sentinels: those mean "leave this field alone", and the origin of an
                // unchanged field is its current value, which interpolates to itself.
                let origin = Pose::of(picture);
                let args = picture_args(cmd, origin.x, origin.y);
                merge_args(picture, &args);
                // With a usable duration the merged fields are only the TARGET: rewind them to
                // where the picture already is and let `advance` walk there. Without one the
                // merged fields are final, i.e. the teleport every duration-less move expects.
                match Transition::from_command(cmd, origin, Pose::of(picture)) {
                    Some(transition) => {
                        picture.x = transition.from.x;
                        picture.y = transition.from.y;
                        picture.scale = transition.from.scale;
                        picture.opacity = transition.from.opacity;
                        picture.transition = Some(transition);
                    }
                    None => picture.transition = None,
                }
            }
        }
    }

    /// Applies one 290 effect command, returning false when the type or the range is unusable.
    ///
    /// True when `kind` names a 290 effect this store knows how to apply.
    ///
    /// Every kind the shipped data uses is handled by the match below; a false return
    /// therefore means either an out-of-range/unsupported kind (never present in this
    /// game) or that the instruction's target picture range holds no live picture yet.
    /// The interpreter uses this to tell a real missing feature apart from a genuine
    /// engine no-op instead of lumping both under one "not drawn" note.
    #[must_use]
    pub fn effect_kind_supported(kind: i32) -> bool {
        matches!(u8::try_from(kind), Ok(k) if Self::effect_kind_supported_u8(k))
    }

    fn effect_kind_supported_u8(kind: u8) -> bool {
        matches!(
            kind,
            EFFECT_FLASH
                | EFFECT_COLOR_CORRECT
                | EFFECT_SHIFT
                | EFFECT_SHAKE
                | EFFECT_ZOOM
                | EFFECT_BLINK
                | EFFECT_BREATH
                | EFFECT_PATTERN_ONCE
                | EFFECT_PATTERN_LOOP
                | EFFECT_PATTERN_PINGPONG
        )
    }

    /// args is the interpreter raw argument list: args 0 is the head word (its high nibble is
    /// already decoded into `kind` by the caller), args 1 the action time, args 2 and 3 the
    /// ends of ONE CLOSED picture range, and args 4..6 three values whose meaning depends on
    /// the type. docs/OPCODE_290.md section 2 lists all eleven types the editor offers; ten
    /// of them occur in this game and all ten are handled here, which is the whole reason the
    /// picture store - not the interpreter - owns the effect state.
    ///
    /// Type 6 (the second blink variant) stays unhandled on purpose: this game contains zero
    /// of them, and guessing at a waveform nobody runs is worse than reporting it.
    pub fn effect(&mut self, kind: i32, duration: i32, args: &[i32]) -> bool {
        let Ok(kind) = u8::try_from(kind) else {
            return false;
        };
        if !Self::effect_kind_supported_u8(kind) {
            return false;
        }
        let Some((lo, hi)) = effect_range(args) else {
            return false;
        };
        let targets: Vec<i32> = self
            .pictures
            .range(lo..=hi)
            .map(|(number, _)| *number)
            .collect();
        if targets.is_empty() {
            return false;
        }
        let value = |index: usize| args.get(index).copied().unwrap_or(0);
        let (v1, v2, v3) = (value(4), value(5), value(6));
        let flash = PictureEffect::from_args(kind, duration, args);
        for number in targets {
            let Some(picture) = self.pictures.get_mut(&number) else {
                continue;
            };
            match kind {
                EFFECT_FLASH | EFFECT_BLINK => {
                    // Every stopping spelling in the data means the same thing: back to the
                    // base tone the picture command set. A zero action time and an all-zero
                    // target are the two ways WOLF writes that for these types.
                    if duration <= 0 || flash.is_neutral() {
                        picture.stop_effects();
                    } else {
                        picture.start_effect(flash);
                    }
                }
                // Assignment, not accumulation: see EFFECT_COLOR_CORRECT for the menu-row
                // highlight that only works this way.
                EFFECT_COLOR_CORRECT => {
                    picture.color_corr = [v1, v2, v3].map(|c| c.clamp(-200, 200))
                }
                EFFECT_SHIFT => picture.shift = (v1, v2),
                EFFECT_SHAKE => {
                    // A zero amplitude is how the author stops a shake, and the repetition
                    // count is the third value, not a duration.
                    picture.shake = if v1 == 0 && v2 == 0 {
                        None
                    } else {
                        Some(Shake::new((v1, v2), v3, duration))
                    };
                }
                EFFECT_ZOOM => {
                    // args 6 is the percentage (all 49 instructions in this game send 100 or
                    // 105), so 0 is a malformed request rather than a request for an
                    // invisible picture; 100 - the neutral zoom - is the only sane reading.
                    let target = if v3 <= 0 { SCALE_ONE } else { v3 };
                    let from = picture.zoom.map_or(SCALE_ONE, |zoom| zoom.percent());
                    picture.zoom = Some(Zoom::new((v1, v2), from, target, duration));
                }
                EFFECT_BREATH => {
                    picture.breath = if v1 == 0 && v2 == 0 {
                        None
                    } else {
                        Some(Breath::new((v1, v2), duration, v3))
                    };
                }
                _ => {
                    // 8, 9 and 10: the third value is not part of the instruction at all
                    // (docs/OPCODE_290.md section 5.8), and the action time is the hold.
                    let base = picture
                        .pattern
                        .map_or(picture.pattern_index as i32, |fx| fx.base);
                    picture.pattern = Some(PatternFx::new(kind, v1, v2, duration, base));
                }
            }
        }
        true
    }
    /// Flattens the live pictures into draw requests, in draw order.
    ///
    /// tex_size resolves an asset path to its pixel size. A `<...>` built-in system
    /// graphic has no file and takes its size from the picture's own window fields instead
    /// (see `picture_size`); everything else that resolves to nothing skips the picture,
    /// because a quad of unknown size cannot be placed and inventing one would draw
    /// garbage. Text pictures are emitted with an empty source rectangle so the text layer
    /// can pick them up in the same pass.
    #[must_use]
    pub fn quads<F>(&self, mut tex_size: F) -> Vec<ScreenQuad>
    where
        F: FnMut(&str) -> Option<(u32, u32)>,
    {
        let mut out = Vec::with_capacity(self.pictures.len());
        for picture in self.pictures.values() {
            if picture.hidden || picture.opacity <= 0 {
                continue;
            }
            // Window kinds are painted by the atlas as a nine-slice panel (from
            // Picture::window_skin) rather than as a sprite; letting them through here would
            // draw the 18x18 skin at its natural size instead of the window box. The
            // built-in system-graphic spelling is the exception: those are real drawings
            // sized by the picture itself, and Atlas::sprites skips them as panels.
            if picture.kind.is_window()
                && picture.window.is_some()
                && crate::sysgraphic::parse(&picture.file).is_none()
            {
                continue;
            }
            let (src, dst) = if picture.kind.is_text() {
                // Text boxes carry their own metrics and have never been scaled by the 150
                // percent slot, so they keep the plain placement law and only gain the
                // positional effects - a message window has to shake with its picture.
                let (w, h) = picture.window.unwrap_or((0, 0));
                let placed = place(
                    picture.anchor,
                    picture.x,
                    picture.y,
                    w.max(0) as f32,
                    h.max(0) as f32,
                );
                let mut dst = picture.transform(placed);
                let ui = self.ui_scale_for(picture.number);
                if ui > 1.0 {
                    dst = [dst[0], dst[1] / ui, dst[2] / ui, dst[3] / ui];
                }
                ([0, 0, 0, 0], dst)
            } else {
                let Some((src, (w, h))) = picture_frame(picture, &mut tex_size) else {
                    continue;
                };
                let mut dst = picture.destination(w as f32, h as f32);
                let ui = self.ui_scale_for(picture.number);
                if ui > 1.0 {
                    dst = [dst[0], dst[1] / ui, dst[2] / ui, dst[3] / ui];
                }
                (src, dst)
            };
            if !on_screen(dst) {
                continue;
            }
            out.push(ScreenQuad::from(picture, src, dst));
        }
        out
    }
}

/// True when a destination rectangle overlaps the logical screen at all.
///
/// Pictures are routinely parked far outside it: the third-party balloon-message library
/// that event 98 sets up keeps its 24 controls at (-2784, 2880) until a bubble opens, and a
/// quad that cannot touch the screen contributes no pixels. Dropping it here keeps the draw
/// list honest instead of relying on every downstream stage to clip it.
#[must_use]
pub fn on_screen(dst: [f32; 4]) -> bool {
    dst[2] > 0.0
        && dst[3] > 0.0
        && dst[0] + dst[2] > 0.0
        && dst[1] + dst[3] > 0.0
        && dst[0] < SCREEN_W as f32
        && dst[1] < SCREEN_H as f32
}

impl Picture {
    /// Where this picture lands when it draws w*h pixels, anchor, scale and effects applied.
    ///
    /// The message-window metrics need the frame rectangle without the texture lookup
    /// that `Screen::quads` does, so the placement law lives here once and both callers
    /// share it. Both draw paths reach the effects through this method, so a shaken panel
    /// and a shaken sprite cannot drift apart.
    #[must_use]
    pub fn destination(&self, w: f32, h: f32) -> [f32; 4] {
        let scale = self.scale.max(0) as f32 / SCALE_ONE as f32;
        let (sx, sy) = self.effect_scale();
        let placed = place(self.anchor, self.x, self.y, w * scale * sx, h * scale * sy);
        self.transform(placed)
    }

    /// The animation pattern the picture shows right now, if a type 8/9/10 owns it.
    #[must_use]
    pub fn pattern_now(&self) -> Option<i32> {
        self.pattern.map(|fx| fx.current)
    }

    /// The width and height scale the running effects ask for, on top of the 150 scale.
    ///
    /// Only the type 7 expansion changes the size, and it changes it about the picture's
    /// own anchor: `place` puts the anchor at x/y, so scaling the extent while keeping the
    /// anchor fixed is exactly "grow around the anchored point". A centred picture therefore
    /// grows in all four directions and a corner-anchored one grows to the right and down,
    /// which is what the authors see in the editor.
    fn effect_scale(&self) -> (f32, f32) {
        let Some(breath) = &self.breath else {
            return (1.0, 1.0);
        };
        let (gx, gy) = breath.growth();
        (
            1.0 + gx as f32 / SCALE_ONE as f32,
            1.0 + gy as f32 / SCALE_ONE as f32,
        )
    }

    /// The logical-pixel displacement the running effects ask for.
    pub(crate) fn effect_offset(&self) -> (f32, f32) {
        let mut x = self.shift.0 as f32;
        let mut y = self.shift.1 as f32;
        if let Some(shake) = &self.shake {
            let (dx, dy) = shake.displacement();
            x += dx as f32;
            y += dy as f32;
        }
        (x, y)
    }

    /// Applies the effects that move an already placed rectangle: zoom, then shift and shake.
    ///
    /// The order matters and is the one docs/OPCODE_290.md section 5.4 implies: zoom is
    /// defined about a point of the SCREEN, so it has to work on the placed rectangle, while
    /// shift and shake are pixel displacements that must not be scaled by it. A neutral
    /// picture takes neither branch and keeps the exact floats it had before effects
    /// existed, which is what keeps the title frame byte-identical.
    fn transform(&self, dst: [f32; 4]) -> [f32; 4] {
        let mut out = dst;
        if let Some(zoom) = &self.zoom {
            let k = zoom.percent().max(0) as f32 / SCALE_ONE as f32;
            if (k - 1.0).abs() > f32::EPSILON {
                let (cx, cy) = (zoom.centre.0 as f32, zoom.centre.1 as f32);
                out = [
                    cx + (out[0] - cx) * k,
                    cy + (out[1] - cy) * k,
                    out[2] * k,
                    out[3] * k,
                ];
            }
        }
        let (ox, oy) = self.effect_offset();
        if ox != 0.0 || oy != 0.0 {
            out[0] += ox;
            out[1] += oy;
        }
        out
    }

    /// Advances the effect clocks that are not colour ramps.
    ///
    /// Called from `Screen::tick` with the same one-frame step as the fade ramp, so a host
    /// that calls tick once per frame gets the animation rate the data asked for. The colour
    /// effects keep their own clock in `PictureEffect::age`; these four carry theirs because
    /// they are not ramps towards a target.
    fn tick_fx(&mut self) {
        if let Some(zoom) = &mut self.zoom {
            zoom.advance();
        }
        if let Some(breath) = &mut self.breath {
            breath.advance();
        }
        if let Some(pattern) = &mut self.pattern {
            pattern.advance();
        }
        if let Some(shake) = &mut self.shake {
            shake.advance();
            if shake.is_over() {
                self.shake = None;
            }
        }
    }
}

impl ScreenQuad {
    /// Builds a quad from a picture plus its finished source/destination rectangles.
    fn from(picture: &Picture, src: [u32; 4], dst: [f32; 4]) -> Self {
        Self {
            number: picture.number,
            kind: picture.kind,
            file: picture.file.clone(),
            text: picture.text.clone(),
            src,
            dst,
            alpha: picture.alpha(),
            tone: picture.tone_byte(),
            blend: picture.blend,
        }
    }
}

/// Turns an anchor code plus a w*h extent into the destination rectangle.
///
/// ANCHOR_CENTRE shifts by half the extent on both axes, which is what the retail title
/// banner needs; every other code keeps the corner behaviour and is unverified.
fn place(anchor: u8, x: i32, y: i32, w: f32, h: f32) -> [f32; 4] {
    let mut left = x as f32;
    let mut top = y as f32;
    if anchor == ANCHOR_CENTRE {
        left -= w / 2.0;
        top -= h / 2.0;
    }
    [left, top, w, h]
}

/// Resolves the pixel size of whatever one picture draws.
///
/// A real file always wins: its own size is what the artist made and what the blit uses.
/// A `<...>` built-in command has no file at all, so its size is the box the `150`
/// instruction wrote into the window fields - see `sysgraphic::box_size`, which also
/// explains why the `-a-b` suffix of a `<GRAD*-a-b>` name is not a size. Both the
/// whole-screen layers and the ordinary pictures resolve through here, so a built-in shape
/// is placed, scaled and clipped by exactly the same rules as an image.
fn picture_frame<F>(picture: &Picture, tex_size: &mut F) -> Option<([u32; 4], (u32, u32))>
where
    F: FnMut(&str) -> Option<(u32, u32)>,
{
    if let Some((full_w, full_h)) = tex_size(&picture.file) {
        let (columns, rows) = (picture.split.0.max(1), picture.split.1.max(1));
        if columns == 1 && rows == 1 {
            return Some(([0, 0, full_w, full_h], (full_w, full_h)));
        }
        let (cell_w, cell_h) = (full_w / columns, full_h / rows);
        if cell_w == 0 || cell_h == 0 {
            return Some(([0, 0, full_w, full_h], (full_w, full_h)));
        }
        let pattern = picture
            .pattern_now()
            .unwrap_or(picture.pattern_index as i32)
            .max(1);
        let index = (pattern - 1) as u32;
        let column = index % columns;
        let row = index / columns;
        if row >= rows {
            return Some(([0, 0, cell_w, cell_h], (cell_w, cell_h)));
        }
        return Some((
            [column * cell_w, row * cell_h, cell_w, cell_h],
            (cell_w, cell_h),
        ));
    }
    let shape = crate::sysgraphic::parse(&picture.file)?;
    let (w, h) = crate::sysgraphic::box_size(shape, picture.window)?;
    Some(([0, 0, w, h], (w, h)))
}

/// One frame of a linear slide between two whole numbers, rounded half away from zero.
///
/// Both endpoints are whole numbers because that is what the layer stores; interpolating in
/// `f64` keeps a 20-frame ramp from accumulating the error `f32` would leave behind. The
/// arrival frame never comes through here - `Picture::advance` assigns the stored target.
fn blend(from: i32, to: i32, age: u32, duration: u32) -> i32 {
    let step = f64::from(age) / f64::from(duration);
    let value = f64::from(from) + (f64::from(to) - f64::from(from)) * step;
    value.round() as i32
}

/// Reads the picture range out of a `290` argument list, normalising a reversed one.
///
/// docs/OPCODE_290.md section 1.2 shows args 2 and 3 are the two ends of ONE CLOSED range,
/// not two independent pictures: the flashing-cursor instruction in common event 85 names
/// [1600021, 1600026] and expects six pictures to blink, and a type 5 dimmer names
/// [390, 500] for 72 pictures. Exactly one instruction in this game writes its ends in
/// descending order (common event 94, slot 616); the engine cannot have drawn that as "no
/// pictures at all", so it is a typing mistake in the data and the ends are swapped.
fn effect_range(args: &[i32]) -> Option<(i32, i32)> {
    let lo = args.get(2).copied()?;
    let hi = args.get(3).copied()?;
    Some(if lo <= hi { (lo, hi) } else { (hi, lo) })
}

/// Returns the command field words with x/y made absolute when the head word's
/// 0x10000 bit marks them relative to base_x/base_y.
///
/// The flag applies to both draws and moves (common events 238/239 use it on both): the
/// word is an offset from the slot current position, so 0 means stay on this axis.
/// UNCHANGED still wins, because the relative form never uses that sentinel as an offset.
fn picture_args(cmd: &PictureCmd, base_x: i32, base_y: i32) -> Vec<i32> {
    let mut args = cmd.args.clone();
    if cmd.relative {
        if let Some(dx) = take(&args, field::X) {
            args[field::X] = base_x.saturating_add(dx);
        }
        if let Some(dy) = take(&args, field::Y) {
            args[field::Y] = base_y.saturating_add(dy);
        }
    }
    args
}

/// Merges a command's field words into a picture, honouring the UNCHANGED sentinel.
fn merge_args(picture: &mut Picture, args: &[i32]) {
    if let Some(value) = take(args, field::OPACITY) {
        picture.opacity = value.clamp(0, 255);
    }
    if let Some(value) = take(args, field::X) {
        picture.x = value;
    }
    if let Some(value) = take(args, field::Y) {
        picture.y = value;
    }
    if let Some(value) = take(args, field::SCALE) {
        picture.scale = value;
    }
    if let Some(value) = take(args, field::BLEND) {
        picture.blend = value;
    }
    // For file pictures the same two slots are the sprite-sheet grid and slot 3 is the
    // one-based cell, so a standing character can be one PNG holding six outfits.
    if matches!(picture.kind, PictureKind::File | PictureKind::FileString) {
        if let (Some(columns), Some(rows)) =
            (take(args, field::WINDOW_W), take(args, field::WINDOW_H))
        {
            if columns > 0 && rows > 0 {
                picture.split = (columns as u32, rows as u32);
            }
        }
        if let Some(pattern) = take(args, field::RESERVED) {
            if pattern > 0 {
                picture.pattern_index = pattern as u32;
            }
        }
    }
    // Window dimensions only mean something for the non-file kinds, and the short forms do
    // not carry them at all; a 0x0 window would make the text invisible, so require > 0 -
    // with one measured exception. All 7 `<LINE>` instructions in this game pass a zero
    // height and still draw a hairline, and refusing the pair here would throw the width
    // away with it (see crates/wolf-game/src/sysgraphic.rs). The exception is tied to the
    // built-in spelling so a degenerate text window is still refused.
    if !matches!(picture.kind, PictureKind::File | PictureKind::FileString) {
        if let (Some(w), Some(h)) = (take(args, field::WINDOW_W), take(args, field::WINDOW_H)) {
            let zero_height_ok = h == 0 && crate::sysgraphic::parse(&picture.file).is_some();
            if w > 0 && (h > 0 || zero_height_ok) {
                picture.window = Some((w, h));
            }
        }
    }
    if let Some(value) = take(args, field::FADE_IN) {
        picture.fade = value.clamp(0, 600) as u32;
    }
    if args.len() > field::EXTRAS {
        picture.extras = args[field::EXTRAS..].to_vec();
    }
    // The 150 long form also carries the base colour in the three slots the opcode
    // notes number 15..17; PictureCmd::args starts at raw arg 2, so they land at
    // 13..15 here. The short forms simply do not have them, which leaves the
    // default neutral tone in place.
    if let (Some(r), Some(g), Some(b)) = (
        take(args, field::TONE_R),
        take(args, field::TONE_G),
        take(args, field::TONE_B),
    ) {
        picture.tone = [r.clamp(0, 200), g.clamp(0, 200), b.clamp(0, 200)];
    }
}

/// Reads a field, mapping the UNCHANGED sentinel and out-of-range indices to None.
fn take(args: &[i32], index: usize) -> Option<i32> {
    match args.get(index) {
        Some(&value) if value != UNCHANGED => Some(value),
        _ => None,
    }
}
#[cfg(test)]
mod tests {
    use super::*;
    use wolf_vm::PictureCmd;

    #[test]
    fn every_effect_kind_the_game_ships_is_supported() {
        // 0,1,2,3,4,5,7,8,9,10 all occur in the data and are handled by Screen::effect.
        for kind in [0, 1, 2, 3, 4, 5, 7, 8, 9, 10] {
            assert!(
                Screen::effect_kind_supported(kind),
                "kind {kind} should be supported"
            );
        }
        // Type 6 (the second blink variant) has zero uses and stays unhandled on purpose;
        // out-of-range values are likewise rejected rather than guessed at.
        for kind in [6, -1, 11, 999] {
            assert!(
                !Screen::effect_kind_supported(kind),
                "kind {kind} should be unsupported"
            );
        }
    }

    /// Builds a command the way the interpreter does: args start at raw arg[2].
    fn cmd(
        number: i32,
        kind: u8,
        action: PictureAction,
        file: &str,
        text: &str,
        args: &[i32],
    ) -> PictureCmd {
        PictureCmd {
            number,
            kind,
            action,
            file: file.to_owned(),
            text: text.to_owned(),
            args: args.to_vec(),
            animate: Vec::new(),
            keep_shift: false,
            relative: false,
            anchor: ANCHOR_TOP_LEFT,
        }
    }

    /// A draw whose head word carries 0x10000 treats x/y as offsets from the slot current
    /// position. CE238 parks status panel 320 at x=-305, then redraws it with +305.
    #[test]
    fn a_relative_draw_offsets_from_the_current_position() {
        let mut screen = Screen::new();
        screen.apply(&cmd(
            320,
            0,
            PictureAction::Draw,
            "Picture/status01.png",
            "",
            &[0, 1, 1, 1, 255, -305, 0, 100, 0],
        ));
        let mut show = cmd(
            320,
            0,
            PictureAction::Draw,
            "Picture/status01.png",
            "",
            &[20, 1, 1, 1, 255, 305, 0, 100, 0],
        );
        show.relative = true;
        screen.apply(&show);
        let picture = screen.get(320).expect("panel");
        assert_eq!((picture.x, picture.y), (0, 0));
    }

    /// The same flag on a Move shifts a label relative to where the hidden panel put it.
    #[test]
    fn a_relative_move_offsets_from_the_current_position() {
        let mut screen = Screen::new();
        screen.apply(&cmd(
            321,
            2,
            PictureAction::Draw,
            "",
            "25",
            &[20, 0, 0, 1, 255, -65, 90, 100, 0],
        ));
        let mut show = cmd(
            321,
            2,
            PictureAction::Move,
            "",
            "",
            &[20, 0, 0, 1, 255, 305, 0, 100, 0],
        );
        show.relative = true;
        screen.apply(&show);
        let picture = screen.get(321).expect("label");
        assert_eq!((picture.x, picture.y), (240, 90));
    }

    /// A move without the flag must keep its absolute meaning; the 13k ordinary op150s
    /// in the retail data rely on that.
    #[test]
    fn an_absolute_move_is_not_offset() {
        let mut screen = Screen::new();
        screen.apply(&cmd(
            322,
            2,
            PictureAction::Draw,
            "",
            "10",
            &[20, 0, 0, 1, 255, -230, 405, 100, 0],
        ));
        screen.apply(&cmd(
            322,
            2,
            PictureAction::Move,
            "",
            "",
            &[20, 0, 0, 1, 255, 305, 0, 100, 0],
        ));
        let picture = screen.get(322).expect("label");
        assert_eq!((picture.x, picture.y), (305, 0));
    }

    /// A move built the way the interpreter builds one: `args` is the full argument list from
    /// raw arg 2, and `animate` is its tail from slot 11, which is where the frame count lives.
    fn animated_move(number: i32, args: &[i32]) -> PictureCmd {
        let mut command = cmd(number, 0, PictureAction::Move, "", "", args);
        command.animate = if args.len() > 11 {
            args[11..].to_vec()
        } else {
            Vec::new()
        };
        command
    }

    /// The argument list of a long-form move that writes x/y and leaves everything else alone.
    ///
    /// Slots 0..10 are the head of a real instruction (fade, window, opacity, x, y, scale,
    /// blend, extras) plus the 0x01000000 flag word; `frames` is the animation tail.
    fn slide_args(x: i32, y: i32, frames: &[i32]) -> Vec<i32> {
        let mut args = vec![
            0,
            UNCHANGED,
            UNCHANGED,
            1,
            UNCHANGED,
            x,
            y,
            UNCHANGED,
            UNCHANGED,
            UNCHANGED,
            0x0100_0000,
        ];
        args.extend_from_slice(frames);
        args
    }

    #[test]
    fn place_only_shifts_the_centre_anchor() {
        assert_eq!(
            place(ANCHOR_TOP_LEFT, 512, 520, 606.0, 35.0),
            [512.0, 520.0, 606.0, 35.0]
        );
        assert_eq!(
            place(ANCHOR_CENTRE, 512, 520, 606.0, 35.0),
            [209.0, 502.5, 606.0, 35.0]
        );
        // The unverified codes must behave like the corner, never like the centre.
        assert_eq!(place(3, 100, 50, 20.0, 10.0), [100.0, 50.0, 20.0, 10.0]);
    }

    #[test]
    fn a_centred_picture_places_its_middle_at_xy() {
        let mut screen = Screen::new();
        let mut command = cmd(
            12001,
            0,
            PictureAction::Draw,
            "SystemFile/Button01.png",
            "",
            &[4096, 1, 1, 1, 255, 512, 520, 100, 0],
        );
        command.anchor = ANCHOR_CENTRE;
        screen.apply(&command);
        let quads = screen.quads(|_| Some((606, 35)));
        assert_eq!(quads.len(), 1);
        assert_eq!(quads[0].dst, [209.0, 502.5, 606.0, 35.0]);
    }

    #[test]
    fn a_picture_parked_outside_the_screen_is_not_queued() {
        // The balloon library that event 98 sets up parks its controls at (-2784, 2880)
        // until a bubble opens. Those pictures are alive, but a quad there cannot reach a
        // pixel, and queueing it cost 30 quads plus a nine-slice skin pack per panel.
        let mut screen = Screen::new();
        screen.apply(&cmd(
            10225,
            0,
            PictureAction::Draw,
            "SystemFile/WindowBase.png",
            "",
            &[0, 368, 1872, 1, 255, -2784, 2880, 100, 0],
        ));
        assert_eq!(screen.len(), 1, "the picture is still alive");
        assert!(
            screen.quads(|_| Some((18, 18))).is_empty(),
            "parked picture drawn"
        );
        // A picture that only clips at an edge still draws: (1000, 500) overlaps.
        screen.apply(&cmd(
            7,
            0,
            PictureAction::Draw,
            "a.png",
            "",
            &[0, 1, 1, 1, 255, 1000, 500, 100, 0],
        ));
        assert_eq!(screen.quads(|_| Some((100, 100))).len(), 1);
    }

    #[test]
    fn a_move_can_switch_the_anchor() {
        let mut screen = Screen::new();
        screen.apply(&cmd(
            7,
            0,
            PictureAction::Draw,
            "a.png",
            "",
            &[0, 1, 1, 1, 255, 0, 0, 100, 0],
        ));
        let mut moved = cmd(
            7,
            0,
            PictureAction::Move,
            "",
            "",
            &[0, 1, 1, 1, 255, 512, 288, 100, 0],
        );
        moved.anchor = ANCHOR_CENTRE;
        screen.apply(&moved);
        let quads = screen.quads(|_| Some((100, 50)));
        assert_eq!(quads[0].dst, [462.0, 263.0, 100.0, 50.0]);
    }

    /// The real title background command, verbatim from event 42 pc20:
    /// raw [0, -2, 30, 1, 1, 1, 255, 0, 0, 100, 0] with file SystemGraphic/TitleGraphic.jpg,
    /// so args (everything after the type word and the number) is [30,1,1,1,255,0,0,100,0].
    fn title_background() -> PictureCmd {
        cmd(
            -2,
            0,
            PictureAction::Draw,
            "SystemGraphic/TitleGraphic.jpg",
            "",
            &[30, 1, 1, 1, 255, 0, 0, 100, 0],
        )
    }

    #[test]
    fn title_background_lands_where_the_measurement_says() {
        let mut screen = Screen::new();
        screen.apply(&title_background());
        let picture = screen.get(-2).expect("picture");
        assert_eq!(picture.kind, PictureKind::File);
        assert_eq!(picture.file, "SystemGraphic/TitleGraphic.jpg");
        assert_eq!(picture.x, 0);
        assert_eq!(picture.y, 0);
        assert_eq!(picture.scale, 100);
        assert_eq!(picture.opacity, 255);
        assert_eq!(picture.blend, 0);
        // The command carries 30 in the fade slot, so the art ramps in over 30 frames
        // instead of popping; the fully faded state is the steady one to assert here.
        assert_eq!(picture.fade, 30);
        assert_eq!(picture.alpha(), 0.0);
        for _ in 0..30 {
            screen.tick();
        }
        let picture = screen.get(-2).expect("picture");
        assert_eq!(picture.alpha(), 1.0);
        assert!(picture.is_screen_layer());
    }

    #[test]
    fn a_screen_layer_uses_its_native_size_and_position() {
        let mut screen = Screen::new();
        screen.apply(&title_background());
        let quads = screen.quads(|_| Some((1024, 576)));
        assert_eq!(quads.len(), 1);
        assert_eq!(quads[0].src, [0, 0, 1024, 576]);
        assert_eq!(quads[0].dst, [0.0, 0.0, 1024.0, 576.0]);

        // A fixed-screen HUD icon is also a negative slot, but it is 48x64 at (10,510):
        // the old full-screen shortcut drew it stretched across the whole viewport.
        let mut screen = Screen::new();
        screen.apply(&cmd(
            -5,
            0,
            PictureAction::Draw,
            "Picture/icon01.png",
            "",
            &[0, 1, 1, 1, 255, 10, 510, 100, 0],
        ));
        let quads = screen.quads(|_| Some((48, 64)));
        assert_eq!(quads.len(), 1);
        assert_eq!(quads[0].dst, [10.0, 510.0, 48.0, 64.0]);

        // Undersized files keep their own size too; scale, not the viewport, decides.
        let quads = screen.quads(|_| Some((512, 288)));
        assert_eq!(quads[0].dst, [10.0, 510.0, 512.0, 288.0]);
    }

    #[test]
    fn move_only_patches_fields_that_are_not_the_unchanged_sentinel() {
        let mut screen = Screen::new();
        screen.apply(&title_background());
        // Move to (100, 200) at 50% and leave opacity and blend alone.
        screen.apply(&cmd(
            -2,
            0,
            PictureAction::Move,
            "",
            "",
            &[
                UNCHANGED, UNCHANGED, UNCHANGED, UNCHANGED, UNCHANGED, 100, 200, 50, UNCHANGED,
            ],
        ));
        let picture = screen.get(-2).expect("picture");
        assert_eq!(picture.x, 100);
        assert_eq!(picture.y, 200);
        assert_eq!(picture.scale, 50);
        assert_eq!(picture.opacity, 255);
        assert_eq!(picture.blend, 0);
        assert_eq!(picture.file, "SystemGraphic/TitleGraphic.jpg");
    }

    #[test]
    fn move_creates_a_missing_slot_instead_of_dropping_the_mutation() {
        let mut screen = Screen::new();
        screen.apply(&cmd(
            7,
            0,
            PictureAction::Move,
            "Kagura/bg.png",
            "",
            &[
                UNCHANGED, UNCHANGED, UNCHANGED, UNCHANGED, UNCHANGED, 10, 20, 100, 0,
            ],
        ));
        let picture = screen.get(7).expect("created by move");
        assert_eq!(picture.x, 10);
        assert_eq!(picture.y, 20);
        assert_eq!(picture.file, "Kagura/bg.png");
    }

    /// The shortest argument list that draws a visible sprite.
    fn short_draw_args() -> [i32; 9] {
        [0, 1, 1, 1, 255, 0, 0, 100, 0]
    }

    #[test]
    fn erase_removes_the_slot_and_is_idempotent() {
        let mut screen = Screen::new();
        screen.apply(&title_background());
        assert_eq!(screen.len(), 1);
        screen.apply(&cmd(-2, 0, PictureAction::Erase, "", "", &[]));
        assert!(screen.is_empty());
        screen.apply(&cmd(-2, 0, PictureAction::Erase, "", "", &[]));
        assert!(screen.is_empty());
    }

    #[test]
    fn the_long_erase_form_clears_every_slot_between_its_endpoints() {
        let mut screen = Screen::new();
        for number in 50000..=50003 {
            screen.apply(&cmd(
                number,
                0,
                PictureAction::Draw,
                "a.png",
                "",
                &short_draw_args(),
            ));
        }
        screen.apply(&cmd(
            50004,
            0,
            PictureAction::Draw,
            "a.png",
            "",
            &short_draw_args(),
        ));
        // ce221 pc36, verbatim: the pair is 50000 and 50003.
        screen.apply(&cmd(
            50000,
            0,
            PictureAction::Erase,
            "",
            "",
            &[5, 5, 0, 50003],
        ));
        assert_eq!(
            screen.len(),
            1,
            "only the picture outside the pair survives"
        );
        assert!(screen.get(50004).is_some());
    }

    #[test]
    fn the_erase_range_is_read_between_its_endpoints_not_in_argument_order() {
        let mut screen = Screen::new();
        for number in [-2, -1] {
            screen.apply(&cmd(
                number,
                0,
                PictureAction::Draw,
                "a.png",
                "",
                &short_draw_args(),
            ));
        }
        // Map003.mps:ev1 pc24 passes the endpoints the wrong way round.
        screen.apply(&cmd(-1, 0, PictureAction::Erase, "", "", &[0, 0, 0, -2]));
        assert!(screen.is_empty());
    }

    #[test]
    fn the_short_erase_form_removes_only_its_own_slot() {
        let mut screen = Screen::new();
        for number in [10, 11, 12] {
            screen.apply(&cmd(
                number,
                0,
                PictureAction::Draw,
                "a.png",
                "",
                &short_draw_args(),
            ));
        }
        screen.apply(&cmd(11, 0, PictureAction::Erase, "", "", &[0]));
        assert_eq!(screen.len(), 2);
        assert!(screen.get(10).is_some() && screen.get(12).is_some());
    }

    #[test]
    fn a_hidden_picture_keeps_its_place_but_is_not_drawn() {
        // 150 action 3 is "hide" (ev63 uses it when the window fades below 1), not a
        // redraw: the slot keeps its file, box and position and simply stops painting.
        let mut screen = Screen::new();
        screen.apply(&cmd(
            12000,
            0,
            PictureAction::Draw,
            "Kagura/bg.png",
            "",
            &short_draw_args(),
        ));
        assert_eq!(screen.quads(|_| Some((1024, 576))).len(), 1);

        screen.apply(&cmd(12000, 0, PictureAction::Hide, "", "", &[]));
        let picture = screen.get(12000).expect("hide must not erase the slot");
        assert!(picture.hidden);
        assert_eq!(picture.file, "Kagura/bg.png");
        assert!(screen.quads(|_| Some((1024, 576))).is_empty());
    }

    #[test]
    fn a_hidden_window_keeps_its_skin_and_box() {
        let mut screen = Screen::new();
        let mut draw = cmd(
            19500,
            4,
            PictureAction::Draw,
            "SystemFile/WindowBase.png",
            "",
            &[5, 960, 168, 1, 255, 512, 480, 100, 0],
        );
        draw.anchor = ANCHOR_CENTRE;
        screen.apply(&draw);
        screen.apply(&cmd(19500, 4, PictureAction::Hide, "", "", &[]));

        let picture = screen.get(19500).expect("the window slot survives a hide");
        assert!(picture.hidden);
        assert_eq!(picture.file, "SystemFile/WindowBase.png");
        assert_eq!(picture.window, Some((960, 168)));
        assert_eq!(
            picture.destination(960.0, 168.0),
            [32.0, 396.0, 960.0, 168.0]
        );
    }

    #[test]
    fn opacity_is_clamped_and_transparent_pictures_are_not_drawn() {
        let mut screen = Screen::new();
        screen.apply(&cmd(
            1,
            0,
            PictureAction::Draw,
            "a.png",
            "",
            &[0, 0, 0, 0, 999, 0, 0, 100, 0],
        ));
        assert_eq!(screen.get(1).expect("picture").opacity, 255);
        screen.apply(&cmd(
            2,
            0,
            PictureAction::Draw,
            "b.png",
            "",
            &[0, 0, 0, 0, -5, 0, 0, 100, 0],
        ));
        assert_eq!(screen.get(2).expect("picture").opacity, 0);
        let quads = screen.quads(|_| Some((16, 16)));
        assert_eq!(quads.len(), 1);
        assert_eq!(quads[0].number, 1);
    }

    #[test]
    fn a_text_picture_carries_no_source_rect_and_the_window_rect_as_destination() {
        let mut screen = Screen::new();
        // The real notice window: 300x200 at (855, 200), text kind 2.
        screen.apply(&cmd(
            12500,
            2,
            PictureAction::Draw,
            "",
            "hello",
            &[0, 300, 200, 1, 255, 855, 200, 100, 0],
        ));
        let quads = screen.quads(|_| Some((1024, 576)));
        assert_eq!(quads.len(), 1);
        assert_eq!(quads[0].kind, PictureKind::Text);
        assert_eq!(quads[0].src, [0, 0, 0, 0]);
        assert_eq!(quads[0].dst, [855.0, 200.0, 300.0, 200.0]);
        assert_eq!(quads[0].text, "hello");
    }

    #[test]
    fn an_image_picture_with_an_unknown_texture_is_skipped() {
        let mut screen = Screen::new();
        screen.apply(&cmd(
            3,
            0,
            PictureAction::Draw,
            "missing.png",
            "",
            &[0, 0, 0, 0, 255, 5, 6, 100, 0],
        ));
        assert!(screen.quads(|_| None).is_empty());
        let quads = screen.quads(|_| Some((40, 20)));
        assert_eq!(quads.len(), 1);
        assert_eq!(quads[0].dst, [5.0, 6.0, 40.0, 20.0]);
    }

    #[test]
    fn a_system_graphic_picture_takes_its_box_from_the_window_fields() {
        let mut screen = Screen::new();
        // The retail progress-bar frame, and the spelling WOLF stores it as: kind 3.
        screen.apply(&cmd(
            40,
            3,
            PictureAction::Draw,
            "<SQUARE>FRAME",
            "",
            &[0, 120, 5, 1, 255, 320, 342, 100, 0],
        ));
        // The texture callback knows nothing about the name - that is the point: a built-in
        // shape must not need a file to have a size.
        let quads = screen.quads(|_| None);
        assert_eq!(quads.len(), 1);
        assert_eq!(quads[0].src, [0, 0, 120, 5]);
        assert_eq!(quads[0].dst, [320.0, 342.0, 120.0, 5.0]);

        // `<LINE>` really does arrive with h = 0 (all 7 instances); the width must survive
        // that, and the height becomes the one pixel the rule is.
        screen.apply(&cmd(
            41,
            3,
            PictureAction::Draw,
            "<LINE>",
            "",
            &[0, 400, 0, 1, 255, 10, 20, 100, 0],
        ));
        let quads = screen.quads(|_| None);
        assert_eq!(quads[1].src, [0, 0, 400, 1]);
        assert_eq!(quads[1].dst, [10.0, 20.0, 400.0, 1.0]);

        // A shape with no box at all cannot be placed and is dropped, like a missing file.
        screen.apply(&cmd(
            42,
            3,
            PictureAction::Draw,
            "<SQUARE>",
            "",
            &[0, 0, 0, 1, 255, 0, 0, 100, 0],
        ));
        assert_eq!(screen.quads(|_| None).len(), 2);
    }

    #[test]
    fn images_are_scaled_by_percent() {
        let mut screen = Screen::new();
        screen.apply(&cmd(
            3,
            0,
            PictureAction::Draw,
            "a.png",
            "",
            &[0, 0, 0, 0, 255, 5, 6, 250, 0],
        ));
        let quads = screen.quads(|_| Some((40, 20)));
        assert_eq!(quads[0].dst, [5.0, 6.0, 100.0, 50.0]);
    }

    #[test]
    fn iteration_is_in_ascending_number_order_because_that_is_the_draw_order() {
        let mut screen = Screen::new();
        for number in [5, -2, 12, 0] {
            screen.apply(&cmd(
                number,
                0,
                PictureAction::Draw,
                "a.png",
                "",
                &[0, 0, 0, 0, 255, 0, 0, 100, 0],
            ));
        }
        let order: Vec<i32> = screen.iter().map(|p| p.number).collect();
        assert_eq!(order, vec![-2, 0, 5, 12]);
        let quad_order: Vec<i32> = screen
            .quads(|_| Some((1, 1)))
            .into_iter()
            .map(|q| q.number)
            .collect();
        assert_eq!(quad_order, vec![-2, 0, 5, 12]);
    }

    #[test]
    fn tick_advances_the_animation_clock_and_clear_empties_the_screen() {
        let mut screen = Screen::new();
        screen.apply(&title_background());
        screen.tick();
        screen.tick();
        assert_eq!(screen.get(-2).expect("picture").age, 2);
        screen.clear();
        assert!(screen.is_empty());
    }

    #[test]
    fn draw_replaces_a_previous_picture_rather_than_patching_it() {
        let mut screen = Screen::new();
        screen.apply(&title_background());
        screen.apply(&cmd(
            0,
            0,
            PictureAction::Draw,
            "b.png",
            "",
            &[
                UNCHANGED, UNCHANGED, UNCHANGED, UNCHANGED, UNCHANGED, UNCHANGED, UNCHANGED,
                UNCHANGED, UNCHANGED,
            ],
        ));
        // Draw with everything unchanged means "back to the defaults", not "keep the old".
        let picture = screen.get(0).expect("picture");
        assert_eq!(picture.scale, SCALE_ONE);
        assert_eq!(picture.opacity, 255);
        assert_eq!(picture.file, "b.png");
    }

    #[test]
    fn a_three_frame_move_slides_to_the_target_and_only_then() {
        let mut screen = Screen::new();
        screen.apply(&cmd(
            7,
            0,
            PictureAction::Draw,
            "a.png",
            "",
            &short_draw_args(),
        ));
        // Applying the move must not jump the picture to the destination, or the first frame
        // of the slide would already show the end of it.
        screen.apply(&animated_move(7, &slide_args(300, 100, &[3])));
        let left = |screen: &Screen| screen.quads(|_| Some((100, 50)))[0].dst;
        assert_eq!(left(&screen), [0.0, 0.0, 100.0, 50.0]);
        assert!(screen.get(7).expect("picture").is_moving());

        let mut trail = vec![left(&screen)];
        for step in 1..=3 {
            screen.advance();
            trail.push(left(&screen));
            assert_eq!(
                screen.get(7).expect("picture").is_moving(),
                step < 3,
                "the slide is in flight until the third advance"
            );
        }
        assert_eq!(
            trail,
            vec![
                [0.0, 0.0, 100.0, 50.0],
                [100.0, 33.0, 100.0, 50.0],
                [200.0, 67.0, 100.0, 50.0],
                [300.0, 100.0, 100.0, 50.0],
            ]
        );
        assert!(
            trail
                .windows(2)
                .all(|pair| pair[1][0] > pair[0][0] && pair[1][1] > pair[0][1]),
            "every frame of the slide is further along than the one before"
        );
        // Landed to the pixel, and one more frame does not overshoot.
        screen.advance();
        assert_eq!(left(&screen), [300.0, 100.0, 100.0, 50.0]);
    }

    #[test]
    fn a_move_without_a_usable_duration_teleports_in_one_apply() {
        let mut screen = Screen::new();
        screen.apply(&cmd(
            7,
            0,
            PictureAction::Draw,
            "a.png",
            "",
            &short_draw_args(),
        ));

        // 2,817 of the game's 3,365 moves carry no tail at all.
        screen.apply(&animated_move(7, &slide_args(300, 100, &[])));
        let picture = screen.get(7).expect("picture");
        assert_eq!((picture.x, picture.y), (300, 100));
        assert!(!picture.is_moving());

        // A literal 0 in the duration slot (168 moves) means the same thing.
        screen.apply(&animated_move(7, &slide_args(40, 60, &[0])));
        let picture = screen.get(7).expect("picture");
        assert_eq!((picture.x, picture.y), (40, 60));
        assert!(!picture.is_moving());

        // And so does a self-variable reference the interpreter left unresolved.
        screen.apply(&animated_move(7, &slide_args(50, 70, &[1_600_032])));
        let picture = screen.get(7).expect("picture");
        assert_eq!((picture.x, picture.y), (50, 70));
        assert!(!picture.is_moving());
    }

    #[test]
    fn an_alpha_only_move_fades_the_alpha_while_the_rect_stays_put() {
        let mut screen = Screen::new();
        screen.apply(&cmd(
            7,
            0,
            PictureAction::Draw,
            "a.png",
            "",
            &[0, 1, 1, 1, 255, 10, 20, 100, 0],
        ));
        // ev63 pc102/pc103 shape: the position slots stay at the sentinel and only the opacity
        // travels, so every frame of the slide has to keep the same rectangle.
        let mut args = slide_args(UNCHANGED, UNCHANGED, &[4]);
        args[field::OPACITY] = 0;
        screen.apply(&animated_move(7, &args));

        let alpha = |screen: &Screen| screen.get(7).expect("picture").alpha();
        let rect = |screen: &Screen| screen.quads(|_| Some((40, 20)))[0].dst;
        assert_eq!(rect(&screen), [10.0, 20.0, 40.0, 20.0]);
        assert_eq!(alpha(&screen), 1.0);

        for (step, expected) in [191.0_f32, 128.0, 64.0].into_iter().enumerate() {
            screen.advance();
            assert_eq!(rect(&screen), [10.0, 20.0, 40.0, 20.0], "step {step}");
            assert_eq!(alpha(&screen), expected / 255.0, "step {step}");
        }

        screen.advance();
        assert_eq!(alpha(&screen), 0.0);
        assert!(!screen.get(7).expect("picture").is_moving());
        assert!(
            screen.quads(|_| Some((40, 20))).is_empty(),
            "opacity 0 is not drawn"
        );
    }

    #[test]
    fn advance_without_a_slide_changes_nothing() {
        let mut screen = Screen::new();
        screen.apply(&title_background());
        screen.tick();
        assert!(screen.iter().all(|picture| !picture.is_moving()));
        let state: Vec<(i32, i32, i32, i32, f32)> = screen
            .iter()
            .map(|p| (p.x, p.y, p.scale, p.opacity, p.alpha()))
            .collect();
        let quads = screen.quads(|_| Some((1024, 576)));
        for _ in 0..5 {
            screen.advance();
        }
        let after: Vec<(i32, i32, i32, i32, f32)> = screen
            .iter()
            .map(|p| (p.x, p.y, p.scale, p.opacity, p.alpha()))
            .collect();
        assert_eq!(state, after);
        assert_eq!(quads, screen.quads(|_| Some((1024, 576))));
    }

    #[test]
    fn a_slide_interpolates_from_the_current_fields_not_from_the_sentinels() {
        let mut screen = Screen::new();
        screen.apply(&cmd(
            7,
            0,
            PictureAction::Draw,
            "a.png",
            "",
            &[0, 1, 1, 1, 255, 10, 20, 100, 0],
        ));
        // Only x travels; y, scale and opacity stay at the sentinel and must keep their current
        // values instead of being interpolated from -1000000.
        screen.apply(&animated_move(7, &slide_args(250, UNCHANGED, &[2])));
        for step in 1..=2 {
            screen.advance();
            let picture = screen.get(7).expect("picture");
            assert_eq!(picture.y, 20, "unchanged y stays put (step {step})");
            assert_eq!(
                picture.scale, 100,
                "unchanged scale stays put (step {step})"
            );
            assert_eq!(
                picture.opacity, 255,
                "unchanged opacity stays put (step {step})"
            );
        }
        assert_eq!(screen.get(7).expect("picture").x, 250);

        // A second move while the first is still in flight re-bases from the frame on screen.
        screen.apply(&animated_move(7, &slide_args(UNCHANGED, 80, &[2])));
        screen.advance();
        let picture = screen.get(7).expect("picture");
        assert_eq!(picture.x, 250, "x is not part of the second move");
        assert_eq!(picture.y, 50, "y slides from 20 to 80 over 2 frames");
    }
}

#[cfg(test)]
mod tone_tests {
    use super::*;

    /// Pins the ramp that has to reproduce the retail banner tone of 222/255.
    ///
    /// TitleMap event 2 runs 290 with head 80, duration 30 and targets (-50, -50, -50):
    /// type 5, a 30 frame cycle, target 50 percent. The ramp therefore visits
    /// 50 + 50 * phase/30 percent, which converts to 128 + 127 * phase/30 bytes.
    /// A 30 frame cycle can only land on 128, 132, ... 255; 222 itself is unreachable
    /// because it needs phase 22.2. Phase 22 gives 221, the closest the cycle ever comes,
    /// so the assertion allows two bytes of slack rather than pretending the model has
    /// more resolution than the cycle length gives it. The retail screenshot is one
    /// arbitrary frame of that cycle and measures 222, between our 221 and 225.
    #[test]
    fn blink_ramp_reaches_the_retail_banner_tone() {
        let mut picture = Picture::new(12001);
        picture
            .effects
            .push(PictureEffect::new(EFFECT_BLINK, 30, [-50, -50, -50]));

        let mut closest: i32 = 0;
        for age in 0..30 {
            picture.effects[0].age = age;
            let byte = i32::from(picture.tone_byte()[0]);
            if (byte - 222).abs() < (closest - 222).abs() {
                closest = byte;
            }
        }
        assert!(
            (closest - 222).abs() <= 2,
            "closest byte to the retail 222 was {closest}"
        );
        picture.effects[0].age = 22;
        assert_eq!(picture.tone_byte(), [221, 221, 221]);
    }

    /// An effect multiplies the command base tone instead of replacing it.
    #[test]
    fn effect_multiplies_the_command_tone() {
        let mut picture = Picture::new(1);
        picture.tone = [100, 50, 0];
        assert_eq!(picture.tone_byte(), [255, 128, 0]);
        picture
            .effects
            .push(PictureEffect::new(EFFECT_FLASH, 25, [-50, 0, 0]));
        assert_eq!(picture.tone_byte(), [128, 128, 0]);
        assert_eq!(picture.alpha(), 1.0);
    }

    /// A type 5 blink ramps the base tone instead of scaling it.
    ///
    /// CE94 draws one cursor window per save slot at tone 0, then gives only the selected
    /// slot a 15-frame blink with target +100. A multiplier of a black base stays black,
    /// which is exactly the invisible save cursor this pins against: the frame must start
    /// white (100% + 100%), pass through grey, and return to black at the end of the
    /// cycle, so the player sees it pulse.
    #[test]
    fn blink_ramps_the_base_tone_instead_of_scaling_it() {
        let mut picture = Picture::new(12051);
        picture.tone = [0, 0, 0];
        picture
            .effects
            .push(PictureEffect::new(EFFECT_BLINK, 15, [100, 100, 100]));
        assert_eq!(picture.tone_byte(), [255, 255, 255], "start of the cycle");
        picture.effects[0].age = 7;
        let middle = picture.tone_byte()[0];
        assert!(
            (100..200).contains(&middle),
            "the frame passes through grey mid-cycle, got {middle}"
        );
        picture.effects[0].age = 14;
        let end = picture.tone_byte()[0];
        assert!(end < 30, "the ramp returns to the black base, got {end}");
    }

    /// A finished one-shot drops out of the list, so the base tone takes over again.
    #[test]
    fn finished_flash_falls_back_to_the_base_tone() {
        let mut screen = Screen::new();
        let mut picture = Picture::new(7);
        picture.tone = [50, 50, 50];
        picture
            .effects
            .push(PictureEffect::new(EFFECT_FLASH, 2, [-50, -50, -50]));
        screen.pictures.insert(7, picture);
        assert_eq!(screen.get(7).unwrap().tone_byte(), [64, 64, 64]);
        screen.tick();
        screen.tick();
        assert!(screen.get(7).unwrap().effects.is_empty());
        assert_eq!(screen.get(7).unwrap().tone_byte(), [128, 128, 128]);
    }
}

#[cfg(test)]
mod effect_tests {
    use super::*;

    /// One `290` argument list the way the interpreter hands it over.
    ///
    /// Slot 0 is the head word, which the interpreter has already split into the type it
    /// passes as `kind`, so the tests only have to make the slot exist.
    fn args(duration: i32, lo: i32, hi: i32, values: [i32; 3]) -> Vec<i32> {
        vec![0, duration, lo, hi, values[0], values[1], values[2]]
    }

    /// A screen holding one freshly drawn picture per number, in the given slots.
    fn screen_with(numbers: &[i32]) -> Screen {
        let mut screen = Screen::new();
        for number in numbers {
            screen.pictures.insert(*number, Picture::new(*number));
        }
        screen
    }

    /// A map change drops the whole-screen (negative) layers but keeps ordinary pictures.
    ///
    /// The sample title screen draws its art into slot -2; when its menu answers
    /// `はじめから` with a `130`, that art belongs to the old map and must not stay on
    /// top of the new scene, while numbered pictures (and the HUD) survive.
    #[test]
    fn a_map_change_clears_only_the_negative_screen_layers() {
        let mut screen = screen_with(&[-2, -1, 0, 50000, 12001]);
        screen.clear_screen_layers();
        let left: Vec<i32> = screen.iter().map(|picture| picture.number).collect();
        assert_eq!(left, vec![0, 12001, 50000]);
    }

    /// The picture range is the closed interval the manual describes, not two loose slots.
    ///
    /// Common event 85 blinks six cursors with one instruction and a type 5 dimmer darkens
    /// 72 pictures at once, so reading args 2 and 3 as two independent numbers would leave
    /// 70 of those 72 untouched.
    #[test]
    fn the_picture_range_is_closed_and_inclusive() {
        let mut screen = screen_with(&[1, 2, 3, 4, 5]);
        assert!(screen.effect(
            i32::from(EFFECT_COLOR_CORRECT),
            0,
            &args(0, 2, 4, [10, 0, 0])
        ));
        for number in 2..=4 {
            assert_eq!(
                screen.get(number).expect("picture").color_corr[0],
                10,
                "slot {number} is inside [2, 4]"
            );
        }
        assert_eq!(screen.get(1).expect("picture").color_corr[0], 0);
        assert_eq!(screen.get(5).expect("picture").color_corr[0], 0);
    }

    /// A range written high-to-low is swapped instead of matching nothing.
    ///
    /// Common event 94 slot 616 is the only instruction in the game that writes its ends in
    /// descending order. The engine cannot have drawn that as "no pictures at all", so the
    /// data is a typo and the ends get ordered.
    #[test]
    fn a_reversed_range_is_swapped_instead_of_touching_nothing() {
        let mut screen = screen_with(&[10, 11, 12]);
        assert!(screen.effect(i32::from(EFFECT_SHIFT), 0, &args(0, 12, 10, [4, -4, 0])));
        for number in [10, 11, 12] {
            assert_eq!(screen.get(number).expect("picture").shift, (4, -4));
        }
    }

    /// Type 1 assigns the colour offset; it does not accumulate and cannot be cancelled.
    ///
    /// This is the SampleMapA event 8 menu highlight: `+25` on the newly selected row and
    /// `(0, 0, 0)` on the row that was selected before. An accumulating correction could
    /// never be cleared by adding zero, and the game has no "clear all effects" instruction.
    #[test]
    fn colour_correction_assigns_instead_of_accumulating() {
        let mut screen = screen_with(&[3200, 3201]);
        screen.pictures.get_mut(&3200).expect("picture").tone = [50, 50, 50];

        let brightness = |screen: &Screen| screen.get(3200).expect("picture").tone_byte()[0];
        assert_eq!(brightness(&screen), 128, "50 percent of a channel");

        let highlight = args(1, 3200, 3201, [25, 25, 25]);
        assert!(screen.effect(i32::from(EFFECT_COLOR_CORRECT), 1, &highlight));
        assert_eq!(brightness(&screen), 191, "50 + 25 percent");
        // The very same instruction again must not reach 100 percent.
        assert!(screen.effect(i32::from(EFFECT_COLOR_CORRECT), 1, &highlight));
        assert_eq!(brightness(&screen), 191);

        let reset = args(1, 3200, 3201, [0, 0, 0]);
        assert!(screen.effect(i32::from(EFFECT_COLOR_CORRECT), 1, &reset));
        assert_eq!(brightness(&screen), 128, "back to the 150 base tone");
    }

    /// A finite shake alternates every period and then disappears instead of resting.
    #[test]
    fn a_shake_alternates_every_period_and_stops_after_its_count() {
        let mut screen = screen_with(&[900]);
        assert!(screen.effect(i32::from(EFFECT_SHAKE), 3, &args(3, 900, 900, [6, 0, 2])));
        let left = |screen: &Screen| screen.get(900).expect("picture").destination(10.0, 10.0)[0];

        assert_eq!(left(&screen), 6.0, "first half of the wave");
        for _ in 0..3 {
            screen.tick();
        }
        assert_eq!(left(&screen), -6.0, "second half of the wave");
        for _ in 0..3 {
            screen.tick();
        }
        assert!(screen.get(900).expect("picture").shake.is_none());
        assert_eq!(left(&screen), 0.0);
    }

    /// A shake asking for 100000 repetitions or more never ages out.
    ///
    /// The game writes 99999 in 124 instructions and 999999 in two more, which only means
    /// anything as "until something else stops it".
    #[test]
    fn an_endless_shake_survives_far_past_its_count() {
        let mut screen = screen_with(&[901]);
        assert!(screen.effect(
            i32::from(EFFECT_SHAKE),
            2,
            &args(2, 901, 901, [3, 3, 99_999])
        ));
        for _ in 0..1_000 {
            screen.tick();
        }
        assert!(screen.get(901).expect("picture").shake.is_some());
    }

    /// The type 7 expansion grows to its amplitude and then sits at the natural size.
    ///
    /// The shape is the one docs/OPCODE_290.md section 5.7 recommends: one excursion over
    /// the action time, then the rest frames back at 100 percent.
    #[test]
    fn the_expansion_grows_to_its_amplitude_then_rests() {
        let mut screen = screen_with(&[6100]);
        assert!(screen.effect(
            i32::from(EFFECT_BREATH),
            10,
            &args(10, 6100, 6100, [10, 20, 5])
        ));
        let size = |screen: &Screen| {
            let dst = screen.get(6100).expect("picture").destination(100.0, 50.0);
            (dst[2].round(), dst[3].round())
        };

        assert_eq!(
            size(&screen),
            (100.0, 50.0),
            "the cycle starts at 100 percent"
        );
        for _ in 0..5 {
            screen.tick();
        }
        assert_eq!(
            size(&screen),
            (105.0, 55.0),
            "half way into a 10 frame excursion"
        );
        for _ in 0..5 {
            screen.tick();
        }
        assert_eq!(
            size(&screen),
            (100.0, 50.0),
            "the rest frames sit at 100 percent"
        );
    }

    /// Types 8, 9 and 10 differ only in what they do at the far end of the sequence.
    #[test]
    fn pattern_animations_walk_and_terminate_differently_per_type() {
        let walk = |kind: u8, steps: usize| {
            let mut screen = screen_with(&[700]);
            assert!(screen.effect(i32::from(kind), 1, &args(1, 700, 700, [1, 3, 0])));
            let mut seen = vec![screen.get(700).expect("picture").pattern_now().expect("fx")];
            for _ in 0..steps {
                screen.tick();
                seen.push(screen.get(700).expect("picture").pattern_now().expect("fx"));
            }
            seen
        };

        // 8 stops and hands the picture back to the pattern its 150 command asked for -
        // the save-sheet default is 1, so the sequence ends at 1 instead of on a stale 3.
        assert_eq!(walk(EFFECT_PATTERN_ONCE, 3), vec![1, 2, 3, 1]);
        // 9 loops back to the first pattern.
        assert_eq!(walk(EFFECT_PATTERN_LOOP, 3), vec![1, 2, 3, 1]);
        // 10 turns around at the far end and walks back.
        assert_eq!(walk(EFFECT_PATTERN_PINGPONG, 3), vec![1, 2, 3, 2]);
    }

    /// A shift displaces the finished rectangle until another shift replaces it.
    #[test]
    fn a_shift_displaces_the_destination_until_it_is_set_back() {
        let mut screen = screen_with(&[512]);
        {
            let picture = screen.pictures.get_mut(&512).expect("picture");
            picture.x = 100;
            picture.y = 100;
        }
        assert!(screen.effect(i32::from(EFFECT_SHIFT), 0, &args(0, 512, 512, [7, -3, 0])));
        let dst = screen.get(512).expect("picture").destination(10.0, 10.0);
        assert_eq!((dst[0], dst[1]), (107.0, 97.0));

        // The type is named "final value": re-issuing zero puts the picture back and no
        // cancellation instruction is needed.
        assert!(screen.effect(i32::from(EFFECT_SHIFT), 0, &args(0, 512, 512, [0, 0, 0])));
        let dst = screen.get(512).expect("picture").destination(10.0, 10.0);
        assert_eq!((dst[0], dst[1]), (100.0, 100.0));
    }

    /// A zoom scales the placed rectangle about a SCREEN point, not about the picture.
    #[test]
    fn a_zoom_scales_the_placed_rectangle_about_its_centre() {
        let mut screen = screen_with(&[1200]);
        {
            let picture = screen.pictures.get_mut(&1200).expect("picture");
            picture.x = 512;
            picture.y = 288;
            picture.anchor = ANCHOR_CENTRE;
        }
        // args 4 and 5 are the centre in logical pixels and args 6 the percentage; all 49
        // zoom instructions in this game send 512 for x and 100 or 105 for the percentage.
        assert!(screen.effect(
            i32::from(EFFECT_ZOOM),
            0,
            &args(0, 1200, 1200, [512, 288, 200])
        ));
        let dst = screen.get(1200).expect("picture").destination(100.0, 100.0);
        assert_eq!(dst, [412.0, 188.0, 200.0, 200.0]);
    }

    /// A sprite-sheet picture draws only its one cell of the sheet.
    ///
    /// Retail save 90 is `stand_imouto_paja2.png` - a 2400x1300 wardrobe of six 400x650
    /// outfits by two poses - with pattern 2. The same file also backs eyes and mouths as
    /// 7x1 strips whose records say pattern 7, which is why the count is one-based.
    #[test]
    fn a_sprite_sheet_picture_draws_one_cell() {
        let mut screen = Screen::new();
        let mut picture = Picture::new(90);
        picture.file = "Picture/stand_imouto_paja2.png".to_owned();
        picture.split = (6, 2);
        picture.pattern_index = 2;
        screen.insert(picture);
        let quads =
            screen.quads(|name| (name == "Picture/stand_imouto_paja2.png").then_some((2400, 1300)));
        assert_eq!(quads.len(), 1);
        assert_eq!(quads[0].src, [400, 0, 400, 650]);
        assert_eq!(quads[0].dst, [0.0, 0.0, 400.0, 650.0]);

        // A pattern past the last row falls back to the sheet's first cell instead of
        // drawing outside the image.
        let mut picture = Picture::new(91);
        picture.file = "Picture/stand_imouto_paja2.png".to_owned();
        picture.split = (6, 2);
        picture.pattern_index = 99;
        screen.insert(picture);
        let quads =
            screen.quads(|name| (name == "Picture/stand_imouto_paja2.png").then_some((2400, 1300)));
        let cell = quads
            .iter()
            .find(|quad| quad.number == 91)
            .expect("picture 91");
        assert_eq!(cell.src, [0, 0, 400, 650]);
    }

    /// A `150` draw carries the same grid in its slots 1..3.
    #[test]
    fn a_draw_command_carries_the_sprite_grid() {
        let mut screen = Screen::new();
        screen.apply(&PictureCmd {
            number: 90,
            kind: 0,
            action: PictureAction::Draw,
            file: "Picture/stand_imouto_paja2.png".to_owned(),
            text: String::new(),
            args: vec![0, 6, 2, 2, 255, 600, 80, 100, 0],
            animate: Vec::new(),
            keep_shift: false,
            relative: false,
            anchor: ANCHOR_TOP_LEFT,
        });
        let picture = screen.get(90).expect("picture");
        assert_eq!(picture.split, (6, 2));
        assert_eq!(picture.pattern_index, 2);
        assert_eq!(picture.window, None, "a file picture has no window box");
        let quads =
            screen.quads(|name| (name == "Picture/stand_imouto_paja2.png").then_some((2400, 1300)));
        assert_eq!(quads[0].src, [400, 0, 400, 650]);
    }

    /// A `290` pattern animation overrides the `150` pattern while it runs.
    #[test]
    fn a_pattern_effect_selects_the_sheet_cell() {
        let mut screen = Screen::new();
        let mut picture = Picture::new(90);
        picture.file = "Picture/stand_imouto_paja2.png".to_owned();
        picture.split = (6, 2);
        picture.pattern_index = 1;
        picture.pattern = Some(PatternFx::new(EFFECT_PATTERN_LOOP, 2, 3, 4, 1));
        screen.insert(picture);
        let quads =
            screen.quads(|name| (name == "Picture/stand_imouto_paja2.png").then_some((2400, 1300)));
        assert_eq!(
            quads[0].src,
            [400, 0, 400, 650],
            "pattern 2 is the second cell"
        );
        for _ in 0..4 {
            screen.tick();
        }
        let quads =
            screen.quads(|name| (name == "Picture/stand_imouto_paja2.png").then_some((2400, 1300)));
        assert_eq!(
            quads[0].src,
            [800, 0, 400, 650],
            "the loop reaches pattern 3 next"
        );
    }

    /// The zoom percentage ramps over the action time instead of popping.
    #[test]
    fn a_zoom_ramps_over_its_action_time() {
        let mut zoom = Zoom::new((512, 288), 100, 200, 4);
        assert_eq!(zoom.percent(), 100);
        zoom.advance();
        zoom.advance();
        assert_eq!(zoom.percent(), 150);
        for _ in 0..4 {
            zoom.advance();
        }
        assert_eq!(zoom.percent(), 200, "the ramp parks at its target");
    }
}
