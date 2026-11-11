# Opcode 122 — SetString 変数文字列操作

Opcode `122` writes a string into a string variable. The **second operand** is a
mode word, not a plain enumerator:

```
operation   = mode & 0xFFF0
source kind = mode & 0x000F
```

The old interpreter treated every site as a plain assignment, which is why the
save-slot play time came out as two zeros and the slot number was lost. A later
fix masked with `0xFF00`; that still folded the first-line cut (operation
`0x0010`, used by CE268 with mode 17) into assignment, so it is explicitly
`0xFFF0` now.

Operand layout: `[destination, mode, (source_operand)]`, and literal text (if
any) travels in `cmd.strings`.

## Source kinds (`mode & 0x0F`)

Manual: 文字列操作 → ３．代入する文字列.

| nibble | meaning | evaluation |
|--------|---------|------------|
| 0 | 手動入力 (literal) | `expand(cmd.strings[0])`, `""` when absent |
| 1 | 文字列変数 | `eval_str(source_operand)` |
| 2 | ロード位置を変数で指定 | `eval_num(source_operand)` is a `3_000_000+n` string code; read that string variable |
| 3 | キーボード入力 | interactive; not present in this game's data and not modelled |

Cut operations write the shortened text back into the same source variable
(kind 1) or the string variable the numeric operand pointed at (kind 2). A
literal has nowhere to write back and is left untouched.

## Operations

Manual: 文字列操作 → ２．代入方法.

| operation | manual label | semantics |
|-----------|--------------|-----------|
| `0x0000` | ＝ | `dst = rhs` |
| `0x0100` | ＋＝ | `dst = dst + rhs` |
| `0x0010` | 上1行切り取り | `dst = first line of rhs`; rhs loses that line |
| `0x0300` | 上1行コピー | `dst = first line of rhs`; rhs unchanged |
| `0x0400` | に↓から1文字切り出し | `dst = first display unit of rhs`; rhs loses it |
| `0x0500` | に↓から最後1文字切り出し | `dst = last display unit of rhs`; rhs loses it |
| `0x0800` | から↓の文字列を全消去 | remove every occurrence of the literal from `dst` |
| `0x0900` | から以下の文字列を置換 | replace every occurrence of `strings[0]` with `strings[1]` in `dst` |
| `0x0A00` | から指定文字まで切り出し | `dst = text before the first marker` (marker excluded); `<<NotFound>>` on a miss |
| `0x0B00` | から指定文字以降を切り出し | `dst = text after the first marker` (marker excluded); `<<NotFound>>` on a miss |

A display unit is one UTF-8 scalar, or one whole control escape (`\E`, `\c[1]`,
`\A+`, `\r[...]`), so a cut never leaves half an escape behind. The manual also
says `\r[X,A]` cuts only `\r[`; `first_unit_len` follows that rule for the
simple forms this game uses.

## Form 1 — copy from another string variable

```
122 [dst, 1, src]        dst := eval_str(src)
```

The third operand is a string magic value, evaluated with `eval_str` (so it may
be a `\cself[n]`-style self string, a `\cdb`-style DB string, or an escaped
literal). CE94 pc394 `[1600005, 1, 1600006]` copies the hero name from
`self[6]` into the display buffer `self[5]`.

## Form 2 — append a literal

```
122 [dst, 256|mode, ...]  dst := eval_str(dst) + rhs
```

CE94 builds the play-time prefix this way and appends the minutes (pc293/296,
`"0\cself[67]"` / `"\cself[67]"`), and the save-slot label appends the slot
number to the term (pc396, pc228).

## Form 3 — plain assignment

Otherwise the destination is overwritten with the expanded literal (`""` when no
string operand is present). CE94 pc403 / pc228 use this to reset a buffer before
the other forms fill it.

## Indirected destination

WOLF's editor offers 代入先を変数で指定: the destination operand may itself be a
numeric self slot that holds a string-variable address. When that slot contains a
`3_000_000+n` string variable, a `9_000_000+n` system string or a cross-event
common-self cell, the write goes through the address instead of overwriting the
holder. Slots CSelf5..9 are the event's real string slots and remain direct.

CE268 (名前欄の変更) computes CE269's CSelf5 address one instruction earlier and
then executes `122 [1_600_010, 17, 1_600_005]`; the speaker name lands in
`15_000_000 + 100*269 + 5` and CE270 reads it for the name plate.

The same cross-event bank is used by `121`: a numeric destination that resolves
to `15_000_000 + 100*event + slot` writes that event's numeric slot. CE265/266
build this address with `(99+offset)*100 + 15_000_000`; the balloon library keeps
its window state in CE270's bank rather than in its own one-shot self slots.
Slots 5..9 are string cells and only the string paths dereference them; numeric
reads of a CommonSelf address keep the raw value (the library also uses it as an
arithmetic base).

## Escape expansion

`expand(raw, inst, vars, host)` (in `crates/wolf-vm/src/text.rs`) resolves the
inline escapes the strings use in practice — `\cself[n]`, `\cdb[...]`,
`\udb[...]`, `\sdb[...]`, `\f[...]`, colour tags and `\\` — before the value is
stored.

## Related opcode 112 — 文字列条件分岐

`112` shares the `401` / `420` / `499` block skeleton with the numeric `111`.
`head & 0x0F` is the condition count and `head & 0x10` selects the else branch.
Each operand packs the comparison mode in its highest nibble:

- `mode = 1` means 異なる (not equal);
- other/unidentified modes keep the historical equality test.

The operand can also carry a string-variable type flag in **bit 24**. Strip it
with `raw & 0x00FF_FFFF` before `eval_str`; otherwise a value such as
`0x11186A05` is decoded as an address outside the Self bank and becomes an empty
string. The low 24 bits of that example are `0x00186A05 = 1_600_005`, i.e.
CSelf5.

Two argument layouts share this opcode:

- `argc == 1 + count`: right-hand values are the literal strings in
  `cmd.strings[i]`;
- `argc > 1 + count`: every condition is a pair of string-variable operands
  (left at `1 + 2*i`, right at `2 + 2*i`).

CE270 pc92 uses the second layout to compare CSelf5 with SysStr25 (the current
message buffer) and detect a new message. Missing the bit-24 mask made that
comparison true every frame, which reset the name-exists flag and hid picture
`36014` after its first frame. Regression coverage:
`string_condition_strips_the_variable_type_flag_from_cself_operands` in
`crates/wolf-vm/src/exec.rs` and `crates/wolf-game/tests/m15_balloon_name.rs`.

## Verification

- CE94 slot 1 now yields `数据 1` / ` 0:00` / ` 1` / `早泄 ` instead of `000000`.
- CE212's typewriter (mode 1025 = `0x0401`) shows one glyph per iteration; with
  the old "target = rest" reading it repeated the whole remainder instead.
- CE268/C268 name-list parsing uses mode 17 (`0x0011`) as 上1行切り取り;
  the indirect write stores the speaker name in CE269's CSelf5
  (`tests/m15_balloon_name.rs`).
- Regression coverage: `crates/wolf-vm/src/exec.rs` unit test
  `op122_advanced_modes_move_the_right_text_and_keep_the_manual_direction`;
  `crates/wolf-game/tests/m3_save_ui_roundtrip.rs`, `m3_hud_buttons.rs`,
  `m3_menu_screens.rs` assert the slot strings.
