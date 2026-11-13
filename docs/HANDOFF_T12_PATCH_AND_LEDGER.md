# T12 性能补丁与 BUG-20..24 双台账收口 —— 会话存档（2026-11-13）

> **状态**：代码与文档改动均已落地，**未 commit**。本文件只记录本会话的判断与证据，
> 便于下次会话不经回溯对话即可接手。
> **关联文档**：`docs/TASKS_REMAINING_BUGS.md` §0、`docs/HANDOFF_M0.md` §11.1/§11.3、
> `docs/HANDOFF_PROGRESS.md` 2026-11-13「T12 性能补丁与两套 BUG-20..24 口径收口」条目。
> 紧随其后的审计轮（截图 6 项 + P1/P2）见 `docs/AUDIT_REBUILD_FIX_REPORT.md`。

## 1. 结论摘要

* 改动 9 个文件（+118 / −57）：3 个代码文件、6 个文档文件。
* 2026-11-13 续查另动 3 个文件：`game.rs`（停靠侧栏 alpha 复原）、`m14_visual_regression.rs`
  （文本计数重钉）、`wolf-gdext/src/lib.rs`（选项切片去双 clone）。
* 定向回归（真实数据 `work/Data`）：`m16_old_bug_review` **4 passed / 0 ignored**、
  `m17_ui_regressions` **21/21**、`m18_t18_regressions` **6/6**；`cargo check -q -p wolf-game`
  0 error，`cargo fmt --all -- --check` 与 `git diff --check` 通过。
* **`m14` 已由 2 红转 5 绿（2026-11-13 续查，§4.1 已重写）**：漂移与本次补丁无关，来自
  T18 `1a9fafe` 的两处渲染改动。其中「停靠侧栏 alpha」是 T18 稳定 `hover` 引入的真实回归，
  已在 `game.rs` 用 `SIDE_PANEL_PARKED_ALPHA` 复原零售 20% 把手；另一处 slot 230 行动力
  文本拆分是审计报告 §一.4 要保留的宿主进度条布局，只重钉文本计数（+1 图/项/行），
  像素基线 533187 / 554890 **一位未改**。

## 2. 代码改动

### 2.1 `Assets::alpha_bounds_in` 记忆化（`crates/wolf-game/src/assets.rs`）

| 位置 | 内容 |
| :--- | :--- |
| `assets.rs:261` | 新字段 `alpha_bounds_cache: HashMap<String, HashMap<([u32; 4], u8), Option<[u32; 4]>>>` |
| `assets.rs:295` | `with_overlays()` 初始化为 `HashMap::new()` |
| `assets.rs:326` | `clear()` 追加 `self.alpha_bounds_cache.clear();`（回标题时与解码缓存同生命周期） |
| `assets.rs:340-361` | 新方法 `alpha_bounds_in(&mut self, name, region, threshold) -> Option<[u32;4]>` |
| `game.rs:248` | `picture_ink_rect_in` 的 `assets.load(...)` + `image.alpha_bounds_in(...)` 合并为 `assets.alpha_bounds_in(&picture.file, source, 16)?` |

契约与要点：

* 区域越界 / 全透明 / 加载失败一律 `None`，与 `ImageData::alpha_bounds_in` 的行为逐条等价
  （阈值在键上先 `min(255)`，与像素扫描口径一致）。
* 两级键（名称 → 「区域, 阈值」）而不是扁平三元组：命中路径只借用 `&str`，不为查表分配 `String`；
  这也是把初版扁平键改掉的原因。
* 区域必须进键：同一张 spritesheet 的不同格子 alpha 轮廓不同，若只按文件缓存会串格。
* UV 映射、`picture.scale < 0` 水平翻转、`destination` 变换全部未动，命中盒语义不变。

收益：`update_side_panel_auto_retract()` 每帧扫一侧栏（330x576 = **190,080 px**），
`picture_state` 的 hover 轮询每帧查 `-7 | -5 | -4 | 1108`；改后由每帧全图 alpha 扫描变为 O(1) 查表，
`picture_action_event_at()` 的点击路径同样受益。

### 2.2 `install_map` 的 `MAP_SELF_BASE` 清扫（`crates/wolf-game/src/game.rs:1556-1573`）

```text
runtime.stop_all(&mut vm)
→ 收集 instances() 中 self_base == MAP_SELF_BASE 的 id 列表
→ 逐个 vm.stop_instance(id)
→ boot_map_active = false
```

* 只匹配 `MAP_SELF_BASE`：公共事件协程共用同一 VM，必须跨地图存活。
* 先收集 id 再停：`stop_instance` 会改动实例切片，边遍历边停会漏项。
* 子协程随祖先级联回收（`Vm::stop_instance` 既定语义），无主页面派生的调用链不会跨图残留。
* 运行期影响面：**首次装载是 no-op**（此前不存在地图协程），只在换图/读档这类「已有旧实例」的
  路径上生效。这也是 §4.1 中 `m14` 两场景数值在打完补丁后一位未变的原因之一。

## 3. 测试与文档口径

### 3.1 `crates/wolf-game/tests/m16_old_bug_review.rs`

| 旧名 | 新名 | 状态 |
| :--- | :--- | :--- |
| `bug20_character_state_...` | `hist_bug20_character_state_...` | 运行（历史台账） |
| `bug21_install_map_retires_...` | `report_s6_bug21_install_map_retires_...` | **取消 `#[ignore]`**（§六 BUG-21 已实现） |
| `old_bug23_flash_and_shake_survive_...` | `hist_bug23_empty_range_effect_is_noop` | **取消 `#[ignore]`**，断言反转为「空范围 `Screen::effect` 返回 `false`」 |
| `old_bug24_key_repeat_...` | `hist_bug24_key_repeat_...` | 运行（历史台账） |

文件头注释重写为两套台账并列：`hist_*` = `HANDOFF_PROGRESS.md` 2026-11-11 台账，
`report_s6_*` = `CODE_REVIEW_4ROUND.md` §六；并注明 §六 的 BUG-20/22/23/24 已有生产测试
（`m3_map_click` / `m3_mouse_menu` / CSelf 套件 / `ProgramSet::id_by_name` 与 Op300 单测），此处不重复。

`hist_bug23` 反转断言的依据：零售脚本总是先 `Draw` 再对同一槽位施加 `effect`，
空范围是手册定义的 no-op；把它钉成 `false` 可防止后续改动把空范围升级成整屏闪烁。

### 3.2 文档口径（6 处，两套编号不再混称）

| 文件 | 改动 |
| :--- | :--- |
| `docs/reviews/README.md` | 编号表拆成「报告 §六基线 BUG-20..24」与「旧台账（2026-11-11）BUG-20..24」两行 |
| `docs/reviews/CODE_REVIEW_4ROUND.md` | §1.1 第 2 条改为「同号不同义的两套基线」；第六章标题加「本报告 §六」，章首加互不套用警示；§5.4 的 `Field 11/12` 由「窗口内坐标 / 移出窗口 −1」修正为**帧间位移 `dx/dy`**；§六 BUG-21 行标注已实现 |
| `docs/HANDOFF_DEEP_REVIEW_FIX.md` | 来源行补注「报告 §六编号，与 2026-11-11 台账同号不同义」 |
| `docs/README.md` | 索引行同步为「报告 §六基线 BUG-20..24（与旧台账同号不同义）」 |
| `docs/HANDOFF_PROGRESS.md` | 2026-11-12 文档整理条目补注同号不同义 |
| `docs/HANDOFF_M0.md` §11.1 | 旧编号条目改为分源表述，并记录 §六 BUG-21 于 2026-11-13 闭环、m16 变为 4/0 |

## 4. 验证记录

| 命令 | 结果 |
| :--- | :--- |
| `cargo check -q -p wolf-game` | 0 error |
| `cargo check -q -p wolf-gdext` | 0 error（选项双 clone 合并后） |
| `cargo fmt --all -- --check`、`git diff --check` | 通过 |
| `WOLF_DATA_ROOT=<abs>/work/Data cargo test -q -p wolf-game --test m16_old_bug_review` | **4 passed / 0 ignored**（2026-11-13 复验，exit 0） |
| 同上 `--test m17_ui_regressions` | 21/21 |
| 同上 `--test m18_t18_regressions` | 6/6（停靠侧栏 alpha 复原后复验） |
| 同上 `-p wolf-cli --test m14_visual_regression` | **5 passed**（像素基线 533187 / 554890 未动，§4.1） |
| `bash tools/smoke-godot.sh`（`GODOT_BIN` 指向主 exe） | exit 0；`load_save: pictures=50 texts=15`、save→load 往返 38/38 |
| `cargo test -q --workspace` | exit 101，只余既有的 `m3_manual_rules::late_night_bedtime_skips_to_next_evening`（04:30 就寝期望次日 19:00，长期台账） |

> 本机执行环境补充：`cargo test --workspace` 会在 `wolf-cli` 单测
> `font_lookup_prefers_the_games_face_and_scans_unexpected_names` 的收尾
> `std::fs::remove_dir_all` 里挂死（E: 盘的 `work/out` 删除返回 os error 145
> 「目录不是空的」后无限重试，纯 CPU 自旋）。已用仓库外的独立 `rustc` 小程序复现，
> 与项目代码无关，PowerShell 手动删除同一目录是瞬时的。上表的 workspace 结果是
> 加 `-- --skip font_lookup_prefers_the_games_face_and_scans_unexpected_names` 得到的；
> 该用例自身逻辑在跳过前的阶段（两次 `font_paths_in`）全部通过。

### 4.1 `m14` 两处失败的归因（A/B 实验）

方法：把 `assets.rs` / `game.rs` 备份到 `work/out/t12_backup`，`git checkout` 回 HEAD 版本，
用同一命令跑 `m14_visual_regression`；跑完从备份恢复（SHA-256 校验一致）。

| 场景 | 基线 `nonblack` | 打补丁后 | 回到 HEAD | 结论 |
| :--- | :--- | :--- | :--- | :--- |
| `day_command` | 533187 | 531398 | **531398** | 两次完全相同 |
| `hud` | 554890 | 552738 | **552738** | 两次完全相同 |

**结论：既有漂移，不是本次补丁引入。** 另有一条运行期理由可交叉解释：补丁的清扫只在
「已存在旧地图协程」的换图/读档路径生效，而这两个场景都是新起进程装载地图，清扫为 no-op。

2026-11-13 续查用独立 worktree 复验：`work/out/ee808fe_tree`（detached `ee808fe`，已删除）
配独立 `--target-dir` 重建的基线二进制，用同一存档 `work/Data/Save/SaveData01.sav` 跑
`--event 245 --frames 240` 与 `--frames 60`，结果 **533187 / 23 text pics / 22 items** 与
**554890 / 14 / 13**，即 fixture、字体与环境都没漂移，差异全部来自 `ee808fe..HEAD` 的源码。

逐项归因（日志探针 + 像素 diff）：

1. **+1 text picture / item / line = slot 230 拆分**。`Game::build_text_picture`
   （`game.rs:2349`）在 T18 新增 `split_action_readout`（`game.rs:190`）：图片号为 230 且文本
   形如 `\f[14]行动力60/65` 时，拆成 label@x=560 与 value@x=668 两个 run，给宿主的进度条
   （`HUD_ACTION_BAR`）留空。字形总数不变，但 run/item/line 各 +1。像素计数不变：同一行字形
   只是挪位，仍压在同一块亮色顶栏上，黑像素数不变。
2. **nonblack −1789 / −2152 = 停靠侧栏 alpha 从 0.20 变 1.00**。旧版每帧由地图 ev8/ev11 调
   CE238/CE239 的 hide 页（探针显示 `owner_event 238/239` 的 `merge_args` 每帧各一次），每次
   重画都把 10 帧淡入重置、`age` 停在 2，于是 `alpha = 255 × 2/10 = 0.2` —— 零售左缘那条淡灰
   滑条/三角把手就是这么来的。T18 为消除每帧重画与 hover 抖动，把 `Game::hover` 改成对
   320/2300 恒返回 1（"Report a stable hover …"），hide 页不再运行；面板保持存档里的
   `opacity 255 / fade 0`，画成 1.00 不透明，左缘变暗、nonblack 下降。像素 diff 的 `lostBox`
   与热点 tile 正好落在 `(640,0)` 行动力区和 x=0 侧栏列。

修复与重钉：

* `game.rs` 新增 `SIDE_PANEL_PARKED_ALPHA = 0.2`、`SIDE_PANEL_PARKED_X = -300`；
  `picture_quads` 对已停靠（`x ≤ -300` 且无进行中的过渡）的 320/2300 乘 0.2，打开/关闭
  滑动仍为 1.0。既保留 T18 的「不每帧重画」，又复原零售观感。
* `m14_visual_regression` 只重钉 day_command / hud 的 `text_pictures`、`text_items`、
  `text_lines`（23→24、22→23、22→23；14→15、13→14、13→14），注释写明 slot 230 拆分；
  **nonblack 533187 / 554890 保持原值**（侧栏修复后 UI 逐像素回到基线）。
* 复验：m14 **5 passed**（day_command 533187 / 24 / 23 / 23，hud 554890 / 15 / 14 / 14）。

> 操作陷阱：两个 worktree 共用同一个 `target` 目录时，cargo 会复用另一棵树的产物。本轮
> 先出现过一次「m14 假 5/5」（旧树产物被当前树复用），`cargo clean -p wolf-game -p wolf-cli`
> 后立刻回到 531398 / 552738。A/B 必须给旧树独立 `--target-dir`；另外在 pwsh 里别用 `$t`
> 存路径——`tools/env.ps1` 的 `$T` 与它同名（大小写不敏感），会把目标目录覆盖成 `tools/`。

## 5. 未完成 / 下一步

* ~~**`m14` 基线重钉**~~ **已收口（2026-11-13）**：见 §4.1。停靠侧栏 alpha 回归已修复，
  只重钉两场景的文本计数，像素基线未动；m14 5/5。
* ~~`wolf-gdext` `lib.rs::frame()` 里 `choice_options` 双 `clone()`~~ **已完成**：改为直接
  借用 `game.choices` 的选项切片（`overlay_at_sized` 传 `game.choice_cursor()`），
  `cargo check -q -p wolf-gdext` exit 0；`tools/build-godot.sh` 重建 dll 后 headless
  `smoke-godot.sh` exit 0（本机 console 包装器报 CreateProcess error 193，需把 `GODOT_BIN`
  指向 `Godot_v4.7.2-stable_win64.exe` 主程序）。
* `Atlas` 内容包围盒仍是左上角矩形，`Atlas::add()` 递增 `revision` 会整盒重传（新游戏 600 帧
  11 次 / 129.6 MiB、`upload_max=11.648 ms`）；若要压低过场尖峰，可先 `prewarm_draw()` 预热常用资源，
  之后再考虑区域更新。
* `install_map` 清扫与 boot 事件的语义边界：本次未给 `BOOT_EVENT` 特例（首次装载本就 no-op），
  若后续出现「显式重装同一张图」的调用方，需要重新确认 boot 页是否应豁免。

## 6. 复现与验收

```powershell
$env:WOLF_DATA_ROOT='E:\Study\github program\Imouto Life\work\Data'
cargo test -q -p wolf-game --test m16_old_bug_review    # 期望 4 passed / 0 ignored
cargo test -q -p wolf-game --test m17_ui_regressions    # 期望 21 passed
cargo test -q -p wolf-game --test m18_t18_regressions   # 期望 6 passed
cargo check -q --workspace
cargo fmt --all -- --check
git diff --check
cargo test -q -p wolf-cli --test m14_visual_regression   # 期望 5 passed
cargo test -q --workspace                               # 期望 exit 0
```

## 7. 本次改动清单

```text
crates/wolf-game/src/assets.rs                 +44
crates/wolf-game/src/game.rs                   +31（T12）+ 停靠侧栏 alpha 复原
crates/wolf-game/tests/m16_old_bug_review.rs    59 行改写
crates/wolf-gdext/src/lib.rs                   choice_options 双 clone 合并
crates/wolf-cli/tests/m14_visual_regression.rs  文本计数重钉 + 溯源注释
docs/HANDOFF_DEEP_REVIEW_FIX.md                +4/-…
docs/HANDOFF_M0.md                             §11.1
docs/HANDOFF_PROGRESS.md                       2026-11-13 条目
docs/README.md                                 索引行
docs/reviews/CODE_REVIEW_4ROUND.md             12 行
docs/reviews/README.md                         5 行
```

## 8. 明确未做

* 未 commit（按约定由 lead 统一提交）。
* 未改 `work/Data`（含 `Save/` 存档）与 `ptr_sc/`；m14 只重钉文本计数，像素基线未动。
* 未动他人未跟踪文件（`crates/wolf-game/tests/zz_probe_nameplate.rs`、两个截图 zip、
  `docs/imouto_life_*.md`）。
* A/B 用的临时备份 `work/out/t12_backup` 在恢复校验后已删除；`work/out/ee808fe_tree`
  与 `work/out/m14_ab/` 是本次复核产物，确认不再需要后可直接删除。
