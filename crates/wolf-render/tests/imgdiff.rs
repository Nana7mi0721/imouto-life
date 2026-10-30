//! Integration test for the pixel-diff maths.
//!
//! WHY it lives in tests/ and not in src/diff.rs: the numbers the tool prints are
//! what the whole rendering-validation workflow trusts, so they are pinned here
//! against hand-computed frames rather than against the implementation's own
//! intermediate values. The frames are built in memory -- no GPU, no decoder, no
//! files on disk -- so this test also runs on a machine without a graphics adapter.

use wolf_render::{compare, diff_image, rgba_at, DiffReport, DIFF_GAIN, WORST_LIMIT};

/// Build a solid RGBA frame.
fn solid(width: u32, height: u32, color: [u8; 4]) -> Vec<u8> {
    let mut out = Vec::with_capacity((width as usize) * (height as usize) * 4);
    for _ in 0..(width * height) {
        out.extend_from_slice(&color);
    }
    out
}

#[test]
fn identical_frames_report_zero_everywhere() {
    let frame = solid(8, 4, [10, 20, 30, 255]);
    let report = compare(&frame, [8, 4], &frame, [8, 4]);
    assert!(report.identical);
    assert_eq!(report.pixels, 32);
    assert_eq!(report.mean_abs, [0.0, 0.0, 0.0]);
    assert_eq!(report.max_abs, [0, 0, 0]);
    assert_eq!(report.rmse, [0.0, 0.0, 0.0]);
    assert_eq!(report.within_2, 100.0);
    assert_eq!(report.within_8, 100.0);
    assert_eq!(report.above_32, 0.0);
    assert!(report.worst.is_empty());
    assert!(report.psnr().is_infinite());
    for cell in report.regions {
        assert_eq!(cell, [0.0, 0.0, 0.0]);
    }
}

#[test]
fn one_changed_pixel_is_pinned_to_exact_statistics() {
    // 4x2 = 8 pixels; pixel (1,1) turns red. Exactly one of eight pixels differs,
    // so the percentages are 87.5 / 87.5 / 12.5. The grid is always 3x3 whatever
    // the frame size: column = x*3/width and row = y*3/height, so x=1 of 4 lands in
    // column 0 and y=1 of 2 lands in row 1.
    let a = solid(4, 2, [0, 0, 0, 255]);
    let mut b = a.clone();
    let index = (4 + 1) * 4; // row 1 (stride 4), column 1
    b[index] = 200;

    let report = compare(&a, [4, 2], &b, [4, 2]);
    assert!(!report.identical);
    assert_eq!(report.pixels, 8);
    // Only the red channel moved, by 200, over 8 pixels.
    assert_eq!(report.mean_abs[0], 25.0);
    assert_eq!(report.mean_abs[1], 0.0);
    assert_eq!(report.mean_abs[2], 0.0);
    assert_eq!(report.max_abs, [200, 0, 0]);
    assert!((report.rmse[0] - (200.0_f64 * 200.0 / 8.0).sqrt()).abs() < 1e-9);
    assert_eq!(report.within_2, 87.5);
    assert_eq!(report.within_8, 87.5);
    assert_eq!(report.above_32, 12.5);

    // The single changed pixel is reported, with its coordinates and both colours.
    assert_eq!(report.worst.len(), 1);
    let worst = report.worst[0];
    assert_eq!((worst.x, worst.y), (1, 1));
    assert_eq!(worst.a, [0, 0, 0]);
    assert_eq!(worst.b, [200, 0, 0]);
    assert_eq!(worst.delta, [200, 0, 0]);
    assert_eq!(worst.max_delta(), 200);

    // Cell (0,1): x in 0..2 (columns 0 and 1 both map to 0 at width 4), y = 1 ->
    // two pixels, one of which is the changed one, so the mean is 200/2.
    assert_eq!(report.region_at(0, 1), Some([100.0, 0.0, 0.0]));
    // Cell (1,0): x = 2 only, y = 0 -> one unchanged pixel.
    assert_eq!(report.region_at(1, 0), Some([0.0, 0.0, 0.0]));
    assert!(report.region_at(3, 0).is_none());
}

#[test]
fn tolerance_buckets_count_pixels_not_channels() {
    // Three pixels: delta 0, delta 8 (inside both buckets), delta 33 (above).
    let a = solid(3, 1, [0, 0, 0, 255]);
    let mut b = a.clone();
    b[4] = 8; // red of pixel 1: delta 8, inside the <=8 bucket only
    b[8] = 33; // red of pixel 2: delta 33, past the >32 bucket
    let report = compare(&a, [3, 1], &b, [3, 1]);
    // Only the untouched pixel is within 2; two of three are within 8; one exceeds 32.
    assert!((report.within_2 - 100.0 / 3.0).abs() < 1e-9);
    assert!((report.within_8 - 200.0 / 3.0).abs() < 1e-9);
    assert!((report.above_32 - 100.0 / 3.0).abs() < 1e-9);
    assert_eq!(report.max_abs, [33, 0, 0]);
}

#[test]
fn a_smaller_frame_is_padded_with_black_instead_of_rejected() {
    let small = solid(2, 2, [255, 255, 255, 255]);
    let large = solid(4, 3, [255, 255, 255, 255]);
    let report = compare(&small, [2, 2], &large, [4, 3]);
    // 12 compared pixels; 4 of them are the small frame's white, the remaining 8
    // are padding (black) on one side only, so they differ by 255.
    assert_eq!(report.compared, [4, 3]);
    assert_eq!(report.pixels, 12);
    assert_eq!(report.max_abs, [255, 255, 255]);
    let expected = 255.0 * 8.0 / 12.0;
    assert!((report.mean_abs[0] - expected).abs() < 1e-9);
    assert!((report.above_32 - 800.0 / 12.0).abs() < 1e-9);
}

#[test]
fn out_of_bounds_reads_are_opaque_black() {
    let frame = solid(2, 2, [1, 2, 3, 255]);
    assert_eq!(rgba_at(&frame, [2, 2], 0, 0), [1, 2, 3, 255]);
    assert_eq!(rgba_at(&frame, [2, 2], 2, 0), [0, 0, 0, 255]);
    assert_eq!(rgba_at(&frame, [2, 2], 0, 2), [0, 0, 0, 255]);
    // A short buffer (fewer bytes than width*height*4) reads as black too.
    assert_eq!(rgba_at(&frame[..4], [2, 2], 1, 0), [0, 0, 0, 255]);
}

#[test]
fn the_worst_list_keeps_the_largest_deltas_and_is_deterministic() {
    // A 64x64 frame with a diagonal of increasing deltas: 64 differing pixels, but
    // the report must keep only the WORST_LIMIT largest.
    let (width, height) = (64_u32, 64_u32);
    let a = solid(width, height, [0, 0, 0, 255]);
    let mut b = a.clone();
    for step in 0..64_u32 {
        let index = ((step * width + step) * 4) as usize;
        b[index] = (step + 1) as u8;
    }
    let report = compare(&a, [width, height], &b, [width, height]);
    assert_eq!(report.worst.len(), WORST_LIMIT);
    // Largest deltas first: 64, 63, ... 49.
    for (offset, pixel) in report.worst.iter().enumerate() {
        assert_eq!(pixel.max_delta(), 64 - offset as u8);
        assert_eq!(pixel.x, pixel.y);
    }
    // Running it twice yields the same list (ties are broken by position).
    let again = compare(&a, [width, height], &b, [width, height]);
    assert_eq!(again.worst, report.worst);
}

#[test]
fn the_diff_image_scales_the_delta_and_forces_opaque_alpha() {
    let a = solid(2, 1, [0, 0, 0, 0]);
    let mut b = solid(2, 1, [0, 0, 0, 0]);
    b[0] = 3; // red of pixel 0
    b[4] = 100; // red of pixel 1
    let (pixels, size) = diff_image(&a, [2, 1], &b, [2, 1]);
    assert_eq!(size, [2, 1]);
    // 3 * 8 = 24 (no clipping), 100 * 8 saturates at 255.
    assert_eq!(pixels, vec![24, 0, 0, 255, 255, 0, 0, 255]);
    assert_eq!(DIFF_GAIN, 8);
}

#[test]
fn an_empty_frame_compares_to_zero_instead_of_panicking() {
    let report: DiffReport = compare(&[], [0, 0], &[], [0, 0]);
    assert_eq!(report.pixels, 0);
    assert!(report.identical);
    assert!(report.worst.is_empty());
    assert_eq!(report.mean_abs, [0.0, 0.0, 0.0]);
}
