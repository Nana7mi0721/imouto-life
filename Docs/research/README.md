# docs/research — 调研与实证资料

这里放**一手/二手调研资料**，不是当前实现的事实源。

- [M7_PRNG.md](M7_PRNG.md) — PRNG 实证：Game.dat 的 static-random 块是预生成表，`random_a/b` 是生成器输出 K1/K2 而非种子；姊妹作 28,936/28,936 字节全等，本作前 1,055 字节全等、之后为汉化补丁改写/损坏，按原字节消费。结论已在 M3 落地。
- 6 份 GPT 深度调研报告与前置问题组在 [gpt-reports/](gpt-reports/)（`deep-research-report*.md`、`GPT_RESEARCH_GROUPS.md`），其中若干条已被本作数据实测推翻，**采信/推翻清单见 [../HANDOFF_M0.md](../HANDOFF_M0.md) §7**。
