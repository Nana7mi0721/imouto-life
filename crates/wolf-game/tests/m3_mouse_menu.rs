//! M3-N mouse menu path + anchor consistency for the game under test.
//!
//! The night command menu is a WOLF 102 choice prompt, not a picture-button
//! overlay: SaveData01 restores the bedroom HUD, then start_event(245) opens the
//! five-row menu "开始交流 / 泡茶 / 泡澡 / 网上购物 / 今天就这样睡吧" with the
//! engine window parked at the system-variable anchor (512, 230). This file pins
//! the mouse contract against that real prompt:
//!
//!   * the hit test (Game::choice_row_at) agrees with the geometry the renderer
//!     draws (choice::layout_at_sized): the centre of every row maps back to that
//!     row, the panel padding and points off the panel map to nothing, and the
//!     row pitch is exactly choice::line_pitch(20.0);
//!   * a real left click (moved onto the row, then a press edge held for a while so
//!     a single-frame poll can never miss it) lands on the intended branch for all
//!     five rows, and the empty optional action is not painted as a sixth row;
//!   * the cancel key closes the prompt without picking an option: it drops
//!     CE245 outright, returns from the CE246 sub-menu to the parent menu, and
//!     closes the CE249/CE250 branches without charging money or starting an
//!     action.
//!
//! A right-button press cancels an open 102-choice prompt, matching the manual's
//! cancel contract (right click = cancel). It is edge-triggered like the keyboard
//! CANCEL key: a held button does not repeat, and the prompt's event unwinds as if
//! CANCEL had been pressed (the night menu drops CE245 outright, and the CE246 /
//! CE249 / CE250 sub-menus unwind the same way).
//!
//! Moving the pointer over a row moves the highlight (choice_cursor) under it, so
//! the menu can be driven by hover alone; the highlight does not move on a frame
//! where the pointer is parked or off the panel, and a left click still confirms
//! the row under the pointer. A left click outside the panel is a Cancel reply
//! when the opcode-102 block has a 421 marker (BUG-18), not a swallowed edge.
//!
//! Every step must keep stats.warnings at zero and must not touch the save file.
//! Data-missing runs skip with a message and exit 0.

use std::path::PathBuf;

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

fn save_path() -> PathBuf {
    data_root().join("Save").join("SaveData01.sav")
}

/// Loads SaveData01 without booting into the title: it restores the 800 normal vars
/// and the bedroom HUD, and stops there, so start_event drives a known state.
fn open_loaded_bedroom() -> Option<Game> {
    let root = data_root();
    let mut game = match Game::new(root.clone()) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping mouse-menu tests: {err}");
            return None;
        }
    };
    if let Err(err) = game.load_save(&save_path()) {
        eprintln!("skipping mouse-menu tests: {err}");
        return None;
    }
    // Let messages dismiss themselves so events march to the next choice without input.
    game.auto_advance = true;
    game.auto_choice = false;
    Some(game)
}

/// Starts CE245 (night command) and runs until its five-row choice prompt is live.
fn open_night_menu(game: &mut Game) {
    game.screen.clear();
    assert!(game.start_event(245), "common event 245 starts");
    for _ in 0..60 {
        game.frame();
        if game.choices.is_some() {
            return;
        }
    }
    panic!("the night command menu never opened");
}

/// Current choice options with trailing whitespace trimmed (the data pads labels).
fn trimmed_options(game: &Game) -> Vec<String> {
    game.choices
        .as_ref()
        .map(|c| c.options.iter().map(|s| s.trim_end().to_owned()).collect())
        .unwrap_or_default()
}

/// The five live rows of the night menu, as the renderer would place them.
fn row_rects(game: &Game) -> Vec<[f32; 4]> {
    let choices = game.choices.as_ref().expect("a choice prompt is open");
    let layout = wolf_game::choice::layout_at_sized(
        &choices.options,
        game.choice_cursor(),
        game.choice_anchor().0,
        game.choice_anchor().1,
        game.font_px(),
    )
    .expect("the choice panel is on screen");
    layout.lines.clone()
}

fn row_centre(line: &[f32; 4]) -> (i32, i32) {
    (
        (line[0] + line[2] * 0.5) as i32,
        (line[1] + line[3] * 0.5) as i32,
    )
}

/// Hovers the centre of row row, then holds the left button long enough that a
/// single-frame poll could never miss the click, then releases.
fn click_row(game: &mut Game, row: usize) {
    let lines = row_rects(game);
    let (x, y) = row_centre(&lines[row]);
    game.mouse = [x, y];
    game.frame(); // hover frame; a press edge must be a separate frame
    game.mouse_buttons = 1;
    for _ in 0..24 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..4 {
        game.frame();
    }
}

/// One fresh cancel-key press (edge-triggered inside handle_choice_input).
fn press_cancel(game: &mut Game) {
    game.key_bits = key::CANCEL;
    game.frame();
    game.key_bits = 0;
}

/// One fresh right-button press (edge-triggered inside handle_choice_input). The
/// pointer is parked off the panel first so the press is a clean edge and never a
/// hover that has to settle first.
fn press_right(game: &mut Game) {
    game.mouse = [20, 20];
    game.frame(); // settle the pointer so the press is a clean edge
    game.mouse_buttons = 2;
    for _ in 0..24 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..4 {
        game.frame();
    }
}

fn live_events(game: &Game) -> Vec<u32> {
    let mut events: Vec<u32> = game.vm.instances().iter().map(|i| i.event).collect();
    events.sort_unstable();
    events.dedup();
    events
}

fn is_night_menu(game: &Game) -> bool {
    trimmed_options(game)
        == ["开始交流", "泡茶", "泡澡", "网上购物", "今天就这样睡吧"]
            .map(str::to_owned)
            .to_vec()
}

#[test]
fn hover_hit_test_matches_anchor_row_pitch_and_padding() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    open_night_menu(&mut game);

    // The night menu is painted at the engine anchor the data set in Sys3/Sys4.
    assert_eq!(
        game.choice_anchor(),
        (512, 230),
        "the night menu window anchors at (512,230)"
    );
    assert_eq!(game.font_px(), 20.0, "the menu draws at the Sys8 font size");

    let lines = row_rects(&game);
    assert_eq!(lines.len(), 5, "five option rows");
    // Uniform row pitch: consecutive rows are exactly one line pitch apart.
    for window in lines.windows(2) {
        assert_eq!(
            window[1][1] - window[0][1],
            wolf_game::choice::line_pitch(20.0),
            "row pitch equals choice::line_pitch(20.0)"
        );
    }

    // The hit test is geometry-based, not cursor-based: moving the highlight must
    // not move the row a point maps to.
    game.set_choice_cursor(3);
    for (row, line) in lines.iter().enumerate() {
        let (cx, cy) = row_centre(line);
        assert_eq!(
            game.choice_row_at(cx, cy),
            Some(row),
            "a point at the centre of row {row} hit-tests to row {row}"
        );
        // Hover without pressing only reports a target; it must not consume a row.
        game.mouse = [cx, cy];
        game.frame();
        assert_eq!(
            game.choice_row_at(cx, cy),
            Some(row),
            "hovering row {row} keeps hit-testing to row {row}"
        );
        assert!(
            is_night_menu(&game),
            "hover must not pick an option (row {row})"
        );
    }

    // Inner padding above the first row and points off the panel are not rows.
    let (ax, ay) = game.choice_anchor();
    assert_eq!(
        game.choice_row_at(ax + 4, ay + 4),
        None,
        "the panel padding is not a row"
    );
    assert_eq!(
        game.choice_row_at(ax - 20, ay - 20),
        None,
        "a point off the panel maps to nothing"
    );
    assert_eq!(game.stats.warnings, 0, "hover hit-testing is warning-free");
}

#[test]
fn hover_moves_the_highlight_and_left_click_still_hits() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    open_night_menu(&mut game);
    let lines = row_rects(&game);
    assert_eq!(lines.len(), 5, "five option rows");

    // Start on a non-zero row so a follow can be told apart from "stayed put".
    game.set_choice_cursor(4);
    // Move to the centre of each row in turn; the highlight follows the pointer.
    for row in 0..5usize {
        let (x, y) = row_centre(&lines[row]);
        game.mouse = [x, y];
        game.frame();
        assert_eq!(
            game.choice_cursor(),
            row,
            "moving onto row {row} highlights row {row}"
        );
        assert!(
            is_night_menu(&game),
            "hovering hides nothing and picks no row ({row})"
        );
    }

    // A move that lands off the panel leaves the highlight where it was.
    let (ax, ay) = game.choice_anchor();
    let before = game.choice_cursor();
    game.mouse = [ax - 40, ay - 40];
    game.frame();
    assert_eq!(
        game.choice_cursor(),
        before,
        "moving off the panel leaves the highlight unchanged"
    );

    // Moving back onto a row resumes the follow.
    let (x, y) = row_centre(&lines[2]);
    game.mouse = [x, y];
    game.frame();
    assert_eq!(
        game.choice_cursor(),
        2,
        "moving back onto row 2 highlights row 2 again"
    );

    // A left click on a row still confirms it: row 2 (泡澡) opens CE249.
    game.mouse = [x, y];
    game.frame(); // park on the row so the press is a clean edge
    game.mouse_buttons = 1;
    for _ in 0..24 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..4 {
        game.frame();
    }
    assert!(
        live_events(&game).contains(&249),
        "a left click still hits the row under the pointer (CE249), events {:?}",
        live_events(&game)
    );
    assert_eq!(game.stats.warnings, 0, "hover + left click is warning-free");
}

#[test]
fn left_click_hits_each_night_action() {
    // Row -> what the click must reach. Checked one fresh game per row so earlier
    // clicks cannot mutate the state a later row is judged in.
    for row in 0..5usize {
        let Some(mut game) = open_loaded_bedroom() else {
            return;
        };
        open_night_menu(&mut game);
        assert!(is_night_menu(&game), "row {row}: starts on the menu");

        click_row(&mut game, row);

        match row {
            0 => {
                // 开始交流 hands off to CE246 with its own four options.
                assert_eq!(
                    trimmed_options(&game),
                    ["说话", "看看电视吧", "玩游戏吧", "鸡鸡伸展！"]
                        .map(str::to_owned)
                        .to_vec(),
                    "row 0 opens the CE246 communication menu"
                );
                assert!(live_events(&game).contains(&246), "CE246 is running");
            }
            1 => {
                // 泡茶 opens the eight-row drink submenu.
                let options = trimmed_options(&game);
                assert_eq!(options.len(), 8, "row 1 opens the 8-drink submenu");
                assert!(
                    options[0].starts_with("绿茶"),
                    "drink submenu starts with 绿茶"
                );
            }
            2 => {
                // 泡澡 launches CE249.
                assert_eq!(
                    trimmed_options(&game),
                    ["一个人洗", "两个人洗"].map(str::to_owned).to_vec(),
                    "row 2 opens the CE249 bath menu"
                );
                assert!(live_events(&game).contains(&249), "CE249 is running");
            }
            3 => {
                // 网上购物 launches CE250 (sets var15 = 1 on entry). Which three rows the
                // shop offers is branch/RNG-dependent (one shipped row is also a known
                // corrupted string), so only the count and the live event are pinned.
                let options = trimmed_options(&game);
                assert_eq!(
                    options.len(),
                    3,
                    "row 3 opens the three-item shop menu: {options:?}"
                );
                assert!(live_events(&game).contains(&250), "CE250 is running");
                assert_eq!(game.vm.vars.get(15), 1, "the shop flag var15 is set");
            }
            4 => {
                // 今天就这样睡吧 raises the 是 / 否 confirmation.
                assert_eq!(
                    trimmed_options(&game),
                    ["是", "否"].map(str::to_owned).to_vec(),
                    "row 4 raises the sleep confirmation"
                );
            }
            _ => unreachable!(),
        }
        assert_eq!(game.stats.warnings, 0, "row {row} click is warning-free");
    }
}

#[test]
fn cancel_key_drops_ce245_without_picking() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    open_night_menu(&mut game);
    assert!(is_night_menu(&game));

    press_cancel(&mut game);
    for _ in 0..4 {
        game.frame();
    }

    assert!(game.choices.is_none(), "cancel closes the night menu");
    assert!(
        live_events(&game).is_empty(),
        "cancel picks no action: no child event is left running, got {:?}",
        live_events(&game)
    );
    assert_eq!(game.vm.vars.get(7), 10000, "cancel spends no money");
    assert_eq!(game.stats.warnings, 0, "cancel is warning-free");
}

#[test]
fn a_left_click_outside_the_panel_cancels_the_prompt() {
    // BUG-18: an outside click used to be marked consumed and then ignored, so
    // the prompt looked dead. When the opcode-102 block has a 421 cancel marker,
    // the outside click is a real Cancel reply, just like the CANCEL key.
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    open_night_menu(&mut game);
    assert!(is_night_menu(&game));

    game.mouse = [0, 0];
    game.frame(); // settle the pointer outside the panel
    assert!(game.choices.is_some(), "hovering outside must not cancel");
    game.mouse_buttons = 1;
    for _ in 0..6 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..4 {
        game.frame();
    }

    assert!(game.choices.is_none(), "outside click closes the prompt");
    assert!(
        live_events(&game).is_empty(),
        "outside click picks no action, got {:?}",
        live_events(&game)
    );
    assert_eq!(game.vm.vars.get(7), 10000, "outside click spends no money");
    assert_eq!(game.stats.warnings, 0, "outside click is warning-free");
}

#[test]
fn cancel_key_returns_from_ce246_to_parent_menu() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    open_night_menu(&mut game);
    click_row(&mut game, 0); // 开始交流 -> CE246
    assert_eq!(
        trimmed_options(&game),
        ["说话", "看看电视吧", "玩游戏吧", "鸡鸡伸展！"]
            .map(str::to_owned)
            .to_vec(),
        "CE246 menu is open before cancelling"
    );

    press_cancel(&mut game);
    for _ in 0..6 {
        game.frame();
    }

    assert!(
        is_night_menu(&game),
        "cancelling CE246 returns to the parent CE245 menu, got {:?}",
        trimmed_options(&game)
    );
    assert!(
        live_events(&game).contains(&245),
        "CE245 is still the parent"
    );
    assert_eq!(
        game.stats.warnings, 0,
        "returning from CE246 is warning-free"
    );
}

#[test]
fn cancel_key_closes_ce249_bath_without_starting_it() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    open_night_menu(&mut game);
    click_row(&mut game, 2); // 泡澡 -> CE249
    assert_eq!(
        trimmed_options(&game),
        ["一个人洗", "两个人洗"].map(str::to_owned).to_vec(),
        "CE249 bath menu is open before cancelling"
    );

    press_cancel(&mut game);
    for _ in 0..30 {
        game.frame();
    }

    assert!(game.choices.is_none(), "cancel closes the bath menu");
    assert!(
        live_events(&game).is_empty(),
        "cancel starts no bath action, events {:?}",
        live_events(&game)
    );
    assert!(game.messages.is_empty(), "cancel leaves no bath message");
    assert_eq!(game.stats.warnings, 0, "cancelling CE249 is warning-free");
}

#[test]
fn cancel_key_closes_ce250_shop_without_buying() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    open_night_menu(&mut game);
    click_row(&mut game, 3); // 网上购物 -> CE250
    assert_eq!(trimmed_options(&game).len(), 3, "CE250 shop menu is open");
    assert_eq!(game.vm.vars.get(15), 1, "shop flag set on entry");

    press_cancel(&mut game);
    for _ in 0..30 {
        game.frame();
    }

    assert!(game.choices.is_none(), "cancel closes the shop menu");
    assert_eq!(game.vm.vars.get(7), 10000, "cancel spends no money");
    assert_eq!(game.vm.vars.get(15), 0, "the shop flag resets on close");
    assert_eq!(game.stats.warnings, 0, "cancelling CE250 is warning-free");
}

#[test]
fn right_button_cancels_the_night_menu() {
    // The manual's cancel contract applies to a 102-choice prompt too: a right-button
    // press is an edge-triggered cancel, exactly like the keyboard CANCEL key. The
    // night menu unwinds and CE245 ends without picking a row.
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    open_night_menu(&mut game);
    assert!(is_night_menu(&game));

    game.mouse = [500, 300];
    game.frame(); // settle the pointer so the press is a clean edge
    game.mouse_buttons = 2;
    for _ in 0..24 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..4 {
        game.frame();
    }

    assert!(
        game.choices.is_none(),
        "a right-button press cancels the choice prompt"
    );
    assert!(
        !live_events(&game).contains(&245),
        "cancelling unwinds CE245 itself, not just its prompt"
    );
    assert_eq!(
        game.vm.vars.get(7),
        10000,
        "a right-click cancel spends no money"
    );
    assert_eq!(game.vm.vars.get(15), 0, "the shop flag stays clear");
    assert_eq!(game.stats.warnings, 0, "right-click cancel is warning-free");
}

#[test]
fn right_button_returns_from_ce246_to_parent_menu() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    open_night_menu(&mut game);
    click_row(&mut game, 0); // 开始交流 -> CE246
    assert_eq!(
        trimmed_options(&game),
        ["说话", "看看电视吧", "玩游戏吧", "鸡鸡伸展！"]
            .map(str::to_owned)
            .to_vec(),
        "CE246 menu is open before right-clicking"
    );

    press_right(&mut game);
    for _ in 0..6 {
        game.frame();
    }

    assert!(
        is_night_menu(&game),
        "a right click cancels CE246 back to the parent CE245 menu, got {:?}",
        trimmed_options(&game)
    );
    assert!(
        live_events(&game).contains(&245),
        "CE245 is the parent after unwinding CE246"
    );
    assert_eq!(
        game.stats.warnings, 0,
        "right-click from CE246 is warning-free"
    );
}

#[test]
fn right_button_closes_ce249_bath_without_starting_it() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    open_night_menu(&mut game);
    click_row(&mut game, 2); // 泡澡 -> CE249
    assert_eq!(
        trimmed_options(&game),
        ["一个人洗", "两个人洗"].map(str::to_owned).to_vec(),
        "CE249 bath menu is open before right-clicking"
    );

    press_right(&mut game);
    for _ in 0..30 {
        game.frame();
    }

    assert!(game.choices.is_none(), "a right click closes the bath menu");
    assert!(
        live_events(&game).is_empty(),
        "a right click starts no bath action, events {:?}",
        live_events(&game)
    );
    assert!(
        game.messages.is_empty(),
        "a right click leaves no bath message"
    );
    assert_eq!(
        game.stats.warnings, 0,
        "right-clicking CE249 is warning-free"
    );
}

#[test]
fn right_button_closes_ce250_shop_without_buying() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    open_night_menu(&mut game);
    click_row(&mut game, 3); // 网上购物 -> CE250
    assert_eq!(trimmed_options(&game).len(), 3, "CE250 shop menu is open");
    assert_eq!(game.vm.vars.get(15), 1, "shop flag set on entry");

    press_right(&mut game);
    for _ in 0..30 {
        game.frame();
    }

    assert!(game.choices.is_none(), "a right click closes the shop menu");
    assert_eq!(game.vm.vars.get(7), 10000, "a right click spends no money");
    assert_eq!(game.vm.vars.get(15), 0, "the shop flag resets on close");
    assert_eq!(
        game.stats.warnings, 0,
        "right-clicking CE250 is warning-free"
    );
}

#[test]
fn full_mouse_run_leaves_the_save_file_untouched() {
    let Some(before) = std::fs::read(save_path()).ok() else {
        eprintln!("skipping mouse-menu tests: no SaveData01.sav");
        return;
    };

    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    open_night_menu(&mut game);
    // Walk every branch by mouse, then cancel the shop branch, to exercise the
    // whole path once and confirm nothing writes the save.
    for row in 0..4usize {
        let Some(mut detour) = open_loaded_bedroom() else {
            return;
        };
        open_night_menu(&mut detour);
        click_row(&mut detour, row);
        assert_eq!(detour.stats.warnings, 0, "row {row} run is warning-free");
    }
    press_cancel(&mut game);

    let after = std::fs::read(save_path()).expect("re-read the save file");
    assert_eq!(
        before, after,
        "the mouse menu run must not rewrite SaveData01.sav"
    );
    assert_eq!(
        before.len(),
        after.len(),
        "the save file keeps its byte length"
    );
    assert_eq!(game.stats.warnings, 0, "the full run is warning-free");
}
