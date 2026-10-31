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

    /// Read a `t_str` as a `String`.
    ///
    /// Three encodings appear in WOLF data: the 2.10 generation (sibling game)
    /// stores UTF-8; the 2.00 generation (this game) stores CP932; and this
    /// game's Chinese fan translation overwrote many display strings with GBK
    /// while leaving system/template text in CP932. Decode by trying UTF-8
    /// strictly first, then scoring CP932 against GBK.
    pub fn t_str(&mut self) -> Result<String> {
        let raw = self.t_str_bytes()?;
        Ok(decode_wolf_str(raw))
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

/// Decode a WOLF string payload, which may be UTF-8, CP932 (Shift-JIS) or GBK.
///
/// All three candidates are scored rather than trusting UTF-8 blindly: a handful
/// of GBK byte pairs (for example the fan translation's C7 BF D7 B3 = "强壮")
/// are also *valid* UTF-8, spelling unrelated code points ("ǿ׳"). UTF-8 gets a
/// bonus per multibyte sequence so genuine UTF-8 (Chinese, Japanese, emoji, an
/// older engine's fallback text) still wins, while a GBK reading that scores much
/// higher takes the collision back. CP932 and GBK remain scored against each
/// other as before: GBK display text decodes to plausible hanzi under GBK but to
/// halfwidth katakana under CP932, while untranslated Japanese does the reverse.
#[must_use]
pub fn decode_wolf_str(raw: &[u8]) -> String {
    let (best, best_total) = cp932_gbk_reading(raw);
    if let Ok(text) = std::str::from_utf8(raw) {
        let utf8_total = score_utf8_chars(text) + score_utf8_bytes(raw);
        if utf8_total + 2 >= best_total {
            return text.to_owned();
        }
    }
    best
}

/// Character plausibility for a *valid* UTF-8 payload. Unlike [score_chars], a
/// real Greek/Cyrillic/accented letter is not evidence of a misread GBK pair, so
/// it earns a small positive score instead of a penalty. CJK and kana still
/// weigh more, and Hebrew is penalised because the retail collision `C7 BF D7 B3`
/// spells U+01FF U+05F3 under UTF-8.
fn score_utf8_chars(text: &str) -> i32 {
    let mut score = 0;
    for ch in text.chars() {
        let c = u32::from(ch);
        if ch == '\u{FFFD}' {
            score -= 30;
        } else if (0x3040..=0x30FF).contains(&c) {
            score += 3;
        } else if (0x4E00..=0x9FFF).contains(&c) {
            score += 2;
        } else if (0x0590..=0x05FF).contains(&c) {
            score -= 10;
        } else if c >= 0x80 {
            score += 1;
        }
    }
    score
}

/// Pick the best CP932-or-GBK reading of a byte payload, plus its score.
///
/// This is the pre-existing heuristic, unchanged: a clean reading beats a
/// replacement-bearing one, and otherwise the two are scored with a two-point
/// margin that favours CP932 on near-ties (the common case for Japanese UI
/// labels). UTF-8 is handled by the caller.
fn cp932_gbk_reading(raw: &[u8]) -> (String, i32) {
    let cp = crate::dxarchive::decode_cp932(raw);
    let (gb, gb_bad) = crate::gbk::decode(raw);
    let cp_bad = cp.contains('\u{FFFD}');
    let cp_total = score_cp932_bytes(raw) + score_chars(&cp);
    let gb_total = score_gbk_bytes(raw) + score_chars(&gb);
    if gb_bad && !cp_bad {
        return (cp, cp_total);
    }
    if cp_bad && !gb_bad {
        return (gb, gb_total);
    }
    if gb_total > cp_total + 2 {
        (gb, gb_total)
    } else {
        (cp, cp_total)
    }
}

/// Score valid UTF-8 multibyte sequences: +3 each. Only called after
/// std::str::from_utf8 accepted the whole payload, so lengths are trustworthy.
fn score_utf8_bytes(raw: &[u8]) -> i32 {
    let mut score = 0;
    let mut i = 0;
    while i < raw.len() {
        let b = raw[i];
        if b < 0x80 {
            i += 1;
            continue;
        }
        let len = match b {
            0xC2..=0xDF => 2,
            0xE0..=0xEF => 3,
            0xF0..=0xF4 => 4,
            _ => 1,
        };
        if len > 1 && i + len <= raw.len() {
            score += 3;
            i += len;
        } else {
            i += 1;
        }
    }
    score
}

/// Score how much a byte payload looks like GB2312/GBK hanzi: lead 0xB0..=0xF7
/// with trail 0xA1..=0xFE is the common-hanzi band.
fn score_gbk_bytes(raw: &[u8]) -> i32 {
    let mut score = 0;
    let mut i = 0;
    while i + 1 < raw.len() {
        let (b, t) = (raw[i], raw[i + 1]);
        if b < 0x80 {
            i += 1;
            continue;
        }
        if (0xB0..=0xF7).contains(&b) && (0xA1..=0xFE).contains(&t) {
            score += 3;
        } else if (0x81..=0xAF).contains(&b) {
            score += 1;
        }
        i += 2;
    }
    score
}

/// Score how much a byte payload looks like CP932: kanji/kana two-byte pairs
/// use lead 0x81..=0x9F or 0xE0..=0xEA; bytes 0xA1..=0xDF read as single-byte
/// halfwidth katakana, which is what GBK hanzi turn into under CP932.
fn score_cp932_bytes(raw: &[u8]) -> i32 {
    let mut score = 0;
    let mut i = 0;
    while i + 1 < raw.len() {
        let (b, t) = (raw[i], raw[i + 1]);
        if b < 0x80 {
            i += 1;
            continue;
        }
        if ((0x81..=0x9F).contains(&b) || (0xE0..=0xEA).contains(&b))
            && ((0x40..=0x7E).contains(&t) || (0x80..=0xFC).contains(&t))
        {
            score += 3;
        } else if (0xA1..=0xDF).contains(&b) {
            score -= 2;
        } else {
            score -= 1;
        }
        i += 2;
    }
    score
}

/// Character-level plausibility: CJK ideographs and fullwidth kana are real
/// text; Greek/Cyrillic letters are the signature of GBK bytes read as CP932.
fn score_chars(text: &str) -> i32 {
    let mut score = 0;
    for ch in text.chars() {
        let c = u32::from(ch);
        if ch == '\u{FFFD}' {
            score -= 30;
        } else if (0x3040..=0x30FF).contains(&c) {
            score += 3;
        } else if (0x4E00..=0x9FFF).contains(&c) {
            score += 2;
        } else if (0x0370..=0x04FF).contains(&c) {
            score -= 4;
        }
    }
    score
}
