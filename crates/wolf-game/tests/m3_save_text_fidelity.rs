//! M3-F: byte fidelity of text-picture payloads across load -> save.
//!
//! `docs/M3_MANUAL_ALIGNMENT.md` gap #9 used to record that a text picture's `md1`
//! stream was normalized by decode -> encode: the canonical encoder only knows the
//! `\E` / `\f[n]` / `\c[n]` spellings, while the shipped saves also contain a
//! `01 02 20` control escape and a second font-size form (`01 05 1d ..`). The loader
//! now keeps the original bytes next to the decoded text, and `picture_to_record`
//! reuses them while the text is untouched, so an unmodified load -> save preserves
//! every payload byte-for-byte.
//!
//! Measured before the fix: SaveData01 had 3 differing text records (35 text
//! pictures) and SaveData02 had 2 (35). After the fix both are 0. Pictures whose text
//! an event rewrites still go through the canonical encoder; that case is pinned
//! separately.
//!
//! Everything skips cleanly when work/Data is absent, so the default workspace run
//! stays exit 0.

use std::path::{Path, PathBuf};

use wolf_game::savegame::{
    decode_picture_text, encode_picture_text, picture_from_record, picture_to_record, read_save,
};
use wolf_game::Game;

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
    data_root().join("Save").join(format!("SaveData{slot:02}.sav"))
}

fn out_dir() -> PathBuf {
    let mut root = data_root();
    root.pop();
    root.pop();
    root.join("work").join("out")
}

/// Picture `number` -> original `md1` for every text record of a shipped save.
fn text_payloads(path: &Path) -> Option<Vec<(i32, Vec<u8>)>> {
    let save = read_save(path).ok()?;
    Some(
        save.part5
            .events
            .iter()
            .filter(|record| record.var5 == 1)
            .map(|record| (record.var1 as i32, record.md1.clone()))
            .collect(),
    )
}

#[test]
fn every_shipped_text_picture_round_trips_byte_for_byte() {
    for slot in [1u32, 2] {
        let path = save_file(slot);
        let Ok(save) = read_save(&path) else {
            eprintln!("skipping: no {}", path.display());
            return;
        };
        let mut checked = 0usize;
        for record in &save.part5.events {
            if record.var5 != 1 {
                continue;
            }
            let picture = picture_from_record(record).expect("a text record builds a picture");
            let again = picture_to_record(&picture);
            assert_eq!(
                again.md1, record.md1,
                "SaveData{slot:02} picture {}: the md1 stream changed across load -> save",
                record.var1
            );
            checked += 1;
        }
        assert!(checked > 0, "SaveData{slot:02} carries text pictures");
    }
}

#[test]
fn a_whole_game_load_then_save_keeps_every_text_payload() {
    let path = save_file(1);
    let Some(before) = text_payloads(&path) else {
        eprintln!("skipping: no {}", path.display());
        return;
    };
    assert!(before.len() > 30, "SaveData01 carries its text pictures");

    let mut game = Game::new(data_root()).expect("game data loads");
    game.load_save(&path).expect("SaveData01 loads");

    let out = out_dir().join("m3_text_fidelity.sav");
    std::fs::create_dir_all(out.parent().unwrap()).expect("work/out is writable");
    let _ = std::fs::remove_file(&out);
    game.save_to(&out).expect("save_to writes the snapshot");

    let after = text_payloads(&out).expect("the written save parses");
    let _ = std::fs::remove_file(&out);
    for (number, bytes) in &before {
        let written = after
            .iter()
            .find(|(n, _)| n == number)
            .unwrap_or_else(|| panic!("picture {number} disappeared from the saved screen"));
        assert_eq!(
            &written.1, bytes,
            "picture {number}: Game::save_to rewrote an untouched text payload"
        );
    }
}

#[test]
fn an_edited_loaded_picture_falls_back_to_the_canonical_encoder() {
    let path = save_file(1);
    let Ok(save) = read_save(&path) else {
        eprintln!("skipping: no {}", path.display());
        return;
    };
    let record = save
        .part5
        .events
        .iter()
        .find(|record| record.var5 == 1)
        .expect("a text picture exists");
    let mut picture = picture_from_record(record).expect("text picture");
    picture.text = "\\Echanged text 12:34".to_owned();
    let again = picture_to_record(&picture);
    assert_ne!(
        again.md1, record.md1,
        "a rewritten text must not reuse the loaded byte stream"
    );
    let decoded = decode_picture_text(&again.md1);
    assert_eq!(
        decoded, picture.text,
        "the canonical encoder round-trips the new text"
    );
}

#[test]
fn a_new_text_picture_uses_the_canonical_encoder() {
    let mut picture = wolf_game::picture::Picture::new(6200);
    picture.kind = wolf_game::picture::PictureKind::Text;
    picture.text = "\\E\\f[24]\\c[9]21:40".to_owned();
    let record = picture_to_record(&picture);
    assert_eq!(record.var5, 1);
    assert_eq!(
        decode_picture_text(&record.md1),
        picture.text,
        "a picture that never came from a save keeps the canonical spelling"
    );
    assert_eq!(
        encode_picture_text(&picture.text),
        record.md1,
        "new pictures never carry retained bytes"
    );
}