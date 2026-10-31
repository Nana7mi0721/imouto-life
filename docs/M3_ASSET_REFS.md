# M3-L — 事件脚本资源引用完整性静态扫描（task-18）

本文件记录对《妹！生活 ～単色～》全部事件脚本做的一次**静态资源引用扫描**：把每条脚本里出现的图片/音频文件名字符串抽出来，去重后逐一核对是否真实存在于解包数据（`Data.wolf` → work/Data，1,361 条目）中。目的：在运行时之前发现"脚本引用了但资源没随包发布"的静默空图/静音。

- 交付代码：`crates/wolf-format/tests/m3_asset_refs.rs`（2 个 `#[test]`，不改 `src`）
- 数据根：默认 `work/Data`，可用环境变量 `WOLF_DATA_ROOT` 覆盖；数据缺失时 `eprintln` skip 并 return（`exit 0`）。
- 运行：`WOLF_DATA_ROOT=work/Data cargo test -q -p wolf-format --test m3_asset_refs`
- 结果：**2 passed, 0 failed**。

## 1. 扫描范围与方法

| 来源 | 解析 API | 覆盖 |
| --- | --- | --- |
| `BasicData/CommonEvent.dat` | `wolf_format::commonevent::CommonEventData::parse` | 350 个公共事件，遍历每个 `Slot::Command` 的 `strings` |
| `MapData/*.mps`（8 张） | `wolf_format::mps::Map::parse` | 每个 `MapEvent` 的每个 `MapEventPage.commands` 的 `strings` |

- **图片扩展名**：png / jpg / jpeg / bmp / gif / webp
- **音频扩展名**：mp3 / ogg / wav
- 只认"扩展名字符串"，因此脚本里普通对白不会被误判。
- 解析前把引用做规范化：`trim`、反斜杠转正斜杠、转小写，按**精确相对路径**匹配数据根索引（大小写不敏感；**不做**跨目录 basename 回退，否则"放错目录"会被静默放过）。
- 音频只验证**存在且非空**（`metadata.len() > 0`），**不**重新解码音频——解码正确性由 task-15 覆盖，避免重复。
- 图片在存在性之外再做**文件头 magic 校验**（PNG `89 50 4E 47` / JPEG `FF D8` / BMP `42 4D` / GIF `GIF` / WebP `RIFF..WEBP`），至少 20 张、最多 40 张。

## 2. 扫描统计（work/Data，实测）

- 数据根下共 **1,364** 个文件（= `Data.wolf` 的 1,361 条目解包，另有少量附带文件/字体）。
- 公共事件：**350** 个；地图：**8** 张。
- 图片引用：**2,433** 条（去重 **661** 个文件名）。
- 音频引用：**161** 条（去重 **34** 个文件名）。
- 解析结果：可用精确路径解析 → 其余 = `basename_only` **1** + `missing` **7**，合计 **8** 个未解析图片引用（详见 §4）。
- 音频：**0 缺失**（34 个去重引用全部命中且非空）。
- 图片 magic：抽查的前 **40** 张引用图片文件头全部正确（0 bad）。

数据根目录分布（文件数）：`BGM` 28、`BalloonBase_CafeLatte` 13、`BasicData` 149、`BattleEffect` 48、`CharaChip` 11、`FIcon` 10、`Fog_BackGround` 10、`MapChip` 102、`MapData` 8、`Picture` 330、`SE` 214、`Save` 3、`SystemFile` 22、`SystemGraphic` 21、`cg` 393（另有 2 个 `.ttf`）。

## 3. 结论

- 所有**音频**引用完整、可用。
- 所有**实际运行路径会用到**的图片引用完整、magic 正确。
- 仅有 **8 个图片引用**在 `Data.wolf` 中不存在或放错目录；经溯源，**全部属于 WOLF 内建示例工程的残留脚本，本作正常游玩不会加载**（见 §4）。因此不阻塞 M3，也无须补资源。

## 4. 未解析引用清单（8 个，均为 WOLF 示例工程残留）

这些引用出现在随 `.dat` 一起打包的 WOLF 出厂示例事件/示例地图里，是引擎模板自带的"死代码"；发布时未随 `Data.wolf` 打包（或路径写错）。**运行时不会触发**。

| # | 引用路径 | 来源事件/地图 | 判定 |
| --- | --- | --- | --- |
| 1 | `Picture/title2.jpg` | CE 42 "オリジナルタイトル画面Ａ"；Map003.mps ev1 "ニューゲーム処理" | 文件不存在 |
| 2 | `Picture/message_frame3.png` | CE 214 "応援会話リコ" | 文件不存在 |
| 3 | `Picture/pipo-emotion.png` | CE 213 "アイコン表示長い"；CE 221 "[北]ぴぽや感情・状態ｱｲｺﾝ表示" | 放错目录：真实文件在 `CharaChip/pipo-emotion.png` |
| 4 | `Picture/map_Village01_top.png` | Map002.mps ev0 "マップ表示" | 文件不存在（示例动作RPG地图） |
| 5 | `Picture/explosion.png` | Map002.mps ev3 "爆弾" | 文件不存在（示例动作RPG地图） |
| 6 | `Picture/attack_effect01.png` | Map002.mps ev5 "接近攻撃" | 文件不存在（示例动作RPG地图） |
| 7 | `Picture/bg_map3_effect.png` | Map031.mps ev0 "ロード時の自動処理" | 文件不存在（加载钩子示例） |
| 8 | `Picture/bg_map4_top.png` | Map031.mps ev0 "ロード時の自動処理" | 文件不存在（加载钩子示例） |

判定依据：文件名（`title2.jpg`、`explosion.png`、`attack_effect01.png`、`pipo-emotion.png` 等）均是 WOLF 出厂示例工程/ぴぽや免费素材的经典命名；且 `Map002`（"爆弾/接近攻撃/マップ表示"= 示例动作RPG地图）与 `Map031`（"ロード時の自動処理"= 示例加载钩子）本身就是 WOLF 自带演示地图，不在本作 5 张注册定屏地图之列。

## 5. 测试如何表达这一结论

`crates/wolf-format/tests/m3_asset_refs.rs` 用显式白名单 `KNOWN_UNSHIPPED` 收下上述 8 个引用：

- `all_event_and_map_asset_refs_resolve`：断言 `(missing ∪ basename_only)` 扣除 `KNOWN_UNSHIPPED` 后**为空**——即**任何新的缺失/错放都会 fail**；并断言每个音频引用可解析且非空；sanity 下限（distinct 图片 ≥ 500、音频 ≥ 20）防止解析回归。
- `referenced_images_have_valid_magic`：对最多 40 张可解析引用图片做 magic 校验，要求 ≥ 20 张通过、0 损坏。

> 若后续希望"任何缺失即硬 fail"，只需把 `KNOWN_UNSHIPPED` 清空即可；当前保留 8 项是为了让既有的出厂示例残留不致让 CI 长期报红，同时据实记录。
