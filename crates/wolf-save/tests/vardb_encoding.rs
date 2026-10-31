//! Byte-level contract for the variable database's textual cells.
//!
//! A WOLF 2.00 save stores bytes, not Unicode, and this release's saves mix two
//! code pages. Measured on the shipped `SaveData01/02` (identical variable
//! databases, 1589 textual cells):
//!
//! * 1521 empty, 23 ASCII, 45 non-ASCII.
//! * 43 of the non-ASCII bodies are CP932 template text, e.g.
//!   `83 71 81 5B 83 8D 81 5B 82 B3 82 F1 00` = `"ヒーローさん"`,
//!   `97 45 8E D2 00` = `"勇者"`, `8B 5A 94 5C 00` = `"技能"`.
//! * 1 was written by character creation in GBK: `D4 E7 D0 B9 20 00` =
//!   `"早泄 "`. Its sibling cell `C7 BF D7 B3 20 00` is the GBK spelling of
//!   `"强壮 "`, which also happens to be valid UTF-8 (`"ǿ׳ "`). The decoder
//!   now scores the UTF-8 and GBK readings instead of trusting UTF-8 blindly,
//!   so this real collision decodes as `"强壮 "` while genuine UTF-8 text
//!   (Chinese, Japanese, an older build's fallback) still wins.
//!
//! The same save's runtime strings in `SavePart3` are GBK
//! (`"没有数据"` = `C3 BB D3 D0 CA FD BE DD 00`), which is what the fan
//! translation's script text uses. Text-only re-encoding cannot tell a CP932
//! `"勇者"` from a GBK `"勇者"`, so [VariableDatabase::set_text] keeps an
//! existing legacy body while the caller's text still describes it, and encodes
//! a genuinely new non-ASCII string as GBK when that round-trips, else UTF-8.
//!
//! Everything skips cleanly when work/Data is absent, so the default workspace
//! run stays exit 0.

use std::path::PathBuf;

use wolf_save::vardb::{VariableDatabase, VariableValue};
use wolf_save::{SaveFile, VARDB_ID};

const FILES: &[&str] = &["SaveData01.sav", "SaveData02.sav"];

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

fn save_path(name: &str) -> PathBuf {
    data_root().join("Save").join(name)
}

/// The save's bytes and parsed form, or None when the data tree is absent.
fn read(name: &str) -> Option<(Vec<u8>, SaveFile)> {
    let path = save_path(name);
    let Ok(bytes) = std::fs::read(&path) else {
        eprintln!("skipping: no {}", path.display());
        return None;
    };
    let save = SaveFile::parse(&bytes).unwrap_or_else(|err| panic!("{}: {err}", path.display()));
    Some((bytes, save))
}

fn first_difference(left: &[u8], right: &[u8]) -> Option<usize> {
    let shared = left.len().min(right.len());
    for at in 0..shared {
        if left[at] != right[at] {
            return Some(at);
        }
    }
    if left.len() == right.len() {
        None
    } else {
        Some(shared)
    }
}

fn strip_nul(body: &[u8]) -> &[u8] {
    body.strip_suffix(&[0]).unwrap_or(body)
}

/// Every textual cell as (type, row, field, body).
fn text_cells(db: &VariableDatabase) -> Vec<(usize, usize, usize, Vec<u8>)> {
    let mut out = Vec::new();
    for (type_index, kind) in db.types.iter().enumerate() {
        for (row_index, row) in kind.rows.iter().enumerate() {
            for (field_index, definition) in kind.config.iter().enumerate() {
                if *definition >= 2000 {
                    if let Some(body) = row.string(field_index as u32) {
                        out.push((type_index, row_index, field_index, body.to_vec()));
                    }
                }
            }
        }
    }
    out
}

fn cell(db: &VariableDatabase, type_index: usize, row_index: usize, field_index: usize) -> &[u8] {
    db.string(type_index, row_index, field_index)
        .unwrap_or_else(|| {
            panic!("type {type_index} row {row_index} field {field_index} must be textual")
        })
}

/// What `wolf-game`'s database layer produces today: `String::from_utf8_lossy`
/// followed by `trim_end_matches('\0')` (see `Databases::apply_saved_database`).
fn lossy_view(body: &[u8]) -> String {
    String::from_utf8_lossy(strip_nul(body))
        .trim_end_matches('\0')
        .to_owned()
}

/// ASCII/UTF-8 spelling of `text` with the game's NUL terminator.
fn utf8_body(text: &str) -> Vec<u8> {
    let mut body = text.as_bytes().to_vec();
    body.push(0);
    body
}

/// The measured shape of the shipped saves: two code pages in one segment.
#[test]
fn retail_vardb_strings_come_from_two_code_pages() {
    for name in FILES {
        let Some((_original, save)) = read(name) else {
            return;
        };
        let cells = text_cells(&save.vardb);
        assert_eq!(cells.len(), 1589, "{name}: textual cells");

        let non_ascii = cells
            .iter()
            .filter(|(_, _, _, body)| strip_nul(body).iter().any(|byte| *byte >= 0x80))
            .count();
        assert_eq!(non_ascii, 45, "{name}: non-ASCII textual cells");

        // Untouched template text is CP932.
        assert_eq!(
            cell(&save.vardb, 0, 0, 0),
            &[0x83, 0x71, 0x81, 0x5B, 0x83, 0x8D, 0x81, 0x5B, 0x82, 0xB3, 0x82, 0xF1, 0][..],
            "{name}: \"ヒーローさん\" is stored as CP932"
        );
        assert_eq!(
            wolf_format::bytes::decode_wolf_str(strip_nul(cell(&save.vardb, 0, 0, 0))),
            "ヒーローさん",
            "{name}: the CP932 body decodes as Japanese"
        );
        assert_eq!(
            cell(&save.vardb, 18, 24, 1),
            &[0x8B, 0x5A, 0x94, 0x5C, 0][..],
            "{name}: \"技能\" is stored as CP932"
        );

        // Character creation wrote the player's values in GBK.
        assert_eq!(
            cell(&save.vardb, 0, 12, 0),
            &[0xD4, 0xE7, 0xD0, 0xB9, 0x20, 0][..],
            "{name}: the name cell is stored as GBK"
        );
        assert_eq!(
            wolf_format::gbk::decode(strip_nul(cell(&save.vardb, 0, 12, 0))).0,
            "早泄 ",
            "{name}: the name cell is GBK text"
        );

        // The GBK spelling of "强壮" is also valid UTF-8 ("ǿ׳"). The scored
        // decoder must recover the GBK reading; the bytes are still GBK and the
        // writer must not corrupt them.
        let collision = cell(&save.vardb, 0, 12, 1);
        assert_eq!(collision, &[0xC7, 0xBF, 0xD7, 0xB3, 0x20, 0][..]);
        assert_eq!(
            std::str::from_utf8(strip_nul(collision)).expect("valid UTF-8"),
            "ǿ׳ ",
            "{name}: GBK/UTF-8 collision cell"
        );
        assert_eq!(
            wolf_format::gbk::decode(strip_nul(collision)).0,
            "强壮 ",
            "{name}: the same bytes are GBK text"
        );
        assert_eq!(
            wolf_format::bytes::decode_wolf_str(strip_nul(collision)),
            "强壮 ",
            "{name}: the scored decoder recovers the GBK reading"
        );
    }
}

/// Load -> save through the engine-shaped lossy view leaves every cell and the
/// whole variable-database segment byte-identical.
#[test]
fn load_then_save_keeps_every_text_cell_byte_identical() {
    for name in FILES {
        let Some((original, save)) = read(name) else {
            return;
        };

        // The game's database layer hands `set_text` a lossy UTF-8 view.
        let mut db = save.vardb.clone();
        for (type_index, row_index, field_index, body) in text_cells(&save.vardb) {
            let text = lossy_view(&body);
            assert!(
                db.set_text(type_index, row_index, field_index, &text),
                "{name}: type {type_index} row {row_index} field {field_index} is writable"
            );
            assert_eq!(
                db.string(type_index, row_index, field_index),
                Some(body.as_slice()),
                "{name}: type {type_index} row {row_index} field {field_index} changed bytes \
                 while its text was unchanged"
            );
        }
        assert_eq!(
            db.to_bytes().expect("encode"),
            save.chunk_bytes(VARDB_ID).expect("vardb bytes"),
            "{name}: the re-encoded segment differs"
        );

        // The same through the real decoder, which is what a future fixed
        // database layer will hand over.
        let mut decoded_db = save.vardb.clone();
        for (type_index, row_index, field_index, body) in text_cells(&save.vardb) {
            let text = wolf_format::bytes::decode_wolf_str(strip_nul(&body));
            assert!(decoded_db.set_text(type_index, row_index, field_index, &text));
            assert_eq!(
                decoded_db.string(type_index, row_index, field_index),
                Some(body.as_slice()),
                "{name}: correct-decode write changed type {type_index} row {row_index} \
                 field {field_index}"
            );
        }
        assert_eq!(
            decoded_db.to_bytes().expect("encode"),
            save.chunk_bytes(VARDB_ID).expect("vardb bytes"),
            "{name}: the real-decode re-encode differs"
        );

        // Fold the segment back into the file: the whole save must come back.
        let mut edited = save.clone();
        edited.set_vardb(&db).expect("set_vardb");
        let written = edited.to_bytes_rebuilt().expect("rebuild");
        if let Some(at) = first_difference(&original, &written) {
            panic!("{name}: written save differs at offset {at:#X}");
        }
    }
}

/// A genuinely new Chinese string is stored in the code page retail uses.
#[test]
fn a_new_chinese_string_is_stored_as_gbk() {
    let Some((_original, save)) = read(FILES[0]) else {
        return;
    };
    for (text, expected) in [
        ("行动力", vec![0xD0, 0xD0, 0xB6, 0xAF, 0xC1, 0xA6, 0]),
        (
            "没有数据",
            vec![0xC3, 0xBB, 0xD3, 0xD0, 0xCA, 0xFD, 0xBE, 0xDD, 0],
        ),
        (
            "持有金钱",
            vec![0xB3, 0xD6, 0xD3, 0xD0, 0xBD, 0xF0, 0xC7, 0xAE, 0],
        ),
    ] {
        let mut db = save.vardb.clone();
        assert!(db.set_text(0, 0, 0, text));
        assert_eq!(
            cell(&db, 0, 0, 0),
            expected.as_slice(),
            "{text:?} must be written as GBK"
        );
        assert_ne!(
            cell(&db, 0, 0, 0),
            utf8_body(text).as_slice(),
            "{text:?} must not be written as UTF-8"
        );
        assert_eq!(
            wolf_format::bytes::decode_wolf_str(strip_nul(cell(&db, 0, 0, 0))),
            text
        );
    }

    // The edit reaches the file and reads back through the public API.
    let mut db = save.vardb.clone();
    assert!(db.set_text(0, 0, 0, "行动力"));
    let mut edited = save.clone();
    edited.set_vardb(&db).expect("set_vardb");
    let fresh = SaveFile::parse(&edited.to_bytes_rebuilt().expect("write")).expect("reparse");
    assert_eq!(
        wolf_format::bytes::decode_wolf_str(strip_nul(cell(&fresh.vardb, 0, 0, 0))),
        "行动力",
        "a saved Chinese string reads back"
    );
}

/// Text GBK cannot represent is kept self-consistent as UTF-8.
///
/// A character absent from the GBK table would become `?`, so those strings take
/// the UTF-8 fallback; the retail `Game.exe` would not render them, but the
/// engine's own round trip is exact. (The old `"强壮"` collision is no longer in
/// this list: its bytes are valid GBK and the scored decoder recovers them; see
/// `a_gbk_string_whose_bytes_are_valid_utf8_round_trips_as_gbk`.)
#[test]
fn text_gbk_cannot_round_trip_falls_back_to_utf8() {
    let Some((_original, save)) = read(FILES[0]) else {
        return;
    };
    for text in ["🎮", "Ω≈ç√∫"] {
        let mut db = save.vardb.clone();
        assert!(db.set_text(0, 0, 0, text), "{text:?} writes");
        let body = cell(&db, 0, 0, 0);
        assert_eq!(
            body,
            utf8_body(text).as_slice(),
            "{text:?} must fall back to UTF-8"
        );
        assert_eq!(
            wolf_format::bytes::decode_wolf_str(strip_nul(body)),
            text,
            "{text:?} must decode back to itself"
        );
        assert!(
            !body.contains(&b'?'),
            "{text:?} must not be lossy-encoded to '?'"
        );
    }
}

/// A GBK body whose bytes also spell valid UTF-8 is written as GBK and read
/// back as the GBK text, thanks to the scored decoder.
#[test]
fn a_gbk_string_whose_bytes_are_valid_utf8_round_trips_as_gbk() {
    let Some((_original, save)) = read(FILES[0]) else {
        return;
    };
    let mut db = save.vardb.clone();
    assert!(db.set_text(0, 0, 0, "强壮"));
    assert_eq!(
        cell(&db, 0, 0, 0),
        &[0xC7, 0xBF, 0xD7, 0xB3, 0][..],
        "the collision string is written as GBK, not UTF-8"
    );
    assert_eq!(
        wolf_format::bytes::decode_wolf_str(strip_nul(cell(&db, 0, 0, 0))),
        "强壮"
    );
}

/// A new Japanese string keeps its text even though only a GBK encoder exists.
#[test]
fn a_new_japanese_string_round_trips_through_the_gbk_encoder() {
    let Some((_original, save)) = read(FILES[0]) else {
        return;
    };
    let mut db = save.vardb.clone();
    // Type 0 row 0 field 0 currently holds "ヒーローさん"; change it so the
    // unchanged-body retention cannot apply.
    assert!(db.set_text(0, 0, 0, "ウィッチさん"));
    let body = cell(&db, 0, 0, 0);
    assert!(!body.contains(&b'?'), "no character was lost");
    assert_eq!(
        wolf_format::bytes::decode_wolf_str(strip_nul(body)),
        "ウィッチさん"
    );
    assert_ne!(
        body,
        &[0x83, 0x45, 0x83, 0x42, 0x83, 0x62, 0x83, 0x60, 0x82, 0xB3, 0x82, 0xF1, 0][..],
        "the writer has no CP932 encoder, so a new string is not the retail CP932 spelling"
    );
}

/// `set_string` remains verbatim: no code-page guessing, no normalization.
#[test]
fn set_string_keeps_bytes_verbatim() {
    let Some((_original, save)) = read(FILES[0]) else {
        return;
    };
    let mut db = save.vardb.clone();

    let gbk = [0xD0, 0xD0, 0xB6, 0xAF, 0xC1, 0xA6, 0];
    assert!(db.set_string(0, 0, 0, &gbk));
    assert_eq!(cell(&db, 0, 0, 0), gbk.as_slice());

    // A UTF-8 body is kept byte for byte too, even though `set_text` would
    // normalize it to GBK.
    let utf8 = [0xE8, 0xA1, 0x8C, 0xE5, 0x8A, 0xA8, 0xE5, 0x8A, 0x9B, 0];
    assert!(db.set_string(0, 0, 0, &utf8));
    assert_eq!(cell(&db, 0, 0, 0), utf8.as_slice());

    // A raw body without a terminator stays without one.
    assert!(db.set_string(0, 0, 0, &[0x41]));
    assert_eq!(cell(&db, 0, 0, 0), &[0x41][..]);
}

/// ASCII and empty text are encoding-independent.
#[test]
fn ascii_and_empty_text_are_encoding_independent() {
    let Some((_original, save)) = read(FILES[0]) else {
        return;
    };
    let mut db = save.vardb.clone();
    assert!(db.set_text(0, 0, 0, "Z"));
    assert_eq!(cell(&db, 0, 0, 0), &[0x5A, 0][..]);
    assert!(db.set_text(0, 0, 0, ""));
    assert_eq!(cell(&db, 0, 0, 0), &[0][..]);
    // The empty body is stable through another write of the empty string.
    assert!(db.set_text(0, 0, 0, ""));
    assert_eq!(cell(&db, 0, 0, 0), &[0][..]);
}

/// The expected bytes above encode what the GBK table does; keep them honest.
#[test]
fn the_expected_gbk_bytes_match_the_table() {
    for (text, expected) in [
        ("行动力", vec![0xD0, 0xD0, 0xB6, 0xAF, 0xC1, 0xA6, 0]),
        (
            "没有数据",
            vec![0xC3, 0xBB, 0xD3, 0xD0, 0xCA, 0xFD, 0xBE, 0xDD, 0],
        ),
        (
            "持有金钱",
            vec![0xB3, 0xD6, 0xD3, 0xD0, 0xBD, 0xF0, 0xC7, 0xAE, 0],
        ),
        ("早泄", vec![0xD4, 0xE7, 0xD0, 0xB9, 0]),
    ] {
        let mut bytes = wolf_format::gbk::encode(text);
        bytes.push(0);
        assert_eq!(bytes, expected, "{text:?}");
    }
}

/// A body already in UTF-8 (written by an older build of this engine) is
/// normalized to GBK when the text is written again.
///
/// This is the boundary of the unchanged-body rule: only bodies that are not
/// valid UTF-8 are treated as legacy and retained.
#[test]
fn a_utf8_body_from_an_older_write_is_normalized_to_gbk() {
    let mut db = VariableDatabase {
        unknown: 0x6F,
        type_count: 0,
        types: Vec::new(),
    };
    db.types.push(wolf_save::vardb::VariableType {
        unknown: -2,
        dis: 0,
        field_count: 1,
        config: vec![2000],
        row_count: 1,
        rows: vec![wolf_save::vardb::VariableRow {
            index: 0,
            fields: vec![wolf_save::vardb::VariableField {
                id: 0,
                value: VariableValue::String(
                    [0xE8, 0xA1, 0x8C, 0xE5, 0x8A, 0xA8, 0xE5, 0x8A, 0x9B, 0].to_vec(),
                ),
            }],
        }],
    });
    assert!(db.set_text(0, 0, 0, "行动力"));
    assert_eq!(
        cell(&db, 0, 0, 0),
        &[0xD0, 0xD0, 0xB6, 0xAF, 0xC1, 0xA6, 0][..]
    );
}
