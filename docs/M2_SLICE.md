# M2 日常循环切片（本作实测）

本文件记录 M2 阶段落地范围、实测数值与复现命令。所有测试均以本作 `work/Data` 为数据根；未设置 `WOLF_DATA_ROOT` 时按仓库约定跳过数据用例并保持 exit 0。

## 1. 范围

M2 打通「读档进入卧室 → 夜间行动菜单 → 就寝/日期推进」的日常循环，并把界面按钮的鼠标点击接入解释器的按键轮询。共 13 个新增集成测试 + 若干单元测试。

| 模块 | 文件 | 测试数 |
|---|---|---|
| 鼠标→键码桥接与图片菜单点选 | `crates/wolf-game/src/key.rs`、`crates/wolf-game/src/game.rs`、`crates/wolf-game/tests/m2_input.rs` | 3 单元 + 1 单元 + 5 集成 |
| 夜间菜单与就寝/日期推进 | `crates/wolf-game/tests/m2_daily_loop.rs` | 4 |
| HUD 公共事件（状态/时刻/行动力/日中菜单） | `crates/wolf-game/tests/m2_hud_events.rs` | 4 |

## 2. 读档后的卧室状态

用 `SaveData01.sav` 走标题第二项（读档），跑 1600 帧后：

* HUD 文本含 `19:30`、`周一`、`行动力`、`持有金钱`、`5466円`。
  > 后续说明（M3）：读档收敛过程中的工资抽取是随机事件；换成零售静态随机表后具体
  > 金额会变（当前回归改为只断言 `持有金钱` + 一个 `円` 金额，不再 pin 5466）。
* `vars[4]=19`、`vars[5]=30`（时/分）。
* interpreter warnings = 0。

## 3. 夜间行动菜单（CE245）

读档后 `start_event(245)`，首屏为 6 个选项：

```text
["开始交流 ", "泡茶 ", "泡澡 ", "网上购物 ", "今天就这样睡吧 ", "0"]
```

cursor=0，锚点 `(512,230)`。选择第 5 项（索引 4）会先弹出确认：

```text
"差不多该睡了吧…？" -> ["是 ", "否 "]
```

## 4. 就寝与日期推进（CE251）

* 必须使用干净的 `Game::new` 事件状态运行 CE251；在读档后的 19:30 直接 `start_event(251)` 只会输出 `"…………"` 并停在 00:00 的等待分支（存档状态与事件入口不匹配）。
* 干净状态下跑 400 帧：首条消息含「早上好，哥哥！」；统计 `messages=9 / pictures=74 / sounds=6`；`vars[4]/vars[5]` 由 `00:00` 推进到 `08:30`；末尾停在当日行动菜单（含「睡觉」）。

## 5. HUD 公共事件

测试在每次 `start_event` 前 `game.screen.clear()`，否则读档 HUD 已占用的槽位会混淆归因（已占用 200/220/230/240/250/251/320/2300+；负槽 -5/-4 为背景图标，忽略）。

| 事件 | 名称 | 清屏后画出的正向图片 | 断言要点 |
|---|---|---|---|
| CE242 | 状态表示 | `[220,230,240,250,251]` | 名字 / 行动力 / 精力 / 持有金钱 / 金额(円) |
| CE243 | 时刻表示 | `[200,210]` | `HH:MM`、周N |
| CE244 | 行动力变动 | `[110]` | 带符号整数（本次 `+0`） |
| CE256 | 日中菜单 | 无自带图片 | 出现消息「那么，该怎么做呢。」；时钟前进（before != after） |

CE256 的选项会在第 6/7、14/15 帧短暂出现并被 `auto_choice_delay=2` 自动回答，因此测试只断言最终无残留 choice，而非全程无 choice。

## 6. 鼠标→菜单键码

### 6.1 实现

* `crates/wolf-game/src/key.rs` 新增 `pub fn mouse_bits(buttons: u32, previous: u32) -> u32`：左键按下边沿 → `OK`（决定码 10），右键按下边沿 → `CANCEL`（取消码 11），中键不映射。按住不重复，只在按下那一帧产生新位。
* `crates/wolf-game/src/game.rs` 新增私有 `fn mouse_key_bits(&self) -> u32`（放在 `impl GameHost` inherent 块，避免 E0407）；`key_code`（opcode 123）与 `key_code_auto`（opcode 125）都并入鼠标边沿位，键盘路径不变。

### 6.2 EV16 的真实契约

`SampleMapA` 的 EV16「コマンド選択判定」每帧对每个按钮：

```text
op124 [1100000,16384,<pic>,8]   悬停？
op111 if 1100000 == 1
  op123 [1100001,17]            读键码
  op111 if 1100001 == 10        决定
    op121 [2000067,<index>]     var67 = index
```

测试验证：悬停 + 左键按下 → `var67=1`（picture 400 的 index）；仅悬停不写；点按钮外不写（op124 门控）；右键（11）不写；按住不重复写；键盘 OK 仍驱动同一 poll。

### 6.3 三个坑

1. EV16 page0 的条件是 `var100 >= 1`（byte17=operator1=OP_GREATER_OR_EQUAL），默认 `var100=0` 时该页不激活；测试需先 `game.vm.vars.set(100,1)`。
2. 条件成立的那一帧只启动页，事件下一帧才真正执行；测试在置好 `var100` 后先跑 3 帧预热，再注入输入，否则首帧点击会漏。
3. 不要用 `vm.started_events` 判断地图事件页是否启动——`start_program_inner` 不登记 map event page。

## 7. 验收命令

```bash
cd '/e/Study/github program/Imouto Life' && source tools/env.sh
cargo test -q --workspace                     # exit 0（默认无数据，数据用例跳过）
WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --test m2_input        # 5 passed
WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --test m2_daily_loop   # 4 passed
WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --test m2_hud_events   # 4 passed
WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --lib                  # 229 passed
./target/debug/wolf-cli.exe verify                                         # PASS 64 / 1 SKIP(dxarchive.header)
```

已知非 M2 遗留：`WOLF_DATA_ROOT=work/Data` 跑整个 `-p wolf-game` 时，`m6_night_menu` 等姊妹作 M6 用例仍失败（本作 day-loop 语义不同，M6 按本作重写）；默认无 env 时按设计跳过。
