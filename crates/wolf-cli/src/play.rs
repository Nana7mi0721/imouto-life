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
//! The window is 1024x576 logical pixels scaled by the largest whole integer factor that
//! fits (with black bars), so a 1920x1080 desktop shows a crisp 1:1 or 1.875x image
//! instead of a blurry fractional upscale - see `wolf_render::Scaler`.

use std::collections::HashSet;
use std::sync::Arc;
use std::time::{Duration, Instant};

use winit::application::ApplicationHandler;
use winit::dpi::PhysicalSize;
use winit::event::{ElementState, MouseButton, WindowEvent};
use winit::event_loop::{ActiveEventLoop, ControlFlow, EventLoop};
use winit::keyboard::{Key, NamedKey};
use winit::window::{Window, WindowId};

use wolf_game::atlas::{Atlas, TextQuad};
use wolf_game::{choice, key, Game};
use wolf_render::{Renderer, Scaler, SpriteInstance, TextItem, LOGICAL_H, LOGICAL_W};

/// One frame at 60 Hz.
const FRAME_TIME: Duration = Duration::from_micros(16_667);

/// Runs the title screen in a window until the user closes it (or `frames` pass).
///
/// A non-zero frame budget makes the window self-closing, which is how the interactive
/// path gets smoke-tested: the same code that a player drives also has to survive an
/// unattended run without panicking or wedging the event loop.
pub fn run(
    root: &std::path::Path,
    frames: Option<u64>,
    entry: crate::Entry<'_>,
) -> std::process::ExitCode {
    let mut game = match Game::new(root) {
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
        mouse: [-1, -1],
        mouse_buttons: 0,
        window: None,
        renderer: None,
        uploaded_images: usize::MAX,
        frame_limit: frames,
        next_frame: Instant::now(),
        fps_frames: 0,
        fps_since: Instant::now(),
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
    /// Data root the game was built from, kept so F12 can rebuild the session in place.
    root: std::path::PathBuf,
    atlas: Atlas,
    sprites: Vec<SpriteInstance>,
    texts: Vec<TextQuad>,
    held: HashSet<u32>,
    /// Mouse position in game pixels, or (-1, -1) while the cursor is outside the window.
    mouse: [i32; 2],
    /// WOLF mouse button bits: 1 left, 2 right, 4 middle.
    mouse_buttons: u32,
    window: Option<Arc<Window>>,
    renderer: Option<Renderer>,
    /// Atlas image count at the last upload; a change means new artwork was packed.
    uploaded_images: usize,
    /// Quit after this many frames (None = run until the window closes).
    frame_limit: Option<u64>,
    next_frame: Instant,
    fps_frames: u32,
    fps_since: Instant,
}

impl App {
    fn bits(&self) -> u32 {
        self.held.iter().copied().fold(0, |acc, bit| acc | bit)
    }

    /// Advances one frame: latch input, run the script, rebuild the draw list.
    fn step(&mut self) {
        self.game.key_bits = self.bits();
        self.game.mouse = self.mouse;
        self.game.mouse_buttons = self.mouse_buttons;
        let outcome = self.game.frame();
        if outcome.idle && !self.game.screen.is_empty() {
            // Nothing is running any more: keep presenting the last frame rather than
            // tearing the window down, so the capture stays inspectable.
        }
        self.rebuild();
    }

    /// F12 = restart (manual01, `F12_Reset=1` in Game.ini).
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
        let mut game = match Game::new(&root) {
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
        if let Err(err) = game.boot() {
            eprintln!("restart failed (boot): {err}");
            return;
        }
        // The atlas is keyed by asset path, and a restart reads the same data root, so the
        // packed images stay valid. Only the transient state belongs to the old session.
        self.game = game;
        self.held.clear();
        self.mouse_buttons = 0;
        self.step();
        if let Some(renderer) = self.renderer.as_ref() {
            self.refresh_title(renderer);
        }
        println!("restart: F12 booted the title map again");
    }

    /// Rebuilds the draw list: script pictures, the runtime choice panel, and text.
    ///
    /// The panel is appended last so it composites over every script layer, which is
    /// what the engine does: a choice prompt is an engine overlay, not a picture slot.
    fn rebuild(&mut self) {
        let mut quads = self.game.tile_quads(&mut self.atlas);
        quads.extend(self.game.picture_quads(&mut self.atlas));
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
        items
    }

    fn upload_if_needed(&mut self, renderer: &mut Renderer) {
        if self.atlas.len() == self.uploaded_images {
            return;
        }
        let [width, height] = self.atlas.size();
        // The atlas is sent to the GPU only when the packed image set changes, so a steady
        // screen costs one instance-buffer write per frame and zero texture uploads.
        if renderer
            .set_atlas(self.atlas.pixels(), width, height)
            .is_ok()
        {
            self.uploaded_images = self.atlas.len();
        }
    }

    fn refresh_title(&self, renderer: &Renderer) {
        let Some(window) = self.window.as_ref() else {
            return;
        };
        let scaler = renderer.scaler();
        let text_count = self.game.text_quads().len();
        window.set_title(&format!(
            "imoto-life | {}x{} -> x{} | frame {} | {} quad(s){} | {} fps",
            LOGICAL_W,
            LOGICAL_H,
            scaler.scale,
            self.game.stats.frames,
            self.sprites.len(),
            if text_count > 0 { ", text pending" } else { "" },
            self.fps_frames
        ));
    }
}

impl ApplicationHandler for App {
    fn resumed(&mut self, event_loop: &ActiveEventLoop) {
        let attributes = Window::default_attributes()
            .with_title("imoto-life | title screen")
            .with_inner_size(PhysicalSize::new(1920u32, 1080u32));
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
        let info = renderer.adapter_info();
        println!(
            "play: {} ({:?}, backend {:?}) | {}x{} logical",
            info.name, info.device_type, info.backend, LOGICAL_W, LOGICAL_H
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
        self.window = Some(window);
        self.renderer = Some(renderer);
        self.next_frame = Instant::now() + FRAME_TIME;
    }

    fn window_event(&mut self, event_loop: &ActiveEventLoop, _id: WindowId, event: WindowEvent) {
        match event {
            WindowEvent::CloseRequested => event_loop.exit(),
            WindowEvent::KeyboardInput { event, .. } => {
                let bit = wolf_bit(&event.logical_key);
                if event.state == ElementState::Pressed {
                    if matches!(event.logical_key, Key::Named(NamedKey::F10)) {
                        event_loop.exit();
                        return;
                    }
                    // manual01: F12 restarts the game. Ignore auto-repeat so a held key
                    // cannot reload the data root dozens of times a second.
                    if is_restart_key(&event.logical_key) {
                        if !event.repeat {
                            self.restart();
                        }
                        return;
                    }
                    if let Some(bit) = bit {
                        self.held.insert(bit);
                    }
                } else if let Some(bit) = bit {
                    self.held.remove(&bit);
                }
            }
            WindowEvent::CursorMoved { position, .. } => {
                // winit reports physical pixels; the scaler maps them back onto the
                // 1024x576 grid the game draws in, so the pointer lands where the
                // player sees it even with letterboxing or an integer upscale.
                if let Some(window) = &self.window {
                    self.mouse = game_point(window, position.x, position.y);
                }
            }
            WindowEvent::CursorLeft { .. } => {
                self.mouse = [-1, -1];
                self.mouse_buttons = 0;
            }
            WindowEvent::MouseInput { state, button, .. } => {
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
                    renderer.draw(&self.sprites);
                    let items = self.build_text_items();
                    renderer.draw_text(&items);
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
/// Maps a physical window position onto the 1024x576 game grid.
///
/// The renderer blits with the largest whole integer scale and centres the result, so the
/// inverse is `(pos - offset) / scale`. A position on the black bar maps to a negative
/// game coordinate, which is also how the engine reports "outside the screen".
fn game_point(window: &Window, x: f64, y: f64) -> [i32; 2] {
    let size = window.inner_size();
    let scaler = Scaler::new(size.width.max(1), size.height.max(1));
    let scale = f64::from(scaler.scale.max(1));
    [
        ((x - f64::from(scaler.offset[0])) / scale).floor() as i32,
        ((y - f64::from(scaler.offset[1])) / scale).floor() as i32,
    ]
}

/// True for the physical key that restarts the session.
///
/// manual01 lists F12 as 「再起动」 and `Game.ini` ships `F12_Reset=1`, so the port
/// mirrors that binding instead of reserving F12 for anything else.
fn is_restart_key(key: &Key) -> bool {
    matches!(key, Key::Named(NamedKey::F12))
}

fn wolf_bit(key: &Key) -> Option<u32> {
    match key {
        Key::Named(NamedKey::ArrowUp) => Some(key::UP),
        Key::Named(NamedKey::ArrowDown) => Some(key::DOWN),
        Key::Named(NamedKey::ArrowLeft) => Some(key::LEFT),
        Key::Named(NamedKey::ArrowRight) => Some(key::RIGHT),
        Key::Named(NamedKey::Enter | NamedKey::Space) => Some(key::OK),
        Key::Named(NamedKey::Escape | NamedKey::Backspace) => Some(key::CANCEL),
        Key::Named(NamedKey::Shift | NamedKey::Tab) => Some(key::SUB),
        Key::Character(text) => match text.to_lowercase().as_str() {
            "z" | "y" => Some(key::OK),
            "x" => Some(key::CANCEL),
            "c" => Some(key::SUB),
            _ => None,
        },
        _ => None,
    }
}

#[cfg(test)]
mod tests {
    use super::is_restart_key;
    use winit::keyboard::{Key, NamedKey};

    /// manual01/F12_Reset: only F12 restarts; F10 stays the quit key and the ordinary
    /// gameplay keys must never trigger a reload.
    #[test]
    fn f12_is_the_restart_key() {
        assert!(is_restart_key(&Key::Named(NamedKey::F12)));
        for key in [
            Key::Named(NamedKey::F10),
            Key::Named(NamedKey::F11),
            Key::Named(NamedKey::Escape),
            Key::Named(NamedKey::Enter),
            Key::Character("z".into()),
        ] {
            assert!(!is_restart_key(&key), "{key:?} must not restart");
        }
    }
}
