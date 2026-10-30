//! Inline text markup: the tokeniser for message strings carried by opcode 101.
//!
//! A message string is not plain text. It is literal characters interleaved with
//! half-width backslash codes that change drawing state (colour, outline, font
//! size), inject values (`\v[12]`, `\cself[13]`, `\cdb[21:78:0]`), or drive the
//! typewriter (`\sp[40]`, `\.`, `\!`). The renderer cannot draw the raw string
//! and the VM cannot execute it, so both consume the token list produced here.
//!
//! Grammar: docs/TEXT_SPEC.md section 2 lists every documented code, section 3
//! records which of them this game actually ships. Every code is half-width
//! ASCII and case-sensitive — `\E` is not `\e`, and the full-width yen sign that
//! some reference pages print for `\A+` is a rendering artefact, not part of the
//! syntax.
//!
//! Three invariants, each covered by tests/messagetext.rs:
//!
//! 1. [`tokenize`] never panics, whatever bytes it is handed. An unclosed bracket,
//!    a trailing backslash, a lone `<` — all degrade to literal text.
//! 2. No byte is silently dropped. An unrecognised escape stays literal, and
//!    [`to_source`] re-renders every accepted construct back to its exact
//!    spelling, so to_source(tokenize(s)) == s holds for all 12,027 shipped
//!    messages.
//! 3. `\E` is a token, not a decoration on a text run. The renderer draws an
//!    outlined run as four offset copies of the same glyphs, so flattening `\E`
//!    into styled text would lose the draw order the original engine relies on.
//!
//! Why those three, in order:
//!
//! Lossless round-tripping is the load-bearing one. A message string is game
//! data the player can never edit but the tooling must: a future editor writes
//! the string back into CommonEvent.dat, and a tokeniser that normalises
//! `\c[07]` to `\c[7]` or drops an escape it did not recognise would corrupt
//! the file. Keeping [`to_source`] an exact inverse makes editing safe by
//! construction, and it is also what lets the test assert over all 12,027
//! shipped strings rather than over hand-picked samples.
//!
//! Never panicking matters because the input is untrusted data from a file, not
//! a literal in our source. A save file, a fan translation or a modded
//! CommonEvent.dat can contain a half-written escape; a panic there would take
//! the whole game down on a load, so every malformed construct degrades to the
//! literal bytes instead.
//!
//! Passing unknown escapes through as literal text is the same principle seen
//! from the data side. WOLF's grammar is larger than any one game uses, and a
//! game may carry codes this build has never heard of. Guessing would silently
//! change what the player reads; leaving the bytes alone means an unknown code
//! shows up as visible garbage — obvious, reportable, and fixable by adding one
//! row to the table.
//!
//! Substitution is deliberately not done here. Resolving `\v[12]` needs VM state
//! this crate does not have, so the split is: this module recovers structure and
//! keeps a nested escape such as `\cself[\v[12]]` intact as [`TextToken::Var`],
//! and `wolf_vm::text::expand` walks the token list afterwards to turn each
//! [`TextToken::Var`] into digits. See docs/TEXT_SPEC.md section 5 for the
//! recommended call shape.

use std::fmt;
use std::fmt::Write as _;

/// Deepest bracket nesting [tokenize] descends into.
///
/// WOLF nests one level in practice (`\cdb[0:\cdb[6:0:1]:0]`); the limit exists
/// only so that pathological input cannot recurse without bound. Past the limit
/// a backslash is literal text.
pub const MAX_DEPTH: u8 = 8;

/// Per-line alignment, set by the `<L>`, `<C>` and `<R>` tags.
///
/// Alignment is measured against the widest line of the whole message, so a
/// single-line message always renders left-aligned no matter what it asks for
/// (docs/TEXT_SPEC.md section 2.9).
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Align {
    /// `<L>` — the default, and the only alignment a single-line message can use.
    Left,
    /// `<C>`.
    Center,
    /// `<R>`.
    Right,
}

impl Align {
    /// The tag that produces this alignment.
    #[must_use]
    pub fn tag(self) -> &'static str {
        match self {
            Align::Left => "<L>",
            Align::Center => "<C>",
            Align::Right => "<R>",
        }
    }
}

/// Which variable bank an escape reads from.
///
/// The documented precedence order is
/// `\v` < `\v1`..`\v9` < `\self` < `\cself` < `\sys` < `\udb` < `\cdb` < `\sdb` < `\s`
/// < `\sysS`, and a bracket may only contain codes of *lower* precedence. That is why
/// [VarRef::args] holds token lists rather than integers: `\cself[\v[12]]` is
/// legal and must keep its inner escape until the VM can resolve it.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum VarBank {
    /// `\v[n]` — ordinary numeric variables.
    Normal,
    /// `\v1[n]` through `\v9[n]` — reserve variable banks 1 to 9. The digit is
    /// written between the code letter and the bracket, with no separator.
    Reserve(u8),
    /// `\s[n]` — string variables.
    Str,
    /// `\sys[n]` — system variables.
    Sys,
    /// `\sysS[n]` — system strings. The capital S is mandatory.
    SysStr,
    /// `\self[n]` — the map event's own self variables.
    SelfVar,
    /// `\cself[n]` — the running common event's self variables. Slots 0 to 4 and
    /// 10 to 99 are numeric, 5 to 9 are strings.
    CommonSelf,
    /// `\udb[A:B:C]` — user database.
    UserDb,
    /// `\cdb[A:B:C]` — variable database.
    VarDb,
    /// `\sdb[A:B:C]` — system database.
    SysDb,
    /// `\xy[N:X:Y]` — XY array cell addressed by number.
    Xy,
    /// `\xyN[NAME:X:Y]` — XY array cell addressed by name.
    XyNamed,
}

impl VarBank {
    /// The code name, without the leading backslash.
    ///
    /// A reserve bank reports "v"; the digit lives in [VarBank::reserve].
    #[must_use]
    pub fn name(self) -> &'static str {
        match self {
            VarBank::Normal | VarBank::Reserve(_) => "v",
            VarBank::Str => "s",
            VarBank::Sys => "sys",
            VarBank::SysStr => "sysS",
            VarBank::SelfVar => "self",
            VarBank::CommonSelf => "cself",
            VarBank::UserDb => "udb",
            VarBank::VarDb => "cdb",
            VarBank::SysDb => "sdb",
            VarBank::Xy => "xy",
            VarBank::XyNamed => "xyN",
        }
    }

    /// The reserve bank number, when this is a `\v1`..`\v9` escape.
    #[must_use]
    pub fn reserve(self) -> Option<u8> {
        match self {
            VarBank::Reserve(bank) => Some(bank),
            _ => None,
        }
    }

    /// True for the database and XY codes, whose bracket holds colon-separated
    /// fields rather than a single slot number.
    #[must_use]
    pub fn is_multi_field(self) -> bool {
        matches!(
            self,
            VarBank::UserDb | VarBank::VarDb | VarBank::SysDb | VarBank::Xy | VarBank::XyNamed
        )
    }
}

/// One variable escape, with its bracket arguments still tokenised.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct VarRef {
    /// Which bank is being read.
    pub bank: VarBank,
    /// Colon-separated bracket fields, each a token list of its own.
    ///
    /// A plain `\v[12]` yields one field holding the literal text "12"; a
    /// `\cdb[0:\v[0]:0]` yields three.
    pub args: Vec<Vec<TextToken>>,
}

impl VarRef {
    /// The slot number, when the first field is a plain decimal integer.
    ///
    /// This is the shape every escape in this game takes; the Option exists for
    /// `\cself[\v[12]]`-style indirection, which needs the VM.
    #[must_use]
    pub fn slot(&self) -> Option<u32> {
        match self.args.first().map(Vec::as_slice) {
            Some([TextToken::Text(text)]) => parse_u32(text),
            _ => None,
        }
    }

    /// The bracket fields as source text, nested escapes included.
    #[must_use]
    pub fn fields(&self) -> Vec<String> {
        self.args.iter().map(|field| to_source(field)).collect()
    }
}

impl fmt::Display for VarRef {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        f.write_str(&render_var(self))
    }
}

/// A bracketed code whose argument is not a plain canonical integer.
///
/// Every code in docs/TEXT_SPEC.md section 2 takes a decimal argument, so the
/// common case gets a dedicated [TextToken] variant. A code lands in
/// [TextToken::Code] only when its argument is computed, such as `\c[\v[3]]`, or
/// malformed; the raw field text is preserved so the round trip still holds.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum CodeKind {
    /// `\wE[n]` — outline thickness, 1 to 5.
    OutlineWidth,
    /// `\cE[n]` — outline colour; `\cE[-1]` restores the default black.
    OutlineColor,
    /// `\c[n]` — font colour, a data id in the SystemDB row `12:文字色`.
    Color,
    /// `\cS[n]` — shadow colour, same database.
    ShadowColor,
    /// `\cR[n]` — ruby colour.
    RubyColor,
    /// `\fR[n]` — ruby size.
    RubySize,
    /// `\f[n]` — absolute font size in pixels.
    FontSize,
    /// `\f+[n]` — relative font size; a negative value shrinks.
    FontSizeDelta,
    /// `\m[n]` — baseline for the current line, reset by a newline.
    Baseline,
    /// `\font[n]` — font slot, 0 to 3.
    FontSlot,
    /// `\-[n]` — letter spacing tweak; a negative value widens.
    LetterSpacing,
    /// `\space[n]` — line gap in pixels for subsequent newlines.
    LineGap,
    /// `\sp[n]` — typewriter speed in characters per second; 0 is instant.
    Speed,
    /// `\bx[n]` — X start for subsequent lines.
    LineStartX,
    /// `\mx[n]` — relative X offset for the next character.
    OffsetX,
    /// `\my[n]` — relative Y offset for the next character.
    OffsetY,
    /// `\ax[n]` — absolute X within the picture for the next character.
    AbsoluteX,
    /// `\ay[n]` — absolute Y within the picture for the next character.
    AbsoluteY,
    /// `\i[n]` — inline icon, smooth-scaled.
    Icon,
    /// `\iS[n]` — inline icon, nearest-scaled.
    IconNearest,
    /// `\isize[n]` — percent scale for subsequent icons and images.
    IconScale,
    /// `\r[text,ruby]` — ruby annotation, used only when the bracket has no
    /// comma and so cannot be split into a base and an annotation.
    Ruby,
}

impl CodeKind {
    /// The code name, without the leading backslash.
    #[must_use]
    pub fn name(self) -> &'static str {
        match self {
            CodeKind::OutlineWidth => "wE",
            CodeKind::OutlineColor => "cE",
            CodeKind::Color => "c",
            CodeKind::ShadowColor => "cS",
            CodeKind::RubyColor => "cR",
            CodeKind::RubySize => "fR",
            CodeKind::FontSize => "f",
            CodeKind::FontSizeDelta => "f+",
            CodeKind::Baseline => "m",
            CodeKind::FontSlot => "font",
            CodeKind::LetterSpacing => "-",
            CodeKind::LineGap => "space",
            CodeKind::Speed => "sp",
            CodeKind::LineStartX => "bx",
            CodeKind::OffsetX => "mx",
            CodeKind::OffsetY => "my",
            CodeKind::AbsoluteX => "ax",
            CodeKind::AbsoluteY => "ay",
            CodeKind::Icon => "i",
            CodeKind::IconNearest => "iS",
            CodeKind::IconScale => "isize",
            CodeKind::Ruby => "r",
        }
    }
}

/// One piece of a message string.
///
/// Text runs are maximal: two adjacent literal characters always share one
/// [TextToken::Text], so the token list is the shortest description of the
/// string that preserves every byte.
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum TextToken {
    /// Literal characters, never containing a newline.
    Text(String),
    /// A line break. Carried as a token because it also ends `\m` and `<L>` scope.
    Newline,
    /// A literal backslash, written as a doubled backslash in source.
    Backslash,
    /// `<L>`, `<C>` or `<R>` — per-line alignment.
    Align(Align),
    /// `\E` enables the outline, `\N` disables it. Outline off is the default.
    Outline(bool),
    /// `\wE[n]` — outline thickness in pixels.
    OutlineWidth(u8),
    /// `\cE[n]` — outline colour; None means `\cE[-1]`, the default black.
    OutlineColor(Option<u32>),
    /// `\c[n]` — font colour.
    Color(u32),
    /// `\cS[n]` — shadow colour.
    ShadowColor(u32),
    /// `\cR[n]` — ruby colour.
    RubyColor(u32),
    /// `\fR[n]` — ruby size.
    RubySize(i32),
    /// `\f[n]` — font size in pixels.
    FontSize(u32),
    /// `\f+[n]` — relative font size change.
    FontSizeDelta(i32),
    /// `\m[n]` — baseline for this line only.
    Baseline(i32),
    /// `\font[n]` — font slot 0 to 3.
    FontSlot(u8),
    /// `\A`+ enables anti-aliasing, `\A`- disables it.
    AntiAlias(bool),
    /// `\-[n]` — letter spacing tweak.
    LetterSpacing(i32),
    /// `\space[n]` — line gap for subsequent newlines.
    LineGap(i32),
    /// `\sp[n]` — typewriter speed in characters per second.
    Speed(u32),
    /// `\bx[n]` — X start for subsequent lines.
    LineStartX(i32),
    /// `\mx[n]` — relative X offset for the next character.
    OffsetX(i32),
    /// `\my[n]` — relative Y offset for the next character.
    OffsetY(i32),
    /// `\ax[n]` — absolute X for the next character.
    AbsoluteX(i32),
    /// `\ay[n]` — absolute Y for the next character.
    AbsoluteY(i32),
    /// `\!` — stop the typewriter until the player presses a key, then continue.
    Wait,
    /// `\^` — close the message window without waiting for a key.
    Close,
    /// `\.` — pause for a quarter of a second.
    Pause,
    /// `\>` turns instant display on, `\<` turns it back off.
    Instant(bool),
    /// `\i[n]` — inline icon, smooth-scaled.
    Icon(u32),
    /// `\iS[n]` — inline icon, nearest-scaled.
    IconNearest(u32),
    /// `\isize[n]` — percent scale for subsequent icons and images.
    IconScale(u32),
    /// `\img[path]` — inline image, smooth-scaled.
    ///
    /// The bracket body is kept raw: a path may legitimately contain a literal
    /// backslash, and the body may carry <DIV/X6/Y4/8>-style directives that are
    /// not text markup at all.
    Image(String),
    /// `\imgS[path]` — inline image, nearest-scaled.
    ImageNearest(String),
    /// `\se[address,volume,pitch]` — play a sound effect inline.
    ///
    /// Kept raw for the same reason as [TextToken::Image]; the caller splits on
    /// commas. Only the address is mandatory.
    Sound(String),
    /// `\r[text,ruby]` — ruby annotation drawn above text.
    Ruby {
        /// The base text, which occupies the normal pen positions.
        text: String,
        /// The annotation drawn above it.
        ruby: String,
    },
    /// A variable or database read.
    Var(VarRef),
    /// A bracketed code with a non-canonical argument, preserved verbatim.
    Code {
        /// Which code this is.
        kind: CodeKind,
        /// Colon-separated bracket fields, as source text.
        args: Vec<String>,
    },
}

impl fmt::Display for TextToken {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        f.write_str(&to_source(std::slice::from_ref(self)))
    }
}

/// Split a message string into [TextToken]s.
///
/// Never panics and never loses bytes: anything that does not match a documented
/// code stays literal, so the output is always re-renderable by [to_source].
#[must_use]
pub fn tokenize(s: &str) -> Vec<TextToken> {
    tokenize_depth(s, 0)
}

/// The plain text of a message, with every escape removed.
///
/// Keeps literal characters, newlines, doubled backslashes and the base text of
/// ruby annotations. Drops everything else — this is what a log, a search index
/// or a debug dump wants, not what the renderer wants.
#[must_use]
pub fn strip(s: &str) -> String {
    let mut out = String::new();
    for token in tokenize(s) {
        match token {
            TextToken::Text(text) => out.push_str(&text),
            TextToken::Backslash => out.push('\\'),
            TextToken::Newline => out.push('\n'),
            TextToken::Ruby { text, .. } => out.push_str(&text),
            _ => {}
        }
    }
    out
}

/// Re-render a token list as source text.
///
/// The inverse of [tokenize]: to_source(tokenize(s)) == s for every string the
/// tokeniser accepts, which is what makes it safe to edit a message in place.
#[must_use]
pub fn to_source(tokens: &[TextToken]) -> String {
    let mut out = String::new();
    for token in tokens {
        match token {
            TextToken::Text(text) => out.push_str(text),
            TextToken::Newline => out.push('\n'),
            TextToken::Backslash => {
                // A literal backslash is written doubled, or it would start an
                // escape. Round-tripping is why this is not a single byte.
                out.push('\\');
                out.push('\\');
            }
            TextToken::Align(align) => out.push_str(align.tag()),
            TextToken::Outline(true) => push_code(&mut out, "E", ""),
            TextToken::Outline(false) => push_code(&mut out, "N", ""),
            TextToken::OutlineWidth(width) => push_code(&mut out, "wE", &width.to_string()),
            TextToken::OutlineColor(color) => {
                let body = match color {
                    Some(value) => value.to_string(),
                    None => "-1".to_string(),
                };
                push_code(&mut out, "cE", &body);
            }
            TextToken::Color(color) => push_code(&mut out, "c", &color.to_string()),
            TextToken::ShadowColor(color) => push_code(&mut out, "cS", &color.to_string()),
            TextToken::RubyColor(color) => push_code(&mut out, "cR", &color.to_string()),
            TextToken::RubySize(size) => push_code(&mut out, "fR", &size.to_string()),
            TextToken::FontSize(size) => push_code(&mut out, "f", &size.to_string()),
            TextToken::FontSizeDelta(delta) => push_code(&mut out, "f+", &delta.to_string()),
            TextToken::Baseline(baseline) => push_code(&mut out, "m", &baseline.to_string()),
            TextToken::FontSlot(slot) => push_code(&mut out, "font", &slot.to_string()),
            TextToken::AntiAlias(true) => push_code(&mut out, "A+", ""),
            TextToken::AntiAlias(false) => push_code(&mut out, "A-", ""),
            TextToken::LetterSpacing(spacing) => push_code(&mut out, "-", &spacing.to_string()),
            TextToken::LineGap(gap) => push_code(&mut out, "space", &gap.to_string()),
            TextToken::Speed(speed) => push_code(&mut out, "sp", &speed.to_string()),
            TextToken::LineStartX(x) => push_code(&mut out, "bx", &x.to_string()),
            TextToken::OffsetX(x) => push_code(&mut out, "mx", &x.to_string()),
            TextToken::OffsetY(y) => push_code(&mut out, "my", &y.to_string()),
            TextToken::AbsoluteX(x) => push_code(&mut out, "ax", &x.to_string()),
            TextToken::AbsoluteY(y) => push_code(&mut out, "ay", &y.to_string()),
            TextToken::Wait => push_code(&mut out, "!", ""),
            TextToken::Close => push_code(&mut out, "^", ""),
            TextToken::Pause => push_code(&mut out, ".", ""),
            TextToken::Instant(true) => push_code(&mut out, ">", ""),
            TextToken::Instant(false) => push_code(&mut out, "<", ""),
            TextToken::Icon(index) => push_code(&mut out, "i", &index.to_string()),
            TextToken::IconNearest(index) => push_code(&mut out, "iS", &index.to_string()),
            TextToken::IconScale(scale) => push_code(&mut out, "isize", &scale.to_string()),
            TextToken::Image(path) => push_code(&mut out, "img", path),
            TextToken::ImageNearest(path) => push_code(&mut out, "imgS", path),
            TextToken::Sound(body) => push_code(&mut out, "se", body),
            TextToken::Ruby { text, ruby } => {
                let mut body = String::with_capacity(text.len() + ruby.len() + 1);
                body.push_str(text);
                body.push(',');
                body.push_str(ruby);
                push_code(&mut out, "r", &body);
            }
            TextToken::Var(var) => out.push_str(&render_var(var)),
            TextToken::Code { kind, args } => {
                // Written with brackets unconditionally: a Code token only
                // exists because the source had them, and \c[] must not come
                // back as \c.
                let mut body = String::new();
                for (index, arg) in args.iter().enumerate() {
                    if index > 0 {
                        body.push(':');
                    }
                    body.push_str(arg);
                }
                out.push('\\');
                out.push_str(kind.name());
                out.push('[');
                out.push_str(&body);
                out.push(']');
            }
        }
    }
    out
}

/// A cheap upper bound on how many glyph cells a token list will draw.
///
/// Counts one cell per literal character, per doubled backslash, per ruby base
/// character, and per icon or image. Escapes count zero because they draw
/// nothing themselves. This is a wrapping hint, not a measurement: it ignores
/// letter spacing, font size and the digits a [TextToken::Var] will expand to,
/// so the renderer must still measure real glyphs when it lays a line out.
#[must_use]
pub fn display_width_hint(tokens: &[TextToken]) -> u32 {
    let mut width = 0u32;
    for token in tokens {
        width = width.saturating_add(match token {
            TextToken::Text(text) => count_glyphs(text),
            TextToken::Backslash => 1,
            TextToken::Ruby { text, .. } => count_glyphs(text),
            TextToken::Icon(_)
            | TextToken::IconNearest(_)
            | TextToken::Image(_)
            | TextToken::ImageNearest(_) => 1,
            _ => 0,
        });
    }
    width
}

fn count_glyphs(text: &str) -> u32 {
    u32::try_from(text.chars().count()).unwrap_or(u32::MAX)
}

fn push_code(out: &mut String, name: &str, body: &str) {
    out.push('\\');
    out.push_str(name);
    let always_bracketed = matches!(name, "img" | "imgS" | "se" | "r");
    if always_bracketed || !body.is_empty() {
        out.push('[');
        out.push_str(body);
        out.push(']');
    }
}

fn render_var(var: &VarRef) -> String {
    let mut out = String::new();
    out.push('\\');
    out.push_str(var.bank.name());
    if let Some(bank) = var.bank.reserve() {
        let _ = write!(out, "{bank}");
    }
    out.push('[');
    for (index, field) in var.args.iter().enumerate() {
        if index > 0 {
            out.push(':');
        }
        out.push_str(&to_source(field));
    }
    out.push(']');
    out
}

/// Code names that take a bracket argument, longest first.
///
/// Order is load-bearing. Matching is prefix-based, so cself must be tried
/// before c, sysS before sys, space before sp, imgS before img, isize before iS
/// before i, and font before f. A name only counts when the very next byte is
/// '[', so a shorter name that also matches still fails cleanly, but trying the
/// longest first keeps the intent obvious and stops a future addition from
/// silently shadowing an existing code.
const CODE_NAMES: [&str; 36] = [
    "cself", "isize", "space", "font", "imgS", "sysS", "self", "cdb", "img", "sdb", "sys", "udb",
    "xyN", "ax", "ay", "bx", "cE", "cR", "cS", "f+", "fR", "iS", "mx", "my", "se", "sp", "wE",
    "xy", "-", "c", "f", "i", "m", "r", "s", "v",
];

fn tokenize_depth(s: &str, depth: u8) -> Vec<TextToken> {
    let bytes = s.as_bytes();
    let mut tokens = Vec::new();
    let mut text = String::new();
    let mut index = 0usize;
    while index < bytes.len() {
        let byte = bytes[index];
        let parsed = match byte {
            b'\\' => parse_escape(s, index, depth),
            b'<' => parse_align(s, index),
            _ => None,
        };
        if let Some((token, next)) = parsed {
            flush(&mut tokens, &mut text);
            tokens.push(token);
            index = next;
            continue;
        }
        if byte == b'\n' {
            flush(&mut tokens, &mut text);
            tokens.push(TextToken::Newline);
            index += 1;
            continue;
        }
        match s[index..].chars().next() {
            Some(ch) => {
                text.push(ch);
                index += ch.len_utf8();
            }
            None => break,
        }
    }
    flush(&mut tokens, &mut text);
    tokens
}

fn flush(tokens: &mut Vec<TextToken>, text: &mut String) {
    if !text.is_empty() {
        tokens.push(TextToken::Text(std::mem::take(text)));
    }
}

/// Match `<L>`, `<C>` or `<R>` exactly, or nothing.
///
/// A '<' that is not one of these three tags is literal text: messages contain
/// <状態A> and <装着A?> as ordinary writing, so a looser rule would corrupt them.
fn parse_align(s: &str, start: usize) -> Option<(TextToken, usize)> {
    let rest = s.get(start..)?;
    for (tag, align) in [
        ("<L>", Align::Left),
        ("<C>", Align::Center),
        ("<R>", Align::Right),
    ] {
        if rest.starts_with(tag) {
            return Some((TextToken::Align(align), start + tag.len()));
        }
    }
    None
}

fn parse_escape(s: &str, start: usize, depth: u8) -> Option<(TextToken, usize)> {
    if depth >= MAX_DEPTH {
        return None;
    }
    let bytes = s.as_bytes();
    let after = start + 1;
    let head = *bytes.get(after)?;

    // Bracket-less codes come first. They are one or two bytes and several of
    // them share a prefix with a bracketed name, so they must be settled before
    // the table is consulted.
    let bare = match head {
        b'\\' => Some((TextToken::Backslash, after + 1)),
        b'E' => Some((TextToken::Outline(true), after + 1)),
        b'N' => Some((TextToken::Outline(false), after + 1)),
        b'>' => Some((TextToken::Instant(true), after + 1)),
        b'<' => Some((TextToken::Instant(false), after + 1)),
        b'!' => Some((TextToken::Wait, after + 1)),
        b'^' => Some((TextToken::Close, after + 1)),
        b'.' => Some((TextToken::Pause, after + 1)),
        b'A' => match bytes.get(after + 1).copied() {
            Some(b'+') => Some((TextToken::AntiAlias(true), after + 2)),
            Some(b'-') => Some((TextToken::AntiAlias(false), after + 2)),
            _ => None,
        },
        _ => None,
    };
    if bare.is_some() {
        return bare;
    }

    // Reserve banks put the bank digit between the letter and the bracket —
    // \v1[30], not \v[1:30] — so this shape cannot be reached through the table.
    if head == b'v' {
        if let (Some(bank @ b'1'..=b'9'), Some(b'[')) =
            (bytes.get(after + 1).copied(), bytes.get(after + 2).copied())
        {
            let open = after + 2;
            let close = find_close(s, open)?;
            let inner = s.get(open + 1..close)?;
            let var = VarRef {
                bank: VarBank::Reserve(bank - b'0'),
                args: parse_fields(inner, depth + 1),
            };
            return Some((TextToken::Var(var), close + 1));
        }
    }

    let rest = s.get(after..)?;
    let mut matched = None;
    for name in CODE_NAMES {
        if rest.starts_with(name) {
            let bracket = after + name.len();
            if bytes.get(bracket).copied() == Some(b'[') {
                matched = Some(name);
                break;
            }
        }
    }
    let name = matched?;
    let open = after + name.len();
    let close = find_close(s, open)?;
    let body = s.get(open + 1..close)?;
    Some((bracketed(name, body, depth)?, close + 1))
}

fn bracketed(name: &str, body: &str, depth: u8) -> Option<TextToken> {
    if let Some(token) = bracketed_var(name, body, depth) {
        return Some(token);
    }
    bracketed_code(name, body)
}

/// Variable reads: the bracket holds slot numbers or colon-separated database
/// coordinates, and may itself contain a lower-precedence escape.
fn bracketed_var(name: &str, body: &str, depth: u8) -> Option<TextToken> {
    let bank = match name {
        "cself" => VarBank::CommonSelf,
        "sysS" => VarBank::SysStr,
        "self" => VarBank::SelfVar,
        "cdb" => VarBank::VarDb,
        "sdb" => VarBank::SysDb,
        "sys" => VarBank::Sys,
        "udb" => VarBank::UserDb,
        "xyN" => VarBank::XyNamed,
        "xy" => VarBank::Xy,
        "s" => VarBank::Str,
        "v" => VarBank::Normal,
        _ => return None,
    };
    Some(var(bank, body, depth))
}

fn var(bank: VarBank, body: &str, depth: u8) -> TextToken {
    TextToken::Var(VarRef {
        bank,
        args: parse_fields(body, depth + 1),
    })
}

/// Fall back to [TextToken::Code] when the argument is not a canonical integer.
///
/// The fallback keeps the field text verbatim, so a computed argument such as
/// `\c[\v[3]]` still round-trips through [to_source].
fn code<F>(kind: CodeKind, body: &str, typed: F) -> TextToken
where
    F: FnOnce(&str) -> Option<TextToken>,
{
    match typed(body) {
        Some(token) => token,
        None => TextToken::Code {
            kind,
            args: body.split(':').map(str::to_string).collect(),
        },
    }
}

fn bracketed_code(name: &str, body: &str) -> Option<TextToken> {
    let token = match name {
        "wE" => code(CodeKind::OutlineWidth, body, |t| {
            parse_u8(t).map(TextToken::OutlineWidth)
        }),
        "cE" => code(CodeKind::OutlineColor, body, |t| {
            if t == "-1" {
                Some(TextToken::OutlineColor(None))
            } else {
                parse_u32(t).map(|color| TextToken::OutlineColor(Some(color)))
            }
        }),
        "c" => code(CodeKind::Color, body, |t| {
            parse_u32(t).map(TextToken::Color)
        }),
        "cS" => code(CodeKind::ShadowColor, body, |t| {
            parse_u32(t).map(TextToken::ShadowColor)
        }),
        "cR" => code(CodeKind::RubyColor, body, |t| {
            parse_u32(t).map(TextToken::RubyColor)
        }),
        "fR" => code(CodeKind::RubySize, body, |t| {
            parse_i32(t).map(TextToken::RubySize)
        }),
        "f" => code(CodeKind::FontSize, body, |t| {
            parse_u32(t).map(TextToken::FontSize)
        }),
        "f+" => code(CodeKind::FontSizeDelta, body, |t| {
            parse_i32(t).map(TextToken::FontSizeDelta)
        }),
        "m" => code(CodeKind::Baseline, body, |t| {
            parse_i32(t).map(TextToken::Baseline)
        }),
        "font" => code(CodeKind::FontSlot, body, |t| {
            parse_u8(t).map(TextToken::FontSlot)
        }),
        "-" => code(CodeKind::LetterSpacing, body, |t| {
            parse_i32(t).map(TextToken::LetterSpacing)
        }),
        "space" => code(CodeKind::LineGap, body, |t| {
            parse_i32(t).map(TextToken::LineGap)
        }),
        "sp" => code(CodeKind::Speed, body, |t| {
            parse_u32(t).map(TextToken::Speed)
        }),
        _ => return bracketed_more(name, body),
    };
    Some(token)
}

fn bracketed_more(name: &str, body: &str) -> Option<TextToken> {
    let token = match name {
        "bx" => code(CodeKind::LineStartX, body, |t| {
            parse_i32(t).map(TextToken::LineStartX)
        }),
        "mx" => code(CodeKind::OffsetX, body, |t| {
            parse_i32(t).map(TextToken::OffsetX)
        }),
        "my" => code(CodeKind::OffsetY, body, |t| {
            parse_i32(t).map(TextToken::OffsetY)
        }),
        "ax" => code(CodeKind::AbsoluteX, body, |t| {
            parse_i32(t).map(TextToken::AbsoluteX)
        }),
        "ay" => code(CodeKind::AbsoluteY, body, |t| {
            parse_i32(t).map(TextToken::AbsoluteY)
        }),
        "i" => code(CodeKind::Icon, body, |t| parse_u32(t).map(TextToken::Icon)),
        "iS" => code(CodeKind::IconNearest, body, |t| {
            parse_u32(t).map(TextToken::IconNearest)
        }),
        "isize" => code(CodeKind::IconScale, body, |t| {
            parse_u32(t).map(TextToken::IconScale)
        }),
        "img" => TextToken::Image(body.to_string()),
        "imgS" => TextToken::ImageNearest(body.to_string()),
        "se" => TextToken::Sound(body.to_string()),
        "r" => split_ruby(body),
        _ => return None,
    };
    Some(token)
}

fn split_ruby(body: &str) -> TextToken {
    match body.split_once(',') {
        Some((text, ruby)) => TextToken::Ruby {
            text: text.to_string(),
            ruby: ruby.to_string(),
        },
        None => TextToken::Code {
            kind: CodeKind::Ruby,
            args: vec![body.to_string()],
        },
    }
}

fn parse_fields(body: &str, depth: u8) -> Vec<Vec<TextToken>> {
    let mut fields = Vec::new();
    let mut start = 0usize;
    let mut nest = 0u32;
    for (index, byte) in body.bytes().enumerate() {
        match byte {
            b'[' => nest += 1,
            b']' => nest = nest.saturating_sub(1),
            b':' if nest == 0 => {
                fields.push(tokenize_depth(&body[start..index], depth));
                start = index + 1;
            }
            _ => {}
        }
    }
    fields.push(tokenize_depth(&body[start..], depth));
    fields
}

fn find_close(s: &str, open: usize) -> Option<usize> {
    let bytes = s.as_bytes();
    if bytes.get(open).copied() != Some(b'[') {
        return None;
    }
    let mut nest = 0u32;
    for (offset, byte) in bytes.get(open..)?.iter().enumerate() {
        match byte {
            b'[' => nest += 1,
            b']' => {
                nest = nest.checked_sub(1)?;
                if nest == 0 {
                    return Some(open + offset);
                }
            }
            _ => {}
        }
    }
    None
}

/// Parse a canonical decimal integer.
///
/// Canonical means the source spelling is exactly what to_string produces: no
/// leading zeros, no leading plus, no "-0". Every numeric argument in the
/// shipped messages satisfies this (docs/TEXT_SPEC.md section 3.2), so a token
/// that parses can always be re-rendered byte-identically. Anything else falls
/// back to [TextToken::Code], which preserves the original spelling.
fn parse_u32(text: &str) -> Option<u32> {
    let value: u32 = text.parse().ok()?;
    (value.to_string() == text).then_some(value)
}

fn parse_i32(text: &str) -> Option<i32> {
    let value: i32 = text.parse().ok()?;
    (value.to_string() == text).then_some(value)
}

fn parse_u8(text: &str) -> Option<u8> {
    let value: u8 = text.parse().ok()?;
    (value.to_string() == text).then_some(value)
}
