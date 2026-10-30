//! Draw the title/save-screen text pictures offscreen and write a PNG.
//!
//! This is both the example for the text pass and its acceptance test: it loads a
//! font from the local WOLF install (never from a baked-in path), lays out the
//! exact strings CommonEvent 94 puts into its text pictures, renders them into the
//! 1024x576 logical framebuffer through the same render pass the sprite batch
//! uses, and writes the result to disk.
//!
//! `\\\text
//! cargo run -p wolf-render --example text_blit -- --out work/out/text.png
//! `\\\
//!
//! WHY the notice string is hard-coded here: it is the CN patch's DLC notice
//! (picture 12501 of CommonEvent 94) and it is the only string in the archive that
//! mixes ASCII digits, CJK punctuation and a full-width exclamation mark, which
//! makes it a good coverage probe for the game's bundled fonts. The menu strings
//! are the three semantic items of the title menu (CommonEvent 42 draws them as
//! images, but they are still the strings the original engine would lay out).

use std::path::{Path, PathBuf};

use wolf_render::{layout_box, missing_glyphs, Renderer, TextItem, LOGICAL_H, LOGICAL_W};

/// The CN patch's DLC notice, verbatim from CommonEvent 94 picture 12501.
const NOTICE: &str = "欢迎来到Ver2.0DLC！\n烦请注意\n存档的第一栏\n为自动存档所使用\n第一栏已有存档数据时，\n请先读取该存档，\n重新保存至合适的位置。";

/// The three title-menu entries (CommonEvent 42).
const MENU: [&str; 3] = ["はじめから", "つづきから", "おわる"];

/// Font size used for the notice, in logical pixels.
const NOTICE_SIZE: f32 = 22.0;

/// A font found on this machine: its path, its bytes, and the probe characters
/// it cannot render.
type PickedFont = (PathBuf, Vec<u8>, Vec<char>);

/// Font size used for the menu entries, in logical pixels.
const MENU_SIZE: f32 = 32.0;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut out = PathBuf::from("work/out/text.png");
    let mut explicit_font: Option<PathBuf> = None;
    let mut args = std::env::args().skip(1);
    while let Some(arg) = args.next() {
        match arg.as_str() {
            "--out" => out = PathBuf::from(args.next().ok_or("--out needs a path")?),
            "--font" => {
                explicit_font = Some(PathBuf::from(args.next().ok_or("--font needs a path")?))
            }
            "--help" | "-h" => {
                println!("usage: text_blit [--out <png>] [--font <ttf>]");
                println!("  --out   where to write the 1024x576 PNG (default work/out/text.png)");
                println!("  --font  use this TTF instead of probing the local install");
                return Ok(());
            }
            other => return Err(format!("unknown argument: {other}").into()),
        }
    }

    // The workspace root: examples live in crates/wolf-render/examples.
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("..").join("..");

    let probe = format!("{NOTICE}\n{}", MENU.concat());
    let chosen = match explicit_font {
        Some(path) => {
            let bytes = std::fs::read(&path)?;
            let missing = missing_glyphs(&bytes, &probe, NOTICE_SIZE);
            println!("font (explicit): {}", path.display());
            report_missing(&missing);
            (path, bytes, missing)
        }
        None => pick_font(&root, &probe)?,
    };
    let (font_path, font_bytes, missing) = chosen;
    if missing.is_empty() {
        println!("font covers every glyph in the probe string");
    }

    let mut renderer = Renderer::new_offscreen()?;
    println!(
        "adapter: backend={:?} name={}",
        renderer.adapter_info().backend,
        renderer.adapter_info().name
    );
    println!(
        "logical framebuffer: {LOGICAL_W}x{LOGICAL_H}, font: {}",
        font_path.display()
    );
    renderer.set_font(&font_bytes)?;

    // A flat dark panel behind the notice: this is a sprite, drawn in the same
    // render pass as the glyphs, so the PNG also proves the two share the pass
    // (the text is only visible if it is encoded after the sprite batch).
    let mut atlas = vec![0_u8; 4 * 4 * 4];
    for px in atlas.chunks_exact_mut(4) {
        px.copy_from_slice(&[28, 30, 42, 255]);
    }
    renderer.set_atlas(&atlas, 4, 4)?;
    renderer.draw(&[wolf_render::SpriteInstance::new(
        [24.0, 70.0, 552.0, 440.0],
        [0.0, 0.0, 1.0, 1.0],
    )]);

    let mut items = Vec::new();
    // The notice box, inset inside the panel.
    items.push(TextItem::new(
        NOTICE,
        [44.0, 90.0, 512.0, 400.0],
        NOTICE_SIZE,
    ));
    for (index, entry) in MENU.iter().enumerate() {
        let top = 200.0 + index as f32 * 56.0;
        items.push(TextItem::new(*entry, [700.0, top, 300.0, 48.0], MENU_SIZE));
    }
    // A half-transparent item, to exercise the alpha path.
    items.push(
        TextItem::new("AUTO SAVE SLOT", [700.0, 380.0, 300.0, 40.0], 24.0)
            .with_alpha(0.5)
            .with_align(wolf_render::TextAlign::Right),
    );
    // WOLF `\c[n]` + `\E`: gold body with a dark ring, which is how the game
    // draws its highlighted menu labels. Both travel through the same shaped
    // buffer and atlas entries as the white text above, so this PNG is the visual
    // proof that the two extra `TextItem` fields reach the GPU in order (ring
    // first, body on top).
    items.push(
        TextItem::new("COLOUR + OUTLINE", [700.0, 436.0, 300.0, 40.0], 24.0)
            .with_colour([255, 214, 102])
            .with_outline(2, [64, 120, 255])
            .with_align(wolf_render::TextAlign::Right),
    );
    renderer.draw_text(&items);

    renderer.present();

    let stats = renderer.text_stats().clone();
    println!(
        "laid out {} item(s), {} line(s), {} glyph(s), {} outline copy(ies); substituted {} char(s) with U+FFFD",
        stats.items, stats.lines, stats.glyphs, stats.outlines, stats.substituted
    );
    report_missing(&stats.missing);
    if let Some(err) = renderer.text_error() {
        println!("text pass reported: {err}");
    }

    // Show what the renderer does with a real WOLF text picture: picture 12501 is
    // 1x1 at (715,115), so the box has to be derived from the canvas.
    if let Some(bx) = layout_box([715.0, 115.0, 1.0, 1.0], [LOGICAL_W, LOGICAL_H]) {
        println!(
            "WOLF picture 12501 rect (715,115,1,1) -> layout box {:.0}x{:.0} at ({:.0},{:.0}), clip {:?}",
            bx.width, bx.height, bx.left, bx.top, bx.clip
        );
    }

    let pixels = renderer.capture_rgba()?;
    if let Some(dir) = out.parent() {
        if !dir.as_os_str().is_empty() {
            std::fs::create_dir_all(dir)?;
        }
    }
    image::save_buffer(&out, &pixels, LOGICAL_W, LOGICAL_H, image::ColorType::Rgba8)?;
    let bytes = std::fs::metadata(&out)?.len();
    println!(
        "wrote {} ({}x{}, {} bytes)",
        out.display(),
        LOGICAL_W,
        LOGICAL_H,
        bytes
    );
    Ok(())
}

fn report_missing(missing: &[char]) {
    if missing.is_empty() {
        return;
    }
    let rendered: String = missing
        .iter()
        .copied()
        .map(|c| format!("{c}(U+{:04X})", c as u32))
        .collect::<Vec<_>>()
        .join(" ");
    println!("missing glyphs -> U+FFFD: {rendered}");
}

/// Every directory that may hold a font the game ships.
///
/// WHY the install root is probed via an environment variable and a documented
/// fallback, and never hard-coded in the library: the fonts live in the player's
/// install directory (outside `Data/`, so they are not in the `.wolf` archives and
/// never end up under `work/alldata`), and the library must stay asset-free. This is
/// an example whose whole job is to find a local asset, so it may guess; the
/// fallback is the install path recorded in docs/FORMAT_SPEC.md and `--font` always
/// overrides it.
fn font_dirs(root: &Path) -> Vec<PathBuf> {
    let mut dirs: Vec<PathBuf> = Vec::new();
    let mut push = |dir: PathBuf| {
        if !dirs.contains(&dir) {
            dirs.push(dir);
        }
    };
    if let Some(install) = std::env::var_os("WOLF_GAME_DIR") {
        let install = PathBuf::from(install);
        push(install.clone());
        push(install.join("Data"));
    }
    let fallback =
        PathBuf::from("E:/SteamLibrary/steamapps/common/Living With SIster Monochrome Fantasy");
    push(fallback.clone());
    push(fallback.join("Data"));
    push(root.join("work/alldata"));
    push(root.join("work/full"));
    push(root.join("work/full/Data"));
    dirs
}

/// Pick the local font that covers the probe string best.
///
/// WHY "best coverage" instead of a fixed file name: the retail JP build and the
/// CN patch ship different font sets, and the patch's Simplified-Chinese strings
/// are not guaranteed to be in the game's Japanese default font. Probing every
/// TTF the install contains and reporting the shortfall is more useful than a
/// silent first-match. On this install that distinction is real: Lolita.ttf
/// covers all 89 glyphs of the probe, while 07yasashi/08gothic/GenJyuuGothicXPB
/// miss 9 of them (欢 烦 请 栏 为 动 时 读 该).
fn pick_font(root: &Path, probe: &str) -> Result<PickedFont, Box<dyn std::error::Error>> {
    let mut candidates: Vec<PathBuf> = Vec::new();
    for dir in font_dirs(root) {
        let Ok(entries) = std::fs::read_dir(&dir) else {
            continue;
        };
        for entry in entries.flatten() {
            let path = entry.path();
            let is_ttf = path
                .extension()
                .and_then(|ext| ext.to_str())
                .is_some_and(|ext| {
                    ext.eq_ignore_ascii_case("ttf") || ext.eq_ignore_ascii_case("otf")
                });
            if is_ttf {
                candidates.push(path);
            }
        }
    }
    candidates.sort();
    if candidates.is_empty() {
        return Err("no .ttf found under work/; pass --font <path.ttf>".into());
    }

    let mut best: Option<(usize, PathBuf, Vec<u8>, Vec<char>)> = None;
    for path in candidates {
        let Ok(bytes) = std::fs::read(&path) else {
            continue;
        };
        let missing = missing_glyphs(&bytes, probe, NOTICE_SIZE);
        println!(
            "  candidate {:<52} missing {:>2} glyph(s)",
            path.strip_prefix(root).unwrap_or(&path).display(),
            missing.len()
        );
        let better = best
            .as_ref()
            .is_none_or(|(count, ..)| missing.len() < *count);
        if better {
            best = Some((missing.len(), path, bytes, missing));
        }
    }
    let (count, path, bytes, missing) =
        best.ok_or("every candidate font failed to parse; pass --font <path.ttf>")?;
    println!("font: {} ({} missing glyph(s))", path.display(), count);
    Ok((path, bytes, missing))
}
