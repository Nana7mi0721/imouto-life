# 代码审查报告目录（docs/reviews/）

本目录存放**面向当前工程的代码审查报告**。审查报告是缺陷台账与修复依据，不是引擎规范；
引擎行为以 `docs/ENGINE_BEHAVIOR.md` 与 `docs/re/` 的实测证据为准。

## 现行报告

| 文件 | 状态 | 范围 |
|---|---|---|
| [CODE_REVIEW_4ROUND.md](CODE_REVIEW_4ROUND.md) | **现行 · 唯一审查事实源** | 第一至四轮完整版（2026-11）：历史基线 BUG-20..24；第一轮 BUG-25..35；第二轮 BUG-36..40；第三轮 BUG-41..46；第四轮 BUG-47..48；含系统性架构建议 |

## 专项审计

| 文件 | 状态 | 范围 |
|---|---|---|
| [T13_UI_REGRESSION_AUDIT.md](T13_UI_REGRESSION_AUDIT.md) | 现行 · UI/命中盒专项 | 2026-11-12 用户 15 项截图缺陷逐项复核；91 passed / 2 ignored，中央对话双源仍开放 |

## 轮次与缺陷编号

| 轮次 | 缺陷编号 | 主题 |
|---|---|---|
| 历史基线 | BUG-20..24 | 深水区审计遗留项（滚轮、鼠标出界、character_state、全屏特效、按键连发） |
| 第一轮 | BUG-25..35 | 核心架构与调度器、变量寻址、输入、存档、文本层 |
| 第二轮 | BUG-36..40 | 全量字节码指令语义（176 / 140 / 220..222 / 130 / 151）与前端开销 |
| 第三轮 | BUG-41..46 | 真实二进制资产 + `wolf-gdext` / `GameView.gd` 跨语言管线 |
| 第四轮 | BUG-47..48 | 图层几何、`Opcode 124` 复合算子、`PictureAction::Erase` 淡出 |

## 阅读注意

- 报告中的行号对应其写作时的快照；修复后行号会漂移，**以符号名和报告描述的行为为准**。
- 报告的部分结论已被实测修正（例如 `ENGINE_RESTART` 取值、`Opcode 121` flags、
  `Opcode 151` 首参、blend 编码）。差异清单与证据见
  [../HANDOFF_DEEP_REVIEW_FIX.md](../HANDOFF_DEEP_REVIEW_FIX.md) §5。
- 第一、二轮单行本已被现行报告收录，归档在
  [../archive/reviews/CODE_REVIEW_1_2ROUND_superseded.md](../archive/reviews/CODE_REVIEW_1_2ROUND_superseded.md)，
  仅作证据链保留，不要再作为现行依据。
- 新审查报告命名建议 `CODE_REVIEW_<轮次或日期>.md`，并在 `docs/README.md` 登记；
  被取代的旧报告移入 `docs/archive/reviews/`。
