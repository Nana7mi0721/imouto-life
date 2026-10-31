//! Full-file rebuild: parse -> rebuild (typed serializers) -> encrypt must
//! reproduce each of the nine retail saves byte for byte.
//!
//! Two writers exist and this file pins the difference:
//!
//! * SaveFile::serialize copies every segment's original bytes; it only
//!   re-derives the header, the name, the version and the checksum.
//! * SaveFile::rebuild re-encodes SavePart1/2/3/4/5 and the VariableDatabase from
//!   their typed views and copies only SavePart7, which has no writer yet.
//!
//! Both must agree with the file on disk, and a mutated typed field must survive
//! the second one.

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

/// The retail save directory, or None when it is not on this machine.
///
/// work/retail_backup/Save holds the untouched copies checked into the work
/// tree; WOLF_GAME_DIR/Save is the live install. Both hold the same nine files.
fn save_dir() -> Option<PathBuf> {
    let candidates = [
        Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..")
            .join("work")
            .join("retail_backup")
            .join("Save"),
        std::env::var("WOLF_GAME_DIR")
            .map(PathBuf::from)
            .unwrap_or_else(|_| {
                PathBuf::from(
                    r"E:\SteamLibrary\steamapps\common\Living With SIster Monochrome Fantasy",
                )
            })
            .join("Save"),
    ];
    for dir in candidates {
        if dir.is_dir() {
            return Some(dir);
        }
    }
    eprintln!("skipping: no save directory found (set WOLF_GAME_DIR to the install directory)");
    None
}

/// Every save on disk as (name, original bytes, parsed).
fn all_saves() -> Vec<(&'static str, Vec<u8>, SaveFile)> {
    let Some(dir) = save_dir() else {
        return Vec::new();
    };
    FILES
        .iter()
        .map(|name| {
            let path = dir.join(name);
            let data = std::fs::read(&path)
                .unwrap_or_else(|err| panic!("cannot read {}: {err}", path.display()));
            let save = SaveFile::parse(&data)
                .unwrap_or_else(|err| panic!("{} must parse: {err}", path.display()));
            (*name, data, save)
        })
        .collect()
}

/// Where two buffers first disagree, for a readable assertion message.
fn first_difference(left: &[u8], right: &[u8]) -> Option<usize> {
    if left.len() != right.len() {
        let shared = left.len().min(right.len());
        for at in 0..shared {
            if left[at] != right[at] {
                return Some(at);
            }
        }
        return Some(shared);
    }
    left.iter().zip(right).position(|(a, b)| a != b)
}

/// The gate: every retail save survives a typed rebuild unchanged.
#[test]
fn every_retail_save_rebuilds_to_the_same_bytes() {
    let saves = all_saves();
    if saves.is_empty() {
        return;
    }
    for (name, original, save) in &saves {
        let rebuilt = save
            .to_bytes_rebuilt()
            .unwrap_or_else(|err| panic!("{name} rebuild failed: {err}"));
        if let Some(at) = first_difference(original, &rebuilt) {
            panic!(
                "{name}: rebuilt file differs at offset {at:#X} ({} vs {} byte(s))",
                original.len(),
                rebuilt.len()
            );
        }
        assert_eq!(rebuilt.len(), original.len(), "{name}: length");
    }
    assert_eq!(saves.len(), 9);
}

/// The copy-everything writer and the rebuild writer must agree.
#[test]
fn rebuild_matches_serialize_and_to_bytes() {
    let saves = all_saves();
    if saves.is_empty() {
        return;
    }
    for (name, original, save) in &saves {
        let copied = save.serialize().expect("serialize");
        let rebuilt = save.rebuild().expect("rebuild");
        assert_eq!(
            copied,
            rebuilt,
            "{name}: serialize and rebuild disagree ({} vs {} byte(s))",
            copied.len(),
            rebuilt.len()
        );
        assert_eq!(copied.len(), original.len(), "{name}: length");
        assert_eq!(
            &save.to_bytes().expect("to_bytes"),
            original,
            "{name}: to_bytes"
        );
    }
}

/// Each segment encoder on its own, compared with the segment bytes on disk.
#[test]
fn each_segment_encoder_reproduces_its_parsed_bytes() {
    let saves = all_saves();
    if saves.is_empty() {
        return;
    }
    for (name, _original, save) in &saves {
        let version = save.file_version;
        let cases: [(&str, Vec<u8>, &[u8]); 6] = [
            (
                "SavePart1",
                save.part1.to_bytes(version).expect("part1"),
                save.chunk_bytes(wolf_save::PART1_ID).expect("part1 bytes"),
            ),
            (
                "SavePart2",
                save.part2.to_bytes(version).expect("part2"),
                save.chunk_bytes(wolf_save::PART2_ID).expect("part2 bytes"),
            ),
            (
                "SavePart3",
                save.part3.to_bytes_with_version(version).expect("part3"),
                save.chunk_bytes(wolf_save::PART3_ID).expect("part3 bytes"),
            ),
            (
                "SavePart4",
                save.part4.to_bytes(version).expect("part4"),
                save.chunk_bytes(wolf_save::PART4_ID).expect("part4 bytes"),
            ),
            (
                "SavePart5",
                save.part5.to_bytes(version).expect("part5"),
                save.chunk_bytes(wolf_save::PART5_ID).expect("part5 bytes"),
            ),
            (
                "VariableDatabase",
                save.vardb.to_bytes().expect("vardb"),
                save.chunk_bytes(wolf_save::VARDB_ID).expect("vardb bytes"),
            ),
        ];
        for (label, encoded, parsed) in cases {
            if let Some(at) = first_difference(parsed, &encoded) {
                panic!(
                    "{name} {label}: encoder differs at offset {at:#X} ({} vs {} byte(s))",
                    parsed.len(),
                    encoded.len()
                );
            }
        }
    }
}

/// Mutating a SavePart2 word and a SavePart5 event field survives a full write.
#[test]
fn mutations_in_part2_and_part5_survive_a_rebuild() {
    let saves = all_saves();
    if saves.is_empty() {
        return;
    }
    let (name, _original, base) = &saves[0];

    // SavePart2: the play time, word 0 of vars3_21. That is also the field
    // SaveFile::set_playtime_frames patches in place, so the two paths must
    // agree on the bytes they produce.
    let mut save = base.clone();
    let before = save.playtime_frames().expect("play time");
    let edited = before.wrapping_add(1234);
    let mut part2 = save.part2.clone();
    part2.vars3_21[0] = edited;
    save.set_part2(&part2).expect("set_part2");
    assert_eq!(save.playtime_frames(), Some(edited));
    let bytes = save.to_bytes_rebuilt().expect("rebuild after part2 edit");
    let fresh = SaveFile::parse(&bytes).expect("reparse after part2 edit");
    assert_eq!(fresh.playtime_frames(), Some(edited), "{name}: play time");
    assert_eq!(fresh.name, base.name, "{name}: name unchanged");
    assert!(fresh.checksum_ok(), "{name}: checksum after part2 edit");

    // SavePart5: one word inside one event's runtime state.
    let mut save = base.clone();
    assert!(
        !save.part5.events.is_empty(),
        "{name}: expected event states"
    );
    let slot = save.part5.events.len() / 2;
    let mut part5 = save.part5.clone();
    let old = part5.events[slot].vars7_18[0];
    part5.events[slot].vars7_18[0] = 0x5A5A_5A5A;
    save.set_part5(&part5).expect("set_part5");
    assert_eq!(save.part5.events[slot].vars7_18[0], 0x5A5A_5A5A);
    let bytes = save.to_bytes_rebuilt().expect("rebuild after part5 edit");
    let fresh = SaveFile::parse(&bytes).expect("reparse after part5 edit");
    assert_eq!(
        fresh.part5.events.len(),
        part5.events.len(),
        "{name}: event count"
    );
    assert_eq!(
        fresh.part5.events[slot].vars7_18[0], 0x5A5A_5A5A,
        "{name}: edited word (was {old:#010X})"
    );
    assert_eq!(
        fresh.part5.events[slot].var1, part5.events[slot].var1,
        "{name}: event id"
    );

    // Reverting the edit gets the original bytes back, which is the strongest
    // statement that the serializer has no hidden state.
    let mut reverted = fresh.clone();
    let mut back = reverted.part5.clone();
    back.events[slot].vars7_18[0] = old;
    reverted.set_part5(&back).expect("set_part5 revert");
    let bytes = reverted.to_bytes_rebuilt().expect("rebuild after revert");
    assert_eq!(&bytes, _original, "{name}: revert must restore the file");
}

/// The first cell of the database whose config entry says "numeric".
fn first_numeric_cell(db: &wolf_save::vardb::VariableDatabase) -> Option<(usize, usize, usize)> {
    for (type_index, kind) in db.types.iter().enumerate() {
        let Some(field_index) = kind.config.iter().position(|def| *def < 2000) else {
            continue;
        };
        for (row_index, row) in kind.rows.iter().enumerate() {
            if row.number(field_index as u32).is_some() {
                return Some((type_index, row_index, field_index));
            }
        }
    }
    None
}

/// The first cell of the database whose config entry says "textual".
fn first_text_cell(db: &wolf_save::vardb::VariableDatabase) -> Option<(usize, usize, usize)> {
    for (type_index, kind) in db.types.iter().enumerate() {
        let Some(field_index) = kind.config.iter().position(|def| *def >= 2000) else {
            continue;
        };
        for (row_index, row) in kind.rows.iter().enumerate() {
            if row.string(field_index as u32).is_some() {
                return Some((type_index, row_index, field_index));
            }
        }
    }
    None
}

/// A hand-built database covering the three shapes `m_unknown` can take.
///
/// The retail saves all store -2, so the positive and -1 forms are never
/// exercised by them; this test is the only thing that pins those branches.
fn synthetic_database() -> wolf_save::vardb::VariableDatabase {
    use wolf_save::vardb::{
        VariableDatabase, VariableField, VariableRow, VariableType, VariableValue,
    };

    fn row(index: u32, values: &[(u32, VariableValue)]) -> VariableRow {
        let mut fields: Vec<VariableField> = values
            .iter()
            .map(|(id, value)| VariableField {
                id: *id,
                value: value.clone(),
            })
            .collect();
        fields.sort_by_key(|field| field.id);
        VariableRow { index, fields }
    }

    let text = |body: &str| {
        let mut bytes = body.as_bytes().to_vec();
        bytes.push(0);
        VariableValue::String(bytes)
    };
    let empty_text = || VariableValue::String(vec![0]);

    // Shape 1: m_unknown positive -- it is the field count, no m_dis, no
    // m_fieldCount on disk. 2 numeric fields then 1 textual.
    let positive = VariableType {
        unknown: 3,
        dis: 0,
        field_count: 0,
        config: vec![0, 1, 2000],
        row_count: 1,
        rows: vec![row(
            0,
            &[
                (0, VariableValue::Number(7)),
                (1, VariableValue::Number(-9)),
                (2, text("あ")),
            ],
        )],
    };

    // Shape 2: m_unknown == -1 -- m_fieldCount is present, m_dis is not.
    let minus_one = VariableType {
        unknown: -1,
        dis: 0,
        field_count: 2,
        config: vec![1, 2001],
        row_count: 2,
        rows: vec![
            row(0, &[(0, VariableValue::Number(11)), (1, text("one"))]),
            row(1, &[(0, VariableValue::Number(-11)), (1, text("two"))]),
        ],
    };

    // Shape 3: m_unknown == -2 -- both m_dis and m_fieldCount, no fields at all.
    let minus_two = VariableType {
        unknown: -2,
        dis: 7,
        field_count: 0,
        config: Vec::new(),
        row_count: 2,
        rows: vec![row(0, &[]), row(1, &[])],
    };

    // Shape 4: -3 with a mixture, and an empty textual body.
    let minus_three = VariableType {
        unknown: -3,
        dis: 42,
        field_count: 4,
        config: vec![0, 2002, 3, 2003],
        row_count: 1,
        rows: vec![row(
            0,
            &[
                (0, VariableValue::Number(i32::MIN)),
                (1, empty_text()),
                (2, VariableValue::Number(i32::MAX)),
                (3, text("")),
            ],
        )],
    };

    VariableDatabase {
        unknown: 0x6F,
        type_count: 4,
        types: vec![positive, minus_one, minus_two, minus_three],
    }
}

/// `to_bytes` -> `parse` must reproduce the value it started from, for every
/// shape of `m_unknown`.
#[test]
fn a_synthetic_variable_database_round_trips_through_to_bytes() {
    let original = synthetic_database();
    let bytes = original.to_bytes().expect("encode synthetic database");
    let parsed = wolf_save::vardb::parse_bytes(&bytes).expect("reparse synthetic database");
    assert_eq!(parsed, original, "synthetic database did not round-trip");
    assert_eq!(
        parsed.to_bytes().expect("re-encode"),
        bytes,
        "re-encoding the reparsed value must be stable"
    );
}

/// A numeric cell edit reaches the file, and reverting it restores the file.
#[test]
fn a_mutated_vardb_number_survives_a_full_rebuild() {
    let saves = all_saves();
    if saves.is_empty() {
        return;
    }
    let (name, original, base) = &saves[0];
    let Some((type_index, row_index, field_index)) = first_numeric_cell(&base.vardb) else {
        panic!("{name}: the variable database has no numeric cell");
    };
    let before = base
        .vardb
        .number(type_index, row_index, field_index)
        .expect("cell");
    let edited = before.wrapping_add(1);

    let mut save = base.clone();
    assert!(
        save.set_vardb_num(type_index, row_index, field_index, edited)
            .expect("set_vardb_num"),
        "{name}: type {type_index} row {row_index} field {field_index} must be writable"
    );
    assert_eq!(
        save.vardb.number(type_index, row_index, field_index),
        Some(edited),
        "{name}: in-memory view"
    );
    let bytes = save.to_bytes_rebuilt().expect("rebuild after vardb edit");
    let fresh = SaveFile::parse(&bytes).expect("reparse after vardb edit");
    assert_eq!(
        fresh.vardb.number(type_index, row_index, field_index),
        Some(edited),
        "{name}: edited cell type {type_index} row {row_index} field {field_index}"
    );
    assert_eq!(
        fresh.vardb.type_count, base.vardb.type_count,
        "{name}: types"
    );
    assert!(fresh.checksum_ok(), "{name}: checksum after vardb edit");

    // Revert: the encoder must have no hidden state, so the file comes back.
    let mut reverted = fresh;
    assert!(
        reverted
            .set_vardb_num(type_index, row_index, field_index, before)
            .expect("revert"),
        "{name}: revert"
    );
    let bytes = reverted.to_bytes_rebuilt().expect("rebuild after revert");
    if let Some(at) = first_difference(original, &bytes) {
        panic!("{name}: revert differs at offset {at:#X}");
    }
}

/// A textual cell edit survives a write, NUL terminator included.
///
/// `VariableDatabase::text` is the lossy UTF-8 view of the body (the live game
/// layer's contract); the bytes are written in this release's GBK display
/// encoding, so the comparison goes through the real WOLF decoder.
#[test]
fn a_mutated_vardb_text_survives_a_full_rebuild() {
    let saves = all_saves();
    if saves.is_empty() {
        return;
    }
    let (name, _original, base) = &saves[0];
    let Some((type_index, row_index, field_index)) = first_text_cell(&base.vardb) else {
        panic!("{name}: the variable database has no textual cell");
    };
    let before = base
        .vardb
        .string(type_index, row_index, field_index)
        .expect("cell")
        .to_vec();

    let mut save = base.clone();
    assert!(
        save.set_vardb_text(type_index, row_index, field_index, "書き込みテスト")
            .expect("set_vardb_text"),
        "{name}: type {type_index} row {row_index} field {field_index} must be writable"
    );
    let bytes = save.to_bytes_rebuilt().expect("rebuild after vardb text");
    let fresh = SaveFile::parse(&bytes).expect("reparse after vardb text");
    let written = fresh
        .vardb
        .string(type_index, row_index, field_index)
        .expect("cell");
    let raw = written.strip_suffix(&[0]).unwrap_or(written);
    assert_eq!(
        wolf_format::bytes::decode_wolf_str(raw),
        "書き込みテスト",
        "{name}: edited text"
    );
    assert!(fresh.checksum_ok(), "{name}: checksum after vardb text");

    let mut reverted = fresh;
    assert!(
        reverted
            .set_vardb_string(type_index, row_index, field_index, &before)
            .expect("revert text"),
        "{name}: revert"
    );
    let bytes = reverted.to_bytes_rebuilt().expect("rebuild after revert");
    let back = SaveFile::parse(&bytes).expect("reparse after revert");
    assert_eq!(
        back.vardb.string(type_index, row_index, field_index),
        Some(before.as_slice()),
        "{name}: reverted text"
    );
}

/// Wrong-kind writes and out-of-range indexes are refused, not silently dropped.
#[test]
fn vardb_setters_refuse_what_they_cannot_encode() {
    let original = synthetic_database();
    let mut db = original.clone();

    // Field 2 of type 0 is textual; a numeric write there must fail.
    assert!(!db.set_num(0, 0, 2, 5));
    // Field 0 of type 0 is numeric; a textual write there must fail.
    assert!(!db.set_string(0, 0, 0, &[0]));
    // Out of range on every axis.
    assert!(!db.set_num(9, 0, 0, 5));
    assert!(!db.set_num(0, 9, 0, 5));
    assert!(!db.set_num(0, 0, 9, 5));
    // None of the refusals touched anything.
    assert_eq!(db, original);

    // A valid write does land, and encodes back out.
    assert!(db.set_num(0, 0, 1, -1));
    let bytes = db.to_bytes().expect("encode");
    let parsed = wolf_save::vardb::parse_bytes(&bytes).expect("reparse");
    assert_eq!(parsed.number(0, 0, 1), Some(-1));
}
