//! The opening story script: SampleMapA event 0, run headlessly.
//!
//! This is M2's vertical slice. The script starts with a long linear cutscene
//! (disclaimer, choices, fades, cg pictures) and is the first content that uses
//! the message, choice, save/load and effect paths together, so a regression in
//! any of them shows up here as a change in the instruction count or a warning.

use std::path::PathBuf;

use wolf_game::atlas::{self, Atlas};
use wolf_game::key;
use wolf_game::Game;

fn data_root() -> PathBuf {
    let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    base.pop();
    base.pop();
    base.join("work/full")
}

#[test]
fn the_opening_script_runs_and_draws_its_pictures() {
    let root = data_root();
    let mut game = match Game::new(&root) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    // Messages dismiss themselves, but the opening prompt is HELD: dice the choice and
    // the script walks on into the character creation loop, which spins without a frame
    // wait (measured: 103 million instructions over 600 frames). Holding it is what the
    // retail player sees at the end of the cutscene and what `wolf-cli capture` photographs.
    game.auto_advance = true;
    if let Err(err) = game.start_map_event_by_name("SampleMapA", 0) {
        eprintln!("skipping: cannot start the opening: {err}");
        return;
    }
    for _ in 0..600 {
        let _ = game.frame();
    }
    let mut atlas = Atlas::new();
    let quads = atlas.sprites(&game.screen, &mut game.assets);
    let texts = atlas::texts(&game.screen);
    println!(
        "frames 600 instructions {} pictures {} quads {} texts {} atlas images {} warnings {}",
        game.stats.instructions,
        game.screen.len(),
        quads.len(),
        texts.len(),
        atlas.len(),
        game.stats.warnings
    );
    for picture in game.screen.iter() {
        println!(
            "  pic {:<6} {:?} at ({}, {}) scale {} alpha {:.2} {:?}",
            picture.number,
            picture.kind,
            picture.x,
            picture.y,
            picture.scale,
            picture.alpha(),
            picture.file
        );
    }
    // The measured shape of the first ten seconds, taken from this run rather than
    // guessed: 19,596 instructions, 696 picture operations, no warnings. The script
    // draws a black backdrop, runs the loading screen (common event 221), erases it and
    // parks on the four-option opening prompt.
    assert_eq!(game.stats.warnings, 0, "the opening produced warnings");
    assert!(
        (15_000..200_000).contains(&game.stats.instructions),
        "script ran {} instructions",
        game.stats.instructions
    );
    // The backdrop is the whole-screen layer WOLF numbers -1.
    let backdrop = game.screen.get(-1).expect("black backdrop");
    assert_eq!(backdrop.file, "cg/blackscreen.jpg");
    // The regression this test exists for: common event 221 ends the loading screen with
    // ONE ranged erase, `150 [16777218, 50000, 5, 5, 0, 50003]`. While the picture layer
    // read that as a single-slot erase, the eyecatch (50001), the NOW LOADING text (50002)
    // and the progress bar (50003) stayed on screen for the whole game, because nothing
    // else in the script ever names them.
    for number in 50000..=50003 {
        assert!(
            game.screen.get(number).is_none(),
            "loading picture {number} survived the ranged erase"
        );
    }
    // The prompt itself: the engine choice window is painted by the caller (see
    // wolf_game::choice), so the live prompt is what proves the script parked where the
    // retail player sees the menu.
    let prompt = game.choices.as_ref().expect("the opening prompt is open");
    assert_eq!(
        prompt.options,
        [
            "广阔的战场",
            "广袤的森林",
            "微风吹拂而过的麦田",
            "有人在等我的家"
        ],
        "the opening prompt changed"
    );
    // The prompt is mouse-first, so the hit test and the drawn geometry have to agree: a
    // click on the centre of every row must return exactly that row, and a click outside
    // the panel must return nothing.
    let layout = wolf_game::choice::layout_at_sized(
        &prompt.options,
        game.choice_cursor(),
        game.choice_anchor().0,
        game.choice_anchor().1,
        game.font_px(),
    )
    .expect("the prompt must be visible");
    for (row, line) in layout.lines.iter().enumerate() {
        let (cx, cy) = (line[0] + line[2] * 0.5, line[1] + line[3] * 0.5);
        assert_eq!(
            game.choice_row_at(cx as i32, cy as i32),
            Some(row),
            "a click on row {row} must select it"
        );
    }
    assert_eq!(
        game.choice_row_at(0, 0),
        None,
        "a click outside the panel must select nothing"
    );
    // The prompt arrives through the choice path, so no text picture is on screen. The
    // only text pictures alive belong to the third-party balloon-message library that
    // event 98 initialises: it parks its 24 controls at (-2784, 2880) until a bubble is
    // opened, and `atlas::texts` reports them because a parked control is still a live
    // picture. Asserting on the numbers instead of the count keeps the check honest when
    // the library adds a control.
    let on_screen_texts: Vec<i32> = game
        .screen
        .iter()
        .filter(|picture| picture.kind.is_text())
        .filter(|picture| (0..1024).contains(&picture.x) && (0..576).contains(&picture.y))
        .map(|picture| picture.number)
        .collect();
    assert!(
        on_screen_texts.is_empty(),
        "text pictures on screen: {on_screen_texts:?} (texts {})",
        texts.len()
    );
    assert!(!quads.is_empty(), "nothing textured on screen");
    // The narration was shown and dismissed: a 101 that is never closed leaves the
    // message in Game::messages for the rest of the session and pins Sys12 at 1, which
    // makes common event 63 repaint the window frame every frame (measured: +150
    // instructions per frame). One frame of a dismissed message must leave nothing.
    assert!(
        game.messages.is_empty(),
        "{} message(s) stayed on screen after the prompt opened",
        game.messages.len()
    );
    assert!(
        game.stats.messages > 0,
        "the opening narration never arrived"
    );
}

/// The new-game processing map (Map003 event 1) is the path the title menu takes:
/// it draws its pre-game screen and then runs opcode 130 with map id -1. The
/// measured meaning of -1 is MapData row 1, SampleMapA, and -2 is row 0, TitleMap
/// (docs/ASSET_AUDIT.md section 3.6); the new game must land on the opening story.
#[test]
fn the_new_game_processing_map_teleports_into_the_opening() {
    let root = data_root();
    let mut game = match Game::new(&root) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    game.auto_advance = true;
    if let Err(err) = game.start_map_event_by_name("Map003", 1) {
        eprintln!("skipping: cannot start new-game processing: {err}");
        return;
    }
    for _ in 0..600 {
        let _ = game.frame();
    }
    assert!(
        game.diagnostics
            .keys()
            .any(|line| line.contains("130 Teleport: MapData/SampleMapA.mps")),
        "the new-game map never teleported: {:?}",
        game.diagnostics.keys().collect::<Vec<_>>()
    );
    let prompt = game.choices.as_ref().expect("the opening prompt is open");
    assert_eq!(
        prompt.options,
        [
            "广阔的战场",
            "广袤的森林",
            "微风吹拂而过的麦田",
            "有人在等我的家"
        ],
        "the teleport did not reach the opening prompt"
    );
    assert_eq!(
        game.stats.warnings, 0,
        "the new-game path produced warnings"
    );
}

/// The retail entry chain: boot to the title art, confirm opens the title menu,
/// and its first option starts a new game through opcode 130 map id -1. This is
/// the chain PLAN.md calls title -> new game; the map-run test above starts one
/// step later, at Map003 event 1.
#[test]
fn the_title_menu_starts_a_new_game() {
    let root = data_root();
    let mut game = match Game::new(&root) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    if let Err(err) = game.boot() {
        eprintln!("skipping: cannot boot: {err}");
        return;
    }
    for _ in 0..800 {
        game.frame();
    }
    assert!(
        game.screen
            .iter()
            .any(|picture| picture.file.contains("title01")),
        "the boot chain did not reach the title art"
    );
    game.key_bits = key::OK;
    game.frame();
    game.key_bits = 0;
    for _ in 0..240 {
        game.frame();
    }
    let menu = game.choices.as_ref().expect("the title menu is open");
    assert_eq!(menu.options, ["1", "2", "3"], "the title menu changed");
    game.set_choice_cursor(0);
    game.auto_choice = true;
    game.auto_choice_delay = 1;
    // Answer ONLY the title menu: leave auto_choice on until the menu closes, then
    // turn it off so the opening prompt downstream is held like the retail player
    // sees it (and like the other two tests).
    for _ in 0..120 {
        game.frame();
        if game.choices.is_none() {
            break;
        }
    }
    game.auto_choice = false;
    // The opening narration is a 101 message; with auto_advance off it would hold
    // the script before the prompt (the other tests set this from the start).
    game.auto_advance = true;
    for _ in 0..900 {
        game.frame();
    }
    assert!(
        game.diagnostics
            .keys()
            .any(|line| line.contains("130 Teleport: MapData/SampleMapA.mps")),
        "the title menu never started a new game: {:?}",
        game.diagnostics.keys().collect::<Vec<_>>()
    );
    let prompt = game.choices.as_ref().expect("the opening prompt is open");
    assert_eq!(
        prompt.options,
        [
            "广阔的战场",
            "广袤的森林",
            "微风吹拂而过的麦田",
            "有人在等我的家"
        ],
        "the title menu did not reach the opening prompt"
    );
    assert_eq!(game.stats.warnings, 0, "the title path produced warnings");
}

/// The M2 everyday chain: start a new game, answer the opening prompts, reach the
/// story HUD, write a save and load it back into a fresh Game. Everything the
/// player sees (the picture layer) and the state that changes during play (normal
/// variables, play time, choice anchor) must survive the round trip.
#[test]
fn a_title_new_game_can_be_saved_and_reloaded_after_the_opening() {
    let root = data_root();
    let mut game = match Game::new(&root) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    let template = PathBuf::from(env!("CARGO_MANIFEST_DIR"))
        .join("../..")
        .join("work/retail_backup/Save/System.sav");
    let Ok(bytes) = std::fs::read(&template) else {
        eprintln!("skipping: no retail System.sav at {}", template.display());
        return;
    };
    game.base_save = Some(wolf_save::SaveFile::parse(&bytes).expect("template parses"));

    // The full PLAN.md chain starts at the title screen: boot, confirm, title menu,
    // first option (new game), then let the opening dialogue and prompts run.
    if let Err(err) = game.boot() {
        eprintln!("skipping: cannot boot: {err}");
        return;
    }
    for _ in 0..800 {
        game.frame();
    }
    assert!(
        game.screen
            .iter()
            .any(|picture| picture.file.contains("title01")),
        "the boot chain did not reach the title art"
    );
    game.key_bits = key::OK;
    game.frame();
    game.key_bits = 0;
    for _ in 0..240 {
        game.frame();
    }
    let menu = game.choices.as_ref().expect("the title menu is open");
    assert_eq!(menu.options, ["1", "2", "3"], "the title menu changed");
    game.set_choice_cursor(0);
    game.auto_choice = true;
    game.auto_choice_delay = 1;
    for _ in 0..120 {
        game.frame();
        if game.choices.is_none() {
            break;
        }
    }
    game.auto_advance = true;
    for _ in 0..1200 {
        let _ = game.frame();
    }
    assert!(
        game.screen.len() > 40,
        "the new game did not reach the story scene: {} pictures",
        game.screen.len()
    );
    assert_eq!(game.stats.warnings, 0, "the new-game run produced warnings");

    fn visible_pictures(
        screen: &wolf_game::picture::Screen,
    ) -> Vec<(i32, String, i32, i32, u8, i32, (u32, u32), u32)> {
        screen
            .iter()
            .filter(|p| p.x < 1024 && p.y < 576 && p.x + 1 > 0 && p.y + 1 > 0)
            .filter(|p| !p.file.is_empty() || !p.text.is_empty())
            .map(|p| {
                let content = if p.kind.is_text() {
                    format!("text:{}", p.text)
                } else {
                    p.file.clone()
                };
                (
                    p.number,
                    content,
                    p.x,
                    p.y,
                    p.anchor,
                    p.scale,
                    p.split,
                    p.pattern_index,
                )
            })
            .collect()
    }
    let before_screen = visible_pictures(&game.screen);
    let before_vars: Vec<i32> = (0..800).map(|index| game.vm.vars.get(index)).collect();
    let before_playtime = game.playtime_frames();
    assert!(before_playtime > 0, "play time did not advance");

    let dir = PathBuf::from(env!("CARGO_MANIFEST_DIR"))
        .join("../..")
        .join("target")
        .join("test-scratch");
    std::fs::create_dir_all(&dir).expect("scratch dir");
    let path = dir.join("m2-newgame-roundtrip.sav");
    let written = game.save_to(&path).expect("save the new game");
    assert!(written > 300_000, "{written} bytes");

    let mut reloaded = Game::new(&root).expect("fresh game");
    reloaded.load_save(&path).expect("load the new game");
    let after_screen = visible_pictures(&reloaded.screen);
    assert_eq!(
        before_screen, after_screen,
        "the visible picture layer changed"
    );
    assert_eq!(
        reloaded.playtime_frames(),
        before_playtime,
        "play time changed"
    );
    for index in 0..800 {
        assert_eq!(
            reloaded.vm.vars.get(index),
            before_vars[index],
            "normal variable {index} changed"
        );
    }
    assert_eq!(
        reloaded.vm.vars.get_sys(3),
        game.vm.vars.get_sys(3),
        "Sys3 changed"
    );
    assert_eq!(
        reloaded.vm.vars.get_sys(4),
        game.vm.vars.get_sys(4),
        "Sys4 changed"
    );
}
