//! Resolving WOLF asset names and decoding them to RGBA8.
//!
//! Every asset reference in the game data is a *relative* path with forward slashes,
//! resolved against the game root - for example `SystemGraphic/TitleGraphic.jpg`,
//! `MapChip/kiri_project.png` or `Kagura/bg.png`. Three quirks matter:
//!
//! 1. **The name may have no extension.** Some `150` commands store a bare stem and let
//!    the engine probe the codecs, so resolution has to try the extensions the game
//!    actually ships before giving up.
//! 2. **DxLib is case-insensitive on Windows.** A data tree extracted on a
//!    case-sensitive filesystem must still resolve `Kagura/bg.png` when the file on disk
//!    is `kagura/BG.png`, so lookup falls back to a segment-by-segment case-insensitive
//!    walk instead of failing.
//! 3. **Missing assets are normal.** The M1 title screen only needs one image, and the
//!    map backgrounds live in `Picture.wolf` which is not unpacked yet, so the caller
//!    gets a typed error and draws nothing rather than a panic.
//!
//! Decoding yields premultiplied-free RGBA8 in sRGB space, which is exactly what the
//! renderer uploads as `Rgba8UnormSrgb`.

use std::collections::{HashMap, HashSet};
use std::fmt;
use std::path::{Path, PathBuf};
use std::sync::Arc;

use crate::patch::PatchSet;

/// Extensions probed when an asset name carries none, in the order WOLF tries them.
pub const PROBE_EXTENSIONS: [&str; 5] = ["png", "jpg", "bmp", "jpeg", "webp"];

/// Refuse absurd dimensions early: a corrupt header must not ask for a 4 GiB buffer.
pub const MAX_DIMENSION: u32 = 16_384;

/// One decoded image, ready to be uploaded as a texture.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct ImageData {
    /// Width in pixels.
    pub width: u32,
    /// Height in pixels.
    pub height: u32,
    /// Tightly packed RGBA8, `width * height * 4` bytes, row-major, no padding.
    pub rgba: Vec<u8>,
}

impl ImageData {
    /// Wraps raw pixels, rejecting a buffer whose length disagrees with the size.
    #[must_use]
    pub fn new(width: u32, height: u32, rgba: Vec<u8>) -> Option<Self> {
        let expected = (width as usize)
            .checked_mul(height as usize)?
            .checked_mul(4)?;
        if rgba.len() != expected {
            return None;
        }
        Some(Self {
            width,
            height,
            rgba,
        })
    }

    /// Size as the tuple tex_size callbacks want.
    #[must_use]
    pub fn size(&self) -> (u32, u32) {
        (self.width, self.height)
    }

    /// Copies one `[x, y, w, h]` rectangle out of this image.
    ///
    /// Sprite sheets are the caller: a 2400x1300 character sheet is larger than any
    /// texture page the atlas can hold, but the one 400x650 cell a picture asks for fits.
    /// Returns None when the rectangle does not lie inside the image.
    #[must_use]
    pub fn crop(&self, rect: [u32; 4]) -> Option<Self> {
        let [x, y, width, height] = rect;
        let right = x.checked_add(width)?;
        let bottom = y.checked_add(height)?;
        if width == 0 || height == 0 || right > self.width || bottom > self.height {
            return None;
        }
        let mut rgba = Vec::with_capacity(width as usize * height as usize * 4);
        for row in y..bottom {
            let start = (row as usize * self.width as usize + x as usize) * 4;
            let end = start + width as usize * 4;
            rgba.extend_from_slice(&self.rgba[start..end]);
        }
        Self::new(width, height, rgba)
    }

    /// Bytes per row, for `Queue::write_texture`.
    #[must_use]
    pub fn stride(&self) -> u32 {
        self.width * 4
    }

    /// True when the image has no pixels at all.
    #[must_use]
    pub fn is_empty(&self) -> bool {
        self.width == 0 || self.height == 0
    }

    /// Reads one pixel, or None when out of bounds.
    #[must_use]
    pub fn pixel(&self, x: u32, y: u32) -> Option<[u8; 4]> {
        if x >= self.width || y >= self.height {
            return None;
        }
        let offset = (y as usize * self.width as usize + x as usize) * 4;
        let slice = self.rgba.get(offset..offset + 4)?;
        Some([slice[0], slice[1], slice[2], slice[3]])
    }

    /// Bounding box of pixels whose alpha is above the requested threshold.
    ///
    /// Returns `[x, y, width, height]` in source-image pixels, not an exclusive
    /// right/bottom edge. The UI controls in this game are drawn on transparent
    /// canvases (80x60 for the HUD icons), so their picture rectangles contain
    /// large dead margins. Callers that need a click surface matching the visible
    /// art can map this box through the same destination rectangle the renderer
    /// uses.
    #[must_use]
    pub fn alpha_bounds(&self, threshold: u8) -> Option<[u32; 4]> {
        self.alpha_bounds_in([0, 0, self.width, self.height], threshold)
    }

    /// Bounding box of opaque pixels inside one source-image rectangle.
    ///
    /// Sprite sheets need this for click surfaces: a standing-character atlas is
    /// much larger than one visible pose, so scanning the whole file would turn the
    /// transparent margins of every other cell into dead-but-clickable space.
    #[must_use]
    pub fn alpha_bounds_in(&self, region: [u32; 4], threshold: u8) -> Option<[u32; 4]> {
        let [region_x, region_y, region_w, region_h] = region;
        let region_right = region_x.checked_add(region_w)?;
        let region_bottom = region_y.checked_add(region_h)?;
        if region_w == 0
            || region_h == 0
            || region_right > self.width
            || region_bottom > self.height
        {
            return None;
        }
        let threshold = threshold.min(255);
        let mut left = region_right;
        let mut top = region_bottom;
        let mut right = region_x;
        let mut bottom = region_y;
        for y in region_y..region_bottom {
            for x in region_x..region_right {
                let offset = (y as usize * self.width as usize + x as usize) * 4 + 3;
                if self.rgba[offset] > threshold {
                    left = left.min(x);
                    top = top.min(y);
                    right = right.max(x);
                    bottom = bottom.max(y);
                }
            }
        }
        (right >= left && bottom >= top).then_some([left, top, right - left + 1, bottom - top + 1])
    }
}

/// Why an asset could not be produced.
#[derive(Debug)]
pub enum AssetError {
    /// The name is not a legal relative path (empty, absolute, or containing "..").
    BadName {
        /// The offending name.
        name: String,
    },
    /// Nothing on disk matched the name, even case-insensitively and with extensions.
    NotFound {
        /// The requested name.
        name: String,
        /// Root the search was anchored at.
        root: PathBuf,
    },
    /// The file exists but could not be read.
    Io {
        /// The requested name.
        name: String,
        /// Underlying error.
        source: std::io::Error,
    },
    /// The bytes are not a PNG/JPEG the decoder accepts.
    Decode {
        /// The requested name.
        name: String,
        /// Underlying error.
        source: image::ImageError,
    },
    /// Decoded, but the dimensions are unusable (zero, or above `MAX_DIMENSION`).
    BadSize {
        /// The requested name.
        name: String,
        /// Decoded width.
        width: u32,
        /// Decoded height.
        height: u32,
    },
}

impl fmt::Display for AssetError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::BadName { name } => write!(f, "invalid asset name: {name}"),
            Self::NotFound { name, root } => {
                write!(f, "asset not found: {name} under {}", root.display())
            }
            Self::Io { name, source } => write!(f, "cannot read asset {name}: {source}"),
            Self::Decode { name, source } => write!(f, "cannot decode asset {name}: {source}"),
            Self::BadSize {
                name,
                width,
                height,
            } => write!(f, "asset {name} has unusable size {width}x{height}"),
        }
    }
}

impl std::error::Error for AssetError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self {
            Self::Io { source, .. } => Some(source),
            Self::Decode { source, .. } => Some(source),
            _ => None,
        }
    }
}

/// The asset database: a data-root path plus a decode cache.
///
/// The cache is keyed by the *requested* name rather than the resolved path (the two are
/// usually identical and the requested name is what the interpreter keeps handing us). It
/// stores `Arc<ImageData>` so the renderer can hold a texture reference while the game
/// keeps loading other pictures.
#[derive(Clone, Debug)]
pub struct Assets {
    root: PathBuf,
    /// Optional mod roots, highest priority last (a later overlay wins a name clash).
    /// Empty for a plain data root; see Assets::with_overlays.
    overlays: Vec<PathBuf>,
    cache: HashMap<String, Arc<ImageData>>,
    /// Names that are not files (built-in `<SHAPE>` system graphics) or whose
    /// resolution failed. The picture layer asks for a size on every draw, and a
    /// repeated miss costs a case-insensitive directory walk each time; remembering
    /// it turns the per-frame probe into a hash lookup (see docs/M4_PERF.md §6.1).
    missing: HashSet<String>,
    /// Asset names that were resolved through a fallback alias (currently the
    /// `Picture/word_effect* -> hword/` author typo). The game layer drains these into
    /// its diagnostics so a silent path fix stays visible.
    fallbacks: Vec<String>,
    /// Byte-range patches declared by the mod overlays, applied to raw file bytes
    /// before decoding (see [`crate::patch`] and `docs/M7_PATCH.md`).
    patches: PatchSet,
    /// Memoised alpha bounding boxes: asset name, then `(source rectangle,
    /// threshold)`. The picture hit test asks for the same box every frame and
    /// one 330x576 panel scan walks 190,080 pixels, so the answer is kept until
    /// `clear()` drops the decoded images it was derived from. Two levels rather
    /// than one flat key so a hit borrows the name instead of allocating it.
    alpha_bounds_cache: HashMap<String, HashMap<([u32; 4], u8), Option<[u32; 4]>>>,
}

impl Assets {
    /// Anchors the database at an unpacked game root (the folder holding BasicData/).
    #[must_use]
    pub fn new(root: impl Into<PathBuf>) -> Self {
        Self::with_overlays(root, Vec::new())
    }

    /// Anchors the database at a base root plus zero or more mod overlay roots.
    ///
    /// Each overlay is a directory that mirrors the data tree (for example
    /// mod/Picture/status01.png). A name is looked up in every overlay first,
    /// newest overlay first, then in the base root. The first hit wins, so an overlay
    /// only has to carry the files it replaces.
    #[must_use]
    pub fn with_overlays(root: impl Into<PathBuf>, overlays: Vec<PathBuf>) -> Self {
        // A malformed patch set is reported and ignored: a broken mod must not stop
        // the game from loading its own assets.
        let patches = match PatchSet::load_from_overlays(&overlays) {
            Ok(set) => set,
            Err(error) => {
                eprintln!("mod patch: cannot load asset patches: {error}");
                PatchSet::default()
            }
        };
        Self {
            root: root.into(),
            overlays,
            cache: HashMap::new(),
            missing: HashSet::new(),
            fallbacks: Vec::new(),
            patches,
            alpha_bounds_cache: HashMap::new(),
        }
    }

    /// The data root this database resolves against.
    #[must_use]
    pub fn root(&self) -> &Path {
        &self.root
    }

    /// The mod overlay roots, lowest priority first.
    #[must_use]
    pub fn overlays(&self) -> &[PathBuf] {
        &self.overlays
    }

    /// Number of decoded images held.
    #[must_use]
    pub fn len(&self) -> usize {
        self.cache.len()
    }

    /// True when nothing has been decoded yet.
    #[must_use]
    pub fn is_empty(&self) -> bool {
        self.cache.is_empty()
    }

    /// Drops every decoded image. Called when returning to the title.
    pub fn clear(&mut self) {
        self.cache.clear();
        self.alpha_bounds_cache.clear();
    }

    /// Non-transparent bounding box of `name` inside `region`, memoised.
    ///
    /// Same contract as [`ImageData::alpha_bounds_in`], but the pixel scan runs
    /// once per `(name, region, threshold)` instead of once per call, and a hit
    /// is a hash lookup that does not allocate. A name that cannot be loaded
    /// caches `None` for that region instead of retrying every frame.
    ///
    /// The source rectangle and threshold are part of the key because the answer
    /// differs per animated pose and per caller; a sprite sheet asked for one
    /// cell must not answer with another cell's silhouette.
    #[must_use]
    pub fn alpha_bounds_in(
        &mut self,
        name: &str,
        region: [u32; 4],
        threshold: u8,
    ) -> Option<[u32; 4]> {
        let key = (region, threshold.min(255));
        if let Some(cached) = self
            .alpha_bounds_cache
            .get(name)
            .and_then(|regions| regions.get(&key))
        {
            return *cached;
        }
        let bounds = self
            .load(name)
            .ok()
            .and_then(|image| image.alpha_bounds_in(region, key.1));
        self.alpha_bounds_cache
            .entry(name.to_owned())
            .or_default()
            .insert(key, bounds);
        bounds
    }

    /// Returns an already decoded image without touching the disk.
    #[must_use]
    pub fn cached(&self, name: &str) -> Option<Arc<ImageData>> {
        self.cache.get(name).cloned()
    }

    /// Drains the fallback resolutions taken since the last call.
    ///
    /// The game layer folds each message into its diagnostics (counted like every
    /// other note), so an asset borrowed through an alias such as the
    /// `Picture/word_effect* -> hword/` typo is still reported instead of vanishing.
    pub fn take_fallbacks(&mut self) -> Vec<String> {
        std::mem::take(&mut self.fallbacks)
    }

    /// Resolves a WOLF asset name to a file, or None when the data tree lacks it.
    ///
    /// Public because the M0 verifier and the packer tooling want to know what is
    /// present without paying for a decode.
    #[must_use]
    pub fn resolve(&self, name: &str) -> Option<PathBuf> {
        let relative = normalize(name)?;
        for root in self
            .overlays
            .iter()
            .rev()
            .chain(std::iter::once(&self.root))
        {
            if let Some(path) = resolve_in(root, &relative) {
                return Some(path);
            }
        }
        None
    }

    /// Resolves a name, then a narrow fallback alias if the direct lookup misses.
    ///
    /// Only the `Picture/word_effect* -> hword/word_effect*` author typo is aliased
    /// (docs/HSCENE.md 4.6). Everything else obeys the strict `missing file is fatal`
    /// rule, so a genuinely absent asset still errors out.
    fn resolve_with_fallback(&self, name: &str) -> Option<(PathBuf, Option<String>)> {
        if let Some(path) = self.resolve(name) {
            return Some((path, None));
        }
        let alias = word_effect_alias(name)?;
        let path = self.resolve(&alias)?;
        Some((path, Some(alias)))
    }

    /// Decodes an image, reusing the cache.
    ///
    /// # Errors
    ///
    /// `BadName` for illegal names, `NotFound` when the data tree lacks the file,
    /// `Io`/`Decode` for unreadable or corrupt files, `BadSize` for zero or absurd
    /// dimensions.
    pub fn load(&mut self, name: &str) -> Result<Arc<ImageData>, AssetError> {
        if let Some(hit) = self.cache.get(name) {
            return Ok(Arc::clone(hit));
        }
        if normalize(name).is_none() {
            return Err(AssetError::BadName {
                name: name.to_owned(),
            });
        }
        let (path, alias) = match self.resolve_with_fallback(name) {
            Some(pair) => pair,
            None => {
                return Err(AssetError::NotFound {
                    name: name.to_owned(),
                    root: self.root.clone(),
                })
            }
        };
        if let Some(alias) = &alias {
            let message = format!("asset fallback: {name} -> {alias}");
            if !self.fallbacks.iter().any(|existing| existing == &message) {
                self.fallbacks.push(message);
            }
        }
        let mut bytes = std::fs::read(&path).map_err(|source| AssetError::Io {
            name: name.to_owned(),
            source,
        })?;
        // Byte patches run on the raw file bytes, before the decoder sees them.
        let mut candidates: Vec<&str> = vec![name];
        if let Some(alias) = alias.as_deref() {
            candidates.push(alias);
        }
        if let Err(error) = self.patches.apply_bytes(&mut bytes, &candidates) {
            eprintln!("mod patch: asset {name}: {error}");
        }
        let decoded = image::load_from_memory(&bytes).map_err(|source| AssetError::Decode {
            name: name.to_owned(),
            source,
        })?;
        let (width, height) = (decoded.width(), decoded.height());
        if width == 0 || height == 0 || width > MAX_DIMENSION || height > MAX_DIMENSION {
            return Err(AssetError::BadSize {
                name: name.to_owned(),
                width,
                height,
            });
        }
        let rgba = decoded.to_rgba8().into_raw();
        let data = ImageData {
            width,
            height,
            rgba,
        };
        let shared = Arc::new(data);
        self.cache.insert(name.to_owned(), Arc::clone(&shared));
        Ok(shared)
    }

    /// tex_size callback for [`crate::picture::Screen::quads`](crate::picture::Screen).
    ///
    /// Decodes on demand; a missing asset returns None, which makes the picture layer
    /// skip that slot instead of drawing a garbage-sized quad.
    pub fn texture_size(&mut self, name: &str) -> Option<(u32, u32)> {
        if name.is_empty() {
            return None;
        }
        // Built-in system graphics are never files; answering here avoids the
        // directory walk below on every draw (docs/M4_PERF.md §6.1).
        if crate::sysgraphic::parse(name).is_some() {
            return None;
        }
        if self.missing.contains(name) {
            return None;
        }
        match self.load(name) {
            Ok(image) => Some(image.size()),
            Err(err) => {
                // Not a warning per call: the picture layer re-asks every frame and the
                // same missing background would bury the log. Remember the miss so the
                // next frame does not repeat the filesystem probe.
                let _ = err;
                self.missing.insert(name.to_owned());
                None
            }
        }
    }
}

/// Normalises a WOLF asset name, rejecting anything that could escape the data root.
///
/// Returns None for an empty name, an absolute path, or a name containing ".." - the
/// game never stores those, so treating them as invalid is free fidelity plus free safety.
fn normalize(name: &str) -> Option<String> {
    let trimmed = name.trim().replace('\\', "/");
    let trimmed = trimmed.trim_start_matches("./").trim_start_matches('/');
    if trimmed.is_empty() {
        return None;
    }
    if trimmed.contains(':') {
        return None;
    }
    let mut parts: Vec<&str> = Vec::new();
    for segment in trimmed.split('/') {
        match segment {
            "" | "." => continue,
            ".." => return None,
            other => parts.push(other),
        }
    }
    if parts.is_empty() {
        None
    } else {
        Some(parts.join("/"))
    }
}

/// Resolves one already-normalised name under a single root, applying the same
/// extension probe and case-insensitive walk the public lookup uses.
fn resolve_in(root: &Path, relative: &str) -> Option<PathBuf> {
    let direct = root.join(relative);
    if direct.is_file() {
        return Some(direct);
    }
    // A name without an extension: probe the codecs the game ships.
    if Path::new(relative).extension().is_none() {
        for extension in PROBE_EXTENSIONS {
            let candidate = root.join(format!("{relative}.{extension}"));
            if candidate.is_file() {
                return Some(candidate);
            }
        }
    }
    // Case-insensitive walk, one path segment at a time.
    let mut current = root.to_path_buf();
    for segment in relative.split('/') {
        let entries = std::fs::read_dir(&current).ok()?;
        let mut found: Option<PathBuf> = None;
        for entry in entries.flatten() {
            let candidate = entry.path();
            let Some(file_name) = candidate.file_name().and_then(|n| n.to_str()) else {
                continue;
            };
            if file_name.eq_ignore_ascii_case(segment) {
                found = Some(candidate);
                break;
            }
        }
        current = found?;
    }
    if current.is_file() {
        Some(current)
    } else {
        None
    }
}

/// Maps the author's misspelt `Picture/word_effectNN.png` to the real
/// `hword/word_effectNN.png` (docs/HSCENE.md 4.6, docs/UNVERIFIED.md).
///
/// Deliberately narrow: only a `Picture/` directory and a `word_effect` filename.
/// Any other missing asset is left to fail as before.
fn word_effect_alias(name: &str) -> Option<String> {
    let relative = normalize(name)?;
    let (directory, file) = relative.rsplit_once('/')?;
    if !directory.eq_ignore_ascii_case("Picture") {
        return None;
    }
    if !file.to_ascii_lowercase().starts_with("word_effect") {
        return None;
    }
    Some(format!("hword/{file}"))
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn normalize_cleans_up_separators() {
        assert_eq!(
            normalize("SystemGraphic/TitleGraphic.jpg").as_deref(),
            Some("SystemGraphic/TitleGraphic.jpg")
        );
        assert_eq!(
            normalize("./Kagura/bg.png").as_deref(),
            Some("Kagura/bg.png")
        );
        assert_eq!(
            normalize("/Kagura/bg.png").as_deref(),
            Some("Kagura/bg.png")
        );
        assert_eq!(
            normalize("Kagura//bg.png").as_deref(),
            Some("Kagura/bg.png")
        );
    }

    #[test]
    fn normalize_rejects_escapes_and_empties() {
        assert!(normalize("").is_none());
        assert!(normalize("   ").is_none());
        assert!(normalize("../secret.png").is_none());
        assert!(normalize("Kagura/../../secret.png").is_none());
        assert!(normalize("C:/Windows/system32/x.png").is_none());
    }

    #[test]
    fn image_data_validates_length() {
        assert!(ImageData::new(2, 2, vec![0; 16]).is_some());
        assert!(ImageData::new(2, 2, vec![0; 15]).is_none());
        let image = ImageData::new(2, 1, vec![1, 2, 3, 4, 5, 6, 7, 8]).expect("image");
        assert_eq!(image.stride(), 8);
        assert_eq!(image.pixel(0, 0), Some([1, 2, 3, 4]));
        assert_eq!(image.pixel(1, 0), Some([5, 6, 7, 8]));
        assert_eq!(image.pixel(2, 0), None);
    }

    #[test]
    fn crop_copies_a_rectangle_and_rejects_out_of_bounds() {
        let image = ImageData::new(3, 2, (0u8..24).collect()).expect("image");
        let cell = image.crop([1, 0, 2, 2]).expect("2x2 cell");
        assert_eq!(cell.size(), (2, 2));
        assert_eq!(cell.pixel(0, 0), Some([4, 5, 6, 7]));
        assert_eq!(cell.pixel(1, 0), Some([8, 9, 10, 11]));
        assert_eq!(cell.pixel(0, 1), Some([16, 17, 18, 19]));
        assert!(
            image.crop([2, 0, 2, 2]).is_none(),
            "two columns do not fit after x=2"
        );
        assert!(
            image.crop([0, 1, 3, 2]).is_none(),
            "two rows do not fit after y=1"
        );
        assert!(
            image.crop([0, 0, 0, 1]).is_none(),
            "a zero-width cell is not an image"
        );
    }

    #[test]
    fn missing_asset_is_an_error_not_a_panic() {
        let mut assets = Assets::new("no-such-root");
        assert!(matches!(
            assets.load("SystemGraphic/TitleGraphic.jpg"),
            Err(AssetError::NotFound { .. })
        ));
        assert_eq!(assets.texture_size("SystemGraphic/TitleGraphic.jpg"), None);
        assert!(assets.is_empty());
    }

    /// Builds a throwaway directory tree under the crate's target dir.
    ///
    /// Deliberately NOT %TEMP%: on this machine a bash-spawned child gets
    /// PermissionDenied when it creates files there, which has already cost two
    /// debugging sessions. target/ is always writable by the build that runs the test.
    fn scratch_dir(tag: &str) -> PathBuf {
        let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        path.pop(); // crates/
        path.pop(); // workspace root
        path.push("target");
        path.push("test-scratch");
        path.push(format!("assets-{tag}-{}", std::process::id()));
        let _ = std::fs::remove_dir_all(&path);
        std::fs::create_dir_all(&path).expect("scratch dir");
        path
    }

    #[test]
    fn resolves_case_insensitively_and_without_extension() {
        let root = scratch_dir("resolve");
        std::fs::create_dir_all(root.join("systemgraphic")).expect("dir");
        // 1x1 PNG, the smallest legal file the decoder accepts.
        const PNG: [u8; 67] = [
            0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48,
            0x44, 0x52, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x08, 0x06, 0x00, 0x00,
            0x00, 0x1F, 0x15, 0xC4, 0x89, 0x00, 0x00, 0x00, 0x0A, 0x49, 0x44, 0x41, 0x54, 0x78,
            0x9C, 0x63, 0x00, 0x01, 0x00, 0x00, 0x05, 0x00, 0x01, 0x0D, 0x0A, 0x2D, 0xB4, 0x00,
            0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82,
        ];
        std::fs::write(root.join("systemgraphic").join("titlegraphic.png"), PNG).expect("write");

        let mut assets = Assets::new(&root);
        // Mixed case on the directory, bare stem on the file: both quirks at once.
        let image = assets
            .load("SystemGraphic/TitleGraphic")
            .expect("resolved case-insensitively with a probed extension");
        assert_eq!(image.size(), (1, 1));
        assert_eq!(image.rgba.len(), 4);
        assert_eq!(assets.len(), 1);
        assert!(assets.cached("SystemGraphic/TitleGraphic").is_some());

        let _ = std::fs::remove_dir_all(&root);
    }

    #[test]
    fn word_effect_alias_is_narrowly_scoped() {
        assert_eq!(
            word_effect_alias("Picture/word_effect30.png").as_deref(),
            Some("hword/word_effect30.png")
        );
        // Case on the directory is tolerated (the data tree is case-insensitive).
        assert_eq!(
            word_effect_alias("picture/word_effect30.png").as_deref(),
            Some("hword/word_effect30.png")
        );
        // Anything that is not the misspelt Picture/word_effect* path is untouched.
        assert_eq!(word_effect_alias("hword/word_effect30.png"), None);
        assert_eq!(word_effect_alias("Picture/other.png"), None);
        // A bare stem is still a word_effect name; the loader probes extensions later.
        assert_eq!(
            word_effect_alias("Picture/word_effect").as_deref(),
            Some("hword/word_effect")
        );
        assert_eq!(word_effect_alias("word_effect30.png"), None);
    }

    #[test]
    fn picture_word_effect_falls_back_to_hword_with_a_diagnostic() {
        let root = scratch_dir("word-effect-fallback");
        std::fs::create_dir_all(root.join("hword")).expect("dir");
        // 1x1 PNG, the smallest legal file the decoder accepts.
        const PNG: [u8; 67] = [
            0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48,
            0x44, 0x52, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x08, 0x06, 0x00, 0x00,
            0x00, 0x1F, 0x15, 0xC4, 0x89, 0x00, 0x00, 0x00, 0x0A, 0x49, 0x44, 0x41, 0x54, 0x78,
            0x9C, 0x63, 0x00, 0x01, 0x00, 0x00, 0x05, 0x00, 0x01, 0x0D, 0x0A, 0x2D, 0xB4, 0x00,
            0x00, 0x00, 0x00, 0x49, 0x45, 0x4E, 0x44, 0xAE, 0x42, 0x60, 0x82,
        ];
        std::fs::write(root.join("hword").join("word_effect30.png"), PNG).expect("write");

        let mut assets = Assets::new(&root);
        // The misspelt Picture/ path is absent, but the hword/ target exists: it resolves.
        assets
            .load("Picture/word_effect30.png")
            .expect("fallback resolves the real hword asset");
        assert_eq!(
            assets.take_fallbacks(),
            vec![
                "asset fallback: Picture/word_effect30.png -> hword/word_effect30.png".to_string()
            ]
        );
        // Taking the messages clears them: a second frame does not repeat the diagnostic.
        assert!(assets.take_fallbacks().is_empty());

        // A different missing asset is still a hard error, not silently aliased.
        assert!(matches!(
            assets.load("Picture/definitely_missing.png"),
            Err(AssetError::NotFound { .. })
        ));

        let _ = std::fs::remove_dir_all(&root);
    }

    #[test]
    fn a_mod_overlay_wins_over_the_base_asset() {
        let base = scratch_dir("overlay-base");
        let overlay = scratch_dir("overlay-mod");
        std::fs::create_dir_all(base.join("Picture")).expect("base dir");
        std::fs::create_dir_all(overlay.join("Picture")).expect("overlay dir");
        // Base is 1x1 opaque black; the overlay is 2x1 with two distinct colours.
        let base_px = [0u8, 0, 0, 255];
        image::save_buffer(
            base.join("Picture").join("status01.png"),
            &base_px,
            1,
            1,
            image::ColorType::Rgba8,
        )
        .expect("base png");
        let overlay_px = [1u8, 2, 3, 255, 4, 5, 6, 255];
        image::save_buffer(
            overlay.join("Picture").join("status01.png"),
            &overlay_px,
            2,
            1,
            image::ColorType::Rgba8,
        )
        .expect("overlay png");

        let mut plain = Assets::new(&base);
        assert_eq!(
            plain
                .load("Picture/status01.png")
                .expect("base asset")
                .size(),
            (1, 1)
        );

        let mut layered = Assets::with_overlays(&base, vec![overlay.clone()]);
        let image = layered.load("Picture/status01.png").expect("overlay asset");
        assert_eq!(image.size(), (2, 1));
        assert_eq!(image.pixel(0, 0), Some([1, 2, 3, 255]));
        assert_eq!(image.pixel(1, 0), Some([4, 5, 6, 255]));
        assert_eq!(layered.overlays(), std::slice::from_ref(&overlay));

        let _ = std::fs::remove_dir_all(&base);
        let _ = std::fs::remove_dir_all(&overlay);
    }
}
