# M4 对等与打磨 — 工作分解（计划稿）

M4 的目标：让 Rust 重写在**玩家可感知层面**与零售 2.03 等价。M3 已把运行时/事件/
存档/设置 API 打通；M4 处理界面、音频、存档互通、性能与打包。

## 1. 渲染与界面（最高优先级）

- **离屏截图链路已可用**：`wolf-render` 有界初始化/回读超时 + `WOLF_RENDER_BACKEND`/
  `WOLF_RENDER_ADAPTER` 覆盖；`wolf-cli capture` 可出 1024x576 PNG（标题/读档/事件）。
  `capture --map SampleMapA` 黑屏已修；map 路径与 `--load-save` 现在都会装入地图页面与 HUD。
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

- 引擎/混音器已完成，离线契约测试覆盖音量、循环、淡出、SE 混音、重采样、null 与
  SE stop-all（`mixer_contract` 18 条 + `m4_soundcmd` 11 条 + 单元测试）。
- `SoundCmd.frames` 的 BGM 淡入 / SE 延迟语义已实现（task-45，`m4_soundcmd` 契约测试）。
- opcode 140 的 SE 停止在零售数据里是 `SoundFreeAll`/`SoundFreeAllVariable`（参考解码器
  `State::FreeAll`），不携带文件名或 voice id；普查 `BasicData/CommonEvent.dat` +
  `MapData/*.mps` 共 247 条 opcode 140，其中 73 条无文件名状态（62 条真正 FreeAll 变体：
  60 个 0xFF 哨兵 + 2 个变量形态；11 条 DB-entry 播放），字符串表全为空。故 SE Stop 的
  零售语义就是清空整个 SE 总线（stop-all），Rust 端 `stop_all_se()` 正确，无需也不应实现
  per-voice stop；`mixer_contract` 已加「多条并发 SE 一次停止全清空、BGM 不受影响」契约
  测试。
- 待办：play 路径实机试听；BGM/SE 音量设置项与界面排布已完成，实机听感与键位重绑定仍需
  用户截图/操作核验。
- 遗留（非 M4 阻塞）：少量 sound-type=0 的 DB-entry SE 播放（如 CE249 pc258/pc280、
  SampleMapA ev15 的 `ints=[544,...]`）当前被播放判别落入 Stop 分支，需 SysDatabase SE
  id 解析，属独立后续。
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
wolf-cli capture --map SampleMapA --load-save work/Data/Save/SaveData01.sav --event 10 --var 15=99 --pointer 100,200 --frames 60 --out work/out/shots/status_panel8.png
wolf-cli capture --load-save work/Data/Save/SaveData01.sav --event 245 --frames 90 --out work/out/shots/night_menu4.png
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

## 8. 2026-10-31 M4 状态（更新）

- **已完成**：tile quad 缓存（task-44）、SoundCmd.frames 淡入/延迟（task-45）、
  100 日长链永久测试（m4_long_chain）、v8 语义审计（docs/M4_V8_AUDIT.md）、
  发布打包（tools/package.*、docs/PACKAGING.md）、负号图片固定屏修复、
  decode_wolf_str GBK/UTF-8 冲突修复、读档前 CE48 初始化（prime_engine）、
  数据库值 magic/op121 DB 写入（详见 docs/M4_HUD.md）。
- **读档恢复地图 Runtime**：`play/capture --load-save` 以前只 prime+load，停在静态卧室；
  现由 `Game::resume_loaded_map` 用 SavePart1 的 64x36、35 个 event id 唯一识别
  SampleMapA，`start_pages_loaded` + `MapRuntime::start_pending_loaded` 装入 tilemap/
  页面并按恢复的全局变量重选页，只把无条件 autorun（ev0 ニューゲーム处理）标成
  已运行，避免读档重播开场。存档对象 var2/var3 是地图坐标的 2 倍，不是页号；
  本作存档不保存事件当前页。新增 `crates/wolf-game/tests/m4_load_resume.rs` 2 条。
- **验收**：workspace 全绿；verify PASS 64/1 SKIP；verify --wolf 72/0；
  读档截图 HUD 与实机参考一致（work/out/shots/bedroom_hudfix.png）。
- **状态面板截图已收口**：`capture --map SampleMapA --load-save ... --event 10 --var 15=99
  --pointer 100,200` 可直接触发 ev10 的状态入口（v15==99 为该页的显式门槛，正常流程不可达，
  是数据怪癖），得到房间+HUD+左侧状态面板（work/out/shots/status_panel8.png）。
  关键是实现了 op150 的 head bit 0x10000 相对坐标：CE238 隐藏时面板在 x=-305，显示时
  相对 +305 落到 x=0，五个动态文本也相对 +(305,0) 移到各标签旁（见 docs/M4_HUD.md §6）。
- **夜菜单截图已收口**：`capture --load-save ... --event 245` 过去会丢掉 event（Entry::Save
  优先级高于 --event）；现在 `run_capture` 增加 `save_event`，读档恢复地图后再启动指定
  common event，得到房间+HUD+夜菜单六项的 work/out/shots/night_menu4.png。
- **字体覆盖补齐**：msyhbd.ttc（本作 Game.dat 指定的 UI 族）不含 U+25B6（夜菜单光标 ▶）。
  新增 `Renderer::add_fallback_font` / `TextRenderer::add_fallback_font`，把
  C:/Windows/Fonts/seguisym.ttf 载入同一 private fontdb（平台 common fallback 名
  "Segoe UI Symbol" 正好命中）；text stats 由 `1 substituted` 变为
  `0 substituted`，截图中的 ▶ 正确显示。单元测试
  `text::tests::a_named_fallback_covers_a_glyph_the_primary_lacks` 覆盖。
- **仍需实机核验**：可视设置界面已完成 CE132/CE95 排版（`docs/M4_SETTINGS_UI.md`、
  `m4_settings_ui`），键位重绑定、设置交互与音量听感仍需用户在 `wolf-cli play` 里截图/
  操作确认；msyhbd.ttc TTC 字体加载已实测可用。
