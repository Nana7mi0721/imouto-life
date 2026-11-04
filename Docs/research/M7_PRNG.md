# M7 W5-H-PRNG: the retail random source

Status: re-verified and corrected. Write scope: `crates/wolf-vm/src/rng.rs`,
`crates/wolf-vm/tests/rng_retail.rs`, this file. No commit/push.

## 1. Summary

* `Game.dat` ships a pre-generated "static random" block: two 32-bit words
  followed by ~28,940 bytes of 0..=127 values.
* The editor generates that block with the MSVC C-runtime LCG documented in
  `_wolfref/game_dat_random.c`; each byte is `getNextRandom() >> 8`, i.e. the
  high seven bits of a 15-bit draw.
* The two leading words (`random_a`, `random_b`, 22507 / 23301 in this build)
  are **not seeds**. They are `K1`/`K2` derived from the generator's first two
  draws: `K1 = draw1 % 3000 + block_offset + 20000`,
  `K2 = draw2 % 3000 + block_offset + 200 + K1`. The previous module version
  used `random_a` as a live LCG state, which cannot reproduce the shipped block
  or the retail game's draws.
* The runtime source is the table itself: a cursor advances one 7-bit entry per
  draw (wrapping). System variable 110 is named `現在の乱数のシード(種)`
  ("current random seed"), i.e. the engine tracks that cursor as a seed value.
* The range operator keeps the multiply-high mapping, now over the 7-bit entry:
  `value = low + (entry * (span + 1)) >> 7`, equivalently
  `((entry << 8) * (span + 1)) >> 15`. For narrow spans this is the same answer
  a full 15-bit draw gives except when the discarded low eight bits carry, which
  is why the old narrow-range vectors (`range(1,10)` → 3,9,9,2,10,5,1,4) do not
  move.

## 2. What was verified against retail data

### 2.1 The generator is proven (sibling build)

`_wolfref/game_dat_random.c` contains the generator and a seed-recovery tool.
Its formulas, transcribed from the file's header comment:

```c
#define RAND(a) ((a)*0x343fd+0x269ec3)
getNextRandom() {
    _seed = RAND(_seed);
    return ((_seed >> 16) & 0x7fff);          // 15-bit draw
}
generate() {
    r1 = getNextRandom(); K1 = r1 % 3000;
    writeU32(K1 + _offset + 20000);            // = random_a
    r2 = getNextRandom(); K2 = r2 % 3000;
    writeU32(K2 + _offset + 200 + K1);         // = random_b
    while (_offset < _len) {
        r = getNextRandom();
        writeU8(r >> 8);                       // 7-bit table byte
        _offset ++;
    }
}
```

The `_offset` in those formulas is the **file offset of the block**, not 0.
The sibling 2.10 build (`E:/Study/github program/imoto life/work/full/BasicData/Game.dat`,
29,273 bytes, block at 328, `random_a` 22227, `random_b` 25684, table 28,936
bytes, all 0..=127) was used as the control:

* Recovering the LCG state with the tool's algorithm (offset 328, `r1=1899`,
  `r2=2925`, 442 candidate states) yields one state whose byte stream matches
  **28,936 / 28,936** table bytes.
* Therefore the generator, the `r >> 8` extraction, and the K1/K2 derivation are
  all exact, not inferred.

### 2.2 This zh-CN 2.00 build's block is partly patched

`work/Data/BasicData/Game.dat` (29,172 bytes): `random_a = 22507`,
`random_b = 23301`, block starts at file offset 221, table = bytes 229..29171
(28,942 bytes), footer `0xC2`.

* Table statistics: min 0, max 251, 143 distinct values, and **16 bytes above
  127**, clustered at indices 23073..23093.
* Running the same recovery at offset 221 (`r1=2286`, `r2=369`, 480 candidate
  states) gives `s0 = 0x4426a8a3`; that stream matches the first **1,055** bytes
  exactly, then diverges:
  * single-byte mismatches at 1055, 3498, 4950, 5414, 5451, 5788, 5947, 9514,
    11525, 12699, 13906;
  * dense divergence from 22278 onward (6,624 mismatches total).
* Conclusion: the fan-translation patch rewrote part of `Game.dat` (its strings
  and font name) without regenerating the whole random block. The runtime would
  still have read the shipped bytes, so the port does the same: it consumes the
  table verbatim and masks each entry to 7 bits (the engine's `entry << 8` must
  stay inside a 15-bit draw, and the editor can never write a value above 127).

### 2.3 `random_a` / `random_b` are derived words, not seeds

For the sibling block, the recovered state satisfies
`K1 = 28899 % 3000 + 20000 + 328 = 22227` and
`K2 = 17925 % 3000 + 22227 + 200 + 328 + 4 = 25684`. For this build the same
arithmetic gives 22507 / 23301 from draws 29286 / 21369. Seeding a live LCG with
`random_a` therefore starts the stream at the wrong place entirely: it was the
bug in the previous port.

### 2.4 Observed retail draws are consistent with the table model

Both retail saves store the four new-game quiz variant variables
(`v35..v38`) set by `SampleMapA` event 0 pc1-4 from `121` `0x6000` draws, and
both read **3, 0, 2, 2**. They are written nowhere else, so they are raw random
outputs from the original engine.

The exact table index at that moment depends on how many draws the engine
consumed while the title screen was up, which the data cannot pin. The table
model reproduces `3,0,2,2` at many positions (e.g. index 291 with
`low + entry*(span+1)>>7`), so it is consistent; the old live-LCG-from-22507
model only reaches that tuple after hundreds of draws as well, so this evidence
does not *discriminate* between the two by itself. The decisive evidence for the
table is §2.1-§2.3: the table is real, is generated by the editor, and
`random_a` is provably not a seed.

## 3. Implemented model

`WolfRng` now owns the table and a cursor:

* `new()` / `from_seed(seed)` synthesise a 4,096-entry table with the editor's
  generator (byte = `(state >> 24) & 0x7f` after each `RAND`). Used by a bare
  `Vm` (CLI `run`/`dump`) or data without `Game.dat`; deterministic but not the
  retail stream.
* `from_game(seed_a, seed_b, table)` uses the shipped table verbatim (masking
  entries to 7 bits). The two words are accepted for API compatibility and
  ignored. An empty table falls back to the synthetic stream.
* `next_raw()` returns the next 7-bit entry and advances/wraps the cursor.
* `range(min, max)` swaps reversed bounds, returns `low` without consuming an
  entry for zero-width ranges, and otherwise applies
  `low + (entry * (span + 1)) >> 7`.
* `state()` keeps its old name and now reports the cursor; `draws()` still counts
  `range()` calls.

## 4. Residual uncertainty (inferred, not proven)

1. **Initial cursor**: 0 is assumed. The engine may seed it from Sys110 or a
   save field. This game's scripts never touch Sys110 (0 references in 350
   common events), and the parsed save layout does not expose it, so no data
   pins a different start.
2. **Wrap policy**: modulo the block length. The engine could stop or reseed;
   modulo is the only policy that keeps a long session deterministic.
3. **Advance point**: one entry per draw is assumed, not observed.
4. **Range mapping granularity**: with 7-bit entries the multiply-high mapping
   has 128 levels. For spans up to 127 it reaches both endpoints; for wider
   spans the top of the range is approached but not reached (e.g.
   `-20000..20000` tops out at +19688). This matches the "entry is draw >> 8"
   reconstruction; an engine that composes several entries into one wider draw
   would differ, but no evidence for that was found (the 15-bit LCG is the
   editor-side generator, not necessarily the runtime consumer).
5. **The corrupted block tail** is consumed as shipped (masked). The retail
   engine would have done the same with the patched bytes, but the resulting
   stream after index ~22,278 is not the editor's intended one.

## 5. Wiring status

`Game::new` now parses `BasicData/Game.dat` once and installs the shipped table:
`game.vm.rng = WolfRng::from_game(dat.random_a, dat.random_b,
dat.static_randoms.clone())` (crates/wolf-game/src/game.rs). Every `Game`-based
path (capture/play/tests) therefore draws from the retail block.

A bare `Vm::new()` (used by `wolf-cli run`/`dump` when it constructs a VM without
a `Game`) still uses the synthetic editor-style table; that is a deliberate
fallback for data without `Game.dat`, not the retail stream. If `wolf-cli run`
must match retail draws, it should parse `Game.dat` and call `from_game` too.
