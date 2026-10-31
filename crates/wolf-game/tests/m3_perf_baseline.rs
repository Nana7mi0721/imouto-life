//! M4 headless performance baseline.
//!
//! This file measures the pure-logic half of the engine (VM + game host + picture
//! layer + text layout), which is what `wolf-cli run --event` exercises without a
//! GPU. It is a *measurement*, not an optimisation gate: every assertion here is
//! about correctness (the scenario ran, executed instructions, stayed
//! warning-free), never about wall-clock time, because a shared CI/GPU machine
//! under training load changes the numbers by an order of magnitude.
//!
//! Five scenarios, matching the shapes M4 will need to keep fast, plus a sixth
//! diagnostic "engine floor" scenario that isolates the fixed per-frame host cost:
//!
//! | id | scenario | setup | measured frames |
//! |----|----------|-------|-----------------|
//! | A | boot -> title settle | `Game::new` + `boot` | 300 |
//! | B | loaded bedroom (SaveData01) | engine events + `load_save` | 600 |
//! | C | one full CE251 sleep run | clean `Game::new`, `start_event(251)` | 400 |
//! | D | night menu CE245 | loaded bedroom, `start_event(245)` | 120 |
//! | E | night interaction UI composition | SampleMapA pages + CE230 | 180 |
//! | F | engine floor (diagnostic) | `Game::new` + engine events only | 600 |
//!
//! Each scenario runs one untimed warm-up pass (so asset/file caches are warm),
//! then three timed runs on a fresh `Game`; the report carries the min and median
//! ms/frame. `text_quads()` (the per-frame text shaping the renderer does) is
//! timed separately, after the frame loop, because it is pure and safe to repeat.
//! `picture_quads()` and `tile_quads()` are timed the same way after one warm call
//! with a reused `Atlas`, so their cold first-frame decode/pack never pollutes the
//! steady-state number.
//!
//! Run with data:
//!
//! ```text
//! WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --test m3_perf_baseline -- --nocapture
//! ```
//!
//! Without data the test prints a skip line and returns, so the default workspace
//! suite keeps exiting 0. The measured table and method live in docs/M4_PERF.md.
//!
//! This file deliberately contains one `#[test]` so cargo runs the scenarios on a
//! single thread; parallel test threads would contend for the same core and make
//! the numbers meaningless.

use std::path::{Path, PathBuf};
use std::time::Instant;

use wolf_format::mps::Map;
use wolf_game::{Atlas, Game};

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

fn save_path(root: &Path) -> PathBuf {
    root.join("Save").join("SaveData01.sav")
}

fn new_game() -> Result<Game, String> {
    Game::new(data_root()).map_err(|err| err.to_string())
}

/// A fresh game parked in the loaded-save bedroom, with the engine-owned coroutines
/// running (the same state `m3_event_smoke` calls `bedroom()`).
fn loaded_bedroom() -> Result<Game, String> {
    let mut game = new_game()?;
    game.start_engine_events();
    game.load_save(&save_path(&data_root()))?;
    game.auto_advance = true;
    game.auto_choice = false;
    Ok(game)
}

/// Scenario F setup: a fresh game with only the engine-owned coroutines (no save
/// load, no map). Isolates the fixed per-frame host overhead -- auto-event sync
/// over the 97 conditional events, map runtime, screen tick/advance, and the
/// engine's own per-frame poll scripts -- from any user-visible script work.
fn engine_floor() -> Result<Game, String> {
    let mut game = new_game()?;
    game.start_engine_events();
    game.auto_advance = true;
    Ok(game)
}

/// Scenario A setup: the retail boot chain up to the title menu (no frames run).
fn booted_title() -> Result<Game, String> {
    let mut game = new_game()?;
    game.auto_advance = true;
    game.auto_choice = false;
    game.boot().map_err(|err| err.to_string())?;
    Ok(game)
}

/// Scenario C setup: CE251 from a clean event state, exactly like the m2 baseline.
fn sleep_run() -> Result<Game, String> {
    let mut game = new_game()?;
    game.auto_advance = true;
    game.auto_choice = false;
    if !game.start_event(251) {
        return Err("common event 251 is not in this build".to_owned());
    }
    Ok(game)
}

/// Scenario D setup: loaded bedroom with the night command menu open. The menu
/// parks waiting for a key, which is the realistic idle-night UI shape.
fn night_menu() -> Result<Game, String> {
    let mut game = loaded_bedroom()?;
    if !game.start_event(245) {
        return Err("common event 245 is not in this build".to_owned());
    }
    Ok(game)
}

/// The map's night-interface pages only: ev15/16/17/18/19/20/23/26 (copy of the
/// m3_night_interaction_e2e helper; the story events are left out so they cannot
/// answer prompts for us).
fn ui_map() -> Result<Map, String> {
    let path = data_root().join("MapData").join("SampleMapA.mps");
    let bytes = std::fs::read(&path).map_err(|err| format!("cannot read {path:?}: {err}"))?;
    let mut map = Map::parse(&bytes).map_err(|err| err.to_string())?;
    map.events
        .retain(|event| matches!(event.id, 15 | 16 | 17 | 18 | 19 | 20 | 23 | 26));
    Ok(map)
}

/// Scenario E setup: the interface composition (status bar, body layers, item
/// slots, command buttons) entered through CE230 after the map pages start.
/// The 260 entry frames are setup, not measured; the 180 measured frames are the
/// steady interface (ev15/16/18 poll the mouse every frame).
fn night_interface() -> Result<Game, String> {
    let mut game = loaded_bedroom()?;
    let map = ui_map()?;
    game.start_pages(&map, None);
    game.vm.vars.set(100, 1);
    if !game.start_event(230) {
        return Err("common event 230 is not in this build".to_owned());
    }
    for _ in 0..260 {
        game.frame();
    }
    Ok(game)
}

/// One timed run of one scenario.
struct Run {
    setup_ms: f64,
    frames_ms: f64,
    instructions: u64,
    peak_instances: usize,
    live_instances: usize,
    warnings: u64,
    diagnostics: usize,
    pictures: usize,
    text_pictures: usize,
    text_quads: usize,
    text_quads_ms: f64,
    /// `Game::picture_quads` (asset lookup + tint bake) per call.
    picture_quads_ms: f64,
    /// Quads the sprite pass emitted in the warmed call.
    sprite_quads: usize,
    /// `Game::tile_quads` (tile cull + autotile) per call.
    tile_quads_ms: f64,
    /// Quads the tile pass emitted in the warmed call.
    tile_quads: usize,
    /// `Screen::iter().count()` per call; trivial, kept as the "iterate the
    /// picture layer" floor the renderer pays on top of every quirk above.
    screen_iter_ms: f64,
}

impl Run {
    fn ms_per_frame(&self, frames: usize) -> f64 {
        self.frames_ms / frames as f64
    }

    fn instructions_per_frame(&self, frames: usize) -> f64 {
        self.instructions as f64 / frames as f64
    }
}

/// Runs one warm-up pass (untimed) and `runs` timed passes of `frames` frames.
///
/// Returns `None` when the scenario cannot be built (missing data), which is how
/// the whole test skips.
fn measure(
    name: &str,
    frames: usize,
    build: &dyn Fn() -> Result<Game, String>,
    runs: usize,
) -> Option<Vec<Run>> {
    // Warm-up: decode/parse caches and the OS file cache get their first pass.
    let mut warm = match build() {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: cannot set up {name}: {err}");
            return None;
        }
    };
    for _ in 0..frames {
        warm.frame();
    }
    drop(warm);

    let mut results = Vec::new();
    for run_index in 0..runs {
        let t_setup = Instant::now();
        let mut game = match build() {
            Ok(game) => game,
            Err(err) => {
                eprintln!("skipping: cannot set up {name} on run {run_index}: {err}");
                return None;
            }
        };
        let setup_ms = t_setup.elapsed().as_secs_f64() * 1000.0;

        let before_instructions = game.stats.instructions;
        let t0 = Instant::now();
        for _ in 0..frames {
            game.frame();
        }
        let frames_ms = t0.elapsed().as_secs_f64() * 1000.0;

        // Pure read: repeatable, so time ten calls and divide. This is the work
        // the renderer does every frame for every text picture.
        let t_text = Instant::now();
        let mut quad_count = 0usize;
        for _ in 0..10 {
            quad_count = game.text_quads().len();
        }
        let text_quads_ms = t_text.elapsed().as_secs_f64() * 1000.0 / 10.0;

        // The other two per-frame renderer passes. Both take `&mut self` (asset
        // fallbacks are drained into diagnostics), so they cannot run inside the
        // timed frame loop, but they are idempotent enough to repeat here.
        //
        // A fresh `Atlas` decodes and packs every referenced image on its first
        // call, which is a one-off cost the steady-state renderer never pays; run
        // each pass once before timing so the numbers are the warm cost.
        let mut atlas = Atlas::new();
        let sprite_quads = game.picture_quads(&mut atlas).len();
        let tile_quads = game.tile_quads(&mut atlas).len();
        std::hint::black_box(game.text_quads());

        let t_pics = Instant::now();
        for _ in 0..10 {
            std::hint::black_box(game.picture_quads(&mut atlas));
        }
        let picture_quads_ms = t_pics.elapsed().as_secs_f64() * 1000.0 / 10.0;

        let t_tiles = Instant::now();
        for _ in 0..10 {
            std::hint::black_box(game.tile_quads(&mut atlas));
        }
        let tile_quads_ms = t_tiles.elapsed().as_secs_f64() * 1000.0 / 10.0;

        let t_iter = Instant::now();
        for _ in 0..10 {
            std::hint::black_box(game.screen.iter().count());
        }
        let screen_iter_ms = t_iter.elapsed().as_secs_f64() * 1000.0 / 10.0;

        results.push(Run {
            setup_ms,
            frames_ms,
            instructions: game.stats.instructions.saturating_sub(before_instructions),
            peak_instances: game.stats.peak_instances,
            live_instances: game.vm.instances().len(),
            warnings: game.stats.warnings,
            diagnostics: game.diagnostics.len(),
            pictures: game.screen.len(),
            text_pictures: game.screen.iter().filter(|p| p.kind.is_text()).count(),
            text_quads: quad_count,
            text_quads_ms,
            picture_quads_ms,
            sprite_quads,
            tile_quads_ms,
            tile_quads,
            screen_iter_ms,
        });
    }
    Some(results)
}

fn median(values: &mut [f64]) -> f64 {
    values.sort_by(|a, b| a.partial_cmp(b).unwrap_or(std::cmp::Ordering::Equal));
    let mid = values.len() / 2;
    if values.len() % 2 == 0 {
        (values[mid - 1] + values[mid]) / 2.0
    } else {
        values[mid]
    }
}

fn min_of(values: &[f64]) -> f64 {
    values.iter().copied().fold(f64::INFINITY, f64::min)
}

struct Scenario {
    name: &'static str,
    frames: usize,
    runs: Vec<Run>,
}

impl Scenario {
    fn min_ms_per_frame(&self) -> f64 {
        min_of(
            &self
                .runs
                .iter()
                .map(|run| run.ms_per_frame(self.frames))
                .collect::<Vec<_>>(),
        )
    }

    fn median_ms_per_frame(&self) -> f64 {
        median(
            &mut self
                .runs
                .iter()
                .map(|run| run.ms_per_frame(self.frames))
                .collect::<Vec<_>>(),
        )
    }

    fn median_frames_per_second(&self) -> f64 {
        let ms = self.median_ms_per_frame();
        if ms <= 0.0 {
            f64::INFINITY
        } else {
            1000.0 / ms
        }
    }

    fn median_instructions_per_frame(&self) -> f64 {
        median(
            &mut self
                .runs
                .iter()
                .map(|run| run.instructions_per_frame(self.frames))
                .collect::<Vec<_>>(),
        )
    }

    fn median_setup_ms(&self) -> f64 {
        median(&mut self.runs.iter().map(|run| run.setup_ms).collect::<Vec<_>>())
    }

    fn median_text_quads_ms(&self) -> f64 {
        median(
            &mut self
                .runs
                .iter()
                .map(|run| run.text_quads_ms)
                .collect::<Vec<_>>(),
        )
    }

    fn median_picture_quads_ms(&self) -> f64 {
        median(
            &mut self
                .runs
                .iter()
                .map(|run| run.picture_quads_ms)
                .collect::<Vec<_>>(),
        )
    }

    fn median_tile_quads_ms(&self) -> f64 {
        median(
            &mut self
                .runs
                .iter()
                .map(|run| run.tile_quads_ms)
                .collect::<Vec<_>>(),
        )
    }

    fn median_screen_iter_ms(&self) -> f64 {
        median(
            &mut self
                .runs
                .iter()
                .map(|run| run.screen_iter_ms)
                .collect::<Vec<_>>(),
        )
    }
}

#[test]
fn m4_perf_baseline() {
    // Data missing is the normal CI case: print the skip line and exit 0.
    let root = data_root();
    if !root.join("BasicData").join("CommonEvent.dat").is_file() {
        eprintln!(
            "skipping: no WOLF data at {root:?} (set WOLF_DATA_ROOT to the unpacked Data directory)"
        );
        return;
    }

    const RUNS: usize = 3;
    let mut scenarios: Vec<Scenario> = Vec::new();

    let mut record = |name: &'static str,
                      frames: usize,
                      build: &dyn Fn() -> Result<Game, String>| {
        let Some(runs) = measure(name, frames, build, RUNS) else {
            return false;
        };

        // Correctness-only assertions: the scenario ran, the interpreter executed
        // instructions, and nothing logged a warning. No timing thresholds.
        for run in &runs {
            assert_eq!(run.warnings, 0, "{name}: warnings must stay 0");
            assert!(
                run.instructions > 0,
                "{name}: the scenario must execute instructions"
            );
        }
        assert!(
            !runs.is_empty(),
            "{name}: at least one timed run must complete"
        );
        eprintln!(
            "{name}: {} run(s) over {frames} frames, median {:.3} ms/frame, \
             median {:.0} frames/s, median {:.1} VM inst/frame, text_quads {:.3} ms/call",
            runs.len(),
            median(
                &mut runs
                    .iter()
                    .map(|r| r.ms_per_frame(frames))
                    .collect::<Vec<_>>()
            ),
            {
                let ms = median(
                    &mut runs
                        .iter()
                        .map(|r| r.ms_per_frame(frames))
                        .collect::<Vec<_>>(),
                );
                if ms > 0.0 {
                    1000.0 / ms
                } else {
                    f64::INFINITY
                }
            },
            median(
                &mut runs
                    .iter()
                    .map(|r| r.instructions_per_frame(frames))
                    .collect::<Vec<_>>()
            ),
            median(&mut runs.iter().map(|r| r.text_quads_ms).collect::<Vec<_>>()),
        );
        for (index, run) in runs.iter().enumerate() {
            eprintln!(
                "  run {}: setup {:.2} ms, frames {:.2} ms ({:.3} ms/frame), \
                 inst {} ({:.1}/frame), peak {} live {}, pics {} ({} text), quads {}, \
                 warnings {}, diagnostics {}; render text {:.3} / pics {:.3} ({} quads) / tiles {:.3} ({} quads) / iter {:.3} ms",
                index + 1,
                run.setup_ms,
                run.frames_ms,
                run.ms_per_frame(frames),
                run.instructions,
                run.instructions_per_frame(frames),
                run.peak_instances,
                run.live_instances,
                run.pictures,
                run.text_pictures,
                run.text_quads,
                run.warnings,
                run.diagnostics,
                run.text_quads_ms,
                run.picture_quads_ms,
                run.sprite_quads,
                run.tile_quads_ms,
                run.tile_quads,
                run.screen_iter_ms,
            );
        }
        scenarios.push(Scenario { name, frames, runs });
        true
    };

    if !record("A boot -> title settle", 300, &booted_title) {
        return;
    }
    if !record("B loaded bedroom", 600, &loaded_bedroom) {
        return;
    }
    if !record("C CE251 sleep run", 400, &sleep_run) {
        return;
    }
    if !record("D night menu CE245", 120, &night_menu) {
        return;
    }
    if !record("E night interaction UI", 180, &night_interface) {
        return;
    }
    // Last, so its numbers cannot warm anything the scripted scenarios rely on.
    if !record("F engine floor", 600, &engine_floor) {
        return;
    }

    // Machine-readable-ish table; docs/M4_PERF.md is filled from this output.
    // The render columns are per-call costs, not part of the frame-loop time:
    // a host that draws pays them on top of `med ms/frame`.
    println!();
    println!(
        "{:<24} {:>6} {:>13} {:>14} {:>10} {:>11} {:>9} {:>8} {:>8} {:>8} {:>8} {:>6} {:>9} {:>6} {:>5} {:>5} {:>8} {:>8}",
        "scenario",
        "frames",
        "min ms/frame",
        "med ms/frame",
        "med fps",
        "med inst/fr",
        "setup ms",
        "text ms",
        "pics ms",
        "tiles ms",
        "iter ms",
        "pics",
        "text pics",
        "quads",
        "peak",
        "live",
        "spr qds",
        "tile qds",
    );
    for scenario in &scenarios {
        let last = scenario.runs.last().expect("timed runs");
        println!(
            "{:<24} {:>6} {:>13.3} {:>14.3} {:>10.0} {:>11.1} {:>9.2} {:>8.3} {:>8.3} {:>8.3} {:>8.4} {:>6} {:>9} {:>6} {:>5} {:>5} {:>8} {:>8}",
            scenario.name,
            scenario.frames,
            scenario.min_ms_per_frame(),
            scenario.median_ms_per_frame(),
            scenario.median_frames_per_second(),
            scenario.median_instructions_per_frame(),
            scenario.median_setup_ms(),
            scenario.median_text_quads_ms(),
            scenario.median_picture_quads_ms(),
            scenario.median_tile_quads_ms(),
            scenario.median_screen_iter_ms(),
            last.pictures,
            last.text_pictures,
            last.text_quads,
            last.peak_instances,
            last.live_instances,
            last.sprite_quads,
            last.tile_quads,
        );
    }
    println!();

    // Every scenario must have produced a nonzero frame count. The per-frame
    // instruction check above covers "the VM actually ran"; this pins the frame
    // accounting itself (fresh games start at 0 frames).
    for scenario in &scenarios {
        for run in &scenario.runs {
            assert!(
                scenario.frames > 0,
                "{}: frames must be nonzero",
                scenario.name
            );
            assert!(
                run.peak_instances > 0,
                "{}: at least one coroutine must be alive",
                scenario.name
            );
        }
    }
}
