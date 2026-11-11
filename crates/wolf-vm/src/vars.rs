//! Variable storage (docs/OPCODE_SPEC.md §2.1, §2.2).
//!
//! Every store is a flat `Vec` indexed by the decoded slot number, for a reason
//! that comes straight out of the instruction census: this game executes 17,258
//! `121 SetVariable` and 10,743 `111 ConditionalBranch` instructions, and each
//! one does at least one read plus one write. A `HashMap<i32, i32>` would put a
//! hash + probe on that path and, more importantly, would make "variable 7000 was
//! never touched" indistinguishable from "variable 7000 is 0" — WOLF treats a
//! variable that was never written as 0, so the sparse representation buys
//! nothing and costs a branch on every access.
//!
//! The four banks are distinct namespaces and **must not share storage**:
//!
//! * `nums` — ordinary variables, magic `2_000_000 + n` (17,258 writes).
//! * `strings` — ordinary string variables, magic `3_000_000 + n`. The numbers
//!   overlap the int bank on purpose (both use `0, 1, 2, ...`), so a string
//!   write must never touch `nums`.
//! * `sys_nums` / `sys_strings` — system variables, magic `9_000_000 + n`.
//!
//! Self variables live per coroutine ([crate::exec::Instance]), not here: two
//! instances of the same common event have independent self variables, which is
//! exactly what the menus rely on. One exception lives here: the durable banks of
//! common events, because the manual encodes cross-event access as
//! `15_000_000 + 100*event + slot`.

use std::collections::BTreeMap;

/// Slot count above which we stop growing silently and start warning.
///
/// The real game addresses at most a few thousand ordinary variables and 33
/// system variables (`9_000_033` is the highest seen). The ceiling exists so a
/// corrupt magic number (say `2_999_999`) cannot allocate 12 MB by accident.
pub const MAX_SLOTS: usize = 1_000_000;

/// The global variable banks.
#[derive(Clone, Debug)]
pub struct Variables {
    nums: Vec<i32>,
    strings: Vec<String>,
    sys_nums: Vec<i32>,
    sys_strings: Vec<String>,
    /// Durable common-event self banks, addressable from any script as
    /// `15_000_000 + 100*event + slot` (manual 06valueget: コモンEv Y の
    /// コモンセルフ変数 X). Keeping them beside the other banks lets the
    /// interpreter resolve the message library's cross-event string writes.
    pub common_self: BTreeMap<u32, EventSelfVars>,
}

impl Default for Variables {
    fn default() -> Self {
        Self::new()
    }
}

impl Variables {
    /// An empty bank set. Slots grow on first write (docs/OPCODE_SPEC.md §2.1:
    /// WOLF variables are 0 until written).
    #[must_use]
    pub fn new() -> Self {
        Self {
            nums: Vec::new(),
            strings: Vec::new(),
            sys_nums: Vec::new(),
            sys_strings: Vec::new(),
            common_self: BTreeMap::new(),
        }
    }

    /// Pre-size the banks so the first frame does not allocate.
    #[must_use]
    pub fn with_capacity(nums: usize, strings: usize, sys: usize) -> Self {
        Self {
            nums: vec![0; nums],
            strings: vec![String::new(); strings],
            sys_nums: vec![0; sys],
            sys_strings: Vec::new(),
            common_self: BTreeMap::new(),
        }
    }

    /// Read an ordinary integer variable.
    #[must_use]
    pub fn get(&self, index: usize) -> i32 {
        self.nums.get(index).copied().unwrap_or(0)
    }

    /// Write an ordinary integer variable, growing the bank as needed.
    pub fn set(&mut self, index: usize, value: i32) {
        if index >= MAX_SLOTS {
            return;
        }
        if index >= self.nums.len() {
            self.nums.resize(index + 1, 0);
        }
        self.nums[index] = value;
    }

    /// Read an ordinary string variable.
    #[must_use]
    pub fn get_str(&self, index: usize) -> &str {
        self.strings.get(index).map_or("", String::as_str)
    }

    /// Write an ordinary string variable.
    pub fn set_str(&mut self, index: usize, value: &str) {
        if index >= MAX_SLOTS {
            return;
        }
        if index >= self.strings.len() {
            self.strings.resize(index + 1, String::new());
        }
        let slot = &mut self.strings[index];
        slot.clear();
        slot.push_str(value);
    }

    /// Read a system integer variable.
    #[must_use]
    pub fn get_sys(&self, index: usize) -> i32 {
        self.sys_nums.get(index).copied().unwrap_or(0)
    }

    /// Write a system integer variable.
    pub fn set_sys(&mut self, index: usize, value: i32) {
        if index >= MAX_SLOTS {
            return;
        }
        if index >= self.sys_nums.len() {
            self.sys_nums.resize(index + 1, 0);
        }
        self.sys_nums[index] = value;
    }

    /// Read a system string variable.
    #[must_use]
    pub fn get_sys_str(&self, index: usize) -> &str {
        self.sys_strings.get(index).map_or("", String::as_str)
    }

    /// Write a system string variable.
    pub fn set_sys_str(&mut self, index: usize, value: &str) {
        if index >= MAX_SLOTS {
            return;
        }
        if index >= self.sys_strings.len() {
            self.sys_strings.resize(index + 1, String::new());
        }
        let slot = &mut self.sys_strings[index];
        slot.clear();
        slot.push_str(value);
    }

    /// Number of allocated ordinary integer slots (for the trace/save layers).
    #[must_use]
    pub fn len(&self) -> usize {
        self.nums.len()
    }

    /// True when nothing has been allocated yet.
    #[must_use]
    pub fn is_empty(&self) -> bool {
        self.nums.is_empty()
    }
}

/// Self variables of one common event, outside any running coroutine.
///
/// WOLF stores a common event's self variables in the event (100 numeric slots,
/// CSelf0..CSelf99, plus the five string slots CSelf5..CSelf9) and a save carries all
/// of them, including events that are not running. The interpreter needs the same
/// durable bank: a coroutine starting after a load must see what the previous
/// invocation left, not zeros.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct EventSelfVars {
    nums: Vec<i32>,
    strings: Vec<String>,
}

/// Numeric self slots a common event persists.
pub const EVENT_SELF_SLOTS: usize = crate::magic::SELF_SLOTS_PER_GROUP;
/// String self slots a common event persists (CSelf5..CSelf9).
pub const EVENT_SELF_STRINGS: usize = 5;

impl Default for EventSelfVars {
    fn default() -> Self {
        Self::new()
    }
}

impl EventSelfVars {
    /// An all-zero bank, matching a common event that never ran.
    #[must_use]
    pub fn new() -> Self {
        Self {
            nums: vec![0; EVENT_SELF_SLOTS],
            strings: vec![String::new(); EVENT_SELF_STRINGS],
        }
    }

    /// Read numeric slot `slot` (0..100).
    #[must_use]
    pub fn get(&self, slot: usize) -> i32 {
        self.nums.get(slot).copied().unwrap_or(0)
    }

    /// Write numeric slot `slot`; out-of-range slots are ignored.
    pub fn set(&mut self, slot: usize, value: i32) {
        if let Some(cell) = self.nums.get_mut(slot) {
            *cell = value;
        }
    }

    /// Read string slot `slot` (0..5, i.e. CSelf5..CSelf9).
    #[must_use]
    pub fn get_str(&self, slot: usize) -> &str {
        self.strings.get(slot).map_or("", String::as_str)
    }

    /// Write string slot `slot`; out-of-range slots are ignored.
    pub fn set_str(&mut self, slot: usize, value: &str) {
        if let Some(cell) = self.strings.get_mut(slot) {
            cell.clear();
            cell.push_str(value);
        }
    }
}

/// One coroutine's self variables.
///
/// WOLF addresses self variables as `1_000_000 + group*100_000 + slot` with
/// `group` in `0..=9`, i.e. `V0-0 .. V9-99` (docs/OPCODE_SPEC.md §2.2). That
/// flattens to a 1000-entry window, see [crate::magic::self_slot].
#[derive(Clone, Debug)]
pub struct SelfVars {
    nums: Vec<i32>,
    strings: Vec<String>,
}

/// Flattened self-variable slots: 10 groups x 100 slots.
pub const SELF_SLOTS: usize = crate::magic::SELF_GROUPS * crate::magic::SELF_SLOTS_PER_GROUP;

impl Default for SelfVars {
    fn default() -> Self {
        Self::new()
    }
}

impl SelfVars {
    /// A fresh set, all zero / empty, matching a just-started event.
    #[must_use]
    pub fn new() -> Self {
        Self {
            nums: vec![0; SELF_SLOTS],
            strings: vec![String::new(); SELF_SLOTS],
        }
    }

    /// Read a self variable.
    #[must_use]
    pub fn get(&self, index: usize) -> i32 {
        self.nums.get(index).copied().unwrap_or(0)
    }

    /// Write a self variable. Out-of-window indices are ignored rather than
    /// growing the bank: the window is a fixed 10x100 in the original.
    pub fn set(&mut self, index: usize, value: i32) {
        if let Some(slot) = self.nums.get_mut(index) {
            *slot = value;
        }
    }

    /// Read a self string variable.
    #[must_use]
    pub fn get_str(&self, index: usize) -> &str {
        self.strings.get(index).map_or("", String::as_str)
    }

    /// Write a self string variable.
    pub fn set_str(&mut self, index: usize, value: &str) {
        if let Some(slot) = self.strings.get_mut(index) {
            slot.clear();
            slot.push_str(value);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn unwritten_variables_read_as_zero() {
        let v = Variables::new();
        assert_eq!(v.get(0), 0);
        assert_eq!(v.get(4_000), 0);
        assert_eq!(v.get_sys(24), 0);
        assert_eq!(v.get_str(0), "");
        assert!(v.is_empty());
    }

    #[test]
    fn int_and_string_banks_are_independent() {
        let mut v = Variables::new();
        v.set(9, 1234);
        v.set_str(9, "hello");
        assert_eq!(v.get(9), 1234);
        assert_eq!(v.get_str(9), "hello");
        // Writing the string must not have touched the integer.
        v.set_str(9, "bye");
        assert_eq!(v.get(9), 1234);
        // Nor the other way round.
        v.set(9, 7);
        assert_eq!(v.get_str(9), "bye");
    }

    #[test]
    fn system_bank_is_separate_from_the_ordinary_bank() {
        let mut v = Variables::new();
        v.set(24, 1);
        v.set_sys(24, 2);
        assert_eq!(v.get(24), 1);
        assert_eq!(v.get_sys(24), 2);
    }

    #[test]
    fn grow_on_write_keeps_earlier_slots() {
        let mut v = Variables::new();
        v.set(3, 33);
        v.set(500, 55);
        assert_eq!(v.get(3), 33);
        assert_eq!(v.get(500), 55);
        assert_eq!(v.len(), 501);
    }

    #[test]
    fn absurd_indices_are_dropped_not_allocated() {
        let mut v = Variables::new();
        v.set(2_999_999, 1);
        assert_eq!(v.len(), 0);
        assert_eq!(v.get(2_999_999), 0);
    }

    #[test]
    fn self_vars_are_fixed_window() {
        let mut sv = SelfVars::new();
        assert_eq!(sv.get(699), 0);
        sv.set(699, 42);
        assert_eq!(sv.get(699), 42);
        // Out of window is a silent no-op, never a panic.
        sv.set(5_000, 1);
        assert_eq!(sv.get(5_000), 0);
        sv.set_str(0, "x");
        assert_eq!(sv.get_str(0), "x");
    }
}
