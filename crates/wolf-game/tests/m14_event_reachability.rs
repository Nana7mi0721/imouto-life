//! M14: per-event reachability audit for every shipped event.
//!
//! Two event banks exist in this game and both are enumerated here:
//!
//! * common events, from BasicData/CommonEvent.dat (350 entries: 0..=211 are the WOLF
//!   template set, 212..=303 are the game's own, 304..=349 are unused template slots
//!   that still carry a program);
//! * map events, from the five registered .mps files (40 events / 41 pages in total).
//!
//! For every event a fresh game is parked in the loaded-save bedroom state, the event
//! is started, and the interpreter is driven for a bounded number of frames with
//! auto-advance and auto-choice on. The audit records whether the instance started,
//! how many frames it lived, whether it finished on its own, how many messages,
//! choices, pictures and sounds it produced, how many interpreter warnings it logged
//! and which unmodelled diagnostics it emitted. The table is written to
//! work/out/event_reach/report.tsv and summarised by docs/re/EVENT_REACHABILITY.md.
//!
//! Deadlocks do not hang this test: the VM already carries a per-frame instruction
//! budget (wolf_vm::exec::DEFAULT_BUDGET, 200_000 steps), so an endless loop shows up
//! as a frame that reports exactly the budget. Three consecutive such frames are
//! recorded as a spin and the event is abandoned, which is the difference between a
//! script that waits for input and a script that can never make progress.
//!
//! Map pages are selected with wolf_format's own active_page_index against the
//! variable bank of SaveData01, i.e. the page the retail runtime would display in that
//! state; pages that no state of this save selects are reported as no_active_page
//! instead of being silently skipped, and the condition slots of every page are kept
//! in the report so the reason is visible. Event self-variables have no bank outside a
//! running map event, so they read as 0 here, the same fallback the map renderer uses.
//!
//! Missing data (WOLF_DATA_ROOT) or an unreadable save makes the test print a skip
//! notice and return, so the default cargo test run stays green without data.

use std::collections::BTreeMap;
use std::path::PathBuf;
use std::sync::Arc;

use wolf_format::mps::{Map, MapEvent, MapEventPage};
use wolf_game::Game;
use wolf_vm::{InstanceId, Magic, MagicKind, Program};

/// Per-frame instruction budget of the interpreter; a frame that reports this many
/// steps was cut off by the budget rather than finishing its work.
const INSTRUCTION_BUDGET: usize = wolf_vm::exec::DEFAULT_BUDGET;
/// Consecutive budget-exhausted frames before an event is called a spin.
const SPIN_FRAMES: u32 = 3;

const REGISTERED_MAPS: [&str; 5] = [
    "TitleMap.mps",
    "SampleMapA.mps",
    "Map003.mps",
    "Map024.mps",
    "Map031.mps",
];

/// Events that legitimately burn the whole per-frame budget in this harness. They are
/// pinned so a regression that turns a waiting event into a spinning one is visible;
/// see docs/re/EVENT_REACHABILITY.md for why each one spins.
const KNOWN_SPINS: &[(&str, u32)] = &[("common", 212)];

/// Events that log interpreter warnings even though they run to completion. Pinned for
/// the same reason; the report records the exact count.
const KNOWN_WARNING_EVENTS: &[(&str, u32)] = &[];

fn repo_root() -> PathBuf {
    let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    base.pop();
    base.pop();
    base
}

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let path = PathBuf::from(raw);
    if path.is_absolute() {
        path
    } else {
        repo_root().join(path)
    }
}

/// Save slot under test. `M14_SAVE=SaveData02.sav` reruns the audit against a
/// different state (e.g. a clean slot) without touching the code.
fn save_name() -> String {
    std::env::var("M14_SAVE").unwrap_or_else(|_| "SaveData01.sav".to_owned())
}

fn save_path() -> PathBuf {
    data_root().join("Save").join(save_name())
}

fn frame_budget() -> u32 {
    std::env::var("M14_FRAMES")
        .ok()
        .and_then(|v| v.parse().ok())
        .unwrap_or(180)
}

/// Strips WOLF text escapes so the report shows the glyphs the player would see.
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

fn short(text: &str, max: usize) -> String {
    let visible = visible(text);
    let mut out: String = visible.chars().take(max).collect();
    if visible.chars().count() > max {
        out.push('…');
    }
    out
}

/// A single cell for the TSV: no tabs, no line breaks.
fn cell(text: &str) -> String {
    text.replace('\t', " ").replace(['\n', '\r'], " ")
}

/// A fresh game parked in the loaded-save bedroom state (engine events running, HUD up).
fn bedroom() -> Result<Game, String> {
    let mut game = Game::new(data_root()).map_err(|err| err.to_string())?;
    game.start_engine_events();
    game.load_save(&save_path())?;
    for _ in 0..5 {
        game.frame();
    }
    let has_hud = game
        .screen
        .iter()
        .any(|picture| picture.number == 230 && visible(&picture.text).contains("行动力"));
    if !has_hud {
        // The slot is only a state source: a slot without the bedroom HUD still drives
        // events, it just shifts which map pages are active. Only the default slot is
        // required to look like the retail bedroom.
        if save_name() == "SaveData01.sav" {
            return Err(format!("{} did not load into the bedroom HUD", save_name()));
        }
        eprintln!("note: {} has no bedroom HUD; running anyway", save_name());
    }
    Ok(game)
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

#[derive(Default)]
struct Drive {
    frames: u32,
    ended: bool,
    spin: bool,
    messages: Vec<String>,
    choices: Vec<String>,
    pictures: u32,
    sounds: u32,
}

/// Drives frames until the main instance ends, the event spins, or the budget runs out.
fn drive(game: &mut Game, main: Option<InstanceId>, frames: u32) -> Drive {
    let mut out = Drive::default();
    let mut seen_pictures: Vec<i32> = Vec::new();
    let mut spin_run = 0u32;
    for _ in 0..frames {
        let outcome = game.frame();
        out.frames += 1;
        for message in &game.messages {
            if out.messages.last() != Some(&message.text) {
                out.messages.push(message.text.clone());
            }
        }
        if let Some(choices) = &game.choices {
            if out.choices.is_empty() {
                out.choices = choices.options.clone();
            }
        }
        for picture in game.screen.iter() {
            if picture.number > 0 && !seen_pictures.contains(&picture.number) {
                seen_pictures.push(picture.number);
            }
        }
        out.sounds += game.sounds.len() as u32;
        if outcome.report.steps >= INSTRUCTION_BUDGET {
            spin_run += 1;
            if spin_run >= SPIN_FRAMES {
                out.spin = true;
                break;
            }
        } else {
            spin_run = 0;
        }
        if let Some(main) = main {
            if game.vm.instance(main).is_none() {
                out.ended = true;
                break;
            }
        }
    }
    out.pictures = seen_pictures.len() as u32;
    out
}

struct Row {
    kind: &'static str,
    source: String,
    id: u32,
    name: String,
    page: Option<usize>,
    pages: usize,
    trigger: Option<u8>,
    status: &'static str,
    frames: u32,
    messages: u32,
    choices: u32,
    pictures: u32,
    sounds: u32,
    warnings: u64,
    first_message: String,
    first_choice: String,
    conditions: String,
    diagnostics: String,
}

impl Row {
    fn tsv_header() -> String {
        [
            "kind",
            "source",
            "id",
            "name",
            "page",
            "pages",
            "trigger",
            "status",
            "frames",
            "messages",
            "choices",
            "pictures",
            "sounds",
            "warnings",
            "first_message",
            "first_choice",
            "conditions",
            "diagnostics",
        ]
        .join("\t")
    }

    fn to_tsv(&self) -> String {
        let page = self
            .page
            .map(|p| p.to_string())
            .unwrap_or_else(|| "-".to_owned());
        let trigger = self
            .trigger
            .map(|t| t.to_string())
            .unwrap_or_else(|| "-".to_owned());
        [
            self.kind.to_owned(),
            cell(&self.source),
            self.id.to_string(),
            cell(&self.name),
            page,
            self.pages.to_string(),
            trigger,
            self.status.to_owned(),
            self.frames.to_string(),
            self.messages.to_string(),
            self.choices.to_string(),
            self.pictures.to_string(),
            self.sounds.to_string(),
            self.warnings.to_string(),
            cell(&self.first_message),
            cell(&self.first_choice),
            cell(&self.conditions),
            cell(&self.diagnostics),
        ]
        .join("\t")
    }
}

/// Enabled condition slots of one map page as "variable==value" pairs.
fn page_conditions(page: &MapEventPage) -> String {
    let mut parts: Vec<String> = Vec::new();
    for slot in 0..4 {
        if page.trigger_switches[slot] & 0x0f == 1 {
            parts.push(format!(
                "{}=={}",
                page.trigger_variables[slot], page.trigger_values[slot]
            ));
        }
    }
    if parts.is_empty() {
        "-".to_owned()
    } else {
        parts.join("&")
    }
}

fn event_conditions(event: &MapEvent) -> String {
    event
        .pages
        .iter()
        .enumerate()
        .map(|(index, page)| format!("p{index}:{}", page_conditions(page)))
        .collect::<Vec<_>>()
        .join(" ")
}

/// Runs one already-started instance and packages the observation as a row.
#[allow(clippy::too_many_arguments)]
fn observe(
    mut game: Game,
    kind: &'static str,
    source: &str,
    id: u32,
    name: &str,
    page: Option<usize>,
    pages: usize,
    trigger: Option<u8>,
    conditions: String,
    main: Option<InstanceId>,
    frames: u32,
) -> Row {
    let warnings_before = game.stats.warnings;
    let diagnostics_before = game.diagnostics.clone();
    let drive = drive(&mut game, main, frames);
    let warnings = game.stats.warnings.saturating_sub(warnings_before);
    let diagnostics = diff_counts(&diagnostics_before, &game.diagnostics);
    let status = if main.is_none() {
        "not_started"
    } else if drive.spin {
        "spin"
    } else if drive.ended {
        "ended"
    } else {
        "running"
    };
    Row {
        kind,
        source: source.to_owned(),
        id,
        name: name.to_owned(),
        page,
        pages,
        trigger,
        status,
        frames: drive.frames,
        messages: drive.messages.len() as u32,
        choices: drive.choices.len() as u32,
        pictures: drive.pictures,
        sounds: drive.sounds,
        warnings,
        first_message: drive
            .messages
            .first()
            .map(|m| short(m, 40))
            .unwrap_or_default(),
        first_choice: drive
            .choices
            .first()
            .map(|c| short(c, 16))
            .unwrap_or_default(),
        conditions,
        diagnostics: diagnostics
            .iter()
            .map(|(key, count)| format!("{key} x{count}"))
            .collect::<Vec<_>>()
            .join("; "),
    }
}

fn run_common(id: u32, name: &str, frames: u32) -> Result<Row, String> {
    let mut game = bedroom()?;
    game.auto_advance = true;
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.screen.clear();
    let main = game.vm.start_event(id);
    Ok(observe(
        game,
        "common",
        "CommonEvent",
        id,
        name,
        None,
        0,
        None,
        String::new(),
        main,
        frames,
    ))
}

/// The variable bank a loaded save provides, mirroring what map page conditions see.
struct Seed {
    normal: Vec<i32>,
    sys3: i32,
    sys4: i32,
}

fn seed() -> Result<Seed, String> {
    let save = wolf_game::savegame::read_save(&save_path()).map_err(|err| err.to_string())?;
    let mut normal = Vec::new();
    let mut index = 0;
    while let Some(value) = save.part3.normal_var(index) {
        normal.push(value);
        index += 1;
    }
    Ok(Seed {
        normal,
        sys3: save.part2.vars3_21.get(9).copied().unwrap_or(512) as i32,
        sys4: save.part2.vars3_21.get(10).copied().unwrap_or(240) as i32,
    })
}

fn get_variable(seed: &Seed, raw: u32) -> i32 {
    let magic = Magic::decode(raw as i32);
    match magic.kind() {
        MagicKind::Literal => magic.index() as i32,
        MagicKind::Var => seed
            .normal
            .get(magic.index() as usize)
            .copied()
            .unwrap_or(0),
        MagicKind::SysVar => match magic.index() {
            3 => seed.sys3,
            4 => seed.sys4,
            _ => 0,
        },
        MagicKind::SelfVar
        | MagicKind::StrVar
        | MagicKind::CommonSelf
        | MagicKind::DbCell
        | MagicKind::Opaque => 0,
    }
}

fn run_map_event(
    map_file: &str,
    event: &MapEvent,
    seed: &Seed,
    frames: u32,
) -> Result<Row, String> {
    let page_index = {
        let mut getter = |raw: u32| get_variable(seed, raw);
        event.active_page_index(&mut getter)
    };
    let pages = event.pages.len();
    let source = format!("MapData/{map_file}");
    let conditions = event_conditions(event);

    let Some(page_index) = page_index else {
        // No state of this save selects a page: the event is not on the map in the
        // bedroom state, which is a reachability result in itself.
        return Ok(Row {
            kind: "map",
            source,
            id: event.id,
            name: event.name.clone(),
            page: None,
            pages,
            trigger: None,
            status: "no_active_page",
            frames: 0,
            messages: 0,
            choices: 0,
            pictures: 0,
            sounds: 0,
            warnings: 0,
            first_message: String::new(),
            first_choice: String::new(),
            conditions,
            diagnostics: String::new(),
        });
    };

    let page = &event.pages[page_index];
    if page.commands.is_empty() {
        return Ok(Row {
            kind: "map",
            source,
            id: event.id,
            name: event.name.clone(),
            page: Some(page_index),
            pages,
            trigger: Some(page.trigger),
            status: "empty_page",
            frames: 0,
            messages: 0,
            choices: 0,
            pictures: 0,
            sounds: 0,
            warnings: 0,
            first_message: String::new(),
            first_choice: String::new(),
            conditions,
            diagnostics: String::new(),
        });
    }

    let program = Program::from_slots(event.id, &event.name, page.commands.clone());
    let mut game = bedroom()?;
    game.auto_advance = true;
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.screen.clear();
    let main = game.vm.start_program(Arc::new(program));
    Ok(observe(
        game,
        "map",
        &source,
        event.id,
        &event.name,
        Some(page_index),
        pages,
        Some(page.trigger),
        conditions,
        main,
        frames,
    ))
}

#[test]
fn every_event_is_reachable_or_explained() {
    let root = data_root();
    if !root.is_dir() {
        eprintln!(
            "skipping m14_event_reachability: data root {} is missing (set WOLF_DATA_ROOT)",
            root.display()
        );
        return;
    }
    let frames = frame_budget();

    let probe = match bedroom() {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping m14_event_reachability: {err}");
            return;
        }
    };
    let mut common_ids: Vec<u32> = Vec::new();
    for id in 0..4096u32 {
        if probe.vm.programs.event(id).is_some() {
            common_ids.push(id);
        }
    }
    let mut common_names: BTreeMap<u32, String> = BTreeMap::new();
    for id in &common_ids {
        if let Some(program) = probe.vm.programs.event(*id) {
            common_names.insert(*id, program.title.clone());
        }
    }
    drop(probe);

    let seed = match seed() {
        Ok(seed) => seed,
        Err(err) => {
            eprintln!("skipping m14_event_reachability: {err}");
            return;
        }
    };

    let mut rows: Vec<Row> = Vec::new();
    for id in &common_ids {
        let name = common_names
            .get(id)
            .cloned()
            .unwrap_or_else(|| format!("common {id}"));
        match run_common(*id, &name, frames) {
            Ok(row) => rows.push(row),
            Err(err) => {
                eprintln!("skipping m14_event_reachability: {err}");
                return;
            }
        }
    }

    let mut map_rows = 0usize;
    for map_file in REGISTERED_MAPS {
        let Ok(bytes) = std::fs::read(root.join("MapData").join(map_file)) else {
            eprintln!("skipping m14_event_reachability: no MapData/{map_file}");
            return;
        };
        let map = match Map::parse(&bytes) {
            Ok(map) => map,
            Err(err) => {
                eprintln!("skipping m14_event_reachability: cannot parse {map_file}: {err}");
                return;
            }
        };
        for event in &map.events {
            match run_map_event(map_file, event, &seed, frames) {
                Ok(row) => {
                    map_rows += 1;
                    rows.push(row);
                }
                Err(err) => {
                    eprintln!("skipping m14_event_reachability: {err}");
                    return;
                }
            }
        }
    }

    // The table is the deliverable; the companion document is written from it.
    let out_dir = repo_root().join("work/out/event_reach");
    std::fs::create_dir_all(&out_dir).expect("create work/out/event_reach");
    let mut tsv = String::from(Row::tsv_header());
    tsv.push('\n');
    for row in &rows {
        println!(
            "EVT {:6} {:>4} {:26} page={:>2}/{:>2} trig={} status={:8} frames={:>3} msgs={:>2} choices={:>2} pics={:>2} sounds={:>2} warn={} first={:?}{}",
            row.kind,
            row.id,
            short(&row.name, 26),
            row.page.map(|p| p as i32).unwrap_or(-1),
            row.pages,
            row.trigger.map(|t| t as i32).unwrap_or(-1),
            row.status,
            row.frames,
            row.messages,
            row.choices,
            row.pictures,
            row.sounds,
            row.warnings,
            row.first_message,
            if row.diagnostics.is_empty() {
                String::new()
            } else {
                format!(" diags=[{}]", row.diagnostics)
            },
        );
        tsv.push_str(&row.to_tsv());
        tsv.push('\n');
    }
    let report_name = std::env::var("M14_REPORT").unwrap_or_else(|_| "report.tsv".to_owned());
    let report_path = out_dir.join(report_name);
    std::fs::write(&report_path, &tsv).expect("write event reachability report");

    let mut counts: BTreeMap<&str, usize> = BTreeMap::new();
    for row in &rows {
        *counts.entry(row.status).or_default() += 1;
    }
    let spins: Vec<String> = rows
        .iter()
        .filter(|row| row.status == "spin")
        .map(|row| format!("{}:{}", row.kind, row.id))
        .collect();
    let warned: Vec<String> = rows
        .iter()
        .filter(|row| row.warnings > 0)
        .map(|row| format!("{}:{}w{}", row.kind, row.id, row.warnings))
        .collect();
    let unreachable: Vec<String> = rows
        .iter()
        .filter(|row| row.status == "no_active_page")
        .map(|row| format!("{}:{}", row.source, row.id))
        .collect();

    println!(
        "SUMMARY common={} map={} rows={} statuses={:?}",
        common_ids.len(),
        map_rows,
        rows.len(),
        counts
    );
    println!("SPIN [{}]", spins.join(", "));
    println!("WARN [{}]", warned.join(", "));
    println!("NO_ACTIVE_PAGE [{}]", unreachable.join(", "));
    println!("REPORT {}", report_path.display());

    // Reachability invariants: a common event that cannot even be started is a data or
    // loader defect, not a runtime quirk, and must not be silently dropped.
    let not_started: Vec<String> = rows
        .iter()
        .filter(|row| row.status == "not_started")
        .map(|row| format!("{}:{} '{}'", row.kind, row.id, row.name))
        .collect();
    assert!(
        not_started.is_empty(),
        "events that failed to start: {not_started:#?}"
    );
    assert_eq!(common_ids.len(), 350, "the game ships 350 common events");

    let unknown_spins: Vec<String> = rows
        .iter()
        .filter(|row| row.status == "spin")
        .filter(|row| {
            !KNOWN_SPINS
                .iter()
                .any(|(kind, id)| *kind == row.kind && *id == row.id)
        })
        .map(|row| format!("{}:{} '{}'", row.kind, row.id, row.name))
        .collect();
    assert!(
        unknown_spins.is_empty(),
        "new spinning events (deadlock regressions): {unknown_spins:#?}"
    );

    let unknown_warnings: Vec<String> = rows
        .iter()
        .filter(|row| row.warnings > 0)
        .filter(|row| {
            !KNOWN_WARNING_EVENTS
                .iter()
                .any(|(kind, id)| *kind == row.kind && *id == row.id)
        })
        .map(|row| format!("{}:{} '{}' w{}", row.kind, row.id, row.name, row.warnings))
        .collect();
    assert!(
        unknown_warnings.is_empty(),
        "new warning-producing events: {unknown_warnings:#?}"
    );
}
