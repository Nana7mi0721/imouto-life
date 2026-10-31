//! M3-AM: static call graph and reachability audit for this game's 350 common
//! events plus the five maps registered in SysDatabase type 0.
//!
//! The test is data-driven: with no data root it prints a skip line and returns,
//! so cargo test -q --workspace stays green.

use std::collections::{BTreeMap, BTreeSet, VecDeque};
use std::path::PathBuf;

use wolf_format::command::{Command, Slot};
use wolf_format::commonevent::CommonEventData;
use wolf_format::mps::Map;
use wolf_format::sysdatabase::SysDatabase;

// The event engine starts these itself; duplicated here because this crate must
// not depend on wolf-game. Sources:
//   crates/wolf-game/src/game.rs:61-69  ENGINE_ALWAYS
//   crates/wolf-game/src/game.rs:82     ENGINE_AUTO_START
//   crates/wolf-game/src/game.rs:87     ENGINE_IMPLICIT
const ENGINE_ROOTS: &[u32] = &[48, 261, 269, 270, 271, 214, 216, 241, 63];
// crates/wolf-game/src/auto_events.rs:52/68. Event 43 is a documented dead
// title variant; 242/243 are condition-gated call-only events.
const SCHEDULER_SKIPPED: &[u32] = &[43];
const GATED_CALL_ONLY: &[u32] = &[242, 243];

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

fn args(cmd: &Command) -> Vec<i32> {
    cmd.params
        .chunks_exact(4)
        .map(|c| i32::from_le_bytes([c[0], c[1], c[2], c[3]]))
        .collect()
}

fn target(raw: i32) -> Option<u32> {
    match raw {
        500_000..=599_999 => Some((raw - 500_000) as u32),
        600_000..=699_999 => Some((raw - 600_000) as u32),
        _ => None,
    }
}

// A local copy of wolf-vm's Magic classification. This test crate does not
// depend on wolf-vm, but op210/211 put their target in the first argument and
// the storage flag decides whether it can be decoded statically.
fn kind(raw: i32) -> &'static str {
    let flags = (raw >> 28) as u8 & 0x0F;
    let body = raw & 0x0FFF_FFFF;
    if flags != 0 {
        if (1_000_000..3_000_000).contains(&body) {
            kind0(body)
        } else {
            "Opaque"
        }
    } else {
        kind0(body)
    }
}
fn kind0(body: i32) -> &'static str {
    match body {
        0..=999_999 => "Literal",
        1_000_000..2_000_000 => "SelfVar",
        2_000_000..3_000_000 => "Var",
        3_000_000..4_000_000 => "StrVar",
        9_000_000..=9_999_999 => "SysVar",
        _ => "Opaque",
    }
}
fn is_storage(raw: i32) -> bool {
    !matches!(kind(raw), "Literal" | "Opaque")
}

#[derive(Default, Debug)]
struct Calls {
    op210: BTreeSet<u32>,
    op211: BTreeSet<u32>,
    names: BTreeMap<String, usize>,
    op210_calls: usize,
    op211_calls: usize,
    op300_calls: usize,
    dyn210: usize,
    dyn211: usize,
}

fn scan(slots: &[Slot], out: &mut Calls) {
    for slot in slots {
        let Slot::Command(c) = slot else { continue };
        match c.opcode {
            210 => {
                out.op210_calls += 1;
                let raw = args(c).first().copied().unwrap_or(0);
                if is_storage(raw) {
                    out.dyn210 += 1;
                } else if let Some(t) = target(raw) {
                    out.op210.insert(t);
                }
            }
            211 => {
                out.op211_calls += 1;
                let raw = args(c).first().copied().unwrap_or(0);
                if is_storage(raw) {
                    out.dyn211 += 1;
                } else if let Some(t) = target(raw) {
                    out.op211.insert(t);
                }
            }
            300 => {
                out.op300_calls += 1;
                if let Some(s) = c.strings.first() {
                    *out.names.entry(s.clone()).or_insert(0) += 1;
                }
            }
            _ => {}
        }
    }
}

fn resolve_name(index: &BTreeMap<String, Vec<u32>>, name: &str) -> Option<u32> {
    match index.get(name) {
        Some(v) if v.len() == 1 => Some(v[0]),
        _ => None,
    }
}

fn bfs(
    edges: &BTreeMap<u32, BTreeSet<u32>>,
    roots: &BTreeSet<u32>,
    all: &BTreeSet<u32>,
) -> BTreeSet<u32> {
    let mut seen = BTreeSet::new();
    let mut q = VecDeque::new();
    for &r in roots {
        if all.contains(&r) && seen.insert(r) {
            q.push_back(r);
        }
    }
    while let Some(n) = q.pop_front() {
        if let Some(next) = edges.get(&n) {
            for &m in next {
                if all.contains(&m) && seen.insert(m) {
                    q.push_back(m);
                }
            }
        }
    }
    seen
}

fn own(id: u32) -> bool {
    (212..=303).contains(&id)
}

fn sorted(set: &BTreeSet<u32>) -> Vec<u32> {
    set.iter().copied().collect()
}

#[test]
fn event_graph() {
    let dir = data_root();
    let ce_path = dir.join("BasicData/CommonEvent.dat");
    if !ce_path.is_file() {
        eprintln!("skipping: {} not found", ce_path.display());
        return;
    }
    let bytes = std::fs::read(&ce_path).unwrap();
    let ce = CommonEventData::parse(&bytes).unwrap();
    let all: BTreeSet<u32> = ce.events.iter().map(|e| e.id).collect();
    let hist = ce.run_condition_histogram();

    let mut titles: BTreeMap<String, Vec<u32>> = BTreeMap::new();
    for e in &ce.events {
        titles.entry(e.title.clone()).or_default().push(e.id);
    }

    let mut edges_core: BTreeMap<u32, BTreeSet<u32>> = BTreeMap::new();
    let mut edges_all: BTreeMap<u32, BTreeSet<u32>> = BTreeMap::new();
    let mut op210_total = 0usize;
    let mut op210_dyn = 0usize;
    let mut op211_total = 0usize;
    let mut op300_total = 0usize;
    let mut op300_resolved = 0usize;
    let mut op300_ambiguous = 0usize;
    let mut op300_unknown = 0usize;
    let mut op300_unknown_names: BTreeMap<String, usize> = BTreeMap::new();

    for e in &ce.events {
        let mut c = Calls::default();
        scan(&e.commands, &mut c);
        op210_total += c.op210_calls;
        op210_dyn += c.dyn210;
        op211_total += c.op211_calls;
        op300_total += c.op300_calls;

        let mut core: BTreeSet<u32> = c.op210.iter().chain(c.op211.iter()).copied().collect();
        let mut extra: BTreeSet<u32> = BTreeSet::new();
        for name in c.names.keys() {
            match resolve_name(&titles, name) {
                Some(id) => {
                    extra.insert(id);
                    op300_resolved += 1;
                }
                None => {
                    if titles.contains_key(name) {
                        op300_ambiguous += 1;
                    } else {
                        op300_unknown += 1;
                        *op300_unknown_names.entry(name.clone()).or_insert(0) += 1;
                    }
                }
            }
        }
        core.extend(extra.iter().copied());
        edges_core.insert(e.id, core.clone());
        let mut both = core;
        both.extend(extra);
        edges_all.insert(e.id, both);
    }

    // Registered maps: roots, not CE->CE edges. A map event id is not a common
    // event id, so mixing map events into the edge map would create false callers.
    let sysb = std::fs::read(dir.join("BasicData/SysDatabase.dat")).unwrap();
    let sys = SysDatabase::parse(&sysb).unwrap();
    let maps: Vec<String> = (0..sys.row_count(SysDatabase::MAP_SETTINGS_TYPE))
        .filter_map(|r| {
            sys.text(SysDatabase::MAP_SETTINGS_TYPE, r, 0)
                .map(|s| s.to_owned())
        })
        .filter(|s| !s.is_empty())
        .collect();
    let mut map_roots_core: BTreeSet<u32> = BTreeSet::new();
    let mut map_roots_all: BTreeSet<u32> = BTreeSet::new();
    let mut map_roots_active0: BTreeSet<u32> = BTreeSet::new();
    let mut map_events = 0usize;
    let mut map_pages = 0usize;
    let mut map_op210 = 0usize;
    for mp in &maps {
        let mb = std::fs::read(dir.join(mp)).unwrap();
        let map = Map::parse(&mb).unwrap();
        println!(
            "map {mp}: events={} pages={} w={} h={}",
            map.events.len(),
            map.events.iter().map(|e| e.pages.len()).sum::<usize>(),
            map.width,
            map.height
        );
        for e in &map.events {
            map_events += 1;
            map_pages += e.pages.len();
            for pg in &e.pages {
                let mut c = Calls::default();
                scan(&pg.commands, &mut c);
                map_op210 += c.op210_calls;
                let core: BTreeSet<u32> = c.op210.iter().chain(c.op211.iter()).copied().collect();
                map_roots_core.extend(core.iter().copied());
                map_roots_all.extend(core.iter().copied());
                for name in c.names.keys() {
                    if let Some(id) = resolve_name(&titles, name) {
                        map_roots_all.insert(id);
                    }
                }
            }
            if let Some(ix) = e.active_page_index(|_| 0) {
                let mut c = Calls::default();
                scan(&e.pages[ix].commands, &mut c);
                map_roots_active0.extend(c.op210.iter().chain(c.op211.iter()).copied());
                for name in c.names.keys() {
                    if let Some(id) = resolve_name(&titles, name) {
                        map_roots_active0.insert(id);
                    }
                }
            }
        }
    }
    let map_state_gated: BTreeSet<u32> = map_roots_all
        .difference(&map_roots_active0)
        .copied()
        .collect();
    println!(
        "registered_maps={maps:?} map_events={map_events} map_pages={map_pages} map_op210_calls={map_op210}"
    );
    println!("MAP_ROOTS_ACTIVE0={:?}", sorted(&map_roots_active0));
    println!("MAP_ROOTS_ALL={:?}", sorted(&map_roots_all));
    println!("MAP_STATE_GATED={:?}", sorted(&map_state_gated));

    let engine_roots: BTreeSet<u32> = ENGINE_ROOTS.iter().copied().collect();
    let mut roots_core = engine_roots.clone();
    roots_core.extend(map_roots_core.iter().copied());
    let mut roots_all = engine_roots.clone();
    roots_all.extend(map_roots_all.iter().copied());
    if ce.event(42).is_some() {
        roots_core.insert(42);
        roots_all.insert(42);
    }

    let reachable_core = bfs(&edges_core, &roots_core, &all);
    let reachable_call = bfs(&edges_all, &roots_all, &all);

    // run_condition == 2 events are started by AutoEvents, not by a call opcode.
    let mut scheduler: BTreeSet<u32> = ce
        .events
        .iter()
        .filter(|e| e.run_condition() == 2 && !SCHEDULER_SKIPPED.contains(&e.id))
        .map(|e| e.id)
        .collect();
    for id in GATED_CALL_ONLY {
        if all.contains(id) {
            scheduler.insert(*id);
        }
    }
    let mut runtime_roots = roots_all.clone();
    runtime_roots.extend(scheduler.iter().copied());
    let reachable_runtime = bfs(&edges_all, &runtime_roots, &all);

    println!(
        "events={} min={:?} max={:?} run_condition_hist={:?} CE549={}",
        ce.events.len(),
        all.iter().next(),
        all.iter().next_back(),
        hist,
        ce.event(549).is_some()
    );
    println!(
        "op210 calls={op210_total} dynamic={op210_dyn}; op211 calls={op211_total}; op300 calls={op300_total} resolved={op300_resolved} ambiguous={op300_ambiguous} unknown={op300_unknown}"
    );
    println!(
        "op300_unknown_names={:?}",
        op300_unknown_names.iter().collect::<Vec<_>>()
    );
    println!(
        "reachable: core={} call_allpages={} runtime={} scheduler={}",
        reachable_core.len(),
        reachable_call.len(),
        reachable_runtime.len(),
        scheduler.len()
    );

    let unreachable_own = |set: &BTreeSet<u32>| -> Vec<u32> {
        (212..=303)
            .filter(|id| all.contains(id) && !set.contains(id))
            .collect()
    };
    let un_core = unreachable_own(&reachable_core);
    let un_call = unreachable_own(&reachable_call);
    let un_runtime = unreachable_own(&reachable_runtime);
    println!("UNREACHABLE_CORE={un_core:?}");
    println!("UNREACHABLE_CALL={un_call:?}");
    println!("UNREACHABLE_RUNTIME={un_runtime:?}");
    for id in (212..=303).filter(|id| all.contains(id) && !reachable_call.contains(id)) {
        let ev = ce.event(id).unwrap();
        let inc = edges_all
            .iter()
            .filter(|(_, dst)| dst.contains(&id))
            .count();
        println!(
            "UNREACHABLE_ROW\t{id}\t{}\t{}\t{inc}\t{}\t{}",
            ev.title,
            ev.run_condition(),
            scheduler.contains(&id),
            reachable_runtime.contains(&id)
        );
    }
    println!(
        "own_total={} own_call_reachable={} own_runtime_reachable={}",
        (212..=303).filter(|id| all.contains(id)).count(),
        reachable_call.iter().filter(|&&id| own(id)).count(),
        reachable_runtime.iter().filter(|&&id| own(id)).count()
    );
    let scheduler_only: Vec<u32> = scheduler
        .iter()
        .copied()
        .filter(|&id| own(id) && !reachable_call.contains(&id))
        .collect();
    println!(
        "scheduler_own={:?} scheduler_only={:?}",
        scheduler
            .iter()
            .copied()
            .filter(|&id| own(id))
            .collect::<Vec<_>>(),
        scheduler_only
    );

    // One stable, machine-readable line per event that has outgoing CE calls.
    for (id, outs) in &edges_all {
        if outs.is_empty() {
            continue;
        }
        let title = ce.event(*id).map(|e| e.title.as_str()).unwrap_or("?");
        println!(
            "OUTGOING\t{id}\t{title}\t{}",
            sorted(outs)
                .iter()
                .map(u32::to_string)
                .collect::<Vec<_>>()
                .join(",")
        );
    }

    let incoming = |id: u32| -> Vec<u32> {
        edges_all
            .iter()
            .filter(|(_, dst)| dst.contains(&id))
            .map(|(src, _)| *src)
            .collect()
    };
    for id in [224u32, 225, 226, 228, 229, 237, 212, 42, 43, 242, 243, 549] {
        println!(
            "CHECK\tCE{id}\texists={}\tcond={:?}\tcall_reachable={}\tscheduler={}\truntime={}\tcallers={:?}",
            ce.event(id).is_some(),
            ce.event(id).map(|e| e.run_condition()),
            reachable_call.contains(&id),
            scheduler.contains(&id),
            reachable_runtime.contains(&id),
            incoming(id)
        );
    }

    // ---- Regression assertions (measured M0 baseline, 350 events) ----
    assert_eq!(ce.events.len(), 350);
    assert_eq!(all.iter().next(), Some(&0));
    assert_eq!(all.iter().next_back(), Some(&349));
    assert_eq!(hist.get(&0), Some(&312));
    assert_eq!(hist.get(&2), Some(&31));
    assert_eq!(hist.get(&3), Some(&7));
    assert!(ce.event(42).is_some(), "title event CE42 missing");
    assert!(ce.event(549).is_none(), "CE549 unexpectedly exists");

    assert_eq!(map_events, 40);
    assert_eq!(map_pages, 83);
    assert_eq!(map_op210, 829);
    let expected_active0: BTreeSet<u32> = [
        5, 14, 42, 228, 238, 239, 240, 242, 243, 244, 245, 264, 296, 303,
    ]
    .into_iter()
    .collect();
    assert_eq!(map_roots_active0, expected_active0);
    let expected_all: BTreeSet<u32> = [
        5, 14, 42, 219, 220, 227, 228, 230, 238, 239, 240, 242, 243, 244, 245, 251, 256, 259, 264,
        283, 296, 303,
    ]
    .into_iter()
    .collect();
    assert_eq!(map_roots_all, expected_all);
    let expected_state_gated: BTreeSet<u32> = [219, 220, 227, 230, 251, 256, 259, 283]
        .into_iter()
        .collect();
    assert_eq!(map_state_gated, expected_state_gated);

    assert_eq!(op210_total, 2869);
    assert_eq!(op210_dyn, 10);
    assert_eq!(op211_total, 4);
    assert_eq!(op300_total, 1158);
    assert_eq!(op300_unknown, 2);

    assert_eq!(reachable_core.len(), 126);
    assert_eq!(reachable_call.len(), 126);
    assert_eq!(reachable_runtime.len(), 152);
    assert_eq!(scheduler.len(), 30);

    let expected_un_call: Vec<u32> = vec![
        212, 213, 215, 217, 218, 221, 222, 223, 224, 225, 226, 229, 231, 232, 233, 234, 235, 236,
        237, 265, 266, 267, 268, 272, 273, 274, 277, 278, 279, 281, 282, 284, 285, 286, 287, 288,
        289, 291, 292, 294, 299, 301,
    ];
    assert_eq!(un_call, expected_un_call);
    let expected_un_runtime: Vec<u32> = vec![
        212, 213, 217, 218, 221, 222, 236, 265, 266, 267, 268, 272, 289, 291, 292, 301,
    ];
    assert_eq!(un_runtime, expected_un_runtime);
    assert_eq!(scheduler_only.len(), 26);

    // The anchors called out by task-32 are background scheduler events, not
    // orphans: no call edge, but AutoEvents starts them from run_condition == 2.
    for id in [224u32, 225, 226, 229, 237] {
        assert!(
            !reachable_call.contains(&id),
            "CE{id} unexpectedly call reachable"
        );
        assert!(
            scheduler.contains(&id),
            "CE{id} missing from scheduler roots"
        );
        assert!(
            reachable_runtime.contains(&id),
            "CE{id} not runtime reachable"
        );
        assert!(
            incoming(id).is_empty(),
            "CE{id} unexpectedly has a CE caller"
        );
    }
    // CE228 is genuinely wired in from Map031 event 0 page 0 (active page).
    assert!(reachable_call.contains(&228));
    assert!(incoming(228).is_empty());

    // CE212 is a parameterised helper: no static call site at all.
    assert!(!reachable_call.contains(&212));
    assert!(incoming(212).is_empty());
    // CE43 is the documented dead title variant excluded by auto_events.rs.
    assert!(!reachable_runtime.contains(&43));
}
