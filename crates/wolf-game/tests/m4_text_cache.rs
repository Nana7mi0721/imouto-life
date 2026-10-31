//! M4: the per-picture text layout cache (docs/M4_PERF.md candidate 3).
//!
//! Game::text_quads used to lay every visible text picture out again on every
//! frame. The cache keeps the last Vec<TextQuad> under a key that covers the
//! resolved markup (variables, database cells and palette colours included),
//! the base position, the anchor, the alpha and the installed font generation.
//! These tests pin the two properties that matter: a static picture is laid out
//! once and reused, and every input that changes the quads invalidates the
//! entry instead of serving stale text. They skip when work/Data is absent,
//! like the rest of the data-gated suite.

use std::path::{Path, PathBuf};

use wolf_game::{Game, Picture, PictureKind};

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

/// A game whose screen holds exactly one synthetic text picture.
fn game_with_text(text: &str) -> Option<Game> {
    let root = data_root();
    let mut game = match Game::new(root) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: cannot open data root: {err}");
            return None;
        }
    };
    game.screen.clear();
    let mut picture = Picture::new(900);
    picture.kind = PictureKind::Text;
    picture.text = text.to_owned();
    picture.x = 10;
    picture.y = 20;
    game.screen.insert(picture);
    Some(game)
}

fn texts(quads: &[wolf_game::atlas::TextQuad]) -> String {
    quads.iter().map(|quad| quad.text.as_str()).collect()
}

fn first_ttf(root: &Path) -> Option<Vec<u8>> {
    for entry in std::fs::read_dir(root).ok()? {
        let path = entry.ok()?.path();
        let is_font = path
            .extension()
            .and_then(|ext| ext.to_str())
            .is_some_and(|ext| ext.eq_ignore_ascii_case("ttf"));
        if is_font {
            if let Ok(bytes) = std::fs::read(&path) {
                return Some(bytes);
            }
        }
    }
    None
}

#[test]
fn a_static_text_picture_is_laid_out_once() {
    let Some(game) = game_with_text("信赖 25") else {
        return;
    };

    let first = game.text_quads();
    assert!(
        !first.is_empty(),
        "the synthetic label lays out at least one run"
    );
    let after_first = game.text_cache_stats();
    assert_eq!(after_first.misses, 1, "first frame is a miss");
    assert_eq!(after_first.hits, 0);
    assert_eq!(after_first.pictures, 1);

    let second = game.text_quads();
    assert_eq!(
        second, first,
        "a cached frame returns the identical quad list"
    );
    let after_second = game.text_cache_stats();
    assert_eq!(after_second.hits, 1, "second frame hits the cache");
    assert_eq!(after_second.misses, 1, "no relayout happened");
    assert_eq!(after_second.pictures, 1);
}

#[test]
fn a_variable_text_change_invalidates_the_cache() {
    let Some(mut game) = game_with_text("\\v[0]") else {
        return;
    };
    game.vm.vars.set(0, 7);
    let seven = game.text_quads();
    assert_eq!(
        texts(&seven),
        "7",
        "the escape resolves through the normal variable"
    );

    game.vm.vars.set(0, 8);
    let eight = game.text_quads();
    assert_eq!(
        texts(&eight),
        "8",
        "the variable change must reach the quads"
    );
    let after_change = game.text_cache_stats();
    assert_eq!(
        after_change.misses, 2,
        "the changed resolved text is a new layout"
    );
    assert_eq!(after_change.hits, 0);

    let eight_again = game.text_quads();
    assert_eq!(eight_again, eight);
    let after_again = game.text_cache_stats();
    assert_eq!(after_again.hits, 1, "an unchanged second frame is a hit");
    assert_eq!(after_again.misses, 2);
}

#[test]
fn moving_a_picture_rebuilds_its_quads() {
    let Some(mut game) = game_with_text("位置") else {
        return;
    };
    let before = game.text_quads();
    let stats_before = game.text_cache_stats();

    let mut moved = game.screen.get(900).expect("synthetic picture").clone();
    moved.x += 5;
    game.screen.insert(moved);

    let after = game.text_quads();
    assert_ne!(after, before, "the quad rect follows the picture x");
    let stats_after = game.text_cache_stats();
    assert_eq!(stats_after.misses, stats_before.misses + 1, "a move misses");
    assert_eq!(stats_after.hits, stats_before.hits);
}

#[test]
fn installing_font_metrics_invalidates_cached_layouts() {
    let Some(mut game) = game_with_text("字体缓存") else {
        return;
    };
    let first = game.text_quads();
    let before = game.text_cache_stats();
    assert_eq!(before.misses, 1);

    let Some(bytes) = first_ttf(&data_root()) else {
        eprintln!("skipping font-metrics half: no .ttf in the data root");
        return;
    };
    assert!(game.set_font_metrics(bytes), "the shipped font parses");

    let after = game.text_quads();
    let after_stats = game.text_cache_stats();
    assert_eq!(
        after_stats.misses,
        before.misses + 1,
        "a new advance table misses"
    );
    assert_eq!(after_stats.hits, before.hits);
    assert_eq!(
        after.len(),
        first.len(),
        "the same picture keeps one run set"
    );
}
