# 交接归档：POST_DEEPSEEK 19 项审查修复与 BUG-02 收尾（已完成）

> 读者：接手本任务的 agent。开工前请先读 `AGENTS.md` 与 `docs/HANDOFF_M0.md`。
> **状态：已完成（2026-11-11）。** BUG-02 已闭环，18 项确认缺陷修复和 BUG-04 的原版设计判定均已验证；
> 本文保留为历史交接与排查记录，**不要重做已完成的修复**。
> 当前工作区**故意未提交**，包含本轮的源码、测试和文档改动；临时调试打印已删除，清理已完成。

---

## 1. 任务来源与总体状态

审查报告：`work/out/review/POST_DEEPSEEK_BUGS_INVESTIGATION_REPORT.md`

报告共 19 项：

- **18 项 CONFIRMED 缺陷已修复**（VM、输入、存档、地图、音频、渲染、退出）。
- **BUG-04 判定为 NOT-A-BUG**：日常顶栏只有文本、没有体力条，是原版设计。
- **BUG-02 已闭环**：`112` 字符串条件错误保留了 bit 24 的变量类型标志，导致 CE270 每帧误判“消息变化”并隐藏名字牌；修复后名字牌在消息期间连续可见。

本交接任务已经完成：

1. 气泡名字牌在消息显示期间持续可见，回归测试要求连续至少 60 帧；
2. 临时调试代码已删除；
3. 默认/真实数据/verify/视觉回归/Godot smoke/parity 已验证；
4. 文档已同步，里程碑清理已完成；
5. 工作区未 commit（除非用户另行指示）。

---

## 2. 已确认并已落地的修复（不要重做）

### 2.1 VM / 字节码语义

| 项目 | 内容 |
|---|---|
| BUG-01 | `250` 在 argc≥5 时，若第 5 操作数是 `3_000_000+n` 字符串变量，按字符串写库，不再写成数字地址 |
| BUG-12/19 | `210/211` 的 `600_000..699_999` 按“调用者 + (raw - 600_100)”解析；CE264 的 `600104` 到达 CE268 |
| 跨事件公共 Self | `15_000_000 + 100*event + slot`；槽 5..9 是字符串。CE268 写 CE269 CSelf5，CE270 读回 |
| `121/122` | 间接数值/字符串目标：Self 槽保存地址时解引用；`122` 保留字符串高级操作 |
| BUG-13 | `213` 动态标签未命中时告警并继续执行，不再杀整个协程 |
| BUG-14 | `125` 自动按键只在当前帧有效，帧末清零 |
| BUG-03/09/10/16 | 图片/文字按 Picture Slot 排序；地图换页不再强杀运行中实例 |
| BUG-15 | `mouse_consumed` 改为广播语义，不再让并行事件读不到点击 |
| BUG-17 | BGM/BGS 独立总线；同路径重复 SoundCmd 只更新音量，不从头重启 |
| BUG-11 | `175 EndGame` 触发进程退出 |
| BUG-18 | 选择支外点击不再被吞掉 |

### 2.2 为气泡库补齐的 WOLF 语义

这几项是 BUG-02 数据链能跑通的前提，已经实现并有测试：

1. **`112` 字符串条件**
   - 最高半字节是比较模式：`1 = 不相等`，其余按相等。
   - 去掉最高半字节后，bit 24 是字符串变量类型标志，低 24 位才是字符串变量 magic。
   - 两种布局：
     - `argc == 1 + count`：右值是 `cmd.strings[i]` 字面量；
     - `argc > 1 + count`：每对操作数是两个字符串变量（CE270 用这种）。

2. **SysStr25 = 当前消息缓冲**
   - magic `9_900_025` 解码到系统字符串索引 `900_025`。
   - `Game::frame` 每帧把 `messages.first().text` 写入 `SysStr25`，并维护 `Sys12`（是否有消息）。

3. **Sys115/116/117**
   - CE261 只在 `Sys115 == 220` 时按 `Sys116/117` 计算屏幕常量。
   - 现在初始化：`Sys115=220`、`Sys116=1024`、`Sys117=576`。
   - CE261 由此得到 `2700000..2700003 = 512,288,512,288`、`2700004=24`、`2700005=19`。

4. **MAX_SLOTS**
   - `crates/wolf-vm/src/vars.rs` 的 `MAX_SLOTS` 已从 65,536 提升到 1,000,000。
   - 原因：插件使用 `2_700_001..2_700_005` 这类高位保留普通变量；旧上限会静默丢弃。

5. **常时事件重入**
   - `Game::ENGINE_RESTART = &[270]`。
   - CE48/261/269 是一次性初始化器；CE214 末尾清 HUD 槽 200/210；都不能每帧重入。
   - CE270 本身是持续运行的显示协程，`restart_always_events` 只在没有 270 实例时启动它。

### 2.3 BUG-02 数据链已打通

数据链：

```text
SampleMapA Event 1
  -> 210 [500264, .., "妹妹"]          (CE264 接口)
  -> CE264 pc47: 210 [600104, .., self5]
  -> 600104 相对调用 = CE268（不是 CE104）
  -> CE268 写 CE269 CSelf5 = "妹妹"
  -> CE270 读 CE269 CSelf5
  -> CE270 画图片 36014，文本 "\\>妹妹"
```

回归测试：`crates/wolf-game/tests/m15_balloon_name.rs`

- 数据门槛：无 `work/Data` 时打印 skipping 并 return。
- 当前断言（2026-11-11 加强）：
  - `common_self[269].get_str(0) == "妹妹"`；
  - 消息显示期间图 `36014` 连续可见至少 60 帧，文本包含“妹妹”；
  - 图片矩形非空且完全位于 1024×576 内；
  - `game.stats.warnings == 0`。
- 真实数据下测试 **1 passed**。

运行：

```bash
cd '/e/Study/github program/Imouto Life' && source tools/env.sh >/dev/null 2>&1
WOLF_DATA_ROOT="$PWD/work/Data" cargo test -q -p wolf-game --test m15_balloon_name -- --nocapture
```

---

## 3. 历史排查记录：名字牌每帧被 CE270 隐藏（已解决）

> 以下内容记录定位过程，供以后回溯；根因与修复见 §3.2，无需重复排查。

### 3.1 已观察到的事实

临时 trace（见 §4 的调试打印）显示：

- 名字牌首次绘制：
  - `CE270 pc1880`：`150 [head=69699, number=36014]`，action = Hide；
  - `CE270 pc1885`：`150 [head=4128, number=36014, ..., x=-236, y=-80, ...]`，文本 `\>妹妹`；
  - 随后 `36008`（名字底板）、`36009..36012`（四角）等一起绘制。
- 之后每一帧都执行：
  - `CE270 pc1985/1988`：再次 Hide `36008` / `36014`；
  - `CE270 pc1989`：Move（相对偏移 `-1000000` 表示不变）；
  - `CE270 pc1992/1993`：Hide/Move `36009..36012`。
- 隐藏分支来自：
  - `CE270 pc1752`：`111 [17, self56, 1, 2]`，条件 `self56 == 1`；
  - 匹配时进入名字显示块；不匹配时 `420` 的 else 是 `pc1984..1994`，即隐藏名字牌。
- `self56` 的赋值：
  - `pc407`：`self56 = 0`（每次进入“测量/刷新”块都清 0）；
  - `pc469`：`self56 = 1`（名字部分计算完成后置 1）。
- 后续帧的 VM trace 中 `self56 = 0`，同时 `self15 = 0`（人名栏模式，来自窗口 DB 第 9 列）；`self15 = 2` 只在窗口刚打开的那一帧出现。
- 消息本身没有消失：测试每帧都打印 `frame msg="…什么？" sys12=1 sysstr25="…什么？"`。
- 图片坐标不是“屏外”：
  - `36014` 的 x/y 字段是 `(-236,-80)`，这是相对偏移；
  - `CE270 pc2224..2230` 用 `290` kind 2（`EFFECT_SHIFT`）把 `36000..36015` 整组 shift 到 `(512,536)`；
  - 实际屏幕位置约 `(276,456)`，所以不要按 `picture.x/y` 直接判断屏外。

### 3.2 已确认根因与修复

`CE270 pc92` 的 `112` 操作数是 `0x11186A05`：

- 最高半字节 `1` 是比较模式（**不相等**）；
- bit 24 是字符串变量类型标志；
- 低 24 位 `0x00186A05 = 1_600_005` 才是 CSelf5。

旧 `eval_string_condition` 只去掉比较模式、保留了 bit 24；`eval_str` 因此把操作数解码到 Self 池之外并返回空串，使 `CSelf5 != SysStr25` 每帧都成立（误判“消息变化”）。测量块随后反复把 `self56` 清 0，CE270 进入隐藏分支，名字牌只显示一帧。

修复：

- `crates/wolf-vm/src/exec.rs::eval_string_condition` 对左右操作数统一使用 `raw & 0x00FF_FFFF`；
- 新增单测 `string_condition_strips_the_variable_type_flag_from_cself_operands`，覆盖带 `0x0100_0000` 类型标志的 CSelf5；
- `m15_balloon_name` 的“曾经生成过”断言已加强为连续 60 帧可见、矩形在屏内、文本含“妹妹”、`warnings == 0`。

此前关于“CE270 每帧重启”“字符坐标或 `character_state` 缺失”“Case 块结构错误”的假设均已排除。固定模式 `2002` 的位置由 `290` kind 2 对 `36000..36015` 的 `(512,536)` 平移得到，`36014` 实际约在 `(276,456)`。

### 3.3 历史调试步骤（已执行完毕）

当时按以下顺序定位，记录在此避免重复：

1. 在 `CE270` 的 `pc379`、`pc407`、`pc468/469`、`pc1752`、`pc2038` 加临时打印：
   - `self5/self6` 字符串；
   - `self15/self50/self55/self56`；
   - `SysStr25`；
   - 当前实例 id、pc、是否 finish。
2. 打印 `Vm::reap_finished` 时 CE270 的实例 id 与 `bank_from(inst)`，确认它是否每帧重启。
3. 检查 `seed_common_self`/`save_common_self` 的时序，判断跨帧状态到底存在实例里还是 durable bank 里。
4. 修复方向应是“让窗口打开状态和名字存在状态跨帧保持”，不是“强行不隐藏”：
   - 如果 CE270 应持续运行：确保它不被提前 finish，且 `self56` 在每帧路径中不被错误重置；
   - 如果 CE270 确实每帧重启：把 `self50/self55/self56` 纳入 durable bank 的正确写回时机，或在每帧路径中根据 `SysStr25`/消息状态重新建立 `self56`。
5. 修复后强化 `m15_balloon_name`：连续帧断言、屏幕矩形检查、无数据跳过均已落地。

### 3.4 不要做的事

- 不要伪造 `character_state` 坐标来“把图片挪到屏幕上”。当前气泡是固定模式（`2002` 底部），名字牌位置由 `290` shift 决定，已在 1024×576 内。
- 不要为了让人名牌常驻而删掉 CE270 的隐藏分支；隐藏分支在“无消息/换窗口/名字为空”时是正确行为。
- 不要把 `ENGINE_RESTART` 扩大回所有 `ENGINE_ALWAYS`；CE48/261/269/214 会产生 HUD 或初始化回归。

---

## 4. 临时调试代码（已于 2026-11-11 删除）

以下打印曾用于排查，现已全部移除；按这些标记搜索源码应无命中。若重新出现，说明调试代码回退：

### `crates/wolf-vm/src/exec.rs`

- `execute()` 内：`VM ce270 pc=...` 调试打印（约 2041–2045 行附近）。
- `Control::Case` 分支：`CASE pc=... block=... head=...` 打印（约 2063–2068 行）。
- `Control::LabelJump` 分支：`LABEL pc=... name=... target=...` 打印（约 2082–2087 行）。
- `enter_block()` 的 `BlockKind::Condition`：`ENTER block=...` 打印（约 3050 行）。
- `decode_picture()` 末尾：`DECODE ce...` 打印（约 3390 行）。

### `crates/wolf-game/src/game.rs`

- `GameHost::picture()` 内：`PIC ...` 打印（约 3199–3208 行）。

### `crates/wolf-game/tests/m15_balloon_name.rs`

- `frame msg=...`
- `strings 270: ...`
- `bank frame self...`
- `frame pic ...`
- `screen consts 2700000..5 = ...`
- 末尾 `cself270[...]` 循环
- 这些可以保留少量“失败时输出上下文”，但正常路径不应每帧刷屏；最终版本建议只保留断言失败信息。

删除后已执行：

```bash
cd '/e/Study/github program/Imouto Life' && source tools/env.sh >/dev/null 2>&1
cargo fmt --all
```

---

## 5. 验证结果（2026-11-11，全部完成）

### 5.1 默认 workspace

```bash
cd '/e/Study/github program/Imouto Life' && source tools/env.sh >/dev/null 2>&1
cargo test -q --workspace
```

要求：**exit 0**，数据依赖用例打印 skipping 后正常返回。

**结果：exit 0。**

### 5.2 本作数据 workspace

```bash
WOLF_DATA_ROOT="$PWD/work/Data" cargo test -q --workspace --no-fail-fast
```

要求：只允许出现 `docs/HANDOFF_PROGRESS.md` 已记录的 **7 个姊妹作期望值/事件语义差异** 失败；不得新增失败。
注意 `WOLF_DATA_ROOT` 必须是绝对路径。

**结果：仅 7 个既有姊妹作差异（auto_events 3、db 2、game title 2），无新增失败。**

### 5.3 verify

```bash
WOLF_DATA_ROOT="$PWD/work/Data" ./target/debug/wolf-cli.exe verify
```

要求：**PASS 64 / 1 SKIP**（M0 基线）。

**结果：PASS 64 / 1 SKIP。**

### 5.4 视觉回归

```bash
cargo test -q -p wolf-cli --test m14_visual_regression
```

当前基线与代码中的注释：

- title peak = 8
- day_command peak = 8
- hud peak = 7
- map_idle = 5
- saveui = 8

title 的首帧启动突发为 `48/270/271/216/63/2/264/265`，之后收敛到 3，峰值 8 不是协程泄漏。
**结果：5 passed。** 如果后续画面变化，先判断是否更接近实机；不要为了变绿盲目重录，需要重录时同时更新注释说明原因。

### 5.5 Godot 冒烟 / 对齐

```bash
bash tools/smoke-godot.sh
bash tools/parity-godot.sh 600 --pixel-check=0
```

要求：

- smoke 退出 0，P0 基线 `pictures=4 sprites=4`；
- parity 600 帧 PASS。

**结果：** `smoke-godot.sh` 退出 0（smoke `pictures=4 sprites=4`、load_save `50/14`、roundtrip `38/38`）；`parity-godot.sh 600 --pixel-check=0` PASS（instructions 15,549 / pictures 4,418 / messages 15 / choices 3 / warnings 0 / sounds 3）。Godot 曾输出 `ObjectDB instances were leaked at exit`，但脚本成功退出，不影响基线。

若 `crates/wolf-gdext` 有改动，先：

```bash
bash tools/build-godot.sh
```

Godot 窗口运行时不能覆盖 `godot/bin/wolf_gdext.dll`；先关窗口/编辑器。

---

## 6. 文档更新（已完成）

已完成：

1. `docs/HANDOFF_PROGRESS.md` 末尾已追加 BUG-02 进度：
   - 名字牌持续可见的根因与修复；
   - 删除的调试代码；
   - 全部验证结果（默认 / 数据 / verify / visual / smoke / parity）；
   - 清理后 `du -sh .` 数字。
2. `docs/HANDOFF_M0.md` §11.1 当前状态：
   - 已把“气泡屏幕几何仍依赖 character_state”改为实际结论：
     - 固定模式 `2002` 的位置由 `290` shift 到 `(512,536)`，不需要角色坐标；
     - 名字牌问题的实际根因是 op112 保留 bit 24 类型标志，不在坐标系。
   - 保留“不要伪造坐标”的约束。
3. `docs/OPCODE_122.md` 已补 op112 的双布局/比较模式：
   - 模式 1 = 不相等；
   - 字面量布局 vs 双变量布局；
   - `0x0100_0000` 变量类型标志。
4. 本文件已归档，保留为历史交接与排查记录。

---

## 7. 里程碑清理（已完成）

2026-11-11 已按 `AGENTS.md` §7 执行：

```bash
cd '/e/Study/github program/Imouto Life'
rm -rf target/debug/incremental target/release target/ver6 work/out/saveprobe
find work/out -maxdepth 1 -type f \( -name '*.pdb' -o -name '*_probe.exe' -o -name '*probe*.pdb' \) -delete
du -sh . work work/Data target
```

- 永远不要删除 `work/Data`、`work/out/dist`、`docs/`、`crates/`、`prt sc/`。
- 删除本轮临时日志：`work/out/ce*.dump`、`work/out/m15_trace*.log`、`work/out/balloon_after_screenvars.log` 等。
- 如果彻底清理删除了 `target`，下次验证前重新 `cargo build -q --workspace`。
- 把 `du -sh .` 写进进度日志和 `HANDOFF_M0.md` §11.1。

**结果：** 已删除 `target/debug/incremental`、`target/release`、`target/ver6`、`work/out/saveprobe`、`work/out/title_peak.png`、`work/out/godot_roundtrip.sav`、`work/out/dllprobe` 及本轮 trace；`du -sh .` = **7.5 GB**（work 334 M = Data 176 M + out 159 M；target 7.1 G = debug 6.2 G + godot 894 M）。

---

## 8. 工程约束（必须遵守）

- 每次 bash 开头：

  ```bash
  cd '/e/Study/github program/Imouto Life' && source tools/env.sh >/dev/null 2>&1
  ```

- 数据根是 `work/Data`，不要提交；数据测试必须用绝对路径。
- 临时输出放 `work/out/`，不要用 `/tmp`。
- 不要用 PowerShell 抢前台或模拟按键截图；原版截图只能由用户按 PrintScreen。
- 不新增外部依赖；`wolf-gdext` 的 Godot 0.5.5 + `api-4-7` 是既定选择。
- **不要 commit**，除非用户明确要求。
- 面向用户的说明与代码注释保持中性技术描述。
- 写作用域不重叠；本任务已完成，后续新任务再按 `AGENTS.md` 拆分并行子代理。

---

## 9. 验收结果（全部满足）

- [x] `m15_balloon_name` 断言名字牌在消息显示期间连续 60 帧可见，且屏幕矩形在 1024×576 内。
- [x] 默认 workspace exit 0；数据 workspace 无新增失败；verify PASS 64/1 SKIP。
- [x] visual regression 5 passed；smoke-godot 退出 0；parity 600 帧 PASS。
- [x] 所有临时调试打印已删除，`cargo fmt --all -- --check` 通过。
- [x] `docs/HANDOFF_PROGRESS.md`、`docs/HANDOFF_M0.md` §11.1 与 `docs/OPCODE_122.md` 已更新。
- [x] 已完成清理并记录 `du -sh .` = 7.5 GB。
- [x] 工作区仍未 commit（除非用户另行指示）。

---

## 10. 独立复核后的收尾补丁（2026-11-11）

复核发现两处仍未真正闭环，已在归档后补齐：

1. **BUG-05 的真实鼠标命中**：`Screen::picture_rect` 对 CE131 的 window 图仍使用 18x18 皮肤纹理，可见槽位面板（928x115.2）只有左上角 1.8x1.8 能点中，点中心仍保存到第 1 槽。现在 window 图先取 `Picture::window` 盒，再按 `Atlas::sprites` 的 tenths 规则缩放；过小（Atlas 不绘制）的窗口返回 None。新增 `m3_menu_screens::ce131_slot_hit_boxes_are_the_visible_panels_not_the_skin_texture`。
2. **回归补强**：新增 `m3_hud_buttons::repeated_save_menu_cycles_do_not_lock_the_hud_icons`（BUG-08，连续 3 次开关 CE131 后数据图标仍响应）、`m3_event_page_switch::blocked_event_cleans_up_before_a_page_switch`（BUG-09/16，CE245 打开时改页条件，Event 1 仍执行清理再换页）与 `m3_mouse_menu::a_left_click_outside_the_panel_cancels_the_prompt`（BUG-18）。
3. **precompile 基线**：`dynamic_labels` 由错误的 51 修正为实测 3；`wolf-cli precompile` PASS 19/0。

最终验证：默认 workspace exit 0；数据 workspace 105 target ok + 仅 7 个既有姊妹作差异；verify PASS 64/1 SKIP；precompile PASS 19/0；m14 5/5；fmt/diff-check 通过；smoke-godot exit 0；parity 600 PASS（15,549/4,418/15/3/0/3）。清理后 `du -sh .` = 7.5 GB。
