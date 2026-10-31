//! M4 audio contract: offline, deterministic checks for the mixer and the engine adapter.
//!
//! Everything here is device-free. Sources are synthesised in memory (constant/ramp PCM), so
//! the tests pin mixer behaviour exactly instead of depending on codec output; the one
//! data-dependent case (a shipped SE) skips when `work/Data` is absent.
//!
//! Contract pinned below:
//! * master volumes (`set_bgm_volume`/`set_se_volume`) and the per-voice volume multiply, and
//!   both are clamped to 0..=1 (a SoundCmd carrying 200 becomes 1.0, not 2.0);
//! * `play_bgm` replaces the previous BGM voice; a non-looping BGM ends and is removed;
//! * a fade-out is monotonically non-increasing, reaches silence and then clears the voice;
//! * resampling is linear interpolation with step = source_rate / output_rate (up and down);
//! * mono sources fan out to every output channel; SE voices are concurrent, sum, and are
//!   clamped to [-1, 1] by the mixer;
//! * the null engine is deterministic and silent when idle;
//! * `Engine::apply_sound_cmd` accepts every BGM/SE Play/Stop shape without panicking and
//!   keeps the documented state transitions.
//!
//! `SoundCmd.frames` is a fade-in for BGM, a start delay for SE, and a fade-out for a BGM
//! stop; all three are honoured now. A retail opcode 140 SE stop is `State::FreeAll` in the
//! reference decoder — it carries no file name or voice id — so it clears the whole SE bus,
//! which `se_stop_is_stop_all_and_clears_every_concurrent_voice` pins.

use std::path::{Path, PathBuf};

use wolf_audio::decode::{decode_bytes, decode_file};
use wolf_audio::mixer::{Mixer, GAME_FPS};
use wolf_audio::{DecodedAudio, Engine};
use wolf_vm::{SoundAction, SoundChannel, SoundCmd};

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

/// Constant-valued source (all channels share the value).
fn constant(value: f32, frames: usize, rate: u32, channels: u16) -> DecodedAudio {
    DecodedAudio {
        sample_rate: rate,
        channels,
        samples: vec![value; frames * channels as usize],
        loop_start: None,
        loop_end: None,
    }
}

/// Mono ramp source: frame `i` has value `start + i * step`.
fn ramp(start: f32, step: f32, frames: usize, rate: u32) -> DecodedAudio {
    let samples = (0..frames).map(|i| start + i as f32 * step).collect();
    DecodedAudio {
        sample_rate: rate,
        channels: 1,
        samples,
        loop_start: None,
        loop_end: None,
    }
}

fn cmd(
    channel: SoundChannel,
    action: SoundAction,
    file: &str,
    volume: i32,
    frames: i32,
) -> SoundCmd {
    SoundCmd {
        channel,
        action,
        file: file.to_owned(),
        volume,
        frames,
    }
}

/// A minimal 16-bit PCM WAV file (mono or interleaved), so `decode_bytes` can be exercised
/// without shipping an asset.
fn wav_bytes(samples: &[i16], rate: u32, channels: u16) -> Vec<u8> {
    let data_len = (samples.len() * 2) as u32;
    let byte_rate = rate * u32::from(channels) * 2;
    let block_align = channels * 2;
    let mut out = Vec::with_capacity(44 + data_len as usize);
    out.extend_from_slice(b"RIFF");
    out.extend_from_slice(&(36 + data_len).to_le_bytes());
    out.extend_from_slice(b"WAVE");
    out.extend_from_slice(b"fmt ");
    out.extend_from_slice(&16u32.to_le_bytes());
    out.extend_from_slice(&1u16.to_le_bytes()); // PCM
    out.extend_from_slice(&channels.to_le_bytes());
    out.extend_from_slice(&rate.to_le_bytes());
    out.extend_from_slice(&byte_rate.to_le_bytes());
    out.extend_from_slice(&block_align.to_le_bytes());
    out.extend_from_slice(&16u16.to_le_bytes());
    out.extend_from_slice(b"data");
    out.extend_from_slice(&data_len.to_le_bytes());
    for sample in samples {
        out.extend_from_slice(&sample.to_le_bytes());
    }
    out
}

/// The smallest shipped ogg/mp3 SE, if the data tree is present.
fn smallest_shipped_se() -> Option<PathBuf> {
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../work/Data/SE");
    let entries = std::fs::read_dir(root).ok()?;
    entries
        .flatten()
        .map(|entry| entry.path())
        .filter(|path| {
            matches!(
                path.extension().and_then(|e| e.to_str()),
                Some("ogg" | "mp3" | "wav")
            )
        })
        .min_by_key(|path| std::fs::metadata(path).map(|m| m.len()).unwrap_or(u64::MAX))
}

// ---------------------------------------------------------------------------
// Master and per-voice volume
// ---------------------------------------------------------------------------

#[test]
fn master_volumes_multiply_and_clamp() {
    // BGM: sample 0.5 * voice 0.5 * master 0.5 -> 0.125 on every channel.
    let mut mixer = Mixer::new(48_000, 2);
    mixer.play_bgm(constant(0.5, 64, 48_000, 2), true, 0.5);
    mixer.set_bgm_volume(0.5);
    let out = mixer.render(4);
    for s in &out {
        assert!((s - 0.125).abs() < 1e-6, "BGM master gain: got {s}");
    }

    // Master 0 is silence; the voice still exists (volume is a live gain, not a stop).
    mixer.set_bgm_volume(0.0);
    assert_eq!(mixer.bgm_volume(), 0.0);
    assert!(mixer.render(4).iter().all(|s| s.abs() < 1e-9));
    assert!(mixer.bgm_playing());

    // Out-of-range master values clamp instead of amplifying/inverting.
    mixer.set_bgm_volume(-3.0);
    assert_eq!(mixer.bgm_volume(), 0.0);
    mixer.set_bgm_volume(9.0);
    assert_eq!(mixer.bgm_volume(), 1.0);

    // SE volume behaves the same way.
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_se(constant(0.4, 64, 48_000, 1), 0.5);
    mixer.set_se_volume(0.5);
    for s in mixer.render(4) {
        assert!((s - 0.1).abs() < 1e-6, "SE master gain: got {s}");
    }
    mixer.set_se_volume(0.0);
    assert!(mixer.render(4).iter().all(|s| s.abs() < 1e-9));
}

#[test]
fn per_voice_volume_above_one_is_clamped() {
    // SoundCmd carries 0..=100 (a few shipped SE store 200); /100 can exceed 1.
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_se(constant(0.5, 16, 48_000, 1), 2.0);
    for s in mixer.render(4) {
        assert!(
            (s - 0.5).abs() < 1e-6,
            "voice gain must clamp to 1.0: got {s}"
        );
    }
}

// ---------------------------------------------------------------------------
// BGM voice lifecycle
// ---------------------------------------------------------------------------

#[test]
fn play_bgm_replaces_the_previous_voice() {
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_bgm(constant(0.2, 64, 48_000, 1), true, 1.0);
    assert!((mixer.render(4)[0] - 0.2).abs() < 1e-6);
    mixer.play_bgm(constant(0.6, 64, 48_000, 1), true, 1.0);
    let out = mixer.render(4);
    assert!(mixer.bgm_playing(), "the new BGM voice is installed");
    for s in out {
        assert!((s - 0.6).abs() < 1e-6, "old BGM leaked: got {s}");
    }
}

#[test]
fn non_looping_bgm_ends_and_is_removed() {
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_bgm(constant(0.5, 4, 48_000, 1), false, 1.0);
    let out = mixer.render(4);
    assert_eq!(out.len(), 4);
    assert!(
        !mixer.bgm_playing(),
        "a finished non-looping BGM must be removed"
    );
    let rest = mixer.render(8);
    assert!(
        rest.iter().all(|s| s.abs() < 1e-9),
        "silence after the BGM ended"
    );
}

#[test]
fn looping_bgm_without_loop_points_wraps_at_the_end() {
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_bgm(ramp(0.0, 0.1, 4, 48_000), true, 1.0);
    let out = mixer.render(6);
    let expected = [0.0f32, 0.1, 0.2, 0.3, 0.0, 0.1];
    for (i, (got, want)) in out.iter().zip(expected.iter()).enumerate() {
        assert!(
            (got - want).abs() < 1e-3,
            "frame {i}: got {got}, want {want} (end-wrap)"
        );
    }
    assert!(mixer.bgm_playing());
}

#[test]
fn fade_out_is_monotonic_and_silent_at_the_end() {
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_bgm(constant(1.0, 48_000, 48_000, 1), true, 1.0);
    mixer.stop_bgm(60); // 60 game frames = 1 second at 48 kHz
    let expected = 48_000usize; // 60 game frames at 60 fps = 1 second at 48 kHz
    let out = mixer.render(expected);
    assert_eq!(out.len(), expected);
    // Starts at full scale, never rises, and ends essentially silent.
    assert!(
        (out[0] - 1.0).abs() < 1e-6,
        "fade must start at full gain: {}",
        out[0]
    );
    for pair in out.windows(2) {
        assert!(
            pair[1] <= pair[0] + 1e-7,
            "fade gain rose: {} -> {}",
            pair[0],
            pair[1]
        );
    }
    assert!(
        out.last().copied().unwrap().abs() < 1e-3,
        "fade did not reach silence"
    );
    assert!(
        !mixer.bgm_playing(),
        "BGM must be cleared after the fade completes"
    );

    // The fade length is expressed in game frames, not output samples.
    let mut mixer = Mixer::new(96_000, 1);
    mixer.play_bgm(constant(1.0, 96_000, 96_000, 1), true, 1.0);
    mixer.stop_bgm(GAME_FPS as u32); // one second -> 96,000 output frames at 96 kHz
    let out = mixer.render(96_000);
    assert!(out.last().copied().unwrap().abs() < 1e-3);
    assert!(!mixer.bgm_playing());
}

// ---------------------------------------------------------------------------
// Resampling
// ---------------------------------------------------------------------------

#[test]
fn resampling_upsamples_with_linear_interpolation() {
    // 24 kHz source into a 48 kHz mixer: step 0.5, so output frames land on
    // source positions 0, 0.5, 1.0, 1.5 -> 0, 0.05, 0.1, 0.15.
    let mut mixer = Mixer::new(48_000, 1);
    let mut audio = ramp(0.0, 0.1, 16, 24_000);
    audio.loop_start = Some(0);
    audio.loop_end = Some(16);
    mixer.play_bgm(audio, true, 1.0);
    let out = mixer.render(4);
    let expected = [0.0f32, 0.05, 0.1, 0.15];
    for (i, (got, want)) in out.iter().zip(expected.iter()).enumerate() {
        assert!((got - want).abs() < 1e-3, "up {i}: got {got}, want {want}");
    }
}

#[test]
fn resampling_downsamples_by_skipping_source_frames() {
    // 96 kHz source into a 48 kHz mixer: step 2.0, so output frames read source
    // positions 0, 2, 4 -> 0, 0.2, 0.4.
    let mut mixer = Mixer::new(48_000, 1);
    let mut audio = ramp(0.0, 0.1, 16, 96_000);
    audio.loop_start = Some(0);
    audio.loop_end = Some(16);
    mixer.play_bgm(audio, true, 1.0);
    let out = mixer.render(3);
    let expected = [0.0f32, 0.2, 0.4];
    for (i, (got, want)) in out.iter().zip(expected.iter()).enumerate() {
        assert!(
            (got - want).abs() < 1e-3,
            "down {i}: got {got}, want {want}"
        );
    }
}

// ---------------------------------------------------------------------------
// Channel mapping and SE mixing
// ---------------------------------------------------------------------------

#[test]
fn mono_source_fans_out_to_every_output_channel() {
    let mut mixer = Mixer::new(48_000, 2);
    mixer.play_bgm(constant(0.4, 8, 48_000, 1), true, 1.0);
    let out = mixer.render(4);
    assert_eq!(out.len(), 8);
    for (i, s) in out.iter().enumerate() {
        assert!((s - 0.4).abs() < 1e-6, "channel {i}: got {s}");
    }
}

#[test]
fn concurrent_se_voices_sum_clamp_and_expire() {
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_se(constant(0.5, 4, 48_000, 1), 1.0);
    mixer.play_se(constant(0.25, 4, 48_000, 1), 1.0);
    assert_eq!(mixer.se_count(), 2);
    let out = mixer.render(2);
    for s in out {
        assert!((s - 0.75).abs() < 1e-6, "SEs must sum: got {s}");
    }
    let rest = mixer.render(8);
    assert_eq!(mixer.se_count(), 0, "finished SE voices must be removed");
    // The two remaining source frames (positions 2 and 3) play inside this call; once a
    // voice reports `done` it must go silent immediately instead of holding its clamped
    // last sample for the rest of the buffer.
    for (i, s) in rest.iter().enumerate() {
        if i < 2 {
            assert!((s - 0.75).abs() < 1e-6, "tail frame {i}: got {s}");
        } else {
            assert!(s.abs() < 1e-9, "frame {i} after the voices ended: got {s}");
        }
    }
}

#[test]
fn a_finished_se_does_not_hold_its_last_sample() {
    // Regression: a one-shot voice used to keep emitting its clamped final sample for
    // every remaining frame of the render chunk (a DC tail after the sound ended).
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_se(constant(0.5, 2, 48_000, 1), 1.0);
    let out = mixer.render(8);
    assert!((out[0] - 0.5).abs() < 1e-6);
    assert!((out[1] - 0.5).abs() < 1e-6);
    for (i, s) in out.iter().enumerate().skip(2) {
        assert!(s.abs() < 1e-9, "frame {i} after the SE ended: got {s}");
    }
    assert_eq!(mixer.se_count(), 0);
}

// ---------------------------------------------------------------------------
// Null engine and SoundCmd adapter
// ---------------------------------------------------------------------------

#[test]
fn null_engine_is_deterministic_and_silent_without_voices() {
    let a = Engine::null_with(48_000, 2);
    let b = Engine::null_with(48_000, 2);
    assert!(a.is_silent() && b.is_silent());
    assert!(a.render_offline(64).iter().all(|s| s.abs() < 1e-9));

    let mut a = Engine::null_with(48_000, 2);
    let mut b = Engine::null_with(48_000, 2);
    a.play_bgm_audio(constant(0.3, 64, 48_000, 2), true, 1.0);
    b.play_bgm_audio(constant(0.3, 64, 48_000, 2), true, 1.0);
    assert_eq!(a.render_offline(32), b.render_offline(32));
}

#[test]
fn sound_cmd_play_and_stop_shapes_are_safe() {
    // Missing files: Play must warn (once) and leave the engine usable, never panic.
    let mut engine = Engine::null_with(48_000, 2);
    engine.apply_sound_cmd(&cmd(
        SoundChannel::Bgm,
        SoundAction::Play,
        "BGM/does-not-exist.ogg",
        100,
        0,
    ));
    engine.apply_sound_cmd(&cmd(
        SoundChannel::Se,
        SoundAction::Play,
        "SE/does-not-exist.wav",
        200, // shipped loud-SE volume; must clamp, not amplify
        0,
    ));
    assert!(!engine.bgm_playing());
    assert_eq!(engine.se_count(), 0);

    // A real (tiny) shipped SE resolves and plays exactly once.
    if let Some(path) = smallest_shipped_se() {
        let data_root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../work/Data");
        let mut engine = Engine::null_with(48_000, 2);
        engine.set_asset_root(&data_root);
        let relative = path
            .strip_prefix(&data_root)
            .expect("SE under the asset root")
            .to_string_lossy()
            .replace('\\', "/");
        engine.apply_sound_cmd(&cmd(SoundChannel::Se, SoundAction::Play, &relative, 100, 0));
        assert_eq!(engine.se_count(), 1, "shipped SE {relative} should play");
        engine.apply_sound_cmd(&cmd(SoundChannel::Se, SoundAction::Stop, "", 0, 0));
        assert_eq!(engine.se_count(), 0, "SE Stop clears all SE voices");
    } else {
        eprintln!("skipping the real-SE half: work/Data/SE is absent");
    }

    // BGM Play with a real loop-tagged file also accepts SoundCmd's fade field on stop.
    if let Some(path) = smallest_shipped_se() {
        let ext = path.extension().and_then(|e| e.to_str()).unwrap_or("");
        if ext == "ogg" {
            let data_root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../work/Data");
            let mut engine = Engine::null_with(48_000, 2);
            engine.set_asset_root(&data_root);
            let relative = path
                .strip_prefix(&data_root)
                .expect("SE under the asset root")
                .to_string_lossy()
                .replace('\\', "/");
            engine.apply_sound_cmd(&cmd(SoundChannel::Bgm, SoundAction::Play, &relative, 50, 0));
            assert!(engine.bgm_playing(), "BGM Play installs a voice");
            engine.apply_sound_cmd(&cmd(SoundChannel::Bgm, SoundAction::Stop, "", 0, 30));
            assert!(engine.bgm_playing(), "a fading BGM is still audible");
            let _ = engine.render_offline(48_000);
            assert!(
                !engine.bgm_playing(),
                "the fade completed and cleared the BGM"
            );
        }
    }
}

#[test]
fn se_stop_is_stop_all_and_clears_every_concurrent_voice() {
    let mut engine = Engine::null_with(48_000, 2);
    engine.play_se_audio(constant(0.2, 4_800, 48_000, 1), 1.0);
    engine.play_se_audio(constant(0.3, 4_800, 48_000, 1), 1.0);
    engine.play_se_audio_with_delay(constant(0.4, 4_800, 48_000, 1), 1.0, 30);
    assert_eq!(engine.se_count(), 3, "three concurrent/pending SE voices");

    // intArgs[1] is the BGM fade-out slot; an SE stop ignores it and clears at once.
    engine.apply_sound_cmd(&cmd(SoundChannel::Se, SoundAction::Stop, "", 0, 12));
    assert_eq!(engine.se_count(), 0, "SE Stop clears every SE voice");
    let out = engine.render_offline(256);
    assert!(out.iter().all(|s| s.abs() < 1e-9), "nothing left to render");
}

#[test]
fn se_stop_leaves_the_bgm_voice_untouched() {
    let mut engine = Engine::null_with(48_000, 2);
    engine.play_bgm_audio(constant(0.25, 4_800, 48_000, 2), true, 1.0);
    engine.play_se_audio(constant(0.5, 4_800, 48_000, 1), 1.0);
    engine.play_se_audio(constant(0.5, 4_800, 48_000, 1), 1.0);
    assert!(engine.bgm_playing());
    assert_eq!(engine.se_count(), 2);

    engine.apply_sound_cmd(&cmd(SoundChannel::Se, SoundAction::Stop, "", 0, 0));
    assert_eq!(engine.se_count(), 0, "SE stop clears the SE bus");
    assert!(engine.bgm_playing(), "SE stop must not touch BGM");
    let out = engine.render_offline(256);
    assert!(out.iter().any(|s| s.abs() > 1e-6), "BGM is still audible");
}

#[test]
fn se_stop_on_an_empty_bus_is_a_silent_no_op() {
    let mut engine = Engine::null_with(48_000, 2);
    engine.apply_sound_cmd(&cmd(SoundChannel::Se, SoundAction::Stop, "", 0, 5));
    assert_eq!(engine.se_count(), 0);
    assert!(engine.render_offline(64).iter().all(|s| s.abs() < 1e-9));
}

// ---------------------------------------------------------------------------
// Decoding
// ---------------------------------------------------------------------------

#[test]
fn decodes_a_synthetic_pcm_wav() {
    // 8 kHz, 16-bit mono, four frames: -1.0, -0.5, 0.5, 1.0 (full-scale i16 steps).
    let samples = [i16::MIN, -16_384, 16_384, i16::MAX];
    let audio = decode_bytes(wav_bytes(&samples, 8_000, 1)).expect("probe + decode WAV");
    assert_eq!(audio.sample_rate, 8_000);
    assert_eq!(audio.channels, 1);
    assert_eq!(audio.frames(), 4);
    let got: Vec<f32> = (0..4).map(|i| audio.sample(i, 0)).collect();
    assert!((got[0] + 1.0).abs() < 1e-3, "first sample: {}", got[0]);
    assert!((got[1] + 0.5).abs() < 1e-3, "second sample: {}", got[1]);
    assert!((got[2] - 0.5).abs() < 1e-3, "third sample: {}", got[2]);
    assert!((got[3] - 1.0).abs() < 1e-3, "fourth sample: {}", got[3]);
}

#[test]
fn decodes_the_smallest_shipped_se() {
    let Some(path) = smallest_shipped_se() else {
        eprintln!("skipping decodes_the_smallest_shipped_se: work/Data/SE is absent");
        return;
    };
    let audio =
        decode_file(&path).unwrap_or_else(|e| panic!("failed to decode {}: {e}", path.display()));
    assert!(audio.sample_rate > 0, "{}: sample rate", path.display());
    assert!(audio.channels > 0, "{}: channels", path.display());
    assert!(audio.frames() > 0, "{}: frames", path.display());
}
