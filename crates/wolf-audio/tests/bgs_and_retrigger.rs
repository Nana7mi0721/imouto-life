//! BUG-17 regression: BGS owns a second bus under the BGM, and repeating a
//! SoundCmd for a track that is already playing does not restart it.
//!
//! The shipped scripts re-issue the same ambience/BGM command from several
//! update branches; before this fix each repeat rebuilt the voice from sample
//! zero, which was audible as a stutter every few frames.

use std::io::Write;
use std::path::{Path, PathBuf};

use wolf_audio::mixer::Mixer;
use wolf_audio::{DecodedAudio, Engine};

fn constant(value: f32, frames: usize, rate: u32, channels: u16) -> DecodedAudio {
    DecodedAudio {
        sample_rate: rate,
        channels,
        samples: vec![value; frames * channels as usize],
        loop_start: None,
        loop_end: None,
    }
}

/// Minimal 16-bit mono PCM WAV so the Engine can exercise its path-based load.
fn write_pcm16(path: &Path, rate: u32, samples: &[i16]) {
    let data_len = (samples.len() * 2) as u32;
    let mut bytes = Vec::with_capacity(44 + data_len as usize);
    bytes.extend_from_slice(b"RIFF");
    bytes.extend_from_slice(&(36 + data_len).to_le_bytes());
    bytes.extend_from_slice(b"WAVEfmt ");
    bytes.extend_from_slice(&16u32.to_le_bytes());
    bytes.extend_from_slice(&1u16.to_le_bytes()); // PCM
    bytes.extend_from_slice(&1u16.to_le_bytes()); // mono
    bytes.extend_from_slice(&rate.to_le_bytes());
    bytes.extend_from_slice(&(rate * 2).to_le_bytes());
    bytes.extend_from_slice(&2u16.to_le_bytes());
    bytes.extend_from_slice(&16u16.to_le_bytes());
    bytes.extend_from_slice(b"data");
    bytes.extend_from_slice(&data_len.to_le_bytes());
    for sample in samples {
        bytes.extend_from_slice(&sample.to_le_bytes());
    }
    let mut file = std::fs::File::create(path).expect("create wav");
    file.write_all(&bytes).expect("write wav");
}

/// A 1 s, 8 kHz file that is silent for the first half and 0.8 for the second.
fn step_wav() -> (PathBuf, PathBuf) {
    // Work inside the repository's ignored scratch tree: the Windows system temp
    // directory is not writable in this environment.
    let root = Path::new(env!("CARGO_MANIFEST_DIR"))
        .join("../../work/out")
        .join(format!("audio_bug17_{}", std::process::id()));
    let bgm = root.join("BGM");
    std::fs::create_dir_all(&bgm).expect("create fixture root");
    let path = bgm.join("step.wav");
    let mut samples = vec![0i16; 4_000];
    samples.extend(std::iter::repeat(26_214i16).take(4_000));
    write_pcm16(&path, 8_000, &samples);
    (root, path)
}

#[test]
fn bgs_mixes_under_the_bgm_on_its_own_bus() {
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_bgm(constant(0.2, 4_800, 48_000, 1), true, 1.0);
    mixer.play_bgs_with_fade(constant(0.3, 4_800, 48_000, 1), true, 1.0, 0);
    assert!(mixer.bgm_playing());
    assert!(mixer.bgs_playing());

    let mixed = mixer.render(8);
    for sample in &mixed {
        assert!(
            (sample - 0.5).abs() < 1e-6,
            "BGS must add to the BGM instead of replacing it: {sample}"
        );
    }

    // Stopping the BGM must not take the ambience with it.
    mixer.stop_bgm(0);
    assert!(!mixer.bgm_playing());
    let ambience = mixer.render(8);
    for sample in &ambience {
        assert!(
            (sample - 0.3).abs() < 1e-6,
            "stopping the BGM must leave the BGS bus alone: {sample}"
        );
    }
}

#[test]
fn replaying_the_same_bgm_path_does_not_restart_the_voice() {
    let (root, step) = step_wav();
    let mut engine = Engine::null_with_overlays(&root, Vec::new());
    let file = step
        .strip_prefix(&root)
        .expect("fixture below root")
        .to_string_lossy()
        .replace('\\', "/");

    engine.play_bgm(&file, true).expect("first play");
    // 32,000 output frames = 2/3 s, past the silent first half of the source.
    let before = engine.render_offline(32_000);
    let tail = *before.last().expect("samples");
    assert!(
        tail > 0.7,
        "the step must have reached its loud half before the repeat: {tail}"
    );

    engine.play_bgm(&file, true).expect("repeat play");
    let after = engine.render_offline(64);
    assert!(
        after[0] > 0.5,
        "a repeated SoundCmd for the same path must continue the voice, not restart it: {}",
        after[0]
    );

    // A stop really stops: a later play starts from the silent head again.
    engine.stop_bgm(0);
    engine.play_bgm(&file, true).expect("play after stop");
    let restarted = engine.render_offline(64);
    for sample in &restarted {
        assert!(
            sample.abs() < 0.01,
            "after a stop the track must start from the beginning: {sample}"
        );
    }

    let _ = std::fs::remove_dir_all(&root);
}
