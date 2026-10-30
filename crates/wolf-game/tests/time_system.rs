//! The game clock: `217 時刻表示` draws it, `329 就寝処理` and `317 早朝処理` move it.
//!
//! `docs/TIME_SYSTEM.md` is the spec this file pins down, and every number below was
//! measured through that document's command index. The clock is the first subsystem that
//! only moves because a 常時 (engine) coroutine asks it to: nothing in the frame loop
//! advances time by itself, so "23:30, then sleep" is a script-authored chain of absolute
//! writes plus a handful of `217` deltas. Keeping that chain faithful needs three retail
//! quirks to survive:
//!
//! * `217` *adds* minutes and carries at most **once** (TIME_SYSTEM §2.3b). A `while`
//!   loop here would make the runtime stricter than the game and change the answer for
//!   large deltas.
//! * `329` advances the weekday only when the hour is `>= 6` (§3), which is what keeps a
//!   03:30 bedtime on the same day.
//! * `2000008 = 25` means "tomorrow is the weekend"; it is set on Friday and Saturday
//!   nights only, and `217` never clears it (§2.4).
//!
//! A run of `329` on a Saturday at 23:30 lands on 09:30 Sunday, and the 9:00 in that
//! result comes from `317`, not from `329`: `317` then calls `217` twice with
//! `delta = 15` (§4.2). The instruction-count assertion is what notices if any of those
//! links stops firing.

use std::path::PathBuf;
use std::sync::Arc;

use wolf_game::Game;
use wolf_vm::SelfVars;

/// Runtime variable indices (docs/TIME_SYSTEM.md §1.1): the `2_000_000` magic prefix is
/// stripped, so `2000004` is slot 4.
const HOUR: usize = 4;
const MINUTE: usize = 5;
const WEEKDAY: usize = 6;
const WEEKEND: usize = 8;

/// Flat self index of Ev Self group 6 slot 0, where `210` puts a callee's arguments.
const SELF_ARG_600: usize = 600;

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/full".to_owned());
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

/// Rewinds the world to "`hour:minute` on `weekday`, nothing running".
///
/// Every scenario below reuses one `Game` because the retail data is 4,085 files; the
/// reset has to retire leftover coroutines as well as the four variables, or a bedtime
/// run that stops to wait for input would bleed into the next weekday's result.
fn reset_clock(game: &mut Game, hour: i32, minute: i32, weekday: i32) {
    while let Some(id) = game.vm.instances().first().map(|instance| instance.id) {
        game.vm.stop_instance(id);
    }
    game.auto_advance = true;
    game.messages.clear();
    game.choices = None;
    game.screen.clear();
    game.vm.vars.set(HOUR, hour);
    game.vm.vars.set(MINUTE, minute);
    game.vm.vars.set(WEEKDAY, weekday);
    game.vm.vars.set(WEEKEND, 0);
}

/// Runs frames until nothing is in flight (or `limit` is hit). Returns frames stepped.
fn run_until_idle(game: &mut Game, limit: u32) -> u32 {
    let mut frames = 0;
    while frames < limit && !game.vm.instances().is_empty() {
        let _ = game.frame();
        frames += 1;
    }
    frames
}

/// `(hour, minute, weekday)` after stepping `frames`.
fn clock(game: &Game) -> (i32, i32, i32) {
    (
        game.vm.vars.get(HOUR),
        game.vm.vars.get(MINUTE),
        game.vm.vars.get(WEEKDAY),
    )
}

fn picture_text(game: &Game, number: i32) -> Option<String> {
    game.screen.get(number).map(|picture| picture.text.clone())
}

/// One `217` call with its argument, the way the scripts make it: `210 [500217, 1, delta]`
/// lands `delta` in the callee's self slot 600 (§2.1).
fn run_217(game: &mut Game, hour: i32, minute: i32, weekday: i32, delta: i32) {
    reset_clock(game, hour, minute, weekday);
    let program = match game.vm.programs.event(217) {
        Some(program) => Arc::clone(program),
        None => {
            eprintln!("skipping: event 217 missing");
            return;
        }
    };
    let mut bank = SelfVars::new();
    bank.set(SELF_ARG_600, delta);
    let id = game
        .vm
        .start_program_with_self(program, bank)
        .expect("event 217 should start");
    // `start_program_with_self` marks the coroutine [retain_after_finish] so the caller can
    // read the self bank back after it ends, which means an idle check would never see it
    // disappear. Wait for the program counter to run off the end instead.
    let finished = |game: &Game| {
        game.vm
            .instance(id)
            .is_none_or(|instance| instance.pc >= instance.program.len())
    };
    for _ in 0..60 {
        if finished(game) {
            break;
        }
        let _ = game.frame();
    }
    assert!(finished(game), "217 should finish within 60 frames");
}

/// A bedtime at `hour:minute` on `weekday`: `329` writes 7:45, hands over to `317`, which
/// picks 8:00 or 9:00 and then spends a few 15-minute `217` deltas (§3, §4).
fn bedtime(game: &mut Game, hour: i32, minute: i32, weekday: i32) -> u32 {
    reset_clock(game, hour, minute, weekday);
    assert!(game.start_event(329), "event 329 should exist");
    // 4,000 frames is the ceiling that the waiting branches of `wd=0..2` need before they
    // park on an input wait; the clock has already reached its final value by then.
    run_until_idle(game, 4_000)
}

#[test]
fn sleeping_on_a_saturday_night_wakes_up_at_half_past_nine_on_sunday() {
    let Some(mut game) = open_game() else {
        return;
    };
    let instructions_before = game.stats.instructions;
    let warnings_before = game.stats.warnings;

    let frames = bedtime(&mut game, 23, 30, 5);

    let instructions = game.stats.instructions - instructions_before;
    let warnings = game.stats.warnings - warnings_before;
    let (hour, minute, weekday) = clock(&game);
    println!(
        "329 at 23:30 wd=5 -> {hour}:{minute:02} wd={weekday} flag8={} \
         frames {frames} instructions {instructions} warnings {warnings}",
        game.vm.vars.get(WEEKEND)
    );

    // The tail of the chain: 317's 9:00 plus two 15-minute 217 deltas (§4.2).
    assert_eq!(hour, 9, "317's nine o'clock branch should be the one taken");
    assert_eq!(minute, 30, "4.2: 9:00 + 15 + 15");
    assert_eq!(weekday, 6, "Saturday 23:30 crosses into Sunday");
    assert_eq!(
        game.vm.vars.get(WEEKEND),
        0,
        "the Sunday branch of 217 leaves 2000008 alone (§2.4)"
    );
    assert_eq!(warnings, 0, "the bedtime chain produced warnings");
    // A regression anchor: 8,088 instructions over 1,396 frames is what the chain costs
    // when 329, 317 and both 217 deltas fire in that order.
    assert_eq!(
        instructions, 8_088,
        "the instruction count of the 23:30 chain"
    );
    assert_eq!(frames, 1_396, "the frame count of the 23:30 chain");

    // The two HUD pictures 217 drives, read back off the screen (§4.3).
    assert_eq!(
        picture_text(&game, 6200).as_deref(),
        Some(r"\f[24]9:30"),
        "6200 is the clock face"
    );
    assert_eq!(
        picture_text(&game, 6210).as_deref(),
        Some(r"\c[2]\f[18]周日"),
        "wd=6 draws 周日 in red"
    );
    assert_eq!(
        picture_text(&game, 6211).as_deref(),
        Some(r"\f[18]1\f[14]天"),
        "6211 is the day counter"
    );
}

#[test]
fn the_weekday_advances_only_when_bedtime_is_past_six_in_the_morning() {
    let Some(mut game) = open_game() else {
        return;
    };
    // §3's bedtime matrix: the 8:00 branch below Saturday, the 9:00 branch on Saturday and
    // Sunday - decided by the weekday *after* the increment, which is why 木曜 lands on the
    // 8:00 branch even though it wakes up on Friday.
    let expected = [
        (0, 1, 8, 30),
        (1, 2, 8, 30),
        (2, 3, 8, 30),
        (3, 4, 8, 30),
        (4, 5, 9, 30),
        (5, 6, 9, 30),
        (6, 0, 8, 30),
    ];
    for (bed, wake_day, wake_hour, wake_minute) in expected {
        bedtime(&mut game, 23, 30, bed);
        let (hour, minute, weekday) = clock(&game);
        assert_eq!(
            (weekday, hour, minute),
            (wake_day, wake_hour, wake_minute),
            "23:30 on weekday {bed}"
        );
        // 217 runs at the *woken* weekday, so the flag records Friday/Saturday nights (§2.4).
        let weekend = game.vm.vars.get(WEEKEND);
        let want_flag = if wake_day == 4 || wake_day == 5 {
            25
        } else {
            0
        };
        assert_eq!(weekend, want_flag, "2000008 after 23:30 on weekday {bed}");
    }

    // The 03:30 cases are what rule out a `hour <= 6` reading of pc375: an early-morning
    // bedtime stays on the same day, because the day has not been crossed yet.
    bedtime(&mut game, 3, 30, 4);
    assert_eq!(clock(&game), (8, 30, 4), "03:30 on Thursday stays Thursday");
    bedtime(&mut game, 3, 30, 5);
    assert_eq!(
        clock(&game),
        (9, 30, 5),
        "03:30 on Saturday keeps the day but still gets the 9:00 branch"
    );
    assert_eq!(game.stats.warnings, 0, "bedtime runs produced no warnings");
}

#[test]
fn the_clock_adds_minutes_and_carries_at_most_once() {
    let Some(mut game) = open_game() else {
        return;
    };
    // Ordinary deltas: 45 minutes crosses midnight, one minute edges past 23:59.
    let cases = [
        (
            (23, 55, 5),
            45,
            (0, 40, 6),
            "23:55 + 45 crosses into the next day",
        ),
        ((23, 59, 0), 1, (0, 0, 1), "23:59 + 1 is midnight"),
        ((22, 50, 2), 10, (23, 0, 2), "22:50 + 10 is 23:00"),
        ((9, 0, 3), 0, (9, 0, 3), "a zero delta only redraws"),
        // §2.3b: the carry is a single `if`, so an oversized delta leaves an impossible
        // minute value instead of wrapping twice. This is the retail behaviour.
        (
            (12, 0, 3),
            130,
            (13, 70, 3),
            "130 minutes carries exactly once",
        ),
        (
            (12, 0, 3),
            230,
            (13, 170, 3),
            "230 minutes carries exactly once",
        ),
    ];
    for ((hour, minute, weekday), delta, want, note) in cases {
        run_217(&mut game, hour, minute, weekday, delta);
        assert_eq!(
            clock(&game),
            (want.0, want.1, want.2),
            "{note} (delta {delta} from {hour}:{minute:02})"
        );
    }
    assert_eq!(game.stats.warnings, 0, "217 produced no warnings");
}

#[test]
fn the_clock_face_pads_the_minute_and_the_weekday_face_colours_the_weekend() {
    let Some(mut game) = open_game() else {
        return;
    };
    // §2.3c: three shapes, one of which carries a stray trailing newline that comes
    // straight out of the retail data. The hour is never zero-padded.
    let faces = [
        ((9, 0), r"\f[24]9:00"),
        ((9, 5), "\\f[24]9:05\n"),
        ((9, 10), r"\f[24]9:10"),
        ((3, 0), r"\f[24]3:00"),
    ];
    for ((hour, minute), want) in faces {
        run_217(&mut game, hour, minute, 0, 0);
        assert_eq!(
            picture_text(&game, 6200).as_deref(),
            Some(want),
            "the clock face at {hour}:{minute:02}"
        );
    }

    // §2.5: the weekday table, including which weekdays carry an explicit colour and
    // which two of them set 2000008 = 25.
    let weekdays = [
        (0, r"\c[0]\f[18]周一", 0),
        (1, r"\f[18]周二", 0),
        (2, r"\f[18]周三", 0),
        (3, r"\f[18]周四", 0),
        (4, r"\f[18]周五", 25),
        (5, r"\c[1]\f[18]周六", 25),
        (6, r"\c[2]\f[18]周日", 0),
    ];
    for (weekday, want, flag) in weekdays {
        run_217(&mut game, 9, 30, weekday, 0);
        assert_eq!(
            picture_text(&game, 6210).as_deref(),
            Some(want),
            "the weekday face for weekday {weekday}"
        );
        assert_eq!(
            game.vm.vars.get(WEEKEND),
            flag,
            "2000008 for weekday {weekday}"
        );
    }
    assert_eq!(
        game.stats.warnings, 0,
        "the clock faces produced no warnings"
    );
}
