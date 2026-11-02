# 过渡与叠色逆向：§3-10 过渡语义/掩膜、§3-11 tint × fade 顺序

任务：team task-5（owner transition-metrics）。只读分析 `work/out/re_all`（Ghidra 12.2 全量反编译）与
`work/Data`（冻结原版数据），**未改动任何代码**。临时脚本在 `work/out/transition/`。

复现命令（只读）：

```bash
cd '/e/Study/github program/Imouto Life'
grep -n 'case 0x\(97\|a0\|a1\|a2\):' work/out/re_all/all/00450460_FUN_00450460.c
python work/out/transition/analyze_fade5.py     # 掩膜几何/曲线
```

## 0. 结论速览

| 问题 | 结论 | 证据强度 |
|---|---|---|
| 过渡是整屏调暗还是按掩膜图案 | **不是调暗到黑**：原版是「冻结旧帧 → 用掩膜做逐像素 alpha 的交叉溶解（旧→新）」。kind>=0 用 `SystemFile/[Transition]<name>.png` 当 blend graph 逐像素混合；kind<0（本作唯一一次调用是 -1）没有掩膜，退化成**均匀 alpha 的整屏交叉溶解** | 强（见 §2） |
| 曲线 | **线性**，`t = elapsed/duration`，整数除法、无 easing；elapsed 由 `DAT_0084b244`（≈1 帧）逐帧递减 | 强（见 §3） |
| 是否三角波（出去再回来） | **单程**，不是三角波。一次 160/162 只从「旧画面」走到「新画面」；"淡出到黑再淡入"在原版是**两次过渡**（旧→黑、黑→新） | 强（见 §2/§3） |
| tint × fade 顺序 | **先 tint 后 fade**，而且是**两段独立的合成阶段**（tint 是画 sprite 时的 draw-bright 状态，fade 是画完全部 sprite 之后再叠加的一层 overlay），**不是**逐像素相乘 | 中-强（见 §4） |
| 掩膜是纯渐变还是含图案 | **纯线性平面渐变**（无图案/无边框/无噪点结构），方向 ≈ 水平偏下 21.5°，中间 ~272px 的斜面过渡带，两端硬饱和 | 强（见 §1） |

## 1. `SystemFile/[Transition]Fade.png` 实测

```python
from PIL import Image
im = Image.open('work/Data/SystemFile/[Transition]Fade.png')
# (640, 480) 'L'，info 只有 dpi/gamma/chromaticity
```

| 量 | 值 |
|---|---|
| 尺寸/模式 | 640x480，`L`（8-bit 灰度） |
| 灰阶分布 | 252 个不同值，0..251（**最大值 251，永远不等于 255**） |
| 直方图头部 | `250:72517`、`251:72194`、`0:29762`，其余值各 ~300–1900 px |
| 四角 | TL=0、TR=250、BL=12、BR=250、中心=236 |
| 结构 | 等值线是**直线且平行**：`x = -0.397*y + c(level)`（拟合残差 < 1.2 px） |
| 渐变方向 | `u = x + 0.3976*y`；即从左上（黑，u<160）指向右/右下（白，u>432），法线方向相对 +x 轴 21.5° |
| 过渡带宽 | u ∈ [160, 432]，约 272 px；带宽外是两段平台（0 与 250/251） |
| 曲线 | 见下：`v/250` 相对 t 略呈 convex（幂 ≈1.4），不是 smoothstep；也**不是**纯线性 |

实测剖面（沿 u 归一化 t，v 取 4px 桶均值；`std<1.6`，说明没有图案噪点，只有 PNG 量化抖动）：

```
t=0.00 v=0.010   t=0.29 v=0.152   t=0.60 v=0.505   t=1.00 v=0.991
t=0.10 v=0.040   t=0.40 v=0.250   t=0.71 v=0.648
t=0.21 v=0.089   t=0.50 v=0.369   t=0.90 v=0.893
线性参照:        0.103 / 0.206 / 0.294 / 0.397 / 0.500 / 0.706 / 0.897
```

结论：**单张平面线性渐变（约 21.5° 斜向、近线性略 convex、两端硬饱和、无边框/无四角标记/无图案）**。
所以它只能做"按掩膜的扫入/溶解"，做不出"径向/图案擦除"那种效果。
（注：`SystemFile/` 里只有这一张 `[Transition]` 前缀资源，即本作只可能用到这一种掩膜形态。）

## 2. VM 里 160/161/162 的真实语义

### 2.1 指令分派

主指令循环是 `FUN_00450460`（本套反编译里唯一一处同时出现 `case 0x97/0xa0/0xa1/0xa2` 的 switch，
`work/out/re_all/all/00450460_FUN_00450460.c`）：

| 行号 | opcode | 处理器 |
|---|---|---|
| :114 | 0x97 = 151 ChangeColor | `FUN_0045ca90` |
| :118 | 0xa0 = 160 Transition 设定 | `FUN_0045cdd0` |
| :122 | 0xa1 = 161 过渡准备（冻结画面） | `FUN_0045ce60` |
| :126 | 0xa2 = 162 过渡执行 | `FUN_0045ceb0` |

### 2.2 160：安装设置 + **加载掩膜图**

`FUN_0045cdd0`（`all/0045cdd0_FUN_0045cdd0.c`，19 行）：

```c
DAT_00a18af4 = *arg1;                       // kind
DAT_00a18af8 = *arg2 & 0xffff;              // duration（帧数，低 16 位）
DAT_00a18afc = (*arg2 & 0x10000) != 0;       // "wait" 位
FUN_00476220(kind, duration, wait);
```

`FUN_00476220`（`all/00476220_FUN_00476220.c`）是这个设置落到渲染对象上的地方，是**决定性证据**：

```c
FUN_00515700(*(this+0x100), 0);            // 释放上一张掩膜 graph
*(this+0x100) = 0;
if (kind < 0) {
  if (kind == -2) {                        // -2：直接用当前画面（屏幕截图）
     *(this+0x100) = FUN_0052bbd0(FUN_004cbb30());
  } else {                                 // 其它负数（-1 即本作唯一一次调用）
     *(this+0x58) = "";                    // 无掩膜文件名
     *(this+0xf4) = 1;                     // ← "无掩膜" 标志
     *(this+0xfc) = duration;              // 帧数
     *(this+0xf3) = wait;
  }
} else {
  FUN_004cb840(&DAT_00a14c70);             // 路径前缀
  name = FUN_0046ff30(tmp, /*type=*/0xb, kind, 0, 0);   // 资源名模板 type=11
  FUN_004cb880(name);                      // 拼文件名
  *(this+0x100) = FUN_0052bbd0(FUN_004cbb30());  // LoadGraph(掩膜图)
  *(this+0xf4) = 0;                        // ← "有掩膜" 标志
  *(this+0xfc) = duration;
  *(this+0xf3) = wait;
}
```

即 **kind≥0 的过渡一定会加载一张 `[Transition]…` 掩膜图**（资源模板 type=0xb，见 `FUN_0046ff30`
`all/0046ff30_FUN_0046ff30.c`，走 `_sprintf` 模板 + `DAT_00a117cc` 缺资源告警），kind<0 才是"无掩膜"。

### 2.3 161：冻结当前画面

`FUN_0045ce60`（`all/0045ce60_FUN_0045ce60.c`）：

```c
if (DAT_00a1405c == 0 && DAT_00a14062 == 0) {   // 没有别的过渡在跑
  DAT_00a14092 = 1;                             // prepared 标志（同帧冻结绘制，见 §2.5）
  FUN_00521db0(0,0,DAT_0084b230,DAT_0084b234,DAT_00a140a4,1);   // 把整屏拷进 graph DAT_00a140a4
}
```

`FUN_00521db0` = DxLib 的 `DrawModiGraph/GetGraph` 系列（把一个 graph 的矩形区域拷到另一个 graph 区，
`all/00521db0_FUN_00521db0.c`），所以 `DAT_00a140a4` = **旧画面截图**。

### 2.4 162：执行（阻塞 frames 帧）

`FUN_0045ceb0`（`all/0045ceb0_FUN_0045ceb0.c`）：

```c
if (DAT_00a14092 == 0) FUN_0045ce60();   // 没 prepare 过就现场补一次
if (DAT_00a14062 == 0) {                 // 未在跑 → 起跑
  DAT_00a14092 = 0;                      // 解冻
  DAT_00a14062 = 1;                      // 过渡运行中
  _DAT_00a14098 = DAT_00a1409c;          // 剩余帧 = 总帧
  return true;                           // = VM 该帧阻塞
}
return false;
```

> TODO（未闭合）：`DAT_00a14098/9c` 这对全局与渲染对象上的 `+0xf8/+0xfc` 计数器（§3）的对应关系没有直接
> 找到桥接代码（Ghidra 对 `0xa140f8/0xa140fc` 没有绝对符号，说明渲染对象是通过指针访问的，不是这两个全局）。
> 从语义看前者是 VM 的"阻塞帧数"，后者是渲染的"剩余帧"。不影响曲线结论。

### 2.5 每帧 tick 与绘制

主循环 `FUN_004c1bb0`（`all/004c1bb0_FUN_004c1bb0.c`）每帧顺序（行号）：

```
:315 FUN_0044ef40()    // 跑 VM
:363 FUN_004c35c0()    // 标题/菜单动画（无关）
:371 FUN_004c2ae0()
:377 FUN_004c4b90()
:381 FUN_004bb030()
:390 FUN_004c2a80()    // ← 过渡计时（elapsed 递减）
:398 FUN_004c27a0()    // ← 151 tint 线性插值
:402 FUN_004cb440()
:406 FUN_004c5fa0()
...
:459 FUN_004c25f0()    // ← 151 tint 的 flash 叠加
:467 FUN_004c28d0()    // ← 过渡真正绘制
```

**过渡计时** `FUN_004c2a80`（`all/004c2a80_FUN_004c2a80.c`，13 行，全体）：

```c
if (*(int *)(this+0xf8) - DAT_0084b244 < -9) local_c = -10;
else local_c = *(int *)(this+0xf8) - DAT_0084b244;
*(int *)(this+0xf8) = local_c;   // elapsed 递减，最多越过终点 10 个时间单位
```

`DAT_0084b244` 是引擎的"每帧时间步"，由 `FUN_00469820` 设置：`DAT_0084b244 = 0x3c / *DAT_00a16684`
（`all/00469820_FUN_00469820.c:458`），即 **60fps 时 = 1**（低帧率时按比例放大）。
`0xf8` 从 `0xfc`（=duration）递减到 ≤0 → **线性、无 easing、以帧为单位**。

**过渡绘制** `FUN_004c28d0`（`all/004c28d0_FUN_004c28d0.c`，31 行，全体）：

```c
if (this+0xc2 == 0) return;                        // 未激活
FUN_005161e0(0xff,0xff,0xff);                      // SetDrawBright 复位成中性 ★（见 §4）
if (this+0xf8 < 0 || this+0xfc < 1) {              // 已走完
  if (this+0x108 == 0) this+0xc2 = 0;              // 结束
  else { /* 重新截图 → 再来一遍（+0x108 = "二段式"）*/ this+0xf8 = this+0xfc; this+0xc2 = 1; }
} else if (this+0xf4 == 0) {                       // ★ 有掩膜
  FUN_005160d0(1, 0xff);                           // SetDrawBlendMode(1=alpha, 255)
  FUN_00528ab0(0, 0, this+0x104 /*旧画面*/, 0,
               this+0x100 /*掩膜*/, 0xff - (0xf8*0xff)/0xfc, 0x40);
                                                    // ↑ alpha = 255*(1 - elapsed/duration)
} else {                                           // ★ 无掩膜（kind = -1）
  FUN_005160d0(1, (0xf8*0xff)/0xfc);               // alpha = 255*(elapsed/duration)
  FUN_0051e930(0, 0, this+0x104 /*旧画面*/, 0);     // 均匀 alpha 画旧帧
}
```

`FUN_005160d0` = `SetDrawBlendMode(mode, alpha)`（`all/005160d0_FUN_005160d0.c`，写 `DAT_00a380cc/0a380d0`），
`FUN_0051e930` = `DrawGraph`（`all/0051e930_FUN_0051e930.c`），
`FUN_005161e0` = `SetDrawBright(r,g,b)`（0..255，255=中性，`all/005161e0_FUN_005161e0.c`），
`FUN_00528ab0` = `SetBlendGraphParam(mask, 1, alpha, 0x40); DrawGraph(...); 还原`
（`all/00528ab0_FUN_00528ab0.c`，内部就是对 `FUN_005217b0` + `FUN_0051e930` 的包裹）。

**所以**：
- 有掩膜：旧帧被"掩膜灰度当逐像素 alpha"地叠到新帧上，**掩膜灰阶决定溶解先后**（0 处先露出新画面，251 处最后），
  再乘一层随时间增长的全局 alpha → 就是"按掩膜图案的溶解/扫入"，**不是把屏幕整体乘一个亮度**。
- 无掩膜（kind=-1）：旧帧以 `alpha = elapsed/duration`（255→0）均匀盖在新帧上 → **整屏交叉溶解**。
- 两种情况都是**单程**（旧→新），终态 alpha=0 时旧帧完全消失，屏幕上就是新帧；**没有** "中间全黑再回来"。

> 本作数据里唯一一次过渡调用是 CE48 的 `160 [-1, 0x0001_000A]`（kind=-1、duration=10、wait 位 0x10000），
> 走的正是"无掩膜均匀交叉溶解"这条路径（见 `docs/M3_EVENT_MAP.md:29` 的诊断串）。这也是为什么
> 仓内注释把 kind=-1 当成"hard cut"其实不准确：它仍然是一次 10 帧的溶解，只是没有掩膜。

> TODO（未闭合）：`this+0x108`（"二段式/再来一遍"标志）在哪些调用点被置位，没有找到写入点；
> 推测对应"旧的→黑、黑→新"这种由脚本连续发两条 162 的用法，但不确信。

## 3. 曲线与 t 的算法

```
t        = elapsed / duration          （整数除法，向下取整）
elapsed  : 从 duration 每帧 -= DAT_0084b244（60fps 时 = 1），下限 -10
mask 模式 : mask_alpha_global = 0xff * (1 - elapsed/duration)   → 0 → 255
no-mask   : frame_alpha       = 0xff * (elapsed/duration)        → 255 → 0
```

- **线性**，没有 easing（不是 `smoothstep`、不是三角波、没有 `sin`）。
- 每帧步长 `DAT_0084b244 = 60 / FPS`（`FUN_00469820:458`），所以"帧数"参数在高帧率机器上仍是真实帧数。
- 尾部 `-9/-10` 的越界保护（`FUN_004c2a80`）让最后一帧的 alpha 精确落在 0/255 上，不产生负 alpha。

## 4. §3-11：151 tint 与 160/162 fade 的叠加顺序

### 4.1 151 到底做了什么

`FUN_0045ca90`（`all/0045ca90_FUN_0045ca90.c`）——**不是百分比乘子，是 DxLib `SetDrawBright` 的偏移量**：

```c
if ((colour & 0x1000000) == 0) {                       // bit24 = 0 → 普通渐变
   frames = arg2;
   r = ((colour >> 16) - 100) * 0xff / 100;
   g = ((colour >>  8) - 100) * 0xff / 100;
   b = ( colour       - 100) * 0xff / 100;
   FUN_004a57d0(b, g, r, frames);                       // 线性 ramp
} else {                                               // bit24 = 1 → flash
   ...同样换算... FUN_004a5870(b, g, r, frames);
}
```

`FUN_004a57d0`（`all/004a57d0_FUN_004a57d0.c`）：`+0x902 = +0x904 = frames+1`（tick/总帧），
`+0x8fc..0x900 = 当前值`（from），`+0x8f6..0x8fa = 目标值`（to）。

`FUN_004c27a0`（`all/004c27a0_FUN_004c27a0.c`）：`+0x8f0[i] = to[i] + (from[i]-to[i]) * tick / total`，
tick 每帧 `-= DAT_0084b244`，到 0 后置 -1 结束 → **线性、整数除法**。

`FUN_004bf5b0`（`all/004bf5b0_FUN_004bf5b0.c:20-101`）把 `+0x8f0` 变成真正的 draw state：

```c
bright_r = (*(short*)(this+0x8f0) < 1) ? *(short*)(this+0x8f0) + 0xff : 0xff;   // 0 + 255 → 中性
FUN_005161e0(bright_r, bright_g, bright_b);          // SetDrawBright
```

即 **151 的百分比 p 最终是 `SetDrawBright = clamp(255 + (p-100)*255/100, 0, 255)`，是"线性缩放每通道亮度"，不是 RGB 百分比乘子**（对 0..255 的通道两者近似等价，但 151 的 `p=150` 在 DxLib 里会被钳到 255=中性，而"乘 1.5"会溢出——这是可见差异）。

**flash（bit24=1）走的完全是另一条路**：`FUN_004a5870`（`all/004a5870_FUN_004a5870.c`）不碰
`+0x8f0` 那套 ramp，而是把 `+0x906..0x90a` 直接写成 `channel + 0xff`，计时/总帧写 `+0x90c/+0x90e`。
再由 `FUN_004c25f0`（`all/004c25f0_FUN_004c25f0.c`）画一张**整屏纯色矩形叠加层**：

```c
FUN_005160d0(1, (this+0x90c)*0xff/(this+0x90e));   // SetDrawBlendMode(ALPHA, alpha=剩余帧/总帧)
FUN_005161e0(0xff,0xff,0xff);                      // 先置 SetDrawBright 中性
b = clamp(+0x906); g = clamp(+0x908); r = clamp(+0x90a);   // 0..255 手动钳位
col = FUN_00543f70(b, g, r);                        // = DxLib GetColor(r,g,b)（all/00543f70 全文）
FUN_00526390(0,0,DAT_0084b230,DAT_0084b234,col);    // = DrawBox / 整屏填充（all/00526390 全文）
```

把一个百分比 p 代进去：`+0x906 = (p-100)*255/100 + 255 = 255*p/100`，再钳到 0..255，**即 flash 的颜色 = 各通道
`p%` 的 255 后钳顶**。所以 p>100 的 flash 一律变成**纯白满屏色块**，alpha 从 255 单向衰减到 0。

→ **flash = "一上来就整屏刷一层（通常白色的）色块，然后 alpha 线性衰减"，不是亮度乘子、也不是三角波**。
（Confidence: 强——`FUN_00543f70`/`FUN_00526390` 两个被调函数全文已核。）

**已确认的实例**：本作 dungeon 事件 1 的 flash `0x0196_C896`（R150 G200 B150，20 帧，见
`crates/wolf-game/src/tint.rs:150` 的注释）在原版是 **R=255*150/100→255、G=255*200/100→255、B=255*150/100→255
的纯白 flash，20 帧内 alpha 线性衰减**；仓内却把它当成"亮度乘到 1.5/2.0/1.5 再回来"，视觉上会是过曝彩色脉冲
而不是白色闪光。这是一个**可观测的行为差异**（同时回答了 §6 的 TODO 6：`p>100` 的 151 确实存在）。

### 4.2 fade 与 tint 谁先

答案是：**它们在渲染管线里是两个先后发生的、彼此独立的阶段，不是同一个乘子。**

证据（`FUN_004c1bb0` 的每帧顺序 + `FUN_004c28d0` 开头）：

1. tint 是 **sprite 绘制期间的 DxLib 全局状态**（`SetDrawBright`）：`FUN_004c27a0` 只更新数值（:398），
   数值在 `FUN_004bf5b0`/`FUN_004c25f0` 里被 `FUN_005161e0` 设成 draw state，作用于**当时画的那些 sprite**。
2. fade 是 **画完场景之后叠的一整帧 overlay**：`FUN_004c28d0`（:467）画的是已经截好图的旧帧 `this+0x104`。
3. `FUN_004c28d0` 第一件事就是 `FUN_005161e0(0xff,0xff,0xff)` **把 SetDrawBright 复位**，
   所以 **151 的 tint 状态不会污染 fade 用的那层 overlay**。

因此原版语义 = **先 tint（作用于场景 sprite），再 fade（在合成结果上叠 mask/alpha 的交叉溶解层）**，
是"合成顺序"而不是"逐像素相乘"。

一个推论：161 截图发生在 tint 已生效之后 → 截图里已经含 tint；所以淡出方向（旧→新）里旧帧带 tint、新帧带新 tint，
不会互相相乘。

> TODO（未闭合）：`FUN_004bf5b0` 里 `param_2/param_3` 两个分支（`FUN_005160d0(2,0xff)` vs 直接 SetDrawBright）
> 分别对应"窗口/地图层"与"HUD"，具体哪层用哪个分支没有逐调用点确认；但两者都是 draw state，不改变"先 tint 后 fade"。

## 5. 对照仓内实现（落地前 → 落地后）

### 5.1 落地前的仓内实现（历史，2026-11-02 之前）

| 项 | 仓内现状 | 原版实测 | 差异/建议 |
|---|---|---|---|
| 过渡形态 | `transition.rs`：`brightness = \|2t-1\|` 三角波，`alpha = 1-brightness`，**中点全黑** | 单程交叉溶解（旧→新），有掩膜时按掩膜 alpha | **形态不同**。本作唯一调用 kind=-1 → 应建模为 `alpha = (1-t)` 的单程整屏溶解（10 帧，线性），**不是** 5 帧变黑 + 5 帧变亮 |
| 掩膜 | 完全没有掩膜贴图 | `[Transition]Fade.png` 640x480 灰度 **平面斜向线性渐变**（21.5°，带宽 272px，0..251，略 convex） | 若要精确复刻：把该 png 的灰度当逐像素 alpha（掩膜 0 处先露出新画面）。kind>=0 时才用；本作数据**未使用** kind>=0，可保留"未实现掩膜"但把注释改成"kind<0 = 无掩膜交叉溶解"，不要写成"hard cut" |
| 曲线 | 三角波、`progress = elapsed/duration` | `elapsed/duration` 线性、整数除法、每帧 -= `60/FPS` | t 的公式**一致**（线性、无 easing）；只是映射到 alpha 的函数不同 |
| 计时单位 | `frames = flags & 0xFF`，0 当 1 | `duration = flags & 0xffff`（**低 16 位**），每帧减 `60/FPS` | **建议**：`& 0xFF` → `& 0xffff`。本作 flags=0x0001000A，两者都得到 10，无实际影响，但与引擎语义不符 |
| wait 位 | 没建模（总是阻塞 frames 帧，162 无条件 Blocked） | `flags & 0x10000` = wait，**存在非阻塞过渡** | 本作唯一调用 wait=1，无影响；但可在 162 分支里按位决定是否 Blocked |
| 151 语义 | `tint.rs`：`channel = byte/100`，RGB **百分比乘子** | `bright = clamp(255 + (p-100)*255/100, 0, 255)`，DxLib draw-bright | p≤100 时两者近似等价；p>100 时原版会**钳到中性色**（`p=150` 不更亮），仓内会乘 1.5。本作是否有 p>100 需要脚本统计，见 TODO |
| 151 flash | `flash` = 同一 duration 的三角波 lerp（先升后降） | **整屏纯色块 overlay（颜色 = 各通道 p% 的 255 钳顶），alpha 从 255 单向衰减到 0** | 形态**不同**。实例：dungeon 事件 1 的 `0x0196C896`（R150/G200/B150）在原版=**纯白闪一下然后 20 帧淡掉**，仓内=亮度乘到 1.5/2.0/1.5 的彩色脉冲 |
| 151 作用域 | 只乘 `quad.number < 0` 与地图层（`game.rs:1165 apply_screen_tint`） | tint 是 draw-bright 全局状态，作用于**之后画的所有 sprite**（含窗口/HUD，除非该层被显式复位） | **可能过窄**。`FUN_004bf5b0` 有两个分支（含 `SetDrawBlendMode(2,0xff)` 的 HUD 路径），说明至少还有"不受 tint"的分支存在；仓内"仅画面层"是否等价未证实 |
| tint × fade | 同一个 `apply_screen_tint` 里把 tint、fade **逐 quad 相乘** | 两阶段：tint 在 sprite 上，fade 是之后的一层 overlay，且 overlay 前 SetDrawBright 被复位 | **应该改**：fade 不应乘以 tint（也不该乘到 HUD 的 `quad.tint` 上）；理想实现是"先画带 tint 的场景 → 再画一层 mask/alpha 的旧帧 overlay" |

### 5.2 落地后的实现（**已执行**，2026-11-02）

四项建议动作已全部落地，另补了渲染侧 overlay：

| # | 动作 | 落点 | 现在的语义 |
|---|---|---|---|
| 1 | 过渡改单程溶解 | `crates/wolf-game/src/transition.rs` | `ScreenTransition{kind,flags,duration,remaining,active,freeze_requested}`；`install()` 只存参数（160）、`prepare()` 请求冻结（161）、`execute()` 起跑并置 `remaining=duration`（162）；`alpha()=remaining/duration`，旧帧不透明度 1.0→0.0 线性下降；`kind<0` 与 `kind>=0` 走同一均匀溶解（掩膜未实现，本作不用）。三角波整体删除。 |
| 2 | flags 低 16 位 + 三阶段 Host | `crates/wolf-vm/src/exec.rs`、`crates/wolf-game/src/game.rs` | `TransitionState::frames() = flags & 0xffff`；Host trait 由单个 `transition()` 拆成 `transition_install/prepare/execute`，与 160/161/162 一一对应；162 仍阻塞 `frames` 帧（RE：`FUN_0045ceb0` 起跑恒 return true），wait 位不建模（本作恒 1）。 |
| 3 | fade 从 tint 里拆出 | `crates/wolf-game/src/game.rs`、`crates/wolf-game/src/overlay.rs`、`crates/wolf-render/src/overlay.rs`、`crates/wolf-cli/src/main.rs`、`crates/wolf-cli/src/play.rs` | `apply_screen_tint()` 只乘 151 亮度（不再逐 quad 乘 fade）；整屏效果改由 `Game::screen_overlays()` 输出 `ScreenOverlay{Colour,FrozenFrame}`，渲染器在 text pass 之后、present 之前按序合成；161 的冻结请求经 `Game::take_freeze_request()` 交给 `Renderer::freeze()`（必须在上一帧 present 之后调用）。 |
| 4 | 151 改为 DxLib draw-bright + flash overlay | `crates/wolf-game/src/tint.rs` | 普通 151：`rgb = clamp(255+(p-100)*255/100,0,255)/255`，p≥100 钳到中性（不再是百分比乘子）；bit24 flash：独立整屏色块，颜色取同一钳顶公式（`0x0196C896` → 纯白），alpha=remaining/duration 单向衰减，不改 ramp。整数换算复刻 C 的向零截断（40%→102/255、30%→77/255、50%→128/255）。 |

测试同步：`crates/wolf-game/src/transition.rs` 9 个单测、`crates/wolf-game/src/tint.rs` 8 个单测、
`crates/wolf-game/tests/m3_visual_text.rs::screen_transition_and_tint_state_machines`、
`crates/wolf-game/tests/screen_tint.rs::screen_tint_scales_the_tile_layer`；
`crates/wolf-render` 新增 6 个 overlay 单测 + 2 个 GPU 离屏用例（整屏色块覆盖、冻结帧按 alpha 还原）。

## 6. 未闭合项（TODO）

1. `this+0x108`（"二段式过渡"标志）的写入点未找到 → 无法确认"一次 162 = 单程"是否恒成立。
2. `DAT_00a14098/9c`（VM 阻塞帧数）与渲染对象 `+0xf8/+0xfc` 的桥接代码未定位。
3. `FUN_0046ff30(type=0xb, index=kind)` 的资源名模板没在 `.c` 里解出字面串（走 `_sprintf`），
   所以"type 0xb 就是 `[Transition]`"是从 `FUN_004cb840(&DAT_00a14c70)` 前缀 + 唯一的 `[Transition]Fade.png` 推断的，**中-强**置信度。
4. `FUN_004c28d0` 里 `FUN_00528ab0(..., 0x40)` 的第 7 参 `0x40`（blend 类型常量）未与 DxLib 头文件比对。
5. ~~151 的 flash 配色 `FUN_00543f70` 语义~~ → **已核实**：它就是 DxLib `GetColor(r,g,b)`（`all/00543f70` 全文，
   按 `DAT_00a37d78==1` 走 `(r<<16)|(g<<8)|b` 快路径），`FUN_00526390` 就是整屏填充。
6. ~~脚本里是否存在 `p > 100` 的 151~~ → **已确认存在**（dungeon 事件 1 的 flash `0x0196C896` = R150/G200/B150，
   `crates/wolf-game/src/tint.rs:150` 注释），但全数据集里 `p>100` 的**非 flash** 151 仍未枚举（需扫全部 CE 的 151 参数）。