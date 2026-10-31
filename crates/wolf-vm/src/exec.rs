//! The scheduler and the opcode dispatch (docs/OPCODE_SPEC.md §5–§8).
//!
//! # Coroutines, not calls
//!
//! WOLF runs up to 108 event *instances* concurrently (docs/OPCODE_SPEC.md §7.1):
//! the 442 background common events of this game alone are 108 in practice, plus
//! every map event page and every menu. Each one is an [Instance] with its own
//! `pc` and self variables, and one frame advances all of them once.
//!
//! `210 CommonEvent` therefore does **not** push a Rust call frame: it spawns a
//! child [Instance] and marks the caller `WaitState::Child`. Three consequences
//! are worth spelling out because they are easy to get wrong:
//!
//! * recursion is bounded by the *instance list*, not by the machine stack, so a
//!   menu that calls back into its caller (real data does this) cannot overflow;
//! * the child's self variables are its own — the parent's `V6-0` is untouched;
//! * `172 TerminateEvent` inside the child ends only the child.
//!
//! # Blocking
//!
//! docs/OPCODE_SPEC.md §7.2 lists which instructions stop a coroutine for a frame
//! or until the player acts. This module encodes that table directly: a blocking
//! opcode sets [WaitState] and returns [Signal::Blocked]; everything else falls
//! through to `pc + 1` in the same frame.
//!
//! # Budget
//!
//! `170 StartLoop` is an unconditional loop and the data contains loops that only
//! leave via a variable condition. A bug in that condition must not hang the
//! process, so the frame has an instruction budget ([Vm::with_budget],
//! 200,000 by default — roughly 6x the whole title closure). Hitting it just ends
//! the frame early; the next frame resumes at the same `pc`.

use std::collections::BTreeSet;
use std::sync::Arc;

use wolf_format::command::{Command, RouteCommand, Slot, Tail};

use crate::magic::{Magic, MagicKind};
use crate::program::{arg, argc, BlockKind, Control, Program, ProgramSet, NO_RETURN_VALUE};
use crate::rng::WolfRng;
use crate::text::{self, EscapeBank, VarLookup};
use crate::vars::{SelfVars, Variables};

/// Identifies an event (a `CommonEvent.dat` row).
pub type EventId = u32;
/// Identifies a running coroutine.
pub type InstanceId = u32;

/// The `-1000000` sentinel used by `150 Picture` for "leave this field alone".
pub const PICTURE_UNCHANGED: i32 = -1_000_000;

/// Default instructions per frame across all instances.
pub const DEFAULT_BUDGET: usize = 200_000;

/// How many addresses a hot spot report keeps per coroutine.
pub const HOT_SPOTS: usize = 5;
/// Hard cap on concurrently running coroutines; a runaway `210` chain stops here.
pub const MAX_INSTANCES: usize = 4_096;

/// First self variable a called event sees its string arguments in (CSelf5).
///
/// The editor exposes four numeric inputs (CSelf0..3) and four string inputs
/// (CSelf5..8); the gap at CSelf4 belongs to the editor, not to us
/// (docs/OPCODE_210_RETURN.md section 8).
pub const SELF_ARG_STRING_OFFSET: usize = 5;
/// Flat self variable index of the first string argument: CSelf5
/// (magic `1_600_005`).
pub const SELF_ARG_STRING_BASE: usize = crate::magic::SELF_ARG_BASE + SELF_ARG_STRING_OFFSET;
/// How many string arguments a call can carry (CSelf5..8).
pub const SELF_ARG_STRING_SLOTS: usize = 4;

/// Severity for [Host::log].
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord)]
pub enum LogLevel {
    /// Per-instruction detail (only with tracing enabled).
    Trace,
    /// State changes worth seeing in a trace.
    Info,
    /// Something the original would tolerate but we had to guess at.
    Warn,
    /// Data we cannot execute; the coroutine keeps going where possible.
    Error,
}

/// What a coroutine is waiting for.
#[derive(Clone, Debug, PartialEq, Eq, Default)]
pub enum WaitState {
    /// Runnable.
    #[default]
    None,
    /// `180 Wait`: this many frames, counting down.
    Frames(u32),
    /// `101 Message`: until the player dismisses it.
    Message,
    /// `102 ShowChoices`: until a choice arrives; the block names the case table.
    Choice { block: usize },
    /// `210`/`300`: until the child coroutine ends.
    Child(InstanceId),
}

/// One open loop of a coroutine (docs/OPCODE_SPEC.md §4.6).
#[derive(Clone, Copy, Debug)]
pub struct LoopCtx {
    /// Index into [Program::blocks].
    pub block: usize,
    /// Remaining iterations; `-1` for an unconditional loop (`170`/`176`).
    pub remaining: i64,
}

/// A running coroutine.
#[derive(Clone, Debug)]
pub struct Instance {
    /// Unique within the [Vm].
    pub id: InstanceId,
    /// The coroutine that called us, if any.
    pub parent: Option<InstanceId>,
    /// Event id, for traces.
    pub event: EventId,
    /// Precompiled program.
    pub program: Arc<Program>,
    /// Next instruction.
    pub pc: usize,
    /// `V0-0 .. V9-99`, private to this coroutine.
    pub self_vars: SelfVars,
    /// What we are waiting for.
    pub wait: WaitState,
    /// Open loops, innermost last.
    pub loops: Vec<LoopCtx>,
    /// Where to write this coroutine's return value when it ends.
    pub return_to: Option<i32>,
    /// True when the owning event, not the coroutine, owns [SelfVars].
    ///
    /// A map page keeps its self variables in the map event, so they survive a
    /// page switch and a parallel restart. Such an instance is left in place by
    /// [Vm::reap_finished] after its program ends; the map runtime reads the
    /// bank and retires the instance itself. Common events keep the default
    /// false and are reaped exactly as before.
    pub retain_after_finish: bool,
}

impl Instance {
    /// Fresh coroutine at pc 0.
    #[must_use]
    pub fn new(id: InstanceId, parent: Option<InstanceId>, program: Arc<Program>) -> Self {
        let event = program.id;
        Self {
            id,
            parent,
            event,
            program,
            pc: 0,
            self_vars: SelfVars::new(),
            wait: WaitState::None,
            loops: Vec::new(),
            return_to: None,
            retain_after_finish: false,
        }
    }

    /// True when this coroutine can be advanced this frame.
    #[must_use]
    pub fn is_runnable(&self) -> bool {
        self.wait == WaitState::None
    }
}

/// `\cself[n]` names slot `n` of the running event, which is NOT bank `n`:
/// a common event keeps its own variables in group 6, a map page in group 1
/// (see [`crate::program::COMMON_SELF_BASE`]). The file spells the same slots
/// absolutely as magic `1_600_000 + n`, so only the escape needs this offset.
impl VarLookup for Instance {
    fn lookup_num(&self, bank: EscapeBank, index: usize) -> i32 {
        match bank {
            EscapeBank::SelfVar => self.self_vars.get(self.program.self_base + index),
            _ => 0,
        }
    }

    fn lookup_str(&self, bank: EscapeBank, index: usize) -> String {
        match bank {
            EscapeBank::SelfVar => self
                .self_vars
                .get_str(self.program.self_base + index)
                .to_owned(),
            _ => String::new(),
        }
    }
}

/// Reads that span the self bank and the global banks.
struct Lookup<'a> {
    inst: &'a Instance,
    vars: &'a Variables,
}

impl VarLookup for Lookup<'_> {
    fn lookup_num(&self, bank: EscapeBank, index: usize) -> i32 {
        match bank {
            EscapeBank::SelfVar => self.inst.self_vars.get(self.inst.program.self_base + index),
            EscapeBank::Var => self.vars.get(index),
            EscapeBank::SysVar => self.vars.get_sys(index),
            // A numeric read of a string bank is a data error; WOLF yields 0.
            EscapeBank::StrVar => 0,
        }
    }

    fn lookup_str(&self, bank: EscapeBank, index: usize) -> String {
        match bank {
            EscapeBank::SelfVar => self
                .inst
                .self_vars
                .get_str(self.inst.program.self_base + index)
                .to_owned(),
            EscapeBank::Var => String::new(),
            EscapeBank::StrVar => self.vars.get_str(index).to_owned(),
            EscapeBank::SysVar => self.vars.get_sys_str(index).to_owned(),
        }
    }
}

/// A decoded `150 Picture` instruction.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct PictureCmd {
    /// Picture slot (WOLF calls it the "picture number").
    pub number: i32,
    /// Picture type: 0 file, 1 file-from-string-var, 2 text, 3 window-file, 4 window-string.
    pub kind: u8,
    /// What to do with the slot.
    pub action: PictureAction,
    /// Resolved file name (types 0/3) — escapes already expanded.
    pub file: String,
    /// Resolved text (types 2/4).
    pub text: String,
    /// x, y, scale-x, scale-y, opacity, rotation, blend, and the remaining slots.
    pub args: Vec<i32>,
    /// Where args measures x/y from: 0 = top-left corner, 1 = centre (bit 0x1000 of the
    /// head word). See crates/wolf-game/src/picture.rs for the measurement behind this.
    pub anchor: u8,
    /// Trailing animation slots for the long form (docs/OPCODE_SPEC.md §5.31).
    pub animate: Vec<i32>,
    /// Bit 0x400000 of the head word asks the draw to inherit the slot's existing
    /// draw-coordinate shift instead of resetting it. Common event 95's settings screen
    /// redraws its help text with head 0x411f20, x=y=0 and relies on the shift that a
    /// preceding 290 left on the slot; without this the text lands at the screen origin.
    pub keep_shift: bool,
    /// Bit 0x10000 of the head word marks x/y as offsets from the picture's current
    /// position instead of absolute screen coordinates. Common event 238 parks the status
    /// panel at x=-305 and then redraws it with head 0x10000 and x=305, which puts it at
    /// x=0 on screen; the same flag on the five label moves shifts each label by (+305, 0)
    /// from where the hidden panel drew it. Treating those words absolutely parks the whole
    /// panel at x=305 and stacks every label on top of it.
    pub relative: bool,
}

/// The `cmd` nibble of a `150 Picture` instruction.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum PictureAction {
    /// `cmd 0` — create/draw.
    Draw,
    /// `cmd 1` — move or animate an existing picture.
    Move,
    /// `cmd 2` — erase.
    Erase,
    /// `cmd 3` — hide the slot without disturbing its fields.
    ///
    /// Common event 63 writes `150 [3, 19500]` under the comment フェードが1以外ならウィンドウを非表示
    /// (hide the window when the fade is not 1) every time it parks its message window.
    /// Decoding that as a redraw threw the window's skin name and box size away, which is
    /// why the 101 message frame never appeared in a capture.
    Hide,
    /// `cmd 4..` — never emitted by the editor; kept so decoding stays total.
    Set,
}

/// Which mixer channel a `140 PlaySound` instruction addressed.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum SoundChannel {
    /// Background music.
    Bgm,
    /// Sound effect.
    Se,
}

/// A decoded `140 PlaySound` instruction.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct SoundCmd {
    /// BGM or SE.
    pub channel: SoundChannel,
    /// Play or stop.
    pub action: SoundAction,
    /// File name, escapes expanded (empty for a stop).
    pub file: String,
    /// Volume from intArgs[4], 0..=100 in retail data (the editor also stores 200 for a
    /// few loud SE; the mixer clamps at full scale).
    pub volume: i32,
    /// intArgs[1]: fade-in length for BGM, start delay for SE, or fade-out length for a
    /// stop. The mixer currently consumes it only on stop.
    pub frames: i32,
}

/// What a `140 PlaySound` does.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum SoundAction {
    /// Start playing.
    Play,
    /// Stop, optionally fading.
    Stop,
}

/// A decoded `250 DatabaseAccess` instruction.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct DbOp {
    /// Which of the three databases this addresses, from `(flags >> 8) & 3`
    /// (docs/OPCODE_250.md section 3.2: 2,195 of 2,195 labelled sites agree).
    pub container: DbContainer,
    /// Read (cell -> variable) or write (variable -> cell), from `flags & 0x1000`
    /// (docs/OPCODE_250.md section 3.3).
    pub direction: DbDirection,
    /// The cell arithmetic, `(flags >> 4) & 7`: 0 assign, 1 add, 2 sub, 3 mul,
    /// 4 div, 5 rem, 6 max, 7 min (docs/OPCODE_250.md section 3.4).
    pub op: u8,
    /// Database type (0..=24), already evaluated.
    pub db_type: i32,
    /// Row id, already evaluated (it is often a `1_600_000+` self variable).
    pub data_id: i32,
    /// Column id, already evaluated.
    pub item_id: i32,
    /// Raw addressing bitfield, kept verbatim for logging.
    pub flags: i32,
    /// Destination variable address (a magic operand) for a read.
    ///
    /// Always `None` for a write: there the fifth operand is the *source* value,
    /// which travels in [`DbOp::source`] instead (docs/OPCODE_250.md section 0.1
    /// item 5).
    pub destination: Option<i32>,
    /// Source value for a write, already evaluated.
    ///
    /// [`DbValue::Num`] is the fifth operand; [`DbValue::Str`] is
    /// `stringArgs[0]` for the 16 `argc == 4` sites that carry no operand at all
    /// (docs/OPCODE_250.md section 1.3).
    pub source: Option<DbValue>,
    /// `stringArgs[1]`: the type name the editor recorded (empty for 9 sites).
    ///
    /// This is the most reliable key for resolving [`DbOp::db_type`], which is a
    /// runtime type id rather than a `.dat` index (docs/OPCODE_250.md section 4).
    pub type_label: Option<String>,
    /// `stringArgs[3]`: the column name the editor recorded.
    pub field_label: Option<String>,
}

impl DbOp {
    /// True when the instruction carries no value operand and the string in
    /// `stringArgs[0]` is what gets written (docs/OPCODE_250.md section 1.3).
    #[must_use]
    pub const fn string_write(&self) -> bool {
        matches!(self.source, Some(DbValue::Str(_)))
    }
}

/// Which database a `250` addresses, from `(flags >> 8) & 3`.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum DbContainer {
    /// `BasicData/CDataBase.dat` (可変DB), flag value 0.
    CData,
    /// `BasicData/SysDatabase.dat` (システムDB), flag value 1.
    Sys,
    /// `BasicData/DataBase.dat` (ユーザーDB), flag value 2.
    Data,
}

impl DbContainer {
    /// Decode the container from a `250` flags word.
    ///
    /// Never use bit 9: it happens to look right for `Data` but maps
    /// `Sys` (which only sets bit 8) onto `CData` (docs/OPCODE_250.md section 3.2).
    #[must_use]
    pub const fn from_flags(flags: i32) -> Self {
        match (flags >> 8) & 3 {
            1 => Self::Sys,
            2 => Self::Data,
            // 0 is the variable database; 3 never appears in this game and the
            // engine has no fourth container, so fall back to CDataBase.
            _ => Self::CData,
        }
    }
}

/// Which way a `250` moves data, from `flags & 0x1000`.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum DbDirection {
    /// Bit 12 set: database cell -> the variable in [`DbOp::destination`].
    Read,
    /// Bit 12 clear: [`DbOp::source`] -> database cell, through [`DbOp::op`].
    Write,
}

impl DbDirection {
    /// Decode the direction from a `250` flags word.
    ///
    /// Bit 16 is *not* the direction: it only records that `stringArgs[1]` is
    /// non-empty (docs/OPCODE_250.md section 3.5).
    #[must_use]
    pub const fn from_flags(flags: i32) -> Self {
        if flags & 0x1000 == 0 {
            Self::Write
        } else {
            Self::Read
        }
    }
}

/// One cell value crossing the [`DbOp`] boundary.
///
/// A read hands an answer back in this shape; a write carries its source value the
/// same way, in [`DbOp::source`].
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum DbValue {
    /// A numeric cell.
    Num(i32),
    /// A string cell.
    Str(String),
}

/// Where a `220`/`221`/`222` instruction points.
///
/// WOLF chooses between a slot and an explicit path by the *type* of the magic
/// operand, not by its value: a string variable holds `Save/System.sav`, a
/// numeric variable holds a slot number (docs/OPCODE_220_SAVE.md section 2.1).
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum SaveTarget {
    /// A numeric slot, one-based; the engine maps it to `Save/SaveDataNN.sav`.
    Slot(i32),
    /// An explicit path from a string variable.
    Path(String),
}

/// A decoded `220 SaveLoad` / `221 LoadGame` / `222 SaveGame` instruction.
///
/// The three opcodes share a magic-evaluated file operand but differ in what the
/// other two operands mean, so one struct with an explicit [`SaveOp::opcode`] is
/// simpler than three nearly identical host calls.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct SaveOp {
    /// 220, 221 or 222.
    pub opcode: u8,
    /// 220 only: 0 = save, 1 = load.
    pub mode: i32,
    /// The file to read or write.
    pub file: SaveTarget,
    /// 221 only: the running variable that receives the loaded value.
    pub destination: i32,
    /// 221/222: the variable address inside the save file, raw magic.
    pub address: i32,
    /// 222 only: the source value, already evaluated.
    pub value: i32,
    /// The trailing flag; 0 in 34 of 37 `221` sites and all 5 `222` sites.
    pub flag: i32,
    /// The common event that issued the instruction, so a `1_600_000+`
    /// address can be resolved against that event's self-variable group.
    pub owner: EventId,
}

/// What stopped (or did not stop) a coroutine.
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum Signal {
    /// Ran until the frame's instruction budget was exhausted.
    Continue,
    /// Set a [WaitState]; nothing more this frame.
    Blocked,
    /// The coroutine ended (pc ran off the end, `172`, or `173`).
    Finished,
    /// `210 CommonEvent`: spawn a child and block.
    Call {
        /// Event to call.
        target: EventId,
        /// Numeric arguments, already evaluated.
        args: Vec<i32>,
        /// String arguments, already resolved (literal or variable).
        strings: Vec<String>,
        /// Where the child's return value goes, if the call asked for one.
        return_to: Option<i32>,
    },
    /// `300 CallByName`: same, but resolved through the event title.
    CallByName {
        /// Event title.
        name: String,
        /// Numeric arguments, already evaluated.
        args: Vec<i32>,
        /// String arguments, already resolved (literal or variable).
        strings: Vec<String>,
        /// Where the child's return value goes, if the call asked for one.
        return_to: Option<i32>,
    },
    /// `174 ReturnToTitle`.
    ReturnToTitle,
    /// `175 EndGame`.
    EndGame,
    /// Data we could not execute; the frame continues with other coroutines.
    Error(String),
}

/// Result of advancing one coroutine.
#[derive(Clone, Debug)]
pub struct BlockResult {
    /// How it stopped.
    pub signal: Signal,
    /// Instructions executed.
    pub steps: usize,
}

/// What the platform layer has to do for the interpreter.
///
/// Every method has a default: `wolf-cli` only overrides `log` and `show_message`
/// and gets a fully working trace host, which is how the M1 acceptance test is
/// driven.
pub trait Host {
    /// `101 Message`: display `text` and keep it up until
    /// [Host::message_dismissed] returns true. `face` is the `@n` speaker prefix
    /// (20 messages carry one, docs/OPCODE_SPEC.md §5.3).
    fn show_message(&mut self, text: &str, face: Option<i32>) {
        let _ = (text, face);
    }

    /// Has the player advanced the message? Polled once per frame.
    fn message_dismissed(&mut self) -> bool {
        true
    }

    /// `105 CloseMessage`: take the message window down without waiting.
    fn close_message(&mut self) {}

    /// `102 ShowChoices`: present the options and keep them up until
    /// [Host::choice_made] answers.
    fn show_choices(&mut self, options: &[String]) {
        let _ = options;
    }

    /// Polled once per frame while a `102` is blocking.
    fn choice_made(&mut self) -> Option<ChoiceReply> {
        Some(ChoiceReply::Index(0))
    }

    /// `150 Picture`.
    fn picture(&mut self, cmd: &PictureCmd) {
        let _ = cmd;
    }

    /// `140 PlaySound`.
    fn sound(&mut self, cmd: &SoundCmd) {
        let _ = cmd;
    }

    /// `250 DatabaseAccess`. Answers the cell the script asked for; `None` leaves
    /// the destination variable untouched, exactly like a cell that is empty in
    /// the editor.
    fn database(&mut self, op: &DbOp) -> Option<DbValue> {
        let _ = op;
        None
    }

    /// Reads one cell addressed by a database-value magic operand (the
    /// `1_100_000_000 + row*100 + column` bank used by CE242/CE250/CE251/CE258).
    ///
    /// This is deliberately separate from [`Host::database`]: that call carries
    /// editor labels and statistics, while a condition operand only needs the
    /// current numeric value.  The default `None` gives the same result as an
    /// empty cell, so headless hosts keep working unchanged.
    fn database_cell(
        &mut self,
        container: DbContainer,
        db_type: i32,
        row: i32,
        column: i32,
    ) -> Option<i32> {
        let _ = (container, db_type, row, column);
        None
    }

    /// Writes one cell addressed by a database-value magic operand.
    ///
    /// Returns whether the write landed.  The default `false` keeps hosts that
    /// do not own a database unchanged.
    fn set_database_cell(
        &mut self,
        container: DbContainer,
        db_type: i32,
        row: i32,
        column: i32,
        value: i32,
    ) -> bool {
        let _ = (container, db_type, row, column, value);
        false
    }

    /// `201 SetMoveRoute`.
    fn move_route(&mut self, target: i32, route: &[RouteCommand]) {
        let _ = (target, route);
    }

    /// `130 Teleport`.
    ///
    /// The raw command is `target, x, y, map, options` (WOLF's transfer command):
    /// `target` is `0xffffffff` for the hero, `0xefd8ffff` for a saved position,
    /// or a variable id; `options` packs precise-coordinate (bit 0) and the
    /// transition kind (bits 4..7). `map` is the destination map id.
    fn teleport(&mut self, target: i32, map: i32, x: i32, y: i32, options: i32) {
        let _ = (target, map, x, y, options);
    }

    /// `160 Transition`.
    fn transition(&mut self, kind: i32, flags: i32) {
        let _ = (kind, flags);
    }

    /// `151 ChangeColor`: whole-screen colour multiplier.
    ///
    /// `colour` packs R/G/B in its low three bytes (100 = neutral) and the flash
    /// flag in the top byte; `frames` is the ramp length. Pictures 0 and above are
    /// not affected, pictures -1 and below are - the host applies the multiplier
    /// to the screen layers it owns.
    fn change_color(&mut self, colour: i32, frames: i32) {
        let _ = (colour, frames);
    }

    /// `270 Party` (add/remove/reorder party members).
    fn party(&mut self, args: &[i32]) {
        let _ = args;
    }

    /// `281 Scroll` (camera scroll).
    fn scroll(&mut self, args: &[i32]) {
        let _ = args;
    }

    /// `290 Effect` (screen effects).
    fn effect(&mut self, kind: i32, duration: i32, args: &[i32]) {
        let _ = (kind, duration, args);
    }

    /// `220 SaveLoad`, `221 LoadGame`, `222 SaveGame`.
    ///
    /// A `221` read returns the value the interpreter must store in
    /// [`SaveOp::destination`]; the other two return `None`.
    fn save_load(&mut self, op: &SaveOp) -> Option<i32> {
        let _ = op;
        None
    }

    /// `211 CommonEventReserve`: schedule an event to start after this one ends.
    fn reserve(&mut self, event: EventId) {
        let _ = event;
    }

    /// Reads one attribute of a picture for `124 SetVariableEx` (`0x4000` / `0x4400`).
    ///
    /// Returns `None` when the host has no opinion, which makes the interpreter leave
    /// the destination variable untouched - the same behaviour the original engine has
    /// for a picture number that does not exist (docs/OPCODE_124.md §3.1).
    fn picture_state(&mut self, number: i32, field: i32) -> Option<i32> {
        let _ = (number, field);
        None
    }

    /// Reads one attribute of a map event or party member for `124` (`0x1000` / `0x1200`).
    ///
    /// The map layer only arrives in M2, so the default is "unknown".
    fn character_state(&mut self, target: i32, field: i32) -> Option<i32> {
        let _ = (target, field);
        None
    }

    /// Reads one engine attribute for `124` (`0x3000`): mouse, map id, BGM id, ...
    ///
    /// `field 18` (the event being processed) is answered by the interpreter itself, so
    /// hosts never have to know their own event id.
    fn engine_state(&mut self, field: i32) -> Option<i32> {
        let _ = field;
        None
    }

    /// Key code a script reads for opcode 123, given the poll's key `mask`.
    ///
    /// The value is a CODE, not a bit pattern: 10 decide, 11 cancel, 12 sub, and the
    /// numpad direction codes (2 down, 4 left, 6 right, 8 up), 0 when nothing is
    /// held. The evidence is the developers' own debug comments next to the
    /// comparisons in this game (crates/wolf-game/src/key.rs lists them).
    ///
    /// What the mask selects is still unknown, which is why it is handed to the host
    /// instead of being applied here: one poll can yield six different codes.
    /// Headless hosts return 0, which reads exactly like "nobody is touching the
    /// keyboard".
    fn key_code(&mut self, mask: u32) -> i32 {
        let _ = mask;
        0
    }

    /// Like [`Host::key_code`], with the key bits opcode 125 asked the engine to
    /// press even when the player is not touching the keyboard.
    ///
    /// The interpreter passes its current `InputState::auto_keys` here on every
    /// 123 poll. A host that owns a real keyboard can OR the bits into its held-key
    /// state; the default ignores them, which keeps every headless host unchanged.
    fn key_code_auto(&mut self, mask: u32, auto: u32) -> i32 {
        let _ = auto;
        self.key_code(mask)
    }

    /// `106 DebugMessage`.
    fn debug_message(&mut self, text: &str) {
        let _ = text;
    }

    /// `107 ClearDebugMessage`.
    fn clear_debug(&mut self) {}

    /// `174 ReturnToTitle`.
    fn return_to_title(&mut self) {}

    /// `175 EndGame`.
    fn end_game(&mut self) {}

    /// `1000 ProFeature`.
    fn pro_feature(&mut self, kind: i32, milliseconds: i32) {
        let _ = (kind, milliseconds);
    }

    /// Any diagnostic the interpreter wants to surface.
    fn log(&mut self, level: LogLevel, message: &str) {
        let _ = (level, message);
    }
}

/// Answer to a blocking `102 ShowChoices`.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum ChoiceReply {
    /// Option index, 0-based.
    Index(usize),
    /// The player cancelled out of the window.
    Cancel,
}

/// Aggregate result of one frame.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct StepReport {
    /// Frame counter (starts at 1).
    pub frame: u64,
    /// Instructions executed across all coroutines.
    pub steps: usize,
    /// Coroutines alive at the end of the frame.
    pub running: usize,
    /// Coroutines that ended during this frame.
    pub finished: usize,
    /// Diagnostics produced this frame.
    pub notes: Vec<String>,
    /// The most frequently executed addresses of this frame, filled only when
    /// `Vm::hot_trace` is on (the histogram costs a linear scan per step).
    pub hottest: Vec<HotSpot>,
}

/// One instruction address the interpreter executed many times in one frame.
///
/// A script that burns the whole per-frame budget shows up here as a handful of
/// addresses with tens of thousands of hits each -- that is how an endless loop
/// and a poll of a flag that never changes are told apart.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct HotSpot {
    /// Event whose coroutine ran the address.
    pub event: EventId,
    /// Program counter inside that event.
    pub pc: usize,
    /// How many times it ran during the frame.
    pub hits: u64,
}

/// Input policy set by the two input-control opcodes.
///
/// 125 (auto input) and 126 (ban input) both take a single int argument that is
/// a key mask in the same bit space that 123 polls: this game passes 1, 2, 16,
/// 32, 64, 128, 240, 247, 496, 752 - the OK/cancel/sub bits plus the four
/// direction bits, sometimes all at once (247 = every key). The value persists
/// until the script writes it again, so the two masks are state, not one-shot
/// commands.
///
/// Banning is applied by the interpreter itself: the banned bits are cleared out
/// of the mask handed to the host, so a banned key reads as not pressed. Auto
/// input is passed to the host on every 123 poll through `Host::key_code_auto`;
/// a host that owns a real keyboard ORs it into the held-key state, while a
/// headless host keeps its default "nobody is touching the keyboard". 126 appears
/// in the opening script (it bans every key for the cutscene); 125 is polled by the
/// UI cursor events in the real game.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct InputState {
    /// Key bits the script wants pressed even when the player is not pressing them.
    pub auto_keys: u32,
    /// Key bits the script wants ignored while they are held.
    pub ban_keys: u32,
}

/// Transition setting installed by opcode 160 and consumed by 161/162.
///
/// `kind` is the transition type (`-1` = simple cut, the shipped default).
/// `flags` packs the duration in its low byte and the "wait for the transition"
/// bit at 0x1_0000 (the CE48 default is 0x0001_000A = wait, 10 frames). WOLF
/// keeps one setting for the whole game: 160 replaces it, 161 prepares the screen
/// freeze and 162 executes and blocks for the configured number of frames.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct TransitionState {
    /// Transition type from opcode 160, `-1` for a simple cut.
    pub kind: i32,
    /// Duration (low byte) and wait flag (bit 16).
    pub flags: i32,
    /// True between 161 PrepareTransition and 162 ExecuteTransition.
    pub prepared: bool,
}

impl TransitionState {
    /// Frames 162 blocks for. The engine treats a zero duration as one frame.
    #[must_use]
    pub const fn frames(&self) -> u32 {
        let frames = (self.flags & 0xFF) as u32;
        if frames == 0 {
            1
        } else {
            frames
        }
    }
}

/// The interpreter.
pub struct Vm {
    /// Every precompiled common event.
    pub programs: ProgramSet,
    /// The global variable banks.
    pub vars: Variables,
    /// Running coroutines, in spawn order.
    instances: Vec<Instance>,
    next_id: InstanceId,
    frame: u64,
    budget: usize,
    /// Random source for 121's 0x6000 operator (docs/OPCODE_SPEC.md §3.2).
    pub rng: WolfRng,
    /// Collect a per-frame instruction histogram into StepReport::hottest.
    pub hot_trace: bool,
    /// Input policy set by opcodes 125 and 126.
    pub input: InputState,
    /// Transition setting shared by 160/161/162.
    pub transition: TransitionState,
    /// Every common-event id this VM started at least once. The M6 main-line
    /// harness reads this to prove how many of the 108 background coroutines
    /// were exercised by a run (docs/HANDOFF_M4.md section 4.6).
    pub started_events: BTreeSet<EventId>,
    /// Successful `start_event` calls, including restarts of the same id.
    pub started_event_total: u64,
}

impl Vm {
    /// A VM over a precompiled event set.
    #[must_use]
    pub fn new(programs: ProgramSet) -> Self {
        Self {
            programs,
            vars: Variables::new(),
            instances: Vec::new(),
            next_id: 1,
            frame: 0,
            budget: DEFAULT_BUDGET,
            rng: WolfRng::new(),
            hot_trace: false,
            input: InputState::default(),
            transition: TransitionState::default(),
            started_events: BTreeSet::new(),
            started_event_total: 0,
        }
    }

    /// Same, with a custom per-frame instruction budget.
    #[must_use]
    pub fn with_budget(programs: ProgramSet, budget: usize) -> Self {
        let mut vm = Self::new(programs);
        vm.budget = budget.max(1);
        vm
    }

    /// Frames elapsed.
    #[must_use]
    pub const fn frame(&self) -> u64 {
        self.frame
    }

    /// Running coroutines.
    #[must_use]
    pub fn instances(&self) -> &[Instance] {
        &self.instances
    }

    /// One coroutine by id.
    #[must_use]
    pub fn instance(&self, id: InstanceId) -> Option<&Instance> {
        self.instances.iter().find(|i| i.id == id)
    }

    /// One coroutine by id, mutably. Used by the diagnostics harness to seed a
    /// coroutine's self variables before it runs (e.g. common event 189 reads SV28
    /// to size the CDataBase types).
    #[must_use]
    pub fn instance_mut(&mut self, id: InstanceId) -> Option<&mut Instance> {
        self.instances.iter_mut().find(|i| i.id == id)
    }

    /// Load an event into a fresh coroutine. Returns `None` when the id is unknown.
    pub fn start_event(&mut self, event: EventId) -> Option<InstanceId> {
        self.start_event_with(event, None)
    }

    /// Same, with a return target.
    pub fn start_event_with(
        &mut self,
        event: EventId,
        return_to: Option<i32>,
    ) -> Option<InstanceId> {
        let program = Arc::clone(self.programs.event(event)?);
        if self.instances.len() >= MAX_INSTANCES {
            return None;
        }
        let id = self.next_id;
        self.next_id += 1;
        let mut inst = Instance::new(id, None, program);
        inst.return_to = return_to;
        self.instances.push(inst);
        self.started_events.insert(event);
        self.started_event_total += 1;
        Some(id)
    }

    /// Load an already-compiled program into a fresh coroutine.
    ///
    /// Map-event pages are not common events, so they have no entry in
    /// [ProgramSet]; the caller compiles them with [Program::from_slots] and
    /// hands them over here. Everything downstream (blocks, waits, return
    /// values) behaves exactly as for a common event.
    pub fn start_program(&mut self, program: Arc<Program>) -> Option<InstanceId> {
        self.start_program_inner(program, None)
    }

    /// Start a map-event page with the self-variable bank its event carries.
    ///
    /// WOLF stores an event's self variables in the event, not in the coroutine
    /// that happens to be running its current page: they survive a page switch
    /// and a parallel page restarting at the end of its stream. The caller owns
    /// the bank and hands in the latest copy at every start; this instance is
    /// marked [Instance::retain_after_finish], so when the program ends the
    /// runtime can still read the final bank out before retiring it.
    pub fn start_program_with_self(
        &mut self,
        program: Arc<Program>,
        self_vars: SelfVars,
    ) -> Option<InstanceId> {
        self.start_program_inner(program, Some(self_vars))
    }

    fn start_program_inner(
        &mut self,
        program: Arc<Program>,
        self_vars: Option<SelfVars>,
    ) -> Option<InstanceId> {
        if self.instances.len() >= MAX_INSTANCES {
            return None;
        }
        let id = self.next_id;
        self.next_id += 1;
        let mut instance = Instance::new(id, None, program);
        if let Some(self_vars) = self_vars {
            instance.self_vars = self_vars;
            instance.retain_after_finish = true;
        }
        self.instances.push(instance);
        Some(id)
    }

    /// Stop one coroutine, and every coroutine it spawned, right now.
    ///
    /// A map event page owns exactly one coroutine, so switching pages has to
    /// retire the old one. Ending the program instead of removing the instance
    /// would keep it alive for the rest of the frame and, worse, would hand its
    /// return value to a parent that never asked for it. Waking the parent is
    /// this function's job: a caller waiting in [WaitState::Child] must not
    /// block forever on a coroutine that no longer exists.
    ///
    /// Returns true when the instance was found.
    pub fn stop_instance(&mut self, id: InstanceId) -> bool {
        if !self.instances.iter().any(|instance| instance.id == id) {
            return false;
        }
        // Descendants die with their ancestor: a child coroutine without its
        // caller has nobody left to return to.
        let mut doomed = vec![id];
        loop {
            let mut grew = false;
            for instance in &self.instances {
                if doomed.contains(&instance.id) {
                    continue;
                }
                let mut parent = instance.parent;
                while let Some(pid) = parent {
                    if doomed.contains(&pid) {
                        doomed.push(instance.id);
                        grew = true;
                        break;
                    }
                    parent = self
                        .instances
                        .iter()
                        .find(|other| other.id == pid)
                        .and_then(|other| other.parent);
                }
            }
            if !grew {
                break;
            }
        }
        // Wake anyone waiting on a doomed coroutine before it disappears.
        for index in 0..self.instances.len() {
            if let WaitState::Child(child) = self.instances[index].wait {
                if doomed.contains(&child) {
                    self.instances[index].wait = WaitState::None;
                }
            }
        }
        self.instances
            .retain(|instance| !doomed.contains(&instance.id));
        true
    }

    /// Load an event by title. Returns `None` when no title matches.
    pub fn start_event_by_name(&mut self, name: &str) -> Option<InstanceId> {
        let event = self.programs.id_by_name(name)?;
        self.start_event(event)
    }

    /// Advance every coroutine by one frame.
    pub fn step_frame(&mut self, host: &mut dyn Host) -> StepReport {
        self.frame += 1;
        let mut report = StepReport {
            frame: self.frame,
            ..StepReport::default()
        };
        let mut budget = self.budget;

        self.poll_waits(host);
        self.run_instances(host, &mut budget, &mut report);
        self.reap_finished(host);

        report.steps = self.budget - budget.min(self.budget);
        report.running = self.instances.len();
        report
    }

    /// Tick every wait state once, resolving the ones the host answered.
    fn poll_waits(&mut self, host: &mut dyn Host) {
        for i in 0..self.instances.len() {
            let wait = self.instances[i].wait.clone();
            match wait {
                WaitState::None | WaitState::Child(_) => {}
                WaitState::Frames(n) => {
                    self.instances[i].wait = if n <= 1 {
                        WaitState::None
                    } else {
                        WaitState::Frames(n - 1)
                    };
                }
                WaitState::Message => {
                    if host.message_dismissed() {
                        // The engine closes the window on the confirm key and drops
                        // system variable 12 (表示中) back to 0. Clearing the wait
                        // alone would leave the text on screen forever and keep
                        // ev63 convinced the window is still open.
                        host.close_message();
                        self.instances[i].wait = WaitState::None;
                    }
                }
                WaitState::Choice { block } => {
                    if let Some(reply) = host.choice_made() {
                        let inst = &mut self.instances[i];
                        let len = inst.program.len();
                        let target = match reply {
                            // 102's case ids are option index + 2 (docs/OPCODE_SPEC.md §4.2).
                            ChoiceReply::Index(index) => inst
                                .program
                                .blocks
                                .get(block)
                                .and_then(|b| b.case_target(index as i32 + 2))
                                .or_else(|| {
                                    inst.program.blocks.get(block).map(|b| b.end_target(len))
                                }),
                            ChoiceReply::Cancel => inst
                                .program
                                .blocks
                                .get(block)
                                .and_then(|b| b.cancel_pc)
                                .or_else(|| {
                                    inst.program.blocks.get(block).map(|b| b.end_target(len))
                                }),
                        };
                        if let Some(target) = target {
                            self.instances[i].pc = target;
                        }
                        self.instances[i].wait = WaitState::None;
                    }
                }
            }
        }
    }

    /// Run every runnable coroutine until the frame budget is gone.
    fn run_instances(&mut self, host: &mut dyn Host, budget: &mut usize, report: &mut StepReport) {
        let mut i = 0;
        while i < self.instances.len() {
            if !self.instances[i].is_runnable() {
                i += 1;
                continue;
            }
            if *budget == 0 {
                return;
            }
            let mut hist: Vec<(usize, u64)> = Vec::new();
            let result = {
                let inst = &mut self.instances[i];
                execute(
                    inst,
                    &self.programs,
                    &mut self.vars,
                    host,
                    budget,
                    &mut self.rng,
                    &mut self.input,
                    &mut self.transition,
                    self.hot_trace,
                    &mut hist,
                )
            };
            if self.hot_trace && !hist.is_empty() {
                let event = self.instances[i].event;
                hist.sort_by(|a, b| b.1.cmp(&a.1).then(a.0.cmp(&b.0)));
                for (pc, hits) in hist.iter().take(HOT_SPOTS) {
                    report.hottest.push(HotSpot {
                        event,
                        pc: *pc,
                        hits: *hits,
                    });
                }
            }
            report.steps += result.steps;
            match result.signal {
                Signal::Blocked | Signal::Continue => {}
                Signal::Finished => {
                    report.finished += 1;
                }
                Signal::Call {
                    target,
                    args,
                    strings,
                    return_to,
                } => {
                    self.spawn_child(i, target, args, strings, return_to, host, report);
                }
                Signal::CallByName {
                    name,
                    args,
                    strings,
                    return_to,
                } => match self.programs.id_by_name(&name) {
                    Some(target) => {
                        self.spawn_child(i, target, args, strings, return_to, host, report);
                    }
                    None => {
                        host.log(
                            LogLevel::Error,
                            &format!("300 CallByName: no event titled `{name}`"),
                        );
                        report.notes.push(format!("unknown event name: {name}"));
                        // Non-blocking by design: the original would show an empty
                        // dialogue and continue, which is what falling through does.
                        self.instances[i].wait = WaitState::None;
                    }
                },
                Signal::ReturnToTitle => {
                    host.return_to_title();
                    self.instances[i].wait = WaitState::None;
                    self.instances[i].pc = self.instances[i].program.len();
                }
                Signal::EndGame => {
                    host.end_game();
                    self.instances.clear();
                    return;
                }
                Signal::Error(message) => {
                    host.log(LogLevel::Error, &message);
                    report.notes.push(message);
                    // A data error must not wedge the instance forever.
                    self.instances[i].pc += 1;
                }
            }
            i += 1;
        }
    }

    /// Create the child coroutine of a `210`/`300` and block the caller.
    fn spawn_child(
        &mut self,
        caller: usize,
        target: EventId,
        args: Vec<i32>,
        strings: Vec<String>,
        return_to: Option<i32>,
        host: &mut dyn Host,
        report: &mut StepReport,
    ) {
        let Some(program) = self.programs.event(target).map(Arc::clone) else {
            host.log(
                LogLevel::Error,
                &format!("210 CallCommonEvent: no event with id {target}"),
            );
            report
                .notes
                .push(format!("unknown common event id {target}"));
            return;
        };
        if self.instances.len() >= MAX_INSTANCES {
            host.log(LogLevel::Error, "instance limit reached; call dropped");
            return;
        }
        let id = self.next_id;
        self.next_id += 1;
        let mut child = Instance::new(id, Some(self.instances[caller].id), program);
        // Arguments land in self variable group 6 (magic 1_600_000 + i), not in
        // group 0 - see magic::SELF_ARG_BASE for the measurement. Getting this
        // wrong is invisible on the title screen but wedges every story script
        // that uses a progress bar or a mode switch.
        for (slot, value) in args.iter().enumerate() {
            child
                .self_vars
                .set(crate::magic::SELF_ARG_BASE + slot, *value);
        }
        // String arguments go to CSelf5..8 (magic 1_600_005 + k), mirroring the
        // editor's four numeric and four string input boxes
        // (docs/OPCODE_210_RETURN.md section 8). 8,229 of the 8,260 call sites
        // that pass a string have a callee that reads 1_600_005, so dropping
        // them leaves every message window blank.
        for (slot, text) in strings.iter().take(SELF_ARG_STRING_SLOTS).enumerate() {
            child.self_vars.set_str(SELF_ARG_STRING_BASE + slot, text);
        }
        child.return_to = return_to;
        self.instances.push(child);
        self.instances[caller].wait = WaitState::Child(id);
    }

    /// Drop ended coroutines and hand their return values to the parents.
    fn reap_finished(&mut self, host: &mut dyn Host) {
        // A coroutine parked on `WaitState::Child` is *not* finished even when its
        // pc already points past the last slot: a 210 as the final instruction of
        // an event leaves pc == len while the child still has to deliver the
        // return value, and reaping the parent first would drop it on the floor
        // (the child then finds no waiting parent). Children are reaped before
        // their parents because a blocked parent is skipped here.
        let finished: Vec<InstanceId> = self
            .instances
            .iter()
            .filter(|i| {
                i.pc >= i.program.len() && i.wait == WaitState::None && !i.retain_after_finish
            })
            .map(|i| i.id)
            .collect();
        if finished.is_empty() {
            return;
        }
        for id in &finished {
            let Some(pos) = self.instances.iter().position(|i| i.id == *id) else {
                continue;
            };
            let mut inst = self.instances.remove(pos);
            let parent = inst.parent.and_then(|pid| {
                let idx = self.instances.iter().position(|i| i.id == pid)?;
                if self.instances[idx].wait == WaitState::Child(inst.id) {
                    Some(idx)
                } else {
                    None
                }
            });
            match parent {
                Some(idx) => {
                    // The child's return value lives in the self slot the event
                    // declared, and the caller named the destination in the
                    // trailing operand of its 210/300. That operand is stored on
                    // the *child* (V[child].return_to) because it describes the
                    // value the child produces; it is written into the parent's
                    // variable namespace here, once the child has ended
                    // (docs/OPCODE_210_RETURN.md §2.2).
                    if let Some(target) = inst.return_to.take() {
                        if let Some(slot) = return_slot(&inst.program) {
                            let value = inst.self_vars.get(slot);
                            store_num(&mut self.instances[idx], &mut self.vars, target, value);
                        }
                    }
                    self.instances[idx].wait = WaitState::None;
                }
                None => {
                    if inst.parent.is_some() {
                        host.log(
                            LogLevel::Warn,
                            &format!("coroutine {} ended with no waiting parent", inst.id),
                        );
                    }
                }
            }
        }
    }
}

/// The self-variable slot a common event returns its value through.
///
/// The declaration is a bare slot number inside self group 6, the call-frame
/// bank the arguments are delivered to, so the address is `1_600_000 + id`
/// (docs/OPCODE_210_RETURN.md §3).
///
/// `None` when the event declares no return value (`0xFFFF_FFFF`): eight call
/// sites in this game do ask such an event for a value, but the callee never
/// writes the slot either, so copying it would only push a stale value into the
/// caller's variable (docs/OPCODE_210_RETURN.md §4).
fn return_slot(program: &Program) -> Option<usize> {
    if program.return_value_id == NO_RETURN_VALUE {
        return None;
    }
    let slot = Magic::decode(1_600_000i32.wrapping_add(program.return_value_id as i32));
    Some(slot.index() as usize)
}

/// Read one magic operand.
fn eval_num(raw: i32, inst: &Instance, vars: &Variables) -> i32 {
    let magic = Magic::decode(raw);
    match magic.kind() {
        MagicKind::Literal => magic.index() as i32,
        MagicKind::SelfVar => inst.self_vars.get(magic.index() as usize),
        MagicKind::Var => vars.get(magic.index() as usize),
        MagicKind::SysVar => vars.get_sys(magic.index() as usize),
        // A string bank read as a number is 0 (the editor never does this).
        MagicKind::StrVar => 0,
        // Database cells need a host to read; callers that can resolve them use
        // `eval_num_host`.  Keeping the raw value is the least surprising
        // fallback for the few generic call sites that never see this bank.
        MagicKind::DbCell => raw,
        // "Opaque" is not a bank at all: it is the negative-sentinel space
        // (-1 keep, -2 whole screen, -1_000_000 unchanged) plus anything above
        // the system bank. Those values are literals and must survive, otherwise
        // picture -2 collapses to 0 and the full-screen layer is lost
        // (docs/M1_CLOSURE.md Q3).
        MagicKind::Opaque => raw,
    }
}

/// Read one `250` address operand (type / row / column) as a number.
///
/// All three are ordinary magic operands, and the hottest cells of this game are
/// addressed through self variables (docs/OPCODE_250.md section 0.1 item 3). A
/// literal passes through unchanged and a negative sentinel such as `-1` keeps its
/// sign, because [`eval_num`] treats both as opaque values rather than banks.
///
/// A string-bank operand (the `3_000_000` range) reads as 0 here; that form does
/// not occur on any of the 2,663 address operands (docs/OPCODE_250.md section 2).
fn eval_address(raw: i32, inst: &Instance, vars: &Variables) -> i32 {
    eval_num(raw, inst, vars)
}

/// Read a database-value magic operand from the host, if it is one.
fn database_value(raw: i32, host: &mut dyn Host) -> Option<i32> {
    let magic = Magic::decode(raw);
    if magic.kind() != MagicKind::DbCell {
        return None;
    }
    // Every database-value operand measured in this title is CDataBase type 0
    // (可変DB[0]); the magic carries only row and column.
    host.database_cell(DbContainer::CData, 0, magic.db_row(), magic.db_column())
}

/// Read one magic operand, resolving database cells through the host.
fn eval_num_host(raw: i32, inst: &Instance, vars: &Variables, host: &mut dyn Host) -> i32 {
    database_value(raw, host).unwrap_or_else(|| eval_num(raw, inst, vars))
}

/// One of the label strings a `250` carries, when it is non-empty.
///
/// `stringArgs[1]` is the editor's type name and `stringArgs[3]` its column name;
/// both are the most reliable keys for resolving a runtime type id or column
/// number (docs/OPCODE_250.md sections 4 and 6).
fn label(cmd: &wolf_format::command::Command, index: usize) -> Option<String> {
    cmd.strings
        .get(index)
        .filter(|text| !text.is_empty())
        .cloned()
}

/// Read one magic operand as a string.
fn eval_str(raw: i32, inst: &Instance, vars: &Variables) -> String {
    let magic = Magic::decode(raw);
    match magic.kind() {
        MagicKind::StrVar => vars.get_str(magic.index() as usize).to_owned(),
        MagicKind::SelfVar => inst.self_vars.get_str(magic.index() as usize).to_owned(),
        MagicKind::SysVar => vars.get_sys_str(magic.index() as usize).to_owned(),
        // A numeric bank read as text yields the decimal form, which is what the
        // editor's `cself[n]` expansion does.
        MagicKind::Literal => magic.index().to_string(),
        MagicKind::Var => vars.get(magic.index() as usize).to_string(),
        MagicKind::DbCell | MagicKind::Opaque => String::new(),
    }
}

/// Write one magic operand.
fn store_num(inst: &mut Instance, vars: &mut Variables, raw: i32, value: i32) {
    let magic = Magic::decode(raw);
    match magic.kind() {
        MagicKind::SelfVar => inst.self_vars.set(magic.index() as usize, value),
        MagicKind::Var => vars.set(magic.index() as usize, value),
        MagicKind::SysVar => vars.set_sys(magic.index() as usize, value),
        // Writing to a literal or a sentinel is a no-op in every WOLF build.
        MagicKind::Literal | MagicKind::StrVar | MagicKind::DbCell | MagicKind::Opaque => {}
    }
}

/// Write one magic operand as a string.
fn store_str(inst: &mut Instance, vars: &mut Variables, raw: i32, value: &str) {
    let magic = Magic::decode(raw);
    match magic.kind() {
        MagicKind::StrVar => vars.set_str(magic.index() as usize, value),
        MagicKind::SelfVar => inst.self_vars.set_str(magic.index() as usize, value),
        MagicKind::SysVar => vars.set_sys_str(magic.index() as usize, value),
        MagicKind::Literal | MagicKind::Var | MagicKind::DbCell | MagicKind::Opaque => {}
    }
}

/// Expand escapes in a string using the instance and the globals.
fn expand(raw: &str, inst: &Instance, vars: &Variables) -> String {
    let lookup = Lookup { inst, vars };
    text::expand(raw, &lookup)
}

/// Split the `@n` speaker prefix off a message (docs/OPCODE_SPEC.md §5.3).
fn split_face(text: &str) -> (Option<i32>, &str) {
    let bytes = text.as_bytes();
    if bytes.first() == Some(&b'@') {
        if let Some(digit) = bytes.get(1) {
            if digit.is_ascii_digit() {
                let face = i32::from(digit - b'0');
                return (Some(face), text.get(2..).unwrap_or(""));
            }
        }
    }
    (None, text)
}

/// Binary operators for `121`, docs/OPCODE_SPEC.md §3.2.
///
/// WolfTL's comment table swaps two of these: it lists `0x3000` as modulo and
/// `0x4000` as bitwise NOT, but WolfTL never decodes the operator itself, so
/// nothing ever checked the table. The data does:
///
/// * `0x3` is division. CE48 pc30 computes `Sys116 / 32` where Sys116 is the
///   1024 px screen width and the result has to be the coordinate scale 32;
///   `1024 % 32` would be 0 and every window would collapse to nothing.
///   CE63 pc46 divides the vertical scale by 10 to get the 2 px nudge that
///   makes Sys2 = 410 instead of 408. Operators `0x3` occur 438 times here.
/// * `0x4` is modulo. CE48 pc172 does `self20 %= 10000` and then adds 20000
///   to re-pack an item id, CE86 pc44 does the same before branching on
///   `> 19999 / > 29999`. `~` with an operand of 10000 is meaningless.
///   107 sites.
fn binary_op(kind: u8, a: i32, b: i32) -> i32 {
    match kind {
        0x0 => a.wrapping_add(b),
        0x1 => a.wrapping_sub(b),
        0x2 => a.wrapping_mul(b),
        0x3 => {
            if b == 0 {
                a
            } else {
                a.wrapping_div(b)
            }
        }
        0x4 => {
            if b == 0 {
                a
            } else {
                a.wrapping_rem(b)
            }
        }
        0x5 => a & b,
        // 0x6 never reaches here: the 121 arm routes it to rng.range first
        // (1,101 sites, docs/OPCODE_SPEC.md §3.2). Kept so the table is total.
        0x6 => a.wrapping_shr((b & 31) as u32),
        0x7 => a | b,
        0x8 => a ^ b,
        0x9 => a.wrapping_shl((b & 31) as u32),
        _ => a,
    }
}

/// Compound assignment / unary transforms for `121`, docs/OPCODE_SPEC.md §3.1.
fn compound(kind: i32, current: i32, value: i32) -> i32 {
    // Only bits 8..11 select the operation (WolfTL Command.hpp:36-49). 194 of the
    // 17,258 121 instructions also set bits 0..7 (0x104, 0x3302, 0x4 ...), which
    // the editor uses as flags we have not identified; masking them off keeps the
    // documented operation intact instead of falling through to "assign".
    match kind & 0x0F00 {
        0x000 => value,
        0x100 => current.wrapping_add(value),
        0x200 => current.wrapping_sub(value),
        0x300 => current.wrapping_mul(value),
        0x400 => {
            if value == 0 {
                current
            } else {
                current / value
            }
        }
        0x500 => {
            if value == 0 {
                current
            } else {
                current % value
            }
        }
        0x600 => value,
        0x700 => value,
        0x800 => value.abs(),
        0x900 => {
            // Angle from slope, in tenths of a degree.
            let deg = (value as f64).atan2(current as f64).to_degrees();
            (deg * 10.0) as i32
        }
        0xA00 => {
            let deg = (value as f64) / 10.0;
            (deg.to_radians().sin() * 1000.0) as i32
        }
        0xB00 => {
            let deg = (value as f64) / 10.0;
            (deg.to_radians().cos() * 1000.0) as i32
        }
        0xC00 => {
            let root = (value.max(0) as f64).sqrt();
            (root * 1000.0) as i32
        }
        _ => value,
    }
}

/// `111` comparison operators, docs/OPCODE_SPEC.md §3.3.
fn compare(lhs: i32, rhs: i32, operator: i32) -> bool {
    match operator {
        0 => lhs > rhs,
        1 => lhs >= rhs,
        2 => lhs == rhs,
        3 => lhs <= rhs,
        4 => lhs < rhs,
        5 => lhs != rhs,
        6 => (lhs & rhs) != 0,
        // 17/18/19 occur 44x and are undocumented; equality is the least
        // surprising reading and matches the single-condition branches they
        // appear in.
        _ => lhs == rhs,
    }
}

/// Execute one coroutine until it blocks, ends, or the budget runs out.
fn execute(
    inst: &mut Instance,
    _programs: &ProgramSet,
    vars: &mut Variables,
    host: &mut dyn Host,
    budget: &mut usize,
    rng: &mut WolfRng,
    input: &mut InputState,
    transition: &mut TransitionState,
    hot: bool,
    hist: &mut Vec<(usize, u64)>,
) -> BlockResult {
    // Holds the jump table and the instruction stream. Cloning the Arc (not the
    // Program) keeps the `&Command` borrow pointing at this local instead of at
    // `inst`, which the loop mutates on almost every arm.
    let program = Arc::clone(&inst.program);
    let mut steps = 0;
    loop {
        if inst.pc >= program.len() {
            return BlockResult {
                signal: Signal::Finished,
                steps,
            };
        }
        if *budget == 0 {
            return BlockResult {
                signal: Signal::Continue,
                steps,
            };
        }
        *budget -= 1;
        steps += 1;
        if hot {
            match hist.iter_mut().find(|entry| entry.0 == inst.pc) {
                Some(entry) => entry.1 += 1,
                None => hist.push((inst.pc, 1)),
            }
        }

        let pc = inst.pc;
        let Slot::Command(cmd) = &program.slots[pc] else {
            inst.pc += 1;
            continue;
        };
        let opcode = cmd.opcode;

        // Control flow first: these need the jump table, everything else does not.
        match program.control.get(pc).copied().unwrap_or(Control::None) {
            Control::Block(block) => {
                if let Some(result) = enter_block(inst, &program, vars, host, cmd, block, steps) {
                    return result;
                }
                continue;
            }
            Control::Case { block } => {
                // Reaching a case marker *by executing it* always means control
                // fell through the previous case body into the next marker, and
                // in WOLF that ends the branch: every 401 body runs from its
                // marker to the next 401 (or the closing 499) and must not leak
                // into the following case. Case *entry* never lands here -- it is
                // done by enter_block() / poll_waits() through case_target(),
                // which resume one slot PAST the marker. Getting this wrong makes
                // the title menu run every option at once (docs/M1_CLOSURE.md Q1).
                let block = &program.blocks[block];
                inst.pc = block.end_target(program.len());
                continue;
            }
            Control::LoopEnd { block } => {
                close_loop(inst, block);
                continue;
            }
            Control::LabelJump => {
                let name = expand(cmd.strings.first().map_or("", String::as_str), inst, vars);
                match program.labels.get(&name) {
                    Some(target) => inst.pc = *target,
                    None => {
                        host.log(
                            LogLevel::Warn,
                            &format!("213 JumpLabel: label `{name}` not found; skipping event"),
                        );
                        inst.pc = program.len();
                    }
                }
                continue;
            }
            Control::None => {}
        }

        let signal = match opcode {
            0 => {
                inst.pc += 1;
                None
            }
            99 => {
                // Exclusive branch start marker; nothing to do.
                inst.pc += 1;
                None
            }
            101 => {
                let raw = cmd.strings.first().map_or("", String::as_str);
                let expanded = expand(raw, inst, vars);
                let (face, text) = split_face(&expanded);
                // `@n` is the per-message face override; the message-window coroutine
                // (common event 63) reads Sys0 to pick the face picture, so publish it
                // before the host sees the text (docs/OPCODE_101.md section 4.2).
                if let Some(face) = face {
                    vars.set_sys(0, face);
                }
                host.show_message(text, face);
                inst.wait = WaitState::Message;
                inst.pc += 1;
                Some(Signal::Blocked)
            }
            102 => {
                let options: Vec<String> = cmd
                    .strings
                    .iter()
                    .map(|option| expand(option, inst, vars))
                    .collect();
                let block = match program.control.get(pc) {
                    Some(Control::Block(index)) => *index,
                    _ => 0,
                };
                host.show_choices(&options);
                inst.wait = WaitState::Choice { block };
                inst.pc += 1;
                Some(Signal::Blocked)
            }
            103 => {
                // Comment marker, 9,707 of them in this data.
                inst.pc += 1;
                None
            }
            104 => {
                // One site in the whole corpus (CE341 pc615) with argc 0. WolfTL's
                // CommandType has no 104, docs/OPCODE_SPEC.md section 5.5 leaves it
                // unconfirmed, and an empty-argument command cannot have a side effect
                // we could observe, so it is a no-op until a second site appears.
                inst.pc += 1;
                None
            }
            105 => {
                host.close_message();
                inst.pc += 1;
                None
            }
            106 => {
                let text = expand(cmd.strings.first().map_or("", String::as_str), inst, vars);
                host.debug_message(&text);
                inst.pc += 1;
                None
            }
            107 => {
                host.clear_debug();
                inst.pc += 1;
                None
            }
            111 => {
                // Handled through Control::Block; kept for the no-table fallback.
                inst.pc += 1;
                None
            }
            112 => {
                inst.pc = eval_string_condition(inst, vars, cmd);
                None
            }
            121 => {
                let target = arg(cmd, 0);
                let a = eval_num(arg(cmd, 1), inst, vars);
                let b = eval_num(arg(cmd, 2), inst, vars);
                let bits = arg(cmd, 3) as u32;
                let bin = ((bits >> 12) & 0x0F) as u8;
                // 0x6000 is a random range: docs/OPCODE_SPEC.md §3.2 calls it
                // undefined in WolfTL, but 1,101 call sites pass (min, max) pairs
                // that only make sense as rand(min, max) — see rng.rs.
                let result = if bin == 6 {
                    rng.range(a, b)
                } else {
                    binary_op(bin, a, b)
                };
                // A database-value target is written as `[base, value, bin,
                // bits, type, row, column]`: the base alone is not the cell, so
                // the row and column are the trailing operands.  CE242 pc17 uses
                // `[1_100_000_000, 99, 0, 0, 0, 12, 9]` to set the action maximum,
                // and CE259/CE284/CE298 write stamina/action the same way.
                if target == crate::magic::DB_VALUE_BASE && argc(cmd) >= 7 {
                    let db_type = eval_num(arg(cmd, 4), inst, vars);
                    let row = eval_num(arg(cmd, 5), inst, vars);
                    let column = eval_num(arg(cmd, 6), inst, vars);
                    let current = host
                        .database_cell(DbContainer::CData, db_type, row, column)
                        .unwrap_or(0);
                    let value = compound((bits & 0x0FFF) as i32, current, result);
                    host.set_database_cell(DbContainer::CData, db_type, row, column, value);
                    inst.pc += 1;
                    None
                } else {
                    let current = eval_num_host(target, inst, vars, host);
                    let value = compound((bits & 0x0FFF) as i32, current, result);
                    if Magic::decode(target).kind() == MagicKind::DbCell {
                        let magic = Magic::decode(target);
                        host.set_database_cell(
                            DbContainer::CData,
                            0,
                            magic.db_row(),
                            magic.db_column(),
                            value,
                        );
                    } else {
                        store_num(inst, vars, target, value);
                    }
                    inst.pc += 1;
                    None
                }
            }
            122 => {
                let target = arg(cmd, 0);
                let value = cmd
                    .strings
                    .first()
                    .map_or(String::new(), |raw| expand(raw, inst, vars));
                store_str(inst, vars, target, &value);
                inst.pc += 1;
                None
            }
            123 => {
                // Key-input poll (docs/OPCODE_SPEC.md 5.13). The destination receives
                // the CODE of the held key, not a bit pattern - the game compares it
                // against 10/11/12 and the numpad direction codes, which is why the
                // old "key_bits & mask" model could never take a branch. A headless
                // host reports 0, exactly like an untouched keyboard.
                let target = arg(cmd, 0);
                // A key the script banned with 126 must read as not pressed; a key
                // it asked for with 125 is handed to the host, which owns the keyboard.
                let mask = arg(cmd, 1) as u32 & !input.ban_keys;
                store_num(
                    inst,
                    vars,
                    target,
                    host.key_code_auto(mask, input.auto_keys),
                );
                inst.pc += 1;
                None
            }
            124 => {
                // 124 SetVariableEx (``変数操作（拡張）``; WolfTL Command.hpp:112) is a pure
                // query: pick a value out of the engine state and store it. It never
                // blocks and never touches the block stack (docs/OPCODE_124.md §0).
                //
                // Shape: argc 4 = [dst, sub, object, field], argc 3 = [dst, sub, field]
                // (only 0x3000 appears in the short form, 278/278 in this game). The
                // object operand is a normal magic value - a picture number can be
                // 5 digits or a variable reference - so it goes through eval_num.
                let target = arg(cmd, 0);
                let sub = arg(cmd, 1);
                let field = if argc(cmd) >= 4 {
                    arg(cmd, 3)
                } else {
                    arg(cmd, 2)
                };
                let value = match sub {
                    0x3000 => {
                        // field 18 is "the event being processed", which only the
                        // interpreter knows; common events report id + 500000.
                        if field == 18 {
                            Some(inst.event as i32 + 500_000)
                        } else {
                            host.engine_state(field)
                        }
                    }
                    0x1000 | 0x1200 => {
                        let object = if argc(cmd) >= 4 {
                            eval_num(arg(cmd, 2), inst, vars)
                        } else {
                            0
                        };
                        host.character_state(object, field)
                    }
                    0x4000 | 0x4400 => {
                        let object = if argc(cmd) >= 4 {
                            eval_num(arg(cmd, 2), inst, vars)
                        } else {
                            0
                        };
                        host.picture_state(object, field)
                    }
                    other => {
                        host.log(
                            LogLevel::Info,
                            &format!("124 SetVariableEx: sub-op {other:#x} unused in this game"),
                        );
                        None
                    }
                };
                // `None` deliberately leaves the destination alone: the original engine does
                // not write anything when the queried object does not exist (§3.1).
                if let Some(value) = value {
                    store_num(inst, vars, target, value);
                }
                inst.pc += 1;
                None
            }
            125 => {
                // Auto input: remember the mask. Only the host can force a press,
                // because it owns the real keyboard.
                input.auto_keys = arg(cmd, 0) as u32;
                inst.pc += 1;
                None
            }
            126 => {
                // Ban input: every later 123 poll has these bits cleared.
                input.ban_keys = arg(cmd, 0) as u32;
                inst.pc += 1;
                None
            }
            130 => {
                // Raw layout is target, x, y, map, options - not map-first.
                host.teleport(
                    arg(cmd, 0),
                    arg(cmd, 3),
                    arg(cmd, 1),
                    arg(cmd, 2),
                    arg(cmd, 4),
                );
                // The map load is instant in the original; one frame of slack
                // keeps the host from having to re-enter the interpreter.
                inst.wait = WaitState::Frames(1);
                inst.pc += 1;
                Some(Signal::Blocked)
            }
            140 => {
                // Raw layout (wolfrpg-map-parser 0.4.1 sound_command):
                //   [0] = options/system-db/type word
                //   [1] = fade time (BGM/BGS) or delay (SE)
                //   [2] = variable, [3] = start time
                //   [4] = volume, [5] = tempo, [6] = loop point (BGM/BGS only)
                // Old code mistook [1] for the volume, which silenced every track whose
                // fade time was 0 and rendered 10 as 10%. The retail data's [4] values
                // are the sane 0..100 (200 for the loud SE), so read [4] here.
                let bits = arg(cmd, 0);
                let channel = if bits & 0x20 != 0 {
                    SoundChannel::Se
                } else {
                    SoundChannel::Bgm
                };
                let playing = bits >= 0 && bits & 0x0200_0000 != 0;
                let (action, file, volume, frames) = if playing {
                    let file = expand(cmd.strings.first().map_or("", String::as_str), inst, vars);
                    let volume = if argc(cmd) >= 6 { arg(cmd, 4) } else { 100 };
                    // For BGM this is the fade-in length; SE treats the same slot as a
                    // start delay. The mixer currently only uses frames when stopping,
                    // but keeping it here preserves the field instead of dropping it.
                    let frames = if argc(cmd) >= 6 {
                        arg(cmd, 1).max(0)
                    } else {
                        0
                    };
                    (SoundAction::Play, file, volume, frames)
                } else {
                    let frames = if argc(cmd) <= 5 { arg(cmd, 1) } else { 0 };
                    (SoundAction::Stop, String::new(), 0, frames)
                };
                host.sound(&SoundCmd {
                    channel,
                    action,
                    file,
                    volume,
                    frames,
                });
                inst.pc += 1;
                None
            }
            150 => {
                host.picture(&decode_picture(inst, vars, cmd));
                inst.pc += 1;
                None
            }
            151 => {
                host.change_color(arg(cmd, 0), arg(cmd, 1));
                inst.pc += 1;
                None
            }
            160 => {
                // 160 installs the setting; it does not block and draws nothing.
                // CE48 starts every game with [-1, 0x0001_000A]: simple cut, wait,
                // 10 frames (docs/OPCODE_SPEC.md section 5.20).
                transition.kind = arg(cmd, 0);
                transition.flags = arg(cmd, 1);
                host.transition(transition.kind, transition.flags);
                inst.pc += 1;
                None
            }
            161 => {
                // PrepareTransition freezes the drawn screen while event
                // processing continues. The host owns the actual freeze.
                transition.prepared = true;
                host.transition(transition.kind, transition.flags);
                inst.pc += 1;
                None
            }
            162 => {
                // ExecuteTransition resumes drawing and blocks until the
                // configured animation has run. The old one-frame wait ignored
                // the 10-frame default, which would cut every SampleMapB
                // transition ten times too short.
                transition.prepared = false;
                let frames = transition.frames();
                host.transition(transition.kind, transition.flags);
                inst.wait = WaitState::Frames(frames);
                inst.pc += 1;
                Some(Signal::Blocked)
            }
            170 | 176 => {
                // Unconditional loop heads. Control::Block pushed nothing yet:
                // enter_block handles the push, so reaching here means the jump
                // table was not built (a hand-made Program). Treat as fallthrough.
                inst.pc += 1;
                None
            }
            171 => {
                // Break the innermost loop: continue after its 498.
                if let Some(ctx) = inst.loops.pop() {
                    let block = &program.blocks[ctx.block];
                    inst.pc = block.end_target(program.len());
                } else {
                    host.log(LogLevel::Warn, "171 BreakLoop outside any loop");
                    inst.pc += 1;
                }
                None
            }
            172 | 173 => {
                // Both end the coroutine; retiring the pc is what tells the
                // scheduler the instance is done.
                inst.pc = program.len();
                Some(Signal::Finished)
            }
            174 => Some(Signal::ReturnToTitle),
            175 => Some(Signal::EndGame),
            179 => {
                inst.pc += 1;
                None
            }
            180 => {
                let frames = eval_num(arg(cmd, 0), inst, vars).max(1) as u32;
                inst.wait = WaitState::Frames(frames);
                inst.pc += 1;
                Some(Signal::Blocked)
            }
            201 => {
                let target = arg(cmd, 0);
                if let Tail::MoveRoute(route) = &cmd.tail {
                    host.move_route(target, &route.commands);
                }
                inst.pc += 1;
                None
            }
            210 => {
                let mut raw = arg(cmd, 0);
                if Magic::decode(raw).is_storage() {
                    raw = eval_num(raw, inst, vars);
                }
                let target = match raw {
                    500_000..=599_999 => Some((raw - 500_000) as EventId),
                    600_000..=699_999 => Some((raw - 600_000) as EventId),
                    _ => None,
                };
                let Some(target) = target else {
                    host.log(
                        LogLevel::Error,
                        &format!("210 CallCommonEvent: unsupported target {raw}"),
                    );
                    inst.pc += 1;
                    return BlockResult {
                        signal: Signal::Continue,
                        steps,
                    };
                };
                let (args, strings, return_to) = call_arguments(cmd, inst, vars);
                inst.pc += 1;
                Some(Signal::Call {
                    target,
                    args,
                    strings,
                    return_to,
                })
            }
            211 => {
                let mut raw = arg(cmd, 0);
                if Magic::decode(raw).is_storage() {
                    raw = eval_num(raw, inst, vars);
                }
                let target = match raw {
                    500_000..=599_999 => (raw - 500_000) as EventId,
                    600_000..=699_999 => (raw - 600_000) as EventId,
                    _ => raw.max(0) as EventId,
                };
                host.reserve(target);
                inst.pc += 1;
                None
            }
            212 => {
                inst.pc += 1;
                None
            }
            213 => {
                inst.pc += 1;
                None
            }
            220..=222 => {
                // The file operand is the one place where the magic *type*
                // matters: a string variable holds an explicit path while a
                // numeric variable holds a slot number (docs/OPCODE_220_SAVE.md
                // section 2.1). All other operands stay raw where they are
                // addresses (221 arg0, 221/222 arg2) and are evaluated where they
                // are values (220 mode, 222 source, the trailing flag).
                let file_raw = arg(cmd, 1);
                let file = if matches!(Magic::decode(file_raw).kind(), MagicKind::StrVar) {
                    SaveTarget::Path(eval_str(file_raw, inst, vars))
                } else {
                    SaveTarget::Slot(eval_num(file_raw, inst, vars))
                };
                let opcode = cmd.opcode;
                let op = SaveOp {
                    opcode: opcode as u8,
                    mode: if opcode == 220 {
                        eval_num(arg(cmd, 0), inst, vars)
                    } else {
                        0
                    },
                    file,
                    destination: if opcode == 221 { arg(cmd, 0) } else { 0 },
                    address: if opcode == 220 { 0 } else { arg(cmd, 2) },
                    value: if opcode == 222 {
                        eval_num(arg(cmd, 0), inst, vars)
                    } else {
                        0
                    },
                    flag: if argc(cmd) >= 4 {
                        eval_num(arg(cmd, 3), inst, vars)
                    } else {
                        0
                    },
                    owner: inst.program.id,
                };
                if let Some(value) = host.save_load(&op) {
                    store_num(inst, vars, op.destination, value);
                }
                inst.pc += 1;
                None
            }
            250 => {
                // 250 DatabaseAccess addresses one cell of one of the three
                // databases. Everything about the address lives in the flags word
                // (docs/OPCODE_250.md section 3):
                //   bits 8..9 (0x300)  container: 0 CDataBase, 1 SysDatabase, 2 DataBase
                //   bit 12 (0x1000)    direction: 1 read (cell -> variable), 0 write
                //   bits 4..6 (0x70)   cell arithmetic: 0 assign .. 7 min
                // Bits 16..18 are editor bookkeeping (they only record which of the
                // three label strings is non-empty) and carry no runtime meaning.
                let flags = arg(cmd, 3);
                let container = DbContainer::from_flags(flags);
                let direction = DbDirection::from_flags(flags);
                let op = ((flags >> 4) & 7) as u8;
                let type_label = label(cmd, 1);
                let field_label = label(cmd, 3);
                // The type, the row and the column are all magic operands: the
                // hottest cells in this game are read through self variables
                // (docs/OPCODE_250.md section 0.1 item 3).
                let db_type = eval_address(arg(cmd, 0), inst, vars);
                let data_id = eval_address(arg(cmd, 1), inst, vars);
                let item_id = eval_address(arg(cmd, 2), inst, vars);
                // The 16 argc-4 sites have no value operand at all: the value is the
                // first string (docs/OPCODE_250.md section 1.3).
                let (destination, source) = match direction {
                    DbDirection::Read if argc(cmd) >= 5 => (Some(arg(cmd, 4)), None),
                    DbDirection::Read => (None, None),
                    DbDirection::Write if argc(cmd) >= 5 => {
                        (None, Some(DbValue::Num(eval_num(arg(cmd, 4), inst, vars))))
                    }
                    DbDirection::Write => (
                        None,
                        Some(DbValue::Str(
                            cmd.strings
                                .first()
                                .map_or(String::new(), |raw| expand(raw, inst, vars)),
                        )),
                    ),
                };
                let answer = host.database(&DbOp {
                    container,
                    direction,
                    op,
                    db_type,
                    data_id,
                    item_id,
                    flags,
                    destination,
                    source,
                    type_label,
                    field_label,
                });
                // A write must never touch a variable: its fifth operand is the
                // source value, not a destination (docs/OPCODE_250.md section 0.1).
                if let (DbDirection::Read, Some(answer), Some(target)) =
                    (direction, answer, destination)
                {
                    match answer {
                        DbValue::Num(value) => store_num(inst, vars, target, value),
                        DbValue::Str(text) => store_str(inst, vars, target, &text),
                    }
                }
                inst.pc += 1;
                None
            }
            270 => {
                let args: Vec<i32> = (0..argc(cmd)).map(|i| arg(cmd, i)).collect();
                host.party(&args);
                inst.pc += 1;
                None
            }
            281 => {
                let args: Vec<i32> = (0..argc(cmd)).map(|i| arg(cmd, i)).collect();
                host.scroll(&args);
                inst.pc += 1;
                None
            }
            290 => {
                // Every operand is a magic number, not a constant: the balloon library and
                // the HUD both pass self variables as picture ids. Evaluating only the
                // type/duration left those ids pointing at unrelated slots.
                let args: Vec<i32> = (0..argc(cmd))
                    .map(|i| eval_num(arg(cmd, i), inst, vars))
                    .collect();
                let kind = args.first().copied().unwrap_or(0) >> 4;
                let duration = args.get(1).copied().unwrap_or(0);
                host.effect(kind, duration, &args);
                inst.pc += 1;
                None
            }
            300 => {
                let name = expand(cmd.strings.first().map_or("", String::as_str), inst, vars);
                let (args, strings, return_to) = call_arguments(cmd, inst, vars);
                inst.pc += 1;
                Some(Signal::CallByName {
                    name,
                    args,
                    strings,
                    return_to,
                })
            }
            401 | 402 => {
                // Only reachable when the jump table was not built.
                inst.pc += 1;
                None
            }
            420 | 421 => {
                inst.pc += 1;
                None
            }
            498 => {
                inst.pc += 1;
                None
            }
            499 => {
                inst.pc += 1;
                None
            }
            1000 => {
                let kind = arg(cmd, 0) >> 16;
                let milliseconds = arg(cmd, 1);
                host.pro_feature(kind, milliseconds);
                if kind == 5 {
                    inst.wait = WaitState::Frames((milliseconds / 16).max(1) as u32);
                    inst.pc += 1;
                    Some(Signal::Blocked)
                } else {
                    inst.pc += 1;
                    None
                }
            }
            other => {
                host.log(
                    LogLevel::Warn,
                    &format!("unhandled opcode {other} at pc {pc}"),
                );
                inst.pc += 1;
                None
            }
        };

        if let Some(signal) = signal {
            return BlockResult { signal, steps };
        }
    }
}

/// Handle a `111`/`102`/loop head, which needs its block's case table.
fn enter_block(
    inst: &mut Instance,
    program: &Program,
    vars: &mut Variables,
    host: &mut dyn Host,
    cmd: &Command,
    block_index: usize,
    steps: usize,
) -> Option<BlockResult> {
    let block = program.blocks[block_index].clone();
    let len = program.len();
    match block.kind {
        BlockKind::Loop => {
            let remaining = if cmd.opcode == 179 {
                let count = eval_num(arg(cmd, 0), inst, vars);
                if count <= 0 {
                    inst.pc = block.end_target(len);
                    return None;
                }
                i64::from(count)
            } else {
                -1
            };
            inst.loops.push(LoopCtx {
                block: block_index,
                remaining,
            });
            inst.pc += 1;
            None
        }
        BlockKind::Condition => {
            if cmd.opcode == 112 {
                // The string flavour branches through the very same case table;
                // only the comparison differs, so it reuses the block stack instead of
                // duplicating the enter/close discipline.
                inst.pc = eval_string_condition(inst, vars, cmd);
                return None;
            }
            let head = arg(cmd, 0);
            let count = (head & 0x0F) as usize;
            let mut matched = None;
            for i in 0..count {
                let var = arg(cmd, 1 + 3 * i);
                // The right-hand side is a magic operand too: this title's
                // condition blocks compare a counter against a value held in a
                // self variable (CE79 pc85 compares self621 with self616), and
                // reading it raw turned a six-iteration loop into a 1.6-million
                // iteration one that never returned.
                let value = eval_num_host(arg(cmd, 2 + 3 * i), inst, vars, host);
                let operator = arg(cmd, 3 + 3 * i);
                let lhs = eval_num_host(var, inst, vars, host);
                if compare(lhs, value, operator) {
                    matched = Some((i + 1) as i32);
                    break;
                }
            }
            let target = match matched {
                Some(case_id) => block.case_target(case_id),
                None => None,
            };
            // Bit 4 of the head nibble is documented as "has else", but this
            // game's 0x10..0x14 shapes disagree with where the 420 markers
            // actually sit (docs/OPCODE_SPEC.md §5.16), so the structural
            // evidence — a 420 belonging to this block — is what we trust.
            let target = target.or(block.else_pc);
            inst.pc = target.unwrap_or_else(|| block.end_target(len));
            None
        }
        BlockKind::Choices => {
            let options: Vec<String> = cmd
                .strings
                .iter()
                .map(|option| expand(option, inst, vars))
                .collect();
            host.show_choices(&options);
            inst.wait = WaitState::Choice { block: block_index };
            inst.pc += 1;
            Some(BlockResult {
                signal: Signal::Blocked,
                steps,
            })
        }
    }
}

/// `498`: count the loop down and close it, or jump back to the body.
fn close_loop(inst: &mut Instance, block_index: usize) {
    let len = inst.program.len();
    let Some(pos) = inst.loops.iter().rposition(|ctx| ctx.block == block_index) else {
        // Orphan 498 (docs/OPCODE_SPEC.md §4.3): behave like a no-op.
        inst.pc += 1;
        return;
    };
    let ctx = &mut inst.loops[pos];
    // A negative count is an endless loop (170/176), which must always jump back;
    // a counted loop (179) runs its body once per unit and exits on the last one.
    let again = if ctx.remaining < 0 {
        true
    } else if ctx.remaining > 1 {
        ctx.remaining -= 1;
        true
    } else {
        false
    };
    if again {
        inst.pc = inst.program.blocks[block_index].head + 1;
    } else {
        inst.loops.truncate(pos);
        inst.pc = inst.program.blocks[block_index].end_target(len);
    }
}

/// `112`: string conditional branch (文字列条件分岐). Layout per
/// docs/OPCODE_SPEC.md §5.10: one string variable and one compared string per
/// condition (`argc == 1 + (head & 0x0F)`, `strc == 4`), the same 401/420/499
/// skeleton as `111`, and equality is the only comparison the opcode offers.
/// The game really does use it: 123 sites in the common events and 21 in the map
/// pages, which is why it has to share the block stack (see `from_slots`).
fn eval_string_condition(inst: &mut Instance, vars: &mut Variables, cmd: &Command) -> usize {
    let head = arg(cmd, 0);
    let count = (head & 0x0F) as usize;
    let use_else = head & 0x10 != 0;
    let block_index = match inst.program.control.get(inst.pc) {
        Some(Control::Block(index)) => *index,
        _ => return inst.pc + 1,
    };
    let block = inst.program.blocks[block_index].clone();
    let len = inst.program.len();
    let mut matched = None;
    for i in 0..count {
        let var = arg(cmd, 1 + i);
        let lhs = eval_str(var, inst, vars);
        let rhs = cmd
            .strings
            .get(i)
            .map_or(String::new(), |raw| expand(raw, inst, vars));
        if lhs == rhs {
            matched = Some((i + 1) as i32);
            break;
        }
    }
    let target = matched.and_then(|case_id| block.case_target(case_id));
    let target = target.or(if use_else { block.else_pc } else { None });
    target.unwrap_or_else(|| block.end_target(len))
}

/// Evaluate the numeric and string arguments plus the return target of a
/// `210`/`300`.
fn call_arguments(
    cmd: &Command,
    inst: &Instance,
    vars: &Variables,
) -> (Vec<i32>, Vec<String>, Option<i32>) {
    let Some(status) = cmd.param_status() else {
        return (Vec::new(), Vec::new(), None);
    };
    let count = status.number_count();
    let mut args = Vec::with_capacity(count);
    for i in 0..count {
        args.push(eval_num(arg(cmd, 2 + i), inst, vars));
    }
    let strings = string_arguments(cmd, inst, vars, status);
    // The parameter table is numeric arguments, then string arguments, then the
    // optional destination. Both kinds occupy one 4-byte word, so the destination
    // sits at 2 + total_count, not 2 + number_count: 22 sites in this game pass a
    // string argument *and* ask for a return value, and the naive index reads the
    // string reference as if it were a variable address
    // (docs/OPCODE_210_RETURN.md §2.2).
    let return_to = if status.return_value_enabled() {
        Some(arg(cmd, 2 + status.total_count()))
    } else {
        None
    };
    (args, strings, return_to)
}

/// Resolve the string arguments of a `210`/`300` in the caller's context.
///
/// Each string slot is either a literal or a variable reference, and the
/// editor tells them apart with its own enable bit: `string_enabled(k)` set
/// means "use `stringArgs[1 + k]`", clear means "the word in the argument
/// table is a magic address". The two never disagree in this game - all 73
/// variable slots carry a non-zero word and all 16,110 literal slots carry 0 -
/// but the word is also checked so a zero can never be read as variable 0
/// (docs/OPCODE_210_RETURN.md section 8).
fn string_arguments(
    cmd: &Command,
    inst: &Instance,
    vars: &Variables,
    status: wolf_format::command::ParamStatus,
) -> Vec<String> {
    let count = status.string_count().min(SELF_ARG_STRING_SLOTS);
    let mut out = Vec::with_capacity(count);
    for k in 0..count {
        let word = arg(cmd, 2 + status.number_count() + k);
        if status.string_enabled(k) || word == 0 {
            // stringArgs[0] is the event title for 300 and a reserved blank for
            // 210, so the k-th literal lives at 1 + k.
            out.push(
                cmd.strings
                    .get(1 + k)
                    .map_or_else(String::new, Clone::clone),
            );
        } else {
            out.push(eval_str(word, inst, vars));
        }
    }
    out
}

/// Decode a `150 Picture` instruction (docs/OPCODE_SPEC.md §5.31).
/// One `150` argument: evaluate magic storage references, pass flags and sentinels through.
fn picture_arg(raw: i32, inst: &Instance, vars: &Variables) -> i32 {
    // 0x0F00_0000 is the flag nibble Magic::decode strips; those bits are data here.
    if (raw as u32) & 0x0F00_0000 != 0 {
        raw
    } else {
        eval_num(raw, inst, vars)
    }
}

/// Raw argument index of the string-variable reference picture types 1 and 4 carry.
///
/// The argument list is [head, number, ..fields], and the reference is the last of the
/// nineteen field words, so it lands on raw index 11 (decoded index 9, `field::EXTRAS`).
const PICTURE_STRING_SLOT: usize = 11;

/// Resolves the file name a type-1 or type-4 picture command names.
///
/// The operand is an ordinary magic reference but it has to be read out of the STRING bank
/// even though it looks numeric: `1_600_009` means "event self string 9" in this position,
/// and the same encoding addresses the numeric self slots everywhere else. Anything this
/// engine cannot dereference yields an empty name, which the picture layer treats as
/// "nothing to draw yet" rather than inventing a path.
fn picture_string_ref(cmd: &Command, inst: &Instance, vars: &Variables) -> String {
    let magic = Magic::decode(arg(cmd, PICTURE_STRING_SLOT));
    // Magic::index is already the flat bank index (1_600_009 is group 6, slot 9, i.e. 609),
    // which is why program.self_base must NOT be added here: that offset belongs to the
    // cself[n] escape, whose n counts inside the event instead of naming the bank.
    match magic.kind() {
        MagicKind::SelfVar => inst.self_vars.get_str(magic.index() as usize).to_owned(),
        MagicKind::StrVar => vars.get_str(magic.index() as usize).to_owned(),
        _ => String::new(),
    }
}

fn decode_picture(inst: &Instance, vars: &Variables, cmd: &Command) -> PictureCmd {
    let head = arg(cmd, 0);
    let kind = ((head >> 4) & 0x07) as u8;
    // Bits 12..14 of the head word anchor the picture: 0 means x/y is the top-left corner,
    // 1 (0x1000) means it is the centre. Measured over 13,637 long-form draws - the 0x1000
    // group sits on x=512 / y=288 (the logical screen centre), and the retail title hint
    // banner only lines up when its 606x35 image is centred on (512, 520).
    let anchor = ((head >> 12) & 0x07) as u8;
    // Bit 22 asks the redraw to keep the slot's current draw-coordinate shift. It is
    // common on moving/drawing commands (188 of 5,433 retail op150s) and the settings
    // screen's help text depends on it.
    let keep_shift = head & 0x0040_0000 != 0;
    let relative = head & 0x0001_0000 != 0;
    let action = match head & 0x0F {
        0 => PictureAction::Draw,
        1 => PictureAction::Move,
        2 => PictureAction::Erase,
        3 => PictureAction::Hide,
        _ => PictureAction::Set,
    };
    let number = eval_num(arg(cmd, 1), inst, vars);
    let raw = cmd.strings.first().map_or("", String::as_str);
    let expanded = expand(raw, inst, vars);
    let (file, text) = match kind {
        0 | 3 => (expanded, String::new()),
        2 => (String::new(), expanded),
        // Types 1 and 4 name a string VARIABLE, and the reference rides in the last integer
        // slot (decoded index 9), not in the command's string table: all 54 type-1 and all
        // 53 type-4 draws in this game carry zero string arguments. Common event 63 draws the
        // message window with `150 [0x1040, 19500, 5, .., 100, 0, 1600009]` - "whatever file
        // event self string 9 holds" - and fills that slot from the database with
        // SystemFile/WindowBase.png.
        1 | 4 => (picture_string_ref(cmd, inst, vars), String::new()),
        _ => (String::new(), String::new()),
    };
    // Every argument past the head is a value: the measured title script passes its menu
    // coordinates as self-variable references (picture 0 sits at self[41]/self[42]) rather
    // than constants, so they must be evaluated here or the picture lands at 1,600,041.
    // Flag carriers (top nibble set, e.g. 0x02000000) and the negative sentinels
    // (-1 / -2 / -1000000) are passed through untouched: their high bits are meaningful.
    let args: Vec<i32> = (2..argc(cmd))
        .map(|i| picture_arg(arg(cmd, i), inst, vars))
        .collect();
    let animate = if args.len() > 11 {
        args[11..].to_vec()
    } else {
        Vec::new()
    };
    PictureCmd {
        number,
        kind,
        action,
        file,
        text,
        args,
        anchor,
        animate,
        keep_shift,
        relative,
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use wolf_format::command::{Command, Slot, Tail};

    fn cmd(opcode: u32, args: &[i32], strings: &[&str]) -> Slot {
        let mut params = Vec::new();
        for a in args {
            params.extend_from_slice(&a.to_le_bytes());
        }
        Slot::Command(Box::new(Command {
            param_count: (args.len() + 1) as u8,
            opcode,
            params,
            branch_depth: 0,
            strings: strings.iter().map(|s| (*s).to_owned()).collect(),
            tail: Tail::None,
        }))
    }

    fn event(id: u32, title: &str, commands: Vec<Slot>) -> wolf_format::commonevent::CommonEvent {
        wolf_format::commonevent::CommonEvent {
            id,
            raw_condition: 0,
            condition_variable: 0,
            condition_value: 0,
            arg_num_count: 0,
            arg_str_count: 0,
            title: title.to_owned(),
            commands,
            memo: String::new(),
            arg_names: Vec::new(),
            arg_special_spec: Vec::new(),
            arg_string_pages: Vec::new(),
            arg_value_pages: Vec::new(),
            default_values: Vec::new(),
            color: 0,
            self_variable_names: Vec::new(),
            return_name: String::new(),
            // A test event returns nothing unless it says so, matching the 476
            // of 550 events in the real file that carry 0xFFFF_FFFF.
            return_value_id: NO_RETURN_VALUE,
        }
    }

    /// Same, but declaring a return value in self group 6 slot `id`.
    fn event_ret(
        id: u32,
        title: &str,
        return_value_id: u32,
        commands: Vec<Slot>,
    ) -> wolf_format::commonevent::CommonEvent {
        let mut e = event(id, title, commands);
        e.return_value_id = return_value_id;
        e
    }

    fn vm_with(events: Vec<wolf_format::commonevent::CommonEvent>) -> Vm {
        let mut data = wolf_format::commonevent::CommonEventData {
            version_header: 0x55,
            version: 0xC9,
            events,
            footer: 0x90,
        };
        data.events.sort_by_key(|e| e.id);
        Vm::new(ProgramSet::from_common_events(&data))
    }

    #[derive(Default)]
    struct Recorder {
        messages: Vec<String>,
        faces: Vec<Option<i32>>,
        choices: Vec<Vec<String>>,
        pictures: Vec<PictureCmd>,
        sounds: Vec<SoundCmd>,
        logs: Vec<(LogLevel, String)>,
        teleports: Vec<(i32, i32, i32, i32, i32)>,
        dismiss: bool,
        reply: Option<ChoiceReply>,
        // Answers served to 124 picture queries, keyed by (number, field).
        picture_answers: Vec<(i32, i32, Option<i32>)>,
        // Every (number, field) pair 124 actually asked about.
        picture_queries: Vec<(i32, i32)>,
        // Canned engine answers for 124 0x3000, keyed by field.
        engine_answers: Vec<(i32, i32)>,
        // How many times the interpreter told the host to close the window.
        closed: usize,
        // Every 250 DatabaseAccess the interpreter decoded, in order.
        databases: Vec<DbOp>,
        // The answer served back for a 250 read, if any. Served for writes too, so a
        // test can prove the interpreter drops it.
        db_answer: Option<DbValue>,
        // Every 220/221/222 the interpreter decoded, in order.
        saves: Vec<SaveOp>,
        // The answer served back for a 221 read.
        save_answer: Option<i32>,
        // Every 290 effect the interpreter decoded: (type, duration, evaluated args).
        effects: Vec<(i32, i32, Vec<i32>)>,
        // Every 123 poll the host answered: (mask, auto-input bits).
        key_polls: Vec<(u32, u32)>,
        // Every 151 ChangeColor: (packed colour, frames).
        colours: Vec<(i32, i32)>,
    }

    impl Host for Recorder {
        fn show_message(&mut self, text: &str, face: Option<i32>) {
            self.messages.push(text.to_owned());
            self.faces.push(face);
        }
        fn message_dismissed(&mut self) -> bool {
            self.dismiss
        }
        fn show_choices(&mut self, options: &[String]) {
            self.choices.push(options.to_vec());
        }
        fn choice_made(&mut self) -> Option<ChoiceReply> {
            self.reply
        }
        fn picture(&mut self, cmd: &PictureCmd) {
            self.pictures.push(cmd.clone());
        }
        fn sound(&mut self, cmd: &SoundCmd) {
            self.sounds.push(cmd.clone());
        }
        fn teleport(&mut self, target: i32, map: i32, x: i32, y: i32, options: i32) {
            self.teleports.push((target, map, x, y, options));
        }
        fn change_color(&mut self, colour: i32, frames: i32) {
            self.colours.push((colour, frames));
        }
        fn log(&mut self, level: LogLevel, message: &str) {
            self.logs.push((level, message.to_owned()));
        }
        fn picture_state(&mut self, number: i32, field: i32) -> Option<i32> {
            self.picture_queries.push((number, field));
            self.picture_answers
                .iter()
                .find(|(n, f, _)| *n == number && *f == field)
                .and_then(|(_, _, value)| *value)
        }
        fn engine_state(&mut self, field: i32) -> Option<i32> {
            self.engine_answers
                .iter()
                .find(|(f, _)| *f == field)
                .map(|(_, value)| *value)
        }
        fn database(&mut self, op: &DbOp) -> Option<DbValue> {
            self.databases.push(op.clone());
            self.db_answer.clone()
        }
        fn save_load(&mut self, op: &SaveOp) -> Option<i32> {
            self.saves.push(op.clone());
            self.save_answer
        }
        fn effect(&mut self, kind: i32, duration: i32, args: &[i32]) {
            self.effects.push((kind, duration, args.to_vec()));
        }
        fn key_code_auto(&mut self, mask: u32, auto: u32) -> i32 {
            self.key_polls.push((mask, auto));
            0
        }
        fn close_message(&mut self) {
            self.closed += 1;
        }
    }

    #[test]
    fn auto_input_reaches_the_host_with_the_poll_mask() {
        // 125 remembers the key bits the script wants pressed; the next 123 must
        // carry them to the host, not just leave them in the interpreter.
        let ev = event(
            5,
            "auto input",
            vec![
                cmd(125, &[16], &[]),
                cmd(123, &[2_000_000, 247], &[]),
                cmd(125, &[0], &[]),
                cmd(123, &[2_000_001, 247], &[]),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        vm.start_event(5).unwrap();
        let mut host = Recorder::default();
        vm.step_frame(&mut host);
        assert_eq!(host.key_polls, vec![(247, 16), (247, 0)]);
    }

    #[test]
    fn a_dismissed_message_is_closed_on_the_host() {
        let ev = event(
            31,
            "message",
            vec![cmd(101, &[], &["\\Ehello"]), cmd(103, &[], &[])],
        );
        let mut vm = vm_with(vec![ev]);
        let mut host = Recorder::default();
        vm.start_event(31).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(host.messages, vec!["\\Ehello".to_owned()]);
        assert_eq!(host.closed, 0, "nothing dismissed yet");

        host.dismiss = true;
        vm.step_frame(&mut host);
        assert_eq!(host.closed, 1, "the window closes exactly once");
        assert_eq!(host.messages.len(), 1, "no second message");
    }

    #[test]
    fn opcode_124_writes_picture_and_engine_answers() {
        // 0x4000 reads a picture field: field 8 is the hover test that drives the whole
        // title menu (588 uses game-wide, docs/OPCODE_124.md section 5.3).
        let ev = event(
            42,
            "queries",
            vec![
                cmd(124, &[2_000_000, 0x4000, 12_005, 8], &[]),
                cmd(124, &[2_000_001, 0x4000, 12_005, 9], &[]),
                // argc 3 is the short form and only 0x3000 uses it: [dst, sub, field].
                cmd(124, &[2_000_002, 0x3000, 20], &[]),
                // An unanswered field must leave the destination alone, not write 0:
                // seed it with 7 first, then ask a field nobody answers.
                cmd(121, &[2_000_003, 7, 0, 0], &[]),
                cmd(124, &[2_000_003, 0x4000, 12_005, 77], &[]),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        vm.start_event(42);
        let mut host = Recorder {
            picture_answers: vec![(12_005, 8, Some(1)), (12_005, 9, Some(0))],
            engine_answers: vec![(20, 640)],
            ..Recorder::default()
        };
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 1, "hover answer");
        assert_eq!(vm.vars.get(1), 0, "in-use answer");
        assert_eq!(vm.vars.get(2), 640, "mouse x from the short form");
        assert_eq!(vm.vars.get(3), 7, "unanswered field keeps the old value");
        assert_eq!(
            host.picture_queries,
            vec![(12_005, 8), (12_005, 9), (12_005, 77)]
        );
        // The object operand is a magic value, so a 5-digit picture number arrives
        // verbatim instead of being decoded as a variable reference.
        assert!(host.logs.is_empty(), "unexpected logs");
    }

    #[test]
    fn opcode_124_reports_the_running_event_for_field_18() {
        // Field 18 answers 'which event is running' from the interpreter itself, and
        // common events report id + 500000 so they cannot collide with map events.
        let ev = event(77, "self id", vec![cmd(124, &[2_000_000, 0x3000, 18], &[])]);
        let mut vm = vm_with(vec![ev]);
        vm.start_event(77);
        let mut host = Recorder::default();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 500_077);
    }

    #[test]
    fn arithmetic_assigns_and_compounds() {
        // v[0] = 2 + 3; v[1] = v[0] * 4
        let e = event(
            1,
            "arith",
            vec![
                cmd(121, &[2_000_000, 2, 3, 0], &[]),
                cmd(121, &[2_000_001, 2_000_000, 4, 0x2000], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 5);
        assert_eq!(vm.vars.get(1), 20);
    }

    #[test]
    fn cself_reads_the_self_bank_of_the_running_event() {
        // ev63 returns to its caller with a 213 whose label ends in cself[40]
        // after storing 2 in slot 40. Slot 40 of a common event is magic
        // 1_600_040, so the escape must read bank 640; reading bank 40 expanded
        // to a label nobody defines and killed the message-window coroutine.
        let commands = vec![
            cmd(121, &[1_600_040, 2, 0, 0], &[]),
            cmd(213, &[], &[r"m\cself[40]"]),
            // Wrong path: bank 40 reads 0, so the name would be m0.
            cmd(121, &[2_000_000, 99, 0, 0], &[]),
            cmd(212, &[], &["m1"]),
            cmd(121, &[2_000_001, 1, 0, 0], &[]),
            cmd(212, &[], &["m2"]),
            cmd(121, &[2_000_002, 3, 0, 0], &[]),
        ];
        let mut vm = vm_with(vec![event(1, "jump", commands)]);
        vm.start_event(1);
        let mut host = Recorder::default();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 0, "the wrong label must not be reached");
        assert_eq!(vm.vars.get(1), 0, "landed past the m2 body");
        assert_eq!(vm.vars.get(2), 3, "landed after the second label");
    }
    #[test]
    fn operator_0x6000_is_a_random_range() {
        // 1,101 real instructions use it; before this was understood, every one
        // of them silently took the wrong branch (docs/OPCODE_SPEC.md §3.2).
        let ev = event(
            42,
            "random",
            vec![
                cmd(121, &[2_000_000, 1, 6, 0x6000], &[]),
                cmd(121, &[2_000_001, 0, 2_000_000, 0x0000], &[]),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        vm.start_event(42);
        let mut host = Recorder::default();
        vm.step_frame(&mut host);
        let drawn = vm.vars.get(0);
        assert!((1..=6).contains(&drawn), "not in range: {drawn}");
        assert_eq!(vm.rng.draws(), 1);
        // The 0x0000 binary op is still plain addition, not a random draw.
        assert_eq!(vm.vars.get(1), drawn);
        assert_eq!(vm.rng.draws(), 1);
    }

    #[test]
    fn stray_low_bits_do_not_change_the_operator() {
        // 194 real instructions set undocumented bits 0..7 (0x104, 0x3302, 0x4).
        // 0x104 must still be `+=`, not a plain assignment.
        let ev = event(
            7,
            "bits",
            vec![
                cmd(121, &[2_000_000, 5, 0, 0x0000], &[]),
                cmd(121, &[2_000_000, 3, 0, 0x0104], &[]),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        vm.start_event(7);
        let mut host = Recorder::default();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 8, "expected 5 += 3");
    }
    #[test]
    fn compound_assignment_operators() {
        let e = event(
            1,
            "compound",
            vec![cmd(121, &[2_000_000, 7, 0, 0x000], &[])],
        );
        let mut vm = vm_with(vec![e]);
        vm.vars.set(0, 100);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 7);
    }

    #[test]
    fn division_by_zero_keeps_the_old_value() {
        // v[0] /= (0 + 0): the binary op supplies the divisor, the compound
        // operator divides by it.
        let e = event(1, "divzero", vec![cmd(121, &[2_000_000, 0, 0, 0x400], &[])]);
        let mut vm = vm_with(vec![e]);
        vm.vars.set(0, 33);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 33);
    }

    #[test]
    fn conditional_takes_the_matching_branch() {
        // if (v[0] > 5) { v[1] = 1 } else { v[1] = 2 }
        let e = event(
            1,
            "branch",
            vec![
                cmd(111, &[1, 2_000_000, 5, 0], &[]),
                cmd(121, &[2_000_001, 1, 0, 0], &[]),
                cmd(401, &[1], &[]),
                cmd(121, &[2_000_001, 1, 0, 0], &[]),
                cmd(420, &[0], &[]),
                cmd(121, &[2_000_001, 2, 0, 0], &[]),
                cmd(499, &[], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        vm.vars.set(0, 9);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(1), 1);
    }

    #[test]
    fn conditional_takes_the_else_when_nothing_matches() {
        let e = event(
            1,
            "branch2",
            vec![
                cmd(111, &[1, 2_000_000, 5, 0], &[]),
                cmd(121, &[2_000_001, 1, 0, 0], &[]),
                cmd(401, &[1], &[]),
                cmd(121, &[2_000_001, 1, 0, 0], &[]),
                cmd(420, &[0], &[]),
                cmd(121, &[2_000_001, 2, 0, 0], &[]),
                cmd(499, &[], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        vm.vars.set(0, 1);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(1), 2);
    }

    #[test]
    fn loop_times_runs_exactly_n_times() {
        // v[0] = 0; loop 3 times { v[0] += 1 }
        let e = event(
            1,
            "loop",
            vec![
                cmd(121, &[2_000_000, 0, 0, 0], &[]),
                cmd(179, &[3], &[]),
                cmd(121, &[2_000_000, 2_000_000, 1, 0], &[]),
                cmd(498, &[], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 3);
        assert_eq!(vm.instances().len(), 0);
    }

    #[test]
    fn loop_times_zero_skips_the_body() {
        let e = event(
            1,
            "loop0",
            vec![
                cmd(179, &[0], &[]),
                cmd(121, &[2_000_000, 1, 0, 0], &[]),
                cmd(498, &[], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 0);
    }

    #[test]
    fn break_loop_leaves_the_loop() {
        // loop { v[0] += 1; if v[0] == 2 { break } }
        let e = event(
            1,
            "break",
            vec![
                cmd(170, &[], &[]),
                cmd(121, &[2_000_000, 2_000_000, 1, 0], &[]),
                cmd(111, &[1, 2_000_000, 2, 2], &[]),
                cmd(401, &[1], &[]),
                cmd(171, &[], &[]),
                cmd(499, &[], &[]),
                cmd(498, &[], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 2);
    }

    #[test]
    fn wait_one_blocks_exactly_one_frame() {
        let e = event(
            1,
            "wait",
            vec![cmd(180, &[1], &[]), cmd(121, &[2_000_000, 5, 0, 0], &[])],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 0, "must still be waiting after frame 1");
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 5, "must resume on frame 2");
    }

    #[test]
    fn message_blocks_until_dismissed() {
        let e = event(
            1,
            "msg",
            vec![
                cmd(101, &[], &["@2hello"]),
                cmd(121, &[2_000_000, 1, 0, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(host.messages, vec!["hello".to_owned()]);
        assert_eq!(host.faces, vec![Some(2)]);
        assert_eq!(
            vm.vars.get_sys(0),
            2,
            "`@2` must reach Sys0 for the frame painter"
        );
        assert_eq!(vm.vars.get(0), 0);
        host.dismiss = true;
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 1);
    }

    #[test]
    fn choice_jumps_to_the_selected_case() {
        // 102 with 2 options: option 1 sets v[0] = 11, option 0 sets v[0] = 10
        let e = event(
            1,
            "choice",
            vec![
                cmd(102, &[2], &["first", "second"]),
                cmd(401, &[2], &[]),
                cmd(121, &[2_000_000, 10, 0, 0], &[]),
                cmd(401, &[3], &[]),
                cmd(121, &[2_000_000, 11, 0, 0], &[]),
                cmd(421, &[0], &[]),
                cmd(499, &[], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder {
            reply: Some(ChoiceReply::Index(1)),
            ..Recorder::default()
        };
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(
            host.choices[0],
            vec!["first".to_owned(), "second".to_owned()]
        );
        // The reply is polled at the start of the next frame, so the jump lands
        // there — same latency the original has when the player clicks.
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 11);
    }

    #[test]
    fn a_case_body_does_not_fall_through_into_the_next_case() {
        // Choosing option 0 must run only the first body. The old interpreter
        // executed the next 401 marker and jumped straight into the sibling
        // case, so the title menu ran every entry at once (M1_CLOSURE Q1).
        let e = event(
            1,
            "no fall-through",
            vec![
                cmd(102, &[2], &["first", "second"]),
                cmd(401, &[2], &[]),
                cmd(121, &[2_000_000, 10, 0, 0], &[]),
                cmd(121, &[2_000_001, 10_000, 0, 0], &[]),
                cmd(401, &[3], &[]),
                cmd(121, &[2_000_001, 22_222, 0, 0], &[]),
                cmd(499, &[], &[]),
                cmd(121, &[2_000_002, 33_333, 0, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder {
            reply: Some(ChoiceReply::Index(0)),
            ..Recorder::default()
        };
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 10, "first case body ran");
        assert_eq!(
            vm.vars.get(1),
            10_000,
            "the next marker ended the branch instead of entering the sibling case"
        );
        // The branch ends at the 499, so the instruction after it still runs.
        assert_eq!(
            vm.vars.get(2),
            33_333,
            "execution continues past the branch"
        );
        assert!(vm.instance(0).is_none(), "event finished");
    }

    #[test]
    fn opaque_operands_keep_their_negative_value() {
        // -2 is the "whole screen" picture sentinel, -1_000_000 means "leave
        // unchanged": both live in the MagicKind::Opaque space and used to decay
        // to 0, which silently turned layer -2 into picture 0 (M1_CLOSURE Q3).
        let e = event(
            1,
            "opaque",
            vec![
                cmd(121, &[2_000_000, -2, 0, 0], &[]),
                cmd(121, &[2_000_001, -1_000_000, 0, 0], &[]),
                cmd(150, &[0, -2, 30, 1, 1, 1, 255, 0, 0, 100, 0], &["a.jpg"]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), -2);
        assert_eq!(vm.vars.get(1), -1_000_000);
        assert_eq!(host.pictures[0].number, -2, "screen-layer picture number");
    }

    #[test]
    fn common_event_call_spawns_a_child_and_blocks_the_caller() {
        let callee = event(
            2,
            "callee",
            vec![cmd(121, &[2_000_000, 7, 0, 0], &[]), cmd(172, &[], &[])],
        );
        let caller = event(
            1,
            "caller",
            vec![
                cmd(210, &[500_002, 0, 0, 0], &[]),
                cmd(121, &[2_000_001, 1, 0, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![callee, caller]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        // The child is a separate coroutine: it runs on the next frame, and the
        // parent stays blocked until it finishes.
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 7);
        // Parent resumed after the child ended.
        assert_eq!(vm.vars.get(1), 1);
        assert_eq!(vm.instances().len(), 0);
    }

    #[test]
    fn common_event_return_value_lands_in_the_callers_variable() {
        // docs/OPCODE_210_RETURN.md: the callee leaves its result in self group 6
        // at \`return_value_id\` (here slot 10 -> 1_600_010), the caller named the
        // destination 2_000_000 in the trailing operand of its 210.
        let callee = event_ret(
            2,
            "callee",
            10,
            vec![cmd(121, &[1_600_010, 42, 0, 0], &[]), cmd(172, &[], &[])],
        );
        let caller = event_ret(
            1,
            "caller",
            NO_RETURN_VALUE,
            // 0x0100_0000: no arguments, one return destination.
            vec![cmd(210, &[500_002, 0x0100_0000, 2_000_000], &[])],
        );
        let mut vm = vm_with(vec![callee, caller]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        for _ in 0..3 {
            vm.step_frame(&mut host);
        }
        assert_eq!(vm.vars.get(0), 42);
        assert_eq!(vm.instances().len(), 0);
    }

    #[test]
    fn common_event_without_declared_return_leaves_the_caller_alone() {
        // 8 real call sites ask for a return value from an event that declares
        // none (0xFFFF_FFFF); the callee never writes the slot either, so the
        // destination keeps its old value (docs/OPCODE_210_RETURN.md §4).
        let callee = event_ret(
            2,
            "noret",
            NO_RETURN_VALUE,
            vec![cmd(121, &[2_000_009, 9, 0, 0], &[]), cmd(172, &[], &[])],
        );
        let caller = event_ret(
            1,
            "caller",
            NO_RETURN_VALUE,
            vec![
                cmd(121, &[2_000_000, 5, 0, 0], &[]),
                cmd(210, &[500_002, 0x0100_0000, 2_000_000], &[]),
            ],
        );
        let mut vm = vm_with(vec![callee, caller]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        for _ in 0..3 {
            vm.step_frame(&mut host);
        }
        assert_eq!(vm.vars.get(0), 5);
        assert_eq!(vm.vars.get(9), 9);
    }

    #[test]
    fn return_destination_follows_the_string_parameters() {
        // 0x0100_0011 = one numeric argument, one string argument, one return
        // value. The destination is the *fourth* word, after the string
        // reference; indexing it by number_count alone lands on the string
        // reference (docs/OPCODE_210_RETURN.md §2.2, 22 sites in the real data).
        let callee = event_ret(
            2,
            "ret9",
            9,
            vec![cmd(121, &[1_600_009, 42, 0, 0], &[]), cmd(172, &[], &[])],
        );
        let caller = event_ret(
            1,
            "caller",
            NO_RETURN_VALUE,
            vec![cmd(210, &[500_002, 0x0100_0011, 5, 0, 2_000_007], &[])],
        );
        let mut vm = vm_with(vec![callee, caller]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        for _ in 0..3 {
            vm.step_frame(&mut host);
        }
        assert_eq!(vm.vars.get(7), 42);
        assert_eq!(vm.vars.get(0), 0);
    }

    #[test]
    fn binary_operator_table_matches_the_editor() {
        // WolfTL's Command.hpp comment lists 0x3000 as % and 0x4000 as ~, but it
        // never decodes operators, so nothing ever verified the table. The game
        // does: CE48 pc30 [1600025, 9000116, 32, 0x3000] is 1024 / 32 = 32, the
        // horizontal coordinate scale, and CE48 pc172 [1600020, 1600020, 10000,
        // 0x4000] is the % 10000 item-id re-pack.
        assert_eq!(binary_op(0x3, 1024, 32), 32, "0x3 is division");
        assert_eq!(binary_op(0x3, 1025, 32), 32);
        assert_eq!(binary_op(0x4, 1025, 32), 1, "0x4 is modulo");
        assert_eq!(binary_op(0x4, 20_017, 10_000), 17);
        // A former ~-site now yields the remainder instead of -20_018.
        assert_eq!(binary_op(0x4, 20_017, 20_000), 17);
        // Division and modulo by zero keep the left operand.
        assert_eq!(binary_op(0x3, 7, 0), 7);
        assert_eq!(binary_op(0x4, 7, 0), 7);
        // The untouched neighbours.
        assert_eq!(binary_op(0x0, 7, 3), 10);
        assert_eq!(binary_op(0x1, 7, 3), 4);
        assert_eq!(binary_op(0x2, 7, 3), 21);
        assert_eq!(binary_op(0x5, 0b1100, 0b1010), 0b1000);
        assert_eq!(binary_op(0x7, 0b1100, 0b1010), 0b1110);
        assert_eq!(binary_op(0x8, 0b1100, 0b1010), 0b0110);
        assert_eq!(binary_op(0x9, 1, 4), 16);
    }

    #[test]
    fn set_variable_divides_where_the_old_table_took_a_remainder() {
        // End to end through 121: [target, arg1, arg2, 0x3000] assigns
        // arg1 / arg2, which is exactly CE48 pc30.
        let e = event(
            1,
            "ops",
            vec![
                cmd(121, &[2_000_000, 1024, 32, 0x3000], &[]),
                cmd(121, &[2_000_001, 1_025, 32, 0x4000], &[]),
                cmd(121, &[2_000_002, 9_000_116, 32, 0x3000], &[]),
                cmd(172, &[], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 32);
        assert_eq!(vm.vars.get(1), 1);
        // 9_000_116 is a system variable, not a literal: it is 0 here.
        assert_eq!(vm.vars.get(2), 0);
    }

    #[test]
    fn string_arguments_land_in_cself5_and_cself6() {
        // docs/OPCODE_210_RETURN.md section 8: the editor's four string inputs
        // arrive in CSelf5..8, i.e. magic 1_600_005 + k, one slot above the
        // four numeric inputs at CSelf0..3.
        // 0x3020 = two string arguments, both literals (enable bits 12 and 13).
        let callee = event_ret(
            2,
            "callee",
            NO_RETURN_VALUE,
            vec![
                cmd(112, &[0x11, 1_600_005], &["alpha"]),
                cmd(401, &[1], &[]),
                cmd(121, &[2_000_000, 1, 0, 0], &[]),
                cmd(112, &[0x11, 1_600_006], &["beta"]),
                cmd(401, &[1], &[]),
                cmd(121, &[2_000_001, 1, 0, 0], &[]),
                cmd(499, &[], &[]),
                cmd(499, &[], &[]),
                cmd(172, &[], &[]),
            ],
        );
        let caller = event_ret(
            1,
            "caller",
            NO_RETURN_VALUE,
            // stringArgs[0] is the reserved blank of a 210, so "alpha" is
            // stringArgs[1] and "beta" is stringArgs[2].
            vec![cmd(210, &[500_002, 0x3020, 0, 0], &["", "alpha", "beta"])],
        );
        let mut vm = vm_with(vec![callee, caller]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        for _ in 0..3 {
            vm.step_frame(&mut host);
        }
        assert_eq!(vm.vars.get(0), 1, "CSelf5 carried \"alpha\"");
        assert_eq!(vm.vars.get(1), 1, "CSelf6 carried \"beta\"");
        assert_eq!(vm.instances().len(), 0);
    }

    #[test]
    fn call_by_name_does_not_pass_its_own_title_as_a_string_argument() {
        // A 300 keeps the callee title in stringArgs[0] and the literals from
        // stringArgs[1] on. Reading the literal at k instead of 1 + k would hand
        // the callee its own title and every by-name message would be wrong.
        // 0x1010 = no numeric argument, one string argument, literal.
        let callee = event_ret(
            2,
            "named",
            NO_RETURN_VALUE,
            vec![
                cmd(112, &[0x11, 1_600_005], &["alpha"]),
                cmd(401, &[1], &[]),
                cmd(121, &[2_000_000, 1, 0, 0], &[]),
                cmd(499, &[], &[]),
                cmd(172, &[], &[]),
            ],
        );
        let caller = event_ret(
            1,
            "caller",
            NO_RETURN_VALUE,
            vec![cmd(300, &[0, 0x1010, 0], &["named", "alpha"])],
        );
        let mut vm = vm_with(vec![callee, caller]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        for _ in 0..3 {
            vm.step_frame(&mut host);
        }
        assert_eq!(vm.vars.get(0), 1, "CSelf5 carried \"alpha\"");
        assert_eq!(vm.instances().len(), 0);
    }

    #[test]
    fn a_wrapper_forwards_its_cself5_to_the_grandchild() {
        // 7,787 of the 8,260 string-passing call sites are wrappers that hand
        // their own CSelf5 straight down by putting 1_600_005 in the argument
        // word with the enable bit clear (real site: ev264 pc47). That path
        // needs the variable branch of string_arguments, not the literal one.
        // 0x0010 = no numeric argument, one string argument, variable.
        let grandchild = event_ret(
            3,
            "grandchild",
            NO_RETURN_VALUE,
            vec![
                cmd(112, &[0x11, 1_600_005], &["alpha"]),
                cmd(401, &[1], &[]),
                cmd(121, &[2_000_000, 1, 0, 0], &[]),
                cmd(499, &[], &[]),
                cmd(172, &[], &[]),
            ],
        );
        let wrapper = event_ret(
            2,
            "wrapper",
            NO_RETURN_VALUE,
            vec![
                cmd(210, &[500_003, 0x0010, 1_600_005], &[]),
                cmd(172, &[], &[]),
            ],
        );
        let caller = event_ret(
            1,
            "caller",
            NO_RETURN_VALUE,
            vec![cmd(210, &[500_002, 0x1020, 0], &["", "alpha"])],
        );
        let mut vm = vm_with(vec![grandchild, wrapper, caller]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        for _ in 0..6 {
            vm.step_frame(&mut host);
        }
        assert_eq!(vm.vars.get(0), 1, "the literal reached the grandchild");
        assert_eq!(vm.instances().len(), 0);
    }

    #[test]
    fn db_op_decode_splits_container_direction_and_operation() {
        // Real sites: ev63 pc25 [18,0,24,0x51200,self9] reads the user database,
        // ev63 pc119 [24,self49,0,0x51100,self8] reads the system database (only bit 8
        // tells it apart from CDataBase), and ev48 pc101 [18,51,0,0x10000,6] writes one.
        let ev = event(
            5,
            "db decode",
            vec![
                cmd(
                    250,
                    &[18, 0, 24, 0x51200, 2_000_000],
                    &["", "画像/音声設定", "", "メッセ—ジウィンドウ ベ—ス画像"],
                ),
                cmd(121, &[1_600_049, 2, 0, 0], &[]),
                cmd(
                    250,
                    &[24, 1_600_049, 0, 0x51100, 2_000_001],
                    &["", "顔グラフィック名", "", "顔画像ファイル"],
                ),
                cmd(
                    250,
                    &[18, 97, 0, 0x10000, 6],
                    &["", "マップ設定", "", "座標倍率X"],
                ),
                // The clamp idiom of ev50 pc30 / ev53 pc5: max() instead of assign.
                cmd(
                    250,
                    &[19, 0, 26, 0x10060, 3],
                    &["", "システム設定", "", "顔倍率"],
                ),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        vm.start_event(5).unwrap();
        let mut host = Recorder::default();
        vm.step_frame(&mut host);
        assert_eq!(host.databases.len(), 4);

        let user = &host.databases[0];
        assert_eq!(
            user.container,
            DbContainer::Data,
            "bit 9 is Data, not bit 8"
        );
        assert_eq!(user.direction, DbDirection::Read);
        assert_eq!(user.op, 0, "assign");
        assert_eq!((user.db_type, user.data_id, user.item_id), (18, 0, 24));
        assert_eq!(user.destination, Some(2_000_000));
        assert_eq!(user.source, None);
        assert_eq!(user.type_label.as_deref(), Some("画像/音声設定"));
        assert_eq!(
            user.field_label.as_deref(),
            Some("メッセ—ジウィンドウ ベ—ス画像")
        );

        let system = &host.databases[1];
        assert_eq!(system.container, DbContainer::Sys, "only bit 8 is set");
        assert_eq!(system.direction, DbDirection::Read);
        assert_eq!(system.data_id, 2, "the row is self[49], not 1600049");
        assert_eq!(system.item_id, 0);

        let write = &host.databases[2];
        assert_eq!(
            write.container,
            DbContainer::CData,
            "bit 16 is not a container"
        );
        assert_eq!(
            write.direction,
            DbDirection::Write,
            "bit 16 is not the direction"
        );
        assert_eq!(write.op, 0);
        assert_eq!(write.destination, None, "a write has no destination");
        assert_eq!(write.source, Some(DbValue::Num(6)));
        assert!(!write.string_write());

        let clamp = &host.databases[3];
        assert_eq!(clamp.direction, DbDirection::Write);
        assert_eq!(clamp.op, 6, "max()");
        assert_eq!(clamp.source, Some(DbValue::Num(3)));
        assert!(host.logs.is_empty(), "unexpected logs");
    }

    #[test]
    fn db_write_never_touches_the_source_variable() {
        // A write's fifth operand is the value to store, so even an answer from the
        // host must be dropped: v[1] has to stay 5 after the cell is written.
        let ev = event(
            6,
            "db write",
            vec![
                cmd(121, &[2_000_001, 5, 0, 0], &[]),
                cmd(250, &[18, 51, 0, 0x10000, 2_000_001], &[]),
                // Bogus ids still route to the container bits, not to the string form.
                cmd(250, &[18, 52, 0, 0x10000, 2_000_002], &[]),
                // argc 4 is the string form: the value is stringArgs[0] and bit 1 says so.
                cmd(250, &[21, 90, 1, 0x10002], &["習得した"]),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        vm.start_event(6).unwrap();
        let mut host = Recorder {
            db_answer: Some(DbValue::Num(99)),
            ..Recorder::default()
        };
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(1), 5, "the source variable was overwritten");
        assert_eq!(vm.vars.get(2), 0, "a write must not store into a variable");
        assert_eq!(host.databases.len(), 3);

        assert_eq!(host.databases[0].source, Some(DbValue::Num(5)));
        assert_eq!(host.databases[0].data_id, 51);
        assert_eq!(host.databases[1].source, Some(DbValue::Num(0)));

        let string_write = &host.databases[2];
        assert_eq!(string_write.direction, DbDirection::Write);
        assert_eq!(string_write.op, 0);
        assert_eq!(
            string_write.source,
            Some(DbValue::Str("習得した".to_owned()))
        );
        assert!(string_write.string_write());
        assert!(host.logs.is_empty(), "unexpected logs");
    }

    #[test]
    fn save_ops_decode_slot_paths_and_store_the_221_answer() {
        // ev48 pc209 is the canonical 221: `[self20, "Save/System.sav", 2000000, 0]`.
        // The file operand is a *string* variable, so it must arrive as a path rather
        // than a slot; the destination and the in-save address stay raw magic.
        let ev = event(
            7,
            "save ops",
            vec![
                cmd(122, &[3_000_009], &["Save/System.sav"]),
                cmd(121, &[1_600_012, 2, 0, 0], &[]),
                cmd(221, &[1_600_020, 3_000_009, 2_000_546, 0], &[]),
                cmd(221, &[2_000_001, 2_000_000, 2_000_002, 0], &[]),
                cmd(222, &[1_600_012, 3_000_009, 2_000_302, 0], &[]),
                cmd(220, &[1, 3_000_009], &[]),
                // Copy self[20] into a normal variable so the test can see the answer.
                cmd(121, &[2_000_001, 1_600_020, 0, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        vm.start_event(7).unwrap();
        let mut host = Recorder {
            save_answer: Some(7),
            ..Recorder::default()
        };
        vm.step_frame(&mut host);
        assert_eq!(host.saves.len(), 4);

        let read = &host.saves[0];
        assert_eq!(read.opcode, 221);
        assert_eq!(read.file, SaveTarget::Path("Save/System.sav".to_owned()));
        assert_eq!(read.destination, 1_600_020);
        assert_eq!(read.address, 2_000_546);
        assert_eq!(read.owner, 7);

        let slot_read = &host.saves[1];
        assert_eq!(
            slot_read.file,
            SaveTarget::Slot(0),
            "a numeric operand is a slot"
        );

        let write = &host.saves[2];
        assert_eq!(write.opcode, 222);
        assert_eq!(write.value, 2, "the source operand is evaluated");
        assert_eq!(write.address, 2_000_302);

        let load = &host.saves[3];
        assert_eq!(load.opcode, 220);
        assert_eq!(load.mode, 1);
        assert_eq!(load.file, SaveTarget::Path("Save/System.sav".to_owned()));

        assert_eq!(vm.vars.get(1), 7, "the 221 answer reached its destination");
        assert!(host.logs.is_empty(), "unexpected logs");
    }

    #[test]
    fn effect_operands_are_evaluated_before_the_host_sees_them() {
        // The balloon library and the HUD pass self variables as picture ids. The effect
        // command itself carries magic numbers, so the host must see 250 and 12 rather
        // than the raw 1_600_021 / 1_600_022 addresses.
        let ev = event(
            9,
            "effect",
            vec![
                cmd(121, &[1_600_021, 250, 0, 0], &[]),
                cmd(121, &[1_600_022, 12, 0, 0], &[]),
                cmd(290, &[0x50, 30, 1_600_021, 1_600_022, 0, 0, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        vm.start_event(9).unwrap();
        let mut host = Recorder::default();
        vm.step_frame(&mut host);
        assert_eq!(host.effects.len(), 1);
        let (kind, duration, args) = &host.effects[0];
        assert_eq!((*kind, *duration), (5, 30));
        assert_eq!(&args[..4], &[0x50, 30, 250, 12]);
    }

    #[test]
    fn db_read_writes_the_answer_into_the_destination_variable() {
        // ev63 pc119 stores a picture file name into self[8] through the system
        // database, which is the only Sys container in the whole game.
        let ev = event(
            7,
            "db read",
            vec![cmd(
                250,
                &[24, 1_600_049, 0, 0x51100, 3_000_000],
                &["", "顔グラフィック名", "", "顔画像ファイル"],
            )],
        );
        let mut vm = vm_with(vec![ev]);
        let mut host = Recorder {
            db_answer: Some(DbValue::Str("Picture/face01.png".to_owned())),
            ..Recorder::default()
        };
        vm.start_event(7).unwrap();
        vm.step_frame(&mut host);
        // The destination is a magic operand like any other: string variable 0 here,
        // self[8] (1_600_008) at the real site ev63 pc119.
        assert_eq!(host.databases[0].destination, Some(3_000_000));
        assert_eq!(vm.vars.get_str(0), "Picture/face01.png");
    }

    #[test]
    fn label_jump_lands_on_the_set_label() {
        let e = event(
            1,
            "labels",
            vec![
                cmd(213, &[], &["skip"]),
                cmd(121, &[2_000_000, 1, 0, 0], &[]),
                cmd(212, &[], &["skip"]),
                cmd(121, &[2_000_001, 2, 0, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 0, "the skipped instruction must not run");
        assert_eq!(vm.vars.get(1), 2);
    }

    #[test]
    fn unknown_label_ends_the_event_instead_of_looping() {
        let e = event(
            1,
            "badlabel",
            vec![
                cmd(213, &[], &["nowhere"]),
                cmd(121, &[2_000_000, 1, 0, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 0);
        assert!(host.logs.iter().any(|(l, _)| *l == LogLevel::Warn));
        assert_eq!(vm.instances().len(), 0);
    }

    #[test]
    fn picture_long_form_decodes_position_and_file() {
        let e = event(
            1,
            "picture",
            vec![cmd(
                150,
                &[0x00, 3, 100, 200, 50, 50, 255, 0, 0, 0, 0, 0, 0x0200_0000],
                &["SystemGraphic/TitleGraphic01.jpg"],
            )],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        let picture = &host.pictures[0];
        assert_eq!(picture.number, 3);
        assert_eq!(picture.kind, 0);
        assert_eq!(picture.action, PictureAction::Draw);
        assert_eq!(picture.file, "SystemGraphic/TitleGraphic01.jpg");
        assert_eq!(picture.args[0], 100);
        assert_eq!(picture.args[1], 200);
        assert_eq!(picture.anchor, 0, "0x0000 anchors the top-left corner");
    }

    #[test]
    fn picture_type_4_names_a_string_variable_not_a_string_argument() {
        // ev63 draws the message window as 150 [0x1040, 19500, 5, 960, 168, 1, 255, ...]
        // with NO string argument: the skin rides in int slot 11 as 1_600_009, i.e. self
        // string slot 9, which the event filled from the database a few commands earlier.
        let e = event(
            1,
            "window",
            vec![
                cmd(122, &[1_600_009], &["SystemFile/WindowBase.png"]),
                cmd(
                    150,
                    &[
                        0x1040, 19500, 5, 960, 168, 1, 255, 512, 480, 100, 0, 1_600_009,
                    ],
                    &[],
                ),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        let picture = &host.pictures[0];
        assert_eq!(picture.kind, 4);
        assert_eq!(picture.action, PictureAction::Draw);
        assert_eq!(picture.file, "SystemFile/WindowBase.png");
        assert_eq!(picture.text, "");
        // args start at raw arg[2], so [0] is the fade and [1]/[2] the window box.
        assert_eq!(picture.args[1], 960, "the window width follows the head");
        assert_eq!(picture.args[2], 168);
    }

    #[test]
    fn the_short_picture_form_with_head_three_is_a_hide() {
        // ev63: 150 [3, 19500] under the comment フェードが1以外ならウィンドウを非表示.
        let e = event(1, "hide", vec![cmd(150, &[3, 19500], &[])]);
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(host.pictures[0].number, 19500);
        assert_eq!(host.pictures[0].action, PictureAction::Hide);
    }

    #[test]
    fn picture_head_bits_12_to_14_carry_the_anchor() {
        // The retail title banner: head 4096 = 0x1000, drawn at the screen centre.
        let e = event(
            1,
            "banner",
            vec![cmd(
                150,
                &[4096, 12001, 0, 1, 1, 1, 255, 512, 520],
                &["SystemFile/Button01.png"],
            )],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(host.pictures[0].anchor, 1, "0x1000 anchors the centre");
        assert_eq!(host.pictures[0].kind, 0);
        assert_eq!(host.pictures[0].action, PictureAction::Draw);
    }

    #[test]
    fn picture_text_form_keeps_the_text() {
        let e = event(
            1,
            "picture_text",
            vec![cmd(150, &[0x20, 1, 0, 0], &["こんにちは"])],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(host.pictures[0].kind, 2);
        assert_eq!(host.pictures[0].text, "こんにちは");
        assert!(host.pictures[0].file.is_empty());
    }

    #[test]
    fn se_play_is_non_blocking_and_decodes_the_channel() {
        let e = event(
            1,
            "se",
            vec![
                cmd(140, &[0x0200_0020, 7, 0, 0, 80, 100], &["SE/click"]),
                cmd(121, &[2_000_000, 1, 0, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(host.sounds[0].channel, SoundChannel::Se);
        assert_eq!(host.sounds[0].action, SoundAction::Play);
        assert_eq!(host.sounds[0].file, "SE/click");
        assert_eq!(host.sounds[0].volume, 80, "volume is intArgs[4], not [1]");
        assert_eq!(host.sounds[0].frames, 7, "intArgs[1] is the delay");
        assert_eq!(vm.vars.get(0), 1, "must not block");
    }

    #[test]
    fn bgm_play_reads_the_volume_from_slot_four() {
        let e = event(
            1,
            "bgm",
            vec![cmd(
                140,
                &[0x0200_0000, 10, 0, 0, 70, 100, 0],
                &["BGM/White_Base.mp3"],
            )],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(host.sounds[0].channel, SoundChannel::Bgm);
        assert_eq!(host.sounds[0].action, SoundAction::Play);
        assert_eq!(host.sounds[0].volume, 70);
        assert_eq!(host.sounds[0].frames, 10);
    }

    #[test]
    fn bgm_stop_does_not_index_a_missing_string() {
        let e = event(1, "bgmstop", vec![cmd(140, &[-256, 30], &[])]);
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(host.sounds[0].action, SoundAction::Stop);
        assert_eq!(host.sounds[0].channel, SoundChannel::Bgm);
        assert_eq!(host.sounds[0].frames, 30);
    }

    #[test]
    fn teleport_blocks_one_frame() {
        let e = event(
            1,
            "teleport",
            vec![
                cmd(130, &[-1, 60, 34, 3, 1], &[]),
                cmd(121, &[2_000_000, 1, 0, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        // target, map, x, y, options
        assert_eq!(host.teleports, vec![(-1, 3, 60, 34, 1)]);
        assert_eq!(vm.vars.get(0), 0);
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 1);
    }

    #[test]
    fn self_variables_are_per_instance() {
        let child = event(
            2,
            "child",
            vec![cmd(121, &[1_600_000, 5, 0, 0], &[]), cmd(172, &[], &[])],
        );
        let caller = event(
            1,
            "caller",
            vec![
                cmd(121, &[1_600_000, 1, 0, 0], &[]),
                cmd(210, &[500_002, 0], &[]),
                cmd(121, &[2_000_000, 1_600_000, 0, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![child, caller]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        vm.step_frame(&mut host);
        // v[0] receives the caller's own V6-0, which the child did not touch.
        assert_eq!(vm.vars.get(0), 1);
    }

    #[test]
    fn contains_its_own_budget_so_an_infinite_loop_cannot_hang() {
        let e = event(1, "spin", vec![cmd(170, &[], &[]), cmd(498, &[], &[])]);
        let mut vm = Vm::with_budget(
            {
                let data = wolf_format::commonevent::CommonEventData {
                    version_header: 0x55,
                    version: 0xC9,
                    events: vec![e],
                    footer: 0x90,
                };
                ProgramSet::from_common_events(&data)
            },
            50,
        );
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        let report = vm.step_frame(&mut host);
        assert_eq!(report.steps, 50);
        assert_eq!(vm.instances().len(), 1, "still running, not wedged");
    }

    #[test]
    fn transition_setting_is_installed_by_160_and_blocks_162_for_its_duration() {
        // CE48's default: simple cut, wait flag, 10 frames.
        let e = event(
            1,
            "transition",
            vec![
                cmd(160, &[-1, 0x0001_000A], &[]),
                cmd(161, &[], &[]),
                cmd(162, &[], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        let id = vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.transition.kind, -1);
        assert_eq!(vm.transition.flags, 0x0001_000A);
        assert!(!vm.transition.prepared, "162 clears the prepared flag");
        assert_eq!(vm.instance(id).unwrap().wait, WaitState::Frames(10));
        // Nine more frames tick 10 -> 1, the tenth resolves the wait and the
        // event ends (a common event is reaped once its pc runs past the end).
        for _ in 0..9 {
            vm.step_frame(&mut host);
        }
        assert_eq!(vm.instance(id).unwrap().wait, WaitState::Frames(1));
        vm.step_frame(&mut host);
        assert!(vm.instance(id).is_none());
    }

    #[test]
    fn change_color_reaches_the_host_with_its_packed_colour() {
        // Dungeon event 1: flash, R150 G200 B150, 20 frames.
        let e = event(1, "tint", vec![cmd(151, &[0x0196_C896, 20], &[])]);
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(host.colours, vec![(0x0196_C896, 20)]);
    }

    #[test]
    fn return_to_title_is_surfaced_to_the_host() {
        #[derive(Default)]
        struct TitleHost {
            titled: bool,
        }
        impl Host for TitleHost {
            fn return_to_title(&mut self) {
                self.titled = true;
            }
        }
        let e = event(1, "title", vec![cmd(174, &[], &[])]);
        let mut vm = vm_with(vec![e]);
        let mut host = TitleHost::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert!(host.titled);
        assert_eq!(vm.instances().len(), 0);
    }
}
