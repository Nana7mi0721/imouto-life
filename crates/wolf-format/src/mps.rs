//! `.mps` map loader.
//!
//! Layout is documented in `docs/FORMAT_SPEC.md` §5: a fixed header (magic, version,
//! title, tileset index, size, event count), an optional tile block of three
//! `width * height` layers, then the event stream and a one-byte footer.
//!
//! Two properties of the real data are preserved rather than "repaired":
//!
//! * Two of the 134 shipped map pages end with a `0x00` terminator instead of the
//!   documented `0x7A` (`Dungeon.mps` at offset 17716, `Map024.mps` at offset 234).
//!   The loader accepts those and keeps the raw byte in [`MapEventPage::footer`]
//!   so callers can still tell them apart from healthy pages.
//! * Event names are editor-truncated (e.g. `"妹クリック判定（夜"`); they are decoded
//!   lossily and never normalised.
//!
//! The four condition bytes of a page are `operator << 4 | enabled` for the
//! *variable* condition in the same slot, not "switch conditions": the shipped data
//! proves there is no switch id anywhere in the 37-byte block, so page selection is
//! driven by variables only. See [`MapEventPage::conditions`] and
//! `docs/FORMAT_SPEC.md` §5.6.3.

use crate::bytes::Reader;
use crate::command::{RouteData, Slot, SlotStats};
use crate::error::{Error, Result};

/// Number of tile layers in a `0x66` map file. The spec allows a `layer_count`
/// field from v3.5 on, but every map in this game uses the fixed three-layer format.
pub const LAYER_COUNT: usize = 3;

/// Number of activation-condition slots in a map page, see `docs/FORMAT_SPEC.md` §5.6.
///
/// The condition block is a fixed `1 + 4 + 4 * 4 + 4 * 4` bytes, so four slots is
/// the whole story — there is no room for switch ids, and the shipped data uses all
/// four slots as variable conditions.
pub const CONDITION_SLOTS: usize = 4;

/// A parsed `.mps` map.
#[derive(Debug, Clone)]
pub struct Map {
    /// Header byte at offset 16, `0x55` in every shipped map.
    pub version_header: u8,
    /// Map format version at offset 24, `0x66` in every shipped map.
    pub version: u8,
    /// Map name from the editor; only ever the literal `"なし"` ("none") in this game.
    pub name: String,
    /// Index into `TileSetData.dat`, see [`crate::tileset::TileSetData::get`].
    pub tileset_index: u32,
    /// Map width in tiles.
    pub width: u32,
    /// Map height in tiles.
    pub height: u32,
    /// `false` when the tile block is just the `0xFFFFFFFF` "no layer" marker.
    /// `Map024` and `Map031` are the two such maps.
    pub has_tile_data: bool,
    /// Three layers of `width * height` raw tile words, layer 0 (surface) first,
    /// then layer 1 (decoration), then layer 2 (top), row-major within each layer.
    /// Empty when [`Self::has_tile_data`] is `false`.
    pub layers: Vec<Vec<u32>>,
    /// Map events, in file order.
    pub events: Vec<MapEvent>,
    /// Footer byte, `0x66`.
    pub footer: u8,
}

impl Map {
    /// Ten zero bytes followed by `WOLFM\0`.
    pub const MAGIC: [u8; 16] = [
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x4F, 0x4C, 0x46, 0x4D,
        0x00,
    ];
    /// Three zero bytes between the version header and `unknown1`.
    pub const MAGIC2: [u8; 3] = [0x00, 0x00, 0x00];
    /// `unknown1` at offset 20; always 100 in this game's maps.
    pub const UNKNOWN1: u32 = 0x64;
    /// Map version bytes this loader understands. Both share the same layout.
    pub const VERSIONS: [u8; 2] = [0x65, 0x66];
    /// Tile word that marks "no tile" and, as the first word of the tile block,
    /// "this map has no tile layers at all".
    pub const EMPTY_TILE: u32 = 0xFFFF_FFFF;
    /// First byte of an event record.
    pub const EVENT_MAGIC: u8 = 0x6F;
    /// Second word of an event record; always 12345.
    pub const EVENT_MAGIC2: u32 = 12_345;
    /// Word between the page count and the first page; always 0.
    pub const EVENT_SEPARATOR: u32 = 0;
    /// Event footer byte.
    pub const EVENT_FOOTER: u8 = 0x70;
    /// First byte of a page record.
    pub const PAGE_MAGIC: u8 = 0x79;
    /// Documented page footer byte.
    pub const PAGE_FOOTER: u8 = 0x7A;
    /// Footer byte that two shipped pages carry instead of [`Self::PAGE_FOOTER`].
    pub const PAGE_FOOTER_TOLERATED: u8 = 0x00;
    /// Map footer byte.
    pub const FOOTER: u8 = 0x66;

    /// Parse a whole `.mps` file.
    ///
    /// Consumes the complete buffer: the event stream must be followed by the
    /// footer and then nothing but zero padding.
    pub fn parse(data: &[u8]) -> Result<Self> {
        let mut r = Reader::new(data);
        r.expect(&Self::MAGIC, "map magic")?;
        let version_header = r.u8()?;
        r.expect(&Self::MAGIC2, "map magic2")?;
        let unknown1 = r.u32()?;
        if unknown1 != Self::UNKNOWN1 {
            return Err(Error::field(
                "map unknown1",
                r.pos() - 4,
                format!("expected {}, got {unknown1}", Self::UNKNOWN1),
            ));
        }
        let version = r.u8()?;
        if !Self::VERSIONS.contains(&version) {
            return Err(Error::field(
                "map version",
                r.pos() - 1,
                format!("unsupported map version 0x{version:02X}"),
            ));
        }
        let name = r.t_str()?;
        let tileset_index = r.u32()?;
        let width = r.u32()?;
        let height = r.u32()?;
        let event_count = r.u32()? as usize;
        // An event record is at least 29 bytes, so a wildly larger count cannot be
        // real. The bound below is deliberately looser than that: it only has to
        // stop a corrupt header from driving the loop, never reject real data.
        if event_count > r.remaining() / 8 {
            return Err(Error::field(
                "map event count",
                r.pos() - 4,
                format!("{event_count} events do not fit in {} bytes", r.remaining()),
            ));
        }

        let first_pixel = r.u32()?;
        let (has_tile_data, layers) = if first_pixel == Self::EMPTY_TILE {
            (false, Vec::new())
        } else {
            let pixels = (width as u64) * (height as u64) * (LAYER_COUNT as u64) * 4;
            // The first word has already been consumed above.
            let needed = pixels.saturating_sub(4);
            if needed > r.remaining() as u64 {
                return Err(Error::eof(r.pos(), needed as usize, r.remaining()));
            }
            let per_layer = (width as usize) * (height as usize);
            let mut layers = Vec::with_capacity(LAYER_COUNT);
            for layer in 0..LAYER_COUNT {
                let mut values = Vec::with_capacity(per_layer);
                if layer == 0 {
                    values.push(first_pixel);
                }
                while values.len() < per_layer {
                    values.push(r.u32()?);
                }
                layers.push(values);
            }
            (true, layers)
        };

        let mut events = Vec::new();
        while !r.at_end() && r.peek_u8()? == Self::EVENT_MAGIC {
            events.push(MapEvent::read(&mut r)?);
        }
        if events.len() != event_count {
            return Err(Error::field(
                "map event count",
                r.pos(),
                format!(
                    "header declares {event_count} events, found {}",
                    events.len()
                ),
            ));
        }

        let footer = r.u8()?;
        if footer != Self::FOOTER {
            return Err(Error::magic(
                "map footer",
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
            version_header,
            version,
            name,
            tileset_index,
            width,
            height,
            has_tile_data,
            layers,
            events,
            footer,
        })
    }

    /// Command statistics over every page of every event.
    pub fn stats(&self) -> SlotStats {
        let mut stats = SlotStats::default();
        for event in &self.events {
            for page in &event.pages {
                stats.extend(page.commands.iter());
            }
        }
        stats
    }

    /// Raw tile word of `layer` at `(x, y)`, if both are inside the map.
    pub fn tile(&self, layer: usize, x: u32, y: u32) -> Option<u32> {
        if x >= self.width || y >= self.height {
            return None;
        }
        let index = y as usize * self.width as usize + x as usize;
        self.layers.get(layer)?.get(index).copied()
    }
}

/// A map event: the position on the map plus one page per configured state.
#[derive(Debug, Clone)]
pub struct MapEvent {
    /// Event id, unique within the map.
    pub id: u32,
    /// Event name as typed in the editor (may be truncated, see the module docs).
    pub name: String,
    /// Map x coordinate in tiles.
    pub x: u32,
    /// Map y coordinate in tiles.
    pub y: u32,
    /// Event pages in file order; page 0 is the default page.
    pub pages: Vec<MapEventPage>,
}

impl MapEvent {
    /// First byte of an event record.
    pub const MAGIC: u8 = Map::EVENT_MAGIC;

    fn read(r: &mut Reader<'_>) -> Result<Self> {
        r.expect_u8(Self::MAGIC, "map event magic")?;
        let magic2 = r.u32()?;
        if magic2 != Map::EVENT_MAGIC2 {
            return Err(Error::field(
                "map event magic2",
                r.pos() - 4,
                format!("expected {}, got {magic2}", Map::EVENT_MAGIC2),
            ));
        }
        let id = r.u32()?;
        let name = r.t_str()?;
        let x = r.u32()?;
        let y = r.u32()?;
        let page_count = r.u32()? as usize;
        let separator = r.u32()?;
        if separator != Map::EVENT_SEPARATOR {
            return Err(Error::field(
                "map event separator",
                r.pos() - 4,
                format!("expected {}, got {separator}", Map::EVENT_SEPARATOR),
            ));
        }
        // A page record is at least 72 bytes, so this loose bound rejects a
        // corrupt count without risking a false rejection.
        if page_count > r.remaining() / 8 {
            return Err(Error::field(
                "map event page count",
                r.pos() - 8,
                format!("{page_count} pages do not fit in {} bytes", r.remaining()),
            ));
        }
        let mut pages = Vec::with_capacity(page_count);
        for _ in 0..page_count {
            pages.push(MapEventPage::read(r)?);
        }
        r.expect_u8(Map::EVENT_FOOTER, "map event footer")?;
        Ok(Self {
            id,
            name,
            x,
            y,
            pages,
        })
    }

    /// Index of the page WOLF would display right now.
    ///
    /// The official editor documentation quoted in `docs/FORMAT_SPEC.md` §5.6.3 is
    /// explicit: "the highest page number whose activation conditions are met is
    /// displayed", and a page with more conditions therefore overrides the earlier
    /// fallback pages. `None` means no page matches, i.e. the event is not present
    /// on the map at all.
    ///
    /// The whole event executes as the returned page — its trigger, graphic and
    /// command list — which is why a single event can be a parallel page in one
    /// state and an action-key page in another (8 of the 25 shipped multi-page
    /// events do exactly that).
    pub fn active_page_index(&self, mut get_variable: impl FnMut(u32) -> i32) -> Option<usize> {
        (0..self.pages.len())
            .rev()
            .find(|&index| self.pages[index].conditions_met(&mut get_variable))
    }

    /// The page WOLF would display right now, see [`Self::active_page_index`].
    pub fn active_page(&self, get_variable: impl FnMut(u32) -> i32) -> Option<&MapEventPage> {
        self.active_page_index(get_variable)
            .map(|index| &self.pages[index])
    }
}

/// One page of a map event.
///
/// Which page is on screen is decided by the four condition slots: WOLF displays
/// the *highest* page whose enabled conditions all hold, see
/// [`MapEvent::active_page_index`].
///
/// The condition bytes stay raw (`trigger_switches`) so no existing consumer has to
/// change, and the decoded view is derived on demand by [`Self::conditions`]. Across
/// the 134 shipped pages the 536 bytes take exactly seven values — `0x10`, `0x11`,
/// `0x20`, `0x21`, `0x31`, `0x50`, `0x51` — i.e. a low nibble of `0`/`1` and an
/// operator from `_wolfref/common.ksy` in the high nibble
/// (`docs/FORMAT_SPEC.md` §5.6.3).
#[derive(Debug, Clone)]
pub struct MapEventPage {
    /// Graphic chip id, `0xFFFFFFFF` when the graphic comes from [`Self::graphic`].
    pub graphic_chip_id: u32,
    /// Graphic file name relative to the `Picture` folder.
    pub graphic: String,
    /// Facing direction, 0-7.
    pub direction: u8,
    /// Animation frame, 0-2.
    pub frame: u8,
    /// Opacity, 0-255.
    pub opacity: u8,
    /// Render mode: 0 normal, 1 multiply, 2 add, 3 subtract.
    pub display_type: u8,
    /// Trigger condition: 0 confirm, 1 autorun, 2 parallel, 3 player-touch,
    /// 4 event-touch. Only 0-3 occur in this game.
    pub trigger: u8,
    /// Raw condition flag bytes of the four slots: high nibble is the comparison
    /// operator, low nibble is `1` when the slot is enabled. The name predates the
    /// measurement — these bytes carry **no** switch id, see [`Self::conditions`].
    pub trigger_switches: [u8; 4],
    /// Variable number of each condition slot (WOLF magic numbers, so
    /// `2_000_062` is global variable 62 and `1_100_000` a self variable).
    pub trigger_variables: [u32; 4],
    /// Value each condition compares its variable against.
    pub trigger_values: [i32; 4],
    /// Page movement settings and custom move route.
    pub route: RouteData,
    /// Event commands executed by this page.
    pub commands: Vec<Slot>,
    /// Feature word; always 3 in this game (bit 0 movement, bit 1 move route).
    pub features: u32,
    /// Shadow graphic id.
    pub shadow_graphic: u8,
    /// Collision range extension in x, 0-250.
    pub collision_width: u8,
    /// Collision range extension in y, 0-250.
    pub collision_height: u8,
    /// Raw page terminator: `0x7A` normally, `0x00` for the two tolerated pages.
    pub footer: u8,
}

impl MapEventPage {
    fn read(r: &mut Reader<'_>) -> Result<Self> {
        r.expect_u8(Map::PAGE_MAGIC, "map page magic")?;
        let graphic_chip_id = r.u32()?;
        let graphic = r.t_str()?;
        let direction = r.u8()?;
        let frame = r.u8()?;
        let opacity = r.u8()?;
        let display_type = r.u8()?;
        // 37-byte condition block, see docs/FORMAT_SPEC.md §5.6.1.
        let trigger = r.u8()?;
        let mut trigger_switches = [0u8; 4];
        for byte in &mut trigger_switches {
            *byte = r.u8()?;
        }
        let mut trigger_variables = [0u32; 4];
        for value in &mut trigger_variables {
            *value = r.u32()?;
        }
        let mut trigger_values = [0i32; 4];
        for value in &mut trigger_values {
            *value = r.i32()?;
        }
        let route = RouteData::read(r)?;
        let command_count = r.u32()? as usize;
        // A blank slot is three bytes (param count, branch depth, string count),
        // so this bound can never reject a well-formed page.
        if command_count > r.remaining() / 3 {
            return Err(Error::field(
                "map page command count",
                r.pos() - 4,
                format!(
                    "{command_count} commands do not fit in {} bytes",
                    r.remaining()
                ),
            ));
        }
        let mut commands = Vec::with_capacity(command_count);
        for _ in 0..command_count {
            commands.push(Slot::read(r)?);
        }
        let features = r.u32()?;
        let shadow_graphic = r.u8()?;
        let collision_width = r.u8()?;
        let collision_height = r.u8()?;
        if features > 3 {
            // Bit 2 ("page transfer") adds one trailing byte. It never occurs in
            // this game's maps, but skipping it keeps the page walk in sync.
            r.skip(1)?;
        }
        let footer = r.u8()?;
        if footer != Map::PAGE_FOOTER {
            let tolerated = footer == Map::PAGE_FOOTER_TOLERATED
                && (r.at_end() || matches!(r.peek_u8()?, Map::EVENT_FOOTER | Map::PAGE_MAGIC));
            if !tolerated {
                return Err(Error::magic(
                    "map page footer",
                    r.pos() - 1,
                    &[footer],
                    &[Map::PAGE_FOOTER],
                ));
            }
        }
        Ok(Self {
            graphic_chip_id,
            graphic,
            direction,
            frame,
            opacity,
            display_type,
            trigger,
            trigger_switches,
            trigger_variables,
            trigger_values,
            route,
            commands,
            features,
            shadow_graphic,
            collision_width,
            collision_height,
            footer,
        })
    }

    /// Decoded view of the four condition slots.
    ///
    /// This is a pure decode of [`Self::trigger_switches`], [`Self::trigger_variables`]
    /// and [`Self::trigger_values`], so the struct keeps its shape for every other
    /// crate that builds pages by hand (e.g. the runtime's test fixtures).
    pub fn conditions(&self) -> [PageCondition; CONDITION_SLOTS] {
        std::array::from_fn(|slot| PageCondition {
            enabled: self.trigger_switches[slot] & 0x0F == 1,
            operator: self.trigger_switches[slot] >> 4,
            variable: self.trigger_variables[slot],
            value: self.trigger_values[slot],
        })
    }

    /// True when every enabled condition holds.
    ///
    /// A page with no enabled condition always matches, which is why page 0 of an
    /// event is usually the unconditional fallback page. An operator outside the
    /// verified set counts as "does not match" — the caller can inspect
    /// [`PageCondition::operator`] if it wants to log that case.
    pub fn conditions_met(&self, mut get_variable: impl FnMut(u32) -> i32) -> bool {
        self.conditions().iter().all(|condition| {
            !condition.enabled
                || condition
                    .compare(get_variable(condition.variable))
                    .unwrap_or(false)
        })
    }
}

/// One decoded activation-condition slot of a map event page.
///
/// `docs/FORMAT_SPEC.md` §5.6.3: the page's 37-byte condition block is one trigger
/// byte, four flag bytes, four `u32` variable numbers and four `i32` values. The flag
/// byte of a slot is `operator << 4 | enabled`, so the operator belongs to the
/// variable in the *same* slot. Measured over all 134 shipped pages: 536 slots, 208
/// enabled, operators only `>=`(25) `==`(173) `<=`(3) `!=`(7) — clear numeric
/// comparisons, not the on/off test a switch condition would need.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct PageCondition {
    /// `true` when this slot takes part in page selection.
    pub enabled: bool,
    /// Comparison operator; one of the `OP_*` constants.
    pub operator: u8,
    /// Variable number compared (WOLF magic number).
    pub variable: u32,
    /// Value the variable is compared against.
    pub value: i32,
}

impl PageCondition {
    /// `>` — never used by a shipped page condition.
    pub const OP_GREATER_THAN: u8 = 0;
    /// `>=` — 25 of the 208 enabled shipped conditions.
    pub const OP_GREATER_OR_EQUAL: u8 = 1;
    /// `==` — 173 of the 208 enabled shipped conditions.
    pub const OP_EQUAL: u8 = 2;
    /// `<=` — 3 of the 208 enabled shipped conditions.
    pub const OP_LESS_OR_EQUAL: u8 = 3;
    /// `<` — never used by a shipped page condition.
    pub const OP_LESS_THAN: u8 = 4;
    /// `!=` — 7 of the 208 enabled shipped conditions.
    pub const OP_NOT_EQUAL: u8 = 5;
    /// `&` bitwise test; never used by a shipped page condition and deliberately
    /// left out of [`Self::compare`].
    pub const OP_BITWISE_AND: u8 = 6;

    /// Evaluate the condition against the variable's current value.
    ///
    /// Returns `None` for an operator outside the verified set so a caller can log
    /// the case instead of silently folding it into `false`.
    pub fn compare(&self, actual: i32) -> Option<bool> {
        Some(match self.operator {
            Self::OP_GREATER_THAN => actual > self.value,
            Self::OP_GREATER_OR_EQUAL => actual >= self.value,
            Self::OP_EQUAL => actual == self.value,
            Self::OP_LESS_OR_EQUAL => actual <= self.value,
            Self::OP_LESS_THAN => actual < self.value,
            Self::OP_NOT_EQUAL => actual != self.value,
            _ => return None,
        })
    }

    /// Operator spelled the way `_wolfref/common.ksy::operator` names it.
    pub fn operator_name(&self) -> &'static str {
        match self.operator {
            Self::OP_GREATER_THAN => ">",
            Self::OP_GREATER_OR_EQUAL => ">=",
            Self::OP_EQUAL => "==",
            Self::OP_LESS_OR_EQUAL => "<=",
            Self::OP_LESS_THAN => "<",
            Self::OP_NOT_EQUAL => "!=",
            Self::OP_BITWISE_AND => "&",
            _ => "?",
        }
    }
}

/// Decoded meaning of a raw tile word, see docs/FORMAT_SPEC.md §5.4.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Tile {
    /// No tile on this layer at this position (`0xFFFFFFFF`).
    Empty,
    /// An autotile: `id` selects the autotile within the tileset and `corners`
    /// holds the four quadrant variants in `[top_left, top_right, bottom_left,
    /// bottom_right]` order, each 0-9.
    Autotile { id: u32, corners: [u8; 4] },
    /// A plain base tile; `id` indexes the tileset's base tile image.
    Base(u32),
}

/// Decode a raw tile word into an autotile reference or a base tile id.
///
/// The encoding is decimal: `autotile_id = raw / 100000`, and when that is
/// non-zero the remaining four decimal digits are the four quadrant variants.
/// `0xFFFFFFFF` is the only non-decimal value and means "no tile".
pub fn decode_tile(raw: u32) -> Tile {
    if raw == Map::EMPTY_TILE {
        return Tile::Empty;
    }
    let autotile_id = raw / 100_000;
    if autotile_id > 0 {
        Tile::Autotile {
            id: autotile_id,
            corners: [
                ((raw % 10_000) / 1_000) as u8,
                ((raw % 1_000) / 100) as u8,
                ((raw % 100) / 10) as u8,
                (raw % 10) as u8,
            ],
        }
    } else {
        Tile::Base(raw)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn magic_is_ten_zero_bytes_then_wolfm() {
        assert_eq!(&Map::MAGIC[..10], &[0u8; 10]);
        assert_eq!(&Map::MAGIC[10..], &[0x57, 0x4F, 0x4C, 0x46, 0x4D, 0x00]);
        assert_eq!(Map::MAGIC.len(), 16);
    }

    #[test]
    fn decode_tile_splits_autotile_digits() {
        // Measured first tile of SampleMapA layer 0: autotile 1, four 4s.
        assert_eq!(
            decode_tile(104_444),
            Tile::Autotile {
                id: 1,
                corners: [4, 4, 4, 4]
            }
        );
        assert_eq!(
            decode_tile(100_000),
            Tile::Autotile {
                id: 1,
                corners: [0, 0, 0, 0]
            }
        );
        assert_eq!(decode_tile(1), Tile::Base(1));
        assert_eq!(decode_tile(292), Tile::Base(292));
        assert_eq!(decode_tile(99_999), Tile::Base(99_999));
        assert_eq!(decode_tile(Map::EMPTY_TILE), Tile::Empty);
    }

    #[test]
    fn layout_constants_match_the_spec() {
        assert_eq!(LAYER_COUNT, 3);
        assert_eq!(CONDITION_SLOTS, 4);
        assert_eq!(Map::EVENT_MAGIC, 0x6F);
        assert_eq!(Map::EVENT_MAGIC2, 0x3039);
        assert_eq!(Map::EVENT_FOOTER, 0x70);
        assert_eq!(Map::PAGE_MAGIC, 0x79);
        assert_eq!(Map::PAGE_FOOTER, 0x7A);
        assert_eq!(Map::FOOTER, 0x66);
        assert_eq!(Map::UNKNOWN1, 100);
    }

    /// A page whose four condition slots are set from `flags`/`vars`/`values`.
    fn page(flags: [u8; 4], vars: [u32; 4], values: [i32; 4]) -> MapEventPage {
        MapEventPage {
            graphic_chip_id: 0xFFFF_FFFF,
            graphic: String::new(),
            direction: 2,
            frame: 1,
            opacity: 255,
            display_type: 0,
            trigger: 0,
            trigger_switches: flags,
            trigger_variables: vars,
            trigger_values: values,
            route: RouteData::default(),
            commands: Vec::new(),
            features: 3,
            shadow_graphic: 0,
            collision_width: 0,
            collision_height: 0,
            footer: Map::PAGE_FOOTER,
        }
    }

    #[test]
    fn condition_bytes_decode_into_operator_and_flag() {
        let slots = page([0x21, 0x20, 0x11, 0x50], [10, 20, 30, 40], [1, 2, 3, 4]).conditions();
        assert!(slots[0].enabled);
        assert_eq!(slots[0].operator, PageCondition::OP_EQUAL);
        assert_eq!(slots[0].variable, 10);
        assert_eq!(slots[0].value, 1);
        assert!(!slots[1].enabled);
        assert!(slots[2].enabled);
        assert_eq!(slots[2].operator, PageCondition::OP_GREATER_OR_EQUAL);
        assert!(!slots[3].enabled);
        assert_eq!(slots[3].operator, PageCondition::OP_NOT_EQUAL);
    }

    #[test]
    fn every_documented_operator_compares_correctly() {
        let cases = [
            (PageCondition::OP_GREATER_THAN, 3, true),
            (PageCondition::OP_GREATER_OR_EQUAL, 2, true),
            (PageCondition::OP_EQUAL, 2, true),
            (PageCondition::OP_LESS_OR_EQUAL, 2, true),
            (PageCondition::OP_LESS_THAN, 1, true),
            (PageCondition::OP_NOT_EQUAL, 7, true),
            (PageCondition::OP_EQUAL, 3, false),
            (PageCondition::OP_LESS_THAN, 3, false),
        ];
        for (operator, actual, expected) in cases {
            let condition = PageCondition {
                enabled: true,
                operator,
                variable: 0,
                value: 2,
            };
            assert_eq!(
                condition.compare(actual),
                Some(expected),
                "op {} against {}",
                condition.operator_name(),
                actual
            );
        }
        let unknown = PageCondition {
            enabled: true,
            operator: PageCondition::OP_BITWISE_AND,
            variable: 0,
            value: 2,
        };
        assert_eq!(unknown.compare(2), None);
        assert_eq!(unknown.operator_name(), "&");
    }

    #[test]
    fn conditions_met_ignores_disabled_slots() {
        // Enabled `var 10 == 1` plus three disabled slots holding junk.
        let conditional = page([0x21, 0x20, 0x20, 0x20], [10, 11, 12, 13], [1, 9, 9, 9]);
        assert!(conditional.conditions_met(|id| if id == 10 { 1 } else { 0 }));
        assert!(!conditional.conditions_met(|_| 0));
        // A page without any enabled condition always matches.
        assert!(page([0x20; 4], [0; 4], [0; 4]).conditions_met(|_| 0));
    }

    #[test]
    fn highest_matching_page_wins() {
        let event = MapEvent {
            id: 1,
            name: String::new(),
            x: 0,
            y: 0,
            pages: vec![
                page([0x20; 4], [0; 4], [0; 4]), // page 1: always shown
                page([0x21, 0x20, 0x20, 0x20], [100, 0, 0, 0], [1, 0, 0, 0]), // page 2
                page([0x21, 0x20, 0x20, 0x20], [100, 0, 0, 0], [2, 0, 0, 0]), // page 3
            ],
        };
        // state 2 -> page 3; state 1 -> page 2; anything else -> page 1.
        assert_eq!(
            event.active_page_index(|id| if id == 100 { 2 } else { 0 }),
            Some(2)
        );
        assert_eq!(
            event.active_page_index(|id| if id == 100 { 1 } else { 0 }),
            Some(1)
        );
        assert_eq!(event.active_page_index(|_| 0), Some(0));
        assert_eq!(
            event
                .active_page(|id| if id == 100 { 2 } else { 0 })
                .map(|page| page.trigger),
            Some(0)
        );
        // No unconditional page and no match -> the event is not on the map.
        let conditional = MapEvent {
            id: 2,
            name: String::new(),
            x: 0,
            y: 0,
            pages: vec![page([0x21, 0x20, 0x20, 0x20], [100, 0, 0, 0], [1, 0, 0, 0])],
        };
        assert_eq!(conditional.active_page_index(|_| 0), None);
    }
}
