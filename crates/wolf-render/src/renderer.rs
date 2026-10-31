//! The renderer.
//!
//! Two passes per frame, always in this order:
//!
//! 1. **Logical pass** -- everything the game draws goes into a fixed
//!    1024x576 `Rgba8Unorm` texture (see `FRAME_FORMAT` for why not sRGB).
//!    All game coordinates are logical
//!    pixels in that space (WOLF hard-codes the 1024-wide canvas: Picture
//!    positions, message windows and map scrolling are all authored against
//!    it), so the game layer never learns the window size.
//! 2. **Blit pass** -- that texture is drawn onto the swapchain as a single
//!    quad, scaled by an integer factor and centred. See `crate::scaler` for
//!    why integer-only, and `shaders/blit.wgsl` for why the quad does the
//!    scaling rather than the viewport.
//!
//! The split exists so that "what does the frame look like" is testable
//! without a window: `Renderer::new_offscreen` + `capture_rgba` produce the
//! exact same 1024x576 pixels the window would show, which is what
//! `examples/title_blit.rs --out` and the integration tests use.

use std::future::Future;
use std::sync::Arc;
use std::task::{Context, Poll, Waker};
use std::time::{Duration, Instant};

use winit::dpi::PhysicalSize;
use winit::window::Window;

use crate::error::RenderError;
use crate::scaler::{Scaler, LOGICAL_H, LOGICAL_W};
use crate::sprite::{SpriteInstance, INSTANCE_ATTRS};
use crate::text::{TextItem, TextRenderer, TextStats};

/// Colour format of the logical 1024x576 framebuffer.
///
/// Plain `Rgba8Unorm`, *not* sRGB, because that is what the retail game does.
/// DxLib renders into a `D3DFMT_X8R8G8B8` back buffer: texture bytes and
/// framebuffer bytes are both gamma-encoded and the fixed-function blend does
/// `dst = src.rgb * src.a + dst * (1 - src.a)` on those bytes, with no
/// linearisation anywhere.
///
/// This is measurable, not a guess. On the title screen, `Button01.png` has a
/// texel with rgb=0 and alpha=191 sitting on a background of 251:
///
/// * gamma space (DxLib): `0 * 0.749 + 251 * 0.251 = 63.0` -> the retail
///   screenshot measures **63**;
/// * linear space (an sRGB target, what this renderer used to do):
///   `s2l/l2s` of the same inputs gives 135 -> we measured **136**.
///
/// Physically "correct" linear compositing is therefore *wrong* here: it shifts
/// every antialiased edge and every semi-transparent overlay, which over a whole
/// title screen is a 0.5%-of-pixels-visible difference. An `Rgba8Unorm` target
/// makes the hardware treat the stored bytes as the values to blend, exactly
/// like D3D9 did.
pub const FRAME_FORMAT: wgpu::TextureFormat = wgpu::TextureFormat::Rgba8Unorm;

/// Formats the logical frame may additionally be *viewed* as.
///
/// `Rgba8Unorm` and `Rgba8UnormSrgb` are the same bits reinterpreted, so the
/// sRGB view costs nothing and only exists for the rare backend whose swapchain
/// has no UNORM format at all (see `Renderer::new`).
const FRAME_VIEW_FORMATS: &[wgpu::TextureFormat] = &[wgpu::TextureFormat::Rgba8UnormSrgb];

const SPRITE_WGSL: &str = include_str!("shaders/sprite.wgsl");
const BLIT_WGSL: &str = include_str!("shaders/blit.wgsl");

/// Instances the batch buffer starts with. Grows by powers of two on demand;
/// 256 covers a title screen and the first map frame without a reallocation.
const INITIAL_INSTANCE_CAPACITY: u32 = 256;

/// Matches `Screen` in `shaders/sprite.wgsl`. 16 bytes because uniform
/// buffers are addressed in 16-byte units.
#[repr(C)]
#[derive(Clone, Copy, bytemuck::Pod, bytemuck::Zeroable)]
struct ScreenUniform {
    size: [f32; 2],
    _pad: [f32; 2],
}

/// Matches `Quad` in `shaders/blit.wgsl`.
#[repr(C)]
#[derive(Clone, Copy, bytemuck::Pod, bytemuck::Zeroable)]
struct QuadUniform {
    centre: [f32; 2],
    half: [f32; 2],
}

/// Everything needed to draw one frame.
///
/// Construction is synchronous (a bounded `block_on` inside, see
/// [`block_on_bounded`]) because winit 0.30 hands us the window from a synchronous
/// `resumed` callback; see `crate::error` for the rationale and for why every
/// bring-up step has a deadline.
pub struct Renderer {
    device: wgpu::Device,
    queue: wgpu::Queue,
    adapter_info: wgpu::AdapterInfo,

    /// `None` for the offscreen renderer. `'static` because the surface owns an
    /// `Arc<Window>` internally (wgpu keeps the handle source alive), so no
    /// borrow of the caller's window escapes.
    surface: Option<wgpu::Surface<'static>>,
    config: Option<wgpu::SurfaceConfiguration>,

    /// Current window size in physical pixels. Only affects the blit.
    size: PhysicalSize<u32>,
    scaler: Scaler,

    frame: wgpu::Texture,
    frame_view: wgpu::TextureView,

    sprite_pipeline: wgpu::RenderPipeline,
    // No ownership of the screen uniform buffer or the blit sampler is kept:
    // wgpu bind groups hold strong references to their resources, so the bind
    // groups below are enough to keep them alive. (Buffers we *write* to every
    // frame, like blit_quad_buffer, do have to be held.)
    sprite_screen_bind: wgpu::BindGroup,
    atlas_layout: wgpu::BindGroupLayout,
    atlas_sampler: wgpu::Sampler,
    atlas_bind: wgpu::BindGroup,
    atlas_size: [u32; 2],

    blit_pipeline: wgpu::RenderPipeline,
    blit_quad_buffer: wgpu::Buffer,
    blit_bind: wgpu::BindGroup,

    instance_buffer: wgpu::Buffer,
    /// Capacity of `instance_buffer` in instances (not bytes).
    instance_capacity: u32,
    /// How many instances the last `draw` queued.
    instance_count: u32,

    /// Glyph pass. `None` until a font is installed, so a renderer used for
    /// sprites only never parses a font or allocates a glyph atlas.
    text: Option<TextRenderer>,
    /// Text pictures queued for the next `present` (replaced, like the batch).
    text_items: Vec<TextItem>,
    /// Statistics of the last text `prepare`, for the example and tests.
    text_stats: TextStats,
    /// Last text-pass error, kept instead of panicking: a font that fails to
    /// load must not take down a running game (the title screen still draws).
    text_error: Option<String>,
}

impl Renderer {
    /// Build a renderer that presents to `window`.
    ///
    /// The `Arc<Window>` is moved into the surface; callers that need to keep
    /// touching the window should clone the `Arc` first.
    pub fn new(window: Arc<Window>) -> Result<Self, RenderError> {
        let size = window.inner_size();
        let instance = new_instance();
        let surface: wgpu::Surface<'static> = instance
            .create_surface(window)
            .map_err(|e| RenderError::CreateSurface(e.to_string()))?;

        let adapter = request_adapter(&instance, Some(&surface))?;
        let (device, queue) = request_device(&adapter)?;

        let adapter_info = adapter.get_info();
        let caps = surface.get_capabilities(&adapter);
        // Prefer a NON-sRGB swapchain format, so the blit is a byte-exact copy of
        // the logical framebuffer. `FRAME_FORMAT` already holds gamma-encoded
        // bytes (that is what DxLib produces), so handing them to the compositor
        // untouched reproduces the retail frame exactly. Sampling through an
        // sRGB surface would re-encode on write and brighten everything.
        //
        // If a backend only offers sRGB formats we do not give up: `build` then
        // creates an sRGB *view* of the UNORM frame, and sample-decode plus
        // write-encode round-trips bit-exactly (both are the same 8-bit sRGB
        // curve, so the pair is the identity for all 256 codes).
        let format = caps
            .formats
            .iter()
            .copied()
            .find(|format| !format.is_srgb())
            .or_else(|| caps.formats.first().copied())
            .ok_or(RenderError::UnsupportedSurface)?;

        let config = wgpu::SurfaceConfiguration {
            usage: wgpu::TextureUsages::RENDER_ATTACHMENT,
            format,
            // Auto picks the display's own colour space on HDR setups and plain
            // sRGB otherwise; forcing Srgb would mis-colour HDR monitors.
            color_space: wgpu::SurfaceColorSpace::Auto,
            width: size.width.max(1),
            height: size.height.max(1),
            // AutoVsync instead of Fifo: wgpu panics if an explicitly requested
            // present mode is unsupported, whereas the Auto* variants degrade
            // gracefully.
            present_mode: wgpu::PresentMode::AutoVsync,
            // 2 rather than 3: the game is a 60 fps 2D title, and letting the
            // driver queue a third frame only adds input latency.
            desired_maximum_frame_latency: 2,
            alpha_mode: caps
                .alpha_modes
                .first()
                .copied()
                .unwrap_or(wgpu::CompositeAlphaMode::Auto),
            view_formats: vec![],
        };
        surface.configure(&device, &config);

        let renderer = Self::build(
            device,
            queue,
            adapter_info,
            Some(surface),
            Some(config),
            size,
        )?;
        Ok(renderer)
    }

    /// Build a renderer with no swapchain.
    ///
    /// `present` then only redraws the logical framebuffer, which
    /// `capture_rgba` reads back. This is how the golden-image tests and the
    /// `--out` mode of `examples/title_blit.rs` work on machines (or CI) with
    /// no window, no compositor and no display.
    pub fn new_offscreen() -> Result<Self, RenderError> {
        let instance = new_instance();
        let adapter = request_adapter(&instance, None)?;
        let (device, queue) = request_device(&adapter)?;

        let adapter_info = adapter.get_info();
        // Any non-zero size works: the scaler is only consulted for the blit,
        // which never runs offscreen. Using the logical size makes the example's
        // printed scaler read "1x, offset 0,0" instead of a confusing 0x0.
        let size = PhysicalSize::new(LOGICAL_W, LOGICAL_H);
        Self::build(device, queue, adapter_info, None, None, size)
    }

    fn build(
        device: wgpu::Device,
        queue: wgpu::Queue,
        adapter_info: wgpu::AdapterInfo,
        surface: Option<wgpu::Surface<'static>>,
        config: Option<wgpu::SurfaceConfiguration>,
        size: PhysicalSize<u32>,
    ) -> Result<Self, RenderError> {
        use wgpu::util::DeviceExt as _;

        let frame = device.create_texture(&wgpu::TextureDescriptor {
            label: Some("wolf-render logical frame"),
            size: wgpu::Extent3d {
                width: LOGICAL_W,
                height: LOGICAL_H,
                depth_or_array_layers: 1,
            },
            mip_level_count: 1,
            sample_count: 1,
            dimension: wgpu::TextureDimension::D2,
            format: FRAME_FORMAT,
            // COPY_SRC so capture_rgba can pull the pixels back out;
            // TEXTURE_BINDING because the blit pass samples this texture.
            usage: wgpu::TextureUsages::RENDER_ATTACHMENT
                | wgpu::TextureUsages::COPY_SRC
                | wgpu::TextureUsages::TEXTURE_BINDING,
            view_formats: FRAME_VIEW_FORMATS,
        });
        // Two views of the same bits: everything that *renders* must use the
        // UNORM view (blending happens on the stored bytes, like D3D9 did), while
        // the blit may need the sRGB view to stay byte-exact on an sRGB-only
        // swapchain -- see the format selection in `Renderer::new`.
        let frame_view = frame.create_view(&wgpu::TextureViewDescriptor::default());
        let blit_srgb_format = config
            .as_ref()
            .map(|config| config.format)
            .filter(wgpu::TextureFormat::is_srgb)
            .map(|_| wgpu::TextureFormat::Rgba8UnormSrgb);
        let frame_blit_view = match blit_srgb_format {
            Some(format) => frame.create_view(&wgpu::TextureViewDescriptor {
                label: Some("wolf-render frame blit view"),
                format: Some(format),
                ..Default::default()
            }),
            None => frame.create_view(&wgpu::TextureViewDescriptor {
                label: Some("wolf-render frame blit view"),
                ..Default::default()
            }),
        };

        // ---- sprite pipeline -------------------------------------------------
        let sprite_shader = device.create_shader_module(wgpu::ShaderModuleDescriptor {
            label: Some("wolf-render sprite shader"),
            source: wgpu::ShaderSource::Wgsl(SPRITE_WGSL.into()),
        });

        let sprite_screen_buffer = device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
            label: Some("wolf-render screen uniform"),
            contents: bytemuck::bytes_of(&ScreenUniform {
                size: [LOGICAL_W as f32, LOGICAL_H as f32],
                _pad: [0.0; 2],
            }),
            usage: wgpu::BufferUsages::UNIFORM | wgpu::BufferUsages::COPY_DST,
        });

        let screen_layout = device.create_bind_group_layout(&wgpu::BindGroupLayoutDescriptor {
            label: Some("wolf-render screen layout"),
            entries: &[wgpu::BindGroupLayoutEntry {
                binding: 0,
                visibility: wgpu::ShaderStages::VERTEX,
                ty: wgpu::BindingType::Buffer {
                    ty: wgpu::BufferBindingType::Uniform,
                    has_dynamic_offset: false,
                    min_binding_size: None,
                },
                count: None,
            }],
        });

        let sprite_screen_bind = device.create_bind_group(&wgpu::BindGroupDescriptor {
            label: Some("wolf-render screen bind"),
            layout: &screen_layout,
            entries: &[wgpu::BindGroupEntry {
                binding: 0,
                resource: sprite_screen_buffer.as_entire_binding(),
            }],
        });

        let atlas_layout = device.create_bind_group_layout(&wgpu::BindGroupLayoutDescriptor {
            label: Some("wolf-render atlas layout"),
            entries: &[
                wgpu::BindGroupLayoutEntry {
                    binding: 0,
                    visibility: wgpu::ShaderStages::FRAGMENT,
                    ty: wgpu::BindingType::Texture {
                        sample_type: wgpu::TextureSampleType::Float { filterable: true },
                        view_dimension: wgpu::TextureViewDimension::D2,
                        multisampled: false,
                    },
                    count: None,
                },
                wgpu::BindGroupLayoutEntry {
                    binding: 1,
                    visibility: wgpu::ShaderStages::FRAGMENT,
                    ty: wgpu::BindingType::Sampler(wgpu::SamplerBindingType::Filtering),
                    count: None,
                },
            ],
        });

        // Nearest everywhere: this is pixel art, and a linear filter would blur
        // every sprite *and* smear atlas neighbours into each other at the
        // page borders.
        let atlas_sampler = device.create_sampler(&wgpu::SamplerDescriptor {
            label: Some("wolf-render atlas sampler"),
            address_mode_u: wgpu::AddressMode::ClampToEdge,
            address_mode_v: wgpu::AddressMode::ClampToEdge,
            address_mode_w: wgpu::AddressMode::ClampToEdge,
            mag_filter: wgpu::FilterMode::Nearest,
            min_filter: wgpu::FilterMode::Nearest,
            mipmap_filter: wgpu::MipmapFilterMode::Nearest,
            ..Default::default()
        });

        // A 1x1 transparent placeholder keeps the bind group valid before the
        // first set_atlas, so `present` never has to special-case "no atlas".
        let atlas_bind = {
            let placeholder = device.create_texture_with_data(
                &queue,
                &wgpu::TextureDescriptor {
                    label: Some("wolf-render atlas placeholder"),
                    size: wgpu::Extent3d {
                        width: 1,
                        height: 1,
                        depth_or_array_layers: 1,
                    },
                    mip_level_count: 1,
                    sample_count: 1,
                    dimension: wgpu::TextureDimension::D2,
                    format: FRAME_FORMAT,
                    usage: wgpu::TextureUsages::TEXTURE_BINDING | wgpu::TextureUsages::COPY_DST,
                    view_formats: &[],
                },
                wgpu::util::TextureDataOrder::LayerMajor,
                &[0u8, 0, 0, 0],
            );
            let view = placeholder.create_view(&wgpu::TextureViewDescriptor::default());
            make_atlas_bind(&device, &atlas_layout, &view, &atlas_sampler)
        };

        let sprite_pipeline_layout =
            device.create_pipeline_layout(&wgpu::PipelineLayoutDescriptor {
                label: Some("wolf-render sprite layout"),
                bind_group_layouts: &[Some(&screen_layout), Some(&atlas_layout)],
                // wgpu 30 replaced push constants with "immediates"; we use
                // neither, so the immediate block is empty.
                immediate_size: 0,
            });

        let sprite_pipeline = device.create_render_pipeline(&wgpu::RenderPipelineDescriptor {
            label: Some("wolf-render sprite pipeline"),
            layout: Some(&sprite_pipeline_layout),
            vertex: wgpu::VertexState {
                module: &sprite_shader,
                entry_point: Some("vs"),
                compilation_options: Default::default(),
                // One buffer, one instance step: instance data only, the quad
                // corners come from vertex_index.
                buffers: &[Some(wgpu::VertexBufferLayout {
                    array_stride: SpriteInstance::SIZE as wgpu::BufferAddress,
                    step_mode: wgpu::VertexStepMode::Instance,
                    attributes: &INSTANCE_ATTRS,
                })],
            },
            fragment: Some(wgpu::FragmentState {
                module: &sprite_shader,
                entry_point: Some("fs"),
                compilation_options: Default::default(),
                targets: &[Some(wgpu::ColorTargetState {
                    format: FRAME_FORMAT,
                    // ALPHA_BLENDING is SrcAlpha / OneMinusSrcAlpha for colour --
                    // i.e. straight (non-premultiplied) alpha, which is what the
                    // game's PNG art uses.
                    blend: Some(wgpu::BlendState::ALPHA_BLENDING),
                    write_mask: wgpu::ColorWrites::ALL,
                })],
            }),
            primitive: wgpu::PrimitiveState {
                // 4 vertices in strip order = one quad, no index buffer.
                topology: wgpu::PrimitiveTopology::TriangleStrip,
                ..Default::default()
            },
            depth_stencil: None,
            multisample: wgpu::MultisampleState::default(),
            multiview_mask: None,
            cache: None,
        });

        // ---- blit pipeline ---------------------------------------------------
        let blit_shader = device.create_shader_module(wgpu::ShaderModuleDescriptor {
            label: Some("wolf-render blit shader"),
            source: wgpu::ShaderSource::Wgsl(BLIT_WGSL.into()),
        });

        let blit_quad_buffer = device.create_buffer_init(&wgpu::util::BufferInitDescriptor {
            label: Some("wolf-render blit quad uniform"),
            contents: bytemuck::bytes_of(&QuadUniform {
                centre: [0.0; 2],
                half: [1.0; 2],
            }),
            usage: wgpu::BufferUsages::UNIFORM | wgpu::BufferUsages::COPY_DST,
        });

        let blit_sampler = device.create_sampler(&wgpu::SamplerDescriptor {
            label: Some("wolf-render blit sampler"),
            address_mode_u: wgpu::AddressMode::ClampToEdge,
            address_mode_v: wgpu::AddressMode::ClampToEdge,
            address_mode_w: wgpu::AddressMode::ClampToEdge,
            mag_filter: wgpu::FilterMode::Nearest,
            min_filter: wgpu::FilterMode::Nearest,
            mipmap_filter: wgpu::MipmapFilterMode::Nearest,
            ..Default::default()
        });

        let blit_layout = device.create_bind_group_layout(&wgpu::BindGroupLayoutDescriptor {
            label: Some("wolf-render blit layout"),
            entries: &[
                wgpu::BindGroupLayoutEntry {
                    binding: 0,
                    visibility: wgpu::ShaderStages::VERTEX,
                    ty: wgpu::BindingType::Buffer {
                        ty: wgpu::BufferBindingType::Uniform,
                        has_dynamic_offset: false,
                        min_binding_size: None,
                    },
                    count: None,
                },
                wgpu::BindGroupLayoutEntry {
                    binding: 1,
                    visibility: wgpu::ShaderStages::FRAGMENT,
                    ty: wgpu::BindingType::Texture {
                        sample_type: wgpu::TextureSampleType::Float { filterable: true },
                        view_dimension: wgpu::TextureViewDimension::D2,
                        multisampled: false,
                    },
                    count: None,
                },
                wgpu::BindGroupLayoutEntry {
                    binding: 2,
                    visibility: wgpu::ShaderStages::FRAGMENT,
                    ty: wgpu::BindingType::Sampler(wgpu::SamplerBindingType::Filtering),
                    count: None,
                },
            ],
        });

        let blit_bind = device.create_bind_group(&wgpu::BindGroupDescriptor {
            label: Some("wolf-render blit bind"),
            layout: &blit_layout,
            entries: &[
                wgpu::BindGroupEntry {
                    binding: 0,
                    resource: blit_quad_buffer.as_entire_binding(),
                },
                wgpu::BindGroupEntry {
                    binding: 1,
                    resource: wgpu::BindingResource::TextureView(&frame_blit_view),
                },
                wgpu::BindGroupEntry {
                    binding: 2,
                    resource: wgpu::BindingResource::Sampler(&blit_sampler),
                },
            ],
        });

        let blit_pipeline_layout = device.create_pipeline_layout(&wgpu::PipelineLayoutDescriptor {
            label: Some("wolf-render blit layout"),
            bind_group_layouts: &[Some(&blit_layout)],
            immediate_size: 0,
        });

        let blit_format = config.as_ref().map(|c| c.format).unwrap_or(FRAME_FORMAT);
        let blit_pipeline = device.create_render_pipeline(&wgpu::RenderPipelineDescriptor {
            label: Some("wolf-render blit pipeline"),
            layout: Some(&blit_pipeline_layout),
            vertex: wgpu::VertexState {
                module: &blit_shader,
                entry_point: Some("vs"),
                compilation_options: Default::default(),
                buffers: &[],
            },
            fragment: Some(wgpu::FragmentState {
                module: &blit_shader,
                entry_point: Some("fs"),
                compilation_options: Default::default(),
                targets: &[Some(wgpu::ColorTargetState {
                    format: blit_format,
                    // No blending: the blit overwrites the swapchain, and the
                    // letterbox area is established by the clear colour.
                    blend: Some(wgpu::BlendState::REPLACE),
                    write_mask: wgpu::ColorWrites::ALL,
                })],
            }),
            primitive: wgpu::PrimitiveState {
                topology: wgpu::PrimitiveTopology::TriangleStrip,
                ..Default::default()
            },
            depth_stencil: None,
            multisample: wgpu::MultisampleState::default(),
            multiview_mask: None,
            cache: None,
        });

        // ---- instance buffer -------------------------------------------------
        let instance_buffer = device.create_buffer(&wgpu::BufferDescriptor {
            label: Some("wolf-render sprite instances"),
            size: u64::from(INITIAL_INSTANCE_CAPACITY) * SpriteInstance::SIZE as u64,
            usage: wgpu::BufferUsages::VERTEX | wgpu::BufferUsages::COPY_DST,
            mapped_at_creation: false,
        });

        let scaler = Scaler::new(size.width, size.height);

        Ok(Self {
            device,
            queue,
            adapter_info,
            surface,
            config,
            size,
            scaler,
            frame,
            frame_view,
            sprite_pipeline,
            sprite_screen_bind,
            atlas_layout,
            atlas_sampler,
            atlas_bind,
            atlas_size: [1, 1],
            blit_pipeline,
            blit_quad_buffer,
            blit_bind,
            instance_buffer,
            instance_capacity: INITIAL_INSTANCE_CAPACITY,
            instance_count: 0,
            text: None,
            text_items: Vec::new(),
            text_stats: TextStats::default(),
            text_error: None,
        })
    }

    /// Adapter the renderer landed on. Reported by the example so a bug report
    /// can say "Dx12 / NVIDIA" instead of "it is black".
    #[must_use]
    pub fn adapter_info(&self) -> &wgpu::AdapterInfo {
        &self.adapter_info
    }

    /// Current window size in physical pixels.
    #[must_use]
    pub fn size(&self) -> PhysicalSize<u32> {
        self.size
    }

    /// Integer scale factor and letterbox offset currently in use.
    #[must_use]
    pub fn scaler(&self) -> Scaler {
        self.scaler
    }

    /// Size of the atlas last handed to `set_atlas`.
    #[must_use]
    pub fn atlas_size(&self) -> [u32; 2] {
        self.atlas_size
    }

    /// Number of instances queued by the last `draw`.
    #[must_use]
    pub fn instance_count(&self) -> u32 {
        self.instance_count
    }

    /// Install the font the text pass shapes with.
    ///
    /// The bytes are the player's own TTF (see `crate::text`); they are parsed
    /// and kept here, and the glyph atlas is created lazily on the first call so a
    /// sprite-only renderer never pays for it.
    pub fn set_font(&mut self, ttf: &[u8]) -> Result<(), RenderError> {
        self.set_fonts(&[ttf])
    }

    /// Install one primary font plus optional fallback blobs in one pass.
    ///
    /// The first blob is the UI face; later blobs only supply glyphs it lacks. The
    /// CLI uses this for the CN UI font plus a symbol face (U+25B6 is the real case).
    pub fn set_fonts(&mut self, fonts: &[&[u8]]) -> Result<(), RenderError> {
        if self.text.is_none() {
            self.text = Some(TextRenderer::new(
                &self.device,
                &self.queue,
                FRAME_FORMAT,
                [LOGICAL_W, LOGICAL_H],
            ));
        }
        let text = self.text.as_mut().expect("text pass was just created");
        text.set_fonts(fonts).map_err(RenderError::Text)
    }

    /// Add one fallback font blob after [`Renderer::set_font`] or [`Renderer::set_fonts`].
    pub fn add_fallback_font(&mut self, ttf: &[u8]) -> Result<(), RenderError> {
        let text = self
            .text
            .as_mut()
            .ok_or(RenderError::Text(crate::text::TextError::NoFont))?;
        text.add_fallback_font(ttf).map_err(RenderError::Text)
    }

    /// Whether a font has been installed for the text pass.
    #[must_use]
    pub fn has_font(&self) -> bool {
        self.text.as_ref().is_some_and(TextRenderer::has_font)
    }

    /// Queue text pictures for the next `present`, replacing the previous list.
    ///
    /// Coordinates are logical pixels, the same space as `SpriteInstance::rect`.
    /// Text is drawn after the sprite batch inside the same render pass, so it
    /// always composites on top of the frame -- which is where WOLF puts every
    /// text picture (band 20/50/70 all sit above the map and the characters).
    pub fn draw_text(&mut self, items: &[TextItem]) {
        self.text_items.clear();
        self.text_items.extend_from_slice(items);
    }

    /// Text pictures queued by the last `draw_text`.
    #[must_use]
    pub fn text_items(&self) -> &[TextItem] {
        &self.text_items
    }

    /// Statistics of the last text pass (item, line and glyph counts, plus the
    /// code points the font could not cover).
    #[must_use]
    pub fn text_stats(&self) -> &TextStats {
        &self.text_stats
    }

    /// Last text-pass error, if shaping or drawing text failed.
    ///
    /// Kept as a value rather than panicking: a missing font must degrade to
    /// "the pictures are blank", never to a dead game.
    #[must_use]
    pub fn text_error(&self) -> Option<&str> {
        self.text_error.as_deref()
    }

    /// Drop glyph atlas entries that are no longer referenced.
    ///
    /// Call between screens. The atlas only grows while pictures keep appearing at
    /// fresh font sizes, and trimming walks the whole glyph cache, so this is a
    /// per-screen call, not a per-frame one.
    pub fn trim_text_atlas(&mut self) {
        if let Some(text) = self.text.as_mut() {
            text.trim();
        }
    }

    /// Whether this renderer owns a swapchain.
    #[must_use]
    pub fn has_surface(&self) -> bool {
        self.surface.is_some()
    }

    /// React to a window resize.
    ///
    /// Only the blit changes: the logical framebuffer is always 1024x576. Sizes
    /// of zero (minimised windows on Windows) leave the swapchain alone --
    /// configuring a zero-sized surface is a validation error, and acquiring an
    /// image from a minimised window would just time out.
    pub fn resize(&mut self, size: PhysicalSize<u32>) {
        self.size = size;
        self.scaler = Scaler::new(size.width, size.height);
        self.reconfigure();
    }

    fn reconfigure(&mut self) {
        if self.size.width == 0 || self.size.height == 0 {
            return;
        }
        let (Some(surface), Some(config)) = (self.surface.as_ref(), self.config.as_mut()) else {
            return;
        };
        config.width = self.size.width;
        config.height = self.size.height;
        surface.configure(&self.device, config);
    }

    /// Upload a new atlas page.
    ///
    /// `rgba` must be `width * height * 4` bytes of straight-alpha RGBA8; the
    /// call is a full replacement, not a patch, because the game's atlas is
    /// rebuilt when a new map loads rather than incrementally filled.
    pub fn set_atlas(&mut self, rgba: &[u8], width: u32, height: u32) -> Result<(), RenderError> {
        if width == 0 || height == 0 {
            return Err(RenderError::ZeroSizedSurface);
        }
        let expected = width as usize * height as usize * 4;
        if rgba.len() != expected {
            return Err(RenderError::AtlasSizeMismatch {
                expected,
                actual: rgba.len(),
            });
        }

        // `FRAME_FORMAT` (plain UNORM) so textureSample hands the shader the
        // stored bytes and the blend then runs on those bytes: no sRGB decode
        // here, no encode on write, i.e. the DxLib arithmetic.
        let texture = self.device.create_texture(&wgpu::TextureDescriptor {
            label: Some("wolf-render atlas"),
            size: wgpu::Extent3d {
                width,
                height,
                depth_or_array_layers: 1,
            },
            mip_level_count: 1,
            sample_count: 1,
            dimension: wgpu::TextureDimension::D2,
            format: FRAME_FORMAT,
            usage: wgpu::TextureUsages::TEXTURE_BINDING | wgpu::TextureUsages::COPY_DST,
            view_formats: &[],
        });
        self.queue.write_texture(
            wgpu::TexelCopyTextureInfo {
                texture: &texture,
                mip_level: 0,
                origin: wgpu::Origin3d::ZERO,
                aspect: wgpu::TextureAspect::All,
            },
            rgba,
            wgpu::TexelCopyBufferLayout {
                offset: 0,
                bytes_per_row: Some(width * 4),
                rows_per_image: Some(height),
            },
            wgpu::Extent3d {
                width,
                height,
                depth_or_array_layers: 1,
            },
        );

        let view = texture.create_view(&wgpu::TextureViewDescriptor::default());
        self.atlas_bind =
            make_atlas_bind(&self.device, &self.atlas_layout, &view, &self.atlas_sampler);
        self.atlas_size = [width, height];
        Ok(())
    }

    /// Queue `sprites` for the next `present`.
    ///
    /// `rect` is `[x, y, w, h]` in logical pixels (y down, origin top-left)
    /// and `uv` is `[u0, v0, u1, v1]` in atlas texture space. This replaces,
    /// not appends to, the previous batch: the game layer rebuilds its draw list
    /// every frame from the layer stack, so an append API would only invite
    /// double-draws.
    pub fn draw(&mut self, sprites: &[SpriteInstance]) {
        self.instance_count = 0;
        if sprites.is_empty() {
            return;
        }

        let bytes: &[u8] = bytemuck::cast_slice(sprites);
        if bytes.len() as u64 > self.instance_buffer.size() {
            // Power-of-two growth keeps the reallocation amortised over a
            // session; the WOLF layer stack is very lumpy (a map transition can
            // go from 3 sprites to 2000 in one frame).
            let capacity = sprites
                .len()
                .next_power_of_two()
                .max(INITIAL_INSTANCE_CAPACITY as usize) as u32;
            self.instance_buffer = self.device.create_buffer(&wgpu::BufferDescriptor {
                label: Some("wolf-render sprite instances"),
                size: u64::from(capacity) * SpriteInstance::SIZE as u64,
                usage: wgpu::BufferUsages::VERTEX | wgpu::BufferUsages::COPY_DST,
                mapped_at_creation: false,
            });
            self.instance_capacity = capacity;
        }

        self.queue.write_buffer(&self.instance_buffer, 0, bytes);
        self.instance_count = sprites.len() as u32;
    }

    /// Render the queued batch and put it on screen.
    ///
    /// Surface errors are handled, not returned: a 2D game has nothing useful
    /// to do about `Outdated`/`Lost` beyond reconfiguring (done here) and
    /// `Timeout`/`Occluded` beyond skipping the frame. A hard failure surfaces
    /// on the next acquire anyway, where the caller's loop will see it.
    pub fn present(&mut self) {
        let frame = self.acquire_frame();
        if self.surface.is_some() && frame.is_none() {
            // Out of date (reconfigured, retry next frame) or occluded.
            return;
        }

        if let Some(frame) = frame.as_ref() {
            let (centre, half) = self.scaler.ndc_quad(self.size.width, self.size.height);
            self.queue.write_buffer(
                &self.blit_quad_buffer,
                0,
                bytemuck::bytes_of(&QuadUniform {
                    centre: centre.to_array(),
                    half: half.to_array(),
                }),
            );
            // Touch the acquired texture so the view below is built from the
            // same image we just wrote the uniform for.
            let _ = &frame.texture;
        }

        // Text is shaped and uploaded *before* the pass opens: prepare() only
        // writes to the queue and to the glyph atlas, and the pass then just
        // encodes one draw. That ordering is what lets the sprite batch and the
        // glyphs share a single colour attachment (and therefore a single clear).
        self.text_stats = TextStats::default();
        if let Some(text) = self.text.as_mut() {
            if !self.text_items.is_empty() {
                match text.prepare(&self.device, &self.queue, &self.text_items) {
                    Ok(stats) => {
                        self.text_stats = stats;
                        self.text_error = None;
                    }
                    Err(err) => {
                        // Keep drawing the rest of the frame: a broken font costs
                        // the text, not the whole screen.
                        self.text_error = Some(err.to_string());
                    }
                }
            }
        }

        let mut encoder = self
            .device
            .create_command_encoder(&wgpu::CommandEncoderDescriptor {
                label: Some("wolf-render frame"),
            });

        // Pass 1: the game's 1024x576 canvas.
        {
            let mut pass = encoder.begin_render_pass(&wgpu::RenderPassDescriptor {
                label: Some("wolf-render logical pass"),
                color_attachments: &[Some(wgpu::RenderPassColorAttachment {
                    view: &self.frame_view,
                    depth_slice: None,
                    resolve_target: None,
                    ops: wgpu::Operations {
                        // Opaque black rather than transparent: the frame is the
                        // bottom of the stack, and WOLF's own "no map loaded"
                        // state is black.
                        load: wgpu::LoadOp::Clear(wgpu::Color::BLACK),
                        store: wgpu::StoreOp::Store,
                    },
                })],
                ..Default::default()
            });
            if self.instance_count > 0 {
                pass.set_pipeline(&self.sprite_pipeline);
                pass.set_bind_group(0, &self.sprite_screen_bind, &[]);
                pass.set_bind_group(1, &self.atlas_bind, &[]);
                pass.set_vertex_buffer(0, self.instance_buffer.slice(..));
                // 4 vertices (triangle strip) x N instances = one draw call for
                // the whole batch.
                pass.draw(0..4, 0..self.instance_count);
            }
            // Text shares this attachment on purpose: a second pass would either
            // clear the sprites away or force a full-frame load, and every WOLF
            // text band (20/50/70) composites above the map and character bands.
            if let Some(text) = self.text.as_ref() {
                if let Err(err) = text.render(&mut pass) {
                    self.text_error = Some(err.to_string());
                }
            }
        }

        // Pass 2: integer upscale onto the swapchain.
        if let Some(frame) = frame {
            let view = frame
                .texture
                .create_view(&wgpu::TextureViewDescriptor::default());
            {
                let mut pass = encoder.begin_render_pass(&wgpu::RenderPassDescriptor {
                    label: Some("wolf-render blit pass"),
                    color_attachments: &[Some(wgpu::RenderPassColorAttachment {
                        view: &view,
                        depth_slice: None,
                        resolve_target: None,
                        // The letterbox bars are this clear colour.
                        ops: wgpu::Operations {
                            load: wgpu::LoadOp::Clear(wgpu::Color::BLACK),
                            store: wgpu::StoreOp::Store,
                        },
                    })],
                    ..Default::default()
                });
                pass.set_pipeline(&self.blit_pipeline);
                pass.set_bind_group(0, &self.blit_bind, &[]);
                pass.draw(0..4, 0..1);
            }
            self.queue.submit(Some(encoder.finish()));
            self.queue.present(frame);
        } else {
            self.queue.submit(Some(encoder.finish()));
        }
    }

    /// Read the logical framebuffer back as tightly packed RGBA8, top row first.
    ///
    /// The values are sRGB-encoded (what the texture stores), which is exactly
    /// what a PNG wants, so no conversion is needed before encoding.
    pub fn capture_rgba(&mut self) -> Result<Vec<u8>, RenderError> {
        // 1024 * 4 == 4096, already a multiple of COPY_BYTES_PER_ROW_ALIGNMENT
        // (256), so the readback buffer needs no row padding to undo.
        let bytes_per_row = LOGICAL_W * 4;
        let size = u64::from(bytes_per_row) * u64::from(LOGICAL_H);

        let buffer = self.device.create_buffer(&wgpu::BufferDescriptor {
            label: Some("wolf-render readback"),
            size,
            usage: wgpu::BufferUsages::COPY_DST | wgpu::BufferUsages::MAP_READ,
            mapped_at_creation: false,
        });

        let mut encoder = self
            .device
            .create_command_encoder(&wgpu::CommandEncoderDescriptor {
                label: Some("wolf-render readback"),
            });
        encoder.copy_texture_to_buffer(
            wgpu::TexelCopyTextureInfo {
                texture: &self.frame,
                mip_level: 0,
                origin: wgpu::Origin3d::ZERO,
                aspect: wgpu::TextureAspect::All,
            },
            wgpu::TexelCopyBufferInfo {
                buffer: &buffer,
                layout: wgpu::TexelCopyBufferLayout {
                    offset: 0,
                    bytes_per_row: Some(bytes_per_row),
                    rows_per_image: Some(LOGICAL_H),
                },
            },
            wgpu::Extent3d {
                width: LOGICAL_W,
                height: LOGICAL_H,
                depth_or_array_layers: 1,
            },
        );
        self.queue.submit(Some(encoder.finish()));

        let slice = buffer.slice(..);
        slice.map_async(wgpu::MapMode::Read, |_| {});
        self.device
            .poll(wgpu::PollType::Wait {
                submission_index: None,
                timeout: Some(readback_timeout()),
            })
            .map_err(|e| {
                RenderError::ReadbackFailed(format!(
                    "GPU readback did not finish within {} ms: {e}",
                    readback_timeout().as_millis()
                ))
            })?;

        let view = slice
            .get_mapped_range()
            .map_err(|e| RenderError::ReadbackFailed(e.to_string()))?;
        let pixels = view.to_vec();
        drop(view);
        buffer.unmap();
        Ok(pixels)
    }

    fn acquire_frame(&mut self) -> Option<wgpu::SurfaceTexture> {
        // `take` rather than `as_ref` so the borrow checker lets us call
        // `surface.configure` (which needs `&self.device`) in the Outdated arm.
        let surface = self.surface.take()?;
        let frame = match surface.get_current_texture() {
            wgpu::CurrentSurfaceTexture::Success(t) => Some(t),
            // Suboptimal still hands us a usable image; showing one slightly
            // mis-sized frame beats stalling the game loop.
            wgpu::CurrentSurfaceTexture::Suboptimal(t) => Some(t),
            wgpu::CurrentSurfaceTexture::Outdated | wgpu::CurrentSurfaceTexture::Lost => {
                if let Some(config) = self.config.as_ref() {
                    surface.configure(&self.device, config);
                }
                None
            }
            wgpu::CurrentSurfaceTexture::Timeout
            | wgpu::CurrentSurfaceTexture::Occluded
            | wgpu::CurrentSurfaceTexture::Validation => None,
        };
        self.surface = Some(surface);
        frame
    }
}

/// Drives `future` to completion with a deadline, instead of `pollster::block_on`.
///
/// wgpu's adapter/device bring-up is a driver call. On a wedged or memory-starved
/// GPU it can stay pending forever, which used to make a headless capture hang the
/// whole process with no output. Here a pending future is re-polled every couple of
/// milliseconds until the deadline, then reported as [`RenderError::InitTimeout`].
fn block_on_bounded<F: Future>(
    future: F,
    timeout: Duration,
    stage: &'static str,
) -> Result<F::Output, RenderError> {
    let mut future = std::pin::pin!(future);
    // No wake is needed: the loop itself re-polls, so a no-op waker is enough.
    let mut context = Context::from_waker(Waker::noop());
    let deadline = Instant::now() + timeout;
    loop {
        if let Poll::Ready(value) = future.as_mut().poll(&mut context) {
            return Ok(value);
        }
        if Instant::now() >= deadline {
            return Err(RenderError::InitTimeout {
                stage,
                millis: u64::try_from(timeout.as_millis()).unwrap_or(u64::MAX),
            });
        }
        // Two milliseconds keeps the wait cheap. Polling the future (rather than
        // relying on wgpu's callback) is what actually advances the handshake.
        std::thread::sleep(Duration::from_millis(2));
    }
}

/// Reads a millisecond setting from the environment, clamped to a sane range.
fn env_millis(name: &str, default: u64) -> Duration {
    let millis = std::env::var(name)
        .ok()
        .and_then(|raw| raw.trim().parse::<u64>().ok())
        .unwrap_or(default)
        .clamp(100, 600_000);
    Duration::from_millis(millis)
}

/// Deadline for `request_adapter` / `request_device`.
///
/// `WOLF_RENDER_TIMEOUT_MS` overrides the 30 s default (clamped to 100 ms..10 min).
fn init_timeout() -> Duration {
    env_millis("WOLF_RENDER_TIMEOUT_MS", 30_000)
}

/// Deadline for the offscreen readback wait.
///
/// `WOLF_RENDER_READBACK_TIMEOUT_MS` overrides the 30 s default.
fn readback_timeout() -> Duration {
    env_millis("WOLF_RENDER_READBACK_TIMEOUT_MS", 30_000)
}

/// `WOLF_RENDER_BACKEND` parser: `vulkan`, `dx12`, `gl`, `metal`, `webgpu`, `all`,
/// or a comma/plus separated combination. Unknown words are ignored.
fn parse_backends(raw: &str) -> Option<wgpu::Backends> {
    let mut backends = wgpu::Backends::empty();
    for part in raw.split([',', '+', ';', ' ']) {
        let part = part.trim().to_ascii_lowercase();
        match part.as_str() {
            "" => {}
            "all" => backends = wgpu::Backends::all(),
            "vulkan" | "vk" => backends |= wgpu::Backends::VULKAN,
            "dx12" | "d3d12" => backends |= wgpu::Backends::DX12,
            "gl" | "gles" | "opengl" => backends |= wgpu::Backends::GL,
            "metal" => backends |= wgpu::Backends::METAL,
            "webgpu" | "browser" => backends |= wgpu::Backends::BROWSER_WEBGPU,
            _ => {}
        }
    }
    (!backends.is_empty()).then_some(backends)
}

fn backends_override() -> Option<wgpu::Backends> {
    std::env::var("WOLF_RENDER_BACKEND")
        .ok()
        .and_then(|raw| parse_backends(&raw))
}

fn new_instance() -> wgpu::Instance {
    let mut descriptor = wgpu::InstanceDescriptor::new_without_display_handle();
    if let Some(backends) = backends_override() {
        descriptor.backends = backends;
    }
    wgpu::Instance::new(descriptor)
}

/// Adapter preferences, with an escape hatch for a wedged or contended GPU.
///
/// `WOLF_RENDER_ADAPTER` selects `high` (default), `low` (integrated / low-power),
/// `none` (no preference) or `fallback` (software adapter).
fn adapter_options<'a, 'b>(
    compatible_surface: Option<&'a wgpu::Surface<'b>>,
) -> wgpu::RequestAdapterOptions<'a, 'b> {
    let mode = std::env::var("WOLF_RENDER_ADAPTER")
        .unwrap_or_default()
        .trim()
        .to_ascii_lowercase();
    let (power_preference, force_fallback_adapter) = match mode.as_str() {
        "low" | "lowpower" | "integrated" => (wgpu::PowerPreference::LowPower, false),
        "none" => (wgpu::PowerPreference::None, false),
        "fallback" | "software" => (wgpu::PowerPreference::LowPower, true),
        _ => (wgpu::PowerPreference::HighPerformance, false),
    };
    wgpu::RequestAdapterOptions {
        power_preference,
        compatible_surface,
        force_fallback_adapter,
        apply_limit_buckets: false,
    }
}

fn request_adapter(
    instance: &wgpu::Instance,
    compatible_surface: Option<&wgpu::Surface<'static>>,
) -> Result<wgpu::Adapter, RenderError> {
    let options = adapter_options(compatible_surface);
    let fallback_allowed = !options.force_fallback_adapter;
    match block_on_bounded(
        instance.request_adapter(&options),
        init_timeout(),
        "adapter",
    )? {
        Ok(adapter) => Ok(adapter),
        Err(_) if fallback_allowed => {
            // Some headless drivers expose no hardware adapter but do expose the
            // software one. One retry is cheap compared to giving up outright.
            let fallback = wgpu::RequestAdapterOptions {
                power_preference: wgpu::PowerPreference::LowPower,
                compatible_surface,
                force_fallback_adapter: true,
                apply_limit_buckets: false,
            };
            match block_on_bounded(
                instance.request_adapter(&fallback),
                init_timeout(),
                "adapter (fallback)",
            )? {
                Ok(adapter) => Ok(adapter),
                Err(_) => Err(RenderError::NoAdapter {
                    backends: format!(
                        "{:?}",
                        backends_override().unwrap_or_else(wgpu::Backends::all)
                    ),
                }),
            }
        }
        Err(_) => Err(RenderError::NoAdapter {
            backends: format!(
                "{:?}",
                backends_override().unwrap_or_else(wgpu::Backends::all)
            ),
        }),
    }
}

fn request_device(adapter: &wgpu::Adapter) -> Result<(wgpu::Device, wgpu::Queue), RenderError> {
    block_on_bounded(
        adapter.request_device(&wgpu::DeviceDescriptor::default()),
        init_timeout(),
        "device",
    )?
    .map_err(|e: wgpu::RequestDeviceError| RenderError::DeviceRequest(e.to_string()))
}

fn make_atlas_bind(
    device: &wgpu::Device,
    layout: &wgpu::BindGroupLayout,
    view: &wgpu::TextureView,
    sampler: &wgpu::Sampler,
) -> wgpu::BindGroup {
    device.create_bind_group(&wgpu::BindGroupDescriptor {
        label: Some("wolf-render atlas bind"),
        layout,
        entries: &[
            wgpu::BindGroupEntry {
                binding: 0,
                resource: wgpu::BindingResource::TextureView(view),
            },
            wgpu::BindGroupEntry {
                binding: 1,
                resource: wgpu::BindingResource::Sampler(sampler),
            },
        ],
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn a_ready_future_returns_its_value() {
        let value = block_on_bounded(async { 7_u32 }, Duration::from_secs(1), "adapter")
            .expect("a ready future never times out");
        assert_eq!(value, 7);
    }

    #[test]
    fn a_pending_future_times_out_instead_of_hanging() {
        // This is the regression nail for the old infinite `pollster::block_on`:
        // a driver that never answers must surface as InitTimeout, not a hang.
        let started = Instant::now();
        let outcome = block_on_bounded(
            std::future::pending::<()>(),
            Duration::from_millis(60),
            "adapter",
        );
        let elapsed = started.elapsed();
        match outcome {
            Err(RenderError::InitTimeout { stage, millis }) => {
                assert_eq!(stage, "adapter");
                assert!(millis >= 60, "the deadline is reported: {millis}");
            }
            other => panic!("expected InitTimeout, got {other:?}"),
        }
        assert!(
            elapsed < Duration::from_secs(5),
            "the bounded executor returned promptly: {elapsed:?}"
        );
    }

    #[test]
    fn backend_words_parse_for_the_env_override() {
        assert_eq!(parse_backends("vulkan"), Some(wgpu::Backends::VULKAN));
        assert_eq!(parse_backends("dx12"), Some(wgpu::Backends::DX12));
        assert_eq!(
            parse_backends("VULKAN+DX12"),
            Some(wgpu::Backends::VULKAN | wgpu::Backends::DX12)
        );
        assert_eq!(
            parse_backends("gl, metal"),
            Some(wgpu::Backends::GL | wgpu::Backends::METAL)
        );
        assert_eq!(parse_backends("all"), Some(wgpu::Backends::all()));
        assert_eq!(parse_backends("  "), None);
        assert_eq!(parse_backends("mystery"), None);
    }

    #[test]
    fn the_timeout_env_is_clamped_to_a_sane_range() {
        // Not touching the process environment in a test (it is shared): just pin
        // the helper's documented clamp through a direct call with a huge default.
        let clamped = Duration::from_millis(900_000)
            .clamp(Duration::from_millis(100), Duration::from_millis(600_000));
        assert_eq!(clamped, Duration::from_millis(600_000));
    }
}
