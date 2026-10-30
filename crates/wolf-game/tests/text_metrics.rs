//! Real font advances move a right-aligned text picture to where the retail HUD puts it.
//!
//! The unit tests in `wolf_game::fontmetrics` prove the metrics; this drives the whole
//! `Game::text_quads` path so a regression that stops passing them into layout is caught.

use std::path::PathBuf;

use wolf_game::picture::{Picture, PictureKind};
use wolf_game::Game;

fn data_root() -> PathBuf {
    let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    path.pop();
    path.pop();
    path.push("work/full");
    path
}

fn lolita() -> Option<Vec<u8>> {
    std::fs::read(data_root().join("Fonts/Lolita.ttf")).ok()
}

#[test]
fn right_aligned_text_uses_the_real_font_advance_when_available() {
    let Some(font) = lolita() else {
        eprintln!("skipping: work/full/Fonts/Lolita.ttf is not present");
        return;
    };
    let mut game = Game::new(data_root()).expect("work/full loads");
    let mut picture = Picture::new(6200);
    picture.kind = PictureKind::Text;
    picture.text = "\\f[24]21:40".to_string();
    picture.x = 140;
    picture.y = 0;
    picture.anchor = 3; // right edge on x
    game.screen.insert(picture);

    let fallback = game.text_quads();
    assert_eq!(fallback.len(), 1);
    let half_em_left = fallback[0].rect[0];
    // Five half-em glyphs at 24 px => 60 px, so the block starts at 80.
    assert!(
        (half_em_left - 80.0).abs() < 0.01,
        "fallback left = {half_em_left}"
    );

    assert!(game.set_font_metrics(font), "Lolita.ttf is a usable font");
    let shaped = game.text_quads();
    assert_eq!(shaped.len(), 1);
    let real_left = shaped[0].rect[0];
    // The real run is 56.31 px, so the left edge lands on 83.69 - about 4 px right of
    // the half-em estimate, exactly the retail screenshot's ink position.
    assert!((real_left - 83.69).abs() < 0.1, "shaped left = {real_left}");
    assert!(real_left > half_em_left + 3.0);
}
