//! M4 audio contract for SoundCmd.frames: BGM fade-in and SE start delay.
//!
//! SoundCmd.frames comes from opcode 140 intArgs[1] (the retail 'fade time / delay' slot):
//! for a BGM Play it is a fade-in length in game frames, for an SE Play it is a start delay in
//! game frames, and for a Stop it is a fade-out length. Until this task the mixer consumed it
//! only on Stop; these tests pin the newly implemented Play half.
//!
//! Everything is device-free and synthetic (constant PCM), so the suite runs with no work/Data
//! present. The one SoundCmd-adapter case that needs a real file is guarded and skips when the
//! shipped SE tree is absent.

use std::path::{Path, PathBuf};

use wolf_audio::mixer::{Mixer, GAME_FPS};
use wolf_audio::{DecodedAudio, Engine};
use wolf_vm::{SoundAction, SoundChannel, SoundCmd};

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

/// Constant-valued source (every channel carries 'value').
fn constant(value: f32, frames: usize, rate: u32, channels: u16) -> DecodedAudio {
    DecodedAudio {
        sample_rate: rate,
        channels,
        samples: vec![value; frames * channels as usize],
        loop_start: None,
        loop_end: None,
    }
}

/// Output frames for a length in game frames at 'rate' Hz (mirrors the mixer's conversion).
fn output_frames(game_frames: u32, rate: u32) -> usize {
    (((game_frames as f64 * rate as f64) / GAME_FPS as f64).round() as usize).max(1)
}

fn assert_monotonic_nondecreasing(out: &[f32], eps: f32) {
    for pair in out.windows(2) {
        assert!(
            pair[1] >= pair[0] - eps,
            "envelope must not fall: {} -> {}",
            pair[0],
            pair[1]
        );
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
        pitch: 100,
    }
}

/// The smallest shipped ogg/mp3/wav SE, if work/Data is present.
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
// BGM fade-in (SoundCmd.frames on a BGM Play)
// ---------------------------------------------------------------------------

#[test]
fn bgm_fade_in_ramps_monotonically_to_full_gain() {
    let mut mixer = Mixer::new(48_000, 1);
    // 6 game frames at 60 fps = 4,800 output frames at 48 kHz.
    mixer.play_bgm_with_fade(constant(1.0, 96_000, 48_000, 1), true, 1.0, 6);
    let fade_len = output_frames(6, 48_000);
    let out = mixer.render(fade_len);

    assert_eq!(out.len(), fade_len);
    assert!(
        out[0] > 0.0 && out[0] < 0.01,
        "fade must start near silence: {}",
        out[0]
    );
    assert_monotonic_nondecreasing(&out, 1e-7);
    assert!(
        (out[fade_len - 1] - 1.0).abs() < 1e-6,
        "fade must reach full gain on its final frame: {}",
        out[fade_len - 1]
    );

    // After the fade the voice keeps playing at full gain.
    let after = mixer.render(16);
    for s in &after {
        assert!(
            (s - 1.0).abs() < 1e-6,
            "post-fade gain must stay at 1.0: {s}"
        );
    }
    assert!(mixer.bgm_playing());
}

#[test]
fn bgm_fade_in_length_is_measured_in_game_frames() {
    // One second of fade at 96 kHz is still 60 game frames -> 96,000 output frames.
    let mut mixer = Mixer::new(96_000, 1);
    mixer.play_bgm_with_fade(
        constant(1.0, 192_000, 96_000, 1),
        true,
        1.0,
        GAME_FPS as u32,
    );
    let fade_len = output_frames(GAME_FPS as u32, 96_000);
    assert_eq!(fade_len, 96_000);
    let out = mixer.render(fade_len);
    assert_monotonic_nondecreasing(&out, 1e-7);
    assert!(
        out[0] < 0.001,
        "first sample of a one-second fade is tiny: {}",
        out[0]
    );
    assert!((out[fade_len - 1] - 1.0).abs() < 1e-6);
}

#[test]
fn bgm_fade_in_frames_zero_is_immediate() {
    let mut faded = Mixer::new(48_000, 1);
    faded.play_bgm_with_fade(constant(0.7, 64, 48_000, 1), true, 1.0, 0);
    let mut plain = Mixer::new(48_000, 1);
    plain.play_bgm(constant(0.7, 64, 48_000, 1), true, 1.0);

    // frames == 0 must reproduce the historical immediate-start behaviour exactly.
    assert_eq!(faded.render(8), plain.render(8));
    for s in faded.render(8) {
        assert!((s - 0.7).abs() < 1e-6, "no fade expected: {s}");
    }
}

#[test]
fn fade_in_fans_out_to_every_channel() {
    let mut mixer = Mixer::new(48_000, 2);
    mixer.play_bgm_with_fade(constant(1.0, 96_000, 48_000, 2), true, 1.0, 4);
    let fade_len = output_frames(4, 48_000);
    let out = mixer.render(fade_len);
    assert_eq!(out.len(), fade_len * 2);
    for frame in out.chunks_exact(2) {
        assert!(
            (frame[0] - frame[1]).abs() < 1e-9,
            "both channels must carry the same envelope: {:?}",
            frame
        );
    }
    let left: Vec<f32> = out.chunks_exact(2).map(|f| f[0]).collect();
    assert_monotonic_nondecreasing(&left, 1e-7);
    assert!((left[fade_len - 1] - 1.0).abs() < 1e-6);
}

// ---------------------------------------------------------------------------
// SE start delay (SoundCmd.frames on an SE Play)
// ---------------------------------------------------------------------------

#[test]
fn se_delay_stays_silent_then_plays() {
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_se_delayed(constant(0.5, 96_000, 48_000, 1), 1.0, 6);
    let delay_len = output_frames(6, 48_000);

    let quiet = mixer.render(delay_len);
    assert_eq!(quiet.len(), delay_len);
    assert!(
        quiet.iter().all(|s| s.abs() < 1e-9),
        "SE must be silent for the whole delay window"
    );
    assert_eq!(mixer.se_count(), 1, "the delayed voice still exists");

    let tail = mixer.render(8);
    for s in &tail {
        assert!((s - 0.5).abs() < 1e-6, "SE must sound after the delay: {s}");
    }
}

#[test]
fn se_delay_does_not_consume_the_source() {
    // A 4-frame source delayed by 6 game frames must still play all 4 frames afterwards.
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_se_delayed(constant(0.5, 4, 48_000, 1), 1.0, 6);
    let quiet = mixer.render(output_frames(6, 48_000));
    assert!(quiet.iter().all(|s| s.abs() < 1e-9));

    let out = mixer.render(8);
    for (i, s) in out.iter().enumerate() {
        if i < 4 {
            assert!((s - 0.5).abs() < 1e-6, "delayed source frame {i}: {s}");
        } else {
            assert!(s.abs() < 1e-9, "silence after the short source ended: {s}");
        }
    }
    assert_eq!(mixer.se_count(), 0);
}

#[test]
fn se_delay_frames_zero_is_immediate() {
    let mut delayed = Mixer::new(48_000, 1);
    delayed.play_se_delayed(constant(0.4, 8, 48_000, 1), 1.0, 0);
    let mut plain = Mixer::new(48_000, 1);
    plain.play_se(constant(0.4, 8, 48_000, 1), 1.0);
    assert_eq!(delayed.render(4), plain.render(4));
    for s in delayed.render(4) {
        assert!((s - 0.4).abs() < 1e-6, "no delay expected: {s}");
    }
}

// ---------------------------------------------------------------------------
// Fade-in / stop boundaries
// ---------------------------------------------------------------------------

#[test]
fn stopping_during_a_fade_in_clears_the_bgm() {
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_bgm_with_fade(constant(1.0, 96_000, 48_000, 1), true, 1.0, 30);
    let _ = mixer.render(100);
    mixer.stop_bgm(0); // immediate stop
    assert!(
        !mixer.bgm_playing(),
        "an immediate stop drops the voice even mid fade-in"
    );
    assert!(mixer.render(8).iter().all(|s| s.abs() < 1e-9));
}

#[test]
fn fade_in_then_fade_out_reaches_silence_and_clears() {
    let mut mixer = Mixer::new(48_000, 1);
    mixer.play_bgm_with_fade(constant(1.0, 96_000, 48_000, 1), true, 1.0, 6);
    let _ = mixer.render(output_frames(6, 48_000) / 2); // render halfway through the fade-in
    mixer.stop_bgm(6); // then fade out over 6 game frames
    let out = mixer.render(output_frames(6, 48_000));
    assert!(
        out.last().copied().unwrap().abs() < 1e-3,
        "fade-out must reach silence"
    );
    assert!(
        !mixer.bgm_playing(),
        "the voice is dropped once the fade-out completes"
    );
}

// ---------------------------------------------------------------------------
// Null engine (no device) still renders the envelope
// ---------------------------------------------------------------------------

#[test]
fn null_engine_fade_in_and_delay_render_offline() {
    let mut bgm = Engine::null_with(48_000, 1);
    assert!(bgm.is_silent());
    bgm.play_bgm_audio_with_fade(constant(1.0, 96_000, 48_000, 1), true, 1.0, 6);
    let fade_len = output_frames(6, 48_000);
    let out = bgm.render_offline(fade_len);
    assert!(out[0] < 0.01);
    assert_monotonic_nondecreasing(&out, 1e-7);
    assert!((out[fade_len - 1] - 1.0).abs() < 1e-6);

    let mut se = Engine::null_with(48_000, 1);
    se.play_se_audio_with_delay(constant(0.5, 96_000, 48_000, 1), 1.0, 6);
    let quiet = se.render_offline(fade_len);
    assert!(
        quiet.iter().all(|s| s.abs() < 1e-9),
        "null backend honours the SE delay"
    );
    assert_eq!(se.se_count(), 1);
    let tail = se.render_offline(8);
    assert!(tail.iter().all(|s| (s - 0.5).abs() < 1e-6));
}

/// SoundCmd adapter: the same frames slot must land as a BGM fade-in / SE delay. Needs a real
/// file to exercise apply_sound_cmd; skips when work/Data is absent.
#[test]
fn sound_cmd_play_frames_map_to_fade_and_delay() {
    let Some(path) = smallest_shipped_se() else {
        eprintln!("skipping sound_cmd_play_frames_map_to_fade_and_delay: work/Data/SE is absent");
        return;
    };
    let data_root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../work/Data");
    let relative = path
        .strip_prefix(&data_root)
        .expect("SE under the asset root")
        .to_string_lossy()
        .replace('\\', "/");

    // SE Play with a 6-game-frame delay: silent for the whole window, voice present.
    let mut se = Engine::null_with(48_000, 1);
    se.set_asset_root(&data_root);
    se.apply_sound_cmd(&cmd(SoundChannel::Se, SoundAction::Play, &relative, 100, 6));
    assert_eq!(se.se_count(), 1, "SE Play installs one voice");
    let quiet = se.render_offline(output_frames(6, 48_000));
    assert!(
        quiet.iter().all(|s| s.abs() < 1e-9),
        "SE must be silent while its SoundCmd.frames delay runs"
    );

    // BGM Play with a 60-game-frame (1 s) fade-in: the first output sample is essentially zero.
    let mut bgm = Engine::null_with(48_000, 1);
    bgm.set_asset_root(&data_root);
    bgm.apply_sound_cmd(&cmd(
        SoundChannel::Bgm,
        SoundAction::Play,
        &relative,
        50,
        60,
    ));
    assert!(bgm.bgm_playing(), "BGM Play installs a voice");
    let first = bgm.render_offline(8);
    assert!(
        first.iter().all(|s| s.abs() < 0.01),
        "BGM must fade in from near silence when SoundCmd.frames > 0"
    );
}
