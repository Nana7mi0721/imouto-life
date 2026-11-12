//! M17 UI regressions: visible picture hit boxes, message click priority and
//! night-HUD visibility.
//!
//! These tests use the shipped `SaveData01` and `SampleMapA.mps` when
//! `WOLF_DATA_ROOT` is present. Without data they print a skip line and return,
//! matching the rest of the data-driven suite.

use std::path::PathBuf;

use wolf_format::mps::Map;
use wolf_game::{key, Atlas, Game};

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

fn open_loaded() -> Option<Game> {
    let root = data_root();
    let save = root.join("Save").join("SaveData01.sav");
    if !save.is_file() {
        eprintln!("skipping: no SaveData01 under {}", root.display());
        return None;
    }
    let mut game = match Game::new(root) {
        Ok(game) => game,
        Err(err) => {
            eprintln!("skipping: cannot open data root: {err}");
            return None;
        }
    };
    if let Err(err) = game.load_save(&save) {
        eprintln!("skipping: cannot load SaveData01: {err}");
        return None;
    }
    game.auto_advance = false;
    game.auto_choice = false;
    Some(game)
}

fn map_with(events: &[u32]) -> Option<Map> {
    let path = data_root().join("MapData").join("SampleMapA.mps");
    let bytes = std::fs::read(&path).ok()?;
    let mut map = Map::parse(&bytes).ok()?;
    map.events.retain(|event| events.contains(&event.id));
    Some(map)
}

fn loaded_with(events: &[u32]) -> Option<Game> {
    let mut game = open_loaded()?;
    let map = map_with(events)?;
    game.start_pages(&map, None);
    Some(game)
}

fn click_at(game: &mut Game, x: i32, y: i32) {
    game.mouse = [x, y];
    game.frame();
    game.mouse_buttons = 1;
    game.frame();
    game.mouse_buttons = 0;
    for _ in 0..4 {
        game.frame();
    }
}

fn visible(game: &Game, number: i32) -> bool {
    game.screen
        .get(number)
        .is_some_and(|picture| !picture.hidden && picture.opacity > 0)
}

fn assert_panel_visible(game: &Game, number: i32, x: i32, context: &str) {
    let picture = game
        .screen
        .get(number)
        .unwrap_or_else(|| panic!("{context}: missing panel picture {number}"));
    assert!(!picture.hidden, "{context}: panel {number} became hidden");
    assert_eq!(picture.x, x, "{context}: panel {number} moved");
    assert_eq!(
        picture.opacity, 255,
        "{context}: panel {number} opacity changed"
    );
    assert!(
        picture.alpha() > 0.0,
        "{context}: panel {number} became fully transparent"
    );
}

fn open_event_one_balloon() -> Option<Game> {
    let root = data_root();
    if !root.join("BasicData").join("CommonEvent.dat").is_file() {
        eprintln!("skipping: no WOLF data at {root:?}");
        return None;
    }
    let mut game = Game::new(root.clone()).ok()?;
    game.prime_engine();
    let save = root.join("Save").join("SaveData01.sav");
    if let Err(err) = game.load_save(&save) {
        eprintln!("skipping: cannot load SaveData01: {err}");
        return None;
    }
    game.auto_advance = false;
    game.screen.clear();
    game.messages.clear();
    let bytes = std::fs::read(root.join("MapData").join("SampleMapA.mps")).ok()?;
    let mut map = Map::parse(&bytes).ok()?;
    map.events.retain(|event| event.id == 1);
    game.start_pages(&map, None);
    assert!(game.start_map_event(&map, 1), "Event 1 starts");
    Some(game)
}

#[test]
fn balloon_face_stays_anchored_when_the_frame_grows() {
    let Some(mut game) = open_event_one_balloon() else {
        return;
    };
    let mut atlas = Atlas::with_size(2048, 4096);
    let mut one_line = None;
    for frame in 0..120 {
        game.frame();
        let _ = game.picture_quads(&mut atlas);
        let _ = game.text_quads();
        let face_visible = game
            .screen
            .get(36002)
            .is_some_and(|picture| !picture.hidden && picture.opacity > 0);
        if !face_visible {
            continue;
        }
        let screen = &game.screen;
        let assets = &mut game.assets;
        let frame_rect = screen
            .picture_rect(36000, |file| assets.texture_size(file))
            .expect("one-line balloon frame");
        let face_rect = screen
            .picture_rect(36002, |file| assets.texture_size(file))
            .expect("one-line balloon face");
        one_line = Some((frame, frame_rect, face_rect));
        break;
    }
    let (_, one_line_frame, one_line_face) =
        one_line.expect("event 1 never exposed the balloon face");
    assert_eq!(
        one_line_face[1] + one_line_face[3],
        one_line_frame[1] + one_line_frame[3] + 38.0,
        "the one-line face extends 38 px below the balloon bottom"
    );

    let message = game
        .messages
        .last_mut()
        .expect("event 1 must leave a live message");
    message.text = "第一行文字\n第二行文字\n第三行文字".to_owned();
    message.frames = 0;
    let mut three_line = None;
    for frame in 120..280 {
        game.frame();
        let _ = game.picture_quads(&mut atlas);
        let _ = game.text_quads();
        let body_visible = game.screen.get(36013).is_some_and(|body| {
            !body.hidden && body.text.contains("第三行文字") && body.opacity > 0
        });
        if !body_visible {
            continue;
        }
        let screen = &game.screen;
        let assets = &mut game.assets;
        let frame_rect = screen
            .picture_rect(36000, |file| assets.texture_size(file))
            .expect("three-line balloon frame");
        let face_rect = screen
            .picture_rect(36002, |file| assets.texture_size(file))
            .expect("three-line balloon face");
        three_line = Some((frame, frame_rect, face_rect));
        break;
    }
    let (_, three_line_frame, three_line_face) =
        three_line.expect("the synthetic third line never reached 36013");
    assert!(
        three_line_frame[3] >= 79.0,
        "the three-line frame must grow upward: {three_line_frame:?}"
    );
    assert!(
        (three_line_frame[1] + three_line_frame[3] - one_line_frame[1] - one_line_frame[3]).abs()
            <= 1.0,
        "the bubble bottom must stay fixed: one={one_line_frame:?}, three={three_line_frame:?}"
    );
    assert_eq!(
        three_line_face, one_line_face,
        "the face is bottom-anchored and must not move with the body height"
    );
}

#[test]
fn visible_picture_ink_is_the_save_and_data_hit_box() {
    let Some(mut game) = loaded_with(&[5]) else {
        return;
    };
    assert_eq!(
        game.screen.get(-5).map(|p| (p.x, p.y, p.file.as_str())),
        Some((10, 510, "Picture/icon01.png"))
    );
    let rect = {
        let screen = &game.screen;
        let assets = &mut game.assets;
        screen
            .picture_rect(-5, |file| assets.texture_size(file))
            .expect("save icon rectangle")
    };
    assert_eq!(rect, [10.0, 510.0, 80.0, 60.0]);

    // Inside ev5's old tile rectangle but outside the visible 80x60 icon.
    click_at(&mut game, 94, 590);
    assert_eq!(
        game.last_action_event, None,
        "the old tile box must not fire outside the save icon"
    );

    // (12,512) is the transparent top-left corner of the 80x60 canvas; the art
    // begins eight pixels lower and six pixels further right.
    click_at(&mut game, 12, 512);
    assert_eq!(
        game.last_action_event, None,
        "a transparent corner of the save canvas is not a button"
    );

    // Inside the visible ink, outside ev5's old tile box.
    click_at(&mut game, 25, 535);
    assert_eq!(
        game.last_action_event,
        Some(5),
        "the save icon itself must activate ev5"
    );

    let Some(mut game) = loaded_with(&[30]) else {
        return;
    };
    assert_eq!(
        game.screen.get(-4).map(|p| (p.x, p.y, p.file.as_str())),
        Some((925, 507, "Picture/icon05.png"))
    );
    let rect = {
        let screen = &game.screen;
        let assets = &mut game.assets;
        screen
            .picture_rect(-4, |file| assets.texture_size(file))
            .expect("data icon rectangle")
    };
    assert_eq!(rect, [925.0, 507.0, 80.0, 60.0]);

    // Inside ev30's old tile rectangle but outside the visible icon.
    click_at(&mut game, 1035, 590);
    assert_eq!(
        game.last_action_event, None,
        "the old tile box must not fire outside the data icon"
    );

    // The corner pixel belongs to the transparent canvas, not the data icon.
    click_at(&mut game, 926, 508);
    assert_eq!(
        game.last_action_event, None,
        "a transparent corner of the data canvas is not a button"
    );

    // Inside the visible ink, outside ev30's old tile box.
    click_at(&mut game, 950, 530);
    assert_eq!(
        game.last_action_event,
        Some(30),
        "the data icon itself must activate ev30"
    );
}

fn night_game() -> Option<Game> {
    let mut game = loaded_with(&[5, 15, 16, 17, 18, 19, 20, 21, 23, 26])?;
    game.vm.vars.set(100, 1);
    game.vm.vars.set(125, 0);
    game.vm.vars.set(18, 32);
    game.vm.vars.set(19, 32);
    assert!(game.start_event(230), "CE230 must start");
    Some(game)
}

fn press_ok_until(game: &mut Game, frames: usize, mut done: impl FnMut(&Game) -> bool) -> bool {
    for _ in 0..frames {
        game.frame();
        if done(game) {
            return true;
        }
        if !game.messages.is_empty() {
            game.key_bits = key::OK;
            game.frame();
            game.key_bits = 0;
        }
    }
    false
}

#[test]
fn night_message_click_is_not_eaten_by_parallel_pollers() {
    let Some(mut game) = night_game() else {
        return;
    };

    let notice = |game: &Game| {
        game.messages
            .iter()
            .any(|message| message.text.contains("深夜模式全部由光标操作"))
    };
    let mut seen = false;
    for _ in 0..700 {
        game.frame();
        if notice(&game) {
            seen = true;
            break;
        }
        if !game.messages.is_empty() {
            click_at(&mut game, 512, 288);
        }
    }
    assert!(seen, "the first-night system notice did not appear");

    click_at(&mut game, 512, 288);
    for _ in 0..5 {
        game.frame();
    }
    assert!(
        !notice(&game),
        "a click on the visible notice must dismiss it before script key polls"
    );
}

#[test]
fn night_end_button_uses_its_picture_and_hides_the_data_icon() {
    let Some(mut game) = night_game() else {
        return;
    };
    assert!(
        press_ok_until(&mut game, 700, |game| visible(game, 1108)),
        "the night UI never drew the end button"
    );
    assert_eq!(
        game.screen.get(1108).map(|p| p.file.as_str()),
        Some("Picture/endbutton.png")
    );
    let rect = {
        let screen = &game.screen;
        let assets = &mut game.assets;
        screen
            .picture_rect(1108, |file| assets.texture_size(file))
            .expect("end button rectangle")
    };
    assert_eq!(
        rect,
        [935.0, 505.0, 90.0, 70.0],
        "the end hit box must be its picture canvas"
    );
    assert!(
        game.screen.get(-4).is_none_or(|picture| picture.hidden),
        "the data icon must not leak through the end arrow"
    );

    // Inside ev21's old tile box but outside the 90x70 end picture.
    click_at(&mut game, 1060, 590);
    assert_eq!(
        game.last_action_event, None,
        "the old ev21 tile box must not fire outside the end picture"
    );

    // Inside the end picture, outside ev21's old tile box. This point also
    // overlaps the data picture; 1108 is later in draw order and must win.
    click_at(&mut game, 940, 510);
    assert_eq!(
        game.last_action_event,
        Some(21),
        "clicking the end arrow must activate ev21"
    );
}

#[test]
fn night_end_button_center_starts_the_end_page() {
    let Some(mut game) = night_game() else {
        return;
    };
    assert!(
        press_ok_until(&mut game, 700, |game| visible(game, 1108)),
        "the night UI never drew the end button"
    );
    let screen = &game.screen;
    let assets = &mut game.assets;
    let rect = screen
        .picture_rect(1108, |file| assets.texture_size(file))
        .expect("end button rectangle");
    let x = (rect[0] + rect[2] / 2.0) as i32;
    let y = (rect[1] + rect[3] / 2.0) as i32;
    click_at(&mut game, x, y);
    assert_eq!(
        game.last_action_event,
        Some(21),
        "the center of the visible end arrow must activate ev21"
    );
}

#[test]
fn negative_bad_bar_scale_keeps_a_nonzero_geometry_and_hit_box() {
    let Some(mut game) = open_loaded() else {
        return;
    };
    assert!(game.start_event(237), "CE237 must start");
    for _ in 0..30 {
        game.frame();
    }

    for number in [1996, 1998] {
        let picture = game.screen.get(number).expect("BAD bar slot");
        assert_eq!(picture.scale, -100, "slot {number} keeps the retail scale");
    }
    let screen = &game.screen;
    let assets = &mut game.assets;
    for (number, anchor) in [(1996, 490.0), (1998, 491.0)] {
        let rect = screen
            .picture_rect(number, |file| assets.texture_size(file))
            .unwrap_or_else(|| panic!("slot {number} has no rect"));
        assert!(
            rect[2] > 0.0 && rect[3] > 0.0,
            "negative scale collapsed slot {number}: {rect:?}"
        );
        assert!(
            (rect[0] + rect[2] - anchor).abs() < 0.01,
            "slot {number} must mirror left up to its x={anchor} anchor, got {rect:?}"
        );
        assert!(
            rect[0] < 280.0,
            "slot {number} must reach the BAD label at x=280, got {rect:?}"
        );
    }

    let screen = &game.screen;
    let assets = &mut game.assets;
    let quads = screen.quads(|file| assets.texture_size(file));
    for number in [1996, 1998] {
        let quad = quads
            .iter()
            .find(|quad| quad.number == number)
            .unwrap_or_else(|| panic!("slot {number} must produce a visible quad"));
        assert!(
            quad.dst[2] > 0.0 && quad.dst[3] > 0.0,
            "slot {number} must not collapse in the draw list: {:?}",
            quad.dst
        );
        assert!(
            quad.dst[0] < 280.0,
            "slot {number} must still cover the BAD gauge: {:?}",
            quad.dst
        );
    }
}

#[test]
fn album_icon_uses_its_visible_picture_ink() {
    let Some(mut game) = loaded_with(&[32, 35]) else {
        return;
    };
    game.vm.vars.set(237, 1);
    for _ in 0..4 {
        game.frame();
    }
    assert_eq!(
        game.screen.get(-7).map(|p| (p.x, p.y, p.file.as_str())),
        Some((925, 430, "Picture/icon06.png"))
    );

    let screen = &game.screen;
    let assets = &mut game.assets;
    let rect = screen
        .picture_rect(-7, |file| assets.texture_size(file))
        .expect("album icon rectangle");
    assert_eq!(rect, [925.0, 430.0, 80.0, 60.0]);

    click_at(&mut game, 926, 431);
    assert_eq!(
        game.last_action_event, None,
        "the transparent canvas corner must not reach a map hotspot"
    );
    assert!(
        !game
            .vm
            .instances()
            .iter()
            .any(|instance| instance.event == 303),
        "the transparent canvas corner must not start the album"
    );

    click_at(&mut game, 1020, 570);
    assert_eq!(
        game.last_action_event, None,
        "a click in the old screen-sized album box must not start the album"
    );
    assert!(
        !game
            .vm
            .instances()
            .iter()
            .any(|instance| instance.event == 303),
        "the album must remain closed outside its visible icon"
    );

    let x = (rect[0] + rect[2] / 2.0) as i32;
    let y = (rect[1] + rect[3] / 2.0) as i32;
    click_at(&mut game, x, y);
    assert!(
        game.vm
            .instances()
            .iter()
            .any(|instance| instance.event == 303),
        "clicking the visible album icon must start CE303"
    );
}

#[test]
fn overlapping_album_and_data_icons_use_the_topmost_picture() {
    let Some(mut game) = loaded_with(&[30, 32]) else {
        return;
    };
    game.vm.vars.set(237, 1);
    for _ in 0..4 {
        game.frame();
    }

    let (album_x, album_y) = {
        let album = game.screen.get(-7).expect("visible album icon");
        (album.x, album.y)
    };
    let (data_x, data_y) = {
        let data = game.screen.get(-4).expect("visible data icon");
        (data.x, data.y)
    };
    assert_eq!(
        (album_x, album_y),
        (925, 430),
        "album icon moved from its shipped position"
    );
    assert_eq!(
        (data_x, data_y),
        (925, 507),
        "data icon moved from its shipped position"
    );

    {
        let album = game.screen.get_mut(-7).expect("album picture");
        album.x = data_x;
        album.y = data_y;
    }
    click_at(&mut game, data_x + 40, data_y + 30);
    assert_eq!(
        game.last_action_event,
        Some(30),
        "the higher data icon slot must own an overlapping album click"
    );
    assert!(
        !game
            .vm
            .instances()
            .iter()
            .any(|instance| instance.event == 303),
        "the lower album icon must not start CE303 through the overlap"
    );
}

#[test]
fn night_notice_dismissal_restores_the_save_icon_click() {
    let Some(mut game) = night_game() else {
        return;
    };
    assert!(
        press_ok_until(&mut game, 700, |game| visible(game, 1108)),
        "the night HUD never became interactive"
    );
    assert!(
        visible(&game, -5),
        "the save icon must remain visible during the night UI"
    );

    let screen = &game.screen;
    let assets = &mut game.assets;
    let rect = screen
        .picture_rect(-5, |file| assets.texture_size(file))
        .expect("save icon rectangle");
    let x = (rect[0] + rect[2] / 2.0) as i32;
    let y = (rect[1] + rect[3] / 2.0) as i32;
    click_at(&mut game, x, y);
    assert_eq!(
        game.last_action_event,
        Some(5),
        "the save icon must still open its action page after the first-night notice"
    );
}

#[test]
fn night_save_icon_opens_from_the_touch_page() {
    let Some(mut game) = night_game() else {
        return;
    };
    assert!(
        press_ok_until(&mut game, 700, |game| visible(game, 1108)),
        "the night UI never drew the end button"
    );
    assert!(
        visible(&game, -5),
        "the save icon must remain visible on the night touch page"
    );

    let screen = &game.screen;
    let assets = &mut game.assets;
    let rect = screen
        .picture_rect(-5, |file| assets.texture_size(file))
        .expect("save icon rectangle");
    let x = (rect[0] + rect[2] / 2.0) as i32;
    let y = (rect[1] + rect[3] / 2.0) as i32;
    click_at(&mut game, x, y);
    assert_eq!(
        game.last_action_event,
        Some(5),
        "the save icon must open its action page from the night touch page"
    );
    assert!(
        game.vm
            .instances()
            .iter()
            .any(|instance| instance.event == 131),
        "the save screen CE131 must start from the night touch page"
    );
}

#[test]
fn hidden_save_icon_does_not_fall_back_to_the_old_tile_box() {
    let Some(mut game) = loaded_with(&[5]) else {
        return;
    };
    game.screen.get_mut(-5).expect("save icon slot").hidden = true;

    // (50,540) is inside ev5's old 64x64 tile rectangle but there is no visible
    // save icon there now. A hidden picture-only control must not be resurrected.
    click_at(&mut game, 50, 540);
    assert_eq!(
        game.last_action_event, None,
        "a hidden save icon fell back to its old map tile rectangle"
    );
}

#[test]
fn side_panel_handles_open_toggle_and_stay_stable() {
    let Some(mut game) = loaded_with(&[7, 8, 10, 11]) else {
        return;
    };
    assert_eq!(
        game.vm.vars.get(15),
        0,
        "the shipped save keeps v15 at zero"
    );
    assert_eq!(
        game.screen.get(320).map(|picture| picture.x),
        Some(-305),
        "status panel starts parked off the left edge"
    );

    click_at(&mut game, 15, 137);
    assert_eq!(
        game.last_action_event,
        Some(10),
        "the status triangle must open CE238"
    );
    for _ in 0..30 {
        game.frame();
    }
    assert_panel_visible(&game, 320, 0, "after status slide-in");

    // The drawer is click-to-toggle. Events 8/11 still poll hover every frame,
    // but an open panel reports a stable hover so it cannot blink shut while the
    // pointer crosses its transparent interior.
    for (frame, mouse) in [[600, 192], [320, 137], [0, 500], [512, 288], [15, 137]]
        .into_iter()
        .cycle()
        .take(120)
        .enumerate()
    {
        game.mouse = mouse;
        game.frame();
        assert_panel_visible(
            &game,
            320,
            0,
            &format!("status panel frame {frame} at mouse {mouse:?}"),
        );
    }
    assert_eq!(game.vm.vars.get(15), 0, "the UI bridge must not fake v15");

    // The handle moved to the opened panel's right edge. Clicking it again is
    // the explicit close action.
    click_at(&mut game, 320, 137);
    for _ in 0..30 {
        game.frame();
    }
    assert_panel_visible(&game, 320, -305, "after status close");
}

#[test]
fn status_and_item_handles_are_independent_and_mutually_exclusive() {
    let Some(mut game) = loaded_with(&[7, 8, 10, 11]) else {
        return;
    };
    click_at(&mut game, 15, 279);
    assert_eq!(
        game.last_action_event,
        Some(7),
        "the lower triangle must own the item drawer"
    );
    for _ in 0..30 {
        game.frame();
    }
    assert_panel_visible(&game, 2300, 0, "after item slide-in");
    game.mouse = [600, 192];
    for frame in 0..60 {
        game.frame();
        assert_panel_visible(&game, 2300, 0, &format!("item panel frame {frame}"));
    }

    // Opening status explicitly closes the item drawer first.
    click_at(&mut game, 15, 137);
    for _ in 0..30 {
        game.frame();
    }
    assert_panel_visible(&game, 320, 0, "after opening status over item");
    assert_panel_visible(
        &game,
        2300,
        -305,
        "opening status must retract the item drawer",
    );

    // Opening item closes status through CE239's own op210 call.
    click_at(&mut game, 15, 279);
    for _ in 0..30 {
        game.frame();
    }
    assert_panel_visible(&game, 2300, 0, "after opening item over status");
    assert_panel_visible(
        &game,
        320,
        -305,
        "opening item must retract the status drawer",
    );
}

#[test]
fn every_visible_part_of_the_side_handle_is_clickable() {
    for (x, y) in [(0, 118), (0, 156), (4, 137), (24, 137)] {
        let Some(mut game) = loaded_with(&[7, 8, 10, 11]) else {
            return;
        };
        click_at(&mut game, x, y);
        for _ in 0..30 {
            game.frame();
        }
        assert_panel_visible(&game, 320, 0, &format!("status handle at ({x},{y})"));
        click_at(&mut game, 320, y);
        for _ in 0..30 {
            game.frame();
        }
        assert_panel_visible(&game, 320, -305, &format!("status close after ({x},{y})"));
    }

    for (x, y) in [(0, 260), (0, 296), (4, 279), (24, 279)] {
        let Some(mut game) = loaded_with(&[7, 8, 10, 11]) else {
            return;
        };
        click_at(&mut game, x, y);
        for _ in 0..30 {
            game.frame();
        }
        assert_panel_visible(&game, 2300, 0, &format!("item handle at ({x},{y})"));
        click_at(&mut game, 320, y);
        for _ in 0..30 {
            game.frame();
        }
        assert_panel_visible(&game, 2300, -305, &format!("item close after ({x},{y})"));
    }
}

fn bedroom_with_standing_art() -> Option<Game> {
    let mut game = loaded_with(&[1, 2, 3, 4, 25])?;
    game.vm.vars.common_self.remove(&240);
    assert!(game.start_event(240), "CE240 must start");
    for _ in 0..30 {
        game.frame();
    }
    assert!(visible(&game, 900), "the sister body layer must be visible");
    Some(game)
}

#[test]
fn bedroom_standing_art_maps_v14_to_the_action_events() {
    for (pose, event) in [(0, 1), (1, 2), (2, 3), (3, 4), (6, 25)] {
        let Some(mut game) = bedroom_with_standing_art() else {
            return;
        };
        game.vm.vars.set(14, pose);
        game.vm.vars.set(23, 0);
        game.vm.vars.set(100, 0);
        game.vm.vars.set(176, 0);
        game.vm.vars.set(238, 0);
        for _ in 0..2 {
            game.frame();
        }

        let screen = &game.screen;
        let assets = &mut game.assets;
        let rect = screen
            .picture_rect(900, |file| assets.texture_size(file))
            .expect("visible body rectangle");
        let x = (rect[0] + rect[2] / 2.0) as i32;
        let y = (rect[1] + rect[3] / 2.0) as i32;
        click_at(&mut game, x, y);
        assert_eq!(
            game.last_action_event,
            Some(event),
            "v14={pose} must route the standing-art click to ev{event}"
        );
    }
}

#[test]
fn bedroom_standing_art_gates_outside_pixels_and_deep_night() {
    let Some(mut game) = bedroom_with_standing_art() else {
        return;
    };
    game.vm.vars.set(14, 0);
    game.vm.vars.set(23, 0);
    game.vm.vars.set(100, 0);
    game.vm.vars.set(176, 0);
    game.vm.vars.set(238, 0);
    for _ in 0..2 {
        game.frame();
    }
    let screen = &game.screen;
    let assets = &mut game.assets;
    let rect = screen
        .picture_rect(900, |file| assets.texture_size(file))
        .expect("visible body rectangle");

    click_at(&mut game, rect[0] as i32 - 1, 300);
    assert_eq!(
        game.last_action_event, None,
        "one pixel left of the standing art must not trigger the sister"
    );

    game.vm.vars.set(100, 1);
    let x = (rect[0] + rect[2] / 2.0) as i32;
    let y = (rect[1] + rect[3] / 2.0) as i32;
    click_at(&mut game, x, y);
    assert_eq!(
        game.last_action_event, None,
        "deep-night controls must keep ownership of the standing art"
    );
}
