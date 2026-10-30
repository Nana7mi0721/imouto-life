//! `CommonEvent.dat` — the 550 event programs that drive almost everything.
//!
//! This one file is the game. It holds 163,828 instruction slots (139,273 real
//! instructions) versus 37,610 on the map side, so the interpreter will spend
//! essentially all of its time here.
//!
//! Layout: `docs/FORMAT_SPEC.md` §3; instruction stream: §4 (shared with
//! `.mps`, see [`crate::command`]).

use crate::bytes::Reader;
use crate::command::{Slot, SlotStats};
use crate::error::{Error, Result};

/// Parsed `CommonEvent.dat`.
#[derive(Debug, Clone)]
pub struct CommonEventData {
    /// Container header version byte (`0x55`).
    pub version_header: u8,
    /// Content version byte (`0xC9` here).
    pub version: u8,
    /// The events, in file order.
    pub events: Vec<CommonEvent>,
    /// Container footer byte (`0x90`).
    pub footer: u8,
}

/// One common event (a callable subroutine plus its metadata).
#[derive(Debug, Clone)]
pub struct CommonEvent {
    /// Event id (`*@1` in editor speak). `1..=550` in this game, no gaps.
    pub id: u32,
    /// Raw `run_condition` byte.
    ///
    /// The low nibble is the run condition and the high nibble is the condition
    /// operator — the opposite of what the Kaitai schema claims. Keep the raw
    /// byte so the mapping cannot be silently wrong.`
    pub raw_condition: u8,
    /// Variable watched by the run condition.
    pub condition_variable: u32,
    /// Comparison value for the run condition.
    pub condition_value: u32,
    /// Declared numeric argument count.
    pub arg_num_count: u8,
    /// Declared string argument count.
    pub arg_str_count: u8,
    /// Event title. Editor-truncated, so may be cut mid-character-run.
    pub title: String,
    /// The instruction list.
    pub commands: Vec<Slot>,
    /// Author memo.
    pub memo: String,
    /// Declared argument names.
    pub arg_names: Vec<String>,
    /// Per-argument special specification (0 none / 1 string / 2 ...).
    pub arg_special_spec: Vec<u8>,
    /// Per-page string defaults for the "manual page" argument feature.
    pub arg_string_pages: Vec<Vec<String>>,
    /// Per-page numeric defaults for the same feature.
    pub arg_value_pages: Vec<Vec<u32>>,
    /// Initial argument values.
    pub default_values: Vec<i32>,
    /// Title-bar colour.
    pub color: u32,
    /// The 100 "self variable" names every event carries.
    pub self_variable_names: Vec<String>,
    /// Name of the return value, if declared.
    pub return_name: String,
    /// Declared return value id.
    pub return_value_id: u32,
}

impl CommonEvent {
    /// The run condition (low nibble of [`Self::raw_condition`]).
    #[must_use]
    pub const fn run_condition(&self) -> u8 {
        self.raw_condition & 0x0F
    }

    /// The condition operator (high nibble of [`Self::raw_condition`]).
    #[must_use]
    pub const fn condition_operator(&self) -> u8 {
        (self.raw_condition >> 4) & 0x0F
    }

    /// Whether the event runs as a background coroutine.
    ///
    /// 442 events run on call only, 108 run in the background (`run_condition`
    /// 2) or under other conditions — the interpreter must support concurrent
    /// event instances from day one.
    #[must_use]
    pub const fn is_background(&self) -> bool {
        self.run_condition() != 0
    }
}

impl CommonEventData {
    /// Six-byte container magic shared by every `.dat` file.
    pub const MAGIC: [u8; 6] = [0x00, 0x57, 0x00, 0x00, 0x4F, 0x4C];
    /// The three-byte type suffix that identifies `CommonEvent.dat`.
    pub const MAGIC_TYPE: [u8; 3] = *b"FC\0";
    /// Expected footer byte.
    pub const FOOTER: u8 = 0x90;
    /// Magic byte that opens a single event record.
    pub const EVENT_START: u8 = 0x8E;
    /// The five bytes the editor writes after the command list.
    pub const UNKNOWN_4: [u8; 5] = [0x01, 0x00, 0x00, 0x00, 0x00];
    /// Separator that opens the argument-name block.
    pub const SEP_1: u8 = 0x8F;
    /// Separator that opens the colour / self-variable block.
    pub const SEP_2: u8 = 0x90;
    /// Separator that opens the second unknown block.
    pub const SEP_3: u8 = 0x91;
    /// Separator around the return-value block.
    pub const SEP_4: u8 = 0x92;
    /// How many self-variable name slots every event reserves.
    pub const SELF_VARIABLE_SLOTS: usize = 100;

    /// Parse a `CommonEvent.dat` image.
    pub fn parse(data: &[u8]) -> Result<Self> {
        let mut r = Reader::new(data);

        r.expect(&Self::MAGIC, "CommonEvent.dat magic")?;
        let version_header = r.u8()?;
        let generation = crate::generation::WolfGeneration::require_version_header(
            version_header,
            "CommonEvent.dat version_header",
            r.pos() - 1,
        )?;
        r.expect(&Self::MAGIC_TYPE, "CommonEvent.dat type suffix")?;
        let version = r.u8()?;

        let count = r.u32()? as usize;
        if count > r.remaining() / 8 {
            return Err(Error::field(
                "CommonEvent.dat event count",
                r.pos() - 4,
                format!("{count} events do not fit in {} bytes", r.remaining()),
            ));
        }

        let mut events = Vec::with_capacity(count);
        for _ in 0..count {
            events.push(Self::parse_event(&mut r)?);
        }

        let footer = r.u8()?;
        let want_footer = generation.commonevent_footer();
        if footer != want_footer {
            return Err(Error::magic(
                "CommonEvent.dat footer",
                r.pos() - 1,
                &[footer],
                &[want_footer],
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
            events,
            footer,
        })
    }

    fn parse_event(r: &mut Reader<'_>) -> Result<CommonEvent> {
        r.expect_u8(Self::EVENT_START, "common event start marker")?;
        let id = r.u32()?;
        let raw_condition = r.u8()?;
        let condition_variable = r.u32()?;
        let condition_value = r.u32()?;
        let arg_num_count = r.u8()?;
        let arg_str_count = r.u8()?;
        let title = r.t_str()?;

        let line_count = r.u32()? as usize;
        if line_count > r.remaining() / 3 {
            return Err(Error::field(
                "common event line count",
                r.pos() - 4,
                format!(
                    "event {id} declares {line_count} lines but only {} bytes remain",
                    r.remaining()
                ),
            ));
        }
        let mut commands = Vec::with_capacity(line_count);
        for _ in 0..line_count {
            commands.push(Slot::read(r)?);
        }

        r.expect(&Self::UNKNOWN_4, "common event unknown4")?;
        let memo = r.t_str()?;

        r.expect_u8(Self::SEP_1, "common event separator 1")?;
        let arg_names = r.t_str_array()?;

        let arg_page_count = r.u32()? as usize;
        let arg_special_spec = r.take(arg_page_count)?.to_vec();

        let string_page_count = r.u32()? as usize;
        let mut arg_string_pages = Vec::with_capacity(string_page_count.min(64));
        for _ in 0..string_page_count {
            arg_string_pages.push(r.t_str_array()?);
        }

        let value_page_count = r.u32()? as usize;
        let mut arg_value_pages = Vec::with_capacity(value_page_count.min(64));
        for _ in 0..value_page_count {
            arg_value_pages.push(r.t_u32_array()?);
        }

        let default_values = r.t_i32_array()?;

        r.expect_u8(Self::SEP_2, "common event separator 2")?;
        let color = r.u32()?;
        let mut self_variable_names = Vec::with_capacity(Self::SELF_VARIABLE_SLOTS);
        for _ in 0..Self::SELF_VARIABLE_SLOTS {
            self_variable_names.push(r.t_str()?);
        }

        r.expect_u8(Self::SEP_3, "common event separator 3")?;
        r.expect(&Self::UNKNOWN_4, "common event unknown5")?;

        r.expect_u8(Self::SEP_4, "common event separator 4")?;
        let return_name = r.t_str()?;
        let return_value_id = r.u32()?;
        r.expect_u8(Self::SEP_4, "common event separator 5")?;

        Ok(CommonEvent {
            id,
            raw_condition,
            condition_variable,
            condition_value,
            arg_num_count,
            arg_str_count,
            title,
            commands,
            memo,
            arg_names,
            arg_special_spec,
            arg_string_pages,
            arg_value_pages,
            default_values,
            color,
            self_variable_names,
            return_name,
            return_value_id,
        })
    }

    /// Aggregate instruction statistics over every event.
    #[must_use]
    pub fn stats(&self) -> SlotStats {
        let mut stats = SlotStats::default();
        for event in &self.events {
            stats.extend(&event.commands);
        }
        stats
    }

    /// Histogram of [`CommonEvent::run_condition`].
    #[must_use]
    pub fn run_condition_histogram(&self) -> std::collections::BTreeMap<u8, usize> {
        let mut hist = std::collections::BTreeMap::new();
        for event in &self.events {
            *hist.entry(event.run_condition()).or_insert(0) += 1;
        }
        hist
    }

    /// Look up an event by id.
    #[must_use]
    pub fn event(&self, id: u32) -> Option<&CommonEvent> {
        // Ids are dense and 1-based; this stays correct as long as they are.
        self.events.iter().find(|e| e.id == id)
    }
}

#[cfg(test)]
mod tests {
    use super::CommonEventData;

    #[test]
    fn magic_constants_are_distinct() {
        assert_eq!(CommonEventData::MAGIC[5], 0x4C);
        assert_eq!(CommonEventData::MAGIC_TYPE[0], b'F');
    }
}
