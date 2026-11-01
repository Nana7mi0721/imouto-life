//! M5-E mod data overlay acceptance: a mod directory that mirrors the data tree
//! replaces individual files while everything else falls back to the base install.

use std::path::PathBuf;

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

fn scratch_dir(name: &str) -> PathBuf {
    let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    path.pop();
    path.pop();
    path.join("target/test-scratch").join(name)
}

#[test]
fn a_mod_overlay_replaces_one_picture_without_touching_the_base() {
    let root = data_root();
    if !root.join("Game.dat").is_file() && !root.join("BasicData/Game.dat").is_file() {
        eprintln!("skipping: no game data under {}", root.display());
        return;
    }

    let overlay = scratch_dir("m5_mod_overlay");
    let _ = std::fs::remove_dir_all(&overlay);
    std::fs::create_dir_all(overlay.join("Picture")).expect("overlay Picture dir");
    // status01.png is 330x576 in the retail data; the mod ships a 2x1 marker.
    let pixels = [10u8, 20, 30, 255, 40, 50, 60, 255];
    image::save_buffer(
        overlay.join("Picture/status01.png"),
        &pixels,
        2,
        1,
        image::ColorType::Rgba8,
    )
    .expect("write overlay png");

    let mut base = Game::new(&root).expect("base game");
    let base_image = base
        .assets
        .load("Picture/status01.png")
        .expect("base status asset");
    assert_eq!(base_image.size(), (330, 576));

    let mut layered = Game::with_overlays(&root, vec![overlay.clone()]).expect("layered game");
    let image = layered
        .assets
        .load("Picture/status01.png")
        .expect("overlay status asset");
    assert_eq!(image.size(), (2, 1));
    assert_eq!(image.pixel(0, 0), Some([10, 20, 30, 255]));
    assert_eq!(image.pixel(1, 0), Some([40, 50, 60, 255]));
    assert_eq!(layered.overlays(), std::slice::from_ref(&overlay));

    let _ = std::fs::remove_dir_all(&overlay);
}

#[test]
fn game_audio_engine_receives_the_same_mod_overlays() {
    let root = data_root();
    if !root.join("Game.dat").is_file() && !root.join("BasicData/Game.dat").is_file() {
        eprintln!("skipping: no game data under {}", root.display());
        return;
    }

    let overlay = scratch_dir("m5_mod_overlay_audio");
    let _ = std::fs::remove_dir_all(&overlay);
    std::fs::create_dir_all(overlay.join("BGM")).expect("overlay BGM dir");
    std::fs::write(overlay.join("BGM/theme.ogg"), b"marker").expect("overlay bgm marker");

    let mut layered = Game::with_overlays(&root, vec![overlay.clone()]).expect("layered game");
    layered.enable_audio();
    let engine = layered.audio.as_ref().expect("audio engine installed");
    assert_eq!(engine.overlays(), std::slice::from_ref(&overlay));
    assert_eq!(
        engine.resolve("BGM/theme.ogg"),
        Some(overlay.join("BGM/theme.ogg"))
    );

    let _ = std::fs::remove_dir_all(&overlay);
}
