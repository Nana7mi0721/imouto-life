# 发布打包（M4-PACKAGE）

把 Rust 重写版构建成一个可分发的目录 `work/out/dist/<version>/`，包含可执行文件、
用户 README、Windows 启动器与校验和。**不打包、不提交游戏数据**（`work/Data`、`.exe`
都在 `.gitignore` 中）。

## 1. 一键打包

msys / git-bash（推荐）：

```bash
cd "/e/Study/github program/Imouto Life"
source tools/env.sh >/dev/null 2>&1
bash tools/package.sh                 # 构建 release 并打包到 work/out/dist/<version>/
bash tools/package.sh --skip-build     # 复用已有 target/release/wolf-cli.exe
bash tools/package.sh --verify --data-root work/Data   # 打包后跑一次 verify 冒烟
```

Windows PowerShell（等价实现）：

```powershell
powershell -ExecutionPolicy Bypass -File tools/package.ps1
powershell -ExecutionPolicy Bypass -File tools/package.ps1 -Verify -DataRoot work/Data
```

两者行为一致：`cargo build --release -p wolf-cli` → 拷 `wolf-cli.exe` → 由
`tools/package/README.txt`、`tools/package/launcher.cmd` 模板渲染出 `README.txt`、
`Play-ImoutoLife.cmd`（替换 `{{VERSION}}` / `{{BUILT}}`）→ 生成 `checksums.txt`。

版本号默认取根 `Cargo.toml` 的 `[workspace.package] version`，可用 `--version` / `-Version` 覆盖。
输出根默认 `work/out/dist`，可用 `--out-root` / `-OutRoot` 覆盖。

## 2. 产物结构

```
work/out/dist/<version>/
  wolf-cli.exe           # release 构建（约 3-8 MB），单文件运行
  README.txt             # 面向用户的说明（数据准备、启动、诊断命令、校验）
  Play-ImoutoLife.cmd    # 双击启动器，自动定位数据根
  checksums.txt          # 各文件 SHA-256，格式 "<hash>  <name>"（sha256sum -c 可用）
```

这些文件全部位于 `work/` 下，天然被 git 忽略；`tools/**` 与 `docs/PACKAGING.md` 才是
需要检查/提交的源文件。

## 3. 数据根解析（启动器与 wolf-cli 的一致性）

`wolf-cli` 的数据根解析顺序（`default_root()`）：`--root/-r` 参数 > 环境变量
`WOLF_DATA_ROOT` > 默认 `work/Data`。数据根必须是**解包后的目录**，含 `BasicData/` 与
`MapData/`（BGM/SE/图片/字体都在其下）。运行时**不能**直接挂 `Data.wolf` 原始包；
`--wolf` 仅用于 `verify` 逐字节比对。

`Play-ImoutoLife.cmd` 在调用 `wolf-cli.exe play` 前按同样思路定位数据根：

1. 第一个命令行参数（可带引号的路径）；
2. 环境变量 `WOLF_DATA_ROOT`；
3. 启动器同目录下的 `Data\`（存在 `Data\BasicData` 时）。

找到后执行 `wolf-cli.exe play --root "<数据根>" <其余参数...>`。窗口 1024x576；
方向键移动，Enter/Z 或鼠标确定，F12 重启；追加 `--audio` 播放 BGM/SE（无音频设备时
自动静音）。找不到数据根时给出提示并以退出码 2 结束。

## 4. 字体

`font_paths()` 的查找顺序：`Game.dat` 的 `font_main`（"Microsoft Yahei UI Bold"）→
内置字体常量 `BUNDLED_FONT_NAMES`（在 `<root>/Fonts`、`<root>`、安装目录搜索）→
其它 `*.ttf/otf/ttc`。Windows 通常自带 `msyhbd.ttc`；缺失时回退到数据目录/安装目录内
附带字体。发布包不额外内嵌字体。

## 5. 验收（本任务执行记录）

```bash
source tools/env.sh >/dev/null 2>&1
bash tools/package.sh            # 期望：cargo build --release exit 0，打印 dist 列表
ls -l work/out/dist/<version>/   # 期望：wolf-cli.exe README.txt Play-ImoutoLife.cmd checksums.txt
```

打包脚本只新增文件、不触碰 `src/` 与测试；如需回归验证，另跑
`cargo test -q --workspace`、`WOLF_DATA_ROOT=work/Data cargo test -q --workspace` 与
`wolf-cli verify`。

## 6. 常见坑

- `*.exe` 与 `work/` 都被 git 忽略，dist 产物不会误提交；提交前 `git status` 确认只含
  `tools/package*` 与 `docs/PACKAGING.md`。
- 用 PowerShell 5.1 读 UTF-8 模板时务必显式按 UTF-8 读取（脚本已用
  `[System.IO.File]::ReadAllText(..., UTF8)`），否则中文 README 会乱码。
- 启动器 `.cmd` 以无 BOM 写回（BOM 会破坏 `@echo off` 首行）；模板本身为 CRLF。
- 数据根必须是解包目录，不是 `Data.wolf`；`play` 不接受 `.wolf`。
- 不改 `game.rs`/`tilemap.rs` 等范围外文件；本任务是纯打包交付物。

