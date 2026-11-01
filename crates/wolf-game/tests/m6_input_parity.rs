//! M6: input parity — the decoded `123` option word, raw key codes and the
//! click-to-continue waits.
//!
//! Three player-visible behaviours are pinned here against the shipped data:
//!
//! 1. The settings screen's key rows capture a raw keyboard code. CE132 polls
//!    opcode 123 with `0x101` (device = keyboard) and stores what it reads into
//!    Sys52..54; the host has to expose physical keys as WOLF codes for that to
//!    work at all.
//! 2. A `123` poll with the wait bit blocks. CE251's night scene parks on
//!    `123 [var, 0x91]` under a 「クリック処理」 comment: the poll's value is never
//!    read, the command exists to hold the scene until the player acts.
//! 3. A volume edit in the settings window reaches the mixer while the window is
//!    still open (the retail engine feeds the mixer as soon as Sys100/Sys102 move).
//!
//! Everything skips cleanly when `work/Data` is absent (default workspace run).

use std::path::PathBuf;

use wolf_game::{key, Game};
use wolf_vm::WaitState;

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

fn open_game() -> Option<Game> {
    if !data_root().join("BasicData/CommonEvent.dat").exists() {
        eprintln!("skipping: no data under {}", data_root().display());
        return None;
    }
    match Game::new(data_root()) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!("skipping: {err}");
            None
        }
    }
}

fn self_slot(game: &Game, id: wolf_vm::InstanceId, slot: usize) -> i32 {
    game.vm
        .instance(id)
        .map(|inst| inst.self_vars.get(600 + slot))
        .unwrap_or(-1)
}

/// Hold `bits` for three frames — one row step in CE132 — then let it settle.
fn tap(game: &mut Game, bits: u32) {
    game.key_bits = bits;
    for _ in 0..3 {
        game.frame();
    }
    game.key_bits = 0;
    for _ in 0..6 {
        game.frame();
    }
}

/// Walks CE132's cursor from row 0 to `target` with real down-key presses.
fn goto_row(game: &mut Game, id: wolf_vm::InstanceId, target: i32) {
    let mut guard = 0;
    while self_slot(game, id, 10) != target {
        let before = self_slot(game, id, 10);
        tap(game, key::DOWN);
        assert_ne!(
            self_slot(game, id, 10),
            before,
            "CE132 cursor stuck at row {before}"
        );
        guard += 1;
        assert!(guard < 20, "CE132 never reached row {target}");
    }
}

#[test]
fn ce132_captures_a_raw_keyboard_key_into_the_key_config() {
    let Some(mut game) = open_game() else { return };
    game.start_engine_events();
    assert!(game.start_event(132), "CE132 starts");
    let id = game
        .vm
        .instances()
        .iter()
        .find(|inst| inst.event == 132)
        .map(|inst| inst.id)
        .expect("CE132 instance");
    for _ in 0..30 {
        game.frame();
    }

    // Row 5 is キー設定（キーボード）: its loop polls the raw keyboard (0x101).
    goto_row(&mut game, id, 5);
    assert_eq!(
        game.sys(52),
        144,
        "shipped decide key is Z (scancode 44 + 100)"
    );

    // Press a key the engine has never seen bound: C is 146, A is 130.
    game.raw_keys = vec![key::keyboard_code(0x1E)];
    for _ in 0..8 {
        game.frame();
    }
    game.raw_keys.clear();

    assert_eq!(
        game.sys(52),
        key::keyboard_code(0x1E),
        "CE132 stores the captured keyboard code in Sys52"
    );
    assert_eq!(
        game.live_settings().key_config[0],
        130,
        "live config follows"
    );
    assert_eq!(game.stats.warnings, 0, "the capture path is warning-free");
}

#[test]
fn a_click_to_continue_poll_holds_the_scene_until_a_key_arrives() {
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    assert!(game.start_event(251), "CE251 starts");
    let id = game
        .vm
        .instances()
        .iter()
        .find(|inst| inst.event == 251)
        .map(|inst| inst.id)
        .expect("CE251 instance");

    // Walk the scene until it parks on the click-to-continue poll.
    let mut parked = false;
    for _ in 0..1200 {
        game.frame();
        if let Some(inst) = game.vm.instance(id) {
            if inst.wait == WaitState::Key {
                parked = true;
                break;
            }
        }
    }
    assert!(
        parked,
        "CE251's `123 [var, 0x91]` poll must block the scene"
    );

    // No key: the scene stays exactly where it is.
    let pc = game.vm.instance(id).map(|inst| inst.pc);
    for _ in 0..30 {
        game.frame();
    }
    assert_eq!(
        game.vm.instance(id).map(|inst| inst.pc),
        pc,
        "without a key the wait poll keeps the coroutine in place"
    );

    // One decide press releases it.
    game.key_bits = key::OK;
    game.frame();
    game.key_bits = 0;
    assert_ne!(
        game.vm.instance(id).map(|inst| inst.pc),
        pc,
        "a decide press releases the click-to-continue poll"
    );
    assert_eq!(game.stats.warnings, 0, "warnings");
}

#[test]
fn a_volume_edit_in_the_settings_screen_reaches_the_mixer() {
    let Some(mut game) = open_game() else { return };
    game.audio = Some(wolf_audio::Engine::null());
    let tone = wolf_audio::DecodedAudio {
        sample_rate: 48_000,
        channels: 1,
        samples: vec![1.0; 48_000],
        loop_start: None,
        loop_end: None,
    };
    game.audio
        .as_mut()
        .expect("audio")
        .play_bgm_audio(tone, true, 1.0);
    game.vm.vars.set_sys(100, 100);
    game.vm.vars.set_sys(101, 100);
    game.frame();
    let full = game.audio.as_ref().expect("audio").render_offline(64);
    assert!(
        (full[0] - 1.0).abs() < 1e-4,
        "100% BGM starts at unity, got {}",
        full[0]
    );

    game.start_engine_events();
    assert!(game.start_event(132), "CE132 starts");
    let id = game
        .vm
        .instances()
        .iter()
        .find(|inst| inst.event == 132)
        .map(|inst| inst.id)
        .expect("CE132 instance");
    for _ in 0..30 {
        game.frame();
    }
    goto_row(&mut game, id, 3);

    // Left lowers the BGM volume one step (1 or 5, depending on the current value).
    tap(&mut game, key::LEFT);
    let lowered = game.sys(100);
    assert!(
        (0..100).contains(&lowered),
        "left on the BGM row must lower Sys100, got {lowered}"
    );

    for _ in 0..3 {
        game.frame();
    }
    let quiet = game.audio.as_ref().expect("audio").render_offline(64);
    let expected = lowered as f32 / 100.0;
    assert!(
        (quiet[0] - expected).abs() < 1e-3,
        "the mixer follows the settings window live: Sys100={lowered} expected {expected}, got {}",
        quiet[0]
    );
    assert_eq!(game.stats.warnings, 0, "warnings");
}

/// PlayerTouch (trigger 3) is not used by any map this game registers.
///
/// The two shipped sample maps that *do* carry trigger-3 pages (`Dungeon.mps`,
/// `SampleMapB.mps`) are editor samples and are not reachable: MapTree/SysDatabase
/// register only TitleMap, SampleMapA, Map003, Map024 and Map031. That is why the
/// port leaves PlayerTouch dormant instead of modelling a walking player the game
/// never has (AGENTS.md §4).
#[test]
fn no_registered_map_uses_the_player_touch_trigger() {
    let Some(game) = open_game() else { return };
    let mut registered = Vec::new();
    for id in 0..50 {
        if let Some(path) = game.databases.map_path(id) {
            if path.trim().is_empty() || registered.iter().any(|seen| seen == path) {
                continue;
            }
            registered.push(path.to_owned());
        }
    }
    assert_eq!(
        registered.len(),
        5,
        "the shipped SysDatabase registers five maps, got {registered:?}"
    );

    for name in &registered {
        let file = data_root().join(name);
        let bytes = std::fs::read(&file).unwrap_or_else(|err| panic!("{}: {err}", file.display()));
        let map = wolf_format::mps::Map::parse(&bytes).expect("parse map");
        for event in &map.events {
            for (page, data) in event.pages.iter().enumerate() {
                assert_ne!(
                    data.trigger, 3,
                    "{name} event {} page {page} uses PlayerTouch, which the port does not model",
                    event.id
                );
            }
        }
    }
}
