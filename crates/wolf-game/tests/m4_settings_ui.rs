//! M4 settings-screen layout (common event 132 -> common event 95).
//!
//! The settings UI is built entirely from ten text pictures, each drawn at the same base
//! coordinate and separated by a 290 type-2 draw-coordinate shift. CE95 works in tenths of
//! a character cell, so the screen store scales the whole block back to pixels. The last
//! help-text redraw carries head 0x411f20 (bit 0x400000): it asks the draw to keep the
//! slot's existing shift, which is what lands it inside the help box at the bottom.
//!
//! These tests pin the visible result so a future refactor cannot silently stack the rows
//! or drop the help text again. Data-missing runs print a skip and return, keeping the
//! default cargo test exit 0.

use std::path::PathBuf;

use wolf_game::Game;

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let path = PathBuf::from(raw);
    if path.is_absolute() {
        return path;
    }
    let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    base.pop();
    base.pop();
    base.join(path)
}

fn visible(raw: &str) -> String {
    let mut out = String::new();
    let mut chars = raw.chars().peekable();
    while let Some(c) = chars.next() {
        if (c as u32) != 92 {
            out.push(c);
            continue;
        }
        while let Some(&ch) = chars.peek() {
            if ch.is_ascii_alphanumeric() {
                chars.next();
            } else {
                break;
            }
        }
        if chars.peek() == Some(&'[') {
            for ch in chars.by_ref() {
                if ch == ']' {
                    break;
                }
            }
        }
    }
    out
}

fn settings_game() -> Option<Game> {
    let root = data_root();
    if !root.join("BasicData/CommonEvent.dat").exists() {
        eprintln!("skipping: no data at {}", root.display());
        return None;
    }
    let mut game = Game::new(&root).expect("open game");
    game.start_engine_events();
    assert!(game.start_event(132), "CE132 should start");
    for _ in 0..180 {
        let _ = game.frame();
    }
    Some(game)
}

fn settings_quads() -> Option<Vec<(String, [f32; 4])>> {
    let game = settings_game()?;
    Some(
        game.text_quads()
            .into_iter()
            .map(|quad| (visible(&quad.text), quad.rect))
            .collect(),
    )
}

#[test]
fn every_settings_row_is_laid_out_at_its_own_shifted_position() {
    let Some(quads) = settings_quads() else {
        return;
    };
    for label in [
        "キー位置保存",
        "キーリピート速度",
        "ＢＧＭ音量",
        "ＳＥ音量",
        "決定キー",
        "キャンセル",
        "サブキー",
        "リセット",
        "設定完了",
    ] {
        assert!(
            quads.iter().any(|(text, _)| text.contains(label)),
            "missing settings label {label:?}; got {:?}",
            quads.iter().map(|(text, _)| text).collect::<Vec<_>>()
        );
    }
    // Every row must sit on a distinct y. If the 290 shift is ignored all ten stack at
    // the base coordinate and this set has one element.
    let mut ys: Vec<i32> = quads
        .iter()
        .filter(|(text, _)| text.contains("キー") || text.contains("音量"))
        .map(|(_, rect)| rect[1] as i32)
        .collect();
    ys.sort_unstable();
    ys.dedup();
    assert!(ys.len() >= 5, "rows stacked instead of shifted: {ys:?}");
    for (text, rect) in &quads {
        let [x, y, w, h] = *rect;
        assert!(
            x >= -1.0 && y >= -1.0 && x + w <= 1025.0 && y + h <= 577.0,
            "{text:?} is off the logical screen: {rect:?}"
        );
    }
}

#[test]
fn the_cursor_keeps_its_pixel_height_and_the_labels_keep_their_shift() {
    let Some(game) = settings_game() else {
        return;
    };
    let cursor = game
        .screen
        .get(12015)
        .expect("the CE95 settings cursor picture");
    let (_, height) = cursor.window.expect("cursor window size");
    assert_eq!(
        height, 24,
        "CE95 divides its tenths block once in the VM; the renderer must not scale it again"
    );

    let (_, shift_y) = game.screen.get(12053).expect("the BGM volume label").shift;
    assert!(
        shift_y > 0,
        "CE95 separates settings rows with Opcode 290 shifts, got {shift_y}"
    );
}

#[test]
fn the_help_text_keeps_the_shift_that_places_it_in_the_bottom_box() {
    let Some(quads) = settings_quads() else {
        return;
    };
    let help = quads
        .iter()
        .find(|(text, _)| text.contains("技能"))
        .expect("the 12004 help text should be on screen (0x400000 keeps its shift)");
    let [x, y, w, h] = help.1;
    assert!(
        y >= 470.0 && y + h <= 577.0,
        "help text not in bottom box: {help:?}"
    );
    assert!(
        x >= 0.0 && x + w <= 1025.0,
        "help text off screen horizontally: {help:?}"
    );
}
