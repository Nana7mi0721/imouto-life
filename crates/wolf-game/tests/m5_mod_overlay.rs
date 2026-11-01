//! M5-E mod data overlay acceptance: a mod directory that mirrors the data tree
//! replaces individual files while everything else falls back to the base install.

use std::path::PathBuf;

use wolf_game::mods::ModError;
use wolf_game::{Game, GameError, TextContext};

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
fn a_mod_can_patch_text_and_the_explicit_catalog_merges_last() {
    let root = data_root();
    if !root.join("Game.dat").is_file() && !root.join("BasicData/Game.dat").is_file() {
        eprintln!("skipping: no game data under {}", root.display());
        return;
    }

    let overlay = scratch_dir("m5_mod_overlay_text");
    let _ = std::fs::remove_dir_all(&overlay);
    std::fs::create_dir_all(&overlay).expect("overlay dir");
    std::fs::write(
        overlay.join("mod.ini"),
        "name=text-mod\nversion=0.1\nrequires=base\n",
    )
    .expect("manifest");
    std::fs::write(overlay.join("translations.tsv"), "开始交流 \tMod chat\n").expect("mod catalog");

    let mut game = Game::with_overlays(&root, vec![overlay.clone()]).expect("layered game");
    assert_eq!(game.translation_len(), 1);
    assert_eq!(
        game.translator()
            .translate_in(TextContext::Choice, "开始交流 "),
        Some("Mod chat")
    );

    let explicit = scratch_dir("m5_mod_overlay_text_explicit");
    let _ = std::fs::remove_dir_all(&explicit);
    std::fs::create_dir_all(&explicit).expect("explicit dir");
    let catalog = explicit.join("explicit.tsv");
    std::fs::write(&catalog, "开始交流 \tExplicit chat\nextra\tExtra\n").expect("catalog");
    assert_eq!(game.merge_translation_file(&catalog).expect("merge"), 2);
    assert_eq!(
        game.translator()
            .translate_in(TextContext::Choice, "开始交流 "),
        Some("Explicit chat")
    );
    assert_eq!(game.translation_len(), 2);

    let _ = std::fs::remove_dir_all(&overlay);
    let _ = std::fs::remove_dir_all(&explicit);
}

#[test]
fn an_unsatisfied_mod_dependency_is_rejected_before_data_is_read() {
    let root = data_root();
    if !root.join("Game.dat").is_file() && !root.join("BasicData/Game.dat").is_file() {
        eprintln!("skipping: no game data under {}", root.display());
        return;
    }

    let overlay = scratch_dir("m5_mod_overlay_dependency");
    let _ = std::fs::remove_dir_all(&overlay);
    std::fs::create_dir_all(&overlay).expect("overlay dir");
    std::fs::write(
        overlay.join("mod.ini"),
        "name=needs-peer\nversion=1.0\nrequires=absent\n",
    )
    .expect("manifest");

    let error = match Game::with_overlays(&root, vec![overlay.clone()]) {
        Ok(_) => panic!("a missing dependency must fail the load"),
        Err(error) => error,
    };
    match error {
        GameError::Mod(ModError::MissingRequirement { name, requires }) => {
            assert_eq!(name, "needs-peer");
            assert_eq!(requires, "absent");
        }
        other => panic!("unexpected error: {other}"),
    }

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
