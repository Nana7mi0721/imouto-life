//! Layout of `150` Picture *text pictures* (display types 2 and 4).
//!
//! # Why this module exists
//!
//! `150` has seven display kinds. Kinds 2 and 4 do not name an asset at all: their
//! argument tail is a *markup string* that the engine lays out with a font inside
//! the picture box. 2,736 of this game's 20,424 `150` instructions are text pictures
//! (2,645 of type 2, 91 of type 4) and 2,403 of those carry a markup string, so this
//! is not a corner case - it is the whole HUD.
//!
//! The host used to strip the markup (`messagetext::strip`) and draw every text picture
//! at `choice::TEXT_PX`, which is why the HUD collapsed into overlapping labels: CE217
//! alone places three text pictures that only make sense with their own sizes *and*
//! their own anchors - `\f[18]73\f[14]日` right-aligned on x=66,
//! `\f[24]\v[4]:\v[5]` right-aligned on x=140, `\f[18]周六` left-aligned on x=150.
//!
//! # Scope
//!
//! Pure maths, like the rest of this crate: no GPU, no font rasteriser, no clock. One
//! markup string plus an anchor becomes a list of [Run]s, and each run is one text area
//! for the renderer. Everything the layout needs from the outside world comes through
//! [Ctx], so the module is unit-testable on a machine that has never seen `Data/` - which
//! matters, because the retail game is the only reference implementation and it cannot
//! be scripted.
//!
//! # Escape grammar
//!
//! The grammar is not re-implemented here: `wolf_format::messagetext::tokenize` is the single
//! source of truth for markup (the same tokeniser the message window and the text dump
//! use; its catalogue is docs/TEXT_SPEC.md section 2). This module only decides what
//! each token *means for layout*:
//!
//! | token | effect |
//! | --- | --- |
//! | `\f[n]` | font size in pixels; starts a new [Run] |
//! | `\c[n]` | font colour *index* into SystemDB `12:文字色`; starts a new run |
//! | `\E` / `\N` | outline on / off; starts a new run |
//! | `\v[n]` | numeric variable `n`, rendered in decimal |
//! | `\s[n]`, `\cself[n]` | string variable `n` (see the [Vars] contract) |
//! | `\cdb[a:b:c]`, `\udb[a:b:c]` | database cell; a missing cell renders as empty |
//! | `\n` | hard line break |
//! | `<R>` | right-align the *rest of the line* against the block's right edge |
//!
//! Everything else the tokeniser knows about (ruby, inline icons, typewriter speed,
//! letter spacing, `\ax`/`\ay` absolute positioning) is layout-neutral here and is
//! dropped with a TODO rather than guessed at.
//!
//! # Anchors
//!
//! `150` carries the anchor in bits 12..14 of its head word (crate::picture::Screen
//! already decodes it). Only the top-left and centre anchors were ever verified; the
//! other three are derived from the retail screenshot `Save/save1.jpg`:
//!
//! * anchor 3 (`0x3000`) puts the block's *right edge* on x. Pic 6200 is
//!   `\f[24]\v[4]:\v[5]` at x=140 and its ink lands on x 85..138; pic 6211 is
//!   `\f[18]\v[160]\f[14]日` at x=66 and its ink lands on x 32..64.
//! * anchor 0 puts the *left edge* on x (pic 6210 at x=150 draws from x=151).
//! * anchors 2 and 4 move the block's *bottom edge* to y, by symmetry with 1.
//!
//! # Widths (read this before trusting a number)
//!
//! [measure] uses the crate's single width rule, `choice::advance_at`: a full-width glyph
//! advances one em, anything else half an em. The message window and the choice list
//! already use that rule, and one rule beats three.
//!
//! It is, however, an *approximation* of the retail engine, and the difference is
//! measurable. WOLF draws text pictures with DxLib and the real font (this game ships
//! `Fonts/Lolita.ttf`, upm 2048), so advances are proportional:
//!
//! * `21:40` at 24 px: real advances sum to 56.31 px (2=0.4990 em, 1=0.4595,
//!   :=0.2993, 4=0.4888, 0=0.5996). With the block's right edge on x=140 the left edge
//!   lands on 83.7 and the first ink pixel on 85 - exactly what the retail screenshot
//!   shows. The half-em rule gives 60, i.e. a left edge of 80 and a 5 px left bearing
//!   that no digit in this font has.
//! * `90日` (`\f[18]90\f[14]日`) at x=66: real advances give 34.6 px, left edge
//!   31.4, measured ink starts on 32. The half-em rule gives 32, left edge 34.
//!
//! So the half-em rule over-measures a digit run by about 6%, which shows up as a 3-4 px
//! shift on anchors 1, 3 and 4. Rather than smuggle a font metrics table into this crate
//! (the renderer already owns the font, and this module must stay testable without one),
//! every entry point has a `_with` twin that takes the advance function. The host can pass
//! cosmic-text's shaped advances once the renderer is wired to it; until then [measure] is
//! the documented approximation.
//!
//! # Variables and self variables
//!
//! Two conventions matter, and both exist because of how this game writes its HUD:
//!
//! * `Vars::text` must return the *decimal rendering of numeric slots too*. The game
//!   writes `\f[\cself[19]]` - a font size read from a self variable - so the evaluator
//!   asks [Vars::text] for it and parses the digits.
//! * [Vars::num] is only used for `\v[n]`, whose bank is the normal numeric array.
//!
//! That split keeps the module free of any "is this slot numeric?" heuristic, which this
//! crate cannot answer without the VM's own type information.

use crate::choice;
use wolf_format::messagetext::{tokenize, Align, CodeKind, TextToken, VarBank, VarRef};

/// Line pitch as a multiple of the largest font size on the line.
///
/// 1.3 is the ratio the message window uses (choice::LINE_HEIGHT is 30 for a 20 px
/// font), and it is the only ratio the retail HUD is consistent with. For the
/// uniform-font lines that every multi-line text picture in this game uses, it
/// reproduces the brief's "rows x font_px x ratio" exactly while still keeping a
/// mixed-size line from colliding with the line under it.
pub const DEFAULT_LINE_PITCH_RATIO: f32 = 1.3;

/// Smallest font size an escape may set, in pixels.
///
/// `\f[0]` and `\f+[-40]` both occur in the wild; a zero or negative size would make
/// every advance zero, which collapses the line to a point and loses the text. One
/// pixel keeps the run visible and the arithmetic finite.
pub const MIN_FONT_PX: f32 = 1.0;

/// Guards `\f[\cself[\cself[\cself[...]]]]`, which the tokeniser alone would
/// happily keep unwrapping.
const MAX_ESCAPE_DEPTH: u8 = 8;

/// The escape state a run inherits.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct Style {
    /// Font size in pixels as set by the last `\f[n]`.
    pub font_px: f32,
    /// Colour index as set by the last `\c[n]`, or `None` for the default (white; the
    /// picture's own tone still applies on top).
    pub colour: Option<i32>,
    /// Whether `\E` is in effect for this run.
    pub outline: bool,
}

/// One contiguous piece of one line that renders with a single [Style].
///
/// The renderer turns each run into one text area, so a style change *has* to split:
/// glyphon applies colour per glyph attribute and size per layout, and a run is the
/// smallest unit that keeps both right. One shaping call per style change is cheap -
/// the retail HUD averages well under two per picture.
#[derive(Clone, Debug, PartialEq)]
pub struct Run {
    /// Text to draw, with every escape already resolved.
    pub text: String,
    /// Left edge in picture-local pixels.
    pub x: f32,
    /// Top edge of this line's box in picture-local pixels.
    pub y: f32,
    /// Font size for this run.
    pub font_px: f32,
    /// Colour index, resolved through [Colours] by the renderer (see [rgb]).
    pub colour: Option<i32>,
    /// Whether the text is outlined (the `\E` flag).
    pub outline: bool,
    /// True when `<R>` placed this run against the block's right edge.
    ///
    /// Reported separately from [Run::x] so the host can tell the two placements apart
    /// when it has to re-flow a picture on its own.
    pub align_right: bool,
    /// Advance width of [Run::text] at [Run::font_px], in pixels.
    ///
    /// The layout already walks every chunk to advance the cursor, so keeping the width
    /// here lets the host build its render quads without measuring the same run again.
    pub width: f32,
}

/// Everything the layout reads from the running game.
///
/// All three are trait objects so this crate keeps its "no GPU, no data files"
/// property: the host hands over live VM state, a test hands over constants.
pub struct Ctx<'a> {
    /// Variable banks.
    pub vars: &'a dyn Vars,
    /// Database cells.
    pub cells: &'a dyn Cells,
    /// The SystemDB `12:文字色` palette that `\c[n]` indexes.
    pub colours: &'a dyn Colours,
    /// Font size to use before any `\f` escape, normally SystemDB `8:フォントサイズ`
    /// (20 px in this game, written there by common event 48).
    pub default_font_px: f32,
}

/// Numeric and string variable reads.
///
/// Implementors point this at the *caller's* self-variable bank when the picture
/// belongs to a common event, which is what `\cself` means.
pub trait Vars {
    /// A numeric variable, `\v[n]`.
    fn num(&self, index: usize) -> i32;

    /// A string or self variable, `\s[n]` and `\cself[n]`.
    ///
    /// Must return the decimal form for slots that currently hold a number, because
    /// `\f[\cself[19]]` reads a font size through this method.
    fn text(&self, index: usize) -> String;
}

/// Database cell reads, `\cdb` and `\udb`.
pub trait Cells {
    /// A cell of the type-`ty` common database.
    fn cdb(&self, ty: i32, row: i32, column: i32) -> Option<String>;

    /// A cell of the type-`ty` user database.
    fn udb(&self, ty: i32, row: i32, column: i32) -> Option<String>;
}

/// The palette `\c[n]` indexes.
pub trait Colours {
    /// RGB for a colour index, or `None` for "default".
    fn colour(&self, index: i32) -> Option<[u8; 3]>;
}

/// Advance width of one character, in pixels.
type Advance<'a> = &'a dyn Fn(char, f32) -> f32;

/// Width of a plain, markup-free string at `font_px`.
///
/// Newlines have no advance, so a whole string can be measured at once; a caller that
/// wants per-line widths splits first ([block_size] does).
#[must_use]
pub fn measure(text: &str, font_px: f32) -> f32 {
    measure_with(text, font_px, &|ch, px| choice::advance_at(ch, px))
}

/// [measure] with a caller-supplied advance function.
///
/// The host should pass the renderer's shaped advances: the half-em rule in
/// `choice::advance_at` over-measures a digit run by about 6% (see the module docs), and
/// that error is what pushes right-aligned HUD text a few pixels off.
#[must_use]
pub fn measure_with(text: &str, font_px: f32, advance: Advance<'_>) -> f32 {
    text.chars()
        .filter(|ch| *ch != '\n')
        .map(|ch| advance(ch, font_px))
        .sum()
}

/// Size of the block `raw` would occupy, in pixels.
///
/// The picture layer needs this for text pictures: their box is not given by an asset
/// (there is no asset), so the laid-out block is the box.
#[must_use]
pub fn block_size(raw: &str, ctx: &Ctx<'_>) -> (f32, f32) {
    let mut builder = Builder::new(ctx, &|ch, px| choice::advance_at(ch, px));
    builder.run(raw);
    let lines = std::mem::take(&mut builder.lines);
    let width = lines.iter().map(|line| line.width).fold(0.0_f32, f32::max);
    let height = lines.iter().map(|line| line_pitch(ctx, line)).sum();
    (width, height)
}

/// Lay `raw` out inside a block whose anchor sits on `(x, y)`.
///
/// `anchor` is the 3-bit code from `150`'s head word: 0 top-left, 1 centre,
/// 2 bottom-left, 3 top-right, 4 bottom-right; anything else is treated as top-left.
#[must_use]
pub fn layout(raw: &str, x: f32, y: f32, anchor: u8, ctx: &Ctx<'_>) -> Vec<Run> {
    layout_with(raw, x, y, anchor, ctx, &|ch, px| choice::advance_at(ch, px))
}

/// [layout] with a caller-supplied advance function.
#[must_use]
pub fn layout_with(
    raw: &str,
    x: f32,
    y: f32,
    anchor: u8,
    ctx: &Ctx<'_>,
    advance: Advance<'_>,
) -> Vec<Run> {
    let mut builder = Builder::new(ctx, advance);
    builder.run(raw);
    let lines = std::mem::take(&mut builder.lines);

    let block_w = lines.iter().map(|line| line.width).fold(0.0_f32, f32::max);
    let block_h: f32 = lines.iter().map(|line| line_pitch(ctx, line)).sum();
    let (left, mut top) = anchor_origin(anchor, x, y, block_w, block_h);

    let mut runs = Vec::new();
    for line in &lines {
        let split = line
            .tail_from
            .unwrap_or(line.chunks.len())
            .min(line.chunks.len());
        let mut cursor = left;
        for chunk in &line.chunks[..split] {
            let width = width_of(&chunk.text, chunk.style.font_px, advance);
            let mut run = run_of(chunk, cursor, top, false);
            run.width = width;
            runs.push(run);
            cursor += width;
        }
        if split < line.chunks.len() {
            let tail: f32 = line.chunks[split..]
                .iter()
                .map(|chunk| width_of(&chunk.text, chunk.style.font_px, advance))
                .sum();
            cursor = left + block_w - tail;
            for chunk in &line.chunks[split..] {
                let width = width_of(&chunk.text, chunk.style.font_px, advance);
                let mut run = run_of(chunk, cursor, top, true);
                run.width = width;
                runs.push(run);
                cursor += width;
            }
        }
        top += line_pitch(ctx, line);
    }
    runs
}

/// Resolve a run's colour index to RGB through the picture's palette.
///
/// Kept out of [layout] so the layout never needs a palette: the index survives even
/// when SystemDB is not loaded, and the renderer decides what "default" means (white
/// here, because `150` text pictures carry colour in the picture tone instead).
#[must_use]
pub fn rgb(ctx: &Ctx<'_>, colour: Option<i32>) -> Option<[u8; 3]> {
    colour.and_then(|index| ctx.colours.colour(index))
}

/// One piece of one line, before placement.
#[derive(Clone, Debug)]
struct Chunk {
    text: String,
    style: Style,
}

/// One output line: its chunks, the width of the whole line, and where `<R>` cut it.
#[derive(Clone, Debug, Default)]
struct Line {
    chunks: Vec<Chunk>,
    /// Index of the first chunk that `<R>` moved to the right edge.
    tail_from: Option<usize>,
    width: f32,
}

/// Turns a markup string into [Line]s.
struct Builder<'a, 'b> {
    ctx: &'a Ctx<'b>,
    advance: Advance<'a>,
    style: Style,
    /// Text accumulated since the last style change or line end.
    buf: String,
    lines: Vec<Line>,
    /// The line being built; taken when the line ends.
    line: Line,
    depth: u8,
}

impl<'a, 'b> Builder<'a, 'b> {
    fn new(ctx: &'a Ctx<'b>, advance: Advance<'a>) -> Self {
        Self {
            ctx,
            advance,
            style: Style {
                font_px: ctx.default_font_px.max(MIN_FONT_PX),
                colour: None,
                outline: false,
            },
            buf: String::new(),
            lines: Vec::new(),
            line: Line::default(),
            depth: 0,
        }
    }

    /// Build every line of `raw`.
    fn run(&mut self, raw: &str) {
        for token in tokenize(raw) {
            self.token(&token);
        }
        self.end_line();
        // A trailing `\n` closes the last line and leaves an empty one behind. Retail text
        // pictures never draw it (a one-line picture ending in `\n` is 1.3 em tall, not
        // 2.6), so drop it - but keep a lone empty line, which is how `\n` alone means
        // "one blank row".
        if self.lines.len() > 1 && self.lines.last().is_some_and(|line| line.chunks.is_empty()) {
            self.lines.pop();
        }
    }

    fn token(&mut self, token: &TextToken) {
        match token {
            TextToken::Text(text) => self.buf.push_str(text),
            // `\\` is a literal backslash; the tokeniser already made it its own token.
            TextToken::Backslash => self.buf.push('\\'),
            TextToken::Newline => self.end_line(),
            TextToken::Align(Align::Right) => self.right_align(),
            // `<C>` (centre) and `<L>` (left) are line-start alignment for the message window.
            // Inside a picture box the host already knows where the block goes, and this game
            // only ever pairs them with single-line labels, so they stay no-ops.
            TextToken::Align(_) => {}
            TextToken::Outline(on) => {
                self.flush();
                self.style.outline = *on;
            }
            TextToken::Color(index) => {
                self.flush();
                // The token is the raw `\c[n]` index (u32). The palette is
                // 1-based in the editor but 0-based in the data, so no shift.
                self.style.colour = Some(*index as i32);
            }
            TextToken::FontSize(px) => {
                self.set_font_px(*px as f32);
            }
            TextToken::FontSizeDelta(delta) => {
                let next = self.style.font_px + *delta as f32;
                self.set_font_px(next);
            }
            TextToken::Var(var) => {
                let text = self.var_text(var);
                self.buf.push_str(&text);
            }
            TextToken::Code { kind, args } => {
                let kind = *kind;
                let args = args.clone();
                self.code(kind, &args);
            }
            // Ruby, icons, sounds, speed, spacing, absolute positioning: none of them move
            // the glyphs of the runs themselves, and this game barely uses them.
            _ => {}
        }
    }

    /// Apply a new font size, clamping it to something drawable.
    ///
    /// A non-positive size is the game's way of asking for the default: CE132's settings
    /// screen writes `\f[0]` on all 23 row labels, so treating zero as one pixel would
    /// render the whole panel at 1/20 scale. Only positive values are literal sizes.
    fn set_font_px(&mut self, px: f32) {
        self.flush();
        self.style.font_px = if px.is_finite() && px > 0.0 {
            px.max(MIN_FONT_PX)
        } else {
            self.ctx.default_font_px.max(MIN_FONT_PX)
        };
    }

    /// A `\code[...]` whose argument did not parse as a plain integer.
    ///
    /// The tokeniser only falls back to [TextToken::Code] when the bracket contains
    /// markup, which is the common case in this game: `\f[\cself[19]]` and
    /// `\f[\cself[17]]` are how every HUD label picks its size. So the arguments here are
    /// markup fragments, not numbers, and they have to go back through the same
    /// evaluator before the kind can be applied.
    fn code(&mut self, kind: CodeKind, args: &[String]) {
        match kind {
            CodeKind::FontSize => {
                if let Some(px) = args.first().and_then(|arg| self.int_raw(arg)) {
                    self.set_font_px(px as f32);
                }
            }
            CodeKind::FontSizeDelta => {
                if let Some(delta) = args.first().and_then(|arg| self.int_raw(arg)) {
                    let next = self.style.font_px + delta as f32;
                    self.set_font_px(next);
                }
            }
            CodeKind::Color => {
                if let Some(index) = args.first().and_then(|arg| self.int_raw(arg)) {
                    self.flush();
                    self.style.colour = Some(index);
                }
            }
            // `\ax[n]` / `\ay[n]` place the *next character* absolutely inside the picture.
            // This game uses them 13 times, always alongside a `\n` that already puts the text
            // where the author wanted it, and honouring them would need a second layout pass.
            // Recorded here so the omission is visible rather than silent.
            CodeKind::AbsoluteX | CodeKind::AbsoluteY => {}
            // Every other code is either an inline object (icons, ruby) or a message-window
            // animation knob; neither moves the glyphs of this run.
            _ => {}
        }
    }

    /// Close the pending text into a chunk, if there is any.
    fn flush(&mut self) {
        if self.buf.is_empty() {
            return;
        }
        let text = std::mem::take(&mut self.buf);
        self.line.width += width_of(&text, self.style.font_px, self.advance);
        self.line.chunks.push(Chunk {
            text,
            style: self.style,
        });
    }

    /// Finish the current line and start a new one.
    fn end_line(&mut self) {
        self.flush();
        let line = std::mem::take(&mut self.line);
        self.lines.push(line);
    }

    /// `<R>`: everything after this point hugs the block's right edge.
    ///
    /// Only the first `<R>` on a line counts. A second one would have to right-align an
    /// already right-aligned tail against itself, and the game never writes one.
    fn right_align(&mut self) {
        self.flush();
        if self.line.tail_from.is_none() {
            self.line.tail_from = Some(self.line.chunks.len());
        }
    }

    /// Resolve one variable escape to text.
    fn var_text(&mut self, var: &VarRef) -> String {
        if self.depth >= MAX_ESCAPE_DEPTH {
            return String::new();
        }
        self.depth += 1;
        let text = self.var_text_inner(var);
        self.depth -= 1;
        text
    }

    fn var_text_inner(&mut self, var: &VarRef) -> String {
        match var.bank {
            // The type-`a` database and the system database share a bank on the VM side;
            // `\sdb` resolves through the same call because WOLF stores both in one array.
            VarBank::VarDb | VarBank::SysDb => {
                let [ty, row, column] = self.db_coords(var);
                self.ctx.cells.cdb(ty, row, column).unwrap_or_default()
            }
            VarBank::UserDb => {
                let [ty, row, column] = self.db_coords(var);
                self.ctx.cells.udb(ty, row, column).unwrap_or_default()
            }
            VarBank::Normal => match self.slot(var) {
                Some(index) => self.ctx.vars.num(index).to_string(),
                None => String::new(),
            },
            // Strings, self variables and `\cself` all reach the same string bank from the
            // host's point of view; which bank is *live* is the caller's business (see
            // [Vars::text]).
            VarBank::Str | VarBank::SelfVar | VarBank::CommonSelf => match self.slot(var) {
                Some(index) => self.ctx.vars.text(index),
                None => String::new(),
            },
            // Reserve numbers, XY coordinates and named XY have no picture-side meaning.
            _ => String::new(),
        }
    }

    /// The slot number of an escape, resolving indirection like `\v[\v[12]]`.
    fn slot(&mut self, var: &VarRef) -> Option<usize> {
        match var.slot() {
            Some(slot) => Some(slot as usize),
            None => {
                let first = var.args.first()?;
                let value = self.int(first)?;
                usize::try_from(value).ok()
            }
        }
    }

    /// The three bracket fields of a database escape, missing fields defaulting to 0.
    fn db_coords(&mut self, var: &VarRef) -> [i32; 3] {
        let mut coords = [0_i32; 3];
        for (index, field) in var.args.iter().take(3).enumerate() {
            coords[index] = self.int(field).unwrap_or(0);
        }
        coords
    }

    /// Render a token list back to plain text, resolving the escapes inside it.
    fn display(&mut self, tokens: &[TextToken]) -> String {
        if self.depth >= MAX_ESCAPE_DEPTH {
            return String::new();
        }
        self.depth += 1;
        let mut out = String::new();
        for token in tokens {
            match token {
                TextToken::Text(text) => out.push_str(text),
                TextToken::Backslash => out.push('\\'),
                TextToken::Newline => out.push('\n'),
                TextToken::Var(var) => {
                    let text = self.var_text(var);
                    out.push_str(&text);
                }
                TextToken::Code { args, .. } => {
                    for (index, arg) in args.iter().enumerate() {
                        if index > 0 {
                            out.push(':');
                        }
                        let inner = tokenize(arg);
                        let text = self.display(&inner);
                        out.push_str(&text);
                    }
                }
                _ => {}
            }
        }
        self.depth -= 1;
        out
    }

    /// Evaluate a token list as an integer, if it resolves to one.
    fn int(&mut self, tokens: &[TextToken]) -> Option<i32> {
        let text = self.display(tokens);
        text.trim().parse::<i32>().ok()
    }

    /// Evaluate a markup fragment (a [TextToken::Code] argument) as an integer.
    fn int_raw(&mut self, source: &str) -> Option<i32> {
        let tokens = tokenize(source);
        self.int(&tokens)
    }
}

/// Width of a plain string at `font_px`, through the caller's advance function.
fn width_of(text: &str, font_px: f32, advance: Advance<'_>) -> f32 {
    text.chars()
        .filter(|ch| *ch != '\n')
        .map(|ch| advance(ch, font_px))
        .sum()
}

/// Vertical advance from this line's top edge to the next line's.
///
/// The tallest font on the line sets the pitch, so a `\f[24]` label followed by
/// `\f[12]` body text keeps the same rhythm as the retail HUD instead of stacking
/// two different baselines. An empty line still occupies one default pitch, which is
/// what `\n`-only text pictures rely on.
fn line_pitch(ctx: &Ctx<'_>, line: &Line) -> f32 {
    let font_px = line
        .chunks
        .iter()
        .map(|chunk| chunk.style.font_px)
        .fold(0.0_f32, f32::max);
    let font_px = if font_px > 0.0 {
        font_px
    } else {
        ctx.default_font_px.max(MIN_FONT_PX)
    };
    font_px * DEFAULT_LINE_PITCH_RATIO
}

/// Top-left corner of a block of `(w, h)` whose anchor sits on `(x, y)`.
fn anchor_origin(anchor: u8, x: f32, y: f32, w: f32, h: f32) -> (f32, f32) {
    match anchor {
        1 => (x - w * 0.5, y - h * 0.5),
        2 => (x, y - h),
        3 => (x - w, y),
        4 => (x - w, y - h),
        // 0 is top-left, and so is every code this game never writes (5, 6, 7 are
        // reserved by the editor).
        _ => (x, y),
    }
}

/// Turn a placed chunk into a [Run].
fn run_of(chunk: &Chunk, x: f32, y: f32, align_right: bool) -> Run {
    Run {
        text: chunk.text.clone(),
        x,
        y,
        font_px: chunk.style.font_px,
        colour: chunk.style.colour,
        outline: chunk.style.outline,
        align_right,
        width: 0.0,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    struct NoVars;
    impl Vars for NoVars {
        fn num(&self, _index: usize) -> i32 {
            0
        }
        fn text(&self, _index: usize) -> String {
            String::new()
        }
    }

    struct FakeVars {
        nums: Vec<i32>,
        texts: Vec<&'static str>,
    }
    impl Vars for FakeVars {
        fn num(&self, index: usize) -> i32 {
            self.nums.get(index).copied().unwrap_or(0)
        }
        fn text(&self, index: usize) -> String {
            self.texts.get(index).copied().unwrap_or("").to_string()
        }
    }

    struct NoCells;
    impl Cells for NoCells {
        fn cdb(&self, _ty: i32, _row: i32, _column: i32) -> Option<String> {
            None
        }
        fn udb(&self, _ty: i32, _row: i32, _column: i32) -> Option<String> {
            None
        }
    }

    /// One row of each database, keyed the way `\cdb[0:12:1]` writes it.
    struct FakeCells;
    impl Cells for FakeCells {
        fn cdb(&self, ty: i32, row: i32, column: i32) -> Option<String> {
            match (ty, row, column) {
                (0, 12, 0) => Some("Lv".to_string()),
                (0, 12, 1) => Some("3".to_string()),
                _ => None,
            }
        }
        fn udb(&self, ty: i32, row: i32, column: i32) -> Option<String> {
            match (ty, row, column) {
                (0, 4, 2) => Some("ゆう".to_string()),
                _ => None,
            }
        }
    }

    struct NoColours;
    impl Colours for NoColours {
        fn colour(&self, _index: i32) -> Option<[u8; 3]> {
            None
        }
    }

    struct FakeColours;
    impl Colours for FakeColours {
        fn colour(&self, index: i32) -> Option<[u8; 3]> {
            match index {
                0 => Some([255, 255, 255]),
                1 => Some([255, 0, 0]),
                _ => None,
            }
        }
    }

    static NO_VARS: NoVars = NoVars;
    static NO_CELLS: NoCells = NoCells;
    static NO_COLOURS: NoColours = NoColours;

    /// A context with no variables, no database and no palette; 20 px default font.
    fn bare() -> Ctx<'static> {
        Ctx {
            vars: &NO_VARS,
            cells: &NO_CELLS,
            colours: &NO_COLOURS,
            default_font_px: 20.0,
        }
    }

    fn approx(actual: f32, expected: f32) -> bool {
        (actual - expected).abs() < 0.01
    }

    #[test]
    fn measure_is_five_half_ems() {
        // Five half-width glyphs at 24 px. The retail engine measures 56.31 px because it
        // uses the real font; see measure_with_digit_advances_is_proportional.
        assert!(approx(measure("18:30", 24.0), 60.0));
    }

    #[test]
    fn measure_of_full_width_glyphs_is_one_em_each() {
        assert!(approx(measure("周三", 18.0), 36.0));
    }

    #[test]
    fn measure_skips_newlines() {
        assert!(approx(measure("AB\nCD", 20.0), 40.0));
    }

    #[test]
    fn measure_with_digit_advances_is_proportional() {
        // Lolita.ttf advances, measured with fontTools (upm 2048): 2=0.4990, 1=0.4595,
        // :=0.2993, 4=0.4888, 0=0.5996. The retail screenshot agrees to within a pixel;
        // the half-em rule in choice::advance_at does not.
        let advance = |ch: char, px: f32| {
            let em = match ch {
                '2' => 0.4990,
                '1' => 0.4595,
                ':' => 0.2993,
                '4' => 0.4888,
                '0' => 0.5996,
                _ => 0.5,
            };
            px * em
        };
        assert!(approx(measure_with("21:40", 24.0, &advance), 56.31));
    }

    #[test]
    fn anchor_top_left_is_the_origin() {
        let runs = layout("AB", 10.0, 12.0, 0, &bare());
        assert_eq!(runs.len(), 1);
        assert!(approx(runs[0].x, 10.0));
        assert!(approx(runs[0].y, 12.0));
    }

    #[test]
    fn anchor_top_right_ends_the_block_on_x() {
        // "AB" at the default 20 px is 20 px wide, so the block starts on 100 - 20.
        let runs = layout("AB", 100.0, 0.0, 3, &bare());
        assert!(approx(runs[0].x, 80.0));
        assert!(approx(runs[0].y, 0.0));
    }

    #[test]
    fn anchor_centre_centres_both_axes() {
        // 20 px wide, one 26 px line (20 x 1.3).
        let runs = layout("AB", 100.0, 100.0, 1, &bare());
        assert!(approx(runs[0].x, 90.0));
        assert!(approx(runs[0].y, 87.0));
    }

    #[test]
    fn anchor_bottom_left_lifts_the_block() {
        let runs = layout("AB", 100.0, 100.0, 2, &bare());
        assert!(approx(runs[0].x, 100.0));
        assert!(approx(runs[0].y, 74.0));
    }

    #[test]
    fn anchor_bottom_right_moves_both_edges() {
        let runs = layout("AB", 100.0, 100.0, 4, &bare());
        assert!(approx(runs[0].x, 80.0));
        assert!(approx(runs[0].y, 74.0));
    }

    #[test]
    fn unknown_anchor_falls_back_to_top_left() {
        let runs = layout("AB", 100.0, 100.0, 5, &bare());
        assert!(approx(runs[0].x, 100.0));
        assert!(approx(runs[0].y, 100.0));
    }

    #[test]
    fn run_width_matches_the_measured_advance() {
        let runs = layout("AB", 0.0, 0.0, 0, &bare());
        assert_eq!(runs.len(), 1);
        assert!(approx(runs[0].width, 20.0));
        assert!(approx(
            runs[0].width,
            measure(&runs[0].text, runs[0].font_px)
        ));
    }

    #[test]
    fn font_escape_splits_a_line_into_runs() {
        let runs = layout(r"\f[10]A\f[20]B", 0.0, 0.0, 0, &bare());
        assert_eq!(runs.len(), 2);
        assert_eq!(runs[0].text, "A");
        assert!(approx(runs[0].font_px, 10.0));
        assert_eq!(runs[1].text, "B");
        assert!(approx(runs[1].font_px, 20.0));
        assert!(approx(runs[1].x, 5.0));
    }

    #[test]
    fn colour_escape_is_an_index_not_rgb() {
        let runs = layout(r"\c[2]X", 0.0, 0.0, 0, &bare());
        assert_eq!(runs[0].colour, Some(2));
        // ... and resolving it needs the palette, which has no entry for 2.
        assert_eq!(rgb(&bare(), Some(2)), None);
    }

    #[test]
    fn rgb_resolves_through_the_palette() {
        let colours = FakeColours;
        let ctx = Ctx {
            vars: &NO_VARS,
            cells: &NO_CELLS,
            colours: &colours,
            default_font_px: 20.0,
        };
        assert_eq!(rgb(&ctx, Some(1)), Some([255, 0, 0]));
        assert_eq!(rgb(&ctx, None), None);
    }

    #[test]
    fn outline_escape_flags_the_run() {
        let runs = layout(r"\EA\NB", 0.0, 0.0, 0, &bare());
        assert_eq!(runs.len(), 2);
        assert!(runs[0].outline);
        assert!(!runs[1].outline);
    }

    #[test]
    fn numeric_variable_is_expanded_in_decimal() {
        let mut nums = vec![0_i32; 8];
        nums[3] = 42;
        let vars = FakeVars {
            nums,
            texts: Vec::new(),
        };
        let ctx = Ctx {
            vars: &vars,
            cells: &NO_CELLS,
            colours: &NO_COLOURS,
            default_font_px: 20.0,
        };
        let runs = layout(r"\v[3]", 0.0, 0.0, 0, &ctx);
        assert_eq!(runs[0].text, "42");
    }

    #[test]
    fn self_variable_is_expanded() {
        let mut texts = vec![""; 10];
        texts[9] = "周六";
        let vars = FakeVars {
            nums: Vec::new(),
            texts,
        };
        let ctx = Ctx {
            vars: &vars,
            cells: &NO_CELLS,
            colours: &NO_COLOURS,
            default_font_px: 20.0,
        };
        let runs = layout(r"\cself[9]", 0.0, 0.0, 0, &ctx);
        assert_eq!(runs[0].text, "周六");
    }

    #[test]
    fn computed_font_size_reads_a_self_variable() {
        // The shape every HUD label uses: \f[\cself[19]], with the size living in a
        // self variable.
        let mut texts = vec![""; 20];
        texts[19] = "24";
        let vars = FakeVars {
            nums: Vec::new(),
            texts,
        };
        let ctx = Ctx {
            vars: &vars,
            cells: &NO_CELLS,
            colours: &NO_COLOURS,
            default_font_px: 20.0,
        };
        let runs = layout(r"\f[\cself[19]]21:40", 0.0, 0.0, 0, &ctx);
        assert_eq!(runs.len(), 1);
        assert!(approx(runs[0].font_px, 24.0));
        assert!(approx(runs[0].x, 0.0));
    }

    #[test]
    fn database_cells_are_expanded() {
        let cells = FakeCells;
        let ctx = Ctx {
            vars: &NO_VARS,
            cells: &cells,
            colours: &NO_COLOURS,
            default_font_px: 20.0,
        };
        let runs = layout(r"\cdb[0:12:0]\cdb[0:12:1]", 0.0, 0.0, 0, &ctx);
        assert_eq!(runs[0].text, "Lv3");
        let runs = layout(r"\udb[0:4:2]", 0.0, 0.0, 0, &ctx);
        assert_eq!(runs[0].text, "ゆう");
    }

    #[test]
    fn missing_database_cell_is_empty() {
        let runs = layout(r"\cdb[0:1:1]X", 0.0, 0.0, 0, &bare());
        assert_eq!(runs[0].text, "X");
    }

    #[test]
    fn right_align_hugs_the_block_right_edge() {
        // "AB" (20 px) then a 10 px "C" pushed to the block's right edge: the block is
        // 25 px wide, so C starts on 20, not on 20-and-a-bit past it.
        let runs = layout(r"\f[20]AB<R>\f[10]C", 0.0, 0.0, 0, &bare());
        assert_eq!(runs.len(), 2);
        assert!(approx(runs[0].x, 0.0));
        assert!(!runs[0].align_right);
        assert!(approx(runs[1].x, 20.0));
        assert!(runs[1].align_right);
    }

    #[test]
    fn newline_advances_by_one_pitch() {
        let runs = layout(concat!(r"\f[20]A", "\n", "B"), 0.0, 0.0, 0, &bare());
        assert_eq!(runs.len(), 2);
        assert!(approx(runs[0].y, 0.0));
        assert!(approx(runs[1].y, 26.0));
    }

    #[test]
    fn trailing_newline_does_not_add_a_line() {
        let runs = layout("AB\n", 0.0, 0.0, 0, &bare());
        assert_eq!(runs.len(), 1);
    }

    #[test]
    fn block_size_is_the_widest_line_by_the_pitch() {
        let (w, h) = block_size("AB\nABCDE", &bare());
        assert!(approx(w, 50.0));
        assert!(approx(h, 52.0));
    }

    #[test]
    fn literal_backslash_is_preserved() {
        let runs = layout(r"A\\B", 0.0, 0.0, 0, &bare());
        assert_eq!(runs[0].text, r"A\B");
    }

    #[test]
    fn absolute_position_escape_is_parsed_but_ignored() {
        // \ax/\ay would need a second layout pass; they must not leak into the text.
        let runs = layout(r"\ax[100]\ay[50]A", 0.0, 0.0, 0, &bare());
        assert_eq!(runs.len(), 1);
        assert_eq!(runs[0].text, "A");
        assert!(approx(runs[0].x, 0.0));
    }
}
