//! Title-screen blit: example *and* acceptance test for `wolf-render`.
//!
//! What it proves, in one run:
//!
//! * adapter selection works and is reported (backend + name), so a bug report
//!   can say which driver produced the pixels;
//! * the 1024x576 logical framebuffer renders headlessly to exactly that size
//!   (`--out`) with no window, no compositor and no display;
//! * the instanced sprite path draws straight-alpha geometry into a gamma-space
//!   (plain UNORM) target, the way DxLib does -- the second quad is a 50%-alpha
//!   stretch, so both the blend state and the blend space have to be right for
//!   the result to look like the retail game;
//! * with a window, the integer upscale and letterbox behave (title bar shows
//!   the scale factor).
//!
//! Usage:
//!
//! ```text
//! cargo run -p wolf-render --example title_blit -- --out /tmp/blit.png
//! cargo run -p wolf-render --example title_blit
//! ```
//!
//! Assets are read from the user's own unpacked game data at runtime; nothing
//! game-derived is committed to this repository.

use std::error::Error;
use std::path::{Path, PathBuf};
use std::sync::Arc;

use winit::application::ApplicationHandler;
use winit::dpi::PhysicalSize;
use winit::event::{ElementState, WindowEvent};
use winit::event_loop::{ActiveEventLoop, EventLoop};
use winit::keyboard::{Key, NamedKey};
use winit::window::{Window, WindowId};

use wolf_render::{Renderer, SpriteInstance, LOGICAL_H, LOGICAL_W};

/// Atlas page size. 2048x2048 RGBA8 = 16 MiB of VRAM, which is the sweet spot
/// for this game: the biggest single sheet family (CharaChip) packs into one
/// page, and every backend we care about supports 2048 even under WebGL2-style
/// minimum limits.
const ATLAS_W: u32 = 2048;
const ATLAS_H: u32 = 2048;

/// Where the example looks for artwork, in order of preference.
///
/// The logo is exactly 1024x576 (i.e. one logical screen of artwork), so it
/// exercises "native size" and "stretched" with the same source; the 12x12 icon
/// is the fallback for a checkout where only BasicData was unpacked.
const CANDIDATES: [&str; 2] = [
    "work/full/SystemFile/logo.jpg",
    "work/full/BasicData/icon000.png",
];

fn main() -> Result<(), Box<dyn Error>> {
    let mut out: Option<PathBuf> = None;
    let mut asset: Option<PathBuf> = None;
    let mut args = std::env::args().skip(1);
    while let Some(arg) = args.next() {
        match arg.as_str() {
            "--out" => {
                out = Some(PathBuf::from(
                    args.next().ok_or("--out needs a path argument")?,
                ))
            }
            "--asset" => {
                asset = Some(PathBuf::from(
                    args.next().ok_or("--asset needs a path argument")?,
                ))
            }
            "--help" | "-h" => {
                println!("usage: title_blit [--out <png>] [--asset <image>]");
                return Ok(());
            }
            other => return Err(format!("unknown argument {other}").into()),
        }
    }

    let asset_path = resolve_asset(asset.as_deref())?;
    let image = image::open(&asset_path)?.to_rgba8();
    println!(
        "asset: {} ({}x{})",
        asset_path.display(),
        image.width(),
        image.height()
    );

    let (atlas, uv) = build_atlas(&image);
    let sprites = build_sprites(uv, image.width(), image.height());

    match out {
        Some(path) => render_offscreen(&path, &atlas, &sprites),
        None => run_windowed(&atlas, &sprites),
    }
}

fn resolve_asset(explicit: Option<&Path>) -> Result<PathBuf, Box<dyn Error>> {
    if let Some(path) = explicit {
        return Ok(path.to_path_buf());
    }
    // crates/wolf-render -> repository root
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("..").join("..");
    for rel in CANDIDATES {
        let candidate = root.join(rel);
        if candidate.is_file() {
            return Ok(candidate);
        }
    }
    Err(format!(
        "no artwork found under {} (looked for {:?}); unpack the game's Data/*.wolf first \
         or pass --asset <image>",
        root.display(),
        CANDIDATES
    )
    .into())
}

/// Pack the source image at the atlas origin and return its uv rect.
fn build_atlas(image: &image::RgbaImage) -> (Vec<u8>, [f32; 4]) {
    let mut atlas = vec![0u8; (ATLAS_W * ATLAS_H * 4) as usize];
    let (w, h) = (image.width(), image.height());
    assert!(
        w <= ATLAS_W && h <= ATLAS_H,
        "source image {w}x{h} does not fit a {ATLAS_W}x{ATLAS_H} page"
    );
    let src = image.as_raw();
    for y in 0..h {
        let src_off = (y * w * 4) as usize;
        let dst_off = (y * ATLAS_W * 4) as usize;
        let row = (w * 4) as usize;
        atlas[dst_off..dst_off + row].copy_from_slice(&src[src_off..src_off + row]);
    }
    let uv = [
        0.0,
        0.0,
        w as f32 / ATLAS_W as f32,
        h as f32 / ATLAS_H as f32,
    ];
    (atlas, uv)
}

/// Two quads: one at native size, one stretched over the whole canvas at 50%
/// alpha. See the module docs for why the second one samples only the right half
/// of the source.
fn build_sprites(uv: [f32; 4], image_w: u32, image_h: u32) -> Vec<SpriteInstance> {
    let native = SpriteInstance::new([0.0, 0.0, image_w as f32, image_h as f32], uv);

    // Deliberate deviation from "stretch the same uv": the logo is *exactly*
    // 1024x576, so stretching the full uv over the canvas gives the same rect
    // with the same texels, and 50% of an image over itself is the image -- the
    // test would prove nothing. Sampling the right half and stretching it over
    // the full canvas keeps the "stretched to fill + 50% alpha" property while
    // making the composite visually unmistakable, and it exercises non-zero
    // uv.xy, which the native quad does not.
    let mid_u = (uv[0] + uv[2]) * 0.5;
    let stretched = SpriteInstance::new(
        [0.0, 0.0, LOGICAL_W as f32, LOGICAL_H as f32],
        [mid_u, uv[1], uv[2], uv[3]],
    )
    .with_alpha(0.5);

    vec![native, stretched]
}

fn print_adapter(renderer: &Renderer) {
    let info = renderer.adapter_info();
    println!("adapter: backend={:?} name={}", info.backend, info.name);
    println!(
        "logical framebuffer: {LOGICAL_W}x{LOGICAL_H}, atlas: {}x{}",
        renderer.atlas_size()[0],
        renderer.atlas_size()[1]
    );
}

fn render_offscreen(
    out: &Path,
    atlas: &[u8],
    sprites: &[SpriteInstance],
) -> Result<(), Box<dyn Error>> {
    let mut renderer = Renderer::new_offscreen()?;
    println!("mode: offscreen (no window)");
    renderer.set_atlas(atlas, ATLAS_W, ATLAS_H)?;
    print_adapter(&renderer);

    renderer.draw(sprites);
    println!("queued {} instances", renderer.instance_count());
    renderer.present();

    let pixels = renderer.capture_rgba()?;
    assert_eq!(
        pixels.len(),
        (LOGICAL_W * LOGICAL_H * 4) as usize,
        "readback is not one 1024x576 RGBA frame"
    );

    // Cheap content check: an all-black frame would still be a valid PNG, so
    // report how much of the frame is non-black. Both quads cover the canvas, so
    // a correct render is ~100%.
    let non_black = pixels
        .chunks_exact(4)
        .filter(|px| px[0] | px[1] | px[2] != 0)
        .count();
    println!(
        "non-black pixels: {non_black} / {} ({:.1}%)",
        LOGICAL_W * LOGICAL_H,
        non_black as f64 * 100.0 / f64::from(LOGICAL_W * LOGICAL_H)
    );

    if let Some(parent) = out.parent() {
        if !parent.as_os_str().is_empty() {
            std::fs::create_dir_all(parent)?;
        }
    }
    image::save_buffer(out, &pixels, LOGICAL_W, LOGICAL_H, image::ColorType::Rgba8)?;
    println!("wrote {} ({}x{})", out.display(), LOGICAL_W, LOGICAL_H);
    Ok(())
}

struct App {
    atlas: Vec<u8>,
    sprites: Vec<SpriteInstance>,
    window: Option<Arc<Window>>,
    renderer: Option<Renderer>,
}

impl ApplicationHandler for App {
    fn resumed(&mut self, event_loop: &ActiveEventLoop) {
        let attributes = Window::default_attributes()
            .with_title("wolf-render | title_blit")
            .with_inner_size(PhysicalSize::new(1920u32, 1080u32));
        let window = match event_loop.create_window(attributes) {
            Ok(window) => Arc::new(window),
            Err(err) => {
                eprintln!("could not create a window: {err}");
                event_loop.exit();
                return;
            }
        };

        let mut renderer = match Renderer::new(window.clone()) {
            Ok(renderer) => renderer,
            Err(err) => {
                eprintln!("renderer init failed: {err}");
                event_loop.exit();
                return;
            }
        };
        println!("mode: windowed");
        if let Err(err) = renderer.set_atlas(&self.atlas, ATLAS_W, ATLAS_H) {
            eprintln!("atlas upload failed: {err}");
            event_loop.exit();
            return;
        }
        print_adapter(&renderer);
        renderer.draw(&self.sprites);

        self.window = Some(window);
        self.renderer = Some(renderer);
    }

    fn window_event(&mut self, event_loop: &ActiveEventLoop, _id: WindowId, event: WindowEvent) {
        match event {
            WindowEvent::CloseRequested => event_loop.exit(),
            WindowEvent::KeyboardInput { event, .. } => {
                if event.state == ElementState::Pressed
                    && matches!(event.logical_key, Key::Named(NamedKey::Escape))
                {
                    event_loop.exit();
                }
            }
            WindowEvent::Resized(size) => {
                if let Some(renderer) = self.renderer.as_mut() {
                    renderer.resize(size);
                    let scaler = renderer.scaler();
                    if let Some(window) = self.window.as_ref() {
                        // Surface the integer scale in the title bar: the whole
                        // point of the scaler is that this is an integer, and
                        // seeing it move by whole steps on a resize is the
                        // cheapest manual check there is.
                        window.set_title(&format!(
                            "wolf-render | {}x{} -> {}x (offset {}, {})",
                            size.width,
                            size.height,
                            scaler.scale,
                            scaler.offset[0],
                            scaler.offset[1]
                        ));
                    }
                }
            }
            WindowEvent::RedrawRequested => {
                if let Some(renderer) = self.renderer.as_mut() {
                    renderer.draw(&self.sprites);
                    renderer.present();
                }
            }
            _ => {}
        }
    }

    fn about_to_wait(&mut self, _event_loop: &ActiveEventLoop) {
        if let Some(window) = self.window.as_ref() {
            window.request_redraw();
        }
    }
}

fn run_windowed(atlas: &[u8], sprites: &[SpriteInstance]) -> Result<(), Box<dyn Error>> {
    let event_loop = EventLoop::new()?;
    let mut app = App {
        atlas: atlas.to_vec(),
        sprites: sprites.to_vec(),
        window: None,
        renderer: None,
    };
    event_loop.run_app(&mut app)?;
    Ok(())
}
