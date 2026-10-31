//! M4 night-interface gap coverage (docs/M3_RUNTIME.md §5, gap #5).
//!
//! This file closes the two recorded end-to-end gaps:
//!
//! * the ejaculation-sensation / displeasure percentage branch: the BAD bar and
//!   variable 59 follow the shipped script's `v64 * 100 / 18` integer formula
//!   (100% at v64 = 18, and the 120%-style region just past it; integer vars
//!   cannot represent exactly 21.6), while 射精感 v66 forces the phase exactly
//!   at 120 but never at 100 or 119;
//! * the real 结束 button 1108 path: clicking the picture (as opposed to only
//!   directly starting ev21) goes through MapRuntime's trigger-0 action-key
//!   bridge, opens the 是/否 prompt, and choosing 是 ends the interface.
//!
//! Every test skips (eprintln + return) when work/Data is absent, matching the
//! existing data-gated suite.

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

fn read_map(name: &str, events: &[u32]) -> Option<Map> {
    let path = data_root().join("MapData").join(name);
    let bytes = std::fs::read(&path).ok()?;
    let mut map = Map::parse(&bytes).ok()?;
    map.events.retain(|event| events.contains(&event.id));
    Some(map)
}

/// Strip WOLF text-control escapes so assertions look at the visible glyphs.
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

fn var(game: &Game, index: usize) -> i32 {
    game.vm.vars.get(index)
}

fn running(game: &Game, event: u32) -> bool {
    game.vm
        .instances()
        .iter()
        .any(|instance| instance.event == event)
}

fn picture_file(game: &Game, number: i32) -> Option<String> {
    game.screen.get(number).map(|p| p.file.clone())
}

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

/// The map's night-interface pages plus (optionally) the trigger-0 exit ev21.
fn night_map(events: &[u32]) -> Option<Map> {
    read_map("SampleMapA.mps", events)
}

/// Opens the deep-night interface through its own entry point (CE230 深夜1) after
/// starting the selected map pages.
fn open_night(events: &[u32]) -> Option<Game> {
    let mut game = open_loaded()?;
    let map = night_map(events)?;
    game.start_pages(&map, None);
    game.vm.vars.set(100, 1);
    game.vm.vars.set(125, 0);
    // The shipped interface starts in the awake-ish 32/32 sleep state; pin it so
    // the end-event closing line is deterministic.
    game.vm.vars.set(18, 32);
    game.vm.vars.set(19, 32);
    game.start_event(230);
    let mut seen = Vec::new();
    for _ in 0..260 {
        step_collect(&mut game, &mut seen);
    }
    Some(game)
}

/// A real left click: park the pointer, press for one fresh edge frame, release.
fn click_at(game: &mut Game, x: i32, y: i32) {
    game.mouse = [x, y];
    for _ in 0..2 {
        game.frame();
    }
    game.mouse_buttons = 1;
    game.frame();
    game.mouse_buttons = 0;
    for _ in 0..4 {
        game.frame();
    }
}

fn run_with_drive(value: i32, frames: usize) -> Option<(Game, Vec<String>)> {
    let mut game = open_night(&[15, 16, 17, 18, 19, 20, 23, 26])?;
    game.vm.vars.set(66, value);
    let mut messages = Vec::new();
    for _ in 0..frames {
        step_collect(&mut game, &mut messages);
    }
    Some((game, messages))
}

// ---------------------------------------------------------------------------
// (a) Displeasure percentage formula and the 100% / 120% region.
// ---------------------------------------------------------------------------

#[test]
fn displeasure_formula_is_100_percent_at_18_and_crosses_120_after_21() {
    // CE237's BAD bar and normal variable 59 are both the shipped script's
    // integer formula v64 * 100 / 18. v64 = 18 is exactly 100%; the script
    // cannot represent 120% exactly (that would need v64 = 21.6), so pin the
    // values on both sides of the boundary: 21 -> 116%, 22 -> 122%.
    for v64 in [18i32, 21, 22, 36] {
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
        game.vm.vars.set(64, v64);
        game.vm.vars.set(24, 40);
        game.start_event(237);
        for _ in 0..8 {
            game.frame();
        }

        let expected = (v64 * 100) / 18;
        assert_eq!(
            var(&game, 59),
            expected,
            "v59 must be the script's v64*100/18 for v64={v64}"
        );
        assert_eq!(
            game.screen.get(1997).map(|p| p.scale),
            Some(expected),
            "the BAD gradient must track v59 for v64={v64}"
        );
        if v64 == 18 {
            assert_eq!(var(&game, 59), 100, "v64=18 is the 100% point");
            assert_eq!(
                game.screen.get(1997).map(|p| p.scale),
                Some(100),
                "the BAD bar is full at 100%"
            );
        }
        if v64 == 22 {
            assert!(
                var(&game, 59) >= 120,
                "v64=22 has crossed the 120%-style region: {}",
                var(&game, 59)
            );
        }
        assert_eq!(
            game.screen.get(1993).map(|p| p.scale),
            Some(40),
            "GOOD still tracks v24=40"
        );
        assert_eq!(game.stats.warnings, 0, "warnings");
    }
}

// ---------------------------------------------------------------------------
// (a cont.) 射精感 threshold: 100 is not an end, 120 is the forced branch.
// ---------------------------------------------------------------------------

#[test]
fn ejaculation_sensation_forces_at_120_but_not_at_100_or_119() {
    // 100 is only the "can ejaculate" check used by the text/effect scripts;
    // 119 is one short of the forced phase. Neither may run ev17 page 5.
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

    // 120 is the forced threshold: ev20 sets v125 = 1, ev17 page 5
    // (「例外処理 強制射精」) plays the line, resets v66 and counts v180.
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

// ---------------------------------------------------------------------------
// (b) Real 结束 button 1108 click -> trigger-0 ev21 -> 是/否 -> end.
// ---------------------------------------------------------------------------

#[test]
fn clicking_picture_1108_opens_ev21_and_yes_ends_the_interface() {
    let Some(mut game) = open_night(&[15, 16, 17, 18, 19, 20, 21, 23, 26]) else {
        return;
    };

    // The visible end button is picture 1108 (Picture/endbutton.png); ev21's
    // trigger-0 hit box is the bottom-right tile rectangle (976,544)-(1072,608).
    // Their overlap is the lower-right part of the button. Click there so the
    // press is a real click on 1108 *and* lands in ev21's action-key hotspot.
    let picture = game.screen.get(1108).expect("end button 1108 on screen");
    assert_eq!(
        picture_file(&game, 1108).as_deref(),
        Some("Picture/endbutton.png")
    );
    let (x, y) = (picture.x + 49, picture.y + 47);
    assert!(
        x >= picture.x && x < picture.x + 90 && y >= picture.y && y < picture.y + 70,
        "click point ({x},{y}) must be inside picture 1108 at ({},{}) 90x70",
        picture.x,
        picture.y
    );
    assert!(
        (976..1072).contains(&x) && (544..608).contains(&y),
        "click point ({x},{y}) must fall in ev21's action-key tile rectangle"
    );

    // From here the event chain may show dialogue before the 是/否 prompt, so
    // let the runtime auto-advance messages (as the real click flow does).
    game.auto_advance = true;

    // Hover alone never activates the trigger-0 page.
    game.mouse = [x, y];
    for _ in 0..10 {
        game.frame();
    }
    assert!(
        !running(&game, 21),
        "hovering the end button must not start ev21"
    );
    assert_eq!(game.last_action_event, None, "hover is not a click");

    // A fresh left click reaches the action-key layer even though the click is
    // also inside ev18's picture hit handler (that overlap is the documented,
    // intended bridge in map_runtime/game.rs).
    click_at(&mut game, x, y);
    let mut messages = Vec::new();
    let mut options = None;
    for _ in 0..120 {
        game.frame();
        for message in &game.messages {
            let text = visible(&message.text);
            if !text.is_empty() && !messages.contains(&text) {
                messages.push(text);
            }
        }
        if let Some(choices) = &game.choices {
            options = Some(choices.options.clone());
            break;
        }
    }
    assert_eq!(
        game.last_action_event,
        Some(21),
        "the end button click must activate ev21 through the action-key path"
    );
    assert_eq!(
        options.as_deref(),
        Some(["是".to_owned(), "否".to_owned()].as_slice()),
        "clicking 1108 opens the 是/否 end prompt"
    );

    // 是 ends the interface and plays the closing line.
    game.set_choice_cursor(0);
    game.key_bits = key::OK;
    game.frame();
    game.key_bits = 0;
    for _ in 0..150 {
        step_collect(&mut game, &mut messages);
    }

    assert!(
        messages
            .iter()
            .any(|text| text.contains("暴露了的话就惨了")),
        "exit closing line missing from {messages:?}"
    );
    assert_eq!(var(&game, 100), 0, "是 clears the interface page");
    assert_eq!(var(&game, 125), 0, "是 clears the action phase");
    assert!(!running(&game, 21), "the exit event finishes");
    assert_eq!(game.stats.warnings, 0, "warnings");
}
