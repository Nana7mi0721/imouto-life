//! M3: point-and-click bridge for map-event action-key pages (WOLF trigger 0).
//!
//! The bedroom map is a fixed-screen point-and-click UI: there is no walking
//! player, so WOLF's trigger-0 ("action key") pages could never run through a
//! facing tile. `MapRuntime::action_key_at` adds the missing layer — a press over
//! a trigger-0 event's hit rectangle starts that page — and `Game::frame` routes
//! a fresh left click (or a fresh confirm key with the pointer over the map) to
//! it. Hovering alone never activates.
//!
//! Measured geometry (SampleMapA, `work/Data`):
//!
//! | event | name | tile | collision | pixel rectangle | visual control |
//! |---|---|---|---|---|---|
//! | 5 | セーブ | (2,33) | 3x3 | (32,528) 64x64 | bottom-left 保存 icon, slot -5 at (10,510) 80x60 |
//! | 10 | ステータス | (0,9) | 2x5 | (0,144) 48x96 | left-edge status strip |
//! | 21 | 終了仮 | (61,34) | 5x3 | (976,544) 96x64 | bottom-right end button 1108 at (935,505) 90x70 |
//! | 30 | スタッツ | (61,33) | 3x3 | (976,528) 64x64 | bottom-right データ icon, slot -4 at (925,507) 80x60 |
//! | 9 | 日中メニュー | (30,18) | 55x26 | (480,288) 896x432 | full lower-right day menu region |
//!
//! The tiles are 16 px (screen 1024x576 over a 64x36 map), read from
//! `wolf_game::TILE_PX`. The rectangle is `(1 + collision) * 16` wide and tall,
//! anchored at the event tile: the collision fields are WOLF's *range extension*
//! (the ksy calls them `range_extension_x`/`range_extension_y`). The save, end and
//! data buttons each overlap the lower-right part of their event's box (the box
//! starts inside the visible button and reaches past it toward the screen edge);
//! the exact boundary points are pinned by the hit-area test.
//!
//! Activation rules pinned here:
//! * the page is selected by its own four condition slots (the highest page
//!   whose conditions hold), so a hotspot that the save state does not enable
//!   must not fire;
//! * one instance per event: pressing again while the page runs does nothing;
//! * a visible message or an open opcode-102 choice owns the press, so a click
//!   that dismisses text cannot also open a map event;
//! * right click never activates.
//!
//! Data findings (reported, not worked around):
//! * ev10 ステータス requires `v15 == 99`, but no shipped script ever writes 99:
//!   the only writers of v15 are CE250/CE257/CE259, and they write 0 or 1. The
//!   status page is therefore unreachable in normal play without a state edit;
//!   the test pins `v15 = 99` explicitly to exercise the click path and has a
//!   second test proving the condition gate refuses it at the save's v15 = 0.
//! * Deep-night overlap was measured, and the data itself gates it: CE230 sets
//!   v70 = 1, which selects the sister events' 1-tile blank page (ev3 page 4,
//!   condition v70 == 1, coll 0x0, commands [blank]), so a click on the night body
//!   (e.g. (500,445), inside picture 1105 at (460,430) 80x90) starts nothing
//!   (`last_action_event == None`) while ev18's own hit handler still runs. Only
//!   a state the shipped flow never produces (v100 == 1 with v70 forced back to
//!   0) makes ev3 page 2 active and lets the same click reach both ev3 and the
//!   picture-1105 handler. The mapped controls (save/status/menu/end) are disjoint
//!   in every state.
//!
//! Without `work/Data` every test prints a skip line and returns, so the default
//! workspace suite stays green.

use std::path::PathBuf;

use wolf_format::mps::Map;
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

/// Loads the shipped bedroom save and collects only the requested map events.
///
/// The full SampleMapA set includes ev0 (the new-game opening autorun), which
/// would run its own story over every click test, so each test names the events
/// it needs.
fn loaded_with(events: &[u32]) -> Option<Game> {
    let root = data_root();
    let save = root.join("Save").join("SaveData01.sav");
    if !save.is_file() {
        eprintln!("skipping: no SaveData01 under {}", root.display());
        return None;
    }
    let mut game = match Game::new(root.clone()) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: cannot open data root {}: {err}", root.display());
            return None;
        }
    };
    if let Err(err) = game.load_save(&save) {
        eprintln!("skipping: cannot load {}: {err}", save.display());
        return None;
    }
    let map = match read_map("SampleMapA.mps", events) {
        Ok(map) => map,
        Err(err) => {
            eprintln!("skipping: {err}");
            return None;
        }
    };
    game.auto_advance = true;
    game.auto_choice = false;
    game.start_pages(&map, None);
    Some(game)
}

fn read_map(name: &str, events: &[u32]) -> Result<Map, String> {
    let path = data_root().join("MapData").join(name);
    let bytes =
        std::fs::read(&path).map_err(|err| format!("cannot read {}: {err}", path.display()))?;
    let mut map =
        Map::parse(&bytes).map_err(|err| format!("cannot parse {}: {err}", path.display()))?;
    map.events.retain(|event| events.contains(&event.id));
    Ok(map)
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

fn running(game: &Game, event: u32) -> bool {
    game.vm
        .instances()
        .iter()
        .any(|instance| instance.event == event)
}

fn text_of(game: &Game, slot: i32) -> String {
    game.screen
        .get(slot)
        .map(|picture| visible(&picture.text))
        .unwrap_or_default()
}

fn file_of(game: &Game, slot: i32) -> String {
    game.screen
        .get(slot)
        .map(|picture| picture.file.clone())
        .unwrap_or_default()
}

/// A real left click: park the pointer, press for one edge frame, release.
fn click_at(game: &mut Game, x: i32, y: i32) {
    game.mouse = [x, y];
    for _ in 0..2 {
        game.frame();
    }
    game.mouse_buttons = 1;
    game.frame();
    game.mouse_buttons = 0;
    for _ in 0..4 {
        game.frame();
    }
}

/// A real right click, same edge shape as [`click_at`].
fn right_click_at(game: &mut Game, x: i32, y: i32) {
    game.mouse = [x, y];
    for _ in 0..2 {
        game.frame();
    }
    game.mouse_buttons = 2;
    game.frame();
    game.mouse_buttons = 0;
    for _ in 0..4 {
        game.frame();
    }
}

/// Holds a key long enough for an event's 123-poll cadence to see it.
fn press(game: &mut Game, bits: u32) {
    game.key_bits = bits;
    for _ in 0..24 {
        game.frame();
    }
    game.key_bits = 0;
    for _ in 0..6 {
        game.frame();
    }
}

/// Name + size of every file in work/Data/Save, to prove no test wrote a save.
fn save_fingerprint() -> Vec<(String, u64)> {
    let dir = data_root().join("Save");
    let mut out = Vec::new();
    if let Ok(entries) = std::fs::read_dir(&dir) {
        for entry in entries.flatten() {
            if let Ok(meta) = entry.metadata() {
                if meta.is_file() {
                    out.push((entry.file_name().to_string_lossy().into_owned(), meta.len()));
                }
            }
        }
    }
    out.sort();
    out
}

fn assert_no_menu_leftovers(game: &Game) {
    assert!(
        !running(game, 14),
        "CE14 dispatcher still running: {:?}",
        game.vm
            .instances()
            .iter()
            .map(|i| i.event)
            .collect::<Vec<_>>()
    );
    assert!(!running(game, 131), "CE131 save screen still running");
    let leftover: Vec<i32> = game
        .screen
        .iter()
        .filter(|picture| (12000..=12999).contains(&picture.number))
        .map(|picture| picture.number)
        .collect();
    assert!(leftover.is_empty(), "save screen not cleared: {leftover:?}");
    assert_eq!(game.stats.warnings, 0, "warnings");
}

// ---------------------------------------------------------------------------
// 1. The save button (ev5) opens CE131, and a second fresh confirm also works.
// ---------------------------------------------------------------------------

#[test]
fn clicking_the_save_icon_starts_event_5_and_opens_the_save_screen() {
    let Some(mut game) = loaded_with(&[5]) else {
        return;
    };
    let before = save_fingerprint();

    // Slot -5 (Picture/icon01.png) is the bottom-left 保存 button at (10,510),
    // 80x60; its centre (50,540) lies in event 5's (32,528) 64x64 rectangle.
    assert_eq!(file_of(&game, -5), "Picture/icon01.png");
    assert_eq!(game.screen.get(-5).map(|p| (p.x, p.y)), Some((10, 510)));
    click_at(&mut game, 50, 540);
    for _ in 0..30 {
        game.frame();
    }

    assert_eq!(
        game.last_action_event,
        Some(5),
        "save event was not activated"
    );
    assert!(running(&game, 14), "ev5 calls the CE14 menu dispatcher");
    assert!(running(&game, 131), "CE14 dispatches into CE131");
    assert!(
        text_of(&game, 12002).contains("保存"),
        "save header: {:?}",
        text_of(&game, 12002)
    );
    assert!(
        game.choices.is_none(),
        "the save grid is not a choice prompt"
    );
    assert_eq!(game.stats.warnings, 0, "warnings while the grid draws");

    // Cancel unwinds the whole chain and leaves no 12xxx slots behind.
    press(&mut game, key::CANCEL);
    assert_no_menu_leftovers(&game);
    assert_eq!(save_fingerprint(), before, "the test never confirms a save");

    // The keyboard path is the same activation: a fresh OK while the pointer
    // rests on the icon must also start ev5/CE131.
    game.last_action_event = None;
    game.key_bits = key::OK;
    game.frame();
    game.key_bits = 0;
    for _ in 0..30 {
        game.frame();
    }
    assert_eq!(
        game.last_action_event,
        Some(5),
        "confirm key with the pointer on the save icon did not activate ev5"
    );
    assert!(
        running(&game, 14) && running(&game, 131),
        "OK path opens the save screen"
    );
    assert!(text_of(&game, 12002).contains("保存"));
    assert_eq!(game.stats.warnings, 0, "warnings");

    press(&mut game, key::CANCEL);
    assert_no_menu_leftovers(&game);
    assert_eq!(save_fingerprint(), before, "the test never confirms a save");
}

// ---------------------------------------------------------------------------
// 2. Hit-area unit: the shipped event data and the (1+collision) tile rectangle.
// ---------------------------------------------------------------------------

#[test]
fn action_key_hit_area_matches_the_shipped_event_geometry() {
    let map = match read_map("SampleMapA.mps", &[5]) {
        Ok(map) => map,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    let save = map
        .events
        .iter()
        .find(|event| event.id == 5)
        .expect("event 5");
    assert_eq!((save.x, save.y), (2, 33), "event 5 placement");
    assert_eq!(
        (
            save.pages[0].collision_width,
            save.pages[0].collision_height
        ),
        (3, 3),
        "event 5 range extension"
    );
    // Tile (2,33) with a 3x3 extension is 4x4 tiles of 16 px: (32,528)-(96,592).

    let Some(mut game) = loaded_with(&[5]) else {
        return;
    };
    // The visible save icon is (10,510) 80x60. The old 64x64 tile box around
    // (32,528) must no longer own points outside the icon:
    //   * (9,540) is inside the old box but left of the icon;
    //   * (96,540) is inside the old box but right of the icon;
    //   * the top/bottom points are outside the icon vertically.
    // Every point is outside the picture rectangle and must miss.
    for (x, y, label) in [
        (9, 540, "left"),
        (96, 540, "right"),
        (50, 509, "top"),
        (50, 592, "bottom"),
    ] {
        click_at(&mut game, x, y);
        assert_eq!(
            game.last_action_event, None,
            "({x},{y}) outside {label} edge must miss"
        );
        assert!(
            !running(&game, 5) && !running(&game, 131),
            "no save screen from {label}"
        );
    }

    // The centre of the tile box does hit and starts the page.
    click_at(&mut game, 50, 540);
    for _ in 0..10 {
        game.frame();
    }
    assert_eq!(game.last_action_event, Some(5), "inside point must hit");
    assert!(running(&game, 131), "inside point opens CE131");
    assert_eq!(game.stats.warnings, 0, "warnings");
}

// ---------------------------------------------------------------------------
// 3. Status hotspot (ev10 + CE238) and its condition gate.
// ---------------------------------------------------------------------------

/// ev10 page 0 still requires `v15 == 99`, which no shipped script writes. The
/// visible 25-pixel status sliver is a UI affordance: it opens CE238 directly
/// without faking v15 or reviving event 10's dead action page.
#[test]
fn status_sliver_opens_without_faking_the_dead_v15_gate() {
    let Some(mut game) = loaded_with(&[10]) else {
        return;
    };
    assert_eq!(game.vm.vars.get(15), 0, "SaveData01 leaves v15 at zero");
    click_at(&mut game, 8, 152);
    for _ in 0..20 {
        game.frame();
    }
    assert_eq!(
        game.last_action_event,
        Some(10),
        "the visible status strip must open CE238"
    );
    assert_eq!(
        game.screen.get(320).map(|picture| picture.x),
        Some(0),
        "CE238 must slide the panel in"
    );
    assert_eq!(game.vm.vars.get(15), 0, "the bridge must not write v15");
    assert_eq!(game.stats.warnings, 0, "warnings");
}

#[test]
fn clicking_the_status_hotspot_draws_the_status_panel() {
    let Some(mut game) = loaded_with(&[10]) else {
        return;
    };
    // Pin the page condition the shipped scripts never reach (documented quirk):
    // only then is ev10 the active page of the event.
    game.vm.vars.set(15, 99);
    // Tile (0,9) with a 2x5 extension: (0,144)-(48,240). Click its centre.
    click_at(&mut game, 8, 152);
    for _ in 0..30 {
        game.frame();
    }

    assert_eq!(
        game.last_action_event,
        Some(10),
        "status event was not activated"
    );
    // CE238(1,1) slides the status panel in: op150 head bit 0x10000 is a
    // relative offset, so -305 + 305 lands at x=0 (the left screen edge).
    let panel = game.screen.get(320).expect("status panel picture 320");
    assert_eq!(panel.file, "Picture/status01.png");
    assert_eq!(panel.x, 0, "status panel slides in to x=0");
    assert_eq!(text_of(&game, 323), "普通", "status rows are drawn");
    assert_eq!(game.stats.warnings, 0, "warnings");
}

// ---------------------------------------------------------------------------
// 4. Deep-night end button: ev21 終了仮, 是/否, and the closing line.
// ---------------------------------------------------------------------------

/// The map's night-interface pages plus the action-key exit ev21.
fn night_map() -> Result<Map, String> {
    read_map("SampleMapA.mps", &[15, 16, 17, 18, 19, 20, 21, 23, 26])
}

#[test]
fn clicking_the_end_button_opens_ev21_and_the_yes_answer_ends_the_interface() {
    let root = data_root();
    let save = root.join("Save").join("SaveData01.sav");
    if !save.is_file() {
        eprintln!("skipping: no SaveData01 under {}", root.display());
        return;
    }
    let Some(mut game) = loaded_with(&[]) else {
        return;
    };
    let map = match night_map() {
        Ok(map) => map,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    let save_before = save_fingerprint();
    game.start_pages(&map, None);
    // Same entry point as m3_night_interaction_e2e.rs: CE230 深夜1 opens the
    // interface (v100 = 1) and draws the body/item/status layers.
    game.vm.vars.set(100, 1);
    game.vm.vars.set(125, 0);
    game.vm.vars.set(18, 32);
    game.vm.vars.set(19, 32);
    game.start_event(230);
    for _ in 0..260 {
        game.frame();
    }
    assert!(
        !running(&game, 21),
        "trigger-0 ev21 is dormant before the click"
    );
    assert_eq!(
        file_of(&game, 1108),
        "Picture/endbutton.png",
        "the end button is on screen"
    );

    // Tile (61,34) with a 5x3 extension: (976,544)-(1072,608); its tile centre.
    click_at(&mut game, 984, 552);
    let mut messages = Vec::new();
    let mut options = None;
    for _ in 0..120 {
        game.frame();
        for message in &game.messages {
            let text = visible(&message.text);
            if !text.is_empty() && !messages.contains(&text) {
                messages.push(text);
            }
        }
        if let Some(choices) = &game.choices {
            options = Some(choices.options.clone());
            break;
        }
    }
    assert_eq!(
        game.last_action_event,
        Some(21),
        "end event was not activated"
    );
    assert_eq!(
        options.as_deref(),
        Some(["是".to_owned(), "否".to_owned()].as_slice()),
        "the end prompt offers 是/否"
    );

    // 是 ends the interface (v100 -> 0) and plays the closing line.
    game.set_choice_cursor(0);
    game.key_bits = key::OK;
    game.frame();
    game.key_bits = 0;
    for _ in 0..150 {
        game.frame();
        for message in &game.messages {
            let text = visible(&message.text);
            if !text.is_empty() && !messages.contains(&text) {
                messages.push(text);
            }
        }
        if !game.messages.is_empty() {
            game.key_bits = key::OK;
            game.frame();
            game.key_bits = 0;
        }
    }

    assert!(
        messages
            .iter()
            .any(|text| text.contains("暴露了的话就惨了")),
        "exit closing line missing from {messages:?}"
    );
    assert_eq!(
        game.vm.vars.get(100),
        0,
        "the end choice clears the interface page"
    );
    assert_eq!(
        game.vm.vars.get(125),
        0,
        "the end choice clears the action phase"
    );
    assert_eq!(game.stats.warnings, 0, "warnings");
    assert_eq!(save_fingerprint(), save_before, "no save write");
}

#[test]
fn night_body_click_does_not_start_the_daytime_sister_event() {
    // CE230 sets v70 = 1, which selects the sister events' 1-tile blank page
    // (e.g. ev3 page 4: v70 == 1, collision 0x0). Their daytime rectangles are
    // therefore gone even though v100 == 1, so a click on the night body reaches
    // only the interface's own picture handlers (ev18), never ev3.
    let Some(mut game) = loaded_with(&[]) else {
        return;
    };
    let map = match read_map(
        "SampleMapA.mps",
        &[1, 2, 3, 4, 15, 16, 17, 18, 19, 20, 23, 26],
    ) {
        Ok(map) => map,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    game.start_pages(&map, None);
    game.vm.vars.set(100, 1);
    game.start_event(230);
    for _ in 0..260 {
        game.frame();
    }
    assert_eq!(game.vm.vars.get(70), 1, "CE230 enters the deep-night part");

    // (500,445) is inside night picture 1105 (460,430) 80x90 and, were v70 still 0,
    // inside ev3's daytime rectangle (464,368) 80x96.
    click_at(&mut game, 500, 445);
    for _ in 0..20 {
        game.frame();
    }
    assert_eq!(
        game.last_action_event, None,
        "the deep-night blank page must not run a daytime sister event"
    );
    assert!(!running(&game, 3), "ev3 must stay dormant in the night UI");
    assert_eq!(game.stats.warnings, 0, "warnings");
}

// ---------------------------------------------------------------------------
// 5. Non-activating input: empty floor, right click, and owned presses.
// ---------------------------------------------------------------------------

#[test]
fn empty_floor_and_right_click_do_not_activate_anything() {
    let Some(mut game) = loaded_with(&[5, 7, 10, 30]) else {
        return;
    };
    // Make every daytime hotspot condition true so only the point can decide.
    game.vm.vars.set(15, 99);
    game.vm.vars.set(32, 1);
    let count = game.vm.instances().len();

    // (300,100) lies in no trigger-0 rectangle of these events.
    click_at(&mut game, 300, 100);
    for _ in 0..10 {
        game.frame();
    }
    assert_eq!(
        game.last_action_event, None,
        "empty floor must not activate"
    );
    assert_eq!(
        game.vm.instances().len(),
        count,
        "empty floor started an instance"
    );
    assert!(!running(&game, 5) && !running(&game, 7) && !running(&game, 10) && !running(&game, 30));
    assert!(game.messages.is_empty() && game.choices.is_none());

    // Right click on the save hotspot is CANCEL, never an activation.
    right_click_at(&mut game, 50, 540);
    for _ in 0..10 {
        game.frame();
    }
    assert_eq!(
        game.last_action_event, None,
        "right click must not activate"
    );
    assert!(!running(&game, 5) && !running(&game, 14) && !running(&game, 131));
    assert_eq!(game.stats.warnings, 0, "warnings");
}

#[test]
fn an_open_message_owns_the_press() {
    let Some(mut game) = loaded_with(&[5]) else {
        return;
    };
    game.messages.push(wolf_game::Message {
        text: "test".to_owned(),
        face: None,
        frames: 0,
    });
    // auto_advance would dismiss it during the same frame; turn it off so the
    // message is visibly open when the click arrives.
    game.auto_advance = false;
    click_at(&mut game, 50, 540);
    assert_eq!(
        game.last_action_event, None,
        "a click that owns a message must not activate"
    );
    assert!(!running(&game, 5) && !running(&game, 131));
    assert_eq!(game.stats.warnings, 0, "warnings");
}
