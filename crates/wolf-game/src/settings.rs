//! Player-visible global settings and their `Save/System.sav` bridge (M3 gap #3, M4).
//!
//! The retail engine keeps its global settings in `SavePart2` (the "system data" segment):
//!
//! | `SavePart2` field | meaning here | evidence |
//! | --- | --- | --- |
//! | `vars72_74` | BGM / SE / ambient volume, 0..=120 | live values all 100; CE132 edits Sys100 (BGM) and Sys102 (SE) |
//! | `vars64_69` | raw key-configuration words | six words, `[144, 16, 145, 32, 146, 64]` in the shipped System.sav |
//! | `vars42_45` | window colour RGBA, one u16 per channel | `[160, 68, 75, 200]` in every save |
//!
//! The common-event settings screen (CE132 `X┗[移]システム欄実行`) edits six system
//! variables, not the save directly:
//!
//! * Sys100 BGM volume (Sys101 mirrors it for the on-screen number),
//! * Sys102 SE volume,
//! * Sys52..Sys57 the six configurable keys (keyboard decide/cancel/sub, pad decide/
//!   cancel/sub; CE132 resets them to 144/145/146/301/302/303).
//!
//! The engine, not the script, is what persists the settings: this module maps the
//! volume pair onto `vars72_74` and exposes the key words both raw and through the
//! Sys52..57 working copy. See [`GlobalSettings::key_config`] for what is *not* proven
//! about the key encoding.
//!
//! Out of scope here: "key position save", "key repeat" and "combat mashing" are
//! CDataBase type 18 rows 56..58 (ス script reads them through opcode 250 at CE132
//! start-up). They live in the variable database, which now round-trips through every
//! save (docs/M3_VARDB_BUG.md), not in `System.sav`.

use wolf_save::SavePart2;

/// The upper bound the settings screen clamps volumes to (CE132 `> 120 -> 120`).
pub const VOLUME_MAX: u32 = 120;

/// Key codes CE132's reset branch writes on the Japanese/Chinese keyboard layout:
/// 144 = Z, 145 = X, 146 = C (WOLF stores DirectInput scancode + 100), 301..303 = the
/// three pad buttons.
pub const DEFAULT_KEY_CONFIG: [u32; 6] = [144, 145, 146, 301, 302, 303];

/// Window colour of the shipped `System.sav` (RGBA, one u16 per channel).
pub const DEFAULT_WINDOW_COLOUR: [u16; 4] = [160, 68, 75, 200];

/// A player-visible global settings snapshot.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct GlobalSettings {
    /// BGM volume, 0..=120. Live home: Sys100 (Sys101 mirrors it).
    pub bgm_volume: u32,
    /// SE volume, 0..=120. Live home: Sys102.
    pub se_volume: u32,
    /// Ambient volume, 0..=120. Only `System.sav` stores it; no script reads it.
    pub ambient_volume: u32,
    /// The six raw key-configuration words (`SavePart2::vars64_69`).
    ///
    /// The shipped file reads `[144, 16, 145, 32, 146, 64]`, i.e. three
    /// `(key code, flag)` pairs. CE132 writes six *separate* codes (Sys52..57) and the
    /// reset branch uses 144/145/146/301/302/303, which does not fit that pairing; how
    /// the engine translates between the two layouts is NOT proven. This type therefore
    /// keeps the file words verbatim: the settings API can read and write them without
    /// pretending to know the mapping. See [`DEFAULT_KEY_CONFIG`] for the script defaults.
    pub key_config: [u32; 6],
    /// Window colour RGBA, one channel per u16.
    pub window_colour: [u16; 4],
}

impl Default for GlobalSettings {
    fn default() -> Self {
        Self {
            bgm_volume: 100,
            se_volume: 100,
            ambient_volume: 100,
            key_config: DEFAULT_KEY_CONFIG,
            window_colour: DEFAULT_WINDOW_COLOUR,
        }
    }
}

impl GlobalSettings {
    /// Reads the settings a save carries. Version-gated fields that are absent in an
    /// older file version read as zero (the same convention `SavePart2` itself uses),
    /// so callers that need "the retail default when absent" should compare against
    /// [`Self::default`] on a fresh `Game` instead.
    #[must_use]
    pub fn from_part2(part2: &SavePart2) -> Self {
        Self {
            bgm_volume: part2.vars72_74[0],
            se_volume: part2.vars72_74[1],
            ambient_volume: part2.vars72_74[2],
            key_config: part2.vars64_69,
            window_colour: part2.vars42_45,
        }
    }

    /// This snapshot with the ranges the retail UI enforces applied.
    ///
    /// Volumes clamp to `0..=VOLUME_MAX`; colour channels clamp to a byte range. The key
    /// words are kept verbatim: they are an opaque configuration encoding.
    #[must_use]
    pub fn clamped(&self) -> Self {
        Self {
            bgm_volume: self.bgm_volume.min(VOLUME_MAX),
            se_volume: self.se_volume.min(VOLUME_MAX),
            ambient_volume: self.ambient_volume.min(VOLUME_MAX),
            key_config: self.key_config,
            window_colour: self
                .window_colour
                .map(|channel| channel.min(u16::from(u8::MAX))),
        }
    }

    /// Writes this snapshot back into a part-2 image (clamped as [`Self::clamped`]).
    pub fn write_part2(&self, part2: &mut SavePart2) {
        let clamped = self.clamped();
        part2.vars72_74 = [
            clamped.bgm_volume,
            clamped.se_volume,
            clamped.ambient_volume,
        ];
        part2.vars64_69 = clamped.key_config;
        part2.vars42_45 = clamped.window_colour;
    }

    /// BGM mixer gain for the 0..=120 scale.
    ///
    /// 100 is "normal" and maps to unity. The software mixer clamps its master gain to
    /// 0..=1, so 101..=120 saturates at unity rather than amplifying; document that
    /// instead of silently accepting a louder-looking number.
    #[must_use]
    pub fn bgm_gain(&self) -> f32 {
        gain(self.bgm_volume)
    }

    /// SE mixer gain, same scale and saturation as [`Self::bgm_gain`].
    #[must_use]
    pub fn se_gain(&self) -> f32 {
        gain(self.se_volume)
    }
}

fn gain(volume: u32) -> f32 {
    (volume.min(VOLUME_MAX) as f32 / 100.0).clamp(0.0, 1.0)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn defaults_are_the_retail_settings() {
        let defaults = GlobalSettings::default();
        assert_eq!(defaults.bgm_volume, 100);
        assert_eq!(defaults.se_volume, 100);
        assert_eq!(defaults.ambient_volume, 100);
        assert_eq!(defaults.key_config, DEFAULT_KEY_CONFIG);
    }

    #[test]
    fn volume_gain_maps_100_to_unity_and_saturates_above_it() {
        let mut settings = GlobalSettings::default();
        assert!((settings.bgm_gain() - 1.0).abs() < f32::EPSILON);
        settings.bgm_volume = 50;
        assert!((settings.bgm_gain() - 0.5).abs() < f32::EPSILON);
        settings.bgm_volume = 0;
        assert!((settings.bgm_gain() - 0.0).abs() < f32::EPSILON);
        settings.bgm_volume = 120;
        assert!(
            (settings.bgm_gain() - 1.0).abs() < f32::EPSILON,
            "the mixer clamps to unity; 120 must not amplify past it"
        );
        settings.se_volume = 25;
        assert!((settings.se_gain() - 0.25).abs() < f32::EPSILON);
    }

    #[test]
    fn clamping_stays_inside_the_retail_ranges() {
        let settings = GlobalSettings {
            bgm_volume: 999,
            se_volume: 0,
            ambient_volume: 121,
            key_config: [1, 2, 3, 4, 5, 6],
            window_colour: [0, 255, 256, 700],
        }
        .clamped();
        assert_eq!(settings.bgm_volume, VOLUME_MAX);
        assert_eq!(settings.se_volume, 0);
        assert_eq!(settings.ambient_volume, VOLUME_MAX);
        assert_eq!(settings.key_config, [1, 2, 3, 4, 5, 6], "key words are opaque");
        assert_eq!(settings.window_colour, [0, 255, 255, 255]);
    }
}