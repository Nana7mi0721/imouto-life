# ASSETS.md — 素材摆放目录（wolf-cli assets）

## 目的

重构版要还原原版的每一个画面，最费时的是「每个立绘/背景/表情分层画在哪个层槽、什么坐标、
缩放多少、混合/不透明度多少」。这些信息**本来就写在 WOLF 明文脚本里**（opcode 150 的
参数与字符串），不需要逆向 exe。`wolf-cli assets` 把它一次性导出成可检索的目录，供摆放、
对拍与自动化核对使用。

## 用法

```
wolf-cli assets [--root <DIR>] [--include-maps] [--coords] [--db-defaults]
                [--format tsv|json] [--filter <TEXT>] [--out <FILE>]
```

- 默认：按文件聚合，一行一个资产，按绘制点数量降序。
- `--coords`：逐绘制点输出（每个 op150 一行），精确定位用。
- `--include-maps`：同时扫描 `MapData/*.mps` 的事件页（默认只扫 `CommonEvent.dat`）。
- `--db-defaults`：切换成**数据库层**导出（不混资产行，保证 JSON 合法），见下节「DB 默认值导出」。
- `--format tsv|json`：输出编码，默认 tsv。
- `--filter <TEXT>`：只保留路径包含该子串的资产（大小写不敏感）。
- `--event <ID>`：只保留该事件 id 内的绘制点（按 CE 场景重建绘制顺序时用）。
- `--out <FILE>`：写入文件（否则打印到 stdout；摘要行始终打到 stderr）。

示例：

```
./target/debug/wolf-cli.exe assets --root "$PWD/work/Data" --include-maps --out work/out/assets.tsv
./target/debug/wolf-cli.exe assets --root "$PWD/work/Data" --coords --filter bg_001_01 --format json
./target/debug/wolf-cli.exe assets --root "$PWD/work/Data" --event 245 --coords
```

## 输出列

聚合（默认）：

| 列 | 含义 |
|---|---|
| asset | 图片路径（相对数据根的路径，如 `cg/bg_001_01.jpg`） |
| category | 顶层目录归桶：cg / Picture / SystemFile / other |
| draw_sites | 该图被绘制的总点数 |
| distinct_placements | 去重后的摆法数（action,anchor,layer,opacity,x,y,scale,blend） |
| scopes | 出现的事件集合，形如 `CE:245`、`SampleMapA:0` |
| first_placement | 首次出现的一处摆法，逗号分隔 |

逐点（`--coords`）：

| 列 | 含义 |
|---|---|
| asset / category | 同上 |
| scope / event / slot | 来源（CE 或地图名）、事件 id、命令槽序号 |
| action | Draw / Move / Erase / Hide / Set（head 低 4 位） |
| anchor | 锚点（topleft / centre / 0x2000..0x6000） |
| layer | 图片层槽号（`number`，arg1） |
| opacity / x / y / scale / blend | 长形式参数：不透明度(0..255)、坐标、缩放百分比、混合模式 |

## 字段解码依据

op150 参数布局：arg0 = head（`kind=(head>>4)&7`、`anchor=(head>>12)&7`、`action=head&0x0F`），
arg1 = 图片层槽号，长形式值为 `[flag, win_w, win_h, 1, opacity, x, y, scale%, blend, ...]`。
与 `crates/wolf-vm/src/exec.rs`（decode_picture）和 `crates/wolf-game/src/picture.rs` 的字段表一致。

## DB 默认值导出（`--db-defaults`）

`--db-defaults` 不去枚举绘制点，而是导出**引擎从数据里读取的数据库层**——即此前「边界」里
列为数据可得的三块内容。输出同样支持 `--format tsv|json` 与 `--out`，且与资产行**互斥**
（单独成一份 JSON，避免两种记录混进同一文件）。

JSON 结构：

| 键 | 含义 |
|---|---|
| `screen` | 画面尺寸 `{w,h}`，取自 Game.dat；缺省 1024×576 |
| `coordinate_scale` | 坐标步进 `{x,y}` = (`w/32`, `h/24`)（crates/wolf-game/src/db.rs） |
| `window_skin` | 默认窗口皮肤文件，当前为 `SystemFile/WindowBase.png` |
| `message_window` | 由 CE63 的布局规则从 scale 推导的消息窗矩形 `{x,y,w,h}`：`x=2*sx`、`w=sw-2*sx`、`h=7*sy`、`y=sh-h` |
| `tables` | 三套数据库的表清单：`container`(Sys/Data/CData)/`type`/`type_name`/`rows`/`fields` |
| `cells` | 每格取值：`container`/`type`/`row`/`row_name`/`col`/`field`/`value` |

- Sys 侧**全部**单元格都会导出；名称型表（`文字列変数名`/`システム変数名`/`通常変数名` 等
  `fields=0`）的标签存在行名里，此时输出一条 `field="name"`、`value=行名` 的单元格，
  于是「每个槽位叫什么」也能查。
- Data/CData 是可变游戏数据、体量大，**默认只导出表清单**；传 `--filter` 时才对命中的表展开单元格。
- `--filter` 按表名（编辑器标签）或类型索引的子串匹配。
- 当前快照：**98 张表 / 1381 个单元格**。Sys 6（システム変数名）直接给出消息窗/选择窗坐标、
  姿势游标、基础字号、消息速度等引擎变量的槽位名，可作为对齐原版的客观依据。

示例：

```
./target/debug/wolf-cli.exe assets --db-defaults --format json --out work/out/db.json
./target/debug/wolf-cli.exe assets --db-defaults --filter 6      # 只列类型 6 及其单元格
```

## 覆盖与边界

- 覆盖：`CommonEvent.dat` 350 公共事件里所有 op150 文件绘制；`--include-maps` 再并入 8 张地图事件。
- DB 默认值已由 `--db-defaults` 导出（见上节）；不再属于「不含」。
- 不含：地图 tile 层（占位示例 chip，见 HANDOFF 闪烁修复）、以及一切**引擎几何**
  （九宫格窗口布局、文本度量、choice 越界回退、1/10 UI 缩放、淡入/过渡、present/swapchain）。
  这些在代码里，不在数据里。
- kind 1/4 是字符串变量引用（目标文件运行时才知），无法静态定位，故跳过；kind 2 是文本绘制。
- 数值随 `work/Data` 版本变化，以下为当前数据的一次快照：CE 侧 561 资产 / 2162 绘制点；
  并入 8 张地图后 660 资产 / 2431 绘制点。

## 与实机截图对拍

`prt sc/` 是原版（zh-CN 2.03）实机截图。拿到某场景截图后，可用 `--filter` 查该场景用到的
背景/立绘，再用 `--coords` 核对层槽与坐标，作为渲染是否对齐的客观依据。
