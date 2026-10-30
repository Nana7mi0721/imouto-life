//! Little-endian cursor with WOLF's string primitives.
//!
//! WOLF is an x86/DxLib program, so every integer is little-endian and nothing
//! is padded. `t_str` is a `u32` byte length (which **includes** the trailing
//! NUL) followed by the payload.

use crate::error::{Error, Result};

/// A cursor over a borrowed byte slice.
#[derive(Debug, Clone)]
pub struct Reader<'a> {
    buf: &'a [u8],
    pos: usize,
}

impl<'a> Reader<'a> {
    /// Wrap a buffer, starting at offset 0.
    #[must_use]
    pub const fn new(buf: &'a [u8]) -> Self {
        Self { buf, pos: 0 }
    }

    /// Current offset.
    #[must_use]
    pub const fn pos(&self) -> usize {
        self.pos
    }

    /// Move to an absolute offset. Subsequent reads fail cleanly if it is past
    /// the end, so this is safe to expose.
    pub fn set_pos(&mut self, pos: usize) {
        self.pos = pos;
    }

    /// Total length of the underlying buffer.
    #[must_use]
    pub const fn is_empty(&self) -> bool {
        self.buf.is_empty()
    }

    pub const fn len(&self) -> usize {
        self.buf.len()
    }

    /// Bytes left after the cursor.
    #[must_use]
    pub const fn remaining(&self) -> usize {
        self.buf.len() - self.pos
    }

    /// Whether the cursor sits exactly at the end.
    #[must_use]
    pub const fn at_end(&self) -> bool {
        self.pos == self.buf.len()
    }

    /// The whole underlying buffer.
    #[must_use]
    pub const fn buffer(&self) -> &'a [u8] {
        self.buf
    }

    /// Borrow `n` bytes and advance.
    pub fn take(&mut self, n: usize) -> Result<&'a [u8]> {
        if self.remaining() < n {
            return Err(Error::eof(self.pos, n, self.remaining()));
        }
        let out = &self.buf[self.pos..self.pos + n];
        self.pos += n;
        Ok(out)
    }

    /// Borrow the next `n` bytes without advancing.
    pub fn peek(&self, n: usize) -> Result<&'a [u8]> {
        if self.remaining() < n {
            return Err(Error::eof(self.pos, n, self.remaining()));
        }
        Ok(&self.buf[self.pos..self.pos + n])
    }

    /// Advance without looking at the bytes.
    pub fn skip(&mut self, n: usize) -> Result<()> {
        self.take(n).map(|_| ())
    }

    /// Read one byte without advancing.
    pub fn peek_u8(&self) -> Result<u8> {
        Ok(self.peek(1)?[0])
    }

    /// Read one unsigned byte.
    pub fn u8(&mut self) -> Result<u8> {
        Ok(self.take(1)?[0])
    }

    /// Read a little-endian `u16`.
    pub fn u16(&mut self) -> Result<u16> {
        let b = self.take(2)?;
        Ok(u16::from_le_bytes([b[0], b[1]]))
    }

    /// Read a little-endian `u32`.
    pub fn u32(&mut self) -> Result<u32> {
        let b = self.take(4)?;
        Ok(u32::from_le_bytes([b[0], b[1], b[2], b[3]]))
    }

    /// Read a little-endian `i32`.
    pub fn i32(&mut self) -> Result<i32> {
        let b = self.take(4)?;
        Ok(i32::from_le_bytes([b[0], b[1], b[2], b[3]]))
    }

    /// Read a little-endian `u64`.
    pub fn u64(&mut self) -> Result<u64> {
        let b = self.take(8)?;
        Ok(u64::from_le_bytes([
            b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7],
        ]))
    }

    /// Read `n` little-endian `u32`s.
    pub fn u32_array(&mut self, n: usize) -> Result<Vec<u32>> {
        // Guard the allocation against a corrupt length field.
        if n > self.remaining() / 4 {
            return Err(Error::eof(self.pos, n * 4, self.remaining()));
        }
        let mut out = Vec::with_capacity(n);
        for _ in 0..n {
            out.push(self.u32()?);
        }
        Ok(out)
    }

    /// Read `n` little-endian `i32`s.
    pub fn i32_array(&mut self, n: usize) -> Result<Vec<i32>> {
        if n > self.remaining() / 4 {
            return Err(Error::eof(self.pos, n * 4, self.remaining()));
        }
        let mut out = Vec::with_capacity(n);
        for _ in 0..n {
            out.push(self.i32()?);
        }
        Ok(out)
    }

    /// Read a length-prefixed `u32` array (WOLF's `t_u4_array`).
    pub fn t_u32_array(&mut self) -> Result<Vec<u32>> {
        let n = self.u32()? as usize;
        self.u32_array(n)
    }

    /// Read a length-prefixed `i32` array (WOLF's `t_s4_array`).
    ///
    /// The count is signed in the file format; a negative count is treated as
    /// empty rather than as an error, matching WolfTL's tolerant behaviour.
    pub fn t_i32_array(&mut self) -> Result<Vec<i32>> {
        let n = self.i32()?;
        if n <= 0 {
            return Ok(Vec::new());
        }
        self.i32_array(n as usize)
    }

    /// Read a `t_str`: raw payload bytes with the NUL terminator removed.
    ///
    /// A length of 0 is a valid empty string (the editor also writes length 1
    /// containing a single NUL for empty slots; both collapse to `&`).
    pub fn t_str_bytes(&mut self) -> Result<&'a [u8]> {
        let start = self.pos;
        let n = self.u32()? as usize;
        if n > self.remaining() {
            return Err(Error::field(
                "t_str length",
                start,
                format!("declared {n} byte(s) but only {} remain", self.remaining()),
            ));
        }
        let raw = self.take(n)?;
        // WOLF stores a NUL-terminated string; truncate at the first NUL.
        let end = raw.iter().position(|&b| b == 0).unwrap_or(raw.len());
        Ok(&raw[..end])
    }

    /// Read a `t_str` as a `String`, replacing invalid UTF-8.
    ///
    /// Lossy on purpose: a few strings in this game's data are genuinely
    /// corrupt on disk (see `docs/FORMAT_SPEC.md` §1.4). Round-tripping such a
    /// string is never required, so a lossy decode is the right trade.
    pub fn t_str(&mut self) -> Result<String> {
        let raw = self.t_str_bytes()?;
        Ok(String::from_utf8_lossy(raw).into_owned())
    }

    /// Read a `t_str_array`.
    pub fn t_str_array(&mut self) -> Result<Vec<String>> {
        let n = self.u32()? as usize;
        if n > self.remaining() / 4 {
            return Err(Error::eof(self.pos, n * 4, self.remaining()));
        }
        let mut out = Vec::with_capacity(n);
        for _ in 0..n {
            out.push(self.t_str()?);
        }
        Ok(out)
    }

    /// Read exactly the fixed `want` bytes or fail with a magic error.
    pub fn expect(&mut self, want: &[u8], what: &'static str) -> Result<()> {
        let pos = self.pos;
        let got = self.take(want.len())?;
        if got != want {
            return Err(Error::magic(what, pos, got, want));
        }
        Ok(())
    }

    /// Read one byte and require it to equal `want`.
    pub fn expect_u8(&mut self, want: u8, what: &'static str) -> Result<()> {
        let pos = self.pos;
        let got = self.u8()?;
        if got != want {
            return Err(Error::magic(what, pos, &[got], &[want]));
        }
        Ok(())
    }

    /// Fail if the cursor is not exactly at the end of the buffer.
    pub fn expect_end(&mut self) -> Result<()> {
        if self.at_end() {
            Ok(())
        } else {
            Err(Error::trailing(self.pos, self.remaining()))
        }
    }
}
