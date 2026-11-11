//! M2 HUD common events: the on-demand panels the game repaints over the bedroom.
//!
//! The loaded bedroom HUD is drawn once when SaveData01 restores; these four common
//! events are the game's own repaint routines, invoked by hand from that state. The
//! measured shape of each, taken with WOLF_DATA_ROOT=work/Data and SaveData01 loaded
//! through the title menu's second option (the same path as m1_title_load), is:
//!
//! | event | title (JP) | paints on an empty screen |
//! |---|---|---|
//! | 242 | status display | 5 text pictures: #220 name, #230 action label, #240 energy, #250 money label, #251 amount |
//! | 243 | clock display | 2 text pictures: #200 HH:MM time, #210 weekday |
//! | 244 | action-point change | 1 text picture: #110 a signed "+N" delta |
//! | 256 | daytime menu | no pictures of its own; the prompt message then an idle line, and it winds the clock forward |
//!
//! Each test clears game.screen immediately before start_event, so the pictures the
//! event paints are attributed to it rather than to the HUD the save already restored
//! (the loaded HUD already holds slots 200/220/230/240/250/251/320/2300+). The two
//! negative icon slots (-5/-4) are background layers and are ignored.
//!
//! Data-missing runs skip, matching the rest of the suite.

use std::collections::BTreeMap;
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
        // Consume the escape command name (one or more ASCII alphanumerics), then an
        // optional [...] argument block.
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

fn is_hh_mm(text: &str) -> bool {
    let Some((h, m)) = text.split_once(':') else {
        return false;
    };
    !h.is_empty()
        && h.len() <= 2
        && m.len() == 2
        && h.chars().all(|c| c.is_ascii_digit())
        && m.chars().all(|c| c.is_ascii_digit())
}

fn is_signed_int(text: &str) -> bool {
    let mut chars = text.chars();
    match chars.next() {
        Some('+') | Some('-') => {}
        _ => return false,
    }
    let rest: String = chars.collect();
    !rest.is_empty() && rest.chars().all(|c| c.is_ascii_digit())
}

/// Boots the title map, takes the load path (SaveData01), and runs long enough to land
/// in the bedroom HUD. Skips when the data or the save is absent.
fn open_loaded_bedroom() -> Option<Game> {
    let mut game = match Game::new(data_root()) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: {err}");
            return None;
        }
    };
    game.auto_advance = true;
    game.set_choice_cursor(1); // menu2 = load
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    if let Err(err) = game.boot() {
        eprintln!("skipping: {err}");
        return None;
    }
    for _ in 0..1600 {
        let grid = game.vm.instances().iter().any(|inst| inst.event == 131);
        if grid {
            game.key_bits = wolf_game::key::OK;
        } else {
            game.key_bits = 0;
        }
        game.frame();
    }
    game.key_bits = 0;
    // If the save did not restore, the bedroom HUD's action-point readout is absent; skip.
    let has_hud = game
        .screen
        .iter()
        .any(|picture| picture.number == 230 && visible(&picture.text).contains("行动力"));
    if !has_hud {
        eprintln!("skipping: SaveData01 did not load into the bedroom HUD");
        return None;
    }
    Some(game)
}

/// What one common event did on an emptied screen.
struct EventRun {
    /// Positive picture slots the event painted, mapped to their raw text (last seen).
    pictures: BTreeMap<i32, String>,
    /// Every message text seen across the frames, in first-seen order.
    messages: Vec<String>,
    /// Whether a choice prompt was still pending on the final frame.
    final_choice: bool,
    /// Interpreter warnings logged during the run.
    warnings: u64,
}

fn run_event(game: &mut Game, id: u32, frames: u32) -> EventRun {
    game.screen.clear();
    assert!(game.start_event(id), "common event {id} exists");
    let mut run = EventRun {
        pictures: BTreeMap::new(),
        messages: Vec::new(),
        final_choice: false,
        warnings: 0,
    };
    for _ in 0..frames {
        game.frame();
        for message in &game.messages {
            if !run.messages.iter().any(|seen| seen == &message.text) {
                run.messages.push(message.text.clone());
            }
        }
        for picture in game.screen.iter() {
            if picture.number > 0 {
                run.pictures.insert(picture.number, picture.text.clone());
            }
        }
    }
    run.final_choice = game.choices.is_some();
    run.warnings = game.stats.warnings;
    run
}

#[test]
fn ce242_status_panel_paints_the_five_hud_readouts() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let run = run_event(&mut game, 242, 5);

    let slots: Vec<i32> = run.pictures.keys().copied().collect();
    assert_eq!(
        slots,
        vec![220, 230, 240, 250, 251],
        "CE242 paints exactly the five status readouts (plus background icons)"
    );
    let text = |slot: i32| visible(run.pictures.get(&slot).map(String::as_str).unwrap_or(""));
    assert!(
        text(230).contains("行动力"),
        "the status panel labels action points: {:?}",
        text(230)
    );
    assert!(
        text(240).contains("精力"),
        "the status panel labels energy: {:?}",
        text(240)
    );
    assert!(
        text(250).contains("持有金钱"),
        "the status panel labels money: {:?}",
        text(250)
    );
    assert!(
        text(251).contains('円'),
        "the status panel shows the money amount: {:?}",
        text(251)
    );
    assert!(
        !text(220).is_empty(),
        "the status panel paints the character name line"
    );
    assert!(run.messages.is_empty(), "the status panel shows no message");
    assert_eq!(run.warnings, 0, "CE242 runs warning-free");
}

#[test]
fn ce243_time_display_paints_the_clock_and_weekday() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let run = run_event(&mut game, 243, 5);

    let slots: Vec<i32> = run.pictures.keys().copied().collect();
    assert_eq!(
        slots,
        vec![200, 210],
        "CE243 paints exactly the clock (#200) and weekday (#210)"
    );
    let time = visible(run.pictures.get(&200).map(String::as_str).unwrap_or(""));
    let day = visible(run.pictures.get(&210).map(String::as_str).unwrap_or(""));
    assert!(is_hh_mm(&time), "the clock reads HH:MM, got {time:?}");
    assert!(
        day.contains('周'),
        "the weekday reads like weekday N, got {day:?}"
    );
    assert!(
        run.messages.is_empty(),
        "the clock display shows no message"
    );
    assert_eq!(run.warnings, 0, "CE243 runs warning-free");
}

#[test]
fn ce244_action_point_change_paints_the_delta() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    // CE244 takes the delta in its self slot 0. The durable bank now keeps the
    // last real caller's argument (15 on this save), and 55 + 15 would clamp to
    // the 60 maximum instead of painting a delta. Seed a -5 change so the
    // non-clamping branch runs deterministically; the live caller still goes
    // through the same seeded bank.
    game.vm
        .vars
        .common_self
        .entry(244)
        .or_insert_with(Default::default)
        .set(0, -5);
    let run = run_event(&mut game, 244, 8);

    let slots: Vec<i32> = run.pictures.keys().copied().collect();
    assert_eq!(
        slots,
        vec![110],
        "CE244 paints exactly one picture, the action-point delta #110"
    );
    let delta = visible(run.pictures.get(&110).map(String::as_str).unwrap_or(""));
    assert!(
        is_signed_int(&delta),
        "the action-point change is a signed integer, got {delta:?}"
    );
    assert_eq!(delta, "-5", "the painted delta is the seeded change");
    assert!(
        run.messages.is_empty(),
        "the action-point change shows no message"
    );
    assert_eq!(run.warnings, 0, "CE244 runs warning-free");
}

#[test]
fn ce256_daytime_menu_asks_its_prompt_and_winds_the_clock() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let before_time = game
        .screen
        .get(200)
        .map(|picture| visible(&picture.text))
        .unwrap_or_default();

    let run = run_event(&mut game, 256, 50);

    assert!(
        run.messages
            .iter()
            .any(|message| visible(message).contains("那么，该怎么做呢。")),
        "the daytime menu asks its prompt: {:?}",
        run.messages
    );
    assert!(
        !run.final_choice,
        "the prompt is resolved within the run, leaving no pending choice"
    );
    let after_time = run
        .pictures
        .get(&200)
        .map(|text| visible(text))
        .unwrap_or_default();
    assert_ne!(
        before_time, after_time,
        "the daytime menu winds the clock forward (before {before_time:?}, after {after_time:?})"
    );
    assert_eq!(run.warnings, 0, "CE256 runs warning-free");
}
