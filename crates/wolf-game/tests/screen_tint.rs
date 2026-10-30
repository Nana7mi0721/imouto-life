//! `151 ChangeColor` tints the map and the screen-layer pictures, and the capture path
//! bakes that multiplier into the quad tints. This pins the tile half end to end: a
//! neutral run leaves every quad untinted, and an installed colour multiplies them.

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
fn screen_tint_multiplies_the_tile_layer() {
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

    // The Dungeon flash colour (R150 G200 B150), applied instantly (0 frames).
    game.screen_tint.set(0x0096_C896, 0);
    let tinted = game.tile_quads(&mut atlas);
    assert_eq!(
        tinted.len(),
        neutral.len(),
        "tinting leaves the geometry alone"
    );
    for quad in &tinted {
        assert!((quad.tint[0] - 1.5).abs() < 1e-5, "red {}", quad.tint[0]);
        assert!((quad.tint[1] - 2.0).abs() < 1e-5, "green {}", quad.tint[1]);
        assert!((quad.tint[2] - 1.5).abs() < 1e-5, "blue {}", quad.tint[2]);
    }

    // A later neutral 151 restores the map.
    game.screen_tint.set(0x0064_6464, 0);
    let restored = game.tile_quads(&mut atlas);
    assert!(restored.iter().all(|quad| quad.tint == [1.0, 1.0, 1.0]));
}
