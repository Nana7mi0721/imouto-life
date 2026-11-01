//! M5-E audio overlay: mod roots can replace BGM/SE files, later roots win, and the
//! base root remains the fallback. Device-free via the silent null engine.

use std::path::{Path, PathBuf};

use wolf_audio::Engine;

fn scratch_dir(name: &str) -> PathBuf {
    let path = Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("../..")
        .join("target/test-scratch/m5_audio_overlay")
        .join(name);
    let _ = std::fs::remove_dir_all(&path);
    std::fs::create_dir_all(&path).expect("scratch dir");
    path
}

#[test]
fn audio_overlays_replace_base_files_and_later_roots_win() {
    let base = scratch_dir("base");
    let first = scratch_dir("first");
    let second = scratch_dir("second");
    for dir in [&base, &first, &second] {
        std::fs::create_dir_all(dir.join("BGM")).expect("BGM dir");
        std::fs::create_dir_all(dir.join("SE")).expect("SE dir");
    }
    std::fs::write(base.join("BGM/theme.ogg"), b"base").expect("base bgm");
    std::fs::write(base.join("BGM/root-only.ogg"), b"root").expect("base only");
    std::fs::write(first.join("BGM/theme.ogg"), b"first").expect("first bgm");
    std::fs::write(second.join("BGM/theme.ogg"), b"second").expect("second bgm");
    std::fs::write(first.join("SE/click.ogg"), b"click").expect("first se");

    let engine = Engine::null_with_overlays(&base, vec![first.clone(), second.clone()]);
    assert_eq!(engine.overlays(), &[first.clone(), second.clone()]);

    // A later overlay wins over an earlier one, and both win over the base.
    assert_eq!(
        engine.resolve("BGM/theme.ogg"),
        Some(second.join("BGM/theme.ogg"))
    );
    assert_eq!(
        engine.resolve("BGM\\theme.ogg"),
        Some(second.join("BGM/theme.ogg"))
    );
    // A file only carried by an earlier overlay is still found.
    assert_eq!(
        engine.resolve("SE/click.ogg"),
        Some(first.join("SE/click.ogg"))
    );
    // A file no overlay carries falls back to the base root.
    assert_eq!(
        engine.resolve("BGM/root-only.ogg"),
        Some(base.join("BGM/root-only.ogg"))
    );
    assert_eq!(engine.resolve("BGM/missing.ogg"), None);

    let absolute = base.join("BGM/root-only.ogg");
    assert_eq!(
        engine.resolve(&absolute.to_string_lossy()),
        Some(absolute.clone())
    );

    let _ = std::fs::remove_dir_all(&base);
    let _ = std::fs::remove_dir_all(&first);
    let _ = std::fs::remove_dir_all(&second);
}
