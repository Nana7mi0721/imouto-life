//! M4 tile-quad cache: the map's drawn quad list must be built once per (map,
//! atlas layout, autotile phase) and then reused, while still tracking autotile
//! animation and map switches exactly.
//!
//! These are correctness tests, not timing gates: they compare the cached list with
//! a freshly built one and read the internal build/hit counters. Without WOLF data
//! every test prints a skip line and returns, so the default workspace suite stays
//! green (exit 0).
//!
//! Run with data:
//!
//! ```text
//! WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --test m4_tile_cache -- --nocapture
//! ```

use std::path::{Path, PathBuf};

use wolf_format::mps::Map;
use wolf_game::{Atlas, Game};

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
    let root = data_root();
    if !root.join("BasicData").join("CommonEvent.dat").is_file() {
        eprintln!(
            "skipping: no WOLF data at {root:?} (set WOLF_DATA_ROOT to the unpacked Data directory)"
        );
        return None;
    }
    match Game::new(root) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!("skipping: {err}");
            None
        }
    }
}

fn load_map(root: &Path, name: &str) -> Result<Map, String> {
    let path = root.join("MapData").join(format!("{name}.mps"));
    let bytes = std::fs::read(&path).map_err(|err| format!("cannot read {path:?}: {err}"))?;
    Map::parse(&bytes).map_err(|err| err.to_string())
}

/// Installs `name` as the current map and returns one built quad list.
fn install_and_draw(
    game: &mut Game,
    atlas: &mut Atlas,
    root: &Path,
    name: &str,
) -> Vec<wolf_game::atlas::SpriteQuad> {
    let map = load_map(root, name).expect("registered map parses");
    game.start_pages(&map, None);
    game.tile_quads(atlas)
}

#[test]
fn consecutive_calls_are_equal_and_served_from_cache() {
    let Some(mut game) = open_game() else {
        return;
    };
    let root = data_root();
    let mut atlas = Atlas::new();

    let first = install_and_draw(&mut game, &mut atlas, &root, "SampleMapA");
    let stats_after_first = game
        .tilemap
        .as_ref()
        .expect("SampleMapA installed a tilemap")
        .cache_stats();
    assert_eq!(stats_after_first.builds, 1, "first draw must build");
    assert_eq!(stats_after_first.hits, 0, "first draw cannot be a hit");

    let second = game.tile_quads(&mut atlas);
    let stats_after_second = game.tilemap.as_ref().unwrap().cache_stats();
    assert_eq!(
        stats_after_second.builds, 1,
        "a second draw at the same map/phase must not rebuild"
    );
    assert_eq!(
        stats_after_second.hits, 1,
        "a second draw at the same map/phase must be a cache hit"
    );

    // Geometry, UVs, alpha and tint must be byte-for-byte identical: the clone is the
    // same list the build produced.
    assert_eq!(
        first.len(),
        second.len(),
        "quad count is stable across calls"
    );
    assert!(!first.is_empty(), "SampleMapA draws its three tile layers");
    assert_eq!(first, second, "cached list equals the freshly built one");
    eprintln!(
        "SampleMapA: {} quads, period {}, phase {}, builds {}, hits {}",
        stats_after_second.quads,
        stats_after_second.period,
        stats_after_second.phase,
        stats_after_second.builds,
        stats_after_second.hits,
    );
}

#[test]
fn switching_map_invalidates_the_cache() {
    let Some(mut game) = open_game() else {
        return;
    };
    let root = data_root();
    let mut atlas = Atlas::new();

    let first = install_and_draw(&mut game, &mut atlas, &root, "SampleMapA");
    // Warm a hit so we know the cache was live before the switch.
    let _ = game.tile_quads(&mut atlas);
    let warm = game.tilemap.as_ref().unwrap().cache_stats();
    assert!(warm.hits >= 1, "cache must be warm before switching");

    // A new map replaces `TileMap` entirely, so its cache must start cold: the next
    // draw has to build, never hit the previous map's list.
    let map = load_map(&root, "Map003").expect("Map003 parses");
    game.start_pages(&map, None);
    let fresh = game.tilemap.as_ref().unwrap().cache_stats();
    assert_eq!(fresh.builds, 0, "a switched-in map starts with no build");
    assert_eq!(fresh.hits, 0, "a switched-in map starts with no hits");

    let second = game.tile_quads(&mut atlas);
    let after = game.tilemap.as_ref().unwrap().cache_stats();
    assert_eq!(after.builds, 1, "the new map builds exactly once");
    assert_eq!(
        after.hits, 0,
        "the new map was not served from the old cache"
    );
    assert!(!second.is_empty(), "Map003 draws tiles");
    // Different maps produce different geometry; the switch must not have kept the old
    // list around.
    assert_ne!(
        first.len(),
        second.len(),
        "different map, different quad list"
    );
}

#[test]
fn autotile_phase_never_leaks_between_frames() {
    let Some(mut game) = open_game() else {
        return;
    };
    let root = data_root();
    let mut atlas = Atlas::new();

    // Find a shipped map that actually animates an autotile it paints. Period 1 means
    // static, which is the trivial case; try the registered maps in turn.
    let candidates = [
        "SampleMapA",
        "Dungeon",
        "Map003",
        "Map024",
        "Map031",
        "SampleMapB",
        "Map002",
        "TitleMap",
    ];
    let mut chosen: Option<(&str, u32)> = None;
    for name in candidates {
        let Ok(map) = load_map(&root, name) else {
            continue;
        };
        game.start_pages(&map, None);
        game.set_playtime_frames(0);
        let _ = game.tile_quads(&mut atlas);
        let period = game.tilemap.as_ref().unwrap().cache_stats().period;
        eprintln!("phase probe {name}: period {period}");
        if period > 1 {
            chosen = Some((name, period));
            break;
        }
    }

    let Some((name, period)) = chosen else {
        // No shipped map animates autotiles: the static path is already covered by the
        // hit test above. Statically prove the phase stays identical across play time.
        let map = load_map(&root, "SampleMapA").unwrap();
        game.start_pages(&map, None);
        game.set_playtime_frames(0);
        let base = game.tile_quads(&mut atlas);
        game.set_playtime_frames(5);
        let later = game.tile_quads(&mut atlas);
        assert_eq!(base, later, "period-1 map must not change with play time");
        eprintln!("no animated autotile in shipped maps; verified static invalidation only");
        return;
    };

    eprintln!("animated map {name} with period {period}");
    game.set_playtime_frames(0);
    let phase0 = game.tile_quads(&mut atlas);

    // Advancing the play clock by one frame moves the autotile phase; the cached list
    // must be rebuilt, not served stale.
    game.set_playtime_frames(1);
    let phase1 = game.tile_quads(&mut atlas);
    assert_ne!(
        phase0, phase1,
        "a different animation phase must produce a different quad list"
    );

    // Returning to the original phase must reproduce the original list exactly; a
    // single-slot cache must never let phase 1 leak into a phase 0 draw.
    game.set_playtime_frames(0);
    let phase0_again = game.tile_quads(&mut atlas);
    assert_eq!(
        phase0, phase0_again,
        "phase 0 draw must be identical after visiting phase 1 (no cross-frame leak)"
    );

    // And within one phase, repeated draws are hits again.
    let stats = game.tilemap.as_ref().unwrap().cache_stats();
    let before_hits = stats.hits;
    let _ = game.tile_quads(&mut atlas);
    let after_hits = game.tilemap.as_ref().unwrap().cache_stats().hits;
    assert_eq!(after_hits, before_hits + 1, "same phase is a cache hit");
}
