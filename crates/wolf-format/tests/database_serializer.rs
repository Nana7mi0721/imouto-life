//! Byte-exact round-trip checks for the record database serializer.
//!
//! Each check parses a shipped database and re-serializes it, asserting the two
//! byte strings are identical. When the unpacked data is not present the test
//! prints a skip note and returns, so `cargo test --workspace` stays green on a
//! machine without `work/Data`.

use std::path::PathBuf;

use wolf_format::database::Database;

/// The unpacked data root: `WOLF_DATA_ROOT` when set, else `work/full`.
fn data_root() -> PathBuf {
    std::env::var_os("WOLF_DATA_ROOT")
        .map(PathBuf::from)
        .unwrap_or_else(|| PathBuf::from("work/full"))
}

fn first_mismatch(expected: &[u8], actual: &[u8]) -> Option<usize> {
    let limit = expected.len().min(actual.len());
    for index in 0..limit {
        if expected[index] != actual[index] {
            return Some(index);
        }
    }
    (expected.len() != actual.len()).then_some(limit)
}

fn assert_round_trips(name: &str) {
    let path = data_root().join("BasicData").join(name);
    let bytes = match std::fs::read(&path) {
        Ok(bytes) => bytes,
        Err(error) => {
            eprintln!("skipping {name}: cannot read {} ({error})", path.display());
            return;
        }
    };
    let database = Database::parse(&bytes).expect("parse shipped database");
    let rebuilt = database.to_bytes();
    if let Some(offset) = first_mismatch(&bytes, &rebuilt) {
        panic!(
            "{name} did not round-trip: first difference at offset {offset:#x} \
             (original {} bytes, rebuilt {} bytes)",
            bytes.len(),
            rebuilt.len()
        );
    }
    assert_eq!(
        rebuilt.len(),
        bytes.len(),
        "{name}: rebuilt length must match the original"
    );
}

#[test]
fn data_database_round_trips_byte_for_byte() {
    assert_round_trips("DataBase.dat");
}

#[test]
fn cdata_database_round_trips_byte_for_byte() {
    assert_round_trips("CDataBase.dat");
}

#[test]
fn sys_database_round_trips_byte_for_byte() {
    assert_round_trips("SysDatabase.dat");
}
