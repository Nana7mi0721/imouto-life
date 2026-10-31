//! Regression proofs for the retail random source.
//!
//! The engine ships a pre-generated 7-bit table in `Game.dat` (`static_randoms`)
//! and advances a cursor through it. The editor builds that table with the MSVC
//! C-runtime LCG documented in `_wolfref/game_dat_random.c`:
//!
//! ```text
//! state = state * 0x343FD + 0x269EC3 (mod 2^32)
//! draw  = (state >> 16) & 0x7fff        // 15-bit
//! byte  = draw >> 8                     // 7-bit, what the table stores
//! ```
//!
//! These tests exercise the public API only. See `crates/wolf-vm/src/rng.rs`
//! and `docs/research/M7_PRNG.md` for the evidence chain, including the retail
//! block verification and the residual uncertainty about the initial cursor.

use wolf_vm::WolfRng;

/// `from_seed(22507)` table bytes, matching the editor's generator.
const GAME_SEED: u32 = 22_507;

#[test]
fn same_seed_produces_the_same_sequence() {
    let mut a = WolfRng::from_seed(GAME_SEED);
    let mut b = WolfRng::from_seed(GAME_SEED);
    let ra: Vec<u16> = (0..64).map(|_| a.next_raw()).collect();
    let rb: Vec<u16> = (0..64).map(|_| b.next_raw()).collect();
    assert_eq!(ra, rb, "identical seeds must replay identically");

    let mut c = WolfRng::new();
    let mut d = WolfRng::new();
    let rc: Vec<i32> = (0..64).map(|_| c.range(0, 1_000_000)).collect();
    let rd: Vec<i32> = (0..64).map(|_| d.range(0, 1_000_000)).collect();
    assert_eq!(rc, rd, "range() draws must also replay identically");
}

#[test]
fn different_seeds_produce_different_sequences() {
    let mut a = WolfRng::from_seed(22_507);
    let mut b = WolfRng::from_seed(23_301);
    let ra: Vec<u16> = (0..64).map(|_| a.next_raw()).collect();
    let rb: Vec<u16> = (0..64).map(|_| b.next_raw()).collect();
    assert_ne!(ra, rb, "different seeds must diverge");
}

#[test]
fn the_editor_generator_vectors_are_pinned() {
    // Both are getNextRandom() >> 8 for the stated seed. Seed 1 is the canonical
    // MSVC srand(1) stream (41, 18467, 6334, ...); its first entries are
    // 41>>8=0, 18467>>8=72, 6334>>8=24, ...
    let mut seeded = WolfRng::from_seed(1);
    let got: Vec<u16> = (0..8).map(|_| seeded.next_raw()).collect();
    assert_eq!(got, vec![0, 72, 24, 103, 74, 61, 44, 114]);

    let mut game = WolfRng::from_seed(GAME_SEED);
    let got: Vec<u16> = (0..8).map(|_| game.next_raw()).collect();
    assert_eq!(got, vec![31, 112, 104, 23, 119, 60, 9, 46]);
}

#[test]
fn from_game_replays_the_shipped_table_and_wraps() {
    // A three-entry block: the cursor must return the entries in order and wrap.
    let mut rng = WolfRng::from_game(0, 0, vec![0, 64, 127]);
    assert_eq!(rng.table_len(), 3);
    assert_eq!(
        (0..6).map(|_| rng.next_raw()).collect::<Vec<_>>(),
        vec![0, 64, 127, 0, 64, 127]
    );
    // The two leading Game.dat words are metadata, not seeds: they must not
    // change the stream.
    let mut other = WolfRng::from_game(22_507, 23_301, vec![0, 64, 127]);
    assert_eq!(
        (0..3).map(|_| other.next_raw()).collect::<Vec<_>>(),
        vec![0, 64, 127]
    );
}

#[test]
fn range_is_inclusive_and_stays_inside_the_bounds() {
    let mut rng = WolfRng::new();
    for _ in 0..2000 {
        let value = rng.range(1, 10);
        assert!((1..=10).contains(&value), "1..=10 out of range: {value}");
    }
    let mut rng = WolfRng::new();
    for _ in 0..2000 {
        let value = rng.range(-20_000, 20_000);
        assert!(
            (-20_000..=20_000).contains(&value),
            "-20000..=20000 out of range: {value}"
        );
    }
}

#[test]
fn a_wide_range_uses_both_halves() {
    // Multiply-high scaling over the 7-bit table reaches both tails. A plain
    // draw % (span+1) would cap at +127 and never leave the low end.
    let mut rng = WolfRng::new();
    let mut min = i32::MAX;
    let mut max = i32::MIN;
    for _ in 0..3000 {
        let value = rng.range(-20_000, 20_000);
        min = min.min(value);
        max = max.max(value);
    }
    assert!(min < -19_000, "lower tail reached: min={min}");
    assert!(max > 19_000, "upper tail reached: max={max}");
}

#[test]
fn narrow_range_draws_are_exact_vectors() {
    // Pinned so drift in the mapping is caught. First 8 draws of range(1, 10)
    // from the default synthetic table (editor bytes 31, 112, 104, 23, ...).
    let mut rng = WolfRng::new();
    let got: Vec<i32> = (0..8).map(|_| rng.range(1, 10)).collect();
    assert_eq!(got, vec![3, 9, 9, 2, 10, 5, 1, 4]);
}

#[test]
fn reversed_bounds_are_swapped() {
    let mut rng = WolfRng::new();
    let mut a = WolfRng::new();
    let mut b = WolfRng::new();
    for _ in 0..200 {
        assert!((3..=7).contains(&rng.range(7, 3)));
    }
    // range(7,3) must equal range(3,7) draw for draw.
    for _ in 0..32 {
        assert_eq!(a.range(7, 3), b.range(3, 7));
    }
}

#[test]
fn zero_width_ranges_do_not_panic() {
    let mut rng = WolfRng::new();
    for _ in 0..10 {
        assert_eq!(rng.range(5, 5), 5);
        assert_eq!(rng.range(-3, -3), -3);
        assert_eq!(rng.range(0, 0), 0);
    }
    // Extreme-but-valid bounds must also not panic.
    let _ = rng.range(i32::MIN, i32::MIN);
    let _ = rng.range(i32::MAX, i32::MAX);
    let _ = rng.range(i32::MIN, i32::MAX);
}

#[test]
fn draws_counts_range_calls_not_raw_steps() {
    let mut rng = WolfRng::new();
    assert_eq!(rng.draws(), 0);
    for _ in 0..7 {
        let _ = rng.range(0, 10);
    }
    assert_eq!(rng.draws(), 7);
    // A zero-width range still counts as a draw call.
    let _ = rng.range(4, 4);
    assert_eq!(rng.draws(), 8);
}
