//! M16 item 11: one mouse click reaches every parallel opcode-123 poller.
//!
//! BUG-30 has two halves:
//!
//! * opcode 125's automatic input is delivered once per coroutine and survives
//!   one frame of TTL, so a coroutine that ran before the injector still sees it;
//! * a real mouse edge is broadcast to every coroutine polling opcode 123 in the
//!   same frame. The first poller must not spend the click for the next one.
//!
//! The first two tests run without game data: they drive one or two VMs and a
//! local Host that mirrors the production click bookkeeping. The other tests use
//! `Game` end to end: first with two synthetic parallel map events, then with the
//! real SampleMapA events 16 and 26 when `WOLF_DATA_ROOT` (or `work/Data`) is
//! present.

use std::path::PathBuf;

use wolf_format::command::{Command, RouteData, Slot, Tail};
use wolf_format::commonevent::{CommonEvent, CommonEventData};
use wolf_format::mps::{Map, MapEvent, MapEventPage};
use wolf_game::key;
use wolf_game::picture::ANCHOR_TOP_LEFT;
use wolf_game::{Game, Picture};
use wolf_vm::{Host, KeyQuery, ProgramSet, SoundAction, Vm, WaitState};

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
        strings: strings.iter().map(|s| (*s).to_owned()).collect(),
        tail: Tail::None,
    }))
}

fn common_event(id: u32, title: &str, commands: Vec<Slot>) -> CommonEvent {
    CommonEvent {
        id,
        raw_condition: 0,
        condition_variable: 0,
        condition_value: 0,
        arg_num_count: 0,
        arg_str_count: 0,
        title: title.to_owned(),
        commands,
        memo: String::new(),
        arg_names: Vec::new(),
        arg_special_spec: Vec::new(),
        arg_string_pages: Vec::new(),
        arg_value_pages: Vec::new(),
        default_values: Vec::new(),
        color: 0,
        self_variable_names: vec![String::new(); 100],
        return_name: String::new(),
        return_value_id: 0,
    }
}

fn vm_with(events: Vec<CommonEvent>) -> Vm {
    Vm::new(ProgramSet::from_common_events(&CommonEventData {
        version_header: 0xC9,
        version: 0xC9,
        events,
        footer: 0x90,
    }))
}

/// A host with the same click bookkeeping as `GameHost`: an edge is stored as
/// pending so a poll that did not accept it this frame does not destroy it, and
/// only a poll that actually observed the edge spends it at frame end.
#[derive(Default)]
struct SharedClickHost {
    buttons: u32,
    previous: u32,
    pending: u32,
    pending_age: u8,
    consumed: bool,
    polls: Vec<(KeyQuery, u32, u32, i32)>,
}

impl SharedClickHost {
    fn frame_begin(&mut self) {
        let fresh = key::mouse_bits(self.buttons, self.previous);
        if fresh != 0 {
            self.pending |= fresh;
            self.pending_age = 0;
        }
    }

    fn frame_end(&mut self) {
        if self.consumed {
            self.pending = 0;
            self.pending_age = 0;
        } else if self.pending != 0 {
            self.pending_age += 1;
            if self.pending_age > 2 {
                self.pending = 0;
                self.pending_age = 0;
            }
        }
        self.consumed = false;
        self.previous = self.buttons;
    }

    fn mouse_key_bits(&mut self) -> u32 {
        let pending = self.pending;
        self.consumed = true;
        key::mouse_bits(self.buttons, self.previous) | pending
    }
}

impl Host for SharedClickHost {
    fn key_code_auto(&mut self, query: KeyQuery, auto: u32, banned: u32) -> i32 {
        let held = key::from_wolf_bits(auto) | self.mouse_key_bits();
        let code = key::code_for(held, query, key::from_wolf_bits(banned));
        self.polls.push((query, auto, banned, code));
        code
    }
}

/// BUG-30: a coroutine that polls before the injector runs must still receive
/// the automatic key on the next frame. Delivery is tracked per instance, so the
/// injector's own poll does not starve the earlier coroutine.
#[test]
fn bug_30_auto_key_ttl_reaches_a_coroutine_that_ran_before_the_injector() {
    // Event 100 runs first (spawn order) and parks on a wait poll with no
    // automatic input on the first frame.
    let before = common_event(
        100,
        "poll-before-injector",
        vec![
            cmd(123, &[2_000_010, 0x97], &[]),
            cmd(121, &[2_000_030, 2_000_010, 0, 0], &[]),
            cmd(180, &[1], &[]),
            cmd(123, &[2_000_011, 0x97], &[]),
            cmd(121, &[2_000_031, 2_000_011, 0, 0], &[]),
        ],
    );
    // Event 200 injects decide/down for one frame and then ends. Its poll runs
    // after the injection in the same frame.
    let injector = common_event(
        200,
        "injector",
        vec![
            cmd(125, &[16], &[]),
            cmd(123, &[2_000_020, 0x17], &[]),
            cmd(121, &[2_000_040, 2_000_020, 0, 0], &[]),
        ],
    );
    let mut vm = vm_with(vec![before, injector]);
    let first = vm.start_event(100).expect("event 100");
    let injector_id = vm.start_event(200).expect("event 200");
    let mut host = SharedClickHost::default();

    vm.step_frame(&mut host);
    assert_eq!(
        vm.vars.get(30),
        0,
        "the earlier coroutine polled before 125"
    );
    assert_eq!(vm.vars.get(40), key::CODE_DOWN, "the injector saw its key");
    assert_eq!(host.polls.len(), 2);
    assert_eq!(host.polls[0].1, 0);
    assert_eq!(host.polls[1].1, 16);
    assert!(
        vm.input.auto_keys_delivered.contains(&injector_id),
        "only the injector has consumed the automatic input so far"
    );
    assert!(
        !vm.input.auto_keys_delivered.contains(&first),
        "the earlier coroutine must still be eligible for delivery"
    );

    vm.step_frame(&mut host);
    assert_eq!(
        vm.vars.get(30),
        key::CODE_DOWN,
        "the earlier coroutine reads the carried-over automatic key next frame"
    );
    vm.step_frame(&mut host);
    assert_eq!(
        vm.vars.get(31),
        0,
        "the two-frame TTL expires instead of repeating forever"
    );
    let parked = vm.instance(first).expect("event 100 still parked");
    assert_eq!(
        parked.pc, 3,
        "the second poll re-ran after the one-frame wait"
    );
    assert_eq!(
        parked.wait,
        WaitState::Key,
        "with no automatic input left, the second poll blocks"
    );
}

/// The same click edge is visible to two independent VMs stepped in the same
/// frame. This is the smallest form of the parallel-input contract: the first
/// VM's poll consumes the edge for the frame, but not for the second VM.
#[test]
fn two_vm_instances_both_see_one_click_and_the_next_click() {
    let event = |id: u32, poll: i32, count: i32| {
        common_event(
            id,
            "wait-poller",
            vec![
                cmd(170, &[0], &[]),
                cmd(123, &[2_000_000 + poll, 0x91], &[]),
                cmd(121, &[2_000_000 + count, 1, 0, 0x100], &[]),
                cmd(180, &[1], &[]),
                cmd(498, &[], &[]),
            ],
        )
    };
    let mut first = vm_with(vec![event(1, 1, 11)]);
    let mut second = vm_with(vec![event(2, 2, 12)]);
    first.start_event(1).expect("first event");
    second.start_event(2).expect("second event");
    let mut host = SharedClickHost::default();

    host.buttons = 1;
    host.frame_begin();
    first.step_frame(&mut host);
    second.step_frame(&mut host);
    host.frame_end();
    assert_eq!(first.vars.get(1), key::CODE_OK, "first VM saw the click");
    assert_eq!(second.vars.get(2), key::CODE_OK, "second VM saw the click");
    assert_eq!(first.vars.get(11), 1);
    assert_eq!(second.vars.get(12), 1);

    for _ in 0..3 {
        host.frame_begin();
        first.step_frame(&mut host);
        second.step_frame(&mut host);
        host.frame_end();
    }
    assert_eq!(first.vars.get(11), 1, "a held button is not a new click");
    assert_eq!(second.vars.get(12), 1, "a held button is not a new click");

    host.buttons = 0;
    host.frame_begin();
    first.step_frame(&mut host);
    second.step_frame(&mut host);
    host.frame_end();

    host.buttons = 1;
    host.frame_begin();
    first.step_frame(&mut host);
    second.step_frame(&mut host);
    host.frame_end();
    assert_eq!(
        first.vars.get(11),
        2,
        "the second click reaches the first VM"
    );
    assert_eq!(
        second.vars.get(12),
        2,
        "the second click reaches the second VM"
    );
}

fn parallel_script(poll: i32, count: i32) -> Vec<Slot> {
    vec![
        cmd(123, &[2_000_000 + poll, 0x91], &[]),
        cmd(121, &[2_000_000 + count, 1, 0, 0x100], &[]),
    ]
}

fn delayed_parallel_script(poll: i32, count: i32) -> Vec<Slot> {
    vec![
        cmd(180, &[1], &[]),
        cmd(123, &[2_000_000 + poll, 0x91], &[]),
        cmd(121, &[2_000_000 + count, 1, 0, 0x100], &[]),
    ]
}

fn map_page(commands: Vec<Slot>) -> MapEventPage {
    MapEventPage {
        graphic_chip_id: u32::MAX,
        graphic: String::new(),
        direction: 0,
        frame: 0,
        opacity: 255,
        display_type: 0,
        trigger: 2,
        trigger_switches: [0; 4],
        trigger_variables: [0; 4],
        trigger_values: [0; 4],
        route: RouteData::default(),
        commands,
        features: 3,
        shadow_graphic: 0,
        collision_width: 0,
        collision_height: 0,
        footer: Map::PAGE_FOOTER,
    }
}

fn synthetic_map(events: &[(u32, Vec<Slot>)]) -> Map {
    Map {
        version_header: 0x55,
        version: 0x66,
        name: String::new(),
        tileset_index: 0,
        width: 64,
        height: 36,
        has_tile_data: false,
        layers: Vec::new(),
        events: events
            .iter()
            .map(|(id, commands)| MapEvent {
                id: *id,
                name: format!("parallel-{id}"),
                x: 0,
                y: 0,
                pages: vec![map_page(commands.clone())],
            })
            .collect(),
        footer: Map::FOOTER,
    }
}

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
    match Game::new(data_root()) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!("skipping parallel-input tests: {err}");
            None
        }
    }
}

fn run_synthetic_click_round(game: &mut Game) {
    let left = 10u32;
    let right = 11u32;
    let left_poll = 1usize;
    let right_poll = 2usize;
    let left_count = 11usize;
    let right_count = 12usize;

    // One press edge. Both parallel pages are blocked on their wait poll, so the
    // frame both must resume and count exactly once.
    game.mouse_buttons = 1;
    game.frame();
    assert_eq!(game.vm.vars.get(left_poll), key::CODE_OK);
    assert_eq!(game.vm.vars.get(right_poll), key::CODE_OK);
    assert_eq!(
        game.vm.vars.get(left_count),
        1,
        "event {left} saw the click"
    );
    assert_eq!(
        game.vm.vars.get(right_count),
        1,
        "event {right} saw the click"
    );

    // Holding the same button is not a new click.
    for _ in 0..3 {
        game.frame();
    }
    assert_eq!(game.vm.vars.get(left_count), 1, "no repeat while held");
    assert_eq!(game.vm.vars.get(right_count), 1, "no repeat while held");

    // Releasing and pressing again is a second independent click.
    game.mouse_buttons = 0;
    game.frame();
    assert_eq!(game.vm.vars.get(left_count), 1);
    assert_eq!(game.vm.vars.get(right_count), 1);
    game.mouse_buttons = 1;
    game.frame();
    assert_eq!(
        game.vm.vars.get(left_count),
        2,
        "second click reaches {left}"
    );
    assert_eq!(
        game.vm.vars.get(right_count),
        2,
        "second click reaches {right}"
    );

    // The second press is also spent once.
    for _ in 0..3 {
        game.frame();
    }
    assert_eq!(game.vm.vars.get(left_count), 2);
    assert_eq!(game.vm.vars.get(right_count), 2);
}

fn synthetic_parallel_game(events: &[(u32, Vec<Slot>)]) -> Option<Game> {
    let mut game = open_game()?;
    let map = synthetic_map(events);
    game.mouse = [300, 240];
    game.start_pages(&map, None);
    Some(game)
}

/// Two parallel map events poll 123 with the wait bit. One click in one frame
/// must release both; the next press must reach both again, once each.
#[test]
fn one_click_is_broadcast_to_every_parallel_123_poller_in_both_spawn_orders() {
    let left = (10u32, parallel_script(1, 11));
    let right = (11u32, parallel_script(2, 12));

    let Some(mut forward) = synthetic_parallel_game(&[left.clone(), right.clone()]) else {
        return;
    };
    run_synthetic_click_round(&mut forward);

    // Reversing the map event order reverses spawn order. The broadcast must not
    // depend on which coroutine the interpreter reaches first.
    let Some(mut reverse) = synthetic_parallel_game(&[right, left]) else {
        return;
    };
    run_synthetic_click_round(&mut reverse);
}

/// A click that arrives while both parallel pages are in a one-frame wait has
/// no opcode-123 poll to deliver it. It must stay pending for the next frame,
/// where both pollers still receive it.
#[test]
fn a_click_before_the_next_poll_is_carried_to_every_parallel_reader() {
    let events = [
        (20u32, delayed_parallel_script(3, 13)),
        (21u32, delayed_parallel_script(4, 14)),
    ];
    let Some(mut game) = synthetic_parallel_game(&events) else {
        return;
    };

    // Both pages park on `180 [1]` before their first 123 poll.
    game.mouse_buttons = 1;
    game.frame();
    assert_eq!(game.vm.vars.get(13), 0, "no poll ran this frame");
    assert_eq!(game.vm.vars.get(14), 0, "no poll ran this frame");

    game.frame();
    assert_eq!(game.vm.vars.get(3), key::CODE_OK);
    assert_eq!(game.vm.vars.get(4), key::CODE_OK);
    assert_eq!(
        game.vm.vars.get(13),
        1,
        "the carried click reached event 20"
    );
    assert_eq!(
        game.vm.vars.get(14),
        1,
        "the carried click reached event 21"
    );

    for _ in 0..3 {
        game.frame();
    }
    assert_eq!(game.vm.vars.get(13), 1, "the carried click fires once");
    assert_eq!(game.vm.vars.get(14), 1, "the carried click fires once");
}

fn two_real_parallel_events() -> Option<Map> {
    let path = data_root().join("MapData").join("SampleMapA.mps");
    let bytes = std::fs::read(&path).ok()?;
    let mut map = Map::parse(&bytes).ok()?;
    map.events.retain(|event| matches!(event.id, 16 | 26));
    if map.events.len() != 2 {
        return None;
    }
    Some(map)
}

fn clickable_picture(number: i32, x: i32, y: i32) -> Picture {
    let mut picture = Picture::new(number);
    picture.x = x;
    picture.y = y;
    picture.window = Some((200, 80));
    picture.anchor = ANCHOR_TOP_LEFT;
    picture
}

/// Real data: SampleMapA events 16 (`コマンド実行`) and 26
/// (`システム関係の監視`) are both parallel pages. Event 16 writes the hovered
/// command index into v67; event 26 plays its click SE when picture 1112 is
/// hovered. One press must make both real scripts react in the same frame.
#[test]
fn real_sample_map_events_16_and_26_both_react_to_one_click() {
    let Some(map) = two_real_parallel_events() else {
        eprintln!("skipping real parallel-input test: SampleMapA.mps has no event 16/26");
        return;
    };
    let Some(mut game) = open_game() else {
        return;
    };

    game.vm.vars.set(100, 1);
    game.vm.vars.set(101, 1);
    game.mouse = [300, 240];
    game.screen.insert(clickable_picture(400, 200, 200));
    game.screen.insert(clickable_picture(1112, 200, 200));
    game.start_pages(&map, None);

    // Let the parallel pages install themselves and settle. No click yet, so
    // neither script may produce its click side effect.
    for _ in 0..3 {
        game.frame();
    }
    assert_eq!(game.vm.vars.get(67), 0, "no click yet");

    game.mouse_buttons = 1;
    game.frame();
    assert_eq!(
        game.vm.vars.get(67),
        1,
        "event 16's real 123 poll saw the command click"
    );
    assert!(
        game.sounds
            .iter()
            .any(|sound| sound.file == "SE/Enter.wav" && sound.action == SoundAction::Play),
        "event 26's real 123 poll saw the same click and played its SE"
    );

    for _ in 0..3 {
        game.frame();
    }
    assert!(
        !game.sounds.iter().any(|sound| sound.file == "SE/Enter.wav"),
        "holding the button must not repeat the click in real data"
    );
    game.mouse_buttons = 0;
    game.frame();
}
