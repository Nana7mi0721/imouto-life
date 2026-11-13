# 《妹！生活 ～単色～》Rust + Godot 重写项目静态代码审查报告（第一、二轮汇总）

- **审查范围**：`cb5ecb4..ee808fe` 核心补丁（57 files，+12234 / -625）及当前 HEAD 快照 `141c524`（已排除第三方插件 `godot/addons/godot_ai`）
- **审查方式**：纯静态代码与字节码对照审查（未构建、未运行游戏、未修改源码）
- **已知边界**：不含 `work/Data`、Godot 编辑器与离线 crates；`BUG-20..24` 编号均明确区分「历史台账」与「四轮审查 §6」；已知既有噪声（`m3_manual_rules::late_night_bedtime_skips_to_next_evening` 及 2 个姊妹作 `db` 占位串测试）不归因于本轮补丁。

---

## 1. 总评：**Approve with changes**

本轮补丁围绕四轮审查 §6（`BUG-25..48`）、Godot 前端 UI 命中与混合批层渲染、以及 T13/T14 性能与图集包络线优化进行了大规模重构与修复。整体工程质量较高：T13 移除玩法前端瓦片绘制、图集内容包围盒裁剪、文本框与姓名牌协同布局、以及 `2_000_000+` 正常变量与 `common_self` 的基础映射均已落地且有对应单元测试支撑。

但在两轮静态深挖与原版字节码（`_ce_full.json` / `SampleMapA.mps`）交叉核对后，确认存在 **3 项 P1 级逻辑/几何回归**、**4 项 P2 级状态同步与渲染/缓存缺陷**、**2 项 P3 级调度边界问题**，以及若干高风险测试盲区和文档冲突。建议优先修复 P1 缺陷并补齐对应回归测试后再合入主线。

---

## 2. 缺陷列表（按 P0 / P1 / P2 / P3 排序）

*(注：本轮未发现导致立即崩溃或存档不可逆损毁的 P0 阻塞缺陷，最高优先级从 P1 开始。)*

### P1 级缺陷

#### [P1-1] `Opcode 121` 的 `self_range` 短路规则将所有 `SelfVar` 批量操作强制退化为单槽更新，破坏通用 `SelfVar` 批量赋值并导致 `CE 95` 内部几何单位撕裂（第一轮）

- **文件与行号**：
  - `crates/wolf-vm/src/exec.rs:2510, 2565-2569`
  - 耦合路径：`crates/wolf-game/src/picture.rs:1156-1170, 1521-1523, 1541-1544`、`crates/wolf-game/src/atlas.rs:626`、`crates/wolf-game/src/game.rs:2016-2017, 4633-4657`
- **触发的具体代码路径**：
  1. `exec.rs:2510, 2565` 将所有左值为 `MagicKind::SelfVar` 且带 `bit 16`（`0x1_0000` 批量模式）的 `Opcode 121` 标记为 `self_range = true`，并将 `batch_count` 强制置为 `0`：
     ```rust
     let self_range = batch_mode && Magic::decode(raw_lhs).kind() == MagicKind::SelfVar;
     let batch_count = if batch_mode && !self_range { arg(cmd, 4).max(0) as i32 } else { 0 };
     ```
  2. **路径 A（通用 `SelfVar` 批量赋值被截断）**：
     - 在 `CE 64`（`X[共]万能ｳｨﾝﾄﾞｳ描画処理`，被 `CE 65`、`CE 128` 道具栏、`CE 129` 技能栏等调用）`pc=671`：`121 [1600053, 100, 0, 0x10000, 2]` 原意是在绘制每一行前将 RGB 色调 `self53..=55` 重置为 `(100, 100, 100)`，随后对禁用行在 `pc=673..677` 改为 `(50, 50, 70)`。因 `batch_count` 被置 `0`，`self54(G)` 与 `self55(B)` 完全未被写入。
     - 同理，`CE 36 pc=46-47`（`1600060..=64` X 坐标表批量缩放）、`CE 36 pc=66-67`（`1600084..=85` 透明度批量钳制）、`CE 93 pc=51`、`CE 114 pc=120`、`CE 123 pc=158` 的后续槽位全部漏更新。
  3. **路径 B（`CE 95` 系统设置界面单位撕裂与 `CE 223` 命中错位）**：
     - `CE 95`（`X[移]システム画面描画`，由 `CE 132` 调用）在 `pc=100` 执行 `121 [1600060, 10, 0, 0x10400, 17]`（将 `self60..=77` 除以 10）。因 `self_range` 只除 `self60`，导致 `self60 = 320`（像素），而 `self62..=76` 仍保持十分之一像素（如 `self66 = 2976`、`self74 = 1600`）。
     - 随后 `CE 95 pc=269` 对文本图片 `12050` 执行 `Opcode 290` 位移 `dx = self60 (320)`，而 `game.rs:2016`（`x + dx / 10.0`）对 `12050..12059` 无条件再除以 10，导致 `12050` 的实际 X 位移只有 `32 px`（而非 `320 px`）。
     - `CE 95 pc=587, 638` 生成 `12015..12022`（`WindowString` 光标框）时传入 `width = self74 = 1600`（十分之一像素）与 `height = self37 = 20`（像素）。`atlas.rs:626` 因 `w > 640` 触发 `ui = 10.0` 缩放，将 `y`、`w`、`h` 全部除以 10，导致光标高度被压扁为 `20 / 10 = 2 px`。
     - 当 `CE 223 pc=585-586, 607-608` 通过 `Opcode 124` 查询图片 `12053 / 12054` 的 X 坐标与宽度以判定音量条点击时，`Game::picture_state`（`game.rs:4631`）只返回未叠加 `Picture.shift`（`Opcode 290` 位移）的原始 `picture.x`，导致 `CE 223` 拿到的命中框与实际渲染位置脱节。
- **玩家可见或系统级影响**：
  - `CE 64` 通用窗口渲染的列表项在未触发禁用行前 `G/B` 分量为 `0`（呈纯红色 `(100, 0, 0)`），一旦遇到禁用行后，后续所有正常行都会残留禁用行的暗紫蓝色调 `(100, 50, 70)`。
  - `CE 95 / CE 132` 系统设置界面标题/第一项文本 `12050` 水平错位、选框光标高度压扁为 `2 px`，且 `CE 223` 音量条点击坐标失准。
- **最小修复建议**：
  - **方案 A（推荐）**：移除 `exec.rs:2510, 2565` 中一刀切的 `self_range` 短路，按原版 `FUN_00453720` 对所有 `0..=batch_count` 槽位完整执行批量运算，并同步移除 `picture.rs` / `atlas.rs` / `game.rs` 中针对未除 10 槽位打的 `/ 10.0` 补偿补丁（`tenths_block`）。
  - **方案 B（最小改动）**：若需保留 `CE 94` 的十分之一坐标路径，必须将 `self_range` 严格限定为 `assign_op == 0x0400 && v1 == 10`（仅限 `/= 10` 的坐标换算指令），并在 `CE 95` 中统一 `self60` 与 `self62..=77` 的缩放语义，同时在 `game.rs:4631` 的 `picture_state` 中对 `12050..=12059` 计入 `Picture.shift`。
- **证据等级**：`Confirmed`

---

#### [P1-2] 新游戏流程（`v[1] == 1`）中 `AutoEvents` 常驻启动 `CE 223`，导致 `Game::apply_wheel()` 无条件提前返回，所有选项与存读档界面的鼠标滚轮失效（第一轮）

- **文件与行号**：
  - `crates/wolf-game/src/game.rs:2853-2860`（`Game::apply_wheel`）
  - `crates/wolf-game/src/auto_events.rs:248-280`
- **触发的具体代码路径**：
  1. 本轮修复了四轮审查 §6 `BUG-25`（`2_000_000..=2_099_999` 正确映射至 `NormalVar` `v[id]`）。
  2. 新游戏从 `SampleMapA.mps` Event 0 Page 0 启动时，`pc=25` 执行 `121 [2000001, 1, 0, 0]` 将 `v[1]` 置为 `1`，并在整个新游戏会话期间保持 `v[1] == 1`。
  3. `CE 223`（`ウィンドウ処理`）的触发头条件正是 `v[1] == 1`，因此 `AutoEvents::sync` 在新游戏的每一帧都会拉起 `CE 223`，使 `self.vm.instances()` 中始终存在 `instance.event == 223`。
  4. `Game::apply_wheel()`（`game.rs:2853-2860`）检查到 `instance.event == 223` 即直接放弃宿主滚轮处理：
     ```rust
     if self.vm.instances().iter().any(|instance| instance.event == 223) {
         return 0;
     }
     ```
  5. 然而在 `CE 223` 字节码中，`pc=27-29` 首先查询 `Picture(100000)` 的存在状态（`cself[39] = 100000; Op124 cself[40] = Picture(100000).field(9); if cself[40] == 1`）。本作在常规对话选项（`Opcode 102`）与存读档网格（`CE 131`）中并不会绘制编号 `100000` 的图片，导致 `cself[40]` 恒为 `0`，`CE 223` 在 `pc=29` 直接跳过整段窗口逻辑并退出。
- **玩家可见或系统级影响**：
  - 在任何新游戏流程中，只要经过了 `SampleMapA Ev 0 pc=25`，`CE 223` 每帧空转退出，而 `Game::apply_wheel()` 因看到 `event == 223` 在运行而直接 `return 0`，导致**所有分支选项菜单（`Opcode 102`）和存读档界面（`CE 131`）的鼠标滚轮翻页/滚动完全失效**。
  - 现有测试 `m6_title_wheel.rs` 之所以全绿，是因为标题画面时 `v[1] == 0`，且 `open_grid()` 读取的 `SaveData01.sav` 恰好 `v[1] == 0`，绕过了新游戏的 `v[1] == 1` 路径。
- **最小修复建议**：
  - 在 `crates/wolf-game/src/game.rs:2856` 中，不要仅凭 `instance.event == 223` 就拦截滚轮；应改为仅当 `CE 223` 的窗口光标图片确实处于激活状态（例如 `self.screen.get(100_000).is_some()` 或 `self.vm.vars.common_self.get(&223).is_some_and(|b| b.get(40) == 1)`）时，才将滚轮交由 `CE 223` 接管。
- **证据等级**：`Confirmed`

---

#### [P1-3] `Game::picture_quads()` 在渲染读取路径中调用 `expand_balloon_frame()` 原地修改 `Picture 36000` 状态，破坏渲染幂等性与无头/存档状态一致性（第一轮）

- **文件与行号**：
  - `crates/wolf-game/src/game.rs:1486-1498, 1921-1946`
- **触发的具体代码路径**：
  1. `Game::picture_quads(&mut self)` 在每次生成渲染图元时调用 `self.expand_balloon_frame()`（`game.rs:1486`）。
  2. `expand_balloon_frame()`（`game.rs:1940-1945`）直接对 `self.screen` 中的 `Picture 36000` 执行原地写操作：
     ```rust
     let Some((width, current_height)) = frame.window else { return; };
     let bottom = frame.y + current_height / 2;
     frame.window = Some((width, height));
     frame.y = bottom - height / 2;
     ```
  3. 此处存在两重缺陷：
     - **渲染函数污染逻辑/存档状态**：`Game::frame()` 本身不调用 `picture_quads()`。因此无头步进（headless test）与带渲染步进（Godot 前端）在 `Picture 36000` 的 `y` 与 `window` 字段上状态不一致；若在调用 `picture_quads()` 后执行存档或 `Opcode 124`（`picture_state`），被改写后的 `frame.y = -10` 与 `window = (580, 80)` 会被持久化进存档或暴露给脚本。
     - **奇数高度下的非幂等截断**：整数除法 `current_height / 2` 仅在 `current_height` 和 `height` 均为偶数时恰好幂等。注释 `game.rs:1919` 提到目标高度可能为 `79-80 px`；若目标高度为奇数或存在初始奇数 `frame.y`，且某帧 `CE 270` 未重绘 `36000`（如暂停、冻结或连续多次调用 `picture_quads()`），整数截断会产生累积偏移。
- **玩家可见或系统级影响**：
  - 无头测试与实际渲染运行时的 `Picture 36000` 几何状态分裂；在气泡框显示期间保存游戏会把渲染层的临时扩高尺寸写入存档快照。
- **最小修复建议**：
  - 不要在 `picture_quads()` 中原地修改 `self.screen` 的 `Picture 36000`；应像 `game.rs:1490-1497` 处理 `36008..=36012`（姓名牌上移）那样，仅在生成 `SpriteQuad` 时计算并应用气泡框的扩展高度与底边锚定偏移。
- **证据等级**：`Confirmed`

---

### P2 级缺陷

#### [P2-1] `PictureAction::Move` 在取消 `Erase` 渐隐（`erase_after_slide`）时，若 `duration == 0` 未清空残留的 `transition`，导致图片在原渐隐周期结束时透明度被静默归零（第一轮）

- **文件与行号**：
  - `crates/wolf-game/src/picture.rs:1326, 1954-1968, 2650-2677`
- **触发的具体代码路径**：
  1. 对图片槽执行带 `fade > 0` 的 `PictureAction::Erase` 时，`start_erase_fade` 设置 `picture.erase_after_slide = true` 且 `picture.transition = Some(Transition { to: Pose { opacity: 0, .. }, duration: fade, age: 0 })`。
  2. 若在渐隐结束前，脚本对该槽位发起瞬时 `PictureAction::Move`（`duration == 0`）：
     - `picture.rs:1326` 将 `picture.erase_after_slide` 设为 `false`；
     - 但 `merge_args`（`picture.rs:1956-1968`）在 `duration == 0` 分支只直接更新了 `self.x / self.y / self.opacity`，**没有执行 `self.transition = None`**。
  3. 后续每帧 `picture.advance()` 继续推进残留的 `Erase` `Transition`，并在 `age == duration` 时将 `self.opacity` 覆写为 `to.opacity`（`0`）。
  4. 本轮新增测试 `move_cancels_an_erase_fade`（`picture.rs:2650-2677`）传入 `args: vec![0, 50, 60]`（`duration == 0`），10 帧后仅断言 `assert!(screen.get(20).is_some())`，未检查 `opacity` 已被归零。
- **玩家可见或系统级影响**：
  - 正在淡出销毁的图片若被瞬时 `Move` 指令复用，图片虽保留在槽位字典中，但会在原淡出倒计时结束的那一帧突然变成完全透明（`opacity = 0`）。
- **最小修复建议**：
  - 在 `crates/wolf-game/src/picture.rs:1326` 取消 `picture.erase_after_slide = false` 时（或在 `merge_args` 的 `duration == 0` 分支中），同步执行 `picture.transition = None;`。
- **证据等级**：`Confirmed`

---

#### [P2-2] `sync_save_grid_cursor()` 直接修改 `instance.self_vars` 而未调用 `Vm::set_instance_self_var`，导致跨事件可见的 `Variables.common_self[&131]` 失步（第一轮）

- **文件与行号**：
  - `crates/wolf-game/src/game.rs:2952-2956`
- **触发的具体代码路径**：
  - 本轮在 `exec.rs:1343` 新增了 `Vm::set_instance_self_var(id, idx, value)` 以确保宿主修改实例 `self_vars` 时同步写穿至 `vm.vars.common_self`（且 `docs/HANDOFF_DEEP_REVIEW_FIX.md:111` 记录了需要将 `sync_save_grid_cursor` 改为调用该接口），但 `game.rs:2952-2956` 仍直接写入 `instance.self_vars.set(610, slot);`。
- **玩家可见或系统级影响**：
  - 在存读档界面（`CE 131`）切换光标槽位时，`vm.vars.common_self[&131]`（对应 `15_013_110`）仍保留旧值，并行事件或跨事件读取 `15_013_110` 会拿到过期槽位号。
- **最小修复建议**：
  - 将 `crates/wolf-game/src/game.rs:2953-2955` 替换为 `self.vm.set_instance_self_var(id, 610, slot);`。
- **证据等级**：`Confirmed`

---

#### [P2-3] `GameView.gd` 从混合批次路径切回快路径时未释放 `_batch_pool` 节点的字典与纹理引用，且静态帧仍存在每帧 FFI 字典构造与全量排序开销（第一轮）

- **文件与行号**：
  - `godot/scripts/GameView.gd:510-524, 598-606`
  - `crates/wolf-gdext/src/lib.rs:265-366`
- **触发的具体代码路径**：
  1. 在 `GameView.gd:521-524`，当画面从含特殊混合模式（`has_blends == true`）切回纯 Normal 混合快路径（`not has_blends`）时，循环只设置了 `batch.visible = false`，未像 `600-605` 行那样清空 `batch.items`、`batch.overlays`、`batch.energy` 与 `batch.frozen_texture`。
  2. 即便 `outcome.idle == true` 且画面静止，`wolf-gdext/src/lib.rs:265-366` 每帧仍重新分配所有 `sprites` 与 `texts` 的 `VarDictionary`，`GameView.gd:510-519` 每帧仍构造包装 Dictionary 并执行 `items.sort_custom(_draw_item_before)`。
- **玩家可见或系统级影响**：
  - 离开混合模式场景（如过场或夜间特效）后，隐藏的 `_batch_pool` 节点会持续持有上一帧的 `frozen_texture` 与字典数组引用；静态等待帧仍有每帧 GDScript/FFI 分配。
- **最小修复建议**：
  - 在 `GameView.gd:522-524` 隐藏 `batch` 时同步清空 `batch.items.clear()`、`batch.overlays.clear()`、`batch.energy = {}`、`batch.frozen_texture = null`。
- **证据等级**：`Confirmed`

---

#### [P2-4] `GameView.gd` `_update_frozen_frame()` 的 `frozen_texture == null` 守卫阻止连续 `161` 刷新截屏，且 `_capture_frozen_frame()` 未复用现有 `ImageTexture`（第二轮新增）

- **文件与行号**：
  - `godot/scripts/GameView.gd:853-870`
- **触发的具体代码路径**：
  1. `wolf-gdext/src/lib.rs:271` 调用 `game.take_freeze_request()` 在 `Opcode 161` 执行的当帧消费并重置标志位，因此 `packet.get("freeze", false)` 仅在 `161` 触发的当帧为 `true`。
  2. 然而 `GameView.gd:854` 写了：
     ```gdscript
     if packet.get("freeze", false) and frozen_texture == null:
         _capture_frozen_frame()
     ```
     若脚本连续执行 `161 -> 162 -> 161 -> 162`（第二次 `161` 发生在第一次 `162` 结束的同一帧、尚未经过非过渡帧调用 `_clear_frozen_frame()` 之前），或连续两次执行 `161` 刷新冻结画面，此时 `frozen_texture` 仍非空，导致第二次 `_capture_frozen_frame()` 被跳过。
  3. 同时，`GameView.gd:867` 每次都调用 `ImageTexture.create_from_image(previous)` 重新创建纹理对象，而非在尺寸一致时复用 `frozen_texture.update(previous)`（与本轮“161 冻结帧复用 `ImageTexture`”的目标未完全对齐）。
- **玩家可见或系统级影响**：
  - 连续过场转场时，第二次 `162` 淡出可能错误地显示第一次 `161` 残留的旧画面；每次冻结都会重新分配 GPU 纹理对象。
- **最小修复建议**：
  - 将 `GameView.gd:854` 改为 `if packet.get("freeze", false):`（去掉 `and frozen_texture == null`）；并在 `_capture_frozen_frame()` 中当 `frozen_texture != null` 且 `frozen_texture.get_size() == Vector2(previous.get_size())` 时调用 `frozen_texture.update(previous)` 复用纹理。
- **证据等级**：`Confirmed`

---

### P3 级缺陷

#### [P3-1] `Opcode 125`（`auto_keys`）按实例 ID 单次消费，若同一协程在单帧内连续执行两次 `Opcode 123` 查询不同按键，第二次查询会丢失注入按键（第一轮）

- **文件与行号**：
  - `crates/wolf-vm/src/exec.rs:1388-1398, 2777-2786, 2887-2890`
- **触发的具体代码路径**：
  - `Opcode 125` 设置 `input.auto_keys = bits; input.auto_keys_ttl = 2; input.auto_keys_delivered.clear();`。但协程第一次执行 `Opcode 123`（无论该 `123` 查询的按键掩码是否包含 `auto_keys`）即将 `inst.id` 加入 `auto_keys_delivered`，导致同一协程同帧内的后续 `123` 查询读到 `effective_auto = 0`。
- **玩家可见或系统级影响**：
  - 若脚本在单帧内分两条 `123` 指令轮询不同按键组，第一条未命中 `auto_keys` 的 `123` 会提前消耗掉注入按键，使第二条 `123` 漏检。
- **最小修复建议**：
  - 仅在 `Opcode 123` 查询的按键掩码与 `auto_keys` 存在交集时标记消费，或将 `auto_keys` 生命周期严格绑定到单帧所有协程步进结束之后。
- **证据等级**：`Plausible`

---

#### [P3-2] `Vm::spawn_child()` 未向 `210 / 300` 子协程继承父协程的 `is_parallel` 标志，导致并行背景协程调用子事件时污染 `Sys110`（当前前台事件）（第二轮新增）

- **文件与行号**：
  - `crates/wolf-vm/src/exec.rs:1477-1492, 1606-1612`
- **触发的具体代码路径**：
  1. `run_instances`（`exec.rs:1477-1492`）通过逆序查找首个 `!other.is_parallel` 的活动协程来计算 `foreground_event`（供 `SysVar 110` 读取）。
  2. 当一个 `is_parallel == true` 的并行事件（如 `AutoEvents` 调度的 `CE 223/224` 或 `Trigger::Parallel` 地图事件）通过 `Opcode 210 / 300` 调用公共事件时，`spawn_child`（`exec.rs:1606`）新建 `child` 实例时未继承 `self.instances[caller].is_parallel`，默认将 `child.is_parallel` 设为 `false`。
- **玩家可见或系统级影响**：
  - 并行后台事件调用公共子程序期间，`Sys110` 会短暂将后台子协程误判为当前前台事件，可能干扰依赖 `Sys110` 判断前台是否空闲的逻辑。
- **最小修复建议**：
  - 在 `exec.rs:1606` `spawn_child` 中添加 `child.is_parallel = self.instances[caller].is_parallel;`。
- **证据等级**：`Plausible`

---

## 3. 测试缺口

1. **新游戏 `v[1] == 1` 状态下的鼠标滚轮端到端回归缺失**：
   - `m6_title_wheel.rs` 仅覆盖了标题画面（`v[1] == 0`）与 `SaveData01.sav`（恰好 `v[1] == 0`），完全未覆盖新游戏进入主循环后 `v[1] == 1`、`AutoEvents` 常驻拉起 `CE 223` 时的选项/存档滚轮行为（漏掉了 **[P1-2]**）。
2. **`CE 95 / CE 132`（系统设置界面）与 `CE 64`（万能窗口）在 `self_range` 规则下的几何与色调验证缺失**：
   - 现有 UI/视觉测试仅覆盖了 `CE 94 / CE 131`（存读档），未覆盖同样依赖 `SelfVar` 批量 `Opcode 121` 的 `CE 95`（`pc=100`）与 `CE 64`（`pc=671`），漏掉了 **[P1-1]**。
3. **`move_cancels_an_erase_fade` 测试断言过宽**：
   - `crates/wolf-game/src/picture.rs:2650-2677` 仅断言 `screen.get(20).is_some()`，未断言 10 帧后 `opacity` 仍为非零值，掩盖了 **[P2-1]**。
4. **部分既有 HUD 集成测试显式关闭了 `auto_events`**：
   - 本轮在 `m2_hud_events.rs:127`、`m3_stats_collection.rs:67`、`m3_ui_screens.rs:128`、`m3_visual_text.rs:75` 中加入了 `game.auto_events.set_enabled(false);`。虽利于单事件隔离，但也使这些套件失去了对 `AutoEvents` 与主界面 HUD 并发交互的回归保护。
5. **连续 `161 -> 162 -> 161 -> 162` 冻结帧与 `GameView.gd` 混合批层切回快路径的状态清理测试缺失**：
   - Godot 端 `smoke.gd` 未覆盖连续 `161` 转场截图刷新与混合模式退回快路径后的纹理释放（**[P2-3]**、**[P2-4]**）。

---

## 4. 文档与实现冲突

1. **`docs/README.md:145` 仍将 T12 已废弃的“地图瓦片 RGBA 纹理”写为当前 `wolf-gdext` 实现**：
   - `docs/README.md:145` 仍写着 `WolfGame GDExtension 类：每帧返回动态 sprites/texts/overlays/sounds，以及缓存的地图瓦片 RGBA 纹理`，与 T13 移除瓦片桥接及 `docs/GODOT_MIGRATION.md:237-241`、`docs/HANDOFF_M0.md:277-281` 的明确要求冲突。
2. **`docs/HANDOFF_DEEP_REVIEW_FIX.md` 两处描述与当前代码不一致**：
   - `docs/HANDOFF_DEEP_REVIEW_FIX.md:111`（§4.1 第 5 条）声称 `sync_save_grid_cursor` 已改用 `Vm::set_instance_self_var(id, 610, slot)`，但 `crates/wolf-game/src/game.rs:2953-2955` 仍直接修改 `instance.self_vars`（见 **[P2-2]**）。
   - `docs/HANDOFF_DEEP_REVIEW_FIX.md:26`（§0）仍将“Godot 瓦片层”列为最终回归覆盖项。
3. **多处交接文档对侧栏命中热区的描述停留在 T13 中间态（`try_status_panel_strip`），与 T14 最终代码（`try_side_panel_handle`）冲突**：
   - `docs/HANDOFF_M0.md:289-290`、`docs/HANDOFF_PROGRESS.md:978`、`docs/TASKS_REMAINING_BUGS.md:91-93` 均仍写着“侧栏现在整条 25px 可见滑条（物品栏 y 288..384 除外）可点击打开” / `try_status_panel_strip`。而 HEAD 代码（`crates/wolf-game/src/game.rs:164-169, 2475-2542`）已将其替换为 `try_side_panel_handle`，仅响应两个三角把手区 `STATUS_HANDLE_Y = (118.0, 157.0)` 与 `ITEM_HANDLE_Y = (260.0, 297.0)`（且 `m3_hud_buttons.rs:468` 明确断言点击 `(15, 192)` 空白滑条**不会**打开侧栏）。
4. **`docs/TASKS_REMAINING_BUGS.md` 内部关于默认测试状态的表述自相矛盾**：
   - 第 16 行（§0）写“当前仓库默认 `cargo test -q --workspace` 为 `exit 0`”，而第 146 行（§0.1）写“全量默认测试仍有既有 `m3_manual_rules::late_night_bedtime_skips_to_next_evening`（17:00 vs 19:00）失败”。

---

## 5. 建议新增的最高价值回归测试

1. **`new_game_v1_active_does_not_swallow_mouse_wheel_in_choices_and_save_grid`**（覆盖 **[P1-2]**）：
   - 从新游戏启动并推进至 `SampleMapA Ev 0` 将 `v[1]` 置为 `1`（确认 `AutoEvents` 已拉起 `CE 223`），随后触发 `Opcode 102` 多分支选项及打开 `CE 131` 存档界面，分别注入 `wheel_delta = 1` 与 `-1`，断言选项焦点索引和存档页码正常滚动。
2. **`ce64_universal_window_batch_selfvar_rgb_reset_and_disabled_row_tint`**（覆盖 **[P1-1]** 路径 A）：
   - 构造或运行 `CE 64` 列表渲染流程（含可用行 -> 禁用行 -> 可用行），断言可用行的 `self53..=55` 均完整重置为 `(100, 100, 100)`，不会出现首行纯红或后续行继承禁用行 `(100, 50, 70)` 色调污染。
3. **`ce95_system_settings_cursor_and_label_geometry_and_ce223_volume_hit`**（覆盖 **[P1-1]** 路径 B）：
   - 启动 `CE 132 / CE 95` 系统设置画面，断言：① 文本图片 `12050` 的屏幕 X 坐标与 `12051..12054` 对齐；② 光标框 `12015..12022` 渲染高度为 `20 px`（未被压扁为 `2 px`）；③ `picture_state(12053, 0)` 返回包含 `Opcode 290` 位移后的真实屏幕 X 坐标。
4. **`instant_move_cancels_erase_fade_and_preserves_nonzero_opacity`**（覆盖 **[P2-1]**）：
   - 补强 `crates/wolf-game/src/picture.rs` 中的 `move_cancels_an_erase_fade`：在 `Erase (fade=5)` 后执行瞬时 `Move (duration=0)`，推进 10 帧后同时断言 `screen.get(20).is_some()` 且 `screen.get(20).unwrap().opacity == 255`。
5. **`picture_quads_is_idempotent_and_does_not_mutate_screen_balloon_state`**（覆盖 **[P1-3]**）：
   - 在 `Picture 36000` 与多行 `36013` 文本同屏时连续调用两次 `game.picture_quads()`，断言两次输出的 `36000` / `36008..=36012` 坐标完全一致，且 `game.screen.get(36000)` 的逻辑 `y` 与 `window` 字段未被修改。
