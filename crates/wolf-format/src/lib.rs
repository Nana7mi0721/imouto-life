//! Binary format loaders for WOLF RPG Editor (ウディタ) game data.
//!
//! Everything in this crate is pure parsing: no I/O, no allocation-heavy
//! abstractions, no external crates. Feed it `&[u8]` and get typed structures
//! that mirror the on-disk layout documented in `docs/FORMAT_SPEC.md`.
//!
//! The one deliberate design rule: **never normalise what the original file
//! says**. Event titles are truncation-limited by the editor, some tileset
//! strings contain corrupt bytes, and a handful of map pages carry `0x00`
//! instead of `0x7A` as their terminator. Loaders preserve the raw values and
//! only decode lossily at the display boundary.
#![forbid(unsafe_code)]

pub mod bytes;
pub mod command;
pub mod commonevent;
pub mod database;
pub mod dxarchive;
pub mod error;
pub mod gamedat;
pub mod generation;
pub mod maptree;
pub mod messagetext;
pub mod mps;
pub mod sysdatabase;
pub mod tileset;

pub use bytes::Reader;
pub use error::{Error, Result};
