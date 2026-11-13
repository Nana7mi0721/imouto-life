# 《妹！生活 ～単色～》重构修复报告（T12 收口 + 审计轮）

> 日期：2026-11-13  
> 工作区：`E:\Study\github program\Imouto Life`，代码提交 `b2b6998`（已 push `origin/master`；文档补记见后续提交）
> 依据：`docs/HANDOFF_T12_PATCH_AND_LEDGER.md`、`docs/imouto_life_rebuild_fixes_and_full_audit.md`

---

## 0. 结论

两轮工作均已完成并验证：

1. **T12 补丁收口轮**：m14 从 2 红恢复 **5 passed**，像素基线 `533187 / 554890` 一位未改；停靠侧栏按零售 `0.2` alpha 复原；`wolf-gdext::frame()` 去掉选项数组二次 clone。
2. **审计修复轮**：`imouto_life_rebuild_fixes_and_full_audit.md` §一 6 条实机截图问题中，选项错位/乱码/残留、行动力条误显示与样式、`36002` 头像裁切 5 条已修复；§一.6 经原版零售截图核对，`message` 名牌是零售可见行为，未按占位符隐藏；“连续同人第二框无名牌”未获得零售反证，留给逐帧证据。§二 4 条漏洞/性能项落地 3 条 + 1 条（字体双读）判定为一次性启动成本不处理；2 条已由 T12 完成的性能项在报告中标注闭环。

全量 Rust 测试只余长期既有的 `m3_manual_rules::late_night_bedtime_skips_to_next_evening`（04:30 就寝期望 19:00，实测 17:00）；Godot headless 冒烟 9 个脚本全绿。

---

## 1. T12 补丁收口轮

### 1.1 m14 两处红的归因

两处红来自 T18 `1a9fafe` 的行为变化，不是 T12 补丁：

| 场景 | 现象 | 根因 |
| :--- | :--- | :--- |
| day_command / hud | text picture / item / line 各 +1，glyph 数不变 | `Game::build_text_picture` 对 slot 230 的 `\f[14]行动力60/65` 调 `split_action_readout`，拆成 label@560 与 value@668 两个 run，给宿主进度条留空 |
| day_command | nonblack −1789（533187→531398） | T18 把 `Game::hover` 对 320/2300 改成恒返回 1，地图 ev8/ev11 不再每帧调 CE238/239 的 hide 页，停靠侧栏不再走“每次重画重置 10 帧淡入、age 停在 2”的路径，alpha 从零售 `255×2/10=0.2` 变成 1.0 |
| hud | nonblack −2152（554890→552738） | 同上 |

用 detached worktree `ee808fe` + 独立 `--target-dir` 复验：旧版输出 `533187/23/22` 与 `554890/14/13`，证明存档 fixture、字体、环境均未漂移。

### 1.2 修复

- `crates/wolf-game/src/game.rs`：
  - 新增 `SIDE_PANEL_PARKED_ALPHA = 0.2`、`SIDE_PANEL_PARKED_X = -300`；
  - `picture_quads` 对已停靠（`x ≤ -300` 且 `transition.is_none()`）的 320/2300 乘 0.2，开合滑动仍 1.0。
- `crates/wolf-cli/tests/m14_visual_regression.rs`：只重钉 day_command/hud 的 `text_pictures` / `text_items` / `text_lines`（23→24、22→23、22→23；14→15、13→14、13→14），`nonblack` 不动。
- `crates/wolf-gdext/src/lib.rs`：`frame()` 不再双 clone `choice_options`，直接借用 `game.choices`，`overlay_at_sized` 传 `game.choice_cursor()`。
- `crates/wolf-game/src/assets.rs`：`alpha_bounds_cache` 二级键 + `clear()` 同步清空 + `alpha_bounds_in()`（T12 已完成）。

### 1.3 验证

- `m14_visual_regression` **5 passed**：day_command `533187 / 50 live / 23 quads / 24 text pics / 23 items / 76 glyphs / 23 lines`；hud `554890 / 50 live / 5 quads / 15 text pics / 14 items / 44 glyphs / 14 lines`。
- `m16` 4、`m17_ui_regressions` 21、`m18` 6 全过。
- `cargo fmt --all -- --check` exit 0，`cargo check -p wolf-gdext` exit 0。
- 视觉证据：`work/out/m14_ab/leftedge_new_vs_old.png`（左缘 70 px 三倍放大，新图与旧基线一致，淡灰把手复原）。

---

## 2. 审计修复轮

### 2.1 §一 实机截图问题

#### ① 选项位置错乱（左上角 `(0,0)`）

- **修复**：`crates/wolf-game/src/choice.rs::layout_at_sized` 把 `x == 0 && y == 0` 与屏外锚点同等处理，回退到居中布局；真实屏内非零锚点不变。
- **测试**：新增 `a_zero_anchor_falls_back_to_the_centred_default`，断言 3 行选项面板中心为 `(512, 288)`。

#### ② 选项文字 `♦ 2000` 乱码

- **修复**：`Game::show_choices` 在翻译后调用 `wolf_format::messagetext::strip` 剥离 `\c[...]` / `\f[...]` / 图标控制码；保留原始空白，避免无意义地改动既有文本度量；空标签仍被跳过并保留 `sources` 索引。
- **说明**：`♦` 是控制码在缺少图标字体时留下的缺字占位，剥离后不再绘制；选项面板宽度随可见文本重算。

#### ③ 强制射精后选项框残留

- **修复（两处）**：
  1. `Game::frame` 在 VM 推进与存档/地图请求处理之后，检查 `self.vm.instances()` 是否仍有 `WaitState::Choice` 或 `WaitState::MessageWithChoices`；没有则清空 `self.choices` 并归零 `choice_cursor`。
  2. `Game::install_map` 清空遗留 `choices`（仅当确实有打开的选项时才重置光标，避免覆盖调用方预设的起始行）。
- **测试**：`m3_mouse_menu` 新增 `a_choice_prompt_is_dropped_when_its_waiter_disappears`：打开夜间五选项菜单 → 直接 `stop_instance` 掉 Choice 等待者 → `frame()` 后断言 `choices.is_none()`。该套件 **14 passed**。

#### ④ 黑屏开场误显示行动力条 + 进度条样式

- **误显示修复**：`Game::hud_action_points` 增加 `hud.kind.is_text()` 与 `split_action_readout(&hud.text).is_some()` 校验；slot 230 只有确实是 `行动力 current/max` 文本时才出条，黑屏开场“一个月前——”不再孤立绘制。
- **样式修复**：
  - Rust 布局：`HUD_ACTION_VALUE_X 668 → 716`，`HUD_ACTION_BAR [608,20,54,8] → [608,18,100,12]`（参考图实测条体 148×13，本作受 `精力` 槽位 x=760 限制取 100×12）。
  - Godot：`GameView.gd` 两处 `_draw_action_points`（内层 `_BlendBatch` 与主类）改为深灰槽体 + 1 px 亮灰边框 + 1 px 内缩柔和灰白填充，替换原来的 2 px 内缩纯白块。
- **验证**：m14 文本计数与像素基线不变（只挪动 value run，字形数量和顶栏底色不变）；`smoke.gd` 的 `action_points_normal_batch=ok` 通过。

#### ⑤ `36002` 头像底部裁切

- **修复**：`Game::picture_quads` 在气球消息激活时，对 `BALLOON_FACE_PICTURE = 36002` 做底边钳位：`y = min(y, SCREEN_H - h)`，只改渲染矩形，不写回脚本 Picture。
- **测试**：`m17_ui_regressions.rs` 原来把“底边超出气球 38 px、到 604”写成正向断言，现改为断言底边等于 `SCREEN_H (576)`；三行气球仍断言头像不随框体高度移动。**21 passed**。

#### ⑥ 连续同人对话人名框消失 / 首框 `"message"`

- **核对结论（不改代码）**：`work/out/shot_metrics/full_89EF.png` 是从 `prt sc/` 的
  1532×862 零售窗口截图缩放得到的原版实机图，其名牌就是字面量 `message`。也就是说
  “首框显示 `message`”是零售行为，不是本重构独有缺陷；`TASKS_REMAINING_BUGS.md`
  第 103–105 行与 `HANDOFF_M0.md` 的既有约束都要求“确认说话人规则前不要擅自隐藏”。
  因此 `balloon_nameplate_active` 保持只判空，不按 `"message"` 特判。
- **连续同人第二框无名牌**：用户截图 `当前后连续两个对话都来自同一人时，后面对话的人民框消失.png`
  是一句温泉旁白/内心独白（“这里是温泉旅馆……”），零售的旁白图
  `prt sc/白天_过场（社会人）.png` 也没有名牌，因此“该句本就无人名牌”有旁证；但同一人
  翻页瞬间是否应短暂保留上一名牌，仍缺逐帧证据，未加 latch。
- **待办**：若要进一步区分“占位符 `message`”与真实人名，需要原版脚本在不同说话人下的
  名牌槽位录像，或逆向 CE270 的 name 写入分支；本轮不做猜测性修改。

#### ⑦ 其他截图

- `文字与消息框略微有错位.png`：T13 已修气球正文；夜间横幅 1–2 px 偏移未再改动（缺少稳定的原版量测基准）。
- `其他问题.txt` #1（随机事件连续两天相同）：由 §二.1 RNG 游标处理。
- `其他问题.txt` #2（恶作剧部位点击）：由 §一.③ 残留选项清理处理，T14 已修存档/结束按钮。

### 2.2 §二 漏洞与性能项

| 项 | 状态 | 落地内容 |
| :--- | :--- | :--- |
| P1 `WolfRng::cursor` 读档归零 | 已做 | `WolfRng::set_cursor` + `savegame::apply` 在恢复 playtime 后 `set_cursor(playtime_frames)`；同一存档重放位置稳定，不同存档序列不同；不扩展 `.sav` 布局 |
| P1 `install_map` 未清 `MAP_SELF_BASE` / `choices` | 已做 | `MAP_SELF_BASE` 清扫由 T12 完成（`m16` 4 passed / 0 ignored）；本轮补 `choices` 清理 |
| P2 `audio_cache` 只增不减 | 已做 | `GameView.gd` 增加 `AUDIO_CACHE_LIMIT = 64` + 插入序淘汰；正在被 BGM/BGS/SE 播放器引用的流不淘汰 |
| P2 每帧 `wolf.key_config()` FFI 分配 | 已做 | `wolf-gdext` 新增 `key_config_revision()`（六字的 FNV-1a 指纹）；`GameView._key_bits` 仅在 revision 变化时重建数组 |
| P1 `picture_ink_rect_in` 每帧全图扫描 | T12 已做 | `Assets::alpha_bounds_in` 二级键哈希缓存 |
| P1 `WolfText` 每帧重建 `TextParagraph` | 已做 | `WolfText.gd` 新增 256 项 `(face,px,width,text)` 缓存，`draw_text` 复用已塑形段落；headless 重绘探针通过（临时脚本已删除） |
| P2 `frame()` 选项双 clone | T12 已做 | 直接借用 `game.choices` |
| P2 启动期字体双读（16.9 MB） | 不处理 | 一次性约百毫秒级冷启动成本；共享字体字节需要改 gdext 与 GDScript 两端的生命周期，收益低、风险高 |

### 2.3 RNG 说明与边界

- 新游戏仍从表头 `0` 开始；读档按 `playtime_frames` 取模定位。
- **已知局限**：同一个存档重复读取仍会得到同一条序列（`.sav` 没有游标字段，也不宜为此改存档布局）。要彻底打散需要扩展存档元数据或确认零售 `Sys110` 的真实语义；本轮按审计报告给出的“playtime 派生”方案执行，并在 `rng.rs` / `savegame.rs` 注释中写明。

---

## 3. 改动文件

| 文件 | 轮次 | 内容 |
| :--- | :--- | :--- |
| `crates/wolf-game/src/choice.rs` | 审计 | `(0,0)` 锚点回退居中 + 单测 |
| `crates/wolf-game/src/game.rs` | T12 + 审计 | 侧栏 alpha、`install_map` 清扫与选项清理、帧末失活选项回收、HUD 文本校验与新条位、`36002` 钳位、选项控制码剥离（`message` 名牌核对后保持原样） |
| `crates/wolf-game/src/savegame.rs` | 审计 | 读档后按 playtime 设置 RNG 游标 |
| `crates/wolf-vm/src/rng.rs` | 审计 | `set_cursor` + 单测 |
| `crates/wolf-game/src/assets.rs` | T12 | alpha bounds 缓存 |
| `crates/wolf-gdext/src/lib.rs` | T12 + 审计 | 去选项双 clone、`key_config_revision` |
| `crates/wolf-cli/tests/m14_visual_regression.rs` | T12 | 文本计数重钉 |
| `crates/wolf-game/tests/m17_ui_regressions.rs` | 审计 | 头像底边断言反转 |
| `crates/wolf-game/tests/m3_mouse_menu.rs` | 审计 | 失活选项回收回归 |
| `godot/scripts/GameView.gd` | 审计 | 行动力条样式、音频缓存上限、键位缓存 |
| `godot/scripts/WolfText.gd` | 审计 | `TextParagraph` 缓存 |
| `docs/HANDOFF_T12_PATCH_AND_LEDGER.md` | T12 | 归因、修复与验证台账 |
| `docs/HANDOFF_PROGRESS.md` / `docs/HANDOFF_M0.md` | 两轮 | 进度与当前状态 |

---

## 4. 验证记录

### 4.1 Rust

```powershell
cargo fmt --all -- --check                                  # exit 0
cargo check -q -p wolf-game -p wolf-gdext                   # exit 0
$env:WOLF_DATA_ROOT='E:\Study\github program\Imouto Life\work\Data'
cargo test -q -p wolf-cli --test m14_visual_regression      # 5 passed
cargo test -q -p wolf-game --test m16_old_bug_review        # 4 passed
cargo test -q -p wolf-game --test m17_ui_regressions        # 21 passed
cargo test -q -p wolf-game --test m18_t18_regressions       # 6 passed
cargo test -q -p wolf-game --test m1_title_load             # 4 passed
cargo test -q -p wolf-game --test m3_mouse_menu             # 14 passed
cargo test -q --workspace -- --skip font_lookup_prefers_the_games_face_and_scans_unexpected_names
```

- m14 最终数值：day_command `533187 / 24 text pics / 23 items / 76 glyphs / 23 lines`；hud `554890 / 15 / 14 / 44 / 14`。
- workspace 全量仅 `m3_manual_rules::late_night_bedtime_skips_to_next_evening` 失败（04:30 就寝期望次日 19:00，实测 17:00），与 T12 前一致，属既有口径差，不是本轮回归。

### 4.2 Godot

```powershell
cargo build -q -p wolf-gdext --profile godot
Copy-Item target\godot\wolf_gdext.dll godot\bin\wolf_gdext.dll -Force
Godot_v4.7.2-stable_win64.exe --headless --path godot --script res://tests/<each>.gd -- ...
```

依次通过：`smoke`（`pictures=4 sprites=4`、`action_points_normal_batch=ok`）、`mouse_title`（到达 `map003`）、`key_map`（98 checks / 0 failures）、`mouse_latch`、`title_wheel`、`gameview_title_wheel`、`load_save`（`pictures=50 texts=15`）、`load_menu`、`save_roundtrip`（save→load 38/38）。另有一次性 `text_cache_probe` 验证 `TextParagraph` 缓存重复绘制无异常，脚本已删除。

### 4.3 环境坑（已实证）

1. **console 包装器不可用**：`Godot_v4.7.2-stable_win64_console.exe`（198 KB stub）启动报 `CreateProcess failed, error 193`；必须把 `GODOT_BIN` 指向 180 MB 的主 exe。
2. **`work/out` 下 `std::fs::remove_dir_all` 自旋**：os error 145「目录不是空的」时纯 CPU 重试，导致 `font_lookup_prefers_the_games_face_and_scans_unexpected_names` 收尾清理挂死；workspace 全量用 `-- --skip` 跑过，PowerShell 手动删同目录瞬时完成。
3. **共享 `target` 污染 A/B**：两个 worktree 共用 `target` 会让 cargo 复用对方产物，旧基线必须给独立 `--target-dir`。
4. 本机 agent shell 无 `git` / `bash`，Godot 冒烟脚本按 `tools/smoke-godot.sh` 的步骤逐条用 PowerShell 复现；未改动 `work/Data`（误写的 `godot_roundtrip.sav` 已删除）。

---

## 5. 未处理项与后续建议

1. **`message` 名牌与连续同人第二框**：原版零售实机图 `full_89EF.png` 同样显示 `message`，按零售结果保留；第二框截图是旁白（零售旁白图同样没有名牌），但同人翻页瞬间是否有一帧闪烁仍需原版逐帧录像，确认前不加 latch。
2. **RNG 同存档重放仍相同**：如需真正打散，需扩展存档元数据保存 `cursor`，或逆向确认 `Sys110` 的零售语义。
3. **启动字体双读**：一次性成本，暂不处理。
4. **夜间横幅 1–2 px 偏移**：缺少稳定量测基准，未改 `message.rs` 内边距。
5. **行动力条视觉**：宿主条为 100×12 的深灰槽 + 亮边 + 柔和填充，目前只有代码审查与 `smoke.gd` 的 `action_points_normal_batch=ok` 支撑；`--headless --capture` 启动后不退出，已 `TaskStop`，未产出 Godot 侧条体截图，仍需实机看一眼。若后续拿到 1024×576 原版顶栏完整截图，可再按真实比例微调宽度与 x。

---

## 6. 清理与备注

- 已删除临时草稿 `work/out/audit_round_notes.md`、跑分脚本 `work/out/bar_measure.py` 与 `target/debug/incremental`；`work/out/m14_visual/`、`work/out/m14_ab/` 保留作证据。
- 清理后仓库合计 **7.99 GiB**（work 1.07 GiB / target 6.64 GiB / work/out 0.90 GiB，其中 `work/Data` 0.17 GiB）。
- 已 commit `b2b6998` 并 push 到 `origin/master`（2026-11-13）；提交身份 `imoto lead <lead@imoto.local>`。
- 交付包：`work/out/dist/ImoutoLife_fix_bundle_b2b6998_2026-11-13.zip`（22 个改动文件 + `FIX_MANIFEST.md`）。
- 证据目录：`work/out/m14_visual/`（五个场景 PNG+LOG）、`work/out/m14_ab/`（A/B 对比与左缘放大图）。
