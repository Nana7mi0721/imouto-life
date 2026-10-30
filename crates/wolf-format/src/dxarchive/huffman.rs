//! Huffman decoder for DXArchive blocks (docs/FORMAT_SPEC.md §8.5).
//!
//! Blocks are produced by `Huffman_Encode` in
//! `docs/vendor/WolfDec-master/src/WolfDec/3rdParty/Huffman.cpp`: a bit-packed
//! header (the two sizes plus 256 delta-coded weights), then the symbols. The
//! header is read most-significant-bit first, while the symbol stream is read
//! least-significant-bit first from each byte — that asymmetry is the one part
//! of this format that is easy to get wrong.
//!
//! The reference decoder builds a nine-bit lookup table and has a special case
//! for the last 17 output bytes; both are pure optimisations, so this port
//! simply walks the tree from the root for every symbol, which yields identical
//! output.

use crate::error::{Error, Result};

/// Leaf symbols (`unsigned` char in the original).
const SYMBOL_COUNT: usize = 256;

/// Total nodes: one leaf per byte value plus one internal node per merge.
const NODE_COUNT: usize = 2 * SYMBOL_COUNT - 1;

/// Root of the finished tree: the last internal node built.
const ROOT: usize = NODE_COUNT - 1;

/// Ceiling for the initial allocation; a corrupt size field must not reserve
/// gigabytes up front.
const INITIAL_CAPACITY: usize = 1 << 20;

/// Most-significant-bit-first reader over a packed header.
struct BitReader<'a> {
    buffer: &'a [u8],
    byte: usize,
    bit: u8,
}

impl<'a> BitReader<'a> {
    const fn new(buffer: &'a [u8]) -> Self {
        Self {
            buffer,
            byte: 0,
            bit: 0,
        }
    }

    /// Read `bits` bits into the low end of the result, first bit most
    /// significant (`BitStream_Read` in the reference).
    fn read(&mut self, bits: u32) -> Result<u64> {
        let mut result = 0u64;
        for index in 0..bits {
            let byte = *self
                .buffer
                .get(self.byte)
                .ok_or_else(|| Error::eof(self.byte, 1, 0))?;
            let bit = (byte >> (7 - self.bit)) & 1;
            result |= u64::from(bit) << (bits - 1 - index);
            self.bit += 1;
            if self.bit == 8 {
                self.bit = 0;
                self.byte += 1;
            }
        }
        Ok(result)
    }

    /// Bytes consumed so far, rounding a partial byte up
    /// (`BitStream_GetBytes` in the reference).
    const fn consumed(&self) -> usize {
        self.byte + if self.bit == 0 { 0 } else { 1 }
    }
}

/// Decompress one Huffman block.
///
/// `what` names the block in error messages.
pub(super) fn decode(press: &[u8], what: &'static str) -> Result<Vec<u8>> {
    let mut reader = BitReader::new(press);
    let size_bits = reader.read(6)?;
    let original_size = reader.read(size_bits as u32 + 1)?;
    let press_bits = reader.read(6)?;
    let _press_size = reader.read(press_bits as u32 + 1)?;

    let mut weight = [0u16; SYMBOL_COUNT];
    for index in 0..SYMBOL_COUNT {
        let bit_num = (reader.read(3)? as u32 + 1) * 2;
        let minus = reader.read(1)?;
        let save = reader.read(bit_num)? as u16;
        weight[index] = if index == 0 {
            save
        } else if minus == 1 {
            weight[index - 1].wrapping_sub(save)
        } else {
            weight[index - 1].wrapping_add(save)
        };
    }
    let header_size = reader.consumed();
    if header_size > press.len() {
        return Err(Error::eof(header_size, 1, 0));
    }
    let press_data = &press[header_size..];

    // The tree is rebuilt exactly the way the encoder built it: the two
    // smallest-weight unclaimed nodes, lowest index first, ties resolved by the
    // ascending scan. Any deviation changes the emitted byte codes.
    let mut node_weight = [0u64; NODE_COUNT];
    let mut child = [[0usize; 2]; NODE_COUNT];
    let mut parent = [-1i32; NODE_COUNT];
    for (index, &symbol_weight) in weight.iter().enumerate() {
        node_weight[index] = u64::from(symbol_weight);
    }

    let mut data_num = SYMBOL_COUNT as i32;
    let mut node_num = SYMBOL_COUNT as i32;
    while data_num > 1 {
        let mut min_first: i32 = -1;
        let mut min_second: i32 = -1;
        let mut node_index = 0usize;
        let mut claimed = 0i32;
        while claimed < data_num && node_index < NODE_COUNT {
            if parent[node_index] != -1 {
                node_index += 1;
                continue;
            }
            claimed += 1;
            if min_first == -1 || node_weight[min_first as usize] > node_weight[node_index] {
                min_second = min_first;
                min_first = node_index as i32;
            } else if min_second == -1 || node_weight[min_second as usize] > node_weight[node_index]
            {
                min_second = node_index as i32;
            }
            node_index += 1;
        }
        if min_first == -1 || min_second == -1 {
            return Err(Error::field(
                what,
                0,
                "Huffman weight table does not describe a complete binary tree",
            ));
        }
        let first = min_first as usize;
        let second = min_second as usize;
        let parent_index = node_num as usize;
        node_weight[parent_index] = node_weight[first] + node_weight[second];
        child[parent_index] = [first, second];
        parent[first] = node_num;
        parent[second] = node_num;
        node_num += 1;
        data_num -= 1;
    }

    let dest_size = usize::try_from(original_size).map_err(|_| {
        Error::field(
            what,
            0,
            format!(
                "Huffman block declares {original_size} byte(s), which does not fit this platform"
            ),
        )
    })?;
    let mut out = Vec::with_capacity(dest_size.min(INITIAL_CAPACITY));

    // Each symbol is one least-significant-bit-first walk from the root.
    let mut bit_pos = 0usize;
    for _ in 0..dest_size {
        let mut node = ROOT;
        while node >= SYMBOL_COUNT {
            let byte_index = bit_pos / 8;
            let byte = *press_data
                .get(byte_index)
                .ok_or_else(|| Error::eof(header_size + byte_index, 1, 0))?;
            let bit = usize::from((byte >> (bit_pos % 8)) & 1);
            bit_pos += 1;
            node = child[node][bit];
        }
        out.push(node as u8);
    }

    Ok(out)
}

#[cfg(test)]
mod tests {
    use super::BitReader;

    #[test]
    fn reads_bits_most_significant_first() {
        let mut reader = BitReader::new(&[0b1010_0110, 0b1111_0000]);
        assert_eq!(reader.read(3).unwrap(), 0b101);
        assert_eq!(reader.read(1).unwrap(), 0b0);
        assert_eq!(reader.read(8).unwrap(), 0b0110_1111);
        assert_eq!(reader.consumed(), 2);
    }

    #[test]
    fn empty_block_decodes_to_nothing() {
        // OriginalSize = 0, PressSize = 0, then 256 zero-delta weights.
        let mut press: Vec<u8> = Vec::new();
        let mut byte = 0u8;
        let mut bits = 0u32;
        let mut push = |value: u32, width: u32| {
            for index in (0..width).rev() {
                let bit = ((value >> index) & 1) as u8;
                byte = (byte << 1) | bit;
                bits += 1;
                if bits == 8 {
                    press.push(byte);
                    byte = 0;
                    bits = 0;
                }
            }
        };
        push(0, 6); // OriginalSize uses one bit
        push(0, 1);
        push(0, 6); // PressSize uses one bit
        push(0, 1);
        for _ in 0..256 {
            push(0, 3); // BitNum = (0 + 1) * 2
            push(0, 1); // Minus
            push(0, 2); // SaveData
        }
        if bits != 0 {
            press.push(byte << (8 - bits));
        }
        assert_eq!(super::decode(&press, "test").unwrap(), Vec::<u8>::new());
    }
}
