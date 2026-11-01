# Imouto! Life ～単色～ — Rust 数据级重写

《妹！生活 ～単色～》（いぬすく 2019，WOLF RPG Editor，zh-CN 汉化 2.03）的 Rust 重写工程。
本仓库只包含**代码、测试与文档**；零售数据、构建产物和用户截图不入 git。

## 当前状态

- M0 数据勘察与工程骨架：完成
- M1 标题 / 读档 / 文本解码：完成
- M2 日常循环切片：完成并推送
- M3 完整运行时：完成并推送
- M4 对等打磨：完成并推送（HUD、设置界面、状态面板相对坐标、夜菜单、tile/text 缓存、音频语义、打包）
- M5 超越原版：进行中，首个切片 M5-A（高分辨率 / 无级缩放 / 全屏）已落地

最新详细状态、已验证数字与遗留缺口见 **[docs/HANDOFF_M0.md](docs/HANDOFF_M0.md)** 的「§11 进度」。
开工前必读协作约定见 **[AGENTS.md](AGENTS.md)**。

## 文档入口

- **[docs/README.md](docs/README.md)** — 全量文档索引（按里程碑与用途分组，标注现行/历史）
- **[docs/HANDOFF_M0.md](docs/HANDOFF_M0.md)** — 新会话交接：数据事实、世代差异、M0 清单、进度
- **[docs/BASELINE.json](docs/BASELINE.json)** — 本作自己的 verify 基线（不是姊妹作的）
- **[docs/REFERENCE.md](docs/REFERENCE.md)** — 日文原版、攻略、实机截图与存档样本索引

## 快速开始

要求：Windows + Rust stable（见 `rust-toolchain.toml`），数据根为 `work/Data`（175 MB，已 gitignore）。

```bash
cd '/e/Study/github program/Imouto Life'
source tools/env.sh

cargo build -q --workspace
cargo test -q --workspace                          # 无数据时数据用例自动 skip，仍须 exit 0
WOLF_DATA_ROOT=work/Data cargo test -q --workspace # 真正跑本作数据
WOLF_DATA_ROOT=work/Data ./target/debug/wolf-cli.exe verify
```

装包与发布：见 **[docs/PACKAGING.md](docs/PACKAGING.md)**，产物在 `work/out/dist/<version>/`。

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
| `docs/` | 交接、里程碑说明、审计报告与调研资料 |
| `work/` | 本地数据与临时输出（gitignore） |

## 硬性约束（摘要）

- 不要照抄姊妹作 `imoto life` 的 `docs/BASELINE.json`；本作期望值看本仓库的 `docs/BASELINE.json`。
- 不要为 Sys 变量 104/105 建 player/camera/滚动模型：本作 5 张注册地图全是定屏。
- 不要把 .wolf 解密当难题（VER6 已解开，`verify --wolf` 1,361/1,361 逐字节通过）。
- 截图只能由用户按游戏内 PrintScreen；不要用 PowerShell 抢前台或模拟按键。
- 每次 bash 开头 `source tools/env.sh`；临时输出放 `work/out/`。
