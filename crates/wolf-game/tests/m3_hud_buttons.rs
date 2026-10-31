//! M3-AL HUD picture-button click routing (task-42).
//!
//! The bedroom HUD exposes four point-and-click entries. Two are real picture
//! slots drawn by map events:
//!   * save/menu icon  -5 / Picture/icon01.png at (10, 510), map event 6;
//!     its trigger rectangle is sample-map event 5, tile (2,33) 3x3 -> (32,528) 64x64.
//!   * data icon       -4 / Picture/icon05.png at (925, 507), map event 32;
//!     its trigger rectangle is sample-map event 30, tile (61,33) 3x3 -> (976,528) 64x64.
//!
//! The other two are invisible trigger rectangles on the left screen edge, not
//! picture slots: item list event 7, tile (0,18) 2x5 -> (0,288) 48x96; status
//! event 10, tile (0,9) 2x5 -> (0,144) 48x96. They open the offscreen panels
//! 2300 (itemlist.png) and 320 (status01.png), both parked at x=-305.
//!
//! The panels are interactive because map events 8 and 11 poll opcode 124
//! picture field 8 (hover): while the pointer is inside the opened panel the
//! panel stays at x=0; moving away one frame later calls CE239/CE238 with
//! argument 0 and parks it at x=-305 again. (The open x is 0, not 305, because
//! op150 head bit 0x10000 makes the slide-in relative: -305 + 305 = 0.) That exercises the engine mouse
//! state path (engine_state fields 7/20/21 and picture_state field 8), so a
//! missing mouse-to-opcode124 bridge is not a source gap.
//!
//! The status entry is dormant in the shipped save: event 10 is gated by
//! variable 15 == 99, and no shipped script writes 99 (the normal save has
//! v15=0). Forcing v15=99 proves the CE238 panel itself works, so this is a
//! data-side gate, not a missing engine feature. Item list has no such gate.
//!
//! No test writes a save file; the save click test hashes Save/* before and
//! after and requires byte equality.

use std::path::{Path, PathBuf};

use wolf_game::Game;

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let p = PathBuf::from(raw);
    if p.is_absolute() {
        return p;
    }
    let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    base.pop();
    base.pop();
    base.join(p)
}

/// Strip WOLF text escapes: a backslash starts an alphabetic command name and
/// an optional [..] argument. Kept as char-code 92 so the source never contains
/// a literal backslash in a JSON-hostile position.
fn visible(raw: &str) -> String {
    let mut out = String::new();
    let mut it = raw.chars().peekable();
    while let Some(c) = it.next() {
        if (c as u32) != 92 {
            out.push(c);
            continue;
        }
        while let Some(&ch) = it.peek() {
            if ch.is_ascii_alphabetic() {
                it.next();
            } else {
                break;
            }
        }
        if it.peek() == Some(&'[') {
            for ch in it.by_ref() {
                if ch == ']' {
                    break;
                }
            }
        }
    }
    out
}

/// Boot through the title and choose the load entry, reaching the bedroom HUD.
/// Loading the save directly would leave MapRuntime with zero events, so the
/// point-and-click trigger-0 pages would not be collected.
fn load_bedroom() -> Option<Game> {
    if !data_root().join("Save/SaveData01.sav").is_file() {
        eprintln!("skipping: no SaveData01 under {}", data_root().display());
        return None;
    }
    let mut game = Game::new(data_root()).ok()?;
    game.auto_advance = true;
    game.set_choice_cursor(1); // title menu menu2 = load
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    if game.boot().is_err() {
        eprintln!("skipping: boot failed");
        return None;
    }
    for _ in 0..1600 {
        game.frame();
    }
    if !game
        .screen
        .iter()
        .any(|p| visible(&p.text).contains("行动力"))
    {
        eprintln!("skipping: bedroom HUD not reached");
        return None;
    }
    Some(game)
}

fn slot_text(game: &Game, slot: i32) -> String {
    game.screen
        .get(slot)
        .map(|p| visible(&p.text))
        .unwrap_or_default()
}

fn slot_file(game: &Game, slot: i32) -> String {
    game.screen
        .get(slot)
        .map(|p| p.file.clone())
        .unwrap_or_default()
}

fn slot_x(game: &Game, slot: i32) -> Option<i32> {
    game.screen.get(slot).map(|p| p.x)
}

fn running_event(game: &Game, id: u32) -> bool {
    game.vm.instances().iter().any(|i| i.event == id)
}

fn settle_pointer(game: &mut Game, x: i32, y: i32) {
    game.mouse = [x, y];
    for _ in 0..4 {
        game.frame();
    }
}

/// Left button held for 24 frames, then released for 6, as required by task-42.
fn hold_and_release(game: &mut Game) {
    game.mouse_buttons = 1;
    for _ in 0..24 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..6 {
        game.frame();
    }
}

fn save_snapshot() -> Vec<(PathBuf, Vec<u8>)> {
    fn walk(dir: &Path, files: &mut Vec<PathBuf>) {
        let Ok(entries) = std::fs::read_dir(dir) else {
            return;
        };
        for entry in entries.flatten() {
            let path = entry.path();
            if path.is_dir() {
                walk(&path, files);
            } else {
                files.push(path);
            }
        }
    }
    let mut files = Vec::new();
    walk(&data_root().join("Save"), &mut files);
    files.sort();
    files
        .into_iter()
        .map(|path| {
            let bytes = std::fs::read(&path).unwrap_or_default();
            (path, bytes)
        })
        .collect()
}

#[test]
fn hud_shows_two_visible_icon_buttons_and_two_parked_panels() {
    let Some(game) = load_bedroom() else {
        return;
    };
    // Stable HUD text confirms the bedroom, not the title or a menu.
    assert!(game
        .screen
        .iter()
        .any(|p| visible(&p.text).contains("行动力")));
    assert!(slot_text(&game, 230).contains("行动力"));
    assert!(!slot_text(&game, 200).is_empty());
    assert!(slot_text(&game, 210).contains('周'));

    // The two real picture buttons live in the bottom corners.
    assert_eq!(slot_file(&game, -5), "Picture/icon01.png");
    assert_eq!(slot_x(&game, -5), Some(10));
    assert_eq!(game.screen.get(-5).map(|p| p.y), Some(510));
    assert_eq!(slot_file(&game, -4), "Picture/icon05.png");
    assert_eq!(slot_x(&game, -4), Some(925));
    assert_eq!(game.screen.get(-4).map(|p| p.y), Some(507));

    // Panels exist but are parked off the left edge until their event slides
    // them in (relative +305 from -305 lands at x=0).
    assert_eq!(slot_file(&game, 320), "Picture/status01.png");
    assert_eq!(slot_x(&game, 320), Some(-305));
    assert_eq!(slot_file(&game, 2300), "Picture/itemlist.png");
    assert_eq!(slot_x(&game, 2300), Some(-305));

    // Gates read by sample-map events 7/10/30; the shipped save has all zero,
    // so the status entry is dormant while save/item/data are live.
    assert_eq!(game.vm.vars.get(15), 0);
    assert_eq!(game.vm.vars.get(100), 0);
    assert_eq!(game.vm.vars.get(176), 0);
    assert_eq!(game.vm.vars.get(238), 0);
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn save_icon_left_click_routes_to_save_menu_without_writing_a_save() {
    let before = save_snapshot();
    let Some(mut game) = load_bedroom() else {
        return;
    };
    settle_pointer(&mut game, 50, 540);
    hold_and_release(&mut game);
    for _ in 0..30 {
        game.frame();
    }

    assert_eq!(
        game.last_action_event,
        Some(5),
        "save icon must start map event 5"
    );
    assert!(
        running_event(&game, 14),
        "event 5 must call CE14 menu dispatcher"
    );
    assert!(
        running_event(&game, 131),
        "CE14 must reach CE131 save/load panel"
    );
    assert!(slot_text(&game, 12002).contains("选择要保存的数据。"));
    assert_eq!(slot_text(&game, 12052), "1");
    assert_eq!(game.stats.warnings, 0);
    assert_eq!(
        before,
        save_snapshot(),
        "clicking the save icon must not write Save/*"
    );
}

#[test]
fn data_icon_left_click_opens_the_play_tendency_panel() {
    let Some(mut game) = load_bedroom() else {
        return;
    };
    settle_pointer(&mut game, 1000, 550);
    game.mouse_buttons = 1;
    game.frame(); // the action page starts on the press edge

    assert_eq!(
        game.last_action_event,
        Some(30),
        "data icon must start map event 30"
    );
    assert_eq!(
        game.vm.vars.get(176),
        1,
        "event 30 raises the stats-shown flag"
    );
    assert!(slot_text(&game, 400).contains("两人以妹妹升学为契机"));
    assert!(slot_text(&game, 401).contains("两个人的生活才刚刚开始"));
    assert!(slot_text(&game, 412).contains("妹妹好像"));
    assert!(slot_text(&game, 413).contains("妹妹似乎"));
    assert_eq!(game.stats.warnings, 0);

    // Finish the required long press/release; the event has already delivered
    // its one-shot overlay, so only the trigger identity is checked afterwards.
    for _ in 0..23 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..6 {
        game.frame();
    }
    for _ in 0..30 {
        game.frame();
    }
    assert_eq!(game.last_action_event, Some(30));
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn item_strip_left_click_opens_item_list_and_hover_keeps_it_open() {
    let Some(mut game) = load_bedroom() else {
        return;
    };
    assert_eq!(slot_x(&game, 2300), Some(-305));

    // Click the invisible left-edge trigger, then slide the pointer into the
    // opened panel while still holding. Event 8 polls picture 2300 field 8 and
    // sees hover=1, so the panel remains open at x=0.
    settle_pointer(&mut game, 24, 336);
    game.mouse_buttons = 1;
    game.frame();
    assert_eq!(
        game.last_action_event,
        Some(7),
        "item strip must start map event 7"
    );
    assert!(
        running_event(&game, 239),
        "event 7 must call CE239 item list"
    );

    game.mouse = [100, 336];
    for _ in 0..20 {
        game.frame();
    }
    assert_eq!(slot_x(&game, 2300), Some(0));
    assert_eq!(slot_file(&game, 2300), "Picture/itemlist.png");
    for slot in 2301..=2319 {
        assert!(
            game.screen.get(slot).is_some(),
            "CE239 layer {slot} is missing"
        );
    }
    assert_eq!(game.stats.warnings, 0);

    // Moving the pointer off the panel is seen by the same opcode 124 poll and
    // event 8 parks the list again on the next frame.
    game.mouse = [800, 336];
    for _ in 0..3 {
        game.frame();
    }
    assert_eq!(slot_x(&game, 2300), Some(-305));
    game.mouse_buttons = 0;
    for _ in 0..5 {
        game.frame();
    }
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn status_strip_is_dormant_in_the_shipped_save() {
    let Some(mut game) = load_bedroom() else {
        return;
    };
    assert_eq!(game.vm.vars.get(15), 0);
    settle_pointer(&mut game, 24, 192);
    hold_and_release(&mut game);
    for _ in 0..30 {
        game.frame();
    }
    // Event 10 requires v15 == 99, which no shipped script writes; the click
    // therefore finds no page and the panel stays parked.
    assert_eq!(game.last_action_event, None);
    assert_eq!(slot_x(&game, 320), Some(-305));
    assert!(!running_event(&game, 10));
    assert!(!running_event(&game, 238));
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn status_panel_opens_and_tracks_hover_once_the_gate_is_forced() {
    let Some(mut game) = load_bedroom() else {
        return;
    };
    game.vm.vars.set(15, 99);
    for _ in 0..2 {
        game.frame();
    }

    settle_pointer(&mut game, 24, 192);
    game.mouse_buttons = 1;
    game.frame();
    assert_eq!(
        game.last_action_event,
        Some(10),
        "status strip must start map event 10"
    );
    assert_eq!(slot_x(&game, 320), Some(0));
    assert_eq!(slot_file(&game, 320), "Picture/status01.png");

    game.mouse = [100, 192];
    for _ in 0..20 {
        game.frame();
    }
    assert_eq!(slot_x(&game, 320), Some(0));
    assert!(slot_text(&game, 321).contains("25"));
    assert!(slot_text(&game, 323).contains("普通"));
    assert!(slot_text(&game, 324).contains("普通"));
    assert_eq!(game.stats.warnings, 0);

    // Same opcode 124 field 8 poll as the item list: leaving the rectangle makes
    // event 11 call CE238 with argument 0 and park the panel at x=-305.
    game.mouse = [600, 192];
    for _ in 0..3 {
        game.frame();
    }
    assert_eq!(slot_x(&game, 320), Some(-305));
    game.mouse_buttons = 0;
    for _ in 0..5 {
        game.frame();
    }
    assert_eq!(game.stats.warnings, 0);
}
