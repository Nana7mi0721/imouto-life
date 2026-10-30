//! LZ77-style decompressor for DXArchive blocks (docs/FORMAT_SPEC.md §8.6).
//!
//! The block starts with a nine-byte header: the decompressed size, the size of
//! the coded stream (`+ 9`, so this field counts the whole block), and an escape
//! byte. Tokens are then either a literal, a doubled escape byte, or a
//! back-reference with a variable-width distance.
//!
//! Reference: `Decode` in
//! `docs/vendor/WolfDec-master/src/WolfDec/3rdParty/DXArchive.cpp` (line 1785).

use crate::error::{Error, Result};

/// `MIN_COMPRESS`: the shortest back-reference the encoder emits.
const MIN_COMPRESS: usize = 4;

/// Bytes of block header before the token stream.
const HEADER_SIZE: usize = 9;

/// Upper bound for the initial allocation; a corrupt size field must not be able
/// to reserve gigabytes up front.
const INITIAL_CAPACITY: usize = 1 << 24;

/// Decompress one LZ block.
///
/// `what` names the block in error messages. The distance is `index` and the
/// copy is byte by byte, so a run can overlap the bytes it reads — writing the
/// copy as a slice operation silently corrupts every run shorter than its
/// distance.
pub(super) fn decode(src: &[u8], what: &'static str) -> Result<Vec<u8>> {
    if src.len() < HEADER_SIZE {
        return Err(Error::field(
            what,
            0,
            format!(
                "LZ block is {} byte(s), shorter than its 9-byte header",
                src.len()
            ),
        ));
    }
    let dest_size = u32::from_le_bytes([src[0], src[1], src[2], src[3]]);
    let declared = u32::from_le_bytes([src[4], src[5], src[6], src[7]]);
    let Some(coded_size) = declared.checked_sub(HEADER_SIZE as u32) else {
        return Err(Error::field(
            what,
            4,
            format!("LZ block declares {declared} byte(s), less than its 9-byte header"),
        ));
    };
    let keycode = src[8];

    let dest_size = usize::try_from(dest_size).map_err(|_| {
        Error::field(
            what,
            0,
            format!("LZ block declares {dest_size} byte(s), which does not fit this platform"),
        )
    })?;
    let mut coded_size = coded_size as usize;
    let mut out = Vec::with_capacity(dest_size.min(INITIAL_CAPACITY));
    let mut sp = HEADER_SIZE;

    while coded_size > 0 {
        let byte = *src.get(sp).ok_or_else(|| Error::eof(sp, 1, 0))?;
        if byte != keycode {
            out.push(byte);
            sp += 1;
            coded_size -= 1;
            continue;
        }
        let next = *src.get(sp + 1).ok_or_else(|| Error::eof(sp + 1, 1, 0))?;
        if next == keycode {
            out.push(keycode);
            sp += 2;
            coded_size = coded_size.saturating_sub(2);
            continue;
        }

        // A back-reference: shrink the distance alphabet so the escape byte can
        // never appear inside it.
        let mut code = u32::from(next);
        if code > u32::from(keycode) {
            code -= 1;
        }
        sp += 2;
        coded_size = coded_size.saturating_sub(2);

        let mut length = (code >> 3) as usize;
        if code & 4 != 0 {
            let high = *src.get(sp).ok_or_else(|| Error::eof(sp, 1, 0))?;
            length |= usize::from(high) << 5;
            sp += 1;
            coded_size = coded_size.saturating_sub(1);
        }
        length += MIN_COMPRESS;

        let index_size = code & 3;
        let mut index = match index_size {
            0 => {
                let low = *src.get(sp).ok_or_else(|| Error::eof(sp, 1, 0))?;
                sp += 1;
                coded_size = coded_size.saturating_sub(1);
                u32::from(low)
            }
            1 => {
                let bytes = src.get(sp..sp + 2).ok_or_else(|| Error::eof(sp, 2, 0))?;
                sp += 2;
                coded_size = coded_size.saturating_sub(2);
                u32::from(u16::from_le_bytes([bytes[0], bytes[1]]))
            }
            2 => {
                let bytes = src.get(sp..sp + 3).ok_or_else(|| Error::eof(sp, 3, 0))?;
                sp += 3;
                coded_size = coded_size.saturating_sub(3);
                u32::from(u16::from_le_bytes([bytes[0], bytes[1]])) | (u32::from(bytes[2]) << 16)
            }
            _ => {
                return Err(Error::field(
                    what,
                    sp,
                    "LZ token uses a 3-byte distance, which the format never emits",
                ))
            }
        };
        index += 1;

        let index = index as usize;
        if index > out.len() {
            return Err(Error::field(
                what,
                sp,
                format!(
                    "LZ back-reference distance {index} exceeds the {} byte(s) decoded so far",
                    out.len()
                ),
            ));
        }
        // Byte by byte on purpose: the run may overlap itself.
        for _ in 0..length {
            let byte = out[out.len() - index];
            out.push(byte);
        }
    }

    if out.len() != dest_size {
        return Err(Error::field(
            what,
            0,
            format!(
                "LZ block decoded to {} byte(s), header declares {dest_size}",
                out.len()
            ),
        ));
    }
    Ok(out)
}

#[cfg(test)]
mod tests {
    use super::decode;

    #[test]
    fn literals_doubled_escapes_and_overlapping_runs() {
        // destsize 11, keycode 0xFF: "ab" then a doubled escape, then a run of 8
        // bytes copied from distance 2 (overlapping on purpose).
        let mut block = Vec::new();
        block.extend_from_slice(&11u32.to_le_bytes());
        block.extend_from_slice(&16u32.to_le_bytes()); // whole block: 9-byte header + 7 coded bytes
        block.push(0xFF);
        block.extend_from_slice(b"ab");
        block.extend_from_slice(&[0xFF, 0xFF]);
        // code: length 8 - MIN_COMPRESS(4) = 4 -> code = 4 << 3 = 32, distance 2 - 1 = 1 -> 1-byte index
        block.push(0xFF);
        block.push(32);
        block.push(1);
        assert_eq!(block.len(), 9 + 7);
        assert_eq!(
            decode(&block, "test").unwrap(),
            b"ab\xFFb\xFFb\xFFb\xFFb\xFF"
        );
    }
}
