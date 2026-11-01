//! Optional content translation layer (M5-D).
//!
//! The port keeps the shipped Chinese script as the source of truth. This module adds a
//! side-car catalog that maps an exact runtime string to a replacement, applied at the two
//! places where game text reaches the screen: opcode 101 messages and opcode 102 choices.
//! It deliberately does not touch the picture layer, so a translation can only reword
//! text the script already draws.
//!
//! The catalog is a UTF-8 TSV file, one entry per line: an original string, a literal
//! TAB, then its replacement. Lines starting with # are comments.
//!
//! Blank lines and lines whose first non-space character is '#' are ignored. The first
//! column is matched exactly against the runtime string; the second is used verbatim,
//! except for the escapes \n, \t and \\. Duplicate originals keep the last translation.
//! No external dependency is involved.

use std::collections::HashMap;
use std::fmt;
use std::fs;
use std::io;
use std::path::{Path, PathBuf};

/// A failed translation catalog load or parse.
#[derive(Debug)]
pub enum TranslateError {
    /// The file could not be read.
    Io {
        /// Path that failed.
        path: PathBuf,
        /// Underlying error.
        source: io::Error,
    },
    /// A non-comment line had no tab or an empty source column.
    Syntax {
        /// 1-based physical line number.
        line: usize,
        /// Why the line was rejected.
        reason: &'static str,
    },
}

impl fmt::Display for TranslateError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Io { path, source } => write!(f, "cannot read {}: {source}", path.display()),
            Self::Syntax { line, reason } => {
                write!(f, "translation catalog line {line}: {reason}")
            }
        }
    }
}

impl std::error::Error for TranslateError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self {
            Self::Io { source, .. } => Some(source),
            Self::Syntax { .. } => None,
        }
    }
}

/// Exact-string translation catalog.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct Translator {
    entries: HashMap<String, String>,
}

impl Translator {
    /// Parses a catalog from already-read UTF-8 text.
    ///
    /// # Errors
    ///
    /// Returns TranslateError::Syntax for a line that is neither blank/comment nor a
    /// source-TAB-translation pair.
    pub fn parse(text: &str) -> Result<Self, TranslateError> {
        let mut translator = Self::default();
        for (index, raw) in text.lines().enumerate() {
            let line = raw.strip_suffix('\r').unwrap_or(raw);
            let trimmed = line.trim_start();
            if trimmed.is_empty() || trimmed.starts_with('#') {
                continue;
            }
            let Some((original, translated)) = line.split_once('\t') else {
                return Err(TranslateError::Syntax {
                    line: index + 1,
                    reason: "expected original<TAB>translation",
                });
            };
            if original.is_empty() {
                return Err(TranslateError::Syntax {
                    line: index + 1,
                    reason: "the original string is empty",
                });
            }
            translator
                .entries
                .insert(original.to_owned(), unescape(translated));
        }
        Ok(translator)
    }

    /// Reads and parses a UTF-8 catalog file.
    ///
    /// # Errors
    ///
    /// Returns TranslateError::Io when the file cannot be read and
    /// TranslateError::Syntax for malformed lines.
    pub fn load(path: impl AsRef<Path>) -> Result<Self, TranslateError> {
        let path = path.as_ref();
        let text = fs::read_to_string(path).map_err(|source| TranslateError::Io {
            path: path.to_path_buf(),
            source,
        })?;
        Self::parse(&text)
    }

    /// Returns the replacement for an exact runtime string, or None to keep it.
    #[must_use]
    pub fn translate<'a>(&'a self, text: &'a str) -> Option<&'a str> {
        self.entries.get(text).map(String::as_str)
    }

    /// Number of loaded entries.
    #[must_use]
    pub fn len(&self) -> usize {
        self.entries.len()
    }

    /// True when the catalog is empty (the default, meaning "show the script verbatim").
    #[must_use]
    pub fn is_empty(&self) -> bool {
        self.entries.is_empty()
    }
}

/// Expands the three escapes a TSV cell cannot express literally.
fn unescape(text: &str) -> String {
    let mut out = String::with_capacity(text.len());
    let mut chars = text.chars();
    while let Some(ch) = chars.next() {
        if ch != '\\' {
            out.push(ch);
            continue;
        }
        match chars.next() {
            Some('n') => out.push('\n'),
            Some('t') => out.push('\t'),
            Some('\\') => out.push('\\'),
            Some(other) => {
                out.push('\\');
                out.push(other);
            }
            None => out.push('\\'),
        }
    }
    out
}

#[cfg(test)]
mod tests {
    use super::Translator;

    #[test]
    fn parses_comments_and_escapes() {
        let catalog = "# demo\n\noriginal\tfirst\\nsecond\n";
        let translator = Translator::parse(catalog).expect("catalog");
        assert_eq!(translator.len(), 1);
        assert_eq!(translator.translate("original"), Some("first\nsecond"));
    }

    #[test]
    fn the_last_duplicate_wins() {
        let translator = Translator::parse("yes\tYes\nyes\tOkay\n").expect("catalog");
        assert_eq!(translator.translate("yes"), Some("Okay"));
    }

    #[test]
    fn a_line_without_a_tab_is_reported_with_its_number() {
        let error = Translator::parse("ok\tfine\nbroken\n").unwrap_err();
        assert_eq!(
            error.to_string(),
            "translation catalog line 2: expected original<TAB>translation"
        );
    }

    #[test]
    fn an_empty_original_is_rejected() {
        let error = Translator::parse("\tignored\n").unwrap_err();
        assert_eq!(
            error.to_string(),
            "translation catalog line 1: the original string is empty"
        );
    }

    #[test]
    fn missing_strings_are_left_to_the_script() {
        let translator = Translator::parse("yes\tYes\n").expect("catalog");
        assert_eq!(translator.translate("no"), None);
        assert!(!translator.is_empty());
    }
}
