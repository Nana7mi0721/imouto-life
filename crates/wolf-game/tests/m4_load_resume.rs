//! M4: a bare save load rebuilds the map runtime without replaying the opening.
//!
//! play --load-save and capture --load-save have no retail save-menu coroutine to
//! restart the map, so Game::resume_loaded_map identifies the saved map from the
//! SavePart1 snapshot and installs its pages. The shipped save does not store each
//! map event's current page, so pages are re-selected from the restored variables;
//! the one hazard is SampleMapA event 0, whose unconditional autorun is the
//! new-game opening. start_pages_loaded records that autorun as already run while
//! still selecting its page, so the bedroom comes up on the first frame.

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

fn live_events(game: &Game) -> Vec<u32> {
    let mut events: Vec<u32> = game.vm.instances().iter().map(|inst| inst.event).collect();
    events.sort_unstable();
    events.dedup();
    events
}

fn load_and_resume() -> Option<Game> {
    let root = data_root();
    let save = root.join("Save").join("SaveData01.sav");
    if !save.is_file() {
        eprintln!("skipping: missing {}", save.display());
        return None;
    }
    let mut game = Game::new(root).expect("game");
    game.auto_advance = true;
    game.auto_choice = false;
    game.prime_engine();
    game.load_save(&save).expect("load SaveData01");
    let map = game.resume_loaded_map().expect("resume map");
    assert_eq!(map, "SampleMapA", "saved room is the 64x36 home map");
    for _ in 0..120 {
        game.frame();
    }
    Some(game)
}

#[test]
fn loading_a_save_installs_the_map_and_hud() {
    let Some(game) = load_and_resume() else {
        return;
    };
    assert!(
        game.tilemap.is_some(),
        "the saved map's tile layer is installed"
    );

    let texts: Vec<String> = game.text_quads().into_iter().map(|q| q.text).collect();
    assert!(
        texts.iter().any(|text| text == "行动力60/65"),
        "HUD action text after load: {texts:?}"
    );
    // The HUD layout splits at ASCII spaces, so the two spans are separate quads.
    let compact: String = texts
        .concat()
        .chars()
        .filter(|c| !c.is_whitespace())
        .collect();
    assert!(
        compact.contains("精力3/3"),
        "HUD stamina text after load: {texts:?}"
    );
}

#[test]
fn loading_a_save_does_not_replay_the_opening_autorun() {
    let Some(game) = load_and_resume() else {
        return;
    };

    // Event 0 is the unconditional new-game opening on SampleMapA. Its page is
    // still selected (so the runtime state matches retail page selection), but its
    // autorun coroutine must not be running.
    let pages = game.runtime.active_pages(&game.vm);
    let event_zero = pages.iter().find(|(event, _)| *event == 0).copied();
    assert_eq!(
        event_zero,
        Some((0, Some(0))),
        "event 0 page 0 should be selected after load: {pages:?}"
    );
    let live = live_events(&game);
    assert!(
        !live.contains(&0),
        "event 0 opening scene must not run after load, live events: {live:?}"
    );

    // A plain loaded frame has no message window and no choice prompt from the
    // opening scene; the clickable map UI is the visible interactive layer instead.
    assert!(
        game.messages.is_empty(),
        "no opening message after load: {:?}",
        game.messages
    );
    assert!(game.choices.is_none(), "no opening choice after load");
}
