//! Parses every save file this game ships and checks the numbers in
//! docs/SAVE_SPEC.md.
//!
//! The expected values below were measured independently with a throwaway Python
//! reader and then reproduced here, so a mismatch means the Rust reader and the
//! reference disagree — it is not a "the fixture changed" situation.
//!
//! Set WOLF_GAME_DIR to the install directory. When it is missing the test skips
//! instead of failing, because the saves are copyrighted game data and cannot be
//! committed.

use std::path::{Path, PathBuf};

use wolf_save::SaveFile;

/// One save file's measured shape.
struct Expected {
    file: &'static str,
    size: usize,
    seeds: [u8; 3],
    checksum: u8,
    /// SavePart1 length; 34318 in every save.
    part1: usize,
    /// SavePart2 length; 595 or 617.
    part2: usize,
    /// SavePart3 length.
    part3: usize,
    /// SavePart4 length; 1213 or 1194.
    part4: usize,
    /// SavePart5 length.
    part5: usize,
    /// VariableDatabase length; 81851 or 81842.
    vardb: usize,
    /// SavePart5's event count.
    events: u16,
}

const EXPECTED: &[Expected] = &[
    Expected {
        file: "SaveData01.sav",
        size: 366146,
        seeds: [136, 182, 95],
        checksum: 178,
        part1: 34318,
        part2: 595,
        part3: 218610,
        part4: 1213,
        part5: 29489,
        vardb: 81851,
        events: 66,
    },
    Expected {
        file: "SaveData02.sav",
        size: 361637,
        seeds: [241, 177, 136],
        checksum: 250,
        part1: 34318,
        part2: 595,
        part3: 217708,
        part4: 1194,
        part5: 25910,
        vardb: 81842,
        events: 58,
    },
    Expected {
        file: "SaveData03.sav",
        size: 364263,
        seeds: [11, 134, 74],
        checksum: 113,
        part1: 34318,
        part2: 595,
        part3: 218472,
        part4: 1194,
        part5: 27772,
        vardb: 81842,
        events: 62,
    },
    Expected {
        file: "SaveData04.sav",
        size: 365071,
        seeds: [142, 176, 12],
        checksum: 236,
        part1: 34318,
        part2: 595,
        part3: 218466,
        part4: 1194,
        part5: 28586,
        vardb: 81842,
        events: 64,
    },
    Expected {
        file: "SaveData05.sav",
        size: 385978,
        seeds: [184, 10, 18],
        checksum: 58,
        part1: 34318,
        part2: 595,
        part3: 239821,
        part4: 1194,
        part5: 28138,
        vardb: 81842,
        events: 63,
    },
    Expected {
        file: "SaveData06.sav",
        size: 364257,
        seeds: [123, 1, 39],
        checksum: 224,
        part1: 34318,
        part2: 595,
        part3: 218462,
        part4: 1213,
        part5: 27748,
        vardb: 81851,
        events: 62,
    },
    Expected {
        file: "SaveData07.sav",
        size: 364399,
        seeds: [134, 201, 14],
        checksum: 185,
        part1: 34318,
        part2: 595,
        part3: 218574,
        part4: 1213,
        part5: 27778,
        vardb: 81851,
        events: 62,
    },
    Expected {
        file: "SaveData08.sav",
        size: 395566,
        seeds: [141, 100, 148],
        checksum: 216,
        part1: 34318,
        part2: 617,
        part3: 240000,
        part4: 1213,
        part5: 37497,
        vardb: 81851,
        events: 84,
    },
    Expected {
        file: "System.sav",
        size: 374216,
        seeds: [186, 159, 232],
        checksum: 164,
        part1: 34318,
        part2: 617,
        part3: 218650,
        part4: 1213,
        part5: 37497,
        vardb: 81851,
        events: 84,
    },
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

#[test]
fn every_save_parses_with_the_measured_shape() {
    let Some(dir) = save_dir() else { return };

    let mut checked = 0;
    for expected in EXPECTED {
        let Some(data) = read_save(&dir, expected.file) else {
            continue;
        };
        checked += 1;

        assert_eq!(
            data.len(),
            expected.size,
            "{}: unexpected file size",
            expected.file
        );

        let save = SaveFile::parse(&data)
            .unwrap_or_else(|err| panic!("{}: parse failed: {err}", expected.file));

        assert_eq!(
            [
                save.header.seed0(),
                save.header.seed1(),
                save.header.seed2()
            ],
            expected.seeds,
            "{}: seeds",
            expected.file
        );
        assert_eq!(
            save.stored_checksum, expected.checksum,
            "{}: stored checksum",
            expected.file
        );
        assert!(
            save.checksum_ok(),
            "{}: checksum {} does not match the body ({})",
            expected.file,
            save.stored_checksum,
            save.computed_checksum
        );
        assert_eq!(
            save.header.start_byte, 0x19,
            "{}: start byte",
            expected.file
        );
        assert_eq!(save.end_byte, 0x19, "{}: end byte", expected.file);
        assert_eq!(save.file_version, 0x8C, "{}: file version", expected.file);
        assert!(save.is_utf8, "{}: strings should be UTF-8", expected.file);
        assert_eq!(
            save.name, "妹相随～黑白世界的缤纷冒险～",
            "{}: save name",
            expected.file
        );

        let lens: Vec<usize> = save.chunks().iter().map(|chunk| chunk.len).collect();
        assert_eq!(
            lens,
            vec![
                expected.part1,
                expected.part2,
                expected.part3,
                expected.part4,
                expected.part5,
                expected.vardb,
                1
            ],
            "{}: segment lengths",
            expected.file
        );
        assert_eq!(
            save.chunks()
                .iter()
                .map(|chunk| chunk.name)
                .collect::<Vec<_>>(),
            vec![
                "SavePart1",
                "SavePart2",
                "SavePart3",
                "SavePart4",
                "SavePart5",
                "VariableDatabase",
                "SavePart7"
            ],
            "{}: segment order",
            expected.file
        );

        let first = save.chunks()[0].offset;
        let last = save.chunks()[6].offset + save.chunks()[6].len;
        assert_eq!(
            last + 1,
            data.len(),
            "{}: the body must end one byte before EOF",
            expected.file
        );
        assert!(
            first > 0x14,
            "{}: body must start after the header",
            expected.file
        );

        assert_eq!(
            save.part5.var1, expected.events,
            "{}: SavePart5 event count",
            expected.file
        );
        assert_eq!(
            save.part5.events.len(),
            usize::from(expected.events),
            "{}: SavePart5 table size",
            expected.file
        );

        assert_eq!(save.part7.var1, 0, "{}: SavePart7 gate", expected.file);
        assert!(
            save.part7.entries.is_empty(),
            "{}: SavePart7 should be empty",
            expected.file
        );
    }

    assert!(checked > 0, "no save files were checked");
    eprintln!("checked {checked} save file(s)");
}
