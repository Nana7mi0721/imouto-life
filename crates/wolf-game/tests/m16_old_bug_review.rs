//! T12 review of the historical BUG-20..24 baseline.
//!
//! The numbers come from two different ledgers, so each test names its source
//! explicitly:
//!
//! * `bug20` is the historical HANDOFF_PROGRESS BUG-20 (`character_state` fields
//!   2/3/6/7), not report section 6's BUG-20 (action-key trigger separation).
//! * `bug21` is report section 6's BUG-21 (`install_map` must retire direct
//!   `MAP_SELF_BASE` coroutines), not the historical BUG-21 (mouse wheel).
//! * `old_bug23` is the historical BUG-23 (opcode 290 Flash/Shake with no live
//!   picture), NOT report section 6's BUG-23 (CSelf5..9 string slots).
//! * `old_bug24` is the historical BUG-24 (Sys15/16 key-repeat timing), NOT
//!   report section 6's BUG-24 (opcode 300 CallByName).
//!
//! Report section 6 BUG-20/BUG-22/BUG-23/BUG-24 have their own production tests
//! (`m3_map_click`, `m3_mouse_menu`, the CSelf VM/runtime tests, and the
//! `ProgramSet::id_by_name` / opcode 300 unit tests); only their covered paths are
//! exercised there, so this file does not duplicate them. BUG-20 and BUG-24 have
//! positive evidence and run normally. BUG-21's desired
//! behavior is still missing, and old BUG-23's empty-range path still discards the
//! effect (that test is synthetic; real-data reproduction is not established), so
//! both assertions stay ignored until a production fix or a behavior decision lands.
//!
//! Data-backed tests print a skip notice and return when `work/Data` is absent,
//! keeping the default workspace run green.

use std::path::PathBuf;
use std::sync::Arc;

use wolf_format::command::{Command, Slot, Tail};
use wolf_format::mps::Map;
use wolf_game::picture::{Screen, EFFECT_FLASH, EFFECT_SHAKE};
use wolf_game::{Game, TILE_PX};
use wolf_vm::program::{COMMON_SELF_BASE, MAP_SELF_BASE};
use wolf_vm::Program;

fn repo_root() -> PathBuf {
    let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    path.pop();
    path.pop();
    path
}

fn data_root() -> PathBuf {
    match std::env::var("WOLF_DATA_ROOT") {
        Ok(raw) if !raw.is_empty() => {
            let path = PathBuf::from(raw);
            if path.is_absolute() {
                path
            } else {
                repo_root().join(path)
            }
        }
        _ => repo_root().join("work").join("Data"),
    }
}

fn open_game() -> Option<Game> {
    let root = data_root();
    if !root.join("BasicData").join("CommonEvent.dat").is_file() {
        eprintln!(
            "skipping m16_old_bug_review: no game data under {}",
            root.display()
        );
        return None;
    }
    match Game::new(root) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!("skipping m16_old_bug_review: cannot create Game: {err}");
            None
        }
    }
}

fn read_map(name: &str) -> Option<Map> {
    let path = data_root().join("MapData").join(name);
    let bytes = match std::fs::read(&path) {
        Ok(bytes) => bytes,
        Err(err) => {
            eprintln!(
                "skipping m16_old_bug_review: cannot read {}: {err}",
                path.display()
            );
            return None;
        }
    };
    match Map::parse(&bytes) {
        Ok(map) => Some(map),
        Err(err) => {
            eprintln!(
                "skipping m16_old_bug_review: cannot parse {}: {err}",
                path.display()
            );
            None
        }
    }
}

fn cmd(opcode: u32, args: &[i32]) -> Slot {
    let mut params = Vec::with_capacity(args.len() * 4);
    for arg in args {
        params.extend_from_slice(&arg.to_le_bytes());
    }
    Slot::Command(Box::new(Command {
        param_count: (args.len() + 1) as u8,
        opcode,
        params,
        branch_depth: 0,
        strings: Vec::new(),
        tail: Tail::None,
    }))
}

fn program(id: u32, slots: Vec<Slot>) -> Arc<Program> {
    Arc::new(Program::from_slots(id, "m16-old-bug-review", slots))
}

fn program_with_self_base(id: u32, self_base: usize, slots: Vec<Slot>) -> Arc<Program> {
    let mut program = Program::from_slots(id, "m16-old-bug-review", slots);
    program.self_base = self_base;
    Arc::new(program)
}

fn character_query(target: i32, character: i32, field: i32) -> Slot {
    cmd(124, &[target, 0x1000, character, field])
}

/// Historical HANDOFF_PROGRESS BUG-20: map-event pixel coordinates were missing.
#[test]
fn bug20_character_state_returns_real_map_event_coordinates() {
    let Some(mut game) = open_game() else {
        return;
    };
    let Some(map) = read_map("SampleMapA.mps") else {
        return;
    };
    let event = map
        .events
        .iter()
        .find(|event| event.id == 1)
        .expect("SampleMapA event 1");
    let (tile_x, tile_y) = (event.x as i32, event.y as i32);
    game.current_map = Some(map);

    game.vm
        .start_program(program(
            90_020,
            vec![
                character_query(2_000_000, 1, 2),
                character_query(2_000_001, 1, 3),
                character_query(2_000_002, 1, 6),
                character_query(2_000_003, 1, 7),
            ],
        ))
        .expect("synthetic BUG-20 event starts");
    game.frame();

    assert_eq!(game.vm.vars.get(0), tile_x, "field 2 is the tile X");
    assert_eq!(game.vm.vars.get(1), tile_y, "field 3 is the tile Y");
    assert_eq!(
        game.vm.vars.get(2),
        tile_x * TILE_PX as i32,
        "field 6 is the pixel X"
    );
    assert_eq!(
        game.vm.vars.get(3),
        tile_y * TILE_PX as i32,
        "field 7 is the pixel Y"
    );
}

#[test]
#[ignore = "BUG-21 reproduced: install_map only retires MapRuntime-owned instances"]
fn bug21_install_map_retires_independent_map_event_instances() {
    let Some(mut game) = open_game() else {
        return;
    };
    let Some(map) = read_map("SampleMapA.mps") else {
        return;
    };
    game.start_pages(&map, None);

    let stale = game
        .vm
        .start_program(program(90_021, vec![cmd(180, &[999_999])]))
        .expect("independent map-self coroutine starts");
    assert_eq!(
        game.vm
            .instance(stale)
            .expect("stale instance is live")
            .program
            .self_base,
        MAP_SELF_BASE
    );

    let survivor = game
        .vm
        .start_program(program_with_self_base(
            90_022,
            COMMON_SELF_BASE,
            vec![cmd(180, &[999_998])],
        ))
        .expect("non-map common-event coroutine starts");

    game.start_pages(&map, Some(90_021));
    assert!(
        game.vm.instance(stale).is_none(),
        "installing a map must retire map-self coroutines that MapRuntime never owned"
    );
    assert!(
        game.vm.instance(survivor).is_some(),
        "installing a map must not stop an unrelated common-event coroutine"
    );
}

/// Historical HANDOFF_PROGRESS BUG-23: viewport-level effects had no carrier.
///
/// The two words are the shipped CE90 shapes (`pc 508` Flash and `pc 394` Shake),
/// both targeting picture 1_600_021. On a fresh `Screen` that slot is empty, which
/// is exactly the latent empty-range path. This proves the API discards it; it is
/// not by itself proof that a retail scene drops the effect, because a direct
/// `wolf-cli run --event 90` mounts picture 10223 and applies the shake.
#[test]
#[ignore = "old BUG-23 latent: Screen::effect drops effects when the range holds no picture"]
fn old_bug23_flash_and_shake_survive_without_a_mounted_picture() {
    let mut screen = Screen::new();

    let flash = [0, 25, 1_600_021, 1_600_021, 200, -100, -100];
    assert!(
        screen.effect(i32::from(EFFECT_FLASH), 25, &flash),
        "a whole-screen flash must not be discarded just because its range is empty"
    );

    let shake = [48, 30, 1_600_021, 1_600_021, 0, 1, 999_999];
    assert!(
        screen.effect(i32::from(EFFECT_SHAKE), 30, &shake),
        "a whole-screen shake must not be discarded just because its range is empty"
    );
}

/// Historical HANDOFF_PROGRESS BUG-24: Sys15/16 are not undefined scratch cells.
///
/// CE115 maps the five shipped levels to the key-repeat delay/interval pairs below
/// and writes them into Sys15/16. CE48 starts at level 2, so the boot result 14/8
/// is the same pair the table defines, not an accidental value.
#[test]
fn old_bug24_key_repeat_levels_are_defined_by_ce115() {
    let Some(mut game) = open_game() else {
        return;
    };

    game.start_engine_events();
    for _ in 0..30 {
        game.frame();
    }
    let boot = (game.sys(15), game.sys(16));
    assert_eq!(
        boot,
        (14, 8),
        "CE48 calls CE115 with the shipped default level 2"
    );

    for (level, delay, interval) in [(0, 25, 15), (1, 19, 9), (2, 14, 8), (3, 11, 6), (4, 9, 4)] {
        let Some(mut settings) = open_game() else {
            return;
        };
        assert!(
            settings
                .vm
                .start_event_with_args(115, &[level], &[])
                .is_some(),
            "CE115 starts for level {level}"
        );
        settings.frame();
        assert_eq!(
            (settings.sys(15), settings.sys(16)),
            (delay, interval),
            "CE115 level {level} must write its shipped delay/interval pair"
        );
    }
}
