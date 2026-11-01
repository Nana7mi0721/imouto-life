//! End-to-end checks that mod patch files reach the database and asset loaders.
//!
//! Each test builds a throwaway data root and mod overlay under
//! target/test-scratch, drops a patches/*.patch file, then loads the game data
//! through the normal public API. No shipped game data is required.

use std::path::{Path, PathBuf};
use std::sync::atomic::{AtomicU64, Ordering};

use wolf_format::database::{Database, DatabaseType, FieldKind, Row};
use wolf_game::assets::{AssetError, Assets};
use wolf_game::db::{Container, Databases};

fn scratch_dir(tag: &str) -> PathBuf {
    static COUNTER: AtomicU64 = AtomicU64::new(0);
    let unique = COUNTER.fetch_add(1, Ordering::Relaxed);
    let mut dir = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    dir.pop(); // crates/
    dir.pop(); // workspace root
    dir.push("target");
    dir.push("test-scratch");
    dir.push(format!("patch-it-{tag}-{}-{unique}", std::process::id()));
    let _ = std::fs::remove_dir_all(&dir);
    std::fs::create_dir_all(&dir).expect("scratch dir");
    dir
}

/// One type, one row: numeric column 0 holds 1, string column 1 holds "a".
fn sample_database_bytes() -> Vec<u8> {
    Database::synthetic(
        0xC1,
        vec![DatabaseType::synthetic(
            0,
            vec![FieldKind::Num(0), FieldKind::Str(0)],
            vec![Row {
                numbers: vec![1],
                strings: vec!["a".to_owned()],
            }],
        )],
        0xC1,
    )
    .to_bytes()
}

fn write_base_database(base: &Path) -> PathBuf {
    let basic = base.join("BasicData");
    std::fs::create_dir_all(&basic).expect("BasicData dir");
    let path = basic.join("DataBase.dat");
    std::fs::write(&path, sample_database_bytes()).expect("write DataBase.dat");
    path
}

fn write_patch(mod_root: &Path, name: &str, body: &str) {
    let dir = mod_root.join("patches");
    std::fs::create_dir_all(&dir).expect("patches dir");
    std::fs::write(dir.join(name), body).expect("write patch");
}

#[test]
fn record_patch_changes_a_database_cell() {
    let dir = scratch_dir("record");
    let base = dir.join("base");
    write_base_database(&base);
    let mod_root = dir.join("mod");
    write_patch(
        &mod_root,
        "cells.patch",
        "file = DataBase.dat\n\
         type = 0\n\
         row = 0\n\
         column = 0\n\
         number = 42\n",
    );
    write_patch(
        &mod_root,
        "text.patch",
        "file = DataBase.dat\n\
         type = 0\n\
         row = 0\n\
         column = 1\n\
         text = a much longer patched value\n",
    );

    let dbs = Databases::load_with_overlays(&base.join("BasicData"), &[mod_root], (1024, 576));
    assert_eq!(
        dbs.num(Container::Data, 0, 0, 0),
        Some(42),
        "numeric record patch must land in the loaded table"
    );
    assert_eq!(
        dbs.text(Container::Data, 0, 0, 1),
        Some("a much longer patched value"),
        "a longer text patch must land in the loaded table"
    );
    let _ = std::fs::remove_dir_all(&dir);
}

#[test]
fn byte_patch_edits_a_database_before_parse() {
    let dir = scratch_dir("dbbytes");
    let base = dir.join("base");
    write_base_database(&base);
    let mod_root = dir.join("mod");
    // The first numeric cell sits at offset 39 in this minimal layout and holds
    // 1 (little-endian 01 00 00 00); rewrite it to 7 before parsing.
    write_patch(
        &mod_root,
        "num.patch",
        "file = DataBase.dat\n\
         offset = 39\n\
         expect = 01 00 00 00\n\
         replace = 07 00 00 00\n",
    );
    let dbs = Databases::load_with_overlays(&base.join("BasicData"), &[mod_root], (1024, 576));
    assert_eq!(
        dbs.num(Container::Data, 0, 0, 0),
        Some(7),
        "byte patch must change the parsed cell"
    );
    let _ = std::fs::remove_dir_all(&dir);
}

#[test]
fn a_mismatched_byte_patch_is_ignored() {
    let dir = scratch_dir("mismatch");
    let base = dir.join("base");
    write_base_database(&base);
    let mod_root = dir.join("mod");
    write_patch(
        &mod_root,
        "num.patch",
        "file = DataBase.dat\n\
         offset = 39\n\
         expect = AA BB CC DD\n\
         replace = 07 00 00 00\n",
    );
    let dbs = Databases::load_with_overlays(&base.join("BasicData"), &[mod_root], (1024, 576));
    assert_eq!(
        dbs.num(Container::Data, 0, 0, 0),
        Some(1),
        "a mismatched expect must leave the original value in place"
    );
    let _ = std::fs::remove_dir_all(&dir);
}

fn write_png(path: &Path) {
    if let Some(parent) = path.parent() {
        std::fs::create_dir_all(parent).expect("png dir");
    }
    let image = image::RgbaImage::from_pixel(2, 2, image::Rgba([200, 30, 90, 255]));
    image::DynamicImage::ImageRgba8(image)
        .save(path)
        .expect("write png");
}

#[test]
fn asset_byte_patch_applies_before_decode() {
    let dir = scratch_dir("assetdamage");
    let base = dir.join("base");
    write_png(&base.join("SystemFile").join("patchme.png"));
    let mod_root = dir.join("mod");
    // Zero the PNG signature so the decoder must reject the patched bytes.
    write_patch(
        &mod_root,
        "damage.patch",
        "file = SystemFile/patchme.png\n\
         offset = 0\n\
         expect = 89 50 4E 47\n\
         replace = 00 00 00 00\n",
    );
    let mut assets = Assets::with_overlays(&base, vec![mod_root]);
    let result = assets.load("SystemFile/patchme.png");
    assert!(
        matches!(result, Err(AssetError::Decode { .. })),
        "damage patch must reach the decoder, got {result:?}"
    );
    let _ = std::fs::remove_dir_all(&dir);
}

#[test]
fn asset_loads_when_patch_does_not_match() {
    let dir = scratch_dir("assetclean");
    let base = dir.join("base");
    write_png(&base.join("SystemFile").join("clean.png"));
    let mod_root = dir.join("mod");
    write_patch(
        &mod_root,
        "stale.patch",
        "file = SystemFile/clean.png\n\
         offset = 0\n\
         expect = DE AD BE EF\n\
         replace = 00 00 00 00\n",
    );
    let mut assets = Assets::with_overlays(&base, vec![mod_root]);
    let image = assets
        .load("SystemFile/clean.png")
        .expect("a non-matching patch must not break the image");
    assert_eq!(image.size(), (2, 2));
    let _ = std::fs::remove_dir_all(&dir);
}
