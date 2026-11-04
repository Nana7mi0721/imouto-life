# 文档索引（docs/README.md）

本文件是《妹！生活 ～単色～》Rust 重写的**唯一文档地图**。按用途分组：
交接 → 基线 → 里程碑 → M3 专题审计 → 引擎行为与逆向 → 调研资料 → 翻译 → 参考实现 → 工具与工作区。
标「历史」的文档只作证据链保留，**当前事实以「现行」条目为准**。

## 1. 交接与工程约定（先读）

| 文件 | 状态 | 内容 |
|---|---|---|
| [HANDOFF_M0.md](HANDOFF_M0.md) | **现行 · 先读** | 新会话交接：§0 提示词、§1 现状、§3 已实测硬事实、§4 世代差异、§5 M0 清单、§6 代码地图、§7 调研采信/推翻、§8 陷阱、§9 不要做、**§11 当前状态摘要** |
| [HANDOFF_PROGRESS.md](HANDOFF_PROGRESS.md) | 现行 · 查史 | 完整进度日志（M0–M7 与 C 任务逐步的改动、验证数字、坑），由 HANDOFF §11 拆出 |
| [../AGENTS.md](../AGENTS.md) | **现行 · 必读** | 协作约定：并行/写作用域、bash 开头、数据与测试、提交、清理、内容安全 |
| [../README.md](../README.md) | 现行 | 仓库总览、当前状态、快速开始、目录结构 |
| [PROJECT_ASSETS.md](PROJECT_ASSETS.md) | 现行 · 资产盘点 | 停止重构后的清理记录与可复用资产清单（源码/数据/文档/逆向/证据） |

## 2. 基线

| 文件 | 状态 | 内容 |
|---|---|---|
| [BASELINE.json](BASELINE.json) | 现行 | 本作自己的 `wolf-cli verify` 期望值（25 个 Game.dat 参数、350 公共事件、地图事件、tileset/文件版本、1,361 条 archive） |
| [REFERENCE.md](REFERENCE.md) | 现行 | 日文原版路径、攻略链接、10 张实机截图目录、存档样本 |

## 3. 里程碑说明

| 文件 | 状态 | 内容 |
|---|---|---|
| [M2_SLICE.md](M2_SLICE.md) | 完成 | M2 日常循环切片：CE245/CE251/CE242/CE243/CE244/CE256 实测、鼠标→键码契约、验收 |
| [M3_RUNTIME.md](M3_RUNTIME.md) | 完成 | M3 完整运行时：测试基架、引擎修复、存档/字符串/音频、遗留缺口 |
| [M4_PARITY.md](M4_PARITY.md) | 完成 | M4 对等打磨分解（UI、音频、存档互通、性能） |
| [M4_HUD.md](M4_HUD.md) | 完成 | M4 HUD/读档数值与负号图片保真修复 |
| [M4_SETTINGS_UI.md](M4_SETTINGS_UI.md) | 完成 | CE132/CE95 设置界面排版修复（字号、290 位移、1/10 字符格、CursorBase） |
| [M4_PERF.md](M4_PERF.md) | 完成/基线 | M4 headless 性能基线与优化候选（tile quad 缓存已落地） |
| [M4_V8_AUDIT.md](M4_V8_AUDIT.md) | 完成 | 普通变量 v8 语义专项（夜间可活动上限 23..26） |
| [M5_BEYOND.md](M5_BEYOND.md) | 完成 | M5 超越原版 A–F 切片（高分辨率/调试 overlay/统计/翻译目录/mod 覆盖/消息回顾） |
| [M6_INPUT.md](M6_INPUT.md) | 完成 | M6 输入层对等（123 选项字解码、键码闭环、125/126、121 min-max） |
| [M7_I18N.md](M7_I18N.md) | 完成 | M7 英语语言包（TSV 双列转义、模板静态句、en.full.tsv 100%） |
| [M7_PATCH.md](M7_PATCH.md) | 完成 | M7 mod 记录级二进制补丁（Database 字节序列化 + set_cell + 两阶段补丁） |
| [M7_HOTKEYS.md](M7_HOTKEYS.md) | 完成 | M7 模拟器热键重绑定（--hotkeys） |
| [ASSETS.md](ASSETS.md) | 完成 | 素材目录导出：`wolf-cli assets`（另见 `--db-defaults` 数据库层导出） |
| [PACKAGING.md](PACKAGING.md) | 完成 | 发布打包：`work/out/dist/<version>/` |

## 4. M3 专题审计

| 文件 | 主题 | 对应测试 |
|---|---|---|
| [M3_EVENT_MAP.md](M3_EVENT_MAP.md) | 自有公共事件 CE212..303 冒烟与事件地图 | `m3_event_smoke` |
| [M3_EVENT_GRAPH.md](M3_EVENT_GRAPH.md) | 公共事件调用图与可达性静态审计 | `m3_event_graph` |
| [M3_EVENT_INPUTS.md](M3_EVENT_INPUTS.md) | 自有事件在真实按键注入下的可达性 | `m3_event_inputs` |
| [M3_MAP_EVENTS.md](M3_MAP_EVENTS.md) | 5 张注册地图属性 + SampleMapA 35 事件冒烟 | `m3_map_events` |
| [M3_MANUAL_ALIGNMENT.md](M3_MANUAL_ALIGNMENT.md) | 官方说明书 manual01..06 逐条核对 | — |
| [M3_ASSET_REFS.md](M3_ASSET_REFS.md) | 事件脚本图片/音频引用完整性扫描 | `m3_asset_refs` |
| [M3_STRING_DECODE.md](M3_STRING_DECODE.md) | CP932/GBK 混排解码审计与回归 | `m3_string_decode` |
| [M3_VARDB_BUG.md](M3_VARDB_BUG.md) | 新游戏存档丢失 CDataBase 可变数据库（已修复） | `m3_vardb_cdata_roundtrip` |
| [M3_TITLE_UX.md](M3_TITLE_UX.md) | 标题菜单可见性与“取消读档返回标题”链 | 标题/读档测试 |
| [M3_ENDINGS.md](M3_ENDINGS.md) | 结局条件、变量写入者与事件链 | `m3_endings` |

## 5. 引擎行为与逆向（C 任务）

> 这一组是**引擎行为的事实源**。`ENGINE_BEHAVIOR.md` 是面向实现的规范；
> `RE_GAME_EXE.md` 与 `re/*.md` 是原版 Game.exe 的反编译证据（方法、函数地址、伪码行号）。

| 文件 | 状态 | 内容 |
|---|---|---|
| [ENGINE_BEHAVIOR.md](ENGINE_BEHAVIOR.md) | **现行 · 引擎规范** | 六类核心行为（九宫格/文本度量与换行/选择面板/1-10 UI 缩放/过渡/叠色）+ §3 十二项常量与落地状态 |
| [RE_GAME_EXE.md](RE_GAME_EXE.md) | 现行 · 逆向方法 | 工具链（Ghidra 12.2 + JDK 25）、二进制身份、函数地图、可复现步骤与坑 |
| [re/RUNTIME_CONSTANTS.md](re/RUNTIME_CONSTANTS.md) | 现行 · 证据 | 帧率/窗口/present 后端/皮肤/过渡掩膜几何 |
| [re/TEXT_METRICS.md](re/TEXT_METRICS.md) | 现行 · 证据 | 行距公式、禁则（原版无）、打字机累加水位 |
| [re/LAYOUT_METRICS.md](re/LAYOUT_METRICS.md) | 现行 · 证据 | 坐标取整、默认原点、九宫格、极小盒、102 面板全链、超宽选项；§9 落地记录 |
| [re/TRANSITION.md](re/TRANSITION.md) | 现行 · 证据 | 过渡掩膜几何、溶解语义、tint×fade 顺序；§5 落地前后对照 |
| [re/SCREENSHOT_METRICS.md](re/SCREENSHOT_METRICS.md) | 现行 · 实机 | 实机截图标定：消息行距 23、选择支行距 27、面板 156×114 / 162×141、内缩 8 |

## 6. 调研与实证（历史背景，不是当前事实源）

| 文件 | 说明 |
|---|---|
| [research/README.md](research/README.md) | 调研目录说明 |
| [research/M7_PRNG.md](research/M7_PRNG.md) | PRNG 实证（M3 已落地） |
| [research/gpt-reports/](research/gpt-reports/) | M0 之前的 6 份 GPT 深度调研报告 + 前置问题组 `GPT_RESEARCH_GROUPS.md`；**采信/推翻清单以 HANDOFF §7 为准** |
| [攻略文档/](攻略文档/) | 第三方攻略与资料（gitignore，不提交；仅本地参考，非事实源） |
| 相关链接.txt | 外部链接汇总（gitignore，不提交） |

## 7. 翻译目录

| 文件 | 内容 |
|---|---|
| [translations/README.md](translations/README.md) | TSV 目录格式、`[msg]`/`[choice]` 作用域键、生成工具 |
| [translations/en.tsv](translations/en.tsv) / [en.full.tsv](translations/en.full.tsv) / [ja.tsv](translations/ja.tsv) | 演示/完整语言目录与日文回填表 |

## 8. 参考实现

| 目录 | 内容 |
|---|---|
| [vendor/uberwolf-ref/](vendor/uberwolf-ref/) | 第三方 WOLF 数据解码参考（DXLib / UberWolfLib / dw2_header.py / dw8_verify.py）。**只读参考，不参与构建** |

## 9. 工具与工作区产物

| 位置 | 说明 |
|---|---|
| `tools/env.sh` / `env.ps1` / `setpath.ps1` | 环境（含 `GHIDRA_INSTALL_DIR`/`GHIDRA_JAVA_HOME`） |
| `tools/package.sh` / `package.ps1` / `package/` | 打包脚本与模板 |
| [../tools/re/wolfpe.py](../tools/re/wolfpe.py) | 只读 PE 探针（facts/strings/xref/disasm） |
| [../tools/re/ghidra/README.md](../tools/re/ghidra/README.md) | Ghidra headless 反编译脚本（DumpAll/DumpByAnchor） |
| `work/Data` | 解包后的本作数据，176 MB，**gitignore**，测试必需 |
| `work/out/re_all/` | 4,375 个 ≥64B 函数的 Ghidra C 伪码 + index.tsv（27 MB，未入库，复核用） |
| `work/out/ghidra/` | 已于 2026-11-04 清理（166 MB）；需要时用 `tools/re/ghidra` 从原版 `Game.exe` 重新 import（约 4 分钟） |
| `work/out/_archive/` | 历史提交信息（`commit_messages/`）与一次性探针脚本（`scripts/`）归档，未入库 |
| `work/out/shot_metrics/` | 截图度量脚本与标注图（未入库，SCREENSHOT_METRICS 的复现材料） |

## 10. 被引用但本仓库缺失的文档

以下路径在**代码注释**里被引用，但本仓库没有对应文件（沿用上一作仓库的文档名，未随仓库复制过来）。
新会话不要以为它们存在；需要时从上一作仓库取，或按 [ENGINE_BEHAVIOR.md](ENGINE_BEHAVIOR.md) 重写：

`ARCHITECTURE.md`、`OPCODE_SPEC.md`、`OPCODE_101/102/112/124/210_RETURN/220_SAVE/250/290.md`、
`FORMAT_SPEC.md`、`SAVE_SPEC.md`、`TEXT_SPEC.md`、`BATTLE.md`、`HSCENE.md`、`ENGINE_EVENTS.md`、
`MAP_AUDIT.md`、`ASSET_AUDIT.md`、`AUDIO.md`、`M1_CLOSURE.md`、`HANDOFF_M3.md`、`HANDOFF_M4.md`、`PLAN.md`、`UNVERIFIED.md`。

## 11. 文档维护规则

- 新里程碑说明命名 `M<N>_<主题>.md`，新专题审计放 `docs/` 根，并**在本索引登记**。
- 完成且被取代的文档不删除，标「历史」保留证据链。
- 会改变玩家可见行为或 verify 数值的改动：同时更新 [HANDOFF_M0.md](HANDOFF_M0.md) §11.1、
  [HANDOFF_PROGRESS.md](HANDOFF_PROGRESS.md) 末尾新增一条，以及本索引对应条目状态。
- 反编译/实测证据进 `docs/re/`；调研背景进 `docs/research/`；两者都不与规范文档混放。
