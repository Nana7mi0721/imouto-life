//! Capacity contract for the atlas page.
//!
//! These tests use only the crate's public API, so they also pin the shape of what
//! `crates/wolf-cli` is allowed to rely on: `Atlas::new()` is the shipped page, and
//! anything it refuses comes back through `Atlas::take_warnings()` instead of vanishing.
//!
//! The numbers are taken from docs/HSCENE.md 4.1: a retail save (SaveData08) restores 84
//! picture records, and the three stacked character layers alone want 129% of a 2048
//! pixel page. The old page size dropped them silently; this file is the regression test
//! for that.

use wolf_game::assets::ImageData;
use wolf_game::atlas::{Atlas, AtlasMissReason, ATLAS_SIZE};

/// A solid image, cheap to build and easy to tell apart in the packed page.
fn image(w: u32, h: u32, fill: u8) -> ImageData {
    ImageData::new(w, h, vec![fill; (w * h * 4) as usize]).expect("image")
}

#[test]
fn the_shipped_page_is_the_one_the_retail_saves_need() {
    assert_eq!(ATLAS_SIZE, 4096);
    let atlas = Atlas::new();
    assert_eq!(atlas.size(), [ATLAS_SIZE, ATLAS_SIZE]);
    assert!(atlas.is_empty());
}

#[test]
fn three_stacked_character_layers_that_overflowed_a_2048_page_fit_on_the_shipped_page() {
    // Each layer is a 540x540 character portrait; the retail save stacks several of them
    // on top of a full-screen background and a UI frame. 129% of 2048x2048 is 5.41 Mpx,
    // so 2048 must refuse the set while 4096 accepts all of it.
    let mut layers = vec![("background", image(1024, 576, 0x20))];
    for index in 0..14 {
        layers.push((
            Box::leak(format!("layer{index}").into_boxed_str()) as &str,
            image(540, 540, index as u8),
        ));
    }
    let area: u64 = layers
        .iter()
        .map(|(_, img)| u64::from(img.width) * u64::from(img.height))
        .sum();
    assert!(
        area > 2048 * 2048,
        "the fixture must overflow a 2048 page, area {area}"
    );
    assert!(
        area < 4096 * 4096,
        "the fixture must fit a 4096 page, area {area}"
    );

    let mut small = Atlas::with_size(2048, 2048);
    let mut small_packed = 0;
    for (name, img) in &layers {
        if small.add(name, img).is_some() {
            small_packed += 1;
        }
    }
    assert!(
        small_packed < layers.len(),
        "2048 packed {small_packed}/{} layers, the fixture no longer overflows",
        layers.len()
    );
    assert!(
        !small.misses().is_empty(),
        "the layers 2048 dropped must be on the record"
    );

    let mut shipped = Atlas::new();
    for (name, img) in &layers {
        shipped.add(name, img).expect("4096 holds the whole set");
    }
    assert!(shipped.misses().is_empty(), "nothing was refused");
    assert_eq!(shipped.len(), layers.len());
}

#[test]
fn a_refused_picture_reaches_the_caller_as_a_warning_with_its_name() {
    // A page far too small for the art, which is the situation the retail saves hit.
    let mut atlas = Atlas::with_size(64, 64);
    let big = image(256, 256, 0x7F);
    assert!(atlas.add("Picture/stand_imouto.png", &big).is_none());
    let warnings = atlas.take_warnings();
    assert_eq!(warnings, ["atlas too-large: Picture/stand_imouto.png"]);
    assert_eq!(atlas.misses()[..], [] as [wolf_game::atlas::AtlasMiss; 0]);
}

#[test]
fn a_full_page_names_the_pictures_it_could_not_take() {
    let mut atlas = Atlas::with_size(32, 32);
    atlas.add("first", &image(32, 16, 1)).expect("first");
    atlas.add("second", &image(32, 16, 2)).expect("second");
    // The page is now full; both of these are refused and both are named.
    assert!(atlas.add("third", &image(32, 16, 3)).is_none());
    assert!(atlas.add("fourth", &image(16, 16, 4)).is_none());
    assert_eq!(atlas.misses()[0].reason, AtlasMissReason::Full);
    let warnings = atlas.take_warnings();
    assert_eq!(
        warnings,
        ["atlas full: third", "atlas full: fourth"],
        "each refused picture is named once"
    );
    // A full page keeps answering for what it already holds; only new work is refused.
    assert!(atlas.entry("first").is_some());
    assert_eq!(atlas.len(), 2);
}

#[test]
fn draining_the_warnings_leaves_the_atlas_usable() {
    let mut atlas = Atlas::new();
    atlas.add("ok", &image(64, 64, 9)).expect("ok");
    assert!(atlas.take_warnings().is_empty());
    // Refuse one, drain, refuse it again: the second report must still appear, because a
    // per-frame caller needs to see a persistent problem every frame it happens.
    assert!(atlas.add("bad", &image(0, 0, 0)).is_none());
    assert_eq!(atlas.take_warnings(), ["atlas empty: bad"]);
    assert!(atlas.add("bad", &image(0, 0, 0)).is_none());
    assert_eq!(atlas.take_warnings(), ["atlas empty: bad"]);
}
