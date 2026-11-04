//! \`151 ChangeColor\` scales the brightness of the map and the screen-layer pictures,
//! and the capture path bakes that multiplier into the quad tints. This pins the tile
//! half end to end: a neutral run leaves every quad untinted, and an installed colour
//! scales them (values above 100 clamp to neutral, they do not brighten).

use std::path::PathBuf;

use wolf_game::{Atlas, Game};

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/full".to_owned());
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

#[test]
fn screen_tint_scales_the_tile_layer() {
    let Some(mut game) = open_game() else {
        return;
    };
    game.start_map_event_by_name("SampleMapA", 0)
        .expect("SampleMapA is a registered map");
    let mut atlas = Atlas::new();

    // Neutral tint: every tile quad keeps the default [1, 1, 1].
    let neutral = game.tile_quads(&mut atlas);
    assert!(!neutral.is_empty());
    assert!(neutral.iter().all(|quad| quad.tint == [1.0, 1.0, 1.0]));

    // The Dungeon darkening (R40 G40 B30), applied instantly (0 frames):
    // DxLib SetDrawBright maps 40% to 102/255 and 30% to 77/255.
    game.screen_tint.set(0x0028_281E, 0);
    let tinted = game.tile_quads(&mut atlas);
    assert_eq!(
        tinted.len(),
        neutral.len(),
        "tinting leaves the geometry alone"
    );
    for quad in &tinted {
        assert!(
            (quad.tint[0] - 102.0 / 255.0).abs() < 1e-5,
            "red {}",
            quad.tint[0]
        );
        assert!(
            (quad.tint[1] - 102.0 / 255.0).abs() < 1e-5,
            "green {}",
            quad.tint[1]
        );
        assert!(
            (quad.tint[2] - 77.0 / 255.0).abs() < 1e-5,
            "blue {}",
            quad.tint[2]
        );
    }

    // 150% channels clamp to 255 = neutral, they do not multiply by 1.5.
    game.screen_tint.set(0x0096_C896, 0);
    let clamped = game.tile_quads(&mut atlas);
    assert!(clamped.iter().all(|quad| quad.tint == [1.0, 1.0, 1.0]));

    // A later neutral 151 restores the map.
    game.screen_tint.set(0x0064_6464, 0);
    let restored = game.tile_quads(&mut atlas);
    assert!(restored.iter().all(|quad| quad.tint == [1.0, 1.0, 1.0]));

    // A flash is an overlay, never a sprite multiplier.
    game.screen_tint.set(0x0196_C896, 20);
    let flashed = game.tile_quads(&mut atlas);
    assert!(flashed.iter().all(|quad| quad.tint == [1.0, 1.0, 1.0]));
    let overlays = game.screen_overlays();
    assert_eq!(overlays.len(), 1, "one flash overlay");
    assert_eq!(
        overlays[0].layer,
        wolf_game::OverlayLayer::Colour([255, 255, 255])
    );
    assert!((overlays[0].alpha - 1.0).abs() < 1e-6);
}
