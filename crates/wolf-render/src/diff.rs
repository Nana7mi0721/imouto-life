//! Pixel diffing for offscreen captures vs. real in-game screenshots.
//!
//! WHY this exists: the only ground truth we have is the retail engine's own
//! PrintScreen output, so every rendering milestone is validated by comparing a
//! capture against a reference frame. A single "mean error" number cannot tell
//! "the background is right but the text is missing" from "everything is wrong",
//! so the report carries a 3x3 region grid plus per-channel statistics, and the
//! 16 worst pixels so a human can look at exactly where the disagreement is.
//!
//! WHY it takes raw RGBA slices instead of paths: `image` is only a dev-dependency
//! of this crate (the renderer itself never decodes files -- assets are decoded by
//! the asset layer), and the maths is worth testing without a decoder. The example
//! does the decoding; this module stays dependency-free and `#![forbid(unsafe_code)]`
//! keeps it trivially auditable.

/// How many of the worst pixels a report keeps.
pub const WORST_LIMIT: usize = 16;

/// Gain applied to the absolute delta when writing a diff image.
///
/// A per-pixel error of 1..8 is invisible on screen but is exactly what we need to
/// see in a diff, so the delta is scaled up; 8 maps the "<= 8" tolerance bucket to
/// 64/255, which is plainly visible without clipping the whole image to white.
pub const DIFF_GAIN: u8 = 8;

/// One pixel where the two frames disagree most.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct WorstPixel {
    /// X coordinate in the compared canvas.
    pub x: u32,
    /// Y coordinate in the compared canvas.
    pub y: u32,
    /// First frame's RGB.
    pub a: [u8; 3],
    /// Second frame's RGB.
    pub b: [u8; 3],
    /// Absolute per-channel difference (`|a - b|`).
    pub delta: [u8; 3],
}

impl WorstPixel {
    /// Largest single-channel difference, the sort key of the worst-pixel list.
    #[must_use]
    pub fn max_delta(&self) -> u8 {
        self.delta[0].max(self.delta[1]).max(self.delta[2])
    }
}

/// Result of comparing two frames.
///
/// All means are over the *compared* canvas (the union of both sizes, with the
/// smaller frame padded with opaque black), and all percentages are in `0.0..=100.0`.
#[derive(Clone, Debug, PartialEq)]
pub struct DiffReport {
    /// Size of the first frame, in pixels.
    pub a_size: [u32; 2],
    /// Size of the second frame, in pixels.
    pub b_size: [u32; 2],
    /// Size actually compared (the per-axis maximum), in pixels.
    pub compared: [u32; 2],
    /// Number of pixels compared.
    pub pixels: u64,
    /// True when every compared pixel is byte-identical in RGB.
    pub identical: bool,
    /// Mean absolute error per channel (R, G, B).
    pub mean_abs: [f64; 3],
    /// Largest absolute error per channel (R, G, B).
    pub max_abs: [u8; 3],
    /// Root-mean-square error per channel (R, G, B).
    pub rmse: [f64; 3],
    /// Percentage of pixels whose largest channel delta is <= 2.
    pub within_2: f64,
    /// Percentage of pixels whose largest channel delta is <= 8.
    pub within_8: f64,
    /// Percentage of pixels whose largest channel delta is > 32.
    pub above_32: f64,
    /// Mean absolute error per channel for each cell of a 3x3 grid, row-major
    /// (index = `row * 3 + column`).
    pub regions: [[f64; 3]; 9],
    /// The `WORST_LIMIT` worst pixels, largest delta first.
    pub worst: Vec<WorstPixel>,
}

impl DiffReport {
    /// Mean absolute error over all three channels, the single headline number.
    #[must_use]
    pub fn mean_abs_all(&self) -> f64 {
        (self.mean_abs[0] + self.mean_abs[1] + self.mean_abs[2]) / 3.0
    }

    /// Largest absolute error over all three channels.
    #[must_use]
    pub fn max_abs_all(&self) -> u8 {
        self.max_abs[0].max(self.max_abs[1]).max(self.max_abs[2])
    }

    /// Peak signal-to-noise ratio in dB over all channels.
    ///
    /// WHY report it: it is the number people compare across papers and engines,
    /// and it stays meaningful when the mean error is 0.4 but one band is wrong.
    /// Returns `f64::INFINITY` for identical frames.
    #[must_use]
    pub fn psnr(&self) -> f64 {
        let mse = (self.rmse[0] * self.rmse[0]
            + self.rmse[1] * self.rmse[1]
            + self.rmse[2] * self.rmse[2])
            / 3.0;
        if mse <= 0.0 {
            return f64::INFINITY;
        }
        10.0 * (255.0_f64 * 255.0 / mse).log10()
    }

    /// Mean absolute error of the 3x3 cell holding the given canvas coordinates.
    #[must_use]
    pub fn region_at(&self, column: usize, row: usize) -> Option<[f64; 3]> {
        if column >= 3 || row >= 3 {
            return None;
        }
        Some(self.regions[row * 3 + column])
    }
}

/// Read one RGBA pixel, treating anything outside the buffer as opaque black.
///
/// WHY pad instead of refusing: captures occasionally come back one pixel short
/// (a window-manager edge), and failing the whole measurement over that hides the
/// 99.99% of the frame that did compare.
#[must_use]
pub fn rgba_at(rgba: &[u8], size: [u32; 2], x: u32, y: u32) -> [u8; 4] {
    if x >= size[0] || y >= size[1] {
        return [0, 0, 0, 255];
    }
    let index = ((y as usize) * (size[0] as usize) + (x as usize)) * 4;
    match rgba.get(index..index + 4) {
        Some(px) => [px[0], px[1], px[2], px[3]],
        None => [0, 0, 0, 255],
    }
}

/// Compare two RGBA8 frames.
///
/// The compared canvas is the per-axis maximum of both sizes; pixels outside a
/// frame's own bounds are read as opaque black, so a smaller capture is padded
/// rather than rejected. Alpha is ignored (a PrintScreen capture and our own
/// readback both come back fully opaque, and an alpha difference is never what we
/// are chasing).
#[must_use]
pub fn compare(a: &[u8], a_size: [u32; 2], b: &[u8], b_size: [u32; 2]) -> DiffReport {
    let width = a_size[0].max(b_size[0]);
    let height = a_size[1].max(b_size[1]);
    let pixels = u64::from(width) * u64::from(height);

    let mut report = DiffReport {
        a_size,
        b_size,
        compared: [width, height],
        pixels,
        identical: true,
        mean_abs: [0.0; 3],
        max_abs: [0; 3],
        rmse: [0.0; 3],
        within_2: 100.0,
        within_8: 100.0,
        above_32: 0.0,
        regions: [[0.0; 3]; 9],
        worst: Vec::new(),
    };
    if pixels == 0 {
        return report;
    }

    let mut sum_abs = [0_u64; 3];
    let mut sum_sq = [0_u64; 3];
    let mut region_abs = [[0_u64; 3]; 9];
    let mut region_count = [0_u64; 9];
    let mut count_within_2 = 0_u64;
    let mut count_within_8 = 0_u64;
    let mut count_above_32 = 0_u64;

    for y in 0..height {
        // Row bands and column bands of the 3x3 grid, computed with integer
        // arithmetic so a 1024-wide frame splits into 341/341/342 and the grid
        // always covers every pixel exactly once.
        let row = (u64::from(y) * 3 / u64::from(height)).min(2) as usize;
        for x in 0..width {
            let column = (u64::from(x) * 3 / u64::from(width)).min(2) as usize;
            let cell = row * 3 + column;

            let pa = rgba_at(a, a_size, x, y);
            let pb = rgba_at(b, b_size, x, y);
            let mut delta = [0_u8; 3];
            let mut max_delta = 0_u8;
            for channel in 0..3 {
                let d = pa[channel].abs_diff(pb[channel]);
                delta[channel] = d;
                max_delta = max_delta.max(d);
                sum_abs[channel] += u64::from(d);
                sum_sq[channel] += u64::from(d) * u64::from(d);
                region_abs[cell][channel] += u64::from(d);
            }
            region_count[cell] += 1;

            if max_delta <= 2 {
                count_within_2 += 1;
            }
            if max_delta <= 8 {
                count_within_8 += 1;
            }
            if max_delta > 32 {
                count_above_32 += 1;
            }
            if max_delta > 0 {
                report.identical = false;
                for (channel, value) in delta.iter().enumerate() {
                    report.max_abs[channel] = report.max_abs[channel].max(*value);
                }
                push_worst(
                    &mut report.worst,
                    WorstPixel {
                        x,
                        y,
                        a: [pa[0], pa[1], pa[2]],
                        b: [pb[0], pb[1], pb[2]],
                        delta,
                    },
                );
            }
        }
    }

    let total = pixels as f64;
    for channel in 0..3 {
        report.mean_abs[channel] = sum_abs[channel] as f64 / total;
        report.rmse[channel] = (sum_sq[channel] as f64 / total).sqrt();
    }
    for (cell, sums) in region_abs.iter().enumerate() {
        let count = region_count[cell].max(1) as f64;
        for (channel, sum) in sums.iter().enumerate() {
            report.regions[cell][channel] = *sum as f64 / count;
        }
    }
    report.within_2 = count_within_2 as f64 * 100.0 / total;
    report.within_8 = count_within_8 as f64 * 100.0 / total;
    report.above_32 = count_above_32 as f64 * 100.0 / total;
    // Largest error first; ties broken by position so two runs of the same input
    // print the same list (a report that shuffles is a report you cannot diff).
    report.worst.sort_by(|left, right| {
        right
            .max_delta()
            .cmp(&left.max_delta())
            .then(left.y.cmp(&right.y))
            .then(left.x.cmp(&right.x))
    });
    report
}

/// Keep the `limit` largest-delta pixels without sorting the whole frame.
///
/// WHY not "collect every differing pixel then sort": a 1024x576 frame has 589,824
/// pixels and the interesting ones are a handful; keeping a bounded list makes the
/// memory cost of the report independent of the image size.
fn push_worst(worst: &mut Vec<WorstPixel>, candidate: WorstPixel) {
    if worst.len() < WORST_LIMIT {
        worst.push(candidate);
        return;
    }
    let (mut min_index, mut min_delta) = (0_usize, u8::MAX);
    for (index, pixel) in worst.iter().enumerate() {
        let delta = pixel.max_delta();
        if delta < min_delta {
            min_index = index;
            min_delta = delta;
        }
    }
    if candidate.max_delta() > min_delta {
        worst[min_index] = candidate;
    }
}

/// Build an RGBA image of the absolute difference, scaled by `DIFF_GAIN`.
///
/// Returns the pixels and their size. Alpha is forced opaque so the diff can be
/// opened in any viewer without the black background turning transparent.
#[must_use]
pub fn diff_image(a: &[u8], a_size: [u32; 2], b: &[u8], b_size: [u32; 2]) -> (Vec<u8>, [u32; 2]) {
    let width = a_size[0].max(b_size[0]);
    let height = a_size[1].max(b_size[1]);
    let mut out = vec![0_u8; (width as usize) * (height as usize) * 4];
    for y in 0..height {
        for x in 0..width {
            let pa = rgba_at(a, a_size, x, y);
            let pb = rgba_at(b, b_size, x, y);
            let index = ((y as usize) * (width as usize) + (x as usize)) * 4;
            for channel in 0..3 {
                out[index + channel] = pa[channel].abs_diff(pb[channel]).saturating_mul(DIFF_GAIN);
            }
            out[index + 3] = 255;
        }
    }
    (out, [width, height])
}
