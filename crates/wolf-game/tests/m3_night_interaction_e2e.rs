//! M3 night close-interaction end-to-end slice (manual04).
//!
//! The deep-night interface is a picture-button state machine driven by the map's
//! parallel events (SampleMapA ev15 コマンドリスト表示 / ev16 コマンド選択判定 /
//! ev17 コマンド実行 / ev18 カーソル切り替え / ev26 アイテムクリック監視), keyed on
//! normal variable 100 (2000100, the interface page). `load_save` restores the
//! bedroom but does not start the map pages, so these tests start the UI pages
//! explicitly with `Game::start_pages`, then start CE230 (深夜1) exactly like the
//! game's own sleep path does.
//!
//! Pinned here (all measured against work/Data, all warning-free):
//!
//! * the interface composition: GOOD/BAD status bar, body layers, the twenty item
//!   slots, the pose area and the right-hand command buttons + end button;
//! * the command state machine: clicking picture 400 moves the interface page
//!   var100 1 -> 3 and swaps in the submenu (pictures 390/415); clicking 390 moves
//!   it to page 10 with the command slots 2/3/4; clicking 430 runs the undress
//!   action (message + sleep depth down by one) and returns to page 1;
//! * body-part hit boxes: clicking the head box (1100) pats the sleeping sister
//!   (head-pat message and sleep depth up), while
//!   clicking the face box (1101; the mouth box is 1102) is refused with the
//!   deep-sleep line;
//! * the BAD bar: CE237's 1997 gradient scale and variable 59 both equal
//!   `v64 * 100 / 18` (the shipped script normalises 嫌悪感 by 18), and GOOD's
//!   1993 scale tracks v24;
//! * 射精感 (v66): ev20 page 0 forces phase v125 = 1 exactly when v66 >= 120,
//!   and ev17 page 5 (「例外処理 強制射精」) then plays the forced-ejaculation
//!   line, resets v66 to 0 and increments v180 (射精回数). 100 and 119 do not
//!   force: 100 is only the "may ejaculate" threshold used by the text/effect
//!   scripts, not an automatic end;
//! * the end script: `要结束动作吗？` is map event 21, a **trigger-0 (action key)**
//!   page with conditions v100 == 1 and v125 != 1. Started directly it offers
//!   是/否, and 是 ends the interface (v100 -> 0) with the closing line
//!   「…暴露了的话就惨了…就做到这样吧…」.
//!
//! Known engine gap behind the end button (reported, not worked around in src):
//! clicking picture 1108 (endbutton.png) does NOT run ev21. The shipped ev18
//! branch for that hit box only writes `v121 = 0` and a `103` comment
//! (“处理结束”); v121 (2000121) has no reader in any of the 350 common events
//! or in the SampleMapA interface events ev15–26 (both scanned), so the button is
//! data-inert. The real exit page ev21 is trigger 0, and map_runtime only
//! auto-starts Autorun/Parallel pages (`Trigger::ActionKey`/`PlayerTouch` stay
//! dormant, map_runtime.rs), so no action-key or click path can activate it.
//! Only a player/action-key activation layer (or an explicit click-to-action-key
//! bridge) would.
//!
//! Data-missing runs print a skip line and return, so the default suite keeps
//! exiting 0.

use std::collections::BTreeSet;
use std::path::{Path, PathBuf};

use wolf_format::mps::Map;
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

/// The map's night-interface pages only: ev15/16/17/18/19/20/23/26. The story
/// events (ev0/1/4) are left out so they cannot answer prompts for us.
fn ui_map() -> Option<Map> {
    let bytes = std::fs::read(data_root().join("MapData").join("SampleMapA.mps")).ok()?;
    let mut map = Map::parse(&bytes).ok()?;
    map.events
        .retain(|event| matches!(event.id, 15 | 16 | 17 | 18 | 19 | 20 | 23 | 26));
    Some(map)
}

/// Strip WOLF text-control escapes so only the glyphs remain.
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

fn live_events(game: &Game) -> BTreeSet<u32> {
    game.vm.instances().iter().map(|i| i.event).collect()
}

fn var(game: &Game, index: usize) -> i32 {
    game.vm.vars.get(index)
}

fn has_picture(game: &Game, number: i32) -> bool {
    game.screen.get(number).is_some()
}

fn picture_file(game: &Game, number: i32) -> Option<String> {
    game.screen.get(number).map(|p| p.file.clone())
}

/// Advances one frame and returns the visible messages that appeared, pressing
/// OK for any message currently waiting so the intro script keeps moving.
fn step_collect(game: &mut Game, seen: &mut Vec<String>) {
    game.frame();
    let now: Vec<String> = game.messages.iter().map(|m| visible(&m.text)).collect();
    for text in now.iter() {
        if !text.is_empty() && !seen.contains(text) {
            seen.push(text.clone());
        }
    }
    if !game.messages.is_empty() {
        game.key_bits = key::OK;
        game.frame();
        game.key_bits = 0;
    }
}

/// Opens the interface through its own entry point after starting the map pages.
/// CE230 is the deep-night initialiser the real sleep path calls; it sets the
/// page flag var100 = 1 and draws the status/body/item layers.
fn enter_interface() -> Option<Game> {
    let mut game = open_loaded()?;
    let map = ui_map()?;
    game.start_pages(&map, None);
    game.vm.vars.set(100, 1);
    game.start_event(230);
    let mut seen = Vec::new();
    for _ in 0..260 {
        step_collect(&mut game, &mut seen);
    }
    Some(game)
}

/// Real left click: move onto the button (hover is polled by op124), hold the
/// button for a few frames so the per-frame poll cannot miss the edge, release.
/// Returns false when the picture is not on screen.
fn click_picture(game: &mut Game, number: i32) -> bool {
    let Some(picture) = game.screen.get(number) else {
        return false;
    };
    let (x, y) = (picture.x + 30, picture.y + 30);
    game.mouse = [x, y];
    game.frame();
    game.mouse_buttons = 1;
    for _ in 0..6 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..6 {
        game.frame();
    }
    true
}

/// Same click, but collects messages while the action plays out.
fn click_picture_collecting(game: &mut Game, number: i32, frames: usize) -> Vec<String> {
    let mut seen = Vec::new();
    if !click_picture(game, number) {
        return seen;
    }
    for _ in 0..frames {
        step_collect(game, &mut seen);
    }
    seen
}

fn assert_status_bar(game: &Game) {
    for number in 1992..=2000 {
        assert!(has_picture(game, number), "status slot {number} is missing");
    }
    let good = game
        .screen
        .get(1995)
        .map(|p| visible(&p.text))
        .unwrap_or_default();
    let bad = game
        .screen
        .get(1999)
        .map(|p| visible(&p.text))
        .unwrap_or_default();
    assert!(good.contains("GOOD"), "1995 label = {good:?}");
    assert!(bad.contains("BAD"), "1999 label = {bad:?}");
    let sleeping = picture_file(game, 2000).unwrap_or_default();
    assert!(
        sleeping.contains("sleeping_staus.png"),
        "2000 file = {sleeping:?}"
    );
}

fn assert_body_layers(game: &Game) {
    for number in [950, 1000, 1001, 1002, 1003, 1109] {
        assert!(has_picture(game, number), "body layer {number} is missing");
    }
    let clothing = [1014, 1015, 1016]
        .iter()
        .filter(|&&n| has_picture(game, n))
        .count();
    assert!(clothing >= 1, "at least one clothing layer expected");
    let slots = (2300..=2319).filter(|&n| has_picture(game, n)).count();
    assert_eq!(slots, 20, "item list slots");
}

#[test]
fn interface_composition_and_command_state_machine() {
    let Some(mut game) = enter_interface() else {
        return;
    };
    let live = live_events(&game);
    assert!(
        live.contains(&15),
        "command list page ev15 runs, live = {live:?}"
    );
    assert!(
        live.contains(&16),
        "command judge ev16 runs, live = {live:?}"
    );
    assert!(
        live.contains(&18),
        "body hit test ev18 runs, live = {live:?}"
    );
    assert_status_bar(&game);
    assert_body_layers(&game);

    // The right-hand command buttons and the end button are on screen.
    assert_eq!(
        picture_file(&game, 400).as_deref(),
        Some("Picture/menu1_03.png")
    );
    assert_eq!(
        picture_file(&game, 404).as_deref(),
        Some("Picture/menu1_03.png")
    );
    assert_eq!(
        picture_file(&game, 1108).as_deref(),
        Some("Picture/endbutton.png")
    );
    assert_eq!(
        picture_file(&game, 1110).as_deref(),
        Some("Picture/pose_icon01.png")
    );

    // Page 1: clicking button 400 opens the hand submenu (page 3).
    assert_eq!(var(&game, 100), 1, "interface starts on page 1");
    assert!(click_picture(&mut game, 400), "button 400 is on screen");
    for _ in 0..10 {
        game.frame();
    }
    assert_eq!(
        var(&game, 100),
        3,
        "button 400 moves the interface to page 3"
    );
    assert_eq!(
        picture_file(&game, 390).as_deref(),
        Some("Picture/menu1_04.png"),
        "submenu button 390 replaces the row"
    );
    assert_eq!(
        picture_file(&game, 415).as_deref(),
        Some("Picture/menu2_12.png"),
        "submenu adds button 415"
    );

    // Page 3 -> page 10 through the submenu button.
    assert!(
        click_picture(&mut game, 390),
        "submenu button 390 is on screen"
    );
    for _ in 0..10 {
        game.frame();
    }
    assert_eq!(var(&game, 100), 10, "button 390 selects command page 10");
    assert_eq!(
        (var(&game, 104), var(&game, 105), var(&game, 106)),
        (2, 3, 4),
        "command slots 104/105/106"
    );

    // Page 10: the undress action runs, lowers sleep depth and returns to page 1.
    let depth_before = var(&game, 18);
    let messages = click_picture_collecting(&mut game, 430, 90);
    assert_eq!(var(&game, 100), 1, "the action returns to page 1");
    assert!(
        var(&game, 18) < depth_before,
        "undressing lowers sleep depth: {depth_before} -> {}",
        var(&game, 18)
    );
    assert!(
        messages.iter().any(|m| m.contains("一点一点地脱掉")),
        "undress message missing from {messages:?}"
    );
    assert_eq!(game.stats.warnings, 0, "warnings");
}

#[test]
fn patting_the_head_plays_the_cut_in_and_deepens_sleep() {
    let Some(mut game) = enter_interface() else {
        return;
    };
    assert_eq!(
        var(&game, 66),
        0,
        "射精感 starts at zero at the interface entry"
    );
    let depth_before = var(&game, 18);
    assert_eq!(
        depth_before,
        var(&game, 19),
        "sleep depth starts at its maximum"
    );

    // Picture 1100 is the head hit box at the top of the sleeping sister.
    assert!(has_picture(&game, 1100), "head hit box 1100 is on screen");
    let messages = click_picture_collecting(&mut game, 1100, 40);

    assert!(
        messages
            .iter()
            .any(|m| m.contains("轻轻抚摸着熟睡着的妹妹的头")),
        "head-pat message missing from {messages:?}"
    );
    assert!(
        messages.iter().any(|m| m.contains("呼")),
        "sleeping breath line missing from {messages:?}"
    );
    assert!(
        var(&game, 18) > depth_before,
        "patting deepens sleep: {depth_before} -> {}",
        var(&game, 18)
    );
    // Pictures 16000/16001 came from CE264's old misrouted template call, not
    // from the head-pat cut-in itself (report BUG-12/19); the sleep-depth change
    // and the dialogue above are the observable cut-in effects.
    assert_eq!(game.stats.warnings, 0, "warnings");
}

#[test]
fn deep_sleep_refuses_the_face_action() {
    let Some(mut game) = enter_interface() else {
        return;
    };
    let depth_before = var(&game, 18);
    // ev19 labels picture 1101 「かお」 (face); the mouth box is 1102.
    assert!(has_picture(&game, 1101), "face hit box 1101 is on screen");

    let messages = click_picture_collecting(&mut game, 1101, 40);

    assert!(
        messages.iter().any(|m| m.contains("普通地睡着了")),
        "deep-sleep refusal line missing from {messages:?}"
    );
    assert!(
        messages.iter().any(|m| m.contains("不能做的太过分")),
        "deep-sleep limit line missing from {messages:?}"
    );
    assert!(
        var(&game, 18) > depth_before,
        "the refused action still settles the sister deeper: {depth_before} -> {}",
        var(&game, 18)
    );
    assert!(
        !has_picture(&game, 16000) && !has_picture(&game, 16001),
        "a refused action draws no template cut-in picture"
    );
    assert_eq!(game.stats.warnings, 0, "warnings");
}

#[test]
fn bad_bar_and_variable_59_track_displeasure() {
    for (displeasure, expected) in [(9i32, 50i32), (18, 100), (36, 200)] {
        let root = data_root();
        let mut game = match Game::new(root.clone()) {
            Ok(game) => game,
            Err(err) => {
                eprintln!("skipping: {err}");
                return;
            }
        };
        if let Err(err) = game.load_save(&save_path(&root)) {
            eprintln!("skipping: {err}");
            return;
        }
        game.vm.vars.set(63, 100);
        game.vm.vars.set(64, displeasure);
        game.vm.vars.set(24, 40);
        game.start_event(237);
        for _ in 0..8 {
            game.frame();
        }

        assert_status_bar(&game);
        let bad_scale = game.screen.get(1997).map(|p| p.scale);
        let good_scale = game.screen.get(1993).map(|p| p.scale);
        assert_eq!(
            bad_scale,
            Some(expected),
            "BAD gradient scale for v64={displeasure}"
        );
        assert_eq!(
            var(&game, 59),
            expected,
            "嫌悪感割合値 v59 for v64={displeasure}"
        );
        assert_eq!(good_scale, Some(40), "GOOD gradient scale tracks v24=40");
        assert_eq!(game.stats.warnings, 0, "warnings");
    }
}

/// Runs the interface with a preset 射精感 and reports whether the forced
/// ejaculation phase fired, the messages it showed, and the final counters.
fn run_with_drive(value: i32, frames: usize) -> Option<(Game, Vec<String>)> {
    let mut game = enter_interface()?;
    game.vm.vars.set(66, value);
    let mut messages = Vec::new();
    for _ in 0..frames {
        step_collect(&mut game, &mut messages);
    }
    Some((game, messages))
}

#[test]
fn forced_ejaculation_fires_at_120_but_not_at_100_or_119() {
    // 100 is the "can ejaculate" threshold the text/effect scripts check; it is
    // not an automatic end. 119 is one short of the force threshold.
    for value in [100i32, 119] {
        let Some((game, messages)) = run_with_drive(value, 24) else {
            return;
        };
        assert_eq!(var(&game, 125), 0, "v66={value} must not force a phase");
        assert_eq!(var(&game, 180), 0, "v66={value} must not ejaculate");
        assert!(
            !messages.iter().any(|m| m.contains("不行了")),
            "v66={value} must not show the forced line: {messages:?}"
        );
        assert_eq!(game.stats.warnings, 0, "warnings");
    }

    // 120 is the forced threshold: ev20 sets phase v125 = 1, ev17 page 5 runs
    // 「例外処理 強制射精」, resets drive to zero, counts one ejaculation and
    // plays the forced line, then returns the phase to idle.
    let Some((game, messages)) = run_with_drive(120, 60) else {
        return;
    };
    assert!(
        messages.iter().any(|m| m.contains("不行了…出、出来了")),
        "forced-ejaculation line missing from {messages:?}"
    );
    assert_eq!(var(&game, 66), 0, "forced release resets 射精感");
    assert_eq!(var(&game, 180), 1, "forced release counts one ejaculation");
    assert_eq!(var(&game, 125), 0, "the forced phase returns to idle");
    assert_eq!(game.stats.warnings, 0, "warnings");
}

#[test]
fn end_choice_runs_the_trigger_zero_exit_script() {
    // The real exit script is SampleMapA event 21 (終了仮): trigger 0
    // (action-key), conditions v100 == 1 and v125 != 1. The runtime only
    // auto-starts Autorun/Parallel pages, so the map event has to be started
    // explicitly here; clicking the end button picture never reaches it
    // (ev18's 1108 branch only writes the unread var v121 - see the module
    // header, reported engine gap).
    let Some(mut game) = open_loaded() else {
        return;
    };
    game.auto_advance = true;
    game.auto_choice = false;
    let Some(bytes) = std::fs::read(data_root().join("MapData").join("SampleMapA.mps")).ok() else {
        return;
    };
    let Ok(mut map) = Map::parse(&bytes) else {
        return;
    };
    map.events.retain(|event| event.id == 21);
    game.vm.vars.set(100, 1);
    game.vm.vars.set(125, 0);
    // ev21 branches its closing line on how deep the sister sleeps (v18); pin
    // the awake-ish 32/32 state the interface starts with so the message is
    // deterministic.
    game.vm.vars.set(18, 32);
    game.vm.vars.set(19, 32);

    assert!(game.start_map_event(&map, 21), "event 21 starts");
    let mut options = None;
    for _ in 0..120 {
        game.frame();
        if let Some(choices) = &game.choices {
            options = Some(choices.options.clone());
            break;
        }
    }
    assert_eq!(
        options.as_deref(),
        Some(["是".to_owned(), "否".to_owned()].as_slice()),
        "the end prompt offers 是/否"
    );

    game.set_choice_cursor(0); // 是
    game.key_bits = key::OK;
    game.frame();
    game.key_bits = 0;
    let mut messages = Vec::new();
    for _ in 0..150 {
        step_collect(&mut game, &mut messages);
    }

    assert!(
        messages.iter().any(|m| m.contains("暴露了的话就惨了")),
        "exit closing line missing from {messages:?}"
    );
    assert_eq!(
        var(&game, 100),
        0,
        "the end choice clears the interface page"
    );
    assert_eq!(var(&game, 125), 0, "the end choice clears the action phase");
    assert_eq!(game.stats.warnings, 0, "warnings");
}
