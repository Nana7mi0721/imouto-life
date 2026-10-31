//! M4: fixed-screen (negative-numbered) pictures keep their native size.
//!
//! Retail WOLF numbers below zero mean "does not scroll with the map", not "covers the
//! whole 1024x576 screen". SaveData01 places the save icon in slot -5 and the data icon in
//! slot -4; drawing those as full-screen layers zoomed them into giant overlays.

use std::path::PathBuf;

use wolf_game::{Atlas, Game};

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let p = PathBuf::from(raw);
    if p.is_absolute() {
        p
    } else {
        let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        base.pop();
        base.pop();
        base.join(p)
    }
}

fn loaded() -> Option<Game> {
    let root = data_root();
    let save = root.join("Save").join("SaveData01.sav");
    if !save.is_file() {
        eprintln!("skipping: missing {}", save.display());
        return None;
    }
    let mut game = match Game::new(root) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: cannot open data root: {err}");
            return None;
        }
    };
    if let Err(err) = game.load_save(&save) {
        eprintln!("skipping: cannot load SaveData01: {err}");
        return None;
    }
    game.auto_advance = true;
    game.auto_choice = false;
    for _ in 0..120 {
        game.frame();
    }
    Some(game)
}

fn quad_for(game: &mut Game, number: i32) -> Option<[f32; 4]> {
    let mut atlas = Atlas::new();
    game.picture_quads(&mut atlas)
        .into_iter()
        .find(|quad| quad.number == number)
        .map(|quad| quad.rect)
}

#[test]
fn hud_icons_are_not_stretched_to_the_whole_screen() {
    let Some(mut game) = loaded() else { return };
    assert_eq!(
        game.screen.get(-5).map(|p| p.file.as_str()),
        Some("Picture/icon01.png")
    );
    assert_eq!(
        game.screen.get(-4).map(|p| p.file.as_str()),
        Some("Picture/icon05.png")
    );

    let save_icon = quad_for(&mut game, -5).expect("save icon quad");
    assert_eq!(save_icon[0], 10.0);
    assert_eq!(save_icon[1], 510.0);
    assert!(
        save_icon[2] <= 100.0 && save_icon[3] <= 100.0,
        "{save_icon:?}"
    );

    let data_icon = quad_for(&mut game, -4).expect("data icon quad");
    assert_eq!(data_icon[0], 925.0);
    assert_eq!(data_icon[1], 507.0);
    assert!(
        data_icon[2] <= 100.0 && data_icon[3] <= 100.0,
        "{data_icon:?}"
    );
}

#[test]
fn title_art_is_a_full_screen_fixed_layer() {
    if !data_root().join("BasicData/CommonEvent.dat").is_file() {
        eprintln!("skipping: no data under {}", data_root().display());
        return;
    }
    let mut game = Game::new(data_root()).expect("game");
    game.auto_advance = true;
    game.auto_choice = false;
    game.start_title().expect("title event");
    for _ in 0..30 {
        game.frame();
    }
    let title = quad_for(&mut game, -2).expect("title quad");
    assert_eq!(title, [0.0, 0.0, 1024.0, 576.0]);
}
