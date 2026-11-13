//! Godot 4 GDExtension facade for the WOLF runtime.
//!
//! The heavy parts of the original WOLF engine are already implemented and tested in
//! pure Rust (`wolf-format` / `wolf-vm` / `wolf-save` / `wolf-game`). This crate is the
//! thin bridge that lets a Godot scene drive that runtime:
//!
//! * [`WolfGame`] owns one [`Game`] plus the packed [`Atlas`].
//! * Every frame the scene calls [`WolfGame::frame`], then draws the returned sprite
//!   and text quads itself. No wgpu, winit or audio device is compiled into this DLL;
//!   Godot owns the window, the renderer and the mixer.
//! * The atlas travels as a raw RGBA8 `PackedByteArray`, only when its entry count
//!   changed. Text quads carry logical-pixel rectangles and style runs, so the scene
//!   only has to pick a face and draw.
//!
//! Deliberately absent from the P0 surface: font shaping (Godot's `TextParagraph`
//! handles it), audio playback (Godot's own decoders handle ogg/mp3/wav), and the
//! engine-side debug overlays. Those arrive in later migration phases.

use std::path::{Path, PathBuf};

use godot::builtin::VarDictionary;
use godot::classes::RefCounted;
use godot::prelude::*;

use wolf_game::atlas::{Atlas, SpriteQuad, TextQuad};
use wolf_game::message::{self, Run as MessageRun};
use wolf_game::{Game, OverlayLayer};
use wolf_vm::{ChoiceReply, SoundAction, SoundChannel};

struct WolfGdext;

#[gdextension]
unsafe impl ExtensionLibrary for WolfGdext {}

/// One live WOLF session, exposed to GDScript as `WolfGame`.
#[derive(GodotClass)]
#[class(base = RefCounted)]
struct WolfGame {
    base: Base<RefCounted>,
    game: Option<Game>,
    atlas: Atlas,
    root: Option<PathBuf>,
}

#[godot_api]
impl IRefCounted for WolfGame {
    fn init(base: Base<RefCounted>) -> Self {
        Self {
            base,
            game: None,
            atlas: Atlas::new(),
            root: None,
        }
    }
}

#[godot_api]
impl WolfGame {
    /// Loads the WOLF data root and builds an idle VM.
    ///
    /// `root` is the unpacked data directory (the folder that contains `BasicData/`).
    /// Returns false and logs a Godot error when a mandatory file is missing.
    #[func]
    fn open(&mut self, root: GString) -> bool {
        let root = PathBuf::from(root.to_string());
        let started = std::time::Instant::now();
        match Game::with_overlays(&root, Vec::new()) {
            Ok(mut game) => {
                let load_ms = started.elapsed().as_secs_f64() * 1000.0;
                game.apply_settings();
                let font_started = std::time::Instant::now();
                install_font_metrics(&mut game, &root);
                let font_ms = font_started.elapsed().as_secs_f64() * 1000.0;
                godot_print!(
                    "wolf-gdext: open game={load_ms:.1}ms font={font_ms:.1}ms total={:.1}ms",
                    started.elapsed().as_secs_f64() * 1000.0
                );
                self.root = Some(root);
                self.game = Some(game);
                true
            }
            Err(err) => {
                godot_error!("wolf-gdext: cannot load {}: {err}", root.display());
                false
            }
        }
    }

    /// Runs the boot map event (the title splash / title screen sequence).
    #[func]
    fn boot(&mut self) -> bool {
        let Some(game) = self.game.as_mut() else {
            godot_error!("wolf-gdext: boot before open");
            return false;
        };
        match game.boot() {
            Ok(()) => true,
            Err(err) => {
                godot_error!("wolf-gdext: boot failed: {err}");
                false
            }
        }
    }

    /// Starts common event 42 (the title menu) without the boot map.
    #[func]
    fn start_title(&mut self) -> bool {
        let Some(game) = self.game.as_mut() else {
            godot_error!("wolf-gdext: start_title before open");
            return false;
        };
        match game.start_title() {
            Ok(()) => true,
            Err(err) => {
                godot_error!("wolf-gdext: start_title failed: {err}");
                false
            }
        }
    }

    /// Queues a choice answer for the next frame. `index` is the visible row index.
    #[func]
    fn reply(&mut self, index: i64) {
        if let Some(game) = self.game.as_mut() {
            game.reply(ChoiceReply::Index(index.max(0) as usize));
        }
    }

    /// Queues a cancel/back answer for the next frame.
    #[func]
    fn cancel(&mut self) {
        if let Some(game) = self.game.as_mut() {
            game.reply(ChoiceReply::Cancel);
        }
    }

    /// Moves the highlighted choice row (used by scripted captures and tests).
    #[func]
    fn set_choice_cursor(&mut self, index: i64) {
        if let Some(game) = self.game.as_mut() {
            game.set_choice_cursor(index.max(0) as usize);
        }
    }

    /// Enables the headless capture behaviour used by `wolf-cli capture --answer 0`:
    /// messages dismiss themselves and every choice prompt answers option 0 after
    /// `delay` frames. Enable only for scripted captures, never for interactive play.
    #[func]
    fn set_auto_play(&mut self, enabled: bool, delay: u32) {
        if let Some(game) = self.game.as_mut() {
            game.auto_advance = enabled;
            game.auto_choice = enabled;
            game.auto_choice_delay = delay;
        }
    }

    /// Toggles automatic message dismissal independently of choice answering.
    #[func]
    fn set_auto_advance(&mut self, enabled: bool) {
        if let Some(game) = self.game.as_mut() {
            game.auto_advance = enabled;
        }
    }

    /// The six key bindings the settings screen edits (`Sys52..57`).
    ///
    /// Only the even entries are keyboard decide/cancel/sub; the odd entries are the
    /// file's flag words (see `wolf_game::settings::GlobalSettings::key_config`). A
    /// front-end needs this to turn held physical keys into the logical `key_bits`
    /// mask after the player rebinds them in CE132, exactly like `wolf-cli play`.
    #[func]
    fn key_config(&self) -> PackedInt32Array {
        let mut out = PackedInt32Array::new();
        let Some(game) = self.game.as_ref() else {
            return out;
        };
        for word in game.live_settings().key_config {
            out.push(i32::try_from(word).unwrap_or(0));
        }
        out
    }

    /// Queues this frame's mouse-wheel notches: positive is up, negative down.
    ///
    /// `Game::frame` turns them into a choice-cursor step, a save-grid page key
    /// (left/right) or an up/down menu key, then clears the queue. The front-end
    /// accumulates `InputEventMouseButton` wheel events between physics ticks.
    #[func]
    fn set_wheel(&mut self, notches: i32) {
        if let Some(game) = self.game.as_mut() {
            game.wheel = notches;
        }
    }

    /// The message history (oldest first), for the in-game log and bug reports.
    ///
    /// Bounded by `wolf_game::HISTORY_LIMIT` (200 lines). New messages append; a
    /// load does not clear it, so a transcript can span a save/load session.
    #[func]
    fn transcript(&self) -> Array<GString> {
        let mut out = Array::new();
        let Some(game) = self.game.as_ref() else {
            return out;
        };
        for message in game.message_history() {
            let line = GString::from(message.text.as_str());
            out.push(&line);
        }
        out
    }

    /// Event ids of the common-event coroutines currently alive, for diagnostics.
    #[func]
    fn running_events(&self) -> PackedInt32Array {
        let mut out = PackedInt32Array::new();
        let Some(game) = self.game.as_ref() else {
            return out;
        };
        for instance in game.vm.instances() {
            out.push(i32::try_from(instance.event).unwrap_or(0));
        }
        out
    }

    /// Publishes this frame's input state into the runtime.
    ///
    /// `key_bits` uses the port's host bitmask (`wolf_game::key::OK` = 1, CANCEL = 2,
    /// SUB = 4, directions 16/32/64/128). `raw_keys` are WOLF keyboard codes
    /// (scancode + 100) used only by the key-config screen. `mouse` is in logical
    /// 1024x576 pixels, `mouse_buttons` is 1 left / 2 right / 4 middle.
    #[func]
    fn set_input(
        &mut self,
        key_bits: u32,
        raw_keys: PackedInt32Array,
        mouse: Vector2i,
        mouse_buttons: u32,
    ) {
        let Some(game) = self.game.as_mut() else {
            return;
        };
        game.key_bits = key_bits;
        game.raw_keys.clear();
        game.raw_keys.extend_from_slice(raw_keys.as_slice());
        game.mouse = [mouse.x, mouse.y];
        game.mouse_buttons = mouse_buttons;
    }

    /// Advances the VM by one 1/60 s frame and returns this frame's draw packet.
    ///
    /// The returned dictionary contains:
    /// * `sprites`: dynamic picture quads (`{rect, src, alpha, tint, blend, number}`);
    /// * `texts`: array of `{text, rect, alpha, font_px, colour, outline, weight}`;
    /// * `overlays`: array of `{kind: "colour"|"frozen", color: Color, alpha: float}`;
    /// * `sounds`: array of `{channel, action, file, volume, frames}`;
    /// * `freeze`: true when the scene should snapshot the previous frame;
    /// * `pictures`, `idle`, `diagnostics`.
    #[func]
    fn frame(&mut self) -> VarDictionary {
        let mut packet = VarDictionary::new();
        let Self { game, atlas, .. } = self;
        let Some(game) = game.as_mut() else {
            return packet;
        };

        let outcome = game.frame();
        // Drop a page that filled up on a previous frame before rebuilding the draw
        // list: the entries a long session accumulated may all be off-screen now, while
        // the pictures this frame needs still fit.
        atlas.begin_frame();
        let freeze = game.take_freeze_request();
        let choice_options = game
            .choices
            .as_ref()
            .map_or_else(Vec::new, |choices| choices.options.clone());
        let choice_cursor = game.choice_cursor() as i64;
        let (choice_x, choice_y) = game.choice_anchor();

        let mut sprites: Array<VarDictionary> = Array::new();
        for quad in game.picture_quads(atlas) {
            let sprite = sprite_dict(&quad, atlas.size());
            sprites.push(&sprite);
        }

        // The engine paints the choice panel and the pause cursor itself; they are not
        // picture slots and `picture_quads` cannot reproduce them.
        let choice_data = game.choices.as_ref().map(|choices| {
            (
                choices.options.clone(),
                game.choice_cursor(),
                game.choice_anchor(),
                game.font_px(),
            )
        });
        let mut choice_texts: Vec<TextQuad> = Vec::new();
        if let Some((options, cursor, (x, y), font_px)) = choice_data {
            if let Some((panel, rows)) = wolf_game::choice::overlay_at_sized(
                atlas,
                &mut game.assets,
                &options,
                cursor,
                x,
                y,
                font_px,
            ) {
                for quad in panel {
                    let mut sprite = sprite_dict(&quad, atlas.size());
                    // The engine's own menu chrome sits above every picture slot.
                    sprite.set("z", UI_Z);
                    sprites.push(&sprite);
                }
                choice_texts = rows;
            }
        }

        // Both the cursor and the native text runs consume this layout. Compute it
        // once; in balloon mode it is `None`, and in article mode the layout work is
        // otherwise duplicated every frame.
        let message_layout = game.rendered_message_layout();
        let cursor_data = message_layout.as_ref().and_then(|layout| {
            layout
                .cursor
                .map(|at| (at, game.messages.last().map_or(0, |message| message.frames)))
        });
        if let Some((at, frames)) = cursor_data {
            let frame = message::cursor_frame(frames);
            let src = [
                0,
                frame * message::CURSOR_FRAME_H,
                message::CURSOR_FRAME_W,
                message::CURSOR_FRAME_H,
            ];
            let dst = [
                at[0],
                at[1],
                message::CURSOR_FRAME_W as f32,
                message::CURSOR_FRAME_H as f32,
            ];
            if let Some(quad) = atlas.sprite_from(
                &mut game.assets,
                message::CURSOR_FILE,
                message::CURSOR_SLOT,
                src,
                dst,
                1.0,
            ) {
                let mut sprite = sprite_dict(&quad, atlas.size());
                sprite.set("z", UI_Z);
                sprites.push(&sprite);
            }
        }

        let mut texts: Array<VarDictionary> = Array::new();
        for text in game.text_quads() {
            let text = text_dict(&text);
            texts.push(&text);
        }
        for text in choice_texts {
            let mut text = text_dict(&text);
            text.set("z", UI_Z);
            texts.push(&text);
        }
        if let Some(layout) = &message_layout {
            for run in &layout.runs {
                let text = message_run_dict(run);
                texts.push(&text);
            }
        }

        let mut overlays: Array<VarDictionary> = Array::new();
        for overlay in game.screen_overlays() {
            let mut dict = VarDictionary::new();
            match overlay.layer {
                OverlayLayer::Colour(rgb) => {
                    dict.set("kind", "colour");
                    dict.set("color", colour(rgb));
                }
                OverlayLayer::FrozenFrame => {
                    dict.set("kind", "frozen");
                    dict.set("color", Color::from_rgba(1.0, 1.0, 1.0, 1.0));
                }
            }
            dict.set("alpha", overlay.alpha);
            overlays.push(&dict);
        }

        let mut sounds: Array<VarDictionary> = Array::new();
        for cmd in &game.sounds {
            let mut dict = VarDictionary::new();
            dict.set(
                "channel",
                match cmd.channel {
                    SoundChannel::Bgm => "bgm",
                    SoundChannel::Bgs => "bgs",
                    SoundChannel::Se => "se",
                },
            );
            dict.set(
                "action",
                match cmd.action {
                    SoundAction::Play => "play",
                    SoundAction::Stop => "stop",
                },
            );
            dict.set("file", cmd.file.clone());
            dict.set("volume", cmd.volume as i64);
            dict.set("pitch", cmd.pitch as i64);
            dict.set("frames", cmd.frames as i64);
            sounds.push(&dict);
        }

        let mut diagnostics: Array<GString> = Array::new();
        for (text, count) in game.diagnostics.iter().take(20) {
            let line = format!("{count}x {text}");
            let line = GString::from(line.as_str());
            diagnostics.push(&line);
        }

        let mut options: Array<GString> = Array::new();
        for option in &choice_options {
            let value = GString::from(option.as_str());
            options.push(&value);
        }

        packet.set("sprites", &sprites);
        packet.set("texts", &texts);
        packet.set("overlays", &overlays);
        packet.set("sounds", &sounds);
        packet.set("bgm_volume", game.bgm_volume() as i64);
        packet.set("se_volume", game.se_volume() as i64);
        packet.set("freeze", freeze);
        packet.set("transition_active", game.screen_transition.is_active());
        packet.set("pictures", outcome.pictures as i64);
        packet.set("idle", outcome.idle);
        if let Some((current, maximum)) = game.hud_action_points() {
            let mut ap = VarDictionary::new();
            ap.set("current", current as i64);
            ap.set("max", maximum as i64);
            let bar = Game::hud_action_bar_rect();
            ap.set(
                "bar",
                Rect2::new(Vector2::new(bar[0], bar[1]), Vector2::new(bar[2], bar[3])),
            );
            packet.set("ap", &ap);
        }
        // Opcode 175 (title → おわる) asks the process to exit; the front-end owns the
        // window, so it polls this instead of the engine calling exit() mid-frame.
        packet.set("quit", game.quit_requested);
        packet.set("diagnostics", &diagnostics);
        let mut stats = VarDictionary::new();
        stats.set("frames", game.stats.frames as i64);
        stats.set("instructions", game.stats.instructions as i64);
        stats.set("pictures", game.stats.pictures as i64);
        stats.set("messages", game.stats.messages as i64);
        stats.set("choices", game.stats.choices as i64);
        stats.set("warnings", game.stats.warnings as i64);
        stats.set("unmodelled", game.stats.unmodelled as i64);
        packet.set("stats", &stats);
        packet.set("choices", &options);
        packet.set("choice_cursor", choice_cursor);
        packet.set("choice_anchor", Vector2i::new(choice_x, choice_y));
        // -1 = no map hotspot has been activated by a click/OK yet. A front-end log
        // showing this unchanged after a click means the pointer missed every
        // trigger-0 hit box (or a message/choice owned the press).
        packet.set(
            "last_action_event",
            game.last_action_event.map_or(-1, i64::from),
        );
        packet
    }

    /// Atlas content revision. Changes when artwork was added or the page was reset,
    /// which is the scene's cue to pull `atlas_pixels()` again. The entry count alone
    /// was not enough: a reset can repack the same number of entries with different
    /// pixels.
    #[func]
    fn atlas_len(&self) -> i64 {
        self.atlas.revision() as i64
    }

    /// Uploaded atlas dimensions in pixels: the smallest rectangle containing every
    /// packed entry, in the original 4096x4096 coordinate space.
    ///
    /// `sprite_dict` keeps converting UVs against the full backing page, so the
    /// source rectangles remain valid even though the empty right/bottom tail is not
    /// copied to Godot.
    #[func]
    fn atlas_size(&self) -> Vector2i {
        let [width, height] = self.atlas.content_size();
        Vector2i::new(width as i32, height as i32)
    }

    /// Raw RGBA8 pixels cropped to [`WolfGame::atlas_size`], row-major, top-left origin.
    ///
    /// This is deliberately not `Atlas::pixels()`: uploading the full empty 4096² page
    /// cost 64 MiB per atlas revision and was the dominant startup/menu hitch.
    #[func]
    fn atlas_pixels(&self) -> PackedByteArray {
        let [width, height] = self.atlas.content_size();
        let mut bytes = PackedByteArray::new();
        let needed = width as usize * height as usize * 4;
        bytes.resize(needed);
        if !self.atlas.copy_content_pixels(bytes.as_mut_slice()) {
            bytes.resize(0);
        }
        bytes
    }

    /// Runs the one-shot engine initialisation (common event 48) before a save load.
    /// Mirrors `wolf-cli capture --load-save`, which does this to stop CE48's first
    /// pass from overwriting the restored status cells. Returns the frames driven.
    #[func]
    fn prime_engine(&mut self) -> i64 {
        let Some(game) = self.game.as_mut() else {
            return 0;
        };
        game.prime_engine() as i64
    }

    /// Builds the first visible draw packet before the window presents a frame.
    ///
    /// `open`/`load_save` only parse data; picture decoding and the first atlas
    /// pack happen lazily in `frame()`. On a cold disk that made the first
    /// visible frame much slower than `ready_ms` suggested. This calls the same
    /// render-only paths as `frame()` without advancing the VM, so the caller
    /// can upload the atlas once while still showing its loading state.
    #[func]
    fn prewarm_draw(&mut self) {
        let Self { game, atlas, .. } = self;
        let Some(game) = game.as_mut() else {
            return;
        };
        let _ = game.picture_quads(atlas);
        let _ = game.text_quads();
    }

    /// Saves the live session to a WOLF `.sav` file.
    #[func]
    fn save_to(&mut self, path: GString) -> bool {
        let Some(game) = self.game.as_mut() else {
            return false;
        };
        match game.save_to(Path::new(&path.to_string())) {
            Ok(bytes) => {
                godot_print!("wolf-gdext: wrote {bytes} byte(s) to {path}");
                true
            }
            Err(err) => {
                godot_error!("wolf-gdext: save failed: {err}");
                false
            }
        }
    }

    /// Persists live system settings on front-end shutdown, when they changed.
    ///
    /// Returns true when the settings are already on disk or were written; false
    /// when there is no session or the write failed.
    #[func]
    fn save_settings(&mut self) -> bool {
        let Some(game) = self.game.as_mut() else {
            return false;
        };
        if !game.settings_dirty() {
            return true;
        }
        match game.save_system_settings() {
            Ok(()) => true,
            Err(err) => {
                godot_error!("wolf-gdext: settings save failed: {err}");
                false
            }
        }
    }

    /// Loads a WOLF `.sav` file and resumes its map, if one is stored.
    #[func]
    fn load_save(&mut self, path: GString) -> bool {
        let Some(game) = self.game.as_mut() else {
            return false;
        };
        match game.load_save(Path::new(&path.to_string())) {
            Ok(_) => match game.resume_loaded_map() {
                Ok(map) => {
                    godot_print!("wolf-gdext: loaded save, map {map}");
                    true
                }
                Err(err) => {
                    godot_error!("wolf-gdext: resume after load failed: {err}");
                    false
                }
            },
            Err(err) => {
                godot_error!("wolf-gdext: load failed: {err}");
                false
            }
        }
    }

    /// Logical resolution of the runtime (1024x576 in this game).
    #[func]
    fn screen_size(&self) -> Vector2i {
        Vector2i::new(1024, 576)
    }

    /// True once `open` succeeded.
    #[func]
    fn is_open(&self) -> bool {
        self.game.is_some()
    }

    /// Data root this session was opened with, or an empty string.
    #[func]
    fn data_root(&self) -> GString {
        self.root.as_ref().map_or_else(GString::new, |path| {
            GString::from(path.to_string_lossy().as_ref())
        })
    }
}

fn sprite_dict(quad: &SpriteQuad, atlas_size: [u32; 2]) -> VarDictionary {
    let mut dict = VarDictionary::new();
    dict.set("number", quad.number as i64);
    // CE237 draws the two gauge frames at 1994/1998 and then the decorative
    // sleeping overlay at 2000. The retail close-up shows the central sleeping
    // badge covering the inner endpoints of both frames, so keep WOLF's slot
    // order instead of lifting the frames above the decoration.
    let z = sprite_z(quad.number);
    dict.set("z", z as i64);
    dict.set("blend", quad.blend as i64);
    dict.set("rect", rect2(quad.rect));
    dict.set(
        "src",
        Rect2::new(
            Vector2::new(
                quad.uv[0] * atlas_size[0] as f32,
                quad.uv[1] * atlas_size[1] as f32,
            ),
            Vector2::new(
                (quad.uv[2] - quad.uv[0]) * atlas_size[0] as f32,
                (quad.uv[3] - quad.uv[1]) * atlas_size[1] as f32,
            ),
        ),
    );
    dict.set("alpha", quad.alpha);
    dict.set("tint", tint_colour(quad.tint));
    dict
}

fn sprite_z(number: i32) -> i64 {
    i64::from(number)
}

/// Draw order for the engine's own menu chrome (choice panel/text, message text and
/// cursor). It must sit above every picture slot, including the 12xxx save grid.
const UI_Z: i64 = 1_000_000;

fn text_dict(text: &TextQuad) -> VarDictionary {
    let mut dict = VarDictionary::new();
    dict.set("text", text.text.clone());
    dict.set("rect", rect2(text.rect));
    dict.set("alpha", text.alpha);
    dict.set("font_px", text.font_px);
    dict.set("colour", colour(text.colour));
    dict.set("outline", text.outline);
    dict.set("weight", i64::from(text.weight));
    // The front-end composites texts and sprites in one pass; without the slot number
    // every text was painted after every sprite, so the HUD (slots 200..252) floated on
    // top of the 12000-range save window instead of being covered by it.
    dict.set("number", i64::from(text.number));
    dict.set("z", i64::from(text.number));
    dict
}

fn message_run_dict(run: &MessageRun) -> VarDictionary {
    let mut dict = VarDictionary::new();
    dict.set("text", run.text.clone());
    // The shaping pass needs one em of slack so the last glyph does not wrap.
    let mut rect = run.rect;
    rect[2] += run.font_px;
    dict.set("rect", rect2(rect));
    dict.set("alpha", 1.0);
    dict.set("font_px", run.font_px);
    dict.set(
        "colour",
        colour(run.colour.unwrap_or(message::DEFAULT_COLOUR)),
    );
    dict.set("outline", run.outline);
    dict.set("weight", 700_i64);
    dict.set("z", UI_Z);
    dict
}

fn rect2(rect: [f32; 4]) -> Rect2 {
    Rect2::new(
        Vector2::new(rect[0], rect[1]),
        Vector2::new(rect[2], rect[3]),
    )
}

fn colour(rgb: [u8; 3]) -> Color {
    Color::from_rgba(
        f32::from(rgb[0]) / 255.0,
        f32::from(rgb[1]) / 255.0,
        f32::from(rgb[2]) / 255.0,
        1.0,
    )
}

fn tint_colour(rgb: [f32; 3]) -> Color {
    Color::from_rgba(rgb[0], rgb[1], rgb[2], 1.0)
}

/// Installs the game's real font metrics for text-picture anchor maths.
///
/// The retail face is `Microsoft YaHei UI Bold` from `Game.dat`; the data root also
/// ships two fallback faces. Whichever parses first wins, matching the CLI's search
/// order closely enough for the title and HUD.
fn install_font_metrics(game: &mut Game, root: &Path) {
    let mut candidates = vec![PathBuf::from("C:/Windows/Fonts/msyhbd.ttc")];
    for name in [
        "◆GenJyuuGothicX-P-Bold.ttf",
        "07やさしさゴシックボールド.ttf",
    ] {
        candidates.push(root.join(name));
    }
    for path in candidates {
        let Ok(bytes) = std::fs::read(&path) else {
            continue;
        };
        if game.set_font_metrics(bytes) {
            godot_print!("wolf-gdext: font metrics {}", path.display());
            return;
        }
    }
    godot_warn!("wolf-gdext: no usable font metrics found");
}

#[cfg(test)]
mod tests {
    use super::sprite_z;

    #[test]
    fn shared_status_frames_stay_below_the_sleeping_decoration() {
        assert!(sprite_z(1994) < sprite_z(2000));
        assert!(sprite_z(1998) < sprite_z(2000));
        assert_eq!(sprite_z(1996), 1996);
    }
}
