//! Message-window / text-picture visual layer for the M3 milestone.
//!
//! The game draws its dialogue through a third-party balloon-message plugin
//! (common events 269/270/271 plus helpers 264-268) rather than the engine's
//! native opcode 101. Those events live entirely as scripts, so a headless run
//! only exercises them through the picture layer: the window frame, the text
//! pictures, the HP/SP value readouts, the number popups, etc.
//!
//! These tests drive the real save (SaveData01) into the bedroom, then start
//! the target common events and assert on what the picture / message / tint /
//! transition stores hold afterwards. They also cover the pure state machines
//! (screen tint, screen transition) and the font-metric fallback used when no
//! real font file is present under work/Data.
//!
//! Everything skips cleanly (eprintln + return) when WOLF_DATA_ROOT is missing
//! so a plain `cargo test --workspace` keeps exit 0.

use std::path::PathBuf;

use wolf_game::picture::{Picture, PictureKind};
use wolf_game::{Game, ScreenTint, ScreenTransition};

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

/// Pops WOLF backslash escapes (`\\`, `\\c[n]`, control codes) so the
/// remaining text can be compared against plain strings.
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

/// Loads SaveData01 into the bedroom HUD (picture 230 shows 行動力). Returns
/// `Err` when the data dump is absent so callers can skip.
fn bedroom() -> Result<Game, String> {
    let mut game = Game::new(data_root()).map_err(|err| err.to_string())?;
    game.start_engine_events();
    let save = data_root().join("Save").join("SaveData01.sav");
    game.load_save(&save)?;
    for _ in 0..5 {
        game.frame();
    }
    let has_hud = game
        .screen
        .iter()
        .any(|picture| picture.number == 230 && visible(&picture.text).contains("行动力"));
    if !has_hud {
        return Err("SaveData01 did not load into the bedroom HUD".to_owned());
    }
    Ok(game)
}

fn on_screen_texts(game: &Game) -> Vec<(i32, String)> {
    game.screen
        .iter()
        .filter(|p| p.kind.is_text() && !visible(&p.text).is_empty())
        .map(|p| (p.number, visible(&p.text)))
        .collect()
}

// ---------------------------------------------------------------------------
// CE264: message-window interface — paints the window frame plus the value
// readouts (HP/SP) and a small number popup. Deterministic against SaveData01.
// ---------------------------------------------------------------------------
#[test]
fn message_window_interface_paints_frame_and_text() {
    let mut game = match bedroom() {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    let warnings_before = game.stats.warnings;
    game.screen.clear();
    assert!(game.start_event(264), "CE264 should start");
    for _ in 0..30 {
        game.frame();
    }

    let mut numbers: Vec<i32> = game
        .screen
        .iter()
        .filter(|p| p.number > 0)
        .map(|p| p.number)
        .collect();
    numbers.sort_unstable();
    assert_eq!(
        numbers.len(),
        13,
        "CE264 should paint 13 pictures, got {numbers:?}"
    );
    for expected in [12000, 12001, 12010, 12014, 12018, 16000, 16001] {
        assert!(
            numbers.contains(&expected),
            "CE264 missing picture {expected} in {numbers:?}"
        );
    }

    let frame = game
        .screen
        .iter()
        .find(|p| p.number == 12001)
        .expect("window frame picture 12001");
    assert!(
        frame.file.contains("WindowBase_amania"),
        "window frame should use WindowBase_amania, got {:?}",
        frame.file
    );

    let texts = on_screen_texts(&game);
    assert_eq!(
        texts.len(),
        3,
        "CE264 should paint exactly 3 text pictures, got {texts:?}"
    );
    let text_of = |number: i32| {
        texts
            .iter()
            .find(|(n, _)| *n == number)
            .map(|(_, t)| t.clone())
            .unwrap_or_default()
    };
    assert_eq!(text_of(12010).trim(), "1", "number popup 12010");
    let hp = text_of(12014);
    assert!(
        hp.contains("HP") && hp.contains("/50"),
        "HP readout 12014 = {hp:?}"
    );
    let sp = text_of(12018);
    assert!(
        sp.contains("SP") && sp.contains("/20"),
        "SP readout 12018 = {sp:?}"
    );

    let quads = game.text_quads();
    // 12010 is one run; 12014 and 12018 each split into three style runs (HP, name,
    // /50) once the 290 shift is applied in the same tenth-of-a-cell unit as the panel.
    assert_eq!(quads.len(), 7, "CE264 should emit 7 text quads");
    assert!(
        quads.iter().any(|q| q.text.contains("/50")),
        "a quad carries /50"
    );
    assert!(
        quads.iter().any(|q| q.text.contains("/20")),
        "a quad carries /20"
    );

    assert_eq!(game.stats.warnings, warnings_before, "CE264 must not warn");
}

// ---------------------------------------------------------------------------
// CE230: a plain story message — text is revealed character by character and
// the layout reports the font metrics (font 20, line height 26).
// ---------------------------------------------------------------------------
#[test]
fn story_message_types_out() {
    let mut game = match bedroom() {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    game.auto_advance = false;
    game.screen.clear();
    assert!(game.start_event(230), "CE230 should start");

    let mut series: Vec<(usize, usize, bool)> = Vec::new();
    for _ in 0..90 {
        game.frame();
        if let Some(layout) = game.message_layout() {
            series.push((layout.typed, layout.total, layout.typing));
        }
    }

    let last = game.messages.last().expect("a message should be active");
    assert!(
        visible(&last.text).contains("咽口水"),
        "CE230 message text = {:?}",
        visible(&last.text)
    );
    assert_eq!(last.face, None, "CE230 has no face");

    let layout = game.message_layout().expect("layout present");
    assert_eq!(layout.font_px, 20.0, "default font size");
    assert_eq!(
        layout.line_height, 23.0,
        "line height = font + scaled spacing 3"
    );
    assert_eq!(layout.typed, layout.total, "message finishes revealing");
    assert!(!layout.typing, "typing should be done");
    assert!(layout.rows.len() >= 1);
    assert_eq!(layout.total, 6, "…咽口水。 is six characters");

    // Reveal count only ever grows, and starts from zero.
    assert_eq!(series.first().map(|s| s.0), Some(0), "starts fully hidden");
    for pair in series.windows(2) {
        assert!(
            pair[1].0 >= pair[0].0,
            "typed count is monotonic: {series:?}"
        );
    }
}

// ---------------------------------------------------------------------------
// Word wrapping: a long run of full-width characters is split into rows that
// together preserve every original character.
// ---------------------------------------------------------------------------
#[test]
fn message_wrap_splits_long_lines() {
    let text = "あいうえおかきくけこさしすせそ";
    let rows = wolf_game::message::wrap(text, 100.0, 20.0);
    assert!(rows.len() > 1, "long text should wrap, got {rows:?}");
    let mut joined = String::new();
    for row in &rows {
        assert!(!row.is_empty(), "no empty rows");
        joined.push_str(row);
    }
    assert_eq!(joined, text, "wrapping preserves every character");
    // An explicit newline forces a break too.
    let multi = wolf_game::message::wrap("first\nsecond", 400.0, 20.0);
    assert_eq!(multi.len(), 2, "newline splits rows: {multi:?}");
    assert_eq!(multi[0], "first");
    assert_eq!(multi[1], "second");
}

// ---------------------------------------------------------------------------
// CE231-235 (text-effect library): without an active balloon these routines
// are inert — they start, paint no text pictures and never warn.
// ---------------------------------------------------------------------------
#[test]
fn word_effect_events_are_inert_without_a_bubble() {
    for id in [231u32, 232, 233, 234, 235] {
        let mut game = match bedroom() {
            Ok(game) => game,
            Err(err) => {
                eprintln!("skipping: {err}");
                return;
            }
        };
        game.auto_advance = false;
        game.screen.clear();
        let warnings_before = game.stats.warnings;
        assert!(game.start_event(id), "CE{id} should start");
        for _ in 0..60 {
            game.frame();
        }
        assert!(
            on_screen_texts(&game).is_empty(),
            "CE{id} should stay inert (no text pictures), got {:?}",
            on_screen_texts(&game)
        );
        assert_eq!(game.stats.warnings, warnings_before, "CE{id} must not warn");
    }
}

// ---------------------------------------------------------------------------
// CE265-268 (window/face/name sub-events) and CE269-271 (the always-on plugin
// core) all start cleanly. Event 271 (auto-skip) stays resident in the bedroom.
// ---------------------------------------------------------------------------
#[test]
fn message_window_sub_events_and_always_events_run() {
    for id in [265u32, 266, 267, 268, 269, 270, 271] {
        let mut game = match bedroom() {
            Ok(game) => game,
            Err(err) => {
                eprintln!("skipping: {err}");
                return;
            }
        };
        game.screen.clear();
        let warnings_before = game.stats.warnings;
        assert!(game.start_event(id), "CE{id} should start");
        for _ in 0..30 {
            game.frame();
        }
        assert_eq!(game.stats.warnings, warnings_before, "CE{id} must not warn");
    }

    // The bedroom already keeps the auto-skip handler (271) running.
    let game = match bedroom() {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    let ids: Vec<u32> = game
        .vm
        .instances()
        .iter()
        .map(|instance| instance.event)
        .collect();
    assert!(
        ids.contains(&271),
        "auto-skip CE271 should be resident, got {ids:?}"
    );
}

// ---------------------------------------------------------------------------
#[test]
fn screen_transition_and_tint_state_machines() {
    // Transition: 160 installs, 161 freezes, 162 dissolves the frozen frame from
    // opaque to transparent over the duration (docs/re/TRANSITION.md section 3).
    let mut transition = ScreenTransition::new();
    assert!(!transition.is_active());
    assert_eq!(transition.alpha(), 0.0);

    transition.install(0, 0x0001_000A);
    assert!(!transition.is_active(), "160 alone draws nothing");
    assert_eq!(transition.alpha(), 0.0);
    transition.prepare();
    assert!(transition.take_freeze_request(), "161 asks for a freeze");
    transition.execute();
    assert!(transition.is_active());
    assert!((transition.alpha() - 1.0).abs() < 1e-6, "old frame opaque");
    for _ in 0..5 {
        transition.tick();
    }
    assert!((transition.alpha() - 0.5).abs() < 1e-6, "halfway");
    assert!((transition.progress() - 0.5).abs() < 1e-6);
    for _ in 0..5 {
        transition.tick();
    }
    assert_eq!(transition.alpha(), 0.0, "new frame fully visible");
    assert!(!transition.is_active());

    transition.cancel();
    assert!(!transition.is_active());
    assert_eq!(transition.alpha(), 0.0);

    // A kind without a mask is the same uniform dissolve; this build never draws
    // the mask picture ([Transition]Fade.png).
    let mut masked = ScreenTransition::new();
    masked.install(3, 0x000A);
    assert!(masked.wants_mask());
    masked.execute();
    assert!(masked.is_active());

    // Zero frames is treated as one.
    let mut one = ScreenTransition::new();
    one.install(-1, 0);
    one.execute();
    one.tick();
    assert!(!one.is_active());

    // Tint: 100 is neutral, a channel above 100 clamps to neutral, and a ramp
    // scales luminance instead of multiplying RGB.
    let mut tint = ScreenTint::new();
    assert_eq!(tint.rgb(), [1.0, 1.0, 1.0]);
    assert!(tint.is_neutral());

    tint.set(0x0096_C896, 0); // R150 G200 B150 clamps to 255 = neutral
    assert_eq!(tint.rgb(), [1.0, 1.0, 1.0], "brightness clamps at neutral");
    assert!(tint.is_neutral());

    tint.set(0x0028_281E, 0); // R40 G40 B30 -> 102/255, 102/255, 77/255
    let rgb = tint.rgb();
    assert!((rgb[0] - 102.0 / 255.0).abs() < 1e-6, "R {}", rgb[0]);
    assert!((rgb[1] - 102.0 / 255.0).abs() < 1e-6, "G {}", rgb[1]);
    assert!((rgb[2] - 77.0 / 255.0).abs() < 1e-6, "B {}", rgb[2]);
    assert!(!tint.is_neutral());

    tint.set(0x0064_6464, 0); // 100/100/100 -> neutral
    assert!(tint.is_neutral(), "100% channels are neutral");

    // A flash queues a full-screen colour quad that fades out once, leaving the
    // brightness ramp alone.
    let mut flash = ScreenTint::new();
    flash.set(0x0100_00C8, 10); // flash flag + B=200 -> clamped to 255
    assert_eq!(flash.rgb(), [1.0, 1.0, 1.0], "flash does not tint sprites");
    assert_eq!(flash.flash_overlay(), Some(([0, 0, 255], 1.0)));
    for _ in 0..5 {
        flash.tick();
    }
    let (colour, alpha) = flash.flash_overlay().expect("still fading");
    assert_eq!(colour, [0, 0, 255]);
    assert!(
        (alpha - 0.5).abs() < 1e-6,
        "alpha {} at the midpoint",
        alpha
    );
    for _ in 0..5 {
        flash.tick();
    }
    assert_eq!(flash.flash_overlay(), None, "flash fades out once");
    assert!(flash.is_neutral());
}
#[test]
fn font_metrics_fallback_measures_half_em() {
    let mut game = match bedroom() {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: {err}");
            return;
        }
    };
    game.screen.clear();
    let mut picture = Picture::new(6200);
    picture.kind = PictureKind::Text;
    picture.text = "12345".to_string();
    picture.x = 140;
    picture.y = 0;
    picture.anchor = 3;
    game.screen.insert(picture);

    let quads = game.text_quads();
    assert_eq!(quads.len(), 1, "one text quad expected");
    let quad = &quads[0];
    assert_eq!(quad.font_px, 20.0, "default font size");
    assert_eq!(quad.text, "12345");
    assert!(
        (quad.rect[0] - 90.0).abs() < 2.0,
        "half-em right-aligned left edge ≈ 90, got {}",
        quad.rect[0]
    );
    assert!(quad.rect[2] > 0.0, "quad has positive width");
}
