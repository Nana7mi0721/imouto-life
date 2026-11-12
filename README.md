# Imouto! Life ～単色～ — Rust 数据级重写

《妹！生活 ～単色～》（いぬすく 2019，WOLF RPG Editor，zh-CN 汉化 2.03）的 Rust 重写工程。
本仓库只包含**代码、测试与文档**；零售数据、构建产物和用户截图不入 git。

## 当前状态

- M0 数据勘察与工程骨架：完成
- M1 标题 / 读档 / 文本解码：完成
- M2 日常循环切片：完成并推送
- M3 完整运行时：完成并推送
- M4 对等打磨：完成并推送（HUD、设置界面、状态面板相对坐标、夜菜单、tile/text 缓存、音频语义、打包）
- M5 超越原版：完成，M5-A（高分辨率 / 无级缩放 / 全屏）、M5-B（F3 运行时调试 overlay）、M5-C（F2 统计/里程碑 overlay）、M5-D（TSV 内容翻译目录 + 覆盖检查工具/上下文键）、M5-E（--mod 数据/音频覆盖层 + mod 清单/依赖/文本补丁）、M5-F（F4 消息回顾）已落地
- M6 输入层对等：完成（`123` 选项字/掩码过滤/等待位、原始键码与改键闭环、`125`/`126` 编码、`121` min-max）
- M7 三项增强：完成（完整英语语言包 `docs/translations/en.full.tsv`、mod 记录级二进制补丁、模拟器热键重绑定 `--hotkeys`；本地提交）
- **Godot 迁移：P0/P1/P2 完成**（GDExtension 混合前端；标题菜单与 Rust capture 基线 **99.779% 像素完全一致**；输入/读档/文字校准/600-1800 帧长程 parity 已通）。见 **[docs/GODOT_MIGRATION.md](docs/GODOT_MIGRATION.md)**
- **深度审查 BUG-25..48：修复完成**（构建/默认测试全绿，真实数据仅 2 项既有姊妹作 `db` 差异；verify 64/1 SKIP、precompile 19/0、m14 5/5、Godot smoke/parity PASS）。见 **[docs/HANDOFF_DEEP_REVIEW_FIX.md](docs/HANDOFF_DEEP_REVIEW_FIX.md)**

当前状态摘要与遗留事项见 **[docs/HANDOFF_M0.md](docs/HANDOFF_M0.md) §11**；完整历史进度见 **[docs/HANDOFF_PROGRESS.md](docs/HANDOFF_PROGRESS.md)**。
开工前必读协作约定见 **[AGENTS.md](AGENTS.md)**。

## 文档入口

- **[docs/README.md](docs/README.md)** — 全量文档索引（按里程碑与用途分组，标注现行/历史）
- **[docs/HANDOFF_M0.md](docs/HANDOFF_M0.md)** — 新会话交接：数据事实、世代差异、M0 清单、当前状态摘要
- **[docs/HANDOFF_PROGRESS.md](docs/HANDOFF_PROGRESS.md)** — 完整进度日志（M0–M7 与 C 任务）
- **[docs/reviews/CODE_REVIEW_4ROUND.md](docs/reviews/CODE_REVIEW_4ROUND.md)** — 第一至四轮深度代码审查（BUG-25..48，含历史基线）
- **[docs/HANDOFF_DEEP_REVIEW_FIX.md](docs/HANDOFF_DEEP_REVIEW_FIX.md)** — 深度审查 BUG-25..48 的完成交接、语义证据与验证结果
- **[docs/ENGINE_BEHAVIOR.md](docs/ENGINE_BEHAVIOR.md)** — 引擎行为规范；逆向细节见 [docs/RE_GAME_EXE.md](docs/RE_GAME_EXE.md) 与 [docs/re/](docs/re/)
- **[docs/BASELINE.json](docs/BASELINE.json)** — 本作自己的 verify 基线（不是姊妹作的）
- **[docs/REFERENCE.md](docs/REFERENCE.md)** — 日文原版、攻略、实机截图与存档样本索引

## 快速开始

要求：Windows + Rust stable（见 `rust-toolchain.toml`），数据根为 `work/Data`（175 MB，已 gitignore）。

```bash
cd '/e/Study/github program/Imouto Life'
source tools/env.sh

cargo build -q --workspace
cargo test -q --workspace                          # 无数据时数据用例自动 skip，仍须 exit 0
WOLF_DATA_ROOT="$PWD/work/Data" cargo test -q --workspace  # 真正跑本作数据（须绝对路径；cargo 以各 crate 根为 cwd，相对路径会静默 skip）
WOLF_DATA_ROOT=work/Data ./target/debug/wolf-cli.exe verify
```

装包与发布：见 **[docs/PACKAGING.md](docs/PACKAGING.md)**，产物在 `work/out/dist/<version>/`。

### Godot 前端（迁移中）

需要 Godot 4.7.2（当前 `E:/Study/github program/Godot_v4.7.2-stable/`）。Rust 只编
`wolf-gdext` 一个 cdylib（不含 wgpu/winit），Godot 负责窗口、渲染、音频与 UI：

```bash
bash tools/build-godot.sh     # 产出 godot/bin/wolf_gdext.dll
bash tools/smoke-godot.sh     # headless：标题/键码/鼠标/滚轮/读档界面/存档往返
bash tools/parity-godot.sh    # 600/1200/1800 帧 VM 统计 + 600 帧像素对照
'/e/Study/github program/Godot_v4.7.2-stable/Godot_v4.7.2-stable_win64_console.exe' --path godot
```

细节、数据根参数与截图命令见 **[docs/GODOT_MIGRATION.md](docs/GODOT_MIGRATION.md)**；
操作/显示/对话问题的复现与日志开关见 **[docs/GODOT_DEBUGGING.md](docs/GODOT_DEBUGGING.md)**。

## 仓库结构

| 目录 | 内容 |
|---|---|
| `crates/wolf-format` | WOLF 数据格式：Game.dat / CommonEvent / Database / mps / tileset / DXArchive VER6 等 |
| `crates/wolf-save` | .sav 存档编解码与 vardb |
| `crates/wolf-vm` | WOLF 字节码解释器、变量与 magic 地址 |
| `crates/wolf-render` | 软件/离屏渲染与文本 |
| `crates/wolf-audio` | BGM/SE 混音与 SoundCmd 语义 |
| `crates/wolf-game` | 游戏层：Game、地图运行时、HUD、设置、存档应用 |
| `crates/wolf-cli` | `wolf-cli` 子命令：verify / precompile / list / capture / play / run |
| `crates/wolf-gdext` | Godot 4 GDExtension 桥：`WolfGame` 类 + 每帧绘制包 |
| `godot/` | Godot 4.7 工程（1024x576，GDExtension 混合前端） |
| `docs/` | 交接、里程碑说明、审计报告与调研资料 |
| `work/` | 本地数据与临时输出（gitignore） |

## 硬性约束（摘要）

- 不要照抄姊妹作 `imoto life` 的 `docs/BASELINE.json`；本作期望值看本仓库的 `docs/BASELINE.json`。
- 不要为 Sys 变量 104/105 建 player/camera/滚动模型：本作 5 张注册地图全是定屏。
- 不要把 .wolf 解密当难题（VER6 已解开，`verify --wolf` 1,361/1,361 逐字节通过）。
- 截图只能由用户按游戏内 PrintScreen；不要用 PowerShell 抢前台或模拟按键。
- 每次 bash 开头 `source tools/env.sh`；临时输出放 `work/out/`。
