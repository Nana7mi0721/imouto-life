# T13 UI / 命中盒回归审计

日期：2026-11-12
角色：T13 子代理「UI/命中盒审计员」
范围：用户本轮 15 类问题、前序截图取证、Godot/Rust UI 回归。
约束：未修改 `work/Data`，未改 `crates/wolf-gdext/src/lib.rs`、`godot/scripts/GameView.gd`、
`crates/wolf-game/src/game.rs`，未 commit/reset/checkout。

> **最终修订（2026-11-12 晚，优先于本文件下方的审计快照）**：
> 本文件最初记录的是“中央对话尚未闭环”的中间状态。后续补丁已把 CE270 气球正文
> `36013` 改为消息正文行距、清理 `\ax/\ay` 定位前导、令气球从底部向上增长，并在
> 气球可见时过滤原生 `19500/19501`；`m17_text_layer` 现为 **3 passed**（含三行
> 全部落在屏内）。`36014` 的 `message` 字面量在原版 `full_89EF.png` 中也存在，
> 在确认说话人规则前不应擅自隐藏。当前真实数据回归：`m17_ui_regressions` 13/13、
> `m17_t13_ui_audit` 3/3、`m17_render_regressions` 5/5、`m3_map_click` 8/8、
> `m3_hud_buttons` 9/9。侧栏入口在 T13 中间态曾从 48x96 热点扩展为整条 25px 可见滑条
> （物品栏 y 288..384 除外）；T14 已改为两个三角把手，见下方更正。
> 图片按钮优先。`m14_visual_regression` 现为
> **5 passed**：saveui 的 101 像素差归因为测试遗留 `SaveData03.sav` 第四格；
> 隔离只保留出货 01/02 时为 25/13、576227（与基线 576221 差 6 像素），
> 已加 `depends_on_save_grid` fixture 守卫。最终 DLL 20:09:05 已重建并完成窗口
> 复核：读档 180 帧无黄/绿像素，新游戏 300 帧三行正文 493/516/539 且无原生
> `19500/19501`。

> **T14 后续更正**：侧栏命中最终改为 `try_side_panel_handle`，只响应状态
> `(y≈118..157)` 与物品 `(y≈260..297)` 两个三角把手区，空白滑条不触发。
> 本文件下文出现的“整条 25px 可见滑条”均指 T13 中间态，不是现行实现。

## 0. 结论摘要

- 本轮相关回归在审计快照时为 **91 passed / 0 failed / 2 ignored**，覆盖 17 个
  target；后续文本补丁把 `m17_text_layer` 从 1 项扩到 **3/3 passed**。最终数字
  见上方“最终修订”。
- 已形成证据的闭环项：黄色瓦片层退场、CE63 黑色 tone 人头、夜间提示点击、
  结束按钮图片命中、触摸/衣服后数据图标隐藏、保存/相册/数据图片矩形命中、
  BAD 条负缩放几何、妹妹立绘命中、身份-白天 CG 分支。
- **当时的 P0（后续已修）：中央/底部对话重复。** 审计时同一句同时由 101 原生
  `message_layout()` 和 CE270 气球 `36013` 绘制；实测同时存在 `19500` 原生框、
  `36000` 气球框、原生 3 行文字、气球 2 行文字和字面量名牌 `message`。
  只抑制原生文字会留下不完整的气球文本，因此不能只做前端去重。后续补丁已按
  “修正文排布 + 隐藏原生 19500/19501”的方案闭环，详见上方最终修订。
- **证据不足、不能凭空补的项**：保存按钮 hover 高亮、哥哥体力条。
  扫描 350 个公共事件与 7 张地图后，v74/v75 没有任何绘图引用；v74 只在
  CE214 slot 126 的条件判断中出现，v75 无引用。需要主代理/用户给出原版目标图或
  确认“体力条”具体指哪个 UI 元素。
- 侧栏闪烁目前是 **120 帧逻辑稳定测试通过**，尚无连续实机录帧；
  点击左侧 25px 可见条可打开，但“拖拽拉出”没有实现。

## 1. 测试结果

环境：

```bash
cd '/e/Study/github program/Imouto Life'
source tools/env.sh >/dev/null 2>&1
export WOLF_DATA_ROOT="$PWD/work/Data"
```

| target | 结果 | 覆盖 |
|---|---:|---|
| `wolf-game/m17_text_layer` | 3 passed（最终） | 气球正文无前导 `0`、原生层抑制、三行不裁切 |
| `wolf-game/m17_ui_regressions` | 13 passed | 保存/数据/相册/结束命中、夜间提示、侧栏、妹妹轮廓、BAD 几何 |
| `wolf-game/m17_render_regressions` | 5 passed | 瓦片 fixture、图集裁剪、CE63 tone、气球脸 alpha |
| `wolf-game/m17_t13_ui_audit` | **3 passed（新增）** | 触摸/衣服/子菜单动作不复活数据图标 |
| `wolf-game/m3_map_click` | 8 passed | 地图事件点击桥、保存/状态/结束 |
| `wolf-game/m3_hud_buttons` | 7 passed | 日出 HUD 图标、面板、状态条 |
| `wolf-game/m3_hud_layout` | 3 passed | 稳定 HUD 全槽布局、Z 序、事件重绘 |
| `wolf-game/m3_night_interaction` | 6 passed | 夜间界面组合与状态条 |
| `wolf-game/m3_night_interaction_e2e` | 6 passed | 触摸/衣服/身体命中/结束链 |
| `wolf-game/m4_hud_status` | 2 passed | 读档行动力/精力 |
| `wolf-game/m4_night_gaps` | 3 passed | BAD 公式、结束按钮图片点击 |
| `wolf-game/m3_ui_screens` | 13 passed | CE237/238 等 UI 槽位 |
| `wolf-game/m3_visual_text` | 7 passed | 气球消息、文字层 |
| `wolf-game/m3_status_panel` | 6 passed | 妹妹状态面板 |
| `wolf-game/m15_balloon_name` | 1 passed | 明确说话人时 `36014` 名牌 |
| `wolf-game/m16_old_bug_review` | 2 passed / 2 ignored | 历史台账 BUG-20/24 通过；报告 §六 BUG-21、历史台账 BUG-23 合成探针忽略 |
| `wolf-vm/m17_identity_branch` | 5 passed | 学生/社会人/自由职业/NEET 身份分支 |

## 2. 用户 15 项逐项审计

### 1. 进入游戏几帧黄绿斑点

**状态：已修（前端路径）；仍建议实机首 5–10 帧复核。**

证据：

- `wolf-gdext` / `GameView.gd` 已无 `tile_quads`、`tile_texture`、
  `tile_revision`、`tile_tint` 任一符号；玩法前端不再绘制地图瓦片。
- 当前 `wolf-cli` 新游戏/读档 capture 的背景为黑场或完整 CG，不再出现
  `MapChip/[A]Dirt1_pipo.png` frame 4 的黄色棋盘。
- `m17_render_regressions` 仍保留原始地图数据 fixture，确认黄色 dirt 是**数据中的**
  卧室地板单元；它不代表前端仍应绘制该层。

仍缺：

- 没有自动化断言“Godot 启动前 N 帧完全无瓦片色块”；建议用现有 Godot viewport
  capture 抓 `--frames=1,3,5,10` 做一次视觉 smoke，但这不应阻塞当前逻辑回归。

### 2. 黄色地图背景

**状态：已修（玩法前端）。**

证据：

- `t13_audit_event245.png` 显示卧室 CG 正常，背景无黄色铺满。
- 前端瓦片层已被移除；`capture --map` 保留瓦片仅用于地图数据检查，不是玩家游戏路径。

建议：

- 不要把 `capture --map` 的黄色瓦片误判为回归；该路径按设计 `include_tiles=true`。

### 3. 屏幕中间对话显示异常 / 中央与底部重复

**状态：已修（2026-11-12 后续补丁）；最终实机像素复核待做。**

> 以下“实测证据”保留修复前快照，用于说明为什么不能只在前端按字符串去重。
> 修复后的三行位置为 493/516/539，气球最低高度 60px，原生
> `19500/19501` 在气球可见时被过滤；`m17_text_layer` 3/3。

实测证据：

```text
Message 300 帧 capture:
  pic 19500  WindowString ... (960,168), 原生消息框
  pic 36000  WindowString ... (580,60), 气球框
  pic 36013  Text ... 正文
  pic 36014  Text ... "\>message"
  text pic 36013 at [238,538] 第 1 行
  text pic 36013 at [238,564] 第 2 行
  message : 3 row(s), 42/42 char(s), font 20 at [64,410], wrap 896
```

截图：`work/out/t13_audit_message300.png`。同一段文字在原生框和气球框各出现一次；
气球只显示 3 行中的前 2 行，第 3 行落在画面下方；名牌显示字面量 `message`。

代码路径：

- `crates/wolf-gdext/src/lib.rs:308` 与 `:351` 都无条件读取
  `game.message_layout()`；前者画原生光标，后者把原生文字追加到 `texts`。
- `crates/wolf-cli/src/main.rs:3835` 也在 `text_quads` 之后追加原生消息文字。
- `Game::text_quads()` 同时会输出可见的 CE270 气球 `36013`，因此两套文字共存。
- `crates/wolf-game/src/game.rs:1778` 的 `message_layout()` 本身不应删；它仍是
  测试/调试/无气球消息的合法来源。

判断：

- **不能只在前端按文本字符串去重**：这类台词可能合法重复，去重会误删；
- **不能只隐藏原生文字**：当前气球正文只有 2/3 行且名牌是 `message`，
  隐藏原生层会让玩家丢掉第 3 行；
- CE63 的原生框 `19500` 与 CE270 的 `36000` 也同时可见，是否保留原生框需要按
  目标版本决定。

建议主代理：

1. 在 `Game` 增加集中判断，例如 `balloon_message_active()`：
   屏幕中存在可见、非空、`owner_event == 270` 的正文 text picture；
2. 增加仅供渲染的 `message_layout_for_renderer()` / `message_cursor_for_renderer()`：
   气球正文有效时统一返回 `None`，否则返回原生布局；
3. `wolf-gdext` 与 `wolf-cli` 两条渲染路径都改用该 API；
4. 单独修 CE270 正文排布/名牌，先用真实场景确认 3 行内容应落在哪个框；
5. 若气球是唯一的成交显示路径，再决定是否隐藏 `19500`；不要先删原生框。

### 4. 妹妹说话时右下角黑色阴影人头

**状态：已修（根因已定位并有回归）。**

证据：

- CE63 pc131 使用 `0x01000000` 标志，但 args 15..17 是编辑器填充零；旧代码把
  这三个零当作 tone，导致 `19501` 脸层变成纯黑轮廓。
- `crates/wolf-game/src/picture.rs` 现在只把 `0x02000000` 当作
  `TONE_PRESENT`，才读取 tone triplet。
- `m17_render_regressions::the_ce63_window_draw_keeps_the_unused_tone_tail_neutral`
  通过；真实 CE94 tone 仍能到达图片。
- `work/out/t13_audit_event245.png` 未出现纯黑人头。

仍缺：

- 没有保存一份“修复前后同帧像素 diff”作为长期视觉基线；若需要可将
  `t13_audit_event245.png` 作为人工证据，不建议直接硬编码进测试。

### 5. 侧边妹妹状态栏闪烁 / 无法拉出查看

**状态：部分闭环。逻辑可开、120 帧不闪；无连续视觉证据，未实现拖拽。**

证据：

- `m17_ui_regressions::parked_status_sliver_opens_and_stays_stable_until_pointer_leaves`
  点击 `(8,192)` 打开 CE238，`320` 从 `x=-305` 滑到 `x=0`，指针停留 120 帧
  `x` 保持 `0`，移出后回到 `-305`。
- `m17_ui_regressions::status_sliver_does_not_steal_the_item_hotspot` 通过。
- `m3_hud_buttons::status_strip_opens_through_the_visible_sliver` 通过。
- 审计快照时可见交互是左边缘约 25px 的条带点击，`Game::try_status_panel_strip`
  只接受 `x < 25`、`y=144..240`。**T13 最终修订曾扩展为整条可见滑条点击**
  （物品栏 y 288..384 除外）；T14 已改为两个三角把手，图片按钮优先；仍没有
  按住拖拽手势。

仍缺：

- 没有 Godot 连续帧截图证明“视觉上不闪”；
- 若原版要求“拖出”而不是“点击条带”，当前实现仍不满足；
- 状态栏在屏外的 330px 面板仍可能被用户误认为裁切，建议实机录一段指针停留/
  移出序列确认。

### 6. 第一次恶作剧系统提示点击后不消失

**状态：已修（点击优先级测试通过）。**

证据：

- `m17_ui_regressions::night_message_click_is_not_eaten_by_parallel_pollers`
  在提示出现后点击 `(512,288)`，5 帧内提示消失。
- `m17_ui_regressions::night_notice_dismissal_restores_the_save_icon_click`
  继续点击保存图标可触发 `ev5`。
- `m3_night_interaction_e2e` / `m4_night_gaps` 的夜间流程通过。

约束：

- 该修复依赖“点击先清 message，再让地图热点/并行 poller 处理输入”的顺序；
  以后改 `Game::frame` 输入顺序必须保留此回归。

### 7. BAD 条外框视觉消失

**状态：几何已修；视觉上当前 capture 能看到 BAD 侧 217x6 的薄框。**

证据：

- `t13_audit_ce237.log`：
  `1998` 为 `<SQUARE><FRAME>`，`scale=-100`，quad
  `[274,57,217,6]`；`1994` GOOD 外框 quad `[530,56,217,8]`。
- `m17_ui_regressions::negative_bad_bar_scale_keeps_a_nonzero_geometry_and_hit_box`
  断言负缩放不会塌成 0，且横向覆盖到 BAD 标签。
- `work/out/t13_audit_night230.png` 顶部可见 BAD 侧外框/轨道；不再是零宽。

仍缺：

- 没有原版同分辨率像素基线判断“外框是否应更粗/更闭合”；当前数据本身是 217x6，
  6px 高的闭合框在视觉上天然很薄，建议主代理用原版截图确认形状，不要盲目加粗。

**2026-11-13 后续：** `ptr_sc/恶作剧_BAD&GOOD条特写.png` 已确认中央睡眠圆标
覆盖两根外框的内侧端点。`wolf-gdext` 原先将 `1994/1998` 抬到 `z=2001` 的折中
已移除，改为自然槽位顺序；外框仍按数据给定的 217x6/217x8 绘制，不再作为
“外框消失”问题处理。

### 8. 哥哥体力条视觉上不显示

**状态：证据不足，不能定位槽位。**

数据扫描：

- 350 个公共事件 dump 中，只有 CE214 slot 126 读取 `2000074`：
  `args=[2,2000068,1,2,2000074,0,2]`；
- 没有公共事件引用 `2000075`；
- 7 张地图 dump（11,945 行）没有任何 `2000074/2000075` 绘图引用；
- CE237 只画 GOOD/BAD 条、睡眠图标，没有哥哥 stamina 条槽；
- 当前夜间截图顶部只有文字 `精力 3/3`，没有额外体力条。

判断：

- “哥哥体力条”可能指顶部 `精力 3/3` 文本的图形化替代，也可能是原版另一处我们
  尚未定位的 UI；在数据中没有可见槽位/图片引用，不能凭猜测加一个条。

建议主代理：

1. 向用户确认目标元素的位置/截图；
2. 若指 `精力 3/3`，当前已显示，属于视觉设计问题而非缺失数据；
3. 若指独立的 stamina gauge，需要先找到原版 slot/file 或事件；否则新增 UI 会
   违背“没证据不臆造”。

### 9. 卧室点击妹妹位置判定范围太小

**状态：已修到可见立绘包围盒；不是 alpha 轮廓级命中。**

证据：

- `crates/wolf-game/src/game.rs:2338` 的 `sister_body_action_event_at` 合并
  可见 `900..903` 的 `picture_rect()`，并通过 `v14` 映射到 ev1/2/3/4/25。
- `m17_ui_regressions::bedroom_standing_art_maps_v14_to_the_action_events`
  覆盖 5 个姿态；
- `bedroom_standing_art_gates_outside_pixels_and_deep_night` 证明轮廓左外 1px
  不触发、深夜不抢控制；
- `m3_night_interaction` 的身体图层与交互链通过。

仍缺：

- 这是 900..903 可见矩形并集，不是逐像素 alpha mask；人物透明边缘仍可能命中。
  若用户要求“人物轮廓”严格贴合，需要 alpha/mask 命中，不建议在当前任务中
  无基线重做。

### 10. 恶作剧点击结束无反应

**状态：已修。**

证据：

- 结束按钮 `1108` 的图片矩形是 `(935,505,90,70)`；事件 21 旧 tile 盒是
  `(976,544,96,64)`，只覆盖右下角。
- `m17_ui_regressions::night_end_button_uses_its_picture_and_hides_the_data_icon`
  与 `night_end_button_center_starts_the_end_page` 在中心点击均触发 `ev21`。
- `m4_night_gaps::clicking_picture_1108_opens_ev21_and_yes_ends_the_interface`
  走完是/否分支并进入就寝链。

注意：

- 如果夜间提示 message 还在，第一次点击会先用于关闭提示；这是有意的事件所有权，
  不是重复丢失输入。

### 11. 点触摸/衣服时数据图标错误出现且压在结束按钮下

**状态：已修，新增回归覆盖动作页。**

证据：

- 初始夜间界面 `-4` 不可见；`1108` 可见（`m17_ui_regressions`）。
- 新增 `crates/wolf-game/tests/m17_t13_ui_audit.rs`：
  - 点击 `400`（触摸页）后 `-4` 仍隐藏；
  - 点击 `404`（衣服页）后 `-4` 仍隐藏；
  - 点击 `400 -> 390 -> 430`（子菜单/脱衣动作）后 `-4` 仍隐藏。
- 3/3 passed。

仍缺：

- 没有逐帧记录“图标刚被画出一帧又隐藏”的瞬时泄漏；当前以点击后稳定帧断言。
  若实机仍能闪一帧，建议在 `GameView` 捕获连续 3–5 帧并记录 `-4` 的
  `hidden/opacity`。

### 12. 保存按钮未高亮 / 不可点击

**状态：点击已修；hover 高亮未证实。**

已修：

- `m17_ui_regressions::night_save_icon_opens_from_the_touch_page`：从夜间触摸页
  点击 `-5` 可启动 `ev5` 并进入 CE131；
- `night_notice_dismissal_restores_the_save_icon_click`：提示关闭后保存仍可点；
- 保存命中区为图片矩形 `(10,510,80,60)`，旧 tile 盒不再抢/漏。

仍缺：

- 数据只有一张 `Picture/icon01.png`，没有独立的 hover/selected 资源；
- `picture_action_event_at()` 只路由事件，不修改 `tone/opacity/blend`；
- 当前代码没有保存按钮 hover 高亮/悬停变色逻辑。

建议：

- 若原版确有 hover 高亮，需提供原版截图/视频或素材槽证据，再有针对性地在
  `Game` 的 picture action 层加视觉状态；不要仅凭“看起来暗”改全局 tint。

### 13. 保存/相册/数据点击判定应等于图标本身

**状态：已修。**

证据：

- `m17_ui_regressions::visible_picture_rectangles_are_the_save_and_data_hit_boxes`
  断言保存 `(10,510,80,60)`、数据 `(925,507,80,60)`；
  旧 tile 盒外/内交叉点分别不触发/触发。
- `album_icon_uses_its_visible_picture_rectangle` 断言相册
  `(925,430,80,60)`，点击旧全屏盒不打开 CE303，点击图标中心打开。
- 结束按钮同理由图片矩形 `(935,505,90,70)` 控制。

同类风险：

- 图片矩形包含透明像素，这是 WOLF 文档定义的 picture hit area；若用户要求
  “非透明像素才可点”，那会变成 alpha mask，和当前测试契约不同，需要另开需求。

### 14. 哥哥身份与白天过场 CG 不匹配

**状态：已修（VM 分支层），测试通过。**

证据：

- `m17_identity_branch` 5/5:
  - CE251 重复标签取第一次定义；
  - 学生走 CE252 和学生 CG，不画办公室 CG；
  - 社会人走 CE254 和 `cg/bg_004_01.jpg`/`cg/bg_005_01.jpg`；
  - 自由职业/NEET 不画社会人办公室 CG。
- `m3_hud_layout` 仍断言学生身份 HUD 文本为 `哥哥（学生）`。

仍缺：

- 测试从 CE251 的白天入口 pc 1118 驱动分支，不是完整从居所地图走到白天过场的
  真实回放；若实机仍偶发错 CG，下一步应捕获具体 day/时间与当前 `screen` 的
  CG slot，而不是再改身份标签解析。

### 15. 举一反三：命中范围 / UI 显隐 / 文字位置 / Z 顺序

**状态：已补同类回归；剩余项均需原版证据或新 DLL 实机复核。**

已复核：

- HUD 稳定槽顺序、Z 序、`12000+` 存档面板覆盖关系由 `m3_hud_layout` 覆盖；
- 结束/数据/保存/相册四个图片按钮的命中区由 `m17_ui_regressions` 覆盖；
- 夜间触摸/衣服/子菜单动作不复活 `-4` 由新增 `m17_t13_ui_audit` 覆盖；
- CE237 负缩放 BAD 条不再塌陷；
- 文本前导 `0` 由 `m17_text_layer` 覆盖。

仍缺/建议：

1. **中央文字双源**：已在后续补丁闭环（见第 3 项与顶部最终修订），
   仍需新 DLL 的实机像素复核；
2. **名牌 `message`**：`36014` 的字面量在原版参考图中也出现，需确认
   不同说话人的名牌规则，不能仅凭外观删除；
3. **保存 hover 高亮**：见第 12 项；
4. **哥哥体力条**：见第 8 项；
5. 侧栏拖拽、人物 alpha 轮廓仍需原版截图/素材证据。

## 3. 可复现证据文件

| 文件 | 用途 |
|---|---|
| `work/out/T13_SCREENSHOT_TRIAGE.md` | 用户 9 张截图的逐像素/槽位取证 |
| `work/out/t13_audit_message300.png` | 中央/底部对话重复、原生框/气球框、名牌 `message` |
| `work/out/t13_audit_message300.log` | `19500`/`36000`/`36013`/`36014` 与原生 `message_layout` 原始行 |
| `work/out/t13_audit_night230.png` | 夜间 UI、BAD/GOOD、数据图标隐藏、保存按钮 |
| `work/out/t13_audit_ce237.png` | CE237 状态条与 BAD 负缩放外框 |
| `work/out/t13_audit_ce237.log` | 1992..2000 槽位与 quad 坐标 |
| `work/out/t13_audit_event245.png` | 妹妹说话/夜间菜单场景，无黑色人头 |
| `work/out/t13_all_events_dump.txt` | 350 个公共事件变量引用扫描 |
| `work/out/t13_all_maps_dump.txt` | 7 张地图事件变量引用扫描 |

## 4. 主代理修复优先级

### P0（已完成）

1. 中央/底部对话双源已在 `Game` 层集中处理：气球正文可见时
   `rendered_message_layout()` 返回 `None`，并过滤 `19500/19501`；GDExt 与
   `wolf-cli` 共用该渲染 API，未做前端字符串去重。
2. CE270 正文已改为消息行距、清理定位前导并向上扩框；三行均可见。
3. 仍需在新 DLL 上做一次 `message300` 实机像素复核；这不改变逻辑测试结论。

### P1

1. 确认“哥哥体力条”目标元素；当前没有可追踪的绘图槽，暂不要新增臆造 UI。
2. 保存按钮 hover 高亮需要原版证据；点击可用性已闭环。
3. 侧栏若要求“拖拽”而非“点击左侧条带”，需单开交互设计；当前只有点击路径。

### P2

1. Godot 首 5–10 帧黄绿斑点 capture smoke；
2. 侧栏连续 120 帧实机 capture，证明无闪烁；
3. 夜间动作页逐帧 `-4` 泄漏检查（当前稳定帧已通过）。
4. 文档同步已完成：T12 tile texture/packet、27,653 sprites 与 64 MiB 整页上传
   均已标为历史；当前方案是玩法前端不发 tile、atlas 只上传 content bbox。
   引用旧编号时必须写“历史台账 BUG-xx”或“报告 §六 BUG-xx”。

## 5. 本次新增/修改

- 新增：`crates/wolf-game/tests/m17_t13_ui_audit.rs`
  - `touch_button_page_does_not_restore_the_night_data_icon`
  - `clothes_button_page_does_not_restore_the_night_data_icon`
  - `action_submenu_does_not_restore_the_night_data_icon`
- 未修改生产代码；未修改 `work/Data`。
