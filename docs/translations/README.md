# Translation catalogs (M5-D)

These are demonstration catalogs for the optional content text layer. The shipped data stays
unchanged; a catalog only replaces exact strings as they leave the VM.

## Format

UTF-8 TSV, one entry per line:

    original<TAB>translation

- Lines whose first non-space character is `#` are comments; blank lines are ignored.
- The left column must match the runtime string exactly (trailing spaces included).
- The right column accepts `\n`, `\t` and `\\` escapes.
- An empty right column is a placeholder: the line is ignored, so a generated template
  can be loaded as-is without hiding any text.
- A duplicate left column keeps the last translation.

## Scoped keys

Prefix the left column with `[msg]` or `[choice]` to target only messages or only
choices. A scoped entry wins over an unscoped one, and the unscoped entry stays the
fallback for the other context.

    [msg]同じ台詞	Spoken line
    [choice]同じ台詞	Menu label
    同じ台詞	Both contexts

## Authoring tools

    # Count the script's literal strings (1,218 static / 46 variable-dependent here)
    wolf-cli translations --root work/Data

    # Write a fill-in template (empty translation column = placeholder)
    wolf-cli translations --root work/Data --template work/out/i18n_template.tsv

    # Check coverage; --strict exits 1 when a static string is untranslated
    wolf-cli translations --root work/Data --check docs/translations/en.tsv --strict

Strings containing variable escapes (`\v[12]`, `\self[3]`, ...) have no fixed runtime
text, so they are reported separately and are not part of the template or the coverage
denominator.

## Use

    wolf-cli play --load-save work/Data/Save/SaveData01.sav --translation docs/translations/en.tsv
    wolf-cli capture --load-save work/Data/Save/SaveData01.sav --event 245 \
        --translation docs/translations/en.tsv --frames 90 --out work/out/night_en.png

`en.tsv` and `ja.tsv` only cover the six night-menu labels as a working sample; a complete
translation is a community/authoring effort, not a code change. Missing entries fall back to
the original script text.

A mod directory may also contain its own `translations.tsv` at the root. Mod catalogs
merge in `--mod` order (later wins), and an explicit `--translation` catalog merges last,
so it always has the final say.
