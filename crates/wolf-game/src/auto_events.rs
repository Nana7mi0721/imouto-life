//! Scheduler for common events whose header says `run_condition == 2`
//! (parallel process with a condition).
//!
//! WOLF's four run conditions are measured on this game's 550 events as
//! `{0: 442, 1: 1, 2: 97, 3: 10}` (docs/ENGINE_EVENTS.md section 2.2). The ten
//! `run_condition == 3` events are engine-owned always-on coroutines and live in
//! [`crate::game::ENGINE_ALWAYS`]; the single `run_condition == 1` event is
//! [`crate::game::ENGINE_AUTO_START`]. This module owns the remaining 97: each one
//! is created when its condition becomes true and destroyed when it becomes false.
//!
//! The scheduler is level-triggered. A condition that stays true restarts a
//! coroutine that ended on its own (matching WOLF's looping parallel execution for
//! `run_condition == 2` events), while a condition that becomes false immediately
//! stops and discards any running coroutine. Event 43 is the lone one-shot exception;
//! it is started on the false-to-true edge of the title-menu gate and is replayed
//! explicitly by [`crate::game::Game::frame`] when the cursor changes.
//!
//! ## The title menu renderer (event 43)
//!
//! Event 43 (`┗オリジナルタイトル画面Ｂ`) has zero 210/211/300 call sites, but it is
//! NOT dead code: it is the original title screen's menu renderer. On its own page life
//! it draws the three hand-drawn image buttons `Picture/menu1_b`/`menu2_b`/`menu3_b`
//! at x=10, y=400/450/500, and overlays the dark selected variant (`menu*_a`) of
//! whichever row system variable 20 selects. The `_b` files are the lighter,
//! unselected buttons; `_a` is the dark highlight. Its run condition (global v0 == 0)
//! holds only at the title, but the event itself draws once and ends. It therefore
//! starts on the title-menu gate's rising edge, not whenever the level stays true;
//! [`crate::game::Game::frame`] replays it on a cursor change so the highlight tracks
//! the player's selection. The previous port excluded it as a "dead title variant" and
//! painted an inferred text panel instead, which is why the title menu looked wrong;
//! see docs/M3_TITLE_UX.md.

use std::collections::BTreeMap;

use wolf_format::commonevent::CommonEventData;
use wolf_vm::exec::InstanceId;
use wolf_vm::magic::{SELF_ARG_BASE, VAR_BASE};
use wolf_vm::Vm;

/// Event id -> condition operator / variable / value, taken from the event header.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct AutoEvent {
    /// Common event id.
    pub id: u32,
    /// Editor title, for diagnostics.
    pub title: String,
    /// Comparison operator (1 `>=`, 2 `==`, 3 `<=`; measured on all 97 events).
    pub operator: u8,
    /// Raw ordinary-variable address (`2_000_000 + n`).
    pub variable: u32,
    /// Right-hand side of the comparison.
    pub value: u32,
    /// Declared numeric default arguments, truncated to `arg_num_count`.
    ///
    /// A bare scheduler start has no caller to supply `210` arguments, so the
    /// event header's defaults are the only correct initial self values.
    pub default_args: Vec<i32>,
}

/// Events this scheduler deliberately does not start.
///
/// Empty: every `run_condition == 2` event in this data set is live. Event 43, once
/// listed here as a "dead title variant", is actually the title menu renderer and is
/// scheduled normally; see the module documentation.
pub const SKIPPED: &[u32] = &[];

/// `run_condition == 0` events that the engine never starts on its own but that
/// this runtime must start from a condition variable, because the battle flow
/// relies on them.
///
/// WOLF's `run_condition == 0` ("called only") events normally run only when a
/// 210/211/300 instruction calls them. The battle state machine breaks that
/// rule: `CE242` (condvar 2000350 == 1) and `CE243` (condvar 2000350 == 2) have
/// zero static call sites and are started purely by the engine watching their
/// condition (docs/BATTLE.md section 1.3). This is the same edge-triggered
/// condition scheduler as the `run_condition == 2` events; the list is an
/// explicit allow-list so the other thirteen dormant `run==0` events seen on
/// this data set are not accidentally woken (they are not validated battle
/// entry points). Both conditions are false at boot (2000350 == 0), so they
/// cost nothing until the battle sets 2000350.
pub const GATED_CALL_ONLY: &[u32] = &[242, 243];

/// Result of one scheduler pass.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct SyncReport {
    /// Coroutines created this pass.
    pub started: usize,
    /// Coroutines stopped this pass.
    pub stopped: usize,
    /// Coroutines still alive after the pass.
    pub running: usize,
}

/// The run-condition-2 scheduler.
#[derive(Debug, Default)]
pub struct AutoEvents {
    events: Vec<AutoEvent>,
    /// Last observed truth value, so a transition can be detected. For event 43 this
    /// records the title-menu gate edge rather than the raw header condition.
    latched: BTreeMap<u32, bool>,
    /// Instance ids of coroutines this scheduler owns. When a coroutine ends
    /// naturally while its condition remains true, the scheduler starts a fresh
    /// copy on the next pass (level-triggered parallel execution). When the condition
    /// becomes false, the coroutine is stopped and removed.
    running: BTreeMap<u32, InstanceId>,
    enabled: bool,
    /// Whether the title menu is actually up. The title menu renderer (event 43) has a
    /// script condition (global v0 == 0) that can also hold in synthetic states where v0
    /// was never set; gating it here keeps the title buttons from painting over a scene.
    title_menu_active: bool,
}

impl AutoEvents {
    /// Collects every `run_condition == 2` event except [`SKIPPED`].
    #[must_use]
    pub fn from_common_events(data: &CommonEventData) -> Self {
        let events = data
            .events
            .iter()
            .filter(|event| {
                !SKIPPED.contains(&event.id)
                    && (event.run_condition() == 2
                        || (event.run_condition() == 0 && GATED_CALL_ONLY.contains(&event.id)))
            })
            .map(|event| {
                let default_args = event
                    .default_values
                    .iter()
                    .copied()
                    .take(event.arg_num_count as usize)
                    .collect();
                AutoEvent {
                    id: event.id,
                    title: event.title.clone(),
                    operator: event.condition_operator(),
                    variable: event.condition_variable,
                    value: event.condition_value,
                    default_args,
                }
            })
            .collect();
        Self {
            events,
            latched: BTreeMap::new(),
            running: BTreeMap::new(),
            enabled: true,
            title_menu_active: false,
        }
    }

    /// Tells the scheduler whether the title menu (the three `menu1/2/3` options) is up.
    ///
    /// Event 43 (the title menu renderer) is only allowed to run while this is true, so
    /// its `v0 == 0` script condition cannot light it up in a scene where v0 happens to
    /// be 0 for unrelated reasons.
    pub fn set_title_menu_active(&mut self, active: bool) {
        self.title_menu_active = active;
    }

    /// Number of tracked events (98 = 96 `run==2` + 2 gated `run==0` calls).
    #[must_use]
    pub fn len(&self) -> usize {
        self.events.len()
    }

    /// Whether no event is tracked.
    #[must_use]
    pub fn is_empty(&self) -> bool {
        self.events.is_empty()
    }

    /// Enables or disables the scheduler, used by tests and A/B captures.
    pub fn set_enabled(&mut self, enabled: bool) {
        self.enabled = enabled;
    }

    /// Whether the scheduler is enabled.
    #[must_use]
    pub fn enabled(&self) -> bool {
        self.enabled
    }

    /// The tracked events, for diagnostics and tests.
    #[must_use]
    pub fn events(&self) -> &[AutoEvent] {
        &self.events
    }

    /// Coroutines currently alive.
    #[must_use]
    pub fn running_count(&self) -> usize {
        self.running.len()
    }

    /// The instance id of a tracked event, if it was started and has not been
    /// stopped by a failing condition.
    #[must_use]
    pub fn instance(&self, event: u32) -> Option<InstanceId> {
        self.running.get(&event).copied()
    }

    /// Event ids this scheduler currently owns, for diagnostics.
    #[must_use]
    pub fn running_ids(&self) -> Vec<u32> {
        self.running.keys().copied().collect()
    }

    /// Resets runtime state of the scheduler.
    pub fn reset(&mut self) {
        self.latched.clear();
        self.running.clear();
        self.title_menu_active = false;
    }

    /// Restarts one owned event from its first instruction.
    ///
    /// The title menu renderer (event 43) draws one frame and ends, so moving the
    /// highlight has to replay it: it reads Sys20 only at start-up. The scheduler's
    /// normal condition edge stays latched, which keeps [`Self::sync`] from starting
    /// a second copy on the next frame.
    pub fn restart(&mut self, event: u32, vm: &mut Vm) -> bool {
        if !self.enabled {
            return false;
        }
        if let Some(instance) = self.running.remove(&event) {
            vm.stop_instance(instance);
        }
        let defaults: &[i32] = self
            .events
            .iter()
            .find(|tracked| tracked.id == event)
            .map_or(&[], |tracked| &tracked.default_args);
        match start_event_with_defaults(vm, event, defaults) {
            Some(instance) => {
                vm.set_instance_parallel(instance, true);
                self.running.insert(event, instance);
                self.latched.insert(event, true);
                true
            }
            None => false,
        }
    }

    /// Evaluates every condition and creates or destroys coroutines as needed.
    pub fn sync(&mut self, vm: &mut Vm) -> SyncReport {
        let mut report = SyncReport::default();
        if !self.enabled {
            return report;
        }
        for event in &self.events {
            let header_condition = condition_value(vm, event.variable).map_or(false, |left| {
                condition_met(event.operator, left, event.value)
            });
            // Event 43 is the title menu renderer: only run it while the title menu is up.
            let now = header_condition && (event.id != 43 || self.title_menu_active);
            let alive = self
                .running
                .get(&event.id)
                .is_some_and(|id| vm.instance(*id).is_some());
            let before = self.latched.get(&event.id).copied().unwrap_or(false);
            if now {
                // CE43 is a one-shot renderer: it paints the three rows/highlight and
                // ends. Restart it only when the title menu becomes active (or on the
                // explicit `restart(43)` from a cursor change), never merely because
                // the level-triggered header condition is still true.
                let should_start = if event.id == 43 { !before } else { !alive };
                if should_start {
                    if let Some(instance) =
                        start_event_with_defaults(vm, event.id, &event.default_args)
                    {
                        vm.set_instance_parallel(instance, true);
                        self.running.insert(event.id, instance);
                        report.started += 1;
                    }
                }
            } else if let Some(instance) = self.running.remove(&event.id) {
                if vm.stop_instance(instance) {
                    report.stopped += 1;
                }
            }
            self.latched.insert(event.id, now);
        }
        report.running = self
            .running
            .values()
            .filter(|instance| vm.instance(**instance).is_some())
            .count();
        report
    }
}

/// Starts an owned event and replaces only its declared numeric arguments.
///
/// `Vm::start_event` seeds a fresh instance from the durable common-self bank.
/// That bank may hold an explicit `210` caller's arguments, which must not leak
/// into a bare scheduler start. The defaults are written directly into this new
/// instance's group-6 call-argument slots; the durable bank and sibling instances
/// of the same event are left alone, so an explicit call cannot contaminate a
/// parallel scheduler instance (and vice versa).
fn start_event_with_defaults(vm: &mut Vm, event: u32, defaults: &[i32]) -> Option<InstanceId> {
    let instance = vm.start_event(event)?;
    if let Some(inst) = vm.instance_mut(instance) {
        for (slot, value) in defaults.iter().enumerate() {
            inst.self_vars.set(SELF_ARG_BASE + slot, *value);
        }
    }
    Some(instance)
}

/// Reads a normal-variable operand used by a run condition.
///
/// Every one of the 108 automatic events names an ordinary variable in
/// `2_000_000..2_999_999` (docs/ENGINE_EVENTS.md section 2.3), so the only legal
/// address is `VAR_BASE + 0..800`.
fn condition_value(vm: &Vm, raw: u32) -> Option<i32> {
    let index = raw.checked_sub(VAR_BASE as u32)? as usize;
    if index < 800 {
        Some(vm.vars.get(index))
    } else {
        None
    }
}

/// Applies one run-condition operator to the two operands.
///
/// Measured operators on the 97 `run_condition == 2` events are only `>=` (77),
/// `==` (19) and `<=` (1). An unknown operator is treated as false and must never
/// start a coroutine.
#[must_use]
pub fn condition_met(operator: u8, left: i32, right: u32) -> bool {
    let right = right as i32;
    match operator {
        1 => left >= right,
        2 => left == right,
        3 => left <= right,
        _ => false,
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::PathBuf;
    use wolf_format::command::Slot;
    use wolf_format::commonevent::CommonEvent;
    use wolf_vm::program::NO_RETURN_VALUE;
    use wolf_vm::{ProgramSet, Vm};

    struct Quiet;

    impl wolf_vm::Host for Quiet {}

    fn data_root() -> PathBuf {
        if let Ok(value) = std::env::var("WOLF_DATA_ROOT") {
            if !value.is_empty() {
                return PathBuf::from(value);
            }
        }
        let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        path.pop();
        path.pop();
        path.push("work");
        path.push("full");
        path
    }

    fn have_data() -> Option<(CommonEventData, PathBuf)> {
        let root = data_root();
        let file = root.join("BasicData").join("CommonEvent.dat");
        let Ok(bytes) = std::fs::read(&file) else {
            eprintln!("skipping: no game data at {}", file.display());
            return None;
        };
        Some((
            CommonEventData::parse(&bytes).expect("CommonEvent.dat"),
            root,
        ))
    }

    fn synthetic_parallel_data(arg_num_count: u8, default_values: Vec<i32>) -> CommonEventData {
        CommonEventData {
            version_header: 0x55,
            version: 0xC9,
            events: vec![CommonEvent {
                id: 10,
                raw_condition: 0x22, // run_condition 2, operator ==
                condition_variable: VAR_BASE as u32,
                condition_value: 1,
                arg_num_count,
                arg_str_count: 0,
                title: "parallel_loop".to_string(),
                commands: vec![Slot::Blank],
                memo: String::new(),
                arg_names: Vec::new(),
                arg_special_spec: Vec::new(),
                arg_string_pages: Vec::new(),
                arg_value_pages: Vec::new(),
                default_values,
                color: 0,
                self_variable_names: Vec::new(),
                return_name: String::new(),
                return_value_id: NO_RETURN_VALUE,
            }],
            footer: 0x90,
        }
    }

    fn synthetic_title_menu_data() -> CommonEventData {
        let mut data = synthetic_parallel_data(0, Vec::new());
        let event = &mut data.events[0];
        event.id = 43;
        event.condition_value = 0;
        event.title = "title menu".to_string();
        data
    }

    fn assert_default_arg(vm: &Vm, instance: InstanceId, event: u32, slot: usize, value: i32) {
        assert_eq!(
            vm.instance(instance)
                .expect("instance must be alive")
                .self_vars
                .get(SELF_ARG_BASE + slot),
            value,
            "CE{event} call-argument slot {slot}"
        );
    }

    #[test]
    fn the_scheduler_tracks_every_run_condition_two_event() {
        let Some((data, _)) = have_data() else { return };
        let auto = AutoEvents::from_common_events(&data);
        let run_two = data
            .events
            .iter()
            .filter(|event| event.run_condition() == 2)
            .count();
        assert_eq!(auto.len(), run_two, "all run=2 events must be tracked");
        assert!(auto
            .events()
            .iter()
            .all(|event| matches!(event.operator, 1..=3)));
        assert!(auto.events().iter().any(|event| event.id == 43));
        assert!(auto.events().iter().any(|event| event.id == 223));
        assert!(auto.events().iter().any(|event| event.id == 242));
        assert!(auto.events().iter().any(|event| event.id == 243));
        assert!(!auto.events().iter().any(|event| event.id == 38));
    }

    #[test]
    fn ce242_and_ce243_follow_their_shared_trigger() {
        let Some((data, _)) = have_data() else { return };
        let programs = ProgramSet::from_common_events(&data);
        let mut vm = Vm::new(programs);
        let mut auto = AutoEvents::from_common_events(&data);
        let clock = auto
            .events()
            .iter()
            .find(|event| event.id == 243)
            .expect("CE243");
        let condition = usize::try_from(clock.variable - VAR_BASE as u32).expect("variable");
        let trigger = clock.value as i32;

        // Dormant at boot: both display events share the clock's trigger variable.
        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 0, "no run=2 event is true at boot");
        assert!(!vm.instances().iter().any(|instance| instance.event == 242));
        assert!(!vm.instances().iter().any(|instance| instance.event == 243));
        // The display pair starts together.
        vm.vars.set(condition, trigger);
        auto.sync(&mut vm);
        assert!(vm.instances().iter().any(|instance| instance.event == 242));
        assert!(vm.instances().iter().any(|instance| instance.event == 243));
        // Lowering the trigger stops both.
        vm.vars.set(condition, 0);
        auto.sync(&mut vm);
        assert!(!vm.instances().iter().any(|instance| instance.event == 242));
        assert!(!vm.instances().iter().any(|instance| instance.event == 243));
    }

    #[test]
    fn the_three_measured_operators_compare_like_wolf() {
        assert!(condition_met(1, 2, 2));
        assert!(!condition_met(1, 1, 2));
        assert!(condition_met(2, 2, 2));
        assert!(!condition_met(2, 3, 2));
        assert!(condition_met(3, 2, 2));
        assert!(!condition_met(3, 3, 2));
        assert!(!condition_met(99, 2, 2), "unknown operators never fire");
    }

    #[test]
    fn a_true_condition_starts_an_event_and_false_stops_it() {
        let Some((data, _)) = have_data() else { return };
        let programs = ProgramSet::from_common_events(&data);
        let mut vm = Vm::new(programs);
        let mut auto = AutoEvents::from_common_events(&data);
        let event = auto
            .events()
            .iter()
            .find(|event| event.id == 223)
            .expect("CE223");
        let condition = usize::try_from(event.variable - VAR_BASE as u32).expect("variable");
        let trigger = event.value as i32;

        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 0);
        assert!(!vm.instances().iter().any(|instance| instance.event == 223));
        vm.vars.set(condition, trigger);
        let report = auto.sync(&mut vm);
        assert!(report.started >= 1);
        assert!(vm.instances().iter().any(|instance| instance.event == 223));
        vm.vars.set(condition, trigger - 1);
        let report = auto.sync(&mut vm);
        assert!(report.stopped >= 1);
        assert!(!vm.instances().iter().any(|instance| instance.event == 223));
    }

    #[test]
    fn parallel_event_restarts_when_finished_while_condition_is_true_and_stops_when_false() {
        let data = synthetic_parallel_data(0, Vec::new());

        let mut vm = Vm::new(ProgramSet::from_common_events(&data));
        let mut auto = AutoEvents::from_common_events(&data);

        // When condition is false (var 0 == 0), event does not start.
        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 0);
        assert_eq!(report.running, 0);

        // When condition becomes true (var 0 == 1), first sync starts it.
        vm.vars.set(0, 1);
        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 1);
        assert_eq!(report.running, 1);
        let first_id = auto.instance(10).expect("instance started");
        assert!(vm.instance(first_id).is_some());

        // Step one frame to let event 10 finish and be reaped.
        let mut host = Quiet;
        let _ = vm.step_frame(&mut host);
        assert!(
            vm.instance(first_id).is_none(),
            "event should have finished"
        );

        // Next sync: condition remains true (var 0 == 1).
        // Level triggering restarts the event!
        let report = auto.sync(&mut vm);
        assert_eq!(
            report.started, 1,
            "finished event must restart while condition remains true"
        );
        assert_eq!(report.running, 1);
        let second_id = auto.instance(10).expect("instance restarted");
        assert_ne!(first_id, second_id, "must be a fresh instance");
        assert!(vm.instance(second_id).is_some());

        // When condition becomes false, next sync stops it immediately.
        vm.vars.set(0, 0);
        let report = auto.sync(&mut vm);
        assert_eq!(
            report.stopped, 1,
            "must stop immediately when condition becomes false"
        );
        assert_eq!(report.running, 0);
        assert!(vm.instance(second_id).is_none());
    }

    #[test]
    fn ce43_starts_only_on_the_title_menu_gate_edge() {
        let data = synthetic_title_menu_data();
        let mut vm = Vm::new(ProgramSet::from_common_events(&data));
        let mut auto = AutoEvents::from_common_events(&data);
        let mut host = Quiet;

        // The header condition (v0 == 0) is already true, but the title menu gate is
        // closed, so the renderer must stay dormant.
        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 0);
        assert!(auto.instance(43).is_none());

        // First false-to-true edge of the title menu starts it once.
        auto.set_title_menu_active(true);
        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 1);
        let first = auto.instance(43).expect("CE43 first instance");
        assert!(vm.instance(first).is_some());
        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 0, "an alive renderer is not started twice");

        // CE43 draws one frame and ends. The gate stays active, so the level-triggered
        // header condition must not start another copy.
        vm.step_frame(&mut host);
        assert!(vm.instance(first).is_none(), "CE43 must finish its pass");
        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 0, "active menu does not replay CE43");
        assert!(
            auto.instance(43).is_some(),
            "ownership remains until the gate closes"
        );

        // Closing the gate retires the finished renderer and a later rising edge starts
        // a fresh instance.
        auto.set_title_menu_active(false);
        auto.sync(&mut vm);
        assert!(auto.instance(43).is_none());
        auto.set_title_menu_active(true);
        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 1);
        let second = auto
            .instance(43)
            .expect("CE43 restarted on the next rising edge");
        assert_ne!(first, second);

        // Closing the gate while the renderer is still alive stops it immediately.
        auto.set_title_menu_active(false);
        let report = auto.sync(&mut vm);
        assert_eq!(report.stopped, 1);
        assert!(vm.instance(second).is_none());
        assert!(auto.instance(43).is_none());
    }

    #[test]
    fn sync_and_restart_replace_stale_self_args_with_declared_defaults() {
        let data = synthetic_parallel_data(1, vec![0]);
        let mut vm = Vm::new(ProgramSet::from_common_events(&data));
        let mut auto = AutoEvents::from_common_events(&data);
        {
            let bank = vm.vars.common_self.entry(10).or_default();
            bank.set(0, 10);
            bank.set(1, 99);
        }
        vm.vars.set(0, 1);

        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 1);
        let first = auto.instance(10).expect("instance started");
        assert_default_arg(&vm, first, 10, 0, 0);
        assert_default_arg(&vm, first, 10, 1, 99);

        let mut host = Quiet;
        vm.step_frame(&mut host);
        assert!(vm.instance(first).is_none(), "blank event must finish");

        // A later caller may have put 10 back in the durable bank. The next bare
        // scheduler start must still use the event's declared default.
        vm.vars.common_self.entry(10).or_default().set(0, 10);
        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 1);
        let second = auto.instance(10).expect("instance restarted");
        assert_ne!(first, second);
        assert_default_arg(&vm, second, 10, 0, 0);
        assert_default_arg(&vm, second, 10, 1, 99);

        // `restart` follows the same rule and replaces only the new instance's
        // declared argument, leaving the non-argument slot seeded from the bank.
        vm.vars.common_self.entry(10).or_default().set(0, 10);
        assert!(auto.restart(10, &mut vm));
        let third = auto.instance(10).expect("instance restarted explicitly");
        assert_ne!(second, third);
        assert_default_arg(&vm, third, 10, 0, 0);
        assert_default_arg(&vm, third, 10, 1, 99);
    }

    #[test]
    fn ce243_auto_start_does_not_share_an_explicit_call_argument() {
        let Some((data, _)) = have_data() else { return };
        let programs = ProgramSet::from_common_events(&data);
        let mut vm = Vm::new(programs);
        let mut auto = AutoEvents::from_common_events(&data);
        let event = auto
            .events()
            .iter()
            .find(|event| event.id == 243)
            .expect("CE243");
        assert_eq!(event.default_args, vec![0]);
        let condition = usize::try_from(event.variable - VAR_BASE as u32).expect("variable");
        let trigger = event.value as i32;

        vm.vars.set(4, 19);
        vm.vars.set(5, 30);
        vm.vars.set(6, 0);
        // A previous explicit call left +10 in the durable bank. The bare
        // scheduler start must override that with the event's declared default
        // in its own instance only.
        vm.vars.common_self.entry(243).or_default().set(0, 10);
        vm.vars.set(condition, trigger);
        auto.sync(&mut vm);

        let auto_instance = auto.instance(243).expect("CE243 auto instance");
        assert_default_arg(&vm, auto_instance, 243, 0, 0);

        let explicit = vm
            .start_event_with_args(243, &[10], &[])
            .expect("explicit CE243 call");
        assert_default_arg(&vm, auto_instance, 243, 0, 0);
        assert_default_arg(&vm, explicit, 243, 0, 10);

        let mut host = Quiet;
        for _ in 0..5 {
            vm.step_frame(&mut host);
        }
        assert_eq!(
            (vm.vars.get(4), vm.vars.get(5)),
            (19, 40),
            "only the explicit +10 call must advance the clock"
        );
    }

    #[test]
    fn ce241_auto_start_applies_both_declared_default_args() {
        let Some((data, _)) = have_data() else { return };
        let programs = ProgramSet::from_common_events(&data);
        let mut vm = Vm::new(programs);
        let mut auto = AutoEvents::from_common_events(&data);
        let event = auto
            .events()
            .iter()
            .find(|event| event.id == 241)
            .expect("CE241");
        assert_eq!(event.default_args, vec![0, 0]);
        let condition = usize::try_from(event.variable - VAR_BASE as u32).expect("variable");
        let trigger = event.value as i32;

        {
            let bank = vm.vars.common_self.entry(241).or_default();
            bank.set(0, 7);
            bank.set(1, 8);
        }
        vm.vars.set(condition, trigger);
        auto.sync(&mut vm);

        let instance = auto.instance(241).expect("CE241 auto instance");
        assert_default_arg(&vm, instance, 241, 0, 0);
        assert_default_arg(&vm, instance, 241, 1, 0);
    }
}
