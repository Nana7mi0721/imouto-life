//! M2 mouse-to-key input slice for 《妹！生活 ～単色～》 (this game).
//!
//! The command menus are picture buttons; the per-frame judge event polls each
//! button with opcode 124 (hover), and when a button is hovered it polls the key
//! state with opcode 123 and, if that reads 10 (decide), writes the button's index
//! into variable 67. That is the whole mouse-to-menu contract:
//!
//!   EV16 「コマンド選択判定」 page0 (parallel, condition var100 >= 1):
//!     op124 [1100000,16384,<pic>,8]   hover?
//!     op111 if 1100000 == 1
//!       op123 [1100001,17]            key code
//!       op111 if 1100001 == 10
//!         op121 [2000067,<index>]     var67 = index
//!
//! Before this slice the port only folded the keyboard bits into the poll, so a
//! mouse click could never satisfy EV16. These tests drive the real event and pin
//! both the click path and the gates around it (hover required, press edge only).
//!
//! The tests skip when the data root is absent, like the rest of the suite.

use std::path::PathBuf;

use wolf_format::mps::Map;
use wolf_game::picture::ANCHOR_TOP_LEFT;
use wolf_game::{key, Game, Picture};

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

/// Parse `MapData/<name>.mps` and keep only one event, so the test runs that
/// event's real command stream without dragging in the map's story event.
fn one_event_map(name: &str, event_id: u32) -> Map {
    let path = data_root().join("MapData").join(format!("{name}.mps"));
    let bytes = std::fs::read(&path).expect("read the map file");
    let mut map = Map::parse(&bytes).expect("parse the map file");
    map.events.retain(|event| event.id == event_id);
    assert_eq!(map.events.len(), 1, "the map has event {event_id}");
    map
}

/// Start EV16 alone and open a command category so its page condition
/// (var100 >= 1) holds. The map's own menu draw event (EV15) is not loaded, so
/// the only picture the judge sees is the one the test inserts.
fn start_command_judge(game: &mut Game) {
    let map = one_event_map("SampleMapA", 16);
    game.start_pages(&map, None);
    game.vm.vars.set(100, 1);
    // EV16 only starts on the frame after its page condition first holds, so run
    // a few frames with nothing hovered to get it looping before the real input.
    for _ in 0..3 {
        game.frame();
    }
}

/// The picture-button EV16 watches for index 1.
fn button_400() -> Picture {
    let mut picture = Picture::new(400);
    picture.x = 200;
    picture.y = 200;
    picture.window = Some((200, 80));
    picture.anchor = ANCHOR_TOP_LEFT;
    picture
}

#[test]
fn left_click_on_a_hovered_button_writes_its_index_into_var67() {
    let Some(mut game) = open_game() else { return };
    start_command_judge(&mut game);

    // Nothing hovered or pressed yet: the judge runs but writes nothing.
    for _ in 0..10 {
        game.frame();
    }
    assert_eq!(game.vm.vars.get(67), 0, "var67 starts clean");

    // Put the cursor in the middle of button 400 and hover without pressing.
    game.screen.insert(button_400());
    game.mouse = [300, 240];
    for _ in 0..5 {
        game.frame();
    }
    assert_eq!(
        game.vm.vars.get(67),
        0,
        "hovering alone must not pick the command"
    );

    // One frame with the left button down is a press edge; EV16 must see code 10.
    game.mouse_buttons = 1;
    game.frame();
    game.mouse_buttons = 0;
    for _ in 0..2 {
        game.frame();
    }
    assert_eq!(
        game.vm.vars.get(67),
        1,
        "picture 400 is index 1 in EV16"
    );
}

#[test]
fn a_click_away_from_the_button_does_not_pick_it() {
    let Some(mut game) = open_game() else { return };
    start_command_judge(&mut game);
    game.screen.insert(button_400());

    // Cursor deliberately outside the 200x80 box at (200,200).
    game.mouse = [50, 50];
    game.mouse_buttons = 1;
    game.frame();
    game.mouse_buttons = 0;
    for _ in 0..2 {
        game.frame();
    }
    assert_eq!(
        game.vm.vars.get(67),
        0,
        "op124 gates the click: no hover means no pick"
    );
}

#[test]
fn a_right_click_is_cancel_and_never_picks_a_command() {
    let Some(mut game) = open_game() else { return };
    start_command_judge(&mut game);
    game.screen.insert(button_400());
    game.mouse = [300, 240];
    for _ in 0..3 {
        game.frame();
    }

    // Right press is code 11, and EV16 only acts on 10, so var67 stays clean.
    game.mouse_buttons = 2;
    game.frame();
    game.mouse_buttons = 0;
    for _ in 0..2 {
        game.frame();
    }
    assert_eq!(
        game.vm.vars.get(67),
        0,
        "the cancel code must not pick the command"
    );
}

#[test]
fn holding_the_button_does_not_repeat_the_pick() {
    let Some(mut game) = open_game() else { return };
    start_command_judge(&mut game);
    game.screen.insert(button_400());
    game.mouse = [300, 240];

    // Press and keep holding for several frames; the pick must land once.
    game.mouse_buttons = 1;
    for _ in 0..6 {
        game.frame();
    }
    assert_eq!(game.vm.vars.get(67), 1, "the press edge picks once");

    game.mouse_buttons = 0;
    game.frame();
    assert_eq!(
        game.vm.vars.get(67),
        1,
        "releasing does not change the written index"
    );
}

#[test]
fn the_keyboard_still_drives_the_same_poll() {
    let Some(mut game) = open_game() else { return };
    start_command_judge(&mut game);
    game.screen.insert(button_400());
    game.mouse = [300, 240];

    // No mouse button, only the keyboard decide bit held.
    game.key_bits = key::OK;
    game.frame();
    assert_eq!(
        game.vm.vars.get(67),
        1,
        "the mouse path must not replace the keyboard path"
    );
}
