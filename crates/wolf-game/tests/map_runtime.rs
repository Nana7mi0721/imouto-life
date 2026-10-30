//! The map runtime against the real game data.
//!
//! Skipped when the unpacked data is absent, like every other integration test.

use std::path::PathBuf;

use wolf_format::mps::Map;
use wolf_game::map_runtime::MapRuntime;
use wolf_vm::{Host, ProgramSet, Vm};

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/full".to_owned());
    let path = PathBuf::from(raw);
    if path.is_absolute() {
        path
    } else {
        let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        base.pop();
        base.pop();
        base.join(path)
    }
}

fn read_map(name: &str) -> Option<Map> {
    let bytes = std::fs::read(data_root().join("MapData").join(name)).ok()?;
    Map::parse(&bytes).ok()
}

#[test]
fn samplemapa_selects_one_page_per_event() {
    let Some(map) = read_map("SampleMapA.mps") else {
        eprintln!("skipping: no unpacked data");
        return;
    };
    let mut runtime = MapRuntime::collect(&map);
    let mut vm = Vm::new(ProgramSet::default());
    let started = runtime.start_pending(&mut vm);
    println!(
        "map {}x{} events {} tracked {}",
        map.width,
        map.height,
        map.events.len(),
        runtime.event_count()
    );
    println!(
        "active {} of {} tracked, triggers {:?}, started {started}",
        runtime.len(),
        runtime.event_count(),
        runtime.trigger_counts()
    );
    // Page selection is one page per event, so the count can never exceed the
    // number of events the map has.
    assert!(runtime.len() <= map.events.len());
    for slot in runtime.slots() {
        println!(
            "  event {:2} page {} trigger {:?} slots {}",
            slot.event,
            slot.page,
            slot.trigger,
            slot.program.len()
        );
    }
    assert!(!runtime.is_empty(), "no active event at all");
    let automatic = runtime
        .slots()
        .iter()
        .filter(|slot| slot.trigger.is_automatic())
        .count();
    assert_eq!(
        started, automatic,
        "every automatic active page started once"
    );
    for slot in runtime.slots() {
        // Action-key and player-touch pages stay dormant until an input layer
        // exists; every collected page must still carry a real program.
        assert!(!slot.program.is_empty());
    }
}

#[test]
fn a_variable_write_switches_the_active_page() {
    let Some(map) = read_map("SampleMapA.mps") else {
        eprintln!("skipping: no unpacked data");
        return;
    };
    // Event 15 is the measured nine-page state machine: page i is selected by
    // global variable 2000100. Pages 0..=4 and 6 take one exact value; pages 5,
    // 7 and 8 take a range (6..=7, 9..=10, 11..=12).
    let Some(event) = map.events.iter().find(|event| event.id == 15) else {
        eprintln!("skipping: SampleMapA has no event 15");
        return;
    };
    assert_eq!(event.pages.len(), 9, "event 15 lost pages");

    let mut runtime = MapRuntime::collect(&map);
    let mut vm = Vm::new(ProgramSet::default());
    // Global variable 100 = the variable half of magic 2000100.
    for (value, expected) in [(1i32, 0usize), (5, 4), (6, 5), (8, 6), (12, 8)] {
        vm.vars.set(100, value);
        runtime.start_pending(&mut vm);
        let page = runtime
            .active_pages(&vm)
            .into_iter()
            .find(|(id, _)| *id == 15)
            .and_then(|(_, page)| page);
        println!("global 100 = {value} -> event 15 page {page:?}");
        assert_eq!(page, Some(expected), "global 100 = {value}");
    }
    // Out of range matches no page: every page of event 15 wants 1..=12.
    vm.vars.set(100, 99);
    runtime.start_pending(&mut vm);
    let page = runtime
        .active_pages(&vm)
        .into_iter()
        .find(|(id, _)| *id == 15)
        .and_then(|(_, page)| page);
    println!(
        "global 100 = 99 -> event 15 page {page:?} switches {}",
        runtime.switches
    );
    assert_eq!(page, None, "no page of event 15 asks for 99");
}

#[test]
fn parallel_pages_restart_when_their_stream_ends() {
    let Some(map) = read_map("SampleMapA.mps") else {
        eprintln!("skipping: no unpacked data");
        return;
    };
    let mut runtime = MapRuntime::collect_except(&map, Some(0));
    let mut vm = Vm::new(ProgramSet::default());
    let mut host = Quiet;
    runtime.start_pending(&mut vm);
    assert!(
        runtime.slots().iter().all(|slot| slot.event != 0),
        "the skipped boot event must not be collected"
    );
    assert!(
        runtime.trigger_counts().contains_key(&2),
        "parallel pages must be collected"
    );
    let mut instructions = 0usize;
    for _ in 0..120 {
        runtime.start_pending(&mut vm);
        let report = vm.step_frame(&mut host);
        instructions += report.steps;
    }
    println!(
        "frames 120 instructions {instructions} starts {} switches {} active {}",
        runtime.restarts,
        runtime.switches,
        runtime.len()
    );
    assert!(
        runtime.restarts > runtime.len() as u64,
        "parallel pages never restarted"
    );
    assert!(instructions > 0);
}

struct Quiet;

impl Host for Quiet {}
