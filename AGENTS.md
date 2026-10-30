# AGENTS.md — 协作与工程约定（《妹！生活 ～単色～》Rust 重写）

本文件是每个 agent（Lead / 子代理 / teammate）开工前必读的操作约定。项目总览、数据勘察结论、代际差异与陷阱见 docs/HANDOFF_M0.md；动代码前先读它。

## 0. 最高优先级：多用子代理并行

- **模型额度有期限，尽量把可并行的任务拆开并行推进**：能独立完成的调研、测试编写、某个 crate/文件的实现，优先交给子代理/teammate 同时做，Lead 负责拆分、去冲突、验收与文档。
- **写作用域必须互不重叠**：拆任务时把「要改的文件/目录」写进共享任务的 write_scopes；一个文件同一时间只允许一个 owner 改。新增测试文件天然适合并行（每人一个 tests/xxx.rs）。
- 依赖关系用 blocked_by：例如「依赖鼠标输入的菜单测试」必须等输入桥接任务完成后再跑。
- 每完成一个任务就向 lead send_message 汇报：改了什么文件、跑了什么命令、测试输出、坑；不要各自 commit。

## 1. 每次 bash 的固定开头

```bash
cd '/e/Study/github program/Imouto Life' && source tools/env.sh >/dev/null 2>&1
```

- 路径用 msys 形式（/e/...）；PowerShell 路径只在 env.ps1 等 Windows 脚本里用。
- 保持 C:/Users/REISEN/.cargo/config.toml 里的 [http] proxy=''；不要开 sccache（会破坏 MSVC 链接）。
- 临时输出放 work/out/，不要用 /tmp（Windows 上 bash 子进程写 /tmp 会 PermissionDenied）。
- Python 补丁脚本写 newline='' 并先写 .new 再 os.replace。

## 2. 数据与测试

- 数据根是 **work/Data**（已解包的本作数据，175MB，已 gitignore）。不要把它提交进 git。
- 默认 `cargo test -q --workspace` 会跳过需要数据的用例（缺数据就 eprintln skipping 后 return），必须保持 exit 0。
- 真正跑本作数据测试用：`WOLF_DATA_ROOT=work/Data cargo test -q -p <crate>`。
- 每个里程碑结束跑：`cargo test -q --workspace`、`WOLF_DATA_ROOT=work/Data ./target/debug/wolf-cli.exe verify`（PASS 64 / 1 SKIP 为 M0 基线），需要时再跑 `verify --wolf <安装目录>/Data.wolf`。
- 本作自己的期望值在 docs/BASELINE.json；**不要照抄姊妹作 imoto life 的 BASELINE.json**（那是第一部游戏的数值）。

## 3. Godot / 截图 / 前台

- **不要用 PowerShell 抢前台或模拟按键截图**（用户明令会打断他操作电脑）。截图只能由用户按游戏内 PrintScreen（Game.ini ScreenShotFlag=1，产物在安装目录，1024x576 原生）。
- 需要视觉核对时优先用已有实机截图（docs/REFERENCE.md 有 10 张目录）或读用户新截图；headless capture 的 wgpu 离屏初始化目前卡死，属渲染阶段问题，不要在这上面硬耗。

## 4. 本作特有的“不要做”

- 不要为 Sys 变量 104/105 建 player/camera/滚动模型：本作 5 张注册地图全是定屏，脚本不读写这两个变量，引擎只需输出常量。
- 不要把 opcode 104（本作没有）或战斗模板当待实现功能；战斗表/ BattleEffect 资产是可标死的模板残留。
- 不要把 .wolf 解密当难题（VER6 已解开、verify --wolf 1,361/1,361 逐字节通过）。
- 没读官方说明书/实机截图前，不要凭调研报告臆造 UI 数值。

## 5. 代码与提交

- 仓库是 Cargo workspace，7 个 crate：wolf-format / wolf-save / wolf-vm / wolf-render / wolf-audio / wolf-game / wolf-cli。
- 不新增外部依赖，除非有充分理由并先问 lead。
- 提交身份：`git -c user.name='imoto lead' -c user.email='lead@imoto.local' commit -F <msgfile>`。
- push：全局 http.proxy 是死代理，必须 `git -c http.proxy= -c https.proxy= push origin master`。
- 不要提交 work/、tools/bin|cmake|ffmpeg、*.exe、prt sc/、docs/相关链接.txt。
- 每推进一步更新 docs/HANDOFF_M0.md 的「进度」段（方便下次交接）；里程碑结束写对应的 docs/M*_*.md 说明。

## 6. 内容安全

- 面向用户的说明与代码注释避免露骨性词汇，保持中性技术描述（否则可能触发 Provider content_filter）。
