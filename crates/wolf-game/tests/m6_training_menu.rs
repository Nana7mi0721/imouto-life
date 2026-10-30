//! M6 natural training menu: the bedroom's 钻研 (training) icon opens the engine's
//! three-way training prompt (common-event 245) through the same mouse path a player
//! takes, and each option really spends the afternoon and moves the status stats.
//!
//! The entry is the canonical new game: start_map_event_by_name("SampleMapA", 0) with
//! auto-advance / auto-choice answers the character-creation prompts and settles into
//! the 18:30 bedroom on day 1. The training icon is picture 122 (comicon_10.png) at
//! (195,475) in the 1024x576 frame. A real left click hovers it first, then presses for
//! a few frames and releases; that runs the 钻研 action up to its "自主训练提升各项能力"
//! description, and one decide (OK) press then opens event 245's 102 prompt:
//! 力量锻炼 / 空挥 / 冥想.
//!
//! Measured effects (reproduced byte-for-byte across repeated runs; see the deltas
//! pinned below):
//!   * every option: clock 18:30 -> 20:00 (var4 18 -> 20, var5 30 -> 0), a 90-minute
//!     afternoon block; the day (var160) stays 1; no second prompt; 0 warnings.
//!   * option 0 「力量锻炼」: energy var14 100 -> 80 (-20), stat var170 35 -> 37 (+2).
//!   * option 1 「空挥」:     energy var14 100 -> 80 (-20), stat var172  5 ->  7 (+2).
//!   * option 2 「冥想」:     energy var14 100 -> 90 (-10), stat var171  6 ->  8 (+2).
//! The five status stats are var170..var174 (baseline 35/6/5/9/5); each option only
//! touches its own stat, and var48 (day-command id) stays 0 because this is the
//! bedroom action, not the daytime CE251 menu.

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

/// Drives the canonical new game up to the 18:30 day-1 bedroom and stops with
/// auto-choice turned off, so the test can click the icon as a human would.
fn bedroom_game() -> Option<Game> {
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
    game.auto_choice = false;
    Some(game)
}

/// The player-facing click: hover picture 122, press the left button for a few frames,
/// release, then send one decide frame. Leaves the event-245 choice prompt open.
fn open_training_menu(game: &mut Game) {
    game.mouse = [195, 475]; // picture 122, the 钻研 icon
    for _ in 0..10 {
        game.frame();
    }
    game.mouse_buttons = 1;
    for _ in 0..5 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..5 {
        game.frame();
    }
    // The click starts the training description; one decide press opens the 245 menu.
    game.key_bits = wolf_game::key::OK;
    game.frame();
    game.key_bits = 0;
    for _ in 0..120 {
        game.frame();
        if game.choices.is_some() {
            break;
        }
    }
}

#[test]
fn the_bedroom_training_icon_opens_the_three_way_training_menu() {
    let Some(mut game) = bedroom_game() else {
        return;
    };

    // The room is the 18:30 day-1 bedroom, warning-free, with the training icon drawn.
    assert_eq!(game.vm.vars.get(4), 18, "the bedroom clock is 18:00");
    assert_eq!(game.vm.vars.get(5), 30, "and 18:30");
    assert_eq!(game.vm.vars.get(160), 1, "on day 1");
    assert_eq!(game.stats.warnings, 0, "the opening story is warning-free");
    let icon = game
        .screen
        .iter()
        .find(|picture| picture.number == 122)
        .expect("the 钻研 training icon is picture 122");
    assert_eq!((icon.x, icon.y), (195, 475), "the icon sits at (195,475)");
    assert!(!icon.hidden, "the icon is visible to click");
    assert!(game.choices.is_none(), "no prompt before the click");

    open_training_menu(&mut game);

    let options = game
        .choices
        .as_ref()
        .expect("the training menu opens after the click + decide press")
        .options
        .clone();
    assert_eq!(
        options,
        vec!["力量锻炼".to_owned(), "空挥".to_owned(), "冥想".to_owned()],
        "event 245 offers the three-way training prompt"
    );
    assert!(
        game.vm
            .instances()
            .iter()
            .any(|instance| instance.event == 245),
        "the event-245 menu coroutine is alive while the prompt is open"
    );
    // The prompt is drawn over the description picture the click raised.
    let texts: Vec<&str> = game
        .screen
        .iter()
        .map(|picture| picture.text.as_str())
        .collect();
    assert!(
        texts.iter().any(|text| text.contains("自主训练")),
        "the training description is drawn: {texts:?}"
    );
    assert_eq!(game.stats.warnings, 0, "opening the menu is warning-free");
}

#[test]
fn every_training_option_advances_the_clock_and_applies_its_real_effect() {
    // (cursor index, the one stat variable it raises, the gain, the energy cost)
    // Measured: 力量锻炼 -> var170 +2 / -20 energy; 空挥 -> var172 +2 / -20;
    // 冥想 -> var171 +2 / -10. All three spend 18:30 -> 20:00.
    let cases = [
        (0usize, 170usize, 2i32, 20i32),
        (1usize, 172usize, 2i32, 20i32),
        (2usize, 171usize, 2i32, 10i32),
    ];

    for (cursor, stat_var, stat_gain, energy_cost) in cases {
        let Some(mut game) = bedroom_game() else {
            return;
        };
        open_training_menu(&mut game);
        assert!(
            game.choices.is_some(),
            "menu is open before choosing option {cursor}"
        );

        let before_time = (game.vm.vars.get(4), game.vm.vars.get(5));
        let before_energy = game.vm.vars.get(14);
        let before_stat = game.vm.vars.get(stat_var);
        assert_eq!(before_time, (18, 30), "option {cursor} starts at 18:30");
        assert_eq!(before_energy, 100, "option {cursor} starts with 100 energy");

        // Choose the option and let the training subroutine run to completion. The
        // energy drains one point per frame for the training frames, then the 90-minute
        // afternoon block plays out; the coroutine is finished once event 245 is gone.
        game.set_choice_cursor(cursor);
        game.key_bits = wolf_game::key::OK;
        game.frame();
        game.key_bits = 0;
        let mut settled = false;
        for frame in 0..4000 {
            game.frame();
            let running = game
                .vm
                .instances()
                .iter()
                .any(|instance| instance.event == 245);
            if !running && game.choices.is_none() && frame > 30 {
                settled = true;
                break;
            }
        }
        assert!(settled, "option {cursor} finishes its training coroutine");

        assert_eq!(game.stats.warnings, 0, "option {cursor} is warning-free");
        assert_eq!(
            game.vm.vars.get(4),
            20,
            "option {cursor} advances the clock to 20:00"
        );
        assert_eq!(game.vm.vars.get(5), 0, "option {cursor} lands on :00");
        assert_eq!(
            game.vm.vars.get(160),
            1,
            "option {cursor} does not roll the day over"
        );
        assert_eq!(
            game.vm.vars.get(stat_var),
            before_stat + stat_gain,
            "option {cursor} raises stat var {stat_var} by {stat_gain}"
        );
        assert_eq!(
            game.vm.vars.get(14),
            before_energy - energy_cost,
            "option {cursor} spends {energy_cost} energy"
        );
        assert_eq!(
            game.vm.vars.get(48),
            0,
            "the bedroom action is not a CE251 day command"
        );
        assert!(
            game.choices.is_none(),
            "option {cursor} leaves no prompt open"
        );
    }
}
