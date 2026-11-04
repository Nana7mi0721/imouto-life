# 参考资料索引（REFERENCE）

本文件登记重写本作时可用的一手/二手资料。所有路径均为仓库内相对路径或本机绝对路径。

## 1. 日文原版（一手，最高价值）

* 路径：`E:\EROGAME\限界!？お兄ちゃん 「妹!せいかつ」～モノクローム～2.03`
  * 说明：这是**日文原版**（非汉化）。原先目录名因 CP932→GBK 编码错乱变成乱码，已按用户授权还原为规范日文名；内部 12 个日文文件名也一并还原（`マニュアル01..06.jpg`、`お読みください.txt`、`更新履歴.txt`、`やさしさゴシックボールド.ttf` 等）。ASCII 文件名（`Game.exe`、`*.wolf`、`Save` 等）保持不变。
  * 结构：顶层含 `Data/`（已解包的 **17 个 .wolf 归档**：BasicData / MapData / Picture / BGM / SE / CharaChip / MapChip / SystemFile / SystemGraphic / BalloonBase_CafeLatte / BattleEffect / EnemyGraphic / FIcon / Fog_BackGround / cg 等）、`Save/`、`Game.exe`、`Config.exe`、`Game.ini`、`Game_ErrorLog.txt`、`GuruguruSMF4.dll`、两份字体、6 页官方说明书 `マニュアル01..06.jpg`、`お読みください.txt`、`更新履歴.txt`。
  * 用途：可直接对照**原始 UI 文本 / 字体 / 说明书**，免去从汉化版反推原版的一整轮猜测；说明书 6 页是一手 UI 参照。
  * 注意：本作目标对齐 **2.03**（日文原版与 zh-CN 汉化均为 2.03）。攻略站 AyauGaming 写的是 2.04，数值不能直接当 2.03 结论。

## 2. 攻略与研究链接（二手）

来源清单见 `docs/相关链接.txt`（GPT 搜集，已按证据价值排序）。最值得收藏的五份：

| 优先级 | 资料 | 用途 |
| --- | --- | --- |
| 1 | [Gamerch 攻略 Wiki](https://gamerch.com/biim/318371) | 事件流程、UI、道具、状态、结局条件 |
| 2 | [AyauGaming 数值攻略](https://ayaugaming.com/rj258445) | 行动消耗、属性成长、事件门槛（针对 2.04，慎用） |
| 3 | [Doureview 攻略/感想](https://www.doureview.com/blog-entry-236.html) | 结局、行动效果交叉核对 |
| 4 | [PTT 玩家讨论](https://www.pttweb.cc/bbs/H-GAME/M.1620109249.A.106) | 边界条件、特殊事件反例 |
| 5 | [官方作品介绍页](https://masukuinu.sakura.ne.jp/imouto/mono_01/index.html) | 作者原始描述、功能名称 |

作者一手来源：CI-en <https://ci-en.dlsite.com/creator/64>、官网 <https://inusuku.dojin.com/>、X <https://x.com/inusuku>。

**下一步建议**（来自链接整理者）：把 Gamerch / AyauGaming / Doureview 三份攻略里的每个数值抽成一张交叉验证表，同值标为高可信、异值标版本差异、单源值保留来源标签，避免把攻略作者的错误写进 Rust 引擎。

## 3. 实机截图（一手，zh-CN 2.03）

目录：`prt sc/`（10 张 PNG，用户在游戏内 PrintScreen 取得，约 1530x860）。原生帧 1024x576 的放大截图，适合对**布局**（不是字形——汉化字体为 Microsoft Yahei UI Bold）。

| 文件 | 界面 |
| --- | --- |
| `{25B8577A-18EA-4AD0-B444-AEE4B94E60FF}.png` | 存档/读档界面：4 个存档槽，显示时间、角色名与「没有数据」 |
| `{524117D7-1B43-426A-A5EA-296CDAA14359}.png` | 夜间室内行动菜单（鼠标悬停某行动项）+ 底部对话 |
| `{682883F3-53AE-4713-B72E-A57FBF314B58}.png` | 收集品 + 游玩统计面板：左侧 20 格收集槽（0/20），中间立绘，右侧统计栏 |
| `{93D46236-57BF-4D9E-927D-91C89A1D343C}.png` | 室内场景（妹妹坐姿，无菜单） |
| `{36375B54-E2C2-4164-9280-4FCEEF39D4B4}.png` | ITEM 道具栏面板（各类道具与数量） |
| `{3FAD3D6F-1F44-4F33-8D2B-89D27FB911F8}.png` | 室内场景 + 立绘 + 底部对话 |
| `{62CC63DE-2E38-4AE9-92A4-266AA58DA6C6}.png` | 街道场景（白天 17:00）+ ITEM 面板 + 购买菜单（含价格） |
| `{D6FB4E97-FE82-4FB5-8E43-1F4662735C3B}.png` | 夜间近距离互动界面（BAD/GOOD 条、若干操作按钮、参数百分比、结束按钮） |
| `{E7758F69-B529-4D08-9283-97D3B232AF6D}.png` | 回忆相册：15 个相册格，各带标题（初次、日常、购物、泳池、海、祭典、温泉、圣诞、新年、情人节、赏花、结局、100 天等） |
| `{EE3763D0-E855-4693-99A1-FEE747EE4947}.png` | 状态面板（信赖/兴致/敏感度/心情 + Q 版立绘）+ 行动菜单（交流/泡茶/泡澡/网上购物/睡觉） |

顶栏在两套界面里一致：时间 + 星期 + 姓名/身份（学生）+ 行动力 xx/65 + 精力 3/3 + 持有金钱。右下角有「数据」按钮、左下角有「保存」按钮。

## 4. 存档样本（一手）

zh-CN 安装目录 `E:\EROGAME\Imouto! Life ~Monochrome~ zh-CN Ver\Save\`：`SaveData01.sav`(293,742 B)、`System.sav`(155,615 B)。`wolf-cli verify` 的 save 段已能解析（version 0x80 / end_byte 0x19 / checksum_ok）。日文原版 `Save/` 亦有对应样本。
