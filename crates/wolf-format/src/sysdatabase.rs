//! `SysDatabase.dat` loader: the engine's fixed system tables.
//!
//! `SysDatabase.dat` uses the same container as `DataBase.dat` (§6): a type list
//! whose field tables describe the row shape. What makes it special is that the
//! *meaning* of every type and row is fixed by the engine rather than declared
//! in the file: type 12 is always the 30-entry colour palette, type 6 is always
//! the 150 system variables, type 0 is the map list, and so on.
//!
//! The container itself stores no names at all. The editor keeps those in the
//! `SysDatabase.project` companion next to it, and
//! [`SysDatabase::apply_project_names`] reads them from there; without that file a
//! [`SysDatabase`] is complete except for type and row names.
//!
//! Row shapes are engine-fixed too, and several tables carry no fields at all
//! (types 4, 5, 6 and 14..=23 are name-only slots whose rows are zero bytes):
//! `docs/FORMAT_SPEC.md` §6.6 records the measured shapes. Because the engine
//! indexes tables by slot number, the accessors here are positional —
//! [`SysDatabase::num`] and [`SysDatabase::text`] take a *logical* column (the one
//! the editor shows), not a physical slot in [`Row::numbers`] / [`Row::strings`].

use crate::database::{Database, FieldKind, ProjectNames, Row, RowValue};
use crate::error::Result;

/// A parsed `SysDatabase.dat` plus the names from its `.project` companion.
#[derive(Debug, Clone)]
pub struct SysDatabase {
    /// Container version byte, `0xC2` in this game.
    pub version: u8,
    /// Types in file order. The order is part of the format: the engine looks
    /// tables up by index, so it must never be sorted.
    pub types: Vec<SysType>,
    /// Footer byte, `0xC2`.
    pub footer: u8,
}

impl SysDatabase {
    /// Type index of the map list (マップ設定), the only correct source for the
    /// registered `.mps` list.
    pub const MAP_SETTINGS_TYPE: usize = Database::MAP_SETTINGS_TYPE;
    /// Type index of the 150 system variables.
    pub const SYSTEM_VARIABLE_TYPE: usize = 6;
    /// Type index of the colour palette, see [`Self::colour`].
    pub const COLOUR_TYPE: usize = 12;
    /// Type index of the face graphic list (顔グラフィック名).
    pub const FACE_GRAPHIC_TYPE: usize = 24;

    /// Parse a whole `SysDatabase.dat`.
    ///
    /// The container framing, field tables and rows are identical to the other
    /// databases, so this reuses [`Database::parse`] instead of duplicating the
    /// walk; only the per-type names are added, and they come from the
    /// `.project` companion (see [`Self::apply_project_names`]).
    pub fn parse(data: &[u8]) -> Result<Self> {
        let database = Database::parse(data)?;
        let types = database
            .types
            .into_iter()
            .map(|database_type| SysType {
                name: String::new(),
                fields: database_type.fields,
                field_names: Vec::new(),
                rows: database_type.rows,
                row_names: Vec::new(),
            })
            .collect();
        Ok(Self {
            version: database.version,
            types,
            footer: database.footer,
        })
    }

    /// The type tables, in file order.
    pub fn types(&self) -> &[SysType] {
        &self.types
    }

    /// Number of rows in type `ty`, or `0` when there is no such type.
    pub fn row_count(&self, ty: usize) -> usize {
        self.types.get(ty).map_or(0, |table| table.rows.len())
    }

    /// Editor name of row `row` in type `ty`.
    ///
    /// `None` when the type or row does not exist *or* when the `.project`
    /// companion was not loaded — the container itself has no row names.
    pub fn name_of(&self, ty: usize, row: usize) -> Option<&str> {
        self.types.get(ty)?.row_name(row)
    }

    /// Editor name of logical column `column` in type `ty`.
    ///
    /// `None` when the type or column does not exist, when the `.project`
    /// companion was not loaded, or when the companion's field list disagrees
    /// with the table's field count (a label must never be attached to a column
    /// that is not there).
    pub fn field_name(&self, ty: usize, column: usize) -> Option<&str> {
        self.types.get(ty)?.field_name(column)
    }

    /// Numeric cell in logical column `col` of row `row`, widened to `i64`.
    ///
    /// `None` when the indexes are out of range or when the field table says
    /// that column is a string.
    pub fn num(&self, ty: usize, row: usize, col: usize) -> Option<i64> {
        match self.types.get(ty)?.value(row, col)? {
            RowValue::Num(value) => Some(i64::from(value)),
            RowValue::Str(_) => None,
        }
    }

    /// String cell in logical column `col` of row `row`.
    ///
    /// `None` when the indexes are out of range or when the field table says
    /// that column is numeric.
    pub fn text(&self, ty: usize, row: usize, col: usize) -> Option<&str> {
        match self.types.get(ty)?.value(row, col)? {
            RowValue::Str(value) => Some(value),
            RowValue::Num(_) => None,
        }
    }

    /// Palette entry `index` of type 12 (文字色) as `[red, green, blue]`.
    ///
    /// The table has exactly three numeric columns per row (§6.6) and the editor
    /// writes `0..=255`; anything outside that range is clamped rather than
    /// scaled, because that is what the engine's renderer does with it.
    pub fn colour(&self, index: usize) -> Option<[u8; 3]> {
        let table = self.types.get(Self::COLOUR_TYPE)?;
        let channel = |column: usize| -> Option<u8> {
            match table.value(index, column)? {
                RowValue::Num(value) => Some(value.clamp(0, 255) as u8),
                RowValue::Str(_) => None,
            }
        };
        Some([channel(0)?, channel(1)?, channel(2)?])
    }

    /// Read type, field and row names from the editor's `SysDatabase.project`
    /// companion.
    ///
    /// The `.dat` carries no labels at all; the editor keeps them in the
    /// `.project` file next to it, one self-describing record per type, and the
    /// records are index-aligned with this database's type list. The record walk
    /// lives in [`ProjectNames`] and is exact: it follows each record's four
    /// editor-metadata blocks and lands on the end of the file, so no scanning is
    /// needed (see `docs/FORMAT_SPEC.md` §6.8).
    ///
    /// Labels are attached per shape: the type name always, the field names only
    /// when the companion's field count matches the table, the row names only
    /// when the row count does. A companion from a different game version fails
    /// the leading type count and names nothing.
    ///
    /// Returns how many types the companion described — `0` when it does not
    /// belong to this database — counting a type whose editor name is empty
    /// (types 25..=27 of this game) as described too.
    pub fn apply_project_names(&mut self, project: &[u8]) -> usize {
        let names = ProjectNames::parse(project, self.types.len());
        let mut filled = 0;
        for (table, record) in self.types.iter_mut().zip(names.iter()) {
            table.name.clone_from(&record.name);
            if record.fields.len() == table.fields.len() {
                table.field_names.clone_from(&record.fields);
            }
            if record.rows.len() == table.rows.len() {
                table.row_names.clone_from(&record.rows);
            }
            filled += 1;
        }
        filled
    }
}

/// One data type of `SysDatabase.dat`.
#[derive(Debug, Clone)]
pub struct SysType {
    /// Editor name of the type, e.g. `マップ設定`; empty until
    /// [`SysDatabase::apply_project_names`] runs.
    pub name: String,
    /// Field table in logical column order.
    pub fields: Vec<FieldKind>,
    /// Editor name per field, parallel to [`Self::fields`]; empty until
    /// [`SysDatabase::apply_project_names`] runs.
    pub field_names: Vec<String>,
    /// Rows in file order; the engine indexes them by slot number.
    pub rows: Vec<Row>,
    /// Editor name per row, parallel to [`Self::rows`]; empty until
    /// [`SysDatabase::apply_project_names`] runs.
    pub row_names: Vec<String>,
}

impl SysType {
    /// Numeric slots a row of this type carries.
    ///
    /// Every field below [`Database::STRING_START`] occupies a numeric slot,
    /// including absent fields, exactly like [`crate::database::DatabaseType`].
    pub fn numeric_columns(&self) -> usize {
        self.fields
            .iter()
            .filter(|field| !matches!(field, FieldKind::Str(_)))
            .count()
    }

    /// String slots a row of this type carries.
    pub fn string_columns(&self) -> usize {
        self.fields
            .iter()
            .filter(|field| matches!(field, FieldKind::Str(_)))
            .count()
    }

    /// Value of logical column `column` in row `row`.
    pub fn value(&self, row: usize, column: usize) -> Option<RowValue<'_>> {
        self.rows.get(row)?.value(&self.fields, column)
    }

    /// Editor name of `row`, once the `.project` names were applied.
    pub fn row_name(&self, row: usize) -> Option<&str> {
        self.row_names.get(row).map(String::as_str)
    }

    /// Editor name of logical column `column`, once the `.project` names were
    /// applied.
    pub fn field_name(&self, column: usize) -> Option<&str> {
        self.field_names.get(column).map(String::as_str)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::PathBuf;

    /// Data root, resolved the way the integration tests do it: `$WOLF_DATA_ROOT`
    /// when set, otherwise `work/full` relative to the workspace root.
    fn data_root() -> Option<PathBuf> {
        let raw = match std::env::var("WOLF_DATA_ROOT") {
            Ok(value) if !value.is_empty() => PathBuf::from(value),
            _ => PathBuf::from("work/full"),
        };
        let root = if raw.is_absolute() {
            raw
        } else {
            let manifest = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
            let workspace = manifest
                .parent()
                .and_then(|crates| crates.parent())
                .unwrap_or(&manifest)
                .to_path_buf();
            let candidate = workspace.join(&raw);
            if candidate.is_dir() {
                candidate
            } else {
                raw
            }
        };
        root.is_dir().then_some(root)
    }

    /// A file from `BasicData/`, or `None` when the data tree is absent.
    fn load(name: &str) -> Option<Vec<u8>> {
        std::fs::read(data_root()?.join("BasicData").join(name)).ok()
    }

    fn skip(name: &str) {
        let root =
            data_root().map_or_else(|| "<none>".to_owned(), |root| root.display().to_string());
        eprintln!("skipping {name}: no data under {root}");
    }

    /// A tiny hand-built database, for the accessors that must not need a file.
    fn sample() -> SysDatabase {
        SysDatabase {
            version: Database::VERSION,
            types: vec![SysType {
                name: "種別".to_owned(),
                fields: vec![FieldKind::Str(0), FieldKind::Num(0), FieldKind::Num(1)],
                field_names: vec!["文字列".to_owned(), "数値".to_owned(), "個数".to_owned()],
                rows: vec![Row {
                    numbers: vec![7, 300],
                    strings: vec!["文字".to_owned()],
                }],
                row_names: vec!["行".to_owned()],
            }],
            footer: Database::FOOTER,
        }
    }

    #[test]
    fn accessors_follow_the_field_table() {
        let database = sample();
        assert_eq!(database.types().len(), 1);
        assert_eq!(database.row_count(0), 1);
        assert_eq!(database.row_count(1), 0, "missing type has no rows");
        assert_eq!(database.name_of(0, 0), Some("行"));
        assert_eq!(database.name_of(0, 1), None);
        assert_eq!(database.name_of(1, 0), None);

        assert_eq!(database.text(0, 0, 0), Some("文字"));
        assert_eq!(database.num(0, 0, 0), None, "column 0 is a string field");
        assert_eq!(database.num(0, 0, 1), Some(7));
        assert_eq!(database.num(0, 0, 2), Some(300));
        assert_eq!(database.text(0, 0, 1), None, "column 1 is numeric");
        assert_eq!(database.num(0, 0, 3), None, "no fourth column");
        assert_eq!(database.num(0, 1, 1), None, "no second row");
        assert_eq!(database.num(1, 0, 0), None, "no second type");
        assert_eq!(
            database.colour(0),
            None,
            "type 12 is missing, so there is no palette"
        );
    }

    #[test]
    fn the_container_parses_without_any_names() {
        let Some(data) = load("SysDatabase.dat") else {
            skip("SysDatabase.dat");
            return;
        };
        let database = SysDatabase::parse(&data).expect("SysDatabase.dat parses");
        assert_eq!(database.version, 0xC1, "version");
        assert_eq!(database.footer, 0xC1, "footer");
        assert_eq!(database.types.len(), 28, "type count");
        assert!(
            database.types.iter().all(|table| table.name.is_empty()),
            "the .dat carries no type names"
        );
        assert!(
            database
                .types
                .iter()
                .all(|table| table.row_names.is_empty()),
            "the .dat carries no row names"
        );
        assert_eq!(database.name_of(SysDatabase::SYSTEM_VARIABLE_TYPE, 1), None);
    }

    #[test]
    fn every_type_has_the_measured_shape() {
        let Some(data) = load("SysDatabase.dat") else {
            skip("SysDatabase.dat");
            return;
        };
        let database = SysDatabase::parse(&data).expect("SysDatabase.dat parses");

        let field_counts: [usize; 28] = [
            8, 4, 4, 4, 0, 0, 0, 3, 1, 1, 2, 1, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
        ];
        let row_counts: [usize; 28] = [
            50, 16, 6, 20, 10, 55, 135, 10, 300, 6, 3, 1, 30, 80, 302, 4, 7, 4, 1, 1, 1, 6, 1,
            10, 12, 1, 1, 1,
        ];
        for (index, table) in database.types.iter().enumerate() {
            assert_eq!(
                table.fields.len(),
                field_counts[index],
                "type {index} field count"
            );
            assert_eq!(
                table.rows.len(),
                row_counts[index],
                "type {index} row count"
            );
            // A row must carry exactly the slots its own field table declares.
            for (row_index, row) in table.rows.iter().enumerate() {
                assert_eq!(
                    row.numbers.len(),
                    table.numeric_columns(),
                    "type {index} row {row_index} numeric slots"
                );
                assert_eq!(
                    row.strings.len(),
                    table.string_columns(),
                    "type {index} row {row_index} string slots"
                );
            }
        }
        // The name-only tables are the ones with zero fields.
        for index in [4usize, 5, 6, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23] {
            assert_eq!(
                database.types[index].fields.len(),
                0,
                "type {index} is a name-only table"
            );
        }
    }

    #[test]
    fn the_map_list_is_type_zero() {
        let Some(data) = load("SysDatabase.dat") else {
            skip("SysDatabase.dat");
            return;
        };
        let database = SysDatabase::parse(&data).expect("SysDatabase.dat parses");
        let table = &database.types[SysDatabase::MAP_SETTINGS_TYPE];
        assert_eq!(table.fields.len(), 8, "map settings field count");
        assert_eq!(table.rows.len(), 50, "map settings row count");
        assert_eq!(
            database.text(SysDatabase::MAP_SETTINGS_TYPE, 0, 0),
            Some("MapData/TitleMap.mps"),
            "row 0 path"
        );
        assert_eq!(
            database.text(SysDatabase::MAP_SETTINGS_TYPE, 1, 0),
            Some("MapData/SampleMapA.mps"),
            "row 1 path"
        );
        // Logical columns, not physical slots: 0 is the path string, 1 the BGM
        // number, 2 the BGS number, 3 the loop mode, 4 the scenery number.
        assert_eq!(database.num(0, 0, 1), Some(-1), "row 0 BGM number");
        assert_eq!(database.num(0, 0, 2), Some(-1), "row 0 BGS number");
        assert_eq!(database.num(0, 0, 3), Some(0), "row 0 loop mode");
        assert_eq!(database.num(0, 0, 4), Some(-1), "row 0 scenery number");
        assert_eq!(database.num(0, 0, 5), None, "column 5 is a string field");
        assert_eq!(database.text(0, 3, 0), Some("MapData/Map003.mps"), "row 3");
        assert_eq!(
            database.text(0, 24, 0),
            Some("MapData/Map024.mps"),
            "row 24"
        );
        assert_eq!(
            database.text(0, 31, 0),
            Some("MapData/Map031.mps"),
            "row 31"
        );
        // The remaining 45 slots are unregistered maps.
        let registered = (0..table.rows.len())
            .filter(|row| {
                database
                    .text(0, *row, 0)
                    .is_some_and(|path| !path.is_empty())
            })
            .count();
        assert_eq!(registered, 5, "registered maps");
    }

    #[test]
    fn the_colour_table_holds_the_palette() {
        let Some(data) = load("SysDatabase.dat") else {
            skip("SysDatabase.dat");
            return;
        };
        let database = SysDatabase::parse(&data).expect("SysDatabase.dat parses");
        let table = &database.types[SysDatabase::COLOUR_TYPE];
        assert_eq!(table.fields.len(), 3, "three channels per row");
        assert_eq!(table.numeric_columns(), 3, "all three are numeric");
        assert_eq!(table.string_columns(), 0);
        assert_eq!(table.rows.len(), 30, "palette size");

        let palette: [[u8; 3]; 5] = [
            [255, 255, 255],
            [130, 130, 210],
            [210, 130, 130],
            [130, 230, 130],
            [90, 40, 0],
        ];
        for (index, expected) in palette.iter().enumerate() {
            assert_eq!(database.colour(index), Some(*expected), "colour {index}");
        }
        assert_eq!(database.colour(29), Some([0, 0, 0]), "last palette entry");
        assert_eq!(database.colour(30), None, "palette has 30 entries");
    }

    #[test]
    fn the_face_graphic_table_points_at_pictures() {
        let Some(data) = load("SysDatabase.dat") else {
            skip("SysDatabase.dat");
            return;
        };
        let database = SysDatabase::parse(&data).expect("SysDatabase.dat parses");
        let table = &database.types[SysDatabase::FACE_GRAPHIC_TYPE];
        assert_eq!(table.fields.len(), 1, "one string field");
        assert_eq!(table.string_columns(), 1);
        assert_eq!(table.rows.len(), 12, "face graphic slots");
        assert_eq!(database.text(24, 2, 0), Some("Picture/face01.png"));
        assert_eq!(database.text(24, 3, 0), Some("Picture/face02.png"));
        assert_eq!(database.text(24, 4, 0), Some("Picture/face_normal.png"));
        assert_eq!(database.num(24, 2, 0), None, "column 0 is a string");
    }

    #[test]
    fn project_names_attach_to_types_and_rows() {
        let Some(data) = load("SysDatabase.dat") else {
            skip("SysDatabase.dat");
            return;
        };
        let Some(project) = load("SysDatabase.project") else {
            skip("SysDatabase.project");
            return;
        };
        let mut database = SysDatabase::parse(&data).expect("SysDatabase.dat parses");
        let filled = database.apply_project_names(&project);
        assert_eq!(filled, 28, "every type record was found");

        assert_eq!(database.types[0].name, "マップ設定");
        assert_eq!(database.types[1].name, "BGMリスト");
        assert_eq!(database.types[6].name, "システム変数名");
        assert_eq!(database.types[12].name, "文字色");
        assert_eq!(database.types[23].name, "予備変数9");
        assert_eq!(database.types[24].name, "顔グラフィック名");

        // Type 6 is the system variable block: 150 rows, and row names are the
        // only names it has — the table itself has no fields at all.
        let variables = SysDatabase::SYSTEM_VARIABLE_TYPE;
        assert_eq!(database.row_count(variables), 135);
        assert_eq!(database.name_of(variables, 0), Some("顔ｸﾞﾗﾌｨｯｸ番号"));
        assert_eq!(database.name_of(variables, 1), Some("ﾒｯｾｰｼﾞｳｨﾝﾄﾞｳ X座標"));
        assert_eq!(database.name_of(variables, 2), Some("ﾒｯｾｰｼﾞｳｨﾝﾄﾞｳ Y座標"));
        assert_eq!(database.name_of(variables, 150), None, "no 136th variable");

        // Row names line up with the map list and the palette, too.
        assert_eq!(database.name_of(0, 0), Some("タイトル"));
        assert_eq!(database.name_of(0, 1), Some("自宅1"));
        assert_eq!(database.name_of(0, 4), Some(""), "unused slot has no name");
        assert_eq!(database.name_of(12, 0), Some("デフォルト色"));
        assert_eq!(database.name_of(12, 1), Some("青色"));
        assert_eq!(database.name_of(24, 2), Some("妹（制服）"));
        assert_eq!(database.name_of(4, 0), Some("一時文字列"));

        // Field names come from the same record; the map list's eight fields are
        // the ones this port reads (§6.4 / §6.8).
        assert_eq!(database.field_name(0, 0), Some("マップファイル名"));
        assert_eq!(database.field_name(0, 1), Some("BGM番号(ﾘｽﾄ読込)"));
        assert_eq!(database.field_name(0, 5), Some("BGMﾌｧｲﾙ名[BGM番号=-3]"));
        assert_eq!(database.field_name(0, 8), None, "type 0 has eight fields");
        assert_eq!(database.types[0].field_name(4), Some("遠景番号"));
        assert_eq!(
            database.field_name(6, 0),
            None,
            "the name-only table has no field"
        );
        assert_eq!(database.field_name(28, 0), None, "past the last type");
    }

    #[test]
    fn project_names_are_rejected_for_a_mismatched_container() {
        let Some(data) = load("SysDatabase.dat") else {
            skip("SysDatabase.dat");
            return;
        };
        let mut database = SysDatabase::parse(&data).expect("SysDatabase.dat parses");
        // A companion with the wrong leading type count belongs to a different
        // database version and must not be trusted.
        let mut project = Vec::new();
        project.extend_from_slice(&7u32.to_le_bytes());
        project.extend_from_slice(&[0x7F; 32]);
        assert_eq!(database.apply_project_names(&project), 0);
        assert!(database.types.iter().all(|table| table.name.is_empty()));
        assert_eq!(database.apply_project_names(&[]), 0, "empty companion");
    }
}
