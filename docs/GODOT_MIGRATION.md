# Godot 迁移（GDExtension 混合）

> 状态：2026-11-10，**P0 骨架 + P1 核心 + P2 输入/文字/长程 parity 完成**。
> 目标：**忠实复刻**。Godot 只替换窗口、渲染、音频与 UI 宿主；WOLF 的格式、字节码、
> 变量、存档和游戏层语义继续留在已经测试过的 Rust 核心里。

## 1. 架构边界

| 层 | 位置 | 迁移后 |
|---|---|---|
| 数据格式 / 解包 / 文本解码 | `crates/wolf-format` | **保留**，编进 DLL |
| 字节码解释器 / 变量 / 选择肢 | `crates/wolf-vm` | **保留**，编进 DLL |
| `.sav` 存档 / vardb | `crates/wolf-save` | **保留**，编进 DLL |
| 游戏层（picture / map / message / save UI / settings） | `crates/wolf-game` | **保留**，编进 DLL |
| 窗口 / 渲染 / 输入 | `crates/wolf-render` + `wolf-cli play` | **替换**为 Godot |
| 音频设备 / 解码 | `crates/wolf-audio` | **替换**为 Godot `AudioStream*` |
| 启动器 | `crates/wolf-launcher` | P3 下线 |
| 离线工具（verify / capture / assets / precompile） | `crates/wolf-cli` | **保留**，不参与 Godot 运行时 |

新的 `crates/wolf-gdext` 是唯一的桥：它把 `Game` 和 `Atlas` 包成 GDScript 可见的
`WolfGame`，每帧返回一个绘制包。Godot 侧不依赖 wgpu、winit、glyphon、cosmic-text，
也不编译音频后端。

## 2. 工程布局

```
crates/wolf-gdext/          # cdylib：WolfGame 类 + 帧数据包
  src/lib.rs
godot/                      # Godot 4.7 工程
  project.godot             # 1024x576 / canvas_items / GL Compatibility
  main.tscn                 # 全屏 Control，挂 GameView.gd
  scripts/GameView.gd       # 输入、帧循环、atlas 上传、文字/overlay 绘制
  scripts/WolfKeys.gd       # Godot 物理键 -> WOLF scancode+100、key_bits 组合
  scripts/WolfText.gd       # TextParagraph 校准（基线/行距/描边/宽度 slack）
  tests/smoke.gd            # headless 冒烟（SceneTree）
  tests/key_map.gd          # 97 项键码/改键组合单测
  tests/load_menu.gd        # 标题 -> CE14 -> CE131 读档端到端
  tests/parity_stats.gd     # 长程 Rust/Godot VM 统计对照
  tests/text_probe.gd       # 文字度量/像素探针（可重复跑）
  bin/wolf_gdext.gdextension
  bin/wolf_gdext.dll        # 构建产物，gitignore
tools/build-godot.sh        # cargo build + 拷贝 DLL
tools/smoke-godot.sh        # 构建 + import + headless 冒烟（含 key_map/load_menu）
tools/parity-godot.sh       # 600/1200/1800 帧统计 + 像素对照
```

## 3. 构建与运行

前置：Rust stable（仓库 `rust-toolchain.toml`）、Godot 4.7.2（当前在
`E:/Study/github program/Godot_v4.7.2-stable/`）。

```bash
cd '/e/Study/github program/Imouto Life'
source tools/env.sh
bash tools/build-godot.sh          # 默认 profile "godot"（优化、无 debug info）
bash tools/smoke-godot.sh          # headless：标题/键码/鼠标/滚轮/读档/存档往返
bash tools/parity-godot.sh         # 长程 parity：600/1200/1800 帧 + 600 帧像素
bash tools/parity-godot.sh --pixel-check=0   # 只比 VM 统计，不开窗口
```

窗口运行（默认数据根 `godot/../work/Data`）：

```bash
'/e/Study/github program/Godot_v4.7.2-stable/Godot_v4.7.2-stable_win64_console.exe' \
  --path godot
```

显式数据根与自动截图（`--` 之后的参数由 `OS.get_cmdline_user_args()` 读取）：

```bash
Godot_v4.7.2-stable_win64_console.exe --path godot -- \
  --data-root='E:/Study/github program/Imouto Life/work/Data' \
  --entry=menu \
  --capture='E:/Study/github program/Imouto Life/work/out/godot_menu.png' \
  --frames=120
```

- 窗口按 1024x576 启动；F11 在窗口/全屏之间切换。
- 复现操作/显示/对话问题：加 `--log-input`（键/鼠标/滚轮）、`--log-events`
  （运行中的事件、`last_action_event`）与 `--log-messages`（逐条对话）；
  完整流程见 **[GODOT_DEBUGGING.md](GODOT_DEBUGGING.md)**。
- `--capture` 在达到目标游戏帧后冻结物理时钟，再等 `frame_post_draw` 截图；
  捕获严格是第 N 帧，避免 N/N+1 动画相位差。
- `--entry=menu` 走 `Game::start_title()`（CE42，最终标题菜单）；默认 `boot` 走
  标题地图事件（开场 splash）。对照标题截图时用 `menu`。
- 第一次运行若无 `godot/.godot/extension_list.cfg`，先跑
  `Godot --headless --path godot --import`；`tools/smoke-godot.sh` 会自动处理。
- 构建 profile 说明：`--debug`（普通 dev，带 debug info）、默认 `godot`（优化、
  无 debug info，`target/godot` 约 893 MB）、`--release`（thin LTO）。
- 当前 DLL：`target/godot/wolf_gdext.dll` ≈ 7.3 MB。

## 4. 验收结果（2026-11-10）

### P0 骨架

- GDExtension 加载：`Initialize godot-rust (API v4.7.stable.official, runtime v4.7.2...)`。
- headless 冒烟：240 帧后 `pictures=4 sprites=4 texts=0`，exit 0。
- 标题画面对照：`--entry=menu --frames=120` 的 1024x576 输出与
  `work/out/_archive/evidence/title.png`（Rust capture 基线）
  **99.779% 像素完全一致，最大通道差 1，MAE 0.0022**。
- 这说明 atlas 打包、UV 换算、RGBA8 上传、tint/alpha、绘制顺序和 nine-slice
  面板都已经正确接到 Godot。

### P1 核心（新游戏 / 文字 / 读档 / 音频）

- 新游戏路径：`--entry=menu --auto-new-game --frames=600`（`--frames` 现在按
  **游戏帧**计数，与 `wolf-cli capture` 一致）从标题三键走 Map003 → SampleMapA。
  Godot 与 Rust 的 VM 统计**完全相同**：600 帧 / 16,038 指令 / 4,526 picture op /
  15 messages / 3 choices / 0 warnings。
- 新游戏画面（P2 文字校准前）：Godot vs Rust `capture --menu-only --answer 0 --frames 600`
  **99.28% 像素在 ±8、99.46% 在 ±32 内，MAE 0.77**；差异集中在顶部 HUD 文字
  （bbox y=11..104），场景、面板、图标位置一致。
- 读档（P2 文字校准前）：`--load-save=work/Data/Save/SaveData01.sav --frames=120`
  成功恢复 `SampleMapA`（50 picture / 14 text）；与 Rust `capture --load-save` 对照
  **99.17% 在 ±8、99.37% 在 ±32 内，MAE 0.89**。
- 存档闭环：新游戏 600 帧后 `save_to` 写出 289,487 B 的 `.sav`，Part1 携带
  **64x36x3 地图快照 + 35 个事件对象**；全新会话 `prime_engine → load_save →
  resume_loaded_map` 恢复 SampleMapA，`resumed_pictures=40`。Rust CLI 读同一文件
  也能恢复并渲染（93.89% 非黑）。修法见 `savegame::part1_from_map`：只在模板
  Part1 没有对象时填充，零售存档的 Part1 仍原样保留（字节保真测试通过）。
- 与零售 SaveData01 的 Part1 静态字段对照：`map_tiles`（6912 word）、`chip_image`、
  `auto_tiles`（15）、`vars2_new`（2360 个 passability）、`tail_vars`、每个对象的
  `var1/var2/var3`（事件 id 与 x*2/y*2 坐标）、`var4..9/11/13/14/17/18/20/25..32`
  **全部相等**；只有 `var10/12/15/16/19/21/23/24` 与 `sp1.head[4]` 这类运行态字段
  按默认值写出（实测零售两存档之间本身就不同）。
- 输入：`mouse_title.gd` 在标题三键的第 0 行 (100,420) 注入左键按下/松开，
  180 帧后诊断出现 `130 Teleport: MapData/Map003.mps`，说明鼠标命中、`choice_row_at`
  与分支回复链路都在 Godot 侧正常工作。
- 消息文字（P2 文字校准前）：`--auto-new-game --hold-message --frames=300` 停在
  第一条消息；与 Rust `capture --menu-only --answer 0 --hold-message --frames 300`
  对照 **98.48% 在 ±8、98.71% 在 ±32 内，MAE 2.19**，差异 bbox 仅消息窗口文字区
  (0,1)-(327,72)。
- 音频：`sounds` 已接到 Godot `AudioStreamPlayer`；BGM 循环、音量、`frames`
  淡入/淡出、SE 播放/延迟/停止已实现（无法自动化听感验收，只能确认加载与播放
  无错误）。首个实测命令：`BGM/asa_otozure.ogg` volume 40 fade-in 200 帧。
- headless 联合冒烟：`tools/smoke-godot.sh` 依次跑标题菜单、标题鼠标点击、
  键码映射、零售存档读档、读档界面、新游戏存档往返，`smoke: pictures=4 sprites=4` +
  `mouse_title: ... reached_map003=true` + `key_map: checks=98 failures=0` +
  `load_save: pictures=50 texts=14` + `load_menu: ... pictures=50 texts=14` +
  `roundtrip: ... resumed_pictures=38`，exit 0。

### P2 输入 / 文字 / 长程 parity（2026-11-10）

- **输入桥接**：`godot/scripts/WolfKeys.gd` 完整镜像 `wolf-cli play` 的
  `raw_key_code()` / `fixed_bit()` / `App::bits()`：Godot 物理键 -> WOLF
  scancode+100（Z=144/X=145/C=146、Enter=128、Backspace=114、Escape=101、
  Space=157、方向 172/180/175/177），并在每帧用 `WolfGame.key_config()`
  （Sys52/54/56）实时组合 OK/CANCEL/SUB。`GameView.gd` 用 `_input` 跟踪
  `physical_keycode`（失焦清空、忽略 echo），把原始键码数组传给 `set_input`。
  `godot/tests/key_map.gd` 97 项断言全部通过，覆盖改键后 Z/X 互换。
  **行为修正**：Space 不再默认当决定、Shift 不再默认当副键，与 `play.rs` /
  说明书（决定 Enter/Z/左键，取消 Backspace/X/右键）一致。
- **读档界面端到端**：`godot/tests/load_menu.gd` 从 `boot()` 的标题菜单
  （83 帧出现 menu1/2/3）用真实 Down/Enter 输入进入 CE14 -> CE131：
  110 帧后读档画面 28 picture；两次 Down 落到空槽 3（确认不加载，证明两次输入
  都生效），再两次 Up + Enter 加载 SaveData01；取消后退回卧室，
  **pictures=50 / texts=14**，诊断含 `220 SaveLoad: loaded`，且不产生
  SaveData03。路径与 Rust `m3_save_ui_roundtrip` 的 LOAD phase 一致。
- **文字校准**：`godot/scripts/WolfText.gd` 用实测度量替代旧的
  `line_spacing=size*0.25`：
  - Rust 参考基线 = `round(rect.y) + round(size * 1.023193359375)`（cosmic-text
    行盒 `1.25*size`、msyhbd face0 hhea A=2167/2048、D=536/2048）；
  - Godot 第一行基线 = `rect.y + FontFile.get_ascent(size)`（= ceil(1.058105*size)），
    故补 `baseline_shift = round(size*1.023193) - ascent`（14/16 -> -1，
    18/20 -> -2，24/32 -> -1，36/40 -> -2）；
  - x/y 都显式取整（Godot 截断、Rust 取整）；行距 =
    `round(1.25*size) - get_height(size)`（20px 为 -3）；
  - `\E` 描边改为与 Rust 同构的 ±2px 四份黑字；宽度 +2px 防 FreeType 折行。
  - 实测（同一帧 Godot vs Rust）：
    | 场景 | 全局 MAE | ±8 | 文字区 MAE | 文字区 ±8 |
    |---|---|---|---|---|
    | 新游戏 600 帧 HUD | 0.769 -> **0.368** | 99.28 -> **99.45%** | 3.674 -> **1.749** | 96.55 -> **97.36%** |
    | 零售读档 120 帧 HUD | 0.888 -> **0.423** | 99.17 -> **99.36%** | 4.246 -> **2.009** | 96.00 -> **96.95%** |
    | 消息 300 帧 | 2.191 -> **0.594** | 98.48 -> **99.14%** | 26.92 -> **7.30** | 81.26 -> **89.40%** |
  - 标题菜单无 text item，仍为 99.779% 像素一致 / max 1；文字 rect 外 changed
    px=0，无非文字回归。消息三行 ink 行 y 与 Rust 完全一致，最佳平移 (0,0)。
- **长程 parity**：`tools/parity-godot.sh` + `godot/tests/parity_stats.gd`
  在 600/1200/1800 帧逐项对齐 Rust `capture --menu-only --answer 0`：

  | 帧 | instructions | pictures | messages | choices | warnings | sounds |
  |---|---|---|---|---|---|---|
  | 600 | 16038 / 16038 | 4526 / 4526 | 15 / 15 | 3 / 3 | 0 / 0 | 3 / 3 |
  | 1200 | 43938 / 43938 | 14726 / 14726 | 15 / 15 | 3 / 3 | 0 / 0 | 3 / 3 |
  | 1800 | 71838 / 71838 | 24926 / 24926 | 15 / 15 | 3 / 3 | 0 / 0 | 3 / 3 |

  600 帧像素 **MAE 0.3680 / ±8 99.45% / ±32 99.67%**（文字校准后），差异只
  在 HUD 文字 bbox `(36,11)-(1000,104)`。读档模式 120 帧同样逐项一致
  （19267 指令 / 2055 picture / 0 message / 0 choice / 0 warning / 0 sound）。
  `unmodelled=1`（`270 Party` 只记录参数）Rust 侧也是同一条 diagnostic，
  不算分歧。
- **过渡审计**：扫描全部 8 张 `.mps`，`161/162` 只出现在**未注册**的
  `SampleMapB.mps` ev2 page0（trigger=3 PlayerTouch，编辑器示例）；本作注册的
  5 张图（TitleMap/SampleMapA/Map003/Map024/Map031）没有 160/161/162。
  因此冻结帧过渡在本作正式流程不可达；`ScreenTransition` 实现保留，由
  `m3_visual_text` 单元测试覆盖。`kind >= 0` 的掩膜过渡同样不触发。

### P2 补丁：标题高亮 / 滚轮 / 鼠标锁存 / 确定性捕获（2026-11-10）

- **标题高亮**：CE43 是“画一次就结束”的渲染器，启动时只读一次 Sys20；旧调度
  是边沿触发，光标变化不会重跑。`Game::frame` 现在在标题光标变化时调用
  `AutoEvents::restart(43)`，深色 `menu*_a` 随上下键、滚轮和鼠标悬停移动。
  实测 `menu*_a` 比 `menu*_b` 暗（平均亮度 62/69 vs 104/127），与用户口径一致。
- **滚轮**：`GameView` 从 `InputEventMouseButton` 累计 notch，`WolfGame.set_wheel`
  交给 `Game::apply_wheel`：op102 选项直接移动光标；CE131 存档网格注入
  LEFT/RIGHT 页键（`self[610..613]` 的页状态与手动左右键逐字节等价）；其它
  `123` 菜单注入 UP/DOWN。注入位只存在一帧，下一帧不会变成“按住”。
- **鼠标锁存**：快速点击（按下+松开都在两个物理帧之间）不再丢失：
  `_input` 锁存按下到下一物理帧，并保存按下时的 logical 坐标供地图热点命中；
  右键取消走同一条边沿。失焦清空键/鼠标/滚轮状态。
- **字体 fallback 实验（已回退）**：把 `seguisym.ttf` 挂到 msyhbd/msyh 的
  `fallbacks` 后，Godot 的整段文字度量被改写，新游戏 600 帧像素 MAE 从
  **0.368 涨到 3.11**。扫描 1,218 条静态消息/选项（21,009 字符）后，msyhbd
  只缺 5 个私用区/乱码码点，正常对话不缺字形；因此保持 fallback 关闭。
- **确定性捕获**：`--capture` 到达目标帧后先 `set_physics_process(false)`，
  再等 `frame_post_draw`；否则 physics 可能在 await 期间多走一帧，捕获到
  N+1 的动画相位（左侧 25px 竖条差）。修复后 parity 像素稳定在 **MAE 0.3680**。
- **测试**：新增 `crates/wolf-game/tests/m6_title_wheel.rs`（标题高亮 +
  方向键/滚轮；滚轮与 CE131 左右页键的网格状态逐字节相同）、
  `godot/tests/mouse_latch.gd`、`godot/tests/title_wheel.gd`、
  `godot/tests/gameview_title_wheel.gd`，全部进 `tools/smoke-godot.sh`。
- **存档 fixture**：玩家存档会覆盖 `work/Data/Save/SaveData01/02.sav`，视觉
  基线随即失真。本轮已把玩家存档备份到 `work/out/player_saves_2026-11-10/`，
  并用 50-picture 出货状态恢复 Save 目录；`m14_visual_regression` 增加
  `depends_on_save` 守卫，以后玩家再覆盖 SaveData01 时跳过依赖它的三个场景。

### 2026-11-12 深度审查补丁与 T13 瓦片退场

- **历史方案（T12，已由 T13 删除；不得作为当前验收）**：`WolfGame::frame()` 曾把
  19k–27k 个 tile quad 烘焙成一张 1024×576 RGBA8 纹理；缓存键为
  `(tilemap generation, atlas revision, autotile phase)`，packet 曾带
  `tile_pixels` / `tile_revision` / `tile_quads` / `tile_tint`，`GameView` 曾先画
  1 张瓦片纹理再画动态 picture/text。当时读档 60 帧约 0.42 s、600 帧约 0.61 s，
  `m14_visual_regression` 5/5，`parity-godot.sh 600` PASS；`max_sprites` 曾按
  dynamic sprites + tile_quads 统计为 27,653。上述实现、packet 字段和
  `t12_tile_bake*` 测试均已被 T13 删除，`Atlas::composite_tile_layer()` 也不在
  当前源码中；这些数字只保留为历史证据。
- **当前方案（T13）**：`wolf-gdext` / `GameView.gd` 不请求、不接收也不绘制
  `tile_quads` / `tile_pixels` / `tile_revision` / `tile_tint`，玩法前端每帧只发
  picture、text 与 HUD；`Game::tile_quads()`、`Atlas` 合成与 CLI
  `capture --map` 仍保留给取证/诊断。不要再把“每帧 1 个瓦片 quad”“27,653 sprites”
  或 tile packet 写成当前实现。
- **Atlas 上传**：早期整页 4096² RGBA8 上传为 **64 MiB/次**，是启动/菜单 hitch
  的历史来源；T13 已改为只发送已打包内容的包围盒。当前
  `m17_render_regressions` 示例为 2607×576 / **5.7 MiB**，19:07 读档 600 帧为
  `sync_uploads=1` / `sync_MiB=4.1`、`wolf_avg_ms=0.443`、`draw_avg_ms=0.302`、
  `physics_avg_ms=0.752`（历史日志 `work/out/t13_final_loadsave_600.log`）。最终
  DLL（20:09:05，SHA-256 `fee3e727…efadd1`）已重跑：读档 180 帧
  `wolf_avg_ms=0.565` / `draw_avg_ms=0.287` / `sync_MiB=4.1`，新游戏 300 帧
  `wolf_avg_ms=0.342` / `draw_avg_ms=0.058`；smoke 全绿、parity 600 PASS。
- **混合/退出**：`SpriteQuad.blend` 经 atlas/gdext 透传到 `GameView.gd` 的
  ADD/SUB/MUL 批处理；`save_settings()` 在窗口关闭/退出树时持久化，CE132
  本身仍不写盘。
- **标题**：CE43 现在是标题菜单进入沿的一次性渲染器，Godot 标题菜单匹配
  Rust 的 4-picture 状态；鼠标/滚轮高亮仍通过显式 restart 重绘。

## 5. 已知缺口

- 文字几何已对齐，剩余差异来自栅格器：Rust swash hinting vs Godot FreeType
  light hinting，消息区 MAE 7.30 / 单 item 6.6-19，最佳平移已经是 (0,0)。
  试过 `hinting=none`（消息 7.30 -> 6.97，但 HUD 1.749 -> 1.795），未全局启用。
- **Godot 全局字体 fallback 不可用**：给 msyhbd/msyh 挂 `seguisym.ttf`
  会把整段文字度量改掉（600 帧 MAE 0.368 -> 3.11）。正常对话字形覆盖足够
  （21,009 字符只缺 5 个私用区/乱码码点）；真遇到缺字要按字符分段用 fallback
  画，不能挂全局链。
- `weight=400` 潜在不一致：gdext 对存档槽 data/time/name 行发 weight 400；
  Rust 的 fontdb 只装 `msyhbd.ttc`（face 全是 700），实际仍画粗体；Godot
  的 WolfText 按 <600 选 `msyh.ttc` 常规。三组验收捕获全是 weight 700，
  未触发；需要存读档界面像素对照后再决定是否统一为 bold。
- 多行 `TextParagraph` 折行路径只做了度量验证，捕获里每个 packet item 都是
  单行（行盒由 wolf-game 预先切好）；Rust 的 scissor 裁剪未在 Godot 复刻，
  当前数据字形未越界。
- `161` 冻结帧过渡：全量 `.mps` 扫描只在未注册的 `SampleMapB.mps`
  （PlayerTouch 示例）出现，正式注册图没有，故本作不可达；实现与单测保留。
- 新建存档的 Part1 静态字段已与零售对齐；`var10/12/15/16/19/21/23/24` 等
  运行态字段用默认值（零售两存档本身也不同），不影响本作 resume。
- 读档界面已从 Godot 输入走通；**游戏内存档点**（`SampleMapA ev5 "セーブ"`
  调 CE14）尚未做脚本化端到端写槽验证——需要先把角色移动到存档点再做 OK。
- 数据根仍是外部目录；P3 才做导出打包。

## 6. 下一步

1. 游戏内存档：驱动 `SampleMapA ev5 "セーブ"`（action trigger，调 CE14）走
   CE131 的 save 模式，选空槽写入 `SaveData03`，再读回；覆盖移动/OK 输入与
   存档点命中。
2. 文字：用存读档界面做一次像素对照，确认 `weight=400` 该用 bold 还是
   regular；若需进一步压消息区 MAE，再评估 hinting 策略。
3. 存档 Part1 运行态字段（图形/方向/路线/页表）补全；当前最小字段已能让
   本作 resume。
4. 长程 parity 扩到日常循环/结局链，并加入变量/事件轨迹对照（不只统计计数）。
5. 导出打包：把 `Data/` 与 DLL 一起放进 P3 发行包。

## 7. 坑与约定

- **gdext 版本**：`godot = "0.5.5"`，feature `api-4-7`；与 Godot 4.7.2 已实测可加载。
  若换 Godot 小版本，先改 feature 并重跑 `--import`。
- **离线 API**：本机已用
  `Godot --headless --dump-extension-api` 生成 `work/out/godot_api/extension_api.json`；
  gdext 0.5.5 自带 4.7 API，不联网也能构建。
- **Windows DLL 锁**：Godot 正在运行时无法覆盖 `godot/bin/wolf_gdext.dll`；先关窗口/
  编辑器再 `tools/build-godot.sh`。
- **headless 不能出像素**：`--headless` 用 dummy 渲染，`get_viewport().get_texture()
  .get_image()` 拿不到画面；VM 统计可以 headless 紧密循环，像素捕获必须开窗口
  （`parity-godot.sh` 的像素检查约 N/60 秒实时）。
- **GDScript 类注册**：`WolfText.gd` / `WolfKeys.gd` 在 `GameView.gd` 里用
  `preload("res://scripts/...")` 引用，不依赖 `.godot` 的全局 class 扫描。
- **load_menu 前置**：需要 `Save/SaveData01.sav`；若 `SaveData03.sav` 存在，
  测试会跳过「空槽确认」探针，避免误加载别的测试存档。
- **捕获必须冻结时钟**：`--capture` 达到目标帧后会关闭 `_physics_process`；否则
  物理帧在 await 期间前进一帧，动画相位/像素基线会漂。
- **SaveData01/02 是可变的**：玩家保存会覆盖 `work/Data/Save/`；视觉基线要求
  50-picture 出货状态。玩家存档备份在 `work/out/player_saves_2026-11-10/`，
  `m14_visual_regression` 的 `depends_on_save` 守卫会在 fixture 漂移时跳过。
- **滚轮语义**：标题/op102 选项直接移动光标；CE131 存档网格滚轮 = 左右页键
  （上滚上一页、下滚下一页），不是逐槽滚动。
- **不要提交**：`godot/.godot/`、`godot/bin/*.dll`、`work/`。`.gdextension`
  配置文件要提交。
- **数据根不要进工程**：`work/Data` 176 MB，继续 gitignore；玩家侧后续用外部
  `Data` 目录或导出包内 `Data/`。
- 本文件只记录迁移层；WOLF 语义仍以 `docs/HANDOFF_M0.md`、`docs/ENGINE_BEHAVIOR.md`
  和 `docs/BASELINE.json` 为准。
