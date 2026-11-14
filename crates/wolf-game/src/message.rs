//! The 101 Message window: where the engine draws its text, and how much of it.
//!
//! WOLF splits the message window in two, and this module is deliberately only the
//! second half:
//!
//! * the FRAME (the nine-slice skin, the face chip) is drawn by common event 63, which
//!   the engine starts for the whole run and which paints ordinary 150 pictures into
//!   picture slots 19500 and up whenever Sys12 says a message is up. Nothing here draws
//!   a frame, and nothing should: the author owns that geometry.
//! * the TEXT is drawn by the engine itself, and its geometry comes from the system
//!   variables that the same event initialises before jumping back to its caller.
//!
//! Every law below is measured; docs/OPCODE_101.md carries the bytecode evidence.
//!
//! * [已实测] The coordinate scale is the screen divided by the engine virtual screen:
//!   rateX = width / 32, rateY = height / 24 (common event 48 divides Sys116/Sys117 by
//!   exactly those numbers; common event 63 multiplies back and stores 1024 and 576).
//! * [已实测] Text origin = Sys1/Sys2 = (2*rateX, 17*rateY + rateY/10) = (64, 410) on a
//!   1024x576 screen. The nudge is rateY/10 (24 / 10 = 2). An earlier note here read 412 and
//!   blamed a /5 nudge, but that capture predated the 121 operator fix (0x3000 was remainder).
//! * [已实测] Font size = Sys8, and this game sets 20.
//! * [已实测] Line pitch = Sys8 + Game.dat text_line_spacing (6) = 26.
//! * [已实测] Typewriter speed = Sys9 characters per second: 500 at boot (common event
//!   48), 120 after common event 269 slows it down. Sys10 holds 9 idle, 1 while showing.
//! * [未实测] The per-frame reveal uses a fractional accumulator of Sys9/60 per frame;
//!   the manual only says X characters per second, and no frame-exact sample exists.
//! * [已实测] The pause cursor is drawn by the ENGINE at (Sys1 + Sys5, Sys2 + Sys6) =
//!   (576, 554), which is inside the frame, bottom right of the text origin.
//! * [已实测] The right padding of the wrap box mirrors the left one: the frame
//!   picture (slot 19500, 960x168 centred at Sys3/Sys4) covers x 32..992, the text
//!   origin is x 64, so the wrap width is 896 and a long row stops 32 px before the
//!   frame's right edge.
//! * [已实测] A bare LF byte is the line break; 3,915 of them exist in real messages.

use crate::choice;
use wolf_format::messagetext::{Align, TextToken};

/// Frames per second the engine counts the typewriter speed in.
pub const FPS: f32 = 60.0;

/// Sys8 as common event 48 leaves it in this game.
pub const DEFAULT_FONT_PX: f32 = 20.0;

/// Game.dat text_line_spacing: the spacing is scaled by the base font size before it is
/// added to Sys8, so a 16 px base font turns the configured 6 into 3 px (see
/// `line_height`).
pub const LINE_GAP: f32 = 6.0;

/// Game.dat's base font size, the divisor the line spacing is scaled by.
///
/// The engine multiplies the configured spacing by `min(base, 32) / 32` (FUN_004c2d50),
/// so the base size matters even though the game never reads it back at run time.
pub const BASE_FONT_PX: f32 = 16.0;

/// Sys9 as common event 48 leaves it: characters per second.
pub const DEFAULT_CHARS_PER_SECOND: i32 = 500;

/// Sys10 as common event 63 leaves it while a message is up.
pub const DEFAULT_PREROLL: i32 = 9;

/// The virtual screen the coordinate scale divides by: 32 steps across, 24 down.
pub const SCREEN_STEPS: (f32, f32) = (32.0, 24.0);

/// Picture slot common event 63 keeps the message-window frame in (its self[20]).
///
/// This is a SLOT NUMBER, not a file name: Picture/19500 does not exist, and the frame
/// is an ordinary 150 window-type draw with the skin SysDatabase answers for the
/// [250, 18, 0, 24] read. When the slot is live its rectangle is the box the text must
/// wrap inside, which is why this module still reads it.
pub const FRAME_PICTURE: i32 = 19500;

/// Gap between the last glyph of the text and an auto-placed pause cursor, in pixels.
pub const CURSOR_GAP: f32 = 6.0;

/// The engine pause cursor: `SystemFile/Text_Pause.png`.
///
/// [已实测] The file is 17x90 and its opaque pixels fall into six 17x15 bands, each a
/// 16x10 downward triangle whose top edge sits at y 3, 2, 1, 0, 1, 3 inside its band: a
/// six-frame bob, not the three 17x30 frames an earlier note guessed. No script draws
/// it - common event 63 only draws slots 19500..19503 - so the engine owns it.
pub const CURSOR_FILE: &str = "SystemFile/Text_Pause.png";
/// Width of one cursor frame, in pixels.
pub const CURSOR_FRAME_W: u32 = 17;
/// Height of one cursor frame, in pixels.
pub const CURSOR_FRAME_H: u32 = 15;
/// Frames in the cursor bob animation.
pub const CURSOR_FRAMES: u32 = 6;
/// Frames of the message clock per cursor animation step (未验证 rhythm).
pub const CURSOR_STEP_FRAMES: u32 = 8;
/// Trace id for the cursor quad; never a picture slot, which are all >= -100.
pub const CURSOR_SLOT: i32 = -100_000;

/// The smallest font size the styled pass honours, in pixels.
const MIN_FONT_PX: f32 = 1.0;

/// The colour a message run falls back to: white, like the engine default.
pub const DEFAULT_COLOUR: [u8; 3] = [255, 255, 255];

/// Which cursor frame a message clock lands on.
#[must_use]
pub fn cursor_frame(frames: u32) -> u32 {
    (frames / CURSOR_STEP_FRAMES) % CURSOR_FRAMES
}

/// The coordinate scale (rateX, rateY) for a screen size.
#[must_use]
pub fn coordinate_scale(screen_w: f32, screen_h: f32) -> (f32, f32) {
    (
        (screen_w / SCREEN_STEPS.0).max(1.0),
        (screen_h / SCREEN_STEPS.1).max(1.0),
    )
}

/// The text origin a boot-time initialiser leaves in Sys1/Sys2.
///
/// Sys1 = 2*rateX, then Sys2 = 17*rateY followed by a Ver3.00 nudge of the same rate. The
/// nudge is rateY/10: with rateY = 24 it is 2 px, and the running game now reads Sys2 = 410
/// (the YADOT-WOLF transcript of common event 63 publishes the identical `Sys2 += CSelf89 / 10`
/// line). Both terms are rounded, so the 1024x576 origin is (64, 410).
#[must_use]
pub fn default_origin(screen_w: f32, screen_h: f32) -> (f32, f32) {
    let (rate_x, rate_y) = coordinate_scale(screen_w, screen_h);
    (
        (2.0 * rate_x).round(),
        // Integer division, like the bytecode operator: 24 / 10 is 2, not 2.4 rounded up.
        (17.0 * rate_y + (rate_y / 10.0).trunc()).round(),
    )
}

/// Line advance in pixels for a font size: Sys8 + the scaled text_line_spacing.
///
/// The engine adds `trunc(spacing * min(base, 32) / 32)` (FUN_004c2d50), which is 3 px
/// for this game's 6 px spacing at the 16 px base font, not the full 6 px. The retail
/// message window measures 23 px between rows at Sys8 = 20, matching the scaled value.
#[must_use]
pub fn line_height(font_px: f32) -> f32 {
    font_px + (LINE_GAP * BASE_FONT_PX.min(32.0) / 32.0).trunc()
}

/// The system variables the message window reads.
///
/// Filled from Game by the caller; kept as plain numbers so this module stays
/// independent of the VM and can be tested without one.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct Vars {
    /// Sys1 - text origin X in absolute screen pixels.
    pub x: f32,
    /// Sys2 - text origin Y in absolute screen pixels.
    pub y: f32,
    /// Sys8 - font size in pixels; non-positive falls back to DEFAULT_FONT_PX.
    pub font_px: f32,
    /// Sys9 - typewriter speed in characters per second; zero or less shows it all.
    pub chars_per_second: i32,
    /// Sys10 - frames of pre-roll before typing starts.
    pub preroll: i32,
    /// Wrap width in pixels, or None to wrap at the frame right edge.
    pub width: Option<f32>,
    /// (Sys5, Sys6) - the pause cursor position relative to the origin, when both >= 0.
    pub cursor_offset: Option<(f32, f32)>,
    /// Screen width in pixels, used when width is None.
    pub screen_w: f32,
}

impl Vars {
    /// The message-window variables a boot-time initialiser leaves behind.
    #[must_use]
    pub fn defaults(screen_w: f32, screen_h: f32) -> Self {
        let (x, y) = default_origin(screen_w, screen_h);
        Self {
            x,
            y,
            font_px: DEFAULT_FONT_PX,
            chars_per_second: DEFAULT_CHARS_PER_SECOND,
            preroll: DEFAULT_PREROLL,
            width: None,
            cursor_offset: None,
            screen_w,
        }
    }

    /// The wrap width actually used, in pixels.
    #[must_use]
    pub fn wrap_width(&self) -> f32 {
        self.width.unwrap_or(self.screen_w - self.x)
    }

    /// The font size actually used, in pixels.
    #[must_use]
    pub fn font_px(&self) -> f32 {
        if self.font_px > 0.0 {
            self.font_px
        } else {
            DEFAULT_FONT_PX
        }
    }
}

/// One line of message text and where it goes.
#[derive(Clone, Debug, PartialEq)]
pub struct Row {
    /// The characters this row shows, already stripped of WOLF markup.
    pub text: String,
    /// Destination rectangle, [x, y, w, h] in logical pixels.
    pub rect: [f32; 4],
}

/// One same-styled span of a visible message row.
///
/// [已实测] A picture-150 text draw carries its own markup, and this game uses it for HUD
/// readouts that mix sizes and colours inside ONE picture: common event 217 puts
/// \f[18]73\f[14]日 at the top right with \f[24]\v[4]:\v[5] beside it, and common event 216's
/// status bar branches to \c[2]\f[14] for the same reason. One Row per line is too coarse to
/// draw that, so the styled pass reports runs and lets the renderer pick the face.
#[derive(Clone, Debug, PartialEq)]
pub struct Run {
    /// The characters this span shows, already stripped of markup.
    pub text: String,
    /// Destination rectangle, [x, y, w, h] in logical pixels.
    pub rect: [f32; 4],
    /// Font size in pixels this span is drawn at.
    pub font_px: f32,
    /// Resolved colour, or None when the palette had no answer for the index.
    pub colour: Option<[u8; 3]>,
    /// Whether the span carries the WOLF outline escape (docs/OPCODE_101.md section 7).
    pub outline: bool,
}

/// The colour table a message colour escape indexes into.
///
/// [未实测] The engine reads these from the SysDatabase colour settings, which nothing in
/// this repo decodes yet, so the palette is a parameter: a caller without one passes
/// [WhiteColours] and gets plain white text instead of a guess.
pub trait Colours {
    /// The RGB behind a colour index, or None when the index is out of range.
    fn colour(&self, index: u32) -> Option<[u8; 3]>;
}

/// The palette that answers white for every index.
///
/// This is what the plain [layout] feeds the styled pass, so an unconfigured game draws
/// readable text rather than nothing.
#[derive(Clone, Copy, Debug, Default)]
pub struct WhiteColours;

impl Colours for WhiteColours {
    fn colour(&self, _index: u32) -> Option<[u8; 3]> {
        Some(DEFAULT_COLOUR)
    }
}

/// What the text pass should draw for the current message.
#[derive(Clone, Debug, PartialEq)]
pub struct Layout {
    /// Visible rows, top to bottom. A partially typed row is already truncated.
    pub rows: Vec<Row>,

    /// Same-styled spans of the visible rows, already positioned.
    ///
    /// A styled layout splits a row wherever the font, colour or outline changes; the plain
    /// [layout] emits exactly one white run per row so both share one renderer path.
    pub runs: Vec<Run>,
    /// Characters revealed so far, counting line breaks.
    pub typed: usize,
    /// Characters in the whole message, counting line breaks.
    pub total: usize,
    /// The message is still typing.
    pub typing: bool,
    /// Where to draw the pause cursor, when the message is complete.
    pub cursor: Option<[f32; 2]>,
    /// Font size the rows are drawn at.
    pub font_px: f32,
    /// Line advance in pixels.
    pub line_height: f32,
}

/// How many characters of a message are visible at a given frame.
///
/// The engine accumulates Sys9/60 characters per frame and draws the integer part, so
/// the count after N frames is floor(N * Sys9 / 60). None means "all of them": a speed of
/// zero or less shows the message at once.
#[must_use]
pub fn revealed(frames: u32, chars_per_second: i32, preroll: i32) -> Option<usize> {
    if chars_per_second <= 0 {
        return None;
    }
    let preroll = preroll.max(0) as u32;
    if frames < preroll {
        return Some(0);
    }
    let elapsed = f64::from(frames - preroll);
    let whole = (elapsed * f64::from(chars_per_second) / f64::from(FPS)).floor();
    usize::try_from(whole as u64).ok()
}

/// Wrap text to width pixels at font_px, honouring explicit line breaks.
///
/// WOLF message markup uses a real newline for a forced break, and its text is
/// overwhelmingly CJK, which has no spaces to break on: this wraps between any two
/// characters. A space that lands on the break is dropped, so an ASCII sentence does not
/// start its next line with one.
#[must_use]
pub fn wrap(text: &str, width: f32, font_px: f32) -> Vec<String> {
    let width = width.max(font_px);
    let mut rows: Vec<String> = Vec::new();
    for paragraph in text.split('\n') {
        let mut row = String::new();
        let mut used = 0.0_f32;
        for ch in paragraph.chars() {
            let advance = choice::advance_at(ch, font_px);
            if used + advance > width && !row.is_empty() {
                rows.push(std::mem::take(&mut row));
                used = 0.0;
                if ch == ' ' {
                    continue;
                }
            }
            row.push(ch);
            used += advance;
        }
        rows.push(row);
    }
    rows
}

/// Lay out the current message for the text pass.
///
/// text is the raw message as the script produced it; WOLF markup (colour, outline,
/// face prefix, ruby) is stripped here, because the renderer must not be handed escapes.
#[must_use]
pub fn layout(text: &str, vars: &Vars, frames: u32) -> Layout {
    let font_px = vars.font_px();
    let line_height = line_height(font_px);
    let stripped = wolf_format::messagetext::strip(text);
    let rows = wrap(&stripped, vars.wrap_width(), font_px);
    let total: usize = rows.iter().map(|row| row.chars().count()).sum::<usize>() + rows.len() - 1;
    let typed =
        revealed(frames, vars.chars_per_second, vars.preroll).map_or(total, |n| n.min(total));
    let mut budget = typed;
    let mut visible: Vec<Row> = Vec::new();
    for (index, row) in rows.iter().enumerate() {
        if index > 0 {
            if budget == 0 {
                break;
            }
            budget -= 1;
        }
        let take = row.chars().count().min(budget);
        let shown: String = row.chars().take(take).collect();
        budget -= take;
        visible.push(Row {
            text: shown.clone(),
            rect: [
                vars.x,
                vars.y + index as f32 * line_height,
                vars.wrap_width(),
                line_height,
            ],
        });
        if take < row.chars().count() {
            break;
        }
    }
    let typing = typed < total;
    let cursor = if typing {
        None
    } else {
        Some(match vars.cursor_offset {
            Some((dx, dy)) => [vars.x + dx, vars.y + dy],
            None => match visible.last() {
                Some(row) => [
                    vars.x + choice::text_width_at(&row.text, font_px) + CURSOR_GAP,
                    row.rect[1],
                ],
                None => [vars.x, vars.y],
            },
        })
    };
    // The plain pass knows nothing about styling, so every row becomes exactly one white
    // run: the renderer then has a single path for both layouts.
    let runs: Vec<Run> = visible
        .iter()
        .map(|row| Run {
            text: row.text.clone(),
            rect: row.rect,
            font_px,
            colour: Some(DEFAULT_COLOUR),
            outline: false,
        })
        .collect();
    Layout {
        rows: visible,
        runs,
        typed,
        total,
        typing,
        cursor,
        font_px,
        line_height,
    }
}

/// The style a character is drawn with, after the escapes are resolved.
#[derive(Clone, Copy, Debug, PartialEq)]
struct Style {
    font_px: f32,
    colour: Option<[u8; 3]>,
    outline: bool,
}

/// One character and the style the escape stream had reached when it appeared.
#[derive(Clone, Copy, Debug, PartialEq)]
struct Glyph {
    ch: char,
    style: Style,
}

/// One row of the styled layout, before it becomes [Row]s and [Run]s.
#[derive(Clone, Debug, PartialEq)]
struct StyledLine {
    glyphs: Vec<Glyph>,
    align: Align,
    /// True when a hard line break, not a wrap, started this row.
    hard_break_before: bool,
}

/// What the escape stream produces: a glyph, a hard break, or an alignment change.
#[derive(Clone, Copy, Debug, PartialEq)]
enum Item {
    Glyph(Glyph),
    Break,
    Align(Align),
}

/// Map the two shipped alertness-meter tiles onto box-drawing glyphs.
///
/// The files are deliberately tiny single-colour squares (`box01` white, `box02`
/// black) and are used only by CE277's `\img[...]` run. Keeping the mapping here
/// leaves the font/picture renderers untouched for every other inline image.
fn inline_box_glyph(path: &str) -> Option<char> {
    let name = path
        .rsplit(['\\', '/'])
        .next()
        .unwrap_or(path)
        .to_ascii_lowercase();
    match name.as_str() {
        "box01.png" => Some('□'),
        "box02.png" => Some('■'),
        _ => None,
    }
}

/// Feed plain text into the item stream: a real LF is a break, everything else is a glyph.
fn push_plain(items: &mut Vec<Item>, text: &str, style: Style) {
    for ch in text.chars() {
        if ch == '\n' {
            items.push(Item::Break);
        } else {
            items.push(Item::Glyph(Glyph { ch, style }));
        }
    }
}

/// Turn the raw message into a flat stream of glyphs and layout events.
///
/// The module only honours the escapes a message window can act on: colour, outline, font
/// size and alignment. Everything else (ruby, icons, sounds, per-character spacing, the
/// offset escapes) is dropped rather than shown, because a control escape reaching the
/// screen is worse than a missing effect. A surviving variable read is the opposite case:
/// the VM expands variables before show_message, so one that is still here was written
/// literally and is shown as text.
fn styled_items(text: &str, base_font_px: f32, colours: &dyn Colours) -> Vec<Item> {
    let mut style = Style {
        font_px: base_font_px.max(MIN_FONT_PX),
        colour: None,
        outline: false,
    };
    let mut items: Vec<Item> = Vec::new();
    for token in wolf_format::messagetext::tokenize(text) {
        if let TextToken::Var(_) = token {
            let literal = wolf_format::messagetext::to_source(std::slice::from_ref(&token));
            push_plain(&mut items, &literal, style);
            continue;
        }
        match &token {
            TextToken::Text(text) => push_plain(&mut items, text, style),
            TextToken::Backslash => push_plain(&mut items, "\\", style),
            TextToken::Newline => items.push(Item::Break),
            TextToken::Image(path) | TextToken::ImageNearest(path) => {
                // CE277 paints the night alertness meter as a row of `box01`/`box02`
                // inline images. The glyph pass has no image channel, so dropping the
                // token erased the whole meter (the black-grid progress bar the
                // player sees in the retail build). The two box files are 19x20
                // single-colour squares; map them onto the matching box glyphs and
                // let the normal text layout place them in the row. Any other
                // inline image keeps the old drop behaviour rather than guessing.
                if let Some(ch) = inline_box_glyph(path) {
                    push_plain(&mut items, &ch.to_string(), style);
                }
            }
            TextToken::Align(align) => items.push(Item::Align(*align)),
            TextToken::Color(index) => {
                // An index the palette cannot answer keeps the colour it had, so a bad
                // escape does not silently blank the rest of the line.
                if let Some(rgb) = colours.colour(*index) {
                    style.colour = Some(rgb);
                }
            }
            TextToken::Outline(on) => style.outline = *on,
            // In a message the size escape is a FONT SIZE, not a font slot: the slot form
            // is \font[n], which lands in Code and is ignored here.
            TextToken::FontSize(px) => style.font_px = (*px as f32).max(MIN_FONT_PX),
            TextToken::FontSizeDelta(delta) => {
                style.font_px = (style.font_px + *delta as f32).max(MIN_FONT_PX);
            }
            _ => {}
        }
    }
    items
}

/// Wrap the item stream into rows, at the font size each character carries.
///
/// A wrap boundary costs no typewriter character (only a hard break does), and alignment
/// survives a soft wrap - the engine keeps the line mode until the next hard break, which
/// is what the author sees when a right-aligned HUD string happens to be long.
fn styled_lines(items: &[Item], wrap_width: f32) -> Vec<StyledLine> {
    let width = wrap_width.max(1.0);
    let mut lines: Vec<StyledLine> = Vec::new();
    let mut glyphs: Vec<Glyph> = Vec::new();
    let mut used = 0.0_f32;
    let mut align = Align::Left;
    let mut hard_before = false;
    for item in items {
        match *item {
            Item::Align(next) => align = next,
            Item::Break => {
                lines.push(StyledLine {
                    glyphs: std::mem::take(&mut glyphs),
                    align,
                    hard_break_before: hard_before,
                });
                hard_before = true;
                align = Align::Left;
                used = 0.0;
            }
            Item::Glyph(glyph) => {
                let advance = choice::advance_at(glyph.ch, glyph.style.font_px);
                // A glyph that cannot fit even on an empty row is kept, not looped on.
                if used + advance > width && !glyphs.is_empty() {
                    lines.push(StyledLine {
                        glyphs: std::mem::take(&mut glyphs),
                        align,
                        hard_break_before: hard_before,
                    });
                    hard_before = false;
                    used = 0.0;
                    if glyph.ch == ' ' {
                        continue;
                    }
                }
                glyphs.push(glyph);
                used += advance;
            }
        }
    }
    lines.push(StyledLine {
        glyphs,
        align,
        hard_break_before: hard_before,
    });
    lines
}

/// Lay out a message with its styling intact.
///
/// [layout] strips every escape before measuring, which is right for a plain message and
/// wrong for the HUD pictures this game draws: common event 217 renders the clock as
/// \f[24]\v[4]:\v[5] next to a \f[18]73\f[14]日 date, and flattening those to one Sys8 size
/// makes them overlap. This keeps the per-character size, colour and outline instead.
///
/// The laws, measured in docs/OPCODE_101.md:
/// * a row is as tall as its tallest glyph plus the scaled text_line_spacing, so a bigger
///   escape grows the row;
/// * alignment is measured against the wrap width and resets to the left at a hard break;
/// * the typewriter counts plain characters only, so a soft wrap is free and a cut can land
///   in the middle of a styled run, which is then split.
///
/// The returned [Layout] carries the same rows as [layout] plus the [Run]s to draw; the
/// pause cursor sits after the last visible glyph of the last visible row.
#[must_use]
pub fn layout_styled(text: &str, vars: &Vars, frames: u32, colours: &dyn Colours) -> Layout {
    let font_px = vars.font_px();
    let wrap_width = vars.wrap_width();
    let items = styled_items(text, font_px, colours);
    let lines = styled_lines(&items, wrap_width);
    let breaks = items
        .iter()
        .filter(|item| matches!(item, Item::Break))
        .count();
    let glyphs = items
        .iter()
        .filter(|item| matches!(item, Item::Glyph(_)))
        .count();
    let total = glyphs + breaks;
    let typed =
        revealed(frames, vars.chars_per_second, vars.preroll).map_or(total, |n| n.min(total));
    let mut budget = typed;
    let mut rows: Vec<Row> = Vec::new();
    let mut runs: Vec<Run> = Vec::new();
    let mut y = vars.y;
    let mut last_end: Option<(f32, f32)> = None;
    for line in &lines {
        if line.hard_break_before {
            if budget == 0 {
                break;
            }
            budget -= 1;
        }
        let take = line.glyphs.len().min(budget);
        budget -= take;
        let visible = &line.glyphs[..take];
        let mut tallest = 0.0_f32;
        let mut width = 0.0_f32;
        for glyph in visible {
            tallest = tallest.max(glyph.style.font_px);
            width += choice::advance_at(glyph.ch, glyph.style.font_px);
        }
        // An empty row still takes the base pitch, so a blank line keeps its height.
        let row_height = line_height(if tallest > 0.0 { tallest } else { font_px });
        let offset = match line.align {
            Align::Left => 0.0,
            Align::Center => ((wrap_width - width) * 0.5).max(0.0),
            Align::Right => (wrap_width - width).max(0.0),
        };
        let left = vars.x + offset;
        rows.push(Row {
            text: visible.iter().map(|glyph| glyph.ch).collect(),
            rect: [left, y, wrap_width, row_height],
        });
        // Split the row wherever the style changes: one run per (font, colour, outline).
        let mut run_left = left;
        let mut index = 0usize;
        while index < visible.len() {
            let style = visible[index].style;
            let mut end = index + 1;
            while end < visible.len() && visible[end].style == style {
                end += 1;
            }
            let mut run_text = String::new();
            let mut run_width = 0.0_f32;
            for glyph in &visible[index..end] {
                run_text.push(glyph.ch);
                run_width += choice::advance_at(glyph.ch, glyph.style.font_px);
            }
            runs.push(Run {
                text: run_text,
                rect: [run_left, y, run_width, row_height],
                font_px: style.font_px,
                colour: style.colour,
                outline: style.outline,
            });
            run_left += run_width;
            index = end;
        }
        last_end = Some((left + width, y));
        y += row_height;
        if take < line.glyphs.len() {
            break;
        }
    }
    let typing = typed < total;
    let cursor = if typing {
        None
    } else {
        Some(match vars.cursor_offset {
            Some((dx, dy)) => [vars.x + dx, vars.y + dy],
            None => match last_end {
                Some((end, top)) => [end + CURSOR_GAP, top],
                None => [vars.x, vars.y],
            },
        })
    };
    Layout {
        rows,
        runs,
        typed,
        total,
        typing,
        cursor,
        font_px,
        line_height: line_height(font_px),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn vars() -> Vars {
        Vars {
            x: 64.0,
            y: 410.0,
            font_px: DEFAULT_FONT_PX,
            chars_per_second: 0,
            preroll: 0,
            width: Some(200.0),
            cursor_offset: None,
            screen_w: 1024.0,
        }
    }

    #[test]
    fn the_coordinate_scale_is_the_screen_divided_by_32_and_24() {
        assert_eq!(coordinate_scale(1024.0, 576.0), (32.0, 24.0));
        assert_eq!(coordinate_scale(1280.0, 720.0), (40.0, 30.0));
    }

    #[test]
    fn the_text_origin_is_two_steps_in_and_seventeen_down() {
        assert_eq!(default_origin(1024.0, 576.0), (64.0, 410.0));
        // 1280x720: 2*40 = 80, 17*30 + 30/10 = 513.
        assert_eq!(default_origin(1280.0, 720.0), (80.0, 513.0));
        let vars = Vars::defaults(1024.0, 576.0);
        assert_eq!((vars.x, vars.y), (64.0, 410.0));
        assert_eq!(vars.font_px(), 20.0);
        assert_eq!(vars.chars_per_second, 500);
        assert_eq!(vars.wrap_width(), 960.0);
    }

    #[test]
    fn the_line_pitch_scales_the_game_dat_spacing_by_the_base_font() {
        // spacing 6 * min(base 16, 32) / 32 = 3 px of gap on top of Sys8.
        assert_eq!(line_height(20.0), 23.0);
        assert_eq!(line_height(14.0), 17.0);
    }

    #[test]
    fn a_full_width_message_wraps_at_the_font_size() {
        let rows = wrap("一二三四五六七八九十一二三", 200.0, 20.0);
        assert_eq!(
            rows,
            vec!["一二三四五六七八九十".to_owned(), "一二三".to_owned()]
        );
    }

    #[test]
    fn an_explicit_line_break_starts_a_new_row() {
        let rows = wrap("上\n下", 200.0, 20.0);
        assert_eq!(rows, vec!["上".to_owned(), "下".to_owned()]);
    }

    #[test]
    fn rows_advance_by_one_line_pitch() {
        let mut vars = vars();
        vars.width = Some(20.0);
        let layout = layout("甲乙", &vars, 0);
        assert_eq!(layout.rows.len(), 2);
        assert_eq!(layout.rows[0].rect, [64.0, 410.0, 20.0, 23.0]);
        assert_eq!(layout.rows[1].rect[1], 433.0);
    }

    #[test]
    fn a_zero_speed_typewriter_shows_the_whole_message() {
        assert_eq!(revealed(10, 0, 0), None);
        let layout = layout("你好", &vars(), 0);
        assert_eq!(layout.typed, 2);
        assert!(!layout.typing);
        assert_eq!(layout.rows.len(), 1);
        assert_eq!(layout.rows[0].text, "你好");
    }

    #[test]
    fn a_speed_is_characters_per_second_not_per_frame() {
        assert_eq!(revealed(60, 30, 0), Some(30));
        assert_eq!(revealed(1, 30, 0), Some(0));
        assert_eq!(revealed(59, 30, 0), Some(29));
        // The retail speed of 500 characters per second emits 8 per frame.
        assert_eq!(revealed(1, 500, 0), Some(8));
        assert_eq!(revealed(3, 500, 0), Some(25));
    }

    #[test]
    fn the_preroll_delays_the_first_character() {
        assert_eq!(revealed(3, 60, 5), Some(0));
        assert_eq!(revealed(5, 60, 5), Some(0));
        assert_eq!(revealed(7, 60, 5), Some(2));
    }

    #[test]
    fn a_typing_message_reveals_one_row_at_a_time_and_has_no_cursor() {
        let mut vars = vars();
        vars.chars_per_second = 60;
        vars.width = Some(20.0);
        let layout = layout("甲乙丙", &vars, 1);
        assert_eq!(layout.typed, 1);
        assert!(layout.typing);
        assert_eq!(layout.rows.len(), 1);
        assert_eq!(layout.rows[0].text, "甲");
        assert_eq!(layout.cursor, None);
    }

    #[test]
    fn the_pause_cursor_sits_after_the_last_glyph_when_the_engine_places_it() {
        let layout = layout("甲乙", &vars(), 0);
        assert_eq!(layout.cursor, Some([64.0 + 40.0 + CURSOR_GAP, 410.0]));
    }

    #[test]
    fn an_explicit_cursor_offset_wins_over_the_auto_placement() {
        let mut vars = vars();
        vars.cursor_offset = Some((16.0, 6.0));
        let layout = layout("甲", &vars, 0);
        assert_eq!(layout.cursor, Some([80.0, 416.0]));
    }

    #[test]
    fn the_pause_cursor_walks_six_frames_and_loops() {
        let seen: Vec<u32> = (0..48)
            .map(|f| cursor_frame(f * CURSOR_STEP_FRAMES))
            .collect();
        assert_eq!(seen[..7], [0, 1, 2, 3, 4, 5, 0]);
        assert!(seen.iter().all(|f| *f < CURSOR_FRAMES));
        // Within one step the frame is steady, so a 60 fps message does not strobe.
        assert_eq!(cursor_frame(0), cursor_frame(CURSOR_STEP_FRAMES - 1));
    }

    #[test]
    fn the_retail_cursor_offset_lands_inside_the_frame() {
        // Sys5 = 512, Sys6 = 144 is what this game writes: 64+512, 410+144.
        let mut vars = vars();
        vars.cursor_offset = Some((512.0, 144.0));
        let layout = layout("甲", &vars, 0);
        assert_eq!(layout.cursor, Some([576.0, 554.0]));
    }

    #[test]
    fn wolf_markup_never_reaches_the_text_pass() {
        let layout = layout("\\E\\c[6]你好", &vars(), 0);
        assert_eq!(layout.rows[0].text, "你好");
        assert_eq!(layout.total, 2);
    }

    #[test]
    fn a_missing_font_size_falls_back_to_the_measured_font_size() {
        let mut vars = vars();
        vars.font_px = 0.0;
        let layout = layout("甲", &vars, 0);
        assert_eq!(layout.font_px, DEFAULT_FONT_PX);
    }

    /// A palette with three answers, so a resolved colour is visible in the output.
    struct Palette;

    impl Colours for Palette {
        fn colour(&self, index: u32) -> Option<[u8; 3]> {
            match index {
                0 => Some(DEFAULT_COLOUR),
                1 => Some([255, 0, 0]),
                2 => Some([0, 0, 255]),
                _ => None,
            }
        }
    }

    fn styled_with(text: &str, vars: &Vars, frames: u32) -> Layout {
        layout_styled(text, vars, frames, &Palette)
    }

    #[test]
    fn the_styled_layout_resolves_colour_indices() {
        let styled = styled_with(r"\c[1]赤\c[2]青", &vars(), 0);
        assert_eq!(styled.runs.len(), 2);
        assert_eq!(styled.runs[0].text, "赤");
        assert_eq!(styled.runs[0].colour, Some([255, 0, 0]));
        assert_eq!(styled.runs[1].text, "青");
        assert_eq!(styled.runs[1].colour, Some([0, 0, 255]));
        // Both runs sit on the same row, end to end.
        assert_eq!(styled.runs[1].rect[0], styled.runs[0].rect[0] + 20.0);
    }

    #[test]
    fn an_unknown_colour_index_keeps_the_previous_colour() {
        let styled = styled_with(r"\c[1]赤\c[9]青", &vars(), 0);
        assert_eq!(styled.runs.len(), 1);
        assert_eq!(styled.runs[0].text, "赤青");
        assert_eq!(styled.runs[0].colour, Some([255, 0, 0]));
    }

    #[test]
    fn the_outline_escape_toggles_the_run_flag() {
        let styled = styled_with(r"\E赤\N青", &vars(), 0);
        assert_eq!(styled.runs.len(), 2);
        assert!(styled.runs[0].outline);
        assert!(!styled.runs[1].outline);
    }

    #[test]
    fn a_message_mixes_font_sizes_within_one_row() {
        let styled = styled_with(r"\f[10]小\f[30]大", &vars(), 0);
        assert_eq!(styled.rows.len(), 1);
        assert_eq!(styled.runs.len(), 2);
        assert_eq!(styled.runs[0].font_px, 10.0);
        assert_eq!(styled.runs[1].font_px, 30.0);
        // The second run starts where the first ended: 64 + the 10px-wide glyph.
        assert_eq!(styled.runs[1].rect[0], 74.0);
        // The row is as tall as its tallest glyph plus the scaled game.dat spacing.
        assert_eq!(styled.rows[0].rect[3], 33.0);
        assert_eq!(styled.runs[0].rect[3], 33.0);
    }

    #[test]
    fn the_font_size_escape_grows_the_row_pitch() {
        let styled = styled_with(r"\f[40]甲", &vars(), 0);
        assert_eq!(styled.runs[0].font_px, 40.0);
        assert_eq!(styled.rows[0].rect[3], 43.0);
        // The layout keeps reporting the base Sys8 size and pitch, like the plain pass.
        assert_eq!(styled.font_px, DEFAULT_FONT_PX);
        assert_eq!(styled.line_height, 23.0);
    }

    #[test]
    fn cjk_text_wraps_at_the_current_font_size() {
        let mut vars = vars();
        vars.width = Some(60.0);
        let styled = styled_with("一二三四", &vars, 0);
        // 20px glyphs into a 60px box: three fit, the fourth wraps.
        assert_eq!(styled.rows.len(), 2);
        assert_eq!(styled.rows[0].text, "一二三");
        assert_eq!(styled.rows[1].text, "四");
        assert_eq!(styled.rows[1].rect[1], 433.0);
        // A wrapped row starts at the text origin, not at the row above's end.
        assert_eq!(styled.runs[1].rect, [64.0, 433.0, 20.0, 23.0]);
    }

    #[test]
    fn the_typewriter_cuts_inside_a_run_and_keeps_the_style() {
        let mut vars = vars();
        vars.chars_per_second = 60;
        // One character per frame at 60 characters per second: three revealed.
        let styled = styled_with(r"\c[1]甲乙\c[2]丙丁", &vars, 3);
        assert_eq!(styled.typed, 3);
        assert_eq!(styled.total, 4);
        assert!(styled.typing);
        assert_eq!(styled.runs.len(), 2);
        assert_eq!(styled.runs[0].text, "甲乙");
        // The cut landed inside the second run, so it is truncated, not dropped.
        assert_eq!(styled.runs[1].text, "丙");
        assert_eq!(styled.runs[1].colour, Some([0, 0, 255]));
        assert_eq!(styled.cursor, None);
    }

    #[test]
    fn a_soft_wrap_costs_no_typewriter_character() {
        let mut vars = vars();
        vars.chars_per_second = 60;
        vars.width = Some(20.0);
        // Two glyphs wrapped onto two rows: still two characters, so nothing is held back.
        let styled = styled_with("甲乙", &vars, 2);
        assert_eq!(styled.total, 2);
        assert_eq!(styled.typed, 2);
        assert!(!styled.typing);
        assert_eq!(styled.rows.len(), 2);
    }

    #[test]
    fn a_right_aligned_row_sits_against_the_wrap_edge() {
        let styled = styled_with(r"<R>ab", &vars(), 0);
        // Half-width glyphs at 20px are 10 wide: a 20px row in a 200px box, right aligned.
        assert_eq!(styled.runs[0].rect[0], 64.0 + 180.0);
        assert_eq!(styled.rows[0].rect[0], 64.0 + 180.0);
        assert_eq!(styled.rows[0].text, "ab");
    }

    #[test]
    fn a_centred_row_sits_in_the_middle_of_the_wrap_box() {
        let styled = styled_with(r"<C>ab", &vars(), 0);
        assert_eq!(styled.runs[0].rect[0], 64.0 + 90.0);
    }

    #[test]
    fn alignment_resets_to_the_left_after_a_hard_break() {
        let styled = styled_with("<R>ab\ncd", &vars(), 0);
        assert_eq!(styled.runs[0].rect[0], 64.0 + 180.0);
        assert_eq!(styled.runs[1].rect[0], 64.0);
        assert_eq!(styled.runs[1].rect[1], 433.0);
    }

    #[test]
    fn markup_never_reaches_the_styled_runs() {
        let styled = styled_with(r"\E\c[1]\f[24]你好", &vars(), 0);
        assert_eq!(styled.rows[0].text, "你好");
        assert_eq!(styled.runs.len(), 1);
        assert_eq!(styled.runs[0].text, "你好");
        assert_eq!(styled.runs[0].font_px, 24.0);
        assert!(styled.runs[0].outline);
        assert_eq!(styled.total, 2);
        assert_eq!(styled.typed, 2);
        assert!(!styled.typing);
    }

    #[test]
    fn a_variable_read_that_survives_the_vm_is_shown_as_text() {
        // The VM expands variables before show_message; a survivor was written literally.
        let styled = styled_with(r"\v[3]", &vars(), 0);
        assert_eq!(styled.total, 5);
        assert_eq!(styled.runs.len(), 1);
        assert_eq!(styled.runs[0].text, r"\v[3]");
    }

    #[test]
    fn the_pause_cursor_follows_the_last_styled_run() {
        let styled = styled_with(r"\c[1]甲乙", &vars(), 0);
        assert_eq!(styled.cursor, Some([64.0 + 40.0 + CURSOR_GAP, 410.0]));
    }

    #[test]
    fn an_empty_message_lays_out_a_single_empty_row() {
        let styled = styled_with("", &vars(), 0);
        assert_eq!(styled.rows.len(), 1);
        assert!(styled.rows[0].text.is_empty());
        assert!(styled.runs.is_empty());
        assert_eq!(styled.total, 0);
        assert_eq!(styled.typed, 0);
        assert!(!styled.typing);
        assert_eq!(styled.cursor, Some([64.0 + CURSOR_GAP, 410.0]));
    }

    #[test]
    fn the_alertness_meter_box_images_survive_as_box_glyphs() {
        // CE277 draws the meter as `\c[9]\img[Picture\box01.png]...`; the token
        // used to be dropped, leaving the night progress bar blank.
        let styled = styled_with(
            r"\c[9]\img[Picture\box01.png]\img[Picture\box02.png]",
            &vars(),
            0,
        );
        assert_eq!(styled.rows[0].text, "□■");
        assert_eq!(styled.total, 2);
        assert_eq!(styled.runs.len(), 1);
    }

    #[test]
    fn the_plain_layout_carries_one_white_run_per_row() {
        let plain = layout("你好", &vars(), 0);
        assert_eq!(plain.runs.len(), 1);
        assert_eq!(plain.runs[0].text, "你好");
        assert_eq!(plain.runs[0].rect, plain.rows[0].rect);
        assert_eq!(plain.runs[0].colour, Some(DEFAULT_COLOUR));
        assert!(!plain.runs[0].outline);
    }
}
