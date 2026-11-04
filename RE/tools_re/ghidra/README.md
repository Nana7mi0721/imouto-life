# tools/re/ghidra — Ghidra 12.2 headless decompile helpers

用于对原版 `Game.exe`（WOLF RPG Editor ver2.22, PE32/i386, DxLib 静态链接）做批量反编译、
按字符串锚点定位引擎常量实现。产出的是 Ghidra 伪 C，用于核对 `docs/ENGINE_BEHAVIOR.md` §3
的引擎常量，不做自动改写。

## 环境前提

| 项 | 值 |
| --- | --- |
| Ghidra | `D:\Program\ghidra_12.2_PUBLIC` |
| JDK | `D:\Program\Java\jdk-25.0.5+8`（Ghidra 12.2 需要 JDK 21+，这里固定 25） |
| 项目目录 | `work/out/ghidra/proj` |
| 项目名 | `ImoutoLife` |
| Program 名 | `Game.exe`（import 自 `work/out/ghidra/input/Game.exe`） |
| 输出目录 | 默认 `work/out/re_dump` |

项目必须已经 import 并完成自动分析（见 `work/out/ghidra/import.bat`）。脚本一律用
`-process ... -noanalysis` 复用现成分析结果，不重新分析、不修改项目。

## 文件

| 文件 | 作用 |
| --- | --- |
| `DumpByAnchor.java` | 按字符串锚点（或 `--va=`）找引用点 → 所属函数 → 反编译，一个函数一个 `.c` |
| `DumpAll.java` | 把所有自定义函数反编译成 `<outdir>/all/<entry>_<name>.c` + `index.tsv`，便于全量 grep |
| `run_ghidra.sh` | MSYS bash 封装：生成 `.bat` 用 `cmd //c` 调 `analyzeHeadless.bat`，参数走 UTF-8 args 文件 |

## 为什么这么绕

1. **必须用 .bat，不能用 `support/analyzeHeadless`**：Git-Bash 下 POSIX launch 脚本的 JDK
   探测会失败，而且本仓库路径含空格。
2. **参数不走命令行，走 args 文件**：`analyzeHeadless.bat` 的参数循环开了
   `EnableDelayedExpansion`，且每行 .bat 还会做一次 `%@ 展开，所以
   `WindowModeFlag=%d` 会被吃成 `WindowModeFlag=d`，含 `!` 的参数也会丢。
   `run_ghidra.sh` 把输出目录和全部脚本参数写进 UTF-8 文件（一行一个），只把
   `--argsfile=<path>` 交给 cmd；`DumpByAnchor` / `DumpAll` 会先展开这个文件。
3. **路径全部转 Windows 形式**（`cygpath -w`），JAVA_HOME 用 Windows 形式写进 bat。

## 用法

```bash
cd '/e/Study/github program/Imouto Life'
source tools/env.sh >/dev/null 2>&1

# 1) 按字符串锚点定位（最常用）
./tools/re/ghidra/run_ghidra.sh DumpByAnchor \
    "[Read]Screen size X" "WindowModeFlag=%d" "*.ttf" "*.ttc"

# 2) 直接给 VA（跳过字面量搜索）
./tools/re/ghidra/run_ghidra.sh DumpByAnchor --va=0x007ca638

# 3) 换输出目录 + 保留生成的 bat/args（排障用）
./tools/re/ghidra/run_ghidra.sh --out-dir="$PWD/work/out/re_dump_s3" --keep-bat \
    DumpByAnchor "DefaultFontName=%s"

# 4) 只打印将要执行的 bat 与 args 文件，不真正跑
./tools/re/ghidra/run_ghidra.sh --print-only DumpByAnchor "WindowModeFlag=%d"

# 5) 全量反编译（2187 个 >=200 字节的函数；很慢，可 Ctrl-C 中断）
./tools/re/ghidra/run_ghidra.sh --max-cpu=8 DumpAll --min-size=200
# 只看某些函数
./tools/re/ghidra/run_ghidra.sh DumpAll --filter='FUN_0040.*' --min-size=100

# 6) 全量结果里 grep 常量
grep -rn "WindowModeFlag" work/out/re_dump/all/*.c | head
```

`run_ghidra.sh` 的包装选项（必须写在脚本名之前）见 `--help`：`--out-dir=`、
`--max-cpu=`、`--analyze`、`--project=`、`--project-name=`、`--program=`、
`--keep-bat`、`--print-only`。

### DumpByAnchor 参数

| 参数 | 说明 |
| --- | --- |
| `<outdir>` | 第一个位置参数（由 run_ghidra.sh 自动注入） |
| `[anchor text]` | 任意多个字符串锚点（按给定编码的原始字节在内存里搜） |
| `--va=0x...` | 直接把 VA 当锚点，不做字面量搜索 |
| `--max-depth=N` | 指针间接层数，默认 2 |
| `--max-xref=N` | 每个锚点最多收集多少个引用点，默认 200 |
| `--ref-window=N` | 锚点本身没有引用时，在 ±N 字节内找最近的被引用地址，默认 64 |
| `--timeout=SEC` | 单函数反编译超时，默认 60 |
| `--enc=cp932` | 用指定字符集把锚点编码成字节（日文锚点常用；默认 UTF-8，找不到再试 UTF-16LE） |
| `--no-scan-ptr` | 关掉 4 字节裸指针扫描（更快，但会漏掉指针表引用） |
| `--skip-existing` | 不覆盖已存在的非空 `.c` |
| `--argsfile=PATH` | 从 UTF-8 文件读参数（run_ghidra.sh 用；手工调用不需要） |

输出：`<outdir>/<funcEntry>_<sanitized-anchor>.c`，文件头写函数名/入口/大小/锚点/字符串
VA/引用点/状态，另写 `<outdir>/anchor_summary.tsv`。同一个锚点命中同一个函数时自动去重
（不会重复写多份）。

### DumpAll 参数

| 参数 | 说明 |
| --- | --- |
| `<outdir>` | 第一个位置参数（自动注入） |
| `--min-size=N` / `--max-size=N` | 按函数体字节数过滤 |
| `--filter=REGEX` | 按函数名过滤（Java 正则，`find()` 语义） |
| `--include-thunks` / `--include-external` | 连 thunk / 外部函数一起导（外部函数没有函数体，反编译必然失败） |
| `--limit=N` | 只导前 N 个（冒烟测试用） |
| `--timeout=SEC` | 单函数反编译超时，默认 60 |
| `--dir=NAME` | 输出子目录名，默认 `all` |
| `--skip-existing` | 断点续跑：已存在的非空 `.c` 跳过 |
| `--quiet` | 只打最终统计 |

输出：`<outdir>/all/<entry>_<name>.c`（文件头带 entry/size/status）和
`<outdir>/all/index.tsv`（`entry<TAB>name<TAB>size<TAB>file`）。进度每 25 个函数打印
一行；`TaskMonitor` 被取消（Ctrl-C）时会在当前函数后停下，`index.tsv` 保留已写完的条目。

## 已知限制

- **没有分析的项目没有 xref**：`-noanalysis` 复用的项目必须已经跑完自动分析。
  若只 import 没分析，锚点能搜到地址但引用数为 0，也就反编译不出函数
  （冒烟测试可以看 `--va=0x401000` 是否有引用）。
- **字符串搜索是原始字节匹配**：UTF-8/ASCII 直接搜；日文串要用 `--enc=cp932`
  （Ghidra 参数经 args 文件是 UTF-8，脚本再按 cp932 编码成字节）。
- **拼接字符串块**：WOLF 的 ini 键值串常被拼成一大段（如
  `Start=%d\nSoftModeFlag=%d\nWindowModeFlag=%d\n...`），锚点命中的是块中间，引用指向块首。
  `--ref-window` 就是干这个的（默认 64 字节；块很长时调大，如 `--ref-window=512`），
  会打印 `(base 0x...)` 说明用的是哪个基址。
- **指针表**：除 Ghidra 自带引用外，还会扫内存里「4 字节等于目标地址」的槽位
  （`PTR-SCAN`），并支持向下追 `--max-depth` 层；这只覆盖绝对指针，相对偏移/
  运行时计算的表结构抓不到。
- **超大函数**：`FUN_00401c50`（约 88 KB）反编译出来约 82 万字符，单文件很大，内存要够
  （headless 默认 2G，可设 `GHIDRA_HEADLESS_MAXMEM=4G`）。
- **外部函数无法反编译**：`--include-external` 会把 `EXTERNAL` 地址空间的函数导出来，
  但反编译一定失败（`Cannot marshal address space: EXTERNAL`），文件里只有失败备注。
- **项目锁**：项目被 GUI 或另一个 analyzeHeadless 打开时 `.lock` 存在，本次调用会直接失败
  （`Could not find project` / `Project is locked`）。等对方跑完再来。
- **时间**：全量 2187 个 >=200B 的函数约数小时量级（单个 88 KB 函数就要十几秒），建议按需
  `--filter` / `--min-size` 收窄；DumpByAnchor 通常几十秒出结果。
- 脚本只写输出目录，不 commit、不改 `work/out/ghidra/proj`。

## 本机验证记录（2026-11）

- `javac --release 21` + 全量 Ghidra jar classpath 编译通过（GhidraScript 在
  `Features/Base/lib/Base.jar`）。
- 在 Lead 分析完的项目**拷贝**上实跑（避免并发锁）：
  - `[Read]Screen size X` → `0x007ca638` → `FUN_00401c50`（88 KB）→ 写出 C。
  - `WindowModeFlag=%d` → 5 处命中，命中点在拼接串块中间，`--ref-window` 归位到块首后
    找到 `FUN_00401c50` 与 `FUN_0042baa0`；后者 C 里能看到
    `Start=%d\nSoftModeFlag=%d\nWindowModeFlag=%d\n...` 字面量。
  - `*.ttf` → `FUN_00469820`（字体加载，7.6 KB）。
  - `DumpAll --min-size=200 --limit=5` → 5 个函数 11 秒，`index.tsv` 正常。
