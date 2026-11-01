//! The three WOLF databases, plus the cells the engine fills in by itself.
//!
//! Opcode 250 is the only database opcode this game uses: a probe over all 550
//! common events finds 2,592 [250] instructions and **no 251/252/253 at all**, so
//! no script ever writes a database. The argument count histogram is
//! {5: 2571, 4: 16}, i.e. [type, row, column, flags, destination]; the 16
//! four-argument sites have no destination and are pure side-effect reads.
//!
//! Which file a given type means is still being settled by docs/OPCODE_250.md,
//! so the routing below is **provisional** and deliberately forgiving: a numeric
//! read tries CDataBase then DataBase, a string read tries SysDatabase, then
//! CDataBase, then DataBase. What is not provisional is that the engine owns a
//! handful of cells no script writes -- see `Databases::apply_engine_defaults`.
//!
//! Evidence for the engine-owned cells:
//!
//! * `250 [18, 97, 0, ...]` and `250 [18, 98, 0, ...]` are read by common event
//!   48 (基本システム自動初期化) and by common event 63 as 座標倍率X/Y. CDataBase
//!   type 18 rows 97/98 carry the author own note in their string column --
//!   `この値は「自動システム初期化」処理でセットされます`, "this value is set by the
//!   automatic system initialisation" -- while their numeric column is 0 in the
//!   file. So the engine computes it at boot and the file never holds it.
//! * `250 [18, 0, 24, ...]` is read by common event 63 pc25 into the picture file
//!   name of the message-window frame. `SystemFile/WindowBase.png` is the skin
//!   `crate::window` already nine-slices, and it is the only plausible answer:
//!   DataBase type 18 has zero columns in this game, so the cell cannot come from
//!   a file at all.
//!
//! The coordinate scale is NOT the tile size: it is the screen size divided by the
//! engine's virtual screen, 1024x576 / 32x24. docs/OPCODE_101.md section 3.1 proves
//! it twice over: common event 48 divides the screen system variables by 32 and 24
//! (Sys116/32, Sys117/24), and common event 63 multiplies the result back and
//! stores 32*rateX = 1024 and 24*rateY = 576 into its own self[42]/self[43].
//! With rateX = 32 and rateY = 24 common event 63 places the message frame at
//! (64, 408), 960x168, flush with the bottom-right corner of the screen -- exactly
//! where a message box belongs, and 2 px above the text origin it computes
//! (Sys1 = 64, Sys2 = 410). Feeding it the tile size 16 instead lands Sys2 at 278,
//! i.e. above the frame the same event just drew; that was the bug fixed here.

use std::collections::BTreeMap;
use std::fs;
use std::path::{Path, PathBuf};

use wolf_format::database::{Database, FieldKind, RowValue};
use wolf_format::sysdatabase::SysDatabase;

/// `CDataBase` type the 座標倍率 (coordinate scale) lives in.
pub const COORDINATE_SCALE_TYPE: i32 = 18;
/// Row holding the X scale.
pub const COORDINATE_SCALE_X_ROW: i32 = 97;
/// Row holding the Y scale.
pub const COORDINATE_SCALE_Y_ROW: i32 = 98;
/// `CDataBase` type the message-window skin name is read from.
pub const WINDOW_SKIN_TYPE: i32 = 18;
/// Row of the message-window skin name.
pub const WINDOW_SKIN_ROW: i32 = 0;
/// Column of the message-window skin name (docs/OPCODE_250.md, ev63 pc25).
pub const WINDOW_SKIN_COLUMN: i32 = 24;
/// The skin the engine uses for the system message window.
pub const WINDOW_SKIN_FILE: &str = "SystemFile/WindowBase.png";
/// Screen size assumed when Game.dat cannot be read.
pub const DEFAULT_SCREEN: (u32, u32) = (1024, 576);
/// The engine's virtual screen, in units of one coordinate step.
pub const SCREEN_STEPS: (u32, u32) = (32, 24);

/// Row id a `250` **read** uses to ask for the current row count of a table.
///
/// CE48 pc153 reads `(0, -1, 33)` into self[10] and CE48 pc156 then loops
/// `179 [self[10]]` times over rows 0..count, i.e. the engine answers with the number
/// of rows, not with any cell (docs/OPCODE_250.md section 3.5). CE75 pc42 does the same
/// for 状態設定 and compares the count against the loop counter to raise
/// "【エラー】状態IDが大きすぎます" when a script walks past the last row.
pub const ROW_COUNT_QUERY: i32 = -1;

/// Row id a `250` **write** uses to set the current row count of a table.
///
/// CE191 pc30 writes `(22, -2, 0, write, 2)` and then writes rows 0 and 1 by hand;
/// CE157 pc28 writes `(14, -2, 6, write, 0)` under the comment 全部消去. The column
/// plays no part, and no new row id comes back to the caller -- see
/// [`Databases::set_row_count`].
pub const ROW_COUNT_SET: i32 = -2;

/// Column id a `250` **read** uses to ask for the first empty slot of a row.
///
/// CE58 pc10 reads `(1, self0, -1)` under the comment 最初に見つかった空欄箇所を記憶する
/// 変数 ("remember the first empty place found"). The engine answers with a row index of
/// the addressed type. Four sites use it; the scan looks at every field of every row and
/// answers the first all-empty row, or the row count when the table is full.
pub const FIRST_EMPTY_COLUMN: i32 = -1;

/// Column id a `250` **write** uses to clear every field of one row.
///
/// CE75 pc169 writes `(5, self0, -2)` under 強制全回復 ("force full recovery"); the
/// battle copy events CE79/CE143/CE144/CE171 all write `[10..14, row, -2]` before
/// copying a combatant into the temporary battle tables. The value operand is ignored.
pub const ROW_CLEAR_COLUMN: i32 = -2;

/// Column id a `250` **read** uses to return the editor name of one row.
///
/// CE265 (メッセージウィンドウの変更) reads `Data (26, 0, -3)` and CE267
/// (顔グラフィックの変更) reads `Sys (24, 0, -3)`, both into a string variable.
/// Type 26 is メッセージウィンドウ種類 and type 24 is 顔グラフィック名, so the
/// negative column is the row's own editor name (the label a `.project`
/// companion carries), which the engine hands back as a string.
pub const ROW_NAME_COLUMN: i32 = -3;

/// First row of the runtime extension area, i.e. the `100 + n` battle slots.
///
/// `CDataBase` type 0 holds 17 rows in this game, yet a capture of CE239 is seen to
/// read `CData (0, 100, 0)` as a character name (docs/BATTLE.md section 2.6). Rows from
/// 100 up are not in any file: the engine keeps them at run time and they start empty.
pub const EXTENSION_ROW_BASE: i32 = 100;

/// Which of the three database files a `250` instruction addresses.
///
/// The value comes from `(flags >> 8) & 3` and is verified on 2,195 labelled sites
/// with zero exceptions (docs/OPCODE_250.md section 3.2): 0 = CDataBase,
/// 1 = SysDatabase, 2 = DataBase. Testing bit 9 instead would misread every
/// SysDatabase access, and testing bit 12 would misread all of them.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq, PartialOrd, Ord)]
pub enum Container {
    /// The game's variable database (可変DB), `BasicData/CDataBase.dat`.
    #[default]
    CData,
    /// The engine's system database, `BasicData/SysDatabase.dat`.
    Sys,
    /// The editor's fixed database, `BasicData/DataBase.dat`.
    Data,
}

impl Container {
    /// Decodes the container from a `250` flags word.
    #[must_use]
    pub fn from_flags(flags: i32) -> Self {
        match (flags >> 8) & 3 {
            1 => Container::Sys,
            2 => Container::Data,
            _ => Container::CData,
        }
    }
}

/// The interpreter decodes `(flags >> 8) & 3` itself, so the game layer borrows that
/// decoding rather than repeating it; the two enums stay in step through this impl.
impl From<wolf_vm::DbContainer> for Container {
    fn from(value: wolf_vm::DbContainer) -> Self {
        match value {
            wolf_vm::DbContainer::CData => Container::CData,
            wolf_vm::DbContainer::Sys => Container::Sys,
            wolf_vm::DbContainer::Data => Container::Data,
        }
    }
}

/// The coordinate scale pair (rateX, rateY) for a screen size: one step is one
/// 32nd of the width and one 24th of the height (docs/OPCODE_101.md section 3.1).
pub fn coordinate_scale(screen: (u32, u32)) -> (i32, i32) {
    let divisor = |value: u32, steps: u32| i32::try_from((value / steps).max(1)).unwrap_or(1);
    (
        divisor(screen.0, SCREEN_STEPS.0),
        divisor(screen.1, SCREEN_STEPS.1),
    )
}

/// The game databases plus the engine-owned cells layered on top of them.
#[derive(Debug, Default)]
pub struct Databases {
    data: Option<Database>,
    cdata: Option<Database>,
    sys: Option<SysDatabase>,
    /// Engine-owned numeric cells, keyed (container, type, row, column).
    cells: BTreeMap<(Container, i32, i32, i32), i32>,
    /// Engine-owned string cells, same key.
    texts: BTreeMap<(Container, i32, i32, i32), String>,
    /// Row counts a script set at run time, keyed (container, type).
    ///
    /// A `250` write to row [`ROW_COUNT_SET`] replaces the row count the `.dat` file
    /// carries; the entries here shadow it. The editor ships tables of fixed height, but
    /// every 一覧算出 event in this game empties a scratch table and refills it, so the
    /// count has to move at run time.
    row_counts: BTreeMap<(Container, i32), i32>,
}

impl Databases {
    /// Loads `DataBase.dat`, `CDataBase.dat` and `SysDatabase.dat` from `basic`
    /// (the `BasicData` directory), then layers the engine defaults on top.
    ///
    /// A missing or corrupt file is not an error: the game still boots and the
    /// diagnostics report which cells stay unanswered.
    pub fn load(basic: &Path, screen: (u32, u32)) -> Self {
        Self::load_with_overlays(basic, &[], screen)
    }

    /// Loads the database files through mod overlays, highest priority last.
    ///
    /// Each overlay may mirror the data root directly or its `BasicData` folder. A name
    /// that no overlay carries falls back to `basic`, so a mod can ship just one table.
    pub fn load_with_overlays(basic: &Path, overlays: &[PathBuf], screen: (u32, u32)) -> Self {
        let read = |name: &str| {
            for overlay in overlays.iter().rev() {
                for candidate in [overlay.join("BasicData").join(name), overlay.join(name)] {
                    if candidate.is_file() {
                        return fs::read(candidate).ok();
                    }
                }
            }
            fs::read(basic.join(name)).ok()
        };
        let mut databases = Databases {
            data: read("DataBase.dat").and_then(|bytes| Database::parse(&bytes).ok()),
            cdata: read("CDataBase.dat").and_then(|bytes| Database::parse(&bytes).ok()),
            sys: read("SysDatabase.dat").and_then(|bytes| SysDatabase::parse(&bytes).ok()),
            ..Databases::default()
        };
        // The .project companions hold the editor labels, and `250` puts those labels in
        // its string arguments. They are what `resolve_labels` needs to map a script's
        // type id onto the right table row; without them only the numeric id is usable.
        if let (Some(table), Some(bytes)) = (databases.data.as_mut(), read("DataBase.project")) {
            table.apply_project_names(&bytes);
        }
        if let (Some(table), Some(bytes)) = (databases.cdata.as_mut(), read("CDataBase.project")) {
            table.apply_project_names(&bytes);
        }
        if let (Some(table), Some(bytes)) = (databases.sys.as_mut(), read("SysDatabase.project")) {
            table.apply_project_names(&bytes);
        }
        databases.apply_engine_defaults(screen);
        databases
    }

    /// An empty store that still answers the engine-owned cells.
    pub fn with_engine_defaults(screen: (u32, u32)) -> Self {
        let mut databases = Databases::default();
        databases.apply_engine_defaults(screen);
        databases
    }

    /// Fills the cells 自動システム初期化 sets: the coordinate scale pair and the
    /// message-window skin name.
    pub fn apply_engine_defaults(&mut self, screen: (u32, u32)) {
        let (scale_x, scale_y) = coordinate_scale(screen);
        self.set_num(
            Container::CData,
            COORDINATE_SCALE_TYPE,
            COORDINATE_SCALE_X_ROW,
            0,
            scale_x,
        );
        self.set_num(
            Container::CData,
            COORDINATE_SCALE_TYPE,
            COORDINATE_SCALE_Y_ROW,
            0,
            scale_y,
        );
        self.set_text(
            Container::Data,
            WINDOW_SKIN_TYPE,
            WINDOW_SKIN_ROW,
            WINDOW_SKIN_COLUMN,
            WINDOW_SKIN_FILE,
        );
    }

    /// True when no database file could be read; the engine cells may still exist.
    pub fn is_empty(&self) -> bool {
        self.data.is_none() && self.cdata.is_none() && self.sys.is_none()
    }

    /// Row count of `db_type` in `container`.
    ///
    /// SysDatabase answers through its own API; the two .dat containers share the type
    /// numbering but not the type meanings, so a caller must say which one it means.
    pub fn row_count(&self, container: Container, db_type: i32) -> Option<usize> {
        // A run-time count wins: a script emptied or refilled this table (see
        // [`Databases::set_row_count`]) and the .dat height is stale.
        if let Some(count) = self.row_counts.get(&(container, db_type)) {
            return usize::try_from(*count).ok();
        }
        match container {
            Container::Sys => self
                .sys
                .as_ref()
                .and_then(|table| Some(table.row_count(usize::try_from(db_type).ok()?))),
            _ => self
                .table(container)
                .and_then(|table| table.types.get(usize::try_from(db_type).ok()?))
                .map(|table| table.rows.len()),
        }
    }

    /// Editor name of row `row` of `db_type` — the `250` read of column [ROW_NAME_COLUMN].
    ///
    /// `None` when the type or row does not exist, or when no `.project` companion
    /// supplied the labels (the `.dat` files carry no names). The SysDatabase keeps
    /// its own name table; the other two share [`Database::row_name`].
    pub fn row_name(&self, container: Container, db_type: i32, row: i32) -> Option<&str> {
        let ty = usize::try_from(db_type).ok()?;
        let row = usize::try_from(row).ok()?;
        match container {
            Container::Sys => self.sys.as_ref()?.name_of(ty, row),
            _ => self.table(container)?.row_name(ty, row),
        }
    }

    /// True when `row` addresses a row the table currently holds.
    ///
    /// A negative row is a sentinel ([ROW_COUNT_QUERY] / [ROW_COUNT_SET]), not a row, and
    /// a row past the current count does not exist at all -- reading one used to clamp
    /// onto the last row, which answered the wrong character.
    #[must_use]
    pub fn row_exists(&self, container: Container, db_type: i32, row: i32) -> bool {
        usize::try_from(row).is_ok_and(|row| {
            self.row_count(container, db_type)
                .is_some_and(|count| row < count)
        })
    }

    /// True when a script has resized this table at run time (`250` write to row
    /// [ROW_COUNT_SET]). The `row_counts` overlay then wins over the `.dat` height, and a
    /// row the overlay no longer holds is a row the table genuinely dropped -- a read of
    /// it is empty rather than stale (see `Game::database`).
    #[must_use]
    pub fn has_runtime_row_count(&self, container: Container, db_type: i32) -> bool {
        self.row_counts.contains_key(&(container, db_type))
    }

    /// Sets the row count of one table -- the `250` write to row [ROW_COUNT_SET].
    ///
    /// CE191 pc30 sets 万能ウィンドウ to 2 and then writes rows 0 and 1 by hand; CE157
    /// pc28 sets a table to 0 under the comment 全部消去; every 一覧算出 event clears its
    /// scratch table to 0 before appending its entries. So the operand is the **new row
    /// count**, the column is ignored, and nothing is handed back to the caller (the
    /// interpreter drops a write's answer).
    ///
    /// Cells the table no longer has are dropped: a row that ceased to exist must not
    /// answer a later read. Negative rows are kept -- they are cell-layer scratch that
    /// [`Databases::write_into`] reports as a miss rather than addressing.
    pub fn set_row_count(&mut self, container: Container, db_type: i32, count: i32) {
        let count = count.max(0);
        self.row_counts.insert((container, db_type), count);
        let gone = |key: &(Container, i32, i32, i32)| {
            key.0 == container && key.1 == db_type && key.2 >= count && key.2 >= 0
        };
        self.cells.retain(|key, _| !gone(key));
        self.texts.retain(|key, _| !gone(key));
    }

    /// Number of logical fields one row of `db_type` carries, or `None` when the
    /// type does not exist. SysDatabase and the two .dat containers share this API.
    pub fn field_count(&self, container: Container, db_type: i32) -> Option<usize> {
        Some(self.field_kinds(container, db_type)?.len())
    }

    /// First row whose every field is empty, or the row count when none is.
    ///
    /// This is the answer to the `250` read of column [FIRST_EMPTY_COLUMN]: CE58 pc10
    /// remembers 最初に見つかった空欄箇所 before writing a newly learned skill, and
    /// CE143 pc187 compares the answer with 38 before storing a piece of armour.
    pub fn first_empty_row(&self, container: Container, db_type: i32) -> Option<i32> {
        let count = self.row_count(container, db_type)?;
        let fields = self.field_kinds(container, db_type)?;
        let row = (0..count).find(|row| {
            fields.iter().enumerate().all(|(column, field)| {
                let column = i32::try_from(column).unwrap_or(i32::MAX);
                match field {
                    FieldKind::Num(_) => {
                        self.num(container, db_type, *row as i32, column)
                            .unwrap_or(0)
                            == 0
                    }
                    FieldKind::Str(_) => self
                        .text(container, db_type, *row as i32, column)
                        .is_none_or(str::is_empty),
                }
            })
        });
        i32::try_from(row.unwrap_or(count)).ok()
    }

    /// Clears every field of one row -- the `250` write to a negative column.
    ///
    /// The engine cells are dropped and then every field is shadowed with its zero
    /// value, so a column the .dat file carries is cleared too, not just the cells a
    /// script happened to touch. Returns false when the type does not exist.
    pub fn clear_row(&mut self, container: Container, db_type: i32, row: i32) -> bool {
        let Some(fields) = self.field_kinds(container, db_type) else {
            return false;
        };
        let keys_match = |key: &(Container, i32, i32, i32)| {
            key.0 == container && key.1 == db_type && key.2 == row
        };
        self.cells.retain(|key, _| !keys_match(key));
        self.texts.retain(|key, _| !keys_match(key));
        for (column, field) in fields.iter().enumerate() {
            let column = i32::try_from(column).unwrap_or(i32::MAX);
            match field {
                FieldKind::Num(_) => self.set_num(container, db_type, row, column, 0),
                FieldKind::Str(_) => self.set_text(container, db_type, row, column, ""),
            }
        }
        true
    }

    /// The field kinds of one type, in logical column order.
    fn field_kinds(&self, container: Container, db_type: i32) -> Option<Vec<FieldKind>> {
        match container {
            Container::Sys => Some(
                self.sys
                    .as_ref()?
                    .types()
                    .get(usize::try_from(db_type).ok()?)?
                    .fields
                    .clone(),
            ),
            _ => Some(
                self.table(container)?
                    .types
                    .get(usize::try_from(db_type).ok()?)?
                    .fields
                    .clone(),
            ),
        }
    }

    /// The `.mps` path registered for a map id (SysDatabase type 0, column 0).
    ///
    /// Opcode 130 stores map ids in a signed form: `-1` is map 1 and `-2` is
    /// map 0. Both new-game paths use `-1` to reach SampleMapA (MapData row 1),
    /// and Map002 has four `-2` sites that return to TitleMap (row 0); no other
    /// values appear in the game (docs/ASSET_AUDIT.md section 3.6).
    pub fn map_path(&self, id: i32) -> Option<&str> {
        let row = usize::try_from(id).ok()?;
        self.sys.as_ref()?.text(0, row, 0)
    }

    /// Numeric read: engine cells win, then the addressed container.
    /// The SystemDB `12:文字色` palette entry that `\c[n]` names.
    ///
    /// The palette lives in SysDatabase type 12 (30 rows, 3 numeric fields) and is the
    /// only place the game defines text colours; a text picture that writes `\c[1]`
    /// means row 1 of this table, not an RGB literal.
    pub fn colour(&self, index: i32) -> Option<[u8; 3]> {
        let row = usize::try_from(index).ok()?;
        self.sys.as_ref()?.colour(row)
    }

    /// The engine cell layer alone: the value a script or the save put here.
    ///
    /// [`Databases::num`] falls back to the `.dat` row, which is right for a normal read
    /// but useless for a runtime extension row (`100 + n`) or for deciding whether a
    /// write starts from zero instead of from the last row of the file.
    #[must_use]
    pub fn engine_num(
        &self,
        container: Container,
        db_type: i32,
        row: i32,
        column: i32,
    ) -> Option<i32> {
        self.cells.get(&(container, db_type, row, column)).copied()
    }

    /// The engine cell layer alone, string side.
    #[must_use]
    pub fn engine_text(
        &self,
        container: Container,
        db_type: i32,
        row: i32,
        column: i32,
    ) -> Option<&str> {
        self.texts
            .get(&(container, db_type, row, column))
            .map(String::as_str)
    }

    pub fn num(&self, container: Container, db_type: i32, row: i32, column: i32) -> Option<i32> {
        if let Some(value) = self.cells.get(&(container, db_type, row, column)) {
            return Some(*value);
        }
        if row < 0 || column < 0 {
            return None;
        }
        let (row, column) = (row as usize, column as usize);
        match container {
            Container::Sys => self
                .sys
                .as_ref()
                .and_then(|table| table.num(db_type as usize, row, column))
                .and_then(|value| i32::try_from(value).ok()),
            _ => self
                .table(container)
                .and_then(|table| numeric_cell(table, db_type, row, column)),
        }
    }

    /// String read: engine cells win, then the addressed container.
    pub fn text(&self, container: Container, db_type: i32, row: i32, column: i32) -> Option<&str> {
        if let Some(value) = self.texts.get(&(container, db_type, row, column)) {
            return Some(value);
        }
        if row < 0 || column < 0 {
            return None;
        }
        let (row, column) = (row as usize, column as usize);
        match container {
            Container::Sys => self
                .sys
                .as_ref()
                .and_then(|table| table.text(db_type as usize, row, column)),
            _ => self
                .table(container)
                .and_then(|table| string_cell(table, db_type, row, column)),
        }
    }

    /// Copies every row of a save file variable database over the .dat tables.
    ///
    /// The variable database is part of the save, not of the installation:
    /// character creation writes the player name into CDataBase type 0 row 12,
    /// and every later script reads it back through opcode 250. Without this copy a
    /// loaded save would show the names the .dat file happens to contain (empty)
    /// instead of the player own. The values go into the engine cell layer, so an
    /// ordinary 250 write and a later save both see the same data.
    pub fn apply_saved_database(&mut self, database: &wolf_save::VariableDatabase) {
        for (type_index, table) in database.types.iter().enumerate() {
            let db_type = i32::try_from(type_index).unwrap_or(i32::MAX);
            for row in &table.rows {
                let row_index = i32::try_from(row.index).unwrap_or(i32::MAX);
                for (column, definition) in table.config.iter().enumerate() {
                    let column = i32::try_from(column).unwrap_or(i32::MAX);
                    if *definition >= 2000 {
                        if let Some(bytes) = row.string(column as u32) {
                            // Saved vardb strings mix CP932 template text with GBK
                            // fan-translation text (measured: ヒーローさん CP932, 没有数据
                            // GBK). A lossy UTF-8 read would turn both into mojibake and,
                            // worse, make a re-save unable to recognise the unchanged
                            // cell. Decode with the same heuristic the .dat loaders use;
                            // the writer keeps the original bytes when the text matches.
                            let text = wolf_format::bytes::decode_wolf_str(bytes);
                            let text = text.trim_end_matches(char::from(0));
                            self.set_text(Container::CData, db_type, row_index, column, text);
                        }
                    } else if let Some(value) = row.number(column as u32) {
                        self.set_num(Container::CData, db_type, row_index, column, value);
                    }
                }
            }
        }
    }

    /// Builds the complete save-file variable database from the static `CDataBase`.
    ///
    /// `Save/System.sav` is the template a brand-new game saves from, but this build's
    /// copy carries an **empty** variable database (0 types / 0 rows / 0 configs,
    /// measured — see docs/M3_VARDB_BUG.md). [`Self::write_into`] can only overwrite
    /// types, rows and fields that already exist, so without a schema no 可変DB cell
    /// can reach the file and every runtime edit is lost on reload.
    ///
    /// The static `CDataBase.dat` is the authoritative schema: its type count, field
    /// kinds, `data_id_method` and row table are exactly what the shipped SaveData01/02
    /// variable databases carry (30 types / 1052 configs / the same `dis` values), and
    /// the only difference is the one row a script appends at run time, which
    /// [`Self::reconcile_row_counts`] adds when that happens. Values start at the static
    /// cells; [`Self::write_into`] then overlays the live engine cells.
    ///
    /// Does nothing (and returns false) when the database already has a schema or when
    /// `CDataBase.dat` is missing — a loaded retail save keeps its own complete vardb.
    pub fn seed_vardb(&self, database: &mut wolf_save::VariableDatabase) -> bool {
        if !database.types.is_empty() {
            return false;
        }
        let Some(cdata) = self.cdata.as_ref() else {
            return false;
        };
        let mut types = Vec::with_capacity(cdata.types.len());
        for table in &cdata.types {
            let config: Vec<u32> = table.fields.iter().map(FieldKind::raw).collect();
            let mut rows = Vec::with_capacity(table.rows.len());
            for (index, row) in table.rows.iter().enumerate() {
                let mut fields = Vec::with_capacity(config.len());
                for (column, kind) in table.fields.iter().enumerate() {
                    let value = match kind {
                        FieldKind::Num(slot) => wolf_save::vardb::VariableValue::Number(
                            *row.numbers.get(*slot).unwrap_or(&0),
                        ),
                        FieldKind::Str(slot) => {
                            let mut body = row
                                .strings
                                .get(*slot)
                                .cloned()
                                .unwrap_or_default()
                                .into_bytes();
                            // The game stores NUL-terminated MemData bodies.
                            body.push(0);
                            wolf_save::vardb::VariableValue::String(body)
                        }
                    };
                    fields.push(wolf_save::vardb::VariableField {
                        id: column as u32,
                        value,
                    });
                }
                rows.push(wolf_save::vardb::VariableRow {
                    index: index as u32,
                    fields,
                });
            }
            let row_count = rows.len() as u32;
            types.push(wolf_save::vardb::VariableType {
                // Every retail save stores m_unknown = -2 with the real count in
                // m_fieldCount (vardb.rs documents this), and `dis` mirrors the
                // static `data_id_method` byte for byte on all 30 types.
                unknown: -2,
                dis: i32::try_from(table.data_id_method).unwrap_or(0),
                field_count: config.len() as u32,
                config,
                row_count,
                rows,
            });
        }
        database.type_count = types.len() as u32;
        database.types = types;
        true
    }

    /// Copies the engine-owned `CData` cells into a save file variable database.
    ///
    /// Only the 可変DB belongs in a save: `CDataBase` is the game's variable table,
    /// while `SysDatabase` is the engine's own configuration and `DataBase` is the
    /// editor's fixed table — neither is stored per player, so both are skipped here
    /// even though the engine layer may hold cells for them.
    ///
    /// Returns `(written, missed)`. `written` counts the cells the destination
    /// variable database accepted; `missed` counts the cells it refused because the
    /// type, row or field is not in the save at all (a fresh save has fewer rows than
    /// the .dat, and a field whose config says the other kind is refused by
    /// [VariableDatabase::set_num](wolf_save::vardb::VariableDatabase::set_num)). A negative
    /// row or column is not addressable and
    /// also counts as a miss rather than a panic: scripts do address row -1.
    pub fn write_into(&self, database: &mut wolf_save::VariableDatabase) -> (usize, usize) {
        // A table a script resized at run time ([`Databases::set_row_count`]) must be
        // resized in the save as well, or the rows it appended are not storable and the
        // rows it dropped come back on load. The .dat height is only a starting point.
        self.reconcile_row_counts(database);
        let (mut written, mut missed) = (0, 0);
        for ((container, db_type, row, column), value) in &self.cells {
            if *container != Container::CData {
                continue;
            }
            let stored = cell_address(*db_type, *row, *column)
                .is_some_and(|(ty, row, column)| database.set_num(ty, row, column, *value));
            if stored {
                written += 1;
            } else {
                missed += 1;
            }
        }
        for ((container, db_type, row, column), text) in &self.texts {
            if *container != Container::CData {
                continue;
            }
            let body = text.trim_end_matches(char::from(0));
            let stored = cell_address(*db_type, *row, *column)
                .is_some_and(|(ty, row, column)| database.set_text(ty, row, column, body));
            if stored {
                written += 1;
            } else {
                missed += 1;
            }
        }
        (written, missed)
    }

    /// Applies every run-time row count to a save file variable database.
    ///
    /// The variable database stores rows positionally (`m_idx == position`, measured
    /// across 9 retail saves and 6,507 rows with no exception), so a type can only hold
    /// rows `0..count`. Growing therefore appends default rows -- every numeric field 0,
    /// every textual field the empty string -- and shrinking truncates the tail. Types
    /// the game never resized are left exactly as loaded.
    fn reconcile_row_counts(&self, database: &mut wolf_save::VariableDatabase) {
        for ((container, db_type), count) in &self.row_counts {
            if *container != Container::CData {
                continue;
            }
            let (Ok(type_index), Ok(count)) = (usize::try_from(*db_type), usize::try_from(*count))
            else {
                continue;
            };
            let Some(kind) = database.types.get_mut(type_index) else {
                continue;
            };
            if kind.rows.len() > count {
                kind.rows.truncate(count);
            }
            while kind.rows.len() < count {
                let index = kind.rows.len() as u32;
                let fields = kind
                    .config
                    .iter()
                    .enumerate()
                    .map(|(id, definition)| wolf_save::vardb::VariableField {
                        id: id as u32,
                        value: if *definition >= 2000 {
                            wolf_save::vardb::VariableValue::String(vec![0])
                        } else {
                            wolf_save::vardb::VariableValue::Number(0)
                        },
                    })
                    .collect();
                kind.rows
                    .push(wolf_save::vardb::VariableRow { index, fields });
            }
            kind.row_count = kind.rows.len() as u32;
        }
    }

    /// Overwrites a numeric cell in the engine layer.
    pub fn set_num(
        &mut self,
        container: Container,
        db_type: i32,
        row: i32,
        column: i32,
        value: i32,
    ) {
        self.cells.insert((container, db_type, row, column), value);
    }

    /// Overwrites a string cell in the engine layer.
    pub fn set_text(
        &mut self,
        container: Container,
        db_type: i32,
        row: i32,
        column: i32,
        value: &str,
    ) {
        self.texts
            .insert((container, db_type, row, column), value.to_owned());
    }

    /// Resolves the editor labels a `250` command carries onto real table indices.
    ///
    /// The runtime type id is **not** always the table index. The eight `システム設定` /
    /// `装備可能欄数` reads in this game pass type 18 / column 22 (ev48 pc158, ev85 pc29,
    /// ev93 pc38, ev102 pc38, ev109 pc14, ev123 pc15, ev147 pc21, ev185 pc49) while the
    /// cell the author means is `DataBase` type 17 column 22, value 5: the editor counts
    /// the empty separator type 14 in its own numbering, so the ids drift. When a table
    /// has labels the names are therefore authoritative; a table without a `.project`
    /// (or a site whose labels do not resolve) keeps the numeric pair unchanged.
    pub fn resolve_labels(
        &self,
        container: Container,
        db_type: i32,
        column: i32,
        type_label: Option<&str>,
        field_label: Option<&str>,
    ) -> (i32, i32) {
        let Some(table) = self.table(container) else {
            return (db_type, column);
        };
        let type_wanted = type_label
            .map(normalise_label)
            .filter(|label| !label.is_empty());
        let named_type = type_wanted
            .as_deref()
            .and_then(|want| {
                (0..table.types.len()).find(|index| {
                    table.type_name(*index).map(normalise_label).as_deref() == Some(want)
                })
            })
            .map(|index| index as i32)
            .unwrap_or(db_type);
        let field_wanted = field_label
            .map(normalise_label)
            .filter(|label| !label.is_empty());
        let named_column = field_wanted
            .as_deref()
            .and_then(|want| {
                let index = usize::try_from(named_type).ok()?;
                let fields = table.types.get(index)?.fields.len();
                (0..fields).find(|column| {
                    table
                        .field_name(index, *column)
                        .map(normalise_label)
                        .as_deref()
                        == Some(want)
                })
            })
            .map(|index| index as i32)
            .unwrap_or(column);
        (named_type, named_column)
    }

    /// The .dat table behind one container; SysDatabase has its own type.
    fn table(&self, container: Container) -> Option<&Database> {
        match container {
            Container::CData => self.cdata.as_ref(),
            Container::Data => self.data.as_ref(),
            Container::Sys => None,
        }
    }
}

/// Normalises an editor label for comparison.
///
/// The .project companions mix U+2014 and U+2015 dashes and full-width spaces;
/// both spellings mean the same label to the engine.
fn normalise_label(label: &str) -> String {
    label
        .trim_end_matches(char::from(0))
        .replace('—', "-")
        .replace('―', "-")
        .replace('　', " ")
        .trim()
        .to_owned()
}

/// A `250` address as indices into a save file variable database.
///
/// Scripts address row -1 (and a table with no fields can address column -1), which
/// is a real read of "nothing" rather than an index; a save file has no such cell.
fn cell_address(db_type: i32, row: i32, column: i32) -> Option<(usize, usize, usize)> {
    let db_type = usize::try_from(db_type).ok()?;
    let row = usize::try_from(row).ok()?;
    let column = usize::try_from(column).ok()?;
    Some((db_type, row, column))
}

fn numeric_cell(table: &Database, db_type: i32, row: usize, column: usize) -> Option<i32> {
    let index = usize::try_from(db_type).ok()?;
    let table = table.types.get(index)?;
    // Scripts use negative rows as "last" sentinels and sometimes carry a row one
    // past the end (the editor counts a separator row). Clamp instead of leaving
    // the whole read unanswered; the engine treats the nearest existing row as the cell.
    let row = row.min(table.rows.len().checked_sub(1)?);
    let row = table.rows.get(row)?;
    match table.value(row, column)? {
        RowValue::Num(value) => Some(value),
        RowValue::Str(_) => None,
    }
}

fn string_cell(table: &Database, db_type: i32, row: usize, column: usize) -> Option<&str> {
    let index = usize::try_from(db_type).ok()?;
    let table = table.types.get(index)?;
    let row = row.min(table.rows.len().checked_sub(1)?);
    let row = table.rows.get(row)?;
    match table.value(row, column)? {
        RowValue::Str(text) => Some(text),
        RowValue::Num(_) => None,
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::PathBuf;

    fn data_root() -> PathBuf {
        if let Ok(value) = std::env::var("WOLF_DATA_ROOT") {
            if !value.is_empty() {
                return PathBuf::from(value);
            }
        }
        let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        path.pop();
        path.pop();
        path.push("work");
        path.push("full");
        path
    }

    fn have_data() -> Option<PathBuf> {
        let root = data_root();
        if root.join("BasicData").join("CDataBase.dat").is_file() {
            Some(root)
        } else {
            eprintln!("skipping: no game data at {}", root.display());
            None
        }
    }

    #[test]
    fn a_saved_variable_database_supplies_the_player_name() {
        // SaveData01 type 0 row 12 holds the two halves the HUD concatenates.
        let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        path.pop();
        path.pop();
        path.push("work");
        path.push("retail_backup");
        path.push("Save");
        path.push("SaveData01.sav");
        let Ok(bytes) = std::fs::read(&path) else {
            eprintln!("skipping: no retail save at {}", path.display());
            return;
        };
        let save = wolf_save::SaveFile::parse(&bytes).expect("SaveData01 parses");
        let mut databases = Databases::with_engine_defaults(DEFAULT_SCREEN);
        databases.apply_saved_database(&save.vardb);
        assert_eq!(databases.text(Container::CData, 0, 12, 0), Some("温柔的"));
        assert_eq!(databases.text(Container::CData, 0, 12, 1), Some("尖叫的"));
    }

    #[test]
    fn the_engine_owns_the_coordinate_scale_and_the_window_skin() {
        let databases = Databases::with_engine_defaults(DEFAULT_SCREEN);
        assert!(databases.is_empty());
        assert_eq!(
            databases.num(Container::CData, COORDINATE_SCALE_TYPE, 97, 0),
            Some(32)
        );
        assert_eq!(
            databases.num(Container::CData, COORDINATE_SCALE_TYPE, 98, 0),
            Some(24)
        );
        assert_eq!(
            databases.text(
                Container::Data,
                WINDOW_SKIN_TYPE,
                WINDOW_SKIN_ROW,
                WINDOW_SKIN_COLUMN
            ),
            Some("SystemFile/WindowBase.png")
        );
    }

    #[test]
    fn the_coordinate_scale_divides_the_screen_by_32_and_24() {
        assert_eq!(coordinate_scale((1024, 576)), (32, 24));
        assert_eq!(coordinate_scale((1280, 720,)), (40, 30));
        assert_eq!(coordinate_scale((8, 8)), (1, 1));
    }

    #[test]
    fn an_empty_store_answers_only_the_engine_cells() {
        let databases = Databases::with_engine_defaults(DEFAULT_SCREEN);
        assert_eq!(databases.num(Container::CData, 16, 0, 2), None);
        assert_eq!(databases.text(Container::Data, 16, 0, 2), None);
        assert_eq!(databases.row_count(Container::CData, 18), None);
        assert_eq!(databases.row_count(Container::Sys, 24), None);
    }

    #[test]
    fn the_engine_layer_wins_over_the_file() {
        let mut databases = Databases::with_engine_defaults(DEFAULT_SCREEN);
        databases.set_num(
            Container::CData,
            COORDINATE_SCALE_TYPE,
            COORDINATE_SCALE_X_ROW,
            0,
            24,
        );
        assert_eq!(
            databases.num(Container::CData, COORDINATE_SCALE_TYPE, 97, 0),
            Some(24)
        );
    }

    #[test]
    fn sysdatabase_decodes_the_face_graphic_type() {
        // Type id 24 of a `250` read is SysDatabase type 24 unchanged: 12 rows of
        // face-graphic names, `Picture/face01.png` at row 2.
        let Some(root) = have_data() else { return };
        let databases = Databases::load(&root.join("BasicData"), DEFAULT_SCREEN);
        assert!(!databases.is_empty());
        assert_eq!(
            databases.text(Container::Sys, 24, 2, 0),
            Some("Picture/face01.png")
        );
        assert_eq!(
            databases.text(Container::Sys, 24, 4, 0),
            Some("DLC_data/member_20_s.png")
        );
    }

    #[test]
    fn a_negative_name_column_returns_the_row_name() {
        // CE265 reads Data (26, 0, -3) and CE267 reads Sys (24, 0, -3): the column
        // is [ROW_NAME_COLUMN], the editor name of one row rather than a field.
        let Some(root) = have_data() else { return };
        let databases = Databases::load(&root.join("BasicData"), DEFAULT_SCREEN);
        assert_eq!(
            databases.row_name(Container::Data, 26, 0),
            Some("まる（妹）"),
            "Data type 26 is メッセージウィンドウ種類"
        );
        assert_eq!(
            databases.row_name(Container::Sys, 24, 0),
            Some("ウィンドウ表示なし"),
            "Sys type 24 is 顔グラフィック名"
        );
        assert_eq!(
            databases.row_name(Container::Data, 26, 99),
            None,
            "a row past the table has no name"
        );
        // A store without the .project companions has no names at all.
        assert_eq!(
            Databases::with_engine_defaults(DEFAULT_SCREEN).row_name(Container::Data, 26, 0),
            None
        );
    }

    #[test]
    fn the_real_databases_still_answer_the_engine_cells() {
        let Some(root) = have_data() else { return };
        let databases = Databases::load(&root.join("BasicData"), DEFAULT_SCREEN);
        // CDataBase type 18 stores 0 in rows 97/98; the engine value must win.
        assert_eq!(
            databases.num(Container::CData, COORDINATE_SCALE_TYPE, 97, 0),
            Some(32)
        );
        assert_eq!(
            databases.num(Container::CData, COORDINATE_SCALE_TYPE, 98, 0),
            Some(24)
        );
        assert_eq!(
            databases.row_count(Container::CData, COORDINATE_SCALE_TYPE),
            Some(100)
        );
        // A file-backed cell still resolves in its own container.
        assert_eq!(
            databases.text(Container::Data, 16, 0, 2),
            Some("SystemFile/WindowBase.png"),
            "DataBase type 16 row 0 column 2 must still be reachable"
        );
    }

    #[test]
    fn the_interpreter_container_maps_onto_the_right_table() {
        // The VM decodes (flags >> 8) & 3 itself; this impl is the only bridge, so a
        // mismatch here would silently route 250 reads into the wrong .dat file.
        assert_eq!(
            Container::from(wolf_vm::DbContainer::CData),
            Container::CData
        );
        assert_eq!(Container::from(wolf_vm::DbContainer::Sys), Container::Sys);
        assert_eq!(Container::from(wolf_vm::DbContainer::Data), Container::Data);
    }

    #[test]
    fn the_equipment_slot_label_resolves_onto_the_admin_type() {
        // This is the site the label route exists for: eight reads pass type 18 / column
        // 22 and mean DataBase type 17 column 22, because the editor numbering counts the
        // separator type 14 differently from the file. Without labels the read returns
        // nothing and the scripts believe there are zero equipment slots.
        let Some(root) = have_data() else { return };
        let databases = Databases::load(&root.join("BasicData"), DEFAULT_SCREEN);
        let (ty, column) = databases.resolve_labels(
            Container::Data,
            18,
            22,
            Some("システム設定"),
            Some("装備可能欄数"),
        );
        assert_eq!(
            (ty, column),
            (17, 22),
            "labels must land on DataBase type 17"
        );
        assert_eq!(databases.num(Container::Data, ty, 0, column), Some(5));
        // A raw read of the numeric pair the script carries answers nothing, which is why
        // the labels are not optional here.
        assert_eq!(databases.num(Container::Data, 18, 0, 22), None);
    }

    #[test]
    fn an_unresolvable_label_keeps_the_numeric_pair() {
        let Some(root) = have_data() else { return };
        let databases = Databases::load(&root.join("BasicData"), DEFAULT_SCREEN);
        assert_eq!(
            databases.resolve_labels(Container::Data, 16, 2, None, None),
            (16, 2)
        );
        assert_eq!(
            databases.resolve_labels(
                Container::Data,
                16,
                2,
                Some("存在しない型"),
                Some("存在しない列")
            ),
            (16, 2)
        );
        // Sys is answered by SysDatabase's own name table, but resolve_labels is a
        // .dat-container operation; it must leave a Sys call alone rather than guess.
        assert_eq!(
            databases.resolve_labels(Container::Sys, 6, 0, None, None),
            (6, 0)
        );
    }

    #[test]
    fn the_party_label_resolves_onto_the_player_row() {
        // CE105 asks for the member of party position 0 and labels the table
        // パーティー情報, member 1. The numeric type 3 is 属性耐性, so only the label
        // route reaches the row that says the party leader is status row 12.
        let Some(root) = have_data() else { return };
        let databases = Databases::load(&root.join("BasicData"), DEFAULT_SCREEN);
        let (db_type, column) = databases.resolve_labels(
            Container::CData,
            3,
            1,
            Some("パーティー情報"),
            Some("メンバー1"),
        );
        assert_eq!((db_type, column), (6, 1));
        assert_eq!(
            databases.num(Container::CData, db_type, 0, column),
            Some(12)
        );
    }

    fn retail_save() -> Option<wolf_save::SaveFile> {
        let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        path.pop();
        path.pop();
        path.push("work");
        path.push("retail_backup");
        path.push("Save");
        path.push("SaveData01.sav");
        let Ok(bytes) = std::fs::read(&path) else {
            eprintln!("skipping: no retail save at {}", path.display());
            return None;
        };
        Some(wolf_save::SaveFile::parse(&bytes).expect("SaveData01 parses"))
    }

    #[test]
    fn the_engine_cells_land_in_the_save_variable_database() {
        let Some(save) = retail_save() else { return };
        let mut database = save.vardb.clone();
        // The engine cells the boot sequence owns: the coordinate scale pair. The
        // save carries its own values for these rows, so a successful write is
        // visible against a non-zero previous state.
        let databases = Databases::with_engine_defaults(DEFAULT_SCREEN);
        let (written, missed) = databases.write_into(&mut database);
        assert_eq!(written, 2, "the scale pair, and nothing else");
        assert_eq!(missed, 0, "both rows exist in the retail save");
        assert_eq!(
            database.number(18, 97, 0),
            Some(32),
            "rateX must be 1024/32"
        );
        assert_eq!(database.number(18, 98, 0), Some(24), "rateY must be 576/24");
        // `250 [18, 0, 24]` reads the message-window skin through the **Data**
        // container; DataBase is not part of a save, so the skin must not be written
        // into the variable database even though the engine layer holds it.
        let skin = database.string(18, 0, 24);
        assert!(
            skin.is_none(),
            "DataBase cells must stay out of the save, got {skin:?}"
        );

        // A round-trip proves the write survives the encoder, not just the struct.
        let bytes = database.to_bytes().expect("the vardb re-encodes");
        let reparsed = wolf_save::vardb::parse_bytes(&bytes).expect("and parses back");
        assert_eq!(reparsed.number(18, 97, 0), Some(32));
        assert_eq!(reparsed.number(18, 98, 0), Some(24));
    }

    #[test]
    fn a_row_count_write_changes_the_table_height() {
        // CE191 pc30 sets 万能ウィンドウ to 2 rows and then writes rows 0 and 1 by hand;
        // CE157 pc28 sets a table to 0 under the comment 全部消去. Row -2 is the height,
        // never a row, so the write of the count must not create a row at index -2.
        let mut databases = Databases::with_engine_defaults(DEFAULT_SCREEN);
        assert_eq!(databases.row_count(Container::CData, 22), None);
        databases.set_row_count(Container::CData, 22, 2);
        assert_eq!(databases.row_count(Container::CData, 22), Some(2));
        assert!(databases.row_exists(Container::CData, 22, 0));
        assert!(databases.row_exists(Container::CData, 22, 1));
        assert!(!databases.row_exists(Container::CData, 22, 2));
        // A negative row is a sentinel, not a row of the table.
        assert!(!databases.row_exists(Container::CData, 22, ROW_COUNT_SET));
        // Clearing drops the rows the table lost; a read of one must not answer.
        databases.set_num(Container::CData, 22, 0, 0, 5);
        databases.set_num(Container::CData, 22, 1, 0, 6);
        databases.set_row_count(Container::CData, 22, 1);
        assert_eq!(databases.engine_num(Container::CData, 22, 0, 0), Some(5));
        assert_eq!(databases.engine_num(Container::CData, 22, 1, 0), None);
        databases.set_row_count(Container::CData, 22, 0);
        assert_eq!(databases.row_count(Container::CData, 22), Some(0));
        assert_eq!(databases.engine_num(Container::CData, 22, 0, 0), None);
    }

    #[test]
    fn a_row_count_the_script_set_reaches_the_save_as_appended_rows() {
        // A table a script grew has to be grown in the save too, or the rows the game
        // appended would be dropped on save and the list would come back stale on load.
        let Some(save) = retail_save() else { return };
        let mut database = save.vardb.clone();
        // Pick a type the save really holds with a real field, so the appended row has
        // somewhere to put its value: type 22 turns out to carry no fields at all.
        let (db_type, before, column) = (0..database.types.len())
            .find_map(|index| {
                let kind = database.types.get(index)?;
                let column = kind
                    .config
                    .iter()
                    .position(|definition| *definition < 2000)?;
                (!kind.rows.is_empty()).then_some((index as i32, kind.rows.len(), column as i32))
            })
            .expect("the retail save holds a type with a row and a numeric field");
        let mut databases = Databases::with_engine_defaults(DEFAULT_SCREEN);
        databases.set_row_count(Container::CData, db_type, before as i32 + 1);
        databases.set_num(Container::CData, db_type, before as i32, column, 77);
        let (written, missed) = databases.write_into(&mut database);
        assert_eq!(missed, 0, "the appended row must be storable");
        // The two coordinate-scale cells the engine always owns, plus the appended one.
        assert_eq!(written, 3);
        let kind = database
            .type_of(usize::try_from(db_type).expect("index"))
            .expect("the type survives");
        assert_eq!(
            kind.rows.len(),
            before + 1,
            "the save must carry the appended row"
        );
        assert_eq!(
            kind.row_count as usize,
            before + 1,
            "and the stored row count must agree with the rows"
        );
        assert_eq!(
            database.number(
                usize::try_from(db_type).expect("index"),
                before,
                usize::try_from(column).expect("column")
            ),
            Some(77)
        );
        // The whole variable database must still serialize: a row count that disagrees
        // with the row list is rejected by the writer.
        assert!(
            database.to_bytes().is_ok(),
            "the reconciled variable database must serialize"
        );
    }

    #[test]
    fn clearing_a_row_zeroes_every_field_in_the_file_and_the_engine_layer() {
        let Some(root) = have_data() else { return };
        let mut databases = Databases::load(&root.join("BasicData"), DEFAULT_SCREEN);
        let fields = databases
            .field_count(Container::CData, 0)
            .expect("主人公ステータス has a field table");
        assert!(fields >= 46);
        // Row 0 is 勇者先生 with a name and a full stat block, so it is a hard case:
        // clearing it has to shadow both the string and the numeric .dat columns.
        assert_eq!(databases.text(Container::CData, 0, 0, 0), Some("勇者先生"));
        databases.set_num(Container::CData, 0, 0, 0, 7);
        assert!(databases.clear_row(Container::CData, 0, 0));
        for column in 0..fields {
            let column = i32::try_from(column).expect("small column");
            if let Some(text) = databases.text(Container::CData, 0, 0, column) {
                assert!(text.is_empty(), "column {column} still holds {text:?}");
            }
            if let Some(value) = databases.num(Container::CData, 0, 0, column) {
                assert_eq!(value, 0, "column {column} still holds {value}");
            }
        }
        assert!(!databases.clear_row(Container::CData, 999, 0));
    }

    #[test]
    fn the_first_empty_row_is_a_row_index_not_a_zero_fallback() {
        let Some(root) = have_data() else { return };
        let mut databases = Databases::load(&root.join("BasicData"), DEFAULT_SCREEN);
        let count = databases
            .row_count(Container::CData, 0)
            .expect("主人公ステータス has rows");
        let first = databases
            .first_empty_row(Container::CData, 0)
            .expect("the query answers");
        assert!(first >= 0 && (first as usize) <= count);
        // Row 0 is the hero and cannot be the first empty row while it retains its name.
        assert_ne!(first, 0);
        assert!(databases.clear_row(Container::CData, 0, 0));
        assert_eq!(databases.first_empty_row(Container::CData, 0), Some(0));
    }

    #[test]
    fn a_cell_the_save_does_not_have_is_counted_as_a_miss() {
        let Some(save) = retail_save() else { return };
        let mut database = save.vardb.clone();
        let mut databases = Databases::with_engine_defaults(DEFAULT_SCREEN);
        // Row -1 is what a script means by "no row"; a save file cannot address it.
        databases.set_num(Container::CData, 18, -1, 0, 7);
        databases.set_num(Container::CData, 99, 0, 0, 7);
        databases.set_num(Container::CData, 18, 97, 9, 7);
        // A textual field refuses a numeric write, and vice versa.
        databases.set_text(Container::CData, 18, 97, 0, "not a number");
        let (written, missed) = databases.write_into(&mut database);
        assert_eq!(written, 2, "the two real scale cells still land");
        assert_eq!(missed, 4, "row -1, type 99, column 9, and the wrong kind");
        assert_eq!(database.number(18, 97, 0), Some(32));
    }
}
