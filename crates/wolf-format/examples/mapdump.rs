//! Dump one map event's command stream with its strings decoded.
//!
//! `cargo run -q -p wolf-format --example mapdump -- <DATA_ROOT> <MAP> <EVENT> [FROM] [TO]`

use std::fs;
use std::path::Path;

use wolf_format::mps::Map;

fn main() {
    let mut args = std::env::args().skip(1);
    let root = args.next().unwrap_or_else(|| "work/full".to_owned());
    let map = args.next().unwrap_or_else(|| "SampleMapA.mps".to_owned());
    let event: u32 = args.next().and_then(|v| v.parse().ok()).unwrap_or(0);
    let from: usize = args.next().and_then(|v| v.parse().ok()).unwrap_or(0);
    let to: usize = args
        .next()
        .and_then(|v| v.parse().ok())
        .unwrap_or(usize::MAX);
    let path = Path::new(&root).join("MapData").join(&map);
    let bytes = match fs::read(&path) {
        Ok(bytes) => bytes,
        Err(err) => {
            eprintln!("cannot read {}: {err}", path.display());
            std::process::exit(2);
        }
    };
    let parsed = match Map::parse(&bytes) {
        Ok(map) => map,
        Err(err) => {
            eprintln!("cannot parse {}: {err}", path.display());
            std::process::exit(2);
        }
    };
    let Some(found) = parsed.events.iter().find(|e| e.id == event) else {
        eprintln!("map {map} has no event {event}");
        std::process::exit(2);
    };
    for (index, page) in found.pages.iter().enumerate() {
        println!(
            "page {index}: trigger {} commands {}",
            page.trigger,
            page.commands.len()
        );
        for (pc, slot) in page.commands.iter().enumerate() {
            if pc < from || pc > to {
                continue;
            }
            let wolf_format::command::Slot::Command(cmd) = slot else {
                println!("{pc:>4} ----");
                continue;
            };
            let ints: Vec<i32> = cmd
                .params
                .chunks_exact(4)
                .map(|word| i32::from_le_bytes([word[0], word[1], word[2], word[3]]))
                .collect();
            println!("{pc:>4} {:<4} {:?} {:?}", cmd.opcode, ints, cmd.strings);
        }
    }
}
