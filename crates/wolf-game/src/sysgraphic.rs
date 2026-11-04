//! WOLF's built-in graphics: the `150` pictures whose "file name" is a drawing command.
//!
//! A `150 Picture` instruction normally names a file (`SystemGraphic/TitleGraphic.jpg`),
//! but it may instead name one of the editor's *system graphics*: primitives the runtime
//! synthesises on the fly instead of loading them from disk. docs/ASSET_AUDIT.md counted
//! 24 such `<...>` names in `CommonEvent.dat` and more in the map events, and separated
//! two very different things hiding behind the same spelling:
//!
//! * **drawing commands** - `<SQUARE>`, `<SQUARE><FRAME>`, `<LINE>`, `<CIRCLE>`,
//!   `<TRI-LEFT|RIGHT|UP|DOWN>`, `<GRADX-a-b>`, `<GRADY-a-b>` - this module;
//! * **text markup** - `<C>`, `<L>`, `<R>`, `<FRAME>` - not graphics at all; they
//!   are alignment and decoration codes inside a text picture, and `parse` deliberately
//!   rejects them so a caller cannot mistake one for a drawable shape.
//!
//! Every **solid** shape is drawn white and un-tinted. Colour comes from the picture's own
//! tone (`crate::picture::field::TONE_R` and friends, percent per channel), which is why the
//! retail title banner is a `<SQUARE>` multiplied by 222/255 rather than a grey bitmap
//! (docs/OPCODE_290.md section 3). Baking a colour in here would double-count that.
//!
//! The two gradient shapes are the exception: they are **black** shadows, not white fades.
//! A `<GRADY-779-111>` full-screen box is how the save/load, status and battle screens
//! darken the room behind them, and every one of the 38 gradient draws in this game leaves
//! the picture tone at neutral white - so a white bitmap would *lighten* the scene instead
//! of shadowing it. Retail evidence: in the reference save-screen shot the margin outside
//! the slot panels is neutral dark (42,42,46) while a white 0.78-alpha ramp over any
//! plausible room colour would sit above 190; a black ramp at the same alpha lands on the
//! measured value. The gradient therefore carries its own black colour.
//!
//! The output is a plain `ImageData`, so a generated shape travels the exact same path as a
//! decoded PNG: it goes into `crate::atlas::Atlas` under the key from `atlas_key`, gets
//! packed once, and from then on costs one sprite instance like any other picture.
//!
//! ## What this game actually uses
//!
//! Scanning every `150` in the 550 common events plus all map events (work/_probe_sysg.py)
//! finds 38 gradient, 33 square, 27 frame, 7 line, 3 circle and 3 triangle instructions; the
//! rest of the `<...>` names are text markup. Every shape below is therefore exercised by
//! real data except `<TRI-UP>`, which is implemented for completeness because other WOLF
//! games use it.

use crate::assets::ImageData;

/// Largest side a generated shape may have, in pixels.
///
/// The logical screen is 1024x576, so anything beyond a few thousand pixels cannot be
/// visible; the cap exists so a corrupt or hostile instruction cannot ask for a huge
/// buffer. It is 4096 - deliberately smaller than `crate::assets::MAX_DIMENSION` (16384),
/// because a shape is synthesised rather than decoded and one shape never legitimately
/// needs to be that large.
pub const MAX_SIDE: u32 = 4096;

/// Largest pixel count a generated shape may have (2 Mi pixels, 8 MiB of RGBA8).
///
/// A full-screen gradient is 589,824 pixels, so this leaves room for a shape several times
/// larger than the screen while still bounding the allocation. Both limits are checked
/// before a buffer is allocated, so a bogus box costs nothing.
pub const MAX_PIXELS: u32 = 2_097_152;

/// Thickness of the `<SQUARE><FRAME>` border, in pixels.
///
/// **Assumption, not a measurement.** WOLF's editor documents a single hollow-rectangle
/// command, and the 27 frame instructions in this game come in two spellings -
/// `<SQUARE><FRAME>` (11) and `<SQUARE>FRAME` (16, missing the inner `<>`, evidently a
/// typo the original engine tolerated) - which behave identically. One pixel is what the
/// editor draws in its own preview, and a 120x5 progress-bar frame with a 2-pixel border
/// would leave a 1-pixel hole, which nobody draws on purpose. Keeping this a constant
/// rather than a field of `Shape` lets a future measurement flip the border width in one
/// place; the two spellings are intentionally *not* distinguished.
pub const FRAME_THICKNESS: u32 = 1;

/// The per-mille value meaning "fully opaque" in a gradient command's parameters.
pub const ALPHA_OPAQUE: u32 = 1000;

/// The per-mille value meaning "fully transparent" in a gradient command's parameters.
pub const ALPHA_CLEAR: u32 = 0;

/// Which edge a `<TRI-*` triangle points at.
///
/// The name is the direction the **apex** points, not the edge the base sits on: the game
/// uses `<TRI-DOWN>` as the "page down" marker of a message window, which is a downward
/// arrow, so `TriDir::Down` has its apex on the bottom edge and its base along the top.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
pub enum TriDir {
    /// Apex on the left edge, base along the right edge.
    Left,
    /// Apex on the right edge, base along the left edge.
    Right,
    /// Apex on the top edge, base along the bottom edge.
    Up,
    /// Apex on the bottom edge, base along the top edge.
    Down,
}

/// One of the primitives WOLF draws instead of loading a file.
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
pub enum Shape {
    /// `<SQUARE>`: a solid white rectangle. Tint it with the picture tone to get a panel.
    Square,
    /// `<SQUARE><FRAME>` (also written `<SQUARE>FRAME`): a hollow rectangle of
    /// `FRAME_THICKNESS` pixels, transparent inside.
    SquareFrame,
    /// `<GRADX-a-b>`: white, at its most opaque on the left and fading towards the right.
    ///
    /// `from` and `to` are the alpha at the two edges in **per-mille** (0..=`ALPHA_OPAQUE`);
    /// see a note on the trailing numbers there. The geometry always comes from the picture's
    /// own box, never from the name.
    GradX {
        /// Alpha at the left edge, per-mille.
        from: u32,
        /// Alpha at the right edge, per-mille.
        to: u32,
    },
    /// `<GRADY-a-b>`: the same ramp, running from the top edge downwards.
    GradY {
        /// Alpha at the top edge, per-mille.
        from: u32,
        /// Alpha at the bottom edge, per-mille.
        to: u32,
    },
    /// `<LINE>`: a solid rule. See `render` for the degenerate-height rule.
    Line,
    /// `<CIRCLE>`: the ellipse inscribed in the picture's box.
    Circle,
    /// `<TRI-LEFT|RIGHT|UP|DOWN>`: an isosceles triangle pointing at one edge.
    Triangle(TriDir),
}

/// Splits a `<...>` command into upper-case tokens, dropping brackets, dashes and spaces.
///
/// `<SQUARE><FRAME>` becomes `["SQUARE", "FRAME"]`, `<GRADX-999-274>` becomes
/// `["GRADX", "999", "274"]`, and `<SQUARE>FRAME` becomes `["SQUARE", "FRAME"]` too -
/// exactly the tolerance the data needs.
fn tokens(name: &str) -> Vec<String> {
    name.trim()
        .trim_start_matches('<')
        .split(['<', '>', '-', ' ', '\t'])
        .filter(|part| !part.is_empty())
        .map(|part| part.to_ascii_uppercase())
        .collect()
}

/// Reads the two trailing numbers of a `<GRAD*-a-b>` command as per-mille endpoints.
///
/// Missing or unparsable numbers fall back to a full opaque-to-clear ramp, because that is
/// the only ramp a shape with no parameters can mean; a gradient that draws *something*
/// beats a picture that vanishes.
fn gradient_endpoints(parts: &[String]) -> (u32, u32) {
    let read = |index: usize, fallback: u32| {
        parts
            .get(index)
            .and_then(|part| part.parse::<u32>().ok())
            .unwrap_or(fallback)
            .min(ALPHA_OPAQUE)
    };
    (read(0, ALPHA_OPAQUE), read(1, ALPHA_CLEAR))
}

/// Recognises a built-in drawing command, or None when the name is a file or a text code.
///
/// Case-insensitive and whitespace-tolerant: the data really does contain `'<SQUARE> '`
/// with a trailing space (twice) and `'<SQUARE>FRAME'` without the second pair of brackets.
/// Returning None for `<C>`, `<L>`, `<R>` and a bare `<FRAME>` is deliberate - those
/// are text markup, and a caller that drew them would paint a meaningless blob.
#[must_use]
pub fn parse(name: &str) -> Option<Shape> {
    let parts = tokens(name);
    match parts.first()?.as_str() {
        "SQUARE" => match parts.get(1).map(String::as_str) {
            None => Some(Shape::Square),
            Some("FRAME") => Some(Shape::SquareFrame),
            Some(_) => None,
        },
        "GRADX" => {
            let (from, to) = gradient_endpoints(&parts[1..]);
            Some(Shape::GradX { from, to })
        }
        "GRADY" => {
            let (from, to) = gradient_endpoints(&parts[1..]);
            Some(Shape::GradY { from, to })
        }
        "LINE" => Some(Shape::Line),
        "CIRCLE" => Some(Shape::Circle),
        "TRI" => match parts.get(1).map(String::as_str) {
            Some("LEFT") => Some(Shape::Triangle(TriDir::Left)),
            Some("RIGHT") => Some(Shape::Triangle(TriDir::Right)),
            Some("UP") => Some(Shape::Triangle(TriDir::Up)),
            Some("DOWN") => Some(Shape::Triangle(TriDir::Down)),
            _ => None,
        },
        _ => None,
    }
}

/// True when a `150` name must be synthesised rather than loaded from disk.
#[must_use]
pub fn is_builtin(name: &str) -> bool {
    parse(name).is_some()
}

/// The canonical spelling of a shape, with its parameters when it has any.
#[must_use]
pub fn name(shape: Shape) -> String {
    match shape {
        Shape::Square => "<SQUARE>".to_owned(),
        Shape::SquareFrame => "<SQUARE><FRAME>".to_owned(),
        Shape::GradX { from, to } => format!("<GRADX-{from}-{to}>"),
        Shape::GradY { from, to } => format!("<GRADY-{from}-{to}>"),
        Shape::Line => "<LINE>".to_owned(),
        Shape::Circle => "<CIRCLE>".to_owned(),
        Shape::Triangle(TriDir::Left) => "<TRI-LEFT>".to_owned(),
        Shape::Triangle(TriDir::Right) => "<TRI-RIGHT>".to_owned(),
        Shape::Triangle(TriDir::Up) => "<TRI-UP>".to_owned(),
        Shape::Triangle(TriDir::Down) => "<TRI-DOWN>".to_owned(),
    }
}

/// A stable atlas key for a generated shape at a given size.
///
/// The key contains a colon, and `crate::assets` rejects every asset name containing one
/// (it could otherwise address a drive letter), so a generated shape can never collide
/// with a real file name - including the file name of a *text* picture, which starts with
/// `<` just like a command does. Including the size matters: `<SQUARE>` at 120x5 and at
/// 800x500 are two different bitmaps and must not share a slot, and the gradient endpoints
/// are part of the shape for the same reason.
#[must_use]
pub fn atlas_key(shape: Shape, w: u32, h: u32) -> String {
    format!("<sysgraphic:{}:{w}x{h}>", name(shape))
}

/// The pixel box a built-in shape is drawn at, decoded from a picture's window fields.
///
/// WOLF has nowhere else to keep it. A `150` command's window width and height (args 1
/// and 2) are the box for the window picture kinds, and every one of the 375 built-in
/// graphic instructions in this game fills them in - measured over work/wolftl/dump, the
/// smallest is a 9x9 `<TRI-DOWN>` and the largest a full-width `<SQUARE>` bar - so the
/// box, not a file size, is what says how big the drawing is.
///
/// The `-a-b` suffix of a `<GRAD*-a-b>` name is deliberately NOT used as a fallback
/// size: those two numbers are the gradient's own per-mille alpha endpoints, and 38 of 38
/// gradient instructions pass a box that has nothing to do with them
/// (`<GRADX-999-666>` fills 470x8). Reading them as a width and height would paint a
/// 999x666 fade where the script asked for a 470x8 one, and the `-000-444` spelling
/// would become a zero-wide picture that draws nothing at all.
///
/// A missing or non-positive box yields `None` - the caller then draws nothing, exactly as
/// it would for a missing file. A zero *height* is kept for `<LINE>`, the one shape this
/// game writes a zero extent for (all 7 instances), because a rule with no thickness is
/// still a one-pixel rule.
#[must_use]
pub fn box_size(shape: Shape, window: Option<(i32, i32)>) -> Option<(u32, u32)> {
    let (w, h) = window?;
    let w = u32::try_from(w).ok().filter(|w| *w > 0)?;
    let h = match h {
        h if h > 0 => u32::try_from(h).ok()?,
        _ if matches!(shape, Shape::Line) => 1,
        _ => return None,
    };
    Some((w, h))
}

/// Rounds a per-mille alpha down to a byte.
fn alpha_byte(per_mille: u32) -> u8 {
    let clamped = per_mille.min(ALPHA_OPAQUE);
    ((clamped * 255 + ALPHA_OPAQUE / 2) / ALPHA_OPAQUE) as u8
}

/// Linear ramp between two per-mille endpoints over `span` steps.
fn ramp(from: u32, to: u32, index: u32, span: u32) -> u8 {
    if span == 0 {
        return alpha_byte(from);
    }
    let delta = i64::from(to) - i64::from(from);
    let value = i64::from(from) + delta * i64::from(index) / i64::from(span);
    alpha_byte(value.clamp(0, i64::from(ALPHA_OPAQUE)) as u32)
}

/// Rejects sizes that are zero, absurd, or would allocate more than `MAX_PIXELS`.
fn checked_size(w: u32, h: u32) -> Option<usize> {
    if w == 0 || h == 0 || w > MAX_SIDE || h > MAX_SIDE {
        return None;
    }
    let pixels = w.checked_mul(h)?;
    if pixels > MAX_PIXELS {
        return None;
    }
    Some(pixels as usize)
}

/// Fills a `w`x`h` buffer by asking `shade` for every pixel's colour.
fn build(w: u32, h: u32, mut shade: impl FnMut(u32, u32) -> [u8; 4]) -> Option<ImageData> {
    let pixels = checked_size(w, h)?;
    let mut rgba = Vec::with_capacity(pixels * 4);
    for y in 0..h {
        for x in 0..w {
            rgba.extend_from_slice(&shade(x, y));
        }
    }
    ImageData::new(w, h, rgba)
}

/// Is the pixel inside the triangle pointing in `dir`?
///
/// The test is one half-plane comparison per pixel rather than a scan conversion: at
/// column x the triangle's half-height grows linearly from the apex, so a pixel is inside
/// when it lies within that band. Sampling at pixel centres keeps the apex and the base
/// row symmetric, which is what makes a 9x9 `<TRI-DOWN>` look like an arrow instead of a
/// lopsided wedge.
fn triangle_covers(dir: TriDir, x: u32, y: u32, w: u32, h: u32) -> bool {
    let px = x as f32 + 0.5;
    let py = y as f32 + 0.5;
    let cw = w as f32;
    let ch = h as f32;
    match dir {
        TriDir::Left => (py - ch * 0.5).abs() <= ch * 0.5 * (px / cw),
        TriDir::Right => (py - ch * 0.5).abs() <= ch * 0.5 * ((cw - px) / cw),
        // Apex at the bottom edge: the base spans the whole top row and the band
        // narrows downwards, so the band shrinks as py grows.
        TriDir::Down => (px - cw * 0.5).abs() <= cw * 0.5 * ((ch - py) / ch),
        TriDir::Up => (px - cw * 0.5).abs() <= cw * 0.5 * (py / ch),
    }
}

/// Is the pixel inside the ellipse inscribed in the box?
fn ellipse_covers(x: u32, y: u32, w: u32, h: u32) -> bool {
    let nx = (x as f32 + 0.5) / w as f32 * 2.0 - 1.0;
    let ny = (y as f32 + 0.5) / h as f32 * 2.0 - 1.0;
    nx * nx + ny * ny <= 1.0
}

/// Synthesises the pixels of one built-in shape at a given size.
///
/// Returns None for a zero-sized box, for a box larger than `MAX_SIDE` or `MAX_PIXELS`,
/// and for a shape whose parameters make no sense - so the caller draws nothing, exactly
/// as it would for a missing file, instead of panicking.
///
/// `<LINE>` is the one shape that tolerates a zero extent: the game writes `h = 0` for
/// every one of its 7 line instructions (the height comes from a self-variable that
/// evaluates to 0), and a rule with no thickness is still a one-pixel rule. A zero
/// *width* is still refused, because a zero-length line draws nothing.
#[must_use]
pub fn render(shape: Shape, w: u32, h: u32) -> Option<ImageData> {
    match shape {
        Shape::Square => build(w, h, |_, _| [255, 255, 255, 255]),
        Shape::SquareFrame => {
            // A border thicker than half the box would leave no hole at all, so clamp it:
            // a 2x2 frame is all border, and that is the only sensible reading.
            let t = FRAME_THICKNESS
                .min(w.div_ceil(2).max(1))
                .min(h.div_ceil(2).max(1))
                .max(1);
            build(w, h, move |x, y| {
                if x < t || y < t || x + t >= w || y + t >= h {
                    [255, 255, 255, 255]
                } else {
                    [255, 255, 255, 0]
                }
            })
        }
        Shape::GradX { from, to } => {
            let span = w.saturating_sub(1);
            build(w, h, move |x, _| [0, 0, 0, ramp(from, to, x, span)])
        }
        Shape::GradY { from, to } => {
            let span = h.saturating_sub(1);
            build(w, h, move |_, y| [0, 0, 0, ramp(from, to, y, span)])
        }
        Shape::Line if w == 0 => None,
        Shape::Line => build(w, h.max(1), |_, _| [255, 255, 255, 255]),
        Shape::Circle => build(w, h, |x, y| {
            if ellipse_covers(x, y, w, h) {
                [255, 255, 255, 255]
            } else {
                [255, 255, 255, 0]
            }
        }),
        Shape::Triangle(dir) => build(w, h, |x, y| {
            if triangle_covers(dir, x, y, w, h) {
                [255, 255, 255, 255]
            } else {
                [255, 255, 255, 0]
            }
        }),
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::assets::AssetError;

    fn alpha_at(image: &ImageData, x: u32, y: u32) -> u8 {
        image.pixel(x, y).expect("pixel in bounds")[3]
    }

    fn assert_opaque_white(image: &ImageData) {
        for (index, chunk) in image.rgba.chunks_exact(4).enumerate() {
            assert_eq!(
                chunk,
                [255, 255, 255, 255],
                "pixel {index} is not opaque white"
            );
        }
    }

    #[test]
    fn parses_every_spelling_the_game_uses() {
        assert_eq!(parse("<SQUARE>"), Some(Shape::Square));
        assert_eq!(parse("<SQUARE><FRAME>"), Some(Shape::SquareFrame));
        // 16 uses in the data are missing the inner bracket pair; WOLF tolerated it.
        assert_eq!(parse("<SQUARE>FRAME"), Some(Shape::SquareFrame));
        // Two uses carry a trailing space.
        assert_eq!(parse("<SQUARE> "), Some(Shape::Square));
        assert_eq!(parse("<LINE>"), Some(Shape::Line));
        assert_eq!(parse("<CIRCLE>"), Some(Shape::Circle));
        assert_eq!(parse("<TRI-LEFT>"), Some(Shape::Triangle(TriDir::Left)));
        assert_eq!(parse("<TRI-RIGHT>"), Some(Shape::Triangle(TriDir::Right)));
        assert_eq!(parse("<TRI-DOWN>"), Some(Shape::Triangle(TriDir::Down)));
        assert_eq!(parse("<TRI-UP>"), Some(Shape::Triangle(TriDir::Up)));
        // Case-insensitive: nothing here depends on it, but the editor never normalises
        // what a user types either.
        assert_eq!(parse("<square>"), Some(Shape::Square));
        assert_eq!(parse(" <Square><Frame> "), Some(Shape::SquareFrame));
    }

    #[test]
    fn parses_gradients_with_their_endpoints() {
        assert_eq!(
            parse("<GRADX>"),
            Some(Shape::GradX {
                from: ALPHA_OPAQUE,
                to: ALPHA_CLEAR
            })
        );
        assert_eq!(
            parse("<GRADX-999-274>"),
            Some(Shape::GradX { from: 999, to: 274 })
        );
        assert_eq!(
            parse("<GRADY-000-444>"),
            Some(Shape::GradY { from: 0, to: 444 })
        );
        // Unparsable parameters degrade to the default ramp rather than the whole command
        // failing, because a shape that draws something beats a picture that vanishes.
        assert_eq!(
            parse("<GRADX-abc-def>"),
            Some(Shape::GradX {
                from: ALPHA_OPAQUE,
                to: ALPHA_CLEAR
            })
        );
    }

    #[test]
    fn text_markup_is_not_a_shape() {
        assert_eq!(parse("<C>"), None);
        assert_eq!(parse("<L>"), None);
        assert_eq!(parse("<R>"), None);
        assert_eq!(parse("<FRAME>"), None);
        assert_eq!(parse("<SQUARE>EXTRA"), None);
        assert_eq!(parse("<TRI-SIDEWAYS>"), None);
        assert_eq!(parse("SystemGraphic/TitleGraphic.jpg"), None);
        assert_eq!(parse(""), None);
        assert_eq!(parse("   "), None);
        assert!(!is_builtin("<C>"));
        assert!(is_builtin("<SQUARE>"));
    }

    #[test]
    fn square_is_opaque_white() {
        let image = render(Shape::Square, 120, 5).expect("square");
        assert_eq!(image.size(), (120, 5));
        assert_opaque_white(&image);
    }

    #[test]
    fn square_frame_is_hollow() {
        // The game's real frame: 120x5 at (320, 342) on SampleMapA.
        let image = render(Shape::SquareFrame, 120, 5).expect("frame");
        assert_eq!(image.size(), (120, 5));
        for (x, y) in [(0, 0), (119, 0), (0, 4), (119, 4), (0, 2), (119, 2)] {
            assert_eq!(alpha_at(&image, x, y), 255, "border at ({x}, {y})");
            assert_eq!(image.pixel(x, y).expect("border"), [255, 255, 255, 255]);
        }
        // The middle is a hole: a 120x5 frame has a 118x3 interior.
        for (x, y) in [(60, 2), (1, 1), (118, 3), (60, 1)] {
            assert_eq!(alpha_at(&image, x, y), 0, "interior at ({x}, {y})");
        }
    }

    #[test]
    fn a_frame_thinner_than_its_border_is_all_border() {
        assert_opaque_white(&render(Shape::SquareFrame, 1, 1).expect("1x1 frame"));
        assert_opaque_white(&render(Shape::SquareFrame, 2, 2).expect("2x2 frame"));
    }

    #[test]
    fn gradx_runs_from_opaque_to_transparent() {
        let image = render(
            Shape::GradX {
                from: ALPHA_OPAQUE,
                to: ALPHA_CLEAR,
            },
            800,
            500,
        )
        .expect("gradient");
        assert_eq!(image.size(), (800, 500));
        assert_eq!(alpha_at(&image, 0, 0), 255);
        assert_eq!(alpha_at(&image, 799, 499), 0);
        // Every row of a horizontal ramp ramps the same way, and the RGB stays black: a
        // gradient is a shadow, so its own colour is the one that has to darken the scene.
        assert_eq!(alpha_at(&image, 0, 250), 255);
        assert_eq!(alpha_at(&image, 799, 250), 0);
        assert_eq!(
            image.pixel(400, 250).expect("middle"),
            [0, 0, 0, alpha_at(&image, 400, 250)]
        );
        // A one-pixel-wide ramp has no room to interpolate: it takes the near endpoint.
        let thin = render(Shape::GradX { from: 500, to: 0 }, 1, 4).expect("thin gradient");
        assert_eq!(alpha_at(&thin, 0, 0), 128);
    }

    #[test]
    fn grady_runs_from_opaque_to_transparent() {
        let image = render(
            Shape::GradY {
                from: ALPHA_OPAQUE,
                to: ALPHA_CLEAR,
            },
            215,
            4,
        )
        .expect("gradient");
        assert_eq!(alpha_at(&image, 0, 0), 255);
        assert_eq!(alpha_at(&image, 214, 0), 255);
        assert_eq!(alpha_at(&image, 0, 3), 0);
        assert_eq!(alpha_at(&image, 214, 3), 0);
    }

    #[test]
    fn gradient_endpoints_scale_the_ramp() {
        // The two halves of a matched fade pair present in the data: <GRADX-444-000> sits
        // left of <GRADX-000-444> at 215x4, so one fades out where the other fades in.
        let out = parse("<GRADX-444-000>").expect("fade out");
        let image = render(out, 215, 4).expect("fade out image");
        assert_eq!(alpha_at(&image, 0, 0), 113); // 444 per-mille
        assert_eq!(alpha_at(&image, 214, 0), 0);

        let into = parse("<GRADX-000-444>").expect("fade in");
        let image = render(into, 215, 4).expect("fade in image");
        assert_eq!(alpha_at(&image, 0, 0), 0);
        assert_eq!(alpha_at(&image, 214, 0), 113);
    }

    #[test]
    fn line_with_zero_height_is_one_pixel() {
        // All 7 line instructions in the game pass a height of 0.
        let image = render(Shape::Line, 200, 0).expect("line with no thickness");
        assert_eq!(image.size(), (200, 1));
        assert_opaque_white(&image);
        let wide = render(Shape::Line, 200, 3).expect("thick line");
        assert_eq!(wide.size(), (200, 3));
        assert_opaque_white(&wide);
        // A zero-length rule still draws nothing.
        assert_eq!(render(Shape::Line, 0, 0), None);
    }

    #[test]
    fn circle_is_inscribed_in_its_box() {
        // The game's real circle: 70x70.
        let image = render(Shape::Circle, 70, 70).expect("circle");
        assert_eq!(alpha_at(&image, 0, 0), 0);
        assert_eq!(alpha_at(&image, 69, 0), 0);
        assert_eq!(alpha_at(&image, 0, 69), 0);
        assert_eq!(alpha_at(&image, 69, 69), 0);
        assert_eq!(alpha_at(&image, 35, 35), 255);
        assert_eq!(alpha_at(&image, 35, 0), 255);
        assert_eq!(alpha_at(&image, 0, 35), 255);
        // A wide box gives an ellipse, not a circle.
        let ellipse = render(Shape::Circle, 100, 20).expect("ellipse");
        assert_eq!(alpha_at(&ellipse, 50, 10), 255);
        assert_eq!(alpha_at(&ellipse, 2, 2), 0);
    }

    #[test]
    fn triangles_point_where_they_are_named() {
        // The game's only literal triangle: <TRI-DOWN> at 9x9, the page-down marker of a
        // message window. The apex is on the bottom edge, the base along the top.
        let down = render(Shape::Triangle(TriDir::Down), 9, 9).expect("down triangle");
        // Base along the top row, apex at the bottom centre.
        for x in 0..9 {
            assert_eq!(alpha_at(&down, x, 0), 255, "base column {x}");
        }
        assert_eq!(alpha_at(&down, 4, 8), 255, "apex");
        assert_eq!(alpha_at(&down, 0, 8), 0);
        assert_eq!(alpha_at(&down, 8, 8), 0);
        assert_eq!(alpha_at(&down, 0, 4), 0);

        let left = render(Shape::Triangle(TriDir::Left), 9, 9).expect("left triangle");
        assert_eq!(alpha_at(&left, 0, 4), 255);
        assert_eq!(alpha_at(&left, 8, 0), 255);
        assert_eq!(alpha_at(&left, 8, 8), 255);
        assert_eq!(alpha_at(&left, 8, 4), 255);
        assert_eq!(alpha_at(&left, 0, 0), 0);
        assert_eq!(alpha_at(&left, 0, 8), 0);

        let right = render(Shape::Triangle(TriDir::Right), 9, 9).expect("right triangle");
        assert_eq!(alpha_at(&right, 8, 4), 255);
        assert_eq!(alpha_at(&right, 0, 0), 255);
        assert_eq!(alpha_at(&right, 0, 8), 255);
        assert_eq!(alpha_at(&right, 8, 0), 0);

        let up = render(Shape::Triangle(TriDir::Up), 9, 9).expect("up triangle");
        for x in 0..9 {
            assert_eq!(alpha_at(&up, x, 8), 255, "base column {x}");
        }
        assert_eq!(alpha_at(&up, 4, 0), 255, "apex");
        assert_eq!(alpha_at(&up, 0, 0), 0);
    }

    #[test]
    fn absurd_sizes_are_refused_rather_than_allocated() {
        assert_eq!(render(Shape::Square, 0, 10), None);
        assert_eq!(render(Shape::Square, 10, 0), None);
        assert_eq!(render(Shape::Circle, 0, 0), None);
        assert_eq!(render(Shape::SquareFrame, 0, 5), None);
        // Over MAX_SIDE on one axis.
        assert_eq!(render(Shape::Square, MAX_SIDE + 1, 1), None);
        assert_eq!(render(Shape::Square, 1, MAX_SIDE + 1), None);
        // Individually legal, jointly over MAX_PIXELS.
        assert_eq!(render(Shape::Square, MAX_SIDE, MAX_SIDE), None);
        // The largest legal shape is accepted.
        assert!(render(Shape::Square, 1024, 576).is_some());
    }

    #[test]
    fn atlas_keys_are_unique_and_cannot_collide_with_file_names() {
        let small = atlas_key(Shape::Square, 120, 5);
        let big = atlas_key(Shape::Square, 800, 500);
        let frame = atlas_key(Shape::SquareFrame, 120, 5);
        assert_ne!(small, big, "size must be part of the key");
        assert_ne!(small, frame);
        // Opposite fades over the same box must not share a slot.
        let out = atlas_key(Shape::GradX { from: 444, to: 0 }, 215, 4);
        let into = atlas_key(Shape::GradX { from: 0, to: 444 }, 215, 4);
        assert_ne!(out, into);
        assert_eq!(small, atlas_key(Shape::Square, 120, 5));

        // A generated key contains ':', which assets::normalize refuses (a colon could
        // address a drive letter), so no on-disk name can ever produce the same string.
        assert!(small.contains(':'));
        let mut assets = crate::assets::Assets::new("unused");
        assert!(matches!(
            assets.load(&small),
            Err(AssetError::BadName { .. })
        ));
        assert!(matches!(
            assets.load(&frame),
            Err(AssetError::BadName { .. })
        ));
    }

    #[test]
    fn spelling_round_trips_through_parse() {
        let shapes = [
            Shape::Square,
            Shape::SquareFrame,
            Shape::GradX { from: 999, to: 274 },
            Shape::GradY { from: 111, to: 555 },
            Shape::Line,
            Shape::Circle,
            Shape::Triangle(TriDir::Left),
            Shape::Triangle(TriDir::Right),
            Shape::Triangle(TriDir::Up),
            Shape::Triangle(TriDir::Down),
        ];
        for shape in shapes {
            let text = name(shape);
            assert_eq!(parse(&text), Some(shape), "{text} did not round-trip");
        }
    }

    #[test]
    fn a_box_comes_from_the_window_fields_and_a_line_keeps_a_zero_height() {
        // The retail progress bar: `<SQUARE>FRAME` at 120x5, x=320, y=342.
        assert_eq!(box_size(Shape::SquareFrame, Some((120, 5))), Some((120, 5)));
        // All 7 `<LINE>` instructions arrive with h = 0 and still draw a hairline.
        assert_eq!(box_size(Shape::Line, Some((400, 0))), Some((400, 1)));
        // Every other shape refuses a degenerate box rather than drawing a blob.
        assert_eq!(box_size(Shape::Square, Some((120, 0))), None);
        assert_eq!(box_size(Shape::Circle, Some((0, 70))), None);
        assert_eq!(box_size(Shape::Square, Some((-8, 8))), None);
        assert_eq!(box_size(Shape::Square, None), None);
        // The gradient parameters are alpha endpoints, never a size: the box is the only
        // authority, whatever the name says.
        let grad = parse("<GRADX-999-666>").expect("gradient");
        assert_eq!(box_size(grad, Some((470, 8))), Some((470, 8)));
    }
}
