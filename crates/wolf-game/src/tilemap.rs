//! Tile layers: a WOLF map plus its tileset, turned into sprite quads.
//!
//! WOLF draws a map as three independent tile layers, each a grid of 16x16 cells
//! stored layer-major in the .mps file. A cell is either empty (0xFFFFFFFF), a plain
//! base chip (an index into the tileset base image) or an autotile (a tileset autotile
//! plus four quadrant codes).
//!
//! The autotile layout was measured from the shipped art: an autotile image is a
//! vertical strip of five 16x16 cells (one per quadrant code 0..4) and, when the image
//! is wider than 16 px, each further 16 px column is an animation frame. A cell is
//! therefore composed of four 8x8 quadrants. The source rectangle for quadrant
//! (qx, qy) is (frame * 16 + qx * 8, code * 16 + qy * 8, 8, 8) in pixels.
//! work/out/autotile_test.png shows the result: code 4 for all
//! four quadrants is a solid tile, code 0 for all four is an isolated blob, and the
//! mixed codes produce the expected edges and corners.

use crate::assets::Assets;
use crate::atlas::{Atlas, AtlasRect, SpriteQuad};
use wolf_format::mps::{decode_tile, Tile};
use wolf_format::tileset::TileSet;

/// WOLF's tile size in logical pixels (Game.dat u8_settings[0] is 16 for this game).
pub const TILE_PX: u32 = 16;
/// Half a tile: one autotile quadrant.
pub const QUADRANT_PX: u32 = TILE_PX / 2;
/// How many tile layers a .mps carries.
pub const LAYERS: usize = 3;
/// Picture-number key used for tile quads so they sort behind script pictures.
pub const TILE_NUMBER: i32 = -10_000;

/// A map's tile layers, decoded and ready to draw.
///
/// The tileset is reduced to the two things rendering needs (base image plus autotile
/// slot names) so no .mps bytes and no passability tables are retained.
pub struct TileMap {
    /// Map width in tiles.
    pub width: i32,
    /// Map height in tiles.
    pub height: i32,
    /// Which tileset the map points at.
    pub tileset_index: u32,
    /// Decoded cells, one vector per layer, row-major.
    layers: Vec<Vec<Tile>>,
    /// Tileset base image, relative to the data root.
    base_image: String,
    /// Autotile slot names; index 0 is autotile id 1.
    autotiles: Vec<String>,
}

impl TileMap {
    /// Decodes a parsed map against its tileset.
    ///
    /// version is the TileSetData version (0xD2 in this game) because the autotile
    /// slot count depends on it.
    #[must_use]
    pub fn new(map: &wolf_format::mps::Map, tileset: &TileSet, version: u8) -> Self {
        let slots = TileSet::autotile_slots(version);
        let mut autotiles = Vec::with_capacity(slots);
        for index in 0..slots {
            autotiles.push(tileset.autotiles.get(index).cloned().unwrap_or_default());
        }
        let layers = map
            .layers
            .iter()
            .map(|layer| layer.iter().map(|raw| decode_tile(*raw)).collect())
            .collect();
        Self {
            width: map.width as i32,
            height: map.height as i32,
            tileset_index: map.tileset_index,
            layers,
            base_image: tileset.base_image.clone(),
            autotiles,
        }
    }

    /// Size of the whole map in logical pixels.
    #[must_use]
    pub fn size_px(&self) -> [i32; 2] {
        [self.width * TILE_PX as i32, self.height * TILE_PX as i32]
    }

    /// One layer of decoded cells, if it exists.
    #[must_use]
    pub fn layer(&self, index: usize) -> Option<&[Tile]> {
        self.layers.get(index).map(Vec::as_slice)
    }

    /// How many layers this map actually carries.
    #[must_use]
    pub fn layer_count(&self) -> usize {
        self.layers.len()
    }

    /// Builds the quads for everything inside the camera window.
    ///
    /// camera is the logical pixel offset of the map origin, i.e. the map pixel shown
    /// at the top-left of the screen. Cells outside the window are skipped, which is
    /// what makes the 70x170 map affordable: only about 64x36 cells survive the cull.
    pub fn quads(
        &self,
        atlas: &mut Atlas,
        assets: &mut Assets,
        camera: [i32; 2],
        screen: [u32; 2],
        frame: u32,
    ) -> Vec<SpriteQuad> {
        let mut out = Vec::new();
        let [atlas_w, atlas_h] = atlas.size();
        let (cols, rows) = cull_range([self.width, self.height], camera, screen, TILE_PX);
        // Pack the base sheet once per call; absent art is a skip, never a panic.
        let base = atlas.add_asset(assets, &self.base_image);
        let base_size = atlas.source_size(&self.base_image).unwrap_or([0, 0]);
        let autotile_rects: Vec<Option<AtlasRect>> = self
            .autotiles
            .iter()
            .map(|name| {
                if name.is_empty() {
                    None
                } else {
                    atlas.add_asset(assets, name)
                }
            })
            .collect();
        let autotile_sizes: Vec<[u32; 2]> = self
            .autotiles
            .iter()
            .map(|name| {
                if name.is_empty() {
                    [0, 0]
                } else {
                    atlas.source_size(name).unwrap_or([0, 0])
                }
            })
            .collect();

        for (layer_index, layer) in self.layers.iter().enumerate() {
            let number = TILE_NUMBER + layer_index as i32;
            for y in rows.clone() {
                for x in cols.clone() {
                    let Some(tile) = layer.get((y * self.width + x) as usize) else {
                        continue;
                    };
                    let dst_x = x * TILE_PX as i32 - camera[0];
                    let dst_y = y * TILE_PX as i32 - camera[1];
                    match *tile {
                        Tile::Empty => {}
                        Tile::Base(index) => {
                            let (Some(rect), [sheet_w, sheet_h]) = (base, base_size) else {
                                continue;
                            };
                            let Some(src) = base_src(index, [sheet_w, sheet_h]) else {
                                continue;
                            };
                            out.push(SpriteQuad {
                                number,
                                rect: [
                                    dst_x as f32,
                                    dst_y as f32,
                                    TILE_PX as f32,
                                    TILE_PX as f32,
                                ],
                                uv: rect.sub_uv(atlas_w, atlas_h, src),
                                alpha: 1.0,
                                tint: [1.0, 1.0, 1.0],
                            });
                        }
                        Tile::Autotile { id, corners } => {
                            let slot = (id as usize).saturating_sub(1);
                            let (Some(rect), [sheet_w, _]) = (
                                autotile_rects.get(slot).and_then(|value| *value),
                                autotile_sizes.get(slot).copied().unwrap_or([0, 0]),
                            ) else {
                                continue;
                            };
                            for (quadrant, code) in corners.iter().enumerate() {
                                let Some(src) = autotile_src(*code, quadrant, sheet_w, frame)
                                else {
                                    continue;
                                };
                                let qx = (quadrant % 2) as i32;
                                let qy = (quadrant / 2) as i32;
                                out.push(SpriteQuad {
                                    number,
                                    rect: [
                                        dst_x as f32 + (qx * QUADRANT_PX as i32) as f32,
                                        dst_y as f32 + (qy * QUADRANT_PX as i32) as f32,
                                        QUADRANT_PX as f32,
                                        QUADRANT_PX as f32,
                                    ],
                                    uv: rect.sub_uv(atlas_w, atlas_h, src),
                                    alpha: 1.0,
                                    tint: [1.0, 1.0, 1.0],
                                });
                            }
                        }
                    }
                }
            }
        }
        out
    }
}

/// Turns a base chip index into a source rectangle inside the tileset base image.
///
/// The base sheet is a plain grid of 16x16 cells, eight columns wide in every shipped
/// tileset. TileSetData declares capacity (2376 entries) that exceeds the art, so an
/// index past the bottom of the sheet returns None instead of wrapping to a wrong cell.
#[must_use]
pub fn base_src(index: u32, sheet: [u32; 2]) -> Option<[u32; 4]> {
    if sheet[0] < TILE_PX || sheet[1] < TILE_PX {
        return None;
    }
    let cols = sheet[0] / TILE_PX;
    let rows = sheet[1] / TILE_PX;
    let x = index % cols;
    let y = index / cols;
    if y >= rows {
        return None;
    }
    Some([x * TILE_PX, y * TILE_PX, TILE_PX, TILE_PX])
}

/// Turns one autotile quadrant into a source rectangle.
///
/// code is the .mps quadrant variant (0..4 in real data; anything above that is a
/// corrupt tile and is skipped rather than sampling a nonexistent row), quadrant is
/// 0 = top-left, 1 = top-right, 2 = bottom-left, 3 = bottom-right, and sheet_w drives
/// the animation frame count because each frame is one 16 px column.
#[must_use]
pub fn autotile_src(code: u8, quadrant: usize, sheet_w: u32, frame: u32) -> Option<[u32; 4]> {
    if code > 4 || quadrant > 3 {
        return None;
    }
    let frames = (sheet_w / TILE_PX).max(1);
    let column = frame % frames;
    let qx = (quadrant % 2) as u32;
    let qy = (quadrant / 2) as u32;
    Some([
        column * TILE_PX + qx * QUADRANT_PX,
        code as u32 * TILE_PX + qy * QUADRANT_PX,
        QUADRANT_PX,
        QUADRANT_PX,
    ])
}

/// Half-open tile index range covering the camera window, clamped to the map.
///
/// Returned as (columns, rows) so callers can iterate twice without recomputing.
#[must_use]
pub fn cull_range(
    map_tiles: [i32; 2],
    camera: [i32; 2],
    screen: [u32; 2],
    tile_px: u32,
) -> (std::ops::Range<i32>, std::ops::Range<i32>) {
    let tile = tile_px.max(1) as i32;
    let first_col = camera[0].div_euclid(tile).clamp(0, map_tiles[0]);
    let first_row = camera[1].div_euclid(tile).clamp(0, map_tiles[1]);
    let last_col = ((camera[0] + screen[0] as i32).div_euclid(tile) + 1).clamp(0, map_tiles[0]);
    let last_row = ((camera[1] + screen[1] as i32).div_euclid(tile) + 1).clamp(0, map_tiles[1]);
    (first_col..last_col, first_row..last_row)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn base_chips_are_a_grid_of_tiles() {
        let sheet = [128, 3984];
        assert_eq!(base_src(0, sheet), Some([0, 0, 16, 16]));
        assert_eq!(base_src(7, sheet), Some([112, 0, 16, 16]));
        assert_eq!(base_src(8, sheet), Some([0, 16, 16, 16]));
        // 931 = 8 * 116 + 3, so column 3, row 116 of a 249-row sheet.
        assert_eq!(base_src(931, sheet), Some([48, 1856, 16, 16]));
        // TileSetData declares 2376 entries but the art only has 1992 cells.
        assert_eq!(base_src(2375, sheet), None);
        assert_eq!(base_src(0, [0, 0]), None);
    }

    #[test]
    fn autotile_quadrants_follow_the_measured_strip() {
        assert_eq!(autotile_src(4, 0, 16, 0), Some([0, 64, 8, 8]));
        assert_eq!(autotile_src(4, 1, 16, 0), Some([8, 64, 8, 8]));
        assert_eq!(autotile_src(4, 2, 16, 0), Some([0, 72, 8, 8]));
        assert_eq!(autotile_src(4, 3, 16, 0), Some([8, 72, 8, 8]));
        // A 64 px wide strip is four frames; frame 2 is the third column.
        assert_eq!(autotile_src(0, 0, 64, 2), Some([32, 0, 8, 8]));
        assert_eq!(autotile_src(0, 0, 64, 6), Some([32, 0, 8, 8]));
        assert_eq!(autotile_src(5, 0, 16, 0), None);
        assert_eq!(autotile_src(0, 4, 16, 0), None);
    }

    #[test]
    fn culling_covers_the_visible_window_only() {
        let (cols, rows) = cull_range([70, 170], [0, 0], [1024, 576], 16);
        assert_eq!(cols, 0..65);
        assert_eq!(rows, 0..37);
        let (cols, rows) = cull_range([70, 170], [1000, 2600], [1024, 576], 16);
        assert_eq!(cols, 62..70);
        assert_eq!(rows, 162..170);
        let (cols, _) = cull_range([10, 10], [-64, -64], [1024, 576], 16);
        assert_eq!(cols, 0..10);
    }
}