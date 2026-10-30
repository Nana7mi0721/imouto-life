//! `TileSetData.dat` loader.
//!
//! Layout is documented in `docs/FORMAT_SPEC.md` §7: the same container as the
//! databases (§6), one record per tileset, each holding the base image, 31
//! autotile image slots, a per-tile tag byte and a per-tile passability word.
//!
//! Two things the real data forces on the loader:
//!
//! * The 31 autotile names of tileset 5 are genuinely corrupt on disk (UTF-8
//!   text that was double-encoded once already). They are kept as raw bytes in
//!   [`TileSet::raw_autotile_bytes`] and decoded lossily for display only, so a
//!   re-encode never has to invent characters that were not in the file.
//! * Bits 8 and 9 of the passability word carry data in this game's tilesets
//!   (values 1, 2 and 3 occur), so the loader exposes them as
//!   [`TilePassability::na`] instead of asserting the spec's "must be zero".

use crate::bytes::Reader;
use crate::error::{Error, Result};

/// Number of autotile slots in the version 210 layout.
pub const AUTOTILE_SLOTS_210: usize = 31;
/// Number of autotile slots in the legacy version 209 layout.
pub const AUTOTILE_SLOTS_209: usize = 15;

/// A parsed `TileSetData.dat`.
#[derive(Debug, Clone)]
pub struct TileSetData {
    /// Container version byte, `0xD2` (210) in this game.
    pub version: u8,
    /// Tilesets in file order; the index is what [`Map::tileset_index`] refers to.
    ///
    /// [`Map::tileset_index`]: crate::mps::Map::tileset_index
    pub tilesets: Vec<TileSet>,
    /// Footer byte, `0xCF`.
    pub footer: u8,
}

impl TileSetData {
    /// Container magic: `00 57 00 00 4F 4C`.
    pub const MAGIC: [u8; 6] = [0x00, 0x57, 0x00, 0x00, 0x4F, 0x4C];
    /// Container type magic: `FM\0`.
    pub const MAGIC_TYPE: [u8; 3] = [0x46, 0x4D, 0x00];
    /// Container version this loader implements.
    pub const VERSION_210: u8 = 0xD2;
    /// Legacy container version, still supported for the shorter autotile list.
    pub const VERSION_209: u8 = 0xD1;
    /// Footer byte.
    pub const FOOTER: u8 = 0xCF;
    /// Separator byte between the autotile slots and the tag list.
    pub const SEPARATOR: u8 = 0xFF;

    /// Parse a whole `TileSetData.dat`.
    pub fn parse(data: &[u8]) -> Result<Self> {
        let mut r = Reader::new(data);
        r.expect(&Self::MAGIC, "tileset magic")?;
        let version_header = r.u8()?;
        r.expect(&Self::MAGIC_TYPE, "tileset magic type")?;
        let version = r.u8()?;
        if version != Self::VERSION_210 && version != Self::VERSION_209 {
            return Err(Error::field(
                "tileset version",
                r.pos() - 1,
                format!("unsupported TileSetData version 0x{version:02X}"),
            ));
        }
        let _ = version_header;
        let count = r.u32()? as usize;
        // A tileset record is at least 142 bytes (two names, 31 autotile slots,
        // two separators and two list counts), so this loose bound rejects a
        // corrupt count without risking a false rejection.
        if count > r.remaining() / 8 {
            return Err(Error::field(
                "tileset count",
                r.pos() - 4,
                format!("{count} tilesets do not fit in {} bytes", r.remaining()),
            ));
        }
        let mut tilesets = Vec::with_capacity(count);
        for _ in 0..count {
            tilesets.push(TileSet::read(&mut r, version)?);
        }
        let footer = r.u8()?;
        if footer != Self::FOOTER {
            return Err(Error::magic(
                "tileset footer",
                r.pos() - 1,
                &[footer],
                &[Self::FOOTER],
            ));
        }
        while !r.at_end() {
            if r.u8()? != 0 {
                return Err(Error::trailing(r.pos() - 1, r.remaining() + 1));
            }
        }
        Ok(Self {
            version,
            tilesets,
            footer,
        })
    }

    /// Look a tileset up by the index stored in a map header.
    pub fn get(&self, index: u32) -> Option<&TileSet> {
        self.tilesets.get(index as usize)
    }
}

/// One tileset: a base tile image plus up to 31 autotile images.
#[derive(Debug, Clone)]
pub struct TileSet {
    /// Tileset name shown in the editor.
    pub name: String,
    /// Base tile image path, relative to the game root.
    pub base_image: String,
    /// Autotile image paths, decoded lossily from [`Self::raw_autotile_bytes`].
    pub autotiles: Vec<String>,
    /// Autotile image paths exactly as stored, NUL terminator removed.
    ///
    /// Kept because a few of them are not valid UTF-8; see the module docs.
    pub raw_autotile_bytes: Vec<Vec<u8>>,
    /// One tag byte per tile, parallel to [`Self::passability`].
    pub tags: Vec<u8>,
    /// One passability word per tile, parallel to [`Self::tags`].
    pub passability: Vec<TilePassability>,
}

impl TileSet {
    /// Number of autotile slots for a container version.
    pub fn autotile_slots(version: u8) -> usize {
        if version == TileSetData::VERSION_210 {
            AUTOTILE_SLOTS_210
        } else {
            AUTOTILE_SLOTS_209
        }
    }

    fn read(r: &mut Reader<'_>, version: u8) -> Result<Self> {
        let name = r.t_str()?;
        let base_image = r.t_str()?;
        let slots = Self::autotile_slots(version);
        let mut autotiles = Vec::with_capacity(slots);
        let mut raw_autotile_bytes = Vec::with_capacity(slots);
        for _ in 0..slots {
            let raw = r.t_str_bytes()?.to_vec();
            autotiles.push(String::from_utf8_lossy(&raw).into_owned());
            raw_autotile_bytes.push(raw);
        }

        r.expect_u8(TileSetData::SEPARATOR, "tileset separator 1")?;
        let tag_count = r.u32()? as usize;
        if tag_count > r.remaining() {
            return Err(Error::eof(r.pos(), tag_count, r.remaining()));
        }
        let tags = r.take(tag_count)?.to_vec();

        r.expect_u8(TileSetData::SEPARATOR, "tileset separator 2")?;
        let passable_count = r.u32()? as usize;
        let passable = r.u32_array(passable_count)?;
        let passability = passable.into_iter().map(TilePassability::decode).collect();

        Ok(Self {
            name,
            base_image,
            autotiles,
            raw_autotile_bytes,
            tags,
            passability,
        })
    }
}

/// One passability word of a tileset, both raw and decoded.
///
/// Bit layout (least significant bit first), see `docs/FORMAT_SPEC.md` §7.3:
/// bit 0 counter, bit 1 square, bit 2 quarter tile, bit 3 star, bits 4-7 the
/// four directional flags, bits 8-13 reserved, bit 14 down arrow, bit 15
/// triangle.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct TilePassability {
    /// The word exactly as stored.
    pub raw: u32,
    /// Bit 0: the tile can carry a counter (event) on top.
    pub counter_enabled: bool,
    /// Bit 1: the collision shape is a square.
    pub square: bool,
    /// Bit 2: the collision shape is a quarter tile instead of a full tile.
    pub quarter_tile: bool,
    /// Bit 3: the tile is a star tile (never blocks, always drawn on top).
    pub star: bool,
    /// Bits 4-7 when [`Self::quarter_tile`] is set: passable from the top left.
    pub top_left_passable: bool,
    /// Bits 4-7 when [`Self::quarter_tile`] is set: passable from the top right.
    pub top_right_passable: bool,
    /// Bits 4-7 when [`Self::quarter_tile`] is set: passable from the bottom left.
    pub bottom_left_passable: bool,
    /// Bits 4-7 when [`Self::quarter_tile`] is set: passable from the bottom right.
    pub bottom_right_passable: bool,
    /// Bits 4-7 when [`Self::quarter_tile`] is clear: blocked when moving up.
    pub upwards_not_passable: bool,
    /// Bits 4-7 when [`Self::quarter_tile`] is clear: blocked when moving right.
    pub rightwards_not_passable: bool,
    /// Bits 4-7 when [`Self::quarter_tile`] is clear: blocked when moving left.
    pub leftwards_not_passable: bool,
    /// Bits 4-7 when [`Self::quarter_tile`] is clear: blocked when moving down.
    pub downwards_not_passable: bool,
    /// Bits 8-13: reserved in the spec, but **not** zero in this game's data —
    /// values 1, 2 and 3 occur, so they are exposed rather than rejected.
    pub na: u8,
    /// Bit 14: down arrow tile.
    pub downarrow: bool,
    /// Bit 15: triangle tile.
    pub triangle: bool,
    /// Bits 16-31: reserved upper half; zero in every shipped tileset.
    pub upper: u16,
}

impl TilePassability {
    /// Decode a raw passability word.
    pub fn decode(raw: u32) -> Self {
        let bit = |n: u32| (raw >> n) & 1 == 1;
        let quarter = bit(2);
        let d0 = bit(4);
        let d1 = bit(5);
        let d2 = bit(6);
        let d3 = bit(7);
        Self {
            raw,
            counter_enabled: bit(0),
            square: bit(1),
            quarter_tile: quarter,
            star: bit(3),
            // The same four bits mean "passable towards" for a quarter tile and
            // "blocked towards" for a full tile; both views are exposed.
            top_left_passable: d0,
            top_right_passable: d1,
            bottom_left_passable: d2,
            bottom_right_passable: d3,
            upwards_not_passable: d0,
            rightwards_not_passable: d1,
            leftwards_not_passable: d2,
            downwards_not_passable: d3,
            na: ((raw >> 8) & 0x3F) as u8,
            downarrow: bit(14),
            triangle: bit(15),
            upper: (raw >> 16) as u16,
        }
    }

    /// Directional flag for a full tile: is movement from `direction` blocked?
    ///
    /// `direction` is 0 up, 1 right, 2 left, 3 down; `None` for any other value.
    pub fn blocked(&self, direction: u8) -> Option<bool> {
        match direction {
            0 => Some(self.upwards_not_passable),
            1 => Some(self.rightwards_not_passable),
            2 => Some(self.leftwards_not_passable),
            3 => Some(self.downwards_not_passable),
            _ => None,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn container_constants_match_the_spec() {
        assert_eq!(TileSetData::MAGIC, [0x00, 0x57, 0x00, 0x00, 0x4F, 0x4C]);
        assert_eq!(TileSetData::MAGIC_TYPE, *b"FM\0");
        assert_eq!(TileSetData::VERSION_210, 210);
        assert_eq!(TileSetData::FOOTER, 0xCF);
        assert_eq!(TileSetData::SEPARATOR, 0xFF);
        assert_eq!(AUTOTILE_SLOTS_210, 31);
        assert_eq!(AUTOTILE_SLOTS_209, 15);
    }

    #[test]
    fn passability_decodes_the_documented_bits() {
        // Bit 0 only: counter enabled, otherwise a plain full tile.
        let counter = TilePassability::decode(0x0000_0001);
        assert!(counter.counter_enabled);
        assert!(!counter.square);
        assert!(!counter.quarter_tile);
        assert!(!counter.star);
        assert_eq!(counter.na, 0);
        assert_eq!(counter.upper, 0);
        assert!(!counter.downarrow);
        assert!(!counter.triangle);

        // Quarter tile with all four quadrants passable.
        let quarter = TilePassability::decode(0x0000_00F4);
        assert!(quarter.quarter_tile);
        assert!(quarter.top_left_passable);
        assert!(quarter.top_right_passable);
        assert!(quarter.bottom_left_passable);
        assert!(quarter.bottom_right_passable);
        assert_eq!(quarter.na, 0);

        // Full tile blocked upwards and rightwards (bits 4 and 5).
        let blocked = TilePassability::decode(0x0000_0030);
        assert!(!blocked.quarter_tile);
        assert!(blocked.upwards_not_passable);
        assert!(blocked.rightwards_not_passable);
        assert!(!blocked.leftwards_not_passable);
        assert!(!blocked.downwards_not_passable);
        assert_eq!(blocked.blocked(0), Some(true));
        assert_eq!(blocked.blocked(1), Some(true));
        assert_eq!(blocked.blocked(2), Some(false));
        assert_eq!(blocked.blocked(3), Some(false));
        assert_eq!(blocked.blocked(4), None);

        // Bits 8-9 carry real data in this game, and the upper half is a u16.
        let reserved = TilePassability::decode(0x0000_0300);
        assert_eq!(reserved.na, 3);
        assert_eq!(reserved.upper, 0);
        assert!(TilePassability::decode(0xFFFF_0000).upper == 0xFFFF);
        assert!(TilePassability::decode(0x0000_4000).downarrow);
        assert!(TilePassability::decode(0x0000_8000).triangle);
    }
}
