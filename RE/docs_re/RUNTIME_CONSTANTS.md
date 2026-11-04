# RUNTIME_CONSTANTS.md — 原版运行期常量：帧节奏 / 窗口尺寸、过渡掩膜、窗口皮肤

本文件是 `docs/ENGINE_BEHAVIOR.md` §3 清单里**不依赖反编译器**就能定案的那几条的取证记录：

* **§3-12** 原版帧率锁与窗口初始尺寸（Game.ini / Config.exe / Game.exe 常量与调用点）
* **§3-10** 过渡掩膜 `SystemFile/[Transition]Fade.png` 的实际图案
* **§3-1 / §3-2** 九宫格内边距与"盒小于帧"退化可用的资源证据

配套文档：清单在 `docs/ENGINE_BEHAVIOR.md` §3，其它二进制结论在 `docs/RE_GAME_EXE.md`。本文只做只读静态分析，**不执行 Game.exe**，也不修改上述两份文档或 `crates/`。

> 内容安全：全文只做二进制/资源层与数值层描述。

---

## 0 结论摘要

| 项 | 结论 | 证据强度 |
|---|---|---|
| §3-12 帧率锁 | 原版有**软件限帧 16.6 ms/帧（≈60 fps 上限）**，本机 `FrameSkip=0` = 不跳帧、满帧输出（详见 §2.7），由 `timeGetTime`+1ms 定时器分辨率+QueryPerformanceCounter 忙等实现；**不是硬件 vsync 锁**（呈现是 GDI DIB 位块，无交换链）。另有一条独立的 24 ms `Sleep` 与 16 ms 分支、64 ms 卡顿复位阈值 | 帧预算常量与调用点**已定案**；"16.6 与 16/24 ms 三条路径在哪种运行状态下生效"**仍需实机确认** |
| §3-12 窗口初始尺寸 | 没有"分辨率/窗口尺寸"配置项。客户区 = **数据里的屏幕尺寸 1024×576（1:1）**，窗口矩形 = 客户区 + 非客户区（`AdjustWindowRectEx`），位置按显示器居中；全屏 A/B 走 `ChangeDisplaySettingsA`。无任何 DPI 感知 API → 由系统做 DPI 虚拟化（用户截图 ≈1.5×1024×576 与此一致） | **已定案**（尺寸来源）；`WindowModeFlag` 的 0/1/2 **数值映射仍未知**（见 §2.8 末段） |
| §3-10 掩膜图案 | 不是渐变叠黑/暗角/图案，而是**单轴平面渐变（等值线是直线，残差 ≤0.5 px）+ 两端饱和**：暗端 9.7 % 纯 0、亮端 47.1 % 为抖动到 250/251 的平台；过渡带 262 px，曲线是**缓入缓出的 S 形**（余弦/smoothstep 拟合 RMS≈2.7/250，线性 RMS=3.7，即"非纯线性"）。轴向 ≈ **21.75°**（dy/dx=0.399） | 几何与曲线**已定案**（对这张资源）；"引擎如何把灰度当阈值/透明度使用、以及时间轴 easing"**仍需反编译/实测**（§3-10 的语义部分不在本文范围） |
| §3-1 九宫格内边距 | `WindowBase.png` = 18×18、**3 px 对称九宫格**、四角各只有 1 个全透明像素；**皮肤本身不含任何 padding 元数据**；体区是 **alpha=223 的半透明灰**（0x1F2425 @ 0xDF）。气球窗口的 padding 来自 DB（`Data/26 メッセージウィンドウ種類` 的 `余白[px]` = 10 或 5），系统消息窗没有该字段 | 皮肤/DB 侧**已定案**；系统窗口文本首像素偏移（§3-1 的真正问题）**仍缺**（需实测/反编译） |
| §3-2 盒小于帧的退化 | 本作数据**根本不产生 <6 px 的窗口盒**（系统消息窗 960×168、气球固定模式 580×60、文本图 1×1 是"尺寸自适"哨兵），所以资源/数据无法定案；现行 `window.rs` 的"角取 `min(CORNER, dst/2)`"是**选定的行为**而非实测值 | **仍未定**（需反编译或逐帧实测），本文只给出边界：只有脚本显式给小于 6×6 的窗口图盒才可能触发 |

---

## 1 工具与方法

全部结论可用仓库自带工具复现（命令见 §5）：

* `tools/re/wolfpe.py`（pefile 2024.8.26 + capstone 5.0.7）：只读 PE 解析、字符串/导入枚举、绝对 VA 交叉引用、前向反汇编。
* 本文额外用到的临时脚本（**未入库**，都在 `work/out/`）：

| 脚本 | 作用 |
|---|---|
| `work/out/sleep_sweep.py` | 线性反汇编整个 `.text`，收集 `Sleep`/`QueryPerformanceCounter`/`timeGetTime` 的全部调用点及其前一条指令 |
| `work/out/timer_users.py`、`work/out/winmm_str.py` | 解析 DxLib 运行期 `GetProcAddress("winmm.dll")` 的绑定槽位与名字串 |
| `work/out/fade_angle.py`、`work/out/fade_np.py`、`work/out/fade_pow.py` | 掩膜的轴向扫描、等值线直线/圆拟合、传输曲线族拟合（numpy） |
| `work/out/skin_grid.py`、`work/out/skin_hash.py` | 皮肤 PNG 逐像素网格与像素级哈希对比 |

二进制身份（`wolfpe.py facts`）：

| 文件 | SHA-256（前 16） | 大小 | 说明 |
|---|---|---|---|
| `Game.exe` | `e0716a35323007c7…5b76` | 6,365,184 | PE32 / ImageBase 0x400000 / 时间戳 1529667528 |
| `Config.exe` | `283f1e94ab5397e3…00eb` | 299,008 | MFC 对话框工具，只写 Game.ini |

---

## 2 §3-12 帧率锁与窗口初始尺寸

### 2.1 Game.ini 的现状（安装目录）

`/e/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver/Game.ini`，156 字节、CRLF，**恰好 10 个键**：

```
Start=0
SoftModeFlag=0
WindowModeFlag=1
SEandBGM=3
FrameSkip=0
Proxy=
ProxyPort=
ScreenShotFlag=1
F12_Reset=1
Display_Number=0
Old_DirectX_Use=0
```

关键点：**没有任何分辨率/窗口宽高/缩放键**。所以"窗口初始尺寸"不可能来自 ini。

### 2.2 Config.exe 能设什么（对话框资源证据）

`Config.exe` 只有一个设置对话框（`RT_DIALOG` id=102, 2268 字节，标题 `ゲーム設定`）。把该对话框模板里的 UTF-16 串扫出来（`work/out/cfg_dlg3.py`）得到三组互斥/下拉项：

```
グラフィック表示モード
  ３Ｄモード                … "たいてい高速で処理可能だが、環境によっては正しく表示されない場合がある。"
  ソフトウェアモード        … "処理速度は遅いが、安定して表示される。表示が怪しい場合はこちらにしてください。"
画面ウィンドウ設定
  ウィンドウモード ： ウィンドウ画面でプレイ
  全画面モードA ：[標準] 縦横比を維持して全画面サイズに拡大
  全画面モードB ： 画面解像度ごと変更、できなければAモード
フレームスキップ
  高スペック：なめらか / 中スペック：そこそこ / 低スペック：ガタガタ
BGMの再生 / 効果音の再生（ON/OFF）、オンライン機能、適用、キャンセル、OK
```

对应关系（`Config.exe` 的 ini 写入块，`.rdata` @`0x41C548`）：

```
"Start=%d\nSoftModeFlag=%d\nWindowModeFlag=%d\nSEandBGM=%d\nFrameSkip=%d\nProxy=%s\n
 ProxyPort=%s\nScreenShotFlag=%d\nF12_Reset=%d\nDisplay_Number=%d\nOld_DirectX_Use=%d\n"
```

即：

* `SoftModeFlag` = 图形模式（0/1 对应 ３Ｄモード / ソフトウェアモード，**具体 0/1 归属未证实**；随附 ini 为 0）
* `WindowModeFlag` = 三种画面模式之一（ウィンドウ / 全画面A / 全画面B）
* `FrameSkip` = フレームスキップ档位（高/中/低），随附 ini 为 0

**没有**分辨率、没有窗口宽高、没有"缩放倍率"——这一点很重要：窗口尺寸不由用户配置决定。
Config.exe 以文本方式改写 ini（键名串 `Start=`、`WindowModeFlag=` … @`0x41C480`…`0x41C50C`，`WritePrivateProfileStringA` 未使用，而是读入整文件替换行）。

### 2.3 Game.exe 侧的键读取

* 键名格式串：`SoftModeFlag=%d` @`0x7BC241`、`WindowModeFlag=%d` @`0x7BC251`、`FrameSkip=%d` @`0x7BC26F`（另有 `0x7BC2F1`、`0x7C7C41`、`0x7CD5A9` 等多份拷贝，用于写入/迁移）
* 读取用的键名（无 `=%d`）：`WindowModeFlag=` @`0x7CD4E0`，**唯一代码引用**在 `0x42B4FB`（`push 0x7cd4e0` → `call 0x4cbbc0` 取配置串 → `cmp`/`atoi` → 写回调用方指针）。同一段代码接着读 `FrameSkip=`（@`0x7CD4F0`）。
  → 说明 **Game.exe 自己解析 Game.ini 文本**，不是 `GetPrivateProfileInt`（`GetPrivateProfile*` 不在导入表里）。

### 2.4 计时原语（导入 + 运行期绑定）

`Game.exe` 的导入表里与计时相关的只有（其它都是 CRT/图形/窗口）：

| API | IAT 槽 |
|---|---|
| `KERNEL32!Sleep` | `0x7B40A4` |
| `KERNEL32!QueryPerformanceCounter` | `0x7B418C` |
| `KERNEL32!QueryPerformanceFrequency` | `0x7B427C` |
| `KERNEL32!GetTickCount` | `0x7B40E4` |
| `WINMM!timeGetTime` | `0x7B4428` |

`timeBeginPeriod` / `timeEndPeriod` / `timeSetEvent` / `timeKillEvent` / `timeGetDevCaps` **不在导入表**，而是 DxLib 在 `0x56C540`–`0x56C6xx` 用 `LoadLibraryW("winmm.dll")` + `GetProcAddress` 动态绑定到 `.data` 槽（名字串在 `.rdata` `0x7D7D24`–`0x7D7D94`）：

| 槽 | 函数 |
|---|---|
| `0xABA154` | winmm 模块句柄 |
| `0xABA158` | `timeSetEvent` |
| `0xABA15C` | `timeKillEvent` |
| `0xABA160` | `timeBeginPeriod` |
| `0xABA164` | `timeEndPeriod` |
| `0xABA168` | `timeGetTime` |
| `0xABA16C` | `timeGetDevCaps` |

启动时（`0x513F7A`–`0x513F90`）正是经典写法：

```
00513f7a: push 8
00513f7c: lea edx, [ebp - 0xb3b0]
00513f82: push edx
00513f83: call dword ptr [0xaba16c]      ; timeGetDevCaps(&caps, sizeof(TIMECAPS)=8)
00513f89: mov eax, [ebp - 0xb3b0]        ; caps.wPeriodMin（通常 1）
00513f8f: push eax
00513f90: call dword ptr [0xaba160]      ; timeBeginPeriod(wPeriodMin)
```

配套还有 `QueryPerformanceFrequency(&0xA238D8)`（`0x513F40`）→ 非零则在 `0xA238D4` 置 1，表示"有高精度计数器"。

两个内部时钟函数（本文后面反复用到）：

| 函数 | 语义 | 证据 |
|---|---|---|
| `0x550060` | `now_ms()` = `timeGetTime() & 0x7FFFFFFF`（无 winmm 时返回 -1，并先调 `0x56C2C0` 补绑定） | `call [0xABA168]` + `and eax, 0x7fffffff` |
| `0x550090` | `now_us()` = 64 位微秒；有 QPF 时 `QPC × 1_000_000 / QPF`（常量 `0xF4240`=1000000 @`0x5500B6`），否则 `timeGetTime × 1000` | `call [0x7B418C]` + `0x56D6C0/0x56D730`（64 位乘除） |

### 2.5 限帧：等待函数、帧预算、追帧/丢帧

**(a) `wait_ms(int ms)` @`0x52EB30`** —— 精确等待，注意它是**忙等**而不是纯 `Sleep`：

```
0052eb37: push 0
0052eb39: call 0x550090              ; t0 = now_us()
0052eb3e: mov ebx, [esp+0x20]        ; ms
0052eb42: imul ebx, ebx, 1000        ; → µs
0052eb4b: cmp ebx, 0xfa0             ; > 4000 µs（4 ms）？
0052eb59: jle 0x52eba3
   ; 长等待路径：循环 { if (0x52ece0() != 0) break; if (now_us() >= deadline) break; Sleep(1) }
   ;   0x52eb8e push 1 / call 0x56DA20 → 1 ms 睡眠（每个 1 ms 步进都泵消息）
0052eba3: ; 收尾：纯忙等 now_us() < deadline  （0x52ebb0 循环，无 Sleep）
```

即"**>4 ms 用 1 ms 步进 Sleep + 泵消息，最后不足 4 ms 用 QPC 忙等对齐**"。这解释了为什么 `timeBeginPeriod(1)` 必须开。

**(b) 帧控制器 `0x4C1490`**，初始化（`ecx`=`this`）：

```
004c14b5: call 0x550060              ; t0 = now_ms()
004c14c0: mov [edx+0xa474], eax      ; this->frame_start = t0
004c14ce: fild dword [0x84b244]      ; k  = 帧倍率（默认 1）
004c14d4: fmul qword [0x7d1ea0]      ; k *= 16.6        ← double 0x403099999999999A
004c14da: fadd qword [0x804a60]      ; k += 0.5         ← double 0.5
004c14e0: call 0x4fe844              ; 截断 → 四舍五入到整 ms
004c14e5: mov [ecx+0xa478], eax      ; this->frame_ms  (= 17，k=1 时)
004c150e..: 同上再算一次 → this->+0xa47c
004c1510: fild [0x84b244] / *16.6 / *3.0 [0x8053f0] / +0.5 → this->+0xa480  (= 50，k=1 时)
004c1534: 同上（不乘 3）→ this->+0xa48c，并复制到 +0xa488/+0xa484
```

其中 `0x84B244` 是在 `0x46A5E3`–`0x46A5F4` 算出来的：

```
0046a5e3: mov edx, [0xa16684]        ; 运行期从数据头取的一个字节（BSS，文件里为 0）
0046a5e9: movsx ecx, byte ptr [edx]
0046a5ec: mov eax, 0x3c              ; 60
0046a5f2: idiv ecx
0046a5f4: mov [0x84b244], eax        ; k = 60 / fps字节
```

→ **帧预算公式：`frame_ms = round(16.6 × 60/fps + 0.5)`**，`fps=60` 时 = **17 ms**；三帧预算 = **50 ms**。

> 交叉确认（2026-11）：Lead 的 Ghidra decompile 在 `FUN_00469820` 独立得到同一个式子 `DAT_0084b244 = 0x3c / *DAT_00a16684`，即"每帧单位步进 = 60 / 数据里的 fps 字节"，与本文 `0x46A5E3` 的前向反汇编完全一致。`DAT_00a16684` 是**数据头的 fps 字节**（`.data` BSS，文件里为 0，运行期由数据填）。

**(c) 等待与丢帧判定**（同一函数后半段）：

```
004c15a6: cmp dword [0xa18a3c], 0x36      ; 某运行期帧率统计量 >= 54 ?
004c15ad: jge 0x4c17a9                    ; → 走 16 ms 分支
   ; 常规分支：elapsed = now_ms - frame_start - frame_ms(17)；若 <0 取 0 → wait_ms(elapsed)
   ;          再按"三帧累计 (+0xa484 + +0xa488 + +0xa48c)"与 +0xa480(=50) 的差额 wait_ms()
   ;          末尾把差额累加进 +0xa484（滑动三帧限速）
004c17a9: ; 16 ms 分支
004c1803: mov ecx, 0x10                   ; 16
004c1808: sub ecx, eax                    ; 16 - (now_ms - frame_start)
004c1832: push edx / call 0x52eb30        ; wait_ms(剩余)
   ; 以及"如果已经晚了超过 3 帧（+0xa480=50 ms）就不等"的旁路
```

另有**丢帧/补帧**标志 `this+0xA468`（字节，1=本帧允许再跑一帧），最多允许 1 次（`004c1786 cmp [ebp-4],1 / jle`）。

**(d) 每帧入口 `0x5501A0`（消息泵 + 一帧）里的三处硬编码等待**：

| 位置 | 值 | 语义（按上下文） |
|---|---|---|
| `0x550376` `push edi(0); call Sleep` | **0 ms** | "无事可做"让出 CPU 的路径（其后 `now_ms - 0xA21074 > 0x40`(64 ms) 就复位计时器） |
| `0x550582` `push 0x18; call Sleep` | **24 ms** | 窗口非活动/不需重绘分支的固定节流（`0x550543 cmp [0xA24D40],0` 进入） |
| `0x510D34`、`0x550394` | 比较 `0x40` = **64 ms** | 单帧超时就视为卡顿，重置节流基准 |

### 2.6 结论速览（已定案的部分）

**（本节是速览，FrameSkip 与判定合在一起看 §2.7）**

1. 原版有**引擎自己的 60 fps 级软件限帧**：帧预算 `16.6 ms ≈ 1/60 s`（`0x7D1EA0` 的 double `16.6`，配 `+0.5` 取整 → 17 ms；另有 16 ms 与 3×16.6≈50 ms 两级窗口），以 `timeGetTime`（1 ms 分辨率，启动时 `timeBeginPeriod(wPeriodMin)` 提升）+ `QueryPerformanceCounter` 忙等对齐。
2. **不是 vsync 锁**：呈现走 GDI（`CreateDIBSection`/`StretchDIBits`/`SetDIBitsToDevice`），没有 d3d9/d3d11/dxgi **导入**，也没有交换链语义，因此"等垂直同步"这种锁不存在（对应 §1.6 / `RE_GAME_EXE.md` §3）。
3. 但 `SoftModeFlag=0` 在 Config.exe 里对应"３Ｄモード"，而 DxLib 的 D3D 分支是**动态加载**进来的（`.rdata` 有 `Source/Library/Main/Windows/DxGraphicsD3D9.cpp`、`DxGraphicsD3D11.cpp`、`DwmGetWindowAttribute`，`d3d9.dll` 走 `LoadLibraryA`+`GetProcAddress`，不是静态导入）。所以"3D 模式"下运行时**可能**另有一条 D3D9 `Present` 的等待，静态分析无法排除；但 16.6 ms 的软件预算无论如何都把上限压在 ≈60 fps。
4. `FrameSkip=0`（本机 ini）表示不跳帧，脚本的"帧"与呈现帧 1:1。

**仍需实机确认的边界**：

* 哪条等待路径实际生效（16.6/17 ms 滑窗 vs 16 ms vs 24 ms），取决于运行期那几个全局量（`0xA18A3C` 帧率统计、`0xA24D40` 状态位）的取值；
* 实测帧率是否严格 60.0 还是略高（`16.6` 而非 `16.666`，理论 ~60.2 fps，再加 `+0.5` 取整为 17 ms 又变成 ~58.8 fps，二者差 2 %）；
* 是否在某些机器上被 D3D9 的 vsync 进一步限制。
* 建议的实测方法：不改引擎，直接看游戏内 F8 调试条（`FPS(%d/%d … ScreenFPS%d/InnerFPS%d` 字符串在 `.rdata` `0x7C2F08`/`0x7C2FA0`），或用外部抓帧时间戳（不许抢前台，用用户录屏/游戏自带截图时间戳代替）。

### 2.7 判定：原版是否"锁 60 fps"（含 FrameSkip 的角色）

把 §2.4–§2.5 的证据拼起来，可以得到一个**分层的答案**（而不是简单的"是/否"）：

1. **时间基准 = 60 Hz 级**：`frame_ms = round(16.6 × (60 / fps) + 0.5)`。fps=60 时是 17 ms（≈58.8 fps），未取整的原式是 16.6 ms（≈60.2 fps）。**16.6 就是 `1/60 s` 的十进制近似**，所以"原版按 60 fps 的帧长计时"这一点是确定的。
2. **上限是软件限帧，不是 vsync**：呈现是 GDI DIB 位块（无交换链），等待由 `wait_ms` 用 `timeGetTime`（1 ms 分辨率，启动时 `timeBeginPeriod(wPeriodMin)` 提升）+ QPC 忙等完成。**不存在"被显示器刷新率锁住"的机制**（3D 模式是否另有 D3D9 Present 等待见 §2.6 第 3 条，静态分析不能排除，但软件预算已经把上限压在 ≈60）。
3. **有"追帧/丢帧"余量**：三帧滑动预算（3×16.6 ≈ 50 ms）+ 单帧丢帧标志（`this+0xA468`，最多多跑 1 帧）+ 64 ms 卡顿复位阈值。也就是说：**能跑满时按 60 fps 出帧；跑不动时允许一次性补 1 帧，并用 50 ms 窗口摊平抖动**——这是"目标 60 fps"的实现方式，不是"严格 60 Hz 节拍器"。
4. **FrameSkip 的角色**：`Game.ini` 的 `FrameSkip` 由 Config.exe 的"フレームスキップ：高スペック：なめらか / 中スペック：そこそこ / 低スペック：ガタガタ"写入，本机 `FrameSkip=0`（最高档 = 不跳帧）。`Game.exe` 在 `0x42B4FB` 起依次比对 `WindowModeFlag=` / `SEandBGM=` / `FrameSkip=`（键名串是一整块复用模板 `0x7CD4E0`–`0x7CD520`，`eSkip=` @`0x7CD500` 只是 `FrameSkip=` 的后缀别名）。它与上面第 3 条的"允许丢帧上限"是同一套机制的两端：**0 = 每帧都画（60 fps 满帧），数值越大越允许跳帧以保脚本速度**。本机配置等价于"不跳帧"。
5. **一条容易误读的证据**：虽然 `0x4C1490` 与 `0x513F96` 附近都出现 `cmp …, 0x3c`（60），但 `0x513F96` 处那一段（`0x513FA3` 起 `push 0x7d521c` 日文调试串）是 **DxLib 的 60 帧/1000 ms 帧率测量循环**（同时用 60 和 1000 ms 做终止条件），只用于调试条显示，**不是**帧节拍常量；真正的节拍常量是 `0x7D1EA0` 的 double `16.6` 与 `0x10`(16)/`0x18`(24)/`0x40`(64) 四处。

**一句话结论**：**原版是"目标 60 fps 的软件限帧"，且本机 `FrameSkip=0` 时为满帧输出**；不是 vsync 锁，也不是自由帧率。剩余不确定只剩"16.6 vs 16 ms 两条分支谁在常见状态下生效""3D 模式是否有额外 Present 等待"，这两点需要 Lead 的 Ghidra 函数上下文或一次实机计时。

### 2.8 窗口初始尺寸

**尺寸来源**：数据里的屏幕尺寸，**不是 ini、也不是硬编码**。

* 运行时调试串 `[Read]Screen size X` @`0x7CA638`、`[Read]Screen size Y` @`0x7CA660`（读数据库打印）
* `wolf-cli assets --db-defaults` 导出的引擎默认值：`screen.w 1024` / `screen.h 576`（`coordinate_scale 32×24`、`message_window 64,408,960,168`）

**窗口创建**（DxLib）：

* 动态绑定 `CreateWindowExW`：名字串 @`0x7D7B78` → `GetProcAddress` @`0x56C760` → 指针槽 `0xABA1C4`
* 调用点 `0x514729`（窗口模式）与 `0x514815`（另一分支）；参数里的客户区宽高来自上面那份 screen size，位置来自 `[0xA20C04]` 索引的两张 DxLib 表（`0x7D48B4` / `0x7D48E4`）加显示器偏移
* 客户区尺寸 = `round(屏幕尺寸 × 倍率)`：`0x5113A9` `fild dword [esp+0x1c]` / `fmul qword [esp+0x2c]` → `call 0x50E240`（取整）；宽、高各算一次。倍率是 DxLib 的窗口倍率参数，WOLF 默认 **1.0**（本作没有设置缩放，因为 Config.exe 里没有该选项）
* 客户区 ↔ 窗口矩形换算：`AdjustWindowRectEx` @`0x51140F`（另一处 `0x514596`），随后把结果拆成非客户区左上/右下偏移存进 `DAT_00a2d7e8/ec/f0/f4`
* 居中：`0x5114A4`–`0x5114CB` 的 `(display - window) / 2`（`sub eax, esi; sar eax, 1`），随后 `SetWindowPos` @`0x51152D`/`0x51159E`
* 位置可被覆盖：`0x5114F8` `cmp dword [0xa2d7cc], 1` → 为 1 时用 `DAT_00a2d7c4/c8` 作为窗口左上角（否则用居中值）。这两个变量是 DxLib 的 `SetWindowPosition` 记录值，WOLF 不设置 → 走居中
* 与 Ghidra 对齐（2026-11）：Lead 反编译的 `FUN_00513580` 即本节这一段（`AdjustWindowRectEx` + 屏幕尺寸 × 倍率 + 居中），窗口矩形缓存到 `DAT_00a2d7b4/b8`（窗口宽/高）与 `DAT_00a2d7bc/bc+` 系列；两路证据一致
* 全屏切换：`ShowWindow(SW_*)` @`0x510EE9` + `ChangeDisplaySettingsA(0,0)` @`0x510EDA`（全屏 B 改分辨率、A 保持模式只做等比放大，与 Config.exe 的文字一致）

**DPI**：`Game.exe` 与 `Config.exe` 的导入表里**没有任何** `SetProcessDPIAware` / `SetProcessDpiAwareness* / AdjustWindowRectExForDpi / GetDpiForWindow`。所以进程是 DPI 不感知的，Windows 按系统 DPI 做位图虚拟化：1024×576 的客户区在 150 % 桌面上会被放大到 1536×864（**用户实机截图 1532–1539 × 859–867 ≈ 1.5×1024×576**，与 150 % 缩放吻合；截图可能裁掉了边框，因此只能算旁证）。

**结论**：

* 窗口模式：客户区 = **数据屏幕尺寸（本作 1024×576）1:1**；窗口矩形 = 客户区 + 非客户区；窗口按显示器居中；无缩放倍率、无 ini 尺寸项。
* 全屏 A：保持 4:3/16:9 等比放大到显示器；全屏 B：改显示模式（失败回退 A）。
* `WindowModeFlag` 的**数值映射未证实**：Config.exe 只有三个互斥项（ウィンドウモード / 全画面モードA / 全画面モードB，资源顺序即此顺序；MFC 通常按 tab 顺序编号 0/1/2），但没有找到把该值写入 ini 的显式常量，Game.exe 侧也只看到"读键→atoi"。**要确认只需一次实机观察**：启动后有无窗口边框/标题栏——有边框即ウィンドウモード，无边框且铺满桌面即全屏 A。随附 ini 是 `WindowModeFlag=1`。

---

## 3 §3-10 过渡掩膜的实际图案

### 3.1 文件形态

`work/Data/SystemFile/[Transition]Fade.png`

| 项 | 值 |
|---|---|
| SHA-256 | `29a70a3174f3e34e81ccdb5b4173b73ccd7fe70d6626ac3667f3e976fe0681ea` |
| 尺寸/模式 | **640×480，PNG 8-bit 灰度（`L`）** |
| PNG 块 | `IHDR` `pHYs` `gAMA` `cHRM` `IDAT`(70154) `IEND` —— 带色彩管理块，说明是**图像工具导出**，不是引擎生成 |
| 灰度级数 | 252 级（min 0，max **251**，不是 255） |
| 数据库定义 | `Sys/11 ﾄﾗﾝｼﾞｼｮﾝﾀｲﾌﾟ` 唯一一行 = **「横フェード」**，`ファイル名(ﾓﾉｸﾛ)` = `SystemFile/[Transition]Fade.png` |

### 3.2 直方图与几何：平面渐变，不是图案

直方图（307200 像素）：

```
0        : 29,762  (9.69 %)   → 暗端完全饱和
250      : 72,517
251      : 72,194               → 亮端平台合计 144,711 (47.11 %)，均值 250.50
其余 249 级 : 约 132,727 (43.2 %) 分布在整个过渡带
```

亮端只出现 `250/251` 两值、且水平相邻差 `|Δ|∈{0,1,2}`（均值 0.49，约 50 % 的相邻对不同）→ 是**逐像素随机抖动**在 250.5 处的量化，不是有序图案、不是边框。

**等值线形状**（关键判据：`work/out/fade_fit.py`）。对每个灰度级取等值像素集，分别拟合"最优直线"和"最优圆"：

| 灰度级 | 像素数 | 直线拟合 RMS / max (px) | 圆拟合 RMS (px) |
|---|---|---|---|
| 30 | 694 | **0.501 / 1.740** | 134.2 |
| 60 | 511 | **0.352 / 1.317** | 365.4 |
| 90 | 430 | **0.392 / 1.229** | 86.9 |

→ **等值线是直线**（亚像素级），所以这是**单轴平面渐变**：不是径向暗角、不是同心圆、不是图案/网点。

**轴向**：以"同投影值分箱内方差最小"扫描角度，最佳角 **21.75°**（单位向量 `(0.928810, 0.370557)`，即 `dy/dx = 0.399 ≈ 0.4`，分箱 RMS 1.32 灰阶）。投影 `u = 0.9288·x + 0.3706·y` 的范围是 `0..771`。

沿该轴的剖面（0.5 灰阶精度，`work/out/fade_tab.py`）：

| u | 0–141 | 155 | 170 | 185 | 200 | 215 | 230 | 245 | 260 | 275 | 290 | 305 | 320 | 335 | 350 | 365 | 380 | 395 | ≥403 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 灰度 | 0 | 4.7 | 8.9 | 14.9 | 22.9 | 33.1 | 45.5 | 59.9 | 76.3 | 94.3 | 113.7 | 133.9 | 154.5 | 175.0 | 194.9 | 213.4 | 230.0 | 244.1 | 250.5 |

所以：**暗端平台 9.7 %（左/上角），过渡带 ≈262 px 宽，亮端平台 47.1 %（右下区域）**。这一分布对"阈值型 wipe"是合理的，对"整屏乘一个系数"则不合理（那样整幅掩膜的均值才重要，不需要这么大面积的两端平台）。

### 3.3 过渡带不是线性，是 S 形

把剖面按 `v = 250.5 · f(clamp((u-u0)/w))` 拟合，`f` 取 8 族候选函数，网格搜 `u0,w`（`work/out/fade_np.py`，numpy）：

| 曲线族 | 最优 u0 / w | RMS（灰阶，满量程 250.5） |
|---|---|---|
| **余弦 ease `(1-cos πt)/2`** | 150 / 290 | **2.76** |
| **smoothstep `3t²-2t³`** | 156 / 280 | **2.78** |
| smootherstep `t³(6t²-15t+10)` | 128 / 336 | 2.78 |
| 幂律 `t^1.4` | 158 / 232 | 2.03（最佳单参数族） |
| 线性 `t` | 192 / 208 | 3.79 |
| `t²` | 108 / 276 | 3.15 |
| `√t` | 232 / 198 | 10.87 |

结论：**过渡带是缓入缓出的 S 形（中段最陡 ≈1.4 灰阶/px，两端趋 0）**，而不是线性楔形；量级上 2.0–2.8 灰阶的残差 ≈ 1 % 满量程，属于"资源本身手绘/抖动+轴向 1 px 误差"的量级。要注意这是**一张美术位图**，谁都可能随手画成 S 形；引擎自己的**时间轴** easing 与这张图无关，无法从资源推断。

### 3.4 与 `crates/wolf-game/src/transition.rs` 的三角波模型对照

`transition.rs` 建模的是**时间轴上的整屏亮度三角波**：`brightness = |2t-1|`（1→0→1，中点全黑），渲染器把整屏乘这个系数（`alpha = 1-brightness`）。

对照实际资源，两者**概念不同**：

| | 本仓 `transition.rs` | 原版资源 |
|---|---|---|
| 数据 | 无（纯解析式） | 640×480 灰度位图，**空间分布**信息 |
| 作用维度 | 时间（每次乘同一个标量） | 空间（每个像素有自己的阈值/权重） |
| 视觉结果 | 整屏**均匀变暗**再变亮 | **斜向 wipe**：一条 21.75° 的界线扫过屏幕（暗端先/后变化） |
| 曲线 | 三角波（线性升降） | 位图内是 S 形，时间轴未知 |

因此：

* 若把 `Fade.png` 当"调暗用的灰度图"，会得到**每像素不同步变暗**的效果（斜向擦除），不是均匀 dim；
* 该资源本身**没有时间轴信息**，所以"过渡是线性三角波还是 easing"**无法从这张图判定**，必须靠引擎代码（opcode 160/161/162 的具体实现）或逐帧实测（§3-10 语义部分仍未定）；
* **对当前移植没有影响**：`transition.rs` 文档已说明本作唯一使用的调用是 `CE48 [-1, 0x0001_000A]`（`kind=-1` 硬切），不会走到掩膜绘制。

### 3.5 一个容易被忽略的细节：掩膜 640×480 vs 屏幕 1024×576

掩膜是 **4:3**，屏幕是 **16:9**（1024×576）。所以原版必须**各向异性拉伸**掩膜（1024/640=1.6、576/480=1.2）。拉伸后屏幕空间的等值线斜率变成 `0.399 × 1.2 / 1.6 = 0.299 ≈ 0.3`。若将来真要复刻可见过渡，注意：**按屏幕尺寸缩放后再取样**，而不是按 640×480 直接平铺/居中。

---

## 4 §3-1 / §3-2 可用的资源证据

### 4.1 `SystemFile/WindowBase.png` 逐像素（3 px 九宫格，无 padding）

18×18、RGBA、7 种颜色。逐像素网格（`work/out/skin_grid.py`）：

```
      0 1 2 3 ……………… 14 15 16 17
 0    A B B B B B B B B B B B B B B B B A
 1    B C D D D D D D D D D D D D D D C B
 2    B D E F F F F F F F F F F F F E D B
 3    B D F G G G G G G G G G G G G F D B
 …
14    B D F G G G G G G G G G G G G F D B
15    B D E F F F F F F F F F F F F E D B
16    B C D D D D D D D D D D D D D D C B
17    A B B B B B B B B B B B B B B B B A
```

| 记号 | RGBA | 角色 |
|---|---|---|
| A | `(255,255,255,0)` | **四角各 1 个全透明像素**（圆角只剩这一像素） |
| B | `(66,66,66,255)` | 外暗线 `#424242`（第 0 行/列） |
| C | `(136,136,136,255)` | 角部斜面 `#888888` |
| D | `(242,243,243,255)` | 亮棱 `#F2F3F3`（第 1 行/列） |
| E | `(217,220,221,255)` | 角部过渡 `#D9DCDD` |
| F | `(87,96,98,255)` | 过渡线 `#576062`（第 2 行/列） |
| G | `(31,36,37,**223**)` | **体区** `#1F2425`，**alpha 0xDF = 87.5 % 半透明** |

要点：

1. **边框恰为 3 px 且上下/左右镜像**，体区 12×12 → 九宫格切点 `CORNER=3` 与 `crates/wolf-game/src/window.rs` 一致。
2. **皮肤里没有任何 padding/文本内边距字段**。WOLF 的皮肤图只提供线框，"文本从哪开始"由引擎常量或调用方的盒坐标决定。
3. **体区是半透明的**（alpha 223），意味着窗口后面的画面会透出来 —— 渲染时必须混色，不能当不透明贴图盖上去。这一条在 `RE_GAME_EXE.md` §4.1 的网格里以"逐像素 3 px"记录过但未强调 alpha。
4. 四角唯一透明像素意味着：如果引擎在**极小盒**上仍按 3 px 切角，透明像素会跑到框线中间（见 §4.5）。

### 4.2 `WindowBase_amania.png`：像素完全相同，且不是系统皮肤

| 文件 | 文件 SHA-256（前 16） | 像素 RGBA 哈希（前 16） |
|---|---|---|
| `WindowBase.png` | `895a8e2a5157f32b` | `3fd6344a44bff9c2` |
| `WindowBase_amania.png` | `56de2178e7bc3121` | **`3fd6344a44bff9c2`（同一）** |

→ 两者只差 PNG 编码（IDAT 压缩方式），**逐像素一致**。

数据库侧（`Sys/10 ウィンドウ画像` 三行）只登记了：

```
row0  入力待ちﾎﾟｰｽﾞ画像    （文件名留空，縦分割数=0）
row1  選択肢ｳｨﾝﾄﾞｳ画像      SystemFile/WindowBase.png        縦分割数=0
row2  選択肢カーソル指定    SystemFile/CursorBase.png        縦分割数=1
```

→ `WindowBase_amania.png` **不是**系统皮肤的一份变体配置，而是被脚本当**普通图片**画的（`HANDOFF_M0.md` §… 记录 CE264 的 picture 12001 用的就是它）。结论：皮肤只有一个规格（18×18 / 3 px），不存在"不同尺寸窗口各有一张皮肤"。

### 4.3 其它 SystemFile 皮肤：只有一张九宫格

| 文件 | 尺寸/模式 | 用途（DB 或引擎） | 特征 |
|---|---|---|---|
| `CursorBase.png` | 12×12 RGBA，53 色 | `Sys/10 row2` 選択肢カーソル（縦分割数=1） | **有软边**：alpha 177–255 连续，中心暗、外圈渐亮（`139,139,139,210`→边缘），是**抗锯齿圆光标**，不是九宫格 |
| `Text_Pause.png` | 17×90 RGBA，alpha 仅 0/255 两值 | 引擎硬编码的"文字送り待ち"光标（`Sys/10 row0` 文件名为空，故非 DB 指定） | 17×90 = **5 帧 17×18** 的动画条 |
| `shadow64TX.png` | 384×256 RGBA，alpha 0–120 | 引擎阴影贴图 | 384/64=6、256/64=4 → **24 块 64×64** 的软阴影图集 |
| `WindowBase.png` | 18×18 RGBA | 唯一九宫格皮肤（选择肢窗/消息窗共用） | 见 §4.1 |

**没有第二张窗口皮肤**（`work/Data/SystemFile` 下只有 `WindowBase.png` 与像素相同的 `WindowBase_amania.png`）。所以"不同尺寸窗口是否需要额外 padding"这个问题在资源层面是**否**：只有一张 3 px 线框图，任何尺寸都靠拉伸。

### 4.4 数据库侧的 padding：只有"气球窗口"才有

`Data/26 メッセージウィンドウ種類`（9 种，第三方吹き出し插件风格的消息窗）**自带内边距字段**：

```
row0 まる（妹）           余白[px] = 10   名前欄余白[px]=4  セーフゾーン x/y = 10/10  分割数 = 3  [固定モード] 580×60
row1 まる（妹）サイレント   余白[px] =  5   …（同上）                                             580×60
row2 まる（お兄ちゃん）     余白[px] =  5   …
```

而**系统消息窗**（`message_window 64,408,960,168`，皮肤 `WindowBase.png`）**没有** padding 字段。所以：

* 气球窗：padding/分割数/安全区全在数据里（`余白[px]`=5/10、`分割数`=3 → 3×3 切图，角尺寸 = 图宽/3）；
* 系统窗：文本首像素相对盒左上角的偏移只能是**引擎常量**——这正是 §3-1 尚未取到的那个数，资源里没有。

### 4.5 §3-2（盒小于帧）能推到哪一步

可得的边界事实：

1. 皮肤切点是 3 px，最小"不退化"盒是 6×6。
2. 本作数据里**最小的窗口盒**：系统消息窗 960×168；气球固定模式 580×60；再往下是文本图的 `1×1` ——但它是"尺寸跟随内容"的哨兵（`window.rs: MIN_BOX=2` 已按此建模），不是真实小盒。
3. 四角唯一透明像素说明皮肤作者默认"角是圆的"（1 px 圆角），一旦盒高/宽 < 6 px，四个角片会互相重叠、透明像素落进线框内部 → 引擎要么裁切、要么缩小角片。

**无法从资源/数据判定**引擎选哪种；现行 `window.rs` 的 `dcols[1] = min(cw, w/2)`（角片最多占一半，超出则折半）是**选定的行为**，既没有二进制证据、也没有实测证据。要定案只能：

* 反编译窗口绘制函数（九宫格取样），或
* 用脚本/改存档造一个 4×4 的窗口图盒逐帧实测。

---

## 5 复现命令

固定开头（`AGENTS.md` §1）：

```bash
cd '/e/Study/github program/Imouto Life' && source tools/env.sh >/dev/null 2>&1
GAME='/e/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver/Game.exe'
CFG='/e/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver/Config.exe'
```

**§3-12**

```bash
cat -A '/e/EROGAME/Imouto! Life ~Monochrome~ zh-CN Ver/Game.ini'
python tools/re/wolfpe.py "$GAME" facts | head -60
python tools/re/wolfpe.py "$GAME" xref --string 'WindowModeFlag=' --disasm --length 200
python tools/re/wolfpe.py "$GAME" strings --filter 'WindowModeFlag|FrameSkip|SoftModeFlag|Display_Number' --min 4
python tools/re/wolfpe.py "$GAME" disasm --va 0x550060 --length 90      # now_ms
python tools/re/wolfpe.py "$GAME" disasm --va 0x550090 --length 90      # now_us (QPC)
python tools/re/wolfpe.py "$GAME" disasm --va 0x52eb30 --length 180     # wait_ms
python tools/re/wolfpe.py "$GAME" disasm --va 0x4c1490 --length 260     # 帧预算初始化
python tools/re/wolfpe.py "$GAME" disasm --va 0x513f40 --length 120     # QPF + timeBeginPeriod
python tools/re/wolfpe.py "$GAME" disasm --va 0x56c540 --length 340     # winmm 动态绑定
python tools/re/wolfpe.py "$CFG"  strings --filter 'Game.ini|WindowModeFlag|FrameSkip' --min 4
PYTHONIOENCODING=utf-8 python work/out/cfg_dlg3.py                      # 对话框 UTF-16 文案
PYTHONIOENCODING=utf-8 python work/out/sleep_sweep.py                   # 全部 Sleep 调用点
PYTHONIOENCODING=utf-8 python work/out/fps_acc.py                       # 帧预算/统计
```

**§3-10**

```bash
python - <<'PY'
from PIL import Image
im=Image.open("work/Data/SystemFile/[Transition]Fade.png")
print(im.size, im.mode, im.info)
PY
PYTHONIOENCODING=utf-8 python work/out/fade_angle.py    # 轴向扫描 + 剖面
PYTHONIOENCODING=utf-8 python work/out/fade_fit.py      # 等值线直线 vs 圆
PYTHONIOENCODING=utf-8 python work/out/fade_np.py       # 曲线族拟合（numpy）
PYTHONIOENCODING=utf-8 python work/out/fade_final.py    # 直方图/抖动/平台
PYTHONIOENCODING=utf-8 python work/out/fade_tab.py      # 剖面采样表
```

**§3-1 / §3-2**

```bash
PYTHONIOENCODING=utf-8 python work/out/skin_grid.py     # 逐像素网格 + 颜色图例
PYTHONIOENCODING=utf-8 python work/out/skin_hash.py     # 皮肤像素级哈希对比
./target/debug/wolf-cli.exe --root work/Data assets --db-defaults | head -14
./target/debug/wolf-cli.exe --root work/Data assets --db-defaults --filter 'ウィンドウ画像'
./target/debug/wolf-cli.exe --root work/Data assets --db-defaults --filter 'メッセージウィンドウ種類'
```

（`assets --db-defaults` 的 `Data/CData` 单元格需要 `--filter` 才展开，不含 filter 时只列引擎默认值与表清单。）

---

## 6 仍然需要 Ghidra / 实机实测的部分

| 项 | 为什么静态分析到此为止 | 建议 |
|---|---|---|
| §3-12 `WindowModeFlag` 0/1/2 映射 | Config.exe 用 MFC DDX 绑定成员，没有把索引写成常量；Game.exe 只做"读键→atoi" | 一次实机观察（有无窗口边框），或看游戏内 F4 切换后的表现 |
| §3-12 实际生效的等待路径 / 精确 fps | 取决于运行期全局 `0xA18A3C`、`0xA24D40`、`0x84B244`（后者又取决于数据头里的 fps 字节 `0xA16684`） | 游戏内 F8 调试条读数（`0x7C2F08` 的 `FPS(...)` 串）或外部帧时间戳 |
| §3-12 3D 模式是否另有 D3D9 Present 等待 | d3d9.dll 是动态加载，静态导入表看不到 | 运行期模块列表（Process Explorer）或实测帧率上限 |
| §3-10 过渡的时间轴 easing / 阈值语义 | 资源只有空间分布；引擎用灰度的方式（阈值 wipe vs alpha 混合）在 `0x4C`/`0x5A` 区段的绘制代码里，需函数级反编译 | Ghidra 反编译 opcode 160/161/162 的实现 |
| §3-1 系统消息窗文本首像素偏移 | 皮肤无 padding 字段，DB 也没有 | 反编译窗口绘制或实测（截图量像素） |
| §3-2 盒 < 6 px 的退化 | 本作数据不产生这种盒 | 反编译九宫格绘制，或造小盒实测 |

---

## 附录 A：本文引用的关键地址表

**Game.exe（ImageBase 0x400000）**

| VA | 内容 |
|---|---|
| `0x550060` | `now_ms()`：`timeGetTime() & 0x7FFFFFFF` |
| `0x550090` | `now_us()`：QPC×1000000/QPF（回退 timeGetTime×1000） |
| `0x52EB30` | `wait_ms(ms)`：>4 ms 走 1 ms Sleep 步进 + 泵消息，末段 QPC 忙等 |
| `0x52ECE0` | 泵消息/退出检查（wait 循环里用） |
| `0x56DA20` | `Sleep(n)` 包装 |
| `0x4C1490` | 帧控制器：帧预算 16.6 ms / 3 帧 50 ms / 16 ms 分支 / 丢帧标志 |
| `0x5501A0` | 每帧入口（PeekMessage + 一帧 + `Sleep(0)`/`Sleep(24)`） |
| `0x46A5E3` | `0x84B244 = 60 / *(int8*)0xA16684` |
| `0x513F40` | QPF 探测；`0x513F83` timeGetDevCaps；`0x513F90` timeBeginPeriod |
| `0x56C540` | winmm.dll 动态绑定（`0xABA154`…`0xABA178`） |
| `0x56C760` | `GetProcAddress("CreateWindowExW")` → 槽 `0xABA1C4` |
| `0x514729` / `0x514815` | `CreateWindowExW` 调用点 |
| `0x51140F` / `0x514596` | `AdjustWindowRectEx` |
| `0x5114A4`–`0x5114CB` | 窗口居中 `(display-window)/2` |
| `0x510EDA` | `ChangeDisplaySettingsA(0,0)`（退出全屏） |
| `0x42B4FB` | Game.ini 键解析（`push "WindowModeFlag="`） |
| `0x7D1EA0` | double `16.6` |
| `0x804A60` | double `0.5`（取整偏移） |
| `0x8053F0` | double `3.0`（三帧预算） |
| `0x7D7D24`…`0x7D7D94` | winmm 函数名串（timeGetDevCaps/timeGetTime/timeEndPeriod/timeBeginPeriod/timeKillEvent/timeSetEvent/winmm.dll） |
| `0x7CA638` / `0x7CA660` | `[Read]Screen size X` / `Y` |

**Config.exe**

| VA | 内容 |
|---|---|
| `0x41C468` | `Game.ini` |
| `0x41C49C` / `0x41C561` | `WindowModeFlag=` / `WindowModeFlag=%d` |
| `0x41C548` | ini 写入的整块格式串（11 个键） |
| `RT_DIALOG 102` | `ゲーム設定` 对话框（含三画面模式/フレームスキップ文案） |

**资源**

| 文件 | 关键数 |
|---|---|
| `[Transition]Fade.png` | 640×480 L；轴向 21.75°（dy/dx=0.399）；暗平台 u≤141；亮平台 u≥403；平台值 250.5；过渡带 S 形 |
| `WindowBase.png` | 18×18 RGBA；3 px 九宫格；体区 `(31,36,37,223)`；四角 1 px 全透明 |
| `WindowBase_amania.png` | 与上者**像素相同** |
| `CursorBase.png` | 12×12，alpha 177–255 软边 |
| `Text_Pause.png` | 17×90 = 5×17×18，二值 alpha |
| `shadow64TX.png` | 384×256 = 6×4 块 64×64，alpha ≤120 |
