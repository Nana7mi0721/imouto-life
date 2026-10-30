//! Load-time precompilation (docs/OPCODE_SPEC.md §4, §7.5).
//!
//! The editor stores control flow as *paired plain instructions*: an `111`
//! conditional sits somewhere, its branches are `401` markers, and the block
//! closes with `499`. Nothing in the instruction says where the block ends, so
//! the original interpreter had to scan forward. This game executes 139,273
//! instructions per pass over the common events and the census counts 10,743
//! `111`, 1,036 `102` and 2,126 loop heads — a forward scan per branch would
//! turn every one of those into an O(n) walk.
//!
//! [Program::compile] resolves the whole tree once instead:
//!
//! * every branch/loop head becomes a [Block] carrying its case table
//!   (`Vec<(case_id, target_pc)>`), its `else`/`cancel` targets and its end pc;
//! * a `401 Case` knows its owning block, so at run time it is a table lookup
//!   (docs/OPCODE_SPEC.md §4.2 documents the two different case-numbering
//!   schemes the editor uses — that difference is absorbed here and never
//!   reaches the interpreter);
//! * a `498 LoopEnd` knows its loop head, so the loop counter lives in one flat
//!   vector;
//! * `212 SetLabel` names are collected into a map. **Labels are strings, not
//!   indices** (docs/PLAN.md §3.2). 5 of the 1,543 `213 JumpLabel` instructions
//!   embed a `cself[n]` and are only resolvable at run time, so they are marked
//!   dynamic instead of being resolved to `None`.
//!
//! Structure resolution is deliberately tolerant (docs/OPCODE_SPEC.md §4.3):
//! 131 case markers in this data have no open block at all, and 123 block ends
//! have nothing to close. Those are real, shipped bytes — a strict compiler would
//! reject the game's own data, so orphans are counted in [PrecompileStats] and
//! execution treats them as no-ops.

use std::collections::HashMap;
use std::sync::Arc;

use wolf_format::command::{Command, Slot};
use wolf_format::commonevent::CommonEventData;

use crate::text;

/// What kind of statement opened a [Block].
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum BlockKind {
    /// `111 ConditionalBranch` — integer condition chain.
    Condition,
    /// `102 ShowChoices` — player choice.
    Choices,
    /// `170 StartLoop`, `176 StartLoop2`, `179 LoopTimes`.
    Loop,
}

/// One resolved control-flow construct.
#[derive(Clone, Debug)]
pub struct Block {
    /// pc of the head instruction (`111`, `102`, `170/176/179`).
    pub head: usize,
    /// What opened this block.
    pub kind: BlockKind,
    /// Case table for [BlockKind::Condition] and [BlockKind::Choices].
    ///
    /// `case_id` is the raw first argument of the `401` that introduced the case,
    /// i.e. 1-based for `111` and *option index + 2* for `102`
    /// (docs/OPCODE_SPEC.md §4.2). Keeping the raw id means the runtime never has
    /// to know which of the two schemes is in play.
    pub cases: Vec<(i32, usize)>,
    /// Target of `420` (the `else` of an `111`), pre-resolved to `pc + 1`.
    pub else_pc: Option<usize>,
    /// Target of `421` (the cancel arm of a `102`).
    pub cancel_pc: Option<usize>,
    /// pc of the instruction that closed the block (`499` / `498`),
    /// or [usize::MAX] when it never closed (execution then falls to program end).
    pub end_pc: usize,
}

impl Block {
    /// Where control resumes when the block is skipped or finished.
    #[must_use]
    pub fn end_target(&self, len: usize) -> usize {
        if self.end_pc == usize::MAX {
            len
        } else {
            self.end_pc + 1
        }
    }

    /// Look a case up by its raw id.
    #[must_use]
    pub fn case_target(&self, case_id: i32) -> Option<usize> {
        self.cases
            .iter()
            .find(|(id, _)| *id == case_id)
            .map(|(_, pc)| *pc)
    }
}

/// Per-instruction jump table entry.
///
/// Indexed by pc, parallel to the instruction vector, so dispatch costs one array
/// access instead of a match on the opcode.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Control {
    /// Not a control-flow instruction.
    None,
    /// A `111`/`102`/loop head; index into [Program::blocks].
    Block(usize),
    /// A `401` case marker; the block whose case table names the target.
    Case { block: usize },
    /// A `498` loop end; the loop block to decrement.
    LoopEnd { block: usize },
    /// A `213` label jump, resolved at run time.
    LabelJump,
}

/// Aggregate structure counts, used by `wolf-cli verify` and the tests.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct PrecompileStats {
    /// Instructions (including blanks).
    pub slots: usize,
    /// Blocks opened.
    pub blocks: usize,
    /// [BlockKind::Condition] blocks.
    pub conditions: usize,
    /// [BlockKind::Choices] blocks.
    pub choices: usize,
    /// [BlockKind::Loop] blocks.
    pub loops: usize,
    /// `401` case markers attached to a block.
    pub cases: usize,
    /// `401` markers with no open branch block (docs/OPCODE_SPEC.md §4.3: 131).
    pub orphan_cases: usize,
    /// `420` else markers attached.
    pub else_cases: usize,
    /// `421` cancel markers attached.
    pub cancel_cases: usize,
    /// `499`/`498` that closed nothing.
    pub orphan_ends: usize,
    /// Blocks closed implicitly by an outer terminator (`176` relies on this).
    pub implicit_closes: usize,
    /// Blocks still open at the end of the event.
    pub unclosed_blocks: usize,
    /// `212` labels defined.
    pub labels: usize,
    /// `213` jumps, static or dynamic.
    pub label_jumps: usize,
    /// `213` jumps whose name still holds an escape after static expansion.
    pub dynamic_labels: usize,
    /// `213` jumps whose label was never defined.
    pub unresolved_labels: usize,
    /// Deepest block nesting.
    pub max_depth: usize,
    /// `111` whose argc is not `1 + 3*cond_count` (must stay 0 in this game).
    pub malformed_conditions: usize,
}

impl PrecompileStats {
    /// Add another program's counts into this one.
    pub fn merge(&mut self, other: &Self) {
        self.slots += other.slots;
        self.blocks += other.blocks;
        self.conditions += other.conditions;
        self.choices += other.choices;
        self.loops += other.loops;
        self.cases += other.cases;
        self.orphan_cases += other.orphan_cases;
        self.else_cases += other.else_cases;
        self.cancel_cases += other.cancel_cases;
        self.orphan_ends += other.orphan_ends;
        self.implicit_closes += other.implicit_closes;
        self.unclosed_blocks += other.unclosed_blocks;
        self.labels += other.labels;
        self.label_jumps += other.label_jumps;
        self.dynamic_labels += other.dynamic_labels;
        self.unresolved_labels += other.unresolved_labels;
        self.max_depth = self.max_depth.max(other.max_depth);
        self.malformed_conditions += other.malformed_conditions;
    }
}

/// `return_value_id` of an event that declares no return value (`0xFFFF_FFFF`).
///
/// 476 of the 550 common events in this game carry it; calls into them leave the
/// caller's destination variable untouched (docs/OPCODE_210_RETURN.md §3.2).
pub const NO_RETURN_VALUE: u32 = u32::MAX;

/// Self bank a common event keeps its own variables in.
///
/// All 550 events address their own state through magic `1_600_000 + slot`
/// (32,391 reads and 9,642 writes land in group 6, and not one write lands in
/// group 0), so group 6 is where a common event lives - including the call
/// arguments the engine writes at [`crate::magic::SELF_ARG_BASE`].
pub const COMMON_SELF_BASE: usize = 600;

/// Self bank a map page keeps its own variables in.
///
/// The editor spells a map event own state as `1_100_000 + slot`: the YADOT-WOLF
/// docs show an event writing `1100005` and the debug window reporting it as
/// `1000025`, i.e. group 1 slot 5. No map page in this game expands a
/// `\cself[n]` escape, so this value is inferred from the documented magic
/// rather than measured against a capture.
pub const MAP_SELF_BASE: usize = 100;

/// One event, ready to execute.
#[derive(Clone, Debug)]
pub struct Program {
    /// Event id (`CommonEvent.id`).
    pub id: u32,
    /// Event title, for traces and `300 CallByName`.
    pub title: String,
    /// `CommonEvent.return_value_id`: which self variable of *this* event holds
    /// the value a caller receives.
    ///
    /// WOLF numbers it inside self group 6 - the same bank the call arguments
    /// arrive in - so the slot is `1_600_000 + return_value_id`
    /// (docs/OPCODE_210_RETURN.md §3). [`NO_RETURN_VALUE`] means the event
    /// declares no return value, and the caller's destination keeps its old value.
    pub return_value_id: u32,
    /// Self bank this program own variables live in.
    ///
    /// `\cself[n]` means slot `n` of the running event, so the escape resolves to
    /// `self_base + n`. The magic operands stored in the file already carry the
    /// same base explicitly, which is why this field is only consulted by the
    /// text expander. See [`COMMON_SELF_BASE`] and [`MAP_SELF_BASE`].
    pub self_base: usize,
    /// The instruction stream, unchanged from the file.
    pub slots: Vec<Slot>,
    /// Jump table, parallel to [Program::slots].
    pub control: Vec<Control>,
    /// Resolved blocks.
    pub blocks: Vec<Block>,
    /// `212` labels: name -> pc *after* the `212` instruction.
    pub labels: HashMap<String, usize>,
    /// pcs of `213` instructions whose label needs run-time expansion.
    pub dynamic_jumps: Vec<usize>,
    /// Structure counts for this event.
    pub stats: PrecompileStats,
}

impl Program {
    /// Resolve one event's control flow.
    #[must_use]
    pub fn compile(event: &wolf_format::commonevent::CommonEvent) -> Self {
        let mut program = Self::from_slots(event.id, &event.title, event.commands.clone());
        program.return_value_id = event.return_value_id;
        program.self_base = COMMON_SELF_BASE;
        program
    }

    /// Same, for a bare instruction stream.
    ///
    /// Map events (`.mps` pages) are ordinary `Slot` streams with no owning
    /// `CommonEvent`, and the interpreter needs exactly the same jump tables for
    /// them: a map page can open an `111` branch chain and a `179` loop just like
    /// a common event can. TitleMap.mps event 2 - the real title screen - is 133
    /// slots of `111`/`179`/`498`/`213`, so keeping two compilers would mean two
    /// chances to disagree about where a branch ends.
    #[must_use]
    pub fn from_slots(id: u32, title: &str, slots: Vec<Slot>) -> Self {
        let len = slots.len();
        let mut control = vec![Control::None; len];
        let mut blocks: Vec<Block> = Vec::new();
        let mut open: Vec<usize> = Vec::new();
        let mut stats = PrecompileStats {
            slots: len,
            ..PrecompileStats::default()
        };
        let mut dynamic_jumps = Vec::new();
        let mut max_depth = 0;

        for (pc, slot) in slots.iter().enumerate() {
            let Slot::Command(cmd) = slot else {
                continue;
            };
            match cmd.opcode {
                // 112 is the STRING form of the 111 branch: N string variables
                // compared against inline strings, then the identical 401/420/499
                // skeleton. It has to open a block of its own, because otherwise its
                // 401 case markers attach to whatever branch encloses it and its 499
                // closes that branch early - which is exactly how the inheritance menu
                // of SampleMapA event 0 ended up with a case table full of its nested
                // string comparisons and an end 150 slots too early.
                111 | 112 | 102 | 170 | 176 | 179 => {
                    let kind = match cmd.opcode {
                        102 => BlockKind::Choices,
                        111 | 112 => BlockKind::Condition,
                        _ => BlockKind::Loop,
                    };
                    if cmd.opcode == 111 && !condition_layout_ok(cmd) {
                        stats.malformed_conditions += 1;
                    }
                    blocks.push(Block {
                        head: pc,
                        kind,
                        cases: Vec::new(),
                        else_pc: None,
                        cancel_pc: None,
                        end_pc: usize::MAX,
                    });
                    let index = blocks.len() - 1;
                    open.push(index);
                    control[pc] = Control::Block(index);
                    match kind {
                        BlockKind::Condition => stats.conditions += 1,
                        BlockKind::Choices => stats.choices += 1,
                        BlockKind::Loop => stats.loops += 1,
                    }
                    max_depth = max_depth.max(open.len());
                }
                401 => {
                    // Attach to the innermost open *branch* block. Nested loops
                    // between the head and its case markers are legal, so we scan
                    // the stack instead of only looking at its top.
                    match find_open(&blocks, &open, |k| k != BlockKind::Loop) {
                        Some(index) => {
                            let id = arg(cmd, 0);
                            blocks[index].cases.push((id, pc + 1));
                            control[pc] = Control::Case { block: index };
                            stats.cases += 1;
                        }
                        None => stats.orphan_cases += 1,
                    }
                }
                420 => match find_open(&blocks, &open, |k| k == BlockKind::Condition) {
                    Some(index) => {
                        blocks[index].else_pc = Some(pc + 1);
                        // Control is set as well: reaching a 420 by fall-through
                        // (i.e. from the branch above it) means "skip to the end
                        // of the block", and Control::Case with an id that has no
                        // case does exactly that.
                        control[pc] = Control::Case { block: index };
                        stats.else_cases += 1;
                    }
                    None => stats.orphan_cases += 1,
                },
                421 => match find_open(&blocks, &open, |k| k == BlockKind::Choices) {
                    Some(index) => {
                        blocks[index].cancel_pc = Some(pc + 1);
                        control[pc] = Control::Case { block: index };
                        stats.cancel_cases += 1;
                    }
                    None => stats.orphan_cases += 1,
                },
                499 => match find_open(&blocks, &open, |k| k != BlockKind::Loop) {
                    Some(index) => {
                        stats.implicit_closes += close_from(&mut blocks, &mut open, index, pc);
                        control[pc] = Control::Case { block: index };
                    }
                    None => stats.orphan_ends += 1,
                },
                498 => match find_open(&blocks, &open, |k| k == BlockKind::Loop) {
                    Some(index) => {
                        stats.implicit_closes += close_from(&mut blocks, &mut open, index, pc);
                        blocks[index].end_pc = pc;
                        control[pc] = Control::LoopEnd { block: index };
                    }
                    None => stats.orphan_ends += 1,
                },
                // Labels and jumps are resolved in a second pass: a 213 may jump
                // forwards to a 212 that has not been visited yet, so a single
                // pass cannot know the target.
                212 => {
                    stats.labels += 1;
                }
                213 => {
                    let name = cmd.strings.first().cloned().unwrap_or_default();
                    if text::has_escape(&name) {
                        stats.dynamic_labels += 1;
                        dynamic_jumps.push(pc);
                    }
                    control[pc] = Control::LabelJump;
                    stats.label_jumps += 1;
                }
                _ => {}
            }
        }

        stats.blocks = blocks.len();
        stats.max_depth = max_depth;
        stats.unclosed_blocks = open.len();

        // Second pass: labels. A 213 may jump backwards to a 212 already seen or
        // forwards to one that comes later, so targets are only known once the
        // whole stream has been walked.
        let mut labels: HashMap<String, usize> = HashMap::new();
        let mut static_jumps: Vec<String> = Vec::new();
        for (pc, slot) in slots.iter().enumerate() {
            let Slot::Command(cmd) = slot else {
                continue;
            };
            match cmd.opcode {
                // The target is the instruction *after* the SetLabel.
                212 => {
                    labels.insert(cmd.strings.first().cloned().unwrap_or_default(), pc + 1);
                }
                213 => {
                    let name = cmd.strings.first().cloned().unwrap_or_default();
                    if !text::has_escape(&name) {
                        static_jumps.push(name);
                    }
                }
                _ => {}
            }
        }
        // A jump to a name that no 212 defines would loop or crash in the
        // original; we count it and make the interpreter fall off the end.
        stats.unresolved_labels = static_jumps
            .iter()
            .filter(|name| !labels.contains_key(*name))
            .count();

        Self {
            id,
            title: title.to_owned(),
            // A bare slot stream carries no declaration; map event pages are not
            // callable through 210 with a return value in this game.
            return_value_id: NO_RETURN_VALUE,
            self_base: MAP_SELF_BASE,
            slots,
            control,
            blocks,
            labels,
            dynamic_jumps,
            stats,
        }
    }

    /// Number of instructions.
    #[must_use]
    pub fn len(&self) -> usize {
        self.slots.len()
    }

    /// True when the event has no instructions.
    #[must_use]
    pub fn is_empty(&self) -> bool {
        self.slots.is_empty()
    }

    /// The block opened at `pc`, if any.
    #[must_use]
    pub fn block_at(&self, pc: usize) -> Option<&Block> {
        match self.control.get(pc) {
            Some(Control::Block(index)) => self.blocks.get(*index),
            _ => None,
        }
    }
}

/// Every common event, precompiled and indexed the way the call opcodes need.
#[derive(Clone, Debug, Default)]
pub struct ProgramSet {
    /// Indexed by event id; `None` for ids the file skips.
    events: Vec<Option<Arc<Program>>>,
    /// Event title -> id, for `300 CallByName`.
    by_name: HashMap<String, u32>,
    /// Title with a leading `[..]` tag stripped -> id. WOLF event titles carry a
    /// `[共]`/`[移]` prefix in the editor that call sites do not always include.
    by_name_plain: HashMap<String, u32>,
    /// Totals over the whole set.
    pub stats: PrecompileStats,
}

impl ProgramSet {
    /// Precompile every event in a `CommonEvent.dat`.
    #[must_use]
    pub fn from_common_events(data: &CommonEventData) -> Self {
        let mut events: Vec<Option<Arc<Program>>> = Vec::new();
        let mut stats = PrecompileStats::default();
        let mut by_name = HashMap::new();
        let mut by_name_plain = HashMap::new();

        for event in &data.events {
            let program = Arc::new(Program::compile(event));
            stats.merge(&program.stats);
            let id = program.id;
            by_name.insert(program.title.clone(), id);
            by_name_plain.insert(strip_tag(&program.title).to_owned(), id);
            let index = id as usize;
            if events.len() <= index {
                events.resize_with(index + 1, || None);
            }
            events[index] = Some(program);
        }

        Self {
            events,
            by_name,
            by_name_plain,
            stats,
        }
    }

    /// Fetch a precompiled event by id.
    #[must_use]
    pub fn event(&self, id: u32) -> Option<&Arc<Program>> {
        self.events.get(id as usize).and_then(Option::as_ref)
    }

    /// Number of populated ids (not the highest id + 1).
    #[must_use]
    pub fn len(&self) -> usize {
        self.events.iter().filter(|e| e.is_some()).count()
    }

    /// True when no event was loaded.
    #[must_use]
    pub fn is_empty(&self) -> bool {
        self.events.iter().all(Option::is_none)
    }

    /// Resolve a `300 CallByName` target.
    #[must_use]
    pub fn id_by_name(&self, name: &str) -> Option<u32> {
        self.by_name
            .get(name)
            .copied()
            .or_else(|| self.by_name_plain.get(name).copied())
            .or_else(|| self.by_name_plain.get(strip_tag(name)).copied())
    }
}

/// Strip a leading `[..]` tag from an event title.
fn strip_tag(title: &str) -> &str {
    let trimmed = title.trim_start();
    if let Some(rest) = trimmed.strip_prefix('[') {
        if let Some(end) = rest.find(']') {
            return rest.get(end + 1..).unwrap_or(rest).trim_start();
        }
    }
    trimmed
}

/// Close blocks from the top of the stack down to (and including) `index`.
///
/// Returns how many *outer* blocks were closed implicitly, which is what
/// `176 StartLoop2` does in this data (docs/OPCODE_SPEC.md §4.6: its `498` has a
/// negative indent diff and rolls back several layers at once).
fn close_from(blocks: &mut [Block], open: &mut Vec<usize>, index: usize, pc: usize) -> usize {
    let mut implicit = 0;
    while let Some(top) = open.pop() {
        // The target block gets stamped too: its 499 *is* its end (the
        // interpreter resumes at end_pc + 1). Inner blocks closed on the way out
        // are the implicit ones, counted separately.
        if blocks[top].end_pc == usize::MAX {
            blocks[top].end_pc = pc;
        }
        if top == index {
            break;
        }
        implicit += 1;
    }
    implicit
}

/// Find the innermost open block matching `pred`.
fn find_open(blocks: &[Block], open: &[usize], pred: impl Fn(BlockKind) -> bool) -> Option<usize> {
    open.iter()
        .rev()
        .copied()
        .find(|index| blocks.get(*index).is_some_and(|b| pred(b.kind)))
}

/// `111` must carry `1 + 3*cond_count` int args (docs/OPCODE_SPEC.md §5.26).
fn condition_layout_ok(cmd: &Command) -> bool {
    let count = i64::from(arg(cmd, 0)) & 0x0F;
    argc(cmd) as i64 == 1 + 3 * count
}

/// Number of 4-byte integer arguments.
#[must_use]
pub fn argc(cmd: &Command) -> usize {
    cmd.params.len() / 4
}

/// One 4-byte integer argument, little-endian; 0 when absent.
///
/// Missing arguments are not a panic: several opcodes in this data are called
/// with fewer slots than the spec documents (docs/OPCODE_SPEC.md §10).
#[must_use]
pub fn arg(cmd: &Command, index: usize) -> i32 {
    let start = index * 4;
    let slice = cmd.params.get(start..start + 4);
    match slice {
        Some(b) => i32::from_le_bytes([b[0], b[1], b[2], b[3]]),
        None => 0,
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

    fn blank() -> Slot {
        cmd(0, &[], &[])
    }

    #[test]
    fn simple_if_else_resolves() {
        // 0: 111 cond  1: 121 (body)  2: 401 case1  3: 121 (body)
        // 4: 420       5: 121 (else)  6: 499
        let slots = vec![
            cmd(111, &[1, 2_000_000, 5, 2], &[]),
            cmd(121, &[2_000_001, 1, 2, 0], &[]),
            cmd(401, &[1], &[]),
            cmd(121, &[2_000_002, 1, 2, 0], &[]),
            cmd(420, &[0], &[]),
            cmd(121, &[2_000_003, 1, 2, 0], &[]),
            cmd(499, &[], &[]),
        ];
        let event = fake_event(1, "test", slots);
        let p = Program::compile(&event);
        assert_eq!(p.blocks.len(), 1);
        let b = &p.blocks[0];
        assert_eq!(b.head, 0);
        assert_eq!(b.kind, BlockKind::Condition);
        assert_eq!(b.cases, vec![(1, 3)]);
        assert_eq!(b.else_pc, Some(5));
        assert_eq!(b.end_pc, 6);
        assert_eq!(b.end_target(p.len()), 7);
        assert_eq!(b.case_target(1), Some(3));
        assert_eq!(p.stats.malformed_conditions, 0);
        assert_eq!(p.stats.orphan_cases, 0);
        assert_eq!(p.stats.orphan_ends, 0);
    }

    #[test]
    fn choices_use_option_plus_two_numbering() {
        let slots = vec![
            cmd(102, &[2], &["a", "b"]),
            cmd(401, &[2], &[]),
            cmd(121, &[2_000_000, 1, 2, 0], &[]),
            cmd(401, &[3], &[]),
            cmd(121, &[2_000_001, 1, 2, 0], &[]),
            cmd(421, &[0], &[]),
            cmd(499, &[], &[]),
        ];
        let p = Program::compile(&fake_event(2, "choices", slots));
        let b = &p.blocks[0];
        assert_eq!(b.kind, BlockKind::Choices);
        assert_eq!(b.cases, vec![(2, 2), (3, 4)]);
        assert_eq!(b.cancel_pc, Some(6));
    }

    #[test]
    fn loop_pairs_through_498() {
        let slots = vec![cmd(179, &[3], &[]), cmd(180, &[1], &[]), cmd(498, &[], &[])];
        let p = Program::compile(&fake_event(3, "loop", slots));
        assert_eq!(p.blocks.len(), 1);
        assert_eq!(p.blocks[0].kind, BlockKind::Loop);
        assert_eq!(p.blocks[0].end_pc, 2);
        assert_eq!(p.control[0], Control::Block(0));
        assert_eq!(p.control[2], Control::LoopEnd { block: 0 });
    }

    #[test]
    fn nested_blocks_close_inner_first() {
        let slots = vec![
            cmd(170, &[], &[]),                   // 0 loop
            cmd(111, &[1, 2_000_000, 0, 2], &[]), // 1 if
            cmd(401, &[1], &[]),                  // 2
            cmd(121, &[2_000_001, 1, 1, 0], &[]), // 3
            cmd(499, &[], &[]),                   // 4 closes the if
            cmd(498, &[], &[]),                   // 5 closes the loop
        ];
        let p = Program::compile(&fake_event(4, "nested", slots));
        assert_eq!(p.blocks[0].kind, BlockKind::Loop);
        assert_eq!(p.blocks[1].kind, BlockKind::Condition);
        assert_eq!(p.blocks[1].end_pc, 4);
        assert_eq!(p.blocks[0].end_pc, 5);
        assert_eq!(p.stats.max_depth, 2);
    }

    #[test]
    fn orphan_cases_are_tolerated_not_rejected() {
        let slots = vec![cmd(401, &[1], &[]), cmd(499, &[], &[])];
        let p = Program::compile(&fake_event(5, "orphan", slots));
        assert_eq!(p.stats.orphan_cases, 1);
        assert_eq!(p.stats.orphan_ends, 1);
        assert_eq!(p.blocks.len(), 0);
    }

    #[test]
    fn labels_resolve_and_dynamic_jumps_are_flagged() {
        let slots = vec![
            cmd(212, &[], &["start"]),
            cmd(180, &[1], &[]),
            cmd(213, &[], &["start"]),
            cmd(213, &[], &[r"\cself[0]"]),
        ];
        let p = Program::compile(&fake_event(6, "labels", slots));
        assert_eq!(p.labels.get("start"), Some(&1));
        assert_eq!(p.stats.labels, 1);
        assert_eq!(p.stats.label_jumps, 2);
        assert_eq!(p.stats.dynamic_labels, 1);
        assert_eq!(p.stats.unresolved_labels, 0);
        assert_eq!(p.dynamic_jumps, vec![3]);
        assert_eq!(p.control[2], Control::LabelJump);
    }

    #[test]
    fn unresolved_label_is_counted() {
        let slots = vec![cmd(213, &[], &["nope"])];
        let p = Program::compile(&fake_event(7, "badlabel", slots));
        assert_eq!(p.stats.unresolved_labels, 1);
    }

    #[test]
    fn missing_args_read_as_zero_instead_of_panicking() {
        let c = match cmd(180, &[], &[]) {
            Slot::Command(c) => c,
            _ => unreachable!(),
        };
        assert_eq!(argc(&c), 0);
        assert_eq!(arg(&c, 0), 0);
        assert_eq!(arg(&c, 9), 0);
    }

    #[test]
    fn arg_decodes_little_endian() {
        let c = match cmd(180, &[0x0102_0304], &[]) {
            Slot::Command(c) => c,
            _ => unreachable!(),
        };
        assert_eq!(argc(&c), 1);
        assert_eq!(arg(&c, 0), 0x0102_0304);
        assert_eq!(c.params, vec![0x04, 0x03, 0x02, 0x01]);
    }

    #[test]
    fn tag_stripping_matches_both_title_forms() {
        assert_eq!(strip_tag("[共] テスト"), "テスト");
        assert_eq!(strip_tag("plain"), "plain");
    }

    fn fake_event(
        id: u32,
        title: &str,
        commands: Vec<Slot>,
    ) -> wolf_format::commonevent::CommonEvent {
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
            return_value_id: NO_RETURN_VALUE,
        }
    }

    #[test]
    fn blank_slots_are_ignored() {
        let slots = vec![blank(), blank(), blank()];
        let p = Program::compile(&fake_event(8, "blanks", slots));
        assert_eq!(p.blocks.len(), 0);
        assert_eq!(p.stats.slots, 3);
    }
}
