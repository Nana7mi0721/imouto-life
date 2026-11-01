# M5 — 超越原版

状态：**M5-A..F 已完成第一切片；M5-D2（翻译工具/上下文键）与 M5-E2（mod 清单/依赖/文本级补丁）已完成**。M0–M4 已交付；M5 的目标是在数据级重写与
逐像素对等之外，补上原版没有、玩家实际能感知的能力。

| 切片 | 内容 | 状态 |
|---|---|---|
| M5-A | 高分辨率与无级缩放（窗口 fit / 全屏） | 已完成第一切片 |
| M5-B | 运行时调试器（F3 overlay） | 已完成第一切片 |
| M5-C | 游戏倾向 / 里程碑汇总面板（F2 overlay） | 已完成第一切片（实时读取存档变量，无独立成就存档） |
| M5-D | 多语言文本层（中/日/英） | 已完成（含 D2 工具与上下文键） |
| M5-E | Mod 数据/音频覆盖层 | 已完成（含 E2 清单/依赖与文本级补丁） |
| M5-F | 消息回顾（F4 转录） | 已完成第一切片（运行期保留最近 200 条，分页回看，不写存档） |

## M5-A：高分辨率与无级缩放

原版逻辑画布固定为 **1024x576**，WOLF 的 op150 坐标、消息窗口和地图图层都按这个
坐标系授权。本切片只改变最后的 blit（逻辑帧 -> 窗口），不改任何游戏坐标或存档。

### 玩家用法

```bash
# 默认：整数倍最近邻（1080p 下是 1x、加黑边，保持零售像素网格）
wolf-cli play --load-save work/Data/Save/SaveData01.sav

# 分数 fit：铺满 16:9 窗口；nearest 保留硬像素，linear 更平滑
wolf-cli play --load-save work/Data/Save/SaveData01.sav --scale fit-nearest
wolf-cli play --load-save work/Data/Save/SaveData01.sav --scale fit-linear

# 无边框全屏
wolf-cli play --load-save work/Data/Save/SaveData01.sav --fullscreen
```

运行中热键：

- **F9**：integer -> fit-nearest -> fit-linear -> integer 循环；
- **F11**：无边框全屏开关；
- **F10**：退出（沿用既有绑定，不改）；
- **F12**：重开标题（沿用既有绑定）。

窗口标题会显示当前因子（如 `1.875x fit-nearest`）与 windowed/fullscreen。

### 实现

- `crates/wolf-render/src/scaler.rs`
  - 新增 `ScaleMode`：`Integer`（默认）、`FitNearest`、`FitLinear`，带 `parse`、
    `label`、`next`、`is_fit`。
  - 新增 `FitScaler { scale: f32, offset: [f32;2], used: [f32;2] }` 与
    `fit_scale(win_w, win_h)`：`scale = min(w/1024, h/576)`，允许 <1（小窗口完整显示），
    计算精确的分数偏移和 NDC quad。
  - `Scaler::game_point` / `FitScaler::game_point` 提供 blit 的逆映射；
    `Renderer::window_to_game` 按当前模式调用，鼠标位置在 fit 模式下仍然准确。
- `crates/wolf-render/src/renderer.rs`
  - blit sampler 由单个 nearest 改为 **nearest + linear 两个 sampler**，对应两个
    bind group；`ScaleMode::FitLinear` 才走 linear，其余走 nearest。
  - `present()` 根据模式选择 `Scaler::ndc_quad` 或 `FitScaler::ndc_quad`。
  - 新增 `set_scale_mode` / `scale_mode` / `fit_scaler` / `scale_factor` /
    `window_to_game`。
- `crates/wolf-cli/src/play.rs`：`DisplayOptions { mode, fullscreen }`；启动时设置窗口
  fullscreen 与 renderer 模式；F9/F11 热键；窗口标题显示模式与因子；鼠标走
  `Renderer::window_to_game`。
- `crates/wolf-cli/src/main.rs`：`--scale <integer|fit-nearest|fit-linear>`、
  `--fullscreen` 参数与帮助文本。没有新增外部依赖。

### 测试

`crates/wolf-render/src/scaler.rs` 新增纯函数测试：

- `fit_scale_uses_the_whole_16_by_9_window`（1080p/1440p/4K 全屏且无黑边，
  1.875/2.5/3.75 因子）；
- `fit_scale_shrinks_a_small_window_instead_of_clipping_it`（1000x700 -> 0.9766x，
  used 1000x562.5，上下 68.75 黑边）；
- `fit_ndc_quad_covers_the_screen_and_keeps_the_aspect_ratio`；
- `the_window_to_game_mapping_is_the_inverse_of_the_blit`；
- `scale_mode_parses_and_cycles`。

验收：

```bash
cargo test -q -p wolf-render --lib
cargo build -q -p wolf-cli
cargo test -q -p wolf-cli
```

### 边界

- `capture` 仍输出 **1024x576 逻辑帧**，不受窗口 fit 影响；这是刻意的：capture 的 PNG
  用来和原版逐像素比较，不能把窗口缩放混进证据链。
- 窗口/全屏的实际观感需要真实窗口；headless capture 不模拟 swapchain blit。
- 不改 `Sys 104/105` 相机，不改存档或游戏坐标。

## M5-B：运行时调试器（F3 overlay）

### 玩家用法

```bash
# 启动时显示调试层
wolf-cli play --load-save work/Data/Save/SaveData01.sav --debug

# 顺带观察若干变量（平面槽 154 或脚本 magic 地址 2000350 均可）
wolf-cli play --load-save work/Data/Save/SaveData01.sav --debug --debug-var 154,155,2000350

# 运行中按 F3 开关调试层；F9/F11 仍控制缩放/全屏，F10 退出、F12 重开
```

overlay 固定画在逻辑画布左上角，列出：帧号、fps、已执行指令数、picture 命令数、
warning 数、当前 sprite/text 数、鼠标位置（或 outside）、鼠标键位、WOLF 键位、
最近一次 map/action 事件，以及 `--debug-var` 指定的变量值。文字沿用游戏主字体
（含 Segoe UI Symbol fallback），黑边白字，不引入新的 GUI 依赖。

### 实现

- `crates/wolf-cli/src/play.rs`
  - 新增 `DebugOptions { overlay, vars }` 与 `DebugOptions::default()`。
  - `run(..., display, debug)` 把选项存进 `App { debug_overlay, debug_vars, fps }`；
    `--debug-var` 非空时默认打开 overlay。
  - `build_text_items` 在消息文本之后追加 `DebugSnapshot` 的纯文本行，
    每行一个 `TextItem`（16 px、白字、2 px 黑边），因此和游戏文字共用同一 glyph pass。
  - `F3` 切换 `debug_overlay` 并打印状态；fps 每秒从 `fps_frames` 结算到 `fps`。
  - `parse_debug_vars("154, 155,, 2000350")` 接受逗号/空格/空项，拒绝非数字；
    `debug_slot` 把 `2_000_000 + n` 归一成平面槽 `n`。
- `crates/wolf-cli/src/main.rs`：`--debug`、`--debug-var <ADDR,...>` 与帮助文本；
  未新增外部依赖。

### 测试

- `play::tests::debug_overlay_reports_frame_pointer_and_watched_vars`（字段/变量行格式）；
- `play::tests::debug_overlay_marks_an_outside_pointer_and_no_event`；
- `play::tests::parse_debug_vars_accepts_commas_and_rejects_garbage`；
- `play::tests::debug_slot_accepts_flat_and_magic_addresses`。

验收：`cargo test -q -p wolf-cli`；实际窗口 smoke：
`wolf-cli play --load-save work/Data/Save/SaveData01.sav --scale fit-nearest --debug --debug-var 154,155 --until 5`。
headless capture 仍输出不带调试层的 1024x576 证据帧。

### 边界

- overlay 只在 `play` 窗口里存在；`capture` 不画它，保持像素证据链纯净。
- 只读状态，不改 VM、变量或存档；变量越界按 `Variables::get` 的默认值显示。
- 不做 console/远程调试协议；后续若需要可另开切片。

## M5-C：游戏倾向 / 里程碑汇总（F2 overlay）

原版 CE296 的「■プレイ傾向」把文本写死在事件脚本里，且只显示四到八行。本切片在
不修改 CE296、不改存档格式的前提下，从同一组权威变量读取一份结构化快照，并在
play 窗口叠加显示（F2 开关）。第一切片是实时统计 + 里程碑，不是独立成就存档：
解锁状态每帧按当前变量重算，因此换存档/新游戏都会即时变化。

### 变量来源（已由 m3_stats_collection 钉住）

| 字段 | 变量 | 含义 |
|---|---|---|
| days | v99 | 経過日数 |
| trust | v20 | 妹信頼度 |
| interest | v21 | 妹性興味 |
| sensitivity | v22 | 妹感度 |
| mood | v23 | 妹機嫌 |
| alert | v154 | 警戒度 |
| interactions | v187 | イカせた回数（显示为“共同经历”） |
| cleared | v199 | クリア |
| hundred_days | v201 | 100日到達 |
| pants_complete | v202 | パンツコンプリート |

### 玩家用法

    # 启动时显示统计/里程碑层（运行中按 F2 开关）
    wolf-cli play --load-save work/Data/Save/SaveData01.sav --stats

    # 也可以与 F3 调试层同时打开；两层按行顺序堆叠，不会互相覆盖
    wolf-cli play --load-save work/Data/Save/SaveData01.sav --debug --stats

overlay 顶部两行是统计摘要与成就计数，下面每条 [x] 标题 - 说明 是里程碑；未解锁
显示灰色，已解锁显示绿色。全部是文字，沿用游戏字体与 fallback，无新依赖。

### 实现

- 新增 crates/wolf-game/src/achievements.rs：
  - PlayStats { days, trust, interest, sensitivity, mood, alert, interactions,
    cleared, hundred_days, pants_complete }，from_vars(&Variables) 按上表读取；
  - Milestone { id, title, detail, unlocked } 与 milestones(&PlayStats)：9 条
    保守里程碑（10/30/100 天、信赖 100/350、兴致 100、共同经历 10 次、服饰收集、
    完成流程）。阈值直接沿用 CE296 的 100/200/350 分档，不凭报告臆造。
- crates/wolf-game/src/lib.rs 导出 achievements、PlayStats、Milestone、milestones。
- crates/wolf-game/src/game.rs 新增只读 Game::play_stats() 与 Game::milestones()。
- crates/wolf-cli/src/play.rs：DebugOptions 增加 stats 字段、App.stats_overlay、
  stats_lines(&PlayStats, &[Milestone]) 负责行/颜色；F2 切换；与 F3 层按行堆叠。
- crates/wolf-cli/src/main.rs：--stats 参数与帮助文本；未新增外部依赖。

### 测试

- achievements::tests::play_stats_reads_the_authoritative_slots；
- achievements::tests::milestones_unlock_from_thresholds_and_flags；
- achievements::tests::a_fresh_game_has_no_milestones；
- play::tests::stats_overlay_reports_progress_and_milestones（摘要行、成就计数、
  绿色/灰色颜色）。

验收：cargo test -q -p wolf-game --lib 246 passed；cargo test -q -p wolf-cli 18 passed；
窗口 smoke：play --load-save work/Data/Save/SaveData01.sav --scale fit-nearest --stats --until 5。
headless capture 仍输出不带 overlay 的 1024x576 证据帧。

### 边界

- 第一切片不写独立成就文件、不改 Save/System.sav；解锁状态完全由现有存档变量决定。
- 变量越界按 Variables::get 返回 0；不使用可空或猜测变量。
- 后续若要做跨周目永久成就，再单独设计新存档字段与迁移，不与本次混在一起。

## M5-D：多语言文本层（内容翻译目录）

原版把中文对白和选项写死在数据里，换语言只能改包。本切片不改任何数据文件，而是增加
一个 side-car 目录，在 opcode 101 消息和 opcode 102 选项离开 VM 后按精确字符串替换。
这样同一份数据可以配不同语言目录，且不改存档或地图坐标。

### 玩家用法

    # Play with an English sample catalog
    wolf-cli play --load-save work/Data/Save/SaveData01.sav --translation docs/translations/en.tsv

    # Headless capture with the same catalog (the night menu shows the translated choices)
    wolf-cli capture --load-save work/Data/Save/SaveData01.sav --event 245 \
        --translation docs/translations/en.tsv --frames 90 --out work/out/night_en.png

### 实现

- 新增 crates/wolf-game/src/translate.rs：
  - Translator { entries: HashMap<String, String> }；parse(text) / load(path)；
    translate(text) 精确匹配，未命中返回 None；len/is_empty。
  - 目录是 UTF-8 TSV（original<TAB>translation），支持 # 注释、空行、\n \t \\ 转义；
    重复键后者覆盖前者；错误带物理行号。
- crates/wolf-game/src/game.rs：Game 新增 translator 字段（默认空）和
  set_translator / load_translation_file / translation_len；GameHost::show_message 与
  show_choices 在生成 Message/Choices 前应用目录；未命中保持原脚本。
- crates/wolf-cli/src/main.rs 与 play.rs：--translation <FILE> 贯通 play、capture、
  capture --map/--map-run；play 的 F12 重启会重新加载同一目录。
- docs/translations/en.tsv、ja.tsv 是只覆盖夜菜单六项的示范目录；完整翻译属于内容
  作者/社区工作，不需要改代码。没有新增外部依赖。

### 测试

- translate::tests 5 条（注释/转义、重复键、无 TAB 行号、空源、未命中回退）；
- game::tests::a_translation_catalog_rewrites_messages_and_choices（消息与选项都替换，
  未命中文本保持原样）；
- capture 实测：--translation docs/translations/en.tsv 输出
  choice ["Start a chat", "Make tea", "Take a bath", "Shop online", "Turn in for today", "0"]，
  90.4% 非黑、0 warning。

### 边界

- 只做精确字符串替换，不做正则/模糊匹配；漏译自动回退原文，不会空白。
- 只覆盖 opcode 101 消息与 opcode 102 选项，不覆盖图片内文字、F2/F3 overlay 标签。
- 目录语言不限，中/日/英都只是同一格式的文件；完整词条需要人工整理。

## M5-D2：翻译目录工具与上下文键

第一切片只有一个固定的精确匹配表；要判断「还差多少句」只能靠人工。第二切片补上
authoring 工具和更细的匹配键，仍然不改数据、不写存档。

### 玩家/译者用法

```bash
# 统计脚本里的字面文本
wolf-cli translations --root work/Data

# 生成待翻译模板（右列为空）
wolf-cli translations --root work/Data --template work/out/i18n_template.tsv

# 检查现有目录覆盖率；--strict 在有静态句未翻译时退出 1
wolf-cli translations --root work/Data --check docs/translations/en.tsv
wolf-cli translations --root work/Data --check docs/translations/en.tsv --strict
```

实测本作：**1,218 条静态字符串**（1,046 消息 + 172 选项）、**46 条变量相关字符串**、
1,476 个静态出现点（同一句在多个事件里计多次）。`en.tsv` 的 5 条夜菜单示例覆盖
5/1,218，`--strict` 正确返回 1。

### 上下文键

左列可以加前缀，只命中对应上下文：

    [msg]同じ台詞	Spoken line
    [choice]同じ台詞	Menu label
    同じ台詞	Both contexts (fallback)

带前缀的条目优先于无前缀条目；另一种上下文仍回退到无前缀条目。解析器仍做精确
匹配，不做正则或模糊匹配。

### 模板语义

- 模板每行是 `原文<TAB>`，右列为空；**空翻译列被解析器忽略**，所以模板本身可以
  直接交给 `--translation` 而不会把游戏文本清空。
- 原文列逐字匹配（解析器不对原文做反转义）；原文含真实 TAB/CR/LF 的条目会跳过，
  并在模板头注明条数。
- 不含变量的 `\c[6]`、`\n`、`@1` 等显示标记保留在原文里，照常精确匹配。
- 含 `\v[12]`、`\self[3]` 等变量转义的字符串运行时文本不固定，因此不进入模板，
  也不计入覆盖率分母；工具单独报告这类字符串数量。

### 实现

- `crates/wolf-game/src/translate.rs`：`Context`、`Translator::translate_in`、
  `[msg]`/`[choice]` 前缀、空翻译占位、`keys/has_in/merge`；
  `SourceScan::from_common_events` 遍历全部事件，收集 101/102 字符串，
  用 `wolf_vm::text::expand(..., NoVars)` 区分静态与变量相关，
  并剥掉消息的 `@n` 说话人前缀（与 VM 的 `split_face` 一致）。
- `SourceScan::template()` / `coverage()`；`Coverage` 报告静态总数、已覆盖、缺失、
  动态总数与未命中目录项。
- `crates/wolf-cli/src/main.rs`：`translations` 子命令、`--template`/`--check`/`--strict`；
  读取 CommonEvent.dat 时走 mod overlay，和运行时同一份文件。
- 单测覆盖前缀优先级、空翻译、模板占位、覆盖率与未命中项；
  `crates/wolf-game/tests/m5_translation_scan.rs` 在真实数据上验证 1,000+ 条静态句、
  夜菜单选项、模板可解析且为空目录。

### 边界

- 仍是精确匹配；同一句在不同上下文语义不同时用前缀区分，不做自动语义判断。
- 只覆盖 opcode 101/102 文本，不覆盖图片内文字与 overlay 标签。
- 完整语言包仍是内容工作；工具只保证「不漏句、不瞎翻」。

## M5-E：Mod 数据/音频覆盖层

原版把地图、公共事件、数据库、图片和 BGM/SE 都放在安装目录的数据树里，改一个文件就得备份整包。
本切片增加可重复的 --mod 目录：每个目录镜像数据树的相对路径，只放要改的文件；
运行时先查 mod，未命中再回落 base。这样地图、事件、数据库、美术和音频都能像资源包一样替换，
又不需要改 exe 或复制 175MB 数据。

### 玩家用法

    # 一个改了 SampleMapA、状态面板图和一首 BGM 的 mod
    wolf-cli play --load-save work/Data/Save/SaveData01.sav --mod mods/example

    # 多个 mod：后面的目录优先
    wolf-cli play --mod mods/base --mod mods/override

    # capture 同样接受 --mod，便于离线核对
    wolf-cli capture --map SampleMapA --mod mods/example --frames 60 --out work/out/map.png

mod 目录示例（相对路径与数据根一致）：

    mods/example/BasicData/CommonEvent.dat
    mods/example/BasicData/SysDatabase.dat
    mods/example/MapData/SampleMapA.mps
    mods/example/Picture/status01.png
    mods/example/BGM/theme.ogg
    mods/example/SE/click.ogg

也可以把 BasicData 省掉，直接写 mods/example/Game.dat 或 mods/example/MapData/...；
两种布局都会先查 BasicData/name，再查 name。

### 实现

- crates/wolf-game/src/assets.rs：Assets 新增 overlays 字段和 with_overlays；resolve
  按 overlays 逆序 + base 依次查同一相对路径，原大小写不敏感探测逻辑保留在 resolve_in。
- crates/wolf-game/src/game.rs：Game 新增 overlays 字段与 with_overlays；
  CommonEvent.dat / Game.dat / TileSetData.dat 通过 layered_path 读取；Game::read 让
  MapData 等运行期路径也走 overlay；resume_loaded_map 扫描 overlay 的 MapData；
  Assets::with_overlays 统一接管图片。
- crates/wolf-game/src/db.rs：Databases::load_with_overlays 读 DataBase、CDataBase、
  SysDatabase 及其 .project，overlay 优先、缺文件回落 base；原 load 保持为无 overlay 包装。
- crates/wolf-cli/src/main.rs / play.rs：新增可重复 --mod <DIR>，贯通 play、capture、
  capture --map/--map-run；play 的 F12 重启会保留同一组 mod；地图 capture 的预读
  TileSetData/mps 也走 overlay，避免只有 Game 内部生效、命令行预检仍读 base。
- crates/wolf-audio/src/engine.rs：Engine 新增 overlays 字段与 with_overlays；resolve
  按 overlays 逆序、当前目录、base、base/Data 查同一 BGM/SE 相对路径。
  Game::enable_audio 把同一组 mod 传给音频引擎，因此 play/capture 的 BGM/SE 也走 overlay；
  混音、音量、淡入/延迟与 SoundCmd 语义完全不变。
- 写存档、Save/System.sav、Save/*.sav 始终写 base 根，不写回 mod；overlay 只影响读取。
- 没有新增外部依赖；mod 不需要脚本或安装器，只是目录布局约定。

### 测试

- assets::tests::a_mod_overlay_wins_over_the_base_asset：base 1x1 黑图与 overlay 2x1
  两色图，Assets::with_overlays 后读到 overlay 的尺寸与像素，Assets::new 仍是 base。
- crates/wolf-game/tests/m5_mod_overlay.rs：真实数据下 base status01 为 330x576，
  overlay 换成 2x1 PNG 后 Game::with_overlays 读到 (2,1) 且像素正确，base Game 不变。
- wolf-cli tests::later_mod_overlays_win_and_missing_files_fall_back：后置 overlay 优先、
  缺文件回落 base、BasicData 嵌套布局与 MapData 相对路径都覆盖。
- crates/wolf-audio/tests/m5_audio_overlay.rs：后置 overlay 的 BGM 优先、早置 overlay 的 SE
  可命中、base 仅有的文件回落、缺失返回 None、反斜杠路径与绝对路径都覆盖。
- wolf-game/tests/m5_mod_overlay.rs 第二条：Game::enable_audio 后的音频引擎拿到同一组
  overlays，并能把 BGM/theme.ogg 解析到 mod 目录。
- capture 实测：--mod 目录放一份相同 status01 时输出与无 mod 逐字节相同；
  放一张 330x576 纯色替换图时输出与基准不同（95.4% 非黑、0 warning），证明覆盖真正生效。

### 边界

- 只覆盖数据文件，不覆盖 exe、脚本运行器或渲染参数；mod 不能注入新 opcode。
- 第一切片按整文件替换，不做逐行/逐记录合并；mod 要改 CommonEvent.dat 就得提供完整文件。
- BGM/SE 也按整文件覆盖；不重编码、不改混音/音量/淡入语义，mod 里的音频格式仍须被
  wolf-audio 解码器支持（ogg/mp3/wav）。
- 存档格式与 base 完全一致；读档时地图对象匹配会同时扫描 overlay 与 base 的 MapData。

## M5-E2：Mod 清单、依赖与文本级补丁

第一切片按目录整体覆盖，无法声明「我是谁、我依赖谁」，想改一句台词也只能替换整个
`CommonEvent.dat`。第二切片补上一个可选的 `mod.ini`，并让每个 mod 可以带一份文本
目录补丁。

### 清单格式

`<mod 目录>/mod.ini`，UTF-8，`key=value`，支持 `#` / `;` 注释：

    # mods/example/mod.ini
    name=Example Mod
    version=1.0
    requires=base-ui, extra-maps

- `name` 缺省时用目录名；同一组 `--mod` 里名字必须唯一。
- `requires` 用逗号/空白分隔；每一项必须出现在同一组 `--mod` 里。保留名 `base`
  表示未修改的原始数据，永远满足。
- 依赖只做校验，不重排加载顺序：`--mod` 的先后就是覆盖优先级（后者优先），
  避免隐式改序让玩家看不懂。
- 错误会在加载数据前报出：清单语法/未知键、重名、保留名 base、自依赖、缺依赖。
- 没有 `mod.ini` 的目录照旧可用，目录名就是 mod 名。

启动时 play/capture 会打印实际加载的清单：

    mod: Example Mod 1.0 (mods/example)

### 文本级补丁

每个 mod 可以在根目录放 `translations.tsv`，格式与 M5-D 目录相同。它只替换
opcode 101/102 的字面文本，不必提供完整的 `CommonEvent.dat`：

    # mods/example/translations.tsv
    开始交流 	Start a chat

合并顺序：`--mod` 先后（后者覆盖前者）→ 命令行的 `--translation` 最后合并。
因此显式目录永远拥有最终解释权，mod 之间也能分层覆盖。

### 实现

- `crates/wolf-game/src/mods.rs`：`ModManifest` 解析、`validate` 依赖/重名/保留名
  检查、`ModInfo::label`；`Game::with_overlays` 在读取任何数据文件前调用。
- `GameError::Mod` / `GameError::Translate`；`Game::mods()` 暴露已校验清单。
- `Game::with_overlays` 读取每个 overlay 根目录的 `translations.tsv` 并按序
  `Translator::merge`；新增 `Game::merge_translation_file` 与 `Game::translator()`，
  `--translation` 改用 merge，保证显式目录最后生效。
- `play`/`capture` 启动时打印 mod 清单；装载失败时直接报出具体依赖名。

### 测试

- `mods.rs` 单测 8 条：清单解析/注释、缺省名与未知键、默认清单、重名、自依赖、
  base 依赖、缺依赖、保留名。
- `crates/wolf-game/tests/m5_mod_overlay.rs` 4 条真实数据用例：图片覆盖、音频覆盖、
  mod 文本补丁 + 显式目录最后合并、缺依赖在读数前失败。
- capture 实测：带 `translations.tsv` 的 mod 让夜菜单第一项变为 “Mod chat”；
  缺依赖时报 `mod error: mod 'broken' requires 'absent'...`。
- `Translator::merge` 单测覆盖同名条目后者覆盖、作用域条目覆盖、无前缀条目保留。

### 边界

- 文本补丁仍是精确字符串替换，不做逐行二进制补丁；`CommonEvent.dat`/数据库等
  非文本文件仍只能整文件覆盖。
- 依赖只校验存在性，不处理版本区间、循环依赖或自动下载；mod 仍需用户自己准备。
- 清单不注入代码、不改变 exe 或渲染参数。

## M5-F：消息回顾（F4 转录）

原版的消息窗口只有一条：每执行一次 101，上一句就被替换掉，玩家误触确认或
走完一段长对话后无法重读。本切片把已经显示过的文本留在运行期，用 F4 打开一个
只读回顾页。

### 玩家用法

```bash
# 正常游玩，按 F4 打开/关闭消息回顾
wolf-cli play --load-save work/Data/Save/SaveData01.sav

# 打开后：PgUp 往前翻 18 条，PgDn 往回翻；F4 关闭；F10 退出不变
```

回顾页是模态文本页：打开时暂时隐藏游戏自身的文字，并拦下键盘/鼠标游戏输入
（脚本仍在后台运行，但不会因为误触而推进对话），避免两层文字叠在一起。标题行
显示当前页范围与总数，正文白字 2 px 黑边，长句由 cosmic-text 在 1008 px 宽度内
自动换行。F10 退出、F12 重开仍可用。

### 实现

- `crates/wolf-game/src/game.rs`
  - 新增 `HISTORY_LIMIT = 200` 与 `Game::history: Vec<Message>`；
    `GameHost::show_message` 在翻译之后把同一条消息（`frames = 0`）追加进 history，
    超过上限从最旧端 `drain`。现行 `messages` 仍只保留一条。
  - 新增 `message_history()` / `clear_message_history()`；`start_title` 与
    `savegame::load_into` 清空，避免标题、读档把两段无关对话接在一起。
- `crates/wolf-cli/src/play.rs`
  - `App` 新增 `backlog` / `backlog_scroll`；F4 开关，PgUp/PgDn 每页 18 条，
    滚动量 clamp 到 `len - BACKLOG_ROWS`，不会翻出空白页。
  - `backlog_view(history, scroll) -> (header, body)` 是纯函数，负责页范围、
    标题与正文拼接；`build_text_items` 在回顾页打开时直接返回这两条 TextItem。
  - 打开/关闭时清空 held 与鼠标按键，打开期间键盘（除 F4/PgUp/PgDn/F10/F12）
    与鼠标输入不送进游戏；F12 重启会关闭回顾页并清零滚动位置。
- 不改存档格式、不新增外部依赖；回顾内容只存在于当前进程。

### 测试

- `wolf-game` 单测 `a_transcript_keeps_order_and_is_bounded`：连续 203 条消息后
  history 恰好 200 条、最旧为 `line 3`、最新为 `line 202`，活动窗口仍只有 1 条；
  `clear_message_history` 清空。
- `wolf-cli` 单测：空历史、25 条消息的首页（第 8-25 条）、PgUp 后的第 1-18 条、
  超出上限的滚动夹紧，均断言 header 与正文首尾行。
- `cargo test -q -p wolf-cli play::tests` 8 passed；`cargo test -q -p wolf-game --lib`
  在 `WOLF_DATA_ROOT=work/Data` 下 255 passed；全 workspace 默认与数据根均
  832 passed / 0 failed / 2 ignored；verify 64 matched / 1 SKIP、
  verify --wolf 72 matched / 0 pending（1,361/1,361 bytes equal）。

### 边界

- 只保留运行期最近 200 条；不提供跨会话历史，也不把转录写进 `.sav`（存档格式
  继续与原版逐字节兼容）。
- 回顾页复用文本 pass，没有背景面板、鼠标点击或富文本；F4 是固定热键，未做
  键位重绑定。
- 翻译目录（M5-D）在入 history 之前应用，因此回顾页显示的是玩家实际看到的文本。

## 后续切片的设计约束

- M5-D 的目录格式与上下文键已定；工具已能列出全部静态句并检查覆盖率。剩余工作是
  完整语言包的内容本身（人工/社区翻译），以及变量相关句的运行时翻译策略（当前
  不进入模板）。
- M5-E 已有 `--mod` 数据/音频覆盖、`mod.ini` 清单/依赖与 `translations.tsv` 文本补丁。
  剩余工作是**非文本文件的记录级二进制补丁**（当前仍整文件替换），以及版本区间/
  循环依赖检查；这些都需要独立的补丁格式设计，不与现有覆盖层混在一起。
- M5-C 跨周目永久成就仍按原计划单独设计新存档字段与迁移，当前 F2 只读存档变量。
- M5-F 的 F4/PgUp/PgDn 仍是固定热键，键位重绑定不在本里程碑内。
