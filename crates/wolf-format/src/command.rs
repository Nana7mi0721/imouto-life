//! The event-command stream.
//!
//! Common events and map event pages share **one** encoding, so there is one
//! parser and both callers reuse it (`docs/FORMAT_SPEC.md` §4, §5.7).
//!
//! The skeleton is:
//!
//! ```text
//! u8  param_count      // 0 => empty slot (end of a branch, blank line, ...)
//! if param_count > 0:
//!     u32 opcode
//!     u8[(param_count - 1) * 4] raw parameter bytes
//! u8  branch_depth
//! u8  string_count
//!     t_str[string_count]
//! if param_count > 0:
//!     u8 tail_kind     // 0 = none, 1 = move-route block
//!     if tail_kind == 1: RouteData
//! ```
//!
//! Note that `param_count` counts **4-byte words including the opcode word**, so
//! the parameter payload is always `(param_count - 1) * 4` bytes. That means
//! the loader never needs an opcode table to walk a stream — which is exactly
//! why unknown opcodes cannot desynchronise it.

use std::collections::BTreeMap;

use crate::bytes::Reader;
use crate::error::Result;

/// Opcode stored in an empty slot.
pub const OPCODE_BLANK: u32 = 0;

/// One move-route step: a kind byte, then `u32` and byte argument lists.
#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct RouteCommand {
    /// Route command id (WOLF move-route opcode).
    pub kind: u8,
    /// Word-sized arguments.
    pub u32_args: Vec<u32>,
    /// Byte-sized arguments.
    pub u8_args: Vec<u8>,
}

/// A full move-route block: six header bytes followed by the step list.
///
/// The same shape is used by map event pages (as their initial route) and by
/// the `tail` of opcode 201 commands, which is why it lives here.
#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct RouteData {
    /// Animation frequency.
    pub animation_frequency: u8,
    /// Move speed.
    pub move_speed: u8,
    /// Move frequency.
    pub move_frequency: u8,
    /// Move route mode.
    pub move_route_mode: u8,
    /// Behaviour options bitfield.
    pub behavior_options: u8,
    /// Route options bitfield.
    pub route_options: u8,
    /// The steps.
    pub commands: Vec<RouteCommand>,
}

impl RouteData {
    /// Read a route block from the stream.
    pub fn read(r: &mut Reader<'_>) -> Result<Self> {
        let animation_frequency = r.u8()?;
        let move_speed = r.u8()?;
        let move_frequency = r.u8()?;
        let move_route_mode = r.u8()?;
        let behavior_options = r.u8()?;
        let route_options = r.u8()?;
        let count = r.u32()? as usize;
        let mut commands = Vec::with_capacity(count.min(1024));
        for _ in 0..count {
            let kind = r.u8()?;
            let u32_count = r.u8()? as usize;
            let u32_args = r.u32_array(u32_count)?;
            let u8_count = r.u8()? as usize;
            let u8_args = r.take(u8_count)?.to_vec();
            commands.push(RouteCommand {
                kind,
                u32_args,
                u8_args,
            });
        }
        Ok(Self {
            animation_frequency,
            move_speed,
            move_frequency,
            move_route_mode,
            behavior_options,
            route_options,
            commands,
        })
    }
}

/// What follows the string table of a command.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum Tail {
    /// Ordinary command.
    None,
    /// Opcode 201 carries an embedded move route.
    MoveRoute(RouteData),
}

/// A single non-empty command.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Command {
    /// `param_count` as written, including the opcode word.
    pub param_count: u8,
    /// The opcode.
    pub opcode: u32,
    /// Raw parameter bytes: `(param_count - 1) * 4` of them.
    ///
    /// Kept raw so that the loader cannot rot when the opcode table grows; the
    /// typed decoders in `wolf-vm` interpret this slice.
    pub params: Vec<u8>,
    /// Branch nesting depth as recorded by the editor.
    pub branch_depth: u8,
    /// Inline strings (message text, label names, comments, ...).
    pub strings: Vec<String>,
    /// Embedded move route, if any.
    pub tail: Tail,
}

impl Command {
    /// Parameter payload length in bytes.
    #[must_use]
    pub fn param_len(&self) -> usize {
        self.params.len()
    }

    /// The `param_status` word carried by opcodes 210/211/300, if this is one.
    ///
    /// Those opcodes always store `param_status` immediately after their first
    /// `u32` field, regardless of any other condition. The Kaitai schema gates
    /// it on a variable-id range that this game's data never satisfies, so
    /// trusting the schema loses sync.
    #[must_use]
    pub fn param_status(&self) -> Option<ParamStatus> {
        match self.opcode {
            210 | 211 | 300 => {
                let bytes = self.params.get(4..8)?;
                Some(ParamStatus(u32::from_le_bytes([
                    bytes[0], bytes[1], bytes[2], bytes[3],
                ])))
            }
            _ => None,
        }
    }

    /// Parameter byte count implied by this command's `param_status`, for the
    /// opcodes whose layout is fully decoded.
    ///
    /// This exists purely as a loader self-check: if a future refactor
    /// desynchronises the stream, these opcodes will disagree first because
    /// they are the most frequent (210 alone is 18,468 instructions).
    #[must_use]
    pub fn expected_param_len(&self) -> Option<usize> {
        match self.opcode {
            // u32 call target (or a discarded placeholder) + param_status
            // + one word per argument + optional return-variable word.
            210 | 211 | 300 => {
                let status = self.param_status()?;
                let mut len = 8 + 4 * status.total_count();
                if status.return_value_enabled() {
                    len += 4;
                }
                Some(len)
            }
            // u8 packed condition count + 3 reserved + 12 bytes per condition.
            111 => Some(4 + 12 * usize::from(self.params.first().copied()? & 0x0F)),
            _ => None,
        }
    }
}

/// A slot in a command list: either empty or a command.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum Slot {
    /// `param_count == 0`.
    Blank,
    /// A real command.
    Command(Box<Command>),
}

impl Slot {
    /// The opcode, or 0 for an empty slot.
    #[must_use]
    pub fn opcode(&self) -> u32 {
        match self {
            Slot::Blank => OPCODE_BLANK,
            Slot::Command(c) => c.opcode,
        }
    }

    /// Read one slot from the stream.
    pub fn read(r: &mut Reader<'_>) -> Result<Self> {
        let param_count = r.u8()?;
        if param_count == 0 {
            // Empty slots still carry a branch depth, an (empty) string table
            // and no tail byte.
            let _branch_depth = r.u8()?;
            let string_count = r.u8()? as usize;
            skip_strings(r, string_count)?;
            return Ok(Slot::Blank);
        }

        let opcode = r.u32()?;
        let params = r.take((param_count as usize - 1) * 4)?.to_vec();
        let branch_depth = r.u8()?;
        let string_count = r.u8()? as usize;
        let mut strings = Vec::with_capacity(string_count.min(16));
        for _ in 0..string_count {
            strings.push(r.t_str()?);
        }
        let tail = match r.u8()? {
            0 => Tail::None,
            1 => Tail::MoveRoute(RouteData::read(r)?),
            other => {
                return Err(crate::error::Error::field(
                    "command tail kind",
                    r.pos() - 1,
                    format!("unknown tail kind {other} (only 0 and 1 exist)"),
                ))
            }
        };
        Ok(Slot::Command(Box::new(Command {
            param_count,
            opcode,
            params,
            branch_depth,
            strings,
            tail,
        })))
    }
}

fn skip_strings(r: &mut Reader<'_>, count: usize) -> Result<()> {
    for _ in 0..count {
        r.t_str_bytes()?;
    }
    Ok(())
}

/// The decoded `param_status` bitfield used by variable-argument opcodes.
///
/// ```text
/// bits  0..=3  number_count
/// bits  4..=7  string_count
/// bits 12..=16 string_1..string_5 enabled
/// bit  24      return_value_enabled
/// ```
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct ParamStatus(u32);

impl ParamStatus {
    /// Wrap a raw word.
    #[must_use]
    pub const fn new(raw: u32) -> Self {
        Self(raw)
    }

    /// The raw word.
    #[must_use]
    pub const fn raw(self) -> u32 {
        self.0
    }

    /// Number of `s32` parameters.
    #[must_use]
    pub const fn number_count(self) -> usize {
        (self.0 & 0xF) as usize
    }

    /// Number of string parameters.
    #[must_use]
    pub const fn string_count(self) -> usize {
        ((self.0 >> 4) & 0xF) as usize
    }

    /// Total parameter count (numbers then strings).
    #[must_use]
    pub const fn total_count(self) -> usize {
        self.number_count() + self.string_count()
    }

    /// Whether string parameter `index` (0-based) is enabled.
    #[must_use]
    pub const fn string_enabled(self, index: usize) -> bool {
        index < 5 && (self.0 >> (12 + index)) & 1 == 1
    }

    /// Whether a return-variable id follows the parameters.
    #[must_use]
    pub const fn return_value_enabled(self) -> bool {
        (self.0 >> 24) & 1 == 1
    }
}

/// Aggregate counts over a command list.
///
/// Used by both `CommonEvent.dat` and `.mps` so the two share one definition
/// of "how many instructions does this game actually contain".
#[derive(Debug, Clone, Default)]
pub struct SlotStats {
    /// Every slot, empty or not.
    pub slots: usize,
    /// Slots that carried `param_count == 0` (structurally absent command).
    ///
    /// Zero throughout this game's data: the editor always writes
    /// `param_count >= 1` and represents an empty line as `command_type == 0`.
    /// Kept because other WOLF builds may differ.
    pub param_count_zero: usize,
    /// Opcode histogram, **including** opcode 0 for NOP slots.
    pub opcodes: BTreeMap<u32, usize>,
    /// Deepest recorded branch depth.
    pub max_branch_depth: u8,
    /// Number of commands carrying a move-route tail.
    pub move_route_tails: usize,
    /// Commands whose parameter bytes disagreed with the known `param_status`
    /// layout for their opcode. Must stay 0 for this game.
    pub param_layout_mismatches: usize,
}

impl SlotStats {
    /// Count one slot.
    pub fn push(&mut self, slot: &Slot) {
        self.slots += 1;
        match slot {
            Slot::Blank => self.param_count_zero += 1,
            Slot::Command(cmd) => {
                *self.opcodes.entry(cmd.opcode).or_insert(0) += 1;
                self.max_branch_depth = self.max_branch_depth.max(cmd.branch_depth);
                if matches!(cmd.tail, Tail::MoveRoute(_)) {
                    self.move_route_tails += 1;
                }
                if let Some(expected) = cmd.expected_param_len() {
                    if expected != cmd.params.len() {
                        self.param_layout_mismatches += 1;
                    }
                }
            }
        }
    }

    /// Count a whole list.
    pub fn extend<'a>(&mut self, slots: impl IntoIterator<Item = &'a Slot>) {
        for slot in slots {
            self.push(slot);
        }
    }

    /// Slots that do **not** carry a real instruction (NOP rows and the
    /// structurally-empty form).
    #[must_use]
    pub fn blank(&self) -> usize {
        self.param_count_zero + self.opcodes.get(&OPCODE_BLANK).copied().unwrap_or(0)
    }

    /// Slots that carry a real instruction.
    #[must_use]
    pub fn real(&self) -> usize {
        self.slots - self.blank()
    }

    /// Distinct opcodes seen, excluding the NOP opcode.
    #[must_use]
    pub fn distinct_opcodes(&self) -> usize {
        self.opcodes.keys().filter(|&&op| op != OPCODE_BLANK).count()
    }

    /// Merge another set of counts into this one.
    pub fn merge(&mut self, other: &SlotStats) {
        self.slots += other.slots;
        self.param_count_zero += other.param_count_zero;
        self.max_branch_depth = self.max_branch_depth.max(other.max_branch_depth);
        self.move_route_tails += other.move_route_tails;
        self.param_layout_mismatches += other.param_layout_mismatches;
        for (&op, &n) in &other.opcodes {
            *self.opcodes.entry(op).or_insert(0) += n;
        }
    }
}
