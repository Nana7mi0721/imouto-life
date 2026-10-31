//! M3-AI: save-file robustness against corrupt, missing and hostile inputs.
//!
//! The matrix exercises the three public load entry points:
//! SaveFile::parse, savegame::read_save and Game::load_save. Every malformed file
//! must return Err without panicking. Two source-level gaps discovered while writing
//! this test are pinned explicitly and reported to the Lead:
//!   * a wrong stored checksum is detected by SaveFile::checksum_ok but is NOT
//!     rejected by parse/read_save/Game::load_save;
//!   * Game::save_to creates a missing parent directory (game.rs:487), so only a
//!     parent that cannot be created (a regular file in the path) is an error.
//!
//! All temporary artifacts live under work/out/ and are deleted on drop. The shipped
//! work/Data/Save directory is read-only for these tests and its fingerprint is checked
//! before and after every test body.

use std::panic::{catch_unwind, AssertUnwindSafe};
use std::path::{Path, PathBuf};

use wolf_game::{savegame, Game};
use wolf_save::SaveFile;

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

fn out_dir() -> PathBuf {
    data_root().parent().expect("data root parent").join("out")
}

fn save_dir() -> PathBuf {
    data_root().join("Save")
}

fn sample_save_path() -> Option<PathBuf> {
    for name in ["SaveData01.sav", "SaveData02.sav", "System.sav"] {
        let path = save_dir().join(name);
        if path.is_file() {
            return Some(path);
        }
    }
    None
}

fn valid_save_bytes() -> Option<Vec<u8>> {
    let path = sample_save_path()?;
    let save = savegame::read_save(&path).ok()?;
    if !save.checksum_ok() {
        eprintln!("skipping: {} has an invalid checksum", path.display());
        return None;
    }
    Some(save.to_bytes().expect("re-encode a valid save"))
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

fn fnv1a(bytes: &[u8]) -> u64 {
    let mut hash = 0xcbf2_9ce4_8422_2325u64;
    for byte in bytes {
        hash ^= u64::from(*byte);
        hash = hash.wrapping_mul(0x1000_0000_01b3);
    }
    hash
}

/// Content fingerprint of every regular file in work/Data/Save: name, size, FNV-1a.
fn save_fingerprint() -> Result<Vec<(String, u64, u64)>, String> {
    let dir = save_dir();
    let entries =
        std::fs::read_dir(&dir).map_err(|err| format!("cannot list {}: {err}", dir.display()))?;
    let mut files = Vec::new();
    for entry in entries {
        let entry = entry.map_err(|err| format!("cannot read {} entry: {err}", dir.display()))?;
        let path = entry.path();
        if !path.is_file() {
            continue;
        }
        let bytes =
            std::fs::read(&path).map_err(|err| format!("cannot read {}: {err}", path.display()))?;
        let name = path
            .file_name()
            .unwrap_or_default()
            .to_string_lossy()
            .into_owned();
        files.push((name, bytes.len() as u64, fnv1a(&bytes)));
    }
    files.sort();
    Ok(files)
}

/// Runs a test body while proving it never changes work/Data/Save.
fn preserve_save_dir<F: FnOnce()>(label: &str, body: F) {
    let before = save_fingerprint().expect("snapshot Save directory");
    body();
    let after = save_fingerprint().expect("resnapshot Save directory");
    assert_eq!(after, before, "{label} changed the shipped Save directory");
}

/// Scratch directory under work/out; removed recursively on drop.
struct Scratch {
    dir: PathBuf,
}

impl Scratch {
    fn new(label: &str) -> Self {
        let dir = out_dir().join(format!("m3_robust_{label}"));
        clear_readonly(&dir);
        let _ = std::fs::remove_dir_all(&dir);
        std::fs::create_dir_all(&dir).expect("create scratch dir");
        Self { dir }
    }

    fn path(&self, name: &str) -> PathBuf {
        self.dir.join(name)
    }

    fn write(&self, name: &str, bytes: &[u8]) -> PathBuf {
        let path = self.path(name);
        std::fs::write(&path, bytes).expect("write scratch file");
        path
    }
}

impl Drop for Scratch {
    fn drop(&mut self) {
        clear_readonly(&self.dir);
        let _ = std::fs::remove_dir_all(&self.dir);
    }
}

fn clear_readonly(path: &Path) {
    let Ok(meta) = std::fs::metadata(path) else {
        return;
    };
    if meta.is_dir() {
        if let Ok(entries) = std::fs::read_dir(path) {
            for entry in entries.flatten() {
                clear_readonly(&entry.path());
            }
        }
    } else {
        let mut permissions = meta.permissions();
        if permissions.readonly() {
            permissions.set_readonly(false);
            let _ = std::fs::set_permissions(path, permissions);
        }
    }
}

/// Calls f inside catch_unwind and asserts it returned Err (not Ok, not a panic).
fn expect_err<T, E, F>(label: &str, f: F) -> E
where
    F: FnOnce() -> Result<T, E>,
    E: std::fmt::Debug,
{
    let outcome = catch_unwind(AssertUnwindSafe(f));
    match outcome {
        Ok(Ok(_)) => panic!("{label}: expected Err, got Ok"),
        Ok(Err(err)) => {
            println!("{label}: Err -> {err:?}");
            err
        }
        Err(_) => panic!("{label}: panicked on hostile input"),
    }
}

fn random_bytes() -> Vec<u8> {
    let mut state = 0x1234_5678u32;
    let mut bytes = Vec::with_capacity(4096);
    for _ in 0..4096 {
        state = state.wrapping_mul(1_664_525).wrapping_add(1_013_904_223);
        bytes.push((state >> 24) as u8);
    }
    bytes
}

#[test]
fn corrupt_save_files_return_err_without_panicking() {
    let Some(valid) = valid_save_bytes() else {
        return;
    };
    let Some(mut game) = open_game() else {
        return;
    };
    let scratch = Scratch::new("corrupt");
    let parsed = SaveFile::parse(&valid).expect("valid baseline");

    let mut variants: Vec<(&str, Vec<u8>)> = vec![
        ("empty", Vec::new()),
        ("truncated_header", valid[..10].to_vec()),
        ("truncated_body", valid[..valid.len() / 2].to_vec()),
        ("random_bytes", random_bytes()),
    ];

    let mut bad_version = parsed.clone();
    bad_version.file_version = 0x8F;
    variants.push((
        "bad_file_version",
        bad_version.to_bytes().expect("encode bad version"),
    ));

    let mut bad_end = parsed.clone();
    bad_end.end_byte = 0;
    variants.push((
        "bad_end_byte",
        bad_end.to_bytes().expect("encode bad end byte"),
    ));

    let mut bad_start = parsed.clone();
    bad_start.header.start_byte = 0;
    variants.push((
        "bad_start_byte",
        bad_start.to_bytes().expect("encode bad start byte"),
    ));

    let mut huge = parsed.clone();
    huge.replace_part(5, &[0xFF, 0xFF, 0xFF, 0xFF])
        .expect("replace vardb");
    variants.push((
        "huge_declared_length",
        huge.to_bytes().expect("encode huge length"),
    ));

    preserve_save_dir("corrupt matrix", || {
        for (name, bytes) in &variants {
            expect_err(&format!("{name}/SaveFile::parse"), || {
                SaveFile::parse(bytes)
            });
            let path = scratch.write(&format!("{name}.sav"), bytes);
            expect_err(&format!("{name}/read_save"), || savegame::read_save(&path));
            expect_err(&format!("{name}/Game::load_save"), || game.load_save(&path));
        }

        let missing = scratch.path("never_written.sav");
        expect_err("missing/read_save", || savegame::read_save(&missing));
        expect_err("missing/Game::load_save", || game.load_save(&missing));
    });
}

/// Pin the current checksum gap: the byte is exposed and checksum_ok sees it, but
/// neither parser rejects the file and Game::load_save happily loads it.
#[test]
fn wrong_checksum_is_detected_but_not_rejected_by_current_load_paths() {
    let Some(valid) = valid_save_bytes() else {
        return;
    };
    let Some(mut game) = open_game() else {
        return;
    };
    let scratch = Scratch::new("checksum_gap");

    preserve_save_dir("checksum gap", || {
        let mut bytes = valid.clone();
        bytes[2] = bytes[2].wrapping_add(1);
        let path = scratch.write("bad_checksum.sav", &bytes);

        let save = SaveFile::parse(&bytes).expect("CURRENT GAP: parse accepts a bad checksum");
        assert!(!save.checksum_ok(), "checksum_ok must report the mismatch");
        println!(
            "checksum gap: stored={} computed={}",
            save.stored_checksum, save.computed_checksum
        );

        let read =
            savegame::read_save(&path).expect("CURRENT GAP: read_save accepts a bad checksum");
        assert!(
            !read.checksum_ok(),
            "read_save result must report checksum_ok=false"
        );

        let loaded = game
            .load_save(&path)
            .expect("CURRENT GAP: Game::load_save accepts a bad checksum");
        println!(
            "checksum gap: Game::load_save returned pictures={}",
            loaded.pictures
        );

        let frame = catch_unwind(AssertUnwindSafe(|| game.frame()));
        assert!(
            frame.is_ok(),
            "a bad-checksum load must not leave the game unusable"
        );
    });
}

/// Desired behaviour after the checksum gap is fixed. Keep ignored until then.
#[test]
#[ignore = "API gap: SaveFile::parse/read_save/Game::load_save do not validate the stored checksum"]
fn wrong_checksum_is_rejected_by_all_load_paths() {
    let Some(valid) = valid_save_bytes() else {
        return;
    };
    let Some(mut game) = open_game() else {
        return;
    };
    let scratch = Scratch::new("checksum_fixed");

    let mut bytes = valid.clone();
    bytes[2] = bytes[2].wrapping_add(1);
    let path = scratch.write("bad_checksum.sav", &bytes);

    assert!(
        SaveFile::parse(&bytes).is_err(),
        "SaveFile::parse must reject a bad checksum"
    );
    assert!(
        savegame::read_save(&path).is_err(),
        "read_save must reject a bad checksum"
    );
    assert!(
        game.load_save(&path).is_err(),
        "Game::load_save must reject a bad checksum"
    );
}

#[test]
fn unwritable_save_targets_return_err_without_panicking() {
    let Some(_valid) = valid_save_bytes() else {
        return;
    };
    let Some(mut game) = open_game() else {
        return;
    };
    let scratch = Scratch::new("unwritable");

    preserve_save_dir("save_to error paths", || {
        let as_directory = scratch.path("target_is_a_directory");
        std::fs::create_dir_all(&as_directory).expect("make target directory");
        expect_err("save_to/existing_directory", || game.save_to(&as_directory));

        let blocker = scratch.path("parent_is_a_file");
        std::fs::write(&blocker, b"not a directory").expect("make blocker file");
        let child = blocker.join("child.sav");
        expect_err("save_to/parent_is_file", || game.save_to(&child));

        let readonly = scratch.path("readonly_target.sav");
        std::fs::write(&readonly, b"existing").expect("make readonly file");
        let mut permissions = std::fs::metadata(&readonly)
            .expect("stat readonly")
            .permissions();
        permissions.set_readonly(true);
        std::fs::set_permissions(&readonly, permissions).expect("set readonly");
        expect_err("save_to/readonly_file", || game.save_to(&readonly));
        let mut permissions = std::fs::metadata(&readonly)
            .expect("stat readonly after")
            .permissions();
        permissions.set_readonly(false);
        std::fs::set_permissions(&readonly, permissions).expect("clear readonly");
    });
}

#[test]
fn failed_load_leaves_the_game_usable() {
    let Some(valid) = valid_save_bytes() else {
        return;
    };
    let Some(mut game) = open_game() else {
        return;
    };
    let scratch = Scratch::new("failed_load");

    preserve_save_dir("failed load recovery", || {
        let path = scratch.write("truncated.sav", &valid[..valid.len() / 2]);
        expect_err("failed/Game::load_save", || game.load_save(&path));

        let frame = catch_unwind(AssertUnwindSafe(|| {
            game.frame();
        }));
        assert!(
            frame.is_ok(),
            "Game must keep running one frame after a failed load"
        );
        println!("failed load recovery: one frame ran after the error");
    });
}
