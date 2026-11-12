//! M16 VM/scheduler integration regressions.
//!
//! These cases sit above the wolf-vm unit tests: they load the shipped common-event
//! data, compile it with `ProgramSet`, and drive the public `Vm`/`AutoEvents` API.
//! Data-backed tests print a skip notice and return when the repository data root is
//! unavailable, so a default workspace run stays green on machines without the game
//! files.

use std::collections::{BTreeMap, BTreeSet};
use std::path::PathBuf;
use std::sync::Arc;

use wolf_format::command::{Command, Slot, Tail};
use wolf_format::commonevent::CommonEventData;
use wolf_game::auto_events::{AutoEvent, AutoEvents};
use wolf_vm::magic::VAR_BASE;
use wolf_vm::program::{Program, ProgramSet};
use wolf_vm::{Host, InstanceId, Vm};

fn repo_root() -> PathBuf {
    let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    path.pop();
    path.pop();
    path
}

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let path = PathBuf::from(raw);
    if path.is_absolute() {
        path
    } else {
        repo_root().join(path)
    }
}

/// Loads the retail common-event table and verifies the save fixture named by the
/// task is present. Tests that need real data call this and return on `None`.
fn game_data() -> Option<(CommonEventData, PathBuf)> {
    let root = data_root();
    let common = root.join("BasicData").join("CommonEvent.dat");
    if !common.is_file() {
        eprintln!("skipping: missing {}", common.display());
        return None;
    }
    let save = root.join("Save").join("SaveData01.sav");
    if !save.is_file() {
        eprintln!("skipping: missing {}", save.display());
        return None;
    }
    let bytes = match std::fs::read(&common) {
        Ok(bytes) => bytes,
        Err(err) => {
            eprintln!("skipping: cannot read {}: {err}", common.display());
            return None;
        }
    };
    let events = match CommonEventData::parse(&bytes) {
        Ok(events) => events,
        Err(err) => {
            eprintln!("skipping: cannot parse {}: {err}", common.display());
            return None;
        }
    };
    Some((events, root))
}

fn cmd(opcode: u32, args: &[i32]) -> Slot {
    let mut params = Vec::with_capacity(args.len() * 4);
    for arg in args {
        params.extend_from_slice(&arg.to_le_bytes());
    }
    Slot::Command(Box::new(Command {
        param_count: (args.len() + 1).try_into().expect("command fits params"),
        opcode,
        params,
        branch_depth: 0,
        strings: Vec::new(),
        tail: Tail::None,
    }))
}

fn synthetic_event(id: u32, slots: Vec<Slot>) -> Arc<Program> {
    Arc::new(Program::from_slots(id, "m16 synthetic", slots))
}

struct Quiet;

impl Host for Quiet {}

fn auto_event<'a>(events: &'a [AutoEvent], id: u32) -> &'a AutoEvent {
    events
        .iter()
        .find(|event| event.id == id)
        .unwrap_or_else(|| panic!("CE{id} must be tracked by AutoEvents"))
}

fn set_condition(vm: &mut Vm, event: &AutoEvent, value: i32) {
    let index = usize::try_from(event.variable - VAR_BASE as u32)
        .expect("auto-event condition must use the variable bank");
    vm.vars.set(index, value);
}

fn common_self(vm: &Vm, instance: InstanceId, event: u32, slot: usize) -> i32 {
    if let Some(inst) = vm.instance(instance) {
        return inst.self_vars.get(slot);
    }
    vm.vars
        .common_self
        .get(&event)
        .map_or(0, |bank| bank.get(slot - 600))
}

#[test]
fn op176_real_events_compile_cleanly_and_counted_continue_closes() {
    let Some((data, _)) = game_data() else {
        return;
    };
    let programs = ProgramSet::from_common_events(&data);

    let mut events_with_176 = 0usize;
    for event in &data.events {
        if !event.commands.iter().any(|slot| slot.opcode() == 176) {
            continue;
        }
        events_with_176 += 1;
        let program = programs
            .event(event.id)
            .unwrap_or_else(|| panic!("CE{} was not compiled", event.id));
        assert_eq!(
            program.stats.implicit_closes, 0,
            "CE{} has implicit block closes",
            event.id
        );
        assert_eq!(
            program.stats.unclosed_blocks, 0,
            "CE{} leaves blocks open",
            event.id
        );
        assert_eq!(
            program.stats.blocks,
            program.stats.conditions + program.stats.choices + program.stats.loops,
            "CE{} block count must partition by kind",
            event.id
        );
    }
    assert!(
        events_with_176 >= 4,
        "the shipped table must contain several 176 sites"
    );

    for id in [63u32, 212, 268, 270] {
        let program = programs
            .event(id)
            .unwrap_or_else(|| panic!("CE{id} must exist"));
        assert!(
            program.slots.iter().any(|slot| slot.opcode() == 176),
            "CE{id} should contain ContinueLoop"
        );
        assert!(
            program.stats.loops > 0,
            "CE{id} must compile at least one loop block"
        );
        assert_eq!(
            program.stats.implicit_closes, 0,
            "CE{id} must not repair a 176 site as an implicit close"
        );
        assert_eq!(program.stats.unclosed_blocks, 0, "CE{id} loop stack");
    }

    // A counted loop driven through 176 exercises both paths: the first iterations
    // jump back to the loop head, and the final iteration exits after the body.
    let program = synthetic_event(
        900,
        vec![
            cmd(179, &[4]),
            cmd(121, &[VAR_BASE + 0, 1, 0, 0x0104]),
            cmd(176, &[]),
            cmd(121, &[VAR_BASE + 1, 1, 0, 0x0104]),
            cmd(498, &[]),
        ],
    );
    let mut vm = Vm::new(ProgramSet::default());
    let instance = vm
        .start_program(program)
        .expect("synthetic ContinueLoop event starts");
    let mut host = Quiet;
    vm.step_frame(&mut host);
    assert_eq!(vm.vars.get(0), 4, "counted loop body must run four times");
    assert_eq!(
        vm.vars.get(1),
        0,
        "instructions after 176 must be skipped on every iteration"
    );
    assert!(
        vm.instance(instance).is_none(),
        "the final 176 must exit the counted loop and finish the event"
    );
}

#[test]
fn op121_flag_bits_apply_clamp_real_literal_indirection_and_batch() {
    let program = synthetic_event(
        901,
        vec![
            // 0x01: the result is clamped to +/-999999 after evaluation.
            cmd(121, &[VAR_BASE + 12, VAR_BASE + 2, 0, 0x0001]),
            cmd(121, &[VAR_BASE + 13, VAR_BASE + 3, 0, 0x0001]),
            // 0x02: f64 arithmetic. 30 * (2500 / 1000.0) = 75, not integer 60.
            cmd(121, &[VAR_BASE + 4, 2500, 1000, 0x3302]),
            // 0x04 / 0x08: the RHS words are literals and must not be dereferenced.
            cmd(121, &[VAR_BASE + 7, VAR_BASE + 5, 0, 0x0004]),
            cmd(121, &[VAR_BASE + 8, 5, VAR_BASE + 6, 0x0008]),
            // 0x10: lhs is a second-order pointer (var0 holds VAR_BASE + 10).
            cmd(121, &[VAR_BASE, 5, 0, 0x0110]),
            // 0x20: rhs1 is a second-order pointer (var1 holds VAR_BASE + 20).
            cmd(121, &[VAR_BASE + 11, VAR_BASE + 1, 0, 0x0020]),
            // bit16: batch assignment, count = arg4, inclusive.
            cmd(121, &[VAR_BASE + 30, 42, 0, 0x10000, 2]),
        ],
    );
    let mut vm = Vm::new(ProgramSet::default());
    vm.vars.set(0, VAR_BASE + 10);
    vm.vars.set(1, VAR_BASE + 20);
    vm.vars.set(2, 2_000_000);
    vm.vars.set(3, -2_000_000);
    vm.vars.set(4, 30);
    vm.vars.set(5, 100);
    vm.vars.set(6, 20);
    vm.vars.set(10, 7);
    vm.vars.set(20, 9);
    vm.vars.set(33, -7);

    vm.start_program(program)
        .expect("synthetic opcode-121 event");
    vm.step_frame(&mut Quiet);

    assert_eq!(vm.vars.get(12), 999_999, "0x01 clamps the positive result");
    assert_eq!(vm.vars.get(13), -999_999, "0x01 clamps the negative result");
    assert_eq!(vm.vars.get(4), 75, "0x02 uses f64 before converting back");
    assert_eq!(vm.vars.get(7), VAR_BASE + 5, "0x04 keeps rhs1 as a literal");
    assert_eq!(
        vm.vars.get(8),
        5 + VAR_BASE + 6,
        "0x08 keeps rhs2 as a literal"
    );
    assert_eq!(vm.vars.get(10), 12, "0x10 dereferences the lhs target");
    assert_eq!(vm.vars.get(11), 9, "0x20 dereferences the rhs operand");
    assert_eq!(
        (vm.vars.get(30), vm.vars.get(31), vm.vars.get(32)),
        (42, 42, 42),
        "bit16 writes count + 1 consecutive variables"
    );
    assert_eq!(vm.vars.get(33), -7, "batch must stop at arg4");
}

#[test]
fn auto_events_level_trigger_restarts_real_events_and_false_stops_them() {
    let Some((data, _)) = game_data() else {
        return;
    };
    let programs = ProgramSet::from_common_events(&data);
    let mut vm = Vm::new(programs);
    let mut auto = AutoEvents::from_common_events(&data);
    let targets = [241u32, 242, 281, 282];
    let events: Vec<AutoEvent> = targets
        .iter()
        .map(|id| auto_event(auto.events(), *id).clone())
        .collect();

    for event in &events {
        set_condition(&mut vm, event, event.value as i32);
    }
    let first = auto.sync(&mut vm);
    assert!(
        first.started >= targets.len(),
        "all four real level conditions must start"
    );
    for id in targets {
        assert!(auto.instance(id).is_some(), "CE{id} must be running");
        assert!(
            vm.instance(auto.instance(id).expect("started"))
                .is_some_and(|inst| inst.is_parallel),
            "CE{id} is a parallel auto event"
        );
    }

    let mut old_ids: BTreeMap<u32, InstanceId> = targets
        .iter()
        .map(|id| (*id, auto.instance(*id).expect("started")))
        .collect();
    let mut restarted = BTreeSet::new();
    let mut host = Quiet;
    for _ in 0..2_500 {
        vm.step_frame(&mut host);
        auto.sync(&mut vm);
        for id in targets {
            if restarted.contains(&id) {
                continue;
            }
            let old = old_ids[&id];
            let new = auto.instance(id);
            if vm.instance(old).is_none() && new.is_some_and(|new| new != old) {
                restarted.insert(id);
            }
        }
        old_ids = targets
            .iter()
            .filter_map(|id| auto.instance(*id).map(|instance| (*id, instance)))
            .collect();
        if restarted.len() == targets.len() {
            break;
        }
    }
    assert_eq!(
        restarted,
        targets.into_iter().collect(),
        "each true level condition must reopen after its instance ends"
    );

    for event in &events {
        let false_value = match event.operator {
            1 => event.value as i32 - 1,
            2 => event.value as i32 + 1,
            3 => event.value as i32 + 1,
            operator => panic!("unexpected AutoEvents operator {operator}"),
        };
        set_condition(&mut vm, event, false_value);
    }
    let live: BTreeMap<u32, InstanceId> = targets
        .iter()
        .filter_map(|id| auto.instance(*id).map(|instance| (*id, instance)))
        .collect();
    let stopped = auto.sync(&mut vm);
    assert!(
        stopped.stopped >= live.len(),
        "a false level condition must stop its live instance"
    );
    for id in targets {
        assert!(auto.instance(id).is_none(), "CE{id} must be unregistered");
        assert!(
            !vm.instances().iter().any(|instance| instance.event == id),
            "CE{id} must have no live coroutine after the condition turns false"
        );
    }
}

#[test]
fn field18_ce223_hits_the_foreground_window_branch() {
    let Some((data, _)) = game_data() else {
        return;
    };
    let programs = ProgramSet::from_common_events(&data);
    let mut vm = Vm::new(programs);
    let bg = vm.start_event(223).expect("CE223 must exist");
    vm.set_instance_parallel(bg, true);
    let foreground = vm.start_event(131).expect("CE131 must exist");
    vm.vars.set_sys(111, 1);
    // CE223 only enters its window dispatch after confirming that cursor picture
    // 100000 exists; seed the inherited flag the way a running cursor layer does.
    vm.set_instance_self_var(bg, 640, 1);
    // The 500131 branch copies `15_013_110`, i.e. CE131 CSelf10, into CE223
    // CSelf15. A distinctive source value keeps the branch assertion meaningful.
    vm.set_instance_self_var(foreground, 610, 654_321);

    let mut host = Quiet;
    vm.step_frame(&mut host);
    assert_eq!(
        common_self(&vm, bg, 223, 610),
        500_131,
        "field 18 must name the foreground CE131, not CE223 itself"
    );
    assert_eq!(
        common_self(&vm, bg, 223, 615),
        654_321,
        "CE223 must execute its 500131 window branch and read CE131 CSelf10"
    );
    assert!(
        vm.instance(foreground).is_some(),
        "CE131 must remain the foreground owner while CE223 reads field 18"
    );

    // A host-provided field 18 value has priority over the interpreter's foreground
    // fallback, matching the documented lookup order.
    struct Field18(i32);
    impl Host for Field18 {
        fn engine_state(&mut self, field: i32) -> Option<i32> {
            (field == 18).then_some(self.0)
        }
    }

    let mut vm = Vm::new(ProgramSet::from_common_events(&data));
    let bg = vm.start_event(223).expect("CE223 must exist");
    vm.set_instance_parallel(bg, true);
    vm.vars.set_sys(111, 1);
    vm.set_instance_self_var(bg, 640, 1);
    let mut host = Field18(500_132);
    vm.step_frame(&mut host);
    assert_eq!(
        common_self(&vm, bg, 223, 610),
        500_132,
        "host field 18 overrides the foreground-event fallback"
    );
}
