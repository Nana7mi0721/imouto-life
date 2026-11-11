# Godot 前端：操作 / 显示 / 对话问题的排查手册

> 适用：`godot/` 前端 + `crates/wolf-gdext` 桥。WOLF 语义仍以
> `docs/HANDOFF_M0.md`、`docs/ENGINE_BEHAVIOR.md` 为准；本文只讲怎么定位
> “按键没反应 / 画面不对 / 对话不见了”。

## 1. 操作契约（本作实机口径）

| 输入 | 行为 |
|---|---|
| `Esc` / 鼠标右键 | 返回上一级 / 取消（CANCEL） |
| `Enter` / 鼠标左键（指针在选项上） | 点击 & 确认（OK） |
| 上下方向键 / 滚轮 | 切换选项；标题菜单同步把选中项换成深色 `menu*_a` |
| 左右方向键 | 存档/读档网格翻页；上下方向键切换存档槽 |
| 滚轮（存档/读档网格） | 翻页（等同左右方向键；不是逐槽滚动） |
| 鼠标左键（地图热点） | 触发指针下的 `trigger=0` 地图事件 |

实现位置：

- `godot/scripts/GameView.gd`：物理键跟踪、鼠标按下/松开锁存、滚轮累计、
  `set_input` / `set_wheel`。
- `godot/scripts/WolfKeys.gd`：Godot `KEY_*` → WOLF `scancode+100`，
  以及 `App::bits()` 同款的 OK/CANCEL/SUB 组合（Sys52/54/56 改键即时生效）。
- `crates/wolf-game/src/game.rs`：
  - `handle_choice_input`：op102 选择肢的上下/确认/取消、鼠标悬停、点击命中。
  - `apply_wheel`：滚轮 → 选项光标 / 存档页键 / 普通菜单上下。
  - `handle_action_key_input`：左键/OK 触发地图热点。
  - 标题高亮：CE43 是“画一次就结束”的渲染器，`frame()` 在光标变化时
    重启它，保证深色 `menu*_a` 跟着键盘/滚轮/悬停移动。

## 2. 三个已定位的根因（2026-11-10 修复）

1. **标题高亮不动**：CE43 只在启动时读一次 Sys20，之后结束；旧的 auto-event
   调度是边沿触发，不会因为 Sys20 变化重跑。现在标题光标变化时
   `AutoEvents::restart(43)` 重放一次，暗色按钮随选择移动。
2. **滚轮完全没接**：Godot 的滚轮是 `InputEventMouseButton`（WHEEL_UP/DOWN），
   不是按键。`GameView` 现在按 notch 累计，`WolfGame.set_wheel` 交给
   `Game::apply_wheel`；标题/选项直接移动光标，存档网格注入左右页键。
3. **某些场景鼠标点击丢**：旧代码在物理帧里读 `Input.is_mouse_button_pressed`
   （电平），一次按下+松开如果落在两个物理帧之间就完全丢失；同时热点命中用的是
   当前指针位置，不是按下位置。现在 `_input` 锁存一次按下到下一物理帧，并保存
   按下时的 logical 坐标。右键取消走同一条边沿。

另外两项与“显示/对话”直接相关：

- **不要给 Godot 字体挂全局 fallback**：尝试把 `seguisym.ttf` 挂到 msyhbd/msyh
  的 `fallbacks` 后，Godot 的整段文字度量被改写，600 帧新游戏像素 MAE 从
  0.368 涨到 3.11。扫描 1,218 条静态消息/选项（21,009 字）后，msyhbd 只缺
  5 个码点，且都是私用区/乱码（U+E07E、U+E4DE、U+0225、U+0377、U+FFFD）。
  结论：正常对话不缺字形，fallback 保持关闭；真遇到缺字再做“逐字形 fallback”。
- **截图必须冻结 60Hz 时钟**：`--capture` 到达目标帧后先
  `set_physics_process(false)` 再等 `frame_post_draw`，否则物理帧可能在 await
  期间多走一帧，捕获到 N+1 帧的动画相位（表现为左侧 25px 竖条差）。

## 3. 诊断开关

启动参数（`--` 之后的用户参数）：

```bash
Godot_v4.7.2-stable_win64_console.exe --path godot -- \
  --data-root='E:/.../work/Data' \
  --entry=menu --auto-new-game --frames=600 \
  --log-input --log-events --log-messages \
  --capture='E:/.../work/out/repro.png'
```

| 开关 | 输出 |
|---|---|
| `--log-input` | 每个键按下/松开、鼠标按下/松开（bit + 坐标）、滚轮 notch，以及选项列表/光标变化 |
| `--log-events` | 运行中的 common event id、`last_action_event`、diagnostics |
| `--log-messages` | 每条新消息的帧号 + 原文（保留 WOLF `\E`/`\c` 转义） |
| `--capture=... --frames=N` | 第 N 个游戏帧的 1024x576 PNG（物理时钟已冻结） |

GDExtension 额外 API（GDScript/测试可用）：

- `WolfGame.transcript()`：最近 200 条消息（`Game::message_history`）。
- `WolfGame.running_events()`：当前存活的 common event id。
- `WolfGame.set_wheel(notches)`：正数向上、负数向下。
- `WolfGame.key_config()`：Sys52..57 六个词。
- `frame()` 的 packet 新增 `last_action_event`（-1 = 还没触发过地图热点）。

## 4. 排查流程

### 4.1 操作没反应

1. 带 `--log-input` 复现。看 `input:` 行：
   - **没有按键/鼠标事件**：Godot 窗口焦点、`_input` 被 GUI 吃掉、或测试脚本没
     把事件送进树。检查窗口是否在前台、`mouse_filter`、是否用了 `--headless`
     （headless 没有真实输入）。
   - **有按下但 `choices`/`cursor` 不变**：事件到了 GameView，但游戏层没接住。
     看 `--log-events` 的 `running`：当前是否真的在等待这个菜单（例如存档网格
     是 CE131，标题是 CE42，夜晚菜单是 CE245）。
   - **`last_action=-1` 且点的是地图热点**：点击位置没命中任何 `trigger=0` 的
     事件（或当时有消息/选择肢占用了这次点击）。看 `input: mouse down ... at`
     的坐标，再用 `wolf-cli assets --coords` 或实机截图核对热点。
2. 对照 Rust：`wolf-cli play` 同场景同按键；如果 Rust 也不动，问题在
   `wolf-game` 语义而不是 Godot 桥。
3. 记住按键重复：菜单的 `123` 等待轮询吃 Sys15/16 重复；一次 tap 只按 2 帧，
   不要用长按来测试“点一下”。

### 4.2 画面不对

1. 同帧捕获：Godot `--capture` + Rust
   `wolf-cli capture --menu-only --answer 0 --frames=N`。
2. `python work/out/text_calib/diff_report.py A.png B.png [--region ...]`
   看 MAE、±8/±32、差异 bbox：
   - bbox 只在文字行 → 文字度量/字体/字号；
   - bbox 覆盖整块图片 → atlas 槽位、UV、tint/alpha、绘制顺序；
   - bbox 只在边缘条带 → 动画相位/捕获时机（确认 `--capture` 已冻结物理帧）。
3. 长程漂移用 `bash tools/parity-godot.sh`：VM 统计逐项相等、像素只看 HUD
   文字（当前 MAE ≈0.368）。

### 4.3 对话缺失 / 对话不对

1. 同帧跑 Godot `--log-messages` 和 Rust 侧消息表（`Game::message_history`，
   或 `wolf-cli capture` 的 message 计数）：
   - **消息条数不同**：VM/分支/输入时序问题，先按 4.1 查输入；
   - **条数相同、文本不同**：脚本/翻译/字符串槽问题，查 `wolf-vm` 的文本展开；
   - **条数相同、文本相同、屏幕没有**：渲染层。看该帧 `texts` 数组是否有
     这一项、`rect` 是否在屏内、`alpha` 是否 >0、`font_px` 是否合理；
     用 `--capture` 截该帧，再按 4.2 做 bbox diff。
2. 字形覆盖：静态消息/选项共 21,009 个字符，msyhbd 只缺 5 个码点，且都是
   私用区/乱码（U+E07E、U+E4DE、U+0225、U+0377、U+FFFD）。若新文本真的缺字，
   不要挂全局 fallback（会改度量），应按字符分段用 fallback 画。
3. 消息“被跳过”多半是输入：左键/Enter 的 OK 边沿在一个物理帧内被记录两次
   （按下+锁存）或消息窗口被 `auto_advance` 提前推进。用 `--log-input` 看
   OK 边沿，确认没有 `--auto-new-game`（它会自动推进消息）。

## 5. 存档 fixture 的坑

`work/Data/Save/SaveData01.sav` / `SaveData02.sav` 是**可被玩家覆盖**的实机存档。
视觉回归基线（`m14_visual_regression`）原本按“50 picture 的出货存档”录制；
玩家在游戏里保存后会变成当前画面（例如带存档界面的 64 picture），整帧基线
自然对不上。本轮已：

- 把玩家当前存档备份到 `work/out/player_saves_2026-11-10/`；
- 用 `work/out/save_analysis/synth/SaveData01/02.sav`（50-picture 出货状态）
  恢复 `work/Data/Save/`，让全套 `m3_*` / `m14` 视觉基线重新可跑；
- `m14_visual_regression` 增加 `depends_on_save` 守卫：以后玩家再覆盖
  SaveData01 时，依赖该存档的三个场景会打印 skip，而不是误报渲染回归；
- 存档格式/读写回归由 `m3_save_load` / `m3_save_byte_fidelity` /
  `m3_save_newgame_part1` / `m3_save_ui_roundtrip` 负责，不依赖视觉基线。

要恢复玩家存档：把 `work/out/player_saves_2026-11-10/SaveData01.sav` /
`SaveData02.sav` 复制回 `work/Data/Save/`（测试会按上面的守卫跳过视觉场景）。

## 6. 测试入口

```bash
bash tools/smoke-godot.sh    # 标题/键码/鼠标锁存/滚轮/GameView/读档/存档往返
bash tools/parity-godot.sh   # 600/1200/1800 帧统计 + 600 帧像素
```

新增回归：

| 测试 | 覆盖 |
|---|---|
| `crates/wolf-game/tests/m6_title_wheel.rs` | CE43 深色高亮随方向键/滚轮变化；滚轮与存档网格左右页键逐字节等价 |
| `godot/tests/mouse_latch.gd` | 快速点击锁存、按下坐标、右键、滚轮累计、方向键 raw code、失焦清理 |
| `godot/tests/title_wheel.gd` | `WolfGame.set_wheel` 在标题菜单的上下移动 |
| `godot/tests/gameview_title_wheel.gd` | 真实 `GameView` 的滚轮 + 方向键 → 标题光标 |
