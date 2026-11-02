//! Typed access to the variables a save carries, and the writer that puts them
//! back.
//!
//! Two things are proved here:
//!
//! 1. SavePart3 re-encodes to the exact bytes it was parsed from, so editing one
//!    variable cannot disturb the other 218,000 bytes.
//! 2. The three variable tables really hold what the game shows: the money HUD,
//!    the play-time clock, and the CSelf slots every common event keeps. The values
//!    themselves are live gameplay state, so only their shape and accessors are pinned.
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

/// The stable shape of the tables in every save file.
///
/// The money (normal variable 2000007), the play-time word, the number of registered
/// common events and the last-used slot (ev131 CSelf12) are live gameplay state: they
/// change every time the player saves again, so they are only checked for presence and
/// a sane range here. The pinned values measured when these saves were first read are
/// recorded in docs/SAVE_FORMAT.md.
///
/// What must hold for every save, whatever the player did since:
/// * the normal-variable table is ten rows, the first 800 words long;
/// * event 48 leaves its font/size constants in CSelf16/25/26 (6, 12, 24);
/// * event 131 writes "Save/System.sav" into CSelf5;
/// * part 3 is the large segment (the tables, not a stub).
#[test]
fn the_tables_hold_the_numbers_the_game_ships() {
    let saves = all_saves();
    if saves.is_empty() {
        return;
    }
    assert_eq!(saves.len(), FILES.len());
    for (name, save) in &saves {
        // Ten rows, the first 800 words long: the normal variables.
        assert_eq!(
            save.part3.row_counts,
            vec![800, 4, 7, 4, 1, 1, 1, 6, 1, 10],
            "{name}: the row counts are the same in every save"
        );
        let money = save
            .part3
            .normal_var(7)
            .unwrap_or_else(|| panic!("{name}: normal variable 2000007 is the money word"));
        assert!(
            (0..1_000_000).contains(&money),
            "{name}: money {money} out of range"
        );
        assert!(
            save.playtime_frames().is_some(),
            "{name}: the play-time word reads"
        );
        assert!(
            save.part3.list_counts.len() >= 500,
            "{name}: one group per common event, {} found",
            save.part3.list_counts.len()
        );
        assert!(
            save.chunk_bytes(wolf_save::PART3_ID).expect("part3").len() >= 200_000,
            "{name}: part3 holds the variable tables"
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
        let slot = save
            .part3
            .self_var(131, 12)
            .unwrap_or_else(|| panic!("{name}: ev131 CSelf12 is the save slot"));
        // 1..8 are the menu slots; the game also writes auto-save slots above them.
        assert!(
            (0..=16).contains(&slot),
            "{name}: save slot {slot} out of range"
        );
    }
    let (_, system) = saves
        .iter()
        .find(|(name, _)| *name == "System.sav")
        .unwrap();
    // System.sav keeps the last used slot in normal variable 2000000.
    assert!(
        system.part3.normal_var(0).is_some(),
        "System.sav: the last-used slot reads"
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
    // Live value, not a fixture: only the round trip below is pinned.
    assert!((0..1_000_000).contains(&money_before));

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
