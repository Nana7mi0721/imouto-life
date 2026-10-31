# M4 对等与打磨 — 工作分解（计划稿）

M4 的目标：让 Rust 重写在**玩家可感知层面**与零售 2.03 等价。M3 已把运行时/事件/
存档/设置 API 打通；M4 处理界面、音频、存档互通、性能与打包。

## 1. 渲染与界面（最高优先级）

- **离屏截图链路已可用**：`wolf-render` 有界初始化/回读超时 + `WOLF_RENDER_BACKEND`/
  `WOLF_RENDER_ADAPTER` 覆盖；`wolf-cli capture` 可出 1024x576 PNG（标题/读档/事件）。
  仍有：`capture --map SampleMapA` 黑屏（wolf-cli map 路径，专项修复中）。
- **字体发现**：`find_font` 原来只认姊妹作字体名，本作 `07やさしさゴシックボールド.ttf`
  被跳过 → 截图/窗口无文字。已改为包含本作字体名 + *.ttf 回退。
- **像素对照流程**：用 `capture` 出图 → 与 `prt sc/` 的 10 张实机截图（1530x860，原生
  1024x576 放大）做布局对照；`wolf-render --example imgdiff` 可做差异图。注意汉化字体
  与日文原版不同，字形不可逐像素对齐，只对布局/颜色/槽位。
- **界面细节**：窗口九宫格、光标、文字换行/字号/颜色转义、290 特效、160/162 转场、
  选择窗锚点（标题 Sys3/4=-1000 的出厂怪癖保持忠实）。
- **窗口化交互**：`wolf-cli play` 已有 1024x576 整数缩放、鼠标→WOLF 键码、F12 重启；
  需要补设置界面（音量/键位）与退出时持久化。

## 2. 音频

- 引擎/混音器已完成并有 15 条离线契约测试（音量、循环、淡出、SE 混音、重采样、null）。
- 待办：`SoundCmd.frames` 的 BGM 淡入 / SE 延迟语义未实现；单条 SE 无法单独停止；
  play 路径实机试听；BGM/SE 音量与设置界面接线。
- 本作 BGM 69.2 MB / SE 10.6 MB，全部在 work/Data，无需再解包。

## 3. 存档互通与格式保真

- 文本图 payload 已在「未修改」情况下逐字节保真（retained_text），修改过的图会走
  规范编码（显示等价、字节可能规范化）。
- **vardb 字符串编码**：`wolf-save::VariableDatabase::set_text` 写 UTF-8；零售存档里
  的字符串是 GBK/CP932。引擎内自洽，但写出的存档交给零售 Game.exe 会乱码。M4 需要
  决定：写盘时把 CData 字符串按 GBK 编码（与 `savegame.rs` 文本图一致）并验证
  SaveData01 往返仍字节一致。
- System.sav 设置写回、Config.exe 字段语义（音量顺序、键码映射、重复速度）仍有
  未确认项，见 work/out/settings_api_design.md §4。
- 220/222 存档路径与官方 SaveData01/02 的读写已覆盖；新游戏 vardb 已补全。

## 4. 性能与打包

- headless 每帧成本基准（`wolf-cli run --event 251 --frames N` 计时）、事件冒烟的
  92 事件总耗时、10,745 行测试的整套耗时。
- 资源加载：图片/音频按需缓存与 LRU；`Screen`/`Atlas` 的上传批处理。
- 打包：`cargo build --release`，把 `work/Data`/字体内嵌或以 Data.wolf 原包读取
  （VER6 解包已实现），提供启动器与 readme；不提交 work/。

## 5. 语义/数据遗留（不作为 M4 阻塞）

- `v8` 命名（深夜/就寝代码）待专项审计；CE250/CE257 源数据坏字节保持 allowlist；
- 100 日长链与妊娠判定只按阈值分支测试；opcode 104/战斗模板明确为模板残留；
- CE212 需调用上下文（气泡辅助事件），不能独立运行。

## 6. M4 验收草案

```bash
cargo test -q --workspace
WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --tests --no-fail-fast
WOLF_DATA_ROOT=work/Data ./target/debug/wolf-cli.exe verify
WOLF_DATA_ROOT=work/Data ./target/debug/wolf-cli.exe verify --wolf <安装目录>/Data.wolf
# 截图：标题 / 读档（SaveData01）/ 状态面板 / 夜菜单 / 商店 / 相册
wolf-cli capture --menu-only --frames 120 --out work/out/shots/title.png
wolf-cli capture --load-save work/Data/Save/SaveData01.sav --frames 120 --out work/out/shots/bedroom.png
wolf-cli capture --event 238 --frames 60 --out work/out/shots/status.png
# 窗口实机：F12 重启、鼠标点选、音量/键位设置、退出落盘
```

## 7. M3 收口后新增/变化的事项（更新）

- **地图 ActionKey 点击层已完成**：SampleMapA 的 44 个 trigger-0 页（保存/道具/状态/
  日中菜单/就寝/结束/姿势/统计/相册/妹妹位置）现在由 `MapRuntime::action_key_at` +
  Game 左键/悬停 OK 路由激活；ev5 保存、ev10 状态、ev21「終了仮」夜间退出均已端到端
  （m3_map_click 7 条）。PlayerTouch 在定屏地图上仍不建模。
- **字体**：`find_font` 优先本作 `07やさしさゴシックボールド.ttf` 并支持任意
  *.ttf/*.otf/*.ttc；但该日语字体缺少简体专有字形（废/欢/烦/请/栏/为/动/时/读/该）。
  Game.dat 指定的是系统 `Microsoft Yahei UI Bold`，M4 应优先加载
  `C:/Windows/Fonts/msyhbd.ttc`（若渲染器支持 TTC），否则保留现回退。
- **存档编码与字节保真已完成**：vardb 文本未修改保留原字节、新文本 GBK；
  `db.rs` 改用 decode_wolf_str 读回。SavePart5 数字字段也已用「保留原始记录」补齐，
  `Game::load_save → save_to` 对官方 SaveData01/02 现在 **0 个差异字节**（含
  header checksum），二次往返稳定。
- **性能基线**：m3_perf_baseline + docs/M4_PERF.md（5 场景，非门限）。
