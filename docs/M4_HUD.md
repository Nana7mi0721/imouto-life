# M4-HUD：HUD/读档数值与负号图片保真修复

记录 2026-10-31 M4 阶段修复的四个玩家可见缺陷、根因与回归测试。所有结论来自本作
零售数据与实机截图对照，不沿用姊妹作数值。

## 1. 负号图片并不是「全屏层」

- **症状**：读档卧室截图的左下「保存」/右下「数据」图标被放大成巨大旋转的
  「データ」叠在场景中央；状态面板（Picture/status01.png，330x576，槽停靠 x=-305）
  被拉成整屏黑罩，导致 status/night capture 近乎全黑。（面板显示时由 op150
  head bit 0x10000 相对坐标从 -305 移到 x=0，见 §6。）
- **根因**：`crates/wolf-game/src/picture.rs` 的 `Screen::quads` 旧分支把编号 < 0 的
  picture 一律当 `is_screen_layer()`，强制 `dst=[0,0,1024,576]`、src 也回退全屏，
  依据的是错误的 H-PIC-1「负号图都是 1024x576」。零售 SaveData01 实测：槽 -5 是
  `Picture/icon01.png @(10,510)` 纹理 80x60、槽 -4 是 `icon05.png @(925,507)` 80x60；
  只有标题 -2 是 1024x576。负号只意味着「不随地图相机滚动」的固定屏层，不改变尺寸。
- **修复**：删除该全屏分支，所有负号图走与正号图相同的 native size/scale/anchor/
  destination 路径；模块文档改写为 fixed-screen layers，并记录 H-PIC-1 已被零售数据推翻。
- **回归**：`crates/wolf-game/tests/m4_screen_layers.rs` 2 条：HUD 图标不被放大、
  标题美术仍是全屏固定层。截图 `bedroom_fix.png` 93.7% 非黑、图标恢复正常。

## 2. GBK 名称被误判为 UTF-8（姓名乱码）

- **症状**：HUD 姓名显示「早泄 ǿ׳ 哥哥（学生）」，参考实机为「早泄 强壮 哥哥（学生）」，
  渲染器报 `font has no glyph for '׳'`。
- **根因**：`crates/wolf-format/src/bytes.rs:251 decode_wolf_str` 旧实现无条件先试
  `std::str::from_utf8`。「强壮」的 GBK 字节 `C7 BF D7 B3 20 00` 恰好是合法 UTF-8
  （U+01FF ǿ、U+05F3 ׳），于是永远走不到 CP932/GBK 分支。影响所有「GBK 字节串碰巧
  合法 UTF-8」的存档/数据字符串，不只姓名。
- **修复**：UTF-8 降为候选之一，与 CP932/GBK 一起打分：CJK +2、kana +3、Hebrew
  U+0590..U+05FF -10、U+FFFD -30；合法 UTF-8 多字节序列按长度 +3；GBK/CP932 候选
  保留原字节启发式。只有 UTF-8 得分明显不低于最佳 CP932/GBK 时才选 UTF-8。
  注意：不能给无效 UTF-8 的 CP932/GBK 候选加惩罚，否则 CE247 等正常中文会出现 U+FFFD。
- **回归**：`crates/wolf-save/tests/vardb_encoding.rs` 10 条（含 collision「强壮」、
  写回 `[C7,BF,D7,B3,0]`、非往返 UTF-8 回退）、`wolf-format --test m3_string_decode`
  3 passed/1 ignored（U+FFFD 仅 CE257 源数据坏字节）。截图姓名恢复、font warning 消失。

## 3. 读档前必须先跑完引擎初始化（CE48）

- **症状**：`capture --load-save SaveData01` 跑 120 帧后 HUD 显示「行动力0/65、精力1/0」，
  存档明明是 60/65、3/3。
- **根因**：`crates/wolf-cli/src/main.rs` `run_capture_map` 先 `load_save` 再
  `start_engine_events`。真机在标题前 CE48「基本ｼｽﾃﾑ自動初期化」早已完成；CLI 却让
  CE48 在读档后才跑，经 CE70(+999999)→CE124 把已恢复的 CData type0 row12 行动力/精力
  清成初始值。CE48 完整结束实测需要 138 帧。
- **修复**：`crates/wolf-game/src/game.rs:776 pub fn prime_engine(&mut self) -> usize`
  启动引擎协程并最多跑 600 帧，直到没有 CE48 实例，返回驱动帧数。capture
  (`main.rs:3073 let primed = game.prime_engine();`) 与 `play` 的 Entry::Save 都在
  `load_save` 之前调用它。
- **回归**：`crates/wolf-game/tests/m4_hud_status.rs` 2 条：读档后 0:12:6..9 =
  3/3/60/65，text quads 含「行动力60/65」「精力 3/3」；prime_engine 帧数在 1..600 内。

## 4. 数据库值 magic（0x4???????）与 op121 DB 写入

- **症状**：即使初始化顺序修好，HUD 精力上限仍显示 9，不是存档的 3。
- **根因**：CE242「ステータス表示」的条件/写入使用 **database value magic**：
  `1_100_000_000` = CData type0 row0 col0，cell = base + row*100 + col。
  1,100,001,206/1207/1208/1209 = CData 0:12:6/7/8/9。旧 `Magic::decode` 把
  0x4190AFB7 当 Opaque 返回原始 1.1B；于是 CE242 条件 `1.1B >= 9` 命中，pc26 将
  col7 写成 9。正确应读 CData 0:12:6=3，3>=9 false、3>=0 true，保持上限 3。
- **修复**：
  - `crates/wolf-vm/src/magic.rs:45` 新增 `DB_VALUE_BASE: i32 = 1_100_000_000`、
    `DB_VALUE_STRIDE=100`，`MagicKind::DbCell`；`Magic::decode` 在通用 flag 前识别
    `[BASE, BASE+1_000_000)`，`db_row()/db_column()` 拆行列。
  - `crates/wolf-vm/src/exec.rs` Host trait 新增 `database_cell` / `set_database_cell`
    默认实现；新增 `database_value` / `eval_num_host`；op111 条件用 host 求左右值；
    op121 目标为 `DB_VALUE_BASE` 且 argc>=7 时按 `[base,value,bin,bits,type,row,col]`
    读写 DB cell（compound 位保留）。
  - `crates/wolf-game/src/game.rs:1883/1901` 实现 Host：读 `databases.engine_num`
    优先、回落静态 CDataBase；写 `databases.set_num` 并计 database_writes。
- **回归**：`m4_hud_status`；`magic.rs` 单测 `database_cells_decode_by_row_and_column`；
  `m3_hud_layout`、`m3_hud_numeric` 旧期望 9 已改为 3。

## 5. 验收结果（本块）

```
WOLF_DATA_ROOT=work/Data cargo test -q --workspace     # exit 0
WOLF_DATA_ROOT=work/Data ./target/debug/wolf-cli.exe verify
# PASS — 64 check(s) matched baseline, 1 pending
./target/debug/wolf-cli.exe verify --wolf "E:/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver/Data.wolf"
# PASS — 72 check(s) matched baseline, 0 pending (1,361/1,361 bytes)
```

读档截图：`work/out/shots/bedroom_hudfix.png`，1024x576、94.1% 非黑；
HUD = 19:30 周一 / 早泄 强壮 哥哥（学生） / 行动力60/65 / 精力 3/3 / 持有金钱 10000円 /
同居 1天；左下保存、右下数据小图标正常。

## 6. 尚未收口（M4 后续）

- **状态面板静态截图已收口（2026-10-31）**：`capture --map SampleMapA --load-save
  work/Data/Save/SaveData01.sav --event 10 --var 15=99 --pointer 100,200 --frames 60
  --out work/out/shots/status_panel8.png` 得到房间+HUD+左侧状态面板。
  根因不是渲染：CE238 的显示分支用 op150 **head bit 0x10000 = 相对当前图片位置**，
  隐藏时 Draw 到 x=-305，显示时 Draw/Move 都相对 +(305,0) 落到 x=0，五个文本
  (321..325) 也相对移到各标签旁。
  - `crates/wolf-vm/src/exec.rs`：`PictureCmd` 新增 `relative: bool`，`decode_picture`
    解析 `head & 0x0001_0000`。
  - `crates/wolf-game/src/picture.rs`：新增 `picture_args(cmd, base_x, base_y)`；Draw/Set
    以当前 slot 的 x/y 为基底、Move 以 `Pose::of` 的当前 x/y 为基底，相对偏移 0 表示
    +0（不走 UNCHANGED 语义），其余字段仍按原语义 merge。
  - 测试：`picture::tests` 3 条单测（相对 Draw/Move、绝对 Move 回归）+ `m3_status_panel
    ::ce238_relative_panel_lands_at_the_left_edge`（先隐藏 self600=0 再显示 self600=1，
    断言面板 x=0、文本 321 (240,90)/322 (75,405)/323 (245,410)/324 (245,465)）。
  - 该 flag 在 CommonEvent 全量中低频但关键：head 0x10000 仅 CE238/CE239 两处，
    head 0x10001 有 403 处（大量 text move）；其余 13k+ 普通 op150 不受影响。
- 夜菜单静态截图仍需合成输入/点击触发。
- 设置 UI：CE132/CE95 的可视排版已在 M4 设置屏修复中完成（详见
  `docs/M4_SETTINGS_UI.md`：1/10 字符格坐标、\f[0] 字号、290 位移、keep_shift、
  CursorBase）；音量/键位持久化 API 与通用输入路由已就绪，实机键位重绑定仍待
  用户截图后再核验。
- 字体优先 `C:/Windows/Fonts/msyhbd.ttc`：capture 实测已输出
  `font : C:/Windows/Fonts/msyhbd.ttc`，`Renderer::set_font` 接受 TTC，可标完成。
