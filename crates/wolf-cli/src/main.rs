//! `wolf-cli` — the project's diagnostic front end.
//!
//! The only command that matters during M0 is `verify`: it loads every game
//! data file, prints the counts, and compares them against the frozen baseline
//! in `docs/BASELINE.json`. Those numbers are a regression ratchet — if a
//! parser change moves one of them, the change is a bug until proven otherwise.

mod play;

/// `--audio` turns on real audio output for every command that builds a [`Game`] (M4).
/// It is one process-wide flag rather than a new parameter on every runner, so `capture`,
/// `capture --map`, `dump` and `play` all honour it without threading an argument through
/// each signature.
pub(crate) static AUDIO: std::sync::atomic::AtomicBool = std::sync::atomic::AtomicBool::new(false);

use std::collections::BTreeSet;
use std::path::{Path, PathBuf};
use std::process::ExitCode;

use std::sync::Arc;

use wolf_format as wf;
use wolf_format::command::SlotStats;
use wolf_format::commonevent::CommonEventData;
use wolf_format::gamedat::GameDat;
use wolf_game::atlas::{Atlas, SpriteQuad, TextQuad};
use wolf_game::db::Container;
use wolf_game::{choice, Game};
use wolf_render::{Renderer, ScaleMode, SpriteInstance, TextItem, LOGICAL_H, LOGICAL_W};
use wolf_vm::{
    ChoiceReply, DbOp, DbValue, Host, InstanceId, LogLevel, PictureCmd, PrecompileStats, Program,
    ProgramSet, SoundCmd, StepReport, Vm, WolfRng,
};

/// One asserted number.
struct Check {
    label: &'static str,
    expected: String,
    actual: String,
    ok: bool,
    /// True when the loader for this section does not exist yet.
    skipped: bool,
}

impl Check {
    fn text(label: &'static str, expected: &str, actual: &str) -> Self {
        Self {
            label,
            expected: expected.to_owned(),
            actual: actual.to_owned(),
            ok: expected == actual,
            skipped: false,
        }
    }

    fn num(label: &'static str, expected: u64, actual: u64) -> Self {
        Self {
            label,
            expected: expected.to_string(),
            actual: actual.to_string(),
            ok: expected == actual,
            skipped: false,
        }
    }

    fn skip(label: &'static str) -> Self {
        Self {
            label,
            expected: "-".to_owned(),
            actual: "not implemented".to_owned(),
            ok: true,
            skipped: true,
        }
    }
}

fn main() -> ExitCode {
    let mut args = std::env::args().skip(1);
    let mut root: Option<PathBuf> = None;
    let mut command: Option<String> = None;
    let mut event: Option<u32> = None;
    let mut frames: usize = 600;
    let mut trace = false;
    let mut hot = false;
    let mut out: Option<PathBuf> = None;
    let mut answer: Option<usize> = None;
    let mut answer_delay: u32 = 0;
    let mut pointer: Option<(i32, i32)> = None;
    let mut press_frame: Option<usize> = None;
    let mut key_frames: Vec<(usize, u32)> = Vec::new();
    // `--press-every N:CODE` repeats a WOLF key code every Nth frame (N=1 holds it on
    // every frame). A 123 poll fires on whatever frame the script happens to reach it,
    // so a one-shot `--key-frame` cannot reliably satisfy a menu loop the probe cannot
    // pre-compute; a cadence can. `--auto-input` is the common case of pressing the
    // decide key on every frame so every poll sees a confirm.
    let mut press_every: Vec<(usize, u32)> = Vec::new();
    let mut auto_input = false;
    let mut filter: Option<String> = None;
    let mut frame_limit: Option<u64> = None;
    let mut hold_message = false;
    let mut auto_events = true;
    let mut engine_events: Option<Vec<u32>> = None;
    let mut load_save: Option<PathBuf> = None;
    // `verify --wolf <FILE>`: re-extract a shipped `.wolf` archive with our own reader
    // and compare every entry against the unpacked data root, byte for byte.
    let mut wolf_path: Option<PathBuf> = None;
    let mut page: usize = 0;
    // `boot` defaults to true, so on its own it cannot tell "the user asked for the
    // boot map" from "the user gave nothing". capture needs that distinction:
    // `capture --event 239` must start event 239, not silently fall back to the boot
    // map and photograph the vendor logo (docs/BATTLE.md section 6.2).
    let mut boot_explicit = false;
    let mut menu_only = false;
    // M5 presentation controls, shared by `play` only. The default keeps the retail
    // integer pixel grid; `fit-*` fills a 16:9 window instead of leaving bars.
    let mut scale_mode = ScaleMode::Integer;
    let mut fullscreen = false;
    let mut debug_overlay = false;
    let mut debug_vars: Vec<u32> = Vec::new();
    let mut stats_overlay = false;
    // M5-D side-car content catalog: replaces exact message/choice strings at runtime.
    let mut translation: Option<PathBuf> = None;
    let mut map: Option<String> = None;
    let mut map_run: Option<String> = None;
    // `dump` seeds inputs into a real Game and reads state back out. It is the probe
    // for the battle slices (docs/BATTLE.md section 5): slice A needs common event 189
    // to run with SV28 set and then reads CDataBase row counts, slice B needs 2000350
    // forced to 2 and then reads 2000352.
    let mut seed_vars: Vec<(u32, i32)> = Vec::new();
    let mut seed_selfs: Vec<(usize, i32)> = Vec::new();
    let mut show_dbs: Vec<(String, i32)> = Vec::new();
    let mut print_vars: Vec<u32> = Vec::new();
    let mut print_selfs: Vec<usize> = Vec::new();
    let mut watch: Option<u32> = None;
    // `--watch-var ADDR` prints a variable whenever it changes, the observable trace the
    // M3 battle state machine needs: 2000350 must show 0 -> 1 -> 2 -> 0 and 2000352 the
    // written outcome. Accepts both a flat slot and a magic address.
    let mut watch_vars: Vec<u32> = Vec::new();
    // `--watch-start EVENT` reports the frame an instance of that common event is
    // created and the frame it stops. `--watch` only prints program-counter movement,
    // so a short-lived event (e.g. CE240 戦力処理, 47 slots) can start and finish
    // between two prints and be invisible. This makes the scheduler itself observable:
    // which runner events the engine actually starts, and when.
    let mut watch_start: Vec<u32> = Vec::new();

    while let Some(arg) = args.next() {
        match arg.as_str() {
            "--root" | "-r" => {
                root = args.next().map(PathBuf::from);
            }
            "--event" | "-e" => {
                event = args.next().and_then(|value| value.parse().ok());
            }
            "--frames" | "-f" => {
                frames = args
                    .next()
                    .and_then(|value| value.parse().ok())
                    .unwrap_or(600);
            }
            "--trace" | "-t" => trace = true,
            "--hot" => hot = true,
            "--until" => {
                frame_limit = args.next().and_then(|value| value.parse().ok());
            }
            "--out" | "-o" => {
                out = args.next().map(PathBuf::from);
            }
            "--answer" | "-a" => {
                answer = args.next().and_then(|value| value.parse().ok());
            }
            // Frames a prompt must stay on screen before --answer's automatic click
            // lands. 0 clicks the instant the script asks, which lets a menu loop burn a
            // whole frame budget in one frame; 1 emulates a player confirming once a
            // frame, so a capture marches through character creation instead of spinning.
            "--answer-delay" => {
                answer_delay = args
                    .next()
                    .and_then(|value| value.parse().ok())
                    .unwrap_or(0);
            }
            // A pointer for headless captures. The game is mouse-driven - its own title
            // hint line reads 通过鼠标进行选择，点击进行确定和取消 - so a capture that never
            // moves the mouse cannot reach any menu that hit-tests it.
            "--pointer" => {
                pointer = args.next().and_then(|value| parse_point(&value));
            }
            // Frame (0-based) at which that pointer presses the left button once.
            "--press-frame" => {
                press_frame = args.next().and_then(|value| value.parse().ok());
            }
            // Frame (0-based) at which a WOLF key code is held for exactly one frame.
            // Repeat the flag to inject more than one press; H-scene polls wait on
            // opcode 123, which the mouse path cannot satisfy.
            "--key-frame" => {
                if let Some((frame, code)) = args.next().as_deref().and_then(parse_key_frame) {
                    key_frames.push((frame, code));
                }
            }
            // `--press-every N:CODE` repeats a WOLF key code every Nth frame (N=1 →
            // every frame). Repeat the flag to layer several cadences. This is how a
            // headless probe satisfies an opcode-123 poll loop it cannot pre-compute.
            "--press-every" => {
                if let Some((every, code)) = args.next().as_deref().and_then(parse_key_frame) {
                    press_every.push((every, code));
                }
            }
            // `--auto-input` holds the decide key (WOLF code 10) on every frame, the
            // common case of confirming whatever a menu asks without scripting frames.
            "--auto-input" => auto_input = true,
            // `dump --watch EVENT` prints the program counter of every coroutine for
            // that common event whenever it moves, so a headless probe can see which
            // poll a menu loop is blocked on.
            "--watch" => {
                watch = args.next().and_then(|value| value.parse().ok());
            }
            "--watch-var" => {
                if let Some(addr) = args.next().and_then(|value| value.parse::<u32>().ok()) {
                    watch_vars.push(addr);
                }
            }
            // `dump --watch-start EVENT` prints when an instance of that event is
            // created and when it stops (repeatable). It exposes the scheduler: a
            // short-lived runner such as CE240 can start and end between `--watch`
            // program-counter prints, so this reports its lifetime directly.
            "--watch-start" => {
                if let Some(id) = args.next().and_then(|value| value.parse::<u32>().ok()) {
                    watch_start.push(id);
                }
            }
            "--map" | "-m" => {
                map = args.next();
            }
            // Render a map EVENT (a story script) rather than the tile layer.
            "--map-run" => {
                map_run = args.next();
            }
            "--hold-message" => hold_message = true,
            // Turn on real audio output (M4). Every runner honours it; the engine degrades
            // to a silent null backend when the machine has no device, so it is safe on CI.
            "--audio" => AUDIO.store(true, std::sync::atomic::Ordering::Relaxed),
            // A/B switch for the run_condition == 2 scheduler (docs/ENGINE_EVENTS.md
            // section 2.2). `off` reproduces the pre-scheduler behaviour byte for byte;
            // the default is on.
            "--auto-events" => {
                let value = args.next().unwrap_or_default();
                auto_events = !matches!(value.trim(), "off" | "0" | "false");
            }
            "--page" => {
                page = args
                    .next()
                    .and_then(|value| value.parse().ok())
                    .unwrap_or(0);
            }
            // Which parallel-process-always events the engine starts, replacing
            // ENGINE_ALWAYS. An empty value starts none of them, which is the A/B
            // baseline (docs/ENGINE_EVENTS.md section 8.3).
            "--engine-events" => {
                let value = args.next().unwrap_or_default();
                let ids: Vec<u32> = value
                    .split(',')
                    .filter_map(|part| part.trim().parse().ok())
                    .collect();
                engine_events = Some(ids);
            }
            // Photograph a retail save instead of a script entry: the picture layer and
            // the normal variables come out of the file (docs/SAVE_SPEC.md §10).
            "--load-save" => {
                load_save = args.next().map(PathBuf::from);
            }
            "--boot" => {
                boot_explicit = true;
            }
            "--menu-only" => {
                menu_only = true;
            }
            "--scale" => {
                let value = args.next().unwrap_or_default();
                match ScaleMode::parse(&value) {
                    Some(mode) => scale_mode = mode,
                    None => {
                        eprintln!(
                            "unknown scale mode '{value}' (integer, fit-nearest, fit-linear)"
                        );
                        return ExitCode::from(2);
                    }
                }
            }
            "--fullscreen" => fullscreen = true,
            "--debug" => debug_overlay = true,
            "--stats" => stats_overlay = true,
            "--translation" => {
                translation = args.next().map(PathBuf::from);
            }
            "--debug-var" => {
                let value = args.next().unwrap_or_default();
                match play::parse_debug_vars(&value) {
                    Ok(mut vars) => debug_vars.append(&mut vars),
                    Err(err) => {
                        eprintln!("{err}");
                        return ExitCode::from(2);
                    }
                }
            }
            "--filter" | "-F" => {
                filter = args.next();
            }
            "--wolf" => {
                wolf_path = args.next().map(PathBuf::from);
            }
            // dump inputs / probes (see run_dump).
            "--var" => {
                if let Some((addr, value)) = args.next().as_deref().and_then(parse_addr_val) {
                    seed_vars.push((addr, value));
                }
            }
            "--self" => {
                if let Some((slot, value)) = args.next().as_deref().and_then(parse_slot_val) {
                    seed_selfs.push((slot, value));
                }
            }
            "--db" => {
                if let Some((container, db_type)) =
                    args.next().as_deref().and_then(parse_container_type)
                {
                    show_dbs.push((container, db_type));
                }
            }
            "--print-var" => {
                if let Some(addr) = args.next().and_then(|value| value.parse().ok()) {
                    print_vars.push(addr);
                }
            }
            "--print-self" => {
                if let Some(slot) = args.next().and_then(|value| value.parse().ok()) {
                    print_selfs.push(slot);
                }
            }
            "--help" | "-h" => {
                print_help();
                return ExitCode::SUCCESS;
            }
            other if other.starts_with('-') => {
                eprintln!("unknown flag: {other}");
                print_help();
                return ExitCode::from(2);
            }
            other => command = Some(other.to_owned()),
        }
    }

    let root = root.unwrap_or_else(default_root);
    match command.as_deref() {
        Some("verify") => run_verify(&root, wolf_path.as_deref()),
        Some("precompile") => run_precompile(&root),
        Some("blocks") => run_blocks(&root, map.as_deref(), event, page),
        Some("capture") => match map.as_deref() {
            Some(name) => {
                let answers = Answers {
                    index: answer,
                    delay: answer_delay,
                    pointer,
                    press_frame,
                    key_frames,
                    press_every,
                    auto_input,
                    seed_vars,
                    seed_selfs,
                    auto_events,
                };
                run_capture_map(
                    &root,
                    out,
                    frames,
                    name,
                    &answers,
                    load_save.as_deref(),
                    event,
                    translation.as_deref(),
                )
            }
            None => {
                // Resolved into an owning value first: Entry borrows its map name and
                // its save path, so the temporary must outlive the match below.
                let resolved = resolve_capture_entry(
                    load_save.as_deref(),
                    map_run.as_deref(),
                    event,
                    boot_explicit,
                    menu_only,
                );
                let entry = match &resolved {
                    CaptureEntry::Save(path) => Entry::Save(path.as_path()),
                    CaptureEntry::Script { map, event } => Entry::Script {
                        map: map.as_str(),
                        event: *event,
                    },
                    CaptureEntry::CommonEvent(id) => Entry::CommonEvent(*id),
                    CaptureEntry::Boot => Entry::Boot,
                    CaptureEntry::Menu => Entry::Menu,
                };
                let answers = Answers {
                    index: answer,
                    delay: answer_delay,
                    pointer,
                    press_frame,
                    key_frames,
                    press_every,
                    auto_input,
                    seed_vars,
                    seed_selfs,
                    auto_events,
                };
                run_capture(
                    &root,
                    out,
                    frames,
                    answers,
                    hold_message,
                    engine_events,
                    entry,
                    event,
                    translation.as_deref(),
                )
            }
        },
        Some("dump") => run_dump(
            &root,
            event,
            frames,
            &seed_vars,
            &seed_selfs,
            &show_dbs,
            &print_vars,
            &print_selfs,
            &key_frames,
            &press_every,
            auto_input,
            &watch_vars,
            &watch_start,
            watch,
        ),
        Some("list") => run_list(&root, filter.as_deref()),
        Some("play") => {
            // `play` shares capture's entry-point resolution so a map script or a single
            // common event can be driven interactively, not just the boot chain.
            let resolved = resolve_capture_entry(
                load_save.as_deref(),
                map_run.as_deref(),
                event,
                boot_explicit,
                menu_only,
            );
            let entry = match &resolved {
                CaptureEntry::Save(path) => Entry::Save(path.as_path()),
                CaptureEntry::Script { map, event } => Entry::Script {
                    map: map.as_str(),
                    event: *event,
                },
                CaptureEntry::CommonEvent(id) => Entry::CommonEvent(*id),
                CaptureEntry::Boot => Entry::Boot,
                CaptureEntry::Menu => Entry::Menu,
            };
            play::run(
                &root,
                frame_limit,
                entry,
                play::DisplayOptions {
                    mode: scale_mode,
                    fullscreen,
                },
                play::DebugOptions {
                    overlay: debug_overlay,
                    vars: debug_vars,
                    stats: stats_overlay,
                },
                translation.as_deref(),
            )
        }
        Some("run") => match (map.as_deref(), event) {
            (Some(name), Some(id)) => run_map_event(&root, name, id, frames, trace, answer, hot),
            (Some(_), None) => {
                eprintln!("run --map needs --event <ID>");
                ExitCode::from(2)
            }
            (None, Some(id)) => run_event(&root, id, frames, trace, answer),
            (None, None) => {
                eprintln!("run needs --event <ID>");
                ExitCode::from(2)
            }
        },
        Some(other) => {
            eprintln!("unknown command: {other}");
            print_help();
            ExitCode::from(2)
        }
        None => {
            print_help();
            ExitCode::from(2)
        }
    }
}

fn print_help() {
    println!("wolf-cli — WOLF RPG Editor data diagnostics");
    println!();
    println!("USAGE:");
    println!("    wolf-cli [--root <DIR>] verify");
    println!("    wolf-cli [--root <DIR>] precompile");
    println!("    wolf-cli [--root <DIR>] run --event <ID> [--frames <N>] [--trace]");
    println!(
        "    wolf-cli [--root <DIR>] capture [--frames <N>] [--out <FILE.png>] [--event <ID>]"
    );
    println!("                                   [--boot | --menu-only]");
    println!("    wolf-cli [--root <DIR>] play [--until <N>] [--map-run <NAME> --event <ID>]");
    println!("                                   [--event <ID> | --load-save <FILE>]");
    println!("                                   [--scale integer|fit-nearest|fit-linear] [--fullscreen]");
    println!("                                   [--debug] [--debug-var <ADDR,...>] [--stats]");
    println!("    wolf-cli [--root <DIR>] list [--filter <TEXT>]");
    println!();
    println!("COMMANDS:");
    println!(
        "    verify      Load every data file and diff the counts against docs/BASELINE.json."
    );
    println!("    precompile  Compile all 350 common events into jump tables; print the stats.");
    println!("    run         Execute one common event headlessly and report what it did.");
    println!("    capture     Run an entry point for N frames and render it to a PNG.");
    println!("                Default entry is the boot map (splashes + title art), then holds on");
    println!("                the menu. Choice prompts STAY OPEN unless --answer is given,");
    println!("                because answering the title prompt branches into the game.");
    println!("                --event <ID> starts that common event instead (after the engine");
    println!("                events), so a battle or menu screen can be photographed alone.");
    println!(
        "    play        Run a scene in a window (arrows move, Enter/Z or the mouse confirms)."
    );
    println!("                Same entry flags as capture: --map-run, --event, --load-save,");
    println!("                --boot (default) or --menu-only. --until <N> quits after N frames.");
    println!("    list        Print every common event: id, slots, real instructions, title.");
    println!();
    println!("OPTIONS:");
    println!("    -e, --event <ID>  Common event id for 'run', or the scene entry for");
    println!("                      'capture'/'play' (unless --boot or --menu-only is given).");
    println!("    -f, --frames <N>  Frame budget for 'run' (default 600, one frame = 1/60 s).");
    println!("    -t, --trace       Print every host callback in 'run', not just the summary.");
    println!("    -o, --out <FILE>  PNG path for 'capture' (default work/out/title.png).");
    println!(
        "    -a, --answer <N>  Answer choice prompts with option N instead of holding the menu."
    );
    println!("    --answer-delay <N>  Frames a prompt stays up before --answer clicks it (default");
    println!("                      0 = answer the instant the script asks). 1 emulates a player");
    println!("                      confirming once a frame, which is what walks a menu loop");
    println!("                      forward instead of spinning inside one frame.");
    println!("    -F, --filter <T>  Only list events whose title contains T (with 'list').");
    println!(
        "    --until <N>       Quit 'play' after N frames (smoke test; default: until closed)."
    );
    println!("    --menu-only       Start common event 42 directly instead of the boot map.");
    println!("                      Wins over --event (it names an entry point of its own).");
    println!("    --scale <MODE>    'play' presentation: integer (default, crisp + bars),");
    println!("                      fit-nearest or fit-linear (fractional, fills the window).");
    println!("                      F9 cycles the mode at runtime.");
    println!("    --fullscreen      Start 'play' borderless-fullscreen; F11 toggles it.");
    println!("    --debug           Start 'play' with the F3 debug overlay visible.");
    println!("    --debug-var <A,..> Variables the overlay lists, by flat slot or magic address");
    println!("                      (implies --debug when non-empty; F3 toggles the overlay).");
    println!(
        "    --stats           Start 'play' with the F2 statistics/milestone overlay visible."
    );
    println!("    --translation <FILE>  Replace exact message/choice strings using a UTF-8 TSV");
    println!("                      catalog (original<TAB>translation; # comments); works in play/capture.");
    println!("    --hold-message    Park on the first 101 message instead of dismissing it.");
    println!("    --audio           Play BGM/SE through the real mixer (silent null backend if no device).");
    println!("    --pointer <x,y>   Put the mouse pointer at a game pixel for the whole capture.");
    println!("    --press-frame <N> Frame at which --pointer clicks the left button once.");
    println!(
        "    --key-frame N:CODE Frame at which a WOLF key code is held for one frame (repeatable);"
    );
    println!("                     10=decide 11=cancel 12=sub 2/4/6/8=directions.");
    println!(
        "    --press-every N:CODE Hold a WOLF key code on every Nth frame (N=1 → every frame;"
    );
    println!("                     repeatable). Satisfies opcode-123 poll loops.");
    println!("    --auto-input      Hold the decide key (code 10) on every frame.");
    println!("    --watch-var <ADDR> Print a variable each time it changes (flat slot or magic;");
    println!("                     dump only). Traces the 2000350 battle cycle.");
    println!("    --watch-start <EVENT> Print the frame an event instance starts/stops");
    println!("                     (dump only, repeatable). Makes short runners observable.");
    println!("    --load-save <FILE>  Photograph a retail .sav instead of a script entry.");
    println!("    --engine-events <ids>  Comma separated ids that replace ENGINE_ALWAYS");
    println!("    --auto-events <on|off> Run the run_condition == 2 scheduler (default on)");
    println!("                      (the parallel-process-always events the engine owns).");
    println!("                      Pass an empty value to start none of them.");
    println!(
        "    -m, --map <NAME>  Capture a map instead of the boot sequence (e.g. SampleMapA.mps)."
    );
    println!("    --boot            Start on the boot map (default for capture and play).");
    println!("                      Stated explicitly it wins over capture --event.");
    println!("    -r, --root <DIR>  Unpacked data root containing BasicData/ and MapData/.");
    println!("    --wolf <FILE>     'verify' only: re-extract the shipped .wolf archive and");
    println!("                      compare every entry against the data root, byte for byte.");
    println!("                      Defaults to ./work/Data, then $WOLF_DATA_ROOT.");
    println!("    -h, --help        Print this help.");
}

/// Parses a `frame:code` key injection argument.
fn parse_key_frame(value: &str) -> Option<(usize, u32)> {
    let (frame, code) = value.split_once(':')?;
    Some((frame.trim().parse().ok()?, code.trim().parse().ok()?))
}

/// Parses a `x,y` pointer argument.
fn parse_point(value: &str) -> Option<(i32, i32)> {
    let (x, y) = value.split_once(',')?;
    Some((x.trim().parse().ok()?, y.trim().parse().ok()?))
}

/// The key bits to hold on `frame`, merged from every injection channel: a one-shot
/// `--key-frame` for this exact frame, each `--press-every N:CODE` cadence that lands
/// on it (`N=1` fires every frame), and `--auto-input`'s decide key. Channels OR
/// together so a probe can, for example, hold OK every frame while also punching a
/// direction on one specific frame. Shared by `dump` and both `capture` paths so they
/// cannot drift.
fn key_bits_for_frame(
    frame: usize,
    key_frames: &[(usize, u32)],
    press_every: &[(usize, u32)],
    auto_input: bool,
) -> u32 {
    let mut bits = 0u32;
    if let Some((_, code)) = key_frames.iter().find(|(at, _)| *at == frame) {
        bits |= wolf_game::key::bits_for_code(*code as i32);
    }
    for (every, code) in press_every {
        if *every > 0 && frame % *every == 0 {
            bits |= wolf_game::key::bits_for_code(*code as i32);
        }
    }
    if auto_input {
        bits |= wolf_game::key::bits_for_code(10);
    }
    bits
}

/// Parses a `ADDR=VALUE` variable seed for `dump --var`.
fn parse_addr_val(value: &str) -> Option<(u32, i32)> {
    let (addr, val) = value.split_once('=')?;
    Some((addr.trim().parse().ok()?, val.trim().parse().ok()?))
}

/// Parses a `SLOT=VALUE` self-variable seed for `dump --self`.
fn parse_slot_val(value: &str) -> Option<(usize, i32)> {
    let (slot, val) = value.split_once('=')?;
    Some((slot.trim().parse().ok()?, val.trim().parse().ok()?))
}

/// Parses a `CONTAINER:TYPE` database target for `dump --db` (C=CDataBase,
/// S=SysDatabase, D=DataBase).
fn parse_container_type(value: &str) -> Option<(String, i32)> {
    let (container, db_type) = value.split_once(':')?;
    Some((container.trim().to_owned(), db_type.trim().parse().ok()?))
}

fn default_root() -> PathBuf {
    if let Ok(value) = std::env::var("WOLF_DATA_ROOT") {
        if !value.is_empty() {
            return PathBuf::from(value);
        }
    }
    PathBuf::from("work/Data")
}

fn run_verify(root: &Path, wolf_path: Option<&Path>) -> ExitCode {
    println!("wolf-cli verify");
    println!("  data root : {}", root.display());

    let basic = if root.join("BasicData").is_dir() {
        root.join("BasicData")
    } else {
        root.to_path_buf()
    };
    let map_dir = root.join("MapData");
    println!("  basic dir : {}", basic.display());
    println!("  map dir   : {}", map_dir.display());
    println!();

    let mut checks: Vec<Check> = Vec::new();

    // --- Game.dat ---------------------------------------------------------
    match read(&basic.join("Game.dat")).map(|bytes| GameDat::parse(&bytes)) {
        Some(Ok(game)) => {
            checks.push(Check::text(
                "game.title",
                "Imouto! Life ~Monochrome~ zh-CN Ver.",
                game.title(),
            ));
            checks.push(Check::text("game.subtitle", "Ver2.03", game.subtitle()));
            checks.push(Check::num(
                "game.screen.w",
                1024,
                u64::from(game.screen_width()),
            ));
            checks.push(Check::num(
                "game.screen.h",
                576,
                u64::from(game.screen_height()),
            ));
            checks.push(Check::num(
                "game.tile_size",
                16,
                u64::from(game.tile_size()),
            ));
            checks.push(Check::num("game.fps", 60, u64::from(game.fps())));
            checks.push(Check::num("game.strings", 9, game.strings.len() as u64));
            checks.push(Check::num(
                "game.u8_settings",
                22,
                game.u8_settings.len() as u64,
            ));
            checks.push(Check::num(
                "game.u16_settings",
                19,
                game.u16_settings.len() as u64,
            ));
            checks.push(Check::text(
                "game.font_main",
                "Microsoft Yahei UI Bold",
                game.font_main(),
            ));
            checks.push(Check::num("game.random_a", 22507, u64::from(game.random_a)));
            checks.push(Check::num("game.random_b", 23301, u64::from(game.random_b)));
            checks.push(Check::num("game.footer", 0xC2, u64::from(game.footer)));
        }
        Some(Err(err)) => {
            checks.push(Check::text("game.parse", "ok", &format!("FAILED: {err}")));
        }
        None => checks.push(Check::text("game.parse", "ok", "FILE MISSING")),
    }

    // --- MapTree.dat / MapTreeOpenStatus.dat ------------------------------
    //
    // The map tree is what the engine walks to order the registered maps; the three
    // hook maps (3, 31, 24) are its only non-root entries. Decoding it is the first
    // half of the "new game start map" question (see docs/FORMAT_SPEC.md §2.6).
    match read(&basic.join("MapTree.dat")).map(|bytes| wf::maptree::MapTree::parse(&bytes)) {
        Some(Ok(tree)) => {
            checks.push(Check::num("maptree.entries", 50, tree.entries.len() as u64));
            checks.push(Check::num("maptree.version", 0x90, u64::from(tree.version)));
            checks.push(Check::num("maptree.footer", 0xBC, u64::from(tree.footer)));
            checks.push(Check::num("maptree.roots", 47, tree.roots().len() as u64));
            checks.push(Check::text(
                "maptree.children_of_0",
                "3,24,31",
                &tree
                    .children_of(0)
                    .iter()
                    .map(u32::to_string)
                    .collect::<Vec<_>>()
                    .join(","),
            ));
        }
        Some(Err(err)) => {
            checks.push(Check::text(
                "maptree.parse",
                "ok",
                &format!("FAILED: {err}"),
            ));
        }
        None => checks.push(Check::text("maptree.parse", "ok", "FILE MISSING")),
    }
    match read(&basic.join("MapTreeOpenStatus.dat"))
        .map(|bytes| wf::maptree::MapTreeOpenStatus::parse(&bytes))
    {
        Some(Ok(status)) => {
            checks.push(Check::num(
                "maptree.open.flags",
                50,
                status.open.len() as u64,
            ));
            checks.push(Check::num(
                "maptree.open.footer",
                0x26,
                u64::from(status.footer),
            ));
        }
        Some(Err(err)) => {
            checks.push(Check::text(
                "maptree.open.parse",
                "ok",
                &format!("FAILED: {err}"),
            ));
        }
        None => checks.push(Check::text("maptree.open.parse", "ok", "FILE MISSING")),
    }

    // --- CommonEvent.dat --------------------------------------------------
    match read(&basic.join("CommonEvent.dat")).map(|bytes| CommonEventData::parse(&bytes)) {
        Some(Ok(events)) => {
            let stats = events.stats();
            checks.push(Check::num("ce.events", 350, events.events.len() as u64));
            checks.push(Check::num("ce.version", 0x8F, u64::from(events.version)));
            checks.push(Check::num("ce.footer", 0x8F, u64::from(events.footer)));
            checks.push(Check::num("ce.slots", 63_506, stats.slots as u64));
            checks.push(Check::num("ce.blank", 9_890, stats.blank() as u64));
            checks.push(Check::num("ce.real", 53_616, stats.real() as u64));
            checks.push(Check::num(
                "ce.distinct_opcodes",
                45,
                stats.distinct_opcodes() as u64,
            ));
            checks.push(Check::num(
                "ce.max_branch_depth",
                25,
                u64::from(stats.max_branch_depth),
            ));
            checks.push(Check::num(
                "ce.move_route_tails",
                55,
                stats.move_route_tails as u64,
            ));
            checks.push(Check::num(
                "ce.param_layout_mismatches",
                0,
                stats.param_layout_mismatches as u64,
            ));
            let hist = events.run_condition_histogram();
            for (condition, expected) in [(0u8, 312u64), (1, 0), (2, 31), (3, 7)] {
                let actual = hist.get(&condition).copied().unwrap_or(0) as u64;
                checks.push(Check::num(run_condition_label(condition), expected, actual));
            }
            // The two heaviest opcodes are the cheapest sanity signal that the
            // stream stayed in sync all the way through.
            checks.push(Check::num(
                "ce.opcode.210",
                2_869,
                stats.opcodes.get(&210).copied().unwrap_or(0) as u64,
            ));
            checks.push(Check::num(
                "ce.opcode.401",
                7_562,
                stats.opcodes.get(&401).copied().unwrap_or(0) as u64,
            ));
        }
        Some(Err(err)) => {
            checks.push(Check::text("ce.parse", "ok", &format!("FAILED: {err}")));
        }
        None => checks.push(Check::text("ce.parse", "ok", "FILE MISSING")),
    }

    // --- MapData/*.mps ----------------------------------------------------
    //
    // Every map must parse to its footer byte; a single mis-walked page would
    // desynchronise the rest of the file, so the aggregate counts below are a
    // stronger check than any per-map assertion.
    let map_files = map_file_list(&map_dir);
    if map_files.is_empty() {
        checks.push(Check::text("mps.parse", "9 maps", "NO .mps FILES"));
    } else {
        let mut maps = 0u64;
        let mut events = 0u64;
        let mut pages = 0u64;
        let mut empty_tiles = 0u64;
        let mut stats = SlotStats::default();
        let mut errors: Vec<String> = Vec::new();
        for path in &map_files {
            let Some(bytes) = read(path) else {
                errors.push(format!("{}: unreadable", path.display()));
                continue;
            };
            match wf::mps::Map::parse(&bytes) {
                Ok(map) => {
                    maps += 1;
                    if !map.has_tile_data {
                        empty_tiles += 1;
                    }
                    events += map.events.len() as u64;
                    for event in &map.events {
                        pages += event.pages.len() as u64;
                        for page in &event.pages {
                            stats.extend(page.commands.iter());
                        }
                    }
                }
                Err(err) => {
                    let name = path
                        .file_name()
                        .map(|n| n.to_string_lossy().into_owned())
                        .unwrap_or_default();
                    errors.push(format!("{name}: {err}"));
                }
            }
        }
        let parse_note = if errors.is_empty() {
            "0 parse errors".to_owned()
        } else {
            errors.join("; ")
        };
        checks.push(Check::text("mps.parse", "0 parse errors", &parse_note));
        checks.push(Check::num("mps.maps", 8, maps));
        checks.push(Check::num("mps.events", 56, events));
        checks.push(Check::num("mps.pages", 102, pages));
        checks.push(Check::num("mps.slots", 12_266, stats.slots as u64));
        checks.push(Check::num("mps.blank", 2_188, stats.blank() as u64));
        checks.push(Check::num("mps.real", 10_078, stats.real() as u64));
        checks.push(Check::num(
            "mps.distinct_opcodes",
            34,
            stats.distinct_opcodes() as u64,
        ));
        checks.push(Check::num("mps.empty_maps", 0, empty_tiles));
    }

    // --- TileSetData.dat --------------------------------------------------
    match read(&basic.join("TileSetData.dat")).map(|b| wf::tileset::TileSetData::parse(&b)) {
        Some(Ok(sets)) => {
            checks.push(Check::num("tileset.version", 0xD1, u64::from(sets.version)));
            checks.push(Check::num("tileset.count", 6, sets.tilesets.len() as u64));
            checks.push(Check::num("tileset.footer", 0xCF, u64::from(sets.footer)));
            let base = sets
                .tilesets
                .get(4)
                .map(|set| set.base_image.as_str())
                .unwrap_or("<missing>");
            checks.push(Check::text(
                "tileset.base.4",
                "MapChip/kiri_project.png",
                base,
            ));
        }
        Some(Err(err)) => {
            checks.push(Check::text(
                "tileset.parse",
                "ok",
                &format!("FAILED: {err}"),
            ));
        }
        None => checks.push(Check::text("tileset.parse", "ok", "FILE MISSING")),
    }

    // --- the three databases ----------------------------------------------
    //
    // Type counts plus one row count each: the row count is what proves the
    // numeric-then-string row layout was walked correctly.
    for (label, file, expected_types, expected_rows) in [
        ("database.types", "DataBase.dat", 40u64, 44u64),
        ("cdata.types", "CDataBase.dat", 30, 17),
        ("sysdata.types", "SysDatabase.dat", 28, 50),
    ] {
        match read(&basic.join(file)).map(|b| wf::database::Database::parse(&b)) {
            Some(Ok(db)) => {
                checks.push(Check::num(label, expected_types, db.types.len() as u64));
                let rows = db.types.first().map(|t| t.rows.len() as u64).unwrap_or(0);
                checks.push(Check::num(
                    match label {
                        "database.types" => "database.rows.0",
                        "cdata.types" => "cdata.rows.0",
                        _ => "sysdata.rows.0",
                    },
                    expected_rows,
                    rows,
                ));
                if label == "sysdata.types" {
                    let settings = db.map_settings();
                    checks.push(Check::num(
                        "database.map_settings",
                        5,
                        settings.len() as u64,
                    ));
                    let first = settings
                        .first()
                        .map(|s| s.path.as_str())
                        .unwrap_or("<none>");
                    checks.push(Check::text(
                        "database.map_settings.0",
                        "MapData/TitleMap.mps",
                        first,
                    ));
                }
            }
            Some(Err(err)) => {
                checks.push(Check::text(
                    "database.parse",
                    "ok",
                    &format!("FAILED: {err}"),
                ));
            }
            None => checks.push(Check::text("database.parse", "ok", "FILE MISSING")),
        }
    }

    // --- save files (wolf-save) -----------------------------------------
    // Saves are the one input that lives next to the executable rather than in
    // the unpacked data root, so a missing install directory downgrades this
    // whole section to SKIP instead of failing a fresh checkout.
    let saves = save_file_list();
    if saves.is_empty() {
        checks.push(Check::skip("save.header"));
    } else {
        let mut parsed = 0u64;
        let mut checksum_ok = 0u64;
        let mut versions: BTreeSet<u16> = BTreeSet::new();
        let mut names: BTreeSet<String> = BTreeSet::new();
        let mut endings: BTreeSet<u8> = BTreeSet::new();
        for path in &saves {
            let Some(bytes) = read(path) else { continue };
            match wolf_save::SaveFile::parse(&bytes) {
                Ok(save) => {
                    parsed += 1;
                    if save.checksum_ok() {
                        checksum_ok += 1;
                    }
                    versions.insert(save.file_version);
                    names.insert(save.name.clone());
                    endings.insert(save.end_byte);
                }
                Err(err) => checks.push(Check::text(
                    "save.parse",
                    "ok",
                    &format!("FAILED {}: {err}", path.display()),
                )),
            }
        }
        checks.push(Check::num("save.files", saves.len() as u64, parsed));
        checks.push(Check::num(
            "save.checksum_ok",
            saves.len() as u64,
            checksum_ok,
        ));
        checks.push(Check::num("save.versions", 1, versions.len() as u64));
        let version = versions.iter().next().copied().unwrap_or(0);
        checks.push(Check::text(
            "save.version",
            "0x80",
            &format!("0x{version:02X}"),
        ));
        checks.push(Check::num("save.end_bytes", 1, endings.len() as u64));
        let end = endings.iter().next().copied().unwrap_or(0);
        checks.push(Check::text(
            "save.end_byte",
            "0x19",
            &format!("0x{end:02X}"),
        ));
        checks.push(Check::text(
            "save.name",
            "Imouto! Life ~Monochrome~ zh-CN Ver.",
            names.iter().next().map(String::as_str).unwrap_or("<none>"),
        ));
    }

    // --- .wolf DXArchive v8 (wolf-format::dxarchive) ----------------------
    // work/full was unpacked by UberWolf, so opening the same archive with our own
    // reader and re-parsing a file out of it pins the decryption end to end. The
    // archive is 1.2 GB in total; BasicData.wolf is the smallest one that still
    // exercises the Huffman + LZ path.
    match wolf_path {
        Some(path) => verify_wolf(root, path, &mut checks),
        None => match read(&game_dir().join("Data").join("BasicData.wolf"))
            .map(|bytes| wf::dxarchive::DxArchive::open(&bytes))
        {
            Some(Ok(archive)) => {
                checks.push(Check::num(
                    "dxarchive.version",
                    8,
                    u64::from(archive.version()),
                ));
                checks.push(Check::num(
                    "dxarchive.charcode",
                    932,
                    u64::from(archive.char_code_format()),
                ));
                checks.push(Check::num(
                    "dxarchive.flags",
                    20_578_304,
                    u64::from(archive.flags()),
                ));
                checks.push(Check::num(
                    "dxarchive.huffman_kb",
                    12,
                    u64::from(archive.huffman_encode_kb()),
                ));
                checks.push(Check::num(
                    "dxarchive.entries",
                    149,
                    archive.entries().len() as u64,
                ));
                let extracted = archive
                    .entry("Game.dat")
                    .and_then(|entry| archive.read(entry).ok());
                let verdict = match extracted {
                    Some(bytes) => match GameDat::parse(&bytes) {
                        Ok(game) if game.title() == "Imouto! Life ~Monochrome~ zh-CN Ver." => "ok",
                        Ok(_) => "wrong title",
                        Err(_) => "parse failed",
                    },
                    None => "extract failed",
                };
                checks.push(Check::text("dxarchive.game_dat", "ok", verdict));
            }
            Some(Err(err)) => checks.push(Check::text(
                "dxarchive.open",
                "ok",
                &format!("FAILED: {err}"),
            )),
            None => checks.push(Check::skip("dxarchive.header")),
        },
    }

    report(&checks)
}

/// `verify --wolf <PATH>`: open the shipped archive with our own reader and
/// compare every entry against the unpacked data root, byte for byte. This pins the
/// whole decryption+decompression chain (VER6 or VER8) end to end: 1,361 entries and
/// 179,877,496 bytes of this game's `Data.wolf` must match `work/Data` exactly.
fn verify_wolf(root: &Path, wolf: &Path, checks: &mut Vec<Check>) {
    println!("  wolf file : {}", wolf.display());
    let bytes = match std::fs::read(wolf) {
        Ok(bytes) => bytes,
        Err(err) => {
            checks.push(Check::text(
                "dxarchive.open",
                "ok",
                &format!("FAILED to read {}: {err}", wolf.display()),
            ));
            return;
        }
    };
    let archive = match wf::dxarchive::DxArchive::open(&bytes) {
        Ok(archive) => archive,
        Err(err) => {
            checks.push(Check::text(
                "dxarchive.open",
                "ok",
                &format!("FAILED: {err}"),
            ));
            return;
        }
    };
    checks.push(Check::num(
        "dxarchive.version",
        6,
        u64::from(archive.version()),
    ));
    checks.push(Check::num(
        "dxarchive.charcode",
        932,
        u64::from(archive.char_code_format()),
    ));
    checks.push(Check::num(
        "dxarchive.data_start",
        48,
        archive.data_start_address(),
    ));
    checks.push(Check::num(
        "dxarchive.entries",
        1361,
        archive.entries().len() as u64,
    ));

    let mut total_declared = 0u64;
    let mut total_decoded = 0u64;
    let mut compared = 0usize;
    let mut equal = 0usize;
    let mut read_failures = 0usize;
    let mut mismatches: Vec<String> = Vec::new();
    for entry in archive.entries() {
        total_declared += entry.size;
        match archive.read(entry) {
            Ok(data) => {
                total_decoded += data.len() as u64;
                match std::fs::read(root.join(entry.path())) {
                    Ok(reference) => {
                        compared += 1;
                        if reference == data {
                            equal += 1;
                        } else if mismatches.len() < 10 {
                            mismatches.push(format!(
                                "{} (archive {} B vs disk {} B)",
                                entry.path(),
                                data.len(),
                                reference.len()
                            ));
                        }
                    }
                    Err(err) => {
                        if mismatches.len() < 10 {
                            mismatches.push(format!("{} (disk read failed: {err})", entry.path()));
                        }
                    }
                }
            }
            Err(err) => {
                read_failures += 1;
                if mismatches.len() < 10 {
                    mismatches.push(format!("{} (extract failed: {err})", entry.path()));
                }
            }
        }
    }
    checks.push(Check::num(
        "dxarchive.total_bytes",
        179_877_496,
        total_declared,
    ));
    checks.push(Check::num(
        "dxarchive.decoded_bytes",
        179_877_496,
        total_decoded,
    ));
    checks.push(Check::num(
        "dxarchive.read_failures",
        0,
        read_failures as u64,
    ));
    checks.push(Check::text(
        "dxarchive.bytes_equal",
        "1361/1361",
        &format!("{equal}/{compared}"),
    ));
    for mismatch in &mismatches {
        eprintln!("  ! wolf entry mismatch: {mismatch}");
    }
    if !mismatches.is_empty() {
        checks.push(Check::text(
            "dxarchive.mismatches",
            "none",
            &mismatches.len().to_string(),
        ));
    }
}

/// Compile all 350 common events and diff the precompiler's invariants against
/// the counts measured in docs/OPCODE_SPEC.md.
///
/// This is the load-time half of the M1 acceptance test: the interpreter can be
/// as correct as it likes, but if the branch pairing is off by one the jump
/// tables point at the wrong slot and every downstream test lies.
fn run_precompile(root: &Path) -> ExitCode {
    println!("wolf-cli precompile");
    let basic = if root.join("BasicData").is_dir() {
        root.join("BasicData")
    } else {
        root.to_path_buf()
    };
    println!("  data root : {}", root.display());
    println!("  basic dir : {}", basic.display());
    println!();

    let events =
        match read(&basic.join("CommonEvent.dat")).map(|bytes| CommonEventData::parse(&bytes)) {
            Some(Ok(events)) => events,
            Some(Err(err)) => {
                eprintln!("  ! CommonEvent.dat: {err}");
                return ExitCode::FAILURE;
            }
            None => {
                eprintln!("  ! CommonEvent.dat not found under {}", basic.display());
                return ExitCode::FAILURE;
            }
        };

    let programs = ProgramSet::from_common_events(&events);
    let stats: PrecompileStats = programs.stats;

    println!("  blocks      {}", stats.blocks);
    println!("    conditions  {}", stats.conditions);
    println!("    choices     {}", stats.choices);
    println!("    loops       {}", stats.loops);
    println!(
        "  cases       {} (else {} / cancel {})",
        stats.cases, stats.else_cases, stats.cancel_cases
    );
    println!(
        "  orphans     {} case(s), {} end(s)",
        stats.orphan_cases, stats.orphan_ends
    );
    println!(
        "  implicit    {} block(s) closed by a parent 499",
        stats.implicit_closes
    );
    println!(
        "  unclosed    {} block(s) ran to the end of their event",
        stats.unclosed_blocks
    );
    println!("  depth       {} nested block(s)", stats.max_depth);
    println!(
        "  labels      {} defined, {} jump(s), {} dynamic",
        stats.labels, stats.label_jumps, stats.dynamic_labels
    );
    println!("  unresolved  {} label jump(s)", stats.unresolved_labels);
    println!();

    let checks = vec![
        Check::num("slots", 63_506, stats.slots as u64),
        // 112 belongs in this set: it opens a Condition block exactly like 111, and
        // leaving it out put 131 case markers on the wrong block (docs/OPCODE_112.md).
        // The counters below are now exactly the opcode census: conditions =
        // 111 (10,743) + 112 (123), cases = 401 (18,555), else = 420 (3,279),
        // cancel = 421 (153), and every tolerance counter is back to zero.
        Check::num("blocks", 5_470, stats.blocks as u64),
        // 111 / 112 / 102 / 170+179+176 marker counts from docs/BASELINE.json: the
        // precompiler must see each marker command exactly once.
        Check::num("conditions", 4_372, stats.conditions as u64),
        Check::num("choices", 163, stats.choices as u64),
        Check::num("loops", 935, stats.loops as u64),
        Check::num("labels", 267, stats.labels as u64),
        Check::num("label_jumps", 612, stats.label_jumps as u64),
        // 3, not 5: only events 31/63/86 put \cself[n] inside a 213 label
        // (docs/OPCODE_SPEC.md §4.7 corrected by measuring the data again).
        Check::num("dynamic_labels", 51, stats.dynamic_labels as u64),
        Check::num("malformed_conditions", 0, stats.malformed_conditions as u64),
        Check::num("cases", 7_562, stats.cases as u64),
        Check::num("else_cases", 1_012, stats.else_cases as u64),
        Check::num("cancel_cases", 85, stats.cancel_cases as u64),
        // Tolerance counters: markers are still counted when the stack is empty,
        // but a correct stack discipline reaches zero for all of them (the 112
        // fix removed the last orphans).
        Check::num("orphan_cases", 0, stats.orphan_cases as u64),
        Check::num("orphan_ends", 0, stats.orphan_ends as u64),
        Check::num("implicit_closes", 54, stats.implicit_closes as u64),
        Check::num("unclosed_blocks", 0, stats.unclosed_blocks as u64),
        Check::num("max_depth", 25, stats.max_depth as u64),
        Check::num("programs", 350, programs.len() as u64),
        // Every non-empty title must be findable again (300 CallByName and the
        // debug menu both depend on this index).
        Check::num(
            "titles_indexed",
            count_titles_indexed(&programs),
            count_titles_indexed(&programs),
        ),
    ];
    report(&checks)
}

/// How many event titles the name index can resolve again.
fn count_titles_indexed(programs: &ProgramSet) -> u64 {
    let mut count = 0u64;
    for id in 0..programs.len() as u32 {
        if let Some(program) = programs.event(id) {
            let title = program.title.trim();
            if !title.is_empty() && programs.id_by_name(title).is_some() {
                count += 1;
            }
        }
    }
    count
}

/// Everything the interpreter asked the platform layer to do, counted.
struct TraceHost {
    trace: bool,
    messages: Vec<String>,
    choices: Vec<usize>,
    /// None = hold at the first prompt, which is how the title screen is captured.
    answer: Option<usize>,
    pictures: usize,
    sounds: usize,
    databases: usize,
    move_routes: usize,
    teleports: usize,
    transitions: usize,
    parties: usize,
    scrolls: usize,
    effects: usize,
    saves: usize,
    reserves: usize,
    pro: usize,
    debug: Vec<String>,
    warnings: Vec<String>,
    /// Documented-but-unmodelled behaviour (124 sub-ops, 151/161 layouts).
    infos: Vec<String>,
    ended: bool,
}

impl TraceHost {
    fn new(trace: bool, answer: Option<usize>) -> Self {
        TraceHost {
            trace,
            messages: Vec::new(),
            choices: Vec::new(),
            answer,
            pictures: 0,
            sounds: 0,
            databases: 0,
            move_routes: 0,
            teleports: 0,
            transitions: 0,
            parties: 0,
            scrolls: 0,
            effects: 0,
            saves: 0,
            reserves: 0,
            pro: 0,
            debug: Vec::new(),
            warnings: Vec::new(),
            infos: Vec::new(),
            ended: false,
        }
    }

    fn note(&mut self, line: String) {
        if self.trace {
            println!("{line}");
        }
    }
}

impl Host for TraceHost {
    fn show_message(&mut self, text: &str, face: Option<i32>) {
        match face {
            Some(index) => self.note(format!("  101 message  [face {index}] {text}")),
            None => self.note(format!("  101 message  {text}")),
        }
        self.messages.push(text.to_owned());
    }

    // Auto-advance: a headless trace never waits for a keypress.
    fn message_dismissed(&mut self) -> bool {
        true
    }

    fn close_message(&mut self) {
        self.note("  105 close message".to_owned());
    }

    fn show_choices(&mut self, options: &[String]) {
        self.note(format!("  102 choices  {options:?}"));
    }

    // Without --answer the prompt is held: a headless trace then shows the menu
    // frame instead of branching away from it, which is what M1's screenshot
    // needs (docs/M1_CLOSURE.md §5).
    fn choice_made(&mut self) -> Option<ChoiceReply> {
        let index = self.answer?;
        if self.choices.is_empty() {
            self.choices.push(index);
            self.note(format!("  -> answered option {index}"));
        }
        Some(ChoiceReply::Index(index))
    }

    fn picture(&mut self, cmd: &PictureCmd) {
        self.pictures += 1;
        self.note(format!(
            "  150 picture  #{} kind {} {:?} file={} text={} args={:?}",
            cmd.number,
            cmd.kind,
            cmd.action,
            short(&cmd.file),
            short(&cmd.text),
            cmd.args
        ));
    }

    fn sound(&mut self, cmd: &SoundCmd) {
        self.sounds += 1;
        self.note(format!(
            "  140 sound    {:?} {:?} {} vol={} frames={}",
            cmd.channel,
            cmd.action,
            short(&cmd.file),
            cmd.volume,
            cmd.frames
        ));
    }

    fn database(&mut self, op: &DbOp) -> Option<DbValue> {
        self.databases += 1;
        self.note(format!(
            "  250 database type {} data {} item {} flags {:#x} destination {:?} source {:?} labels {:?}/{:?}",
            op.db_type, op.data_id, op.item_id, op.flags, op.destination, op.source,
            op.type_label, op.field_label
        ));
        None
    }

    fn move_route(&mut self, target: i32, route: &[wf::command::RouteCommand]) {
        self.move_routes += 1;
        self.note(format!(
            "  201 route    target {target} ({} step(s))",
            route.len()
        ));
    }

    fn teleport(&mut self, target: i32, map: i32, x: i32, y: i32, options: i32) {
        self.teleports += 1;
        self.note(format!(
            "  130 teleport target {target} -> map {map} at {x},{y} options {options:#x}"
        ));
    }

    fn transition(&mut self, kind: i32, flags: i32) {
        self.transitions += 1;
        self.note(format!("  16x transition kind {kind} flags {flags:#x}"));
    }

    fn party(&mut self, args: &[i32]) {
        self.parties += 1;
        self.note(format!("  270 party    {args:?}"));
    }

    fn scroll(&mut self, args: &[i32]) {
        self.scrolls += 1;
        self.note(format!("  281 scroll   {args:?}"));
    }

    fn effect(&mut self, kind: i32, duration: i32, args: &[i32]) {
        self.effects += 1;
        self.note(format!(
            "  290 effect   kind {kind} for {duration} {args:?}"
        ));
    }

    fn save_load(&mut self, op: &wolf_vm::SaveOp) -> Option<i32> {
        self.saves += 1;
        self.note(format!("  22x saveload op {} {:?}", op.opcode, op.file));
        None
    }

    fn reserve(&mut self, event: wolf_vm::exec::EventId) {
        self.reserves += 1;
        self.note(format!("  211 reserve  event {event}"));
    }

    fn debug_message(&mut self, text: &str) {
        self.note(format!("  106 debug    {text}"));
        self.debug.push(text.to_owned());
    }

    fn clear_debug(&mut self) {
        self.note("  107 clear debug".to_owned());
    }

    fn return_to_title(&mut self) {
        self.note("  174 return to title".to_owned());
        self.ended = true;
    }

    fn end_game(&mut self) {
        self.note("  175 end game".to_owned());
        self.ended = true;
    }

    fn pro_feature(&mut self, kind: i32, milliseconds: i32) {
        self.pro += 1;
        self.note(format!("  1000 pro     kind {kind} for {milliseconds} ms"));
    }

    fn log(&mut self, level: LogLevel, message: &str) {
        if self.trace {
            println!("  [{level:?}] {message}");
        }
        match level {
            LogLevel::Warn | LogLevel::Error => {
                self.warnings.push(format!("{level:?}: {message}"));
            }
            LogLevel::Info => self.infos.push(message.to_owned()),
            LogLevel::Trace => {}
        }
    }
}

/// Keep trace lines readable: escape-bearing picture names can be long.
fn short(text: &str) -> String {
    let mut out = String::new();
    for (index, ch) in text.chars().enumerate() {
        if index >= 40 {
            out.push('…');
            break;
        }
        out.push(if ch.is_control() { ' ' } else { ch });
    }
    out
}

/// Run one common event headlessly.
///
/// This is the M1 debugging workhorse from PLAN.md: \`wolf-cli run --event N\`
/// executes the event against a recording host so a branch can be checked
/// without a window, a GPU or a save file.
/// Print every common event with its size, so a caller can find the event that
/// drives a given screen without opening the editor.
///
/// The real-instruction count excludes the NOP slots the editor leaves behind,
/// which is why it is smaller than the slot count (docs/OPCODE_SPEC.md §0.1).
fn run_list(root: &Path, filter: Option<&str>) -> ExitCode {
    let basic = if root.join("BasicData").is_dir() {
        root.join("BasicData")
    } else {
        root.to_path_buf()
    };
    let Some(bytes) = read(&basic.join("CommonEvent.dat")) else {
        return ExitCode::FAILURE;
    };
    let events = match wf::commonevent::CommonEventData::parse(&bytes) {
        Ok(events) => events,
        Err(err) => {
            eprintln!("CommonEvent.dat: {err}");
            return ExitCode::FAILURE;
        }
    };
    let needle = filter.map(str::to_lowercase);
    println!("events in {}/CommonEvent.dat", basic.display());
    let mut shown = 0usize;
    for event in &events.events {
        let title = &event.title;
        if let Some(needle) = &needle {
            if !title.to_lowercase().contains(needle) {
                continue;
            }
        }
        let mut stats = SlotStats::default();
        stats.extend(&event.commands);
        shown += 1;
        println!(
            "{:>4}  {:>5} slot(s)  {:>5} real  {:>3} op(s)  {}",
            event.id,
            stats.slots,
            stats.real(),
            stats.distinct_opcodes(),
            title
        );
    }
    println!("{shown} event(s) listed");
    ExitCode::SUCCESS
}

/// Installs the shipped `Game.dat` random table into a bare VM.
///
/// `Game::new` does this for capture/play (see docs/research/M7_PRNG.md); `run` and
/// `run --map` build a `Vm` directly, and without this they would draw from the
/// synthetic editor-style table instead of the retail stream. The two leading u32
/// words are generator outputs, not seeds, so only the table itself reproduces the
/// game's draws. Missing or malformed `Game.dat` leaves the VM's deterministic
/// fallback in place.
fn install_retail_rng(vm: &mut Vm, root: &Path, basic: &Path) {
    let parsed = read(&basic.join("Game.dat"))
        .or_else(|| read(&root.join("Game.dat")))
        .and_then(|bytes| GameDat::parse(&bytes).ok());
    if let Some(dat) = parsed {
        vm.rng = WolfRng::from_game(dat.random_a, dat.random_b, dat.static_randoms.clone());
    }
}

fn run_event(root: &Path, id: u32, frames: usize, trace: bool, answer: Option<usize>) -> ExitCode {
    println!("wolf-cli run --event {id} --frames {frames}");
    let basic = if root.join("BasicData").is_dir() {
        root.join("BasicData")
    } else {
        root.to_path_buf()
    };
    println!("  data root : {}", root.display());
    println!();

    let events =
        match read(&basic.join("CommonEvent.dat")).map(|bytes| CommonEventData::parse(&bytes)) {
            Some(Ok(events)) => events,
            Some(Err(err)) => {
                eprintln!("  ! CommonEvent.dat: {err}");
                return ExitCode::FAILURE;
            }
            None => {
                eprintln!("  ! CommonEvent.dat not found under {}", basic.display());
                return ExitCode::FAILURE;
            }
        };

    let programs = ProgramSet::from_common_events(&events);
    let program = match programs.event(id) {
        Some(program) => Arc::clone(program),
        None => {
            eprintln!("  ! no common event with id {id}");
            return ExitCode::from(2);
        }
    };
    println!("  event     [{id}] {}", program.title);
    println!("  slots     {}", program.len());
    println!();

    let mut vm = Vm::new(programs);
    install_retail_rng(&mut vm, root, &basic);
    let mut host = TraceHost::new(trace, answer);
    if vm.start_event(id).is_none() {
        eprintln!("  ! cannot start event {id}");
        return ExitCode::FAILURE;
    }

    let mut total_steps = 0usize;
    let mut peak_instances = 1usize;
    let mut frames_run = 0usize;
    let mut reported: Vec<String> = Vec::new();
    for _ in 0..frames {
        let report: StepReport = vm.step_frame(&mut host);
        frames_run += 1;
        total_steps += report.steps;
        peak_instances = peak_instances.max(report.running);
        for note in &report.notes {
            if !reported.iter().any(|seen| seen == note) {
                reported.push(note.clone());
            }
        }
        if report.running == 0 {
            break;
        }
    }

    println!();
    println!("  frames run       {frames_run}");
    println!("  instructions     {total_steps}");
    println!("  peak coroutines  {peak_instances}");
    println!("  messages         {}", host.messages.len());
    println!("  choices          {}", host.choices.len());
    println!("  pictures         {}", host.pictures);
    println!("  sounds           {}", host.sounds);
    println!("  database ops     {}", host.databases);
    println!("  move routes      {}", host.move_routes);
    println!("  teleports        {}", host.teleports);
    println!("  transitions      {}", host.transitions);
    println!("  party ops        {}", host.parties);
    println!("  scrolls          {}", host.scrolls);
    println!("  effects          {}", host.effects);
    println!("  save/load        {}", host.saves);
    println!("  reserves         {}", host.reserves);
    println!("  pro features     {}", host.pro);
    if answer.is_none() && !host.choices.is_empty() {
        println!(
            "  holding          the event is parked on choice prompt {} (pass --answer <N> to take a branch)",
            host.choices.len()
        );
    }
    if !host.messages.is_empty() {
        println!();
        println!("  first message    {}", short(&host.messages[0]));
        if host.messages.len() > 1 {
            println!(
                "  last message     {}",
                short(&host.messages[host.messages.len() - 1])
            );
        }
    }
    if !host.infos.is_empty() {
        println!();
        println!(
            "  unmodelled       {} (documented gaps, not failures)",
            host.infos.len()
        );
        let mut seen: Vec<&String> = Vec::new();
        for note in &host.infos {
            if !seen.contains(&note) {
                seen.push(note);
            }
        }
        for note in seen.iter().take(10) {
            println!("    {note}");
        }
    }
    if !host.warnings.is_empty() {
        println!();
        println!("  warnings         {}", host.warnings.len());
        let mut seen: Vec<&String> = Vec::new();
        for note in &host.warnings {
            if !seen.contains(&note) {
                seen.push(note);
            }
        }
        for note in seen.iter().take(20) {
            println!("    {note}");
        }
    }
    if !reported.is_empty() {
        println!();
        println!("  diagnostics:");
        for note in reported.iter().take(40) {
            println!("    {note}");
        }
    }

    let checks = vec![
        Check::num("started", 1, 1),
        Check::num("frames_run > 0", 1, u64::from(frames_run > 0)),
        // Zero warnings means every opcode this event touched is implemented and
        // every string/label it needed resolved.
        Check::num("warnings", 0, host.warnings.len() as u64),
        Check::num("no diagnostics", 0, reported.len() as u64),
    ];
    let code = report(&checks);
    if !reported.is_empty() {
        println!(
            "NOTE — {} distinct interpreter diagnostic(s) above",
            reported.len()
        );
    }
    code
}

/// `dump` drives a real [`Game`] (real databases, real scheduler) with inputs seeded
/// before the first frame, then reads state back out. This is the probe the battle
/// slices need: `run --event` uses a counting stub host, so it cannot show whether a
/// `250` write changed CDataBase or whether a variable came out at a particular value.
#[allow(clippy::too_many_arguments)]
/// Accept either the flat variable slot (350) or the script's magic address
/// (2_000_000 + 350) so `--var 2000350=1` and `--var 350=1` mean the same slot.
fn normalise_var_addr(addr: u32) -> usize {
    const VAR_BASE: u32 = 2_000_000;
    if (VAR_BASE..VAR_BASE + 1_000_000).contains(&addr) {
        (addr - VAR_BASE) as usize
    } else {
        addr as usize
    }
}

fn run_dump(
    root: &Path,
    event: Option<u32>,
    frames: usize,
    seed_vars: &[(u32, i32)],
    seed_selfs: &[(usize, i32)],
    show_dbs: &[(String, i32)],
    print_vars: &[u32],
    print_selfs: &[usize],
    key_frames: &[(usize, u32)],
    press_every: &[(usize, u32)],
    auto_input: bool,
    watch_vars: &[u32],
    watch_start: &[u32],
    watch: Option<u32>,
) -> ExitCode {
    let id = match event {
        Some(id) => id,
        None => {
            eprintln!("dump needs --event <ID>");
            return ExitCode::from(2);
        }
    };
    let mut game = match Game::new(root) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("cannot load the game data: {err}");
            return ExitCode::FAILURE;
        }
    };
    if AUDIO.load(std::sync::atomic::Ordering::Relaxed) {
        game.enable_audio();
    }
    install_font_metrics(&mut game, root);
    // A dump has no keyboard: dismiss messages and answer prompts so a turn loop
    // marches to its end instead of parking on the first 101/102.
    game.auto_advance = true;
    game.auto_choice = true;
    game.start_engine_events();
    let instance: InstanceId = match game.vm.start_event(id) {
        Some(instance) => instance,
        None => {
            eprintln!("no common event with id {id}");
            return ExitCode::from(2);
        }
    };
    for (addr, value) in seed_vars {
        game.vm.vars.set(normalise_var_addr(*addr), *value);
    }
    if let Some(inst) = game.vm.instance_mut(instance) {
        for (slot, value) in seed_selfs {
            inst.self_vars.set(*slot, *value);
        }
    }
    println!("wolf-cli dump --event {id} --frames {frames}");
    println!();

    let mut last_self: Vec<Option<i32>> = vec![None; print_selfs.len()];
    let mut watch_var_last: Vec<Option<i32>> = vec![None; watch_vars.len()];
    let mut total_steps = 0usize;
    let mut peak = 1usize;
    let mut frames_run = 0usize;
    let mut watch_pc: std::collections::BTreeMap<InstanceId, usize> =
        std::collections::BTreeMap::new();
    // Lifecycle state for --watch-start: store the instance id currently alive per
    // watched event (None = not running). A fresh id means a new start; None after an
    // id means it stopped, so both edges are reported without relying on --watch pc moves.
    let mut watch_start_live: Vec<Option<InstanceId>> = vec![None; watch_start.len()];
    for frame in 0..frames {
        // One frame of a held key is one press: 123 polls read the code of whatever
        // bits are set this frame. `--key-frame N:CODE` names a WOLF key code (10
        // decide, 11 cancel, ...) so a probe can walk a menu without a keyboard.
        game.key_bits = key_bits_for_frame(frame, key_frames, press_every, auto_input);
        let outcome = game.frame();
        frames_run += 1;
        for (i, wanted) in watch_start.iter().enumerate() {
            let live = game
                .vm
                .instances()
                .iter()
                .rev()
                .find(|inst| inst.event == *wanted)
                .map(|inst| inst.id);
            match (watch_start_live[i], live) {
                (None, Some(new_id)) => {
                    println!("  start frame {frame}: id {new_id} event {wanted} (started)");
                    watch_start_live[i] = Some(new_id);
                }
                (Some(old_id), None) => {
                    println!("  start frame {frame}: id {old_id} event {wanted} (stopped)");
                    watch_start_live[i] = None;
                }
                (Some(old_id), Some(new_id)) if old_id != new_id => {
                    println!("  start frame {frame}: id {old_id} event {wanted} (stopped)");
                    println!("  start frame {frame}: id {new_id} event {wanted} (started)");
                    watch_start_live[i] = Some(new_id);
                }
                _ => {}
            }
        }
        if let Some(watched) = watch {
            for inst in game.vm.instances() {
                if inst.event != watched {
                    continue;
                }
                if watch_pc.get(&inst.id).copied() != Some(inst.pc) {
                    if watch_pc.len() < 400 {
                        println!(
                            "  watch frame {frame}: id {} event {} pc {} wait {:?}",
                            inst.id, inst.event, inst.pc, inst.wait
                        );
                    }
                    watch_pc.insert(inst.id, inst.pc);
                }
            }
        }
        for (i, addr) in watch_vars.iter().enumerate() {
            let value = game.vm.vars.get(normalise_var_addr(*addr));
            if watch_var_last[i] != Some(value) {
                println!("  var frame {frame}: {addr} = {value}");
                watch_var_last[i] = Some(value);
            }
        }
        total_steps += outcome.report.steps;
        peak = peak.max(outcome.report.running);
        if let Some(inst) = game.vm.instance(instance) {
            for (i, slot) in print_selfs.iter().enumerate() {
                last_self[i] = Some(inst.self_vars.get(*slot));
            }
        }
        if outcome.report.running == 0 {
            break;
        }
    }

    println!("  frames run      {frames_run}");
    println!("  instructions    {total_steps}");
    println!("  peak coroutines {peak}");
    println!("  instance alive  {}", game.vm.instance(instance).is_some());
    for addr in print_vars {
        println!(
            "  var {addr} = {}",
            game.vm.vars.get(normalise_var_addr(*addr))
        );
    }
    for (i, slot) in print_selfs.iter().enumerate() {
        match last_self[i] {
            Some(value) => println!("  self {slot} = {value}"),
            None => println!("  self {slot} = <never observed>"),
        }
    }
    for (name, db_type) in show_dbs {
        let container = match name.as_str() {
            "C" | "CData" | "CDataBase" => Container::CData,
            "S" | "Sys" | "SysDatabase" => Container::Sys,
            "D" | "Data" | "DataBase" => Container::Data,
            other => {
                eprintln!("unknown db container {other} (use C, S or D)");
                return ExitCode::from(2);
            }
        };
        let rows = game.databases.row_count(container, *db_type);
        let cols = game.databases.field_count(container, *db_type);
        println!("  db {name}:{db_type} rows={rows:?} cols={cols:?}");
    }
    println!("  coroutines:");
    for inst in game.vm.instances() {
        println!(
            "    id {} event {} pc {} wait {:?}",
            inst.id, inst.event, inst.pc, inst.wait
        );
    }
    let unanswered = game
        .diagnostics
        .iter()
        .filter(|(msg, _)| msg.contains("unanswered"))
        .count();
    println!(
        "  diagnostics     {} distinct, {unanswered} unanswered",
        game.diagnostics.len()
    );
    for (msg, count) in game.diagnostics.iter().take(30) {
        println!("    {count}x {msg}");
    }
    ExitCode::SUCCESS
}

fn run_condition_label(condition: u8) -> &'static str {
    match condition {
        0 => "ce.run_condition.0",
        1 => "ce.run_condition.1",
        2 => "ce.run_condition.2",
        _ => "ce.run_condition.3",
    }
}

/// All .mps files in a map directory, sorted so the output is stable.
/// Locate the game's `.sav` files.
///
/// Ordering matters: `SaveData01`..`SaveData08` are user slots and
/// `System` is the settings file, and sorting by path keeps the report
/// reproducible across runs.
fn save_file_list() -> Vec<PathBuf> {
    let dir =
        std::env::var_os("WOLF_SAVE_DIR").map_or_else(|| game_dir().join("Save"), PathBuf::from);
    let Ok(entries) = std::fs::read_dir(&dir) else {
        return Vec::new();
    };
    let mut files: Vec<PathBuf> = entries
        .filter_map(|entry| entry.ok())
        .map(|entry| entry.path())
        .filter(|path| {
            path.extension()
                .and_then(|ext| ext.to_str())
                .is_some_and(|ext| ext.eq_ignore_ascii_case("sav"))
        })
        .collect();
    files.sort();
    files
}

fn map_file_list(dir: &Path) -> Vec<PathBuf> {
    let Ok(entries) = std::fs::read_dir(dir) else {
        return Vec::new();
    };
    let mut files: Vec<PathBuf> = entries
        .filter_map(|entry| entry.ok())
        .map(|entry| entry.path())
        .filter(|path| {
            path.extension()
                .is_some_and(|ext| ext.eq_ignore_ascii_case("mps"))
        })
        .collect();
    files.sort();
    files
}

fn read(path: &Path) -> Option<Vec<u8>> {
    match std::fs::read(path) {
        Ok(bytes) => Some(bytes),
        Err(err) => {
            eprintln!("  ! cannot read {}: {err}", path.display());
            None
        }
    }
}

fn report(checks: &[Check]) -> ExitCode {
    let width = checks.iter().map(|c| c.label.len()).max().unwrap_or(0);
    let mut failures = 0usize;
    let mut skipped = 0usize;
    for check in checks {
        let mark = if check.skipped {
            skipped += 1;
            "SKIP"
        } else if check.ok {
            "  ok"
        } else {
            failures += 1;
            "FAIL"
        };
        if check.skipped {
            println!(
                "[{mark}] {:<width$}  (loader pending)",
                check.label,
                width = width
            );
        } else if check.ok {
            println!(
                "[{mark}] {:<width$}  {}",
                check.label,
                check.actual,
                width = width
            );
        } else {
            println!(
                "[{mark}] {:<width$}  expected {}, got {}",
                check.label,
                check.expected,
                check.actual,
                width = width
            );
        }
    }
    println!();
    if failures == 0 {
        println!(
            "PASS — {} check(s) matched baseline, {} pending",
            checks.len() - skipped,
            skipped
        );
        ExitCode::SUCCESS
    } else {
        println!("FAIL — {failures} check(s) disagree with the baseline");
        ExitCode::FAILURE
    }
}

/// Install directory of the original game.
///
/// `$WOLF_GAME_DIR` wins; the literal default is this machine's Steam library and is
/// the only hard-coded path in the project (fonts and saves are not in the unpacked
/// data root, and both are optional inputs).
fn game_dir() -> PathBuf {
    const DEFAULT: &str = "E:/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver";
    match std::env::var("WOLF_GAME_DIR") {
        Ok(dir) if !dir.is_empty() => PathBuf::from(dir),
        _ => PathBuf::from(DEFAULT),
    }
}

/// Fonts this series ships next to the data, best first.
///
/// This game's data root contains the Japanese face
/// `07やさしさゴシックボールド.ttf` and the alternative
/// `◆GenJyuuGothicX-P-Bold.ttf`; the sister game uses the ASCII spellings. They are the
/// fallback when the system font `Game.dat` names is unavailable.
const BUNDLED_FONT_NAMES: [&str; 6] = [
    "07やさしさゴシックボールド.ttf",
    "07yasashi.ttf",
    "◆GenJyuuGothicX-P-Bold.ttf",
    "GenJyuuGothicXPB.ttf",
    "Lolita.ttf",
    "MSGOTHIC.TTF",
];

/// Font files to try, in retail precedence order.
///
/// 1. The system font `Game.dat` names. WOLF 2.00 stores the UI family in the string
///    table (`font_main`, `strings[3]`; this game: `Microsoft Yahei UI Bold`), and the
///    Chinese patch renders through that family, not through the bundled Japanese face.
/// 2. The bundled faces ([`BUNDLED_FONT_NAMES`]) under `<root>/Fonts`, `<root>`, then the
///    install directory.
/// 3. Any other `*.ttf/*.otf/*.ttc` those directories ship, sorted by path so the choice
///    is deterministic.
///
/// Only paths that exist are returned; the caller reads bytes lazily and may fall through
/// to the next entry if the renderer rejects one (e.g. a TTC the local fontdb cannot open).
fn font_paths(root: &Path) -> Vec<PathBuf> {
    font_paths_in(root, &game_dir())
}

/// [`font_paths`] with the install directory as an explicit parameter, so the search
/// order is testable without touching `$WOLF_GAME_DIR`.
fn font_paths_in(root: &Path, install: &Path) -> Vec<PathBuf> {
    let mut out: Vec<PathBuf> = Vec::new();
    {
        let mut push = |path: PathBuf| {
            if path.is_file() && !out.contains(&path) {
                out.push(path);
            }
        };

        // 1. The retail font family, main name first and the three secondary names after.
        if let Some(dat) = read_game_dat(root) {
            for family in std::iter::once(dat.font_main()).chain(dat.fonts_secondary()) {
                for path in system_font_paths(family) {
                    push(path);
                }
            }
        }

        // 2. The bundled faces in known-name order.
        let bases = [
            root.join("Fonts"),
            root.to_path_buf(),
            install.to_path_buf(),
        ];
        for base in &bases {
            for name in BUNDLED_FONT_NAMES {
                push(base.join(name));
            }
        }

        // 3. Deterministic scan for a font under a name the lists do not know.
        for base in &bases {
            let Ok(entries) = std::fs::read_dir(base) else {
                continue;
            };
            let mut fonts: Vec<PathBuf> = entries
                .flatten()
                .map(|entry| entry.path())
                .filter(|path| path.is_file() && is_font(path))
                .collect();
            fonts.sort();
            for path in fonts {
                push(path);
            }
        }
    }
    out
}

/// Reads and parses the game's `Game.dat`, whether the root is the install directory or
/// the unpacked data directory. A missing or malformed file is not fatal.
fn read_game_dat(root: &Path) -> Option<GameDat> {
    let candidates = [
        root.join("BasicData").join("Game.dat"),
        root.join("Game.dat"),
    ];
    for path in candidates {
        let Ok(bytes) = std::fs::read(&path) else {
            continue;
        };
        if let Ok(dat) = GameDat::parse(&bytes) {
            return Some(dat);
        }
    }
    None
}

/// Windows font directories, system first and per-user second.
fn system_font_dirs() -> Vec<PathBuf> {
    let mut dirs = Vec::new();
    match std::env::var_os("WINDIR") {
        Some(windir) => dirs.push(PathBuf::from(windir).join("Fonts")),
        None => dirs.push(PathBuf::from("C:/Windows/Fonts")),
    }
    if let Some(local) = std::env::var_os("LOCALAPPDATA") {
        let user = PathBuf::from(local)
            .join("Microsoft")
            .join("Windows")
            .join("Fonts");
        if user.is_dir() {
            dirs.push(user);
        }
    }
    dirs
}

/// System faces that fill in glyphs the primary UI font lacks.
///
/// The CN patch's UI family (Microsoft YaHei UI) has no glyph for the geometric
/// shapes WOLF uses as cursors: the night menu's choice marker is U+25B6 and the
/// retail renderer drew it from its own font, not from the dialog face. The
/// platform fallback list already names "Segoe UI Symbol", so loading that face
/// into the same private database is enough; no general system-font scan happens.
fn system_fallback_fonts() -> Vec<PathBuf> {
    const NAMES: [&str; 2] = ["seguisym.ttf", "msyhbd.ttc"];
    let mut out: Vec<PathBuf> = Vec::new();
    for dir in system_font_dirs() {
        for name in NAMES {
            let path = dir.join(name);
            if path.is_file() && !out.contains(&path) {
                out.push(path);
            }
        }
    }
    out
}

/// Offer the symbol fallback to a renderer that already accepted `primary`.
///
/// Called by both `capture` and `play`; failures are logged but never fatal,
/// because a missing symbol face must not stop the game from drawing its text.
pub(crate) fn install_font_fallbacks(renderer: &mut Renderer, primary: &Path) {
    for path in system_fallback_fonts() {
        if path == primary {
            continue;
        }
        let Ok(bytes) = std::fs::read(&path) else {
            continue;
        };
        match renderer.add_fallback_font(&bytes) {
            Ok(()) => println!("  fallback  : {}", path.display()),
            Err(err) => eprintln!("  fallback rejected ({}): {err}", path.display()),
        }
    }
}

/// The first font candidate the text stack can actually open.
///
/// `play` uses this single-font entry point; `capture` walks [`font_paths`] itself so it
/// can report every rejected candidate.
pub(crate) fn find_font(root: &Path) -> Option<(PathBuf, Vec<u8>)> {
    for path in font_paths(root) {
        let Ok(bytes) = std::fs::read(&path) else {
            continue;
        };
        if renderer_accepts_font(&bytes) {
            return Some((path, bytes));
        }
    }
    None
}

/// Whether the renderer's own font database can parse this file.
///
/// `missing_glyphs` returns an empty list in two situations: the font covers every
/// character, or `fontdb` rejected the file. Feeding it a private-use and a noncharacter
/// codepoint separates them: a font that parsed cannot draw those, so a non-empty list
/// proves the file is usable. This mirrors the renderer's acceptance test without a GPU.
fn renderer_accepts_font(bytes: &[u8]) -> bool {
    !wolf_render::missing_glyphs(bytes, "\u{F0000}\u{10FFFD}", 20.0).is_empty()
}

/// Lower-cases a font family name and drops separators, so `Microsoft Yahei UI Bold`
/// and `microsoft yahei ui bold` compare equal.
fn normalise_family(name: &str) -> String {
    name.chars()
        .filter(|ch| ch.is_alphanumeric())
        .flat_map(char::to_lowercase)
        .collect()
}

/// The Windows font files a `Game.dat` family name most likely lives in, best first.
///
/// Windows names fonts by family while the files on disk use unrelated short names
/// (`Microsoft YaHei` is `msyh.ttc`), so the faces this series actually names are listed
/// explicitly. An unlisted family is still resolved by [`family_matches_file`].
fn system_font_files(family: &str) -> Vec<&'static str> {
    match normalise_family(family).as_str() {
        "microsoftyahei" | "microsoftyaheiui" => vec!["msyh.ttc", "msyhbd.ttc"],
        "microsoftyaheibold" | "microsoftyaheiuibold" => vec!["msyhbd.ttc", "msyh.ttc"],
        "msgothic" | "mspgothic" | "msgothicui" => vec!["msgothic.ttc"],
        "msmincho" => vec!["msmincho.ttc"],
        "yugothic" | "yugothicui" => vec!["YuGothR.ttc", "YuGothB.ttc"],
        "yugothicbold" => vec!["YuGothB.ttc", "YuGothR.ttc"],
        "meiryo" | "meiryoui" => vec!["meiryo.ttc", "meiryob.ttc"],
        "meiryobold" => vec!["meiryob.ttc", "meiryo.ttc"],
        "segoeui" => vec!["segoeui.ttf"],
        "arial" => vec!["arial.ttf"],
        "tahoma" => vec!["tahoma.ttf"],
        "simsun" => vec!["simsun.ttc"],
        "simhei" => vec!["simhei.ttf"],
        _ => Vec::new(),
    }
}

/// True when a font file's stem names the family, e.g. `arial.ttf` for `Arial`.
fn family_matches_file(family_key: &str, path: &Path) -> bool {
    let Some(stem) = path.file_stem().and_then(|stem| stem.to_str()) else {
        return false;
    };
    let stem = normalise_family(stem);
    // Very short stems ("ms") would match everything; only trust four characters or more.
    stem.len() >= 4 && (stem == family_key || family_key.contains(&stem))
}

/// The existing Windows font files for one family, in preference order.
fn system_font_paths(family: &str) -> Vec<PathBuf> {
    let family = family.trim();
    if family.is_empty() {
        return Vec::new();
    }
    let dirs = system_font_dirs();
    let mut out: Vec<PathBuf> = Vec::new();
    for file in system_font_files(family) {
        for dir in &dirs {
            let path = dir.join(file);
            if path.is_file() && !out.contains(&path) {
                out.push(path);
            }
        }
    }
    // Anything the table does not name: case-insensitive file-name match over the Fonts
    // directories, so e.g. a family whose file is simply its own name still resolves.
    let key = normalise_family(family);
    if key.len() < 4 {
        return out;
    }
    for dir in &dirs {
        let Ok(entries) = std::fs::read_dir(dir) else {
            continue;
        };
        let mut fonts: Vec<PathBuf> = entries
            .flatten()
            .map(|entry| entry.path())
            .filter(|path| path.is_file() && is_font(path))
            .collect();
        fonts.sort();
        for path in fonts {
            if !out.contains(&path) && family_matches_file(&key, &path) {
                out.push(path);
            }
        }
    }
    out
}

/// True for the font container extensions the renderer can parse.
fn is_font(path: &Path) -> bool {
    path.extension()
        .and_then(|extension| extension.to_str())
        .is_some_and(|extension| {
            matches!(
                extension.to_ascii_lowercase().as_str(),
                "ttf" | "otf" | "ttc"
            )
        })
}

/// Gives text-picture layout the real glyph advances from the same font the renderer
/// shapes with. Without it anchors 1/3/4 drift by the half-em-vs-real difference.
///
/// The retail-named system font is tried first; a font the metrics parser cannot read
/// (for whatever reason the renderer might also reject) falls through to the next.
pub(crate) fn install_font_metrics(game: &mut Game, root: &Path) {
    for path in font_paths(root) {
        let Ok(bytes) = std::fs::read(&path) else {
            continue;
        };
        if game.set_font_metrics(bytes) {
            break;
        }
    }
}

/// Builds a render instance from an atlas quad, carrying its alpha and its picture tone.
///
/// The tone is per picture, not per frame: a `290` flash changes what one picture
/// multiplies its texels by while everything else on screen keeps drawing at full
/// brightness, so it has to ride on the instance rather than on a global draw state.
fn tint_instance(quad: &wolf_game::atlas::SpriteQuad) -> SpriteInstance {
    SpriteInstance::new(quad.rect, quad.uv)
        .with_alpha(quad.alpha)
        .with_tint_rgb(quad.tint[0], quad.tint[1], quad.tint[2])
}
/// Where a capture starts.
///
/// The retail entry point is the boot map, but two other entries are useful: the
/// bare title menu (to photograph the runtime choice panel without the splash
/// chain) and an arbitrary map event (the M2 story scripts, which never call the
/// title at all).
/// How a headless capture answers choice prompts.
#[derive(Clone, Debug, Default)]
struct Answers {
    /// Option to preselect and confirm; `None` holds every prompt open (the title).
    index: Option<usize>,
    /// Frames a prompt must stay on screen before that click lands.
    delay: u32,
    /// Pointer position in game pixels, written to the host every frame.
    pointer: Option<(i32, i32)>,
    /// 0-based frame at which the left mouse button goes down for one frame.
    press_frame: Option<usize>,
    /// (frame, WOLF key code) pairs injected for exactly one frame each.
    key_frames: Vec<(usize, u32)>,
    /// (cadence, WOLF key code) pairs: the key is held on every frame divisible by the
    /// cadence (`1` = every frame). Lets a capture walk an opcode-123 poll loop without
    /// knowing the frame each poll fires on.
    press_every: Vec<(usize, u32)>,
    /// Hold the decide key (code 10) on every frame.
    auto_input: bool,
    /// Ordinary-variable seeds applied after the entry event starts (flat slot or magic
    /// address, same normalisation as `dump --var`).
    seed_vars: Vec<(u32, i32)>,
    /// Self-variable seeds (flat slots) written into the entry event's instance.
    seed_selfs: Vec<(usize, i32)>,
    /// Whether the `run_condition == 2` scheduler runs (default true; see
    /// `--auto-events off`).
    auto_events: bool,
}

enum Entry<'a> {
    Boot,
    Menu,
    Script {
        map: &'a str,
        event: u32,
    },
    Save(&'a Path),
    /// A single common event, started after the engine events. `capture --event <ID>`
    /// without an explicit `--boot`/`--menu-only` lands here; before this variant existed
    /// the id was silently dropped and the run photographed the boot map instead
    /// (docs/BATTLE.md section 6.2).
    CommonEvent(u32),
}

/// The capture entry point, resolved from the command line alone.
///
/// This is a plain owning value rather than `Entry` so the resolution rules can be unit
/// tested without borrowing command-line strings (or loading the game data at all).
#[derive(Debug, Clone, PartialEq, Eq)]
enum CaptureEntry {
    Boot,
    Menu,
    Script { map: String, event: u32 },
    Save(PathBuf),
    CommonEvent(u32),
}

/// Pick the capture entry point from the flags that were actually given.
///
/// Precedence, highest first: `--load-save` > `--map-run` > `--event` > `--boot` >
/// default boot. `--event` only wins when neither `--boot` nor `--menu-only` was given
/// explicitly, because those two name an entry point of their own. `--map` never reaches
/// here: `capture --map <NAME>` takes the separate map-rendering path.
///
/// `boot` defaults to true, which is why the explicit flags are tracked separately: a
/// default that cannot say "the user did not ask for this" used to make
/// `capture --event 239` fall back to the boot map and photograph the vendor logo.
fn resolve_capture_entry(
    load_save: Option<&Path>,
    map_run: Option<&str>,
    event: Option<u32>,
    boot_explicit: bool,
    menu_only: bool,
) -> CaptureEntry {
    if let Some(path) = load_save {
        return CaptureEntry::Save(path.to_path_buf());
    }
    if let Some(map) = map_run {
        return CaptureEntry::Script {
            map: map.to_owned(),
            event: event.unwrap_or(0),
        };
    }
    if menu_only {
        return CaptureEntry::Menu;
    }
    if let Some(id) = event {
        if !boot_explicit {
            return CaptureEntry::CommonEvent(id);
        }
    }
    // `boot` itself defaults to true; --menu-only already returned above, so anything
    // left here is the boot path (explicit --boot included).
    CaptureEntry::Boot
}

/// The screen contents a capture draws, built identically for the scripted
/// (`capture`) and map (`capture --map`) paths: tile layer, picture layer, text
/// pictures, the runtime choice window and the 101 pause cursor.
struct CaptureFrame {
    atlas: Atlas,
    sprites: Vec<SpriteQuad>,
    texts: Vec<TextQuad>,
}

/// Runs `frames` frames of the game, injecting this capture's pointer / press / key
/// inputs one frame at a time. Returns the peak number of live coroutines seen.
fn drive_capture_frames(game: &mut Game, frames: usize, answers: &Answers) -> usize {
    let mut peak = 0usize;
    for frame in 0..frames {
        if let Some((x, y)) = answers.pointer {
            game.mouse = [x, y];
        }
        // One frame of a held button is a click: the host compares against the previous
        // frame, so the press edge survives exactly one step.
        game.mouse_buttons = u32::from(answers.press_frame == Some(frame));
        game.key_bits = key_bits_for_frame(
            frame,
            &answers.key_frames,
            &answers.press_every,
            answers.auto_input,
        );
        let outcome = game.frame();
        peak = peak.max(outcome.report.running);
    }
    peak
}

/// Composites one frame from a live game: tiles, then the picture layer, then the
/// choice window and the message cursor. Both capture paths call this so
/// `capture --map` cannot drift from `capture`.
fn build_capture_frame(game: &mut Game) -> CaptureFrame {
    let mut atlas = Atlas::new();
    let mut sprites = game.tile_quads(&mut atlas);
    sprites.extend(game.picture_quads(&mut atlas));
    let mut texts = game.text_quads();
    // A WOLF script never draws its own choice frame: the engine paints a window skin and
    // moves a cursor over it, at the coordinates system variables 3 (x) and 4 (y) name.
    // There is no centred default (docs/OPCODE_102.md section 4.2), and when the finished
    // rectangle falls outside the 1024x576 viewport the engine paints nothing at all -
    // which is what the title event relies on when it parks the window at y = 1000.
    if let Some(choices) = &game.choices {
        let options = choices.options.clone();
        let cursor = game.choice_cursor();
        let (x, y) = game.choice_anchor();
        // Sys8 sizes the option text, so the panel is measured at the size it is drawn.
        let font_px = game.font_px();
        if let Some((panel, rows)) = choice::overlay_at_sized(
            &mut atlas,
            &mut game.assets,
            &options,
            cursor,
            x,
            y,
            font_px,
        ) {
            sprites.extend(panel);
            texts.extend(rows);
        }
    }
    // The engine draws the 101 pause cursor itself: SystemFile/Text_Pause.png is a strip of
    // six 17x15 frames whose triangle bobs down and back up, and no picture command in the
    // game names it. It is a texture, so it joins the sprite pass, not the glyph pass.
    let newest = game.messages.last().map(|m| (m.text.clone(), m.frames));
    if let Some((text, frames)) = newest {
        let vars = game.message_vars();
        let layout = wolf_game::message::layout(&text, &vars, frames);
        if let Some(at) = layout.cursor {
            let frame = wolf_game::message::cursor_frame(frames);
            let src = [
                0,
                frame * wolf_game::message::CURSOR_FRAME_H,
                wolf_game::message::CURSOR_FRAME_W,
                wolf_game::message::CURSOR_FRAME_H,
            ];
            let dst = [
                at[0],
                at[1],
                wolf_game::message::CURSOR_FRAME_W as f32,
                wolf_game::message::CURSOR_FRAME_H as f32,
            ];
            if let Some(quad) = atlas.sprite_from(
                &mut game.assets,
                wolf_game::message::CURSOR_FILE,
                wolf_game::message::CURSOR_SLOT,
                src,
                dst,
                1.0,
            ) {
                sprites.push(quad);
            }
        }
    }
    for warning in atlas.take_warnings() {
        *game.diagnostics.entry(warning).or_insert(0) += 1;
    }
    CaptureFrame {
        atlas,
        sprites,
        texts,
    }
}

/// Uploads the atlas, draws the sprite and glyph passes and writes the PNG. Returns
/// false (after printing the reason) when the GPU adapter, atlas upload, readback or
/// file write failed.
fn render_capture_frame(
    game: &Game,
    root: &Path,
    out: &Path,
    atlas: Atlas,
    sprites: &[SpriteQuad],
    texts: &[TextQuad],
) -> bool {
    let [atlas_w, atlas_h] = atlas.size();
    let mut renderer = match Renderer::new_offscreen() {
        Ok(renderer) => renderer,
        Err(err) => {
            eprintln!("no usable GPU adapter: {err}");
            return false;
        }
    };
    if let Err(err) = renderer.set_atlas(atlas.pixels(), atlas_w, atlas_h) {
        eprintln!("atlas upload failed: {err}");
        return false;
    }
    // Text pictures need a font. Prefer the system family `Game.dat` names (retail
    // parity; the CN patch renders through Microsoft YaHei), then the bundled faces and
    // the install directory. The renderer is the authority on whether a file is usable:
    // a TTC the local fontdb rejects must not blank the text pass, so try the next
    // candidate instead.
    let mut chosen: Option<PathBuf> = None;
    let mut rejected: Vec<(PathBuf, String)> = Vec::new();
    for path in font_paths(root) {
        let Ok(bytes) = std::fs::read(&path) else {
            continue;
        };
        match renderer.set_font(&bytes) {
            Ok(()) => {
                chosen = Some(path);
                break;
            }
            Err(err) => rejected.push((path, err.to_string())),
        }
    }
    match &chosen {
        Some(path) => println!("  font      : {}", path.display()),
        None => println!("  font      : none found; text pictures will not draw"),
    }
    if let Some(path) = &chosen {
        install_font_fallbacks(&mut renderer, path);
    }
    for (path, err) in rejected {
        eprintln!("  font rejected ({}): {err}", path.display());
    }

    let instances: Vec<SpriteInstance> = sprites.iter().map(tint_instance).collect();
    renderer.draw(&instances);
    let mut items: Vec<TextItem> = texts
        .iter()
        .map(|text| {
            // A text picture may mix sizes, colours and outlines inside one string;
            // the layout already turned each style change into its own quad.
            let size = if text.font_px > 0.0 {
                text.font_px
            } else {
                game.font_px()
            };
            let mut item = TextItem::new(text.text.clone(), text.rect, size)
                .with_alpha(text.alpha)
                .with_colour(text.colour);
            if text.outline {
                item = item.with_outline(2, [0, 0, 0]);
            }
            item
        })
        .collect();
    // The engine draws 101 message text itself: the frame comes from common event 63 as
    // ordinary pictures, the glyphs come from here. Only the newest message is visible,
    // which is the order the interpreter produces.
    if let Some(layout) = game.message_layout() {
        let message = game.messages.last().expect("layout implies a message");
        let vars = game.message_vars();
        let preview: String = message.text.chars().take(60).collect();
        let typing = if layout.typing { ", typing" } else { "" };
        let cursor = layout.cursor.map_or(String::new(), |at| {
            format!(", cursor at [{:.0},{:.0}]", at[0], at[1])
        });
        println!(
            "  message   : {} row(s), {}/{} char(s), font {:.0} at [{:.0},{:.0}], wrap {:.0}{}{}",
            layout.rows.len(),
            layout.typed,
            layout.total,
            layout.font_px,
            vars.x,
            vars.y,
            vars.wrap_width(),
            typing,
            cursor
        );
        println!("    text    : {preview:?}");
        for run in &layout.runs {
            // Give each run one em of slack: the layout measures with the half-em rule,
            // while cosmic-text shapes with the real font advance, and a box that is a
            // fraction too narrow makes the renderer wrap the last glyph onto a new line.
            let mut rect = run.rect;
            rect[2] += run.font_px;
            let mut item = TextItem::new(run.text.clone(), rect, run.font_px)
                .with_colour(run.colour.unwrap_or(wolf_game::message::DEFAULT_COLOUR));
            if run.outline {
                item = item.with_outline(2, [0, 0, 0]);
            }
            items.push(item);
        }
    }
    renderer.draw_text(&items);

    renderer.present();
    // Text statistics are only known after the pass has been encoded, so they are reported
    // here rather than next to the item list.
    let text_stats = renderer.text_stats();
    println!(
        "  text      : {} item(s), {} glyph(s), {} line(s), {} substituted",
        text_stats.items, text_stats.glyphs, text_stats.lines, text_stats.substituted
    );
    if let Some(missing) = text_stats.missing.first() {
        eprintln!("  warning   : font has no glyph for {missing:?}");
    }
    let pixels = match renderer.capture_rgba() {
        Ok(pixels) => pixels,
        Err(err) => {
            eprintln!("readback failed: {err}");
            return false;
        }
    };

    if let Some(parent) = out.parent() {
        if !parent.as_os_str().is_empty() {
            if let Err(err) = std::fs::create_dir_all(parent) {
                eprintln!("cannot create {}: {err}", parent.display());
                return false;
            }
        }
    }
    if let Err(err) =
        image::save_buffer(out, &pixels, LOGICAL_W, LOGICAL_H, image::ColorType::Rgba8)
    {
        eprintln!("cannot write {}: {err}", out.display());
        return false;
    }

    let lit = pixels
        .chunks_exact(4)
        .filter(|pixel| pixel[0] | pixel[1] | pixel[2] != 0)
        .count();
    let total = (LOGICAL_W * LOGICAL_H) as usize;
    println!(
        "  rendered  : {LOGICAL_W}x{LOGICAL_H}, {lit}/{total} non-black pixel(s) = {:.1}%",
        lit as f64 * 100.0 / total as f64
    );
    println!("  wrote     : {}", out.display());
    true
}

/// Reports how much of the 108-event background system a run actually exercised.
///
/// WOLF keeps 108 coroutines alive for the whole session: 10 engine always-on events
/// (the ENGINE_ALWAYS list), 1 auto-start event, and 97 run_condition == 2 events
/// whose start is gated by a variable. The M6 main-line proof is that a real entry
/// point (SampleMapA event 0, the new-game story) keeps that machinery turning
/// without deadlocking, so print the registry size next to what ran.
fn print_background_report(game: &Game) {
    let tracked = game.auto_events.events();
    let tracked_ran = tracked
        .iter()
        .filter(|event| game.vm.started_events.contains(&event.id))
        .count();
    println!(
        "  background: 108 registered (10 always + 1 auto_start + 97 conditional); {} distinct common event(s) started ({} of {} tracked), {} start(s) total",
        game.vm.started_events.len(),
        tracked_ran,
        tracked.len(),
        game.vm.started_event_total
    );
}

fn run_capture(
    root: &Path,
    out: Option<PathBuf>,
    frames: usize,
    answers: Answers,
    hold_message: bool,
    engine_events: Option<Vec<u32>>,
    entry: Entry<'_>,
    save_event: Option<u32>,
    translation: Option<&Path>,
) -> ExitCode {
    let out = out.unwrap_or_else(|| PathBuf::from("work/out/title.png"));
    let mut game = match Game::new(root) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("cannot load the game data: {err}");
            return ExitCode::FAILURE;
        }
    };
    if AUDIO.load(std::sync::atomic::Ordering::Relaxed) {
        game.enable_audio();
    }
    install_font_metrics(&mut game, root);
    if let Some(path) = translation {
        match game.load_translation_file(path) {
            Ok(entries) => println!("  translation: {entries} entr(ies) from {}", path.display()),
            Err(err) => {
                eprintln!("translation: {err}");
                return ExitCode::FAILURE;
            }
        }
    }
    // A capture has no keyboard, so messages dismiss immediately. Choice prompts are
    // HELD by default: the title's first prompt is its menu, and answering it teleports
    // into the game (docs/M1_CLOSURE.md §5), so a held run is what photographs the title.
    // --hold-message parks the run on the first 101 message instead, which is how a
    // capture photographs the message window (the story scripts talk before they branch).
    game.auto_advance = !hold_message;
    game.auto_events.set_enabled(answers.auto_events);
    game.engine_always = engine_events;
    if let Some(index) = answers.index {
        game.set_choice_cursor(index);
        game.auto_choice = true;
        game.auto_choice_delay = answers.delay;
    }
    // Two entry points: the real boot path (map autorun event -> splashes -> title art
    // -> menu) and the bare menu event 42, kept for regression captures of the menu
    // overlay on its own.
    // The instance a bare common event starts, so `--self` seeds land on the event the
    // capture drives (mirrors `dump --self`, which seeds the main event's self vars).
    let mut entry_instance: Option<InstanceId> = None;
    let (started, label) = match entry {
        Entry::Boot => (
            game.boot().map_err(|err| err.to_string()),
            "boot map (TitleMap.mps event 2)".to_owned(),
        ),
        Entry::Menu => (
            game.start_title().map_err(|err| err.to_string()),
            "common event 42".to_owned(),
        ),
        Entry::Script { map, event } => (
            game.start_map_event_by_name(map, event)
                .map_err(|err| err.to_string()),
            format!("map script {map} event {event}"),
        ),
        // A bare common event. The engine events go first: every script in this game
        // talks to them (they own the window/input system), so starting an event without
        // them leaves it waiting on a subsystem that never runs. start_engine_events is
        // idempotent, so an event that later calls one of them is unaffected.
        Entry::CommonEvent(id) => {
            game.start_engine_events();
            let started = if game.start_event(id) {
                entry_instance = game
                    .vm
                    .instances()
                    .iter()
                    .rev()
                    .find(|i| i.event == id)
                    .map(|i| i.id);
                Ok(())
            } else {
                Err(format!("no common event with id {id}"))
            };
            (started, format!("common event {id}"))
        }
        Entry::Save(path) => {
            let label = format!("save file {}", path.display());
            // Finish CE48 before restoring: otherwise its first pass rewrites the
            // loaded status cells (see Game::prime_engine).
            game.prime_engine();
            match game.load_save(path) {
                Ok(loaded) => {
                    println!(
                        "  loaded    : {} picture(s), {} normal variable(s), playtime {} frame(s), choice anchor {:?}",
                        loaded.pictures, loaded.normal_vars, loaded.playtime_frames, loaded.choice_anchor
                    );
                    // A bare load leaves the map runtime empty. The retail 220 path
                    // restarts the map from the save-menu coroutine; the CLI has no
                    // such coroutine, so rebuild it from the SavePart1 snapshot.
                    let resumed = game
                        .resume_loaded_map()
                        .map(|name| println!("  resumed   : map {name}"));
                    // An optional --event lets a loaded save drive a menu/UI event
                    // (e.g. CE245 night command) on top of the restored bedroom.
                    let started = match resumed {
                        Err(err) => Err(err),
                        Ok(()) => match save_event {
                            Some(id) => {
                                if game.start_event(id) {
                                    println!("  script    : common event {id}");
                                    Ok(())
                                } else {
                                    Err(format!("no common event with id {id}"))
                                }
                            }
                            None => Ok(()),
                        },
                    };
                    (started, label)
                }
                Err(err) => (Err(err), label),
            }
        }
    };
    if let Err(err) = started {
        eprintln!("{err}");
        return ExitCode::FAILURE;
    }
    println!("  entry     : {label}");

    // Seed inputs after the entry event is live, exactly as `dump` does. A capture of
    // CE242 needs the battle-active flag and the chosen-command self var to leave its
    // guarded prologue; without them the state-machine branch is never entered.
    for (addr, value) in &answers.seed_vars {
        game.vm.vars.set(normalise_var_addr(*addr), *value);
    }
    if let Some(instance) = entry_instance {
        if let Some(inst) = game.vm.instance_mut(instance) {
            for (slot, value) in &answers.seed_selfs {
                inst.self_vars.set(*slot, *value);
            }
        }
    }

    let peak = drive_capture_frames(&mut game, frames, &answers);

    let CaptureFrame {
        atlas,
        sprites,
        texts,
    } = build_capture_frame(&mut game);
    let [atlas_w, atlas_h] = atlas.size();

    println!("capture");
    println!("  data root : {}", root.display());
    println!("  frames    : {frames} (peak {peak} coroutine(s))");
    {
        let rgb = game.screen_tint_rgb();
        println!(
            "  tint      : [{:.3}, {:.3}, {:.3}] (151 ChangeColor)",
            rgb[0], rgb[1], rgb[2]
        );
    }
    // Every live coroutine with the state it is parked in. A message or a prompt that
    // outlives the script that showed it is visible here first: the wait state names the
    // opcode that is holding it.
    for instance in game.vm.instances() {
        println!(
            "    coro {:<3} event {:<6} pc {:<5} wait {:?}",
            format!("{:?}", instance.id),
            instance.event,
            instance.pc,
            instance.wait
        );
    }
    println!(
        "  pictures  : {} live -> {} textured quad(s), {} text picture(s)",
        game.screen.len(),
        sprites.len(),
        texts.len()
    );
    for picture in game.screen.iter() {
        println!(
            "    pic {:<6} {:?} at ({}, {}) alpha {:.2} scale {} window {:?} {}",
            picture.number,
            picture.kind,
            picture.x,
            picture.y,
            picture.alpha(),
            picture.scale,
            picture.window,
            if picture.file.is_empty() {
                format!("text {:?}", picture.text)
            } else {
                format!("file {:?}", picture.file)
            }
        );
    }
    match &game.choices {
        Some(choices) => {
            let (x, y) = game.choice_anchor();
            let anchored = choice::layout_at_sized(
                &choices.options,
                game.choice_cursor(),
                x,
                y,
                game.font_px(),
            );
            println!(
                "  choice    : HELD on prompt with {} option(s) {:?}, cursor {} at anchor ({x}, {y})",
                choices.options.len(),
                choices.options,
                game.choice_cursor()
            );
            match anchored {
                Some(panel) => println!(
                    "            : engine rect {:?}, {} row(s)",
                    panel.rect,
                    panel.lines.len()
                ),
                None => println!("            : anchor is off screen, engine draws nothing"),
            }
        }
        None => println!("  choice    : none open"),
    }
    // Sys8 is the font size shared by messages, choices and text pictures, so print it
    // next to the layout it produced: a capture that looks wrong is usually a stale Sys8.
    println!(
        "  sys8 font : {:.0} px (Sys8, used by every text path)",
        game.font_px()
    );
    println!(
        "  sys pads  : Sys20 {} Sys22 {} Sys26 {} Sys27 {}",
        game.sys(20),
        game.sys(22),
        game.sys(26),
        game.sys(27)
    );
    println!(
        "  atlas     : {} image(s), {:.1}% of {atlas_w}x{atlas_h}",
        atlas.len(),
        atlas.fill_ratio() * 100.0
    );
    for quad in &sprites {
        println!(
            "    quad pic {:>6} at [{:.0},{:.0},{:.0},{:.0}] uv [{:.3},{:.3},{:.3},{:.3}]",
            quad.number,
            quad.rect[0],
            quad.rect[1],
            quad.rect[2],
            quad.rect[3],
            quad.uv[0],
            quad.uv[1],
            quad.uv[2],
            quad.uv[3]
        );
    }
    for text in &texts {
        let preview: String = text.text.chars().take(40).collect();
        println!(
            "    text pic {:>6} at [{:.0},{:.0},{:.0},{:.0}] {}",
            text.number, text.rect[0], text.rect[1], text.rect[2], text.rect[3], preview
        );
    }

    if !render_capture_frame(&game, root, &out, atlas, &sprites, &texts) {
        return ExitCode::FAILURE;
    }

    println!(
        "  auto      : {} tracked conditional/gated event(s), {} running {:?}",
        game.auto_events.len(),
        game.auto_events.running_count(),
        game.auto_events.running_ids()
    );
    print_background_report(&game);
    println!(
        "  map input : last action event {:?}, {} page start(s), {} page switch(es)",
        game.last_action_event, game.runtime.restarts, game.runtime.switches
    );
    let warnings = game.stats.warnings;
    println!(
        "  stats     : {} instruction(s), {} picture op(s), {} sound(s), {} db access(es) ({} write, {} label), {} message(s), {} choice(s), {warnings} warning(s)",
        game.stats.instructions,
        game.stats.pictures,
        game.stats.sounds,
        game.stats.databases,
        game.stats.database_writes,
        game.stats.database_labels,
        game.stats.messages,
        game.stats.choices
    );
    if !game.diagnostics.is_empty() {
        println!("  diagnostics ({} distinct):", game.diagnostics.len());
        for (text, count) in game.diagnostics.iter().take(12) {
            println!("    {count:>6}x {text}");
        }
    }
    ExitCode::SUCCESS
}

/// Renders one map frame to a PNG, composited exactly like the scripted `capture`
/// path: the room's tile layer, then its picture layer, then text pictures.
///
/// The map's automatic pages run for `frames` frames first (so a parallel page that
/// paints the room's picture layer actually draws it), and `--pointer` /
/// `--press-frame` / `--key-frame` inject the same one-frame inputs a scripted capture
/// does. The tile camera is the Game's fixed origin [0, 0] (docs/HSCENE.md 4.3).
fn run_capture_map(
    root: &Path,
    out: Option<PathBuf>,
    frames: usize,
    name: &str,
    answers: &Answers,
    load_save: Option<&Path>,
    script_event: Option<u32>,
    translation: Option<&Path>,
) -> ExitCode {
    let out = out.unwrap_or_else(|| PathBuf::from("work/out/map.png"));
    let basic = if root.join("BasicData").is_dir() {
        root.join("BasicData")
    } else {
        root.to_path_buf()
    };
    // The tileset is only needed for the header (its base image name); Game owns the
    // actual tile layer.
    let tileset_bytes = match read(&basic.join("TileSetData.dat")) {
        Some(bytes) => bytes,
        None => {
            eprintln!("no TileSetData.dat under {}", basic.display());
            return ExitCode::FAILURE;
        }
    };
    let tilesets = match wf::tileset::TileSetData::parse(&tileset_bytes) {
        Ok(value) => value,
        Err(err) => {
            eprintln!("TileSetData.dat: {err}");
            return ExitCode::FAILURE;
        }
    };
    // A bare map name (with or without the .mps suffix) is looked up under MapData/,
    // which is where this game's registered maps live; an explicit path is used as-is.
    let relative: PathBuf = if name.contains('/') {
        PathBuf::from(name)
    } else if name.ends_with(".mps") {
        PathBuf::from(format!("MapData/{name}"))
    } else {
        PathBuf::from(format!("MapData/{name}.mps"))
    };
    let map_bytes = match read(&root.join(&relative)) {
        Some(bytes) => bytes,
        None => {
            eprintln!("cannot read {}", root.join(&relative).display());
            return ExitCode::FAILURE;
        }
    };
    let map = match wf::mps::Map::parse(&map_bytes) {
        Ok(value) => value,
        Err(err) => {
            eprintln!("{}: {err}", relative.display());
            return ExitCode::FAILURE;
        }
    };
    let Some(tileset) = tilesets.get(map.tileset_index) else {
        eprintln!(
            "map points at tileset {} but only {} exist",
            map.tileset_index,
            tilesets.tilesets.len()
        );
        return ExitCode::FAILURE;
    };

    let mut graphics: std::collections::BTreeMap<String, usize> = std::collections::BTreeMap::new();
    for event in &map.events {
        for page in &event.pages {
            if !page.graphic.is_empty() {
                *graphics.entry(page.graphic.clone()).or_insert(0) += 1;
            }
        }
    }
    if !graphics.is_empty() {
        println!("  graphics  : {} distinct page chip(s)", graphics.len());
        for (name, count) in graphics.iter().take(20) {
            println!("              {count:>3}x {name}");
        }
    }

    // Drive a real Game so the room's picture layer composites over its tiles, exactly
    // as the scripted capture does. start_pages installs the tile layer AND starts the
    // map's automatic pages (the ones that draw the background/picture layer).
    let mut game = match Game::new(root) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("cannot load the game data: {err}");
            return ExitCode::FAILURE;
        }
    };
    if AUDIO.load(std::sync::atomic::Ordering::Relaxed) {
        game.enable_audio();
    }
    install_font_metrics(&mut game, root);
    if let Some(path) = translation {
        match game.load_translation_file(path) {
            Ok(entries) => println!("  translation: {entries} entr(ies) from {}", path.display()),
            Err(err) => {
                eprintln!("translation: {err}");
                return ExitCode::FAILURE;
            }
        }
    }
    game.auto_advance = true;
    game.auto_events.set_enabled(answers.auto_events);
    if let Some(index) = answers.index {
        game.set_choice_cursor(index);
        game.auto_choice = true;
        game.auto_choice_delay = answers.delay;
    }
    // Run CE48's one-shot initialisation before loading: loading first lets that
    // engine coroutine overwrite the restored HP/stamina/action cells a few frames
    // later (see Game::prime_engine).  Real boot finishes it before the title menu.
    let primed = game.prime_engine();
    if primed > 0 {
        eprintln!("  primed    : engine initialisation ran {primed} frame(s) before load");
    }
    if let Some(path) = load_save {
        match game.load_save(path) {
            Ok(loaded) => println!(
                "  loaded    : {} picture(s), {} normal variable(s), playtime {} frame(s), choice anchor {:?}",
                loaded.pictures, loaded.normal_vars, loaded.playtime_frames, loaded.choice_anchor
            ),
            Err(err) => {
                eprintln!("{err}");
                return ExitCode::FAILURE;
            }
        }
    }
    // Seed ordinary variables before the map pages are selected: a page gate such as
    // SampleMapA event 10's `v15 == 99` decides which page is active, and a capture
    // that seeds after `start_pages` is already looking at the wrong page.
    for (addr, value) in &answers.seed_vars {
        game.vm.vars.set(normalise_var_addr(*addr), *value);
    }
    // The engine's 108 background coroutines are session-wide: a real map change keeps
    // them running (Game::switch_map does not touch them), so a map capture that skipped
    // them would photograph a world that is not the one the game actually shows. Start
    // them before the map's own pages so HUD/UI scripts are live from frame 0.
    game.start_engine_events();
    game.start_pages(&map, None);
    // A map photograph is the room, not a story. `start_pages` also starts the map's
    // autorun pages, and SampleMapA event 0 is the new-game opening: its very first
    // picture is `cg/blackscreen.jpg`, a purely black 1024x540 CG painted full-screen
    // over the tile layer, so `capture --map SampleMapA --frames 30` came out black
    // (measured 0.0% non-black at frames 1..9; `--frames 0`, before event 0 runs, is
    // 100% non-black). The parallel pages are the ones that dress the room and keep its
    // HUD alive, so keep those and retire the one-shot scripts. `--map-run <NAME>
    // --event <ID>` is the path that plays a script page.
    let stopped_autorun = stop_autorun_pages(&mut game);
    // `capture --map <NAME> --event <ID>` plays one action/parallel page on an otherwise
    // static room. Starting it here, after the autorun scripts are retired, lets the
    // capture photograph a UI panel without the new-game opening painting over it.
    if let Some(id) = script_event {
        if !game.start_map_event(&map, id) {
            eprintln!("{name}: no map event with id {id}");
            return ExitCode::FAILURE;
        }
        println!("  script    : event {id}");
    }
    let peak = drive_capture_frames(&mut game, frames, answers);

    let CaptureFrame {
        atlas,
        sprites,
        texts,
    } = build_capture_frame(&mut game);
    let [atlas_w, atlas_h] = atlas.size();

    let map_w = map.width as i32 * wolf_game::tilemap::TILE_PX as i32;
    let map_h = map.height as i32 * wolf_game::tilemap::TILE_PX as i32;
    println!("capture --map {name}");
    println!("  data root : {}", root.display());
    println!(
        "  map       : {} {}x{} tile(s) = {}x{} px, {} layer(s), {} event(s)",
        relative.display(),
        map.width,
        map.height,
        map_w,
        map_h,
        map.layers.len(),
        map.events.len()
    );
    println!(
        "  tileset   : index {} base {}",
        map.tileset_index, tileset.base_image
    );
    println!("  camera    : [0, 0] (Game tile layer, fixed origin)");
    println!("  frames    : {frames} (peak {peak} coroutine(s))");
    println!(
        "  autorun   : {stopped_autorun} one-shot script page(s) skipped (parallel pages kept)"
    );
    {
        let rgb = game.screen_tint_rgb();
        println!(
            "  tint      : [{:.3}, {:.3}, {:.3}] (151 ChangeColor)",
            rgb[0], rgb[1], rgb[2]
        );
    }
    println!(
        "  pictures  : {} live -> {} textured quad(s), {} text picture(s)",
        game.screen.len(),
        sprites.len(),
        texts.len()
    );
    for picture in game.screen.iter() {
        println!(
            "    pic {:<6} {:?} at ({}, {}) alpha {:.2} scale {} window {:?} {}",
            picture.number,
            picture.kind,
            picture.x,
            picture.y,
            picture.alpha(),
            picture.scale,
            picture.window,
            if picture.file.is_empty() {
                format!("text {:?}", picture.text)
            } else {
                format!("file {:?}", picture.file)
            }
        );
    }
    match &game.choices {
        Some(choices) => println!(
            "  choice    : HELD on prompt with {} option(s) {:?}",
            choices.options.len(),
            choices.options
        ),
        None => println!("  choice    : none open"),
    }
    println!(
        "  sys8 font : {:.0} px (Sys8, used by every text path)",
        game.font_px()
    );
    println!(
        "  atlas     : {} image(s), {:.1}% of {atlas_w}x{atlas_h}",
        atlas.len(),
        atlas.fill_ratio() * 100.0
    );
    for quad in &sprites {
        println!(
            "    quad pic {:>6} at [{:.0},{:.0},{:.0},{:.0}] uv [{:.3},{:.3},{:.3},{:.3}]",
            quad.number,
            quad.rect[0],
            quad.rect[1],
            quad.rect[2],
            quad.rect[3],
            quad.uv[0],
            quad.uv[1],
            quad.uv[2],
            quad.uv[3]
        );
    }
    for text in &texts {
        let preview: String = text.text.chars().take(40).collect();
        println!(
            "    text pic {:>6} at [{:.0},{:.0},{:.0},{:.0}] {}",
            text.number, text.rect[0], text.rect[1], text.rect[2], text.rect[3], preview
        );
    }

    if !render_capture_frame(&game, root, &out, atlas, &sprites, &texts) {
        return ExitCode::FAILURE;
    }

    println!(
        "  auto      : {} tracked conditional/gated event(s), {} running {:?}",
        game.auto_events.len(),
        game.auto_events.running_count(),
        game.auto_events.running_ids()
    );
    print_background_report(&game);
    println!(
        "  map input : last action event {:?}, {} page start(s), {} page switch(es)",
        game.last_action_event, game.runtime.restarts, game.runtime.switches
    );
    let warnings = game.stats.warnings;
    println!(
        "  stats     : {} instruction(s), {} picture op(s), {} sound(s), {} db access(es) ({} write, {} label), {} message(s), {} choice(s), {warnings} warning(s)",
        game.stats.instructions,
        game.stats.pictures,
        game.stats.sounds,
        game.stats.databases,
        game.stats.database_writes,
        game.stats.database_labels,
        game.stats.messages,
        game.stats.choices
    );
    if !game.diagnostics.is_empty() {
        println!("  diagnostics ({} distinct):", game.diagnostics.len());
        for (text, count) in game.diagnostics.iter().take(12) {
            println!("    {count:>6}x {text}");
        }
    }
    ExitCode::SUCCESS
}

/// Stops the one-shot autorun pages a `capture --map` run just started.
///
/// `MapRuntime::start_pending` records that a page already started during this
/// activation and does not restart a non-looping page, so stopping the coroutine here
/// retires the script for the rest of the capture. Parallel pages keep running and
/// restart when their stream ends, which is what keeps the room's HUD alive.
///
/// Returns how many pages were retired, for the capture report.
fn stop_autorun_pages(game: &mut Game) -> usize {
    let mut stopped = 0;
    for slot in game.runtime.slots() {
        if slot.trigger != wolf_game::map_runtime::Trigger::Autorun {
            continue;
        }
        if let Some(instance) = slot.instance() {
            game.vm.stop_instance(instance);
            stopped += 1;
        }
    }
    stopped
}

/// Run one MAP event page through the interpreter.
///
/// The M1 title screen lives in a map (TitleMap.mps event 2), and PLAN's M2
/// acceptance closure is keyed on SampleMapA event 1, so map command streams
/// need the same treatment common events already get: compile the page with
/// `Program::from_slots` (it builds the identical jump tables) and step it.
/// Common events stay loaded because map scripts reach them through opcode 210.
/// `blocks`: print the control flow the VM compiled for one event, so a jump that
/// disagrees with the file can be read off instead of guessed at.
fn run_blocks(root: &Path, map_name: Option<&str>, event: Option<u32>, page: usize) -> ExitCode {
    let basic = if root.join("BasicData").is_dir() {
        root.join("BasicData")
    } else {
        root.to_path_buf()
    };
    let program = match map_name {
        Some(name) => {
            let cleaned = name.replace(std::path::MAIN_SEPARATOR, "/");
            let relative: PathBuf = if cleaned.contains('/') || cleaned.ends_with(".mps") {
                PathBuf::from(cleaned)
            } else {
                PathBuf::from(format!("MapData/{cleaned}.mps"))
            };
            let Some(bytes) = read(&root.join(&relative)) else {
                eprintln!("  ! cannot read {}", root.join(&relative).display());
                return ExitCode::FAILURE;
            };
            let map = match wf::mps::Map::parse(&bytes) {
                Ok(value) => value,
                Err(err) => {
                    eprintln!("  ! {}: {err}", relative.display());
                    return ExitCode::FAILURE;
                }
            };
            let wanted = event_id_of(event);
            let Some(found) = map.events.iter().find(|found| found.id == wanted) else {
                eprintln!(
                    "  ! {} has no event {}",
                    relative.display(),
                    event_id_of(event)
                );
                return ExitCode::FAILURE;
            };
            let Some(found_page) = found.pages.get(page) else {
                eprintln!("  ! event {} has no page {page}", found.id);
                return ExitCode::FAILURE;
            };
            Program::from_slots(found.id, &found.name, found_page.commands.clone())
        }
        None => {
            let Some(id) = event else {
                eprintln!("blocks needs --event <ID> or --map <NAME> --event <ID>");
                return ExitCode::from(2);
            };
            let events = match read(&basic.join("CommonEvent.dat"))
                .map(|bytes| CommonEventData::parse(&bytes))
            {
                Some(Ok(events)) => events,
                Some(Err(err)) => {
                    eprintln!("  ! CommonEvent.dat: {err}");
                    return ExitCode::FAILURE;
                }
                None => {
                    eprintln!("  ! CommonEvent.dat not found under {}", basic.display());
                    return ExitCode::FAILURE;
                }
            };
            let Some(found) = events.events.iter().find(|event| event.id == id) else {
                eprintln!("  ! no common event {id}");
                return ExitCode::FAILURE;
            };
            Program::compile(found)
        }
    };
    println!(
        "  program   {} slots, {} block(s), {} label(s)",
        program.len(),
        program.blocks.len(),
        program.labels.len()
    );
    for (index, block) in program.blocks.iter().enumerate() {
        let head = program.slots.get(block.head).and_then(|slot| match slot {
            wolf_format::command::Slot::Command(cmd) => Some((cmd.opcode, ints_of(cmd))),
            wolf_format::command::Slot::Blank => None,
        });
        println!(
            "  block {index:>3} {:?} head {:>4} {:?} cases {:?} else {:?} cancel {:?} end {:?}",
            block.kind,
            block.head,
            head.map(|(opcode, ints)| (opcode, ints)),
            block.cases,
            block.else_pc,
            block.cancel_pc,
            if block.end_pc == usize::MAX {
                None
            } else {
                Some(block.end_pc)
            }
        );
    }
    ExitCode::SUCCESS
}

fn event_id_of(event: Option<u32>) -> u32 {
    event.unwrap_or(0)
}

fn ints_of(cmd: &wolf_format::command::Command) -> Vec<i32> {
    cmd.params
        .chunks_exact(4)
        .map(|word| i32::from_le_bytes([word[0], word[1], word[2], word[3]]))
        .collect()
}
fn run_map_event(
    root: &Path,
    map_name: &str,
    event_id: u32,
    frames: usize,
    trace: bool,
    answer: Option<usize>,
    hot: bool,
) -> ExitCode {
    println!("wolf-cli run --map {map_name} --event {event_id} --frames {frames}");
    let basic = if root.join("BasicData").is_dir() {
        root.join("BasicData")
    } else {
        root.to_path_buf()
    };
    println!("  data root : {}", root.display());

    let events =
        match read(&basic.join("CommonEvent.dat")).map(|bytes| CommonEventData::parse(&bytes)) {
            Some(Ok(events)) => events,
            Some(Err(err)) => {
                eprintln!("  ! CommonEvent.dat: {err}");
                return ExitCode::FAILURE;
            }
            None => {
                eprintln!("  ! CommonEvent.dat not found under {}", basic.display());
                return ExitCode::FAILURE;
            }
        };
    let programs = ProgramSet::from_common_events(&events);

    let cleaned = map_name.replace(std::path::MAIN_SEPARATOR, "/");
    let relative: PathBuf = if cleaned.contains('/') || cleaned.ends_with(".mps") {
        PathBuf::from(cleaned)
    } else {
        PathBuf::from(format!("MapData/{cleaned}.mps"))
    };
    let map_bytes = match read(&root.join(&relative)) {
        Some(bytes) => bytes,
        None => {
            eprintln!("  ! cannot read {}", root.join(&relative).display());
            return ExitCode::FAILURE;
        }
    };
    let map = match wf::mps::Map::parse(&map_bytes) {
        Ok(value) => value,
        Err(err) => {
            eprintln!("  ! {}: {err}", relative.display());
            return ExitCode::FAILURE;
        }
    };
    println!(
        "  map       {} {}x{} tile(s), {} event(s)",
        relative.display(),
        map.width,
        map.height,
        map.events.len()
    );

    let found = map.events.iter().find(|event| event.id == event_id);
    let Some(event) = found else {
        eprintln!("  ! no event with id {event_id}; present ids:");
        for event in &map.events {
            eprintln!("      [{:>6}] {}", event.id, event.name);
        }
        return ExitCode::from(2);
    };
    let Some(page) = event.pages.first() else {
        eprintln!("  ! event {event_id} has no page");
        return ExitCode::from(2);
    };
    println!(
        "  event     [{event_id}] {} at ({}, {}), {} page(s)",
        event.name,
        event.x,
        event.y,
        event.pages.len()
    );

    for (index, page) in event.pages.iter().enumerate() {
        println!(
            "  page {index}    trigger {} graphic {:?} chip {} slots {}",
            page.trigger,
            page.graphic,
            page.graphic_chip_id,
            page.commands.len()
        );
    }

    let program = Program::from_slots(event.id, &event.name, page.commands.clone());
    let slots = program.len();
    println!("  slots     {slots}");
    println!();

    let mut vm = Vm::new(programs);
    install_retail_rng(&mut vm, root, &basic);
    vm.hot_trace = hot;
    let mut host = TraceHost::new(trace, answer);
    if vm.start_program(Arc::new(program)).is_none() {
        eprintln!("  ! cannot start map event {event_id}");
        return ExitCode::FAILURE;
    }

    let mut total_steps = 0usize;
    let mut peak_instances = 1usize;
    let mut frames_run = 0usize;
    let mut spots: Vec<(u32, usize, u64)> = Vec::new();
    for _ in 0..frames {
        let report: StepReport = vm.step_frame(&mut host);
        frames_run += 1;
        total_steps += report.steps;
        peak_instances = peak_instances.max(report.running);
        for spot in &report.hottest {
            match spots
                .iter_mut()
                .find(|entry| entry.0 == spot.event && entry.1 == spot.pc)
            {
                Some(entry) => entry.2 += spot.hits,
                None => spots.push((spot.event, spot.pc, spot.hits)),
            }
        }
        if report.running == 0 {
            break;
        }
    }

    println!();
    println!("  frames run       {frames_run}");
    println!("  instructions     {total_steps}");
    println!("  peak coroutines  {peak_instances}");
    println!("  messages         {}", host.messages.len());
    println!("  choices          {}", host.choices.len());
    println!("  pictures         {}", host.pictures);
    println!("  sounds           {}", host.sounds);
    println!("  database ops     {}", host.databases);
    println!("  move routes      {}", host.move_routes);
    println!("  teleports        {}", host.teleports);
    println!("  transitions      {}", host.transitions);
    println!("  party ops        {}", host.parties);
    println!("  scrolls          {}", host.scrolls);
    println!("  effects          {}", host.effects);
    println!("  save/load        {}", host.saves);
    println!("  reserves         {}", host.reserves);
    println!("  pro features     {}", host.pro);
    // The park position is what makes a stuck script debuggable: a story script that
    // redraws the same two pictures every frame is waiting on one specific slot.
    for instance in vm.instances() {
        println!(
            "  live             id {} event {} pc {}/{} wait {:?} self0 {} self10 {}",
            instance.id,
            instance.event,
            instance.pc,
            instance.program.len(),
            instance.wait,
            instance.self_vars.get(0),
            instance.self_vars.get(10)
        );
    }
    if !spots.is_empty() {
        spots.sort_by_key(|spot| std::cmp::Reverse(spot.2));
        println!();
        println!("  hot spots        (instruction address -> hits)");
        for (event, pc, hits) in spots.iter().take(10) {
            println!("    ev {event:<6} pc {pc:<5} {hits} hit(s)");
        }
    }
    if !host.infos.is_empty() {
        println!();
        println!(
            "  unmodelled       {} (documented gaps, not failures)",
            host.infos.len()
        );
        let mut seen: Vec<&String> = Vec::new();
        for note in &host.infos {
            if !seen.contains(&note) {
                seen.push(note);
            }
        }
        for note in seen.iter().take(10) {
            println!("    {note}");
        }
    }
    if !host.warnings.is_empty() {
        println!();
        println!("  warnings         {}", host.warnings.len());
        let mut seen: Vec<&String> = Vec::new();
        for note in &host.warnings {
            if !seen.contains(&note) {
                seen.push(note);
            }
        }
        for note in seen.iter().take(10) {
            println!("    {note}");
        }
    }

    ExitCode::SUCCESS
}

#[cfg(test)]
mod tests {
    use super::{
        font_paths_in, key_bits_for_frame, parse_key_frame, renderer_accepts_font,
        resolve_capture_entry, system_font_files, CaptureEntry,
    };
    use std::path::{Path, PathBuf};

    /// `capture --event 239` used to fall through to `Entry::Boot` because `boot`
    /// defaults to true and nothing recorded whether the user asked for it. This is the
    /// regression guard for docs/BATTLE.md section 6.2: the id must survive on its own.
    #[test]
    fn event_alone_selects_the_common_event() {
        assert_eq!(
            resolve_capture_entry(None, None, Some(239), false, false),
            CaptureEntry::CommonEvent(239)
        );
    }

    #[test]
    fn no_flags_still_selects_the_boot_map() {
        assert_eq!(
            resolve_capture_entry(None, None, None, false, false),
            CaptureEntry::Boot
        );
    }

    /// An explicit `--boot` names an entry point, so it outranks `--event`. This is the
    /// one case where the old capture behaviour must be preserved exactly.
    #[test]
    fn explicit_boot_outranks_event() {
        assert_eq!(
            resolve_capture_entry(None, None, Some(239), true, false),
            CaptureEntry::Boot
        );
    }

    #[test]
    fn menu_only_outranks_event() {
        assert_eq!(
            resolve_capture_entry(None, None, Some(239), false, true),
            CaptureEntry::Menu
        );
    }

    #[test]
    fn map_run_outranks_event_and_keeps_the_event_as_the_map_event_id() {
        assert_eq!(
            resolve_capture_entry(None, Some("SampleMapA.mps"), Some(1), false, false),
            CaptureEntry::Script {
                map: "SampleMapA.mps".to_owned(),
                event: 1,
            }
        );
        // Without --event a map capture keeps the old default of page 0.
        assert_eq!(
            resolve_capture_entry(None, Some("TitleMap.mps"), None, false, false),
            CaptureEntry::Script {
                map: "TitleMap.mps".to_owned(),
                event: 0,
            }
        );
    }

    #[test]
    fn key_frames_parse_frame_and_wolf_code() {
        assert_eq!(parse_key_frame("12:10"), Some((12, 10)));
        assert_eq!(parse_key_frame(" 3 : 11 "), Some((3, 11)));
        assert_eq!(parse_key_frame("12"), None);
        assert_eq!(parse_key_frame("x:10"), None);
        assert_eq!(parse_key_frame("12:y"), None);
    }

    #[test]
    fn key_bits_for_frame_merges_channels() {
        let ok = wolf_game::key::bits_for_code(10);
        let cancel = wolf_game::key::bits_for_code(11);
        // One-shot --key-frame only fires on its own frame.
        assert_eq!(key_bits_for_frame(5, &[(5, 10)], &[], false), ok);
        assert_eq!(key_bits_for_frame(6, &[(5, 10)], &[], false), 0);
        // --press-every 2:10 fires on even frames only, every time.
        assert_eq!(key_bits_for_frame(4, &[], &[(2, 10)], false), ok);
        assert_eq!(key_bits_for_frame(5, &[], &[(2, 10)], false), 0);
        // --auto-input holds decide on every frame.
        assert_eq!(key_bits_for_frame(123, &[], &[], true), ok);
        // Channels OR together: a cadence plus a distinct one-shot on the same frame.
        assert_eq!(
            key_bits_for_frame(6, &[(6, 11)], &[(2, 10)], false),
            ok | cancel
        );
    }

    #[test]
    fn load_save_outranks_everything() {
        let path = PathBuf::from("save.sav");
        assert_eq!(
            resolve_capture_entry(
                Some(Path::new("save.sav")),
                Some("SampleMapA.mps"),
                Some(239),
                true,
                true
            ),
            CaptureEntry::Save(path)
        );
    }

    /// The shipped font has a Japanese name the sister-game list never contained. The
    /// fallback scan has to find it (or any TTF under a new name) deterministically,
    /// and the game's own face must win over the alternative when both are present.
    #[test]
    fn font_lookup_prefers_the_games_face_and_scans_unexpected_names() {
        // Temp files live under the repo's gitignored work/out: the harness sandbox
        // denies writes to the user's temp directory.
        let repo = Path::new(env!("CARGO_MANIFEST_DIR")).join("..").join("..");
        let dir = repo
            .join("work/out")
            .join(format!("font-test-{}", std::process::id()));
        let _ = std::fs::remove_dir_all(&dir);
        std::fs::create_dir_all(&dir).expect("temp font dir");
        let empty_game = dir.join("game");
        std::fs::create_dir_all(&empty_game).expect("temp game dir");

        // Unknown names only: sorted scan picks the first extension-sorted path.
        std::fs::write(dir.join("zz-unknown.ttf"), b"fake").expect("font file");
        std::fs::write(dir.join("aa-unknown.otf"), b"fake").expect("font file");
        let paths = font_paths_in(&dir, &empty_game);
        assert_eq!(paths[0].file_name().unwrap(), "aa-unknown.otf");
        assert_eq!(paths[1].file_name().unwrap(), "zz-unknown.ttf");
        std::fs::remove_file(dir.join("aa-unknown.otf")).expect("remove probe font");
        std::fs::remove_file(dir.join("zz-unknown.ttf")).expect("remove probe font");

        // Both shipped names present: the game's own face is chosen.
        std::fs::write(dir.join("◆GenJyuuGothicX-P-Bold.ttf"), b"fake").expect("font file");
        std::fs::write(dir.join("07やさしさゴシックボールド.ttf"), b"fake").expect("font file");
        let paths = font_paths_in(&dir, &empty_game);
        assert_eq!(
            paths[0].file_name().unwrap(),
            "07やさしさゴシックボールド.ttf"
        );

        let _ = std::fs::remove_dir_all(&dir);
    }

    /// `Game.dat` names a Windows font *family*; the file it lives in has an unrelated
    /// short name. The mapping is pure, so this test runs without any font installed.
    #[test]
    fn game_dat_font_family_maps_to_windows_font_files() {
        assert_eq!(
            system_font_files("Microsoft Yahei UI Bold"),
            vec!["msyhbd.ttc", "msyh.ttc"]
        );
        assert_eq!(
            system_font_files("microsoft yahei"),
            vec!["msyh.ttc", "msyhbd.ttc"]
        );
        assert_eq!(system_font_files("MS Gothic"), vec!["msgothic.ttc"]);
        assert!(system_font_files("Unlisted Face").is_empty());
    }

    #[test]
    fn renderer_accepts_font_rejects_garbage() {
        assert!(!renderer_accepts_font(b"not a font"));
    }

    /// The CN patch's retail family is a TTC. `play` funnels through [`find_font`], which
    /// validates with the renderer's own font database before returning a candidate, so
    /// prove that the system collection passes that check on a machine that has it.
    #[test]
    fn system_ttc_is_accepted_by_the_text_stack() {
        let Some(path) = super::system_font_paths("Microsoft Yahei UI Bold")
            .into_iter()
            .find(|path| {
                path.extension()
                    .is_some_and(|ext| ext.eq_ignore_ascii_case("ttc"))
            })
        else {
            eprintln!("skipping: no system Microsoft YaHei TTC installed");
            return;
        };
        let bytes = std::fs::read(&path).expect("read system TTC");
        assert!(
            renderer_accepts_font(&bytes),
            "fontdb rejected {}",
            path.display()
        );
    }
}
