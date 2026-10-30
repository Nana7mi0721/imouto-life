//! Integration test: every shipped message string round-trips through the
//! tokeniser.
//!
//! The numbers below come from the opcode 101 (Message) strings in
//! `work/Data/BasicData/CommonEvent.dat`: 350 events carrying 2,113 strings,
//! and the per-variant histogram this game's data actually produces. The
//! test skips itself when the data tree is absent so the crate stays testable
//! without the game files.

use std::collections::BTreeMap;
use std::path::PathBuf;

use wolf_format::command::Slot;
use wolf_format::commonevent::CommonEventData;
use wolf_format::messagetext::{self, Align, CodeKind, TextToken, VarBank};

/// Opcode of the Message instruction that carries a display string.
const OPCODE_MESSAGE: u32 = 101;

/// Strings carried by opcode 101 across the whole database.
const EXPECTED_MESSAGES: usize = 2_113;

/// Events in the shipped CommonEvent.dat.
const EXPECTED_EVENTS: usize = 350;

fn data_root() -> PathBuf {
    let raw = match std::env::var("WOLF_DATA_ROOT") {
        Ok(value) if !value.is_empty() => PathBuf::from(value),
        _ => PathBuf::from("work/full"),
    };
    if raw.is_absolute() {
        return raw;
    }
    let manifest = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    let workspace = manifest
        .parent()
        .and_then(|crates| crates.parent())
        .unwrap_or(&manifest);
    let candidate = workspace.join(&raw);
    if candidate.is_dir() {
        candidate
    } else {
        raw
    }
}

fn load_common_events() -> Option<CommonEventData> {
    let path = data_root().join("BasicData").join("CommonEvent.dat");
    let data = std::fs::read(path).ok()?;
    CommonEventData::parse(&data).ok()
}

/// Every message string in the database, in file order.
fn messages(data: &CommonEventData) -> Vec<String> {
    let mut out = Vec::new();
    for event in &data.events {
        for slot in &event.commands {
            if let Slot::Command(command) = slot {
                if command.opcode == OPCODE_MESSAGE {
                    if let Some(text) = command.strings.first() {
                        out.push(text.clone());
                    }
                }
            }
        }
    }
    out
}

/// Variant counts across the shipped database, from docs/TEXT_SPEC.md section 3.
#[test]
fn token_histogram_matches_spec() {
    let Some(data) = load_common_events() else {
        eprintln!(
            "skipping: no CommonEvent.dat under {}",
            data_root().display()
        );
        return;
    };
    assert_eq!(data.events.len(), EXPECTED_EVENTS);
    let strings = messages(&data);
    assert_eq!(strings.len(), EXPECTED_MESSAGES);

    let mut histogram: BTreeMap<&'static str, usize> = BTreeMap::new();
    for text in &strings {
        for token in messagetext::tokenize(text) {
            *histogram.entry(variant_name(&token)).or_insert(0) += 1;
        }
    }

    // Only these nine variants occur. Everything else in the documented
    // grammar is reachable but unused by this game (no c colour or
    // s speed codes at all).
    assert_eq!(histogram.len(), 9, "unexpected variants: {histogram:?}");
    assert_eq!(histogram["Text"], 2_590);
    assert_eq!(histogram["Outline"], 2_055);
    assert_eq!(histogram["Newline"], 449);
    assert_eq!(histogram["Var"], 84);
    assert_eq!(histogram["FontSize"], 7);
    assert_eq!(histogram["Instant"], 44);
    assert_eq!(histogram["Align"], 11);
    assert_eq!(histogram["Pause"], 2);
    assert_eq!(histogram["Close"], 4);
}

fn variant_name(token: &TextToken) -> &'static str {
    match token {
        TextToken::Text(_) => "Text",
        TextToken::Newline => "Newline",
        TextToken::Backslash => "Backslash",
        TextToken::Align(_) => "Align",
        TextToken::Outline(_) => "Outline",
        TextToken::OutlineWidth(_) => "OutlineWidth",
        TextToken::OutlineColor(_) => "OutlineColor",
        TextToken::Color(_) => "Color",
        TextToken::ShadowColor(_) => "ShadowColor",
        TextToken::RubyColor(_) => "RubyColor",
        TextToken::RubySize(_) => "RubySize",
        TextToken::FontSize(_) => "FontSize",
        TextToken::FontSizeDelta(_) => "FontSizeDelta",
        TextToken::Baseline(_) => "Baseline",
        TextToken::FontSlot(_) => "FontSlot",
        TextToken::AntiAlias(_) => "AntiAlias",
        TextToken::LetterSpacing(_) => "LetterSpacing",
        TextToken::LineGap(_) => "LineGap",
        TextToken::Speed(_) => "Speed",
        TextToken::LineStartX(_) => "LineStartX",
        TextToken::OffsetX(_) => "OffsetX",
        TextToken::OffsetY(_) => "OffsetY",
        TextToken::AbsoluteX(_) => "AbsoluteX",
        TextToken::AbsoluteY(_) => "AbsoluteY",
        TextToken::Wait => "Wait",
        TextToken::Close => "Close",
        TextToken::Pause => "Pause",
        TextToken::Instant(_) => "Instant",
        TextToken::Icon(_) => "Icon",
        TextToken::IconNearest(_) => "IconNearest",
        TextToken::IconScale(_) => "IconScale",
        TextToken::Image(_) => "Image",
        TextToken::ImageNearest(_) => "ImageNearest",
        TextToken::Sound(_) => "Sound",
        TextToken::Ruby { .. } => "Ruby",
        TextToken::Var(_) => "Var",
        TextToken::Code { .. } => "Code",
    }
}

/// to_source(tokenize(s)) == s for every shipped message.
///
/// This is the invariant the whole module rests on: a token list is not a lossy
/// view of the source but a bijection with it, so a message can be edited in
/// place without corrupting an escape.
#[test]
fn roundtrip_is_exact_for_every_message() {
    let Some(data) = load_common_events() else {
        eprintln!(
            "skipping: no CommonEvent.dat under {}",
            data_root().display()
        );
        return;
    };
    let strings = messages(&data);
    assert_eq!(strings.len(), EXPECTED_MESSAGES);

    let mut failures = Vec::new();
    for text in &strings {
        let rendered = messagetext::to_source(&messagetext::tokenize(text));
        if rendered != *text {
            failures.push((text.clone(), rendered));
        }
    }
    assert!(
        failures.is_empty(),
        "{} of {} messages failed to round-trip, first: {:?}",
        failures.len(),
        strings.len(),
        failures.first()
    );
}

/// The observed subset of the grammar, counted exactly.
///
/// docs/TEXT_SPEC.md section 3 records these numbers; a drift here means either
/// the data changed or the tokeniser started accepting something it should not.
#[test]
fn observed_codes_match_spec() {
    let Some(data) = load_common_events() else {
        eprintln!(
            "skipping: no CommonEvent.dat under {}",
            data_root().display()
        );
        return;
    };
    let strings = messages(&data);

    let mut colors: BTreeMap<u32, usize> = BTreeMap::new();
    let mut banks: BTreeMap<&'static str, usize> = BTreeMap::new();
    let mut aligns: BTreeMap<&'static str, usize> = BTreeMap::new();
    let mut sizes: BTreeMap<u32, usize> = BTreeMap::new();
    let mut starting_outline = 0usize;
    let mut plain = 0usize;
    let mut multiline = 0usize;

    for text in &strings {
        if !text.contains('\\') {
            plain += 1;
        }
        if text.contains('\n') {
            multiline += 1;
        }
        let tokens = messagetext::tokenize(text);
        if matches!(tokens.first(), Some(TextToken::Outline(true))) {
            starting_outline += 1;
        }
        for token in &tokens {
            match token {
                TextToken::Color(color) => *colors.entry(*color).or_insert(0) += 1,
                TextToken::FontSize(size) => *sizes.entry(*size).or_insert(0) += 1,
                TextToken::Align(align) => *aligns.entry(align.tag()).or_insert(0) += 1,
                TextToken::Var(var) => *banks.entry(var.bank.name()).or_insert(0) += 1,
                _ => {}
            }
        }
    }

    // \c[n]: this game ships no colour codes at all.
    assert!(colors.is_empty(), "unexpected colours: {colors:?}");

    // \f[n]: three distinct sizes, 7 uses.
    assert_eq!(sizes.len(), 3);
    assert_eq!(sizes.get(&5), Some(&1));
    assert_eq!(sizes.get(&24), Some(&1));
    assert_eq!(sizes.get(&32), Some(&5));
    assert_eq!(sizes.values().sum::<usize>(), 7);

    // \cself and \cdb are the only variable banks used; \v never appears.
    assert_eq!(banks.get("cself"), Some(&70));
    assert_eq!(banks.get("cdb"), Some(&14));
    assert_eq!(banks.get("v"), None);
    assert_eq!(banks.len(), 2);

    // <C> 11, <L> and <R> never.
    assert_eq!(aligns.get("<C>"), Some(&11));
    assert_eq!(aligns.get("<L>"), None);
    assert_eq!(aligns.get("<R>"), None);

    // 2,055 of 2,113 messages open with \E; none carry no escape at all.
    assert_eq!(starting_outline, 2_055);
    assert_eq!(plain, 0);
    assert_eq!(multiline, 427);
}

/// strip() keeps prose and drops markup.
#[test]
fn strip_keeps_prose_only() {
    assert_eq!(messagetext::strip("\\E你好\\c[7]，世界"), "你好，世界");
    assert_eq!(messagetext::strip("第一行\n第二行"), "第一行\n第二行");
    // A doubled backslash is a literal one and survives stripping.
    assert_eq!(messagetext::strip("C:\\\\path"), "C:\\path");
    // Ruby keeps its base text, not its annotation.
    assert_eq!(messagetext::strip("\\r[漢字,かんじ]です"), "漢字です");
    // Every escape the game ships disappears.
    let stripped = messagetext::strip("\\E\\c[1]\\f[14]\\v[12]\\cself[13]\\sp[40]文字");
    assert_eq!(stripped, "文字");
}

/// A message with no escapes comes back unchanged.
#[test]
fn plain_text_is_one_token() {
    let tokens = messagetext::tokenize("普通の文字列");
    assert_eq!(tokens, vec![TextToken::Text("普通の文字列".to_string())]);
    assert_eq!(messagetext::strip("普通の文字列"), "普通の文字列");
}

/// \E followed by digits is the outline code plus ordinary text.
///
/// This is the case a naive "scan the letters after the backslash" lexer gets
/// wrong: \E3000G is not an unknown escape called E3000G, it is \E and then the
/// price 3000G.
#[test]
fn outline_before_digits_is_not_a_code() {
    let tokens = messagetext::tokenize("\\E3000G诶……要买么？");
    assert_eq!(
        tokens,
        vec![
            TextToken::Outline(true),
            TextToken::Text("3000G诶……要买么？".to_string()),
        ]
    );
}

/// An unclosed bracket, a trailing backslash and a lone '<' are literal text.
///
/// Invariant 1: the tokeniser never panics and never guesses. Anything it cannot
/// finish reading stays as the bytes it was handed.
#[test]
fn malformed_input_degrades_to_literal() {
    for source in [
        "\\",
        "\\[",
        "\\c[",
        "\\v[1",
        "\\cself[\\v[",
        "\\img[",
        "<",
        "<L",
        "<X>",
        "\\A",
    ] {
        let tokens = messagetext::tokenize(source);
        assert_eq!(
            messagetext::to_source(&tokens),
            source,
            "round trip failed for {source:?}"
        );
    }
    // A trailing backslash is just a backslash.
    assert_eq!(
        messagetext::tokenize("abc\\"),
        vec![TextToken::Text("abc\\".to_string())]
    );
}

/// \cself[\v[12]] keeps the inner escape instead of resolving it.
///
/// Precedence puts \v below \cself, so the bracket may legally contain a \v
/// escape. Resolving it here would need VM state the format crate does not have;
/// the structure is preserved and VarRef::slot reports None so the caller knows
/// it must ask the VM.
#[test]
fn nested_variable_escape_is_preserved() {
    let tokens = messagetext::tokenize("\\cself[\\v[12]]");
    let [TextToken::Var(var)] = tokens.as_slice() else {
        panic!("expected one Var token, got {tokens:?}");
    };
    assert_eq!(var.bank, VarBank::CommonSelf);
    assert_eq!(var.fields(), vec!["\\v[12]".to_string()]);
    assert_eq!(var.slot(), None);
    assert_eq!(
        messagetext::to_source(&tokens),
        "\\cself[\\v[12]]".to_string()
    );

    // The three-field database form, with a nested escape in the middle field.
    let tokens = messagetext::tokenize("\\cdb[0:\\cdb[6:0:1]:0]");
    let [TextToken::Var(var)] = tokens.as_slice() else {
        panic!("expected one Var token, got {tokens:?}");
    };
    assert_eq!(var.bank, VarBank::VarDb);
    assert_eq!(var.fields().len(), 3);
    assert_eq!(var.fields()[1], "\\cdb[6:0:1]");
}

/// Reserve banks put the digit before the bracket.
///
/// \v1[30] is bank 1 slot 30, not variable 1 with argument 30 — the digit is
/// part of the code name.
#[test]
fn reserve_bank_digit_is_part_of_the_name() {
    let tokens = messagetext::tokenize("\\v1[30]");
    let [TextToken::Var(var)] = tokens.as_slice() else {
        panic!("expected one Var token, got {tokens:?}");
    };
    assert_eq!(var.bank, VarBank::Reserve(1));
    assert_eq!(var.slot(), Some(30));
    assert_eq!(messagetext::to_source(&tokens), "\\v1[30]");

    // \v0 is not a reserve bank: 1 to 9 only. It stays literal.
    assert_eq!(
        messagetext::tokenize("\\v0[1]"),
        vec![TextToken::Text("\\v0[1]".to_string())]
    );
}

/// An image path keeps its literal backslash.
///
/// The bracket body of \img is a filesystem path relative to Data/, and WOLF's
/// own documentation uses one with a backslash in it. Recursing into it would
/// read ピクチャ as an unknown escape and corrupt the path.
#[test]
fn image_path_is_not_tokenised() {
    let tokens = messagetext::tokenize("\\img[ピクチャ\\Test1.png]");
    assert_eq!(
        tokens,
        vec![TextToken::Image("ピクチャ\\Test1.png".to_string())]
    );
    assert_eq!(
        messagetext::to_source(&tokens),
        "\\img[ピクチャ\\Test1.png]"
    );
}

/// Ruby splits on the first comma only.
#[test]
fn ruby_splits_on_first_comma() {
    let tokens = messagetext::tokenize("\\r[a,b,c]");
    assert_eq!(
        tokens,
        vec![TextToken::Ruby {
            text: "a".to_string(),
            ruby: "b,c".to_string(),
        }]
    );
    assert_eq!(messagetext::to_source(&tokens), "\\r[a,b,c]");
}

/// A non-canonical argument falls back to a verbatim Code token.
///
/// Numeric arguments in the shipped data are all canonical decimals, so an
/// integer token always re-renders byte-identically. Anything else — a computed
/// argument, a leading zero — keeps its source spelling instead of being
/// normalised into a different string.
#[test]
fn non_canonical_argument_stays_verbatim() {
    let tokens = messagetext::tokenize("\\c[\\v[3]]");
    let [TextToken::Code { args, .. }] = tokens.as_slice() else {
        panic!("expected one Code token, got {tokens:?}");
    };
    assert_eq!(args, &vec!["\\v[3]".to_string()]);
    assert_eq!(messagetext::to_source(&tokens), "\\c[\\v[3]]");

    assert_eq!(
        messagetext::tokenize("\\c[007]"),
        vec![TextToken::Code {
            kind: CodeKind::Color,
            args: vec!["007".to_string()],
        }]
    );
}

/// The width hint counts glyph cells, not escapes.
#[test]
fn width_hint_counts_glyphs() {
    // \E and \c[7] draw nothing, so only the four characters count.
    assert_eq!(
        messagetext::display_width_hint(&messagetext::tokenize("\\E\\c[7]文字数")),
        3
    );
    // A newline resets the line but contributes no cell.
    assert_eq!(
        messagetext::display_width_hint(&messagetext::tokenize("ab\ncd")),
        4
    );
    // A doubled backslash draws one glyph; ruby counts its base only.
    assert_eq!(
        messagetext::display_width_hint(&messagetext::tokenize("a\\\\b")),
        3
    );
    assert_eq!(
        messagetext::display_width_hint(&messagetext::tokenize("\\r[漢字,かんじ]")),
        2
    );
}

/// Deep nesting stops at MAX_DEPTH instead of recursing without bound.
#[test]
fn nesting_is_bounded() {
    let mut source = String::from("1");
    for _ in 0..40 {
        source = format!("\\v[{source}]");
    }
    let tokens = messagetext::tokenize(&source);
    // Whatever it decides, it must survive and re-render exactly.
    assert_eq!(messagetext::to_source(&tokens), source);
}

/// The alignment tags are only recognised as the exact three-byte forms.
///
/// Messages contain <状態A> and <装着A?> as ordinary writing, so a looser rule
/// would turn prose into markup.
#[test]
fn angle_tags_are_exact() {
    assert_eq!(
        messagetext::tokenize("<C>"),
        vec![TextToken::Align(Align::Center)]
    );
    assert_eq!(
        messagetext::tokenize("<R>"),
        vec![TextToken::Align(Align::Right)]
    );
    assert_eq!(
        messagetext::tokenize("<状態A>"),
        vec![TextToken::Text("<状態A>".to_string())]
    );
    assert_eq!(
        messagetext::tokenize("<L"),
        vec![TextToken::Text("<L".to_string())]
    );
}

/// Every pathological input from the design notes round-trips byte for byte.
///
/// This is the table the tokeniser was hardened against: unbalanced brackets,
/// empty brackets, escapes with no body, nested escapes, image paths that
/// contain a backslash, reserve-bank digits, control characters and the
/// \E-followed-by-digits case that must stay prose. Invariant 1 and 2 are
/// asserted together here — nothing may panic and nothing may be rewritten.
#[test]
fn pathological_inputs_round_trip() {
    const CASES: [&str; 60] = [
        "\\",
        "\\[",
        "\\c[",
        "\\c[]",
        "\\v[",
        "\\v[\\v[\\v[1]]]",
        "<",
        "<L",
        "<X>",
        "\\E\\E\\E",
        "\\img[",
        "\\r[",
        "\\r[a]",
        "\\r[a,b]",
        "\\cdb[1:2]",
        "\\cdb[1:2:3:4]",
        "\\v9[1]",
        "\\v0[1]",
        "\\A",
        "\\A+",
        "\\A-",
        "\\c[-1]",
        "\\cE[-1]",
        "\\wE[99]",
        "\\f+[-3]",
        "\u{0}\u{1}\u{feff}",
        "\\\\",
        "\\\\E",
        "\\<",
        "\\>",
        "\\!",
        "\\^",
        "\\.",
        "\\font[3]",
        "\\isize[150]",
        "\\img[ピクチャ\\Test1.png]",
        "\\se[10,80,100]",
        "\\cself[\\v[12]]",
        "\\cdb[0:\\cdb[6:0:1]:0]",
        "\\v1[30]",
        "\\sysS[4]",
        "\\xyN[a b:1:2]",
        "\\i[1234]",
        "\\iS[3]",
        "\\space[8]",
        "\\bx[40]",
        "\\mx[-100]",
        "\\ay[12]",
        "\\-[-2]",
        "\\m[20]",
        "\\f[18]\\c[3]\\E text <C>\\N",
        "\\E3000G诶……要买么？",
        "\\E，哥哥",
        "\\E\"独家新闻！\"",
        "\\",
        "\\",
        "\\\\\\",
        "\\\\\\E",
        "<L><C><R>",
        "\\N\\E",
    ];
    for source in CASES {
        let tokens = messagetext::tokenize(source);
        assert_eq!(
            messagetext::to_source(&tokens),
            source,
            "round trip failed for {source:?}"
        );
    }
}
