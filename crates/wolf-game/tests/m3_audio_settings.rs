//! M3-I: audio-asset and global-settings runtime acceptance.
//!
//! These tests close two gaps left by audio_wiring.rs (which only proves the recorder
//! path and that enable_audio does not panic):
//!
//! 1. The shipped audio assets really parse/decode (one representative per format),
//!    the inventory has only the expected extensions, and the single .url shortcut is
//!    kept out of the decode path.
//! 2. Two common events that carry opcode-140 commands (CE297 staff roll, CE251 sleep)
//!    resolve every played file against the asset root and mix a non-silent buffer.
//! 3. Save/System.sav (the global settings snapshot) round-trips a BGM/SE volume edit
//!    through serialize/to_bytes with a valid checksum, without touching the file.
//! 4. The settings fields that drive window colours / volumes / key config are readable
//!    and in sane ranges (the Game settings API landed in `crate::settings`; the
//!    read/write/apply contract is pinned in m3_settings_persist.rs).
//!
//! Everything skips cleanly when work/Data is absent, so the default workspace test
//! run keeps exit 0.

use std::path::{Path, PathBuf};

use wolf_audio::{decode_file, Engine};
use wolf_game::Game;
use wolf_save::SaveFile;
use wolf_vm::{SoundAction, SoundChannel};

/// The only extensions a real audio asset may have in this game's data.
const AUDIO_EXTS: [&str; 3] = ["mp3", "ogg", "wav"];

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

fn ext_of(path: &Path) -> String {
    path.extension()
        .and_then(|e| e.to_str())
        .map(|e| e.to_ascii_lowercase())
        .unwrap_or_default()
}

/// Split one asset directory into (real audio files, .url shortcuts).
fn collect(dir: &Path) -> (Vec<PathBuf>, Vec<PathBuf>) {
    let mut audio = Vec::new();
    let mut urls = Vec::new();
    let entries =
        std::fs::read_dir(dir).unwrap_or_else(|e| panic!("read_dir {}: {e}", dir.display()));
    for entry in entries {
        let path = entry.expect("dir entry").path();
        if !path.is_file() {
            continue;
        }
        if ext_of(&path) == "url" {
            urls.push(path);
        } else {
            audio.push(path);
        }
    }
    (audio, urls)
}

/// Smallest file with a given extension, so representative decodes stay quick.
fn smallest_with_ext(dir: &Path, wanted: &str) -> Option<PathBuf> {
    let mut best: Option<(u64, PathBuf)> = None;
    let entries = std::fs::read_dir(dir).ok()?;
    for entry in entries.flatten() {
        let path = entry.path();
        if !path.is_file() || ext_of(&path) != wanted {
            continue;
        }
        let len = entry.metadata().map(|m| m.len()).unwrap_or(0);
        if best.as_ref().map_or(true, |(best_len, _)| len < *best_len) {
            best = Some((len, path));
        }
    }
    best.map(|(_, path)| path)
}

fn ext_counts(files: &[PathBuf]) -> std::collections::BTreeMap<String, usize> {
    let mut counts = std::collections::BTreeMap::new();
    for f in files {
        *counts.entry(ext_of(f)).or_insert(0) += 1;
    }
    counts
}

fn open_game() -> Option<Game> {
    match Game::new(data_root()) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!("skipping: {err}");
            None
        }
    }
}

// ---------------------------------------------------------------------------
// 1. Asset inventory + representative decodes
// ---------------------------------------------------------------------------

#[test]
fn asset_inventory_and_representative_decodes() {
    let root = data_root();
    let bgm_dir = root.join("BGM");
    let se_dir = root.join("SE");
    if !bgm_dir.is_dir() || !se_dir.is_dir() {
        eprintln!("skipping: BGM/SE not found under {}", root.display());
        return;
    }

    let (bgm_audio, bgm_urls) = collect(&bgm_dir);
    let (se_audio, se_urls) = collect(&se_dir);

    // Inventory shape measured from work/Data.
    assert_eq!(bgm_audio.len() + bgm_urls.len(), 28, "BGM total entries");
    assert_eq!(
        bgm_urls.len(),
        1,
        "exactly one external .url shortcut in BGM"
    );
    assert_eq!(se_audio.len() + se_urls.len(), 214, "SE total entries");
    assert_eq!(se_urls.len(), 0, "SE has no .url shortcuts");

    let bgm_counts = ext_counts(&bgm_audio);
    assert_eq!(
        bgm_counts.get("mp3").copied().unwrap_or(0),
        15,
        "BGM mp3 count: {bgm_counts:?}"
    );
    assert_eq!(
        bgm_counts.get("ogg").copied().unwrap_or(0),
        12,
        "BGM ogg count: {bgm_counts:?}"
    );
    let se_counts = ext_counts(&se_audio);
    assert_eq!(
        se_counts.get("mp3").copied().unwrap_or(0),
        87,
        "SE mp3 count: {se_counts:?}"
    );
    assert_eq!(
        se_counts.get("ogg").copied().unwrap_or(0),
        99,
        "SE ogg count: {se_counts:?}"
    );
    assert_eq!(
        se_counts.get("wav").copied().unwrap_or(0),
        28,
        "SE wav count: {se_counts:?}"
    );

    // Every real audio extension is one we can decode.
    for f in bgm_audio.iter().chain(se_audio.iter()) {
        let ext = ext_of(f);
        assert!(
            AUDIO_EXTS.contains(&ext.as_str()),
            "unexpected audio extension {ext:?} at {}",
            f.display()
        );
    }

    // The .url shortcut is an internet shortcut, not audio: decoding it must fail cleanly
    // (not panic). That is what keeps it out of the playable asset list.
    let url = &bgm_urls[0];
    assert_eq!(ext_of(url), "url");
    assert!(
        decode_file(url).is_err(),
        ".url shortcut {} unexpectedly decoded as audio",
        url.display()
    );

    // Decode one representative per format present in each library: BGM ogg+mp3,
    // SE ogg+mp3+wav (>= 5 files), asserting the decoded stream is sane.
    let reps: [(&str, Option<PathBuf>); 5] = [
        ("BGM ogg", smallest_with_ext(&bgm_dir, "ogg")),
        ("BGM mp3", smallest_with_ext(&bgm_dir, "mp3")),
        ("SE ogg", smallest_with_ext(&se_dir, "ogg")),
        ("SE mp3", smallest_with_ext(&se_dir, "mp3")),
        ("SE wav", smallest_with_ext(&se_dir, "wav")),
    ];
    for (label, path) in reps {
        let path = path.unwrap_or_else(|| panic!("no representative {label} file"));
        let audio =
            decode_file(&path).unwrap_or_else(|e| panic!("decode {label} {}: {e}", path.display()));
        assert!(
            audio.frames() > 0,
            "{label} decoded no frames: {}",
            path.display()
        );
        assert!(audio.sample_rate > 0, "{label} has zero sample rate");
        assert!(
            audio.channels == 1 || audio.channels == 2,
            "{label} has {} channels (expected mono/stereo)",
            audio.channels
        );
        assert!(
            !audio.samples.is_empty(),
            "{label} decoded empty sample buffer"
        );
        for &s in audio.samples.iter() {
            assert!(
                (-1.0..=1.0).contains(&s),
                "{label} sample {s} outside [-1, 1] in {}",
                path.display()
            );
        }
    }
}

// ---------------------------------------------------------------------------
// 2. Event sound commands resolve and mix a non-silent buffer
// ---------------------------------------------------------------------------

#[test]
fn event_sound_commands_resolve_and_render() {
    let Some(mut game) = open_game() else {
        return;
    };
    game.enable_audio();
    game.auto_advance = true;
    game.auto_choice = true;

    let mut first_bgm: Option<String> = None;
    let mut first_se: Option<String> = None;

    for id in [297u32, 251u32] {
        assert!(game.start_event(id), "common event {id} starts");
        let mut plays = Vec::new();
        for _ in 0..300 {
            game.frame();
            for cmd in &game.sounds {
                if cmd.action != SoundAction::Play {
                    continue;
                }
                if cmd.file.is_empty() {
                    continue;
                }
                plays.push(cmd.clone());
                match cmd.channel {
                    SoundChannel::Bgm => {
                        if first_bgm.is_none() {
                            first_bgm = Some(cmd.file.clone());
                        }
                    }
                    SoundChannel::Se => {
                        if first_se.is_none() {
                            first_se = Some(cmd.file.clone());
                        }
                    }
                }
            }
        }

        assert!(!plays.is_empty(), "event {id} emitted no playable SoundCmd");
        let engine = game.audio.as_ref().expect("audio engine installed");
        for cmd in &plays {
            assert!(
                engine.resolve(&cmd.file).is_some(),
                "event {id} plays {:?} but it does not resolve under {}",
                cmd.file,
                engine.asset_root().display()
            );
        }
    }

    // Spot-check that the first BGM and first SE really mix audio, not just resolve.
    let bgm = first_bgm.expect("at least one BGM Play command across the events");
    let se = first_se.expect("at least one SE Play command across the events");

    {
        let engine: &mut Engine = game.audio.as_mut().unwrap();
        engine
            .play_bgm(&bgm, true)
            .unwrap_or_else(|e| panic!("play_bgm {bgm}: {e}"));
        let buffer = engine.render_offline(1024);
        assert!(
            !buffer.is_empty() && buffer.iter().any(|s| s.abs() > 0.0),
            "BGM {bgm} rendered silence over 1024 frames"
        );
    }
    {
        let engine: &mut Engine = game.audio.as_mut().unwrap();
        engine
            .play_se(&se)
            .unwrap_or_else(|e| panic!("play_se {se}: {e}"));
        let buffer = engine.render_offline(1024);
        assert!(
            !buffer.is_empty() && buffer.iter().any(|s| s.abs() > 0.0),
            "SE {se} rendered silence over 1024 frames"
        );
    }
}

// ---------------------------------------------------------------------------
// 3. System.sav global settings: parse, edit, serialize/to_bytes round-trip
// ---------------------------------------------------------------------------

fn read_system_save() -> Option<(PathBuf, Vec<u8>)> {
    let path = data_root().join("Save").join("System.sav");
    match std::fs::read(&path) {
        Ok(bytes) => Some((path, bytes)),
        Err(err) => {
            eprintln!("skipping: cannot read {}: {err}", path.display());
            None
        }
    }
}

#[test]
fn system_save_settings_roundtrip() {
    let Some((path, original)) = read_system_save() else {
        return;
    };
    let save = SaveFile::parse(&original).expect("parse System.sav");

    // The global settings snapshot is present and the file is self-consistent.
    assert!(save.checksum_ok(), "System.sav checksum must validate");
    assert_eq!(save.chunks().len(), 7, "a full save has seven segments");
    assert!(
        save.part2.bgm.is_some(),
        "settings include the BGM slots (version >= 108)"
    );
    // vars72_74 is the BGM/SE/ambient volume trio (all 100 = full here).
    assert!(
        save.part2.vars72_74.iter().all(|&v| v <= 100),
        "volume trio should be percentages: {:?}",
        save.part2.vars72_74
    );

    // Edit one BGM volume field, re-encode the segment, and round-trip through
    // serialize/to_bytes (the exact bytes written to disk).
    let mut edited = save.clone();
    let old = edited.part2.vars72_74[0];
    let new = if old == 100 { 80 } else { 100 };
    edited.part2.vars72_74[0] = new;
    let part2 = edited.part2.clone();
    edited
        .set_part2(&part2)
        .expect("set_part2 re-encodes the segment");

    let written = edited
        .to_bytes()
        .expect("to_bytes encrypts the serialized file");
    let back = SaveFile::parse(&written).expect("re-parse the round-tripped bytes");
    assert!(back.checksum_ok(), "round-tripped checksum must validate");
    assert_eq!(
        back.part2.vars72_74[0], new,
        "edited BGM volume survives round-trip"
    );
    assert_eq!(
        &back.part2.vars72_74[1..],
        &save.part2.vars72_74[1..],
        "untouched volume fields are unchanged"
    );
    assert_eq!(
        back.part2.bgm, save.part2.bgm,
        "BGM slots are otherwise identical"
    );
    assert!(!back.decrypted().is_empty());

    // The on-disk System.sav must not have been touched (all edits were in memory).
    let after = std::fs::read(&path).expect("re-read System.sav");
    assert_eq!(original, after, "System.sav was modified on disk");
}

// ---------------------------------------------------------------------------
// 4. Settings fields (window / volumes / key config) are readable and sane
// ---------------------------------------------------------------------------

#[test]
fn global_settings_fields_visible_and_sane() {
    let Some((_path, bytes)) = read_system_save() else {
        return;
    };
    let save = SaveFile::parse(&bytes).expect("parse System.sav");
    assert!(save.checksum_ok());
    let p2 = &save.part2;

    // Window colour is stored as four u16 channels (RGBA), each within a byte range.
    assert!(
        p2.vars42_45.iter().all(|&c| c <= 255),
        "window colour channels out of range: {:?}",
        p2.vars42_45
    );
    // Volume trio stays within 0..=100 percent.
    assert!(
        p2.vars72_74.iter().all(|&v| v <= 100),
        "volume trio out of range: {:?}",
        p2.vars72_74
    );
    // The key-configuration triplets are populated (three key pairs).
    assert!(
        p2.vars64_69.iter().any(|&v| v != 0),
        "key-config snapshot should be populated: {:?}",
        p2.vars64_69
    );
    // A window/background block exists for this file version, proving the settings
    // snapshot is the full global-settings record, not just a couple of words.
    assert!(
        p2.block109.is_some(),
        "settings include the background block (version >= 109)"
    );

    // This test keeps the acceptance at the file-format layer; the Game-level
    // read/write/apply/persist contract lives in m3_settings_persist.rs and
    // crate::settings. It deliberately does NOT duplicate the ver6
    // m3_visual_text.rs pixel/text checks.
    eprintln!(
        "System.sav settings: window_colour={:?} volumes={:?} key_config={:?}",
        p2.vars42_45, p2.vars72_74, p2.vars64_69
    );
}
