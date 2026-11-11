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
//! Blank lines and lines whose first non-space character is '#' are ignored. Both
//! columns understand the escapes \n, \t, \r and \\, so a source that itself contains
//! a literal TAB, CR, LF or backslash can be written on one physical line (the emitted
//! template uses this to list every static string). Any other backslash sequence is
//! copied through untouched, which keeps display markup such as \c[6] and \v[12]
//! literal. Duplicate originals keep the last translation. A line whose translation
//! column is empty is a placeholder: it is kept out of the catalog so a generated
//! template can be loaded without hiding any text.
//!
//! A source may be prefixed with `[msg]` or `[choice]` to target only messages or only
//! choices; an unprefixed entry stays the fallback for both. This is the finer key for
//! the same source string meaning different things in the two contexts.
//!
//! [`SourceScan`] is the authoring companion: it walks every common event, collects the
//! literal message and choice strings, and can emit a template catalog or report how
//! many static strings a catalog covers. Strings that interpolate variables (`\v[12]`,
//! `\self[3]`, ...) have no fixed runtime text, so they are counted separately and are
//! not part of the template or the coverage denominator.
//!
//! No external dependency is involved.

use std::collections::{BTreeMap, BTreeSet, HashMap};
use std::fmt;
use std::fs;
use std::io;
use std::path::{Path, PathBuf};

use wolf_format::command::Slot;
use wolf_format::commonevent::CommonEventData;

/// Where a game string appears, used to scope catalog entries.
#[derive(Clone, Copy, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum Context {
    /// Opcode 101 message text.
    Message,
    /// Opcode 102 choice option.
    Choice,
}

impl Context {
    /// The TSV prefix that scopes an entry to this context.
    #[must_use]
    pub const fn key(self) -> &'static str {
        match self {
            Self::Message => "[msg]",
            Self::Choice => "[choice]",
        }
    }
}

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
    /// Unscoped entries: apply to both messages and choices.
    entries: HashMap<String, String>,
    /// Context-scoped entries: apply only where the source matches the context.
    scoped: HashMap<Context, HashMap<String, String>>,
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
            // An empty right column is the placeholder a generated template leaves
            // behind; it must not blank the runtime text, so it is not an entry.
            if translated.is_empty() {
                continue;
            }
            let translated = unescape(translated);
            // The source column uses the same escaping as the translation column, so
            // a literal TAB/CR/LF/backslash written as \t/\r/\n/\\ recovers the exact
            // runtime string. Other backslash sequences (display markup) stay literal.
            let unescaped = unescape(original);
            let mut source: &str = unescaped.as_str();
            let mut context = None;
            for candidate in [Context::Message, Context::Choice] {
                if let Some(rest) = source.strip_prefix(candidate.key()) {
                    source = rest;
                    context = Some(candidate);
                    break;
                }
            }
            if source.is_empty() {
                return Err(TranslateError::Syntax {
                    line: index + 1,
                    reason: "the original string is empty after its context prefix",
                });
            }
            if let Some(context) = context {
                translator
                    .scoped
                    .entry(context)
                    .or_default()
                    .insert(source.to_owned(), translated);
            } else {
                translator.entries.insert(source.to_owned(), translated);
            }
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
    ///
    /// Unscoped lookups ignore the context, which keeps the original M5-D catalog
    /// format working unchanged.
    #[must_use]
    pub fn translate<'a>(&'a self, text: &'a str) -> Option<&'a str> {
        self.entries.get(text).map(String::as_str)
    }

    /// Returns the replacement for a string in one context.
    ///
    /// A `[msg]` / `[choice]` entry wins over an unscoped entry; the unscoped entry
    /// remains the fallback for the other context.
    #[must_use]
    pub fn translate_in<'a>(&'a self, context: Context, text: &'a str) -> Option<&'a str> {
        self.scoped
            .get(&context)
            .and_then(|entries| entries.get(text))
            .or_else(|| self.entries.get(text))
            .map(String::as_str)
    }

    /// Number of loaded entries, scoped and unscoped combined.
    #[must_use]
    pub fn len(&self) -> usize {
        self.entries.len() + self.scoped.values().map(HashMap::len).sum::<usize>()
    }

    /// Merges another catalog into this one; the incoming entries win.
    ///
    /// Used for mod-level catalogs (loaded in mod order, later mods overriding) and
    /// for the explicit `--translation` catalog, which is merged last so it always has
    /// the final say.
    pub fn merge(&mut self, other: Self) {
        self.entries.extend(other.entries);
        for (context, entries) in other.scoped {
            self.scoped.entry(context).or_default().extend(entries);
        }
    }

    /// True when the catalog is empty (the default, meaning "show the script verbatim").
    #[must_use]
    pub fn is_empty(&self) -> bool {
        self.entries.is_empty() && self.scoped.is_empty()
    }

    /// Every catalog key, as `(context, source)`; None means the entry is unscoped.
    ///
    /// Used by the coverage report to find entries that no longer match any script
    /// string.
    pub fn keys(&self) -> impl Iterator<Item = (Option<Context>, &str)> {
        self.entries
            .keys()
            .map(|key| (None, key.as_str()))
            .chain(self.scoped.iter().flat_map(|(context, entries)| {
                entries
                    .keys()
                    .map(move |key| (Some(*context), key.as_str()))
            }))
    }

    /// True when a key is present at the given scope.
    #[must_use]
    pub fn has_in(&self, context: Context, text: &str) -> bool {
        self.scoped
            .get(&context)
            .is_some_and(|entries| entries.contains_key(text))
            || self.entries.contains_key(text)
    }
}

/// Expands the escapes a TSV cell cannot express literally: \n, \t, \r and \\.
///
/// An unrecognised backslash sequence (display markup such as \c[6] or \v[12]) is
/// copied through unchanged, so both the escaped template form and a plain
/// hand-written catalog round-trip the same way.
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
            Some('r') => out.push('\r'),
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

/// Escapes a TSV cell so a string containing a literal TAB, CR, LF or backslash fits
/// on one physical line. The inverse of unescape; used by SourceScan::template.
fn escape(text: &str) -> String {
    let mut out = String::with_capacity(text.len());
    for ch in text.chars() {
        match ch {
            '\\' => out.push_str("\\\\"),
            '\t' => out.push_str("\\t"),
            '\n' => out.push_str("\\n"),
            '\r' => out.push_str("\\r"),
            other => out.push(other),
        }
    }
    out
}

/// One distinct source string, with every event that mentions it.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct SourceText {
    /// Message or choice.
    pub context: Context,
    /// Runtime text: variable escapes are not expanded, but a leading `@n` face tag
    /// (which the host has always stripped before translation) is.
    pub text: String,
    /// Events where the string is literal and can be matched exactly.
    pub static_events: BTreeSet<u32>,
    /// Events where the string interpolates variables, so its runtime text varies.
    pub dynamic_events: BTreeSet<u32>,
}

impl SourceText {
    /// True when at least one site uses this string literally.
    #[must_use]
    pub fn is_static(&self) -> bool {
        !self.static_events.is_empty()
    }
}

/// The literal message/choice strings of a `CommonEvent.dat`.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct SourceScan {
    /// One entry per distinct `(context, text)`, sorted by context then text.
    pub texts: Vec<SourceText>,
}

impl SourceScan {
    /// Walks every event and collects opcode 101/102 strings.
    #[must_use]
    pub fn from_common_events(events: &CommonEventData) -> Self {
        let mut buckets: BTreeMap<(Context, String), (BTreeSet<u32>, BTreeSet<u32>)> =
            BTreeMap::new();
        for event in &events.events {
            for slot in &event.commands {
                let Slot::Command(command) = slot else {
                    continue;
                };
                match command.opcode {
                    101 => {
                        if let Some(raw) = command.strings.first() {
                            Self::record(&mut buckets, Context::Message, event.id, raw);
                        }
                    }
                    102 => {
                        for raw in &command.strings {
                            Self::record(&mut buckets, Context::Choice, event.id, raw);
                        }
                    }
                    _ => {}
                }
            }
        }
        Self::finish(buckets)
    }

    fn finish(buckets: BTreeMap<(Context, String), (BTreeSet<u32>, BTreeSet<u32>)>) -> Self {
        Self {
            texts: buckets
                .into_iter()
                .map(
                    |((context, text), (static_events, dynamic_events))| SourceText {
                        context,
                        text,
                        static_events,
                        dynamic_events,
                    },
                )
                .collect(),
        }
    }

    fn record(
        buckets: &mut BTreeMap<(Context, String), (BTreeSet<u32>, BTreeSet<u32>)>,
        context: Context,
        event: u32,
        raw: &str,
    ) {
        // `expand` with a lookup that knows nothing replaces variable escapes with
        // `0`/empty; when it changes the string the site is value-dependent. Display
        // markup (`\c[6]`, `\n`, `@1`) passes through untouched.
        let mut lookup = wolf_vm::text::NoVars;
        let expanded = wolf_vm::text::expand(raw, &mut lookup);
        let dynamic = expanded != raw;
        let text = if context == Context::Message {
            strip_face(&expanded).to_owned()
        } else {
            expanded
        };
        let entry = buckets
            .entry((context, text))
            .or_insert_with(|| (BTreeSet::new(), BTreeSet::new()));
        if dynamic {
            entry.1.insert(event);
        } else {
            entry.0.insert(event);
        }
    }

    /// Number of distinct static strings (the template / coverage denominator).
    #[must_use]
    pub fn static_count(&self) -> usize {
        self.texts.iter().filter(|text| text.is_static()).count()
    }

    /// Number of distinct strings that only interpolate variables.
    #[must_use]
    pub fn dynamic_count(&self) -> usize {
        self.texts.iter().filter(|text| !text.is_static()).count()
    }

    /// Number of static sites, counting an event once per distinct string.
    #[must_use]
    pub fn static_sites(&self) -> usize {
        self.texts
            .iter()
            .filter(|text| text.is_static())
            .map(|text| text.static_events.len())
            .sum()
    }

    /// Builds a fill-in TSV template: every static string, an empty translation
    /// column, and a header explaining the format.
    ///
    /// The source column uses the same escaping as the translation column, so a string
    /// containing a literal TAB/CR/LF (or a backslash) stays on one physical line and
    /// round-trips through Translator::parse. Every static string is listed, so the row
    /// count always equals static_count().
    #[must_use]
    pub fn template(&self) -> String {
        let mut out = String::new();
        out.push_str("# wolf-cli translations template\n");
        out.push_str(&format!(
            "# {} distinct static string(s); {} variable-dependent string(s) are not listed.\n",
            self.static_count(),
            self.dynamic_count()
        ));
        out.push_str("# Fill the empty column after the TAB; an empty translation is ignored.\n");
        out.push_str("# Prefix a source with [msg] or [choice] to target one context only.\n");
        out.push_str("# Both columns understand \\n, \\t, \\r and \\\\ escapes, so a source\n");
        out.push_str("# containing a literal TAB/CR/LF still occupies a single line.\n");
        for text in self.texts.iter().filter(|text| text.is_static()) {
            out.push_str(&escape(&text.text));
            out.push('\t');
            out.push('\n');
        }
        out
    }

    /// Compares a catalog against the static script strings.
    #[must_use]
    pub fn coverage(&self, translator: &Translator) -> Coverage {
        let mut covered = 0usize;
        let mut missing = Vec::new();
        for text in self.texts.iter().filter(|text| text.is_static()) {
            if translator.has_in(text.context, &text.text) {
                covered += 1;
            } else {
                missing.push((text.context, text.text.clone()));
            }
        }
        let known: BTreeSet<(Option<Context>, &str)> = self
            .texts
            .iter()
            .map(|text| (Some(text.context), text.text.as_str()))
            .collect();
        let all_text: BTreeSet<&str> = self.texts.iter().map(|text| text.text.as_str()).collect();
        let mut unused = Vec::new();
        for (context, key) in translator.keys() {
            let used = match context {
                Some(context) => known.contains(&(Some(context), key)),
                None => all_text.contains(key),
            };
            if !used {
                unused.push(key.to_owned());
            }
        }
        Coverage {
            static_total: self.static_count(),
            covered,
            missing,
            dynamic_total: self.dynamic_count(),
            unused,
        }
    }
}

/// Result of [`SourceScan::coverage`].
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct Coverage {
    /// Distinct static script strings.
    pub static_total: usize,
    /// How many of them the catalog replaces.
    pub covered: usize,
    /// Static strings with no catalog entry.
    pub missing: Vec<(Context, String)>,
    /// Distinct strings whose runtime text depends on variables (not counted).
    pub dynamic_total: usize,
    /// Catalog entries that match no script string at any scope.
    pub unused: Vec<String>,
}

/// Strips the `@n` speaker prefix exactly as the VM does before showing a message.
fn strip_face(text: &str) -> &str {
    let bytes = text.as_bytes();
    if bytes.first() == Some(&b'@') && bytes.get(1).is_some_and(|digit| digit.is_ascii_digit()) {
        text.get(2..).unwrap_or("")
    } else {
        text
    }
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

    #[test]
    fn an_empty_translation_is_a_placeholder_not_a_blanking_entry() {
        let translator = Translator::parse("yes\t\nno\tNo\n").expect("catalog");
        assert_eq!(translator.len(), 1);
        assert_eq!(translator.translate("yes"), None);
        assert_eq!(translator.translate("no"), Some("No"));
    }

    #[test]
    fn a_context_prefix_wins_and_falls_back_to_the_shared_entry() {
        use super::Context;
        let translator =
            Translator::parse("[msg]same\tSpoken\nsame\tShared\n[choice]only\tPicked\n")
                .expect("catalog");
        assert_eq!(
            translator.translate_in(Context::Message, "same"),
            Some("Spoken")
        );
        assert_eq!(
            translator.translate_in(Context::Choice, "same"),
            Some("Shared")
        );
        assert_eq!(
            translator.translate_in(Context::Choice, "only"),
            Some("Picked")
        );
        assert_eq!(translator.translate("same"), Some("Shared"));
        assert_eq!(translator.translate_in(Context::Message, "only"), None);
    }

    #[test]
    fn a_context_prefix_without_a_source_is_rejected() {
        let error = Translator::parse("[msg]\tignored\n").unwrap_err();
        assert_eq!(
            error.to_string(),
            "translation catalog line 1: the original string is empty after its context prefix"
        );
    }

    #[test]
    fn a_merge_lets_the_incoming_catalog_override() {
        use super::Context;
        let mut base = Translator::parse("same\tBase\n[msg]same\tSpoken base\nonly\tBase only\n")
            .expect("base");
        base.merge(Translator::parse("[msg]same\tSpoken mod\nonly\tMod only\n").expect("mod"));
        assert_eq!(base.translate("same"), Some("Base"));
        assert_eq!(
            base.translate_in(Context::Message, "same"),
            Some("Spoken mod")
        );
        assert_eq!(base.translate("only"), Some("Mod only"));
        assert_eq!(base.len(), 3);
    }

    fn scan_of(entries: &[(super::Context, u32, &str)]) -> super::SourceScan {
        let mut buckets = std::collections::BTreeMap::new();
        for (context, event, raw) in entries {
            super::SourceScan::record(&mut buckets, *context, *event, raw);
        }
        super::SourceScan::finish(buckets)
    }

    #[test]
    fn a_static_message_is_stored_without_its_face_prefix() {
        use super::Context;
        let scan = scan_of(&[
            (Context::Message, 212, "@1早上好"),
            (Context::Choice, 245, "开始交流"),
        ]);
        assert_eq!(scan.static_count(), 2);
        let message = scan
            .texts
            .iter()
            .find(|text| text.context == Context::Message)
            .expect("message");
        assert_eq!(message.text, "早上好");
        assert_eq!(
            message.static_events.iter().copied().collect::<Vec<_>>(),
            vec![212]
        );
        assert!(message.dynamic_events.is_empty());
    }

    #[test]
    fn a_variable_escape_is_dynamic_and_kept_out_of_the_template() {
        use super::Context;
        let scan = scan_of(&[(Context::Message, 212, "还有\\v[3]天")]);
        assert_eq!(scan.static_count(), 0);
        assert_eq!(scan.dynamic_count(), 1);
        let template = scan.template();
        assert!(template.contains("0 distinct static string(s)"));
        assert!(!template.contains("还有"));
    }

    #[test]
    fn a_template_row_is_a_placeholder_that_parses_as_no_entry() {
        use super::Context;
        let scan = scan_of(&[(Context::Message, 212, "早上好")]);
        let template = scan.template();
        assert!(template.contains("早上好\t\n"), "{template}");
        let translator = Translator::parse(&template).expect("template catalog");
        assert!(translator.is_empty());
        let coverage = scan.coverage(&translator);
        assert_eq!(coverage.static_total, 1);
        assert_eq!(coverage.covered, 0);
        assert_eq!(coverage.missing.len(), 1);
    }

    #[test]
    fn coverage_respects_scoped_entries_and_reports_unused_keys() {
        use super::Context;
        let scan = scan_of(&[(Context::Message, 212, "yes"), (Context::Choice, 245, "no")]);
        let translator = Translator::parse("[msg]yes\t是\nstale\t无\n").expect("catalog");
        let coverage = scan.coverage(&translator);
        assert_eq!(coverage.static_total, 2);
        assert_eq!(coverage.covered, 1);
        assert_eq!(coverage.missing, vec![(Context::Choice, "no".to_owned())]);
        assert_eq!(coverage.unused, vec!["stale".to_owned()]);
        assert_eq!(coverage.dynamic_total, 0);
    }

    #[test]
    fn a_source_with_a_literal_tab_round_trips_through_the_template() {
        use super::Context;
        let scan = scan_of(&[(Context::Message, 212, "a\tb")]);
        assert_eq!(scan.static_count(), 1);
        let template = scan.template();
        assert!(template.contains("a\\tb\t\n"), "{template:?}");
        let translator = Translator::parse("a\\tb\tA then B\n").expect("catalog");
        assert_eq!(translator.translate("a\tb"), Some("A then B"));
        let coverage = scan.coverage(&translator);
        assert_eq!(coverage.static_total, 1);
        assert_eq!(coverage.covered, 1);
        assert!(coverage.unused.is_empty());
    }

    #[test]
    fn a_source_with_a_literal_newline_is_escaped_and_parsed() {
        use super::Context;
        let scan = scan_of(&[(Context::Message, 7, "one\ntwo")]);
        let template = scan.template();
        assert!(template.contains("one\\ntwo\t\n"), "{template:?}");
        let translator = Translator::parse("one\\ntwo\tfirst\\nsecond\n").expect("catalog");
        assert_eq!(translator.translate("one\ntwo"), Some("first\nsecond"));
        assert_eq!(scan.coverage(&translator).covered, 1);
    }

    #[test]
    fn a_literal_backslash_in_a_source_round_trips() {
        use super::Context;
        let scan = scan_of(&[(Context::Message, 9, "line\\nbreak")]);
        let template = scan.template();
        assert!(template.contains("line\\\\nbreak\t\n"), "{template:?}");
        let translator = Translator::parse("line\\\\nbreak\tLine break\n").expect("catalog");
        assert_eq!(translator.translate("line\\nbreak"), Some("Line break"));
        assert_eq!(scan.coverage(&translator).covered, 1);
    }

    #[test]
    fn a_carriage_return_escape_is_expanded() {
        let translator = Translator::parse("x\tA\\rB\n").expect("catalog");
        assert_eq!(translator.translate("x"), Some("A\rB"));
    }

    #[test]
    fn an_unescaped_source_with_display_markup_still_matches() {
        use super::Context;
        let scan = scan_of(&[(Context::Message, 3, "\\E\\f[24]hello")]);
        let translator = Translator::parse("\\E\\f[24]hello\tHello\n").expect("catalog");
        assert_eq!(translator.translate("\\E\\f[24]hello"), Some("Hello"));
        assert_eq!(scan.coverage(&translator).covered, 1);
    }

    #[test]
    fn the_template_lists_every_static_string_even_with_control_characters() {
        use super::Context;
        let scan = scan_of(&[
            (Context::Message, 1, "plain"),
            (Context::Message, 2, "tab\there"),
            (Context::Message, 3, "line\nbreak"),
            (Context::Choice, 4, "carriage\rreturn"),
        ]);
        assert_eq!(scan.static_count(), 4);
        let template = scan.template();
        let rows: Vec<&str> = template
            .lines()
            .filter(|line| !line.starts_with('#'))
            .collect();
        assert_eq!(rows.len(), 4, "{template:?}");
        for line in rows {
            let (source, translation) = line.split_once('\t').expect("row has a tab");
            assert!(!source.chars().any(|ch| matches!(ch, '\t' | '\n' | '\r')));
            assert!(translation.is_empty());
        }
        assert!(!template.contains("were skipped"));
    }
}
