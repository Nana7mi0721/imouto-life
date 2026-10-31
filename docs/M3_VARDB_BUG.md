# M3-VARDB：新游戏存档丢失 CDataBase 可变数据库

状态：**已修复**（M3 集成）。`Databases::seed_vardb` 在 `Game::new` 与 `save_to`
两处为空模板补全静态 CDataBase schema（30 类 / 1052 配置 / 静态值），回归测试
`crates/wolf-game/tests/m3_vardb_cdata_roundtrip.rs` 3 条全通过（含原先 `#[ignore]` 的
用例）；新游戏存档 missing=0 / mismatch=0 / stats.unmodelled 不增。
实测静态 CDataBase 为 **649 行**（官方 SaveData01/02 的 650 行是运行期在 type5 追加
一行），因此新存档按静态 schema 649 行落盘，`reconcile_row_counts` 会在脚本设置行数
时追上。残余风险见文末「修复后残余」。

## 结论先行

- 本作 CDataBase（可変DB）共 **19196 个 cell**（30 类 × 650 行 × 1052 个配置字段）。
- **读档 SaveData01 后再 save_to**：19196/19196 个 cell 全部写入，missing=0，mismatch=0。
- **全新 Game::new（未读任何存档）直接 save_to**：19196/19196 个 cell 全部缺失，missing=19196，mismatch=0，stats.unmodelled += 1。
- 根因不是 write_into 的遍历逻辑，而是 **Save/System.sav 模板里的 variable database 是空的**：type_count=0、types=0、rows=0、config=0；save_to 以它为模板，write_into 只能修改“模板里已存在的 type/row/field”，于是每个 cell 都被拒收。
- 读真实存档（SaveData01/02）会把 base_save 换成带完整 vardb 的存档（savegame.rs:87），所以“读档后存档”这条路径正常；这也解释了为什么既有测试只在一个 cell 上看到漂移。

## 实测数据

### 模板 variable database 形状

| 文件 | type_count | types.len | rows 总数 | config 总数 |
|---|---:|---:|---:|---:|
| Save/System.sav | 0 | 0 | 0 | 0 |
| Save/SaveData01.sav | 30 | 30 | 650 | 1052 |
| Save/SaveData02.sav | 30 | 30 | 650 | 1052 |

SaveData01/02 前 8 类的 (config 长度, row_count, rows.len())：

```
[(60, 17, 17), (100, 16, 16), (48, 22, 22), (100, 40, 40),
 (100, 16, 16), (100, 17, 17), (7, 1, 1), (1, 10, 10)]
```

### CDataBase cell 覆盖对比（save_to -> read back）

| 场景 | 活 cell 数 | missing | mismatch | stats.unmodelled |
|---|---:|---:|---:|---:|
| 先 load SaveData01 | 19196 | 0 | 0 | 0 |
| 全新 Game::new | 19196 | 19196 | 0 | 1 |

全新游戏缺失覆盖全部 30 类；首个缺失 cell 是 type0 row0 col0 的字符串 live=Str("ヒーローさん")。写入后的存档文件 vardb 仍为空（types 为空）。

## 最小复现

```rust
let mut game = Game::new(data_root())?;          // base_save = Save/System.sav
game.save_to(&work_out.join("x.sav"))?;          // 无任何 load
let save = savegame::read_save(&work_out.join("x.sav"))?;
assert!(save.vardb.types.is_empty());            // 当前 bug：CDataBase 一个 cell 都没写进去
```

更直观的数据丢失复现（测试 `new_game_save_template_drops_every_cdata_cell` 已钉住）：

1. `Game::new(work/Data)`；
2. 把 CDataBase type6 row0 col1 从静态值 `original` 改成 `original + 1`；
3. `save_to` 到 work/out 临时槽；
4. 全新 `Game::new(work/Data)` + `load_save`：type6 row0 col1 回到静态 `original`，运行时修改丢失（对应 task-25 观察到的 source=0 / loaded=12）。

修复后应使 `new_game_save_preserves_every_cdata_cell_and_runtime_edit` 从 `#[ignore]` 变成通过：missing=0、mismatch=0、stats.unmodelled=0，且 type6 row0 col1 读回 `original + 1`。

## 根因链

1. `crates/wolf-game/src/game.rs:348`
   `let base_save = crate::savegame::read_save(&root.join("Save").join("System.sav")).ok();`
   上方注释（game.rs:346-347）假设 System.sav 是“完整存档文件，可直接当模板”，但实测其 vardb 为空。
2. `crates/wolf-game/src/game.rs:432` save_to 克隆 `self.base_save` 作为输出骨架。
3. `crates/wolf-game/src/game.rs:475`
   `let (written, missed) = self.databases.write_into(&mut save.vardb);`
4. `crates/wolf-game/src/db.rs:544` write_into：
   - `reconcile_row_counts`（db.rs:585）只按运行时 set_row_count 记录调整“已存在的 type”的行数；System.sav 根本没有 type，因此帮不上忙。
   - 随后只遍历 `self.cells`/`self.texts` 中 Container::CData 的覆盖项，调用 `database.set_num/set_text`。
   - `crates/wolf-save/src/vardb.rs:430` 的 set_num：`self.types.get(type_index).and_then(|kind| kind.config.get(field_index))` 取不到就返回 false；`vardb.rs:462/490` 的 set_string/set_text 同样在 type/config/row 不存在时返回 false（“adding the field when the id is absent”只补 field，不补 type/row）。
   - 因此 19196 个 cell 全部计为 missed。
5. `crates/wolf-game/src/game.rs:476-482` 只把 missed 记成一条 diagnostic 并 `stats.unmodelled += 1`，然后 `game.rs:494` 把仍然空的 vardb 写回 `self.base_save`；之后所有新游戏存档继续沿用空模板，bug 不会自愈，直到读入一个真实存档。
6. 读档路径 `crates/wolf-game/src/savegame.rs:87` `game.base_save = Some(save.clone())` 带完整 vardb，随后 `savegame.rs:104` `apply_saved_database` 也只在 vardb 已有 type/row/config 时覆盖。新游戏存档 vardb 为空，所以重载时所有 cell 走静态 .dat 回落（`db.rs:461` num -> `db.rs:735` numeric_cell），运行时改动不可见；大部分 cell 恰好等于静态值，所以只有被脚本改过的少数 cell 会暴露（如 type6 row0 col1）。

## 影响

- 新游戏从标题进入后、在读取任何真实存档之前产生的 CDataBase 运行时修改（250 命令的数据库写入）不会进入存档；重载后全部回落到静态 .dat。
- SaveData01/02 这类官方存档本身带完整 vardb，因此“读档 -> 存档”没有该问题；M3 新游戏跨日测试只观察到 1 个 cell 漂移，是“大多数 cell 与静态值相同”掩盖后的表象。

## 修复建议（按推荐顺序）

1. **在 Game::new 建好 Databases 后，为 System.sav 模板补齐 CData schema**（game.rs:342 之后、game.rs:348 附近）：
   - 若 `base_save.vardb.types.is_empty()`（或缺少 CData 的 type/row/config），用 `databases` 的静态 CDataBase 结构生成完整 vardb：30 个 type、每个 type 的 config（FieldKind::Num(i) => 1000+i，Str(i) => 2000+i，与 Database::FieldKind::raw 一致）、650 行，并按静态 `databases.num/text` 填入初始值；再交给 save_to 的 write_into 覆盖运行时值。
2. **在 save_to 内兜底**（game.rs:475 之后）：若 `save.vardb.types.is_empty()` 或 `missed > 0`，从 `self.databases` 直接构造完整 vardb（包含当前活值）替换 `save.vardb`，而不是只记 warning；这样即使模板不完整也能得到自洽存档。
3. **让 write_into 能补 type/row/config**：在 `db.rs:544` 写 cell 前，按 CDataBase 结构补建缺失的 VariableType/VariableRow（config 默认值参照 Static Database）。这条更靠近数据层，但需要谨慎处理官方存档已有 config 的定义，避免破坏对齐；建议以方案 1/2 为主，3 作为鲁棒性补强。
4. 不建议把 SaveData01 直接当模板：不同游戏版本/不同玩家存档的 schema 可能不同，System.sav 才是设计上的模板；应补齐其 vardb，而不是换文件。

## 验收

- `WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --test m3_vardb_cdata_roundtrip` 当前：2 passed / 0 failed / 1 ignored。
- 修复后：去掉 ignored 测试的 `#[ignore]`，应 3 passed；同时更新/删除 `new_game_save_template_drops_every_cdata_cell`（它按设计钉的是当前 bug 行为）。
- 修复不应改变 `loaded_save_writes_every_cdata_cell_into_the_saved_database` 的 missing=0/mismatch=0。


## 修复后残余

- 补全的字符串单元格按引擎既有约定写 **UTF-8**（`VariableDatabase::set_text`），
  与零售存档的 GBK/CP932 字节不兼容：Rust 引擎自洽，但把这样的存档交给零售
  Game.exe 读取会乱码。M4 需决定写盘编码（见 docs/M4_PARITY.md §3）。
- System.sav 模板本身仍是空 vardb；补全发生在 `Game::new` 的克隆上，不改磁盘文件。
