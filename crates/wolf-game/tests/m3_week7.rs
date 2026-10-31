//! M3-Y 完整一周（7 个游戏日）日常循环贯通测试：《妹！生活 ～単色～》
//!
//! 目标：真实驱动「就寝(CE251) -> 翌朝日菜单 -> 白天行动/休日行动 -> 归宅 -> 就寝」
//! 这条日常循环，连续跑满 7 个游戏日（周一..周日），并在第 8 天验证星期回到周一；
//! 期间在工作日断言 CE256 日菜单、在周末断言 CE259 休日菜单与 09:00 起床，并做至少
//! 两次「跨日存档 -> 全新 Game 读档」的严格一致性校验。
//!
//! 数据根与其它 m* 测试一致：默认 work/Data，可用 WOLF_DATA_ROOT 覆盖；缺失数据时
//! eprintln 跳过并 return，保证整套测试默认仍 exit 0。本文件只做断言，不依赖任何未公开
//! 的 src 内部改动。
//!
//! 已知限制（记录、不修改 src）：本作有少量 CData 字段在配置上是文本列，但运行期脚本
//! 用数值写它们，值只进入引擎 cells 层；Game::save_to 无法把这类数值编码进 vardb（实测
//! 会记 "… could not be encoded"），读档后回落到模板基线值。跨日存档校验把这种"回落
//! 基线"的单元单独列出并给出数量，其余数据库单元要求严格一致。
//!
//! 变量语义（本作实测确认，见 docs/HANDOFF_M0.md）：v4=時、v5=分、v6=曜日(0=周一)、
//! v7=所持金、v14=妹位置、v20=妹信頼度、v99=同居天数(HUD「同居 N 天」)。本作没有把
//! 日计数放在 v160（v160 恒 0，是お風呂タイマー2），日计数一律看 v99。

use std::path::PathBuf;

use wolf_game::db::Container;
use wolf_game::game::Game;
use wolf_game::savegame;

const WORKDAY_MENU: [&str; 5] = [
    "无所事事地度过 ",
    "在附近散步 ",
    "做家务 ",
    "偷内裤 ",
    "睡觉 ",
];
const HOLIDAY_MENU: [&str; 5] = [
    "和妹妹一起玩 ",
    "做运动 ",
    "把积攒的家务做完 ",
    "努力打工 ",
    "睡觉 ",
];

/// 数据根：默认 work/Data，可被 WOLF_DATA_ROOT 覆盖（相对路径按 crate 往上两级解析）。
fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let path = PathBuf::from(raw);
    if path.is_absolute() {
        return path;
    }
    let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    base.pop();
    base.pop();
    base.join(path)
}

fn open_game() -> Option<Game> {
    match Game::new(data_root()) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!("skipping: {err}");
            None
        }
    }
}

/// 打开一个"基线已归一"的 Game：全新 Game 的运行期变量数据库可能缺少模板
/// (Save/System.sav) vardb 里的个别单元（num 读到默认 0，而模板里是别的值），
/// 直接 save_to 会把模板值写回去造成一次读档的假差异。先对空态做一次
/// save_to -> load_save 自洽化，让数据库与模板 vardb 对齐，再做后续跨日校验。
fn normalized_game() -> Option<Game> {
    let mut game = open_game()?;
    let out_dir = data_root().parent()?.join("out");
    std::fs::create_dir_all(&out_dir).ok()?;
    let tmp = out_dir.join(format!(
        "m3_week7_normalize-{}-{}.sav",
        std::process::id(),
        scratch_seq()
    ));
    game.save_to(&tmp).ok()?;
    game.load_save(&tmp).ok()?;
    let _ = std::fs::remove_file(&tmp);
    Some(game)
}

/// Unique suffix for scratch save files: tests in one binary run on parallel threads,
/// and concurrent verification runs share work/out. A process id alone is not enough
/// (two tests of this binary can overlap), so an atomic counter joins it.
fn scratch_seq() -> u64 {
    use std::sync::atomic::{AtomicU64, Ordering};
    static NEXT: AtomicU64 = AtomicU64::new(0);
    NEXT.fetch_add(1, Ordering::Relaxed)
}

/// 读变量（未被写的槽位按 0 处理）。
fn var(game: &Game, index: usize) -> i32 {
    game.vm.vars.get(index)
}

/// 当前存活的脚本事件编号（去重、排序）。
fn live_events(game: &Game) -> Vec<u32> {
    let mut events: Vec<u32> = game.vm.instances().iter().map(|inst| inst.event).collect();
    events.sort_unstable();
    events.dedup();
    events
}

/// 点一下 OK（handle_choice_input 只认新按下的键，所以先置位再清零）。
fn press_ok(game: &mut Game) {
    game.key_bits = wolf_game::key::OK;
    game.frame();
    game.key_bits = 0;
}

/// 在当前菜单里选择包含 needle 的选项，返回被选中的完整文本。
fn choose(game: &mut Game, needle: &str) -> String {
    let options = game.choices.as_ref().expect("choices open").options.clone();
    let index = options
        .iter()
        .position(|option| option.contains(needle))
        .unwrap_or_else(|| panic!("no option containing {needle:?} in {options:?}"));
    let chosen = options[index].clone();
    game.set_choice_cursor(index);
    press_ok(game);
    chosen
}

fn menu_options(game: &Game) -> Vec<String> {
    game.choices
        .as_ref()
        .expect("a menu is open")
        .options
        .clone()
}

fn has_option(options: &[String], needle: &str) -> bool {
    options.iter().any(|option| option.contains(needle))
}

/// 跑若干帧，等到一个新菜单弹出为止（auto_advance 会消费消息，靠逐帧推进时序）。
fn wait_for_menu(game: &mut Game, frames: usize) {
    for _ in 0..frames {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }
}

/// 工作日白天：从 08:30 日菜单反复「无所事事地度过」+「是」，16:00 出现归宅菜单后
/// 选「一个人去」，把一天推进到 19:30 家里。返回途中见过的菜单集合。
fn advance_workday(game: &mut Game) -> Vec<Vec<String>> {
    let mut menus: Vec<Vec<String>> = Vec::new();
    for _ in 0..40 {
        if game.choices.is_none() {
            for _ in 0..400 {
                game.frame();
                if game.choices.is_some() {
                    break;
                }
                let events = live_events(game);
                if game.choices.is_none()
                    && var(game, 4) >= 18
                    && !events
                        .iter()
                        .any(|&e| e == 241 || e == 251 || e == 255 || e == 256)
                {
                    break;
                }
            }
        }
        if game.choices.is_none() {
            break;
        }
        let options = menu_options(game);
        if !menus.iter().any(|menu| menu == &options) {
            menus.push(options.clone());
        }
        if has_option(&options, "一个人去") {
            choose(game, "一个人去");
        } else if has_option(&options, "是") && has_option(&options, "否") {
            choose(game, "是");
        } else if has_option(&options, "无所事事") {
            choose(game, "无所事事");
        } else {
            game.set_choice_cursor(0);
            press_ok(game);
        }
    }
    menus
}

/// 休日白天：CE259 菜单里反复「睡觉」午睡推进时间（09:00 -> 12:30 -> 14:30 -> 16:30），
/// 到 16:30 会出现休日归宅菜单（一个人去/一起去/不想去），选「一个人去」把一天推进到
/// 19:00。返回途中见过的菜单集合。
fn advance_holiday(game: &mut Game) -> Vec<Vec<String>> {
    let mut menus: Vec<Vec<String>> = Vec::new();
    let mut naps = 0;
    for _ in 0..20 {
        let options = match game.choices.as_ref() {
            Some(_) => menu_options(game),
            None => panic!("休日白天菜单意外关闭（{naps} 次午睡后）"),
        };
        if !menus.iter().any(|menu| menu == &options) {
            menus.push(options.clone());
        }
        if has_option(&options, "一个人去") {
            choose(game, "一个人去");
            // 归宅后当天结束：跑少量帧让脚本收尾（此段已无菜单）。
            for _ in 0..300 {
                game.frame();
                if game.choices.is_some() {
                    break;
                }
            }
            return menus;
        }
        assert!(
            has_option(&options, "和妹妹一起玩"),
            "休日白天出现未知菜单: {options:?}"
        );
        choose(game, "睡觉");
        wait_for_menu(game, 2500);
        naps += 1;
        assert!(naps < 15, "午睡次数过多，休日循环可能没有推进时间");
    }
    panic!("休日白天始终没有出现归宅菜单");
}

/// 从当前早晨把一天推进到夜里（自动区分工作日/周末），随后就寝并等到翌朝日菜单。
fn advance_one_day(game: &mut Game) {
    let week = var(game, 6);
    if week < 5 {
        let menus = advance_workday(game);
        assert!(
            menus.iter().any(|menu| has_option(menu, "一个人去")),
            "工作日白天应出现归宅菜单, menus={menus:?}"
        );
        assert_eq!(
            (var(game, 4), var(game, 5)),
            (19, 30),
            "工作日（v6={week}）白天应推进到 19:30"
        );
    } else {
        let menus = advance_holiday(game);
        assert!(
            menus.iter().any(|menu| has_option(menu, "一个人去")),
            "休日白天应出现归宅菜单, menus={menus:?}"
        );
        assert_eq!(
            (var(game, 4), var(game, 5)),
            (19, 0),
            "休日（v6={week}）白天应推进到 19:00"
        );
    }
    assert!(game.choices.is_none(), "一天结束时不应还有待选菜单");
    assert!(game.start_event(251), "应能启动就寝事件 CE251");
    wait_for_menu(game, 2500);
    assert_eq!(game.stats.warnings, 0, "推进一天后不应产生 warning");
}

// ---------------------------------------------------------------------------
// 存档快照：复刻 m3_save_load.rs 的几何比对口径（文本图的文本被 legacy 编码破坏，
// 只比几何；非文本图逐字段比）。
// ---------------------------------------------------------------------------
/// 画面几何口径：只比画什么(资源文件)和放在哪、多大、透明度/缩放/锚点/拆分数；
/// 不比 kind 和 window。理由（记录、非失败）：save 的 part5 重建会把运行期
/// WindowFile 记成 WindowString，文本图的 window 也会回成 Some((1,1))，但几何完全一致。
#[derive(Debug, PartialEq, Eq)]
struct Geom {
    number: i32,
    file: String,
    x: i32,
    y: i32,
    opacity: i32,
    scale: i32,
    anchor: u8,
    split: (u32, u32),
    pattern_index: u32,
}

fn geometry(game: &Game) -> Vec<Geom> {
    game.screen
        .iter()
        .map(|p| Geom {
            number: p.number,
            file: p.file.clone(),
            x: p.x,
            y: p.y,
            opacity: p.opacity,
            scale: p.scale,
            anchor: p.anchor,
            split: p.split,
            pattern_index: p.pattern_index,
        })
        .collect()
}

fn text_picture_count(game: &Game) -> usize {
    game.screen.iter().filter(|p| p.kind.is_text()).count()
}

fn db_snapshot(game: &Game) -> Vec<Option<i32>> {
    let mut out = Vec::new();
    for container in [Container::CData, Container::Sys, Container::Data] {
        for db_type in 0..40 {
            for row in 0..60 {
                for column in 0..8 {
                    out.push(game.databases.num(container, db_type, row, column));
                }
            }
        }
    }
    out
}

fn stored_normal_var_count(path: &std::path::Path) -> usize {
    savegame::read_save(path)
        .ok()
        .and_then(|save| save.part3.row_counts.first().copied())
        .map(|count| count as usize)
        .unwrap_or(0)
}

/// 一次「跨日存档 -> 全新 Game 读档」严格校验：变量、日计数/星期/时钟/金钱、
/// 变量数据库、画面几何、warnings 全部一致，且 vars[stored..337] 必须回落到 0。
fn roundtrip_check(game: &mut Game, out: &std::path::Path, label: &str) {
    let stored = stored_normal_var_count(&data_root().join("Save").join("System.sav"));
    let span = if stored == 0 { 302 } else { stored };
    assert_eq!(span, 302, "{label}: 模板存档 row0 应存 302 个普通变量");

    let vars_before: Vec<i32> = (0..span).map(|index| var(game, index)).collect();
    let day_before = var(game, 99);
    let week_before = var(game, 6);
    let clock_before = (var(game, 4), var(game, 5));
    let money_before = var(game, 7);
    // 模板基线：全新 Game 的数据库视图。个别 CData 字段在配置上是文本列，
    // 运行时被数值写入只进 engine cell 层、save_to 无法编码（见文件顶部说明），
    // 读档会回落到模板值——这类"回落到基线"的单元单独列出、不作为失败。
    let template_db = db_snapshot(&open_game().expect("template game for db baseline"));
    let db_before = db_snapshot(game);
    let pics_before = geometry(game);
    let text_pics_before = text_picture_count(game);
    let playtime_before = game.playtime_frames;
    assert_eq!(game.stats.warnings, 0, "{label}: 写档前不应有 warning");

    let written = game.save_to(out).expect("save_to");
    assert!(written > 0, "{label}: save_to 应写出非空文件");
    assert!(out.is_file(), "{label}: 存档文件应存在 {}", out.display());

    let mut reloaded = open_game().expect("重新打开全新 Game 用于读档");
    reloaded.load_save(out).expect("load_save 应成功读回");
    let _ = std::fs::remove_file(out);

    let vars_after: Vec<i32> = (0..span).map(|index| var(&reloaded, index)).collect();
    assert_eq!(
        vars_after, vars_before,
        "{label}: 普通变量 0..{span} 必须逐项一致"
    );
    for index in span..337 {
        assert_eq!(
            var(&reloaded, index),
            0,
            "{label}: vars[{index}] 读档后必须回落为 0（不能被后续 row 污染）"
        );
    }

    assert_eq!(var(&reloaded, 99), day_before, "{label}: 日计数 v99 一致");
    assert_eq!(var(&reloaded, 6), week_before, "{label}: 星期 v6 一致");
    assert_eq!(
        (var(&reloaded, 4), var(&reloaded, 5)),
        clock_before,
        "{label}: 时钟 v4/v5 一致"
    );
    assert_eq!(var(&reloaded, 7), money_before, "{label}: 所持金 v7 一致");

    let db_after = db_snapshot(&reloaded);
    let mut reverted = 0usize;
    let mut reverted_examples: Vec<(usize, Option<i32>, Option<i32>)> = Vec::new();
    let mut unexplained: Vec<(usize, Option<i32>, Option<i32>)> = Vec::new();
    for (index, (before, after)) in db_before.iter().zip(db_after.iter()).enumerate() {
        if before == after {
            continue;
        }
        // 允许"回落模板基线"的已知不可编码单元（运行期数值写进文本配置列）。
        if template_db.get(index) == Some(after) {
            reverted += 1;
            if reverted_examples.len() < 8 {
                reverted_examples.push((index, *before, *after));
            }
        } else {
            unexplained.push((index, *before, *after));
        }
    }
    eprintln!(
        "{label}: 数据库读档差异——不可编码回落 {reverted} 个（例 {:?}），其它 {unexplained_count} 个",
        reverted_examples,
        unexplained_count = unexplained.len()
    );
    assert!(
        unexplained.is_empty(),
        "{label}: {} 个数据库单元在读档后出现无法解释的变化，前几个 {:?}",
        unexplained.len(),
        &unexplained[..unexplained.len().min(20)]
    );
    assert!(
        reverted <= 8,
        "{label}: 回落模板基线的数据库单元过多（{reverted} 个），超过本作已知的少量不可编码字段"
    );

    assert_eq!(
        geometry(&reloaded),
        pics_before,
        "{label}: 画面几何逐图一致"
    );
    assert_eq!(
        text_picture_count(&reloaded),
        text_pics_before,
        "{label}: 文本图数量一致"
    );
    assert_eq!(
        reloaded.playtime_frames, playtime_before,
        "{label}: 游戏时长一致"
    );
    assert_eq!(reloaded.stats.warnings, 0, "{label}: 读档后不应有 warning");
}

// ---------------------------------------------------------------------------
// 1) 连续 7 个游戏日：周一..周日（v6=0..6），每天翌朝 v99×周几 递增、v14 重置 4，
//    工作日 CE256 / 周末 CE259 菜单各自正确；第 8 天星期回到周一（v6 6->0）。
// ---------------------------------------------------------------------------
#[test]
fn seven_day_week_loop_advances_and_wraps() {
    let Some(mut game) = open_game() else {
        return;
    };
    game.auto_advance = true;
    game.auto_choice = false;

    assert!(game.start_event(251), "应能启动就寝事件 CE251");
    wait_for_menu(&mut game, 2500);

    // 逐日断言 + 推进，跑满 7 个游戏日。
    for day in 1..=7i32 {
        assert_eq!(var(&game, 99), day, "第 {day} 天应满足 v99={day}");
        let week = var(&game, 6);
        assert_eq!(week, day - 1, "第 {day} 天星期应为 {}", day - 1);
        assert_eq!(var(&game, 14), 4, "第 {day} 天早晨妹位置应重置为 4");

        let options = menu_options(&game);
        if week < 5 {
            assert_eq!(
                (var(&game, 4), var(&game, 5)),
                (8, 30),
                "工作日第 {day} 天应 08:30 起床"
            );
            assert_eq!(
                options,
                WORKDAY_MENU
                    .iter()
                    .map(|s| s.to_string())
                    .collect::<Vec<_>>(),
                "工作日第 {day} 天应弹出 CE256 日菜单"
            );
        } else {
            assert_eq!(
                (var(&game, 4), var(&game, 5)),
                (9, 0),
                "休日第 {day} 天应 09:00 起床"
            );
            assert_eq!(
                options,
                HOLIDAY_MENU
                    .iter()
                    .map(|s| s.to_string())
                    .collect::<Vec<_>>(),
                "休日第 {day} 天应弹出 CE259 休日菜单"
            );
        }
        assert_eq!(game.stats.warnings, 0, "第 {day} 天不应产生 warning");

        // 推进到次日早晨（第 7 天推进后得到第 8 天，用来验证星期回卷）。
        advance_one_day(&mut game);
    }

    // 第 8 天：周一（v6 6 -> 0），工作日起床 08:30、CE256 日菜单。
    assert_eq!(var(&game, 99), 8, "第 8 天应为同居第 8 天");
    assert_eq!(var(&game, 6), 0, "第 8 天星期应回卷到周一 (v6=0)");
    assert_eq!(
        (var(&game, 4), var(&game, 5)),
        (8, 30),
        "第 8 天应 08:30 起床"
    );
    assert_eq!(var(&game, 14), 4, "第 8 天早晨妹位置应为 4");
    assert_eq!(
        menu_options(&game),
        WORKDAY_MENU
            .iter()
            .map(|s| s.to_string())
            .collect::<Vec<_>>(),
        "第 8 天应回到工作日 CE256 日菜单"
    );
    assert_eq!(game.stats.warnings, 0, "整周不应产生 warning");

    // 结局 / 天数阈值：一周内（v99=8）远未达到 100 日与通关阈值，如实记录不伪造。
    assert_eq!(var(&game, 201), 0, "一周内不应触发 100 日到达 (v201)");
    assert_eq!(var(&game, 199), 0, "一周内不应触发通关 (v199)");
    eprintln!(
        "note: 一周循环结束时 v99={} (100 日阈值 v201={}, 通关 v199={})——结局/长周期阈值在本测试内不可达，如实跳过",
        var(&game, 99),
        var(&game, 201),
        var(&game, 199)
    );
}

// ---------------------------------------------------------------------------
// 2) 跨日存档往返：在第 3 天（工作日）与第 6 天（周六休日）各做一次
//    save_to -> 全新 Game load_save 的严格一致性校验，并清理临时存档。
// ---------------------------------------------------------------------------
#[test]
fn cross_day_save_roundtrip_preserves_state() {
    let Some(mut game) = normalized_game() else {
        return;
    };
    game.auto_advance = true;
    game.auto_choice = false;

    let out_dir = data_root()
        .parent()
        .expect("data root has a parent")
        .join("out");
    std::fs::create_dir_all(&out_dir).expect("create work/out");
    let out = out_dir.join(format!(
        "m3_week7_roundtrip-{}-{}.sav",
        std::process::id(),
        scratch_seq()
    ));
    let _ = std::fs::remove_file(&out);

    assert!(game.start_event(251), "应能启动就寝事件 CE251");
    wait_for_menu(&mut game, 2500);

    let mut checked = 0;
    // game 现处于第 1 天早晨；推进到第 3 天与第 6 天早晨各校验一次。
    for day in 1..=6i32 {
        assert_eq!(var(&game, 99), day, "存档测试应处于第 {day} 天");
        if day == 3 {
            roundtrip_check(&mut game, &out, "第3天(工作日)存档往返");
            checked += 1;
        }
        if day == 6 {
            roundtrip_check(&mut game, &out, "第6天(周六休日)存档往返");
            checked += 1;
            break;
        }
        advance_one_day(&mut game);
    }
    assert_eq!(checked, 2, "应完成两次跨日存档往返校验");
    assert!(!out.exists(), "临时存档应已清理");
}
