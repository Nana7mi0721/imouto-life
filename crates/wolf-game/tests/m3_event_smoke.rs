//! M3-E: smoke-run every one of the game's own common events (212..=303).
//!
//! Each event is started from the loaded-save bedroom state on a fresh game, run for a
//! bounded number of frames, and its externally visible behaviour is recorded: whether it
//! started, how many frames it ran, whether it finished, the messages / choices / pictures /
//! sounds it produced, and any interpreter warnings or unmodelled diagnostics. The companion
//! document docs/M3_EVENT_MAP.md is generated from this test's output.
//!
//! Missing data (WOLF_DATA_ROOT) or an unreadable save causes the whole test to skip, matching
//! the rest of the suite.

use std::collections::BTreeMap;
use std::path::PathBuf;

use wolf_game::Game;

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

/// Strips WOLF text escapes so assertions see the glyphs the player would see.
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

/// A fresh game parked in the loaded-save bedroom state (engine events running, HUD restored).
fn bedroom() -> Result<Game, String> {
    let mut game = Game::new(data_root()).map_err(|err| err.to_string())?;
    game.start_engine_events();
    let save = data_root().join("Save").join("SaveData01.sav");
    game.load_save(&save)?;
    for _ in 0..5 {
        game.frame();
    }
    let has_hud = game
        .screen
        .iter()
        .any(|picture| picture.number == 230 && visible(&picture.text).contains("行动力"));
    if !has_hud {
        return Err("SaveData01 did not load into the bedroom HUD".to_owned());
    }
    Ok(game)
}

#[derive(Default)]
struct EventReport {
    warn_base: u64,
    started: bool,
    frames_run: u32,
    ended: bool,
    messages: Vec<String>,
    choices: Vec<String>,
    pictures: BTreeMap<i32, String>,
    sounds: u32,
    warnings: u64,
    diagnostics: BTreeMap<String, u64>,
}

fn diff_counts(
    before: &BTreeMap<String, u64>,
    after: &BTreeMap<String, u64>,
) -> BTreeMap<String, u64> {
    let mut out = BTreeMap::new();
    for (key, value) in after {
        let prev = before.get(key).copied().unwrap_or(0);
        if *value > prev {
            out.insert(key.clone(), value - prev);
        }
    }
    out
}

fn run_one(id: u32, frames: u32) -> Result<EventReport, String> {
    let mut game = bedroom()?;
    game.auto_advance = true;
    game.auto_choice = true;
    game.auto_choice_delay = 2;

    let warnings_before = game.stats.warnings;
    let diagnostics_before = game.diagnostics.clone();
    game.screen.clear();

    let before: Vec<u32> = game.vm.instances().iter().map(|inst| inst.id).collect();
    let mut report = EventReport::default();
    report.warn_base = warnings_before;
    report.started = game.start_event(id);
    if !report.started {
        return Ok(report);
    }
    let main = game
        .vm
        .instances()
        .iter()
        .find(|inst| inst.event == id && !before.contains(&inst.id))
        .map(|inst| inst.id);

    for _ in 0..frames {
        game.frame();
        report.frames_run += 1;
        for message in &game.messages {
            if !report.messages.iter().any(|seen| seen == &message.text) {
                report.messages.push(message.text.clone());
            }
        }
        if let Some(choices) = &game.choices {
            if report.choices.is_empty() {
                report.choices = choices.options.clone();
            }
        }
        for picture in game.screen.iter() {
            if picture.number > 0 {
                report.pictures.insert(picture.number, picture.text.clone());
            }
        }
        report.sounds += game.sounds.len() as u32;
        if let Some(main) = main {
            if game.vm.instance(main).is_none() {
                report.ended = true;
                break;
            }
        }
    }
    report.warnings = game.stats.warnings - warnings_before;
    report.diagnostics = diff_counts(&diagnostics_before, &game.diagnostics);
    Ok(report)
}

fn frame_budget() -> u32 {
    std::env::var("M3_FRAMES")
        .ok()
        .and_then(|v| v.parse().ok())
        .unwrap_or(180)
}

fn selected_ids() -> Vec<u32> {
    if let Ok(raw) = std::env::var("M3_IDS") {
        return raw
            .split(',')
            .filter_map(|part| part.trim().parse().ok())
            .collect();
    }
    (212..=303).collect()
}

/// Events that cannot be smoke-run standalone and are documented instead of executed.
/// CE212 is a parameterised helper: it is invoked by other events with arguments in its self
/// variables, and with the default self=0 its opcode-170 loop never satisfies the opcode-112
/// exit comparison (self1600006 / self1600008), so it spins forever. See docs/M3_EVENT_MAP.md.
const CONTEXT_DEPENDENT: &[(u32, &str)] = &[(
    212,
    "parameterised bubble-text helper; standalone self=0 loops forever at opcode170",
)];

fn short(text: &str, max: usize) -> String {
    let visible = visible(text);
    let mut out: String = visible.chars().take(max).collect();
    if visible.chars().count() > max {
        out.push('…');
    }
    out
}

/// Baseline behaviour of the bedroom with no event started: isolates engine-background
/// warnings/diagnostics so they are not misattributed to individual events.
fn control(frames: u32) -> Result<(u64, BTreeMap<String, u64>), String> {
    let mut game = bedroom()?;
    let warnings_before = game.stats.warnings;
    let diagnostics_before = game.diagnostics.clone();
    for _ in 0..frames {
        game.frame();
    }
    Ok((
        game.stats.warnings - warnings_before,
        diff_counts(&diagnostics_before, &game.diagnostics),
    ))
}

#[test]
fn smoke_events() {
    let ids = selected_ids();
    let frames = frame_budget();
    let mut rows: Vec<(u32, Result<EventReport, String>)> = Vec::new();
    let mut context_rows: Vec<u32> = Vec::new();
    let mut skipped = None;
    for id in ids {
        if CONTEXT_DEPENDENT.iter().any(|(ctx, _)| *ctx == id) {
            println!("EVT {id:>3} CONTEXT-DEPENDENT (not run)");
            context_rows.push(id);
            continue;
        }
        match run_one(id, frames) {
            Ok(report) => rows.push((id, Ok(report))),
            Err(err) => {
                // A missing data root / save only manifests on the first attempt; skip all.
                if rows.is_empty() {
                    skipped = Some(err);
                    break;
                }
                rows.push((id, Err(err)));
            }
        }
    }
    if let Some(reason) = skipped {
        eprintln!("skipping m3_event_smoke: {reason}");
        return;
    }

    match control(frames) {
        Ok((warnings, diagnostics)) => {
            let keys: Vec<String> = diagnostics
                .iter()
                .map(|(k, v)| format!("{k}x{v}"))
                .collect();
            println!(
                "CONTROL frames={frames} warn={warnings} diags=[{}]",
                keys.join(";")
            );
        }
        Err(err) => println!("CONTROL error {err}"),
    }

    let mut failures = Vec::new();
    for (id, result) in &rows {
        match result {
            Ok(report) => {
                let first = report
                    .messages
                    .first()
                    .map(|m| short(m, 24))
                    .unwrap_or_default();
                let choice = report
                    .choices
                    .first()
                    .map(|c| short(c, 12))
                    .unwrap_or_default();
                let diag: Vec<String> = report
                    .diagnostics
                    .iter()
                    .map(|(k, v)| format!("{k}x{v}"))
                    .collect();
                let diag_text = diag.join(";");
                println!(
                    "EVT {id:>3} started={} frames={:>3} ended={} msgs={:>2} choices={:>2} pics={:>2} sounds={:>2} warn={} wbase={} diags=[{}]{}{}",
                    report.started,
                    report.frames_run,
                    report.ended,
                    report.messages.len(),
                    report.choices.len(),
                    report.pictures.len(),
                    report.sounds,
                    report.warnings,
                    report.warn_base,
                    diag_text,
                    if first.is_empty() { String::new() } else { format!(" first=\"{first}\"") },
                    if choice.is_empty() { String::new() } else { format!(" choice=\"{choice}\"") },
                );
                if !report.started {
                    failures.push(format!("event {id} did not start"));
                }
                if report.frames_run == 0 {
                    failures.push(format!("event {id} ran 0 frames"));
                }
                if report.warnings > 0 {
                    failures.push(format!("event {id} logged {} warning(s)", report.warnings));
                }
            }
            Err(err) => {
                println!("EVT {id:>3} ERROR {err}");
                failures.push(format!("event {id} errored: {err}"));
            }
        }
    }

    println!(
        "SUMMARY run={} context_dependent={} failures={}",
        rows.len(),
        context_rows.len(),
        failures.len()
    );
    for failure in &failures {
        eprintln!("FAIL {failure}");
    }
    assert!(failures.is_empty(), "{} event(s) failed", failures.len());
}
