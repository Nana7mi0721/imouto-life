//! M3-A 日常循环全周贯通测试：《妹！生活 ～単色～》
//!
//! 目标：真实驱动「夜间菜单(CE245) -> 就寝(CE251) -> 翌朝 08:30 日菜单(CE256)
//! -> 白天行动 -> 归宅 -> 夜间菜单」这条日常循环，连续推进至少 3 个游戏日，
//! 并进一步跨到周末（v6=5 时白天菜单切换为休日菜单 CE259）。
//!
//! 数据根与 m1/m2 一致：默认 work/Data，可用 WOLF_DATA_ROOT 覆盖；缺失数据时
//! eprintln 跳过并 return，保证整套测试默认仍 exit 0。本文件只做断言，不依赖任何
//! 未公开的 src 内部改动。
//!
//! 变量语义（本作实测确认，见 docs/HANDOFF_M0.md）：v4=時、v5=分、v6=曜日(0=周一)、
//! v7=所持金、v14=妹位置、v20=妹信頼度、v99=同居天数(HUD「同居 N 天」)。

use std::path::PathBuf;

use wolf_game::Game;

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

/// 屏幕 picture 文本与当前消息文本合并：HUD 标签可能落在任意一层。
fn screen_text(game: &Game) -> Vec<&str> {
    game.screen
        .iter()
        .map(|picture| picture.text.as_str())
        .chain(game.messages.iter().map(|message| message.text.as_str()))
        .collect()
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

/// 用标题菜单的读档项（cursor 1）boot，跑 1600 帧还原卧室 HUD（与 m1/m2 一致）。
fn loaded_game() -> Option<Game> {
    let mut game = open_game()?;
    game.auto_advance = true;
    game.set_choice_cursor(1); // menu2 = load
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.boot().expect("the title map has its autorun event");
    for _ in 0..1600 {
        game.frame();
    }
    Some(game)
}

/// 点一下 OK（handle_choice_input 只认新按下的键，所以先置位再清零）。
fn press_ok(game: &mut Game) {
    game.key_bits = wolf_game::key::OK;
    game.frame();
    game.key_bits = 0;
}

/// 在当前菜单里选择包含 `needle` 的选项。
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

/// 跑 `frames` 帧，并把途中出现过的消息文本按出现顺序收集进 `seen`（相邻去重）。
/// auto_advance 会及时消费消息，所以要逐帧抓取，不能等结束后再读 messages。
fn collect(game: &mut Game, frames: usize, seen: &mut Vec<String>) {
    for _ in 0..frames {
        for message in &game.messages {
            if seen.last().map(|last| last != &message.text).unwrap_or(true) {
                seen.push(message.text.clone());
            }
        }
        game.frame();
    }
}

/// 从「08:30 日菜单」状态开始，反复选「无所事事地度过」+「是」，到 16:00 出现
/// 归宅菜单后选「一个人去」，把一天推进到 19:30 家里。返回途中见过的所有菜单快照。
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

/// 从傍晚调起就寝事件后，跑到翌朝日菜单弹出（出现 choices）为止。
fn morning_wait(game: &mut Game) {
    for _ in 0..1500 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }
}

// ---------------------------------------------------------------------------
// 1) 读档落在第 1 天周一的傍晚 19:30 卧室 HUD。
// ---------------------------------------------------------------------------
#[test]
fn loaded_evening_hud_reflects_day_one() {
    let Some(game) = loaded_game() else {
        return;
    };
    let hud = screen_text(&game).join("|");
    assert!(hud.contains("19:30"), "HUD 应显示 19:30, got: {hud}");
    assert!(hud.contains("周一"), "HUD 应显示 周一, got: {hud}");
    // 零售 LCG 换入后，读档过程中的随机事件会改动持有金钱，禁止 pin 具体数值。
    assert!(
        hud.contains("持有金钱") && hud.contains("円"),
        "HUD 应显示 持有金钱 …円, got: {hud}"
    );
    assert_eq!(var(&game, 99), 1, "同居天数应为 1");
    assert_eq!(var(&game, 6), 0, "应为周一 (v6=0)");
    assert_eq!(var(&game, 4), 19, "时为 19");
    assert_eq!(var(&game, 5), 30, "分为 30");
    assert!(
        (0..=1_000_000).contains(&var(&game, 7)),
        "所持金应为合理非负值, got {}",
        var(&game, 7)
    );
    assert_eq!(var(&game, 20), 25, "妹妹信頼度应为 25");
    assert_eq!(game.stats.warnings, 0, "读档不应产生 warning");
}

// ---------------------------------------------------------------------------
// 2) 夜间命令菜单 CE245 列出六项日常行动。
// ---------------------------------------------------------------------------
#[test]
fn night_menu_lists_daily_actions() {
    let Some(mut game) = loaded_game() else {
        return;
    };
    game.auto_advance = true;
    game.auto_choice = false;

    assert!(game.start_event(245), "应能打开夜コマンド CE245");
    for _ in 0..200 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }
    let options = game
        .choices
        .as_ref()
        .expect("夜コマンド菜单应打开")
        .options
        .clone();
    assert_eq!(
        options,
        vec![
            "开始交流 ", "泡茶 ", "泡澡 ", "网上购物 ", "今天就这样睡吧 ", "0"
        ],
        "夜コマンド应恰有六项"
    );
    assert_eq!(game.choice_cursor(), 0, "初始光标应在第 0 项");
    assert_eq!(game.stats.warnings, 0);
}

// ---------------------------------------------------------------------------
// 3) 夜间选「今天就这样睡吧」-> 确认「是」-> 真实就寝把时间快进到午夜，
//    星期推进一天（周一 -> 周二），金钱/信頼度不变、同居天数不变。
// ---------------------------------------------------------------------------
#[test]
fn bedtime_advances_weekday_to_midnight() {
    let Some(mut game) = loaded_game() else {
        return;
    };
    game.auto_advance = true;
    game.auto_choice = false;
    let money_before = var(&game, 7);

    assert!(game.start_event(245), "应能打开夜コマンド");
    for _ in 0..200 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }
    choose(&mut game, "今天就这样睡吧");

    let mut seen: Vec<String> = Vec::new();
    collect(&mut game, 200, &mut seen);
    let options = game
        .choices
        .as_ref()
        .expect("应弹出 sleep 确认")
        .options
        .clone();
    assert!(
        options.iter().any(|option| option.contains("是")) && options.iter().any(|option| option.contains("否")),
        "应弹出 是/否 确认, got {options:?}"
    );
    choose(&mut game, "是");
    collect(&mut game, 800, &mut seen);

    let transcript = seen.join("\n");
    assert!(transcript.contains("差不多该睡了吧"), "应有就寝确认提示, got {transcript}");
    assert!(transcript.contains("已经要睡了吗"), "应有妹妹回应, got {transcript}");
    assert_eq!((var(&game, 4), var(&game, 5)), (0, 0), "时间应快进到 00:00");
    assert_eq!(var(&game, 6), 1, "跨过午夜，星期 周一(0)->周二(1)");
    assert_eq!(var(&game, 99), 1, "就寝本身不增加同居天数");
    // 随机夜间事件可能花费金钱；不再 pin 旧 xorshift 的偶发值，只要求不增加。
    assert!(
        var(&game, 7) >= 0 && var(&game, 7) <= money_before,
        "金钱不应增加, before={money_before} after={}",
        var(&game, 7)
    );
    assert_eq!(var(&game, 20), 25, "信頼度不变");
    assert_eq!(game.stats.warnings, 0);
}

// ---------------------------------------------------------------------------
// 4) 就寝 CE251 从干净事件状态跑出「翌朝 08:30 日菜单」：9 条消息 / 74 图 / 6 音效。
// ---------------------------------------------------------------------------
#[test]
fn morning_opens_first_day_menu() {
    let Some(mut game) = open_game() else {
        return;
    };
    game.auto_advance = true;
    game.auto_choice = false;

    assert!(game.start_event(251), "应能启动就寝事件 CE251");
    let mut seen: Vec<String> = Vec::new();
    collect(&mut game, 400, &mut seen);

    assert_eq!(seen.len(), 9, "morning 应产生 9 条消息, got {seen:?}");
    assert!(seen[0].contains("早上好，哥哥"), "首条应为早晨问候, got {:?}", seen[0]);
    assert!(seen[0].contains("饭做好了哦"), "首条应含早餐邀请, got {:?}", seen[0]);
    assert!(
        seen.last().unwrap().contains("那么，该怎么做呢"),
        "末条应为行动提示, got {:?}",
        seen.last()
    );
    assert_eq!(game.stats.pictures, 74, "应绘制 74 张图片");
    assert_eq!(game.stats.sounds, 6, "应触发 6 个音效");
    assert_eq!((var(&game, 4), var(&game, 5)), (8, 30), "时间应到 08:30");
    assert_eq!(var(&game, 99), 1, "进入第 1 天");
    assert_eq!(var(&game, 6), 0, "应为周一");
    let options = game
        .choices
        .as_ref()
        .expect("应弹出日菜单")
        .options
        .clone();
    assert_eq!(
        options,
        vec!["无所事事地度过 ", "在附近散步 ", "做家务 ", "偷内裤 ", "睡觉 "],
        "日菜单应为五项"
    );
    assert_eq!(game.stats.warnings, 0);
}

// ---------------------------------------------------------------------------
// 5) 连续 3 个游戏日：每天「日菜单 -> 白天行动到 19:30 -> 就寝 -> 翌朝 08:30」，
//    同居天数与星期各 +1，三天后为第 4 天周四；全程 warnings=0。
// ---------------------------------------------------------------------------
#[test]
fn three_consecutive_days_advance_day_and_weekday() {
    let Some(mut game) = open_game() else {
        return;
    };
    game.auto_advance = true;
    game.auto_choice = false;

    assert!(game.start_event(251), "应能启动就寝事件");
    morning_wait(&mut game);
    assert_eq!((var(&game, 99), var(&game, 6)), (1, 0), "起始应为第 1 天周一");

    for day in 0..3 {
        let before_day = var(&game, 99);
        let before_week = var(&game, 6);

        let menus = drive_daytime(&mut game);
        assert!(
            menus.iter().any(|menu| menu.iter().any(|option| option.contains("一个人去"))),
            "第 {day} 天白天应出现归宅菜单, menus={menus:?}"
        );
        assert_eq!((var(&game, 4), var(&game, 5)), (19, 30), "第 {day} 天白天应推进到 19:30");
        assert!(game.choices.is_none(), "19:30 应无待选菜单");

        assert!(game.start_event(251), "第 {day} 天应能就寝");
        morning_wait(&mut game);

        assert_eq!(var(&game, 99), before_day + 1, "第 {day} 天后同居天数应 +1");
        assert_eq!(var(&game, 6), before_week + 1, "第 {day} 天后星期应 +1");
        assert_eq!((var(&game, 4), var(&game, 5)), (8, 30), "第 {day} 天翌朝应为 08:30");
        assert_eq!(var(&game, 14), 4, "翌朝妹位置应重置为 4");
        assert!(
            game.choices
                .as_ref()
                .map(|choices| choices.options.iter().any(|option| option.contains("无所事事")))
                .unwrap_or(false),
            "第 {day} 天翌朝应回到日菜单, got {:?}",
            game.choices.as_ref().map(|c| c.options.clone())
        );
        assert_eq!(game.stats.warnings, 0, "第 {day} 天不应产生 warning");
    }

    assert_eq!((var(&game, 99), var(&game, 6)), (4, 3), "三天后应为第 4 天周四");
}

// ---------------------------------------------------------------------------
// 6) 跨到周末：星期推进到周六(v6=5)时，白天菜单由打工/家务日菜单切换为休日菜单
//    （CE259），证明日循环确实按星期区分工作日与休息日。
// ---------------------------------------------------------------------------
#[test]
fn weekend_switches_to_holiday_menu() {
    let Some(mut game) = open_game() else {
        return;
    };
    game.auto_advance = true;
    game.auto_choice = false;

    assert!(game.start_event(251), "应能启动就寝事件");
    morning_wait(&mut game);

    let mut guard = 0;
    while var(&game, 6) < 5 {
        assert!(
            game.choices
                .as_ref()
                .map(|choices| choices.options.iter().any(|option| option.contains("无所事事")))
                .unwrap_or(false),
            "工作日应处于日菜单, v6={}",
            var(&game, 6)
        );
        let _ = drive_daytime(&mut game);
        assert_eq!((var(&game, 4), var(&game, 5)), (19, 30), "工作日应推进到 19:30");
        assert!(game.start_event(251), "应能就寝");
        morning_wait(&mut game);
        assert_eq!(game.stats.warnings, 0, "v6={} 不应产生 warning", var(&game, 6));

        guard += 1;
        assert!(guard < 10, "推进天数过多，可能循环未按预期前进");
    }

    assert_eq!(var(&game, 6), 5, "应推进到周六");
    let options = game
        .choices
        .as_ref()
        .expect("周末应弹出休日菜单")
        .options
        .clone();
    assert_eq!(
        options,
        vec!["和妹妹一起玩 ", "做运动 ", "把积攒的家务做完 ", "努力打工 ", "睡觉 "],
        "周末白天应切换为休日菜单, v6={}",
        var(&game, 6)
    );
    assert_eq!(game.stats.warnings, 0);
}
