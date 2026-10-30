//! `SavePart7` — a small tagged table that every save here leaves empty.
//!
//! Layout source: `docs/vendor/WolfSave/SavePart7.h`, `Parse` at line 40. The
//! segment opens with a `u8` gate: anything other than 1 ends the segment
//! immediately, which is why it is one byte long in all nine of this game's
//! saves. See `docs/SAVE_SPEC.md` §8.

use wolf_format::bytes::Reader;
use wolf_format::error::Result;

use crate::ensure_fits;

/// One tagged entry: a `u8` tag, then either a `u8` or a `u32` depending on it.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct SavePart7Entry {
    /// `std::get<0>` of `SP7_BBD` — the tag.
    pub tag: u8,
    /// `std::get<1>` — present when `tag < 0xFA`.
    pub byte: u8,
    /// `std::get<2>` — present when `tag >= 0xFA`.
    pub word: u32,
}

/// The trailing segment.
#[derive(Debug, Clone, PartialEq, Eq, Default)]
pub struct SavePart7 {
    /// `m_var1` — the gate; 0 in every save here.
    pub var1: u8,
    /// `m_sp7_bbds` — empty here.
    pub entries: Vec<SavePart7Entry>,
}

pub(crate) fn parse(r: &mut Reader<'_>) -> Result<SavePart7> {
    let var1 = r.u8()?;
    if var1 != 1 {
        return Ok(SavePart7 {
            var1,
            entries: Vec::new(),
        });
    }
    let count = r.u32()? as usize;
    ensure_fits(r, count, 2, "SavePart7 entries")?;
    let mut entries = Vec::with_capacity(count);
    for _ in 0..count {
        let tag = r.u8()?;
        if tag < 0xFA {
            entries.push(SavePart7Entry {
                tag,
                byte: r.u8()?,
                word: 0,
            });
        } else {
            entries.push(SavePart7Entry {
                tag,
                byte: 0,
                word: r.u32()?,
            });
        }
    }
    Ok(SavePart7 { var1, entries })
}
