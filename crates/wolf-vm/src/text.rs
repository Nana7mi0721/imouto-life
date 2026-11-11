//! Escape expansion for the subset of WOLF markup the interpreter itself needs
//! (docs/FORMAT_SPEC.md §4.6, docs/OPCODE_SPEC.md §5.39).
//!
//! Two opcodes carry strings that are *not* literal:
//!
//! * `213 JumpLabel` — the label name is a template. 5 of the 1,543 jumps in this
//!   game embed a `\cself[n]` and only match their `212 SetLabel` after
//!   expansion (docs/OPCODE_SPEC.md §4.7); resolving labels statically would send
//!   the combat/message code paths to the wrong place.
//! * `140 PlaySound`, `150 Picture`, `300 CallByName` — filenames and event names
//!   can embed variables too (e.g. `\cself[9]`).
//!
//! This module deliberately implements **only** the variable-substitution escapes.
//! Everything else (`\n` line breaks, `\c[6]` colour, `\>{...}` timed text, the
//! `@face` speaker prefix, ...) is display markup and belongs to
//! `wolf-format::messagetext`; leaving those sequences untouched here keeps this
//! function lossless, which matters because its output is used for *lookups*, not
//! for drawing.
//!
//! Expansion is innermost-first: `\cself[\cself[0]]` is a real shape in the label
//! set, so a single left-to-right pass would leave the inner escape unexpanded and
//! the lookup would fail. We therefore re-scan after each substitution.

use crate::magic::{Magic, MagicKind};

/// Which bank an escape reads from.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum EscapeBank {
    /// `\self[n]` / `\cself[n]` — the running event's self variables.
    SelfVar,
    /// `\v[n]` — ordinary variables.
    Var,
    /// `\s[n]` — ordinary string variables.
    StrVar,
    /// `\sys[n]` — system variables.
    SysVar,
}

/// What the expander needs from the running instance.
pub trait VarLookup {
    /// Read an integer bank slot.
    fn lookup_num(&mut self, bank: EscapeBank, index: usize) -> i32;
    /// Read a string bank slot.
    fn lookup_str(&mut self, bank: EscapeBank, index: usize) -> String;
    /// Read a database string cell. `None` when the host has no database.
    fn lookup_db(
        &mut self,
        _container: crate::exec::DbContainer,
        _db_type: i32,
        _row: i32,
        _column: i32,
    ) -> Option<String> {
        None
    }
}

/// A lookup that knows nothing: every escape expands to `0`.
///
/// Used by the load-time precompiler, which has no instance to ask. A label that
/// still contains an escape after expanding with this can never be resolved
/// statically, and [crate::program::Program] records it as such.
#[derive(Clone, Copy, Debug, Default)]
pub struct NoVars;

impl VarLookup for NoVars {
    fn lookup_num(&mut self, _bank: EscapeBank, _index: usize) -> i32 {
        0
    }

    fn lookup_str(&mut self, _bank: EscapeBank, _index: usize) -> String {
        String::new()
    }
}

/// Expand every variable escape in `text`.
///
/// Unrecognised escapes are copied through verbatim, so the result can be used
/// for filename and label lookup without corrupting the name. The loop is
/// bounded: 64 passes, then we give up and return what we have (a self-referential
/// label such as `\cself[\cself[0]]` where slot 0 holds text is data-dependent and
/// must never hang the interpreter).
#[must_use]
pub fn expand<L: VarLookup + ?Sized>(text: &str, lookup: &mut L) -> String {
    let mut out = text.to_owned();
    for _ in 0..64 {
        match expand_once(&out, lookup) {
            Some(next) => out = next,
            None => break,
        }
    }
    out
}

/// True when `text` contains at least one recognisable escape.
#[must_use]
pub fn has_escape(text: &str) -> bool {
    text.contains('\\')
}

/// Expand an opcode 102 choice label.
///
/// The only difference from [`expand`] is the bare `\cself[n]` shape: choice lists
/// use it for an optional action whose label is stored in a string slot. An unwritten
/// slot has no label, and WOLF paints no row for it, so this returns the string slot
/// (empty) instead of falling back to the numeric slot. The normal expander has to
/// keep that numeric fallback because `\f[\cself[19]]` selects a font size; that is a
/// numeric context, unlike a whole-label choice entry.
#[must_use]
pub fn expand_choice<L: VarLookup + ?Sized>(text: &str, lookup: &mut L) -> String {
    let trimmed = text.trim();
    if let Some((EscapeBank::SelfVar, index)) = single_escape(trimmed) {
        return lookup.lookup_str(EscapeBank::SelfVar, index);
    }
    expand(text, lookup)
}

/// Parse `text` when it is exactly one `\name[n]` escape, with no other characters.
fn single_escape(text: &str) -> Option<(EscapeBank, usize)> {
    let rest = text.strip_prefix('\\')?;
    let mut j = 0;
    let bytes = rest.as_bytes();
    while j < bytes.len() && bytes[j].is_ascii_alphabetic() {
        j += 1;
    }
    let bank = match rest.get(..j)? {
        "cself" | "self" | "cself_s" | "self_s" => EscapeBank::SelfVar,
        "v" | "corgv" => EscapeBank::Var,
        "s" | "corgs" => EscapeBank::StrVar,
        "sys" | "csys" => EscapeBank::SysVar,
        _ => return None,
    };
    let after = rest.get(j..)?;
    let digits = after.strip_prefix('[')?.strip_suffix(']')?;
    if digits.is_empty() || !digits.bytes().all(|byte| byte.is_ascii_digit()) {
        return None;
    }
    Some((bank, digits.parse().ok()?))
}

/// One innermost-first substitution pass. `None` means "nothing left to expand".
fn expand_once<L: VarLookup + ?Sized>(text: &str, lookup: &mut L) -> Option<String> {
    // Walk from the right so the *last* escape in the string is expanded first;
    // for tagged markup that is the innermost one.
    let bytes = text.as_bytes();
    let mut i = bytes.len();
    while i > 0 {
        i -= 1;
        if bytes[i] != b'\\' {
            continue;
        }
        if let Some((end, replacement)) = parse_escape(text, i, lookup) {
            let mut out = String::with_capacity(text.len() + replacement.len());
            out.push_str(&text[..i]);
            out.push_str(&replacement);
            out.push_str(&text[end..]);
            return Some(out);
        }
    }
    None
}

/// Try to parse an escape starting at `start` (the backslash).
///
/// Returns `(end_offset, replacement)` where `end_offset` is the index just past
/// the escape. `None` = not a variable escape, leave it alone.
fn parse_escape<L: VarLookup + ?Sized>(
    text: &str,
    start: usize,
    lookup: &mut L,
) -> Option<(usize, String)> {
    let rest = text.get(start + 1..)?;
    let bytes = rest.as_bytes();

    // The name is ASCII letters (`cself`, `self`, `v`, `s`, `sys`); `c` is the
    // "convert" prefix WOLF uses for numbers embedded in strings.
    let mut j = 0;
    while j < bytes.len() && bytes[j].is_ascii_alphabetic() {
        j += 1;
    }
    if j == 0 {
        return None;
    }
    let name = rest.get(..j)?;

    // Database references use a three-part index `[db_type:row:column]`:
    // `\cdb` variable DB, `\udb` user DB, `\sdb` system DB. CE258 pc1348 writes
    // `\E你是……\cdb[0:12:0]\cdb[0:12:1]哥哥。`, where 0/12 is the player-name cell
    // (columns 0 and 1 are the two string fields). Before this branch existed the
    // whole escape reached the screen verbatim.
    if matches!(name, "cdb" | "udb" | "sdb") {
        let after = rest.get(j..)?;
        if !after.starts_with('[') {
            return None;
        }
        let close = after.find(']')?;
        let body = after.get(1..close)?;
        let parts: Vec<&str> = body.split(':').collect();
        if parts.len() != 3 {
            return None;
        }
        let mut values = [0i32; 3];
        for (slot, part) in parts.iter().enumerate() {
            values[slot] = part.trim().parse().ok()?;
        }
        let container = match name {
            "cdb" => crate::exec::DbContainer::CData,
            "udb" => crate::exec::DbContainer::Data,
            _ => crate::exec::DbContainer::Sys,
        };
        let replacement = lookup
            .lookup_db(container, values[0], values[1], values[2])
            .unwrap_or_default();
        return Some((start + 1 + j + close + 1, replacement));
    }

    let bank = match name {
        "cself" | "self" => EscapeBank::SelfVar,
        "cself_s" | "self_s" => EscapeBank::SelfVar,
        "v" | "corgv" => EscapeBank::Var,
        "s" | "corgs" => EscapeBank::StrVar,
        "sys" | "csys" => EscapeBank::SysVar,
        _ => return None,
    };

    // Index form: `[123]`. A bare digit run is not used by this game's data.
    let after = rest.get(j..)?;
    if !after.starts_with('[') {
        return None;
    }
    let close = after.find(']')?;
    let digits = after.get(1..close)?;
    let index: usize = digits.trim().parse().ok()?;
    let end = start + 1 + j + close + 1;

    let replacement = match bank {
        // \s[n] is a plain string slot.
        EscapeBank::StrVar => lookup.lookup_str(bank, index),
        // \cself[n] reads the running event's self slot. Most of the time that
        // slot is a string (menu labels, filenames), but the same escape is also
        // used numerically - \f[\cself[19]] picks a font size - so fall back to
        // the integer slot when no string has been written. Without this, every
        // CE251 day-command button rendered its numeric slot (0) instead of the
        // label the event had just stored in the self string bank.
        EscapeBank::SelfVar => {
            let text = lookup.lookup_str(bank, index);
            if text.is_empty() {
                let num = lookup.lookup_num(bank, index);
                // A self slot can hold an internal database value handle
                // (1_100_000_000 + row*100 + column) that should resolve to a database
                // cell's text; until that resolution exists, render it empty rather
                // than leaking the nine-digit address into a filename, label or picture
                // string (the save/load slot labels printed exactly such a handle).
                if Magic::decode(num).kind() == MagicKind::DbCell {
                    String::new()
                } else {
                    num.to_string()
                }
            } else {
                text
            }
        }
        _ => lookup.lookup_num(bank, index).to_string(),
    };
    Some((end, replacement))
}

/// Resolve a magic operand to an integer using `lookup`.
///
/// Shared by the interpreter and the trace host so both agree on what
/// `-1_000_000` ("leave unchanged") and literals mean.
#[must_use]
pub fn eval_magic<L: VarLookup + ?Sized>(magic: Magic, lookup: &mut L) -> i32 {
    match magic.kind() {
        MagicKind::Literal => magic.index() as i32,
        MagicKind::SelfVar => lookup.lookup_num(EscapeBank::SelfVar, magic.index() as usize),
        MagicKind::Var => lookup.lookup_num(EscapeBank::Var, magic.index() as usize),
        MagicKind::SysVar => lookup.lookup_num(EscapeBank::SysVar, magic.index() as usize),
        // A string bank read in an integer context is a data error; WOLF yields 0.
        MagicKind::StrVar | MagicKind::CommonSelf | MagicKind::DbCell | MagicKind::Opaque => 0,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    struct Fixed {
        self_nums: Vec<i32>,
        self_strs: Vec<String>,
        nums: Vec<i32>,
        strs: Vec<String>,
    }

    impl VarLookup for Fixed {
        fn lookup_num(&mut self, bank: EscapeBank, index: usize) -> i32 {
            match bank {
                EscapeBank::SelfVar => self.self_nums.get(index).copied().unwrap_or(0),
                EscapeBank::SysVar => 99,
                _ => self.nums.get(index).copied().unwrap_or(0),
            }
        }

        fn lookup_str(&mut self, bank: EscapeBank, index: usize) -> String {
            match bank {
                EscapeBank::SelfVar => self.self_strs.get(index).cloned().unwrap_or_default(),
                _ => self.strs.get(index).cloned().unwrap_or_default(),
            }
        }

        fn lookup_db(
            &mut self,
            container: crate::exec::DbContainer,
            db_type: i32,
            row: i32,
            column: i32,
        ) -> Option<String> {
            (container == crate::exec::DbContainer::CData
                && db_type == 0
                && row == 12
                && column == 0)
                .then(|| "英雄".to_owned())
        }
    }

    fn fixed() -> Fixed {
        Fixed {
            self_nums: vec![7, 8, 9],
            self_strs: vec![String::new(); 6],
            nums: vec![100, 200],
            strs: vec!["sfx".into()],
        }
    }

    #[test]
    fn database_escapes_expand_to_the_named_cell() {
        let mut f = fixed();
        // CE258 pc1348 writes the player name this way: the two string fields of
        // CData type 0 row 12 are columns 0 and 1.
        let out = expand(r"\E你是……\cdb[0:12:0]哥哥。", &mut f);
        assert_eq!(out, r"\E你是……英雄哥哥。");
        // A cell the host does not know (or a host with no database) is empty, not
        // the literal escape, which is what used to reach the message window.
        assert_eq!(expand(r"\cdb[0:13:0]", &mut f), "");
        assert_eq!(expand(r"\udb[1:2:3]", &mut f), "");
        assert_eq!(expand(r"\sdb[1:2:3]", &mut f), "");
        assert_eq!(
            expand(r"before \cdb[0:12:0] after", &mut f),
            "before 英雄 after"
        );
    }

    #[test]
    fn no_escape_is_returned_unchanged() {
        let mut f = fixed();
        assert_eq!(expand("plain text", &mut f), "plain text");
        assert!(!has_escape("plain text"));
    }

    #[test]
    fn self_variable_substitution() {
        let mut f = fixed();
        assert_eq!(expand("front\\cself[0]", &mut f), "front7");
        assert_eq!(expand("a\\self[1]b", &mut f), "a8b");
        assert_eq!(expand("\\cself[2]", &mut f), "9");
    }

    #[test]
    fn self_string_takes_precedence_over_the_numeric_slot() {
        // CE251 stores "学习会" in self string 5 and leaves numeric slot 5 at 0;
        // \cself[5] must draw the label, not the slot.
        let mut f = fixed();
        f.self_strs[5] = "学习会".into();
        assert_eq!(expand(r"\cself[5]", &mut f), "学习会");
        // With no string written, the numeric fallback still drives font sizes.
        assert_eq!(expand(r"\cself[1]", &mut f), "8");
    }

    #[test]
    fn choice_labels_hide_an_unwritten_self_string() {
        let mut f = fixed();
        // A bare \cself[n] option is a label slot, not a number: when the branch did
        // not fill it the menu must paint no row at all (the retail five-row menu).
        assert_eq!(expand_choice(r"\cself[1]", &mut f), "");
        f.self_strs[5] = "想做爱".into();
        assert_eq!(expand_choice(r"\cself[5]", &mut f), "想做爱");
        // Only the whole-label shape is special; embedded escapes keep the numeric
        // fallback that font-size markup relies on.
        assert_eq!(expand_choice(r"label \cself[1]", &mut f), "label 8");
    }

    #[test]
    fn other_banks() {
        let mut f = fixed();
        assert_eq!(expand("\\v[1]", &mut f), "200");
        assert_eq!(expand("\\s[0]", &mut f), "sfx");
        assert_eq!(expand("\\sys[3]", &mut f), "99");
    }

    #[test]
    fn nested_escapes_expand_innermost_first() {
        // \cself[\cself[0]] with slot 0 = 7 -> \cself[7] -> 0 (slot 7 unwritten)
        let mut f = fixed();
        assert_eq!(expand("\\cself[\\cself[0]]", &mut f), "0");
    }

    #[test]
    fn display_markup_is_left_alone() {
        let mut f = fixed();
        // These are messagetext's job; corrupting them would break filenames.
        for raw in ["\\c[6]text\\c[0]", "line\\nbreak", "@2 face", "\\>{}"] {
            assert_eq!(expand(raw, &mut f), raw, "raw: {raw}");
        }
        // Inside display markup the *markup* survives but a variable escape is
        // still a variable escape — the engine evaluates it before laying out.
        assert_eq!(expand("\\>{\\cself[0]}", &mut f), "\\>{7}");
    }

    #[test]
    fn malformed_escapes_never_panic() {
        let mut f = fixed();
        for raw in [
            "\\",
            "\\[0]",
            "\\cself",
            "\\cself[",
            "\\cself[x]",
            "\\cself[-1]",
        ] {
            let _ = expand(raw, &mut f);
        }
    }

    #[test]
    fn self_referential_escape_terminates() {
        struct Loop;
        impl VarLookup for Loop {
            fn lookup_num(&mut self, _bank: EscapeBank, _index: usize) -> i32 {
                // Always produces text that expands again.
                0
            }
            fn lookup_str(&mut self, _bank: EscapeBank, _index: usize) -> String {
                "\\cself[0]".into()
            }
        }
        // Bounded at 64 passes; must return rather than hang.
        let mut lookup = Loop;
        let out = expand("\\s[0]", &mut lookup);
        assert!(!out.is_empty());
    }

    #[test]
    fn eval_magic_covers_every_bank() {
        let mut f = fixed();
        assert_eq!(eval_magic(Magic::decode(42), &mut f), 42);
        assert_eq!(eval_magic(Magic::decode(2_000_001), &mut f), 200);
        assert_eq!(eval_magic(Magic::decode(1_000_001), &mut f), 8);
        assert_eq!(eval_magic(Magic::decode(9_000_000), &mut f), 99);
        // Opaque sentinels read as 0, never as a bogus slot.
        assert_eq!(eval_magic(Magic::decode(-1_000_000), &mut f), 0);
    }
}
