//! Round-trips every save file this game ships and checks the writer.
//!
//! `SaveFile::parse` -> `serialize` -> `to_bytes` must reproduce the original file
//! byte for byte, including the checksum byte in the plaintext header. The
//! measured shapes live in `tests/save.rs`; this file only cares that writing is
//! the exact inverse of reading.
//!
//! Set WOLF_GAME_DIR to the install directory. When it is missing the tests that
//! need real data skip, because the saves are copyrighted game data.

use std::path::{Path, PathBuf};

use wolf_save::{SaveFile, END_BYTE};

/// Every save this game ships, in the order the game numbers its slots.
const FILES: &[&str] = &[
    "SaveData01.sav",
    "SaveData02.sav",
    "SaveData03.sav",
    "SaveData04.sav",
    "SaveData05.sav",
    "SaveData06.sav",
    "SaveData07.sav",
    "SaveData08.sav",
    "System.sav",
];

/// The save directory, or None when the game is not installed here.
fn save_dir() -> Option<PathBuf> {
    let root = std::env::var("WOLF_GAME_DIR")
        .map(PathBuf::from)
        .unwrap_or_else(|_| {
            PathBuf::from(r"E:\SteamLibrary\steamapps\common\Living With SIster Monochrome Fantasy")
        });
    let dir = root.join("Save");
    if dir.is_dir() {
        Some(dir)
    } else {
        eprintln!(
            "skipping: {} does not exist (set WOLF_GAME_DIR to the install directory)",
            dir.display()
        );
        None
    }
}

fn read_save(dir: &Path, name: &str) -> Option<Vec<u8>> {
    let path = dir.join(name);
    match std::fs::read(&path) {
        Ok(data) => Some(data),
        Err(err) => {
            eprintln!("skipping: cannot read {}: {err}", path.display());
            None
        }
    }
}

/// The cipher must be its own inverse, and it must leave the header alone.
#[test]
fn the_cipher_wraps_any_buffer() {
    let mut data = vec![0u8; 200];
    data[0] = 0x11;
    data[3] = 0x22;
    data[9] = 0x33;

    let enc = wolf_save::encrypt(&data).expect("encrypt");
    assert_eq!(&enc[..0x14], &data[..0x14], "the header stays plaintext");
    assert_ne!(&enc[0x14..], &data[0x14..], "the body must be obfuscated");
    assert_eq!(wolf_save::decrypt(&enc).expect("decrypt"), data);
    assert_eq!(wolf_save::encrypt(&enc).expect("re-encrypt"), data);
}

/// Every shipped save comes back identical: decrypted bytes, then raw bytes.
#[test]
fn every_save_round_trips_byte_for_byte() {
    let Some(dir) = save_dir() else { return };

    let mut checked = 0;
    for file in FILES {
        let Some(original) = read_save(&dir, file) else {
            continue;
        };
        checked += 1;

        let save =
            SaveFile::parse(&original).unwrap_or_else(|err| panic!("{file}: parse failed: {err}"));

        let plain = save.serialize().expect("serialize");
        assert_eq!(
            plain,
            save.decrypted(),
            "{file}: serialize must reproduce the decrypted bytes"
        );

        let bytes = save.to_bytes().expect("to_bytes");
        assert_eq!(bytes.len(), original.len(), "{file}: written size");
        assert_eq!(bytes, original, "{file}: written bytes");

        let again =
            SaveFile::parse(&bytes).unwrap_or_else(|err| panic!("{file}: re-parse failed: {err}"));
        assert!(again.checksum_ok(), "{file}: checksum after re-parse");
        assert_eq!(again.end_byte, END_BYTE, "{file}: end byte after re-parse");
    }

    assert!(checked > 0, "no save files were round-tripped");
    eprintln!("round-tripped {checked} save file(s)");
}

/// Renaming repacks the `MemData<WORD>` header field and shifts the whole body.
#[test]
fn renaming_rebuilds_the_header_and_shifts_the_body() {
    let Some(dir) = save_dir() else { return };
    let Some(original) = read_save(&dir, "SaveData01.sav") else {
        return;
    };

    let mut save = SaveFile::parse(&original).expect("parse");
    assert_eq!(save.name, "妹相随～黑白世界的缤纷冒险～");
    let old_part1_offset = save.chunks()[0].offset;
    let part3 = save.chunk_bytes(2).expect("part3").to_vec();
    let events = save.part5.events.len();

    save.name = "test".to_string();
    let bytes = save.to_bytes().expect("to_bytes");

    // The old name field was 43 bytes (42 bytes of text plus a terminator), the new one is 5.
    let expected_size = original.len() - 38;
    assert_eq!(bytes.len(), expected_size, "written size");

    let fresh = SaveFile::parse(&bytes).expect("re-parse");
    assert_eq!(fresh.name, "test", "name");
    assert_eq!(fresh.file_version, 0x8C, "file version");
    assert!(fresh.is_utf8, "strings stay UTF-8");
    assert!(fresh.checksum_ok(), "checksum");
    assert_eq!(
        fresh.chunks()[0].offset,
        old_part1_offset - 38,
        "body shift"
    );
    assert_eq!(fresh.chunk_bytes(2).expect("part3"), &part3[..], "part3");
    assert_eq!(fresh.part5.events.len(), events, "part5 survives");
}

/// Replacing a middle segment shifts everything after it and fixes the checksum.
#[test]
fn growing_a_middle_segment_shifts_the_later_offsets() {
    let Some(dir) = save_dir() else { return };
    let Some(original) = read_save(&dir, "SaveData01.sav") else {
        return;
    };

    let mut save = SaveFile::parse(&original).expect("parse");
    let before: Vec<usize> = save.chunks().iter().map(|chunk| chunk.offset).collect();
    let before_len = save.chunks()[2].len;

    let mut grown = save.chunk_bytes(2).expect("part3").to_vec();
    grown.extend_from_slice(&[0u8; 10]);
    save.replace_part(2, &grown).expect("replace_part");

    let after: Vec<usize> = save.chunks().iter().map(|chunk| chunk.offset).collect();
    assert_eq!(after[0], before[0], "part1 stays put");
    assert_eq!(after[2], before[2], "part3 starts where it did");
    assert_eq!(after[3], before[3] + 10, "part4 moved");
    assert_eq!(after[6], before[6] + 10, "part7 moved");
    assert_eq!(save.chunks()[2].len, before_len + 10, "part3 grew");

    let bytes = save.to_bytes().expect("to_bytes");
    assert_eq!(bytes.len(), original.len() + 10, "written size");

    let old_plain = wolf_save::decrypt(&original).expect("decrypt");
    let new_plain = wolf_save::decrypt(&bytes).expect("decrypt");
    assert_eq!(
        &new_plain[..before[3]],
        &old_plain[..before[3]],
        "bytes before the edited segment are untouched"
    );
    assert_eq!(
        &new_plain[before[3] + 10..],
        &old_plain[before[3]..],
        "everything after the edited segment moved by exactly 10"
    );
    assert_eq!(
        new_plain[2],
        new_plain[0x14..]
            .iter()
            .fold(0u8, |acc, byte| acc.wrapping_add(*byte)),
        "the stored checksum follows the new body"
    );
}

/// A segment the parser accepts can be grown and still parse back.
#[test]
fn a_replaced_trailing_segment_parses_back() {
    let Some(dir) = save_dir() else { return };
    let Some(original) = read_save(&dir, "SaveData01.sav") else {
        return;
    };

    let mut save = SaveFile::parse(&original).expect("parse");
    assert!(save.part7.entries.is_empty(), "the shipped part7 is empty");

    // One SavePart7 entry: gate 1, count 1, tag 0x05 with the byte payload 0x2A.
    save.replace_part(6, &[1, 1, 0, 0, 0, 0x05, 0x2A])
        .expect("replace_part");
    let bytes = save.to_bytes().expect("to_bytes");
    assert_eq!(bytes.len(), original.len() + 6, "written size");

    let fresh = SaveFile::parse(&bytes).expect("re-parse");
    assert_eq!(fresh.part7.var1, 1, "gate");
    assert_eq!(fresh.part7.entries.len(), 1, "entry count");
    assert_eq!(fresh.part7.entries[0].tag, 0x05, "entry tag");
    assert_eq!(fresh.part7.entries[0].byte, 0x2A, "entry payload");
    assert!(fresh.checksum_ok(), "checksum");
    assert_eq!(fresh.end_byte, END_BYTE, "end byte");
}

/// Only the seven real segment ids are addressable.
#[test]
fn an_unknown_segment_id_is_rejected() {
    let Some(dir) = save_dir() else { return };
    let Some(original) = read_save(&dir, "System.sav") else {
        return;
    };

    let mut save = SaveFile::parse(&original).expect("parse");
    assert!(save.replace_part(7, &[0]).is_err(), "id 7 does not exist");
    assert!(
        save.replace_part(u32::MAX, &[0]).is_err(),
        "so does u32::MAX"
    );
    assert_eq!(
        save.serialize().expect("serialize"),
        save.decrypted(),
        "a rejected edit must not touch the buffer"
    );
}
