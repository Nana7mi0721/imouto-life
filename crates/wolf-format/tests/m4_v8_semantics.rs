//! M4 v8 semantics: normal variable 8 is the night time limit, not action points.
//!
//! Static audit of `BasicData/CommonEvent.dat`. See docs/M4_V8_AUDIT.md.
use std::collections::BTreeSet;
use std::path::PathBuf;

use wolf_format::command::{Command, Slot};
use wolf_format::commonevent::CommonEventData;

const VAR8: i64 = 2_000_008;

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let p = PathBuf::from(raw);
    if p.is_absolute() {
        return p;
    }
    let mut b = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    b.pop();
    b.pop();
    b.join(p)
}

fn load() -> Option<CommonEventData> {
    let path = data_root().join("BasicData/CommonEvent.dat");
    if !path.is_file() {
        eprintln!("skipping: missing {}", path.display());
        return None;
    }
    Some(CommonEventData::parse(&std::fs::read(path).unwrap()).unwrap())
}

fn args(c: &Command) -> Vec<i64> {
    c.params
        .chunks_exact(4)
        .map(|x| i32::from_le_bytes([x[0], x[1], x[2], x[3]]) as i64)
        .collect()
}

fn body(raw: i64) -> i64 {
    raw & 0x0fff_ffff
}

#[derive(Debug, PartialEq, Eq)]
struct Write {
    event: u32,
    pc: usize,
    value: i64,
    kind: i64,
}

#[derive(Debug, PartialEq, Eq)]
struct Cond {
    event: u32,
    pc: usize,
    value: i64,
    cmp: i64,
}

fn writes_to_var8(ce: &CommonEventData) -> Vec<Write> {
    let mut out = Vec::new();
    for ev in &ce.events {
        for (pc, slot) in ev.commands.iter().enumerate() {
            let Slot::Command(c) = slot else { continue };
            if c.opcode != 121 {
                continue;
            }
            let a = args(c);
            if a.first().map(|x| body(*x)) != Some(VAR8) {
                continue;
            }
            out.push(Write {
                event: ev.id,
                pc,
                value: a.get(1).copied().unwrap_or(0),
                kind: a.get(3).copied().unwrap_or(0),
            });
        }
    }
    out
}

fn conds_on_var8(ce: &CommonEventData) -> Vec<Cond> {
    let mut out = Vec::new();
    for ev in &ce.events {
        for (pc, slot) in ev.commands.iter().enumerate() {
            let Slot::Command(c) = slot else { continue };
            if c.opcode != 111 {
                continue;
            }
            let a = args(c);
            let n = a.first().copied().unwrap_or(0).max(0) as usize;
            for i in 0..n {
                let Some(raw) = a.get(1 + i * 3) else { break };
                if body(*raw) == VAR8 {
                    out.push(Cond {
                        event: ev.id,
                        pc,
                        value: a.get(2 + i * 3).copied().unwrap_or(0),
                        cmp: a.get(3 + i * 3).copied().unwrap_or(0),
                    });
                }
            }
        }
    }
    out
}

#[test]
fn var8_is_written_only_by_the_clock_and_night_events() {
    let Some(ce) = load() else { return };
    let writes = writes_to_var8(&ce);
    let events: BTreeSet<u32> = writes.iter().map(|w| w.event).collect();
    assert_eq!(
        events,
        BTreeSet::from([243, 245, 251]),
        "unexpected v8 writer: {writes:?}"
    );
    let conds = conds_on_var8(&ce);
    let cond_events: BTreeSet<u32> = conds.iter().map(|c| c.event).collect();
    assert_eq!(
        cond_events,
        BTreeSet::from([245, 246]),
        "unexpected v8 reader: {conds:?}"
    );
}

#[test]
fn clock_and_bedtime_reset_write_literal_limits() {
    let Some(ce) = load() else { return };
    let writes = writes_to_var8(&ce);
    let literal = |event: u32, pc: usize, value: i64| {
        assert!(
            writes.iter().any(|w| w
                == &Write {
                    event,
                    pc,
                    value,
                    kind: 0
                }),
            "missing {event}:{pc}={value} in {writes:?}"
        );
    };
    // CE243 時刻表示: weekend / late-night branches raise the limit to 25:00.
    literal(243, 52, 25);
    literal(243, 57, 25);
    // CE251 就寝: reset for the next day. vars 10/11/12 decide 24 vs 23.
    literal(251, 174, 24);
    literal(251, 177, 23);
    literal(251, 180, 23);
    literal(251, 183, 24);
}

#[test]
fn drinks_extend_the_night_limit_by_one_or_two_hours() {
    let Some(ce) = load() else { return };
    let writes = writes_to_var8(&ce);
    // compound 0x100 = add. CE245 pc399 coffee +2, pc432 tea +1.
    assert!(
        writes.iter().any(|w| w
            == &Write {
                event: 245,
                pc: 399,
                value: 2,
                kind: 0x100
            }),
        "{writes:?}"
    );
    assert!(
        writes.iter().any(|w| w
            == &Write {
                event: 245,
                pc: 432,
                value: 1,
                kind: 0x100
            }),
        "{writes:?}"
    );
}

#[test]
fn night_command_and_communication_gate_on_the_limit() {
    let Some(ce) = load() else { return };
    let conds = conds_on_var8(&ce);
    for (event, pc, values) in [
        (245u32, 58usize, vec![24i64, 25]),
        (246, 128, vec![24, 25, 26]),
    ] {
        let got: Vec<i64> = conds
            .iter()
            .filter(|c| c.event == event && c.pc == pc)
            .map(|c| c.value)
            .collect();
        assert_eq!(got, values, "CE{event}:{pc} conditions differ in {conds:?}");
        assert!(
            conds
                .iter()
                .filter(|c| c.event == event && c.pc == pc)
                .all(|c| c.cmp == 2),
            "expected equality comparisons"
        );
    }
}

#[test]
fn every_literal_limit_is_a_valid_extended_clock_hour() {
    let Some(ce) = load() else { return };
    for w in writes_to_var8(&ce) {
        if w.kind == 0 {
            assert!(
                (23..=26).contains(&w.value),
                "literal v8={} at CE{}:{} is not an extended clock hour",
                w.value,
                w.event,
                w.pc
            );
        } else {
            assert_eq!(
                w.kind, 0x100,
                "unexpected compound op at CE{}:{}",
                w.event, w.pc
            );
            assert!(
                (1..=2).contains(&w.value),
                "drink extension {} at CE{}:{}",
                w.value,
                w.event,
                w.pc
            );
        }
    }
}
