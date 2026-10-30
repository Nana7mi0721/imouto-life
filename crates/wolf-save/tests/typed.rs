//! Typed access to the variables a save carries, and the writer that puts them
//! back.
//!
//! Two things are proved here:
//!
//! 1. SavePart3 re-encodes to the exact bytes it was parsed from, so editing one
//!    variable cannot disturb the other 218,000 bytes.
//! 2. The three variable tables really hold what the game shows: the money HUD,
//!    the play-time clock, and the CSelf slots every common event keeps.
//!
//! Set WOLF_GAME_DIR to the install directory. When it is missing the tests that
//! need real data skip, because the saves are copyrighted game data.

use std::path::{Path, PathBuf};

use wolf_save::SaveFile;

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

/// Parse one save, or None when the game is not installed.
fn load(dir: &Path, name: &str) -> Option<SaveFile> {
    let path = dir.join(name);
    let data = match std::fs::read(&path) {
        Ok(data) => data,
        Err(err) => {
            eprintln!("skipping: cannot read {}: {err}", path.display());
            return None;
        }
    };
    Some(SaveFile::parse(&data).expect("the shipped saves must parse"))
}

/// Every save a caller can read; empty when the game is not installed.
fn all_saves() -> Vec<(&'static str, SaveFile)> {
    let Some(dir) = save_dir() else {
        return Vec::new();
    };
    FILES
        .iter()
        .filter_map(|name| load(&dir, name).map(|save| (*name, save)))
        .collect()
}

/// The segment must be a lossless view: encode(parse(bytes)) == bytes.
#[test]
fn every_part3_re_encodes_byte_for_byte() {
    let saves = all_saves();
    if saves.is_empty() {
        return;
    }
    let mut checked = 0usize;
    for (name, save) in &saves {
        let original = save.chunk_bytes(wolf_save::PART3_ID).expect("part3");
        let encoded = save.part3.to_bytes().expect("encode");
        assert_eq!(
            encoded.len(),
            original.len(),
            "{name}: part3 re-encoded to {} byte(s), parsed {}",
            encoded.len(),
            original.len()
        );
        assert!(
            encoded == original,
            "{name}: part3 is not byte-identical after a round trip"
        );
        checked += 1;
    }
    assert_eq!(checked, saves.len());
}

/// Per-save values read straight out of the tables: the money the HUD shows
/// (normal variable 2000007), the play-time word, the group count, the last-used
/// save slot (ev131 CSelf12) and the segment length.
const EXPECTED: &[(&str, i32, u32, usize, i32, usize)] = &[
    // name, money, play frames, groups, ev131 slot, part3 length
    ("SaveData01.sav", 7586, 16_642, 500, 8, 218_610),
    ("SaveData02.sav", 2254, 1_252, 500, 2, 217_708),
    ("SaveData03.sav", 8231, 13_877, 500, 3, 218_472),
    ("SaveData04.sav", 1293, 16_536, 500, 4, 218_466),
    ("SaveData05.sav", 1193, 16_705, 550, 5, 239_821),
    ("SaveData06.sav", 1503, 7_882, 500, 6, 218_462),
    ("SaveData07.sav", 15_453, 11_143, 500, 7, 218_574),
    ("SaveData08.sav", 7586, 16_887, 550, 8, 240_000),
    ("System.sav", 7586, 16_887, 500, 8, 218_650),
];

/// The numbers the retail game shows on screen, read straight out of the tables.
#[test]
fn the_tables_hold_the_numbers_the_game_ships() {
    let saves = all_saves();
    if saves.is_empty() {
        return;
    }
    assert_eq!(saves.len(), EXPECTED.len());
    for ((name, save), (want_name, money, play, groups, slot, part3_len)) in
        saves.iter().zip(EXPECTED)
    {
        assert_eq!(name, want_name);
        // Ten rows, the first 800 words long: the normal variables.
        assert_eq!(
            save.part3.row_counts,
            vec![800, 4, 7, 4, 1, 1, 1, 6, 1, 10],
            "{name}: the row counts are the same in every save"
        );
        assert_eq!(
            save.part3.normal_var(7),
            Some(*money),
            "{name}: normal variable 2000007 is the money the HUD shows"
        );
        assert_eq!(save.playtime_frames(), Some(*play), "{name}: play time");
        assert_eq!(
            save.part3.list_counts.len(),
            *groups,
            "{name}: one group per common event"
        );
        assert_eq!(
            save.chunk_bytes(wolf_save::PART3_ID).expect("part3").len(),
            *part3_len,
            "{name}: part3 length"
        );
        // Group index == common event id, so these are CSelf slots of event 48.
        assert_eq!(save.part3.self_var(48, 16), Some(6), "{name}: ev48 CSelf16");
        assert_eq!(
            save.part3.self_var(48, 25),
            Some(12),
            "{name}: ev48 CSelf25"
        );
        assert_eq!(
            save.part3.self_var(48, 26),
            Some(24),
            "{name}: ev48 CSelf26"
        );
        // Ev131 writes its save path into CSelf5 and the slot number into CSelf12.
        assert_eq!(
            save.part3.self_string(131, 0),
            Some("Save/System.sav"),
            "{name}: ev131 CSelf5"
        );
        assert_eq!(
            save.part3.self_var(131, 12),
            Some(*slot),
            "{name}: ev131 CSelf12 is the save slot"
        );
    }
    let (_, system) = saves
        .iter()
        .find(|(name, _)| *name == "System.sav")
        .unwrap();
    // System.sav keeps the last used slot in normal variable 2000000.
    assert_eq!(
        system.part3.normal_var(0),
        Some(8),
        "System.sav: the last-used slot"
    );
}

/// Editing a normal variable must survive serialize -> parse and touch nothing else.
#[test]
fn editing_a_normal_variable_survives_a_write() {
    let Some(dir) = save_dir() else { return };
    let Some(mut save) = load(&dir, "SaveData01.sav") else {
        return;
    };
    let before_len = save.decrypted().len();
    let money_before = save.normal_var(7).expect("money");
    assert_eq!(money_before, 7586);

    assert!(save.set_normal_var(7, 123_456).expect("set"));
    let bytes = save.to_bytes().expect("write");
    let fresh = SaveFile::parse(&bytes).expect("reparse");

    assert_eq!(fresh.normal_var(7), Some(123_456));
    assert_eq!(
        fresh.decrypted().len(),
        before_len,
        "no segment changed size"
    );
    assert_eq!(fresh.playtime_frames(), save.playtime_frames());
    assert_eq!(fresh.self_string(131, 0), Some("Save/System.sav"));
    assert_eq!(
        fresh.part3.self_var(48, 16),
        Some(6),
        "the self variables are untouched"
    );
    assert!(fresh.checksum_ok());
    // And the edited segment is still a lossless view of its own bytes.
    assert_eq!(
        fresh.part3.to_bytes().expect("encode"),
        fresh.chunk_bytes(wolf_save::PART3_ID).expect("part3")
    );
}

/// Self variables and self strings live in the same segment; both must persist.
#[test]
fn editing_self_state_survives_a_write() {
    let Some(dir) = save_dir() else { return };
    let Some(mut save) = load(&dir, "SaveData05.sav") else {
        return;
    };
    assert!(save.set_self_var(48, 25, 99).expect("set self var"));
    assert!(save
        .set_self_string(131, 0, "Save/Other.sav")
        .expect("set string"));

    let fresh = SaveFile::parse(&save.to_bytes().expect("write")).expect("reparse");
    assert_eq!(fresh.self_var(48, 25), Some(99));
    assert_eq!(fresh.self_string(131, 0), Some("Save/Other.sav"));
    // The neighbouring slots keep their values.
    assert_eq!(fresh.self_var(48, 26), Some(24));
    assert_eq!(fresh.self_string(131, 1), Some(""));
    assert_eq!(fresh.self_var(131, 12), Some(5), "SaveData05 stores 5 here");
    assert!(fresh.checksum_ok());
}

/// The play-time word sits at offset 2 of the second segment; patching it must
/// leave every other byte alone.
#[test]
fn playtime_round_trips_through_the_header() {
    let Some(dir) = save_dir() else { return };
    let Some(mut save) = load(&dir, "SaveData05.sav") else {
        return;
    };
    let original_len = save.decrypted().len();
    assert_eq!(save.playtime_frames(), Some(16_705));
    let part3_before = save
        .chunk_bytes(wolf_save::PART3_ID)
        .expect("part3")
        .to_vec();
    let part2_before = save
        .chunk_bytes(wolf_save::PART2_ID)
        .expect("part2")
        .to_vec();

    save.set_playtime_frames(4321).expect("patch");
    let part2_after = save
        .chunk_bytes(wolf_save::PART2_ID)
        .expect("part2")
        .to_vec();
    assert_eq!(part2_after.len(), part2_before.len());
    let differing: Vec<usize> = part2_before
        .iter()
        .zip(&part2_after)
        .enumerate()
        .filter(|(_, (a, b))| a != b)
        .map(|(at, _)| at)
        .collect();
    assert_eq!(
        differing,
        vec![2, 3],
        "only the low two bytes of the play-time word changed (4321 = 0x10E1)"
    );

    let fresh = SaveFile::parse(&save.to_bytes().expect("write")).expect("reparse");
    assert_eq!(fresh.playtime_frames(), Some(4321));
    assert_eq!(fresh.decrypted().len(), original_len);
    assert_eq!(
        fresh.chunk_bytes(wolf_save::PART3_ID).expect("part3"),
        part3_before.as_slice(),
        "the variable tables are untouched"
    );
    assert!(fresh.checksum_ok());
}

/// Out-of-range indexes are refused rather than silently clamped.
#[test]
fn out_of_range_indexes_are_refused() {
    let saves = all_saves();
    if saves.is_empty() {
        return;
    }
    let (_, save) = &saves[0];
    assert_eq!(
        save.part3.normal_var(799).is_some() && save.part3.normal_var(800).is_none(),
        true
    );
    assert_eq!(save.part3.self_var(0, 99).is_some(), true);
    assert!(save.part3.self_var(0, 100).is_none(), "100 words per group");
    assert!(
        save.part3
            .self_var(save.part3.list_counts.len() as u32, 0)
            .is_none(),
        "there is no group past the table"
    );
    assert!(
        save.part3.self_string(0, 5).is_none(),
        "five strings per group"
    );

    let mut edited = save.clone();
    assert!(!edited.part3.set_normal_var(800, 1));
    assert!(!edited.part3.set_self_var(0, 100, 1));
    assert!(!edited.part3.set_self_string(0, 5, "x"));
    assert_eq!(edited.set_normal_var(800, 1).expect("set"), false);
    assert_eq!(edited.set_self_var(0, 100, 1).expect("set"), false);
}
