//! Integration test: `MapTree.dat` and `MapTreeOpenStatus.dat` parse byte-exactly.
//!
//! Expected values come from the shipped 416-byte / 75-byte files. The test skips
//! itself when the data tree is absent so the crate stays testable without the
//! game files (same convention as tests/mps.rs).

use std::path::PathBuf;

use wolf_format::maptree::{MapTree, MapTreeOpenStatus};

fn data_root() -> PathBuf {
    let raw = match std::env::var("WOLF_DATA_ROOT") {
        Ok(value) if !value.is_empty() => PathBuf::from(value),
        _ => PathBuf::from("work/full"),
    };
    if raw.is_absolute() {
        return raw;
    }
    let manifest = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    let workspace = manifest
        .parent()
        .and_then(|crates| crates.parent())
        .unwrap_or(&manifest);
    let candidate = workspace.join(&raw);
    if candidate.is_dir() {
        candidate
    } else {
        raw
    }
}

fn synthetic(entries: &[(i32, u32)], footer: u8) -> Vec<u8> {
    let mut bytes = vec![0u8; 10];
    bytes.push(MapTree::VERSION);
    bytes.extend_from_slice(&(entries.len() as u32).to_le_bytes());
    for (parent, map_id) in entries {
        bytes.extend_from_slice(&parent.to_le_bytes());
        bytes.extend_from_slice(&map_id.to_le_bytes());
    }
    bytes.push(footer);
    bytes
}

#[test]
fn a_synthetic_tree_round_trips_through_the_parser() {
    let bytes = synthetic(&[(-1, 0), (0, 3), (0, 24), (-1, 7)], MapTree::FOOTER);
    let tree = MapTree::parse(&bytes).expect("parse");
    assert_eq!(tree.version, MapTree::VERSION);
    assert_eq!(tree.footer, MapTree::FOOTER);
    assert_eq!(tree.entries.len(), 4);
    assert_eq!(tree.entries[1].parent, 0);
    assert_eq!(tree.entries[1].map_id, 3);
    assert_eq!(
        tree.roots().iter().map(|e| e.map_id).collect::<Vec<_>>(),
        vec![0, 7]
    );
    assert_eq!(tree.children_of(0), vec![3, 24]);
    assert!(tree.contains_map(24));
    assert!(!tree.contains_map(99));
}

#[test]
fn a_truncated_tree_is_an_error_not_a_panic() {
    let mut bytes = synthetic(&[(-1, 0), (0, 3)], MapTree::FOOTER);
    bytes.truncate(bytes.len() - 3);
    assert!(MapTree::parse(&bytes).is_err());
}

#[test]
fn the_shipped_tree_decodes_to_fifty_entries_and_three_hook_children() {
    let path = data_root().join("BasicData").join("MapTree.dat");
    let bytes = match std::fs::read(&path) {
        Ok(bytes) => bytes,
        Err(_) => {
            eprintln!("skipping: {} not readable", path.display());
            return;
        }
    };
    assert_eq!(bytes.len(), 416, "shipped MapTree.dat is 416 bytes");
    let tree = MapTree::parse(&bytes).expect("parse MapTree.dat");
    assert_eq!(tree.version, MapTree::VERSION);
    assert_eq!(tree.footer, MapTree::FOOTER);
    assert_eq!(tree.entries.len(), 50);
    // 47 roots: every map is a root except the three hook maps, whose parent is 0.
    assert_eq!(tree.roots().len(), 47);
    assert_eq!(tree.children_of(0), vec![3, 24, 31]);
    assert_eq!(tree.entries[0].map_id, 0);
    assert_eq!(tree.entries[0].parent, -1);
    // Map ids form a permutation of 0..50 with no duplicates.
    let mut ids: Vec<u32> = tree.entries.iter().map(|e| e.map_id).collect();
    ids.sort_unstable();
    ids.dedup();
    assert_eq!(ids.len(), 50);
    assert_eq!(ids.first(), Some(&0));
    assert_eq!(ids.last(), Some(&49));
}

#[test]
fn the_shipped_open_status_is_fifty_flags_with_only_the_title_map_open() {
    let path = data_root().join("BasicData").join("MapTreeOpenStatus.dat");
    let bytes = match std::fs::read(&path) {
        Ok(bytes) => bytes,
        Err(_) => {
            eprintln!("skipping: {} not readable", path.display());
            return;
        }
    };
    assert_eq!(bytes.len(), 75);
    let status = MapTreeOpenStatus::parse(&bytes).expect("parse MapTreeOpenStatus.dat");
    assert_eq!(status.footer, MapTreeOpenStatus::FOOTER);
    assert_eq!(status.open.len(), 50);
    assert_eq!(status.open.iter().filter(|&&flag| flag != 0).count(), 1);
    assert!(status.is_open(0));
    assert!(!status.is_open(1));
    assert!(!status.is_open(100));
}
