//! CRC-32 (reflected, polynomial `0xEDB88320`) as used by DXArchive keys.
//!
//! `DXArchive.cpp:1908` (`HashCRC32`) initialises the register with
//! `0xFFFFFFFF` and returns it XOR-ed with `0xFFFFFFFF`, which is exactly the
//! zlib/PKZIP variant; only the key derivation uses it (see `super::key`).

/// Standard CRC-32 of `data`.
///
/// Computed bit by bit rather than from a 256-entry table: the only inputs are
/// 7-byte to 200-byte key strings, so the table would cost more code than it
/// saves.
#[must_use]
pub(super) fn crc32(data: &[u8]) -> u32 {
    let mut crc = 0xFFFF_FFFFu32;
    for &byte in data {
        crc ^= u32::from(byte);
        for _ in 0..8 {
            crc = if crc & 1 == 0 {
                crc >> 1
            } else {
                (crc >> 1) ^ 0xEDB8_8320
            };
        }
    }
    crc ^ 0xFFFF_FFFF
}

#[cfg(test)]
mod tests {
    use super::crc32;

    #[test]
    fn matches_known_crc32_vectors() {
        assert_eq!(crc32(b""), 0x0000_0000);
        assert_eq!(crc32(b"123456789"), 0xCBF4_3926);
        assert_eq!(
            crc32(b"The quick brown fox jumps over the lazy dog"),
            0x414F_A339
        );
    }
}
