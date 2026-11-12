//! T13 UI audit: keep the night interaction controls from restoring HUD icons
//! that the end-button layer owns.
//!
//! The first-night notice and the initial end-button state are already covered
//! by `m17_ui_regressions`. This file follows the action pages themselves:
//! clicking 触摸/衣服 and entering a command submenu must not redraw the `-4`
//! data icon underneath the end arrow.

use std::path::PathBuf;

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

fn open_night() -> Option<Game> {
    let root = data_root();
    let save = root.join("Save").join("SaveData01.sav");
    if !save.is_file() {
        eprintln!("skipping: no SaveData01 under {}", root.display());
        return None;
    }
    let mut game = Game::new(root.clone()).ok()?;
    game.load_save(&save).ok()?;
    game.auto_advance = false;
    game.auto_choice = false;

    let bytes = std::fs::read(root.join("MapData").join("SampleMapA.mps")).ok()?;
    let mut map = Map::parse(&bytes).ok()?;
    map.events
        .retain(|event| [5, 15, 16, 17, 18, 19, 20, 21, 23, 26].contains(&event.id));
    game.start_pages(&map, None);
    game.vm.vars.set(100, 1);
    game.vm.vars.set(125, 0);
    game.vm.vars.set(18, 32);
    game.vm.vars.set(19, 32);
    game.start_event(230);
    Some(game)
}

fn visible(game: &Game, number: i32) -> bool {
    game.screen
        .get(number)
        .is_some_and(|picture| !picture.hidden && picture.opacity > 0)
}

fn wait_for_night_ui(game: &mut Game) {
    let mut stable = 0;
    for _ in 0..800 {
        game.frame();
        if !game.messages.is_empty() {
            game.key_bits = key::OK;
            game.frame();
            game.key_bits = 0;
        }
        if visible(game, 1108) && game.messages.is_empty() {
            stable += 1;
            if stable >= 30 {
                return;
            }
        } else {
            stable = 0;
        }
    }
    panic!("the night interface never drew its end button");
}

fn click_picture(game: &mut Game, number: i32) {
    let picture = game.screen.get(number).expect("picture button");
    let (x, y) = (picture.x + 30, picture.y + 30);
    game.mouse = [x, y];
    game.frame();
    game.mouse_buttons = 1;
    for _ in 0..6 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..12 {
        game.frame();
    }
}

fn assert_data_icon_hidden(game: &Game, context: &str) {
    assert!(
        !visible(game, -4),
        "{context}: data icon -4 reappeared under the end button"
    );
}

#[test]
fn touch_button_page_does_not_restore_the_night_data_icon() {
    let Some(mut game) = open_night() else {
        return;
    };
    wait_for_night_ui(&mut game);
    assert_data_icon_hidden(&game, "initial night UI");

    click_picture(&mut game, 400);
    assert_eq!(game.vm.vars.get(100), 3, "touch button opens page 3");
    assert_data_icon_hidden(&game, "after touch page");
}

#[test]
fn clothes_button_page_does_not_restore_the_night_data_icon() {
    let Some(mut game) = open_night() else {
        return;
    };
    wait_for_night_ui(&mut game);
    assert_data_icon_hidden(&game, "initial night UI");

    click_picture(&mut game, 404);
    assert_data_icon_hidden(&game, "after clothes page");
}

#[test]
fn action_submenu_does_not_restore_the_night_data_icon() {
    let Some(mut game) = open_night() else {
        return;
    };
    wait_for_night_ui(&mut game);
    click_picture(&mut game, 400);
    assert_eq!(game.vm.vars.get(100), 3, "touch button opens page 3");

    click_picture(&mut game, 390);
    assert_eq!(game.vm.vars.get(100), 10, "submenu opens action page 10");
    assert_data_icon_hidden(&game, "after opening action page");

    click_picture(&mut game, 430);
    assert_data_icon_hidden(&game, "after undress action");
}

#[test]
fn end_button_stays_clickable_after_opening_the_action_submenu() {
    let Some(mut game) = open_night() else {
        return;
    };
    wait_for_night_ui(&mut game);
    click_picture(&mut game, 400);
    assert_eq!(game.vm.vars.get(100), 3, "touch button opens page 3");
    click_picture(&mut game, 390);
    assert_eq!(game.vm.vars.get(100), 10, "submenu opens action page 10");

    click_picture(&mut game, 1108);
    assert_eq!(
        game.last_action_event,
        Some(21),
        "the end arrow must still own its visible hit box after the action submenu"
    );
    assert!(
        game.messages
            .iter()
            .any(|message| message.text.contains("要结束动作吗")),
        "the end arrow must open its confirmation instead of silently doing nothing"
    );
}

#[test]
fn save_icon_stays_clickable_after_opening_the_action_submenu() {
    let Some(mut game) = open_night() else {
        return;
    };
    wait_for_night_ui(&mut game);
    click_picture(&mut game, 400);
    click_picture(&mut game, 390);
    assert_eq!(game.vm.vars.get(100), 10, "submenu opens action page 10");
    assert!(
        visible(&game, -5),
        "the save icon must remain visible on the night action page"
    );

    click_picture(&mut game, -5);
    assert_eq!(
        game.last_action_event,
        Some(5),
        "the save icon must open its action page from the night action submenu"
    );
    assert!(
        game.vm
            .instances()
            .iter()
            .any(|instance| instance.event == 131),
        "the save screen CE131 must start from the night action submenu"
    );
}
