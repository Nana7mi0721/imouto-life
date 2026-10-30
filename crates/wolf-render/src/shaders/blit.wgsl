// Full-screen upscale of the 1024x576 logical framebuffer onto the swapchain.
//
// Why a quadratic blit inside the shader instead of a textureless fullscreen
// triangle plus a viewport: the requirements are integer-only scaling and
// centring. Expressing that as "the NDC rect the logical image occupies"
// (centre + +/- half) keeps the letterbox trivial -- the cleared surface shows
// through outside the quad -- and keeps the sampler at Nearest so each logical
// pixel becomes an exact scale x scale block. Handing the scaling to the OS or
// the driver (e.g. by configuring a smaller swapchain and letting Windows
// stretch it) produces bilinear-ish artefacts and, on mixed-DPI Windows
// displays, an unpredictable stretch we cannot test.

struct Quad {
    // Centre of the logical image in NDC, y up.
    centre: vec2<f32>,
    // Half extent of the logical image in NDC (always positive).
    half: vec2<f32>,
};

@group(0) @binding(0) var<uniform> quad: Quad;
@group(0) @binding(1) var src_tex: texture_2d<f32>;
@group(0) @binding(2) var src_smp: sampler;

struct VsOut {
    @builtin(position) clip: vec4<f32>,
    @location(0) uv: vec2<f32>,
};

@vertex
fn vs(@builtin(vertex_index) vi: u32) -> VsOut {
    let corner = vec2<f32>(f32(vi & 1u), f32((vi >> 1u) & 1u));

    // corner is y-down; NDC is y-up, hence the minus on y.
    let ndc = vec2<f32>(
        quad.centre.x + (corner.x * 2.0 - 1.0) * quad.half.x,
        quad.centre.y - (corner.y * 2.0 - 1.0) * quad.half.y,
    );

    var out: VsOut;
    out.clip = vec4<f32>(ndc, 0.0, 1.0);
    // corner doubles as the uv: top-left corner samples texel (0,0).
    out.uv = corner;
    return out;
}

@fragment
fn fs(in: VsOut) -> @location(0) vec4<f32> {
    // Plain copy: the frame is Rgba8Unorm and the swapchain is a NON-sRGB
    // format whenever the backend offers one, so these bytes land on screen
    // unchanged -- which is what makes the window and the retail screenshot
    // agree. On an sRGB-only swapchain the caller samples an sRGB view of the
    // frame instead (sample-decode + write-encode is the identity), so either
    // way this line stays a copy. The nearest sampler plus a ClampToEdge address
    // mode means uv == 1.0 lands on the last texel, not on a wrapped neighbour.
    return textureSample(src_tex, src_smp, in.uv);
}
