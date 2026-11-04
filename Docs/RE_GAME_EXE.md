# RE_GAME_EXE.md — 原版 Game.exe 定点逆向记录（C 任务）

本文件记录对原版运行时 `Game.exe` 的**只读静态逆向**结果，用于核对 `docs/ENGINE_BEHAVIOR.md` §3 中"数据外部、只能靠逆向后实测确认"的引擎常量。与 `ENGINE_BEHAVIOR.md` 配套：那边是清单，这边是逆向证据与结论。

> 内容安全：本文只做二进制/资源层的技术描述，不涉及游戏内容。

---

## 0 结论摘要

1. **工具链现状**：`rea-agents` v6.7.0 可本地运行，但本机**没有可用的原生分析引擎**——`hopper` 仅 macOS、`ghidra` 未安装（`GHIDRA_INSTALL_DIR` 未设）、`ida-registration` 未配置、`kuna`/`jadx` 未设；`rea doctor` 报 `healthy:false`。因此 rea 的 `decompile`/`analyze`（依赖 Ghidra/IDA/Hopper/Kuna）在本机不可用，`inspect-binary-layout` 也只支持 ELF、不支持本作的 PE32。
2. **替代方案**：用本机已有的 `pefile 2024.8.26` + `capstone 5.0.7` 自建只读静态分析工具 **`tools/re/wolfpe.py`**（解析 PE、枚举字符串与导入、按绝对地址/字符串字面量定位代码引用、前向反汇编）。全部产物可复现、不执行目标。
3. **已从二进制/随附资源直接核实的架构事实**：引擎为 **WOLF RPG Editor ver2.22（Editor 构建 20180525）**；DxLib **静态链接**进 `Game.exe`；运行时**走 GDI 软件光栅**（`CreateDIBSection`/`StretchDIBits`/`SetDIBitsToDevice`），**不含 d3d9/d3d11/dxgi/opengl/ddraw 导入**，即 §1.6 的 present/swapchain 实为 DIB 位块传输、无交换链；文本度量走 GDI（`GetTextExtentPoint32W`/`GetTextMetricsA`）；字体以 `FindFirstFileA("*.ttf")` 从数据目录枚举文件加载。
4. **已核对/收敛的 §3 项**：九宫格 3px 帧厚（皮肤 `WindowBase.png` 18x18、逐像素 3px 对称边框）、过渡掩膜资源形态（`[Transition]Fade.png` 640x480 8-bit 灰度）、present 后端（GDI DIB）、字体来源、分辨率数据驱动。
5. **仍需 Ghidra 反编译或逐帧实测的项**：行距缩放关系、禁则字符集、选择面板越界阈值与超宽处理、coordinate_scale 取整、default_origin 的 `trunc(rateY/10)` 项、过渡曲线 easing 与 tint×fade 顺序、原版帧率/窗口初始尺寸等（详见 §5）。

一句话：**架构级与资源级常量已坐实；纯数值级 UI 常量在没有反编译器的前提下无法从二进制稳定取出**，需要装 Ghidra（或逐帧实测）才能闭环。

---

## 1 工具与方法

### 1.1 rea 探测结果

```
npx rea-agents doctor        -> healthy:false
npx rea-agents providers     -> native-macos(全 false) / rea-artifact-graph / rea-dotnet-static / sqlite
npx rea-agents inspect-binary-layout --help -> 仅接受 ELF 文件/可重定位目标
```

缺失引擎：hopper（mac-only）、ghidra（`GHIDRA_INSTALL_DIR` 未设，需 Ghidra 12.1.x）、ida-registration（未配置）、kuna、jadx。
可无引擎运行的 rea 子命令：`inspect-pe-resources`、`inspect-artifact`（已能正确解析本 PE 头/资源）。

### 1.2 自建工具 tools/re/wolfpe.py

依赖 `pefile` + `capstone`（本机已有）。只读、不执行目标。

```bash
GAME='/e/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver/Game.exe'

python tools/re/wolfpe.py "$GAME" facts                 # PE 身份/段表/导入/版本串（JSON）
python tools/re/wolfpe.py "$GAME" strings --filter '\.ttf' --min 4
python tools/re/wolfpe.py "$GAME" xref --string '*.ttf' --disasm --length 90
python tools/re/wolfpe.py "$GAME" xref --va 0x7c6ec8 --disasm
python tools/re/wolfpe.py "$GAME" disasm --va 0x46a21d --length 128
```

原理：PE32 无重定位干扰，代码对字符串/对象用**绝对 VA** 立即数引用，故在 `.text` 内搜索目标 VA 的 4 字节小端即可定位引用点；若命中前 1 字节为 `0x68` 则是 `push imm32`（即字符串字面量参数），从该指令起前向反汇编。

### 1.3 证据目录

原始输出（PE 事实 JSON 等）保存在 `.recon/`（已被 `.gitignore` 忽略，不入库）；可复现结论以本文与脚本为准。

---

## 2 二进制身份

| 项 | 值 |
|---|---|
| 路径 | `E:/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver/Game.exe` |
| SHA-256 | `e0716a35323007c79e6033bc19c610a38e1d4ccc0dce47c6f79cf706853e5b76` |
| 大小 | 6,365,184 字节 |
| 格式 | PE32，machine `0x14c`(i386)，subsystem 2(GUI)，ImageBase `0x400000` |
| 时间戳 | 2018-06-22 11:38:48 UTC（`0x5B2CC2C8`） |
| 段 | `.text` RVA 0x1000 / vsize 0x3b2461；`.rdata` 0x3b4000 / 0x96b2c；`.data` 0x44b000 / 0x6fecc0；`.rsrc` 0xb4a000 / 0x1710 |
| 引擎版本串 | `Editor - 20180525_ver2.22`；`WOLF RPG EDITOR`；`[Ver2.00` |
| 链接方式 | DxLib **静态链接**（无 DxLib.dll 导入；`.rdata` 内含 DxLib 源码路径如 `..\Source\Library\Main\DxFont.cpp`） |

结论：本作运行时 = **WOLF RPG Editor ver2.22**（2018-05-25 构建）静态链接 DxLib 的单文件 exe。这为"引擎行为"研究提供了明确的版本锚点。

---

## 3 导入表 → 渲染/文本后端

`Game.exe` 只导入系统 DLL：KERNEL32(140)、USER32(81)、GDI32(28)、SHLWAPI(1)、SHELL32(5)、WININET(5)、WINMM(1)。**没有** d3d9/d3d11/dxgi/opengl/ddraw 导入。

- **光栅/呈现 = GDI 软件路径**：`CreateDIBSection`、`StretchDIBits`、`SetDIBitsToDevice`、`CreateDCW`、`GetDeviceCaps`。DxLib 的 D3D9/D3D11 代码虽被编译进 exe，但未通过导入实际启用 → 本作呈现就是 "画进 DIB → 位块贴屏"，**没有 swapchain、没有硬件 vsync 交换链语义**。
- **文本 = GDI**：`CreateFontW`、`TextOutW`、`GetTextExtentPoint32W`、`GetTextMetricsA`、`GetGlyphOutlineW`、`EnumFontFamiliesExW`、`AddFontResourceExA`。→ 字宽/换行度量基于 GDI 文本度量（与 `message.rs`/`fontmetrics.rs` 的方向一致）。
- **字体来源 = 数据目录文件**：`.text` @0x46a21d 处 `push "*.ttf"` 后 `call [0x7b40d0]`，而 `0x7b40d0 = KERNEL32!FindFirstFileA`——即运行时用通配符枚举数据目录下的 `*.ttf` 再逐个加载。仓库 `work/Data` 下确有 2 个 ttf（`07やさしさゴシックボールド.ttf` 2.3 MB、`GenJyuuGothicX-P-Bold.ttf` 11.5 MB），与"字体随数据携带"一致。

反汇编片段（`xref --string '*.ttf' --disasm`）：

```
0046a21d: 6834037d00        push 0x7d0334          ; "*.ttf"
0046a222: ff15d0407b00      call dword ptr [0x7b40d0]   ; KERNEL32!FindFirstFileA
0046a228: 8985141cffff      mov  dword ptr [ebp-0xe3ec], eax ; handle
0046a22e: 83bd101cffff01    cmp  dword ptr [ebp-0xe3f0], 1
0046a235: 7518              jne  0x46a24f
0046a237: 8d8514c1ffff      lea  eax, [ebp-0x3eec]
0046a23d: 51                push ecx
0046a23e: 683c037d00        push 0x7d033c          ; 第二个通配/子目录
0046a243: ff15d0407b00      call dword ptr [0x7b40d0]   ; FindFirstFileA again
```

---

## 4 已核对的 §3 项

| §3 项 | 逆向/资源结论 | 证据 | 状态 |
|---|---|---|---|
| 1 九宫格内边距 | 皮肤 `SystemFile/WindowBase.png` = **18x18**，逐像素为 **3px 对称边框**（0/1/2 行列为边线，3..14 为体），`CORNER=3` 正确，**无额外 padding**；文本原点由数据 `Sys1/Sys2=(64,410)` 决定 | 见下方像素网格；`window.rs:27,30` | ✅ 已核对 |
| 10 过渡掩膜 | `SystemFile/[Transition]Fade.png` 实际为 **640x480、mode L（8-bit 灰度）**，与清单描述一致；"调暗 vs 掩膜图案"的**曲线语义**未解 | `PIL` 读取尺寸/模式 | ◐ 资源已核对，语义待解 |
| 12 present 后端 | 运行时 = **GDI DIB 位块**（`CreateDIBSection`/`StretchDIBits`/`SetDIBitsToDevice`），**无 swapchain/vsync**；原版帧率是否锁 60 及窗口初始尺寸仍未取到 | 导入表（§3） | ◐ 后端已核对，帧率/窗口待测 |
| 2.2 文本度量 | 走 **GDI** `GetTextExtentPoint32W`/`GetTextMetricsA`/`GetGlyphOutlineW`；`line_height=font+6` 的具体 +6 常量未从二进制取到 | 导入表 | ◐ 机制已核对，数值待取 |
| 2.2 字体文件 | 运行时 `FindFirstFileA("*.ttf")` 从数据目录枚举 ttf；`work/Data` 下 2 个 ttf | 反汇编 @0x46a21d | ✅ 已核对 |
| 1.4 分辨率 | 数据驱动（运行时有 `[Read]Screen size X` 调试串，屏幕尺寸来自 DB/Game.dat，非硬编码）；`--db-defaults` 已导出 screen=1024x576 | 字符串 + `assets --db-defaults` | ✅ 已核对 |

### 4.1 皮肤像素网格（证明 3px 帧厚）

`work/Data/SystemFile/WindowBase.png`（18x18，颜色图例见下）逐像素：

```
ABBBBBBBBBBBBBBBBA     A=(255,255,255,0)   透明角
BCDDDDDDDDDDDDDDCB     B=(66,66,66)        0x424242 外暗线
BDEFFFFFFFFFFFFEDB     C=(136,136,136)     0x888888
BDFGGGGGGGGGGGGFDB     D=(242,243,243)     0xf2f3f3 亮棱
BDFGGGGGGGGGGGGFDB     E=(217,220,221)     0xd9dcdd
BDFGGGGGGGGGGGGFDB     F=(87,96,98)        0x576062 过渡线
...（体区 3..14 共 12x12，G=(31,36,37,223)）...
BDFGGGGGGGGGGGGFDB
BDEFFFFFFFFFFFFEDB
BCDDDDDDDDDDDDDDCB
ABBBBBBBBBBBBBBBBA
```

外层第 0/1/2 行与第 0/1/2 列构成 **3 像素**对称边框，中部为 12x12 可拉伸体 → 九宫格角尺寸 3，与 `crates/wolf-game/src/window.rs` 的 `CORNER=3`、`SKIN="SystemFile/WindowBase.png"` 完全一致（该模块文档亦已记录这三行颜色）。

---

## 5 仍需 Ghidra / 逐帧实测的项

以下数值级常量无法靠"字符串/资源锚定 + 前向反汇编"稳定取出，需安装反编译器（Ghidra 12.1.x + JDK21，接 rea 或 headless）或逐帧实测：

- §3-2 盒小于帧的退化（角折半阈值/像素分配）
- §3-3 标点避头尾（禁则字符集与挤压规则）
- §3-4 行距与字号的缩放关系（恒 +6 还是 ×系数）
- §3-5 打字机 cps/preroll 精度
- §3-6 选择面板越界回退阈值（完全越界才居中 vs 部分越界）
- §3-7 超宽选项处理（截断/滚动/强制换行）
- §3-8 coordinate_scale 取整方式（整除/floor/round）
- §3-9 default_origin 的 `trunc(rateY/10)` 项
- §3-10 过渡曲线 easing / 掩膜图案语义
- §3-11 tint × transition 叠加顺序
- §3-12 原版帧率锁与窗口初始尺寸

这些多为"立即数常量"或"分支阈值"，在 3.9 MB 无符号 `.text` 中缺乏字符串/资源锚点，线性前向反汇编不足以定位函数语义；需要真正的函数级反编译/交叉引用图。

---

## 6 复现步骤

```bash
cd '/e/Study/github program/Imouto Life'
GAME='/e/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver/Game.exe'
python tools/re/wolfpe.py "$GAME" facts | tee .recon/game_facts.json
python tools/re/wolfpe.py "$GAME" xref --string '*.ttf' --disasm
python - <<'PY'
from PIL import Image
im=Image.open("work/Data/SystemFile/WindowBase.png"); print(im.size, im.mode)
im2=Image.open("work/Data/SystemFile/[Transition]Fade.png"); print(im2.size, im2.mode)
PY
```

## 7 附：版本与哈希

- 引擎：WOLF RPG Editor **ver2.22**（Editor 构建 **20180525**）
- Game.exe SHA-256：`e0716a35323007c79e6033bc19c610a38e1d4ccc0dce47c6f79cf706853e5b76`

---

## 8 Ghidra 反编译工具链（2026-11-02 安装）

按"软件装 D 盘 Program"的约定，反编译工具链装在 **D:\Program**，不放进仓库（仓库只放脚本与结论）。

| 组件 | 版本 | 安装路径 | 说明 |
|---|---|---|---|
| Ghidra | **12.2 PUBLIC**（20261016 构建） | `D:\Program\ghidra_12.2_PUBLIC` | 569 MB zip 解压；官方要求 **JDK 25+** |
| Temurin JDK | **25.0.5+8** | `D:\Program\Java\jdk-25.0.5+8` | Ghidra 运行时 |
| Temurin JDK | **21.0.13+9** | `D:\Program\Java\jdk-21.0.13+9` | 备用（java 21 语法编译/其它工具） |

`tools/env.sh` 新增 `GHIDRA_INSTALL_DIR`、`GHIDRA_JAVA_HOME`、`JAVA21_HOME` 三个变量（只在 `source tools/env.sh` 后生效）。

### 8.1 两个必踩的坑（已绕开）

1. **Ghidra 12.2 需要 JDK 25，不是 21**。用 JDK 21 启动会报 `JDK 25+ (64-bit) could not be found`。JDK 21 保留但不用作 Ghidra 运行时。
2. **Git-Bash 下不能直接跑 `support/analyzeHeadless`**：msys 版探测 JDK 失败（`JAVA_HOME ... unsupported java version`）。必须走 `support/analyzeHeadless.bat` + `cmd.exe`，并且 `cmd` 的参数循环开了 `EnableDelayedExpansion`，会吃掉参数里的 `!`，`.bat` 的 `%` 展开会吃掉 `%d`。**脚本参数一律写 UTF-8 args 文件传进去**（`tools/re/ghidra/DumpByAnchor.java --argsfile=`）。
3. 项目目录路径不能含 `!`（`E:\EROGAME\Imouto! Life ...`）：先把 `Game.exe` 复制成无特殊字符路径（本仓用 `work/out/ghidra/input/Game.exe`，SHA-256 不变）再 import；否则解析出的路径会少一个 `!`。

### 8.2 导入与自动分析

```bash
# project: work/out/ghidra/proj/ImoutoLife（已 gitignore）
JAVA_HOME='D:\Program\Java\jdk-25.0.5+8' \
  D:/Program/ghidra_12.2_PUBLIC/support/analyzeHeadless.bat \
  "E:\Study\github program\Imouto Life\work\out\ghidra\proj" ImoutoLife \
  -import "…/work/out/ghidra/input/Game.exe" -max-cpu 16
```

结果（16 CPU / 32 逻辑核，16 GB 内存）：**自动分析 238 s**，识别 **10,589 个函数**（x86:LE:32:default，ImageBase 00400000）。随后用 post-script 全量反编译导出 **4,375 个 ≥64 字节函数**的 C 伪码到 `work/out/re_all/all/`（含 `index.tsv`），供 grep 定位常量。

### 8.3 脚本

| 文件 | 作用 |
|---|---|
| `tools/re/ghidra/DumpByAnchor.java` | 字符串锚点/VA → 引用点 → 所属函数 → 反编译落盘（`--argsfile` 传参、`--ref-window` 处理块中间引用） |
| `tools/re/ghidra/DumpAll.java` | 全量函数反编译（`--min-size`/`--filter`/断点续跑） |
| `tools/re/ghidra/run_ghidra.sh` | 生成 .bat + `cmd //c` 调 `analyzeHeadless.bat`，项目/程序名/`-noanalysis` 已固化 |
| `tools/re/ghidra/README.md` | 用法与参数表 |

### 8.4 复现

```bash
cd '/e/Study/github program/Imouto Life' && source tools/env.sh
bash tools/re/ghidra/run_ghidra.sh --help
bash tools/re/ghidra/run_ghidra.sh --out-dir=work/out/re_dump \
  --anchor='[Read]Screen size X' --anchor='*.ttf'
```

> 同一时刻只能有一个进程持有 Ghidra 项目锁；并发 `analyzeHeadless` 会报 `Unable to lock project`。


---

## 9 Ghidra 反编译结论（2026-11-02，C 任务续）

工具链见 §8。项目 `work/out/ghidra/proj`，全量 dump `work/out/re_all/all/…`（4,375 个 ≥64B 函数）。下列地址均为镜像内绝对 VA（ImageBase 0x400000）。

### 9.1 关键函数地图（已定位、可复现）

| 函数 | 大小 | 作用（由反编译内容判定） |
|---|---|---|
| `FUN_00469820` | 7,668 B | 启动初始化：枚举 `*.ttf` 加载字体、确定屏幕倍率、帧步进、配置文件写出 |
| `FUN_00494480` | 27,671 B | **文本渲染主函数**：逐字节处理 WOLF 文本控制码（0x01…0x1f）、按字符推进 x/y、"Can't Draw Message." |
| `FUN_0049b440` | 225 B | **字号钳制/取整**：按版本与倍率把字号夹到 2…200（倍率 2）或 4…400（倍率 1），并做小字号避让（4→3、5→6、8→7、0xa→9、0xb→9/10、0xd→0xc、0x12→0x11、0x16→0x15、0x1a→0x19） |
| `FUN_0049adc0` | 1,022 B | 字体/绘图状态设置（DxLib 字体句柄、颜色、clip） |
| `FUN_0049b230` | 519 B | 渲染器复位/时间基准初始化 |
| `FUN_00401c50` | 88,144 B | DB 读取 + 大型字符串表初始化（`[Read]Screen size X` 等调试串都在这里） |
| `FUN_0042fe30` | 9,967 B | **标题菜单绘制/布局**（行距 `0x1e`=30、面板 0x294×0xdc、x=10、窄屏分支） |
| `FUN_0043e5f0` | 3,251 B | 面板参数默认值表（`0xaa`、`DAT_0084b264*10`、`0xffffffff` 表示"用默认"） |
| `FUN_0044b0a0` | 约 700 B | 滚动步进：`((a*b*c*0x40)/DAT_0084b244)/10` |
| `FUN_00488310` | 49,438 B | 解释器/事件主循环（调用文本渲染器） |
| `FUN_0042b1d0` / `FUN_0042baa0` | 2,250 / 580 B | Game.ini 读取 / 写出（10 个键的模板） |
| `FUN_00513580` | 5,347 B | DxLib 窗口创建（`RegisterClassExW`→`AdjustWindowRectEx`→`CreateWindowExW`→居中） |
| `FUN_00595780` | 1,901 B | DxLib 字体创建（`CreateFontW` + `GetTextMetricsA`，width=100 权重，`ＭＳ ゴシック` 回退） |
| `FUN_005960c0` / `FUN_00596000` | 1,119 / 191 B | DxLib 字形度量（`GetTextExtentPoint32W`/`GetGlyphOutlineW`/`GetTextMetricsA`） |

### 9.2 从反编译直接读出的公式/常量

1. **帧步进**：`DAT_0084b244 = 0x3c / *DAT_00a16684`（`FUN_00469820`）。`DAT_0084b244` 是全引擎统一的"每帧时间单位"：动画时钟 `FUN_00443770` 用它加减、`FUN_0042c8b0` 用"经过毫秒 / 它"换算帧数、`FUN_0044b0a0` 的滚动步进也除它。→ 原版时间轴以 **60 帧/秒** 为基准量化（对应 §3-12 与 §3-5）。
2. **屏幕倍率**：`DAT_0084b248 = 1`，仅当数据里的屏幕尺寸恰为 **320×240**（0x140/0xF0）时置 2；`DAT_0084b230 = 屏宽 × 倍率`、`DAT_0084b234 = 屏高 × 倍率`（`FUN_00469820`）。本作数据 1024×576 → 倍率 1。
3. **字号基准**：`DAT_0084b264` 取 0x28 / 0x20 / 0x10（由数据里字体标志字节决定）；该值与"×10"、"×2×坐标"等组合出现在面板/滚动公式里（`FUN_0043e5f0`、`FUN_004431…` 系列）。
4. **文本行推进**（公式已由 TEXT_METRICS 定案）：换行时 `y += row_px * (DAT_0084b248<<1)/2`（= 本行最大钳制字号 × 倍率），普通窗口再追加 `y += trunc(line_spacing_cfg × min(base_font_cfg,32)/32) × 倍率`。本作 Game.dat 行距配置=6、基准字号=16 → 额外 3 px；渲染器里**不存在固定的 `+6`**，`message.rs` 的 `font+6` 只在基准字号 ≥32 时等价。详见 `docs/re/TEXT_METRICS.md` §1。
5. **标题菜单几何**：`local_20 = 10`（x）、`local_14 = 0xdc`（220，高）、`local_30 = 0x294`（660，宽）；窄屏（`DAT_0084b264==0x10 && 倍率==1`）改为 x=9、高=0xa0、宽=0x140；行距/网格分母为 `0x1e`(30)，菜单区 y 基准 500（屏宽 <801 时）/630（否则），文字位置随 `(屏宽 × 30)/屏高` 计算。
6. **窗口创建**：客户区 = 屏幕尺寸 × 倍率，`AdjustWindowRectEx` 加非客户区，按显示器居中（`(display - window)/2`），用动态绑定的 `CreateWindowExW`；全屏走 `ChangeDisplaySettingsA`。
7. **字体来源**：`FindFirstFileA("*.ttf")` 枚举数据目录 + `AddFontResourceExA`；DxLib 的字体对象记录 `tmHeight`、`tmAscent` 等（`DAT_00ddb2fc…`），字形推进用 `GetGlyphOutlineW` 的 `gmCellIncX`。

### 9.3 与 §3 清单的对应

运行期/资源侧的取证（帧率、窗口、掩膜、皮肤）见 **`docs/re/RUNTIME_CONSTANTS.md`**；文本度量见 **`docs/re/TEXT_METRICS.md`**、布局缩放见 **`docs/re/LAYOUT_METRICS.md`**、过渡/叠色见 **`docs/re/TRANSITION.md`**（均由本任务并行产出）。本文只保留二进制工具链与函数地图，避免与那几份报告重复。

