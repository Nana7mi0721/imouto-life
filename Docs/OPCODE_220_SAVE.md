# Opcodes 220 / 221 / 222 — save-file access

The three save opcodes share one wire shape but mean different things. They are
decoded in `crates/wolf-vm/src/exec.rs` into a single `SaveOp`
(`opcode`, `mode`, `file`, `destination`, `address`, `value`, `flag`,
`owner`) and handed to `Host::save_load`, which returns
`Option<DbValue>` (a number or, for database string cells, text).

| opcode | name | meaning |
|--------|------|---------|
| 220 | SaveLoad | full save / load of the whole game state |
| 221 | LoadGame | read **one** value out of a save file into a running variable |
| 222 | SaveGame | write **one** value into a save file |

## 1. Operands

```
220 [mode, file]                 mode 0 = save, 1 = load
221 [dst, file, address, flag]   dst := read(file, address)
222 [src, file, address, flag]   write(file, address, src)
```

- `mode` is evaluated as a number.
- `src` (222) is evaluated as a number.
- `flag` (the trailing operand) is evaluated as a number; it is 0 in 34 of the
  37 `221` sites and in all `222` sites and carries no modelled meaning here.
- `dst` (221) stays a **raw** address (it is the variable the answer is stored
  into via `store_num`/`store_str`).
- `address` (221/222) is a **value**: it is a literal save-bank address or a
  self variable that holds a computed database address, so it is evaluated with
  `eval_save_address` before the host sees it (§4).

## 2. The file operand

A save target is a slot or an explicit path, chosen by the magic **kind** of the
file operand, not by its value (§2.1):

- a **string variable** holds an explicit path (`SaveTarget::Path`, e.g.
  `"Save/System.sav"`);
- anything else is a numeric **slot** number (`SaveTarget::Slot`, one-based;
  the engine maps slot `n` to `Save/SaveDataNN.sav`).

## 3. 221 read semantics

`read_save(path)` parses the `.sav`; then `save_address(save, op)` resolves the
address against one of the banks in §4. A **missing slot** is not an error: the
game probes slots with `221` to decide whether to draw "没有数据", so a failure
to parse yields `Some(DbValue::Num(0))`.

## 4. Address banks

The address is an absolute value in one of these banks:

| range | bank | resolution |
|-------|------|-----------|
| `2_000_000..=2_999_999` | normal variables | `save.normal_var(addr - 2_000_000)` |
| `1_600_000..=1_699_999` | self variables | `save.self_var(op.owner, addr - 1_600_000)` — relative to the **issuing** event |
| `9_000_000..=9_099_999` | system variables | index 29 = play time in **minutes** (`frames / 60`); 24 = constant 1; 0..=12 = `part2.vars3_21[index+6]` |
| `1_100_000_000..=1_200_000_000` | computed database cell | `off = addr - 1_100_000_000`; `type = off / 1_000_000`; `row = (off % 1_000_000) / 100`; `col = off % 100`; numeric column via `vardb.number`, else `vardb.string` decoded as text |

### 4.1 Database string cells

A computed database address can point at a text column (the hero name, the term
label, …). The raw fixed-width cell ends in a single `0x00` terminator, which
`WolfSave` strips like `MemData::toString`; the engine therefore strips **only
that one trailing NUL** and keeps intentional trailing spaces (the term cell
stores `"数据 "` with a trailing space on purpose). The bytes are decoded with
`wolf_format::bytes::decode_wolf_str` — the game's CP932/GBK detector — never
with a UTF-8 lossy conversion, which would garble the CP932 hero name.

## 5. 222 write semantics

`222` writes one **numeric** value into a save file (`write_save_address`): the
normal / self / system banks above are supported; a computed database cell is
not written here (those go through `250`). An address outside every bank is
reported as a diagnostic rather than silently dropped.

## 6. Why evaluating the address matters (bug history)

CE94 builds the database addresses by arithmetic on `1_000_000` in `121`, then
stores them in self variables and passes the *variable* to `221`. Two bugs
compounded: `121` evaluated the literal `1_000_000` through `Magic::decode` as a
self-variable reference (`self[0] == 0`), collapsing `1_106_000_001` to
`1_100_000_001`, and `221`/opcode `250` had to treat their address/type operands as
values, not raw slots. With both fixed, slot 1 reads the real hero id (type 6
row 0 col 1 = 12), the character name (`早泄 `) and level (1) from `SaveData01.sav`.
