# 暂停工作状态（2026-11-03 00:02 用户关机暂停）

## 当前目标
继续 task-10 存档界面布局与背景修整（用户 m02832/m02834：看到/听到/玩到与原版一致）。

## 已完成并验证（本次暂停前）
- 文本解码修复已完工（task-8，已 complete）。
- event reachability 初版已做（task-9 仍 in_progress）。
- 存档槽名称文本水平居中已修：crates/wolf-game/src/game.rs 的 text_quads 对 picture.anchor==3 改用 0x83（水平居中、y 保持 top），textpic.rs anchor_origin 增加 0x83 分支。
- 左列“数据N/0:00”x 缩放已修：game.rs text_quads 中 x 从 (picture.x+dx)/ui 改为 picture.x + dx/ui（tenths 块 x 已是像素、dx 仍是十分之一）。capture 实测槽1行1 ink x=71..122 vs 参考 68.2..119.1，基本对齐；名字块右缘 529 vs 参考 529.2，已对齐。

## 尚未完成 / 待续
- 槽间黑带：12050 WindowBase_amania 与 12051 CursorBase 同 rect；CursorBase 的 tint 当前被解析为 [0,0,0]（args 颜色为 0，被当黑色 tint），导致面板边缘全黑、WindowBase 的浅色 bevel 被盖掉。参考图分隔线在 ly199 有 213 亮线。
  - 下一步：查 picture.rs 的 150 颜色参数解码/apply，确认颜色 0 是“无色/不变”还是黑色；让 CursorBase 使用中性 tint（或把 CursorBase 排在 WindowBase 之前画/内缩 3px），再 capture 对比。
- 需要清理的临时调试代码（未提交）：
  - crates/wolf-game/src/game.rs text_quads 中 WOLF_DEBUG_TEXTPOS 的 TXTPOS/SELF eprintln。
  - crates/wolf-vm/src/exec.rs 中 WOLF_DEBUG_ARITH 的 ARITH eprintln（打印 target 1600051/1600052）。
  - crates/wolf-game/src/atlas.rs 中 WOLF_DEBUG_PANEL 的 PANEL eprintln。
  - crates/wolf-format/examples/dump_event.rs 的 anchors/scan 模式（RE 辅助）。
- 未跑最终 cargo test -q -p wolf-game / workspace，未清理 target，未更新 docs/HANDOFF_M0.md。
- task-10 的最终交付（saveui_layout.png、title/map_idle/hud 无回退、测试）尚未完成。

## 关键实测数据（供续接）
- capture 命令：WOLF_DATA_ROOT="$PWD/work/Data" ./target/debug/wolf-cli.exe capture --root work/Data --map SampleMapA --event 5 --frames 40 --out work/out/play_gpu/saveui_text1.png
- 当前面板：12050 WindowBase_amania dst=[48,86.4,928,115.2] tint=1；12051 CursorBase 同 dst tint=[0,0,0]。
- 文本：12052 raw(48,864) dx224 anchor0 -> 70.4；12053 -> 76.8；12055 raw(1001,1680) anchor3 -> 居中到 512。
