//! WOLF RPG Editor generation constants.
//!
//! Two container generations ship across the sister games: 2.00 (this game)
//! and 2.10 (the successor). Every container carries a version_header byte that
//! selects the generation; the footer / version bytes then depend on it. The
//! rule enforced here is: read the version_header, pick exactly one generation,
//! and validate the remaining bytes against that generation constants. Never
//! accept both at once - an unknown version_header is a hard error, not a guess.
//!
//! Measured on disk:
//! * Game.dat            - footer 0xC2 (2.00) / 0xC3 (2.10)
//! * CommonEvent.dat     - footer 0x8F (2.00) / 0x90 (2.10)
//! * DataBase.dat etc.   - version+footer 0xC1 (2.00) / 0xC2 (2.10)

use crate::error::{Error, Result};

/// One WOLF RPG Editor container generation.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum WolfGeneration {
    /// 2.00 line - this game. version_header 0x00.
    V200,
    /// 2.10 line - the successor. version_header 0x55.
    V210,
}

impl WolfGeneration {
    /// Map a container version_header byte to its generation, or None.
    #[must_use]
    pub const fn from_version_header(byte: u8) -> Option<Self> {
        match byte {
            0x00 => Some(Self::V200),
            0x55 => Some(Self::V210),
            _ => None,
        }
    }

    /// Like from_version_header but returns a rich error naming the container
    /// and the offending offset.
    pub fn require_version_header(byte: u8, what: &'static str, pos: usize) -> Result<Self> {
        Self::from_version_header(byte).ok_or_else(|| {
            Error::field(
                what,
                pos,
                format!("unknown WOLF generation version_header 0x{byte:02X}"),
            )
        })
    }

    /// Game.dat footer byte for this generation.
    #[must_use]
    pub const fn gamedat_footer(self) -> u8 {
        match self {
            Self::V200 => 0xC2,
            Self::V210 => 0xC3,
        }
    }

    /// CommonEvent.dat footer byte for this generation.
    #[must_use]
    pub const fn commonevent_footer(self) -> u8 {
        match self {
            Self::V200 => 0x8F,
            Self::V210 => 0x90,
        }
    }

    /// Database container version byte for this generation.
    #[must_use]
    pub const fn database_version(self) -> u8 {
        match self {
            Self::V200 => 0xC1,
            Self::V210 => 0xC2,
        }
    }

    /// Database container footer byte for this generation.
    #[must_use]
    pub const fn database_footer(self) -> u8 {
        match self {
            Self::V200 => 0xC1,
            Self::V210 => 0xC2,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn selects_by_version_header() {
        assert_eq!(
            WolfGeneration::from_version_header(0x00),
            Some(WolfGeneration::V200)
        );
        assert_eq!(
            WolfGeneration::from_version_header(0x55),
            Some(WolfGeneration::V210)
        );
        assert_eq!(WolfGeneration::from_version_header(0x01), None);
    }

    #[test]
    fn constants_match_the_two_generations() {
        assert_eq!(WolfGeneration::V200.gamedat_footer(), 0xC2);
        assert_eq!(WolfGeneration::V210.gamedat_footer(), 0xC3);
        assert_eq!(WolfGeneration::V200.commonevent_footer(), 0x8F);
        assert_eq!(WolfGeneration::V210.commonevent_footer(), 0x90);
        assert_eq!(WolfGeneration::V200.database_version(), 0xC1);
        assert_eq!(WolfGeneration::V210.database_version(), 0xC2);
    }

    #[test]
    fn unknown_version_header_is_an_error() {
        assert!(WolfGeneration::require_version_header(0x42, "test", 7).is_err());
    }
}
