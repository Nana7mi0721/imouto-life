//! The runtime choice panel: WOLF draws opcode `102`'s options itself.
//!
//! A WOLF script never draws its own menu frame for a choice prompt. `102` hands the
//! option strings to the engine, and the engine moves the cursor, paints the window
//! skin and returns a 0-based index. Keeping that split is what makes a script written
//! for the engine work here unchanged: the measured title event draws only its
//! background (one `150` command) and then parks on a `102` with three options, so
//! without a runtime panel the port shows a title screen with no menu at all.
//!
//! Geometry is measured, not guessed. The engine's own panel code is
//! `FUN_004c3d20` (size), `FUN_004c3fa0` (anchor), `FUN_004c40f0` (frame and cursor)
//! and `FUN_004c35c0` (row picking); the numbers below come from those functions and
//! from two retail 1024x576 screenshots (docs/re/SCREENSHOT_METRICS.md). The frame is
//! `SystemFile/WindowBase.png`, the grey skin the game's SysDatabase
//! "ウィンドウ画像 / ×選択肢ウィンドウ画像" row names (see [`crate::window`]), and the
//! selected row sits in `SystemFile/CursorBase.png`, the engine's 12x12 cursor box.

use crate::assets::Assets;
use crate::atlas::{Atlas, SpriteQuad, TextQuad};
use crate::picture::{SCREEN_H, SCREEN_W};
use crate::window::{self, WindowPiece};

/// Game.dat u8[12]: the choice window's line spacing, 14 in this game.
pub const CHOICE_LINE_SPACING: f32 = 14.0;
/// The game's base font size, Game.dat u8[0].
///
/// The original scales a line-spacing setting by min(base, 32) / 32 before adding it
/// to the row's own font size (docs/re/TEXT_METRICS.md section 1), so 14 px of choice
/// spacing becomes trunc(14 * 16 / 32) = 7 px of extra row pitch at the shipped base
/// size - which is exactly the 27 px row pitch the retail panels measure.
pub const BASE_FONT_PX: f32 = 16.0;
/// Inset of the option text from the panel's left edge, in logical pixels.
///
/// FUN_004c3fa0:25-28 puts the text origin at 2 + (base << 2) / 10 inside the window
/// (8 px at base 16), and both retail screenshots measure 8 px from the window's border
/// to the first glyph's ink. The same inset is used on the right, so the panel is the
/// widest option plus twice this value.
pub const TEXT_INSET: f32 = 8.0;
/// Distance from the panel's top edge to the first option row.
///
/// The retail panels put the first row's ink 9 px below the border and the glyph's own
/// top bearing is 3 px, so the row starts 6 px down. The panel is then exactly
/// ROW_TOP + rows * pitch tall: 114 px for the four-option prompt and 141 px for the
/// five-option one, both within half a pixel of the screenshots.
pub const ROW_TOP: f32 = 6.0;
/// Fallback pixel size for option text, used by tools and tests that have no VM.
///
/// The live size is Sys8, which common event 48 writes as 20 and which WOLF shares
/// between messages, choices and text pictures (work/yado.txt lines 56-79); the game
/// passes it in through [layout_at_sized] via [crate::game::Game::font_px]. This
/// constant must stay equal to that default, and it is the single source of truth for
/// sizing when no VM exists: the frame is measured with the same advance the glyphs are
/// painted with, so the two can never drift again. They used to: the panel budgeted
/// 16 px per character while the text pass drew 22 px glyphs, so the nine-character
/// opening option 微风吹拂而过的麦田 needed 198 px inside a 144 px content box and
/// wrapped, and its second line was overdrawn by the row below.
pub const TEXT_PX: f32 = 20.0;
/// Asset name of the choice cursor: the small nine-slice box the engine draws behind
/// the selected row (FUN_004c40f0 draws it from the picture table's cursor entries).
pub const CURSOR_SKIN: &str = "SystemFile/CursorBase.png";
/// Frame thickness of the cursor skin, in texels (12x12 skin, one third).
pub const CURSOR_CORNER: u32 = 4;

/// Vertical advance of one option row, in pixels.
///
/// The shipped engine computes line pitch as the row's own font size plus
/// trunc(spacing * min(base, 32) / 32); for the choice window that is Sys8 + 7 px, which
/// is the 27 px the retail panels measure at Sys8 = 20.
#[must_use]
pub fn line_pitch(font_px: f32) -> f32 {
    let extra = (CHOICE_LINE_SPACING * BASE_FONT_PX.min(32.0) / 32.0).trunc();
    font_px + extra
}

/// Where the panel and its option lines sit on the logical screen.
#[derive(Clone, Debug, PartialEq)]
pub struct ChoiceLayout {
    /// Panel rectangle, `[x, y, w, h]` in logical pixels.
    pub rect: [f32; 4],
    /// One rectangle per option, top to bottom.
    pub lines: Vec<[f32; 4]>,
    /// Rectangle of the highlighted option (the cursor row).
    pub cursor: [f32; 4],
    /// Font size the panel was measured at (Sys8). The text pass draws the rows at this
    /// size, so it must travel with the layout instead of falling back to the caller's
    /// default: a setting that changes Sys8 would otherwise measure and paint differently.
    pub font_px: f32,
}

/// Whether a glyph is full width, i.e. one em wide at any size.
///
/// These are the CJK, kana, hangul, full-width form and CJK-symbol planes plus the
/// supplementary ideographic planes. Everything else is treated as half width, which is
/// right for Latin, digits and the ASCII punctuation WOLF menus use.
fn is_wide(ch: char) -> bool {
    matches!(
        ch as u32,
        0x1100..=0x115F
            | 0x2E80..=0x303E
            | 0x3041..=0x33FF
            | 0x3400..=0x4DBF
            | 0x4E00..=0x9FFF
            | 0xA000..=0xA4CF
            | 0xAC00..=0xD7A3
            | 0xF900..=0xFAFF
            | 0xFE30..=0xFE4F
            | 0xFF00..=0xFF60
            | 0xFFE0..=0xFFE6
            | 0x20000..=0x3FFFD
    )
}

/// Advance width of one character at [`TEXT_PX`], in pixels.
/// Advance of one character at a given font size, in pixels.
///
/// Full-width glyphs (CJK, kana, hangul, full-width forms) take one em; everything
/// else takes half an em. The message window draws at Sys8 rather than [`TEXT_PX`],
/// so the advance has to be a function of the font size, not a constant.
pub fn advance_at(ch: char, font_px: f32) -> f32 {
    if is_wide(ch) {
        font_px
    } else {
        font_px * 0.5
    }
}

/// Width the text pass will need to draw `text` on one line, in pixels.
#[must_use]
pub fn text_width(text: &str) -> f32 {
    text_width_at(text, TEXT_PX)
}

/// Width `text` needs when the text pass draws it at `font_px`, in pixels.
pub fn text_width_at(text: &str, font_px: f32) -> f32 {
    text.chars().map(|ch| advance_at(ch, font_px)).sum()
}

/// Panel size in logical pixels, rounded so every row lands on a whole pixel.
///
/// The width is the widest option measured at the size the text pass actually draws,
/// plus the cursor column and the frame padding. A flat per-character estimate is what
/// broke CJK: a full-width glyph is one em, not half of one.
fn size(options: &[String], font_px: f32) -> (f32, f32) {
    // Measure the label that is actually drawn, not the raw option key: the title
    // menu passes `menu1`/`menu2`/`menu3` but paints the localised labels, so sizing
    // the raw keys clipped them. `option_label` is the identity for every other prompt.
    let widest = options
        .iter()
        .map(|option| text_width_at(option_label(option), font_px))
        .fold(0.0_f32, f32::max);
    let width = widest + TEXT_INSET * 2.0;
    let rows = options.len().max(1) as f32;
    (
        width.round(),
        (ROW_TOP + rows * line_pitch(font_px)).round(),
    )
}

/// Builds rows and cursor rectangle for a panel whose top-left corner is `(x, y)`.
fn build(options: &[String], cursor: usize, x: f32, y: f32, font_px: f32) -> ChoiceLayout {
    let (width, height) = size(options, font_px);
    let rect = [x, y, width, height];
    let pitch = line_pitch(font_px);
    let mut lines = Vec::with_capacity(options.len());
    for (index, _) in options.iter().enumerate() {
        lines.push([
            rect[0] + TEXT_INSET,
            rect[1] + ROW_TOP + index as f32 * pitch,
            rect[2] - TEXT_INSET * 2.0,
            pitch,
        ]);
    }
    // The cursor is not the text row: it is the engine's own box, drawn 6 px inside the
    // window frame and as tall as the font (not as tall as the row pitch). The retail
    // screenshots measure exactly that: bar 6 px in from the border, 20 px tall, with
    // the text 8 px in and 27 px apart.
    let row = lines
        .get(cursor)
        .copied()
        .or_else(|| lines.first().copied());
    let cursor_rect = match row {
        Some(row) => [rect[0] + ROW_TOP, row[1], rect[2] - ROW_TOP * 2.0, font_px],
        None => [rect[0], rect[1], rect[2], pitch],
    };
    ChoiceLayout {
        rect,
        lines,
        cursor: cursor_rect,
        font_px,
    }
}

/// Lays out a choice panel for `options` with `cursor` highlighted, centred on the
/// logical screen.
///
/// This is the layout for a host with no engine anchor (tests, offline tools). The
/// game itself goes through [`layout_at`] with the script's own system variables,
/// because the original engine never centres a choice window on its own.
#[must_use]
pub fn layout(options: &[String], cursor: usize) -> ChoiceLayout {
    let (width, height) = size(options, TEXT_PX);
    let x = ((SCREEN_W as f32) - width) / 2.0;
    let y = ((SCREEN_H as f32) - height) / 2.0;
    build(options, cursor, x.round(), y.round(), TEXT_PX)
}

/// Lays out the panel at the engine's own choice-window anchor.
///
/// WOLF places `102`'s window at system variables 3 (X) and 4 (Y). When the anchor
/// would put the whole panel off screen (the shipped title event parks it at
/// (-1000,-1000), and the manual's `-1` sentinel means "default position"), the panel
/// falls back to the centred default position so the prompt is still visible and
/// clickable. Known anchors are taken as the top-left corner, exactly like the manual
/// describes. (The old comment quoted (512,1000); the data actually writes -1000.)
#[must_use]
pub fn layout_at(options: &[String], cursor: usize, x: i32, y: i32) -> Option<ChoiceLayout> {
    layout_at_sized(options, cursor, x, y, TEXT_PX)
}

/// layout_at with the engine's live font size (Sys8) instead of the fallback.
#[must_use]
pub fn layout_at_sized(
    options: &[String],
    cursor: usize,
    x: i32,
    y: i32,
    font_px: f32,
) -> Option<ChoiceLayout> {
    if options.is_empty() {
        return None;
    }
    // The original title menu is real image buttons painted by event 43; the port must
    // not paint an inferred text panel over them, but it still needs the fixed hit rows.
    if is_title_image_menu(options) {
        return Some(title_image_layout(cursor));
    }
    let panel = build(options, cursor, x as f32, y as f32, font_px);
    let on_screen = panel.rect[0] < SCREEN_W as f32
        && panel.rect[1] < SCREEN_H as f32
        && panel.rect[0] + panel.rect[2] > 0.0
        && panel.rect[1] + panel.rect[3] > 0.0;
    if on_screen {
        Some(panel)
    } else {
        // Out-of-bounds anchor: fall back to the centred default position instead of
        // painting nothing. The shipped title event parks its window at (-1000,-1000);
        // treating that as "invisible" left the title with no menu the player could see
        // or click. WOLF's manual reserves the sentinel -1 for "default position", and an
        // off-screen pair is the same intent, so honour it here. This only affects anchors
        // that would draw entirely outside the screen; every in-screen prompt is unchanged.
        let (width, height) = size(options, font_px);
        let cx = ((SCREEN_W as f32) - width) / 2.0;
        let cy = ((SCREEN_H as f32) - height) / 2.0;
        Some(build(options, cursor, cx.round(), cy.round(), font_px))
    }
}

/// Whether `options` are the three internal keys the shipped title event hands to
/// opcode `102` (`menu1`/`menu2`/`menu3`).
///
/// The original title menu is not a text window at all: three hand-drawn image buttons
/// (`Picture/menu1_a.png` .. `menu3_a.png`) are painted at fixed screen rows by the
/// conditional title event 43; `_a` is the dark selected button, `_b` the lighter
/// unselected one, and system variable 20 picks which `_a` overlay is drawn.
/// Recognising these exact keys lets the port skip the inferred text panel and let the
/// script's own images be the menu (see [`title_image_layout`] for the hit rows).
#[must_use]
pub fn is_title_image_menu(options: &[String]) -> bool {
    options.len() == 3 && options[0] == "menu1" && options[1] == "menu2" && options[2] == "menu3"
}

/// Fixed screen rows of the original title image-button menu.
///
/// CE43 draws `menu1_*`/`menu2_*`/`menu3_*` at x=10, y=400/450/500, each 240x52. These
/// rectangles are used only for the mouse hit test; the visible menu is the script's own
/// pictures, so nothing is painted from this layout.
fn title_image_layout(cursor: usize) -> ChoiceLayout {
    const X: f32 = 10.0;
    const Y: f32 = 400.0;
    const W: f32 = 240.0;
    const H: f32 = 52.0;
    const GAP: f32 = 50.0;
    let mut lines = Vec::with_capacity(3);
    for index in 0..3 {
        lines.push([X, Y + index as f32 * GAP, W, H]);
    }
    let cursor_rect = lines.get(cursor).copied().unwrap_or(lines[0]);
    ChoiceLayout {
        rect: [X, Y, W, H + 2.0 * GAP],
        lines,
        cursor: cursor_rect,
        // This path is only a mouse hit test; nothing is painted from it.
        font_px: TEXT_PX,
    }
}

/// The nine window pieces that paint `layout`'s frame.
#[must_use]
pub fn skin_pieces(layout: &ChoiceLayout, skin_w: u32, skin_h: u32) -> Vec<WindowPiece> {
    window::nine_slice(layout.rect, skin_w, skin_h)
}

/// Human-facing label for a choice option.
///
/// The shipped title event names its three options `menu1`/`menu2`/`menu3`; those are
/// internal keys, and its branch bodies state their meaning (common event 42 pc29/35/43:
/// "はじめから" / "つづきから" / "おわる"). Showing the raw keys on the title menu looked
/// broken, so map just those three keys to localised labels here. Every other prompt keeps
/// its own text untouched, and the underlying option strings (used for branching and for
/// tests) are never rewritten.
fn option_label(option: &str) -> &str {
    match option {
        "menu1" => "开始游戏",
        "menu2" => "读取存档",
        "menu3" => "退出游戏",
        other => other,
    }
}

/// Builds the panel draw list: window pieces, then the cursor box, then the rows.
///
/// The engine marks the selected row by drawing its cursor skin over it
/// (FUN_004c40f0), not by prefixing a glyph: the retail panels show a framed box behind
/// the current option and the option text aligned with every other row.
fn draw(
    atlas: &mut Atlas,
    assets: &mut Assets,
    options: &[String],
    cursor: usize,
    layout: &ChoiceLayout,
) -> (Vec<SpriteQuad>, Vec<TextQuad>) {
    let mut sprites = Vec::new();
    if let Some(skin) = atlas.add_asset(assets, window::SKIN) {
        for piece in skin_pieces(layout, skin.w, skin.h) {
            sprites.push(SpriteQuad {
                number: window::PANEL_PICTURE,
                rect: piece.rect,
                uv: skin.sub_uv(atlas.size()[0], atlas.size()[1], piece.src),
                alpha: 1.0,
                tint: [1.0, 1.0, 1.0],
                blend: 0,
            });
        }
    }
    // The cursor box: the same nine-slice routine as the window, over the cursor's own
    // 12x12 skin, one row tall and 6 px in from each side.
    if cursor < options.len() {
        if let Some(skin) = atlas.add_asset(assets, CURSOR_SKIN) {
            for piece in window::nine_slice_cornered(layout.cursor, skin.w, skin.h, CURSOR_CORNER) {
                sprites.push(SpriteQuad {
                    number: window::PANEL_PICTURE,
                    rect: piece.rect,
                    uv: skin.sub_uv(atlas.size()[0], atlas.size()[1], piece.src),
                    alpha: 1.0,
                    tint: [1.0, 1.0, 1.0],
                    blend: 0,
                });
            }
        }
    }
    let mut texts = Vec::with_capacity(options.len());
    for (index, option) in options.iter().enumerate() {
        texts.push(TextQuad {
            number: window::PANEL_PICTURE,
            text: option_label(option).to_owned(),
            rect: layout.lines[index],
            alpha: 1.0,
            // The panel was measured at Sys8; paint the row at that same size.
            font_px: layout.font_px,
            colour: [255, 255, 255],
            outline: false,
            weight: 700,
        });
    }
    (sprites, texts)
}

/// Builds the centred panel: window pieces first, then one text row per option.
pub fn overlay(
    atlas: &mut Atlas,
    assets: &mut Assets,
    options: &[String],
    cursor: usize,
) -> (Vec<SpriteQuad>, Vec<TextQuad>) {
    if options.is_empty() || is_title_image_menu(options) {
        return (Vec::new(), Vec::new());
    }
    let panel = layout(options, cursor);
    draw(atlas, assets, options, cursor, &panel)
}

/// Builds the engine-anchored draw list, `None` when the window would be invisible.
///
/// Telling the caller that nothing was painted is better than silently dropping a
/// prompt a player still has to answer.
pub fn overlay_at(
    atlas: &mut Atlas,
    assets: &mut Assets,
    options: &[String],
    cursor: usize,
    x: i32,
    y: i32,
) -> Option<(Vec<SpriteQuad>, Vec<TextQuad>)> {
    if is_title_image_menu(options) {
        return Some((Vec::new(), Vec::new()));
    }
    let panel = layout_at(options, cursor, x, y)?;
    Some(draw(atlas, assets, options, cursor, &panel))
}

/// overlay_at with the engine's live font size (Sys8).
pub fn overlay_at_sized(
    atlas: &mut Atlas,
    assets: &mut Assets,
    options: &[String],
    cursor: usize,
    x: i32,
    y: i32,
    font_px: f32,
) -> Option<(Vec<SpriteQuad>, Vec<TextQuad>)> {
    if is_title_image_menu(options) {
        return Some((Vec::new(), Vec::new()));
    }
    let panel = layout_at_sized(options, cursor, x, y, font_px)?;
    Some(draw(atlas, assets, options, cursor, &panel))
}

#[cfg(test)]
mod tests {
    use super::*;

    fn options(count: usize) -> Vec<String> {
        (0..count).map(|index| format!("option {index}")).collect()
    }

    #[test]
    fn a_three_option_panel_is_centred_and_stacked() {
        let layout = layout(&options(3), 0);
        assert!((layout.rect[0] + layout.rect[2] / 2.0 - 512.0).abs() <= 1.0);
        assert!((layout.rect[1] + layout.rect[3] / 2.0 - 288.0).abs() <= 1.0);
        assert_eq!(layout.lines.len(), 3);
        assert!(layout.lines[1][1] > layout.lines[0][1]);
        // The cursor box sits on the first row, 6 px inside the frame, as tall as the
        // font: the retail screenshots measure 6 px in and 20 px tall at Sys8 = 20.
        assert_eq!(layout.cursor[1], layout.lines[0][1]);
        assert_eq!(layout.cursor[0], layout.rect[0] + ROW_TOP);
        assert_eq!(layout.cursor[3], TEXT_PX);
    }

    #[test]
    fn the_cursor_follows_the_selected_row() {
        let panel = layout(&options(3), 2);
        assert_eq!(panel.cursor[1], panel.lines[2][1]);
        // Out-of-range cursors clamp to a real row instead of panicking.
        assert_eq!(layout(&options(3), 99).cursor[1], panel.lines[0][1]);
    }

    #[test]
    fn the_panel_geometry_is_the_measured_102_panel() {
        // A four-option prompt of seven full-width characters: the retail 102 panel is
        // 156 px wide, 114 px tall, rows 27 px apart and text 8 px inside the frame.
        let rows = vec!["已经这个时间了".to_owned(); 4];
        let panel =
            layout_at_sized(&rows, 0, 400, 200, 20.0).expect("an on-screen anchor yields a panel");
        assert_eq!(panel.rect[2], 7.0 * 20.0 + TEXT_INSET * 2.0, "panel width");
        assert_eq!(panel.rect[3], ROW_TOP + 4.0 * 27.0, "four rows are 114 px");
        assert_eq!(panel.lines[0][0], panel.rect[0] + TEXT_INSET, "text inset");
        assert_eq!(
            panel.lines[0][2],
            panel.rect[2] - TEXT_INSET * 2.0,
            "row width"
        );
        for index in 1..4 {
            let pitch = panel.lines[index][1] - panel.lines[index - 1][1];
            assert!((pitch - 27.0).abs() < 0.01, "row {index} pitch is {pitch}");
        }
    }

    #[test]
    fn a_cjk_option_is_wide_enough_for_the_text_it_draws() {
        // Regression for the clipped opening prompt: a nine-character CJK option is 9 em
        // wide at the size the glyphs are drawn, and the row has to fit the cursor column
        // plus that text or the renderer wraps it into the row below.
        let option = "微风吹拂而过的麦田".to_owned();
        let panel = layout(std::slice::from_ref(&option), 0);
        let content = panel.lines[0][2];
        assert_eq!(text_width(&option), 9.0 * TEXT_PX);
        assert!(
            content >= text_width(&option),
            "row {content} must fit {} px of text",
            text_width(&option)
        );
        assert!(panel.rect[0] >= 0.0 && panel.rect[0] + panel.rect[2] <= SCREEN_W as f32);
    }

    #[test]
    fn a_long_option_widens_the_panel() {
        let narrow = layout(&["a".to_owned()], 0);
        let wide = layout(&["a".repeat(40)], 0);
        // No minimum width: the engine sizes the window to the widest option plus the
        // 8 px inset on each side, and a one-letter option gets a 26 px box.
        assert_eq!(narrow.rect[2], text_width("a") + TEXT_INSET * 2.0);
        assert!(wide.rect[2] > narrow.rect[2]);
    }

    #[test]
    fn an_empty_prompt_draws_nothing() {
        let mut atlas = Atlas::new();
        let mut assets = Assets::new("no-such-root");
        let (sprites, texts) = overlay(&mut atlas, &mut assets, &[], 0);
        assert!(sprites.is_empty() && texts.is_empty());
    }

    #[test]
    fn the_overlay_draws_the_plain_labels_and_no_marker_glyph() {
        let mut atlas = Atlas::new();
        let mut assets = Assets::new("no-such-root");
        // Without the skin assets on disk only the rows come back: the panel degrades
        // to text instead of failing the frame, and the engine's cursor is a skin, so a
        // missing cursor skin costs the box but never the option text.
        let (sprites, texts) = overlay(&mut atlas, &mut assets, &options(2), 1);
        assert!(sprites.is_empty(), "no skin available in a bare root");
        assert_eq!(texts.len(), 2);
        assert_eq!(texts[0].text, "option 0");
        assert_eq!(texts[1].text, "option 1");
    }

    #[test]
    fn rows_are_painted_at_the_size_the_panel_was_measured_at() {
        let mut atlas = Atlas::new();
        let mut assets = Assets::new("no-such-root");
        // A live Sys8 other than the default must reach the text pass; passing 0.0 here
        // made the host fall back to its own default while the panel was sized for Sys8.
        let (_, texts) = overlay_at_sized(&mut atlas, &mut assets, &options(2), 0, 400, 200, 33.0)
            .expect("an on-screen anchor yields a panel");
        assert!(texts.iter().all(|text| text.font_px == 33.0));
    }
}
