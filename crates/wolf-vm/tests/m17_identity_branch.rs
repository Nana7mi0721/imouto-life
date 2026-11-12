use std::collections::BTreeSet;
use std::path::PathBuf;

use wolf_format::commonevent::CommonEventData;
use wolf_vm::program::{Program, ProgramSet};
use wolf_vm::{Host, PictureAction, PictureCmd, Vm};

const SALARYMAN_CGS: [&str; 2] = ["cg/bg_004_01.jpg", "cg/bg_005_01.jpg"];

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

fn load_programs() -> Option<ProgramSet> {
    let path = data_root().join("BasicData").join("CommonEvent.dat");
    let Ok(bytes) = std::fs::read(&path) else {
        eprintln!("skipping: missing {}", path.display());
        return None;
    };
    let data = CommonEventData::parse(&bytes).expect("CommonEvent.dat parses");
    Some(ProgramSet::from_common_events(&data))
}

fn label_targets(program: &Program, name: &str) -> Vec<usize> {
    program
        .label_defs
        .iter()
        .filter_map(|(label, target)| (label == name).then_some(*target))
        .collect()
}

#[derive(Default)]
struct Probe {
    messages: Vec<String>,
    pictures: BTreeSet<String>,
    events: BTreeSet<u32>,
}

impl Host for Probe {
    fn show_message(&mut self, text: &str, _face: Option<i32>) {
        self.messages.push(text.to_owned());
    }

    fn picture(&mut self, cmd: &PictureCmd) {
        if cmd.action == PictureAction::Draw && !cmd.file.is_empty() {
            self.pictures.insert(cmd.file.clone());
        }
    }
}

fn run_day_branch(programs: ProgramSet, career: usize, inner_condition: i32) -> Probe {
    let mut vm = Vm::new(programs);
    for variable in 10..=13 {
        vm.vars.set(variable, i32::from(variable == career));
    }
    vm.vars.set(131, inner_condition);

    let id = vm.start_event(251).expect("CE251 starts");
    vm.instance_mut(id).expect("CE251 instance").pc = 1118;

    let mut host = Probe::default();
    for _ in 0..600 {
        vm.step_frame(&mut host);
        for instance in vm.instances() {
            host.events.insert(instance.event);
        }
    }
    host
}

fn assert_no_salaryman_cg(host: &Probe, context: &str) {
    for cg in SALARYMAN_CGS {
        assert!(
            !host.pictures.contains(cg),
            "{context} must not draw the salaryman CG {cg}: {:?}",
            host.pictures
        );
    }
}

#[test]
fn retail_duplicate_labels_resolve_to_first_definition() {
    let Some(programs) = load_programs() else {
        return;
    };

    let ce251 = programs.event(251).expect("CE251 exists");
    assert_eq!(label_targets(ce251, "学生"), vec![1134, 1197]);
    assert_eq!(ce251.labels.get("学生"), Some(&1134));
    assert_eq!(ce251.labels.get("社会人"), Some(&1214));

    let ce249 = programs.event(249).expect("CE249 exists");
    assert_eq!(label_targets(ce249, "手交"), vec![2827, 3607]);
    assert_eq!(ce249.labels.get("手交"), Some(&2827));

    let ce259 = programs.event(259).expect("CE259 exists");
    assert_eq!(label_targets(ce259, "自宅待機"), vec![143, 2647]);
    assert_eq!(ce259.labels.get("自宅待機"), Some(&143));
}

#[test]
fn student_inner_condition_true_uses_student_cg_and_ce252() {
    let Some(programs) = load_programs() else {
        return;
    };
    let host = run_day_branch(programs, 10, 1);

    assert!(
        host.events.contains(&252),
        "student branch must call CE252, saw {:?}",
        host.events
    );
    assert!(
        host.messages
            .iter()
            .any(|message| message.contains("那个…我要先走了哦")),
        "student branch did not execute its inner true arm: {:?}",
        host.messages
    );
    for cg in [
        "cg/bg_003_01.jpg",
        "cg/bg_003_s01.png",
        "cg/bg_008_01.jpg",
        "cg/bg_009_01.jpg",
    ] {
        assert!(
            host.pictures.contains(cg),
            "student branch is missing {cg}: {:?}",
            host.pictures
        );
    }
    assert_no_salaryman_cg(&host, "student branch");
}

#[test]
fn student_inner_condition_false_stays_on_student_path() {
    let Some(programs) = load_programs() else {
        return;
    };
    let host = run_day_branch(programs, 10, 0);

    assert!(
        host.events.contains(&252),
        "student branch must call CE252, saw {:?}",
        host.events
    );
    assert!(
        host.pictures.contains("cg/bg_009_01.jpg"),
        "student fall-through must reach the student CG block: {:?}",
        host.pictures
    );
    assert_no_salaryman_cg(&host, "student fall-through");
}

#[test]
fn salaryman_branch_still_uses_office_cg_and_ce254() {
    let Some(programs) = load_programs() else {
        return;
    };
    let host = run_day_branch(programs, 12, 1);

    assert!(
        host.events.contains(&254),
        "salaryman branch must call CE254, saw {:?}",
        host.events
    );
    for cg in SALARYMAN_CGS {
        assert!(
            host.pictures.contains(cg),
            "salaryman branch is missing {cg}: {:?}",
            host.pictures
        );
    }
    assert!(
        !host.pictures.contains("cg/bg_008_01.jpg") && !host.pictures.contains("cg/bg_009_01.jpg"),
        "salaryman branch must not run the student CG block: {:?}",
        host.pictures
    );
}

#[test]
fn freelancer_and_neet_branches_never_use_salaryman_office_cg() {
    let Some(programs) = load_programs() else {
        return;
    };

    for (career, expected_child) in [(11, 253), (13, 255)] {
        let host = run_day_branch(programs.clone(), career, 1);
        assert!(
            host.events.contains(&expected_child),
            "var{career} must call CE{expected_child}, saw {:?}",
            host.events
        );
        assert_no_salaryman_cg(&host, &format!("var{career} branch"));
    }
}
