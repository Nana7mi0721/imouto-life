//! Game layer: the state that sits between the interpreter and the renderer.
//!
//! Responsibilities, kept deliberately separate from `wolf-vm` (which knows nothing
//! about pictures or files) and from `wolf-render` (which knows nothing about WOLF
//! semantics):
//!
//! * [`picture`] - the `150` Picture layer system. This is the biggest visual surface
//!   in the game (16,716 instructions in common events, and 3,261 of them fire inside
//!   the first 200 frames of the title screen), and it is a real layer store: pictures
//!   are keyed by number, mutate in place, animate, and composite in key order.
//! * [`assets`] - resolving WOLF's relative asset names (`SystemGraphic/TitleGraphic.jpg`)
//!   against an unpacked data root and decoding them to RGBA8 for the atlas.
//! * [`game`] - the host the interpreter talks to: it collects pictures, sounds,
//!   messages and choices into typed state and advances the VM one frame at a time.
//! * [`key`] - the key bitmask opcode 123 polls.
//!
//! Everything here is pure data plus maths: no GPU, no window, no clock. That keeps the
//! whole crate unit-testable on a machine with no display, which matters because the
//! renderer can only be verified by eye.

#![forbid(unsafe_code)]

pub mod achievements;
pub mod assets;
pub mod atlas;
pub mod auto_events;
pub mod choice;
pub mod db;
pub mod fontmetrics;
pub mod game;
pub mod key;
pub mod map_runtime;
pub mod message;
pub mod mods;
pub mod picture;
pub mod savegame;
pub mod settings;
pub mod sysgraphic;
pub mod textpic;
pub mod tilemap;
pub mod tint;
pub mod transition;
pub mod translate;
pub mod window;

pub use achievements::{milestones, Milestone, PlayStats};
pub use assets::{AssetError, Assets, ImageData};
pub use atlas::{Atlas, AtlasRect, SpriteQuad, TextQuad, ATLAS_SIZE};
pub use choice::{layout as choice_layout, ChoiceLayout};
pub use fontmetrics::FontMetrics;
pub use game::{
    layered_data_path, Choices, FrameOutcome, Game, GameError, GameStats, Message, TITLE_EVENT,
};
pub use map_runtime::{MapRuntime, PageSlot, Trigger};
pub use picture::{Picture, PictureKind, Screen, ScreenQuad, UNCHANGED};
pub use tilemap::{autotile_src, base_src, cull_range, TileMap, QUADRANT_PX, TILE_NUMBER, TILE_PX};
pub use tint::ScreenTint;
pub use transition::ScreenTransition;
pub use translate::{
    Context as TextContext, Coverage, SourceScan, SourceText, TranslateError, Translator,
};
pub use window::{nine_slice, WindowPiece, PANEL_PICTURE};
