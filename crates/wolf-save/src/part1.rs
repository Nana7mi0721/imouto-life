//! `SavePart1` — the map snapshot and the object (event) table.
//!
//! Layout source: `docs/vendor/WolfSave/SavePart1.h`, `Parse` at line 478. Every
//! field is checked against all nine saves this game writes; see
//! `docs/SAVE_SPEC.md` §3.

use wolf_format::bytes::Reader;
use wolf_format::error::{Error, Result};

use crate::{
    ensure_fits, mem_data, push_count, push_mem_data, push_u16, push_u32, push_u8, signed_count,
};

/// The map snapshot: tile layers, the chip image, the automatic tile names and
/// the per-map object table.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SavePart1 {
    /// `m_var1` — 1 in every save here.
    pub var1: u32,
    /// `m_var2` — 0 in every save here.
    pub var2: u32,
    /// `m_var3` — 0 in every save here.
    pub var3: u32,
    /// `m_var4` — map width in tiles. 0 when `file_version < 0x69`.
    pub map_width: u32,
    /// `m_var5` — map height in tiles.
    pub map_height: u32,
    /// `m_vars1` — three tile layers, layer-major: `[z][y][x]`.
    ///
    /// Empty when the `m_var6` sentinel is `0xFFFFFFFF`, which means the save
    /// carries no map snapshot at all. 64 x 36 x 3 = 6912 entries here.
    pub map_tiles: Vec<u32>,
    /// `m_md1` — the chip image path, e.g. `MapChip/kiri_project.png`.
    pub chip_image: Vec<u8>,
    /// `m_vars_140` — the automatic tile names, 31 entries at
    /// `file_version >= 0x8A` (15 at 0x73, 7 below that).
    pub auto_tiles: Vec<Vec<u8>>,
    /// `m_vars2New` — 192 `u32` switch words at `file_version >= 0x64`.
    pub vars2_new: Vec<u32>,
    /// `m_vars2Old` — the same table as bytes on older file versions.
    pub vars2_old: Vec<u8>,
    /// `m_savePart1_1s` — 40 objects here.
    pub objects: Vec<SavePart1_1>,
    /// `m_var9` .. `m_var19`, 11 words at `file_version >= 0x72`.
    pub tail_vars: Vec<u32>,
    /// `m_vars3` — empty here (`m_var20 == 0`).
    pub vars3: Vec<u32>,
}

/// One object (map event instance) from `m_savePart1_1s`.
///
/// The C++ keeps `var1..var39` as separate members with no names, so this
/// mirrors that and documents what each one holds instead of inventing names.
/// Fields behind a version gate stay at their default when the gate is closed.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SavePart1_1 {
    /// `m_var1`.
    pub var1: u32,
    /// `m_var2` — the object's map-event page or template index.
    pub var2: u32,
    /// `m_var3`.
    pub var3: u32,
    /// `m_var4`.
    pub var4: u32,
    /// `m_var5`.
    pub var5: u8,
    /// `m_var6` — `0xFFFFFFFF` in every object here.
    pub var6: u32,
    /// `m_md1` — `MemData<WORD>`, one NUL byte in every object here.
    pub md1: Vec<u8>,
    /// `m_var7`.
    pub var7: u16,
    /// `m_var8`.
    pub var8: u16,
    /// `m_var9`.
    pub var9: u16,
    /// `m_var10`.
    pub var10: u16,
    /// `m_var11`.
    pub var11: u8,
    /// `m_var12`.
    pub var12: u8,
    /// `m_savePart1_1_1` (first).
    pub sp1: SavePart1_1_1,
    /// `m_savePart1_1_2` (second).
    pub sp2: SavePart1_1_1,
    /// `m_var13`.
    pub var13: u16,
    /// `m_var14`.
    pub var14: u16,
    /// `m_var15`.
    pub var15: u16,
    /// `m_var16`.
    pub var16: u16,
    /// `m_var17`.
    pub var17: u16,
    /// `m_var18`.
    pub var18: u16,
    /// `m_var19`.
    pub var19: u8,
    /// `m_var20`.
    pub var20: u8,
    /// `m_var21`.
    pub var21: u8,
    /// `m_vars1` — empty in every object here.
    pub vars1: Vec<u32>,
    /// `m_var23`, `file_version >= 0x70`.
    pub var23: u8,
    /// `m_var24`, `file_version >= 0x70`.
    pub var24: u8,
    /// `m_var25`, `file_version >= 0x73`.
    pub var25: u32,
    /// `m_var26`.
    pub var26: u32,
    /// `m_var27`.
    pub var27: u32,
    /// `m_var28`.
    pub var28: u32,
    /// `m_var29`, `file_version >= 0x78`.
    pub var29: u32,
    /// `m_var30`, `file_version >= 0x85`.
    pub var30: u32,
    /// `m_var31`.
    pub var31: u32,
    /// `m_var32`.
    pub var32: u32,
    /// `m_mds1` — `MemData<WORD>` entries, `file_version >= 0x8A`.
    pub mds1: Vec<Vec<u8>>,
    /// `m_var34`, `file_version >= 0x8A`.
    pub var34: u32,
    /// `m_var35`.
    pub var35: u8,
    /// `m_var36`.
    pub var36: u32,
    /// `m_var37`.
    pub var37: u32,
    /// `m_var38`, `file_version >= 0x8B`.
    pub var38: u32,
    /// `m_var39`, `file_version >= 0x8C` — 131073 in the first object.
    pub var39: u32,
}

/// A page table nested inside an object.
#[derive(Debug, Clone, PartialEq, Eq, Default)]
pub struct SavePart1_1_1 {
    /// `m_var1` .. `m_var6` — six `u8` flags; `[3, 3, 3, 0, 3, 2]` here.
    pub head: [u8; 6],
    /// `m_var7` — the entry count, rejected above 0x10000.
    pub count: u32,
    /// The entries.
    pub items: Vec<SavePart1_1_1_1>,
}

/// One page-table entry.
#[derive(Debug, Clone, PartialEq, Eq, Default)]
pub struct SavePart1_1_1_1 {
    /// `m_var1`.
    pub var1: u8,
    /// `m_vars1` — `m_var2` words.
    pub vars1: Vec<u32>,
    /// `m_vars2` — `m_var3` bytes.
    pub vars2: Vec<u8>,
}

pub(crate) fn parse(r: &mut Reader<'_>, file_version: u16) -> Result<SavePart1> {
    let var1 = r.u32()?;
    let var2 = r.u32()?;
    let var3 = r.u32()?;

    let mut map_width = 0;
    let mut map_height = 0;
    let mut map_tiles = Vec::new();
    if file_version >= 0x69 {
        map_width = r.u32()?;
        map_height = r.u32()?;
        let sentinel_pos = r.pos();
        let sentinel = r.u32()?;
        if sentinel != u32::MAX {
            // The reference implementation reads this word only to test it, then
            // rewinds and treats it as the first tile.
            r.set_pos(sentinel_pos);
            let cells = (map_width as usize)
                .checked_mul(map_height as usize)
                .and_then(|per_layer| per_layer.checked_mul(3))
                .ok_or_else(|| {
                    Error::field(
                        "SavePart1 map size",
                        sentinel_pos,
                        format!("{map_width} x {map_height} tiles does not fit in memory"),
                    )
                })?;
            ensure_fits(r, cells, 4, "SavePart1 map tiles")?;
            map_tiles = Vec::with_capacity(cells);
            for _ in 0..cells {
                map_tiles.push(r.u32()?);
            }
        }
    }

    let chip_image = mem_data(r, 4)?;

    let auto_count = if file_version >= 0x8A {
        31
    } else if file_version >= 0x73 {
        15
    } else {
        7
    };
    ensure_fits(r, auto_count, 4, "SavePart1 automatic tiles")?;
    let mut auto_tiles = Vec::with_capacity(auto_count);
    for _ in 0..auto_count {
        auto_tiles.push(mem_data(r, 4)?);
    }

    let count = signed_count(r.u32()?);
    let mut vars2_new = Vec::new();
    let mut vars2_old = Vec::new();
    if file_version >= 0x64 {
        ensure_fits(r, count, 4, "SavePart1 vars2")?;
        vars2_new = Vec::with_capacity(count);
        for _ in 0..count {
            vars2_new.push(r.u32()?);
        }
    } else {
        ensure_fits(r, count, 1, "SavePart1 vars2")?;
        vars2_old = r.take(count)?.to_vec();
    }

    let count = signed_count(r.u32()?);
    // Every object costs at least 40 bytes at any version this crate accepts.
    ensure_fits(r, count, 40, "SavePart1 objects")?;
    let mut objects = Vec::with_capacity(count);
    for _ in 0..count {
        objects.push(SavePart1_1::parse(r, file_version)?);
    }

    let mut tail_vars = Vec::new();
    if file_version >= 0x72 {
        ensure_fits(r, 11, 4, "SavePart1 tail vars")?;
        tail_vars = Vec::with_capacity(11);
        for _ in 0..11 {
            tail_vars.push(r.u32()?);
        }
    }

    let count = signed_count(r.u32()?);
    ensure_fits(r, count, 4, "SavePart1 vars3")?;
    let mut vars3 = Vec::with_capacity(count);
    for _ in 0..count {
        vars3.push(r.u32()?);
    }

    Ok(SavePart1 {
        var1,
        var2,
        var3,
        map_width,
        map_height,
        map_tiles,
        chip_image,
        auto_tiles,
        vars2_new,
        vars2_old,
        objects,
        tail_vars,
        vars3,
    })
}

impl SavePart1_1 {
    pub(crate) fn parse(r: &mut Reader<'_>, file_version: u16) -> Result<SavePart1_1> {
        let var1 = r.u32()?;
        let var2 = r.u32()?;
        let var3 = r.u32()?;
        let var4 = r.u32()?;
        let var5 = r.u8()?;
        let var6 = r.u32()?;
        let md1 = mem_data(r, 2)?;
        let var7 = r.u16()?;
        let var8 = r.u16()?;
        let var9 = r.u16()?;
        let var10 = r.u16()?;
        let var11 = r.u8()?;
        let var12 = r.u8()?;
        let sp1 = SavePart1_1_1::parse(r)?;
        let sp2 = SavePart1_1_1::parse(r)?;
        let var13 = r.u16()?;
        let var14 = r.u16()?;
        let var15 = r.u16()?;
        let var16 = r.u16()?;
        let var17 = r.u16()?;
        let var18 = r.u16()?;
        let var19 = r.u8()?;
        let var20 = r.u8()?;
        let var21 = r.u8()?;

        let count = signed_count(r.u32()?);
        ensure_fits(r, count, 4, "SavePart1_1 vars1")?;
        let mut vars1 = Vec::with_capacity(count);
        for _ in 0..count {
            vars1.push(r.u32()?);
        }

        let mut var23 = 0;
        let mut var24 = 0;
        if file_version >= 0x70 {
            var23 = r.u8()?;
            var24 = r.u8()?;
        }

        let mut var25 = 0;
        let mut var26 = 0;
        let mut var27 = 0;
        let mut var28 = 0;
        if file_version >= 0x73 {
            var25 = r.u32()?;
            var26 = r.u32()?;
            var27 = r.u32()?;
            var28 = r.u32()?;
        }

        let mut var29 = 0;
        if file_version >= 0x78 {
            var29 = r.u32()?;
        }

        let mut var30 = 0;
        let mut var31 = 0;
        let mut var32 = 0;
        if file_version >= 0x85 {
            var30 = r.u32()?;
            var31 = r.u32()?;
            var32 = r.u32()?;
        }

        let mut mds1 = Vec::new();
        let mut var34 = 0;
        let mut var35 = 0;
        let mut var36 = 0;
        let mut var37 = 0;
        if file_version >= 0x8A {
            // The count is a signed 16-bit test, so 0xFFFF means "none".
            let raw = r.u16()?;
            let count = if (raw as i16) > 0 {
                usize::from(raw)
            } else {
                0
            };
            ensure_fits(r, count, 2, "SavePart1_1 mds1")?;
            mds1 = Vec::with_capacity(count);
            for _ in 0..count {
                mds1.push(mem_data(r, 2)?);
            }
            var34 = r.u32()?;
            var35 = r.u8()?;
            var36 = r.u32()?;
            var37 = r.u32()?;
        }

        let mut var38 = 0;
        if file_version >= 0x8B {
            var38 = r.u32()?;
        }

        let mut var39 = 0;
        if file_version >= 0x8C {
            var39 = r.u32()?;
        }

        Ok(SavePart1_1 {
            var1,
            var2,
            var3,
            var4,
            var5,
            var6,
            md1,
            var7,
            var8,
            var9,
            var10,
            var11,
            var12,
            sp1,
            sp2,
            var13,
            var14,
            var15,
            var16,
            var17,
            var18,
            var19,
            var20,
            var21,
            vars1,
            var23,
            var24,
            var25,
            var26,
            var27,
            var28,
            var29,
            var30,
            var31,
            var32,
            mds1,
            var34,
            var35,
            var36,
            var37,
            var38,
            var39,
        })
    }
}

impl SavePart1_1_1 {
    pub(crate) fn parse(r: &mut Reader<'_>) -> Result<SavePart1_1_1> {
        let mut head = [0u8; 6];
        for byte in &mut head {
            *byte = r.u8()?;
        }
        let count_pos = r.pos();
        let count = r.u32()?;
        if count > 0x1_0000 {
            return Err(Error::field(
                "SavePart1_1_1 count",
                count_pos,
                format!(
                    "{count} entries; the reference implementation rejects anything above 0x10000"
                ),
            ));
        }
        ensure_fits(r, count as usize, 2, "SavePart1_1_1 items")?;
        let mut items = Vec::with_capacity(count as usize);
        for _ in 0..count {
            items.push(SavePart1_1_1_1::parse(r)?);
        }
        Ok(SavePart1_1_1 { head, count, items })
    }
}

impl SavePart1_1_1_1 {
    pub(crate) fn parse(r: &mut Reader<'_>) -> Result<SavePart1_1_1_1> {
        let var1 = r.u8()?;
        let count = usize::from(r.u8()?);
        ensure_fits(r, count, 4, "SavePart1_1_1_1 vars1")?;
        let mut vars1 = Vec::with_capacity(count);
        for _ in 0..count {
            vars1.push(r.u32()?);
        }
        let count = usize::from(r.u8()?);
        ensure_fits(r, count, 1, "SavePart1_1_1_1 vars2")?;
        let vars2 = r.take(count)?.to_vec();
        Ok(SavePart1_1_1_1 { var1, vars1, vars2 })
    }
}

// ---- writing ---------------------------------------------------------

impl SavePart1 {
    /// Re-encode this segment exactly as this module's parse() reads it.
    ///
    /// The version gates are the same ones parse uses, so a part parsed at 0x8C
    /// and re-encoded at 0x8C is byte-identical. A field list whose length
    /// disagrees with what the version expects is an error rather than silently
    /// truncated data.
    pub fn to_bytes(&self, file_version: u16) -> Result<Vec<u8>> {
        let mut out = Vec::new();
        push_u32(&mut out, self.var1);
        push_u32(&mut out, self.var2);
        push_u32(&mut out, self.var3);

        if file_version >= 0x69 {
            push_u32(&mut out, self.map_width);
            push_u32(&mut out, self.map_height);
            if self.map_tiles.is_empty() {
                // No map snapshot: parse reads this word only as the sentinel.
                push_u32(&mut out, u32::MAX);
            } else {
                let want = (self.map_width as usize)
                    .checked_mul(self.map_height as usize)
                    .and_then(|per_layer| per_layer.checked_mul(3))
                    .ok_or_else(|| {
                        Error::field(
                            "SavePart1 map size",
                            out.len(),
                            format!(
                                "{} x {} tiles does not fit in memory",
                                self.map_width, self.map_height
                            ),
                        )
                    })?;
                if self.map_tiles.len() != want {
                    return Err(Error::field(
                        "SavePart1 map tiles",
                        out.len(),
                        format!(
                            "{} tile(s) stored but {} x {} x 3 = {want} expected",
                            self.map_tiles.len(),
                            self.map_width,
                            self.map_height
                        ),
                    ));
                }
                for tile in &self.map_tiles {
                    push_u32(&mut out, *tile);
                }
            }
        }

        push_mem_data(&mut out, &self.chip_image, 4)?;

        let auto_count = if file_version >= 0x8A {
            31
        } else if file_version >= 0x73 {
            15
        } else {
            7
        };
        if self.auto_tiles.len() != auto_count {
            return Err(Error::field(
                "SavePart1 automatic tiles",
                out.len(),
                format!(
                    "{} name(s) stored but {auto_count} expected at file_version {file_version:#06X}",
                    self.auto_tiles.len()
                ),
            ));
        }
        for name in &self.auto_tiles {
            push_mem_data(&mut out, name, 4)?;
        }

        if file_version >= 0x64 {
            push_count(&mut out, self.vars2_new.len())?;
            for word in &self.vars2_new {
                push_u32(&mut out, *word);
            }
        } else {
            push_count(&mut out, self.vars2_old.len())?;
            out.extend_from_slice(&self.vars2_old);
        }

        push_count(&mut out, self.objects.len())?;
        for object in &self.objects {
            out.extend_from_slice(&object.to_bytes(file_version)?);
        }

        if file_version >= 0x72 {
            if self.tail_vars.len() != 11 {
                return Err(Error::field(
                    "SavePart1 tail vars",
                    out.len(),
                    format!(
                        "{} word(s) stored but 11 expected at file_version {file_version:#06X}",
                        self.tail_vars.len()
                    ),
                ));
            }
            for word in &self.tail_vars {
                push_u32(&mut out, *word);
            }
        }

        push_count(&mut out, self.vars3.len())?;
        for word in &self.vars3 {
            push_u32(&mut out, *word);
        }

        Ok(out)
    }
}

impl SavePart1_1 {
    /// Re-encode one object; mirrors SavePart1_1::parse gate for gate.
    pub fn to_bytes(&self, file_version: u16) -> Result<Vec<u8>> {
        let mut out = Vec::new();
        push_u32(&mut out, self.var1);
        push_u32(&mut out, self.var2);
        push_u32(&mut out, self.var3);
        push_u32(&mut out, self.var4);
        push_u8(&mut out, self.var5);
        push_u32(&mut out, self.var6);
        push_mem_data(&mut out, &self.md1, 2)?;
        push_u16(&mut out, self.var7);
        push_u16(&mut out, self.var8);
        push_u16(&mut out, self.var9);
        push_u16(&mut out, self.var10);
        push_u8(&mut out, self.var11);
        push_u8(&mut out, self.var12);
        out.extend_from_slice(&self.sp1.to_bytes()?);
        out.extend_from_slice(&self.sp2.to_bytes()?);
        push_u16(&mut out, self.var13);
        push_u16(&mut out, self.var14);
        push_u16(&mut out, self.var15);
        push_u16(&mut out, self.var16);
        push_u16(&mut out, self.var17);
        push_u16(&mut out, self.var18);
        push_u8(&mut out, self.var19);
        push_u8(&mut out, self.var20);
        push_u8(&mut out, self.var21);

        push_count(&mut out, self.vars1.len())?;
        for word in &self.vars1 {
            push_u32(&mut out, *word);
        }

        if file_version >= 0x70 {
            push_u8(&mut out, self.var23);
            push_u8(&mut out, self.var24);
        }
        if file_version >= 0x73 {
            push_u32(&mut out, self.var25);
            push_u32(&mut out, self.var26);
            push_u32(&mut out, self.var27);
            push_u32(&mut out, self.var28);
        }
        if file_version >= 0x78 {
            push_u32(&mut out, self.var29);
        }
        if file_version >= 0x85 {
            push_u32(&mut out, self.var30);
            push_u32(&mut out, self.var31);
            push_u32(&mut out, self.var32);
        }

        if file_version >= 0x8A {
            // The count is read as a signed 16-bit test, so only 0..=0x7FFF
            // can be expressed; a bigger table would read back as "none".
            if self.mds1.len() > i16::MAX as usize {
                return Err(Error::field(
                    "SavePart1_1 mds1",
                    out.len(),
                    format!(
                        "{} entry(s) do not fit in the signed 16-bit count",
                        self.mds1.len()
                    ),
                ));
            }
            push_u16(&mut out, self.mds1.len() as u16);
            for body in &self.mds1 {
                push_mem_data(&mut out, body, 2)?;
            }
            push_u32(&mut out, self.var34);
            push_u8(&mut out, self.var35);
            push_u32(&mut out, self.var36);
            push_u32(&mut out, self.var37);
        }
        if file_version >= 0x8B {
            push_u32(&mut out, self.var38);
        }
        if file_version >= 0x8C {
            push_u32(&mut out, self.var39);
        }

        Ok(out)
    }
}

impl SavePart1_1_1 {
    /// Re-encode one page table. The stored count always equals items.len().
    pub fn to_bytes(&self) -> Result<Vec<u8>> {
        let mut out = Vec::new();
        out.extend_from_slice(&self.head);
        if usize::try_from(self.count) != Ok(self.items.len()) {
            return Err(Error::field(
                "SavePart1_1_1 count",
                out.len(),
                format!(
                    "m_var7 says {} entr(ies) but {} were stored",
                    self.count,
                    self.items.len()
                ),
            ));
        }
        if self.items.len() > 0x1_0000 {
            return Err(Error::field(
                "SavePart1_1_1 count",
                out.len(),
                format!(
                    "{} entries; parse rejects anything above 0x10000",
                    self.items.len()
                ),
            ));
        }
        push_count(&mut out, self.items.len())?;
        for item in &self.items {
            out.extend_from_slice(&item.to_bytes()?);
        }
        Ok(out)
    }
}

impl SavePart1_1_1_1 {
    /// Re-encode one page-table entry: two u8-length sub tables.
    pub fn to_bytes(&self) -> Result<Vec<u8>> {
        let mut out = Vec::new();
        push_u8(&mut out, self.var1);
        let count = u8::try_from(self.vars1.len()).map_err(|_| {
            Error::field(
                "SavePart1_1_1_1 vars1",
                out.len(),
                format!("{} word(s) do not fit in a u8 count", self.vars1.len()),
            )
        })?;
        push_u8(&mut out, count);
        for word in &self.vars1 {
            push_u32(&mut out, *word);
        }
        let count = u8::try_from(self.vars2.len()).map_err(|_| {
            Error::field(
                "SavePart1_1_1_1 vars2",
                out.len(),
                format!("{} byte(s) do not fit in a u8 count", self.vars2.len()),
            )
        })?;
        push_u8(&mut out, count);
        out.extend_from_slice(&self.vars2);
        Ok(out)
    }
}
