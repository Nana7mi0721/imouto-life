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
    fn lookup_num(&self, bank: EscapeBank, index: usize) -> i32;
    /// Read a string bank slot.
    fn lookup_str(&self, bank: EscapeBank, index: usize) -> String;
}

/// A lookup that knows nothing: every escape expands to `0`.
///
/// Used by the load-time precompiler, which has no instance to ask. A label that
/// still contains an escape after expanding with this can never be resolved
/// statically, and [crate::program::Program] records it as such.
#[derive(Clone, Copy, Debug, Default)]
pub struct NoVars;

impl VarLookup for NoVars {
    fn lookup_num(&self, _bank: EscapeBank, _index: usize) -> i32 {
        0
    }

    fn lookup_str(&self, _bank: EscapeBank, _index: usize) -> String {
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
pub fn expand<L: VarLookup + ?Sized>(text: &str, lookup: &L) -> String {
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

/// One innermost-first substitution pass. `None` means "nothing left to expand".
fn expand_once<L: VarLookup + ?Sized>(text: &str, lookup: &L) -> Option<String> {
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
    lookup: &L,
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
                lookup.lookup_num(bank, index).to_string()
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
pub fn eval_magic<L: VarLookup + ?Sized>(magic: Magic, lookup: &L) -> i32 {
    match magic.kind() {
        MagicKind::Literal => magic.index() as i32,
        MagicKind::SelfVar => lookup.lookup_num(EscapeBank::SelfVar, magic.index() as usize),
        MagicKind::Var => lookup.lookup_num(EscapeBank::Var, magic.index() as usize),
        MagicKind::SysVar => lookup.lookup_num(EscapeBank::SysVar, magic.index() as usize),
        // A string bank read in an integer context is a data error; WOLF yields 0.
        MagicKind::StrVar | MagicKind::Opaque => 0,
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
        fn lookup_num(&self, bank: EscapeBank, index: usize) -> i32 {
            match bank {
                EscapeBank::SelfVar => self.self_nums.get(index).copied().unwrap_or(0),
                EscapeBank::SysVar => 99,
                _ => self.nums.get(index).copied().unwrap_or(0),
            }
        }

        fn lookup_str(&self, bank: EscapeBank, index: usize) -> String {
            match bank {
                EscapeBank::SelfVar => self.self_strs.get(index).cloned().unwrap_or_default(),
                _ => self.strs.get(index).cloned().unwrap_or_default(),
            }
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
    fn no_escape_is_returned_unchanged() {
        let f = fixed();
        assert_eq!(expand("plain text", &f), "plain text");
        assert!(!has_escape("plain text"));
    }

    #[test]
    fn self_variable_substitution() {
        let f = fixed();
        assert_eq!(expand("front\\cself[0]", &f), "front7");
        assert_eq!(expand("a\\self[1]b", &f), "a8b");
        assert_eq!(expand("\\cself[2]", &f), "9");
    }

    #[test]
    fn self_string_takes_precedence_over_the_numeric_slot() {
        // CE251 stores "学习会" in self string 5 and leaves numeric slot 5 at 0;
        // \cself[5] must draw the label, not the slot.
        let mut f = fixed();
        f.self_strs[5] = "学习会".into();
        assert_eq!(expand(r"\cself[5]", &f), "学习会");
        // With no string written, the numeric fallback still drives font sizes.
        assert_eq!(expand(r"\cself[1]", &f), "8");
    }

    #[test]
    fn other_banks() {
        let f = fixed();
        assert_eq!(expand("\\v[1]", &f), "200");
        assert_eq!(expand("\\s[0]", &f), "sfx");
        assert_eq!(expand("\\sys[3]", &f), "99");
    }

    #[test]
    fn nested_escapes_expand_innermost_first() {
        // \cself[\cself[0]] with slot 0 = 7 -> \cself[7] -> 0 (slot 7 unwritten)
        let f = fixed();
        assert_eq!(expand("\\cself[\\cself[0]]", &f), "0");
    }

    #[test]
    fn display_markup_is_left_alone() {
        let f = fixed();
        // These are messagetext's job; corrupting them would break filenames.
        for raw in ["\\c[6]text\\c[0]", "line\\nbreak", "@2 face", "\\>{}"] {
            assert_eq!(expand(raw, &f), raw, "raw: {raw}");
        }
        // Inside display markup the *markup* survives but a variable escape is
        // still a variable escape — the engine evaluates it before laying out.
        assert_eq!(expand("\\>{\\cself[0]}", &f), "\\>{7}");
    }

    #[test]
    fn malformed_escapes_never_panic() {
        let f = fixed();
        for raw in [
            "\\",
            "\\[0]",
            "\\cself",
            "\\cself[",
            "\\cself[x]",
            "\\cself[-1]",
        ] {
            let _ = expand(raw, &f);
        }
    }

    #[test]
    fn self_referential_escape_terminates() {
        struct Loop;
        impl VarLookup for Loop {
            fn lookup_num(&self, _bank: EscapeBank, _index: usize) -> i32 {
                // Always produces text that expands again.
                0
            }
            fn lookup_str(&self, _bank: EscapeBank, _index: usize) -> String {
                "\\cself[0]".into()
            }
        }
        // Bounded at 64 passes; must return rather than hang.
        let out = expand("\\s[0]", &Loop);
        assert!(!out.is_empty());
    }

    #[test]
    fn eval_magic_covers_every_bank() {
        let f = fixed();
        assert_eq!(eval_magic(Magic::decode(42), &f), 42);
        assert_eq!(eval_magic(Magic::decode(2_000_001), &f), 200);
        assert_eq!(eval_magic(Magic::decode(1_000_001), &f), 8);
        assert_eq!(eval_magic(Magic::decode(9_000_000), &f), 99);
        // Opaque sentinels read as 0, never as a bogus slot.
        assert_eq!(eval_magic(Magic::decode(-1_000_000), &f), 0);
    }
}
