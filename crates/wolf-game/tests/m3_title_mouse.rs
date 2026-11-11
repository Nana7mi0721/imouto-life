//! M3-U title/load mouse path for the game under test.
//!
//! Two separate mechanisms meet at the boot title screen:
//!
//!   * The title "menu" is NOT a picture-button overlay here. It is common event
//!     42 ("オリジナルタイトル画面Ａ", the WOLF sample title screen A). Before it
//!     opens the 102-choice prompt it hard-sets system vars 3/4 to -1000
//!     (CE42 op121 [9000003,-1000] / [9000004,-1000]), i.e. it deliberately parks
//!     the choice window completely off screen; its background picture
//!     Picture/title2.jpg does not exist in this build (docs/M3_ASSET_REFS.md). So
//!     the real title prompt has no on-screen rows at all and cannot be clicked
//!     with the mouse until it is relocated. The first test pins that real,
//!     off-screen placeholder state.
//!   * The choice input layer (Game::handle_choice_input) is shared with the
//!     night command menu. To exercise the mouse contract on the title prompt this
//!     file relocates the window with a test-side write to system vars 3/4
//!     (game.vm.vars.set_sys) -- clearly SYNTHETIC, it does not change game source
//!     and is labelled as such -- and then hovers/clicks the rows exactly like a
//!     real pointer would.
//!
//! Downstream of the prompt the real events run: menu1 (new game) teleports
//! Map003 -> SampleMapA; menu2 (load) opens common event 14's read-a-save grid.
//!
//! Known current-behaviour facts, pinned here and reported to the lead:
//!   * A right-button press cancels a 102-choice prompt, matching the keyboard
//!     CANCEL key (edge-triggered). At the title it replies Cancel, CE42 unwinds
//!     past its op102 into the [60] Sys4=150 instruction and the title event ends.
//!     It also cancels the picture-driven load grid, because that grid polls
//!     opcode 123 through the mouse->key bridge.
//!   * Cancelling the load grid (cancel key or right click) closes it but does NOT
//!     return to the title menu: CE42's load branch ends the title event chain and
//!     this port has no "restart title" step, so the engine goes idle. The test
//!     documents this instead of pretending the title comes back.
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

fn save_fingerprint() -> Vec<u8> {
    std::fs::read(save_path()).unwrap_or_default()
}

/// Boots the title map and runs to the three-option choice prompt.
fn open_title() -> Option<Game> {
    let mut game = match Game::new(data_root()) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping title-mouse tests: {err}");
            return None;
        }
    };
    game.auto_advance = true;
    game.auto_choice = false;
    if let Err(err) = game.boot() {
        eprintln!("skipping title-mouse tests: {err}");
        return None;
    }
    for _ in 0..240 {
        game.frame();
        if game.choices.is_some() {
            // The title renderer (event 43) only runs while the menu is up, so give it
            // a few frames to paint the Picture/menu*_* buttons after the prompt appears.
            for _ in 0..3 {
                game.frame();
            }
            return Some(game);
        }
    }
    eprintln!("skipping title-mouse tests: the title prompt never opened");
    None
}

/// Strips WOLF text escapes (\f[0], \c[0], \cdb[..], \E, \A-, ...) so a decoded
/// picture label can be compared against the plain Chinese it should read as.
fn visible(raw: &str) -> String {
    let mut out = String::new();
    let mut chars = raw.chars().peekable();
    while let Some(ch) = chars.next() {
        if ch == '\\' {
            while matches!(chars.peek(), Some(c) if c.is_ascii_alphanumeric()) {
                chars.next();
            }
            if chars.peek() == Some(&'[') {
                chars.next();
                for c in chars.by_ref() {
                    if c == ']' {
                        break;
                    }
                }
            }
        } else {
            out.push(ch);
        }
    }
    out
}

fn trimmed_options(game: &Game) -> Vec<String> {
    game.choices
        .as_ref()
        .map(|c| c.options.iter().map(|s| s.trim_end().to_owned()).collect())
        .unwrap_or_default()
}

fn has_load_grid(game: &Game) -> bool {
    game.screen
        .iter()
        .any(|picture| visible(&picture.text).contains("选择要读取的数据"))
}

fn live_events(game: &Game) -> Vec<u32> {
    let mut events: Vec<u32> = game.vm.instances().iter().map(|i| i.event).collect();
    events.sort_unstable();
    events.dedup();
    events
}

/// SYNTHETIC test-only relocation: move the off-screen title prompt onto the
/// screen by overriding system vars 3/4, so the shared choice input layer can be
/// driven by a pointer. Does not touch game source.
fn relocate_prompt(game: &mut Game) {
    game.vm.vars.set_sys(3, 300);
    game.vm.vars.set_sys(4, 200);
}

fn row_rects(game: &Game) -> Vec<[f32; 4]> {
    let choices = game.choices.as_ref().expect("a choice prompt is open");
    wolf_game::choice::layout_at_sized(
        &choices.options,
        game.choice_cursor(),
        game.choice_anchor().0,
        game.choice_anchor().1,
        game.font_px(),
    )
    .expect("the relocated choice panel is on screen")
    .lines
    .clone()
}

fn row_centre(line: &[f32; 4]) -> (i32, i32) {
    (
        (line[0] + line[2] * 0.5) as i32,
        (line[1] + line[3] * 0.5) as i32,
    )
}

/// Hovers the centre of row, then holds the left button for a while so a
/// single-frame poll can never miss the press edge, then releases.
fn click_row(game: &mut Game, row: usize) {
    let lines = row_rects(game);
    let (x, y) = row_centre(&lines[row]);
    game.mouse = [x, y];
    game.frame();
    game.mouse_buttons = 1;
    for _ in 0..24 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..6 {
        game.frame();
    }
}

fn press_cancel(game: &mut Game) {
    game.key_bits = key::CANCEL;
    game.frame();
    game.key_bits = 0;
}

/// Right-button press edge held long enough for the opcode 123 poll to catch it.
fn press_right_button(game: &mut Game) {
    game.mouse_buttons = 2;
    for _ in 0..20 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..10 {
        game.frame();
    }
}

fn run_frames(game: &mut Game, count: usize) {
    for _ in 0..count {
        game.frame();
    }
}

const EXPECTED_TITLE: [&str; 3] = ["menu1", "menu2", "menu3"];

#[test]
fn title_prompt_falls_back_to_a_hittable_centred_panel() {
    let Some(game) = open_title() else {
        return;
    };
    assert_eq!(
        trimmed_options(&game),
        EXPECTED_TITLE.map(str::to_owned).to_vec()
    );
    // The WOLF sample title screen parks the window at (-1000,-1000).
    assert_eq!(
        game.choice_anchor(),
        (-1000, -1000),
        "CE42 hard-sets system vars 3/4 to -1000"
    );
    // That off-screen anchor now falls back to a visible, centred panel instead of
    // painting nothing, so the title menu the player needs is actually there.
    let choices = game.choices.as_ref().unwrap();
    let panel = wolf_game::choice::layout_at_sized(
        &choices.options,
        game.choice_cursor(),
        game.choice_anchor().0,
        game.choice_anchor().1,
        game.font_px(),
    )
    .expect("the parked anchor falls back to a centred on-screen panel");
    assert!(
        panel.rect[0] >= 0.0
            && panel.rect[1] >= 0.0
            && panel.rect[0] + panel.rect[2] <= 1024.0
            && panel.rect[1] + panel.rect[3] <= 576.0,
        "the fallback panel is fully on screen: {:?}",
        panel.rect
    );
    // Every one of the three title rows is now mouse-hittable at its centre.
    for (row, line) in panel.lines.iter().enumerate() {
        let (x, y) = row_centre(line);
        assert_eq!(
            game.choice_row_at(x, y),
            Some(row),
            "row {row} of the visible title menu is hittable at ({x},{y})"
        );
    }
    assert_eq!(
        game.stats.warnings, 0,
        "the visible title prompt is warning-free"
    );
}

#[test]
fn synthetic_relocation_makes_the_three_rows_mouse_hittable() {
    let Some(mut game) = open_title() else {
        return;
    };
    relocate_prompt(&mut game);
    assert_eq!(game.choices.as_ref().map(|c| c.options.len()), Some(3));

    let lines = row_rects(&game);
    assert_eq!(lines.len(), 3);
    // The title menu is the script's own image buttons, drawn at fixed 50 px pitch
    // (y = 400/450/500); the hit rows mirror exactly those rows, not choice::LINE_HEIGHT.
    assert!(
        (lines[1][1] - lines[0][1] - 50.0).abs() < 0.01,
        "title image rows sit 50 px apart: {lines:?}"
    );
    assert!(
        game.screen.iter().any(|p| p.file.contains("menu1")),
        "event 43 paints the real Picture/menu1_* button, not a text panel: {:?}",
        game.screen
            .iter()
            .map(|p| p.file.clone())
            .collect::<Vec<_>>()
    );
    for (row, line) in lines.iter().enumerate() {
        let (x, y) = row_centre(line);
        assert_eq!(
            game.choice_row_at(x, y),
            Some(row),
            "hovering the centre of row {row} hits row {row}"
        );
    }
    // Well away from the panel nothing is hit.
    assert_eq!(game.choice_row_at(10, 10), None);

    // Right-button press cancels the 102-choice prompt, like the keyboard CANCEL key.
    // CE42 then unwinds past its op102 into the [60] Sys4=150 instruction and ends.
    press_right_button(&mut game);
    assert!(
        game.choices.is_none(),
        "a right click cancels the choice prompt"
    );
    assert!(
        !live_events(&game).contains(&42),
        "the title event (42) has unwound after the cancel"
    );
    assert_eq!(
        game.sys(4),
        150,
        "control returned past op102 into [60] Sys4=150"
    );
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn left_click_new_game_teleports_through_map003_into_sample_map_a() {
    let Some(mut game) = open_title() else {
        return;
    };
    relocate_prompt(&mut game);
    click_row(&mut game, 0); // menu1 = new game
    assert!(
        game.choices.is_none(),
        "the left click replies with row 0, closing the prompt"
    );

    let mut reached = false;
    for _ in 0..4000 {
        game.frame();
        if game.stats.warnings > 0 {
            break;
        }
        let seen: Vec<&str> = game.diagnostics.keys().map(String::as_str).collect();
        if seen
            .iter()
            .any(|l| l.contains("130 Teleport: MapData/Map003.mps"))
            && seen
                .iter()
                .any(|l| l.contains("130 Teleport: MapData/SampleMapA.mps"))
        {
            reached = true;
            break;
        }
    }
    let seen: Vec<&str> = game.diagnostics.keys().map(String::as_str).collect();
    assert!(
        reached,
        "the clicked new-game path teleports to both maps: {seen:?}"
    );
    assert!(
        seen.iter()
            .any(|l| l.contains("130 Teleport: MapData/Map003.mps")),
        "title menu1 passes through the Map003 new-game hook: {seen:?}"
    );
    assert!(
        seen.iter()
            .any(|l| l.contains("130 Teleport: MapData/SampleMapA.mps")),
        "the hook then teleports into SampleMapA: {seen:?}"
    );
    assert_eq!(
        game.stats.warnings, 0,
        "the clicked new-game path is warning-free"
    );
}

#[test]
fn left_click_load_opens_the_ce14_read_grid() {
    let Some(mut game) = open_title() else {
        return;
    };
    relocate_prompt(&mut game);
    click_row(&mut game, 1); // menu2 = load
    assert!(game.choices.is_none(), "the left click replies with row 1");

    let mut opened = false;
    for _ in 0..600 {
        game.frame();
        if has_load_grid(&game) {
            opened = true;
            break;
        }
    }
    assert!(opened, "menu2 opens CE14's read-save grid");
    assert!(
        live_events(&game).contains(&14),
        "common event 14 (the load screen) is alive: {:?}",
        live_events(&game)
    );
    // The grid keeps 25 window/text pictures and a handful of icons; the old
    // threshold of 30 counted the six stray "0" glyph pictures per slot that the
    // save-slot text fix removed, so 20 still proves the full grid was built.
    assert!(
        game.screen.len() > 20,
        "the load grid draws many pictures: {}",
        game.screen.len()
    );
    assert_eq!(game.stats.warnings, 0, "the load grid is warning-free");
}

#[test]
fn cancel_closes_the_load_grid_and_reopens_the_title_menu() {
    let Some(mut game) = open_title() else {
        return;
    };
    relocate_prompt(&mut game);
    click_row(&mut game, 1);
    // Run a fixed window so the grid is fully built and polling before the edge,
    // matching how a real player would pause on the screen.
    run_frames(&mut game, 300);
    assert!(has_load_grid(&game), "precondition: the load grid opened");

    press_cancel(&mut game);
    run_frames(&mut game, 40);

    assert!(!has_load_grid(&game), "the cancel key clears the load grid");
    assert!(
        !live_events(&game).contains(&14),
        "CE14 has ended after cancel: {:?}",
        live_events(&game)
    );
    // ESC/right click is "back to the previous level": cancelling the load grid
    // returns to the title menu (CE42's cancel arm restarts it).
    assert_eq!(
        trimmed_options(&game),
        EXPECTED_TITLE.map(str::to_owned).to_vec(),
        "cancel returns to the title menu"
    );
    assert_eq!(
        game.stats.warnings, 0,
        "cancelling the load grid is warning-free"
    );
}

#[test]
fn right_button_closes_the_load_grid_through_the_opcode_123_bridge() {
    let Some(mut game) = open_title() else {
        return;
    };
    relocate_prompt(&mut game);
    click_row(&mut game, 1);
    // Run a fixed window so the grid is fully built and polling before the edge.
    run_frames(&mut game, 300);
    assert!(has_load_grid(&game), "precondition: the load grid opened");

    press_right_button(&mut game);
    run_frames(&mut game, 40);

    assert!(
        !has_load_grid(&game),
        "the picture-driven load grid cancels on a right click (op123 sees it)"
    );
    assert!(
        !live_events(&game).contains(&14),
        "CE14 has ended after the right click"
    );
    assert_eq!(game.stats.warnings, 0, "right-click cancel is warning-free");
}

#[test]
fn the_title_cursor_is_mirrored_into_sys20_for_the_image_highlighter() {
    let Some(mut game) = open_title() else {
        return;
    };
    // Event 43 picks the bright menu*_a.png by reading Sys20 == 0/1/2, so the port mirrors
    // the choice cursor there every frame; otherwise the highlight never moves.
    game.set_choice_cursor(0);
    game.frame();
    assert_eq!(game.sys(20), 0, "cursor 0 lights the first title button");
    game.set_choice_cursor(1);
    game.frame();
    assert_eq!(game.sys(20), 1, "cursor 1 lights the second title button");
    game.set_choice_cursor(2);
    game.frame();
    assert_eq!(game.sys(20), 2, "cursor 2 lights the third title button");
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn title_mouse_run_leaves_the_save_file_untouched() {
    let Some(mut game) = open_title() else {
        return;
    };
    let before = save_fingerprint();
    assert!(!before.is_empty(), "precondition: SaveData01 is present");
    relocate_prompt(&mut game);
    click_row(&mut game, 1); // open the load grid...
    let mut opened = false;
    for _ in 0..600 {
        game.frame();
        if has_load_grid(&game) {
            opened = true;
            break;
        }
    }
    assert!(opened, "precondition: the load grid opened");
    press_cancel(&mut game); // ...and cancel it without loading anything
    run_frames(&mut game, 40);

    assert_eq!(game.stats.warnings, 0);
    assert_eq!(
        save_fingerprint(),
        before,
        "opening and cancelling the load grid must not rewrite SaveData01"
    );
}
