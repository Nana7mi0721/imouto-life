//! `SavePart5` — the per-common-event runtime state.
//!
//! Layout source: `docs/vendor/WolfSave/SavePart5.h`, `Parse` at line 661, and
//! `SavePart5_1::Parse` at line 44. This segment has the most version gates
//! of any in the file — twenty of them — so it is written as a straight-line
//! transcription rather than something clever. See `docs/SAVE_SPEC.md` §7.

use wolf_format::bytes::Reader;
use wolf_format::error::{Error, Result};

use crate::{
    ensure_fits, mem_data, push_count, push_mem_data, push_u16, push_u32, push_u8, signed_count,
};

/// The runtime state of one common event.
///
/// The C++ names every field `m_var1` … `m_var97`; this keeps that numbering so a
/// reader can line the fields up with the source instead of guessing meanings.
#[derive(Debug, Clone, PartialEq, Eq, Default)]
pub struct SavePart5_1 {
    /// `m_var1` — the event id.
    pub var1: u32,
    /// `m_var2`.
    pub var2: u8,
    /// `m_var3`.
    pub var3: u8,
    /// `m_var4`.
    pub var4: u16,
    /// `m_var5`.
    pub var5: u8,
    /// `m_var6`.
    pub var6: u8,
    /// `m_md1` — `MemData<WORD>`.
    pub md1: Vec<u8>,
    /// `m_var7` .. `m_var18`.
    pub vars7_18: [u32; 12],
    /// `m_vals1` — six words (`m_vals1[0..3]` in the source).
    pub vals1: [u32; 6],
    /// `m_var19` .. `m_var36` — `file_version >= 0x69`.
    pub vars19_36: [u32; 18],
    /// `m_var37` — `file_version >= 0x6B`.
    pub var37: u8,
    /// `m_var38` — `file_version >= 0x72`.
    pub var38: u8,
    /// `m_var39`.
    pub var39: u8,
    /// `m_vals2` — four words, `file_version >= 0x72`.
    pub vals2: [u32; 4],
    /// `m_vals3` — four words, `file_version >= 0x72`.
    pub vals3: [u32; 4],
    /// `m_var40` .. `m_var43` — `file_version >= 0x73`.
    pub vars40_43: [u32; 4],
    /// `m_var44` .. `m_var48` — `file_version >= 0x74`.
    pub vars44_48: [u32; 5],
    /// `m_var49` .. `m_var54` — `file_version >= 0x75`.
    pub vars49_54: [u32; 6],
    /// `m_var55` .. `m_var60` — `file_version >= 0x73`.
    pub vars55_60: [u32; 6],
    /// `m_var61` .. `m_var63` — `file_version >= 0x76`.
    pub vars61_63: [u32; 3],
    /// `m_var64` .. `m_var84` — `file_version >= 0x81`.
    pub vars64_84: [u32; 21],
    /// `m_var85` .. `m_var89` — `file_version >= 0x87`.
    pub vars85_89: [u32; 5],
    /// `m_var90` — `file_version >= 0x89`; the number of sub-tables.
    pub var90: u32,
    /// The `m_var90` sub-tables, each a count and that many words.
    pub sub_tables: Vec<Vec<u32>>,
    /// `m_var91` .. `m_var97` — `file_version >= 0x89`.
    pub vars91_97: [u32; 7],
}

/// The per-common-event runtime state.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SavePart5 {
    /// `m_var1` — the number of events with saved state, 58 to 84 here.
    ///
    /// When bit 15 is set the segment carries no table at all and `events` is empty.
    pub var1: u16,
    /// The per-event states.
    pub events: Vec<SavePart5_1>,
}

fn fixed_u32<const N: usize>(r: &mut Reader<'_>, what: &'static str) -> Result<[u32; N]> {
    ensure_fits(r, N, 4, what)?;
    let mut out = [0u32; N];
    for slot in &mut out {
        *slot = r.u32()?;
    }
    Ok(out)
}

pub(crate) fn parse(r: &mut Reader<'_>, file_version: u16) -> Result<SavePart5> {
    let var1 = r.u16()?;
    let mut events = Vec::new();
    if var1 & 0x8000 == 0 {
        ensure_fits(r, usize::from(var1), 8, "SavePart5 events")?;
        events = Vec::with_capacity(usize::from(var1));
        for _ in 0..var1 {
            events.push(SavePart5_1::parse(r, file_version)?);
        }
    }
    Ok(SavePart5 { var1, events })
}

impl SavePart5_1 {
    pub(crate) fn parse(r: &mut Reader<'_>, file_version: u16) -> Result<SavePart5_1> {
        let mut item = SavePart5_1 {
            var1: r.u32()?,
            var2: r.u8()?,
            var3: r.u8()?,
            var4: r.u16()?,
            var5: r.u8()?,
            var6: r.u8()?,
            md1: mem_data(r, 2)?,
            vars7_18: fixed_u32::<12>(r, "SavePart5_1 vars7_18")?,
            vals1: fixed_u32::<6>(r, "SavePart5_1 vals1")?,
            ..SavePart5_1::default()
        };

        if file_version >= 0x69 {
            item.vars19_36 = fixed_u32::<18>(r, "SavePart5_1 vars19_36")?;
        }
        if file_version >= 0x6B {
            item.var37 = r.u8()?;
        }
        if file_version >= 0x72 {
            item.var38 = r.u8()?;
            item.var39 = r.u8()?;
            item.vals2 = fixed_u32::<4>(r, "SavePart5_1 vals2")?;
            item.vals3 = fixed_u32::<4>(r, "SavePart5_1 vals3")?;
        }
        if file_version >= 0x73 {
            item.vars40_43 = fixed_u32::<4>(r, "SavePart5_1 vars40_43")?;
            if file_version >= 0x74 {
                item.vars44_48 = fixed_u32::<5>(r, "SavePart5_1 vars44_48")?;
            }
            if file_version >= 0x75 {
                item.vars49_54 = fixed_u32::<6>(r, "SavePart5_1 vars49_54")?;
            }
            item.vars55_60 = fixed_u32::<6>(r, "SavePart5_1 vars55_60")?;
        }
        if file_version >= 0x76 {
            item.vars61_63 = fixed_u32::<3>(r, "SavePart5_1 vars61_63")?;
        }
        if file_version < 0x81 {
            return Ok(item);
        }

        item.vars64_84 = fixed_u32::<21>(r, "SavePart5_1 vars64_84")?;
        if file_version >= 0x87 {
            item.vars85_89 = fixed_u32::<5>(r, "SavePart5_1 vars85_89")?;
        }
        if file_version >= 0x89 {
            item.var90 = r.u32()?;
            let count = signed_count(item.var90);
            ensure_fits(r, count, 4, "SavePart5_1 sub tables")?;
            item.sub_tables = Vec::with_capacity(count);
            for _ in 0..count {
                let len = signed_count(r.u32()?);
                ensure_fits(r, len, 4, "SavePart5_1 sub table")?;
                let mut words = Vec::with_capacity(len);
                for _ in 0..len {
                    words.push(r.u32()?);
                }
                item.sub_tables.push(words);
            }
            item.vars91_97 = fixed_u32::<7>(r, "SavePart5_1 vars91_97")?;
        }

        Ok(item)
    }
}

// ---- writing ---------------------------------------------------------

impl SavePart5 {
    /// Re-encode this segment exactly as this module's parse() reads it.
    ///
    /// var1 is both the event count and the "there is no table" flag (bit 15),
    /// so nothing else introduces the table. A count that disagrees with the
    /// vector is an error instead of a silently truncated segment.
    pub fn to_bytes(&self, file_version: u16) -> Result<Vec<u8>> {
        if self.var1 & 0x8000 != 0 {
            if !self.events.is_empty() {
                return Err(Error::field(
                    "SavePart5 events",
                    self.events.len(),
                    format!(
                        "var1 = {:#06X} says there is no table but {} event(s) were stored",
                        self.var1,
                        self.events.len()
                    ),
                ));
            }
        } else if usize::from(self.var1) != self.events.len() {
            return Err(Error::field(
                "SavePart5 events",
                self.events.len(),
                format!(
                    "var1 says {} event(s) but {} were stored",
                    self.var1,
                    self.events.len()
                ),
            ));
        }

        let mut out = Vec::new();
        push_u16(&mut out, self.var1);
        for event in &self.events {
            out.extend_from_slice(&event.to_bytes(file_version)?);
        }
        Ok(out)
    }
}

impl SavePart5_1 {
    /// Re-encode one event's runtime state.
    pub fn to_bytes(&self, file_version: u16) -> Result<Vec<u8>> {
        let mut out = Vec::new();
        push_u32(&mut out, self.var1);
        push_u8(&mut out, self.var2);
        push_u8(&mut out, self.var3);
        push_u16(&mut out, self.var4);
        push_u8(&mut out, self.var5);
        push_u8(&mut out, self.var6);
        push_mem_data(&mut out, &self.md1, 2)?;
        for word in &self.vars7_18 {
            push_u32(&mut out, *word);
        }
        for word in &self.vals1 {
            push_u32(&mut out, *word);
        }

        if file_version >= 0x69 {
            for word in &self.vars19_36 {
                push_u32(&mut out, *word);
            }
        }
        if file_version >= 0x6B {
            push_u8(&mut out, self.var37);
        }
        if file_version >= 0x72 {
            push_u8(&mut out, self.var38);
            push_u8(&mut out, self.var39);
            for word in &self.vals2 {
                push_u32(&mut out, *word);
            }
            for word in &self.vals3 {
                push_u32(&mut out, *word);
            }
        }
        if file_version >= 0x73 {
            for word in &self.vars40_43 {
                push_u32(&mut out, *word);
            }
            if file_version >= 0x74 {
                for word in &self.vars44_48 {
                    push_u32(&mut out, *word);
                }
            }
            if file_version >= 0x75 {
                for word in &self.vars49_54 {
                    push_u32(&mut out, *word);
                }
            }
            for word in &self.vars55_60 {
                push_u32(&mut out, *word);
            }
        }
        if file_version >= 0x76 {
            for word in &self.vars61_63 {
                push_u32(&mut out, *word);
            }
        }
        if file_version < 0x81 {
            return Ok(out);
        }

        for word in &self.vars64_84 {
            push_u32(&mut out, *word);
        }
        if file_version >= 0x87 {
            for word in &self.vars85_89 {
                push_u32(&mut out, *word);
            }
        }
        if file_version >= 0x89 {
            // var90 is the sub-table count itself, not a separate length.
            if signed_count(self.var90) != self.sub_tables.len() {
                return Err(Error::field(
                    "SavePart5_1 sub tables",
                    out.len(),
                    format!(
                        "var90 says {} table(s) but {} were stored",
                        signed_count(self.var90),
                        self.sub_tables.len()
                    ),
                ));
            }
            push_u32(&mut out, self.var90);
            for words in &self.sub_tables {
                push_count(&mut out, words.len())?;
                for word in words {
                    push_u32(&mut out, *word);
                }
            }
            for word in &self.vars91_97 {
                push_u32(&mut out, *word);
            }
        }

        Ok(out)
    }
}
