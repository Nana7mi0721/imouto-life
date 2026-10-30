//! `SavePart2` — the global settings snapshot (BGM, background, UI colours,
//! play time and so on).
//!
//! Layout source: `docs/vendor/WolfSave/SavePart2.h`, `Parse` at line 39.
//! Every version gate is spelled out; a field that its gate skips stays at zero
//! (or empty) because the reference implementation does not distinguish
//! "absent" from "zero" either. See `docs/SAVE_SPEC.md` §4.

use wolf_format::bytes::Reader;

use wolf_format::error::Result;

use crate::{
    ensure_fits, mem_data, push_count, push_mem_data, push_u16, push_u32, push_u8, signed_count,
};

/// The `file_version >= 100` block.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SavePart2Block100 {
    /// `m_var54` — `0xFFFFFFFF` in every save here.
    pub var54: u32,
    /// `m_var55` — 10 here.
    pub var55: u32,
    /// `m_var56` — 1 here.
    pub var56: u8,
    /// `m_vars1` — `m_var57` `MemData<DWORD>` entries; empty here.
    pub vars1: Vec<Vec<u8>>,
    /// `m_vars2` — `m_var58` words; five `0xFFFFFFFF` here.
    pub vars2: Vec<u32>,
    /// `m_var59` .. `m_var63`.
    pub vars59_63: [u32; 5],
}

/// The `file_version >= 108` block: two BGM slots with their volume and pan.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SavePart2Bgm {
    /// `m_md3` — the first BGM path, e.g. `BGM/yuuyake.mp3`.
    pub path1: Vec<u8>,
    /// `m_var75` .. `m_var77` — volume, pan and loop for `path1`.
    pub vars75_77: [u32; 3],
    /// `m_md4` — the second BGM path, e.g. `BGM/se_akimusi2.ogg`.
    pub path2: Vec<u8>,
    /// `m_var78` .. `m_var80` — volume, pan and loop for `path2`.
    pub vars78_80: [u32; 3],
}

/// The `file_version >= 109` block.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SavePart2Block109 {
    /// `m_md5` — the current background CG, e.g. `cg/bg_01_home_d.jpg`.
    pub background: Vec<u8>,
    /// `m_md6`.
    pub md6: Vec<u8>,
    /// `m_var81` — 1 here.
    pub var81: u8,
}

/// The `file_version >= 137` block.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SavePart2Block137 {
    /// `m_var98` .. `m_var101` — `[1, 0, 0, 0]` here.
    pub vars98_101: [u32; 4],
    /// `m_vars2` — 24 words, all zero here.
    pub vars2: [u32; 24],
}

/// The `file_version >= 0x8A` block.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SavePart2Block8A {
    /// `m_var102` .. `m_var105`.
    pub vars102_105: [u32; 4],
    /// `m_md10` — the only `MemData<DWORD>` in this segment.
    pub md10: Vec<u8>,
    /// `m_mds2` — `m_var106` entries; five empty ones here.
    pub mds2: Vec<Vec<u8>>,
}

/// The global settings snapshot.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SavePart2 {
    /// `m_var1`.
    pub var1: u8,
    /// `m_var2`.
    pub var2: u8,
    /// `m_var3` .. `m_var21`.
    pub vars3_21: [u32; 19],
    /// `m_var22` .. `m_var24`.
    pub vars22_24: [u16; 3],
    /// `m_var25`.
    pub var25: u32,
    /// `m_var26` .. `m_var28`.
    pub vars26_28: [u16; 3],
    /// `m_var29` .. `m_var37`.
    pub vars29_37: [u32; 9],
    /// `m_var38`.
    pub var38: u8,
    /// `m_var39` — 2 here.
    pub var39: u16,
    /// `m_var40`, `m_var41` — 14 and 8 here.
    pub vars40_41: [u32; 2],
    /// `m_var42` .. `m_var45` — `[160, 68, 75, 200]` here, an RGBA colour.
    pub vars42_45: [u16; 4],
    /// `m_var46` .. `m_var48` — `[120, 1000000, 6]` here.
    pub vars46_48: [u32; 3],
    /// `m_var49` — 1 here.
    pub var49: u8,
    /// `m_var50` — only read at `file_version <= 96`.
    pub var50: u32,
    /// `m_var51`.
    pub var51: u32,
    /// `m_var52`, `m_var53` — `file_version >= 98`.
    pub vars52_53: [u32; 2],
    /// `file_version >= 100` block.
    pub block100: Option<SavePart2Block100>,
    /// `m_var64` .. `m_var69` — `file_version >= 101`.
    pub vars64_69: [u32; 6],
    /// `m_var70` — `file_version >= 102`, a `u16` here.
    pub var70: u16,
    /// `m_md1`, `m_md2` — `file_version >= 103`, `MemData<WORD>`.
    pub md1_md2: Option<(Vec<u8>, Vec<u8>)>,
    /// `m_var71` — `file_version >= 104`. A per-save timestamp.
    pub var71: u32,
    /// `m_var72` .. `m_var74` — `file_version >= 106`.
    pub vars72_74: [u32; 3],
    /// `file_version >= 108` block.
    pub bgm: Option<SavePart2Bgm>,
    /// `file_version >= 109` block.
    pub block109: Option<SavePart2Block109>,
    /// `m_var82` — `file_version >= 110`.
    pub var82: u8,
    /// `m_md7` .. `m_md9` — `file_version >= 119`, `MemData<WORD>`.
    pub mds7_9: Option<[Vec<u8>; 3]>,
    /// `m_var83` — `file_version >= 121`.
    pub var83: u32,
    /// `m_var84` — `file_version >= 122`.
    pub var84: u32,
    /// `m_var85` — `file_version >= 124`.
    pub var85: u32,
    /// `m_var86` — `file_version >= 126`, 12 here.
    pub var86: u32,
    /// `m_var87` — `file_version >= 128`.
    pub var87: u32,
    /// `m_var88`, `m_var89` — `file_version >= 129`.
    pub vars88_89: [u32; 2],
    /// `m_var90` — `file_version >= 130`.
    pub var90: u32,
    /// `m_var91` — `file_version >= 131`.
    pub var91: u32,
    /// `m_var92` .. `m_var95` — `file_version >= 132`.
    pub vars92_95: [u32; 4],
    /// `m_var96` — `file_version >= 134`, 1 here.
    pub var96: u8,
    /// `m_var97` — `file_version >= 136`, 1 here.
    pub var97: u8,
    /// `file_version >= 137` block.
    pub block137: Option<SavePart2Block137>,
    /// `file_version >= 0x8A` block.
    pub block8a: Option<SavePart2Block8A>,
}

fn array_u32(r: &mut Reader<'_>, len: usize, what: &'static str) -> Result<Vec<u32>> {
    ensure_fits(r, len, 4, what)?;
    let mut out = Vec::with_capacity(len);
    for _ in 0..len {
        out.push(r.u32()?);
    }
    Ok(out)
}

fn array_u16(r: &mut Reader<'_>, len: usize, what: &'static str) -> Result<Vec<u16>> {
    ensure_fits(r, len, 2, what)?;
    let mut out = Vec::with_capacity(len);
    for _ in 0..len {
        out.push(r.u16()?);
    }
    Ok(out)
}

fn fixed_u32<const N: usize>(r: &mut Reader<'_>, what: &'static str) -> Result<[u32; N]> {
    let v = array_u32(r, N, what)?;
    let mut out = [0u32; N];
    out.copy_from_slice(&v);
    Ok(out)
}

fn fixed_u16<const N: usize>(r: &mut Reader<'_>, what: &'static str) -> Result<[u16; N]> {
    let v = array_u16(r, N, what)?;
    let mut out = [0u16; N];
    out.copy_from_slice(&v);
    Ok(out)
}

pub(crate) fn parse(r: &mut Reader<'_>, file_version: u16) -> Result<SavePart2> {
    let var1 = r.u8()?;
    let var2 = r.u8()?;
    let vars3_21 = fixed_u32::<19>(r, "SavePart2 vars3_21")?;
    let vars22_24 = fixed_u16::<3>(r, "SavePart2 vars22_24")?;
    let var25 = r.u32()?;
    let vars26_28 = fixed_u16::<3>(r, "SavePart2 vars26_28")?;
    let vars29_37 = fixed_u32::<9>(r, "SavePart2 vars29_37")?;
    let var38 = r.u8()?;
    let var39 = r.u16()?;
    let vars40_41 = fixed_u32::<2>(r, "SavePart2 vars40_41")?;
    let vars42_45 = fixed_u16::<4>(r, "SavePart2 vars42_45")?;
    let vars46_48 = fixed_u32::<3>(r, "SavePart2 vars46_48")?;
    let var49 = r.u8()?;

    let mut var50 = 0;
    if file_version <= 96 {
        var50 = r.u32()?;
    }

    let var51 = r.u32()?;

    let mut vars52_53 = [0u32; 2];
    if file_version >= 98 {
        vars52_53 = fixed_u32::<2>(r, "SavePart2 vars52_53")?;
    }

    let mut block100 = None;
    if file_version >= 100 {
        let var54 = r.u32()?;
        let var55 = r.u32()?;
        let var56 = r.u8()?;
        let count = signed_count(r.u32()?);
        ensure_fits(r, count, 2, "SavePart2 vars1")?;
        let mut vars1 = Vec::with_capacity(count);
        for _ in 0..count {
            vars1.push(mem_data(r, 4)?);
        }
        let count = signed_count(r.u32()?);
        let vars2 = array_u32(r, count, "SavePart2 vars2")?;
        let vars59_63 = fixed_u32::<5>(r, "SavePart2 vars59_63")?;
        block100 = Some(SavePart2Block100 {
            var54,
            var55,
            var56,
            vars1,
            vars2,
            vars59_63,
        });
    }

    let mut vars64_69 = [0u32; 6];
    if file_version >= 101 {
        vars64_69 = fixed_u32::<6>(r, "SavePart2 vars64_69")?;
    }

    let mut var70 = 0;
    if file_version >= 102 {
        var70 = r.u16()?;
    }

    let mut md1_md2 = None;
    if file_version >= 103 {
        md1_md2 = Some((mem_data(r, 2)?, mem_data(r, 2)?));
    }

    let mut var71 = 0;
    if file_version >= 104 {
        var71 = r.u32()?;
    }

    let mut vars72_74 = [0u32; 3];
    if file_version >= 106 {
        vars72_74 = fixed_u32::<3>(r, "SavePart2 vars72_74")?;
    }

    let mut bgm = None;
    if file_version >= 108 {
        let path1 = mem_data(r, 2)?;
        let vars75_77 = fixed_u32::<3>(r, "SavePart2 vars75_77")?;
        let path2 = mem_data(r, 2)?;
        let vars78_80 = fixed_u32::<3>(r, "SavePart2 vars78_80")?;
        bgm = Some(SavePart2Bgm {
            path1,
            vars75_77,
            path2,
            vars78_80,
        });
    }

    let mut block109 = None;
    if file_version >= 109 {
        let background = mem_data(r, 2)?;
        let md6 = mem_data(r, 2)?;
        let var81 = r.u8()?;
        block109 = Some(SavePart2Block109 {
            background,
            md6,
            var81,
        });
    }

    let mut var82 = 0;
    if file_version >= 110 {
        var82 = r.u8()?;
    }

    let mut mds7_9 = None;
    if file_version >= 119 {
        mds7_9 = Some([mem_data(r, 2)?, mem_data(r, 2)?, mem_data(r, 2)?]);
    }

    let mut var83 = 0;
    if file_version >= 121 {
        var83 = r.u32()?;
    }
    let mut var84 = 0;
    if file_version >= 122 {
        var84 = r.u32()?;
    }
    let mut var85 = 0;
    if file_version >= 124 {
        var85 = r.u32()?;
    }
    let mut var86 = 0;
    if file_version >= 126 {
        var86 = r.u32()?;
    }
    let mut var87 = 0;
    if file_version >= 128 {
        var87 = r.u32()?;
    }
    let mut vars88_89 = [0u32; 2];
    if file_version >= 129 {
        vars88_89 = fixed_u32::<2>(r, "SavePart2 vars88_89")?;
    }
    let mut var90 = 0;
    if file_version >= 130 {
        var90 = r.u32()?;
    }
    let mut var91 = 0;
    if file_version >= 131 {
        var91 = r.u32()?;
    }
    let mut vars92_95 = [0u32; 4];
    if file_version >= 132 {
        vars92_95 = fixed_u32::<4>(r, "SavePart2 vars92_95")?;
    }
    let mut var96 = 0;
    if file_version >= 134 {
        var96 = r.u8()?;
    }
    let mut var97 = 0;
    if file_version >= 136 {
        var97 = r.u8()?;
    }

    let mut block137 = None;
    if file_version >= 137 {
        let vars98_101 = fixed_u32::<4>(r, "SavePart2 vars98_101")?;
        let vars2 = fixed_u32::<24>(r, "SavePart2 vars2 (137)")?;
        block137 = Some(SavePart2Block137 { vars98_101, vars2 });
    }

    let mut block8a = None;
    if file_version >= 0x8A {
        let vars102_105 = fixed_u32::<4>(r, "SavePart2 vars102_105")?;
        let md10 = mem_data(r, 4)?;
        let count = signed_count(r.u32()?);
        ensure_fits(r, count, 2, "SavePart2 mds2")?;
        let mut mds2 = Vec::with_capacity(count);
        for _ in 0..count {
            mds2.push(mem_data(r, 4)?);
        }
        block8a = Some(SavePart2Block8A {
            vars102_105,
            md10,
            mds2,
        });
    }

    Ok(SavePart2 {
        var1,
        var2,
        vars3_21,
        vars22_24,
        var25,
        vars26_28,
        vars29_37,
        var38,
        var39,
        vars40_41,
        vars42_45,
        vars46_48,
        var49,
        var50,
        var51,
        vars52_53,
        block100,
        vars64_69,
        var70,
        md1_md2,
        var71,
        vars72_74,
        bgm,
        block109,
        var82,
        mds7_9,
        var83,
        var84,
        var85,
        var86,
        var87,
        vars88_89,
        var90,
        var91,
        vars92_95,
        var96,
        var97,
        block137,
        block8a,
    })
}

// ---- writing ---------------------------------------------------------

impl SavePart2 {
    /// Re-encode this segment exactly as this module's parse() reads it.
    pub fn to_bytes(&self, file_version: u16) -> Result<Vec<u8>> {
        let mut out = Vec::new();
        push_u8(&mut out, self.var1);
        push_u8(&mut out, self.var2);
        for word in &self.vars3_21 {
            push_u32(&mut out, *word);
        }
        for word in &self.vars22_24 {
            push_u16(&mut out, *word);
        }
        push_u32(&mut out, self.var25);
        for word in &self.vars26_28 {
            push_u16(&mut out, *word);
        }
        for word in &self.vars29_37 {
            push_u32(&mut out, *word);
        }
        push_u8(&mut out, self.var38);
        push_u16(&mut out, self.var39);
        for word in &self.vars40_41 {
            push_u32(&mut out, *word);
        }
        for word in &self.vars42_45 {
            push_u16(&mut out, *word);
        }
        for word in &self.vars46_48 {
            push_u32(&mut out, *word);
        }
        push_u8(&mut out, self.var49);

        if file_version <= 96 {
            push_u32(&mut out, self.var50);
        }

        push_u32(&mut out, self.var51);

        if file_version >= 98 {
            for word in &self.vars52_53 {
                push_u32(&mut out, *word);
            }
        }

        if file_version >= 100 {
            let (var54, var55, var56, vars1, vars2, vars59_63) = match &self.block100 {
                Some(block) => (
                    block.var54,
                    block.var55,
                    block.var56,
                    block.vars1.as_slice(),
                    block.vars2.as_slice(),
                    block.vars59_63,
                ),
                None => (0, 0, 0, &[][..], &[][..], [0u32; 5]),
            };
            push_u32(&mut out, var54);
            push_u32(&mut out, var55);
            push_u8(&mut out, var56);
            push_count(&mut out, vars1.len())?;
            for body in vars1 {
                push_mem_data(&mut out, body, 4)?;
            }
            push_count(&mut out, vars2.len())?;
            for word in vars2 {
                push_u32(&mut out, *word);
            }
            for word in &vars59_63 {
                push_u32(&mut out, *word);
            }
        }

        if file_version >= 101 {
            for word in &self.vars64_69 {
                push_u32(&mut out, *word);
            }
        }

        if file_version >= 102 {
            push_u16(&mut out, self.var70);
        }

        if file_version >= 103 {
            let (md1, md2) = match &self.md1_md2 {
                Some((first, second)) => (first.as_slice(), second.as_slice()),
                None => (&[][..], &[][..]),
            };
            push_mem_data(&mut out, md1, 2)?;
            push_mem_data(&mut out, md2, 2)?;
        }

        if file_version >= 104 {
            push_u32(&mut out, self.var71);
        }

        if file_version >= 106 {
            for word in &self.vars72_74 {
                push_u32(&mut out, *word);
            }
        }

        if file_version >= 108 {
            let (path1, vars75_77, path2, vars78_80) = match &self.bgm {
                Some(bgm) => (
                    bgm.path1.as_slice(),
                    bgm.vars75_77,
                    bgm.path2.as_slice(),
                    bgm.vars78_80,
                ),
                None => (&[][..], [0u32; 3], &[][..], [0u32; 3]),
            };
            push_mem_data(&mut out, path1, 2)?;
            for word in &vars75_77 {
                push_u32(&mut out, *word);
            }
            push_mem_data(&mut out, path2, 2)?;
            for word in &vars78_80 {
                push_u32(&mut out, *word);
            }
        }

        if file_version >= 109 {
            let (background, md6, var81) = match &self.block109 {
                Some(block) => (
                    block.background.as_slice(),
                    block.md6.as_slice(),
                    block.var81,
                ),
                None => (&[][..], &[][..], 0),
            };
            push_mem_data(&mut out, background, 2)?;
            push_mem_data(&mut out, md6, 2)?;
            push_u8(&mut out, var81);
        }

        if file_version >= 110 {
            push_u8(&mut out, self.var82);
        }

        if file_version >= 119 {
            match &self.mds7_9 {
                Some(bodies) => {
                    for body in bodies {
                        push_mem_data(&mut out, body, 2)?;
                    }
                }
                None => {
                    for _ in 0..3 {
                        push_mem_data(&mut out, &[], 2)?;
                    }
                }
            }
        }

        if file_version >= 121 {
            push_u32(&mut out, self.var83);
        }
        if file_version >= 122 {
            push_u32(&mut out, self.var84);
        }
        if file_version >= 124 {
            push_u32(&mut out, self.var85);
        }
        if file_version >= 126 {
            push_u32(&mut out, self.var86);
        }
        if file_version >= 128 {
            push_u32(&mut out, self.var87);
        }
        if file_version >= 129 {
            for word in &self.vars88_89 {
                push_u32(&mut out, *word);
            }
        }
        if file_version >= 130 {
            push_u32(&mut out, self.var90);
        }
        if file_version >= 131 {
            push_u32(&mut out, self.var91);
        }
        if file_version >= 132 {
            for word in &self.vars92_95 {
                push_u32(&mut out, *word);
            }
        }
        if file_version >= 134 {
            push_u8(&mut out, self.var96);
        }
        if file_version >= 136 {
            push_u8(&mut out, self.var97);
        }

        if file_version >= 137 {
            let (vars98_101, vars2) = match &self.block137 {
                Some(block) => (block.vars98_101, block.vars2),
                None => ([0u32; 4], [0u32; 24]),
            };
            for word in &vars98_101 {
                push_u32(&mut out, *word);
            }
            for word in &vars2 {
                push_u32(&mut out, *word);
            }
        }

        if file_version >= 0x8A {
            let (vars102_105, md10, mds2) = match &self.block8a {
                Some(block) => (
                    block.vars102_105,
                    block.md10.as_slice(),
                    block.mds2.as_slice(),
                ),
                None => ([0u32; 4], &[][..], &[][..]),
            };
            for word in &vars102_105 {
                push_u32(&mut out, *word);
            }
            push_mem_data(&mut out, md10, 4)?;
            push_count(&mut out, mds2.len())?;
            for body in mds2 {
                push_mem_data(&mut out, body, 4)?;
            }
        }

        Ok(out)
    }
}
