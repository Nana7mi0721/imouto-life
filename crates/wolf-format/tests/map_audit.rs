//! Integration test: the shipped maps match the audit written up in docs/MAP_AUDIT.md.
//!
//! Every expectation below was measured from work/full/MapData (the command index of
//! the audit doc, C1-C11, reproduces each number) and cross-checked against
//! docs/BASELINE.json. Tests skip cleanly when the game data is not installed, so the
//! crate still builds and tests green on a machine without work/full.

use std::collections::BTreeMap;
use std::path::PathBuf;

use wolf_format::command::Slot;
use wolf_format::mps::{Map, MapEvent};

/// Teleport opcode; docs/OPCODE_SPEC.md section 5.17.
const OPCODE_TELEPORT: u32 = 130;

/// Page terminator accepted in addition to 0x7A, see docs/FORMAT_SPEC.md section 5.6.1.
const TOLERATED_PAGE_FOOTER: u8 = 0x00;

/// Data root, resolved the way wolf-cli does it (see tests/mps.rs).
fn data_root() -> PathBuf {
    let raw = match std::env::var("WOLF_DATA_ROOT") {
        Ok(value) if !value.is_empty() => PathBuf::from(value),
        _ => PathBuf::from("work/full"),
    };
    if raw.is_absolute() {
        return raw;
    }
    let manifest = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    let workspace = manifest
        .parent()
        .and_then(|crates| crates.parent())
        .unwrap_or(&manifest);
    let candidate = workspace.join(&raw);
    if candidate.is_dir() {
        candidate
    } else {
        raw
    }
}

fn load_map(name: &str) -> Option<Map> {
    let path = data_root().join("MapData").join(name);
    let data = std::fs::read(&path).ok()?;
    match Map::parse(&data) {
        Ok(map) => Some(map),
        Err(error) => panic!("{} did not parse: {error}", path.display()),
    }
}

/// The six maps registered in SysDatabase type 0 plus the three orphans, in the order
/// the audit doc lists them.
const SHIPPED: [&str; 9] = [
    "TitleMap.mps",
    "SampleMapA.mps",
    "SampleMapA_1.mps",
    "Map003.mps",
    "Map024.mps",
    "Map031.mps",
    "SampleMapB.mps",
    "Dungeon.mps",
    "Map002.mps",
];

/// The six maps registered in SysDatabase type 0 (map ids 0, 1, 2, 3, 24, 31).
const REGISTERED: [&str; 6] = [
    "TitleMap.mps",
    "SampleMapA.mps",
    "SampleMapA_1.mps",
    "Map003.mps",
    "Map024.mps",
    "Map031.mps",
];

fn load_shipped() -> Option<Vec<(&'static str, Map)>> {
    let mut maps = Vec::with_capacity(SHIPPED.len());
    for name in SHIPPED {
        maps.push((name, load_map(name)?));
    }
    Some(maps)
}

fn page_count(map: &Map) -> usize {
    map.events.iter().map(|event| event.pages.len()).sum()
}

fn shapes(
    game: &[(&'static str, Map)],
) -> Vec<(&'static str, u32, u32, u32, bool, usize, usize, usize)> {
    game.iter()
        .map(|(name, map)| {
            (
                *name,
                map.width,
                map.height,
                map.tileset_index,
                map.has_tile_data,
                map.events.len(),
                page_count(map),
                map.stats().slots,
            )
        })
        .collect()
}

/// width, height, tileset index, has tile data, events, pages, slots (audit doc 1.2).
const EXPECTED_SHAPES: [(&str, u32, u32, u32, bool, usize, usize, usize); 9] = [
    ("TitleMap.mps", 53, 30, 4, true, 1, 1, 133),
    ("SampleMapA.mps", 64, 36, 4, true, 40, 93, 31083),
    ("SampleMapA_1.mps", 64, 36, 4, true, 12, 17, 5752),
    ("Map003.mps", 70, 170, 4, true, 2, 2, 45),
    ("Map024.mps", 53, 30, 4, false, 1, 1, 3),
    ("Map031.mps", 53, 30, 0, false, 1, 1, 63),
    ("SampleMapB.mps", 30, 30, 0, true, 6, 6, 36),
    ("Dungeon.mps", 40, 30, 0, true, 5, 6, 79),
    ("Map002.mps", 100, 30, 4, true, 5, 7, 416),
];

#[test]
fn shipped_maps_match_the_audited_shapes() {
    let Some(game) = load_shipped() else {
        eprintln!("skipping: no map data under {}", data_root().display());
        return;
    };
    let actual = shapes(&game);
    let expected: Vec<(&str, u32, u32, u32, bool, usize, usize, usize)> = EXPECTED_SHAPES.to_vec();
    assert_eq!(
        actual, expected,
        "map shapes drifted from docs/MAP_AUDIT.md section 1.2"
    );

    let mut events = 0;
    let mut pages = 0;
    let mut slots = 0;
    let mut stats = wolf_format::command::SlotStats::default();
    for (name, map) in &game {
        events += map.events.len();
        pages += page_count(map);
        slots += map.stats().slots;
        stats.merge(&map.stats());
        assert_eq!(map.footer, 0x66, "{name} footer");
        assert_eq!(map.version, 0x66, "{name} version");
    }
    assert_eq!(
        (events, pages, slots),
        (73, 134, 37610),
        "docs/BASELINE.json totals"
    );
    assert_eq!(stats.blank(), 7052);
    assert_eq!(stats.real(), 30558);
    assert_eq!(
        stats.distinct_opcodes(),
        40,
        "docs/BASELINE.json distinct_opcodes"
    );
}

#[test]
fn tile_layers_are_three_or_absent() {
    let Some(game) = load_shipped() else {
        eprintln!("skipping: no map data under {}", data_root().display());
        return;
    };
    for (name, map) in &game {
        if map.has_tile_data {
            assert_eq!(
                map.layers.len(),
                wolf_format::mps::LAYER_COUNT,
                "{name} layers"
            );
            for layer in &map.layers {
                assert_eq!(
                    layer.len(),
                    (map.width as usize) * (map.height as usize),
                    "{name} layer length"
                );
            }
            assert!(
                map.tile(0, 0, 0).is_some(),
                "{name} tile accessor works when tiles exist"
            );
        } else {
            assert!(map.layers.is_empty(), "{name} must not carry layers");
            assert_eq!(
                map.tile(0, 0, 0),
                None,
                "{name} tile accessor on a tile-less map"
            );
        }
    }
    // Audit doc section 1.4: exactly these two maps lost their tile block.
    for name in ["Map024.mps", "Map031.mps"] {
        let map = game
            .iter()
            .find(|(file, _)| *file == name)
            .map(|(_, map)| map);
        assert_eq!(map.map(|map| map.has_tile_data), Some(false), "{name}");
    }
}

#[test]
fn trigger_histogram_matches_the_audit() {
    let Some(game) = load_shipped() else {
        eprintln!("skipping: no map data under {}", data_root().display());
        return;
    };
    let mut histogram: BTreeMap<u8, usize> = BTreeMap::new();
    for (_, map) in &game {
        for event in &map.events {
            for page in &event.pages {
                *histogram.entry(page.trigger).or_insert(0) += 1;
            }
        }
    }
    // Audit doc section 1.2: confirm 14, autorun 26, parallel 90, touch 4.
    assert_eq!(histogram.get(&0).copied().unwrap_or(0), 14, "confirm pages");
    assert_eq!(histogram.get(&1).copied().unwrap_or(0), 26, "autorun pages");
    assert_eq!(
        histogram.get(&2).copied().unwrap_or(0),
        90,
        "parallel pages"
    );
    assert_eq!(histogram.get(&3).copied().unwrap_or(0), 4, "touch pages");
    assert_eq!(histogram.len(), 4, "trigger byte 4 never appears");
}

/// Raw trigger_switches histogram, enabled-operator histogram, enabled slots, slots.
type ConditionStats = (BTreeMap<u8, usize>, BTreeMap<u8, usize>, usize, usize);

fn condition_histogram<'a>(game: impl IntoIterator<Item = &'a Map>) -> ConditionStats {
    let mut raw: BTreeMap<u8, usize> = BTreeMap::new();
    let mut operators: BTreeMap<u8, usize> = BTreeMap::new();
    let mut enabled = 0;
    let mut slots = 0;
    for map in game {
        for event in &map.events {
            for page in &event.pages {
                let conditions = page.conditions();
                for slot in 0..wolf_format::mps::CONDITION_SLOTS {
                    slots += 1;
                    *raw.entry(page.trigger_switches[slot]).or_insert(0) += 1;
                    if conditions[slot].enabled {
                        enabled += 1;
                        *operators.entry(conditions[slot].operator).or_insert(0) += 1;
                    }
                }
            }
        }
    }
    (raw, operators, enabled, slots)
}

#[test]
fn condition_slots_match_the_audit() {
    let Some(game) = load_shipped() else {
        eprintln!("skipping: no map data under {}", data_root().display());
        return;
    };
    let all = condition_histogram(game.iter().map(|(_, map)| map));
    // Audit doc section 2.2: 134 pages x 4 slots, 208 enabled.
    assert_eq!(all.3, 536, "condition slots over all nine maps");
    assert_eq!(all.2, 208, "enabled condition slots");
    assert_eq!(
        all.0,
        BTreeMap::from([
            (0x10, 2),
            (0x11, 25),
            (0x20, 324),
            (0x21, 173),
            (0x31, 3),
            (0x50, 2),
            (0x51, 7),
        ]),
        "raw trigger_switches bytes"
    );
    assert_eq!(
        all.1,
        BTreeMap::from([(1u8, 25), (2u8, 173), (3u8, 3), (5u8, 7)]),
        "enabled operators 1 >=, 2 ==, 3 <=, 5 != only"
    );

    let registered = condition_histogram(
        game.iter()
            .filter(|(name, _)| REGISTERED.contains(name))
            .map(|(_, map)| map),
    );
    assert_eq!(registered.3, 460);
    assert_eq!(registered.2, 201);
    assert_eq!(
        registered.1,
        BTreeMap::from([(1u8, 25), (2u8, 167), (3u8, 2), (5u8, 7)])
    );
}

#[test]
fn fresh_vm_activates_the_expected_pages() {
    let Some(game) = load_shipped() else {
        eprintln!("skipping: no map data under {}", data_root().display());
        return;
    };
    // (event id, page index, trigger, command count) at a fresh VM, all variables 0.
    // Audit doc section 3.
    let expected: [(&str, Vec<(u32, usize, u8, usize)>); 7] = [
        ("TitleMap.mps", vec![(2, 0, 1, 133)]),
        (
            "SampleMapA.mps",
            vec![
                (0, 0, 1, 846),
                (13, 0, 2, 2),
                (15, 0, 2, 295),
                (25, 0, 2, 34),
            ],
        ),
        (
            "SampleMapA_1.mps",
            vec![(1, 0, 2, 68), (2, 0, 2, 176), (3, 0, 2, 109)],
        ),
        ("Map003.mps", vec![(1, 0, 1, 43)]),
        ("Map024.mps", vec![]),
        ("Map031.mps", vec![(0, 0, 1, 63)]),
        (
            "SampleMapB.mps",
            vec![
                (0, 0, 3, 2),
                (1, 0, 0, 5),
                (2, 0, 3, 4),
                (3, 0, 0, 9),
                (4, 0, 0, 4),
                (5, 0, 0, 12),
            ],
        ),
    ];
    for (name, pages) in expected {
        let map = game
            .iter()
            .find(|(file, _)| *file == name)
            .map(|(_, map)| map)
            .unwrap_or_else(|| panic!("{name} missing"));
        let mut actual = Vec::new();
        for event in &map.events {
            if let Some(index) = event.active_page_index(|_| 0) {
                let page = &event.pages[index];
                actual.push((event.id, index, page.trigger, page.commands.len()));
            }
        }
        assert_eq!(actual, pages, "{name}: fresh-VM active pages");
    }
}

#[test]
fn global_62_selects_the_deep_night_pages() {
    let Some(game) = load_shipped() else {
        eprintln!("skipping: no map data under {}", data_root().display());
        return;
    };
    let map = game
        .iter()
        .find(|(file, _)| *file == "SampleMapA.mps")
        .map(|(_, map)| map)
        .expect("SampleMapA.mps");
    let first = map
        .events
        .iter()
        .find(|event| event.id == 9)
        .expect("event 9");
    let second = map
        .events
        .iter()
        .find(|event| event.id == 10)
        .expect("event 10");
    assert_eq!(first.pages.len(), 10);
    assert_eq!(second.pages.len(), 6);
    // Audit doc section 2.3: event 9 picks page v62 - 1, event 10 picks page v62 - 11.
    let probe = |event: &MapEvent, value: i32| {
        let variable = 2_000_062;
        event.active_page_index(|candidate| if candidate == variable { value } else { 0 })
    };
    for (value, page) in [
        (0, None),
        (1, Some(0)),
        (5, Some(4)),
        (10, Some(9)),
        (16, None),
        (99, None),
    ] {
        assert_eq!(
            probe(first, value),
            page,
            "event 9 with global 62 = {value}"
        );
    }
    for (value, page) in [(10, None), (11, Some(0)), (16, Some(5)), (17, None)] {
        assert_eq!(
            probe(second, value),
            page,
            "event 10 with global 62 = {value}"
        );
    }
}

#[test]
fn map024_hooks_on_variable_zero() {
    let Some(game) = load_shipped() else {
        eprintln!("skipping: no map data under {}", data_root().display());
        return;
    };
    let map = game
        .iter()
        .find(|(file, _)| *file == "Map024.mps")
        .map(|(_, map)| map)
        .expect("Map024.mps");
    let event = &map.events[0];
    assert_eq!(event.pages.len(), 1);
    assert_eq!(
        event.active_page_index(|_| 0),
        None,
        "inactive at a fresh VM"
    );
    // Map003 event 1 sets v0 = 1 before the map is entered (audit doc section 7.2).
    let variable_zero = 2_000_000;
    assert_eq!(
        event.active_page_index(|variable| if variable == variable_zero { 1 } else { 0 }),
        Some(0)
    );
}

#[test]
fn page_footers_only_use_the_tolerated_bytes() {
    let Some(game) = load_shipped() else {
        eprintln!("skipping: no map data under {}", data_root().display());
        return;
    };
    let mut normal = 0;
    let mut tolerated = 0;
    for (name, map) in &game {
        for event in &map.events {
            for page in &event.pages {
                match page.footer {
                    0x7A => normal += 1,
                    TOLERATED_PAGE_FOOTER => tolerated += 1,
                    other => panic!("{name} has an unexpected page footer {other:#04X}"),
                }
            }
        }
    }
    assert_eq!((normal, tolerated), (132, 2), "audit doc section 2.2");
}

/// Pages whose graphic name is not empty, per map.
fn graphic_pages(map: &Map) -> usize {
    map.events
        .iter()
        .flat_map(|event| event.pages.iter())
        .filter(|page| !page.graphic.is_empty())
        .count()
}

#[test]
fn registered_maps_never_use_page_graphics() {
    let Some(game) = load_shipped() else {
        eprintln!("skipping: no map data under {}", data_root().display());
        return;
    };
    let mut registered_pages = 0;
    for (name, map) in &game {
        if !REGISTERED.contains(name) {
            continue;
        }
        for event in &map.events {
            for page in &event.pages {
                registered_pages += 1;
                assert_eq!(
                    page.graphic, "",
                    "{name}: registered maps draw no page graphic"
                );
                assert_eq!(
                    page.graphic_chip_id, 0xFFFF_FFFF,
                    "{name}: no page has a chip graphic either"
                );
            }
        }
    }
    assert_eq!(registered_pages, 115, "audit doc section 5.1");

    // Positive control: the orphan maps do carry walkable graphics, so the field is
    // decoded correctly and the empty result above is a property of the game, not of
    // the parser (audit doc section 5.1).
    let mut control: BTreeMap<&str, usize> = BTreeMap::new();
    let mut total_pages = 0;
    for (name, map) in &game {
        total_pages += page_count(map);
        control.insert(*name, graphic_pages(map));
    }
    assert_eq!(total_pages, 134);
    assert_eq!(control.get("SampleMapB.mps"), Some(&4));
    assert_eq!(control.get("Dungeon.mps"), Some(&2));
    assert_eq!(control.get("Map002.mps"), Some(&2));
    for name in REGISTERED {
        assert_eq!(control.get(name), Some(&0), "{name}");
    }
}

fn teleport_args(params: &[u8]) -> Vec<i32> {
    params
        .chunks_exact(4)
        .map(|chunk| i32::from_le_bytes([chunk[0], chunk[1], chunk[2], chunk[3]]))
        .collect()
}

fn teleport_sites(map: &Map) -> Vec<(u32, usize, usize, Vec<i32>)> {
    let mut sites = Vec::new();
    for event in &map.events {
        for (page_index, page) in event.pages.iter().enumerate() {
            for (pc, slot) in page.commands.iter().enumerate() {
                if slot.opcode() != OPCODE_TELEPORT {
                    continue;
                }
                let Slot::Command(command) = slot else {
                    panic!("a blank slot cannot carry opcode {OPCODE_TELEPORT}");
                };
                sites.push((event.id, page_index, pc, teleport_args(&command.params)));
            }
        }
    }
    sites
}

#[test]
fn teleport_sites_match_the_audit() {
    let Some(game) = load_shipped() else {
        eprintln!("skipping: no map data under {}", data_root().display());
        return;
    };
    let expected: [(&str, u32, usize, usize, [i32; 5]); 8] = [
        ("Map003.mps", 1, 0, 28, [-1, 62, 38, 1, 1]),
        ("Map031.mps", 0, 0, 0, [-1, 22, 18, 27, 16]),
        ("SampleMapB.mps", 2, 0, 1, [-1, 15, 1, 1, 0]),
        ("Dungeon.mps", 0, 0, 3, [-1, 34, 12, 1, 32]),
        ("Map002.mps", 3, 0, 7, [-2, 2000007, 1100005, 0, 1]),
        ("Map002.mps", 3, 0, 10, [-2, 2000007, 1100005, 0, 1]),
        ("Map002.mps", 5, 0, 7, [-2, 2000007, 1100005, 0, 1]),
        ("Map002.mps", 5, 0, 10, [-2, 2000007, 1100005, 0, 1]),
    ];
    let mut actual = Vec::new();
    for (name, map) in &game {
        for (event, page, pc, args) in teleport_sites(map) {
            let five: [i32; 5] = args.as_slice().try_into().unwrap_or_else(|_| {
                panic!("{name} event {event}: unexpected argument count {args:?}")
            });
            actual.push((*name, event, page, pc, five));
        }
    }
    assert_eq!(actual, expected.to_vec(), "audit doc section 6.1");
    // Section 6.3: no teleport names a literal map id, so nothing can dangle.
    for (name, event, _, _, args) in &actual {
        assert!(
            args[0] < 0,
            "{name} event {event} teleports to literal map id {}",
            args[0]
        );
    }
}

fn candidate_values(threshold: i32) -> [i32; 6] {
    [
        threshold - 1,
        threshold,
        threshold + 1,
        threshold ^ 1,
        threshold | 1,
        -1,
    ]
}

fn domain(thresholds: &[i32]) -> Vec<i32> {
    let mut values = vec![0i32];
    for &threshold in thresholds {
        values.extend(candidate_values(threshold));
    }
    values.sort_unstable();
    values.dedup();
    values
}

fn observe(
    event: &MapEvent,
    domains: &[Vec<i32>],
    depth: usize,
    assignment: &mut [(u32, i32)],
    won: &mut [bool],
) {
    if depth == domains.len() {
        let winner = event.active_page_index(|variable| {
            assignment
                .iter()
                .find(|(known, _)| *known == variable)
                .map_or(0, |(_, value)| *value)
        });
        if let Some(index) = winner {
            won[index] = true;
        }
        return;
    }
    for &value in &domains[depth] {
        assignment[depth].1 = value;
        observe(event, domains, depth + 1, assignment, won);
    }
}

/// Pages that no assignment of the condition variables can ever activate.
///
/// The domain is the breakpoint set of docs/MAP_AUDIT.md section 4.1: zero plus every
/// value that flips a comparison against a threshold used by the same variable.
fn dead_pages(event: &MapEvent) -> Vec<usize> {
    let mut variables: Vec<u32> = Vec::new();
    let mut thresholds: Vec<Vec<i32>> = Vec::new();
    for page in &event.pages {
        for condition in page.conditions() {
            if !condition.enabled {
                continue;
            }
            match variables
                .iter()
                .position(|&known| known == condition.variable)
            {
                Some(index) => thresholds[index].push(condition.value),
                None => {
                    variables.push(condition.variable);
                    thresholds.push(vec![condition.value]);
                }
            }
        }
    }
    let domains: Vec<Vec<i32>> = thresholds.iter().map(|values| domain(values)).collect();
    let mut won = vec![false; event.pages.len()];
    let mut assignment: Vec<(u32, i32)> = variables.iter().map(|&variable| (variable, 0)).collect();
    observe(event, &domains, 0, &mut assignment, &mut won);
    (0..event.pages.len())
        .filter(|&index| !won[index])
        .collect()
}

#[test]
fn no_multi_page_event_has_a_dead_page() {
    let Some(game) = load_shipped() else {
        eprintln!("skipping: no map data under {}", data_root().display());
        return;
    };
    let mut per_map: BTreeMap<&str, usize> = BTreeMap::new();
    let mut checked = 0;
    for (name, map) in &game {
        for event in &map.events {
            if event.pages.len() < 2 {
                continue;
            }
            checked += 1;
            *per_map.entry(*name).or_insert(0) += 1;
            assert_eq!(
                dead_pages(event),
                Vec::<usize>::new(),
                "{name} event {} ({}) has an unreachable page",
                event.id,
                event.name
            );
        }
    }
    // Audit doc section 2.4 and 8.x: 25 multi-page events, 22 of them registered.
    assert_eq!(checked, 25, "multi-page events");
    let expected = BTreeMap::from([
        ("SampleMapA.mps", 18),
        ("SampleMapA_1.mps", 4),
        ("Dungeon.mps", 1),
        ("Map002.mps", 2),
    ]);
    assert_eq!(per_map, expected, "multi-page events per map");
}
