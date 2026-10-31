# M4 性能基线（headless，可重复）

本文件记录 M4 的性能测量方法与一次实测结果，作为后续优化的对照基线。**这里只测量，
不优化**：所有优化候选都只列在 §6，尚未落代码。

配套：测试入口 `crates/wolf-game/tests/m3_perf_baseline.rs`；计划见
`docs/M4_PARITY.md`；数据/环境见 `docs/HANDOFF_M0.md`。

## 1. 目标与边界

覆盖 M4 需要保持流畅的五种纯逻辑场景（VM + 游戏宿主 + 图片层 + 文字排版）：

| 编号 | 场景 | 构造 | 计帧 |
| --- | --- | --- | ---: |
| A | boot -> 标题稳定 | `Game::new` + `boot()` | 300 |
| B | 读档卧室 | engine events + `load_save(SaveData01)` | 600 |
| C | 一次完整 CE251 就寝 | 干净 `Game::new` + `start_event(251)` | 400 |
| D | CE245 夜间菜单 | 读档卧室 + `start_event(245)` | 120 |
| E | 夜间互动 UI 合成 | SampleMapA 夜间页 + CE230 | 180 |
| F | 引擎空转地板（诊断用） | `Game::new` + `start_engine_events`（无存档/地图） | 600 |

F 不是玩家场景，它把「每帧固定开销」（97 条条件自动事件扫描、map runtime、屏幕
tick/advance、引擎自带轮询脚本）从脚本工作量里分离出来。

不包含：GPU 绘制、音频输出、图片解码首帧（见 §3 的 warm-up）、真实窗口/输入设备。

## 2. 运行方法

```bash
cd '/e/Study/github program/Imouto Life' && source tools/env.sh >/dev/null 2>&1
WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --test m3_perf_baseline -- --nocapture
```

无数据时打印 `skipping: no WOLF data ...` 并返回，默认 `cargo test -q --workspace`
仍然 exit 0。优化后复测用同一条命令，对比各场景的 **min/中位 ms/帧**，不要加任何
墙钟阈值断言。

## 3. 测量方法

- `std::time::Instant`；每个场景先跑一次**不计时的 warm-up**（文件/资产/OS 缓存），
  再在**全新的 `Game`** 上跑 3 次计时 run，报告 3 次的 min 与中位数。
- 单个 `#[test]`，避免 cargo 的并行测试线程互相抢 CPU。
- 每帧循环只包含 `Game::frame()`；`setup ms` 是构造场景的时间（A 含 `Game::new`+
  `boot`，E 含 260 帧界面入场），各场景不可横向比较。
- `text_quads()` 是纯读函数，帧循环后连续调用 10 次取均值。
- `picture_quads()` / `tile_quads()` 需要 `&mut Game`，同样在帧循环后测；两者前先各
  调一次，把 `Atlas` 的首次解码/打包成本排除，得到的才是渲染器每帧的稳态成本。
- 帧循环**不**调用这三个渲染函数：基线测的是逻辑帧，渲染成本单列。
- 断言只检查正确性：`warnings == 0`、`instructions > 0`、帧数 > 0、峰值协程 > 0。
  没有毫秒阈值。

## 4. 机器上下文与噪声

- Windows 11 Home China 10.0.26100；仓库在 `E:`；`cargo test` **debug/test** 构建
  （不是 `--release`）；数据 `work/Data`（约 175 MB）。
- 共享机器，GPU0 上常有训练负载，CPU/内存带宽都会抖动。**本文所有数字都依赖机器
  负载**，同一份代码在不同时刻可能相差 ±20%~30%，跨机器没有可比性。
- 连续 4 次完整运行的观察范围（中位 ms/帧）：A 0.053–0.071、B 0.017–0.020、
  C 0.054–0.066、D 0.078–0.091、E 0.52–0.61、F 0.015–0.016。A/E 的尾帧抖动最大。
- 比较优化收益时请在同一时段交替跑「改前/改后」，并以中位数为准。

## 5. 实测表（一次代表性运行，2026-10-31）

命令见 §2；同一次输出里的汇总行：

| 场景 | 帧数 | min ms/帧 | 中位 ms/帧 | 中位 fps | VM 指令/帧 | 峰值协程 | setup ms | text_quads ms | picture_quads ms（quad） | tile_quads ms（quad） |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| A boot -> 标题 | 300 | 0.055 | 0.056 | 17,753 | 47.4 | 6 | 72.0 | 0.000 | 0.001（1） | **0.477（19,080）** |
| B 读档卧室 | 600 | 0.017 | 0.017 | 57,548 | 30.8 | 5 | 70.6 | 0.023 | 0.004（5） | 0（无 tilemap） |
| C CE251 就寝 | 400 | 0.063 | 0.066 | 15,059 | 4.8 | 4 | 75.5 | 0.004 | 0.002（1） | 0 |
| D CE245 菜单 | 120 | 0.078 | 0.079 | 12,726 | 87.1 | 6 | 59.6 | 0.021 | 0.004（5） | 0 |
| E 夜间互动 UI | 180 | 0.516 | 0.525 | 1,903 | 380.5 | 19 | 241.2 | 0.024 | **0.328（25）** | **0.649（27,648）** |
| F 引擎地板 | 600 | 0.015 | 0.015 | 67,049 | 30.6 | 5 | 83.9 | 0.000 | 0（0） | 0（0） |

屏幕状态（每个场景计时结束时的读数）：

| 场景 | 屏幕图片 | 其中文字图片 | text_quads 数量 | 屏幕协程 |
| --- | ---: | ---: | ---: | ---: |
| A | 1 | 0 | 0 | 3 |
| B | 50 | 35 | 10 | 1 |
| C | 6 | 3 | 2 | 3 |
| D | 50 | 35 | 14 | 3 |
| E | 84 | 38 | 11 | 9 |
| F | 0 | 0 | 0 | 1 |

读法：

- 纯逻辑帧非常便宜：最慢的 E 也是 ~0.52 ms/帧（1.9k fps），其余都在 0.02–0.08 ms/帧。
  现实下限由渲染/合成决定，不在本表。
- B 只有 0.017 ms/帧，是因为 `load_save` 直接恢复图片层，没有 `start_pages`，所以
  tilemap 为空、`tile_quads` 为 0；真实「标题读档」路径（m2 的 1600 帧）会额外安装
  地图。这是按任务要求选的轻量构造，对比时注意。
- E 的 380.5 指令/帧远高于其它场景，但 §6.1 的归因实验表明**墙钟大头不是 VM 派发**，
  而是内置图形（`<SQUARE>`/`<GRADX...>`）触发的资产缓存未命中。

## 6. 观察到的热点（含 file:line 证据）

### 6.1 内置图形每次绘制都做一次文件系统探测（夜间 UI 的主成本）

链路：

- `GameHost::picture`（`crates/wolf-game/src/game.rs:1770`）在每次非文字 `150` 绘制后
  调用 `assets.texture_size(&cmd.file)` 预热缓存（`game.rs:1776-1778`）。
- `Assets::texture_size`（`crates/wolf-game/src/assets.rs:365`）→ `Assets::load`
  （`assets.rs:310`）。`load` **只缓存成功结果**；失败名字每帧重新解析。
- `Assets::resolve`（`crates/wolf-game/src/assets.rs:250`）先 `is_file()`，无扩展名时
  再试 3 个扩展名，最后做**逐段大小写不敏感的 `read_dir` 遍历**。`<SQUARE>`、
  `<GRADX-444-000>` 这类内置图形永远不是文件，于是每次绘制都走完整条失败路径。
- 渲染侧同样的顺序问题：`picture_frame`（`crates/wolf-game/src/picture.rs:1513`）先
  问 `tex_size`，然后才在 `picture.rs:1537` 尝试 `sysgraphic::parse`；
  `Atlas::sprites`（`crates/wolf-game/src/atlas.rs:561/569`）与 `hover`
  （`game.rs:1664/1677`）也各自会问 `texture_size`。

实测（work/Data，warm OS cache）：

- `texture_size("<SQUARE>")` ≈ **81–110 µs/次**；`"<SQUARE><FRAME>"` ≈ 81 µs；
  `"<GRADX-444-000>"` ≈ 83 µs；普通文件（缓存命中）≈ 0.1–4 µs。
- 归因探针（读档卧室 + 只启动单个地图事件，各 600 帧）：

  | 只启动 | ms/帧 | 图片命令/帧 |
  | --- | ---: | ---: |
  | 无（仅 CE230） | 0.001 | 0.0 |
  | ev15 | 0.022 | 13.0 |
  | ev16 | 0.021 | 0.0 |
  | ev17 | 0.027 | 0.0 |
  | ev18 | 0.019 | 0.0 |
  | **ev19** | **0.670** | **12.0** |
  | ev20 | 0.022 | 0.0 |
  | ev23 | 0.017 | 2.5 |
  | ev26 | 0.026 | 0.0 |
  | 全部 8 页 | 0.589–0.871 | 27.5 |

- ev19 的第一页共 39 条 `150` 绘制，其中 **20 条是内置图形**；每帧约 12 次绘制，
  约 6 次内置 → 6 × ~100 µs ≈ 0.6 ms/帧，正好解释 ev19 单页 0.67 ms/帧和全界面
  0.59–0.87 ms/帧。其余事件单独跑都在 0.02–0.03 ms/帧。
- 同一机制也出现在渲染 pass：E 的 `picture_quads` 0.33–0.39 ms（84 图，25 quad），
  B 只有 0.004 ms（50 图，5 quad），差额与画面上的 14 个内置图形（状态条/渐变/
  判定框）吻合。

### 6.2 tile quads 每帧全量重建

- `Game::tile_quads`（`crates/wolf-game/src/game.rs:802`）→ `TileMap::quads`
  （`crates/wolf-game/src/tilemap.rs:100`）：遍历最多 3 层 × 可视格，自动图块每个
  发 4 个象限 quad（`tilemap.rs:171-190`）。
- 本作地图正好铺满 1024×576 视口，几乎不裁剪：标题图 **19,080** quad、
  SampleMapA 卧室 **27,648** quad（测试输出里的 `tile qds` 列）。
- 稳态成本：标题 0.41–0.55 ms/次，卧室 0.62–0.83 ms/次（基线测试内，Atlas 已预热）；
  另行 100 次独立测量得到 0.87 / 1.40 ms。它是本基线里最大的单项渲染准备成本。
- 相机固定为 `[0,0]`（`game.rs:806-812`，本作全部定屏），地图只在 `start_pages`/
  `switch_map` 时更换，因此这份 quad 列表天然可缓存；唯一逐帧变化的是自动图块动画
  相位（`tilemap.rs:106/172` 的 `frame` 参数）。

### 6.3 文字排版每帧重算两遍

- `Game::text_quads`（`game.rs:1098`）对每个可见文字图片先 `layout`（`game.rs:1121/
  1130`），再对每个 run 调 `measure`（`game.rs:1153/1155`）——同一字符串每帧被 shaping
  两次。
- 实测 0.021–0.025 ms/次（35–38 个文字图片，E 的 11 个 quad）。绝对值不大，但已是
  B 整个逻辑帧（0.017 ms）的 ~1.4 倍，且渲染器还要另外栅格化字形。

### 6.4 已确认可以忽略的项

- `auto_events.sync`（`crates/wolf-game/src/auto_events.rs:171`）每帧扫 97 条条件和
  latch HashMap：**0.6 µs**。
- `Screen::tick` + `advance`（`game.rs:1356/1359`）遍历 84 张图：**0.7 µs**。
- 引擎地板 F：30.6 指令/帧、0.015 ms/帧（≈67k fps），即固定 host 开销可以忽略。
- CE251 就寝只有 4.8 指令/帧（400 帧里大部分时间在等消息/时间推进），不是 CPU 场景。

## 7. 优化候选（按预期收益排序，尚未实现）

1. **给资产解析加内置图形/负缓存**（预期最大）
   - 做法：`Assets` 增加内置图形尺寸表或失败名字负缓存；`GameHost::picture`
     （`game.rs:1770`）对 `sysgraphic::is_builtin(&cmd.file)` 直接跳过预热；
     `picture_frame`（`picture.rs:1513`）先 `sysgraphic::parse` 再问 `tex_size`；
     `atlas.rs:561`、`hover`（`game.rs:1677`）同步调整。
   - 预期：夜间 UI 从 **~0.87 ms/帧降到 ~0.1–0.2 ms/帧**（约 5 倍），并消除所有
     状态条/渐变/判定框场景里每次绘制 80–110 µs 的文件系统探测。风险低：内置图形
     本来就不是文件，语义不变。

2. **缓存 tile quad 列表**
   - 做法：在 `Game`/`TileMap` 里缓存每层 `Vec<SpriteQuad>`，仅在 `start_pages`/
     `switch_map` 或自动图块动画相位变化时重建；动画相位周期很短，可以预生成
     N 个相位或只重建动画图块。
   - 预期：每帧省 **0.4–0.8 ms（基线内 warm）/ 最多 1.4 ms（独立测量）**，是渲染
     准备里最大的一项。代价是约 1 MB 内存（27,648 quad × ~36 B）。风险低。

3. **缓存文字排版结果**
   - 做法：按图片缓存 `Vec<TextQuad>`，键为 text / 位置 / anchor / alpha / 字体
     + 变量代次；至少先去掉「layout 之后再 measure 一遍」的重复 shaping。
   - 预期：每帧省 **0.02–0.04 ms**（相对逻辑帧不小，相对整帧约 3–7%），并避免
     双倍字形测量。风险中：WOLF 文字可引用变量，缓存必须随变量变化失效。

被否掉的方向：`auto_events.sync`、`Screen::tick/advance` 都是亚微秒级，优化它们
不会改善玩家体验；VM 指令派发在 E 的 380 指令/帧里也不是主因（见 6.1）。

## 8. 已知限制

- 全部为 debug/test 构建、CPU-only；GPU0 训练负载会引入 ±20–30% 抖动。
- B 使用 `load_save` 直接读档（无 tilemap）；E 的 setup 含 260 帧入场，setup 列
  不跨场景比较。
- `picture_quads` / `tile_quads` 的计时在帧循环之后单独进行，未与逻辑帧叠加；
  渲染器（`wolf-cli play`，`crates/wolf-cli/src/play.rs:237-240`）实际每帧会同时
  调用两者 + `text_quads`，所以真实每帧 CPU ≈ 逻辑帧 + 三者之和（去重缓存后）。
- 测量不覆盖图片解码首帧、音频混音、GPU 上传/绘制。

## 8. 首轮优化已落地（Lead，2026-10-31）

优化候选 1 的最小版本已实现：`Assets` 增加 `missing` 集合与内置 `<SHAPE>` 早退，
`texture_size` 不再对内置图形/已确认缺失的名字每帧做大小写目录扫描
（crates/wolf-game/src/assets.rs）。同一时段复测：

| 场景 | 改前中位 ms/帧 | 改后中位 ms/帧 |
| --- | ---: | ---: |
| B 读档卧室 | 0.017–0.019 | 0.019 |
| E 夜间互动 UI | 0.516–0.525 | **0.163** |
| E picture_quads | 0.328 ms | **0.026 ms** |
| E setup（含首帧解码） | 241 ms | 146 ms |

夜间 UI 约 3.2x；`picture_quads` 约 12x。候选 2（瓦片 quad 缓存）仍待做。
