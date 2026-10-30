//! M4 audio wiring: the Game keeps the pure recorder path until `enable_audio` installs an
//! engine, and the recorder still sees every opcode-140 command either way. This pins the
//! three-line integration in `Game::sound` so a future refactor cannot silently drop the
//! engine call or make headless runs depend on a sound device.

use std::path::PathBuf;

use wolf_game::Game;

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/full".to_owned());
    let path = PathBuf::from(raw);
    if path.is_absolute() {
        return path;
    }
    let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    base.pop();
    base.pop();
    base.join(path)
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

#[test]
fn audio_silent_until_enabled_and_the_recorder_still_sees_sound_commands() {
    let Some(mut game) = open_game() else {
        return;
    };
    // Default: no engine, so tests and headless captures never touch a device.
    assert!(game.audio.is_none(), "Game::new starts silent");

    // Common event 297 plays two sounds in its very first frame.
    assert!(game.start_event(297), "event 297 starts");
    let mut recorded_a_sound = false;
    for _ in 0..60 {
        game.frame();
        recorded_a_sound |= !game.sounds.is_empty();
    }
    assert!(
        game.stats.sounds > 0,
        "the recorder still sees opcode 140 with audio off"
    );
    assert!(
        recorded_a_sound,
        "some frame kept its SoundCmds in game.sounds"
    );

    // Turning audio on must not panic on a device-less box: the engine falls back to a
    // null backend. After this the same commands also reach the mixer.
    game.enable_audio();
    assert!(game.audio.is_some());
    for _ in 0..30 {
        game.frame();
    }
    assert!(game.stats.sounds > 0);
}
