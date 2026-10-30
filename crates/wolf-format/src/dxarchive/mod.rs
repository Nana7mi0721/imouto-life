//! `.wolf` archives are DXArchive containers.
//!
//! Version 8 is the modern layout described first and in most detail here. The
//! old-generation version 6 layout (pre-2016 WOLF RPG Editor titles) lives in
//! the `ver6` submodule; [`DxArchive::open`] chooses between the two from the
//! header.
//!
//! WOLF RPG Editor keeps its assets in DxLib's DXArchive format. A version 8
//! archive is a 64-byte plaintext header, the file bodies, and one "head" region
//! that holds the name table, the file-head table and the directory table. The
//! head region is itself compressed (Huffman over LZ), and every byte after the
//! header is XOR-obfuscated with a key that CRC-32 derives from the archive key
//! string plus the file's uppercased Shift-JIS name. Extraction is therefore a
//! chain: header -> global key -> head region -> name table -> directory tree ->
//! per-file key -> Huffman + LZ -> file bytes.
//!
//! See `docs/FORMAT_SPEC.md` §8 for the layout and §8.3 for key provenance. The
//! reference implementation is
//! `docs/vendor/WolfDec-master/src/WolfDec/3rdParty/DXArchive.cpp`
//! (`DecodeArchive` at line 2525, `DirectoryDecode` at line 1049).

mod cp932;
mod crc32;
mod huffman;
mod key;
mod lz;
mod sjis;
mod ver6;

use crate::bytes::Reader;
use crate::error::{Error, Result};
use key::{key_conv, key_create, KEY_BYTES};

/// Decode CP932 (Shift-JIS) bytes into a string.
///
/// Exposed crate-wide for the .project name tables: the 2.00 generation stores
/// them in the editor code page rather than UTF-8.
#[must_use]
pub(crate) fn decode_cp932(bytes: &[u8]) -> String {
    sjis::decode(bytes)
}

/// Size of the plaintext `DARC_HEAD` that starts every archive.
pub const HEADER_SIZE: usize = 64;

/// The only archive version this module reads (`DXA_VER`).
pub const VERSION: u16 = 8;

/// `DARC_HEAD.Head`: the two ASCII bytes `DX`, little-endian.
const DXA_HEAD: u16 = 0x5844;

/// `DARC_FILEHEAD` is nine `u64`s.
const FILE_HEAD_SIZE: usize = 72;

/// `DARC_DIRECTORY` is four `u64`s.
const DIRECTORY_SIZE: usize = 32;

/// "This stream is not compressed", as stored in both compressed-size fields.
pub const NO_COMPRESSION: u64 = u64::MAX;

/// `DXA_FLAG_NO_KEY`: the archive is not obfuscated at all.
const FLAG_NO_KEY: u32 = 0x0000_0001;

/// `DXA_FLAG_NO_HEAD_PRESS`: the head region is stored uncompressed.
const FLAG_NO_HEAD_PRESS: u32 = 0x0000_0002;

/// `DARC_FILEHEAD.Attributes` bit that marks a directory.
const ATTRIBUTE_DIRECTORY: u64 = 0x0010;

/// `HuffmanEncodeKB` value meaning "no head/tail split" (`0xFF`).
const HUFFMAN_KB_WHOLE: u8 = 0xFF;

/// Read granularity for stored entries (`DXA_BUFFERSIZE`).
const COPY_CHUNK: usize = 0x1000_0000;

/// Deepest directory nesting accepted, as a guard against a cyclic tree.
const MAX_DEPTH: usize = 32;

/// Decoded `DARC_HEAD` (docs/FORMAT_SPEC.md §8.2).
#[derive(Debug, Clone, Copy)]
struct DarcHead {
    version: u16,
    head_size: u32,
    data_start_address: u64,
    file_name_table_start_address: u64,
    file_table_start_address: u64,
    directory_table_start_address: u64,
    char_code_format: u32,
    flags: u32,
    huffman_encode_kb: u8,
}

impl DarcHead {
    /// Parse and sanity-check the 64 header bytes at the start of `data`.
    fn parse(data: &[u8]) -> Result<Self> {
        let mut reader = Reader::new(data);
        let head = reader.u16()?;
        if head != DXA_HEAD {
            return Err(Error::magic(
                "DXArchive head",
                0,
                &head.to_le_bytes(),
                &DXA_HEAD.to_le_bytes(),
            ));
        }
        let version = reader.u16()?;
        if version != VERSION {
            return Err(Error::field(
                "DXArchive head",
                2,
                format!(
                    "unsupported archive version 0x{version:04X}, only 0x{VERSION:04X} is readable"
                ),
            ));
        }
        let parsed = Self {
            version,
            head_size: reader.u32()?,
            data_start_address: reader.u64()?,
            file_name_table_start_address: reader.u64()?,
            file_table_start_address: reader.u64()?,
            directory_table_start_address: reader.u64()?,
            char_code_format: reader.u32()?,
            flags: reader.u32()?,
            huffman_encode_kb: reader.u8()?,
        };
        reader.skip(15)?; // Reserve, always zero.

        // §8.1: the root directory is the last thing in the head region, so the
        // two offsets must agree. Checked because a mismatch means a truncated
        // archive or one written by a different tool.
        if parsed
            .directory_table_start_address
            .saturating_add(DIRECTORY_SIZE as u64)
            != u64::from(parsed.head_size)
        {
            return Err(Error::field(
                "DXArchive head",
                32,
                format!(
                    "DirectoryTableStartAddress {} plus the 32-byte root directory should equal HeadSize {}",
                    parsed.directory_table_start_address, parsed.head_size
                ),
            ));
        }
        Ok(parsed)
    }
}
// structural append probe
/// One file inside a .wolf archive.
///
/// `name` and `directory` are decoded from Shift-JIS: the name table stores a
/// Shift-JIS copy of the name in `CharCodeFormat` encoding, which is 932 for
/// every known WOLF archive (FORMAT_SPEC 8.4 step 4).
#[derive(Debug, Clone)]
pub struct ArchiveEntry {
    /// File name as Unicode, decoded from Shift-JIS.
    pub name: String,
    /// Parent directory path with slash separators; empty at the archive root.
    pub directory: String,
    /// Absolute offset of the file body inside the archive.
    pub data_offset: u64,
    /// Uncompressed size in bytes.
    pub size: u64,
    /// Size of the LZ-compressed body, or NO_COMPRESSION when absent.
    pub press_size: u64,
    /// Size of the Huffman-compressed body, or NO_COMPRESSION when absent.
    pub huff_press_size: u64,
    /// Whether the body is stored compressed at all.
    pub is_compressed: bool,
    /// Uppercased Shift-JIS name bytes: the first part of this file's key
    /// source (FORMAT_SPEC 8.4 step 6).
    upper_name: Vec<u8>,
    /// Uppercased ancestor directory names concatenated nearest-first, with the
    /// archive root left out. Only the concatenation is ever used: it is the
    /// tail of this file's key source (FORMAT_SPEC 8.4 step 6).
    ancestor_names: Vec<u8>,
}

impl ArchiveEntry {
    /// Path of the entry inside the archive, as "directory/name".
    #[must_use]
    pub fn path(&self) -> String {
        if self.directory.is_empty() {
            return self.name.clone();
        }
        let mut path = String::with_capacity(self.directory.len() + 1 + self.name.len());
        path.push_str(&self.directory);
        path.push('/');
        path.push_str(&self.name);
        path
    }
}
/// A parsed .wolf archive, ready to hand out file contents.
///
/// The whole archive is copied into memory: per-file keys depend on the
/// directory tree, and the Huffman stage looks both backwards and forwards
/// inside a body, so borrowed slices would buy nothing.
#[derive(Debug, Clone)]
pub struct DxArchive {
    data: Vec<u8>,
    backend: Backend,
    entries: Vec<ArchiveEntry>,
}

/// Version-specific state kept beside the archive bytes.
#[derive(Debug, Clone)]
enum Backend {
    /// Modern (v8) archives: plaintext 64-byte header, per-file CRC key.
    V8(V8),
    /// Old-generation (v6) archives: XOR-obfuscated 48-byte header and one
    /// twelve-byte archive-wide key.
    V6(ver6::Ver6),
}

/// The v8 header fields and archive-wide key.
#[derive(Debug, Clone)]
struct V8 {
    head: DarcHead,
    crypt_version: u16,
    key_string: Vec<u8>,
    no_key: bool,
}

impl DxArchive {
    /// Parse an archive, dispatching on its version.
    ///
    /// A plaintext v8 header is recognised by its `DX` magic at offset 0. The v6
    /// header is itself XOR-obfuscated, so its first two bytes are not the magic;
    /// anything without the plaintext magic is tried as a v6 archive, whose
    /// parser reports a precise error when it is neither.
    pub fn open(data: &[u8]) -> Result<Self> {
        if data.len() >= 2 && u16::from_le_bytes([data[0], data[1]]) == DXA_HEAD {
            Self::open_v8(data)
        } else {
            Self::open_ver6(data)
        }
    }

    /// Parse a modern (v8) archive. `data` must start with a plaintext header.
    fn open_v8(data: &[u8]) -> Result<Self> {
        let head = DarcHead::parse(data)?;

        // FORMAT_SPEC 8.2: the low 16 bits are flags, the high 16 bits are the
        // crypt version that selects the built-in key (8.3).
        let no_key = head.flags & FLAG_NO_KEY != 0;
        let crypt_version = (head.flags >> 16) as u16;
        let key_string = match key::mode_key(crypt_version) {
            Some(key) => key.to_vec(),
            None if no_key => Vec::new(),
            None => {
                return Err(Error::field(
                    "DXArchive head",
                    44,
                    format!("no built-in key for crypt version 0x{crypt_version:04X}"),
                ));
            }
        };

        let head_bytes = read_head_region(data, &head, &key_string, !no_key)?;
        let tables = Tables {
            head: &head_bytes,
            file_table: size_of(head.file_table_start_address)?,
            directory_table: size_of(head.directory_table_start_address)?,
        };
        let mut entries = Vec::new();
        tables.walk(0, "", 0, head.data_start_address, &mut entries)?;

        Ok(Self {
            data: data.to_vec(),
            backend: Backend::V8(V8 {
                head,
                crypt_version,
                key_string,
                no_key,
            }),
            entries,
        })
    }

    /// Parse an old-generation (v6) archive; see the `ver6` submodule.
    fn open_ver6(data: &[u8]) -> Result<Self> {
        let (state, entries) = ver6::open(data)?;
        Ok(Self {
            data: data.to_vec(),
            backend: Backend::V6(state),
            entries,
        })
    }
    /// Archive version from the header.
    #[must_use]
    pub fn version(&self) -> u16 {
        match &self.backend {
            Backend::V8(v8) => v8.head.version,
            Backend::V6(v6) => v6.head.version,
        }
    }

    /// Character code of the stored names, 932 (Shift-JIS) for WOLF archives.
    #[must_use]
    pub fn char_code_format(&self) -> u32 {
        match &self.backend {
            Backend::V8(v8) => v8.head.char_code_format,
            Backend::V6(v6) => v6.head.code_page,
        }
    }

    /// Raw Flags word: low 16 bits are flags, high 16 bits the crypt version.
    /// Old-generation archives have no flag word, so this is zero.
    #[must_use]
    pub fn flags(&self) -> u32 {
        match &self.backend {
            Backend::V8(v8) => v8.head.flags,
            Backend::V6(_) => 0,
        }
    }

    /// Crypt version taken from the high half of Flags (FORMAT_SPEC 8.3). Old
    /// archives use one fixed key and expose no crypt version, so this is zero.
    #[must_use]
    pub fn crypt_version(&self) -> u16 {
        match &self.backend {
            Backend::V8(v8) => v8.crypt_version,
            Backend::V6(_) => 0,
        }
    }

    /// HuffmanEncodeKB, which sizes the head/tail split of compressed bodies.
    /// Old archives never split, so this is zero.
    #[must_use]
    pub fn huffman_encode_kb(&self) -> u8 {
        match &self.backend {
            Backend::V8(v8) => v8.head.huffman_encode_kb,
            Backend::V6(_) => 0,
        }
    }

    /// Whether the bodies are XOR-obfuscated.
    #[must_use]
    pub fn is_encrypted(&self) -> bool {
        match &self.backend {
            Backend::V8(v8) => !v8.no_key,
            Backend::V6(_) => true,
        }
    }

    /// Start offset of the raw file data.
    #[must_use]
    pub fn data_start_address(&self) -> u64 {
        match &self.backend {
            Backend::V8(v8) => v8.head.data_start_address,
            Backend::V6(v6) => v6.head.data_start,
        }
    }

    /// All files, in directory-tree order.
    #[must_use]
    pub fn entries(&self) -> &[ArchiveEntry] {
        &self.entries
    }

    /// Find an entry by root-level name, or failing that by its full path.
    #[must_use]
    pub fn entry(&self, name: &str) -> Option<&ArchiveEntry> {
        if let Some(found) = self.entries.iter().find(|entry| entry.name == name) {
            return Some(found);
        }
        self.entries.iter().find(|entry| entry.path() == name)
    }
    /// Decompress one entry, returning its exact original bytes.
    pub fn read(&self, entry: &ArchiveEntry) -> Result<Vec<u8>> {
        match &self.backend {
            Backend::V8(v8) => self.read_v8(entry, v8),
            Backend::V6(v6) => v6.read(&self.data, entry),
        }
    }

    /// Decompress one version 8 entry, returning its exact original bytes.
    ///
    /// Four storage shapes exist (FORMAT_SPEC 8.4 step 7); the two size fields
    /// say which one applies, and NO_COMPRESSION marks the absent stage.
    fn read_v8(&self, entry: &ArchiveEntry, v8: &V8) -> Result<Vec<u8>> {
        let dest_size = size_of(entry.size)?;
        if dest_size == 0 {
            return Ok(Vec::new());
        }
        let key = self.file_key(v8, entry);
        let whole_block = usize::from(v8.head.huffman_encode_kb) * 1024;
        let split = v8.head.huffman_encode_kb != HUFFMAN_KB_WHOLE;
        let press = entry.press_size;
        let huff = entry.huff_press_size;

        if press != NO_COMPRESSION && huff != NO_COMPRESSION {
            // Huffman over LZ. The Huffman stage starts at the file's plaintext
            // size, not at zero, because the encoder only reset its key there.
            let mut coded = self.body(entry.data_offset, huff)?.to_vec();
            if let Some(key) = key.as_ref() {
                key_conv(&mut coded, key, entry.size);
            }
            let decoded = huffman::decode(&coded, "DXArchive file data")?;
            let coded_size = size_of(press)?;
            let lz = if split && coded_size > whole_block * 2 {
                // The encoder Huffman-coded only the head and the tail of the
                // LZ stream; the middle stays in the archive, XORed separately.
                if decoded.len() < whole_block * 2 {
                    return Err(Error::field(
                        "DXArchive file data",
                        entry.data_offset as usize,
                        format!(
                            "Huffman stage returned {} byte(s) but the head/tail split needs {}",
                            decoded.len(),
                            whole_block * 2
                        ),
                    ));
                }
                let middle_len = coded_size - whole_block * 2;
                let mut rebuilt = vec![0u8; coded_size];
                rebuilt[..whole_block].copy_from_slice(&decoded[..whole_block]);
                rebuilt[whole_block..whole_block + middle_len]
                    .copy_from_slice(self.body(entry.data_offset + huff, middle_len as u64)?);
                if let Some(key) = key.as_ref() {
                    key_conv(
                        &mut rebuilt[whole_block..whole_block + middle_len],
                        key,
                        entry.size.wrapping_add(huff),
                    );
                }
                rebuilt[coded_size - whole_block..]
                    .copy_from_slice(&decoded[whole_block..whole_block * 2]);
                rebuilt
            } else {
                if decoded.len() < coded_size {
                    return Err(Error::field(
                        "DXArchive file data",
                        entry.data_offset as usize,
                        format!(
                            "Huffman stage returned {} byte(s) but the LZ stream needs {}",
                            decoded.len(),
                            coded_size
                        ),
                    ));
                }
                decoded[..coded_size].to_vec()
            };
            return expect_size(
                lz::decode(&lz, "DXArchive file data")?,
                dest_size,
                "DXArchive file data",
                entry.data_offset,
            );
        }

        if press != NO_COMPRESSION {
            // LZ only: one key reset at the file's plaintext size.
            let mut coded = self.body(entry.data_offset, press)?.to_vec();
            if let Some(key) = key.as_ref() {
                key_conv(&mut coded, key, entry.size);
            }
            return expect_size(
                lz::decode(&coded, "DXArchive file data")?,
                dest_size,
                "DXArchive file data",
                entry.data_offset,
            );
        }
        if huff != NO_COMPRESSION {
            // Huffman only: no LZ stage, so the output is the plaintext itself.
            let mut coded = self.body(entry.data_offset, huff)?.to_vec();
            if let Some(key) = key.as_ref() {
                key_conv(&mut coded, key, entry.size);
            }
            let decoded = huffman::decode(&coded, "DXArchive file data")?;
            if split && dest_size > whole_block * 2 {
                if decoded.len() < whole_block * 2 {
                    return Err(Error::field(
                        "DXArchive file data",
                        entry.data_offset as usize,
                        format!(
                            "Huffman stage returned {} byte(s) but the head/tail split needs {}",
                            decoded.len(),
                            whole_block * 2
                        ),
                    ));
                }
                let middle_len = dest_size - whole_block * 2;
                let mut rebuilt = vec![0u8; dest_size];
                rebuilt[..whole_block].copy_from_slice(&decoded[..whole_block]);
                rebuilt[whole_block..whole_block + middle_len]
                    .copy_from_slice(self.body(entry.data_offset + huff, middle_len as u64)?);
                if let Some(key) = key.as_ref() {
                    key_conv(
                        &mut rebuilt[whole_block..whole_block + middle_len],
                        key,
                        entry.size.wrapping_add(huff),
                    );
                }
                rebuilt[dest_size - whole_block..]
                    .copy_from_slice(&decoded[whole_block..whole_block * 2]);
                return Ok(rebuilt);
            }
            return expect_size(decoded, dest_size, "DXArchive file data", entry.data_offset);
        }

        // Stored: copy in buffer-sized chunks. The phase advances with the
        // bytes already written, so a chunk boundary anywhere still works.
        let mut out = Vec::with_capacity(dest_size);
        let mut written = 0usize;
        while written < dest_size {
            let chunk = (dest_size - written).min(COPY_CHUNK);
            let start = entry
                .data_offset
                .checked_add(written as u64)
                .ok_or_else(|| {
                    Error::field("DXArchive file data", 0, "file body offset overflows u64")
                })?;
            let mut piece = self.body(start, chunk as u64)?.to_vec();
            if let Some(key) = key.as_ref() {
                key_conv(&mut piece, key, entry.size.wrapping_add(written as u64));
            }
            out.extend_from_slice(&piece);
            written += chunk;
        }
        Ok(out)
    }

    /// The per-file key: CRC-32 over the key string, the file's uppercased name
    /// and its ancestors' uppercased names (FORMAT_SPEC 8.4 step 6).
    fn file_key(&self, v8: &V8, entry: &ArchiveEntry) -> Option<[u8; KEY_BYTES]> {
        if v8.no_key {
            return None;
        }
        let mut source = Vec::with_capacity(
            v8.key_string.len() + entry.upper_name.len() + entry.ancestor_names.len(),
        );
        source.extend_from_slice(&v8.key_string);
        source.extend_from_slice(&entry.upper_name);
        source.extend_from_slice(&entry.ancestor_names);
        Some(key_create(&source))
    }

    /// Borrow a body region, refusing to run past the end of the archive.
    fn body(&self, offset: u64, len: u64) -> Result<&[u8]> {
        let len = size_of(len)?;
        let start = size_of(offset)?;
        slice_of(&self.data, start, len, "DXArchive file data")
    }
}
/// Read and decompress the head region (FORMAT_SPEC 8.1 and 8.4 step 2).
fn read_head_region(
    data: &[u8],
    head: &DarcHead,
    key_string: &[u8],
    encrypted: bool,
) -> Result<Vec<u8>> {
    const WHAT: &str = "DXArchive head region";
    let start = size_of(head.file_name_table_start_address)?;
    let expected = head.head_size as usize;

    let mut bytes = if head.flags & FLAG_NO_HEAD_PRESS != 0 {
        // Uncompressed head: exactly HeadSize bytes follow the name table start.
        let mut plain = slice_of(data, start, expected, WHAT)?.to_vec();
        if encrypted {
            key_conv(&mut plain, &key_create(key_string), 0);
        }
        plain
    } else {
        // Compressed head: the Huffman stream runs to the end of the archive,
        // so it is never safe to stop at the header's own HeadSize -- the
        // compressed form is usually shorter, but can also be longer.
        let mut raw = slice_of(data, start, data.len().saturating_sub(start), WHAT)?.to_vec();
        if encrypted {
            key_conv(&mut raw, &key_create(key_string), 0);
        }
        let lz = huffman::decode(&raw, WHAT)?;
        lz::decode(&lz, WHAT)?
    };

    if bytes.len() != expected {
        return Err(Error::field(
            WHAT,
            start,
            format!(
                "head region decoded to {} byte(s) but the header declares {expected}",
                bytes.len()
            ),
        ));
    }
    // The Huffman stage of the head starts at the archive's first byte.
    bytes.shrink_to_fit();
    Ok(bytes)
}

/// The name-table, file-table and directory-table segments of the head region.
struct Tables<'a> {
    head: &'a [u8],
    file_table: usize,
    directory_table: usize,
}

/// One DARC_DIRECTORY record (FORMAT_SPEC 8.4 step 5).
struct Directory {
    directory_address: u64,
    parent_directory_address: u64,
    file_head_num: u64,
    file_head_address: u64,
}

/// One DARC_FILEHEAD record (FORMAT_SPEC 8.4 step 5).
struct FileHead {
    name_address: u64,
    attributes: u64,
    data_address: u64,
    data_size: u64,
    press_data_size: u64,
    huff_press_data_size: u64,
}

/// Both copies of a name-table entry (FORMAT_SPEC 8.4 step 4).
struct Name {
    upper: Vec<u8>,
    original: String,
}

impl<'a> Tables<'a> {
    /// One DARC_DIRECTORY, at `offset` inside the directory table.
    fn directory(&self, offset: u64) -> Result<Directory> {
        const WHAT: &str = "DXArchive directory table";
        let at = self
            .directory_table
            .checked_add(size_of(offset)?)
            .ok_or_else(|| {
                Error::field(
                    WHAT,
                    self.directory_table,
                    "directory offset overflows usize",
                )
            })?;
        let mut reader = Reader::new(slice_of(self.head, at, DIRECTORY_SIZE, WHAT)?);
        Ok(Directory {
            directory_address: reader.u64()?,
            parent_directory_address: reader.u64()?,
            file_head_num: reader.u64()?,
            file_head_address: reader.u64()?,
        })
    }

    /// One DARC_FILEHEAD, at `offset` inside the file table.
    fn file_head(&self, offset: u64) -> Result<FileHead> {
        const WHAT: &str = "DXArchive file table";
        let at = self
            .file_table
            .checked_add(size_of(offset)?)
            .ok_or_else(|| {
                Error::field(WHAT, self.file_table, "file head offset overflows usize")
            })?;
        let mut reader = Reader::new(slice_of(self.head, at, FILE_HEAD_SIZE, WHAT)?);
        let name_address = reader.u64()?;
        let attributes = reader.u64()?;
        reader.skip(24)?; // DARC_FILETIME: create, last access, last write.
        Ok(FileHead {
            name_address,
            attributes,
            data_address: reader.u64()?,
            data_size: reader.u64()?,
            press_data_size: reader.u64()?,
            huff_press_data_size: reader.u64()?,
        })
    }

    /// The upper-case and original-case copies of a name-table entry.
    ///
    /// `address` is relative to the start of the name table. The stored parity
    /// is the sum of the upper-case bytes modulo 65536, which doubles as a cheap
    /// way to detect a mis-decoded head region.
    fn name(&self, address: u64) -> Result<Name> {
        const WHAT: &str = "DXArchive name table";
        let start = size_of(address)?;
        let rest = slice_of(
            self.head,
            start,
            self.head.len().saturating_sub(start),
            WHAT,
        )?;
        let mut reader = Reader::new(rest);
        let pack = reader.u16()?;
        let parity = reader.u16()?;
        let upper_len = usize::from(pack) * 4;
        let upper_block = reader.take(upper_len)?;
        let end = upper_block
            .iter()
            .position(|&byte| byte == 0)
            .unwrap_or(upper_block.len());
        let upper = upper_block[..end].to_vec();

        let sum = upper
            .iter()
            .fold(0u16, |acc, &byte| acc.wrapping_add(u16::from(byte)));
        if sum != parity {
            return Err(Error::field(
                WHAT,
                start,
                format!("name parity {parity:#06X} does not match the summed bytes {sum:#06X}"),
            ));
        }

        // The original-case copy follows the upper-case one, four-byte aligned
        // and NUL-padded (FORMAT_SPEC 8.4 step 4).
        let tail = &rest[reader.pos()..];
        let length = tail.iter().position(|&byte| byte == 0).ok_or_else(|| {
            Error::field(
                WHAT,
                start + reader.pos(),
                "file name is not NUL terminated",
            )
        })?;
        Ok(Name {
            upper,
            original: sjis::decode(&tail[..length]),
        })
    }

    /// Append the upper-case names of every ancestor directory of the directory
    /// at `dir_offset`, nearest first and with the archive root left out.
    ///
    /// This is the tail of a file's key source (FORMAT_SPEC 8.4 step 6): the
    /// reference reader strings the file's own name first and then walks
    /// DirectoryAddress -> ParentDirectoryAddress, stopping before the root.
    fn push_ancestors(&self, dir_offset: u64, out: &mut Vec<u8>) -> Result<()> {
        const WHAT: &str = "DXArchive directory tree";
        let mut current = dir_offset;
        for _ in 0..MAX_DEPTH {
            let directory = self.directory(current)?;
            let own = directory.directory_address;
            if own == NO_COMPRESSION || own == 0 {
                return Ok(());
            }
            let file = self.file_head(own)?;
            out.extend_from_slice(&self.name(file.name_address)?.upper);
            let parent = directory.parent_directory_address;
            if parent == NO_COMPRESSION || parent == 0 {
                return Ok(());
            }
            current = parent;
        }
        Err(Error::field(
            WHAT,
            self.directory_table,
            "directory chain is cyclic",
        ))
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
        const WHAT: &str = "DXArchive directory tree";
        if depth > MAX_DEPTH {
            return Err(Error::field(
                WHAT,
                self.directory_table,
                "directory nesting is too deep",
            ));
        }
        let directory = self.directory(dir_offset)?;
        let mut ancestors = Vec::new();
        self.push_ancestors(dir_offset, &mut ancestors)?;

        for index in 0..directory.file_head_num {
            let slot = index
                .checked_mul(FILE_HEAD_SIZE as u64)
                .and_then(|step| directory.file_head_address.checked_add(step))
                .ok_or_else(|| {
                    Error::field(WHAT, self.file_table, "file head index overflows u64")
                })?;
            let file = self.file_head(slot)?;
            let name = self.name(file.name_address)?;

            if file.attributes & ATTRIBUTE_DIRECTORY != 0 {
                let mut child = String::with_capacity(prefix.len() + name.original.len() + 1);
                child.push_str(prefix);
                child.push_str(&name.original);
                child.push('/');
                self.walk(file.data_address, &child, depth + 1, data_start, out)?;
                continue;
            }

            let data_offset = data_start.checked_add(file.data_address).ok_or_else(|| {
                Error::field(WHAT, self.file_table, "file body offset overflows u64")
            })?;
            let directory_path = prefix.strip_suffix('/').unwrap_or(prefix);
            out.push(ArchiveEntry {
                name: name.original,
                directory: directory_path.to_string(),
                data_offset,
                size: file.data_size,
                press_size: file.press_data_size,
                huff_press_size: file.huff_press_data_size,
                is_compressed: file.press_data_size != NO_COMPRESSION
                    || file.huff_press_data_size != NO_COMPRESSION,
                upper_name: name.upper,
                ancestor_names: ancestors.clone(),
            });
        }
        Ok(())
    }
}

/// Borrow `len` bytes at `start`, reporting a truncated archive as end of input.
fn slice_of<'a>(data: &'a [u8], start: usize, len: usize, what: &'static str) -> Result<&'a [u8]> {
    let end = start
        .checked_add(len)
        .ok_or_else(|| Error::field(what, start, "slice length overflows usize"))?;
    if end > data.len() {
        return Err(Error::eof(start, len, data.len().saturating_sub(start)));
    }
    Ok(&data[start..end])
}

/// Narrow an archive offset or size to `usize`.
fn size_of(value: u64) -> Result<usize> {
    usize::try_from(value).map_err(|_| {
        Error::field(
            "DXArchive file data",
            usize::MAX,
            format!("value {value} does not fit in this platform's usize"),
        )
    })
}

/// Reject a decoded body whose length disagrees with the directory entry.
fn expect_size(out: Vec<u8>, expected: usize, what: &'static str, at: u64) -> Result<Vec<u8>> {
    if out.len() != expected {
        return Err(Error::field(
            what,
            size_of(at).unwrap_or(0),
            format!(
                "decoded {} byte(s) but the directory entry declares {expected}",
                out.len()
            ),
        ));
    }
    Ok(out)
}
