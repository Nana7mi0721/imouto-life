//! M3-AA regression: stat / collection / album panels (task-33).
//!
//! Covers CE296 (■プレイ傾向), CE301 (アルバム表示 drawer) and CE303
//! (アルバム画面呼び出し).  Only drawing / toggling / cancel is exercised;
//! no save file is written (Save directory fingerprint is compared).
//!
//! Expected strings are measured from work/Data SaveData01, not copied from a
//! sibling game's BASELINE.

use std::collections::BTreeMap;
use std::fs;
use std::path::PathBuf;
use std::time::UNIX_EPOCH;

use wolf_game::{savegame, Game};

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let p = PathBuf::from(raw);
    if p.is_absolute() {
        return p;
    }
    let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    base.pop();
    base.pop();
    base.join(p)
}

/// Strip WOLF inline escape sequences (command name = ASCII letters, optional
/// \`[args]\`) leaving only the human visible text.
fn visible(raw: &str) -> String {
    let mut out = String::new();
    let mut it = raw.chars().peekable();
    while let Some(c) = it.next() {
        if (c as u32) != 92 {
            out.push(c);
            continue;
        }
        while let Some(&ch) = it.peek() {
            if ch.is_ascii_alphabetic() {
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

/// Load SaveDataNN, run to a stable bedroom HUD.  Returns None (skip) when the
/// data root or save file is absent.
fn load_stable(slot: u32) -> Option<Game> {
    let path = data_root().join(format!("Save/SaveData{slot:02}.sav"));
    if !path.is_file() {
        eprintln!("skipping: {} not found", path.display());
        return None;
    }
    let mut game = Game::new(data_root()).ok()?;
    savegame::load_into(&mut game, &path).ok()?;
    game.auto_advance = true;
    game.auto_choice = false;
    for _ in 0..1600 {
        game.frame();
    }
    Some(game)
}

fn running_event(game: &Game, id: u32) -> bool {
    game.vm.instances().iter().any(|i| i.event == id)
}

fn slot_numbers(game: &Game) -> Vec<i32> {
    let mut v: Vec<i32> = game.screen.iter().map(|p| p.number).collect();
    v.sort_unstable();
    v
}

fn slot_text(game: &Game) -> BTreeMap<i32, String> {
    game.screen
        .iter()
        .map(|p| (p.number, visible(&p.text)))
        .filter(|(_, t)| !t.is_empty())
        .collect()
}

fn slot_files(game: &Game) -> BTreeMap<i32, String> {
    game.screen
        .iter()
        .filter(|p| !p.file.is_empty())
        .map(|p| (p.number, p.file.clone()))
        .collect()
}

/// Hold a key bitmask for N frames then release, to let the event poller see a
/// long press (2-frame pulses are sometimes missed by CE303/CE131).
fn hold_key(game: &mut Game, bits: u32, frames: u32) {
    game.key_bits = bits;
    for _ in 0..frames {
        game.frame();
    }
    game.key_bits = 0;
    for _ in 0..6 {
        game.frame();
    }
}

/// Fingerprint of every regular file in Save/ (name, size, mtime nanos).  Used
/// to prove these UI tests never touch the user's save data.
fn save_fingerprint() -> Vec<(String, u64, u128)> {
    let dir = data_root().join("Save");
    let mut out = Vec::new();
    if let Ok(rd) = fs::read_dir(&dir) {
        for entry in rd.flatten() {
            if let Ok(md) = entry.metadata() {
                if md.is_file() {
                    let name = entry.file_name().to_string_lossy().into_owned();
                    let mtime = md
                        .modified()
                        .ok()
                        .and_then(|t| t.duration_since(UNIX_EPOCH).ok())
                        .map(|d| d.as_nanos())
                        .unwrap_or(0);
                    out.push((name, md.len(), mtime));
                }
            }
        }
    }
    out.sort();
    out
}

fn expect_text(texts: &BTreeMap<i32, String>, slot: i32) -> &str {
    texts.get(&slot).unwrap_or_else(|| {
        panic!(
            "slot {slot} not drawn; available text slots: {:?}",
            texts.keys().collect::<Vec<_>>()
        )
    })
}

// ---------------------------------------------------------------------------
// CE296 — ■プレイ傾向 statistics panel.
//
// Event script maps (2_000_000+n == ordinary variable n):
//   400  職業       op6   111 [17,2000200,0,2]  → var[200]==0 branch
//   401  日数       op238 111 var[99] <= 3/15/30 → 1 day picks "才刚刚开始"
//   412  信頼       op209 111 var[20] >= 350/200/100 → else "复杂想法"
//   413  興味       op225 111 var[21] >= 200/100/0 → "H是不对的"
// SaveData01 values: var[200]=0, var[99]=1, var[20]=25, var[21]=10.
// ---------------------------------------------------------------------------
#[test]
fn ce296_status_items_align_with_variable_sources() {
    let Some(mut game) = load_stable(1) else {
        return;
    };
    let before = save_fingerprint();

    assert_eq!(game.vm.vars.get(200), 0, "400 source var[200]");
    assert_eq!(game.vm.vars.get(99), 1, "401 source var[99]");
    assert_eq!(game.vm.vars.get(20), 25, "412 source var[20]");
    assert_eq!(game.vm.vars.get(21), 10, "413 source var[21]");

    game.screen.clear();
    assert!(game.start_event(296), "CE296 start failed");
    for _ in 0..30 {
        game.frame();
    }

    let texts = slot_text(&game);
    assert_eq!(
        expect_text(&texts, 400),
        "两人以妹妹升学为契机，\n以学生身份开始了同居生活。"
    );
    assert_eq!(expect_text(&texts, 401), "两个人的生活才刚刚开始……");
    assert_eq!(expect_text(&texts, 412), "妹妹好像对哥哥抱有复杂的想法。");
    assert_eq!(expect_text(&texts, 413), "妹妹似乎认为H是不对的。");

    // Exactly the four text lines this save takes; all share x=638 and a window.
    assert_eq!(slot_numbers(&game), vec![400, 401, 412, 413]);
    for slot in [400, 401, 412, 413] {
        let p = game.screen.get(slot).unwrap();
        assert_eq!(p.x, 638, "slot {slot} x");
        assert_eq!(p.opacity, 255, "slot {slot} opacity");
        assert_eq!(p.scale, 100, "slot {slot} scale");
        assert_eq!(p.window, Some((1, 1)), "slot {slot} window");
    }

    assert!(game.messages.is_empty(), "CE296 should emit no message");
    assert_eq!(game.stats.warnings, 0, "engine warnings");
    assert_eq!(
        save_fingerprint(),
        before,
        "Save directory must be untouched"
    );
}

// CE296 count items only appear when their source variables are non-zero.
//   402 パンツ   op44   var[202]==1
//   409 イった回数 op168 var[188]>=10
//   410 挿入経験   op155 var[139]>=10
//   411 肛門       op181 var[186]>=10
#[test]
fn ce296_count_items_follow_variables() {
    let Some(mut game) = load_stable(1) else {
        return;
    };

    for (id, value) in [(188usize, 10i32), (139, 10), (186, 10), (202, 1)] {
        game.vm.vars.set(id, value);
    }

    game.screen.clear();
    assert!(game.start_event(296), "CE296 start failed");
    for _ in 0..30 {
        game.frame();
    }

    let texts = slot_text(&game);
    assert_eq!(
        expect_text(&texts, 402),
        "将妹妹穿过的内衣全部换成同样的新品，真是辛苦。"
    );
    assert_eq!(
        expect_text(&texts, 409),
        "也有一整晚高潮到到奄奄一息的经历。"
    );
    assert_eq!(
        expect_text(&texts, 410),
        "两个人为了互相寻求而不断地交缠身体，"
    );
    assert_eq!(
        expect_text(&texts, 411),
        "现在已经完全习惯了使用屁穴的性行为。"
    );

    // The four unconditional lines remain present too.
    for slot in [400, 401, 412, 413] {
        assert!(texts.contains_key(&slot), "slot {slot} missing");
    }
    assert_eq!(game.stats.warnings, 0);
}

// ---------------------------------------------------------------------------
// CE301 — アルバム表示 drawing subroutine.  It reads the album index from its
// own self[0] variable (1_600_000) and is gated by var[248].  Called directly
// with no caller context it must draw/emit nothing and terminate.
// ---------------------------------------------------------------------------
#[test]
fn ce301_album_drawer_needs_caller_context() {
    let Some(mut game) = load_stable(1) else {
        return;
    };
    let before = save_fingerprint();

    game.screen.clear();
    assert!(game.start_event(301), "CE301 start failed");
    for _ in 0..30 {
        game.frame();
    }

    assert_eq!(game.screen.len(), 0, "CE301 standalone must draw nothing");
    assert!(
        game.messages.is_empty(),
        "CE301 standalone must emit no message"
    );
    assert!(
        !running_event(&game, 301),
        "CE301 standalone should terminate"
    );
    assert_eq!(game.stats.warnings, 0);
    assert_eq!(
        save_fingerprint(),
        before,
        "Save directory must be untouched"
    );
}

// ---------------------------------------------------------------------------
// CE303 — アルバム画面呼び出し album screen.
//
// Grid is driven by per-album collection flags in the event script:
//   slot 10  Picture/album_000.png  full-screen background (op 255)
//   slot 114 Picture/album_008.png  (329,249) thumbnail overlay (op 1)
//   slot 115 Picture/album_009.png  (470,249)
//   slot 116 Picture/album_010.png  (611,249)
//   slots 900-903 stand_* four-layer preview at (750,80)
// SaveData01 has only albums 008/009/010 collected, so only three thumbnails
// appear (no numeric "x/20" progress variable exists in the script; the grid
// itself is the collection state).
// var[238] is "アルバム表示中": 0 → 1 on start, 0 again after CANCEL.
// ---------------------------------------------------------------------------
#[test]
fn ce303_album_grid_flags_and_cancel_clears() {
    let Some(mut game) = load_stable(1) else {
        return;
    };
    let before = save_fingerprint();

    assert_eq!(game.vm.vars.get(238), 0, "var[238] before opening album");
    game.screen.clear();
    assert!(game.start_event(303), "CE303 start failed");
    for _ in 0..2 {
        game.frame();
    }

    assert_eq!(game.vm.vars.get(238), 1, "var[238] must be set while open");

    let files = slot_files(&game);
    assert_eq!(
        files.get(&10).map(String::as_str),
        Some("Picture/album_000.png")
    );
    let thumbnails = [
        (114, "Picture/album_008.png", 329, 249),
        (115, "Picture/album_009.png", 470, 249),
        (116, "Picture/album_010.png", 611, 249),
    ];
    for (slot, file, x, y) in thumbnails {
        let p = game
            .screen
            .get(slot)
            .unwrap_or_else(|| panic!("slot {slot} missing"));
        assert_eq!(p.file, file, "slot {slot} file");
        assert_eq!((p.x, p.y), (x, y), "slot {slot} position");
        assert_eq!(p.opacity, 1, "slot {slot} thumbnail overlay opacity");
        assert_eq!(p.scale, 100, "slot {slot} scale");
    }

    // Exactly the collected albums are on screen (no uncollected slots).
    let mut album_files: Vec<String> = files
        .values()
        .filter(|f| f.starts_with("Picture/album_"))
        .cloned()
        .collect();
    album_files.sort();
    assert_eq!(
        album_files,
        vec![
            "Picture/album_000.png",
            "Picture/album_008.png",
            "Picture/album_009.png",
            "Picture/album_010.png",
        ],
        "album grid must show only collected entries"
    );

    // Four-layer standing preview.
    let base = game.screen.get(900).expect("preview base slot 900");
    assert!(
        base.file.starts_with("Picture/stand_"),
        "preview base file {}",
        base.file
    );
    for (slot, file) in [
        (901, "Picture/stand_eye.png"),
        (902, "Picture/stand_mouth.png"),
        (903, "Picture/stand_eyebrow.png"),
    ] {
        let p = game
            .screen
            .get(slot)
            .unwrap_or_else(|| panic!("preview slot {slot}"));
        assert_eq!(p.file, file, "slot {slot}");
        assert_eq!((p.x, p.y), (750, 80), "slot {slot} position");
        assert_eq!(p.opacity, 255, "slot {slot} opacity");
    }

    // Let it settle: still running, grid unchanged (no pagination for 3 items).
    for _ in 0..118 {
        game.frame();
    }
    assert!(running_event(&game, 303), "album screen should stay open");
    let settled = slot_files(&game);
    for (slot, file, x, y) in thumbnails {
        let p = game
            .screen
            .get(slot)
            .unwrap_or_else(|| panic!("settled slot {slot}"));
        assert_eq!(p.file, file, "settled slot {slot} file");
        assert_eq!((p.x, p.y), (x, y), "settled slot {slot} position");
    }
    assert!(settled.contains_key(&10), "album background must persist");

    // CANCEL closes and clears the whole grid.
    hold_key(&mut game, wolf_game::key::CANCEL, 24);
    assert!(!running_event(&game, 303), "CE303 should close on CANCEL");
    assert_eq!(game.vm.vars.get(238), 0, "var[238] must reset after close");
    assert_eq!(game.screen.len(), 0, "album grid must be cleared");
    assert_eq!(game.stats.warnings, 0);
    assert_eq!(
        save_fingerprint(),
        before,
        "Save directory must be untouched"
    );
}
