//! WOLF's "magic number" addressing scheme (docs/OPCODE_SPEC.md §2).
//!
//! A single `i32` encodes both *where a value lives* and *which value it is*:
//!
//! | range | meaning |
//! |---|---|
//! | `0 ..= 999_999` | literal |
//! | `1_000_000 ..= 1_999_999` | event self variable |
//! | `2_000_000 ..= 2_999_999` | ordinary variable ("可変DB[0] 通常変数") |
//! | `3_000_000 ..= 3_999_999` | string variable (only meaningful in string ops) |
//! | `9_000_000 ..= 9_999_999` | system variable (系統DB[14]) |
//!
//! Two wrinkles make this more than a `match`:
//!
//! * **High flag bits.** 112/125/126 carry `0x1/0x2/0x3 << 28` flags on top of a
//!   normal value (docs/OPCODE_SPEC.md §2.3). We keep them in [`Magic::flags`]
//!   and compare them raw, which is what the original appears to do — the flags
//!   are documented as unresolved, so the safest behaviour is to not interpret
//!   them at all.
//! * **The self-variable bank is not flat.** This game's data addresses self
//!   slots as `1_000_000 + group*100_000 + slot` where `group` is 0..=9
//!   (`V0-0 .. V9-99`, docs/OPCODE_SPEC.md §2.2). `1_600_000` is group 6, slot 0,
//!   so the flat index is `6*100 + 0`, not `600_000`.
//!
//! Negative values are *not* magic numbers: `-1`/`-2`/`-1000000` are opcode
//! specific sentinels (docs/OPCODE_SPEC.md §2.4) and surfaces as
//! [`MagicKind::Opaque`], which reads back as the raw value.

/// Base of the event-self bank.
pub const SELF_BASE: i32 = 1_000_000;
/// Base of the ordinary-variable bank.
pub const VAR_BASE: i32 = 2_000_000;
/// Base of the string-variable bank.
pub const STR_BASE: i32 = 3_000_000;
/// Base of the system-variable bank.
pub const SYS_BASE: i32 = 9_000_000;
/// Slots per self-variable group (docs/OPCODE_SPEC.md §2.2).
pub const SELF_GROUP_STRIDE: usize = 100_000;
/// Number of slots inside one self-variable group.
pub const SELF_SLOTS_PER_GROUP: usize = 100;
/// Number of self-variable groups (`V0-0 .. V9-99`).
pub const SELF_GROUPS: usize = 10;

/// First flat self-variable slot used to receive call arguments.
///
/// WOLF passes the arguments of `210 CallCommonEvent` / `300 CallByName` into
/// the child's **self variable group 6**, i.e. magic `1_600_000 + i`. Measured
/// over 9,938 static calls whose callee touches a self variable within its
/// first 12 instructions: 42,435 references point into group 6 and only 121
/// into group 0, and the most frequent first reference is exactly
/// `1_600_000` (7,953 calls). Common event 221 (the loading bar) is the
/// clearest case: callers pass [progress_step, mode] as `1_600_000` /
/// `1_600_001`, and the event uses `1_600_001` as its mode switch and
/// `1_600_000` as the random step of its progress bar.
pub const SELF_ARG_BASE: usize = 6 * SELF_SLOTS_PER_GROUP;

/// What a magic number refers to.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum MagicKind {
    /// A constant.
    Literal,
    /// An event self variable.
    SelfVar,
    /// An ordinary variable.
    Var,
    /// A string variable.
    StrVar,
    /// A system variable.
    SysVar,
    /// Out of range, negative, or carrying unresolved flag bits: use the raw
    /// value and do not try to dereference it.
    Opaque,
}

/// A decoded magic number.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Magic {
    /// The value exactly as stored in the instruction.
    raw: i32,
    /// What kind of storage [`Magic::raw`] points at.
    kind: MagicKind,
    /// The decoded slot index, or the literal value itself for
    /// [`MagicKind::Literal`].
    index: u32,
}

impl Magic {
    /// Decode one raw instruction argument.
    #[must_use]
    pub fn decode(raw: i32) -> Self {
        // Flags live in the top nibble (docs/OPCODE_SPEC.md §2.3). Masking them
        // off before classifying is what lets the flagged 112 operands still
        // resolve to a real variable; the flag itself is kept in `raw`.
        let flags = (raw >> 28) as u8 & 0x0F;
        let body = raw & 0x0FFF_FFFF;
        let (kind, index) = if flags != 0 && (SELF_BASE..STR_BASE).contains(&body) {
            // Flagged operand that still names a variable.
            classify(body)
        } else if flags != 0 {
            (MagicKind::Opaque, 0)
        } else {
            classify(body)
        };
        Self { raw, kind, index }
    }

    /// The value as stored in the instruction.
    #[must_use]
    pub const fn raw(self) -> i32 {
        self.raw
    }

    /// What this magic number refers to.
    #[must_use]
    pub const fn kind(self) -> MagicKind {
        self.kind
    }

    /// The slot index (or the literal value).
    #[must_use]
    pub const fn index(self) -> u32 {
        self.index
    }

    /// The unresolved flag nibble (docs/OPCODE_SPEC.md §2.3).
    #[must_use]
    pub const fn flags(self) -> u8 {
        (self.raw >> 28) as u8 & 0x0F
    }

    /// True when this operand names a storage slot rather than a constant.
    #[must_use]
    pub const fn is_storage(self) -> bool {
        !matches!(self.kind, MagicKind::Literal | MagicKind::Opaque)
    }

    /// True when the value must be read from (or written to) the string bank.
    #[must_use]
    pub const fn is_string(self) -> bool {
        matches!(self.kind, MagicKind::StrVar)
    }
}

/// Classify a flag-stripped value.
fn classify(body: i32) -> (MagicKind, u32) {
    match body {
        0..=999_999 => (MagicKind::Literal, body as u32),
        // These three banks are adjacent, so every arm must stop at the next
        // base: a 2_000_007 is a *variable*, not a self slot at 1_000_007.
        SELF_BASE..VAR_BASE => (MagicKind::SelfVar, self_slot(body)),
        VAR_BASE..STR_BASE => (MagicKind::Var, (body - VAR_BASE) as u32),
        STR_BASE..4_000_000 => (MagicKind::StrVar, (body - STR_BASE) as u32),
        SYS_BASE..=9_999_999 => (MagicKind::SysVar, (body - SYS_BASE) as u32),
        _ => (MagicKind::Opaque, 0),
    }
}

/// Flatten `1_000_000 + group*100_000 + slot` into `group*100 + slot`.
///
/// Docs/OPCODE_SPEC.md §2.2 quotes WolfTL's comment: `V1-0 - V9-0 = (id / 100000)`.
/// This game only ever uses groups 0, 1 and 6, but the formula is applied
/// uniformly so a different WOLF build cannot surprise us.
#[must_use]
pub fn self_slot(value: i32) -> u32 {
    let id = (value - SELF_BASE).max(0);
    let group = (id / SELF_GROUP_STRIDE as i32) as usize;
    let slot = (id % SELF_GROUP_STRIDE as i32) as usize;
    if group == 0 {
        // Group 0 is the flat 0..=99 window (`1_000_000` alone is slot 0, and
        // `1_100_004` starts at 100): a bare `1_000_0nn` is slot nn directly.
        (slot % SELF_SLOTS_PER_GROUP) as u32
    } else {
        (group.min(SELF_GROUPS - 1) * SELF_SLOTS_PER_GROUP + slot) as u32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn literals_and_banks() {
        assert_eq!(Magic::decode(0).kind(), MagicKind::Literal);
        assert_eq!(Magic::decode(30).index(), 30);
        assert_eq!(Magic::decode(2_000_007).kind(), MagicKind::Var);
        assert_eq!(Magic::decode(2_000_007).index(), 7);
        assert_eq!(Magic::decode(3_000_009).kind(), MagicKind::StrVar);
        assert_eq!(Magic::decode(3_000_009).index(), 9);
        assert_eq!(Magic::decode(9_000_024).kind(), MagicKind::SysVar);
        assert_eq!(Magic::decode(9_000_024).index(), 24);
    }

    #[test]
    fn self_groups_flatten() {
        // Group 0: the plain 0..99 window.
        assert_eq!(Magic::decode(1_000_000).index(), 0);
        // Group 1 slot 0 and slot 4 (the data uses 1_100_000 and 1_100_004..6).
        assert_eq!(Magic::decode(1_100_000).index(), 100);
        assert_eq!(Magic::decode(1_100_004).index(), 104);
        // Group 6: the most frequent self bank in this game (1_600_000..1_600_099).
        assert_eq!(Magic::decode(1_600_000).index(), 600);
        assert_eq!(Magic::decode(1_600_099).index(), 699);
    }

    #[test]
    fn sentinels_stay_opaque() {
        for raw in [-1, -2, -1_000_000] {
            let m = Magic::decode(raw);
            assert_eq!(m.kind(), MagicKind::Opaque, "raw {raw}");
            assert_eq!(m.raw(), raw);
            assert!(!m.is_storage());
        }
    }

    #[test]
    fn flagged_operands_keep_their_flag_and_their_variable() {
        // 0x30000000 | 1_600_005 — the shape seen in 112 string conditions.
        let raw: i32 = 0x3000_0000 | 1_600_005;
        let m = Magic::decode(raw);
        assert_eq!(m.flags(), 3);
        assert_eq!(m.kind(), MagicKind::SelfVar);
        assert_eq!(m.index(), 605);
        assert_eq!(m.raw(), raw);
        // 0x20000000 | 1_600_012 — 211 CommonEventReserve target.
        let m = Magic::decode((0x2000_0000i32) | 1_600_012);
        assert_eq!(m.flags(), 2);
        assert_eq!(m.kind(), MagicKind::SelfVar);
        assert_eq!(m.index(), 612);
    }
}
