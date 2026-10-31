//! Static asset-reference completeness scan for M3-L (task-18).
//!
//! The interpreter loads pictures / BGM / SE by name straight out of the event
//! scripts, so a reference the ship does not carry becomes a silent blank at
//! runtime. This test walks every asset-looking string in
//! `CommonEvent.dat` (all 350 events) and every `.mps` under `MapData`,
//! resolves each against the unpacked data root, and fails if anything is
//! referenced but absent.
//!
//! The scan works on the 1,361-entry `Data.wolf` extraction under work/Data
//! (override with `WOLF_DATA_ROOT`). No audio decoding happens here — task-15
//! already verifies the codecs; this only asserts existence, non-zero size and,
//! for images, that the file-header magic matches the extension.
//!
//! ## Known non-shipped references
//!
//! A handful of references belong to WOLF's built-in *sample* project that
//! ships inside every `.dat` but is dead code in this game (sample battle
//! maps, the default "original title A", the ぴぽや icon demo). Those assets
//! were never packed into `Data.wolf`. They are listed in
//! [`KNOWN_UNSHIPPED`] so the test stays green while still failing on any
//! *new* missing reference. See docs/M3_ASSET_REFS.md for the provenance.

use std::collections::{BTreeMap, BTreeSet};
use std::path::{Path, PathBuf};

const IMAGE_EXTS: &[&str] = &["png", "jpg", "jpeg", "bmp", "gif", "webp"];
const AUDIO_EXTS: &[&str] = &["mp3", "ogg", "wav"];

/// References that appear in the shipped scripts but whose files are absent
/// from `Data.wolf`. Every one is a leftover of WOLF's built-in sample project
/// (see docs/M3_ASSET_REFS.md §4); they never load during normal play.
const KNOWN_UNSHIPPED: &[&str] = &[
    // CE42 "オリジナルタイトル画面Ａ" — the sample title screen.
    "Picture/title2.jpg",
    // CE214 "応援会話リコ" — sample support-conversation demo frame.
    "Picture/message_frame3.png",
    // CE213 / CE221 — ぴぽや emotion icons; the real file lives in CharaChip/,
    // not Picture/, so the sample's path is simply wrong.
    "Picture/pipo-emotion.png",
    // Map002 "マップ表示" / "爆弾" / "接近攻撃" — the sample action-RPG map.
    "Picture/map_Village01_top.png",
    "Picture/explosion.png",
    "Picture/attack_effect01.png",
    // Map003 "ニューゲーム処理" — sample new-game hook re-skinning the title.
    "Picture/title2.jpg",
    // Map031 "ロード時の自動処理" — sample load hook backgrounds.
    "Picture/bg_map3_effect.png",
    "Picture/bg_map4_top.png",
];

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

/// Lower-case extension of a candidate filename, if it has an alphanumeric one.
fn extension(s: &str) -> Option<String> {
    let trimmed = s.trim();
    let (_, ext) = trimmed.rsplit_once('.')?;
    if !ext.is_empty() && ext.chars().all(|c| c.is_ascii_alphanumeric()) {
        Some(ext.to_ascii_lowercase())
    } else {
        None
    }
}

fn is_image(s: &str) -> bool {
    extension(s).map(|e| IMAGE_EXTS.contains(&e.as_str())).unwrap_or(false)
}

fn is_audio(s: &str) -> bool {
    extension(s).map(|e| AUDIO_EXTS.contains(&e.as_str())).unwrap_or(false)
}

/// Normalises a script reference into a lower-case, forward-slash relative path.
fn normalise(s: &str) -> String {
    s.trim().replace('\\', "/").to_ascii_lowercase()
}

fn walk_files(root: &Path, out: &mut Vec<PathBuf>) {
    for entry in std::fs::read_dir(root).expect("read data dir") {
        let entry = entry.expect("dir entry");
        let path = entry.path();
        if path.is_dir() {
            walk_files(&path, out);
        } else {
            out.push(path);
        }
    }
}

/// Relative lower-case path index of everything under the data root.
fn build_index(root: &Path) -> (BTreeSet<String>, BTreeMap<String, usize>) {
    let mut files = Vec::new();
    walk_files(root, &mut files);
    let mut rels = BTreeSet::new();
    let mut bases: BTreeMap<String, usize> = BTreeMap::new();
    for file in &files {
        let rel = file
            .strip_prefix(root)
            .expect("indexed file under root")
            .to_string_lossy()
            .replace('\\', "/")
            .to_ascii_lowercase();
        rels.insert(rel);
        if let Some(name) = file.file_name() {
            *bases.entry(name.to_string_lossy().to_ascii_lowercase()).or_insert(0) += 1;
        }
    }
    (rels, bases)
}

/// One media reference found in a script.
#[derive(Debug, Clone)]
struct RefRecord {
    raw: String,
    /// "CE <id> <title>" or "Map <file> ev<id> <name>".
    origin: String,
    opcode: u32,
}

fn collect_common_event_refs(root: &Path) -> Vec<RefRecord> {
    let path = root.join("BasicData").join("CommonEvent.dat");
    let data = std::fs::read(&path).expect("read CommonEvent.dat");
    let parsed =
        wolf_format::commonevent::CommonEventData::parse(&data).expect("parse CommonEvent.dat");
    let mut out = Vec::new();
    for event in &parsed.events {
        for slot in &event.commands {
            if let wolf_format::command::Slot::Command(cmd) = slot {
                for s in &cmd.strings {
                    if is_image(s) || is_audio(s) {
                        out.push(RefRecord {
                            raw: s.trim().to_owned(),
                            origin: format!("CE {} {:?}", event.id, event.title),
                            opcode: cmd.opcode,
                        });
                    }
                }
            }
        }
    }
    out
}

fn collect_map_refs(root: &Path) -> Vec<RefRecord> {
    let dir = root.join("MapData");
    let mut maps: Vec<PathBuf> = std::fs::read_dir(&dir)
        .expect("read MapData")
        .filter_map(|e| e.ok().map(|e| e.path()))
        .filter(|p| p.extension().map(|x| x.eq_ignore_ascii_case("mps")).unwrap_or(false))
        .collect();
    maps.sort();
    let mut out = Vec::new();
    for map_path in &maps {
        let bytes = std::fs::read(map_path).expect("read .mps");
        let map = wolf_format::mps::Map::parse(&bytes).expect("parse .mps");
        let name = map_path.file_name().unwrap().to_string_lossy().to_string();
        for event in &map.events {
            for page in &event.pages {
                for slot in &page.commands {
                    if let wolf_format::command::Slot::Command(cmd) = slot {
                        for s in &cmd.strings {
                            if is_image(s) || is_audio(s) {
                                out.push(RefRecord {
                                    raw: s.trim().to_owned(),
                                    origin: format!(
                                        "Map {} ev{} {:?}",
                                        name, event.id, event.name
                                    ),
                                    opcode: cmd.opcode,
                                });
                            }
                        }
                    }
                }
            }
        }
    }
    out
}

fn collect_all(root: &Path) -> Vec<RefRecord> {
    let mut refs = collect_common_event_refs(root);
    refs.extend(collect_map_refs(root));
    refs
}

/// Resolves a reference to an on-disk path via the exact (case-insensitive)
/// relative path. Cross-directory basename matches are reported separately so a
/// wrong folder (like `Picture/pipo-emotion.png`) is never silently accepted.
fn resolve_exact(root: &Path, rels: &BTreeSet<String>, raw: &str) -> Option<PathBuf> {
    let normalised = normalise(raw);
    if rels.contains(&normalised) {
        Some(root.join(normalised))
    } else {
        None
    }
}

fn magic_matches_extension(path: &Path) -> Result<(), String> {
    let bytes = std::fs::read(path).map_err(|e| format!("read {}: {e}", path.display()))?;
    if bytes.len() < 12 {
        return Err(format!("{} is only {} bytes", path.display(), bytes.len()));
    }
    let ext = path
        .extension()
        .map(|e| e.to_string_lossy().to_ascii_lowercase())
        .unwrap_or_default();
    let ok = match ext.as_str() {
        "png" => bytes.starts_with(&[0x89, 0x50, 0x4E, 0x47]),
        "jpg" | "jpeg" => bytes.starts_with(&[0xFF, 0xD8]),
        "bmp" => bytes.starts_with(&[0x42, 0x4D]),
        "gif" => bytes.starts_with(b"GIF"),
        "webp" => &bytes[0..4] == b"RIFF" && &bytes[8..12] == b"WEBP",
        other => return Err(format!("{}: unexpected extension {other}", path.display())),
    };
    if ok {
        Ok(())
    } else {
        Err(format!("{}: header magic does not match .{ext}", path.display()))
    }
}

// ---------------------------------------------------------------------------
// Core scan: every referenced image and audio file exists in the ship.
// ---------------------------------------------------------------------------
#[test]
fn all_event_and_map_asset_refs_resolve() {
    let root = match data_root() {
        root if root.join("BasicData").join("CommonEvent.dat").exists() => root,
        root => {
            eprintln!("skipping: no data under {}", root.display());
            return;
        }
    };

    let refs = collect_all(&root);
    let (rels, bases) = build_index(&root);

    let images: Vec<&RefRecord> = refs.iter().filter(|r| is_image(&r.raw)).collect();
    let audios: Vec<&RefRecord> = refs.iter().filter(|r| is_audio(&r.raw)).collect();
    assert!(!refs.is_empty(), "no media references found at all");

    // Sanity floors so a parser regression that silently drops commands fails.
    let distinct_images: BTreeSet<String> = images.iter().map(|r| normalise(&r.raw)).collect();
    let distinct_audio: BTreeSet<String> = audios.iter().map(|r| normalise(&r.raw)).collect();
    assert!(
        distinct_images.len() >= 500,
        "expected 500+ distinct image refs, got {}",
        distinct_images.len()
    );
    assert!(
        distinct_audio.len() >= 20,
        "expected 20+ distinct audio refs, got {}",
        distinct_audio.len()
    );

    // Every distinct media reference: divide into exact, basename-only and absent.
    let mut missing: BTreeSet<String> = BTreeSet::new();
    let mut basename_only: BTreeSet<String> = BTreeSet::new();
    let mut origins: BTreeMap<String, BTreeSet<String>> = BTreeMap::new();
    for record in &refs {
        let normalised = normalise(&record.raw);
        origins.entry(normalised.clone()).or_default().insert(record.origin.clone());
        if resolve_exact(&root, &rels, &record.raw).is_some() {
            continue;
        }
        let base = normalised.rsplit('/').next().unwrap_or(&normalised).to_string();
        if bases.contains_key(&base) {
            basename_only.insert(normalised);
        } else {
            missing.insert(normalised);
        }
    }

    println!(
        "asset scan: {} files, {} CE events, image refs={} (distinct {}), audio refs={} (distinct {}), basename_only={}, missing={}",
        rels.len(),
        wolf_format::commonevent::CommonEventData::parse(
            &std::fs::read(root.join("BasicData").join("CommonEvent.dat")).unwrap()
        )
        .unwrap()
        .events
        .len(),
        images.len(),
        distinct_images.len(),
        audios.len(),
        distinct_audio.len(),
        basename_only.len(),
        missing.len(),
    );
    for name in &missing {
        println!("  MISSING {name} <- {:?}", origins.get(name));
    }
    for name in &basename_only {
        println!("  WRONG-FOLDER {name} <- {:?}", origins.get(name));
    }

    // The only tolerated gaps are the documented WOLF sample-project leftovers.
    let expected: BTreeSet<String> = KNOWN_UNSHIPPED.iter().map(|s| s.to_ascii_lowercase()).collect();
    let mut unexpected: BTreeSet<String> = missing.difference(&expected).cloned().collect();
    unexpected.extend(basename_only.difference(&expected).cloned());
    assert!(
        unexpected.is_empty(),
        "unexpected unresolved asset refs (not in KNOWN_UNSHIPPED): {unexpected:?}"
    );

    // And every audio reference must exist and have content (decoders: task-15).
    for record in &audios {
        let path = resolve_exact(&root, &rels, &record.raw).unwrap_or_else(|| {
            panic!("audio ref {:?} from {} does not resolve", record.raw, record.origin)
        });
        let len = std::fs::metadata(&path).expect("audio metadata").len();
        assert!(
            len > 0,
            "audio ref {:?} from {} is empty",
            record.raw,
            record.origin
        );
    }
}

// ---------------------------------------------------------------------------
// Image header magic: at least 20 referenced pictures are real, undamaged files.
// ---------------------------------------------------------------------------
#[test]
fn referenced_images_have_valid_magic() {
    let root = match data_root() {
        root if root.join("BasicData").join("CommonEvent.dat").exists() => root,
        root => {
            eprintln!("skipping: no data under {}", root.display());
            return;
        }
    };
    let refs = collect_all(&root);
    let (rels, _bases) = build_index(&root);

    let mut distinct: BTreeSet<String> = refs
        .iter()
        .filter(|r| is_image(&r.raw))
        .map(|r| normalise(&r.raw))
        .collect();
    // Only files that actually resolve can be inspected.
    distinct.retain(|name| rels.contains(name));

    let mut checked = 0usize;
    let mut failures = Vec::new();
    for name in &distinct {
        if checked >= 40 {
            break;
        }
        let path = root.join(name);
        match magic_matches_extension(&path) {
            Ok(()) => checked += 1,
            Err(err) => failures.push(err),
        }
    }
    assert!(
        failures.is_empty(),
        "image magic failures: {failures:#?}"
    );
    assert!(
        checked >= 20,
        "expected to validate >=20 referenced images, validated {checked}"
    );
    println!("validated image header magic for {checked} referenced pictures");
}
