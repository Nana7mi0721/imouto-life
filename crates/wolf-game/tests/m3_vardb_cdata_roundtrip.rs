//! M3-AB: CDataBase overlay versus the variable database stored in a save file.
//!
//! Game::new uses Save/System.sav as its save template. This build's System.sav carries
//! an empty variable database, so Game::new seeds the CDataBase schema from the static
//! table (docs/M3_VARDB_BUG.md). These tests pin that fix: a new game must be able to
//! save every 可変DB cell, and a runtime edit must survive save_to -> load_save.
//!
//! Tests are data-driven: when WOLF_DATA_ROOT is missing or unreadable, they print a
//! skip line and return so the normal workspace test run still exits zero.

use std::path::PathBuf;

use wolf_game::db::Container;
use wolf_game::{savegame, Game};
use wolf_save::vardb::VariableDatabase;

/// Number of CDataBase cells in this game (30 types, 650 rows, 1052 configured fields).
const EXPECTED_CDATA_CELLS: usize = 19196;
/// Same shape of the complete variable database shipped inside SaveData01/02.
const EXPECTED_VARDB_TYPES: usize = 30;
const EXPECTED_VARDB_ROWS: u64 = 650;
/// Rows in the static CDataBase.dat: one fewer than a shipped save, which appends one
/// row to type 5 at run time.
const EXPECTED_CDATA_ROWS: u64 = 649;
const EXPECTED_VARDB_CONFIG: u64 = 1052;

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let path = PathBuf::from(raw);
    if path.is_absolute() {
        return path;
    }
    let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    base.pop();
    base.pop();
    base.join(path)
}

fn out_dir() -> PathBuf {
    data_root().parent().expect("data root parent").join("out")
}

fn save_file(slot: u32) -> PathBuf {
    data_root().join("Save").join(format!("SaveData{slot:02}.sav"))
}

fn open_new() -> Option<Game> {
    match Game::new(data_root()) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!("skipping: {err}");
            None
        }
    }
}

fn open_loaded(slot: u32) -> Option<Game> {
    let mut game = open_new()?;
    let path = save_file(slot);
    if !path.is_file() {
        eprintln!("skipping: {} missing", path.display());
        return None;
    }
    game.load_save(&path).expect("load shipped save");
    Some(game)
}

#[derive(Debug, Clone, PartialEq, Eq)]
enum Live {
    Num(i32),
    Str(String),
}

#[derive(Debug, Clone, PartialEq, Eq)]
struct Cell {
    ty: usize,
    row: usize,
    col: usize,
    live: Live,
}

#[derive(Debug, Clone)]
enum Stored {
    Missing,
    Num(i32),
    Str(String),
    OtherKind,
}

fn stored_of(db: &VariableDatabase, ty: usize, row: usize, col: usize) -> Stored {
    if let Some(value) = db.number(ty, row, col) {
        return Stored::Num(value);
    }
    if let Some(bytes) = db.string(ty, row, col) {
        // Saved vardb text mixes CP932 template strings with GBK fan-translation
        // strings; the live layer now decodes the same way (db.rs), so the stored
        // bytes must be read with the same heuristic or every non-ASCII cell would
        // look like a mismatch.
        let text = wolf_format::bytes::decode_wolf_str(bytes);
        return Stored::Str(text.trim_end_matches(char::from(0)).to_owned());
    }
    // Both readers returned None. A missing type, row or configured field means the
    // cell was never encoded; an existing slot with another kind is a kind mismatch.
    match db.type_of(ty).and_then(|kind| kind.config.get(col)) {
        None => Stored::Missing,
        Some(_) if db.row(ty, row).is_none() => Stored::Missing,
        Some(_) => Stored::OtherKind,
    }
}

fn live_cells(game: &Game) -> Vec<Cell> {
    let mut cells = Vec::new();
    for ty in 0..40usize {
        let Some(row_count) = game.databases.row_count(Container::CData, ty as i32) else {
            continue;
        };
        let Some(field_count) = game.databases.field_count(Container::CData, ty as i32) else {
            continue;
        };
        for row in 0..row_count {
            for col in 0..field_count {
                let number = game
                    .databases
                    .num(Container::CData, ty as i32, row as i32, col as i32);
                let text = game
                    .databases
                    .text(Container::CData, ty as i32, row as i32, col as i32);
                if let Some(value) = number {
                    cells.push(Cell {
                        ty,
                        row,
                        col,
                        live: Live::Num(value),
                    });
                } else if let Some(value) = text {
                    cells.push(Cell {
                        ty,
                        row,
                        col,
                        live: Live::Str(value.to_owned()),
                    });
                }
            }
        }
    }
    cells
}

/// Returns (missing, mismatch) over every live CDataBase cell.
fn compare(cells: &[Cell], db: &VariableDatabase) -> (usize, usize) {
    let mut missing = 0usize;
    let mut mismatch = 0usize;
    for cell in cells {
        match (&cell.live, stored_of(db, cell.ty, cell.row, cell.col)) {
            (_, Stored::Missing) => missing += 1,
            (Live::Num(a), Stored::Num(b)) if *a == b => {}
            (Live::Str(a), Stored::Str(b)) if *a == b => {}
            _ => mismatch += 1,
        }
    }
    (missing, mismatch)
}

fn rows_total(db: &VariableDatabase) -> u64 {
    db.types.iter().map(|kind| kind.rows.len() as u64).sum()
}

fn config_total(db: &VariableDatabase) -> u64 {
    db.types.iter().map(|kind| kind.config.len() as u64).sum()
}

/// Loading a shipped save installs a complete variable database as the save template,
/// so every CDataBase cell is present in the file written by the next save_to.
#[test]
fn loaded_save_writes_every_cdata_cell_into_the_saved_database() {
    let shipped = match savegame::read_save(&save_file(1)) {
        Ok(save) => save,
        Err(err) => {
            eprintln!("skipping: SaveData01.sav unreadable: {err}");
            return;
        }
    };
    assert_eq!(shipped.vardb.type_count as usize, EXPECTED_VARDB_TYPES);
    assert_eq!(shipped.vardb.types.len(), EXPECTED_VARDB_TYPES);
    assert_eq!(rows_total(&shipped.vardb), EXPECTED_VARDB_ROWS);
    assert_eq!(config_total(&shipped.vardb), EXPECTED_VARDB_CONFIG);

    let Some(mut game) = open_loaded(1) else {
        return;
    };
    let cells = live_cells(&game);
    assert_eq!(
        cells.len(),
        EXPECTED_CDATA_CELLS,
        "every CDataBase cell should be readable"
    );

    let path = out_dir().join("m3_vardb_cdata_shipped.sav");
    let _ = std::fs::create_dir_all(out_dir());
    let _ = std::fs::remove_file(&path);
    assert!(game.save_to(&path).expect("save_to shipped overlay") > 0);
    let stored = savegame::read_save(&path).expect("read back shipped overlay save");

    let (missing, mismatch) = compare(&cells, &stored.vardb);
    assert_eq!(
        missing, 0,
        "a shipped save's template carries the full CData schema"
    );
    assert_eq!(mismatch, 0, "every stored cell must match the live value");

    let _ = std::fs::remove_file(&path);
}

/// Minimal reproduction of the bug, rewritten to pin the fixed behaviour: a fresh
/// Game::new seeds the empty System.sav variable database from the static CDataBase,
/// so the first save carries the full CData schema and every live cell.
#[test]
fn new_game_save_template_is_seeded_from_the_static_cdata() {
    let system = match savegame::read_save(&data_root().join("Save").join("System.sav")) {
        Ok(save) => save,
        Err(err) => {
            eprintln!("skipping: System.sav unreadable: {err}");
            return;
        }
    };
    assert_eq!(system.vardb.type_count, 0, "System.sav ships an empty template");
    assert!(system.vardb.types.is_empty());

    let Some(mut game) = open_new() else {
        return;
    };
    let (ty, row, col) = (6usize, 0usize, 1usize);
    let original = game
        .databases
        .num(Container::CData, ty as i32, row as i32, col as i32)
        .expect("CData type6 row0 col1 is numeric");
    game.databases
        .set_num(Container::CData, ty as i32, row as i32, col as i32, original + 1);
    let cells = live_cells(&game);
    assert_eq!(cells.len(), EXPECTED_CDATA_CELLS);

    // The template is seeded as soon as the game is constructed, before any save.
    let template = game.base_save.as_ref().expect("System.sav template");
    assert_eq!(
        template.vardb.type_count as usize,
        EXPECTED_VARDB_TYPES,
        "the seeded template has all 30 CDataBase types"
    );
    assert_eq!(
        config_total(&template.vardb),
        EXPECTED_VARDB_CONFIG,
        "field configs mirror the static table"
    );
    // The static table has 649 rows; a shipped save has 650 because a script appends one
    // row at run time (reconcile_row_counts reproduces that on a loaded game).
    assert_eq!(rows_total(&template.vardb), EXPECTED_CDATA_ROWS);

    let path = out_dir().join("m3_vardb_cdata_new.sav");
    let _ = std::fs::create_dir_all(out_dir());
    let _ = std::fs::remove_file(&path);
    assert!(game.save_to(&path).expect("save_to fresh game") > 0);
    let stored = savegame::read_save(&path).expect("read back fresh save");

    let (missing, mismatch) = compare(&cells, &stored.vardb);
    assert_eq!(missing, 0, "no CData cell may be dropped");
    assert_eq!(mismatch, 0, "every stored cell must match the live value");
    assert_eq!(
        game.stats.unmodelled, 0,
        "seeding the schema means no cell is refused"
    );
    assert_eq!(
        stored.vardb.type_count as usize,
        EXPECTED_VARDB_TYPES,
        "the written save carries the full schema"
    );
    assert_eq!(
        live_cells(&game),
        cells,
        "save_to must not mutate the live database entries themselves"
    );

    // The runtime edit survives a reload now that the database has a schema.
    let mut reloaded = open_new().expect("fresh game for reload");
    reloaded.load_save(&path).expect("load fresh save");
    let after = reloaded
        .databases
        .num(Container::CData, ty as i32, row as i32, col as i32)
        .expect("CData type6 row0 col1 still numeric");
    assert_eq!(after, original + 1, "the runtime edit must survive the round trip");

    let _ = std::fs::remove_file(&path);
}

/// Expected behaviour once the save template is seeded from the live Databases: every
/// CDataBase cell, including a run-time edit, must survive save_to -> load_save.
#[test]
fn new_game_save_preserves_every_cdata_cell_and_runtime_edit() {
    let Some(mut game) = open_new() else {
        return;
    };
    let (ty, row, col) = (6usize, 0usize, 1usize);
    let original = game
        .databases
        .num(Container::CData, ty as i32, row as i32, col as i32)
        .expect("CData type6 row0 col1 is numeric");
    game.databases
        .set_num(Container::CData, ty as i32, row as i32, col as i32, original + 1);
    let cells = live_cells(&game);
    assert_eq!(cells.len(), EXPECTED_CDATA_CELLS);

    let path = out_dir().join("m3_vardb_cdata_fixed.sav");
    let _ = std::fs::create_dir_all(out_dir());
    let _ = std::fs::remove_file(&path);
    assert!(game.save_to(&path).expect("save_to fresh game") > 0);
    let stored = savegame::read_save(&path).expect("read back fresh save");
    assert_eq!(stored.vardb.type_count as usize, EXPECTED_VARDB_TYPES);
    assert_eq!(stored.vardb.types.len(), EXPECTED_VARDB_TYPES);

    let (missing, mismatch) = compare(&cells, &stored.vardb);
    assert_eq!(missing, 0, "no CDataBase cell may be dropped");
    assert_eq!(mismatch, 0, "every stored cell must match the live value");
    assert_eq!(game.stats.unmodelled, 0);

    let mut reloaded = open_new().expect("fresh game for reload");
    reloaded.load_save(&path).expect("load fresh save");
    let after = reloaded
        .databases
        .num(Container::CData, ty as i32, row as i32, col as i32)
        .expect("CData type6 row0 col1 still numeric");
    assert_eq!(after, original + 1, "the runtime edit must survive the round trip");

    let _ = std::fs::remove_file(&path);
}
