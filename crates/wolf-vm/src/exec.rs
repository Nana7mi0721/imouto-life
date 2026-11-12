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
use crate::vars::{EventSelfVars, SelfVars, Variables};

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
    /// `123` with the wait bit: until a key the poll accepts arrives. Cleared at the
    /// start of the next frame so the same instruction runs again.
    Key,
}

/// One open loop of a coroutine (docs/OPCODE_SPEC.md §4.6).
#[derive(Clone, Copy, Debug)]
pub struct LoopCtx {
    /// Index into [Program::blocks].
    pub block: usize,
    /// Remaining iterations; `-1` for an unconditional loop (`170`).
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
    /// True when this coroutine runs as a parallel background event.
    pub is_parallel: bool,
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
            is_parallel: false,
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
    fn lookup_num(&mut self, bank: EscapeBank, index: usize) -> i32 {
        match bank {
            EscapeBank::SelfVar => self.self_vars.get(self.program.self_base + index),
            _ => 0,
        }
    }

    fn lookup_str(&mut self, bank: EscapeBank, index: usize) -> String {
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
    /// Database access for `\cdb`/`\udb`/`\sdb`. `None` keeps tooling that has no
    /// host working; escapes then expand to an empty string.
    host: Option<&'a mut dyn Host>,
}

impl VarLookup for Lookup<'_> {
    fn lookup_num(&mut self, bank: EscapeBank, index: usize) -> i32 {
        match bank {
            EscapeBank::SelfVar => self.inst.self_vars.get(self.inst.program.self_base + index),
            EscapeBank::Var => self.vars.get(index),
            EscapeBank::SysVar => self.vars.get_sys(index),
            // A numeric read of a string bank is a data error; WOLF yields 0.
            EscapeBank::StrVar => 0,
        }
    }

    fn lookup_str(&mut self, bank: EscapeBank, index: usize) -> String {
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

    fn lookup_db(
        &mut self,
        container: crate::exec::DbContainer,
        db_type: i32,
        row: i32,
        column: i32,
    ) -> Option<String> {
        self.host
            .as_mut()
            .and_then(|host| host.database_string(container, db_type, row, column))
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
    /// Where args measures x/y from: see the anchor table in
    /// crates/wolf-game/src/picture.rs.
    pub anchor: u8,
    /// Scaling mode from head bits 20..23. Mode 3 is `別々` (independent X/Y): the
    /// horizontal percentage is the normal scale slot and the vertical one is the
    /// eighteenth argument. Every other mode scales both axes by the same word.
    pub scale_mode: u8,
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
    /// Owning common event id when created by a common event.
    pub owner_event: Option<u32>,
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
    /// Background sound / ambience. WOLF keeps this on its own loop bus so rain or
    /// wind sits under the music instead of replacing it.
    Bgs,
    /// Sound effect.
    Se,
}

/// A decoded `140 PlaySound` instruction.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct SoundCmd {
    /// BGM, BGS or SE.
    pub channel: SoundChannel,
    /// Play or stop.
    pub action: SoundAction,
    /// File name, escapes expanded (empty for a stop).
    pub file: String,
    /// Volume from intArgs[4], 0..=100 in retail data (the editor also stores 200 for a
    /// few loud SE; the mixer clamps at full scale).
    pub volume: i32,
    /// intArgs[1], the shared "fade time / delay" slot: fade-in length for a BGM play,
    /// start delay for an SE play, or fade-out length for a BGM stop. All of these are
    /// honoured by the mixer via `AudioEngine::apply_sound_cmd`; 0 means immediate.
    pub frames: i32,
    /// Playback pitch (tempo) percentage (default 100).
    pub pitch: i32,
}

impl Default for SoundCmd {
    fn default() -> Self {
        Self {
            channel: SoundChannel::Bgm,
            action: SoundAction::Play,
            file: String::new(),
            volume: 100,
            frames: 0,
            pitch: 100,
        }
    }
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
    /// 221/222: the variable address inside the save file, already evaluated.
    /// It is a literal save bank (2_000_000 n, 1_600_000 n, 9_000_000 n) or a
    /// computed database address (1_100_000_000 + type*1_000_000 + row*100 + col).
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

    /// Resolves a system-database sound entry to its file name and volume.
    ///
    /// Opcode 140's sound-type 0 addresses a row of the SystemDB BGM/BGS/SE list
    /// instead of carrying a file name. `db_type` is 1 (BGM), 2 (BGS) or 3 (SE); the
    /// host owns the database, so the interpreter asks rather than guessing. The
    /// default `None` keeps hosts without a database working: the command still
    /// reaches `sound`, with an empty file name, just as an unresolvable file would.
    fn sound_db(&mut self, db_type: i32, entry: u16) -> Option<(String, i32)> {
        let _ = (db_type, entry);
        None
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

    /// Reads one database cell as text, for the `\cdb`/`\udb`/`\sdb` escapes
    /// inside `101` messages and `150` text pictures.
    ///
    /// Kept separate from [`Host::database_cell`] because the text expander runs
    /// while an instruction is decoded and only ever needs the display string.
    /// The default `None` leaves such an escape rendering as an empty string.
    fn database_string(
        &mut self,
        container: DbContainer,
        db_type: i32,
        row: i32,
        column: i32,
    ) -> Option<String> {
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

    /// `160 InstallTransition`: store the setting and load its mask.
    ///
    /// Installing draws nothing and does not block the script; the screen only
    /// moves when `162` executes the setting.
    fn transition_install(&mut self, kind: i32, flags: i32) {
        let _ = (kind, flags);
    }

    /// `161 PrepareTransition`: freeze the screen that is currently drawn.
    fn transition_prepare(&mut self) {}

    /// `162 ExecuteTransition`: start the dissolve and block for its frames.
    fn transition_execute(&mut self) {}

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
    /// [`SaveOp::destination`]; the other two return `None`. The answer is a
    /// [`DbValue`] because a save cell can be textual (a character name) as well
    /// as numeric (a level).
    fn save_load(&mut self, op: &SaveOp) -> Option<DbValue> {
        let _ = op;
        None
    }

    /// `211 CommonEventReserve`: schedule an event to start after this one ends.
    fn reserve(&mut self, event: EventId) {
        let _ = event;
    }

    /// `211 CommonEventReserve`: schedule an event with arguments to start after this one ends.
    fn reserve_with_args(&mut self, event: EventId, args: &[i32], strings: &[String]) {
        let _ = (args, strings);
        self.reserve(event);
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

    /// Key code a script reads for opcode 123, given the poll's decoded option word.
    ///
    /// The value is a CODE, not a bit pattern: 10 decide, 11 cancel, 12 sub, and the
    /// numpad direction codes (2 down, 4 left, 6 right, 8 up), 0 when nothing is
    /// held. The evidence is the developers' own debug comments next to the
    /// comparisons in this game (crates/wolf-game/src/key.rs lists them).
    ///
    /// `query` is the poll's request: which direction keys and action keys it accepts,
    /// whether it blocks, and which input device it reads. `banned` holds the port's
    /// key bits that opcode 126 switched off. Headless hosts return 0, which reads
    /// exactly like "nobody is touching the keyboard".
    fn key_code(&mut self, query: KeyQuery, banned: u32) -> i32 {
        let _ = (query, banned);
        0
    }

    /// Like [`Host::key_code`], with the key bits opcode 125 asked the engine to
    /// press even when the player is not touching the keyboard.
    ///
    /// The interpreter passes its current `InputState::auto_keys` here on every
    /// 123 poll. A host that owns a real keyboard can OR the bits into its held-key
    /// state; the default ignores them, which keeps every headless host unchanged.
    fn key_code_auto(&mut self, query: KeyQuery, auto: u32, banned: u32) -> i32 {
        let _ = auto;
        self.key_code(query, banned)
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

/// The decoded option word of `123 InputKey` (a `キー入力` poll).
///
/// The command's second argument is not a key bitmask. It packs a one-byte option
/// field and a one-byte device field, the same layout the independent
/// `wolfrpg-map-parser` crate calls `BasicOptions` / `InputType`:
///
/// | bits | meaning |
/// | --- | --- |
/// | 0..3 | direction selector: 0 none, 1 four, 2 eight, 3 up, 4 down, 5 left, 6 right, 7 up+down, 8 left+right |
/// | 0x10 | accept the decide key |
/// | 0x20 | accept the cancel key |
/// | 0x40 | accept the sub key |
/// | 0x80 | wait for input (the poll blocks until an accepted key arrives) |
/// | 8..11 | device: 0 basic, 1 keyboard, 2 pad, 3 mouse |
///
/// The game's own debug comments confirm the fields: event 118 polls `0xB0` under
/// "決定かキャンセルか、だけ受付する" (only decide or cancel), event 84 polls `0xB8`
/// (left+right only) and tests nothing but 4 and 6, and event 59 polls `0x10`/`0x20`/
/// `0x40` as three separate single-key checks. See `crates/wolf-game/src/key.rs`.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct KeyQuery {
    /// Raw direction selector, 0..=8 (see the table above).
    pub directions: u8,
    /// Accept the decide key.
    pub ok: bool,
    /// Accept the cancel key.
    pub cancel: bool,
    /// Accept the sub key.
    pub sub: bool,
    /// The poll blocks until an accepted key arrives.
    pub wait: bool,
    /// Input device: 0 basic, 1 keyboard, 2 pad, 3 mouse.
    pub device: u8,
}

impl KeyQuery {
    /// Decode the raw second argument of a `123` command.
    #[must_use]
    pub fn decode(word: u32) -> Self {
        let options = (word & 0xFF) as u8;
        Self {
            directions: options & 0x0F,
            ok: options & 0x10 != 0,
            cancel: options & 0x20 != 0,
            sub: options & 0x40 != 0,
            wait: options & 0x80 != 0,
            device: ((word >> 8) & 0x0F) as u8,
        }
    }

    /// True for a poll that names a device rather than the logical key set.
    #[must_use]
    pub const fn is_device_poll(self) -> bool {
        self.device != 0
    }
}

/// Input policy set by the two input-control opcodes.
///
/// 125 (automatic input) and 126 (input toggle) both carry a one-byte WOLF key
/// layout in their first word — decide 1, cancel 2, sub 4, down 0x10, left 0x20,
/// right 0x40, up 0x80 — and 126 additionally carries a mode in the second byte:
/// 0 = enabled, 1 = no movement, 2 = disabled. The game uses the toggle around
/// cutscenes (map event 0 opens with `126 [247]`, i.e. *enable* every key) and the
/// automatic input to steer a cursor while the mouse hovers a menu row.
///
/// The values stay in WOLF's layout here; the host translates them into its own
/// key bits. `ban_keys` is therefore not the command word: it is the set of inputs
/// a mode-1/2 toggle switched off, and a mode-0 toggle removes them again.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct InputState {
    /// Key bits the script wants pressed even when the player is not pressing them.
    pub auto_keys: u32,
    /// Key bits a `126` toggle switched off.
    pub ban_keys: u32,
    pub auto_keys_ttl: u8,
    pub auto_keys_delivered: Vec<InstanceId>,
}

#[derive(Clone, Debug)]
pub(crate) enum CrossWrite {
    Num {
        event: u32,
        slot: usize,
        value: i32,
    },
    Str {
        event: u32,
        slot: usize,
        value: String,
    },
}

/// Transition setting installed by opcode 160 and consumed by 161/162.
///
/// `kind` is the transition type (`-1` = no mask, the shipped default).
/// `flags` packs the duration in its low 16 bits and the "wait for the
/// transition" bit at 0x1_0000 (the CE48 default is 0x0001_000A = wait, 10
/// frames; `FUN_0045cdd0` stores `arg2 & 0xffff`). WOLF keeps one setting for
/// the whole game: 160 replaces it, 161 prepares the screen freeze and 162
/// executes and blocks for the configured number of frames.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct TransitionState {
    /// Transition type from opcode 160, `-1` for a simple dissolve without a mask.
    pub kind: i32,
    /// Duration (low 16 bits) and wait flag (bit 16).
    pub flags: i32,
    /// True between 161 PrepareTransition and 162 ExecuteTransition.
    pub prepared: bool,
}

impl TransitionState {
    /// Frames 162 blocks for. The engine treats a zero duration as one frame.
    #[must_use]
    pub const fn frames(&self) -> u32 {
        let frames = (self.flags & 0xFFFF) as u32;
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

    /// Copies a common event's durable bank into a freshly created coroutine.
    ///
    /// Map-event pages keep their bank in the map runtime and are handed in through
    /// [Vm::start_program_with_self], so only common-event programs are seeded here.
    fn seed_common_self(&self, inst: &mut Instance) {
        if inst.program.self_base != crate::program::COMMON_SELF_BASE {
            return;
        }
        let Some(bank) = self.vars.common_self.get(&inst.event) else {
            return;
        };
        let base = crate::program::COMMON_SELF_BASE;
        for slot in 0..crate::vars::EVENT_SELF_SLOTS {
            inst.self_vars.set(base + slot, bank.get(slot));
        }
        for slot in 0..crate::vars::EVENT_SELF_STRINGS {
            inst.self_vars.set_str(base + 5 + slot, bank.get_str(slot));
        }
    }

    /// Snapshot of one common-event coroutine's self variables, `None` for a map page.
    fn bank_from(inst: &Instance) -> Option<(EventId, EventSelfVars)> {
        if inst.program.self_base != crate::program::COMMON_SELF_BASE {
            return None;
        }
        let mut bank = EventSelfVars::new();
        let base = crate::program::COMMON_SELF_BASE;
        for slot in 0..crate::vars::EVENT_SELF_SLOTS {
            bank.set(slot, inst.self_vars.get(base + slot));
        }
        for slot in 0..crate::vars::EVENT_SELF_STRINGS {
            bank.set_str(slot, inst.self_vars.get_str(base + 5 + slot));
        }
        Some((inst.event, bank))
    }

    fn apply_cross_writes(instances: &mut [Instance], cross_writes: &[CrossWrite]) {
        for cw in cross_writes {
            match cw {
                CrossWrite::Num { event, slot, value } => {
                    for inst in instances.iter_mut() {
                        if inst.program.self_base == crate::program::COMMON_SELF_BASE
                            && inst.event == *event
                        {
                            inst.self_vars
                                .set(crate::program::COMMON_SELF_BASE + slot, *value);
                        }
                    }
                }
                CrossWrite::Str { event, slot, value } => {
                    for inst in instances.iter_mut() {
                        if inst.program.self_base == crate::program::COMMON_SELF_BASE
                            && inst.event == *event
                        {
                            inst.self_vars
                                .set_str(crate::program::COMMON_SELF_BASE + 5 + slot, value);
                        }
                    }
                }
            }
        }
    }

    /// Copies one instance's self variables back into its event's durable bank.
    #[allow(dead_code)]
    fn save_common_self(&mut self, inst: &Instance) {
        if let Some((event, bank)) = Self::bank_from(inst) {
            self.vars.common_self.insert(event, bank);
        }
    }

    /// Pushes the durable banks into every live common-event coroutine.
    ///
    /// Called after a load. A coroutine that was already running when the save was
    /// restored would otherwise keep its pre-load self variables and write them back
    /// over the loaded bank when it ends.
    pub fn restore_common_self(&mut self) {
        let base = crate::program::COMMON_SELF_BASE;
        for inst in &mut self.instances {
            if inst.program.self_base != base {
                continue;
            }
            let Some(bank) = self.vars.common_self.get(&inst.event) else {
                continue;
            };
            for slot in 0..crate::vars::EVENT_SELF_SLOTS {
                inst.self_vars.set(base + slot, bank.get(slot));
            }
            for slot in 0..crate::vars::EVENT_SELF_STRINGS {
                inst.self_vars.set_str(base + 5 + slot, bank.get_str(slot));
            }
        }
    }

    /// Folds every live common-event coroutine into its durable bank.
    ///
    /// A frame can be saved while a menu or a daily-loop coroutine is still running;
    /// without this the save would miss the changes that coroutine made since it
    /// started.
    pub fn capture_common_self(&mut self) {
        let banks: Vec<(EventId, EventSelfVars)> =
            self.instances.iter().filter_map(Self::bank_from).collect();
        for (event, bank) in banks {
            self.vars.common_self.insert(event, bank);
        }
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
        self.seed_common_self(&mut inst);
        inst.return_to = return_to;
        self.instances.push(inst);
        self.started_events.insert(event);
        self.started_event_total += 1;
        Some(id)
    }

    /// Load a common event with the numeric and string arguments of a `211`.
    ///
    /// `211 CommonEventReserve` starts its event after the current foreground
    /// stack has ended, so this is the same seeding path as a `210` child:
    /// numbers go to CSelf0.. and the durable `common_self` bank, strings to
    /// CSelf5..8. A reservation must not be started by `start_event`, which
    /// would silently drop its arguments.
    pub fn start_event_with_args(
        &mut self,
        event: EventId,
        args: &[i32],
        strings: &[String],
    ) -> Option<InstanceId> {
        let program = Arc::clone(self.programs.event(event)?);
        if self.instances.len() >= MAX_INSTANCES {
            return None;
        }
        let id = self.next_id;
        self.next_id += 1;
        let mut child = Instance::new(id, None, program);
        self.seed_common_self(&mut child);
        self.bind_call_arguments(event, &mut child, args, strings);
        self.instances.push(child);
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

    /// Mark an instance as parallel background coroutine or foreground coroutine.
    pub fn set_instance_parallel(&mut self, id: InstanceId, parallel: bool) {
        if let Some(inst) = self.instances.iter_mut().find(|i| i.id == id) {
            inst.is_parallel = parallel;
        }
    }

    /// Set an instance self variable and keep durable common-self bank in sync.
    pub fn set_instance_self_var(&mut self, id: InstanceId, slot: usize, value: i32) {
        let mut sync_event = None;
        if let Some(inst) = self.instances.iter_mut().find(|i| i.id == id) {
            inst.self_vars.set(slot, value);
            if inst.program.self_base == crate::program::COMMON_SELF_BASE
                && (600..700).contains(&slot)
            {
                sync_event = Some(inst.event);
            }
        }
        if let Some(event) = sync_event {
            self.vars
                .common_self
                .entry(event)
                .or_default()
                .set(slot - 600, value);
            for other in &mut self.instances {
                if other.program.self_base == crate::program::COMMON_SELF_BASE
                    && other.event == event
                    && other.id != id
                {
                    other.self_vars.set(slot, value);
                }
            }
        }
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
        // 125 自動入力 injects a key for up to two frames or until delivered.
        if self.input.auto_keys_ttl > 0 {
            self.input.auto_keys_ttl -= 1;
            if self.input.auto_keys_ttl == 0 {
                self.input.auto_keys = 0;
                self.input.auto_keys_delivered.clear();
            }
        } else {
            self.input.auto_keys = 0;
            self.input.auto_keys_delivered.clear();
        }

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
                WaitState::Key => {
                    // A key poll re-runs its own instruction next frame; there is no
                    // sticky state to keep, the host answers again from live input.
                    self.instances[i].wait = WaitState::None;
                }
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
            let foreground_event = self
                .instances
                .iter()
                .rev()
                .find(|other| {
                    !other.is_parallel
                        && (other.pc < other.program.len() || other.wait != WaitState::None)
                })
                .map(|other| {
                    let common = other.program.self_base == crate::program::COMMON_SELF_BASE;
                    if common {
                        other.event as i32 + 500_000
                    } else {
                        other.event as i32
                    }
                });
            let mut hist: Vec<(usize, u64)> = Vec::new();
            let mut cross_writes = Vec::new();
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
                    foreground_event,
                    &mut cross_writes,
                )
            };
            Self::apply_cross_writes(&mut self.instances, &cross_writes);
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
                    self.instances.clear();
                    return;
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
        self.seed_common_self(&mut child);
        self.bind_call_arguments(target, &mut child, &args, &strings);
        child.return_to = return_to;
        self.instances.push(child);
        self.instances[caller].wait = WaitState::Child(id);
    }

    /// Seed a not-yet-pushed child with the arguments of a `210`/`211`.
    ///
    /// Arguments land in self variable group 6 (magic 1_600_000 + i), not in
    /// group 0 - see magic::SELF_ARG_BASE for the measurement. Strings go to
    /// CSelf5..8 (magic 1_600_005 + k), mirroring the editor's four numeric and
    /// four string input boxes (docs/OPCODE_210_RETURN.md section 8).
    ///
    /// Only the new child receives the call arguments. Another live instance of
    /// the same event keeps its own group-6 values: a bare scheduler instance is
    /// not a callee and must not inherit an unrelated `210` argument.
    fn bind_call_arguments(
        &mut self,
        target: EventId,
        child: &mut Instance,
        args: &[i32],
        strings: &[String],
    ) {
        for (slot, value) in args.iter().enumerate() {
            child
                .self_vars
                .set(crate::magic::SELF_ARG_BASE + slot, *value);
            self.vars
                .common_self
                .entry(target)
                .or_default()
                .set(slot, *value);
        }
        for (slot, text) in strings.iter().take(SELF_ARG_STRING_SLOTS).enumerate() {
            child.self_vars.set_str(SELF_ARG_STRING_BASE + slot, text);
            self.vars
                .common_self
                .entry(target)
                .or_default()
                .set_str(slot, text);
        }
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
                            let mut cross_writes = Vec::new();
                            store_num(
                                &mut self.instances[idx],
                                &mut self.vars,
                                target,
                                value,
                                &mut cross_writes,
                            );
                            Self::apply_cross_writes(&mut self.instances, &cross_writes);
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

/// Resolve the `600_000..=699_999` relative call target of opcode 210/211.
///
/// In WOLF this range names a common event *relative to the caller*: 600_100 means
/// offset zero, so `caller + (raw - 600_100)`. The message-window plugin in this game
/// relies on it heavily - CE264 calls 600101..600104 to reach CE265..CE268 and CE270
/// calls 600094..600098 to reach its own siblings - and interpreting the range as an
/// absolute `raw - 600_000` routed those calls to unrelated menu events. There are 31
/// such call sites in the shipped data (CE75/CE137/CE262 recursive calls included).
fn relative_call_target(raw: i32, caller: EventId) -> EventId {
    (i64::from(caller) + (i64::from(raw) - 600_100)).max(0) as EventId
}

/// Read one magic operand.
fn eval_num(raw: i32, inst: &Instance, vars: &Variables) -> i32 {
    let magic = Magic::decode(raw);
    match magic.kind() {
        MagicKind::Literal => magic.index() as i32,
        MagicKind::SelfVar => inst.self_vars.get(magic.index() as usize),
        MagicKind::Var => vars.get(magic.index() as usize),
        MagicKind::SysVar => vars.get_sys(magic.index() as usize),
        MagicKind::CommonSelf => vars
            .common_self
            .get(&magic.common_event())
            .map_or(0, |bank| bank.get(magic.common_slot())),
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

/// Resolve a `221`/`222` in-save address operand.
///
/// Most address operands are literals that live in a magic bank (2_000_000 n normal
/// variable, 9_000_000 n system variable) and must reach the host unchanged. A few
/// (CE94 pc325/335/338/341) instead pass a *self variable* whose runtime value is a
/// computed database address such as 1_106_000_001. Only that self-variable form is
/// dereferenced; everything else is kept raw so the save bank match still works.
/// Evaluate an opcode-121 arithmetic operand. The exact base value 1_000_000
/// is a literal constant here (see the CE94/CE79 multiply sites); every other
/// operand in the self bank is still resolved through eval_num.
#[allow(dead_code)]
fn eval_arith_operand(raw: i32, inst: &Instance, vars: &Variables) -> i32 {
    if raw == crate::magic::SELF_BASE {
        raw
    } else {
        eval_num(raw, inst, vars)
    }
}

fn eval_arith_operand_host(
    raw: i32,
    inst: &Instance,
    vars: &Variables,
    host: &mut dyn Host,
) -> i32 {
    if raw == crate::magic::SELF_BASE {
        raw
    } else {
        eval_num_host(raw, inst, vars, host)
    }
}

fn eval_save_address(raw: i32, inst: &Instance) -> i32 {
    let magic = Magic::decode(raw);
    if matches!(magic.kind(), MagicKind::SelfVar) {
        inst.self_vars.get(magic.index() as usize)
    } else {
        raw
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
        MagicKind::CommonSelf => {
            let slot = magic.common_slot();
            if (5..=9).contains(&slot) {
                vars.common_self
                    .get(&magic.common_event())
                    .map_or_else(String::new, |bank| bank.get_str(slot - 5).to_owned())
            } else {
                String::new()
            }
        }
        // A numeric bank read as text yields the decimal form, which is what the
        // editor's `cself[n]` expansion does.
        MagicKind::Literal => magic.index().to_string(),
        MagicKind::Var => vars.get(magic.index() as usize).to_string(),
        MagicKind::DbCell | MagicKind::Opaque => String::new(),
    }
}

/// Write one magic operand.
fn store_num(
    inst: &mut Instance,
    vars: &mut Variables,
    raw: i32,
    value: i32,
    cross_writes: &mut Vec<CrossWrite>,
) {
    let magic = Magic::decode(raw);
    match magic.kind() {
        MagicKind::SelfVar => {
            let slot = magic.index() as usize;
            inst.self_vars.set(slot, value);
            if inst.program.self_base == crate::program::COMMON_SELF_BASE
                && (600..700).contains(&slot)
            {
                vars.common_self
                    .entry(inst.event)
                    .or_default()
                    .set(slot - 600, value);
            }
        }
        MagicKind::Var => vars.set(magic.index() as usize, value),
        MagicKind::SysVar => vars.set_sys(magic.index() as usize, value),
        MagicKind::CommonSelf => {
            let ev = magic.common_event();
            let slot = magic.common_slot();
            vars.common_self.entry(ev).or_default().set(slot, value);
            if inst.program.self_base == crate::program::COMMON_SELF_BASE && inst.event == ev {
                inst.self_vars
                    .set(crate::program::COMMON_SELF_BASE + slot, value);
            }
            cross_writes.push(CrossWrite::Num {
                event: ev,
                slot,
                value,
            });
        }
        // Writing to a literal or a sentinel is a no-op in every WOLF build.
        MagicKind::Literal | MagicKind::StrVar | MagicKind::DbCell | MagicKind::Opaque => {}
    }
}

/// Resolve a `122` destination that is itself a variable holding a string address.
///
/// WOLF's 文字列操作 lets the editor pick "代入先を変数で指定": the numeric
/// destination contains a string-variable address such as `3_000_000+n` or a
/// cross-event `15_000_000+...` cell. CE268 pc14 and CE270 pc2000 use this form
/// with a self variable that was computed one instruction earlier. Slots CSelf5..9
/// are the event's real string slots and stay direct, so only the numeric self
/// slots are dereferenced here.
fn resolve_string_target(raw: i32, inst: &Instance) -> i32 {
    let magic = Magic::decode(raw);
    if matches!(magic.kind(), MagicKind::SelfVar) && !(5..=9).contains(&(magic.index() % 100)) {
        let address = inst.self_vars.get(magic.index() as usize);
        if matches!(
            Magic::decode(address).kind(),
            MagicKind::StrVar | MagicKind::SysVar | MagicKind::CommonSelf
        ) {
            return address;
        }
    }
    raw
}

/// Write one magic operand as a string.
fn store_str(
    inst: &mut Instance,
    vars: &mut Variables,
    raw: i32,
    value: &str,
    cross_writes: &mut Vec<CrossWrite>,
) {
    let magic = Magic::decode(raw);
    match magic.kind() {
        MagicKind::StrVar => vars.set_str(magic.index() as usize, value),
        MagicKind::SelfVar => {
            let slot = magic.index() as usize;
            inst.self_vars.set_str(slot, value);
            if inst.program.self_base == crate::program::COMMON_SELF_BASE
                && (605..=609).contains(&slot)
            {
                vars.common_self
                    .entry(inst.event)
                    .or_default()
                    .set_str(slot - 605, value);
            }
        }
        MagicKind::SysVar => vars.set_sys_str(magic.index() as usize, value),
        MagicKind::CommonSelf => {
            let slot = magic.common_slot();
            if (5..=9).contains(&slot) {
                let ev = magic.common_event();
                vars.common_self
                    .entry(ev)
                    .or_default()
                    .set_str(slot - 5, value);
                if inst.program.self_base == crate::program::COMMON_SELF_BASE && inst.event == ev {
                    inst.self_vars
                        .set_str(crate::program::COMMON_SELF_BASE + slot, value);
                }
                cross_writes.push(CrossWrite::Str {
                    event: ev,
                    slot: slot - 5,
                    value: value.to_string(),
                });
            }
        }
        MagicKind::Literal | MagicKind::Var | MagicKind::DbCell | MagicKind::Opaque => {}
    }
}

/// Splits the first line off `text`, dropping the newline that ended it.
fn split_first_line(text: &str) -> (&str, &str) {
    match text.find('\n') {
        Some(at) => (&text[..at], &text[at + 1..]),
        None => (text, ""),
    }
}

/// Length of one display unit at the start of `text`.
///
/// WOLF's `122` cut modes treat a control escape as one character so removing
/// "one character" never leaves half a `\c[1]` behind. Plain text is one UTF-8
/// scalar; a backslash escape runs through its bracketed argument when present.
fn first_unit_len(text: &str) -> usize {
    let mut chars = text.char_indices();
    let Some((_, first)) = chars.next() else {
        return 0;
    };
    if first != '\\' {
        return first.len_utf8();
    }
    // `\name[...]`: consume the letters and the first balanced-looking bracket.
    let rest = &text[1..];
    let mut name_end = 0;
    for (at, ch) in rest.char_indices() {
        if ch.is_ascii_alphabetic() {
            name_end = at + ch.len_utf8();
        } else {
            break;
        }
    }
    if name_end == 0 {
        return first.len_utf8();
    }
    let after = &rest[name_end..];
    if let Some(close) = after.find(']') {
        // `after` starts with '[' for the normal escape form; a stray `]` in
        // plain text must not swallow the rest of the string.
        if after.starts_with('[') {
            return 1 + name_end + close + 1;
        }
    }
    1 + name_end
}

/// Byte offset where the last display unit of `text` starts.
fn last_unit_start(text: &str) -> usize {
    let mut end = 0;
    let mut last = 0;
    while end < text.len() {
        last = end;
        end += first_unit_len(&text[end..]);
    }
    last
}

/// Expand escapes in a string using the instance, the globals and the host's database.
fn expand(raw: &str, inst: &Instance, vars: &Variables, host: &mut dyn Host) -> String {
    let mut lookup = Lookup {
        inst,
        vars,
        host: Some(host),
    };
    text::expand(raw, &mut lookup)
}

/// Expand one opcode 102 option label.
///
/// A bare `\cself[n]` option is an optional action whose label lives in a string
/// slot. When the current branch never wrote that slot, the text expander's numeric
/// fallback would turn the empty label into `0` and paint a phantom sixth row (the
/// retail five-row night menu has exactly this shape). Choice labels therefore use
/// the string-only expansion, while every other escape keeps the normal rules.
fn expand_choice(raw: &str, inst: &Instance, vars: &Variables, host: &mut dyn Host) -> String {
    let mut lookup = Lookup {
        inst,
        vars,
        host: Some(host),
    };
    text::expand_choice(raw, &mut lookup)
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
                // `i32::MIN / -1` overflows; WOLF wraps instead of panicking.
                current.wrapping_div(value)
            }
        }
        0x500 => {
            if value == 0 {
                current
            } else {
                current.wrapping_rem(value)
            }
        }
        // 0x600/0x700 are the two clamps, not assignments. CE132's volume rows
        // write `Sys100 = max(Sys100, 0)` then `Sys100 = min(Sys100, 120)`;
        // treating them as plain assignment pinned the volume at 120 after a single
        // key press (observed: 100 -> 120 instead of 95). Event 36 pairs the same
        // two ops as `v3 = clamp(v3, 1, v82)`.
        0x600 => current.max(value),
        0x700 => current.min(value),
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

/// Floating-point binary operations for opcode 121 in real mode (`実数計算`).
fn binary_op_f64(kind: u8, a: f64, b: f64, rng: &mut WolfRng) -> f64 {
    match kind {
        0x0 => a + b,
        0x1 => a - b,
        0x2 => a * b,
        0x3 => {
            if b == 0.0 {
                a
            } else {
                a / b
            }
        }
        0x4 => {
            if b == 0.0 {
                a
            } else {
                a % b
            }
        }
        0x5 => ((a as i32) & (b as i32)) as f64,
        0x6 => rng.range(a as i32, b as i32) as f64,
        0x7 => ((a as i32) | (b as i32)) as f64,
        0x8 => ((a as i32) ^ (b as i32)) as f64,
        0x9 => ((a as i32).wrapping_shl((b as i32 & 31) as u32)) as f64,
        _ => a,
    }
}

/// Floating-point compound assignment for opcode 121 in real mode (`実数計算`).
fn compound_f64(kind: i32, current: f64, value: f64) -> f64 {
    match kind & 0x0F00 {
        0x000 => value,
        0x100 => current + value,
        0x200 => current - value,
        0x300 => current * value,
        0x400 => {
            if value == 0.0 {
                current
            } else {
                current / value
            }
        }
        0x500 => {
            if value == 0.0 {
                current
            } else {
                current % value
            }
        }
        0x600 => current.max(value),
        0x700 => current.min(value),
        0x800 => value.abs(),
        0x900 => {
            let deg = value.atan2(current).to_degrees();
            (deg * 10.0).trunc()
        }
        0xA00 => {
            let deg = value / 10.0;
            (deg.to_radians().sin() * 1000.0).trunc()
        }
        0xB00 => {
            let deg = value / 10.0;
            (deg.to_radians().cos() * 1000.0).trunc()
        }
        0xC00 => {
            let root = value.max(0.0).sqrt();
            (root * 1000.0).trunc()
        }
        _ => value,
    }
}

/// `111` comparison operators, docs/OPCODE_SPEC.md §3.3.
///
/// Bit 4 of the operator word is a condition-list flag, not part of the comparison.
/// The retail data pins this: CE249 pc3521 compares a variable against `230`, `200`
/// and `0` in that order with operators 1, 1, 17. Reading 17 as equality would turn
/// the final catch-all (`>= 0`) into `== 0`, so the whole 0..199 band would fall into
/// the else branch. Masking the flag leaves `>=`, the reading the thresholds imply.
/// Every other flagged site uses 18 (`0x10 | ==`), where masking is a no-op.
fn compare(lhs: i32, rhs: i32, operator: i32) -> bool {
    match operator & 0x0F {
        0 => lhs > rhs,
        1 => lhs >= rhs,
        2 => lhs == rhs,
        3 => lhs <= rhs,
        4 => lhs < rhs,
        5 => lhs != rhs,
        // Manual 条件分岐（変数）: the branch fires when `(value & compare) ==
        // compare`, i.e. the value covers every bit the compare operand asks for
        // (a compare of 0 therefore always matches). `!= 0` accepted partial
        // overlaps and made 91 shipped sites branch too early.
        6 => (lhs & rhs) == rhs,
        // 7 is not a documented comparison; equality is the least surprising
        // reading for a value the data never uses.
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
    foreground_event: Option<i32>,
    cross_writes: &mut Vec<CrossWrite>,
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
                let block_ref = &program.blocks[block];
                inst.pc = block_ref.end_target(program.len());
                continue;
            }
            Control::LoopEnd { block } => {
                close_loop(inst, block);
                continue;
            }
            Control::LabelJump => {
                let name = expand(
                    cmd.strings.first().map_or("", String::as_str),
                    inst,
                    vars,
                    host,
                );
                match program.labels.get(&name) {
                    Some(target) => {
                        sync_loops_for_jump(&program, inst, *target);
                        inst.pc = *target;
                    }
                    None => {
                        // A 212 label may itself carry an escape (`戻り先\cself[n]`):
                        // comparing the expanded jump against the raw label map would
                        // miss it. The shipped data happens to use static labels with
                        // dynamic jumps, but the reverse is legal WOLF and would have
                        // killed the whole coroutine. Expand the candidates only on a
                        // miss, so the normal path pays nothing.
                        let dynamic = program.label_defs.iter().find_map(|(label, target)| {
                            (label.contains('\\') && expand(label, inst, vars, host) == name)
                                .then_some(*target)
                        });
                        if let Some(target) = dynamic {
                            sync_loops_for_jump(&program, inst, target);
                            inst.pc = target;
                        } else {
                            // A malformed jump is a script bug, not a reason to kill the
                            // whole coroutine (BUG-13): report it and continue after the
                            // 213 so the rest of the event can still finish.
                            host.log(
                                LogLevel::Warn,
                                &format!(
                                    "213 JumpLabel: label `{name}` not found; continuing after it"
                                ),
                            );
                            inst.pc += 1;
                        }
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
                let expanded = expand(raw, inst, vars, host);
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
                    .map(|option| expand_choice(option, inst, vars, host))
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
                let text = expand(
                    cmd.strings.first().map_or("", String::as_str),
                    inst,
                    vars,
                    host,
                );
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
                inst.pc = eval_string_condition(inst, vars, cmd, host);
                None
            }
            121 => {
                let raw_lhs = arg(cmd, 0);
                let raw_rhs1 = arg(cmd, 1);
                let raw_rhs2 = arg(cmd, 2);
                let word = arg(cmd, 3) as u32;

                let flags = word & 0xFF;
                let assign_op = (word & 0x0F00) as i32;
                let bin = ((word >> 12) & 0x0F) as u8;
                let batch_mode = (word & 0x10000) != 0;
                // The range form of a self-variable operation updates the named
                // slot only. CE94 relies on this when it scales its save-slot
                // tenths grid: pc87 divides self22, but self23..25 (y/w/h) must
                // stay in tenths for the renderer (9280x1152, not 928x115).
                // Ordinary variables keep the full contiguous range below.
                let self_range = batch_mode && Magic::decode(raw_lhs).kind() == MagicKind::SelfVar;

                let v1 = if (flags & 0x04) != 0 {
                    raw_rhs1
                } else {
                    let addr1 = if (flags & 0x20) != 0 {
                        eval_num(raw_rhs1, inst, vars)
                    } else {
                        raw_rhs1
                    };
                    eval_arith_operand_host(addr1, inst, vars, host)
                };

                let v2 = if (flags & 0x08) != 0 {
                    raw_rhs2
                } else {
                    let addr2 = if (flags & 0x40) != 0 {
                        eval_num(raw_rhs2, inst, vars)
                    } else {
                        raw_rhs2
                    };
                    eval_arith_operand_host(addr2, inst, vars, host)
                };

                if !batch_mode
                    && raw_lhs == crate::magic::DB_VALUE_BASE
                    && argc(cmd) >= 7
                    && (flags & 0x10) == 0
                {
                    let db_type = eval_num(arg(cmd, 4), inst, vars);
                    let row = eval_num(arg(cmd, 5), inst, vars);
                    let column = eval_num(arg(cmd, 6), inst, vars);
                    let current = host
                        .database_cell(DbContainer::CData, db_type, row, column)
                        .unwrap_or(0);
                    let value = if (flags & 0x02) != 0 {
                        let rhs_f = binary_op_f64(bin, v1 as f64, v2 as f64, rng);
                        compound_f64(assign_op, current as f64, rhs_f) as i32
                    } else {
                        let rhs = if bin == 6 {
                            rng.range(v1, v2)
                        } else {
                            binary_op(bin, v1, v2)
                        };
                        compound(assign_op, current, rhs)
                    };
                    let value = if (flags & 0x01) != 0 {
                        value.clamp(-999_999, 999_999)
                    } else {
                        value
                    };
                    host.set_database_cell(DbContainer::CData, db_type, row, column, value);
                    inst.pc += 1;
                    None
                } else {
                    let batch_count = if batch_mode && !self_range {
                        arg(cmd, 4).max(0) as i32
                    } else {
                        0
                    };
                    for offset in 0..=batch_count {
                        let lhs_raw = raw_lhs.wrapping_add(offset);
                        let target = if (flags & 0x10) != 0 {
                            eval_num(lhs_raw, inst, vars)
                        } else {
                            lhs_raw
                        };
                        let current = eval_num_host(target, inst, vars, host);
                        let value = if (flags & 0x02) != 0 {
                            let rhs_f = binary_op_f64(bin, v1 as f64, v2 as f64, rng);
                            compound_f64(assign_op, current as f64, rhs_f) as i32
                        } else {
                            let rhs = if bin == 6 {
                                rng.range(v1, v2)
                            } else {
                                binary_op(bin, v1, v2)
                            };
                            compound(assign_op, current, rhs)
                        };
                        let value = if (flags & 0x01) != 0 {
                            value.clamp(-999_999, 999_999)
                        } else {
                            value
                        };
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
                            store_num(inst, vars, target, value, cross_writes);
                        }
                    }
                    inst.pc += 1;
                    None
                }
            }
            122 => {
                // 122 SetString. The mode word is a bitfield: the operation is
                // `mode & 0xFFF0` and the low nibble selects the right-hand operand
                // (0 literal, 1 string variable, 2 string variable addressed by a
                // numeric variable, 3 keyboard input). Note the first-line cut is
                // operation 0x0010, so masking with 0xFF00 would fold 17/18 into the
                // plain-assignment operation 0; the manual lists 上1行切り取り as its
                // own operation and CE268 uses mode 17 for exactly that.
                let target = resolve_string_target(arg(cmd, 0), inst);
                let mode = arg(cmd, 1);
                let source = arg(cmd, 2);
                let operation = mode & 0xFFF0;
                let source_kind = mode & 0x0F;
                let mut literal = |cmd: &Command| {
                    cmd.strings
                        .first()
                        .map_or(String::new(), |raw| expand(raw, inst, vars, host))
                };
                // A non-literal right-hand side resolves to one string-variable
                // address. Kind 2 is the manual's "read the position from a
                // variable": the numeric operand holds a `3_000_000+n` string code.
                let string_source: Option<i32> = match (source_kind, argc(cmd) >= 3) {
                    (1, true) => Some(source),
                    (2, true) => {
                        let address = eval_num(source, inst, vars);
                        matches!(
                            Magic::decode(address).kind(),
                            MagicKind::StrVar | MagicKind::SysVar | MagicKind::CommonSelf
                        )
                        .then_some(address)
                    }
                    _ => None,
                };
                // Reads the right-hand operand for the operations that take one.
                let mut read_source = || match string_source {
                    Some(address) => eval_str(address, inst, vars),
                    None => literal(cmd),
                };
                // Writes the shortened text back into the source variable, which is
                // what makes the "cut" half of an operation work. A literal or
                // keyboard source has nowhere to go and is simply ignored.
                let write_back =
                    |inst: &mut Instance,
                     vars: &mut Variables,
                     text: &str,
                     cross_writes: &mut Vec<CrossWrite>| {
                        if let Some(address) = string_source {
                            store_str(inst, vars, address, text, cross_writes);
                        }
                    };
                match operation {
                    // Assignment: `=`, `= string var`, `= number`.
                    0x0000 => {
                        let value = read_source();
                        store_str(inst, vars, target, &value, cross_writes);
                    }
                    // Append (`+=`): the existing destination is kept.
                    0x0100 => {
                        let value = read_source();
                        let mut combined = eval_str(target, inst, vars);
                        combined.push_str(&value);
                        store_str(inst, vars, target, &combined, cross_writes);
                    }
                    // `上1行切り取り`: move the first line to the destination and
                    // remove it (plus its newline) from the source.
                    0x0010 => {
                        let text = read_source();
                        let (line, rest) = split_first_line(&text);
                        store_str(inst, vars, target, line, cross_writes);
                        write_back(inst, vars, rest, cross_writes);
                    }
                    // `上1行コピー`: same split, source untouched.
                    0x0300 => {
                        let text = read_source();
                        let (line, _) = split_first_line(&text);
                        store_str(inst, vars, target, line, cross_writes);
                    }
                    // `に↓から1文字切り出し`: move one character (a whole escape
                    // unit) from the front of the source into the destination. The
                    // manual is explicit that the source loses that character; the
                    // typewriter in CE212 cuts the next glyph into self9 this way.
                    0x0400 => {
                        let text = read_source();
                        let count = first_unit_len(&text);
                        let (cut, rest) = text.split_at(count);
                        store_str(inst, vars, target, cut, cross_writes);
                        write_back(inst, vars, rest, cross_writes);
                    }
                    // `に↓から最後1文字切り出し`: move the last character (or escape
                    // unit) into the destination and remove it from the source.
                    0x0500 => {
                        let text = read_source();
                        let at = last_unit_start(&text);
                        let (rest, cut) = text.split_at(at);
                        store_str(inst, vars, target, cut, cross_writes);
                        write_back(inst, vars, rest, cross_writes);
                    }
                    // `から↓の文字列を全消去`: delete every occurrence.
                    0x0800 => {
                        let needle = literal(cmd);
                        let mut text = eval_str(target, inst, vars);
                        if !needle.is_empty() {
                            text = text.replace(&needle, "");
                        }
                        store_str(inst, vars, target, &text, cross_writes);
                    }
                    // `から以下の文字列を置換`: two string operands.
                    0x0900 => {
                        let from = cmd
                            .strings
                            .first()
                            .map_or(String::new(), |raw| expand(raw, inst, vars, host));
                        let to = cmd
                            .strings
                            .get(1)
                            .map_or(String::new(), |raw| expand(raw, inst, vars, host));
                        let text = eval_str(target, inst, vars);
                        let replaced = if from.is_empty() {
                            text
                        } else {
                            text.replace(&from, &to)
                        };
                        store_str(inst, vars, target, &replaced, cross_writes);
                    }
                    // `から指定文字まで切り出し`: keep the text before the first
                    // marker. The manual specifies `<<NotFound>>` for a miss.
                    0x0A00 => {
                        let marker = literal(cmd);
                        let text = eval_str(target, inst, vars);
                        let value = match text.find(&marker) {
                            Some(at) if !marker.is_empty() => text[..at].to_owned(),
                            _ => "<<NotFound>>".to_owned(),
                        };
                        store_str(inst, vars, target, &value, cross_writes);
                    }
                    // `の指定文字以降を切り出し`: keep the text after the first marker.
                    0x0B00 => {
                        let marker = literal(cmd);
                        let text = eval_str(target, inst, vars);
                        let value = match text.find(&marker) {
                            Some(at) if !marker.is_empty() => text[at + marker.len()..].to_owned(),
                            _ => "<<NotFound>>".to_owned(),
                        };
                        store_str(inst, vars, target, &value, cross_writes);
                    }
                    // Unknown operation: keep the old plain-assignment behaviour
                    // rather than silently blanking the destination.
                    _ => {
                        let value = read_source();
                        store_str(inst, vars, target, &value, cross_writes);
                    }
                }
                inst.pc += 1;
                None
            }
            123 => {
                // Key-input poll (docs/OPCODE_SPEC.md 5.13). The destination receives
                // the CODE of the held key, not a bit pattern - the game compares it
                // against 10/11/12 and the numpad direction codes, which is why the
                // old "key_bits & mask" model could never take a branch. A headless
                // host reports 0, exactly like an untouched keyboard.
                //
                // The option word is decoded here so the host only sees the request:
                // which keys count, whether the poll waits, and which device it reads.
                let target = arg(cmd, 0);
                let query = KeyQuery::decode(arg(cmd, 1) as u32);
                let effective_auto =
                    if input.auto_keys != 0 && !input.auto_keys_delivered.contains(&inst.id) {
                        input.auto_keys
                    } else {
                        0
                    };
                let code = host.key_code_auto(query, effective_auto, input.ban_keys);
                if input.auto_keys != 0 && !input.auto_keys_delivered.contains(&inst.id) {
                    input.auto_keys_delivered.push(inst.id);
                }
                store_num(inst, vars, target, code, cross_writes);
                // A wait poll (`入力を待つ`) blocks the coroutine until a key it accepts
                // arrives. Event 249's pause overlay polls 0x91 and never reads the
                // result: it exists purely to hold the scene until the player presses a
                // key, which is how the shipped game paces that scene.
                if query.wait && code == 0 {
                    inst.wait = WaitState::Key;
                    Some(Signal::Blocked)
                } else {
                    inst.pc += 1;
                    None
                }
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
                // The high nibble selects the query family; bits 8..11 are the
                // compound-assignment operator (0 assign, 1 add, 2 sub, 3 mul,
                // 4 div, 5 rem). CE48 uses the plain forms, but the editor also
                // emits 0x1200/0x4400 when a script reads and updates one field.
                let value = match sub & 0xF000 {
                    0x3000 => {
                        // Fields 17/18 name the running event, which only the
                        // interpreter knows. 17 is "this common-event id" (-1 for a
                        // map event); 18 is "the event being processed", with
                        // +500000 for common events (manual 04ev_valuenext §7).
                        // The balloon library writes its state through
                        // 15_000_000 + 100*this_id + slot, so field 17 is not
                        // optional: without it every child addressed CE1's bank.
                        let common = inst.program.self_base == crate::program::COMMON_SELF_BASE;
                        if field == 17 {
                            Some(if common { inst.event as i32 } else { -1 })
                        } else if field == 18 {
                            if let Some(val) = host.engine_state(18) {
                                Some(val)
                            } else if let Some(val) = foreground_event {
                                Some(val)
                            } else {
                                Some(if common {
                                    inst.event as i32 + 500_000
                                } else {
                                    inst.event as i32
                                })
                            }
                        } else {
                            host.engine_state(field)
                        }
                    }
                    0x1000 => {
                        let object = if argc(cmd) >= 4 {
                            eval_num(arg(cmd, 2), inst, vars)
                        } else {
                            0
                        };
                        host.character_state(object, field)
                    }
                    0x4000 => {
                        let object = if argc(cmd) >= 4 {
                            eval_num(arg(cmd, 2), inst, vars)
                        } else {
                            0
                        };
                        host.picture_state(object, field)
                    }
                    _ => {
                        host.log(
                            LogLevel::Info,
                            &format!("124 SetVariableEx: sub-op {sub:#x} unused in this game"),
                        );
                        None
                    }
                };
                // `None` deliberately leaves the destination alone: the original engine does
                // not write anything when the queried object does not exist (§3.1).
                if let Some(value) = value {
                    let current = eval_num(target, inst, vars);
                    let value = compound(sub, current, value);
                    store_num(inst, vars, target, value, cross_writes);
                }
                inst.pc += 1;
                None
            }
            125 => {
                // Automatic input: the option byte names the keys the script wants held
                // (WOLF layout: decide 1, cancel 2, sub 4, down 0x10, left 0x20,
                // right 0x40, up 0x80). Only the host can force a press, because it
                // owns the real keyboard.
                let bits = arg(cmd, 0) as u32 & 0xFF;
                input.auto_keys = bits;
                input.auto_keys_ttl = if bits != 0 { 2 } else { 0 };
                input.auto_keys_delivered.clear();
                inst.pc += 1;
                None
            }
            126 => {
                // Input toggle, NOT a ban mask. Byte 0 names the keys (same layout as
                // 125), byte 1 is the mode: 0 = all enabled, 1 = no movement,
                // 2 = all disabled. The shipped scripts disable movement around a
                // cutscene and re-enable it later with mode 0, so treating the whole
                // word as a ban bitmask silenced every key for the rest of the game
                // (map event 0 opens with `126 [247]`, which is *enable all*).
                let word = arg(cmd, 0) as u32;
                let inputs = word & 0xFF;
                let mode = (word >> 8) & 0xFF;
                if mode == 0 {
                    input.ban_keys &= !inputs;
                } else {
                    input.ban_keys |= inputs;
                }
                inst.pc += 1;
                None
            }
            130 => {
                // Raw layout is target, x, y, map, options - not map-first.
                host.teleport(
                    eval_num(arg(cmd, 0), inst, vars),
                    eval_num(arg(cmd, 3), inst, vars),
                    eval_num(arg(cmd, 1), inst, vars),
                    eval_num(arg(cmd, 2), inst, vars),
                    arg(cmd, 4),
                );
                // The map load is instant in the original; one frame of slack
                // keeps the host from having to re-enter the interpreter.
                inst.wait = WaitState::Frames(1);
                inst.pc += 1;
                Some(Signal::Blocked)
            }
            140 => {
                let bits = arg(cmd, 0);
                let fade_or_delay = eval_num(arg(cmd, 1), inst, vars).max(0);
                let db_id = eval_num(arg(cmd, 2), inst, vars);
                let raw_vol = if argc(cmd) >= 5 {
                    eval_num(arg(cmd, 4), inst, vars)
                } else {
                    0
                };
                let raw_pitch = if argc(cmd) >= 6 {
                    eval_num(arg(cmd, 5), inst, vars)
                } else {
                    0
                };

                let channel = match bits & 0xF0 {
                    0x10 => SoundChannel::Bgs,
                    0x20 => SoundChannel::Se,
                    _ => SoundChannel::Bgm,
                };
                let sound_type = ((bits >> 24) & 0xFF) as u8;
                let process_type = (bits & 0x0F) as u8;
                let entry = ((bits >> 8) & 0xFFFF) as u16;
                let db_type = match bits & 0xF0 {
                    0x10 => 2, // BGS list
                    0x20 => 3, // SE list
                    _ => 1,    // BGM list
                };

                if process_type == 1 && sound_type != 0xFF {
                    // Preload is a no-op
                    inst.pc += 1;
                    None
                } else {
                    let is_stop = sound_type == 0xFF
                        || process_type == 2
                        || process_type == 3
                        || (sound_type == 0 && entry == 0xFFFF)
                        || (sound_type == 1 && db_id < 0);

                    if is_stop {
                        host.sound(&SoundCmd {
                            channel,
                            action: SoundAction::Stop,
                            file: String::new(),
                            volume: 0,
                            frames: fade_or_delay,
                            pitch: 100,
                        });
                    } else {
                        let (file, volume, pitch) = match sound_type {
                            0 => {
                                let (file, db_volume) =
                                    host.sound_db(db_type, entry).unwrap_or_default();
                                let mut vol = if argc(cmd) >= 5 && raw_vol > 0 {
                                    raw_vol
                                } else {
                                    db_volume
                                };
                                if vol == 0 {
                                    vol = 100;
                                }
                                let p = if raw_pitch > 0 { raw_pitch } else { 100 };
                                (file, vol, p)
                            }
                            1 => {
                                let (file, db_volume) =
                                    host.sound_db(db_type, db_id as u16).unwrap_or_default();
                                let mut vol = if argc(cmd) >= 5 && raw_vol > 0 {
                                    raw_vol
                                } else {
                                    db_volume
                                };
                                if vol == 0 {
                                    vol = 100;
                                }
                                let p = if raw_pitch > 0 { raw_pitch } else { 100 };
                                (file, vol, p)
                            }
                            _ => {
                                let file = expand(
                                    cmd.strings.first().map_or("", String::as_str),
                                    inst,
                                    vars,
                                    host,
                                );
                                let vol = if argc(cmd) >= 5 && raw_vol > 0 {
                                    raw_vol
                                } else {
                                    100
                                };
                                let p = if raw_pitch > 0 { raw_pitch } else { 100 };
                                (file, vol, p)
                            }
                        };
                        host.sound(&SoundCmd {
                            channel,
                            action: SoundAction::Play,
                            file,
                            volume,
                            frames: fade_or_delay,
                            pitch,
                        });
                    }
                    inst.pc += 1;
                    None
                }
            }
            150 => {
                let decoded = decode_picture(inst, vars, cmd, host);
                host.picture(&decoded);
                inst.pc += 1;
                None
            }
            151 => {
                host.change_color(arg(cmd, 0), eval_num(arg(cmd, 1), inst, vars));
                inst.pc += 1;
                None
            }
            160 => {
                // 160 installs the setting; it does not block and draws nothing.
                // CE48 starts every game with [-1, 0x0001_000A]: simple cut, wait,
                // 10 frames (docs/OPCODE_SPEC.md section 5.20).
                transition.kind = eval_num(arg(cmd, 0), inst, vars);
                transition.flags = eval_num(arg(cmd, 1), inst, vars);
                host.transition_install(transition.kind, transition.flags);
                inst.pc += 1;
                None
            }
            161 => {
                // PrepareTransition freezes the drawn screen while event
                // processing continues. The host owns the actual freeze.
                transition.prepared = true;
                host.transition_prepare();
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
                host.transition_execute();
                inst.wait = WaitState::Frames(frames);
                inst.pc += 1;
                Some(Signal::Blocked)
            }
            170 => {
                // Unconditional loop head. Control::Block pushed nothing yet:
                // enter_block handles the push, so reaching here means the jump
                // table was not built (a hand-made Program). Treat as fallthrough.
                inst.pc += 1;
                None
            }
            176 => {
                // Continue the innermost loop (jump to head or close if counted loop exhausted).
                if let Some(ctx) = inst.loops.last().copied() {
                    close_loop(inst, ctx.block);
                } else {
                    host.log(LogLevel::Warn, "176 ContinueLoop outside any loop");
                    inst.pc += 1;
                }
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
                let frames = eval_num(arg(cmd, 0), inst, vars);
                if frames <= 0 {
                    inst.pc += 1;
                    None
                } else {
                    inst.wait = WaitState::Frames(frames as u32);
                    inst.pc += 1;
                    Some(Signal::Blocked)
                }
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
                    // 600_000..=699_999 is a call relative to the caller: the message
                    // plugins in this game use 600_100 as offset 0 and address their
                    // siblings as caller + (raw - 600_100). CE264 (the message window
                    // interface) calls 600101..600104 for CE265..CE268, and CE270 calls
                    // 600094..600098 for CE264..CE268; the old `raw - 600_000` sent every
                    // one of those calls to an unrelated event (600104 became CE104,
                    // the protagonist menu setup). 31 sites use this form.
                    600_000..=699_999 => Some(relative_call_target(raw, inst.event)),
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
                    600_000..=699_999 => relative_call_target(raw, inst.event),
                    _ => raw.max(0) as EventId,
                };
                let (args, strings, _return_to) = call_arguments(cmd, inst, vars);
                host.reserve_with_args(target, &args, &strings);
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
                let is_map = inst.program.self_base == crate::program::MAP_SELF_BASE;
                let file_raw = arg(cmd, 1);
                let file = if Magic::is_string_slot(file_raw, is_map) {
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
                    // The address is a *value*, not a raw operand: it is either a
                    // literal save-bank address (9000029 = Sys29 play time) or a
                    // self variable that holds a computed database address such as
                    // 1_106_000_001 (CDataBase type 6, row 0, col 1). Evaluating it
                    // here lets the host resolve both (docs/OPCODE_220_SAVE.md section 4).
                    address: if opcode == 220 {
                        0
                    } else {
                        eval_save_address(arg(cmd, 2), inst)
                    },
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
                let answer = host.save_load(&op);
                if let Some(answer) = answer {
                    match answer {
                        DbValue::Num(value) => {
                            store_num(inst, vars, op.destination, value, cross_writes)
                        }
                        DbValue::Str(text) => {
                            store_str(inst, vars, op.destination, &text, cross_writes)
                        }
                    }
                }
                inst.pc += 1;
                // A save cannot be written while the interpreter is inside the host
                // call, so the game queues it and flushes at frame end. CE131 then
                // redraws the slot grid in the *same* command stream (pc 82), and the
                // grid's 221 existence probe still saw the old file: the just-saved
                // slot kept reading 没有数据 until the player left and re-entered.
                // Blocking the saver for one frame lets the flush land before the
                // redraw. The script already waits 16+9 frames around the save, so
                // the extra tick is invisible.
                if opcode == 220 && op.mode == 0 {
                    inst.wait = WaitState::Frames(1);
                    Some(Signal::Blocked)
                } else {
                    None
                }
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
                        let is_map = inst.program.self_base == crate::program::MAP_SELF_BASE;
                        let raw = arg(cmd, 4);
                        if Magic::is_string_slot(raw, is_map) {
                            (None, Some(DbValue::Str(eval_str(raw, inst, vars))))
                        } else {
                            (None, Some(DbValue::Num(eval_num(raw, inst, vars))))
                        }
                    }
                    DbDirection::Write => (
                        None,
                        Some(DbValue::Str(
                            cmd.strings
                                .first()
                                .map_or(String::new(), |raw| expand(raw, inst, vars, host)),
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
                        DbValue::Num(value) => store_num(inst, vars, target, value, cross_writes),
                        DbValue::Str(text) => store_str(inst, vars, target, &text, cross_writes),
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
                let name = expand(
                    cmd.strings.first().map_or("", String::as_str),
                    inst,
                    vars,
                    host,
                );
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
                let milliseconds = eval_num(arg(cmd, 1), inst, vars);
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
                inst.pc = eval_string_condition(inst, vars, cmd, host);
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
                .map(|option| expand_choice(option, inst, vars, host))
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

/// Rebuild the loop stack around a `213 JumpLabel` target.
///
/// WOLF's loop contexts are lexical: a jump out of a loop body has left that
/// loop, and a jump *into* a loop body (common event 63's message-window
/// subroutine does this to return to its main loop) is inside it again. Only
/// contexts whose block body contains `target` may stay; missing enclosing loops
/// are added. The official manual says entering a counted loop from outside does
/// not carry its configured count: the remainder runs once, while the endless
/// `170` form keeps looping.
fn sync_loops_for_jump(program: &Program, inst: &mut Instance, target: usize) {
    let mut enclosing: Vec<usize> = program
        .blocks
        .iter()
        .enumerate()
        .filter(|(_, block)| {
            block.kind == BlockKind::Loop && target > block.head && target <= block.end_pc
        })
        .map(|(index, _)| index)
        .collect();
    enclosing.sort_by_key(|index| program.blocks[*index].head);
    let mut rebuilt = Vec::with_capacity(enclosing.len());
    for index in enclosing {
        if let Some(ctx) = inst.loops.iter().find(|ctx| ctx.block == index) {
            rebuilt.push(*ctx);
            continue;
        }
        let head = program.blocks[index].head;
        let remaining = if program.slots[head].opcode() == 179 {
            1
        } else {
            -1
        };
        rebuilt.push(LoopCtx {
            block: index,
            remaining,
        });
    }
    inst.loops = rebuilt;
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
    // A negative count is an endless loop (170), which must always jump back;
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

/// `112`: string conditional branch (文字列条件分岐). `argc == 1 + (head & 0x0F)`
/// stores literal right-hand strings in `cmd.strings`; the extra-word layout used
/// by CE270 stores a pair of string-variable operands per condition. The same
/// 401/420/499 block skeleton as `111` is shared by both. The game really does
/// use it: 123 sites in the common events and 21 in the map pages, which is why
/// it has to share the block stack (see `from_slots`).
fn eval_string_condition(
    inst: &mut Instance,
    vars: &mut Variables,
    cmd: &Command,
    host: &mut dyn Host,
) -> usize {
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
    // The operand word packs the comparison mode in the top nibble, a variable-type
    // flag in bit 24, and the string variable in the remaining bits:
    // 0x11186A05 is "CSelf5, not equal". Masking 0x00FF_FFFF leaves the actual
    // string magic; leaving bit 24 in place makes Magic::decode look past the end
    // of the self bank and return an empty string. A command with no literal for
    // this condition carries the right-hand string variable as the next argument
    // (CE270 compares CSelf5 with SysStr25 to detect a new message).
    // Two layouts share this opcode. With only `1 + count` words the compared
    // strings are the command's string table; with extra words each condition is a
    // pair of string-variable operands (CE270 compares CSelf5 with SysStr25 to spot
    // a new message). The argument count, not the presence of an empty literal,
    // distinguishes them.
    let rhs_variables = argc(cmd) > 1 + count;
    for i in 0..count {
        let raw = arg(cmd, if rhs_variables { 1 + i * 2 } else { 1 + i });
        let mode = ((raw as u32) >> 28) & 0x0F;
        let lhs = eval_str(raw & 0x00FF_FFFF, inst, vars);
        let rhs = if rhs_variables {
            let right = arg(cmd, 2 + i * 2);
            eval_str(right & 0x00FF_FFFF, inst, vars)
        } else {
            cmd.strings
                .get(i)
                .map_or(String::new(), |raw| expand(raw, inst, vars, host))
        };
        let equal = lhs == rhs;
        // Mode 1 is WOLF's "異なる" (not equal); modes we have not identified keep
        // the historical equality test rather than inventing a comparison.
        let hit = if mode == 1 { !equal } else { equal };
        if hit {
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

fn decode_picture(
    inst: &Instance,
    vars: &Variables,
    cmd: &Command,
    host: &mut dyn Host,
) -> PictureCmd {
    let head = arg(cmd, 0);
    let kind = ((head >> 4) & 0x07) as u8;
    // Bits 12..14 of the head word anchor the picture: 0 means x/y is the top-left corner,
    // 1 (0x1000) means it is the centre. Measured over 13,637 long-form draws - the 0x1000
    // group sits on x=512 / y=288 (the logical screen centre), and the retail title hint
    // banner only lines up when its 606x35 image is centred on (512, 520).
    let anchor = ((head >> 12) & 0x07) as u8;
    // Bits 20..23 select the scaling mode. Mode 0 is uniform (`ScaleX == ScaleY`),
    // mode 3 is the editor's `別々` (independent X/Y, with the vertical percentage in
    // raw argument 18), mode 4 is free-transform and keeps the uniform fallback here.
    let scale_mode = ((head >> 20) & 0x0F) as u8;
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
    let expanded = expand(raw, inst, vars, host);
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
    let owner_event = if inst.program.self_base == crate::program::COMMON_SELF_BASE {
        Some(inst.event)
    } else {
        None
    };
    PictureCmd {
        number,
        kind,
        action,
        file,
        text,
        args,
        anchor,
        scale_mode,
        animate,
        keep_shift,
        relative,
        owner_event,
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

    #[test]
    fn op122_advanced_modes_move_the_right_text_and_keep_the_manual_direction() {
        // Manual (文字列操作): 上1行切り取り / コピー take the source's first line;
        // に↓から1文字切り出し takes the source's first character into the destination
        // and deletes it from the source, and the 最後 variant does the same from the
        // end. から指定文字まで/以降 keep the text before/after the marker.
        let ev = event(
            9,
            "string ops",
            vec![
                cmd(122, &[3_000_000], &["abc"]),
                // First char: s1 <- "a", s0 becomes "bc".
                cmd(122, &[3_000_001, 0x0401, 3_000_000], &[]),
                // Last char: s2 <- "c", s0 becomes "b".
                cmd(122, &[3_000_002, 0x0501, 3_000_000], &[]),
                cmd(122, &[3_000_006, 1, 3_000_000], &[]),
                cmd(
                    122,
                    &[3_000_000],
                    &["one
two"],
                ),
                cmd(122, &[3_000_003, 0x0011, 3_000_000], &[]),
                cmd(122, &[3_000_007, 1, 3_000_000], &[]),
                cmd(
                    122,
                    &[3_000_000],
                    &["one
two"],
                ),
                cmd(122, &[3_000_004, 0x0301, 3_000_000], &[]),
                cmd(122, &[3_000_000], &["aXbXc"]),
                cmd(122, &[3_000_000, 0x0800], &["X"]),
                cmd(122, &[3_000_000], &["a,b,c"]),
                cmd(122, &[3_000_000, 0x0900], &[",", "Y"]),
                cmd(122, &[3_000_000], &["あいうえお"]),
                cmd(122, &[3_000_000, 0x0A00], &["う"]),
                cmd(122, &[3_000_000], &["あいうえお"]),
                cmd(122, &[3_000_000, 0x0B00], &["う"]),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        vm.start_event(9).unwrap();
        vm.step_frame(&mut Recorder::default());
        assert_eq!(vm.vars.get_str(1), "a");
        assert_eq!(vm.vars.get_str(2), "c");
        assert_eq!(vm.vars.get_str(6), "b");
        assert_eq!(vm.vars.get_str(3), "one");
        assert_eq!(vm.vars.get_str(7), "two");
        assert_eq!(vm.vars.get_str(4), "one");
        assert_eq!(vm.vars.get_str(0), "えお");
    }

    #[test]
    fn comparison_operators_match_the_manual() {
        // 条件分岐（変数）orders the seven comparisons >, >=, ==, <=, <, !=, bit
        // product. Bit 4 is a condition-list flag, not part of the comparison.
        assert!(compare(3, 3, 1));
        assert!(compare(3, 3, 17), "17 is >= with the flag bit set");
        assert!(!compare(2, 3, 17));
        // Bit product is `(value & compare) == compare`, not a non-zero overlap:
        // 5 (101) covers 1 (001) but not 3 (011).
        assert!(compare(5, 1, 6));
        assert!(!compare(5, 3, 6));
        assert!(compare(5, 0, 6), "a zero compare always matches");
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
        // Canned answer for a 140 SystemDB sound entry: (db_type, entry) -> file, volume.
        sound_db: Option<(String, i32)>,
        // Every SystemDB sound lookup the interpreter made: (db_type, entry).
        sound_db_queries: Vec<(i32, u16)>,
        // Canned engine answers for 124 0x3000, keyed by field.
        engine_answers: Vec<(i32, i32)>,
        // Canned character answers for 124 0x1000/0x1200, keyed by (target, field).
        character_answers: Vec<(i32, i32, Option<i32>)>,
        // Every (target, field) pair 124 actually asked about.
        character_queries: Vec<(i32, i32)>,
        // Every 160 TransitionInstall: (kind, flags).
        transition_installs: Vec<(i32, i32)>,
        // Every 1000 ProFeature: (kind, milliseconds).
        pro_features: Vec<(i32, i32)>,
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
        save_answer: Option<DbValue>,
        // Every 290 effect the interpreter decoded: (type, duration, evaluated args).
        effects: Vec<(i32, i32, Vec<i32>)>,
        // Every 123 poll the host answered: (mask, auto-input bits).
        key_polls: Vec<(KeyQuery, u32, u32)>,
        // Every 151 ChangeColor: (packed colour, frames).
        colours: Vec<(i32, i32)>,
        // Every 211 CommonEventReserve: (event, args, strings).
        reserves: Vec<(EventId, Vec<i32>, Vec<String>)>,
    }

    impl Host for Recorder {
        fn reserve(&mut self, event: EventId) {
            self.reserves.push((event, Vec::new(), Vec::new()));
        }
        fn reserve_with_args(&mut self, event: EventId, args: &[i32], strings: &[String]) {
            self.reserves.push((event, args.to_vec(), strings.to_vec()));
        }
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
        fn sound_db(&mut self, db_type: i32, entry: u16) -> Option<(String, i32)> {
            self.sound_db_queries.push((db_type, entry));
            self.sound_db.clone()
        }
        fn teleport(&mut self, target: i32, map: i32, x: i32, y: i32, options: i32) {
            self.teleports.push((target, map, x, y, options));
        }
        fn change_color(&mut self, colour: i32, frames: i32) {
            self.colours.push((colour, frames));
        }
        fn transition_install(&mut self, kind: i32, flags: i32) {
            self.transition_installs.push((kind, flags));
        }
        fn pro_feature(&mut self, kind: i32, milliseconds: i32) {
            self.pro_features.push((kind, milliseconds));
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
        fn character_state(&mut self, target: i32, field: i32) -> Option<i32> {
            self.character_queries.push((target, field));
            self.character_answers
                .iter()
                .find(|(t, f, _)| *t == target && *f == field)
                .and_then(|(_, _, value)| *value)
        }
        fn database(&mut self, op: &DbOp) -> Option<DbValue> {
            self.databases.push(op.clone());
            self.db_answer.clone()
        }
        fn save_load(&mut self, op: &SaveOp) -> Option<DbValue> {
            self.saves.push(op.clone());
            self.save_answer.clone()
        }
        fn effect(&mut self, kind: i32, duration: i32, args: &[i32]) {
            self.effects.push((kind, duration, args.to_vec()));
        }
        fn key_code_auto(&mut self, query: KeyQuery, auto: u32, banned: u32) -> i32 {
            self.key_polls.push((query, auto, banned));
            0
        }
        fn close_message(&mut self) {
            self.closed += 1;
        }
    }

    #[test]
    fn auto_input_reaches_the_host_with_the_poll_request() {
        // 125 remembers the key bits the script wants pressed; the next 123 must
        // carry them to the host, not just leave them in the interpreter. The mask
        // is 0x77 (no wait bit) so both polls run in one frame.
        let ev = event(
            5,
            "auto input",
            vec![
                cmd(125, &[16], &[]),
                cmd(123, &[2_000_000, 0x77], &[]),
                cmd(125, &[0], &[]),
                cmd(123, &[2_000_001, 0x77], &[]),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        vm.start_event(5).unwrap();
        let mut host = Recorder::default();
        vm.step_frame(&mut host);
        let query = KeyQuery {
            directions: 7,
            ok: true,
            cancel: true,
            sub: true,
            wait: false,
            device: 0,
        };
        assert_eq!(host.key_polls, vec![(query, 16, 0), (query, 0, 0)]);
    }

    #[test]
    fn the_input_toggle_switches_keys_off_and_back_on() {
        // 126 is a toggle, not a ban mask: byte 0 names the keys, byte 1 the mode
        // (0 enabled, 1 no movement, 2 disabled). The shipped opening command
        // `126 [247]` is *enable everything*, not "ban everything".
        let ev = event(
            7,
            "toggle",
            vec![
                cmd(126, &[0x1F0], &[]), // directions: disabled
                cmd(123, &[2_000_000, 0x11], &[]),
                cmd(126, &[0xF0], &[]), // directions: enabled again
                cmd(123, &[2_000_001, 0x11], &[]),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        vm.start_event(7).unwrap();
        let mut host = Recorder::default();
        vm.step_frame(&mut host);
        let query = KeyQuery::decode(0x11);
        assert_eq!(
            host.key_polls,
            vec![(query, 0, 0xF0), (query, 0, 0)],
            "mode 1 disables the named keys, mode 0 enables them again"
        );
    }

    #[test]
    fn a_wait_poll_holds_the_coroutine_until_a_key_arrives() {
        // The wait bit (0x80) makes 123 block. Event 249 uses it for a pause overlay:
        // the poll's value is never read, the command exists only to stop the scene.
        let ev = event(
            6,
            "wait poll",
            vec![
                cmd(123, &[2_000_000, 0x91], &[]),
                cmd(121, &[2_000_001, 1, 0, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        let id = vm.start_event(6).unwrap();
        let mut host = Recorder::default();
        vm.step_frame(&mut host);
        assert_eq!(host.key_polls.len(), 1, "the poll ran once");
        assert_eq!(
            vm.vars.get(1),
            0,
            "the instruction after the wait must not run"
        );
        assert_eq!(vm.instance(id).unwrap().wait, WaitState::Key);

        // Next frame the poll runs again; the recorder still answers 0, so it stays.
        vm.step_frame(&mut host);
        assert_eq!(host.key_polls.len(), 2);
        assert_eq!(vm.vars.get(1), 0);
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
    fn conditional_takes_the_first_matching_case() {
        // Both conditions are true; WOLF's first-hit branch must take case 1
        // and must not fall through to case 2.
        let e = event(
            1,
            "first-hit",
            vec![
                cmd(111, &[2, 2_000_000, 5, 0, 2_000_001, 10, 0], &[]),
                cmd(401, &[1], &[]),
                cmd(121, &[2_000_002, 1, 0, 0], &[]),
                cmd(401, &[2], &[]),
                cmd(121, &[2_000_002, 2, 0, 0], &[]),
                cmd(420, &[0], &[]),
                cmd(121, &[2_000_002, 3, 0, 0], &[]),
                cmd(499, &[], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        vm.vars.set(0, 9);
        vm.vars.set(1, 20);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(2), 1);
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
    fn label_jump_out_of_a_loop_pops_the_loop_context() {
        // 213 jumps to a label after the matching 171. The loop stack must be
        // unwound too; otherwise the abandoned context keeps the event "inside" a
        // loop it already left and the next 171 breaks the wrong frame.
        let e = event(
            1,
            "jump out",
            vec![
                cmd(170, &[], &[]),
                cmd(213, &[], &["out"]),
                cmd(498, &[], &[]),
                cmd(212, &[], &["out"]),
                cmd(123, &[2_000_000, 0x91], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        vm.start_event(1).unwrap();
        vm.step_frame(&mut Recorder::default());
        let inst = vm.instances().first().expect("parked on the key poll");
        assert!(
            inst.loops.is_empty(),
            "the jump left loop contexts behind: {:?}",
            inst.loops
        );
    }

    #[test]
    fn label_jump_into_an_endless_loop_restores_its_context() {
        // CE63 jumps out of its message loop to set Sys1/2 and a dynamic return
        // label then jumps back into the middle of the loop body. Without a
        // context the closing 498 falls through and the whole message engine
        // ends; entering the body must put the endless loop back on the stack.
        let e = event(
            1,
            "jump in endless",
            vec![
                cmd(213, &[], &["in"]),
                cmd(170, &[], &[]),
                cmd(212, &[], &["in"]),
                cmd(180, &[1], &[]),
                cmd(498, &[], &[]),
                cmd(123, &[2_000_000, 0x91], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        vm.start_event(1).unwrap();
        vm.step_frame(&mut Recorder::default());
        let inst = vm.instances().first().expect("parked on the wait");
        let ctx = inst.loops.last().expect("loop context was not restored");
        assert_eq!(ctx.remaining, -1, "170 loops endlessly");
    }

    #[test]
    fn label_jump_into_a_counted_loop_runs_one_remainder() {
        // Manual ラベル処理: entering a 回数付きループ from outside does not
        // apply its configured count; the body runs once and the 498 exits.
        let e = event(
            1,
            "jump in counted",
            vec![
                cmd(213, &[], &["in"]),
                cmd(179, &[5], &[]),
                cmd(212, &[], &["in"]),
                cmd(180, &[1], &[]),
                cmd(498, &[], &[]),
                cmd(123, &[2_000_000, 0x91], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        vm.start_event(1).unwrap();
        vm.step_frame(&mut Recorder::default());
        let inst = vm.instances().first().expect("parked on the wait");
        let ctx = inst.loops.last().expect("loop context was not restored");
        assert_eq!(ctx.remaining, 1, "an outside entry runs one remainder");
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
    fn string_condition_strips_the_variable_type_flag_from_cself_operands() {
        // CE270 pc92 compares 0x11186A05 (CSelf5, not equal) with SysStr25.
        // The 0x0100_0000 bit is a variable-type flag, not part of the self
        // address: masking only the comparison nibble turned CSelf5 into an
        // out-of-bank operand, so eval_str returned "" and every frame looked
        // like a new message.
        let ev = event(
            1,
            "flagged string condition",
            vec![
                cmd(122, &[1_600_005, 0], &["妹妹"]),
                cmd(112, &[0x11, 0x0100_0000 | 1_600_005], &["妹妹"]),
                cmd(401, &[1], &[]),
                cmd(121, &[2_000_000, 1, 0, 0], &[]),
                cmd(499, &[], &[]),
                cmd(499, &[], &[]),
                cmd(172, &[], &[]),
            ],
        );
        let mut vm = vm_with(vec![ev]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 1, "flagged CSelf5 compared as \"妹妹\"");
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
            save_answer: Some(DbValue::Num(7)),
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
    fn db_write_copies_a_string_variable_into_the_cell() {
        // CE258 pc1341/1347 write self[30] (a string variable) into CData 0:12:0/1.
        // The source operand's bank decides the cell kind; reading it as a number used
        // to store the magic address and leave the cell empty.
        let ev = event(
            7,
            "db string write",
            vec![cmd(250, &[0, 12, 0, 0x50004, 3_000_000], &["", "", "", ""])],
        );
        let mut vm = vm_with(vec![ev]);
        vm.vars.set_str(0, "强壮");
        vm.start_event(7).unwrap();
        let mut host = Recorder::default();
        vm.step_frame(&mut host);
        let write = &host.databases[0];
        assert_eq!(write.direction, DbDirection::Write);
        assert_eq!(write.source, Some(DbValue::Str("强壮".to_owned())));
    }

    #[test]
    fn a_string_cut_writes_through_a_computed_cross_event_address() {
        // CE268 pc11-14: compute CE269's string slot 5 into self10, then write the
        // first line of self5 through it. The target is indirect ("代入先を変数で
        // 指定") and the address uses the 15_000_000+100*event+slot bank.
        let e = event(
            268,
            "name",
            vec![
                cmd(121, &[1_600_010, 15_000_000, 26_905, 260], &[]),
                cmd(122, &[1_600_010, 17, 1_600_005], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let id = vm.start_event(268).unwrap();
        vm.instance_mut(id).unwrap().self_vars.set_str(605, "妹妹");
        let mut host = Recorder::default();
        vm.step_frame(&mut host);
        assert_eq!(
            vm.vars.common_self.get(&269).map(|b| b.get_str(0)),
            Some("妹妹")
        );
    }

    #[test]
    fn relative_600k_calls_are_offsets_from_the_caller() {
        // The message library addresses its siblings as 600_100 + offset:
        // CE264's 600104 is CE268, CE270's 600094 is CE264.
        assert_eq!(relative_call_target(600_104, 264), 268);
        assert_eq!(relative_call_target(600_094, 270), 264);
        assert_eq!(relative_call_target(600_100, 264), 264);
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
    fn unknown_label_warns_and_execution_continues() {
        // BUG-13: the old fallback set pc = program.len(), which killed events such as
        // CE63 whenever a dynamic label failed to match. A bad jump must be reported and
        // skipped, not fatal.
        let e = event(
            1,
            "badlabel",
            vec![
                cmd(213, &[], &["nowhere"]),
                cmd(121, &[2_000_000, 1, 0, 0], &[]),
                cmd(180, &[10], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(
            vm.vars.get(0),
            1,
            "the instruction after 213 must still run"
        );
        assert!(host.logs.iter().any(|(l, _)| *l == LogLevel::Warn));
        assert_eq!(vm.instances().len(), 1, "the coroutine must stay alive");
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
    fn se_db_entry_resolves_through_the_host_and_uses_its_volume() {
        // CE249 pc258 stores arg0 = 0x00000020: SE playback of SystemDB SE row 0.
        let e = event(1, "sedb", vec![cmd(140, &[0x20], &[])]);
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder {
            sound_db: Some(("SystemFile/[SE]Enter.ogg".to_owned(), 90)),
            ..Recorder::default()
        };
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(host.sound_db_queries, vec![(3, 0)]);
        assert_eq!(host.sounds.len(), 1);
        let cmd = &host.sounds[0];
        assert_eq!(cmd.channel, SoundChannel::Se);
        assert_eq!(cmd.action, SoundAction::Play);
        assert_eq!(cmd.file, "SystemFile/[SE]Enter.ogg");
        assert_eq!(cmd.volume, 90, "the DB row volume is the default");
        assert_eq!(cmd.frames, 0);
    }

    #[test]
    fn a_db_entry_without_a_host_answer_still_reaches_the_recorder() {
        let e = event(1, "sedb_missing", vec![cmd(140, &[0x220], &[])]);
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(host.sound_db_queries, vec![(3, 2)]);
        assert_eq!(host.sounds[0].action, SoundAction::Play);
        assert!(host.sounds[0].file.is_empty());
    }

    #[test]
    fn the_00ffff00_bgm_stop_sentinel_is_not_a_db_entry() {
        let e = event(1, "bgm_stop_db_shape", vec![cmd(140, &[0x00FF_FF00], &[])]);
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert!(host.sound_db_queries.is_empty());
        assert_eq!(host.sounds[0].action, SoundAction::Stop);
        assert_eq!(host.sounds[0].channel, SoundChannel::Bgm);
    }

    #[test]
    fn se_stop_clears_the_whole_channel_and_carries_no_file() {
        let e = event(
            1,
            "sestop",
            vec![
                cmd(140, &[0x0200_0020, 0, 0, 0, 100, 100], &["SE/a"]),
                cmd(140, &[0x0200_0020, 0, 0, 0, 100, 100], &["SE/b"]),
                cmd(140, &[-224, 15], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(host.sounds.len(), 3);
        assert_eq!(host.sounds[0].action, SoundAction::Play);
        assert_eq!(host.sounds[0].file, "SE/a");
        assert_eq!(host.sounds[1].action, SoundAction::Play);
        assert_eq!(host.sounds[1].file, "SE/b");
        let stop = &host.sounds[2];
        assert_eq!(stop.action, SoundAction::Stop);
        assert_eq!(stop.channel, SoundChannel::Se);
        assert!(stop.file.is_empty(), "a retail SE stop has no file name");
        assert_eq!(stop.frames, 15);
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

    #[test]
    fn bug_36_continue_loop_jumps_back_or_exits_counted() {
        let e = event(
            1,
            "continue_endless",
            vec![
                cmd(170, &[], &[]),
                cmd(121, &[2_000_000, 1, 0, 0x0104], &[]), // var0 += 1
                cmd(111, &[1, 2_000_000, 2, 2], &[]),      // if var0 == 2
                cmd(401, &[1], &[]),
                cmd(171, &[], &[]), // break
                cmd(499, &[], &[]),
                cmd(176, &[], &[]),                        // continue
                cmd(121, &[2_000_001, 1, 0, 0x0104], &[]), // var1 += 1
                cmd(498, &[], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 2);
        assert_eq!(vm.vars.get(1), 0, "instruction after 176 must be skipped");

        let e2 = event(
            2,
            "continue_counted",
            vec![
                cmd(179, &[3], &[]),
                cmd(121, &[2_000_002, 1, 0, 0x0104], &[]), // var2 += 1
                cmd(176, &[], &[]),                        // continue
                cmd(121, &[2_000_003, 1, 0, 0x0104], &[]), // var3 += 1
                cmd(498, &[], &[]),
            ],
        );
        let mut vm2 = vm_with(vec![e2]);
        vm2.start_event(2).unwrap();
        vm2.step_frame(&mut host);
        assert_eq!(
            vm2.vars.get(2),
            3,
            "counted loop should run exactly 3 times"
        );
        assert_eq!(vm2.vars.get(3), 0, "instruction after 176 must never run");
    }

    #[test]
    fn bug_27_eval_num_common_self_and_121_flags() {
        let mut vm = vm_with(vec![]);
        vm.vars.common_self.entry(42).or_default().set(7, 999);
        let dummy = event(1, "test", vec![]);
        let inst = Instance::new(1, None, Arc::new(Program::compile(&dummy)));
        let raw = 15_000_000 + 100 * 42 + 7;
        assert_eq!(eval_num(raw, &inst, &vm.vars), 999);

        let e = event(
            1,
            "real_and_clamp",
            vec![
                // Real mode 7 / 2 = 3.5 -> 3
                cmd(121, &[2_000_000, 7, 2, 0x300E], &[]),
                // Clamp mode: 2_000_000 clamped to 999_999
                cmd(121, &[2_000_001, 2_000_000, 0, 0x0005], &[]),
                // Real mode compound *=: 30 * (2500 / 1000.0) = 75 (not 60)
                cmd(121, &[2_000_002, 30, 0, 0x0000], &[]),
                cmd(121, &[2_000_002, 2500, 1000, 0x3302], &[]),
                // Batch mode: assign 42 to vars[10..=12] (count = 2)
                cmd(121, &[2_000_010, 42, 0, 0x10004, 2], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 3);
        assert_eq!(vm.vars.get(1), 999_999);
        assert_eq!(vm.vars.get(2), 75);
        assert_eq!(vm.vars.get(10), 42);
        assert_eq!(vm.vars.get(11), 42);
        assert_eq!(vm.vars.get(12), 42);
        assert_eq!(vm.vars.get(13), 0);
    }

    #[test]
    fn bug_29_live_bidirectional_sync() {
        let e1 = event(
            10,
            "live_sync_sender",
            vec![
                cmd(121, &[1_600_000, 12345, 0, 0x0004], &[]),
                cmd(122, &[1_600_005], &["live_string"]),
                cmd(180, &[10], &[]),
            ],
        );
        let e2 = event(
            20,
            "cross_writer",
            vec![cmd(121, &[15_000_000 + 100 * 10, 7777, 0, 0x0004], &[])],
        );
        let mut vm = vm_with(vec![e1, e2]);
        let mut host = Recorder::default();
        let id1 = vm.start_event(10).unwrap();
        vm.step_frame(&mut host);

        assert_eq!(vm.vars.common_self.get(&10).unwrap().get(0), 12345);
        assert_eq!(
            vm.vars.common_self.get(&10).unwrap().get_str(0),
            "live_string"
        );

        vm.set_instance_self_var(id1, 600, 54321);
        assert_eq!(vm.instance(id1).unwrap().self_vars.get(600), 54321);
        assert_eq!(vm.vars.common_self.get(&10).unwrap().get(0), 54321);

        vm.start_event(20).unwrap();
        vm.step_frame(&mut host);

        assert_eq!(vm.instance(id1).unwrap().self_vars.get(600), 7777);
        assert_eq!(vm.vars.common_self.get(&10).unwrap().get(0), 7777);
    }

    #[test]
    fn bug_28_opcode_124_field_18_foreground_event() {
        let e_fg = event(100, "fg_event", vec![cmd(180, &[10], &[])]);
        let e_bg = event(
            200,
            "bg_parallel",
            vec![cmd(124, &[2_000_000, 0x3000, 18], &[])],
        );
        let mut vm = vm_with(vec![e_fg, e_bg]);
        let mut host = Recorder::default();
        let _id_fg = vm.start_event(100).unwrap();
        let id_bg = vm.start_event(200).unwrap();
        vm.set_instance_parallel(id_bg, true);

        vm.step_frame(&mut host);
        assert_eq!(vm.vars.get(0), 500_100);
    }

    #[test]
    fn bug_30_opcode_125_auto_keys_ttl_and_delivery() {
        let e = event(
            1,
            "auto_key",
            vec![
                cmd(125, &[16], &[]),
                cmd(123, &[2_000_000, 0x77], &[]),
                cmd(123, &[2_000_001, 0x77], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);

        assert_eq!(host.key_polls.len(), 2);
        assert_eq!(host.key_polls[0].1, 16);
        assert_eq!(host.key_polls[1].1, 0);
    }

    #[test]
    fn bug_31_and_38_cself_string_slots_in_250_and_save() {
        let e = event(
            1,
            "cself_string_ops",
            vec![
                cmd(122, &[1_600_005], &["hero_name"]),
                cmd(250, &[0, 0, 0, 0x50000, 1_600_005], &[]),
                cmd(221, &[2_000_000, 1_600_005, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);

        assert_eq!(host.databases.len(), 1);
        assert_eq!(
            host.databases[0].source,
            Some(DbValue::Str("hero_name".to_string()))
        );

        assert_eq!(host.saves.len(), 1);
        assert_eq!(
            host.saves[0].file,
            SaveTarget::Path("hero_name".to_string())
        );
    }

    #[test]
    fn bug_32_reserve_with_args_and_return_to_title_clears_all() {
        let e = event(
            1,
            "reserve_args",
            vec![cmd(211, &[42, 0x112, 10, 20], &["", "arg_str"])],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);

        assert_eq!(host.reserves.len(), 1);
        assert_eq!(host.reserves[0].0, 42);
        assert_eq!(host.reserves[0].1, vec![10, 20]);
        assert_eq!(host.reserves[0].2, vec!["arg_str".to_string()]);

        let e_title = event(2, "title", vec![cmd(174, &[], &[])]);
        let e_dummy = event(3, "dummy", vec![cmd(180, &[100], &[])]);
        let mut vm2 = vm_with(vec![e_title, e_dummy]);
        vm2.start_event(3).unwrap();
        vm2.start_event(2).unwrap();
        assert_eq!(vm2.instances().len(), 2);
        vm2.step_frame(&mut host);
        assert_eq!(
            vm2.instances().len(),
            0,
            "ReturnToTitle must clear all instances"
        );
    }

    #[test]
    fn bug_35_wait_zero_and_picture_owner_event() {
        let e = event(
            77,
            "wait_zero",
            vec![
                cmd(180, &[0], &[]),
                cmd(121, &[2_000_000, 1, 0, 0x0004], &[]),
                cmd(150, &[0, 1, 10, 20], &["pic.png"]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(77).unwrap();
        vm.step_frame(&mut host);

        assert_eq!(vm.vars.get(0), 1, "Wait(0) must not block");
        assert_eq!(host.pictures.len(), 1);
        assert_eq!(host.pictures[0].owner_event, Some(77));
    }

    #[test]
    fn bug_37_opcode_140_pitch_and_stop_conditions() {
        let e = event(
            1,
            "sound_tests",
            vec![
                cmd(140, &[0x0200_0020, 0, 0, 0, 90, 120], &["SE/ping"]),
                cmd(140, &[0x0200_0021, 0, 0, 0, 100, 100], &["SE/preload"]),
                cmd(140, &[0x0200_0022, 12, 0, 0], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);

        assert_eq!(host.sounds.len(), 2, "preload must not emit sound");
        assert_eq!(host.sounds[0].action, SoundAction::Play);
        assert_eq!(host.sounds[0].volume, 90);
        assert_eq!(host.sounds[0].pitch, 120);

        assert_eq!(host.sounds[1].action, SoundAction::Stop);
        assert_eq!(host.sounds[1].frames, 12);
        assert_eq!(host.sounds[1].pitch, 100);
    }

    #[test]
    fn bug_39_opcode_130_and_151_evaluation() {
        let e = event(
            1,
            "teleport_and_color",
            vec![
                cmd(130, &[2_000_000, 2_000_001, 2_000_002, 2_000_003, 0], &[]),
                cmd(151, &[2_629_150, 2_000_004], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        vm.vars.set(0, 0); // target
        vm.vars.set(1, 15); // x
        vm.vars.set(2, 25); // y
        vm.vars.set(3, 3); // map
        vm.vars.set(4, 30); // frames
        let mut host = Recorder::default();
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);
        // 130 Teleport blocks for 1 frame; advance one more frame so 151 executes.
        vm.step_frame(&mut host);

        assert_eq!(host.teleports.len(), 1);
        assert_eq!(host.teleports[0], (0, 3, 15, 25, 0));

        assert_eq!(host.colours.len(), 1);
        assert_eq!(host.colours[0], (2_629_150, 30));
    }

    #[test]
    fn bug_47_opcode_124_compound_assignments() {
        let e = event(
            1,
            "op124_compound",
            vec![
                cmd(121, &[2_000_000, 140, 0, 0], &[]),
                // 0x4400 = picture query + divide-assign: 140 / 70 = 2.
                cmd(124, &[2_000_000, 0x4400, 7, 2], &[]),
                cmd(121, &[2_000_001, 100, 0, 0], &[]),
                // 0x1200 = character query + subtract-assign: 100 - 30 = 70.
                cmd(124, &[2_000_001, 0x1200, 5, 2], &[]),
                cmd(121, &[2_000_002, 999, 0, 0], &[]),
                // The plain engine family still overwrites.
                cmd(124, &[2_000_002, 0x3000, 11], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        host.picture_answers.push((7, 2, Some(70)));
        host.character_answers.push((5, 2, Some(30)));
        host.engine_answers.push((11, 42));
        vm.start_event(1).unwrap();
        vm.step_frame(&mut host);

        assert_eq!(vm.vars.get(0), 2);
        assert_eq!(vm.vars.get(1), 70);
        assert_eq!(vm.vars.get(2), 42);
        assert_eq!(host.picture_queries, vec![(7, 2)]);
        assert_eq!(host.character_queries, vec![(5, 2)]);
    }

    #[test]
    fn bug_46_opcode_160_and_1000_evaluate_variable_arguments() {
        let e = event(
            9,
            "transition_and_pro",
            vec![
                cmd(121, &[2_000_000, 3, 0, 0], &[]),
                cmd(121, &[2_000_001, 0x5010, 0, 0], &[]),
                cmd(121, &[2_000_002, 32, 0, 0], &[]),
                cmd(160, &[2_000_000, 2_000_001], &[]),
                cmd(1000, &[0x0005_0000, 2_000_002], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        vm.start_event(9).unwrap();
        vm.step_frame(&mut host);

        assert_eq!(host.transition_installs, vec![(3, 0x5010)]);
        assert_eq!(host.pro_features, vec![(5, 32)]);
    }

    #[test]
    fn bug_32_start_event_with_args_seeds_the_child_and_durable_bank() {
        let e = event(77, "reserved", vec![cmd(0, &[], &[])]);
        let mut vm = vm_with(vec![e]);
        let id = vm
            .start_event_with_args(77, &[7, 8], &["hello".to_owned()])
            .expect("event");
        let instance = vm.instance(id).expect("instance");
        assert_eq!(instance.self_vars.get(crate::magic::SELF_ARG_BASE), 7);
        assert_eq!(instance.self_vars.get(crate::magic::SELF_ARG_BASE + 1), 8);
        assert_eq!(instance.self_vars.get_str(SELF_ARG_STRING_BASE), "hello");
        let bank = vm.vars.common_self.get(&77).expect("bank");
        assert_eq!(bank.get(0), 7);
        assert_eq!(bank.get(1), 8);
        assert_eq!(bank.get_str(0), "hello");
    }

    #[test]
    fn call_arguments_reach_only_the_new_child_not_existing_instances() {
        let e = event(10, "parallel_loop", vec![cmd(0, &[], &[])]);
        let mut vm = vm_with(vec![e]);

        let existing = vm.start_event(10).expect("first instance");
        assert_eq!(
            vm.instance(existing)
                .expect("existing instance")
                .self_vars
                .get(crate::magic::SELF_ARG_BASE),
            0
        );

        let child = vm
            .start_event_with_args(10, &[10], &[])
            .expect("explicit call");
        assert_eq!(
            vm.instance(child)
                .expect("new child")
                .self_vars
                .get(crate::magic::SELF_ARG_BASE),
            10
        );
        assert_eq!(
            vm.instance(existing)
                .expect("existing instance")
                .self_vars
                .get(crate::magic::SELF_ARG_BASE),
            0,
            "a call argument must not be broadcast to another instance"
        );
    }

    #[test]
    fn op121_self_range_divides_only_the_named_slot() {
        let e = event(
            1,
            "tenths_grid",
            vec![
                cmd(121, &[1_600_022, 480, 0, 0], &[]),
                cmd(121, &[1_600_023, 864, 0, 0], &[]),
                cmd(121, &[1_600_024, 9_280, 0, 0], &[]),
                cmd(121, &[1_600_025, 1_152, 0, 0], &[]),
                // The save-slot geometry idiom: range=3 but a self target only
                // divides x. y/w/h stay in tenths for the renderer.
                cmd(121, &[1_600_022, 10, 0, 0x1_0400, 3], &[]),
                // Ordinary variables still take the full contiguous range.
                cmd(121, &[2_000_030, 42, 0, 0x1_0000, 2], &[]),
                cmd(180, &[2], &[]),
            ],
        );
        let mut vm = vm_with(vec![e]);
        let mut host = Recorder::default();
        let instance = vm.start_event(1).expect("event");
        vm.step_frame(&mut host);

        let self_vars = &vm.instance(instance).expect("instance").self_vars;
        let slot = |raw| crate::magic::self_slot(raw) as usize;
        assert_eq!(self_vars.get(slot(1_600_022)), 48);
        assert_eq!(self_vars.get(slot(1_600_023)), 864);
        assert_eq!(self_vars.get(slot(1_600_024)), 9_280);
        assert_eq!(self_vars.get(slot(1_600_025)), 1_152);
        assert_eq!(vm.vars.get(30), 42);
        assert_eq!(vm.vars.get(31), 42);
        assert_eq!(vm.vars.get(32), 42);
        assert_eq!(
            vm.vars.get(33),
            0,
            "normal batch stops after arg4 variables"
        );
    }
}
