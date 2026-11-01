# 文档索引（docs/README.md）

本文件是《妹！生活 ～単色～》Rust 重写的**唯一文档地图**。按用途分组：先看「交接」，再按里程碑查专题，调研资料只作背景。

## 1. 交接与工程约定（先读）

| 文件 | 状态 | 内容 |
|---|---|---|
| [HANDOFF_M0.md](HANDOFF_M0.md) | 现行 | 新会话交接：已实测数据事实、世代差异、M0 清单、陷阱、§11 全部进度（最新状态以此为准） |
| [../AGENTS.md](../AGENTS.md) | 现行 | 每个 agent 开工必读：并行/写作用域、环境、数据、测试、提交、清理、内容安全 |
| [../README.md](../README.md) | 现行 | 仓库总览、快速开始、目录结构 |

## 2. 基线

| 文件 | 状态 | 内容 |
|---|---|---|
| [BASELINE.json](BASELINE.json) | 现行 | 本作自己的 `wolf-cli verify` 期望值（25 个 Game.dat 参数、350 公共事件、地图事件、tileset 版本、文件版本、1,361 条 archive） |
| [REFERENCE.md](REFERENCE.md) | 现行 | 日文原版路径、攻略链接、10 张实机截图目录、存档样本 |

## 3. 里程碑总览

| 文件 | 状态 | 内容 |
|---|---|---|
| [M2_SLICE.md](M2_SLICE.md) | 已完成 | M2 日常循环切片：CE245/CE251/CE242/CE243/CE244/CE256 实测、鼠标→键码契约、验收 |
| [M3_RUNTIME.md](M3_RUNTIME.md) | 已完成 | M3 完整运行时交付：测试基架、引擎修复、存档/字符串/音频、遗留缺口 |
| [M4_PARITY.md](M4_PARITY.md) | 已完成 | M4 对等打磨工作分解（玩家可感知层：UI、音频、存档互通、性能） |
| [M4_HUD.md](M4_HUD.md) | 已完成 | M4 HUD/读档数值与负号图片保真修复：四个玩家可见缺陷的根因与回归 |
| [M4_SETTINGS_UI.md](M4_SETTINGS_UI.md) | 已完成 | CE132/CE95 设置界面排版修复：字号、290 位移、1/10 字符格、CursorBase |
| [M4_PERF.md](M4_PERF.md) | 已完成/基线 | M4 headless 性能基线与优化候选（tile quad 缓存已落地） |
| [M4_V8_AUDIT.md](M4_V8_AUDIT.md) | 已完成 | 普通变量 v8 语义专项：夜间可活动上限 23..26，不是行动力 |
| [M5_BEYOND.md](M5_BEYOND.md) | 进行中 | M5 超越原版：M5-A 高分辨率/缩放/全屏、M5-B F3 调试 overlay、M5-C F2 统计/里程碑 overlay、M5-D TSV 内容翻译目录、M5-E --mod 数据/音频覆盖层、M5-F F4 消息回顾已落地 |
| [PACKAGING.md](PACKAGING.md) | 已完成 | 发布打包：`work/out/dist/<version>/` 的 exe、README、启动器、校验和 |

## 4. M3 专题审计（按主题）

| 文件 | 主题 | 对应测试 |
|---|---|---|
| [M3_EVENT_MAP.md](M3_EVENT_MAP.md) | 自有公共事件 CE212..303 共 92 个的冒烟与事件地图 | `crates/wolf-game/tests/m3_event_smoke.rs` |
| [M3_EVENT_GRAPH.md](M3_EVENT_GRAPH.md) | 公共事件调用图与可达性静态审计 | `crates/wolf-format/tests/m3_event_graph.rs` |
| [M3_EVENT_INPUTS.md](M3_EVENT_INPUTS.md) | 自有事件在真实按键注入下的可达性 | `crates/wolf-game/tests/m3_event_inputs.rs` |
| [M3_MAP_EVENTS.md](M3_MAP_EVENTS.md) | 5 张注册地图属性 + SampleMapA 35 事件冒烟 | `crates/wolf-game/tests/m3_map_events.rs` |
| [M3_MANUAL_ALIGNMENT.md](M3_MANUAL_ALIGNMENT.md) | 官方说明书 manual01..06 与实现的逐条核对 | — |
| [M3_ASSET_REFS.md](M3_ASSET_REFS.md) | 事件脚本图片/音频引用完整性静态扫描 | `crates/wolf-format/tests/m3_asset_refs.rs` |
| [M3_STRING_DECODE.md](M3_STRING_DECODE.md) | 汉化数据 CP932/GBK 混排解码审计与回归 | `crates/wolf-format/tests/m3_string_decode.rs` |
| [M3_VARDB_BUG.md](M3_VARDB_BUG.md) | 新游戏存档丢失 CDataBase 可变数据库（已修复） | `m3_vardb_cdata_roundtrip` |
| [M3_TITLE_UX.md](M3_TITLE_UX.md) | 标题菜单可见性与“取消读档返回标题”链 | 标题/读档测试 |
| [M3_ENDINGS.md](M3_ENDINGS.md) | 结局条件、变量写入者与事件链 | `m3_endings` |

## 5. 调研资料（历史背景，不是当前事实源）

> 6 份 GPT 深度调研报告完成于 M0 之前，其中若干结论已被本作数据实测推翻。
> **采信/推翻清单以 [HANDOFF_M0.md](HANDOFF_M0.md) §7 为准**；报告只作背景与线索。

| 文件 | 说明 |
|---|---|
| [GPT_RESEARCH_GROUPS.md](GPT_RESEARCH_GROUPS.md) | 给 GPT 的 6 个调研问题组（报告的前置 prompt） |
| [deep-research-report.md](deep-research-report.md) | 游戏信息、WOLF 版本、基础资料 |
| [deep-research-report (1).md](deep-research-report%20%281%29.md) | 引擎/版本与开发背景 |
| [deep-research-report (2).md](deep-research-report%20%282%29.md) | 场景与触发条件 |
| [deep-research-report (3).md](deep-research-report%20%283%29.md) | 操作方式与系统 |
| [deep-research-report (4).md](deep-research-report%20%284%29.md) | 机制考证（身份、属性、经济） |
| [deep-research-report (5).md](deep-research-report%20%285%29.md) | 状态面板字段与 UI 描述 |
| [research/M7_PRNG.md](research/M7_PRNG.md) | PRNG 实证：Game.dat static-random 是预生成表，不是种子（M3 已落地） |
| [相关链接.txt](相关链接.txt) | 外部链接汇总（gitignore，不提交） |

## 6. 代码与测试定位

- 上一作代码地图、引擎模块对应关系：见 [HANDOFF_M0.md](HANDOFF_M0.md) §6。
- 代码级测试入口：`crates/*/tests/`；数据用例只在 `WOLF_DATA_ROOT=work/Data` 下真跑。
- 文档生成的测试（改代码后应重跑并更新对应文档）：
  - M3_EVENT_MAP ← `m3_event_smoke`
  - M3_EVENT_GRAPH ← `m3_event_graph`
  - M3_EVENT_INPUTS ← `m3_event_inputs`
  - M3_MAP_EVENTS ← `m3_map_events`
  - M3_ASSET_REFS ← `m3_asset_refs`
  - M3_STRING_DECODE ← `m3_string_decode`

## 7. 文档维护规则

- 新的里程碑说明统一命名 `M<N>_<主题>.md`；新的专题审计也放 `docs/` 根，并在本索引登记。
- 已完成且被后续结论取代的文档不删除，标为「历史」并保留，避免丢失证据链。
- 任何会改变玩家可见行为或 verify 数值的改动，必须同时更新 [HANDOFF_M0.md](HANDOFF_M0.md) §11 和本索引对应条目的状态。