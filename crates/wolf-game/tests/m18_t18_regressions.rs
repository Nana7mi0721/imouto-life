//! T18 regressions for the remaining balloon, hover, side-panel and atlas issues.
//!
//! Every data-dependent test prints a skip line and returns when `work/Data` is
//! unavailable, matching the rest of the data-driven suite.

use std::path::PathBuf;
use std::sync::Arc;

use ttf_parser::Face;
use wolf_format::command::{Command, Slot, Tail};
use wolf_format::mps::Map;
use wolf_game::picture::{Picture, PictureKind, ANCHOR_TOP_LEFT};
use wolf_game::{Atlas, Game, SpriteQuad};
use wolf_vm::Program;

const NAME_TEXT: i32 = 36_014;
const NAME_BASE: i32 = 36_008;
const BALLOON_FRAME: i32 = 36_000;
const BALLOON_BODY: i32 = 36_013;
const NATIVE_MESSAGE_SLOTS: std::ops::RangeInclusive<i32> = 19_500..=19_503;

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

fn open_game() -> Option<Game> {
    let root = data_root();
    if !root.join("BasicData").join("CommonEvent.dat").is_file() {
        eprintln!("skipping: no WOLF data at {root:?}");
        return None;
    }
    match Game::new(root) {
        Ok(mut game) => {
            game.auto_events.set_enabled(false);
            Some(game)
        }
        Err(err) => {
            eprintln!("skipping: cannot create Game: {err}");
            None
        }
    }
}

fn open_loaded(events: &[u32]) -> Option<Game> {
    let root = data_root();
    let save = root.join("Save").join("SaveData01.sav");
    let map_path = root.join("MapData").join("SampleMapA.mps");
    if !save.is_file() || !map_path.is_file() {
        eprintln!(
            "skipping: missing SaveData01 or SampleMapA under {}",
            root.display()
        );
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
    let bytes = std::fs::read(&map_path).ok()?;
    let mut map = Map::parse(&bytes).ok()?;
    map.events.retain(|event| events.contains(&event.id));
    game.start_pages(&map, None);
    Some(game)
}

fn open_balloon_scene() -> Option<Game> {
    let root = data_root();
    let save = root.join("Save").join("SaveData01.sav");
    let map_path = root.join("MapData").join("SampleMapA.mps");
    if !save.is_file() || !map_path.is_file() {
        eprintln!(
            "skipping: missing SaveData01 or SampleMapA under {}",
            root.display()
        );
        return None;
    }
    let mut game = Game::new(root).ok()?;
    game.prime_engine();
    if let Err(err) = game.load_save(&save) {
        eprintln!("skipping: cannot load SaveData01: {err}");
        return None;
    }
    game.auto_advance = false;
    game.screen.clear();
    game.messages.clear();
    let bytes = std::fs::read(&map_path).ok()?;
    let mut map = Map::parse(&bytes).ok()?;
    map.events.retain(|event| event.id == 1);
    game.start_pages(&map, None);
    assert!(game.start_map_event(&map, 1), "Event 1 starts");
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

fn quad_bounds(quads: &[SpriteQuad], number: i32) -> Option<[f32; 4]> {
    let matching: Vec<_> = quads.iter().filter(|quad| quad.number == number).collect();
    let first = matching.first()?;
    let mut left = first.rect[0];
    let mut top = first.rect[1];
    let mut right = first.rect[0] + first.rect[2];
    let mut bottom = first.rect[1] + first.rect[3];
    for quad in matching.iter().skip(1) {
        left = left.min(quad.rect[0]);
        top = top.min(quad.rect[1]);
        right = right.max(quad.rect[0] + quad.rect[2]);
        bottom = bottom.max(quad.rect[1] + quad.rect[3]);
    }
    Some([left, top, right - left, bottom - top])
}

/// The font the Godot host prefers. The shipped data font is the portable fallback.
fn name_font(root: &std::path::Path) -> Option<(Vec<u8>, u32)> {
    let candidates = [
        PathBuf::from("C:/Windows/Fonts/msyhbd.ttc"),
        root.join("◆GenJyuuGothicX-P-Bold.ttf"),
        root.join("07やさしさゴシックボールド.ttf"),
    ];
    for path in candidates {
        let Ok(bytes) = std::fs::read(&path) else {
            continue;
        };
        for index in 0..8 {
            let Ok(face) = Face::parse(&bytes, index) else {
                continue;
            };
            if face.glyph_index('妹').is_some() {
                return Some((bytes, index));
            }
        }
    }
    None
}

fn glyph_ink_span(
    bytes: &[u8],
    face_index: u32,
    text: &str,
    font_px: f32,
    baseline: f32,
) -> Option<(f32, f32)> {
    let face = Face::parse(bytes, face_index).ok()?;
    let scale = font_px / f32::from(face.units_per_em());
    let mut top = f32::INFINITY;
    let mut bottom = f32::NEG_INFINITY;
    for ch in text.chars().filter(|ch| !ch.is_whitespace()) {
        let glyph = face.glyph_index(ch)?;
        let bbox = face.glyph_bounding_box(glyph)?;
        top = top.min(baseline - f32::from(bbox.y_max) * scale);
        bottom = bottom.max(baseline - f32::from(bbox.y_min) * scale);
    }
    (top.is_finite() && bottom.is_finite()).then_some((top, bottom))
}

#[test]
fn balloon_name_ink_center_sits_in_the_opaque_strip() {
    let Some(mut game) = open_balloon_scene() else {
        return;
    };
    let Some((font_bytes, face_index)) = name_font(&data_root()) else {
        eprintln!("skipping: no font available to measure the speaker name");
        return;
    };

    let mut observed = false;
    for _ in 0..180 {
        game.frame();
        let name_visible = game.screen.get(NAME_TEXT).is_some_and(|picture| {
            !picture.hidden
                && picture.opacity > 0
                && wolf_format::messagetext::strip(&picture.text).contains('妹')
        });
        let base_visible = game.screen.get(NAME_BASE).is_some_and(|picture| {
            !picture.hidden && picture.opacity > 0 && picture.file.contains("nameL(Green)")
        });
        if !name_visible || !base_visible {
            continue;
        }

        let mut atlas = Atlas::with_size(2048, 4096);
        let rendered = game.picture_quads(&mut atlas);
        let texts = game.text_quads();
        let band = quad_bounds(&rendered, NAME_BASE).expect("opaque name-strip quad");
        let name = texts
            .iter()
            .find(|quad| quad.number == NAME_TEXT && quad.text.contains('妹'))
            .expect("speaker name text quad");

        assert!(
            (band[3] - 24.0).abs() < 0.01,
            "the 3x72 name strip must expose only its 24 px body: {band:?}"
        );

        // WolfText.gd places the Godot baseline at round(rect.y) +
        // round(font_px * 1.023193); use the same law to turn the text line box
        // into the glyph ink rectangle the player actually sees.
        let px = name.font_px.round();
        let baseline = name.rect[1].round() + (px * 1.023_193).round();
        let (ink_top, ink_bottom) =
            glyph_ink_span(&font_bytes, face_index, &name.text, px, baseline)
                .expect("the selected face covers every name glyph");
        let ink_center = (ink_top + ink_bottom) * 0.5;
        let band_center = band[1] + band[3] * 0.5;
        assert!(
            (ink_center - band_center).abs() <= 4.0,
            "speaker-name ink must be vertically centred in the opaque 24 px strip: \
             ink={ink_top:.1}..{ink_bottom:.1} center={ink_center:.1}, \
             band={:.1}..{:.1} center={band_center:.1}, text={:?} text_rect={:?}",
            band[1],
            band[1] + band[3],
            name.text,
            name.rect
        );
        observed = true;
        break;
    }
    assert!(
        observed,
        "CE270 never exposed a visible speaker name and name strip"
    );
}

fn cmd(opcode: u32, args: &[i32], strings: &[&str]) -> Slot {
    let mut params = Vec::new();
    for arg in args {
        params.extend_from_slice(&arg.to_le_bytes());
    }
    Slot::Command(Box::new(Command {
        param_count: (args.len() + 1) as u8,
        opcode,
        params,
        branch_depth: 0,
        strings: strings.iter().map(|text| (*text).to_owned()).collect(),
        tail: Tail::None,
    }))
}

fn hover_picture(number: i32) -> Picture {
    let mut picture = Picture::new(number);
    picture.x = 200;
    picture.y = 200;
    picture.window = Some((200, 80));
    picture.anchor = ANCHOR_TOP_LEFT;
    picture.opacity = 255;
    picture
}

fn query_hover(game: &mut Game, number: i32) -> i32 {
    game.vm.vars.set(0, -99);
    let program = Arc::new(Program::from_slots(
        90_180,
        "m18-hover",
        vec![cmd(124, &[2_000_000, 0x4000, number, 8], &[])],
    ));
    let id = game
        .vm
        .start_program(program)
        .expect("synthetic event starts");
    game.frame();
    assert!(
        game.vm.instance(id).is_none(),
        "the one-query event must finish in one frame"
    );
    game.vm.vars.get(0)
}

#[test]
fn hidden_and_transparent_pictures_do_not_report_hover() {
    let Some(mut game) = open_game() else {
        return;
    };
    game.screen.clear();
    game.messages.clear();
    game.choices = None;
    game.screen.insert(hover_picture(400));
    game.mouse = [300, 240];

    assert_eq!(
        query_hover(&mut game, 400),
        1,
        "a visible picture owns hover inside its rectangle"
    );

    game.screen.get_mut(400).expect("hover picture").hidden = true;
    assert_eq!(
        query_hover(&mut game, 400),
        0,
        "a script-hidden picture must not answer hover"
    );

    game.screen.get_mut(400).expect("hover picture").hidden = false;
    assert_eq!(
        query_hover(&mut game, 400),
        1,
        "restoring the visible picture must restore hover"
    );

    game.screen.get_mut(400).expect("hover picture").opacity = 0;
    assert_eq!(
        query_hover(&mut game, 400),
        0,
        "a fully transparent picture must not answer hover"
    );

    game.screen.get_mut(400).expect("hover picture").opacity = 255;
    assert_eq!(
        query_hover(&mut game, 400),
        1,
        "restoring opacity must restore hover"
    );
}

fn open_status_drawer(game: &mut Game) {
    click_at(game, 15, 137);
    assert_eq!(
        game.last_action_event,
        Some(10),
        "the status triangle must open CE238"
    );
    for _ in 0..30 {
        game.frame();
    }
    let panel = game.screen.get(320).expect("status panel");
    assert_eq!(
        (panel.x, panel.hidden, panel.opacity),
        (0, false, 255),
        "status drawer did not finish its slide-in"
    );
}

fn assert_status_pointer_region(game: &mut Game, y: i32, context: &str) {
    let bounds = {
        let image = game
            .assets
            .load("Picture/status01.png")
            .expect("status art decodes");
        image
            .alpha_bounds(16)
            .expect("status art has visible pixels")
    };
    assert!(
        y < bounds[1] as i32 || y >= (bounds[1] + bounds[3]) as i32,
        "{context}: y={y} must be transparent in status art bounds {bounds:?}"
    );

    game.mouse = [100, y];
    for frame in 0..7 {
        game.frame();
        assert_eq!(
            game.screen.get(320).map(|picture| picture.x),
            Some(0),
            "{context}: drawer retracted before the 8-frame debounce, frame {frame}"
        );
    }
    for _ in 0..30 {
        game.frame();
    }
    assert_eq!(
        game.screen.get(320).map(|picture| picture.x),
        Some(-305),
        "{context}: a transparent vertical gap must let the drawer auto-retract"
    );
}

#[test]
fn side_panel_top_transparent_gap_retracts_after_debounce() {
    let Some(mut game) = open_loaded(&[7, 8, 10, 11]) else {
        return;
    };
    open_status_drawer(&mut game);
    assert_status_pointer_region(&mut game, 0, "status top gap");
}

#[test]
fn side_panel_bottom_transparent_gap_retracts_after_debounce() {
    let Some(mut game) = open_loaded(&[7, 8, 10, 11]) else {
        return;
    };
    open_status_drawer(&mut game);
    assert_status_pointer_region(&mut game, 550, "status bottom gap");
}

#[test]
fn side_panel_visible_middle_keeps_the_drawer_open() {
    let Some(mut game) = open_loaded(&[7, 8, 10, 11]) else {
        return;
    };
    open_status_drawer(&mut game);

    let bounds = {
        let image = game
            .assets
            .load("Picture/status01.png")
            .expect("status art decodes");
        image
            .alpha_bounds(16)
            .expect("status art has visible pixels")
    };
    let y = 300;
    assert!(
        y >= bounds[1] as i32 && y < (bounds[1] + bounds[3]) as i32,
        "y={y} must be inside status art bounds {bounds:?}"
    );

    game.mouse = [100, y];
    for frame in 0..37 {
        game.frame();
        assert_eq!(
            game.screen.get(320).map(|picture| picture.x),
            Some(0),
            "frame {frame}: the pointer is over visible panel art and must keep it open"
        );
    }
}

fn synthetic_balloon_picture() -> Picture {
    let mut picture = Picture::new(BALLOON_FRAME);
    picture.kind = PictureKind::WindowString;
    picture.file = "BalloonBase_CafeLatte/[CafeLatte]base_Round.png".to_owned();
    picture.window = Some((580, 60));
    picture.anchor = ANCHOR_TOP_LEFT;
    picture.x = 222;
    picture.y = 506;
    picture.opacity = 255;
    picture
}

fn synthetic_balloon_body() -> Picture {
    let mut picture = Picture::new(BALLOON_BODY);
    picture.kind = PictureKind::Text;
    picture.text = "测试".to_owned();
    picture.window = Some((1, 1));
    picture.text_size = Some((120, 20));
    picture.x = 300;
    picture.y = 500;
    picture.opacity = 255;
    picture
}

fn synthetic_native_picture(number: i32, file: &str, window: Option<(i32, i32)>) -> Picture {
    let mut picture = Picture::new(number);
    if number == 19_500 {
        picture.kind = PictureKind::WindowString;
        picture.window = window;
    } else {
        picture.kind = PictureKind::File;
    }
    picture.file = file.to_owned();
    picture.x = 40 + (number - 19_500) * 120;
    picture.y = 80;
    picture.anchor = ANCHOR_TOP_LEFT;
    picture.opacity = 255;
    picture
}

#[test]
fn balloon_mode_prefilters_native_layers_before_atlas_packing() {
    let Some(mut game) = open_game() else {
        return;
    };
    game.screen.clear();
    game.messages.clear();
    game.choices = None;
    game.screen.insert(synthetic_balloon_picture());
    game.screen.insert(synthetic_balloon_body());

    let native = [
        (19_500, "Picture/icon01.png", Some((200, 80))),
        (19_501, "Picture/icon05.png", None),
        (19_502, "Picture/icon06.png", None),
        (19_503, "Picture/face01.png", None),
    ];
    let native_keys: Vec<(String, Option<String>)> = native
        .iter()
        .map(|(_, file, _)| {
            let region = game
                .assets
                .texture_size(file)
                .map(|(width, height)| format!("{file}#0,0,{width},{height}"));
            ((*file).to_owned(), region)
        })
        .collect();
    for &(number, file, window) in &native {
        game.screen
            .insert(synthetic_native_picture(number, file, window));
    }

    let mut atlas = Atlas::with_size(2048, 4096);
    let quads = game.picture_quads(&mut atlas);
    assert!(
        quads
            .iter()
            .all(|quad| !NATIVE_MESSAGE_SLOTS.contains(&quad.number)),
        "balloon mode must still suppress native message quads"
    );
    assert!(
        atlas
            .entry("BalloonBase_CafeLatte/[CafeLatte]base_Round.png")
            .is_some(),
        "the visible balloon skin must still be packed"
    );

    let leaked: Vec<&str> = native_keys
        .iter()
        .filter_map(|(file, region)| {
            (atlas.entry(file).is_some()
                || region
                    .as_deref()
                    .is_some_and(|key| atlas.entry(key).is_some()))
            .then_some(file.as_str())
        })
        .collect();
    assert!(
        leaked.is_empty(),
        "19500..19503 must be excluded before atlas packing; leaked entries: {leaked:?}"
    );
}
