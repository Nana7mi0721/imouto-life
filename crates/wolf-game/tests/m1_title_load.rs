//! M1 title-and-load slice for 《妹！生活 ～単色～》 (this game).
//!
//! Measured facts this pins:
//! - The boot map is TitleMap.mps event 2, which waits, draws the logo, then calls
//!   common event 42 (the title menu) with the placeholder options menu1..menu3.
//! - Option 0 is the new-game path: CE42 -> Map003 hook -> SampleMapA.
//! - Option 1 is the load path: CE42 -> CE14 -> save/load screen, which restores a
//!   save and drops the player back into the bedroom HUD.
//!
//! The tests skip when the data root is absent, like the rest of the suite.

use std::path::PathBuf;

use wolf_game::game::ENGINE_ALWAYS;
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

fn open_game() -> Option<Game> {
    match Game::new(data_root()) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!("skipping: {err}");
            None
        }
    }
}

fn screen_text(game: &Game) -> Vec<&str> {
    game.screen
        .iter()
        .map(|picture| picture.text.as_str())
        .chain(game.messages.iter().map(|message| message.text.as_str()))
        .collect()
}

#[test]
fn boot_reaches_the_three_option_title_menu() {
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.auto_choice = false;
    game.boot().expect("the title map has its autorun event");

    let mut menu: Option<Vec<String>> = None;
    for _ in 0..240 {
        game.frame();
        if let Some(choices) = &game.choices {
            menu = Some(choices.options.clone());
            break;
        }
    }

    assert_eq!(
        menu.as_deref(),
        Some(["menu1".to_owned(), "menu2".to_owned(), "menu3".to_owned()].as_slice()),
        "the title menu shows the three placeholder options"
    );
    assert_eq!(game.stats.warnings, 0, "the boot chain is warning-free");
    // The whole engine-always set is alive before the menu appears.
    for id in ENGINE_ALWAYS {
        assert!(
            game.vm.started_events.contains(id),
            "ENGINE_ALWAYS event {id} must run in every session"
        );
    }
}

#[test]
fn title_menu_new_game_passes_through_the_Map003_hook_into_SampleMapA() {
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.set_choice_cursor(0);
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.boot().expect("the title map has its autorun event");

    for _ in 0..3200 {
        game.frame();
    }

    assert_eq!(game.stats.frames, 3200);
    assert_eq!(game.stats.warnings, 0, "the new-game path is warning-free");
    assert!(
        game.screen.len() > 30,
        "the room and HUD are drawn: {} pictures",
        game.screen.len()
    );
    let diagnostics: Vec<&str> = game.diagnostics.keys().map(String::as_str).collect();
    assert!(
        diagnostics
            .iter()
            .any(|line| line.contains("130 Teleport: MapData/Map003.mps")),
        "the title menu passes through the Map003 new-game hook: {diagnostics:?}"
    );
    assert!(
        diagnostics
            .iter()
            .any(|line| line.contains("130 Teleport: MapData/SampleMapA.mps")),
        "the hook then teleports into SampleMapA: {diagnostics:?}"
    );
}

#[test]
fn title_menu_load_restores_a_save_into_the_bedroom_hud() {
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.set_choice_cursor(1); // menu2 = load
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.boot().expect("the title map has its autorun event");

    for _ in 0..1600 {
        game.frame();
    }

    assert_eq!(game.stats.warnings, 0, "the load path is warning-free");
    assert!(
        game.screen.len() > 30,
        "the loaded room and HUD are drawn: {}",
        game.screen.len()
    );
    let texts = screen_text(&game);
    // The Chinese fan translation's HUD labels decode correctly after the GBK fix.
    for needle in ["行动力", "持有金钱"] {
        assert!(
            texts.iter().any(|text| text.contains(needle)),
            "the restored HUD shows {needle}: {texts:?}"
        );
    }
    for id in ENGINE_ALWAYS {
        assert!(
            game.vm.started_events.contains(id),
            "ENGINE_ALWAYS event {id} must survive a load"
        );
    }
}
