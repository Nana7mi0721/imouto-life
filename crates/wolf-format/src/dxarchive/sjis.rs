//! Shift-JIS (CP932) decoder for archive entry names.
//!
//! `DARC_HEAD.CharCodeFormat` is 932 in every WOLF archive, so names on disk are
//! CP932 bytes while `ArchiveEntry` exposes `String`. This decoder follows the
//! CP932 code page including its vendor single-byte assignments, and it mirrors
//! what a CP932-to-Unicode converter does with an undefined pair: emit U+FFFD
//! and re-read the second byte as a fresh character.
//!
//! The double-byte table is generated — see `cp932.rs`.

use super::cp932::{TABLE, TRAIL_COUNT};

/// Substituted for every byte or pair CP932 does not define.
const REPLACEMENT: char = '\u{FFFD}';

/// Decode CP932 bytes into a `String`.
#[must_use]
pub(super) fn decode(bytes: &[u8]) -> String {
    let mut out = String::with_capacity(bytes.len());
    let mut index = 0;
    while index < bytes.len() {
        let byte = bytes[index];
        if let Some(lead) = lead_index(byte) {
            if let Some(&trail_byte) = bytes.get(index + 1) {
                if let Some(trail) = trail_index(trail_byte) {
                    let code = TABLE[lead * TRAIL_COUNT + trail];
                    if code != 0 {
                        if let Some(character) = char::from_u32(u32::from(code)) {
                            out.push(character);
                            index += 2;
                            continue;
                        }
                    }
                }
            }
            // Undefined pair (or a lead byte at the very end): the pair is one
            // replacement character and the trail byte is decoded again.
            out.push(REPLACEMENT);
            index += 1;
            continue;
        }
        out.push(single(byte));
        index += 1;
    }
    out
}

/// Row of `byte` in the double-byte table, if it is a CP932 lead byte.
fn lead_index(byte: u8) -> Option<usize> {
    match byte {
        0x81..=0x9F => Some(usize::from(byte - 0x81)),
        0xE0..=0xFC => Some(31 + usize::from(byte - 0xE0)),
        _ => None,
    }
}

/// Column of `byte` inside a double-byte row, if it is a CP932 trail byte.
fn trail_index(byte: u8) -> Option<usize> {
    match byte {
        0x40..=0x7E => Some(usize::from(byte - 0x40)),
        0x80..=0xFC => Some(63 + usize::from(byte - 0x80)),
        _ => None,
    }
}

/// Decode one byte that does not start a double-byte character.
fn single(byte: u8) -> char {
    match byte {
        0x00..=0x7F => byte as char,
        0x80 => '\u{0080}',
        0xA0 => '\u{F8F0}',
        0xA1..=0xDF => char::from_u32(0xFF61 + u32::from(byte - 0xA1)).unwrap_or(REPLACEMENT),
        0xFD => '\u{F8F1}',
        0xFE => '\u{F8F2}',
        0xFF => '\u{F8F3}',
        _ => REPLACEMENT,
    }
}

#[cfg(test)]
mod tests {
    use super::decode;

    #[test]
    fn ascii_and_halfwidth_katakana() {
        assert_eq!(decode(b"apple.png"), "apple.png");
        // 0xB1 is the halfwidth katakana "ｱ" (U+FF71).
        assert_eq!(decode(&[0xB1]), "ｱ");
    }

    #[test]
    fn double_byte_names() {
        // 0x82 0xA0 is "あ".
        assert_eq!(decode(&[0x82, 0xA0]), "あ");
        // "くしゃくしゃ.png" as stored in FIcon.wolf.
        assert_eq!(
            decode(&[
                0x82, 0xAD, 0x82, 0xB5, 0x82, 0xE1, 0x82, 0xAD, 0x82, 0xB5, 0x82, 0xE1, 0x2E, 0x70,
                0x6E, 0x67
            ]),
            "くしゃくしゃ.png"
        );
    }

    #[test]
    fn undefined_pairs_become_replacement_and_re_decode_the_trail() {
        assert_eq!(decode(&[0x81, 0x20]), "\u{FFFD} ");
        assert_eq!(decode(&[0x82]), "\u{FFFD}");
    }
}
