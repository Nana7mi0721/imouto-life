# 《妹！生活 ～単色～》重构问题截图纠因与全量代码审查报告

> 日期：2026-11-13  
> 审查范围：`重构游戏问题截图.zip` 全量问题 + 跨 crate（`wolf-vm` / `wolf-game` / `wolf-gdext` / `scripts/*.gd`）全量只读代码审查  
> 约束：只读源码核验，所有行号与符号均对照当前工作区文件。

---

## 一、`重构游戏问题截图.zip` 问题排查、纠因与修改措施

### 1. 选项位置错乱（跑到左上角 `(0, 0)` 遮挡顶栏）
- **对应截图**：`读取存单时进行游戏，选项位置错乱.png`、`选项框同样的错位与选项文字出现乱码.png`
- **根因**：`Game::choice_anchor()`（`crates/wolf-game/src/game.rs:1843-1845`）直接返回 `(Sys3, Sys4)`。当读档或特定脚本路径下 `Sys3 == 0 && Sys4 == 0` 时，`choice::layout_at_sized()`（`crates/wolf-game/src/choice.rs:237-255`）判定 `(0, 0)` 落在屏幕内，于是把选项框画在左上角遮挡顶栏。
- **修改措施**：在 `crates/wolf-game/src/choice.rs:237-255` 中，将 `(x == 0 && y == 0)` 与屏外/负坐标一样视作“使用默认居中位置”，回退到屏幕居中布局。

### 2. 选项文字出现 `♦ 2000` 乱码菱形问号
- **对应截图**：`选项框同样的错位与选项文字出现乱码.png`（`红茶 ♦ 2000`）
- **根因**：`Game::show_choices()`（`game.rs:4312-4322`）仅做了文本翻译，未对选项字符串剥离 WOLF 控制码/图标标记；同时 `choice::draw()`（`choice.rs:365`）直接渲染原始文本，若含特殊符号或解码替换符 `U+FFFD`，在 `msyhbd.ttc` 与 `SYMBOL_FONT_NAMES` 缺失对应字形时即显示为菱形问号。
- **修改措施**：在 `show_choices()` 或 `choice::draw()` 对选项显示文本执行 `wolf_format::messagetext::strip` 清理控制码，并核查商店选项价格前的原始字符编码（必要时在 `GameView.gd` `SYMBOL_FONT_NAMES` 补充字体或做字符替换）。

### 3. 强制射精后选项框残留且无法消除（高危逻辑漏洞）
- **对应截图**：`射精感到上限后强制射精，射精位置选项依然存在，且无法使其消失.png`
- **根因**：`self.choices` 仅在 `choice_made()`（`game.rs:4339-4361`）收到回复时清空。当并行协程因“射精感上限”强制打断或终止正在 `WaitState::Choice` 等待选项的协程时，没有逻辑同步清空 `self.choices`；残留的 `self.choices.is_some()` 还会继续拦截鼠标点击（`game.rs:2641, 4227`），导致选项无法关闭且输入卡死。
- **修改措施**：在 `Game::frame()` 每帧推进 VM 之后，检查 `self.vm.instances()` 是否仍存在 `WaitState::Choice` 或 `WaitState::MessageWithChoices` 实例；若已无等待选项的协程，立即强制清空 `self.choices = None`（并在 `install_map()` 中同步清空）。

### 4. 黑屏开场误显示行动力条 & 进度条样式偏差
- **对应截图**：`新游戏与妈妈交代阶段显示行动力条.png`、`额外要求增加的行动力条不理想，需参考参照图.png`、`参照图仅参考行动力条.png`
- **根因**：
  1. `hud_action_points()`（`game.rs:1894-1902`）未校验 `HUD_ACTION_PICTURE`（槽位 `230`）是否真的包含 `"行动力 current/max"` 可见文本，导致黑屏开场 `"一个月前——"` 无顶栏时孤立绘制了进度条。
  2. 当前 `HUD_ACTION_BAR` 仅 `54×8` 且 `GameView.gd:683-694` 使用内缩 `2 px` 纯白填充，与 `参照图仅参考行动力条.png` 中**更宽、细白边框、深灰/亮灰质感填充**的样式不符。
- **修改措施**：
  1. 在 `hud_action_points()` 增加 `hud.kind.is_text() && split_action_readout(&hud.text).is_some()` 校验。
  2. 参照 `参照图仅参考行动力条.png` 适当加宽/加高 `HUD_ACTION_BAR`（同步微调右侧数值 x 坐标），并在 `GameView.gd:677-695` 改为 `1 px` 内缩与柔和灰白填充。

### 5. 对话框内妹妹小头像 `36002` 底部裁切
- **对应截图**：`对话框内妹妹头像的大小与位置错误（推测为对话框可变高度导致）.png`
- **根因与措施**：当前 `36002` 底边为 `604 > SCREEN_H(576)`，底部 `28 px` 被裁切，且 `m17_ui_regressions.rs:162-165` 将 `+ 38.0` 写成正向断言。对照原版 `T17_original_dialogue_crop.png` 应完整落入屏幕内：在 `Game::picture_quads()`（`game.rs:1621-1631` 附近）对 `36_002` 做底边钳位（`y <= SCREEN_H - h`），并更新该测试断言。

### 6. 连续同人对话人名框消失 & 首框字面量 `"message"`
- **对应截图**：`当前后连续两个对话都来自同一人时，后面对话的人民框消失.png`、`第一个对话框_有人名框.png`
- **根因**：
  1. `picture_quads()`（`game.rs:1641-1648`）在 `!balloon_nameplate_active()` 时整组剔除 `36008..=36012`。若连续同人对话翻页瞬间 `36014` 暂为透明/空串，会导致人名框突然消失（需结合原版确认该句是否本就无人名牌）。
  2. 首框 `"message"` 系原版脚本写入 `36014` 的占位字面量（`TASKS_REMAINING_BUGS.md:103-105`）。
- **修改措施**：若需隐藏占位字面量 `"message"`，可在 `balloon_nameplate_active()`（`game.rs:2088-2098`）增加 `&& stripped != "message"`。

### 7. 其他截图与 `其他问题.txt` 对照
- `文字与消息框略微有错位.png`：气球正文已在 T13 修复；若夜间中央横幅仍有 1–2 px 偏移，可微调 `message.rs` 垂直内边距。
- `其他问题.txt` #1（随机事件连续两天相同）：见下方全量审查 **§二.1（`WolfRng` 游标未持久化）**。
- `其他问题.txt` #2（恶作剧部位点击与底部按钮）：存档/结束按钮已在 T14 修复；若仍全局不可点，优先排查 **§一.3 残留 `self.choices`** 拦截输入。

---

## 二、全量代码审查：新发现漏洞与可优化项目

### 1. 新发现漏洞与边界风险

| 优先级 | 模块与位置 | 问题描述 | 修改建议 |
| :--- | :--- | :--- | :--- |
| **P1** | `crates/wolf-vm/src/rng.rs:66-70`<br>`crates/wolf-game/src/savegame.rs` | **读档后 `WolfRng::cursor` 始终重置为 0**：`WolfRng` 从 `Game.dat` 静态随机表按 `cursor` 顺序取数，但存档加载时未恢复/推进 `cursor`，导致每次读档重玩都会命中完全相同的随机数序列（直接诱发随机事件结果雷同）。 | 在不破坏 `.sav` 兼容性的前提下，可根据存档 `playtime_frames` 派生初始游标偏移，或在存档扩展元数据中保存 `rng.cursor`。 |
| **P1** | `crates/wolf-game/src/game.rs:1553-1571` | **`install_map()` 未清理独立 `MAP_SELF_BASE` 协程与 `self.choices`**：仅调用 `self.runtime.stop_all(&mut self.vm)`，绕过 `MapRuntime` 启动的 `MAP_SELF_BASE` 实例会在切图后继续存活（即报告 §六 `BUG-21`）。 | 在 `install_map()` 中按 `instance.program.self_base == MAP_SELF_BASE` 调用 `vm.stop_instance(id)`，并清空 `self.choices = None`，同步取消 `m16_old_bug_review` 对应 `#[ignore]`。 |
| **P2** | `scripts/GameView.gd:113, 849-869` | **`audio_cache` 只增不减**：`_load_audio()` 将所有播放过的 BGM/BGS/SE `AudioStream` 永久存入 `audio_cache`，长会话切换大量场景与语音后内存持续增长。 | 为 `audio_cache` 增加容量上限/简单淘汰（如仅常驻 BGM/常用 UI 音效，或超过阈值清理）。 |
| **P2** | `scripts/GameView.gd:306, 1092-1095` | **每帧跨 FFI 读取 `wolf.key_config()`**：`_physics_process()` 每帧调用 `wolf.key_config()` 分配 `PackedInt32Array` 并转为 GDScript `Array`，但键位仅在 `CE132` 设置时才会改变。 | 在 `WolfGame` 暴露 `key_config_revision` 或仅在 `CE132` 关闭/设置变更时刷新前端缓存的键位映射。 |

### 2. 新发现性能优化项目

| 优先级 | 模块与位置 | 性能瓶颈 | 优化方案 |
| :--- | :--- | :--- | :--- |
| **P1** | `crates/wolf-game/src/game.rs:235-265`<br>`crates/wolf-game/src/assets.rs:132-160` | **`picture_ink_rect_in()` 每帧全图像素扫描**：侧栏自动缩回（`320/2300`，`330×576`）与 `hover` 轮询每帧对未透明区域逐像素扫描 alpha。 | 在 `Assets` 增加 `HashMap<(String, [u32; 4], u8), Option<[u32; 4]>>` 缓存（`clear()` 时同步清空），将扫描降为 O(1) 查表。 |
| **P1** | `scripts/WolfText.gd:165-175` | **每帧全量重建 `TextParagraph`**：`WolfText.draw_text()` 每帧为屏幕上的每条文本执行 `TextParagraph.new()` + `add_string()`，重复触发 HarfBuzz/FreeType 文本塑形。 | 在 `WolfText` 按 `(text, weight, px, width)` 缓存 `TextParagraph` 对象（保留最近帧活跃项），仅在文本或字号变化时重新塑形。 |
| **P2** | `crates/wolf-gdext/src/lib.rs:275, 289` | **`frame()` 内 `choice_options` 重复 `clone()`**：同一帧内为构造 `packet["choices"]` 和传入 `overlay_at_sized` 分别克隆了选项数组。 | 合并为单次读取或直接借用 `game.choices` 构造。 |
| **P2** | `crates/wolf-gdext/src/lib.rs:719-737`<br>`scripts/GameView.gd:1029-1052` | **启动期重复读取 16.9 MB 字体**：`WolfGame::open()` 与 `GameView._ready()` 各自从磁盘读取一次 `msyhbd.ttc`。 | 属于一次性启动成本（约百毫秒级），如优化冷启动可改为由一端加载后共享字节或缓存 metrics。 |

---

## 三、推荐实施顺序

1. **高危/主流程修复**：`self.choices` 协程失活自动清理 → `choice_anchor (0,0)` 回退居中 → `install_map` 清理 `MAP_SELF_BASE`（+ 取消 `m16_old_bug_review` `#[ignore]`）。
2. **UI 与交互修复**：`hud_action_points` 文本校验 + 进度条样式对齐 → `36002` 底边钳位 → 选项控制码剥离。
3. **性能优化与稳定性**：`Assets::alpha_bounds_in` 缓存 → `WolfText` `TextParagraph` 缓存 → `WolfRng` 游标与 `audio_cache` 上限。
