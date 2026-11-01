# M7 模拟器热键重绑定

本轮把模拟器（端口前端）用于调试与呈现的**功能热键**从源码里的硬编码判断抽成
一份可选的配置文件，玩家不重新编译就能改键。游戏本身的移动 / 确认 / 取消等
键位仍由数据与设置界面决定，**不受本功能影响**。

## 1. 哪些键可以重绑

只针对「模拟器功能键」这一层，默认映射与之前的硬编码行为完全一致：

| 动作（配置文件里的名字） | 作用 | 默认键 |
|---|---|---|
| `stats` | 开关游玩统计 / 成就浮层 | F2 |
| `debug` | 开关运行时调试浮层 | F3 |
| `backlog` | 开关消息回顾浮层 | F4 |
| `scale` | 循环切换呈现缩放模式 | F9 |
| `fullscreen` | 开关无边框全屏 | F11 |
| `quit` | 关闭窗口 | F10 |
| `restart` | 就地重启会话（重载数据并回到标题） | F12 |

以下键位**不在此列，保持固定**，因为它们属于游戏自身的输入映射：

- 方向键（移动光标）、Enter（确认）、Backspace / Escape（取消）等固定别名；
- 设置界面里可配置的 Z / X / C（Sys52..54）以及物理键到 WOLF 键码的映射
  （WASD、方向、确认等由脚本轮询的位）。

换句话说：本功能只改「模拟器自己额外提供的那几个 F 键」，不会动游戏内键位。

## 2. 配置文件格式

`--hotkeys <FILE>` 指向一份 UTF-8 纯文本文件，每行一条 `动作 = 键名`：

- 空行、以 `#` 或 `;` 开头的行被忽略（可当注释）；
- 分隔符用 `=` 或 `:` 均可；
- 动作名、键名都不区分大小写；
- 文件可以只写其中几行，**没写的动作沿用默认键**；
- 若某行写了未知动作名或未知键名，会打印一条明确的错误，并**让该动作保留默认键**
  （不会因为一个笔误把整份配置丢掉）。

### 2.1 示例

```ini
# 模拟器功能热键（等号两边空格随意）
stats      = F5
debug      = F6
backlog    = F7
scale      = F8
fullscreen = F1
quit       = Escape
restart    = F12
```

### 2.2 支持的键名

- 功能键：`F1` .. `F12`；
- 其余非字符键：`Enter`（别名 `Return`）、`Escape`（别名 `Esc`）、`Tab`、
  `Space`、`Backspace`、`Delete`（`Del`）、`Insert`（`Ins`）、`Home`、`End`、
  `PageUp`（`PgUp`）、`PageDown`（`PgDn`）、`Up`/`Down`/`Left`/`Right`
  （或 `ArrowUp` 等）。

字母、数字等字符键不在支持范围内：它们属于游戏内输入，且 winit 把字符键报告为
字符而非命名键，不适合作为模拟器功能键。

## 3. 用法

```bash
# 无配置文件：行为与旧版完全一致
wolf-cli play

# 载入自定义热键
wolf-cli play --hotkeys work/hotkeys.ini

# 期间可用 --until 冒烟退出
wolf-cli play --hotkeys work/hotkeys.ini --until 120
```

载入成功会打印 `hotkeys: loaded <FILE>`；出现坏行时打印
`hotkeys: line N: ... (keeping the default binding)`，其余合法行照常生效。
文件读不到时打印 `hotkeys: cannot read ... (using the built-in mapping)`，
游戏仍会以默认热键启动——配置文件笔误不会阻止游戏运行。

## 4. 实现位置

- `crates/wolf-cli/src/hotkeys.rs`：`HotkeyConfig`（默认表、解析、键名解析、
  `is_*` 匹配方法）以及单元测试。
- `crates/wolf-cli/src/main.rs`：`--hotkeys <FILE>` 参数与 `load_hotkeys` 载入逻辑，
  把配置传入 `play`。
- `crates/wolf-cli/src/play.rs`：`window_event` 里原本的 F 键硬编码判断改为
  查 `HotkeyConfig`；`is_restart_key` 改为 `HotkeyConfig::is_restart`。

测试覆盖：默认映射与旧行为一致、合法配置解析、部分配置保留默认、非法键名/未知动作
报错且回退默认、重启键随配置变化。
