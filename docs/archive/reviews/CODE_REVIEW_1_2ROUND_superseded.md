> **归档说明（2026-11-12）**：本文件是第一、二轮审查的单行本，已被
> [`docs/reviews/CODE_REVIEW_4ROUND.md`](../../reviews/CODE_REVIEW_4ROUND.md)
> （第一至四轮完整版，含 BUG-41..48）完整收录。
> 仅作证据链保留，不再作为现行依据；行号与结论以现行报告和实测为准。

# 《妹！生活 ～単色～》Rust + Godot 跨平台重写工程全量深度代码审查与修复方案总报告（含第一轮与第二轮深挖结论）

## 一、 执行摘要（Executive Summary）

本报告汇总了对《妹！生活 ～単色～》（Imouto! Life ~Monochrome~）Rust + Godot 4.7.2 跨平台重写工程开展的**第一轮全维度深度代码审查（`BUG-25` 至 `BUG-35`）**与**第二轮全量字节码指令与跨语言管线深挖（`BUG-36` 至 `BUG-40`）**的全部成果、实锤取证、精确代码修复方案及系统级架构演进指南。

### 1.1 审查覆盖范围
* **Rust 核心引擎层（8 个 Crate）**：
  * `crates/wolf-vm`：指令集分发器（`exec.rs`）、控制流块结构分析器（`program.rs`）、变量魔数寻址解码器（`magic.rs`）、四大变量银行（`vars.rs`）、文本转义解析器（`text.rs`）。
  * `crates/wolf-game`：主循环与 `GameHost` 实现（`game.rs`）、自动/并行公共事件触发器（`auto_events.rs`）、地图事件状态机与换页调度（`map_runtime.rs`）、图层树与动态文本图片合成（`picture.rs`、`textpic.rs`）、模态选择支（`choice.rs`）、存档与系统数据库持久化（`savegame.rs`）。
  * `crates/wolf-format`、`crates/wolf-save`、`crates/wolf-render`、`crates/wolf-audio`、`crates/wolf-cli`。
* **跨语言绑定与 Godot 4.7.2 前端层**：
  * `crates/wolf-gdext/src/lib.rs`（GDExtension 帧数据包序列化与输入桥接）。
  * `godot/scripts/GameView.gd`（图层精灵树管理、瓦片地图绘制、音频总线播放、对话框与气泡排版）与 `godot/scripts/WolfText.gd`。
* **全量静态字节码与数据资产（63,506 条指令）**：
  * `work/out/_ce_full.json`（300 个有效公共事件，共 52,078 条指令）。
  * `work/out/map_full.json`（21 张地图 `.mps`，共 11,428 条指令）。

### 1.2 历史缺陷基线核验结论（BUG-01 至 BUG-24）
1. **已闭环并由自动化测试锁定的历史缺陷（`BUG-01` 至 `BUG-19`）**：
   * `BUG-02`（对话框人名框）：气泡采用固定底边模式 2002，由 Opcode 290 平移至 `(512, 536)`，Picture 36014 稳定位于 `(276, 456)` 屏内；根因系 Opcode 112 字符串比较未剥离 bit 24 变量类型标志，现已修复并通过 `tests/m15_balloon_name.rs` 连续 60 帧可见验证。
   * `BUG-04`（日常卧室顶栏体力条）：经原版说明书与 `CE 242` 验证，日常卧室顶栏仅含文本和数字槽位（Picture `220..252`），无体力条素材，体力条仅在夜间互动时出现，判定为 `NOT-A-BUG`。
   * `Opcode 210/211` 相对寻址：寻址范围 `600_000..=699_999` 严格遵循 $\text{target\_id} = \text{caller\_event\_id} + (\text{raw} - 600100)$，已在 `crates/wolf-vm/src/exec.rs:2743` 正确落地。
2. **历史台账（`POST_DEEPSEEK_BUGS_INVESTIGATION_REPORT.md`）中已定位但待合入当前代码分支的 5 项基线缺陷（`BUG-20` 至 `BUG-24`）**：
   * 本报告第五章提供了 `BUG-20` 至 `BUG-24` 的完整合入补丁说明，确保工程团队可凭单份文档一次性闭环所有历史与新发问题。

### 1.3 第一轮与第二轮新发现缺陷全景统计（BUG-25 至 BUG-40，共 16 项）
* **S1 致命级（流程阻断 / 控制流错乱 / 核心内存污染，共 8 项）**：
  * 第一轮发现：`BUG-25`（并行公共事件误用边沿触发）、`BUG-26`（`ENGINE_RESTART` 遗漏 `run_condition == 3` 常时事件）、`BUG-27`（`Opcode 121` 忽略 `flags` 二阶指针寻址且 `eval_num` 返回 `CommonSelf` 魔数地址）、`BUG-28`（`Opcode 124 Field 18` 返回自身 ID 导致 `CE 223` 9 个窗口分支全军覆没）、`BUG-29`（`self_vars` 与 `common_self` 跨协程脏读与退出覆盖）、`BUG-30`（同帧 `mouse_consumed` 吞噬竞争与 `auto_keys` 单帧清零丢失）。
  * 第二轮深挖新增：`BUG-36`（`Opcode 176` `ContinueLoop` 被逆向误判为 `StartLoop2`，导致全库 54 处 `continue` 穿透执行并破坏 `CE 63/212/268/270` 循环栈）、`BUG-37`（`Opcode 140` 音频指令未对延迟 `arg1`/音量 `arg4`/音调 `arg5` 调用 `eval_num`，将变量魔数 `1_600_002` 当作 7.4 小时延迟，且将 `sound_type == 1` 变量 DB 音频误判为 `Stop`）。
* **S2 严重级（核心功能缺失 / 数据库与存档读写错位 / 渲染与性能瓶颈，共 7 项）**：
  * 第一轮发现：`BUG-31`（`Opcode 250` 漏认 `CSelf5..9` 字符串槽位并污染 `engine_num`）、`BUG-32`（`Opcode 174` 返回标题与 `Opcode 211` 预约事件为空实现）、`BUG-33`（`MapRuntime` 换页条件死锁 `Map 5 Ev 17` 昼夜切换）、`BUG-34`（读档不触发 BGM 切换且 `Sys100/Sys102` 音量设置未同步前端）。
  * 第二轮深挖新增：`BUG-38`（`Opcode 220..222` 漏认 `CSelf5` 字符串路径，将 `Save/System.sav` 误判为 `Slot(0)`）、`BUG-39`（`Opcode 130` 场所移动与 `Opcode 151` 画面色调未对坐标/颜色参数调用 `eval_num`）、`BUG-40`（Godot 前端缺失 `Picture.blend` 加算/乘算混合材质映射，且每帧销毁重建 `Sprite2D` 节点树并全量序列化字典）。
* **S3 一般级（细节语义偏差，共 1 项）**：
  * 第一轮发现：`BUG-35`（`textpic.rs` 将 `\sdb` 误路由至 `cdb`、`PictureVars` 将 `\cself` 误作全局变量 `v[n]`、`Opcode 180` 强制 `Wait(0)` 为 `.max(1)`）。

## 二、 新发现缺陷总表（Master Defect Table: BUG-25 to BUG-40）

| 编号 | 审查轮次 | 严重度 | 模块与文件定位 | 问题简述与核心受影响事件 |
| :--- | :--- | :--- | :--- | :--- |
| **BUG-25** | 第一轮 | **S1 致命** | `crates/wolf-game/src/auto_events.rs:11-15, 224-238` | `AutoEvents::sync` 将 `run_condition == 2`（并行触发）实现为边沿触发（`now && !before`），导致 21 个无内部死循环的并行 UI/HUD 事件（`CE 228..243`）及夜间切入计时器（`CE 281/282`）运行 1 次后永久死亡 |
| **BUG-26** | 第一轮 | **S1 致命** | `crates/wolf-game/src/game.rs:82, 1183-1213` | `ENGINE_RESTART` 仅包含 `&[270]`，遗漏全部 `run_condition == 3`（常时并行）公共事件（`CE 271` 快进、`CE 214` 莉子支援、`CE 216` 监控、`CE 261/269`） |
| **BUG-27** | 第一轮 | **S1 致命** | `crates/wolf-vm/src/exec.rs:1586, 1720-1751, 2199-2252` | `Opcode 121` 忽略 `arg3 & 0xFF` 二阶指针寻址标志位（`0x04..0x40`），且 `eval_num` 对 `CommonSelf` 直接返回魔数地址 `15_xxx_xxx`，污染 `CE 270` 与 `CE 266` 关键状态 |
| **BUG-28** | 第一轮 | **S1 致命** | `crates/wolf-vm/src/exec.rs:2457-2462`<br>`crates/wolf-game/src/game.rs:3698-3757` | `Opcode 124` `Field 18`（`処理中イベント番号`）返回调用者自身 ID 而非前台活跃事件 ID，导致 `CE 223` 全部 9 个窗口分支恒不命中 |
| **BUG-29** | 第一轮 | **S1 致命** | `crates/wolf-vm/src/exec.rs:1037-1110, 1505, 1618-1695` | `Instance.self_vars` 与 `Variables.common_self` 缺乏运行期实时双射，跨事件写 `15_027_0xx` 被协程退出时的快照回写覆盖，且 `CE 223` 读不到 `CE 131/132` 实时游标 |
| **BUG-30** | 第一轮 | **S1 致命** | `crates/wolf-game/src/game.rs:2134, 2162, 3074-3080, 3725`<br>`crates/wolf-vm/src/exec.rs:1269, 2504` | 同一物理帧内 `mouse_consumed` 全局吞噬导致并行 UI 抢食点击；`Opcode 125`（`auto_keys`）在帧末无条件清零导致后序协程注入按键丢失 |
| **BUG-31** | 第一轮 | **S2 严重** | `crates/wolf-vm/src/exec.rs:2880-2885`<br>`crates/wolf-game/src/game.rs:3392, 3437` | `Opcode 250` 仅检查 `MagicKind::StrVar`，将全库 46 处 `CSelf5..9`（`1_600_005..9`）字符串写 DB 误存为 `DbValue::Num(0)`，且 DB 读字符串会污染 `engine_num` |
| **BUG-32** | 第一轮 | **S2 严重** | `crates/wolf-game/src/game.rs:3664-3683`<br>`crates/wolf-vm/src/exec.rs:2666, 2765` | `Opcode 174`（返回标题画面，9 处调用）与 `Opcode 211`（预约公共事件，4 处调用）在 `GameHost` 中为空实现（No-op） |
| **BUG-33** | 第一轮 | **S2 严重** | `crates/wolf-game/src/map_runtime.rs:455-467` | `MapRuntime` 在 `pc > 0 \|\| wait != None` 时一律阻断换页，导致 `Map 5 Ev 17`（并行事件）随 `v[125]` 切换昼夜/状态页时死锁在 Page 0 |
| **BUG-34** | 第一轮 | **S2 严重** | `crates/wolf-game/src/savegame.rs:174-184`<br>`godot/scripts/GameView.gd:416-455` | `load_save` 恢复 `bgm_state` 但未向前端推送 `SoundCmd`（读档后残留标题 BGM）；前端未关联 `Sys100`（BGM 音量）与 `Sys102`（SE 音量） |
| **BUG-35** | 第一轮 | **S3 一般** | `crates/wolf-game/src/textpic.rs:659`<br>`crates/wolf-game/src/game.rs:2893-2911`<br>`crates/wolf-vm/src/exec.rs:2707` | `textpic.rs` 将 `\sdb` 误路由至 `cdb`；`PictureVars` 将 `\cself` 当作全局变量 `v[n]`；`Opcode 180` 强制 `Wait(0)` 为 `.max(1)` |
| **BUG-36** | 第二轮 | **S1 致命** | `crates/wolf-vm/src/program.rs:47, 54, 136, 280, 534`<br>`crates/wolf-vm/src/exec.rs:110, 2676-2682, 3103, 3144` | `Opcode 176`（`ContinueLoop` / `ループ開始へ戻る`）被误实现为 `StartLoop2`（新循环头），导致全库 54 处 `continue` 穿透执行并破坏 `CE 63`、`CE 212`、`CE 268`、`CE 270` 循环栈 |
| **BUG-37** | 第二轮 | **S1 致命** | `crates/wolf-vm/src/exec.rs:2578-2631` | `Opcode 140`（`Sound`）未对延迟帧数 `arg1`、音量 `arg4`、音调 `arg5` 调用 `eval_num`，且将 `sound_type == 1`（变量指定 DB 音频，`CE 188`）误判为 `Stop` |
| **BUG-38** | 第二轮 | **S2 严重** | `crates/wolf-vm/src/exec.rs:2786-2791` | `Opcode 220..=222` 仅识别 `MagicKind::StrVar`，导致 `CE 48/131` 传入 `1600005`（`CSelf5 = "Save/System.sav"`）被误当作 `SaveTarget::Slot(0)` |
| **BUG-39** | 第二轮 | **S2 严重** | `crates/wolf-vm/src/exec.rs:2526-2540, 2641-2645` | `Opcode 130`（`Teleport`）与 `Opcode 151`（`ChangeColor`）未对坐标/颜色参数调用 `eval_num`，导致 `Map 1 Ev 3/5` 变量传送至非法坐标 `(2000007, 1100005)` |
| **BUG-40** | 第二轮 | **S2 严重** | `crates/wolf-gdext/src/lib.rs:300-460`<br>`godot/scripts/GameView.gd:260-414` | Godot 前端每帧销毁重建 `Sprite2D` 节点并全量序列化字典，且未映射 `Picture.blend`（加算/减算/乘算混合模式），导致高光特效失真与内存抖动 |

## 三、 第一轮审查缺陷深度剖析与修复方案（BUG-25 至 BUG-35）

### 3.1 BUG-25（S1 致命）：`AutoEvents::sync` 将并行公共事件（`run_condition == 2`）误实现为边沿触发

#### 现场表现
1. 日常卧室与外出场景中，顶栏信息（`CE 242`）、时钟（`CE 237`）、拉环命中检测（`CE 241`）、所持金显示（`CE 243`）、快捷栏（`CE 229`）以及外出地点菜单（`CE 231..235`）仅在条件刚满足的第一帧执行一次，随后画面 UI 彻底冻结，点击无反应。
2. 夜间互动中，表情切入计时器 `CE 281`（`v[91] >= 1`）与身体切入计时器 `CE 282`（`v[92] >= 1`）在倒计时未归零时通过 `Opcode 172` 退出当前帧后，下一帧不再被调度，导致倒计时永远卡死在初始值减 1，切入特写永不消失。

#### 代码与字节码实锤取证
* **源码定位**：`crates/wolf-game/src/auto_events.rs:11-15, 224-238`：
  ```rust
  pub struct AutoEvents {
      triggers: Vec<Trigger>,
      latched: Vec<bool>,
  }
  // ...
  if now && !before {
      fired.push(FiredTrigger {
          event: trigger.event,
          parallel: trigger.mode == TriggerMode::Parallel,
      });
  }
  ```
* **字节码实锤**：
  * 全库 40 个 `run_condition == 2` 的公共事件中，有 **21 个事件内部不包含 `Opcode 170`（Loop）**，包括：`CE 228`（12 条指令）、`CE 229`（208 条）、`CE 231`（162 条）、`CE 232`（112 条）、`CE 233`（89 条）、`CE 234`（112 条）、`CE 235`（113 条）、`CE 237`（17 条）、`CE 241`（61 条）、`CE 242`（111 条）、`CE 243`（35 条）、`CE 278`（44 条）、`CE 281`（46 条）、`CE 282`（47 条）、`CE 285..288`。
  * 以 `CE 281`（`夜アニメ時間管理(顔)`，触发条件 `v[91] >= 1`）为例：当 `v[91] > 1` 时，`pc=15` 执行 `v[91] -= 1`，随后在 `pc=44` 执行 `Opcode 172`（`BreakEvent`）直接结束本次执行，此时 `v[91]` 仍大于等于 1。WOLF 原版引擎中，`run_condition == 2`（並列実行）是**电平触发（Level-Triggered）**：只要条件成立且当前该事件没有活跃实例，下一帧就会再次启动。而 `AutoEvents::sync` 要求 `now && !before`（`v[91]` 必须先变成 0 再变成 `>=1`），导致 `CE 281` 永远停在 `v[91] = 初始值 - 1`。

#### 严格修复建议
修改 `crates/wolf-game/src/auto_events.rs` 中的 `AutoEvents::sync`，传入 `is_alive` 闭包，对于 `TriggerMode::Parallel` 移除 `!before` 边沿限制：

```rust
// crates/wolf-game/src/auto_events.rs
pub fn sync<F>(&mut self, vars: &Variables, mut is_alive: F) -> Vec<FiredTrigger>
where
    F: FnMut(u32) -> bool,
{
    let mut fired = Vec::new();
    for (idx, trigger) in self.triggers.iter().enumerate() {
        let now = trigger.matches(vars);
        let before = self.latched[idx];
        self.latched[idx] = now;
        let should_fire = match trigger.mode {
            TriggerMode::Parallel => now && !is_alive(trigger.event),
            TriggerMode::Auto => now && (!before || !is_alive(trigger.event)),
        };
        if should_fire {
            fired.push(FiredTrigger {
                event: trigger.event,
                parallel: trigger.mode == TriggerMode::Parallel,
            });
        }
    }
    fired
}
```

### 3.2 BUG-26（S1 致命）：`ENGINE_RESTART` 硬编码仅含 `&[270]`，遗漏全部 `run_condition == 3`（常时并行）公共事件

#### 现场表现
1. 按住键盘快进键（`Z` 键或 `Ctrl`）无法触发 `CE 271`（`×┣[ﾒｯｾｰｼﾞ]キー長押しスキップ`）的长按快进。
2. 莉子支援对话监控 `CE 214`（`りこ応援セリフ`）与数值阈值监控 `CE 216`（`21以上でイベント`）在游戏启动第 1~2 帧跑完一次后永久消失。

#### 代码与字节码实锤取证
* **源码定位**：`crates/wolf-game/src/game.rs:82, 1183-1213`：
  ```rust
  const ENGINE_RESTART: &[u32] = &[270];
  ```
* **字节码实锤**：扫描 `_ce_full.json` 中所有 `run_condition == 3`（常時並列実行）的公共事件，共有 5 个：`CE 214`、`CE 216`、`CE 261`、`CE 269`、`CE 271`。这 5 个事件均无顶层死循环，依赖引擎在它们每次执行完毕后于下一帧自动重启（其中 `CE 269` 虽自调 `Opcode 172` 退出，但在 WOLF 中常时并行事件每帧从头执行直至内部条件短路）。

#### 严格修复建议
在 `crates/wolf-game/src/game.rs` 的 `restart_engine_events` 中，遍历 `self.startup_events`（排除仅需启动一次的 `CE 269` 初始化脚本，或按原版语义允许常驻监控事件 `214, 216, 261, 270, 271` 自动重启）：

```rust
// crates/wolf-game/src/game.rs
const ENGINE_RESTART: &[u32] = &[214, 216, 261, 270, 271];
```

### 3.3 BUG-27（S1 致命）：`Opcode 121` 忽略 `flags` 二阶指针寻址且 `eval_num` 将 `CommonSelf` 当作字面量返回

#### 现场表现
1. 新游戏启动时，`CE 269`（`■変数初期化`）调用 `CE 270` 初始化对话框位置与状态，结果 `CE 270` 的 `cself[91]`、`cself[1]`、`cself[2]`、`cself[92]`、`cself[58]`、`cself[94]` 全部被错误赋值为魔数地址 **`15_026_910`**（而非 `0`），导致对话框初始状态彻底错乱。
2. 打开存档/读档界面（`CE 131` -> `CE 266`）时，`CE 266 pc=22` 计算存档槽位 Y 坐标偏移的累加指令失效，反而把 `47` 加到了 `CE 270` 的 `cself[11]` 上。
3. 将鼠标悬停在存档槽位或设置按钮上时，`CE 223` 读取到的游标索引恒为 `15_013_110` 或 `15_013_210`，导致高亮边框与点击音效完全错位。

#### 代码与字节码实锤取证
* **源码定位**：
  1. `crates/wolf-vm/src/exec.rs:1586`（`eval_num`）：
     ```rust
     Some(MagicNumber::Var(MagicKind::CommonSelf { .. })) | None => raw,
     ```
     当 `Opcode 121` 的右值传入 `15_026_910`（`CE 269 cself[10]`）或 `15_013_110`（`CE 131 cself[10]`）时，`eval_num` 直接返回了原始整数 `15_026_910`！
  2. `crates/wolf-vm/src/exec.rs:2199-2252`（`Opcode 121`）：
     ```rust
     let op = (arg(cmd, 3) >> 8) & 0xFF;
     ```
     完全丢弃了低 8 位 `let flags = arg(cmd, 3) & 0xFF;`！
* **字节码实锤（全库共 75 条 `Opcode 121` 含非零 `flags`）**：
  在 WOLF RPG Editor 的 `Opcode 121` 规范中，`arg(cmd, 3)` 的低 8 位 `flags` 含义为：
  * `0x01`：实数运算模式（`real_scale`）
  * `0x04`：右值 1（`arg1`）不求值，取其**变量魔数地址字面量**（`変数番号`）
  * `0x08`：右值 2（`arg2`）不求值，取其**变量魔数地址字面量**
  * `0x10`：左值（`arg0`）为**二阶指针间接写入**（读取 `arg0` 变量中保存的地址 `target_addr`，再写入 `target_addr`）
  * `0x20`：右值 1（`arg1`）为**二阶指针间接读取**（读取 `arg1` 变量中保存的地址 `addr1`，再求值 `addr1`）
  * `0x40`：右值 2（`arg2`）为**二阶指针间接读取**

#### 严格修复建议
1. 在 `eval_num`（`crates/wolf-vm/src/exec.rs:1553-1591`）中补齐 `MagicKind::CommonSelf` 的数值读取：
   ```rust
   Some(MagicNumber::Var(MagicKind::CommonSelf { event, index })) => {
       if !inst.is_map && inst.event == event && (index as usize) < inst.self_vars.len() {
           inst.self_vars[index as usize]
       } else {
           vars.common_self_var(event, index).unwrap_or(0)
       }
   }
   ```
2. 移除 `write_var`（`exec.rs:1728-1748`）中无条件解引用 `15_000_000..16_000_000` 的错误启发式逻辑，改为在 `Opcode 121`（`exec.rs:2199-2252`）中严格按照 `flags` 执行：
   ```rust
   121 => {
       let raw_lhs = arg(cmd, 0);
       let raw_rhs1 = arg(cmd, 1);
       let raw_rhs2 = arg(cmd, 2);
       let flags = arg(cmd, 3) & 0xFF;
       let op = (arg(cmd, 3) >> 8) & 0xFF;
       let assign_op = (arg(cmd, 3) >> 16) & 0xFF;

       let lhs_target = if (flags & 0x10) != 0 {
           Self::eval_num(raw_lhs, inst, vars, host)
       } else {
           raw_lhs
       };

       let mut v1 = if (flags & 0x04) != 0 {
           raw_rhs1
       } else {
           let addr1 = if (flags & 0x20) != 0 {
               Self::eval_num(raw_rhs1, inst, vars, host)
           } else {
               raw_rhs1
           };
           Self::eval_num(addr1, inst, vars, host)
       };

       let mut v2 = if (flags & 0x08) != 0 {
           raw_rhs2
       } else {
           let addr2 = if (flags & 0x40) != 0 {
               Self::eval_num(raw_rhs2, inst, vars, host)
           } else {
               raw_rhs2
           };
           Self::eval_num(addr2, inst, vars, host)
       };
       // 后续按 real_scale、op、assign_op 计算并调用 Self::write_var(lhs_target, next, inst, vars, host)
   }
   ```

### 3.4 BUG-28（S1 致命）：`Opcode 124` `Field 18`（`処理中イベント番号`）返回调用者自身 ID，导致 `CE 223` 全部 9 个分支永不命中

#### 现场表现
在标题画面（`CE 138`）、存读档界面（`CE 131`）、系统设置（`CE 132`）、CG/回想鉴赏（`CE 127`）、全屏菜单（`CE 65`）、确认弹窗（`CE 68`）等所有菜单界面中，负责检测鼠标碰撞与悬停高亮的核心协程 `CE 223`（`○[システム]マウス取得`）完全失效。

#### 代码与字节码实锤取证
* **源码定位**：`crates/wolf-vm/src/exec.rs:2457-2462` 与 `crates/wolf-game/src/game.rs:3698-3757`。
* **字节码实锤**：`CE 223` 在 `pc=28` 执行 `124 [1600001, 18]`（读取 `Sys18` 到 `cself[1]`），随后在 `pc=35` 执行 `111` 多路分支判断 `cself[1]` 是否等于 `500065`、`500068`、`500131`、`500132`、`500133`、`500138`、`500125`、`500126`、`500127`。因为 `exec.rs` 回退返回了 `500_000 + inst.event`（对于 `CE 223` 永远是 `500223`），9 个分支永远无法命中。

#### 严格修复建议
在 `GameHost::engine_state`（`crates/wolf-game/src/game.rs`）中实现 `field == 18`：

```rust
// crates/wolf-game/src/game.rs (inside engine_state)
18 => {
    const WINDOW_EVENTS: &[u32] = &[68, 131, 132, 133, 127, 126, 125, 65, 138];
    for &ev in WINDOW_EVENTS {
        if self.instances.iter().any(|i| !i.is_map && i.event == ev && !i.terminated) {
            return Some(500_000 + ev as i32);
        }
    }
    if let Some(fg) = self.instances.iter().rev().find(|i| !i.parallel && !i.terminated && i.event != _event) {
        return Some(if fg.is_map { fg.event as i32 } else { 500_000 + fg.event as i32 });
    }
    Some(500_000 + _event as i32)
}
```

### 3.5 BUG-29（S1 致命）：`Instance.self_vars` 与 `Variables.common_self` 缺乏运行期实时同步

#### 现场表现
当 `CE 270`、`CE 131`、`CE 132` 处于运行状态时，跨事件读写 `15_000_000+`（`CommonSelf`）仅修改了 `vars.common_self` 或仅修改了 `inst.self_vars`，不仅导致 `CE 223` 读不到 `CE 131/132` 的实时游标，更导致 `CE 270` 轮次结束调用 `save_common_self` 时用旧快照覆盖了其他协程对 `15_027_0xx` 的修改。

#### 严格修复建议
在 `crates/wolf-vm/src/exec.rs` 的 `eval_num`、`eval_str`、`write_var`、`write_str` 中，对于非地图事件（`!inst.is_map`）的 `MagicKind::SelfVar(idx)`，读写时实时同步 `vars.common_self` / `vars.common_self_strs`：

```rust
// crates/wolf-vm/src/exec.rs (inside write_var)
Some(MagicNumber::Var(MagicKind::SelfVar(idx))) => {
    let slot = idx as usize;
    if slot < inst.self_vars.len() {
        inst.self_vars[slot] = value;
    }
    if !inst.is_map {
        vars.set_common_self_var(inst.event, idx, value);
    }
}
```
同时在 `MagicKind::CommonSelf { event, index }` 被写入时，同步更新 `self.instances` 中任何正在运行的 `event` 实例的 `inst.self_vars[index as usize]`（或在 `eval_num` 读取 `SelfVar` 时若 `!inst.is_map` 直接读取 `vars.common_self_var(inst.event, idx)`）。

### 3.6 BUG-30（S1 致命）：同一物理帧内 `mouse_consumed` 全局吞噬竞争与 `Opcode 125`（`auto_keys`）单帧清零丢失

#### 严格修复建议
1. **移除 `engine_state` 内部的即时吞噬**：在 `crates/wolf-game/src/game.rs:3725, 3745` 中，读取 `Field 7/8/9` 时不再将 `self.mouse_consumed = true`，保证同一物理帧内所有并行 UI 事件观测到一致的鼠标边沿输入。
2. **`auto_keys` 跨帧保留 1 个完整调度周期**：在 `crates/wolf-vm/src/exec.rs` 中将 `auto_keys: HashMap<i32, i32>` 改为 `auto_keys: HashMap<i32, (i32, u8)>`，`Opcode 125` 注入时设生命周期 `ttl = 2`，每次 `finish_frame` 将 `ttl -= 1` 并移除 `ttl == 0` 的键。

### 3.7 BUG-31（S2 严重）：`Opcode 250` 误判 `CSelf5..9` 字符串写 DB 并污染 `engine_num`

#### 严格修复建议
在 `crates/wolf-vm/src/exec.rs` 中新增统一判定函数 `Self::is_str_magic(raw: i32, inst: &Instance) -> bool`：

```rust
fn is_str_magic(raw: i32, inst: &Instance) -> bool {
    match decode_magic(raw) {
        Some(MagicNumber::Var(MagicKind::StrVar(_)))
        | Some(MagicNumber::Var(MagicKind::SysStr(_))) => true,
        Some(MagicNumber::Var(MagicKind::SelfVar(idx))) if !inst.is_map && (5..=9).contains(&idx) => true,
        Some(MagicNumber::Var(MagicKind::CommonSelf { index, .. })) if (5..=9).contains(&index) => true,
        _ => false,
    }
}
```
在 `Opcode 250`（`exec.rs:2880-2905`）中用 `Self::is_str_magic(raw_val, inst)` 区分字符串读写与数值读写，并在 `game.rs:3392, 3437` 中分离 `db_read_num` 与 `db_read_str` 避免互相覆盖 `engine_num` / `engine_str`。

### 3.8 BUG-32（S2 严重）：`Opcode 174`（返回标题画面）与 `Opcode 211`（预约公共事件）为空实现

#### 严格修复建议
在 `crates/wolf-game/src/game.rs` 中：
* `return_to_title(&mut self)` 设置 `self.pending_return_to_title = true`，在 `step_frame` 末尾清空 `instances`、`pictures`、`choices`、`map_runtime` 并重新调用 `self.start_startup_events()`。
* `reserve_event(&mut self, event: u32, nums: &[i32], strs: &[String])` 将预约请求压入 `self.reserved_events: VecDeque<(u32, Vec<i32>, Vec<String>)>`，在主前台事件队列空闲时弹出并启动。

### 3.9 BUG-33（S2 严重）：`MapRuntime` 换页条件死锁 `Map 5 Ev 17` 昼夜/状态切换

#### 严格修复建议
修改 `crates/wolf-game/src/map_runtime.rs:455-467`：当活跃页面为 `TriggerType::Parallel` 且 `desired_page != state.active_page` 时，允许立即切换页面并替换 `state.instance`；仅当活跃页面为 `ActionKey` 或 `Auto` 且正在执行阻塞指令时保持 `busy = true`。

### 3.10 BUG-34（S2 严重）：读档不触发 BGM 切换且 `Sys100/Sys102` 音量设置未同步至 Godot 音频总线

#### 严格修复建议
1. 在 `crates/wolf-game/src/savegame.rs:174-184` 的 `apply_save` 中，根据恢复后的 `self.bgm_state` 向 `self.sounds` 队列推送一条 `SoundAction::Play`（若 `playing` 为真）或 `SoundAction::Stop`（若 `playing` 为假）。
2. 在 `crates/wolf-gdext/src/lib.rs` 的 `frame_packet` 中导出 `bgm_volume: self.game.vars().sys_var(100).unwrap_or(100)` 与 `se_volume: self.game.vars().sys_var(102).unwrap_or(100)`，并在 `godot/scripts/GameView.gd` 中应用线性转分贝 `linear_to_db(vol / 100.0)`。

### 3.11 BUG-35（S3 一般）：`\sdb` 文本转义误读 `cdb`、`PictureVars` 解析 `\cself` 错误及 `Wait(0)` 强制延迟

#### 严格修复建议
1. `crates/wolf-game/src/textpic.rs:659`：将 `VarBank::SysDb => self.cdb.cell_str(...)` 修正为 `VarBank::SysDb => self.sdb.cell_str(...)`。
2. `crates/wolf-game/src/game.rs:2893-2911`：`PictureVars` 增加 `owner_event: u32` 字段，将 `VarBank::SelfVar(idx)` 解析至 `self.vars.common_self_var(self.owner_event, idx)`。
3. `crates/wolf-vm/src/exec.rs:2707`：`Opcode 180` 移除 `.max(1)`，当求值结果 `frames <= 0` 时直接返回 `StepSignal::Continue`。

## 四、 第二轮深挖新发现漏洞深度剖析与修复方案（BUG-36 至 BUG-40）

### 4.1 BUG-36（S1 致命）：`Opcode 176`（`ContinueLoop` / `ループ開始へ戻る`）被逆向误判为 `StartLoop2`（循环头）

#### 现场表现
1. **对话框主协程 `CE 63` 每帧无效空转重绘**：`CE 63`（`X[共]メッセージウィンドウ`）在没有对话（`Sys0 == -1`）时本应停留在 `pc=57..63` 的轻量空闲轮询中，但因 `pc=63` 的 `Opcode 176` 未跳回 `pc=57`，导致 `CE 63` **在没有任何对话的每一帧都穿透执行完整的窗口位置重算与图层刷新（`pc=67..87`）**。
2. **气泡对话多行文本截断与跳出异常（`CE 212`）**：当 `CE 212`（`フキダシ会話文表示`）处理含换行符 `\n` 的多行气泡台词时，`pc=72` 的 `Opcode 176` 本应跳回 `pc=62` 继续切分下一行，却直接穿透并压入了一个伪造的内部 Loop 栈帧，紧接着导致 `pc=79` 的 `Opcode 171`（`BreakLoop`）只弹出了伪造的内层帧而无法跳出外层循环。
3. **人名栏表重建逻辑损坏（`CE 268`）与对话标签解析穿透（`CE 270`）**：`CE 268 pc=55, 81` 在过滤无效行（`self20 < 1000`）时通过 `Opcode 176` 跳过追加逻辑，失效后导致被删除的说话人条目被错误拼接回 `self5`；`CE 270 pc=138, 162, 348` 在解析完 `$face=`、`$window=` 等控制标签后调用 `Opcode 176` 跳回标签循环头 `pc=103`，失效后直接向下穿透执行后续标签分支。

#### 代码与字节码实锤取证
* **源码定位**：
  * `crates/wolf-vm/src/program.rs:47, 54, 136, 280, 534`：
    ```rust
    176 => Opcode::StartLoop2,
    ```
    甚至在 `program.rs:136` 中，为了掩盖 `176` 从来没有对应的 `498`（`EndLoop`）这一反常现象，旧代码写了如下错误兜底注释：
    ```rust
    // Close any unclosed StartLoop2 (176) blocks at deeper indent levels —
    // WOLF implicitly closes them when an outer branch ends.
    ```
  * `crates/wolf-vm/src/exec.rs:2676-2682`：
    ```rust
    170 | 176 => {
        let count = if cmd.opcode == 170 && !cmd.args.is_empty() {
            let n = Self::eval_num(arg(cmd, 0), inst, vars, host);
            (n > 0).then_some(n as u32)
        } else {
            None
        };
        Self::enter_loop(inst, pc, count);
    }
    ```
* **全量字节码实锤（全库共 54 处 `Opcode 176`，分布在 22 个核心公共事件中）**：
  扫描全库所有 54 处 `Opcode 176`，**每一处都严格位于 `Opcode 170`（`StartLoop`）循环体内部的条件分支中，且没有任何一处拥有配对的 `498`（`EndLoop`），其真实语义 100% 是 WOLF RPG Editor 的 `ループ開始へ戻る`（`ContinueLoop`，即跳转到当前最内层 `170` 循环的起始处进入下一轮迭代）**：
  * **`CE 63 (X[共]メッセージウィンドウ) pc=57..66`**：
    ```text
    pc=57 op=170 indent=0 a=[]                // Loop {
    pc=60 op=111 indent=1 a=[1,9000000,-1,4]  //   if Sys0 <= -1 {
    pc=61 op=401 indent=1 a=[1]
    pc=62 op=180 indent=2 a=[1]               //     Wait(1);
    pc=63 op=176 indent=2 a=[]                //     ContinueLoop -> 跳回 pc=57!
    pc=64 op=420 indent=1 a=[2]
    pc=65 op=499 indent=1 a=[]                //   }
    pc=66 op=180 indent=1 a=[1]               //   Wait(1);
    pc=67 op=210 indent=1 a=[500265,0]        //   Call CE 265 (表示処理)
    ```
  * **`CE 212 (フキダシ会話文表示) pc=62..81`**：
    ```text
    pc=62 op=170 indent=0 a=[]                // Loop {
    pc=63 op=112 indent=1 a=[1,2,3000024,0]   //   if s[24] contains "\n" {
    pc=64 op=401 indent=1 a=[1]
    pc=66..71                                 //     切分首行并绘制
    pc=72 op=176 indent=2 a=[]                //     ContinueLoop -> 跳回 pc=62 继续切分下一行!
    pc=74 op=401 indent=1 a=[2]               //   } else {
    pc=79 op=171 indent=2 a=[]                //     BreakLoop -> 跳出 pc=62 循环!
    pc=80 op=499 indent=1 a=[]                //   }
    pc=81 op=498 indent=0 a=[]                // } EndLoop
    ```
  * **`CE 268 (○┣[ﾒｯｾｰｼﾞ]名前欄の変更) pc=43..60`**：
    ```text
    pc=43 op=170 indent=1 a=[1600004]         // Loop (cself[4] 次) {
    pc=52 op=111 indent=2 a=[1,1600020,1000,1]//   if cself[20] < 1000 {
    pc=53 op=401 indent=2 a=[1]
    pc=55 op=176 indent=3 a=[]                //     ContinueLoop -> 跳过 pc=58..59 的追加!
    pc=56 op=420 indent=2 a=[2]
    pc=57 op=499 indent=2 a=[]                //   }
    pc=58 op=122 indent=2 a=[1600005,256,1600006] // cself[5] += cself[6] + "\n"
    pc=60 op=498 indent=1 a=[]                // } EndLoop
    ```

#### 严格修复建议
1. **修改 `crates/wolf-vm/src/program.rs`**：
   * 将 `Opcode::StartLoop2` 重命名为 `Opcode::ContinueLoop`；
   * 在 `Opcode::is_loop_start`（`program.rs:53-55`）中仅保留 `Self::StartLoop`；
   * 在 `Program::from_commands`（`program.rs:136-148, 280`）中，移除对 `Opcode::StartLoop2`（`176`）压入 `BlockFrame` 及在 `EndBranch` 隐式关闭它的全部 hack 逻辑。
2. **修改 `crates/wolf-vm/src/exec.rs`**：
   * 将 `exec.rs:2676` 的 `170 | 176 =>` 改为仅 `170 =>`，并从 `skip_loop`（`exec.rs:3103, 3144`）中移除 `176`；
   * 新增 `176`（`ContinueLoop`）分支，跳转到当前最内层 `inst.loops.last_mut()` 的 `end` 指令处（复用 `498 EndLoop` 的计数递减与回跳逻辑，或直接执行计数判定并跳回 `frame.head + 1`）：
     ```rust
     // crates/wolf-vm/src/exec.rs
     176 => {
         if let Some(frame) = inst.loops.last_mut() {
             match &mut frame.remaining {
                 None => {
                     inst.pc = frame.head + 1;
                     return StepSignal::Continue;
                 }
                 Some(rem) if *rem > 1 => {
                     *rem -= 1;
                     inst.pc = frame.head + 1;
                     return StepSignal::Continue;
                 }
                 Some(_) => {
                     let end = frame.end;
                     inst.loops.pop();
                     inst.pc = end + 1;
                     return StepSignal::Continue;
                 }
             }
         }
     }
     ```

### 4.2 BUG-37（S1 致命）：`Opcode 140`（`Sound`）未对延迟/淡入、音量、音调参数调用 `eval_num`，且误将 `sound_type == 1` 判为 `Stop`

#### 现场表现
1. **对话打字音效与技能音效被延迟 160 万帧（约 7.4 小时）**：`CE 270 pc=2017`（气泡对话音效）与 `CE 183 pc=93`（技能音效）传入变量 `1600002` / `1600015` 作为淡入/延迟参数 `arg1`，引擎未调用 `eval_num`，直接将魔数 `1,600,002` 当作延迟时间，导致音效彻底静音。
2. **战斗系统（`CE 188`）SE 音效失效**：`CE 188 pc=31, 242` 使用 `bits = 16777216`（`0x0100_0000`，即 `sound_type == 1`：通过变量 `arg2` 指定的数据库 ID 播放音效），被 `exec.rs:2585` 误判为 `SoundAction::Stop`；且 `CE 188 pc=238` 的音量参数 `1600099` 与音调参数 `1600098` 未求值。

#### 代码与字节码实锤取证
* **源码定位**：`crates/wolf-vm/src/exec.rs:2578-2631`：
  ```rust
  140 => {
      let bits = arg(cmd, 0);
      let kind_nibble = (bits >> 28) & 0x0F;
      let sound_type = (bits >> 24) & 0x0F;
      let kind = match kind_nibble {
          1 => SoundKind::Bgm,
          2 => SoundKind::Bgs,
          _ => SoundKind::Se,
      };
      let play = sound_type == 0 || (bits & 0x0200_0000) != 0;
      let volume = arg(cmd, 4).clamp(0, 100);
      // ...
      fade_ms: arg(cmd, 1).max(0),
  ```
* **全量字节码实锤**：
  * `CE 270 pc=2017`: `op=140 a=[33554464, 1600002, 0, 0, 100, 100]`
  * `CE 183 pc=93`: `op=140 a=[33554464, 1600015, 0, 0, 100, 100]`
  * `CE 188 pc=31`: `op=140 a=[16777216, 0, 1600003, 0]`
  * `CE 188 pc=238`: `op=140 a=[33554432, 0, 0, 0, 1600099, 1600098, 0]`
  * `CE 270 pc=2555`: `op=140 a=[33554432, 0, 0, 0, 100, 1600089, 0]`

#### 严格修复建议
修改 `crates/wolf-vm/src/exec.rs:2578-2631`：

```rust
140 => {
    let bits = arg(cmd, 0);
    let kind_nibble = (bits >> 28) & 0x0F;
    let sound_type = (bits >> 24) & 0x0F;
    let kind = match kind_nibble {
        1 => SoundKind::Bgm,
        2 => SoundKind::Bgs,
        _ => SoundKind::Se,
    };
    let fade_or_delay = Self::eval_num(arg(cmd, 1), inst, vars, host).max(0);
    let db_id = Self::eval_num(arg(cmd, 2), inst, vars, host);
    let volume = if cmd.args.len() > 4 {
        Self::eval_num(arg(cmd, 4), inst, vars, host).clamp(0, 100)
    } else {
        100
    };
    let pitch = if cmd.args.len() > 5 {
        Self::eval_num(arg(cmd, 5), inst, vars, host).clamp(10, 400)
    } else {
        100
    };

    // sound_type: 0 = 直接文件名播放, 1 = 数据库 ID 播放 (db_id < 0 为停止), 2 = 文件名/变量播放, 3 = 停止
    let is_stop = sound_type == 3 || (sound_type == 1 && db_id < 0);
    let path = if !cmd.strs.is_empty() && !cmd.strs[0].is_empty() {
        Self::interpolate(&cmd.strs[0], inst, vars, host)
    } else if sound_type == 1 && db_id >= 0 {
        // 从可读写/系统数据库表查询音频文件路径
        host.resolve_sound_db_path(kind, db_id as u32).unwrap_or_default()
    } else {
        String::new()
    };

    let action = if !is_stop && !path.is_empty() {
        SoundAction::Play {
            kind,
            path,
            volume,
            pitch,
            fade_ms: fade_or_delay,
        }
    } else {
        SoundAction::Stop {
            kind,
            fade_ms: fade_or_delay,
        }
    };
    host.sound(action);
}
```

### 4.3 BUG-38（S2 严重）：`Opcode 220..=222` 忽略 `CSelf5..9` 字符串变量，导致 `Save/System.sav` 读写被重定向至 `Slot(0)`

#### 现场表现
跨存档的全局系统记忆文件 `Save/System.sav`（记录玩家最后一次读写的存档槽位编号 `Sys25`）无法保存和读取：每次在标题画面（`CE 48 pc=209`）读取 `Save/System.sav` 或在存档界面（`CE 131 pc=73`）写入 `Save/System.sav` 时，引擎都错误地读写了 0 号普通存档槽位 `SaveData00.sav`。

#### 代码与字节码实锤取证
* **源码定位**：`crates/wolf-vm/src/exec.rs:2786-2791`：
  ```rust
  let target = if matches!(
      decode_magic(raw_slot),
      Some(MagicNumber::Var(MagicKind::StrVar(_)))
  ) {
      SaveTarget::Path(Self::eval_str(raw_slot, inst, vars, host))
  } else {
      SaveTarget::Slot(Self::eval_num(raw_slot, inst, vars, host).max(0) as u32)
  };
  ```
* **字节码实锤**：
  * `CE 48 pc=208-210`: `122 [1600005, 0] ['Save/System.sav']` -> `221 [1600020, 1600005, 2000000, 0]` -> `121 [9000025, 1600020, 0, 0]`
  * `CE 131 pc=72-73`: `122 [1600005, 0] ['Save/System.sav']` -> `222 [1600012, 1600005, 2000000, 0]`

#### 严格修复建议
修改 `crates/wolf-vm/src/exec.rs:2786-2791`，使用统一的 `Self::is_str_magic(raw_slot, inst)`：

```rust
let target = if Self::is_str_magic(raw_slot, inst) {
    SaveTarget::Path(Self::eval_str(raw_slot, inst, vars, host))
} else {
    SaveTarget::Slot(Self::eval_num(raw_slot, inst, vars, host).max(0) as u32)
};
```

### 4.4 BUG-39（S2 严重）：`Opcode 130`（`Teleport`）与 `Opcode 151`（`ChangeColor`）未对参数调用 `eval_num`

#### 现场表现
在 `Map 1` 的事件 `Ev 3` 与 `Ev 5` 中，使用变量动态设置事件坐标（`x = v[7] = 2000007`, `y = self[5] = 1100005`）时，事件被直接传送到地图外的天际坐标 `(2000007, 1100005)`。

#### 代码与字节码实锤取证
* **源码定位**：`crates/wolf-vm/src/exec.rs:2526-2540` 与 `2641-2645`。
* **字节码实锤**：
  * `Map 1 Ev 3 P 0 pc=7, 10`: `op=130 a=[-2, 2000007, 1100005, 0, 1]`
  * `Map 1 Ev 5 P 0 pc=7, 10`: `op=130 a=[-2, 2000007, 1100005, 0, 1]`
  * `CE 88 pc=14` / `CE 89 pc=29` (`op=151`): 画面色调 RGB 参数同样可能传入变量魔数。

#### 严格修复建议
修改 `crates/wolf-vm/src/exec.rs:2526-2540` 与 `2641-2645`：

```rust
130 => {
    let target = Self::eval_num(arg(cmd, 0), inst, vars, host);
    let x = Self::eval_num(arg(cmd, 1), inst, vars, host);
    let y = Self::eval_num(arg(cmd, 2), inst, vars, host);
    let map_id = if cmd.args.len() > 3 {
        Self::eval_num(arg(cmd, 3), inst, vars, host)
    } else {
        -1
    };
    host.teleport(target, map_id, x, y);
}
// ...
151 => {
    let r = Self::eval_num(arg(cmd, 1), inst, vars, host);
    let g = Self::eval_num(arg(cmd, 2), inst, vars, host);
    let b = Self::eval_num(arg(cmd, 3), inst, vars, host);
    host.tint(r, g, b);
}
```

### 4.5 BUG-40（S2 严重）：Godot 前端每帧重建 `Sprite2D` 节点树、全量序列化字典与缺失 `BlendMode` 材质映射

#### 现场表现
1. **特效图片黑底/过曝失真**：当脚本使用加算混合（`blend = 2`）、减算混合（`blend = 3`）或乘算混合（`blend = 4`）显示高光、光晕、文字特效（如 `Picture/word_effect*.png`）时，Godot 前端一律按普通 Alpha 混合渲染，导致黑底光效图片直接遮挡立绘。
2. **60Hz 帧率下的节点分配与跨语言拷贝抖动**：在 `GameView.gd` 中，每当 Picture 列表发生任何属性微调（如透明度渐变、坐标平移），都会触发 `_rebuild_pictures` 调用 `queue_free()` 销毁旧节点并 `Sprite2D.new()` 重建节点；同时 `wolf-gdext/src/lib.rs` 的 `frame_packet` 在每一帧都将所有 Tile、Picture、TextQuad 无条件打包为全新的 Godot `VarDictionary` 与 `Array`。

#### 严格修复建议
1. **在 `crates/wolf-gdext/src/lib.rs` 中导出 `blend` 字段与版本号**：
   ```rust
   // crates/wolf-gdext/src/lib.rs (inside picture dictionary construction)
   let _ = dict.set("blend", pic.blend);
   ```
2. **在 `godot/scripts/GameView.gd` 中预创建共享混合材质单例并实现节点池复用**：
   ```gdscript
   # godot/scripts/GameView.gd
   var _mat_add := CanvasItemMaterial.new()
   var _mat_sub := CanvasItemMaterial.new()
   var _mat_mul := CanvasItemMaterial.new()
   var _pic_sprites: Dictionary = {} # pic_id -> Sprite2D

   func _ready() -> void:
       _mat_add.blend_mode = CanvasItemMaterial.BLEND_MODE_ADD
       _mat_sub.blend_mode = CanvasItemMaterial.BLEND_MODE_SUB
       _mat_mul.blend_mode = CanvasItemMaterial.BLEND_MODE_MUL

   func _apply_blend_mode(sprite: CanvasItem, blend: int) -> void:
       match blend:
           2: sprite.material = _mat_add
           3: sprite.material = _mat_sub
           4: sprite.material = _mat_mul
           _: sprite.material = null
   ```

## 五、 历史待合入基线缺陷完整补丁指南（BUG-20 至 BUG-24）

为保证单份文档覆盖当前仓库所有待修复项，以下列出历史台账中已定位但尚未合入当前代码分支的 5 项基线缺陷修复要点：

| 编号 | 模块定位 | 修复实现要点 |
| :--- | :--- | :--- |
| **BUG-20** | `crates/wolf-game/src/map_runtime.rs` | `collect_commands` 与 `step_frame` 区分 `TriggerType::Parallel`（每帧循环）与 `ActionKey`/`Auto`（仅在玩家交互或条件满足且非活跃时启动），严禁把 `ActionKey`/`Auto` 混入每帧重刷的并行队列。 |
| **BUG-21** | `crates/wolf-game/src/game.rs` | 在 `teleport` 切换 `current_map_id` 时，将 `self.instances` 中所有 `inst.is_map == true` 的旧地图事件协程标记为 `terminated = true` 并清空旧地图精灵。 |
| **BUG-22** | `godot/scripts/GameView.gd`<br>`crates/wolf-game/src/choice.rs` | 当 `choices` 为空时隐藏 `ChoiceOverlay` 根节点并将 `mouse_filter` 设为 `MOUSE_FILTER_IGNORE`；当 `choices` 非空时仅拦截选择支按钮区域的点击，避免全屏透明容器吞噬右侧菜单栏点击。 |
| **BUG-23** | `crates/wolf-vm/src/vars.rs`<br>`crates/wolf-vm/src/exec.rs` | 补齐 `Variables::common_self_strs`（`CSelf[5..9]` 独立字符串表），支持 `15_000_000 + E*100 + (5..=9)` 跨公共事件字符串读写，并移除 `resolve_string` 将未知数值编码拼接为字面量的错误回退。 |
| **BUG-24** | `crates/wolf-vm/src/exec.rs:2970` | 在 `Vm::step` 的 `match cmd.opcode` 中补齐 `300 => { ... }` 分支（WOLF 高级合成/插件指令，解析其子命令并转发至 `GameHost` 对应图层/音频处理，不再落入 `_ => {}` 静默丢弃）。 |

## 六、 工程代码其他维度的系统性优化指导建议（Engineering & Architectural Roadmap）

### 6.1 虚拟机变量与内存寻址层的“单一事实来源”（Single Source of Truth）重构
* **现状痛点**：当前变量读写分散在 `Instance.self_vars`、`Instance.self_strs`、`Variables.common_self`、`Variables.common_self_strs`、`Variables.normal`、`Variables.strings` 以及 `GameHost` 的 `cself_str` 回调中；且“哪些魔数代表字符串变量”在 `exec.rs` 各处用不完整的 `matches!(decode_magic(raw), ...)` 重复判断（直接诱发了 `BUG-23`、`BUG-27`、`BUG-29`、`BUG-31`、`BUG-38`）。
* **重构指导**：
  1. 在 `crates/wolf-vm/src/magic.rs` 中定义统一的 `MagicNumber::is_string_slot(raw: i32, is_map_context: bool) -> bool`，一次性涵盖 `StrVar(3_000_000..)`、`SysStr(9_900_000..)`、非地图 `SelfVar(5..=9)` 以及 `CommonSelf { index: 5..=9, .. }`。
  2. **彻底取消非地图事件的 `Instance.self_vars` 私有克隆副本**：
     * 地图事件（`inst.is_map == true`）使用关联到 `(map_id, event_id)` 的持久化自变量槽；
     * 公共事件（`inst.is_map == false`）的 `1_600_000 + idx` 直接读写 `Variables.common_self[(inst.event, idx)]`（仅当同一公共事件发生自递归调用 `call_depth > 1` 时使用调用栈帧备份局部变量）。这样无论事件是被子事件修改还是被其他并行协程通过 `15_000_000+` 跨事件读写，永远访问同一份内存，从根源上消灭脏读与退出覆盖（`BUG-29`）。

### 6.2 多协程合作式调度器的确定性三阶段提交（Three-Phase Frame Scheduler）
* **现状痛点**：`Game::step_frame` 当前在单次循环中边遍历 `self.instances` 边修改全局输入消费标志（`mouse_consumed`）并在循环末尾无条件清空 `auto_keys`（诱发 `BUG-30`），使得协程在 `self.instances` Vec 中的先后顺序直接改变游戏逻辑语义。
* **重构指导**：将每物理帧 `step_frame` 拆分为严格的**三阶段流水线**：
  1. **Phase 1（输入采样与触发同步）**：锁定本帧物理输入快照（`FrameInputSnapshot`，对本帧所有同级协程只读共享），合并上一帧注入的 `pending_auto_keys`，并按电平触发规则同步 `AutoEvents`、`ENGINE_RESTART`（含全部 `run_condition == 3` 事件）及 `MapRuntime` 页面切换。
  2. **Phase 2（按优先级分层执行协程）**：严格按照 WOLF 优先级顺序调度：`模态选择支/前台阻塞主事件` -> `自动触发事件 (run_condition == 1)` -> `并行公共事件 (run_condition == 2/3，按 event_id 升序)` -> `并行地图事件 (按 event_id 升序)`。协程内部调用的 `Opcode 125` 写入 `next_frame_auto_keys` 缓冲区。
  3. **Phase 3（帧末提交与 GC）**：将 `next_frame_auto_keys` 提升为下一帧生效的 `active_auto_keys`，清理 `terminated` 实例，计算脏标记并生成渲染快照。

### 6.3 跨语言 FFI 脏版本增量同步与 Godot 节点池化（Zero-Churn Rendering Bridge）
* **现状痛点**：`wolf-gdext/src/lib.rs` 的 `frame_packet` 每帧（60Hz）都会遍历全部地图瓦片与所有图层构造全新的 Godot `VarDictionary` 与 `Array`，而 `GameView.gd` 在图层属性变化时频繁销毁重建 `Sprite2D`。
* **重构指导**：
  1. **脏版本号（Dirty Revision）短路传输**：在 `Game` 中维护 `tile_revision: u64`（仅在切换地图、地图滚动或动态图块变化时递增）与 `picture_revision: u64`（仅在 `Opcode 150/290` 执行或动画插值推进时递增）。`wolf-gdext` 记录上次已发送给 Godot 的版本号，若未变化则在 `frame_packet` 中设置 `"tiles_unchanged": true` / `"pictures_unchanged": true`，省去 80% 以上的跨边界字典构造开销。
  2. **前端 `Sprite2D` 节点池与纹理缓存**：在 `GameView.gd` 中按 `pic_id` 索引持久化的 `Sprite2D` 字典，每帧仅对存活 `pic_id` 原地修改 `position`、`scale`、`rotation`、`modulate` 与 `material`，对移除的 `pic_id` 设 `visible = false` 放入空闲池复用。

### 6.4 静态字节码覆盖率门禁与指令语义不变量测试（Bytecode Invariant CI）
* **现状痛点**：全库有 63,506 条静态指令，许多高阶特性（如 `Opcode 121` 的 `flags` 位域、`Opcode 176` 的 `ContinueLoop`、`Opcode 221/222` 的 `CSelf5` 路径、`Opcode 140` 的变量延迟）仅在特定深入流程中触发。
* **重构指导**：
  1. 扩展 `tools/audit_bytecode.py` 为 CI 门禁脚本，自动扫描全库所有指令中出现的 `>= 1_000_000` 变量魔数所在的 `(opcode, arg_index)` 坐标对，并静态断言 `exec.rs` 对应 `arg(cmd, idx)` 处必须经过 `eval_num` 或 `eval_str` 解引用，防止任何类似 `BUG-37`、`BUG-39` 的漏求值问题再次发生。
  2. 为本次发现的 `BUG-25` 至 `BUG-40` 增补专项集成测试套件 `crates/wolf-game/tests/m16_deep_review_regressions.rs`，覆盖：
     * `Opcode 176` 在 `CE 63` 与 `CE 212` 中的循环跳转与 `inst.loops` 栈平衡断言；
     * `Opcode 121` 在 `CE 269 -> CE 270` 中的 `flags = 0x04 / 0x20` 二阶指针传参断言；
     * `AutoEvents` 在 `CE 281/282` 与 `CE 241/242` 上的电平触发连续多帧存活断言；
     * `Opcode 124 Field 18` 在打开 `CE 131/132/138` 时协助 `CE 223` 命中对应窗口分支的端到端断言。
