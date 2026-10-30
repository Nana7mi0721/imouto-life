//! The map tile layer is drawn underneath the picture layer.
//!
//! A WOLF map is not a walkable scene in this game — the registered maps have no page
//! graphics — but the tile layer still exists and must be composed first: a full-screen
//! picture covers it, while transparent or absent pictures reveal it. This test pins the
//! measured SampleMapA layer: 64x36 cells, 3 layers, 27,648 quads.

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
fn sample_map_a_builds_its_three_tile_layers() {
    let Some(mut game) = open_game() else {
        return;
    };
    game.start_map_event_by_name("SampleMapA", 0)
        .expect("SampleMapA is a registered map");
    let mut atlas = Atlas::new();
    let quads = game.tile_quads(&mut atlas);
    assert_eq!(quads.len(), 27_648, "64x36 cells x 3 layers, all opaque");
    // Autotile cells are four 8x8 quadrant sprites, base tiles are one 16x16 sprite;
    // either way the three layers together must cover the whole 1024x576 screen.
    let covered: f32 = quads.iter().map(|quad| quad.rect[2] * quad.rect[3]).sum();
    assert_eq!(covered, (1024 * 576 * 3) as f32);
}
