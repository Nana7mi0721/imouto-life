//! Integration test: a VER6 ".wolf" archive opens and extracts byte-exactly.
//!
//! This game's retail data is a VER6 archive (`Data.wolf`); the unpacked
//! reference tree is the zh-CN `work/Data` tree. The archive test skips when
//! neither the archive nor the reference tree is present, so the crate stays
//! testable without the retail files. Two data-independent rejection tests pin
//! the header validation.

use std::path::PathBuf;

use wolf_format::dxarchive::DxArchive;
use wolf_format::Error;

/// Compare the first differing byte, if any.
fn first_difference(left: &[u8], right: &[u8]) -> Option<usize> {
    left.iter()
        .zip(right.iter())
        .position(|(a, b)| a != b)
        .or_else(|| {
            if left.len() == right.len() {
                None
            } else {
                Some(left.len().min(right.len()))
            }
        })
}

#[test]
fn rejects_a_foreign_header() {
    let error = DxArchive::open(&[0u8; 64]).expect_err("zeroed bytes are not a DX archive");
    assert!(
        matches!(error, Error::Magic { .. }),
        "expected a magic mismatch, got {error:?}"
    );
}

#[test]
fn rejects_version_seven() {
    let mut bytes = [0u8; 64];
    bytes[0..2].copy_from_slice(&0x5844u16.to_le_bytes());
    bytes[2..4].copy_from_slice(&7u16.to_le_bytes());
    let error = DxArchive::open(&bytes).expect_err("version 7 is not readable");
    match error {
        Error::Field { what, msg, .. } => {
            assert_eq!(what, "DXArchive head");
            assert!(
                msg.contains("version"),
                "message mentions the version: {msg}"
            );
        }
        other => panic!("expected a field error, got {other:?}"),
    }
}

// ---------------------------------------------------------------------------
// DXArchive version 6 (old-generation) coverage
// ---------------------------------------------------------------------------

/// Retail install of "Imouto! Life ~Monochrome~" whose `Data.wolf` is a VER6
/// archive. Used when neither WOLF_DATA_WOLF nor WOLF_GAME_DIR points at one.
const DEFAULT_VER6_DATA_WOLF: &str =
    r"E:\EROGAME\Imouto! Life ~Monochrome~ zh-CN Ver\Data.wolf";

/// Resolve the VER6 `Data.wolf`, preferring the environment over the default.
///
/// Candidate order: `WOLF_DATA_WOLF` (a direct archive path), then
/// `WOLF_GAME_DIR/Data.wolf`, then the hard-coded retail path. The first one
/// that exists on disk wins; when none does the test skips.
fn ver6_data_wolf() -> Option<PathBuf> {
    let mut candidates: Vec<PathBuf> = Vec::new();
    if let Ok(raw) = std::env::var("WOLF_DATA_WOLF") {
        if !raw.is_empty() {
            candidates.push(PathBuf::from(raw));
        }
    }
    if let Ok(dir) = std::env::var("WOLF_GAME_DIR") {
        if !dir.is_empty() {
            candidates.push(PathBuf::from(dir).join("Data.wolf"));
        }
    }
    candidates.push(PathBuf::from(DEFAULT_VER6_DATA_WOLF));

    for candidate in &candidates {
        if candidate.is_file() {
            return Some(candidate.clone());
        }
    }
    eprintln!(
        "skipping: no VER6 Data.wolf, set WOLF_DATA_WOLF or WOLF_GAME_DIR (looked in {})",
        candidates
            .iter()
            .map(|path| path.display().to_string())
            .collect::<Vec<_>>()
            .join(", ")
    );
    None
}

/// The unpacked reference tree for the VER6 archive (`work/Data`), if present.
fn ver6_reference_root() -> Option<PathBuf> {
    let manifest = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    let workspace = manifest.parent().and_then(|crates| crates.parent())?;
    let work = workspace.join("work").join("Data");
    if work.is_dir() {
        Some(work)
    } else {
        let direct = workspace.join("Data");
        direct.is_dir().then_some(direct)
    }
}

/// Read, decode and (when a reference tree exists) byte-compare every entry.
#[test]
fn ver6_data_wolf_extracts_every_entry() {
    let Some(path) = ver6_data_wolf() else {
        return;
    };
    let bytes =
        std::fs::read(&path).unwrap_or_else(|error| panic!("read {}: {error}", path.display()));
    let archive = DxArchive::open(&bytes)
        .unwrap_or_else(|error| panic!("{} opens: {error}", path.display()));

    assert_eq!(archive.version(), 6, "Data.wolf version");
    assert_eq!(archive.char_code_format(), 932, "Data.wolf CharCodeFormat");
    assert_eq!(
        archive.data_start_address(),
        48,
        "Data.wolf DataStartAddress"
    );
    assert!(archive.is_encrypted(), "Data.wolf is XOR obfuscated");
    assert_eq!(archive.entries().len(), 1361, "Data.wolf file count");

    let reference = ver6_reference_root();
    if reference.is_none() {
        eprintln!("note: no unpacked reference tree, checking sizes and totals only");
    }

    let mut declared = 0u64;
    let mut decoded = 0u64;
    let mut compared = 0usize;
    for entry in archive.entries() {
        declared += entry.size;
        let data = archive
            .read(entry)
            .unwrap_or_else(|error| panic!("extract {}: {error}", entry.path()));
        assert_eq!(
            data.len() as u64,
            entry.size,
            "{} decoded length matches the directory entry",
            entry.path()
        );
        decoded += data.len() as u64;

        if let Some(root) = reference.as_ref() {
            let reference_path = root.join(entry.path());
            let expected = std::fs::read(&reference_path)
                .unwrap_or_else(|error| panic!("read {}: {error}", reference_path.display()));
            if let Some(index) = first_difference(&data, &expected) {
                panic!(
                    "{} differs from the reference at byte {index}: decoded {} byte(s), reference {} byte(s)",
                    entry.path(),
                    data.len(),
                    expected.len()
                );
            }
            compared += 1;
        }
    }

    assert_eq!(declared, 179_877_496, "sum of declared sizes");
    assert_eq!(decoded, 179_877_496, "sum of decoded bytes");
    if reference.is_some() {
        assert_eq!(compared, 1361, "every entry was byte-compared");
    }
}
