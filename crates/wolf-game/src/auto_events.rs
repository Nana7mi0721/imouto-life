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
//! The scheduler is edge-triggered. A condition that stays true does not restart a
//! coroutine that ended on its own, and a condition that stays false does nothing.
//! That matches WOLF's page lifecycle ("created while the condition holds, discarded
//! when it fails") without turning a one-shot event into a per-frame loop.
//!
//! ## The title menu renderer (event 43)
//!
//! Event 43 (`┗オリジナルタイトル画面Ｂ`) has zero 210/211/300 call sites, but it is
//! NOT dead code: it is the original title screen's menu renderer. On its own page life
//! it draws the three hand-drawn image buttons `Picture/menu1_b`/`menu2_b`/`menu3_b`
//! at x=10, y=400/450/500, and overlays the dark selected variant (`menu*_a`) of
//! whichever row system variable 20 selects. The `_b` files are the lighter,
//! unselected buttons; `_a` is the dark highlight. Its run condition (global v0 == 0) holds only at the title,
//! so it must be scheduled exactly like every other `run_condition == 2` event; the port
//! then mirrors the choice cursor into Sys20 each frame so the highlight tracks the
//! player's selection (see [`crate::game::Game::frame`]). The previous port excluded it
//! as a "dead title variant" and painted an inferred text panel instead, which is why the
//! title menu looked wrong; see docs/M3_TITLE_UX.md.

use std::collections::BTreeMap;

use wolf_format::commonevent::CommonEventData;
use wolf_vm::exec::InstanceId;
use wolf_vm::magic::VAR_BASE;
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
    /// Last observed truth value, so a transition can be detected.
    latched: BTreeMap<u32, bool>,
    /// Instance ids of coroutines this scheduler owns. An entry stays here even
    /// after the coroutine ends naturally: the condition must go false before a
    /// second start is allowed (edge trigger).
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
            .map(|event| AutoEvent {
                id: event.id,
                title: event.title.clone(),
                operator: event.condition_operator(),
                variable: event.condition_variable,
                value: event.condition_value,
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
        match vm.start_event(event) {
            Some(instance) => {
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
            let before = self.latched.get(&event.id).copied().unwrap_or(false);
            if now && !before {
                if let Some(instance) = vm.start_event(event.id) {
                    self.running.insert(event.id, instance);
                    report.started += 1;
                }
            } else if !now && before {
                if let Some(instance) = self.running.remove(&event.id) {
                    if vm.stop_instance(instance) {
                        report.stopped += 1;
                    }
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
    use wolf_vm::{ProgramSet, Vm};

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

    #[test]
    fn the_scheduler_tracks_conditional_and_gated_events_and_skips_the_dead_one() {
        let Some((data, _)) = have_data() else { return };
        let auto = AutoEvents::from_common_events(&data);
        assert_eq!(auto.len(), 98, "96 run=2 events plus gated 242/243");
        assert!(auto
            .events()
            .iter()
            .all(|event| matches!(event.operator, 1..=3)));
        assert!(auto.events().iter().any(|event| event.id == 38));
        assert!(!auto.events().iter().any(|event| event.id == 43));
        assert!(auto.events().iter().any(|event| event.id == 242));
        assert!(auto.events().iter().any(|event| event.id == 243));
    }

    #[test]
    fn gated_run_zero_events_start_on_their_variable_and_stay_dormant_at_boot() {
        let Some((data, _)) = have_data() else { return };
        let programs = ProgramSet::from_common_events(&data);
        let mut vm = Vm::new(programs);
        let mut auto = AutoEvents::from_common_events(&data);
        // Dormant at boot: 2000350 == 0, so neither 242 (==1) nor 243 (==2) fires.
        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 1, "only event 38 is true at boot");
        assert!(!vm.instances().iter().any(|instance| instance.event == 242));
        assert!(!vm.instances().iter().any(|instance| instance.event == 243));
        // 2000350 == 1 starts 242 only.
        vm.vars.set(350, 1);
        auto.sync(&mut vm);
        assert!(vm.instances().iter().any(|instance| instance.event == 242));
        assert!(!vm.instances().iter().any(|instance| instance.event == 243));
        // 2000350 == 2 stops 242 and starts 243.
        vm.vars.set(350, 2);
        auto.sync(&mut vm);
        assert!(!vm.instances().iter().any(|instance| instance.event == 242));
        assert!(vm.instances().iter().any(|instance| instance.event == 243));
        // Back to 0 stops 243.
        vm.vars.set(350, 0);
        auto.sync(&mut vm);
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
    fn a_true_condition_starts_event_38_and_false_stops_it() {
        let Some((data, _)) = have_data() else { return };
        let programs = ProgramSet::from_common_events(&data);
        let mut vm = Vm::new(programs);
        let mut auto = AutoEvents::from_common_events(&data);
        let report = auto.sync(&mut vm);
        assert_eq!(
            report.started, 1,
            "only event 38 is true at boot (43 is skipped)"
        );
        assert!(vm.instances().iter().any(|instance| instance.event == 38));
        // Normal variable 160 is event 38's condition variable; 3 fails its <= 2 test.
        vm.vars.set(160, 3);
        let report = auto.sync(&mut vm);
        assert_eq!(report.stopped, 1);
        assert!(!vm.instances().iter().any(|instance| instance.event == 38));
        // Setting it back to 0 re-arms the edge and starts a fresh coroutine.
        vm.vars.set(160, 0);
        let report = auto.sync(&mut vm);
        assert_eq!(report.started, 1);
    }
}
