# 《妹！生活 ～単色～》T12 收口与实机截图复核报告

> 日期：2026-11-14  
> 仓库：`E:\Study\github program\Imouto Life`  
> 本轮基线：`47dd4e0`（上一轮 T12 产物）  
> 身份：`imoto lead <lead@imoto.local>`  
> 范围：T12 性能补丁/审计收口（第一轮）+ `docs/imouto_life_rebuild_fixes_and_full_audit.md` 与 `重构游戏问题截图/` 实机复核（第二轮）  
> 约束：不改 `work/Data`，不改零售参考图；所有结论以当前源码、真实数据反汇编、Rust 截图和用户实机截图互证。

---

## 0. 结论摘要

本轮把用户回传的截图逐项对回脚本和渲染层，确认了两处此前未定位到的根因并落地：

1. **开场黑屏的孤立行动力空槽**：不是宿主绘制的 `HUD_ACTION_BAR`，而是槽位 `230` 的 **窗口图片皮肤**。序章把旁白写进同一个槽位，`hud_action_points()` 只校验“有数字”就把它当成行动力读数；窗口图片即使没有有效文本，`Atlas` 仍会画出 1×1 窗口皮肤，形成只有空槽、没有 label/数值的截图。已在 `split_action_readout()` 增加“行动力/行動力”前缀校验，并在 `picture_quads()`、`text_quads()` 两处抑制无效的 230。
2. **茶摊选项的豆腐块**：`CommonEvent.dat` 的 CE257 红茶价格里有一段 7 个 `0xA1` 的奇数 GBK run，严格解码会产生一个 `U+FFFD`。`m3_string_decode` 已明确要求解码器保留它、不得为数据缺陷改 GBK 回退。修复放在显示层 `choice::option_label()`：含 `U+FFFD` 的选项替换为空格，原始选项键和分支值一字不动。

另外找到“格子进度条不显示”的主要根因：CE277 的警戒度条用 `\img[Picture\box01.png]` / `\img[Picture\box02.png]` 作为一格一格的小方块，而 `message.rs` 的文本 token 处理此前把所有 `TextToken::Image` 静默丢弃，整条格子条因此变空。现已把这两个 19×20 单色方块映射为 `□`/`■` 文本字形，并补了单测；其他 `\img` 仍保持“丢弃而不猜测”的原有策略。

**未改的结论**：

* **19:00 第一句黑底不是移植 bug**。`work/out/ev0_newgame.tsv` 显示 pc305/306 的妹妹台词在 pc318 画 `cg/bg_001_06.jpg` 之前，pc326 才把 `-1` 黑幕透明度改为 0，pc348 才画卧室 `cg/bg_001_04.jpg`。这是原脚本的序章演出顺序；零售 `ptr_sc/卧室_点击妹妹_首句话.png` 是 19:30、点击后已推进到背景出现的时点。强行提前画背景会改变序章演出，本轮不做。
* **读档后选项停在左上**：用户已明确“已解决”，不再列为待修项。
* **连续同人第二句 `message` 名牌**、**茶摊左侧物品列表豆腐块**、**随机事件结果固定**、**夜晚身体部位点击/底部姿势图标**仍缺零售逐帧证据或脚本运行态证据，本轮只做根因定位，不凭猜测改行为。

---

## 1. 第一轮：T12 补丁与 Gemini P1 收口

### 1.1 T12 已落地内容

`docs/HANDOFF_T12_PATCH_AND_LEDGER.md` 记录的第一轮工作已提交在基线 `47dd4e0` 之前的提交链中：

| 项目 | 状态 | 证据 |
| :--- | :--- | :--- |
| `Assets::alpha_bounds_in` 记忆化（每帧全图像素扫描 → O(1) 查表） | 已完成 | `crates/wolf-game/src/assets.rs`；`m14_visual_regression` 5/5 |
| `install_map()` 清扫 `MAP_SELF_BASE` 协程 + 清空 `self.choices` | 已完成 | `game.rs:1576-1620`；`m16_old_bug_review` 4 passed / 0 ignored |
| `wolf-gdext` 选项双 `clone()` 合并 | 已完成 | `crates/wolf-gdext/src/lib.rs`；`cargo check -q -p wolf-gdext` |
| 停靠侧栏 0.2 alpha 复原 | 已完成 | `SIDE_PANEL_PARKED_ALPHA`；`m18_t18_regressions` 6/6 |
| `TextQuadKey` 未计入 `balloon_frame_growth()`（Gemini P1） | 已修复 | `112ed76`；流式换行回归 |
| 行动力右对齐（Gemini P3） | 已按报告实现 | `HUD_ACTION_LABEL_X=545`、`HUD_ACTION_BAR=[593,18,100,12]`、`HUD_ACTION_VALUE_X=750`；三位数回归 |
| `Opcode 121`、瞬时 `Move` 清 `transition`、`spawn_child` 继承 `is_parallel` | 已闭环 | 对应单测与 `m14` 5/5，像素基线 533187 / 554890 未动 |

### 1.2 第一轮遗留

* `m3_status_panel::ce238_relative_panel_lands_at_the_left_edge` 在真实数据下仍失败（面板停在 -305），属于 `picture.rs` 相对绘制的独立待查项。
* `m14` 的两个像素基线未变，但 T12 只重钉了文本计数；行动力条的视觉仍以 `smoke.gd` 的 `action_points_normal_batch=ok` 和代码审查为主，缺 1024×576 原版顶栏完整对照图。

---

## 2. 第二轮：截图与审计问题逐项复核

### 2.1 开场黑屏的孤立行动力条（已修复）

**用户截图**：`重构游戏问题截图/新游戏开头黑屏阶段显示行动力条.png`（1024×576，黑屏“一个月前——”，顶部中央只有空槽）。

**根因链**：

1. 序章把旁白写进 picture slot `230`，但 `hud_action_points()` 旧逻辑只要求 slot 是 text、`split_action_readout()` 能从字符串里找到第一个 ASCII 数字；旁白里的数字/日期也能通过。
2. `230` 本身是 `WindowString` 窗口图片。即使没有有效读数，`Atlas` 仍会按窗口皮肤画出一个 1×1 的空槽；宿主 `HUD_ACTION_BAR` 又只在有读数时画，于是截图里只剩孤立空槽。
3. 旧 `split_action_readout()` 把任意 prefix 都当作“行动力”标签，没有校验语义。

**修复**：

* `split_action_readout()`：先 `wolf_format::messagetext::strip(prefix)`，要求纯文本包含“行动力”或“行動力”，否则返回 `None`。
* `Game::picture_quads()`：`hud_action_points().is_none()` 时 `retain` 掉 `HUD_ACTION_PICTURE`（230），连窗口皮肤一起隐藏。
* `Game::text_quads()`：230 且拆分失败时直接 `continue`，避免旁白进入普通文本 pass。
* 新增 `m4_hud_status::prologue_text_in_slot_230_is_not_mistaken_for_the_gauge`。

**验证**：

* `m4_hud_status` 真实数据 3 passed。
* 修复后 360 帧截图 `work/out/prologue_fixed360.png`：顶部只剩 HUD 文本，没有孤立空槽。
* 仍保留了一个已知语义：序章在 `-1` 黑幕期间 HUD 文本会随 CE242 出现；这不是空槽问题，若要与零售 `ptr_sc/开场对话_妈妈.png` 的“全黑、无 HUD”完全一致，需要另立“序章隐藏整套 HUD”的演出规则，不能顺手改。

### 2.2 19:00 第一句“背景应当是卧室”（不是移植 bug）

**用户截图**：`新游戏开头妹妹开始对话时背景是黑屏_应当是卧室.png`（19:00 周一、妹妹立绘、姓名“妹妹”、正文“饭已经做好了哦，一起吃吧。”、背景全黑）。

**反汇编证据**：`work/out/ev0_newgame.tsv`

| pc | 指令 | 含义 |
| :--- | :--- | :--- |
| 305/306 | `101` 妹妹台词 | “啊，哥哥欢迎回来。” / “饭已经做好了哦，一起吃吧。” |
| 318 | `150` `cg/bg_001_06.jpg` | 此时才画第一张晚饭背景 |
| 326 | `150` `1,-1,30,...` | 把 `-1` 黑幕透明度改 0（30 帧过渡） |
| 348 | `150` `cg/bg_001_04.jpg` | 才画卧室背景 |

**结论**：第一句在黑色 `-1` 黑幕上是**脚本顺序**，不是 Rust/Godot 渲染把背景弄丢。零售参考图是 19:30、点击后已推进到 pc348 之后，所以有卧室。若强行在 pc305 前画 `bg_001_04`，会改变序章演出并覆盖 `-1` 黑幕转场，本轮明确不改。

### 2.3 茶摊选项豆腐块（已修复）

**用户截图**：`重构游戏问题截图/选项文字出现乱码.png`（“茶 / 玉露 / 咖啡 / 红茶 + 1000/5000/1000/2000 円”，每行左侧有豆腐块）。

**根因**：CE257 的红茶价格原始字节为 `\xba\xec\xb2\xe8` + 7 个 `0xA1` + `2000`，是奇数 GBK run。严格解码器按设计保留一个 `U+FFFD`；`m3_string_decode.rs` 明确断言不得为源数据缺陷改 GBK 回退（否则 136+ 条合法日文 UI 受影响）。

**修复**：`choice::option_label()` 改为返回 `Cow<'_, str>`；仅当选项含 `U+FFFD` 时 `Cow::Owned(other.replace('\u{FFFD}', " "))`。测量和绘制都用清洗后的标签；原始 `options` 键、分支值和 VM 返回值不变。新增 `the_known_ce257_replacement_character_never_reaches_the_glyph_pass`。

**验证**：`cargo test -q -p wolf-game --lib choice` 与 `m4_hud_status` 均通过；截图中的“♦ 2000”应变为空格加价格。左侧物品列表的豆腐块是另一条渲染路径，见 §2.4。

### 2.4 茶摊左侧物品列表豆腐块（未修复，已缩小范围）

**观察**：选项面板的豆腐块已由 `U+FFFD` 清洗解决；截图左侧“茶/玉露/咖啡/红茶”每行前的小方块属于**物品图标列**，不是选项文本。CE239/CE257 的物品列表可能使用 `\img[Picture/item_iconNN.png]` 或私用区字形；当前 `message.rs` 对非 `box01/box02` 的 `\img` 仍丢弃，字体缺字时也可能显示豆腐块。

**下一步**：用 `wolf-cli assets --include-maps --coords --filter item_icon` 定位槽位与事件，确认是图片 token 被丢弃还是字体缺字；不要用全局替换 `◆`/私用区字符的方式掩盖。

### 2.5 连续同人第二句 `message` 名牌消失（未修复，待零售逐帧证据）

**用户截图**：`当前后连续两个对话都来自同一人时，后面对话的人民框消失.png` 与 `人名框消失参考_此处原本应有人名框_为message.png`。

**现状**：`balloon_nameplate_active()` 只检查 `36014` 是否 visible、opacity > 0、文本非空；`36008..36012` 整组在 36014 不活跃时被 `retain` 掉。连续同人翻页瞬间若 CE270 把 36014 置空/透明，名牌会消失。

**为什么不改**：目前没有零售逐帧录像确认第二句是否应保留名牌；`text_quads()` 对 `36014` 的 `alpha=0` 仍会生成不可见图元。强行把 alpha 拉到 1 可能破坏 CE270 的淡出节奏；若脚本已隐藏 36008..36012，单独恢复文字也得不到完整名牌。需要原版逐帧截图或 CE270 的 36014/36008..36012 显隐条件。

### 2.6 文字与消息框略微错位（旧截图，当前测试覆盖）

**用户截图**：`文字与消息框略微有错位.png`（1591×427 局部，时间 2026-11-13 18:39–19:03，早于 T13/Gemini 修复）。

**现状**：

* `m17_text_layer::three_line_balloon_keeps_every_row_on_screen`：三行气球每行在 576 内、行距 22–24 px、框高 ≥79、底边固定。
* `m17_ui_regressions::balloon_face_stays_anchored_when_the_frame_grows`：头像钳位 576。
* `TextQuadKey` 的 `balloon_frame_growth()` 已在 `112ed76` 修复。

**结论**：旧截图不能作为当前版本证据；本轮未重新截取同帧实机图，报告按“已有测试覆盖”处理，待实机复现再调 `message.rs` 内边距。

### 2.7 格子进度条（已找到根因并做基础修复）

**用户参考图**：`格子进度条参考1/2/3.png`、`格子进度条参考_浴室偷窥撸管.png`。

**根因**：CE277 的“警戒度”条不是 `sysgraphic` 的 `<SQUARE>`，而是：

```text
150 [32,500,...] "\c[9]\img[Picture\box01.png]\img[Picture\box01.png]..."
150 [32,501,...] "\c[9]\img[Picture\box02.png]..."
```

`message.rs::styled_items()` 的 `match` 对 `TextToken::Image` 落到 `_ => {}`，整条 `\img` run 被丢弃，所以格子条完全空白。

**修复**：`inline_box_glyph()` 把 `box01.png` 映射为 `□`、`box02.png` 映射为 `■`；仅这两个 CE277 使用的 19×20 单色方块，其他 `\img` 保持原丢弃策略。新增 `the_alertness_meter_box_images_survive_as_box_glyphs`。

**限制**：这解决的是“格子条被整段丢弃”的基础问题；不同事件的格子条可能使用 `item_icon`、`box` 以外的图片，仍需逐事件验证。当前测试 38/38。

### 2.8 夜晚身体部位点击 / 存档、结束、姿势图标（未修复）

**用户描述**：夜晚恶作剧界面除两侧按钮外，鼠标放在妹妹不同部位点击、以及存档/结束/姿势图标都不可点。

**现状**：

* `sister_body_action_event_at()` 已实现白天站姿的 alpha 轮廓点击，但入口条件 `v100 == 0`；夜间 `v100` 通常为 10，身体点击主要依赖地图并行页的 `op124` 鼠标轮询。
* `PICTURE_ACTION_CONTROLS` 已覆盖 `icon06/icon01/icon05/endbutton` 四个固定图标；`pose_iconarea`（slot 1109）和 `pose_icon00..02`（slot 1110/1117）不在列表。
* `handle_action_key_input()` 中有 `messages/choices` 门禁和 `CE14/95/131/132` 门禁；如果夜间还有残留消息/选项，点击会被整段拦截。

**下一步**：在真实夜间存档上跑 `wolf-cli play --load-save ... --debug`，打印 `v100`、`messages.len()`、`choices.is_some()`、`mouse_consumed` 和 `runtime.action_key_at` 命中；先确认是“全局被拦截”还是“只有 pose 图标没有映射”。不要继续凭截图猜。

### 2.9 随机事件结果固定（未修复）

**用户描述**：连续两天偷看洗澡都被发现，且对话完全相同。

**现状**：`savegame::apply()` 有 `game.vm.rng.set_cursor(loaded.playtime_frames as usize)`；`WolfRng` 文档明确“同一存档重放同一点、不同存档不同点”。这是上一轮为修“每次读档都从 0 开始”而做的设计。连续游玩时游标本应前进；如果结果仍固定，可能是偷窥分支根本不使用 `rng` 而用固定条件/固定 `Sys82`，也可能读档路径把游标重置到同一 playtime。

**下一步**：反汇编 CE249 的暴露分支（`pc83-95`、`op111 [1,1600011,1,3]`）与 `9000082` 的来源；确认 `9000082` 是否随机数、`1600011` 如何由 `1600013` 循环递减。确认前不改 RNG，避免破坏确定性回放。

### 2.10 读档后选项停在左上（已关闭）

用户已明确“读档后选项停在左上已解决”，对应 `choice_anchor()` 的 `(0,0)` 回退居中、`install_map()` 清 `choices`、`m16/m17` 回归均已覆盖，不再列为待修。

---

## 3. 本轮代码改动清单

| 文件 | 改动 |
| :--- | :--- |
| `crates/wolf-game/src/game.rs` | `split_action_readout` 前缀校验；`picture_quads`/`text_quads` 对 230 无效读数与窗口皮肤抑制 |
| `crates/wolf-game/src/choice.rs` | `option_label` 返回 `Cow`；`U+FFFD` 仅显示层替换为空格；新增单测 |
| `crates/wolf-game/src/message.rs` | `TextToken::Image/ImageNearest` 的 `box01/box02` → `□/■`；新增单测 |
| `crates/wolf-game/tests/m4_hud_status.rs` | 新增序章 slot 230 旁白回归 |

---

## 4. 验证记录

| 命令 | 结果 |
| :--- | :--- |
| `cargo test -q -p wolf-game --lib message` | **38 passed** |
| `cargo test -q -p wolf-game --test m4_hud_status`（`WOLF_DATA_ROOT`） | **3 passed** |
| `cargo test -q -p wolf-game --test m17_ui_regressions`（`WOLF_DATA_ROOT`） | **21 passed** |
| `cargo test -q --workspace -- --skip font_lookup_prefers_the_games_face_and_scans_unexpected_names` | 除既有 `m3_manual_rules::late_night_bedtime_skips_to_next_evening` 外通过；该失败是长期台账，非本轮引入 |
| `cargo build --profile godot -p wolf-gdext` | 成功，`target/godot/wolf_gdext.dll` 7,707,648 B，SHA-256 **A93C401F2FB48C9F2AF79CFC2F789F1E5B42550767CE0C446FEDB50C99588B8B** |

### 4.1 环境坑（复现）

* `cargo test --workspace` 会在 `wolf-cli` 的 `font_lookup_prefers_the_games_face_and_scans_unexpected_names` 收尾 `std::fs::remove_dir_all` 里挂死（E: 盘 `work/out` 删除返回 os error 145 后纯 CPU 自旋）。本轮已 `TaskStop` 后台任务并确认残留进程退出；全量结果使用 `-- --skip ...` 得到。
* `godot/bin/wolf_gdext.dll` 被正在运行的 Godot 进程占用，本轮构建产物在 `target/godot/`，尚未覆盖到 `godot/bin/`；**用户需要先关闭两个 Godot 窗口**，再替换，否则打开的是 13:19 的旧 DLL（SHA-256 `F988...`）。

---

## 5. 交付物

* 本报告：`docs/ROUND_T12_AND_SCREENSHOT_FIX_REPORT.md`
* 修复包：`work/out/dist/ImoutoLife_fix_bundle_beb9693.zip`（311,685 B，SHA-256 `355914559F03770EBFE0C54258840C66039BA3D34D641E3A4A1B32262D38383E`；云端 `https://aka.doubaocdn.com/s/kGtcbnyM4x`）
* 证据：`work/out/ev0_newgame.tsv`、`work/out/prologue_fixed360.png`、`work/out/all_strings.tsv`、`work/out/name360.png`、`work/out/boot_new_*.png`
* 参考：`docs/HANDOFF_T12_PATCH_AND_LEDGER.md`、`docs/AUDIT_REBUILD_FIX_REPORT.md`、`docs/Full Code Review 1c76dcc.md`

## 6. 提交与推送状态

* 本地提交：`beb9693 fix(ui): close prologue gauge, tea-stall mojibake and box meter`（7 files，+358/−10）。
* 远端：仍为 `47dd4e0`；`git status -sb` 显示 `master...origin/master [ahead 1]`。
* 推送尝试与结果：
  * `git -c http.proxy= -c https.proxy= push origin master` → `schannel: failed to receive handshake, SSL/TLS connection failed`。
  * `http.sslBackend=openssl` → `TLS connect error: error:0A000126:SSL routines::unexpected eof while reading`。
  * 本机代理 `127.0.0.1:7890` 端口可连，但 HTTPS 到 GitHub 仍在 TLS 握手阶段被中断；TCP 到 `140.82.112.4:443` 可建立，TLS 仍失败。**这是本机网络/代理问题，不是提交或仓库问题**。
  * 云主机已克隆仓库并导入 `beb9693` bundle，但该环境没有可用的 GitHub 写凭据，`git push` 返回 `could not read Username`。因此本轮**没有完成远端推送**。
* 网络恢复后执行：
  ```powershell
  git -c http.proxy= -c https.proxy= push origin master
  ```
  预期远端从 `47dd4e0` 前进到 `beb9693`。

## 7. 未完成项与下一步顺序

1. 关闭 Godot → 替换 `godot/bin/wolf_gdext.dll` 为 `A93C...`，重新启动实机确认“空槽消失、茶摊选项无豆腐块、格子条出现”。
2. 定位茶摊左侧物品图标列：`wolf-cli assets --include-maps --coords --filter item_icon`，区分 `\img` 丢弃与字体缺字。
3. 夜间存档上打印 `v100 / messages / choices / mouse_consumed / action_key_at`，先判定全局拦截还是 pose 图标缺少映射。
4. 反汇编 CE249 暴露分支与 `9000082`，确认随机/固定条件后再决定是否改 RNG。
5. 拿零售逐帧录像或 CE270 显隐条件，再决定是否修连续同人第二句名牌。
6. `m3_status_panel::ce238_relative_panel_lands_at_the_left_edge` 独立排查 `picture.rs` 相对绘制。
