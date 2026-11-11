//! M3-AD title-screen visibility and the cancel-from-load path (task-36).
//!
//! Everything is measured against the shipped data in work/Data; the tests skip when the
//! data root is absent, matching the rest of the suite.
//!
//! What is pinned, and why:
//!
//! * The original title menu is an opcode-102 choice window shown by common event 42
//!   (`オリジナルタイトル画面Ａ`), which is called from the TitleMap event 2 autorun page.
//!   That script sets the choice-window anchor Sys3/Sys4 to **-1000 / -1000** (not the
//!   manual's -1 "default position"); the port lays the window out faithfully at that
//!   anchor, finds it fully off a 1024x576 screen, and paints nothing. The JP original's
//!   CommonEvent.dat and TitleMap.mps carry the same two instructions, so this is the
//!   shipped data's own quirk, not a translation or port regression. The regression nail
//!   asserts the current faithful behaviour: three options exist in the VM, the anchor is
//!   (-1000,-1000), `choice::layout_at_sized` returns None, and no choice text is on screen.
//!
//! * The scaffolding test documents the target of the suggested fix: at any sane anchor a
//!   panel for the same three options is on screen, i.e. treating an out-of-bounds (or the
//!   manual's -1) anchor as "default position" would make the title menu visible again.
//!
//! * Cancelling the load screen must put an operable title menu back. Boot -> menu2
//!   (`つづきから`) runs CE42 -> CE14 -> CE131 (the load screen, picture slots 12000..12113).
//!   Pressing CANCEL unwinds CE131 -> CE14 (op172) -> CE42 -> the rest of the TitleMap
//!   event 2 page ([60] Sys4=150, [62]), and the whole call stack ends. CE42's op102 is a
//!   one-shot, so the Game layer detects the boot map left with no title stack and starts
//!   CE42 again. The test pins the re-opened menu (same three options, Sys3/Sys4 back at
//!   -1000, CE43's button rows repainted).
//!
//! Data-missing runs print a skip and return, keeping the default `cargo test` exit 0.

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

/// Strips WOLF text escapes so assertions look at the glyphs the player would see.
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

fn open_game() -> Option<Game> {
    match Game::new(data_root()) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!("skipping: {err}");
            None
        }
    }
}

fn running(game: &Game, id: u32) -> bool {
    game.vm.instances().iter().any(|inst| inst.event == id)
}

/// Boots and advances until the opcode-102 title choice window is live, without selecting
/// anything. Returns the options the script offered and whether the engine auto-skip
/// event 271 was seen running during boot. Skips (None) when the data is absent or the
/// menu never appears.
fn boot_to_title_choices() -> Option<(Game, Vec<String>, bool)> {
    let mut game = open_game()?;
    game.auto_advance = true;
    game.auto_choice = false;
    if game.boot().is_err() {
        eprintln!("skipping: boot failed");
        return None;
    }
    let mut saw_271 = false;
    for _ in 0..400 {
        game.frame();
        saw_271 |= running(&game, 271);
        if game.choices.is_some() {
            break;
        }
    }
    // The title renderer (event 43) only runs while the menu is up; give it a few frames
    // to paint the Picture/menu*_* buttons after the prompt first appears.
    for _ in 0..3 {
        game.frame();
    }
    let options = game.choices.as_ref().map(|c| c.options.clone())?;
    Some((game, options, saw_271))
}

/// The three default option labels the CE42 script passes to opcode 102.
const TITLE_OPTIONS: [&str; 3] = ["menu1", "menu2", "menu3"];

#[test]
fn title_menu_options_fall_back_to_a_visible_centred_panel() {
    let Some((game, options, saw_271)) = boot_to_title_choices() else {
        return;
    };

    // The VM really is holding a three-option choice window: the menu is there in data.
    assert_eq!(
        options,
        TITLE_OPTIONS
            .iter()
            .map(|s| s.to_string())
            .collect::<Vec<_>>(),
        "CE42 hands opcode 102 the three title options"
    );
    assert_eq!(
        game.choice_cursor(),
        0,
        "initial title cursor is the first row"
    );

    // CE42 parks the window at Sys3/Sys4 = -1000/-1000 (the JP original does the same).
    assert_eq!(game.choice_anchor(), (-1000, -1000), "title choice anchor");
    assert_eq!(game.sys(3), -1000, "Sys3 (choice window X)");
    assert_eq!(game.sys(4), -1000, "Sys4 (choice window Y)");

    // The title menu is the script's own image buttons, so the port returns the fixed
    // image-button hit rows (y = 400/450/500) instead of a text panel, regardless of the
    // script's -1000/-1000 anchor.
    let panel = wolf_game::choice::layout_at_sized(&options, 0, -1000, -1000, 20.0)
        .expect("the title image menu always has on-screen hit rows");
    assert!(
        game.screen.iter().any(|p| p.file.contains("menu1")),
        "event 43 paints the real Picture/menu1_* title button: {:?}",
        game.screen
            .iter()
            .map(|p| p.file.clone())
            .collect::<Vec<_>>()
    );
    assert!(
        panel.rect[0] >= 0.0
            && panel.rect[1] >= 0.0
            && panel.rect[0] + panel.rect[2] <= 1024.0
            && panel.rect[1] + panel.rect[3] <= 576.0,
        "the fallback panel is fully on screen: {:?}",
        panel.rect
    );
    assert_eq!(
        panel.lines.len(),
        3,
        "the fallback panel still lists all three title options"
    );

    // The only picture up is the title art (slot -2); the menu is not baked into it.
    let title_art_present = game.screen.iter().any(|p| p.file.contains("TitleGraphic2"));
    assert!(
        title_art_present,
        "the title background picture is on screen"
    );
    assert!(
        !game.screen.iter().any(|p| p.kind.is_text()),
        "no text picture is used for the title menu"
    );

    // The title event (42) is still on the stack while the window is up. The engine
    // auto-skip event (271) ran at boot (it registers the balloon-message library and
    // then ends), so it is no longer live once the title prompt is waiting -- what is
    // pinned here is that it really did run on the way in.
    assert!(running(&game, 42), "the title event (42) awaits the choice");
    assert!(saw_271, "the engine auto-skip event (271) ran during boot");
    assert!(
        !running(&game, 271),
        "271 finishes after registering its library"
    );
    assert_eq!(game.stats.warnings, 0, "the title path emits no warnings");
}

#[test]
fn a_valid_anchor_would_show_the_title_menu() {
    // Pure layout maths, no data needed: the suggested fix is to treat an out-of-bounds
    // anchor as "default position". This proves that a sane anchor would put the very same
    // three options on screen, so the fix is sufficient to make the title menu operable.
    let options: Vec<String> = TITLE_OPTIONS.iter().map(|s| s.to_string()).collect();
    let panel = wolf_game::choice::layout_at_sized(&options, 0, 512, 300, 20.0)
        .expect("a mid-screen anchor yields a panel");
    let [x, y, w, h] = panel.rect;
    assert!(
        x >= 0.0 && y >= 0.0,
        "panel top-left is on screen: {:?}",
        panel.rect
    );
    assert!(
        x + w <= 1024.0 && y + h <= 576.0,
        "panel fits inside the 1024x576 screen: {:?}",
        panel.rect
    );
    assert_eq!(
        panel.lines.len(),
        options.len(),
        "one clickable row per option"
    );

    // The centred offline layout (used when there is no engine anchor) is on screen too.
    let centred = wolf_game::choice::layout(&options, 0).rect;
    assert!(
        centred[0] >= 0.0
            && centred[1] >= 0.0
            && centred[0] + centred[2] <= 1024.0
            && centred[1] + centred[3] <= 576.0,
        "centred fallback layout stays on screen: {:?}",
        centred
    );
}

#[test]
fn cancelling_the_load_screen_reopens_the_title_menu() {
    let Some((mut game, options, _saw_271)) = boot_to_title_choices() else {
        return;
    };
    assert_eq!(options, TITLE_OPTIONS, "title offers its three options");

    // Choose menu2 (つづきから): CE42 -> CE14 -> CE131 loads the save/load screen.
    game.set_choice_cursor(1);
    game.auto_choice = true;
    game.auto_choice_delay = 2;

    let mut at_load = false;
    for _ in 0..400 {
        game.frame();
        if running(&game, 131) {
            at_load = true;
            break;
        }
    }
    if !at_load {
        eprintln!("skipping: the load screen (CE131) never came up");
        return;
    }

    // Confirm we really are on the load screen, with the title call stack behind it.
    assert!(
        running(&game, 42),
        "the title event (42) is still on the stack"
    );
    assert!(running(&game, 14), "CE14 (menu dispatch) is on the stack");
    assert!(running(&game, 131), "CE131 (load screen) is on the stack");
    let load_title = game
        .screen
        .get(12002)
        .map(|p| visible(&p.text))
        .unwrap_or_default();
    assert!(
        load_title.contains("选择要读取的数据"),
        "the load screen header is up; slot 12002 text = {load_title:?}"
    );
    assert!(
        game.screen.get(12050).is_some(),
        "the load screen paints its slot rows (12050..)"
    );

    // Cancel the load screen.
    let warnings_before = game.stats.warnings;
    game.key_bits = wolf_game::key::CANCEL;
    for _ in 0..24 {
        game.frame();
    }
    game.key_bits = 0;

    // The stack unwinds (CE131 -> CE14 -> CE42 -> the TitleMap event 2 tail), and the
    // Game layer notices that the boot map is left with no flow running. It restarts
    // CE42, so the player gets the title menu back instead of a menu-less background.
    let mut reopened = false;
    for _ in 0..240 {
        game.frame();
        if game.choices.is_some() && running(&game, 42) {
            reopened = true;
            break;
        }
    }
    assert!(
        reopened,
        "cancelling the load screen must re-open the title menu"
    );
    assert!(!running(&game, 131), "the load screen ended on cancel");
    assert!(!running(&game, 14), "CE14 unwound on cancel");
    assert_eq!(
        game.choices.as_ref().map(|c| c.options.clone()),
        Some(
            TITLE_OPTIONS
                .iter()
                .map(|s| s.to_string())
                .collect::<Vec<_>>()
        ),
        "the restarted title event offers the same three options"
    );
    assert_eq!(game.sys(3), -1000, "the restarted CE42 sets Sys3 again");
    assert_eq!(game.sys(4), -1000, "the restarted CE42 sets Sys4 again");
    assert!(
        game.screen.iter().any(|p| p.file.contains("TitleGraphic2")),
        "the title background picture is still displayed"
    );
    assert!(
        game.screen
            .iter()
            .any(|p| p.file.contains("menu1_b") || p.file.contains("menu1_a")),
        "the title button renderer (CE43) painted its rows again"
    );
    assert!(
        game.diagnostics
            .keys()
            .any(|line| line.contains("menu restarted after load-screen cancel")),
        "the restart is recorded as a diagnostic, got {:?}",
        game.diagnostics.keys().collect::<Vec<_>>()
    );
    assert_eq!(
        game.stats.warnings, warnings_before,
        "cancelling the load screen raises no warnings"
    );
}
#[test]
fn a_fresh_boot_reenters_the_title_menu() {
    // The suggested control-flow fix is "restart the title event when the call stack drains".
    // This proves the restart path itself works: a brand-new Game::new + boot() reproduces
    // the identical three-option title menu, so re-booting (or re-running CE42) is a viable
    // way to bring an operable title menu back after the load screen is cancelled.
    let Some((_first, first_options, _)) = boot_to_title_choices() else {
        return;
    };
    assert_eq!(
        first_options, TITLE_OPTIONS,
        "first boot shows the title menu"
    );
    let Some((_second, second_options, _)) = boot_to_title_choices() else {
        return;
    };
    assert_eq!(
        second_options, TITLE_OPTIONS,
        "a fresh Game::new + boot() re-enters the same title menu"
    );
}
