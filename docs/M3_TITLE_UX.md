# M3-AD — 标题菜单可见性与“取消读档返回标题”链（task-36）

本文件记录《妹！生活 ～単色～》标题画面的菜单可见性问题，以及从“つづきから（继续）→ 读档画面 →
取消（CANCEL）”这条链路上“回不到可操作标题菜单”的原因与最小修复建议。全部结论均以 work/Data 实测为准，
并与日文原版（JP 原版 *.wolf）解包结果逐条比对；未在本机运行原版 Game.exe，凡涉及原版运行时行为的判断
均标注为“未验证”。

仅新增测试与文档，未改动 src。

## 1. 结论摘要

1. **标题菜单不可见是原版脚本数据自身的行为**：标题事件 CE42 把选择肢窗口锚点 Sys3/Sys4 写成
   **-1000 / -1000**（不是官方手册的 -1「デフォルト位置」）。日文原版的 CommonEvent.dat 与 TitleMap.mps
   与中文化版这两条指令逐条相同，因此不是翻译或 Rust 端口的回归。
2. 端口 choice::layout_at_sized 按 Sys3/Sys4 忠实布局，判定该窗口在 1024x576 屏外 → 返回 None，
   不画、不可点。标题上只剩背景美术（picture -2，SystemFile/TitleGraphic2.png），没有任何菜单文字。
   两个版本的标题美术都**没有把「はじめから/つづきから/おわる」烘焙进图片**（目视确认）。
3. **取消读档后被困在无菜单标题**：Boot → 选 menu2（つづきから）→ CE42 → CE14 → CE131（读档画面，
   picture 槽 12000..12113）。按 CANCEL 后 CE131 → CE14(op172) → CE42 → TitleMap event2 页面剩余的
   [60] Sys4=150、[62] 依次执行，整条调用栈全部结束，屏幕上只剩标题背景，既无选择窗口、也无任何
   实例在运行。CE42 的 op102 只弹一次、页面也不循环，因此不会重新弹出标题菜单。
4. 次要：Sys7（選択肢次回初期位置，手册语义：有存档时初选「コンティニュー」）在本作标题处实测为 0，
   端口 choice_cursor() 初始为 0（首项「はじめから」）。端口未实现 Sys7 的初选语义（不影响可见性）。

## 2. 证据

### 2.1 CE42 脚本（原版 vs 中文化，逐条一致）
- CE42 title=“オリジナルタイトル画面Ａ”：
  - [13] op111 normal var 2000199 ∈ {0,1} 分支；[14]/[17] op401 分支 op150 画标题图。
  - [25] op121 ints=[9000003, -1000, 0, 0] → **Sys3 = -1000**。
  - [26] op121 ints=[9000004, -1000, 0, 0] → **Sys4 = -1000**。
  - [27] op102 ints=[19] strings=['menu1','menu2','menu3'] → 3 选项。
  - [28..] op401 分支：はじめから（op130 Teleport 去 Map003）/ つづきから（op210 调 CE14）/ おわる（op175）。
- 日文原版 BasicData.wolf 解出的 CommonEvent.dat 中 CE42 与中文化版**逐条相同**（同样 Sys3/Sys4=-1000、
  op102 menu1..3、op150 TitleGraphic2.png）。提取脚本 work/out/ce42_jp_extract.py，产物 work/out/jp_CommonEvent.dat。

### 2.2 TitleMap event2（原版 vs 中文化，命令相同）
- Map name=“なし”，event id=2「新タイトル用イベント」，1 页，64 条命令。关键：
  - [46] op121 ints=[9000007,1] → Sys7=1（有存档时初选コンティニュー）——本作实测运行时为 0（见 2.5）。
  - [57] op210 ints=[500042, 0] → 调用 CE42（500000+42，阻塞）。
  - [60] op121 ints=[9000004, 150, 0, 0] → **Sys4 = 150**，注释「選択肢ウィンドウの表示位置をやや下に移動」。
    该指令在阻塞调用 CE42 返回后才执行，故对本次标题菜单无效（死代码）。
  - [62] op121 ints=[2000000, 0]。
- 日文原版 TitleMap.mps 的 event2 与中文化版命令完全相同（包括 [57]/[60]）。产物：work/out/jp_TitleMap.mps。

### 2.3 标题美术
- 中文化 work/Data/SystemFile/TitleGraphic2.png：1024x576 RGBA 369221B，md5 76b1014631faba51104bd17cce72efab。
- 日文原版 SystemFile/TitleGraphic2.png：374485B，md5 fbac9aa96cdb910870002264f9b02a1d；与其
  SystemGraphic/TitleGraphic.png 同 md5。两版差异仅左上角标题文字（日/中），**均无菜单文字**。
  提取脚本 work/out/extract_jp_titles.py。

### 2.4 端口实测（boot 到标题选择窗口）
WOLF_DATA_ROOT=work/Data 下探针测得：
- choices.options == [“menu1”,“menu2”,“menu3”]，choice_cursor() == 0。
- choice_anchor() == (-1000,-1000)；sys(3) == -1000，sys(4) == -1000。
- 屏幕只有 picture -2（SystemFile/TitleGraphic2.png），text_quads() 为空，messages 为空。
- 标题事件 42 仍在栈上等待选择；引擎 auto-skip 事件 271 在 boot 期间启动（注册气泡库）后已结束，
  故标题等待时 271 不在运行（测试用 saw_271 记录其确曾运行）。stats.warnings == 0。
- wolf_game::choice::layout_at_sized([“menu1”,“menu2”,“menu3”], 0, -1000, -1000, 20.0) 返回 None
  （choice.rs:177-197 的 on_screen 判定为否）。

### 2.5 取消读档：实测链路
Boot → 选 menu2（cursor=1，auto_choice 延迟 2 帧）→ 逐帧观察到实例栈
[48,63,2,42] → [48,63,2,42,14] → [...,131]，读档画面画出 picture [-2,12000,12001,12002,12005,
12050..12065,12070..12085,12090..12093,12110..12113]，文本含「选择要读取的数据。」及各槽「没有数据」。
此时按 CANCEL（wolf_game::key::CANCEL = 2）后：
- 实例栈塌缩为 [63]（引擎隐式事件），!running(131) && !running(14) && !running(42) && !running(2)。
- sys(3) == -1000、**sys(4) == 150**（证明已越过 op102 跑到了 TitleMap event2 的 [60]）。
- choices == None，text_quads() 空，messages 空，屏幕仍留标题背景 picture -2，warnings 不变。
即：整条调用栈结束，停在一个**无菜单、无事件驱动**的标题背景上（软锁）。

## 3. 根因

- **可见性**：CE42 把 Sys3/Sys4 置 -1000（屏外）；端口忠实布局 → 不画。属数据自身怪癖。
- **取消读档回不到标题**：标题菜单由 CE42 内**一次性** op102 呈现；CE131(CANCEL) 结束 → CE14(op172)
  → CE42 继续执行到结束 → TitleMap event2 页面 [60][62] 执行完 → 页面结束。TitleMap 是 autorun 页，
  map_runtime 每页只激活运行一次、不循环；CE42 也无回到 op102 的循环。于是没有任何逻辑重新弹出菜单。
  这不是 map_runtime 的“错误”，而是“标题菜单只弹一次 + 结束后无人重启”的组合结果。

## 4. 最小修复建议（仅建议，未改 src）

1. **让标题菜单可见/可点（布局层）**：在 crates/wolf-game/src/choice.rs 的 layout_at_sized（或 Game 取
   anchor 处）把“越界锚点”或官方语义的 **-1「デフォルト位置」** 视为回退——使用居中 layout() 或把面板
   clamp 进屏幕。这会同时覆盖数据里的 -1000。改动点极小、集中，且不改变其它已在屏内的选择肢。
   - 同时建议修正 choice.rs:162-173 的文档注释：现写“parked at (512,1000)”，与实测 (-1000,-1000) 不符。
2. **取消读档后重新进入标题菜单（控制流层）**：在 Game（如 frame 收帧后）检测“当前处于标题地图、调用栈
   已空（仅剩引擎常驻事件）”时，重启标题事件（CE42）或重跑 TitleMap event2 autorun 页；或让 map_runtime
   对标题地图的 autorun 页循环。二者取其一即可让 CANCEL 后回到可操作菜单。
3. （可选）实现 Sys7「選択肢次回初期位置」初选语义（有存档初选「コンティニュー」），与手册一致；实测
   本作标题处 Sys7=0、端口 cursor=0，属次要 UX 差异。

以上 1、2 是独立的两件事：1 解决“启动时菜单不可见”，2 解决“读档取消后软锁”。

## 5. 未验证 / 不确定度

- 无法在本机运行原版 Game.exe，**未能直接观察原版标题菜单是否可见**。若原版严格按 -1000 布局，则原版亦
  无可见菜单（只能键盘盲选），暗示原版引擎可能对越界锚点做了 clamp、或 VER6 时代引擎行为不同。该点保持
  “未验证”，不作断言。
- 原版取消读档后是否同样软锁未验证；本文只对**端口实测行为**下结论。

## 6. 测试与命令

新增：crates/wolf-game/tests/m3_title_visibility.rs（4 个用例，数据缺失时 eprintln + return，默认 exit 0）：

- title_menu_options_are_parked_off_screen：钉住当前忠实行为——三选项存在、anchor (-1000,-1000)、
  layout_at_sized 为 None、屏上仅标题背景、无文本图、事件 42 在跑、271 于 boot 期间运行过后结束、warnings=0。
- a_valid_anchor_would_show_the_title_menu：纯布局数学——同一三选项在 (512,300) 与居中 layout 下面板均在
  屏内且每项一行（证明“把越界 / -1 视为默认位”的修复足以让菜单可见）。
- cancelling_the_load_screen_unwinds_to_a_menu_less_title：复现取消链路，断言栈全部结束、Sys4=150、
  Sys3=-1000、choices 无、无文本/消息、标题背景仍在、warnings 不变。
- a_fresh_boot_reenters_the_title_menu：验证“重启”可行路径——全新 Game::new + boot() 能再次得到同一
  三选项标题菜单（支撑修复建议 2）。

运行：

    cd '/e/Study/github program/Imouto Life' && source tools/env.sh
    WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-game --test m3_title_visibility
    # 结果：4 passed; 0 failed
    cargo build -q -p wolf-game   # exit 0

数据缺失版（WOLF_DATA_ROOT=/nonexistent/path）同样 4 passed、exit 0。
