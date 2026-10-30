//! VariableDatabase — every variable type's field config and every row.
//!
//! Layout source: docs/vendor/WolfSave/VariableDatabase.h, Parse at line 281
//! and the nested VariableType::Parse / TypeData::Parse at lines 162 and 56.
//!
//! Two details there are easy to get wrong and both matter:
//!
//! * A row's numbers are read first, all of them, and only then its strings —
//!   not interleaved in field order. The reference implementation then sorts the
//!   fields by id, so the in-memory order differs from the on-disk order.
//! * The field list (m_typeConfig) is stored per type and tells you which ids are
//!   numeric (below 2000) and which are textual (2000 and above). The field
//!   names are not in the save at all; they live in
//!   Data/BasicData/CDataBase.project. This crate deliberately does not read
//!   that file — see docs/SAVE_SPEC.md section 9.
#![allow(clippy::module_name_repetitions)]

use wolf_format::bytes::Reader;
use wolf_format::error::{Error, Result};

use crate::{ensure_fits, mem_data, push_i32, push_mem_data, push_u32, push_u8};

/// One field of one row.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct VariableField {
    /// The field id — the index into the type's config list.
    pub id: u32,
    /// The value.
    pub value: VariableValue,
}

/// A field value: either a number or a MemData<DWORD> string body.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum VariableValue {
    /// An int32 from a field whose config entry is below 2000.
    Number(i32),
    /// A string body from a field whose config entry is 2000 or above.
    String(Vec<u8>),
}

/// One row of a type.
#[derive(Debug, Clone, PartialEq, Eq, Default)]
pub struct VariableRow {
    /// The row index, m_idx in the source.
    pub index: u32,
    /// Every field, sorted by id exactly as the C++ sorts them.
    pub fields: Vec<VariableField>,
}

impl VariableRow {
    /// The numeric value of a field, if it is one.
    #[must_use]
    pub fn number(&self, id: u32) -> Option<i32> {
        self.fields
            .iter()
            .find(|f| f.id == id)
            .and_then(|f| match f.value {
                VariableValue::Number(n) => Some(n),
                VariableValue::String(_) => None,
            })
    }

    /// The string body of a field, if it is one.
    #[must_use]
    pub fn string(&self, id: u32) -> Option<&[u8]> {
        self.fields
            .iter()
            .find(|f| f.id == id)
            .and_then(|f| match &f.value {
                VariableValue::String(s) => Some(s.as_slice()),
                VariableValue::Number(_) => None,
            })
    }
}

/// One variable type.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct VariableType {
    /// m_unknown — the first word, which doubles as the field count when positive.
    pub unknown: i32,
    /// m_dis — only read when m_unknown is -2 or lower. 0 means this type has no
    /// separate field names, which is why it also decides how rows are labelled.
    pub dis: i32,
    /// m_fieldCount — only set when m_unknown is -1 or lower.
    pub field_count: u32,
    /// m_typeConfig — the per-field config words. Below 2000 means the field is
    /// numeric, 2000 and above means it is textual.
    pub config: Vec<u32>,
    /// m_typeDataCount — the number of rows.
    pub row_count: u32,
    /// The rows.
    pub rows: Vec<VariableRow>,
}

impl VariableType {
    /// How many of the fields are numeric.
    #[must_use]
    pub fn number_field_count(&self) -> usize {
        self.config.iter().filter(|def| **def < 2000).count()
    }

    /// How many of the fields are textual.
    #[must_use]
    pub fn string_field_count(&self) -> usize {
        self.config.iter().filter(|def| **def >= 2000).count()
    }
}

/// The variable database.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct VariableDatabase {
    /// m_unknown — one byte the reference implementation reads and skips. The
    /// source comments on it: "Is here 1 byte just skipped?" It is 0x6F here.
    pub unknown: u8,
    /// m_typeCount — 30 here.
    pub type_count: u32,
    /// The types.
    pub types: Vec<VariableType>,
}

/// Parse a bare VariableDatabase segment (the sixth chunk of a save file).
///
/// The save-file path goes through [SaveFile::parse](crate::SaveFile::parse);
/// this entry point exists so a segment can be tested and round-tripped on its
/// own, which is what `tests/rebuild.rs` does with the synthetic database.
pub fn parse_bytes(bytes: &[u8]) -> Result<VariableDatabase> {
    let mut r = Reader::new(bytes);
    let database = parse(&mut r)?;
    r.expect_end()?;
    Ok(database)
}

pub(crate) fn parse(r: &mut Reader<'_>) -> Result<VariableDatabase> {
    let unknown = r.u8()?;
    let type_count = r.u32()?;
    // A type costs at least 8 bytes: its first word and the row count.
    ensure_fits(r, type_count as usize, 8, "VariableDatabase types")?;
    let mut types = Vec::with_capacity(type_count as usize);
    for _ in 0..type_count {
        types.push(VariableType::parse(r)?);
    }
    Ok(VariableDatabase {
        unknown,
        type_count,
        types,
    })
}

impl VariableType {
    pub(crate) fn parse(r: &mut Reader<'_>) -> Result<VariableType> {
        let unknown = r.i32()?;
        let mut dis = 0;
        let mut field_count = 0;
        let mut count = unknown;
        if unknown <= -1 {
            if unknown <= -2 {
                dis = r.i32()?;
            }
            let pos = r.pos();
            field_count = r.u32()?;
            if field_count > i32::MAX as u32 {
                return Err(wolf_format::error::Error::field(
                    "VariableType field count",
                    pos,
                    format!("{field_count} fields does not fit in an int32"),
                ));
            }
            count = field_count as i32;
        }

        let mut config = Vec::new();
        if count > 0 {
            ensure_fits(r, count as usize, 4, "VariableType config")?;
            config = Vec::with_capacity(count as usize);
            for _ in 0..count {
                config.push(r.u32()?);
            }
        }

        let row_count = r.u32()?;
        // Every row costs at least one number per numeric field.
        let numeric = config.iter().filter(|def| **def < 2000).count();
        ensure_fits(r, row_count as usize, numeric * 4, "VariableType rows")?;
        let mut rows = Vec::with_capacity(row_count as usize);
        for index in 0..row_count {
            rows.push(VariableRow::parse(r, &config, index)?);
        }

        Ok(VariableType {
            unknown,
            dis,
            field_count,
            config,
            row_count,
            rows,
        })
    }
}

impl VariableRow {
    fn parse(r: &mut Reader<'_>, config: &[u32], index: u32) -> Result<VariableRow> {
        let mut fields = Vec::with_capacity(config.len());

        // First pass: every numeric field, in config order.
        for (id, def) in config.iter().enumerate() {
            if *def < 2000 {
                fields.push(VariableField {
                    id: id as u32,
                    value: VariableValue::Number(r.i32()?),
                });
            }
        }

        // Second pass: every textual field, in config order.
        for (id, def) in config.iter().enumerate() {
            if *def >= 2000 {
                fields.push(VariableField {
                    id: id as u32,
                    value: VariableValue::String(mem_data(r, 4)?),
                });
            }
        }

        // The C++ sorts by id, which merges the two passes back into field order.
        fields.sort_by_key(|field| field.id);

        Ok(VariableRow { index, fields })
    }
}

/// Convenience for callers that only want to know how a type is shaped.
impl std::fmt::Display for VariableType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "type(unknown={}, dis={}, fields={}, rows={}, {}+{})",
            self.unknown,
            self.dis,
            self.config.len(),
            self.row_count,
            self.number_field_count(),
            self.string_field_count()
        )
    }
}

// ---- VariableDatabase writer ------------------------------------------

impl VariableType {
    /// Encode one type exactly the way [VariableType::parse] reads it.
    ///
    /// `m_unknown` doubles as the field count when it is positive; when it is
    /// -1 or lower the real count lives in `m_fieldCount`, and `m_dis` is
    /// only present at -2 or lower. Every retail save here stores -2, which is
    /// why the four fields below all round-trip, but the other two shapes are
    /// written too so a hand-built database encodes like the game writes it.
    pub fn to_bytes(&self) -> Result<Vec<u8>> {
        let mut out = Vec::with_capacity(8 + self.config.len() * 4 + self.rows.len() * 8);
        push_i32(&mut out, self.unknown);
        if self.unknown <= -1 {
            if self.unknown <= -2 {
                push_i32(&mut out, self.dis);
            }
            push_u32(&mut out, self.field_count);
        }
        for def in &self.config {
            push_u32(&mut out, *def);
        }
        push_u32(&mut out, self.row_count);
        if self.rows.len() != self.row_count as usize {
            return Err(Error::field(
                "VariableType rows",
                out.len(),
                format!(
                    "m_typeDataCount says {} row(s) but {} were stored",
                    self.row_count,
                    self.rows.len()
                ),
            ));
        }
        for (index, row) in self.rows.iter().enumerate() {
            if row.index as usize != index {
                return Err(Error::field(
                    "VariableType row index",
                    out.len(),
                    format!("row {index} claims to be row {}", row.index),
                ));
            }
            row.to_bytes(&mut out, &self.config)?;
        }
        Ok(out)
    }
}

impl VariableRow {
    /// One row: every numeric field in config order, then every textual one.
    ///
    /// [VariableRow::parse] sorts the two passes back together by id, so the
    /// in-memory order is field order while the on-disk order is kind order.
    /// This function therefore walks `config`, not `fields`.
    pub fn to_bytes(&self, out: &mut Vec<u8>, config: &[u32]) -> Result<()> {
        let mut seen = vec![false; config.len()];
        for (id, def) in config.iter().enumerate() {
            if *def < 2000 {
                match self.number(id as u32) {
                    Some(value) => push_i32(out, value),
                    None => {
                        return Err(Error::field(
                            "VariableRow number",
                            out.len(),
                            format!("row {} is missing numeric field {id}", self.index),
                        ))
                    }
                }
                seen[id] = true;
            }
        }
        for (id, def) in config.iter().enumerate() {
            if *def >= 2000 {
                match self.string(id as u32) {
                    Some(body) => push_mem_data(out, body, 4)?,
                    None => {
                        return Err(Error::field(
                            "VariableRow string",
                            out.len(),
                            format!("row {} is missing textual field {id}", self.index),
                        ))
                    }
                }
                seen[id] = true;
            }
        }
        // A field id that the config does not know would be dropped silently by
        // the loop above; refuse instead, so a hand-edited row cannot write a
        // file that parses back with fewer fields than it started with.
        for field in &self.fields {
            let id = field.id as usize;
            if id >= config.len() || !seen[id] {
                return Err(Error::field(
                    "VariableRow field",
                    out.len(),
                    format!(
                        "row {} holds field id {id}, which is not a numeric or textual entry of this type's {} field config",
                        self.index,
                        config.len()
                    ),
                ));
            }
        }
        Ok(())
    }
}

impl VariableDatabase {
    /// Encode the whole segment exactly the way [vardb::parse] reads it.
    ///
    /// The nine retail saves re-encode to their original bytes (see
    /// `tests/rebuild.rs`), which is the proof this mirrors the game.
    pub fn to_bytes(&self) -> Result<Vec<u8>> {
        let mut out = Vec::with_capacity(5 + self.types.len() * 8);
        push_u8(&mut out, self.unknown);
        push_u32(&mut out, self.type_count);
        if self.types.len() != self.type_count as usize {
            return Err(Error::field(
                "VariableDatabase types",
                out.len(),
                format!(
                    "m_typeCount says {} type(s) but {} were stored",
                    self.type_count,
                    self.types.len()
                ),
            ));
        }
        for kind in &self.types {
            out.extend_from_slice(&kind.to_bytes()?);
        }
        Ok(out)
    }

    /// One type, or None when the index is past the end.
    #[must_use]
    pub fn type_of(&self, type_index: usize) -> Option<&VariableType> {
        self.types.get(type_index)
    }

    /// One row of one type.
    #[must_use]
    pub fn row(&self, type_index: usize, row_index: usize) -> Option<&VariableRow> {
        self.types.get(type_index)?.rows.get(row_index)
    }

    /// The numeric value of one cell, or None when it is out of range, the field
    /// is textual, or the field id is absent.
    #[must_use]
    pub fn number(&self, type_index: usize, row_index: usize, field_index: usize) -> Option<i32> {
        self.row(type_index, row_index)?
            .number(u32::try_from(field_index).ok()?)
    }

    /// The string body of one cell, with the same None rules as
    /// [VariableDatabase::number].
    #[must_use]
    pub fn string(&self, type_index: usize, row_index: usize, field_index: usize) -> Option<&[u8]> {
        self.row(type_index, row_index)?
            .string(u32::try_from(field_index).ok()?)
    }

    /// The string body of one cell decoded the way the game shows it.
    #[must_use]
    pub fn text(&self, type_index: usize, row_index: usize, field_index: usize) -> Option<String> {
        self.string(type_index, row_index, field_index)
            .map(crate::mem_string)
    }

    /// Whether the config entry for this field says "numeric".
    #[must_use]
    pub fn is_number_field(&self, type_index: usize, field_index: usize) -> Option<bool> {
        self.type_of(type_index)?
            .config
            .get(field_index)
            .map(|def| *def < 2000)
    }

    /// Write one numeric cell, adding the field when the id is absent.
    ///
    /// Returns false (and changes nothing) when the type, the row or the field
    /// id does not exist, or when the field is textual -- a wrong-kind write
    /// would be silently dropped by [VariableDatabase::to_bytes], so it is
    /// refused here instead.
    pub fn set_num(
        &mut self,
        type_index: usize,
        row_index: usize,
        field_index: usize,
        value: i32,
    ) -> bool {
        let Some(config_def) = self
            .types
            .get(type_index)
            .and_then(|kind| kind.config.get(field_index))
        else {
            return false;
        };
        if *config_def >= 2000 {
            return false;
        }
        let Some(kind) = self.types.get_mut(type_index) else {
            return false;
        };
        let Some(row) = kind.rows.get_mut(row_index) else {
            return false;
        };
        row.put_field(field_index as u32, VariableValue::Number(value));
        true
    }

    /// Write one textual cell, adding the field when the id is absent.
    ///
    /// The body is stored verbatim, NUL terminator included -- pass the bytes
    /// the game stores, not a bare string. Use [VariableDatabase::set_text] for
    /// the common case where the caller has a &str.
    pub fn set_string(
        &mut self,
        type_index: usize,
        row_index: usize,
        field_index: usize,
        body: &[u8],
    ) -> bool {
        let Some(config_def) = self
            .types
            .get(type_index)
            .and_then(|kind| kind.config.get(field_index))
        else {
            return false;
        };
        if *config_def < 2000 {
            return false;
        }
        let Some(kind) = self.types.get_mut(type_index) else {
            return false;
        };
        let Some(row) = kind.rows.get_mut(row_index) else {
            return false;
        };
        row.put_field(field_index as u32, VariableValue::String(body.to_vec()));
        true
    }

    /// Write one textual cell from a &str, appending the NUL the game stores.
    pub fn set_text(
        &mut self,
        type_index: usize,
        row_index: usize,
        field_index: usize,
        text: &str,
    ) -> bool {
        let mut body = text.as_bytes().to_vec();
        body.push(0);
        self.set_string(type_index, row_index, field_index, &body)
    }
}

impl VariableRow {
    /// Replace the field with this id, or insert it keeping the id order.
    fn put_field(&mut self, id: u32, value: VariableValue) {
        match self.fields.iter().position(|field| field.id == id) {
            Some(at) => self.fields[at].value = value,
            None => {
                let at = self
                    .fields
                    .iter()
                    .position(|field| field.id > id)
                    .unwrap_or(self.fields.len());
                self.fields.insert(at, VariableField { id, value });
            }
        }
    }
}
