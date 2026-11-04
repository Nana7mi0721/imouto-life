//! Nine-slice geometry for WOLF window pictures.
//!
//! Picture types 3 and 4 are "window" variants: the runtime paints a UI panel
//! behind the content, sized to the picture's box. The default panel comes from
//! the 18x18 skin SystemFile/WindowBase.png - the one the game's SysDatabase
//! "ウィンドウ画像" row names for the choice window ("×選択肢ウィンドウ画像"). Its
//! layout was measured pixel by pixel:
//!
//!   row/col 0      outer dark line     0x424242 (outer corner transparent)
//!   row/col 1      light bevel         0xf2f3f3 (corner 0x888888)
//!   row/col 2      transition line     0x576062 (corner 0xd9dcdd)
//!   rows/cols 3..14 body, 0x1f2425 at alpha 0xdf (the translucent grey fill)
//!   rows 15/16     mirror of 2 and 1
//!
//! so the frame is 3 px thick and the skin is a symmetric nine-slice. WOLF does
//! not tile the edges: it stretches the middle row and column to the target box,
//! which is why the fill looks smooth at any window size. This module reproduces
//! that stretch and nothing else - no rounded corners, no dithering.
//!
//! The 101 message window ships the same grey SystemFile/WindowBase.png through
//! its own 150 picture (common event 63 passes it through self[9]), so the same
//! 3 px cut reproduces both the message and the choice window. SystemGraphic/
//! WindowBase.png is a different, unused navy-gradient sample asset; the retail
//! choice panel is grey. Do not switch back to it. CORNER stays 3.

/// Asset name of the default window skin.
pub const SKIN: &str = "SystemFile/WindowBase.png";

/// Thickness of the skin frame, in texels.
pub const CORNER: u32 = 3;

/// Box sizes at or below this are the "no explicit box" sentinel.
///
/// WOLF writes 1x1 for text pictures that size themselves, and 0x0 for window
/// pictures that inherit the content size, so anything this small cannot be a
/// real panel.
pub const MIN_BOX: i32 = 2;

/// Picture number reported for runtime-drawn panels.
///
/// The engine's own UI is not a script picture, so it needs a number that can never
/// collide with one: scripts use >= -2, so a large negative sentinel sorts it behind
/// every script layer while still being recognisable in a trace.
pub const PANEL_PICTURE: i32 = -100;

/// One stretched piece of the skin.
#[derive(Clone, Copy, Debug, PartialEq)]
pub struct WindowPiece {
    /// Destination rectangle in logical pixels: x, y, width, height.
    pub rect: [f32; 4],
    /// Source rectangle in skin texels: x, y, width, height.
    pub src: [u32; 4],
}

/// Splits a destination rectangle into the nine stretched pieces of a skin.
///
/// Degenerate inputs are tolerated rather than rejected: a zero-sized skin or a
/// destination smaller than the frame collapses the corners so the result is
/// still a covering set of quads (WOLF itself would clip, but a clipped quad and
/// a zero-width quad draw the same nothing).
#[must_use]
pub fn nine_slice(dst: [f32; 4], skin_w: u32, skin_h: u32) -> Vec<WindowPiece> {
    nine_slice_cornered(dst, skin_w, skin_h, CORNER)
}

/// [nine_slice] with an explicit frame thickness.
///
/// The choice cursor uses its own 12x12 skin (SystemFile/CursorBase.png) whose frame is
/// 4 texels, not the window skin's 3. The engine keeps one corner size per picture and
/// stretches each with the same routine, so no second algorithm is needed.
#[must_use]
pub fn nine_slice_cornered(
    dst: [f32; 4],
    skin_w: u32,
    skin_h: u32,
    corner: u32,
) -> Vec<WindowPiece> {
    let mut pieces = Vec::with_capacity(9);
    if skin_w == 0 || skin_h == 0 {
        return pieces;
    }
    let (x, y) = (dst[0], dst[1]);
    let w = dst[2].max(0.0);
    let h = dst[3].max(0.0);
    if w <= 0.0 || h <= 0.0 {
        return pieces;
    }
    // Skin columns: 0..cw, cw..skin_w-cw, skin_w-cw..skin_w. A skin narrower than
    // twice the frame has no middle column, and the frame shrinks to fit.
    let cw = corner.min(skin_w / 2);
    let ch = corner.min(skin_h / 2);
    let cols = split(skin_w, cw);
    let rows = split(skin_h, ch);
    // Destination columns: corners keep their pixel size unless the box is too
    // small for them, in which case they halve so the sum still covers the box.
    let dcols = [
        0.0_f32,
        (cw as f32).min(w / 2.0),
        w - (cw as f32).min(w / 2.0),
        w,
    ];
    let drows = [
        0.0_f32,
        (ch as f32).min(h / 2.0),
        h - (ch as f32).min(h / 2.0),
        h,
    ];
    for row in 0..3 {
        for col in 0..3 {
            let (sx, sw) = (cols[col], cols[col + 1] - cols[col]);
            let (sy, sh) = (rows[row], rows[row + 1] - rows[row]);
            if sw == 0 || sh == 0 {
                continue;
            }
            let dw = dcols[col + 1] - dcols[col];
            let dh = drows[row + 1] - drows[row];
            if dw <= 0.0 || dh <= 0.0 {
                continue;
            }
            pieces.push(WindowPiece {
                rect: [x + dcols[col], y + drows[row], dw, dh],
                src: [sx, sy, sw, sh],
            });
        }
    }
    pieces
}

/// A window skin drawn as a hollow frame: the eight border pieces, no centre fill.
///
/// `SystemFile/CursorBase.png` is a solid 12x12 block, not a panel body. WOLF uses it as a
/// selection cursor, so stretching its centre tile over the whole box (as a normal nine
/// slice does) paints an opaque slab over the panel underneath. Dropping the centre piece
/// leaves only the 4px border, which is what the retail save screen shows.
pub fn nine_slice_frame(dst: [f32; 4], skin_w: u32, skin_h: u32, corner: u32) -> Vec<WindowPiece> {
    let mut pieces = nine_slice_cornered(dst, skin_w, skin_h, corner);
    if pieces.len() == 9 {
        pieces.remove(4);
    }
    pieces
}

/// Three cut points across a length: 0, corner, len - corner, len.
fn split(len: u32, corner: u32) -> [u32; 4] {
    [0, corner, len - corner, len]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn the_default_skin_is_the_grey_system_file_panel() {
        // The game's SysDatabase "ウィンドウ画像" row names this file for the
        // choice window ("×選択肢ウィンドウ画像"). SystemGraphic/WindowBase.png is a
        // navy sample asset that no script or database row references; painting the
        // choice panel with it made every prompt purple.
        assert_eq!(SKIN, "SystemFile/WindowBase.png");
    }

    #[test]
    fn a_full_skin_uses_every_texel_exactly_once() {
        let pieces = nine_slice([0.0, 0.0, 30.0, 20.0], 18, 18);
        assert_eq!(pieces.len(), 9);
        let area: u32 = pieces.iter().map(|piece| piece.src[2] * piece.src[3]).sum();
        assert_eq!(area, 18 * 18);
        // The centre piece keeps the skin centre and stretches in the destination.
        let centre = pieces
            .iter()
            .find(|piece| piece.src == [3, 3, 12, 12])
            .expect("centre piece");
        assert_eq!(centre.rect, [3.0, 3.0, 24.0, 14.0]);
    }

    #[test]
    fn corners_keep_their_pixel_size_and_the_middle_absorbs_the_rest() {
        let pieces = nine_slice([100.0, 50.0, 300.0, 200.0], 18, 18);
        let top_left = pieces
            .iter()
            .find(|piece| piece.src == [0, 0, 3, 3])
            .expect("top-left");
        assert_eq!(top_left.rect, [100.0, 50.0, 3.0, 3.0]);
        let bottom_right = pieces
            .iter()
            .find(|piece| piece.src == [15, 15, 3, 3])
            .expect("bottom-right");
        assert_eq!(bottom_right.rect, [397.0, 247.0, 3.0, 3.0]);
        // Every piece stays inside the requested box.
        for piece in &pieces {
            assert!(piece.rect[0] >= 100.0 && piece.rect[1] >= 50.0);
            assert!(piece.rect[0] + piece.rect[2] <= 400.0 + 0.001);
            assert!(piece.rect[1] + piece.rect[3] <= 250.0 + 0.001);
        }
    }

    #[test]
    fn a_box_smaller_than_the_frame_collapses_the_corners() {
        let pieces = nine_slice([0.0, 0.0, 4.0, 4.0], 18, 18);
        // 2 px corners leave no middle, so only the four corners survive.
        assert_eq!(pieces.len(), 4);
        for piece in &pieces {
            assert_eq!(piece.rect[2], 2.0);
            assert_eq!(piece.rect[3], 2.0);
        }
    }

    #[test]
    fn degenerate_inputs_return_nothing_instead_of_panicking() {
        assert!(nine_slice([0.0, 0.0, 10.0, 10.0], 0, 18).is_empty());
        assert!(nine_slice([0.0, 0.0, 10.0, 10.0], 18, 0).is_empty());
        assert!(nine_slice([0.0, 0.0, 0.0, 10.0], 18, 18).is_empty());
        assert!(nine_slice([0.0, 0.0, 10.0, -4.0], 18, 18).is_empty());
    }

    #[test]
    fn a_skin_without_a_middle_band_still_splits() {
        // A 4 px skin has a 2 px corner and no middle column.
        let pieces = nine_slice([0.0, 0.0, 8.0, 8.0], 4, 4);
        assert_eq!(pieces.len(), 4);
        assert!(pieces.iter().all(|piece| piece.src[2] == 2));
    }
}
