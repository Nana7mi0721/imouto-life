# ASSETS.md — 素材摆放目录（wolf-cli assets）

## 目的

重构版要还原原版的每一个画面，最费时的是「每个立绘/背景/表情分层画在哪个层槽、什么坐标、
缩放多少、混合/不透明度多少」。这些信息**本来就写在 WOLF 明文脚本里**（opcode 150 的
参数与字符串），不需要逆向 exe。`wolf-cli assets` 把它一次性导出成可检索的目录，供摆放、
对拍与自动化核对使用。

## 用法

```
wolf-cli assets [--root <DIR>] [--include-maps] [--coords] [--format tsv|json]
                [--filter <TEXT>] [--out <FILE>]
```

- 默认：按文件聚合，一行一个资产，按绘制点数量降序。
- `--coords`：逐绘制点输出（每个 op150 一行），精确定位用。
- `--include-maps`：同时扫描 `MapData/*.mps` 的事件页（默认只扫 `CommonEvent.dat`）。
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

## 覆盖与边界

- 覆盖：`CommonEvent.dat` 350 公共事件里所有 op150 文件绘制；`--include-maps` 再并入 8 张地图事件。
- 不含：DB 默认值、地图 tile 层（占位示例 chip，见 HANDOFF 闪烁修复）、以及一切**引擎几何**
  （九宫格窗口布局、文本度量、choice 越界回退、1/10 UI 缩放、淡入/过渡、present/swapchain）。
  这些在代码里，不在数据里。
- kind 1/4 是字符串变量引用（目标文件运行时才知），无法静态定位，故跳过；kind 2 是文本绘制。
- 数值随 `work/Data` 版本变化，以下为当前数据的一次快照：CE 侧 561 资产 / 2162 绘制点；
  并入 8 张地图后 660 资产 / 2431 绘制点。

## 与实机截图对拍

`prt sc/` 是原版（zh-CN 2.03）实机截图。拿到某场景截图后，可用 `--filter` 查该场景用到的
背景/立绘，再用 `--coords` 核对层槽与坐标，作为渲染是否对齐的客观依据。
