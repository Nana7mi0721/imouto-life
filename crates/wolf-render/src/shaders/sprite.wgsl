// Instanced sprite shader for the 1024x576 logical framebuffer.
//
// One draw call per atlas page: the unit quad is generated procedurally from
// `vertex_index`, so the vertex buffer carries *no* positions at all -- only the
// per-instance rect / uv / tint. That keeps the instance stride at 48 bytes
// (see crates/wolf-render/src/sprite.rs) instead of the 4 corners * 32 bytes a
// non-instanced path would need, which matters because WOLF Picture layers can
// push thousands of quads per frame.
//
// Why a function-level unit quad instead of an index buffer: with
// PrimitiveTopology::TriangleStrip the 4 corners (0,0) (1,0) (0,1) (1,1) form
// exactly two triangles, so no index buffer, no second bind group, and
// `draw(0..4, 0..n)` is the whole call.

struct Screen {
    // Logical framebuffer size in pixels. Passed as a uniform (not baked into
    // the shader) so the same pipeline survives a future 1280x720 / 640x360
    // logical mode without a shader recompile.
    size: vec2<f32>,
    _pad: vec2<f32>,
};

@group(0) @binding(0) var<uniform> screen: Screen;
@group(1) @binding(0) var atlas_tex: texture_2d<f32>;
@group(1) @binding(1) var atlas_smp: sampler;

struct VsOut {
    @builtin(position) clip: vec4<f32>,
    // Location numbers restart at 0 for varyings; they are independent of the
    // vertex-buffer locations above.
    @location(0) uv: vec2<f32>,
    @location(1) tint: vec4<f32>,
};

@vertex
fn vs(
    @builtin(vertex_index) vi: u32,
    @location(0) rect: vec4<f32>,
    @location(1) uv: vec4<f32>,
    @location(2) tint: vec4<f32>,
) -> VsOut {
    // 0 -> (0,0), 1 -> (1,0), 2 -> (0,1), 3 -> (1,1).
    let corner = vec2<f32>(f32(vi & 1u), f32((vi >> 1u) & 1u));

    // rect = (x, y, w, h) in logical pixels, y down, origin top-left.
    let px = rect.xy + corner * rect.zw;

    // Logical pixels -> NDC. Y is flipped because NDC +Y points up while the
    // WOLF coordinate system the rest of the engine speaks has +Y down.
    let ndc = vec2<f32>(
        px.x / screen.size.x * 2.0 - 1.0,
        1.0 - px.y / screen.size.y * 2.0,
    );

    var out: VsOut;
    out.clip = vec4<f32>(ndc, 0.0, 1.0);
    // uv = (u0, v0, u1, v1) -- the sub-rect of the atlas page.
    out.uv = mix(uv.xy, uv.zw, corner);
    out.tint = tint;
    return out;
}

@fragment
fn fs(in: VsOut) -> @location(0) vec4<f32> {
    // The atlas is plain Rgba8Unorm, so textureSample returns the stored bytes
    // unchanged and the fixed-function blend then runs on those bytes -- no
    // linearisation anywhere. That deliberately mirrors DxLib/D3D9, which the
    // retail game uses; see `FRAME_FORMAT` in renderer.rs for the measurement
    // that pins this (63 vs 136 on one title-screen pixel).
    let texel = textureSample(atlas_tex, atlas_smp, in.uv);
    // alpha comes from tint.a, rgb from tint.rgb. Straight (non-premultiplied)
    // alpha: we deliberately do NOT multiply texel.rgb by texel.a here -- the
    // blend state (BlendState::ALPHA_BLENDING = SrcAlpha / OneMinusSrcAlpha)
    // expects straight alpha, and premultiplying here would double-apply it and
    // darken the edges of 50%-alpha sprites.
    return vec4<f32>(texel.rgb, texel.a) * in.tint;
}
