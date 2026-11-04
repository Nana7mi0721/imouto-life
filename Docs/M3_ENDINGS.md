# M3 结局（ENDING）条件与事件链

本文记录《妹！生活 ～単色～》结局相关变量、写入者、触发条件、演出事件与可见结果，
以及对应用例。所有结论来自本作 `work/Data` 的静态命令流扫描与 headless 运行时实测，
**不照抄姊妹作**；未实测到的路径明确标注为静态/不可达，禁止伪造。

## 1. 结论速览

| 变量 | docs/HANDOFF_M0.md:129 语义 | 写入者 | 读取者/用途 | 可见结果 |
| --- | --- | --- | --- | --- |
| v99 | 経過日数（同居天数，HUD「同居 N 天」） | CE251 / CE258 等日常流程 | CE258 100 日分支 | 达到 100 日触发 100 日结局文本/选项 |
| v199 | クリア（通关） | CommonEvent 内无写入者 | CE42 标题画面 pc13 分支 | 标题背景二选一：v199=0 画 `SystemFile/TitleGraphic2.png`；v199=1 画 `Picture/title2.jpg`（实测极性见 §3） |
| v200 | 妊娠エンド | 仅 CE258（写 1） | CE303 相册门 | 解锁 `Picture/album_011.png` |
| v201 | 100 日到達 | 仅 CE258（写 1） | CE303 相册门 | 解锁 `Picture/album_013.png`；100 日结局提交标记 |
| v202 | パンツコンプリート | 仅 CE258（写 1） | CE303 相册门 | 解锁 `Picture/album_012.png`；内裤收集 Grand End 提交标记 |
| v203 | エンディング（结局已达成） | 仅 CE258（写 1） | CE303 相册门 | 解锁 `Picture/album_014.png` |
| v197 | 内裤收集进度 | 日常流程 | CE258 内裤结局门（v197>=15） | 配合 v202 进入内裤收集结局 |
| v12 | 结局/路线相关条件 | 日常流程 | CE258 怀孕结局门（v12==1） | 与 v20>=100 一起作为怀孕路线前置 |
| v20 | 妹信頼度（trust） | 日常流程 | CE258 怀孕结局门（v20>=100） | 同上 |
| v248 | クレジット中 | CE302 开头置 1、结束置 0 | CE302 自身 | 使用中标记 |
| v238 | アルバム表示中 | CE303 pc0 置 1 | CE303 自身 | 相册界面使用中标记 |

结论：**v200/v201/v202/v203 的唯一写入者是 CE258「晩ごはん処理」**；
CE297「スタッフロール」只被 CE258 的三个结局分支调用；CE302「クレジット」由
CE301 pc379 与 CE303 pc712 调用；CE303 在 CommonEvent 内没有调用者，应由地图/标题触发。

## 2. 事件剧本

### CE258「晩ごはん処理」（1726 命令槽）

包含三条可证实结局分支与一条 BADEND 文本：

| 结局 | 条件/入口（命令流证据） | 演出与提交 |
| --- | --- | --- |
| 内裤收集 Grand End | 存在 v197>=15 与 v202==1 条件；其后写 v202=1、v203=1，并调用 CE297 | 画 `cg/ending03.jpg`、`cg/ending03_2.jpg`、`cg/credit02.png`；消息含 `<C>HAPPY？END`；末尾 op213 显示「グランドエンド1」 |
| 100 日结局 | v201==0 且 v99>=100；写 v201=1 | 画 `cg/ending04.jpg`；消息含「今天是我来这里的第100天」「<C>HAPPYEND ～之后也会继续妹生活～」；给出「我知道 / 不知道」选项；op213「グランドエンド2」 |
| HAPPYEND 兄妹长久（v200 路线） | 命令流中存在 v12==1 与 v20>=100 条件；写 v200=1 | 画 `cg/ending01.jpg`；消息含 `<C>HAPPYEND`；op212 スタッフロール；调用 CE297；op213「グランドエンド3」 |
| BADEND 着床 | 条件涉及 v10/v11/v12 | 文本含 `<C>BADEND ～着床～`；本作 headless 未稳定复现，仅静态记录 |

CE258 的调用者：CE256 日菜单 pc187/252、CE257 归宅菜单 pc27/214/250/286/321、
CE259 休日菜单 pc20/29/38/53/160/2664。

### CE297「スタッフロール」（36 命令槽）

- 开头 BGM `Nine_Jack`，画 `cg/credit03.png`，随后 `cg/credit04..credit13` 与 `cg/credit.jpg`；
- 结尾 `cg/pauseL`，op123 等待按键；
- 无文本消息（无 op101）；独立运行会在按键处停留（旧冒烟 180 帧内不结束，2 个音效）。

### CE302「クレジット」（249 命令槽）

- 循环显示 `cg/credit03..credit`，含 op170/401/499 分支与 op123 等键；
- 开头 v248=1、结束 v248=0；被 CE301 pc379（アルバム表示）与 CE303 pc712 调用。

### CE303「アルバム画面」（905 命令槽）

- pc0 置 v238=1；按 v200/v202/v201/v203 条件分别画
  `Picture/album_011.png`、`album_012.png`、`album_013.png`、`album_014.png`；
- `album_000`、`album_008..010` 为默认显示格；pc712 调 CE302；pc245 等按键。

### CE42「オリジナルタイトル画面Ａ」（49 命令槽）

- pc13 条件读取 v199（0/1），据分支画 `SystemFile/TitleGraphic2.png` 或
  `Picture/title2.jpg`；另有 op102 标题菜单 menu1/menu2/menu3、op130 传送，与结局无直接关系。

## 3. 运行时实测结果（headless）

测试文件：`crates/wolf-game/tests/m3_endings.rs`（6 个用例，均不 pin 随机数值）。

| 用例 | 驱动 | 断言/实测 |
| --- | --- | --- |
| `title_art_switches_on_the_clear_flag` | boot 到标题菜单后设 v199=0/1，重新 `start_event(42)` | **实测极性：v199=0 -> `SystemFile/TitleGraphic2.png`；v199=1 -> `Picture/title2.jpg`**；各自 warnings=0 |
| `hundred_day_dinner_sets_the_clear_flag_and_plays_happy_end` | 读档卧室上下文（SaveData01）设 v99=100、v200..203=0，`start_event(258)` 跑 4000 帧 | v201=1；v203=0（本次 headless 在选项处停止，未提交到 grand-end）；消息含「今天是我来这里的第100天」「HAPPYEND」；选项「我知道 / 不知道」；绘制 `cg/ending04.jpg`；warnings=0 |
| `pants_complete_branch_is_wired_for_the_grand_end` | 静态解析 CE258 | 存在 v197>=15、v202==1 门；写 v202=1、v203=1；调用 CE297（op210 参数 500297）；含 `cg/ending03.jpg`、`cg/ending03_2.jpg`、`cg/credit02.png`、`cg/ending04.jpg` |
| `album_reveals_one_slot_per_ending_flag` | 全新 Game 分别置 v200/v201/v202/v203 单标记，`start_event(303)` 跑 300 帧 | 基础格 album_008..010 常驻；v200 -> album_011；v201 -> album_013；v202 -> album_012；v203 -> album_014；单标记时只解锁 1 格；warnings=0 |
| `staff_roll_runs_headless` | 读档卧室 `start_event(297)` 跑 800 帧 | warnings=0；正槽位图 >=40；绘制 `cg/credit03.png`；CE297 在 800 帧内保持运行（等按键） |
| `ending_scripts_are_statically_wired` | 静态解析 CE258/CE42/CE303 | CE258 写 v200=1 且存在 v12==1、v20>=100 门；写 v201=1；CE42 读 v199==0/1；CE303 读 v200/201/202/203 |

补充探针事实（探针已删除，仅留档）：CE303 每次运行会循环重绘，累计 pictures 计数很大，
但 `screen.iter()` 的可见文件集合稳定；CE297/CE302 运行 300 帧都只停在首张 credit03
（按键等待），音效数分别 3/3，warnings=0。

## 4. 覆盖与限制

- **已覆盖的可证实路径（>=2）**：
  1. 100 日结局（运行时）：v99>=100 + CE258 -> v201=1 + ending04 + HAPPYEND + 选项；
  2. Grand End / スタッフロール：CE297 运行时独立播放 + CE258 内裤分支的 v202/v203/CE297 调度静态钉死；
  3. 四个结局标记到相册格的 gating（运行时 v200/201/202/203 -> album_011/012/013/014）；
  4. v199 通关标记切换标题背景（运行时）。
- **未做运行时直驱的原因**：CE258 完整分支依赖晚餐当日流程、选择与大量前置变量；
  headless 从读档卧室直接置位只能稳定走到 100 日分支的选项处，无法可靠复现内裤/怀孕/
  BADEND 全部演出，因此这些路径以静态命令流断言锁定，不伪造运行时结果。
- **阈值**：本测试只验证结局触发条件与演出接线，不构造 100 日实际游玩；v199 无 CE 写入者，
  需真实游玩到达结局后由存档/地图侧写入，本作 headless 不越权伪造。
- 数据缺失时每个用例 `eprintln!("skipping: ...")` 后返回，默认 `cargo test` 保持 exit 0。

## 5. 验收

```
WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --test m3_endings
# 6 passed

WOLF_DATA_ROOT=work/NoSuchData cargo test -q -p wolf-game --test m3_endings
# 6 passed（全部 skip）
```

未修改任何 src 或旧测试文件，未提交 git。
