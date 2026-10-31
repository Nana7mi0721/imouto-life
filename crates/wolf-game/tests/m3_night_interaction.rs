//! M3-Z: night interaction interface state machine.
//!
//! These tests exercise the real data-driven entry from the night command menu
//! (common event 245) into the deep-night interaction interface (common event
//! 230), the routing of its choice prompts, its on-screen element composition,
//! the parameter-variable writes it performs, and the alternate sleep-exit path.
//! All expectations are measured against work/Data; when the data root is
//! absent each test prints a skip line and returns so the suite exits 0.

use std::collections::BTreeSet;
use std::path::{Path, PathBuf};

use wolf_game::{key, Game};

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

fn save_path(root: &Path) -> PathBuf {
    root.join("Save").join("SaveData01.sav")
}

fn open_loaded() -> Option<Game> {
    let root = data_root();
    let mut game = match Game::new(root.clone()) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: cannot open data root {root:?}: {err}");
            return None;
        }
    };
    if let Err(err) = game.load_save(&save_path(&root)) {
        eprintln!("skipping: cannot load SaveData01: {err}");
        return None;
    }
    game.auto_advance = false;
    game.auto_choice = false;
    Some(game)
}

/// Strip WOLF text-control escape directives (font/colour/db/erase markers) so
/// the remaining glyphs can be compared.
fn visible(raw: &str) -> String {
    let mut out = String::new();
    let mut it = raw.chars().peekable();
    while let Some(c) = it.next() {
        if (c as u32) != 92 {
            out.push(c);
            continue;
        }
        while let Some(&ch) = it.peek() {
            if ch.is_ascii_alphanumeric() {
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

fn options(game: &Game) -> Vec<String> {
    game.choices
        .as_ref()
        .map(|c| c.options.iter().map(|s| s.trim_end().to_owned()).collect())
        .unwrap_or_default()
}

fn messages(game: &Game) -> Vec<String> {
    game.messages.iter().map(|m| visible(&m.text)).collect()
}

fn live_events(game: &Game) -> BTreeSet<u32> {
    game.vm.instances().iter().map(|i| i.event).collect()
}

fn choose(game: &mut Game, index: usize) {
    game.set_choice_cursor(index);
    game.key_bits = key::OK;
    game.frame();
    game.key_bits = 0;
}

fn walk(game: &mut Game, budget: usize, order: &mut Vec<String>) -> Option<Vec<String>> {
    for _ in 0..budget {
        game.frame();
        for m in messages(game) {
            if order.last() != Some(&m) {
                order.push(m);
            }
        }
        if game.choices.is_some() {
            return Some(options(game));
        }
        if !game.messages.is_empty() {
            game.key_bits = key::OK;
            game.frame();
            game.key_bits = 0;
        }
    }
    None
}

fn has_picture(game: &Game, number: i32) -> bool {
    game.screen.iter().any(|p| p.number == number)
}

fn picture_field(game: &Game, number: i32) -> Option<(String, String, i32, i32, i32)> {
    game.screen
        .iter()
        .find(|p| p.number == number)
        .map(|p| (p.file.clone(), p.text.clone(), p.x, p.y, p.scale))
}

fn pictures_in_range(game: &Game, lo: i32, hi: i32) -> usize {
    (lo..=hi).filter(|&n| has_picture(game, n)).count()
}

fn var(game: &Game, index: usize) -> i32 {
    game.vm.vars.get(index)
}

const STATUS_SLOTS: &[i32] = &[1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000];
// Core body layers always drawn by the interface (background, body, eyes,
// mouth and the pose icon area).
const BODY_CORE: &[i32] = &[950, 1000, 1001, 1002, 1003, 1109];
// Clothing layers; which subset shows depends on the current pose/state, so a
// run only guarantees at least one of them.
const BODY_CLOTHING: &[i32] = &[1014, 1015, 1016];

fn assert_status_bar(game: &Game) {
    for &n in STATUS_SLOTS {
        assert!(has_picture(game, n), "status slot picture {n} is missing");
    }
    let (_, good_text, ..) = picture_field(game, 1995).expect("GOOD label");
    assert!(
        visible(&good_text).contains("GOOD"),
        "1995 label = {good_text:?}"
    );
    let (_, bad_text, ..) = picture_field(game, 1999).expect("BAD label");
    assert!(
        visible(&bad_text).contains("BAD"),
        "1999 label = {bad_text:?}"
    );
    let (file, ..) = picture_field(game, 2000).expect("sleeping status picture");
    assert!(file.contains("sleeping_staus.png"), "2000 file = {file:?}");
}

fn assert_body_layers(game: &Game) {
    for &n in BODY_CORE {
        assert!(has_picture(game, n), "body layer picture {n} is missing");
    }
    let clothing = BODY_CLOTHING
        .iter()
        .filter(|&&n| has_picture(game, n))
        .count();
    assert!(clothing >= 1, "at least one clothing layer expected");
    assert_eq!(pictures_in_range(game, 2300, 2319), 20, "item list slots");
}

fn set_branch_prerequisites(game: &mut Game) {
    for (slot, value) in [
        (20usize, 200),
        (21, 200),
        (23, 1),
        (128, 20),
        (129, 2),
        (139, 20),
    ] {
        game.vm.vars.set(slot, value);
    }
}

#[test]
fn night_menu_reaches_the_interaction_interface_when_prerequisites_are_met() {
    let Some(mut game) = open_loaded() else {
        return;
    };
    set_branch_prerequisites(&mut game);
    game.start_event(245);

    let mut order = Vec::new();
    let menu = walk(&mut game, 120, &mut order).expect("night command menu");
    assert!(
        menu.iter().any(|o| o == "今天就这样睡吧"),
        "menu = {menu:?}"
    );

    choose(&mut game, 4);
    let confirm = walk(&mut game, 120, &mut order).expect("sleep confirm");
    assert_eq!(
        confirm,
        vec!["是".to_owned(), "否".to_owned()],
        "confirm = {confirm:?}"
    );

    choose(&mut game, 0);
    let deep_confirm = walk(&mut game, 200, &mut order).expect("deep confirm");
    assert_eq!(deep_confirm.len(), 2, "deep confirm = {deep_confirm:?}");
    choose(&mut game, 0);

    let mut tail = Vec::new();
    let _ = walk(&mut game, 200, &mut tail);
    for m in tail {
        if order.last() != Some(&m) {
            order.push(m);
        }
    }

    assert_status_bar(&game);
    assert_body_layers(&game);

    for needle in ["……哥、哥哥…", "…做吧？"] {
        assert!(
            order.iter().any(|m| m.contains(needle)),
            "message {needle:?} missing from {order:?}"
        );
    }
    assert!(
        order.iter().any(|m| m.contains("深夜模式全部由光标操作")),
        "interface notice missing from {order:?}"
    );

    // 2000100 is set to 1 unconditionally when the interface starts; this is a
    // semantic flag rather than a random draw, so it is stable.
    assert_eq!(var(&game, 100), 1, "2000100 (interface active flag)");
    assert_eq!(game.stats.warnings, 0, "warnings");
}

#[test]
fn night_menu_falls_back_to_the_sleep_exit_when_prerequisites_are_not_met() {
    let Some(mut game) = open_loaded() else {
        return;
    };
    game.start_event(245);

    let mut order = Vec::new();
    let menu = walk(&mut game, 120, &mut order).expect("night command menu");
    assert!(
        menu.iter().any(|o| o == "今天就这样睡吧"),
        "menu = {menu:?}"
    );

    choose(&mut game, 4);
    let confirm = walk(&mut game, 120, &mut order).expect("sleep confirm");
    assert_eq!(confirm, vec!["是".to_owned(), "否".to_owned()]);
    choose(&mut game, 0);

    let mut tail = Vec::new();
    let _ = walk(&mut game, 300, &mut tail);
    for m in tail {
        if order.last() != Some(&m) {
            order.push(m);
        }
    }

    let live = live_events(&game);
    assert!(
        live.contains(&251),
        "sleep event 251 not live, live = {live:?}"
    );
    assert!(
        !live.contains(&230),
        "interface 230 should not run, live = {live:?}"
    );
    assert_eq!(
        pictures_in_range(&game, 1992, 2000),
        0,
        "status bar should not be drawn"
    );
    assert_eq!(var(&game, 100), 0, "interface flag must stay clear");
    assert!(
        order.iter().any(|m| m.contains("晚安哥哥")),
        "sleep good-night line missing from {order:?}"
    );
    assert_eq!(game.stats.warnings, 0, "warnings");
}

#[test]
fn direct_interface_event_draws_layers_and_writes_parameters() {
    let Some(mut game) = open_loaded() else {
        return;
    };
    game.start_event(230);

    let mut order = Vec::new();
    let _ = walk(&mut game, 400, &mut order);

    assert!(
        order.iter().any(|m| m.contains("咽口水")),
        "opening line missing from {order:?}"
    );
    assert!(
        order.iter().any(|m| m.contains("深夜模式全部由光标操作")),
        "interface notice missing from {order:?}"
    );

    assert_status_bar(&game);
    assert_body_layers(&game);

    // The interface sets its active flag and a set of pose bookkeeping
    // variables; those pose values may depend on the random pose pick, so only
    // the unconditional active flag is pinned here.
    assert_eq!(var(&game, 100), 1, "2000100");
    assert_eq!(game.stats.warnings, 0, "warnings");
}

#[test]
fn status_bar_gradient_follows_the_parameter_variable() {
    if open_loaded().is_none() {
        return;
    }
    for desired in [0i32, 25, 50, 75, 100] {
        let Some(mut game) = open_loaded() else {
            return;
        };
        game.vm.vars.set(24, desired);
        game.start_event(237);
        for _ in 0..6 {
            game.frame();
        }
        assert_status_bar(&game);
        let (_, _, _, _, good_scale) = picture_field(&game, 1993).expect("GOOD gradient");
        assert_eq!(
            good_scale, desired,
            "GOOD gradient scale should track var24={desired}"
        );
        assert!(has_picture(&game, 1997), "BAD gradient slot 1997 missing");
        assert_eq!(game.stats.warnings, 0, "warnings");
    }
}

#[test]
fn breath_pose_components_draw_their_backgrounds() {
    for (event_id, expected) in [
        (225u32, "scene0102_bless02.png"),
        (226, "scene0102_bless01.png"),
    ] {
        let Some(mut game) = open_loaded() else {
            return;
        };
        game.start_event(event_id);
        for _ in 0..10 {
            game.frame();
        }
        let hit = game
            .screen
            .iter()
            .find(|p| p.file.contains(expected))
            .map(|p| (p.number, p.file.clone()))
            .unwrap_or_else(|| panic!("event {event_id} did not draw {expected}"));
        assert!(
            hit.0 >= 1000,
            "unexpected picture number for {expected}: {hit:?}"
        );
        assert_eq!(game.stats.warnings, 0, "warnings for event {event_id}");
    }
}

#[test]
fn interaction_run_leaves_the_save_file_untouched() {
    let Some(mut game) = open_loaded() else {
        return;
    };
    let root = data_root();
    let before = std::fs::read(save_path(&root)).expect("read save before");
    set_branch_prerequisites(&mut game);
    game.auto_advance = true;
    game.start_event(245);
    for _ in 0..40 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }
    for index in [4usize, 0, 0] {
        if game.choices.is_some() {
            choose(&mut game, index);
        }
        for _ in 0..80 {
            game.frame();
            if game.choices.is_some() {
                break;
            }
        }
    }
    for _ in 0..120 {
        game.frame();
    }
    let after = std::fs::read(save_path(&root)).expect("read save after");
    assert_eq!(
        before, after,
        "SaveData01 must not be modified by an interaction run"
    );
}
