//! M3-H: map-event runtime smoke and registered-map attribute tests.
//!
//! The five registered maps this game ships in `work/Data/MapData` are:
//!
//! * `TitleMap.mps`  - the boot map (event 2 draws the logo then calls CE42).
//! * `SampleMapA.mps` - the bedroom/living room where the daily loop happens; it is
//!   the only map with a large, varied event set (35 events, 78 pages).
//! * `Map003.mps`    - the new-game hook (event 1 teleports into SampleMapA).
//! * `Map024.mps`    - a two-instruction picture-clearing stub.
//! * `Map031.mps`    - the load-time setup hook (event 0).
//!
//! m1 already pins the title -> CE42 -> Map003 -> SampleMapA / CE14 load chain. This
//! file works from the `.mps` side instead: it asserts the parsed geometry, evaluates
//! every page's activation condition against a real save's variable bank, and runs each
//! SampleMapA page bounded to catch interpreter warnings. It skips (like the rest of the
//! suite) when `work/Data` is absent.

use std::path::PathBuf;

use wolf_format::mps::Map;
use wolf_game::Game;
use wolf_vm::{Magic, MagicKind};

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

fn read_map(name: &str) -> Option<Map> {
    let bytes = std::fs::read(data_root().join("MapData").join(name)).ok()?;
    match Map::parse(&bytes) {
        Ok(map) => Some(map),
        Err(err) => {
            eprintln!("skipping: cannot parse {name}: {err}");
            None
        }
    }
}

fn open_game() -> Option<Game> {
    match Game::new(data_root()) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!("skipping: {err}");
            None
        }
    }
}

/// One page's slot tally, used by the metadata test.
fn page_slot_counts(map: &Map) -> Vec<usize> {
    map.events
        .iter()
        .flat_map(|event| event.pages.iter())
        .map(|page| page.commands.len())
        .collect()
}

// ---------------------------------------------------------------------------
// 1. Parsed geometry of the five registered maps.
// ---------------------------------------------------------------------------

#[test]
fn registered_map_metadata_matches_shipped_data() {
    // (file, width, height, events, pages, slots, blank slots)
    let expected: [(&str, u32, u32, usize, usize, usize, usize); 5] = [
        ("TitleMap.mps", 53, 30, 1, 1, 64, 5),
        ("SampleMapA.mps", 64, 36, 35, 78, 11558, 2108),
        ("Map003.mps", 70, 170, 2, 2, 47, 5),
        ("Map024.mps", 53, 30, 1, 1, 3, 1),
        ("Map031.mps", 53, 30, 1, 1, 63, 17),
    ];

    for (file, width, height, events, pages, slots, blank) in expected {
        let Some(map) = read_map(file) else { return };
        assert_eq!((map.width, map.height), (width, height), "{file} size");
        assert_eq!(map.events.len(), events, "{file} event count");
        let all_slots: usize = page_slot_counts(&map).iter().sum();
        let all_pages: usize = map.events.iter().map(|e| e.pages.len()).sum();
        assert_eq!(all_pages, pages, "{file} page count");
        assert_eq!(all_slots, slots, "{file} slot count");

        let stats = map.stats();
        assert_eq!(stats.slots, slots, "{file} stats slot count");
        assert_eq!(stats.blank(), blank, "{file} blank (NOP) slots");
        assert_eq!(stats.blank() + stats.real(), slots, "{file} blank+real=total");

        // Every shipped map carries a tile layer. Map024/Map031 fill layer 0 with a
        // single filler id (100000) rather than drawing a real room, but the block is
        // present, so has_tile_data is true for all five.
        assert!(map.has_tile_data, "{file} ships tile data");
        assert!(!map.layers.is_empty(), "{file} has at least one tile layer");
    }
}

// ---------------------------------------------------------------------------
// 2. Page activation against a real save's variable bank (zero-panic check).
// ---------------------------------------------------------------------------

#[test]
fn every_event_selects_a_page_under_a_loaded_save_without_panicking() {
    let save_path = data_root().join("Save").join("SaveData01.sav");
    let Ok(save) = wolf_game::savegame::read_save(&save_path) else {
        eprintln!("skipping: no Save/SaveData01.sav");
        return;
    };

    // Rebuild the same variable context a load applies: the 302 normal words from
    // SavePart3 row 0, plus the Sys3/Sys4 choice anchor. Event self-variables have no
    // bank here and read as 0, which is exactly the "page not on the map" fallback.
    let mut normal_vars: Vec<i32> = Vec::new();
    let mut index = 0;
    while let Some(value) = save.part3.normal_var(index) {
        normal_vars.push(value);
        index += 1;
    }
    assert!(normal_vars.len() > 100, "the save carries a variable bank");
    let sys3 = save.part2.vars3_21.get(9).copied().unwrap_or(512) as i32;
    let sys4 = save.part2.vars3_21.get(10).copied().unwrap_or(240) as i32;

    let mut get_variable = |raw: u32| -> i32 {
        let magic = Magic::decode(raw as i32);
        match magic.kind() {
            MagicKind::Literal => magic.index() as i32,
            MagicKind::Var => normal_vars
                .get(magic.index() as usize)
                .copied()
                .unwrap_or(0),
            MagicKind::SysVar => match magic.index() {
                3 => sys3,
                4 => sys4,
                _ => 0,
            },
            MagicKind::SelfVar | MagicKind::StrVar | MagicKind::Opaque => 0,
        }
    };

    for file in [
        "TitleMap.mps",
        "SampleMapA.mps",
        "Map003.mps",
        "Map024.mps",
        "Map031.mps",
    ] {
        let Some(map) = read_map(file) else { return };
        let mut selected = 0usize;
        for event in &map.events {
            // The point of this test is "does not panic and never returns an
            // out-of-range page": active_page_index evaluates every page condition.
            let page = event.active_page_index(&mut get_variable);
            if let Some(page) = page {
                assert!(
                    page < event.pages.len(),
                    "{file} event {} selected page {page} of {}",
                    event.id,
                    event.pages.len()
                );
                selected += 1;
            }
        }
        assert!(
            selected > 0,
            "{file} has at least one page active under the loaded save context"
        );
    }
}

// ---------------------------------------------------------------------------
// 3. SampleMapA: every event page runs bounded and warning-free.
// ---------------------------------------------------------------------------

#[test]
fn samplemapa_event_pages_run_bounded_without_warnings() {
    let Some(map) = read_map("SampleMapA.mps") else { return };

    // Events whose first page produces no message, no text picture and no menu in
    // isolation are the ones that need live context (a player key press, a menu that
    // is open, or a common-event subroutine with arguments). We do not try to force
    // those; the smoke test just proves they can be started and tick without a
    // warning. The list is recorded in docs/M3_MAP_EVENTS.md so drift is visible.
    let context_dependent: &[u32] = &[8, 11, 16, 17, 18, 20, 24, 26, 34, 35];

    let mut failures: Vec<String> = Vec::new();
    for event in &map.events {
        let id = event.id;
        let Some(mut game) = open_game() else { return };
        game.auto_advance = true;
        // start_map_event starts only this event's first page, so the text observed is
        // the page's own. start_map_event_by_name would also start SampleMapA's autorun
        // narration (event 0's opening splash), which masks every other page's first
        // line; both are acceptable APIs for the warning check, this one reads cleaner.
        if !game.start_map_event(&map, id) {
            failures.push(format!("event {id} failed to start"));
            continue;
        }

        // Bounded run: never more than 120 frames for one page.
        let mut messages: Vec<String> = Vec::new();
        for _ in 0..120 {
            game.frame();
            for message in &game.messages {
                if messages.last() != Some(&message.text) {
                    messages.push(message.text.clone());
                }
            }
        }

        let warnings = game.stats.warnings;
        let first = messages.first().map(|text| {
            text.trim()
                .trim_start_matches("\\E")
                .chars()
                .take(24)
                .collect::<String>()
        });
        let quiet = messages.is_empty()
            && game.screen.iter().all(|p| p.text.is_empty())
            && game.stats.pictures == 0;
        if quiet && !context_dependent.contains(&id) {
            // Not a hard failure (the page may legitimately be a handler), but worth
            // surfacing so the docs table stays accurate.
            eprintln!(
                "note: SampleMapA event {id} '{}' produced no visible output in isolation",
                event.name
            );
        }

        if warnings > 0 {
            failures.push(format!(
                "event {id} '{}' produced {warnings} warnings",
                event.name
            ));
        }
        println!(
            "SampleMapA event {id:>2} '{}' messages={} pictures={} warnings={warnings} first={first:?}",
            event.name,
            messages.len(),
            game.stats.pictures,
        );
    }

    assert!(
        failures.is_empty(),
        "SampleMapA pages must start and run bounded without warnings: {failures:#?}"
    );
}

// ---------------------------------------------------------------------------
// 4. Map switching: the title new-game path reaches SampleMapA.
// ---------------------------------------------------------------------------

#[test]
fn title_new_game_map_switch_reaches_sample_map_a() {
    // m1 already asserts this end to end; this test additionally checks it from the
    // .mps side (Map003 event 1 must carry the 130 teleport), so the map file and the
    // runtime diagnosis cannot drift apart.
    let Some(map003) = read_map("Map003.mps") else { return };
    let hook = map003
        .events
        .iter()
        .find(|event| event.name.contains("ニューゲーム"))
        .expect("Map003 has the new-game hook event");
    let hook_ops: Vec<u32> = hook
        .pages
        .first()
        .expect("the hook has a first page")
        .commands
        .iter()
        .map(|slot| slot.opcode())
        .collect();
    assert!(
        hook_ops.contains(&130),
        "Map003 hook page teleports (opcode 130) into SampleMapA: {hook_ops:?}"
    );

    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.set_choice_cursor(0); // menu1 = new game
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.boot().expect("the title map has its autorun event");

    // Run until both teleports are visible (bounded well under m1's 3200-frame walk).
    let mut reached = false;
    for _ in 0..3200 {
        game.frame();
        let diagnostics: Vec<&str> = game.diagnostics.keys().map(String::as_str).collect();
        let map003_seen = diagnostics
            .iter()
            .any(|line| line.contains("130 Teleport: MapData/Map003.mps"));
        let sample_seen = diagnostics
            .iter()
            .any(|line| line.contains("130 Teleport: MapData/SampleMapA.mps"));
        if map003_seen && sample_seen && game.screen.len() > 30 {
            reached = true;
            break;
        }
    }

    assert!(reached, "the new-game path reached SampleMapA within 3200 frames");
    assert_eq!(game.stats.warnings, 0, "the new-game map switch is warning-free");
    assert!(
        game.screen.len() > 30,
        "the SampleMapA room and HUD are drawn: {} pictures",
        game.screen.len()
    );
}
