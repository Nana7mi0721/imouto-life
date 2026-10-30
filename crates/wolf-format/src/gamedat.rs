//! `Game.dat` — the per-game settings blob.
//!
//! Layout verified byte-for-byte in `docs/FORMAT_SPEC.md` §2. Two traps worth
//! repeating: `u8_settings_len` is a **byte** count while `u16_settings_len`
//! is a **u16** count, and the string list length is not fixed — loop on
//! `string_count` instead of indexing a fixed table.

use crate::bytes::Reader;
use crate::error::{Error, Result};

/// Marker for a field that the editor writes but does not name.
pub const UNKNOWN: &str = "unknown";

/// Parsed `Game.dat`.
#[derive(Debug, Clone)]
pub struct GameDat {
    /// Container header version byte (`0x55` for everything in this game).
    pub version_header: u8,
    /// The 35 "u8 setting" bytes, in file order.
    pub u8_settings: Vec<u8>,
    /// The string table, in file order.
    pub strings: Vec<String>,
    /// The file size the editor recorded; must equal `data.len() - 1`.
    pub recorded_size: u32,
    /// The 22 "u16 settings", in file order.
    pub u16_settings: Vec<u16>,
    /// First static random seed.
    pub random_a: u32,
    /// Second static random seed.
    pub random_b: u32,
    /// Static random lookup table (values 0..=127 in this game).
    pub static_randoms: Vec<u8>,
    /// Container footer byte (`0xC3`).
    pub footer: u8,
}

impl GameDat {
    /// Nine-byte container magic, distinct from the other `.dat` files.
    pub const MAGIC: [u8; 9] = [0x00, 0x57, 0x00, 0x00, 0x4F, 0x4C, 0x00, 0x46, 0x4D];
    /// Expected footer byte.
    pub const FOOTER: u8 = 0xC3;

    /// Parse a `Game.dat` image.
    pub fn parse(data: &[u8]) -> Result<Self> {
        let mut r = Reader::new(data);

        r.expect(&Self::MAGIC, "Game.dat magic")?;
        let version_header = r.u8()?;
        let generation = crate::generation::WolfGeneration::require_version_header(
            version_header,
            "Game.dat version_header",
            r.pos() - 1,
        )?;

        let u8_len = r.u32()? as usize;
        let u8_settings = r.take(u8_len)?.to_vec();

        let string_count = r.u32()? as usize;
        if string_count > r.remaining() / 4 {
            return Err(Error::field(
                "Game.dat string_count",
                r.pos() - 4,
                format!(
                    "{string_count} entries do not fit in {} bytes",
                    r.remaining()
                ),
            ));
        }
        let mut strings = Vec::with_capacity(string_count);
        for _ in 0..string_count {
            strings.push(r.t_str()?);
        }

        let recorded_size_pos = r.pos();
        let recorded_size = r.u32()?;
        if recorded_size as usize != data.len().saturating_sub(1) {
            return Err(Error::field(
                "Game.dat recorded size",
                recorded_size_pos,
                format!(
                    "{recorded_size} does not equal file length - 1 ({})",
                    data.len().saturating_sub(1)
                ),
            ));
        }
        // WolfTL calls this m_unknownSize; this game stores 0.
        let _unknown_size = r.u32()?;

        let u16_len = r.u32()? as usize;
        let mut u16_settings = Vec::with_capacity(u16_len);
        for _ in 0..u16_len {
            u16_settings.push(r.u16()?);
        }

        let random_a = r.u32()?;
        let random_b = r.u32()?;
        // The remainder up to the footer is the static random table.
        let static_randoms = r.take(r.remaining().saturating_sub(1))?.to_vec();

        let footer = r.u8()?;
        let want_footer = generation.gamedat_footer();
        if footer != want_footer {
            return Err(Error::magic(
                "Game.dat footer",
                r.pos() - 1,
                &[footer],
                &[want_footer],
            ));
        }
        // The container is followed by at most a NUL pad byte.
        while !r.at_end() {
            if r.u8()? != 0 {
                return Err(Error::trailing(r.pos() - 1, r.remaining() + 1));
            }
        }

        Ok(Self {
            version_header,
            u8_settings,
            strings,
            recorded_size,
            u16_settings,
            random_a,
            random_b,
            static_randoms,
            footer,
        })
    }

    fn u8s(&self, index: usize) -> u8 {
        self.u8_settings.get(index).copied().unwrap_or(0)
    }

    fn u16s(&self, index: usize) -> u16 {
        self.u16_settings.get(index).copied().unwrap_or(0)
    }

    fn string(&self, index: usize) -> &str {
        self.strings.get(index).map_or("", String::as_str)
    }

    // --- string settings (§2.3) -------------------------------------------

    /// `strings[0]` — the game title.
    #[must_use]
    pub fn title(&self) -> &str {
        self.string(0)
    }

    /// `strings[1]` — the licence serial.
    #[must_use]
    pub fn serial(&self) -> &str {
        self.string(1)
    }

    /// `strings[2]` — the key used when the editor encrypts `Game.dat` itself.
    ///
    /// This game ships plaintext, so the key is informational only. It is *not*
    /// the `.wolf` archive key — that one is derived from file names alone
    /// (see `dxarchive`).
    #[must_use]
    pub fn encryption_key(&self) -> &str {
        self.string(2)
    }

    /// `strings[3]` — the main font name.
    #[must_use]
    pub fn font_main(&self) -> &str {
        self.string(3)
    }

    /// `strings[4..7]` — the three secondary font names.
    #[must_use]
    pub fn fonts_secondary(&self) -> [&str; 3] {
        [self.string(4), self.string(5), self.string(6)]
    }

    /// `strings[7]` — default hero graphic name.
    #[must_use]
    pub fn starting_hero_graphic(&self) -> &str {
        self.string(7)
    }

    /// `strings[8]` — the subtitle appended to the window title, if any.
    #[must_use]
    pub fn subtitle(&self) -> &str {
        self.string(8)
    }

    /// `strings[9]` — Pro edition loading picture.
    #[must_use]
    pub fn pro_loading_picture(&self) -> &str {
        self.string(9)
    }

    /// `strings[10]` — Pro edition loading gauge picture.
    #[must_use]
    pub fn pro_loading_gauge(&self) -> &str {
        self.string(10)
    }

    // --- u8 settings (§2.2) -----------------------------------------------

    /// Tile size in pixels (16 / 32 / 40 / 48).
    #[must_use]
    pub fn tile_size(&self) -> u8 {
        self.u8s(0)
    }

    /// Character sprite directions used for graphics.
    #[must_use]
    pub fn character_directions_image(&self) -> u8 {
        self.u8s(1)
    }

    /// Character sprite directions used for movement.
    #[must_use]
    pub fn character_directions_move(&self) -> u8 {
        self.u8s(2)
    }

    /// Whether "guruguru" (rotating) movement is enabled.
    #[must_use]
    pub fn guruguru_enabled(&self) -> u8 {
        self.u8s(3)
    }

    /// Frames per second.
    #[must_use]
    pub fn fps(&self) -> u8 {
        self.u8s(4)
    }

    /// Whether character shadows are drawn.
    #[must_use]
    pub fn character_shadow(&self) -> u8 {
        self.u8s(5)
    }

    /// MIDI source selector.
    #[must_use]
    pub fn midi_source(&self) -> u8 {
        self.u8s(6)
    }

    /// Character animation frame count.
    #[must_use]
    pub fn character_animation_patterns(&self) -> u8 {
        self.u8s(7)
    }

    /// Character movement width.
    #[must_use]
    pub fn character_movement_width(&self) -> u8 {
        self.u8s(8)
    }

    /// Character movement hitbox.
    #[must_use]
    pub fn character_movement_hitbox(&self) -> u8 {
        self.u8s(9)
    }

    /// Text horizontal padding.
    #[must_use]
    pub fn text_horizontal_padding(&self) -> u8 {
        self.u8s(10)
    }

    /// Text line spacing.
    #[must_use]
    pub fn text_line_spacing(&self) -> u8 {
        self.u8s(11)
    }

    /// Choice line spacing.
    #[must_use]
    pub fn choice_line_spacing(&self) -> u8 {
        self.u8s(12)
    }

    /// Anti-aliasing mode: 0 enabled, 1 disabled, 2 disabled + double width.
    #[must_use]
    pub fn anti_aliasing(&self) -> u8 {
        self.u8s(14)
    }

    /// Event move speed setting.
    #[must_use]
    pub fn move_speed_event(&self) -> u8 {
        self.u8s(15)
    }

    /// Hero / ally move speed setting.
    #[must_use]
    pub fn move_speed_hero_allies(&self) -> u8 {
        self.u8s(16)
    }

    /// In-game text language id (4 = Simplified Chinese).
    #[must_use]
    pub fn in_game_language(&self) -> u8 {
        self.u8s(17)
    }

    /// Image scaling method: 0 rough, 1 smooth.
    #[must_use]
    pub fn image_scaling_method(&self) -> u8 {
        self.u8s(18)
    }

    /// Behaviour when the window loses focus: 0 pause, 1 keep running.
    #[must_use]
    pub fn inactive_window_behavior(&self) -> u8 {
        self.u8s(19)
    }

    /// System language: 0 Japanese, 1 English.
    #[must_use]
    pub fn system_language(&self) -> u8 {
        self.u8s(20)
    }

    // --- u16 settings (§2.4) ----------------------------------------------

    /// Framebuffer width in pixels.
    #[must_use]
    pub fn screen_width(&self) -> u16 {
        self.u16s(16)
    }

    /// Framebuffer height in pixels.
    #[must_use]
    pub fn screen_height(&self) -> u16 {
        self.u16s(17)
    }

    /// The `wolf_rpg_version` slot. This game's editor writes **0**, so it is
    /// useless for feature detection — do not branch on it.
    #[must_use]
    pub fn wolf_rpg_version_setting(&self) -> u16 {
        self.u16s(18)
    }

    /// Framebuffer size as `(width, height)`.
    #[must_use]
    pub fn screen_size(&self) -> (u16, u16) {
        (self.screen_width(), self.screen_height())
    }
}
