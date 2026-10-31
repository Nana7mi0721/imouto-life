//! GPU text pass for the 1024x576 logical framebuffer.
//!
//! WHY glyphon + cosmic-text instead of a hand-rolled bitmap or SDF font path:
//! WOLF text is runtime-shaped, proportional CJK. The retail game ships its own
//! CJK TTF files (07yasashi.ttf, Lolita.ttf, MSGOTHIC.TTF, ...) and the CN patch
//! mixes Japanese and Simplified-Chinese strings inside the same archive, so no
//! glyph atlas can be baked at build time -- glyphs have to be rasterised from
//! the player's own font copy at whatever pixel size a picture asks for.
//! cosmic-text gives UAX#14 line breaking, bidi and swash rasterisation; glyphon
//! gives the instanced-quad atlas path on top of it; and glyphon 0.12.0 depends
//! on wgpu 30.0.0 while this crate is on 30.0.1, so exactly one wgpu is linked
//! (see docs/ARCHITECTURE.md section 3).
//!
//! WHY the font arrives as bytes and never as a path: all game assets, fonts
//! included, are read at runtime from the player's own install
//! (docs/ARCHITECTURE.md section 4). A hard-coded path here would make the
//! renderer depend on one machine's layout, and the font file names differ
//! between the retail JP build and the CN patch.
//!
//! WHAT WOLF actually asks for (measured against CommonEvent 94, the save/load
//! screen): a text picture is a rectangle plus a string, and the string already
//! has every WOLF escape (font, colour, outline, newline) expanded by the data
//! layer, so this module lays out plain text only. Pictures of type 2 routinely
//! carry a 1x1 rectangle because WOLF itself sizes them from the text, which is
//! why `layout_box` derives the width when the rectangle is degenerate.

use std::borrow::Cow;

use glyphon::cosmic_text::Align;
use glyphon::{
    fontdb, Attrs, Buffer, Cache, Color, Family, FontSystem, Metrics, Resolution, Shaping,
    SwashCache, TextArea, TextAtlas, TextBounds, TextRenderer as GlyphonTextRenderer, Viewport,
    Wrap,
};
use wgpu::{Device, MultisampleState, Queue, RenderPass, TextureFormat};

/// U+FFFD, substituted for every character the loaded font has no glyph for.
///
/// WHY substitute instead of dropping the character: a dropped CJK glyph turns
/// text into silent nonsense, while a visible replacement character makes a
/// missing-glyph regression obvious in a screenshot diff.
pub const REPLACEMENT_CHAR: char = '\u{FFFD}';

/// Line pitch as a multiple of the font size, matching WOLF's default row
/// height (it draws message text on a fixed pitch, not on the font's own
/// ascender+descender box).
pub const LINE_HEIGHT_FACTOR: f32 = 1.25;

/// Smallest font size the pass will honour (guards `Metrics` against 0).
pub const MIN_SIZE_PX: f32 = 6.0;

/// Largest font size the pass will honour (a 1024x576 canvas cannot show more).
pub const MAX_SIZE_PX: f32 = 256.0;

/// A rectangle whose width or height is at most this many logical pixels is
/// treated as "size me from my content".
///
/// WHY: WOLF text pictures are emitted with a 1x1 rectangle (CommonEvent 94,
/// picture 12501 = 1x1 at (715,115) carrying a seven-line notice) because the
/// engine sizes the window from the text; a renderer that trusted the rectangle
/// would clip that picture to a single pixel.
pub const AUTO_BOX_THRESHOLD: f32 = 2.0;

/// Locale handed to cosmic-text.
///
/// WHY zh-CN: Han unification makes the same code point pick different glyph
/// shapes in Japanese and Simplified-Chinese fonts, and this install is the CN
/// patch on top of the Japanese base game, so the Chinese shapes are the ones
/// the patch author saw.
const LOCALE: &str = "zh-CN";

/// Failure modes of the text pass.
#[derive(Debug)]
pub enum TextError {
    /// `TextRenderer::set_font` was handed an empty byte slice.
    EmptyFont,
    /// The font bytes parsed but the database exposes no face for them.
    FontRejected,
    /// `TextRenderer::prepare` ran before a font was set.
    NoFont,
    /// Glyph layout / atlas upload failed (message is glyphon's own).
    Prepare(String),
    /// Encoding the glyph draw call failed.
    Render(String),
}

impl core::fmt::Display for TextError {
    fn fmt(&self, f: &mut core::fmt::Formatter<'_>) -> core::fmt::Result {
        match self {
            Self::EmptyFont => f.write_str("font bytes are empty"),
            Self::FontRejected => f.write_str("font parsed but exposes no usable face"),
            Self::NoFont => f.write_str("no font has been loaded into the text pass"),
            Self::Prepare(e) => write!(f, "glyph preparation failed: {e}"),
            Self::Render(e) => write!(f, "glyph render failed: {e}"),
        }
    }
}

impl std::error::Error for TextError {}

/// Horizontal alignment of a text picture.
///
/// WOLF pictures are left-aligned by default; the other two exist because menu
/// pictures on the title/save screens are right- or centre-aligned in their box.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub enum TextAlign {
    /// Flush left (WOLF default).
    #[default]
    Left,
    /// Centred inside the box.
    Center,
    /// Flush right.
    Right,
}

impl TextAlign {
    const fn to_cosmic(self) -> Align {
        match self {
            Self::Left => Align::Left,
            Self::Center => Align::Center,
            Self::Right => Align::Right,
        }
    }
}

/// Outline (WOLF `\E`) parameters for one text picture.
///
/// WOLF draws an outline by stamping the glyphs in a solid colour at a ring of
/// offsets *before* the body. `TextRenderer::prepare` does exactly that: one
/// extra shaped buffer (which shares the glyph-atlas entries with the body, so
/// nothing is rasterised twice) plus four offset copies of the same layout.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Outline {
    /// Ring radius in logical pixels. Zero is normalised to "no outline" by
    /// `TextItem::with_outline`, so an escape width can be passed straight
    /// through.
    pub width_px: u8,
    /// Outline colour, RGB. Opaque by construction -- see `TextItem::colour`.
    pub colour: [u8; 3],
}

/// One text picture to draw this frame.
///
/// This is to text what `crate::SpriteInstance` is to sprites: a flat
/// description that owns no GPU state, so the game layer can build the list from
/// WOLF pictures without knowing that glyphon exists.
#[derive(Clone, Debug, PartialEq)]
pub struct TextItem {
    /// UTF-8 text with WOLF escapes already expanded (newlines are real newlines).
    pub text: String,
    /// Destination rectangle in logical pixels: [x, y, w, h] from the top-left
    /// of the 1024x576 canvas.
    pub rect: [f32; 4],
    /// Opacity multiplier in 0.0..=1.0 (WOLF picture alpha).
    pub alpha: f32,
    /// Font size in logical pixels.
    pub size_px: f32,
    /// Horizontal alignment inside `rect`.
    pub align: TextAlign,
    /// Body colour (WOLF `\c[n]`), RGB. Defaults to opaque white, which is what
    /// every text picture without a colour escape uses.
    ///
    /// WHY RGB and not RGBA: the alpha axis of a glyph is not a property of the
    /// colour, it is the picture's opacity, which lives in `Self::alpha` and is
    /// folded into `Attrs::color` at prepare time. Keeping the two apart is what
    /// lets a caller recolour a picture without accidentally un-fading it.
    ///
    /// WHY the opacity has to ride on `Attrs` at all: glyphon resolves a glyph's
    /// colour as `glyph.color_opt.unwrap_or(area.default_color)`, and
    /// cosmic-text copies `Attrs::color` into every glyph, so a body colour
    /// always wins over the area colour -- alpha channel included. A
    /// `TextArea::default_color` alpha is therefore dead for any item that
    /// carries a body colour, which is every item. See `TextRenderer::prepare`.
    pub colour: [u8; 3],
    /// Optional `\E` outline, drawn behind the body.
    pub outline: Option<Outline>,
}

impl TextItem {
    /// A left-aligned, fully opaque item.
    #[must_use]
    pub fn new(text: impl Into<String>, rect: [f32; 4], size_px: f32) -> Self {
        Self {
            text: text.into(),
            rect,
            alpha: 1.0,
            size_px,
            align: TextAlign::Left,
            colour: [255, 255, 255],
            outline: None,
        }
    }

    /// Set opacity (clamped to 0.0..=1.0 at prepare time).
    #[must_use]
    pub fn with_alpha(mut self, alpha: f32) -> Self {
        self.alpha = alpha;
        self
    }

    /// Set horizontal alignment.
    #[must_use]
    pub fn with_align(mut self, align: TextAlign) -> Self {
        self.align = align;
        self
    }

    /// Set the body colour (WOLF `\c[n]`).
    #[must_use]
    pub fn with_colour(mut self, colour: [u8; 3]) -> Self {
        self.colour = colour;
        self
    }

    /// Draw an outline behind the body (WOLF `\E`).
    ///
    /// A zero width is normalised to "no outline" rather than drawing four
    /// copies at offset zero, which would merely overdraw the body.
    #[must_use]
    pub fn with_outline(mut self, width_px: u8, colour: [u8; 3]) -> Self {
        self.outline = if width_px == 0 {
            None
        } else {
            Some(Outline { width_px, colour })
        };
        self
    }
}

/// Resolved placement of one `TextItem` inside the framebuffer.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct LayoutBox {
    /// Rounded left edge in logical pixels (may be negative: glyphon clips).
    pub left: f32,
    /// Rounded top edge in logical pixels (may be negative).
    pub top: f32,
    /// Width of the layout box in logical pixels, always >= 1.
    pub width: f32,
    /// Height of the layout box in logical pixels, always >= 1.
    pub height: f32,
    /// Integer scissor rectangle [left, top, right, bottom], half-open, already
    /// intersected with the framebuffer.
    pub clip: [i32; 4],
}

/// Resolve a WOLF picture rectangle into a layout box.
///
/// Returns `None` when the item can never be visible (non-finite values,
/// zero-sized canvas, or a rectangle entirely outside the canvas) so the caller
/// can skip it instead of asking the GPU for an empty scissor.
///
/// WHY round the origin: text on a 1024x576 pixel-art canvas that starts on a
/// fractional pixel gets resampled by the integer blit and turns into grey
/// mush; WOLF coordinates are integral anyway.
///
/// WHY clip: glyphon rasterises outside the viewport quite happily, but its
/// scissor is expressed in integer target pixels, and negative bounds make the
/// scissor disagree with the glyph positions it computed, so the box is
/// intersected here instead.
#[must_use]
pub fn layout_box(rect: [f32; 4], screen: [u32; 2]) -> Option<LayoutBox> {
    let [x, y, w, h] = rect;
    if !(x.is_finite() && y.is_finite() && w.is_finite() && h.is_finite()) {
        return None;
    }
    if screen[0] == 0 || screen[1] == 0 {
        return None;
    }
    let (screen_w, screen_h) = (screen[0] as f32, screen[1] as f32);

    let left = x.round();
    let top = y.round();
    let width = if w <= AUTO_BOX_THRESHOLD {
        (screen_w - left).max(1.0)
    } else {
        w.round().max(1.0)
    };
    let height = if h <= AUTO_BOX_THRESHOLD {
        (screen_h - top).max(1.0)
    } else {
        h.round().max(1.0)
    };

    let clip_left = left.max(0.0);
    let clip_top = top.max(0.0);
    let clip_right = (left + width).min(screen_w);
    let clip_bottom = (top + height).min(screen_h);
    if clip_right <= clip_left || clip_bottom <= clip_top {
        return None;
    }

    Some(LayoutBox {
        left,
        top,
        width,
        height,
        clip: [
            clip_left.floor() as i32,
            clip_top.floor() as i32,
            clip_right.ceil() as i32,
            clip_bottom.ceil() as i32,
        ],
    })
}

/// Grow a scissor rectangle by `pad` pixels, clamped to the canvas.
///
/// WHY grow at all: an outline sits *outside* the body's box by design, so
/// clipping it to the body box would erase exactly the ring it exists to draw.
/// Why clamp afterwards: glyphon clamps `TextArea::bounds` to the viewport
/// anyway, and an out-of-range integer scissor is a validation error rather than
/// a no-op.
fn expand_clip(clip: [i32; 4], pad: i32, screen: [u32; 2]) -> [i32; 4] {
    let pad = pad.max(0);
    let width = screen[0] as i32;
    let height = screen[1] as i32;
    [
        (clip[0] - pad).clamp(0, width),
        (clip[1] - pad).clamp(0, height),
        (clip[2] + pad).clamp(0, width),
        (clip[3] + pad).clamp(0, height),
    ]
}

/// Replace every character listed in `missing` with `REPLACEMENT_CHAR`.
///
/// Returns the rewritten string and how many characters were replaced. Pure, so
/// it can be tested without a GPU or a font.
#[must_use]
pub fn substitute_missing(text: &str, missing: &[char]) -> (String, usize) {
    if missing.is_empty() {
        return (text.to_owned(), 0);
    }
    let mut out = String::with_capacity(text.len());
    let mut replaced = 0_usize;
    for ch in text.chars() {
        if missing.contains(&ch) {
            out.push(REPLACEMENT_CHAR);
            replaced += 1;
        } else {
            out.push(ch);
        }
    }
    (out, replaced)
}

/// What the last `TextRenderer::prepare` did, for logging and tests.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct TextStats {
    /// Items that survived layout (were on screen).
    pub items: usize,
    /// Glyph quads submitted.
    pub glyphs: usize,
    /// Layout lines produced.
    pub lines: usize,
    /// Distinct characters the font could not cover, in first-seen order.
    pub missing: Vec<char>,
    /// Total characters substituted with U+FFFD.
    pub substituted: usize,
    /// Outline copies submitted this frame (four per outlined item). The body
    /// counters above stay body-only, so a log line does not change merely
    /// because one picture gained an outline.
    pub outlines: usize,
}

/// Turn a freshly loaded font blob into a `FontSystem` holding only that font.
///
/// WHY a private font database instead of `FontSystem::new()`: the default
/// constructor loads every system font (slow, and noisy), and more importantly it
/// silently borrows a system fallback for characters the game font lacks --
/// which would turn a real coverage bug into a "looks fine on my machine" render.
/// With a single-font database the platform fallback family names never resolve,
/// so `LayoutGlyph::glyph_id == 0` means what it says.
fn build_font_system(ttf: &[u8]) -> Result<(FontSystem, fontdb::ID, String), TextError> {
    let (system, id, family, _fallback_ids) = build_font_system_with(ttf, &[])?;
    Ok((system, id, family))
}

/// Like [`build_font_system`], but adds extra blobs to the same private database.
///
/// The extra faces are deliberately *not* a general system-font fallback: the caller
/// names them, and [`missing_chars`] treats their glyphs as covered rather than as a
/// miss. This is what lets a CN-patch UI font draw Chinese while a symbol font supplies
/// the few geometric shapes (the choice cursor U+25B6 is the real case) the UI face
/// does not contain.
fn build_font_system_with(
    ttf: &[u8],
    fallbacks: &[&[u8]],
) -> Result<(FontSystem, fontdb::ID, String, Vec<fontdb::ID>), TextError> {
    if ttf.is_empty() {
        return Err(TextError::EmptyFont);
    }
    let mut db = fontdb::Database::new();
    db.load_font_data(ttf.to_vec());
    let primary_faces: Vec<fontdb::ID> = db.faces().map(|face| face.id).collect();
    let (id, family) = {
        let face = db.faces().next().ok_or(TextError::FontRejected)?;
        let family = face
            .families
            .first()
            .map(|(name, _language)| name.clone())
            .ok_or(TextError::FontRejected)?;
        (face.id, family)
    };
    let mut fallback_ids: Vec<fontdb::ID> = Vec::new();
    for bytes in fallbacks {
        if bytes.is_empty() {
            continue;
        }
        db.load_font_data(bytes.to_vec());
        for face in db.faces() {
            if face.id != id
                && !primary_faces.contains(&face.id)
                && !fallback_ids.contains(&face.id)
            {
                fallback_ids.push(face.id);
            }
        }
    }
    let system = FontSystem::new_with_locale_and_db(LOCALE.to_string(), db);
    Ok((system, id, family, fallback_ids))
}

/// Characters in `buffer` that neither the primary face nor a named fallback can draw.
fn missing_chars(buffer: &Buffer, font_id: fontdb::ID, fallback_ids: &[fontdb::ID]) -> Vec<char> {
    let mut out: Vec<char> = Vec::new();
    for run in buffer.layout_runs() {
        for glyph in run.glyphs {
            // glyph_id 0 is .notdef; a face outside the allowed set means cosmic-text
            // silently swapped in a font the caller did not offer, which is a miss.
            if glyph.glyph_id != 0
                && (glyph.font_id == font_id || fallback_ids.contains(&glyph.font_id))
            {
                continue;
            }
            let Some(slice) = run.text.get(glyph.start..glyph.end) else {
                continue;
            };
            let Some(ch) = slice.chars().next() else {
                continue;
            };
            if ch.is_whitespace() || ch.is_control() || ch == REPLACEMENT_CHAR {
                continue;
            }
            if !out.contains(&ch) {
                out.push(ch);
            }
        }
    }
    out
}

/// Report which characters of `text` the given font cannot draw.
///
/// Pure CPU work (no GPU): a caller can use it to pick between the fonts a WOLF
/// install ships before building a renderer at all, which is exactly what
/// `examples/text_blit.rs` does.
#[must_use]
pub fn missing_glyphs(font: &[u8], text: &str, size_px: f32) -> Vec<char> {
    let Ok((mut system, font_id, family)) = build_font_system(font) else {
        return Vec::new();
    };
    let size = size_px.clamp(MIN_SIZE_PX, MAX_SIZE_PX);
    let mut buffer = Buffer::new(&mut system, Metrics::new(size, size * LINE_HEIGHT_FACTOR));
    let attrs = Attrs::new()
        .family(Family::Name(&family))
        .color(Color::rgb(255, 255, 255));
    buffer.set_text(text, &attrs, Shaping::Advanced, Some(Align::Left));
    buffer.shape_until_scroll(&mut system, false);
    missing_chars(&buffer, font_id, &[])
}

/// One shaped buffer placed on the canvas for this frame.
///
/// WHY a struct instead of the previous `(buffer index, layout box, alpha)`
/// tuple: an outlined item contributes five areas (four outline copies plus the
/// body) that share one layout box but differ in origin and scissor, so the
/// offset has to travel with the entry.
#[derive(Clone, Copy, Debug)]
struct Placed {
    /// Index into `TextRenderer::buffers`.
    buffer: usize,
    /// Area origin in logical pixels, from the top-left of the 1024x576 canvas.
    left: f32,
    /// Area origin in logical pixels, from the top-left of the 1024x576 canvas.
    top: f32,
    /// Integer scissor `[left, top, right, bottom]`, already intersected with the
    /// canvas.
    clip: [i32; 4],
    /// Opacity byte for `TextArea::default_color`.
    alpha: u8,
}

/// Owns the glyphon atlas + font system and draws `TextItem`s into a render pass.
///
/// One instance per `super::Renderer`. The atlas and the shaped buffers live
/// here so that sprite and text draws can share one render pass, and therefore
/// one load/clear, which is what keeps the 1024x576 canvas compositing right.
pub struct TextRenderer {
    cache: Cache,
    atlas: TextAtlas,
    viewport: Viewport,
    glyphs: GlyphonTextRenderer,
    font_system: FontSystem,
    swash: SwashCache,
    /// Face id of the loaded font; `None` until `set_font`.
    font_id: Option<fontdb::ID>,
    /// Extra faces explicitly offered for glyphs the primary face lacks.
    fallback_ids: Vec<fontdb::ID>,
    /// Family name to ask cosmic-text for; empty until `set_font`.
    font_family: String,
    /// Logical canvas size the pass renders into.
    screen: [u32; 2],
    /// Shaped buffers for the current frame, indexed by `placed`.
    buffers: Vec<Buffer>,
    /// Every area to draw this frame, in the order glyphon must emit it.
    placed: Vec<Placed>,
    /// Statistics from the last successful `prepare`.
    stats: TextStats,
}

impl TextRenderer {
    /// Create the text pass for a framebuffer of `screen_size` in `target_format`.
    ///
    /// `target_format` must match the texture the render pass targets
    /// (`crate::FRAME_FORMAT` for the game canvas), because glyphon bakes it into
    /// its pipeline.
    #[must_use]
    pub fn new(
        device: &Device,
        queue: &Queue,
        target_format: TextureFormat,
        screen_size: [u32; 2],
    ) -> Self {
        let cache = Cache::new(device);
        let mut atlas = TextAtlas::new(device, queue, &cache, target_format);
        let glyphs =
            GlyphonTextRenderer::new(&mut atlas, device, MultisampleState::default(), None);
        let mut viewport = Viewport::new(device, &cache);
        let screen = [screen_size[0].max(1), screen_size[1].max(1)];
        viewport.update(
            queue,
            Resolution {
                width: screen[0],
                height: screen[1],
            },
        );
        // Empty font database: set_font() installs the real one. Starting empty
        // keeps construction cheap (FontSystem::new() parses ~1000 system faces).
        let empty_db = fontdb::Database::new();
        let font_system = FontSystem::new_with_locale_and_db(LOCALE.to_string(), empty_db);
        Self {
            cache,
            atlas,
            viewport,
            glyphs,
            font_system,
            swash: SwashCache::new(),
            font_id: None,
            fallback_ids: Vec::new(),
            font_family: String::new(),
            screen,
            buffers: Vec::new(),
            placed: Vec::new(),
            stats: TextStats::default(),
        }
    }

    /// Install the TTF/OTF blob the pass will shape text with.
    ///
    /// The bytes come from the player's install (see the module docs); nothing is
    /// cached on disk here. On failure the previously loaded font keeps working.
    pub fn set_font(&mut self, ttf: &[u8]) -> Result<(), TextError> {
        self.set_fonts(&[ttf])
    }

    /// Install one primary font plus optional fallback blobs.
    ///
    /// The first blob is the UI face; later blobs only fill glyphs it lacks. See
    /// [`build_font_system_with`] for why a fallback is not the platform's implicit one.
    pub fn set_fonts(&mut self, fonts: &[&[u8]]) -> Result<(), TextError> {
        let Some(primary) = fonts.first() else {
            return Err(TextError::EmptyFont);
        };
        let (system, id, family, fallback_ids) = build_font_system_with(primary, &fonts[1..])?;
        self.font_system = system;
        self.font_id = Some(id);
        self.fallback_ids = fallback_ids;
        self.font_family = family;
        self.buffers.clear();
        self.placed.clear();
        self.stats = TextStats::default();
        Ok(())
    }

    /// Add one fallback font blob to an already loaded pass.
    ///
    /// Used by the CLI so it can try several system files without rebuilding the
    /// primary font selection. Invalid or empty bytes are rejected without disturbing
    /// the current font.
    pub fn add_fallback_font(&mut self, ttf: &[u8]) -> Result<(), TextError> {
        if ttf.is_empty() {
            return Err(TextError::EmptyFont);
        }
        let Some(primary) = self.font_id else {
            return Err(TextError::NoFont);
        };
        let before: Vec<fontdb::ID> = {
            let db = self.font_system.db_mut();
            db.faces().map(|face| face.id).collect()
        };
        self.font_system.db_mut().load_font_data(ttf.to_vec());
        let after: Vec<fontdb::ID> = {
            let db = self.font_system.db_mut();
            db.faces().map(|face| face.id).collect()
        };
        for id in after {
            if id != primary && !before.contains(&id) && !self.fallback_ids.contains(&id) {
                self.fallback_ids.push(id);
            }
        }
        self.buffers.clear();
        self.placed.clear();
        self.stats = TextStats::default();
        Ok(())
    }

    /// Whether `set_font` has succeeded at least once.
    #[must_use]
    pub const fn has_font(&self) -> bool {
        self.font_id.is_some()
    }

    /// Family name of the loaded font, if any.
    #[must_use]
    pub fn font_family(&self) -> Option<&str> {
        self.font_id.map(|_| self.font_family.as_str())
    }

    /// Change the logical canvas the pass lays text out on.
    ///
    /// WOLF is fixed at 1024x576, so this only matters to tests.
    pub fn set_screen_size(&mut self, queue: &Queue, screen: [u32; 2]) {
        self.screen = [screen[0].max(1), screen[1].max(1)];
        self.viewport.update(
            queue,
            Resolution {
                width: self.screen[0],
                height: self.screen[1],
            },
        );
    }

    /// Shape `text` into a fresh buffer and return its index in `Self::buffers`.
    ///
    /// The layout metrics, box, wrap and alignment are the caller's, so an
    /// outline buffer is shaped exactly like the body it decorates and therefore
    /// breaks lines identically. `colour` lands on `Attrs` for the reason given
    /// in `prepare`.
    fn shape_buffer(
        &mut self,
        text: &str,
        size: f32,
        bx: &LayoutBox,
        align: TextAlign,
        colour: [u8; 3],
        alpha: u8,
    ) -> usize {
        let family = self.font_family.clone();
        let mut buffer = Buffer::new(
            &mut self.font_system,
            Metrics::new(size, size * LINE_HEIGHT_FACTOR),
        );
        buffer.set_size(Some(bx.width), Some(bx.height));
        buffer.set_wrap(Wrap::WordOrGlyph);
        let attrs = Attrs::new()
            .family(Family::Name(&family))
            .color(Color::rgba(colour[0], colour[1], colour[2], alpha));
        buffer.set_text(text, &attrs, Shaping::Advanced, Some(align.to_cosmic()));
        buffer.shape_until_scroll(&mut self.font_system, false);
        self.buffers.push(buffer);
        self.buffers.len() - 1
    }

    /// Shape and upload every item, and remember them for `Self::render`.
    ///
    /// Call before opening the render pass (it only writes to the queue and the
    /// glyph atlas), then `Self::render` inside the pass. Splitting the two is
    /// what lets sprites and text share one pass.
    pub fn prepare(
        &mut self,
        device: &Device,
        queue: &Queue,
        items: &[TextItem],
    ) -> Result<TextStats, TextError> {
        let font_id = self.font_id.ok_or(TextError::NoFont)?;
        let fallback_ids = self.fallback_ids.clone();
        let family = self.font_family.clone();
        self.buffers.clear();
        self.placed.clear();
        self.stats = TextStats::default();

        for item in items {
            let Some(bx) = layout_box(item.rect, self.screen) else {
                continue;
            };
            let size = if item.size_px.is_finite() {
                item.size_px.clamp(MIN_SIZE_PX, MAX_SIZE_PX)
            } else {
                MIN_SIZE_PX
            };
            let alpha = if item.alpha.is_finite() {
                (item.alpha.clamp(0.0, 1.0) * 255.0).round() as u8
            } else {
                255
            };
            if alpha == 0 || item.text.is_empty() {
                continue;
            }

            let mut buffer = Buffer::new(
                &mut self.font_system,
                Metrics::new(size, size * LINE_HEIGHT_FACTOR),
            );
            buffer.set_size(Some(bx.width), Some(bx.height));
            // CJK has no spaces, so word wrapping alone would overflow the box;
            // WordOrGlyph breaks inside a word only when it has to.
            buffer.set_wrap(Wrap::WordOrGlyph);
            // WHY the colour *and the opacity* ride on `Attrs` and not on
            // `TextArea::default_color`: glyphon resolves a glyph's colour as
            // `glyph.color_opt.unwrap_or(area.default_color)`, and cosmic-text
            // copies `Attrs::color` into every `LayoutGlyph`, so a per-glyph value
            // always wins -- alpha channel included. `Attrs` is therefore the only
            // place a body colour can come from, and (for the same reason) the
            // only place the picture's opacity can come from.
            //
            // WHY straight alpha rather than premultiplied: glyphon's pipeline is
            // `BlendState::ALPHA_BLENDING` (SrcAlpha / OneMinusSrcAlpha) and its
            // shader emits `vec4(color.rgb, color.a * mask)`, i.e. the fixed
            // function multiplies by src alpha. That is exactly the contract
            // `crate::SpriteInstance::tint` uses, so a faded glyph composites
            // identically to a faded sprite and no premultiplication happens on
            // either path.
            let attrs = Attrs::new()
                .family(Family::Name(&family))
                .color(Color::rgba(
                    item.colour[0],
                    item.colour[1],
                    item.colour[2],
                    alpha,
                ));
            buffer.set_text(
                &item.text,
                &attrs,
                Shaping::Advanced,
                Some(item.align.to_cosmic()),
            );
            buffer.shape_until_scroll(&mut self.font_system, false);

            // The text that actually ended up shaped. The outline buffer has to
            // reuse it, otherwise the two passes would break lines differently.
            let mut shaped: Cow<'_, str> = Cow::Borrowed(item.text.as_str());
            let mut missing = missing_chars(&buffer, font_id, &fallback_ids);
            if !missing.is_empty() {
                let (rewritten, replaced) = substitute_missing(&item.text, &missing);
                buffer.set_text(
                    &rewritten,
                    &attrs,
                    Shaping::Advanced,
                    Some(item.align.to_cosmic()),
                );
                buffer.shape_until_scroll(&mut self.font_system, false);
                missing.retain(|ch| !self.stats.missing.contains(ch));
                self.stats.missing.append(&mut missing);
                self.stats.substituted += replaced;
                shaped = Cow::Owned(rewritten);
            }

            for run in buffer.layout_runs() {
                self.stats.lines += 1;
                self.stats.glyphs += run.glyphs.len();
            }
            self.stats.items += 1;
            self.buffers.push(buffer);
            let body = self.buffers.len() - 1;

            // Outline: four copies of the *same* shaped text at ring offsets,
            // queued before the body. Reusing one buffer is what keeps this
            // cheap: glyphon's glyph cache key is (glyph id, subpixel bins, size)
            // and deliberately excludes colour, so the copies hit the very same
            // atlas entries and cost one extra shaping pass, not four extra
            // rasterisations.
            if let Some(outline) = item.outline {
                // The ring fades with the body: a 50% picture whose outline stayed
                // opaque would grow a bright halo exactly where the glyphs vanish.
                let index =
                    self.shape_buffer(&shaped, size, &bx, item.align, outline.colour, alpha);
                let pad = i32::from(outline.width_px);
                let clip = expand_clip(bx.clip, pad, self.screen);
                let w = f32::from(outline.width_px);
                for (dx, dy) in [(w, 0.0), (-w, 0.0), (0.0, w), (0.0, -w)] {
                    self.placed.push(Placed {
                        buffer: index,
                        left: bx.left + dx,
                        top: bx.top + dy,
                        clip,
                        alpha,
                    });
                }
                self.stats.outlines += 4;
            }
            self.placed.push(Placed {
                buffer: body,
                left: bx.left,
                top: bx.top,
                clip: bx.clip,
                alpha,
            });
        }

        if self.placed.is_empty() {
            return Ok(self.stats.clone());
        }

        // One area per placed entry, in push order. glyphon emits its glyph quads
        // in exactly this order and draws them all in a single call, so "the
        // outline entries were pushed first" is precisely what puts the outline
        // underneath the body instead of on top of it.
        let areas: Vec<TextArea<'_>> = self
            .placed
            .iter()
            .map(|placed| TextArea {
                buffer: &self.buffers[placed.buffer],
                left: placed.left,
                top: placed.top,
                scale: 1.0,
                bounds: TextBounds {
                    left: placed.clip[0],
                    top: placed.clip[1],
                    right: placed.clip[2],
                    bottom: placed.clip[3],
                },
                // Dead in practice: every glyph carries its own colour from
                // `Attrs` (see the note in `prepare`), so glyphon never falls back
                // to this value. It is kept alpha-matched anyway so that a future
                // glyphon that honours it cannot silently make the text opaque.
                default_color: Color::rgba(255, 255, 255, placed.alpha),
                custom_glyphs: &[],
            })
            .collect();

        self.glyphs
            .prepare(
                device,
                queue,
                &mut self.font_system,
                &mut self.atlas,
                &self.viewport,
                areas,
                &mut self.swash,
            )
            .map_err(|err| TextError::Prepare(format!("{err}")))?;

        Ok(self.stats.clone())
    }

    /// Encode the prepared glyphs into an already-open render pass.
    ///
    /// Must share the pass with the sprite batch: whichever pass runs first owns
    /// the load/clear, and a second pass would clear the sprites away.
    pub fn render<'pass>(&'pass self, pass: &mut RenderPass<'pass>) -> Result<(), TextError> {
        if self.placed.is_empty() {
            return Ok(());
        }
        self.glyphs
            .render(&self.atlas, &self.viewport, pass)
            .map_err(|err| TextError::Render(format!("{err}")))
    }

    /// Statistics from the last `Self::prepare`.
    #[must_use]
    pub const fn stats(&self) -> &TextStats {
        &self.stats
    }

    /// Release glyphs the atlas no longer needs.
    ///
    /// WHY it is not called per frame: trimming walks every cached glyph, so a
    /// 0.5 s cadence keeps the atlas from growing under font-size churn without
    /// paying for it on every frame.
    pub fn trim(&mut self) {
        let _ = &self.cache;
        self.atlas.trim();
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    /// WOLF ships text pictures with a 1x1 rect (it computes its own box from the
    /// strings), so the only layout decision the renderer gets to make is "grow to
    /// the canvas edge". Picture 12501 of CommonEvent 94 is the real case:
    /// (715,115) 1x1 on 1024x576 must become a 309x461 box.
    #[test]
    fn a_unit_rect_grows_to_the_canvas_edge() {
        let bx = layout_box([715.0, 115.0, 1.0, 1.0], [1024, 576]).expect("on screen");
        assert_eq!(bx.left, 715.0);
        assert_eq!(bx.top, 115.0);
        assert_eq!(bx.width, 309.0);
        assert_eq!(bx.height, 461.0);
        assert_eq!(bx.clip, [715, 115, 1024, 576]);
    }

    #[test]
    fn an_explicit_rect_is_used_verbatim_and_rounded() {
        let bx = layout_box([44.4, 90.6, 512.0, 400.0], [1024, 576]).expect("on screen");
        assert_eq!((bx.left, bx.top), (44.0, 91.0));
        assert_eq!((bx.width, bx.height), (512.0, 400.0));
        assert_eq!(bx.clip, [44, 91, 556, 491]);
    }

    /// Negative WOLF coordinates happen (pictures slide in from off-screen). The
    /// clip is what keeps glyphon's integer scissor in agreement with the layout.
    #[test]
    fn a_partly_offscreen_box_is_clipped_not_moved() {
        let bx = layout_box([-20.0, -10.0, 100.0, 100.0], [1024, 576]).expect("partly visible");
        assert_eq!((bx.left, bx.top), (-20.0, -10.0));
        assert_eq!(bx.clip, [0, 0, 80, 90]);
    }

    #[test]
    fn entirely_offscreen_or_degenerate_boxes_are_dropped() {
        assert!(layout_box([2000.0, 10.0, 100.0, 100.0], [1024, 576]).is_none());
        assert!(layout_box([10.0, 700.0, 100.0, 100.0], [1024, 576]).is_none());
        assert!(layout_box([f32::NAN, 10.0, 100.0, 100.0], [1024, 576]).is_none());
        assert!(layout_box([10.0, 10.0, f32::INFINITY, 100.0], [1024, 576]).is_none());
        assert!(layout_box([10.0, 10.0, 100.0, 100.0], [0, 576]).is_none());
    }

    /// A zero rect is a *request* for the canvas edge, not an empty box, so it must
    /// never collapse to nothing -- otherwise pictures would silently vanish.
    #[test]
    fn a_zero_size_rect_still_yields_at_least_one_pixel() {
        let bx = layout_box([1000.0, 500.0, 0.0, 0.0], [1024, 576]).expect("on screen");
        assert_eq!((bx.width, bx.height), (24.0, 76.0));
        assert!(layout_box([1.0e6, 1.0e6, 0.0, 0.0], [1024, 576]).is_none());
    }

    #[test]
    fn substitution_replaces_every_occurrence_and_counts_it() {
        // The CN DLC notice really does repeat a missing character: 栏 appears in
        // "存档的第一栏" and again in "第一栏已有存档数据时".
        let text = "第一栏已有存档数据时，请先读取该存档。";
        let (out, replaced) = substitute_missing(text, &['栏', '读']);
        assert_eq!(replaced, 2);
        assert_eq!(out, "第一�已有存档数据时，请先�取该存档。");
        assert!(!out.contains('栏') && !out.contains('读'));
    }

    #[test]
    fn substitution_is_the_identity_when_nothing_is_missing() {
        let (out, replaced) = substitute_missing("はじめから", &[]);
        assert_eq!(replaced, 0);
        assert_eq!(out, "はじめから");
    }

    /// Read a Windows system font by file name, or `None` on a machine without it.
    fn windows_font(name: &str) -> Option<Vec<u8>> {
        let dir = std::env::var_os("WINDIR")
            .map(std::path::PathBuf::from)
            .unwrap_or_else(|| std::path::PathBuf::from("C:/Windows"))
            .join("Fonts");
        std::fs::read(dir.join(name)).ok().filter(|b| !b.is_empty())
    }

    /// The CN UI face has no U+25B6 (the night-menu cursor). A named symbol fallback
    /// must make it drawable, and the missing-glyph accounting must treat that face
    /// as covered rather than substituting a replacement character.
    #[test]
    fn a_named_fallback_covers_a_glyph_the_primary_lacks() {
        let (Some(primary), Some(fallback)) =
            (windows_font("msyhbd.ttc"), windows_font("seguisym.ttf"))
        else {
            eprintln!("skipping fallback test: Microsoft YaHei / Segoe UI Symbol missing");
            return;
        };
        assert_eq!(
            missing_glyphs(&primary, "▶", 20.0),
            vec!['▶'],
            "the primary face unexpectedly covers the choice cursor"
        );
        let Ok((mut system, font_id, family, fallback_ids)) =
            build_font_system_with(&primary, &[&fallback])
        else {
            panic!("both system fonts parsed for missing_glyphs but not for the fallback builder");
        };
        assert!(
            !fallback_ids.is_empty(),
            "the fallback face was not registered"
        );
        let size = 20.0_f32;
        let mut buffer = Buffer::new(&mut system, Metrics::new(size, size * LINE_HEIGHT_FACTOR));
        let attrs = Attrs::new()
            .family(Family::Name(&family))
            .color(Color::rgb(255, 255, 255));
        buffer.set_text("▶", &attrs, Shaping::Advanced, Some(Align::Left));
        buffer.shape_until_scroll(&mut system, false);
        assert!(
            missing_chars(&buffer, font_id, &fallback_ids).is_empty(),
            "cosmic-text did not borrow the named fallback for U+25B6"
        );
    }

    /// Garbage font bytes must be an error, never a panic: the game has to keep
    /// running (with blank pictures) if the player's Data/ is damaged.
    #[test]
    fn empty_font_bytes_are_rejected() {
        assert!(matches!(missing_glyphs(&[], "a", 12.0), v if v.is_empty()));
        let system = build_font_system(&[]);
        assert!(matches!(system, Err(TextError::EmptyFont)));
        let system = build_font_system(&[0_u8; 64]);
        assert!(matches!(system, Err(TextError::FontRejected)));
    }

    /// Size is clamped so a broken picture record cannot ask the shaper for a
    /// 0-pixel or 100k-pixel font (cosmic-text asserts on the former).
    #[test]
    fn font_sizes_are_clamped_into_the_supported_window() {
        assert_eq!(MIN_SIZE_PX.clamp(MIN_SIZE_PX, MAX_SIZE_PX), MIN_SIZE_PX);
        assert_eq!(0.0_f32.clamp(MIN_SIZE_PX, MAX_SIZE_PX), MIN_SIZE_PX);
        assert_eq!(1.0e9_f32.clamp(MIN_SIZE_PX, MAX_SIZE_PX), MAX_SIZE_PX);
    }

    // -- colour (`\c[n]`) and outline (`\E`) -------------------------------

    /// Every existing call site builds items through `new`, so the defaults are
    /// what keep the pre-colour captures bit-identical: white body, no ring.
    #[test]
    fn an_unstyled_item_is_white_without_an_outline() {
        let item = TextItem::new("めにゅー", [0.0, 0.0, 100.0, 20.0], 16.0);
        assert_eq!(item.colour, [255, 255, 255]);
        assert_eq!(item.outline, None);
    }

    /// WOLF's `\E` width is a plain number that can legitimately be 0, so the
    /// builder normalises it instead of every call site branching.
    #[test]
    fn a_zero_width_outline_means_no_outline() {
        let plain = TextItem::new("x", [0.0, 0.0, 100.0, 20.0], 16.0).with_outline(0, [1, 2, 3]);
        assert_eq!(plain.outline, None);
        let ringed = TextItem::new("x", [0.0, 0.0, 100.0, 20.0], 16.0).with_outline(2, [1, 2, 3]);
        assert_eq!(
            ringed.outline,
            Some(Outline {
                width_px: 2,
                colour: [1, 2, 3]
            })
        );
    }

    /// The ring has to be allowed to spill outside the body's box, but glyphon
    /// validates the integer scissor against the viewport, so an unclamped grow
    /// would abort the frame instead of merely being clipped.
    #[test]
    fn outline_clip_grows_but_stays_inside_the_canvas() {
        assert_eq!(
            expand_clip([10, 10, 20, 20], 3, [1024, 576]),
            [7, 7, 23, 23]
        );
        assert_eq!(expand_clip([0, 0, 5, 5], 3, [1024, 576]), [0, 0, 8, 8]);
        assert_eq!(
            expand_clip([1020, 570, 1024, 576], 3, [1024, 576]),
            [1017, 567, 1024, 576]
        );
        assert_eq!(
            expand_clip([10, 10, 20, 20], 0, [1024, 576]),
            [10, 10, 20, 20]
        );
    }

    /// The game's own font, if this checkout sits next to the data root.
    fn test_font() -> Option<Vec<u8>> {
        let root = std::path::Path::new(env!("CARGO_MANIFEST_DIR"))
            .join("..")
            .join("..");
        let mut candidates: Vec<std::path::PathBuf> = Vec::new();
        if let Some(dir) = std::env::var_os("WOLF_GAME_DIR") {
            candidates.push(std::path::PathBuf::from(dir).join("Lolita.ttf"));
        }
        for base in ["work/full", "work/alldata", "work/full/Data"] {
            candidates.push(root.join(base).join("Fonts").join("Lolita.ttf"));
        }
        candidates.push(std::path::PathBuf::from(
            "E:/SteamLibrary/steamapps/common/Living With SIster Monochrome Fantasy/Lolita.ttf",
        ));
        for path in candidates {
            match std::fs::read(&path) {
                Ok(bytes) if !bytes.is_empty() => return Some(bytes),
                _ => {}
            }
        }
        eprintln!("skipping GPU text test: no Lolita.ttf found");
        None
    }

    /// Offscreen renderer with the game font, or `None` when the machine has
    /// neither a GPU adapter nor the font -- a missing GPU must not fail the
    /// suite (same posture as `crates/wolf-render/tests/offscreen.rs`).
    fn offscreen() -> Option<crate::Renderer> {
        let font = test_font()?;
        let mut renderer = match crate::Renderer::new_offscreen() {
            Ok(renderer) => renderer,
            Err(err) => {
                eprintln!("skipping GPU text test: {err}");
                return None;
            }
        };
        if let Err(err) = renderer.set_font(&font) {
            eprintln!("skipping GPU text test: font rejected: {err}");
            return None;
        }
        Some(renderer)
    }

    fn count_pixels(pixels: &[u8], want: impl Fn([u8; 4]) -> bool) -> usize {
        pixels
            .chunks_exact(4)
            .filter(|c| want([c[0], c[1], c[2], c[3]]))
            .count()
    }

    /// Lit = anything the frame did not leave black, which is the clear colour.
    fn lit(pixels: &[u8]) -> usize {
        count_pixels(pixels, |p| p[0] | p[1] | p[2] != 0)
    }

    const BODY_RECT: [f32; 4] = [40.0, 40.0, 400.0, 200.0];

    /// The whole point of the field: two items that differ only in `colour` must
    /// land on different pixels, and the coloured one must actually be red where
    /// the white one is white. ("M" has vertical stems, so it has glyph pixels at
    /// full coverage no matter how the hinting rounds.)
    #[test]
    fn body_colour_reaches_the_framebuffer() {
        let Some(mut renderer) = offscreen() else {
            return;
        };
        renderer.draw_text(&[TextItem::new("M", BODY_RECT, 96.0)]);
        renderer.present();
        let white = renderer.capture_rgba().expect("offscreen capture");
        renderer.draw_text(&[TextItem::new("M", BODY_RECT, 96.0).with_colour([255, 0, 0])]);
        renderer.present();
        let red = renderer.capture_rgba().expect("offscreen capture");

        let differing = white
            .chunks_exact(4)
            .zip(red.chunks_exact(4))
            .filter(|(a, b)| a != b)
            .count();
        let solid_red = count_pixels(&red, |p| p == [255, 0, 0, 255]);
        let solid_white = count_pixels(&white, |p| p == [255, 255, 255, 255]);
        assert!(
            differing > 100,
            "colour never reached the framebuffer: {differing} pixels differ"
        );
        assert_eq!(
            solid_red, solid_white,
            "red body should cover the same area"
        );
        assert!(solid_red > 10, "no fully covered glyph pixels: {solid_red}");
    }

    /// `\E` must add coverage outside the glyphs and must not disturb the body
    /// counters. Four offsets, one extra shaped buffer, same atlas entries.
    #[test]
    fn an_outline_adds_a_ring_the_body_does_not_cover() {
        let Some(mut renderer) = offscreen() else {
            return;
        };
        let plain = TextItem::new("M", BODY_RECT, 96.0);
        renderer.draw_text(std::slice::from_ref(&plain));
        renderer.present();
        let bare = renderer.capture_rgba().expect("offscreen capture");
        let bare_stats = renderer.text_stats().clone();

        renderer.draw_text(&[plain.with_outline(3, [0, 255, 0])]);
        renderer.present();
        let ringed = renderer.capture_rgba().expect("offscreen capture");
        let ringed_stats = renderer.text_stats().clone();

        let (bare_lit, ringed_lit) = (lit(&bare), lit(&ringed));
        // Pure green can only come from the outline: the body is white, so every
        // pixel the two share is mixed, and every outline-only pixel is (0, g, 0).
        let ring_only = count_pixels(&ringed, |p| p[0] == 0 && p[2] == 0 && p[1] > 0);
        let bare_green = count_pixels(&bare, |p| p[0] == 0 && p[2] == 0 && p[1] > 0);

        assert_eq!(bare_stats.outlines, 0);
        assert_eq!(ringed_stats.outlines, 4, "four ring offsets per item");
        assert_eq!(ringed_stats.items, bare_stats.items);
        assert_eq!(
            ringed_stats.glyphs, bare_stats.glyphs,
            "outline quads are shaped separately and must not inflate body counts"
        );
        assert_eq!(bare_green, 0);
        assert!(
            ring_only > 100,
            "the ring never reached the frame: {ring_only}"
        );
        assert!(
            ringed_lit > bare_lit,
            "outline must add coverage: {ringed_lit} vs {bare_lit}"
        );
    }

    /// Peak of one channel over the whole frame, on a black clear.
    fn peak_channel(pixels: &[u8]) -> u8 {
        pixels
            .chunks_exact(4)
            .flat_map(|c| [c[0], c[1], c[2]])
            .max()
            .unwrap_or(0)
    }

    /// Draw `item` alone over the black clear and return (frame, peak channel).
    fn render_and_peak(renderer: &mut crate::Renderer, item: TextItem) -> (Vec<u8>, u8) {
        renderer.draw_text(std::slice::from_ref(&item));
        renderer.present();
        let frame = renderer.capture_rgba().expect("offscreen capture");
        let peak = peak_channel(&frame);
        (frame, peak)
    }

    /// The bug this task exists for: `with_alpha` used to be a no-op because the
    /// glyph colour was pinned at `Color::rgb` (alpha 255) on `Attrs`, and
    /// glyphon's per-glyph colour always wins over `TextArea::default_color`.
    /// A half-opacity white glyph over a black clear must therefore peak near
    /// 128, not 255.
    #[test]
    fn alpha_fades_the_glyphs() {
        let Some(mut renderer) = offscreen() else {
            return;
        };
        let (opaque, peak_opaque) =
            render_and_peak(&mut renderer, TextItem::new("M", BODY_RECT, 96.0));
        let (half, peak_half) = render_and_peak(
            &mut renderer,
            TextItem::new("M", BODY_RECT, 96.0).with_alpha(0.5),
        );

        assert_eq!(
            peak_opaque, 255,
            "an opaque white glyph should reach full white"
        );
        let delta = (i32::from(peak_half) - 128).abs();
        assert!(
            delta <= 3,
            "half-opacity glyph peaked at {peak_half}, expected ~128 (+/-3)"
        );
        // And the fade must be uniform, not a handful of pixels: the lit area
        // stays essentially the same, only its brightness halves. It is not
        // bit-identical because an anti-aliased edge pixel at coverage c drops
        // from round(255*c) to round(127.5*c) and the faintest ones round to 0.
        let (lit_opaque, lit_half) = (lit(&opaque), lit(&half));
        let drift = lit_opaque.abs_diff(lit_half);
        assert!(
            drift * 100 <= lit_opaque * 2,
            "alpha changed glyph coverage by {drift} px ({lit_opaque} -> {lit_half})"
        );
        assert!(lit_half > 100, "no glyph coverage to fade: {lit_half}");
    }

    /// Peak of the green channel over pixels that only the ring can have painted
    /// (pure green: the white body always lights red and blue as well).
    fn green_only(pixels: &[u8]) -> (usize, u8) {
        let mut count = 0;
        let mut peak = 0;
        for c in pixels.chunks_exact(4) {
            if c[0] == 0 && c[2] == 0 && c[1] > 0 {
                count += 1;
                peak = peak.max(c[1]);
            }
        }
        (count, peak)
    }

    /// An outlined item has to fade as a whole: the ring shares the body's
    /// opacity, otherwise a fading picture grows a bright halo as its glyphs
    /// disappear.
    ///
    /// WHY the ring's peak is bounded from above instead of being pinned at 128:
    /// glyphon stamps the ring as four offset copies of the same glyph, so where
    /// two copies overlap their alphas compose (0.5 then 0.5*(1-0.5) = 0.75) and
    /// such a pixel lands at 191 rather than 128. What must not happen is a
    /// single copy staying at 255 -- that would mean the ring never faded.
    #[test]
    fn alpha_fades_the_outline_too() {
        let Some(mut renderer) = offscreen() else {
            return;
        };
        let ringed = TextItem::new("M", BODY_RECT, 96.0).with_outline(3, [0, 255, 0]);
        let (opaque, _) = render_and_peak(&mut renderer, ringed.clone());
        let (half, _) = render_and_peak(&mut renderer, ringed.with_alpha(0.5));

        let (opaque_ring, opaque_peak) = green_only(&opaque);
        let (half_ring, half_peak) = green_only(&half);
        assert!(opaque_ring > 100, "no ring pixels at all: {opaque_ring}");
        assert_eq!(opaque_peak, 255, "an opaque ring must reach full green");
        assert!(
            half_peak >= 120,
            "ring faded more than the body did: peak {half_peak}"
        );
        // The ceiling is the four-fold overlap case, not 128: 1 - (1 - 0.5)^4 =
        // 0.9375 -> 239. Anything at 255 means at least one copy kept the
        // picture's opacity.
        assert!(
            half_peak < 255,
            "some ring copy stayed fully opaque: peak {half_peak}"
        );
        assert!(
            half_peak <= 240,
            "ring composited brighter than four half-alpha copies allow: {half_peak}"
        );
        assert!(
            half_ring > 100,
            "the ring vanished instead of fading: {half_ring} px"
        );
    }

    /// Zero alpha means "invisible", not "opaque": the item is skipped entirely
    /// and the frame stays black.
    #[test]
    fn zero_alpha_draws_nothing() {
        let Some(mut renderer) = offscreen() else {
            return;
        };
        let (frame, peak) = render_and_peak(
            &mut renderer,
            TextItem::new("M", BODY_RECT, 96.0).with_alpha(0.0),
        );
        assert_eq!(peak, 0, "alpha 0 must leave the frame black");
        assert_eq!(lit(&frame), 0);
        assert_eq!(
            renderer.text_stats().items,
            0,
            "the item is skipped, not drawn"
        );
    }

    /// A half-transparent item plus an outline is the nastiest combination the
    /// data layer can produce; the outline must still be visible and the body
    /// counters must stay body-only.
    #[test]
    fn an_outlined_item_keeps_its_alpha_path() {
        let Some(mut renderer) = offscreen() else {
            return;
        };
        renderer.draw_text(&[TextItem::new("M", BODY_RECT, 96.0)
            .with_alpha(0.5)
            .with_colour([200, 200, 200])
            .with_outline(2, [255, 0, 0])]);
        renderer.present();
        let frame = renderer.capture_rgba().expect("offscreen capture");
        let stats = renderer.text_stats().clone();
        assert_eq!(stats.items, 1);
        assert_eq!(stats.outlines, 4);
        assert!(
            count_pixels(&frame, |p| p[0] > 0 && p[1] == 0 && p[2] == 0) > 10,
            "red outline missing from the alpha path"
        );
    }
}
