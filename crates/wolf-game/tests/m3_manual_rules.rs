//! M3-X：说明书规则 / 妹妹状态 / 精确阈值测试（《妹！生活 ～単色～》本作实测）。
//!
//! 目的：把 docs/M3_MANUAL_ALIGNMENT.md 里尚未被断言的规则变成「实测断言」：
//! 白天自由行动与时间推进、夜间行动的行动力/时间消耗、深夜强制就寝、
//! 妹妹面板 v20/v21/v22/v23 的显示、结局阈值 v199/v201/v200/v202/v203 的判定点。
//!
//! 原则（见 AGENTS.md / Lead 的 PRNG 变更说明）：不 pin 旧 xorshift 的偶然数值，
//! 只断言语义、标签、范围与可复现的时间/计数；随机只影响 v14/v23（脚本里 bin=6），
//! 行动力/时间/信任度增量在本作脚本中是固定写法，但仍以范围而非魔法值断言。
//!
//! 已知本作 2.03 的实际情况（实测记录，避免伪造）：
//! - CE251 没有独立的「05:00 强制结束」分支；实测是小时→醒来时刻映射：
//!   18:30..22:30 -> 当日 00:00；23:30 -> 次日 01:00；00:30/01:30/02:30 只前进 1~1.5h；
//!   03:30/04:30 -> 次日 19:00（整日跳过），05:30/06:30 -> 次日 17:00。
//!   测试把「04:30 就寝 -> 次日 19:00」作为深夜超时导致整日跳过的实测断言，并在注释里
//!   明确记录「本作无 05:00 字面分支」。
//! - CE245 在 01:30/02:30 只提供「今天就这样睡吧」（深夜强制就寝），00:30/03:30 仍有完整六项。
//! - 妹妹面板：CE238 槽 321=v20 信頼、322=v21 性興味、323=v22 感度五档、324=v23 機嫌五档。
//!   感度/機嫌没有额外的百分比变量，五档就是 v22/v23 的 -2..2。
//! - vars199/200/201/202/203 在本作脚本中确实存在（非「仅攻略站」），判定点见静态测试。

use std::fs;
use std::path::PathBuf;
use std::time::UNIX_EPOCH;

use wolf_format::command::Slot;
use wolf_format::commonevent::{CommonEvent, CommonEventData};
use wolf_game::db::Container;
use wolf_game::savegame;
use wolf_game::Game;
use wolf_vm::magic::{Magic, MagicKind};

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

fn save_dir() -> PathBuf {
    data_root().join("Save")
}

fn open_game() -> Option<Game> {
    match Game::new(data_root()) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!(
                "skipping: cannot open data root {}: {err}",
                data_root().display()
            );
            None
        }
    }
}

/// 直接读 SaveData01.sav 建立 Game（不跑标题/auto_choice 的 1600 帧，避免随机动作污染基线）。
/// 实测基线：19:30 / 周一 / v20=25 / v21=10 / v99=1 / AP=60/65 / 精力=3/3。
fn open_loaded() -> Option<Game> {
    let path = save_dir().join("SaveData01.sav");
    if !path.is_file() {
        eprintln!("skipping: missing save {}", path.display());
        return None;
    }
    let mut game = open_game()?;
    if let Err(err) = savegame::load_into(&mut game, &path) {
        eprintln!("skipping: cannot load {}: {err}", path.display());
        return None;
    }
    game.auto_advance = true;
    game.auto_choice = false;
    Some(game)
}

fn save_fingerprint() -> Vec<(String, u64, u64)> {
    let mut out = Vec::new();
    let Ok(read) = fs::read_dir(save_dir()) else {
        return out;
    };
    for entry in read.flatten() {
        let path = entry.path();
        if !path.is_file() {
            continue;
        }
        let Ok(meta) = entry.metadata() else { continue };
        let modified = meta
            .modified()
            .ok()
            .and_then(|time| time.duration_since(UNIX_EPOCH).ok())
            .map(|d| d.as_nanos() as u64)
            .unwrap_or(0);
        out.push((
            path.file_name().unwrap().to_string_lossy().into_owned(),
            meta.len(),
            modified,
        ));
    }
    out.sort();
    out
}

fn assert_save_unchanged(before: &[(String, u64, u64)]) {
    // 只比较测试开始前已存在的存档：本仓库多人并行，其它 agent 可能在同一 Save 目录
    // 新建 SaveData07 等槽位，不应把这种无关新增误判为「本测试改动了存档」。
    let after: Vec<(String, u64, u64)> = save_fingerprint()
        .into_iter()
        .filter(|(name, _, _)| before.iter().any(|(b, _, _)| b == name))
        .collect();
    assert_eq!(after, before, "测试不应改动已有的 Save 存档");
}

fn var(game: &Game, index: usize) -> i32 {
    game.vm.vars.get(index)
}

fn ap(game: &Game) -> i32 {
    game.databases.num(Container::CData, 0, 12, 8).unwrap_or(-1)
}
fn ap_max(game: &Game) -> i32 {
    game.databases.num(Container::CData, 0, 12, 9).unwrap_or(-1)
}

/// 剥离 WOLF 文本转义；转义名只吃 ASCII 字母，绝不能吞掉后面的数字（\E200）。
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

fn slot_text(game: &Game, number: i32) -> String {
    game.screen
        .get(number)
        .map(|p| visible(&p.text))
        .unwrap_or_default()
        .trim()
        .to_owned()
}

fn slot_file(game: &Game, number: i32) -> String {
    game.screen
        .get(number)
        .map(|p| p.file.clone())
        .unwrap_or_default()
}

fn press_ok(game: &mut Game) {
    game.key_bits = wolf_game::key::OK;
    game.frame();
    game.key_bits = 0;
}

fn choose(game: &mut Game, needle: &str) -> String {
    let options = game.choices.as_ref().expect("choices open").options.clone();
    let index = options
        .iter()
        .position(|option| option.contains(needle))
        .unwrap_or_else(|| panic!("no option containing {needle:?} in {options:?}"));
    let picked = options[index].clone();
    game.set_choice_cursor(index);
    press_ok(game);
    picked
}

fn wait_choices(game: &mut Game, frames: usize) -> bool {
    for _ in 0..frames {
        game.frame();
        if game.choices.is_some() {
            return true;
        }
    }
    game.choices.is_some()
}

fn minutes(game: &Game) -> i32 {
    var(game, 4) * 60 + var(game, 5)
}

// ---------------------------------------------------------------------------
// 1) 妹妹状态面板：v20/v21 数值 + v22 感度五档 + v23 機嫌五档。
// ---------------------------------------------------------------------------
#[test]
fn ce238_panel_shows_trust_interest_sensitivity_and_mood() {
    let before = save_fingerprint();
    let sensitivity = [
        (-2, "超钝感"),
        (-1, "钝感"),
        (0, "普通"),
        (1, "敏感"),
        (2, "超敏感"),
    ];
    let mood = [
        (-2, "爆发之前"),
        (-1, "不悦"),
        (0, "普通"),
        (1, "高兴"),
        (2, "哥哥LOVE"),
    ];

    for &(level, sens_label) in &sensitivity {
        let Some(mut game) = open_loaded() else {
            return;
        };
        game.vm.vars.set(20, 42);
        game.vm.vars.set(21, 7);
        game.vm.vars.set(22, level);
        game.vm.vars.set(23, level);
        assert!(game.start_event(238), "CE238 应能启动");
        for _ in 0..30 {
            game.frame();
        }
        assert_eq!(game.stats.warnings, 0, "CE238 v22={level} 不应告警");
        assert_eq!(slot_text(&game, 321), "42", "槽321 应为信頼 v20");
        assert_eq!(slot_text(&game, 322), "7", "槽322 应为性興味 v21");
        assert_eq!(
            slot_text(&game, 323),
            sens_label,
            "槽323 应为感度 v22={level} 的标签"
        );
        let mood_label = mood.iter().find(|(m, _)| *m == level).unwrap().1;
        assert_eq!(
            slot_text(&game, 324),
            mood_label,
            "槽324 应为機嫌 v23={level} 的标签"
        );
        assert!(
            slot_file(&game, 320).ends_with("status01.png"),
            "槽320 应为 status01.png，实际 {:?}",
            slot_file(&game, 320)
        );
    }
    assert_save_unchanged(&before);
}

// ---------------------------------------------------------------------------
// 2) 夜间「开始交流 -> 说话 -> 无关紧要的话题」：行动力 -10、时间 +30 分、信任度上升。
//    PRNG 说明：本作脚本在 EV246 对 v20 用的是固定 +=，不经过 bin=6，故增量稳定；
//    仍用范围断言，避免把旧 RNG 的偶然结果写死。
// ---------------------------------------------------------------------------
#[test]
fn night_conversation_costs_action_points_and_advances_time() {
    let before_save = save_fingerprint();
    let Some(mut game) = open_loaded() else {
        return;
    };

    let ap_before = ap(&game);
    let trust_before = var(&game, 20);
    let minutes_before = minutes(&game);
    assert!(ap_before >= 10, "读档行动力应足够，实际 {ap_before}");

    assert!(game.start_event(245), "CE245 夜コマンド应能启动");
    assert!(wait_choices(&mut game, 300), "夜菜单应弹出");
    choose(&mut game, "开始交流");
    assert!(wait_choices(&mut game, 400), "交流子菜单应弹出");
    choose(&mut game, "说话");
    assert!(wait_choices(&mut game, 400), "话题子菜单应弹出");
    choose(&mut game, "无关紧要的话题");
    for _ in 0..800 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }

    let ap_after = ap(&game);
    let trust_after = var(&game, 20);
    let minutes_after = minutes(&game);

    assert_eq!(ap_after, ap_before - 10, "一次交流应消耗 10 行动力");
    assert_eq!(minutes_after, minutes_before + 30, "一次交流应经过 30 分钟");
    let delta = trust_after - trust_before;
    assert!(
        delta > 0 && delta <= 5,
        "交流后妹妹信頼度应小幅上升，实际 +{delta}"
    );
    assert_eq!(game.stats.warnings, 0);
    assert_save_unchanged(&before_save);
}

// ---------------------------------------------------------------------------
// 3) 夜间泡澡：时间 +60 分，行动力回复（不超过上限）。v14 在 EV249 是 rand(0,3)，
//    属随机量，不在这里断言具体值。
// ---------------------------------------------------------------------------
#[test]
fn night_bath_advances_time_and_restores_action_points() {
    let before_save = save_fingerprint();
    let Some(mut game) = open_loaded() else {
        return;
    };

    let ap_before = ap(&game);
    let cap = ap_max(&game);
    let minutes_before = minutes(&game);

    assert!(game.start_event(245));
    assert!(wait_choices(&mut game, 300));
    choose(&mut game, "泡澡");
    assert!(wait_choices(&mut game, 400));
    choose(&mut game, "一个人洗");
    assert!(wait_choices(&mut game, 400));
    choose(&mut game, "什么都不做");
    for _ in 0..800 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }

    let ap_after = ap(&game);
    assert_eq!(minutes(&game), minutes_before + 60, "泡澡应经过 60 分钟");
    assert!(
        ap_after >= ap_before,
        "泡澡不应减少行动力：{ap_before} -> {ap_after}"
    );
    assert!(ap_after <= cap, "行动力不应超过上限 {cap}，实际 {ap_after}");
    assert_eq!(game.stats.warnings, 0);
    assert_save_unchanged(&before_save);
}

// ---------------------------------------------------------------------------
// 4) 白天自由行动：08:30 日菜单 -> 3 次「无所事事地度过」到 17:00 归宅菜单 -> 19:30。
//    同时核对主循环计数：翌朝 v14 重置 4、v6=0（周一）、v99=1（第 1 天）。
// ---------------------------------------------------------------------------
#[test]
fn daytime_idle_actions_advance_clock_to_evening() {
    let before_save = save_fingerprint();
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.auto_choice = false;

    assert!(game.start_event(251), "应能从就寝事件进入翌朝");
    assert!(wait_choices(&mut game, 1500), "翌朝日菜单应弹出");
    assert_eq!((var(&game, 4), var(&game, 5)), (8, 30), "翌朝应为 08:30");
    assert_eq!(
        (var(&game, 6), var(&game, 99)),
        (0, 1),
        "主循环起始应为周一/第1天"
    );
    assert_eq!(var(&game, 14), 4, "翌朝 v14 应重置为 4（妹位置）");
    let day_menu = game.choices.as_ref().unwrap().options.clone();
    assert!(
        day_menu.iter().any(|o| o.contains("无所事事")),
        "日菜单应有自由行动项"
    );

    for expected in [(12, 0), (15, 0), (17, 0)] {
        choose(&mut game, "无所事事");
        assert!(wait_choices(&mut game, 600), "应弹出确认");
        choose(&mut game, "是");
        assert!(wait_choices(&mut game, 800), "应回到菜单或归宅菜单");
        assert_eq!(
            (var(&game, 4), var(&game, 5)),
            expected,
            "每次自由行动后的时间不符，期望 {expected:?}"
        );
    }

    let home = game.choices.as_ref().unwrap().options.clone();
    assert!(
        home.iter().any(|o| o.contains("一个人去")),
        "17:00 应弹出归宅菜单，实际 {home:?}"
    );
    choose(&mut game, "一个人去");
    for _ in 0..1200 {
        game.frame();
        if game.choices.is_none() && (var(&game, 4), var(&game, 5)) == (19, 30) {
            break;
        }
    }
    assert_eq!((var(&game, 4), var(&game, 5)), (19, 30), "归宅后应到 19:30");
    assert_eq!(game.stats.warnings, 0);
    assert_save_unchanged(&before_save);
}

// ---------------------------------------------------------------------------
// 5) 深夜强制就寝：CE245 在 01:30 / 02:30 只提供「今天就这样睡吧」；00:30 / 03:30 仍是完整六项。
// ---------------------------------------------------------------------------
#[test]
fn deep_night_menu_forces_bedtime() {
    let Some(mut game) = open_loaded() else {
        return;
    };
    game.vm.vars.set(4, 1);
    game.vm.vars.set(5, 30);
    assert!(game.start_event(245));
    assert!(wait_choices(&mut game, 400), "深夜夜菜单应弹出");
    let options: Vec<String> = game
        .choices
        .as_ref()
        .unwrap()
        .options
        .iter()
        .map(|o| o.trim().to_owned())
        .collect();
    assert_eq!(
        options,
        vec!["今天就这样睡吧"],
        "01:30 应只剩就寝项，实际 {options:?}"
    );

    for (hour, expect_full) in [(0, true), (3, true)] {
        let Some(mut game) = open_loaded() else {
            return;
        };
        game.vm.vars.set(4, hour);
        game.vm.vars.set(5, 30);
        assert!(game.start_event(245));
        assert!(wait_choices(&mut game, 400));
        let count = game.choices.as_ref().unwrap().options.len();
        if expect_full {
            assert_eq!(count, 6, "{hour:02}:30 应仍有完整六项夜菜单");
        }
    }
}

// ---------------------------------------------------------------------------
// 6) 傍晚就寝 -> 当日 00:00，星期 +1、同居天数不变。
// ---------------------------------------------------------------------------
#[test]
fn evening_bedtime_rolls_weekday_to_midnight() {
    let before_save = save_fingerprint();
    let Some(mut game) = open_loaded() else {
        return;
    };
    let day_before = var(&game, 99);
    let weekday_before = var(&game, 6);
    assert_eq!((var(&game, 4), var(&game, 5)), (19, 30), "读档应为 19:30");

    assert!(game.start_event(251), "CE251 就寝应能启动");
    for _ in 0..1500 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }
    assert_eq!(
        (var(&game, 4), var(&game, 5)),
        (0, 0),
        "傍晚就寝应快进到 00:00"
    );
    assert_eq!(var(&game, 6), weekday_before + 1, "跨过午夜星期应 +1");
    assert_eq!(var(&game, 99), day_before, "就寝本身不增加同居天数");
    assert_eq!(game.stats.warnings, 0);
    assert_save_unchanged(&before_save);
}

// ---------------------------------------------------------------------------
// 7) 深夜超时（04:30 就寝）-> 整日跳过，落到次日 19:00；v99 +1。
//    本作没有独立的 05:00 判定分支，此测试记录实际的小时映射行为。
// ---------------------------------------------------------------------------
#[test]
fn late_night_bedtime_skips_to_next_evening() {
    let before_save = save_fingerprint();
    let Some(mut game) = open_loaded() else {
        return;
    };
    let day_before = var(&game, 99);
    game.vm.vars.set(4, 4);
    game.vm.vars.set(5, 30);

    assert!(game.start_event(251), "CE251 应能启动");
    let opened = wait_choices(&mut game, 2000);
    if !opened {
        for _ in 0..2000 {
            game.frame();
            if game.choices.is_some() {
                break;
            }
        }
    }
    let options = game
        .choices
        .as_ref()
        .map(|c| c.options.clone())
        .unwrap_or_default();
    assert!(
        options.iter().any(|o| o.contains("去茶叶店")),
        "深夜超时应落到次日购物场景，实际 {options:?}"
    );
    assert_eq!(
        (var(&game, 4), var(&game, 5)),
        (19, 0),
        "04:30 就寝应跳过整日到次日 19:00"
    );
    assert_eq!(var(&game, 99), day_before + 1, "跨日后同居天数应 +1");
    assert_eq!(game.stats.warnings, 0);
    assert_save_unchanged(&before_save);
}

// ---------------------------------------------------------------------------
// 静态部分：结局阈值 vars199/200/201/202/203 与警戒度 v154 的判定点。
// CE258/CE296/CE303 依赖上下文/参数，无法从读档状态独立跑通，故直接解析
// BasicData/CommonEvent.dat 的命令流，断言条件与写值确实存在（静态判定点）。
// ---------------------------------------------------------------------------

fn arg(cmd: &wolf_format::command::Command, index: usize) -> i32 {
    let bytes = cmd
        .params
        .get(index * 4..index * 4 + 4)
        .unwrap_or(&[0, 0, 0, 0]);
    i32::from_le_bytes([bytes[0], bytes[1], bytes[2], bytes[3]])
}

fn as_var(raw: i32) -> Option<u32> {
    match Magic::decode(raw).kind() {
        MagicKind::Var => Some(Magic::decode(raw).index()),
        _ => None,
    }
}

/// 取某条 111 条件分支的所有 (变量, 右值, 运算符)。
fn condition_triples(event: &CommonEvent, pc: usize) -> Vec<(u32, i32, i32)> {
    let Some(Slot::Command(cmd)) = event.commands.get(pc) else {
        return Vec::new();
    };
    if cmd.opcode != 111 {
        return Vec::new();
    }
    let count = (arg(cmd, 0) & 0x0F) as usize;
    let mut out = Vec::new();
    for i in 0..count {
        if let Some(v) = as_var(arg(cmd, 1 + 3 * i)) {
            out.push((v, arg(cmd, 2 + 3 * i), arg(cmd, 3 + 3 * i)));
        }
    }
    out
}

fn all_condition_triples(event: &CommonEvent) -> Vec<(usize, u32, i32, i32)> {
    let mut out = Vec::new();
    for pc in 0..event.commands.len() {
        for (v, rhs, op) in condition_triples(event, pc) {
            out.push((pc, v, rhs, op));
        }
    }
    out
}

fn op150_file(event: &CommonEvent, pc: usize) -> String {
    match event.commands.get(pc) {
        Some(Slot::Command(cmd)) if cmd.opcode == 150 => {
            cmd.strings.first().cloned().unwrap_or_default()
        }
        _ => String::new(),
    }
}

fn writes_var(event: &CommonEvent, pc: usize) -> Option<(u32, i32)> {
    let Some(Slot::Command(cmd)) = event.commands.get(pc) else {
        return None;
    };
    if cmd.opcode != 121 {
        return None;
    }
    let dst = as_var(arg(cmd, 0))?;
    Some((dst, arg(cmd, 1)))
}

#[test]
fn ending_thresholds_are_wired_in_scripts() {
    let path = data_root().join("BasicData/CommonEvent.dat");
    let Ok(bytes) = fs::read(&path) else {
        eprintln!("skipping: missing {}", path.display());
        return;
    };
    let data = CommonEventData::parse(&bytes).expect("CommonEvent.dat 应能解析");

    // 标题画面：v199 == 0 或 1 -> SystemFile/TitleGraphic2.png；否则 -> Picture/title2.jpg。
    let ev42 = data.event(42).expect("CE42 标题事件应存在");
    let title_conds: Vec<(u32, i32, i32)> = (0..ev42.commands.len())
        .flat_map(|pc| condition_triples(ev42, pc))
        .filter(|(v, _, _)| *v == 199)
        .collect();
    assert!(
        title_conds.iter().any(|&(_, rhs, op)| rhs == 0 && op == 2)
            && title_conds.iter().any(|&(_, rhs, op)| rhs == 1 && op == 2),
        "CE42 应存在 v199==0 / v199==1 的标题图分支，实际 {title_conds:?}"
    );
    let files: Vec<String> = (0..ev42.commands.len())
        .map(|pc| op150_file(ev42, pc))
        .filter(|s| !s.is_empty())
        .collect();
    assert!(
        files.iter().any(|f| f.contains("TitleGraphic2.png")),
        "CE42 应含 TitleGraphic2.png 分支，实际 {files:?}"
    );
    assert!(
        files.iter().any(|f| f.contains("title2.jpg")),
        "CE42 应含 title2.jpg 分支，实际 {files:?}"
    );

    // 100 日结局：CE258 pc954 v201==0 且 pc956 v99>=100，pc1002 写 v201=1。
    let ev258 = data.event(258).expect("CE258 晩ごはん処理应存在");
    let pc954 = condition_triples(ev258, 954);
    assert!(
        pc954
            .iter()
            .any(|&(v, rhs, op)| v == 201 && rhs == 0 && op == 2),
        "CE258 pc954 应为 v201==0，实际 {pc954:?}"
    );
    let pc956 = condition_triples(ev258, 956);
    assert!(
        pc956
            .iter()
            .any(|&(v, rhs, op)| v == 99 && rhs == 100 && op == 1),
        "CE258 pc956 应为 v99>=100，实际 {pc956:?}"
    );
    let write_v201 = (995..=1010)
        .find_map(|pc| writes_var(ev258, pc).filter(|&(v, value)| v == 201 && value == 1));
    assert!(write_v201.is_some(), "CE258 应在 100 日结局后写 v201=1");

    // 相册：CE303 读结局标记 v200/v202/v201/v203。
    let ev303 = data.event(303).expect("CE303 アルバム画面呼び出し应存在");
    let album_vars: Vec<u32> = all_condition_triples(ev303)
        .into_iter()
        .map(|(_, v, _, _)| v)
        .collect();
    for flag in [200u32, 201, 202, 203] {
        assert!(
            album_vars.contains(&flag),
            "CE303 相册应读取结局标记 v{flag}，实际 {album_vars:?}"
        );
    }

    // プレイ傾向：CE296 读 v200/v202 决定追加文本。
    let ev296 = data.event(296).expect("CE296 プレイ傾向应存在");
    let trend_vars: Vec<u32> = all_condition_triples(ev296)
        .into_iter()
        .map(|(_, v, _, _)| v)
        .collect();
    for flag in [200u32, 202] {
        assert!(
            trend_vars.contains(&flag),
            "CE296 应读取 v{flag}，实际 {trend_vars:?}"
        );
    }

    // 警戒度：CE277 按 v154 的 {2,3,4}/{5,6,7}/{8,9,10}/{11,12,13} 分档画盒子。
    let ev277 = data.event(277).expect("CE277 警戒度メータ应存在");
    let alert_rhs: Vec<i32> = all_condition_triples(ev277)
        .into_iter()
        .filter(|(_, v, _, _)| *v == 154)
        .map(|(_, _, rhs, _)| rhs)
        .collect();
    for expected in 2..=13 {
        assert!(
            alert_rhs.contains(&expected),
            "CE277 应对 v154=={expected} 有分档，实际 {alert_rhs:?}"
        );
    }
}
