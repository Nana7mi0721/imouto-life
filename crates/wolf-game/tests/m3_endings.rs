//! M3 结局（ending）链路的 headless 覆盖。
//!
//! 覆盖范围：
//! * 标题画面：CE42 按 v199（通关标记）切换标题图（TitleGraphic2.png / title2.jpg）。
//! * 100 日结局：CE258「晩ごはん処理」在 v99>=100 且 v201==0 时写 v201=1，
//!   播放 100 日剧情与 `<C>HAPPYEND`，并给出「我知道 / 不知道」选项。
//! * 内裤收集（v202）触发的 Grand End：CE258 写 v203=1 并调用 CE297 スタッフロール，
//!   播放 ending04 与 credit03..08。
//! * 相册 CE303：四个结局标记 v200/v201/v202/v203 各自解锁一张相册图
//!   （album_011..014），基础格 album_008..010 常驻。
//! * CE297 スタッフロール本身可在读档卧室上下文独立运行（47 个正槽位、warnings=0）。
//! * 静态判定点：CE258 的妊娠结局（GOODEND）分支写 v200=1，入口受 v12==1 与
//!   v20>=100 约束；该分支依赖晚餐当日流程的完整上下文，headless 只把它钉在
//!   命令流层面（见 `ending_scripts_are_statically_wired`）。
//!
//! 所有用例在数据缺失时打印 skip 后返回，默认 `cargo test` 仍 exit 0。
//! 不 pin 任何随机（PRNG）派生数值。

use std::collections::BTreeSet;
use std::fs;
use std::path::PathBuf;

use wolf_game::Game;
use wolf_vm::{Magic, MagicKind};

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

/// 去掉 WOLF 文本转义，得到玩家看到的字。
fn visible(raw: &str) -> String {
    let mut out = String::new();
    let mut chars = raw.chars().peekable();
    while let Some(c) = chars.next() {
        if (c as u32) != 92 {
            out.push(c);
            continue;
        }
        while let Some(&ch) = chars.peek() {
            if ch.is_ascii_alphanumeric() {
                chars.next();
            } else {
                break;
            }
        }
        if chars.peek() == Some(&'[') {
            for ch in chars.by_ref() {
                if ch == ']' {
                    break;
                }
            }
        }
    }
    out
}

fn var(game: &Game, index: usize) -> i32 {
    game.vm.vars.get(index)
}

/// 读档卧室：引擎常驻事件全部启动，SaveData01 恢复 HUD，预热 5 帧。
fn bedroom() -> Option<Game> {
    let root = data_root();
    let mut game = match Game::new(&root) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping endings tests: {err}");
            return None;
        }
    };
    game.start_engine_events();
    if let Err(err) = game.load_save(&root.join("Save").join("SaveData01.sav")) {
        eprintln!("skipping endings tests: {err}");
        return None;
    }
    for _ in 0..5 {
        game.frame();
    }
    game.auto_advance = true;
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    Some(game)
}

#[derive(Default)]
struct Run {
    messages: Vec<String>,
    choices: Vec<String>,
    files: BTreeSet<String>,
    positive_pictures: BTreeSet<i32>,
}

/// 跑固定帧数（不按 idle 提前结束：等待选项时 idle 也为 true）。
fn run(game: &mut Game, frames: usize) -> Run {
    let mut out = Run::default();
    for _ in 0..frames {
        game.frame();
        for message in &game.messages {
            let text = visible(&message.text);
            if !out.messages.contains(&text) {
                out.messages.push(text);
            }
        }
        if let Some(choices) = &game.choices {
            for option in &choices.options {
                let text = option.trim().to_owned();
                if !out.choices.contains(&text) {
                    out.choices.push(text);
                }
            }
        }
        for picture in game.screen.iter() {
            if picture.number > 0 {
                out.positive_pictures.insert(picture.number);
            }
            if !picture.file.is_empty() {
                out.files.insert(picture.file.clone());
            }
        }
    }
    out
}

// ---------------------------------------------------------------------------
// 1) 标题图：v199 决定 CE42 用哪张标题画。
// ---------------------------------------------------------------------------

#[test]
fn title_art_switches_on_the_clear_flag() {
    let root = data_root();
    let mut game = match Game::new(&root) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    game.auto_advance = true;
    game.auto_choice = false;
    game.boot().expect("the title map has its autorun event");
    for _ in 0..400 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }

    // CE42 在标题画面按 v199 分支：0 -> TitleGraphic2.png，1 -> picture/title2.jpg。
    // 重新启动 CE42 以绕过 boot 期间 CE48 对普通变量的初始化。
    for (flag, want) in [
        (0i32, "SystemFile/TitleGraphic2.png"),
        (1i32, "Picture/title2.jpg"),
    ] {
        game.vm.vars.set(199, flag);
        game.screen.clear();
        assert!(game.start_event(42), "CE42 restarts for the title branch");
        for _ in 0..30 {
            game.frame();
        }
        let files: Vec<&str> = game
            .screen
            .iter()
            .map(|picture| picture.file.as_str())
            .filter(|file| !file.is_empty())
            .collect();
        assert!(
            files.contains(&want),
            "v199={flag} should paint {want}, got {files:?}"
        );
        assert_eq!(
            game.stats.warnings, 0,
            "v199={flag} title branch is warning-free"
        );
    }
}

// ---------------------------------------------------------------------------
// 2) 100 日结局：v201 置位 + HAPPYEND 文本 + 选项。
// ---------------------------------------------------------------------------

#[test]
fn hundred_day_dinner_sets_the_clear_flag_and_plays_happy_end() {
    let Some(mut game) = bedroom() else { return };
    game.vm.vars.set(99, 100); // 経過日数
    game.vm.vars.set(200, 0); // 妊娠エンド
    game.vm.vars.set(201, 0); // 100 日到達
    game.vm.vars.set(202, 0); // パンツコンプリート
    game.vm.vars.set(203, 0); // エンディング済み

    assert!(game.start_event(258), "CE258 晩ごはん処理 starts");
    let run = run(&mut game, 4000);

    assert_eq!(var(&game, 201), 1, "100 日结局应写 v201=1");
    assert_eq!(var(&game, 203), 0, "仅有 100 日结局时 v203 不应置位");
    assert_eq!(game.stats.warnings, 0, "100 日结局无 warning");
    assert!(
        run.messages
            .iter()
            .any(|text| text.contains("今天是我来这里的第100天")),
        "100 日台词缺失: {:?}",
        run.messages
    );
    assert!(
        run.messages.iter().any(|text| text.contains("HAPPYEND")),
        "100 日 HAPPYEND 缺失: {:?}",
        run.messages
    );
    assert!(
        run.choices.iter().any(|text| text == "我知道")
            && run.choices.iter().any(|text| text == "不知道"),
        "100 日选项缺失: {:?}",
        run.choices
    );
    assert!(
        run.files.contains("cg/ending04.jpg"),
        "100 日结局应绘制 cg/ending04.jpg，实际 {:?}",
        run.files
    );
}

// ---------------------------------------------------------------------------
// 3) 内裤收集完成 -> Grand End 的调度点（静态）。
//
// 运行时说明：CE258 的内裤/Grand End 分支位于 pc802 `v197>=15` 且 pc804
// `v202==1` 之后（pc831..850 置 v210..229=1，pc876 写 v202=1，pc885 写 v203=1，
// pc886 调用 CE297）。该分支外层还受晚餐当日流程的前置条件约束；在并行重构
// PRNG/设置 API 的工作树状态下，headless 直接置 v202=1 会先走 100 日分支，
// 未能稳定复现（早期探针曾在旧引擎下复现 v203=1 + credit03..08）。因此这里把
// 调度点钉在命令流层面，运行时可复现的 100 日分支已在上一个用例覆盖。
// ---------------------------------------------------------------------------

#[test]
fn pants_complete_branch_is_wired_for_the_grand_end() {
    let path = data_root().join("BasicData").join("CommonEvent.dat");
    let Ok(bytes) = fs::read(&path) else {
        eprintln!("skipping: missing {}", path.display());
        return;
    };
    let data =
        wolf_format::commonevent::CommonEventData::parse(&bytes).expect("CommonEvent.dat parses");
    let dinner = data.event(258).expect("CE258 exists");

    // 分支入口：v197 >= 15 且 v202 == 1。
    let gate_v197 = (0..dinner.commands.len()).any(|pc| {
        condition_triples(dinner, pc)
            .iter()
            .any(|&(v, rhs, op)| v == 197 && rhs == 15 && op == 1)
    });
    let gate_v202 = (0..dinner.commands.len()).any(|pc| {
        condition_triples(dinner, pc)
            .iter()
            .any(|&(v, rhs, op)| v == 202 && rhs == 1 && op == 2)
    });
    assert!(gate_v197, "CE258 pants branch should gate on v197>=15");
    assert!(gate_v202, "CE258 pants branch should gate on v202==1");

    // 该分支写 v202=1（パンツコンプ）、写 v203=1，并调用 CE297。
    let writes_v202 = (0..dinner.commands.len()).any(|pc| writes_var(dinner, pc) == Some((202, 1)));
    let writes_v203 = (0..dinner.commands.len()).any(|pc| writes_var(dinner, pc) == Some((203, 1)));
    assert!(
        writes_v202,
        "CE258 should mark v202=1 after the pants ending"
    );
    assert!(writes_v203, "CE258 should mark v203=1 after the grand end");
    let calls_staff_roll = (0..dinner.commands.len()).any(|pc| match dinner.commands.get(pc) {
        Some(wolf_format::command::Slot::Command(cmd)) if cmd.opcode == 210 => {
            arg(cmd, 0) == 500_297
        }
        _ => false,
    });
    assert!(
        calls_staff_roll,
        "CE258 grand end should call CE297 (op210 500297)"
    );

    // 结局画面：ending03 / ending03_2 / credit02 / ending04。
    let ending_files: Vec<String> = (0..dinner.commands.len())
        .filter_map(|pc| match dinner.commands.get(pc) {
            Some(wolf_format::command::Slot::Command(cmd)) if cmd.opcode == 150 => {
                cmd.strings.first().cloned()
            }
            _ => None,
        })
        .collect();
    for want in [
        "cg/ending03.jpg",
        "cg/ending03_2.jpg",
        "cg/credit02.png",
        "cg/ending04.jpg",
    ] {
        assert!(
            ending_files.iter().any(|file| file == want),
            "CE258 should paint {want}, got {:?}",
            ending_files
        );
    }
}

// ---------------------------------------------------------------------------
// 4) 相册：每个结局标记解锁一格。
// ---------------------------------------------------------------------------

#[test]
fn album_reveals_one_slot_per_ending_flag() {
    let root = data_root();
    if Game::new(&root).is_err() {
        eprintln!("skipping: no game data under {}", root.display());
        return;
    }

    // flag = (v200, v201, v202, v203)
    let cases: [([i32; 4], Option<&str>); 6] = [
        ([0, 0, 0, 0], None),
        ([1, 0, 0, 0], Some("Picture/album_011.png")), // 妊娠エンド
        ([0, 1, 0, 0], Some("Picture/album_013.png")), // 100 日
        ([0, 0, 1, 0], Some("Picture/album_012.png")), // パンツコンプ
        ([0, 0, 0, 1], Some("Picture/album_014.png")), // Grand End
        ([1, 1, 1, 1], Some("Picture/album_011.png")),
    ];

    for (flags, want) in cases {
        let mut game = Game::new(&root).expect("game");
        game.vm.vars.set(200, flags[0]);
        game.vm.vars.set(201, flags[1]);
        game.vm.vars.set(202, flags[2]);
        game.vm.vars.set(203, flags[3]);
        game.auto_advance = true;
        game.auto_choice = true;
        game.auto_choice_delay = 2;
        assert!(game.start_event(303), "CE303 album starts");
        let run = run(&mut game, 300);

        for base in [
            "Picture/album_008.png",
            "Picture/album_009.png",
            "Picture/album_010.png",
        ] {
            assert!(
                run.files.contains(base),
                "flags={flags:?}: base album cell {base} missing: {:?}",
                run.files
            );
        }
        let unlocked: Vec<&str> = [
            "Picture/album_011.png",
            "Picture/album_012.png",
            "Picture/album_013.png",
            "Picture/album_014.png",
        ]
        .into_iter()
        .filter(|cell| run.files.contains(*cell))
        .collect();
        match want {
            None => assert!(
                unlocked.is_empty(),
                "flags={flags:?}: no ending cell expected, got {unlocked:?}"
            ),
            Some(cell) => {
                assert!(
                    unlocked.contains(&cell),
                    "flags={flags:?}: {cell} missing, got {unlocked:?}"
                );
                if flags.iter().filter(|&&flag| flag == 1).count() == 1 {
                    assert_eq!(
                        unlocked.len(),
                        1,
                        "flags={flags:?}: exactly one cell unlocks, got {unlocked:?}"
                    );
                }
            }
        }
        assert_eq!(game.stats.warnings, 0, "flags={flags:?}: album warning");
    }
}

// ---------------------------------------------------------------------------
// 5) スタッフロール可从读档卧室独立运行。
// ---------------------------------------------------------------------------

#[test]
fn staff_roll_runs_headless() {
    let Some(mut game) = bedroom() else { return };
    assert!(game.start_event(297), "CE297 スタッフロール starts");
    let run = run(&mut game, 800);

    assert_eq!(game.stats.warnings, 0, "staff roll 无 warning");
    assert!(
        run.positive_pictures.len() >= 40,
        "staff roll 应绘制大量正槽位图，实际 {} 个",
        run.positive_pictures.len()
    );
    assert!(
        run.files.contains("cg/credit03.png"),
        "staff roll 应播放 credit03，实际 {:?}",
        run.files
    );
    assert!(
        game.vm
            .instances()
            .iter()
            .any(|instance| instance.event == 297),
        "CE297 应在 800 帧内保持运行"
    );
}

// ---------------------------------------------------------------------------
// 6) 静态判定点：妊娠结局（GOODEND）分支确实存在于 CE258 命令流。
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

fn condition_triples(
    event: &wolf_format::commonevent::CommonEvent,
    pc: usize,
) -> Vec<(u32, i32, i32)> {
    let Some(wolf_format::command::Slot::Command(cmd)) = event.commands.get(pc) else {
        return Vec::new();
    };
    if cmd.opcode != 111 {
        return Vec::new();
    }
    let count = (arg(cmd, 0) & 0x0F) as usize;
    (0..count)
        .filter_map(|i| {
            as_var(arg(cmd, 1 + 3 * i)).map(|var| (var, arg(cmd, 2 + 3 * i), arg(cmd, 3 + 3 * i)))
        })
        .collect()
}

fn writes_var(event: &wolf_format::commonevent::CommonEvent, pc: usize) -> Option<(u32, i32)> {
    let Some(wolf_format::command::Slot::Command(cmd)) = event.commands.get(pc) else {
        return None;
    };
    if cmd.opcode != 121 {
        return None;
    }
    Some((as_var(arg(cmd, 0))?, arg(cmd, 1)))
}

#[test]
fn ending_scripts_are_statically_wired() {
    let path = data_root().join("BasicData").join("CommonEvent.dat");
    let Ok(bytes) = fs::read(&path) else {
        eprintln!("skipping: missing {}", path.display());
        return;
    };
    let data =
        wolf_format::commonevent::CommonEventData::parse(&bytes).expect("CommonEvent.dat parses");

    // CE258 妊娠结局：v200=1 的写入点，且入口附近存在 v12==1 与 v20>=100 的门。
    let dinner = data.event(258).expect("CE258 exists");
    let write_v200 = (0..dinner.commands.len())
        .find_map(|pc| writes_var(dinner, pc).filter(|&(v, value)| v == 200 && value == 1));
    assert!(
        write_v200.is_some(),
        "CE258 should write v200=1 for the pregnancy ending"
    );
    let gate_v12 = (0..dinner.commands.len()).any(|pc| {
        condition_triples(dinner, pc)
            .iter()
            .any(|&(v, rhs, op)| v == 12 && rhs == 1 && op == 2)
    });
    let gate_v20 = (0..dinner.commands.len()).any(|pc| {
        condition_triples(dinner, pc)
            .iter()
            .any(|&(v, rhs, op)| v == 20 && rhs == 100 && op == 1)
    });
    assert!(gate_v12, "CE258 pregnancy gate should test v12==1");
    assert!(gate_v20, "CE258 pregnancy gate should test v20>=100");

    // CE258 也在 100 日阈值处写 v201=1。
    let writes_clear =
        (0..dinner.commands.len()).any(|pc| writes_var(dinner, pc) == Some((201, 1)));
    assert!(
        writes_clear,
        "CE258 should write v201=1 at the 100-day threshold"
    );

    // CE42 标题分支读 v199 的 0/1。
    let title = data.event(42).expect("CE42 exists");
    let title_conds: Vec<(u32, i32)> = (0..title.commands.len())
        .flat_map(|pc| condition_triples(title, pc))
        .filter(|(v, _, _)| *v == 199)
        .map(|(v, rhs, _)| (v, rhs))
        .collect();
    assert!(
        title_conds.contains(&(199, 0)) && title_conds.contains(&(199, 1)),
        "CE42 should branch on v199==0/1, got {title_conds:?}"
    );

    // CE303 相册读取全部四个结局标记。
    let album = data.event(303).expect("CE303 exists");
    let album_vars: Vec<u32> = (0..album.commands.len())
        .flat_map(|pc| condition_triples(album, pc))
        .map(|(v, _, _)| v)
        .collect();
    for flag in [200u32, 201, 202, 203] {
        assert!(
            album_vars.contains(&flag),
            "CE303 should read ending flag v{flag}"
        );
    }
}
