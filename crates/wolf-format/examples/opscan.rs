//! Scan all maps for a set of opcodes: opscan <DATA_ROOT>

use std::fs;
use std::path::Path;

use wolf_format::command::Slot;
use wolf_format::mps::Map;

fn main() {
    let root = std::env::args()
        .nth(1)
        .unwrap_or_else(|| "work/full".to_owned());
    let dir = Path::new(&root).join("MapData");
    let mut names: Vec<_> = fs::read_dir(&dir)
        .unwrap()
        .filter_map(|e| e.ok())
        .map(|e| e.file_name())
        .filter(|n| n.to_string_lossy().ends_with(".mps"))
        .collect();
    names.sort();
    for name in names {
        let path = dir.join(&name);
        let Ok(bytes) = fs::read(&path) else { continue };
        let Ok(map) = Map::parse(&bytes) else {
            continue;
        };
        for event in &map.events {
            for (pi, page) in event.pages.iter().enumerate() {
                for (pc, slot) in page.commands.iter().enumerate() {
                    let Slot::Command(cmd) = slot else { continue };
                    if !matches!(cmd.opcode, 151 | 160 | 161 | 162) {
                        continue;
                    }
                    let ints: Vec<i32> = cmd
                        .params
                        .chunks_exact(4)
                        .map(|w| i32::from_le_bytes([w[0], w[1], w[2], w[3]]))
                        .collect();
                    println!(
                        "{} ev{} {:?} page{} pc{} op{} ints={:?} strings={:?}",
                        name.to_string_lossy(),
                        event.id,
                        event.name,
                        pi,
                        pc,
                        cmd.opcode,
                        ints,
                        cmd.strings
                    );
                }
            }
        }
    }
}
