//! M3-B night-action menu: the whole 夜コマンド branch tree (CE245 -> CE246..CE250).
//!
//! SaveData01 restores the bedroom HUD; from that state the night menu is driven by
//! start_event(245) (夜コマンド). Its observable shape, measured from work/Data with
//! SaveData01 loaded, is:
//!
//! | event | title (JP) | first-level choice (trimmed) | notes |
//! |---|---|---|---|
//! | 245 | 夜コマンド | 开始交流 / 泡茶 / 泡澡 / 网上购物 / 今天就这样睡吧 | the empty sixth slot is hidden |
//! | 246 | コミュニケーション | 说话 / 看看电视吧 / 玩游戏吧 / 鸡鸡伸展！ | reached from 245 #0 |
//! | 247 | ＴＶ視聴 | (none) | reached from 246 #1, plays three lines then ends |
//! | 248 | ゲーム | 对战游戏 / 格斗游戏 / 竞速游戏 / 角色扮演游戏 / 0 / 0 / 0 | reached from 246 #2 |
//! | 249 | お風呂 | 一个人洗 / 两个人洗 | reached from 245 #2 |
//! | 250 | ネットショップ | three item rows | reached from 245 #3, each row then offers 买 / 不买 |
//!
//! Choice 0 (开始交流) hands off to CE246, 2 (泡澡) to CE249 and 3 (网上购物) to CE250;
//! 1 (泡茶) opens a drink submenu and 4 (今天就这样睡吧) asks a 是 / 否 confirmation. A
//! right-click / cancel key closes the current menu instead of picking an option. Every
//! step must keep stats.warnings at zero (no unmodelled opcodes). Data-missing runs skip.

use std::collections::BTreeSet;
use std::path::PathBuf;

use wolf_game::{key, Game};

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

/// Strips WOLF text escapes (font / size / colour / database markers) so assertions can
/// look at the glyphs the player would actually see.
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

/// Loads SaveData01 without booting into the title: it restores the 800 normal vars and
/// the bedroom HUD, and stops there, so start_event drives an event from a known state.
fn open_loaded_bedroom() -> Option<Game> {
    let root = data_root();
    let mut game = match Game::new(root.clone()) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping night-action tests: {err}");
            return None;
        }
    };
    if let Err(err) = game.load_save(&root.join("Save").join("SaveData01.sav")) {
        eprintln!("skipping night-action tests: {err}");
        return None;
    }
    // Let messages dismiss themselves so events march to the next choice without input.
    game.auto_advance = true;
    game.auto_choice = false;
    Some(game)
}

/// One decision key press (the frame the key goes down).
fn press(game: &mut Game, bits: u32) {
    game.key_bits = bits;
    game.frame();
    game.key_bits = 0;
}

/// Runs frames until a choice appears or the budget runs out; true if a choice is live.
fn run_to_choice(game: &mut Game, frames: u32) -> bool {
    for _ in 0..frames {
        game.frame();
        if game.choices.is_some() {
            return true;
        }
    }
    false
}

/// Current choice options, with trailing whitespace trimmed (the data pads labels).
fn options(game: &Game) -> Vec<String> {
    game.choices
        .as_ref()
        .map(|c| c.options.iter().map(|s| s.trim_end().to_owned()).collect())
        .unwrap_or_default()
}

/// Visible text of the messages currently on screen.
fn current_messages(game: &Game) -> Vec<String> {
    game.messages.iter().map(|m| visible(&m.text)).collect()
}

/// Appends newly-seen visible messages to acc, preserving encounter order.
fn absorb(acc: &mut Vec<String>, game: &Game) {
    for text in current_messages(game) {
        if !acc.contains(&text) {
            acc.push(text);
        }
    }
}

fn live_events(game: &Game) -> BTreeSet<u32> {
    game.vm.instances().iter().map(|i| i.event).collect()
}

fn pictures(game: &Game) -> Vec<i32> {
    let mut numbers: Vec<i32> = game
        .screen
        .iter()
        .filter(|p| p.number > 0)
        .map(|p| p.number)
        .collect();
    numbers.sort_unstable();
    numbers.dedup();
    numbers
}

/// Starts id and runs to its first choice, returning the preamble messages seen.
fn start_to_top_menu(game: &mut Game, id: u32, frames: u32) -> Vec<String> {
    game.screen.clear();
    game.start_event(id);
    let mut seen = Vec::new();
    for _ in 0..frames {
        game.frame();
        absorb(&mut seen, game);
        if game.choices.is_some() {
            break;
        }
    }
    seen
}

/// Result of running an event to rest.
struct Run {
    /// Every visible message seen during the run, in encounter order.
    messages: Vec<String>,
    /// The coroutines still live on the last frame (empty once the menu has ended).
    final_events: BTreeSet<u32>,
    /// Union of the on-screen picture numbers seen at any point in the run.
    pictures: Vec<i32>,
}

/// Runs to idle (or the frame budget), collecting messages, the final live events, and
/// the union of picture slots drawn.
fn run_to_idle(game: &mut Game, frames: u32) -> Run {
    let mut seen = Vec::new();
    let mut picture_union = BTreeSet::new();
    for _ in 0..frames {
        let outcome = game.frame();
        absorb(&mut seen, game);
        picture_union.extend(pictures(game));
        if outcome.idle {
            break;
        }
    }
    Run {
        messages: seen,
        final_events: live_events(game),
        pictures: picture_union.into_iter().collect(),
    }
}

// Runs until the shop event (CE250) has fully ended, collecting messages.
///
/// `RunOutcome::idle` is also true while an event merely waits for a choice, so the
/// shop tests cannot use [`run_to_idle`] to know the purchase settled; they must
/// watch CE250 leave the instance stack.
fn run_shop_to_end(game: &mut Game, frames: u32) -> Run {
    let mut seen = Vec::new();
    let mut picture_union = BTreeSet::new();
    for _ in 0..frames {
        game.frame();
        absorb(&mut seen, game);
        picture_union.extend(pictures(game));
        if game.choices.is_none() && !live_events(game).contains(&250) {
            break;
        }
    }
    Run {
        messages: seen,
        final_events: live_events(game),
        pictures: picture_union.into_iter().collect(),
    }
}

// ---------------------------------------------------------------------------
// CE245 夜コマンド: the root menu and its five real actions.
// ---------------------------------------------------------------------------

#[test]
fn ce245_menu_options() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    start_to_top_menu(&mut game, 245, 120);

    assert_eq!(
        options(&game),
        vec![
            "开始交流".to_owned(),
            "泡茶".to_owned(),
            "泡澡".to_owned(),
            "网上购物".to_owned(),
            "今天就这样睡吧".to_owned(),
        ],
        "CE245 draws exactly the five night actions"
    );
    assert_eq!(
        game.stats.warnings, 0,
        "no unmodelled opcodes while drawing CE245"
    );
}

#[test]
fn ce245_cancel_closes_menu() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    start_to_top_menu(&mut game, 245, 120);
    assert!(game.choices.is_some());

    // A cancel/right-click dismisses the menu rather than picking an option.
    press(&mut game, key::CANCEL);
    let run = run_to_idle(&mut game, 90);

    assert!(
        !run.final_events.contains(&245),
        "cancel should end CE245 instead of choosing an action"
    );
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn ce245_action_tea() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    start_to_top_menu(&mut game, 245, 120);

    game.set_choice_cursor(1); // 泡茶
    press(&mut game, key::OK);

    let mut seen = Vec::new();
    let mut opened = false;
    for _ in 0..120 {
        game.frame();
        absorb(&mut seen, &mut game);
        if game.choices.is_some() {
            opened = true;
            break;
        }
    }
    assert!(opened, "泡茶 opens a drink-selection submenu");
    assert!(
        seen.contains(&"喘口气吧。".to_owned()),
        "tea action message"
    );

    let items = options(&game);
    assert_eq!(items.len(), 8, "tea submenu lists eight drinks: {items:?}");
    assert!(
        items[0].starts_with("绿茶"),
        "first drink is 绿茶: {items:?}"
    );
    assert!(
        items.iter().any(|row| row.starts_with("玉露")),
        "tea submenu includes 玉露: {items:?}"
    );
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn ce245_action_bath_dispatches_ce249() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    start_to_top_menu(&mut game, 245, 120);

    game.set_choice_cursor(2); // 泡澡
    press(&mut game, key::OK);

    let mut seen = Vec::new();
    let mut events = BTreeSet::new();
    for _ in 0..40 {
        game.frame();
        absorb(&mut seen, &mut game);
        events.extend(live_events(&game));
        if events.contains(&249) && game.choices.is_some() {
            break;
        }
    }
    assert!(
        seen.contains(&"还是去洗澡吧…".to_owned()),
        "bath action message"
    );
    assert!(events.contains(&249), "泡澡 should launch CE249");
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn ce245_action_shop_dispatches_ce250() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    start_to_top_menu(&mut game, 245, 120);

    game.set_choice_cursor(3); // 网上购物
    press(&mut game, key::OK);

    let mut seen = Vec::new();
    let mut events = BTreeSet::new();
    for _ in 0..40 {
        game.frame();
        absorb(&mut seen, &mut game);
        events.extend(live_events(&game));
        if events.contains(&250) && game.choices.is_some() {
            break;
        }
    }
    assert!(
        seen.contains(&"看一眼网上商店吧。".to_owned()),
        "shop action message"
    );
    assert!(events.contains(&250), "网上购物 should launch CE250");
    assert_eq!(
        game.vm.vars.get(15),
        1,
        "entering the shop flags var15 (0 -> 1)"
    );
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn ce245_action_sleep() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    start_to_top_menu(&mut game, 245, 120);

    game.set_choice_cursor(4); // 今天就这样睡吧
    press(&mut game, key::OK);

    let mut seen = Vec::new();
    let mut opened = false;
    for _ in 0..120 {
        game.frame();
        absorb(&mut seen, &mut game);
        if game.choices.is_some() {
            opened = true;
            break;
        }
    }
    assert!(
        seen.iter().any(|m| m == "差不多该睡了吧…？"),
        "sleep message"
    );
    assert!(opened, "今天就这样睡吧 asks for confirmation");
    assert_eq!(
        options(&game),
        vec!["是".to_owned(), "否".to_owned()],
        "sleep confirmation options"
    );
    assert_eq!(game.stats.warnings, 0);
}

// ---------------------------------------------------------------------------
// CE246 コミュニケーション: opened from CE245 option 0.
// ---------------------------------------------------------------------------

fn enter_ce246(game: &mut Game) {
    start_to_top_menu(game, 245, 120);
    game.set_choice_cursor(0); // 开始交流
    press(game, key::OK);
    assert!(run_to_choice(game, 120), "CE246 should present its submenu");
}

#[test]
fn ce246_submenu_options() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    enter_ce246(&mut game);

    assert_eq!(
        options(&game),
        vec![
            "说话".to_owned(),
            "看看电视吧".to_owned(),
            "玩游戏吧".to_owned(),
            "鸡鸡伸展！".to_owned(),
        ],
        "CE246 lists the four communication options"
    );
    assert_eq!(game.stats.warnings, 0);

    // Option 0 drills into a three-way conversation submenu.
    game.set_choice_cursor(0); // 说话
    press(&mut game, key::OK);
    assert!(run_to_choice(&mut game, 120), "说话 opens a deeper submenu");
    assert_eq!(
        options(&game),
        vec![
            "无关紧要的话题".to_owned(),
            "色色的话题".to_owned(),
            "讨好".to_owned(),
        ],
        "说话 submenu"
    );
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn ce246_dispatch_tv_and_game() {
    // Option 1 (看看电视吧) -> CE247.
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    enter_ce246(&mut game);
    game.set_choice_cursor(1);
    press(&mut game, key::OK);
    let mut seen = Vec::new();
    let mut events = BTreeSet::new();
    for _ in 0..40 {
        game.frame();
        absorb(&mut seen, &mut game);
        events.extend(live_events(&game));
    }
    assert!(
        seen.contains(&"一起看电视吧。".to_owned()),
        "TV dispatch message"
    );
    assert!(events.contains(&247), "看看电视吧 should launch CE247");
    assert_eq!(game.stats.warnings, 0);

    // Option 2 (玩游戏吧) -> CE248.
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    enter_ce246(&mut game);
    game.set_choice_cursor(2);
    press(&mut game, key::OK);
    let mut seen = Vec::new();
    let mut events = BTreeSet::new();
    for _ in 0..40 {
        game.frame();
        absorb(&mut seen, &mut game);
        events.extend(live_events(&game));
    }
    assert!(
        seen.contains(&"那么，去玩游戏吧。".to_owned()),
        "game dispatch message"
    );
    assert!(events.contains(&248), "玩游戏吧 should launch CE248");
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn ce246_dispatch_stretch() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    enter_ce246(&mut game);
    game.set_choice_cursor(3); // 鸡鸡伸展！
    press(&mut game, key::OK);
    let run = run_to_idle(&mut game, 200);
    assert!(
        run.messages.contains(&"…哥哥…这就有点…".to_owned()),
        "stretch branch message"
    );
    // 16000/16001 belonged to the old misrouted template path (report BUG-12).
    for number in [900, 901, 902, 903] {
        assert!(
            run.pictures.contains(&number),
            "stretch branch paints picture {number}"
        );
    }
    assert_eq!(game.stats.warnings, 0);
}

// ---------------------------------------------------------------------------
// CE247 ＴＶ視聴: a three-line cutscene with no further choice.
// ---------------------------------------------------------------------------

#[test]
fn ce247_tv_flow() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    game.screen.clear();
    game.start_event(247);
    let run = run_to_idle(&mut game, 240);

    assert_eq!(
        run.messages,
        vec![
            "一起看电视吧。".to_owned(),
            "…………".to_owned(),
            "高人气的综艺节目。\n身材娇好的女装主持人在说着欢快的话题气氛火热。".to_owned(),
        ],
        "CE247 plays its three TV lines in order"
    );
    assert!(
        run.pictures.contains(&300),
        "CE247 leaves the TV picture #300 on screen"
    );
    assert_eq!(game.stats.warnings, 0);
}

// ---------------------------------------------------------------------------
// CE248 ゲーム: exactly the four real titles (the empty optional slots are hidden).
// ---------------------------------------------------------------------------

#[test]
fn ce248_game_menu_and_branches() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let preamble = start_to_top_menu(&mut game, 248, 160);
    assert_eq!(
        preamble,
        vec![
            "那么，去玩游戏吧。".to_owned(),
            "太棒了！".to_owned(),
            "玩哪个游戏呢…".to_owned(),
        ],
        "CE248 preamble"
    );
    assert_eq!(
        options(&game),
        vec![
            "对战游戏".to_owned(),
            "格斗游戏".to_owned(),
            "竞速游戏".to_owned(),
            "角色扮演游戏".to_owned(),
        ],
        "CE248 lists the four games"
    );
    let menu_pics = pictures(&game);
    // Pictures 16000/16001 used to appear here because opcode 210 sent CE264's
    // 600104 call to template event CE104; with the relative call fixed they are
    // not part of CE248's choice screen (report BUG-12/19).
    for number in [900, 901, 902, 903] {
        assert!(
            menu_pics.contains(&number),
            "CE248 choice screen shows art {number}"
        );
    }
    assert_eq!(game.stats.warnings, 0);

    // Each real game prints its own opening line and leaves the shared art on screen.
    let expectations = [
        (0usize, "好吧，就玩这个对战游戏吧。"),
        (1, "果然还是要选格斗游戏啊。"),
        (2, "好耶！"),
        (3, "嗯。"),
    ];
    for (index, first_message) in expectations {
        let Some(mut game) = open_loaded_bedroom() else {
            return;
        };
        start_to_top_menu(&mut game, 248, 160);
        game.set_choice_cursor(index);
        press(&mut game, key::OK);
        let run = run_to_idle(&mut game, 220);
        assert!(
            run.messages.contains(&first_message.to_owned()),
            "game option {index} should say {first_message:?}"
        );
        for number in [300] {
            assert!(
                run.pictures.contains(&number),
                "game branch keeps picture {number}"
            );
        }
        assert_eq!(game.stats.warnings, 0, "game option {index}");
    }
}

// ---------------------------------------------------------------------------
// CE249 お風呂: first-level menu and both wash modes.
// ---------------------------------------------------------------------------

#[test]
fn ce249_bath_menu_and_branches() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let preamble = start_to_top_menu(&mut game, 249, 120);
    assert!(
        preamble.contains(&"还是去洗澡吧…".to_owned()),
        "bath preamble"
    );
    assert_eq!(
        options(&game),
        vec!["一个人洗".to_owned(), "两个人洗".to_owned()],
        "CE249 offers two wash modes"
    );
    assert_eq!(game.stats.warnings, 0);

    // 一个人洗.
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    start_to_top_menu(&mut game, 249, 120);
    game.set_choice_cursor(0);
    press(&mut game, key::OK);
    let run = run_to_idle(&mut game, 160);
    assert!(
        run.messages.contains(&"好，去吧。".to_owned()),
        "single bath message"
    );
    // The old expectation of picture 16000 came from CE264's misrouted template
    // call (CE101 sets that picture base); the fixed call chain draws the bath
    // through the balloon library instead.
    assert_eq!(game.stats.warnings, 0);

    // 两个人洗.
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    start_to_top_menu(&mut game, 249, 120);
    game.set_choice_cursor(1);
    press(&mut game, key::OK);
    let run = run_to_idle(&mut game, 220);
    assert!(
        run.messages
            .contains(&"哎—，不要——\n哥哥真是色狼。".to_owned()),
        "double bath first line"
    );
    assert!(
        run.messages
            .contains(&"嘛啊，是会这样呢。\n…进去吧。".to_owned()),
        "double bath second line"
    );
    assert_eq!(game.stats.warnings, 0);
}

// ---------------------------------------------------------------------------
// CE250 ネットショップ: item list, per-item confirm, and the insufficient-funds path.
//
// Which three rows the shop offers is branch/RNG-dependent (the script builds the
// list from the current state; the retail random table decides which branch runs),
// and one shipped row is a documented source-data corruption (docs/M3_STRING_DECODE.md
// — an odd run of 0xA1 makes its "円" decode as a CP932 halfwidth glyph). The tests
// therefore never pin names: they read each row's price and pick affordable /
// unaffordable rows from the actual list.
// ---------------------------------------------------------------------------

/// The price printed on one shop row: the last run of ASCII digits in its text.
///
/// Normal rows are "name … 5000円 "; the corrupted CE250 row renders "円" as a
/// halfwidth CP932 glyph, so looking only before 円 would miss it. The price is
/// still the row's trailing digit run in both shapes.
fn row_price(text: &str) -> Option<i32> {
    let mut price = None;
    let mut digits = String::new();
    for ch in text.chars() {
        if ch.is_ascii_digit() {
            digits.push(ch);
        } else if !digits.is_empty() {
            price = digits.parse().ok();
            digits.clear();
        }
    }
    if !digits.is_empty() {
        price = digits.parse().ok();
    }
    price
}

#[test]
fn ce250_shop_menu_and_purchase() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let preamble = start_to_top_menu(&mut game, 250, 140);
    assert!(
        preamble.contains(&"看一眼网上商店吧。".to_owned()),
        "shop preamble"
    );

    let items = options(&game);
    assert_eq!(items.len(), 3, "shop lists three item rows");

    // Every row carries a price. Rows with an intact "円" must have the digits
    // immediately before it; the known corrupted row is exempt (its 円 is damaged).
    let mut prices = Vec::new();
    for (row, text) in items.iter().enumerate() {
        let price = row_price(text).unwrap_or_else(|| panic!("row {row} has no price: {text:?}"));
        if let Some(yen_at) = text.find('円') {
            let before = &text[..yen_at];
            assert!(
                before
                    .chars()
                    .rev()
                    .take_while(|c| *c == ' ' || c.is_ascii_digit())
                    .any(|c| c.is_ascii_digit()),
                "row {row} prints its digits before 円: {text:?}"
            );
        }
        prices.push(price);
    }
    assert_eq!(game.vm.vars.get(15), 1, "shop entry flags var15");
    assert_eq!(game.stats.warnings, 0);

    // Pick the rows from the actual menu: one the loaded money can afford and one
    // it cannot. With SaveData01 (10000 yen) both exist.
    let money = game.vm.vars.get(7);
    assert!(money > 0, "the loaded save has money, got {money}");
    let affordable = prices.iter().position(|p| *p <= money);
    let unaffordable = prices.iter().position(|p| *p > money);
    assert!(
        affordable.is_some(),
        "the shop offers an affordable row with {money} yen: {items:?}"
    );
    let Some(unaffordable) = unaffordable else {
        eprintln!("skipping: every current shop row is affordable with {money} yen");
        return;
    };

    // Unaffordable row: it still asks 买 / 不买; 买 reports the refusal without
    // changing money.
    game.set_choice_cursor(unaffordable);
    press(&mut game, key::OK);
    assert!(
        run_to_choice(&mut game, 120),
        "an unaffordable row asks 买 / 不买"
    );
    assert_eq!(
        options(&game),
        vec!["买".to_owned(), "不买".to_owned()],
        "purchase confirm options"
    );
    let money_before = game.vm.vars.get(7);

    game.set_choice_cursor(0); // 买
    press(&mut game, key::OK);
    let run = run_shop_to_end(&mut game, 200);

    assert!(
        run.messages.contains(&"好像钱不够的样子呢…".to_owned()),
        "an unaffordable item refuses the purchase: {:?}",
        run.messages
    );
    assert_eq!(
        game.vm.vars.get(7),
        money_before,
        "a refused purchase must not change money (var7)"
    );
    assert_eq!(game.vm.vars.get(15), 0, "resolving the shop clears var15");
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn ce250_buying_an_affordable_row_deducts_its_price() {
    // Any affordable row: 买 deducts exactly its printed price and ends the shop
    // with var15 cleared. The row's name is branch-dependent, so only the price
    // read off the menu is used.
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    start_to_top_menu(&mut game, 250, 140);
    let items = options(&game);
    let money = game.vm.vars.get(7);
    let (row, price) = items
        .iter()
        .enumerate()
        .filter_map(|(row, text)| row_price(text).map(|price| (row, price)))
        .find(|(_, price)| *price <= money)
        .unwrap_or_else(|| panic!("no affordable shop row with {money} yen: {items:?}"));

    game.set_choice_cursor(row);
    press(&mut game, key::OK);
    assert!(
        run_to_choice(&mut game, 120),
        "the affordable row asks 买 / 不买"
    );

    game.set_choice_cursor(0); // 买
    press(&mut game, key::OK);
    let _run = run_shop_to_end(&mut game, 200);

    assert_eq!(
        game.vm.vars.get(7),
        money - price,
        "buying row {row} spends exactly its printed price {price}"
    );
    assert_eq!(game.vm.vars.get(15), 0, "resolving the shop clears var15");
    assert_eq!(game.stats.warnings, 0);
}

#[test]
fn ce250_declining_a_purchase_keeps_the_money() {
    // 不买 ends the shop without charging anything, for any affordable row.
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    start_to_top_menu(&mut game, 250, 140);
    let items = options(&game);
    let money = game.vm.vars.get(7);
    let row = items
        .iter()
        .enumerate()
        .filter_map(|(row, text)| row_price(text).map(|price| (row, price)))
        .find(|(_, price)| *price <= money)
        .map(|(row, _)| row)
        .unwrap_or_else(|| panic!("no affordable shop row with {money} yen: {items:?}"));

    game.set_choice_cursor(row);
    press(&mut game, key::OK);
    assert!(
        run_to_choice(&mut game, 120),
        "the affordable row asks 买 / 不买"
    );

    game.set_choice_cursor(1); // 不买
    press(&mut game, key::OK);
    let run = run_shop_to_end(&mut game, 200);

    assert!(
        run.messages.contains(&"…果然还是算了。".to_owned()),
        "declining reports the back-out line: {:?}",
        run.messages
    );
    assert_eq!(
        game.vm.vars.get(7),
        money,
        "declining must not change money"
    );
    assert_eq!(game.vm.vars.get(15), 0, "resolving the shop clears var15");
    assert_eq!(game.stats.warnings, 0);
}
