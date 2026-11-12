# 归档区（docs/archive/）

本目录存放**已完成、已被取代或仅供追溯**的文档。归档不等于删除：保留证据链，
但其中的数字、行号、结论都**不再代表当前工程事实**。

## 归档清单

| 文件 | 归档原因 | 现行替代 |
|---|---|---|
| [HANDOFF_NEXT_AGENT.md](HANDOFF_NEXT_AGENT.md) | 2026-11-11 的 POST_DEEPSEEK 19 项修复交接，任务已完成并闭环 | [../HANDOFF_M0.md](../HANDOFF_M0.md)（项目现状）、[../HANDOFF_PROGRESS.md](../HANDOFF_PROGRESS.md)（历史日志）、[../HANDOFF_DEEP_REVIEW_FIX.md](../HANDOFF_DEEP_REVIEW_FIX.md)（当前修复交接） |
| [reviews/CODE_REVIEW_1_2ROUND_superseded.md](reviews/CODE_REVIEW_1_2ROUND_superseded.md) | 第一、二轮审查单行本（BUG-25..40），已被第一至四轮总报告完整收录 | [../reviews/CODE_REVIEW_4ROUND.md](../reviews/CODE_REVIEW_4ROUND.md) |

## 使用规则

- 需要引用历史结论时，先确认现行文档是否已覆盖；**不要从归档文档直接抄数字或行号**。
- 归档文档不删除；如需更正归档内容，只在文件顶部加“归档说明”，不改写原始记录。
- 新归档项的命名：交接类 `HANDOFF_<主题>.md`；审查类放 `reviews/`，文件名带 `_superseded` 或轮次。
