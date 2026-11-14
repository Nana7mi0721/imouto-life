# Gemini 全量审查 `1c76dcc` 处理报告

- 审查输入：`docs/Full Code Review 1c76dcc.md`（基线 `141c524` + `1c76dcc` 22 文件增量，总评 Approve with changes）
- 处理基线：当前 `HEAD 1c76dcc`，工作区本轮只改 `crates/wolf-game/src/game.rs`、`crates/wolf-game/tests/m4_load_resume.rs`、`godot/scripts/GameView.gd`
- 处理原则：先按当前源码核实报告条目，能确认的缺陷加回归测试后修复；报告里“待核对 `1a9fafe`”的条目以当前代码为准，不照抄旧基线行号；未被本作数据触达的 P3 只记录不扩大改动面。

---

## 1. 结论

| 报告条目 | 当前结论 | 本轮动作 |
|---|---|---|
| **[P1-新] `TextQuadKey` 未计入 `balloon_frame_growth()`** | **成立**。`text_quads()` 先用 raw `y` 写 `y_bits`，`build_text_picture()` 才减去 lift；多行正文流式换行时 `36014` 会命中旧缓存。 | 已修复；新增 `a_streaming_balloon_lifts_the_nameplate_through_the_text_cache`。 |
| **[P1-待核对 `1a9fafe`] `Opcode 121` `self_range` 全局短路** | **当前代码已无该短路**。`batch_count` 直接取 arg4，`SelfVar` 也走完整 `0..=batch_count` 循环；已有 `op121_self_range_updates_every_slot_in_the_range` 覆盖。 | 无需改代码；在报告中记为已闭环。 |
| **[P2-待核对 `1a9fafe`] 瞬时 `Move` 取消 `Erase` 时残留 `transition`** | **当前代码已修**。`Screen::apply` 的无时长 `Move` 分支执行 `picture.transition = None`；`move_cancels_an_erase_fade` 已断言 `transition.is_none()` 且 `opacity == 255`。 | 无需改代码；在报告中记为已闭环。 |
| **[P3-优化项] 行动力数值三位数贴靠 `精力`** | **成立但属预留优化**。当前 `100/120` 的 ink 右边界会到约 764，`精力` 起点 760。 | 已按报告推荐方案 2 实现：条体/标签左移 15 px，数值右对齐到 750；新增 `hud_action_points_three_digit_value_clears_stamina_column`。m14 像素基线未变。 |
| **[P3-既有] `Opcode 125` 单协程同帧多次 `123` 只消费一次** | 仍存在。`123` 首次命中 auto key 后把 instance id 写入 `auto_keys_delivered`，同协程同帧第二次 `123` 读到 0。 | 未改代码；本作数据未依赖该行为，保留为已知边界项。 |
| **[P3-既有] `Vm::spawn_child()` 未继承 `is_parallel`** | **当前代码已修**。`spawn_child` 已执行 `child.is_parallel = self.instances[caller].is_parallel`。 | 无需改代码；在报告中记为已闭环。 |

---

## 2. 新 P1：人名牌缓存错位

### 2.1 根因确认

`1c76dcc` 的 `text_quads()` 在 `crates/wolf-game/src/game.rs` 中先算：

```rust
let (dx, dy) = picture.effect_offset();
let x = picture.x as f32 + dx;
let y = picture.y as f32 + dy;
...
let key = TextQuadKey {
    ...
    y_bits: y.to_bits(),
    ...
};
```

而 `balloon_frame_growth()` 只在 `build_text_picture()` 内部被减去。于是当 `36013` 的正文从一行流式扩到多行、`36000` 的 frame 向上长高时：

- `picture_quads()` 把 `36008..=36012` 名称条向上平移；
- `36014` 的 `text`、`x`、`y`、`anchor`、`alpha`、`font_gen` 全都没变，`TextQuadKey` 命中旧缓存；
- 缓存的 quads 仍带着旧的 `balloon_lift = 0` 坐标，人名掉进正文或悬空。

报告判断与源码一致，属真实缺陷，不是误报。

### 2.2 修复

把 lift 提前到缓存键之前，并让 `build_text_picture()` 只负责名称牌的 `+7 px` ink 偏移：

- `text_quads()`：对 `36013`/`36014` 计算 `balloon_frame_growth()`，先执行 `y -= balloon_lift`，再写 `TextQuadKey.y_bits`；
- `build_text_picture()`：不再重复减 lift，只加 `BALLOON_NAME_TEXT_Y_OFFSET`；
- 缓存命中与 miss 现在使用同一个已经抬升过的 `y`，流式换行不会再把旧图元取回来。

`build_text_picture()` 只有一个调用点（`text_quads()` 的 miss 分支），因此该重构没有第二处调用需要同步。

### 2.3 回归测试

`crates/wolf-game/src/game.rs` 新增：

`a_streaming_balloon_lifts_the_nameplate_through_the_text_cache`

测试构造：

1. `36000` frame，`window = 320 × 60`；
2. `36013` 正文，一行高度 `24`；
3. `36014` 名称 `妹妹`，位置 `(276, 456)`；
4. 第一次 `text_quads()` 让人名牌写入缓存；
5. 只把 `36013.text_size` 改成三行高度 `69`，使 `balloon_frame_growth() = 19`；
6. 第二次 `text_quads()`，断言名称 quad 的 `rect[1]` 比第一次上移 `19 px`。

修复前该断言会失败（第二次取到缓存里的旧 y）；修复后通过。

---

## 3. 两条“待核对 `1a9fafe`”

### 3.1 `Opcode 121 self_range`

当前 `crates/wolf-vm/src/exec.rs` 的 `121` 分支：

- `batch_mode` 由 `word & 0x10000` 决定；
- `batch_count = arg(cmd, 4).max(0)`，不按 `SelfVar` 强制归零；
- 循环 `for offset in 0..=batch_count` 对每个连续 target 执行 `store_num`；
- 已有单测 `op121_self_range_updates_every_slot_in_the_range` 明确覆盖 `1_600_022..1_600_025` 的 SelfVar 连续槽位，并断言普通变量也走完整范围。

因此报告里“基线存在、待核对 `1a9fafe`”的短路在当前 `1c76dcc` 已不存在，CE64 `pc=671` 的 `self53..=55` 批量赋值不会被截断。

### 3.2 `picture.rs` 瞬时 `Move` 取消 `Erase`

当前 `crates/wolf-game/src/picture.rs` 的 `Move` 分支在 `Transition::from_command` 返回 `None` 时执行：

```rust
None => picture.transition = None,
```

`move_cancels_an_erase_fade` 已覆盖完整链路：

- Draw → Erase 设置 `erase_after_slide`；
- 无时长 Move 后断言 `!erase_after_slide`、`transition.is_none()`、`opacity == 255`；
- 再推进 10 帧，仍断言 `opacity == 255`，确认旧 Erase 倒计时不会在之后把 alpha 归零。

该项也已在当前代码闭环。

---

## 4. P3：行动力数值定长/右对齐

### 4.1 实现

采用报告方案 2（右对齐定锚），同时把条体与标签整体左移 15 px，给三位数留出空间：

| 常量 | 旧值 | 新值 |
|---|---|---|
| `HUD_ACTION_LABEL_X` | `560.0` | `545.0` |
| `HUD_ACTION_BAR` | `[608, 18, 100, 12]` | `[593, 18, 100, 12]` |
| `HUD_ACTION_VALUE_X` | `716.0` | `750.0` |

`build_text_picture()` 的 value run 改为 `layout_with(..., 3, ...)`，即 `x=750` 作为右边界锚点；标签仍按原 anchor 左对齐。这样：

- `8/40`、`70/75`、`100/120` 的右边界都锁在 750；
- 数值不会随位数变化抖动；
- 距 `精力` 的 x=760 仍留 10 px 余量；
- 条体 593..693，数值 100/120 的 ink 从约 701 到 750，不压条体。

`godot/scripts/GameView.gd` 两处 `_draw_action_points()` 的 fallback `Rect2` 同步从 `(608,18)` 改为 `(593,18)`；正常路径仍使用 gdext 传下来的 `ap.bar`，fallback 只用于缺字段时。

### 4.2 回归测试

`hud_action_points_three_digit_value_clears_stamina_column`：

- 构造 slot 230 文本 `\f[14]行动力100/120`；
- `text_quads()` 找到 `100/120` 的 value quad；
- 用 `rect[0] + rect[2] - font_px` 计算 ink 右边界（`rect[2]` 含一 em 的 glyph-wrap slack，不能直接当墨迹宽度）；
- 断言右边界 `< 760`，且仍接近 750 的右锚点。

### 4.3 视觉基线

`m14_visual_regression` 复跑 **5 passed**，关键计数与改动前一致：

- `day_command`: text pictures/items/lines `24/23/23`，glyphs `76`，nonblack `533187`
- `hud`: text pictures/items/lines `15/14/14`，glyphs `44`，nonblack `554890`

说明左移 15 px 只改变同一顶栏内的字形位置，没有改变像素计数或文本数量。

---

## 5. P3 既有 VM 项

### 5.1 `Opcode 125` 单协程同帧多次 `123`

当前 `123` 的实现使用：

```rust
let auto_available =
    input.auto_keys != 0 && !input.auto_keys_delivered.contains(&inst.id);
```

首次消费后把整个 instance id 写入 `auto_keys_delivered`，同一协程同帧再执行一次 `123` 会看到 `auto_available = false`，读到 0。这与报告描述一致，仍保留为已知边界项。

未改原因：本作脚本的 `125` 使用路径没有依赖“同帧两次查询不同键位”；改动 delivered 的粒度会扩大输入状态机的改动面，且没有实机/字节码证据表明当前路径会触发。已在报告和交接文档中保留为待评估项。

### 5.2 `Vm::spawn_child()` 的 `is_parallel`

当前 `crates/wolf-vm/src/exec.rs` 的 `spawn_child()` 已包含：

```rust
child.is_parallel = self.instances[caller].is_parallel;
```

报告所述“未继承”在当前 `1c76dcc` 已不成立。

---

## 6. 验证记录

### 6.1 本轮直接相关

| 命令 | 结果 |
|---|---|
| `cargo fmt --all -- --check` | exit 0 |
| `git diff --check` | exit 0 |
| `cargo check -q --workspace` | exit 0 |
| `cargo test -q -p wolf-game a_streaming_balloon_lifts_the_nameplate_through_the_text_cache` | 1 passed |
| `cargo test -q -p wolf-game hud_action_points_three_digit_value_clears_stamina_column` | 1 passed |
| `cargo test -q -p wolf-cli --test m14_visual_regression` | 5 passed |
| `cargo test -q -p wolf-game --test m17_ui_regressions` | 21 passed |
| `cargo test -q -p wolf-game --test m18_t18_regressions` | 6 passed |
| `cargo test -q -p wolf-game --test m15_balloon_name` | 1 passed |
| `cargo test -q -p wolf-game --test m17_text_layer` | 5 passed |
| `cargo test -q -p wolf-game --test m3_hud_numeric` | 5 passed |
| `cargo test -q -p wolf-game --test m4_load_resume` | 2 passed |
| `cargo test -q -p wolf-game --test m4_hud_status` | 2 passed |
| `cargo test -q -p wolf-game --test m3_hud_layout` | 3 passed |

`m4_load_resume` 原先直接断言单个 `"行动力60/65"` quad；T12 已把该文本拆成 label/value 两个 run，本轮顺手改为去空白后 `compact.contains("行动力60/65")`，与当前 HUD 布局一致。

默认无 `WOLF_DATA_ROOT` 的 `cargo test -q --workspace -- --skip font_lookup_prefers_the_games_face_and_scans_unexpected_names` 只余既有 `m3_manual_rules::late_night_bedtime_skips_to_next_evening`（04:30 就寝实测 17:00 / 期望 19:00），没有本轮新增失败；该测试对数据敏感，和本轮改动无关。`wolf-game --lib` 在该默认模式下为 358 passed。

### 6.2 额外发现

`cargo test -q -p wolf-game --test m3_status_panel` 为 **5 passed / 1 failed**：

- 失败项：`ce238_relative_panel_lands_at_the_left_edge`
- 现象：隐藏分支把面板停在 `x=-305` 后，显示分支复跑 20 帧仍为 `(-305, 0)`，期望 `(0, 0)`
- 路径：`Screen::apply` 的 op150 相对 Draw 路径（`picture.rs`），本轮没有修改该文件
- 结论：与本轮人名牌/HUD 改动无直接关系，未纳入本轮修复；记录为待单独排查项。当前 `m3_status_panel` 其余 5 项通过。

真实数据下跑 `cargo test -q -p wolf-game --lib` 另有 2 项既有姊妹作 db 期望差异：

- `db::tests::clearing_a_row_zeroes_every_field_in_the_file_and_the_engine_layer`（「ヒーローさん」vs「勇者先生」）
- `db::tests::sysdatabase_decodes_the_face_graphic_type`（本作 face PNG vs 姊妹作 DLC 图）

这两项与 `docs/HANDOFF_M0.md` 已记录的“真实数据下另有两项既有 `db` 文本差异”一致，不是本轮引入。`wolf-game` 单测实际为 **356 passed / 2 failed**；去掉 `WOLF_DATA_ROOT` 的默认模式为 **358 passed / 0 failed**（数据用例按既有约定跳过）。

---

## 7. 文件清单

本轮改动：

- `crates/wolf-game/src/game.rs`
  - 气球 lift 提前到 `TextQuadKey` 之前
  - `build_text_picture()` 去除重复 lift
  - HUD 行动力常量与右对齐
  - 新增 2 条回归测试
- `crates/wolf-game/tests/m4_load_resume.rs`
  - 适配 T12 的 label/value 拆分
- `godot/scripts/GameView.gd`
  - 两处 action bar fallback x 从 608 改 593

未改：

- `crates/wolf-vm/src/exec.rs`（121 已闭环；125 保留）
- `crates/wolf-game/src/picture.rs`（瞬时 Move 已闭环）
- `docs/Full Code Review 1c76dcc.md`（Gemini 原始报告，保留原文）

---

## 8. 遗留项

1. `Opcode 125` 同协程同帧多次 `123` 的 auto-key 消费粒度，未改。
2. `m3_status_panel::ce238_relative_panel_lands_at_the_left_edge` 仍失败，待单独定位；本轮未触碰相对绘制代码。
3. 连续同人第二框翻页的瞬态闪烁仍需原版逐帧证据；本轮未加 latch。
4. 行动力条三位数布局已预留，但本作当前存档/数据是否会出现三位数仍未实测；本项属渲染侧防御。

---

## 9. 提交状态

本轮已本地提交 `112ed76`（`fix: close Gemini review 1c76dcc balloon cache and HUD reserve`），包含：

- 代码与测试：`game.rs`、`m4_load_resume.rs`、`GameView.gd`
- 文档：本报告、`HANDOFF_PROGRESS.md`、`HANDOFF_M0.md` §11.1、`README.md`

**尚未 push 到 `origin/master`。** `docs/Full Code Review 1c76dcc.md` 为 Gemini 原始输入，保持未跟踪，未纳入提交。
