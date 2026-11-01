//! The `--hotkeys` option must be discoverable from `--help`. This is a light
//! end-to-end check that the flag is wired into argument parsing without needing a
//! window or a data root; the actual parsing and resolution live in unit tests in
//! `src/hotkeys.rs`.

use std::process::Command;

#[test]
fn help_documents_the_hotkeys_flag() {
    let output = Command::new(env!("CARGO_BIN_EXE_wolf-cli"))
        .arg("--help")
        .output()
        .expect("failed to run wolf-cli --help");
    assert!(
        output.status.success(),
        "--help should exit successfully, got {:?}",
        output.status
    );
    let text = String::from_utf8_lossy(&output.stdout);
    assert!(
        text.contains("--hotkeys"),
        "help should mention --hotkeys:\n{text}"
    );
    assert!(
        text.contains("M7_HOTKEYS"),
        "help should point at docs/M7_HOTKEYS.md:\n{text}"
    );
}
