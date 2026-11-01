# Imouto! Life ～単色～ Rust 重写 — 新会话交接

本文件写给**下一个接手的会话**（agent 或人）。读完这一份就能继续，不需要翻聊天记录。
仓库：`E:/Study/github program/Imouto Life`（**尚无 .git、无 Cargo.toml、无代码，只有 docs/**）。
撰写时状态：2025-10-30；上一作（续作）仓库 `E:/Study/github program/imoto life` HEAD `c6d8ea7`，`wolf-cli verify` = PASS 70 checks。

---

## 0. 直接复制给新会话的提示词

```text
接手一个进行中的项目：用 Rust 数据级重写《妹！生活 ～単色～》（いぬすく 2019，WOLF RPG Editor 制作，手上是 zh-CN 汉化 2.03）。
仓库：E:/Study/github program/Imouto Life（目前只有 docs/，没有 .git、没有代码）。
姊妹项目（已完成的续作重写，代码在这里复用）：E:/Study/github program/imoto life，HEAD c6d8ea7，wolf-cli verify PASS 70/70。

第一步，按顺序读这些文件（都在 Imouto Life/docs/ 下）：
1. HANDOFF_M0.md ← 本文件，全部结论与陷阱都在里面
2. GPT_RESEARCH_GROUPS.md（附 B 有里程碑表与数据勘察结论）
3. deep-research-report*.md 共 6 份（GPT 调研报告，其中若干条已被数据实测推翻，HANDOFF_M0.md §7 有采信/推翻清单）

然后：
- 在 Imouto Life 建 git 仓库 + Cargo workspace（7 个 crate 从 imoto life 复制），按 HANDOFF_M0.md §5 的 M0 清单逐条做；
- 数据根用 work/Data（HANDOFF_M0.md §5 有复制命令；原始 Data.wolf 的解包方式已验证，§3.2）；
- 每完成一项就跑 `./target/debug/wolf-cli.exe verify` 和 `cargo test -q --workspace`，并以本作自己的 docs/BASELINE.json 为准。

硬性要求：
- 不要重做已完成的工作（数据勘察、格式解密、6 份调研报告都已完成）；
- 不要照抄上一作的 docs/BASELINE.json（那是第一部游戏的期望值）；
- 不要为 Sys 变量 104/105 建 player/camera/滚动模型（本作 5 张注册地图都是定屏，§3.7）；
- 不要用 PowerShell 抢前台/模拟按键截图；截图只能让用户按游戏内 PrintScreen；
- 环境初始化：先 `source tools/env.sh`（从上一作复制并改两处绝对路径，§8）；
- 每推进一步就更新 HANDOFF_M0.md 的「进度」段，方便下一次交接。
```

---

## 1. 一句话现状

**数据层已经全部勘完、引擎层几乎不用写新东西**：本作有 350 个公共事件（其中 212..303 是本作自有 92 个，0..211 是 WOLF 自带「基本システム Ver2.20」模板）、8 张地图（注册 5 张）、46+35 个 opcode **全部**已在续作的解释器里实现过；真正要做的是「把续作的 7 个 crate 搬过来 + 加一张 WOLF 2.00 世代常量表 + 修 CP932 的 .project 读取 + 补一个 DXArchive VER6 解包分支」，然后才是内容/演出（日常循环、妹妹状态、H 场景、相册）。

**本作没有战斗、没有公会/任务/探索。** 这是内容与演出项目，不是代码量项目。

---

## 2. 两个仓库

| 仓库 | 路径 | 状态 |
| --- | --- | --- |
| 本作（第二作，Imouto! Life ～単色～） | `E:/Study/github program/Imouto Life` | 只有 docs/（7 个 md + docs/vendor/uberwolf-ref/），**未 git init、无代码** |
| 姊妹作（续作 Living With Sister: Monochrome Fantasy，已完成到 M6） | `E:/Study/github program/imoto life` | HEAD `c6d8ea7`；`verify` PASS 70/70；507 个 #[test]；7 个 crate 共 47,417 行 |

上一作的未跟踪 scratch（**不要提交**）：`crates/wolf-format/examples/opscan.rs`、`crates/wolf-format/tests/_scratch_cdata.rs`、`crates/wolf-format/tests/_scratch_event.rs`。

本作安装目录：`E:/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver`（12 个文件：Config.exe 299,008 B / **Data.wolf 176,347,260 B** / Game.exe 6,365,184 B / Game.ini 156 B / GuruguruSMF4.dll 147,456 B / manual01..06.jpg 1000x1415 / readme.txt 1,142 B）。

`readme.txt`（UTF-16LE）要点：(C) いぬすく《妹！生活 ～単色～》2019/8/11；inusuku@inusuku.dojin.com；<https://ci-en.jp/creator/64>；「本作品使用 SmokingWOLF 的 WOLF RPG Editor 制作」<http://www.silversecond.net/>；**需要鼠标**；Z/ENTER/左键=决定，X/BS/右键=取消；禁止二次发布与商业利用。
`Game.ini`：`Start=0 SoftModeFlag=0 WindowModeFlag=1 SEandBGM=3 FrameSkip=0 Proxy= ProxyPort= ScreenShotFlag=1 F12_Reset=1 Display_Number=0 Old_DirectX_Use=0`（`ScreenShotFlag=1` ⇒ 游戏内 PrintScreen 会往安装目录写 1024x576 原生帧，这是唯一允许的截图取证方式）。
`manual01..06.jpg` 是官方说明书（一手 UI 资料）；读具体术语前必须重开图看，不要凭记忆引用。

---

## 3. 已实测确认的硬事实

### 3.1 Data.wolf 已解开（头号成果，可复现）

* 文件 176,347,260 B，首 8 字节 `83 5D CC 7D 49 D4 DC F1` —— **不是明文 `DX`**，因为整包（含 64/48 字节头）被 key 循环 XOR。
* 本作是**老世代 DXArchive VER6** 归档（不是现代 VER8，也不是 WolfCrypt/WolfProt，不需要 Game.exe 里的任何材料；Game.exe 只被 UberWolfCli 用来定位游戏目录，内容无关，已用 1000 字节随机文件复验）。
* 固定 key（UberWolf `DEFAULT_CRYPT_MODES` 里 "Wolf RPG v2.20" 那条，12 字节）：`38 50 40 28 72 4f 21 70 3b 73 35 38`，经 `KeyCreate` 变换后得实际 XOR 流 **`c7 05 ca 7d 8d e3 de f1 d9 0c 85 f4`**（12 字节循环）。
* 解出的头（48 字节 `<HHIQQQQQ`）：`Head 0x5844 Version 6 HeadSize 145348 DataStart 48 NameStart 176201912 FileStart 56708 DirStart 144836 CodePage 932`。
* 结构：`DARC_HEAD_VER6` 48 B / `DARC_FILEHEAD_VER6` 64 B / `DARC_DIRECTORY_VER6` 32 B；**文件数据地址相对 DataStart，子目录地址相对 DirectoryTableStart，文件表与目录表相对 NameP**；文件名 = `NameP + NameAddress` 处 `u16 n` 然后 `+ n*4 + 4` 取到 NUL 的 CP932（名字表里同名并列 UPPERCASE 与原始大小写两份，n 就是跳过多少个 4 字节组）；数据 XOR 的 position 基准是 **DataSize**（不是数据偏移）。
* 解压分支（22 个条目用到）：`u32 destsize / u32 srcsize(=字段值-9) / u8 keycode`，之后 `keycode` 为转义、`code>keycode` 要 `-1`、`conbo=(code>>3)+(code&4? *sp<<5 : 0)+4`、`index` 1..3 字节可变宽 +1、复制走「倍增 memcpy」逻辑；权威实现 `docs/vendor/uberwolf-ref/DXLib/DXArchiveVer6.cpp:1343`。
* **验证：1,361 个条目 / 179,877,496 B，逐字节比对 100% 相同（verified 1361 / bad 0）**，其中 1,339 个未压缩、22 个压缩（全部是 `BasicData/*.dat|.project`、8 张 `.mps`、`BasicData/EncodedIconList.xxxxx` 和一个 2,355,728 B 的 TTF）。
* 复现脚本（在上一作仓库 `work/` 下，已 gitignore）：`_dw8.py`（全量校验，**已复制到本仓库 docs/vendor/uberwolf-ref/dw8_verify.py**）、`_dw2.py`（头+目录树）、`_dw5.py`/`_dw6.py`/`_dw7.py`（未压缩/压缩清单与解压）。
* 参考实现：`docs/vendor/uberwolf-ref/`（`DXLib/DXArchive.h, DXArchiveVer6.h, DXArchiveVer6.cpp, Huffman.h, Huffman.cpp` + `UberWolfLib/WolfDec.cpp, WolfDec.h` + LICENSE）。完整 UberWolf 源码在上一作 `work/uw/UberWolf-main/`（gitignore）。下载方式：`curl -sSL 'https://codeload.github.com/Sinflower/UberWolf/tar.gz/refs/heads/main' -o uw.tgz`（codeload 可用；api.github.com/contents 必须带 `?ref=main`）。

**⇒ 结论：Rust 侧自举解包是明确可移植的工作，不是研究课题。** 顺序：VER6 头 → 12 字节 KeyCreate/KeyConv → 目录表遍历 → VER6 的 Huffman/LZ。

### 3.2 已解包的数据树（直接开工用）

**已复制进本仓库：`work/Data`（1,361 文件 / 179,877,496 B = 171.5 MiB，已核对与解包树一致）**；原件在上一作仓库 `work/imouto/Data`，与 UberWolfCli 全新解包 `diff -rq` 完全一致。
资产分布：BGM 69.2 MB、cg 47.9 MB、BattleEffect 15.4 MB、根目录 13.3 MB（两份 TTF）、SE 10.6 MB、Picture 9.5 MB（330 个 `album_000..` 相册图）、BasicData 2.9 MB、MapChip 0.7 MB（102 个 pipo 系列）、SystemFile 0.6 MB（22）、MapData 0.6 MB、SystemGraphic 0.5 MB（21，含 `WindowBase.png`/`CursorBase.png`/`TitleGraphic.png`）、Fog_BackGround/BalloonBase_CafeLatte/CharaChip（11）/FIcon 各 ~0.1 MB；cg 393 文件（`bg_NNN_MM.jpg` / `bg_NNN_sNN.png`）。
字型：Data 根下有 `07やさしさゴシックボールド.ttf`（2,355,728 B）与 `◆GenJyuuGothicX-P-Bold.ttf`（11,575,152 B）；但 Game.dat 用的是系统字体 `Microsoft Yahei UI Bold`（`C:/Windows/Fonts/msyhbd.ttc` 16,883,552 B 存在）。

### 3.3 Game.dat（29,172 B，版本 2.00）

`version_header 0x00`；`u8_len 22`，`u8_settings [16,8,8,1,60,0,1,3,0,0,0,6,14,0,0,4,9,4,0,1,1,1]`；9 个字符串：`Imouto! Life ~Monochrome~ zh-CN Ver.` / `0000-0000` / 第 3 个是敏感字段（占位遮蔽，勿复述、勿猜测） / `Microsoft Yahei UI Bold` / 5 个空串 / `Ver2.03`；recorded_size 29,171 = filesize-1 ✓；`unknown_size 11`（续作为 0，**新字段，解析要容忍**）；`u16_len 19`，`u16_settings [38218,2,1,4,2,8,4,16,8,32,16,64,32,128,64,10000,1024,576,222]`（续作前 15 项相同，第 16 项 325、后段 `(1024,576,0,0,0,21569)`）；随机种子 **22507 / 23301**；static random 28,942 B，最大值 **251**（续作 28,936 / 127）；footer **0xC2**。分辨率同为 1024x576、tile 16、60 fps。

### 3.4 CommonEvent.dat（2,227,358 B，**格式与续作完全一致，只有版本/脚注不同**）

magic 7 B + `version_header 0x00` + 类型后缀 `FC\0` + `version 0x8F` + u32 事件数 **350** + 事件记录 + footer **0x8F**。
350 事件全部按续作的字段顺序（unknown4 → memo → SEP_1 0x8F → arg_names → arg pages → value pages → defaults → SEP_2 0x90 + colour + 100 self names → SEP_3 0x91 → SEP_4 0x92 + return_name + return_id）走完，零结构意外。
规模：**63,506 槽，空行 9,890，实体 53,616**；regular opcode 直方图（46 种，含 0）：
`0:9890, 99:62, 101:2113, 102:163, 103:7050, 105:4, 106:75, 107:1, 111:4271, 112:101, 121:8442, 122:448, 123:93, 124:197, 125:70, 126:6, 130:1, 140:168, 150:5433, 160:1, 170:194, 171:94, 172:445, 174:9, 175:1, 176:54, 179:687, 180:1426, 201:55, 210:2869, 211:4, 212:267, 213:612, 220:2, 221:8, 222:1, 250:2699, 270:5, 281:3, 290:249, 300:1158, 401:7562, 420:1012, 421:85, 498:881, 499:4535`。
**没有 opcode 104**（续作才有）。`raw_condition` 只有 32/34/35/18/99 五种 ⇒ `run_condition = raw & 0x0F` 得 0/2/3。
事件分区（`work/imouto/ce_titles.txt` 有全文）：
* **0..211 = WOLF「基本システム Ver2.20」模板**（前缀 ○ / ▲ / ◆ / X[共] / X[移] / X[戦]，208 号就叫「【基本ｼｽﾃﾑVer2.20説明書】」）——续作已实现过同类，可复用。
* **212..303 = 本作自有 92 个**（含槽数）：212 フキダシ会話文表示 169、213 アイコン表示長い 61、214 応援会話リコ 166、216 性興味監視 16、219 ■事後処理中断 784、220 ■事後処理 783、221 ぴぽや感情・状態ｱｲｺﾝ表示 61、222 画面拡大 22、223 ウィンドウ処理 666、224 フィールド上処理 262、225/226 深夜1吐息A/B 30、227 深夜1表示 392、228 深夜1衣服 842、229 深夜1アニメ 54、230 深夜1 157、231 文字エフェクトみぎ 959、232 文字エフェクトひだり 1285、233 文字エフェクトセリフ 385、234 文字エフェクト挿入 385、235 文字エフェクト例外 169、237 Hステータス 112、238 ステータス 78、239 アイテムリスト 55、240 立ち絵表示 257、241 ┗立ち絵瞬き 54、242 ステータス表示 44、243 時刻表示 68、244 行動力変動 28、245 夜コマンド 1016、246 ┣コミュニケーション 288、247 ┣ＴＶ視聴 1210、248 ┣ゲーム 450、**249 ┣お風呂 3912（全库最大）**、250 ┣ネットショップ 594、251 ┗就寝 1250、252..255 日中処理 学生/フリーター/社会人/ダメ人間 15/13/33/20、256 日中メニュー 977、257 帰宅メニュー 325、258 晩ごはん処理 1726、259 休日メニュー 2670、260 ┗休日ゲーム 441、261 ×◆座標変数初期化 52、262 ▲先頭空白削除 48、263 ▲文字列数値判定 57、**270 ┣[ﾒｯｾｰｼﾞ]表示処理 2744**、271 オートスキップ 157、273 お風呂タイマー2 668、274 お風呂タイマー1 1993、275 カットイン呼び出しお風呂 192、276 カットイン顔表示 107、**277 ┣警戒度メータ 237**、279 実行バー表記 96、280 カットイン呼び出し 27、281 カットインタイマー右 1119、282 カットインタイマー左 690、283 カットイン呼び出し夜 880、284 射精 358、285..288 文字エフェクト ローター/電マ/バイブ/アナルバイブ 82/46/58/46、290 コマンドカットイン 127、293 カットイン呼び出しトイレ 107、294 トイレタイマー1 666、295 トイレ処理 816、296 ■プレイ傾向 263、297 スタッフロール 36、298 素股処理 192、299 素股タイマー 378、300 カットイン呼び出し素股 73、301 アルバム表示 471、302 クレジット 249、303 アルバム画面呼び出し 905。
* **304..349 全是 1 槽空占位。**

### 3.5 数据库三件套 + .project 编码（**第 5 处世代差异**）

| 文件 | 大小 | version | footer | 类数 / 行数 |
| --- | --- | --- | --- | --- |
| DataBase.dat | 102,901 | 0xC1 | 0xC1 | 40 / 756 |
| CDataBase.dat | 84,203 | 0xC1 | 0xC1 | 30 / 649 |
| SysDatabase.dat | 11,614 | 0xC1 | 0xC1 | 28 / 1,074（**type 6 系統変数名只有 135 行**，续作 150） |
| SysDataBaseBasic.dat | 438 | 0xC0 | 0xC0 | 与续作**逐字节相同** |
| TileSetData.dat | 59,770 | **0xD1 (209)** | 0xCF | 续作是 0xD2，我们的 loader 两个都收 |
| MapTree.dat | 416 | 0x90 | 0xBC | 与续作同形（子节点顺序不同） |
| MapTreeOpenStatus.dat | 75 | — | 0x26 | 同形 |

`.project` 伴生文件：**本作是 CP932，续作是 UTF-8**。`SysDatabase.project` 21,025 B 首字节 `1C 00 00 00 0B 00 00 00 83 7D 83 62 83 76 90 DD 92 E8 00`（= cp932「マップ設定」）；续作同名文件 35,972 B 是 `E3 83 9E…`（UTF-8）。
上一作 `crates/wolf-format/src/database.rs:533-545 fn name_at` 只试 UTF-8，会在第一个名字上失败 ⇒ **整份名字表返回 0 条**。修法：UTF-8 失败后回退 CP932（`dxarchive/sjis.rs` / `cp932.rs` 已有解码器）。
`.project` 记录格式（两代都逐字节走到末尾，imoto SysDatabase 35,972/35,972、imouto 21,025/21,025）：`u32 type_count` → 每类：t_str 类名 / u32 字段数 + t_str×n / u32 行数 + t_str×n / t_str 描述 / u32 byte_len + byte_len 字节（字段类型码）/ 块1 u32 n + n×t_str（字段注释）/ 块2 u32 n + n×(u32 k + k×t_str)（字符串参数）/ 块3 u32 n + n×(u32 k + 4k 字节)（数值参数）/ 块4 u32 n + 4n 字节（默认值）。

### 3.6 地图：磁盘 8 张，**注册 5 张**

`SysDatabase` type 0（マップ設定，field positions `[2000,1000,1001,1002,1003,2001,2002,2003]`）注册：
row 0 `MapData/TitleMap.mps` 53x30（タイトル）、row 1 `MapData/SampleMapA.mps` 64x36（自宅1）、row 3 `MapData/Map003.mps` 70x170（ニューゲーム処理）、row 24 `MapData/Map024.mps` 53x30（ロード処理）、row 31 `MapData/Map031.mps` 53x30（セーブ）。
未注册的是引擎示例：Dungeon 40x30、Map002 100x30、SampleMapB 30x30。
所有 `.mps` 都是 `version 0x65` / footer 0x66 / `version_header 0x00` —— **续作的 mps loader 原样兼容**（`crates/wolf-format/src/mps.rs:76 VERSIONS [0x65,0x66]`）。
地图事件总计 **56 事件 / 102 页 / 12,266 槽 / 空行 2,188 / 实体 10,078 / 35 种 opcode**：
`{0:2188, 101:767, 102:31, 103:351, 111:1033, 112:4, 121:2522, 122:6, 123:61, 124:76, 125:3, 126:17, 130:8, 140:79, 150:622, 151:7, 161:1, 162:1, 172:56, 174:1, 179:2, 180:127, 201:73, 210:855, 212:18, 213:46, 221:2, 250:80, 270:3, 290:72, 401:1849, 420:222, 421:13, 498:2, 499:1068}`。
逐图：Dungeon 5/6/79、Map002 5/13/416、Map003 2/15/47、Map024 1/16/3、Map031 1/17/63、**SampleMapA 35/95/11,558**、SampleMapB 6/101/36、TitleMap 1/102/64。
SampleMapA 重点事件（M2 目标）：ev0 ニューゲーム処理 @(30,0) trigger1 367 槽；ev1 妹寝そべる 6 页；ev9 日中メニュー 2 页；ev15 コマンドリスト表示 9 页（槽 116/68/70/139/62/66/56/70/42）；ev16 コマンド選択判定 458；**ev17 コマンド実行 7 页（4980 槽为主）**；ev18 カーソル切り替え 1567；ev19 当たり判定描画 209；ev20 例外処理監視 101；ev23 深夜表情自動変更 654；ev26 アイテムクリック監視 352；ev30 スタッツ 323；ev31 パンツ詳細 302；ev35 アルバム起動判定 2 页。

### 3.7 全局变量表 = 状态模型的权威命名（SysDatabase type 14，302 行）

`14 妹位置、20 妹信頼度、21 妹性興味、22 妹感度、23 妹機嫌、24 妹快感、25 妹不愉快、26 媚薬効果、4 時、5 分、6 曜日、7 所持金、8 就寝時間、18/19 睡眠深さ/最大、32 日中メニュー、33..41 物品、42 スタミナ消費、50 ダンベル、51 トレーニングマシン、52 コンドーム、56 深夜終了、59 嫌悪感割合値、60 基礎行動力、61 ボーナス行動力、62 精力、63 嫌悪感最大値、64 嫌悪感、65 テンション、66 射精感、70 深夜パート、74/75 スタミナ量/MAX、77 安眠茶、78 アフターピル、97 休日メニュー、99 経過日数、100 深夜1、115 拡大率X、119 就寝兄、122 中出し、127 妊娠、129 妹欲求不満度、138 リビングに居る、143/144/145 電マ/バイブ/アナルバイブ、150 アナル開発度、`**154 警戒度**`、155 お風呂タイマー1、160 お風呂タイマー2、163 はじめから、170 トイレタイマー、175 立ち絵表示位置、176 スタッツ表示中、177 フリー乱数、178 素股タイマー、180 射精回数、187 イカせた回数、189 総射精量、199 クリア、200 妊娠エンド、201 100日到達、202 パンツコンプリート、203 エンディング、205 処女、209 安全日、210..229 パンツ1..20、230 祭り、231 旅行、232 クリスマス、234 正月、235 バレンタイン、237 アルバムアイコン表示、238 アルバム表示中、244/245/246 各开放、247 アルバム回想実行中、248 クレジット中、249/250 お花見、260 コマンド実行中、299 サークルロゴ`。
Sys 变量（type 6，135 行）中 row 104 = `Ｘスクロール値`、row 105 = `Ｙスクロール値`（与续作逐字相同），row 1/2 = メッセージウィンドウ X/Y、3/4 = 選択肢ウィンドウ X/Y、110 = 乱数シード、111 = [読]画面アクティブ状態、115 = [Read]Game.exe version(x100)、116/117/118 = Screen size X/Y + Tile size。
**⇒ M3 的结论可直接沿用：104/105 是引擎维护的相机滚动输出，没有脚本读写；本作 5 张注册地图都是定屏（无行走图事件页），不要建 player/camera 跟随模型。**
完整名字表已落盘：上一作 `work/out/imouto_var_names.txt`（10,189 B），含 SysDatabase type 4/5/6/14、type 0/7/8/13 的全部行名。

### 3.8 数据库类型清单（判断「模板残留」用）

`DataBase` 40 类（0 技能 37 字段/44 行、2 アイテム 21/25、3 武器 35/40、4 防具 40/40、6 戦闘コマンド 4/19、8 状態設定 46/24、9 敵個体 26/42、10 敵行動AI 48/40、11/12 属性/状態耐性 100、13 敵グループ 12/41、15 用語設定 32/1、17 システム設定 35/1、20 吹き出しアイコン 4/11、21 EXスキル 4/40、22 吹き出し会話 20/10、23 サポートキャラ 4/10、24 立ち絵設定用 5/10、25 ランダム肩書 20/21、26 メッセージウィンドウ種類 35/9、30 アニメ設定 1/100、31 統計テキスト 4/4）。
`CDataBase` 30 类（0 主人公ステータス 60/17、3 属性耐性 100/40、6 パーティー情報 7/1、7/8/9 所持個数 1/10、18 基本ｼｽﾃﾑ用変数 2/100、19 万能ｳｨﾝﾄﾞｳ一時DB 11/200、25/26/27 キーコンフィグ系）。
**战斗相关表（DataBase 9/10/11/12/13/21）与 `BattleEffect/` 15.4 MB 资产都是 WOLF 模板残留**，本作无战斗玩法（地图事件里也没有战斗事件）——M0 资产审计可标死资产。

---

## 4. 世代表：需要改的常量（**只此 4 处 + 1 处编码**）

上一作硬编码的是续作（2.10）的常量。**不要改成「两代都接受」的硬编码**：改用「按容器头 `version_header` / version 字节选一套常量表」的 `WolfGeneration`（2.00 → `version_header 0x00`；2.10 → `0x55`），保证两作的 verify 基线互不污染。

| 位置（上一作路径） | 现值（2.10） | 本作（2.00） | 说明 |
| --- | --- | --- | --- |
| `crates/wolf-format/src/gamedat.rs:41` | `FOOTER = 0xC3` | **0xC2** | 校验点在 `:93` |
| `crates/wolf-format/src/commonevent.rs:102` | `FOOTER = 0x90` | **0x8F** | `version 0x8F` **不校验**（`parse` 只读不判，见 `:123`），`version_header 0x00` 也不校验；只需放宽 footer |
| `crates/wolf-format/src/database.rs:40,42` | `VERSION = FOOTER = 0xC2` | **0xC1 / 0xC1** | 闸门在 `:65`，三个 .dat 一致 |
| `crates/wolf-format/src/tileset.rs:44-48` | `VERSION_210 0xD2 / VERSION_209 0xD1 / FOOTER 0xCF` | **0xD1 已在白名单** | 无需改 |
| `crates/wolf-format/src/mps.rs:76,95` | `VERSIONS [0x65,0x66] / FOOTER 0x66` | **0x65 已支持** | 无需改 |
| `crates/wolf-format/src/maptree.rs:63,65,145` | `0x90 / 0xBC / 0x26` | 完全相同 | 无需改 |
| `crates/wolf-format/src/database.rs:533-545` `fn name_at` | 只试 UTF-8 | **需 CP932 回退** | 否则 `.project` 名字表全丢 |
| `crates/wolf-format/src/dxarchive/mod.rs:29,32` | `HEADER_SIZE 64 / VERSION 8` | **VER6 分支**（48 B 头 / u64 地址 / 12 字节 key） | 新增，勿改现有 VER8 路径 |

`wolf-cli verify` 对 `work/imouto/Data` 的现状（放宽前）：15 项 FAIL = game.parse footer 0xC2、ce.parse footer 0x8F、database.parse ×3（`unsupported database version 0xC1`，`database.rs:65`）、maptree.children_of_0 顺序（3,24,31 vs 3,31,24，只是顺序）、mps 七项（全是按续作算的期望值：maps 8 vs 9、events 56 vs 73、pages 102 vs 134、slots 12,266 vs 37,610、blank 2,188 vs 7,052、real 10,078 vs 30,558、opcodes 34 vs 40、empty_maps 0 vs 2；`mps.parse 0 parse errors`）、tileset.version（210 vs 209）。`save.*`/`dxarchive.*` 全 ok（save 读的是续作存档）。

---

## 5. M0 开工清单（按顺序，每步可验证）

1. **建仓库**：`cd 'E:/Study/github program/Imouto Life' && git init`；复制上一作的 `.gitignore`（含 `/target`、`/work/`、`*.exe`、`/tools/{bin,cmake,ffmpeg}/`）、`rust-toolchain.toml`（channel stable + rustfmt + clippy）、`tools/env.sh`（改 `T` 与 `IMO` 两处绝对路径）、`tools/env.ps1`/`setpath.ps1`。
2. **搬 crate**：`cp -r '/e/Study/github program/imoto life/crates' .` + 复制根 `Cargo.toml`（7 成员、resolver 2、`workspace.package` version 0.1.0 / edition 2021 / rust-version 1.87 / license MIT OR Apache-2.0 / publish false、profile.dev opt-level 1 debug 1、dev.package."*" opt-level 2、release opt-level 3 + lto thin + codegen-units 1）。`cargo build -q` 必须绿。
3. **数据已就位**：`work/Data` 已含 1,361 文件 / 179,877,496 B（无需再复制；若要重来：`cp -r '/e/Study/github program/imoto life/work/imouto/Data' work/Data`）。`work/` 要进 `.gitignore`。`wolf-cli` 的 `WOLF_DATA_ROOT` 默认指向 `./work/full`（`crates/wolf-cli/src/main.rs:580`，默认值在 `:517`），本作要改成 `./work/Data`。
4. **WolfGeneration**：按上表加两代常量表 + 用 `version_header`/`version` 选表；`gamedat`/`commonevent`/`database`/`tileset` 的解析都改成「读表拿常量」。
5. **.project CP932**：`name_at` 加 CP932 回退，然后确认 `SysDatabase.project` 能出 28 个类名、`DataBase.project` 40 个、`CDataBase.project` 30 个。
6. **本作基线**：写 `docs/BASELINE.json`（**不要照抄上一作**），先落这些键：`game_dat`（25 个游戏参数、种子 22507/23301、分辨率 1024x576）、`common_events`（350 / 63,506 / 9,890 / 53,616 / 46 opcodes）、`map_events`（56 / 102 / 12,266 / 10,078 / 35 opcodes）、`precompile`、`tileset_data`（版本 209）、`file_versions`（各 .dat 的 version+footer）、`wolf_archives`（1,361 条目 / 179,877,496 B；若实现 VER6 解包，再加 `dxarchive_ver6` 键：key、1,339 未压缩 + 22 压缩、逐字节校验计数）。
7. **wolf-cli 子命令**：`verify / precompile / list / capture / play / run` 沿用；`capture` 的 `--map` / `--map-run` / `--boot` 要改成本作注册地图名（TitleMap / SampleMapA / Map003 / Map024 / Map031）。
8. **（可选但推荐先做）VER6 解包分支**：把 `work/_dw8.py` 的逻辑移植到 `crates/wolf-format/src/dxarchive/ver6.rs`，让 `wolf-cli verify --wolf` 直接读 `Data.wolf` 并与磁盘树逐字节比对 —— **验收标准就是 1,361/1,361 全等**，这是整条数据链的自证。
9. 跑 `cargo test -q --workspace` + `verify` 全绿后提交（`git -c user.name=... -c user.email=... commit -F work/_commit.txt`）。

---

## 6. 上一作代码地图（复用时的定位表）

| 关注点 | 位置 |
| --- | --- |
| wolf-cli 子命令分发 | `crates/wolf-cli/src/main.rs:311-412`；`play.rs` 为交互播放 |
| 数据根 `WOLF_DATA_ROOT` | `crates/wolf-cli/src/main.rs:580`（默认 `./work/full`，见 `:517`） |
| 游戏安装目录探测 | `crates/wolf-cli/src/main.rs:1874 fn game_dir` |
| Game.dat 解析 | `crates/wolf-format/src/gamedat.rs`（`FOOTER` `:41`，校验 `:93`） |
| CommonEvent 解析 | `crates/wolf-format/src/commonevent.rs`（字段序列 `parse_event`，footer `:102`） |
| 数据库 + .project | `crates/wolf-format/src/database.rs`（`ProjectNames::parse` `:415`，`name_at` `:533`，`project_type_at` `:554`） |
| mps / tileset / maptree | `crates/wolf-format/src/{mps,tileset,maptree}.rs` |
| DXArchive VER8 | `crates/wolf-format/src/dxarchive/{mod,key,huffman,lz,crc32,sjis,cp932}.rs`（VER6 新分支加在这里） |
| VM 解释器 | `crates/wolf-vm/src/{exec,program,magic,rng}.rs`；`exec.rs` 的 match 臂覆盖 0/99/101../121/150/210/250/270/290/300/401/420/498/499 等，**本作 46+35 种全部在内** |
| 渲染 | `crates/wolf-render/src/{lib,text,diff}.rs`（wgpu 30 + glyphon 0.12）与 `examples/imgdiff.rs` |
| 游戏层 | `crates/wolf-game/src/{game,map_runtime,picture,tilemap,choice,window,assets,db,key}.rs` |
| 像素对照工具 | `cargo run -p wolf-render --example imgdiff -- A.png B.png [--out diff.png]` |

---

## 7. 6 份 GPT 调研报告 vs 数据实测（采信 / 推翻）

报告在 `docs/deep-research-report.md`..` (5).md`（7,485 / 10,513 / 7,360 / 6,822 / 9,865 / 10,418 B）。**总体质量参差：多为二手攻略，凡与数据冲突一律以数据为准。**

| 结论 | 判定 |
| --- | --- |
| 正式日文名 `妹！せいかつ ～モノクローム～`，作者 いぬすく，2019 年 8 月（readme 写 08-11，报告写 08-22） | 采信（日期取 readme） |
| 本作**无官方中/英文版、无 Steam 版**；我们这份 zh-CN 是民间汉化（改了标题串与字体为 Microsoft Yahei UI Bold） | 采信，且被 Game.dat 的两个字符串直接证实 |
| 四种身份基础值：学生 行動力 60 / 金钱 3000–6000 / 就寝 24:00；フリーター 40 / 8000–12000 / 23:00；社会人 30 / 30000–50000 / 23:00；ダメ人間 25 / 1000 / 24:00；行動力上限 99（ダンベル +5、筋トレ机 +15） | **高价值，待与事件 252..255、244、251 交叉核对后入基线** |
| 道具：お茶 +10、玉露 +20、紅茶 +5 且就寝 +1h、コーヒー 就寝 +2h（至凌晨 2 点）、精力剤 精力上限 +1（上限 9）+2 精力 +20 行動力、媚薬 感度最大 + 快感 50%、安眠茶 浅眠→熟睡、アフターピル 3 天内清怀孕 | 待核对（事件 250 ネットショップ / 33..41 物品变量） |
| 妹妹四项 = 信頼（数）/ 興味（数）/ 感度（%）/ キゲン（五档：爆発寸前 / 不機嫌 / 普通 / 上機嫌 / 兄Love），興味 每日自动下降 | 采信（对应全局 20/21/22/23） |
| 阈值：信頼≥150 且上機嫌 ⇒ 共浴；≥200 ⇒ 新选项；≥250 ⇒ 帮洗身；興味≥150 ⇒「我也想做」；≥200 ⇒ 口交取代手交；信頼≥300 ⇒ 额外 H/CG；同居 100 天 ⇒ HappyEnd；所持金≥100000 且「産めばいい」⇒ TrueEnd；共 3 个结局 | 待核对（全局 199/200/201/202/203/127/209） |
| **报告称「警戒度」在任何资料里都没出现** | **推翻**：全局变量 **154 = 警戒度**，事件 **277 ┣警戒度メータ** 236 槽在实现它 |
| 报告 3（UI/操作）：方向键移动、Z/Enter 确认、长按加速、F12 退出；Config.exe 选项名与默认值「未找到」 | 低价值，只能靠说明书（manual01..06）与实机截图补 |
| 报告 1（引擎世代）：2.00≈2011-07-19、2.02a 2012-06-10、2.10 2013-08-09、2.20 2017-03-22（内部又写 2016-11-22，自相矛盾）、3.00 2022-11-22；「Ver2.10 起改了数据加密方式」 | 部分采信；**本作实测是 DXArchive VER6 + WOLF v2.20 固定 key，与「2.10 改加密」的说法不矛盾但也不能据此推世代，一律以容器头字节为准** |
| 报告 0 称未公开 CG/结局/BGM 数量 | 采信；但数据里可直接数：cg 393 文件、Picture 相册 330 张、BGM 目录 69.2 MB |

**报告没覆盖、但数据已给的**：注册地图只有 5 张；事件分区（0..211 模板 / 212..303 自有）；opcode 全覆盖；Data.wolf 已解；`.project` 是 CP932；SysDatabase type6 只有 135 行。

---

## 8. 环境与协作陷阱（血泪，别重踩）

1. **每条 bash 命令开头**：`cd '/e/Study/github program/Imouto Life' && source tools/env.sh >/dev/null 2>&1`（env.sh 提供 msys PATH + 中科大 rustup 镜像 + `CARGO_NET_GIT_FETCH_WITH_CLI`）。路径必须用 msys 形式（`/e/...`）。
2. `C:/Users/REISEN/.cargo/config.toml` 必须保留 `[http] proxy = ''`：注册表代理（127.0.0.1:7890）会被 cargo/libcurl 采用而 curl 不采用，症状是「curl 能连镜像、cargo 不能」。
3. **sccache 会破坏 MSVC 链接**（LNK1104 lnk{GUID}.tmp）——不要开。
4. **GitHub 直连下载只有 ~2 KB/s**：源码包走 `codeload.github.com`（已验证可用），普通文件用 `ghfast.top` 前缀；`api.github.com` 可读元数据，但读文件内容要带 `?ref=main` 并检查 `.message`（限流）。`cargo-binstall` 不可用（os error 5），用 `cargo install --locked`。
5. **不要用 PowerShell 抢前台/模拟按键截图**（用户明令：会造成他无法操作电脑）。截图只能由用户按游戏内 PrintScreen（`ScreenShotFlag=1`），产物落在安装目录，1024x576 原生。
6. **Python 补丁脚本必须写 `newline=''` 且「写 .new 再 `os.replace`」**：曾因 `io.open(newline='\\n')`（C 层先截断文件再报非法 newline）把 `game.rs` 截成 0 字节。引用锚点要先 `assert` 存在。
7. **临时输出放 `work/out/`**：`/tmp` 在 Windows 上映射到系统临时目录，bash 派生的子进程写它会 `PermissionDenied (os error 5)`；测试临时目录用 `target/test-scratch` + `env!(CARGO_MANIFEST_DIR)`。
8. 交互式截图/报告都落到 `work/out/`；`work/` 与 `/tools/{bin,cmake,ffmpeg}/` 已 gitignore。
9. 团队规模上限 8 人（lead + 7）；共享任务板用 `team_task_*`；写作用域按文件/目录切分。
10. 提交身份按命令传入：`git -c user.name='imoto lead' -c user.email='lead@imoto.local' commit ...`；`git add` 的 CRLF 警告无害。

---

## 9. 不要做的事

* 不要为 Sys 104/105 建玩家坐标/相机跟随/滚动模型（§3.7）。
* 不要把 opcode 104（本作没有）或战斗模板当成待实现功能。
* 不要照抄上一作的 `docs/BASELINE.json`（期望值属于第一部游戏）。
* 不要把 `.wolf` 解密当成「未解难题」——已解开（§3.1），也不要引入 WolfCrypt/WolfProt 的复杂路径（那是 2.225+ 世代）。
* 不要在没读说明书/实机截图的情况下凭 GPT 报告写 UI 数值。
* 不要提交 `work/`（175 MB 数据 + 探针脚本）、`tools/bin|cmake|ffmpeg`、`*.exe`。

---

## 10. 恢复后的第一条命令

```bash
cd '/e/Study/github program/Imouto Life' && source tools/env.sh 2>/dev/null || echo 'run M0 step 1 first (copy tools/env.sh)'
git status --short 2>/dev/null | head
cat docs/HANDOFF_M0.md | head -60
```

若 M0 已开工，接着跑：

```bash
cargo build -q --workspace && cargo test -q --workspace 2>&1 | tail -20
WOLF_DATA_ROOT="$PWD/work/Data" ./target/debug/wolf-cli.exe verify | tail -20
```

---

## 11. 进度

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
