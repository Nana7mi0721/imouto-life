//! M3-AJ：numeric cell 渲染回归。
//!
//! 背景（task-19/task-24）：表达式图片的 \cdb[a:b:c] / \udb[a:b:c] 宏展开由
//! crates/wolf-game/src/game.rs:1611 的 PictureCells 负责。修复前它只查
//! Databases::text(...)，而本作的行动力/精力（CDataBase 0:12:6..9）等单元是
//! numeric-only（text=None，num=Some），于是 CE242 重绘槽 230/240 后数字渲染为空。
//! task-24 增加了 numeric 兜底（text 为空则回退 num.to_string()）。
//!
//! 本文件是修复后的端到端回归：直接驱动事件，再用 Game::text_quads() 取真实排版结果
//! （TextQuad.text 已是 \cdb 展开后的可见文本），断言这些 numeric 单元以数字出现。
//! 修复前：230 展开成 "行动力/"、240 展开成 "精力 /"，下列断言全部失败。
//!
//! 范围：仅新增本测试文件，不改 src/其它测试。默认数据根 work/Data，缺数据 skip exit0。

use std::path::PathBuf;

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

fn open_loaded(slot: u32) -> Option<Game> {
    let path = data_root()
        .join("Save")
        .join(format!("SaveData{slot:02}.sav"));
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

/// 一张图片排版后的全部文本 run 拼接（TextQuad.text 已解析 \cdb 等转义）。
fn quads_for(game: &Game, number: i32) -> String {
    game.text_quads()
        .into_iter()
        .filter(|q| q.number == number)
        .map(|q| q.text)
        .collect::<Vec<_>>()
        .join("")
}

fn run_event(game: &mut Game, event: u32, frames: usize) {
    assert!(game.start_event(event), "CE{event} 应能启动");
    for _ in 0..frames {
        game.frame();
    }
    assert_eq!(game.stats.warnings, 0, "CE{event} 不应告警");
}

/// 从图片原始文本里抽出所有 \cdb[a:b:c] / \udb[a:b:c] 引用。
/// 返回 (是否 udb, ty, row, column)。
fn cell_refs(raw: &str) -> Vec<(bool, i32, i32, i32)> {
    let bytes = raw.as_bytes();
    let mut out = Vec::new();
    let mut i = 0;
    while i + 5 <= bytes.len() {
        let at = bytes[i];
        if at != b'\\' {
            i += 1;
            continue;
        }
        let kind = if raw[i + 1..].starts_with("cdb[") {
            Some(false)
        } else if raw[i + 1..].starts_with("udb[") {
            Some(true)
        } else {
            None
        };
        let Some(is_udb) = kind else {
            i += 1;
            continue;
        };
        let start = i + 1 + 4; // 跳过 \cdb[ / \udb[
        let Some(rel_end) = raw[start..].find(']') else {
            break;
        };
        let inner = &raw[start..start + rel_end];
        let nums: Vec<i32> = inner
            .split(':')
            .filter_map(|part| part.trim().parse::<i32>().ok())
            .collect();
        if nums.len() == 3 {
            out.push((is_udb, nums[0], nums[1], nums[2]));
        }
        i = start + rel_end + 1;
    }
    out
}

/// PictureCells 修复后的期望值：text 非空则用之，否则 num.to_string()。
/// 返回 (期望文本, 是否 numeric-only)。
fn expected_display(game: &Game, is_udb: bool, ty: i32, row: i32, column: i32) -> (String, bool) {
    let container = if is_udb {
        Container::Data
    } else {
        Container::CData
    };
    let text = game.databases.text(container, ty, row, column);
    let num = game.databases.num(container, ty, row, column);
    if let Some(t) = text {
        if !t.is_empty() {
            return (t.to_owned(), false);
        }
    }
    match num {
        Some(value) => (value.to_string(), true),
        None => (String::new(), false),
    }
}

#[test]
fn ce242_action_and_energy_numeric_cells_render_their_numbers() {
    let Some(mut game) = open_loaded(1) else {
        return;
    };
    // 先证明这四格确实是 numeric-only：文本侧为空，数值侧有值。task-24 的兜底正是
    // 为它们而加；修复前 cdb 展开为空，下面的字形断言必然失败。
    for column in [6, 7, 8, 9] {
        assert_eq!(
            game.databases.text(Container::CData, 0, 12, column),
            None,
            "CData 0:12:{column} 应为 numeric-only（无文本镜像）；若数据变了本回归需重审"
        );
        assert!(
            game.databases
                .num(Container::CData, 0, 12, column)
                .is_some(),
            "CData 0:12:{column} 应有数值"
        );
    }

    run_event(&mut game, 242, 20);

    // 槽 230 引用 cdb[0:12:8]/[0:12:9]（行动力 当前/上限），槽 240 引用 [0:12:6]/[0:12:7]（精力）。
    assert_eq!(
        quads_for(&game, 230),
        "行动力60/65",
        "槽 230 行动力数字应可见"
    );
    assert_eq!(quads_for(&game, 240), "精力 3/3", "槽 240 精力数字应可见");
}

#[test]
fn ce242_money_and_cohabitation_values_still_render() {
    let Some(mut game) = open_loaded(1) else {
        return;
    };
    game.vm.vars.set(7, 10_000); // 持有金钱
    game.vm.vars.set(99, 1); // 同居天数

    run_event(&mut game, 242, 20);

    let money = quads_for(&game, 251);
    assert!(
        money.contains("10000円"),
        "槽 251 应显示 10000円，实际 {money:?}"
    );
    let live: String = quads_for(&game, 252).split_whitespace().collect();
    assert_eq!(live, "同居1天", "槽 252 应显示 同居1天，实际 {live:?}");
}

#[test]
fn ce243_clock_and_weekday_still_render_with_numeric_fallback() {
    let Some(mut game) = open_loaded(1) else {
        return;
    };
    game.vm.vars.set(4, 19); // hour
    game.vm.vars.set(5, 30); // minute
    game.vm.vars.set(6, 0); // 周一

    run_event(&mut game, 243, 20);

    assert_eq!(quads_for(&game, 200), "19:30", "CE243 时刻仍应渲染");
    assert_eq!(quads_for(&game, 210), "周一", "CE243 星期仍应渲染");
}

#[test]
fn ce244_status_panel_numeric_slots_still_render() {
    let Some(mut game) = open_loaded(1) else {
        return;
    };
    run_event(&mut game, 244, 20);

    // 槽 110：\f[14]\E+0，正常应展开为 "+0"（不受 numeric 兜底影响）。
    assert_eq!(quads_for(&game, 110), "+0", "CE244 槽 110 应正常显示 +0");
    // 同一帧里 230/240 的 numeric 数字也必须仍可见。
    assert_eq!(
        quads_for(&game, 230),
        "行动力60/65",
        "CE244 槽 230 行动力应可见"
    );
    assert_eq!(quads_for(&game, 240), "精力 3/3", "CE244 槽 240 精力应可见");
    assert!(
        quads_for(&game, 251).contains("10000円"),
        "CE244 槽 251 金钱应可见"
    );
}

#[test]
fn every_referenced_numeric_cell_renders_a_digit_not_empty() {
    // 扫 CE242 / CE238 里所有被图片引用的 \cdb/\udb 单元；凡 numeric-only 的，
    // 其数字必须真实出现在该图片的排版结果里（而不是空 run）。
    for event in [242u32, 238] {
        let Some(mut game) = open_loaded(1) else {
            return;
        };
        run_event(&mut game, event, 20);

        let mut checked = 0usize;
        for picture in game.screen.iter() {
            let refs = cell_refs(&picture.text);
            if refs.is_empty() {
                continue;
            }
            let rendered = quads_for(&game, picture.number);
            for &(is_udb, ty, row, column) in &refs {
                let (expected, numeric_only) = expected_display(&game, is_udb, ty, row, column);
                if !numeric_only || expected.is_empty() {
                    continue;
                }
                checked += 1;
                assert!(
                    rendered.contains(&expected),
                    "CE{event} 槽 {} 的 numeric 单元 ({is_udb}:{ty}:{row}:{column}) 应渲染出 {expected:?}，实际排版 {rendered:?}",
                    picture.number
                );
            }
        }
        // CE242 至少覆盖行动力/精力四格；防止扫描因解析失败而空转。
        if event == 242 {
            assert!(
                checked >= 4,
                "CE242 应至少覆盖 4 个 numeric 引用，实际 {checked}"
            );
        }
    }
}
