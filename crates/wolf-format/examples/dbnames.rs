//! Print the .project row names of one database type.
//!
//! cargo run -q -p wolf-format --example dbnames -- [DATA_ROOT] [FILE] [TYPE]

use std::{env, fs, path::PathBuf, process::ExitCode};

use wolf_format::database::{Database, ProjectNames};

fn main() -> ExitCode {
    let mut args = env::args().skip(1);
    let root = PathBuf::from(args.next().unwrap_or_else(|| "work/full".into()));
    let file = args.next().unwrap_or_else(|| "CDataBase".into());
    let ty: usize = args.next().and_then(|v| v.parse().ok()).unwrap_or(0);

    let dat = root.join("BasicData").join(format!("{file}.dat"));
    let project = root.join("BasicData").join(format!("{file}.project"));
    let Ok(bytes) = fs::read(&dat) else {
        eprintln!("cannot read {}", dat.display());
        return ExitCode::FAILURE;
    };
    let Ok(mut db) = Database::parse(&bytes) else {
        eprintln!("cannot parse {}", dat.display());
        return ExitCode::FAILURE;
    };
    if let Ok(p) = fs::read(&project) {
        let names = ProjectNames::parse(&p, db.types.len());
        db.apply_project_names(&p);
        println!("project names: {} record(s)", names.len());
    }
    let Some(t) = db.types.get(ty) else {
        eprintln!("type {ty} missing");
        return ExitCode::FAILURE;
    };
    println!("type {ty}: {} — {} row(s)", db.type_name(ty).unwrap_or("<unnamed>"), t.rows.len());
    for row in 0..t.rows.len() {
        println!("  row {row:>3} name {:?}", db.row_name(ty, row).unwrap_or("<none>"));
    }
    ExitCode::SUCCESS
}
