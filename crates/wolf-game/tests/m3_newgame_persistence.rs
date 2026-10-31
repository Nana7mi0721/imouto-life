//! M3-S 新游戏跨日存档/读档一致性回归（task-25）。
//!
//! 两段覆盖：
//! 1) 从标题菜单新游戏（cursor 0 + auto_choice）真实 boot 到 SampleMapA，记录初始
//!    日计数 v99、星期 v6、时钟 v4/v5、金钱 v7、妹位置 v14、屏幕几何与 DB 快照。
//! 2) 用「干净事件态」的 Game::new 驱动日循环（docs/M2_SLICE.md §4：CE251 就寝必须用
//!    干净 Game::new 状态；新游戏/读档的 19:30 直接 start_event(251) 只吐「…………」并
//!    停在 00:00）。每天推进到 19:30 后跑 CE251 就寝到次日 08:30；连续 3 日。
//!    CE245 夜菜单仅在 boot 的真实地图事件态可打开，由 test1 断言六项含「今天就这样
//!    睡吧」后取消验证。每日早上把当前状态
//!    save_to(work/out 临时槽) -> 全新 Game（同 root）load_save，断言 v99/v6/时钟
//!    v4/v5/v14/金钱/vars0..302/DB cell 快照/screen 图片几何/playtime 与保存时刻一致，
//!    且 vars302..336 仍全 0（防 SavePart3 row-span 回归）。
//!    两处已知引擎序列化限制按 m3_save_load 同样思路做窄豁免并注释：
//!    - screen：Text 图的 window 字段与 WindowString→WindowFile 的 kind 标签在
//!      save_to->load 后不保留，比较时归一化；其余几何字段严格。
//!    - DB：CData type 6 row 0 col 1 因 base_save 模板 vardb 列布局不一致（write_into
//!      missed），重载回落到静态 12；只豁免该坐标并断言稳定为 source=0/loaded=12。
//!
//! 数据缺失时 eprintln 跳过并 return（默认 exit 0）；临时存档只写 work/out/，测试结束删除。

use std::path::PathBuf;

use wolf_game::db::Container;
use wolf_game::key;
use wolf_game::savegame;
use wolf_game::Game;

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

fn out_dir() -> PathBuf {
    data_root()
        .parent()
        .expect("data root has a parent")
        .join("out")
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

fn var(game: &Game, index: usize) -> i32 {
    game.vm.vars.get(index)
}

fn live_events(game: &Game) -> Vec<u32> {
    let mut events: Vec<u32> = game.vm.instances().iter().map(|inst| inst.event).collect();
    events.sort_unstable();
    events.dedup();
    events
}

fn press(game: &mut Game, key_bit: u32) {
    game.key_bits = key_bit;
    game.frame();
    game.key_bits = 0;
}

fn press_ok(game: &mut Game) {
    press(game, key::OK);
}

fn choose(game: &mut Game, needle: &str) -> String {
    let options = game
        .choices
        .as_ref()
        .expect("choices open")
        .options
        .clone();
    let index = options
        .iter()
        .position(|option| option.contains(needle))
        .unwrap_or_else(|| panic!("no option containing {needle:?} in {options:?}"));
    let chosen = options[index].clone();
    game.set_choice_cursor(index);
    press_ok(game);
    chosen
}

fn drive_daytime(game: &mut Game) -> Vec<Vec<String>> {
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
                    && !events.iter().any(|&e| e == 241 || e == 251 || e == 255 || e == 256)
                {
                    break;
                }
            }
        }
        if game.choices.is_none() {
            break;
        }
        let options = game.choices.as_ref().unwrap().options.clone();
        if !menus.iter().any(|menu| menu == &options) {
            menus.push(options.clone());
        }
        if options.iter().any(|option| option.contains("一个人去")) {
            choose(game, "一个人去");
        } else if options.iter().any(|option| option.contains("是"))
            && options.iter().any(|option| option.contains("否"))
        {
            choose(game, "是");
        } else if options.iter().any(|option| option.contains("无所事事")) {
            choose(game, "无所事事");
        } else {
            game.set_choice_cursor(0);
            press_ok(game);
        }
    }
    menus
}

fn morning_wait(game: &mut Game) {
    for _ in 0..1500 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }
}

/// 打开 CE245 夜菜单，断言六项含就寝项，然后用 CANCEL 关闭，回到无菜单的事件态。
fn open_and_cancel_night_menu(game: &mut Game) {
    assert!(game.start_event(245), "CE245 夜菜单应能打开");
    for _ in 0..200 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }
    let options = game
        .choices
        .as_ref()
        .expect("CE245 夜菜单应弹出")
        .options
        .clone();
    assert!(
        options.iter().any(|option| option.contains("今天就这样睡吧")),
        "夜菜单应含就寝项, got {options:?}"
    );
    press(game, key::CANCEL);
    for _ in 0..120 {
        game.frame();
        if !live_events(game).contains(&245) && game.choices.is_none() {
            break;
        }
    }
    assert!(!live_events(game).contains(&245), "CANCEL 后 CE245 应结束");
}

/// 就寝推进到次日 08:30 日菜单。
fn sleep_to_morning(game: &mut Game) {
    assert!(game.start_event(251), "CE251 就寝应能启动");
    morning_wait(game);
    assert!(game.choices.is_some(), "翌朝应回到日菜单");
}

#[derive(Debug, PartialEq, Eq)]
struct Pic {
    number: i32,
    kind: String,
    file: String,
    x: i32,
    y: i32,
    opacity: i32,
    scale: i32,
    anchor: u8,
    split: (u32, u32),
    pattern_index: u32,
    window: Option<(i32, i32)>,
}

/// Screen 图片几何快照。text 图的 .text 因为 legacy md1 编解码不是严格互逆，不参与比较
/// （见 m3_save_load.rs 的说明）；其余几何字段全部严格比较。
fn screen_snapshot(game: &Game) -> Vec<Pic> {
    // 归一化两处 legacy 序列化差异（引擎 save_to->load_save 不保留，非本测试目标）：
    // 1) 窗口型文字图 WindowString 重建为 WindowFile（同一张 png、同一 window）；
    // 2) Text 图的 window 字段不写入 SavePart5，重建后为 None。
    // 其余几何字段（位置/文件/缩放/锚点/切分/pattern）严格比较。
    game.screen
        .iter()
        .map(|p| {
            let raw_kind = format!("{:?}", p.kind);
            let is_text = raw_kind == "Text";
            let kind = if raw_kind == "WindowString" {
                "WindowFile".to_owned()
            } else {
                raw_kind
            };
            let window = if is_text { None } else { p.window };
            Pic {
                number: p.number,
                kind,
                file: p.file.clone(),
                x: p.x,
                y: p.y,
                opacity: p.opacity,
                scale: p.scale,
                anchor: p.anchor,
                split: p.split,
                pattern_index: p.pattern_index,
                window,
            }
        })
        .collect()
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

/// 把 source 当前状态写到 path，再用全新 Game（同 root）load_save，逐项断言一致。
fn save_and_verify(source: &mut Game, path: &std::path::Path) {
    // 直接复用 Game::save_to 的序列化路径（它会更新 source.base_save，但不改内存状态）。
    source.save_to(path).expect("save_to");
    let stored = savegame::read_save(path).expect("read back the written save");
    let stored_vars = stored.part3.row_counts.first().copied().unwrap_or(0) as usize;
    assert_eq!(stored_vars, 302, "正常变量块仍应为 302 个 (row 0)");

    let mut loaded = open_game().expect("fresh load game");
    loaded.load_save(path).expect("load_save");

    for index in 0..302 {
        assert_eq!(
            loaded.vm.vars.get(index),
            source.vm.vars.get(index),
            "vars[{index}] 应跨存档一致"
        );
    }
    for index in 302..337 {
        assert_eq!(source.vm.vars.get(index), 0, "source vars[{index}] 应为 0");
        assert_eq!(loaded.vm.vars.get(index), 0, "loaded vars[{index}] 应为 0 (row-span 回归)");
    }
    for index in [4usize, 5, 6, 7, 14, 20, 99] {
        assert_eq!(
            loaded.vm.vars.get(index),
            source.vm.vars.get(index),
            "vars[{index}] 应跨存档一致"
        );
    }
    assert_eq!(loaded.playtime_frames, source.playtime_frames, "playtime 应与保存时刻一致");
    assert_eq!(screen_snapshot(&loaded), screen_snapshot(&source), "screen 图片几何应一致");
    let loaded_db = db_snapshot(&loaded);
    let source_db = db_snapshot(&source);
    // 已知引擎限制（已报 Lead）：Game::new 的 base_save 模板 vardb 与静态 CData 的
    // type 6 列布局不一致，save_to 的 write_into 对该 cell 的 set_num 失败（missed），
    // 因而该 cell 不被持久化；重新载入后回落到静态 .dat 的 12。此处只豁免这一个
    // 坐标，并断言它确实呈现 source=0 / loaded=12；其余 5 万多个 cell 仍严格比较。
    let known_drift = (0usize, 6usize, 0usize, 1usize); // (container, type, row, col)
    let mut unexpected: Vec<usize> = Vec::new();
    for i in 0..source_db.len() {
        if loaded_db[i] == source_db[i] {
            continue;
        }
        let col = i % 8;
        let row = (i / 8) % 60;
        let ty = (i / 8 / 60) % 40;
        let container = i / 8 / 60 / 40;
        if (container, ty, row, col) == known_drift {
            assert_eq!(
                (source_db[i], loaded_db[i]),
                (Some(0), Some(12)),
                "已知漂移 cell 的取值应稳定为 source=0/loaded=12"
            );
        } else {
            unexpected.push(i);
        }
    }
    assert!(
        unexpected.is_empty(),
        "DB cell 快照出现非预期差异: {} 个, 首个 idx={}",
        unexpected.len(),
        unexpected.first().copied().unwrap_or(0)
    );
    assert_eq!(loaded.stats.warnings, 0, "读档不应产生 warning");
}

#[test]
fn title_new_game_reaches_sample_map_a_and_records_initial_state() {
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.set_choice_cursor(0);
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.boot().expect("title map autorun");

    for _ in 0..3200 {
        game.frame();
    }

    let diagnostics: Vec<&str> = game.diagnostics.keys().map(String::as_str).collect();
    assert!(
        diagnostics
            .iter()
            .any(|line| line.contains("130 Teleport: MapData/SampleMapA.mps")),
        "新游戏应经 Map003 hook 进入 SampleMapA: {diagnostics:?}"
    );
    assert!(game.screen.len() > 30, "SampleMapA 房间+HUD 应绘制, got {}", game.screen.len());
    assert_eq!(game.stats.warnings, 0, "新游戏路径应无 warning");

    // 初始节奏（与 m3_map_events / m6 实测一致）：第 1 天 周一 19:30。
    // 初始金钱与妹妹位置（v14）都含随机抽样（事件脚本用 121 的 0x6000），零售 PRNG
    // 移植后具体数值会变（旧 xorshift 采样是 15466 / 2），因此只约束合理区间。
    assert_eq!(var(&game, 99), 1, "初始同居天数 v99=1");
    assert_eq!(var(&game, 6), 0, "初始星期 v6=0 (周一)");
    assert_eq!((var(&game, 4), var(&game, 5)), (19, 30), "初始时钟应为 19:30");
    let money = var(&game, 7);
    assert!(
        (10_001..=20_000).contains(&money),
        "初始金钱应在 10000 + 随机零花钱的合理区间, got {money}"
    );
    let sister_position = var(&game, 14);
    assert!(
        (0..=3).contains(&sister_position),
        "初始妹位置 v14 由脚本随机抽取 (0..=3), got {sister_position}"
    );
    assert_eq!(var(&game, 160), 0, "日计数器 v160 初始为 0");
    for index in 302..337 {
        assert_eq!(var(&game, index), 0, "新游戏初始 vars[{index}] 应为 0");
    }
    // 记录初始 DB/屏幕规模，防止后续跨日出现静默缩水。
    assert!(!db_snapshot(&game).is_empty());
    assert!(!screen_snapshot(&game).is_empty());

    // 新游戏 boot 到 19:30 的实机状态里，CE245 夜菜单可正常打开（六项含就寝项），
    // 取消后状态不变。这也是本任务里唯一能在「真实地图事件态」验证 CE245 的位置。
    game.auto_choice = false;
    open_and_cancel_night_menu(&mut game);
    assert_eq!(var(&game, 99), 1, "取消夜菜单后同居天数不变");
    assert_eq!((var(&game, 4), var(&game, 5)), (19, 30), "取消夜菜单后时钟仍为 19:30");
}

#[test]
fn three_days_round_trip_through_save_slots() {
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.auto_choice = false;
    // 干净 Game::new 事件态初始化第 1 天 08:30 日菜单。
    assert!(game.start_event(251), "干净态 CE251 应初始化第 1 天");
    morning_wait(&mut game);
    assert_eq!((var(&game, 99), var(&game, 6)), (1, 0), "起始应为第 1 天周一");
    assert_eq!((var(&game, 4), var(&game, 5)), (8, 30), "起始应为 08:30");
    assert_eq!(game.stats.warnings, 0);

    let dir = out_dir();
    std::fs::create_dir_all(&dir).expect("create work/out");

    for day in 0..3 {
        let before_day = var(&game, 99);
        let before_week = var(&game, 6);
        assert_eq!(before_day, day + 1, "第 {day} 轮起始日应为 {}", day + 1);
        assert_eq!(before_week, day, "第 {day} 轮起始星期应为 {day}");
        assert_eq!(var(&game, 14), 4, "翌朝妹位置应重置为 4");

        // 当日早上存档 -> 全新 Game load -> 全状态一致。
        let path = dir.join(format!("m3_newgame_day{}.sav", day + 1));
        save_and_verify(&mut game, &path);
        let _ = std::fs::remove_file(&path);

        if day == 2 {
            break;
        }

        // 白天推进到 19:30。
        let menus = drive_daytime(&mut game);
        assert!(
            menus.iter().any(|menu| menu.iter().any(|option| option.contains("一个人去"))),
            "第 {day} 天白天应出现归宅菜单, menus={menus:?}"
        );
        assert_eq!((var(&game, 4), var(&game, 5)), (19, 30), "第 {day} 天应推进到 19:30");
        assert!(game.choices.is_none(), "19:30 应无待选菜单");

        // 纯事件态的日循环按 docs/M2_SLICE.md 走 CE251 就寝推进到次日 08:30；
        // CE245 夜菜单只能在 boot 的真实地图事件态打开（test1 已验证），此处不重复。
        sleep_to_morning(&mut game);

        assert_eq!(var(&game, 99), before_day + 1, "第 {day} 天后同居天数应 +1");
        assert_eq!(var(&game, 6), before_week + 1, "第 {day} 天后星期应 +1");
        assert_eq!((var(&game, 4), var(&game, 5)), (8, 30), "第 {day} 天翌朝应为 08:30");
        assert_eq!(var(&game, 14), 4, "翌朝妹位置应重置为 4");
        assert!(
            game.choices
                .as_ref()
                .map(|choices| choices.options.iter().any(|option| option.contains("无所事事")))
                .unwrap_or(false),
            "翌朝应回到日菜单, got {:?}",
            game.choices.as_ref().map(|c| c.options.clone())
        );
        assert_eq!(game.stats.warnings, 0, "第 {day} 天不应产生 warning");
    }

    assert_eq!((var(&game, 99), var(&game, 6)), (3, 2), "连续 3 日后应为第 3 天周三");
}
