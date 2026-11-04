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
| 行距 | 行高 = 字号 + trunc(行距配置 × min(基准字号,32)/32)；本作 6×16/32 = **3** → Sys8=20 时 **23**（RE FUN_004c2d50；实机 101 窗口行距 23.0） | 逆向 A + 截图实测 | 已实现 | crates/wolf-game/src/message.rs:44,50,133 | 实机 101 三行墨迹 pitch 34.36/1.496 ≈ 23.0；Game.dat u8[11]=6、u8[0]=16 |
| 全/半角宽度 | 全角字符=font_px，半角=font_px*0.5 | 逆向/实测 | 部分实现 | crates/wolf-game/src/choice.rs:88（advance_at）；crates/wolf-game/src/fontmetrics.rs（em_advance） | 有 TTF 时用 hmtx em*px，无字形回退 choice 规则；逐字符量宽 |
| 逐行推进（row_height） | 每行 y += max(行内 font) + 缩放后行距（本作 3） | 逆向 A | 已实现 | crates/wolf-game/src/message.rs（layout/layout_styled） | 多字号混排行对照实测 |
| 标点避头尾（禁则处理） | 原版行首禁则字符集与挤压规则 | 需逆向 `[未实测]` | 未实现 | ——（message.rs 无禁则逻辑） | 需原版 Game.exe 逆向或逐帧实测行首标点处理 |
| 打字机显示 | cps=Sys9（boot 500，CE269 后 120），preroll=Sys10（空闲 9 / 显示 1）；revealed=floor((frames−preroll)*cps/60) | 逆向/实测 | 已实现 | crates/wolf-game/src/message.rs:46,49,268 | 逐帧计字数对照 |
| 换行（wrap） | 按 advance_at 累加断行；断点处空格丢弃 | 逆向 `[推断]` | 已实现 | crates/wolf-game/src/message.rs:288 | 单测长句换行与空格处理 |
| 字体文件与度量 | 优先 `07やさしさゴシックボールド.ttf`；ttf_parser 解析 em_advance=hor_advance/units_per_em | 实测 | 已实现 | crates/wolf-game/src/fontmetrics.rs（FontMetrics::load/advance） | 加载 TTF 比对字宽；缺字 fallback seguisym.ttf |

### 1.3 选择面板布局与越界回退（H-MENU-1）

| 行为项 | 原版规则/常量 | 来源 | 现状 | 本仓库实现位置(文件:行) | 测量/核对方法 |
|---|---|---|---|---|---|
| 面板基本常量 | TEXT_PX 20；行距 = font + trunc(14×16/32) = **27**；文本内缩 **8/侧**；行起点 +6；光标 = CursorBase.png 九宫格（corner 4） | 逆向 A + 截图实测 | 已实现 | crates/wolf-game/src/choice.rs:23-62,70 | 89EF/EE 两张实机图：行距 27.18/26.87、边框→首字墨迹 8.05/7.99、高亮条 20 |
| 面板宽高公式 | 宽 = 最宽选项 advance + 2×8（无最小宽）；高 = 6 + rows×27；实测 4 行 156×114、5 行 162×141 | 截图实测（RE 的 +0x1a=26 与实测 17.8 冲突，取内缩值） | 已实现 | crates/wolf-game/src/choice.rs:139-167 | 单测 the_panel_geometry_is_the_measured_102_panel |
| 面板锚点 | Sys3=X、Sys4=Y（WOLF 无居中默认；title 设 (512,1000) 故无框） | 实测 | 已实现 | crates/wolf-game/src/game.rs:1290 | opcode102 按 Sys3/4 定位 |
| H-MENU-1 越界回退 | 原版**无回退、无夹取**（FUN_004c3fa0 直接用字段值/默认锚点） | 反向 A | 保留兜底 | crates/wolf-game/src/choice.rs:211-245 | 屏界面板完全在外时回退居中；仅作隐藏菜单（title 用 −1000 藏引擎面板）的兜底，C 级未闭合，见 LAYOUT §7.1 |
| 光标定位 / 鼠标命中行 | 光标框 [x+6, row_y, w−12, font_px]，整行 CursorBase.png 九宫格；无 "▶ " 字形；命中行矩形 [x+8, y+6+idx*27, w−16, 27] | 逆向 A + 截图实测 | 已实现 | crates/wolf-game/src/choice.rs:153-187；crates/wolf-game/src/game.rs:1301 | choice_row_at 与绘制同一 layout_at_sized |
| 标题图片按钮三行 | 固定 X=10，Y=400/450/500，W=240，H=52，GAP=50；命中行 [10,400+idx*50,240,52] | 实测 | 已实现 | crates/wolf-game/src/choice.rs:225,237 | 三张 Picture/menu1..3_b at (10,400/450/500) 由 CE43 绘制，Sys20 镜像光标 |
| 宽选项超屏宽处理 | 原版截断/滚动/换行策略 | 需逆向 `[未实测]` | 未实现 | ——（choice.rs 未处理超宽） | 逆向或实测超长选项渲染 |

### 1.4 1/10 UI 缩放规则

| 行为项 | 原版规则/常量 | 来源 | 现状 | 本仓库实现位置(文件:行) | 测量/核对方法 |
|---|---|---|---|---|---|
| 坐标倍率 | coordinate_scale = (屏宽/32, 屏高/24).max(1) → 1024x576 得 (32,24) | 实测+逆向 | 已实现 | crates/wolf-game/src/message.rs:97；crates/wolf-game/src/db.rs:159 | CE48 用 Sys116/32、Sys117/24；db.rs:290 写 CData(18,97/98) |
| 逻辑画布 | LOGICAL_W=1024、LOGICAL_H=576 | 实测 | 已实现 | crates/wolf-render/src/scaler.rs:21,23 | 与 Game.dat 分辨率一致 |
| ScaleMode | Integer（默认，整数倍）/ FitNearest / FitLinear | 实测 | 已实现 | crates/wolf-render/src/scaler.rs:27-35；crates/wolf-render/src/renderer.rs:641 | F9 循环切换；integer_scale/fit_scale 单测 |
| 1/10 字符格 UI 块判定 | 同 chapter(number/1000) 内存在宽或高 >两屏（1024x2 / 576x2）的非停靠窗口 picture → 全块 10x；块内 **x 已是像素（不除），y/w/h 才是十分之一（除 10）** | 逆向+实测 | 已实现（存档/读档界面已验证） | crates/wolf-game/src/picture.rs:1046（ui_scale_for）、crates/wolf-game/src/atlas.rs:532、crates/wolf-game/src/window.rs（nine_slice_frame） | CE94 存档屏/CE95 设置屏；见 docs/re/SCREENSHOT_METRICS.md §6 |
| 停靠窗（parked）排除 | \|x\|>SCREEN_W*2 或 \|y\|>SCREEN_H*2 视为停靠，不做 1/10 缩放、不当全屏层 | 实测 | 已实现 | crates/wolf-game/src/picture.rs:1062-1063,1441 | balloon 库 24 控件 @(-2784,2880) 被丢弃 |
| 消息窗默认原点 | default_origin(1024,576)=(2*rateX, 17*rateY+trunc(rateY/10))=(64,410) | 逆向 `[公式推断]` | 已实现 | crates/wolf-game/src/message.rs:111 | 实机截图核对文本原点 |
| 取整方式 | 整除(/) 取整；default_origin 内 trunc(rateY/10) | 需逆向 `[未实测]` | 部分实现 | crates/wolf-game/src/db.rs:159；crates/wolf-game/src/message.rs:111 | 非 32/24 整数倍屏宽时核对 |

### 1.5 过渡 / 淡入淡出语义

| 行为项 | 原版规则/常量 | 来源 | 现状 | 本仓库实现位置(文件:行) | 测量/核对方法 |
|---|---|---|---|---|---|
| ScreenTransition（160/161/162） | **单程交叉溶解**：160 只装参数（kind、flags；duration=`flags & 0xffff`、bit16=wait，起跑恒阻塞）；161 冻结当前帧；162 起跑，alpha=`remaining/duration` **线性递减、无 easing、非三角波**，remaining 每帧减 `60/fps` | 逆向（A，见 `docs/re/TRANSITION.md` §1–§3） | 已实现 | crates/wolf-game/src/transition.rs:70,77,86,135；crates/wolf-vm/src/exec.rs:2115-2134 | capture 逐帧读 alpha；161 在 capture 路径只打日志 |
| 真实过渡掩膜 | `SystemFile/[Transition]Fade.png` 640x480 L **单轴线性斜渐变**（≈21.5°、过渡带≈272 px、灰阶 0..251）；本作唯一 transition 是 kind=−1（无掩膜、均匀 alpha 溶解），掩膜路径降级为同一均匀溶解 | 逆向（A） | 本作路径已实现，掩膜未贴图 | crates/wolf-game/src/transition.rs:168（wants_mask） | 全作无 kind≥0 调用（opcode 直方图） |
| ScreenTint（151 ChangeColor） | 151 是 DxLib `SetDrawBright`：`bright=clamp(255+(p−100)×255/100, 0, 255)`，**p≥100 钳到中性、不是百分比乘子**；flash（bit24）不是三角波，而是**整屏纯色块 overlay**，色值同公式、alpha=(剩余帧/总帧) 单向衰减 | 逆向（B，见 `docs/re/TRANSITION.md` §4–§5） | 已实现 | crates/wolf-game/src/tint.rs:106,119 | 逐帧读 `flash_overlay()` 的 rgb/alpha |
| 叠色顺序 / 作用域 | **先 tint 后 fade，两段独立合成**（fade 前 `SetDrawBright(255,255,255)` 复位 → tint 不污染 fade）；151 只乘负号层（quad.number<0），160/162 溶解是独立 overlay、不逐 quad 相乘 | 逆向/实测 | 已实现 | crates/wolf-game/src/game.rs:1161,1204；crates/wolf-render/src/overlay.rs；crates/wolf-render/src/renderer.rs（freeze/set_overlays） | capture 对照 HUD 是否被 tint/溶解 |
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
现状依据：字号读 Sys8（crates/wolf-game/src/game.rs:1331，范围 8..=64 否则 20）；行高 `line_height(font)=font+trunc(6×min(16,32)/32)=font+3`（crates/wolf-game/src/message.rs:134，`LINE_GAP=6` :45、`BASE_FONT_PX=16` :50）；全/半角 `advance_at(ch,font_px)`（crates/wolf-game/src/choice.rs:115）全角=font_px、半角=0.5*font_px；有 TTF 时 `fontmetrics::FontMetrics::advance` 用 hmtx 的 em_advance*font_px 覆盖近似（crates/wolf-game/src/fontmetrics.rs）；打字机 `revealed=floor((frames−preroll)*cps/60)`（message.rs:268），cps=Sys9（boot 500/CE269 后 120），preroll=Sys10（9/1）；换行 `wrap(text,width,font_px)` 逐字符断行（message.rs:288）。
已知缺口：**禁则是原版本就没有**（4,375 个 ≥64B 函数里对 。、，」等码点零命中，只有显式 '\n' 与行首空格丢弃），因此不实现是正确的；**打字机速率与原版差 2 倍**（RE：每帧 `+0x88 += (60/fps)*speed/30` → 60fps 下 speed/2 字/秒，且无 preroll 减法），但 Sys9→p+0x80 的写入点未定位、本作 CE48 把速度设 500 ≈ 瞬间显示，暂不改（理由见 §3.2、docs/re/TEXT_METRICS.md §3）。
下一步核对：在实机上用长消息（CE 里把 Sys9 调低）录逐帧显字数曲线，确认 2× 关系与 preroll 的有无。

### 2.3 选择面板布局与越界回退（H-MENU-1）
现状依据：常量 `CHOICE_LINE_SPACING=14`（crates/wolf-game/src/choice.rs:24）、`BASE_FONT_PX=16`（:31）、`TEXT_INSET=8`（:38）、`ROW_TOP=6`（:45）、`TEXT_PX=20`（:57）、`CURSOR_SKIN="SystemFile/CursorBase.png"`（:60）、`CURSOR_CORNER=4`（:62），行距 `line_pitch(font)=font+trunc(14×16/32)=font+7`（:70）；`size()` 宽=最宽+2×8、高=6+rows×27（:139）；`build()` 行矩形 [x+8, y+6+idx×27, w−16, 27]、光标框 [x+6, row_y, w−12, font_px]（:153-187）；面板/光标都是九宫格（skin_pieces :288，CursorBase corner 4）；`layout_at_sized`（:211-245）在面板完全屏外时回退居中；`is_title_image_menu`/`title_image_layout` 固定 X=10/Y=400,450,500/W=240/H=52（:256,268）；`game::choice_row_at`（crates/wolf-game/src/game.rs:1301）用同一布局做命中矩形。锚点仍取 Sys3/Sys4（game.rs:1290）：RE 说原版锚点来自 op102 对象字段 +0x8d8/+0x8dc（-1 时用 base×10−w/2 等默认值），本作脚本显式写 Sys3/Sys4，两条路径哪个生效**仍无 C 级证据**，暂保持现状。
已知缺口：**越界回退是本仓策略**（原版无回退、无夹取，RE A 级），保留仅为「标题用 −1000 藏引擎面板」的兜底，属 C 级未闭合假设（docs/re/LAYOUT_METRICS.md §7.1）；超宽选项原版不截断不换行（与仓内一致）。
下一步核对：在标题画面确认 op102 面板是否真的被隐藏（遮挡/坐标），再决定是否删掉居中回退。

### 2.4 1/10 UI 缩放规则
现状依据：`coordinate_scale(screen)->(i32,i32)=((w/32).max(1),(h/24).max(1))`（crates/wolf-game/src/db.rs:159；message.rs:97 同式），1024x576→(32,24)；`LOGICAL_W=1024/LOGICAL_H=576`（crates/wolf-render/src/scaler.rs:21,23）；`ScaleMode{Integer,FitNearest,FitLinear}`（scaler.rs:27-35），`integer_scale`（:97）取 `min(win_w/1024,win_h/576).max(1)` 并居中，`fit_scale`（:134）取 `min(w/1024,h/576)`（<1 允许）。1/10 字符格判定 `Screen::ui_scale_for`（crates/wolf-game/src/picture.rs:1046）：同 chapter(number/1000) 内若存在宽或高 >1024x2/576x2 的非停靠、非 sysgraphic 窗口 picture→返回 10.0，否则 1.0；停靠窗以 `\|x\|>SCREEN_W*2 或 \|y\|>SCREEN_H*2` 判据（:1062-1063）。
块内几何语义（2026-11-02 逆向+实机核对，docs/re/SCREENSHOT_METRICS.md §6）：**x 已由 VM 的 op121 缩放提前除回像素，渲染时不再除**；y/w/h 仍为十分之一，须除 10。实现见 crates/wolf-game/src/atlas.rs:532（window panel dst x 不除、y/w/h 除）与 crates/wolf-game/src/picture.rs quads()（text/sprite 分支同理）。槽框与光标框用 `nine_slice`/`nine_slice_frame`（去中心填充，空心框，crates/wolf-game/src/window.rs），否则 CursorBase 会把整槽铺成黑块。
已知缺口：取整用整除而非 round/floor 的差异在**非 32/24 整数倍**分辨率下**未实测**；`default_origin` 的 `trunc(rateY/10)` 项是**推断**公式。
下一步核对：以 1280x720 等非整数倍分辨率实机截图量像素比；逆向 coordinate_scale 与 UI 缩放的乘除点。

### 2.5 过渡 / 淡入淡出语义
现状依据（已按 RE 落地）：`ScreenTransition{kind,flags,duration,remaining,active,freeze_requested}`——`install(kind,flags)`（crates/wolf-game/src/transition.rs:70）只存参数，`prepare()`（:77）请求冻结当前帧，`execute()`（:86）起跑并把 `remaining` 置 `flags&0xffff` 帧，`alpha()=remaining/duration`（:135，旧帧不透明度 1→0 线性、整数除法、无 easing、无三角波）。opcode 侧 160/161/162 分别映射 `Host::transition_install/prepare/execute`（crates/wolf-vm/src/exec.rs:2115-2134），162 恒 `WaitState::Frames(duration)+Blocked`。本作唯一调用 CE48 `160 [-1,0x0001_000A]` → kind=-1、10 帧、无掩膜（均匀溶解；`wants_mask()` 仅 kind≥0 时为真，本作不可达）。`ScreenTint`：151 普通 ramp 到 `clamp(255+(p−100)*255/100,0,255)/255`（crates/wolf-game/src/tint.rs:106；p≥100 中性，**不是**百分比乘子）；bit24 flash 走独立整屏色块 overlay（:119，alpha=(剩余帧/总帧) 单向衰减）。合成：`apply_screen_tint`（crates/wolf-game/src/game.rs:1204）只把 151 亮度乘到 `quad.number<0`（屏幕层）；160/162 的溶解与新帧由 `screen_overlays()`（game.rs:1161）交给渲染侧 `ScreenOverlay`（crates/wolf-render/src/overlay.rs），CLI 每帧 `renderer.set_overlays()`（crates/wolf-cli/src/play.rs:813,991），161 时先 `renderer.freeze()`（play.rs:983-984，必须在上一帧 present 之后）。每帧 tick 顺序：`screen.tick()→screen.advance()→screen_tint.tick()→screen_transition.tick()`（game.rs:1985-1987）。
已知缺口：掩膜贴图 `[Transition]Fade.png`（640×480 L、单轴线性斜渐变）**未贴图**——本作 kind=-1 不需要；由于 GPU 离屏初始化不可用，play 路径的溶解视觉只在 wolf-render 单测里验证。
下一步核对（如日后用到掩膜过渡）：把 Fade.png 作为 mask 贴到 dissolve 的 alpha 上，并逐帧摄录原版过渡曲线复核。

### 2.6 present / swapchain
现状依据：两 pass（crates/wolf-render/src/renderer.rs:5-14）——Pass1 画进固定 1024x576 Rgba8Unorm 逻辑纹理，Pass2 把该纹理作为单 quad blit 到 swapchain 缩放居中（present :910）；`FRAME_FORMAT=Rgba8Unorm`（:55）刻意非 sRGB 以复现 DxLib 的 gamma 字节空间 alpha 混合（实测 Button01.png rgb0/α191 叠底色 251→gamma 63=retail 截图，linear 136）；present_mode=AutoVsync、latency=2（:196,199）；blit blend=REPLACE、letterbox 由 Pass2 clear BLACK（:566,976）；`capture_rgba` 读回 1024x576 RGBA8（:1041）。帧节奏由 crates/wolf-cli/src/play.rs:35 `FRAME_TIME=16_667µs` 与 `about_to_wait`（:991）驱动，落后>4 帧重置。
已知缺口：本作锁 60Hz/固定网格是否与原版可变帧（DxLib 默认 60）完全一致**未实测**；`window_size_for` 的 6%/10% 留边是本仓播放器策略，原版窗口模式尺寸未知。
下一步核对：抓取原版帧率与窗口尺寸；对比 capture 与实机截图像素（已用于验证 gamma 空间）。

---

## 3 常量清单（C 任务后状态）

2026-11-02 的 Ghidra 反编译已逐条回答这 12 项（结论见 §3.2 表），下表只记"还差什么"：

1. **九宫格内边距** — 已答：帧厚 3 px、无额外 padding；面板内缩实测 **8 px/侧**（RE 的 0x1a=26 与实机量得的宽度差 17.8 冲突，取实测值）。
2. **盒小于帧的退化规则** — 已答：原版不折半、不钳制，交给 blit 裁剪；本作数据不产生 <6 px 盒，**不改**。
3. **禁则字符集** — 已答：**原版没有禁则**（负证据强），仓内不实现即正确。
4. **行距缩放关系** — 已答：`trunc(配置×min(base,32)/32)`；本作 6×16/32=3（文本，实测 23）、14×16/32=7（选择支，实测 27）。已落地。
5. **打字速度语义** — 已答：每帧 `+=(60/fps)*speed/30`，无 preroll；仓内约慢一半。**暂不改**（Sys9→+0x80 写入点未定位、本作速度 500≈瞬间）。
6. **选择面板越界回退** — 已答：原版无回退、无夹取；仓内保留居中兜底（C 级，标题隐藏菜单未验证）。
7. **超宽选项处理** — 已答：无上限、不截断、不换行，超宽伸出屏外靠裁剪；仓内一致。
8. **coordinate_scale 取整** — 已答：整除；仓内 db.rs 等价。
9. **default_origin 的 trunc(rateY/10)** — 已答：原版就是 `17×rateY + rateY/10`（整除），仓内结构一致。
10. **过渡曲线与掩膜** — 已答：单程交叉溶解、线性整数除法、无 easing；掩膜 640×480 单轴斜渐变。本作 kind=−1 无掩膜，已落地。
11. **tint × transition 顺序** — 已答：先 tint 后 fade，两段独立合成；151 是钳制亮度（p≥100 中性），flash 是单向衰减色块。已落地。
12. **present 帧率与窗口尺寸** — 已答：软件限帧 16.6 ms、客户区 1024×576×1.0 居中；仓内一致（窗口留边是播放器策略）。

真正剩下的开放项：打字机 2× 速率（需要实机逐帧曲线）、标题处 op102 面板为何不可见（需要实机确认）、kind≥0 掩膜贴图（本作不可达）。

### 3.1 C 任务（Game.exe 定点逆向）进展与结论

工具链（2026-11-02 更新）：已装 **Ghidra 12.2 + Temurin JDK 25**（D:\Program，见 RE_GAME_EXE.md §8），完成 Game.exe 全量自动分析（238 s / 10,589 函数）与 4,375 个函数的 C 伪码导出；早期用 `pefile`+`capstone` 自建只读工具 `tools/re/wolfpe.py` 的结论仍然有效。完整证据见 **`docs/RE_GAME_EXE.md`**（工具链/函数地图）与 **`docs/re/`** 下四份专项报告。

已从二进制/随附资源**直接核对**（详见 RE_GAME_EXE.md §2–§4）：

- 引擎身份：**WOLF RPG Editor ver2.22（Editor 构建 20180525）**，DxLib 静态链接单文件 exe。
- 呈现后端：GDI 软件光栅（`CreateDIBSection`/`StretchDIBits`/`SetDIBitsToDevice`），**无 d3d9/d3d11/dxgi 导入 → 无 swapchain**（对应 §1.6 / §3-12 的 present 部分）。
- 文本度量：走 GDI（`GetTextExtentPoint32W`/`GetTextMetricsA`/`GetGlyphOutlineW`）；字体以 `FindFirstFileA("*.ttf")` 枚举数据目录加载（对应 §2.2 字体来源）。
- 九宫格：`WindowBase.png` 实测 18x18、3px 对称边框 → `CORNER=3`、无额外 padding（对应 §3-1）。
- 过渡掩膜：`[Transition]Fade.png` 实测 640x480、8-bit 灰度（对应 §3-10 资源部分）。
- 分辨率：数据驱动（运行时有 `[Read]Screen size X` 调试串；`assets --db-defaults` 已导出 1024x576）。

2026-11-02 已完成 12 项中的大部分（见下 §3.2）；剩余项标“待实测/待定位”并写明具体的验证路径。

### 3.2 Ghidra 反编译结果（2026-11-02）

证据等级：**A**=二进制/数据直读，**B**=由 A 推出，**C**=仅否定证据或需实机。详见 `docs/re/RUNTIME_CONSTANTS.md`、`TEXT_METRICS.md`、`LAYOUT_METRICS.md`、`TRANSITION.md`。

| # | 项 | 原版结论 | 仓内现状/差异 | 等级 | 证据 |
|---|---|---|---|---|---|
| 1 | 九宫格内边距 | 皮肤 18×18、**3 px 对称九宫格**，绘制只有“角固定 + 中行列拉伸”，**无额外 padding**；文本位置来自 Sys1/Sys2；体区 alpha=223（必须混色）。选择支面板的固定内缩 = `0x1a` = **26 px**（`FUN_004c3d20:59-72`） | `window.rs` CORNER=3 正确；`choice.rs` 已改为实测内缩 **8/侧**（RE 0x1a 与实机宽度差冲突，取截图值），光标改用 CursorBase 九宫格 | A/实测 | `docs/re/RUNTIME_CONSTANTS.md` §4、`LAYOUT_METRICS.md` §3 |
| 2 | 盒小于帧退化 | 原版**不折半、不钳制**：中段宽 = right − corner，可 ≤0，交给 blit 裁剪 | `window.rs:80` 角折半 `min(cw,w/2)` 是仓内自造 | C | `LAYOUT_METRICS.md` §4 |
| 3 | 标点避头尾（禁则） | 全量 dump（4,375 函数）**没有任何禁则字符常量**（0x3002/0x3001/0xFF0C/0x300C/0x300D/0xFF09/0x3010 零命中）；文本渲染只有显式 `'\n'` 分支 + 行首空格丢弃 → **原版无禁则** | 仓内 wrap() 无禁则，一致 | B（负证据强） | `TEXT_METRICS.md` §3 |
| 4 | 行距缩放 | `line_pitch = 本行最大字号×S + trunc(行距配置×min(基准字号,32)/32)×S`；本作 Game.dat 行距配置=6、基准字号=16 → **额外行距 = 3 px**（即 16 号字行高 19，不是 22/26） | `message.rs:122` `font+6` **只在基准字号≥32 时等价**；基准 16 时应为 `font+3` | A（公式）/B（运行值） | `TEXT_METRICS.md` §1 |
| 5 | 打字机 cps/preroll | 显示门限是 double 水位 `+0x88`；每帧 `水位 += DAT_0084b244 × speed / 30`；60 fps 下 **speed/2 字/秒**；**没有 preroll 减法**（用 `+0xe8` 帧片倒计时） | `message.rs:268` `(frames-preroll)*cps/60` → **约为原版一半速度**，且多了一个原版不存在的 preroll 项 | B/部分 | `TEXT_METRICS.md` §4 |
| 6 | 选择面板越界回退 | op102 全链已定位：`FUN_00450460` case 0x66 → `FUN_00452970` → 尺寸 `FUN_004c3d20` / 锚点 `FUN_004c3fa0` / 绘制 `FUN_004c40f0` / 选行 `FUN_004c35c0`。原版**无回退、无夹取**：锚点来自选择支对象字段 `+0x8d8/+0x8dc`（默认 `(fontbase*10 − w/2, 0xaa/scale − h/2)`），**不读 Sys3/Sys4**；越界就按锚点画、被屏裁剪 | `choice.rs` 居中兜底保留（C 级）；锚点仍取 Sys3/Sys4（本作脚本显式写，RE 的对象字段路径未与本作调用对上）；标题为何看不到面板仍有 1 处未闭合（LAYOUT §7.1） | A | `LAYOUT_METRICS.md` §5 |
| 7 | 超宽选项 | 布局侧**无最大宽、无截断、无换行**：面板宽 = 最宽选项 + 26，超宽伸出屏外被裁剪 | 仓内已无上限、无 MIN_WIDTH；加数为 2×8=16（原版 0x1a=26，差异记在 choice.rs 头注释与 LAYOUT §5） | A | `LAYOUT_METRICS.md` §6 |
| 8 | coordinate_scale 取整 | **整除（i32 `idiv`，向零截断）**：`Sys116/32`、`Sys117/24`（CE48 pc30/31，op121 bits=0x3000=div）；320×240/640×480/800×600 另硬编码 10/20/25 | `db.rs:159` u32 整除**等价**（多了 `.max(1)`）；`message.rs:97` f32 除法在非 32/24 整倍数屏会偏 | A | `LAYOUT_METRICS.md` §1 |
| 9 | default_origin 的 trunc(rateY/10) | **确认是原版公式**：`Sys2 = 17×rateY`，再 `Sys2 += rateY/10`（CE63 pc44-46，bits 0x3100 = 加 + 整除） | `message.rs:111` 结构一致但 rate 为浮点、取整口径不同 | A | `LAYOUT_METRICS.md` §2 |
| 10 | 过渡曲线与掩膜 | 语义 = **单程交叉溶解**：161 先把当前画面截图，162 用 mask/alpha 把旧帧溶解到新帧；`t = elapsed/duration` 是**线性整数除法，无 easing、非三角波**（`FUN_004c2a80` 13 行 + `FUN_004c28d0` 31 行），`elapsed` 每帧减 `DAT_0084b244`（60/fps）。掩膜 `[Transition]Fade.png` = 640×480 L、**单轴线性斜渐变**（等值线 x≈-0.397y+c，残差<1.2 px，方向≈21.5°，过渡带≈272 px，灰阶 0..251、峰值 250/251，无边框/图案/噪点）；拉伸到 1024×576 后斜率≈0.299。本作脚本唯一 transition 是 **kind=-1（无掩膜、均匀 alpha 溶解）** | 已改为单程溶解（`alpha=remaining/duration`）+ 渲染侧 overlay；本作 kind=-1 走均匀溶解 | A | `RUNTIME_CONSTANTS.md` §3、`TRANSITION.md` §1–§3 |
| 11 | tint × transition 顺序 | **先 tint 后 fade，两段独立合成、不是逐像素相乘**：151 是 DxLib `SetDrawBright` 的绘制状态（`FUN_004bf5b0→FUN_005161e0`），fade 是画完场景后叠的旧帧 overlay（`FUN_004c28d0` 开头先 `SetDrawBright(255,255,255)` 复位 → tint 不污染 fade）。另：151 语义是 `bright=clamp(255+(p-100)*255/100,0,255)`（p>100 被钳到中性），**不是百分比乘子**；flash(bit24) 不是三角波，而是整屏色块 overlay、alpha=(剩余帧/总帧)*255 单向衰减 | 已改为钳制亮度 + 单向衰减 flash overlay；fade 从 `apply_screen_tint` 剥离到独立 overlay 阶段 | B | `TRANSITION.md` §4–§5 |
| 12 | present 帧率与窗口尺寸 | 引擎**软件限帧 16.6 ms/帧（≈60 fps 上限）**：`timeGetTime`+1 ms 定时器 + QPC 忙等，非 vsync；帧步进 `DAT_0084b244 = 60/fps`（本机 fps=60）。窗口客户区 = **数据屏幕尺寸 1024×576 × 1.0**，`AdjustWindowRectEx` 后按显示器居中；Game.ini 只有 10 个键、**无尺寸/缩放项**；无任何 DPI 感知 API（150% 系统 DPI 虚拟化） | 仓内 `FRAME_TIME=16_667µs` 与原版 16.6 ms 一致；窗口留边是播放器策略，原版是 1:1 + 居中 | A/部分 | `RUNTIME_CONSTANTS.md` §2、`RE_GAME_EXE.md` §9 |

**据此的代码动作（落地状态）**：

| 项 | 动作 | 状态 |
|---|---|---|
| `transition.rs` | `brightness=|2t-1|` 三角波 → 单程 `alpha=remaining/duration`；160/161/162 拆成 install/prepare/execute 三阶段；flags 读 `& 0xffff`、bit16 建模为 wait | **已落地**（2026-11-02，含单测） |
| `exec.rs` | Host trait 的 `transition(kind,flags)` 拆成 `transition_install` / `transition_prepare` / `transition_execute` | **已落地** |
| `tint.rs` | 151 改为 `SetDrawBright` 钳制公式（p≥100 中性）；flash 改为单向衰减的整屏色块 overlay；fade 从 tint 里剥离 | **已落地** |
| 渲染侧 | fade/溶解不再逐 quad 相乘，改为独立 overlay 层：`freeze()` 冻上一帧 + `set_overlays()` 叠 `Colour`/`Frozen` | **已落地**（`crates/wolf-render/src/overlay.rs`、`renderer.rs`；CLI capture 与 play 两条路径已接线） |
| `message.rs` 行距 | LINE_GAP 保留为 Game.dat 设定值 6，`line_height` 改为 `font + trunc(6×min(base16,32)/32) = font+3` | **已落地**（实机 101 窗口行距 23.0 = 20+3；单测 20→23、14→17） |
| `message.rs` 打字机 | 按 `speed/2 字/秒` 且去掉 preroll | **暂不改**：Sys9→p+0x80 的写入点未定位，且本作 CE48 把速度设成 500（≈瞬间），改动的风险大于收益；已在 TEXT_METRICS §4 记录 |
| `choice.rs` | 内缩 8/侧、宽=最宽+16、无 MIN_WIDTH、行距 27、行起点 +6、去 "▶ " 前缀、光标换 CursorBase 九宫格 | **已落地**（实测 4 行 156×114、5 行 162×141，行距 27.18/26.87；居中回退先保留，LAYOUT §7.1） |
| `window.rs` | 极小盒的“角折半”与原版不同（原版交给 blit 裁剪） | **不改**：本作数据不产生 <6 px 的盒，属于本作不触发的通用路径 |
| 掩膜过渡（kind≥0） | 原版用 `[Transition]Fade.png` 斜渐变掩膜 | **不实现**：全作只有 1 次 op160 且 kind=−1，掩膜路径在本作不可达 |

---

## 4 获取途径与优先级

**官方说明书（已覆盖）**：安装目录 `manual01..06.jpg` 六页（概述/操作/职业、流程/妹妹状态、哥哥状态/道具、夜间互动界面、游戏数据/收集、截图致谢），只给**操作方式、流程与玩法数值**，不含引擎几何/渲染常量。已有逐条核对见 docs/M3_MANUAL_ALIGNMENT.md（只核对界面/流程/数值，状态取值 已实现/待实现/不适用）。因此九宫格、文本度量、choice 回退、1/10 缩放、过渡、present 这些"引擎几何"**说明书中没有**，需另寻途径。

**参考实现（docs/vendor/uberwolf-ref，仅解码格式）**：现含 `DXLib/DXArchiveVer6.*`、`DXLib/Huffman.*`、`DXLib/DXArchive.h`、`UberWolfLib/WolfDec.*`、`dw8_verify.py`、`dw2_header.py` 等，全部只覆盖 **.wolf 归档解码 / 数据格式**，**不覆盖渲染、窗口几何或文本度量**。故不能作为几何常量的来源。

**黑盒实测（首选、低成本）**：游戏内 PrintScreen（Game.ini `ScreenShotFlag=1`，产物在安装目录，**1024x576 原生**）逐帧/逐像素测量；结合游戏内已知坐标（菜单按钮、消息框、状态面板）反推内边距、行距、面板落点与缩放倍率。仓库内已有 docs/REFERENCE.md 的 10 张实机截图目录可复用。注意：headless capture 的 wgpu 离屏初始化目前卡死，仅用于读回纹理，不作视觉核对主路径。

**逆向（适合验证硬编码常量）**：本仓已备好只读静态分析工具 **`tools/re/wolfpe.py`**（`pefile`+`capstone`：PE 事实/字符串/绝对地址 xref/前向反汇编），并产出 **`docs/RE_GAME_EXE.md`**（含 Game.exe SHA-256、引擎版本 ver2.22、导入表与已核对项）。该工具适合验证"说明书没有、实测难分离"的量——九宫格绘制参数、文本度量常量（行长/禁则表）、choice 越界回退阈值、`coordinate_scale` 乘除点、过渡曲线与掩膜资源、present 帧率/窗口尺寸。做法：定位 Game.exe 中对应绘制/布局函数，取立即数常量并与本仓 `文件:行` 的取值比对。

**优先级建议**：(1) 先实测高频可见项——九宫格内边距、行距、标题图片菜单坐标（影响每帧 UI 观感）；(2) 再实测文本换行/打字机曲线（影响对话可读性）；(3) 对难以实测的禁则、回退阈值、过渡曲线与掩膜，排入逆向任务（对应第 3 节 12 项）。