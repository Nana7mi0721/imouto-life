//! M3-F: whole-file byte fidelity of `Game::load_save -> Game::save_to`.
//!
//! `docs/M3_RUNTIME.md` §6 used to record a residual 1,863 bytes (SaveData01) and
//! 1,684 bytes (SaveData02) of difference after the vardb text fix. The cause was
//! `picture_to_record`: it rebuilt every `SavePart5_1` from the live screen, and a
//! `Picture` only models the geometry the renderer uses. A retail record also carries
//! script state that no canonical encoder can invent - `var2`/`var3`, `vals1`,
//! `vars19_36` (the `0x00646464` colour block), the per-kind trailing tables
//! (`vars40_43` .. `vars91_97`), `vars55_60`, `vars61_63`, and inside `vars7_18` the
//! unused word `[7]`, the last fade length `[8]`, the second scale word `[10]` and the
//! reserved word `[11]`.
//!
//! The loader now keeps the decoded record on the picture (`Picture::retained_record`)
//! and `picture_to_record` reuses it while the canonical record is unchanged. This file
//! pins:
//! * a full-save round trip is byte-identical (header checksum included);
//! * a second load -> save of the written file is byte-identical to the first;
//! * a repainted picture falls back to the canonical record instead of inheriting the
//!   retained numeric payload.
//!
//! Everything skips cleanly when `work/Data` is absent, so the default workspace run
//! stays exit 0.

use std::path::{Path, PathBuf};

use wolf_game::savegame::{picture_from_record, picture_to_record, read_save};
use wolf_game::Game;
use wolf_save::part5::SavePart5_1;
use wolf_save::SaveFile;

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

fn save_file(slot: u32) -> PathBuf {
    data_root()
        .join("Save")
        .join(format!("SaveData{slot:02}.sav"))
}

fn out_dir() -> PathBuf {
    let mut root = data_root();
    root.pop();
    root.pop();
    root.join("work").join("out")
}

/// Loads one shipped save into a fresh game and writes it back to `written`.
fn round_trip(slot: u32, written: &Path) -> Option<(Vec<u8>, Vec<u8>)> {
    let path = save_file(slot);
    if !path.is_file() {
        eprintln!("skipping: no save at {}", path.display());
        return None;
    }
    let original = std::fs::read(&path).expect("the shipped save is readable");
    let mut game = match Game::new(data_root()) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: {err}");
            return None;
        }
    };
    game.load_save(&path).expect("the shipped save loads");
    std::fs::create_dir_all(written.parent().unwrap()).expect("work/out is writable");
    let _ = std::fs::remove_file(written);
    game.save_to(written).expect("save_to writes the snapshot");
    let after = std::fs::read(written).expect("the written save is readable");
    let _ = std::fs::remove_file(written);
    Some((original, after))
}

/// Where one differing byte sits in the decrypted save stream.
#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
enum Region {
    /// The fixed 20-byte header, including the checksum byte at offset 2.
    Header(usize),
    /// Start byte, name and file version between the header and SavePart1.
    Preamble(usize),
    /// One of the seven typed segments.
    Chunk(&'static str, usize),
    /// The trailing end byte.
    EndByte(usize),
    /// Something outside every classified range (should not happen).
    Unknown(usize),
}

impl Region {
    fn label(self) -> &'static str {
        match self {
            Region::Header(_) => "header",
            Region::Preamble(_) => "preamble",
            Region::Chunk(name, _) => name,
            Region::EndByte(_) => "end byte",
            Region::Unknown(_) => "unknown",
        }
    }
}

/// Classifies every differing offset of two encrypted saves.
///
/// The cipher is a position-dependent XOR, so a plaintext difference shows up at the
/// same offset in the encrypted file; only the offsets matter here. Segment bounds come
/// from parsing the decrypted original, so the two files must have the same layout.
fn classify(original: &[u8], written: &[u8]) -> Vec<(usize, Region)> {
    let decrypted = wolf_save::decrypt(original).expect("the shipped save decrypts");
    let parsed = SaveFile::parse(original).expect("the shipped save parses");
    let first_part = parsed
        .chunks()
        .first()
        .map_or(wolf_save::CRYPT_START, |chunk| chunk.offset);
    let end_offset = parsed
        .chunks()
        .last()
        .map_or(decrypted.len(), |chunk| chunk.offset + chunk.len);
    let mut out = Vec::new();
    for (offset, (before, after)) in original.iter().zip(written).enumerate() {
        if before == after {
            continue;
        }
        let region = if offset < wolf_save::HEADER_LEN {
            Region::Header(offset)
        } else if offset < first_part {
            Region::Preamble(offset)
        } else if offset >= end_offset && offset < decrypted.len() {
            Region::EndByte(offset)
        } else {
            parsed
                .chunks()
                .iter()
                .find(|chunk| offset >= chunk.offset && offset < chunk.offset + chunk.len)
                .map_or(Region::Unknown(offset), |chunk| {
                    Region::Chunk(chunk.name, offset - chunk.offset)
                })
        };
        out.push((offset, region));
    }
    out
}

/// Fails with a classified report instead of a bare "bytes differ".
fn assert_identical(slot: u32, original: &[u8], written: &[u8]) {
    assert_eq!(
        original.len(),
        written.len(),
        "SaveData{slot:02}: the written file changed length"
    );
    let diffs = classify(original, written);
    if diffs.is_empty() {
        eprintln!(
            "SaveData{slot:02}: 0 differing byte(s) of {} (header checksum included)",
            original.len()
        );
        return;
    }
    let mut by_region: std::collections::BTreeMap<&'static str, Vec<usize>> =
        std::collections::BTreeMap::new();
    for (offset, region) in &diffs {
        by_region.entry(region.label()).or_default().push(*offset);
    }
    for (region, offsets) in &by_region {
        eprintln!(
            "SaveData{slot:02} {region}: {} differing byte(s), first offsets {:?}",
            offsets.len(),
            &offsets[..offsets.len().min(8)]
        );
    }
    panic!(
        "SaveData{slot:02}: {} byte(s) differ after load -> save ({:?})",
        diffs.len(),
        by_region.keys().collect::<Vec<_>>()
    );
}

#[test]
fn a_whole_game_load_then_save_is_byte_identical() {
    for slot in [1u32, 2] {
        let written = out_dir().join(format!("m3_byte_fidelity_{slot:02}.sav"));
        let Some((original, after)) = round_trip(slot, &written) else {
            return;
        };
        assert_identical(slot, &original, &after);
    }
}

#[test]
fn a_second_load_and_save_of_the_written_file_is_stable() {
    for slot in [1u32, 2] {
        let first_path = out_dir().join(format!("m3_bytes_first_{slot:02}.sav"));
        let Some((_original, first)) = round_trip(slot, &first_path) else {
            return;
        };
        // Feed the written file back through a fresh game and save again.
        let second_path = out_dir().join(format!("m3_bytes_second_{slot:02}.sav"));
        std::fs::create_dir_all(second_path.parent().unwrap()).expect("work/out is writable");
        std::fs::write(&first_path, &first).expect("the intermediate save is writable");
        let mut game = Game::new(data_root()).expect("game data loads");
        game.load_save(&first_path).expect("the written save loads");
        let _ = std::fs::remove_file(&first_path);
        let _ = std::fs::remove_file(&second_path);
        game.save_to(&second_path)
            .expect("the second save_to writes");
        let second = std::fs::read(&second_path).expect("the second save is readable");
        let _ = std::fs::remove_file(&second_path);
        assert_eq!(
            first.len(),
            second.len(),
            "SaveData{slot:02}: the second save changed length"
        );
        assert!(
            first == second,
            "SaveData{slot:02}: load -> save is not idempotent ({} byte(s) differ)",
            first.iter().zip(&second).filter(|(a, b)| a != b).count()
        );
    }
}

/// A record whose canonical fields are edited must not be written back from the
/// retained record: the numeric payload would be stale script state.
#[test]
fn an_edited_picture_falls_back_to_the_canonical_record() {
    let path = save_file(1);
    let Ok(save) = read_save(&path) else {
        eprintln!("skipping: no {}", path.display());
        return;
    };
    let record = save
        .part5
        .events
        .iter()
        .find(|record| record.var5 != 1 && record.vars19_36.iter().any(|word| *word != 0))
        .or_else(|| save.part5.events.iter().find(|record| record.var5 != 1))
        .expect("SaveData01 carries picture records");

    let mut picture = picture_from_record(record).expect("a picture record");
    picture.x += 1;

    // A freshly built picture with the same fields is the canonical encoder's output.
    let mut fresh = wolf_game::picture::Picture::new(picture.number);
    fresh.kind = picture.kind;
    fresh.file = picture.file.clone();
    fresh.text = picture.text.clone();
    fresh.x = picture.x;
    fresh.y = picture.y;
    fresh.split = picture.split;
    fresh.pattern_index = picture.pattern_index;
    fresh.scale = picture.scale;
    fresh.opacity = picture.opacity;
    fresh.blend = picture.blend;
    fresh.window = picture.window;
    fresh.anchor = picture.anchor;
    fresh.fade = picture.fade;

    let written = picture_to_record(&picture);
    let canonical = picture_to_record(&fresh);
    assert_ne!(
        written, *record,
        "a moved picture must not reuse the loaded record"
    );
    assert_eq!(
        written, canonical,
        "a moved picture must use exactly the canonical encoder output"
    );

    // The fields the canonical encoder does not model are back at their defaults.
    assert_eq!(written.vals1, [0; 6], "stale vals1 leaked into the record");
    assert_eq!(written.vars19_36, [0; 18], "stale colour block leaked");
    assert_eq!(written.vars55_60, [0; 6], "stale vars55_60 leaked");
    assert_eq!(written.vars61_63, [0; 3], "stale vars61_63 leaked");
    assert_eq!(written.vars7_18[7], u32::MAX);
    assert_eq!(written.vars7_18[11], 0);
    assert_eq!(written.var2, 0);
    assert_eq!(written.var3, 0);
}

/// The retained path must not resurrect stale numeric state after a save/load cycle:
/// the records the written file carries are the ones the next load retains.
#[test]
fn a_retained_record_is_the_written_record_on_the_next_load() {
    let path = save_file(1);
    let Ok(save) = read_save(&path) else {
        eprintln!("skipping: no {}", path.display());
        return;
    };
    let mut checked = 0usize;
    for record in &save.part5.events {
        let picture = picture_from_record(record).expect("a picture record");
        let written: SavePart5_1 = picture_to_record(&picture);
        assert_eq!(
            written, *record,
            "picture {}: an untouched picture was not written back verbatim",
            record.var1
        );
        checked += 1;
    }
    assert!(checked > 0, "SaveData01 carries picture records");
}
