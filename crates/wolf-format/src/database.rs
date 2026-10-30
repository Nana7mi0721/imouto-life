//! `DataBase.dat` / `CDataBase.dat` / `SysDatabase.dat` loaders.
//!
//! Layout is documented in `docs/FORMAT_SPEC.md` §6. Every `.dat` is a container
//! with a type list; each type declares how many fields it has and where each
//! field lives, then stores its rows. The field table is the only description of
//! the row shape, and it is positional: a raw value below `1000` means "field
//! absent", `1000..2000` selects numeric column `raw - 1000` and `>= 2000`
//! selects string column `raw - 2000` (WolfTL `Database.hpp` §Field::IsString).
//!
//! A row is stored as *all* numeric values first, then *all* strings — not
//! interleaved — so a row is read into two cursors and the field table decides
//! which cursor advances. Values are kept in the on-disk column order
//! ([`Row::numbers`] / [`Row::strings`]) and the field table is what maps them
//! back to logical columns.

use crate::bytes::Reader;
use crate::error::{Error, Result};

/// A parsed database file.
#[derive(Debug, Clone)]
pub struct Database {
    /// Container version byte, `0xC2` in this game.
    pub version: u8,
    /// Types in file order; index 0 is the game's first data type.
    pub types: Vec<DatabaseType>,
    /// Footer byte, `0xC2`.
    pub footer: u8,
    /// Editor names from the `.project` companion; empty until
    /// [`Database::apply_project_names`] has been called, because the `.dat`
    /// itself carries no label at all.
    pub names: ProjectNames,
}

impl Database {
    /// Container magic: `00 57 00 00 4F 4C`.
    pub const MAGIC: [u8; 6] = [0x00, 0x57, 0x00, 0x00, 0x4F, 0x4C];
    /// Container type magic: `FM\0`.
    pub const MAGIC_TYPE: [u8; 3] = [0x46, 0x4D, 0x00];
    /// Container version this loader implements (`0xC4` is the packed variant).
    pub const VERSION: u8 = 0xC2;
    /// Footer byte.
    pub const FOOTER: u8 = 0xC2;
    /// Per-type sub-header, `FE FF FF FF`.
    pub const TYPE_SEPARATOR: [u8; 4] = [0xFE, 0xFF, 0xFF, 0xFF];
    /// Raw field value at or above this is a string column.
    pub const STRING_START: u32 = 2000;
    /// Raw field value at or above this is a numeric column.
    pub const INT_START: u32 = 1000;
    /// `data_id_method` value that adds an extra name string after the field count.
    pub const STRING_INDICATOR: u32 = 0x0001_D4C0;
    /// Type index of the map settings table in `SysDatabase.dat`.
    pub const MAP_SETTINGS_TYPE: usize = 0;

    /// Parse a whole database file.
    pub fn parse(data: &[u8]) -> Result<Self> {
        let mut r = Reader::new(data);
        r.expect(&Self::MAGIC, "database magic")?;
        let version_header = r.u8()?;
        let generation = crate::generation::WolfGeneration::require_version_header(
            version_header,
            "database version_header",
            r.pos() - 1,
        )?;
        r.expect(&Self::MAGIC_TYPE, "database magic type")?;
        let version = r.u8()?;
        if version != generation.database_version() {
            return Err(Error::field(
                "database version",
                r.pos() - 1,
                format!("unsupported database version 0x{version:02X}"),
            ));
        }
        let type_count = r.u32()? as usize;
        // A type is at least 16 bytes (sub-header, id method, field count, row
        // count), so this bound can never reject a well-formed file and stops a
        // corrupt count from allocating wildly.
        if type_count > r.remaining() / 16 {
            return Err(Error::field(
                "database type count",
                r.pos() - 4,
                format!("{type_count} types do not fit in {} bytes", r.remaining()),
            ));
        }
        let mut types = Vec::with_capacity(type_count);
        for _ in 0..type_count {
            types.push(DatabaseType::read(&mut r)?);
        }
        let footer = r.u8()?;
        let want_footer = generation.database_footer();
        if footer != want_footer {
            return Err(Error::magic(
                "database footer",
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
            version,
            types,
            footer,
            names: ProjectNames::default(),
        })
    }

    /// The map settings table (type 0 of `SysDatabase.dat`).
    ///
    /// This is the only correct source for the registered map list: 9 `.mps`
    /// files ship on disk but only 6 are registered here, and the order is the
    /// one the game uses (not the file order, not the file names).
    pub fn map_settings(&self) -> Vec<MapSetting> {
        let Some(table) = self.types.get(Self::MAP_SETTINGS_TYPE) else {
            return Vec::new();
        };
        table
            .rows
            .iter()
            .filter_map(|row| {
                let path = row.strings.first()?;
                if path.is_empty() {
                    return None;
                }
                Some(MapSetting {
                    path: path.clone(),
                    numbers: row.numbers.clone(),
                    strings: row.strings.clone(),
                })
            })
            .collect()
    }

    /// Read the type, field and row names from the `.project` companion file.
    ///
    /// Every `.dat` is purely positional: it carries field tables and rows but not
    /// a single label. The editor keeps the labels next to it in a `.project`
    /// file with the same base name (`DataBase.project` for `DataBase.dat`,
    /// `CDataBase.project` for `CDataBase.dat`, `SysDatabase.project` for
    /// `SysDatabase.dat`), one self-describing record per type, and the records
    /// are index-aligned with the `.dat` type list — see `docs/FORMAT_SPEC.md`
    /// §6.8 for the measured layout.
    ///
    /// Returns how many types the companion described — `0` when it does not
    /// belong to this database. A type whose editor name is empty still counts
    /// here (17 of the 40 `DataBase.dat` types are unnamed separators); use
    /// [`ProjectNames::named_types`] for how many carry a label.
    ///
    /// A companion whose leading type count differs says nothing, which is what
    /// keeps a `.project` written by another game version — or belonging to a
    /// different database — from mis-labelling a type.
    pub fn apply_project_names(&mut self, project: &[u8]) -> usize {
        self.names = ProjectNames::parse(project, self.types.len());
        self.names.len()
    }

    /// Editor name of type `ty`.
    ///
    /// `None` when the type has no name in the editor (17 of the 40
    /// `DataBase.dat` types are unnamed separators) or when no `.project` was
    /// applied.
    pub fn type_name(&self, ty: usize) -> Option<&str> {
        self.names.type_name(ty)
    }

    /// Editor name of logical column `column` of type `ty`.
    ///
    /// `None` when the companion's field list disagrees with the `.dat` field
    /// table: measured on this game, 8 types of `DataBase.dat` and 2 of
    /// `CDataBase.dat` keep one field in the editor that the exported table no
    /// longer has, and a label must never be attached to a column that is not
    /// there (§6.8).
    pub fn field_name(&self, ty: usize, column: usize) -> Option<&str> {
        let table = self.types.get(ty)?;
        let record = self.names.record(ty)?;
        if record.fields.len() != table.fields.len() {
            return None;
        }
        record.field_name(column)
    }

    /// Editor name of row `row` of type `ty`, when the row counts agree.
    pub fn row_name(&self, ty: usize, row: usize) -> Option<&str> {
        let table = self.types.get(ty)?;
        let record = self.names.record(ty)?;
        if record.rows.len() != table.rows.len() {
            return None;
        }
        record.row_name(row)
    }
}

/// One data type: a field table plus its rows.
#[derive(Debug, Clone)]
pub struct DatabaseType {
    /// How the game derives a row's id, see `docs/FORMAT_SPEC.md` §6.2.
    ///
    /// 0 manual, 1 same as the first field, 2 same as the previous type,
    /// 10000 and up derived by the engine; all of these occur in this game.
    pub data_id_method: u32,
    /// Field table in logical column order.
    pub fields: Vec<FieldKind>,
    /// Rows in file order.
    pub rows: Vec<Row>,
}

impl DatabaseType {
    /// Number of numeric columns the row layout contains.
    ///
    /// Every field below [`Database::STRING_START`] occupies a numeric slot —
    /// including absent fields, whose raw value is below [`Database::INT_START`].
    pub fn numeric_columns(&self) -> usize {
        self.fields
            .iter()
            .filter(|field| !matches!(field, FieldKind::Str(_)))
            .count()
    }

    /// Number of string columns the row layout contains.
    pub fn string_columns(&self) -> usize {
        self.fields
            .iter()
            .filter(|field| matches!(field, FieldKind::Str(_)))
            .count()
    }

    /// Read one logical column of a row, or `None` when the field is absent.
    pub fn value<'a>(&self, row: &'a Row, column: usize) -> Option<RowValue<'a>> {
        match self.fields.get(column)? {
            FieldKind::Num(index) => row.numbers.get(*index).map(|v| RowValue::Num(*v)),
            FieldKind::Str(index) => row.strings.get(*index).map(|v| RowValue::Str(v)),
        }
    }

    fn read(r: &mut Reader<'_>) -> Result<Self> {
        r.expect(&Database::TYPE_SEPARATOR, "database type separator")?;
        let data_id_method = r.u32()?;
        let field_count = r.u32()? as usize;
        if data_id_method == Database::STRING_INDICATOR {
            // Documented extra name string; no shipped file uses it, but skipping
            // it keeps the walk correct if one ever does.
            let _unknown2 = r.t_str()?;
        }
        if field_count > r.remaining() / 4 {
            return Err(Error::field(
                "database field count",
                r.pos() - 4,
                format!("{field_count} fields do not fit in {} bytes", r.remaining()),
            ));
        }
        let positions = r.u32_array(field_count)?;
        let mut fields = Vec::with_capacity(field_count);
        for raw in positions {
            fields.push(FieldKind::decode(raw, r.pos())?);
        }
        let row_count = r.u32()? as usize;
        // The narrowest row is 4 bytes per numeric column plus 4 per string
        // (a zero-length `t_str` still costs its length word). A type with no
        // fields at all stores zero-byte rows — `SysDatabase.dat` type 14 is
        // exactly that: 800 rows of nothing — so only a non-zero row size bounds
        // the count against the remaining bytes.
        let row_bytes = fields.len() * 4;
        let fits = match r.remaining().checked_div(row_bytes) {
            Some(max_rows) => row_count <= max_rows,
            // A type with no fields stores zero-byte rows, so the remaining
            // bytes cannot bound the count; only a sanity limit applies.
            None => row_count <= MAX_EMPTY_ROWS,
        };
        if !fits {
            return Err(Error::field(
                "database row count",
                r.pos() - 4,
                format!("{row_count} rows do not fit in {} bytes", r.remaining()),
            ));
        }
        let mut rows = Vec::with_capacity(row_count);
        for _ in 0..row_count {
            rows.push(Row::read(r, &fields)?);
        }
        Ok(Self {
            data_id_method,
            fields,
            rows,
        })
    }
}

/// Upper bound on rows of a type that has no fields, where every row occupies
/// zero bytes and the remaining-bytes check cannot constrain the count.
const MAX_EMPTY_ROWS: usize = 1_000_000;

/// Number of string columns in a field table.
fn string_columns(fields: &[FieldKind]) -> usize {
    fields
        .iter()
        .filter(|field| matches!(field, FieldKind::Str(_)))
        .count()
}

/// Where one logical column of a row lives.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum FieldKind {
    /// Numeric column `n` of [`Row::numbers`].
    Num(usize),
    /// String column `n` of [`Row::strings`].
    Str(usize),
}

impl FieldKind {
    /// Decode a raw field position word.
    pub fn decode(raw: u32, pos: usize) -> Result<Self> {
        if raw >= Database::STRING_START {
            Ok(Self::Str((raw - Database::STRING_START) as usize))
        } else if raw >= Database::INT_START {
            Ok(Self::Num((raw - Database::INT_START) as usize))
        } else {
            // Absent fields are documented but never occur in this game's three
            // databases, so refuse rather than silently shifting every later column.
            Err(Error::field(
                "database field position",
                pos,
                format!("invalid field position {raw}"),
            ))
        }
    }

    /// The raw position word this field was decoded from.
    pub fn raw(&self) -> u32 {
        match self {
            Self::Num(index) => Database::INT_START + *index as u32,
            Self::Str(index) => Database::STRING_START + *index as u32,
        }
    }
}

/// One row: numeric values first, then strings, in on-disk column order.
#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct Row {
    /// Numeric columns in the order they appear in the file.
    pub numbers: Vec<i32>,
    /// String columns in the order they appear in the file.
    pub strings: Vec<String>,
}

impl Row {
    fn read(r: &mut Reader<'_>, fields: &[FieldKind]) -> Result<Self> {
        let strings_count = string_columns(fields);
        let numbers = r.i32_array(fields.len() - strings_count)?;
        let mut strings = Vec::with_capacity(strings_count);
        for _ in 0..strings_count {
            strings.push(r.t_str()?);
        }
        Ok(Self { numbers, strings })
    }

    /// Value of logical column `column`, if the field table points at a slot
    /// that this row actually has.
    pub fn value(&self, fields: &[FieldKind], column: usize) -> Option<RowValue<'_>> {
        match fields.get(column)? {
            FieldKind::Num(index) => self.numbers.get(*index).map(|v| RowValue::Num(*v)),
            FieldKind::Str(index) => self.strings.get(*index).map(|v| RowValue::Str(v)),
        }
    }
}

/// A single cell, borrowed from a [`Row`].
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum RowValue<'a> {
    /// A numeric cell.
    Num(i32),
    /// A string cell.
    Str(&'a str),
}

/// One row of the map settings table, see [`Database::map_settings`].
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct MapSetting {
    /// `.mps` path relative to the game root, e.g. `MapData/TitleMap.mps`.
    pub path: String,
    /// Numeric columns in on-disk order.
    pub numbers: Vec<i32>,
    /// String columns in on-disk order; column 0 is [`Self::path`].
    pub strings: Vec<String>,
}

/// Editor labels read from a `.project` companion file.
///
/// The `.dat` files describe the *shape* of a database and carry no names at
/// all, so a database read cannot resolve the type and field labels that
/// `docs/OPCODE_250.md` uses as its most reliable key (`stringArgs[1]` = type
/// label, `stringArgs[3]` = field label) without this companion. The layout is in
/// `docs/FORMAT_SPEC.md` §6.8.
///
/// The record walk is exact rather than heuristic: every record ends with four
/// editor-metadata blocks (field notes, string args, numeric args, defaults) and
/// following them lands exactly on the end of the file for all three companions
/// shipped with this game (35972, 174721 and 170977 bytes).
#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct ProjectNames {
    /// One record per type, in `.dat` order.
    types: Vec<ProjectTypeNames>,
}

impl ProjectNames {
    /// Longest name accepted from a `.project` file, in bytes.
    ///
    /// Field and row names are short; only the type description runs to a few
    /// hundred bytes. The bound stops a corrupt length word from being followed.
    pub const MAX_NAME_BYTES: usize = 4096;

    /// Read the names of a `.project` file belonging to a database with
    /// `type_count` types.
    ///
    /// The leading word must equal `type_count`, otherwise nothing is named: a
    /// companion from another game version names no type rather than the wrong
    /// one. Records are then walked in order, and a record that does not parse
    /// stops the walk and leaves every later type unnamed.
    pub fn parse(project: &[u8], type_count: usize) -> Self {
        if u32_at(project, 0) != Some(type_count as u32) {
            return Self::default();
        }
        let mut types = Vec::with_capacity(type_count);
        let mut at = 4usize;
        for _ in 0..type_count {
            let Some((record, end)) = project_type_at(project, at) else {
                break;
            };
            types.push(record);
            at = end;
        }
        Self { types }
    }

    /// Record of type `ty`, or `None` when the companion did not reach that far.
    pub fn record(&self, ty: usize) -> Option<&ProjectTypeNames> {
        self.types.get(ty)
    }

    /// Every record, in `.dat` type order.
    pub fn iter(&self) -> impl Iterator<Item = &ProjectTypeNames> {
        self.types.iter()
    }

    /// How many types the companion described.
    pub fn len(&self) -> usize {
        self.types.len()
    }

    /// Whether the companion described no type at all.
    pub fn is_empty(&self) -> bool {
        self.types.is_empty()
    }

    /// Editor name of type `ty`; `None` when it is empty or absent.
    pub fn type_name(&self, ty: usize) -> Option<&str> {
        self.record(ty)?.name()
    }

    /// Editor name of logical column `column` of type `ty`.
    pub fn field_name(&self, ty: usize, column: usize) -> Option<&str> {
        self.record(ty)?.field_name(column)
    }

    /// Editor name of row `row` of type `ty`.
    pub fn row_name(&self, ty: usize, row: usize) -> Option<&str> {
        self.record(ty)?.row_name(row)
    }

    /// How many types carry a non-empty name.
    pub fn named_types(&self) -> usize {
        self.types
            .iter()
            .filter(|record| record.name().is_some())
            .count()
    }

    /// How many field names the companion carries over all types.
    pub fn named_fields(&self) -> usize {
        self.types.iter().map(|record| record.fields.len()).sum()
    }

    /// How many row names the companion carries over all types.
    pub fn named_rows(&self) -> usize {
        self.types.iter().map(|record| record.rows.len()).sum()
    }
}

/// One type record of a `.project` file: the editor's labels for a `.dat` type.
#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct ProjectTypeNames {
    /// Editor name of the type, e.g. `技能` or `マップ設定`.
    pub name: String,
    /// Editor name per field, parallel to the `.dat` field table.
    pub fields: Vec<String>,
    /// Editor name per row, parallel to the `.dat` rows.
    pub rows: Vec<String>,
}

impl ProjectTypeNames {
    /// Editor name of the type; `None` when the editor left it empty.
    pub fn name(&self) -> Option<&str> {
        non_empty(&self.name)
    }

    /// Editor name of field `column`.
    pub fn field_name(&self, column: usize) -> Option<&str> {
        self.fields.get(column).and_then(|name| non_empty(name))
    }

    /// Editor name of row `row`.
    pub fn row_name(&self, row: usize) -> Option<&str> {
        self.rows.get(row).and_then(|name| non_empty(name))
    }
}

/// `Some(name)` unless the editor left the name empty.
fn non_empty(name: &str) -> Option<&str> {
    if name.is_empty() {
        None
    } else {
        Some(name)
    }
}

/// Little-endian `u32` at `at`.
fn u32_at(data: &[u8], at: usize) -> Option<u32> {
    let bytes = data.get(at..at + 4)?;
    Some(u32::from_le_bytes([bytes[0], bytes[1], bytes[2], bytes[3]]))
}

/// Read one `.project` string at `at`: a `u32` byte count *including* the NUL
/// terminator, then that many bytes.
///
/// This is the same `t_str` the `.dat` files use, except that the editor writes
/// UTF-8 here, so bytes that are not valid UTF-8 mean this offset is not a name.
fn name_at(data: &[u8], at: usize) -> Option<(String, usize)> {
    let len = u32_at(data, at)? as usize;
    if len == 0 || len > ProjectNames::MAX_NAME_BYTES {
        return None;
    }
    let start = at + 4;
    let raw = data.get(start..start + len)?;
    let (terminator, text) = raw.split_last()?;
    if *terminator != 0 {
        return None;
    }
    Some((decode_project_name(text), start + len))
}

/// Decode one .project name.
///
/// WOLF RPG Editor 2.10 writes these strings as UTF-8, but the 2.00 line (this
/// game) writes them in the editor code page, CP932. Try UTF-8 first so a 2.10
/// companion names correctly, then fall back to CP932. A Japanese CP932 byte
/// pair is never valid UTF-8, so the two encodings cannot be confused for a name
/// that actually contains text.
fn decode_project_name(text: &[u8]) -> String {
    match std::str::from_utf8(text) {
        Ok(name) => name.to_owned(),
        Err(_) => crate::dxarchive::decode_cp932(text),
    }
}

/// Read one whole type record at `at`, returning it with the offset just past it.
///
/// A record is the `.dat` type tuple plus the editor's metadata (§6.8): the type
/// name, the field names, the row names, a description, one type code per field,
/// then the four trailing blocks. The blocks are unnamed editor metadata, but
/// they cannot be skipped — their lengths are what make the next record land
/// where it does.
fn project_type_at(project: &[u8], at: usize) -> Option<(ProjectTypeNames, usize)> {
    let (name, mut offset) = name_at(project, at)?;
    let field_count = u32_at(project, offset)? as usize;
    offset += 4;
    // A field name is at least 5 bytes (length word plus terminator), so a count
    // larger than the file cannot be honest; the bound only stops a wild
    // allocation from a corrupt word.
    if field_count > project.len() / 5 {
        return None;
    }
    let mut fields = Vec::with_capacity(field_count);
    for _ in 0..field_count {
        let (field, next) = name_at(project, offset)?;
        fields.push(field.to_owned());
        offset = next;
    }
    let row_count = u32_at(project, offset)? as usize;
    offset += 4;
    if row_count > project.len() / 5 {
        return None;
    }
    let mut rows = Vec::with_capacity(row_count);
    for _ in 0..row_count {
        let (row, next) = name_at(project, offset)?;
        rows.push(row.to_owned());
        offset = next;
    }
    // Description (the editor's help text; unused here, but it is a t_str and
    // has to be stepped over).
    offset = name_at(project, offset)?.1;
    // Field type codes: a byte count, then that many bytes.
    let type_bytes = u32_at(project, offset)? as usize;
    offset = offset.checked_add(4)?.checked_add(type_bytes)?;
    if offset > project.len() {
        return None;
    }
    // Block 1: one note per field.
    let notes = u32_at(project, offset)? as usize;
    offset += 4;
    for _ in 0..notes {
        offset = name_at(project, offset)?.1;
    }
    // Block 2: per field, a list of string arguments.
    let entries = u32_at(project, offset)? as usize;
    offset += 4;
    for _ in 0..entries {
        let arguments = u32_at(project, offset)? as usize;
        offset += 4;
        for _ in 0..arguments {
            offset = name_at(project, offset)?.1;
        }
    }
    // Block 3: per field, a list of numeric arguments.
    let entries = u32_at(project, offset)? as usize;
    offset += 4;
    for _ in 0..entries {
        let arguments = u32_at(project, offset)? as usize;
        offset = offset
            .checked_add(4)?
            .checked_add(arguments.checked_mul(4)?)?;
        if offset > project.len() {
            return None;
        }
    }
    // Block 4: one default value per field.
    let defaults = u32_at(project, offset)? as usize;
    offset = offset
        .checked_add(4)?
        .checked_add(defaults.checked_mul(4)?)?;
    if offset > project.len() {
        return None;
    }
    Some((
        ProjectTypeNames {
            name: name.to_owned(),
            fields,
            rows,
        },
        offset,
    ))
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn container_constants_match_the_spec() {
        assert_eq!(Database::MAGIC, [0x00, 0x57, 0x00, 0x00, 0x4F, 0x4C]);
        assert_eq!(Database::MAGIC_TYPE, *b"FM\0");
        assert_eq!(Database::VERSION, 0xC2);
        assert_eq!(Database::FOOTER, 0xC2);
        assert_eq!(Database::TYPE_SEPARATOR, [0xFE, 0xFF, 0xFF, 0xFF]);
        assert_eq!(Database::STRING_START, 2000);
        assert_eq!(Database::INT_START, 1000);
        assert_eq!(Database::STRING_INDICATOR, 0x0001_D4C0);
    }

    #[test]
    fn field_kind_decodes_the_two_column_spaces() {
        assert_eq!(FieldKind::decode(2000, 0), Ok(FieldKind::Str(0)));
        assert_eq!(FieldKind::decode(2004, 0), Ok(FieldKind::Str(4)));
        assert_eq!(FieldKind::decode(1000, 0), Ok(FieldKind::Num(0)));
        assert_eq!(FieldKind::decode(1013, 0), Ok(FieldKind::Num(13)));
        assert!(FieldKind::decode(999, 0).is_err());
        assert_eq!(FieldKind::Str(2).raw(), 2002);
        assert_eq!(FieldKind::Num(2).raw(), 1002);
    }

    #[test]
    fn row_value_walks_the_field_table() {
        let fields = [FieldKind::Str(0), FieldKind::Num(0), FieldKind::Str(1)];
        let row = Row {
            numbers: vec![7],
            strings: vec!["a".into(), "b".into()],
        };
        assert_eq!(row.value(&fields, 0), Some(RowValue::Str("a")));
        assert_eq!(row.value(&fields, 1), Some(RowValue::Num(7)));
        assert_eq!(row.value(&fields, 2), Some(RowValue::Str("b")));
        assert_eq!(row.value(&fields, 3), None);
        assert_eq!(
            row.value(&[FieldKind::Num(9)], 0),
            None,
            "a field table pointing past the row must not panic"
        );
    }
}
