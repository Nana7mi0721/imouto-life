//! Title-menu highlight refresh and mouse-wheel navigation.
//!
//! CE43 is a one-shot renderer: it draws the three dim button rows and overlays the
//! dark `menu*_a.png` selected by system variable 20, then ends. The engine used to
//! move the choice cursor without replaying CE43, so keyboard/wheel/hover selection
//! changed the internal cursor but the dark button stayed on row 0. `Game::frame`
//! now restarts CE43 whenever the title cursor changes, and the front-end turns
//! wheel notches into cursor steps.
//!
//! The save/load grid is the other wheel-sensitive screen: CE131's up/down keys
//! move the slot cursor and left/right change the page (`self[10]` is the slot
//! within the page, `self[11]` the page). `Game::apply_wheel` injects the page
//! keys for that screen, so wheel-down pages forward and wheel-up pages back.
//!
//! Data-missing runs skip and keep the default `cargo test` exit 0.

use std::path::PathBuf;

use wolf_game::{key, Game};

fn data_root() -> Option<PathBuf> {
    let raw = std::env::var("WOLF_DATA_ROOT").ok()?;
    let root = PathBuf::from(raw);
    root.join("BasicData").is_dir().then_some(root)
}

fn visible_pictures(game: &Game) -> Vec<String> {
    game.screen
        .iter()
        .filter(|picture| !picture.hidden)
        .map(|picture| picture.file.clone())
        .collect()
}

fn boot_to_title() -> Option<Game> {
    let root = data_root()?;
    let mut game = Game::new(root).ok()?;
    game.auto_advance = true;
    game.auto_choice = false;
    game.boot().ok()?;
    for _ in 0..400 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }
    let options = game.choices.as_ref()?.options.clone();
    assert_eq!(
        options,
        vec![
            "menu1".to_string(),
            "menu2".to_string(),
            "menu3".to_string()
        ]
    );
    // Let CE43 paint the dim rows and the initial dark row.
    for _ in 0..3 {
        game.frame();
    }
    Some(game)
}

#[test]
fn the_dark_title_button_follows_arrows_and_wheel() {
    let Some(mut game) = boot_to_title() else {
        eprintln!("skipping: WOLF_DATA_ROOT is not set to an unpacked data root");
        return;
    };

    let files = visible_pictures(&game);
    assert!(
        files.iter().any(|file| file == "Picture/menu1_a.png"),
        "cursor 0 must paint the dark menu1_a, got {files:?}"
    );
    assert!(
        !files.iter().any(|file| file == "Picture/menu2_a.png"),
        "menu2_a must stay unpainted while cursor is 0"
    );

    // Arrow Down: cursor 1, dark image moves to menu2_a and menu1 returns to dim.
    game.key_bits = key::DOWN;
    game.frame();
    game.key_bits = 0;
    for _ in 0..3 {
        game.frame();
    }
    assert_eq!(
        game.vm.vars.get_sys(20),
        1,
        "Sys20 mirrors the title cursor"
    );
    let files = visible_pictures(&game);
    assert!(
        files.iter().any(|file| file == "Picture/menu2_a.png"),
        "arrow Down must paint the dark menu2_a, got {files:?}"
    );
    assert!(
        !files.iter().any(|file| file == "Picture/menu1_a.png"),
        "the old dark menu1_a must be repainted as dim"
    );
    assert!(
        files.iter().any(|file| file == "Picture/menu1_b.png"),
        "menu1 must be the dim variant after the cursor leaves it"
    );

    // Wheel up: back to cursor 0.
    game.wheel = 1;
    for _ in 0..4 {
        game.frame();
    }
    assert_eq!(game.vm.vars.get_sys(20), 0);
    let files = visible_pictures(&game);
    assert!(files.iter().any(|file| file == "Picture/menu1_a.png"));
    assert!(!files.iter().any(|file| file == "Picture/menu2_a.png"));

    // Wheel down twice: cursor 2 (wrap through 1).
    game.wheel = -2;
    for _ in 0..4 {
        game.frame();
    }
    assert_eq!(game.vm.vars.get_sys(20), 2);
    let files = visible_pictures(&game);
    assert!(
        files.iter().any(|file| file == "Picture/menu3_a.png"),
        "two wheel-down notches must reach the third row, got {files:?}"
    );
    assert!(!files.iter().any(|file| file == "Picture/menu2_a.png"));
}

#[test]
fn a_fresh_wheel_notch_is_not_left_held_for_the_next_frame() {
    let Some(mut game) = boot_to_title() else {
        return;
    };
    // The injected page/up key is one frame only; `Game::frame` must restore the
    // host-provided key mask so a still wheel does not keep scrolling.
    let before = game.key_bits;
    game.wheel = -1;
    game.frame();
    assert_eq!(game.key_bits, before, "wheel key bits must not persist");
    let cursor = game.choice_cursor();
    game.frame();
    assert_eq!(
        game.choice_cursor(),
        cursor,
        "a parked wheel must not take a second step"
    );
}

/// CE131 is a `123`-poll screen. Its up/down keys move the slot cursor and its
/// left/right keys move the page (`self[610..613]` hold the visible grid state).
/// Wheel-down must be byte-for-byte the same key path as RIGHT, and wheel-up the
/// same as LEFT; comparing the grid state after each avoids guessing which
/// self-variable means "page".
#[test]
fn the_wheel_drives_the_save_grid_like_the_page_keys() {
    let Some(root) = data_root() else {
        return;
    };
    let save = root.join("Save").join("SaveData01.sav");
    if !save.is_file() {
        eprintln!("skipping: no {}", save.display());
        return;
    }

    let open_grid = || {
        let mut game = Game::new(&root).expect("open data root");
        wolf_game::savegame::load_into(&mut game, &save).expect("load SaveData01");
        game.auto_advance = true;
        game.auto_choice = false;
        assert!(game.start_event(131), "CE131 save/load grid did not start");
        for _ in 0..30 {
            game.frame();
        }
        game
    };
    let grid_state = |game: &Game| {
        game.vm
            .instances()
            .iter()
            .find(|instance| instance.event == 131)
            .map(|instance| {
                (600..620)
                    .map(|index| instance.self_vars.get(index))
                    .collect::<Vec<_>>()
            })
            .expect("CE131 is still running")
    };

    let mut manual_right = open_grid();
    manual_right.key_bits = key::RIGHT;
    manual_right.frame();
    manual_right.key_bits = 0;
    for _ in 0..4 {
        manual_right.frame();
    }
    let right_state = grid_state(&manual_right);

    let mut wheel_down = open_grid();
    wheel_down.wheel = -1; // scroll down = next page
    for _ in 0..5 {
        wheel_down.frame();
    }
    assert_eq!(
        grid_state(&wheel_down),
        right_state,
        "wheel-down must drive CE131 exactly like the RIGHT page key"
    );

    let mut manual_left = open_grid();
    manual_left.key_bits = key::LEFT;
    manual_left.frame();
    manual_left.key_bits = 0;
    for _ in 0..4 {
        manual_left.frame();
    }
    let left_state = grid_state(&manual_left);

    let mut wheel_up = open_grid();
    wheel_up.wheel = 1; // scroll up = previous page
    for _ in 0..5 {
        wheel_up.frame();
    }
    assert_eq!(
        grid_state(&wheel_up),
        left_state,
        "wheel-up must drive CE131 exactly like the LEFT page key"
    );

    assert_ne!(
        right_state, left_state,
        "the two directions must not collapse to the same grid state"
    );
}
