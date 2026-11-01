# M5 — 超越原版

状态：**进行中（首个切片 M5-A 已完成）**。M0–M4 已交付；M5 的目标是在数据级重写与
逐像素对等之外，补上原版没有、玩家实际能感知的能力。

| 切片 | 内容 | 状态 |
|---|---|---|
| M5-A | 高分辨率与无级缩放（窗口 fit / 全屏） | 已完成第一切片 |
| M5-B | 运行时调试器（F3 overlay） | 计划 |
| M5-C | 成就 / 游戏倾向汇总面板 | 计划，需先钉住 CE296 变量语义 |
| M5-D | 多语言文本层（中/日/英） | 计划，需先做翻译数据格式 |
| M5-E | Mod 数据覆盖层 | 计划，风险与范围待定 |

## M5-A：高分辨率与无级缩放

原版逻辑画布固定为 **1024x576**，WOLF 的 op150 坐标、消息窗口和地图图层都按这个
坐标系授权。本切片只改变最后的 blit（逻辑帧 -> 窗口），不改任何游戏坐标或存档。

### 玩家用法

```bash
# 默认：整数倍最近邻（1080p 下是 1x、加黑边，保持零售像素网格）
wolf-cli play --load-save work/Data/Save/SaveData01.sav

# 分数 fit：铺满 16:9 窗口；nearest 保留硬像素，linear 更平滑
wolf-cli play --load-save work/Data/Save/SaveData01.sav --scale fit-nearest
wolf-cli play --load-save work/Data/Save/SaveData01.sav --scale fit-linear

# 无边框全屏
wolf-cli play --load-save work/Data/Save/SaveData01.sav --fullscreen
```

运行中热键：

- **F9**：integer -> fit-nearest -> fit-linear -> integer 循环；
- **F11**：无边框全屏开关；
- **F10**：退出（沿用既有绑定，不改）；
- **F12**：重开标题（沿用既有绑定）。

窗口标题会显示当前因子（如 `1.875x fit-nearest`）与 windowed/fullscreen。

### 实现

- `crates/wolf-render/src/scaler.rs`
  - 新增 `ScaleMode`：`Integer`（默认）、`FitNearest`、`FitLinear`，带 `parse`、
    `label`、`next`、`is_fit`。
  - 新增 `FitScaler { scale: f32, offset: [f32;2], used: [f32;2] }` 与
    `fit_scale(win_w, win_h)`：`scale = min(w/1024, h/576)`，允许 <1（小窗口完整显示），
    计算精确的分数偏移和 NDC quad。
  - `Scaler::game_point` / `FitScaler::game_point` 提供 blit 的逆映射；
    `Renderer::window_to_game` 按当前模式调用，鼠标位置在 fit 模式下仍然准确。
- `crates/wolf-render/src/renderer.rs`
  - blit sampler 由单个 nearest 改为 **nearest + linear 两个 sampler**，对应两个
    bind group；`ScaleMode::FitLinear` 才走 linear，其余走 nearest。
  - `present()` 根据模式选择 `Scaler::ndc_quad` 或 `FitScaler::ndc_quad`。
  - 新增 `set_scale_mode` / `scale_mode` / `fit_scaler` / `scale_factor` /
    `window_to_game`。
- `crates/wolf-cli/src/play.rs`：`DisplayOptions { mode, fullscreen }`；启动时设置窗口
  fullscreen 与 renderer 模式；F9/F11 热键；窗口标题显示模式与因子；鼠标走
  `Renderer::window_to_game`。
- `crates/wolf-cli/src/main.rs`：`--scale <integer|fit-nearest|fit-linear>`、
  `--fullscreen` 参数与帮助文本。没有新增外部依赖。

### 测试

`crates/wolf-render/src/scaler.rs` 新增纯函数测试：

- `fit_scale_uses_the_whole_16_by_9_window`（1080p/1440p/4K 全屏且无黑边，
  1.875/2.5/3.75 因子）；
- `fit_scale_shrinks_a_small_window_instead_of_clipping_it`（1000x700 -> 0.9766x，
  used 1000x562.5，上下 68.75 黑边）；
- `fit_ndc_quad_covers_the_screen_and_keeps_the_aspect_ratio`；
- `the_window_to_game_mapping_is_the_inverse_of_the_blit`；
- `scale_mode_parses_and_cycles`。

验收：

```bash
cargo test -q -p wolf-render --lib
cargo build -q -p wolf-cli
cargo test -q -p wolf-cli
```

### 边界

- `capture` 仍输出 **1024x576 逻辑帧**，不受窗口 fit 影响；这是刻意的：capture 的 PNG
  用来和原版逐像素比较，不能把窗口缩放混进证据链。
- 窗口/全屏的实际观感需要真实窗口；headless capture 不模拟 swapchain blit。
- 不改 `Sys 104/105` 相机，不改存档或游戏坐标。

## 后续切片的设计约束

- M5-B 调试器优先做成 `play` 内的 F3 overlay，复用现有 `TextItem` 与字体 fallback；
  不引入新 GUI 依赖。需要读 `Game::vm.vars`、`playtime_frames`、`stats`、
  `last_action_event`、pointer、fps。
- M5-C 成就必须先把 CE296 / プレイ傾向 的变量语义（v99/v180/v187/v189/v200/v202）
  在真实存档与新游戏两条路径上钉住，再定义本地成就清单，不能凭报告臆造。
- M5-D 多语言要单独设计翻译键与回退规则，不能直接改 CP932/GBK 混排解码。
