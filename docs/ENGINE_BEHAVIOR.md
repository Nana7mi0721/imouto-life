# ENGINE_BEHAVIOR.md — 引擎行为清单（数据级重写对原版 Game.exe 的还原状态）

## 0 目的与图例

本项目是《妹！生活 ～単色～》（WOLF RPG Editor 引擎）的**数据级重写**：游戏逻辑、数值与流程由 `Data/`（CommonEvent.dat、地图事件、DB）驱动，本仓库的 Rust 运行时负责忠实执行；但**另有一批行为不在 Data 里，而是硬编码在原版 Game.exe 的运行时**（窗口九宫格布局、文本度量与换行、选择面板越界回退、1/10 UI 缩放、淡入/过渡、present/swapchain 等）。这些行为无法从数据文件导出，只能靠说明书、参考实现、黑盒实测或定点逆向逐项确认。

本文件把这些"数据外部"的引擎行为**逐项登记**，记录原版规则/常量、当前 Rust 实现的还原状态、实现位置（`文件:行`）以及后续核对方法，供后续逆向（C 任务）与验收使用。

**状态图例（取值固定为下列之一）：**

| 图例 | 含义 |
|---|---|
| 已实现 | Rust 侧已按原版规则实现，有代码/测试支撑。 |
| 部分实现 | 主体已实现，但存在已知缺口、未覆盖分支，或数值仅近似。 |
| 未实现 | 尚无对应实现（如真实过渡掩膜、标点禁则）。 |
| 数据可导 | 该行为实际由 Data/脚本承载，引擎只需按数据执行，不硬编码。 |
| 需逆向 | 目前只能靠原版 Game.exe 定点逆向或逐帧实测确认常量/形态。 |

**约定：**
- 每行必须给出「来源」与「测量/核对方法」。来源分四类：**说明书**（安装目录 manual01..06）、**参考实现**（docs/vendor/uberwolf-ref，仅解码格式）、**实测**（实机截图/黑盒）、**逆向**（反汇编/定点调试）。
- 能给出确切数字就写确切数字（如 1024x576、32x24、九宫格边距像素、行距=字号+6）；推断未证实的必须标 **`[推断]`** 或 **`未实测`**，不编造。
- `文件:行` 是核对锚点，非当前渲染截图；行号以本文件撰写时的工作区为准。

---

## 1 表格（核心）

### 1.1 九宫格窗口几何

| 行为项 | 原版规则/常量 | 来源 | 现状 | 本仓库实现位置(文件:行) | 测量/核对方法 |
|---|---|---|---|---|---|
| 窗口皮肤文件与格式 | `SystemFile/WindowBase.png`，18x18 像素；3px 对称边框 | 逆向/实测（皮肤像素） | 已实现 | crates/wolf-game/src/window.rs:27,30,62；crates/wolf-game/src/db.rs:62 | 解包该 png 量得 18x18；行/列 0=外暗线 0x424242、1=亮棱 0xf2f3f3、2=过渡线 0x576062、3..14=体 0x1f2425/α0xdf、15/16 镜像 |
| 九宫格切分算法 | 帧厚 3px 对称九宫格；**角保持像素尺寸、中行列吸收余量**（WOLF 不 tile 边缘） | 逆向 `[推断]` | 已实现 | crates/wolf-game/src/window.rs:62（`nine_slice(dst,skin_w,skin_h)`），split(len,corner)=[0,corner,len-corner,len] | 单测 `nine_slice([0,0,30,20],18,18)`=9 片，centre src[3,3,12,12]/rect[3,3,24,14] |
| 内边距 / 文字区偏移 | 3px 边框 + 帧图整体决定；文本原点 Sys1/Sys2=(64,410)，文字区宽 960（1024−64） | 实测 `[未实测精确内边距]` | 部分实现 | crates/wolf-game/src/message.rs:111,169；FRAME_PICTURE=19500 message.rs:60 | 实机 1024x576 截图量首字像素相对框左上角偏移 |
| 盒最小尺寸 / 小盒退化 | `MIN_BOX=2`；盒小于帧尺寸时角折半 | 逆向 `[推断]` | 部分实现 | crates/wolf-game/src/window.rs:37,62 | 单测 4x4 盒只剩 4 角各 2px |
| 消息窗整图（引擎只量不画） | op150 由脚本画 picture 19500；引擎据其矩形定义 wrap 宽 | 数据可导 | 数据可导 | crates/wolf-game/src/message.rs:60 | CE63 画帧，脚本矩形与 message_vars 一致 |

### 1.2 文本度量与自动换行

| 行为项 | 原版规则/常量 | 来源 | 现状 | 本仓库实现位置(文件:行) | 测量/核对方法 |
|---|---|---|---|---|---|
| 字号 | 共享 Sys8；boot 默认 20，范围外回退 20 | 说明书+实测 | 已实现 | crates/wolf-game/src/message.rs:40；crates/wolf-game/src/game.rs:1331 | CE48 写 Sys8=20；font_px() 取 Sys8 |
| 行距 | 行高 = 字号 + 6（LINE_GAP=6）→ 26 | 逆向 `[推断 6px]` | 已实现 | crates/wolf-game/src/message.rs:43,122 | layout 逐行 y+=max(font)+6 |
| 全/半角宽度 | 全角字符=font_px，半角=font_px*0.5 | 逆向/实测 | 部分实现 | crates/wolf-game/src/choice.rs:88（advance_at）；crates/wolf-game/src/fontmetrics.rs（em_advance） | 有 TTF 时用 hmtx em*px，无字形回退 choice 规则；逐字符量宽 |
| 逐行推进（row_height） | 每行 y += max(行内 font)+6 | 逆向 `[推断]` | 已实现 | crates/wolf-game/src/message.rs（layout/layout_styled） | 多字号混排行对照实测 |
| 标点避头尾（禁则处理） | 原版行首禁则字符集与挤压规则 | 需逆向 `[未实测]` | 未实现 | ——（message.rs 无禁则逻辑） | 需原版 Game.exe 逆向或逐帧实测行首标点处理 |
| 打字机显示 | cps=Sys9（boot 500，CE269 后 120），preroll=Sys10（空闲 9 / 显示 1）；revealed=floor((frames−preroll)*cps/60) | 逆向/实测 | 已实现 | crates/wolf-game/src/message.rs:46,49,268 | 逐帧计字数对照 |
| 换行（wrap） | 按 advance_at 累加断行；断点处空格丢弃 | 逆向 `[推断]` | 已实现 | crates/wolf-game/src/message.rs:288 | 单测长句换行与空格处理 |
| 字体文件与度量 | 优先 `07やさしさゴシックボールド.ttf`；ttf_parser 解析 em_advance=hor_advance/units_per_em | 实测 | 已实现 | crates/wolf-game/src/fontmetrics.rs（FontMetrics::load/advance） | 加载 TTF 比对字宽；缺字 fallback seguisym.ttf |

### 1.3 选择面板布局与越界回退（H-MENU-1）

| 行为项 | 原版规则/常量 | 来源 | 现状 | 本仓库实现位置(文件:行) | 测量/核对方法 |
|---|---|---|---|---|---|
| 面板基本常量 | 行高 30、PADDING 14、TEXT_PX 20、MARKER=30、WIDTH_SLACK 4、MIN_WIDTH 120 | 逆向/实测 | 已实现 | crates/wolf-game/src/choice.rs:23,25,37,42,44,46 | 实机量行高/边距 |
| 面板宽高公式 | 宽=(最宽选项+marker+2*padding+slack).max(120)；高=rows*30+28 | 逆向 `[推断 +28]` | 已实现 | crates/wolf-game/src/choice.rs:112 | 单测 size() 对照 |
| 面板锚点 | Sys3=X、Sys4=Y（WOLF 无居中默认；title 设 (512,1000) 故无框） | 实测 | 已实现 | crates/wolf-game/src/game.rs:1290 | opcode102 按 Sys3/4 定位 |
| H-MENU-1 越界回退 | 面板**完全**屏外时回退居中 ((1024−w)/2,(576−h)/2)；部分越界判据 rect[0]<W&&rect[1]<H&&rect[0]+w>0&&rect[1]+h>0 | 逆向 `[部分越界策略未实测]` | 部分实现 | crates/wolf-game/src/choice.rs:180-214 | 构造超屏选项列表量面板落点 |
| 光标定位 / 鼠标命中行 | 命中行矩形 [x+14, y+14+idx*30, w−28, 30]；点击该矩形返回行号 | 实测 | 已实现 | crates/wolf-game/src/choice.rs:127；crates/wolf-game/src/game.rs:1301 | choice_row_at 与绘制同一 layout_at_sized |
| 标题图片按钮三行 | 固定 X=10，Y=400/450/500，W=240，H=52，GAP=50；命中行 [10,400+idx*50,240,52] | 实测 | 已实现 | crates/wolf-game/src/choice.rs:225,237 | 三张 Picture/menu1..3_b at (10,400/450/500) 由 CE43 绘制，Sys20 镜像光标 |
| 宽选项超屏宽处理 | 原版截断/滚动/换行策略 | 需逆向 `[未实测]` | 未实现 | ——（choice.rs 未处理超宽） | 逆向或实测超长选项渲染 |

### 1.4 1/10 UI 缩放规则

| 行为项 | 原版规则/常量 | 来源 | 现状 | 本仓库实现位置(文件:行) | 测量/核对方法 |
|---|---|---|---|---|---|
| 坐标倍率 | coordinate_scale = (屏宽/32, 屏高/24).max(1) → 1024x576 得 (32,24) | 实测+逆向 | 已实现 | crates/wolf-game/src/message.rs:97；crates/wolf-game/src/db.rs:159 | CE48 用 Sys116/32、Sys117/24；db.rs:290 写 CData(18,97/98) |
| 逻辑画布 | LOGICAL_W=1024、LOGICAL_H=576 | 实测 | 已实现 | crates/wolf-render/src/scaler.rs:21,23 | 与 Game.dat 分辨率一致 |
| ScaleMode | Integer（默认，整数倍）/ FitNearest / FitLinear | 实测 | 已实现 | crates/wolf-render/src/scaler.rs:27-35；crates/wolf-render/src/renderer.rs:641 | F9 循环切换；integer_scale/fit_scale 单测 |
| 1/10 字符格 UI 块判定 | 同 block 内存在宽或高 >两屏（1024x2 / 576x2）的非停靠窗口 picture → 全块 10x | 逆向+实测 | 部分实现 | crates/wolf-game/src/picture.rs:1046（ui_scale_for） | CE95 设置屏 180x195 cells；/10 回像素 |
| 停靠窗（parked）排除 | \|x\|>SCREEN_W*2 或 \|y\|>SCREEN_H*2 视为停靠，不做 1/10 缩放、不当全屏层 | 实测 | 已实现 | crates/wolf-game/src/picture.rs:1062-1063,1441 | balloon 库 24 控件 @(-2784,2880) 被丢弃 |
| 消息窗默认原点 | default_origin(1024,576)=(2*rateX, 17*rateY+trunc(rateY/10))=(64,410) | 逆向 `[公式推断]` | 已实现 | crates/wolf-game/src/message.rs:111 | 实机截图核对文本原点 |
| 取整方式 | 整除(/) 取整；default_origin 内 trunc(rateY/10) | 需逆向 `[未实测]` | 部分实现 | crates/wolf-game/src/db.rs:159；crates/wolf-game/src/message.rs:111 | 非 32/24 整数倍屏宽时核对 |

### 1.5 过渡 / 淡入淡出语义

| 行为项 | 原版规则/常量 | 来源 | 现状 | 本仓库实现位置(文件:行) | 测量/核对方法 |
|---|---|---|---|---|---|
| ScreenTransition 调暗 | duration=frames.max(1)；brightness=\|2t−1\|（三角波 1→0 中点全黑→1），alpha=1−brightness | 逆向 `[曲线推断]` | 部分实现 | crates/wolf-game/src/transition.rs:53,98 | 逐帧量屏幕亮度 |
| 真实过渡掩膜 | `SystemFile/[Transition]Fade.png` 8-bit 640x480，未复现（只建模调暗） | 需逆向/实测 | 未实现 | ——（transition.rs 无掩膜贴图） | 解包该 png，比对原版淡入图案 |
| ScreenTint（151 ChangeColor） | from→to 线性插值；channel=byte/100（100 中性）；flash 位 bit24 三角波 t<0.5?2t:(1−t)*2 | 逆向 `[曲线推断]` | 已实现 | crates/wolf-game/src/tint.rs:54,64,98 | 逐帧量叠色 RGB |
| 叠色顺序 / 作用域 | 151 tint 只乘负号层（quad.number<0）与地图；160/162 fade 乘全部 quad（含 HUD）；neutral 时跳过 | 逆向/实测 | 已实现 | crates/wolf-game/src/game.rs:1165 | capture 输出对照 HUD 是否被 tint |
| 触发频度 | op160 CE 侧 1 次；op161/162 地图侧各 1 次（全作极少触发） | 实测（opcode 直方图） | 部分实现 | crates/wolf-game/src/game.rs:2747 | HANDOFF_M0.md:93,123 opcode 计数 |
| Picture 淡入上限 | 单张 picture fade 帧数上限 MAX_TRANSITION_FRAMES=600 | 逆向 `[上限推断]` | 已实现 | crates/wolf-game/src/picture.rs:126 | 长帧 fade 输入核对 |

### 1.6 present / swapchain

| 行为项 | 原版规则/常量 | 来源 | 现状 | 本仓库实现位置(文件:行) | 测量/核对方法 |
|---|---|---|---|---|---|
| 离屏渲染 | Pass1 画进固定 1024x576 逻辑纹理，Pass2 blit 到 swapchain 单 quad 缩放居中 | 实测（设计） | 已实现 | crates/wolf-render/src/renderer.rs:5-14,910 | capture_rgba 读回 1024x576 |
| 帧格式 / 混合空间 | FRAME_FORMAT=Rgba8Unorm（**非 sRGB**，gamma 字节空间混合） | 逆向（实测 Button01.png 叠色=63） | 已实现 | crates/wolf-render/src/renderer.rs:55 | 原版 DxLib D3DFMT_X8R8G8B8 dst=src.rgb*a+dst*(1−a)；gamma→63=retail，linear→136 |
| 呈现模式 / 延迟 | present_mode=AutoVsync，desired_maximum_frame_latency=2，优先非 sRGB swapchain | 实测 | 已实现 | crates/wolf-render/src/renderer.rs:177,196,199 | 观察 vsync 帧节奏 |
| 帧节奏 | 固定 1/60（FRAME_TIME=16_667µs）；落后>4 帧重置；ControlFlow::WaitUntil | 实测（设计） | 已实现 | crates/wolf-cli/src/play.rs:35,991 | 计帧；F9/F11 切换 |
| 缩放呈现 | Integer/FitNearest→nearest，FitLinear→linear；blit blend=REPLACE 无混合；letterbox 黑边（Pass2 clear BLACK） | 实测 | 已实现 | crates/wolf-render/src/renderer.rs:566,910,976 | 放大截图看锯齿/插值 |
| 窗口尺寸策略 | window_size_for(monitor)：宽留 6%、高留 10%，取最大整数倍 (1024*scale,576*scale) | 实测（本仓策略） | 已实现 | crates/wolf-cli/src/play.rs:65 | 多显示器观察窗口尺寸 |
| 上屏坐标逆映射 | 物理像素→逻辑像素 floor((x−offset)/scale)（window_to_game） | 实测 | 已实现 | crates/wolf-render/src/renderer.rs:672；crates/wolf-render/src/scaler.rs:161,173 | CursorMoved 后点选命中验证 |

---

## 2 逐项说明

### 2.1 九宫格窗口几何
现状依据：皮肤固定 `SystemFile/WindowBase.png`（crates/wolf-game/src/window.rs:27），帧轨 `CORNER=3`（:30）、`MIN_BOX=2`（:37）。`pub fn nine_slice(dst:[f32;4], skin_w:u32, skin_h:u32)->Vec<WindowPiece>`（:62）把任一目标矩形切成 9 片：四角保像素尺寸，中列/中行拉伸吸收余量，返回 `WindowPiece{rect, src}`。DB 侧 `WINDOW_SKIN_FILE`、`WINDOW_SKIN_ROW=0`、`WINDOW_SKIN_COLUMN=24`（crates/wolf-game/src/db.rs:62）在 `apply_engine_defaults` 写入 Data(18,0,24)（:290），使皮肤路径与原版一致。
已知缺口：内边距是否恰为 3px（还是另有像素级 padding）、文本首字相对框左上角的精确偏移**未实测**；盒小于帧时"角折半"的具体退化规则来自单测推断。
下一步核对：解包 WindowBase.png 逐像素量边框厚度；用实机 1024x576 截图对齐消息框左上角与首字像素差；必要时逆向 Game.exe 的窗口绘制函数取 padding 常量。

### 2.2 文本度量与自动换行
现状依据：字号读 Sys8（crates/wolf-game/src/game.rs:1331，范围 8..=64 否则 20）；行高 `line_height(font)=font+6`（crates/wolf-game/src/message.rs:122，`LINE_GAP=6` :43）；全/半角 `advance_at(ch,font_px)`（crates/wolf-game/src/choice.rs:88）全角=font_px、半角=0.5*font_px；有 TTF 时 `fontmetrics::FontMetrics::advance` 用 hmtx 的 em_advance*font_px 覆盖近似（crates/wolf-game/src/fontmetrics.rs）；打字机 `revealed=floor((frames−preroll)*cps/60)`（message.rs:268），cps=Sys9（boot 500/CE269 后 120），preroll=Sys10（9/1）；换行 `wrap(text,width,font_px)` 逐字符断行（message.rs:288）。
已知缺口：**标点避头尾/禁则处理未实现**（message.rs 无行首禁则）；行距恒为 +6 是否随字号缩放（如 1.25 倍）**未实测**；混合字号时 row_height 取 max 也是推断。
下一步核对：构造含行首标点（。、」等）与混排全半角的长文本，与实机截图逐行比对；逆向取原版行长与禁则表。

### 2.3 选择面板布局与越界回退（H-MENU-1）
现状依据：常量 `LINE_HEIGHT=30`（crates/wolf-game/src/choice.rs:23）、`PADDING=14`（:25）、`TEXT_PX=20`（:37）、`MARKER_PX=TEXT_PX*1.5=30`（:42）、`WIDTH_SLACK=4`（:44）、`MIN_WIDTH=120`（:46）；`size(options,font_px)` 宽=(最宽+marker+2*padding+slack).max(120)、高=rows*30+28（:112）；`build` 每行矩形 [x+14, y+14+idx*30, w−28, 30]（:127）；`layout_at_sized(options,cursor,x,y,font_px)`（:180-214）在面板完全屏外时回退居中；`is_title_image_menu`/`title_image_layout` 固定 X=10/Y=400,450,500/W=240/H=52（:225,237）；`game::choice_row_at`（crates/wolf-game/src/game.rs:1301）用同一布局做命中矩形（px≥line[0]&&px<line[0]+w&&py≥line[1]&&py<line[1]+h）。锚点取 Sys3/Sys4（game.rs:1290）。
已知缺口："完全屏外才回退居中"是本仓策略，原版是否**部分越界即回退**、还是贴边夹取**未实测**；超宽选项的截断/滚动**未实现**。
下一步核对：用选项数量多/文本超宽的构造菜单，逐像素量面板落点；逆向 opcode102 的面板绘制函数确认回退阈值与对齐方式。

### 2.4 1/10 UI 缩放规则
现状依据：`coordinate_scale(screen)->(i32,i32)=((w/32).max(1),(h/24).max(1))`（crates/wolf-game/src/db.rs:159；message.rs:97 同式），1024x576→(32,24)；`LOGICAL_W=1024/LOGICAL_H=576`（crates/wolf-render/src/scaler.rs:21,23）；`ScaleMode{Integer,FitNearest,FitLinear}`（scaler.rs:27-35），`integer_scale`（:97）取 `min(win_w/1024,win_h/576).max(1)` 并居中，`fit_scale`（:134）取 `min(w/1024,h/576)`（<1 允许）。1/10 字符格判定 `Screen::ui_scale_for`（crates/wolf-game/src/picture.rs:1046）：同 block(number/100) 内若存在宽或高 >1024x2/576x2 的非停靠、非 sysgraphic 窗口 picture→返回 10.0，否则 1.0；停靠窗以 `\|x\|>SCREEN_W*2 或 \|y\|>SCREEN_H*2` 判据（:1062-1063）。
已知缺口：取整用整除而非 round/floor 的差异在**非 32/24 整数倍**分辨率下**未实测**；`default_origin` 的 `trunc(rateY/10)` 项是**推断**公式。
下一步核对：以 1280x720 等非整数倍分辨率实机截图量像素比；逆向 coordinate_scale 与 UI 缩放的乘除点。

### 2.5 过渡 / 淡入淡出语义
现状依据：`ScreenTransition{elapsed,duration,active}`，`start(kind,frames)`（crates/wolf-game/src/transition.rs:53）`duration=frames.max(1)`，`progress=elapsed/duration`，`brightness=|2t−1|` 三角波（:98）；`ScreenTint{from,to,elapsed,duration,flash}`，`set(colour,frames)`（crates/wolf-game/src/tint.rs:54）解析 R/G/B 位 16/8/0 为百分比（100 中性），`rgb()` 线性插值、flash 三角波（:64），`channel=byte/100`（:98）。叠色作用域 `apply_screen_tint`（crates/wolf-game/src/game.rs:1165）：151 tint 只乘 `quad.number<0` 与地图层，160/162 fade 乘全部 quad（含 HUD）。每帧 tick 顺序：`screen.tick()→screen.advance()→screen_tint.tick()→screen_transition.tick()`（game.rs:1948-1956）。
已知缺口：真实掩膜 `[Transition]Fade.png`（640x480 8-bit）**未复现**，仅建模"调暗"；曲线是否纯线性三角波、以及 fade 与 tint 的**相乘先后顺序**是否为原版**未实测**。
下一步核对：解包该 Fade.png；逐帧摄录原版过渡的屏幕亮度曲线拟合 easing；逆向过渡绘制顺序。

### 2.6 present / swapchain
现状依据：两 pass（crates/wolf-render/src/renderer.rs:5-14）——Pass1 画进固定 1024x576 Rgba8Unorm 逻辑纹理，Pass2 把该纹理作为单 quad blit 到 swapchain 缩放居中（present :910）；`FRAME_FORMAT=Rgba8Unorm`（:55）刻意非 sRGB 以复现 DxLib 的 gamma 字节空间 alpha 混合（实测 Button01.png rgb0/α191 叠底色 251→gamma 63=retail 截图，linear 136）；present_mode=AutoVsync、latency=2（:196,199）；blit blend=REPLACE、letterbox 由 Pass2 clear BLACK（:566,976）；`capture_rgba` 读回 1024x576 RGBA8（:1041）。帧节奏由 crates/wolf-cli/src/play.rs:35 `FRAME_TIME=16_667µs` 与 `about_to_wait`（:991）驱动，落后>4 帧重置。
已知缺口：本作锁 60Hz/固定网格是否与原版可变帧（DxLib 默认 60）完全一致**未实测**；`window_size_for` 的 6%/10% 留边是本仓播放器策略，原版窗口模式尺寸未知。
下一步核对：抓取原版帧率与窗口尺寸；对比 capture 与实机截图像素（已用于验证 gamma 空间）。

---

## 3 仍需逆向/实测的常量清单

下列常量目前靠推断或仅近似，需用原版 Game.exe 定点逆向或逐帧实测确认（供后续 C 任务）：

1. **九宫格内边距**：帧厚 3px 之外的额外 padding 是否存在；期望形态=文本首像素相对框左上角 (dx,dy)。
2. **盒小于帧的退化规则**："角折半"的确切阈值与像素分配；期望形态=极小消息框角部裁剪。
3. **标点避头尾（禁则）字符集与挤压规则**；期望形态=行首标点的换行/悬挂策略。
4. **行距缩放关系**：行高恒=字号+6，还是 =字号×系数（如 1.25）；期望形态=不同字号下的行距序列。
5. **打字速度语义**：cps/60 与 preroll=9 帧是否精确；期望形态=逐帧显字数曲线。
6. **选择面板越界回退阈值**：完全越界才居中 vs 部分越界即回退，或贴边夹取；期望形态=面板越界时的落点坐标。
7. **超宽选项处理**：截断 / 横向滚动 / 强制换行；期望形态=超长文本渲染。
8. **coordinate_scale 取整方式**：整除 vs floor vs round；非 32/24 整数倍分辨率下的倍率值。
9. **default_origin 的 trunc(rateY/10) 项**：该经验项是否为原版公式；期望形态=不同屏幕比例下的文本原点。
10. **过渡曲线与掩膜**：是否纯线性三角波/有无 easing；`[Transition]Fade.png` 640x480 8-bit 的实际图案。
11. **tint × transition 叠加顺序**：先乘 151 tint 后乘 fade（本仓）是否为原版顺序；期望形态=两者同时激活时的合成色。
12. **present 帧率与窗口尺寸**：原版是否锁 60Hz、窗口模式初始尺寸；期望形态=抓帧时间戳与窗口矩形。

共 **12** 项需逆向/实测常量。

### 3.1 C 任务（Game.exe 定点逆向）进展与结论

工具链：`rea-agents` v6.7.0 可运行但本机无原生分析引擎（Hopper 仅 macOS、Ghidra 未装、IDA 未配、Kuna 未设），rea 的 decompile/analyze 不可用；改用 `pefile`+`capstone` 自建只读工具 `tools/re/wolfpe.py`。完整证据与反汇编片段见 **`docs/RE_GAME_EXE.md`**。

已从二进制/随附资源**直接核对**（详见 RE_GAME_EXE.md §2–§4）：

- 引擎身份：**WOLF RPG Editor ver2.22（Editor 构建 20180525）**，DxLib 静态链接单文件 exe。
- 呈现后端：GDI 软件光栅（`CreateDIBSection`/`StretchDIBits`/`SetDIBitsToDevice`），**无 d3d9/d3d11/dxgi 导入 → 无 swapchain**（对应 §1.6 / §3-12 的 present 部分）。
- 文本度量：走 GDI（`GetTextExtentPoint32W`/`GetTextMetricsA`/`GetGlyphOutlineW`）；字体以 `FindFirstFileA("*.ttf")` 枚举数据目录加载（对应 §2.2 字体来源）。
- 九宫格：`WindowBase.png` 实测 18x18、3px 对称边框 → `CORNER=3`、无额外 padding（对应 §3-1）。
- 过渡掩膜：`[Transition]Fade.png` 实测 640x480、8-bit 灰度（对应 §3-10 资源部分）。
- 分辨率：数据驱动（运行时有 `[Read]Screen size X` 调试串；`assets --db-defaults` 已导出 1024x576）。

仍**未解、需 Ghidra 反编译或逐帧实测**的项：§3-2 盒退化、§3-3 禁则、§3-4 行距缩放、§3-5 打字机精度、§3-6 选择面板越界阈值、§3-7 超宽选项、§3-8 取整方式、§3-9 `trunc(rateY/10)`、§3-10 曲线 easing/掩膜语义、§3-11 tint×fade 顺序、§3-12 帧率/窗口初始尺寸。

---

## 4 获取途径与优先级

**官方说明书（已覆盖）**：安装目录 `manual01..06.jpg` 六页（概述/操作/职业、流程/妹妹状态、哥哥状态/道具、夜间互动界面、游戏数据/收集、截图致谢），只给**操作方式、流程与玩法数值**，不含引擎几何/渲染常量。已有逐条核对见 docs/M3_MANUAL_ALIGNMENT.md（只核对界面/流程/数值，状态取值 已实现/待实现/不适用）。因此九宫格、文本度量、choice 回退、1/10 缩放、过渡、present 这些"引擎几何"**说明书中没有**，需另寻途径。

**参考实现（docs/vendor/uberwolf-ref，仅解码格式）**：现含 `DXLib/DXArchiveVer6.*`、`DXLib/Huffman.*`、`DXLib/DXArchive.h`、`UberWolfLib/WolfDec.*`、`dw8_verify.py`、`dw2_header.py` 等，全部只覆盖 **.wolf 归档解码 / 数据格式**，**不覆盖渲染、窗口几何或文本度量**。故不能作为几何常量的来源。

**黑盒实测（首选、低成本）**：游戏内 PrintScreen（Game.ini `ScreenShotFlag=1`，产物在安装目录，**1024x576 原生**）逐帧/逐像素测量；结合游戏内已知坐标（菜单按钮、消息框、状态面板）反推内边距、行距、面板落点与缩放倍率。仓库内已有 docs/REFERENCE.md 的 10 张实机截图目录可复用。注意：headless capture 的 wgpu 离屏初始化目前卡死，仅用于读回纹理，不作视觉核对主路径。

**逆向（适合验证硬编码常量）**：本仓已备好只读静态分析工具 **`tools/re/wolfpe.py`**（`pefile`+`capstone`：PE 事实/字符串/绝对地址 xref/前向反汇编），并产出 **`docs/RE_GAME_EXE.md`**（含 Game.exe SHA-256、引擎版本 ver2.22、导入表与已核对项）。该工具适合验证"说明书没有、实测难分离"的量——九宫格绘制参数、文本度量常量（行长/禁则表）、choice 越界回退阈值、`coordinate_scale` 乘除点、过渡曲线与掩膜资源、present 帧率/窗口尺寸。做法：定位 Game.exe 中对应绘制/布局函数，取立即数常量并与本仓 `文件:行` 的取值比对。

**优先级建议**：(1) 先实测高频可见项——九宫格内边距、行距、标题图片菜单坐标（影响每帧 UI 观感）；(2) 再实测文本换行/打字机曲线（影响对话可读性）；(3) 对难以实测的禁则、回退阈值、过渡曲线与掩膜，排入逆向任务（对应第 3 节 12 项）。