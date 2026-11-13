//! BUG-02 regression: the balloon-message interface must reach CE268 and carry
//! the speaker name into the display event.
//!
//! SampleMapA Event 1 (妹寝そべる) opens the third-party balloon window with
//! `210 [500264, .., "妹妹"]`.  CE264's relative call `600104` is CE268
//! (名前欄の変更), not absolute event 104; CE268 computes the cross-event
//! address of CE269's string slot 5 and writes the name there.  CE270 then reads
//! that slot for the name plate (picture 36014).
//!
//! The whole test is data-gated: without work/Data it prints a skip and returns.

use std::path::PathBuf;

use wolf_format::mps::Map;
use wolf_game::picture::{SCREEN_H, SCREEN_W};
use wolf_game::Game;

const PLATE: i32 = 36014;
const REQUIRED_VISIBLE_FRAMES: usize = 60;

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

/// Strips WOLF text escapes so comparisons look at the visible glyphs.
fn visible(raw: &str) -> String {
    let mut out = String::new();
    let mut it = raw.chars().peekable();
    while let Some(c) = it.next() {
        if (c as u32) != 92 {
            out.push(c);
            continue;
        }
        while let Some(&ch) = it.peek() {
            if ch.is_ascii_alphanumeric() {
                it.next();
            } else {
                break;
            }
        }
        if it.peek() == Some(&'[') {
            for ch in it.by_ref() {
                if ch == ']' {
                    break;
                }
            }
        }
    }
    out
}

#[test]
fn event_one_runs_ce268_and_the_name_reaches_the_balloon_plate() {
    let root = data_root();
    let mut game = match Game::new(root.clone()) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: cannot open data root {root:?}: {err}");
            return;
        }
    };
    // The balloon display event CE270 is a 常時作動 coroutine; the real load path
    // starts the engine events before restoring the save. Without this the interface
    // events run but nothing paints the balloon.
    game.prime_engine();
    if let Err(err) = game.load_save(&root.join("Save").join("SaveData01.sav")) {
        eprintln!("skipping: cannot load SaveData01: {err}");
        return;
    }
    game.auto_advance = false;
    // The save snapshot also contains whatever balloon window the player left open.
    // Start from an empty screen so the pictures below are attributable to this run.
    game.screen.clear();
    game.messages.clear();

    let bytes = match std::fs::read(root.join("MapData").join("SampleMapA.mps")) {
        Ok(bytes) => bytes,
        Err(err) => {
            eprintln!("skipping: cannot read SampleMapA: {err}");
            return;
        }
    };
    let mut map = Map::parse(&bytes).expect("SampleMapA parses");
    map.events.retain(|event| event.id == 1);
    game.start_pages(&map, None);
    assert!(game.start_map_event(&map, 1), "Event 1 starts");

    let mut bank_name = String::new();
    let mut visible_streak = 0usize;
    let mut longest_visible_streak = 0usize;
    let mut plate_rect = None;
    for frame in 0..120 {
        game.frame();
        // CE268 writes the name into CE269's CSelf5 (string slot 0).
        let name = game
            .vm
            .vars
            .common_self
            .get(&269)
            .map(|bank| bank.get_str(0).to_owned())
            .unwrap_or_default();
        if !name.is_empty() {
            bank_name = name;
        }
        // CE270 paints the name plate while the window is open. Count the longest
        // run of frames in which it is both present and unpainted-hidden, not just
        // the first frame that happened to contain the text.
        let plate_visible = game
            .screen
            .get(PLATE)
            .is_some_and(|picture| !picture.hidden && visible(&picture.text).contains("妹妹"));
        if !plate_visible {
            visible_streak = 0;
            continue;
        }
        visible_streak += 1;
        longest_visible_streak = longest_visible_streak.max(visible_streak);
        if visible_streak == 1 {
            if let Some(plate) = game.screen.get(36008) {
                eprintln!(
                    "plate base split={:?} pattern={} window={:?} xy=({}, {}) anchor={} extras={:?}",
                    plate.split,
                    plate.pattern_index,
                    plate.window,
                    plate.x,
                    plate.y,
                    plate.anchor,
                    plate.extras
                );
            }
        }
        let rect = game
            .screen
            .picture_rect(PLATE, |_| None)
            .expect("a visible name plate has a screen rectangle");
        assert!(
            rect[2] > 0.0 && rect[3] > 0.0,
            "frame {frame}: name plate has an empty rectangle {rect:?}"
        );
        assert!(
            rect[0] >= 0.0
                && rect[1] >= 0.0
                && rect[0] + rect[2] <= SCREEN_W as f32
                && rect[1] + rect[3] <= SCREEN_H as f32,
            "frame {frame}: name plate is off screen: {rect:?}"
        );
        plate_rect = Some(rect);
    }

    assert_eq!(
        bank_name, "妹妹",
        "CE264's 600104 relative call must reach CE268, which writes the speaker name"
    );
    assert!(
        longest_visible_streak >= REQUIRED_VISIBLE_FRAMES,
        "name plate must stay visible for at least {REQUIRED_VISIBLE_FRAMES} consecutive \
         frames, longest run was {longest_visible_streak}"
    );
    assert!(
        plate_rect.is_some(),
        "CE270 must paint picture {PLATE} with the speaker name"
    );
    assert_eq!(game.stats.warnings, 0, "warnings");
}
