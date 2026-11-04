# Imouto Life — 解包产物与逆向资料

本仓库的 `assets` 分支用于存放《妹！生活 ～単色～》的**已解包游戏数据、音乐/图片素材、逆向分析资料与截图证据**。源码仍在 `master` 分支，保持精简。

> 素材版权归原作者/发行商所有。本仓库仅用于个人研究、汉化与存档分析，请勿公开传播或用于商业用途。仓库为私有仓库。

## 内容

| 目录 | 文件数 | 大小 | 说明 |
|---|---:|---:|---|
| `Data/` | 1,364 | 176 MB | WOLF 数据解包产物：BGM 70M、cg 49M、BattleEffect 16M、SE 12M、Picture 11M、MapChip/MapData、SystemGraphic、BasicData、字体与存档样本 |
| `RE/re_all/` | 4,376 | 27 MB | Ghidra 反编译 C 伪码，4,375 个 ≥64B 函数，附 `index.tsv` |
| `RE/re_anchor/` | 4 | 972 KB | Anchor/GDI 专项反编译证据 |
| `RE/re_dump_gdi/` | 8 | 128 KB | GDI 绘制路径专项 dump |
| `RE/docs_re/` | 6 | 156 KB | 逆向笔记（渲染常量、事件可达性等） |
| `RE/tools_re/` | 7 | 80 KB | Ghidra 脚本与 `wolfpe.py` PE 探针 |
| `Screenshots/reference/` | 34 | 17 MB | 原版实机截图（1024×576 原生） |
| `Evidence/archive/` | 45 | 4.2 MB | 报告、事件 dump、证据截图与历史提交说明 |
| `Evidence/shot_metrics/` | 59 | 8.2 MB | 截图度量脚本、标注图与 metrics JSON |
| `Evidence/wolfmanual/` | 1 | 1.1 MB | 官方说明书图片归档 |
| `Evidence/event_reach/` | 5 | 208 KB | 逐事件可达性审计表 |
| `Docs/` | 63 | 1.2 MB | 引擎行为、RE 笔记、HANDOFF、翻译目录等文档 |
| `MANIFEST.tsv` | — | 348 KB | 全量文件 SHA-256、字节数、相对路径 |

合计约 **5,974 个文件、235 MB**（不含 `.git`）。

## 获取

只拉取解包产物，不下载源码历史：

```bash
git clone --single-branch --branch assets --depth 1 https://github.com/Nana7mi0721/imouto-life.git imouto-life-assets
```

源码：

```bash
git clone --single-branch --branch master https://github.com/Nana7mi0721/imouto-life.git imouto-life
```

## 校验

`MANIFEST.tsv` 每行格式为：

```text
<sha256>\t<bytes>\t<relative/path>
```

可用以下命令逐文件校验：

```bash
cd imouto-life-assets
while IFS=$'\t' read -r hash size path; do
  actual=$(sha256sum "$path" | cut -d' ' -f1)
  [ "$actual" = "$hash" ] || echo "MISMATCH $path"
done < MANIFEST.tsv
```

## 目录约定

- `Data/` 对应原项目 `work/Data/`，是 WOLF 归档解包后的可读数据。
- `RE/` 对应原项目 `work/out/re_all/`、`re_anchor/`、`re_dump_gdi/`、`docs/re/` 与 `tools/re/`。
- `Screenshots/` 对应 `prt sc/`。
- `Evidence/` 与 `Docs/` 对应原项目 `work/out/_archive/`、`work/out/shot_metrics/`、`work/out/wolfmanual/`、`work/out/event_reach/` 与 `docs/`。

生成时间：2026-11-04。
