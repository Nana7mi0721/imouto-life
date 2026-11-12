//! M16 runtime-state integration regressions (T10 items 5-10).
//!
//! These tests stay on the public `Game` / `Vm` surface. Synthetic event streams
//! are started with `Game::vm.start_program` and advanced with `Game::frame`, while
//! save and map checks use the shipped `SaveData01.sav` and `.mps` files.
//!
//! Every data-dependent test prints a skip notice and returns when its data is
//! missing, so the default workspace run stays green without `work/Data`.

use std::path::{Path, PathBuf};
use std::sync::Arc;

use wolf_format::command::{Command, Slot, Tail};
use wolf_format::mps::Map;
use wolf_game::game::BOOT_EVENT;
use wolf_game::savegame;
use wolf_game::{Game, PictureKind, TILE_PX};
use wolf_vm::magic::SELF_ARG_BASE;
use wolf_vm::{Program, SoundAction, SoundChannel, WaitState};

fn repo_root() -> PathBuf {
    let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    path.pop();
    path.pop();
    path
}

fn data_root() -> PathBuf {
    if let Ok(raw) = std::env::var("WOLF_DATA_ROOT") {
        if !raw.is_empty() {
            let path = PathBuf::from(raw);
            return if path.is_absolute() {
                path
            } else {
                repo_root().join(path)
            };
        }
    }
    repo_root().join("work").join("Data")
}

fn open_game() -> Option<Game> {
    let root = data_root();
    if !root.join("BasicData").join("CommonEvent.dat").is_file() {
        eprintln!(
            "skipping m16_runtime_state: no game data under {}",
            root.display()
        );
        return None;
    }
    match Game::new(root) {
        Ok(mut game) => {
            game.auto_events.set_enabled(false);
            Some(game)
        }
        Err(err) => {
            eprintln!("skipping m16_runtime_state: cannot create Game: {err}");
            None
        }
    }
}

fn save_data_one() -> Option<PathBuf> {
    let path = data_root().join("Save").join("SaveData01.sav");
    if !path.is_file() {
        eprintln!(
            "skipping m16_runtime_state: SaveData01.sav is missing at {}",
            path.display()
        );
        return None;
    }
    Some(path)
}

fn read_map(name: &str) -> Option<Map> {
    let root = data_root();
    let path = root.join("MapData").join(name);
    let bytes = match std::fs::read(&path) {
        Ok(bytes) => bytes,
        Err(err) => {
            eprintln!(
                "skipping m16_runtime_state: cannot read {}: {err}",
                path.display()
            );
            return None;
        }
    };
    match Map::parse(&bytes) {
        Ok(map) => Some(map),
        Err(err) => {
            eprintln!(
                "skipping m16_runtime_state: cannot parse {}: {err}",
                path.display()
            );
            None
        }
    }
}

fn cmd(opcode: u32, args: &[i32], strings: &[&str]) -> Slot {
    let mut params = Vec::new();
    for arg in args {
        params.extend_from_slice(&arg.to_le_bytes());
    }
    Slot::Command(Box::new(Command {
        param_count: (args.len() + 1) as u8,
        opcode,
        params,
        branch_depth: 0,
        strings: strings.iter().map(|text| (*text).to_owned()).collect(),
        tail: Tail::None,
    }))
}

fn program(id: u32, slots: Vec<Slot>) -> Arc<Program> {
    Arc::new(Program::from_slots(id, "m16-runtime-state", slots))
}

fn text_draw(number: i32, fade: i32, opacity: i32, text: &str) -> Slot {
    cmd(
        150,
        &[0x20, number, fade, 1, 1, 1, opacity, 10, 20, 100, 0],
        &[text],
    )
}

fn file_draw(number: i32, file: &str, split: (i32, i32)) -> Slot {
    cmd(
        150,
        &[0, number, 0, split.0, split.1, 1, 255, 0, 0, 100, 0],
        &[file],
    )
}

fn window_draw(number: i32, width: i32, height: i32) -> Slot {
    cmd(
        150,
        &[0x30, number, 0, width, height, 1, 255, 0, 0, 100, 0],
        &["SystemFile/WindowBase.png"],
    )
}

fn picture_query(target: i32, sub: i32, picture: i32, field: i32) -> Slot {
    cmd(124, &[target, sub, picture, field], &[])
}

fn character_query(target: i32, sub: i32, character: i32, field: i32) -> Slot {
    cmd(124, &[target, sub, character, field], &[])
}

fn expected_bgm(save: &Path) -> Option<(String, i32)> {
    let save = savegame::read_save(save).ok()?;
    let bgm = save.part2.bgm.as_ref()?;
    let body = bgm.path1.strip_suffix(&[0]).unwrap_or(&bgm.path1);
    let (file, _bad) = wolf_format::gbk::decode(body);
    (!file.is_empty()).then_some((file, bgm.vars75_77[0] as i32))
}

fn assert_same_map(actual: &Map, expected: &Map) {
    assert_eq!(actual.name, expected.name);
    assert_eq!(actual.version, expected.version);
    assert_eq!(actual.tileset_index, expected.tileset_index);
    assert_eq!(actual.width, expected.width);
    assert_eq!(actual.height, expected.height);
    assert_eq!(actual.has_tile_data, expected.has_tile_data);
    let actual_ids: Vec<u32> = actual.events.iter().map(|event| event.id).collect();
    let expected_ids: Vec<u32> = expected.events.iter().map(|event| event.id).collect();
    assert_eq!(actual_ids, expected_ids);
}

#[test]
fn load_save_and_reset_put_bgm_commands_in_the_frame_packet() {
    let Some(save_path) = save_data_one() else {
        return;
    };
    let Some(expected) = expected_bgm(&save_path) else {
        eprintln!("skipping m16_runtime_state: SaveData01 carries no BGM");
        return;
    };

    // The true same-frame 220 path: the VM queues the load, Game::frame applies it
    // after the step and drains the load's pending BGM command into this packet.
    let Some(mut game) = open_game() else {
        return;
    };
    let load = program(
        90_001,
        vec![
            cmd(122, &[3_000_000], &["Save/SaveData01.sav"]),
            cmd(220, &[1, 3_000_000], &[]),
        ],
    );
    assert!(game.vm.start_program(load).is_some());
    let before = game.stats.sounds;
    game.frame();
    assert!(
        game.sounds
            .iter()
            .any(|sound| sound.channel == SoundChannel::Bgm && sound.action == SoundAction::Play),
        "the 220 load must publish Bgm/Play in the same frame packet"
    );
    assert_eq!(
        game.current_bgm,
        Some(expected.clone()),
        "the loaded save's track must be current immediately"
    );
    assert_eq!(
        game.stats.sounds - before,
        game.sounds.len() as u64,
        "stats.sounds must count exactly the commands in the packet"
    );

    // The direct public Game::load_save path queues the command; the next frame is
    // the packet that carries it.
    let Some(mut game) = open_game() else {
        return;
    };
    game.load_save(&save_path).expect("SaveData01 loads");
    let before = game.stats.sounds;
    game.frame();
    assert!(
        game.sounds
            .iter()
            .any(|sound| sound.channel == SoundChannel::Bgm && sound.action == SoundAction::Play),
        "Game::load_save must reach the next frame packet as Bgm/Play"
    );
    assert_eq!(game.current_bgm, Some(expected));
    assert_eq!(game.stats.sounds - before, game.sounds.len() as u64);

    // A save with no BGM (built in memory, never written) must publish Bgm/Stop.
    let mut silent = savegame::read_save(&save_path).expect("SaveData01 parses");
    silent.part2.bgm = None;
    let Some(mut game) = open_game() else {
        return;
    };
    savegame::apply(&mut game, &silent);
    let before = game.stats.sounds;
    game.frame();
    assert!(
        game.sounds
            .iter()
            .any(|sound| sound.channel == SoundChannel::Bgm && sound.action == SoundAction::Stop),
        "a silent save must publish Bgm/Stop"
    );
    assert_eq!(game.stats.sounds - before, game.sounds.len() as u64);

    // reset_to_title queues BGM/BGS stops; the next frame packet carries them.
    let Some(mut game) = open_game() else {
        return;
    };
    game.reset_to_title();
    let before = game.stats.sounds;
    game.frame();
    assert!(
        game.sounds
            .iter()
            .any(|sound| sound.channel == SoundChannel::Bgm && sound.action == SoundAction::Stop),
        "the title reset must publish Bgm/Stop"
    );
    assert_eq!(game.stats.sounds - before, game.sounds.len() as u64);
}

#[test]
fn database_string_slot_is_cleared_by_a_missing_extension_row() {
    let Some(mut game) = open_game() else {
        return;
    };
    let id = game
        .vm
        .start_program(program(
            90_002,
            vec![
                cmd(122, &[1_600_005], &["stale string"]),
                cmd(180, &[1], &[]),
                cmd(250, &[0, 100, 0, 0x51000, 1_600_005], &[]),
                cmd(180, &[100], &[]),
            ],
        ))
        .expect("synthetic event starts");

    game.frame();
    assert_eq!(
        game.vm
            .instance(id)
            .expect("the event is waiting between the write and the read")
            .self_vars
            .get_str(SELF_ARG_BASE + 5),
        "stale string",
        "precondition: 1_600_005 held the old string"
    );

    game.frame();
    assert_eq!(
        game.vm
            .instance(id)
            .expect("the event is waiting after the read")
            .self_vars
            .get_str(SELF_ARG_BASE + 5),
        "",
        "a missing extension row must clear the string destination, not keep the old value"
    );
}

#[test]
fn picture_state_and_op124_report_real_sizes_and_compound_results() {
    let Some(mut game) = open_game() else {
        return;
    };
    let Some(map) = read_map("SampleMapA.mps") else {
        return;
    };
    let event_zero_x = map
        .events
        .iter()
        .find(|event| event.id == 0)
        .expect("SampleMapA event 0")
        .x as i32;
    assert_eq!(event_zero_x, 30, "the measured subtract query value");
    game.current_map = Some(map);

    let file = "Picture/icon01.png";
    let split = (2, 2);
    let id = game
        .vm
        .start_program(program(
            90_003,
            vec![
                text_draw(27_000, 0, 200, "\\f[24]21:40"),
                picture_query(2_000_000, 0x4000, 27_000, 2),
                picture_query(2_000_001, 0x4000, 27_000, 3),
                file_draw(27_001, file, split),
                picture_query(2_000_002, 0x4000, 27_001, 2),
                picture_query(2_000_003, 0x4000, 27_001, 3),
                window_draw(7, 70, 40),
                cmd(121, &[2_000_004, 140, 0, 0], &[]),
                picture_query(2_000_004, 0x4400, 7, 2),
                cmd(121, &[2_000_005, 100, 0, 0], &[]),
                character_query(2_000_005, 0x1200, 0, 2),
            ],
        ))
        .expect("synthetic event starts");
    game.frame();
    assert!(
        game.vm.instance(id).is_none(),
        "the synthetic program should finish in one frame"
    );

    let text_width = game.vm.vars.get(0);
    let text_height = game.vm.vars.get(1);
    let file_width = game.vm.vars.get(2);
    let file_height = game.vm.vars.get(3);
    assert!(
        text_width > 1 && text_height > 1,
        "text field 2/3 must be measured, got {text_width}x{text_height}"
    );

    let text = game.screen.get(27_000).expect("text picture");
    assert_eq!(text.window, Some((1, 1)));
    assert_eq!(text.kind, PictureKind::Text);
    assert_eq!(
        text.text_size,
        Some((text_width, text_height)),
        "the reported size must be the measured text block"
    );

    let (texture_width, texture_height) = game
        .assets
        .texture_size(file)
        .unwrap_or_else(|| panic!("{file} must be readable"));
    assert_eq!(
        file_width,
        i32::try_from(texture_width / split.0 as u32).expect("fits i32")
    );
    assert_eq!(
        file_height,
        i32::try_from(texture_height / split.1 as u32).expect("fits i32")
    );
    let sprite = game.screen.get(27_001).expect("file picture");
    assert_eq!(sprite.split, (split.0 as u32, split.1 as u32));

    assert_eq!(
        game.vm.vars.get(4),
        2,
        "0x4400 divides 140 by a 70-wide picture"
    );
    assert_eq!(
        game.vm.vars.get(5),
        70,
        "0x1200 subtracts the real event-0 tile x (30) from 100"
    );
}

#[test]
fn character_state_reads_real_map_tiles_and_pixels() {
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
        .expect("SampleMapA event 1")
        .clone();
    let (tile_x, tile_y) = (event.x as i32, event.y as i32);
    game.current_map = Some(map);

    game.vm
        .start_program(program(
            90_004,
            vec![
                character_query(2_000_000, 0x1000, 1, 2),
                character_query(2_000_001, 0x1000, 1, 3),
                character_query(2_000_002, 0x1000, 1, 6),
                character_query(2_000_003, 0x1000, 1, 7),
                cmd(121, &[2_000_004, 777, 0, 0], &[]),
                character_query(2_000_004, 0x1000, 9_999, 2),
                cmd(121, &[2_000_005, 555, 0, 0], &[]),
                character_query(2_000_005, 0x1000, 1, 99),
                cmd(121, &[2_000_006, 444, 0, 0], &[]),
                character_query(2_000_006, 0x1000, -1, 2),
            ],
        ))
        .expect("synthetic event starts");
    game.frame();

    assert_eq!(game.vm.vars.get(0), tile_x, "field 2 is the .mps tile x");
    assert_eq!(game.vm.vars.get(1), tile_y, "field 3 is the .mps tile y");
    assert_eq!(
        game.vm.vars.get(2),
        tile_x * TILE_PX as i32,
        "field 6 is pixels"
    );
    assert_eq!(
        game.vm.vars.get(3),
        tile_y * TILE_PX as i32,
        "field 7 is pixels"
    );
    assert_eq!(
        game.vm.vars.get(4),
        777,
        "unknown event must leave its destination alone"
    );
    assert_eq!(
        game.vm.vars.get(5),
        555,
        "unknown field must leave its destination alone"
    );
    assert_eq!(game.vm.vars.get(6), 444, "target -1 has no map event");
}

#[test]
fn return_to_title_reboots_the_title_map() {
    let Some(mut game) = open_game() else {
        return;
    };
    let Some(title_map) = read_map("TitleMap.mps") else {
        return;
    };
    game.vm
        .start_program(program(90_005, vec![cmd(174, &[], &[])]))
        .expect("synthetic event starts");

    game.frame();

    let current = game
        .current_map
        .as_ref()
        .expect("174 must install the title map");
    assert_same_map(current, &title_map);
    assert!(
        game.vm
            .instances()
            .iter()
            .any(|instance| instance.event == BOOT_EVENT),
        "the title map's boot event must be running again"
    );
}

#[test]
fn reserved_event_waits_for_an_idle_foreground_and_keeps_its_arguments() {
    let Some(mut game) = open_game() else {
        return;
    };
    game.vm
        .start_program(program(
            90_006,
            vec![cmd(211, &[269, 0x112, 11, 22], &["", "greeting"])],
        ))
        .expect("synthetic event starts");

    game.frame();

    let instance = game
        .vm
        .instances()
        .iter()
        .find(|instance| instance.event == 269)
        .expect("the reserved event starts once the foreground is idle");
    assert_eq!(instance.self_vars.get(SELF_ARG_BASE), 11);
    assert_eq!(instance.self_vars.get(SELF_ARG_BASE + 1), 22);
    assert_eq!(instance.self_vars.get_str(SELF_ARG_BASE + 5), "greeting");

    let bank = game
        .vm
        .vars
        .common_self
        .get(&269)
        .expect("the durable common-self bank is updated");
    assert_eq!(bank.get(0), 11);
    assert_eq!(bank.get(1), 22);
    assert_eq!(bank.get_str(0), "greeting");

    // A foreground waiter must hold the reservation for a later frame.
    let Some(mut busy) = open_game() else {
        return;
    };
    busy.vm
        .start_program(program(
            90_007,
            vec![
                cmd(211, &[269, 0x112, 33], &["", "held"]),
                cmd(180, &[100], &[]),
            ],
        ))
        .expect("busy synthetic event starts");
    busy.frame();
    assert!(
        busy.vm
            .instances()
            .iter()
            .all(|instance| instance.event != 269),
        "a busy foreground stack must not start the reservation early"
    );
    assert!(
        busy.vm
            .instances()
            .iter()
            .any(|instance| instance.event == 90_007 && instance.wait == WaitState::Frames(100)),
        "precondition: the foreground event is parked on its wait"
    );
}

#[test]
fn ce234_erase_fade_survives_then_fades_and_removes_after_fifty_frames() {
    let Some(mut game) = open_game() else {
        return;
    };
    let number = 50_000;
    game.vm
        .start_program(program(
            90_008,
            vec![
                text_draw(number, 50, 200, "fading"),
                cmd(150, &[2, number, 50], &[]),
            ],
        ))
        .expect("synthetic event starts");

    game.frame();
    let mut previous = game
        .screen
        .get(number)
        .expect("the erase fade must not remove the picture on its first frame")
        .alpha();
    assert!(previous > 0.0);
    assert!(
        game.screen
            .get(number)
            .expect("fading picture")
            .erase_after_slide
    );

    for frame in 2..=49 {
        game.frame();
        let alpha = game
            .screen
            .get(number)
            .unwrap_or_else(|| panic!("picture vanished before frame 50 at frame {frame}"))
            .alpha();
        assert!(
            alpha < previous,
            "alpha must fall every frame: frame {frame} had {alpha}, previous {previous}"
        );
        previous = alpha;
    }
    assert!(
        game.screen.get(number).is_some(),
        "frame 49 is still visible"
    );

    game.frame();
    assert!(
        game.screen.get(number).is_none(),
        "frame 50 removes the faded picture"
    );
}

#[test]
fn range_erase_fades_every_live_slot_and_zero_fade_is_immediate() {
    let Some(mut game) = open_game() else {
        return;
    };
    let mut slots = Vec::new();
    for number in 50_000..=50_003 {
        slots.push(text_draw(number, 0, 200, "range"));
    }
    slots.push(text_draw(50_010, 0, 200, "immediate"));
    slots.push(cmd(150, &[2, 50_000, 5, 5, 0, 50_003], &[]));
    slots.push(cmd(150, &[2, 50_010, 0], &[]));
    game.vm
        .start_program(program(90_009, slots))
        .expect("synthetic event starts");

    game.frame();
    assert!(
        game.screen.get(50_010).is_none(),
        "Erase(fade=0) removes its slot immediately"
    );
    for number in 50_000..=50_003 {
        let picture = game
            .screen
            .get(number)
            .unwrap_or_else(|| panic!("slot {number} must start its fade"));
        assert!(picture.erase_after_slide);
        assert!(picture.transition.is_some());
        assert_eq!(picture.transition.expect("range transition").duration, 5);
    }

    for _ in 0..3 {
        game.frame();
    }
    for number in 50_000..=50_003 {
        assert!(
            game.screen.get(number).is_some(),
            "slot {number} is still fading after four frames"
        );
    }
    game.frame();
    for number in 50_000..=50_003 {
        assert!(
            game.screen.get(number).is_none(),
            "slot {number} must be removed after five fade frames"
        );
    }
}
