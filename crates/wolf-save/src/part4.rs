//! `SavePart4` — the continuation of the object table.
//!
//! Layout source: `docs/vendor/WolfSave/SavePart4.h`, `Parse` at line 39.
//! It opens with one `SavePart1_1` of its own, then `m_var1` more of them, then a
//! word table and (from `0x8A`) a 64-bit table. See `docs/SAVE_SPEC.md` §6.

use wolf_format::bytes::Reader;
use wolf_format::error::Result;

use crate::part1::SavePart1_1;
use crate::{ensure_fits, push_count, push_u32, push_u64, push_u8, signed_count};

/// The object-table continuation.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SavePart4 {
    /// `m_savePart1_1` — the leading object, `var1 == 0xFFFFFFFE` here.
    pub lead: SavePart1_1,
    /// `m_vars1` — the five objects that follow here.
    pub objects: Vec<SavePart1_1>,
    /// `m_var2` — 0 here.
    pub var2: u8,
    /// `m_var3` — 0 here.
    pub var3: u8,
    /// `m_vars2` — `m_var4` words; 100 of them here, first one 8.
    pub vars2: Vec<u32>,
    /// `m_vars3` — `m_var5` 64-bit words, `file_version >= 0x8A`; empty here.
    pub vars3: Vec<u64>,
}

pub(crate) fn parse(r: &mut Reader<'_>, file_version: u16) -> Result<SavePart4> {
    let lead = SavePart1_1::parse(r, file_version)?;

    let count = signed_count(r.u32()?);
    ensure_fits(r, count, 40, "SavePart4 objects")?;
    let mut objects = Vec::with_capacity(count);
    for _ in 0..count {
        objects.push(SavePart1_1::parse(r, file_version)?);
    }

    let var2 = r.u8()?;
    let var3 = r.u8()?;

    let count = signed_count(r.u32()?);
    ensure_fits(r, count, 4, "SavePart4 vars2")?;
    let mut vars2 = Vec::with_capacity(count);
    for _ in 0..count {
        vars2.push(r.u32()?);
    }

    let mut vars3 = Vec::new();
    if file_version >= 0x8A {
        let count = signed_count(r.u32()?);
        ensure_fits(r, count, 8, "SavePart4 vars3")?;
        vars3 = Vec::with_capacity(count);
        for _ in 0..count {
            vars3.push(r.u64()?);
        }
    }

    Ok(SavePart4 {
        lead,
        objects,
        var2,
        var3,
        vars2,
        vars3,
    })
}

// ---- writing ---------------------------------------------------------

impl SavePart4 {
    /// Re-encode this segment exactly as this module's parse() reads it.
    pub fn to_bytes(&self, file_version: u16) -> Result<Vec<u8>> {
        let mut out = Vec::new();
        out.extend_from_slice(&self.lead.to_bytes(file_version)?);

        push_count(&mut out, self.objects.len())?;
        for object in &self.objects {
            out.extend_from_slice(&object.to_bytes(file_version)?);
        }

        push_u8(&mut out, self.var2);
        push_u8(&mut out, self.var3);

        push_count(&mut out, self.vars2.len())?;
        for word in &self.vars2 {
            push_u32(&mut out, *word);
        }

        if file_version >= 0x8A {
            push_count(&mut out, self.vars3.len())?;
            for word in &self.vars3 {
                push_u64(&mut out, *word);
            }
        }

        Ok(out)
    }
}
