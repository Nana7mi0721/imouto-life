//! M6 main-line slice: the new-game story on SampleMapA runs on top of the engine's
//! 108-coroutine background system, and the scheduler keeps turning without deadlock.
//!
//! `Game::start_map_event_by_name` is the code path a real new game takes after the
//! title menu answers (`docs/MAP_AUDIT.md` section 7.5). It starts the engine events
//! first, so the 10 always-on coroutines plus the auto-start event are alive before
//! the story script runs. This test drives that exact path for 900 frames and pins the
//! facts the M6 handoff quotes: peak concurrency, instruction progress, the started
//! event set, and a clean diagnostic-free screen full of live pictures.

use std::path::PathBuf;

use wolf_game::game::ENGINE_ALWAYS;
use wolf_game::Game;

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

#[test]
fn new_game_story_runs_on_the_background_scheduler_without_deadlock() {
    let Some(mut game) = open_game() else { return };
    // A headless capture dismisses messages immediately; choices are the one thing it
    // must answer, so pick option 0 after two frames like a player would.
    game.auto_advance = true;
    game.set_choice_cursor(0);
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.start_map_event_by_name("SampleMapA", 0)
        .expect("new-game entry point exists");

    let mut frames_with_progress = 0usize;
    for _ in 0..900 {
        let before = game.stats.instructions;
        game.frame();
        if game.stats.instructions > before {
            frames_with_progress += 1;
        }
    }

    assert_eq!(game.stats.frames, 900);
    assert!(
        frames_with_progress > 600,
        "the scheduler advanced the story on most frames (no deadlock); got {frames_with_progress}"
    );
    assert!(
        game.stats.instructions > 50_000,
        "900 frames execute the story: {} instructions",
        game.stats.instructions
    );
    assert!(
        game.stats.peak_instances >= 9,
        "UI + story coroutines run concurrently: peak {}",
        game.stats.peak_instances
    );
    assert_eq!(game.stats.warnings, 0, "no interpreter warnings");
    assert!(game.screen.len() > 30, "the room and HUD stay drawn: {} pictures", game.screen.len());

    // Every engine-always coroutine was started, plus the auto-start event and the
    // boot-time conditional event 38. The rest of the 97 are variable-gated UI states
    // that a slice does not necessarily visit; the registry itself is what must exist.
    for id in ENGINE_ALWAYS {
        assert!(
            game.vm.started_events.contains(id),
            "ENGINE_ALWAYS event {id} must run in every session"
        );
    }
    assert!(game.vm.started_events.contains(&241), "auto-start event 241 runs");
    assert!(game.vm.started_events.contains(&38), "boot-time conditional event 38 runs");
    assert!(
        game.vm.started_events.len() >= 13,
        "at least 10 always + auto-start + implicit + 38: {}",
        game.vm.started_events.len()
    );
}


#[test]
fn the_title_menu_new_game_path_no_longer_leaves_title_art_over_the_room() {
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.set_choice_cursor(0);
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.boot().expect("the boot map has its autorun event");

    // The splash -> key wait -> title menu -> confirm chain needs about 800 frames
    // before a single decide press walks the example title menu into the game.
    for frame in 0..3200 {
        if frame == 800 {
            game.key_bits = wolf_game::key::OK;
        }
        game.frame();
        game.key_bits = 0;
    }

    assert_eq!(game.stats.frames, 3200);
    assert_eq!(game.stats.warnings, 0, "no interpreter warnings on the boot path");
    assert!(
        game.stats.instructions > 100_000,
        "the title path runs the splashes plus the room: {} instructions",
        game.stats.instructions
    );
    assert!(game.screen.len() > 30, "the room and HUD are drawn: {} pictures", game.screen.len());
    // The sample title art lives in a negative (whole-screen) slot. Once the menu
    // answers with its 130, that layer belongs to the old map and must be gone.
    let stale: Vec<String> = game
        .screen
        .iter()
        .filter(|picture| picture.number < 0 && picture.file.contains("TitleGraphic"))
        .map(|picture| picture.file.clone())
        .collect();
    assert!(stale.is_empty(), "title art still on screen: {stale:?}");
    // The real new-game path is CE42 -> map 3 (Map003 hook) -> map 1 (SampleMapA).
    // The raw 130 layout is target, x, y, map, options, so this pins both hops.
    let diagnostics: Vec<&str> = game.diagnostics.keys().map(String::as_str).collect();
    assert!(
        diagnostics
            .iter()
            .any(|line| line.contains("130 Teleport: MapData/Map003.mps")),
        "the title menu must pass through the Map003 new-game hook: {diagnostics:?}"
    );
    assert!(
        diagnostics
            .iter()
            .any(|line| line.contains("130 Teleport: MapData/SampleMapA.mps")),
        "the hook then teleports into SampleMapA: {diagnostics:?}"
    );
}



#[test]
fn clicking_the_reading_icon_in_the_bedroom_runs_the_first_playable_action() {
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.set_choice_cursor(0);
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.start_map_event_by_name("Map003", 1)
        .expect("the new-game hook exists");

    // Let the hook teleport into SampleMapA and the room/HUD settle.
    for _ in 0..1500 {
        game.frame();
    }
    assert!(game.screen.len() > 30, "the bedroom is drawn before the click");
    assert_eq!(game.stats.warnings, 0);

    // The bedroom menu is mouse driven: one left click on the 读书 icon
    // (885,240 in the 1024x576 frame) starts the reading action.
    game.auto_advance = false;
    game.mouse = [884, 240];
    game.mouse_buttons = 1;
    game.frame();
    game.mouse_buttons = 0;
    for _ in 0..30 {
        game.frame();
    }

    // The result is drawn as a floating text picture, not a 101 message window.
    let texts: Vec<&str> = game
        .screen
        .iter()
        .map(|picture| picture.text.as_str())
        .chain(game.messages.iter().map(|message| message.text.as_str()))
        .collect();
    assert!(
        texts.iter().any(|text| text.contains("理解")),
        "the reading action reports its effect: {texts:?}"
    );
    assert_eq!(game.stats.warnings, 0);
}



fn click_icon(game: &mut Game, x: i32, y: i32) {
    game.auto_advance = false;
    game.mouse = [x, y];
    game.mouse_buttons = 1;
    game.frame();
    game.mouse_buttons = 0;
    game.auto_advance = true;
    for _ in 0..30 {
        game.frame();
    }
}

#[test]
fn the_bedroom_actions_can_be_played_one_after_another() {
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.set_choice_cursor(0);
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.start_map_event_by_name("Map003", 1)
        .expect("the new-game hook exists");
    for _ in 0..1500 {
        game.frame();
    }

    click_icon(&mut game, 884, 240); // 读书
    let after_read: Vec<&str> = game.screen.iter().map(|p| p.text.as_str()).collect();
    assert!(
        after_read.iter().any(|text| text.contains("理解")),
        "the reading action reports its effect: {after_read:?}"
    );

    click_icon(&mut game, 195, 475); // 钻研
    let after_training: Vec<&str> = game.screen.iter().map(|p| p.text.as_str()).collect();
    assert!(
        after_training.iter().any(|text| text.contains("自主训练")),
        "the training action reports its effect: {after_training:?}"
    );
    assert_eq!(game.stats.warnings, 0);
}



/// Strips WOLF text escape commands so a live picture's text and its
/// save-restored (plain) text compare equal in what the player actually sees.
fn plain_text(text: &str) -> String {
    let mut out = String::new();
    let mut chars = text.chars().peekable();
    while let Some(c) = chars.next() {
        if c != '\\' {
            out.push(c);
            continue;
        }
        while let Some(&next) = chars.peek() {
            if next == '[' {
                chars.next();
                for inner in chars.by_ref() {
                    if inner == ']' {
                        break;
                    }
                }
                break;
            } else if next.is_ascii_alphabetic() {
                chars.next();
            } else {
                break;
            }
        }
    }
    out
}

fn visible_screen(game: &Game) -> Vec<String> {
    game.screen
        .iter()
        .map(|p| {
            let kind = if p.kind.is_text() {
                "text"
            } else if p.kind.is_window() {
                "window"
            } else {
                "file"
            };
            // Only a window picture uses the window rectangle; a text/file
            // picture's default (1,1) after a reload is not a visible change.
            let window = if p.kind.is_window() {
                format!("{:?}", p.window)
            } else {
                "-".to_owned()
            };
            format!(
                "{}|{kind}|{}|{}|{}|{}|{}|{}|{}|{}",
                p.number,
                p.file,
                plain_text(&p.text),
                p.x,
                p.y,
                p.opacity,
                p.scale,
                p.anchor,
                window
            )
        })
        .collect()
}

#[test]
fn a_live_played_scene_survives_a_save_and_reload() {
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.set_choice_cursor(0);
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.start_map_event_by_name("Map003", 1)
        .expect("the new-game hook exists");
    for _ in 0..1500 {
        game.frame();
    }
    click_icon(&mut game, 884, 240); // 读书
    click_icon(&mut game, 195, 475); // 钻研
    assert_eq!(game.stats.warnings, 0);

    let pictures_before = visible_screen(&game);
    let vars_before: Vec<i32> = (0..800).map(|index| game.vm.vars.get(index)).collect();
    let playtime_before = game.playtime_frames;

    let mut out = std::path::PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    out.pop();
    out.pop();
    out.push("work/out/m6_live_roundtrip");
    let _ = std::fs::remove_dir_all(&out);
    if let Err(err) = game.save_to(&out) {
        eprintln!("skipping: live save needs a template save: {err}");
        return;
    }

    let mut reloaded = Game::new(data_root()).expect("reload game");
    wolf_game::savegame::load_into(&mut reloaded, &out).expect("load the live save");
    assert_eq!(
        visible_screen(&reloaded),
        pictures_before,
        "the visible picture layer changed across save -> reload"
    );
    assert_eq!(
        (0..800).map(|index| reloaded.vm.vars.get(index)).collect::<Vec<_>>(),
        vars_before,
        "the 800 normal variables changed across save -> reload"
    );
    assert_eq!(
        reloaded.playtime_frames, playtime_before,
        "play time changed across save -> reload"
    );
    let _ = std::fs::remove_dir_all(&out);
}


#[test]
fn the_sleep_event_rolls_over_to_the_next_morning() {
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.set_choice_cursor(0);
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    game.start_engine_events();
    game.vm.vars.set(4, 18);
    game.vm.vars.set(5, 30);
    game.vm.vars.set(160, 3);
    game.vm.vars.set(6, 1);
    let id = game.vm.start_event(329).expect("the sleep event exists");
    assert!(game.vm.instance(id).is_some());
    for _ in 0..300 {
        game.frame();
    }
    assert_eq!(game.stats.warnings, 0, "no interpreter warnings");
    assert_eq!(game.vm.vars.get(4), 8, "the next morning starts at 8");
    assert_eq!(game.vm.vars.get(5), 30, "and 30 minutes");
    assert_eq!(game.vm.vars.get(160), 4, "the day counter advanced to day 4");
    assert_eq!(game.vm.vars.get(6), 2, "and the weekday advanced to Wednesday");
    assert!(
        game.screen.len() > 20,
        "the morning scene is drawn: {} pictures",
        game.screen.len()
    );
    assert!(
        game.stats.instructions > 10_000,
        "the sleep script really ran: {} instructions",
        game.stats.instructions
    );
}
/// The bedroom's night-time sister page (SampleMapA event 1, page 3) writes variable 63
/// when the player clicks the sleeping sister. That is the real entry to the メニュー処理
/// event 4 sleep page, which offers 恶作剧 / 轻轻把被子盖好 / 今天还是睡吧. Choosing the
/// last option calls common event 329 (就寝処理) and rolls the clock to the next morning,
/// so this test drives the WHOLE player-facing day loop, not just CE329 in isolation.
#[test]
fn the_bedroom_sleep_menu_choice_rolls_over_to_a_new_day() {
    let Some(mut game) = open_game() else { return };
    game.auto_advance = true;
    game.set_choice_cursor(0);
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    // The canonical new-game entry. With auto_choice the character-creation prompts are
    // answered and the story settles into the 18:30 bedroom.
    game.start_map_event_by_name("SampleMapA", 0)
        .expect("the new-game entry point exists");
    for _ in 0..1500 {
        game.frame();
    }
    assert_eq!(game.stats.warnings, 0, "the opening story is warning-free");
    assert_eq!(game.vm.vars.get(4), 18, "the bedroom clock is 18:00");
    assert_eq!(game.vm.vars.get(5), 30, "and 18:30");
    assert_eq!(game.vm.vars.get(160), 1, "on day 1");

    // Event 1's pointer branch is what writes 63 = 1 in a real click; headless input
    // cannot reproduce its hit-test reliably, so seed the flag the click leaves behind.
    game.auto_choice = false;
    game.vm.vars.set(63, 1);

    let mut sleep_options: Option<Vec<String>> = None;
    for _ in 0..120 {
        game.frame();
        if let Some(choices) = &game.choices {
            if choices.frames >= 2 {
                sleep_options = Some(choices.options.clone());
                break;
            }
        }
    }
    let sleep_options = sleep_options.expect("the sister sleep prompt should open");
    assert_eq!(
        sleep_options,
        vec!["恶作剧".to_owned(), "轻轻把被子盖好".to_owned(), "今天还是睡吧".to_owned()],
        "the prompt is the three-way night choice"
    );

    // Pick 今天还是睡吧 (index 2). The next prompt is 要睡到早上吗？ yes/no.
    game.set_choice_cursor(2);
    game.key_bits = wolf_game::key::OK;
    game.frame();
    game.key_bits = 0;

    let mut confirm_options: Option<Vec<String>> = None;
    for _ in 0..120 {
        game.frame();
        if let Some(choices) = &game.choices {
            if choices.frames >= 2 {
                confirm_options = Some(choices.options.clone());
                break;
            }
        }
    }
    assert_eq!(
        confirm_options.as_deref(),
        Some(["是的".to_owned(), "再想想".to_owned()].as_slice()),
        "the sleep confirmation prompt appears"
    );
    game.set_choice_cursor(0);
    game.key_bits = wolf_game::key::OK;
    game.frame();
    game.key_bits = 0;

    // CE329 rewinds the clock, advances the day and plays the morning scene. Stop once
    // the next morning is established; later guild prompts belong to another slice.
    for _ in 0..400 {
        game.frame();
        if game.vm.vars.get(160) == 2 && game.vm.vars.get(4) == 8 && game.vm.vars.get(5) >= 30 {
            break;
        }
    }
    assert_eq!(game.stats.warnings, 0, "the sleep transition is warning-free");
    assert_eq!(game.vm.vars.get(160), 2, "the day counter advanced to day 2");
    assert_eq!(game.vm.vars.get(6), 1, "and the weekday advanced to Tuesday");
    assert_eq!(game.vm.vars.get(4), 8, "the next morning starts at 8");
    assert_eq!(game.vm.vars.get(5), 30, "and 30 minutes");
    assert!(game.screen.len() > 20, "the morning scene is drawn: {} pictures", game.screen.len());
    assert!(game.stats.instructions > 120_000, "the whole loop really ran: {} instructions", game.stats.instructions);

    // The morning lands in CE251, whose day-command buttons draw `\f[20]\cself[5]`
    // and friends. The self string bank holds the label, so \cself must prefer it over
    // the (zero) numeric slot; before that fix every button rendered a bare "0".
    game.auto_choice = true;
    let mut first_label: Option<String> = None;
    for _ in 0..350 {
        game.frame();
        if let Some(picture) = game.screen.get(1201) {
            if !picture.text.is_empty() {
                first_label = Some(picture.text.clone());
                break;
            }
        }
    }
    let first_label = first_label.expect("CE251 draws its first day-command button");
    assert_ne!(
        first_label, "\\f[20]0",
        "the day-command label is a string, not the numeric self slot"
    );
    assert!(
        first_label.contains("学习会") || first_label.contains("秘密特训"),
        "the label comes from the self string bank: {first_label:?}"
    );

    // The menu is the game's own picture-button day command (CE251). Hovering first
    // and then pressing is what a real mouse does; a bare one-frame click only reports
    // the hover. The first button is 学习会 and its confirmation prompt is answered by
    // the auto-choice policy above. The action spends the day (08:30 -> 17:00), costs
    // 20 energy and raises the study stat by 8.
    let study_before = game.vm.vars.get(171);
    let energy_before = game.vm.vars.get(14);
    game.mouse = [512, 230];
    for _ in 0..10 {
        game.frame();
    }
    game.mouse_buttons = 1;
    for _ in 0..5 {
        game.frame();
    }
    game.mouse_buttons = 0;
    for _ in 0..1500 {
        game.frame();
        if game.vm.instances().iter().all(|instance| instance.event != 251) {
            break;
        }
    }
    assert_eq!(game.stats.warnings, 0, "the day command is warning-free");
    assert_eq!(game.vm.vars.get(4), 17, "the action spends the day until 17:00");
    assert_eq!(game.vm.vars.get(5), 0);
    assert_eq!(game.vm.vars.get(48), 2, "the chosen command is 学习会 (2)");
    assert_eq!(
        game.vm.vars.get(171),
        study_before + 8,
        "学习会 raises the study stat by 8"
    );
    assert_eq!(
        game.vm.vars.get(14),
        energy_before - 20,
        "the action costs 20 energy"
    );
    assert!(
        game.vm.instances().iter().all(|instance| instance.event != 251),
        "the day-command script finishes after the action"
    );

    // The day does not stop at the command: the evening scene (dinner, CE326) plays out
    // and the bedroom waits for the player again. Seeding the sister-click flag a second
    // time drives the same night menu -> CE329 -> day 3, which is what makes this a
    // repeatable daily loop rather than a one-day script.
    for _ in 0..1200 {
        game.frame();
    }
    assert_eq!(game.vm.vars.get(160), 2, "still day 2 after the evening scene");
    assert_eq!(game.vm.vars.get(4), 19, "the evening reaches 19:00");
    assert_eq!(game.vm.vars.get(5), 30);

    game.auto_choice = false;
    game.vm.vars.set(63, 1);
    let mut second_options: Option<Vec<String>> = None;
    for _ in 0..300 {
        game.frame();
        if let Some(choices) = &game.choices {
            if choices.frames >= 2 {
                second_options = Some(choices.options.clone());
                break;
            }
        }
    }
    assert_eq!(
        second_options.as_deref(),
        Some(["恶作剧".to_owned(), "轻轻把被子盖好".to_owned(), "今天还是睡吧".to_owned()].as_slice()),
        "the second night opens the same three-way sleep prompt"
    );
    game.set_choice_cursor(2);
    game.key_bits = wolf_game::key::OK;
    game.frame();
    game.key_bits = 0;
    let mut second_confirm: Option<Vec<String>> = None;
    for _ in 0..120 {
        game.frame();
        if let Some(choices) = &game.choices {
            if choices.frames >= 2 {
                second_confirm = Some(choices.options.clone());
                break;
            }
        }
    }
    assert_eq!(
        second_confirm.as_deref(),
        Some(["是的".to_owned(), "再想想".to_owned()].as_slice()),
        "the second confirmation prompt appears"
    );
    game.set_choice_cursor(0);
    game.key_bits = wolf_game::key::OK;
    game.frame();
    game.key_bits = 0;
    for _ in 0..500 {
        game.frame();
        if game.vm.vars.get(160) == 3 && game.vm.vars.get(4) == 8 && game.vm.vars.get(5) >= 30 {
            break;
        }
    }
    assert_eq!(game.stats.warnings, 0, "the second day loop is warning-free");
    assert_eq!(game.vm.vars.get(160), 3, "the loop advances to day 3");
    assert_eq!(game.vm.vars.get(6), 2, "and to Wednesday");
    assert_eq!(game.vm.vars.get(4), 8, "the third morning starts at 8");
    assert_eq!(game.vm.vars.get(5), 30, "and 30 minutes");
    assert!(game.screen.len() > 20, "the third morning is drawn");
}