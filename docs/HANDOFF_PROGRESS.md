# 进度日志（HANDOFF 附录）

本文件是从 [HANDOFF_M0.md](HANDOFF_M0.md) §11 拆出的**完整进度日志**，按时间顺序记录
M0–M7 与 C 任务每一步的改动、验证数字与踩过的坑。它只记录“过去发生了什么”；
**当前状态**看 [HANDOFF_M0.md](HANDOFF_M0.md) §11 摘要。

---

* 2025-10-30：数据勘察完成（Game.dat / CommonEvent / 数据库 / .project / 地图 / 全局变量表 / 资产树全部实测）；`Data.wolf` 解开并 1,361/1,361 逐字节验证；6 份 GPT 报告回收并与数据对账；本文件写就。**代码尚未开始（M0 未动工）。**

* 2025-10-30（M0 进行中）：
  * M0-1 仓库初始化完成（git init；.gitignore / rust-toolchain.toml 复制；tools/env.sh|env.ps1|setpath.ps1 复制并把两处绝对路径改为 Imouto Life）。
  * M0-2 复制 7 个 crate + 根 Cargo.toml/Cargo.lock，`cargo build -q` 全绿。
  * M0-4 `generation.rs` 完成并接入（V200/V210 两代表）：本作 V200 → Game.dat footer 0xC2 / CommonEvent footer 0x8F / Database version+footer 0xC1；build 全绿。
  * M0-5 `.project` CP932 回退完成（database.rs name_at 先 UTF-8 再 decode_cp932）。
  * M0-6 verify 字面量全部本作化 + `docs/BASELINE.json`（11 顶层键，本作实测值）。`verify` PASS 64 / 1 SKIP（dxarchive.header），`precompile` PASS 19，`cargo test -p wolf-cli` 8 passed。
  * M0-8 VER6 解包完成：`dxarchive/ver6.rs` + Backend 自动分派；`verify --wolf` 读到 Data.wolf → PASS 72 checks、dxarchive 条目 1,361/1,361 逐字节相等、total/decoded 179,877,496 B、data_start 48、CodePage 932。
  * 待办：M0-7（capture 地图名改本作）、M0-9（全量 `cargo test -q --workspace` 全绿 + 提交）。test-adapt 子任务仍在进行中。
  * 资料：新增 `docs/REFERENCE.md`（日文原版路径、攻略链接、10 张实机截图目录、存档样本）；日文原版目录已还原为规范日文名。

* 2025-10-30（M0 完成）：
  * M0-3 `wolf-cli` 默认数据根由 `work/full` 改为 `work/Data`（main.rs default_root + help 文本）；`verify` 不带 env 即读本作数据：PASS 64 / 1 SKIP(dxarchive.header)；`verify --wolf <Data.wolf>` PASS 72 / 0 pending（1,361/1,361 byte-equal，179,877,496 B）。
  * M0-7 `capture` 地图名解析本作化（`--map SampleMapA` / `SampleMapA.mps` → `MapData/`）。headless capture 仍卡在 wgpu 离屏初始化（`Renderer::new_offscreen()`），非 M0 验收项，M1 处理；已有用户 10 张实机截图。
  * M0-9 全量 `cargo test -q --workspace`（默认、无 WOLF_DATA_ROOT）**exit 0，39 个 test target 全 ok**；`WOLF_DATA_ROOT=work/Data cargo test -p wolf-format` **86 passed / 0 failed**（lib 35 + database 7 + dxarchive 3 + map_audit 11 + messagetext 16 + mps 6 + tileset 4 + maptree 4）。
  * 测试适配（test-adapt）：wolf-format tests 全部按本作实测值改好（database / dxarchive[删旧 sister-ver8 用例、保留 ver6] / messagetext / mps / tileset / maptree / map_audit）；wolf-game/tests/map_runtime.rs 3/3；audio_wiring.rs 改 `start_event(297)` 避免 engine 挂死。
  * 从姊妹作 HEAD `f5aca1c` 同步唯一引擎改动 `crates/wolf-game/src/map_runtime.rs`（night-page teardown 修复）；其余引擎 crate 与姊妹作逐字节一致（仅此一文件不同）。
  * 已知遗留（M1/M3 处理，非 M0）：设置 `WOLF_DATA_ROOT=work/Data` 跑 wolf-game 时，engine 事件 48（`ENGINE_ALWAYS` 首项）在本作数据上 `Game::frame()` 死循环（sibling 注册表按 550 事件配、本作 350 事件）；wolf-game `time_system.rs` 4 条、db 若干为 sister 期望值 / 事件语义差异。默认无 env 时这些用例按设计 skip，故 workspace 测试全绿。

* 2025-10-31（M1：标题与读档，引擎修复 + 文本解码）：
  * **事件 48 挂死根治**（`crates/wolf-vm/src/exec.rs` 条件块）：`enter_block` 的 `BlockKind::Condition` 把比较右值 `arg(cmd, 2+3*i)` 当字面量，但本作 CE79 pc85 比较的是 `self621 >= self616`（1600016 是 self 组 6 slot16 的 magic 地址），未 `eval_num` 解引用 → 6 次循环变 160 万次、每步 op250 写大行号 DB，表现为 `Game::frame()` 死循环。改为 `eval_num(arg(...))`（字面量原样返回，magic 操作数按变量解引用）。`cargo test -p wolf-vm` 85 passed。
  * **字符串解码**（`crates/wolf-format/src/bytes.rs` `t_str` → `decode_wolf_str`）：本作 `t_str` 是 CP932（未汉化的系统/模板文本）与 GBK（汉化后的显示文本）**同文件混排**，姊妹作 2.10 数据是纯 UTF-8。实现：严格 UTF-8 → 否则 CP932/GBK 双解 + 字节/字符打分（GB2312 汉字带加分、CP932 半角片假名单字节扣分、希腊/西里尔扣分修 '円' 被 CP932 读成 υ），分差 >2 才选 GBK。新增 `crates/wolf-format/src/gbk.rs`（480,619 B、21,791 条排序表，`decode(bytes)->(String,bool)`，用 Python `gbk` codec 生成，无新 crate 依赖；曾试 encoding_rs 因 offline portable-atomic 版本冲突放弃）。效果：boot 后 HUD 显示 周一 / 哥哥（学生）/ 行动力 / 精力 / 持有金钱 / 4911円 / 同居 1天 / 普通，warnings=0。
  * **ENGINE_ALWAYS 本作化**（`crates/wolf-game/src/game.rs`）：本作 350 事件 `run_condition` 直方图 `{0:312,2:31,3:7}`，rc3 ids = `[48,261,269,270,271,214,216]`（原姊妹作十项 [48,261,269,270,271,224,225,213,214,41] 已替换）。
  * **存档数据**：`work/Data/Save/` 已从安装目录复制（SaveData01.sav 293,742 B、SaveData02.sav 294,130 B、System.sav 155,615 B），`Game::new` 需要 `root/Save/System.sav`。
  * **M1 测试** `crates/wolf-game/tests/m1_title_load.rs`（3/3 pass，默认 `work/Data`）：① `boot_reaches_the_three_option_title_menu`（boot 后 f82 出 choices=`["menu1","menu2","menu3"]`，warnings0，ENGINE_ALWAYS 全启动）；② `title_menu_new_game_passes_through_the_Map003_hook_into_SampleMapA`（cursor0+auto_choice 3200 帧，diagnostics 含 130 Teleport Map003→SampleMapA，screen>30）；③ `title_menu_load_restores_a_save_into_the_bedroom_hud`（cursor1=menu2→CE14→存档恢复，screen>30，文本含 行动力/持有金钱）。
  * 删除姊妹作故事测试 `crates/wolf-game/tests/m6_mainline.rs`（600 行，全为姊妹作期望值，M6 按本作重写）。`m6_night_menu.rs` / `m6_training_menu.rs` 仍留着姊妹作 M6 流程，默认数据根 `work/all` 不存在时 skip；设 `WOLF_DATA_ROOT=work/Data` 时 `m6_night_menu` 2 条 FAIL（本作 day-loop 变量语义不同，M6 重写，非引擎 bug）。
  * **验证**：默认 `cargo test -q --workspace` **exit 0**（39 test targets 全 ok）；`WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game`：lib 225 + 5 + 1 + 3 全 pass，仅 `m6_night_menu` 2 FAIL（见上）；`wolf-cli verify` PASS 64 / 1 SKIP（dxarchive.header）。
  * **M1 结论**：标题→（新游戏）Map003→SampleMapA、标题→（读档）CE14 恢复存档到卧室 HUD 两条链已在 headless 跑通；像素级对照仍需用户按 PrintScreen（headless capture 的 wgpu 离屏初始化卡死留给渲染阶段）。
* 2025-10-31（M2：日常循环切片）：
  * **鼠标→键码桥接**（`crates/wolf-game/src/key.rs` + `crates/wolf-game/src/game.rs`）：新增 `mouse_bits(buttons, previous)`（左键按下边沿→OK/决定码10、右键→CANCEL/11、中键忽略、按住不重复）；`key_code`(opcode123) 与 `key_code_auto`(opcode125) 都并入鼠标边沿位，键盘路径不变。新增 3 + 1 个单元测试。
  * **图片菜单点选实测**（`crates/wolf-game/tests/m2_input.rs`，5 tests）：EV16「コマンド選択判定」真实路径 op124 悬停 → op123 读键 → ==10 → op121 写 `var67=index`。左键悬停点 picture400 → `var67=1`；仅悬停不写、点框外不写、右键不写、按住不重复、键盘 OK 仍生效。关键坑：EV16 page0 条件是 `var100 >= 1`（不是 !=1），默认 0 时页不激活；置 `var100=1` 后要预热 3 帧事件才真正在循环中执行；不要用 `vm.started_events` 检测地图事件页。
  * **夜间菜单与就寝**（`crates/wolf-game/tests/m2_daily_loop.rs`，4 tests）：读档 1600 帧 → HUD 含 19:30/周一/行动力/持有金钱/5466円，`vars4=19 vars5=30`；`start_event(245)` 六项 `["开始交流 ","泡茶 ","泡澡 ","网上购物 ","今天就这样睡吧 ","0"]`，anchor(512,230)；选第 5 项先弹「差不多该睡了吧…？」→ `["是 ","否 "]`；CE251 必须用干净 `Game::new` 状态（读档 19:30 直接进 CE251 只吐「…………」停 00:00 等待分支），400 帧首条「早上好，哥哥！」，messages=9/pictures=74/sounds=6，时间 00:00→08:30，末尾当日行动菜单含「睡觉」。
  * **HUD 公共事件**（`crates/wolf-game/tests/m2_hud_events.rs`，4 tests）：每个事件 `start_event` 前 `game.screen.clear()` 才能归因（读档 HUD 已占 200/220/230/240/250/251/320/2300+，负槽 -5/-4 背景忽略）。CE242 状态面板正向图恰 [220,230,240,250,251]；CE243 时刻 [200,210]；CE244 行动力 [110] 带符号 +N；CE256 日中菜单无自带图，消息「那么，该怎么做呢。」+ 时钟前进（其 choice 在第 6/7、14/15 帧短暂出现并被 auto_choice_delay=2 自动回答）。
  * **验收**：默认 `cargo test -q --workspace` **exit 0**（39 target 全 ok）；`WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --test m2_input|m2_daily_loop|m2_hud_events` = **5/4/4 passed**；`--lib` **229 passed**；`wolf-cli verify` **PASS 64 / 1 SKIP(dxarchive.header)**。
  * **文档**：新增 `docs/M2_SLICE.md`（范围、读档状态、CE245/CE251/CE242/CE243/CE244/CE256 实测、鼠标契约与坑、验收命令）；新增仓库根 `AGENTS.md`（子代理并行、写作用域、环境/数据/提交/内容安全约定）。清理 M2 临时探针（dayprobe*.rs、cmddump/mapsum/refs examples），不提交。
  * **已知非 M2 遗留**：`WOLF_DATA_ROOT=work/Data` 跑整个 `-p wolf-game` 时，姊妹作 `m6_night_menu` 等 M6 用例仍失败（本作 day-loop 语义不同，M6 按本作重写）；默认无 env 时按设计跳过。headless capture 的 wgpu 离屏初始化仍卡死（渲染阶段处理）。
* 2026-10-31（M3 完整运行时，进行中）：
  * **测试基架**：按本作数据重写 m3 系列，不复用姊妹作 M6 期望值。已完成并通过的测试文件与用例：
    * `crates/wolf-game/tests/m3_week_loop.rs`（6）：读档 HUD 19:30/周一/5466円，v99=1（日计数）/v6=0（星期）/v4=19/v5=30/v7=15466/v20=25；CE245 恰 6 项；就寝→00:00；CE251 干净态 400 帧=9 msgs/74 pics/6 sounds、08:30、日菜单 5 项；连跑 3 日 v99+1/v6+1/v14 重置 4；周末切 CE259 休日菜单。
    * `crates/wolf-game/tests/m3_night_actions.rs`（14）：CE245 六项/茶 8 饮品/泡澡 CE249/购物 CE250（3 商品 20000/100000/15000、余额不足文案、var15 复位）/就寝确认/CE246-250；坑：FrameOutcome.idle 等待 choice 时也为 true，不能当结束判据。
    * `crates/wolf-game/tests/m3_ui_screens.rs`（13）：CE237/238/239/240/241/242/243/244/296/297/301/302/303 的槽位与资源名、相册 var238、CANCEL 24 帧关闭。
    * `crates/wolf-game/tests/m3_save_load.rs`（9，0 ignored）：SaveData01 50图/playtime16/vars7=10000/vars8=23/19:30；SaveData02 51/273/8000/24/18:00；save_to→初读严格比图/文本图/0..302 vars/playtime/anchor；opcode220/222 真实 dispatch；vardb 往返（84602→85537B）DB 零差异；vars302..336 全 0；SaveData09 缺失显式 skip。
    * `crates/wolf-game/tests/m3_visual_text.rs`（7）：CE264 消息窗口 13 pictures（12001 WindowBase_amania、text 12010=1/12014 HP&50/12018 SP&20）、CE230 打字、wrap、CE231-235 惰性、CE265-271；对话走第三方吹き出し插件，真值看 picture/text_quads，不看 game.messages；卧室常驻实例 [48,271,63,98]。
    * `crates/wolf-game/tests/m3_audio_settings.rs`（4）：BGM 27 音频+1 .url、SE214；代表解码；CE297/CE251 SoundCmd resolve；System.sav version0x80/7段/part2 vars72_74=[100,100,100]/RGBA[160,68,75,200]/按键 vars64_69。
    * `crates/wolf-game/tests/m3_menu_screens.rs`（3）：CE131 存档网格（槽1..4/「没有数据」/无 choice）、CE132 システム設定（帮助行随 DOWN 变）、CE14 dispatcher [14,131]；全程不按保存、Save 指纹不变。
    * `crates/wolf-game/tests/m3_event_smoke.rs`（1，表驱动，12.25s）＋ `docs/M3_EVENT_MAP.md`：CE212..303 共 92 个，91 独立冒烟（started/frames>0/warnings0；71 自然结束、20 常驻等待），CE212 标 context-dependent（opcode170 循环+opcode112 比 self1600006/1600008，带参气泡辅助）。
    * `crates/wolf-game/tests/m3_map_events.rs`（4）＋ `docs/M3_MAP_EVENTS.md`：5 注册图尺寸/事件/页/槽；读档上下文 active_page_index 零 panic；SampleMapA 35 事件 120 帧隔离冒烟 warnings0；新游戏 Map003→SampleMapA teleport。坑：v7=10000 非 HUD 5466（金钱走 DB）；start_map_event_by_name 会带起 event0 开场白污染，改用 start_map_event(&map,id)；Map024/031 第0层填充 id100000 但 has_tile_data=true。
    * `crates/wolf-format/tests/m3_asset_refs.rs`（2）＋ `docs/M3_ASSET_REFS.md`：扫描 1,364 文件、图片引用 2433/去重661、音频161/去重34；音频 0 缺失；8 个未解析图片引用全部为 WOLF 出厂示例残留/放错目录，已用 KNOWN_UNSHIPPED 白名单放行并据实记录。
    * `crates/wolf-game/tests/m3_mouse_menu.rs`（8）：choice_anchor=(512,230)、font_px=20、行距=LINE_HEIGHT(30)；逐行中心 choice_row_at 命中；左键 6 行分别进 CE246/茶8项/CE249/CE250(var15=1)/就寝确认/退出；CANCEL 各级关闭。**已知缺口：右键不能取消 op102 choice，hover 不移动 choice_cursor**（已转 task-24 修，task-26 回归）。
  * **引擎修复（已落地，工作树未提交）**：`crates/wolf-format/src/gbk.rs` 新增 `pub fn encode`；`crates/wolf-game/src/savegame.rs` 文本图 decode/encode 改 GBK、picture 文件名 GBK；`savegame.rs` apply 开头 `game.base_save = Some(save.clone())` 修 vardb 丢失；apply 改用 `save.part3.normal_var(index)` 逐行 span 修 vars302..336 污染。真实 SaveData01 文本解码恢复为 #200 \f[24]19:30 / #210 \c[0]\f[18]周一 / #220 早泄 强壮 哥哥（学生）/ #230 行动力60/65 / #251 10000円 / #252 同居1天。
  * **CE250 乱码结论**：源数据损坏，非引擎 bug。坏串 rawlen=30 hex=`d1c6c1e5 a1a1a1a1a1a1a1 20*11 32 30 30 30 30 83d2 20`，d1c6c1e5=GBK「哑铃」，随后 7 个 0xA1（奇数个，GBK 非法尾），Python gbk/gb18030 同拒绝；CP932 把 0xA1..0xDF 当半角片假名 → 显示 ﾑﾆﾁ蝪…20000υ。全 event 扫 gb_bad&&!cp_bad 共 138 条、136+ 为正常日文 CP932，故不能改 decode_wolf_str 判据；不伪造修复，记入文档。
  * **当前任务板**：completed=7,8,9,10,11,12,13,14,15,16,17,18,20；in_progress=19(m2-hud 状态面板联动)、21(verify-baseline 说明书核对)、22(ver6 全数据字符串审计)、23(m2-loop 存档 UI 端到端)、24(m3-fixer 未建模诊断+右键/悬停修复)、25(test-adapt 新游戏跨日持久化)、27(m2-input 标题鼠标)；pending task-26（依赖 24，修后 m3_mouse_menu 右键/悬停回归）。
  * **验收基线保持**：默认 `cargo test -q --workspace` exit0、`WOLF_DATA_ROOT=work/Data ./target/debug/wolf-cli.exe verify` PASS 64 / 1 SKIP（dxarchive.header）；`-p wolf-game --lib` 229 passed。全部 m3 测试完成后统一复跑并提交。

* 2026-10-31（M3 集成：并行工作流收口）：
  * **PRNG 实证纠正**：Game.dat 的 static-random 块是预生成表，`random_a/b` 是生成器输出
    K1/K2（不是种子）。`WolfRng` 改为「表 + 游标」；`Game::new` 解析 Game.dat 并
    `from_game(a,b,table)` 接入真实零售表。证据链：docs/research/M7_PRNG.md（姊妹作
    28,936/28,936 字节全等；本作前 1,055 字节全等，之后是汉化补丁改写/损坏，按原字节消费）。
    注意：`wolf-cli run` / `run --map` 的裸 Vm 也已通过 `install_retail_rng` 接上
    Game.dat 表；只有数据缺 Game.dat 时才回退合成表。
  * **随机派生值不再可 pin**：读档收敛期的工资/新游戏零花钱/CE250 商品分支都由随机表决定；
    相关测试改为区间/形状断言，CE250 测试按实际菜单价格动态选择买/不买。
  * **设置 API**：`crate::settings::GlobalSettings` + `Game::{settings, live_settings,
    set_settings, sync_live_settings, apply_settings, save_system_settings}`；System.sav
    part2 原子写回（.new+rename），play.rs 启动/F12/退出时应用与落盘；`Game::system_save`
    与 `base_save` 分离，读档槽不会污染全局设置模板。m3_settings_persist 10 条。
  * **存档编码**：官方存档 vardb 文本 = CP932 模板 + GBK 汉化混排，无 UTF-8。`set_text`
    未修改保留原字节、新文本 GBK（不可往返时 UTF-8 回退）；`db.rs::apply_saved_database`
    改 `decode_wolf_str`。vardb 段 load→save 0 字节差、44 个非 ASCII cell 不再重编码；
    SavePart5 数字字段也改为保留原记录（m3_save_byte_fidelity 4 条），因此
    `Game::load_save → save_to` 对 SaveData01/02 现在**逐字节完全相等**
    （293,742 / 294,130 B，含 header checksum），二次往返稳定。
    新增 wolf-save/tests/vardb_encoding.rs（9 条）。
  * **文本图保真**：Picture 保留原始 md1，未修改文本图 70/70 逐字节写回
    （m3_save_text_fidelity 4 条）。
  * **新游戏 vardb**：`Databases::seed_vardb` 补全空模板（30 类/1052 配置），
    m3_vardb_cdata_roundtrip 3 条。
  * **离屏截图可用**：wolf-render 有界初始化/回读 + backend/adapter 覆盖；`wolf-cli
    capture` 稳定出 1024x576 PNG。字体发现改为本作 `07やさしさゴシックボールド.ttf`
    优先 + *.ttf/*.otf/*.ttc 回退；`capture --map` 黑屏根因是 ev0 开场
    `cg/blackscreen.jpg`，CLI 侧停掉一次性 autorun 页后 SampleMapA 0%→92.8% 非黑。
  * **音频**：修 one-shot SE 的 DC 尾巴；wolf-audio 15 条离线契约测试。
  * **F12**：play.rs 重建 Game 并 boot。
  * **测试**：删除姊妹作 m6_night_menu/m6_training_menu/time_system；新增
    m3_endings(6)、m3_night_interaction_e2e(6)、m3_save_text_fidelity(4)、
    m3_perf_baseline、m3_map_click。
  * **地图 ActionKey 点击层已实现**：`MapRuntime::action_key_at`（事件 tile+collision
    命中、最小面积优先、跳过运行中页）＋ Game 在无消息/无 choice 时把新左键或悬停处 OK
    路由过去；ev5 保存、ev10 状态、ev21 夜间结束已端到端（m3_map_click 7 条）。
    PlayerTouch 仍在定屏地图上不支持。已知残余重叠：夜间 UI 的 parallel 页自行轮询
    鼠标，ev1-4 的 trig0 命中区可能与图片热区同时收到一次点击（数据条件已 gate 大部分）。
  * **字体/截图**：system Microsoft YaHei（msyhbd.ttc）优先，`capture` 已重新出图。
  * **其他后续**：`capture --map` 的负层 z-order 观察（-1 blackscreen 在 -10 背景之上，
    属预期淡入层）；tile quad 缓存（性能候选 2）。

* 2026-10-31（M3 收口提交）：
  * 本地提交 `07ab89b`「M3: complete runtime — retail PRNG, save fidelity, settings,
    capture」（74 文件，+18,607/−1,112）；**未推送远端**（用户要求本轮不做远程操作）。
    工作树干净。
  * 终验（`work/out/final_check.log`）：默认 `cargo test -q --workspace` exit 0；
    `WOLF_DATA_ROOT=work/Data cargo test -q --workspace --no-fail-fast` **75 个 test
    target 全 ok**；`verify` **PASS 64 / 1 SKIP(dxarchive.header)**；`verify --wolf`
    **PASS 72 / 0 pending**（1,361/1,361 字节相等，179,877,496 B）；SaveData01/02、
    System.sav 与安装目录原件 MD5 一致（测试未污染数据）。
  * capture 冒烟：1024x576、512,331/589,824 非黑（86.9%）、字体 msyhbd.ttc；仅 1 个
    缺字形 '׳'（系统字体覆盖问题，非渲染 bug）。
  * 计数更正：`m3_map_click` 实际 **8** 条（上文「7 条」为准入时的旧数）。
  * **下一次接手的入口**：从 `07ab89b` 继续；M4 优先级见 `docs/M4_PARITY.md` /
    `docs/M4_PERF.md`（设置 UI、tile quad 缓存、SoundCmd.frames 语义、
    ActionKey 命中框细化、v8 命名审计、100 日长链与打包）。

* 2026-10-31（M3 推送 + Lead 复验）：
  * 模型额度恢复后重读交接；检查 `07ab89b`/`7c79d77` 两条本地提交：无 Claude/Anthropic 尾注，作者为 imoto lead，按用户授权可推送。
  * Lead 复验：默认与 `WOLF_DATA_ROOT=work/Data` 的 `cargo test -q --workspace` 均 exit 0（各 **75 target**，0 failed）；`verify` **PASS 64 / 1 SKIP**；`verify --wolf` **PASS 72 / 0 pending**（1,361/1,361）。
  * 已推送 `origin/master`：`c167c85..7c79d77`，工作树干净。
  * **下一步**：按 `docs/M4_PARITY.md` / `docs/M4_PERF.md` 推进 M4（设置 UI、tile quad 缓存、SoundCmd.frames、ActionKey 命中框、v8 命名审计、100 日长链与打包）。

* 2026-10-31（M4 对等打磨：HUD/读档/渲染修复 + 收口）：
  * **M4 已完成项**：tile quad 缓存（`crates/wolf-game/src/tilemap.rs`，A 0.430→0.070ms、
    E 帧 0.202→0.173ms，`m4_tile_cache` 3 条）；SoundCmd.frames 的 BGM 淡入/SE 延迟
    （`crates/wolf-audio/src/{mixer,engine}.rs`，`m4_soundcmd` 11 条）；100 日长链
    （`crates/wolf-game/tests/m4_long_chain.rs`，v99==100、HAPPYEND 选项与 v201=1）；
    v8 语义审计（`docs/M4_V8_AUDIT.md` + `m4_v8_semantics` 5 条：v8=夜间可活动上限
    23..26，不是行动力）；发布打包（`tools/package.ps1` / `tools/package.sh` /
    `docs/PACKAGING.md`，产物 work/out/dist，不提交二进制）。
  * **本轮修复四个玩家可见缺陷**（详见 `docs/M4_HUD.md`）：
    1) 负号图片被误当全屏层（`crates/wolf-game/src/picture.rs`），HUD 保存/数据图标
       不再放大、status01 不再拉成黑罩；`m4_screen_layers` 2 条。
    2) `decode_wolf_str`（`crates/wolf-format/src/bytes.rs:251`）把 GBK「强壮」
       `C7 BF D7 B3` 误判为合法 UTF-8，姓名乱码；改为 UTF-8/CP932/GBK 打分候选；
       `vardb_encoding` 10 条。
    3) 读档前未跑完 CE48 初始化，行动力/精力被 CE70/CE124 清零；新增
       `Game::prime_engine`（`crates/wolf-game/src/game.rs:776`），capture 与
       Entry::Save 先 prime 再 load；`m4_hud_status` 2 条。
    4) 数据库值 magic `1_100_000_000 + row*100 + col` 未解码，CE242 把精力上限写成 9；
       `crates/wolf-vm/src/magic.rs` 新增 DbCell，exec op111/op121 走 host DB 读写，
       `crates/wolf-game/src/game.rs:1883/1901` 实现。HUD 恢复「行动力60/65 精力 3/3」。
  * **验收**：`WOLF_DATA_ROOT=work/Data cargo test -q --workspace` exit 0；
    `verify` PASS 64 / 1 SKIP；`verify --wolf` PASS 72 / 0 pending（1,361/1,361）。
    读档截图 `work/out/shots/bedroom_hudfix.png` 94.1% 非黑，HUD 与实机参考一致。
  * **仍待办（M4 收尾）**：`capture --event 238` 状态面板需点击/输入才滑入（capture
    需补触发路径）；设置 UI 与键位重绑定尚未做可视界面；msyhbd.ttc（TTC）字体支持待确认。

* 2026-10-31（M4 设置屏排版 + play 读档初始化）：
  * **CE132/CE95 设置界面已可视**（详见 `docs/M4_SETTINGS_UI.md`）：
    修复 `\f[0]` 字号（`crates/wolf-game/src/textpic.rs`）、文本 `290` 位移
    （`crates/wolf-game/src/game.rs` `text_quads` + `picture.rs` `effect_offset`）、
    1/10 字符格 UI 块缩放（`crates/wolf-game/src/picture.rs` `Screen::ui_scale_for`，
    块内任一非内置窗口宽或高超两倍屏即 10x；CE264 `10240x720` 也正确命中）、
    无 window 的 CursorBase 窗口图元、head `0x400000` 保留 290 位移
    （`crates/wolf-vm/src/exec.rs` `PictureCmd.keep_shift`）。
  * 新增 `crates/wolf-game/tests/m4_settings_ui.rs` 2 条；`m3_visual_text` 的
    CE264 文本 quad 期望 5→7（应用 290 位移后的正确分栏）。
  * `crates/wolf-cli/src/play.rs` 的 `Entry::Save` 也改为 `prime_engine()` 后再
    `load_save`，与 capture 一致，避免 CE48 初始化把恢复的行动力/精力清零。
  * **验收**：`cargo fmt --all`；`cargo test -q --workspace` exit 0；
    `verify` PASS 64 / 1 SKIP；设置截图 `work/out/shots/settings_final2.png`
    100% 非黑，九行设置 + 底部说明可读。
  * **仍待办**：`capture --event 238` 状态面板需合成点击/输入；实机键位重绑定与
    设置交互需用户截图后核验；msyhbd.ttc TTC 支持待确认。

* 2026-10-31（M4 读档恢复地图 Runtime）：
  * **修复缺陷**：`play --load-save` / `capture --load-save` 以前只 `prime_engine`+
    `load_save`，不启动当前地图的 MapRuntime，读档后停在静态卧室（`play.rs` 的
    `Entry::Save`、`main.rs` 的 `Entry::Save`）。
  * **实现**：`crates/wolf-game/src/game.rs` 新增 `resume_loaded_map()`：用 SavePart1
    的 `map_width/map_height`（64x36）与 35 个 object.var1（event id 集合）在
    `MapData/*.mps` 中唯一匹配到 SampleMapA；新增 `start_pages_loaded()`，把地图
    安装拆成 `install_map()` + `start_pending_loaded()`。`crates/wolf-game/src/map_runtime.rs`
    的 `start_pending_with(vm, loaded)` 在 loaded 首帧对无条件 `Trigger::Autorun` 页
    置 `starts_on_page = 1`（仍选中该页但不重启 ev0 新游戏开场），条件页照常重选。
  * **数据结论**：SavePart1 不保存地图事件当前页；object.var2/var3 是地图坐标的
    2 倍（ev1 x=8,y=18 => 16,36），不能当页号。页状态由恢复的全局变量重新求值。
  * **测试**：新增 `crates/wolf-game/tests/m4_load_resume.rs` 2 条（tilemap/HUD 文本；
    ev0 页仍选中但 coroutine 不在 live 集合、无开场 message/choice）。
  * **验收**：`WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --test m4_load_resume`
    2 passed；`cargo test -q --workspace` exit 0；`verify` PASS 64 / 1 SKIP。读档截图
    `work/out/shots/bedroom_resume2.png` 94.1% 非黑、行动力60/65、精力 3/3 正常，
    运行事件 [215,223,224,242,243] 不含 ev0。
  * **仍待办**：`capture --event 238` 状态面板需合成点击/输入；实机键位重绑定与
    设置交互需用户截图后核验；msyhbd.ttc TTC 支持待确认。

* 2026-10-31（临时汇报 + 文件清理 + 文档整理）：
  * **当前进度**：M0–M3 已推送；M4 已完成 HUD/读档数值与负号图片、设置界面排版、tile quad 缓存、SoundCmd.frames、100 日长链、v8 命名审计、发布打包。当前正在收尾的玩家可见缺陷：`play --load-save` 读档后只恢复画面与变量、不启动当前地图的 MapRuntime（`crates/wolf-cli/src/play.rs:84` Entry::Save 缺 start_pages）；状态面板 capture 需运行期状态行/点击路径。
  * **空间清理**：清理前仓库 9.4 GB，主要来自 `target/debug/deps`(5.1G)、`target/debug/incremental`(2.3G)、`target/release`(881M)、`work/out/saveprobe`(572M)、`target/debug/examples`(268M)、`target/ver6`(55M)。已删除整个 `target/`、`work/out/saveprobe`、`work/out` 下探针 exe/pdb，并删除未跟踪探针 `crates/wolf-format/examples/{ce_dump,mapsizes}.rs`、`crates/wolf-save/examples/savedump.rs`、`crates/wolf-game/tests/tmp_settings_probe2.rs`。清理后 `du -sh .` = **231 MB**（保留 `work/Data` 176M、`work/out/dist` 发布产物、`prt sc/` 用户截图）。
  * **注意**：`target/` 已清空，下一次跑测试/verify 前先 `cargo build -q --workspace`。清理规则已写入 `AGENTS.md` §7。
  * **文档整理**：新增根 `README.md`（项目总览/快速开始/目录结构）、`docs/README.md`（全量索引：交接、基线、各里程碑、M3 专题、调研资料、维护规则）、`docs/research/README.md`（调研资料说明，强调 HANDOFF §7 为采信/推翻口径）。

* 2026-10-31（M4 状态面板相对坐标 + 截图收口）：
  * **根因**：CE238/CE239 的显示分支用 op150 **head bit 0x10000 = 相对当前图片坐标**。
    面板隐藏时 Draw 到 x=-305，显示时 Draw/Move 都相对 +(305,0) 落到 x=0；动态文本
    321..325 也从各自隐藏坐标平移 (+305,0)。旧实现把相对值当绝对坐标，面板停在 305、
    文本全叠在 (305,0)。
  * **实现**：`crates/wolf-vm/src/exec.rs` 的 `PictureCmd` 新增 `relative: bool`，
    `decode_picture` 解析 `head & 0x0001_0000`；`crates/wolf-game/src/picture.rs` 新增
    `picture_args(cmd, base_x, base_y)`，Draw/Set 以当前 slot、Move 以 `Pose::of` 的当前
    x/y 为基底，相对偏移 0 表示 +0（不走 UNCHANGED），其余字段照常 merge。
  * **截图**：`./target/debug/wolf-cli.exe capture --map SampleMapA --load-save
    work/Data/Save/SaveData01.sav --event 10 --var 15=99 --pointer 100,200 --frames 60
    --out work/out/shots/status_panel8.png` → 房间+HUD+左侧状态面板，90.1% 非黑；
    文本位置 321 (240,90)/322 (75,405)/323 (245,410)/324 (245,465)，与实机截图一致。
    pointer 必须落在面板内（面板在 x=0 后 400,200 已出界，event11 会再隐藏）。
  * **测试**：`picture::tests` 增 3 条（相对 Draw/Move、绝对 Move 回归）；
    `m3_status_panel::ce238_relative_panel_lands_at_the_left_edge`（self600=0 隐藏→
    self600=1 显示，注意 group6 平坦索引是 600 不是 0）；`m3_hud_buttons` 与
    `m3_map_click` 旧期望 305 全改为 0，hover 指针改到面板内/外的新位置。
  * **验收**：`WOLF_DATA_ROOT=work/Data cargo test -q --workspace` 全绿（含所有数据
    测试）；`verify` PASS 64 / 1 SKIP。文档 `docs/M4_HUD.md` §1/§6、
    `docs/M4_PARITY.md` §6/§8 已更新；临时探针 `zz_probe_status.rs` 已删除。
  * **仍待办**：夜菜单静态截图仍需合成输入/点击；实机键位重绑定与设置交互需用户截图
    核验；TTC 字体 capture 已实测输出 msyhbd.ttc。
  * **当前进度**：M0–M4 主体完成，M4 剩余仅夜菜单截图与实机键位/设置核验。

* 2026-10-31（M4 夜菜单截图 + 字体符号 fallback）：
  * **夜菜单截图**：`run_capture` 新增 `save_event` 参数；`Entry::Save` 在
    `resume_loaded_map` 后调用 `game.start_event(id)`，解决 `--load-save` 抢占
    `--event` 导致夜菜单事件不启动。命令：
    `wolf-cli capture --load-save work/Data/Save/SaveData01.sav --event 245 --frames 90
    --out work/out/shots/night_menu4.png`；结果 90.4% 非黑，房间+HUD+状态面板+
    夜菜单六项（开始交流/泡茶/泡澡/网上购物/今天就这样睡吧/0）。
  * **字体 fallback**：msyhbd.ttc 不含 U+25B6（光标 ▶）。`crates/wolf-render/src/text.rs`
    新增 `build_font_system_with(ttf, fallbacks)`、`TextRenderer::set_fonts` /
    `add_fallback_font`、`missing_chars`（primary+显式 fallback 都算覆盖）；
    `crates/wolf-render/src/renderer.rs` 同步暴露 `set_fonts` / `add_fallback_font`；
    CLI 新增 `system_fallback_fonts` 与 `install_font_fallbacks`，capture/play 均加载
    `C:/Windows/Fonts/seguisym.ttf`（platform common fallback 名 "Segoe UI Symbol"）。
    夜菜单 text stats 由 1 substituted 变 0 substituted，▶ 正确显示。单测
    `text::tests::a_named_fallback_covers_a_glyph_the_primary_lacks`。
  * **文档**：`docs/M4_PARITY.md` §6/§8 与 `docs/M4_HUD.md` §6 已更新夜菜单命令、
    save_event、相对坐标、字体 fallback。
  * **验收**：`cargo fmt --all`；`cargo test -q --workspace` 与
    `WOLF_DATA_ROOT=work/Data cargo test -q --workspace` 全绿 0 failed；
    `WOLF_DATA_ROOT=work/Data ./target/debug/wolf-cli.exe verify` PASS 64 check(s),
    1 SKIP（dxarchive.header）。

* 2026-10-31（M4 性能：文字宽度复用）：
  * **动机**：`Game::text_quads` 对每个文字图片先 `layout` 再 `measure` 同一串，等于每帧
    shaping 两遍（docs/M4_PERF.md §6.3/§9）。
  * **实现**：`crates/wolf-game/src/textpic.rs` 的 `Run` 新增 `pub width: f32`，
    `layout_with` 推进 cursor 时记录每个 chunk 的 advance；`crates/wolf-game/src/game.rs`
    的 `text_quads` 改用 `run.width + run.font_px`，删除重复 `measure`/`measure_with`。
    新增单测 `textpic::tests::run_width_matches_the_measured_advance`。
  * **验收**：同参数 capture 输出与改前 **逐字节相同**（`cmp` 退出 0）；同机稳定轮
    B `text_quads` 0.036 → 0.032 ms/call（约 11%），D 0.033 → 0.032，E 0.041 持平。
    `cargo test -q --workspace` / `WOLF_DATA_ROOT=work/Data cargo test -q --workspace`
    全绿；`verify` PASS 64 / 1 SKIP。文档 `docs/M4_PERF.md` §7/§9 已更新。
  * **注意**：跑全量数据测试时 `m3_settings_persist::save_system_settings_...` 偶发
    Windows `PermissionDenied (os error 5)` 写 `target/test-scratch/m3_settings/System.sav`，
    单独重跑即通过，属 Defender/索引瞬时锁，非代码问题。
  * **当前进度**：M0–M4 主体完成；M4 剩余仅实机键位/设置/音量听感核验（需用户操作）。

* 2026-10-31（本轮并行收口：文字排版完整缓存 + 夜间交互 e2e + SE stop 语义 + 最终验收基线）：
  * **task-47 文字排版完整缓存（Lead 接管 m4-perf 未完成部分）**：
    `crates/wolf-game/src/textpic.rs` 新增 `fingerprint(raw, ctx)`（静态 markup 直接
    hash；变量/代码转义用零 advance 布局解析后 hash 每个 run；含调色板 RGB）；
    `crates/wolf-game/src/game.rs` 新增 `TextQuadKey` / `CachedTextQuads` /
    `TextQuadCache` / `TextCacheStats` 与 `Game::text_cache_stats()`，
    `text_quads(&self)` 按 picture number 命中缓存、未命中走 `build_text_picture`，
    每帧 retain 可见图片；`set_font_metrics` 递增 `text_font_gen` 失效。
    `PictureVars` 的 `num/text` 原来用 magic base 直接问 `Variables`（后者按
    bank-local slot 存储），fallback 永远读到 0，改为 `get(index)` / `get_str(index)`。
    新增 `crates/wolf-game/tests/m4_text_cache.rs` 4 条：静态首帧 miss/次帧 hit 且 quad
    相同、`\v[0]` 7→8 失效、只改 x 失效、安装 ttf 失效。视觉：夜菜单 capture 与
    night_menu4 逐字节相同，状态面板 capture 与 m4_final_status_panel 逐字节相同。
    性能：m3_perf_baseline B/D/E text 0.036/0.035/0.044（与 §9 的 0.032/0.032/0.041
    同噪声带）；probe 读档卧室冷 0.1122 ms → 命中 0.0324 ms/call，菜单冷 0.1079 →
    0.0373；命中虽免 shaping，但 fingerprint/克隆成本抵消，稳态无可测收益也无回归，
    已在 docs/M4_PERF.md §7/§10 如实记录。
  * **task-48 夜间交互 e2e（test-adapt）**：新增 `crates/wolf-game/tests/m4_night_gaps.rs`
    3 条：v59 嫌恶感 `v64*100/18`（18/21/22/36→100/116/122/200）、射精感 v66 只在 120
    强制触发并清 v125、真实点 picture 1108 (984,552) 进 ev21 是/否分支选“是”后
    v100=0/v125=0 且 warnings=0。
  * **task-49 SE Stop 语义（m3-fixer）**：普查 247 条 opcode 140 → 73 条无文件名状态
    全是 stop-all（62 个 FreeAll 变体 + 11 个 DB-entry Play），无 per-voice 身份；
    补 `crates/wolf-vm/src/exec.rs` 解码注释/单测、`wolf-audio` 文档与 3 条
    `mixer_contract` 契约测试；docs/M4_PARITY §2 删除“单条 SE 无法单独停止”，遗留
    11 条 sysdb DBEntry Play 需 SysDatabase SE id 解析（独立后续）。
  * **task-50 最终验收（verify-baseline，预变更基线）**：HEAD 7204e56 上
    cargo fmt --all --check OK；cargo test -q --workspace 86 binaries 789 passed/
    0 failed/2 ignored；数据全量同；verify PASS 64/1 pending；verify --wolf
    PASS 72/0。6 图 work/out/shots/m4_final_*.png：title 84.9%、bedroom 94.0%、
    status 90.0%、night 90.4%、shop 28.7%、album 54.0%；contact 见
    m4_final_contact.png，报告 m4_pre_baseline.md。
  * **验收（本轮 Lead 已跑）**：cargo fmt --all；cargo test -q --workspace exit 0；
    WOLF_DATA_ROOT=work/Data cargo test -q --workspace 全绿 0 failed；
    verify PASS 64 check(s) / 1 SKIP（dxarchive.header）。
  * **task-50 最终验收（源码冻结 + 本轮全部改动）**：cargo fmt --all --check EXIT 0；
    cargo test -q --workspace = 88 test binaries，800 passed / 0 failed / 2 ignored；
    WOLF_DATA_ROOT=work/Data 同（800/0/2）；verify PASS 64 matched / 1 pending；
    verify --wolf PASS 72 matched / 0 pending，entries 1361、bytes_equal 1361/1361、
    read_failures 0。相对预基线 789→800 passed、86→88 binaries（+11：m4_text_cache 4、
    m4_night_gaps 3、mixer_contract +3、现有集成套件 +1）。6 图非黑：title 84.9%、
    bedroom 94.0%、status 90.0%、night 90.4%、shop 28.7%、album 54.0%；contact 与
    报告见 work/out/shots/m4_final_contact.png、m4_final_report.md。
  * **状态**：按用户 m07177 要求，本轮四个子任务收口并提交后暂停推进重构，不再开新任务。

* 2026-10-31（M5-A：高分辨率 / 无级缩放 / 全屏，首个切片）：
  * **动机**：用户 m07499 要求继续下一部分（M5 = 超越原版）。原版逻辑画布 1024x576，
    现有整数缩放让 1920x1080 只能 1x 加黑边；M5-A 只改 blit，不改任何游戏坐标/存档。
  * **实现**：
    * `crates/wolf-render/src/scaler.rs` 新增 `ScaleMode`（Integer 默认 / FitNearest /
      FitLinear，parse/label/next/is_fit）、`FitScaler` 与 `fit_scale`（分数因子
      min(w/1024,h/576)，允许 <1）、`Scaler::game_point` / `FitScaler::game_point`
      逆映射。
    * `crates/wolf-render/src/renderer.rs` blit 改为 nearest+linear 两个 sampler/bind
      group；`present` 按模式选 Scaler/FitScaler quad；新增 `set_scale_mode` /
      `scale_mode` / `fit_scaler` / `scale_factor` / `window_to_game`。
    * `crates/wolf-cli/src/play.rs` 新增 `DisplayOptions { mode, fullscreen }`；F9 循环
      integer -> fit-nearest -> fit-linear，F11 无边框全屏，F10 仍退出、F12 仍重开；
      标题显示因子与 windowed/fullscreen；鼠标走 `Renderer::window_to_game`。
    * `crates/wolf-cli/src/main.rs` 新增 `--scale integer|fit-nearest|fit-linear`、
      `--fullscreen` 与帮助文本；未新增外部依赖。
  * **测试**：scaler 新增 5 条纯函数测试（16:9 全屏因子 1.875/2.5/3.75、小窗口 1000x700
    -> 0.9766x 不裁切、NDC 比例、window->game 逆映射、ScaleMode parse/cycle）。
    `cargo test -q -p wolf-render --lib` 35 passed；`cargo build -q -p wolf-cli` exit0。
  * **边界**：capture 仍输出 1024x576 逻辑帧（证据链不与窗口缩放混），窗口/全屏观感需真实
    窗口；不改 Sys 104/105 相机、不改存档格式。
  * **文档**：新增 `docs/M5_BEYOND.md`，docs/README 登记 M5 行，根 README 状态更新；
    M5-B 调试器 / M5-C 成就 / M5-D 多语言 / M5-E Mod 列计划与约束。
  * **当前进度**：M0–M4 完成；M5-A 完成，M5-B..E 待做。用户 m07499 授权持续推进。

* 2026-10-31（M5-B：F3 运行时调试 overlay，第一切片）：
  * **动机**：M5 超越原版的第二切片。原版没有可观察的运行时状态；给玩家/开发者一个
    不依赖外部调试器的轻量 overlay，复用现有字体的符号 fallback。
  * **实现**：
    * `crates/wolf-cli/src/play.rs` 新增 `DebugOptions { overlay, vars }`、`run(..., display, debug)`
      与 `App { debug_overlay, debug_vars, fps }`；`build_text_items` 在消息之后追加
      `DebugSnapshot` 行（帧/fps/指令/picture/warning/sprite/text/鼠标/键位/最近事件/
      `--debug-var` 变量），16 px 白字 2 px 黑边，同一 glyph pass；F3 切换；fps 每秒结算。
    * `parse_debug_vars` 接受逗号/空格/空项并拒绝非数字；`debug_slot` 支持平面槽或
      magic `2_000_000+n`。
    * `crates/wolf-cli/src/main.rs` 新增 `--debug`、`--debug-var <ADDR,...>` 与帮助文本；
      未新增外部依赖。
  * **测试**：play tests 4 条（字段/变量行格式、outside pointer/no event、parse 拒绝垃圾、
    flat/magic slot），`cargo test -q -p wolf-cli` 17 passed。窗口 smoke：
    `play --load-save work/Data/Save/SaveData01.sav --scale fit-nearest --debug --debug-var 154,155 --until 5`
    exit0、141 frame、0 warning。capture 仍输出不带 overlay 的 1024x576 证据帧。
  * **文档**：`docs/M5_BEYOND.md` 增 M5-B 用法/实现/测试/边界，表内 M5-B 标已完成第一切片。
  * **当前进度**：M0–M4 完成；M5-A/M5-B 完成，M5-C..E 待做。用户 m07499 授权持续推进。

* 2026-10-31（M5-C：F2 游戏倾向/里程碑 overlay，第一切片）：
  * **动机**：原版 CE296「■プレイ傾向」把文本写死、只显示少量行；本切片在现有存档变量上
    做只读结构化快照和保守里程碑，不改 CE296、不改存档格式、不新建成就文件。
  * **变量来源**：v99 経過日数、v20 妹信頼度、v21 妹性興味、v22 妹感度、v23 妹機嫌、
    v154 警戒度、v187 イカせた回数（显示为“共同经历”）、v199 クリア、v201 100日到達、
    v202 パンツコンプリート；全部已在 m3_stats_collection 中钉住。
  * **实现**：
    * 新增 `crates/wolf-game/src/achievements.rs`：`PlayStats::from_vars`、
      `Milestone { id,title,detail,unlocked }`、`milestones(&PlayStats)` 9 条（10/30/100 天、
      信赖 100/350、兴致 100、共同经历 10 次、服饰收集、完成流程）；阈值沿用 CE296 的
      100/200/350 分档。
    * `crates/wolf-game/src/lib.rs` 导出 `achievements`/`PlayStats`/`Milestone`/`milestones`；
      `crates/wolf-game/src/game.rs` 新增 `Game::play_stats()` 与 `Game::milestones()`。
    * `crates/wolf-cli/src/play.rs`：`DebugOptions` 增 `stats` 字段、`App.stats_overlay`、
      `stats_lines`（摘要 + `[x] 标题 - 说明`，解锁绿色/未解锁灰色）；F2 切换，与 F3 层按行堆叠；
      `crates/wolf-cli/src/main.rs` 新增 `--stats` 与帮助文本。无新依赖。
  * **测试**：achievements 3 条；play stats 1 条；`cargo test -q -p wolf-game --lib` 246 passed，
    `cargo test -q -p wolf-cli` 18 passed。窗口 smoke：
    `play --load-save work/Data/Save/SaveData01.sav --scale fit-nearest --stats --until 5` exit0。
  * **文档**：`docs/M5_BEYOND.md` 增 M5-C 变量/用法/实现/测试/边界，表内 M5-C 标已完成第一切片。
  * **当前进度**：M0–M4 完成；M5-A/M5-B/M5-C 完成，M5-D/E 待做。用户 m07499 授权持续推进。

* 2026-10-31（M5-D：内容翻译目录，第一切片）：
  * **动机**：原版把中文对白/选项写死在数据里，换语言只能改包。本切片不改数据，只增加
    side-car UTF-8 TSV 目录，在 opcode 101 消息与 opcode 102 选项离开 VM 后按精确字符串替换。
  * **实现**：新增 crates/wolf-game/src/translate.rs（Translator/TranslateError，parse/load/
    translate/len/is_empty，支持 # 注释、空行、\n \t \\ 转义、重复键后者覆盖、错误带行号）；
    Game 增加 translator 字段与 set_translator/load_translation_file/translation_len；
    GameHost::show_message/show_choices 应用目录；main.rs/play.rs 增加 --translation <FILE>，
    贯通 play/capture/capture --map/--map-run，F12 重启重新加载；无新外部依赖。
  * **示例**：docs/translations/en.tsv、ja.tsv 只覆盖夜菜单六项（原字符串含尾随空格），
    docs/translations/README.md 说明格式与用法。
  * **测试**：translate::tests 5 条；game::tests::a_translation_catalog_rewrites_messages_and_choices；
    capture --translation docs/translations/en.tsv --event 245 输出
    choice ["Start a chat","Make tea","Take a bath","Shop online","Turn in for today","0"]，
    90.4% 非黑 0 warning；cargo build -q -p wolf-cli exit0。
  * **边界**：只精确替换消息/选项，不覆盖图片内文字或 F2/F3 overlay 标签；漏译回退原文；
    完整词条属内容作者/社区工作。
  * **当前进度**：M0–M4 完成；M5-A/M5-B/M5-C/M5-D 完成，M5-E 待做。用户 m07499 授权持续推进。

* 2026-10-31（M5-E：Mod 数据覆盖层，第一切片）：
  * **动机**：原版改地图/事件/数据库/图片要动整个安装目录；本切片新增可重复 --mod 目录，
    每个目录镜像数据树，运行时先查 mod 再回落 base。写存档仍写 base，不回写 mod。
  * **实现**：Assets 增加 overlays/with_overlays，resolve 按 overlays 逆序 + base 查相对路径；
    Game 增加 overlays/with_overlays，CommonEvent.dat、Game.dat、TileSetData.dat、
    Databases 及 .project、MapData 运行期读取都走 overlay；resume_loaded_map 同时扫描
    overlay 与 base 的 MapData；Databases::load_with_overlays 保持原 load 兼容。
    main.rs/play.rs 新增可重复 --mod <DIR>，贯通 play、capture、capture --map/--map-run，
    F12 重启保留 mod；地图 capture 的 TileSetData/mps 预读也走 overlay。无新外部依赖。
  * **测试**：assets 单测 a_mod_overlay_wins_over_the_base_asset；
    wolf-game/tests/m5_mod_overlay.rs（真实数据下 status01 330x576 被 overlay 2x1 替换）；
    wolf-cli 单测 later_mod_overlays_win_and_missing_files_fall_back；
    cargo test -q -p wolf-game --lib = 253 passed，cargo test -q -p wolf-cli = 19 passed。
  * **capture 实测**：--mod 放相同 status01 时输出与无 mod 逐字节相同；
    放 330x576 纯色替换图时输出不同（95.4% 非黑、0 warning），覆盖真实生效。
  * **边界**：只覆盖 data 文件，不碰 exe/渲染参数/opcode；整文件替换不做逐行合并；
    音频资产暂不纳入 overlay；存档格式与 base 一致。
  * **当前进度**：M0–M4 完成；M5-A..E 全部完成第一切片。用户 m07499 授权持续推进。

* 2026-10-31（M5-E 补音频 overlay：BGM/SE 也随 --mod 覆盖）：
  * **动机**：M5-E 第一切片只覆盖数据文件，音频仍从 base 根加载，mod 换 BGM/SE 不生效；
    本次把同一组 --mod 接进 wolf-audio，补齐数据/音频一致的资源包语义。
  * **实现**：crates/wolf-audio/src/engine.rs 的 Engine 新增 overlays 字段，
    with_asset_root 委托 with_overlays，新增 with_overlays、null_with_overlays、overlays；
    resolve 按 overlays 逆序、当前目录、base、base/Data 查 BGM/SE 相对路径，绝对路径按原样。
    Game::enable_audio 改为 Engine::with_overlays(self.root, self.overlays)；混音/音量/
    淡入/延迟/SoundCmd 语义不变，Play 的 F12 重启仍保留 mod。
  * **测试**：新增 crates/wolf-audio/tests/m5_audio_overlay.rs（后置 overlay 优先、早置 SE
    命中、base 回落、缺失 None、反斜杠与绝对路径）；m5_mod_overlay.rs 增加
    game_audio_engine_receives_the_same_mod_overlays（enable_audio 后引擎 overlays 与
    BGM/theme.ogg 解析正确）；wolf-audio 1 passed，wolf-game 该文件 2 passed。
  * **边界**：BGM/SE 整文件覆盖，不重编码；音频格式仍须 ogg/mp3/wav 可解码；
    mod 不能注入新 SoundCmd/opcode，存档仍只写 base。
  * **当前进度**：M0–M4 完成；M5-A..E 完成第一切片，M5-E 含音频覆盖。用户 m07499 授权持续推进。

* 2026-11-01（M4 补：opcode 140 sound-type=0 的 SystemDB 条目解析）：
  * **问题**：少量 140 只带 arg0（无文件名字符串），此前一律按 Stop 处理；实数据 10 条：
    CE249 pc258/pc280 指向 SE row 0（决定音），SampleMapA ev15 p1..p8 指向 SE row 2（取消音）。
  * **解码**：arg0 低字节 options 高 nibble 1→BGS、2→SE、其它→BGM；entry=(bits>>8)&0xFFFF；
    sound-type=(bits>>24)&0xFF。sound-type=0 且 entry!=0xFFFF 即为 DB-entry 播放。
    0x00FFFF00 是 BGM stop 哨兵，0xFFFFFFxx 仍是显式 FreeAll，二者都不查库；负值守卫保留。
  * **实现**：wolf-vm Host 新增 sound_db(db_type, entry)->Option<(file, volume)> 默认 None；
    140 DB 分支向 host 取文件名与行音量，命令带显式音量时 arg[4] 优先。wolf-game
    Databases::sound_entry 从 SysDatabase type 1/2/3 的「ファイル名 / 再生音量」取值；
    GameHost 委托并失败时诊断 `140 sound DB {type}/{entry}: no entry`。未改 SoundCmd 结构。
  * **测试**：wolf-vm 新增 3 条（SE row 解析与音量、host 无答案仍记录播放、00FFFF00 是 stop）；
    wolf-game/tests/m4_db_sound.rs 用真实数据断言 SE row0=[SE]Enter.ogg/90、
    row2=[SE]Cancel.ogg/80、缺失 row None。cargo test -q -p wolf-vm = 95 passed；
    workspace 默认与 WOLF_DATA_ROOT=work/Data 均 exit0。
  * **verify**：64 matched / 1 SKIP；verify --wolf 72 matched / 0 pending、1,361/1,361 bytes equal。
  * **当前进度**：M0–M4 完成（音频 DB-entry 遗留已清）；M5-A..E 完成第一切片。
    用户 m07499/m08440 授权持续推进。

* 2026-11-01（M5-F：F4 消息回顾，第一切片）：
  * **动机**：原版消息窗口只保留一条，101 一到上一句就被替换；误触确认或长对话后
    无法重读。本切片把显示过的文本留在运行期，F4 打开只读回顾页，不改存档格式。
  * **实现**：wolf-game 新增 HISTORY_LIMIT=200 与 Game::history；GameHost::show_message
    在翻译后追加 frames=0 的副本并裁掉最旧端，活动 messages 仍只有一条；新增
    message_history/clear_message_history，start_title 与 savegame::load_into 清空。
    wolf-cli/play.rs 新增 App.backlog/backlog_scroll、纯函数 backlog_view（每页 18 条、
    页范围与总数标题、正文拼成单个 TextItem 由 cosmic-text 换行）；F4 开关、PgUp/PgDn
    翻页并夹紧到 len-18；打开时隐藏游戏文字并拦下键盘/鼠标输入，F10/F12 保留，F12
    重启关闭回顾页；不新增依赖。
  * **测试**：wolf-game 单测 a_transcript_keeps_order_and_is_bounded（203 条→200 条、
    最旧 line 3、最新 line 202、窗口仍 1 条）与 loading_a_save_clears_the_transcript；
    wolf-cli 3 条 backlog_view 测试（空历史、25 条首页第 8-25、PgUp 后 1-18、越界夹紧）。
    cargo test -q -p wolf-cli play::tests = 8 passed；WOLF_DATA_ROOT=work/Data
    cargo test -q -p wolf-game --lib = 255 passed；全 workspace 默认与数据根均
    832 passed / 0 failed / 2 ignored。
  * **verify**：64 matched / 1 SKIP；verify --wolf 72 matched / 0 pending，
    1,361/1,361 bytes equal。
  * **边界**：只保留运行期最近 200 条，不跨会话、不写 .sav；回顾页无背景面板/
    鼠标点击/富文本；F4 固定热键，未做重绑定；翻译目录在入 history 前应用。
  * **当前进度**：M0–M4 完成；M5-A..F 完成第一切片。用户 m07499/m08440/m10187
    授权持续推进。

* 2026-11-01（M5-D2/E2：翻译工具与 mod 清单/文本补丁，M5 收口）：
  * **动机**：M5 第一切片留下的两条已记录后续落地——翻译目录缺 authoring 工具和
    细粒度上下文键；mod 覆盖层缺清单/依赖声明，且只能整文件替换。本轮按用户要求
    继续 M5 剩余部分，不使用子代理。
  * **D2 翻译工具**：`wolf-cli translations` 新增 `--template`/`--check`/`--strict`。
    实测本作 **1,218 条静态字符串**（1,046 消息 + 172 选项）、**46 条变量相关**、
    1,476 个静态出现点；`en.tsv` 5/1,218，`--strict` 返回 1。模板右列为空，
    解析器把空翻译当占位（不会清空游戏文本）；原文列逐字匹配，含真实 TAB/CR/LF
    的条目跳过并在模板头注明。含 `\v`/`\self` 等变量转义的句子不进入模板和覆盖率
    分母。左列新增 `[msg]`/`[choice]` 前缀，作用域条目优先、无前缀条目兜底。
    实现：`translate.rs` 的 `Context`、`translate_in`、`SourceScan::from_common_events`
    （101/102 全事件扫描、`@n` 前缀剥离、NoVars 展开区分静态/动态）、`template`、
    `coverage`；CLI 读取 CommonEvent.dat 走 mod overlay。数据测试
    `m5_translation_scan.rs`，单测覆盖前缀/占位/覆盖率/未命中项。
  * **E2 mod 清单/文本补丁**：新增 `<mod>/mod.ini`（`name`/`version`/`requires`，
    `base` 为保留依赖名，缺省名用目录名）；加载前校验重名、保留名、自依赖、缺依赖，
    只校验不重排（`--mod` 顺序仍是优先级）。每个 mod 可在根目录放
    `translations.tsv`，按 mod 顺序合并，命令行 `--translation` 最后合并并最终生效；
    play/capture 启动打印 `mod: name version (dir)`。实现：`crates/wolf-game/src/mods.rs`、
    `GameError::Mod/Translate`、`Game::mods()/translator()/merge_translation_file`。
    `m5_mod_overlay.rs` 新增 mod 文本补丁 + 缺依赖两条真实数据用例；单测覆盖清单解析
    与全部依赖错误。
  * **验证**：默认与 `WOLF_DATA_ROOT=work/Data` 的 `cargo test -q --workspace` 均
    **exit 0，92 个 test result 全 ok**（wolf-game --lib 271、wolf-cli 21、
    m5_mod_overlay 4、m5_translation_scan 1 等）；`verify` **PASS 64 / 1 SKIP**；
    `verify --wolf` **PASS 72 / 0 pending**（1,361/1,361）。capture 实测：
    `[choice]开始交流 → Scoped chat`、mod 内 `translations.tsv → Mod chat`，
    90 帧夜菜单、0 warning。缺依赖报
    `mod error: mod 'broken' requires 'absent', which is not in the --mod list`。
  * **清理（AGENTS §7）**：删除 `target/debug/incremental`、`target/release`、
    `target/ver6`、work/out 里的旧 probe exe/py 与临时模板；`du -sh .` = **3.3G**
    （work 279M，其中 work/Data 176M；target 3.1G，保留可运行 debug 产物）。
  * **当前进度**：M0–M5 完成（A–F 第一切片 + D2/E2）。剩余均为可选后续：
    完整语言包内容、非文本文件的记录级二进制补丁、跨周目永久成就、键位重绑定。
    本地提交（未推送远端）。

* 2026-11-01（M6：输入层对等——`123` 选项字/等待位、改键闭环、`125`/`126` 编码、`121` min-max）：
  * **动机**：用户要求继续推进「对等/交互细节，先还原游戏本身」，明确完整语言包、
    模拟器热键重绑定、mod 记录级二进制补丁留作增强项，引擎内游戏不用的通用功能不做。
  * **`123` 掩码解码**：第二个参数是打包选项字（方向选择 0..8、决定 0x10、取消 0x20、
    副键 0x40、等待 0x80、设备字节 8..11），不是键位掩码；旧实现完全忽略它。
    证据：CE118 `0xB0` 注释「決定かキャンセルか、だけ受付する」、CE84 `0xB8` 只比较
    4/6、CE65 `0xF1` 的副键分支、CE59 用 `0x10/0x20/0x40` 三次单键轮询；与
    `wolfrpg-map-parser 0.4.1` 的 `BasicOptions`/`InputType` 结构一致。本作 93 条
    `123` 全部落在编码内（40 条带等待位）。
  * **掩码过滤**：`key::accepts`/`code_for` 只回报轮询请求的键；CE59 的「按键中断等待」
    不再被方向键触发。
  * **等待位阻塞**：`123` wait=1 且无键时设 `WaitState::Key`、不前进 pc；实测 CE251
    pc162「クリック処理」、CE249 pc257、CE297 pc32 都是「暂停画面等玩家点击」，旧实现
    直接冲过。`poll_waits` 每帧清除该状态以便重试。
  * **改键闭环**：`0x101`/`0x200` 设备轮询返回原始键码（键盘=扫描码+100，Z=144、
    X=145、C=146；手柄 301..303）。新增 `Game::raw_keys/raw_pad_keys`；`play` 用
    winit 物理键码表写原始码，决定/取消/副键读 `live_settings()` 的 Sys52..54，
    加固定别名 Enter/Backspace（`マニュアル01`：決定 Enter・Z・左クリック，
    キャンセル backspace・X・右クリック）。改键立即生效。
  * **`125`/`126` 编码修正**：两者第一字节是编辑器键位（决定 1、取消 2、副键 4、
    下 0x10、左 0x20、右 0x40、上 0x80），`126` 第二字节是模式（0 启用/1 禁止移动/
    2 禁止）。旧实现把 `126 [247]`（=启用全部）当禁令，导致开场后整局读不到按键；
    `125` 的方向位序也被读反（CE223 自动输入按反方向）。
  * **`121` 0x600/0x700 = min/max**：旧实现当赋值，CE132 音量行一按就把值钉到
    边界（实测 100→120）。数据里 0x600 出现 153 次、0x700 49 次，配对形式
    `[v, 下界, 0, 0x600]` / `[v, 上界, 0, 0x700]`（CE36 `v3=clamp(v3,1,v82)`）。
  * **音量实时生效**：`Game::frame` 检测 Sys100/102 变化即送混音器，设置界面里改音量
    立刻可听（原来只在下一次 boot 生效）。
  * **按键重复**：用户实机确认原版按住方向键会按「キーリピート速度」连续滚动。
    `Game::update_key_repeat` 用 Sys15（首次延迟）/Sys16（重复间隔）实现：首帧回报、
    延迟后回报、之后每间隔回报一次（回报只在该帧有效，与原版按时间节拍一致）。
    只有带等待位的 `123` 用它，非等待轮询仍是原始电平（CE132 的改键捕获循环自己
    读 Sys16 实现重复，正好印证这个划分）。CE48 启动时调 CE115 写入这两个值，
    设置界面改速度也即时生效。既有测试改成按「可观察结果」等待（`hold_until`），
    不再用固定帧数按住。
  * **测试**：新增 `crates/wolf-game/tests/m6_input_parity.rs` 5 条（CE132 改键捕获、
    按住方向的重复速度、
    CE251 点击继续阻塞、音量实时进混音、注册地图无 PlayerTouch）+ key.rs/exec.rs 单测
    （选项字解码、过滤、WOLF 位序、126 模式切换）。同时把依赖真实时序的既有测试
    改为在 `WaitState::Key` 时喂一帧决定键（m2_daily_loop、m3_audio_settings、
    m3_endings、m3_manual_rules、m3_menu_screens、m3_newgame_persistence、
    m3_ui_screens、m3_week7、m3_week_loop、m4_long_chain）。
  * **验证**：`cargo test -q --workspace` **exit 0，93 个 test result 全 ok，860 条
    测试通过**；`verify` **PASS 64 / 1 SKIP**；`verify --wolf`（zh-CN `Data.wolf`）
    **PASS 72 / 0**（1,361/1,361 字节相等）。
  * **PlayerTouch 结论**：注册的 5 张地图没有 trigger-3 页，只有未注册样例
    Dungeon/SampleMapB 各 2 页；继续不建模，并用 `m6_input_parity` 数据断言锁定。
  * **ActionKey 结论**：命中框沿用 WOLF 的 tile + range extension（左上锚定、
    `(1+扩展)×16`），与画面按钮的偏差来自数据摆放（结束按钮图元 (935,505) 90×70，
    命中框 (976,544) 起），不是端口偏差；边界仍由 `m3_map_click` 钉住。
  * **当前进度**：M0–M6 完成。可选后续只剩增强项：完整翻译内容、mod 记录级二进制
    补丁、跨周目成就、模拟器热键重绑定。本地提交并推送。

* 2026-11-01（M7：三项增强——完整英语语言包 / mod 记录级二进制补丁 / 模拟器热键重绑定）：
  * **范围**：用户要求补齐三项增强（跨周目成就未选）：① 完整语言包内容；② 非文本文件
    的记录级二进制 mod 补丁（原先只能整文件覆盖）；④ 模拟器热键重绑定（原先固定
    F2/F3/F4/F10/F12）。Lead 定默认：英语完整包、记录级补丁+字节区间兜底、配置文件+CLI。
  * **① 语言包（wolf-game/translate.rs + docs/translations/en.full.tsv）**：模板/目录两列
    都支持 `\n \t \r \\` 转义；`SourceScan::template()` 不再跳过含字面 TAB/CR/LF 的静态句，
    模板 1218 static（1046 message / 172 choice）+ 46 动态、共 1224 行无 skipped；
    `Translator::parse` 先对源列 unescape（其它反斜杠序列如 `\c[6]`/`\v[12]` 原样透传），
    向后兼容旧目录。产出 `docs/translations/en.full.tsv` 全量英文 1218 行，
    `wolf-cli translations --strict` **1218/1218 static (100%)，0 missing / 0 unused**。
    新增 docs/M7_I18N.md、补 docs/translations/README.md。译文为机翻风格、完整对齐，
    如需出版级可后续人工润色（非缺陷）。
  * **② 记录级补丁（wolf-format/database.rs + wolf-game/patch.rs）**：`Database` 新增字节
    级序列化 `to_bytes`（保留 version_header/trailing 与每串原始 t_str chunk，未改串逐字节
    重放、改过的按 UTF-8 重编码）与结构化 `set_number/set_text/set_cell`（ColumnRef
    Index|Name）。真实数据三库 `parse→to_bytes` **逐字节一致**（DataBase/CDataBase/
    SysDatabase，`WOLF_DATA_ROOT` 绝对路径实跑 3 passed）。`PatchSet::apply_bytes` 两阶段
    （先全量校验等长/越界/expect，任一不符整文件不写），`apply_records` 落 set_cell；
    db.rs 在 parse 前应用字节补丁、引擎默认值后应用记录补丁，assets.rs 在解码前应用资产
    字节补丁；坏补丁 eprintln 忽略、不 panic、不加 CLI 参数。新增 docs/M7_PATCH.md、
    tests/database_serializer.rs(3)、tests/m7_patch.rs(5)。
  * **④ 热键重绑定（wolf-cli/hotkeys.rs）**：`HotkeyConfig`（stats/debug/backlog/scale/
    fullscreen/quit/restart）+ `parse/load` + `parse_named_key`（F1..F12 与常用命名键），
    非法键/未知动作回退该动作默认；main.rs 加 `--hotkeys <FILE>`，play.rs 7 处硬编码 F 键
    改查配置。默认映射与原固定键一致（F2/F3/F4/F9/F11/F10/F12）。新增 docs/M7_HOTKEYS.md、
    tests/help_hotkeys.rs。
  * **验证**：`cargo build -q --workspace` exit 0。`cargo test -q --workspace`（默认无数据）
    **exit 0**；`WOLF_DATA_ROOT=work/Data` 用**绝对路径**真跑时，除 7 条**既有、非本轮**
    的姊妹作期望值/事件语义差异失败外全绿（用 HEAD 干净工作树复现同样 7 条，属早已记录的
    已知差异，不是回归；本轮未改这些模块语义）；本轮新增的序列化往返 3 + m7_patch 5 +
    翻译/热键测试全过。`wolf-cli verify` **PASS 64 / 1 SKIP**。
  * **重要提醒（数据测试路径）**：`cargo test` 以各 crate 根为工作目录，`WOLF_DATA_ROOT=work/Data`
    这类相对路径会被解析到 crate 目录而**静默 skip**（于是「全绿」）；要真跑必须用绝对路径
    （如 `WOLF_DATA_ROOT="$PWD/work/Data"`）。已在 README 快速开始与 AGENTS §2 补注。
  * **清理（AGENTS §7）**：删除 target/debug/incremental、target/release、target/ver6、
    work/out 下临时日志/翻译中间件；`du -sh .` = **4.1G**（work 251M、work/Data 176M、
    target 3.8G，保留可运行 debug 产物）。
  * **当前进度**：M0–M7 完成。可选后续仅剩：跨周目永久成就；语言包可人工润色；补丁/
    热键的更多用法。本地提交（未推送远端）。
  * **2026-11-01（玩家可见缺陷修复：窗口尺寸 / 标题三选项 / 场景暗块）：** 用户实机反馈 4 项——
    (1) 窗口比画面大、四周黑边；(2) 初始界面看不到应有的三个选项；(3) 部分场景出现深灰半透明
    方块；(4) 场景切换闪烁；并指出此前「验收通过」只覆盖 `verify` 的数据/计数层，不渲染实时窗口、
    不验收画面与交互，该批评成立（`verify`/`capture` 都不等于实机玩法验收）。
    * **(1) 窗口尺寸** `crates/wolf-cli/src/play.rs`：原 `resumed()` 固定
      `with_inner_size(PhysicalSize::new(1920,1080))` + 默认 `ScaleMode::Integer`，1080p 对
      1024x576 只能 1x → 画面居中、四周巨大黑边。新增 `fn window_size_for(monitor)` 按主显示器
      取能容纳 1024x576 的最大整数倍（宽留 6%/高留 10%），非全屏时用它作初始窗口；无 monitor→1x。
    * **(3) 场景暗块** `crates/wolf-game/src/picture.rs` 的 `Screen::ui_scale_for`：`oversized`
      （十分之一 UI）判定误把停靠在屏外（block 160 消息窗 picture 16000，window 7680x1200 @(512,3840)）
      的窗口按 /10 缩放并拉回屏内，形成约 768x120 的中心暗块。修法：`oversized` 谓词增加 `parked`
      排除（`x.abs()>SCREEN_W*2 || y.abs()>SCREEN_H*2` 的停靠项不参与判定）。
    * **(2) 标题三选项可见** `crates/wolf-game/src/choice.rs`：CE42 把选择锚点 Sys3/Sys4 写成
      -1000/-1000（停靠屏外），`layout_at_sized` 忠实判屏外→None→不画，标题只剩背景。修法：
      越界锚点回退为**居中面板**（`(SCREEN-width)/2,(SCREEN-height)/2`）；新增 `option_label` 把
      裸键 `menu1/2/3` 按 CE42 分支注释映射为「开始游戏/读取存档/退出游戏」，`size()` 与 `draw()`
      都按显示标签测宽/绘制（原按 "menu1" 测宽致中文被裁）；`game.choices.options` 原始键不变。
      同步把 `tests/m3_title_visibility.rs`、`tests/m3_title_mouse.rs` 的 `layout_at_sized(-1000,-1000)
      .is_none()` 断言改为「回退为屏内居中面板」，其余命中测试仍过。
    * **验证**：`cargo build -q --workspace` exit 0；`cargo test -q --workspace`（默认无数据）exit 0；
      `WOLF_DATA_ROOT=<绝对> WOLF_GAME_DIR=<不存在>` `cargo test -q -p wolf-game` = 283 passed /
      7 failed，7 条与干净 HEAD 复现的既有姊妹作期望值/事件语义差异**完全相同**（db 2 + auto_events 3
      + game 2），非本轮回归。标题套件（visibility 4 / mouse 7 / menu_screens 3 / mouse_menu 12）全过。
      离屏截图 `work/out/title_menu_final.png`：标题美术上居中深灰面板显示「▶ 开始游戏 / 读取存档 /
      退出游戏」；暗块(block 160)、设置界面、状态页、读档 HUD 截图均干净。
    * **仍未闭环**：(a) **场景切换闪烁**离屏 capture 不能复现（疑与已修的消息窗暗块同源——切换时该窗口
      图形短暂出现；或 `switch_map` 调 `clear_screen_layers` 后新图未画的 1 帧、present 两 pass
      `Clear(BLACK)`+blit），需用户实机复测确认；若仍在请指明具体切换时机。(b) **取消读档软锁**是既有
      gap（`m3_title_mouse` 有用例断言取消后菜单不恢复；M3_TITLE_UX §4 建议#2 未实现），本轮未动，避免
      误触发 boot 与 EndGame。(c) H-MENU-1（原版标题菜单精确位置/是否用 menuN 图片按钮）仍未实测，
      当前用居中文本+中文标签为最小可见修复。

  * **2026-11-01（补充：场景「闪烁 / 纯色+点状背景 / 黄色背景」根因与修复）：** 用户实机复现的两类
    闪烁——「开始游戏后闪出纯色+点状背景」「确认属性到正式游玩前的对话背景是黄色」——经离屏逐帧取证，
    定位为**地图占位瓦片层外露**：
    * **根因**：5 张注册地图（TitleMap / SampleMapA / Map003 / Map024 / Map031）的 tile 层全部使用
      WOLF 编辑器**自带示例 chip**（绿底白点草皮 autotile1 code0 + 米色块 code4），而实际画面永远由
      整屏 CG 或 cg/blackscreen.jpg 覆盖。在标题画 30 帧淡入期间、开场问候（SampleMapA ev0
      pc304-315 只画妹妹立绘、未画房间 CG）期间、以及地图切换（130）等「CG 尚未盖住」的瞬间，就透出这
      层占位瓦片 → 绿点 / 米色。取证：capture 逐帧 pic 列表（frame400 只有 blackscreen alpha 0.00 +
      妹妹 900-903、无房间 bg；frame600 有 bg_001_03 全屏）；work/out/map_*.png 逐图均为同一套示例 chip。
    * **修复**：crates/wolf-cli/src/main.rs 的 build_capture_frame 增加 include_tiles: bool ——
      **玩法路径**（普通 capture/report）传 false，不再叠加占位瓦片层，未覆盖瞬间回退到 renderer 的
      黑场 clear；capture --map（拍照地图数据本身）仍传 true 保留瓦片。crates/wolf-cli/src/play.rs
      的 rebuild（实时窗口）同样只合成 picture 层、不画瓦片。正常房间因整屏 CG 覆盖不受影响。
    * **验证（绝对数据根，离屏逐帧像素统计）**：标题 frame82 由绿点→**纯黑**（black 100%），frame110/900
      标题美术 + 「开始游戏/读取存档/退出游戏」菜单正常；开场问候 frame390 由黄→黑（black 72%，余为 HUD/
      图标/消息框），frame410/470 黑，frame600/1400 与 --load-save SaveData01 均为正确的整屏房间线稿 CG
      （mean≈195，black≈6%）；capture --map TitleMap 仍显示示例瓦片（green 46% / beige 22%），调试路径
      未受影响。cargo build -q --workspace exit 0；cargo test -q --workspace（默认无数据、
      WOLF_GAME_DIR 指不存在目录跳存档漂移）exit 0；WOLF_DATA_ROOT=<绝对> cargo test -q -p wolf-game
      = 283 passed / 7 failed（与既有 7 条姊妹作期望值/事件语义差异完全相同，非回归）。注：studio logo 帧
      （t_60）的橙米色是**合法 splash 美术**，非瓦片外露。
    * **说明**：仍需用户实机复测确认真实窗口 present 路径下的「闪烁」已消失；离屏 capture 与实时窗口共用
      同一合成逻辑（本次两处都已改），但 present/swapchain 侧若有独立抖动需另查。

  * **清理（本轮，AGENTS §7）**：删除 target/debug/incremental、target/release、target/ver6 与临时文档块；
    du -sh . = 4.2G（target 3.8G、work 333M、work/Data 176M、.git 7.7M，保留可运行 debug 产物与 work/out/dist）。
  * **2026-11-01（工具：`wolf-cli assets` 素材摆放目录）**：用户问「能否从游戏文件还原素材分布以降低重构摆放成本」→ 已把临时脚本固化为 `wolf-cli assets` 子命令（crates/wolf-cli/src/main.rs），文档见 docs/ASSETS.md。
    * **能力**：聚合每个 op150 绘制的图片资产（asset/category/draw_sites/distinct_placements/scopes/first_placement）；`--coords` 逐点列出 scope/event/slot/action/anchor/layer/opacity/x/y/scale/blend；`--include-maps` 并入 MapData/*.mps 事件页；`--format tsv|json`；`--filter`；`--out`。
    * **数据来源**：CommonEvent.dat 的 op150 params（head=arg0 kind/anchor/action、number=arg1 层槽、长形式 opacity/x/y/scale/blend），与 wolf-vm decode_picture 一致。
    * **实测（本作数据）**：CE 侧 561 资产 / 2162 绘制点；并入 8 张地图后 660 资产 / 2431 绘制点。样例 cg/blackscreen.jpg 55 点 / 6 摆法 slot100@(0,36)。
    * **验证**：cargo build -q -p wolf-cli exit0；cargo test -q -p wolf-cli 34 passed（含 3 条新增 asset 单测）；cargo test -q --workspace（无数据）exit0；json 输出经 Node 解析通过。
    * **边界**：DB 默认值、引擎几何（九宫格窗口、文本度量、choice 越界、1/10 UI 缩放、过渡、present）不在数据里；kind 1/4 为字符串变量引用运行时求值。
* 2026-11-02（标题界面修正：原版图片按钮菜单，替换此前的居中文字面板）：
  * **起因**：用户（m01452）指出「标题界面你就实现错了」。核对 prt sc 实机截图（原版标题截图 = prt sc/{925C85F6-AA44-470B-8C47-A1EEBA03388B}.png，NCC 0.978 对 work/Data/SystemFile/TitleGraphic2.png）后确认：原版标题菜单是**三张手写风格图片按钮**，位于 x=10、y=400/450/500（各 240x52），由条件事件 **CE43「┗オリジナルタイトル画面Ｂ」** 绘制；此前实现的「屏幕居中深色文字面板 + menu1→开始游戏 中文标签」与原版不符，已废弃。
  * **数据证据**：CE43 run_condition==2，条件 global v0(2000000)==0（仅标题成立）；[5-7] 画 menu1_b/2_b/3_b 于 (10,400/450/500) layer 3/4/5，[8] op111 按 Sys20==0/1/2 叠画对应 menu*_a 高亮；[55] 结束。全 CommonEvent 无事件调用 500043，仅 TitleMap ev2 slot[57] op210 调 CE42；CE43 由自动调度器在标题运行。
  * **实现**：
    * crates/wolf-game/src/auto_events.rs：SKIPPED 由 &[43] 改为 &[]，模块文档改写为「CE43 是标题菜单渲染器，须正常调度」；并新增 `title_menu_active` 门控——仅三键标题菜单打开时允许 CE43 运行（其 v0==0 条件在合成/边界状态也会成立，否则标题按钮会画到玩法场景上）。
    * crates/wolf-game/src/game.rs frame()：choice 打开且为标题三键菜单时，把 choice_cursor 镜像进 Sys20（vm.vars.set_sys(20, cursor)），使 CE43 高亮跟随。
    * crates/wolf-game/src/choice.rs：新增 is_title_image_menu() 与 title_image_layout()（固定命中行 (10,400,240,52)/(10,450)/(10,500)）；layout_at_sized 对标题菜单返回该图片行布局（供鼠标命中，与 -1000 锚点无关）；overlay/overlay_at/overlay_at_sized 对标题菜单返回空绘制，不再画文字面板。option_label 中文映射保留但标题路径不再用。
  * **测试**：crates/wolf-game/tests/m3_title_visibility.rs / m3_title_mouse.rs 改为断言固定图片行布局、屏上存在 Picture/menu1_*、无文字面板；新增 the_title_cursor_is_mirrored_into_sys20_for_the_image_highlighter（cursor 0/1/2 → Sys20 0/1/2）。CE43 加标题门控后，crates/wolf-game/tests/m2_daily_loop.rs 的 CE251 直启用例无需改动即恢复 pictures=74。
  * **验证**：cargo build -q --workspace exit0；默认无数据 cargo test -q --workspace exit0；WOLF_DATA_ROOT=<绝对> WOLF_GAME_DIR=<不存在> cargo test -q -p wolf-game = **283 passed / 7 failed**，7 条与干净 HEAD 完全相同的既有姊妹作期望值/事件语义差异（db 2 + auto_events 3 + game 2），**非本轮回归**；标题套件 title_visibility 4 / title_mouse 8 全过（绝对数据根实跑）。wolf-cli verify **PASS 64 / 1 SKIP**。
  * **离屏实证**：capture --menu-only --frames 200 输出 pic -2 标题美术 + pic 3/4/5 = Picture/menu1_b/2_b/3_b 于 (10,400/450/500)，choice 锚点仍 (-1000,-1000)、engine rect [10,400,240,152]、text 0 项，画面与原版截图一致；capture --answer 0（新游戏）进入 19:30 场景后屏幕无任何 menu*_* 图片，证明 v0 进入游戏后已非 0、CE43 不泄漏到玩法。
  * **仍未闭环**：M3_TITLE_UX §4 建议 #2（取消读档后重启标题）仍未实现，软锁依旧（m3_title_mouse 有用例断言“不恢复”）。
* 2026-11-02（A 任务：assets 数据库层导出 + B 文档《ENGINE_BEHAVIOR》）——用户 m02019 要求「先做 A+B，再做 C」：
  * **A（代码）**：`wolf-cli assets` 新增 **`--db-defaults`** 开关，切到数据库层导出（与资产行**互斥**，单独成一份 JSON 以保合法）。在 crates/wolf-cli/src/main.rs 新增 `fn run_assets_db(root,format,filter,out)->ExitCode` 与 `push_json_key`/`push_tsv_row`；在 `run_assets` 签名加 `db:bool` 并在 format 校验后 `if db { return run_assets_db(...) }`。导出内容：
    * 引擎默认值：`screen`(取 Game.dat，缺省 1024×576)、`coordinate_scale`=(w/32,h/24)、`window_skin`=SystemFile/WindowBase.png、`message_window` 按 CE63 布局规则推导（x=2*sx、w=sw−2*sx、h=7*sy、y=sh−h → 当前 (64,408,960,168)）。
    * `tables`：Sys/Data/CData 三套库的表清单（container/type/type_name/rows/fields）。
    * `cells`：Sys 侧**全部**单元格 + 名称型表（`fields=0`，如 文字列変数名/システム変数名/通常変数名）以 `field="name"`、`value=行名` 输出；Data/CData 仅在 `--filter` 时展开单元格（体量大）。`--filter` 按表名或类型索引子串匹配。
    * 快照：**98 张表 / 1381 单元格**。Sys6（システム変数名）直接给出消息窗/选择窗坐标、姿势游标、基础字号、消息速度等槽位名，可作对齐原版依据。
  * **A（文档/帮助）**：docs/ASSETS.md 增「DB 默认值导出（--db-defaults）」节并修正「覆盖与边界」；main.rs `print_help` 增 `--db-defaults` 说明（原 `--db` 属 dump 探针，已撞名，故用 `--db-defaults`）。
  * **A（验证）**：cargo build -q --workspace exit0；`assets --db-defaults`/`--format json`/`--filter 6` 均正常；work/out/db_defaults.json 用 Python `json.load` 通过（tables=98,cells=1381,msgwin=(64,408,960,168)）；wolf-cli verify **PASS 64 / 1 SKIP**；WOLF_DATA_ROOT=<绝对> `cargo test -q --workspace` = 其余 crate 全 ok，wolf-game 283 passed / **7 failed**（与既有干净 HEAD 完全相同的姊妹作期望值/事件语义差异：db 2 + auto_events 3 + game 2，**非本轮回归**）。
  * **B（文档）**：docs/ENGINE_BEHAVIOR.md（165 行，新增未跟踪）由子代理 944209e7 完成：§0 图例、§1 六类核心表（九宫格/文本度量换行/选择面板 H-MENU-1/1-10 UI 缩放/过渡淡入/present-swapchain，6 列含来源+现状+文件:行+核对方法）、§2 逐项说明、§3 **12 条需逆向/实测常量清单**、§4 获取途径与优先级。关键锚点：window.rs:62 nine_slice(3px)；message.rs:97/122 coordinate_scale 与 line_height=font+6；choice.rs:112/180-214/127；scaler.rs:21,23,27 + db.rs:159 + picture.rs:1046；renderer.rs:55/910 + play.rs:35。
  * **下一步 C**：用 rea（npx rea-agents，MCP 做二进制/运行时逆向）对原版 Game.exe 定点验证 §3 的 12 条常量。
* 2026-11-02（C 任务：原版 Game.exe 只读静态逆向，产出工具 + 报告）——用户 m02019「先做 A+B，再做 C（用 rea 等工具定点逆向验证引擎常量）」：
  * **工具链现状**：`npx rea-agents` v6.7.0 可运行，但 `doctor` = healthy:false——本机**无任何原生分析引擎**（hopper 仅 macOS、ghidra `GHIDRA_INSTALL_DIR` 未设、IDA 未配置、kuna/jadx 未设），rea 的 decompile/analyze 不可用；`inspect-binary-layout` 仅支持 ELF、不支持本作 PE32。可无引擎用的只有 `inspect-pe-resources`/`inspect-artifact`。
  * **替代方案**：用本机已有 `pefile 2024.8.26`+`capstone 5.0.7` 自建只读工具 **`tools/re/wolfpe.py`**（facts/strings/xref/disasm；按绝对 VA 在 .text 搜 4 字节立即数定位引用，遇 `0x68` 即 `push imm32` 字符串参数）。新文件已入库。
  * **已核实的架构事实**（详 docs/RE_GAME_EXE.md §2–§4）：Game.exe sha256 `e0716a35…e5b76`、PE32 i386 GUI、ImageBase 0x400000、6,365,184 B、时间戳 2018-06-22；引擎版本串 **`Editor - 20180525_ver2.22`** + `[Ver2.00`；DxLib **静态链接**（无 Dll 导入，.rdata 含 DxLib 源码路径）；只导入系统 DLL（KERNEL32/USER32/GDI32/SHLWAPI/SHELL32/WININET/WINMM），**无 d3d9/d3d11/dxgi/opengl/ddraw** → present 走 **GDI 软件 DIB 位块**（CreateDIBSection/StretchDIBits/SetDIBitsToDevice），无 swapchain。
  * **文本/字体**：GDI 文本 API（TextOutW/GetTextExtentPoint32W/GetTextMetricsA/GetGlyphOutlineW/CreateFontW/AddFontResourceExA）；`.text` @0x46a21d `push "*.ttf"` → `call [0x7b40d0]=KERNEL32!FindFirstFileA`，即**从数据目录枚举 ttf 加载**（work/Data 下实测 2 个 ttf）。
  * **已核对 §3 项**：九宫格 3px（`SystemFile/WindowBase.png` 实测 18x18、逐像素 3px 对称边框 → CORNER=3、无额外 padding）；过渡掩膜 `[Transition]Fade.png` 实测 640x480 mode L（8-bit 灰度）；present 后端=GDI DIB；字体来源=文件枚举；分辨率数据驱动（debug 串 `[Read]Screen size X`，assets --db-defaults 导出 1024x576）。
  * **仍未解**（需 Ghidra 反编译或逐帧实测）：盒退化、禁则、行距缩放、打字机精度、选择面板越界阈值、超宽选项、coordinate_scale 取整、default_origin trunc(rateY/10)、过渡曲线 easing 与 tint×fade 顺序、原版帧率/窗口初始尺寸。
  * **文档**：新建 `docs/RE_GAME_EXE.md`（工具/方法/二进制身份/导入表/已核对项/剩余项/复现步骤）；`docs/ENGINE_BEHAVIOR.md` §3 增 `3.1 C 任务进展与结论` 并让 §4 逆向段引用 `tools/re/wolfpe.py`+`RE_GAME_EXE.md`。`.recon/`（证据 JSON）已在 .gitignore。

* 2026-11-02（C 任务续：安装 Ghidra+JDK 并反编译原版 Game.exe）——用户「原来的会话超上下文了，现在你继续完成 c 任务，用 2，安装 ghidra+jdk 反编译；软件装 D 盘 program，不是软件就临时装项目内」：
  * **工具链**（D:\Program，符合“软件装 D 盘”约定，不入库）：Ghidra **12.2 PUBLIC**（`D:\Program\ghidra_12.2_PUBLIC`）+ Temurin **JDK 25.0.5+8**（Ghidra 12.2 要求 25+，21 会报 “JDK 25+ could not be found”；JDK 21.0.13 一并留下备用）。`tools/env.sh` 增 `GHIDRA_INSTALL_DIR`/`GHIDRA_JAVA_HOME`/`JAVA21_HOME`。
  * **坑（已绕开，写进 RE_GAME_EXE.md §8）**：(1) Git-Bash 直接跑 `support/analyzeHeadless` 探测 JDK 失败，必须 `analyzeHeadless.bat` + `cmd //c`；(2) cmd 的 `EnableDelayedExpansion` 会吃参数里的 `!`，`.bat` 的 `%` 展开会吃 `%d`，所以脚本参数一律走 UTF-8 args 文件；(3) 项目路径含 `!`（安装目录名）会丢字符，先把 Game.exe 复制到 `work/out/ghidra/input/Game.exe`（SHA 不变）再 import；(4) 同一时刻只允许一个进程持 Ghidra 项目锁。
  * **反编译**：Import+自动分析 **238 s**、识别 **10,589 函数**（x86:LE:32:default）；随后导出 **4,375 个 ≥64B 函数**的 C 伪码到 `work/out/re_all/all/`（含 index.tsv）。工具脚本入库：`tools/re/ghidra/{DumpByAnchor.java,DumpAll.java,run_ghidra.sh,README.md}`（1422 行，子代理完成，含 `--argsfile`/`--ref-window`；javac + 201 个 Ghidra jar 编译通过）。
  * **结论（12 项清单已闭环 9 项左右，详见 `docs/ENGINE_BEHAVIOR.md` §3.2 与 `docs/re/` 四份报告）**：
    * §3-8 坐标倍率 = **整除/idiv 向零截断**（CE48 pc30/31：Sys116/32、Sys117/24；标准分辨率另硬编码 10/20/25）；仓内 u32 整除等价，message.rs 的 f32 除法在非整倍数屏偏。
    * §3-9 **trunc(rateY/10) 确认是原版公式**（CE63 pc44-46：Sys2=17*rateY; Sys2+=rateY/10）。
    * §3-4 行距 = `本行最大字号×S + trunc(行距配置×min(基准字号,32)/32)×S`；本作 Game.dat 行距=6、基准=16 → **额外行距 3 px**（仓内 `font+6` 只在基准≥32 时对）。
    * §3-5 打字机 = double 水位 + `(DAT_0084b244×speed)/30` 每帧 → 60fps 下 **speed/2 字/秒**；**没有 preroll 减法**（仓内 cps/60 约为一半速度）。
    * §3-3 **原版无禁则**（4,375 函数零命中禁则字符常量，只有 `'\n'` + 行首空格丢弃）。
    * §3-1 无额外 padding（3px 皮肤、体区 α=223 必须混色）；§3-2 原版极小盒**不折半**（交给 blit 裁剪）；§3-6 原版**无越界回退/不夹取**（标题用 (-1000,-1000) 藏面板）；§3-7 布局侧无最大宽。
    * §3-12 原版**软件限帧 16.6 ms/帧（≈60fps，非 vsync）**，帧步进 `DAT_0084b244=60/fps`；窗口客户区 = 数据屏 1024×576 ×1.0，AdjustWindowRectEx + 居中，Game.ini 无尺寸项；无 DPI 感知 API。
    * §3-10 过渡 = **单程交叉溶解**（161 截旧帧 → 162 用掩膜/alpha 溶解到新帧），`t=elapsed/duration` **线性整数除法、无 easing、非三角波**；掩膜 = 单轴线性斜渐变（等值线 x≈-0.397y+c，残差<1.2px，方向≈21.5°，过渡带≈272px，灰阶峰值 250/251），不是图案；本作脚本唯一 transition 是 kind=-1（均匀 alpha 溶解）。
  * **建议但未改的代码动作**（等确认）：message.rs 的 LINE_GAP 改为 `trunc(line_spacing×min(base_font,32)/32)`（=3）与打字机速度/去 preroll；choice.rs 的 PADDING=14/MIN_WIDTH=120/越界居中无原版依据；window.rs 极小盒角折半与原版不同。
  * **测试现状**：`cargo test -q --workspace` 唯一失败是 `wolf-save` 的 `every_save_parses_with_the_measured_shape`——它默认读 `E:\SteamLibrary\...\Living With SIster Monochrome Fantasy\Save\SaveData01.sav`，该文件 2026-11-01 20:57 被改成 386,830 B（期望 366,146），属**外部存档数据变化**，与本轮（只改 docs/tools）无关；其余 crate 全 ok。
  * **空间清理**（里程碑收尾）：删除 `target/debug/incremental`、`target/release`、`work/out/saveprobe` 与 work/out 下 probe/pdb；删除 D:\Program\_dl 下载缓存（约 750 MB）。清理后 `du -sh .` = **4.4 GB**（target 3.8 G 可重编；work 534 M = Data 176 M + Ghidra 项目 166 M + 全量 dump 27 M，保留以便复核，重跑 import 约 4 分钟）。

* 2026-11-02（C 落地：按 RE 结论改 `crates/`，只实现本作触发路径）——用户 m00672「根据逆向结果开始改代码，只实现游戏本身需要的内容」：
  * **过渡（160/161/162）**：`crates/wolf-vm/src/exec.rs` 的 `Host::transition` 拆成 `transition_install`/`transition_prepare`/`transition_execute`（exec.rs:2115-2134），`TransitionState::frames()` 改取 `flags & 0xFFFF`（原版 `arg2 & 0xffff`，bit16 才是 wait）；`crates/wolf-game/src/transition.rs` 整体重写为「160 只 install、161 请求冻结、162 单程交叉溶解」：`alpha = remaining/duration` 线性（原版 `SetDrawBlendMode(ALPHA, 255*elapsed/duration)`），无 easing、**不再是三角波**，`kind=-1` 也不再是 hard cut（本作唯一 op160 `[-1, 0x1000A]` → 10 帧均匀溶解）；同一 transition 在跑时再 162 被忽略（对应 `DAT_00a14062 != 0`）。
  * **叠色（151）**：`crates/wolf-game/src/tint.rs` 重写为 DxLib `SetDrawBright` 语义——亮度 = `clamp(255+(p-100)*255/100, 0, 255)`，p≥100 钳到中性（不再是百分比乘子、p>100 不会变亮）；bit24 的 flash 改为**独立整屏纯色块 overlay**（alpha = 剩余帧/总帧，单向衰减），与亮度 ramp 互不影响。
  * **overlay 通道**：新增 `crates/wolf-game/src/overlay.rs`（`OverlayLayer::{Colour,FrozenFrame}` + `ScreenOverlay`，game 侧不依赖渲染 crate）；`game.rs` 新增 `screen_overlays()`/`take_freeze_request()`，`apply_screen_tint` 改为只乘 151（fade 交给 overlay）。`crates/wolf-render/src/overlay.rs` 新增四顶点整屏 quad 与 `renderer.freeze()`（`copy_texture_to_texture` 到惰性 1024×576 frozen 纹理）/`set_overlays()`；Pass1 在 `text.render` 之后按序画。CLI `main.rs:3448` 起 `render_overlays()` 做映射，capture 路径对 161 只打印「no previous frame」；`play.rs` 每帧顺序 = `freeze()`（上一帧 present 之后）→ draw → `set_overlays()` → present（每帧重设，否则列表残留）。
  * **行距**：`message.rs:134` `line_height = font + trunc(LINE_GAP(6) × min(BASE_FONT_PX,32)/32) = font+3`（新增 `BASE_FONT_PX=16`）；实机 101 窗口三行行距 23.0（20+3）三法互证，旧值 font+6 只在基准≥32 时成立。
  * **选择支面板**：`choice.rs` 常量按实机+RE 重建——`TEXT_INSET=8`（RE `2+(base<<2)/10`，实机 8.05/7.85）、`ROW_TOP=6`、`line_pitch(font)=font+trunc(14×min(16,32)/32)=font+7=27`（实测 27.18/26.88）、宽=`最宽 advance+16`（89EF 156.3=140+16 精确吻合）、高=`6+rows×pitch`（4 行 114、5 行 141）；删 `MIN_WIDTH/WIDTH_SLACK/MARKER_PX` 与 `"▶ "` 前缀；光标改用 `SystemFile/CursorBase.png`（12×12、corner=4）九宫格整行框 `[x+6,row_y,w−12,font_px]`（原版选中行就是高亮条）；`window.rs` 抽出 `nine_slice_cornered(dst,w,h,corner)`。宽度加数只到 B 级（EE37 比 89EF 宽 5.3 px 未解释，RE 的 +0x1a=26 会给出 166），已记为 open item。
  * **截图度量报告**：新建 `docs/re/SCREENSHOT_METRICS.md`——`prt sc/` 34 张全是窗口截图（scale 1.4961/1.5010，用全角 advance 反验）；消息行距 23.0、选择支行距 27、89EF 面板 156.3×114.2、EE37 161.8×140.7、高亮条 20（=字号+1）、左内缩 8；EE37 由 pitch/内缩/条高/高度式四条判据确认也是 102 面板。原始脚本与标注图在 `work/out/shot_metrics/`（未入库）。
  * **文档回填**：`docs/ENGINE_BEHAVIOR.md` §1.2/§1.3/§2.2/§2.3/§2.5 重写为落地后语义、§3 从「12 项待逆向」改为「C 后状态」并留 3 个真正开放项、§3.2 表 5 行、§4 动作表标注已落地；`docs/re/LAYOUT_METRICS.md` 增 §9 落地记录（含宽度分歧推理）、`docs/re/TEXT_METRICS.md` §7 汇总表更新、`docs/re/TRANSITION.md` §5 改「落地前/落地后」两节。
  * **测试**：`cargo test -q -p wolf-game --lib` = **300 passed**；`cargo test -q --workspace` = **exit 0 全绿**。为使 workspace 稳定通过，`wolf-save` 两个测试与**玩家本机存档漂移**解耦：`tests/save.rs` 改为 pinned 判定（长度+seeds+校验和同时吻合才算基线，否则打印 note 后只查结构），`tests/typed.rs` 删死数值表改为不变量断言（表行数、金额/游玩帧/列表/事件 CSelf 槽位等）。
  * **明确不做**（本作不触发或无证据）：`window.rs` 极小盒角折半（数据不产生 <6 px 盒）；打字机 2× 速度与「无 preroll」（`Sys9→p+0x80` 写入点未定位，且本作 CE48 把速度设 500 ≈ 瞬显，风险>收益）；`kind≥0` 掩膜过渡（全作唯一 op160 是 kind=-1）。
  * **清理**：删除 `target/debug/incremental`、`target/release`、`work/out/saveprobe` 与 work/out 下 probe/pdb；清理后 `du -sh .` = **4.6 GB**（target 4.0 G 可重编；work 543 M = Data 176 M + Ghidra 项目 166 M + 全量 dump 27 M + shot_metrics 等）。

* 2026-11-02（文档与仓库整理）：
  * **HANDOFF 拆分**：原 `docs/HANDOFF_M0.md` 的 §11 进度（700 行）拆出为 [HANDOFF_PROGRESS.md](HANDOFF_PROGRESS.md)；主文件保留 §0–§10 + §11「当前状态摘要 / 最近三轮 / 仍开放事项」（956 → 288 行），新会话读主文件即可掌握现状。
  * **文档索引重建**：`docs/README.md` 重写为唯一文档地图，新增「引擎行为与逆向」（ENGINE_BEHAVIOR / RE_GAME_EXE / re/*）、「调研与实证」「翻译目录」「参考实现」「工具与工作区产物」「被引用但缺失的文档」六节；里程碑与 M3 专题表状态统一为完成。
  * **调研归档**：6 份 `deep-research-report*.md` + `GPT_RESEARCH_GROUPS.md` 移入 `docs/research/gpt-reports/`（同步更新 HANDOFF §0/§7 与 research/README 的路径）。
  * **工程约定同步**：AGENTS.md 的「进度段」规则改为「HANDOFF_PROGRESS 追加 + HANDOFF §11.1 摘要」；README.md 文档入口加 HANDOFF_PROGRESS 与 ENGINE_BEHAVIOR。
  * **杂项**：`.gitignore` 增加 `/docs/攻略文档/`（用户本地攻略资料不入库）；`work/` 根下 15 份历史提交信息与 4 个一次性脚本移入 `work/out/_archive/`；修正 `crates/wolf-save/tests/typed.rs` 对不存在的 `docs/SAVE_FORMAT.md` 的引用。
  * **验证**：`cargo test -q --workspace` exit 0；文档相对链接检查全部可解析；`git status` 仅含本次文档/索引改动。


* 2026-11-02（真机 GPU 跑 play 路径）——用户 m02042「现在真机 GPU 跑一遍 play 路径」：
  * **环境**：play 走真实窗口 + GPU，适配器 NVIDIA GeForce RTX 5060 Laptop GPU (DiscreteGpu, backend Vulkan)，1024x576 逻辑分辨率、整数缩放；字体 C:\Windows\Fonts\msyhbd.ttc，fallback seguisym.ttf。
  * **四个入口全部 exit 0、0 warning**：
    * play --boot --until 600：600 帧 / 18,443 指令 / 14 picture op；诊断含 1x 160 InstallTransition: kind -1 flags 0x1000a (10 frame(s), no mask)。
    * play --load-save work/Data/Save/SaveData01.sav --until 900：900 帧 / 58,072 指令 / 12,965 picture op。
    * play --event 245 --until 600：600 帧 / 24,016 指令 / 32 picture op。
    * play --menu-only --until 600（标题菜单）：600 帧 / 40 指令 / 5 picture op。
  * **同渲染器的离屏 capture**（work/out/play_gpu/{boot,title,choice,load,load2}.png）：title.png 标题画面完整正确（logo + 3 个菜单项）。
  * **发现的既有缺口（不影响核心循环）**：存档/读档界面（事件 5）是「十分之一单位」UI block，crates/wolf-game/src/picture.rs:1046 Screen::ui_scale_for 能识别（返回 10）且 atlas.rs:532 / picture.rs:1409,1419 把 dst 除以 10，但行文字字号未同比例缩放，四个槽窗口画成不透明黑块、文字小而错位（pic 12052 "\f[0]1"、12075 "<R>\space[0]\f[0]\-[1]\E\A- ..."），只有顶栏 pic 12001 WindowBase_amania.png + 标题「选择要保存的数据。」正确。用 capture --map SampleMapA --event 5 现场构建同样复现，说明与 --load-save 入口无关。另外玩家存档 SaveData01.sav 是在存档界面按保存写下的，Part5 含整套存档界面图（12000..12113），裸读档会把这些图一并还原。
  * **试过又回退**：在 game.rs resume_loaded_map 里 screen.clear()（HUD 全丢）或新增 Screen::clear_transient_ui() 按 ui_scale>1 删窗口图（误删顶栏 12001，顶部像素由 (52,56,57) 变 (196,196,196)）；两者都 revert，git status 干净、cargo build -q --workspace exit 0。教训：12001 既是存档界面顶栏又是读档后的 HUD 顶栏，不能按 ui_scale 粗删。

* 2026-11-02（修存档/读档界面十分之一单位几何）——用户 m02239「我继续修bug」：
  * **根因**：tenths UI block 的 `Screen::ui_scale_for` 分组键用了 `number/100`（应 `/1000`），且渲染时把 **x 也除了 10**——但 VM 的 op121（flags=0x10400）早已把 x 侧除回像素，只有 y/w/h 仍是十分之一。结果面板落到 x=4.8、整片黑；同时 `CursorBase.png` 被当实心九宫格铺满槽 → 黑块；空槽标签里的 DB 句柄（1_100_000_000+row*100+col）被直接打印成九位数字。
  * **修复**（工作树，`cargo test -q --workspace` exit 0，96 套件全绿、0 warning）：
    * `crates/wolf-game/src/picture.rs` `ui_scale_for`：分组 `div_euclid(100)`→`div_euclid(1000)`；`quads()` text/sprite 分支 ui>1 时 dst 的 **x 不除**、y/w/h 除 10。
    * `crates/wolf-game/src/atlas.rs:532`：window panel dst 同样 x 不除、y/w/h 除 10；`CursorBase.png` 走 `nine_slice_frame`。
    * `crates/wolf-game/src/window.rs`：新增 `nine_slice_frame`（空心九宫格，去中心填充），槽框不再是黑块。
    * `crates/wolf-vm/src/text.rs` `parse_escape`（SelfVar 分支）：空串且 `MagicKind::DbCell` → 返回空串，杜绝九位地址泄漏。
  * **验证**：`capture --map SampleMapA --event 5` 四槽几何/白边/深灰体与实机参考图一致（`work/out/play_gpu/saveui_fix4.png`）；标题/读档 HUD/ev245 三张回归正常。
  * **测试与存档漂移解耦**：`work/Data/Save/SaveData01.sav` 已被玩家在存档界面覆盖为含 94 张存档界面图的版本（playtime 617）。
    * `crates/wolf-game/tests/m3_hud_layout.rs` `hud_stable_snapshot_layers_and_hidden_state`：检测到槽 12000 存在（非干净 HUD 存档）则按跳过处理。
    * `crates/wolf-game/tests/m3_save_load.rs` 的 `save_data_01_and_02_differ_in_hud_time_and_money` 与 `opcode_220_load_request_restores_a_save`：改为自洽/对照 baseline 断言，不再硬编码 50/10000/19:30。
    * `crates/wolf-game/tests/m3_save_ui_roundtrip.rs`：比较还原卧室几何时过滤 12000..12199 存档界面 overlay 层。
  * **文档**：`docs/re/SCREENSHOT_METRICS.md` 新增 §6（十分之一 UI 块几何）；`docs/ENGINE_BEHAVIOR.md` §1 表与 §2.4 更新为 chapter/1000 + x 不除语义。


* 2026-11-03（CE245/CE248 空可选行动行修复）——用户 m05098 / m02832 / m02834：
  * **根因**：opcode 102 的选项里存在裸 `\cself[n]` 可选行动标签；当前分支未写入字符串槽时，`crates/wolf-vm/src/text.rs` 的数值回退把空标签展开成 "0"，CE245 夜菜单多出第 6 行、CE248 游戏菜单多出 3 行 "0"。参考 `prt sc/{EE3763D0-E855-4693-99A1-FEE747EE4947}.png` 与 `docs/re/SCREENSHOT_METRICS.md:48-58` 实测 EE37 为 5 行。
  * **修复**：`crates/wolf-vm/src/text.rs` 新增 `pub fn expand_choice` + `fn single_escape`：完全形如 `\name[n]` 的 SelfVar 标签只查字符串槽（空即空），其它 escape 仍走 `expand`；`crates/wolf-vm/src/exec.rs` 的 op102 与 `BlockKind::Choices` 改用 `expand_choice`。`crates/wolf-game/src/game.rs` 的 `Choices` 新增 `sources: Vec<usize>`，`show_choices` 过滤空标签并记录原始 index，新增 `choice_source_index`；鼠标点击、OK、auto_choice 回复全部映射回原始 case id（op102 case id = index+2，空项可位于中间）。
  * **测试**：更新 `m2_daily_loop`/`m3_night_actions`/`m3_mouse_menu`/`m3_manual_rules`/`m3_week_loop`/`m3_newgame_persistence` 期望为 5 行，CE248 期望 4 行；新增 text.rs `choice_labels_hide_an_unwritten_self_string`；`m14_visual_regression` day_command 基线改为 choice_options=5、textpics19/items19/glyphs82/lines19/nonblack 532756。
  * **验证**：`cargo test -q --workspace` **exit 0**；`cargo test -q -p wolf-cli --test m14_visual_regression` **5 passed**；`WOLF_DATA_ROOT=$PWD/work/Data ./target/debug/wolf-cli.exe verify` **PASS 64 / 1 SKIP**；`capture --load-save ... --event 245 --frames 240` 产物 `work/out/m14_visual/day_command_probe.png` 只剩五行，与参考 EE3763D0 对齐。

* 2026-11-03（HUD/全屏文本字重与垂直基线）——用户 m05098 / m02832 / m02834：
  * **根因**：`Game.dat` 主字体为 `Microsoft YaHei UI Bold`（msyhbd.ttc 只有 weight 700 face），但 `Attrs::new()` 默认请求 weight 400；fontdb 匹配不到主 face 就退到 `C:\Windows\Fonts\seguisym.ttf`，该 fallback 的 digit advance=0.5391em，使 `19:30` 在 24px 只有 56.95px（参考 66.06/墨迹63），所有 ASCII 数字窄约 16%。
  * **修复**：`crates/wolf-render/src/text.rs` 的 `TextQuad/TextItem` 新增 `weight: u16`，所有 `Attrs::new()` 链改用该 weight；`crates/wolf-game/src/game.rs::build_text_picture` 对 tenths UI 块（`ui>1`，存档槽 data/time/name 行）置 400，普通像素文本（HUD/message/top bar）置 700；`crates/wolf-game/src/atlas.rs` 与 `choice.rs` 的 TextQuad 构造补 weight。
  * **垂直**：`crates/wolf-game/src/textpic.rs` 新增 `PLAIN_TEXT_TOP_OFFSET=4.0`，`build_text_picture` 仅对 `ui<=1` 的普通文本把 quad 下移 4px；tenths UI 标签不加。实测 `19:30` 墨迹 x36..98/y11..28（参考 x37..99/y11..28），`周一` y13..29（参考13..28），`持有金钱` 宽159（参考158）；存档 data 仍 x71..121/宽51、time 宽34~35，不回归。
  * **验证**：`cargo fmt --all && cargo build -q --workspace` exit 0；`cargo test -q --workspace` exit 0；`cargo test -q -p wolf-cli --test m14_visual_regression` 5 passed（day_command nonblack 532756→533165、hud 554374→554868 已按字号重录）；`WOLF_DATA_ROOT=$PWD/work/Data ./target/debug/wolf-cli.exe verify` PASS 64/1 SKIP。截图 `work/out/play_gpu/{hud_final.png,hud_final_sbs.png,saveui_final.png,saveui_final_sbs.png,newgame_final.png}`。
* 2026-11-03（HUD ASCII 空格按 0.5 em 度量）——用户 m05098 / m02832 / m02834：
  * **根因**：右上 `同居 1天` 整块比实机参考右移约 9~10px。逐列对比（`work/out/play_gpu/fontcmp_topright.png`）显示参考 line2 宽≈57 = 07/MS Gothic 的 `leading16+'1'20+天14+trailing7`，而 msyhbd 只有 `10+19.27+14+4≈47.3`；但 `19:30` 只有 msyhbd（59）接近参考（58），07 明显更宽（63），所以不能全局换字体。GDI `GetTextExtentPoint32W` 对 `Microsoft YaHei UI Bold` 的 cs0/1/128/134 都是 YaHei，cs255 回退 Modern，也解释不了参考宽度。
  * **修复**：`crates/wolf-game/src/game.rs::build_text_picture` 的 advance 闭包对 `ui <= 1.0 && ch == ' '` 返回 `px * 0.5`，其余字符仍用 `self.font_metrics.advance`（无 metrics 时 `choice::advance_at`）；`textpic::layout_with` 照此度量。渲染时把含空格的 HUD run 按 ASCII 空格拆成独立 span（空格只推进 cursor、不生成 quad），每个 span 单独定位，避免真实字体窄空格把后续字形拉左；同时恢复每个 span 的 `picture::on_screen` 过滤。
  * **结果**：picture 252 的 block left 由 952.56→943.2656，line2 宽 56.73（参考≈57）；`同居/1/天` 与参考墨迹几乎重合，`19:30` 仍与参考同宽。实测 hud text 13 items/44 glyphs/13 lines、nonblack 554890；day_command text 22/76/22、nonblack 533187。
  * **测试**：`m14_visual_regression` 的 hud 基线 textpics14/items13/glyphs44/lines13/nonblack554890，day_command textpics23/items22/glyphs76/lines22/nonblack533187；因空格不再作为 quad，`m3_hud_numeric`、`m3_status_panel`、`m4_hud_status`、`m4_load_resume` 的 `精力 3/3` 断言改为去空白后包含 `精力3/3`。
  * **验证**：`cargo fmt --all && cargo build -q --workspace` exit 0；`cargo test -q --workspace` **exit 0**；`cargo test -q -p wolf-cli --test m14_visual_regression` **5 passed**；`WOLF_DATA_ROOT=$PWD/work/Data ./target/debug/wolf-cli.exe verify` **PASS 64 / 1 SKIP**。截图 `work/out/play_gpu/{topright_space_sbs.png,hud_spacehalf_top.png,hud_spacehalf_sbs.png}`。

* 2026-11-03（正常可双击游玩发布包）——用户 m07879：
  * **用户要求**（m07879）：“我要你生成一个正常的游戏发布包，能通过exe文件直接启动游戏游玩来验证，而不是用命令行”。
  * **实现**：新增 std-only GUI 启动器 `crates/wolf-launcher`（`#![cfg_attr(target_os="windows", windows_subsystem="windows")]`，bin 名 `imouto-life`，无外部依赖）：定位同目录 `Data\BasicData` 与 `runtime\wolf-cli.exe`，`Command` 启动 `play --root <Data> --audio`，`CREATE_NO_WINDOW (0x08000000)` 隐藏控制台，stdout/stderr 写入 `game-log.txt`，失败 MessageBox + `launcher-error.log`，额外参数原样转发。
  * **打包**：新增 `tools/package-playable.sh` 与 `tools/package/PLAYABLE_README.txt`；`cargo build --release -p wolf-cli -p imouto-launcher`（1m38s）→ 输出 `D:\program\Imouto Life\`：`Imouto Life.exe` 236,544 B、`runtime\wolf-cli.exe` 12,469,248 B、`Data\` 全量 176 MB（含 Save）、`README.txt`、`checksums.txt`；目录 188 MB。zip 用 Windows bsdtar 生成：`work/out/dist/Imouto Life-0.1.0-playable.zip` 153 MB，1,387 条目，解压后 UTF-8 文件名正确、`sha256sum -c` 全 OK。
  * **验证**：用假引擎探针确认启动器参数为 `play --root <pkg>\Data --audio` 且 cwd 正确；包内 release 引擎 `verify --root` PASS 64/1 SKIP；`--audio capture --menu-only --frames 5` 渲染 1024x576、499,899/589,824 非黑、exit0。未替用户启动 GUI 窗口（避免抢前台）。
  * **文档**：`docs/PACKAGING.md` 新增 §7；发布包中文说明见 `tools/package/PLAYABLE_README.txt`。
