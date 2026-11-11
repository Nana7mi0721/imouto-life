//! M3-AK: 自有事件（CE212..=303）真实输入可达性审计。
//!
//! m3_event_smoke 只验证事件能启动、跑帧、warnings==0。这里在同样的读档卧室上下文上，
//! 用真实按键注入（非 auto_choice）驱动每个事件，观察它能否在输入下继续推进或结束；
//! 不能结束的如实归类为「等待输入的常驻循环」并记录最后的画面/消息/选项/所需按键。
//!
//! 输入驱动：每帧给 game.key_bits 赋一个 28 帧循环里的值，只在一帧内按下再松开，
//! 使引擎看到的是「新鲜按下」（game 在帧末把 key_bits 存入 previous_keys）。循环覆盖
//! 決定(OK/10)、下(DOWN/2)、上(UP/8)、サブ(SUB/12)、キャンセル(CANCEL/11)，并按需
//! 让引擎自行处理消息推进与 opcode-102 选项导航。auto_advance / auto_choice 均关闭，
//! 全部靠注入的按键推进，这样「推进/结束」确实由输入产生。
//!
//! 缺数据时整测跳过（eprintln skipping, return），默认 workspace 运行 exit 0。

use std::collections::BTreeMap;
use std::path::PathBuf;
use std::time::{Duration, Instant};

use wolf_game::key;
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

fn repo_root() -> PathBuf {
    let mut root = data_root();
    root.pop();
    root.pop();
    root
}

/// WOLF 文本转义剥离，断言/记录用玩家可见字形。
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

fn short(text: &str, max: usize) -> String {
    let visible = visible(text);
    let mut out: String = visible.chars().take(max).collect();
    if visible.chars().count() > max {
        out.push('…');
    }
    out
}

/// 一个全新、停在读档卧室状态的 Game（引擎常驻事件运行、HUD 恢复）。
fn bedroom() -> Result<Game, String> {
    let mut game = Game::new(data_root()).map_err(|err| err.to_string())?;
    game.start_engine_events();
    let save = data_root().join("Save").join("SaveData01.sav");
    game.load_save(&save)?;
    for _ in 0..5 {
        game.frame();
    }
    let has_hud = game
        .screen
        .iter()
        .any(|picture| picture.number == 230 && visible(&picture.text).contains("行动力"));
    if !has_hud {
        return Err("SaveData01 did not load into the bedroom HUD".to_owned());
    }
    game.screen.clear();
    // 指针移出屏幕，避免注入的 OK 被当作地图按钮点击。
    game.mouse = [-1, -1];
    Ok(game)
}

/// 28 帧按键循环：只在指定帧按下，其余帧松开。覆盖所有会出现在脚本比较里的键。
const KEY_CYCLE: [(usize, u32); 9] = [
    (0, key::OK),
    (3, key::DOWN),
    (6, key::OK),
    (9, 0),
    (12, key::UP),
    (15, key::OK),
    (18, key::CANCEL),
    (21, 0),
    (24, key::SUB),
];
const KEY_CYCLE_LEN: usize = 28;

fn key_for_frame(frame: u32) -> u32 {
    let idx = (frame as usize) % KEY_CYCLE_LEN;
    KEY_CYCLE
        .iter()
        .find(|(at, _)| *at == idx)
        .map(|(_, bits)| *bits)
        .unwrap_or(0)
}

/// 事件标题：优先从 docs/M3_EVENT_MAP.md 的逐事件表解析，缺失时退回 CE<id>。
fn titles() -> BTreeMap<u32, String> {
    let mut map = BTreeMap::new();
    let doc = repo_root().join("docs").join("M3_EVENT_MAP.md");
    let Ok(text) = std::fs::read_to_string(&doc) else {
        return map;
    };
    for line in text.lines() {
        if !line.starts_with("| ") {
            continue;
        }
        let cells: Vec<&str> = line.split('|').collect();
        if cells.len() < 4 {
            continue;
        }
        let Ok(id) = cells[1].trim().parse::<u32>() else {
            continue;
        };
        if !(212..=303).contains(&id) {
            continue;
        }
        let title = cells[2].trim().to_owned();
        map.insert(id, title);
    }
    map
}

fn diff_counts(
    before: &BTreeMap<String, u64>,
    after: &BTreeMap<String, u64>,
) -> BTreeMap<String, u64> {
    let mut out = BTreeMap::new();
    for (key, value) in after {
        let prev = before.get(key).copied().unwrap_or(0);
        if *value > prev {
            out.insert(key.clone(), value - prev);
        }
    }
    out
}

#[derive(Default)]
struct InputReport {
    started: bool,
    frames_run: u32,
    ended: bool,
    stalled: bool,
    timed_out: bool,
    warnings: u64,
    messages_seen: Vec<String>,
    choices_seen: Vec<String>,
    max_slot: i32,
    sounds: u32,
    diagnostics: BTreeMap<String, u64>,
}

fn frame_budget() -> u32 {
    std::env::var("M3_INPUT_FRAMES")
        .ok()
        .and_then(|v| v.parse().ok())
        .unwrap_or(1800)
}

fn per_event_secs() -> u64 {
    std::env::var("M3_INPUT_SECS")
        .ok()
        .and_then(|v| v.parse().ok())
        .unwrap_or(6)
}

/// 可观测状态指纹：消息数、选项身份、正槽位图片号集合、声音总数。用于检测停滞。
fn signature(game: &Game) -> (usize, u32, Vec<i32>, usize) {
    let choices = game
        .choices
        .as_ref()
        .map(|c| c.options.len() as u32 + c.options.first().map(|s| s.len() as u32).unwrap_or(0))
        .unwrap_or(0);
    let mut slots: Vec<i32> = game
        .screen
        .iter()
        .filter(|p| p.number > 0)
        .map(|p| p.number)
        .collect();
    slots.sort_unstable();
    slots.dedup();
    (game.messages.len(), choices, slots, game.sounds.len())
}

fn run_one_input(id: u32, frames_budget: u32, cap: Duration) -> Result<InputReport, String> {
    let mut game = bedroom()?;
    game.auto_advance = false;
    game.auto_choice = false;

    let warnings_before = game.stats.warnings;
    let diagnostics_before = game.diagnostics.clone();
    game.screen.clear();

    let before: Vec<u32> = game.vm.instances().iter().map(|inst| inst.id).collect();
    let mut report = InputReport::default();
    // WOLF keeps a common event's self variables between invocations, so the
    // engine already started CE269 during `start_engine_events` and left its
    // self99 = 1 "already initialised" guard in the bank. Starting the event a
    // second time then parks on the 999999-frame wait and says nothing, which is
    // the correct runtime behaviour but not the standalone first-run audit this
    // test performs. Drop the bank so each event is observed from its boot state.
    game.vm.vars.common_self.remove(&id);
    report.started = game.start_event(id);
    if !report.started {
        return Ok(report);
    }
    let main = game
        .vm
        .instances()
        .iter()
        .find(|inst| inst.event == id && !before.contains(&inst.id))
        .map(|inst| inst.id);

    let started_at = Instant::now();
    let mut last_sig = signature(&game);
    let mut stale_for = 0u32;
    for frame in 0..frames_budget {
        game.key_bits = key_for_frame(frame);
        game.frame();
        game.key_bits = 0;
        report.frames_run += 1;
        for message in &game.messages {
            if !report
                .messages_seen
                .iter()
                .any(|seen| seen == &message.text)
            {
                report.messages_seen.push(message.text.clone());
            }
        }
        if let Some(choices) = &game.choices {
            for option in &choices.options {
                if !report.choices_seen.iter().any(|seen| seen == option) {
                    report.choices_seen.push(option.clone());
                }
            }
        }
        for picture in game.screen.iter() {
            if picture.number > report.max_slot {
                report.max_slot = picture.number;
            }
        }
        report.sounds += game.sounds.len() as u32;

        if let Some(main) = main {
            if game.vm.instance(main).is_none() {
                report.ended = true;
                break;
            }
        }
        let sig = signature(&game);
        if sig != last_sig {
            last_sig = sig;
            stale_for = 0;
        } else {
            stale_for += 1;
            // 连续 900 帧无任何可观测变化：判定为等待输入的常驻停滞，提前结束。
            if stale_for >= 900 {
                report.stalled = true;
                break;
            }
        }
        if started_at.elapsed() >= cap {
            report.timed_out = true;
            break;
        }
    }
    if !report.ended && !report.stalled && !report.timed_out {
        // 到达帧预算仍未结束：常驻/等待输入循环（与冒烟一致的正常类别）。
        report.stalled = true;
    }

    report.warnings = game.stats.warnings - warnings_before;
    report.diagnostics = diff_counts(&diagnostics_before, &game.diagnostics);
    Ok(report)
}

fn selected_ids() -> Vec<u32> {
    if let Ok(raw) = std::env::var("M3_IDS") {
        return raw
            .split(',')
            .filter_map(|part| part.trim().parse().ok())
            .collect();
    }
    (212..=303).collect()
}

/// 不能独立跑的事件（需调用方带参）。CE212 是气泡文辅助子程序，self=0 时 opcode170
/// 循环在 opcode112 比较 self1600006/self1600008 上永不退出，单独跑即死循环。
const CONTEXT_DEPENDENT: &[u32] = &[212];

#[test]
fn own_events_advance_or_report_their_input_needs() {
    let ids = selected_ids();
    let budget = frame_budget();
    let cap = Duration::from_secs(per_event_secs());
    let titles = titles();

    let mut skipped = None;
    let mut rows: Vec<(u32, Result<InputReport, String>)> = Vec::new();
    let mut context_rows: Vec<u32> = Vec::new();
    for id in ids {
        if CONTEXT_DEPENDENT.contains(&id) {
            println!("INPUT {id:>3} CONTEXT-DEPENDENT (not run standalone)");
            context_rows.push(id);
            continue;
        }
        match run_one_input(id, budget, cap) {
            Ok(report) => rows.push((id, Ok(report))),
            Err(err) => {
                if rows.is_empty() {
                    skipped = Some(err);
                    break;
                }
                rows.push((id, Err(err)));
            }
        }
    }
    if let Some(reason) = skipped {
        eprintln!("skipping m3_event_inputs: {reason}");
        return;
    }

    let mut failures = Vec::new();
    let mut ended = 0usize;
    let mut stalled = 0usize;
    let mut timed_out = 0usize;
    for (id, result) in &rows {
        let title = titles.get(id).cloned().unwrap_or_else(|| format!("CE{id}"));
        match result {
            Ok(report) => {
                let last = report
                    .messages_seen
                    .last()
                    .map(|m| short(m, 28))
                    .unwrap_or_default();
                let choices: Vec<String> =
                    report.choices_seen.iter().map(|c| short(c, 10)).collect();
                // 扣除引擎背景诊断（空屏卧室跑同样帧数恒有的三条），只保留事件自身触发的。
                let diag: Vec<String> = report
                    .diagnostics
                    .iter()
                    .filter(|(k, _)| {
                        !k.contains("Transition: kind -1 flags 65546")
                            && !k.starts_with("201 SetMoveRoute")
                            && !k.starts_with("270 Party")
                    })
                    .map(|(k, v)| format!("{k}x{v}"))
                    .collect();
                let outcome = if report.ended {
                    ended += 1;
                    "ended"
                } else if report.timed_out {
                    timed_out += 1;
                    "timeout"
                } else {
                    stalled += 1;
                    "stalled/waiting-input"
                };
                println!(
                    "INPUT {id:>3} title=\"{title}\" start={} frames={:>4} outcome={} msgs={:>2} choices={:>2} maxslot={:>3} sounds={:>2} warn={} last=\"{last}\" options=[{}] diags=[{}]",
                    report.started,
                    report.frames_run,
                    outcome,
                    report.messages_seen.len(),
                    report.choices_seen.len(),
                    report.max_slot,
                    report.sounds,
                    report.warnings,
                    choices.join(" / "),
                    diag.join(";"),
                );
                if !report.started {
                    failures.push(format!("event {id} did not start"));
                }
                if report.frames_run == 0 {
                    failures.push(format!("event {id} ran 0 frames"));
                }
                if report.warnings > 0 {
                    failures.push(format!("event {id} logged {} warning(s)", report.warnings));
                }
                // 停滞事件必须至少在画面上留下可解释的东西（消息/选项/图片），否则视为
                // 无输入可推进且无可见反馈的异常（真实失败）。
                if report.stalled
                    && report.messages_seen.is_empty()
                    && report.choices_seen.is_empty()
                    && report.max_slot <= 0
                {
                    failures.push(format!(
                        "event {id} stalled with no message/choice/picture to explain the wait"
                    ));
                }
            }
            Err(err) => {
                println!("INPUT {id:>3} ERROR {err}");
                failures.push(format!("event {id} errored: {err}"));
            }
        }
    }

    println!(
        "SUMMARY run={} context_dependent={} ended={} stalled={} timeout={} failures={}",
        rows.len(),
        context_rows.len(),
        ended,
        stalled,
        timed_out,
        failures.len()
    );
    for failure in &failures {
        eprintln!("FAIL {failure}");
    }
    assert!(failures.is_empty(), "{} event(s) failed", failures.len());
}
