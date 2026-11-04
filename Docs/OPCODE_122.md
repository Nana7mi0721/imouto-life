# Opcode 122 — SetString 変数文字列操作

Opcode `122` writes a string into a string variable. This game uses three
distinct forms, all selected by the **second operand** (the "mode" word); the
old interpreter treated every site as a plain assignment, which is why the
save-slot play time came out as two zeros and the slot number was lost.

Operand layout: `[destination, mode, (source_operand)]`, and the literal text
(if any) travels in `cmd.strings[0]`.

## Form 1 — copy from another string variable

Condition: `mode == 1` **and** there is a third operand.

```
122 [dst, 1, src]        dst := eval_str(src)
```

The third operand is a string magic value, evaluated with `eval_str` (so it may
be a `\cself[n]`-style self string, a `\cdb`-style DB string, or an escaped
literal). CE94 pc394 `[1600005, 1, 1600006]` copies the hero name from
`self[6]` into the display buffer `self[5]`.

## Form 2 — append a literal

Condition: `mode & 0x100 != 0` (bit 256).

```
122 [dst, 256|mode, ...]  dst := eval_str(dst) + expand(cmd.strings[0])
```

The existing value is read back with `eval_str`, the new literal is appended,
and the result is stored. CE94 builds the play-time prefix this way and appends
the minutes (pc293/296, `"0\cself[67]"` / `"\cself[67]"`), and the save-slot
label appends the slot number to the term (pc396, pc228).

## Form 3 — plain assignment

Otherwise the destination is overwritten with the expanded literal
(`""` when no string operand is present). CE94 pc403 / pc228 use this to reset a
buffer before the other forms fill it.

## Escape expansion

`expand(raw, inst, vars)` (in `crates/wolf-vm/src/text.rs`) resolves the inline
escapes the strings use in practice — `\cself[n]`, `\cdb[...]`, `\f[...]`,
`\cself[n]` colour tags and the `\\` escape — before the value is stored.

## Verification

- CE94 slot 1 now yields `数据 1` / ` 0:00` / ` 1` / `早泄 ` instead of `000000`.
- Regression coverage: `crates/wolf-game/tests/m3_save_ui_roundtrip.rs`,
  `m3_hud_buttons.rs`, `m3_menu_screens.rs` assert the slot strings.
