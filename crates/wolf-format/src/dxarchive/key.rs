//! DXArchive XOR keys (docs/FORMAT_SPEC.md §8.3, §8.4 steps 1 and 6).
//!
//! Every byte after the 64-byte header is obfuscated with a 7-byte cyclic XOR
//! key. The archive-wide key comes from the engine's built-in table, selected by
//! the crypt version in the header flags; each file then gets its own key,
//! derived by CRC-32 from the archive key string plus the file's uppercased
//! Shift-JIS name and the uppercased names of its parent directories.
//!
//! Reference: `KeyCreate` and `KeyConv` in
//! `docs/vendor/WolfDec-master/src/WolfDec/3rdParty/DXArchive.cpp` (lines 503
//! and 563).

use super::crc32::crc32;

/// `DXA_KEY_BYTES`: the XOR key is seven bytes wide.
pub(super) const KEY_BYTES: usize = 7;

/// Appended to key sources shorter than four bytes (`DefaultKeyString`).
///
/// `KeyCreate` copies `DefaultKeyString` (the C string `"DXLIBARC"`) after the
/// original bytes; the terminating NUL is not part of the CRC input.
const DEFAULT_KEY_SUFFIX: &[u8] = b"DXLIBARC";

/// Built-in key strings from UberWolf's `DEFAULT_CRYPT_MODES`.
///
/// Entries are `(crypt_version, key_bytes)`; the bytes are the C string without
/// its trailing NUL, which is what `KeyCreate` hashes (verified: this key
/// reproduces the archive keys of every `.wolf` file this crate is tested on).
///
/// `crypt_version` 0x0000 is deliberately absent: WolfDec lists no fewer than
/// five modes under that version (v2.01, v2.10, v2.20, v2.225 and One Way
/// Heroics), so a version of zero is not enough to pick one. ChaCha2 v1 (0x64)
/// is absent too because it is a stream cipher, not a cyclic XOR, and this
/// module only implements the XOR scheme.
const CRYPT_MODES: &[(u16, &[u8])] = &[
    (0x012C, &V3_00),
    (0x013A, &V3_14),
    (0x014B, &V3_31),
    (0x015E, &V3_50),
];

/// "Wolf RPG v3.00" key string (40 bytes).
const V3_00: [u8; 40] = [
    0x0F, 0x53, 0xE1, 0x3E, 0x8E, 0xB5, 0x41, 0x91, 0x52, 0x16, 0x55, 0xAE, 0x34, 0xC9, 0x8F, 0x79,
    0x59, 0x2F, 0x59, 0x6B, 0x95, 0x19, 0x9B, 0x1B, 0x35, 0x9A, 0x2F, 0xDE, 0xC9, 0x7C, 0x12, 0x96,
    0xC3, 0x14, 0xB5, 0x0F, 0x53, 0xE1, 0x3E, 0x8E,
];

/// "Wolf RPG v3.14" key string (45 bytes) — the one every retail WOLF release
/// since 2016 uses, including the archive this crate is tested against.
const V3_14: [u8; 45] = [
    0x31, 0xF9, 0x01, 0x36, 0xA3, 0xE3, 0x8D, 0x3C, 0x7B, 0xC3, 0x7D, 0x25, 0xAD, 0x63, 0x28, 0x19,
    0x1B, 0xF7, 0x8E, 0x6C, 0xC4, 0xE5, 0xE2, 0x76, 0x82, 0xEA, 0x4F, 0xED, 0x61, 0xDA, 0xE0, 0x44,
    0x5B, 0xB6, 0x46, 0x3B, 0x06, 0xD5, 0xCE, 0xB6, 0x78, 0x58, 0xD0, 0x7C, 0x82,
];

/// "Wolf RPG v3.31" key string (52 bytes).
const V3_31: [u8; 52] = [
    0xCA, 0x08, 0x4C, 0x5D, 0x17, 0x0D, 0xDA, 0xA1, 0xD7, 0x27, 0xC8, 0x41, 0x54, 0x38, 0x82, 0x32,
    0x54, 0xB7, 0xF9, 0x46, 0x8E, 0x13, 0x6B, 0xCA, 0xD0, 0x5C, 0x95, 0x95, 0xE2, 0xDC, 0x03, 0x53,
    0x60, 0x9B, 0x4A, 0x38, 0x17, 0xF3, 0x69, 0x59, 0xA4, 0xC7, 0x9A, 0x43, 0x63, 0xE6, 0x54, 0xAF,
    0xDB, 0xBB, 0x43, 0x58,
];

/// "Wolf RPG v3.50" key string (52 bytes).
const V3_50: [u8; 52] = [
    0xD2, 0x84, 0xCE, 0x28, 0xCE, 0x88, 0x82, 0xE4, 0x2A, 0x18, 0x2E, 0x4C, 0x06, 0xB4, 0xEA, 0x84,
    0x06, 0xB8, 0xC6, 0x88, 0x5A, 0xA0, 0x9E, 0x7C, 0x56, 0x40, 0xBA, 0x34, 0x52, 0xCC, 0xC6, 0x7C,
    0x2E, 0x14, 0x12, 0x68, 0xFE, 0x5C, 0x76, 0x94, 0x86, 0x78, 0x8E, 0x4C, 0xBE, 0x88, 0x66, 0x9C,
    0x1E, 0xE0, 0x8E, 0x6C,
];

/// Look up the built-in key string for `crypt_version`.
#[must_use]
pub(super) fn mode_key(crypt_version: u16) -> Option<&'static [u8]> {
    CRYPT_MODES
        .iter()
        .find(|(version, _)| *version == crypt_version)
        .map(|(_, key)| *key)
}

/// Derive the 7-byte cyclic XOR key from a key source (`KeyCreate`).
///
/// Sources shorter than four bytes are extended with `"DXLIBARC"`, and the CRC
/// is computed over the even-index bytes and the odd-index bytes separately; the
/// key is the first four bytes of the first CRC followed by the first three bytes
/// of the second, both little-endian.
#[must_use]
pub(super) fn key_create(source: &[u8]) -> [u8; KEY_BYTES] {
    let extended;
    let source = if source.len() < 4 {
        let mut buffer = Vec::with_capacity(source.len() + DEFAULT_KEY_SUFFIX.len());
        buffer.extend_from_slice(source);
        buffer.extend_from_slice(DEFAULT_KEY_SUFFIX);
        extended = buffer;
        extended.as_slice()
    } else {
        source
    };

    let mut even = Vec::with_capacity(source.len() / 2 + 1);
    let mut odd = Vec::with_capacity(source.len() / 2 + 1);
    for (index, &byte) in source.iter().enumerate() {
        if index % 2 == 0 {
            even.push(byte);
        } else {
            odd.push(byte);
        }
    }
    let first = crc32(&even).to_le_bytes();
    let second = crc32(&odd).to_le_bytes();
    [
        first[0], first[1], first[2], first[3], second[0], second[1], second[2],
    ]
}

/// XOR `data` with `key`, resuming the 7-byte cycle at `position`.
///
/// The position is a byte offset into the file's *plaintext*, which is why the
/// callers pass `DataSize` (or `DataSize` plus the bytes already written) rather than
/// an offset into the compressed data.
pub(super) fn key_conv(data: &mut [u8], key: &[u8; KEY_BYTES], position: u64) {
    let mut index = (position % KEY_BYTES as u64) as usize;
    for byte in data.iter_mut() {
        *byte ^= key[index];
        index += 1;
        if index == KEY_BYTES {
            index = 0;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::{key_conv, key_create, mode_key, V3_14};

    #[test]
    fn v3_14_derives_the_measured_archive_key() {
        // The archive-wide key of every `.wolf` file in the reference game.
        assert_eq!(
            key_create(&V3_14),
            [0x3F, 0x05, 0xF9, 0xEE, 0xF7, 0x1E, 0xCC]
        );
        assert_eq!(mode_key(0x013A), Some(&V3_14[..]));
        assert_eq!(mode_key(0x0999), None);
    }

    #[test]
    fn conv_is_a_seven_byte_cycle_starting_at_position() {
        let key = [1u8, 2, 3, 4, 5, 6, 7];
        let mut data = [0u8; 9];
        key_conv(&mut data, &key, 5);
        assert_eq!(data, [6, 7, 1, 2, 3, 4, 5, 6, 7]);
    }
}
