//! Dump the bytecode slots of one map event or one common event, for RE work.
//!
//! Usage:
//!   cargo run -q -p wolf-format --example dump_event -- map <Map.mps> <event_id>
//!   cargo run -q -p wolf-format --example dump_event -- common <CommonEvent.dat> <id>
use std::env;
fn print_slots(prefix: &str, slots: &[wolf_format::command::Slot]) {
    for (ci, slot) in slots.iter().enumerate() {
        match slot {
            wolf_format::command::Slot::Blank => {}
            wolf_format::command::Slot::Command(c) => {
                let words: Vec<String> = c
                    .params
                    .chunks_exact(4)
                    .map(|w| {
                        let v = i32::from_le_bytes([w[0], w[1], w[2], w[3]]);
                        format!("{}", v)
                    })
                    .collect();
                println!(
                    "  {}{:3} op={:3} args=[{}] strings={:?}",
                    prefix,
                    ci,
                    c.opcode,
                    words.join(","),
                    c.strings
                );
            }
        }
    }
}
fn main() {
    let mut args = env::args().skip(1);
    let mode = args.next().unwrap();
    let path = args.next().unwrap();
    let id: u32 = args.next().unwrap().parse().unwrap();
    let data = std::fs::read(&path).unwrap();
    if mode == "map" {
        let map = wolf_format::mps::Map::parse(&data).unwrap();
        for ev in &map.events {
            if ev.id != id {
                continue;
            }
            println!(
                "event {} name={:?} at ({},{}) pages={}",
                ev.id,
                ev.name,
                ev.x,
                ev.y,
                ev.pages.len()
            );
            for (pi, page) in ev.pages.iter().enumerate() {
                println!("-- page {} trigger={}", pi, page.trigger);
                print_slots("", &page.commands);
            }
        }
    } else if mode == "anchors" {
        let dat = wolf_format::commonevent::CommonEventData::parse(&data).unwrap();
        let want: i32 = std::env::var("ANCHOR")
            .ok()
            .and_then(|s| s.parse().ok())
            .unwrap_or(3);
        for ev in &dat.events {
            for (ci, slot) in ev.commands.iter().enumerate() {
                if let wolf_format::command::Slot::Command(c) = slot {
                    if c.opcode != 150 {
                        continue;
                    }
                    let words: Vec<i32> = c
                        .params
                        .chunks_exact(4)
                        .map(|w| i32::from_le_bytes([w[0], w[1], w[2], w[3]]))
                        .collect();
                    let head = words.first().copied().unwrap_or(0);
                    if ((head >> 12) & 7) == want {
                        println!(
                            "ce {} slot {} head={} args={:?} strings={:?}",
                            ev.id, ci, head, words, c.strings
                        );
                    }
                }
            }
        }
    } else if mode == "tones" {
        let dat = wolf_format::commonevent::CommonEventData::parse(&data).unwrap();
        for ev in &dat.events {
            for (ci, slot) in ev.commands.iter().enumerate() {
                if let wolf_format::command::Slot::Command(c) = slot {
                    if c.opcode != 150 {
                        continue;
                    }
                    let words: Vec<i32> = c
                        .params
                        .chunks_exact(4)
                        .map(|w| i32::from_le_bytes([w[0], w[1], w[2], w[3]]))
                        .collect();
                    if words.len() >= 18 {
                        println!(
                            "ce {} slot {} head={} tone={:?} args={:?} strings={:?}",
                            ev.id,
                            ci,
                            words[0],
                            &words[15..18],
                            words,
                            c.strings
                        );
                    }
                }
            }
        }
    } else if mode == "scan" {
        let dat = wolf_format::commonevent::CommonEventData::parse(&data).unwrap();
        let needle = std::env::var("NEEDLE").unwrap_or_else(|_| "<GRAD".into());
        for ev in &dat.events {
            for (ci, slot) in ev.commands.iter().enumerate() {
                if let wolf_format::command::Slot::Command(c) = slot {
                    if c.strings.iter().any(|s| s.contains(&needle)) {
                        let words: Vec<i32> = c
                            .params
                            .chunks_exact(4)
                            .map(|w| i32::from_le_bytes([w[0], w[1], w[2], w[3]]))
                            .collect();
                        println!(
                            "ce {} slot {} op={} args={:?} strings={:?}",
                            ev.id, ci, c.opcode, words, c.strings
                        );
                    }
                }
            }
        }
    } else {
        let dat = wolf_format::commonevent::CommonEventData::parse(&data).unwrap();
        for ev in &dat.events {
            if ev.id != id {
                continue;
            }
            println!(
                "common event {} title={:?} slots={}",
                ev.id,
                ev.title,
                ev.commands.len()
            );
            print_slots("", &ev.commands);
        }
    }
}
