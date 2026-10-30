//! M6 night command menu: at the day-2 19:30 bedroom the player opens the night
//! command menu (common event 245, 夜コマンドメニュー) with a natural mouse gesture —
//! hover the sister sprite (picture 120, Picture/imouto02.png at 240,340) and press
//! the Decide key — and the menu really draws its five button rows.
//!
//! This exercises SampleMapA event 1 page 0 (the night sister-click detector) and the
//! autorun event 4 page 0 (メニュー処理) up to its pc335 -> CE245 call. It deliberately
//! stops at the menu and its 是/算了 confirmation: the CE328 pre-pc700 abort discovered
//! in docs/research/M6_NIGHT_FLOW.md is a separate problem and is NOT solved here.
//!
//! Input path, from the code:
//!   * ev1 page0 pc5 op124 [self100,0x4000,120,8] = picture field 8 = hover test on
//!     picture 120; pc6 gates on hover==1; pc8 op123 [self101,16] polls the keys;
//!     pc9 compares the poll to 10 (CODE_OK / Decide); pc11 writes var68 = 1.
//!   * ev4 page0 runs autorun while var68==1 && var69==1 && var62==0, and at pc335
//!     op210 [500245] calls CE245. BUT pc1 hard-breaks the whole page when
//!     var295==1 (the first-dinner skill TIPS flag set by CE326 pc1648). Normal play
//!     clears it when the player opens the status/skill screen; a straight fast-forward
//!     leaves it 1, so this test normalizes var295 = 0 like a player who closed the tip.
//!
//! Setup reaches the day-2 19:30 bedroom by the canonical new game followed by the
//! real day loop: day-1 evening -> 今天还是睡吧 (CE329) -> day 2 morning -> one 学习会
//! day command -> the evening scene (dinner, CE326) -> 19:30 bedroom. The sleep at the
//! first night seeds var63 = 1 (the flag the sister-click branch leaves behind), which
//! is how m6_mainline drives the same loop headlessly.

use std::path::PathBuf;

use wolf_game::Game;

/// Data root. Same resolution as the other wolf-game integration tests: default to the
/// extracted retail tree the Lead pins for M6, overridable with WOLF_DATA_ROOT.
fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/all".to_owned());
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

/// Press and release the Decide key for one frame.
fn decide(game: &mut Game) {
    game.key_bits = wolf_game::key::OK;
    game.frame();
    game.key_bits = 0;
}

/// Hover a screen point for a few frames, then left-click (press a few frames, release),
/// the way a player drives the picture buttons.
fn click_at(game: &mut Game, x: i32, y: i32) {
    game.mouse = [x, y];
    for _ in 0..10 {
        game.frame();
    }
    game.mouse_buttons = 1;
    for _ in 0..5 {
        game.frame();
    }
    game.mouse_buttons = 0;
}

/// Drive the canonical new game through day 1 into the day-2 19:30 bedroom.
///
/// Uses auto-choice to answer the character-creation and sleep prompts; the first-night
/// sleep seeds var63 = 1 exactly as the sister-click branch does on a real click, which
/// headless input cannot reproduce from its hit-test. A 学习会 day command spends day 2
/// to 17:00, then the evening scene plays out to the 19:30 bedroom. Leaves the game with
/// auto-choice off and auto-advance on.
fn day2_evening_game() -> Option<Game> {
    let mut game = open_game()?;
    game.auto_advance = true;
    game.set_choice_cursor(0);
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.start_map_event_by_name("SampleMapA", 0)
        .expect("the new-game entry point exists");
    for _ in 0..1500 {
        game.frame();
    }

    // Day-1 night: seed the sister-click flag, choose 今天还是睡吧 (index 2), confirm 是的.
    game.auto_choice = false;
    game.vm.vars.set(63, 1);
    for _ in 0..120 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }
    game.set_choice_cursor(2);
    decide(&mut game);
    for _ in 0..120 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }
    game.set_choice_cursor(0);
    decide(&mut game);
    for _ in 0..400 {
        game.frame();
        if game.vm.vars.get(160) == 2 && game.vm.vars.get(4) == 8 && game.vm.vars.get(5) >= 30 {
            break;
        }
    }

    // Day 2: auto-answer, wait for the CE251 day-command button, spend the day with the
    // first command (学习会, at 512,230), then let the evening scene settle.
    game.auto_choice = true;
    for _ in 0..350 {
        game.frame();
        if game
            .screen
            .get(1201)
            .map(|picture| !picture.text.is_empty())
            .unwrap_or(false)
        {
            break;
        }
    }
    click_at(&mut game, 512, 230);
    for _ in 0..1500 {
        game.frame();
        if game.vm.instances().iter().all(|instance| instance.event != 251) {
            break;
        }
    }
    for _ in 0..1200 {
        game.frame();
    }
    game.auto_choice = false;
    Some(game)
}

/// From the day-2 19:30 bedroom, normalize the stale first-dinner tip and open the night
/// menu with the natural hover-sister + Decide gesture. Leaves the game at the open menu.
fn open_night_menu(game: &mut Game) {
    // Documented state normalization: var295==1 means the first-dinner skill TIPS was
    // never dismissed, and ev4 page0 pc1 breaks on it. A player who opened and closed
    // the status/skill screen leaves it 0. Confirm the gate is real before clearing it.
    assert_eq!(
        game.vm.vars.get(295),
        1,
        "the first-dinner tip flag (var295) is set on the fast-forwarded evening"
    );
    game.vm.vars.set(295, 0);
    game.vm.vars.set(68, 0);

    // The natural gesture: hover picture 120 (the sister sprite) and press Decide.
    game.mouse = [240, 340];
    for _ in 0..8 {
        game.frame();
    }
    decide(game);
    for _ in 0..40 {
        game.frame();
    }
}

fn menu_picture_numbers(game: &Game) -> Vec<i32> {
    game.screen
        .iter()
        .map(|picture| picture.number)
        .filter(|number| (1200..=1213).contains(number))
        .collect()
}

#[test]
fn hovering_the_sister_and_pressing_decide_opens_the_night_command_menu() {
    let Some(mut game) = day2_evening_game() else { return };

    // The bedroom is day 2, 19:30, warning-free, with no menu up and no var64 injected.
    assert_eq!(game.vm.vars.get(160), 2, "the day counter is day 2");
    assert_eq!(game.vm.vars.get(4), 19, "the clock is 19:00");
    assert_eq!(game.vm.vars.get(5), 30, "and 19:30");
    assert_eq!(game.stats.warnings, 0, "the evening scene is warning-free");
    assert_eq!(game.vm.vars.get(64), 0, "no var64 injection is needed");
    assert_eq!(game.vm.vars.get(69), 1, "the evening-day flag var69 is set");
    assert!(game.choices.is_none(), "no prompt before the gesture");
    assert!(
        menu_picture_numbers(&game).is_empty(),
        "the night command menu is not open yet"
    );

    // The sister sprite that the hit-test polls is picture 120 at (240,340).
    let sister = game
        .screen
        .iter()
        .find(|picture| picture.number == 120)
        .expect("the sister sprite is picture 120");
    assert_eq!((sister.x, sister.y), (240, 340), "the sprite sits at (240,340)");
    assert!(!sister.hidden, "the sprite is visible to hover");

    open_night_menu(&mut game);

    // The hover+Decide set var68, which lets autorun ev4 page0 reach its CE245 call.
    assert_eq!(game.vm.vars.get(68), 1, "the sister-click flag var68 is set");
    assert_eq!(game.stats.warnings, 0, "opening the menu is warning-free");
    assert!(
        game.vm
            .instances()
            .iter()
            .any(|instance| instance.event == 245),
        "the event-245 night command menu coroutine is alive"
    );

    // The five button rows are drawn: a base_bottan.png background plus its text label.
    let numbers = menu_picture_numbers(&game);
    for expected in [1200, 1201, 1202, 1203, 1204, 1205, 1206, 1207, 1212, 1213] {
        assert!(
            numbers.contains(&expected),
            "menu picture {expected} is drawn; got {numbers:?}"
        );
    }
    let texts: Vec<&str> = game.screen.iter().map(|picture| picture.text.as_str()).collect();
    for label in ["身体接触", "沟通", "洗澡", "泡茶", "今天先休息吧"] {
        assert!(
            texts.iter().any(|text| text.contains(label)),
            "the menu shows {label}: {texts:?}"
        );
    }
    assert!(game.choices.is_none(), "the open menu is not a 102 prompt");
}

#[test]
fn clicking_rest_in_the_night_menu_raises_the_confirm_choice() {
    let Some(mut game) = day2_evening_game() else { return };
    open_night_menu(&mut game);
    assert!(
        game.vm
            .instances()
            .iter()
            .any(|instance| instance.event == 245),
        "the night command menu is open before the rest click"
    );
    assert_eq!(game.stats.warnings, 0);

    // Click 今天先休息吧 (picture 1212/1213 at 512,450). CE245 asks 是/算了.
    click_at(&mut game, 512, 450);
    let mut options: Option<Vec<String>> = None;
    for _ in 0..400 {
        game.frame();
        if let Some(choices) = &game.choices {
            options = Some(choices.options.clone());
            break;
        }
    }
    assert_eq!(
        options.as_deref(),
        Some(["是".to_owned(), "算了".to_owned()].as_slice()),
        "今天先休息吧 raises the 是/算了 confirmation"
    );
    assert_eq!(game.stats.warnings, 0, "the confirmation is warning-free");
    // The CE328 pre-pc700 abort (docs/research/M6_NIGHT_FLOW.md) is out of scope: the
    // test stops at the confirmation and does not press 是.
}
