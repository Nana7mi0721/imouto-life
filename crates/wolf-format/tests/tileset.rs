//! Integration test: `TileSetData.dat` parses byte-exactly.
//!
//! Expected numbers come from `docs/FORMAT_SPEC.md` §7.4 and `docs/BASELINE.json`.

use std::path::PathBuf;

use wolf_format::tileset::{TilePassability, TileSetData};

/// Data root, resolved the way `wolf-cli` does it (see `tests/mps.rs`).
fn data_root() -> PathBuf {
    let raw = match std::env::var("WOLF_DATA_ROOT") {
        Ok(value) if !value.is_empty() => PathBuf::from(value),
        _ => PathBuf::from("work/full"),
    };
    if raw.is_absolute() {
        return raw;
    }
    let manifest = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    let workspace = manifest
        .parent()
        .and_then(|crates| crates.parent())
        .unwrap_or(&manifest);
    let candidate = workspace.join(&raw);
    if candidate.is_dir() {
        candidate
    } else {
        raw
    }
}

fn load() -> Option<Vec<u8>> {
    std::fs::read(data_root().join("BasicData").join("TileSetData.dat")).ok()
}

#[test]
fn tileset_data_matches_the_spec_table() {
    let Some(data) = load() else {
        eprintln!("skipping: no data under {}", data_root().display());
        return;
    };
    let parsed = TileSetData::parse(&data).expect("TileSetData.dat parses");

    assert_eq!(parsed.version, 209, "container version");
    assert_eq!(parsed.footer, 0xCF, "footer");
    assert_eq!(parsed.tilesets.len(), 6, "tileset count");

    // Base image / passability count per tileset, measured from this game's
    // TileSetData.dat. Names other than tileset 4 are Shift-JIS and decode
    // lossily (this game's data, unlike the sister game's, is not UTF-8 here),
    // so only the clean ASCII name (tileset 4) is asserted by value below.
    let expected: [(&str, usize); 6] = [
        ("MapChip/[Base]BaseChip_pipo.png", 2360),
        ("MapChip/[Base]BaseChip_pipo.png", 2360),
        ("MapChip/[Base]BaseChip_pipo.png", 2360),
        ("MapChip/[Base]WorldMap_pipo.png", 200),
        ("MapChip/kiri_project.png", 2360),
        ("MapChip/map_parts01.png", 1632),
    ];
    for (index, (base, passable)) in expected.iter().enumerate() {
        let tileset = parsed.get(index as u32).expect("tileset exists");
        assert_eq!(&tileset.base_image, base, "tileset {index} base image");
        assert_eq!(
            tileset.passability.len(),
            *passable,
            "tileset {index} passability count"
        );
        assert_eq!(tileset.tags.len(), *passable, "tileset {index} tag count");
        assert_eq!(
            tileset.autotiles.len(),
            15,
            "tileset {index} autotile slots"
        );
        assert_eq!(
            tileset.raw_autotile_bytes.len(),
            15,
            "tileset {index} raw autotile slots"
        );
    }
    assert_eq!(parsed.tilesets[4].name, "kiri", "tileset 4 clean name");
    assert!(parsed.get(6).is_none(), "no seventh tileset");

    // Tileset 0 fills all 15 autotile slots (this game uses 15-slot autotile sets).
    let filled: Vec<&str> = parsed.tilesets[0]
        .autotiles
        .iter()
        .filter(|name| !name.is_empty())
        .map(String::as_str)
        .collect();
    assert_eq!(filled.len(), 15, "tileset 0 configured autotiles");
    assert_eq!(
        filled,
        [
            "MapChip/[A]Grass1-Dirt1_pipo.png",
            "MapChip/[A]Grass1-Grass2_pipo.png",
            "MapChip/[A]Grass1-Grass3_pipo.png",
            "MapChip/[A]Water2_pipo.png",
            "MapChip/[A]Water5_pipo.png",
            "MapChip/[A]Water7_pipo.png",
            "MapChip/[A]WaterFall2_pipo.png",
            "MapChip/[A]Flower_pipo.png",
            "MapChip/[A]Snow_pipo.png",
            "MapChip/[A]Snow_Grass4_pipo.png",
            "MapChip/[A]Snow_Dirt2_pipo.png",
            "MapChip/[A]Ice2_pipo.png",
            "MapChip/[A]Dirt1-Dirt2_pipo.png",
            "MapChip/[A]Wall-Up1_pipo.png",
            "MapChip/[A]Wall-Up2_pipo.png",
        ],
        "tileset 0 autotile list"
    );
}

#[test]
fn passability_words_keep_their_undocumented_bits() {
    let Some(data) = load() else {
        eprintln!("skipping: no data under {}", data_root().display());
        return;
    };
    let parsed = TileSetData::parse(&data).expect("TileSetData.dat parses");

    // The spec says bits 8..13 and the upper half must be zero; only the upper
    // half actually is. Bits 8..9 carry values 1, 2 and 3, so they are exposed
    // rather than rejected (see docs/FORMAT_SPEC.md §7.4 TODO(verify)).
    let mut saw_reserved = false;
    for (index, tileset) in parsed.tilesets.iter().enumerate() {
        for (tile, word) in tileset.passability.iter().enumerate() {
            assert_eq!(
                word.raw >> 16,
                0,
                "tileset {index} tile {tile}: upper half must be zero"
            );
            assert!(
                !word.downarrow && !word.triangle,
                "tileset {index} tile {tile}: bits 14/15 are zero in this game"
            );
            if word.na != 0 {
                saw_reserved = true;
                assert!(
                    word.na <= 3,
                    "tileset {index} tile {tile}: reserved bits {:#X}",
                    word.na
                );
            }
            // Decoding must be lossless: the raw word is kept alongside the flags.
            assert_eq!(TilePassability::decode(word.raw), *word);
        }
    }
    assert!(
        saw_reserved,
        "reserved bits 8..9 carry real data in this game's tilesets"
    );
}

#[test]
fn corrupt_autotile_names_are_kept_as_raw_bytes() {
    let Some(data) = load() else {
        eprintln!("skipping: no data under {}", data_root().display());
        return;
    };
    let parsed = TileSetData::parse(&data).expect("TileSetData.dat parses");

    // Tileset 5 ships 10 autotile names that are not valid UTF-8 (double-encoded
    // Shift-JIS residue). They must survive as raw bytes and decode lossily.
    let mut invalid = 0;
    for tileset in &parsed.tilesets {
        for (index, raw) in tileset.raw_autotile_bytes.iter().enumerate() {
            if std::str::from_utf8(raw).is_err() {
                invalid += 1;
                assert!(
                    !tileset.autotiles[index].is_empty(),
                    "lossy decode of a corrupt name must not be dropped"
                );
                assert!(
                    tileset.autotiles[index].contains('\u{FFFD}'),
                    "lossy decode must mark the replacement characters"
                );
            }
        }
    }
    assert_eq!(invalid, 10, "corrupt autotile names in tileset 5");

    // A clean tileset round-trips byte for byte.
    for (index, raw) in parsed.tilesets[0].raw_autotile_bytes.iter().enumerate() {
        assert_eq!(
            std::str::from_utf8(raw).map(str::to_owned).ok().as_deref(),
            Some(parsed.tilesets[0].autotiles[index].as_str()),
            "tileset 0 autotile {index} round-trips"
        );
    }
}

#[test]
fn tags_match_the_measured_distribution() {
    let Some(data) = load() else {
        eprintln!("skipping: no data under {}", data_root().display());
        return;
    };
    let parsed = TileSetData::parse(&data).expect("TileSetData.dat parses");

    // Tilesets 0-2 use no tags at all; tileset 3 tags 185 tiles with 0 and one
    // tile with each of 1..=15; tilesets 4 and 5 are mostly untagged but use
    // tags 1..=8 and 1..=15 respectively.
    for index in 0..3 {
        assert!(
            parsed.tilesets[index].tags.iter().all(|&tag| tag == 0),
            "tileset {index} has no tags"
        );
    }
    let world_map = &parsed.tilesets[3];
    let zeros = world_map.tags.iter().filter(|&&tag| tag == 0).count();
    assert_eq!(zeros, 185, "tileset 3 untagged tiles");
    for tag in 1..=15u8 {
        assert_eq!(
            world_map.tags.iter().filter(|&&t| t == tag).count(),
            1,
            "tileset 3 tag {tag}"
        );
    }
    assert!(parsed.tilesets[4].tags.contains(&8), "tileset 4 uses tag 8");
    assert!(
        parsed.tilesets[5].tags.contains(&15),
        "tileset 5 uses tag 15"
    );
}
