//! Offline tests for the M4 audio backend. All tests are device-free: they exercise the decoder
//! and the software mixer directly. Tests that need the game's `work/all` asset tree skip
//! themselves when it is not present (e.g. a bare CI checkout).

use std::path::{Path, PathBuf};

use wolf_audio::decode::decode_file;
use wolf_audio::mixer::Mixer;
use wolf_audio::{DecodedAudio, Engine};
use wolf_vm::{SoundAction, SoundChannel, SoundCmd};

/// Locate a sample audio file, searching `work/all/BGM` then `work/all/SE`.
fn find_sample(ext: &str) -> Option<PathBuf> {
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../work/all");
    if !root.is_dir() {
        return None;
    }
    for sub in ["BGM", "SE"] {
        let dir = root.join(sub);
        let Ok(entries) = std::fs::read_dir(&dir) else {
            continue;
        };
        for entry in entries.flatten() {
            let path = entry.path();
            if path.extension().and_then(|e| e.to_str()) == Some(ext) {
                return Some(path);
            }
        }
    }
    None
}

fn decode_first(ext: &str) -> Option<DecodedAudio> {
    let path = find_sample(ext)?;
    let audio =
        decode_file(&path).unwrap_or_else(|e| panic!("failed to decode {}: {e}", path.display()));
    println!(
        "{ext}: {} rate={} ch={} frames={} dur={:.3}s loop={:?}..{:?}",
        path.file_name().unwrap().to_string_lossy(),
        audio.sample_rate,
        audio.channels,
        audio.frames(),
        audio.duration_secs(),
        audio.loop_start,
        audio.loop_end,
    );
    Some(audio)
}

/// Build a small synthetic source at `rate`/`channels` with the given per-frame mono values.
fn synth(values: &[f32], rate: u32, channels: u16) -> DecodedAudio {
    let mut samples = Vec::with_capacity(values.len() * channels as usize);
    for &v in values {
        for _ in 0..channels {
            samples.push(v);
        }
    }
    DecodedAudio {
        sample_rate: rate,
        channels,
        samples,
        loop_start: None,
        loop_end: None,
    }
}

#[test]
fn decode_ogg() {
    let Some(audio) = decode_first("ogg") else {
        eprintln!("skipping decode_ogg: no work/all sample");
        return;
    };
    assert!(audio.sample_rate > 0, "ogg sample rate must be > 0");
    assert!(audio.channels > 0, "ogg channels must be > 0");
    assert!(audio.frames() > 0, "ogg frame count must be > 0");
    assert!(audio.duration_secs() > 0.0);
}

#[test]
fn decode_mp3() {
    let Some(audio) = decode_first("mp3") else {
        eprintln!("skipping decode_mp3: no work/all sample");
        return;
    };
    assert!(audio.sample_rate > 0);
    assert!(audio.channels > 0);
    assert!(audio.frames() > 0);
}

#[test]
fn decode_wav() {
    let Some(audio) = decode_first("wav") else {
        eprintln!("skipping decode_wav: no work/all sample");
        return;
    };
    assert!(audio.sample_rate > 0);
    assert!(audio.channels > 0);
    assert!(audio.frames() > 0);
}

#[test]
fn ogg_loop_tags_are_read() {
    // Acoustic_High_Collar.ogg carries LOOPSTART=1360911 / LOOPLENGTH=2589511.
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../work/all/BGM");
    let path = root.join("Acoustic_High_Collar.ogg");
    if !path.is_file() {
        eprintln!("skipping ogg_loop_tags_are_read: sample missing");
        return;
    }
    let audio = decode_file(&path).expect("decode loop-tagged ogg");
    assert!(
        audio.has_loop_points(),
        "expected LOOPSTART/LOOPLENGTH tags to yield usable loop points"
    );
    let start = audio.loop_start.unwrap();
    let end = audio.loop_end.unwrap();
    assert!(end > start);
    assert!((end as usize) <= audio.frames());
}

#[test]
fn render_length_is_correct() {
    let mut mixer = Mixer::new(48_000, 2);
    mixer.play_se(synth(&[0.25; 32], 48_000, 2), 1.0);
    let out = mixer.render(256);
    assert_eq!(out.len(), 256 * 2, "render must return frames * channels");
}

#[test]
fn two_se_voices_sum_stay_clipped() {
    let mut mixer = Mixer::new(48_000, 2);
    // Two hot voices: 0.8 + 0.8 = 1.6 pre-clamp.
    mixer.play_se(synth(&[0.8; 64], 48_000, 2), 1.0);
    mixer.play_se(synth(&[0.8; 64], 48_000, 2), 1.0);
    let out = mixer.render(32);
    assert_eq!(mixer.se_count(), 2);
    for s in &out {
        assert!(s.abs() <= 1.0 + 1e-6, "mixed sample {s} exceeded [-1, 1]");
    }
    // Both voices are still audible and clamped at full scale.
    assert!(out.iter().any(|s| (*s - 1.0).abs() < 1e-6));
}

#[test]
fn bgm_loops_seamlessly() {
    // Ramp 0,0.1,…,0.5; loop region frames [2,4). With step == 1 we expect the sample
    // sequence 0,0.1,0.2,0.3,0.2,0.3 — i.e. it wraps from frame 3 back to frame 2.
    // (Values stay within [-1,1] because the mixer clamps its output.)
    let mut audio = synth(&[0.0, 0.1, 0.2, 0.3, 0.4, 0.5], 48_000, 1);
    audio.loop_start = Some(2);
    audio.loop_end = Some(4);

    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_bgm(audio, true, 1.0);
    let out = mixer.render(6);
    let expected = [0.0f32, 0.1, 0.2, 0.3, 0.2, 0.3];
    assert_eq!(out.len(), 6);
    for (i, (got, want)) in out.iter().zip(expected.iter()).enumerate() {
        assert!(
            (got - want).abs() < 1e-3,
            "frame {i}: got {got}, want {want} (loop wrap not continuous)"
        );
    }
    // BGM keeps playing after the wrap point.
    assert!(mixer.bgm_playing());
}

#[test]
fn bgm_stop_with_fade_ends_silent() {
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_bgm(synth(&[0.9; 4800], 48_000, 1), true, 1.0);
    mixer.stop_bgm(60); // 1 second at 60 fps
    let out = mixer.render(48_000);
    // The last rendered frame should be essentially silent (one fade step of gain remains).
    assert!(out.last().copied().unwrap().abs() < 1e-3);
    assert!(!mixer.bgm_playing(), "BGM should stop after fade completes");
}

#[test]
fn engine_null_backend_renders_and_handles_cmds() {
    let mut engine = Engine::null_with(48_000, 2);
    assert!(engine.is_silent());

    engine.play_bgm_audio(synth(&[0.3; 100], 48_000, 2), true, 1.0);
    assert!(engine.bgm_playing());
    let out = engine.render_offline(128);
    assert_eq!(out.len(), 128 * 2);

    engine.stop_bgm(0);
    assert!(!engine.bgm_playing());

    // Stop commands must be safe even with nothing playing.
    let stop_se = SoundCmd {
        channel: SoundChannel::Se,
        action: SoundAction::Stop,
        file: String::new(),
        volume: 100,
        frames: 0,
    };
    engine.apply_sound_cmd(&stop_se);
    let stop_bgm = SoundCmd {
        channel: SoundChannel::Bgm,
        action: SoundAction::Stop,
        file: String::new(),
        volume: 0,
        frames: 0,
    };
    engine.apply_sound_cmd(&stop_bgm);
}
