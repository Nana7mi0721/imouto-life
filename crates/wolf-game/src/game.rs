//! The game layer: one VM, one picture screen, one asset database, one frame at a time.
//!
//! [`Game`] is the piece that turns the interpreter into something a window can draw. It
//! implements [`Host`] itself (through a short-lived borrow shim, because the VM needs
//! the host while living inside the game), so every WOLF callback - pictures, sounds,
//! database reads, messages, choices - lands in typed state the renderer can consume.
//!
//! Two rules keep this honest:
//!
//! * Nothing here invents game state. If the VM asks for something we do not model yet,
//!   the request is recorded as a diagnostic and dropped; the frame still runs. A port
//!   that panics on the first unknown opcode never gets past the title screen.
//! * The frame boundary is explicit. Input is latched at the top of [`Game::frame`];
//!   everything the VM produced during the frame is readable when it returns. That makes
//!   a recorded session replayable, which is how the save-compat work will be verified.

use std::collections::BTreeMap;
use std::fmt;
use std::path::{Path, PathBuf};

use std::sync::Arc;

use wolf_format::commonevent::CommonEventData;
use wolf_format::gamedat::GameDat;
use wolf_format::mps::Map;
use wolf_format::tileset::TileSetData;
use wolf_vm::{
    ChoiceReply, DbOp, DbValue, Host, LogLevel, PictureCmd, Program, ProgramSet, SaveOp,
    SaveTarget, SoundCmd, StepReport, Vm,
};

use crate::assets::Assets;
use crate::atlas::{Atlas, SpriteQuad};
use crate::auto_events::AutoEvents;
use crate::db::Databases;
use crate::map_runtime::MapRuntime;
use crate::picture::{PictureKind, Screen, ANCHOR_CENTRE, SCREEN_H, SCREEN_W};
use crate::tilemap::TileMap;
use crate::tint::ScreenTint;
use crate::transition::ScreenTransition;

/// The event the game opens with in this build (the "original title screen A").
pub const TITLE_EVENT: u32 = 42;

/// The map the original boots into (SysDatabase type 0, row 0).
pub const BOOT_MAP: &str = "MapData/TitleMap.mps";

/// The autorun event on [`BOOT_MAP`] that plays the splashes and reaches the title.
pub const BOOT_EVENT: u32 = 2;

/// Events the engine starts unconditionally, because their header says
/// `parallel_process_always(3)` (docs/ENGINE_EVENTS.md section 7).
///
/// The condition byte they also carry is an editor artefact: e.g. `270` names variable
/// `2700020`, which never appears anywhere in the 550 common events or the 9 map
/// resources, so the original cannot be gating on it.
///
/// Order matters: 48 fills the system variables; 261 must precede 270 (270 reads
/// `2700000..2700005`); 269 must precede 270 (270 tests the flag `1600099` that 269
/// sets); 225 publishes Sys71/72, which 224 and 213 consume.
pub const ENGINE_ALWAYS: &[u32] = &[
    48,  // X[共]基本システム自動初期化 - system variables first
    261, // ×◆座標変数初期化      - writes 2700000..2700005 for 270
    269, // ×┣[メッセ—ジ]初期化·設定 - sets self 1600099 for 270
    270, // ×┣[メッセ—ジ]表示処理
    271, // ×┗[メッセ—ジ]オートスキップ - writes sysstr 26/27
    224, // ウィンドウ処理         - needs 225's Sys71/72 and other events' picture numbers
    225, // フィールド上処理         - publishes Sys71/72, draws the picture cursor
    213, // クリックエフェクト        - needs 225's Sys71/72
    214, // 健康監視
    41,  // マウス感知コモン
];
// 271 is the balloon-message library's initiator: it calls event 98, which registers 19
// window pictures (10225..10248). It used to be left out, because starting it alone
// moved retail title parity from mean abs 0.012 to 0.130 at max 255: those widgets
// landed at (0,0) and came out visible. They now land at (-2784, 2880), i.e. on the
// library's own parking spot, once the call arguments reach their self bank and the
// database writes behind them resolve; `picture::on_screen` then drops them, because a
// quad that cannot touch the screen is not a drawing. Re-measured with 271 alone:
// `imgdiff` reports the frame identical to not starting it, and retail parity is back
// at mean abs 0.012 / psnr 67.20 dB (docs/ENGINE_EVENTS.md section 10.5).

/// `auto_start(1)`: run once when the game starts. It clears its own condition variable
/// (slot 628 writes `v350 = 0`) and ends, so it never becomes a resident coroutine.
pub const ENGINE_AUTO_START: &[u32] = &[241];

/// Started by an engine *feature* rather than by `run_condition`: YADOT-WOLF documents
/// that every 【文章の表示】 executes 063 (work/yado.txt:61-63 and :68-70), and no script
/// anywhere targets 500063, so without this the message-window frame never appears.
pub const ENGINE_IMPLICIT: &[u32] = &[63];

/// One visible message window.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Message {
    /// Text as the script produced it, escape-expanded, with the @-face prefix removed.
    pub text: String,
    /// Face graphic id from the @-prefix, when the script carries one.
    pub face: Option<i32>,
    /// Frames this message has been on screen.
    pub frames: u32,
}

/// A pending choice prompt.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Choices {
    /// The option labels, in order.
    pub options: Vec<String>,
    /// Frames this prompt has been on screen.
    pub frames: u32,
}

/// A queued `130 Teleport` request. The map change runs after the VM step
/// because the host cannot borrow `Game`.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct MapRequest {
    /// Raw `130` target: `-1` is the hero (`0xffffffff`), `-2` a variable.
    target: i32,
    /// Destination map id, the fourth raw argument.
    map: i32,
    x: i32,
    y: i32,
    /// Bit 0 = precise coordinates, bits 4..7 = transition kind.
    options: i32,
}

/// Counters that make a headless run comparable to an interactive one.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct GameStats {
    /// Frames advanced.
    pub frames: u64,
    /// Instructions executed across all coroutines.
    pub instructions: u64,
    /// Most coroutines alive at the end of any frame.
    pub peak_instances: usize,
    /// Picture commands applied.
    pub pictures: u64,
    /// Sound commands seen.
    pub sounds: u64,
    /// Database accesses seen.
    pub databases: u64,
    /// Of those, the ones that wrote a cell (`250` with bit 12 clear).
    pub database_writes: u64,
    /// Of those, the ones whose editor labels moved the script's numeric type id onto a
    /// different table row (see [`crate::db::Databases::resolve_labels`]).
    pub database_labels: u64,
    /// Of those, the ones that set a table's row count (`250` write to row -2).
    pub database_row_counts: u64,
    /// Of those, reads that landed on a runtime slot past the last row (`100 + n`);
    /// no file holds those rows, so the answer is the empty value
    /// (docs/BATTLE.md section 2.6).
    pub database_slots: u64,
    /// Of those, reads that fell past a table's own row or column bounds because the
    /// shipped `.dat` is smaller than the battle template the scripts were written
    /// against (the 16-field `戦闘時一時ステータス` carries no `装備中の武器/防具`,
    /// the 9-field `敵キャラ個体デ—タ` carries no `基本命中率/取得経験値`). The
    /// engine answers a Variant default there, so these are empty cells, counted
    /// apart from the reads that miss because a label failed to resolve.
    pub database_out_of_schema: u64,
    /// Of those, reads of a row a run-time `250` row-count shrink/clear dropped (the
    /// battle copy events clear each temporary table before refilling it, so a read that
    /// still uses an old address lands past the live count). The engine answers an empty
    /// cell for a row the table no longer holds, never the stale value, so these are
    /// empty answers counted apart from a label that truly failed to resolve.
    pub database_row_out_of_range: u64,
    /// Messages shown.
    pub messages: u64,
    /// Choice prompts shown.
    pub choices: u64,
    /// Warnings and errors logged by the interpreter.
    pub warnings: u64,
    /// Requests this layer does not model yet (deduplicated in [`Game::diagnostics`]).
    pub unmodelled: u64,
}

/// What one frame produced.
#[derive(Clone, Debug, Default)]
pub struct FrameOutcome {
    /// The interpreter's own per-frame report.
    pub report: StepReport,
    /// Pictures live at the end of the frame.
    pub pictures: usize,
    /// Sounds requested during the frame (the audio layer consumes these).
    pub sounds: usize,
    /// True once nothing is running any more.
    pub idle: bool,
}

/// Why the game could not be created.
#[derive(Debug)]
pub enum GameError {
    /// A data file could not be read.
    Io {
        /// Path that failed.
        path: PathBuf,
        /// Underlying error.
        source: std::io::Error,
    },
    /// A data file parsed incorrectly.
    Format(wolf_format::Error),
    /// The title event does not exist in this build.
    MissingEvent(u32),
}

impl fmt::Display for GameError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Io { path, source } => write!(f, "cannot read {}: {source}", path.display()),
            Self::Format(err) => write!(f, "malformed game data: {err}"),
            Self::MissingEvent(id) => write!(f, "common event {id} is not in this build"),
        }
    }
}

impl std::error::Error for GameError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self {
            Self::Io { source, .. } => Some(source),
            Self::Format(err) => Some(err),
            Self::MissingEvent(_) => None,
        }
    }
}

/// The running game.
pub struct Game {
    /// The interpreter.
    pub vm: Vm,
    /// Live pictures, in WOLF draw order.
    pub screen: Screen,
    /// Whole-screen colour multiplier from `151 ChangeColor`. Neutral unless a map event
    /// is flashing or darkening the map and the screen-layer pictures.
    pub screen_tint: ScreenTint,
    /// Whole-screen transition fade from `160`/`161`/`162`. Neutral (brightness 1.0)
    /// unless a `kind >= 0` transition is running; a `kind -1` hard cut leaves it neutral.
    pub screen_transition: ScreenTransition,
    /// Real glyph advances for text-picture anchors, when the host has loaded the game's
    /// font. `None` keeps the testable half-em fallback in [`crate::textpic`].
    pub font_metrics: Option<crate::fontmetrics::FontMetrics>,
    /// The current map's tile layers, drawn underneath every picture. WOLF draws the
    /// tile grid first and the picture layer over it; keeping the two separate here
    /// preserves that order and lets a map switch replace only the tile half.
    pub tilemap: Option<TileMap>,
    /// The six decoded tilesets. Retained so a teleport can rebuild [`Self::tilemap`]
    /// without re-reading TileSetData.dat.
    tilesets: Option<TileSetData>,
    /// Decoded assets, cached by WOLF asset name.
    pub assets: Assets,
    /// The three .dat databases plus the cells the engine fills in itself
    /// (see [`crate::db`]). Opcode 250 answers every read from here.
    pub databases: Databases,
    /// Keys held this frame (see crate::key).
    pub key_bits: u32,
    /// Sounds requested during the current frame.
    pub sounds: Vec<SoundCmd>,
    /// M4 audio output. `None` keeps the pure-logic and test paths silent and
    /// allocation-free; [`Self::enable_audio`] installs a real engine.
    pub audio: Option<wolf_audio::Engine>,
    /// Message windows on screen.
    pub messages: Vec<Message>,
    /// Pending choice prompt.
    pub choices: Option<Choices>,
    /// Counters.
    pub stats: GameStats,
    /// Deduplicated diagnostics, keyed by message, valued by hit count.
    pub diagnostics: BTreeMap<String, u64>,
    /// Queued answers for choice prompts (front is delivered first).
    pub replies: std::collections::VecDeque<ChoiceReply>,
    /// When true, messages dismiss immediately.
    pub auto_advance: bool,
    /// When true, a choice prompt answers itself with the highlighted option.
    pub auto_choice: bool,
    /// Frames a choice prompt must stay on screen before [`Self::auto_choice`] may answer
    /// it. 0 answers the moment the script asks, which lets a menu loop run to the
    /// instruction budget inside ONE frame; 1 emulates a player confirming once a frame,
    /// which is what a scripted playthrough needs to march through a menu.
    pub auto_choice_delay: u32,
    /// The automatic pages of the map the game booted into.
    pub runtime: MapRuntime,
    /// Common events whose header says `run_condition == 2`: one coroutine each,
    /// created while the condition holds and destroyed when it fails.
    pub auto_events: AutoEvents,
    /// Frames of play time; the save stores this in SavePart2.vars3_21[0].
    pub playtime_frames: u32,
    /// Mouse position in logical pixels, [-1, -1] when the pointer is outside.
    pub mouse: [i32; 2],
    /// Mouse buttons held this frame: bit 0 left, bit 1 right, bit 2 middle.
    pub mouse_buttons: u32,
    /// Which option the player has highlighted in the current choice prompt.
    choice_cursor: usize,
    /// Keys held on the previous frame, so a choice sees presses and not holds.
    previous_keys: u32,
    /// Mouse buttons held on the previous frame, so a press can be told from a hold.
    previous_mouse_buttons: u32,
    /// Replaces [`ENGINE_ALWAYS`] when set, so a capture can A/B one engine event at a
    /// time without editing the constant (see `wolf-cli --engine-events`).
    pub engine_always: Option<Vec<u32>>,
    /// True once the engine events have been started, so a map switch cannot start a
    /// second copy of a coroutine that is meant to live for the whole session.
    engine_events_started: bool,
    /// `220` loads queued by the interpreter; applied after the VM step that asked.
    save_requests: Vec<crate::savegame::SaveRequest>,
    /// `130` teleports queued by the interpreter; applied after the VM step that asked.
    map_requests: Vec<MapRequest>,
    /// The last save this game loaded or was born from, used as the template for
    /// 220 mode 0. A full save needs the map snapshot and object tables, which the
    /// running game does not otherwise keep; the template supplies them and the
    /// dynamic parts (play time, system anchor, normal variables, self variables)
    /// are copied from the live VM before writing.
    pub base_save: Option<wolf_save::SaveFile>,
    root: PathBuf,
}

impl Game {
    /// Loads the data needed to run events and builds an idle VM.
    ///
    /// # Errors
    ///
    /// Fails when Game.dat or CommonEvent.dat is missing or malformed, because without
    /// them no event can run at all.
    pub fn new(root: impl Into<PathBuf>) -> Result<Self, GameError> {
        let root = root.into();
        let basic = if root.join("BasicData").is_dir() {
            root.join("BasicData")
        } else {
            root.clone()
        };
        let events = read_events(&basic.join("CommonEvent.dat"))?;
        let programs = ProgramSet::from_common_events(&events);
        // Common event 63 multiplies every message-window measurement by the
        // coordinate scale, which is one 32nd of the screen width and one 24th of
        // its height (docs/OPCODE_101.md section 3.1); Game.dat owns the screen
        // size, so that value is what the database layer needs.
        let screen = std::fs::read(root.join("Game.dat"))
            .or_else(|_| std::fs::read(basic.join("Game.dat")))
            .ok()
            .and_then(|bytes| GameDat::parse(&bytes).ok())
            .map_or(crate::db::DEFAULT_SCREEN, |dat| {
                let (width, height) = dat.screen_size();
                (u32::from(width), u32::from(height))
            });
        let databases = Databases::load(&basic, screen);
        let tilesets = std::fs::read(basic.join("TileSetData.dat"))
            .ok()
            .and_then(|bytes| TileSetData::parse(&bytes).ok());
        // System.sav is a complete save file in this game: use it as the template so a
        // brand-new game can write its first save without inventing part1/part4.
        let base_save = crate::savegame::read_save(&root.join("Save").join("System.sav")).ok();
        let auto_events = AutoEvents::from_common_events(&events);
        Ok(Self {
            vm: Vm::new(programs),
            screen: Screen::new(),
            screen_tint: ScreenTint::new(),
            screen_transition: ScreenTransition::new(),
            font_metrics: None,
            tilemap: None,
            tilesets,
            assets: Assets::new(&root),
            databases,
            key_bits: 0,
            sounds: Vec::new(),
            audio: None,
            messages: Vec::new(),
            choices: None,
            stats: GameStats::default(),
            diagnostics: BTreeMap::new(),
            replies: std::collections::VecDeque::new(),
            auto_advance: false,
            auto_choice: false,
            auto_choice_delay: 0,
            runtime: MapRuntime::new(),
            auto_events,
            playtime_frames: 0,
            mouse: [-1, -1],
            mouse_buttons: 0,
            choice_cursor: 0,
            previous_keys: 0,
            previous_mouse_buttons: 0,
            engine_always: None,
            engine_events_started: false,
            save_requests: Vec::new(),
            map_requests: Vec::new(),
            base_save,
            root,
        })
    }

    /// The data root this game was created from.
    #[must_use]
    pub fn root(&self) -> &Path {
        &self.root
    }

    /// Turns on real audio output (M4). Safe on a machine with no device -- the engine
    /// degrades to a silent null backend -- and idempotent. Tests leave audio off because
    /// [`Self::new`] defaults to `None`.
    pub fn enable_audio(&mut self) {
        self.audio = Some(wolf_audio::Engine::with_asset_root(self.root.clone()));
    }

    /// Installs real glyph advances for text-picture layout. Returns false when the blob
    /// is not a usable font, in which case the half-em fallback stays in place.
    pub fn set_font_metrics(&mut self, bytes: Vec<u8>) -> bool {
        self.font_metrics = crate::fontmetrics::FontMetrics::load(bytes);
        self.font_metrics.is_some()
    }

    /// Frames of play time, as a save file stores them.
    #[must_use]
    pub fn playtime_frames(&self) -> u32 {
        self.playtime_frames
    }

    /// Replaces the play-time clock, used when a save is loaded.
    pub fn set_playtime_frames(&mut self, frames: u32) {
        self.playtime_frames = frames;
    }

    /// Writes the live game state to a save file.
    ///
    /// The map snapshot and object tables come from the base_save field (the save this
    /// game was loaded from, or System.sav for a new game); the pieces that change while
    /// playing are copied from the VM: play time, the Sys3/Sys4 choice anchor, the 800
    /// normal variables, and the self variables / self strings of every live common-event
    /// coroutine. Returns the number of encrypted bytes written.
    ///
    /// # Errors
    ///
    /// Fails when no template save is available or when a part cannot be encoded.
    pub fn save_to(&mut self, path: &Path) -> Result<usize, String> {
        let Some(mut save) = self.base_save.clone() else {
            return Err("220 SaveLoad: no template save (Save/System.sav is missing)".to_string());
        };

        let mut part2 = save.part2.clone();
        part2.vars3_21[0] = self.playtime_frames;
        part2.vars3_21[9] = self.vm.vars.get_sys(3) as u32;
        part2.vars3_21[10] = self.vm.vars.get_sys(4) as u32;
        save.set_part2(&part2)
            .map_err(|err| format!("220 SaveLoad: cannot encode part2: {err}"))?;

        let mut part3 = save.part3.clone();
        for index in 0..800 {
            let _ = part3.set_normal_var(index, self.vm.vars.get(index));
        }
        for instance in self.vm.instances() {
            if instance.program.self_base != wolf_vm::program::COMMON_SELF_BASE {
                continue;
            }
            let event = instance.event;
            for slot in 0..100 {
                let value = instance.self_vars.get(instance.program.self_base + slot);
                let _ = part3.set_self_var(event, slot, value);
            }
            for slot in 0..5 {
                let text = instance
                    .self_vars
                    .get_str(instance.program.self_base + 5 + slot);
                let _ = part3.set_self_string(event, slot, text);
            }
        }
        save.set_part3(&part3)
            .map_err(|err| format!("220 SaveLoad: cannot encode part3: {err}"))?;

        // The picture table is the frame the player saved on. Rebuilding it from the live
        // Screen (rather than keeping the template Part5) is what makes a saved game look
        // like the scene the player was in when they pressed save.
        let part5 = crate::savegame::part5_from_screen(&self.screen);
        save.set_part5(&part5)
            .map_err(|err| format!("220 SaveLoad: cannot encode part5: {err}"))?;

        // Runtime 250 writes live in the database layer, not in the interpreter banks, so
        // they have to be folded into the save variable database before the file is built.
        let (written, missed) = self.databases.write_into(&mut save.vardb);
        if missed > 0 {
            let text = format!(
                "220 SaveLoad: {written} database cell(s) written, {missed} cell(s) could not be encoded"
            );
            *self.diagnostics.entry(text).or_insert(0) += 1;
            self.stats.unmodelled += 1;
        }

        let bytes = save
            .to_bytes_rebuilt()
            .map_err(|err| format!("220 SaveLoad: cannot rebuild save: {err}"))?;
        if let Some(parent) = path.parent() {
            std::fs::create_dir_all(parent).map_err(|err| {
                format!("220 SaveLoad: cannot create {}: {err}", parent.display())
            })?;
        }
        std::fs::write(path, &bytes)
            .map_err(|err| format!("220 SaveLoad: cannot write {}: {err}", path.display()))?;
        self.base_save = Some(save);
        Ok(bytes.len())
    }

    /// Starts one common event as a coroutine. Returns false when the id is unknown.
    pub fn start_event(&mut self, id: u32) -> bool {
        self.vm.start_event(id).is_some()
    }

    /// Starts the coroutines the runtime owns rather than the script.
    ///
    /// Idempotent: a map change re-enters it and must not spawn a second copy of a
    /// coroutine that is supposed to last the whole session. Returns the number of
    /// instances started this call.
    pub fn start_engine_events(&mut self) -> usize {
        if self.engine_events_started {
            return 0;
        }
        self.engine_events_started = true;
        // The three groups have different lifetimes: ENGINE_ALWAYS lives for the whole
        // session, ENGINE_AUTO_START runs once and ends, ENGINE_IMPLICIT belongs to an
        // engine feature. A future load-game path rebuilds only the first group.
        let mut ids: Vec<u32> = match &self.engine_always {
            Some(ids) => ids.clone(),
            None => ENGINE_ALWAYS.to_vec(),
        };
        ids.extend_from_slice(ENGINE_AUTO_START);
        ids.extend_from_slice(ENGINE_IMPLICIT);
        let mut started = 0;
        for id in ids {
            if self.start_event(id) {
                started += 1;
            }
        }
        // The run_condition == 2 group has no fixed id list: whether each one runs
        // depends on a variable. One pass here starts the ones already true at boot
        // (only event 38 in this game); `Game::frame` keeps them in sync afterwards.
        self.auto_events.sync(&mut self.vm);
        started
    }

    /// Boots the game the way the original does: the autorun event on the title map.
    ///
    /// Common event 42 is *not* the entry point. The measured boot chain is
    /// [`BOOT_MAP`] event 2 -> common event 549 (three splashes) -> a key wait ->
    /// common event 42 (the three-option menu), which is why starting at 42 shows the
    /// menu over a title graphic the original has not drawn yet.
    ///
    /// # Errors
    ///
    /// Fails when the map file is missing or malformed, or when it has no event 2.
    pub fn boot(&mut self) -> Result<(), GameError> {
        self.start_engine_events();
        let bytes = self.read(BOOT_MAP)?;
        let map = Map::parse(&bytes).map_err(GameError::Format)?;
        self.start_pages(&map, Some(BOOT_EVENT));
        if self.start_map_event(&map, BOOT_EVENT) {
            Ok(())
        } else {
            Err(GameError::MissingEvent(BOOT_EVENT))
        }
    }

    /// Starts one map event first page as a coroutine.
    ///
    /// A map page is an ordinary instruction stream, so it compiles through the same
    /// jump-table precompiler the common events use. Only the first page runs: later
    /// pages need the page-switch machinery that M2 adds.
    /// Start every automatic page of `map` and remember them.
    ///
    /// The boot map's own event is started separately by `start_map_event`,
    /// because `BOOT_EVENT` is the title script and must run exactly once
    /// (an autorun page would be started by `MapRuntime` too, and starting it
    /// twice is a behaviour change nobody asked for).
    pub fn start_pages(&mut self, map: &Map, skip: Option<u32>) -> usize {
        self.tilemap = match &self.tilesets {
            Some(sets) => sets
                .get(map.tileset_index)
                .map(|tileset| TileMap::new(map, tileset, sets.version)),
            None => None,
        };
        self.runtime = MapRuntime::collect_except(map, skip);
        self.runtime.start_pending(&mut self.vm)
    }

    /// Builds the tile-layer quads for the current map.
    ///
    /// This is the layer WOLF draws before every picture. It is empty for a map with no
    /// tile data and for a game whose TileSetData.dat is absent, which keeps headless
    /// event-only runs working exactly as before.
    pub fn tile_quads(&mut self, atlas: &mut Atlas) -> Vec<SpriteQuad> {
        let Some(tilemap) = self.tilemap.as_ref() else {
            return Vec::new();
        };
        // The camera is fixed at the map origin: all playable maps in this game fit the
        // 1024x576 viewport at their origin, and Sys 104/105 are engine scroll *outputs*
        // with no script state behind them (docs/HANDOFF_M3.md section 5).
        let mut quads = tilemap.quads(
            atlas,
            &mut self.assets,
            [0, 0],
            [crate::picture::SCREEN_W, crate::picture::SCREEN_H],
            self.playtime_frames,
        );
        self.apply_screen_tint(&mut quads, false);
        self.drain_asset_fallbacks();
        quads
    }

    /// Pictures to draw this frame, with the screen colour multiplier baked in.
    ///
    /// `151 ChangeColor` tints the map and every negative-numbered (screen-layer) picture,
    /// not the HUD. Baking the multiplier into each quad's tint is exact because the frame
    /// is drawn with linear alpha blending, and it is what makes the effect appear in
    /// `capture` output, which reads the composited frame texture.
    pub fn picture_quads(&mut self, atlas: &mut Atlas) -> Vec<SpriteQuad> {
        let mut quads = atlas.sprites(&self.screen, &mut self.assets);
        self.apply_screen_tint(&mut quads, true);
        self.drain_asset_fallbacks();
        quads
    }

    /// The `151` colour multiplier as RGB, `[1, 1, 1]` when nothing is tinting the screen.
    #[must_use]
    pub fn screen_tint_rgb(&self) -> [f32; 3] {
        self.screen_tint.rgb()
    }

    /// Folds any asset-name fallbacks taken while building this frame into diagnostics.
    ///
    /// Keeps the workaround (e.g. the `Picture/word_effect*` typo) visible in the same
    /// `1x ...` diagnostic stream every other note uses, instead of silently succeeding.
    fn drain_asset_fallbacks(&mut self) {
        for message in self.assets.take_fallbacks() {
            *self.diagnostics.entry(message).or_insert(0) += 1;
        }
    }

    /// Multiplies each quad's tint by the screen tint and the transition fade.
    ///
    /// The 151 tint only touches the map and the negative-numbered screen-layer
    /// pictures (`screen_layers_only`); the 160/162 transition fade is a whole-screen
    /// overlay, so it dims *every* quad including the HUD, exactly as a screen wipe
    /// would. Both are skipped while neutral so the common case stays a no-op.
    fn apply_screen_tint(&self, quads: &mut [SpriteQuad], screen_layers_only: bool) {
        let tint = self.screen_tint.rgb();
        let tint_on = tint != [1.0, 1.0, 1.0];
        let fade = self.screen_transition.brightness();
        let fade_on = fade < 1.0;
        if !tint_on && !fade_on {
            return;
        }
        for quad in quads {
            if tint_on && (!screen_layers_only || quad.number < 0) {
                quad.tint[0] *= tint[0];
                quad.tint[1] *= tint[1];
                quad.tint[2] *= tint[2];
            }
            if fade_on {
                quad.tint[0] *= fade;
                quad.tint[1] *= fade;
                quad.tint[2] *= fade;
            }
        }
    }

    /// Switches to the map at `path` and starts its automatic pages.
    ///
    /// `130 Teleport` runs on the same VM, so the current map coroutines are stopped
    /// first: leaving them alive would keep a previous map parallel events
    /// drawing into the new map. Engine events are session-wide and keep running.
    fn switch_map(&mut self, path: &str) -> Result<(), GameError> {
        self.runtime.stop_all(&mut self.vm);
        // Whole-screen layers belong to the map that drew them. The new map's
        // events rebuild whatever overlay it needs; leaving the old map's title
        // art in the negative slots painted it on top of the new scene.
        self.screen.clear_screen_layers();
        let bytes = self.read(path)?;
        let map = Map::parse(&bytes).map_err(GameError::Format)?;
        self.start_pages(&map, None);
        Ok(())
    }

    /// Start one event of a named map, collecting that map's other pages too.
    ///
    /// This is what a new game does once the title menu answers: it switches to
    /// SampleMapA and runs event 0, the opening story script. The event itself
    /// is skipped by the page collector so its coroutine is only started once.
    ///
    /// # Errors
    ///
    /// Fails when the map file is missing or malformed, or when the map has no
    /// event with that id.
    pub fn start_map_event_by_name(
        &mut self,
        map_name: &str,
        event_id: u32,
    ) -> Result<(), GameError> {
        self.start_engine_events();
        let name = if map_name.contains('.') {
            map_name.to_owned()
        } else {
            format!("MapData/{map_name}.mps")
        };
        let bytes = self.read(&name)?;
        let map = Map::parse(&bytes).map_err(GameError::Format)?;
        self.start_pages(&map, Some(event_id));
        if self.start_map_event(&map, event_id) {
            Ok(())
        } else {
            Err(GameError::MissingEvent(event_id))
        }
    }

    pub fn start_map_event(&mut self, map: &Map, event_id: u32) -> bool {
        let Some(event) = map.events.iter().find(|event| event.id == event_id) else {
            return false;
        };
        let Some(page) = event.pages.first() else {
            return false;
        };
        let program = Program::from_slots(event.id, &event.name, page.commands.clone());
        self.vm.start_program(Arc::new(program)).is_some()
    }

    fn read(&self, name: &str) -> Result<Vec<u8>, GameError> {
        let relative: std::path::PathBuf = name.split('/').collect();
        let path = self.root.join(relative);
        std::fs::read(&path).map_err(|source| GameError::Io { path, source })
    }

    /// Starts the title screen event.
    ///
    /// # Errors
    ///
    /// Fails when this build has no event 42.
    pub fn start_title(&mut self) -> Result<(), GameError> {
        if self.start_event(TITLE_EVENT) {
            Ok(())
        } else {
            Err(GameError::MissingEvent(TITLE_EVENT))
        }
    }

    /// Queues an answer for the next choice prompt.
    pub fn reply(&mut self, reply: ChoiceReply) {
        self.replies.push_back(reply);
    }

    /// Highlighted option of the current choice prompt (0 when none is open).
    #[must_use]
    pub fn choice_cursor(&self) -> usize {
        self.choice_cursor
    }

    /// Where the engine puts the current choice window, from system variables 3 (X) and
    /// 4 (Y).
    ///
    /// WOLF has no centred default: [`102`] paints its window at exactly these two
    /// numbers (docs/OPCODE_102.md). The title event sets them to (512, 1000), which is
    /// why the original title screen shows no menu box at all.
    #[must_use]
    pub fn choice_anchor(&self) -> (i32, i32) {
        (self.vm.vars.get_sys(3), self.vm.vars.get_sys(4))
    }

    /// Which option row contains a screen point, when the prompt is open and visible.
    ///
    /// The geometry is [`choice::layout_at_sized`], the same one the renderer draws, so a
    /// click lands on the row the player sees. The original drives every menu with the
    /// mouse - the title hint line literally reads 通过鼠标进行选择，点击进行确定和取消 -
    /// and this hit test is what makes a click mean the same thing in the port.
    #[must_use]
    pub fn choice_row_at(&self, x: i32, y: i32) -> Option<usize> {
        let choices = self.choices.as_ref()?;
        let (anchor_x, anchor_y) = self.choice_anchor();
        let layout = crate::choice::layout_at_sized(
            &choices.options,
            self.choice_cursor,
            anchor_x,
            anchor_y,
            self.font_px(),
        )?;
        let (px, py) = (x as f32, y as f32);
        layout.lines.iter().position(|line| {
            px >= line[0] && px < line[0] + line[2] && py >= line[1] && py < line[1] + line[3]
        })
    }
    /// One system variable by index, for diagnostics and for the layout laws that read
    /// engine state directly (the choice window's margins, the cursor mode).
    #[must_use]
    pub fn sys(&self, index: usize) -> i32 {
        self.vm.vars.get_sys(index)
    }

    /// The engine's font size, from Sys8.
    ///
    /// WOLF shares one font size between 文章の表示, 選択肢 and ピクチャ text (work/yado.txt
    /// lines 56-79), and common event 48 writes Sys8 = 20 during its system-initialisation
    /// branch, so every text path must read it from the VM instead of hard-coding a size.
    /// A value outside 8..=64 falls back to crate::message::DEFAULT_FONT_PX: Sys8 is 0
    /// before event 48 runs, and a negative or absurd size would shred the layout.
    #[must_use]
    pub fn font_px(&self) -> f32 {
        let size = self.vm.vars.get_sys(8);
        if (8..=64).contains(&size) {
            size as f32
        } else {
            crate::message::DEFAULT_FONT_PX
        }
    }

    /// The message-window system variables, as the engine reads them.
    ///
    /// WOLF keeps message geometry in system variables 1, 2, 5, 6, 8, 9 and 10, and
    /// common event 63 initialises them on the engine behalf before every message. The
    /// wrap width comes from the frame picture that same event paints
    /// (message::FRAME_PICTURE), so the text laid out here and the frame drawn by the
    /// script agree on the box; when the frame is not up yet the screen edge is the bound.
    #[must_use]
    pub fn message_vars(&self) -> crate::message::Vars {
        let sys = |index: usize| self.vm.vars.get_sys(index);
        let (cursor_x, cursor_y) = (sys(5), sys(6));
        let cursor_offset = if cursor_x >= 0 && cursor_y >= 0 {
            Some((cursor_x as f32, cursor_y as f32))
        } else {
            None
        };
        // The frame is an ordinary window-type draw (common event 63, picture slot
        // 19500), so when it is live its own right edge is the wrap box; the fallback
        // in `Vars::wrap_width` is the screen edge, the documented hard cap.
        let width = self
            .screen
            .get(crate::message::FRAME_PICTURE)
            .and_then(|frame| {
                let (window_w, window_h) = frame.window?;
                if window_w <= 0 {
                    return None;
                }
                let rect = frame.destination(window_w as f32, window_h.max(0) as f32);
                Some((rect[0] + rect[2] - sys(1) as f32).max(0.0))
            });
        crate::message::Vars {
            x: sys(1) as f32,
            y: sys(2) as f32,
            font_px: sys(8) as f32,
            chars_per_second: sys(9),
            preroll: sys(10),
            width,
            cursor_offset,
            screen_w: crate::picture::SCREEN_W as f32,
        }
    }

    /// The newest 101 message, laid out with its inline styling.
    ///
    /// Colour escapes resolve through the SysDatabase palette the same way text
    /// pictures do; the plain [crate::message::layout] would drop the colour and
    /// outline escapes and fold every glyph into one Sys8-sized run.
    #[must_use]
    pub fn message_layout(&self) -> Option<crate::message::Layout> {
        let message = self.messages.last()?;
        let vars = self.message_vars();
        let colours = PictureColours {
            databases: &self.databases,
        };
        Some(crate::message::layout_styled(
            &message.text,
            &vars,
            message.frames,
            &colours,
        ))
    }

    /// Preselects an option of the current choice prompt.
    ///
    /// Headless captures use this together with [`Self::auto_choice`] to take a
    /// specific branch without a keyboard.
    /// Every text picture, laid out into one quad per style run.
    ///
    /// A `150` text picture carries its own display markup and the HUD depends on all
    /// of it: the top bar writes `18:30` at 24 px beside `周一` at 18 px, the money
    /// counter right-aligns against x = 1015, and 877 pictures ask for the `\E` outline.
    /// [`crate::atlas::texts`] paints one default-sized quad per picture and cannot
    /// reproduce any of that; this is the markup-aware path the renderer uses.
    #[must_use]
    pub fn text_quads(&self) -> Vec<crate::atlas::TextQuad> {
        let vars = PictureVars {
            vars: &self.vm.vars,
        };
        let cells = PictureCells {
            databases: &self.databases,
        };
        let colours = PictureColours {
            databases: &self.databases,
        };
        let ctx = crate::textpic::Ctx {
            vars: &vars,
            cells: &cells,
            colours: &colours,
            default_font_px: self.font_px(),
        };
        let mut quads = Vec::new();
        for picture in self.screen.iter() {
            if !picture.kind.is_text() || picture.hidden || picture.text.is_empty() {
                continue;
            }
            let runs = if let Some(metrics) = &self.font_metrics {
                let advance = |ch: char, px: f32| metrics.advance(ch, px);
                crate::textpic::layout_with(
                    &picture.text,
                    picture.x as f32,
                    picture.y as f32,
                    picture.anchor,
                    &ctx,
                    &advance,
                )
            } else {
                crate::textpic::layout(
                    &picture.text,
                    picture.x as f32,
                    picture.y as f32,
                    picture.anchor,
                    &ctx,
                )
            };
            let alpha = picture.alpha();
            for run in runs {
                if run.text.is_empty() {
                    continue;
                }
                // The balloon library keeps its controls parked far off screen;
                // shaping and drawing them costs time and cannot reach a pixel.
                if !crate::picture::on_screen([run.x, run.y, run.font_px, run.font_px * 2.0]) {
                    continue;
                }
                // The box only has to be wide enough that the glyph pass never
                // re-wraps what the layout already broke; one extra em of slack
                // covers the shaped advance being a few percent off the half-em rule.
                let width = if let Some(metrics) = &self.font_metrics {
                    let advance = |ch: char, px: f32| metrics.advance(ch, px);
                    crate::textpic::measure_with(&run.text, run.font_px, &advance) + run.font_px
                } else {
                    crate::textpic::measure(&run.text, run.font_px) + run.font_px
                };
                quads.push(crate::atlas::TextQuad {
                    number: picture.number,
                    text: run.text,
                    rect: [
                        run.x,
                        run.y,
                        width.max(1.0),
                        run.font_px * crate::textpic::DEFAULT_LINE_PITCH_RATIO,
                    ],
                    alpha,
                    font_px: run.font_px,
                    colour: crate::textpic::rgb(&ctx, run.colour).unwrap_or([255, 255, 255]),
                    outline: run.outline,
                });
            }
        }
        quads
    }

    /// Loads a WOLF save file: normal variables, the choice anchor and the whole picture
    /// layer. The script state is deliberately left alone - `220` load is driven by the
    /// save-menu coroutine, which keeps running after the load and is what restarts the
    /// map; a bare capture only needs the screen and the variables.
    pub fn load_save(&mut self, path: &Path) -> Result<crate::savegame::LoadedSave, String> {
        crate::savegame::load_into(self, path)
    }

    pub fn set_choice_cursor(&mut self, index: usize) {
        self.choice_cursor = index;
    }

    /// Applies this frame's key state to the open choice prompt, if there is one.
    ///
    /// WOLF's runtime owns choice navigation: opcode 102 hands the runtime a list of
    /// options and blocks the coroutine, and the runtime is what moves the cursor and
    /// returns an index. The port has to do the same, otherwise a script that opens a
    /// menu simply stops - the measured title screen does exactly that, advancing 45
    /// instructions and then waiting forever.
    fn handle_choice_input(&mut self) {
        let Some(count) = self.choices.as_ref().map(|choices| choices.options.len()) else {
            self.choice_cursor = 0;
            return;
        };
        if count == 0 {
            return;
        }
        // A left click on a row both highlights and confirms it. WOLF's menu windows are
        // mouse-first, so without this the port would only answer to the keyboard.
        let clicked = self.mouse_buttons & 1 != 0 && self.previous_mouse_buttons & 1 == 0;
        if clicked {
            if let Some(row) = self.choice_row_at(self.mouse[0], self.mouse[1]) {
                self.reply(ChoiceReply::Index(row));
                self.choice_cursor = 0;
                return;
            }
        }
        // Only fresh presses count: holding a key must not scroll a menu at 60 steps a
        // second, which is what a level-triggered read would do.
        let pressed = self.key_bits & !self.previous_keys;
        if pressed & crate::key::UP != 0 {
            self.choice_cursor = (self.choice_cursor + count - 1) % count;
        }
        if pressed & crate::key::DOWN != 0 {
            self.choice_cursor = (self.choice_cursor + 1) % count;
        }
        self.choice_cursor = self.choice_cursor.min(count - 1);
        if pressed & crate::key::OK != 0 {
            self.reply(ChoiceReply::Index(self.choice_cursor));
            self.choice_cursor = 0;
        } else if pressed & crate::key::CANCEL != 0 {
            self.reply(ChoiceReply::Cancel);
            self.choice_cursor = 0;
        }
    }

    /// Advances one frame at 1/60 s.
    pub fn frame(&mut self) -> FrameOutcome {
        self.sounds.clear();
        // Start or stop the conditional background events before anything runs, so a
        // condition that became true last frame is running now (docs/ENGINE_EVENTS.md
        // section 2.2). This is edge-triggered: a condition that stays true does not
        // restart a coroutine that already ended on its own.
        self.auto_events.sync(&mut self.vm);
        self.handle_choice_input();
        let mut report = self.vm.step_frame(&mut GameHost {
            screen: &mut self.screen,
            screen_tint: &mut self.screen_tint,
            screen_transition: &mut self.screen_transition,
            assets: &mut self.assets,
            databases: &mut self.databases,
            sounds: &mut self.sounds,
            audio: self.audio.as_mut(),
            messages: &mut self.messages,
            choices: &mut self.choices,
            replies: &mut self.replies,
            diagnostics: &mut self.diagnostics,
            stats: &mut self.stats,
            key_bits: self.key_bits,
            auto_advance: self.auto_advance,
            auto_choice: self.auto_choice,
            auto_choice_delay: self.auto_choice_delay,
            cursor: self.choice_cursor,
            mouse: self.mouse,
            mouse_buttons: self.mouse_buttons,
            previous_mouse_buttons: self.previous_mouse_buttons,
            root: &self.root,
            save_requests: &mut self.save_requests,
            map_requests: &mut self.map_requests,
        });
        // A `220` load replaces the picture layer and the normal variables, so it runs
        // as soon as the VM step that requested it has released its borrow of `Game`.
        let requests = std::mem::take(&mut self.save_requests);
        for request in requests {
            match request {
                crate::savegame::SaveRequest::Load(path) => {
                    match crate::savegame::load_into(self, &path) {
                        Ok(loaded) => {
                            self.diagnostics.insert(
                                format!(
                                    "220 SaveLoad: loaded {} picture(s), {} variable(s)",
                                    loaded.pictures, loaded.normal_vars
                                ),
                                1,
                            );
                        }
                        Err(err) => {
                            self.diagnostics
                                .entry(format!("220 SaveLoad: {err}"))
                                .or_insert(0);
                        }
                    }
                }
                crate::savegame::SaveRequest::Save(path) => match self.save_to(&path) {
                    Ok(bytes) => {
                        self.diagnostics
                            .insert(format!("220 SaveLoad: wrote {bytes} byte(s)"), 1);
                    }
                    Err(err) => {
                        self.diagnostics.entry(err).or_insert(0);
                    }
                },
            }
        }
        // A `130` teleport queues a map switch for the same reason a `220` load does:
        // the host cannot borrow Game while the VM is inside `step_frame`.
        let map_requests = std::mem::take(&mut self.map_requests);
        for request in map_requests {
            // `130` already carries the destination map id; there is no
            // "-1 keeps the current map" convention (that is `150`).
            let path = self.databases.map_path(request.map).map(str::to_owned);
            let Some(path) = path else {
                self.diagnostics.insert(
                    format!("130 Teleport: no map registered for id {}", request.map),
                    1,
                );
                continue;
            };
            match self.switch_map(&path) {
                Ok(()) => {
                    self.diagnostics.insert(
                        format!(
                            "130 Teleport: {} at ({}, {}) target {} options {:#x}",
                            path, request.x, request.y, request.target, request.options
                        ),
                        1,
                    );
                }
                Err(err) => {
                    self.diagnostics.insert(format!("130 Teleport: {err}"), 1);
                }
            }
        }
        // One more frame of play time; the save stores this in SavePart2.vars3_21[0].
        self.playtime_frames = self.playtime_frames.saturating_add(1);
        // Age the UI state after the VM ran, so a message shown this frame is 0 frames old.
        for message in &mut self.messages {
            message.frames = message.frames.saturating_add(1);
        }
        if let Some(choices) = &mut self.choices {
            choices.frames = choices.frames.saturating_add(1);
        }
        self.screen.tick();
        // Slides (150 Move with a duration tail) live on the same screen and advance
        // one frame at a time, so they are stepped with the fades rather than the VM.
        self.screen.advance();
        // A `151 ChangeColor` ramp advances one frame at a time, alongside the picture
        // slides it shares the screen with.
        self.screen_tint.tick();
        // A `160`/`162` transition fade advances one frame at a time on the same clock.
        self.screen_transition.tick();
        // Sys12 (文章の表示 実行中？) is the engine's flag, not a script variable: a
        // scan of all 550 common events finds 7 reads and zero writes, and common
        // event 63 polls it every frame to decide whether to paint or erase the
        // message-window frame. Publishing it one frame late is invisible at 60 Hz and
        // keeps the borrow of the VM out of the host shim.
        self.vm
            .vars
            .set_sys(12, i32::from(!self.messages.is_empty()));
        self.previous_keys = self.key_bits;
        // Automatic pages are restarted here, i.e. at the end of a frame, so a
        // parallel page that just ended comes back on the next tick.
        self.runtime.start_pending(&mut self.vm);
        self.previous_mouse_buttons = self.mouse_buttons;
        self.stats.frames += 1;
        self.stats.instructions += report.steps as u64;
        self.stats.peak_instances = self.stats.peak_instances.max(report.running);
        let outcome = FrameOutcome {
            pictures: self.screen.len(),
            sounds: self.sounds.len(),
            // A coroutine parked on a menu is alive but does no work, and that is what
            // a renderer needs to know: idle means this frame executed nothing.
            idle: report.steps == 0,
            report: StepReport::default(),
        };
        report.notes.clear();
        // Keep the interpreter note list empty: everything worth keeping went through
        // Host::log, which deduplicates. A per-frame Vec would otherwise grow forever.
        FrameOutcome { report, ..outcome }
    }
}

fn read_events(path: &Path) -> Result<CommonEventData, GameError> {
    let bytes = std::fs::read(path).map_err(|source| GameError::Io {
        path: path.to_path_buf(),
        source,
    })?;
    CommonEventData::parse(&bytes).map_err(GameError::Format)
}

/// One `250` write operator, `(flags >> 4) & 7` (docs/OPCODE_250.md section 3.1).
///
/// 0 assign / 1 add / 2 sub / 3 mul / 4 div / 5 rem / 6 max / 7 min. The money and
/// HP clamp idiom is add, then max with 0, then min with the cap. Division and
/// remainder by zero leave the cell alone, the same rule opcode 121 follows.
fn combine_cell(op: u8, current: i32, operand: i32) -> i32 {
    match op {
        1 => current.wrapping_add(operand),
        2 => current.wrapping_sub(operand),
        3 => current.wrapping_mul(operand),
        4 if operand != 0 => current / operand,
        4 => current,
        5 if operand != 0 => current % operand,
        5 => current,
        6 => current.max(operand),
        7 => current.min(operand),
        _ => operand,
    }
}

/// Read one `221` address out of a parsed save file.
///
/// Addresses use the same magic banks as the running VM: `2_000_000+n` is normal
/// variable `n`, `1_600_000+n` is self variable `n` of the *calling* event, and
/// `9_000_000+n` is system variable `n`. `Sys24` is the save-existence flag the
/// menu probes before it offers a slot; `Sys29` is the play time in seconds.
fn save_address(save: &wolf_save::SaveFile, op: &SaveOp) -> Option<i32> {
    match op.address {
        2_000_000..=2_999_999 => save.normal_var((op.address - 2_000_000) as usize),
        1_600_000..=1_699_999 => save.self_var(op.owner, (op.address - 1_600_000) as usize),
        9_000_000..=9_099_999 => {
            let index = (op.address - 9_000_000) as usize;
            match index {
                24 => Some(1),
                29 => save.playtime_frames().map(|frames| (frames / 60) as i32),
                0..=12 => save
                    .part2
                    .vars3_21
                    .get(index + 6)
                    .map(|value| *value as i32),
                _ => None,
            }
        }
        _ => None,
    }
}

/// Write one `222` value into a parsed save file, returning false for an address
/// outside every bank.
fn write_save_address(save: &mut wolf_save::SaveFile, op: &SaveOp) -> bool {
    match op.address {
        2_000_000..=2_999_999 => save
            .set_normal_var((op.address - 2_000_000) as usize, op.value)
            .unwrap_or(false),
        1_600_000..=1_699_999 => save
            .set_self_var(op.owner, (op.address - 1_600_000) as usize, op.value)
            .unwrap_or(false),
        9_000_000..=9_099_999 => {
            let index = (op.address - 9_000_000) as usize;
            match index {
                29 => save
                    .set_playtime_frames(op.value.max(0) as u32 * 60)
                    .is_ok(),
                0..=12 => {
                    if let Some(cell) = save.part2.vars3_21.get_mut(index + 6) {
                        *cell = op.value.max(0) as u32;
                        true
                    } else {
                        false
                    }
                }
                _ => false,
            }
        }
        _ => false,
    }
}

/// One `250` cell read: numeric columns answer as numbers, string columns as text.
///
/// `None` means the cell does not exist in the addressed table, which is the signal
/// that the numeric type id the script carried drifted and the labels must decide.
fn lookup_cell(
    databases: &crate::db::Databases,
    container: crate::db::Container,
    db_type: i32,
    row: i32,
    column: i32,
) -> Option<DbValue> {
    databases
        .num(container, db_type, row, column)
        .map(DbValue::Num)
        .or_else(|| {
            databases
                .text(container, db_type, row, column)
                .map(|text| DbValue::Str(text.to_owned()))
        })
}

/// Resolves a `250` cell through its editor labels and counts the saves.
///
/// The eight `システム設定` / `装備可能欄数` reads pass type 18 column 22 and mean
/// `DataBase` type 17 column 22 (value 5); without this fallback they answer nothing and
/// the scripts behave as if the player had zero equipment slots.
fn resolve_cell(
    databases: &crate::db::Databases,
    stats: &mut GameStats,
    op: &DbOp,
    container: crate::db::Container,
) -> (i32, i32) {
    let numeric = (op.db_type, op.item_id);
    let resolved = databases.resolve_labels(
        container,
        op.db_type,
        op.item_id,
        op.type_label.as_deref(),
        op.field_label.as_deref(),
    );
    if resolved != numeric {
        stats.database_labels += 1;
    }
    resolved
}

/// [`crate::textpic::Vars`] over the global variable banks.
///
/// `\v[n]` and `\s[n]` in a picture string were already expanded by the interpreter
/// (it owns the running instance, so `\cself` needs no help here); this is the
/// fallback for a string the expander could not resolve.
struct PictureVars<'a> {
    vars: &'a wolf_vm::Variables,
}

impl crate::textpic::Vars for PictureVars<'_> {
    fn num(&self, index: usize) -> i32 {
        self.vars.get(wolf_vm::magic::VAR_BASE as usize + index)
    }

    fn text(&self, index: usize) -> String {
        let raw = self.vars.get_str(wolf_vm::magic::STR_BASE as usize + index);
        if raw.is_empty() {
            self.num(index).to_string()
        } else {
            raw.to_owned()
        }
    }
}

/// [`crate::textpic::Cells`] over the loaded databases.
struct PictureCells<'a> {
    databases: &'a crate::db::Databases,
}

impl crate::textpic::Cells for PictureCells<'_> {
    fn cdb(&self, ty: i32, row: i32, column: i32) -> Option<String> {
        self.databases
            .text(crate::db::Container::CData, ty, row, column)
            .map(str::to_owned)
    }

    fn udb(&self, ty: i32, row: i32, column: i32) -> Option<String> {
        self.databases
            .text(crate::db::Container::Data, ty, row, column)
            .map(str::to_owned)
    }
}

/// [`crate::textpic::Colours`] over the SystemDB palette.
struct PictureColours<'a> {
    databases: &'a crate::db::Databases,
}

impl crate::textpic::Colours for PictureColours<'_> {
    fn colour(&self, index: i32) -> Option<[u8; 3]> {
        self.databases.colour(index)
    }
}

impl crate::message::Colours for PictureColours<'_> {
    fn colour(&self, index: u32) -> Option<[u8; 3]> {
        self.databases.colour(index as i32)
    }
}

/// Per-frame borrow shim: the VM lives inside Game, so the host cannot borrow Game.
struct GameHost<'a> {
    screen: &'a mut Screen,
    screen_tint: &'a mut ScreenTint,
    screen_transition: &'a mut ScreenTransition,
    assets: &'a mut Assets,
    databases: &'a mut crate::db::Databases,
    sounds: &'a mut Vec<SoundCmd>,
    /// M4: the real audio engine, when [`Game::enable_audio`] turned it on. `None` keeps
    /// `Host::sound` a pure recorder (tests, headless captures).
    audio: Option<&'a mut wolf_audio::Engine>,
    messages: &'a mut Vec<Message>,
    choices: &'a mut Option<Choices>,
    replies: &'a mut std::collections::VecDeque<ChoiceReply>,
    diagnostics: &'a mut BTreeMap<String, u64>,
    stats: &'a mut GameStats,
    key_bits: u32,
    auto_advance: bool,
    auto_choice: bool,
    auto_choice_delay: u32,
    cursor: usize,
    mouse: [i32; 2],
    mouse_buttons: u32,
    previous_mouse_buttons: u32,
    root: &'a Path,
    save_requests: &'a mut Vec<crate::savegame::SaveRequest>,
    map_requests: &'a mut Vec<MapRequest>,
}

impl GameHost<'_> {
    fn note(&mut self, text: String) {
        *self.diagnostics.entry(text).or_insert(0) += 1;
        self.stats.unmodelled += 1;
    }

    /// Resolve a `220`/`221`/`222` file operand. A slot is one-based and maps to
    /// `Save/SaveDataNN.sav`; an explicit path is relative to the game root.
    fn save_path(&self, file: &SaveTarget) -> std::path::PathBuf {
        match file {
            SaveTarget::Slot(slot) => self
                .root
                .join("Save")
                .join(format!("SaveData{slot:02}.sav")),
            SaveTarget::Path(path) => {
                let path = std::path::PathBuf::from(path);
                if path.is_absolute() {
                    path
                } else {
                    self.root.join(path)
                }
            }
        }
    }

    /// 1 when the pointer is over the picture, 0 when not, -1 when there is no such
    /// picture (docs/OPCODE_124.md field 8).
    ///
    /// The test is a plain axis-aligned box that includes transparent pixels, as the
    /// engine documentation says: a picture hit area is its rectangle, not its alpha.
    fn hover(&mut self, number: i32) -> i32 {
        let Some(picture) = self.screen.get(number) else {
            return -1;
        };
        let scale = f32::from(picture.scale.max(1) as i16) / 100.0;
        let size = match picture.window {
            Some((width, height))
                if width > crate::window::MIN_BOX && height > crate::window::MIN_BOX =>
            {
                (width as f32 * scale, height as f32 * scale)
            }
            _ if picture.is_screen_layer() => (SCREEN_W as f32, SCREEN_H as f32),
            _ => {
                let Some((width, height)) = self.assets.texture_size(&picture.file) else {
                    return -1;
                };
                (width as f32 * scale, height as f32 * scale)
            }
        };
        let mut left = picture.x as f32;
        let mut top = picture.y as f32;
        if picture.anchor == ANCHOR_CENTRE {
            left -= size.0 / 2.0;
            top -= size.1 / 2.0;
        }
        let (px, py) = (self.mouse[0] as f32, self.mouse[1] as f32);
        let inside_screen = self.mouse[0] >= 0
            && self.mouse[1] >= 0
            && px < SCREEN_W as f32
            && py < SCREEN_H as f32;
        let over =
            inside_screen && px >= left && px < left + size.0 && py >= top && py < top + size.1;
        i32::from(over)
    }
}

/// WOLF reports a mouse button as 0 released, 1 held, 2 pressed this frame.
fn mouse_state(held: bool, held_before: bool) -> i32 {
    if !held {
        0
    } else if held_before {
        1
    } else {
        2
    }
}

impl Host for GameHost<'_> {
    fn show_message(&mut self, text: &str, face: Option<i32>) {
        // The engine keeps at most one message window: a new 101 replaces the old
        // text rather than stacking behind it.
        self.messages.clear();
        self.messages.push(Message {
            text: text.to_owned(),
            face,
            frames: 0,
        });
        self.stats.messages += 1;
    }

    fn message_dismissed(&mut self) -> bool {
        // A human dismisses messages with the confirm key; a headless run dismisses them
        // immediately so a scripted capture can walk through a conversation.
        self.auto_advance || self.key_bits & crate::key::OK != 0
    }

    fn close_message(&mut self) {
        self.messages.clear();
    }

    fn show_choices(&mut self, options: &[String]) {
        *self.choices = Some(Choices {
            options: options.to_vec(),
            frames: 0,
        });
        self.stats.choices += 1;
    }

    fn choice_made(&mut self) -> Option<ChoiceReply> {
        if let Some(reply) = self.replies.pop_front() {
            *self.choices = None;
            return Some(reply);
        }
        // A delay of 0 clicks the instant the script asks. Any larger value lets the
        // prompt live for that many frames first, which turns a menu loop into one
        // step per frame instead of a spin that burns the whole frame budget.
        let settled = self
            .choices
            .as_ref()
            .map_or(true, |choices| choices.frames >= self.auto_choice_delay);
        if self.auto_choice && settled {
            *self.choices = None;
            let index = self.cursor;
            return Some(ChoiceReply::Index(index));
        }
        None
    }

    fn picture(&mut self, cmd: &PictureCmd) {
        self.screen.apply(cmd);
        self.stats.pictures += 1;
        // Warm the image cache for file pictures while the frame is running, so the
        // render path never blocks on a decode: by the time the frame ends, every picture
        // on screen already has its size (and usually its pixels) resident.
        if !PictureKind::from_code(cmd.kind).is_text() && !cmd.file.is_empty() {
            let _ = self.assets.texture_size(&cmd.file);
        }
    }

    fn sound(&mut self, cmd: &SoundCmd) {
        self.sounds.push(cmd.clone());
        self.stats.sounds += 1;
        // M4: the VM already decoded opcode 140 into this SoundCmd; the engine does the
        // play/stop with the right volume and loop rules. Silently skipped when audio is
        // off, so headless captures and tests stay deterministic.
        if let Some(audio) = self.audio.as_mut() {
            audio.apply_sound_cmd(cmd);
        }
    }

    fn database(&mut self, op: &DbOp) -> Option<DbValue> {
        self.stats.databases += 1;
        // Which of the three .dat files this addresses is (flags >> 8) & 3, verified on
        // 2,195 labelled sites with no exceptions (docs/OPCODE_250.md section 3.2). The
        // interpreter decodes it, so no flags work is left here.
        let container = crate::db::Container::from(op.container);
        let row = op.data_id;
        // Bit 12 clear means the cell is written, and the operator is (flags >> 4) & 7.
        // A write never hands a value back: the source of truth is the table.
        if op.direction == wolf_vm::DbDirection::Write {
            // A write must land on the labelled cell straight away: writing the numeric
            // pair would create a stray row in the wrong type instead of failing loudly.
            let (db_type, column) = resolve_cell(self.databases, self.stats, op, container);
            // Row -2 is not a row: the operand is the table's new row count and the
            // column is a leftover the editor never clears (docs/OPCODE_250.md
            // section 3.5). CE191 pc30 sets 万能ウィンドウ to 2 and then writes rows 0
            // and 1 by hand; CE157 pc28 sets a table to 0 under the comment 全部消去;
            // every 一覧算出 event empties its scratch table this way before refilling it.
            // Nothing is handed back: the interpreter drops a write's answer.
            if row == crate::db::ROW_COUNT_SET {
                if let Some(DbValue::Num(count)) = op.source.as_ref() {
                    self.databases.set_row_count(container, db_type, *count);
                    self.stats.database_row_counts += 1;
                } else {
                    self.note(format!(
                        "250 RowCount: {container:?} ({db_type}, -2, {column}) carries no count"
                    ));
                }
                return None;
            }
            if column == crate::db::ROW_CLEAR_COLUMN {
                // Column -2 is not a column: clear every field of the addressed row.
                // CE75 pc169 does this under 強制全回復, and the battle copy events
                // CE79/CE143/CE144/CE171 clear each temporary table row before filling it.
                if self.databases.clear_row(container, db_type, row) {
                    self.stats.database_writes += 1;
                } else {
                    self.note(format!(
                        "250 RowClear: {container:?} ({db_type}, {row}) has no such type"
                    ));
                }
                return None;
            }
            match op.source.as_ref() {
                Some(DbValue::Num(operand)) => {
                    // A row the table holds is the base of the arithmetic. A row past the
                    // end -- the 100+n runtime slots, or a row a script grew into -- must
                    // start from zero: reading it through `num` would clamp onto the last
                    // row of the file and, say, add this character's HP to the last one's.
                    let current = self
                        .databases
                        .engine_num(container, db_type, row, column)
                        .or_else(|| {
                            self.databases
                                .row_exists(container, db_type, row)
                                .then(|| self.databases.num(container, db_type, row, column))
                                .flatten()
                        })
                        .unwrap_or(0);
                    let value = combine_cell(op.op, current, *operand);
                    self.databases
                        .set_num(container, db_type, row, column, value);
                    self.stats.database_writes += 1;
                }
                Some(DbValue::Str(text)) => {
                    self.databases
                        .set_text(container, db_type, row, column, text);
                    self.stats.database_writes += 1;
                }
                None => self.note(format!(
                    "250 DatabaseWrite: {container:?} ({db_type}, {row}, {column}) carries no value"
                )),
            }
            return None;
        }
        // Labels are authoritative, not a fallback. The editor numbering drifts from
        // the file's numbering (it counts separator types the .dat does not), and the
        // numeric pair can even hit a *different* table that happens to have a cell at
        // that address: CE105 asks for the party table member 1 as (3, 0, 1), but
        // CDataBase type 3 is 属性耐性, whose row 0 is all 100s. Reading numerically
        // first returned 100 and the status panel was drawn for a non-existent
        // character id. Resolve the labels first; a table without labels simply
        // returns the original pair.
        let (db_type, column) = resolve_cell(self.databases, self.stats, op, container);
        if row == crate::db::ROW_COUNT_QUERY {
            // CE48 pc153 reads (0, -1, 33) as the loop bound over every row of
            // 主人公ステータス; the engine answers with the row count. CE75 pc42 uses the
            // same read on 状態設定 to raise 「状態IDが大きすぎます」.
            let count = self.databases.row_count(container, db_type).unwrap_or(0);
            return Some(DbValue::Num(i32::try_from(count).unwrap_or(i32::MAX)));
        }
        let wants_text = op.destination.is_some_and(|target| {
            (wolf_vm::magic::STR_BASE..wolf_vm::magic::STR_BASE + 1_000_000).contains(&target)
        });
        if column == crate::db::FIRST_EMPTY_COLUMN {
            // CE58 pc10 looks for the first row with no fields set before learning a
            // skill; the engine answers with a row index of this table.
            let row = self
                .databases
                .first_empty_row(container, db_type)
                .unwrap_or(0);
            return Some(DbValue::Num(row));
        }
        if column < 0 {
            // -3 is unverified (CE265/CE267 appear to use it as a row-name lookup). Do
            // not clamp a negative column onto a real field; answer empty and say so.
            self.note(format!(
                "250 DatabaseAccess: {container:?} ({db_type}, {row}, {column}) negative column not modelled"
            ));
            return Some(if wants_text {
                DbValue::Str(String::new())
            } else {
                DbValue::Num(0)
            });
        }
        // The engine cell layer first: it holds what a script wrote and what the save
        // carried, and it is the only place a runtime row (`100 + n`, or a row past a
        // shrunk count) can live.
        if let Some(value) = self.databases.engine_num(container, db_type, row, column) {
            return Some(DbValue::Num(value));
        }
        if let Some(text) = self.databases.engine_text(container, db_type, row, column) {
            return Some(DbValue::Str(text.to_owned()));
        }
        if self.databases.row_exists(container, db_type, row) {
            if let Some(value) = lookup_cell(self.databases, container, db_type, row, column) {
                return Some(value);
            }
        } else if row >= crate::db::EXTENSION_ROW_BASE {
            // `100 + n` battle slots: CE239 reads (0, 100, 0) as a character name while
            // CDataBase type 0 has 17 rows, so no file can answer. An untouched slot is
            // empty rather than missing. The destination decides which empty: a read into
            // a string variable wants "", a numeric one wants 0.
            self.stats.database_slots += 1;
            let wants_text = op.destination.is_some_and(|target| {
                (wolf_vm::magic::STR_BASE..wolf_vm::magic::STR_BASE + 1_000_000).contains(&target)
            });
            return Some(if wants_text {
                DbValue::Str(String::new())
            } else {
                DbValue::Num(0)
            });
        } else if row >= 0 && self.databases.has_runtime_row_count(container, db_type) {
            // A row a run-time `250` row-count shrink dropped (set_row_count keeps the
            // cell layer consistent, so `row_exists` is already false here). The battle
            // copy events clear a temporary table to 0 rows and refill it; a read that
            // still uses an old address must answer EMPTY, not the stale cell the file
            // might still carry -- docs/BATTLE.md section 2.5 only shows the clear, but
            // the engine drops the rows, so a dropped row is absence, not a value.
            // Deliberately gated on a *runtime* count: a row past the file's own height
            // with no shrink stays unanswered, because that is the label-drift signal.
            self.stats.database_row_out_of_range += 1;
            return Some(if wants_text {
                DbValue::Str(String::new())
            } else {
                DbValue::Num(0)
            });
        }
        // A COLUMN past the table's own field count is an EMPTY cell, not a broken
        // label: a field the .dat does not declare cannot hold a value on ANY row, so
        // the row is irrelevant. THIS game was built from a battle template larger than
        // the shipped .dat: 戦闘時一時ステータス has 16 fields (no 装備中の武器/装備中の
        // 防具1..4) and 敵キャラ個体デ—タ has 9 (no 基本命中率/回避率/取得経験値/入手…).
        // The engine answers a Variant default for a field it does not hold, so answer
        // 0/"" and count it apart from the reads that miss because a label truly failed
        // to resolve. A row past the count is deliberately left unanswered (a shrunk or
        // cleared table must not serve a stale value), so this branch is column-only.
        if self
            .databases
            .field_count(container, db_type)
            .is_some_and(|fields| fields > 0 && usize::try_from(column).is_ok_and(|c| c >= fields))
        {
            self.stats.database_out_of_schema += 1;
            return Some(if wants_text {
                DbValue::Str(String::new())
            } else {
                DbValue::Num(0)
            });
        }
        // The labels ride along, because they are the only clue that a drifted type id is
        // the reason the read missed (an unresolvable label means the .project walk lost
        // the record, not that the script is wrong).
        self.note(format!(
            "250 DatabaseAccess: {container:?} ({db_type}, {row}, {column}) flags {:#x} labels {:?}/{:?} unanswered",
            op.flags,
            op.type_label.as_deref().unwrap_or(""),
            op.field_label.as_deref().unwrap_or("")
        ));
        None
    }

    fn move_route(&mut self, target: i32, route: &[wolf_format::command::RouteCommand]) {
        let _ = target;
        self.note(format!(
            "201 SetMoveRoute: {} command(s) not applied (no map layer yet)",
            route.len()
        ));
    }

    fn teleport(&mut self, target: i32, map: i32, x: i32, y: i32, options: i32) {
        self.map_requests.push(MapRequest {
            target,
            map,
            x,
            y,
            options,
        });
    }

    fn change_color(&mut self, colour: i32, frames: i32) {
        // `151` is a whole-screen tint the engine applies to the map and the screen-layer
        // pictures; the store ramps it over `frames` and the renderer multiplies it in.
        self.screen_tint.set(colour, frames);
    }

    fn transition(&mut self, kind: i32, flags: i32) {
        // The low byte of `flags` is the animation length in frames; the engine treats
        // zero as one frame (docs/OPCODE_SPEC.md section 5.20), matching TransitionState.
        let frames = (flags & 0xFF) as u32;
        if kind < 0 {
            // The only shipped call (CE48 pc145) is [-1, 65546]: a hard cut, no mask.
            self.screen_transition.cancel();
            self.note(format!(
                "160/162 Transition: kind {kind} flags {flags} (hard cut, no mask)"
            ));
        } else {
            // 160/161/162 all call this; the last call from 162 restarts the ramp at its
            // first frame, so the fade is timed from the execute and blocked for `frames`.
            self.screen_transition.start(kind, frames);
            self.note(format!(
                "160/162 Transition: kind {kind} flags {flags} (fade {} frame(s))",
                frames.max(1)
            ));
        }
    }

    fn party(&mut self, args: &[i32]) {
        self.note(format!(
            "270 Party: {} argument(s) recorded only",
            args.len()
        ));
    }

    fn scroll(&mut self, args: &[i32]) {
        self.note(format!(
            "281 Scroll: {} argument(s) recorded only",
            args.len()
        ));
    }

    fn effect(&mut self, kind: i32, duration: i32, args: &[i32]) {
        // Colour effects belong to the picture store, not to the interpreter, because they
        // outlive the instruction: a type 5 flash keeps cycling for as long as the picture
        // exists. Everything else is recorded but not drawn - see Screen::effect.
        if !self.screen.effect(kind, duration, args) {
            self.note(format!(
                "290 Effect: kind {kind} for {duration} frame(s) ({} args) not drawn yet",
                args.len()
            ));
        }
    }

    fn save_load(&mut self, op: &SaveOp) -> Option<i32> {
        let path = self.save_path(&op.file);
        match op.opcode {
            220 => {
                if op.mode == 1 {
                    // A full load replaces the screen and every normal variable, so it
                    // cannot run while `Game` is borrowed field-by-field by the VM.
                    // Queue it; `Game::frame` applies it right after the VM step.
                    self.save_requests
                        .push(crate::savegame::SaveRequest::Load(path));
                } else {
                    // A full save needs the map template and every live VM bank, so it
                    // is queued for the same post-step slot as a load.
                    self.save_requests
                        .push(crate::savegame::SaveRequest::Save(path));
                }
                None
            }
            221 => match crate::savegame::read_save(&path) {
                Ok(save) => Some(save_address(&save, op).unwrap_or(0)),
                // A missing slot is the normal "no save here" answer: 221 is used for
                // existence probes (docs/OPCODE_220_SAVE.md section 3.3).
                Err(_) => Some(0),
            },
            222 => {
                match crate::savegame::read_save(&path) {
                    Ok(mut save) => {
                        if write_save_address(&mut save, op) {
                            if let Err(err) = crate::savegame::write_save(&path, &save) {
                                self.note(format!("222 SaveGame: {err}"));
                            }
                        } else {
                            self.note(format!(
                                "222 SaveGame: address {} is outside every bank",
                                op.address
                            ));
                        }
                    }
                    Err(err) => self.note(format!("222 SaveGame: {err}")),
                }
                None
            }
            _ => None,
        }
    }

    fn reserve(&mut self, event: wolf_vm::exec::EventId) {
        self.note(format!("211 Reserve: event {event} not scheduled yet"));
    }

    fn debug_message(&mut self, text: &str) {
        *self
            .diagnostics
            .entry(format!("106 debug line: {text}"))
            .or_insert(0) += 1;
    }

    fn clear_debug(&mut self) {}

    fn return_to_title(&mut self) {
        self.note("174 ReturnToTitle: the title closure does not use it yet".to_owned());
    }

    fn end_game(&mut self) {
        self.note("175 EndGame: ignored (a port never closes the window from script)".to_owned());
    }

    fn pro_feature(&mut self, kind: i32, ms: i32) {
        self.note(format!(
            "1000 ProFeature: type {kind} ({ms} ms) not modelled"
        ));
    }

    fn log(&mut self, level: LogLevel, text: &str) {
        match level {
            LogLevel::Warn | LogLevel::Error => {
                self.stats.warnings += 1;
                *self.diagnostics.entry(text.to_owned()).or_insert(0) += 1;
            }
            LogLevel::Info => self.note(text.to_owned()),
            LogLevel::Trace => {}
        }
    }

    fn key_code(&mut self, mask: u32) -> i32 {
        // The mask is deliberately unused: one mask can yield six different codes,
        // see crates/wolf-game/src/key.rs.
        let _ = mask;
        crate::key::code(self.key_bits)
    }

    fn key_code_auto(&mut self, mask: u32, auto: u32) -> i32 {
        // Opcode 125 exists exactly for script-driven input: the key bits it names
        // are pressed even when the player is not touching the keyboard. The mask is
        // still irrelevant for the code mapping, as above.
        let _ = mask;
        crate::key::code(self.key_bits | auto)
    }

    fn picture_state(&mut self, number: i32, field: i32) -> Option<i32> {
        // Fields 8 and 9 answer for a picture that does not exist either (-1 vs 0),
        // so they run before the existence check below.
        if field == 8 {
            return Some(self.hover(number));
        }
        if field == 9 {
            return Some(i32::from(self.screen.get(number).is_some()));
        }
        let picture = self.screen.get(number)?;
        match field {
            0 => Some(picture.x),
            1 => Some(picture.y),
            2 | 3 => Some(picture.scale),
            4 => picture.extras.first().copied(),
            10 => Some(if PictureKind::from_code(picture.kind as u8).is_text() {
                1
            } else {
                -1
            }),
            _ => None,
        }
    }

    fn character_state(&mut self, target: i32, field: i32) -> Option<i32> {
        // No map layer until M2: leaving the destination alone is honest, while
        // fabricating coordinates would silently break follower logic.
        let _ = (target, field);
        None
    }

    fn engine_state(&mut self, field: i32) -> Option<i32> {
        match field {
            // Static map id and BGM data id: both unset in the port so far.
            0 => Some(0),
            1 => Some(-1),
            7 => Some(mouse_state(
                self.mouse_buttons & 1 != 0,
                self.previous_mouse_buttons & 1 != 0,
            )),
            8 => Some(mouse_state(
                self.mouse_buttons & 2 != 0,
                self.previous_mouse_buttons & 2 != 0,
            )),
            9 => Some(mouse_state(
                self.mouse_buttons & 4 != 0,
                self.previous_mouse_buttons & 4 != 0,
            )),
            10 => Some(0),
            20 => Some(self.mouse[0]),
            21 => Some(self.mouse[1]),
            _ => None,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::key;

    fn data_root() -> PathBuf {
        if let Ok(value) = std::env::var("WOLF_DATA_ROOT") {
            if !value.is_empty() {
                return PathBuf::from(value);
            }
        }
        let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        path.pop();
        path.pop();
        path.push("work");
        path.push("full");
        path
    }

    fn have_data() -> Option<PathBuf> {
        let root = data_root();
        if root.join("BasicData").join("CommonEvent.dat").is_file() {
            Some(root)
        } else {
            eprintln!("skipping: no game data at {}", root.display());
            None
        }
    }

    #[test]
    fn a_save_written_from_a_retail_template_round_trips() {
        let Some(root) = have_data() else { return };
        let mut template = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        template.pop();
        template.pop();
        template.push("work");
        template.push("retail_backup");
        template.push("Save");
        template.push("SaveData01.sav");
        let Ok(bytes) = std::fs::read(&template) else {
            eprintln!("skipping: no retail save at {}", template.display());
            return;
        };
        let mut game = Game::new(&root).expect("game");
        game.base_save = Some(wolf_save::SaveFile::parse(&bytes).expect("template parses"));
        game.vm.vars.set(7, 4321);
        game.vm.vars.set_sys(3, 111);
        game.vm.vars.set_sys(4, 222);
        game.set_playtime_frames(1234);

        let mut out = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        out.push("..");
        out.push("..");
        out.push("target");
        out.push("test-scratch");
        std::fs::create_dir_all(&out).expect("scratch dir");
        out.push("savegame-roundtrip.sav");
        let written = game.save_to(&out).expect("save");
        assert!(written > 300_000, "{written} bytes");

        let save = crate::savegame::read_save(&out).expect("re-read");
        assert_eq!(save.part3.normal_var(7), Some(4321));
        assert_eq!(save.part2.vars3_21[0], 1234);
        assert_eq!(save.part2.vars3_21[9], 111);
        assert_eq!(save.part2.vars3_21[10], 222);
    }

    #[test]
    fn a_saved_game_reloads_its_live_picture_layer() {
        let Some(root) = have_data() else { return };
        let mut template = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        template.pop();
        template.pop();
        template.push("work");
        template.push("retail_backup");
        template.push("Save");
        template.push("SaveData01.sav");
        let Ok(bytes) = std::fs::read(&template) else {
            return;
        };
        let mut game = Game::new(&root).expect("game");
        game.base_save = Some(wolf_save::SaveFile::parse(&bytes).expect("template parses"));
        let loaded = game.load_save(&template).expect("load");
        assert!(loaded.pictures > 10, "{} pictures", loaded.pictures);
        let before: Vec<_> = game
            .screen
            .iter()
            .map(|p| {
                (
                    p.number,
                    p.kind,
                    p.file.clone(),
                    p.x,
                    p.y,
                    p.anchor,
                    p.scale,
                    p.split,
                    p.pattern_index,
                )
            })
            .collect();
        let mut out = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        out.push("..");
        out.push("..");
        out.push("target");
        out.push("test-scratch");
        std::fs::create_dir_all(&out).expect("scratch dir");
        out.push("savegame-pictures.sav");
        game.save_to(&out).expect("save");

        let mut refreshed = Game::new(&root).expect("game");
        refreshed.load_save(&out).expect("reload");
        let after: Vec<_> = refreshed
            .screen
            .iter()
            .map(|p| {
                (
                    p.number,
                    p.kind,
                    p.file.clone(),
                    p.x,
                    p.y,
                    p.anchor,
                    p.scale,
                    p.split,
                    p.pattern_index,
                )
            })
            .collect();
        assert_eq!(before, after);
    }

    #[test]
    fn a_saved_game_keeps_the_database_cells() {
        let Some(root) = have_data() else { return };
        let mut template = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        template.pop();
        template.pop();
        template.push("work");
        template.push("retail_backup");
        template.push("Save");
        template.push("SaveData01.sav");
        let Ok(bytes) = std::fs::read(&template) else {
            return;
        };
        let mut game = Game::new(&root).expect("game");
        game.base_save = Some(wolf_save::SaveFile::parse(&bytes).expect("template parses"));
        game.load_save(&template).expect("load");
        game.databases
            .set_num(crate::db::Container::CData, 0, 12, 5, 4242);

        let mut out = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        out.push("..");
        out.push("..");
        out.push("target");
        out.push("test-scratch");
        std::fs::create_dir_all(&out).expect("scratch dir");
        out.push("savegame-database.sav");
        game.save_to(&out).expect("save");

        let mut refreshed = Game::new(&root).expect("game");
        refreshed.load_save(&out).expect("reload");
        assert_eq!(
            refreshed
                .databases
                .num(crate::db::Container::CData, 0, 12, 5),
            Some(4242)
        );
    }

    #[test]
    fn a_missing_data_root_is_an_error_not_a_panic() {
        let err = match Game::new("no-such-root") {
            Ok(_) => panic!("loading from a bogus root must fail"),
            Err(err) => err,
        };
        assert!(matches!(err, GameError::Io { .. }), "unexpected: {err}");
    }

    #[test]
    fn the_title_event_parks_on_its_menu_after_one_graphic() {
        let Some(root) = have_data() else { return };
        let mut game = Game::new(&root).expect("game");
        game.start_title().expect("title event");
        let mut peak = 0usize;
        let mut last = FrameOutcome::default();
        for _ in 0..200 {
            last = game.frame();
            peak = peak.max(last.report.running);
        }
        // The real title script: draw one full-screen graphic, start one BGM, open a
        // three-option prompt. Everything the old capture showed beyond that came from a
        // branch fall-through bug that reached the save/load screen chain.
        assert!(
            (30..=120).contains(&game.stats.instructions),
            "{} instruction(s)",
            game.stats.instructions
        );
        assert_eq!(peak, 1, "the title event is a single coroutine");
        assert!(game.choices.is_some(), "the title prompt should be open");
        assert_eq!(game.stats.pictures, 1);
        assert!(last.idle, "a parked title does no work");
        let pictures: Vec<_> = game.screen.iter().collect();
        assert_eq!(pictures.len(), 1);
        assert_eq!(
            pictures[0].number, -2,
            "the title layer is the whole screen"
        );
        assert!(pictures[0].is_screen_layer());
        assert!(pictures[0].file.contains("TitleGraphic"));
        assert_eq!(
            game.stats.warnings, 0,
            "diagnostics: {:?}",
            game.diagnostics
        );
    }

    #[test]
    fn the_title_menu_advances_when_the_confirm_key_is_pressed() {
        let Some(root) = have_data() else { return };
        let mut game = Game::new(&root).expect("game");
        game.start_title().expect("title event");
        for _ in 0..30 {
            game.frame();
        }
        // With no keys held the script parks on its menu: a handful of instructions and
        // then nothing, which is what the original game does.
        let parked = game.stats.instructions;
        assert!(parked < 200, "the title should park quickly, ran {parked}");
        for _ in 0..30 {
            game.frame();
        }
        assert_eq!(
            game.stats.instructions, parked,
            "a parked title must not keep executing"
        );

        // A fresh confirm press has to wake it up and close the prompt.
        game.key_bits = key::OK;
        game.frame();
        game.key_bits = 0;
        for _ in 0..60 {
            game.frame();
        }
        assert!(
            game.stats.instructions > parked,
            "confirm did not advance the menu: {parked} -> {}",
            game.stats.instructions
        );
        assert!(game.choices.is_none(), "the prompt should be answered");
    }

    #[test]
    fn booting_reaches_the_title_art_and_confirm_opens_the_menu() {
        let Some(root) = have_data() else { return };
        let mut game = Game::new(&root).expect("game");
        if let Err(err) = game.boot() {
            eprintln!("skipping: {err}");
            return;
        }
        for _ in 0..800 {
            game.frame();
        }
        // Three splashes and then the real title art, which is a picture and not a common
        // event: the boot map event draws it before it calls event 42.
        let art = game
            .screen
            .iter()
            .find(|picture| picture.file.contains("title01"))
            .expect("the title art should be on screen");
        assert_eq!(art.number, 12000);
        assert_eq!((art.x, art.y), (0, 0));
        let banner = game
            .screen
            .iter()
            .find(|picture| picture.file.contains("Button01"))
            .expect("the hint banner should be on screen");
        assert_eq!(banner.anchor, ANCHOR_CENTRE, "head word 4096 centres it");
        assert_eq!((banner.x, banner.y), (512, 520));

        // One confirm press plays the door sound, erases the banner and enters the menu.
        game.key_bits = key::OK;
        game.frame();
        game.key_bits = 0;
        for _ in 0..240 {
            game.frame();
        }
        let choices = game
            .choices
            .as_ref()
            .expect("confirm should land on the title menu");
        assert_eq!(choices.options, ["1", "2", "3"]);
        assert!(
            game.screen
                .iter()
                .all(|picture| !picture.file.contains("Button01")),
            "the hint banner is erased on the way into the menu"
        );
    }

    #[test]
    fn a_database_write_operator_is_the_flags_nibble() {
        // docs/OPCODE_250.md section 3.1: 0 assign / 1 add / 2 sub / 3 mul / 4 div /
        // 5 rem / 6 max / 7 min. The money clamp in the game is add then max 0 then
        // min cap, so both ends of that chain are covered here.
        assert_eq!(combine_cell(0, 999, 7), 7, "op 0 assigns");
        assert_eq!(combine_cell(1, 10, 5), 15, "op 1 adds");
        assert_eq!(combine_cell(2, 10, 5), 5, "op 2 subtracts");
        assert_eq!(combine_cell(3, 10, 5), 50, "op 3 multiplies");
        assert_eq!(combine_cell(4, 10, 5), 2, "op 4 divides");
        assert_eq!(combine_cell(5, 11, 5), 1, "op 5 takes the remainder");
        assert_eq!(combine_cell(6, -3, 0), 0, "op 6 raises to the operand");
        assert_eq!(combine_cell(7, 40, 99), 40, "op 7 caps at the operand");
        assert_eq!(
            combine_cell(4, 10, 0),
            10,
            "dividing by zero keeps the cell"
        );
        assert_eq!(
            combine_cell(5, 10, 0),
            10,
            "remainder by zero keeps the cell"
        );
    }

    #[test]
    fn a_script_write_lands_in_the_cell_the_next_read_sees() {
        let Some(root) = have_data() else { return };
        let mut game = Game::new(&root).expect("game");
        // The player stat block the game keeps in the variable database: type 0 row 0
        // column 0 exists in CDataBase, so a write has a real cell to land in.
        let container = crate::db::Container::CData;
        let before = game.databases.num(container, 0, 0, 0).unwrap_or(0);
        game.databases.set_num(container, 0, 0, 0, before + 1);
        assert_eq!(game.databases.num(container, 0, 0, 0), Some(before + 1));
    }

    fn retail_save(number: u32) -> Option<wolf_save::SaveFile> {
        // The retail saves are not part of the unpacked data root, so the test only
        // runs on this machine. work/retail_backup is the byte copy taken before any
        // capture touched the install.
        let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        path.pop();
        path.pop();
        path.push("work");
        path.push("retail_backup");
        path.push("Save");
        path.push(format!("SaveData{number:02}.sav"));
        if !path.is_file() {
            eprintln!("skipping: no retail save at {}", path.display());
            return None;
        }
        Some(crate::savegame::read_save(&path).expect("retail save must parse"))
    }

    fn save_op(opcode: u8, address: i32, owner: u32) -> SaveOp {
        SaveOp {
            opcode,
            mode: 0,
            file: SaveTarget::Slot(0),
            destination: 0,
            address,
            value: 0,
            flag: 0,
            owner,
        }
    }

    #[test]
    fn a_save_address_finds_normal_self_and_system_variables() {
        let Some(save) = retail_save(1) else { return };
        // SaveData01 row 0 of the normal-variable table: slot 7 is the money the HUD
        // shows as 7586 G, and slot 8 is the action points the same HUD shows as 25.
        assert_eq!(save_address(&save, &save_op(221, 2_000_007, 0)), Some(7586));
        assert_eq!(save_address(&save, &save_op(221, 2_000_008, 0)), Some(25));
        // Event 131 keeps the save-slot number in its self variable 12.
        assert_eq!(
            save_address(&save, &save_op(221, 1_600_012, 131)),
            Some(8),
            "self variables are addressed by the calling event id"
        );
        // 9_000_003 is the choice-window X the saved screen was using, and 9_000_029 is
        // the play time in whole seconds (the save stores frames).
        assert_eq!(save_address(&save, &save_op(221, 9_000_003, 0)), Some(512));
        assert_eq!(
            save_address(&save, &save_op(221, 9_000_029, 0)),
            Some((save.playtime_frames().expect("play time") / 60) as i32)
        );
        assert_eq!(save_address(&save, &save_op(221, 2_000_999, 0)), None);
    }

    #[test]
    fn a_save_write_reaches_the_next_read() {
        let Some(mut save) = retail_save(1) else {
            return;
        };
        let mut op = save_op(222, 2_000_007, 0);
        op.value = 1234;
        assert!(write_save_address(&mut save, &op));
        assert_eq!(save_address(&save, &save_op(221, 2_000_007, 0)), Some(1234));
        let mut playtime = save_op(222, 9_000_029, 0);
        playtime.value = 277;
        assert!(write_save_address(&mut save, &playtime));
        assert_eq!(save.playtime_frames(), Some(277 * 60));
        assert!(!write_save_address(&mut save, &save_op(222, 9_000_050, 0)));
    }

    #[test]
    fn a_save_file_round_trips_through_the_writer() {
        let Some(save) = retail_save(1) else { return };
        let dir = PathBuf::from(env!("CARGO_MANIFEST_DIR"))
            .join("../..")
            .join("target")
            .join("test-scratch");
        std::fs::create_dir_all(&dir).expect("scratch dir");
        let path = dir.join("save-roundtrip.sav");
        crate::savegame::write_save(&path, &save).expect("write");
        let again = crate::savegame::read_save(&path).expect("read");
        assert_eq!(again.to_bytes(), save.to_bytes());
        let _ = std::fs::remove_file(&path);
    }

    /// The borrow shim [`Game::frame`] builds, so a test can drive one `250` op.
    fn host<'a>(game: &'a mut Game) -> GameHost<'a> {
        GameHost {
            screen: &mut game.screen,
            screen_tint: &mut game.screen_tint,
            screen_transition: &mut game.screen_transition,
            assets: &mut game.assets,
            databases: &mut game.databases,
            sounds: &mut game.sounds,
            audio: game.audio.as_mut(),
            messages: &mut game.messages,
            choices: &mut game.choices,
            replies: &mut game.replies,
            diagnostics: &mut game.diagnostics,
            stats: &mut game.stats,
            key_bits: game.key_bits,
            auto_advance: game.auto_advance,
            auto_choice: game.auto_choice,
            auto_choice_delay: game.auto_choice_delay,
            cursor: game.choice_cursor,
            mouse: game.mouse,
            mouse_buttons: game.mouse_buttons,
            previous_mouse_buttons: game.previous_mouse_buttons,
            root: &game.root,
            save_requests: &mut game.save_requests,
            map_requests: &mut game.map_requests,
        }
    }

    /// One `250` access, through the same host the interpreter uses.
    fn cell(game: &mut Game, op: &DbOp) -> Option<DbValue> {
        Host::database(&mut host(game), op)
    }

    /// A `250` op with no editor labels: the numeric pair is used as written.
    fn op(
        direction: wolf_vm::DbDirection,
        db_type: i32,
        row: i32,
        column: i32,
        flags: i32,
        source: Option<DbValue>,
        destination: Option<i32>,
    ) -> DbOp {
        DbOp {
            container: wolf_vm::DbContainer::CData,
            direction,
            op: 0,
            db_type,
            data_id: row,
            item_id: column,
            flags,
            destination,
            source,
            type_label: None,
            field_label: None,
        }
    }

    #[test]
    fn a_row_count_write_resizes_the_table_and_a_resized_row_reads_back() {
        // Row -2 is the row count, not a row (docs/OPCODE_250.md section 3.5): CE191
        // pc30 sets 万能ウィンドウ (CDataBase type 22) to 2 and then writes rows 0 and 1
        // by hand, and CE157 pc28 sets a table to 0 under the comment 全部消去.
        let Some(root) = have_data() else { return };
        let mut game = Game::new(&root).expect("game");
        let before = game.databases.row_count(crate::db::Container::CData, 22);
        let write = wolf_vm::DbDirection::Write;
        let read = wolf_vm::DbDirection::Read;
        let set = |row, value| op(write, 22, row, 0, 0x10000, Some(DbValue::Num(value)), None);

        cell(&mut game, &set(-2, 2));
        assert_eq!(game.stats.database_row_counts, 1);
        assert_eq!(
            game.databases.row_count(crate::db::Container::CData, 22),
            Some(2),
            "row -2 sets the height (was {before:?})"
        );

        cell(&mut game, &set(0, 5));
        cell(&mut game, &set(1, 6));
        // A compound write on an existing row starts from the stored value. The
        // interpreter carries the operator in DbOp::op, taken out of flags ((flags >> 4)
        // & 7 in the bytecode), so 1 here is "add".
        let add = DbOp {
            op: 1,
            ..op(write, 22, 0, 0, 0x11010, Some(DbValue::Num(7)), None)
        };
        cell(&mut game, &add);
        assert_eq!(
            cell(
                &mut game,
                &op(read, 22, 0, 0, 0x11000, None, Some(1_600_001))
            ),
            Some(DbValue::Num(12)),
            "5 + 7"
        );
        // ... and row -1 still answers the count, which is what CE48 pc153 loops over.
        assert_eq!(
            cell(
                &mut game,
                &op(read, 22, -1, 0, 0x11000, None, Some(1_600_001))
            ),
            Some(DbValue::Num(2))
        );
        // Clearing to zero drops the rows: a read of row 0 must not answer with the
        // stale 12. The engine drops the rows, so a dropped row reads EMPTY (absence, not
        // a value); it is a run-time shrink, counted apart from a label that failed.
        cell(&mut game, &set(-2, 0));
        assert_eq!(
            cell(
                &mut game,
                &op(read, 22, 0, 0, 0x11000, None, Some(1_600_001))
            ),
            Some(DbValue::Num(0)),
            "a cleared row reads empty, never the stale value"
        );
        assert_eq!(
            cell(
                &mut game,
                &op(read, 22, 0, 0, 0x51000, None, Some(3_000_001))
            ),
            Some(DbValue::Str(String::new())),
            "and empty as a string when the destination is a string variable"
        );
        assert_eq!(game.stats.database_row_out_of_range, 2);
    }

    #[test]
    fn a_runtime_row_past_the_last_row_answers_the_empty_slot() {
        // CE239 is seen to read CData (0, 100, 0) as a character name while 主人公ステータス
        // has 17 rows (docs/BATTLE.md section 2.6). No file holds rows 100 and up: the
        // engine keeps them at run time and they start empty, as a string when the
        // destination is a string variable and as zero when it is numeric.
        let Some(root) = have_data() else { return };
        let mut game = Game::new(&root).expect("game");
        let read = wolf_vm::DbDirection::Read;
        let write = wolf_vm::DbDirection::Write;
        assert_eq!(
            cell(
                &mut game,
                &op(read, 0, 100, 0, 0x51000, None, Some(3_000_005))
            ),
            Some(DbValue::Str(String::new())),
            "a 100+n slot read into a string variable is empty"
        );
        assert_eq!(
            cell(
                &mut game,
                &op(read, 0, 100, 0, 0x51000, None, Some(1_600_005))
            ),
            Some(DbValue::Num(0)),
            "and numeric into a number"
        );
        assert_eq!(game.stats.database_slots, 2);
        // Once a script writes the slot it reads back, so a battle can keep its own rows.
        cell(
            &mut game,
            &op(
                write,
                0,
                100,
                0,
                0x50004,
                Some(DbValue::Str("slot".into())),
                None,
            ),
        );
        assert_eq!(
            cell(
                &mut game,
                &op(read, 0, 100, 0, 0x51000, None, Some(3_000_005))
            ),
            Some(DbValue::Str("slot".into()))
        );
        // A row that is inside the table but not one of the 100+n slots stays unanswered
        // rather than pretending to be empty: that is a drifted address, not a slot.
        assert_eq!(
            cell(
                &mut game,
                &op(read, 0, 40, 0, 0x51000, None, Some(3_000_005))
            ),
            None
        );
    }

    #[test]
    fn a_column_past_the_field_count_reads_as_the_empty_cell() {
        // The battle template reads columns this game's .dat does not carry:
        // 戦闘時一時ステータス (CData type 10) has 16 fields, but CE191 asks for
        // 装備中の武器 at column 17 and 装備中の防具1..4 at 27..30. The engine answers
        // a Variant default for a field it does not hold, so the read is empty, not a
        // broken label (docs/BATTLE.md section 2.2).
        let Some(root) = have_data() else { return };
        let mut game = Game::new(&root).expect("game");
        let read = wolf_vm::DbDirection::Read;
        let fields = game
            .databases
            .field_count(crate::db::Container::CData, 10)
            .expect("戦闘時一時ステータス exists");
        assert!(fields >= 16, "the game ships 16 fields, got {fields}");
        let column = i32::try_from(fields).unwrap(); // one past the last field
        assert_eq!(
            cell(
                &mut game,
                &op(read, 10, 0, column, 0x51000, None, Some(1_600_005))
            ),
            Some(DbValue::Num(0)),
            "a numeric read past the field count is zero"
        );
        assert_eq!(
            cell(
                &mut game,
                &op(read, 10, 0, column, 0x51000, None, Some(3_000_005))
            ),
            Some(DbValue::Str(String::new())),
            "a string read past the field count is empty"
        );
        assert_eq!(game.stats.database_out_of_schema, 2);
        // A column the table DOES hold still answers, so the guard is not too wide.
        assert!(
            cell(
                &mut game,
                &op(read, 10, 0, 0, 0x51000, None, Some(3_000_005))
            )
            .is_some(),
            "an in-range string column still reads"
        );
    }
}
