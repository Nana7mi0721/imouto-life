//! M5-D second slice: the translation authoring scanner against the real script.
//!
//! The unit tests in `wolf-game::translate` cover the parsing and coverage rules. This
//! file pins the real-data shape: the scanner reaches every common event, finds the
//! night menu's choice labels, separates variable-dependent strings, and produces a
//! template that is a valid (but empty) catalog.

use std::path::PathBuf;

use wolf_format::commonevent::CommonEventData;
use wolf_game::{SourceScan, TextContext, Translator};

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

fn events(data_root: &std::path::Path) -> Option<CommonEventData> {
    let candidates = [
        data_root.join("CommonEvent.dat"),
        data_root.join("BasicData").join("CommonEvent.dat"),
    ];
    for path in candidates {
        if let Ok(bytes) = std::fs::read(&path) {
            return Some(CommonEventData::parse(&bytes).expect("CommonEvent.dat"));
        }
    }
    None
}

#[test]
fn the_scanner_sees_every_script_string_and_writes_a_valid_template() {
    let root = data_root();
    let Some(events) = events(&root) else {
        eprintln!("skipping: no game data under {}", root.display());
        return;
    };
    let scan = SourceScan::from_common_events(&events);

    // The 350 events hold well over a thousand distinct literal strings; the exact
    // count is a data property, so keep the assertions broad enough to survive a
    // catalog edit but tight enough to catch a scanner that stops early.
    assert!(scan.static_count() > 1_000, "{}", scan.static_count());
    assert!(scan.dynamic_count() > 0);

    let chat = scan
        .texts
        .iter()
        .find(|text| text.context == TextContext::Choice && text.text == "开始交流 ")
        .expect("the night menu's first choice is a scanned literal");
    assert!(chat.is_static());
    assert!(
        chat.static_events.contains(&245),
        "{:?}",
        chat.static_events
    );

    let template = scan.template();
    assert!(template.contains("# wolf-cli translations template\n"));
    let mut rows = 0usize;
    for line in template.lines() {
        if line.starts_with('#') {
            continue;
        }
        let (source, translation) = line.split_once('\t').expect("template row has a tab");
        assert!(!source.is_empty());
        assert!(translation.is_empty(), "template rows are placeholders");
        assert!(!source.chars().any(|ch| matches!(ch, '\t' | '\n' | '\r')));
        rows += 1;
    }
    assert_eq!(rows + skipped_rows(&template), scan.static_count());
    assert!(Translator::parse(&template)
        .expect("template is a valid catalog")
        .is_empty());
}

fn skipped_rows(template: &str) -> usize {
    template
        .lines()
        .find(|line| line.starts_with("# ") && line.contains("contain a literal TAB/CR/LF"))
        .and_then(|line| line.split_whitespace().nth(1))
        .and_then(|count| count.parse().ok())
        .unwrap_or(0)
}
