//! `wolf-cli play` - the interactive title screen.
//!
//! This is the first command that puts the reimplementation on a real screen: it runs
//! event 42 through the interpreter, feeds the resulting picture stack through the atlas
//! and the wgpu renderer, and maps the keyboard onto WOLF's key bitmask so the game's own
//! input polling (opcode 123) sees a player.
//!
//! Frame pacing is a fixed 1/60 s grid rather than "as fast as the GPU allows" because the
//! script counts frames: opcode 180 waits N frames, animations advance per frame, and the
//! title menu's cursor speed is expressed in frames. Running the VM faster than the clock
//! would make menus unusable; running it slower would make animations crawl.
//!
//! The window is a 1024x576 logical canvas scaled into the window. The default is the
//! largest whole integer factor with black bars (the retail pixel grid); `--scale` and F9
//! switch to a fractional fit (nearest or linear), and F11 toggles borderless fullscreen.

use std::collections::HashSet;
use std::sync::Arc;
use std::time::{Duration, Instant};

use winit::application::ApplicationHandler;
use winit::dpi::PhysicalSize;
use winit::event::{ElementState, MouseButton, WindowEvent};
use winit::event_loop::{ActiveEventLoop, ControlFlow, EventLoop};
use winit::keyboard::{Key, NamedKey};
use winit::window::{Fullscreen, Window, WindowId};

use wolf_game::atlas::{Atlas, TextQuad};
use wolf_game::{choice, key, Game, Message};
use wolf_render::{Renderer, ScaleMode, SpriteInstance, TextItem, LOGICAL_H, LOGICAL_W};

use crate::hotkeys::HotkeyConfig;

/// One frame at 60 Hz.
const FRAME_TIME: Duration = Duration::from_micros(16_667);

/// Messages the M5-F transcript shows at once. Eighteen 16 px lines fit under the
/// header without touching the bottom HUD.
const BACKLOG_ROWS: usize = 18;

/// Window presentation chosen on the command line.
#[derive(Clone, Copy, Debug)]
pub struct DisplayOptions {
    /// Integer by default; `fit-nearest`/`fit-linear` fill the window fractionally.
    pub mode: ScaleMode,
    /// Start borderless-fullscreen instead of the windowed presentation.
    pub fullscreen: bool,
}

impl Default for DisplayOptions {
    fn default() -> Self {
        Self {
            mode: ScaleMode::Integer,
            fullscreen: false,
        }
    }
}

/// The largest whole-number multiple of the 1024x576 picture that fits the primary monitor.
///
/// The picture is authored at a fixed 1024x576 and the default scale mode is integer, so a
/// window of any other size letterboxes it with black bars (a 1920x1080 window only fits a
/// 1x picture, leaving wide bars). Sizing the window to the monitor keeps the picture crisp
/// and bar-free at every resolution; with no monitor information it falls back to 1x.
fn window_size_for(monitor: Option<PhysicalSize<u32>>) -> PhysicalSize<u32> {
    let Some(size) = monitor else {
        return PhysicalSize::new(LOGICAL_W, LOGICAL_H);
    };
    // Leave room for the title bar and taskbar so the OS does not clamp the window.
    let max_w = (f64::from(size.width) * 0.94) as u32;
    let max_h = (f64::from(size.height) * 0.90) as u32;
    let mut scale = 1u32;
    while (scale + 1) * LOGICAL_W <= max_w && (scale + 1) * LOGICAL_H <= max_h {
        scale += 1;
    }
    PhysicalSize::new(LOGICAL_W * scale, LOGICAL_H * scale)
}

/// M5-B runtime debug overlay: a toggleable text block drawn over the game.
#[derive(Clone, Debug, Default)]
pub struct DebugOptions {
    /// Show the overlay on startup (the debug hotkey still toggles it).
    pub overlay: bool,
    /// Variables to list by flat slot or magic address while the overlay is open.
    pub vars: Vec<u32>,
    /// Show the M5-C play-statistics / milestone overlay on startup (the stats hotkey toggles it).
    pub stats: bool,
}

/// Parse a comma separated variable list for `--debug-var`.
///
/// Accepts spaces around entries so both `154,155` and `154, 155` work. An empty
/// entry is ignored, but a non-numeric one is reported rather than silently dropped.
pub fn parse_debug_vars(text: &str) -> Result<Vec<u32>, String> {
    let mut vars = Vec::new();
    for part in text.split(',') {
        let part = part.trim();
        if part.is_empty() {
            continue;
        }
        let addr = part
            .parse::<u32>()
            .map_err(|_| format!("invalid debug variable '{part}'"))?;
        vars.push(addr);
    }
    Ok(vars)
}

/// Accept either the flat variable slot (350) or the script's magic address
/// (2_000_000 + 350) so `--debug-var 2000350` and `--debug-var 350` mean the same slot.
fn debug_slot(addr: u32) -> usize {
    const VAR_BASE: u32 = 2_000_000;
    if (VAR_BASE..VAR_BASE + 1_000_000).contains(&addr) {
        (addr - VAR_BASE) as usize
    } else {
        addr as usize
    }
}

/// Builds the M5-F transcript page: a header line and the visible messages.
///
/// `scroll` counts how many of the newest messages are hidden, so 0 is the live end
/// of the conversation and a larger value walks backwards one page at a time. The
/// body is one string rather than one item per message: cosmic-text then wraps a long
/// line inside the panel instead of letting it run into the next message's row.
fn backlog_view(history: &[Message], scroll: usize) -> (String, String) {
    let total = history.len();
    let scroll = scroll.min(total.saturating_sub(BACKLOG_ROWS));
    let end = total - scroll;
    let start = end.saturating_sub(BACKLOG_ROWS);
    let header = if total == 0 {
        "消息回顾 | 暂无消息 | F4 关闭".to_owned()
    } else {
        format!(
            "消息回顾 | {}-{} / {} | PgUp/PgDn 滚动 | F4 关闭",
            start + 1,
            end,
            total
        )
    };
    let mut body = String::new();
    for message in &history[start..end] {
        body.push_str(message.text.trim_end());
        body.push('\n');
    }
    (header, body)
}

/// Runs the title screen in a window until the user closes it (or `frames` pass).
///
/// A non-zero frame budget makes the window self-closing, which is how the interactive
/// path gets smoke-tested: the same code that a player drives also has to survive an
/// unattended run without panicking or wedging the event loop.
pub fn run(
    root: &std::path::Path,
    frames: Option<u64>,
    entry: crate::Entry<'_>,
    display: DisplayOptions,
    debug: DebugOptions,
    translation: Option<&std::path::Path>,
    mods: &[std::path::PathBuf],
    hotkeys: HotkeyConfig,
) -> std::process::ExitCode {
    let mut game = match Game::with_overlays(root, mods.to_vec()) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("cannot load the game data: {err}");
            return std::process::ExitCode::FAILURE;
        }
    };
    if crate::AUDIO.load(std::sync::atomic::Ordering::Relaxed) {
        game.enable_audio();
    }
    // System.sav volumes reach the mixer before the first frame is rendered.
    game.apply_settings();
    crate::install_font_metrics(&mut game, root);
    if let Some(path) = translation {
        match game.merge_translation_file(path) {
            Ok(entries) => println!("translation: {entries} entr(ies) from {}", path.display()),
            Err(err) => {
                eprintln!("translation: {err}");
                return std::process::ExitCode::FAILURE;
            }
        }
    }
    for info in game.mods() {
        println!("mod: {} ({})", info.label(), info.dir.display());
    }
    // The same entry-point rules `capture` uses: default boot (the TitleMap autorun
    // event and its three splashes), --menu-only for common event 42, --map-run for a
    // map script, --event for one common event, --load-save for a save file.
    let (started, label) = match entry {
        crate::Entry::Boot => (
            game.boot().map_err(|err| err.to_string()),
            "boot map".to_owned(),
        ),
        crate::Entry::Menu => (
            game.start_title().map_err(|err| err.to_string()),
            "common event 42".to_owned(),
        ),
        crate::Entry::MenuPrimed => {
            let primed = game.prime_engine();
            (
                game.start_title().map_err(|err| err.to_string()),
                format!("common event 42 after {primed} initialisation frame(s)"),
            )
        }
        crate::Entry::Script { map, event } => (
            game.start_map_event_by_name(map, event)
                .map_err(|err| err.to_string()),
            format!("map {map} event {event}"),
        ),
        crate::Entry::CommonEvent(id) => {
            game.start_engine_events();
            let started = if game.start_event(id) {
                Ok(())
            } else {
                Err(format!("no common event with id {id}"))
            };
            (started, format!("common event {id}"))
        }
        crate::Entry::Save(path) => {
            let label = format!("save {}", path.display());
            // CE48 initialises the live CData stat cells; if the load runs first the
            // deferred initialisation overwrites the restored action/stamina values.
            // Real boot finishes CE48 before the title menu, so prime it here as well.
            game.prime_engine();
            // A bare load only restores the screen and variables. The retail 220 path
            // has the save-menu coroutine continue and restart the map, which a CLI
            // entry has no equivalent of, so resume it explicitly from the snapshot.
            let started = game
                .load_save(path)
                .and_then(|_| game.resume_loaded_map())
                .map(|_| ())
                .map_err(|err| err.to_string());
            (started, label)
        }
    };
    if let Err(err) = started {
        eprintln!("{err}");
        return std::process::ExitCode::FAILURE;
    }

    println!("play: {label}");
    let event_loop = match EventLoop::new() {
        Ok(event_loop) => event_loop,
        Err(err) => {
            eprintln!("cannot create an event loop: {err}");
            return std::process::ExitCode::FAILURE;
        }
    };
    let mut app = App {
        game,
        root: root.to_path_buf(),
        atlas: Atlas::new(),
        sprites: Vec::new(),
        texts: Vec::new(),
        held: HashSet::new(),
        raw_held: Vec::new(),
        mouse: [-1, -1],
        mouse_buttons: 0,
        window: None,
        renderer: None,
        uploaded_revision: 0,
        frame_limit: frames,
        next_frame: Instant::now(),
        fps_frames: 0,
        fps_since: Instant::now(),
        fps: 0,
        display,
        debug_overlay: debug.overlay || !debug.vars.is_empty(),
        debug_vars: debug.vars,
        stats_overlay: debug.stats,
        backlog: false,
        backlog_scroll: 0,
        translation: translation.map(std::path::Path::to_path_buf),
        mods: mods.to_vec(),
        hotkeys,
    };
    if let Err(err) = event_loop.run_app(&mut app) {
        eprintln!("event loop failed: {err}");
        return std::process::ExitCode::FAILURE;
    }
    // The retail engine stores the global settings when the session ends. Only write when
    // CE132 actually changed a volume, so a session that never opened the settings screen
    // leaves Save/System.sav byte-identical.
    if app.game.settings_dirty() {
        match app.game.save_system_settings() {
            Ok(()) => println!("settings: saved to Save/System.sav"),
            Err(err) => eprintln!("settings: could not persist: {err}"),
        }
    }
    println!(
        "exit: {} frame(s), {} instruction(s), {} picture op(s), {} warning(s)",
        app.game.stats.frames,
        app.game.stats.instructions,
        app.game.stats.pictures,
        app.game.stats.warnings
    );
    if !app.game.diagnostics.is_empty() {
        println!("diagnostics seen while playing:");
        for (text, count) in app.game.diagnostics.iter().take(10) {
            println!("  {count:>6}x {text}");
        }
    }
    std::process::ExitCode::SUCCESS
}

struct App {
    game: Game,
    /// Data root the game was built from, kept so the restart key can rebuild the session.
    root: std::path::PathBuf,
    atlas: Atlas,
    sprites: Vec<SpriteInstance>,
    texts: Vec<TextQuad>,
    held: HashSet<u32>,
    /// WOLF keyboard key codes held right now, in press order (scancode + 100).
    ///
    /// The key-config screen (CE132) polls a raw keyboard key and stores it in
    /// Sys52..54, and the decide/cancel/sub bindings are those codes, so the app
    /// has to keep the physical keys as codes as well as as logical bits.
    raw_held: Vec<i32>,
    /// Mouse position in game pixels, or (-1, -1) while the cursor is outside the window.
    mouse: [i32; 2],
    /// WOLF mouse button bits: 1 left, 2 right, 4 middle.
    mouse_buttons: u32,
    window: Option<Arc<Window>>,
    renderer: Option<Renderer>,
    /// Atlas content revision at the last upload; a change means new artwork was
    /// packed or the page was reset and repacked.
    uploaded_revision: u64,
    /// Quit after this many frames (None = run until the window closes).
    frame_limit: Option<u64>,
    next_frame: Instant,
    fps_frames: u32,
    fps_since: Instant,
    /// Frames per second from the last completed one-second window.
    fps: u32,
    /// Window mode selected at startup and updated by the scale/fullscreen hotkeys.
    display: DisplayOptions,
    /// Whether the debug overlay is visible.
    debug_overlay: bool,
    /// Variables the overlay lists, in flat or magic address form.
    debug_vars: Vec<u32>,
    /// Whether the M5-C play-statistics / milestone overlay is visible.
    stats_overlay: bool,
    /// Whether the M5-F message transcript is open (backlog hotkey).
    backlog: bool,
    /// How many of the newest messages the transcript currently hides.
    backlog_scroll: usize,
    /// M5-D catalog path, re-applied when F12 rebuilds the session.
    translation: Option<std::path::PathBuf>,
    /// M5-E mod data overlay roots, re-applied when the restart key rebuilds.
    mods: Vec<std::path::PathBuf>,
    /// Rebindable simulator function keys (default mapping when no file is given).
    hotkeys: HotkeyConfig,
}

/// The primitive values the overlay renders, separated from `App` so the text can be
/// unit-tested without a window, GPU or data root.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
struct DebugSnapshot {
    frame: u64,
    fps: u32,
    instructions: u64,
    pictures: u64,
    warnings: u64,
    sprites: usize,
    texts: usize,
    pointer: [i32; 2],
    buttons: u32,
    key_bits: u32,
    last_action_event: Option<u32>,
    vars: Vec<(u32, i32)>,
}

fn debug_lines(snapshot: &DebugSnapshot) -> Vec<String> {
    let pointer = if snapshot.pointer[0] < 0 || snapshot.pointer[1] < 0 {
        "outside".to_owned()
    } else {
        format!("{},{}", snapshot.pointer[0], snapshot.pointer[1])
    };
    let event = snapshot
        .last_action_event
        .map_or_else(|| "none".to_owned(), |id| id.to_string());
    let mut lines = vec![
        format!(
            "debug | frame {} | {} fps | {} inst",
            snapshot.frame, snapshot.fps, snapshot.instructions
        ),
        format!(
            "pictures {} | warnings {} | sprites {} | texts {}",
            snapshot.pictures, snapshot.warnings, snapshot.sprites, snapshot.texts
        ),
        format!(
            "pointer {} | buttons {} | keys {:#06x}",
            pointer, snapshot.buttons, snapshot.key_bits
        ),
        format!("last action event {event}"),
    ];
    for (addr, value) in &snapshot.vars {
        lines.push(format!("v{addr} = {value}"));
    }
    lines
}

/// Lines and colours for the M5-C statistics overlay.
///
/// Kept separate from `App` so the layout can be tested without a Game, window or data
/// root. Unlocked milestones are green, locked ones grey; the summary rows stay white.
fn stats_lines(
    stats: &wolf_game::PlayStats,
    milestones: &[wolf_game::Milestone],
) -> Vec<(String, [u8; 3])> {
    const WHITE: [u8; 3] = [255, 255, 255];
    const GREEN: [u8; 3] = [120, 255, 160];
    const GREY: [u8; 3] = [180, 180, 180];
    let unlocked = milestones.iter().filter(|m| m.unlocked).count();
    let mut lines = vec![
        (
            format!(
                "统计 | 天数 {} | 信赖 {} | 兴致 {} | 感度 {} | 心情 {} | 警戒 {}",
                stats.days, stats.trust, stats.interest, stats.sensitivity, stats.mood, stats.alert
            ),
            WHITE,
        ),
        (
            format!(
                "共同经历 {} | 成就 {}/{}",
                stats.interactions,
                unlocked,
                milestones.len()
            ),
            WHITE,
        ),
    ];
    for milestone in milestones {
        lines.push((
            format!(
                "[{}] {} - {}",
                if milestone.unlocked { "x" } else { " " },
                milestone.title,
                milestone.detail
            ),
            if milestone.unlocked { GREEN } else { GREY },
        ));
    }
    lines
}

impl App {
    fn bits(&self) -> u32 {
        let mut bits = self.held.iter().copied().fold(0, |acc, bit| acc | bit);
        // CE132 edits the three keyboard bindings live in Sys52..54; the shipped
        // System.sav holds Z/X/C (144/145/146). Enter and Backspace stay as the
        // manual's fixed aliases (manual01: 決定 Enter・Z・left click,
        // キャンセル backspace・X・right click).
        let config = self.game.live_settings().key_config;
        for code in &self.raw_held {
            let code = *code as u32;
            if code == config[0] || code == WOLF_ENTER {
                bits |= key::OK;
            }
            if code == config[2] || code == WOLF_BACKSPACE {
                bits |= key::CANCEL;
            }
            if code == config[4] {
                bits |= key::SUB;
            }
        }
        bits
    }

    /// Advances one frame: latch input, run the script, rebuild the draw list.
    fn step(&mut self) {
        self.game.key_bits = self.bits();
        self.game.raw_keys.clear();
        self.game.raw_keys.extend_from_slice(&self.raw_held);
        self.game.mouse = self.mouse;
        self.game.mouse_buttons = self.mouse_buttons;
        let outcome = self.game.frame();
        if outcome.idle && !self.game.screen.is_empty() {
            // Nothing is running any more: keep presenting the last frame rather than
            // tearing the window down, so the capture stays inspectable.
        }
        self.rebuild();
    }

    /// Restart the session (default hotkey F12; the retail `Game.ini` ships
    /// `F12_Reset=1`).
    ///
    /// Rebuilds the whole `Game` from the data root and boots it into the title map,
    /// exactly like starting `play` afresh, without tearing down the window, the
    /// renderer or the packed atlas. The retail engine resets the running game rather
    /// than relaunching the executable, so this keeps the same session window.
    ///
    /// On failure the current session is left untouched and the error is printed:
    /// a broken restart must not take the window down with it.
    fn restart(&mut self) {
        let root = self.root.clone();
        let mut game = match Game::with_overlays(&root, self.mods.clone()) {
            Ok(game) => game,
            Err(err) => {
                eprintln!("restart failed (cannot reload the game data): {err}");
                return;
            }
        };
        if crate::AUDIO.load(std::sync::atomic::Ordering::Relaxed) {
            game.enable_audio();
        }
        game.apply_settings();
        crate::install_font_metrics(&mut game, &root);
        if let Some(path) = &self.translation {
            if let Err(err) = game.load_translation_file(path) {
                eprintln!("restart failed (translation): {err}");
                return;
            }
        }
        if let Err(err) = game.boot() {
            eprintln!("restart failed (boot): {err}");
            return;
        }
        // The atlas is keyed by asset path, and a restart reads the same data root, so the
        // packed images stay valid. Only the transient state belongs to the old session.
        self.game = game;
        self.held.clear();
        self.raw_held.clear();
        self.mouse_buttons = 0;
        self.backlog = false;
        self.backlog_scroll = 0;
        self.step();
        if let Some(renderer) = self.renderer.as_ref() {
            self.refresh_title(renderer);
        }
        println!("restart: rebooted the title map");
    }

    /// Rebuilds the draw list: script pictures, the runtime choice panel, and text.
    ///
    /// The panel is appended last so it composites over every script layer, which is
    /// what the engine does: a choice prompt is an engine overlay, not a picture slot.
    fn rebuild(&mut self) {
        // A page that filled on a previous frame is dropped before the visible set is
        // packed again (see Atlas::begin_frame).
        self.atlas.begin_frame();
        // The registered maps paint their tiles from the WOLF editor's stock sample chips
        // (green ground / beige patch), and every frame is in practice repainted by a
        // full-screen CG or `cg/blackscreen.jpg`. Those chips are placeholder art the
        // retail game never shows, so the live window composites only the picture layer:
        // an uncovered moment (title fade-in, map switch) falls back to the renderer's
        // black clear instead of flashing green/beige placeholder tiles.
        let quads = self.game.picture_quads(&mut self.atlas);
        let mut sprites: Vec<SpriteInstance> = quads.iter().map(Self::tint_instance).collect();
        let mut texts = self.game.text_quads();
        if let Some(choices) = &self.game.choices {
            let options = choices.options.clone();
            let cursor = self.game.choice_cursor();
            let (x, y) = self.game.choice_anchor();
            // Sys8 sizes the option text, so the panel is measured at the size it is drawn.
            let font_px = self.game.font_px();
            if let Some((panel, rows)) = choice::overlay_at_sized(
                &mut self.atlas,
                &mut self.game.assets,
                &options,
                cursor,
                x,
                y,
                font_px,
            ) {
                sprites.extend(panel.iter().map(Self::tint_instance));
                texts.extend(rows);
            }
        }
        // The engine draws the 101 pause cursor itself (SystemFile/Text_Pause.png, six 17x15
        // frames), so it joins the sprite list rather than the glyph list.
        let newest = self.game.messages.last().map(|m| m.frames);
        if let Some(frames) = newest {
            let Some(layout) = self.game.message_layout() else {
                unreachable!("the newest message has a layout");
            };
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
                if let Some(quad) = self.atlas.sprite_from(
                    &mut self.game.assets,
                    wolf_game::message::CURSOR_FILE,
                    wolf_game::message::CURSOR_SLOT,
                    src,
                    dst,
                    1.0,
                ) {
                    sprites.push(Self::tint_instance(&quad));
                }
            }
        }
        self.sprites = sprites;
        self.texts = texts;
        for warning in self.atlas.take_warnings() {
            *self.game.diagnostics.entry(warning).or_insert(0) += 1;
        }
    }

    /// Builds a render instance from an atlas quad, carrying its alpha and its picture tone.
    ///
    /// The tone is per picture, not per frame: a 290 flash changes what one picture
    /// multiplies its texels by while everything else on screen keeps drawing at full
    /// brightness, so it has to ride on the instance rather than on a global draw state.
    fn tint_instance(quad: &wolf_game::atlas::SpriteQuad) -> SpriteInstance {
        SpriteInstance::new(quad.rect, quad.uv)
            .with_alpha(quad.alpha)
            .with_tint_rgb(quad.tint[0], quad.tint[1], quad.tint[2])
    }

    fn build_text_items(&self) -> Vec<TextItem> {
        // The transcript is a modal read-only page: while it is open the script keeps
        // running, but its glyphs are hidden so the two text layers cannot overlap.
        if self.backlog {
            let (header, body) = backlog_view(self.game.message_history(), self.backlog_scroll);
            return vec![
                TextItem::new(header, [8.0, 8.0, 1008.0, 20.0], 16.0)
                    .with_colour([255, 224, 140])
                    .with_outline(2, [0, 0, 0]),
                TextItem::new(body, [8.0, 34.0, 1008.0, 520.0], 16.0)
                    .with_colour([255, 255, 255])
                    .with_outline(2, [0, 0, 0]),
            ];
        }
        let mut items: Vec<TextItem> = self
            .texts
            .iter()
            .map(|text| {
                let size = if text.font_px > 0.0 {
                    text.font_px
                } else {
                    self.game.font_px()
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
        // A 101 message is engine text, not a picture: the frame comes from common event 63
        // as ordinary pictures, the glyphs come from the message layout. Only the newest
        // message is on screen, which is the order the interpreter produces.
        if let Some(layout) = self.game.message_layout() {
            for run in &layout.runs {
                // One em of slack keeps cosmic-text from wrapping the last glyph: the
                // layout measures with the half-em rule, the shaper uses the real advance.
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
        let mut overlay_row = 0usize;
        if self.debug_overlay {
            let watch: Vec<(u32, i32)> = self
                .debug_vars
                .iter()
                .map(|addr| (*addr, self.game.vm.vars.get(debug_slot(*addr))))
                .collect();
            let snapshot = DebugSnapshot {
                frame: self.game.stats.frames,
                fps: self.fps,
                instructions: self.game.stats.instructions,
                pictures: self.game.stats.pictures,
                warnings: self.game.stats.warnings,
                sprites: self.sprites.len(),
                texts: self.texts.len(),
                pointer: self.mouse,
                buttons: self.mouse_buttons,
                key_bits: self.bits(),
                last_action_event: self.game.last_action_event,
                vars: watch,
            };
            for text in debug_lines(&snapshot) {
                let y = 8.0 + overlay_row as f32 * 18.0;
                overlay_row += 1;
                let item = TextItem::new(text, [8.0, y, 1000.0, 20.0], 16.0)
                    .with_colour([255, 255, 255])
                    .with_outline(2, [0, 0, 0]);
                items.push(item);
            }
        }
        if self.stats_overlay {
            if overlay_row > 0 {
                overlay_row += 1;
            }
            let stats = self.game.play_stats();
            let milestones = self.game.milestones();
            for (text, colour) in stats_lines(&stats, &milestones) {
                let y = 8.0 + overlay_row as f32 * 18.0;
                overlay_row += 1;
                let item = TextItem::new(text, [8.0, y, 1000.0, 20.0], 16.0)
                    .with_colour(colour)
                    .with_outline(2, [0, 0, 0]);
                items.push(item);
            }
        }
        items
    }

    fn upload_if_needed(&mut self, renderer: &mut Renderer) {
        if self.atlas.revision() == self.uploaded_revision {
            return;
        }
        let [width, height] = self.atlas.size();
        // The atlas is sent to the GPU only when the packed image set changes, so a steady
        // screen costs one instance-buffer write per frame and zero texture uploads.
        if renderer
            .set_atlas(self.atlas.pixels(), width, height)
            .is_ok()
        {
            self.uploaded_revision = self.atlas.revision();
        }
    }

    fn refresh_title(&self, renderer: &Renderer) {
        let Some(window) = self.window.as_ref() else {
            return;
        };
        let mode = renderer.scale_mode();
        let scale = if mode == ScaleMode::Integer {
            format!("{}x", renderer.scaler().scale)
        } else {
            format!("{:.3}x {}", renderer.scale_factor(), mode.label())
        };
        let text_count = self.game.text_quads().len();
        window.set_title(&format!(
            "imoto-life | {}x{} -> {} | {} | frame {} | {} quad(s){} | {} fps",
            LOGICAL_W,
            LOGICAL_H,
            scale,
            if self.display.fullscreen {
                "fullscreen"
            } else {
                "windowed"
            },
            self.game.stats.frames,
            self.sprites.len(),
            if text_count > 0 { ", text pending" } else { "" },
            self.fps
        ));
    }
}

impl ApplicationHandler for App {
    fn resumed(&mut self, event_loop: &ActiveEventLoop) {
        let mut attributes = Window::default_attributes().with_title("imoto-life | title screen");
        if self.display.fullscreen {
            attributes = attributes.with_fullscreen(Some(Fullscreen::Borderless(None)));
        } else {
            attributes = attributes.with_inner_size(window_size_for(
                event_loop.primary_monitor().map(|monitor| monitor.size()),
            ));
        }
        let window = match event_loop.create_window(attributes) {
            Ok(window) => Arc::new(window),
            Err(err) => {
                eprintln!("could not create a window: {err}");
                event_loop.exit();
                return;
            }
        };
        // Render the first frame before the window is even shown, so the user never sees
        // an empty (black) frame before the title art appears.
        self.step();
        let mut renderer = match Renderer::new(window.clone()) {
            Ok(renderer) => renderer,
            Err(err) => {
                eprintln!("renderer init failed: {err}");
                event_loop.exit();
                return;
            }
        };
        renderer.set_scale_mode(self.display.mode);
        let info = renderer.adapter_info();
        println!(
            "play: {} ({:?}, backend {:?}) | {}x{} logical | scale {} | fullscreen {}",
            info.name,
            info.device_type,
            info.backend,
            LOGICAL_W,
            LOGICAL_H,
            self.display.mode.label(),
            self.display.fullscreen
        );
        self.upload_if_needed(&mut renderer);
        // The original game keeps its TTFs next to Game.exe, and the font covers the
        // Chinese patch text that the bitmap font would render as boxes.
        match crate::find_font(self.game.root()) {
            Some((path, bytes)) => match renderer.set_font(&bytes) {
                Ok(()) => {
                    println!("font: {}", path.display());
                    crate::install_font_fallbacks(&mut renderer, &path);
                }
                Err(err) => eprintln!("font rejected ({}): {err}", path.display()),
            },
            None => eprintln!("no font found; text will not be drawn"),
        }
        renderer.draw(&self.sprites);
        let items = self.build_text_items();
        renderer.draw_text(&items);
        renderer.set_overlays(&crate::render_overlays(&self.game));
        self.window = Some(window);
        self.renderer = Some(renderer);
        self.next_frame = Instant::now() + FRAME_TIME;
    }

    fn window_event(&mut self, event_loop: &ActiveEventLoop, _id: WindowId, event: WindowEvent) {
        match event {
            WindowEvent::CloseRequested => event_loop.exit(),
            WindowEvent::KeyboardInput { event, .. } => {
                let bit = fixed_bit(event.physical_key);
                let raw = raw_key_code(event.physical_key);
                if event.state == ElementState::Pressed {
                    if self.hotkeys.is_quit(&event.logical_key) {
                        event_loop.exit();
                        return;
                    }
                    // The scale hotkey cycles integer -> fit-nearest -> fit-linear; the
                    // fullscreen hotkey toggles a borderless window. Both are M5
                    // presentation controls with rebindable keys.
                    if self.hotkeys.is_scale(&event.logical_key) {
                        if !event.repeat {
                            self.display.mode = self.display.mode.next();
                            if let Some(renderer) = self.renderer.as_mut() {
                                renderer.set_scale_mode(self.display.mode);
                            }
                            if let Some(renderer) = self.renderer.as_ref() {
                                self.refresh_title(renderer);
                            }
                            println!("display: scale mode {}", self.display.mode.label());
                        }
                        return;
                    }
                    if self.hotkeys.is_fullscreen(&event.logical_key) {
                        if !event.repeat {
                            self.display.fullscreen = !self.display.fullscreen;
                            if let Some(window) = self.window.as_ref() {
                                window.set_fullscreen(if self.display.fullscreen {
                                    Some(Fullscreen::Borderless(None))
                                } else {
                                    None
                                });
                            }
                            if let Some(renderer) = self.renderer.as_ref() {
                                self.refresh_title(renderer);
                            }
                            println!("display: fullscreen {}", self.display.fullscreen);
                        }
                        return;
                    }
                    // The statistics hotkey toggles the M5-C statistics/milestone overlay.
                    if self.hotkeys.is_stats(&event.logical_key) {
                        if !event.repeat {
                            self.stats_overlay = !self.stats_overlay;
                            println!("stats: overlay {}", self.stats_overlay);
                        }
                        return;
                    }
                    // The debug hotkey toggles the M5-B debug overlay. It is an ordinary
                    // text overlay, not a separate UI, so it rides the same glyph pass.
                    if self.hotkeys.is_debug(&event.logical_key) {
                        if !event.repeat {
                            self.debug_overlay = !self.debug_overlay;
                            println!("debug: overlay {}", self.debug_overlay);
                        }
                        return;
                    }
                    // The backlog hotkey opens the M5-F transcript. It is a read-only
                    // overlay: the script keeps running underneath, and the ordinary
                    // game keys are not consumed while it is closed.
                    if self.hotkeys.is_backlog(&event.logical_key) {
                        if !event.repeat {
                            self.backlog = !self.backlog;
                            self.backlog_scroll = 0;
                            // A modal page must not leak held keys/buttons into the
                            // script that keeps running underneath it.
                            self.held.clear();
                            self.raw_held.clear();
                            self.mouse_buttons = 0;
                            println!("backlog: overlay {}", self.backlog);
                        }
                        return;
                    }
                    if self.backlog
                        && matches!(
                            event.logical_key,
                            Key::Named(NamedKey::PageUp | NamedKey::PageDown)
                        )
                    {
                        let total = self.game.message_history().len();
                        let oldest = total.saturating_sub(BACKLOG_ROWS);
                        if matches!(event.logical_key, Key::Named(NamedKey::PageUp)) {
                            self.backlog_scroll = (self.backlog_scroll + BACKLOG_ROWS).min(oldest);
                        } else {
                            self.backlog_scroll = self.backlog_scroll.saturating_sub(BACKLOG_ROWS);
                        }
                        return;
                    }
                    // The restart key (default F12) restarts the game. Ignore auto-repeat
                    // so a held key cannot reload the data root dozens of times a second.
                    if self.hotkeys.is_restart(&event.logical_key) {
                        if !event.repeat {
                            self.restart();
                        }
                        return;
                    }
                    if self.backlog {
                        return;
                    }
                    if let Some(bit) = bit {
                        self.held.insert(bit);
                    }
                    if let Some(code) = raw {
                        if !self.raw_held.contains(&code) {
                            self.raw_held.push(code);
                        }
                    }
                } else {
                    if let Some(bit) = bit {
                        self.held.remove(&bit);
                    }
                    if let Some(code) = raw {
                        self.raw_held.retain(|held| *held != code);
                    }
                }
            }
            WindowEvent::CursorMoved { position, .. } => {
                // winit reports physical pixels; the scaler maps them back onto the
                // 1024x576 grid the game draws in, so the pointer lands where the
                // player sees it even with letterboxing or an integer upscale.
                if let Some(renderer) = self.renderer.as_ref() {
                    self.mouse = renderer.window_to_game(position.x, position.y);
                }
            }
            WindowEvent::CursorLeft { .. } => {
                self.mouse = [-1, -1];
                self.mouse_buttons = 0;
            }
            WindowEvent::MouseInput { state, button, .. } => {
                if self.backlog {
                    return;
                }
                let bit = match button {
                    MouseButton::Left => 1,
                    MouseButton::Right => 2,
                    MouseButton::Middle => 4,
                    MouseButton::Back | MouseButton::Forward | MouseButton::Other(_) => 0,
                };
                if bit != 0 {
                    if state == ElementState::Pressed {
                        self.mouse_buttons |= bit;
                    } else {
                        self.mouse_buttons &= !bit;
                    }
                }
            }
            WindowEvent::Resized(size) => {
                // Taking the renderer out of the struct keeps the borrow checker happy while
                // the title bar needs fields from both sides.
                if let Some(mut renderer) = self.renderer.take() {
                    renderer.resize(size);
                    self.refresh_title(&renderer);
                    self.renderer = Some(renderer);
                }
            }
            WindowEvent::RedrawRequested => {
                if let Some(mut renderer) = self.renderer.take() {
                    self.upload_if_needed(&mut renderer);
                    // 161 PrepareTransition: the frame texture still holds the previously
                    // presented frame, so freeze it before this frame's pass clears it.
                    if self.game.take_freeze_request() {
                        renderer.freeze();
                    }
                    renderer.draw(&self.sprites);
                    let items = self.build_text_items();
                    renderer.draw_text(&items);
                    // Overlays are replaced every frame: a flash or dissolve that ended
                    // must stop drawing, and a frozen frame stays only while it is listed.
                    renderer.set_overlays(&crate::render_overlays(&self.game));
                    renderer.present();
                    self.renderer = Some(renderer);
                }
            }
            _ => {}
        }
    }

    fn about_to_wait(&mut self, event_loop: &ActiveEventLoop) {
        let now = Instant::now();
        if now >= self.next_frame {
            // Catch up at most a few frames if the machine hiccupped; a long stall should
            // not turn into a burst of fast-forwarded script execution.
            let behind = now.duration_since(self.next_frame);
            self.next_frame += FRAME_TIME;
            if behind > FRAME_TIME * 4 {
                self.next_frame = now + FRAME_TIME;
            }
            self.step();
            // Opcode 175 (the title's おわる option) asks the process to exit. The
            // window owns the event loop, so poll the flag here rather than calling
            // exit() from inside the VM.
            if self.game.quit_requested {
                event_loop.exit();
                return;
            }
            if self
                .frame_limit
                .is_some_and(|limit| self.game.stats.frames >= limit)
            {
                println!(
                    "reached the frame limit after {} frame(s)",
                    self.game.stats.frames
                );
                event_loop.exit();
                return;
            }
            self.fps_frames += 1;
            if self.fps_since.elapsed() >= Duration::from_secs(1) {
                self.fps = self.fps_frames;
                if let Some(renderer) = self.renderer.as_ref() {
                    self.refresh_title(renderer);
                }
                self.fps_frames = 0;
                self.fps_since = Instant::now();
            }
            if let Some(window) = self.window.as_ref() {
                window.request_redraw();
            }
        }
        event_loop.set_control_flow(ControlFlow::WaitUntil(self.next_frame));
    }
}

/// Maps one physical key onto WOLF's key bits (crates/wolf-game/src/key.rs).
///
/// Several physical keys share a bit on purpose: the original game honours Enter/Z/Space
/// for confirm and Escape/X for cancel, and a port that only accepted one of them would
/// feel broken to anyone used to the original.
/// Keys that always carry a logical meaning, independent of the player's config.
///
/// manual01 lists 決定 = Enter / Z / left click and キャンセル = backspace / X /
/// right click, so Enter and Backspace stay fixed while Z and X come from the
/// configurable Sys52..54 (shipped defaults 144/145/146). The arrow keys are not
/// configurable in this game; Escape is a port alias for Backspace.
fn fixed_bit(code: winit::keyboard::PhysicalKey) -> Option<u32> {
    use winit::keyboard::KeyCode as K;
    let winit::keyboard::PhysicalKey::Code(code) = code else {
        return None;
    };
    match code {
        K::ArrowUp => Some(key::UP),
        K::ArrowDown => Some(key::DOWN),
        K::ArrowLeft => Some(key::LEFT),
        K::ArrowRight => Some(key::RIGHT),
        K::Enter => Some(key::OK),
        K::Backspace | K::Escape => Some(key::CANCEL),
        _ => None,
    }
}

/// WOLF key codes for the fixed aliases above (scancode + 100).
const WOLF_ENTER: u32 = 128;
const WOLF_BACKSPACE: u32 = 114;

/// The WOLF key code of a physical key, in DirectInput scancode + 100 encoding.
///
/// Only the keys a player can actually bind need an entry; the game's own defaults
/// (Z = 144, X = 145, C = 146) pin the encoding. `None` means "this key has no code
/// we can express", and the key-config screen simply will not capture it.
fn raw_key_code(code: winit::keyboard::PhysicalKey) -> Option<i32> {
    use winit::keyboard::KeyCode as K;
    let winit::keyboard::PhysicalKey::Code(code) = code else {
        return None;
    };
    let scancode: u8 = match code {
        K::Escape => 0x01,
        K::Digit1 => 0x02,
        K::Digit2 => 0x03,
        K::Digit3 => 0x04,
        K::Digit4 => 0x05,
        K::Digit5 => 0x06,
        K::Digit6 => 0x07,
        K::Digit7 => 0x08,
        K::Digit8 => 0x09,
        K::Digit9 => 0x0A,
        K::Digit0 => 0x0B,
        K::Minus => 0x0C,
        K::Equal => 0x0D,
        K::Backspace => 0x0E,
        K::Tab => 0x0F,
        K::KeyQ => 0x10,
        K::KeyW => 0x11,
        K::KeyE => 0x12,
        K::KeyR => 0x13,
        K::KeyT => 0x14,
        K::KeyY => 0x15,
        K::KeyU => 0x16,
        K::KeyI => 0x17,
        K::KeyO => 0x18,
        K::KeyP => 0x19,
        K::BracketLeft => 0x1A,
        K::BracketRight => 0x1B,
        K::Enter => 0x1C,
        K::ControlLeft => 0x1D,
        K::KeyA => 0x1E,
        K::KeyS => 0x1F,
        K::KeyD => 0x20,
        K::KeyF => 0x21,
        K::KeyG => 0x22,
        K::KeyH => 0x23,
        K::KeyJ => 0x24,
        K::KeyK => 0x25,
        K::KeyL => 0x26,
        K::Semicolon => 0x27,
        K::Quote => 0x28,
        K::Backquote => 0x29,
        K::ShiftLeft => 0x2A,
        K::Backslash => 0x2B,
        K::KeyZ => 0x2C,
        K::KeyX => 0x2D,
        K::KeyC => 0x2E,
        K::KeyV => 0x2F,
        K::KeyB => 0x30,
        K::KeyN => 0x31,
        K::KeyM => 0x32,
        K::Comma => 0x33,
        K::Period => 0x34,
        K::Slash => 0x35,
        K::ShiftRight => 0x36,
        K::NumpadMultiply => 0x37,
        K::AltLeft => 0x38,
        K::Space => 0x39,
        K::CapsLock => 0x3A,
        K::F1 => 0x3B,
        K::F2 => 0x3C,
        K::F3 => 0x3D,
        K::F4 => 0x3E,
        K::F5 => 0x3F,
        K::F6 => 0x40,
        K::F7 => 0x41,
        K::F8 => 0x42,
        K::F9 => 0x43,
        K::F10 => 0x44,
        K::NumLock => 0x45,
        K::ScrollLock => 0x46,
        K::Numpad7 => 0x47,
        K::Numpad8 => 0x48,
        K::Numpad9 => 0x49,
        K::NumpadSubtract => 0x4A,
        K::Numpad4 => 0x4B,
        K::Numpad5 => 0x4C,
        K::Numpad6 => 0x4D,
        K::NumpadAdd => 0x4E,
        K::Numpad1 => 0x4F,
        K::Numpad2 => 0x50,
        K::Numpad3 => 0x51,
        K::Numpad0 => 0x52,
        K::NumpadDecimal => 0x53,
        K::F11 => 0x57,
        K::F12 => 0x58,
        // Extended (E0-prefixed) keys use the same make code in set 1.
        K::ArrowUp => 0x48,
        K::ArrowDown => 0x50,
        K::ArrowLeft => 0x4B,
        K::ArrowRight => 0x4D,
        K::Insert => 0x52,
        K::Delete => 0x53,
        K::Home => 0x47,
        K::End => 0x4F,
        K::PageUp => 0x49,
        K::PageDown => 0x51,
        _ => return None,
    };
    Some(key::keyboard_code(scancode))
}

#[cfg(test)]
mod tests {
    use super::{
        backlog_view, debug_lines, debug_slot, parse_debug_vars, stats_lines, DebugSnapshot,
        BACKLOG_ROWS,
    };
    use crate::hotkeys::HotkeyConfig;
    use winit::keyboard::{Key, NamedKey};
    use wolf_game::Message;

    /// manual01/F12_Reset: only F12 restarts; F10 stays the quit key and the ordinary
    /// gameplay keys must never trigger a reload.
    #[test]
    fn debug_overlay_reports_frame_pointer_and_watched_vars() {
        let snapshot = DebugSnapshot {
            frame: 120,
            fps: 59,
            instructions: 3456,
            pictures: 7,
            warnings: 1,
            sprites: 12,
            texts: 3,
            pointer: [100, 200],
            buttons: 1,
            key_bits: 0x20,
            last_action_event: Some(21),
            vars: vec![(154, 7), (2_000_350, 2)],
        };
        let lines = debug_lines(&snapshot);
        assert_eq!(lines[0], "debug | frame 120 | 59 fps | 3456 inst");
        assert_eq!(lines[1], "pictures 7 | warnings 1 | sprites 12 | texts 3");
        assert_eq!(lines[2], "pointer 100,200 | buttons 1 | keys 0x0020");
        assert_eq!(lines[3], "last action event 21");
        assert_eq!(lines[4], "v154 = 7");
        assert_eq!(lines[5], "v2000350 = 2");
    }

    #[test]
    fn debug_overlay_marks_an_outside_pointer_and_no_event() {
        let snapshot = DebugSnapshot {
            pointer: [-1, -1],
            ..DebugSnapshot::default()
        };
        let lines = debug_lines(&snapshot);
        assert_eq!(lines[2], "pointer outside | buttons 0 | keys 0x0000");
        assert_eq!(lines[3], "last action event none");
    }

    #[test]
    fn parse_debug_vars_accepts_commas_and_rejects_garbage() {
        assert_eq!(
            parse_debug_vars("154, 155,, 2000350").unwrap(),
            vec![154, 155, 2_000_350]
        );
        assert!(parse_debug_vars("").unwrap().is_empty());
        assert!(parse_debug_vars("154,nope").is_err());
    }

    #[test]
    fn debug_slot_accepts_flat_and_magic_addresses() {
        assert_eq!(debug_slot(350), 350);
        assert_eq!(debug_slot(2_000_350), 350);
        assert_eq!(debug_slot(154), 154);
    }

    #[test]
    fn stats_overlay_reports_progress_and_milestones() {
        let stats = wolf_game::PlayStats {
            days: 31,
            trust: 210,
            interest: 45,
            sensitivity: 3,
            mood: 2,
            alert: 6,
            interactions: 12,
            cleared: false,
            hundred_days: false,
            pants_complete: true,
        };
        let milestones = vec![
            wolf_game::Milestone {
                id: "days_10",
                title: "十日同行",
                detail: "在一起生活满 10 天",
                unlocked: true,
            },
            wolf_game::Milestone {
                id: "days_100",
                title: "百日纪念",
                detail: "在一起生活满 100 天",
                unlocked: false,
            },
        ];
        let lines = stats_lines(&stats, &milestones);
        assert_eq!(
            lines[0].0,
            "统计 | 天数 31 | 信赖 210 | 兴致 45 | 感度 3 | 心情 2 | 警戒 6"
        );
        assert_eq!(lines[1].0, "共同经历 12 | 成就 1/2");
        assert_eq!(lines[2].0, "[x] 十日同行 - 在一起生活满 10 天");
        assert_eq!(lines[2].1, [120, 255, 160]);
        assert_eq!(lines[3].0, "[ ] 百日纪念 - 在一起生活满 100 天");
        assert_eq!(lines[3].1, [180, 180, 180]);
    }

    fn transcript(count: usize) -> Vec<Message> {
        (0..count)
            .map(|index| Message {
                text: format!("line {index}"),
                face: None,
                frames: 0,
            })
            .collect()
    }

    #[test]
    fn an_empty_transcript_says_so() {
        let (header, body) = backlog_view(&[], 0);
        assert_eq!(header, "消息回顾 | 暂无消息 | F4 关闭");
        assert!(body.is_empty());
    }

    #[test]
    fn the_transcript_shows_the_newest_page_and_scrolls_back() {
        let history = transcript(BACKLOG_ROWS + 7);
        let (header, body) = backlog_view(&history, 0);
        assert_eq!(
            header,
            format!(
                "消息回顾 | 8-{} / {} | PgUp/PgDn 滚动 | F4 关闭",
                history.len(),
                history.len()
            )
        );
        let lines: Vec<&str> = body.lines().collect();
        assert_eq!(lines.len(), BACKLOG_ROWS);
        assert_eq!(lines[0], "line 7");
        assert_eq!(
            lines[BACKLOG_ROWS - 1],
            format!("line {}", history.len() - 1)
        );

        let (header, body) = backlog_view(&history, BACKLOG_ROWS);
        assert_eq!(
            header,
            format!(
                "消息回顾 | 1-{} / {} | PgUp/PgDn 滚动 | F4 关闭",
                BACKLOG_ROWS,
                history.len()
            )
        );
        assert_eq!(body.lines().next(), Some("line 0"));
        // Scrolling past the oldest page clamps instead of showing an empty panel.
        assert_eq!(backlog_view(&history, 999).0, header);
    }

    #[test]
    fn the_restart_key_defaults_to_f12_and_follows_the_config() {
        let config = HotkeyConfig::default();
        assert!(config.is_restart(&Key::Named(NamedKey::F12)));
        for key in [
            Key::Named(NamedKey::F10),
            Key::Named(NamedKey::F11),
            Key::Named(NamedKey::Escape),
            Key::Named(NamedKey::Enter),
            Key::Character("z".into()),
        ] {
            assert!(
                !config.is_restart(&key),
                "{key:?} must not restart by default"
            );
        }
        // Rebinding the restart action moves it off F12 entirely.
        let (custom, errors) = HotkeyConfig::parse("restart = F5\n");
        assert!(errors.is_empty(), "{errors:?}");
        assert!(custom.is_restart(&Key::Named(NamedKey::F5)));
        assert!(!custom.is_restart(&Key::Named(NamedKey::F12)));
    }
}
