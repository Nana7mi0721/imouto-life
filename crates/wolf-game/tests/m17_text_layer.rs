//! Runtime probe for the balloon-message text layer.

use std::collections::BTreeMap;
use std::path::PathBuf;

use wolf_game::db::{Container, Databases};
use wolf_game::picture::{Picture, PictureKind, Screen, SCREEN_H, SCREEN_W};
use wolf_game::{Atlas, Game, Message};
use wolf_vm::text::{EscapeBank, VarLookup};
use wolf_vm::{DbContainer, Variables};

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

fn visible(raw: &str) -> String {
    wolf_format::messagetext::strip(raw)
}

/// The durable CSelf bank exposed by `Game` stores the five string cells at 0..5.
struct BalloonLookup<'a> {
    vars: &'a Variables,
    databases: &'a Databases,
}

impl VarLookup for BalloonLookup<'_> {
    fn lookup_num(&mut self, bank: EscapeBank, index: usize) -> i32 {
        match bank {
            EscapeBank::SelfVar => self
                .vars
                .common_self
                .get(&270)
                .map_or(0, |bank| bank.get(index)),
            EscapeBank::Var => self.vars.get(index),
            EscapeBank::SysVar => self.vars.get_sys(index),
            EscapeBank::StrVar => 0,
        }
    }

    fn lookup_str(&mut self, bank: EscapeBank, index: usize) -> String {
        match bank {
            EscapeBank::SelfVar => {
                self.vars
                    .common_self
                    .get(&270)
                    .map_or_else(String::new, |bank| {
                        if (5..=9).contains(&(index % 100)) {
                            bank.get_str(index - 5).to_owned()
                        } else {
                            String::new()
                        }
                    })
            }
            EscapeBank::StrVar => self.vars.get_str(index).to_owned(),
            EscapeBank::SysVar => self.vars.get_sys_str(index).to_owned(),
            EscapeBank::Var => String::new(),
        }
    }

    fn lookup_db(
        &mut self,
        container: DbContainer,
        db_type: i32,
        row: i32,
        column: i32,
    ) -> Option<String> {
        self.databases
            .text(Container::from(container), db_type, row, column)
            .map(str::to_owned)
    }
}

fn assert_clean(number: i32, raw: &str) {
    let text = visible(raw);
    assert!(
        !text.trim_start().starts_with('0'),
        "balloon text picture {number} gained a numeric prefix: raw={raw:?} visible={text:?}"
    );
    assert!(
        !raw.contains("\\>0") && !raw.contains("0\\E"),
        "balloon text picture {number} still carries the stale type id: {raw:?}"
    );
}

#[test]
fn balloon_message_text_layer_has_no_numeric_prefix() {
    let root = data_root();
    if !root.join("BasicData").join("CommonEvent.dat").is_file() {
        eprintln!("skipping: no WOLF data at {root:?}");
        return;
    }
    let mut game = Game::new(&root).expect("game");
    game.prime_engine();
    game.auto_advance = false;
    game.messages.clear();
    game.messages.push(Message {
        text: "\\E一个月前——".to_owned(),
        face: None,
        frames: 0,
    });

    // CE270 reuses several scratch pictures while it lays out one balloon. 36013
    // carries the final body text and is observable for many frames. 36020 is the
    // measurement/name scratch slot: within one VM step it receives the body text
    // and speaker name, then is overwritten by the face and balloon images. Polling
    // the finished frame therefore cannot see its text command. Keep every 36013
    // observation below and replay 36020 through the same expander with the live
    // CSelf bank and database after CE270 has run.
    let mut candidates: BTreeMap<i32, Vec<(String, String)>> = BTreeMap::new();
    for _ in 0..120 {
        game.frame();
        for picture in game
            .screen
            .iter()
            .filter(|picture| picture.kind.is_text() && !picture.hidden)
        {
            let text = visible(&picture.text);
            if matches!(picture.number, 36013 | 36020) || text.contains("一个月前") {
                candidates
                    .entry(picture.number)
                    .or_default()
                    .push((picture.text.clone(), text));
            }
        }
    }
    let seen = candidates
        .get(&36013)
        .unwrap_or_else(|| panic!("balloon text picture 36013 never appeared"));
    assert!(
        seen.iter().any(|(_, text)| !text.is_empty()),
        "balloon text picture 36013 only appeared empty: {seen:?}"
    );
    for (raw, _) in seen {
        assert_clean(36013, raw);
    }
    assert_eq!(
        game.vm.vars.common_self.get(&270).map(|bank| bank.get(90)),
        Some(26),
        "CE270 must resolve the message-window type label to Data type 26"
    );

    let databases = Databases::load(&root.join("BasicData"), (SCREEN_W, SCREEN_H));
    assert_eq!(
        databases.type_name(Container::Data, 26),
        Some("メッセージウィンドウ種類"),
        "the metadata read must name the type CE270 resolved"
    );
    let mut lookup = BalloonLookup {
        vars: &game.vm.vars,
        databases: &databases,
    };
    let raw = wolf_vm::text::expand("\\>\\udb[\\cself[90]:\\cself[10]:8]\\cself[7]", &mut lookup);
    assert_clean(36020, &raw);

    let mut picture = Picture::new(36020);
    picture.kind = PictureKind::Text;
    picture.text = raw.clone();
    picture.window = Some((1, 1));
    let mut screen = Screen::new();
    screen.insert(picture);
    let picture = screen.get(36020).expect("the replayed 36020 command");
    assert_eq!(picture.number, 36020);
    assert_eq!(picture.kind, PictureKind::Text);
    assert_eq!(picture.text, raw);
}

/// CE270's default mode draws the body as picture 36013. The native 101 layer
/// must not paint a second copy of the same line at the same time.
#[test]
fn picture_mode_balloon_suppresses_the_native_message_layer() {
    let root = data_root();
    if !root.join("BasicData").join("CommonEvent.dat").is_file() {
        eprintln!("skipping: no WOLF data at {root:?}");
        return;
    }
    let mut game = Game::new(&root).expect("game");
    game.prime_engine();
    game.auto_advance = false;
    game.messages.clear();
    game.messages.push(Message {
        text: "\\E一个月前——".to_owned(),
        face: None,
        frames: 0,
    });
    assert!(
        game.rendered_message_layout().is_none(),
        "a configured balloon must own the message before CE270's first draw"
    );
    let mut early_atlas = Atlas::new();
    let early_quads = game.picture_quads(&mut early_atlas);
    assert!(
        early_quads
            .iter()
            .all(|quad| !matches!(quad.number, 19_500 | 19_501)),
        "the native frame and face must stay hidden on the message's first frame"
    );

    let mut observed_balloon = false;
    for _ in 0..120 {
        game.frame();
        let balloon_visible = game
            .screen
            .get(36013)
            .is_some_and(|picture| !picture.hidden && !picture.text.is_empty());
        if !balloon_visible {
            continue;
        }
        observed_balloon = true;
        assert!(
            game.message_layout().is_some(),
            "the native 101 layout must remain available for diagnostics"
        );
        assert!(
            game.rendered_message_layout().is_none(),
            "CE270 picture-mode text must own the visible message layer"
        );
        let mut atlas = Atlas::new();
        let quads = game.picture_quads(&mut atlas);
        assert!(
            quads
                .iter()
                .all(|quad| !matches!(quad.number, 19_500 | 19_501)),
            "picture mode must suppress the native 19500 frame and 19501 face"
        );
        assert!(
            quads.iter().any(|quad| quad.number == 36_000),
            "picture mode must keep the balloon base"
        );
        assert!(
            game.text_quads()
                .iter()
                .any(|quad| quad.number == 36_013 && !quad.text.is_empty()),
            "picture mode must keep the balloon body text"
        );
        break;
    }
    assert!(
        observed_balloon,
        "CE270 never exposed its body text picture 36013"
    );

    game.screen
        .get_mut(36013)
        .expect("balloon body picture")
        .hidden = true;
    assert!(
        game.rendered_message_layout().is_none(),
        "the visible balloon frame still owns the message while its body is between draws"
    );
    game.screen
        .get_mut(36000)
        .expect("balloon frame picture")
        .hidden = true;
    assert!(
        game.rendered_message_layout().is_none(),
        "picture mode owns the message even while the balloon is between draws"
    );

    // Article mode deliberately uses WOLF's native 101 renderer.
    game.vm.vars.common_self.entry(269).or_default().set(11, 1);
    assert!(
        game.rendered_message_layout().is_some(),
        "article mode must return the native layer"
    );
}

/// A three-line balloon must grow upward and keep all three rows inside 576 px.
///
/// CE270 writes `\ax[...]\n\ay[0]` before the body. The newline used to leave an
/// empty row, and the 1.3 em text-picture pitch put the third row at y = 564 with
/// its ink clipped by the screen edge. The message pitch (23 px) plus the same
/// fixed bottom edge as the retail 80 px balloon puts the rows at 493/516/539.
#[test]
fn three_line_balloon_keeps_every_row_on_screen() {
    let root = data_root();
    if !root.join("BasicData").join("CommonEvent.dat").is_file() {
        eprintln!("skipping: no WOLF data at {root:?}");
        return;
    }
    let mut game = Game::new(&root).expect("game");
    game.prime_engine();
    game.auto_advance = false;
    game.messages.clear();
    game.messages.push(Message {
        text: "第一行文字\n第二行文字\n第三行文字".to_owned(),
        face: None,
        frames: 0,
    });

    let mut checked = false;
    for _ in 0..160 {
        game.frame();
        let Some(body) = game.screen.get(36013) else {
            continue;
        };
        if body.hidden || !body.text.contains("第三行文字") {
            continue;
        }
        let mut atlas = Atlas::new();
        let quads = game.picture_quads(&mut atlas);
        assert!(
            quads
                .iter()
                .all(|quad| !matches!(quad.number, 19_500 | 19_501)),
            "balloon mode must keep the native frame/face out of picture_quads"
        );
        let runs: Vec<_> = game
            .text_quads()
            .into_iter()
            .filter(|quad| quad.number == 36013 && !quad.text.is_empty())
            .collect();
        assert_eq!(runs.len(), 3, "three body lines must all lay out: {runs:?}");
        for pair in runs.windows(2) {
            let pitch = pair[1].rect[1] - pair[0].rect[1];
            assert!(
                (22.0..=24.0).contains(&pitch),
                "balloon rows must use the message pitch, got {pitch}: {runs:?}"
            );
        }
        for run in &runs {
            assert!(
                run.rect[1] + run.rect[3] <= SCREEN_H as f32,
                "balloon row clipped by the screen: {run:?}"
            );
        }
        let frame = game.screen.get(36000).expect("balloon frame");
        assert!(
            frame.window.is_some_and(|(_, height)| height >= 79),
            "the three-line balloon frame must grow above the 60 px one-line size: {:?}",
            frame.window
        );
        checked = true;
        break;
    }
    assert!(
        checked,
        "CE270 never laid out the three-line synthetic message"
    );
}
