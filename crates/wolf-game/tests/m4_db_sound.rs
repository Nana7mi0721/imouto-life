//! M4: opcode 140 sound-type 0 resolves its SystemDB entry.
//!
//! The editor stores only the row number for these commands.  CE249 (pc258/pc280)
//! addresses SE row 0, and SampleMapA event 15 addresses SE row 2; neither carries a
//! file name.  The host therefore has to answer from SysDatabase type 3, including the
//! row's volume column, instead of treating the command as an empty stop.

use std::path::PathBuf;

use wolf_game::Game;

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let p = PathBuf::from(raw);
    if p.is_absolute() {
        p
    } else {
        let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        base.pop();
        base.pop();
        base.join(p)
    }
}

#[test]
fn system_db_se_entries_resolve_to_files_and_volumes() {
    let root = data_root();
    if !root.join("BasicData").join("SysDatabase.dat").is_file() {
        eprintln!("skipping: missing {}", root.display());
        return;
    }
    let game = Game::new(root).expect("game");

    let enter = game.databases.sound_entry(3, 0).expect("SE row 0");
    assert_eq!(enter.0, "SystemFile/[SE]Enter.ogg");
    assert_eq!(enter.1, 90);

    let cancel = game.databases.sound_entry(3, 2).expect("SE row 2");
    assert_eq!(cancel.0, "SystemFile/[SE]Cancel.ogg");
    assert_eq!(cancel.1, 80);

    assert_eq!(game.databases.sound_entry(3, 65535), None);
}
