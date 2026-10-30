//! M2 日常循环（daily loop）测试：《妹！生活 ～単色～》
//!
//! 覆盖两段日常循环的公共事件：
//! - CE245 夜コマンド（夜间命令菜单）：读档进入卧室 HUD 后，展开六项行动菜单，
//!   选择第 5 项「今天就这样睡吧」会先问一句再弹出「是/否」sleep 确认。
//! - CE251 就寝（bedtime）：从干净事件状态跑一遍「就寝 -> 翌朝 -> 早餐 -> 当日行动菜单」，
//!   时间从 00:00 推进到 08:30，说明日循环真正跨到了第二天。
//!
//! 读数与 m1_title_load 一致：标题菜单选 load（cursor 1）后 boot，跑 1600 帧把存档
//! 还原进卧室 HUD。数据缺失时 eprintln 跳过，保证无数据时整套测试仍 exit 0。

use std::path::PathBuf;

use wolf_game::Game;

/// 数据根，解析方式与其它 wolf-game 集成测试一致：默认 work/Data，
/// 可用 WOLF_DATA_ROOT 覆盖（相对路径按 crate 往上两级解析）。
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

/// 屏幕 picture 文本与当前消息文本合并，HUD 标签可能落在任意一层。
fn screen_text(game: &Game) -> Vec<&str> {
    game.screen
        .iter()
        .map(|picture| picture.text.as_str())
        .chain(game.messages.iter().map(|message| message.text.as_str()))
        .collect()
}

/// 用标题菜单的读档项（cursor 1）boot，让存档还原进卧室 HUD。
/// 1600 帧是 m1_title_load 钉死的读档收敛点。
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

/// 按一下 Decide 键（一帧按下、下一帧松开，满足「新按下」判定）。
fn press_ok(game: &mut Game) {
    game.key_bits = wolf_game::key::OK;
    game.frame();
    game.key_bits = 0;
}

/// 跑若干帧直到出现任意选择窗，返回其选项（标签）。若超时返回 None。
fn wait_for_choices(game: &mut Game, max_frames: usize) -> Option<Vec<String>> {
    for _ in 0..max_frames {
        game.frame();
        if let Some(choices) = &game.choices {
            return Some(choices.options.clone());
        }
    }
    None
}

#[test]
fn loaded_bedroom_hud_shows_the_evening_clock_and_stats() {
    let Some(game) = loaded_game() else { return };

    assert_eq!(game.stats.warnings, 0, "the load path is warning-free");
    assert!(
        game.screen.len() > 30,
        "the loaded room and HUD are drawn: {} pictures",
        game.screen.len()
    );
    // 存档把时钟放在 19:30（同居第 1 天，周一）。
    assert_eq!(game.vm.vars.get(4), 19, "the restored clock hour is 19");
    assert_eq!(game.vm.vars.get(5), 30, "the restored clock minute is 30");

    let texts = screen_text(&game);
    for needle in ["19:30", "周一", "行动力", "持有金钱", "5466円"] {
        assert!(
            texts.iter().any(|text| text.contains(needle)),
            "the restored HUD shows {needle}: {texts:?}"
        );
    }
    assert!(game.choices.is_none(), "the loaded bedroom has no open prompt");
}

#[test]
fn night_command_menu_ce245_offers_the_six_actions() {
    let Some(mut game) = loaded_game() else { return };
    // 关掉自动选择，让菜单真的停住等我们按。
    game.auto_choice = false;

    assert!(game.start_event(245), "common event 245 starts");
    let options = wait_for_choices(&mut game, 60);

    // 六项行动菜单，注意每项末尾的空格（最后一项 "0" 没有）。
    assert_eq!(
        options.as_deref(),
        Some(
            [
                "开始交流 ".to_owned(),
                "泡茶 ".to_owned(),
                "泡澡 ".to_owned(),
                "网上购物 ".to_owned(),
                "今天就这样睡吧 ".to_owned(),
                "0".to_owned(),
            ]
            .as_slice()
        ),
        "the night command menu shows its six options"
    );
    assert_eq!(game.choice_cursor(), 0, "the menu opens with the cursor on row 0");
    assert_eq!(
        game.choice_anchor(),
        (512, 230),
        "the menu window is painted at (512,230)"
    );
    assert_eq!(game.stats.warnings, 0, "opening the night menu is warning-free");
}

#[test]
fn rest_option_raises_a_sleep_confirmation() {
    let Some(mut game) = loaded_game() else { return };
    game.auto_choice = false;

    assert!(game.start_event(245), "common event 245 starts");
    assert!(
        wait_for_choices(&mut game, 60).is_some(),
        "the night menu is open before the rest pick"
    );

    // 选第 5 项「今天就这样睡吧」（index 4）并按 Decide。
    game.set_choice_cursor(4);
    press_ok(&mut game);

    // 菜单关闭后先显示一句「差不多该睡了吧…？」，随后弹出「是/否」确认。
    let mut saw_sleep_line = false;
    let mut confirm: Option<Vec<String>> = None;
    for _ in 0..120 {
        game.frame();
        if game
            .messages
            .iter()
            .any(|message| message.text.contains("差不多该睡了吧"))
        {
            saw_sleep_line = true;
        }
        if let Some(choices) = &game.choices {
            confirm = Some(choices.options.clone());
            break;
        }
    }

    assert!(
        saw_sleep_line,
        "selecting rest shows the sleep line (差不多该睡了吧…？)"
    );
    assert_eq!(
        confirm.as_deref(),
        Some(["是 ".to_owned(), "否 ".to_owned()].as_slice()),
        "selecting rest raises the 是/否 sleep confirmation"
    );
    assert_eq!(game.stats.warnings, 0, "the rest selection is warning-free");
}

#[test]
fn sleep_event_251_runs_the_morning_and_advances_the_clock() {
    let Some(mut game) = open_game() else { return };
    // CE251「就寝」自己串起「就寝 -> 翌朝 -> 早餐 -> 当日行动菜单」整段日循环。
    // 与 wolf-cli run --event 251 的基线一致，从干净事件状态启动；若从已读档的
    // 19:30 卧室直接 start，事件会停在等待分支，只吐一句「…………」并停在 00:00。
    game.auto_advance = true;

    assert!(game.start_event(251), "common event 251 starts");

    // 消息会被后续剧情覆盖，所以边跑边抓第一条。
    let mut first_message: Option<String> = None;
    let mut last_len = game.messages.len();
    for _ in 0..400 {
        game.frame();
        if game.messages.len() != last_len {
            if first_message.is_none() && !game.messages.is_empty() {
                first_message = Some(game.messages[0].text.clone());
            }
            last_len = game.messages.len();
        }
    }

    let first = first_message.expect("the sleep event shows messages");
    assert!(
        first.contains("早上好，哥哥！"),
        "the first message is the morning greeting: {first:?}"
    );
    // 实测基线：9 条消息、74 张图片、6 个音效，全程无 warning。
    assert_eq!(game.stats.messages, 9, "the sleep event shows the measured nine messages");
    assert_eq!(game.stats.pictures, 74, "and applies the measured 74 picture commands");
    assert_eq!(game.stats.sounds, 6, "and plays the measured six sounds");
    assert_eq!(game.stats.warnings, 0, "the sleep event is warning-free");

    // 时钟从初始 00:00 推进到翌朝 08:30。
    assert_eq!(
        (game.vm.vars.get(4), game.vm.vars.get(5)),
        (8, 30),
        "the clock advances out of 00:00 into the next morning 08:30"
    );

    // 日循环真的跨到了第二天：停在当日行动菜单，其中「睡觉」是可见选项。
    let options = game
        .choices
        .as_ref()
        .expect("the day-command menu opens at the end of the loop")
        .options
        .clone();
    assert!(
        options.iter().any(|option| option.contains("睡觉")),
        "the next-day command menu offers 睡觉: {options:?}"
    );
}
