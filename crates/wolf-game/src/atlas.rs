//! A single RGBA8 atlas plus the shelf packer that fills it.
//!
//! WOLF draws pictures, chips, cursors and window frames from hundreds of separate files.
//! The renderer has exactly one texture and one draw call (see crates/wolf-render), so the
//! job here is to pack whatever the current frame needs into one 4096x4096 RGBA image and
//! hand back normalised UV rectangles.
//!
//! A shelf packer is deliberate rather than a general rectangle packer: WOLF's asset mix is
//! a few huge backgrounds (1024x576) plus many tiny UI pieces, which is exactly the shape a
//! shelf packer handles well with a fraction of the code. Images are inserted at native
//! size and never scaled, so a 1024x576 title graphic costs 2.25 MiB of the 64 MiB atlas -
//! the whole title screen fits with the atlas almost empty.
//!
//! 4096 is the largest page that is safe everywhere (the spec floor for
//! `max_texture_dimension_2d` is 8192) and it is not a luxury: a retail save that restores
//! three stacked character layers needs 129% of a 2048 page (docs/HSCENE.md 4.1), and one
//! cell of a 2400x1300 sprite sheet is only reachable once the page is big enough. What
//! still cannot be packed is recorded in [`Atlas::misses`] instead of vanishing, because a
//! silently dropped picture is indistinguishable from a script that never drew it.
//!
//! Text pictures are NOT atlas content: they carry no texture at all (see
//! [`crate::picture::ScreenQuad`]), so they are returned separately for the glyph pass.

use std::collections::{HashMap, HashSet};

use crate::assets::{Assets, ImageData};
use crate::picture::{Picture, Screen, SCREEN_H, SCREEN_W};
use crate::sysgraphic;
use crate::window;

/// One queued window panel: picture number, destination rect, alpha, tint, skin name.
type Panel<'a> = (i32, [f32; 4], f32, [f32; 3], &'a str);

/// Edge length of the atlas texture, in pixels.
///
/// 4096 costs 64 MiB of VRAM and of host memory (the page is built in RAM and uploaded as
/// one buffer), which is affordable on any GPU that can run this game, and it is the size
/// the retail content actually needs: a restored save stacks three character layers and the
/// resulting picture set wants 129% of a 2048 page. The alternative - several pages and a
/// draw call per page - buys nothing here, because the renderer's whole design is one
/// texture and one instanced draw.
pub const ATLAS_SIZE: u32 = 4096;

/// A rectangle inside the atlas, in pixels.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct AtlasRect {
    /// Left edge.
    pub x: u32,
    /// Top edge.
    pub y: u32,
    /// Width.
    pub w: u32,
    /// Height.
    pub h: u32,
}

impl AtlasRect {
    /// Normalised UVs of the whole rectangle, using the half-texel inset that keeps
    /// nearest sampling from ever touching a neighbour.
    #[must_use]
    pub fn uv(&self, atlas_w: u32, atlas_h: u32) -> [f32; 4] {
        let aw = atlas_w as f32;
        let ah = atlas_h as f32;
        [
            self.x as f32 / aw,
            self.y as f32 / ah,
            (self.x + self.w) as f32 / aw,
            (self.y + self.h) as f32 / ah,
        ]
    }

    /// Normalised UVs of a sub-rectangle, used when a picture animates through a sheet.
    #[must_use]
    pub fn sub_uv(&self, atlas_w: u32, atlas_h: u32, sub: [u32; 4]) -> [f32; 4] {
        let aw = atlas_w as f32;
        let ah = atlas_h as f32;
        let x0 = self.x + sub[0].min(self.w);
        let y0 = self.y + sub[1].min(self.h);
        let x1 = self.x + (sub[0] + sub[2]).min(self.w);
        let y1 = self.y + (sub[1] + sub[3]).min(self.h);
        [
            x0 as f32 / aw,
            y0 as f32 / ah,
            x1 as f32 / aw,
            y1 as f32 / ah,
        ]
    }
}

/// Converts a picture tone in 0..=255 into the 0.0..=1.0 multiplier the shader wants.
///
/// Divided at the last moment and in one place, so the byte value stays the single
/// source of truth for what the framebuffer will contain.
fn tone_tint(picture: &Picture) -> [f32; 3] {
    let [r, g, b] = picture.tone_byte();
    [
        f32::from(r) / 255.0,
        f32::from(g) / 255.0,
        f32::from(b) / 255.0,
    ]
}

/// One textured quad, in the shape the renderer wants.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct SpriteQuad {
    /// Picture slot this came from (for tracing).
    pub number: i32,
    /// Destination: `[x, y, w, h]` in logical (1024x576) pixels.
    pub rect: [f32; 4],
    /// Source: normalised atlas coordinates.
    pub uv: [f32; 4],
    /// Opacity 0.0..=1.0.
    pub alpha: f32,
    /// Per-channel brightness multiplier, normally 1.0 on every channel.
    ///
    /// This is where a picture tone becomes pixels: the retail title banner is drawn
    /// at 222/255 of its own artwork on every channel, which is exactly a tint of
    /// 222/255 multiplied into the texel. Alpha is a separate slot and the tone never
    /// touches it, matching DxLib SetDrawBright.
    pub tint: [f32; 3],
}

/// One text picture that still needs glyphs.
#[derive(Clone, Debug, PartialEq)]
pub struct TextQuad {
    /// Picture slot this came from.
    pub number: i32,
    /// Text to draw (may still contain display markup the glyph pass must strip).
    pub text: String,
    /// Window rectangle in logical pixels: `[x, y, w, h]`.
    pub rect: [f32; 4],
    /// Opacity.
    pub alpha: f32,
    /// Font size in pixels for this run; 0.0 means "use the caller's default (Sys8)".
    ///
    /// A text picture may mix sizes through \f[n], so the size lives on the quad and
    /// not on the picture: one picture becomes one quad per style run.
    pub font_px: f32,
    /// RGB from the SystemDB palette, already resolved; white when the run names none.
    pub colour: [u8; 3],
    /// True when the run asked for the \E outline.
    pub outline: bool,
    /// Font weight the retail face is drawn with (`400` for the tenths UI labels,
    /// `700` for the bold HUD/message text). Stored per quad because one screen can
    /// mix the save-slot raster labels with bold top-bar text.
    pub weight: u16,
}

/// Why a picture never made it into the atlas.
///
/// Dropping a picture silently is indistinguishable from a script that never drew it, and
/// a missing character layer looks like a bug in the save loader rather than a capacity
/// problem. Every refusal therefore carries one of these, and `Game` turns them into
/// diagnostics (see `crates/wolf-game/src/game.rs`).
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum AtlasMissReason {
    /// The image (or the requested cell) has a zero width or height.
    Empty,
    /// The image is wider or taller than the atlas page itself, so no packing order helps.
    TooLarge,
    /// The page is full: no shelf has room for it and no new shelf fits below.
    Full,
    /// The named asset could not be loaded from the data root.
    LoadFailed,
    /// The requested sub-rectangle does not lie inside the loaded image.
    CropFailed,
}

impl AtlasMissReason {
    /// Stable lowercase tag, used as the prefix of a diagnostic line.
    #[must_use]
    pub fn as_str(self) -> &'static str {
        match self {
            Self::Empty => "empty",
            Self::TooLarge => "too-large",
            Self::Full => "full",
            Self::LoadFailed => "load-failed",
            Self::CropFailed => "crop-failed",
        }
    }
}

/// One picture that could not be packed, kept so the caller can report it.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct AtlasMiss {
    /// Cache key of the picture: a WOLF asset name, `name#x,y,w,h` for a cell, or a
    /// `<sysgraphic:...>` key for a built-in drawing.
    pub key: String,
    /// Size that was asked for, in pixels; `[0, 0]` when the asset never loaded.
    pub size: [u32; 2],
    /// Why it was refused.
    pub reason: AtlasMissReason,
}

/// A half-open horizontal strip of the atlas.
#[derive(Clone, Copy, Debug)]
struct Shelf {
    y: u32,
    height: u32,
    used: u32,
}

/// The atlas: pixels, packed entries, and the shelf cursor.
pub struct Atlas {
    width: u32,
    height: u32,
    pixels: Vec<u8>,
    shelves: Vec<Shelf>,
    entries: HashMap<String, AtlasRect>,
    sources: HashMap<String, [u32; 2]>,
    used_area: u64,
    /// Pictures that were refused, in the order they were first seen.
    misses: Vec<AtlasMiss>,
    /// Keys already in `misses`, so a picture re-drawn every frame is reported once
    /// instead of flooding the diagnostics map.
    missed: HashSet<String>,
}

impl Default for Atlas {
    fn default() -> Self {
        Self::new()
    }
}

impl Atlas {
    /// An empty `ATLAS_SIZE` x `ATLAS_SIZE` atlas.
    #[must_use]
    pub fn new() -> Self {
        Self::with_size(ATLAS_SIZE, ATLAS_SIZE)
    }

    /// An empty atlas of an explicit size (tests use tiny ones).
    #[must_use]
    pub fn with_size(width: u32, height: u32) -> Self {
        Self {
            width,
            height,
            pixels: vec![0; width as usize * height as usize * 4],
            shelves: Vec::new(),
            entries: HashMap::new(),
            sources: HashMap::new(),
            used_area: 0,
            misses: Vec::new(),
            missed: HashSet::new(),
        }
    }

    /// `[width, height]` in pixels.
    #[must_use]
    pub fn size(&self) -> [u32; 2] {
        [self.width, self.height]
    }

    /// The RGBA8 pixels, ready for `Renderer::set_atlas`.
    #[must_use]
    pub fn pixels(&self) -> &[u8] {
        &self.pixels
    }

    /// How many distinct images are packed.
    #[must_use]
    pub fn len(&self) -> usize {
        self.entries.len()
    }

    /// True when nothing has been packed.
    #[must_use]
    pub fn is_empty(&self) -> bool {
        self.entries.is_empty()
    }

    /// Fraction of the atlas area in use, 0.0..=1.0.
    #[must_use]
    pub fn fill_ratio(&self) -> f64 {
        let total = f64::from(self.width) * f64::from(self.height);
        self.used_area as f64 / total
    }

    /// Where an already-packed image lives.
    #[must_use]
    pub fn entry(&self, name: &str) -> Option<AtlasRect> {
        self.entries.get(name).copied()
    }

    /// Native size of a packed image.
    #[must_use]
    pub fn source_size(&self, name: &str) -> Option<[u32; 2]> {
        self.sources.get(name).copied()
    }

    /// Packs one image, returning its rectangle. Returns `None` when it cannot fit.
    ///
    /// Names are the caller's key: packing the same name twice returns the first slot, so
    /// a picture re-drawn every frame costs nothing.
    ///
    /// A `None` is never silent: the reason lands in [`Atlas::misses`]. The signature stays
    /// `Option` on purpose - the packer is called from the tile, choice and CLI paths as
    /// well, and every one of them wants the same "pack it if you can" behaviour.
    pub fn add(&mut self, name: &str, image: &ImageData) -> Option<AtlasRect> {
        if let Some(rect) = self.entries.get(name) {
            return Some(*rect);
        }
        let (w, h) = (image.width, image.height);
        if w == 0 || h == 0 {
            self.miss(name, [w, h], AtlasMissReason::Empty);
            return None;
        }
        if w > self.width || h > self.height {
            self.miss(name, [w, h], AtlasMissReason::TooLarge);
            return None;
        }
        // First shelf that still fits, else open a new one. Real WOLF frames re-use the
        // same small UI pieces constantly, so the list stays short in practice.
        let mut slot = None;
        for (index, shelf) in self.shelves.iter_mut().enumerate() {
            if shelf.height >= h && self.width - shelf.used >= w {
                slot = Some((index, shelf.used, shelf.y));
                break;
            }
        }
        let (x, y) = match slot {
            Some((index, x, y)) => {
                self.shelves[index].used += w;
                (x, y)
            }
            None => {
                let y = self
                    .shelves
                    .last()
                    .map_or(0, |shelf| shelf.y + shelf.height);
                if y + h > self.height {
                    self.miss(name, [w, h], AtlasMissReason::Full);
                    return None;
                }
                self.shelves.push(Shelf {
                    y,
                    height: h,
                    used: w,
                });
                (0, y)
            }
        };
        self.blit(image, x, y);
        let rect = AtlasRect { x, y, w, h };
        self.entries.insert(name.to_owned(), rect);
        self.sources.insert(name.to_owned(), [w, h]);
        self.used_area += u64::from(w) * u64::from(h);
        Some(rect)
    }

    /// Loads an asset by WOLF name and packs it, caching by that name.
    pub fn add_asset(&mut self, assets: &mut Assets, name: &str) -> Option<AtlasRect> {
        if let Some(rect) = self.entries.get(name) {
            return Some(*rect);
        }
        let image = match assets.load(name) {
            Ok(image) => image,
            Err(_) => {
                self.miss(name, [0, 0], AtlasMissReason::LoadFailed);
                return None;
            }
        };
        self.add(name, &image)
    }

    /// Packs one `[x, y, w, h]` cell of a named image, caching by `name#rect`.
    ///
    /// The sprite-sheet path needs this: `Picture/stand_imouto_paja2.png` is 2400x1300,
    /// which no 2048-pixel atlas page can hold, but its 6 x 2 grid is six 400x650
    /// characters and only one cell is ever on screen at a time. Cropping first also keeps
    /// the cache honest: two pictures asking for different cells of one strip get two
    /// entries, while two asking for the same cell share one.
    pub fn add_asset_region(
        &mut self,
        assets: &mut Assets,
        name: &str,
        src: [u32; 4],
    ) -> Option<AtlasRect> {
        let key = format!("{name}#{},{},{},{}", src[0], src[1], src[2], src[3]);
        if let Some(rect) = self.entries.get(&key) {
            return Some(*rect);
        }
        let image = match assets.load(name) {
            Ok(image) => image,
            Err(_) => {
                self.miss(&key, [0, 0], AtlasMissReason::LoadFailed);
                return None;
            }
        };
        let cell = match image.crop(src) {
            Some(cell) => cell,
            None => {
                self.miss(&key, [src[2], src[3]], AtlasMissReason::CropFailed);
                return None;
            }
        };
        self.add(&key, &cell)
    }

    /// Renders a built-in `<...>` shape at w x h and packs it, caching by atlas key.
    ///
    /// The key is `sysgraphic::atlas_key`: it carries the shape (gradient endpoints
    /// included) and the size, so a bar that keeps its box is rendered once and only
    /// re-rendered when the script resizes it, and a `<SQUARE>` at 120x5 can never share a
    /// slot with the same command at 800x500.
    ///
    /// The pixels are pure white with a per-pixel alpha mask; the caller multiplies the
    /// picture's own tone and opacity into the quad, so colouring a shape costs nothing and
    /// never has to be re-rasterised.
    pub fn add_sysgraphic(
        &mut self,
        shape: sysgraphic::Shape,
        w: u32,
        h: u32,
    ) -> Option<AtlasRect> {
        let key = sysgraphic::atlas_key(shape, w, h);
        if let Some(rect) = self.entries.get(&key) {
            return Some(*rect);
        }
        let image = match sysgraphic::render(shape, w, h) {
            Some(image) => image,
            None => {
                self.miss(&key, [w, h], AtlasMissReason::Empty);
                return None;
            }
        };
        self.add(&key, &image)
    }

    /// Records that `key` could not be packed, once per key.
    fn miss(&mut self, key: &str, size: [u32; 2], reason: AtlasMissReason) {
        if !self.missed.insert(key.to_owned()) {
            return;
        }
        self.misses.push(AtlasMiss {
            key: key.to_owned(),
            size,
            reason,
        });
    }

    /// Every picture that was refused, in first-seen order.
    #[must_use]
    pub fn misses(&self) -> &[AtlasMiss] {
        &self.misses
    }

    /// Takes the refused list, leaving the atlas ready to report the next frame's misses.
    ///
    /// The caller drains this once per frame and turns each entry into a diagnostic, so
    /// the "atlas full" condition is visible in `--trace` output instead of looking like
    /// art that the script forgot to draw.
    pub fn take_misses(&mut self) -> Vec<AtlasMiss> {
        self.missed.clear();
        std::mem::take(&mut self.misses)
    }

    /// Same as [`Atlas::take_misses`], pre-formatted as `atlas <reason>: <key>`.
    ///
    /// This is the string `Game` folds into its diagnostics map: `atlas full:
    /// Picture/stand_imouto.png` reads as one fact, and the map already collapses
    /// repeats, so a picture refused every frame costs one line, not sixty.
    pub fn take_warnings(&mut self) -> Vec<String> {
        self.take_misses()
            .into_iter()
            .map(|miss| format!("atlas {}: {}", miss.reason.as_str(), miss.key))
            .collect()
    }

    fn blit(&mut self, image: &ImageData, x: u32, y: u32) {
        let stride = self.width as usize * 4;
        for row in 0..image.height as usize {
            let src = row * image.width as usize * 4;
            let dst = (y as usize + row) * stride + x as usize * 4;
            let len = image.width as usize * 4;
            self.pixels[dst..dst + len].copy_from_slice(&image.rgba[src..src + len]);
        }
    }

    /// Builds the draw list for the current screen.
    ///
    /// Text pictures are skipped here: they have no texture, and returning them is
    /// [`texts`]'s job.
    /// Packs one named asset and returns a single quad covering a sub-rectangle of it.
    ///
    /// The engine pause cursor is the first caller: `SystemFile/Text_Pause.png` is a
    /// vertical strip of animation frames and the engine picks one per blink phase, which
    /// no picture command can express. The destination is snapped like every other quad.
    pub fn sprite_from(
        &mut self,
        assets: &mut Assets,
        name: &str,
        number: i32,
        src: [u32; 4],
        dst: [f32; 4],
        alpha: f32,
    ) -> Option<SpriteQuad> {
        let entry = self.add_asset(assets, name)?;
        Some(SpriteQuad {
            number,
            rect: snap(dst),
            uv: entry.sub_uv(self.width, self.height, src),
            alpha,
            tint: [1.0, 1.0, 1.0],
        })
    }

    pub fn sprites(&mut self, screen: &Screen, assets: &mut Assets) -> Vec<SpriteQuad> {
        let mut out = Vec::new();
        // Window pictures (types 3 and 4) own a UI panel drawn from the 18x18 skin, with
        // their content painted on top. Panels are queued before the content loop and the
        // whole list is stably sorted by picture number afterwards, so a panel sits
        // directly under its own content and in script order relative to other pictures.
        let panels: Vec<Panel> = screen
            .iter()
            .filter_map(|picture| {
                if !picture.kind.is_window() {
                    return None;
                }
                // A window picture whose "file" is a built-in drawing command is not a
                // window: WOLF stores every system graphic as a type-3 command (all 375 of
                // them in this game are type 3), so without this test the author's
                // `<SQUARE>`, `<GRADX-999-274>` or `<TRI-DOWN>` would be painted as a nine-slice
                // panel from the default WindowBase.png and the drawing itself would never
                // appear. The skin path is untouched for every other window picture.
                if sysgraphic::parse(&picture.file).is_some() {
                    return None;
                }
                let (w, h) = picture.window?;
                if w <= window::MIN_BOX || h <= window::MIN_BOX {
                    return None;
                }
                // The anchor and the scale live in Picture::destination, the same law the
                // sprite pass and the message metrics use, so a centred panel lands centred.
                let mut dst = picture.destination(w as f32, h as f32);
                let ui = screen.ui_scale_for(picture.number);
                if ui > 1.0 {
                    // In a tenths UI block the VM already divides x back to pixels (op121
                    // with the extra /10 operand); only y, w and h stay in tenths.
                    dst = [dst[0], dst[1] / ui, dst[2] / ui, dst[3] / ui];
                }
                // The balloon library parks its panels off screen between bubbles; a panel
                // that cannot touch the screen would still cost nine quads and a skin pack.
                if !crate::picture::on_screen(dst) {
                    return None;
                }
                Some((
                    picture.number,
                    dst,
                    picture.alpha(),
                    tone_tint(picture),
                    picture.window_skin(),
                ))
            })
            .collect();
        for (number, dst, alpha, tint, skin_name) in panels {
            let Some(skin) = self.add_asset(assets, skin_name) else {
                continue;
            };
            let tex = self.source_size(skin_name).unwrap_or([0, 0]);
            // The cursor skin is a hollow selection frame, not a panel: fill it only when
            // it is used as a panel body (it never is in this game).
            let pieces = if skin_name.ends_with("CursorBase.png") {
                window::nine_slice_frame(dst, tex[0], tex[1], 4)
            } else {
                window::nine_slice(dst, tex[0], tex[1])
            };
            for piece in pieces {
                out.push(SpriteQuad {
                    number,
                    rect: snap(piece.rect),
                    uv: skin.sub_uv(self.width, self.height, piece.src),
                    alpha,
                    tint,
                });
            }
        }
        for quad in screen.quads(|name| assets.texture_size(name)) {
            if quad.kind.is_text() || quad.src[2] == 0 || quad.src[3] == 0 {
                continue;
            }
            // Built-in system graphics are synthesised at exactly the size the quad asks
            // for and cached under their own key, so this branch never touches Assets -
            // whose loader rejects every name containing ':' and would treat the drawing
            // command as a missing file. Everything else keeps the original file path.
            let (rect, size) = match sysgraphic::parse(&quad.file) {
                Some(shape) => match self.add_sysgraphic(shape, quad.src[2], quad.src[3]) {
                    Some(rect) => (rect, [quad.src[2], quad.src[3]]),
                    None => continue,
                },
                None => {
                    // The quad already carries the cell it wants, so pack that cell. For an
                    // ordinary picture this is the whole image; for a sprite sheet it is one
                    // 400x650 character out of a 2400x1300 strip no atlas page could hold.
                    let Some(rect) = self.add_asset_region(assets, &quad.file, quad.src) else {
                        continue;
                    };
                    (rect, [quad.src[2], quad.src[3]])
                }
            };
            let uv = if rect.w == size[0] && rect.h == size[1] {
                rect.uv(self.width, self.height)
            } else {
                rect.sub_uv(self.width, self.height, quad.src)
            };
            out.push(SpriteQuad {
                number: quad.number,
                rect: snap(quad.dst),
                uv,
                alpha: quad.alpha,
                tint: [
                    f32::from(quad.tone[0]) / 255.0,
                    f32::from(quad.tone[1]) / 255.0,
                    f32::from(quad.tone[2]) / 255.0,
                ],
            });
        }
        out.sort_by_key(|quad| quad.number);
        out
    }
}

/// Text pictures on the current screen, for the glyph pass.
#[must_use]
pub fn texts(screen: &Screen) -> Vec<TextQuad> {
    screen
        .quads(|_| None)
        .into_iter()
        .filter(|quad| quad.kind.is_text() && !quad.text.is_empty())
        .map(|quad| TextQuad {
            number: quad.number,
            // WOLF message markup (font size, colour, alignment, line breaks) is
            // display control, not characters: a renderer handed the raw string would
            // draw the escapes. The tokenizer keeps a lossless view for tools/tests;
            // the screen wants the stripped one (see wolf-format::messagetext).
            text: wolf_format::messagetext::strip(&quad.text),
            rect: quad.dst,
            alpha: quad.alpha,
            // One quad per picture: no style split here. `Game::text_quads` is the
            // markup-aware path and fills the three fields below.
            font_px: 0.0,
            colour: [255, 255, 255],
            outline: false,
            weight: 700,
        })
        .collect()
}

/// Snaps a destination rectangle to whole pixels.
///
/// WOLF positions pictures in integers anyway, but two things introduce fractions: the
/// scale percent multiplication, and the half-extent shift of a centre-anchored picture.
/// The origin truncates, because the engine hands float coordinates to a blit that casts
/// them to int; the retail title banner (606x35 at y 520, centre anchor) lands on row 502,
/// not 503, which is only reproducible by truncating 502.5. The extent rounds instead, so
/// nearest-neighbour sampling stays on exact texel edges and a 16 px chip never shows a
/// half-pixel seam.
fn snap(rect: [f32; 4]) -> [f32; 4] {
    [
        rect[0].trunc(),
        rect[1].trunc(),
        rect[2].round().max(1.0),
        rect[3].round().max(1.0),
    ]
}

/// The logical screen size, re-exported so callers need not know where it lives.
pub const LOGICAL: [u32; 2] = [SCREEN_W, SCREEN_H];

#[cfg(test)]
mod tests {
    use super::*;

    fn image(w: u32, h: u32, fill: u8) -> ImageData {
        ImageData::new(w, h, vec![fill; (w * h * 4) as usize]).expect("image")
    }

    #[test]
    fn shelf_packing_fills_a_row_before_opening_a_new_one() {
        let mut atlas = Atlas::with_size(16, 16);
        let a = atlas.add("a", &image(8, 4, 0x11)).expect("a");
        let b = atlas.add("b", &image(8, 4, 0x22)).expect("b");
        assert_eq!(
            a,
            AtlasRect {
                x: 0,
                y: 0,
                w: 8,
                h: 4
            }
        );
        assert_eq!(
            b,
            AtlasRect {
                x: 8,
                y: 0,
                w: 8,
                h: 4
            }
        );
        // Third 8x4 does not fit next to b, so it opens a shelf below the first one.
        let c = atlas.add("c", &image(8, 4, 0x33)).expect("c");
        assert_eq!(
            c,
            AtlasRect {
                x: 0,
                y: 4,
                w: 8,
                h: 4
            }
        );
        assert_eq!(atlas.len(), 3);
    }

    #[test]
    fn pixels_land_where_the_rectangle_says() {
        let mut atlas = Atlas::with_size(4, 4);
        let rect = atlas.add("px", &image(2, 1, 0xAB)).expect("px");
        assert_eq!(
            rect,
            AtlasRect {
                x: 0,
                y: 0,
                w: 2,
                h: 1
            }
        );
        // Two RGBA pixels of 0xAB at the start of the buffer.
        assert_eq!(&atlas.pixels()[..8], &[0xAB; 8]);
        // The rest of the atlas is still untouched.
        assert!(atlas.pixels()[8..].iter().all(|byte| *byte == 0));
    }

    #[test]
    fn the_same_name_is_packed_once() {
        let mut atlas = Atlas::with_size(16, 16);
        let first = atlas.add("dup", &image(4, 4, 0x10)).expect("first");
        let second = atlas.add("dup", &image(4, 4, 0x99)).expect("second");
        assert_eq!(first, second);
        assert_eq!(atlas.len(), 1);
        // The second call must not overwrite the pixels.
        assert_eq!(atlas.pixels()[0], 0x10);
    }

    #[test]
    fn an_image_that_cannot_fit_is_refused_instead_of_panicking() {
        let mut atlas = Atlas::with_size(8, 8);
        assert!(atlas.add("wide", &image(9, 1, 0)).is_none());
        assert!(atlas.add("tall", &image(1, 9, 0)).is_none());
        assert!(atlas.add("empty", &image(0, 0, 0)).is_none());
        // A full atlas refuses new work but keeps answering for what it already holds.
        assert!(atlas.add("ok", &image(8, 8, 1)).is_some());
        assert!(atlas.add("more", &image(4, 4, 2)).is_none());
        assert!(atlas.entry("ok").is_some());
        // Nothing was refused silently: every `None` above is on the record.
        let misses: Vec<(&str, AtlasMissReason)> = atlas
            .misses()
            .iter()
            .map(|miss| (miss.key.as_str(), miss.reason))
            .collect();
        assert_eq!(
            misses,
            [
                ("wide", AtlasMissReason::TooLarge),
                ("tall", AtlasMissReason::TooLarge),
                ("empty", AtlasMissReason::Empty),
                ("more", AtlasMissReason::Full),
            ]
        );
    }

    #[test]
    fn the_default_page_is_4096_which_is_what_the_retail_saves_need() {
        // A restored save stacks three character layers and needs 129% of a 2048 page
        // (docs/HSCENE.md 4.1), so the shipped page size is part of the contract.
        assert_eq!(ATLAS_SIZE, 4096);
        let atlas = Atlas::new();
        assert_eq!(atlas.size(), [4096, 4096]);
        assert_eq!(atlas.pixels().len(), 4096 * 4096 * 4);
    }

    #[test]
    fn an_image_too_big_for_a_2048_page_fits_on_the_shipped_page() {
        // `Picture/stand_imouto_paja2.png` is 2400x1300. One 400x650 cell of it fits either
        // page, but the sheet itself - and any full-bleed background of that size - only
        // fits once the page grows, which is exactly what the retail saves ran into.
        let sheet = image(2400, 1300, 0x5A);
        let mut small = Atlas::with_size(2048, 2048);
        assert!(small.add("sheet", &sheet).is_none());
        assert_eq!(small.misses()[0].reason, AtlasMissReason::TooLarge);
        assert_eq!(small.misses()[0].size, [2400, 1300]);

        let mut shipped = Atlas::with_size(ATLAS_SIZE, ATLAS_SIZE);
        let rect = shipped.add("sheet", &sheet).expect("fits on 4096");
        assert_eq!((rect.w, rect.h), (2400, 1300));
        assert!(shipped.misses().is_empty());
    }

    #[test]
    fn a_page_that_runs_out_of_rows_reports_the_names_that_were_dropped() {
        // Four 8x2 rows fill an 8x8 page exactly; the fifth has nowhere to go.
        let mut atlas = Atlas::with_size(8, 8);
        for index in 0..4 {
            atlas
                .add(&format!("row{index}"), &image(8, 2, index as u8))
                .expect("row");
        }
        assert!(atlas.add("late", &image(8, 2, 9)).is_none());
        let warnings = atlas.take_warnings();
        assert_eq!(warnings, ["atlas full: late"]);
        // Draining clears the record so the next frame starts empty.
        assert!(atlas.take_warnings().is_empty());
        assert!(atlas.misses().is_empty());
    }

    #[test]
    fn a_picture_refused_every_frame_is_reported_once() {
        let mut atlas = Atlas::with_size(8, 8);
        for _ in 0..60 {
            assert!(atlas.add("huge", &image(64, 64, 1)).is_none());
        }
        assert_eq!(atlas.misses().len(), 1, "one line, not sixty");
        assert_eq!(atlas.misses()[0].key, "huge");
        // Once the caller drains, the same key may be reported again next frame.
        atlas.take_warnings();
        assert!(atlas.add("huge", &image(64, 64, 1)).is_none());
        assert_eq!(atlas.misses().len(), 1);
    }

    #[test]
    fn a_failed_asset_load_is_a_miss_not_a_quiet_continue() {
        let mut atlas = Atlas::with_size(64, 64);
        let mut assets = Assets::new("no-such-root");
        assert!(atlas
            .add_asset(&mut assets, "Picture/missing.png")
            .is_none());
        assert_eq!(
            atlas.misses(),
            [AtlasMiss {
                key: "Picture/missing.png".to_owned(),
                size: [0, 0],
                reason: AtlasMissReason::LoadFailed,
            }]
        );
        // A cell request on a missing file is the same class of failure.
        assert!(atlas
            .add_asset_region(&mut assets, "Picture/missing.png", [0, 0, 8, 8])
            .is_none());
        assert_eq!(atlas.misses().len(), 2);
    }

    #[test]
    fn a_system_graphic_that_the_shape_refuses_is_a_miss_too() {
        let mut atlas = Atlas::with_size(64, 64);
        // A zero-width `<LINE>` has no pixels to draw (sysgraphic::render returns None).
        assert!(atlas
            .add_sysgraphic(sysgraphic::Shape::Line, 0, 1)
            .is_none());
        assert_eq!(atlas.misses()[0].reason, AtlasMissReason::Empty);
        assert!(atlas.misses()[0].key.starts_with("<sysgraphic:"));
        // The same shape at a usable size packs and clears nothing.
        assert!(atlas
            .add_sysgraphic(sysgraphic::Shape::Line, 32, 1)
            .is_some());
        assert_eq!(atlas.misses().len(), 1);
    }

    #[test]
    fn uv_rectangles_span_the_rect_and_sub_rects_stay_inside_it() {
        let mut atlas = Atlas::with_size(32, 32);
        let rect = atlas.add("uv", &image(16, 8, 0)).expect("uv");
        assert_eq!(rect.uv(32, 32), [0.0, 0.0, 0.5, 0.25]);
        // A sub-rect of the right half of that image.
        let sub = rect.sub_uv(32, 32, [8, 0, 8, 8]);
        assert_eq!(sub, [8.0 / 32.0, 0.0, 16.0 / 32.0, 8.0 / 32.0]);
        // Asking for more than the image holds clamps instead of running into neighbours.
        let clamped = rect.sub_uv(32, 32, [8, 4, 99, 99]);
        assert_eq!(clamped, [8.0 / 32.0, 4.0 / 32.0, 16.0 / 32.0, 8.0 / 32.0]);
    }

    #[test]
    fn fill_ratio_counts_only_packed_pixels() {
        let mut atlas = Atlas::with_size(4, 4);
        assert!(atlas.is_empty());
        assert_eq!(atlas.fill_ratio(), 0.0);
        atlas.add("half", &image(4, 2, 0)).expect("half");
        assert!((atlas.fill_ratio() - 0.5).abs() < 1e-9);
    }

    #[test]
    fn a_text_picture_produces_no_quad_but_does_surface_as_text() {
        use crate::picture::Screen;
        let mut screen = Screen::new();
        screen.apply(&wolf_vm::PictureCmd {
            number: 12500,
            kind: 2,
            action: wolf_vm::exec::PictureAction::Draw,
            file: String::new(),
            text: "hello".to_owned(),
            args: vec![0, 300, 200, 1, 255, 855, 200, 100, 0],
            animate: Vec::new(),
            keep_shift: false,
            relative: false,
            anchor: 0,
        });
        let mut atlas = Atlas::with_size(8, 8);
        let mut assets = Assets::new("no-such-root");
        assert!(atlas.sprites(&screen, &mut assets).is_empty());
        let texts = texts(&screen);
        assert_eq!(texts.len(), 1);
        assert_eq!(texts[0].rect, [855.0, 200.0, 300.0, 200.0]);
        assert_eq!(texts[0].text, "hello");
    }

    #[test]
    fn a_window_picture_paints_its_skin_under_the_content() {
        use crate::picture::Screen;
        use crate::window;
        let mut screen = Screen::new();
        screen.apply(&wolf_vm::PictureCmd {
            number: 12500,
            kind: 4,
            action: wolf_vm::exec::PictureAction::Draw,
            file: String::new(),
            text: "notice".to_owned(),
            args: vec![0, 300, 200, 1, 255, 855, 200, 100, 0],
            animate: Vec::new(),
            keep_shift: false,
            relative: false,
            anchor: 0,
        });
        let mut atlas = Atlas::with_size(64, 64);
        // Pre-pack the skin so the atlas never touches the filesystem: add_asset
        // returns the existing rectangle and the panel geometry is what is tested.
        let skin = atlas.add(window::SKIN, &image(18, 18, 0x7F)).expect("skin");
        let mut assets = Assets::new("no-such-root");
        let quads = atlas.sprites(&screen, &mut assets);
        assert_eq!(quads.len(), 9, "nine-slice of the 18x18 skin");
        // Frame 3 px, body stretched: 300-6 = 294 wide, 200-6 = 194 tall.
        assert_eq!(quads[0].rect, [855.0, 200.0, 3.0, 3.0]);
        assert_eq!(quads[4].rect, [858.0, 203.0, 294.0, 194.0]);
        assert_eq!(quads[8].rect, [1152.0, 397.0, 3.0, 3.0]);
        assert!(quads.iter().all(|quad| quad.number == 12500));
        assert!(quads.iter().all(|quad| (quad.alpha - 1.0).abs() < 1e-6));
        assert_eq!(atlas.entry(window::SKIN), Some(skin));
        // Type 4 is not text: it names a FILE through a string variable, so an empty name
        // falls back to the default skin and nothing goes to the glyph pass.
        assert_eq!(texts(&screen).len(), 0);
    }

    /// A `150` command for a built-in drawing, in the shape the interpreter emits it.
    fn shape_picture(
        number: i32,
        file: &str,
        box_size: (i32, i32),
        at: (i32, i32),
    ) -> wolf_vm::PictureCmd {
        wolf_vm::PictureCmd {
            number,
            // Every built-in graphic in this game is a type-3 (window/file) command.
            kind: 3,
            action: wolf_vm::exec::PictureAction::Draw,
            file: file.to_owned(),
            text: String::new(),
            args: vec![0, box_size.0, box_size.1, 1, 255, at.0, at.1, 100, 0],
            animate: Vec::new(),
            keep_shift: false,
            relative: false,
            anchor: 0,
        }
    }

    #[test]
    fn a_system_graphic_becomes_a_quad_under_its_own_key_instead_of_a_skin() {
        let mut screen = Screen::new();
        // The retail progress bar: `<SQUARE>FRAME` 120x5 at (320, 342).
        screen.apply(&shape_picture(40, "<SQUARE>FRAME", (120, 5), (320, 342)));
        let mut atlas = Atlas::with_size(256, 256);
        let mut assets = Assets::new("no-such-root");
        let quads = atlas.sprites(&screen, &mut assets);
        assert_eq!(
            quads.len(),
            1,
            "the drawing, and no nine-slice skin under it"
        );
        let key = sysgraphic::atlas_key(sysgraphic::Shape::SquareFrame, 120, 5);
        assert!(
            key.starts_with("<sysgraphic:") && key.contains("120x5"),
            "unexpected key {key}"
        );
        let rect = atlas.entry(&key).expect("packed under the sysgraphic key");
        assert_eq!((rect.w, rect.h), (120, 5));
        assert_eq!(quads[0].rect, [320.0, 342.0, 120.0, 5.0]);
        assert_eq!(quads[0].uv, rect.uv(256, 256));
        // A frame is a hollow white rectangle: the border is opaque, the middle is not.
        let pixel = |x: u32, y: u32| -> [u8; 4] {
            let offset = ((rect.y + y) * 256 + rect.x + x) as usize * 4;
            let slice = &atlas.pixels()[offset..offset + 4];
            [slice[0], slice[1], slice[2], slice[3]]
        };
        assert_eq!(pixel(0, 0), [255, 255, 255, 255]);
        assert_eq!(pixel(60, 2)[3], 0, "the interior stays transparent");
        // The window skin was never asked for, so it was never packed.
        assert_eq!(atlas.len(), 1);
        assert!(atlas.entry(crate::window::SKIN).is_none());
    }

    #[test]
    fn a_zero_height_line_still_reaches_the_atlas_as_one_pixel() {
        let mut screen = Screen::new();
        // All 7 `<LINE>` instructions in the game arrive with h = 0.
        screen.apply(&shape_picture(41, "<LINE>", (400, 0), (10, 20)));
        let mut atlas = Atlas::with_size(512, 16);
        let mut assets = Assets::new("no-such-root");
        let quads = atlas.sprites(&screen, &mut assets);
        assert_eq!(quads.len(), 1);
        assert_eq!(quads[0].rect, [10.0, 20.0, 400.0, 1.0]);
        let key = sysgraphic::atlas_key(sysgraphic::Shape::Line, 400, 1);
        assert!(atlas.entry(&key).is_some(), "a 400x1 rule is packed");
    }

    #[test]
    fn a_name_that_is_not_a_system_graphic_keeps_the_old_path() {
        // `<C>` is text markup and a real path is a real path: neither may be mistaken for
        // a drawing, so both fall through to the file lookup, which finds nothing here.
        assert!(sysgraphic::parse("<C>").is_none());
        assert!(sysgraphic::parse("Picture/frame.png").is_none());
        let mut screen = Screen::new();
        screen.apply(&shape_picture(42, "<C>", (8, 8), (0, 0)));
        let mut atlas = Atlas::with_size(64, 64);
        let mut assets = Assets::new("no-such-root");
        assert!(atlas.sprites(&screen, &mut assets).is_empty());
        assert!(atlas.is_empty());

        // A window picture that names a real file is drawn with THAT file as its skin: the
        // system-graphic tests above must not have stolen the nine-slice path, and the skin
        // is no longer hard-wired to window::SKIN (common event 63 passes its own).
        let mut screen = Screen::new();
        screen.apply(&wolf_vm::PictureCmd {
            number: 7,
            kind: 3,
            action: wolf_vm::exec::PictureAction::Draw,
            file: "SystemFile/panel.png".to_owned(),
            text: String::new(),
            args: vec![0, 300, 200, 1, 255, 855, 200, 100, 0],
            animate: Vec::new(),
            keep_shift: false,
            relative: false,
            anchor: 0,
        });
        let mut atlas = Atlas::with_size(64, 64);
        let skin = atlas
            .add("SystemFile/panel.png", &image(18, 18, 0x7F))
            .expect("skin");
        let quads = atlas.sprites(&screen, &mut assets);
        assert_eq!(quads.len(), 9, "nine-slice of the named 18x18 skin");
        assert_eq!(quads[0].rect, [855.0, 200.0, 3.0, 3.0]);
        assert_eq!(quads[4].rect, [858.0, 203.0, 294.0, 194.0]);
        assert_eq!(atlas.entry("SystemFile/panel.png"), Some(skin));
        // The skin is the only thing in the atlas: no drawing was synthesised for it.
        assert_eq!(atlas.len(), 1);
    }
}
