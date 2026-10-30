//! The event interpreter: WOLF RPG Editor's flat bytecode, executed.
//!
//! Three layers, in the order the data flows through them:
//!
//! 1. [`magic`] — WOLF packs "where a value lives" and "which value it is" into a
//!    single `i32`. Every opcode argument goes through here first.
//! 2. [`program`] — load-time precompilation. The editor stores `if`/`loop` as
//!    *pairs* of plain instructions (`111`..`499`, `170`..`498`), so a naive
//!    interpreter has to scan forwards to find a block's end. We resolve every
//!    branch and loop into a jump table once, at load time, so the hot path is
//!    "read table, set pc" (docs/OPCODE_SPEC.md §4, §7.5).
//! 3. [`exec`] — the scheduler and the opcode dispatch. One [`Instance`] per
//!    running coroutine; 108 of them run in parallel in this game
//!    (docs/OPCODE_SPEC.md §7.1), which is why `210 CommonEvent` spawns a new
//!    coroutine instead of pushing a call frame.
//!
//! Design constraints that shaped this crate:
//!
//! * **safe Rust only, no dependencies.** The interpreter is the piece we must be
//!   able to reason about and serialise into save files, so it holds no
//!   resources, no trait objects and no interior mutability — only plain data.
//! * **No recursion.** `210` can call back into the caller's event (the menus do
//!   this), so call nesting lives in the [`Vm`]'s instance list, never in the
//!   Rust stack.
//! * **Deterministic.** Nothing here reads the clock or the RNG; frame pacing and
//!   input are provided by [`Host`], so the same bytecode + the same host
//!   responses produce the same state — which is what makes the save-compat tests
//!   possible.
//!
//! The platform-facing surface is deliberately tiny: implement [`Host`] and the
//! interpreter can drive a window (wolf-render), an audio device (wolf-audio) or
//! just a text log (wolf-cli).

#![forbid(unsafe_code)]

pub mod exec;
pub mod magic;
pub mod program;
pub mod rng;
pub mod text;
pub mod vars;

pub use exec::{
    BlockResult, ChoiceReply, DbContainer, DbDirection, DbOp, DbValue, Host, Instance, InstanceId,
    LogLevel, PictureAction, PictureCmd, SaveOp, SaveTarget, Signal, SoundAction, SoundChannel,
    SoundCmd, StepReport, Vm, WaitState,
};
pub use magic::{Magic, MagicKind};
pub use program::{Block, BlockKind, Control, PrecompileStats, Program, ProgramSet};
pub use rng::WolfRng;
pub use vars::{SelfVars, Variables};
