//! M3-V: CE132 system-settings screen — in-memory edits and the System.sav
//! persistence contract.
//!
//! CE132 ("システム欄実行", the settings screen runner) is driven for real: the test
//! walks the menu to the BGM-volume row with opcode-123 key polls and raises the
//! volume, which the common event writes to system variable Sys100 (with Sys101 kept
//! in sync for the on-screen number). What this proves and what it exposes:
//!
//! * The settings UI really edits the live system variables (Sys100 / Sys101), with
//!   zero interpreter warnings.
//! * This engine has NO script-driven path that rewrites Save/System.sav from those
//!   variables. No common event contains a 220 save or a 222 system-variable write aimed
//!   at System.sav (only CE48/CE94 read it with 221, and CE131 saves the numbered slots),
//!   so after the screen runs the file is byte-for-byte unchanged and no "220 SaveLoad"
//!   or "222 SaveGame" diagnostic appears. The retail WOLF engine persists the BGM/SE
//!   volumes at exit by copying Sys100/Sys102 into System.sav part 2 vars72_74; the Rust
//!   port now exposes that bridge explicitly as `Game::sync_live_settings` /
//!   `Game::save_system_settings` (see crates/wolf-game/src/settings.rs), and the tests
//!   below drive it through a temporary copy only.
//! * The file-format side of that contract is checked directly: part 2 vars72_74 is the
//!   BGM/SE/ambient volume trio, and a value edited there survives an encrypt/decrypt
//!   round-trip with a valid checksum and every neighbouring field intact.
//!
//! Safety: the on-disk Save/System.sav is backed up (bytes + sha/len) to
//! work/out/m3_settings_backup/ and restored by a Drop guard even on panic, so the
//! file is guaranteed byte-identical after the test. The numbered save slots
//! (SaveData01/02) are never touched, and every persistence test writes to
//! `target/test-scratch/`, not to the data root.
//!
//! Everything skips cleanly when work/Data is absent (default workspace run, exit 0).

use std::path::PathBuf;

use wolf_game::settings::GlobalSettings;
use wolf_game::Game;
use wolf_save::SaveFile;

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

fn repo_root() -> PathBuf {
    let mut root = data_root();
    root.pop();
    root.pop();
    root
}

fn visible(raw: &str) -> String {
    let mut out = String::new();
    let mut chars = raw.chars().peekable();
    while let Some(c) = chars.next() {
        if (c as u32) != 92 {
            out.push(c);
            continue;
        }
        while let Some(&ch) = chars.peek() {
            if ch.is_ascii_alphanumeric() {
                chars.next();
            } else {
                break;
            }
        }
        if chars.peek() == Some(&'[') {
            for ch in chars.by_ref() {
                if ch == ']' {
                    break;
                }
            }
        }
    }
    out
}

fn bedroom() -> Option<Game> {
    let mut game = match Game::new(data_root()) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: {err}");
            return None;
        }
    };
    game.start_engine_events();
    let save = data_root().join("Save").join("SaveData01.sav");
    if let Err(err) = game.load_save(&save) {
        eprintln!("skipping: {err}");
        return None;
    }
    for _ in 0..5 {
        game.frame();
    }
    let has_hud = game
        .screen
        .iter()
        .any(|picture| picture.number == 230 && visible(&picture.text).contains("行动力"));
    if !has_hud {
        eprintln!("skipping: SaveData01 did not reach the bedroom HUD");
        return None;
    }
    Some(game)
}

fn fnv(bytes: &[u8]) -> u64 {
    let mut h: u64 = 0xcbf2_9ce4_8422_2325;
    for &b in bytes {
        h ^= b as u64;
        h = h.wrapping_mul(0x1_0000_0001_b3);
    }
    h
}

struct SystemSaveGuard {
    path: PathBuf,
    original: Vec<u8>,
    original_sha: u64,
}

impl SystemSaveGuard {
    fn install() -> Option<Self> {
        let path = data_root().join("Save").join("System.sav");
        let original = match std::fs::read(&path) {
            Ok(bytes) => bytes,
            Err(err) => {
                eprintln!("skipping: cannot read {}: {err}", path.display());
                return None;
            }
        };
        let sha = fnv(&original);
        let backup_dir = repo_root()
            .join("work")
            .join("out")
            .join("m3_settings_backup");
        if std::fs::create_dir_all(&backup_dir).is_ok() {
            let _ = std::fs::write(backup_dir.join("System.sav"), &original);
        }
        eprintln!(
            "System.sav backed up: {} bytes sha={sha:016x}",
            original.len()
        );
        Some(Self {
            path,
            original,
            original_sha: sha,
        })
    }

    fn assert_untouched(&self, context: &str) {
        let after = std::fs::read(&self.path).expect("re-read System.sav");
        assert_eq!(
            after.len(),
            self.original.len(),
            "{context}: System.sav length changed"
        );
        assert_eq!(
            fnv(&after),
            self.original_sha,
            "{context}: System.sav bytes changed"
        );
        assert_eq!(after, self.original, "{context}: System.sav not restored");
    }
}

impl Drop for SystemSaveGuard {
    fn drop(&mut self) {
        match std::fs::read(&self.path) {
            Ok(current) if current == self.original => {}
            _ => {
                let _ = std::fs::write(&self.path, &self.original);
            }
        }
    }
}

fn bits(code: i32) -> u32 {
    wolf_game::key::bits_for_code(code)
}

fn hold_until(
    game: &mut Game,
    code: i32,
    max_frames: usize,
    mut done: impl FnMut(&Game) -> bool,
) -> bool {
    for _ in 0..max_frames {
        game.key_bits = bits(code);
        game.frame();
        if done(game) {
            game.key_bits = 0;
            return true;
        }
    }
    game.key_bits = 0;
    done(game)
}

fn self_slot(game: &Game, id: u32, slot: usize) -> i32 {
    game.vm
        .instance(id)
        .map(|inst| inst.self_vars.get(600 + slot))
        .unwrap_or(-1)
}

struct Ce132Run {
    sys100_before: i32,
    sys100_after: i32,
    sys101_after: i32,
    sys102_after: i32,
    warnings_delta: u64,
    diag_keys: Vec<String>,
}

fn drive_ce132_bgm_volume() -> Option<Ce132Run> {
    let mut game = bedroom()?;
    game.vm.vars.set_sys(100, 100);
    game.vm.vars.set_sys(101, 100);
    game.vm.vars.set_sys(102, 100);
    let warnings_before = game.stats.warnings;
    let diagnostics_before = game.diagnostics.clone();

    assert!(game.start_event(132), "CE132 must start");
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
    assert_eq!(
        self_slot(&game, id, 10),
        0,
        "cursor starts on the first row"
    );

    let reached = hold_until(&mut game, 2, 300, |g| self_slot(g, id, 10) >= 3);
    assert!(reached, "down key must reach the BGM-volume row (index 3)");
    game.key_bits = 0;
    for _ in 0..6 {
        game.frame();
    }
    assert_eq!(self_slot(&game, id, 10), 3, "cursor parked on BGM volume");

    let sys100_before = game.sys(100);
    assert_eq!(sys100_before, 100, "seeded BGM volume");

    let changed = hold_until(&mut game, 6, 200, |g| g.sys(100) > sys100_before);
    assert!(changed, "right key must raise the BGM volume");
    game.key_bits = 0;
    for _ in 0..4 {
        game.frame();
    }

    let sys100_after = game.sys(100);
    let sys101_after = game.sys(101);
    let sys102_after = game.sys(102);
    assert!(
        sys100_after > sys100_before && sys100_after <= 120,
        "BGM volume after right press: {sys100_after} (started {sys100_before}, WOLF clamps at 120)"
    );
    assert_eq!(sys101_after, sys100_after, "Sys101 mirrors the BGM volume");
    assert_eq!(sys102_after, 100, "SE volume untouched while editing BGM");

    let mut diag_keys = Vec::new();
    for (key, count) in &game.diagnostics {
        let before = diagnostics_before.get(key).copied().unwrap_or(0);
        if *count > before {
            diag_keys.push(key.clone());
        }
    }
    let warnings_delta = game.stats.warnings - warnings_before;

    Some(Ce132Run {
        sys100_before,
        sys100_after,
        sys101_after,
        sys102_after,
        warnings_delta,
        diag_keys,
    })
}

#[test]
fn ce132_edits_live_volume_but_has_no_system_sav_save_path() {
    let Some(guard) = SystemSaveGuard::install() else {
        return;
    };
    let Some(run) = drive_ce132_bgm_volume() else {
        return;
    };

    assert_eq!(run.sys100_before, 100);
    assert!(
        run.sys100_after > 100 && run.sys100_after <= 120,
        "BGM volume changed in memory: {} -> {}",
        run.sys100_before,
        run.sys100_after
    );
    assert_eq!(run.sys101_after, run.sys100_after);
    assert_eq!(run.sys102_after, 100);
    assert_eq!(run.warnings_delta, 0, "CE132 volume edit must not warn");

    for key in &run.diag_keys {
        let lower = key.to_ascii_lowercase();
        assert!(
            !key.contains("220") && !key.contains("222") && !lower.contains("save"),
            "unexpected save diagnostic from CE132: {key}"
        );
    }

    guard.assert_untouched("after CE132");
    eprintln!(
        "CE132: Sys100 {} -> {} (Sys101 {}), System.sav untouched (no 220/222 persistence path)",
        run.sys100_before, run.sys100_after, run.sys101_after
    );
}

#[test]
fn system_sav_part2_roundtrips_the_bgm_volume_field() {
    let Some(guard) = SystemSaveGuard::install() else {
        return;
    };
    let original = guard.original.clone();
    let save = SaveFile::parse(&original).expect("parse System.sav");
    assert!(
        save.checksum_ok(),
        "System.sav checksum must validate before editing"
    );

    let before = save.part2.vars72_74;
    assert!(
        before.iter().all(|&v| v <= 120),
        "volume trio should be within WOLF's 0..=120 range: {before:?}"
    );

    let new_bgm = if before[0] == 120 { 100 } else { 120 };
    let mut edited = save.clone();
    edited.part2.vars72_74[0] = new_bgm;
    let part2 = edited.part2.clone();
    edited
        .set_part2(&part2)
        .expect("set_part2 re-encodes part 2");

    let written = edited.to_bytes().expect("to_bytes encrypts the file");
    let back = SaveFile::parse(&written).expect("re-parse the re-encoded System.sav");
    assert!(
        back.checksum_ok(),
        "round-tripped System.sav checksum must validate"
    );
    assert_eq!(
        back.part2.vars72_74[0], new_bgm,
        "edited BGM volume survives the encrypt/decrypt round-trip"
    );

    assert_eq!(
        &back.part2.vars72_74[1..],
        &before[1..],
        "SE/ambient volumes unchanged"
    );
    assert_eq!(
        back.part2.vars42_45, save.part2.vars42_45,
        "window colour unchanged"
    );
    assert_eq!(
        back.part2.vars64_69, save.part2.vars64_69,
        "key-config unchanged"
    );
    assert_eq!(back.part2.bgm, save.part2.bgm, "BGM slot table unchanged");
    assert_eq!(
        back.part2.block109, save.part2.block109,
        "background block unchanged"
    );
    assert_eq!(back.part2.var82, save.part2.var82);

    guard.assert_untouched("after format round-trip");
    eprintln!(
        "System.sav part2.vars72_74 {before:?} -> BGM {new_bgm}, checksum ok, neighbours intact"
    );
}
// ---------------------------------------------------------------------------
// The runtime settings API (M3 gap #3): Save/System.sav part 2 <-> live Sys vars.
// ---------------------------------------------------------------------------

/// Scratch directory for the persistence tests. Everything here is disposable; the
/// real data root is never written.
fn scratch_dir() -> PathBuf {
    PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../target/test-scratch/m3_settings")
}

fn open_settings_game() -> Option<Game> {
    match Game::new(data_root()) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!("skipping settings test: {err}");
            None
        }
    }
}

/// The shipped System.sav is the settings source: volumes 100/100/100, the three
/// keyboard key code/flag pairs, and the window colour.
#[test]
fn game_reads_system_save_settings_and_seeds_the_live_sys_vars() {
    let Some(guard) = SystemSaveGuard::install() else {
        return;
    };
    let Some(game) = open_settings_game() else {
        return;
    };

    let settings = game.settings();
    assert_eq!(settings.bgm_volume, 100, "System.sav BGM volume");
    assert_eq!(settings.se_volume, 100, "System.sav SE volume");
    assert_eq!(settings.ambient_volume, 100, "System.sav ambient volume");
    assert_eq!(
        settings.key_config,
        [144, 16, 145, 32, 146, 64],
        "raw key-config words from System.sav"
    );
    assert_eq!(
        settings.window_colour,
        [160, 68, 75, 200],
        "window colour from System.sav"
    );

    // CE132 reads these variables; the engine seeds them at boot (CE48 does not).
    assert_eq!(game.sys(100), 100, "Sys100 BGM volume seeded");
    assert_eq!(game.sys(101), 100, "Sys101 mirrors it");
    assert_eq!(game.sys(102), 100, "Sys102 SE volume seeded");
    assert_eq!(game.sys(52), 144, "Sys52 keyboard decide code (pair 0)");
    assert_eq!(game.sys(53), 145, "Sys53 keyboard cancel code (pair 1)");
    assert_eq!(game.sys(54), 146, "Sys54 keyboard sub code (pair 2)");
    assert!(
        !game.settings_dirty(),
        "boot values equal the persisted ones"
    );
    assert_eq!(game.stats.warnings, 0);

    guard.assert_untouched("after reading settings");
}

/// `set_settings` writes the template and the live Sys variables, and `live_settings`
/// reads the same values back.
#[test]
fn set_settings_round_trips_the_template_and_live_vars() {
    let Some(guard) = SystemSaveGuard::install() else {
        return;
    };
    let Some(mut game) = open_settings_game() else {
        return;
    };

    let custom = GlobalSettings {
        bgm_volume: 73,
        se_volume: 41,
        ambient_volume: 66,
        key_config: [150, 16, 151, 32, 152, 64],
        window_colour: [1, 2, 3, 4],
    };
    game.set_settings(custom).expect("set_settings");

    assert_eq!(
        game.settings(),
        custom,
        "the save template carries the new settings"
    );
    assert_eq!(
        game.live_settings(),
        custom,
        "live_settings merges the Sys overlay"
    );
    assert_eq!(game.sys(100), 73);
    assert_eq!(game.sys(101), 73, "Sys101 mirrors the BGM volume");
    assert_eq!(game.sys(102), 41);
    assert_eq!(game.sys(52), 150);
    assert_eq!(game.sys(53), 151);
    assert_eq!(game.sys(54), 152);
    assert!(
        !game.settings_dirty(),
        "set_settings synchronises the live pair"
    );

    // With no audio engine this is a no-op, but it must not panic or warn.
    game.apply_settings();
    assert_eq!(game.stats.warnings, 0);
    guard.assert_untouched("after set_settings");
}

/// Out-of-range values clamp exactly where the retail settings screen clamps.
#[test]
fn set_settings_clamps_volumes_to_the_retail_120_ceiling() {
    let Some(guard) = SystemSaveGuard::install() else {
        return;
    };
    let Some(mut game) = open_settings_game() else {
        return;
    };
    let settings = GlobalSettings {
        bgm_volume: 999,
        se_volume: 0,
        ambient_volume: 121,
        ..GlobalSettings::default()
    };
    game.set_settings(settings).expect("set_settings");
    let read = game.settings();
    assert_eq!(read.bgm_volume, wolf_game::settings::VOLUME_MAX);
    assert_eq!(read.se_volume, 0);
    assert_eq!(read.ambient_volume, wolf_game::settings::VOLUME_MAX);
    guard.assert_untouched("after clamped set_settings");
}

/// The atomic write produces a parseable, checksummed System.sav with every unrelated
/// field intact — exercised on a temporary copy.
#[test]
fn save_system_settings_writes_a_checksummed_copy_without_touching_the_real_file() {
    let Some(guard) = SystemSaveGuard::install() else {
        return;
    };
    let Some(mut game) = open_settings_game() else {
        return;
    };

    let original = SaveFile::parse(&guard.original).expect("parse System.sav");
    let custom = GlobalSettings {
        bgm_volume: 88,
        se_volume: 64,
        ambient_volume: 100,
        key_config: [144, 16, 145, 32, 146, 64],
        window_colour: [160, 68, 75, 200],
    };
    game.set_settings(custom).expect("set_settings");

    let dir = scratch_dir();
    let _ = std::fs::remove_dir_all(&dir);
    std::fs::create_dir_all(&dir).expect("scratch dir");
    let path = dir.join("System.sav");
    game.write_system_settings(&path)
        .expect("write_system_settings");
    assert!(
        !dir.join("System.sav.new").exists(),
        "the .new file is renamed away"
    );

    let bytes = std::fs::read(&path).expect("read copy");
    let written = SaveFile::parse(&bytes).expect("parse written System.sav");
    assert!(
        written.checksum_ok(),
        "the written file carries a valid checksum"
    );
    let part2 = &written.part2;
    assert_eq!(part2.vars72_74, [88, 64, 100], "volume trio persisted");
    assert_eq!(
        part2.vars64_69,
        [144, 16, 145, 32, 146, 64],
        "keys untouched"
    );
    assert_eq!(
        part2.vars42_45,
        [160, 68, 75, 200],
        "window colour untouched"
    );

    // Neighbouring fields of the settings record are byte-identical to the original.
    assert_eq!(part2.vars40_41, original.part2.vars40_41);
    assert_eq!(part2.vars46_48, original.part2.vars46_48);
    assert_eq!(part2.block100, original.part2.block100);
    assert_eq!(part2.bgm, original.part2.bgm);
    assert_eq!(part2.block109, original.part2.block109);
    assert_eq!(part2.var82, original.part2.var82);
    assert_eq!(written.file_version, original.file_version);

    let _ = std::fs::remove_dir_all(&dir);
    guard.assert_untouched("after writing a copy");
}

/// The CE132 -> System.sav bridge: a live Sys100 edit is dirty until synced into the
/// template, and the sync writes the same value the UI shows.
#[test]
fn live_ce132_volume_edits_only_persist_through_the_explicit_bridge() {
    let Some(guard) = SystemSaveGuard::install() else {
        return;
    };
    let Some(mut game) = open_settings_game() else {
        return;
    };
    assert!(!game.settings_dirty());
    game.vm.vars.set_sys(100, 120);
    game.vm.vars.set_sys(101, 120);
    assert!(game.settings_dirty(), "an unsynced live edit is reported");

    game.sync_live_settings().expect("sync_live_settings");
    assert!(!game.settings_dirty(), "sync clears the dirty flag");
    assert_eq!(
        game.settings().bgm_volume,
        120,
        "the template now carries the CE132 value"
    );
    guard.assert_untouched("after sync_live_settings");
}

/// The volume scale maps onto the mixer gain, and 101..120 saturates at unity.
#[test]
fn apply_settings_moves_the_mixer_gain() {
    let Some(guard) = SystemSaveGuard::install() else {
        return;
    };
    let Some(mut game) = open_settings_game() else {
        return;
    };
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
        .play_bgm_audio(tone.clone(), true, 1.0);
    game.audio.as_mut().expect("audio").play_se_audio(tone, 1.0);

    game.vm.vars.set_sys(100, 50);
    game.vm.vars.set_sys(102, 25);
    game.apply_settings();
    let rendered = game.audio.as_ref().expect("audio").render_offline(64);
    // BGM 0.5 + SE 0.25 = 0.75 on every channel; the mixer clamps at unity.
    assert!(
        (rendered[0] - 0.75).abs() < 1e-4,
        "50% BGM + 25% SE mix to 0.75, got {}",
        rendered[0]
    );

    // 120 is louder on paper but the mixer clamps its master gain to unity; with the SE
    // voice stopped that leaves exactly 1.0.
    game.audio.as_mut().expect("audio").stop_all_se();
    game.vm.vars.set_sys(100, 120);
    game.apply_settings();
    let rendered = game.audio.as_ref().expect("audio").render_offline(64);
    assert!(
        (rendered[0] - 1.0).abs() < 1e-4,
        "120% saturates at unity, got {}",
        rendered[0]
    );

    game.vm.vars.set_sys(100, 0);
    game.apply_settings();
    let rendered = game.audio.as_ref().expect("audio").render_offline(64);
    assert!(
        rendered[0].abs() < 1e-4,
        "0% is silent, got {}",
        rendered[0]
    );
    guard.assert_untouched("after mixer gain checks");
}
/// Loading a numbered save changes the save *template* but must not change the player's
/// global settings: System.sav stays the settings source.
#[test]
fn loading_a_numbered_save_does_not_change_the_global_settings() {
    let Some(guard) = SystemSaveGuard::install() else {
        return;
    };
    let Some(mut game) = open_settings_game() else {
        return;
    };
    let before = game.settings();
    let path = data_root().join("Save").join("SaveData01.sav");
    if let Err(err) = game.load_save(&path) {
        eprintln!("skipping: cannot load SaveData01: {err}");
        return;
    }
    assert_eq!(
        game.settings(),
        before,
        "a loaded slot's part 2 must not replace the System.sav settings"
    );
    assert_eq!(
        game.sys(100),
        before.bgm_volume as i32,
        "live volume unchanged"
    );
    assert!(
        game.system_save.is_some(),
        "the pristine System.sav template survives a numbered load"
    );
    guard.assert_untouched("after loading SaveData01");
}

/// Persisting after a numbered load still writes the System.sav skeleton, not the
/// loaded slot's map snapshot/object tables.
#[test]
fn save_system_settings_after_a_load_keeps_the_system_save_skeleton() {
    let Some(guard) = SystemSaveGuard::install() else {
        return;
    };
    let Some(mut game) = open_settings_game() else {
        return;
    };
    let original = SaveFile::parse(&guard.original).expect("parse System.sav");
    let path = data_root().join("Save").join("SaveData01.sav");
    if let Err(err) = game.load_save(&path) {
        eprintln!("skipping: cannot load SaveData01: {err}");
        return;
    }
    game.set_settings(GlobalSettings {
        bgm_volume: 60,
        se_volume: 70,
        ..GlobalSettings::default()
    })
    .expect("set_settings");

    let dir = scratch_dir();
    let _ = std::fs::remove_dir_all(&dir);
    std::fs::create_dir_all(&dir).expect("scratch dir");
    let out = dir.join("System.sav");
    game.write_system_settings(&out)
        .expect("write_system_settings");
    let written = SaveFile::parse(&std::fs::read(&out).expect("read")).expect("parse");
    assert_eq!(
        written.part1, original.part1,
        "the written System.sav keeps System.sav's map snapshot, not SaveData01's"
    );
    assert_eq!(
        written.part4, original.part4,
        "object tables stay System.sav's"
    );
    assert_eq!(
        written.part2.vars72_74,
        [60, 70, 100],
        "the edited volumes are persisted"
    );
    let _ = std::fs::remove_dir_all(&dir);
    guard.assert_untouched("after persist-from-loaded-session");
}
