//! Compare two 1024x576 captures pixel by pixel.
//!
//! This is the measurement half of "did our renderer reproduce the retail engine":
//! it decodes two PNG/JPEG files, runs `wolf_render::compare`, prints per-channel
//! statistics, a 3x3 region grid and the worst pixels, and optionally writes a
//! scaled absolute-difference PNG.
//!
//! `\\\text
//! cargo run -p wolf-render --example imgdiff -- a.png b.png [--out work/out/diff.png]
//! `\\\
//!
//! WHY the exit code is 0 even for wildly different frames: this is a measuring
//! instrument, not a test. A non-zero exit would make every "the renderer is not
//! done yet" comparison look like a broken tool, and shell pipelines would stop at
//! the first interesting result. Only an unreadable file is an error.
//!
//! WHY the 3x3 grid: WOLF screens are composed in bands (background JPEG, map
//! chips, characters, message window). A single mean error cannot distinguish "the
//! background is right and the text is missing" from "everything is wrong", and
//! that distinction decides which subsystem to debug next.

use std::path::PathBuf;

use image::GenericImageView;
use wolf_render::{compare, diff_image, DiffReport};

fn main() {
    let mut args = std::env::args().skip(1);
    let mut paths: Vec<PathBuf> = Vec::new();
    let mut out: Option<PathBuf> = None;
    while let Some(arg) = args.next() {
        match arg.as_str() {
            "--out" => match args.next() {
                Some(path) => out = Some(PathBuf::from(path)),
                None => fail("--out needs a path"),
            },
            "--help" | "-h" => {
                println!("usage: imgdiff <a.png> <b.png> [--out <diff.png>]");
                println!("  prints per-channel error, a 3x3 region grid and the worst pixels");
                println!(
                    "  --out writes the absolute difference scaled by {}",
                    wolf_render::DIFF_GAIN
                );
                return;
            }
            other => paths.push(PathBuf::from(other)),
        }
    }
    if paths.len() != 2 {
        fail("expected exactly two image paths");
    }

    let first = match decode(&paths[0]) {
        Ok(frame) => frame,
        Err(err) => fail(&err),
    };
    let second = match decode(&paths[1]) {
        Ok(frame) => frame,
        Err(err) => fail(&err),
    };

    println!(
        "a: {} {}x{}",
        paths[0].display(),
        first.size[0],
        first.size[1]
    );
    println!(
        "b: {} {}x{}",
        paths[1].display(),
        second.size[0],
        second.size[1]
    );
    if first.size != second.size {
        println!(
            "size mismatch: comparing on {}x{} and padding the smaller frame with opaque black",
            first.size[0].max(second.size[0]),
            first.size[1].max(second.size[1])
        );
    }

    let report = compare(&first.pixels, first.size, &second.pixels, second.size);
    print_report(&report);

    if let Some(path) = out {
        let (pixels, size) = diff_image(&first.pixels, first.size, &second.pixels, second.size);
        if let Some(dir) = path.parent() {
            if !dir.as_os_str().is_empty() {
                if let Err(err) = std::fs::create_dir_all(dir) {
                    fail(&format!("creating {}: {err}", dir.display()));
                }
            }
        }
        if let Err(err) =
            image::save_buffer(&path, &pixels, size[0], size[1], image::ColorType::Rgba8)
        {
            fail(&format!("writing {}: {err}", path.display()));
        }
        let bytes = std::fs::metadata(&path).map(|meta| meta.len()).unwrap_or(0);
        println!(
            "wrote {} ({}x{}, {} bytes, delta scaled x{})",
            path.display(),
            size[0],
            size[1],
            bytes,
            wolf_render::DIFF_GAIN
        );
    }
}

/// A decoded frame: RGBA8 pixels plus their size.
struct Frame {
    pixels: Vec<u8>,
    size: [u32; 2],
}

/// Decode any PNG/JPEG/WebP/GIF the `image` crate understands into RGBA8.
///
/// WHY force RGBA8: PrintScreen output may be RGB (no alpha) and our own readback
/// is RGBA, and comparing buffers of different channel counts would silently
/// compare the wrong bytes.
fn decode(path: &PathBuf) -> Result<Frame, String> {
    let image = image::open(path).map_err(|err| format!("reading {}: {err}", path.display()))?;
    let (width, height) = image.dimensions();
    if width == 0 || height == 0 {
        return Err(format!("{} is empty", path.display()));
    }
    Ok(Frame {
        pixels: image.to_rgba8().into_raw(),
        size: [width, height],
    })
}

fn print_report(report: &DiffReport) {
    let [width, height] = report.compared;
    println!(
        "compared: {width}x{height} = {} px, identical: {}",
        report.pixels, report.identical
    );
    for (index, name) in ["R", "G", "B"].iter().enumerate() {
        println!(
            "  {name}: mean abs {:>7.3}  max abs {:>3}  rmse {:>7.3}",
            report.mean_abs[index], report.max_abs[index], report.rmse[index]
        );
    }
    println!(
        "overall: mean abs {:.3}, max abs {}, rmse {:.3}, psnr {}",
        report.mean_abs_all(),
        report.max_abs_all(),
        report.rmse.iter().sum::<f64>() / 3.0,
        format_psnr(report)
    );
    println!(
        "tolerance: <=2 {:>6.2}%  <=8 {:>6.2}%  >32 {:>6.2}%",
        report.within_2, report.within_8, report.above_32
    );

    println!("region mean abs error (3x3, row-major, R/G/B):");
    for row in 0..3 {
        let mut line = String::new();
        for column in 0..3 {
            if let Some(region) = report.region_at(column, row) {
                line.push_str(&format!(
                    "  [{:>3},{:>3}] {:>6.3}/{:>6.3}/{:>6.3}",
                    column, row, region[0], region[1], region[2]
                ));
            }
        }
        println!("{line}");
    }

    if report.worst.is_empty() {
        println!("worst pixels: none (frames are identical)");
        return;
    }
    println!(
        "worst {} pixels (largest channel delta first):",
        report.worst.len()
    );
    for pixel in &report.worst {
        println!(
            "  ({:>4},{:>3})  a={:>3},{:>3},{:>3}  b={:>3},{:>3},{:>3}  d={:>3},{:>3},{:>3}",
            pixel.x,
            pixel.y,
            pixel.a[0],
            pixel.a[1],
            pixel.a[2],
            pixel.b[0],
            pixel.b[1],
            pixel.b[2],
            pixel.delta[0],
            pixel.delta[1],
            pixel.delta[2]
        );
    }
}

fn format_psnr(report: &DiffReport) -> String {
    let psnr = report.psnr();
    if psnr.is_finite() {
        format!("{psnr:.2} dB")
    } else {
        "inf (identical)".to_owned()
    }
}

/// Report a fatal problem and exit non-zero.
///
/// Only called for unreadable inputs; every measurement outcome is a success.
fn fail(message: &str) -> ! {
    eprintln!("imgdiff: {message}");
    std::process::exit(2);
}
