# M4 设置界面（CE132 / CE95）排版修复

> **当前状态（2026-11-13）**：本文记录的是 2026-11-02 的 tenths UI 修复方案。
> 后续工作区已删除 `Screen::ui_scale_for`、`TENTHS_UI`/`tenths_block` 及渲染
> 二次 `/10` 补偿；下面的缩放细节仅作历史实现证据。当前文本样式由
> `Game::uses_regular_ui_text` 的 `12xxx` 范围选择 regular 字重/基线，`290`
> 位移仍由 `Picture::effect_offset()` 参与布局。

设置界面不是独立写死的 UI，而是 WOLF 事件数据驱动的窗口：公共事件 **CE132
「X┗[移]システム欄実行」** 准备参数后调用 **CE95「X[移]システム画面描画」**，
CE95 用两个窗口图元（主面板 + 底部说明条）、九行文本图元和若干 `290` 座标
平移画完整屏。本次修复让它从「一张几乎不可读的灰屏」变成可读的九行设置面板，
并补了 2 条永久布局测试。

## 数据里的坐标模型

- CE95 pc38..42 先把面板写成字符格单位：`self22=90, self23=11, self24=180,
  self25=195`。
- pc72..75 乘字符格宽高：`self22*=32, self23*=24, self24*=32, self25*=24`。
- pc76 只把左边缘 `self22` 除以 10，所以实测面板图元是
  `x=288, y=264, w=5760, h=4680` —— 宽高仍是 10 倍，左边缘已回到像素。
- 九行标签 12030..12039 全部画在同一个基点 `(288,264)`，靠每行一条
  `290 type2` 平移分开；平移值同样是字符格单位的 10 倍（552/912/.../3720）。
- 底部说明条 12003 是 `5760x720` 的窗口；说明文字 12004 最后由 head
  `0x411f20` 重画成 `x=y=0`，并依赖此前 `290` 留下的 shift
  `(2880,5040)` 才会落进说明条中心。

历史 tenths 方案中，这个界面块必须把 **基点、290 平移、窗口宽高一起除以 10**；
单独缩放其中一项都会让文字互相重叠或飞出屏幕。该全局缩放当前已撤销。

## 四个根因与修复

1. **\f[0] 被当成 1px 字号**（`crates/wolf-game/src/textpic.rs`）
   - CE132 的 23 条文本全部以 `\f[0]` 开头。旧 `set_font_px` 把 0 clamp 到
     `MIN_FONT_PX=1.0`，整屏按 1px 绘制，肉眼几乎不可见。
   - 现在 `px > 0` 才作为字面字号；非正数使用 `ctx.default_font_px`。

2. **文本图元忽略 `290` 位移**（`crates/wolf-game/src/game.rs`）
   - `Game::text_quads` 原来直接用 `picture.x/picture.y` 排版，所有行叠在
     第一行。
   - 现在取 `picture.effect_offset()`（`crates/wolf-game/src/picture.rs`
     改为 `pub(crate)`），把 `(dx,dy)` 加到基点后再排版。

3. **UI 块的 1/10 坐标没有统一缩放（历史实现；当前已撤销）**
   - 当时新增 `Screen::ui_scale_for(number) -> f32`：同一百位图元块里，只要有
     非内置窗口的宽 **或** 高超过逻辑屏两倍，就判定整块是 1/10 字符格 UI，
     返回 10.0；内置 system graphic（全屏渐变）豁免，保持真实 1024x576。
   - 缩放应用于：文本 quad、普通 sprite 的 destination、`Atlas::sprites`
     的窗口九宫格、`Game::text_quads` 的 `(x+dx, y+dy)`。
   - 判定用 **或** 而不是 **与**：CE264 的消息窗口块是 `10240x720`，宽超
     两倍屏但高只有 720；只按「与」会漏判，使其文本 shift 以原值加到基点上
     飞出屏幕（`m3_visual_text` 从 5 个 text quad 掉到 1 个）。修正后为 7 个
     quad（12010 一行；12014/12018 各三段），与真实分栏一致。

4. **无 window 的窗口图元被整体跳过**（`crates/wolf-game/src/picture.rs`）
   - 光标图 `SystemFile/CursorBase.png` 是 window kind 但 `window=None`
     （18x18 原尺寸）。旧分支对所有 window kind 直接 `continue`，光标从未绘制。
   - 现在只有 `window.is_some()` 的窗口才交给面板绘制，其余按普通 sprite 画。

5. **head bit `0x400000`：保留当前 `290` 位移**（`crates/wolf-vm/src/exec.rs`
   + `crates/wolf-game/src/picture.rs`）
   - 全数据 5,433 条 `150` 中 188 条带该位；CE95 的说明文字依赖它。
   - `PictureCmd` 新增 `pub keep_shift: bool`，`decode_picture` 读
     `head & 0x0040_0000`；`Screen::apply` 的 Draw/Set 新建图元前先取旧
     `picture.shift`，若 `keep_shift` 则写回新图元。

## 验证

- 新增 `crates/wolf-game/tests/m4_settings_ui.rs`（2 条）：
  - `every_settings_row_is_laid_out_at_its_own_shifted_position`：九行标签都在，
    行 y 至少 5 个不同值，所有文本 rect 在 1024x576 内；
  - `the_help_text_keeps_the_shift_that_places_it_in_the_bottom_box`：含「技能」
    的说明文字落在 y>=470 的底部说明条内。
- `crates/wolf-game/tests/m3_visual_text.rs`：CE264 文本 quad 期望从 5 改为 7，
  这是应用 `290` 位移后的正确分栏；其余 6 条不变。
- 全量：`cargo fmt --all`；`cargo test -q --workspace` exit 0；
  `WOLF_DATA_ROOT=work/Data ./target/debug/wolf-cli.exe verify`
  **PASS 64 / 1 SKIP(dxarchive.header)**。
- 截图：
  `./target/debug/wolf-cli.exe --root work/Data capture --event 132 --frames 180
  --out work/out/shots/settings_final2.png`
  → 50 pictures、32 textured quads、25 text pictures、100% 非黑。
  面板约 `x=28.8..604.8, y=26.4..494.4`，九行（キー位置保存 / キーリピート速度 /
  戦闘時 自動連打 / BGM 音量 / SE 音量 / 決定キー / キャンセル / サブキー /
  リセット + 設定完了）和底部两行说明都可读。

## 交互层（M6 已闭环）

- 九行光标可移动、帮助行随行变化、取消可退出：`m3_menu_screens` 覆盖。
- 音量行左/右即时改 Sys100/102，`Game::frame` 把新增益送进混音器：`m6_input_parity`
  用真实 CE132 操作 + 混音器回读断言。
- 改键行捕获键盘原始码（扫描码+100）写入 Sys52..54，`play` 的按键映射直接读
  `live_settings()`，改键立即生效：`m6_input_parity` 覆盖。详见
  [M6_INPUT.md](M6_INPUT.md)。
- 仍缺实机截图逐像素核对光标高亮；本机无法自动比对原版画面。

## 还剩下的

- 没有实机参考截图，光标高亮的像素级样式未核对；布局与交互链路由数据测试锁定。
- **play 读档顺序**：`crates/wolf-cli/src/play.rs` 的 `Entry::Save` 现在也先
  `prime_engine()` 再 `load_save`，与 capture 路径一致；`m4_hud_status` 覆盖
  同一核心路径。
- **字体**：`find_font` 已接受 `.ttc`，`system_ttc_is_accepted_by_the_text_stack`
  已存在；截图实际用的是系统字体回退，字形与日文原版不同，只做布局对照。
