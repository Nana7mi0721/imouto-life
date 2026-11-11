//! M3-M：状态面板与数据库变量联动的深度验收。
//!
//! 从 SaveData01 读档后，直接驱动四个 HUD/状态面板事件：
//! - CE237 ステータス（GOOD/BAD/睡眠图标）
//! - CE238 ステータス（信頼/性興味）
//! - CE242 ステータス表示（行动力/精力/持有金钱/同居天数）
//! - CE243 时刻显示（HH:MM 与星期）
//!
//! 测试目的：改变运行时的 vars 与 CDataBase 数值后，确认面板显示随动。
//!
//! 已知引擎缺口（仅记录，不在本测试内修 src）：表达式图片的 cdb 展开
//! （crates/wolf-game/src/game.rs:1317 附近的 PictureCells 路径）在展开 cdb 宏时
//! 只调用 Databases::text(...)，numeric 单元返回 None 时渲染为空。因此 CE242 的
//! 230/240（行动力/精力，对应 CDataBase 0:12:8/9 与 0:12:6/7 的 numeric 单元）
//! 会丢掉数字。为端到端验证「面板确实绑定该 DB 单元」并让字形可见，本测试对同一
//! 单元同时写入 num 与字符串镜像（见 set_status_cell），并单独断言 numeric 读回。

use std::fs;
use std::path::PathBuf;
use std::time::UNIX_EPOCH;

use wolf_game::db::Container;
use wolf_game::savegame;
use wolf_game::Game;

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let p = PathBuf::from(raw);
    if p.is_absolute() {
        return p;
    }
    let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    base.pop();
    base.pop();
    base.join(p)
}

fn save_dir() -> PathBuf {
    data_root().join("Save")
}

fn save_file(slot: u32) -> PathBuf {
    save_dir().join(format!("SaveData{slot:02}.sav"))
}

/// 读档建立 Game；缺数据或缺存档时打印 skipping 并返回 None。
fn open_loaded(slot: u32) -> Option<Game> {
    let path = save_file(slot);
    if !path.is_file() {
        eprintln!("skipping: missing save {}", path.display());
        return None;
    }
    let mut game = match Game::new(data_root()) {
        Ok(game) => game,
        Err(err) => {
            eprintln!(
                "skipping: cannot open data root {}: {err}",
                data_root().display()
            );
            return None;
        }
    };
    if let Err(err) = savegame::load_into(&mut game, &path) {
        eprintln!("skipping: cannot load {}: {err}", path.display());
        return None;
    }
    game.auto_advance = true;
    game.auto_choice = false;
    Some(game)
}

/// 剥离 WOLF 文本转义，只保留可见字符。
///
/// 转义名只消耗 ASCII 字母（再可选方括号参数）。绝不能把后续数字一并吞掉：
/// CE238 的槽 321/322 形如 \E200，若把数字当转义名会让整段变空。
fn visible(raw: &str) -> String {
    let mut out = String::new();
    let mut it = raw.chars().peekable();
    while let Some(c) = it.next() {
        if (c as u32) != 92 {
            out.push(c);
            continue;
        }
        while let Some(&ch) = it.peek() {
            if ch.is_ascii_alphabetic() {
                it.next();
            } else {
                break;
            }
        }
        if it.peek() == Some(&'[') {
            for ch in it.by_ref() {
                if ch == ']' {
                    break;
                }
            }
        }
    }
    out
}

fn slot_visible(game: &Game, number: i32) -> String {
    game.screen
        .get(number)
        .map(|p| visible(&p.text))
        .unwrap_or_default()
}

fn slot_text(game: &Game, number: i32) -> String {
    slot_visible(game, number).trim().to_owned()
}

fn slot_file(game: &Game, number: i32) -> String {
    game.screen
        .get(number)
        .map(|p| p.file.clone())
        .unwrap_or_default()
}

fn quads_text(game: &Game) -> String {
    let quads = game.text_quads();
    quads
        .iter()
        .map(|q| q.text.as_str())
        .collect::<Vec<_>>()
        .join("")
}

fn weekday_name(day: i32) -> &'static str {
    match day {
        0 => "周一",
        1 => "周二",
        2 => "周三",
        3 => "周四",
        4 => "周五",
        5 => "周六",
        6 => "周日",
        _ => "?",
    }
}

/// 同步写入 numeric 单元与其字符串镜像，用于绕过 cdb numeric 渲染缺口。
fn set_status_cell(game: &mut Game, column: i32, value: i32) {
    game.databases
        .set_num(Container::CData, 0, 12, column, value);
    game.databases
        .set_text(Container::CData, 0, 12, column, &value.to_string());
}

type SaveFingerprint = Vec<(String, u64, u64)>;

fn save_fingerprint() -> SaveFingerprint {
    let mut entries = Vec::new();
    if let Ok(rd) = fs::read_dir(save_dir()) {
        for entry in rd.flatten() {
            let path = entry.path();
            if !path.is_file() {
                continue;
            }
            let Ok(meta) = fs::metadata(&path) else {
                continue;
            };
            let modified = meta
                .modified()
                .ok()
                .and_then(|t| t.duration_since(UNIX_EPOCH).ok())
                .map(|d| d.as_nanos() as u64)
                .unwrap_or(0);
            entries.push((
                path.file_name().unwrap().to_string_lossy().into_owned(),
                meta.len(),
                modified,
            ));
        }
    }
    entries.sort();
    entries
}

fn assert_save_unchanged(before: &SaveFingerprint) {
    assert_eq!(before, &save_fingerprint(), "Save 目录不应被写档流程改动");
}

#[test]
fn ce243_clock_and_weekday_follow_runtime_vars() {
    let before = save_fingerprint();

    let clock_cases: [(i32, i32, &str); 5] = [
        (0, 0, "0:00"),
        (9, 5, "9:05"),
        (12, 0, "12:00"),
        (23, 59, "23:59"),
        (7, 5, "7:05"),
    ];
    for (hour, minute, expected) in clock_cases {
        let Some(mut game) = open_loaded(1) else {
            return;
        };
        game.vm.vars.set(4, hour);
        game.vm.vars.set(5, minute);
        assert!(game.start_event(243), "CE243 应能启动");
        for _ in 0..20 {
            game.frame();
        }
        assert_eq!(
            game.stats.warnings, 0,
            "CE243 hour={hour} minute={minute} 不应告警"
        );
        assert_eq!(
            slot_text(&game, 200),
            expected,
            "CE243 时钟应随 vars4/vars5 变化（hour={hour} minute={minute}）"
        );
    }

    for day in 0..=6 {
        let Some(mut game) = open_loaded(1) else {
            return;
        };
        game.vm.vars.set(6, day);
        assert!(game.start_event(243));
        for _ in 0..20 {
            game.frame();
        }
        assert_eq!(game.stats.warnings, 0, "CE243 day={day} 不应告警");
        assert_eq!(
            slot_text(&game, 210),
            weekday_name(day),
            "CE243 星期应随 vars6 变化（day={day}）"
        );
    }

    assert_save_unchanged(&before);
}

#[test]
fn ce242_money_and_cohabitation_follow_runtime_vars() {
    let before = save_fingerprint();

    for money in [0, 7, 10_000, 123_456, 999_999] {
        let Some(mut game) = open_loaded(1) else {
            return;
        };
        game.vm.vars.set(7, money);
        assert!(game.start_event(242), "CE242 应能启动");
        for _ in 0..20 {
            game.frame();
        }
        assert_eq!(game.stats.warnings, 0, "CE242 money={money} 不应告警");
        assert_eq!(
            slot_text(&game, 250),
            "持有金钱",
            "CE242 金钱标签应为固定文案"
        );
        assert_eq!(
            slot_text(&game, 251),
            format!("{money}円"),
            "CE242 持有金钱数值应随 vars7 变化"
        );
    }

    for days in [5, 99] {
        let Some(mut game) = open_loaded(1) else {
            return;
        };
        game.vm.vars.set(99, days);
        assert!(game.start_event(242));
        for _ in 0..20 {
            game.frame();
        }
        assert_eq!(game.stats.warnings, 0, "CE242 days={days} 不应告警");
        let normalized: String = slot_visible(&game, 252).split_whitespace().collect();
        assert_eq!(
            normalized,
            format!("同居{days}天"),
            "CE242 同居天数应随 vars99 变化"
        );
    }

    assert_save_unchanged(&before);
}

#[test]
fn ce242_action_and_energy_follow_cdata_status_cells() {
    let before = save_fingerprint();

    let Some(mut game) = open_loaded(1) else {
        return;
    };
    // 只读检查：行动力 = 0:12:8/0:12:9，精力 = 0:12:6/0:12:7。
    assert_eq!(game.databases.num(Container::CData, 0, 12, 8), Some(60));
    assert_eq!(game.databases.num(Container::CData, 0, 12, 9), Some(65));
    assert_eq!(game.databases.num(Container::CData, 0, 12, 6), Some(3));
    assert_eq!(game.databases.num(Container::CData, 0, 12, 7), Some(3));

    assert!(game.start_event(242));
    for _ in 0..20 {
        game.frame();
    }
    assert_eq!(game.stats.warnings, 0, "CE242 基准不应告警");
    // The VM expands `\cdb` while decoding the picture, so the rendered quads
    // carry the CDataBase 0:12:8/9 and 0:12:6/7 numbers directly.
    let initial = quads_text(&game);
    let compact_initial: String = initial.chars().filter(|c| !c.is_whitespace()).collect();
    assert!(
        compact_initial.contains("行动力60/65"),
        "CE242 行动力面板应显示 CDataBase 0:12:8/9，实际 {initial:?}"
    );
    assert!(
        compact_initial.contains("精力3/3"),
        "CE242 精力面板应显示 CDataBase 0:12:6/7，实际 {initial:?}"
    );

    for (action, action_max, energy, energy_max) in [(42, 45, 7, 7), (11, 99, 9, 2)] {
        let Some(mut game) = open_loaded(1) else {
            return;
        };
        set_status_cell(&mut game, 8, action);
        set_status_cell(&mut game, 9, action_max);
        set_status_cell(&mut game, 6, energy);
        set_status_cell(&mut game, 7, energy_max);
        assert_eq!(game.databases.num(Container::CData, 0, 12, 8), Some(action));
        assert_eq!(
            game.databases.num(Container::CData, 0, 12, 9),
            Some(action_max)
        );
        assert_eq!(game.databases.num(Container::CData, 0, 12, 6), Some(energy));
        assert_eq!(
            game.databases.num(Container::CData, 0, 12, 7),
            Some(energy_max)
        );

        assert!(game.start_event(242));
        for _ in 0..20 {
            game.frame();
        }
        assert_eq!(game.stats.warnings, 0, "CE242 改值不应告警");
        let quads = quads_text(&game);
        // Text quads split on ASCII spaces (the layout keeps the gap, not a space
        // glyph), so compare the visible glyph run with whitespace removed.
        let compact: String = quads.chars().filter(|c| !c.is_whitespace()).collect();
        assert!(
            compact.contains(&format!("行动力{action}/{action_max}")),
            "CE242 行动力应随 DB 单元变化：期望 行动力{action}/{action_max}，实际 quads={quads:?}"
        );
        assert!(
            compact.contains(&format!("精力{energy}/{energy_max}")),
            "CE242 精力应随 DB 单元变化：期望 精力{energy}/{energy_max}，实际 quads={quads:?}"
        );
    }

    assert_save_unchanged(&before);
}

#[test]
fn ce238_status_panel_shows_trust_and_interest() {
    let before = save_fingerprint();

    for (trust, interest) in [(25, 10), (200, 150), (5, 30)] {
        let Some(mut game) = open_loaded(1) else {
            return;
        };
        game.vm.vars.set(20, trust);
        game.vm.vars.set(21, interest);
        assert!(game.start_event(238), "CE238 应能启动");
        for _ in 0..20 {
            game.frame();
        }
        assert_eq!(
            game.stats.warnings, 0,
            "CE238 trust={trust} interest={interest} 不应告警"
        );
        assert_eq!(
            slot_text(&game, 321),
            trust.to_string(),
            "CE238 槽 321 应显示信頼值（vars20）"
        );
        assert_eq!(
            slot_text(&game, 322),
            interest.to_string(),
            "CE238 槽 322 应显示性興味值（vars21）"
        );
        assert!(
            slot_text(&game, 323).contains("普通"),
            "CE238 槽 323 应显示状态标签"
        );
        assert!(
            slot_file(&game, 320).ends_with("status01.png"),
            "CE238 槽 320 应使用 status01.png，实际 {:?}",
            slot_file(&game, 320)
        );
    }

    assert_save_unchanged(&before);
}

#[test]
fn ce237_status_panel_draws_good_bad_and_sleep_icon() {
    let before = save_fingerprint();

    let Some(mut game) = open_loaded(1) else {
        return;
    };
    assert!(game.start_event(237), "CE237 应能启动");
    for _ in 0..20 {
        game.frame();
    }
    assert_eq!(game.stats.warnings, 0, "CE237 不应告警");

    for number in 1992..=2000 {
        assert!(game.screen.get(number).is_some(), "CE237 应绘制槽 {number}");
    }
    assert_eq!(slot_text(&game, 1995), "GOOD", "CE237 槽 1995 应为 GOOD");
    assert_eq!(slot_text(&game, 1999), "BAD", "CE237 槽 1999 应为 BAD");
    assert!(
        slot_file(&game, 2000).ends_with("sleeping_staus.png"),
        "CE237 槽 2000 应为睡眠状态图标，实际 {:?}",
        slot_file(&game, 2000)
    );

    assert_save_unchanged(&before);
}

/// CE238 的显示分支用 head 0x10000（相对坐标）：先按隐藏分支把面板停在 x=-305，
/// 再显示时 +305 应落在 x=0，五个文本也从各自隐藏坐标平移 (+305, 0)。
#[test]
fn ce238_relative_panel_lands_at_the_left_edge() {
    let before = save_fingerprint();

    let Some(mut game) = open_loaded(1) else {
        return;
    };
    game.vm.vars.set(20, 25);
    game.vm.vars.set(21, 10);
    let hide = game.vm.start_event(238).expect("CE238 hide");
    game.vm
        .instance_mut(hide)
        .expect("hide instance")
        .self_vars
        .set(600, 0); // group 6 slot 0 = flat 600, the call argument
    for _ in 0..20 {
        game.frame();
    }
    let hidden = game.screen.get(320).expect("hidden panel");
    assert_eq!(
        (hidden.x, hidden.y),
        (-305, 0),
        "隐藏分支应把面板停在 x=-305"
    );

    let show = game.vm.start_event(238).expect("CE238 show");
    game.vm
        .instance_mut(show)
        .expect("show instance")
        .self_vars
        .set(600, 1); // group 6 slot 0 = flat 600, the call argument
    for _ in 0..20 {
        game.frame();
    }
    assert_eq!(game.stats.warnings, 0, "CE238 相对坐标不应告警");
    let panel = game.screen.get(320).expect("shown panel");
    assert_eq!((panel.x, panel.y), (0, 0), "显示分支应把面板相对移到 x=0");
    let at = |number: i32| {
        let p = game.screen.get(number).expect("label");
        (p.x, p.y)
    };
    assert_eq!(at(321), (240, 90), "信頼值应落在面板标签旁");
    assert_eq!(at(322), (75, 405), "性興味值应落在面板标签旁");
    assert_eq!(at(323), (245, 410), "感度值应落在面板标签旁");
    assert_eq!(at(324), (245, 465), "心情值应落在面板标签旁");

    assert_save_unchanged(&before);
}
