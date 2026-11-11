//! BUG-09/10/16 regression: a map event blocked inside a common-event call must
//! be allowed to finish its cleanup before the runtime switches pages.
//!
//! SampleMapA Event 1 (妹寝そべる) draws the empty-room layer `-9`, a close-up
//! via CE240, shows a line, then calls CE245 (night menu). If a variable that
//! selects another page changes while CE245 is open, the old runtime killed the
//! blocked event, so commands 7/8 (clear CE240, clear `-9`) never ran and the
//! room stayed empty with the close-up on top. The runtime now defers the page
//! switch until the parent returns.
//!
//! Data-gated: without work/Data the test prints a skip and returns.

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

fn running(game: &Game, id: u32) -> bool {
    game.vm.instances().iter().any(|inst| inst.event == id)
}

#[test]
fn blocked_event_cleans_up_before_a_page_switch() {
    let root = data_root();
    let save = root.join("Save").join("SaveData01.sav");
    if !save.is_file() {
        eprintln!("skipping: no SaveData01 under {}", root.display());
        return;
    }
    let mut game = match Game::new(root.clone()) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: cannot open data root: {err}");
            return;
        }
    };
    if game.load_save(&save).is_err() {
        eprintln!("skipping: cannot load SaveData01");
        return;
    }
    game.auto_advance = false;
    game.auto_choice = false;
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

    // Dismiss the opening line until CE245's choice prompt is live. The event
    // is then blocked inside the 210 call, with `-9` and the close-up drawn.
    let mut choice_seen = false;
    for _ in 0..120 {
        game.frame();
        if !game.messages.is_empty() {
            game.key_bits = key::OK;
            game.frame();
            game.key_bits = 0;
        }
        if game.choices.is_some() {
            choice_seen = true;
            break;
        }
    }
    assert!(choice_seen, "CE245 choice prompt never opened");
    assert!(
        game.screen.get(-9).is_some(),
        "the event must draw the empty-room layer before blocking"
    );

    // Select the inert var70 == 1 page. A runtime that acts on the page change
    // immediately kills Event 1 while it is blocked in CE245.
    game.vm.vars.set(70, 1);
    for _ in 0..10 {
        game.frame();
    }
    assert!(
        running(&game, 1),
        "a blocked map event must survive a page-condition change"
    );

    // CANCEL closes CE245; Event 1 must resume commands 7/8 before the page
    // switch is allowed. The selected page 4 has no commands, so nothing redraws
    // the empty-room layer afterwards.
    for _ in 0..12 {
        game.key_bits = key::CANCEL;
        game.frame();
    }
    game.key_bits = 0;
    for _ in 0..60 {
        game.frame();
    }

    assert!(!running(&game, 1), "Event 1 should have finished");
    assert!(
        game.screen.get(-9).is_none(),
        "the empty-room layer must be cleared after the night menu returns"
    );
    assert_eq!(game.stats.warnings, 0, "warnings");
}
