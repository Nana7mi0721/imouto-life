//! M4: the HUD status cells survive a save load.
//!
//! Retail CE48 (X[共]基本ｼｽﾃﾑ自動初期化) is an ENGINE_ALWAYS coroutine whose first pass
//! calls CE70(+999999)/CE124 and resets the temporary status row.  Loading SaveData01
//! before that pass finishes therefore loses the saved action/stamina values.  The real
//! engine finishes CE48 during boot, before the title menu, so a load path must do the
//! same (Game::prime_engine).
//!
//! It also covers the database-value magic operands CE242 uses to read those cells:
//! 1_100_001_206/1207/1208/1209 are CDataBase type 0 row 12 columns 6/7/8/9, not
//! ordinary variables.  Reading them raw made every "current >= max" test true and
//! overwrote the stamina maximum with 9.

use std::path::PathBuf;

use wolf_game::db::Container;
use wolf_game::Game;

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let p = PathBuf::from(raw);
    if p.is_absolute() {
        p
    } else {
        let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        base.pop();
        base.pop();
        base.join(p)
    }
}

fn loaded_after_prime() -> Option<Game> {
    let root = data_root();
    let save = root.join("Save").join("SaveData01.sav");
    if !save.is_file() {
        eprintln!("skipping: missing {}", save.display());
        return None;
    }
    let mut game = Game::new(root).expect("game");
    game.auto_advance = true;
    game.auto_choice = false;
    // Finish CE48 before restoring, exactly like the title menu does.
    game.prime_engine();
    game.load_save(&save).expect("load SaveData01");
    for _ in 0..120 {
        game.frame();
    }
    Some(game)
}

#[test]
fn loading_a_save_keeps_action_and_stamina() {
    let Some(game) = loaded_after_prime() else {
        return;
    };
    let cell = |column| game.databases.num(Container::CData, 0, 12, column);
    // SaveData01: stamina 3/3, action 60/65.
    assert_eq!(cell(6), Some(3), "stamina current");
    assert_eq!(cell(7), Some(3), "stamina maximum");
    assert_eq!(cell(8), Some(60), "action current");
    assert_eq!(cell(9), Some(65), "action maximum");

    let quads = game.text_quads();
    let texts: Vec<&str> = quads.iter().map(|quad| quad.text.as_str()).collect();
    let compact: String = texts
        .concat()
        .chars()
        .filter(|c| !c.is_whitespace())
        .collect();
    assert!(
        compact.contains("行动力60/65"),
        "HUD action text: {texts:?}"
    );
    assert!(compact.contains("精力3/3"), "HUD stamina text: {texts:?}");
    let action: Vec<_> = quads.iter().filter(|quad| quad.number == 230).collect();
    assert_eq!(
        action
            .iter()
            .map(|quad| quad.text.as_str())
            .collect::<Vec<_>>(),
        ["行动力", "60/65"],
        "the optional gauge must split the label from the value"
    );
    assert!(
        action[1].rect[0] >= action[0].rect[0] + action[0].rect[2],
        "the value must not overlap the action label: {action:?}"
    );
    assert_eq!(
        game.hud_action_points(),
        Some((60, 65)),
        "the front-end gauge must read action points, not stamina"
    );
    assert_eq!(
        game.hud_energy(),
        Some((3, 3)),
        "the front-end gauge must read the same live stamina cells"
    );
}

#[test]
fn prologue_text_in_slot_230_is_not_mistaken_for_the_gauge() {
    let Some(mut game) = loaded_after_prime() else {
        return;
    };
    {
        let hud = game
            .screen
            .get_mut(230)
            .expect("CE242 leaves the gauge picture live");
        assert!(!hud.hidden && hud.opacity > 0 && hud.kind.is_text());
        hud.text = "\\f[14]一个月前——".to_owned();
    }
    assert_eq!(
        game.hud_action_points(),
        None,
        "narration must not draw the action bar even though CData holds 60/65"
    );
    assert!(
        game.text_quads().iter().all(|quad| quad.number != 230),
        "prologue narration in slot 230 must not reach the text pass"
    );
    game.screen.get_mut(230).expect("gauge picture").text = "\\f[14]行动力60/65".to_owned();
    assert_eq!(game.hud_action_points(), Some((60, 65)));
}

#[test]
fn prime_engine_finishes_the_initialisation_event() {
    let root = data_root();
    if !root.join("BasicData").join("CommonEvent.dat").is_file() {
        eprintln!("skipping: no data under {}", root.display());
        return;
    }
    let mut game = Game::new(root).expect("game");
    let frames = game.prime_engine();
    assert!(frames > 0, "CE48 should have needed at least one frame");
    assert!(
        frames < 600,
        "CE48 did not finish inside the safety bound: {frames}"
    );
    assert!(
        !game
            .vm
            .instances()
            .iter()
            .any(|instance| instance.event == wolf_game::game::ENGINE_INIT_EVENT),
        "CE48 instance still alive after prime_engine"
    );
}
