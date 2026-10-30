//! Dump cells of a `BasicData/*.dat` database, e.g. `DataBase.dat`.
//!
//! The interpreter needs to answer opcode 250 reads out of these tables, and the
//! mapping from a script's `(type, row, column)` triple to a real cell is exactly what
//! this example lets us pin down by eye.
//!
//! Usage:
//!
//! ```text
//! cargo run -p wolf-format --example dbdump -- [DATA_ROOT] [FILE] [TYPE] [ROWS...]
//! ```
//!
//! `DATA_ROOT` defaults to `work/full`, `FILE` to `DataBase`, `TYPE` to 16 and `ROWS` to
//! `0`; each row prints every column with its kind, so an empty tail column is obvious.

use std::path::PathBuf;

use wolf_format::database::{Database, RowValue};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut args = std::env::args().skip(1);
    let root = PathBuf::from(args.next().unwrap_or_else(|| "work/full".to_owned()));
    let file = args.next().unwrap_or_else(|| "DataBase".to_owned());
    let ty: usize = args.next().and_then(|v| v.parse().ok()).unwrap_or(16);
    let rows: Vec<usize> = {
        let rest: Vec<usize> = args.filter_map(|v| v.parse().ok()).collect();
        if rest.is_empty() {
            vec![0]
        } else {
            rest
        }
    };
    let list_names = std::env::args().any(|value| value == "--names");
    let path = root.join("BasicData").join(format!("{file}.dat"));
    let mut db = Database::parse(&std::fs::read(&path)?)?;
    println!("file    : {}", path.display());
    println!("version : 0x{:02X}, {} type(s)", db.version, db.types.len());
    // The companion .project holds every editor label; without it a dump can only
    // show numbers, and the 250 argument layout is exactly a labelling question.
    let project = root.join("BasicData").join(format!("{file}.project"));
    if let Ok(bytes) = std::fs::read(&project) {
        let aligned = db.apply_project_names(&bytes);
        println!(
            "project : {} ({} record(s) aligned)",
            project.display(),
            aligned
        );
    }
    if list_names {
        for index in 0..db.types.len() {
            let fields = db.types[index].fields.len();
            println!(
                "type {index:>2}: {} ({} field(s))",
                db.type_name(index).unwrap_or("<unnamed>"),
                fields
            );
            for column in 0..fields {
                if let Some(label) = db.field_name(index, column) {
                    println!("          col {column:<3} {label}");
                }
            }
        }
        return Ok(());
    }
    let table = db
        .types
        .get(ty)
        .ok_or_else(|| format!("no type {ty}; the file has {}", db.types.len()))?;
    println!(
        "type {ty:>2}: {} — {} column(s) ({} numeric + {} string), {} row(s), data_id_method {}",
        db.type_name(ty).unwrap_or("<unnamed>"),
        table.fields.len(),
        table.numeric_columns(),
        table.string_columns(),
        table.rows.len(),
        table.data_id_method
    );
    for row in rows {
        let Some(cells) = table.rows.get(row) else {
            println!("row {row:<3}: out of range");
            continue;
        };
        for column in 0..table.fields.len() {
            match table.value(cells, column) {
                Some(RowValue::Num(value)) => println!("row {row:<3} col {column:<3} num {value}"),
                Some(RowValue::Str(text)) => {
                    println!("row {row:<3} col {column:<3} str {text:?}")
                }
                None => println!("row {row:<3} col {column:<3} absent"),
            }
        }
    }
    Ok(())
}
