//! The retail random source behind 121's 0x6000 operator.
//!
//! Provenance (what is proven vs inferred is called out below)
//!
//! WOLF's `Game.dat` ends with a "static random" block: two 32-bit words followed
//! by ~28,940 bytes (docs/BASELINE.json; `game_dat.ksy` names it
//! `static_randoms`). The editor regenerates it on every Game.dat save, and the
//! bundled reference tool `_wolfref/game_dat_random.c` documents both the
//! generator and how to recover the LCG state that produced an existing block:
//!
//! ```text
//! #define RAND(a) ((a)*0x343fd+0x269ec3)
//! getNextRandom() { _seed = RAND(_seed); return ((_seed >> 16) & 0x7fff); }
//! generate() {
//!     r1 = getNextRandom(); K1 = r1 % 3000; writeU32(K1 + _offset + 20000)
//!     r2 = getNextRandom(); K2 = r2 % 3000; writeU32(K2 + _offset + 200 + K1)
//!     while (...) { r = getNextRandom(); writeU8(r >> 8); }
//! }
//! ```
//!
//! This is the Microsoft C runtime LCG (multiplier `0x343FD`, increment
//! `0x269EC3`), and the byte stream stores the **high 7 bits** of each 15-bit
//! draw (`r >> 8`).
//!
//! Verified against retail data
//!
//! * The sibling 2.10 build's block (28,936 bytes, all 0..=127) reproduces
//!   **every byte** from the state recovered with the reference tool, so the
//!   generator above is not a guess.
//! * In this zh-CN 2.00 build the same state recovery (`s0 = 0x4426a8a3`)
//!   reproduces the first **1,055** bytes; after that the block carries
//!   scattered single-byte edits and, from byte 22,278, a different stream.
//!   The fan-translation patch evidently rewrote part of Game.dat without
//!   regenerating the whole block. The runtime still reads the shipped bytes
//!   verbatim, so this module does too (masking each byte to 7 bits).
//! * `random_a` / `random_b` are **not seeds**. They are the K1/K2 words the
//!   generator derives from its first two draws (`random_a = draw1 % 3000 +
//!   block_offset + 20000`). Using `random_a` as a live LCG state — as the
//!   previous version of this module did — cannot reproduce the shipped table
//!   or the retail game's draws.
//!
//! What this module models
//!
//! The table is the runtime source: the engine ships ~28.9 KiB of pre-generated
//! randoms precisely so the sequence is data-defined, and system variable 110 is
//! named `現在の乱数のシード(種)` ("current random seed"), i.e. the engine keeps a
//! cursor into that sequence. Each draw advances the cursor (wrapping at the end
//! of the block) and returns one 7-bit table entry.
//!
//! The range operator (`121` with the `0x6000` binary nibble) then uses the same
//! multiply-high mapping as before:
//!
//! ```text
//! draw = table[cursor] << 8              // the table stores draw >> 8
//! value = low + (draw * (span + 1)) >> 15
//!       = low + (table[cursor] * (span + 1)) >> 7
//! ```
//!
//! For spans up to 127 that reaches both endpoints exactly, and for narrow
//! ranges it agrees with a full 15-bit draw except when the discarded low eight
//! bits would have carried — which is why existing narrow-range expectations
//! (`range(1,10)` etc.) barely move.
//!
//! Residual uncertainty (inferred, not proven)
//!
//! * The initial cursor is taken as 0. The retail engine may seed it from
//!   `Sys110`/save state; this game's scripts never touch Sys110 and the save
//!   layout parsed here does not carry it, so 0 is the only value the data
//!   pins down.
//! * The wrap policy is modulo the block length. The retail engine could stop or
//!   reseed instead; a long session can consume more entries than the block
//!   holds, and modulo is the only policy that keeps running deterministically.
//! * The exact moment the engine advances the cursor (per draw) is assumed, not
//!   observed.
//! * This build's corrupted tail is read as-is (masked to 7 bits), because that
//!   is what the engine would have done with the patched bytes.

#![allow(clippy::cast_possible_truncation, clippy::cast_sign_loss)]

/// Fallback seed used only to synthesise a table when no `Game.dat` table has
/// been supplied (unit tests, `Vm::new` before the loader wires the real one).
///
/// This is this build's `random_a` word, but it is **not** the retail seed: the
/// word is derived from the editor's first two draws. See the module docs.
pub const DEFAULT_SEED: u32 = 22_507;

/// Byte length of the synthetic table built by [`WolfRng::from_seed`].
///
/// The retail block is ~28,940 bytes; 4,096 is plenty for a headless run and
/// keeps the fallback cheap. The retail table is used verbatim through
/// [`WolfRng::from_game`].
pub const SYNTHETIC_TABLE_LEN: usize = 4_096;

/// MSVC C-runtime LCG multiplier (0x343FD).
const MULTIPLIER: u32 = 0x0003_43FD;

/// MSVC C-runtime LCG increment (0x269EC3).
const INCREMENT: u32 = 0x0026_9EC3;

/// The retail random source: a cursor over the pre-generated 7-bit table from
/// `Game.dat`.
#[derive(Debug, Clone)]
pub struct WolfRng {
    /// The static-random table, one 0..=127 entry per draw.
    table: Vec<u8>,
    /// Cursor into [`Self::table`]; advances by one per draw and wraps.
    cursor: usize,
    /// How many range() draws happened. Saved so a replay can be diffed
    /// against the original's draw count instead of guessing.
    draws: u64,
}

impl Default for WolfRng {
    fn default() -> Self {
        Self::new()
    }
}

impl WolfRng {
    /// A generator over a synthetic table built from [`DEFAULT_SEED`].
    ///
    /// Used by callers that have not loaded `Game.dat` yet. Behaviour is
    /// deterministic but the stream is not this game's retail stream.
    #[must_use]
    pub fn new() -> Self {
        Self::from_seed(DEFAULT_SEED)
    }

    /// Builds a table the way the editor does, from a 32-bit LCG seed.
    ///
    /// Each entry is `(state >> 24) & 0x7f` after one `RAND` step, i.e. the high
    /// seven bits of the 15-bit `getNextRandom()` draw (`r >> 8`). Two generators
    /// from the same seed replay identically; different seeds diverge.
    #[must_use]
    pub fn from_seed(seed: u32) -> Self {
        let mut state = seed;
        let mut table = Vec::with_capacity(SYNTHETIC_TABLE_LEN);
        for _ in 0..SYNTHETIC_TABLE_LEN {
            state = state.wrapping_mul(MULTIPLIER).wrapping_add(INCREMENT);
            table.push(((state >> 24) & 0x7f) as u8);
        }
        Self {
            table,
            cursor: 0,
            draws: 0,
        }
    }

    /// Same, from a parsed `Game.dat`.
    ///
    /// The table is used verbatim (masked to 7 bits per entry, because this
    /// build's fan-translated block has a few patched bytes above 127). The two
    /// leading words are accepted for API/source fidelity but are **not** seeds:
    /// the editor derives them from its first two draws, as the module docs
    /// explain.
    #[must_use]
    pub fn from_game(seed_a: u32, _seed_b: u32, table: Vec<u8>) -> Self {
        if table.is_empty() {
            // A store without Game.dat must still run deterministically.
            return Self::from_seed(seed_a);
        }
        Self {
            table,
            cursor: 0,
            draws: 0,
        }
    }

    /// Draws taken so far (counts range() calls).
    #[must_use]
    pub const fn draws(&self) -> u64 {
        self.draws
    }

    /// Current cursor into the static-random table.
    ///
    /// Kept under the old `state()` name for callers that used to inspect the
    /// LCG state; it now names the table position instead.
    #[must_use]
    pub const fn state(&self) -> u32 {
        self.cursor as u32
    }

    /// Entries in the table (the retail block is 28,942 bytes in this build).
    #[must_use]
    pub fn table_len(&self) -> usize {
        self.table.len()
    }

    /// One retail draw: the next 7-bit table entry, advancing the cursor and
    /// wrapping at the end of the block.
    ///
    /// The value stands in for the high seven bits of the engine's 15-bit draw
    /// (`draw = entry << 8`).
    pub fn next_raw(&mut self) -> u16 {
        if self.table.is_empty() {
            return 0;
        }
        let entry = self.table[self.cursor] & 0x7f;
        self.cursor = (self.cursor + 1) % self.table.len();
        u16::from(entry)
    }

    /// Uniform integer in [min, max], inclusive on both ends.
    ///
    /// Out-of-order bounds are swapped rather than treated as an error: the
    /// editor lets the author pick the range with two magic values, and at least
    /// one call site (ev119 pc128) passes a variable as the upper bound, so the
    /// order is only known at run time.
    ///
    /// A zero-width range is a constant (the lower bound) and consumes no
    /// table entry, so it never panics.
    pub fn range(&mut self, min: i32, max: i32) -> i32 {
        self.draws += 1;
        let (low, high) = if min <= max { (min, max) } else { (max, min) };
        let span = i64::from(high) - i64::from(low);
        if span <= 0 {
            return low;
        }
        // The table stores draw >> 8, so `entry << 8` is the engine's 15-bit
        // draw with its low eight bits zero. Multiply-high across the span:
        // (entry << 8) * (span + 1) >> 15 == entry * (span + 1) >> 7.
        let entry = u64::from(self.next_raw());
        let value = (entry * (span as u64 + 1)) >> 7;
        (i64::from(low) + value as i64) as i32
    }
}

#[cfg(test)]
mod tests {
    use super::WolfRng;

    /// The first table entries the editor's generator produces for a seed.
    fn editor_bytes(seed: u32, n: usize) -> Vec<u8> {
        let mut rng = WolfRng::from_seed(seed);
        (0..n).map(|_| rng.next_raw() as u8).collect()
    }

    #[test]
    fn synthetic_tables_reproduce_the_editor_generator() {
        // (state >> 24) & 0x7f after each RAND step, verified against the C
        // reference: getNextRandom() >> 8.
        assert_eq!(
            editor_bytes(1, 16),
            vec![0, 72, 24, 103, 74, 61, 44, 114, 105, 95, 22, 109, 90, 65, 38, 1]
        );
        assert_eq!(
            editor_bytes(22_507, 16),
            vec![31, 112, 104, 23, 119, 60, 9, 46, 58, 9, 75, 14, 41, 0, 66, 39]
        );
    }

    #[test]
    fn from_game_uses_the_supplied_table_verbatim() {
        let mut rng = WolfRng::from_game(1, 2, vec![0, 64, 127]);
        assert_eq!(rng.table_len(), 3);
        assert_eq!(rng.next_raw(), 0);
        assert_eq!(rng.next_raw(), 64);
        assert_eq!(rng.next_raw(), 127);
        // Wrap at the end of the block.
        assert_eq!(rng.next_raw(), 0);
        assert_eq!(rng.state(), 1);
    }

    #[test]
    fn entries_above_127_are_masked_like_the_engine_must() {
        // This build's patched block carries a few bytes above 127; masking
        // keeps `entry << 8` inside the 15-bit draw.
        let mut rng = WolfRng::from_game(0, 0, vec![0xff, 0x80, 0x7f]);
        assert_eq!(rng.next_raw(), 0x7f);
        assert_eq!(rng.next_raw(), 0);
        assert_eq!(rng.next_raw(), 0x7f);
    }

    #[test]
    fn an_empty_game_table_falls_back_to_the_synthetic_stream() {
        let mut from_game = WolfRng::from_game(22_507, 0, Vec::new());
        let mut from_seed = WolfRng::from_seed(22_507);
        assert_eq!(from_game.next_raw(), from_seed.next_raw());
        assert!(from_game.table_len() > 0);
    }

    #[test]
    fn range_stays_inside_the_bounds() {
        let mut rng = WolfRng::new();
        for _ in 0..1000 {
            let value = rng.range(1, 10);
            assert!((1..=10).contains(&value), "out of range: {value}");
        }
        for _ in 0..1000 {
            let value = rng.range(-20_000, 20_000);
            assert!((-20_000..=20_000).contains(&value), "out of range: {value}");
        }
    }

    #[test]
    fn a_narrow_range_reaches_both_endpoints() {
        // A table holding the two extremes must produce min and max.
        let mut rng = WolfRng::from_game(0, 0, vec![0, 127]);
        assert_eq!(rng.range(1, 10), 1);
        assert_eq!(rng.range(1, 10), 10);
    }

    #[test]
    fn reversed_bounds_are_swapped() {
        let mut rng = WolfRng::new();
        for _ in 0..100 {
            assert!((3..=7).contains(&rng.range(7, 3)));
        }
    }

    #[test]
    fn a_degenerate_range_is_a_constant() {
        let mut rng = WolfRng::new();
        for _ in 0..10 {
            assert_eq!(rng.range(5, 5), 5);
            assert_eq!(rng.range(-3, -3), -3);
        }
    }

    #[test]
    fn the_sequence_is_deterministic_and_not_constant() {
        let mut a = WolfRng::from_seed(22_507);
        let mut b = WolfRng::from_seed(22_507);
        let first: Vec<i32> = (0..64).map(|_| a.range(0, 1_000_000)).collect();
        let second: Vec<i32> = (0..64).map(|_| b.range(0, 1_000_000)).collect();
        assert_eq!(first, second, "same seed must replay identically");
        assert!(
            first.iter().any(|value| *value != first[0]),
            "generator is stuck"
        );
        assert_eq!(a.draws(), 64);
    }

    #[test]
    fn different_seeds_diverge() {
        let mut a = WolfRng::from_seed(22_507);
        let mut b = WolfRng::from_seed(23_301);
        let first: Vec<u16> = (0..32).map(|_| a.next_raw()).collect();
        let second: Vec<u16> = (0..32).map(|_| b.next_raw()).collect();
        assert_ne!(first, second, "different seeds must produce different streams");
    }
}
