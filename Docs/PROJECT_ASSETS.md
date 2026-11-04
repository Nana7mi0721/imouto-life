# 项目资产盘点（PROJECT_ASSETS）

> 记录时间：2026-11-04
> 背景：用户决定停止继续重构《妹！生活 ～単色～》，清理发布包与无用产物；本文件用于盘点**仍可复用的资产**，供后续判断用途。
> 结论先说：**已放弃的是“完整可玩替代品”目标，不是代码与逆向资料。** 当前最有价值的是 WOLF RPG Editor 数据/存档/字节码工具链，而不是这套不完整的游戏前端。

---

## 1. 本次已清理的内容

| 项目 | 位置 | 原大小 | 说明 |
|---|---|---:|---|
| 可双击发布包（安装态） | `D:\program\Imouto Life` | 188 MB | 已删除；这是上一次生成的 release 包，不是原版游戏。 |
| 发布压缩包 | `work/out/dist/` | 164 MB | 已删除，含 `Imouto Life-0.1.0-playable.zip`（159.6 MB）与旧 0.1.0 目录。 |
| Rust 构建产物 | `target/` | 4.1 GB | 已删除；需要时用 `cargo build --workspace` 重建。 |
| 文本度量临时工程/截图 | `work/out/text_metrics/` | 660 MB | 已删除；其中 `probe/target` 占 637 MB，结论已在 `docs/re/TEXT_METRICS.md`。 |
| Ghidra 工程 | `work/out/ghidra/` | 166 MB | 已删除；**不是丢弃反编译成果**：4,375 个函数的 C 伪码保留在 `work/out/re_all/`，工程可用 `tools/re/ghidra` 从原版 `Game.exe` 重新 import（约 4 分钟）。 |
| 游戏截图/回归/一次性探测输出 | `work/out/play_gpu/`、`m14_visual/`、`shots/`、顶层 615 个临时文件等 | 约 400+ MB | 已删除；保留少量最终截图与报告，见 §3.5。 |

**清理后项目体积：约 250 MB**（不含 `target/`，未重新构建）。其中 `work/Data` 176 MB、`work/out` 42 MB、`prt sc` 17 MB、`.git` 11 MB、源码/文档/工具约 5.4 MB。

已保留、未删除的关键输入：

- 日文原版：`E:\EROGAME\限界!？お兄ちゃん 「妹!せいかつ」～モノクローム～2.03`（180 MB）
- 中文版：`E:\EROGAME\Imouto! Life ~Monochrome~ zh-CN Ver`（178 MB）
- 解包数据：`work/Data`（176 MB）
- 实机截图：`prt sc/`（34 个文件，17 MB）

---

## 2. 源码资产：8 个 Rust crate，约 10.5 万行

源码在 `crates/`，共 **172 个 Rust 文件、104,651 行**；集成测试文件 **86 个**，源码内 `#[test]` 标记 **939 处**。
当前基线：`cargo test -q --workspace` 在清理前 **exit 0**；`WOLF_DATA_ROOT="$PWD/work/Data" wolf-cli verify` 为 **PASS 64 / 1 SKIP**。

| crate | 行数 | 可复用价值 | 主要能力 |
|---|---:|---|---|
| `crates/wolf-format` | 35,531 | ★★★★★ | WOLF 数据格式：Game.dat / CommonEvent / Database / CDataBase / mps / tileset / DXArchive VER6 解密与解包；CP932/GBK 混排文本解码。 |
| `crates/wolf-vm` | 6,720 | ★★★★★ | WOLF 字节码解释器、opcode 语义、变量与 magic 地址、选择肢/文本展开。 |
| `crates/wolf-save` | 6,025 | ★★★★★ | `.sav` 存档编解码、vardb、checksum、写入与往返保真。 |
| `crates/wolf-render` | 5,377 | ★★★☆☆ | 软件/离屏渲染、文本 shaping（fontdb + 字重/字号/行距）、图像 diff。 |
| `crates/wolf-audio` | 2,171 | ★★★☆☆ | BGM/SE 混音与 SoundCmd 语义、音频覆盖。 |
| `crates/wolf-game` | 41,129 | ★★☆☆☆ | 游戏层：Game、地图运行时、HUD、设置、存档界面、输入、事件状态机；体量最大、与“完整复刻”目标耦合最深。 |
| `crates/wolf-cli` | 7,532 | ★★★★☆ | `wolf-cli` 子命令：`verify` / `list` / `capture` / `play` / `run` / `assets` / `precompile` 等。 |
| `crates/wolf-launcher` | 166 | ★☆☆☆☆ | 上次发布包用的 GUI 启动器；很小，可保留也可删。 |

**最高复用价值不在 `wolf-game`，而在 `wolf-format` + `wolf-vm` + `wolf-save` + `wolf-cli`。**
换句话说：这套代码作为“WOLF 游戏数据提取/翻译/改档工具”比作为“游戏引擎”更成熟。

---

## 3. 数据、文档、逆向与证据资产

### 3.1 解包后的本作数据 `work/Data` — 176 MB
- 1,364 个文件；17 个 `.wolf` 归档已解包：BasicData / MapData / Picture / BGM / SE / CharaChip / MapChip / SystemFile / SystemGraphic / cg 等。
- 含存档样本 `work/Data/Save/`（SaveData01/02、System 等）。
- 这是测试、提取、翻译、改档的直接输入，**建议保留**。
- `wolf-cli verify` 可逐项校验 64 项基线（`docs/BASELINE.json`）。

### 3.2 文档 `docs/` — 1.4 MB，68 个文件（48 个 Markdown）
关键文档：
- 交接：`docs/HANDOFF_M0.md`、`docs/HANDOFF_PROGRESS.md`
- 引擎规范：`docs/ENGINE_BEHAVIOR.md`（六类核心行为 + 12 项常量）
- 逆向方法：`docs/RE_GAME_EXE.md`（Ghidra 12.2 + JDK 25、二进制身份、函数地图、复现步骤）
- 逆向证据：`docs/re/RUNTIME_CONSTANTS.md`、`TEXT_METRICS.md`、`LAYOUT_METRICS.md`、`TRANSITION.md`、`SCREENSHOT_METRICS.md`、`EVENT_REACHABILITY.md`
- 里程碑/审计：`M2_SLICE.md`、`M3_*.md`（事件图、地图事件、文本解码、结局、手册对照等 10+ 篇）、`M4_*.md`、`M5_BEYOND.md`、`M6_INPUT.md`、`M7_*.md`
- 翻译：`docs/translations/en.full.tsv`（116 KB，完整英文本地化目录）、`en.tsv`、`ja.tsv`
- 参考：`docs/REFERENCE.md`（原版、攻略、10 张实机截图、存档样本索引）

### 3.3 原版游戏（项目外，最高价值输入）
- 日文原版 2.03：`E:\EROGAME\限界!？お兄ちゃん 「妹!せいかつ」～モノクローム～2.03`（180 MB，含 `Game.exe`、`Data/`、6 页官方说明书）
- 简中版 2.03：`E:\EROGAME\Imouto! Life ~Monochrome~ zh-CN Ver`（178 MB，含实机存档样本）
- 这两个目录是**原始素材与验证基准**，后续无论做提取、翻译、补丁还是再研究，都应保留。

### 3.4 静态逆向资产
| 资产 | 位置 | 大小 | 用途 |
|---|---|---:|---|
| Ghidra 反编译 C 伪码 | `work/out/re_all/all/` + `index.tsv` | 27 MB | 4,375 个 ≥64B 函数的可搜索 C 伪码，按地址索引；比重新跑 Ghidra 工程更轻。 |
| Anchor/GDI 专项 dump | `work/out/re_anchor/`、`re_dump_gdi/` | 1.1 MB | 特定绘制/锚点函数的补充反编译证据。 |
| Ghidra 脚本 | `tools/re/ghidra/` | 约 40 KB | `DumpAll.java`、`DumpByAnchor.java`、`run_ghidra.sh`、README；可对任意 WOLF Game.exe 复用。 |
| PE 探针 | `tools/re/wolfpe.py` | 9 KB | facts / strings / xref / disasm 只读探针。 |
| 工具安装 | `D:\program\ghidra_12.2_PUBLIC`、`D:\Program\Java\jdk-25.0.5+8`、`jdk-21.0.13+9` | 约 1.5 GB | Ghidra 12.2 + JDK 25/21；环境变量见 `tools/env.sh`。 |

### 3.5 证据与可复现材料（已从临时目录归档）
- `work/out/_archive/evidence/`：最终截图 `title.png`、`hud.png`、`day_command.png`、`saveui.png`、`saveui_sbs.png`、`day_command_probe.png`、`newgame_fix1.png`，以及一个旧坏档快照 `SaveData01.savescreen-snapshot.sav`。
- `work/out/event_reach/`：事件可达性审计 `report.tsv`、`report_savedata02.tsv`、`tables.md`。
- `work/out/shot_metrics/`：截图度量的脚本、标注图、`metrics*.json`（`SCREENSHOT_METRICS.md` 的复现材料）。
- `work/out/wolfmanual/manual.zip`：官方说明书图片归档（1.1 MB）。
- `work/out/_archive/reports/`：数据目录/消息/数据库导出（`all_messages.tsv`、`assets_catalog.tsv`、`asset_manifest.tsv`、`db.tsv`、`db_defaults.json`、`decoded.txt` 等）与 6 份事件 dump。
- `work/out/_archive/commit_messages/` 与 `scripts/`：历史提交说明与一次性探针脚本（合计约 50 KB；`_archive` 总计 4.2 MB，其余为 evidence/reports）。

### 3.6 版控与基线
- Git：当前 master，**40+ 个提交**；最后一轮修复已用提交 `chore: checkpoint final working tree before asset inventory` 固定（具体 hash 用 `git log -1` 查看），便于以后取用。
- 本次清理与资产盘点已提交在 `docs: add project asset inventory`。
- `docs/BASELINE.json`：本作自己的 verify 期望值（25 个 Game.dat 参数、350 公共事件、地图事件、tileset/文件版本、1,361 条 archive）。
- `Cargo.lock` 已锁定依赖；`rust-toolchain.toml` 固定 Rust 版本。

---

## 4. 资产价值判断（建议）

### A. 最适合复用：WOLF 数据工具箱（★★★★★）
把 `wolf-format` + `wolf-save` + `wolf-vm` + `wolf-cli` 抽出来，就是一套可对 WOLF RPG Editor 游戏做：
- `.wolf` VER6 解密/解包；
- Game.dat / CommonEvent / Database / CDataBase 解析；
- 文本提取（含 CP932/GBK 混排修复）、翻译目录回填；
- `.sav` 存档解析/写入/改档；
- 字节码级事件审计。

这部分的测试与 verify 基线完整，复用成本最低、收益最高。

### B. 可作为“逆向与格式研究资料”保留（★★★★☆）
`docs/re/` + `work/out/re_all/` + `tools/re/ghidra/` 记录了原版 Game.exe 的函数地图、文本度量、九宫格、过渡、叠色、事件可达性。
即使不再做这个游戏，也可作为 WOLF 引擎研究与同类游戏分析的参考。

### C. 游戏前端 `wolf-game` 只建议作参考实现（★★☆☆☆）
它包含大量真实 UI/输入/事件状态机代码，但正是“完整可玩复刻”未达标的部分；单独复用价值有限，适合作为“遇到某界面/某机制时查实现”的参考。

### D. 不建议再以“发布可玩游戏”为目标继续投入
发布包已删除；当前源码能通过测试与 verify，但真实游玩仍有 bug。后续若继续，建议只做“工具化/局部验证”，不要重新追求完整替代品。

---

## 5. 当前保留清单（按位置）

```
E:\Study\github program\Imouto Life
├─ crates/                    8 个 crate，172 个 .rs，104,651 行
├─ docs/                      68 个文件；规范、里程碑、逆向证据、翻译
├─ tools/                     env、Ghidra 脚本、PE 探针、打包脚本（约 130 KB）
├─ prt sc/                    34 张实机截图（17 MB）
├─ work/
│  ├─ Data/                   176 MB，解包数据与存档样本
│  └─ out/                    42 MB
│     ├─ _archive/            报告/证据/历史提交信息（4.2 MB）
│     ├─ event_reach/         事件可达性报告（208 KB）
│     ├─ re_all/              4,375 个 Ghidra C 伪码（27 MB）
│     ├─ re_anchor/           锚点反编译证据（972 KB）
│     ├─ re_dump_gdi/         GDI 反编译证据（128 KB）
│     ├─ shot_metrics/        截图度量脚本与标注图（8.2 MB）
│     └─ wolfmanual/          官方说明书归档（1.1 MB）
└─ .git/                      41 个提交（11 MB）
```

项目外保留：
- `E:\EROGAME\限界!？お兄ちゃん 「妹!せいかつ」～モノクローム～2.03`（180 MB，日文原版）
- `E:\EROGAME\Imouto! Life ~Monochrome~ zh-CN Ver`（178 MB，简中版）
- `D:\program\ghidra_12.2_PUBLIC` + `D:\program\Java`（约 1.5 GB，逆向工具链）

---

## 6. 备注

- 本次清理**没有**删除 `work/Data`、`prt sc/`、`docs/`、`crates/`、`tools/`、`.git/`。
- `work/out` 下仍有若干“可再删”的复现材料（`shot_metrics` 8.2 MB、`re_all` 27 MB）；若只保留源码与数据，可再释放约 36 MB。
- 发布包相关的 `crates/wolf-launcher`（166 行）与 `tools/package-playable.sh` 仍保留在源码中，属于小体积、可随时删除的附属资产。
