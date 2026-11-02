//! M3-Q — real save-UI end-to-end write/load round trip.
//!
//! Drives the actual in-game save/load screens (CE131 reached via the 220
//! SaveLoad opcode) through the shipped data set:
//!
//!   1. SAVE phase: from the bedroom (SaveData01 loaded) open the save menu
//!      (CE131), move the cursor to the empty 4th grid slot and confirm. The
//!      game's own 220 opcode writes \`Save/SaveData03.sav\`.
//!   2. LOAD phase: a fresh game boots to the title menu, chooses "load",
//!      walks the CE42 -> CE14 -> CE131 chain, selects slot 3 and confirms.
//!      The 220 opcode reads the slot back and the bedroom HUD reappears.
//!
//! Safety: the whole Save/ directory is snapshotted (bytes + fingerprint)
//! before anything is written and restored by a drop guard, so SaveData01,
//! SaveData02, System.sav are never left modified and the temporary
//! SaveData03 is removed even if an assertion panics.  SaveData01/02 and
//! System.sav are checked to be byte-identical afterwards.
//!
//! Assertions cover: playtime, all 302 normal variables (0..302, with the
//! per-frame engine scratch at index 0 excluded after the load), picture
//! geometry of the restored bedroom (compared against a direct SaveData01
//! load) and that the load screen really went through the 220 opcode path.
//!
//! When the game data is absent the test prints "skipping: ..." and returns,
//! keeping the default no-data test run green.

use std::path::{Path, PathBuf};

use wolf_game::savegame;
use wolf_game::Game;

/// The empty save slot this test writes into. Only slot 3 is ever touched.
const SLOT: u32 = 3;
/// Number of normal (non-Sys) variables persisted in a save file row.
const NORMAL_VARS: usize = 302;

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_string());
    let path = PathBuf::from(raw);
    if path.is_absolute() {
        return path;
    }
    // Resolve a relative data root against the workspace root (two levels up
    // from crates/wolf-game), matching the other wolf-game integration tests.
    let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    base.pop();
    base.pop();
    base.join(path)
}

fn save_dir() -> PathBuf {
    data_root().join("Save")
}

fn save_file(slot: u32) -> PathBuf {
    save_dir().join(format!("SaveData{slot:02}.sav"))
}

/// Small non-cryptographic fingerprint (FNV-1a) used to detect any change to
/// an existing save file without adding a dependency.
fn fingerprint(bytes: &[u8]) -> u64 {
    let mut h: u64 = 0xcbf29ce484222325;
    for &b in bytes {
        h ^= b as u64;
        h = h.wrapping_mul(0x100000001b3);
    }
    h
}

/// Fingerprints of every regular file currently in \`dir\`, sorted by name.
fn dir_fingerprints(dir: &Path) -> Vec<(String, u64)> {
    let mut out = Vec::new();
    let Ok(entries) = std::fs::read_dir(dir) else {
        return out;
    };
    for entry in entries.flatten() {
        if entry.metadata().map(|m| m.is_file()).unwrap_or(false) {
            let name = entry.file_name().to_string_lossy().into_owned();
            if let Ok(bytes) = std::fs::read(entry.path()) {
                out.push((name, fingerprint(&bytes)));
            }
        }
    }
    out.sort();
    out
}

/// Snapshot a Game's rendered picture geometry for comparison.  Text picture
/// payloads are codec-lossy so only non-text text is kept; position/size/order
/// fields form the geometry being compared.
#[derive(Debug, Clone, PartialEq, Eq)]
struct Pic {
    number: i32,
    file: String,
    hidden: bool,
    x: i32,
    y: i32,
    opacity: i32,
    scale: i32,
    anchor: u8,
    text: String,
}

fn snapshot(game: &Game) -> Vec<Pic> {
    let mut pics: Vec<Pic> = game
        .screen
        .iter()
        .map(|p| Pic {
            number: p.number,
            file: p.file.clone(),
            hidden: p.hidden,
            x: p.x,
            y: p.y,
            opacity: p.opacity,
            scale: p.scale,
            anchor: p.anchor,
            text: if p.kind.is_text() {
                String::new()
            } else {
                p.text.clone()
            },
        })
        .collect();
    pics.sort_by_key(|p| (p.number, p.file.clone(), p.x, p.y));
    pics
}

/// Strip the engine's inline escape sequences (e.g. \`\E\`, \`\[...]\`) from a
/// picture's text so HUD assertions read cleanly.
fn visible(raw: &str) -> String {
    let mut out = String::new();
    let mut it = raw.chars().peekable();
    while let Some(c) = it.next() {
        if c as u32 != 92 {
            out.push(c);
            continue;
        }
        while let Some(&ch) = it.peek() {
            if ch.is_ascii_alphanumeric() {
                it.next();
            } else {
                break;
            }
        }
        if it.peek() == Some(&'[') {
            for ch in it.by_ref() {
                if ch == ']' {
                    break;
                }
            }
        }
    }
    out
}

/// Concatenate every visible text picture on screen, for substring checks.
fn hud_text(game: &Game) -> String {
    game.screen
        .iter()
        .map(|p| visible(&p.text))
        .collect::<Vec<_>>()
        .join("|")
}

fn text_at(game: &Game, number: i32) -> String {
    game.screen
        .iter()
        .find(|p| p.number == number)
        .map(|p| visible(&p.text))
        .unwrap_or_default()
}

fn is_running(game: &Game, event: u32) -> bool {
    game.vm.instances().iter().any(|i| i.event == event)
}

/// Load SaveData01 straight into a fresh Game (auto-advancing, no interaction).
/// This is the reference "bedroom HUD" used to validate the UI load geometry.
/// Returns None (after printing why) when the data set is missing.
fn open_loaded(slot: u32) -> Option<Game> {
    let path = save_file(slot);
    if !path.is_file() {
        eprintln!("skipping: {} not found", path.display());
        return None;
    }
    let mut game = match Game::new(data_root()) {
        Ok(g) => g,
        Err(err) => {
            eprintln!("skipping: {err}");
            return None;
        }
    };
    if let Err(err) = savegame::load_into(&mut game, &path) {
        eprintln!("skipping: {err}");
        return None;
    }
    game.auto_advance = true;
    game.auto_choice = false;
    Some(game)
}

/// Press a key for one interaction cycle: hold for 24 frames, release for 6.
/// Returns the number of frames elapsed (30).
fn press(game: &mut Game, bits: u32) -> usize {
    game.key_bits = bits;
    for _ in 0..24 {
        game.frame();
    }
    game.key_bits = 0;
    for _ in 0..6 {
        game.frame();
    }
    30
}

/// Hold `bits` until `done`, then settle.
///
/// The engine reports a held key again after Sys15 frames (キーリピート速度), so a
/// fixed-length hold would step the grid more than once. Waiting for the observable
/// result instead gives exactly one report, like a player tapping the key.
fn hold_until(
    game: &mut Game,
    bits: u32,
    frames: usize,
    mut done: impl FnMut(&Game) -> bool,
) -> usize {
    game.key_bits = bits;
    let mut n = 0;
    while n < frames && !done(game) {
        game.frame();
        n += 1;
    }
    game.key_bits = 0;
    for _ in 0..8 {
        game.frame();
        n += 1;
    }
    n
}

/// CE131's grid cursor as `(row, column)` self variables.
fn grid_cursor(game: &Game) -> Option<(i32, i32)> {
    game.vm
        .instances()
        .iter()
        .find(|inst| inst.event == 131)
        .map(|inst| (inst.self_vars.get(610), inst.self_vars.get(611)))
}

/// Guards the Save/ directory: snapshots every file, and on drop restores the
/// snapshot and deletes anything created during the test.  Also exposes the
/// pre-test fingerprints so existing files can be checked untouched mid-test
/// and the directory checked fully restored after cleanup.
struct SaveGuard {
    dir: PathBuf,
    baseline: Vec<(String, Vec<u8>)>,
}

impl SaveGuard {
    fn new(root: &Path) -> Option<SaveGuard> {
        let dir = root.join("Save");
        if !dir.is_dir() {
            eprintln!("skipping: {} is not a directory", dir.display());
            return None;
        }
        let mut baseline = Vec::new();
        for entry in std::fs::read_dir(&dir).ok()?.flatten() {
            if entry.metadata().map(|m| m.is_file()).unwrap_or(false) {
                let name = entry.file_name().to_string_lossy().into_owned();
                let bytes = std::fs::read(entry.path()).ok()?;
                baseline.push((name, bytes));
            }
        }
        baseline.sort_by(|a, b| a.0.cmp(&b.0));
        Some(SaveGuard { dir, baseline })
    }

    /// Fingerprints of the files that existed before the test.
    fn baseline_fingerprints(&self) -> Vec<(String, u64)> {
        let mut v: Vec<(String, u64)> = self
            .baseline
            .iter()
            .map(|(n, b)| (n.clone(), fingerprint(b)))
            .collect();
        v.sort();
        v
    }

    /// Assert every pre-existing save file is still byte-identical.
    fn assert_existing_unchanged(&self) {
        for (name, bytes) in &self.baseline {
            let current = std::fs::read(self.dir.join(name))
                .unwrap_or_else(|e| panic!("pre-existing save {name} disappeared: {e}"));
            assert_eq!(
                current.len(),
                bytes.len(),
                "pre-existing save {name} length changed"
            );
            assert_eq!(
                fingerprint(&current),
                fingerprint(bytes),
                "pre-existing save {name} content changed"
            );
        }
    }
}

impl Drop for SaveGuard {
    fn drop(&mut self) {
        // Restore every original file.
        for (name, bytes) in &self.baseline {
            let _ = std::fs::write(self.dir.join(name), bytes);
        }
        // Remove anything that was not present before (e.g. SaveData03.sav).
        if let Ok(entries) = std::fs::read_dir(&self.dir) {
            for entry in entries.flatten() {
                let name = entry.file_name().to_string_lossy().into_owned();
                if !self.baseline.iter().any(|(n, _)| n == &name) {
                    let _ = std::fs::remove_file(entry.path());
                }
            }
        }
    }
}

#[test]
fn save_ui_writes_slot3_then_loads_it_back() {
    // ---- Preconditions / safety net -------------------------------------
    if !data_root().join("Save").join("SaveData01.sav").is_file() {
        eprintln!(
            "skipping: SaveData01.sav not found under {}",
            data_root().display()
        );
        return;
    }
    if save_file(SLOT).exists() {
        eprintln!("skipping: slot {SLOT} already contains data");
        return;
    }
    let Some(guard) = SaveGuard::new(&data_root()) else {
        return;
    };
    let original_fingerprints = guard.baseline_fingerprints();

    // A game sitting in the bedroom with SaveData01 loaded (19:30 etc.).
    let Some(mut game) = open_loaded(1) else {
        return;
    };

    // Sentinel normal variables whose values prove the round trip target the
    // exact slot we saved (they are not derivable from default state).
    game.vm.vars.set(20, 77);
    game.vm.vars.set(123, 4242);
    let memory_vars: Vec<i32> = (0..NORMAL_VARS).map(|i| game.vm.vars.get(i)).collect();
    let playtime_before = game.playtime_frames;

    // ---- SAVE phase: open the save screen and write the empty slot 3 ----
    // The save menu is an overlay: the current scene (the bedroom HUD) stays
    // on screen underneath, exactly as in game, so the saved picture table is
    // the full bedroom snapshot that a later load restores.
    assert!(game.start_event(131), "CE131 (save UI) did not start");

    for _ in 0..30 {
        game.frame();
    }
    assert!(
        text_at(&game, 12002).contains("保存"),
        "save header not shown: {:?}",
        text_at(&game, 12002)
    );
    assert_eq!(text_at(&game, 12052), "1", "slot 1 label");
    assert_eq!(text_at(&game, 12072), "2", "slot 2 label");
    assert_eq!(text_at(&game, 12092), "3", "slot 3 label");
    assert_eq!(text_at(&game, 12112), "4", "slot 4 label");
    assert_eq!(
        text_at(&game, 12093),
        "没有数据",
        "slot 3 should start empty, got {:?}",
        text_at(&game, 12093)
    );
    assert!(
        game.choices.is_none(),
        "save screen must not expose a choice list"
    );

    // Cursor starts on slot 1 (top-left); one DOWN moves to the bottom row,
    // where slot 3 lives, then OK confirms.
    // The grid is a four-row list; slot 3 is row 2. Hold until the cursor is there
    // (the engine's repeat makes one hold walk several rows).
    hold_until(&mut game, wolf_game::key::DOWN, 80, |g| {
        grid_cursor(g).map(|(row, _)| row) == Some(2)
    });
    assert!(
        is_running(&game, 131),
        "save UI closed after moving the cursor"
    );

    hold_until(&mut game, wolf_game::key::OK, 80, |_| {
        save_file(SLOT).exists()
    });

    for _ in 0..60 {
        game.frame();
    }

    assert!(
        save_file(SLOT).is_file(),
        "CE131 did not create {}",
        save_file(SLOT).display()
    );
    assert_eq!(game.stats.warnings, 0, "save UI produced warnings");
    assert!(
        game.diagnostics
            .keys()
            .any(|k| k.contains("220 SaveLoad: wrote")),
        "save did not go through the 220 opcode path: diagnostics {:?}",
        game.diagnostics.keys().collect::<Vec<_>>()
    );

    // ---- Inspect the written file against in-memory state ---------------
    let save = savegame::read_save(&save_file(SLOT))
        .unwrap_or_else(|e| panic!("failed to parse slot {SLOT}: {e}"));
    assert!(save.checksum_ok(), "slot {SLOT} checksum is invalid");
    assert!(!save.name.is_empty(), "slot {SLOT} has no save name");
    assert_eq!(save.file_version, 0x80, "unexpected save file version");

    let stored_vars: Vec<i32> = (0..NORMAL_VARS)
        .map(|i| save.part3.normal_var(i).expect("normal var slot"))
        .collect();
    assert_eq!(
        stored_vars, memory_vars,
        "saved normal variables do not match the game state at save time"
    );
    assert_eq!(
        save.part3.normal_var(20),
        Some(77),
        "sentinel v20 not stored"
    );
    assert_eq!(
        save.part3.normal_var(123),
        Some(4242),
        "sentinel v123 not stored"
    );

    let saved_playtime = save.part2.vars3_21.first().copied().unwrap_or(0);
    assert!(
        saved_playtime >= playtime_before,
        "saved playtime {saved_playtime} < playtime before save {playtime_before}"
    );
    assert!(
        saved_playtime <= game.playtime_frames,
        "saved playtime {saved_playtime} > playtime after save {}",
        game.playtime_frames
    );
    let saved_pictures = save.part5.events.len();
    assert!(
        saved_pictures > 0,
        "save file records no pictures (expected the save-screen snapshot)"
    );

    // Existing saves must be untouched even before cleanup.
    guard.assert_existing_unchanged();

    // ---- LOAD phase: boot to title, load, and read slot 3 back ----------
    let mut loader = match Game::new(data_root()) {
        Ok(g) => g,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    loader.auto_advance = true;
    loader.auto_choice = false;
    if let Err(err) = loader.boot() {
        eprintln!("skipping: {err}");
        return;
    }

    let mut frames_run = 0usize;
    let mut title_menu: Option<Vec<String>> = None;
    for _ in 0..240 {
        loader.frame();
        frames_run += 1;
        if let Some(choices) = &loader.choices {
            title_menu = Some(choices.options.clone());
            break;
        }
    }
    assert_eq!(
        title_menu,
        Some(vec![
            "menu1".to_string(),
            "menu2".to_string(),
            "menu3".to_string()
        ]),
        "unexpected title menu"
    );

    // Index 1 is the "load game" entry.
    loader.set_choice_cursor(1);
    frames_run += press(&mut loader, wolf_game::key::OK);
    for _ in 0..60 {
        loader.frame();
        frames_run += 1;
    }
    assert!(
        is_running(&loader, 14) && is_running(&loader, 131),
        "load UI chain (CE14 -> CE131) did not open, events {:?}",
        loader
            .vm
            .instances()
            .iter()
            .map(|i| i.event)
            .collect::<Vec<_>>()
    );
    assert!(
        text_at(&loader, 12002).contains("读取"),
        "load header not shown: {:?}",
        text_at(&loader, 12002)
    );

    // Move to slot 3's row and confirm the load, one report per key like a tap.
    frames_run += hold_until(&mut loader, wolf_game::key::DOWN, 80, |g| {
        grid_cursor(g).map(|(row, _)| row) == Some(2)
    });
    frames_run += hold_until(&mut loader, wolf_game::key::OK, 80, |g| {
        g.vm.vars.get(20) == 77
    });
    for _ in 0..150 {
        loader.frame();
        frames_run += 1;
    }

    // The load applied: sentinels from the saved slot are now live.
    assert_eq!(
        loader.vm.vars.get(20),
        77,
        "load did not restore the saved sentinel v20 (wrong slot?)"
    );
    assert_eq!(
        loader.vm.vars.get(123),
        4242,
        "load did not restore sentinel v123"
    );
    assert!(
        loader
            .diagnostics
            .keys()
            .any(|k| k.contains("220 SaveLoad: loaded")),
        "load did not go through the 220 opcode path: diagnostics {:?}",
        loader.diagnostics.keys().collect::<Vec<_>>()
    );

    // Close the load screen; the menu chain should unwind to engine events.
    frames_run += press(&mut loader, wolf_game::key::CANCEL);
    for _ in 0..60 {
        loader.frame();
        frames_run += 1;
    }
    let leftover: Vec<u32> = loader
        .vm
        .instances()
        .iter()
        .map(|i| i.event)
        .filter(|e| [14, 42, 131].contains(e))
        .collect();
    assert!(
        leftover.is_empty(),
        "load UI did not close cleanly, still running {leftover:?}"
    );
    assert_eq!(loader.stats.warnings, 0, "load UI produced warnings");

    // ---- Compare restored state with the saved file ---------------------
    // Index 0 is per-frame engine scratch (cleared to 0), so compare 1..302.
    for i in 1..NORMAL_VARS {
        assert_eq!(
            loader.vm.vars.get(i),
            save.part3.normal_var(i).expect("normal var slot"),
            "normal variable {i} differs after reload"
        );
    }
    assert_eq!(loader.vm.vars.get(7), 10000, "money (v7) not restored");
    assert!(
        loader.playtime_frames >= saved_playtime
            && (loader.playtime_frames as usize) <= saved_playtime as usize + frames_run,
        "reloaded playtime {} outside [{saved_playtime}, {saved_playtime}+{frames_run}]",
        loader.playtime_frames
    );

    // HUD reflects the restored state.
    let hud = hud_text(&loader);
    assert!(hud.contains("19:30"), "HUD time missing after load: {hud}");
    assert!(
        hud.contains("周一"),
        "HUD weekday missing after load: {hud}"
    );
    assert!(
        hud.contains("持有金钱"),
        "HUD money label missing after load: {hud}"
    );
    assert!(
        hud.contains("10000円"),
        "HUD money value missing after load: {hud}"
    );

    // Picture geometry of the restored bedroom must match a direct load of
    // SaveData01 (same base snapshot; only the sentinel vars differ).
    //
    // SaveData01 is the player's live save and may currently have been written
    // from inside the save screen, in which case its Part5 also carries that
    // screen's own overlay pictures (numbers 12000..12199). Those are not part of
    // the bedroom field, so compare only the field/HUD layers and ignore them.
    let Some(reference) = open_loaded(1) else {
        return;
    };
    let field_only = |mut pics: Vec<Pic>| {
        pics.retain(|p| !(12_000..=12_199).contains(&p.number));
        pics
    };
    let loaded_snapshot = field_only(snapshot(&loader));
    let reference_snapshot = field_only(snapshot(&reference));
    assert_eq!(
        loaded_snapshot.len(),
        reference_snapshot.len(),
        "restored picture count differs from reference bedroom"
    );
    assert_eq!(
        loaded_snapshot, reference_snapshot,
        "restored picture geometry differs from reference bedroom"
    );

    // ---- Cleanup and final integrity check ------------------------------
    drop(guard);
    assert!(
        !save_file(SLOT).exists(),
        "temporary slot {} was not cleaned up",
        SLOT
    );
    assert_eq!(
        dir_fingerprints(&save_dir()),
        original_fingerprints,
        "Save directory was not restored to its original state"
    );
}
