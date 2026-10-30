//! Real font metrics for text layout.
//!
//! Text pictures are laid out before the renderer sees them, so their anchor has to know
//! how wide a glyph actually is. [crate::textpic] deliberately keeps a half-em fallback
//! that is testable without a font; this module supplies the real advances when the host
//! has loaded the game's TTF (Lolita.ttf). The renderer shapes the same font with
//! cosmic-text, so both sides then agree on the run width and right-aligned HUD text stops
//! drifting a few pixels.

use std::cell::RefCell;
use std::collections::HashMap;

use crate::choice;

/// Advances measured from one TTF, cached per character.
///
/// The bytes stay owned here because a `ttf_parser::Face` borrows them. Parsing a face is
/// cheap; the cache means a frame with many text pictures parses each glyph once.
pub struct FontMetrics {
    bytes: Vec<u8>,
    units_per_em: f32,
    advances: RefCell<HashMap<char, Option<f32>>>,
}

impl FontMetrics {
    /// Parses a TTF/OTF blob. Returns `None` when it is not a usable font.
    #[must_use]
    pub fn load(bytes: Vec<u8>) -> Option<Self> {
        let face = ttf_parser::Face::parse(&bytes, 0).ok()?;
        let units_per_em = f32::from(face.units_per_em());
        if units_per_em <= 0.0 {
            return None;
        }
        Some(Self {
            bytes,
            units_per_em,
            advances: RefCell::new(HashMap::new()),
        })
    }

    /// The em advance of `ch`, or `None` when the font has no glyph for it.
    fn em_advance(&self, ch: char) -> Option<f32> {
        if let Some(cached) = self.advances.borrow().get(&ch) {
            return *cached;
        }
        let face = ttf_parser::Face::parse(&self.bytes, 0).ok()?;
        let value = face
            .glyph_index(ch)
            .and_then(|glyph| face.glyph_hor_advance(glyph))
            .map(|units| f32::from(units) / self.units_per_em);
        self.advances.borrow_mut().insert(ch, value);
        value
    }

    /// Advance width of `ch` at `font_px`, falling back to the half-em rule for glyphs
    /// the font does not cover (notably a newline, which never draws).
    #[must_use]
    pub fn advance(&self, ch: char, font_px: f32) -> f32 {
        if ch == '\n' {
            return 0.0;
        }
        self.em_advance(ch)
            .map_or_else(|| choice::advance_at(ch, font_px), |em| em * font_px)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn lolita() -> Option<FontMetrics> {
        let mut path = std::path::PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        path.pop();
        path.pop();
        path.push("work/full/Fonts/Lolita.ttf");
        FontMetrics::load(std::fs::read(path).ok()?)
    }

    #[test]
    fn lolita_digits_measure_like_the_retail_hud() {
        let Some(metrics) = lolita() else {
            eprintln!("skipping: work/full/Fonts/Lolita.ttf is not present");
            return;
        };
        let width: f32 = "21:40".chars().map(|ch| metrics.advance(ch, 24.0)).sum();
        assert!((width - 56.31).abs() < 0.1, "21:40 at 24px = {width}");
        assert!(metrics.advance('0', 24.0) > metrics.advance('1', 24.0));
    }

    #[test]
    fn missing_glyphs_keep_the_half_em_fallback() {
        let Some(metrics) = lolita() else {
            eprintln!("skipping: work/full/Fonts/Lolita.ttf is not present");
            return;
        };
        // U+10FFFD is a private-use shape no normal text font covers.
        assert_eq!(
            metrics.advance('\u{10fffd}', 20.0),
            choice::advance_at('\u{10fffd}', 20.0)
        );
    }

    #[test]
    fn newline_never_advances() {
        let Some(metrics) = lolita() else {
            eprintln!("skipping: work/full/Fonts/Lolita.ttf is not present");
            return;
        };
        assert_eq!(metrics.advance('\n', 20.0), 0.0);
    }
}
