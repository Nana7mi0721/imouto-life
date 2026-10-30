//! `SavePart3` — the map and event runtime tables.
//!
//! This is the largest segment (218,610 bytes in `SaveData01.sav`). Layout
//! source: `docs/vendor/WolfSave/SavePart3.h`, `Parse` at line 38. Note that
//! every nesting level sits behind a signed test, so a negative count silently
//! truncates the whole tail of the segment — that is the reference behaviour
//! and it is reproduced here. See `docs/SAVE_SPEC.md` §5.

use wolf_format::bytes::Reader;
use wolf_format::error::{Error, Result};

use crate::{ensure_fits, mem_data};

/// One entry of the `m_vars1`/`m_vars2`/`m_vars3` table: a count and a list.
#[derive(Debug, Clone, PartialEq, Eq, Default)]
pub struct SavePart3Group {
    /// `m_vars1` — the group's element count.
    pub count: u32,
    /// `m_vars2` — one byte per element.
    pub bytes: Vec<u8>,
    /// `m_vars3` — the words collected across all elements of this group.
    pub words: Vec<u32>,
}

/// One entry of the `m_vars4`/`m_vars5` table.
#[derive(Debug, Clone, PartialEq, Eq, Default)]
pub struct SavePart3Row {
    /// `m_vars4` — the row's element count.
    pub count: u32,
    /// `m_vars5` — the row's words.
    pub words: Vec<u32>,
}

/// One entry of the `m_vars6`/`m_vars7` table.
#[derive(Debug, Clone, PartialEq, Eq, Default)]
pub struct SavePart3List {
    /// `m_vars6` — one byte per entry.
    pub count: u8,
    /// `m_vars7` — the words collected across all entries.
    pub words: Vec<u32>,
}

/// One entry of the `m_vars8`/`m_mds2` table.
#[derive(Debug, Clone, PartialEq, Eq, Default)]
pub struct SavePart3Slot {
    /// `m_vars8` — the number of strings that follow; 0 reads nothing.
    pub count: u8,
    /// `m_mds2New` (`m_mds2Old` below `0x6F`).
    pub strings: Vec<Vec<u8>>,
}

/// The map and event runtime tables.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct SavePart3 {
    /// `m_var1` — differs per save; looks like a timestamp or seed.
    pub var1: u32,
    /// `m_var2` — 2 here; the number of groups.
    pub var2: u32,
    /// `m_vars1` — the group count column.
    pub group_counts: Vec<u32>,
    /// `m_vars2` — the per-element byte column.
    pub group_bytes: Vec<u8>,
    /// `m_vars3` — the words collected across the groups.
    pub group_words: Vec<u32>,
    /// `m_var3` — 10 here.
    pub var3: u32,
    /// `m_vars4` — the row count column.
    pub row_counts: Vec<u32>,
    /// `m_vars5` — the words collected across the rows.
    pub row_words: Vec<u32>,
    /// `m_var4` — 26 here; the number of `MemData` entries.
    pub var4: u32,
    /// `m_mds1New` — 26 strings here, starting with `"周一"` and a save-thumbnail path.
    pub mds1: Vec<Vec<u8>>,
    /// `m_var5` — 500 here (550 in two saves); the number of lists.
    pub var5: u32,
    /// `m_vars6` — one byte per list.
    pub list_counts: Vec<u8>,
    /// `m_vars7` — the words collected across the lists.
    pub list_words: Vec<u32>,
    /// `m_var6` — 500 here (550 in two saves); the number of slots.
    pub var6: u32,
    /// `m_vars8` — one byte per slot.
    pub slot_counts: Vec<u8>,
    /// `m_mds2New` — the strings collected across the slots.
    pub slot_strings: Vec<Vec<u8>>,
}

pub(crate) fn parse(r: &mut Reader<'_>, file_version: u16) -> Result<SavePart3> {
    let var1 = r.u32()?;
    let var2 = r.u32()?;

    let mut part = SavePart3 {
        var1,
        var2,
        group_counts: Vec::new(),
        group_bytes: Vec::new(),
        group_words: Vec::new(),
        var3: 0,
        row_counts: Vec::new(),
        row_words: Vec::new(),
        var4: 0,
        mds1: Vec::new(),
        var5: 0,
        list_counts: Vec::new(),
        list_words: Vec::new(),
        var6: 0,
        slot_counts: Vec::new(),
        slot_strings: Vec::new(),
    };

    if (var2 as i32) < 0 {
        return Ok(part);
    }

    for _ in 0..var2 {
        let count_pos = r.pos();
        let count = r.u32()?;
        if (count as i32) < 0 {
            return Err(Error::field(
                "SavePart3 group count",
                count_pos,
                format!(
                    "{count:#010X} is negative; the reference implementation aborts the segment"
                ),
            ));
        }
        part.group_counts.push(count);
        ensure_fits(r, count as usize, 1, "SavePart3 group bytes")?;
        for _ in 0..count {
            let per = r.u8()?;
            part.group_bytes.push(per);
            ensure_fits(r, usize::from(per), 4, "SavePart3 group words")?;
            for _ in 0..per {
                part.group_words.push(r.u32()?);
            }
        }
    }

    part.var3 = r.u32()?;
    if part.var3 > 0x270F {
        return Ok(part);
    }

    if (part.var3 as i32) > 0 {
        for _ in 0..part.var3 {
            let count_pos = r.pos();
            let count = r.u32()?;
            if (count as i32) < 0 {
                return Err(Error::field(
                    "SavePart3 row count",
                    count_pos,
                    format!("{count:#010X} is negative; the reference implementation aborts the segment"),
                ));
            }
            part.row_counts.push(count);
            ensure_fits(r, count as usize, 4, "SavePart3 row words")?;
            for _ in 0..count {
                part.row_words.push(r.u32()?);
            }
        }
    }

    part.var4 = r.u32()?;
    if (part.var4 as i32) < 0 {
        return Ok(part);
    }

    let size: u8 = if file_version < 0x6F { 2 } else { 4 };
    ensure_fits(r, part.var4 as usize, usize::from(size), "SavePart3 mds1")?;
    for _ in 0..part.var4 {
        part.mds1.push(mem_data(r, size)?);
    }

    part.var5 = r.u32()?;
    let count_pos = r.pos();
    if (part.var5 as i32) < 0 || part.var5 > 10_000 {
        return Err(Error::field(
            "SavePart3 var5",
            count_pos,
            format!("{} is outside 0..=10000", part.var5),
        ));
    }

    for _ in 0..part.var5 {
        let per = r.u8()?;
        part.list_counts.push(per);
        ensure_fits(r, usize::from(per), 4, "SavePart3 list words")?;
        for _ in 0..per {
            part.list_words.push(r.u32()?);
        }
    }

    part.var6 = r.u32()?;
    if part.var6 > 10_000 {
        return Ok(part);
    }
    let count_pos = r.pos();
    if (part.var6 as i32) <= 0 {
        return Err(Error::field(
            "SavePart3 var6",
            count_pos,
            format!(
                "{:#010X} is zero or negative while the segment still has data; the reference implementation rejects it",
                part.var6
            ),
        ));
    }

    for _ in 0..part.var6 {
        let per = r.u8()?;
        part.slot_counts.push(per);
        if per != 0 {
            ensure_fits(
                r,
                usize::from(per),
                usize::from(size),
                "SavePart3 slot strings",
            )?;
            for _ in 0..per {
                part.slot_strings.push(mem_data(r, size)?);
            }
        }
    }

    Ok(part)
}

// ---------------------------------------------------------------------------
// Writing
// ---------------------------------------------------------------------------

/// MemData bodies carry a u32 byte length in every save this game writes.
///
/// The width flips at file_version 0x6F; see
/// [SavePart3::to_bytes_with_version].
const MODERN_MEM_DATA: u8 = 4;

/// Row 0 of the m_vars4/m_vars5 table holds the **normal variables**: word
/// n of that row is variable 2000000 + n, which is why
/// [SavePart3::normal_var] indexes row 0. See docs/SAVE_SPEC.md section 6.1.
pub const NORMAL_VAR_ROW: usize = 0;

impl SavePart3 {
    /// Re-encode the segment exactly as it sits on disk.
    ///
    /// This is the inverse of parse: for the nine saves this game ships the
    /// result equals the original segment bytes byte for byte, so a caller can
    /// edit one variable and write the file back without disturbing anything
    /// else (crates/wolf-save/tests/typed.rs proves it).
    ///
    /// Assumes file_version >= 0x6F, i.e. 4-byte MemData lengths -- that is
    /// what this game writes (0x8C). For anything older use
    /// [SavePart3::to_bytes_with_version].
    pub fn to_bytes(&self) -> Result<Vec<u8>> {
        self.encode(MODERN_MEM_DATA)
    }

    /// Like [SavePart3::to_bytes], but honours the MemData width of
    /// file_version (u16 below 0x6F, u32 from 0x6F on).
    pub fn to_bytes_with_version(&self, file_version: u16) -> Result<Vec<u8>> {
        self.encode(if file_version < 0x6F { 2 } else { 4 })
    }

    /// The shared encoder behind [SavePart3::to_bytes].
    ///
    /// The three early returns mirror parse one for one: a segment the
    /// reference implementation truncates re-encodes to the same prefix, so the
    /// writer stays total even for corrupted input.
    fn encode(&self, size: u8) -> Result<Vec<u8>> {
        let mut out = Vec::with_capacity(1024);
        push_u32(&mut out, self.var1);
        push_u32(&mut out, self.var2);
        if (self.var2 as i32) < 0 {
            return Ok(out);
        }

        let groups = self.var2 as usize;
        if self.group_counts.len() != groups {
            return Err(Error::field(
                "SavePart3 group_counts",
                out.len(),
                format!(
                    "m_var2 says {groups} group(s) but {} count(s) were stored",
                    self.group_counts.len()
                ),
            ));
        }
        let mut bytes_at = 0usize;
        let mut words_at = 0usize;
        for count in &self.group_counts {
            push_u32(&mut out, *count);
            for _ in 0..*count {
                let per = match self.group_bytes.get(bytes_at) {
                    Some(per) => *per,
                    None => {
                        return Err(Error::field(
                            "SavePart3 group_bytes",
                            out.len(),
                            format!(
                                "m_var2/m_vars1 need more than the {} byte(s) stored",
                                self.group_bytes.len()
                            ),
                        ))
                    }
                };
                bytes_at += 1;
                out.push(per);
                let want = usize::from(per);
                let end = match words_at.checked_add(want) {
                    Some(end) => end,
                    None => {
                        return Err(Error::field(
                            "SavePart3 group_words",
                            out.len(),
                            "word offset overflowed".to_string(),
                        ))
                    }
                };
                let words = match self.group_words.get(words_at..end) {
                    Some(words) => words,
                    None => {
                        return Err(Error::field(
                            "SavePart3 group_words",
                            out.len(),
                            format!(
                                "the per-element byte column wants more than the {} word(s) stored",
                                self.group_words.len()
                            ),
                        ))
                    }
                };
                for word in words {
                    push_u32(&mut out, *word);
                }
                words_at = end;
            }
        }
        if bytes_at != self.group_bytes.len() || words_at != self.group_words.len() {
            return Err(Error::field(
                "SavePart3 group tables",
                out.len(),
                format!(
                    "{} byte(s) and {} word(s) were left over",
                    self.group_bytes.len() - bytes_at,
                    self.group_words.len() - words_at
                ),
            ));
        }

        push_u32(&mut out, self.var3);
        if self.var3 > 0x270F {
            return Ok(out);
        }

        if (self.var3 as i32) > 0 {
            let rows = self.var3 as usize;
            if self.row_counts.len() != rows {
                return Err(Error::field(
                    "SavePart3 row_counts",
                    out.len(),
                    format!(
                        "m_var3 says {rows} row(s) but {} count(s) were stored",
                        self.row_counts.len()
                    ),
                ));
            }
            let mut at = 0usize;
            for count in &self.row_counts {
                push_u32(&mut out, *count);
                let want = *count as usize;
                let end = match at.checked_add(want) {
                    Some(end) => end,
                    None => {
                        return Err(Error::field(
                            "SavePart3 row_words",
                            out.len(),
                            "word offset overflowed".to_string(),
                        ))
                    }
                };
                let words = match self.row_words.get(at..end) {
                    Some(words) => words,
                    None => {
                        return Err(Error::field(
                            "SavePart3 row_words",
                            out.len(),
                            format!(
                                "the row counts want more than the {} word(s) stored",
                                self.row_words.len()
                            ),
                        ))
                    }
                };
                for word in words {
                    push_u32(&mut out, *word);
                }
                at = end;
            }
            if at != self.row_words.len() {
                return Err(Error::field(
                    "SavePart3 row tables",
                    out.len(),
                    format!("{} word(s) were left over", self.row_words.len() - at),
                ));
            }
        }

        push_u32(&mut out, self.var4);
        if (self.var4 as i32) < 0 {
            return Ok(out);
        }
        if self.mds1.len() != self.var4 as usize {
            return Err(Error::field(
                "SavePart3 mds1",
                out.len(),
                format!(
                    "m_var4 says {} entry(s) but {} were stored",
                    self.var4,
                    self.mds1.len()
                ),
            ));
        }
        for body in &self.mds1 {
            push_mem_data(&mut out, body, size)?;
        }

        push_u32(&mut out, self.var5);
        if (self.var5 as i32) < 0 || self.var5 > 10_000 {
            return Err(Error::field(
                "SavePart3 var5",
                out.len(),
                format!("{} is outside 0..=10000", self.var5),
            ));
        }
        if self.list_counts.len() != self.var5 as usize {
            return Err(Error::field(
                "SavePart3 list_counts",
                out.len(),
                format!(
                    "m_var5 says {} list(s) but {} count(s) were stored",
                    self.var5,
                    self.list_counts.len()
                ),
            ));
        }
        let mut at = 0usize;
        for count in &self.list_counts {
            out.push(*count);
            let want = usize::from(*count);
            let end = match at.checked_add(want) {
                Some(end) => end,
                None => {
                    return Err(Error::field(
                        "SavePart3 list_words",
                        out.len(),
                        "word offset overflowed".to_string(),
                    ))
                }
            };
            let words = match self.list_words.get(at..end) {
                Some(words) => words,
                None => {
                    return Err(Error::field(
                        "SavePart3 list_words",
                        out.len(),
                        format!(
                            "the list counts want more than the {} word(s) stored",
                            self.list_words.len()
                        ),
                    ))
                }
            };
            for word in words {
                push_u32(&mut out, *word);
            }
            at = end;
        }
        if at != self.list_words.len() {
            return Err(Error::field(
                "SavePart3 list tables",
                out.len(),
                format!("{} word(s) were left over", self.list_words.len() - at),
            ));
        }

        push_u32(&mut out, self.var6);
        if self.var6 > 10_000 {
            return Ok(out);
        }
        if (self.var6 as i32) <= 0 {
            return Err(Error::field(
                "SavePart3 var6",
                out.len(),
                format!("{:#010X} is zero or negative", self.var6),
            ));
        }
        if self.slot_counts.len() != self.var6 as usize {
            return Err(Error::field(
                "SavePart3 slot_counts",
                out.len(),
                format!(
                    "m_var6 says {} slot(s) but {} count(s) were stored",
                    self.var6,
                    self.slot_counts.len()
                ),
            ));
        }
        let mut at = 0usize;
        for count in &self.slot_counts {
            out.push(*count);
            let want = usize::from(*count);
            let end = match at.checked_add(want) {
                Some(end) => end,
                None => {
                    return Err(Error::field(
                        "SavePart3 slot_strings",
                        out.len(),
                        "string offset overflowed".to_string(),
                    ))
                }
            };
            let strings = match self.slot_strings.get(at..end) {
                Some(strings) => strings,
                None => {
                    return Err(Error::field(
                        "SavePart3 slot_strings",
                        out.len(),
                        format!(
                            "the slot counts want more than the {} string(s) stored",
                            self.slot_strings.len()
                        ),
                    ))
                }
            };
            for body in strings {
                push_mem_data(&mut out, body, size)?;
            }
            at = end;
        }
        if at != self.slot_strings.len() {
            return Err(Error::field(
                "SavePart3 slot tables",
                out.len(),
                format!("{} string(s) were left over", self.slot_strings.len() - at),
            ));
        }

        Ok(out)
    }
}

// ---------------------------------------------------------------------------
// Typed accessors
// ---------------------------------------------------------------------------

impl SavePart3 {
    /// Where row row's words start and end inside [SavePart3::row_words].
    fn row_span(&self, row: usize) -> Option<core::ops::Range<usize>> {
        table_span(self.row_counts.iter().map(|count| *count as usize), row)
    }

    /// Where group group's words start and end inside [SavePart3::list_words].
    fn group_span(&self, group: usize) -> Option<core::ops::Range<usize>> {
        table_span(
            self.list_counts.iter().map(|count| usize::from(*count)),
            group,
        )
    }

    /// Where group group's strings start and end inside
    /// [SavePart3::slot_strings].
    fn slot_span(&self, group: usize) -> Option<core::ops::Range<usize>> {
        table_span(
            self.slot_counts.iter().map(|count| usize::from(*count)),
            group,
        )
    }

    /// Normal variable 2000000 + index, e.g. index 7 is the money HUD value
    /// (7586 in SaveData01).
    ///
    /// Row 0 holds 800 words in every save this game ships, so indexes 0..800
    /// work; anything further is None.
    #[must_use]
    pub fn normal_var(&self, index: usize) -> Option<i32> {
        let span = self.row_span(NORMAL_VAR_ROW)?;
        if index >= span.len() {
            return None;
        }
        Some(self.row_words[span.start + index] as i32)
    }

    /// Overwrite normal variable 2000000 + index; false when out of range.
    pub fn set_normal_var(&mut self, index: usize, value: i32) -> bool {
        let Some(span) = self.row_span(NORMAL_VAR_ROW) else {
            return false;
        };
        if index >= span.len() {
            return false;
        }
        self.row_words[span.start + index] = value as u32;
        true
    }

    /// Self variable slot of common event event, i.e. CSelf0..CSelf99.
    ///
    /// The group index **is** the common event id (0-based), which is why the
    /// table has 500 or 550 entries in this game; slot is the self-variable
    /// number, not an offset. Values are stored as raw u32, so a negative
    /// number reads back negative.
    #[must_use]
    pub fn self_var(&self, event: u32, slot: usize) -> Option<i32> {
        let span = self.group_span(event as usize)?;
        if slot >= span.len() {
            return None;
        }
        Some(self.list_words[span.start + slot] as i32)
    }

    /// Overwrite self variable slot of common event event; false when out of
    /// range.
    pub fn set_self_var(&mut self, event: u32, slot: usize, value: i32) -> bool {
        let Some(span) = self.group_span(event as usize) else {
            return false;
        };
        if slot >= span.len() {
            return false;
        }
        self.list_words[span.start + slot] = value as u32;
        true
    }

    /// Self **string** variable of common event event, as raw body bytes (the
    /// length prefix is already stripped).
    ///
    /// slot is the position inside the event's string group, so slot 0 is
    /// CSelf5, the first string a call site can pass, and slot 4 is CSelf9. The
    /// engine stores only those five per event, which is why every
    /// slot_counts entry is 5 in this game.
    #[must_use]
    pub fn self_string_bytes(&self, event: u32, slot: usize) -> Option<&[u8]> {
        let span = self.slot_span(event as usize)?;
        if slot >= span.len() {
            return None;
        }
        self.slot_strings.get(span.start + slot).map(Vec::as_slice)
    }

    /// Self string variable slot of common event event as text.
    ///
    /// None means "out of range **or** not valid UTF-8"; use
    /// [SavePart3::self_string_bytes] when the distinction matters. A body of
    /// length 0 or 1 is the empty string, matching [crate::mem_string] and
    /// WolfSave's MemData::toString.
    #[must_use]
    pub fn self_string(&self, event: u32, slot: usize) -> Option<&str> {
        text_of(self.self_string_bytes(event, slot)?)
    }

    /// Overwrite self string variable slot of common event event.
    ///
    /// The new body is stored NUL-terminated, the way the game writes it. False
    /// when the slot does not exist.
    pub fn set_self_string(&mut self, event: u32, slot: usize, text: &str) -> bool {
        let Some(span) = self.slot_span(event as usize) else {
            return false;
        };
        if slot >= span.len() {
            return false;
        }
        let mut body = text.as_bytes().to_vec();
        body.push(0);
        self.slot_strings[span.start + slot] = body;
        true
    }
}

/// The span of the index-th entry inside a flattened column, computed by
/// summing the per-entry lengths that precede it.
fn table_span(
    lengths: impl Iterator<Item = usize>,
    index: usize,
) -> Option<core::ops::Range<usize>> {
    let mut at = 0usize;
    for (slot, len) in lengths.enumerate() {
        if slot == index {
            return Some(at..at.checked_add(len)?);
        }
        at = at.checked_add(len)?;
    }
    None
}

/// Append a little-endian u32.
fn push_u32(out: &mut Vec<u8>, value: u32) {
    out.extend_from_slice(&value.to_le_bytes());
}

/// Append one MemData body: a byte length of size bytes, then the bytes.
fn push_mem_data(out: &mut Vec<u8>, body: &[u8], size: u8) -> Result<()> {
    let too_big = || {
        Error::field(
            "MemData length",
            out.len(),
            format!("{} byte(s) do not fit in a {size}-byte length", body.len()),
        )
    };
    match size {
        1 => match u8::try_from(body.len()) {
            Ok(len) => out.push(len),
            Err(_) => return Err(too_big()),
        },
        2 => match u16::try_from(body.len()) {
            Ok(len) => out.extend_from_slice(&len.to_le_bytes()),
            Err(_) => return Err(too_big()),
        },
        4 => match u32::try_from(body.len()) {
            Ok(len) => push_u32(out, len),
            Err(_) => return Err(too_big()),
        },
        other => {
            return Err(Error::field(
                "MemData element size",
                out.len(),
                format!("{other} is not 1, 2 or 4"),
            ))
        }
    }
    out.extend_from_slice(body);
    Ok(())
}

/// One MemData body decoded as text, or None when it is not UTF-8.
fn text_of(bytes: &[u8]) -> Option<&str> {
    if bytes.len() <= 1 {
        return Some("");
    }
    let body = match bytes.last() {
        Some(0) => &bytes[..bytes.len() - 1],
        _ => bytes,
    };
    core::str::from_utf8(body).ok()
}
