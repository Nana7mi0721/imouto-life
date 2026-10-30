//! DXArchive **version 6** (old-generation) reader.
//!
//! WOLF RPG Editor 2.xx games ship their assets in the pre-2016 DXArchive
//! layout. It differs from the modern v8 container this module otherwise reads
//! in almost every way:
//!
//! * the 48-byte `DARC_HEAD_VER6` is itself XOR-obfuscated (the v8 header is
//!   plaintext), so even the magic is hidden;
//! * the XOR key is one fixed twelve-byte archive-wide stream, derived by
//!   `KeyCreate` from the built-in "Wolf RPG v2.20" key string -- there is no
//!   per-file CRC key;
//! * the file-head record is 64 bytes and the directory record 32, and file
//!   bodies are addressed relative to `DataStartAddress` while the file and
//!   directory tables are addressed relative to the name table.
//!
//! The reference implementation is
//! `docs/vendor/uberwolf-ref/DXLib/DXArchiveVer6.cpp` (`Decode` at line 1343,
//! `DecodeArchive` at line 1758). The body decompressor is byte-for-byte the
//! same LZ77 variant as v8, so it reuses `super::lz`; only the container and the
//! key differ.

use crate::bytes::Reader;
use crate::error::{Error, Result};

use super::lz;
use super::{ArchiveEntry, NO_COMPRESSION};

/// `DXA_HEAD_VER6`: the two ASCII bytes `DX`, little-endian once decrypted.
const DXA_HEAD: u16 = 0x5844;

/// Size of the plaintext `DARC_HEAD_VER6` that starts every v6 archive.
pub(super) const HEAD_SIZE_VER6: usize = 48;

/// `DARC_FILEHEAD_VER6` is eight `u64`s (name, attributes, three times, three
/// data fields).
pub(super) const FILE_HEAD_SIZE_VER6: usize = 64;

/// `DARC_DIRECTORY_VER6` is four `u64`s.
pub(super) const DIRECTORY_SIZE_VER6: usize = 32;

/// `DXA_KEYSTR_LENGTH_VER6`: the XOR key is twelve bytes wide.
const KEY_LEN: usize = 12;

/// `FILE_ATTRIBUTE_DIRECTORY`: marks a directory file-head.
const ATTRIBUTE_DIRECTORY: u64 = 0x0010;

/// Deepest directory nesting accepted, as a guard against a cyclic tree.
const MAX_DEPTH: usize = 32;

/// The fixed "Wolf RPG v2.20" key string used by old-generation archives.
///
/// This is the `DEFAULT_CRYPT_MODES` entry for WOLF RPG v2.20; `KeyCreate`
/// transforms it into the twelve-byte XOR stream
/// `c7 05 ca 7d 8d e3 de f1 d9 0c 85 f4`.
const KEY_SRC_V220: [u8; KEY_LEN] = [
    0x38, 0x50, 0x40, 0x28, 0x72, 0x4f, 0x21, 0x70, 0x3b, 0x73, 0x35, 0x38,
];

/// Decoded `DARC_HEAD_VER6`, the fields that survive header decryption.
#[derive(Debug, Clone, Copy)]
pub(super) struct HeadVer6 {
    /// Archive version (6 for the archives this reader targets, 6..=8 valid).
    pub(super) version: u16,
    /// `DARC_HEAD_VER6.HeadSize`: the size of the name/file/directory tables.
    pub(super) head_size: u32,
    /// Offset of the first file body; file addresses are relative to this.
    pub(super) data_start: u64,
    /// Offset of the head region (the "NameP" table base).
    pub(super) file_name_table_start: u64,
    /// Offset of the file table inside the head region.
    pub(super) file_table_start: u64,
    /// Offset of the directory table inside the head region.
    pub(super) directory_table_start: u64,
    /// Code page of the stored names, 932 (Shift-JIS) for WOLF archives.
    pub(super) code_page: u32,
}

/// A parsed v6 archive: the header plus the twelve-byte archive-wide key.
#[derive(Debug, Clone)]
pub(super) struct Ver6 {
    pub(super) head: HeadVer6,
    key: [u8; KEY_LEN],
}

/// Parse a v6 archive and walk its directory tree.
pub(super) fn open(data: &[u8]) -> Result<(Ver6, Vec<ArchiveEntry>)> {
    let key = key_create(&KEY_SRC_V220);
    let head = parse_header(data, &key)?;
    let head_bytes = read_head_region(data, &head, &key)?;
    let entries = Tables {
        head: &head_bytes,
        file_table: super::size_of(head.file_table_start)?,
        directory_table: super::size_of(head.directory_table_start)?,
    }
    .walk_all(&head, data)?;
    Ok((Ver6 { head, key }, entries))
}

/// Decrypt and parse the 48-byte v6 header.
fn parse_header(data: &[u8], key: &[u8; KEY_LEN]) -> Result<HeadVer6> {
    const WHAT: &str = "DXArchive v6 head";
    let mut raw = super::slice_of(data, 0, HEAD_SIZE_VER6, WHAT)?.to_vec();
    key_conv(&mut raw, key, 0);

    let mut reader = Reader::new(&raw);
    let head = reader.u16()?;
    if head != DXA_HEAD {
        return Err(Error::magic(
            WHAT,
            0,
            &head.to_le_bytes(),
            &DXA_HEAD.to_le_bytes(),
        ));
    }
    let version = reader.u16()?;
    if !(6..=8).contains(&version) {
        return Err(Error::field(
            WHAT,
            2,
            format!("unsupported old-generation archive version 0x{version:04X}"),
        ));
    }
    let head_size = reader.u32()?;
    let data_start = reader.u64()?;
    let file_name_table_start = reader.u64()?;
    let file_table_start = reader.u64()?;
    let directory_table_start = reader.u64()?;
    let code_page = reader.u32()?;

    if directory_table_start.saturating_add(DIRECTORY_SIZE_VER6 as u64) > u64::from(head_size) {
        return Err(Error::field(
            WHAT,
            32,
            format!(
                "DirectoryTableStartAddress {directory_table_start} plus the 32-byte root directory exceeds HeadSize {head_size}"
            ),
        ));
    }

    Ok(HeadVer6 {
        version,
        head_size,
        data_start,
        file_name_table_start,
        file_table_start,
        directory_table_start,
        code_page,
    })
}

/// Decrypt the head region: the file-name, file and directory tables live in
/// `HeadSize` bytes starting at `FileNameTableStartAddress`, XORed from
/// position zero. Unlike v8 there is no Huffman/LZ stage on the head.
fn read_head_region(data: &[u8], head: &HeadVer6, key: &[u8; KEY_LEN]) -> Result<Vec<u8>> {
    const WHAT: &str = "DXArchive v6 head region";
    let start = super::size_of(head.file_name_table_start)?;
    let len = head.head_size as usize;
    let mut bytes = super::slice_of(data, start, len, WHAT)?.to_vec();
    key_conv(&mut bytes, key, 0);
    Ok(bytes)
}

impl Ver6 {
    /// Decompress one entry, returning its exact original bytes.
    ///
    /// The body is XOR-decrypted from position `entry.size` (the *plaintext*
    /// size, not the archive offset) and then, when the file-head records a
    /// press size, run through the shared LZ decoder. Unpressed bodies are the
    /// decrypted bytes verbatim.
    pub(super) fn read(&self, data: &[u8], entry: &ArchiveEntry) -> Result<Vec<u8>> {
        const WHAT: &str = "DXArchive v6 file data";
        let dest = super::size_of(entry.size)?;
        if dest == 0 {
            return Ok(Vec::new());
        }
        let offset = super::size_of(entry.data_offset)?;
        if entry.press_size != NO_COMPRESSION {
            let mut coded =
                super::slice_of(data, offset, super::size_of(entry.press_size)?, WHAT)?.to_vec();
            key_conv(&mut coded, &self.key, entry.size);
            return super::expect_size(lz::decode(&coded, WHAT)?, dest, WHAT, entry.data_offset);
        }
        let mut raw = super::slice_of(data, offset, dest, WHAT)?.to_vec();
        key_conv(&mut raw, &self.key, entry.size);
        Ok(raw)
    }
}

/// The name-table, file-table and directory-table segments of the head region.
struct Tables<'a> {
    head: &'a [u8],
    file_table: usize,
    directory_table: usize,
}

/// One `DARC_DIRECTORY_VER6` record.
///
/// Only the two fields the tree walk needs are kept; `DirectoryAddress` and
/// `ParentDirectoryAddress` are read (and discarded) to validate the record.
struct Directory {
    file_head_num: u64,
    file_head_address: u64,
}

/// One `DARC_FILEHEAD_VER6` record.
struct FileHead {
    name_address: u64,
    attributes: u64,
    data_address: u64,
    data_size: u64,
    press_data_size: u64,
}

impl<'a> Tables<'a> {
    /// One `DARC_DIRECTORY_VER6`, at `offset` inside the directory table.
    fn directory(&self, offset: u64) -> Result<Directory> {
        const WHAT: &str = "DXArchive v6 directory table";
        let at = self
            .directory_table
            .checked_add(super::size_of(offset)?)
            .ok_or_else(|| {
                Error::field(
                    WHAT,
                    self.directory_table,
                    "directory offset overflows usize",
                )
            })?;
        let mut reader = Reader::new(super::slice_of(self.head, at, DIRECTORY_SIZE_VER6, WHAT)?);
        let _directory_address = reader.u64()?;
        let _parent_directory_address = reader.u64()?;
        let file_head_num = reader.u64()?;
        let file_head_address = reader.u64()?;
        Ok(Directory {
            file_head_num,
            file_head_address,
        })
    }

    /// One `DARC_FILEHEAD_VER6`, at `offset` inside the file table.
    fn file_head(&self, offset: u64) -> Result<FileHead> {
        const WHAT: &str = "DXArchive v6 file table";
        let at = self
            .file_table
            .checked_add(super::size_of(offset)?)
            .ok_or_else(|| {
                Error::field(WHAT, self.file_table, "file head offset overflows usize")
            })?;
        let mut reader = Reader::new(super::slice_of(self.head, at, FILE_HEAD_SIZE_VER6, WHAT)?);
        let name_address = reader.u64()?;
        let attributes = reader.u64()?;
        reader.skip(24)?; // DARC_FILETIME: create, last access, last write.
        Ok(FileHead {
            name_address,
            attributes,
            data_address: reader.u64()?,
            data_size: reader.u64()?,
            press_data_size: reader.u64()?,
        })
    }

    /// The original-case name of a name-table entry.
    ///
    /// The record is: `u16 pack`, `u16 parity`, `pack*4` bytes of uppercased
    /// name, then the NUL-terminated original-case CP932 name.
    fn name(&self, address: u64) -> Result<String> {
        const WHAT: &str = "DXArchive v6 name table";
        let at = super::size_of(address)?;
        let rest = super::slice_of(self.head, at, self.head.len().saturating_sub(at), WHAT)?;
        let mut reader = Reader::new(rest);
        let pack = reader.u16()?;
        let _parity = reader.u16()?;
        let skip = usize::from(pack)
            .checked_mul(4)
            .ok_or_else(|| Error::field(WHAT, at, "name pack count overflows usize"))?;
        reader.skip(skip)?;
        let tail = &rest[reader.pos()..];
        let end = tail
            .iter()
            .position(|&byte| byte == 0)
            .ok_or_else(|| Error::field(WHAT, at, "file name is not NUL terminated"))?;
        Ok(super::decode_cp932(&tail[..end]))
    }

    /// Walk the whole tree starting at the archive root (directory offset 0).
    fn walk_all(&self, head: &HeadVer6, _data: &[u8]) -> Result<Vec<ArchiveEntry>> {
        let mut out = Vec::new();
        self.walk(0, "", 0, head.data_start, &mut out)?;
        Ok(out)
    }

    /// Walk one directory and everything below it, appending files to `out`.
    fn walk(
        &self,
        dir_offset: u64,
        prefix: &str,
        depth: usize,
        data_start: u64,
        out: &mut Vec<ArchiveEntry>,
    ) -> Result<()> {
        const WHAT: &str = "DXArchive v6 directory tree";
        if depth > MAX_DEPTH {
            return Err(Error::field(
                WHAT,
                self.directory_table,
                "directory nesting is too deep",
            ));
        }
        let directory = self.directory(dir_offset)?;

        for index in 0..directory.file_head_num {
            let slot = index
                .checked_mul(FILE_HEAD_SIZE_VER6 as u64)
                .and_then(|step| directory.file_head_address.checked_add(step))
                .ok_or_else(|| {
                    Error::field(WHAT, self.file_table, "file head index overflows u64")
                })?;
            let file = self.file_head(slot)?;
            let name = self.name(file.name_address)?;

            if file.attributes & ATTRIBUTE_DIRECTORY != 0 {
                let mut child = String::with_capacity(prefix.len() + name.len() + 1);
                child.push_str(prefix);
                child.push_str(&name);
                child.push('/');
                self.walk(file.data_address, &child, depth + 1, data_start, out)?;
                continue;
            }

            let data_offset = data_start.checked_add(file.data_address).ok_or_else(|| {
                Error::field(WHAT, self.file_table, "file body offset overflows u64")
            })?;
            let directory_path = prefix.strip_suffix('/').unwrap_or(prefix);
            out.push(ArchiveEntry {
                name,
                directory: directory_path.to_string(),
                data_offset,
                size: file.data_size,
                press_size: file.press_data_size,
                huff_press_size: NO_COMPRESSION,
                is_compressed: file.press_data_size != NO_COMPRESSION,
                upper_name: Vec::new(),
                ancestor_names: Vec::new(),
            });
        }
        Ok(())
    }
}

/// Derive the twelve-byte v6 XOR key from a key source (`KeyCreate`).
///
/// The source is copied (and, when short, repeated) to twelve bytes, then each
/// byte is scrambled by a fixed invert/rotate/XOR step.
fn key_create(source: &[u8]) -> [u8; KEY_LEN] {
    let mut key = [0u8; KEY_LEN];
    if source.is_empty() {
        key = [0xAA; KEY_LEN];
    } else if source.len() > KEY_LEN {
        key.copy_from_slice(&source[..KEY_LEN]);
    } else {
        let mut index = 0;
        while index + source.len() <= KEY_LEN {
            key[index..index + source.len()].copy_from_slice(source);
            index += source.len();
        }
        if index < KEY_LEN {
            let remainder = KEY_LEN - index;
            key[index..].copy_from_slice(&source[..remainder]);
        }
    }

    key[0] = !key[0];
    key[1] = key[1].rotate_left(4);
    key[2] ^= 0x8a;
    key[3] = !key[3].rotate_left(4);
    key[4] = !key[4];
    key[5] ^= 0xac;
    key[6] = !key[6];
    key[7] = !key[7].rotate_left(5);
    key[8] = key[8].rotate_left(3);
    key[9] ^= 0x7f;
    key[10] = key[10].rotate_left(4) ^ 0xd6;
    key[11] ^= 0xcc;
    key
}

/// XOR `data` with the twelve-byte v6 key, resuming the cycle at `position`.
fn key_conv(data: &mut [u8], key: &[u8; KEY_LEN], position: u64) {
    let mut index = (position % KEY_LEN as u64) as usize;
    for byte in data.iter_mut() {
        *byte ^= key[index];
        index += 1;
        if index == KEY_LEN {
            index = 0;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::{key_conv, key_create, KEY_SRC_V220};

    #[test]
    fn key_create_derives_the_measured_v220_key() {
        assert_eq!(
            key_create(&KEY_SRC_V220),
            [0xC7, 0x05, 0xCA, 0x7D, 0x8D, 0xE3, 0xDE, 0xF1, 0xD9, 0x0C, 0x85, 0xF4]
        );
    }

    #[test]
    fn key_conv_is_a_twelve_byte_cycle_at_position() {
        let key = [1u8, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];
        let mut data = [0u8; 14];
        key_conv(&mut data, &key, 10);
        assert_eq!(data, [11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]);
    }
}
