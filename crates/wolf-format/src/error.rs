//! Error type shared by every loader.

use std::fmt;

/// Convenient alias used across the crate.
pub type Result<T> = std::result::Result<T, Error>;

/// A parse failure. Every variant carries the byte offset that produced it,
/// because "which loader ate the file" is the only question that matters when a
/// binary parser breaks.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum Error {
    /// Ran out of bytes.
    Eof {
        /// Offset the failing read started at.
        pos: usize,
        /// Bytes the read wanted.
        want: usize,
        /// Bytes that were actually left.
        have: usize,
    },
    /// A fixed magic value did not match.
    Magic {
        /// Human-readable name of the field.
        what: &'static str,
        /// Offset of the first mismatching byte.
        pos: usize,
        /// Bytes found.
        got: Vec<u8>,
        /// Bytes expected.
        want: Vec<u8>,
    },
    /// A field held a value the format does not allow.
    Field {
        /// Human-readable name of the field.
        what: &'static str,
        /// Offset of the field.
        pos: usize,
        /// What was wrong.
        msg: String,
    },
    /// Parsing finished before the buffer did.
    Trailing {
        /// Offset where parsing stopped.
        pos: usize,
        /// Bytes left over.
        left: usize,
    },
}

impl Error {
    #[must_use]
    pub fn eof(pos: usize, want: usize, have: usize) -> Self {
        Error::Eof { pos, want, have }
    }

    #[must_use]
    pub fn magic(what: &'static str, pos: usize, got: &[u8], want: &[u8]) -> Self {
        Error::Magic {
            what,
            pos,
            got: got.to_vec(),
            want: want.to_vec(),
        }
    }

    #[must_use]
    pub fn field(what: &'static str, pos: usize, msg: impl Into<String>) -> Self {
        Error::Field {
            what,
            pos,
            msg: msg.into(),
        }
    }

    #[must_use]
    pub fn trailing(pos: usize, left: usize) -> Self {
        Error::Trailing { pos, left }
    }

    /// Byte offset the error points at, when the variant knows one.
    #[must_use]
    pub fn position(&self) -> usize {
        match self {
            Error::Eof { pos, .. }
            | Error::Magic { pos, .. }
            | Error::Field { pos, .. }
            | Error::Trailing { pos, .. } => *pos,
        }
    }
}

fn hex(bytes: &[u8]) -> String {
    let mut out = String::with_capacity(bytes.len() * 3);
    for (i, b) in bytes.iter().enumerate() {
        if i > 0 {
            out.push(' ');
        }
        out.push_str(&format!("{b:02X}"));
    }
    out
}

impl fmt::Display for Error {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Error::Eof { pos, want, have } => write!(
                f,
                "unexpected end of input at offset {pos}: wanted {want} byte(s), {have} left"
            ),
            Error::Magic {
                what,
                pos,
                got,
                want,
            } => write!(
                f,
                "bad magic for {what} at offset {pos}: got [{}], want [{}]",
                hex(got),
                hex(want)
            ),
            Error::Field { what, pos, msg } => {
                write!(f, "invalid {what} at offset {pos}: {msg}")
            }
            Error::Trailing { pos, left } => write!(
                f,
                "parse stopped at offset {pos} with {left} byte(s) unconsumed"
            ),
        }
    }
}

impl std::error::Error for Error {}
