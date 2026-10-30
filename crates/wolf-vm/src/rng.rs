//! The random-number source behind 121's 0x6000 operator.
//!
//! 0x6000 is documented as *undefined* in WolfTL (docs/OPCODE_SPEC.md §3.2),
//! but it occurs 1,101 times in this game and the operands give it away:
//! ev37 pc25 [v, -20000, 20000], ev42 pc60 [v, 1, 10], ev119 pc128 [v, 0, v],
//! ev137 pc132 [v, 0, 99] -= ... — those are random ranges, not a right shift:
//! 0/99, 1/10 and -20000/20000 are meaningless as arithmetic, while rand(0, v)
//! is exactly the weighted-pick idiom a combat event would use.
//!
//! The *range* semantics are therefore settled; the *sequence* is not. WOLF
//! keeps a static random table in Game.dat (static_randoms, 28,936 bytes of
//! 0..127, regenerated on every editor save) seeded by random_a/random_b, and
//! the reference C decompilation is _wolfref/game_dat_random.c. Until that is
//! ported this module produces a deterministic sequence of its own: gameplay is
//! correct per draw, but a save-compat replay will not reproduce the original
//! numbers. Tracked as an M2 item — see docs/ARCHITECTURE.md.

#![allow(clippy::cast_possible_truncation, clippy::cast_sign_loss)]

/// xorshift32, chosen because it needs no table and stays deterministic in u32
/// space, which is the shape the WOLF static table also wants.
pub struct WolfRng {
    /// Game.dat random_a (static random seed part 1).
    seed_a: u32,
    /// Game.dat random_b (static random seed part 2).
    seed_b: u32,
    /// Game.dat static_randoms; empty until the loader feeds it in.
    table: Vec<u8>,
    /// Position inside the table; the state also advances arithmetically so the
    /// sequence keeps moving once the table wraps.
    index: usize,
    /// How many draws happened. Saved so a replay can be diffed against the
    /// original's draw count instead of guessing.
    draws: u64,
}

impl Default for WolfRng {
    fn default() -> Self {
        Self::new()
    }
}

impl WolfRng {
    /// A generator seeded the way this build's Game.dat is.
    #[must_use]
    pub fn new() -> Self {
        // 22227 / 25684 are this game's Game.dat values (docs/BASELINE.json),
        // hardcoded so the interpreter is deterministic before wolf-game wires
        // the real file in.
        Self {
            seed_a: 22_227,
            seed_b: 25_684,
            table: Vec::new(),
            index: 0,
            draws: 0,
        }
    }

    /// Same, seeded from a parsed Game.dat (random_a, random_b, static_randoms).
    #[must_use]
    pub fn from_game(seed_a: u32, seed_b: u32, table: Vec<u8>) -> Self {
        Self {
            seed_a,
            seed_b,
            table,
            index: 0,
            draws: 0,
        }
    }

    /// Draws taken so far.
    #[must_use]
    pub const fn draws(&self) -> u64 {
        self.draws
    }

    /// One u32 step.
    fn next_u32(&mut self) -> u32 {
        let mut x = self.seed_a ^ self.seed_b.rotate_left(13) ^ 0x9E37_79B9;
        if x == 0 {
            x = 0x1234_5678;
        }
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        self.seed_a = x;
        self.seed_b = self.seed_b.wrapping_add(0x85EB_CA6B);
        if self.table.is_empty() {
            x
        } else {
            // Mix in the static table the way the original consumes it: one byte
            // per draw, wrapping. Keeping the position in the state means a save
            // that stores `index` reproduces the same stream.
            let byte = self.table[self.index % self.table.len()];
            self.index += 1;
            x ^ u32::from(byte)
        }
    }

    /// Uniform integer in [min, max], inclusive on both ends.
    ///
    /// Out-of-order bounds are swapped rather than treated as an error: the
    /// editor lets the author pick the range with two magic values, and at least
    /// one call site (ev119 pc128) passes a variable as the upper bound, so the
    /// order is only known at run time.
    pub fn range(&mut self, min: i32, max: i32) -> i32 {
        self.draws += 1;
        let (low, high) = if min <= max { (min, max) } else { (max, min) };
        let span = i64::from(high) - i64::from(low);
        if span <= 0 {
            return low;
        }
        let span = span.min(i64::from(u32::MAX));
        let value = i64::from(self.next_u32() % (span as u32 + 1));
        (i64::from(low) + value) as i32
    }
}

#[cfg(test)]
mod tests {
    use super::WolfRng;

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
        }
    }

    #[test]
    fn the_sequence_is_deterministic_and_not_constant() {
        let mut a = WolfRng::new();
        let mut b = WolfRng::new();
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
    fn the_static_table_changes_the_stream() {
        let mut plain = WolfRng::new();
        let mut tabled = WolfRng::from_game(22_227, 25_684, (0..=127u8).collect());
        let plain_values: Vec<i32> = (0..16).map(|_| plain.range(0, 1_000_000)).collect();
        let tabled_values: Vec<i32> = (0..16).map(|_| tabled.range(0, 1_000_000)).collect();
        assert_ne!(plain_values, tabled_values);
    }
}
