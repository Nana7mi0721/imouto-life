# 《妹！生活 ～単色～》Rust + Godot 跨平台重写工程全量深度代码审查与修复方案总报告（第一至四轮完整版）

## 一、 执行摘要（Executive Summary）

本报告汇总了对《妹！生活 ～単色～》（Imouto! Life ~Monochrome~）Rust + Godot 4.7.2 跨平台重写工程开展的**第一轮核心架构深度审查（`BUG-25` 至 `BUG-35`）**、**第二轮全量字节码指令深挖（`BUG-36` 至 `BUG-40`）**、**第三轮基于真实二进制资产（`work/Data/` 全套 `.dat/.project/.mps/.sav`）与 `wolf-gdext` / `GameView.gd` 跨语言管线的实证深挖（`BUG-41` 至 `BUG-46`）**以及**第四轮结合 `imouto_life_sandbox_full.zip` 与 `imouto_life_sandbox.zip` 全量切片包开展的图层几何/复合算子/渐变擦除专项深挖（`BUG-47` 至 `BUG-48`）**的全部技术结论、精确行号取证、函数级修复补丁代码与架构演进指南。

> **关于完整素材包沙箱还原与实测验证的说明**：已通过 Google Drive `imouto life/review_bundle_upload` 文件夹完整拉取 17 个分卷切片（`full.part01.bin`..`full.part17.bin`），以及 2 个逻辑包分卷切片（`logic.part01.bin`..`logic.part02.bin`），经合并与 SHA-256 严格校验（完整包 `2948a4196b5d1d9951fc31b7f74151bfc1cf4dcce6c2746e2755d52779e733a3`、逻辑包 `a3db3a1ee10f3f2876dd29e3705a2e541e404529feff9ba884f846eb8fba406d`）后在沙箱完整解压全部 1,364 个真实媒体与二进制数据资产（`Picture/`、`BGM/`、`SE/`、`cg/`、`BattleEffect/`、`BalloonBase_CafeLatte/`、`SystemFile/`、`SystemGraphic/`、`MapChip/`、`CharaChip/` 及全套 `.dat/.project/.mps/.sav`），并运行 `python3 -I tools/audit_bytecode.py` 与全量资产引用扫描完成第三轮交叉实证。

### 1.1 历史缺陷基线核验结论（BUG-01 至 BUG-24）
1. **已闭环并由回归测试锁定的历史缺陷（`BUG-01` 至 `BUG-19`）**：
   * `BUG-02`（对话框人名框）：气泡采用固定底边模式 2002，由 Opcode 290 平移至 `(512, 536)`，Picture 36014 稳定位于 `(276, 456)` 屏内；根因系 Opcode 112 字符串比较未剥离 bit 24 变量类型标志，已在 `crates/wolf-vm/src/exec.rs:3204` 修复并通过 `tests/m15_balloon_name.rs` 连续 60 帧可见验证。
   * `BUG-04`（日常卧室顶栏体力条）：经原版说明书与 `CE 242` 验证，日常卧室顶栏仅含文本和数字槽位（Picture `220..252`），无体力条素材，体力条仅在夜间互动时出现，判定为 `NOT-A-BUG`。
   * `Opcode 210/211` 相对寻址：寻址范围 `600_000..=699_999` 严格遵循 $\text{target\_id} = \text{caller\_event\_id} + (\text{raw} - 600100)$，已在 `crates/wolf-vm/src/exec.rs:1570, 2743` 落地。
2. **历史台账中已定位但待验证/加固的基线项（`BUG-20` 至 `BUG-24`）**：已整理于本报告第六章，方便团队统一核对。

### 1.2 第一至四轮新发现深水区缺陷全景统计（BUG-25 至 BUG-48，共 24 项）
* **S1 致命级（流程阻断 / 控制流错乱 / 核心内存污染 / 地图与音频跨语言断层 / 图层几何与复合赋值错乱，共 12 项）**：
  * `BUG-25`：`AutoEvents::sync`（`auto_events.rs:224-238`）将 `run_condition == 2`（并行触发）实现为边沿触发（`now && !before`），导致 21 个无内部死循环的并行 UI/HUD 事件及夜间切入计时器（`CE 281/282`）运行 1 次后永久死亡。
  * `BUG-26`：`ENGINE_RESTART`（`game.rs:1192-1215`）仅包含 `&[270]`，遗漏其余无死循环的 `run_condition == 3`（常时并行）公共事件（`CE 271` 快进、`CE 214` 莉子支援、`CE 216` 阈值监控、`CE 261`）。
  * `BUG-27`：`Opcode 121`（`exec.rs:1586, 1720-1736, 2199-2252`）忽略 `arg3 & 0xFF` 二阶指针寻址标志位（`0x04/0x08/0x10/0x20/0x40`），且 `eval_num` 对 `CommonSelf` 直接返回魔数地址 `15_xxx_xxx`，污染 `CE 270` 与 `CE 266` 关键状态。
  * `BUG-28`：`Opcode 124 Field 18`（`exec.rs:2457-2462`）返回调用者自身 ID（`CE 223` 恒得 `500223`）而非前台活跃事件 ID，导致 `CE 223` 全部 9 个窗口分支恒不命中。
  * `BUG-29`：`Instance.self_vars` 与 `Variables.common_self`（`exec.rs:1037-1110, 1700-1718`）仅在协程启停时做单向拷贝，运行期跨事件读写 `15_000_000+` 产生脏读与退出时反向覆盖。
  * `BUG-30`：同一物理帧内 `mouse_consumed` 全局吞噬竞争（`game.rs:2371, 3074, 3121`），以及 `Opcode 125`（`auto_keys`，`exec.rs:2504`）单帧生命周期导致的协程顺序敏感丢键。
  * `BUG-36`：`Opcode 176`（`ContinueLoop` / `ループ開始へ戻る`）在 `program.rs:47, 280` 与 `exec.rs:2676` 中被误判为 `StartLoop2`（新循环头），不仅导致全库 54 处 `continue` 穿透执行并破坏 `CE 63/212/268/270` 循环栈，还直接导致 `tools/audit_bytecode.py` 误报出“32 处无等待死循环”。
  * `BUG-37`：`Opcode 140`（`Sound`，`exec.rs:2578-2631`）未对延迟/淡入 `arg1`、音量 `arg4`、音调 `arg5` 调用 `eval_num`（将魔数 `1_600_002` 当作 7.4 小时延迟），且将 `sound_type == 1`（变量指定 DB 音频，`CE 188`）误判为 `Stop`。
  * `BUG-41`（第三轮新发现）：**`wolf-gdext`（`crates/wolf-gdext/src/lib.rs:265-269`）在 `WolfGame::frame()` 中完全漏调 `game.tile_quads(atlas)`**，导致 Godot 4.7.2 前端中所有地图的 3 层瓦片背景（`TileSetData.dat` + `.mps`）100% 缺失呈现为纯黑！
  * `BUG-42`（第三轮新发现）：**`savegame::apply`（`crates/wolf-game/src/savegame.rs:174-184`）在恢复存档 BGM 时仅调用 `game.audio`（在 Godot 下恒为 `None`），从未向 `game.sounds` 推送 `SoundCmd`**（同时 `GameView.gd::_load_audio` 缺失 Mod 覆盖层与大小写不敏感路径回退），导致 Godot 前端读档后永远残留标题曲或上一场景 BGM！
  * `BUG-43`（第三轮新发现）：**`GameHost::database`（`crates/wolf-game/src/game.rs:3392-3394, 3447-3449`）判断 `wants_text` 仅检查 `STR_BASE`（`3_000_000..`）**，漏掉 `CSelf5..9`（`1_600_005..9`）与 `15_000_000+`，导致读取空槽位或扩展行到 `CSelf5..9` 时返回 `DbValue::Num(0)` 并调用 `store_num`，使 `CSelf5..9` 字符串槽位残留上一轮循环的脏文本！
  * `BUG-47`（第四轮新发现）：**`GameHost::picture_state`（`crates/wolf-game/src/game.rs:3762-3763`）将 `Field 2/3`（图片实际像素宽高 `サイズX/Y`）误返回为缩放比 `scale / scale_y`（`100`），且 `Opcode 124`（`crates/wolf-vm/src/exec.rs:2482`）忽略了 `sub & 0x0F00` 复合赋值算子（如 `0x4400` `/=` 除等、`0x1200` `-=` 减等）**，导致 `CE 270` 对白气泡/立绘/人名框宽高测算全部失真为 `100`、`CE 223` 滑块热区错位、`CE 63/90/94/178` 头像缩放比例计算错误！
* **S2 严重级（核心功能缺失 / 数据库与存档读写错位 / 虚拟硬件断层 / 渲染混合与淡出失真，共 11 项）**：
  * `BUG-31`（`Opcode 250` 写入侧仅检查 `MagicKind::StrVar`，将全库 46 处 `CSelf5..9` 字符串写 DB 误存为 `DbValue::Num(0)`）、`BUG-32`（`Opcode 174` 返回标题与 `Opcode 211` 预约事件为空实现）、`BUG-33`（`MapRuntime` 换页条件死锁 `Map 5 Ev 17` 昼夜切换）、`BUG-34`（`Sys100/Sys102` 音量设置未同步至 Godot 音频总线且未持久化回 `System.sav`）、`BUG-38`（`Opcode 220..222` 将 `CSelf5 = "Save/System.sav"` 误判为 `Slot(0)`）、`BUG-39`（`Opcode 130` 场所移动与 `Opcode 151` 画面色调未对参数调用 `eval_num`）、`BUG-40`（Godot 前端每帧对所有 Sprite/Text 重新构造 `VarDictionary` 并做 O(N log N) GDScript 排序）。
  * `BUG-44`（第三轮新发现）：**`GameHost::engine_state`（`crates/wolf-game/src/game.rs:3781-3804`）硬编码 `Field 10`（滚轮增量）为 `Some(0)`，且 `apply_wheel()` 在 VM 执行前提前清空 `self.wheel`**，导致 `CE 223` 的 9 处原生滚轮读取恒为 `0`；同时 `Field 0`（当前地图 ID）、`Field 1`（当前 BGM ID）硬编码常数，`Field 11/12`（窗口鼠标边界，`CE 224`）返回 `None`。
  * `BUG-45`（第三轮新发现）：**`Atlas::sprites`（`crates/wolf-game/src/atlas.rs:94-110, 505-516`）在构造 `SpriteQuad` 时直接丢弃了 `Picture.blend`（加算 `2` / 减算 `3` / 乘算 `4`）**，`wolf-gdext` 与 `GameView.gd:_draw` 全链路缺失混合模式支持，导致黑底光晕与文字特效直接以黑块遮挡立绘。
  * `BUG-46`（第三轮新发现）：**`GameHost::character_state`（`crates/wolf-game/src/game.rs:3774-3779`）对全部 78 处查询恒返回 `None`**，且 `Opcode 160`（`InstallTransition`）与 `Opcode 1000`（`ProFeature`）在 `exec.rs:2650, 2960` 中未对参数调用 `eval_num`。
  * `BUG-48`（第四轮新发现）：**`Screen::apply`（`crates/wolf-game/src/picture.rs:1245-1262`）在执行 `PictureAction::Erase` 时完全忽略 `cmd.args[0]` 淡出帧数（全库共 241 处带帧数渐隐擦除），在同一微秒内直接 `remove` 图层**，导致 `CE 234` 紧跟在 `Draw(fade=50)` 下一条指令的 `Erase(fade=50)` 瞬间吞噬刚创建的 `Picture 3010`（0 帧可见），且 `CE 219/220/281/282/301/303` 特效与相册交叉淡出全部退化为硬切消失！
* **S3 一般级（细节语义偏差，共 1 项）**：
  * `BUG-35`：`textpic.rs:658` 将 `VarBank::SysDb`（`\sdb`）误路由至 `cdb`；`PictureVars`（`game.rs:2893-2911`）将 `\cself` 误作普通变量；`Opcode 180`（`exec.rs:2707`）强制 `Wait(0)` 为 `.max(1)`。

## 二、 全量新发现缺陷总表（Master Defect Ledger: BUG-25 to BUG-48）

| 编号 | 轮次 | 严重度 | 关键文件与精确行号 | 问题简述与实机影响 |
| :--- | :--- | :--- | :--- | :--- |
| **BUG-25** | 第一轮 | **S1 致命** | `crates/wolf-game/src/auto_events.rs:224-238` | `AutoEvents::sync` 将 `run_condition == 2`（并行事件）误实现为边沿触发（`now && !before`），导致 21 个无死循环的并行 UI/HUD 事件与 `CE 281/282` 切入计时器运行 1 次即永久停摆 |
| **BUG-26** | 第一轮 | **S1 致命** | `crates/wolf-game/src/game.rs:82, 1192-1215` | `ENGINE_RESTART` 仅含 `&[270]`，遗漏无内建死循环的 `run_condition == 3` 常时并行事件（`CE 214, 216, 261, 271`） |
| **BUG-27** | 第一轮 | **S1 致命** | `crates/wolf-vm/src/exec.rs:1586, 1720-1736, 2199-2252` | `Opcode 121` 忽略 `arg3 & 0xFF` 二阶指针寻址标志位（`0x04..0x40`），且 `eval_num` 对 `CommonSelf` 直接返回魔数地址 `15_xxx_xxx`，污染 `CE 270` 与 `CE 266` |
| **BUG-28** | 第一轮 | **S1 致命** | `crates/wolf-vm/src/exec.rs:2457-2462`<br>`crates/wolf-game/src/game.rs:3781-3804` | `Opcode 124 Field 18`（`処理中イベント番号`）返回调用者自身 ID（`500223`）而非前台窗口事件 ID，导致 `CE 223` 全部 9 个菜单窗口分支永不命中 |
| **BUG-29** | 第一轮 | **S1 致命** | `crates/wolf-vm/src/exec.rs:1037-1110, 1700-1718` | `Instance.self_vars` 与 `Variables.common_self` 仅在协程启停时单向同步，跨协程写 `15_027_0xx` 被退出时的旧快照覆盖，且 `CE 223` 读不到 `CE 131/132` 实时游标 |
| **BUG-30** | 第一轮 | **S1 致命** | `crates/wolf-game/src/game.rs:2371, 3074, 3121`<br>`crates/wolf-vm/src/exec.rs:2504` | 同一物理帧内 `mouse_consumed` 吞噬竞争；`Opcode 125`（`auto_keys`）单帧清零导致后序协程注入按键丢失 |
| **BUG-31** | 第一轮 | **S2 严重** | `crates/wolf-vm/src/exec.rs:2885-2893` | `Opcode 250` 写入侧仅检查 `MagicKind::StrVar`，将全库 46 处 `CSelf5..9`（`1_600_005..9`）字符串写 DB 误存为 `DbValue::Num(0)` |
| **BUG-32** | 第一轮 | **S2 严重** | `crates/wolf-game/src/game.rs:3664-3683`<br>`crates/wolf-vm/src/exec.rs:2666, 2765` | `Opcode 174`（返回标题画面，9 处调用）与 `Opcode 211`（预约公共事件，4 处调用）在 `GameHost` 中仅打印日志而未执行实际动作 |
| **BUG-33** | 第一轮 | **S2 严重** | `crates/wolf-game/src/map_runtime.rs:455-467` | `MapRuntime` 在 `pc > 0 \|\| wait != None` 时一律阻断换页，导致并行事件（如 `Map 5 Ev 17`）在变量变化后死锁在旧页面 |
| **BUG-34** | 第一轮 | **S2 严重** | `crates/wolf-game/src/game.rs:894-900, 2635-2640`<br>`godot/scripts/GameView.gd:403-485` | `Sys100`（BGM 主音量）与 `Sys102`（SE 主音量）在 Godot 前端完全未生效，且退出 `CE 132` 设置界面时未自动持久化至 `Save/System.sav` |
| **BUG-35** | 第一轮 | **S3 一般** | `crates/wolf-game/src/textpic.rs:658`<br>`crates/wolf-game/src/game.rs:2893-2911`<br>`crates/wolf-vm/src/exec.rs:2707` | `textpic.rs` 将 `\sdb` 误路由至 `cdb`；`PictureVars` 无法解析 `\cself`；`Opcode 180` 强制 `Wait(0)` 为 `.max(1)` |
| **BUG-36** | 第二轮 | **S1 致命** | `crates/wolf-vm/src/program.rs:47, 280, 444`<br>`crates/wolf-vm/src/exec.rs:2676-2682` | `Opcode 176`（`ContinueLoop` / `ループ開始へ戻る`）被误判为 `StartLoop2`（新循环头），导致全库 54 处 `continue` 穿透执行并破坏 `CE 63/212/268/270` 循环栈（同时造成审计工具误报 32 处死循环） |
| **BUG-37** | 第二轮 | **S1 致命** | `crates/wolf-vm/src/exec.rs:2578-2631` | `Opcode 140`（`Sound`）未对延迟 `arg1`、音量 `arg4`、音调 `arg5` 调用 `eval_num`（将 `1_600_002` 当作 160 万帧延迟），且将 `sound_type == 1`（变量指定 DB 音频，`CE 188`）误判为 `Stop` |
| **BUG-38** | 第二轮 | **S2 严重** | `crates/wolf-vm/src/exec.rs:2786-2791` | `Opcode 220..=222` 仅识别 `MagicKind::StrVar`，导致 `CE 48/131` 传入 `1600005`（`CSelf5 = "Save/System.sav"`）被误判为 `SaveTarget::Slot(0)` |
| **BUG-39** | 第二轮 | **S2 严重** | `crates/wolf-vm/src/exec.rs:2526-2540, 2641-2645` | `Opcode 130`（`Teleport`）与 `Opcode 151`（`ChangeColor`）未对坐标/地图/颜色参数调用 `eval_num`，导致 `Map 1 Ev 3/5` 传送至 `(2000007, 1100005)` |
| **BUG-40** | 第二轮 | **S2 严重** | `crates/wolf-gdext/src/lib.rs:265-345`<br>`godot/scripts/GameView.gd:364-391` | `wolf-gdext` 每帧无条件重分配所有 Sprite/Text 的 `VarDictionary`，且 `GameView.gd:_draw` 每帧构造临时字典数组并执行 GDScript 闭包排序 |
| **BUG-41** | 第三轮 | **S1 致命** | `crates/wolf-gdext/src/lib.rs:265-269` | **`WolfGame::frame` 完全漏调 `game.tile_quads(atlas)`**，导致 Godot 4.7.2 前端中所有地图的 3 层瓦片图层 100% 缺失（仅绘制了 Picture 层） |
| **BUG-42** | 第三轮 | **S1 致命** | `crates/wolf-game/src/savegame.rs:174-184` | **`savegame::apply` 恢复 BGM 时仅操作 `game.audio`（Godot 下为 `None`）而不向 `game.sounds` 推送 `SoundCmd`**，导致 Godot 读档后 BGM 永不切换或不停播 |
| **BUG-43** | 第三轮 | **S1 致命** | `crates/wolf-game/src/game.rs:3392-3394, 3447-3449`<br>`crates/wolf-vm/src/exec.rs:2912-2918` | **`GameHost::database` 的 `wants_text` 仅检查 `STR_BASE`（`3_000_000..`）**，当读取空/扩展 DB 单元格到 `CSelf5..9`（`1_600_005..9`）时返回 `DbValue::Num(0)` 并写入数值槽，导致 `CSelf5..9` 字符串槽残留脏文本 |
| **BUG-44** | 第三轮 | **S2 严重** | `crates/wolf-game/src/game.rs:2245, 3781-3804` | **`GameHost::engine_state` 硬编码 `Field 10`（滚轮）为 `Some(0)` 且 `apply_wheel` 提前清空 `self.wheel`**，导致 `CE 223` 9 处滚轮查询恒为 `0`；`Field 0/1` 硬编码常数，`Field 11/12`（`CE 224`）返回 `None` |
| **BUG-45** | 第三轮 | **S2 严重** | `crates/wolf-game/src/atlas.rs:94-110, 505-516`<br>`godot/scripts/GameView.gd:380-386` | **`Atlas::sprites` 构造 `SpriteQuad` 时丢弃 `Picture.blend`**，Godot `GameView.gd:_draw` 对所有图层一律按普通 Alpha 绘制，导致加算/减算/乘算高光特效渲染为黑底色块 |
| **BUG-46** | 第三轮 | **S2 严重** | `crates/wolf-game/src/game.rs:3774-3779`<br>`crates/wolf-vm/src/exec.rs:2650, 2960` | `GameHost::character_state` 对全库 78 处查询（`Sub-Op 0x1000/0x1200 Field 2/3/6/7/10`）恒返回 `None`；`Opcode 160` 与 `Opcode 1000` 未对参数调用 `eval_num` |
| **BUG-47** | 第四轮 | **S1 致命** | `crates/wolf-game/src/game.rs:3749-3772`<br>`crates/wolf-vm/src/exec.rs:2466-2484`<br>`crates/wolf-game/src/picture.rs:1505-1507` | **`GameHost::picture_state` 将 `Field 2/3`（像素宽高）误返回为 `scale/scale_y`，且 `Opcode 124` 忽略 `sub & 0x0F00` 复合算子（`0x4400` `/=` 与 `0x1200` `-=`）**，导致 `CE 270` 文本/立绘/气泡尺寸测算、`CE 223` 滑块碰撞与 `CE 63/90/94/178` 头像缩放全部失真 |
| **BUG-48** | 第四轮 | **S2 严重** | `crates/wolf-game/src/picture.rs:1245-1262` | **`PictureAction::Erase` 忽略 `cmd.args[0]` 淡出帧数（全库 241 处）直接 `remove` 图层**，导致 `CE 234` 紧跟 `Draw` 之后的 `Erase(fade=50)` 令 `Picture 3010` 零帧消失，且 `CE 281/282/301` 淡出退化为硬切 |

## 三、 第一轮审查缺陷深度剖析与修复方案（BUG-25 至 BUG-35）

### 3.1 BUG-25（S1 致命）：`AutoEvents::sync` 将并行公共事件（`run_condition == 2`）误实现为边沿触发

#### 现场表现与实锤定位
* **源码定位**：`crates/wolf-game/src/auto_events.rs:224-238`：
  ```rust
  let before = self.latched.get(&event.id).copied().unwrap_or(false);
  if now && !before {
      if let Some(instance) = vm.start_event(event.id) {
          self.running.insert(event.id, instance);
          report.started += 1;
      }
  }
  ```
* **机理剖析**：WOLF 中 `run_condition == 2`（並列実行）是**电平触发（Level-Triggered）**：只要条件成立且当前该事件实例已执行完毕退出，下一帧必须自动重新拉起。全库有 21 个 `run_condition == 2` 的事件内部无 `170` 死循环（如 `CE 228..243` HUD 组件，以及通过 `Opcode 172` 提前退出的夜间切入计时器 `CE 281/282`），在当前边沿触发逻辑下运行 1 次后即永久停摆。
* **注意**：唯独 `CE 43`（`┗オリジナルタイトル画面Ｂ`，标题按钮绘制器）与 `GATED_CALL_ONLY`（`CE 242/243`）需要防止同帧无限重入或按特定时机重启。

#### 严格修复建议
修改 `crates/wolf-game/src/auto_events.rs:215-248`：先清理 `self.running` 中已经在 `vm` 里终止的实例（对于 `event.id != 43 && !GATED_CALL_ONLY.contains(&event.id)` 的标准 `run_condition == 2` 并行事件），然后只要 `now && !self.running.contains_key(&event.id)` 即重新启动：

```rust
// crates/wolf-game/src/auto_events.rs
pub fn sync(&mut self, vm: &mut Vm) -> SyncReport {
    let mut report = SyncReport::default();
    if !self.enabled {
        return report;
    }
    // 清理已自然结束的並列実行协程（保留 CE 43 由 Sys20 变化显式 restart）
    self.running.retain(|&event_id, &mut instance_id| {
        if event_id == 43 {
            return true;
        }
        vm.instance(instance_id).is_some()
    });

    for event in &self.events {
        let header_condition = condition_value(vm, event.variable)
            .is_some_and(|left| condition_met(event.operator, left, event.value));
        let now = header_condition && (event.id != 43 || self.title_menu_active);
        let before = self.latched.get(&event.id).copied().unwrap_or(false);
        let is_running = self.running.contains_key(&event.id);

        let should_start = if event.id == 43 || GATED_CALL_ONLY.contains(&event.id) {
            now && !before
        } else {
            now && !is_running
        };

        if should_start {
            if let Some(instance) = vm.start_event(event.id) {
                self.running.insert(event.id, instance);
                report.started += 1;
            }
        } else if !now && (before || is_running) {
            if let Some(instance) = self.running.remove(&event.id) {
                if vm.stop_instance(instance) {
                    report.stopped += 1;
                }
            }
        }
        self.latched.insert(event.id, now);
    }
    report.running = self
        .running
        .values()
        .filter(|instance| vm.instance(**instance).is_some())
        .count();
    report
}
```

### 3.2 BUG-26（S1 致命）：`ENGINE_RESTART` 仅包含 `&[270]`，遗漏其余无死循环的常时并行事件

#### 严格修复建议
在 `crates/wolf-game/src/game.rs` 中将常时并行监控事件加入 `ENGINE_RESTART`：
```rust
const ENGINE_RESTART: &[u32] = &[214, 216, 261, 270, 271];
```

### 3.3 BUG-27（S1 致命）：`Opcode 121` 忽略 `flags` 二阶指针寻址且 `eval_num` 对 `CommonSelf` 返回魔数地址字面量

#### 代码与字节码实锤取证
1. `crates/wolf-vm/src/exec.rs:1586`：`MagicKind::CommonSelf => raw` 导致读取 `15_026_910` 或 `15_013_110` 时返回了十进制地址 `15026910` 而非变量值。
2. `crates/wolf-vm/src/exec.rs:1720-1736`：`resolve_numeric_target` 未检查 `(arg(cmd, 3) & 0x10) != 0`，只要 `self_vars` 当前值落在 `15_000_000..15_100_000` 就无条件当作指针解引用，导致 `CE 266 pc=22`（`self10 += 47`，此时 `arg3 = 0x104`，`bit 4 == 0`）把 `47` 错误加到了 `CE 270` 的 `cself[11]` 上！
3. `crates/wolf-vm/src/exec.rs:2199-2252`：`Opcode 121` 未处理 `flags = arg(cmd, 3) & 0xFF` 的 `0x04`（右值 1 取变量地址字面量）、`0x08`（右值 2 取变量地址字面量）、`0x10`（左值二阶指针写入）、`0x20`（右值 1 二阶指针读取）、`0x40`（右值 2 二阶指针读取）。

#### 严格修复建议
修改 `crates/wolf-vm/src/exec.rs` 中的 `eval_num`、`resolve_numeric_target` 与 `Opcode 121`：

```rust
// crates/wolf-vm/src/exec.rs
fn eval_num(raw: i32, inst: &Instance, vars: &Variables) -> i32 {
    let magic = Magic::decode(raw);
    match magic.kind() {
        MagicKind::Literal => magic.index() as i32,
        MagicKind::SelfVar => inst.self_vars.get(magic.index() as usize),
        MagicKind::Var => vars.get(magic.index() as usize),
        MagicKind::SysVar => vars.get_sys(magic.index() as usize),
        MagicKind::CommonSelf => vars
            .common_self
            .get(&magic.common_event())
            .map_or(0, |bank| bank.get(magic.common_slot())),
        MagicKind::StrVar => 0,
        MagicKind::DbCell | MagicKind::Opaque => raw,
    }
}

fn resolve_numeric_target(raw: i32, flags: u32, inst: &Instance, vars: &Variables) -> i32 {
    if (flags & 0x10) != 0 {
        return eval_num(raw, inst, vars);
    }
    raw
}
```
并在 `121 =>` 分支（`exec.rs:2199`）中按 `flags` 解析 `a` 与 `b`：
```rust
121 => {
    let bits = arg(cmd, 3) as u32;
    let flags = bits & 0xFF;
    let target = resolve_numeric_target(arg(cmd, 0), flags, inst, vars);
    let raw_a = arg(cmd, 1);
    let raw_b = arg(cmd, 2);
    let a = if (flags & 0x04) != 0 {
        raw_a
    } else if (flags & 0x20) != 0 {
        let addr = eval_num(raw_a, inst, vars);
        eval_num_host(addr, inst, vars, host)
    } else {
        eval_arith_operand(raw_a, inst, vars)
    };
    let b = if (flags & 0x08) != 0 {
        raw_b
    } else if (flags & 0x40) != 0 {
        let addr = eval_num(raw_b, inst, vars);
        eval_num_host(addr, inst, vars, host)
    } else {
        eval_arith_operand(raw_b, inst, vars)
    };
    // 其余运算保持不变
```

### 3.4 BUG-28（S1 致命）：`Opcode 124 Field 18`（`処理中イベント番号`）返回调用者自身 ID，导致 `CE 223` 全部 9 个分支永不命中

#### 严格修复建议
修改 `crates/wolf-vm/src/exec.rs:2457-2462`：当 `field == 18` 时，先查询 `host.engine_state(18)`，或在 `Vm` 内查找当前活跃的窗口事件（`65, 68, 125, 126, 127, 131, 132, 133, 138`）或非并行主事件 ID，而非返回 `CE 223` 自身的 `500223`。

### 3.5 BUG-29（S1 致命）：`Instance.self_vars` 与 `Variables.common_self` 缺乏运行期实时同步

#### 严格修复建议
修改 `crates/wolf-vm/src/exec.rs:1696-1718`（`store_num`）与 `1754-1771`（`store_str`）：
1. 当公共事件（`inst.program.self_base == COMMON_SELF_BASE`）写入 `MagicKind::SelfVar`（`600..700`）时，**同时写入 `inst.self_vars` 与 `vars.common_self.entry(inst.event).or_default()`**。
2. 当写入 `MagicKind::CommonSelf` 时，除更新 `vars.common_self` 外，在 `run_instances` 中同步更新任何正在运行的 `instance.event == magic.common_event()` 实例的 `self_vars`，防止该实例结束时 `save_common_self` 用旧值反向覆盖。

### 3.6 BUG-30（S1 致命）：同帧 `mouse_consumed` 吞噬竞争与 `Opcode 125`（`auto_keys`）单帧清零丢失

#### 严格修复建议
1. 在 `crates/wolf-game/src/game.rs:3074-3081`（`mouse_key_bits`）中，仅标记 `self.mouse_consumed = true` 供帧末 `settle_pending_mouse` 清理跨帧缓存，但**不要在同一帧的后续 `mouse_key_bits()` 调用中屏蔽本帧的新鲜点击边沿**。
2. 在 `crates/wolf-vm/src/exec.rs` 中将 `input.auto_keys` 的清零时机从 `step_frame` 帧頭改为保留 1 个完整调度轮次（或双缓冲 `pending_auto_keys -> active_auto_keys`），确保排在 `CE 229`/`CE 271` 之前的协程在下一帧能够观测到 `Opcode 125` 注入的按键。

### 3.7 BUG-31（S2 严重）：`Opcode 250` 写入侧仅检查 `MagicKind::StrVar`，漏掉 `CSelf5..9` 字符串变量

#### 严格修复建议
修改 `crates/wolf-vm/src/exec.rs:2885-2893`：
```rust
let raw = arg(cmd, 4);
if is_string_operand(raw, inst) {
    (None, Some(DbValue::Str(eval_str(raw, inst, vars))))
} else {
    (None, Some(DbValue::Num(eval_num(raw, inst, vars))))
}
```
其中 `is_string_operand(raw, inst)` 定义为：
```rust
fn is_string_operand(raw: i32, inst: &Instance) -> bool {
    let magic = Magic::decode(raw);
    match magic.kind() {
        MagicKind::StrVar => true,
        MagicKind::SelfVar => {
            inst.program.self_base == crate::program::COMMON_SELF_BASE
                && (605..=609).contains(&magic.index())
        }
        MagicKind::CommonSelf => (5..=9).contains(&magic.common_slot()),
        _ => false,
    }
}
```

### 3.8 BUG-32（S2 严重）：`Opcode 174`（返回标题画面）与 `Opcode 211`（预约公共事件）为空实现

#### 严格修复建议
在 `crates/wolf-game/src/game.rs:3664-3683` 中：
* `reserve(&mut self, event: EventId)` 将 `event` 推入 `self.reserved_events: VecDeque<EventId>`，在 `Game::frame` 中当无阻塞主事件时调用 `self.start_event(event)`。
* `return_to_title(&mut self)` 设置 `*self.return_to_title_requested = true`，在 `Game::frame` 末尾停止所有地图与菜单协程、清空图层并重新执行 `self.boot()`。

### 3.9 BUG-33（S2 严重）：`MapRuntime` 换页条件死锁并行事件状态机

#### 严格修复建议
修改 `crates/wolf-game/src/map_runtime.rs:455-467`：仅当当前活跃页面为 `Trigger::ActionKey` 或 `Trigger::Autorun`（或该并行页面正在 `WaitState::Child` 等待同步子事件返回）时才保持 `continue` 阻塞换页；若当前活跃页面为 `Trigger::Parallel` 且僅处于普通 `WaitState::Frames` 等待，当 `state.active != want` 时立即允许换页。

### 3.10 BUG-34（S2 严重）：`Sys100/Sys102` 音量设置未同步至 Godot 前端且未持久化回 `System.sav`

#### 严格修复建议
1. 在 `crates/wolf-gdext/src/lib.rs` 的 `WolfGame::frame` 中将主音量放入 `packet`：
   ```rust
   let settings = game.live_settings();
   packet.set("bgm_volume", settings.bgm_volume as i64);
   packet.set("se_volume", settings.se_volume as i64);
   ```
2. 在 `godot/scripts/GameView.gd` 中乘上主音量系数 `bgm_master := clampf(float(packet.get("bgm_volume", 100)) / 100.0, 0.0, 1.0)` 与 `se_master := clampf(float(packet.get("se_volume", 100)) / 100.0, 0.0, 1.0)`。
3. 在 `crates/wolf-game/src/game.rs:2635-2640` 中，当检测到 `volumes != self.applied_volumes` 或 `CE 132` 退出时，调用 `let _ = self.save_system_settings();`。

### 3.11 BUG-35（S3 一般）：`textpic.rs` 将 `\sdb` 误路由至 `cdb`、`PictureVars` 缺 `\cself` 及 `Wait(0)` 强制延迟

#### 严格修复建议
1. 在 `crates/wolf-game/src/textpic.rs:658` 的 `Cells` trait 中新增 `fn sdb(&self, ty: i32, row: i32, column: i32) -> Option<String>`，并在 `PictureCells`（`game.rs:2919`）中路由至 `Container::Sys`。
2. 在 `crates/wolf-vm/src/exec.rs:2707`（`Opcode 180`）中，若 `eval_num(arg(cmd, 0), inst, vars) <= 0`，直接 `inst.pc += 1; None` 而不阻塞 1 帧。

## 四、 第二轮深挖新发现漏洞深度剖析与修复方案（BUG-36 至 BUG-40）

### 4.1 BUG-36（S1 致命）：`Opcode 176`（`ContinueLoop` / `ループ開始へ戻る`）被逆向误判为 `StartLoop2`（新循环头）

#### 现场表现与审计报告交叉实锤
1. **直接解释了 `BYTECODE_AUDIT_REPORT.md` 第 4 节的“32 处无等待死循环”之谜**：
   运行 `python3 -I tools/audit_bytecode.py` 时，报告第 4 节警告了 `CE 25 pc=20..33`、`CE 75 pc=190..197`、`CE 109 pc=15..39` 等 32 处“无显式 Wait 或 Break 的循环结构”。核查字节码后证实：**这 32 处全部是因为 `Opcode 176` 被误认为循环头 `StartLoop2` 并由外层 `499` 隐式闭合所产生的假循环！**
2. **实机破坏范围（全库 54 处 `Opcode 176`）**：
   * `CE 63 (X[共]メッセージウィンドウ) pc=63`：在 `if Sys0 <= -1 { Wait(1); ContinueLoop(176); }` 中，因 `176` 未跳回 `pc=57` 循环头，`CE 63` 在无对话的每一帧都穿透执行 `pc=67..87` 的窗口重绘。
   * `CE 212 (フキダシ会話文表示) pc=72`：多行气泡台词按 `\n` 切分首行后执行 `176` 继续切分下一行，因 `176` 被当作新循环头压入 `inst.loops` 并向下穿透，导致后续 `pc=79` 的 `BreakLoop(171)` 只弹出了 `176` 伪造的内层帧，无法跳出 `pc=62` 的外层循环。
   * `CE 268 (○┣[ﾒｯｾｰｼﾞ]名前欄の変更) pc=55, 81` 与 `CE 270 (×┣[ﾒｯｾｰｼﾞ]表示処理) pc=138, 162, 348`：在 `170` 循环内过滤无效行或解析完一个 `$tag` 后调用 `176` 跳回循环头，当前全部穿透失效。

#### 严格修复建议
1. **修改 `crates/wolf-vm/src/program.rs`**：
   * 在 `Control` 枚举（`program.rs:92`）中新增 `LoopContinue`；
   * 在 `Program::from_slots`（`program.rs:280`）中，将 `111 | 112 | 102 | 170 | 176 | 179 =>` 改为 `111 | 112 | 102 | 170 | 179 =>`（不再为 `176` 创建 `BlockKind::Loop`）；
   * 为 `176` 添加分支：
     ```rust
     176 => {
         control[pc] = Control::LoopContinue;
     }
     ```
2. **修改 `crates/wolf-vm/src/exec.rs`**：
   * 在 `execute` 的 `match program.control.get(pc)`（`exec.rs:2051`）中处理 `Control::LoopContinue`：
     ```rust
     Control::LoopContinue => {
         if let Some(ctx) = inst.loops.last() {
             close_loop(inst, ctx.block);
         } else {
             inst.pc += 1;
         }
         continue;
     }
     ```
     注：调用 `close_loop(inst, ctx.block)` 既能将无限循环（`170`，`remaining < 0`）跳回 `head + 1`，又能在计次循环（`179`，如 `CE 268 pc=43`）中正确将 `remaining` 减 1 并在最后一次迭代跳出到 `end_target`！

### 4.2 BUG-37（S1 致命）：`Opcode 140`（`Sound`）未对延迟/淡入、音量、音调参数调用 `eval_num`，且误将 `sound_type == 1` 判为 `Stop`

#### 代码与字节码实锤取证
* **源码定位**：`crates/wolf-vm/src/exec.rs:2601-2625`：
  ```rust
  let volume = if argc(cmd) >= 6 { arg(cmd, 4) } else { 100 };
  // ...
  let frames = if argc(cmd) >= 6 {
      arg(cmd, 1).max(0)
  } else {
      0
  };
  ```
* **字节码实锤**：
  * `CE 270 pc=2017`（`a=[33554464, 1600002, 0, 0, 100, 100]`）与 `CE 183 pc=93`（`a=[33554464, 1600015, 0, 0, 100, 100]`）：`arg(cmd, 1)` 是自变量 `1600002` / `1600015`，未调 `eval_num` 导致 `frames = 1_600_002`（在 `GameView.gd:472` 中创建了 `1600002 / 60.0 = 26666.7 秒` 的定时器才播放音效！）。
  * `CE 188 pc=238`（`a=[33554432, 0, 0, 0, 1600099, 1600098, 0]`）：`arg(cmd, 4)` 是变量 `1600099`。
  * `CE 188 pc=31, 242`（`a=[16777216, 0, 1600003, 0]`）：`sound_type == 1`（通过变量 `arg(cmd, 2)` 指定 SystemDB 音频条目），当求值结果 `>= 0` 时应调用 `host.sound_db(db_type, entry)` 播放，`< 0` 时为停止。

#### 严格修复建议
修改 `crates/wolf-vm/src/exec.rs:2585-2631`：
```rust
let sound_type = ((bits >> 24) & 0xFF) as u8;
let entry = ((bits >> 8) & 0xFFFF) as u16;
let var_entry = if sound_type == 1 {
    eval_num(arg(cmd, 2), inst, vars)
} else {
    -1
};
let db_type = match bits & 0xF0 {
    0x10 => 2, // BGS list
    0x20 => 3, // SE list
    _ => 1,    // BGM list
};
let db_play = (sound_type == 0 && entry != 0xFFFF) || (sound_type == 1 && var_entry >= 0);
let is_play = db_play || (bits >= 0 && bits & 0x0200_0000 != 0);
let (action, file, volume, frames) = if is_play {
    let (file, volume) = if db_play {
        let lookup_entry = if sound_type == 1 {
            var_entry as u16
        } else {
            entry
        };
        let (file, db_volume) = host.sound_db(db_type, lookup_entry).unwrap_or_default();
        let volume = if argc(cmd) >= 5 {
            eval_num(arg(cmd, 4), inst, vars)
        } else {
            db_volume
        };
        (file, volume)
    } else {
        let file = expand(
            cmd.strings.first().map_or("", String::as_str),
            inst,
            vars,
            host,
        );
        let volume = if argc(cmd) >= 5 {
            eval_num(arg(cmd, 4), inst, vars)
        } else {
            100
        };
        (file, volume)
    };
    let frames = if argc(cmd) >= 2 {
        eval_num(arg(cmd, 1), inst, vars).max(0)
    } else {
        0
    };
    (SoundAction::Play, file, volume, frames)
} else {
    let frames = if argc(cmd) >= 2 && argc(cmd) <= 5 {
        eval_num(arg(cmd, 1), inst, vars).max(0)
    } else {
        0
    };
    (SoundAction::Stop, String::new(), 0, frames)
};
```

### 4.3 BUG-38（S2 严重）：`Opcode 220..=222` 忽略 `CSelf5..9` 字符串变量，导致 `Save/System.sav` 读写被重定向至 `Slot(0)`

#### 严格修复建议
修改 `crates/wolf-vm/src/exec.rs:2786-2791`：
```rust
let file_raw = arg(cmd, 1);
let file = if is_string_operand(file_raw, inst) {
    SaveTarget::Path(eval_str(file_raw, inst, vars))
} else {
    SaveTarget::Slot(eval_num(file_raw, inst, vars))
};
```

### 4.4 BUG-39（S2 严重）：`Opcode 130`（`Teleport`）与 `Opcode 151`（`ChangeColor`）未对参数调用 `eval_num`

#### 严格修复建议
修改 `crates/wolf-vm/src/exec.rs:2526-2540` 与 `2641-2645`：
```rust
130 => {
    host.teleport(
        eval_num(arg(cmd, 0), inst, vars),
        eval_num(arg(cmd, 3), inst, vars),
        eval_num(arg(cmd, 1), inst, vars),
        eval_num(arg(cmd, 2), inst, vars),
        arg(cmd, 4),
    );
    inst.wait = WaitState::Frames(1);
    inst.pc += 1;
    Some(Signal::Blocked)
}
// ...
151 => {
    host.change_color(
        eval_num(arg(cmd, 0), inst, vars),
        eval_num(arg(cmd, 1), inst, vars),
    );
    inst.pc += 1;
    None
}
```

### 4.5 BUG-40（S2 严重）：`wolf-gdext` 与 `GameView.gd` 每帧全量构造字典与 GDScript 侧二次排序开销

#### 严格修复建议
详见第七章 7.3 节跨语言零抖动渲染桥接改造方案。

## 五、 第三轮基于真实二进制资产与 Godot 桥接层的新发现漏洞剖析（BUG-41 至 BUG-46）

### 5.1 BUG-41（S1 致命）：`wolf-gdext` 的 `WolfGame::frame()` 完全漏调 `game.tile_quads(atlas)`，导致 Godot 前端地图瓦片层 100% 缺失

#### 现场表现
在 Godot 4.7.2 前端运行游戏时，任何依赖瓦片地图层（`TileSetData.dat` + `.mps` 三层图块数据，如 `Map002.mps`、`Map003.mps`、`Dungeon.mps`、`SampleMapB.mps` 等 `has_tile_data == true` 的地图）的场景，背景瓦片完全不显示（呈现为 `draw_rect(..., Color.BLACK)` 的纯黑底色），仅能看到浮在黑底上的 Picture 图层。而在 `wolf-cli` 截图模式下瓦片地图却能正常显示，造成两端渲染严重不一致。

#### 代码实锤取证
* **`crates/wolf-game/src/game.rs:1323-1350`** 专门实现了 `pub fn tile_quads(&mut self, atlas: &mut Atlas) -> Vec<SpriteQuad>`：
  ```rust
  /// Builds the tile-layer quads for the current map.
  /// This is the layer WOLF draws before every picture.
  pub fn tile_quads(&mut self, atlas: &mut Atlas) -> Vec<SpriteQuad> { ... }
  ```
* **`crates/wolf-gdext/src/lib.rs:265-269`**（`WolfGame::frame`）：
  ```rust
  let mut sprites: Array<VarDictionary> = Array::new();
  for quad in game.picture_quads(atlas) {
      let sprite = sprite_dict(&quad, atlas.size());
      sprites.push(&sprite);
  }
  ```
  搜索整个 `crates/wolf-gdext/src/lib.rs`，**全文没有任何一处调用 `game.tile_quads(atlas)`**！

#### 严格修复建议
在 `crates/wolf-gdext/src/lib.rs:265` 的 `WolfGame::frame()` 中，在压入 `picture_quads` 之前先调用 `game.tile_quads(atlas)`，并将其 `z` 轴设为 `TILE_Z`（例如 `-1_000_000`），确保地图瓦片层绘制在所有 Picture 槽位（含负数全屏层 `-1..-9999`）之下：

```rust
// crates/wolf-gdext/src/lib.rs
const TILE_Z: i64 = -1_000_000;

let mut sprites: Array<VarDictionary> = Array::new();
for quad in game.tile_quads(atlas) {
    let mut sprite = sprite_dict(&quad, atlas.size());
    sprite.set("z", TILE_Z);
    sprites.push(&sprite);
}
for quad in game.picture_quads(atlas) {
    let sprite = sprite_dict(&quad, atlas.size());
    sprites.push(&sprite);
}
```

### 5.2 BUG-42（S1 致命）：`savegame::apply` 恢复存档 BGM 时未向 `game.sounds` 推送 `SoundCmd`

#### 现场表现
在 Godot 4.7.2 前端中，无论通过标题画面“读取进度”（`CE 131` 执行 `Opcode 220`）还是命令行 `--load-save=SaveData01.sav` 读档，**读档后背景音乐完全不切换**（标题曲继续播放，或无法按存档状态停播）。

#### 代码与完整素材包实锤取证
* **源码定位**：`crates/wolf-game/src/savegame.rs:167-184`：
  ```rust
  if let Some((file, volume)) = game.current_bgm.clone() {
      if let Some(audio) = game.audio.as_mut() {
          let gain = (volume.clamp(0, 100) as f32) / 100.0;
          let _ = audio.play_bgm_with_fade(&file, true, gain, 0);
      }
  } else if let Some(audio) = game.audio.as_mut() {
      audio.stop_bgm(0);
  }
  ```
* **实证核验**：经扫描完整素材包，`work/Data/BGM/none.mp3` 为真实存在的静音 MP3 文件；但在 Godot 模式下 `game.audio` 恒为 `None`（音频由 `GameView.gd` 消费 `game.sounds: Vec<SoundCmd>` 驱动）。`savegame::apply` 既未在 `Opcode 220` 读档帧向 `game.sounds` 推送 `SoundCmd`，也未在 `GameView.gd::_load_audio` 中支持 Mod 覆盖层与大小写不敏感路径回退。

#### 严格修复建议
修改 `crates/wolf-game/src/savegame.rs:174-184`，同步向 `game.sounds` 推送 `SoundCmd`：

```rust
// crates/wolf-game/src/savegame.rs
if let Some((file, volume)) = game.current_bgm.clone() {
    let clamped_vol = volume.clamp(0, 100);
    game.sounds.push(wolf_vm::SoundCmd {
        channel: wolf_vm::SoundChannel::Bgm,
        action: wolf_vm::SoundAction::Play,
        file: file.clone(),
        volume: clamped_vol,
        frames: 0,
    });
    if let Some(audio) = game.audio.as_mut() {
        let gain = (clamped_vol as f32) / 100.0;
        let _ = audio.play_bgm_with_fade(&file, true, gain, 0);
    }
} else {
    game.sounds.push(wolf_vm::SoundCmd {
        channel: wolf_vm::SoundChannel::Bgm,
        action: wolf_vm::SoundAction::Stop,
        file: String::new(),
        volume: 0,
        frames: 0,
    });
    if let Some(audio) = game.audio.as_mut() {
        audio.stop_bgm(0);
    }
}
```

### 5.3 BUG-43（S1 致命）：`GameHost::database` 的 `wants_text` 仅检查 `STR_BASE`（`3_000_000..`），导致读取空槽位至 `CSelf5..9` 时残留旧字符串

#### 代码实锤取证
* **源码定位**：`crates/wolf-game/src/game.rs:3392-3394, 3447-3449`：
  ```rust
  let wants_text = op.destination.is_some_and(|target| {
      (wolf_vm::magic::STR_BASE..wolf_vm::magic::STR_BASE + 1_000_000).contains(&target)
  });
  ```
* **机理剖析**：当脚本在循环中通过 `Opcode 250` 将数据库字符串列读取到 `CSelf5..9`（`1_600_005..=1_600_009`）时，一旦遇到扩展行（`row >= 100`）、运行期缩容行或超出 schema 的列，因 `1_600_005` 不在 `STR_BASE`（`3_000_000..4_000_000`）范围内，`wants_text` 为 `false`，函数返回 `Some(DbValue::Num(0))`。随后 `exec.rs:2915` 调用 `store_num(inst, vars, 1_600_005, 0)`，只清零了数值槽 `self_vars.nums[605]`，而**字符串槽 `self_vars.strings[605]` 原封不动保留了上一行的字符串**，导致列表渲染出现重复脏行！

#### 严格修复建议
修改 `crates/wolf-game/src/game.rs:3392-3394, 3447-3449` 中的 `wants_text` 判定，涵盖 `CSelf5..9` 与 `CommonSelf` 字符串槽：

```rust
let wants_text = op.destination.is_some_and(|target| {
    let magic = wolf_vm::Magic::decode(target);
    match magic.kind() {
        wolf_vm::MagicKind::StrVar => true,
        wolf_vm::MagicKind::SelfVar => (5..=9).contains(&(magic.index() % 100)),
        wolf_vm::MagicKind::CommonSelf => (5..=9).contains(&magic.common_slot()),
        _ => false,
    }
});
```

### 5.4 BUG-44（S2 严重）：`GameHost::engine_state` 硬编码 `Field 10`（滚轮）为 `Some(0)` 且 `apply_wheel` 提前清空 `self.wheel`

#### 代码与字节码实锤取证
* **源码定位**：
  1. `crates/wolf-game/src/game.rs:2245`：`fn apply_wheel(&mut self) -> u32` 在 `self.vm.step_frame` 之前执行 `let notches = std::mem::take(&mut self.wheel);`，将 `self.wheel` 清零。
  2. `crates/wolf-game/src/game.rs:3781-3804`：
     ```rust
     fn engine_state(&mut self, field: i32) -> Option<i32> {
         match field {
             0 => Some(0),
             1 => Some(-1),
             // ...
             10 => Some(0),
             20 => Some(self.mouse[0]),
             21 => Some(self.mouse[1]),
             _ => None,
         }
     }
     ```
* **字节码实锤**：`BYTECODE_AUDIT_REPORT.md` 第 2.2 节实锤指出：
  * `CE 223` 中有 **9 处** 读取 `Field 10`（鼠标滚轮增量）；
  * `CE 224` 读取 `Field 11` 与 `Field 12`（窗口内鼠标坐标/移出窗口检测，移出窗口时返回 `-1`）。

#### 严格修复建议
1. 在 `Game` 中保留 `frame_wheel: i32` 快照（在 `apply_wheel` 中将 `self.frame_wheel = self.wheel` 保存下来供本帧 `GameHost` 查询），并在 `GameHost::engine_state` 中返回 `10 => Some(self.frame_wheel)`。
2. 对 `Field 11` 与 `Field 12`：当鼠标在 `0..1024` 与 `0..576` 窗口范围内时分别返回 `Some(self.mouse[0])` 与 `Some(self.mouse[1])`，移出窗口时返回 `Some(-1)`，使 `CE 224` 能正确感知鼠标移出窗口。

### 5.5 BUG-45（S2 严重）：`Atlas::sprites` 丢弃 `Picture.blend`，Godot `GameView.gd:_draw` 缺失混合模式渲染

#### 代码实锤取证
* `crates/wolf-game/src/atlas.rs:94-110` 的 `SpriteQuad` 结构体未包含 `pub blend: i32`，`Atlas::sprites`（`atlas.rs:505-516`）在从 `ScreenQuad` 生成 `SpriteQuad` 时丢弃了 `quad.blend`。
* `godot/scripts/GameView.gd:380-386` 的 `_draw()` 直接在单个 `Control` 画布上调用 `draw_texture_rect_region`，未使用材质区分 Normal / Add / Sub / Multiply。

#### 严格修复建议
1. 在 `SpriteQuad`（`crates/wolf-game/src/atlas.rs:94`）中增加 `pub blend: i32` 字段（面板九宫格与光标默认设为 `0`，普通图片从 `ScreenQuad` 传递 `picture.blend`），并在 `wolf-gdext/src/lib.rs:427` 的 `sprite_dict` 中导出 `dict.set("blend", quad.blend as i64)`。
2. 在 Godot `GameView.gd` 中，由于单个 `CanvasItem._draw()` 只能使用单一材质，对于 `blend != 0` 的高光/特效 Quad，可通过轻量级池化的子 `Node2D`/`Sprite2D`（挂载 `BLEND_MODE_ADD` / `BLEND_MODE_SUB` / `BLEND_MODE_MUL` 的 `CanvasItemMaterial` 并设置对应的 `z_index`）渲染，保持普通 `blend == 0` 图层继续走高速批量 `draw_texture_rect_region`。

### 5.6 BUG-46（S2 严重）：`GameHost::character_state` 恒返回 `None`，且 `Opcode 160 / 1000` 漏调 `eval_num`

#### 代码与字节码实锤取证
* `crates/wolf-game/src/game.rs:3774-3779`：`character_state` 对全库 78 处查询恒返回 `None`。虽然 `AGENTS.md` 严令禁止伪造固定常数坐标，但 `self.current_map` 与 `self.runtime` 中实际持有地图事件 `target` 的真实瓦片坐标 `(event.x, event.y)`（来自 `.mps` 或 `SavePart1.objects`）！
* 对于 `target >= 0`（查询指定地图事件 `object`）：可从 `self.current_map` / `self.runtime` 中查询该事件的真实 `x`（`Field 2`：瓦片 X，`Field 6`：`x * 16` 像素 X）与 `y`（`Field 3`：瓦片 Y，`Field 7`：`y * 16` 像素 Y），既不伪造常数，又忠实还原了 `.mps` 数据中的事件真实坐标。
* 同时在 `crates/wolf-vm/src/exec.rs:2650, 2960` 中，对 `Opcode 160` 的 `arg(cmd, 0)`、`arg(cmd, 1)` 以及 `Opcode 1000` 的 `arg(cmd, 1)` 调用 `eval_num(arg(cmd, ...), inst, vars)`。

### 5.7 BUG-47（S1 致命）：`GameHost::picture_state` 将 `Field 2/3`（像素宽高）误作缩放比 `scale`，且 `Opcode 124` 忽略 `sub & 0x0F00` 复合赋值算子

#### 现场表现
1. **对话框与气泡自适应排版失真（`CE 270`）**：`CE 270` 在绘制对白文本、角色姓名、头像、立绘与气泡尾巴后，通过 `Opcode 124 (0x4000) Field 2/3` 读取各图层的实际像素宽度与高度，用于计算气泡窗口缩放、尾巴偏移与姓名牌位置。由于 `picture_state` 错误返回了 `picture.scale`（`100`），导致不论文本有多长、立绘有多高，`CE 270` 读到的宽高永远是 `100 × 100`！
2. **设置界面音量滑块拖拽与点击区域错位（`CE 223`）**：`CE 223` 通过 `Field 2` 读取滑块槽 `Picture 12053 / 12054` 的像素宽度（实际为 `200px`），通过 `Field 3` 读取滚动条 `Picture 12005` 的像素高度，用于计算鼠标拖拽边界 `center_x - width / 2`。由于返回了 `scale = 100`，滑块有效宽度被错误截半！
3. **状态/菜单界面头像缩放到错误的百分比（`CE 63 / CE 90 / CE 94 / CE 178`）**：脚本先将目标显示宽高（如 `140`）存入 `CSelf91/92`，然后调用 `Opcode 124 (sub = 17408 = 0x4400)` 即 **`/=`（除等复合赋值）** 除以图片原始像素宽高以计算缩放百分比；结果一方面 `Field 2/3` 返回了初始 `scale`（在 `CE 94 pc=365` 中初始 `scale` 为 `0`！），另一方面 `Opcode 124` 忽略了 `0x0400`（`/=`）直接覆盖写入，导致 `CSelf91/92` 被直接覆写为 `0` 或 `100`！

#### 代码与字节码实锤取证
* **源码定位 1（`crates/wolf-game/src/game.rs:3749-3772`）**：
  ```rust
  fn picture_state(&mut self, slot: i32, field: i32) -> Option<i32> {
      let picture = self.screen.picture(slot)?;
      let value = match field {
          0 => Some(picture.x),
          1 => Some(picture.y),
          2 => Some(picture.scale),
          3 => Some(picture.scale_y),
          4 => Some(picture.opacity),
  ```
* **源码定位 2（`crates/wolf-vm/src/exec.rs:2466-2484`）**：
  ```rust
  124 => {
      let target = arg(cmd, 0);
      let sub = arg(cmd, 1);
      // ...
      let value = match sub & 0xF000 { ... };
      if let Some(value) = value {
          store_num(inst, vars, target, value); // <--- 完全忽略了 sub & 0x0F00 复合算子！
      }
  }
  ```
* **源码定位 3（`crates/wolf-game/src/picture.rs:1505-1507`）**：
  ```rust
  let (base_width, base_height) = if picture.kind.is_text() {
      picture.window.unwrap_or((0, 0)) // <--- 自动尺寸文本的 window 为 Some((1, 1))，并非实际文本像素宽高！
  ```
* **全量字节码实锤（39 处 `Field 2/3` 查询 + 9 处复合算子调用）**：
  * `CE 270 pc=419..458`：绘制文章文本与姓名文本后立即查询 `Field 2`（`pc=425, 447`）与 `Field 3`（`pc=431, 453`），并在 `pc=439` 打印调试日志 `文章[ \cself[22] , \cself[23] ]`；随后在 `pc=521..599` 查询头像、立绘、气泡尾巴的 `Field 2/3`，日志明确写有 `顔グラ[ \cself[24] , \cself[25] ]`、`キャラ画像H[ \cself[36] ]`、`シッポH[ \cself[29] ]`（`H` 即 Height 像素高度）！
  * `CE 63 pc=145-146`、`CE 90 pc=205-206`、`CE 94 pc=368-369`、`CE 178 pc=248-249`：使用 `sub = 17408`（`0x4400`，即 `0x4000 | 0x0400` 除等 `/=`）；`CE 270 pc=1107`：使用 `sub = 4608`（`0x1200`，即 `0x1000 | 0x0200` 减等 `-=`）。

#### 严格修复建议
1. **修复 `crates/wolf-vm/src/exec.rs:2482-2484` 中的 `Opcode 124` 复合赋值逻辑**：
   ```rust
   if let Some(value) = value {
       let op = (sub >> 8) & 0x0F;
       let final_val = if op == 0 {
           value
       } else {
           let current = eval_num(target, inst, vars);
           match op {
               1 => current.saturating_add(value),
               2 => current.saturating_sub(value),
               3 => current.saturating_mul(value),
               4 => if value != 0 { current / value } else { 0 },
               5 => if value != 0 { current % value } else { 0 },
               _ => value,
           }
       };
       store_num(inst, vars, target, final_val);
   }
   ```
2. **修复 `crates/wolf-game/src/game.rs:3749-3772` 中的 `GameHost::picture_state`（以及 `Screen::picture_rect`）**：
   对于 `Field 2`（像素宽度）与 `Field 3`（像素高度）：
   * 若 `picture.kind` 为 `PictureKind::File` 或 `PictureKind::FileString`：返回纹理单格基础像素尺寸（`base_w / cols`, `base_h / rows`）；
   * 若 `picture.kind` 为 `PictureKind::WindowFile` 或 `PictureKind::WindowString`：返回 `picture.window.unwrap_or((0, 0))` 的宽高；
   * 若 `picture.kind` 为 `PictureKind::Text`：调用 `textpic::expand_picture_text` + `textpic::block_size(&expanded, picture.font_size)` 返回真实排版像素宽高 `(w as i32, h as i32)`（同时在 `Screen::picture_rect` 中对 `window == Some((1, 1))` 的自适应文本同步使用该真实宽高）。

### 5.8 BUG-48（S2 严重）：`PictureAction::Erase` 忽略淡出帧数（全库 241 处），导致 `CE 234` 弹出文本零帧消失与全剧渐隐硬切

#### 现场表现
1. **夜间互动高潮提示文本（`CE 234` `Picture 3010`）完全不可见（0 帧消失）**：在 `CE 234`（`H_射精感メッセージ`）中，脚本在 `pc=10` 执行 `150 Draw(slot=3010, fade=50, opacity=200)` 绘制提示文本，紧接着在**下一条指令 `pc=11`（中间没有任何 `Wait`）**执行 `150 Erase(slot=3010, fade=50)`！在原版 WOLF 引擎中，`Erase(fade=50)` 会启动一个持续 50 帧的透明度归零渐隐过渡，并在过渡结束后移除图层；而当前 `Screen::apply` 直接忽略 `fade=50` 立即 `self.pictures.remove(&3010)`，导致 `Picture 3010` 在创建的同一微秒内被销毁，连 1 帧都未渲染到屏幕上！
2. **夜间切入演出（`CE 219/220/281/282`）与 CG 相册（`CE 301/303`）丢失平滑淡出**：全库共有 **241 条** `PictureAction::Erase` 指令携带了 `fade > 0`（如 `CE 281/282` 结束切入时的 100 帧淡出、`CE 301` 切换相册 CG 时的 20/30 帧交叉淡出），当前全部退化为生硬的 0 帧瞬时消失。

#### 代码与字节码实锤取证
* **源码定位（`crates/wolf-game/src/picture.rs:1245-1262`）**：
  ```rust
  PictureAction::Erase => {
      match cmd.args.get(ERASE_SPAN) {
          Some(other) => {
              let (lo, hi) = (cmd.number.min(*other), cmd.number.max(*other));
              self.pictures
                  .retain(|number, _| *number < lo || *number > hi);
          }
          None => {
              self.pictures.remove(&cmd.number);
          }
      }
  }
  ```
* **字节码实锤（`work/out/_ce_full.json`）**：
  * `CE 234 pc=10`：`{"op": 150, "a": [285212689, 3010, 50, 1, 0, 1, 200, ...], "s": ["\E\cself[6]\f[18]\n\cself[5]"]}`
  * `CE 234 pc=11`：`{"op": 150, "a": [2, 3010, 50, 100]}`（同见 `pc=20..21`、`pc=28..29`）
  * 全库统计：`op=150, action=Erase` 共 683 处，其中 `fade = cmd.args[0] > 0` 的指令多达 **241 处**！

#### 严格修复建议
在 `Picture` 结构体（`crates/wolf-game/src/picture.rs:607`）中新增字段 `pub erase_after_slide: bool`：
1. 当 `PictureAction::Erase` 的 `fade = cmd.args.first().copied().unwrap_or(0) > 0` 时，对目标槽位（或 `[lo..=hi]` 区间内的每个槽位）不立即 `remove`，而是调用 `picture.fade_out_to_erase(fade as u32)`：构造一个 `target.opacity = 0`、`remaining = fade` 的 `Transition`，并将 `picture.erase_after_slide = true`；
2. 在 `Screen::tick`（`crates/wolf-game/src/picture.rs:1286`）中，当 `picture.tick()` 完成过渡（`picture.slide.is_none()`）且 `picture.erase_after_slide` 为 `true` 时，将其从 `self.pictures` 中正式移除（若在渐隐途中收到新的 `Draw` 指令覆盖该槽位，则新的 `Picture` 实例自然重置 `erase_after_slide = false`）。

## 六、 历史待核对基线缺陷汇总（BUG-20 至 BUG-24）

| 编号 | 模块定位 | 当前状态与核对要点 |
| :--- | :--- | :--- |
| **BUG-20** | `crates/wolf-game/src/map_runtime.rs:312-383` | `action_key_at` 与 `start_pending` 已分离 `Trigger::ActionKey` 与 `Trigger::Parallel`，但需配合 `BUG-33` 修复确保 `Parallel` 页面在条件变化时及时换页。 |
| **BUG-21** | `crates/wolf-game/src/game.rs:1298, 1438` | `install_map` 与 `switch_map` 已调用 `self.runtime.stop_all(&mut self.vm)` 及 `self.screen.clear_screen_layers()`，但对由 `start_map_event` 直接启动、未纳入 `self.runtime` 的独立地图事件实例（如 `Event 0`），应在 `install_map` 中按 `instance.program.self_base == MAP_SELF_BASE` 统一清理。 |
| **BUG-22** | `crates/wolf-game/src/game.rs:2145-2185` | `handle_choice_input` 已修复为点击选择支框外部时：若允许取消则触发 Cancel，若不允许取消则保留点击边沿不吞噬（`self.mouse_consumed` 保持 `false`）。 |
| **BUG-23** | `crates/wolf-vm/src/vars.rs:146-210`<br>`crates/wolf-vm/src/exec.rs:1671-1695` | `EventSelfVars` 已内置 5 个字符串槽（`CSelf5..9`），但需配合 `BUG-29`（运行期实时同步）、`BUG-31`（`Opcode 250` 写识别）、`BUG-38`（`Opcode 220..222` 路径识别）与 `BUG-43`（`Opcode 250` 读识别）彻底闭环。 |
| **BUG-24** | `crates/wolf-vm/src/exec.rs:2934-2946` | `Opcode 300`（`CallByName`）已在 `exec.rs:2934` 实现，通过 `ProgramSet::id_by_name`（含 `strip_tag`）解析事件名并生成 `Signal::CallByName`。 |

## 七、 工程代码系统性架构优化指导建议（Engineering & Architectural Roadmap）

### 7.1 虚拟机变量与内存寻址层的“单一事实来源”（Single Source of Truth）重构
1. **在 `Magic` 上统一定义字符串槽位判定方法**：
   在 `crates/wolf-vm/src/magic.rs` 的 `impl Magic` 中修改 `is_string`，支持传入上下文 `is_common_event: bool`：
   ```rust
   #[must_use]
   pub const fn is_string_slot(self, is_common_event: bool) -> bool {
       match self.kind {
           MagicKind::StrVar => true,
           MagicKind::SelfVar => is_common_event && matches!(self.index % 100, 5..=9),
           MagicKind::CommonSelf => matches!(self.index % 100, 5..=9),
           _ => false,
       }
   }
   ```
   在 `Opcode 122`、`Opcode 220..=222`、`Opcode 250`（读与写）中统一调用 `Magic::decode(raw).is_string_slot(...)`，彻底消除散落在各处的判断分歧。
2. **消除公共事件 `Instance.self_vars` 与 `Variables.common_self` 的双份拷贝**：
   将公共事件（`self_base == COMMON_SELF_BASE`）的 `SelfVar` 读写直接路由至 `Variables.common_self.entry(inst.event).or_default()`（仅当同一公共事件发生递归调用 `depth > 1` 时在 `Instance` 中压栈备份局部参数 `CSelf0..9`），从根源上消除跨事件 `15_000_000+` 读写的脏读与退出覆盖（`BUG-29`）。

### 7.2 多协程合作式调度器的确定性三阶段流水线（Three-Phase Frame Scheduler）
将 `Game::frame`（`crates/wolf-game/src/game.rs:2386`）重构为严格的三阶段流水线：
1. **Phase 1（输入快照锁定与触发器电平同步）**：
   * 将本帧 `self.wheel` 快照存入 `self.frame_wheel`（供 `Opcode 124 Field 10` 与 `apply_wheel` 同时读取，互不吞噬）；
   * 按电平触发规则执行 `self.auto_events.sync(&mut self.vm)`（`BUG-25`）与 `self.restart_always_events()`（含 `214, 216, 261, 270, 271`，`BUG-26`）。
2. **Phase 2（VM 步进与双缓冲 `auto_keys`）**：
   * 在 `Vm` 的 `InputState` 中维护 `active_auto_keys: u32` 与 `next_auto_keys: u32`；
   * 协程执行 `Opcode 125` 时同时置位 `active_auto_keys |= bits` 与 `next_auto_keys |= bits`；
   * 帧末将 `active_auto_keys = std::mem::take(&mut next_auto_keys)`，确保无论注入协程排在 `instances` 的前部还是尾部，目标协程都能稳定观测到 1 次虚拟按键（`BUG-30`）。
3. **Phase 3（帧末状态结算与延迟请求处理）**：
   * 处理 `save_requests`（含 `BUG-42` 的 BGM `SoundCmd` 推送）、`map_requests`、`return_to_title_requested`（`BUG-32`）与 `reserved_events`（`BUG-32`）；
   * 当检测到 `Sys100/Sys102/Sys52..54` 变更且离开设置界面时，自动持久化 `Save/System.sav`（`BUG-34`）。

### 7.3 跨语言 FFI 脏版本增量同步与零排序绘制管线（`wolf-gdext` + `GameView.gd`）
1. **Rust 侧统一归并排序（消除 GDScript 每帧字典构造与闭包排序）**：
   当前 `GameView.gd:364-377` 在每一帧（60Hz）都会遍历 `sprites` 与 `texts`，为每个元素重新分配一个包装字典 `{"sprite": sprite, "z": ..., "seq": ...}` 并调用 GDScript 的 `items.sort_custom(...)`。
   优化方案：在 `wolf-gdext/src/lib.rs` 的 `WolfGame::frame` 中，直接按 `(z, seq)` 在 Rust 侧完成 `tile_quads` + `picture_quads` + `choice_quads` 的稳定排序，或当画面处于静态等待（`outcome.idle && !screen_animating`）时在 `packet` 中标记 `"redraw_needed": false`，让 `GameView.gd` 直接跳过 `queue_redraw()`，将静态对话/菜单场景的 CPU 占用降至接近 0%。

### 7.4 静态字节码不变量 CI 门禁（Bytecode Invariant Lint）
在 `tools/audit_bytecode.py` 中新增两条自动化回归断言：
1. **控制流块平衡断言**：修复 `BUG-36`（将 `Opcode 176` 从循环头改为 `ContinueLoop`）后，断言全库 63,506 条指令中“无显式 Wait 或 Break 的死循环”数量从 32 处下降並稳定在预期基线，且 `implicit_closes` 降为 0。
2. **参数魔数求值覆盖率断言**：自动扫描全库所有指令中包含 `>= 1_000_000` 变量魔数的 `(opcode, arg_index)` 组合，确保 `exec.rs` 中对应的每个 `arg(cmd, idx)` 均经过 `eval_num`、`eval_str` 或 `is_string_operand` 解引用，防止任何未求值漏洞再次引入。
