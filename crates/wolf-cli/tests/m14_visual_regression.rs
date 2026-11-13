//! M14: deterministic visual-regression suite for the offscreen capture path.
//!
//! Five fixed scenes are rendered through the real wolf-cli capture path and their
//! frame statistics are pinned: frame count, peak coroutine count, live pictures,
//! textured quads, text pictures, atlas images, text items/glyphs/lines, decoded
//! non-black pixel count, message/choice operation counts and warnings.
//!
//! The suite is black-box on purpose: the capture pipeline (Game -> CaptureFrame ->
//! Renderer -> PNG) lives inside the wolf-cli binary, so each scene spawns the
//! freshly built binary and parses its human-readable report. The PNG itself is
//! decoded and cross-checked against the reported pixel count, so a renderer change
//! that silently stops writing the image cannot pass.
//!
//! Numbers were recorded on the working tree that also carries the sysgraphic
//! <GRADX>/<GRADY> gradient fix (black texture instead of white); re-record them
//! whenever a deliberate rendering change lands, and note why in the commit message.
//! Two consecutive captures of every scene produced byte-identical PNGs and
//! identical stdout, so the pinning is meaningful rather than flaky.
//!
//! 2026-11-13 (T18 follow-up): the day_command and hud text counts moved by one
//! because the host now splits CE242's action-point picture (slot 230) into a
//! label and a value run for the project's extra gauge. The pixel baselines did
//! not move: the parked side drawers are still drawn at retail's 20% handle alpha
//! (see [`SIDE_PANEL_PARKED_ALPHA`] in wolf-game), even though T18 stopped the
//! per-frame CE238/CE239 repaint that used to produce it as a side effect.
//!
//! Fixtures live under work/Data (gitignored). When the data root or the save
//! fixture is missing, the affected scene prints a skip notice and returns, matching
//! the rest of the suite: the default cargo test run must stay green without data.
//!
//! The offscreen wgpu context is not safe to overlap with itself in this harness, so
//! the five scenes run serially under one process-wide lock.

use std::path::{Path, PathBuf};
use std::process::Command;
use std::sync::Mutex;

use image::GenericImageView;

const SCREEN_W: u32 = 1024;
const SCREEN_H: u32 = 576;
const TOTAL_PIXELS: u64 = (SCREEN_W as u64) * (SCREEN_H as u64);

/// Offscreen wgpu capture is single-instance; scenes must not run in parallel.
static CAPTURE_LOCK: Mutex<()> = Mutex::new(());

#[derive(Debug)]
struct Baseline {
    name: &'static str,
    /// Arguments after capture; the save path is injected for load-save scenes.
    args: &'static [&'static str],
    load_save: bool,
    /// The scene reads Save/SaveData01.sav (directly or through the save grid).
    /// The baselines were recorded with the shipping 50-picture save; a player save
    /// overwrites the same file, so the scene skips instead of reporting a false
    /// renderer failure when that fixture no longer matches.
    depends_on_save: bool,
    /// The save-grid scene's baseline was recorded with the two shipping slots
    /// (SaveData01/02). A third save enlarges the grid and changes the pinned
    /// picture/text/pixel counts, so that is fixture drift rather than a renderer
    /// regression.
    depends_on_save_grid: bool,
    expect_header: &'static str,
    frames: u32,
    peak_coroutines: u32,
    pictures_live: u32,
    textured_quads: u32,
    text_pictures: u32,
    choice_open: bool,
    choice_options: u32,
    atlas_images: u32,
    text_items: u32,
    text_glyphs: u32,
    text_lines: u32,
    nonblack: u64,
    messages: u32,
    choices: u32,
}

#[derive(Debug)]
struct Metrics {
    frames: u32,
    peak_coroutines: u32,
    pictures_live: u32,
    textured_quads: u32,
    text_pictures: u32,
    choice_open: bool,
    choice_options: u32,
    atlas_images: u32,
    text_items: u32,
    text_glyphs: u32,
    text_lines: u32,
    width: u32,
    height: u32,
    nonblack: u64,
    png_nonblack: u64,
    messages: u32,
    choices: u32,
    warnings: u32,
}

const BASELINES: [Baseline; 5] = [
    Baseline {
        name: "title",
        args: &["--frames", "240"],
        load_save: false,
        depends_on_save: false,
        depends_on_save_grid: false,
        expect_header: "  entry     : boot map (TitleMap.mps event 2)",
        frames: 240,
        // The first frame starts the engine coroutines and the boot map chain together:
        // 48/270/271/216/63/2 plus CE270's transient CE264/CE265 calls. They settle to
        // the title, HUD and menu coroutines after the splash chain finishes.
        peak_coroutines: 8,
        pictures_live: 4,
        textured_quads: 4,
        text_pictures: 0,
        choice_open: true,
        choice_options: 3,
        atlas_images: 4,
        text_items: 0,
        text_glyphs: 0,
        text_lines: 0,
        nonblack: 499_899,
        messages: 0,
        choices: 1,
    },
    Baseline {
        name: "map_idle",
        args: &["--map", "SampleMapA", "--frames", "600"],
        load_save: false,
        depends_on_save: false,
        depends_on_save_grid: false,
        expect_header: "  map       : MapData/SampleMapA.mps 64x36 tile(s)",
        frames: 600,
        // CE216 (the always-on interest monitor) is part of ENGINE_RESTART and
        // re-enters on top of the idle map's five coroutines. It renders no pixels.
        peak_coroutines: 6,
        pictures_live: 1,
        textured_quads: 27_649,
        text_pictures: 0,
        choice_open: false,
        choice_options: 0,
        atlas_images: 17,
        text_items: 0,
        text_glyphs: 0,
        text_lines: 0,
        nonblack: 589_474,
        messages: 0,
        choices: 0,
    },
    Baseline {
        // The save/load window: nine-slot grid, gradient backdrop, page title and the
        // right-hand command column. 40 frames is the settled state; the earlier 300
        // frame variant pinned identical picture/text geometry but burned more
        // instruction budget, so the shorter scene is the one worth keeping.
        //
        // Snapshot taken 2026-11-03 after the CursorBase/WindowBase and slot-font fixes:
        // the former produced a 928x115 black frame around every slot and the latter moved
        // the labels to the 16 px raster face. Re-recorded again after the HUD anchor fix
        // (only anchor-3 pictures inside a tenths-scale UI block are centred now), which
        // changed the atlas from 20 to 19 images and the non-black count to 589251.
        //
        // Re-recorded 2026-11-12 after restoring CE94's tenths geometry: the slot boxes
        // are 9280x1152 again (rendered 928x115.2), so the UI text uses the regular
        // weight with 13 text pictures / 54 glyphs, and the real `<TRI-RIGHT>` arrow is
        // visible (21 atlas images / 27728 textured quads). The non-black count moved
        // by the cursor-blink phase; CE216 adds one coroutine.
        name: "saveui",
        args: &["--map", "SampleMapA", "--event", "5", "--frames", "40"],
        load_save: false,
        depends_on_save: true,
        depends_on_save_grid: true,
        expect_header: "  map       : MapData/SampleMapA.mps 64x36 tile(s)",
        frames: 40,
        peak_coroutines: 9,
        pictures_live: 25,
        textured_quads: 27_728,
        text_pictures: 13,
        choice_open: false,
        choice_options: 0,
        atlas_images: 21,
        text_items: 13,
        text_glyphs: 54,
        text_lines: 13,
        nonblack: 576_221,
        messages: 0,
        choices: 0,
    },
    Baseline {
        // CE245 (night command) on a resumed save: the five-action menu is held,
        // exactly the layout the retail screenshot EE3763D0 shows.
        name: "day_command",
        args: &["--event", "245", "--frames", "240"],
        load_save: true,
        depends_on_save: true,
        depends_on_save_grid: false,
        expect_header: "  entry     : save file",
        frames: 240,
        // +1 for the restarting CE270 display pass (see the title scene).
        peak_coroutines: 8,
        pictures_live: 50,
        textured_quads: 23,
        // T18 splits CE242's `行动力 current/max` picture (slot 230) into a label run
        // at x=560 and a value run at x=668 so the host can draw the gauge between
        // them, which adds one text picture, one item and one line versus the retail
        // single-run layout. The non-black count is unchanged: the vacated gap sits
        // on the lit top bar, and the same glyphs still cover the same row.
        text_pictures: 24,
        choice_open: true,
        choice_options: 5,
        atlas_images: 7,
        text_items: 23,
        text_glyphs: 76,
        text_lines: 23,
        nonblack: 533_187,
        messages: 0,
        choices: 1,
    },
    Baseline {
        // Plain HUD after loading SaveData01: date/time/stat bar, no menu.
        name: "hud",
        args: &["--frames", "60"],
        load_save: true,
        depends_on_save: true,
        depends_on_save_grid: false,
        expect_header: "  entry     : save file",
        frames: 60,
        // +1 for the restarting CE270 display pass (see the title scene), and +1 for
        // CE216, which is in ENGINE_RESTART and likewise renders no pixels.
        peak_coroutines: 8,
        pictures_live: 50,
        textured_quads: 5,
        // Same slot-230 split as the day_command scene: one extra text picture,
        // item and line for the action-point label/value runs.
        text_pictures: 15,
        choice_open: false,
        choice_options: 0,
        atlas_images: 5,
        text_items: 14,
        text_glyphs: 44,
        text_lines: 14,
        nonblack: 554_890,
        messages: 0,
        choices: 0,
    },
];

#[test]
fn title_scene_matches_its_baseline() {
    run_baseline(baseline("title"));
}

#[test]
fn map_idle_scene_matches_its_baseline() {
    run_baseline(baseline("map_idle"));
}

#[test]
fn save_ui_scene_matches_its_baseline() {
    run_baseline(baseline("saveui"));
}

#[test]
fn day_command_menu_scene_matches_its_baseline() {
    run_baseline(baseline("day_command"));
}

#[test]
fn hud_scene_matches_its_baseline() {
    run_baseline(baseline("hud"));
}

fn baseline(name: &str) -> &'static Baseline {
    BASELINES
        .iter()
        .find(|baseline| baseline.name == name)
        .expect("baseline name must exist")
}

fn repo_root() -> PathBuf {
    Path::new(env!("CARGO_MANIFEST_DIR"))
        .parent()
        .and_then(Path::parent)
        .expect("crates/wolf-cli must live two levels below the repository root")
        .to_path_buf()
}

fn data_root() -> PathBuf {
    match std::env::var_os("WOLF_DATA_ROOT") {
        Some(value) => {
            let path = PathBuf::from(value);
            if path.is_absolute() {
                path
            } else {
                repo_root().join(path)
            }
        }
        None => repo_root().join("work/Data"),
    }
}

fn save_fixture() -> PathBuf {
    data_root().join("Save").join("SaveData01.sav")
}

/// True when SaveData01 still carries the shipping 50-picture bedroom state.
///
/// The baselines below were recorded against that file. A normal player save (or
/// the game's own save screen) rewrites SaveData01 with its current picture table,
/// which changes the whole frame; that is fixture drift, not a renderer change, so
/// the save-dependent scenes skip instead of failing. The save round-trip tests are
/// the ones that must catch a real format/load regression.
fn shipping_save_fixture() -> bool {
    let Ok(bytes) = std::fs::read(save_fixture()) else {
        return false;
    };
    let Ok(save) = wolf_save::SaveFile::parse(&bytes) else {
        return false;
    };
    save.part5.events.len() == 50
}

/// True when the save grid has exactly the two shipping slots.
///
/// The save UI renders one block per existing `SaveDataNN.sav`. Tests and smoke
/// runs can create SaveData03+, which adds a fourth block but does not change the
/// renderer. Checking the grid separately from SaveData01 keeps that fixture drift
/// from being reported as a 101-pixel visual regression.
fn shipping_save_grid() -> bool {
    let Ok(entries) = std::fs::read_dir(data_root().join("Save")) else {
        return false;
    };
    let mut has_first = false;
    let mut has_second = false;
    let mut slots = 0;
    for entry in entries.flatten() {
        let name = entry.file_name();
        let name = name.to_string_lossy();
        if name.starts_with("SaveData") && name.ends_with(".sav") {
            slots += 1;
            has_first |= name == "SaveData01.sav";
            has_second |= name == "SaveData02.sav";
        }
    }
    slots == 2 && has_first && has_second
}

fn run_baseline(baseline: &'static Baseline) {
    let Some(metrics) = capture_scene(baseline) else {
        return;
    };
    assert_scene(baseline, &metrics);
    println!(
        "scene {:11} frames {:4} peak {:2} pictures {:3} quads {:5} textpics {:2} atlas {:2} text {}/{}/{} nonblack {:6}/{} messages {:2} choices {:2} warnings {}",
        baseline.name,
        metrics.frames,
        metrics.peak_coroutines,
        metrics.pictures_live,
        metrics.textured_quads,
        metrics.text_pictures,
        metrics.atlas_images,
        metrics.text_items,
        metrics.text_glyphs,
        metrics.text_lines,
        metrics.nonblack,
        TOTAL_PIXELS,
        metrics.messages,
        metrics.choices,
        metrics.warnings,
    );
}

fn capture_scene(baseline: &'static Baseline) -> Option<Metrics> {
    let root = data_root();
    if !root.is_dir() {
        eprintln!(
            "skipping {}: data root {} is missing (set WOLF_DATA_ROOT)",
            baseline.name,
            root.display()
        );
        return None;
    }
    if baseline.load_save && !save_fixture().is_file() {
        eprintln!(
            "skipping {}: save fixture {} is missing",
            baseline.name,
            save_fixture().display()
        );
        return None;
    }
    if baseline.depends_on_save && !shipping_save_fixture() {
        eprintln!(
            "skipping {}: SaveData01 is no longer the shipping 50-picture bedroom (a player save overwrote it); the save round-trip suite covers format/load",
            baseline.name
        );
        return None;
    }
    if baseline.depends_on_save_grid && !shipping_save_grid() {
        eprintln!(
            "skipping {}: Save/ has extra or missing slots (the baseline uses SaveData01/02 only; SaveData03+ enlarges the grid)",
            baseline.name
        );
        return None;
    }

    let out_dir = repo_root().join("work/out/m14_visual");
    std::fs::create_dir_all(&out_dir).expect("create work/out/m14_visual");
    let png_path = out_dir.join(format!("{}.png", baseline.name));
    let log_path = out_dir.join(format!("{}.log", baseline.name));

    let _guard = CAPTURE_LOCK
        .lock()
        .unwrap_or_else(|poisoned| poisoned.into_inner());

    let mut command = Command::new(env!("CARGO_BIN_EXE_wolf-cli"));
    command.current_dir(repo_root());
    // Capture with the game's own fonts. An inherited WOLF_GAME_DIR (used by some
    // wolf-save fixtures) has no TTF, which silently drops every glyph and changes
    // every text metric; pin the font source so these fixtures stay independent.
    command.env_remove("WOLF_GAME_DIR");
    command.arg("--root").arg(&root);
    command.arg("capture");
    if baseline.load_save {
        command.arg("--load-save").arg(save_fixture());
    }
    for arg in baseline.args {
        command.arg(arg);
    }
    command.arg("--out").arg(&png_path);

    let output = command
        .output()
        .unwrap_or_else(|err| panic!("{}: cannot spawn wolf-cli: {err}", baseline.name));
    let stdout = String::from_utf8_lossy(&output.stdout).into_owned();
    let stderr = String::from_utf8_lossy(&output.stderr).into_owned();
    std::fs::write(&log_path, format!("{stdout}{stderr}")).expect("write capture log");
    assert!(
        output.status.success(),
        "{}: capture failed with status {}\nstdout:\n{stdout}\nstderr:\n{stderr}",
        baseline.name,
        output.status
    );
    assert!(
        stdout.contains(baseline.expect_header),
        "{}: capture output did not contain header {:?}\n--- stdout ---\n{stdout}",
        baseline.name,
        baseline.expect_header
    );
    if baseline.load_save {
        assert!(
            stdout.contains("SaveData01.sav"),
            "{}: the save fixture must be the one that was loaded\n--- stdout ---\n{stdout}",
            baseline.name
        );
    }

    let metrics = parse_metrics(baseline.name, &stdout);
    let png = image::open(&png_path).unwrap_or_else(|err| {
        panic!(
            "{}: cannot decode {}: {err}",
            baseline.name,
            png_path.display()
        )
    });
    let (width, height) = png.dimensions();
    let rgba = png.to_rgba8();
    let png_nonblack = rgba
        .pixels()
        .filter(|pixel| pixel[0] | pixel[1] | pixel[2] != 0)
        .count() as u64;

    Some(Metrics {
        width,
        height,
        png_nonblack,
        ..metrics
    })
}

fn assert_scene(baseline: &Baseline, metrics: &Metrics) {
    assert_eq!(
        (metrics.width, metrics.height),
        (SCREEN_W, SCREEN_H),
        "{}: PNG geometry",
        baseline.name
    );
    assert_eq!(
        metrics.nonblack, baseline.nonblack,
        "{}: stdout non-black pixels",
        baseline.name
    );
    assert_eq!(
        metrics.nonblack, metrics.png_nonblack,
        "{}: decoded PNG non-black pixels must equal the report",
        baseline.name
    );
    assert_eq!(metrics.frames, baseline.frames, "{}: frames", baseline.name);
    assert_eq!(
        metrics.peak_coroutines, baseline.peak_coroutines,
        "{}: peak coroutines",
        baseline.name
    );
    assert_eq!(
        metrics.pictures_live, baseline.pictures_live,
        "{}: live pictures",
        baseline.name
    );
    assert_eq!(
        metrics.textured_quads, baseline.textured_quads,
        "{}: textured quads",
        baseline.name
    );
    assert_eq!(
        metrics.text_pictures, baseline.text_pictures,
        "{}: text pictures",
        baseline.name
    );
    assert_eq!(
        metrics.choice_open, baseline.choice_open,
        "{}: choice open state",
        baseline.name
    );
    assert_eq!(
        metrics.choice_options, baseline.choice_options,
        "{}: choice options",
        baseline.name
    );
    assert_eq!(
        metrics.atlas_images, baseline.atlas_images,
        "{}: atlas images",
        baseline.name
    );
    assert_eq!(
        metrics.text_items, baseline.text_items,
        "{}: text items",
        baseline.name
    );
    assert_eq!(
        metrics.text_glyphs, baseline.text_glyphs,
        "{}: text glyphs",
        baseline.name
    );
    assert_eq!(
        metrics.text_lines, baseline.text_lines,
        "{}: text lines",
        baseline.name
    );
    assert_eq!(
        metrics.messages, baseline.messages,
        "{}: message ops",
        baseline.name
    );
    assert_eq!(
        metrics.choices, baseline.choices,
        "{}: choice ops",
        baseline.name
    );
    assert_eq!(
        metrics.warnings, 0,
        "{}: warnings must be zero",
        baseline.name
    );
}

fn parse_metrics(name: &str, stdout: &str) -> Metrics {
    let frames_line = field_line(stdout, "frames")
        .unwrap_or_else(|| panic!("{name}: no frames line in capture output"));
    let frames = parse_u32_before(frames_line, "(peak")
        .unwrap_or_else(|| panic!("{name}: cannot parse frames from {frames_line:?}"));
    let peak_coroutines = parse_u32_before(frames_line, "coroutine(s))")
        .unwrap_or_else(|| panic!("{name}: cannot parse coroutine peak from {frames_line:?}"));

    let pictures_line = field_line(stdout, "pictures")
        .unwrap_or_else(|| panic!("{name}: no pictures line in capture output"));
    let pictures_live = parse_u32_before(pictures_line, "live")
        .unwrap_or_else(|| panic!("{name}: cannot parse live pictures from {pictures_line:?}"));
    let textured_quads = parse_u32_before(pictures_line, "textured")
        .unwrap_or_else(|| panic!("{name}: cannot parse textured quads from {pictures_line:?}"));
    let text_pictures = parse_u32_before(pictures_line, "text")
        .unwrap_or_else(|| panic!("{name}: cannot parse text pictures from {pictures_line:?}"));

    let choice_line = field_line(stdout, "choice")
        .unwrap_or_else(|| panic!("{name}: no choice line in capture output"));
    let (choice_open, choice_options) = if choice_line.contains("none open") {
        (false, 0)
    } else {
        let options = parse_u32_before(choice_line, "option(s)")
            .unwrap_or_else(|| panic!("{name}: cannot parse choice options from {choice_line:?}"));
        (true, options)
    };

    let atlas_line = field_line(stdout, "atlas")
        .unwrap_or_else(|| panic!("{name}: no atlas line in capture output"));
    let atlas_images = parse_u32_before(atlas_line, "image(s),")
        .unwrap_or_else(|| panic!("{name}: cannot parse atlas images from {atlas_line:?}"));

    let text_line = field_line(stdout, "text")
        .unwrap_or_else(|| panic!("{name}: no text line in capture output"));
    let text_items = parse_u32_before(text_line, "item(s),")
        .unwrap_or_else(|| panic!("{name}: cannot parse text items from {text_line:?}"));
    let text_glyphs = parse_u32_before(text_line, "glyph(s),")
        .unwrap_or_else(|| panic!("{name}: cannot parse text glyphs from {text_line:?}"));
    let text_lines = parse_u32_before(text_line, "line(s),")
        .unwrap_or_else(|| panic!("{name}: cannot parse text lines from {text_line:?}"));

    let rendered_line = field_line(stdout, "rendered")
        .unwrap_or_else(|| panic!("{name}: no rendered line in capture output"));
    assert!(
        rendered_line.contains("1024x576,"),
        "{name}: rendered line geometry: {rendered_line:?}"
    );
    let fraction = rendered_line
        .split_whitespace()
        .find(|token| token.contains('/'))
        .unwrap_or_else(|| panic!("{name}: no non-black fraction in {rendered_line:?}"));
    let (lit, total) = fraction
        .split_once('/')
        .unwrap_or_else(|| panic!("{name}: malformed non-black fraction {fraction:?}"));
    let nonblack = lit
        .parse::<u64>()
        .unwrap_or_else(|_| panic!("{name}: malformed lit pixel count {lit:?}"));
    let reported_total = total
        .parse::<u64>()
        .unwrap_or_else(|_| panic!("{name}: malformed total pixel count {total:?}"));
    assert_eq!(
        reported_total, TOTAL_PIXELS,
        "{name}: capture total pixels must be 1024x576"
    );

    let stats_line = field_line(stdout, "stats")
        .unwrap_or_else(|| panic!("{name}: no stats line in capture output"));
    let messages = parse_u32_before(stats_line, "message(s),")
        .unwrap_or_else(|| panic!("{name}: cannot parse message ops from {stats_line:?}"));
    let choices = parse_u32_before(stats_line, "choice(s),")
        .unwrap_or_else(|| panic!("{name}: cannot parse choice ops from {stats_line:?}"));
    let warnings = parse_u32_before(stats_line, "warning(s)")
        .unwrap_or_else(|| panic!("{name}: cannot parse warnings from {stats_line:?}"));

    Metrics {
        frames,
        peak_coroutines,
        pictures_live,
        textured_quads,
        text_pictures,
        choice_open,
        choice_options,
        atlas_images,
        text_items,
        text_glyphs,
        text_lines,
        width: 0,
        height: 0,
        nonblack,
        png_nonblack: 0,
        messages,
        choices,
        warnings,
    }
}

fn field_line<'a>(stdout: &'a str, field: &str) -> Option<&'a str> {
    stdout.lines().find(|line| {
        let Some((name, _)) = line.split_once(':') else {
            return false;
        };
        name.starts_with("  ") && name.trim() == field
    })
}

fn parse_u32_before(line: &str, marker: &str) -> Option<u32> {
    let tokens: Vec<&str> = line.split_whitespace().collect();
    let index = tokens.iter().position(|token| *token == marker)?;
    tokens.get(index.checked_sub(1)?)?.parse().ok()
}
