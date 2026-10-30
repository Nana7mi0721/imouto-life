//! Game-level save round trip: load a retail save into a real `Game`, write it back
//! with `Game::save_to`, reload the result, and check the live state is identical.
//!
//! This closes the M2 residual "official save round-trip not byte-verified at the game
//! layer": `crates/wolf-save/tests/write.rs` proves `SaveFile::parse -> to_bytes` is the
//! exact inverse of reading the raw file, while this test proves the *engine* inverse
//! (`savegame::load_into` <-> `Game::save_to` / `picture_to_record`) preserves the picture
//! table, the 800 normal variables, play time and the choice anchor.
//!
//! The retail saves are copyrighted, so the test skips when they are absent (set
//! WOLF_RETAIL_SAVE_DIR to point at a `Save` directory that holds SaveDataNN.sav).

use std::path::{Path, PathBuf};

use wolf_game::game::Game;
use wolf_game::savegame;

/// One live picture, reduced to the fields the save format stores.
#[derive(Debug, PartialEq, Eq)]
struct Pic {
    number: i32,
    kind: String,
    file: String,
    text: String,
    x: i32,
    y: i32,
    opacity: i32,
    scale: i32,
    anchor: u8,
    split: (u32, u32),
    pattern_index: u32,
    window: Option<(i32, i32)>,
}

fn repo_root() -> PathBuf {
    let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    path.pop();
    path.pop();
    path
}

fn retail_save_dir() -> Option<PathBuf> {
    if let Ok(dir) = std::env::var("WOLF_RETAIL_SAVE_DIR") {
        let dir = PathBuf::from(dir);
        return dir.is_dir().then_some(dir);
    }
    let dir = repo_root()
        .join("work")
        .join("retail_backup")
        .join("Save");
    dir.is_dir().then_some(dir)
}

fn snapshot(game: &Game) -> Vec<Pic> {
    game.screen
        .iter()
        .map(|p| Pic {
            number: p.number,
            kind: format!("{:?}", p.kind),
            file: p.file.clone(),
            text: p.text.clone(),
            x: p.x,
            y: p.y,
            opacity: p.opacity,
            scale: p.scale,
            anchor: p.anchor,
            split: p.split,
            pattern_index: p.pattern_index,
            window: p.window,
        })
        .collect()
}

fn normal_vars(game: &Game) -> Vec<i32> {
    (0..800).map(|index| game.vm.vars.get(index)).collect()
}

fn round_trip_one(full: &Path, out_dir: &Path, save_path: &Path) {
    let name = save_path.file_name().unwrap().to_string_lossy().into_owned();

    let mut game = Game::new(full).expect("game");
    let loaded = savegame::load_into(&mut game, save_path).expect("load retail save");
    let pics_before = snapshot(&game);
    let vars_before = normal_vars(&game);
    let playtime_before = game.playtime_frames;
    let sys_before = (game.vm.vars.get_sys(3), game.vm.vars.get_sys(4));

    let out = out_dir.join(format!("roundtrip_{name}"));
    std::fs::create_dir_all(out_dir).expect("create out dir");
    game.save_to(&out).expect("save_to");

    let mut reloaded = Game::new(full).expect("reload game");
    let loaded2 = savegame::load_into(&mut reloaded, &out).expect("reload saved file");

    assert_eq!(
        loaded.pictures, loaded2.pictures,
        "{name}: picture count differs after a save round trip"
    );
    assert_eq!(
        snapshot(&reloaded),
        pics_before,
        "{name}: picture table is not stable across save -> reload"
    );
    assert_eq!(
        normal_vars(&reloaded),
        vars_before,
        "{name}: normal variables changed across save -> reload"
    );
    assert_eq!(
        reloaded.playtime_frames, playtime_before,
        "{name}: play time changed across save -> reload"
    );
    assert_eq!(
        (reloaded.vm.vars.get_sys(3), reloaded.vm.vars.get_sys(4)),
        sys_before,
        "{name}: choice anchor changed across save -> reload"
    );

    let _ = std::fs::remove_file(&out);
}

#[test]
fn every_retail_save_survives_a_game_level_save_reload() {
    let Some(dir) = retail_save_dir() else {
        eprintln!("skipping: no retail Save directory (set WOLF_RETAIL_SAVE_DIR)");
        return;
    };
    let full = repo_root().join("work").join("full");
    if !full.is_dir() {
        eprintln!("skipping: work/full data root is missing");
        return;
    }
    let out_dir = repo_root().join("work").join("out");

    let mut checked = 0;
    for slot in 1..=8 {
        let name = format!("SaveData{slot:02}.sav");
        let path = dir.join(&name);
        if !path.is_file() {
            continue;
        }
        round_trip_one(&full, &out_dir, &path);
        checked += 1;
    }
    assert!(checked > 0, "no retail save files were round-tripped");
    eprintln!("game-level round-tripped {checked} save file(s)");
}
