# 深度代码审查缺陷修复 — 完成交接（2026-11-12）

> 来源报告：`docs/reviews/CODE_REVIEW_4ROUND.md`（第一至四轮，BUG-25 ~ BUG-48；
> 历史基线 BUG-20..24 见报告第六章）。
> **最终状态**：BUG-25..BUG-48 的实施与验收均已完成（T0–T11，2026-11-12）。
> 下文 §2/§5/§6 保留实施细节与语义证据；§1/§3/§4/§7/§8 是任务生成/中断时的
> 历史快照，当前状态以 §0 与 `HANDOFF_M0.md` §11.1 为准。

---

## 0. 最终状态（2026-11-12）

- `cargo fmt --all -- --check`、`git diff --check` 通过；`cargo check -q --workspace` 0 error；
  默认 `cargo test -q --workspace` exit 0。
- 真实数据 workspace 仅 2 项既有 `db` 姊妹作期望差异（英雄默认名、头像图形类型）；
  AutoEvents 3 项与标题 2 项历史差异已由生产修复消除。
- `wolf-cli verify` PASS 64 / 1 SKIP；`precompile` PASS 19 / 0
  （blocks 5416 / loops 881 / implicit_closes 0 / dynamic_labels 3）。
- `m14_visual_regression` 5 passed：title/map_idle/day_command/hud/saveui。
  saveui 恢复 tenths 几何、13 text pictures / 54 glyphs、真实右箭头；
  CE43 不再按电平条件无限重放；CE216 的常驻协程峰值按实际调度计入。
- Godot `build-godot.sh`、`smoke-godot.sh` 通过；`parity-godot.sh 600 --pixel-check=0` PASS。
- 新增 `m16_vm_scheduler` 4 / `m16_runtime_state` 8 / `m16_parallel_input` 5，
  真实数据下全过。
- 新增/更新回归覆盖：Op121/176/121 批量、AutoEvents 电平与 CE43 one-shot、Field18、
  读档 BGM flush、DB 字符串槽、`\cself`、滚轮/鼠标帧差、174/211、picture_state/Op124、
  character_state/Op160/1000、Erase 淡出、Godot 瓦片层/blend/退出设置、并行鼠标输入。

---

## 1. 任务生成时的状态快照（历史）

**Wave 1（`wolf-vm` / `wolf-audio` / 调度器 / 文本层 / 基线工具）已完成且测试通过；
Wave 2 的代码大多已落地，但工作区当前 `cargo check` 失败（7 个编译错误），
原因是 `PictureCmd.owner_event` / `SpriteQuad.blend` / `reset_to_title` 的跨文件收尾被打断。**
只需修 5 处编译错误 + 跑通全套验证即可继续。

---

## 2. 已完成并已验证（Wave 1）

### 2.1 `crates/wolf-vm/`（`cargo test -p wolf-vm` = 120 lib tests + 各集成测试全绿）

| 缺陷 | 实现要点 |
|---|---|
| **BUG-36** `Opcode 176` | 正名为 `ContinueLoop`。`program.rs` 不再把 176 当循环头（`111\|112\|102\|170\|179`）；`exec.rs` 新增 `176 => close_loop(inst, ctx.block)`（复用 498 的计数/回跳逻辑）。新增单测 `continue_loop_176_does_not_open_block`、`bug_36_continue_loop_jumps_back_or_exits_counted`。 |
| **BUG-27** `Opcode 121` | 完整实现 `arg3` 位域（见 §6.1）：`0x01` 钳制 ±999999、`0x02` 实数（f64）计算、`0x04/0x08` 右值不求值、`0x10` 左值二阶指针、`0x20/0x40` 右值二阶指针、`0x0F00` 复合赋值、`>>12` 二元算子、bit16 批量（count=arg4）。移除 `resolve_numeric_target` 启发式。`eval_num(CommonSelf)` 改为真正读取 `vars.common_self`。新增 `binary_op_f64` / `compound_f64` / `eval_arith_operand_host`。 |
| **BUG-29** 双射 | `Instance.self_vars` 与 `Variables.common_self` 实时双写：`store_num`/`store_str` 对 `SelfVar` 600..700（字符串 605..609）同步 `common_self`；对 `CommonSelf` 写入生成 `CrossWrite`，`run_instances` 在 `execute` 返回后广播到所有同事件活跃实例。`spawn_child` 的实参同时写入 `common_self` 与其他实例。`reap_finished` / `stop_instance` 不再整包回写覆盖。新增 `Vm::set_instance_self_var`。 |
| **BUG-28** `Field 18` | `Instance.is_parallel` 字段 + `Vm::set_instance_parallel`；`124` `field 18` 依次取 `host.engine_state(18)` → 前台活跃事件（`run_instances` 计算，含等待中的前台）→ 自身 ID 兜底。 |
| **BUG-30** `Opcode 125` | `InputState` 增加 `auto_keys_ttl`、`auto_keys_delivered`：注入后 2 帧有效，同帧内每个协程只投递一次，先于注入者执行的协程下一帧仍能读到。`Copy` 已改 `Clone`。 |
| **BUG-31/38** `CSelf5..9` | `Magic::is_string_slot(raw, is_map_context)` + `Magic::is_sys_str()`；`250` 写库与 `220..=222` 文件参数统一使用该判定。 |
| **BUG-32（VM 侧）** | `Host::reserve_with_args(event, args, strings)`（默认转发 `reserve`）；`211` 解析实参后转发。`Signal::ReturnToTitle` 改为清空全部实例并返回。 |
| **BUG-35（VM 侧）** | `180` 求值 ≤0 时不再 `.max(1)`，直接继续；`PictureCmd.owner_event` 已加入（公共事件 → `Some(event)`）。 |
| **BUG-37** | `SoundCmd` 增 `pitch`；`140` 对 `arg1`(fade/delay)、`arg2`(db_id)、`arg4`(volume)、`arg5`(pitch) 全部 `eval_num`；stop 判定改为 `sound_type==0xFF \|\| process_type==2/3 \|\| (0,0xFFFF) \|\| (1, db_id<0)`；preload（process_type==1）不发声；volume/pitch 为 0 时回退 100（与原版 `FUN_0045abb0` 一致）。 |
| **BUG-39** | `130` 的 target/x/y/map 全部 `eval_num`；`151` 第 0 参为打包 RGB，**保持 raw**、仅 `frames` 求值。 |

### 2.2 `wolf-audio` 测试适配
`SoundCmd` 新增 `pitch` 后同步 `tests/{audio,m4_soundcmd,mixer_contract}.rs`；`cargo test -p wolf-audio` 全绿。

### 2.3 `crates/wolf-game/src/{auto_events,map_runtime,textpic}.rs`

- **BUG-25**：`AutoEvents::sync` 改电平触发（`now && !alive` 即启动；`running` 只在实例仍存活时保留）。新增 `reset()` 与 `set_instance_parallel` 调用；新增电平触发单测。
- **BUG-33**：`start_pending_with` 仅在「非 Parallel 活跃页」时才因 `pc>0 || wait!=None` 延迟换页；Parallel 页立即快照 self 并切换。新增单测（Parallel 立即切换 / ActionKey 仍延迟）。
- **BUG-35（`\sdb`）**：`Cells` trait 增加 `sdb()` 默认实现；`VarBank::SysDb` 走 `sdb` 而非 `cdb`；新增单测。

### 2.4 基线与工具
- `docs/BASELINE.json`：`blocks 5470→5416`、`loops 935→881`、`implicit_closes 54→0`。
- `tools/audit_bytecode.py`：循环栈改为 `if c in (170, 179)`（176 不是循环头）。
- `crates/wolf-cli/src/main.rs`：`run_precompile` 同步上述三项；已实测
  `wolf-cli precompile` = **PASS 19 / 0 pending**。

### 2.5 图形层（已改，尚未编译验证）

- `picture.rs`：`Picture.owner_event: Option<u32>`；Draw/Set/Move 均透传。
- `atlas.rs`：`SpriteQuad.blend: i32`；面板/普通路径均透传 `picture.blend`；新增传播单测。
- `wolf-gdext/src/lib.rs`：`sprite_dict` 导出 `"blend"`；`sounds` 导出 `"pitch"`；packet 导出 `"bgm_volume"` / `"se_volume"`。
- `godot/scripts/GameView.gd`：master BGM/SE 音量、track 音量、pitch、`_gain_to_db`、blend 批处理（`Node2D` 池 + `CanvasItemMaterial` ADD/SUB/MUL，MUL 忽略 opacity；全 normal 时走原直绘快路径）。

---

## 3. 原编译错误（历史，已全部修复）

`cargo check -q -p wolf-game` 输出：

| # | 位置 | 错误 | 修法 |
|---|---|---|---|
| 1 | `crates/wolf-game/src/choice.rs:335` | `SpriteQuad` 缺 `blend` | 加 `blend: 0,`（选项面板无混合） |
| 2 | `crates/wolf-game/src/choice.rs:349` | 同上 | 同上 |
| 3 | `crates/wolf-game/src/tilemap.rs:303` | 同上 | 加 `blend: 0,` |
| 4 | `crates/wolf-game/src/tilemap.rs:326` | 同上 | 加 `blend: 0,` |
| 5 | `crates/wolf-game/src/game.rs:675` | `retail_rng_seed: game_dat...` 类型不符（`u16` vs `u32`） | 字段统一为 `(u32, u32, Vec<u8>)`，或在赋值处 `.into()` |
| 6 | `crates/wolf-game/src/game.rs:1345` | `WolfRng::from_game(*random_a, *random_b, ...)` 参数类型不符 | `WolfRng::from_game((*random_a).into(), (*random_b).into(), ...)` |
| 7 | `crates/wolf-game/src/game.rs:1812` | `PictureVars` 无 `owner_event` 字段 | 给 `struct PictureVars` 加 `owner_event: Option<u32>`，并在 `text()` 里优先读 `vars.common_self[owner_event]`（槽 5..9 为字符串，其余为数字转字符串） |

> 说明：`game.rs` 的 `reset_to_title`、`reserved_events`、`pending_sounds`、`frame_mouse_blocked`、
> `frame_wheel_delta`、`bgm_volume`/`se_volume`、`db.rs::reset_runtime` 已落地（grep 可见），
> 但因上述错误尚未编译验证。

---

## 4. 实施任务清单（历史；T0–T11 已完成）

### 4.1 Wave 2 收尾（编译通过后逐项确认）

1. **`PictureVars` / `text_quads`**：确认 `Game::text_quads()` 按 `picture.owner_event` 构造
   `PictureVars`，且 `text()` 的 `\cself[n]` 能读到公共事件字符串槽与数字槽。
2. **`PictureCells::sdb`**：确认 `Container::Sys` 的 text→num 回退存在（`\sdb`）。
3. **`GameHost::engine_state`**：确认 `10 => frame_wheel_delta`、`11 => mouse.x-prev.x`、
   `12 => mouse.y-prev.y`（原版手册：11/12 是**帧间位移增量 dx/dy**，不是绝对坐标）。
4. **`apply_wheel`**：确认 `frame_wheel_delta` 记录 + CE223 活跃时不再自行注入 LEFT/RIGHT（避免双重翻页）。
5. **`sync_save_grid_cursor`**：确认改用 `Vm::set_instance_self_var(id, 610, slot)`。
6. **`Host::return_to_title` / `reserve_with_args`**：确认 `GameHost` 已实现；
   `174` → `pending_return_to_title`；`211` → `reserved_events` 队列，前台空闲时弹出启动。
7. **`reset_to_title`**：确认重载 `Vm::new(programs)`、重置 `retail_rng_seed`、`seed_live_settings`、
   `Sys115/116/117`、`databases.reset_runtime`、`auto_events.reset`、重新 `boot()`。
8. **读档 BGM**：`savegame.rs` 向 `pending_sounds` 推送 BGM Play/Stop，`Game::frame` 开头与
   `SaveRequest::Load` 之后都要 flush 进 `self.sounds` 并累加 `stats.sounds`。
9. **`db_read` 字符串/数字分流**：`wants_text` 覆盖 `StrVar` / `SysStr` / `1_600_005..=1_600_009` /
   `CommonSelf(5..=9)`；文本读只查 `engine_text`→`text`，数字读只查 `engine_num`→`num`
   （不要让数值 0 污染空字符串标签，如 CE94 pc395）。
10. **`ENGINE_RESTART`**：已为 `[216, 270, 271]`。**严禁**加入 `48 / 214 / 261 / 269`（见 §6.5）。
11. **Godot 前端**：`GameView.gd` 的 blend 批处理/音量/pitch 需 `tools/smoke-godot.sh` 实跑验证；
    确认 `godot/tests/*.gd` 未依赖被改动的 packet 键。

### 4.2 Wave 3 验证与回归

```bash
cd '/e/Study/github program/Imouto Life' && source tools/env.sh >/dev/null 2>&1
cargo check -q --workspace
cargo test -q --workspace
WOLF_DATA_ROOT="$PWD/work/Data" cargo test -q --workspace --no-fail-fast
WOLF_DATA_ROOT="$PWD/work/Data" ./target/debug/wolf-cli.exe verify      # 期望 PASS 64 / 1 SKIP
WOLF_DATA_ROOT="$PWD/work/Data" ./target/debug/wolf-cli.exe precompile  # 期望 PASS 19 / 0
cargo test -q -p wolf-cli --test m14_visual_regression                  # 基线可能需重录
bash tools/smoke-godot.sh
bash tools/parity-godot.sh --pixel-check=0                              # 先只比 VM 统计
```

建议新增 `crates/wolf-game/tests/m16_deep_review_regressions.rs`，覆盖：
- `176` 在 `CE 63/212/268/270` 的循环栈平衡；
- `121` flags `0x04/0x20/0x10/0x01/0x02` 与批量位；
- `AutoEvents` 在 `CE 281/282/241/242` 上的电平持续存活；
- `124 Field 18` 让 `CE 223` 命中窗口分支；
- 读档后 `pending_sounds` 产生 BGM 命令；
- `Picture.owner_event` → `\cself` 文本解析。

**注意**：以下既有基线/期望可能因行为修正而变化，需按实测更新并写明理由：
`m14_visual_regression`（`CE 270` 循环修正后每帧指令/picture 计数变化）、
`m2_daily_loop`/`m3_week_loop` 的 `stats.sounds == 6`、`m14_event_reachability` 的 sounds 列、
`docs/BASELINE.json` 中与 picture/blend 相关的键。

### 4.3 文档与清理（收尾）

- 追加 `docs/HANDOFF_PROGRESS.md`；更新 `docs/HANDOFF_M0.md` §11.1。
- 按 `AGENTS.md` §7 清理 `target/debug/incremental`、`target/release`、`work/out` 探针；
  记录 `du -sh .`。
- 不要提交 `target/`、`work/`、Godot 生成物。

---

## 5. 与报告描述不一致、以实测为准的结论

> 下表按官方手册 + 原版 `Game.exe` 反编译实测修正；现行四轮报告仍沿用这些原始说法，
> 修复时以本表为准。

| 报告说法 | 实测结论 |
|---|---|
| `BUG-26` 建议 `ENGINE_RESTART = [214,216,261,270,271]` | **错误**。`CE 48/261/269` 是 `Wait(999999)+BreakEvent` 一次性初始化；`CE 214` 末尾 `150 [16777218,200,…,210]` 会**每帧清掉 HUD 200..210**。正确值：`[216,270,271]`。`CE 216`（16 条，末尾 `Wait(1)`）与 `CE 271`（157 条，无循环/等待）确实需要逐帧重启。 |
| `BUG-27` 称 flags `0x01` 为实数、`0x02` 未定义 | 手册 `04ev_value.txt` + `FUN_00453720`：**`0x02` 才是实数（f64）计算**；**`0x01` 是「结果钳制到 ±999999」**。另有 bit16 = 批量（数量在 arg4）。 |
| `BUG-39` 称 `151` 的 RGB 参数需 `eval_num` | `151` 首参是**打包 RGB 色值**（如 `2_629_150`，恰好落在 `VAR_BASE` 区间），绝不能 `eval_num`（会被当变量读成 0）。只有第 2 参 `frames` 需求值。`130` 的四个数值参数才全部需要 `eval_num`。 |
| `BUG-40` 称 blend 为 `2/3/4` | 手册 `04ev_picture.txt` + `FUN_004bd8e0`：`0=通常, 1=加算, 2=减算, 3=乘算`，且**乘算忽略不透明度（强制 255）**。 |
| `BUG-40` 称前端每帧销毁重建 `Sprite2D` | 实际 `GameView.gd` 是即时 `_draw()`（无 `Sprite2D` 树）；性能问题真实存在但形态不同。本次改为「全 normal 时零额外节点，混合时才用池化 `Node2D` 批层」。 |
| 旧台账 `BUG-22`（鼠标移出窗口 11/12） | 手册 `04ev_valuenext.txt`：`field 11/12` 是**鼠标帧间位移 dx/dy**，不是绝对坐标/出界标志。按 dx/dy 实现。 |
| 报告称 `Map 5 Ev 17` | 实际是 `SampleMapA.mps` 的 **Event 17**（`コマンド実行`，7 页；P0 `trigger=2` Parallel 4980 条，P1..P6 `trigger=1` Autorun）。 |

---

## 6. 本次核实的关键语义（供后续复用）

### 6.1 `Opcode 121`（`変数操作`）位域

```
arg3 = word
flags      = word & 0xFF         # 0x01 clamp±999999, 0x02 real(f64), 0x04/0x08 rhs字面量, 0x10 lhs间接, 0x20/0x40 rhs间接
assign_op  = word & 0x0F00       # 000 =, 100 +=, 200 -=, 300 *=, 400 /=, 500 %=, 600 max, 700 min, 800 abs,
                                 # 900 angle, A00 sin, B00 cos, C00 sqrt（以现有 compound 表为准）
bin        = (word >> 12) & 0x0F # 0 +, 1 -, 2 *, 3 /, 4 %, 5 &, 6 rand, 7 |, 8 ^, 9 <<
batch      = word & 0x10000      # 成立时对 raw_lhs + 0..=arg4 逐个执行
```
证据：`work/out/re_all/all/00453720_FUN_00453720.c`（L283–L436 二阶指针、L439–L543 整数/实数分支、L544+ 实数模式）、`work/out/wolfmanual/txt/04ev_value.txt`（L43–L46、L67–L68）。
`1_000_000` 作为字面量乘数的特例（CE79/CE94）仍需在 `eval_arith_operand*` 中保留。

### 6.2 `Opcode 176`（`ループ開始へ戻る` / ContinueLoop）

54 处，全部位于 `170` 循环体内且**无配对 498**。语义 = 跳到最内层 `170` 头进入下一轮；
对 `179` 计数循环等价于 498 的递减/退出。修正后 `precompile`：blocks 5416 / loops 881 / implicit_closes 0。

### 6.3 `Opcode 124` `0x3000` 字段

- 10 = 滚轮增量（1 帧变化值）
- 11/12 = 鼠标 X/Y **帧间位移**
- 17 = 本公共事件 ID（地图事件为 -1）
- 18 = 处理中的自动/接触/决定键事件 ID，公共事件 +500000
- 20/21 = 画面相对鼠标坐标
证据：`04ev_valuenext.txt` L79–L206；`FUN_00458580.c` case 0x12/0x13。

### 6.4 `Opcode 140`（`Sound`）

`bits`：低字节低 niblle = process（0 播放 / 1 预载 / 2,3 停止），第 2 字节高 nibble = 通道（0 BGM/1 BGS/2 SE）；
`(bits>>8)&0xFFFF` = SystemDB 行号；`(bits>>24)&0xFF` = sound_type（0 DB 行 / 1 变量 DB ID / 2 文件名 / 0xFF FreeAll）。
`arg1` fade/延迟、`arg2` 变量、`arg4` 音量、`arg5` 音调；音量和音调 0 → 100（`CE 49 pc=115` 注释与 `FUN_0045abb0` 均证实）。
证据：`work/out/re_all/all/0045abb0_FUN_0045abb0.c` L50–L227。

### 6.5 `ENGINE_ALWAYS` / `ENGINE_RESTART`

- `ENGINE_ALWAYS = [48, 261, 269, 270, 271, 214, 216]`（`run_condition == 3`），启动时应标 `is_parallel = true`。
- `ENGINE_RESTART = [216, 270, 271]`。**不可**加入 `48/214/261/269`：
  - 48/261/269：首帧 `Wait(999999) + 172 BreakEvent`，重启会重跑初始化；
  - 214：`pc=164` 的 `150 [16777218, 200, 0, 0, 0, 210]` 每帧清 HUD 槽 200..210。

### 6.6 `AutoEvents`（`run_condition == 2`）

原版是**电平触发**：条件成立且当前无活跃实例 → 下一帧重启。修复后 `CE 223/224/242/243/281/282` 等
21 个无内部循环的事件才能持续工作（此前只跑一次便永久失效）。

### 6.7 `MapRuntime` 换页

- `Trigger::Parallel`：条件一变立即切换（WOLF 并行页无“同步执行”语义）。
- `Trigger::ActionKey` / `Autorun`：若实例 `pc > 0 || wait != None`，必须延迟到当前脚本跑完
  （BUG-09 回归：`m3_event_page_switch.rs`）。

---

## 7. 已执行的下一步顺序

1. 修 §3 的 7 个编译错误（5 个文件，纯机械改动）。
2. `cargo check -q --workspace` → `cargo test -q --workspace`（先默认数据根，确认无 skip 假绿）。
3. 逐项走 §4.1 的 10 条确认（grep/读代码即可），补 §4.2 的 `m16` 回归测试。
4. 真实数据全量测试 + `verify` + `precompile`，按实测更新 `m14` 基线与 `stats.sounds` 期望。
5. `bash tools/build-godot.sh` → `bash tools/smoke-godot.sh` → `bash tools/parity-godot.sh --pixel-check=0`；
   像素基线（600 帧 MAE）如有变化，记录原因（`CE 270` 循环修正会影响每帧 picture 计数）。
6. 文档（HANDOFF_PROGRESS / HANDOFF_M0 §11.1）+ 空间清理（AGENTS §7）。

---

## 8. 任务生成时的工作区快照（历史）

- 已修改（未提交）：`wolf-vm/{exec,magic,program}.rs`、`wolf-audio/tests/{audio,m4_soundcmd,mixer_contract}.rs`、
  `wolf-game/src/{atlas,auto_events,db,game,map_runtime,picture,savegame,textpic}.rs`、
  `wolf-gdext/src/lib.rs`、`godot/scripts/GameView.gd`、`wolf-cli/src/main.rs`、
  `docs/BASELINE.json`、`tools/audit_bytecode.py`。
- 审查报告：现行 `docs/reviews/CODE_REVIEW_4ROUND.md`（第一至四轮，含 BUG-41..48）；
  第一、二轮单行本已归档 `docs/archive/reviews/CODE_REVIEW_1_2ROUND_superseded.md`（被取代）。
- 编译：任务生成时 FAIL（7 errors，见 §3）；最终已恢复 0 error。
- 已验证通过：`cargo test -p wolf-vm`（120 lib + 集成）、`cargo test -p wolf-audio`、
  `wolf-cli precompile`（PASS 19/0）。
- 最终已运行：默认/真实数据 workspace、`verify`、`precompile`、`m14`、
  Godot build/smoke/parity，结果见 §0。
