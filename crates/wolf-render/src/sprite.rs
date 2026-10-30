//! The per-instance payload of the batch.
//!
//! One `SpriteInstance` is one textured quad. Keeping everything in one 48-byte instance
//! (instead of a vertex buffer of 6 vertices) is what lets the whole frame be a single
//! `draw(0..4, 0..n)`: the four corners are synthesised in the vertex shader from
//! `@builtin(vertex_index)`, so the CPU only ships the data that actually differs.

use bytemuck::{Pod, Zeroable};

/// One quad, in logical (1024x576) pixels.
#[repr(C)]
#[derive(Clone, Copy, Debug, PartialEq, Pod, Zeroable)]
pub struct SpriteInstance {
    /// `[x, y, w, h]` of the destination, in logical pixels, origin top-left.
    pub rect: [f32; 4],
    /// `[u0, v0, u1, v1]` of the source sub-rectangle, in normalised atlas coordinates.
    pub uv: [f32; 4],
    /// Straight-alpha tint multiplied into the texel. `[1, 1, 1, 1]` is a no-op.
    pub tint: [f32; 4],
}

impl SpriteInstance {
    /// Byte size of one instance; must match `array_stride` in the vertex layout.
    pub const SIZE: usize = std::mem::size_of::<Self>();

    /// A fully opaque, untinted quad.
    #[must_use]
    pub fn new(rect: [f32; 4], uv: [f32; 4]) -> Self {
        Self {
            rect,
            uv,
            tint: [1.0; 4],
        }
    }

    /// Same quad at `alpha` opacity (0.0 = invisible, 1.0 = opaque).
    #[must_use]
    pub fn with_alpha(mut self, alpha: f32) -> Self {
        self.tint[3] = alpha;
        self
    }

    /// Same quad with its rgb scaled by `tone` (DxLib `SetDrawBright` semantics:
    /// brightness multiplies the colour channels and never the alpha).
    ///
    /// WOLF pictures carry such a tone: the title hint banner renders as its source
    /// bitmap times 222/255 on rgb, alpha untouched. Keeping the tone in the
    /// instance rather than in the blend path is what lets the renderer reproduce
    /// that pixel-exactly; see `tests/offscreen.rs`.
    #[must_use]
    pub fn with_tint_rgb(mut self, r: f32, g: f32, b: f32) -> Self {
        self.tint[0] = r;
        self.tint[1] = g;
        self.tint[2] = b;
        self
    }
}

/// Vertex layout for the instance buffer: three `vec4<f32>`, stepped once per instance.
pub(crate) const INSTANCE_ATTRS: [wgpu::VertexAttribute; 3] =
    wgpu::vertex_attr_array![0 => Float32x4, 1 => Float32x4, 2 => Float32x4];

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn instance_is_twelve_floats() {
        assert_eq!(SpriteInstance::SIZE, 48);
        assert_eq!(SpriteInstance::SIZE, INSTANCE_ATTRS.len() * 16);
    }

    #[test]
    fn alpha_only_touches_the_alpha_slot() {
        let s = SpriteInstance::new([0.0, 0.0, 1.0, 1.0], [0.0, 0.0, 1.0, 1.0]).with_alpha(0.5);
        assert_eq!(s.tint, [1.0, 1.0, 1.0, 0.5]);
    }

    #[test]
    fn rgb_tint_only_touches_the_colour_slots() {
        let s = SpriteInstance::new([0.0, 0.0, 1.0, 1.0], [0.0, 0.0, 1.0, 1.0])
            .with_tint_rgb(0.5, 0.25, 0.75);
        assert_eq!(s.tint, [0.5, 0.25, 0.75, 1.0]);
    }
}
