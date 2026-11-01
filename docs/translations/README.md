# Translation catalogs (M5-D)

These are demonstration catalogs for the optional content text layer. The shipped data stays
unchanged; a catalog only replaces exact strings as they leave the VM.

## Format

UTF-8 TSV, one entry per line:

    original<TAB>translation

- Lines whose first non-space character is `#` are comments; blank lines are ignored.
- The left column must match the runtime string exactly (trailing spaces included).
- The right column accepts `\n`, `\t` and `\\` escapes.
- A duplicate left column keeps the last translation.

## Use

    wolf-cli play --load-save work/Data/Save/SaveData01.sav --translation docs/translations/en.tsv
    wolf-cli capture --load-save work/Data/Save/SaveData01.sav --event 245 \
        --translation docs/translations/en.tsv --frames 90 --out work/out/night_en.png

`en.tsv` and `ja.tsv` only cover the six night-menu labels as a working sample; a complete
translation is a community/authoring effort, not a code change. Missing entries fall back to
the original script text.
