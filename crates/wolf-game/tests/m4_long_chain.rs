//! M4-LONG 百日夜循环端到端测试：《妹！生活 ～単色～》
//!
//! 从新游戏第 1 天 08:30 的日菜单开始，用「白天行动 -> 19:30 就寝 CE251 -> 翌朝
//! 日菜单」逐日驱动 100 个游戏日，验证日常循环在长程上稳定，并在 v99==100 时
//! 由 CE258 触发 100 日结局（v201=1、HAPPYEND、"我知道 / 不知道" 选项）。
//!
//! 休日（v6=5/6）的 CE259 主菜单选择「睡觉」结束白天；工作日按 m3_week_loop 的
//! 既有策略选项目。数据缺失时跳过（exit 0）。

use std::path::PathBuf;

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
    let chosen = options[index].clone();
    game.set_choice_cursor(index);
    press_ok(game);
    chosen
}

/// 跑白天菜单直到 19:30 就寝前（choices 关闭）。
fn drive_daytime(game: &mut Game) {
    let mut seen: Vec<Vec<String>> = Vec::new();
    for _ in 0..60 {
        if game.choices.is_none() {
            for _ in 0..500 {
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
        let options = game.choices.as_ref().unwrap().options.clone();
        if options.iter().any(|o| o.contains("我知道"))
            && options.iter().any(|o| o.contains("不知道"))
        {
            // 100 日结局选项：交给外层断言，不再自动选择。
            break;
        }
        if options.iter().any(|o| o.contains("睡觉"))
            && options.iter().any(|o| o.contains("和妹妹一起玩"))
        {
            // 休日 CE259：直接睡觉结束白天。
            choose(game, "睡觉");
        } else if options.iter().any(|o| o.contains("把积攒的家务做完")) {
            choose(game, "把积攒的家务做完");
        } else if options.iter().any(|o| o.contains("在家里悠闲度过")) {
            choose(game, "在家里悠闲度过");
        } else if options.iter().any(|o| o.contains("一个人去")) {
            choose(game, "一个人去");
        } else if options.iter().any(|o| o.contains("是"))
            && options.iter().any(|o| o.contains("否"))
        {
            choose(game, "是");
        } else if options.iter().any(|o| o.contains("无所事事")) {
            choose(game, "无所事事");
        } else if options.iter().any(|o| o.contains("和妹妹一起玩")) {
            choose(game, "和妹妹一起玩");
        } else if seen.contains(&options) {
            // 兜底：已知菜单循环时轮到不同选项，避免固定在会回主菜单的项目。
            game.set_choice_cursor(0);
            press_ok(game);
        } else {
            game.set_choice_cursor(0);
            press_ok(game);
        }
        seen.push(options);
    }
}

/// 逐帧推进到下一次弹出选项，同时收集途中出现过的消息文本与选项。
fn wait_for_choice(game: &mut Game, messages: &mut Vec<String>, choices: &mut Vec<String>) {
    for _ in 0..3000 {
        game.frame();
        for message in &game.messages {
            let text = message.text.clone();
            if !text.is_empty() && !messages.contains(&text) {
                messages.push(text);
            }
        }
        if let Some(current) = &game.choices {
            for option in &current.options {
                let text = option.trim().to_owned();
                if !text.is_empty() && !choices.contains(&text) {
                    choices.push(text);
                }
            }
            break;
        }
    }
}

#[test]
fn hundred_day_chain_reaches_the_happy_end_choice() {
    let Some(mut game) = open_game() else {
        return;
    };
    game.auto_advance = true;
    game.auto_choice = false;

    let mut messages: Vec<String> = Vec::new();
    let mut choices: Vec<String> = Vec::new();

    // 从第 1 天 08:30 的日菜单开始。
    assert!(game.start_event(251), "CE251 starts the first morning");
    wait_for_choice(&mut game, &mut messages, &mut choices);
    assert_eq!(var(&game, 99), 1, "应从同居第 1 天开始");
    assert!(game.choices.is_some(), "第 1 天应有日菜单");

    let mut reached_ending = false;
    let mut last_day = 1;

    for _ in 0..110 {
        if game.choices.is_none() {
            break;
        }
        let options = game.choices.as_ref().unwrap().options.clone();
        if options.iter().any(|o| o.contains("我知道"))
            && options.iter().any(|o| o.contains("不知道"))
        {
            reached_ending = true;
            break;
        }

        // 推进白天，然后进 19:30 就寝，等待翌朝。
        drive_daytime(&mut game);
        if let Some(current) = &game.choices {
            if current.options.iter().any(|o| o.contains("我知道"))
                && current.options.iter().any(|o| o.contains("不知道"))
            {
                // 白天内 CE258 直接触发了 100 日结局选项。
                reached_ending = true;
                break;
            }
        }
        assert!(
            game.choices.is_none(),
            "白天结束时不应仍停在菜单, day={} v99={}",
            last_day,
            var(&game, 99)
        );
        assert!(
            game.start_event(251),
            "第 {} 天傍晚应能启动 CE251（v99={}）",
            last_day,
            var(&game, 99)
        );
        wait_for_choice(&mut game, &mut messages, &mut choices);

        let day = var(&game, 99);
        assert_eq!(
            day,
            last_day + 1,
            "同居天数应逐日 +1（上一日 {last_day} -> {day}）"
        );
        assert_eq!(game.stats.warnings, 0, "第 {day} 天不应产生 warning");
        last_day = day;

        if day > 105 {
            break;
        }
    }

    assert!(
        reached_ending,
        "应在 100 日内到达 100 日结局选项，最后停在 v99={} choices={:?}",
        var(&game, 99),
        game.choices.as_ref().map(|c| c.options.clone())
    );
    assert_eq!(var(&game, 99), 100, "100 日结局应恰好触发于第 100 天");

    let final_options = game.choices.as_ref().expect("结局选项").options.clone();
    let final_options: Vec<&str> = final_options.iter().map(|s| s.trim()).collect();
    assert!(
        final_options.contains(&"我知道") && final_options.contains(&"不知道"),
        "结局应给出「我知道 / 不知道」选项, got {final_options:?}"
    );

    // 选择「我知道」后，CE258 继续播放 100 日剧情、写 v201 并给出 HAPPYEND。
    choose(&mut game, "我知道");
    for _ in 0..4000 {
        game.frame();
        for message in &game.messages {
            let text = message.text.clone();
            if !text.is_empty() && !messages.contains(&text) {
                messages.push(text);
            }
        }
        if game.choices.is_some() {
            break;
        }
    }

    assert_eq!(var(&game, 201), 1, "100 日结局应置 v201=1");
    assert_eq!(game.stats.warnings, 0, "100 日长链全程无 warning");
    assert!(
        messages.iter().any(|text| text.contains("同居的100天")),
        "缺失 100 日台词, messages={messages:?}"
    );
    assert!(
        messages.iter().any(|text| text.contains("HAPPYEND")),
        "缺失 HAPPYEND, messages={messages:?}"
    );
}
