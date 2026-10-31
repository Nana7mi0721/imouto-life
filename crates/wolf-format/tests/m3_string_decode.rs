//! Whole-data string-decoding audit and regression (task-22, M3-P).
//!
//! The fan translation overwrote most Japanese display strings with GBK bytes
//! while leaving engine/template text in CP932, so every string goes through
//! the UTF-8 -> CP932/GBK heuristic in wolf_format::bytes::decode_wolf_str.
//! This test parses every string-bearing container, asserts the decoder never
//! emits U+FFFD, pins a few known-good Chinese strings, and documents the
//! CE250 "first item name" data defect (a corrupt odd run of 0xA1 in the
//! translation, not a decoder bug - see docs/M3_STRING_DECODE.md).

use std::path::{Path, PathBuf};

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

fn have_data(root: &Path) -> bool {
    root.join("BasicData").join("CommonEvent.dat").exists()
}

/// One decoded string plus where it came from.
#[derive(Clone)]
struct Source {
    file: String,
    field: String,
    text: String,
}

fn push_all(
    out: &mut Vec<Source>,
    file: &str,
    field: &str,
    strings: impl IntoIterator<Item = String>,
) {
    for text in strings {
        out.push(Source {
            file: file.to_owned(),
            field: field.to_owned(),
            text,
        });
    }
}

fn collect_common_events(root: &Path, out: &mut Vec<Source>) {
    let path = root.join("BasicData").join("CommonEvent.dat");
    let data = std::fs::read(&path).expect("read CommonEvent.dat");
    let parsed =
        wolf_format::commonevent::CommonEventData::parse(&data).expect("parse CommonEvent.dat");
    for event in &parsed.events {
        let tag = format!("CE {}", event.id);
        push_all(out, &tag, "title", [event.title.clone()]);
        push_all(out, &tag, "memo", [event.memo.clone()]);
        push_all(out, &tag, "arg_names", event.arg_names.clone());
        push_all(
            out,
            &tag,
            "default_strings",
            event.arg_string_pages.iter().flatten().cloned(),
        );
        push_all(
            out,
            &tag,
            "self_variable_names",
            event.self_variable_names.clone(),
        );
        push_all(out, &tag, "return_name", [event.return_name.clone()]);
        for slot in &event.commands {
            if let wolf_format::command::Slot::Command(cmd) = slot {
                push_all(out, &tag, "command_string", cmd.strings.clone());
            }
        }
    }
}

fn collect_database(root: &Path, dat: &str, project: &str, out: &mut Vec<Source>) {
    let dat_path = root.join("BasicData").join(dat);
    if !dat_path.exists() {
        return;
    }
    let data = std::fs::read(&dat_path).expect("read dat");
    let mut db = wolf_format::database::Database::parse(&data).expect("parse dat");
    let proj_path = root.join("BasicData").join(project);
    if proj_path.exists() {
        let proj = std::fs::read(&proj_path).expect("read project");
        db.apply_project_names(&proj);
    }
    for (ty, table) in db.types.iter().enumerate() {
        let tag = format!("{dat} type{ty}");
        push_all(
            out,
            &tag,
            "type_name",
            db.type_name(ty).map(|s| s.to_owned()).into_iter(),
        );
        for col in 0..table.fields.len() {
            push_all(
                out,
                &tag,
                "field_name",
                db.field_name(ty, col).map(|s| s.to_owned()).into_iter(),
            );
        }
        for (row, r) in table.rows.iter().enumerate() {
            push_all(
                out,
                &tag,
                "row_name",
                db.row_name(ty, row).map(|s| s.to_owned()).into_iter(),
            );
            push_all(out, &tag, "row_string", r.strings.clone());
        }
    }
}

fn collect_sysdatabase(root: &Path, out: &mut Vec<Source>) {
    let dat_path = root.join("BasicData").join("SysDatabase.dat");
    if !dat_path.exists() {
        return;
    }
    let data = std::fs::read(&dat_path).expect("read SysDatabase.dat");
    let mut db =
        wolf_format::sysdatabase::SysDatabase::parse(&data).expect("parse SysDatabase.dat");
    let proj_path = root.join("BasicData").join("SysDatabase.project");
    if proj_path.exists() {
        let proj = std::fs::read(&proj_path).expect("read SysDatabase.project");
        db.apply_project_names(&proj);
    }
    for (ty, table) in db.types().iter().enumerate() {
        let tag = format!("SysDatabase type{ty}");
        push_all(out, &tag, "type_name", [table.name.clone()]);
        push_all(out, &tag, "field_names", table.field_names.clone());
        push_all(out, &tag, "row_names", table.row_names.clone());
        for r in &table.rows {
            push_all(out, &tag, "row_string", r.strings.clone());
        }
    }
}

fn collect_gamedat(root: &Path, out: &mut Vec<Source>) {
    let path = root.join("BasicData").join("Game.dat");
    if !path.exists() {
        return;
    }
    let data = std::fs::read(&path).expect("read Game.dat");
    let parsed = wolf_format::gamedat::GameDat::parse(&data).expect("parse Game.dat");
    push_all(out, "Game.dat", "strings", parsed.strings.clone());
}

fn collect_maps(root: &Path, out: &mut Vec<Source>) {
    let dir = root.join("MapData");
    let mut maps: Vec<PathBuf> = std::fs::read_dir(&dir)
        .expect("read MapData")
        .filter_map(|e| e.ok().map(|e| e.path()))
        .filter(|p| {
            p.extension()
                .map(|x| x.eq_ignore_ascii_case("mps"))
                .unwrap_or(false)
        })
        .collect();
    maps.sort();
    for map_path in &maps {
        let bytes = std::fs::read(map_path).expect("read .mps");
        let map = wolf_format::mps::Map::parse(&bytes).expect("parse .mps");
        let file = map_path.file_name().unwrap().to_string_lossy().to_string();
        push_all(out, &file, "map_name", [map.name.clone()]);
        for event in &map.events {
            push_all(out, &file, "event_name", [event.name.clone()]);
            for page in &event.pages {
                for slot in &page.commands {
                    if let wolf_format::command::Slot::Command(cmd) = slot {
                        push_all(out, &file, "command_string", cmd.strings.clone());
                    }
                }
            }
        }
    }
}

fn collect_all(root: &Path) -> Vec<Source> {
    let mut out = Vec::new();
    collect_common_events(root, &mut out);
    collect_database(root, "DataBase.dat", "DataBase.project", &mut out);
    collect_database(root, "CDataBase.dat", "CDataBase.project", &mut out);
    collect_sysdatabase(root, &mut out);
    collect_gamedat(root, &mut out);
    collect_maps(root, &mut out);
    out
}

fn is_halfwidth_katakana(c: char) -> bool {
    ('\u{FF61}'..='\u{FF9F}').contains(&c)
}

fn has_cjk_ideograph(s: &str) -> bool {
    s.chars().any(|c| ('\u{4E00}'..='\u{9FFF}').contains(&c))
}

// ---------------------------------------------------------------------------
// 1. Parse every container and assert the decoder never emits U+FFFD.
// ---------------------------------------------------------------------------
#[test]
fn every_container_parses_without_replacement_characters() {
    let root = data_root();
    if !have_data(&root) {
        eprintln!("skipping: no data under {}", root.display());
        return;
    }
    let sources = collect_all(&root);

    let mut replacement: Vec<&Source> = Vec::new();
    let mut control: Vec<&Source> = Vec::new();
    let mut halfwidth_cjk: Vec<&Source> = Vec::new();
    let mut empty = 0usize;

    for s in &sources {
        if s.text.contains('\u{FFFD}') {
            replacement.push(s);
        }
        if s.text.is_empty() {
            empty += 1;
        }
        if s.text
            .chars()
            .any(|c| (c as u32) < 0x20 && c != '\n' && c != '\r' && c != '\t')
        {
            control.push(s);
        }
        if has_cjk_ideograph(&s.text) && s.text.chars().any(is_halfwidth_katakana) {
            halfwidth_cjk.push(s);
        }
    }

    let files: std::collections::BTreeSet<&str> = sources.iter().map(|s| s.file.as_str()).collect();
    println!(
        "string audit: {} strings across {} files, U+FFFD={}, control={}, halfwidth+CJK={}, empty={}",
        sources.len(),
        files.len(),
        replacement.len(),
        control.len(),
        halfwidth_cjk.len(),
        empty
    );
    for s in replacement.iter().take(50) {
        println!("  REPLACEMENT {} {} {:?}", s.file, s.field, s.text);
    }
    for s in control.iter().take(20) {
        println!("  CONTROL {} {} {:?}", s.file, s.field, s.text);
    }
    for s in halfwidth_cjk.iter().take(50) {
        println!("  HALFWIDTH+CJK {} {} {:?}", s.file, s.field, s.text);
    }

    // Known data defects that legitimately decode to a replacement character:
    // CE257's red-tea item repeats CE250's odd 0xA1 run (see the CE250 test
    // below). Anything else with U+FFFD is an unexplained decoder failure.
    let unexplained: Vec<&Source> = replacement
        .iter()
        .copied()
        .filter(|s| !(s.file == "CE 257" && s.field == "command_string" && s.text.contains("红茶")))
        .collect();
    assert!(
        unexplained.is_empty(),
        "unexplained U+FFFD in {} string(s): {:?}",
        unexplained.len(),
        unexplained
            .first()
            .map(|s| (s.file.clone(), s.field.clone(), s.text.clone()))
    );
    assert_eq!(
        replacement.len(),
        1,
        "expected exactly the one known CE257 red-tea data defect"
    );
}

// ---------------------------------------------------------------------------
// 2. Known-good Chinese strings decode stably (GBK path).
// ---------------------------------------------------------------------------
#[test]
fn known_chinese_strings_decode_stably() {
    let root = data_root();
    if !have_data(&root) {
        eprintln!("skipping: no data under {}", root.display());
        return;
    }
    let sources = collect_all(&root);
    let corpus: String = sources
        .iter()
        .map(|s| s.text.as_str())
        .collect::<Vec<_>>()
        .join("\n");

    for anchor in [
        "行动力",
        "持有金钱",
        "早上好",
        "网络商店",
        "安全套",
        "跳蛋",
        "春药",
    ] {
        if !corpus.contains(anchor) {
            if matches!(anchor, "行动力" | "持有金钱") {
                panic!("expected core Chinese anchor {anchor:?} in decoded corpus");
            }
            println!("  (anchor {anchor:?} not present)");
        }
    }
    let probe: &[u8] = b"\xbf\xb4\xd2\xbb\xd1\xdb\xcd\xf8\xc9\xcf\xc9\xcc\xb5\xea\xb0\xc9\xa1\xa3";
    assert_eq!(
        wolf_format::bytes::decode_wolf_str(probe),
        "看一眼网上商店吧。"
    );
}

// ---------------------------------------------------------------------------
// 3. CE250 first-item-name defect: source data corruption, not the decoder.
// ---------------------------------------------------------------------------
// The fan translation wrote GBK "哑铃" (d1c6 c1e5) followed by SEVEN 0xA1 bytes.
// GBK pairs them into three fullwidth spaces plus one lone 0xA1, whose trail is
// the next 0x20 - an illegal GBK trail. Strict GBK decoding therefore fails
// (gb_bad), and decode_wolf_str falls back to CP932 where 0xA1..=0xDF are
// halfwidth katakana, producing the mojibake. CE259 holds the same item with
// EIGHT 0xA1 (even) and decodes correctly to "哑铃", proving the byte run is the
// cause. The decoder must NOT be bent to prefer GBK here: m3-fixer measured 138
// gb_bad&&!cp_bad strings of which 136+ are legitimate Japanese UI labels that
// would break if the fallback changed.

/// The exact CE250 first-item bytes (from CommonEvent.dat, slot op=102).
const CE250_ITEM: &[u8] =
    b"\xd1\xc6\xc1\xe5\xa1\xa1\xa1\xa1\xa1\xa1\xa1\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x32\x30\x30\x30\x30\x83\xd2\x20";
/// The even-length CE259 variant that decodes correctly.
const CE259_ITEM: &[u8] =
    b"\xd1\xc6\xc1\xe5\xa1\xa1\xa1\xa1\xa1\xa1\xa1\xa1\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x32\x30\x30\x30\x30\x83\xd2\x20";
/// CE257 red-tea item: the same odd 0xA1 run, which lands on a U+FFFD.
const CE257_TEA: &[u8] =
    b"\xba\xec\xb2\xe8\xa1\xa1\xa1\xa1\xa1\xa1\xa1\x20\x32\x30\x30\x30\x83\xd2";

#[test]
#[allow(invalid_from_utf8)]
fn ce250_first_item_name_is_a_data_defect() {
    assert!(std::str::from_utf8(CE250_ITEM).is_err());
    let a1_run = CE250_ITEM
        .iter()
        .skip(4)
        .take_while(|&&b| b == 0xA1)
        .count();
    assert_eq!(a1_run, 7, "CE250 item has an odd 0xA1 run");
    assert_eq!(CE250_ITEM[4 + a1_run], 0x20);
    assert_eq!(CE250_ITEM.len(), 30);

    let (gb, gb_bad) = wolf_format::gbk::decode(CE250_ITEM);
    assert!(gb_bad, "strict GBK should reject the odd 0xA1 run");
    let _ = gb;
    let decoded = wolf_format::bytes::decode_wolf_str(CE250_ITEM);
    assert!(
        decoded.chars().any(is_halfwidth_katakana),
        "expected halfwidth-katakana fallback, got {decoded:?}"
    );
    assert!(!decoded.contains("哑铃"));

    let (gb_ok, gb_ok_bad) = wolf_format::gbk::decode(CE259_ITEM);
    assert!(!gb_ok_bad);
    assert!(
        gb_ok.starts_with("哑铃"),
        "CE259 variant should start with 哑铃, got {gb_ok:?}"
    );
    assert_eq!(wolf_format::bytes::decode_wolf_str(CE259_ITEM), gb_ok);

    // CE257 red-tea item repeats the odd 0xA1 defect and lands on U+FFFD.
    let tea_a1 = CE257_TEA.iter().skip(4).take_while(|&&b| b == 0xA1).count();
    assert_eq!(tea_a1, 7, "CE257 item has an odd 0xA1 run");
    let (_, tea_bad) = wolf_format::gbk::decode(CE257_TEA);
    assert!(tea_bad, "strict GBK should reject CE257's odd 0xA1 run");
    let tea = wolf_format::bytes::decode_wolf_str(CE257_TEA);
    assert!(tea.contains("红茶"), "got {tea:?}");
    assert!(
        tea.contains('\u{FFFD}'),
        "expected a replacement character in CE257 red-tea, got {tea:?}"
    );
    println!("CE257 red-tea decode_wolf_str = {tea:?}");

    println!("CE250 item raw = {}", hex(CE250_ITEM));
    println!("CE250 item decode_wolf_str = {decoded:?}");
    println!(
        "CE259 item decode_wolf_str = {:?}",
        wolf_format::bytes::decode_wolf_str(CE259_ITEM)
    );
}

/// Aspirational regression: if the translation data is ever fixed (odd 0xA1 run
/// removed), the first item name should read "哑铃". Ignored until then.
#[test]
#[ignore = "source data defect: CE250 first item has an odd 0xA1 run; not a decoder bug"]
fn ce250_first_item_name_ideally_reads_dumbbell() {
    let fixed: &[u8] =
        b"\xd1\xc6\xc1\xe5\xa1\xa1\xa1\xa1\xa1\xa1\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x32\x30\x30\x30\x30\x83\xd2\x20";
    let decoded = wolf_format::bytes::decode_wolf_str(fixed);
    assert!(decoded.contains("哑铃"), "got {decoded:?}");
}

fn hex(bytes: &[u8]) -> String {
    let mut s = String::with_capacity(bytes.len() * 2);
    for b in bytes {
        s.push_str(&format!("{b:02x}"));
    }
    s
}
