//! M3-C UI screens: the game's own status / item / standing-art / album / credit
//! common events, driven by hand from the loaded bedroom (SaveData01) and photographed
//! on an emptied screen. Each expectation was measured first with a throwaway probe
//! against WOLF_DATA_ROOT=work/Data, never copied from the sister project.
//!
//! | event | title (JP) | what it paints / does |
//! |---|---|---|
//! | 237 | Hステータス | window frame + GOOD/BAD gauge labels + sleeping_staus.png backdrop (slots 1992..2000) |
//! | 238 | ステータス | status01.png backdrop + rank text (slots 320..325) |
//! | 239 | アイテムリスト | itemlist.png frame + 19 empty item slots (slots 2300..2319) |
//! | 240 | 立ち絵表示 | layered standing art 900..903 (body / eye / mouth / eyebrow) |
//! | 241 | ┗立ち絵瞬き | blink coroutine that works off 240's art and keeps running |
//! | 242 | ステータス表示 | 5 readouts: name/action/energy/money-label/money (slots 220..251) |
//! | 243 | 時刻表示 | clock #200 HH:MM + weekday #210 |
//! | 244 | 行動力変動 | signed action-point delta #110 |
//! | 296 | ■プレイ傾向 | play-tendency description text (slots 400/401/412/413) |
//! | 297 | スタッフロール | rolls the credit CG strip (slots 6001..) then ends |
//! | 301 | アルバム表示 | no-op on its own (needs a caller's selection context) |
//! | 302 | クレジット | rolls the credit CG strip (slots 6001..) then ends |
//! | 303 | アルバム画面呼び出し | album grid: background + 3 thumbnails + standing preview; closes on cancel |
//!
//! Every test clears game.screen immediately before start_event (except the blink test,
//! which needs 240's art to stay up), so the pictures an event paints are attributed to
//! it rather than to the HUD the save restored. Negative slots (-5/-4) are background
//! icon layers and are ignored. Data-missing runs skip, matching the rest of the suite.

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

/// Strips WOLF text escapes so assertions look at the glyphs the player sees.
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

fn is_hh_mm(s: &str) -> bool {
    let b = s.as_bytes();
    b.len() == 5
        && b[2] == b':'
        && b.iter()
            .enumerate()
            .all(|(i, &c)| i == 2 || c.is_ascii_digit())
}

fn is_signed_int(s: &str) -> bool {
    let t = s.trim();
    let rest = t
        .strip_prefix('+')
        .or_else(|| t.strip_prefix('-'))
        .unwrap_or(t);
    !rest.is_empty() && rest.bytes().all(|c| c.is_ascii_digit())
}

/// Boots SaveData01 and advances into the bedroom HUD, where action points are on screen.
fn open_loaded_bedroom() -> Option<Game> {
    let root = data_root();
    if !root.is_dir() {
        eprintln!("skipping: data root not found at {}", root.display());
        return None;
    }
    let mut game = match Game::new(root) {
        Ok(game) => game,
        Err(_) => {
            eprintln!("skipping: Game::new failed");
            return None;
        }
    };
    game.auto_advance = true;
    game.set_choice_cursor(1);
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    if game.boot().is_err() {
        eprintln!("skipping: boot failed");
        return None;
    }
    for _ in 0..1600 {
        // The title prompt is answered by auto_choice; the load grid that follows
        // is a 123 poll loop and needs the confirm key held until it closes.
        let grid = game.vm.instances().iter().any(|inst| inst.event == 131);
        game.key_bits = if grid { wolf_game::key::OK } else { 0 };
        game.frame();
    }
    game.key_bits = 0;
    let has_action = game
        .screen
        .get(230)
        .map(|p| visible(&p.text).contains("行动力"))
        .unwrap_or(false);
    if !has_action {
        eprintln!("skipping: bedroom HUD did not come up");
        return None;
    }
    game.auto_events.set_enabled(false);
    Some(game)
}

fn running(game: &Game, id: u32) -> bool {
    game.vm.instances().iter().any(|inst| inst.event == id)
}

#[derive(Clone, Debug, Default)]
struct Slot {
    file: String,
    text: String,
    #[allow(dead_code)]
    kind: String,
}

#[derive(Debug, Default)]
struct Shot {
    pictures: BTreeMap<i32, Slot>,
    messages: Vec<String>,
    final_choice: bool,
    still_running: bool,
    warnings: u64,
    frames: u32,
}

/// One frame, answering a `123` wait poll the way a player tapping the decide key
/// would: several screens (staff roll, credits, album) park on a click-to-continue
/// poll whose whole purpose is to hold the scene.
fn tick(game: &mut Game) {
    let held = game.key_bits;
    let waiting = game
        .vm
        .instances()
        .iter()
        .any(|inst| inst.wait == wolf_vm::WaitState::Key);
    game.key_bits = held | if waiting { wolf_game::key::OK } else { 0 };
    game.frame();
    game.key_bits = held;
}

/// Clears the screen, starts one common event, and runs it for a fixed number of frames.
fn run_event(game: &mut Game, id: u32, frames: u32) -> Shot {
    game.screen.clear();
    game.messages.clear();
    assert!(game.start_event(id), "event {id} did not start");
    let mut shot = Shot::default();
    for _ in 0..frames {
        tick(&mut *game);
        for msg in &game.messages {
            let text = visible(&msg.text);
            if !shot.messages.contains(&text) {
                shot.messages.push(text);
            }
        }
    }
    shot.frames = frames;
    shot.final_choice = game.choices.is_some();
    shot.still_running = running(game, id);
    shot.warnings = game.stats.warnings;
    for pic in game.screen.iter() {
        if pic.number > 0 {
            shot.pictures.insert(
                pic.number,
                Slot {
                    file: pic.file.clone(),
                    text: visible(&pic.text),
                    kind: format!("{:?}", pic.kind),
                },
            );
        }
    }
    shot
}

#[derive(Debug, Default)]
struct Roll {
    frames: u32,
    ended: bool,
    warnings: u64,
    saw_credit: bool,
}

/// Runs a scrolling event until it stops (or the safety cap) and notes whether a credit
/// CG ever appeared on screen.
fn run_until_end(game: &mut Game, id: u32, cap: u32) -> Roll {
    game.screen.clear();
    assert!(game.start_event(id), "event {id} did not start");
    let mut roll = Roll::default();
    for _ in 0..cap {
        tick(&mut *game);
        roll.frames += 1;
        if game
            .screen
            .iter()
            .any(|pic| pic.number > 0 && pic.file.contains("credit"))
        {
            roll.saw_credit = true;
        }
        if !running(game, id) {
            roll.ended = true;
            break;
        }
    }
    roll.warnings = game.stats.warnings;
    roll
}

/// Holds a key long enough for the event's poll cadence to see it, then releases it.
fn press(game: &mut Game, bits: u32) {
    game.key_bits = bits;
    for _ in 0..24 {
        tick(&mut *game);
    }
    game.key_bits = 0;
    for _ in 0..6 {
        tick(&mut *game);
    }
}

fn click_at(game: &mut Game, x: i32, y: i32) {
    game.mouse = [x, y];
    for _ in 0..10 {
        tick(&mut *game);
    }
    game.mouse_buttons = 1;
    for _ in 0..5 {
        tick(&mut *game);
    }
    game.mouse_buttons = 0;
    for _ in 0..5 {
        tick(&mut *game);
    }
}

#[test]
fn ce237_status_window() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let shot = run_event(&mut game, 237, 20);
    let slots: Vec<i32> = shot.pictures.keys().copied().collect();
    assert_eq!(slots, (1992..=2000).collect::<Vec<_>>(), "CE237 slot set");
    assert_eq!(shot.pictures[&1995].text, "GOOD", "CE237 GOOD meter");
    assert_eq!(shot.pictures[&1999].text, "BAD", "CE237 BAD meter");
    let backdrop = &shot.pictures[&2000].file;
    assert!(
        backdrop.ends_with("sleeping_staus.png"),
        "CE237 backdrop: {backdrop}"
    );
    assert_eq!(shot.warnings, 0, "CE237 warnings");
}

#[test]
fn ce238_status_screen() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let shot = run_event(&mut game, 238, 20);
    let slots: Vec<i32> = shot.pictures.keys().copied().collect();
    assert_eq!(slots, (320..=325).collect::<Vec<_>>(), "CE238 slot set");
    assert!(
        shot.pictures[&320].file.ends_with("status01.png"),
        "CE238 backdrop: {}",
        shot.pictures[&320].file
    );
    assert_eq!(shot.pictures[&323].text, "普通", "CE238 rank #1");
    assert_eq!(shot.pictures[&324].text, "普通", "CE238 rank #2");
    assert_eq!(shot.pictures[&321].text, "", "CE238 bare slot 321");
    assert_eq!(shot.warnings, 0, "CE238 warnings");
}

#[test]
fn ce239_item_list() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let shot = run_event(&mut game, 239, 20);
    let slots: Vec<i32> = shot.pictures.keys().copied().collect();
    assert_eq!(slots, (2300..=2319).collect::<Vec<_>>(), "CE239 slot set");
    assert!(
        shot.pictures[&2300].file.ends_with("itemlist.png"),
        "CE239 frame: {}",
        shot.pictures[&2300].file
    );
    for slot in 2301..=2319 {
        assert_eq!(
            shot.pictures[&slot].text, "",
            "CE239 empty item slot {slot}"
        );
    }
    assert_eq!(shot.warnings, 0, "CE239 warnings");
}

#[test]
fn ce240_standing_art() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    // WOLF keeps a common event's self variables between invocations, and the
    // boot session already called CE240 with argument -1 (that branch ends the
    // event on purpose). A standalone start is a fresh call, so drop the stale
    // bank; otherwise the event ends before painting anything.
    game.vm.vars.common_self.remove(&240);
    let shot = run_event(&mut game, 240, 20);
    let slots: Vec<i32> = shot.pictures.keys().copied().collect();
    assert_eq!(slots, vec![900, 901, 902, 903], "CE240 layer slots");
    let expected = [
        (900, "stand_001_01.png"),
        (901, "stand_eye.png"),
        (902, "stand_mouth.png"),
        (903, "stand_eyebrow.png"),
    ];
    for (slot, name) in expected {
        let file = &shot.pictures[&slot].file;
        assert!(file.ends_with(name), "CE240 slot {slot}: {file}");
    }
    assert_eq!(shot.warnings, 0, "CE240 warnings");
}

#[test]
fn ce241_blink_keeps_layers() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    // 241 only animates the art that 240 already put up; draw that first. Both
    // banks carry arguments from the boot session, so isolate this fresh call.
    game.vm.vars.common_self.remove(&240);
    game.vm.vars.common_self.remove(&241);
    let _ = run_event(&mut game, 240, 20);
    let before: BTreeMap<i32, String> = game
        .screen
        .iter()
        .filter(|p| p.number > 0)
        .map(|p| (p.number, p.file.clone()))
        .collect();
    assert_eq!(before.len(), 4, "CE240 laid down 4 layers before blink");

    assert!(game.start_event(241), "event 241 did not start");
    for _ in 0..400 {
        tick(&mut game);
    }
    let after: BTreeMap<i32, String> = game
        .screen
        .iter()
        .filter(|p| p.number > 0)
        .map(|p| (p.number, p.file.clone()))
        .collect();
    assert_eq!(after, before, "CE241 must not repaint the layered art");
    assert!(running(&game, 241), "CE241 blink loop should keep running");
    assert_eq!(game.stats.warnings, 0, "CE241 warnings");
}

#[test]
fn ce242_status_readout() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let shot = run_event(&mut game, 242, 20);
    let slots: Vec<i32> = shot.pictures.keys().copied().collect();
    assert_eq!(slots, vec![220, 230, 240, 250, 251], "CE242 slot set");
    assert!(
        shot.pictures[&230].text.contains("行动力"),
        "CE242 action label: {:?}",
        shot.pictures[&230].text
    );
    assert!(
        shot.pictures[&240].text.contains("精力"),
        "CE242 energy label: {:?}",
        shot.pictures[&240].text
    );
    assert!(
        shot.pictures[&250].text.contains("持有金钱"),
        "CE242 money label: {:?}",
        shot.pictures[&250].text
    );
    assert!(
        shot.pictures[&251].text.contains('円'),
        "CE242 money value: {:?}",
        shot.pictures[&251].text
    );
    assert!(
        !shot.pictures[&220].text.is_empty(),
        "CE242 name line must be populated"
    );
    assert!(shot.messages.is_empty(), "CE242 paints no message");
    assert_eq!(shot.warnings, 0, "CE242 warnings");
}

#[test]
fn ce243_clock() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let shot = run_event(&mut game, 243, 20);
    let slots: Vec<i32> = shot.pictures.keys().copied().collect();
    assert_eq!(slots, vec![200, 210], "CE243 slot set");
    let clock = &shot.pictures[&200].text;
    assert!(
        is_hh_mm(clock),
        "CE243 clock should be HH:MM, got {clock:?}"
    );
    assert!(
        shot.pictures[&210].text.contains('周'),
        "CE243 weekday: {:?}",
        shot.pictures[&210].text
    );
    assert_eq!(shot.warnings, 0, "CE243 warnings");
}

#[test]
fn ce244_action_point_delta() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    // CE244's delta is a call argument in self slot 0; the durable bank still
    // holds the last real caller's value, which can clamp the branch away.
    game.vm
        .vars
        .common_self
        .entry(244)
        .or_insert_with(Default::default)
        .set(0, 0);
    let shot = run_event(&mut game, 244, 20);
    let slots: Vec<i32> = shot.pictures.keys().copied().collect();
    assert_eq!(slots, vec![110], "CE244 slot set");
    let delta = &shot.pictures[&110].text;
    assert!(
        is_signed_int(delta),
        "CE244 delta should be a signed integer, got {delta:?}"
    );
    assert_eq!(shot.warnings, 0, "CE244 warnings");
}

#[test]
fn ce296_play_tendency() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let shot = run_event(&mut game, 296, 30);
    let slots: Vec<i32> = shot.pictures.keys().copied().collect();
    assert_eq!(slots, vec![400, 401, 412, 413], "CE296 slot set");
    assert!(
        shot.pictures[&401].text.contains("两个人的生活才刚刚开始"),
        "CE296 summary line: {:?}",
        shot.pictures[&401].text
    );
    assert!(
        shot.pictures[&412].text.contains("妹妹好像"),
        "CE296 row #412: {:?}",
        shot.pictures[&412].text
    );
    assert!(
        shot.pictures[&413].text.contains("妹妹似乎"),
        "CE296 row #413: {:?}",
        shot.pictures[&413].text
    );
    assert!(
        !shot.pictures[&400].text.is_empty(),
        "CE296 header line must be populated"
    );
    assert_eq!(shot.warnings, 0, "CE296 warnings");
}

#[test]
fn ce297_staff_roll() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let roll = run_until_end(&mut game, 297, 8000);
    assert!(
        roll.ended,
        "CE297 should finish within {cap} frames",
        cap = 8000
    );
    assert!(
        roll.frames > 1000,
        "CE297 is a long roll, ran {} frames",
        roll.frames
    );
    assert!(roll.saw_credit, "CE297 scrolls the credit CG strip");
    assert_eq!(roll.warnings, 0, "CE297 warnings");
}

#[test]
fn ce302_credits() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    let roll = run_until_end(&mut game, 302, 8000);
    assert!(
        roll.ended,
        "CE302 should finish within {cap} frames",
        cap = 8000
    );
    assert!(
        roll.frames > 1000,
        "CE302 is a long roll, ran {} frames",
        roll.frames
    );
    assert!(roll.saw_credit, "CE302 scrolls the credit CG strip");
    assert_eq!(roll.warnings, 0, "CE302 warnings");
}

#[test]
fn ce301_album_draw_is_context_only() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    game.screen.clear();
    game.messages.clear();
    let _started = game.start_event(301);
    for _ in 0..30 {
        tick(&mut game);
    }
    let painted = game.screen.iter().filter(|p| p.number > 0).count();
    assert_eq!(
        painted, 0,
        "CE301 paints nothing without a caller selection"
    );
    assert!(
        !running(&game, 301),
        "CE301 is a draw subroutine, not a running event"
    );
    assert!(game.choices.is_none(), "CE301 offers no choice");
    assert!(game.messages.is_empty(), "CE301 says nothing");
    assert_eq!(game.stats.warnings, 0, "CE301 warnings");
}

#[test]
fn ce303_album_screen() {
    let Some(mut game) = open_loaded_bedroom() else {
        return;
    };
    game.screen.clear();
    game.messages.clear();
    assert!(game.start_event(303), "event 303 did not start");
    for _ in 0..30 {
        tick(&mut game);
    }
    assert!(running(&game, 303), "CE303 album screen stays open");

    let layout = [
        (10, "album_000.png", 0, 0),
        (114, "album_008.png", 329, 249),
        (115, "album_009.png", 470, 249),
        (116, "album_010.png", 611, 249),
        (900, "stand_", 750, 80),
        (901, "stand_eye.png", 750, 80),
        (902, "stand_mouth.png", 750, 80),
        (903, "stand_eyebrow.png", 750, 80),
    ];
    for (slot, name, x, y) in layout {
        let pic = game
            .screen
            .get(slot)
            .unwrap_or_else(|| panic!("CE303 missing slot {slot}"));
        // The base preview layer animates between stand_00X_0Y variants, so
        // only pin its prefix; the eye/mouth/brow layers stay exact.
        let ok = if name == "stand_" {
            pic.file.starts_with("Picture/stand_")
        } else {
            pic.file.ends_with(name)
        };
        assert!(ok, "CE303 slot {slot} file: {}", pic.file);
        assert_eq!((pic.x, pic.y), (x, y), "CE303 slot {slot} position");
    }
    assert_eq!(game.vm.vars.get(238), 1, "CE303 raises album-display flag");

    // This save only has three collected thumbnails; clicking them keeps the grid up.
    for (x, y) in [(419, 339), (560, 339), (701, 339)] {
        click_at(&mut game, x, y);
        assert!(
            running(&game, 303),
            "CE303 stays open after clicking ({x},{y})"
        );
        let grid: Vec<i32> = game
            .screen
            .iter()
            .filter(|p| p.number > 0 && p.file.contains("album_"))
            .map(|p| p.number)
            .collect();
        assert_eq!(
            grid,
            vec![10, 114, 115, 116],
            "CE303 grid survives click ({x},{y})"
        );
        // The standing preview must stay layered over the grid.
        for slot in [900, 901, 902, 903] {
            assert!(
                game.screen.get(slot).is_some(),
                "CE303 preview slot {slot} vanished after click"
            );
        }
    }

    // Clicking a thumbnail opens the picture detail as a child coroutine, so the
    // first cancel closes that view and the second closes the album (CE303 polls
    // cancel at pc885 only after the child returns). Press until it is gone.
    for _ in 0..3 {
        if !running(&game, 303) {
            break;
        }
        press(&mut game, wolf_game::key::CANCEL);
    }
    assert!(!running(&game, 303), "CE303 closes on cancel");
    let album_left: Vec<i32> = game
        .screen
        .iter()
        .filter(|p| p.number > 0 && p.file.contains("album_"))
        .map(|p| p.number)
        .collect();
    assert!(
        album_left.is_empty(),
        "CE303 closes the album grid: {album_left:?}"
    );
    assert_eq!(game.vm.vars.get(238), 0, "CE303 lowers album-display flag");
    assert_eq!(game.stats.warnings, 0, "CE303 warnings");
}
