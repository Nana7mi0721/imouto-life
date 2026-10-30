//! `MapTree.dat` loader — the map tree the engine (and the editor's map list) uses
//! to order the registered maps.
//!
//! Layout was decoded from the shipped 416-byte file and is byte-exact:
//!
//! ```text
//! offset 0   : 10 x 0x00           header padding (the same 10 zero bytes every .dat shares)
//! offset 10  : u8   version        0x90 in this game
//! offset 11  : u32  entry_count    50 (matches the 50 rows of SysDatabase type 0)
//! offset 15  : entry_count x 8 B   { i32 parent_map_id, u32 map_id }
//! last byte  : u8   footer         0xBC
//! ```
//!
//! 11 + 4 + 50 * 8 + 1 = 416 bytes, exactly the file length, and the record stream
//! ends one byte short of EOF where the footer sits — so the offsets above are
//! verified rather than guessed.
//!
//! Semantics: `parent_map_id == -1` marks a root; the three entries whose parent is
//! `0` are map ids 3, 31 and 24 — precisely the three "hook" maps that carry no map
//! graphics (`Map003`, `Map031`, `Map024`, see docs/MAP_AUDIT.md §1.4). The order of
//! the entries is the tree's display order, which is why map 3 (the new-game hook)
//! appears right after the root.
//!
//! What this file does **not** contain is a start coordinate: there is no x/y field
//! anywhere in it, so the "new game starts at map N (x, y)" decision is not data
//! driven from here. See docs/FORMAT_SPEC.md §2.6 and docs/MAP_AUDIT.md §0.3.

use crate::bytes::Reader;
use crate::error::{Error, Result};

/// A parsed `MapTree.dat`.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct MapTree {
    /// Version byte at offset 10, `0x90` in this game.
    pub version: u8,
    /// Entries in file order (display order of the map tree).
    pub entries: Vec<MapTreeEntry>,
    /// Footer byte, `0xBC` in this game.
    pub footer: u8,
}

/// One `{ parent, map_id }` pair of the map tree.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct MapTreeEntry {
    /// Parent map id, or `-1` for a root of the tree.
    pub parent: i32,
    /// The map id this node points at (an index into SysDatabase type 0).
    pub map_id: u32,
}

impl MapTreeEntry {
    /// Whether this node is a root (`parent == -1`).
    #[must_use]
    pub const fn is_root(&self) -> bool {
        self.parent == -1
    }
}

impl MapTree {
    /// Ten zero bytes followed by the version byte `0x90`.
    pub const MAGIC: [u8; 10] = [0u8; 10];
    /// Version byte this game ships.
    pub const VERSION: u8 = 0x90;
    /// Footer byte this game ships.
    pub const FOOTER: u8 = 0xBC;

    /// Parse a `MapTree.dat` buffer.
    pub fn parse(data: &[u8]) -> Result<Self> {
        let mut reader = Reader::new(data);
        reader.expect(&Self::MAGIC, "MapTree magic")?;
        let version = reader.u8()?;
        let count = reader.u32()? as usize;
        // Guard against a corrupt count before allocating.
        if count > reader.remaining() / 8 {
            return Err(Error::field(
                "MapTree entry_count",
                reader.pos(),
                format!(
                    "declared {count} entries ({} bytes) but only {} remain",
                    count * 8,
                    reader.remaining()
                ),
            ));
        }
        let mut entries = Vec::with_capacity(count);
        for _ in 0..count {
            let parent = reader.i32()?;
            let map_id = reader.u32()?;
            entries.push(MapTreeEntry { parent, map_id });
        }
        let footer = reader.u8()?;
        reader.expect_end()?;
        Ok(Self {
            version,
            entries,
            footer,
        })
    }

    /// The roots of the tree, in display order.
    #[must_use]
    pub fn roots(&self) -> Vec<&MapTreeEntry> {
        self.entries
            .iter()
            .filter(|entry| entry.is_root())
            .collect()
    }

    /// Direct children of `map_id`, in display order.
    #[must_use]
    pub fn children_of(&self, map_id: i32) -> Vec<u32> {
        self.entries
            .iter()
            .filter(|entry| entry.parent == map_id)
            .map(|entry| entry.map_id)
            .collect()
    }

    /// Whether a map id appears anywhere in the tree.
    #[must_use]
    pub fn contains_map(&self, map_id: u32) -> bool {
        self.entries.iter().any(|entry| entry.map_id == map_id)
    }
}

/// A parsed `MapTreeOpenStatus.dat` (75 bytes).
///
/// ```text
/// offset 0  : 20 x 0x00        header padding
/// offset 20 : u32 count       50
/// offset 24 : count x u8      one open/closed flag per map id
/// last byte : u8 footer       0x26
/// ```
///
/// 20 + 4 + 50 + 1 = 75 bytes. In the shipped file only the first flag is `1`
/// (the title map is "open"); the rest are `0`. Because the flag count equals the
/// `MapTree.dat` entry count, flags are indexed by map id.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct MapTreeOpenStatus {
    /// One flag per map id, in map-id order.
    pub open: Vec<u8>,
    /// Footer byte, `0x26` in this game.
    pub footer: u8,
}

impl MapTreeOpenStatus {
    /// Version byte this game ships.
    pub const FOOTER: u8 = 0x26;

    /// Parse a `MapTreeOpenStatus.dat` buffer.
    pub fn parse(data: &[u8]) -> Result<Self> {
        let mut reader = Reader::new(data);
        reader.skip(20)?;
        let count = reader.u32()? as usize;
        if count > reader.remaining() {
            return Err(Error::field(
                "MapTreeOpenStatus count",
                reader.pos(),
                format!(
                    "declared {count} flags but only {} remain",
                    reader.remaining()
                ),
            ));
        }
        let mut open = Vec::with_capacity(count);
        for _ in 0..count {
            open.push(reader.u8()?);
        }
        let footer = reader.u8()?;
        reader.expect_end()?;
        Ok(Self { open, footer })
    }

    /// Whether map `map_id` is marked open (out-of-range ids read as closed).
    #[must_use]
    pub fn is_open(&self, map_id: u32) -> bool {
        self.open.get(map_id as usize).copied().unwrap_or(0) != 0
    }
}
