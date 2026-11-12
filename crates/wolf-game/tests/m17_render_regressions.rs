//! M17 regressions after the T12 tile-layer bake.
//!
//! The Godot bridge now keeps map chips in a dedicated tile atlas. Picture/UI entries
//! are rebuilt and dropped independently, so their page resets cannot move UVs that
//! were already baked into the screen-sized tile texture.

use std::path::{Path, PathBuf};

use wolf_format::mps::Map;
use wolf_game::picture::{field, Screen};
use wolf_game::{Atlas, Game};
use wolf_vm::{PictureAction, PictureCmd};

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

fn load_map(root: &Path, name: &str) -> Map {
    let bytes = std::fs::read(root.join("MapData").join(format!("{name}.mps")))
        .expect("registered map exists");
    Map::parse(&bytes).expect("registered map parses")
}

#[test]
fn retail_tile_fixtures_explain_the_green_and_yellow_frames() {
    let root = data_root();
    if !root.join("BasicData").join("CommonEvent.dat").is_file() {
        eprintln!("skipping: no WOLF data at {root:?}");
        return;
    }

    let distinct = |map: &Map, layer: usize| {
        let mut words = map.layers[layer].clone();
        words.sort_unstable();
        words.dedup();
        words
    };

    let title = load_map(&root, "TitleMap");
    for layer in 0..title.layers.len() {
        assert_eq!(
            distinct(&title, layer),
            vec![100_000, 104_444],
            "the title fixture must not contain map-3 base chips"
        );
    }

    let map003 = load_map(&root, "Map003");
    assert_eq!(
        distinct(&map003, 0),
        vec![1, 2, 100_000],
        "the green frame is the real Map003 tile layer"
    );
    for layer in 1..map003.layers.len() {
        assert_eq!(
            distinct(&map003, layer),
            vec![100_000],
            "Map003 layer {layer} must stay empty"
        );
    }

    let bedroom = load_map(&root, "SampleMapA");
    for layer in 0..bedroom.layers.len() {
        assert_eq!(
            distinct(&bedroom, layer),
            vec![104_444],
            "the yellow dirt frame is the real bedroom fixture"
        );
    }
}

#[test]
fn picture_atlas_upload_is_cropped_to_packed_content() {
    let Some((mut game, _map)) = open_balloon_scene() else {
        return;
    };
    let mut atlas = Atlas::new();
    for _ in 0..120 {
        game.frame();
        let quads = game.picture_quads(&mut atlas);
        let [width, height] = atlas.content_size();
        for quad in quads {
            let right = (quad.uv[2] * atlas.size()[0] as f32).ceil() as u32;
            let bottom = (quad.uv[3] * atlas.size()[1] as f32).ceil() as u32;
            assert!(
                right <= width && bottom <= height,
                "quad #{} samples outside the cropped upload: {right}x{bottom} > {width}x{height}",
                quad.number
            );
        }
    }

    let [width, height] = atlas.content_size();
    let cropped = atlas.content_pixels();
    assert_eq!(cropped.len(), width as usize * height as usize * 4);
    let full_bytes = atlas.size()[0] as usize * atlas.size()[1] as usize * 4;
    eprintln!(
        "picture atlas upload: {width}x{height}, {:.1} MiB (full page {:.1} MiB)",
        cropped.len() as f64 / 1_048_576.0,
        full_bytes as f64 / 1_048_576.0
    );
    assert!(
        cropped.len() < full_bytes / 2,
        "picture atlas upload still carries the empty page: {} of {full_bytes} bytes",
        cropped.len()
    );
}

fn open_balloon_scene() -> Option<(Game, Map)> {
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

    let bytes =
        std::fs::read(root.join("MapData").join("SampleMapA.mps")).expect("SampleMapA exists");
    let mut map = Map::parse(&bytes).expect("SampleMapA parses");
    map.events.retain(|event| event.id == 1);
    game.start_pages(&map, None);
    assert!(game.start_map_event(&map, 1), "Event 1 starts");
    Some((game, map))
}

fn draw_with_ce63_tail(number: i32, args: Vec<i32>) -> PictureCmd {
    PictureCmd {
        number,
        kind: 0,
        action: PictureAction::Draw,
        file: "Picture/face01.png".to_owned(),
        text: String::new(),
        args,
        anchor: 0,
        scale_mode: 0,
        animate: Vec::new(),
        keep_shift: false,
        relative: false,
        owner_event: Some(63),
    }
}

#[test]
fn the_ce63_window_draw_keeps_the_unused_tone_tail_neutral() {
    // CE63 pc131: a type-1 message-window draw. Its 0x01000000 flag is not the
    // 0x02000000 "tone present" marker, so the three zero words at args 13..15 are
    // editor padding. Interpreting them as black turns the sister's 19501 face into
    // a pure black silhouette.
    let args = vec![
        0, 1, 1, -1_000_000, 255, 1_600_044, 1_600_045, 1_600_023, -1_000_000, 1_600_008,
        16_777_216, 0, 0, 0, 0, 0, 1_600_024,
    ];
    assert_eq!(args[field::TONE_R], 0);
    assert_eq!(args[field::TONE_G], 0);
    assert_eq!(args[field::TONE_B], 0);

    let mut screen = Screen::new();
    screen.apply(&draw_with_ce63_tail(19_501, args));
    assert_eq!(
        screen.get(19_501).expect("sister face").tone_byte(),
        [255, 255, 255],
        "CE63's padding slots must not become a black face"
    );
}

#[test]
fn a_real_ce94_tone_triplet_still_reaches_the_picture() {
    // CE94 pc370 carries 0x02000000 and a real 100/100/100 tone tail. A fix for
    // CE63 must key on the marker, not disable tone decoding globally.
    let args = vec![
        0, 1, 1, 1, 255, 1_600_051, 1_600_052, 1_600_091, 0, 1_600_007, 33_554_432, 0, 0, 100, 100,
        100, 1_600_092,
    ];
    let mut screen = Screen::new();
    screen.apply(&draw_with_ce63_tail(12_000, args));
    assert_eq!(
        screen.get(12_000).expect("save cursor").tone_byte(),
        [255, 255, 255]
    );
}

#[test]
fn balloon_face_36002_keeps_its_white_pixels_and_normal_blend() {
    let Some((mut game, _map)) = open_balloon_scene() else {
        return;
    };
    let face = game
        .assets
        .load("Picture/face01.png")
        .expect("balloon face decodes");
    let visible = face
        .rgba
        .chunks_exact(4)
        .filter(|pixel| pixel[3] != 0)
        .collect::<Vec<_>>();
    assert!(!visible.is_empty(), "face01 must have visible pixels");
    let average = (0..3)
        .map(|channel| {
            visible
                .iter()
                .map(|pixel| u64::from(pixel[channel]))
                .sum::<u64>()
                / visible.len() as u64
        })
        .collect::<Vec<_>>();
    assert!(
        average.iter().all(|&channel| channel > 0),
        "face01 must not decode to an RGB-zero alpha mask: {average:?}"
    );

    let mut atlas = Atlas::with_size(2048, 4096);
    let mut seen_files = std::collections::BTreeSet::new();
    for frame in 0..120 {
        game.frame();
        let sprites = game.picture_quads(&mut atlas);
        let Some(face_quad) = sprites
            .iter()
            .find(|quad| quad.number == 36_002 && quad.alpha > 0.0)
        else {
            continue;
        };
        assert_eq!(
            face_quad.blend, 0,
            "frame {frame}: the balloon face must use normal alpha blending"
        );
        assert!(
            face_quad
                .tint
                .iter()
                .all(|&channel| (channel - 1.0).abs() < f32::EPSILON),
            "frame {frame}: the balloon face must keep neutral tone, got {:?}",
            face_quad.tint
        );

        let picture = game.screen.get(36_002).expect("visible face picture");
        assert!(
            matches!(
                picture.file.as_str(),
                "Picture/face01.png" | "Picture/face02.png"
            ),
            "frame {frame}: unexpected balloon face {}",
            picture.file
        );
        if !seen_files.insert(picture.file.clone()) {
            continue;
        }
        eprintln!(
            "balloon face {} frame {frame}: rect={:?} uv={:?} alpha={}",
            picture.file, face_quad.rect, face_quad.uv, face_quad.alpha
        );
        let pixels = atlas.pixels();
        let atlas_width = atlas.size()[0];
        let atlas_height = atlas.size()[1];
        let rect = [
            (face_quad.uv[0] * atlas_width as f32).round() as u32,
            (face_quad.uv[1] * atlas_height as f32).round() as u32,
            ((face_quad.uv[2] - face_quad.uv[0]) * atlas_width as f32).round() as u32,
            ((face_quad.uv[3] - face_quad.uv[1]) * atlas_height as f32).round() as u32,
        ];
        let mut visible_face = 0usize;
        let mut rgb_zero = 0usize;
        for y in rect[1]..rect[1] + rect[3] {
            for x in rect[0]..rect[0] + rect[2] {
                let at = ((y * atlas_width + x) * 4) as usize;
                if pixels[at + 3] == 0 {
                    continue;
                }
                visible_face += 1;
                if pixels[at..at + 3].iter().all(|&channel| channel == 0) {
                    rgb_zero += 1;
                }
            }
        }
        assert!(visible_face > 0, "frame {frame}: packed face is empty");
        assert!(
            rgb_zero * 10 < visible_face,
            "frame {frame}: packed face is mostly RGB zero ({rgb_zero}/{visible_face})"
        );
    }
    assert!(
        !seen_files.is_empty(),
        "the balloon scene must expose picture 36002 while the sister speaks"
    );
    eprintln!("visible balloon faces: {seen_files:?}");
    for picture in game.screen.iter() {
        if picture.hidden || picture.alpha() <= 0.0 {
            continue;
        }
        if (900..=903).contains(&picture.number)
            || picture.file.contains("stand_")
            || picture.file.contains("face0")
        {
            eprintln!(
                "speech picture {} file={} pos=({}, {}) scale={}x{} alpha={} blend={} tone={:?}",
                picture.number,
                picture.file,
                picture.x,
                picture.y,
                picture.scale,
                picture.scale_y,
                picture.alpha(),
                picture.blend,
                picture.tone_byte()
            );
        }
    }
}
