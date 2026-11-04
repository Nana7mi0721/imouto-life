//! Mod patch files: byte-exact edits and structured record edits.
//!
//! A mod overlay may ship a patches/ directory next to its mirrored data tree.
//! Each *.patch file declares one edit in a small key = value syntax:
//!
//! ```text
//! # Byte-range patch: replace six bytes of a file in place.
//! file    = SystemFile/WindowBase.png
//! offset  = 0x10
//! expect  = 00 01 02 03 04 05
//! replace = FF FE FD FC FB FA
//!
//! # Record patch: set one cell of a database table.
//! file        = CDataBase.dat
//! type        = 18
//! row         = 97
//! column_name = 座標倍率X
//! number      = 32
//! ```
//!
//! Two guarantees keep a bad patch from silently corrupting a game:
//!
//! * A byte patch validates every expect against the file before anything is
//!   written, so a mismatched file is reported and left untouched.
//! * expect and replace must be the same length; a byte patch never grows or
//!   shrinks the target. (Growing a database string is what record patches are
//!   for: the serializer re-encodes the length word.)
//!
//! The format is documented for players in docs/M7_PATCH.md.

use std::fmt;
use std::fs;
use std::path::{Path, PathBuf};

use wolf_format::database::{CellValue, ColumnRef, Database, PatchError as RecordPatchError};

/// The subdirectory of a mod overlay that holds *.patch files.
pub const PATCH_DIR: &str = "patches";

/// How a record patch names the column it edits.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum ColumnSpec {
    /// Logical column index, in field-table order.
    Index(usize),
    /// Editor field name from the database .project companion.
    Name(String),
}

impl ColumnSpec {
    /// Borrows this spec as a ColumnRef for the database API.
    fn as_ref(&self) -> ColumnRef<'_> {
        match self {
            Self::Index(index) => ColumnRef::Index(*index),
            Self::Name(name) => ColumnRef::Name(name),
        }
    }
}

/// One patch operation.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum PatchOp {
    /// Replace a fixed-length byte range of a target file after checking it.
    Bytes {
        /// Target file, matched by base name or path suffix.
        target: String,
        /// Offset of the range from the start of the file.
        offset: usize,
        /// Bytes the file must currently hold at offset.
        expect: Vec<u8>,
        /// Bytes to write instead; same length as expect.
        replace: Vec<u8>,
    },
    /// Set one cell of a database table.
    Record {
        /// Target database file, matched by base name or path suffix.
        target: String,
        /// Type index.
        ty: usize,
        /// Row index.
        row: usize,
        /// Column selector.
        column: ColumnSpec,
        /// Value to write.
        value: CellValue,
    },
}

/// A loaded, ordered set of patch operations.
#[derive(Debug, Clone, Default)]
pub struct PatchSet {
    ops: Vec<PatchOp>,
}

impl PatchSet {
    /// An empty patch set.
    #[must_use]
    pub fn new() -> Self {
        Self::default()
    }

    /// The operations in load order.
    #[must_use]
    pub fn ops(&self) -> &[PatchOp] {
        &self.ops
    }

    /// True when nothing was loaded.
    #[must_use]
    pub fn is_empty(&self) -> bool {
        self.ops.is_empty()
    }

    /// Number of loaded operations.
    #[must_use]
    pub fn len(&self) -> usize {
        self.ops.len()
    }

    /// Loads every <overlay>/patches/*.patch file, lowest-priority overlay first.
    ///
    /// An overlay without a patches/ directory contributes nothing. Files within
    /// one directory load in name order.
    ///
    /// # Errors
    ///
    /// PatchError when a directory cannot be listed or a file cannot be read or
    /// parsed.
    pub fn load_from_overlays(overlays: &[PathBuf]) -> Result<Self, PatchError> {
        let mut ops = Vec::new();
        for overlay in overlays {
            let dir = overlay.join(PATCH_DIR);
            if !dir.is_dir() {
                continue;
            }
            let mut files = Vec::new();
            let entries = fs::read_dir(&dir).map_err(|source| PatchError::Io {
                path: dir.clone(),
                source,
            })?;
            for entry in entries {
                let entry = entry.map_err(|source| PatchError::Io {
                    path: dir.clone(),
                    source,
                })?;
                let path = entry.path();
                if path.is_file() && is_patch_file(&path) {
                    files.push(path);
                }
            }
            files.sort();
            for path in files {
                ops.extend(parse_file(&path)?);
            }
        }
        Ok(Self { ops })
    }

    /// Applies the byte patches that target any of candidates.
    ///
    /// Every matching patch is validated before a single write, so a mismatch
    /// leaves data exactly as it was. Returns the number of patches applied.
    ///
    /// # Errors
    ///
    /// PatchError::LengthMismatch, PatchError::OutOfRange or PatchError::Mismatch
    /// when a patch does not fit the file.
    pub fn apply_bytes(
        &self,
        data: &mut Vec<u8>,
        candidates: &[&str],
    ) -> Result<usize, PatchError> {
        let mut plan: Vec<(usize, &[u8])> = Vec::new();
        for op in &self.ops {
            let PatchOp::Bytes {
                target,
                offset,
                expect,
                replace,
            } = op
            else {
                continue;
            };
            if !target_matches(target, candidates) {
                continue;
            }
            if expect.len() != replace.len() {
                return Err(PatchError::LengthMismatch {
                    target: target.clone(),
                    expect: expect.len(),
                    replace: replace.len(),
                });
            }
            let end = offset
                .checked_add(expect.len())
                .ok_or_else(|| PatchError::OutOfRange {
                    target: target.clone(),
                    offset: *offset,
                    length: expect.len(),
                    file_len: data.len(),
                })?;
            if end > data.len() {
                return Err(PatchError::OutOfRange {
                    target: target.clone(),
                    offset: *offset,
                    length: expect.len(),
                    file_len: data.len(),
                });
            }
            if data[*offset..end] != expect[..] {
                return Err(PatchError::Mismatch {
                    target: target.clone(),
                    offset: *offset,
                    expected: expect.clone(),
                    found: data[*offset..end].to_vec(),
                });
            }
            plan.push((*offset, replace.as_slice()));
        }
        for (offset, replace) in &plan {
            let end = offset + replace.len();
            data[*offset..end].copy_from_slice(replace);
        }
        Ok(plan.len())
    }

    /// Applies the record patches that target any of candidates to database.
    ///
    /// Returns the number of cells written. Stops at the first record that does
    /// not fit the database.
    ///
    /// # Errors
    ///
    /// PatchError::Record when a type/row/column does not exist or has the wrong
    /// kind for the value.
    pub fn apply_records(
        &self,
        database: &mut Database,
        candidates: &[&str],
    ) -> Result<usize, PatchError> {
        let mut applied = 0;
        for op in &self.ops {
            let PatchOp::Record {
                target,
                ty,
                row,
                column,
                value,
            } = op
            else {
                continue;
            };
            if !target_matches(target, candidates) {
                continue;
            }
            database
                .set_cell(*ty, *row, column.as_ref(), value.clone())
                .map_err(PatchError::Record)?;
            applied += 1;
        }
        Ok(applied)
    }
}

/// Why a patch could not be loaded or applied.
#[derive(Debug)]
pub enum PatchError {
    /// A patch directory or file could not be read.
    Io {
        /// Offending path.
        path: PathBuf,
        /// Underlying error.
        source: std::io::Error,
    },
    /// A patch file's syntax was invalid.
    Syntax {
        /// Offending file.
        path: PathBuf,
        /// 1-based line number.
        line: usize,
        /// What was wrong.
        message: String,
    },
    /// The file did not hold the bytes the patch expected.
    Mismatch {
        /// Target file.
        target: String,
        /// Offset checked.
        offset: usize,
        /// Bytes the patch expected.
        expected: Vec<u8>,
        /// Bytes actually present.
        found: Vec<u8>,
    },
    /// expect and replace were not the same length.
    LengthMismatch {
        /// Target file.
        target: String,
        /// Length of expect.
        expect: usize,
        /// Length of replace.
        replace: usize,
    },
    /// The byte range did not fit inside the file.
    OutOfRange {
        /// Target file.
        target: String,
        /// Offset requested.
        offset: usize,
        /// Length requested.
        length: usize,
        /// Size of the file actually read.
        file_len: usize,
    },
    /// A record patch did not fit the database.
    Record(RecordPatchError),
}

impl fmt::Display for PatchError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Io { path, source } => {
                write!(f, "cannot read patch {}: {source}", path.display())
            }
            Self::Syntax {
                path,
                line,
                message,
            } => write!(f, "{}:{line}: {message}", path.display()),
            Self::Mismatch {
                target,
                offset,
                expected,
                found,
            } => write!(
                f,
                "{target}: bytes at {offset:#x} are {}, expected {}",
                hex_bytes(found),
                hex_bytes(expected)
            ),
            Self::LengthMismatch {
                target,
                expect,
                replace,
            } => write!(
                f,
                "{target}: expect has {expect} bytes but replace has {replace}"
            ),
            Self::OutOfRange {
                target,
                offset,
                length,
                file_len,
            } => write!(
                f,
                "{target}: range {offset:#x}+{length:#x} exceeds file length {file_len:#x}"
            ),
            Self::Record(error) => write!(f, "record patch: {error}"),
        }
    }
}

impl std::error::Error for PatchError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self {
            Self::Io { source, .. } => Some(source),
            Self::Record(error) => Some(error),
            _ => None,
        }
    }
}

fn is_patch_file(path: &Path) -> bool {
    path.extension()
        .and_then(|extension| extension.to_str())
        .is_some_and(|extension| extension.eq_ignore_ascii_case("patch"))
}

fn parse_file(path: &Path) -> Result<Vec<PatchOp>, PatchError> {
    let text = fs::read_to_string(path).map_err(|source| PatchError::Io {
        path: path.to_path_buf(),
        source,
    })?;
    let mut entries: Vec<(String, String, usize)> = Vec::new();
    for (index, raw) in text.lines().enumerate() {
        let line = raw.trim();
        if line.is_empty() || line.starts_with('#') || line.starts_with("//") {
            continue;
        }
        let Some((key, value)) = line.split_once('=') else {
            return Err(PatchError::Syntax {
                path: path.to_path_buf(),
                line: index + 1,
                message: format!("expected 'key = value', found '{line}'"),
            });
        };
        entries.push((
            key.trim().to_ascii_lowercase(),
            value.trim().to_string(),
            index + 1,
        ));
    }
    let lookup = |name: &str| {
        entries
            .iter()
            .find(|(key, _, _)| key == name)
            .map(|(_, value, line)| (value.clone(), *line))
    };
    let target = lookup("file")
        .map(|(value, _)| value)
        .ok_or_else(|| syntax(path, 1, "missing required 'file' key"))?;
    if target.is_empty() {
        return Err(syntax(path, 1, "'file' must not be empty"));
    }

    let is_bytes =
        lookup("offset").is_some() || lookup("expect").is_some() || lookup("replace").is_some();
    if is_bytes {
        let (offset_text, offset_line) = lookup("offset")
            .ok_or_else(|| syntax(path, 1, "byte patch missing required 'offset'"))?;
        let offset =
            parse_usize(&offset_text).map_err(|message| syntax(path, offset_line, &message))?;
        let (expect_text, expect_line) =
            lookup("expect").ok_or_else(|| syntax(path, 1, "byte patch missing 'expect'"))?;
        let expect =
            parse_hex(&expect_text).map_err(|message| syntax(path, expect_line, &message))?;
        let (replace_text, replace_line) =
            lookup("replace").ok_or_else(|| syntax(path, 1, "byte patch missing 'replace'"))?;
        let replace =
            parse_hex(&replace_text).map_err(|message| syntax(path, replace_line, &message))?;
        if expect.is_empty() {
            return Err(syntax(path, expect_line, "'expect' must not be empty"));
        }
        return Ok(vec![PatchOp::Bytes {
            target,
            offset,
            expect,
            replace,
        }]);
    }

    // A record patch: keys type/row and one column form plus one value form.
    let (type_text, type_line) =
        lookup("type").ok_or_else(|| syntax(path, 1, "record patch missing 'type'"))?;
    let ty = parse_usize(&type_text).map_err(|message| syntax(path, type_line, &message))?;
    let (row_text, row_line) =
        lookup("row").ok_or_else(|| syntax(path, 1, "record patch missing 'row'"))?;
    let row = parse_usize(&row_text).map_err(|message| syntax(path, row_line, &message))?;
    let column = match (lookup("column"), lookup("column_name")) {
        (Some((value, line)), None) => {
            ColumnSpec::Index(parse_usize(&value).map_err(|m| syntax(path, line, &m))?)
        }
        (None, Some((value, _line))) => ColumnSpec::Name(value),
        (Some(_), Some(_)) => {
            return Err(syntax(
                path,
                1,
                "use either 'column' or 'column_name', not both",
            ))
        }
        (None, None) => {
            return Err(syntax(
                path,
                1,
                "record patch needs 'column' or 'column_name'",
            ))
        }
    };
    let value = match (lookup("number"), lookup("text")) {
        (Some((value, line)), None) => {
            CellValue::Number(parse_i32(&value).map_err(|m| syntax(path, line, &m))?)
        }
        (None, Some((value, _line))) => CellValue::Text(value),
        (Some(_), Some(_)) => {
            return Err(syntax(path, 1, "use either 'number' or 'text', not both"))
        }
        (None, None) => return Err(syntax(path, 1, "record patch needs 'number' or 'text'")),
    };
    Ok(vec![PatchOp::Record {
        target,
        ty,
        row,
        column,
        value,
    }])
}

fn syntax(path: &Path, line: usize, message: &str) -> PatchError {
    PatchError::Syntax {
        path: path.to_path_buf(),
        line,
        message: message.to_owned(),
    }
}

fn parse_usize(text: &str) -> Result<usize, String> {
    let trimmed = text.trim();
    let parsed = if let Some(hex) = trimmed
        .strip_prefix("0x")
        .or_else(|| trimmed.strip_prefix("0X"))
    {
        usize::from_str_radix(hex, 16)
    } else {
        trimmed.parse::<usize>()
    };
    parsed.map_err(|_| format!("'{text}' is not a valid non-negative integer"))
}

fn parse_i32(text: &str) -> Result<i32, String> {
    let trimmed = text.trim();
    let parsed = if let Some(hex) = trimmed
        .strip_prefix("0x")
        .or_else(|| trimmed.strip_prefix("0X"))
    {
        i32::from_str_radix(hex, 16)
    } else {
        trimmed.parse::<i32>()
    };
    parsed.map_err(|_| format!("'{text}' is not a valid 32-bit integer"))
}

/// Parses a whitespace- or comma-separated hex byte list ("00 01 ff").
fn parse_hex(text: &str) -> Result<Vec<u8>, String> {
    let mut bytes = Vec::new();
    for token in text
        .split(|character: char| character.is_whitespace() || character == ',')
        .filter(|token| !token.is_empty())
    {
        let token = token
            .strip_prefix("0x")
            .or_else(|| token.strip_prefix("0X"))
            .unwrap_or(token);
        if token.is_empty() || token.len() > 2 {
            return Err(format!("'{token}' is not a one-byte hex value"));
        }
        let value = u8::from_str_radix(token, 16)
            .map_err(|_| format!("'{token}' is not a one-byte hex value"))?;
        bytes.push(value);
    }
    Ok(bytes)
}

/// True when target names any of candidates by full path or base name.
fn target_matches(target: &str, candidates: &[&str]) -> bool {
    let target = normalize_target(target);
    let target_base = base_name(&target);
    candidates.iter().any(|candidate| {
        let candidate = normalize_target(candidate);
        candidate == target || base_name(&candidate) == target_base
    })
}

fn normalize_target(value: &str) -> String {
    value
        .trim()
        .replace('\\', "/")
        .trim_start_matches("./")
        .to_ascii_lowercase()
}

fn base_name(value: &str) -> &str {
    value.rsplit('/').next().unwrap_or(value)
}

fn hex_bytes(bytes: &[u8]) -> String {
    if bytes.is_empty() {
        return "(empty)".to_owned();
    }
    let mut text = String::with_capacity(bytes.len() * 3);
    for (index, byte) in bytes.iter().enumerate() {
        if index > 0 {
            text.push(' ');
        }
        text.push_str(&format!("{byte:02X}"));
    }
    text
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::sync::atomic::{AtomicU64, Ordering};
    use wolf_format::database::{FieldKind, Row};

    fn byte_set(ops: Vec<PatchOp>) -> PatchSet {
        PatchSet { ops }
    }

    fn scratch_dir(tag: &str) -> PathBuf {
        static COUNTER: AtomicU64 = AtomicU64::new(0);
        let unique = COUNTER.fetch_add(1, Ordering::Relaxed);
        let mut dir = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        dir.pop(); // crates/
        dir.pop(); // workspace root
        dir.push("target");
        dir.push("test-scratch");
        dir.push(format!("patch-{tag}-{}-{unique}", std::process::id()));
        let _ = std::fs::remove_dir_all(&dir);
        std::fs::create_dir_all(&dir).expect("create scratch dir");
        dir
    }

    #[test]
    fn byte_patch_replaces_a_range() {
        let set = byte_set(vec![PatchOp::Bytes {
            target: "foo.bin".to_owned(),
            offset: 1,
            expect: vec![1, 2],
            replace: vec![9, 9],
        }]);
        let mut data = vec![0u8, 1, 2, 3, 4, 5];
        assert_eq!(
            set.apply_bytes(&mut data, &["BasicData/foo.bin"]).unwrap(),
            1
        );
        assert_eq!(data, vec![0, 9, 9, 3, 4, 5]);
    }

    #[test]
    fn mismatched_expect_leaves_data_unchanged() {
        let set = byte_set(vec![PatchOp::Bytes {
            target: "foo.bin".to_owned(),
            offset: 1,
            expect: vec![7, 7],
            replace: vec![9, 9],
        }]);
        let mut data = vec![0u8, 1, 2, 3];
        let error = set.apply_bytes(&mut data, &["foo.bin"]).unwrap_err();
        assert!(matches!(error, PatchError::Mismatch { offset: 1, .. }));
        assert_eq!(data, vec![0, 1, 2, 3], "a mismatch must not write anything");
    }

    #[test]
    fn length_mismatch_is_rejected() {
        let set = byte_set(vec![PatchOp::Bytes {
            target: "foo.bin".to_owned(),
            offset: 0,
            expect: vec![1, 2],
            replace: vec![3],
        }]);
        let mut data = vec![1u8, 2];
        let error = set.apply_bytes(&mut data, &["foo.bin"]).unwrap_err();
        assert!(matches!(error, PatchError::LengthMismatch { .. }));
        assert_eq!(data, vec![1, 2]);
    }

    #[test]
    fn out_of_range_is_rejected() {
        let set = byte_set(vec![PatchOp::Bytes {
            target: "foo.bin".to_owned(),
            offset: 3,
            expect: vec![1, 2, 3],
            replace: vec![1, 2, 3],
        }]);
        let mut data = vec![1u8, 2, 3];
        let error = set.apply_bytes(&mut data, &["foo.bin"]).unwrap_err();
        assert!(matches!(error, PatchError::OutOfRange { .. }));
    }

    #[test]
    fn byte_patches_only_touch_matching_targets() {
        let set = byte_set(vec![PatchOp::Bytes {
            target: "other.bin".to_owned(),
            offset: 0,
            expect: vec![0],
            replace: vec![9],
        }]);
        let mut data = vec![0u8, 0];
        assert_eq!(set.apply_bytes(&mut data, &["foo.bin"]).unwrap(), 0);
        assert_eq!(data, vec![0, 0]);
    }

    #[test]
    fn record_patch_sets_a_cell() {
        let database = || {
            Database::synthetic(
                0xC1,
                vec![wolf_format::database::DatabaseType::synthetic(
                    0,
                    vec![FieldKind::Num(0), FieldKind::Str(0)],
                    vec![Row {
                        numbers: vec![1],
                        strings: vec!["a".to_owned()],
                    }],
                )],
                0xC1,
            )
        };
        let set = byte_set(vec![
            PatchOp::Record {
                target: "CDataBase.dat".to_owned(),
                ty: 0,
                row: 0,
                column: ColumnSpec::Index(0),
                value: CellValue::Number(42),
            },
            PatchOp::Record {
                target: "CDataBase.dat".to_owned(),
                ty: 0,
                row: 0,
                column: ColumnSpec::Index(1),
                value: CellValue::Text("longer text".to_owned()),
            },
        ]);
        let mut db = database();
        assert_eq!(
            set.apply_records(&mut db, &["BasicData/CDataBase.dat"])
                .unwrap(),
            2
        );
        let bytes = db.to_bytes();
        let parsed = Database::parse(&bytes).unwrap();
        assert_eq!(parsed.types[0].rows[0].numbers, vec![42]);
        assert_eq!(
            parsed.types[0].rows[0].strings,
            vec!["longer text".to_owned()]
        );
    }

    #[test]
    fn record_patch_reports_a_bad_cell() {
        let mut db = Database::synthetic(0xC1, Vec::new(), 0xC1);
        let set = byte_set(vec![PatchOp::Record {
            target: "DataBase.dat".to_owned(),
            ty: 0,
            row: 0,
            column: ColumnSpec::Index(0),
            value: CellValue::Number(1),
        }]);
        let error = set.apply_records(&mut db, &["DataBase.dat"]).unwrap_err();
        assert!(matches!(error, PatchError::Record(_)));
    }

    #[test]
    fn loads_patch_files_from_overlays() {
        let dir = scratch_dir("load");
        let patch_dir = dir.join(PATCH_DIR);
        std::fs::create_dir_all(&patch_dir).unwrap();
        std::fs::write(
            patch_dir.join("a.patch"),
            "file = foo.bin\n offset = 0x10\n expect = 00 01\n replace = FF FE\n",
        )
        .unwrap();
        std::fs::write(
            patch_dir.join("b.patch"),
            "file = DataBase.dat\ntype = 2\nrow = 3\ncolumn = 4\nnumber = 7\n",
        )
        .unwrap();
        let set = PatchSet::load_from_overlays(&[dir.clone()]).unwrap();
        assert_eq!(set.len(), 2);
        assert!(matches!(
            &set.ops()[0],
            PatchOp::Bytes {
                offset: 0x10,
                expect,
                replace,
                ..
            } if expect == &vec![0x00, 0x01] && replace == &vec![0xFF, 0xFE]
        ));
        assert!(matches!(
            &set.ops()[1],
            PatchOp::Record {
                ty: 2,
                row: 3,
                column: ColumnSpec::Index(4),
                value: CellValue::Number(7),
                ..
            }
        ));
        std::fs::remove_dir_all(&dir).ok();
    }

    #[test]
    fn target_matching_accepts_a_base_name() {
        assert!(target_matches("DataBase.dat", &["BasicData/DataBase.dat"]));
        assert!(target_matches("BasicData/DataBase.dat", &["DataBase.dat"]));
        assert!(!target_matches("CDataBase.dat", &["DataBase.dat"]));
    }

    #[test]
    fn parse_hex_accepts_prefix_and_commas() {
        assert_eq!(parse_hex("0x00, 0x01 FF").unwrap(), vec![0, 1, 255]);
        assert!(parse_hex("00 001").is_err());
    }
}
