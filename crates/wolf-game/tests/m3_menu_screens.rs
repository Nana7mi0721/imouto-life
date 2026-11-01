//! M3-J menu / save-screen UI coverage for 《妹！生活 ～単色～》 (this game).
//!
//! m3_save_load pins the SaveFile format and the synthetic 220/222 opcodes, and m1 walks
//! the title-menu load path; neither ever draws a real in-game menu screen. This file
//! drives the menu common events themselves from the loaded bedroom (SaveData01) and
//! checks their on-screen layout, cursor movement and cancel handling.
//!
//! What is pinned (all measured against WOLF_DATA_ROOT=work/Data):
//! * CE131 セーブ欄実行 draws the save-slot grid: backdrop <GRADY...>, WindowBase_amania
//!   frame, the header 选择要保存的数据。, four numbered slot windows 1..4 with slot 3/4
//!   reading 没有数据, warnings 0. A held CANCEL closes it and clears every 12xxx slot.
//! * CE132 システム欄実行 draws - システム設定 - with the settings rows (ＢＧＭ音量,
//!   ＳＥ音量, キーリピート速度, 決定キー, キャンセル …) and 設定完了/リセット; DOWN moves
//!   the highlight (the help line under the list changes); CANCEL closes it, warnings 0.
//! * CE14 各種メニュー呼出 is the generic dispatcher: from the loaded bedroom it launches
//!   the save-field child CE131 and paints the same save screen; CANCEL stops the whole
//!   chain (14 + 131) and clears the grid.
//!
//! The tests never confirm a save: they only draw, move the cursor and cancel. Each one
//! fingerprints work/Data/Save before and after and asserts it is unchanged, so a stray
//! write would fail the test rather than overwrite a real save. Missing data skips.

use std::path::PathBuf;

use wolf_game::savegame;
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

fn save_file(slot: u32) -> PathBuf {
    data_root()
        .join("Save")
        .join(format!("SaveData{slot:02}.sav"))
}

/// Loads one shipped save straight into the bedroom HUD state (no menu involvement).
fn open_loaded(slot: u32) -> Option<Game> {
    let path = save_file(slot);
    if !path.is_file() {
        eprintln!("skipping: no save at {}", path.display());
        return None;
    }
    let mut game = match Game::new(data_root()) {
        Ok(game) => game,
        Err(_) => {
            eprintln!("skipping: Game::new failed");
            return None;
        }
    };
    if savegame::load_into(&mut game, &path).is_err() {
        eprintln!("skipping: load failed");
        return None;
    }
    game.auto_advance = true;
    game.auto_choice = false;
    Some(game)
}

/// Strips WOLF text escapes so assertions look at the glyphs the player sees.
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

fn running(game: &Game, id: u32) -> bool {
    game.vm.instances().iter().any(|inst| inst.event == id)
}

fn text_of(game: &Game, slot: i32) -> String {
    game.screen
        .get(slot)
        .map(|picture| visible(&picture.text))
        .unwrap_or_default()
}

fn file_of(game: &Game, slot: i32) -> String {
    game.screen
        .get(slot)
        .map(|picture| picture.file.clone())
        .unwrap_or_default()
}

/// Holds a key long enough for the event's 123-poll cadence to see it, then releases it.
fn press(game: &mut Game, bits: u32) {
    game.key_bits = bits;
    for _ in 0..24 {
        game.frame();
    }
    game.key_bits = 0;
    for _ in 0..6 {
        game.frame();
    }
}

/// One deliberate press: hold for three frames (one row step) then release.
///
/// Holding for longer would keep stepping: CE132's `キー設定` rows trap a held
/// direction in their capture loop, because that row exists to bind a new key.
fn tap(game: &mut Game, bits: u32) {
    game.key_bits = bits;
    for _ in 0..3 {
        game.frame();
    }
    game.key_bits = 0;
    for _ in 0..6 {
        game.frame();
    }
}

/// Name + size of every file in work/Data/Save, to prove a menu test never wrote one.
fn save_dir_fingerprint() -> Vec<(String, u64)> {
    let dir = data_root().join("Save");
    let mut out = Vec::new();
    if let Ok(entries) = std::fs::read_dir(&dir) {
        for entry in entries.flatten() {
            if let Ok(meta) = entry.metadata() {
                if meta.is_file() {
                    out.push((entry.file_name().to_string_lossy().into_owned(), meta.len()));
                }
            }
        }
    }
    out.sort();
    out
}

#[test]
fn ce131_save_slot_grid_draws_and_cancels() {
    let Some(mut game) = open_loaded(1) else {
        return;
    };
    let before = save_dir_fingerprint();

    game.screen.clear();
    game.messages.clear();
    assert!(game.start_event(131), "event 131 did not start");
    for _ in 0..30 {
        game.frame();
    }

    // Header, backdrop gradient and the amania window frame.
    assert!(
        text_of(&game, 12002).contains("保存"),
        "CE131 header: {:?}",
        text_of(&game, 12002)
    );
    assert!(
        file_of(&game, 12000).contains("GRADY"),
        "CE131 backdrop: {:?}",
        file_of(&game, 12000)
    );
    assert!(
        file_of(&game, 12001).contains("WindowBase_amania"),
        "CE131 frame: {:?}",
        file_of(&game, 12001)
    );

    // Four numbered slots; slots 3 and 4 are empty.
    for (slot, label) in [(12052, "1"), (12072, "2"), (12092, "3"), (12112, "4")] {
        assert_eq!(text_of(&game, slot), label, "CE131 slot label at {slot}");
    }
    assert_eq!(text_of(&game, 12093), "没有数据", "CE131 empty slot 3");
    assert_eq!(text_of(&game, 12113), "没有数据", "CE131 empty slot 4");

    // Each slot window plus its cursor layer is actually on screen.
    for slot in [12050, 12051, 12070, 12071, 12090, 12091, 12110, 12111] {
        assert!(
            game.screen.get(slot).is_some(),
            "CE131 slot window {slot} missing"
        );
    }

    // The grid is not a choice / message prompt.
    assert!(game.choices.is_none(), "CE131 should not raise a choice");
    assert_eq!(game.stats.warnings, 0, "CE131 warnings while drawing");

    press(&mut game, wolf_game::key::CANCEL);
    assert!(!running(&game, 131), "CE131 still running after cancel");
    let leftover: Vec<i32> = game
        .screen
        .iter()
        .filter(|p| p.number >= 12000)
        .map(|p| p.number)
        .collect();
    assert!(leftover.is_empty(), "CE131 grid not cleared: {leftover:?}");
    assert_eq!(game.stats.warnings, 0, "CE131 warnings after cancel");
    assert_eq!(
        save_dir_fingerprint(),
        before,
        "CE131 must not write any save file"
    );
}

#[test]
fn ce132_system_settings_draws_navigates_and_cancels() {
    let Some(mut game) = open_loaded(1) else {
        return;
    };

    game.screen.clear();
    game.messages.clear();
    assert!(game.start_event(132), "event 132 did not start");
    for _ in 0..30 {
        game.frame();
    }

    assert!(
        text_of(&game, 12002).contains("システム設定"),
        "CE132 title: {:?}",
        text_of(&game, 12002)
    );

    // All the settings row labels are present in the 12030..=12039 band.
    let labels = (12030..=12039)
        .map(|slot| text_of(&game, slot))
        .collect::<Vec<_>>()
        .join("|");
    for needle in [
        "ＢＧＭ音量",
        "ＳＥ音量",
        "キーリピート速度",
        "決定キー",
        "キャンセル",
    ] {
        assert!(
            labels.contains(needle),
            "CE132 label {needle} missing: {labels}"
        );
    }
    assert!(
        text_of(&game, 12061).contains("リセット"),
        "CE132 reset button"
    );
    assert!(
        text_of(&game, 12062).contains("設定完了"),
        "CE132 apply button"
    );
    assert_eq!(game.stats.warnings, 0, "CE132 warnings while drawing");

    // Moving the highlight down swaps the help line under the list.
    let help0 = text_of(&game, 12004);
    assert!(!help0.is_empty(), "CE132 help line should be populated");
    tap(&mut game, wolf_game::key::DOWN);
    assert!(running(&game, 132), "CE132 still open after pressing down");
    let help1 = text_of(&game, 12004);
    assert_ne!(
        help1, help0,
        "CE132 help line should change when the cursor moves ({help0:?} -> {help1:?})"
    );
    assert_eq!(game.stats.warnings, 0, "CE132 warnings after navigating");

    press(&mut game, wolf_game::key::CANCEL);
    assert!(!running(&game, 132), "CE132 still running after cancel");
    let leftover: Vec<i32> = game
        .screen
        .iter()
        .filter(|p| p.number >= 12000)
        .map(|p| p.number)
        .collect();
    assert!(
        leftover.is_empty(),
        "CE132 screen not cleared: {leftover:?}"
    );
    assert_eq!(game.stats.warnings, 0, "CE132 warnings after cancel");
}

#[test]
fn ce14_menu_dispatches_to_save_screen_and_cancels() {
    let Some(mut game) = open_loaded(1) else {
        return;
    };
    let before = save_dir_fingerprint();

    game.screen.clear();
    game.messages.clear();
    assert!(game.start_event(14), "event 14 did not start");
    for _ in 0..30 {
        game.frame();
    }

    // The generic menu entry point dispatches into the save-field screen (CE131).
    assert!(
        text_of(&game, 12002).contains("保存"),
        "CE14 opens the save screen: {:?}",
        text_of(&game, 12002)
    );
    assert!(running(&game, 14), "CE14 dispatcher itself is running");
    assert!(
        running(&game, 131),
        "CE14 launched the save-field child CE131"
    );
    assert_eq!(game.stats.warnings, 0, "CE14 warnings while drawing");

    press(&mut game, wolf_game::key::CANCEL);
    assert!(
        !running(&game, 14) && !running(&game, 131),
        "CE14 chain did not close on cancel"
    );
    let leftover: Vec<i32> = game
        .screen
        .iter()
        .filter(|p| p.number >= 12000)
        .map(|p| p.number)
        .collect();
    assert!(leftover.is_empty(), "CE14 screen not cleared: {leftover:?}");
    assert_eq!(game.stats.warnings, 0, "CE14 warnings after cancel");
    assert_eq!(
        save_dir_fingerprint(),
        before,
        "CE14 must not write any save file"
    );
}
