//! End-to-end tests for the offscreen pipeline.
//!
//! These need a working adapter, so they *skip* (with a message) instead of
//! failing when none is available: a headless box without a driver should not
//! turn "no GPU" into "the renderer is broken".
//!
//! What is actually being checked:
//!
//! * a sprite really lands where `rect` says, 1:1, inside a 1024x576 frame;
//! * the uv sub-rect really selects the requested texels (atlas left half white,
//!   right half black -- swapping half/whole uv is an easy bug to ship);
//! * 50% alpha over black yields ~127/255, not ~188/255. 188 is what an sRGB
//!   (linear-light) target produces; 127 is plain `dst = src*a + dst*(1-a)`
//!   arithmetic on gamma-encoded bytes -- the DxLib/D3D9 behaviour the retail
//!   game exhibits, and the reason `FRAME_FORMAT` is a UNORM format;
//! * the one measurement that decision rests on is pinned verbatim: a texel of
//!   rgb=0 / alpha=191 over a background of 251 must land on 63, which is what
//!   the retail title screenshot shows at (246,503).

use wolf_render::{Renderer, SpriteInstance, LOGICAL_H, LOGICAL_W};

const ATLAS_W: u32 = 64;
const ATLAS_H: u32 = 64;

/// Left half white, right half black, RGBA8.
fn checkerboard_atlas() -> Vec<u8> {
    let mut atlas = vec![0u8; (ATLAS_W * ATLAS_H * 4) as usize];
    for y in 0..ATLAS_H {
        for x in 0..ATLAS_W / 2 {
            let i = ((y * ATLAS_W + x) * 4) as usize;
            atlas[i] = 255;
            atlas[i + 1] = 255;
            atlas[i + 2] = 255;
            atlas[i + 3] = 255;
        }
    }
    atlas
}

/// Left half: opaque grey 251 (the title art's background). Right half: rgb 0
/// with alpha 191 -- the `Button01.png` texel measured at (246,503) of the
/// retail title screenshot.
fn retail_atlas() -> Vec<u8> {
    let mut atlas = vec![0u8; (ATLAS_W * ATLAS_H * 4) as usize];
    for y in 0..ATLAS_H {
        for x in 0..ATLAS_W {
            let i = ((y * ATLAS_W + x) * 4) as usize;
            if x < ATLAS_W / 2 {
                atlas[i] = 251;
                atlas[i + 1] = 251;
                atlas[i + 2] = 251;
                atlas[i + 3] = 255;
            } else {
                // rgb stays 0; only the alpha differs from the background half.
                atlas[i + 3] = 191;
            }
        }
    }
    atlas
}

fn offscreen_or_skip() -> Option<Renderer> {
    match Renderer::new_offscreen() {
        Ok(renderer) => Some(renderer),
        Err(err) => {
            eprintln!("skipping GPU test: {err}");
            None
        }
    }
}

fn pixel(pixels: &[u8], x: u32, y: u32) -> [u8; 4] {
    let i = ((y * LOGICAL_W + x) * 4) as usize;
    [pixels[i], pixels[i + 1], pixels[i + 2], pixels[i + 3]]
}

fn render(renderer: &mut Renderer, sprites: &[SpriteInstance]) -> Vec<u8> {
    renderer.draw(sprites);
    renderer.present();
    renderer.capture_rgba().expect("readback")
}

#[test]
fn frame_is_exactly_1024x576() {
    let Some(mut renderer) = offscreen_or_skip() else {
        return;
    };
    renderer
        .set_atlas(&checkerboard_atlas(), ATLAS_W, ATLAS_H)
        .unwrap();
    let pixels = render(&mut renderer, &[]);
    assert_eq!(pixels.len(), (LOGICAL_W * LOGICAL_H * 4) as usize);
    // Nothing queued -> clear colour, opaque black.
    assert_eq!(pixel(&pixels, 0, 0), [0, 0, 0, 255]);
    assert_eq!(pixel(&pixels, LOGICAL_W - 1, LOGICAL_H - 1), [0, 0, 0, 255]);
}

#[test]
fn sprite_lands_at_its_rect_and_respects_uv() {
    let Some(mut renderer) = offscreen_or_skip() else {
        return;
    };
    renderer
        .set_atlas(&checkerboard_atlas(), ATLAS_W, ATLAS_H)
        .unwrap();

    // Left half of the atlas (white) into the left half of the frame.
    let left = SpriteInstance::new([0.0, 0.0, 512.0, 576.0], [0.0, 0.0, 0.5, 1.0]);
    // Right half of the atlas (black) into the right half of the frame; it is
    // black, so it stays indistinguishable from the clear colour. If uv were
    // wrong this side would light up.
    let right = SpriteInstance::new([512.0, 0.0, 512.0, 576.0], [0.5, 0.0, 1.0, 1.0]);

    let pixels = render(&mut renderer, &[left, right]);
    assert_eq!(pixel(&pixels, 10, 10), [255, 255, 255, 255]);
    assert_eq!(pixel(&pixels, 511, 575), [255, 255, 255, 255]);
    assert_eq!(pixel(&pixels, 512, 0), [0, 0, 0, 255]);
    assert_eq!(pixel(&pixels, 1023, 300), [0, 0, 0, 255]);
}

/// Blending must happen in gamma space, i.e. on the stored bytes.
///
/// This is deliberately *not* physically correct compositing: an sRGB target
/// would give ~188 here (the linear 0.5 average re-encoded). We match DxLib
/// instead, because the retail game is the reference -- see `FRAME_FORMAT`.
#[test]
fn half_alpha_blends_in_gamma_space() {
    let Some(mut renderer) = offscreen_or_skip() else {
        return;
    };
    renderer
        .set_atlas(&checkerboard_atlas(), ATLAS_W, ATLAS_H)
        .unwrap();

    let quad = SpriteInstance::new(
        [0.0, 0.0, LOGICAL_W as f32, LOGICAL_H as f32],
        [0.0, 0.0, 0.5, 1.0],
    )
    .with_alpha(0.5);
    let pixels = render(&mut renderer, &[quad]);

    let [r, g, b, a] = pixel(&pixels, 512, 288);
    for channel in [r, g, b] {
        assert!(
            (127..=128).contains(&channel),
            "expected 127..=128 (gamma blend of 255 over 0) but got {channel}; 188 would mean linear-space blending"
        );
    }
    // Straight alpha composited OVER opaque black ends up fully opaque.
    assert_eq!(a, 255);
}

/// The retail regression: (246,503) of the real title screen.
///
/// `Button01.png` there is rgb=0 with alpha=191 sitting on a background of 251.
/// DxLib computes `0*0.749 + 251*0.251 = 63.0`; the retail PNG measures 63.
/// A linear-space pipeline computes 135 and we used to measure 136, which is
/// exactly the 0.52%-of-pixels difference the whole blend-space switch fixes.
#[test]
fn retail_gamma_blend_matches_the_screenshot() {
    let Some(mut renderer) = offscreen_or_skip() else {
        return;
    };
    renderer
        .set_atlas(&retail_atlas(), ATLAS_W, ATLAS_H)
        .unwrap();

    let background = SpriteInstance::new(
        [0.0, 0.0, LOGICAL_W as f32, LOGICAL_H as f32],
        [0.0, 0.0, 0.5, 1.0],
    );
    let button = SpriteInstance::new(
        [0.0, 0.0, LOGICAL_W as f32, LOGICAL_H as f32],
        [0.5, 0.0, 1.0, 1.0],
    );
    let pixels = render(&mut renderer, &[background, button]);

    let [r, g, b, a] = pixel(&pixels, 246, 503);
    for channel in [r, g, b] {
        assert!(
            (62..=64).contains(&channel),
            "expected 63 (0*0.749 + 251*0.251) but got {channel}; 136 would mean linear-space blending"
        );
    }
    assert_eq!(
        a, 255,
        "straight alpha over an opaque background stays opaque"
    );
}

#[test]
fn empty_batch_does_not_replay_the_previous_frame() {
    let Some(mut renderer) = offscreen_or_skip() else {
        return;
    };
    renderer
        .set_atlas(&checkerboard_atlas(), ATLAS_W, ATLAS_H)
        .unwrap();

    let quad = SpriteInstance::new([0.0, 0.0, 64.0, 64.0], [0.0, 0.0, 0.5, 1.0]);
    let first = render(&mut renderer, &[quad]);
    assert_eq!(pixel(&first, 0, 0), [255, 255, 255, 255]);

    let second = render(&mut renderer, &[]);
    assert_eq!(
        pixel(&second, 0, 0),
        [0, 0, 0, 255],
        "`draw(&[])` must clear the queue instead of replaying the old instances"
    );
    assert_eq!(renderer.instance_count(), 0);
}

#[test]
fn instance_buffer_grows_past_its_initial_capacity() {
    let Some(mut renderer) = offscreen_or_skip() else {
        return;
    };
    renderer
        .set_atlas(&checkerboard_atlas(), ATLAS_W, ATLAS_H)
        .unwrap();

    // Initial capacity is 256; 5000 instances force a couple of reallocations
    // and would silently truncate if the growth path were wrong.
    let sprites = vec![SpriteInstance::new([0.0, 0.0, 16.0, 16.0], [0.0, 0.0, 0.25, 0.25]); 5000];
    let pixels = render(&mut renderer, &sprites);
    assert_eq!(renderer.instance_count(), 5000);
    assert_eq!(pixel(&pixels, 8, 8), [255, 255, 255, 255]);
}
/// The retail banner is `Button01.png` multiplied by 222/255 on its **rgb only**,
/// alpha untouched -- DxLib `SetDrawBright` semantics ("brightness" scales the
/// colour channels, never the alpha). This pins that the renderer can express that
/// exactly through `SpriteInstance::with_tint_rgb`, i.e. the residual error on the
/// title frame is a per-picture tone the picture model has to supply, not something
/// wrong in the blend path. With the tone applied to the real title frame the mean
/// abs error against the retail screenshot drops from 0.283 to 0.004 (71.8 dB).
#[test]
fn per_picture_tone_is_expressible_through_tint() {
    let Some(mut renderer) = offscreen_or_skip() else {
        return;
    };
    renderer
        .set_atlas(&retail_atlas(), ATLAS_W, ATLAS_H)
        .unwrap();

    let tone = 222.0 / 255.0;
    let full = [0.0, 0.0, LOGICAL_W as f32, LOGICAL_H as f32];

    // Background: the opaque grey half, filling the frame at full brightness.
    let bg = SpriteInstance::new(full, [0.0, 0.0, 0.5, 1.0]);
    // The alpha-191 / rgb-0 texel from (246,503), drawn with a 222/255 tone.
    let button = SpriteInstance::new(full, [0.5, 0.0, 1.0, 1.0]).with_tint_rgb(tone, tone, tone);
    let pixels = render(&mut renderer, &[bg, button]);

    // rgb 0 stays 0 under any tone, so the composite must be unchanged: the tone
    // must not touch alpha. 0 * 191/255 + 251 * 64/255 = 63, the retail value.
    let got = pixel(&pixels, 246, 503);
    assert!(
        (62..=64).contains(&got[0]),
        "an rgb tone must not disturb the alpha blend: expected 63, got {got:?}"
    );
    assert_eq!(got[3], 255);

    // And the tone really does scale rgb: an opaque white texel times 222/255 is
    // 222, which is the retail banner's white fill (we currently emit 255 there).
    let mut white = vec![0u8; (ATLAS_W * ATLAS_H * 4) as usize];
    for texel in white.chunks_exact_mut(4) {
        texel.copy_from_slice(&[255, 255, 255, 255]);
    }
    renderer.set_atlas(&white, ATLAS_W, ATLAS_H).unwrap();
    let toned = SpriteInstance::new(full, [0.0, 0.0, 1.0, 1.0]).with_tint_rgb(tone, tone, tone);
    let pixels = render(&mut renderer, &[toned]);
    let got = pixel(&pixels, 512, 288);
    assert!(
        (221..=223).contains(&got[0]),
        "255 * 222/255 must land on 222, got {got:?}"
    );
    assert_eq!(got[3], 255, "opaque white must stay opaque");
}
