# M3 完整运行时 — 交付说明（草稿，随并行任务回填）

本文件记录 M3「完整运行时」的交付范围、测试证据与遗留缺口。M3 的目标是让本作
350 个公共事件与 5 张注册地图都能在 headless 解释器里被真实调度、真实读写变量/图片/
声音，并把玩家可见的日常循环、菜单、存档、设置、夜间互动与结局都钉进回归测试。

配套文档：`docs/HANDOFF_M0.md`（数据/世代/环境）、`docs/M3_EVENT_MAP.md`（CE212..303
冒烟）、`docs/M3_MAP_EVENTS.md`、`docs/M3_STRING_DECODE.md`、`docs/M3_VARDB_BUG.md`、
`docs/M3_ASSET_REFS.md`、`docs/M3_MANUAL_ALIGNMENT.md`（说明书核对）。

## 1. 验收基线（M3 完成条件）

```bash
cd '/e/Study/github program/Imouto Life' && source tools/env.sh >/dev/null 2>&1
cargo test -q --workspace                                   # 默认无数据也必须 exit 0
WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-format       # 全绿
WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --tests --no-fail-fast
WOLF_DATA_ROOT=work/Data ./target/debug/wolf-cli.exe verify  # PASS 64 / 1 SKIP
WOLF_DATA_ROOT=work/Data ./target/debug/wolf-cli.exe verify --wolf <安装目录>/Data.wolf
                                                            # PASS 72 / 0 pending
```

## 2. 测试矩阵（本作数据，`work/Data`）

| 文件 | 用例 | 覆盖 |
| --- | ---: | --- |
| `wolf-format/tests/m3_asset_refs.rs` | 2 | 全数据资产引用扫描（图片/音频缺失清单） |
| `wolf-format/tests/m3_string_decode.rs` | 4（1 ignored） | 全容器字符串解码审计、CE250/CE257 源数据损坏定性 |
| `wolf-format/tests/m3_event_graph.rs` | 1 | op210/211/300 动态目标与事件图勘察 |
| `wolf-game/tests/m3_week_loop.rs` | 6 | 读档 HUD、CE245 六项、就寝→翌朝→日菜单、3 日推进、周末切换 |
| `wolf-game/tests/m3_week7.rs` | 2 | 7 日循环/周末路径 |
| `wolf-game/tests/m3_night_actions.rs` | 15 | CE245/246/247/248/249/250/251 与购买/余额/确认分支 |
| `wolf-game/tests/m3_night_interaction.rs` | 6 | 夜间互动界面入口/前置条件/状态栏 |
| `wolf-game/tests/m3_ui_screens.rs` | 13 | CE237/238/239/240/241/242/243/244/296/297/301/302/303 |
| `wolf-game/tests/m3_visual_text.rs` | 7 | 消息窗口、文字特效、气泡、换行 |
| `wolf-game/tests/m3_audio_settings.rs` | 4 | BGM/SE 资产与 System.sav 音量子结构 |
| `wolf-game/tests/m3_settings_persist.rs` | 10 | CE132 设置界面与 System.sav 持久化契约 |
| `wolf-game/tests/m3_save_load.rs` | 9 | 两个官方存档的严格读写、220/222、vardb 往返 |
| `wolf-game/tests/m3_save_robustness.rs` | 4（1 ignored） | 损坏/缺失存档的健壮性 |
| `wolf-game/tests/m3_save_ui_roundtrip.rs` | 1 | 存档 UI 端到端 |
| `wolf-game/tests/m3_vardb_cdata_roundtrip.rs` | 3 | 新游戏存档 vardb（M3-VARDB 修复后） |
| `wolf-game/tests/m3_menu_screens.rs` | 3 | CE131/CE132 菜单绘制/取消/不落盘 |
| `wolf-game/tests/m3_event_smoke.rs` | 1 | CE212..303（92 个）逐一冒烟 |
| `wolf-game/tests/m3_map_events.rs` | 4 | 5 注册地图尺寸/事件/页、SampleMapA 冒烟、新游戏传送 |
| `wolf-game/tests/m3_hud_layout.rs` | 3 | 顶栏槽位/DB 绑定/字体度量 |
| `wolf-game/tests/m3_hud_buttons.rs` | 1 | 保存/数据按钮命中 |
| `wolf-game/tests/m3_status_panel.rs` | 5 | CE242/238 状态面板与数字 DB 渲染 |
| `wolf-game/tests/m3_stats_collection.rs` | 4 | ev30 统计、ev31/CE303 收集品 |
| `wolf-game/tests/m3_manual_rules.rs` | 8 | 说明书规则：行动力消耗/洗澡/就寝/星期/结局阈值 |
| `wolf-game/tests/m3_title_mouse.rs` | 7 | 标题菜单鼠标命中/左键选单 |
| `wolf-game/tests/m3_title_visibility.rs` | 3 | Sys3/4=-1000 的标题锚点、读档界面取消回退 |
| `wolf-game/tests/m3_mouse_menu.rs` | 8 | choice 行命中、左键进各夜间菜单、右键取消、悬停 |
| `wolf-game/tests/m3_newgame_persistence.rs` | 2 | 新游戏→Map003→SampleMapA 初始状态/存档持久化 |
| `wolf-game/tests/m3_endings.rs` | 6 | 结局/100 日/怀孕/内裤完成调度点 |
| `wolf-game/tests/m3_night_interaction_e2e.rs` | 6 | 夜间互动端到端（GOOD/BAD、页状态机、摸头/深睡、120% 强制射精、结束脚本） |
| `wolf-game/tests/m3_save_text_fidelity.rs` | 4 | 存档文本图 payload 保真（未修改逐字节） |
| `wolf-game/tests/m3_perf_baseline.rs` | 1 | headless 性能基线（5 场景，非门限） |
| `wolf-game/tests/m3_map_click.rs` | 8 | 地图 ActionKey(trigger 0) 点击激活（保存/状态/结束/空点/右键/消息占用） |
| `wolf-game/tests/m3_save_byte_fidelity.rs` | 4 | 官方存档 load→save 逐字节相等 |
| `wolf-audio/tests/mixer_contract.rs` | 15 | 音量/循环/淡出/SE 混音/重采样/null 后端 |

> 说明：以上文件全部以 `WOLF_DATA_ROOT=work/Data` 为真值；缺数据时打印 skip 并
> return，保持默认 `cargo test --workspace` exit 0。

## 3. 本轮引擎改动（工作树）

1. **零售 PRNG**：`wolf-vm/src/rng.rs` 从 xorshift 占位改为可复现零售序列（详见
   `docs/research/M7_PRNG.md`）。随机驱动数值（工资/金钱/概率）因此变化，测试禁止
   pin 具体随机值。
2. **存档变量应用**：`savegame.rs::apply` 现在保留 `base_save` 模板、按 `part3`
   行跨度逐行恢复普通变量（不再把后续行溢进 0..800），并修 vars302..336 污染。
3. **GBK 文本**：`wolf-format/src/gbk.rs` 增加 `encode`；存档文本图 decode/encode
   与图片文件名改走 GBK；`decode_wolf_str` 的 UTF-8→CP932/GBK 启发式保持不变。
4. **DB 行名列**：`250 DatabaseAccess` 支持列 -3（行编辑名，CE265/CE267）。
5. **数字单元格渲染**：`textpic::Cells::{cdb,udb}` 在字符串单元缺失时回退数字，
   修复 CE242 行动力/精力数字不显示。
6. **鼠标契约**：右键 = 取消 choice；指针移动时悬停跟随，停住时不抢键盘导航。
7. **290 特效诊断**：所有本作出现过的 kind 都已实现；剩余诊断明确区分「无活动图片
   （真实 no-op）」与「未建模」。
8. **新游戏 vardb**：`Game::new` / `save_to` 从静态 CDataBase 结构补全空模板，
   新游戏存档不再丢失全部 CData 单元格（`docs/M3_VARDB_BUG.md`）。
9. **F12 重启**：`wolf-cli play` 支持 F12 重新 boot（F10 仍为退出）。

## 4. 已知缺口 / M4 承接

- Config.exe 等价设置界面：Game 设置 API 已提供读写/应用/持久化；窗口内设置界面
  与音量滑条 UI 留给 M4（见 docs/M4_PARITY.md）。
- headless capture 已可用（wgpu 离屏初始化稳定，有超时保护）。字体发现已改为优先
  本作 `07やさしさゴシックボールド.ttf`（并可回退扫描 *.ttf/*.otf/*.ttc）；
  `capture --map` 黑屏根因是 SampleMapA ev0 开场把 `cg/blackscreen.jpg` 铺满屏，
  已在 CLI 侧停掉一次性 autorun 页（保留 parallel 页），SampleMapA 由 0% 提升到
  92.8% 非黑。像素级对照可自动化。
- 存档文本图逐字节保真已完成（未修改的文本图 70/70 字节相等）；vardb 字符串
  编码（UTF-8 vs 零售 GBK/CP932）留 M4 专项。
- `v8` 语义：脚本中由 CE243（周五/周六写 25）、CE245（±1/2）与 CE251（读 23/24）
  共同使用，不是行动力；命名待专项审计（HANDOFF §3.7 的「就寝時間」暂保留问号）。
- 胜利/结局的完整 100 日链与妊娠判定：以阈值分支测试覆盖，完整长链不逐日模拟。
- CE250/CE257 的源数据坏字节（奇数 0xA1）不伪造修复，保持 allowlist 记录。
- 地图 ActionKey（trigger 0）页的点击激活层已补齐：`MapRuntime::action_key_at` 按
  事件 tile+collision 命中（最小面积优先、跳过运行中的页），Game 在无消息/无 choice
  时把新左键或悬停处的 OK 路由过去；ev5 保存、ev10 状态、ev21 结束已端到端验证。

## 5. 本轮并行任务结果（回填）

- **音频契约**：`crates/wolf-audio/tests/mixer_contract.rs` 新增 15 条离线测试；修掉
  一个真实 bug——one-shot SE 结束后在本次回调剩余帧里仍输出最后一个采样（DC 尾巴）。
- **存档文本图保真**：`Picture` 保留原始 `md1`（`retained_text`），未改写的文本图
  `save_to` 时逐字节写回；SaveData01/02 的 70 个文本图差异从 5 降到 0。改写过的图
  仍走规范编码（显示等价、字节可能规范化的已知边界）。
- **新游戏 vardb**：`Databases::seed_vardb` 从静态 CDataBase 补全模板（30 类/1052
  配置）；新游戏存档 missing=0/mismatch=0。静态 CDataBase 本身是 649 行（官方存档
  650 行是运行时追加一行），测试按 649 断言并记录原因。
- **夜间互动端到端**：`m3_night_interaction_e2e.rs` 4 条：界面构成（GOOD/BAD
  1992..2000、20 格道具 2300..2319、按钮 400/404/401、结束按钮 1108）、
  页状态机 1→3→10→1、摸头（1100）与深睡拒绝（1101）的 cut-in/睡眠深度差异、
  BAD 条与 v59 的 `v64*100/18` 公式。射精感 100/120% 与结束按钮点击路径仍未
  端到端覆盖（记录的缺口）。
- **离屏渲染**：wgpu 离屏初始化在本机已可用（GPU0 高负载下仍成功）；旧「卡死」
  更像驱动/适配器枚举的瞬时停顿。现改为有界执行器：`WOLF_RENDER_TIMEOUT_MS`
  （默认 30 s）→ `RenderError::InitTimeout`，回读用带超时的 `PollType::Wait`；
  新增 `WOLF_RENDER_BACKEND`/`WOLF_RENDER_ADAPTER` 覆盖。7 条离屏渲染+回读测试
  约 3 s 通过。
- **F12**：`play.rs` 新按下沿触发重建 Game 并 boot；单测覆盖键位判定。
- **性能**：`m3_perf_baseline` 五场景 + 引擎地板（docs/M4_PERF.md）。Lead 已落地
  优化候选 1（`Assets` 记住内置 `<SHAPE>`/未命中名字，不再每帧走大小写目录扫描）：
  夜间互动 UI 从 0.525 降到 0.163 ms/帧（约 3.2x），picture_quads 0.328→0.026 ms。
- **字体/地图截图**：`find_font` 原来只认姊妹作字体名，本作字体被跳过（截图无文字）。
  现已优先解析 Game.dat 的字体名并加载系统 `Microsoft YaHei`（msyhbd.ttc），
  回退到 `07やさしさゴシックボールド.ttf` 与任意 ttf/otf/ttc；`capture --map`
  黑屏已修（停一次性 autorun 页），六张对照图在 work/out/shots。

> 已回填：PRNG 表驱动结论与 Game.dat 接线、设置 API、结局/夜间互动、存档编码。

## 6. 存档字节兼容（vardb 编码）

- 官方 SaveData01/02 的 vardb 字符串是 **CP932（模板）+ GBK（汉化/脚本文本）混排**，
  没有 UTF-8 单元格（1589 个文本 cell：1521 空、23 ASCII、45 非 ASCII）。
- `VariableDatabase::set_text` 现在：未修改的 cell 保留原字节；新写/改写的非 ASCII
  文本按 GBK 编码，GBK 无法往返时回退 UTF-8。`set_string` 保持逐字节。
- `Game::load_save → save_to`：vardb 段 0 字节差异、44 个非 ASCII cell 不再被重编码；
  整个存档文件大小不变（SaveData01 293,742 B / SaveData02 294,130 B）。
- 残余已清零：SavePart5（图片记录）改为保留原始记录的数字字段（vars7_18/vars19_36/
  vars55_60/vars61_63），`Game::new → load_save → save_to` 现在与官方存档**逐字节
  完全相等**（SaveData01 293,742 B、SaveData02 294,130 B，含 header checksum），
  第二次 load→save 也稳定；改写过的图片回退到规范记录。测试
  `m3_save_byte_fidelity.rs`（4 条）。
- `db.rs::apply_saved_database` 已改用 `decode_wolf_str` 读取 vardb 文本（此前
  `from_utf8_lossy` 会把新写的中文读成乱码）。
