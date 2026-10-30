//! Integration test: the three database files parse byte-exactly.
//!
//! Expected numbers come from `docs/FORMAT_SPEC.md` §6.3 and `docs/BASELINE.json`.

use std::path::PathBuf;

use wolf_format::database::{Database, FieldKind};

/// Data root, resolved the way `wolf-cli` does it (see `tests/mps.rs`).
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

fn load(name: &str) -> Option<Vec<u8>> {
    std::fs::read(data_root().join("BasicData").join(name)).ok()
}

#[test]
fn database_files_match_their_baseline_shape() {
    // name, type count, type-0 field count, type-0 numeric fields, type-0 string
    // fields, type-0 row count — §6.3.
    let expected: [(&str, usize, usize, usize, usize, usize); 3] = [
        ("DataBase.dat", 40, 37, 32, 5, 44),
        ("CDataBase.dat", 30, 60, 55, 5, 17),
        ("SysDatabase.dat", 28, 8, 4, 4, 50),
    ];

    let mut loaded_any = false;
    for (name, types, fields, numbers, strings, rows) in expected {
        let Some(data) = load(name) else {
            eprintln!("skipping {name}: no data under {}", data_root().display());
            continue;
        };
        loaded_any = true;
        let parsed = Database::parse(&data).unwrap_or_else(|e| panic!("{name}: {e}"));
        assert_eq!(parsed.version, 0xC1, "{name}: version");
        assert_eq!(parsed.footer, 0xC1, "{name}: footer");
        assert_eq!(parsed.types.len(), types, "{name}: type count");

        let first = &parsed.types[0];
        assert_eq!(first.fields.len(), fields, "{name}: type 0 field count");
        assert_eq!(
            first.numeric_columns(),
            numbers,
            "{name}: type 0 numeric fields"
        );
        assert_eq!(
            first.string_columns(),
            strings,
            "{name}: type 0 string fields"
        );
        assert_eq!(first.rows.len(), rows, "{name}: type 0 row count");

        // Every row must carry exactly the columns the field table declares.
        for (index, row) in first.rows.iter().enumerate() {
            assert_eq!(
                row.numbers.len(),
                numbers,
                "{name}: row {index} numeric columns"
            );
            assert_eq!(
                row.strings.len(),
                strings,
                "{name}: row {index} string columns"
            );
        }
        // And every other type's rows must be consistent with its own table.
        for (type_index, db_type) in parsed.types.iter().enumerate() {
            for (row_index, row) in db_type.rows.iter().enumerate() {
                assert_eq!(
                    row.numbers.len(),
                    db_type.numeric_columns(),
                    "{name}: type {type_index} row {row_index} numeric columns"
                );
                assert_eq!(
                    row.strings.len(),
                    db_type.string_columns(),
                    "{name}: type {type_index} row {row_index} string columns"
                );
            }
        }
    }
    if !loaded_any {
        eprintln!(
            "skipping: no database files under {}",
            data_root().display()
        );
    }
}

#[test]
fn data_base_type_zero_has_the_documented_field_table() {
    let Some(data) = load("DataBase.dat") else {
        eprintln!("skipping: no data under {}", data_root().display());
        return;
    };
    let parsed = Database::parse(&data).expect("DataBase.dat parses");
    let first = &parsed.types[0];

    assert_eq!(first.data_id_method, 1, "type 0 data id method");
    let raw: Vec<u32> = first.fields.iter().map(FieldKind::raw).collect();
    assert_eq!(
        raw,
        vec![
            2000, 2001, 1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010, 2002,
            2003, 2004, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019, 1020, 1021, 1022,
            1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030, 1031
        ],
        "type 0 field positions"
    );
    assert_eq!(first.fields[0], FieldKind::Str(0));
    assert_eq!(first.fields[2], FieldKind::Num(0));
    assert_eq!(first.fields[17], FieldKind::Num(12));

    // Measured first row, §6.3. The string cells hold Shift-JIS names that the
    // reader decodes lossily to U+FFFD, so only the numeric columns are asserted
    // exactly.
    let row = &first.rows[0];
    assert_eq!(
        row.numbers,
        vec![
            10, 0, 0, 0, 2, -1, 0, 0, 100, 0, 20, 0, 0, -1, -1, -3, 0, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, 1, 0, 1, 100, 0, 0
        ],
        "type 0 row 0 numeric columns"
    );
    assert_eq!(row.strings.len(), 5, "type 0 row 0 string columns");
    assert!(
        row.strings[0].contains('\u{FFFD}'),
        "string 0 is a lossy name"
    );
    assert_eq!(row.strings[1], "", "string 1 empty");
    assert_eq!(row.strings[2], "", "string 2 empty");
    assert_eq!(row.strings[4], "", "string 4 empty");
}

#[test]
fn sys_database_type_zero_is_the_map_list() {
    let Some(data) = load("SysDatabase.dat") else {
        eprintln!("skipping: no data under {}", data_root().display());
        return;
    };
    let parsed = Database::parse(&data).expect("SysDatabase.dat parses");
    let first = &parsed.types[0];
    assert_eq!(first.data_id_method, 0, "type 0 data id method");
    assert_eq!(
        first.fields.iter().map(FieldKind::raw).collect::<Vec<_>>(),
        vec![2000, 1000, 1001, 1002, 1003, 2001, 2002, 2003],
        "type 0 field positions"
    );

    // 8 .mps files ship on disk, but only these 5 are registered — and in this
    // order, which is neither the file order nor the alphabetical order.
    let settings = parsed.map_settings();
    let paths: Vec<&str> = settings.iter().map(|s| s.path.as_str()).collect();
    assert_eq!(
        paths,
        [
            "MapData/TitleMap.mps",
            "MapData/SampleMapA.mps",
            "MapData/Map003.mps",
            "MapData/Map024.mps",
            "MapData/Map031.mps",
        ],
        "registered maps"
    );
    for setting in &settings {
        assert_eq!(
            setting.numbers.len(),
            4,
            "{}: numeric columns",
            setting.path
        );
        assert_eq!(setting.strings.len(), 4, "{}: string columns", setting.path);
        assert_eq!(
            setting.strings[0], setting.path,
            "{}: path is string column 0",
            setting.path
        );
    }
    // Row 0 of the table: the title map, with -1 sentinels in the three ids.
    assert_eq!(settings[0].numbers, vec![-1, -1, 0, -1], "TitleMap row");
    assert_eq!(settings[1].numbers, vec![-2, -1, 0, 0], "SampleMapA row");

    // The other 45 rows are empty slots and must not appear in the list.
    assert_eq!(first.rows.len(), 50, "type 0 row count");
    let empty = first
        .rows
        .iter()
        .filter(|row| row.strings.first().is_none_or(String::is_empty))
        .count();
    assert_eq!(empty, 45, "unregistered rows");
}

#[test]
fn databases_with_no_types_still_parse() {
    // A truncated header must fail loudly rather than yield an empty database.
    let empty = Database::parse(&[]);
    assert!(empty.is_err(), "empty buffer must not parse");
    let header_only = Database::parse(&[
        0x00, 0x57, 0x00, 0x00, 0x4F, 0x4C, 0x55, 0x46, 0x4D, 0x00, 0xC2,
    ]);
    assert!(
        header_only.is_err(),
        "header without a count must not parse"
    );
}

/// `.project` companions carry the labels the `.dat` files lack, one record per
/// type in `.dat` order (§6.8).
///
/// These labels are the keys `docs/OPCODE_250.md` relies on for database reads —
/// `stringArgs[1]` is the type label and `stringArgs[3]` the field label — so
/// they must come from the editor's own file rather than from a hard-coded table.
#[test]
fn project_names_align_with_data_base() {
    let (Some(data), Some(project)) = (load("DataBase.dat"), load("DataBase.project")) else {
        eprintln!(
            "skipping DataBase.project: no data under {}",
            data_root().display()
        );
        return;
    };
    let mut database = Database::parse(&data).expect("DataBase.dat parses");
    // The container on its own has no labels at all.
    assert_eq!(database.type_name(0), None, "the .dat has no type label");
    assert_eq!(
        database.field_name(0, 0),
        None,
        "the .dat has no field label"
    );

    assert_eq!(
        database.apply_project_names(&project),
        40,
        "the companion describes every type of the .dat"
    );
    assert_eq!(
        database.names.named_types(),
        29,
        "11 types are unnamed separators"
    );
    assert_eq!(database.names.named_fields(), 701, "field labels");
    assert_eq!(database.names.named_rows(), 756, "row labels");

    // Every one of the 40 types, in `.dat` order.
    let expected: [Option<&str>; 40] = [
        Some("技能"),
        Some("┗ アニメーション"),
        Some("アイテム"),
        Some("武器"),
        Some("防具"),
        Some("┗装備タイプ"),
        Some("戦闘コマンド"),
        Some("属性名の設定"),
        Some("状態設定"),
        Some("敵ｷｬﾗ個体ﾃﾞｰﾀ"),
        Some("┣ 敵行動AI"),
        Some("┣ 属性耐性"),
        Some("┗ 状態耐性"),
        Some("敵グループ"),
        Some("------------------------"),
        Some("用語設定"),
        Some("画像/音声設定"),
        Some("システム設定"),
        Some("ドロップアイテムデータ"),
        Some("アニメーション設定"),
        Some("◇吹き出しアイコン"),
        Some("EXスキル"),
        Some("吹き出し会話"),
        Some("サポートキャラ"),
        Some("立ち絵設定用"),
        Some("ランダム肩書"),
        Some("メッセージウィンドウ種類"),
        None,
        None,
        None,
        Some("アニメ設定"),
        Some("統計テキスト"),
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
    ];
    let got: Vec<Option<&str>> = (0..40).map(|ty| database.type_name(ty)).collect();
    assert_eq!(got, expected, "type labels");

    // Field and row labels of the tables this port reads.
    assert_eq!(database.field_name(0, 0), Some("技能の名前"), "skill name");
    assert_eq!(database.field_name(0, 1), Some("説明"), "skill help");
    assert_eq!(database.field_name(2, 0), Some("アイテム名"), "item name");
    assert_eq!(database.field_name(0, 37), None, "past the last column");
    assert_eq!(
        database.field_name(0, 2000),
        None,
        "a field id is not a column"
    );
    assert_eq!(
        database.row_name(0, 0),
        Some("通常攻撃（技能側）"),
        "empty skill row"
    );
    assert_eq!(
        database.row_name(0, 1),
        Some("--------------------"),
        "observe row"
    );
    assert_eq!(database.row_name(2, 0), Some("薬草"), "first item");
    assert_eq!(
        database.row_name(2, 4),
        Some("復活の薬"),
        "row 4 of the item table"
    );
    assert_eq!(database.row_name(0, 44), None, "past the last row");

    // In this game's DataBase companion every record keeps exactly the fields the
    // exported table has, so the editor never carries a column the .dat lacks.
    for ty in 0..40usize {
        if let Some(record) = database.names.record(ty) {
            assert_eq!(
                record.fields.len(),
                database.types[ty].fields.len(),
                "type {ty} editor/dat field count agree"
            );
        }
    }
    assert_eq!(database.type_name(40), None, "past the last type");
}

/// The same companion walk on the second database: 30 types, 1053 field labels and
/// 649 row labels, and one type where the editor keeps a field the table dropped.
#[test]
fn project_names_align_with_c_data_base() {
    let (Some(data), Some(project)) = (load("CDataBase.dat"), load("CDataBase.project")) else {
        eprintln!(
            "skipping CDataBase.project: no data under {}",
            data_root().display()
        );
        return;
    };
    let mut database = Database::parse(&data).expect("CDataBase.dat parses");
    assert_eq!(
        database.apply_project_names(&project),
        30,
        "every type found"
    );
    assert_eq!(database.names.named_types(), 24, "6 types are unnamed");
    assert_eq!(database.names.named_fields(), 1053, "field labels");
    assert_eq!(database.names.named_rows(), 649, "row labels");

    let expected: [Option<&str>; 30] = [
        Some("主人公ステータス"),
        Some("┣ 技能習得Lv"),
        Some("┣ 主人公行動AI"),
        Some("┣ 属性耐性"),
        Some("┣ 状態耐性"),
        Some("┗ 状態リスト"),
        Some("パーティー情報"),
        Some("┣所持アイテム個数"),
        Some("┣所持武器個数"),
        Some("┗所持防具個数"),
        Some("×┏ 戦闘一時ステータス[基]"),
        Some("×┣ 属性耐性計算結果"),
        Some("×┣ 状態耐性計算結果"),
        Some("×┣ 状態リスト"),
        Some("×┣ コマンド処理ﾘｽﾄ"),
        Some("×┗ お宝リスト"),
        Some("× お店一時処理用"),
        Some("×主人公一時DB"),
        Some("基本ｼｽﾃﾑ用変数"),
        Some("万能ｳｨﾝﾄﾞｳ一時DB"),
        Some("×ドロップアイテムリスト"),
        None,
        None,
        None,
        None,
        Some("追加キーコンフィグ設定"),
        Some("新設キー"),
        Some("カスタム選択肢"),
        None,
        None,
    ];
    let got: Vec<Option<&str>> = (0..30).map(|ty| database.type_name(ty)).collect();
    assert_eq!(got, expected, "type labels");

    assert_eq!(database.field_name(0, 0), Some("肩書き1"), "first field");
    assert_eq!(database.field_name(1, 0), Some("<能力>覚えるレベル"));
    assert_eq!(database.row_name(0, 0), Some("ヒーローさん"), "first hero");
    assert_eq!(database.row_name(0, 5), Some("シーフさん"), "sixth hero");
    assert_eq!(database.row_name(1, 0), None, "type 1 names no row");
    // Type 21 is the one type where the editor keeps a field the .dat dropped
    // (dat_fields=0, record_fields=1), so it can get no field label. It and the
    // other five separator types carry no type label either.
    for ty in [21usize, 22, 23, 24, 28, 29] {
        assert_eq!(database.type_name(ty), None, "type {ty} is unnamed");
    }
    assert_eq!(
        database.names.record(21).map(|record| record.fields.len()),
        Some(1),
        "type 21 keeps one field in the editor only"
    );
    assert_eq!(
        database.types[21].fields.len(),
        0,
        "type 21 has no field in the .dat"
    );
    assert_eq!(database.field_name(21, 0), None, "type 21 field label");
}

/// A companion only ever labels the database it belongs to.
#[test]
fn a_companion_for_another_database_names_nothing() {
    let (Some(data), Some(project)) = (load("DataBase.dat"), load("DataBase.project")) else {
        eprintln!(
            "skipping DataBase.project: no data under {}",
            data_root().display()
        );
        return;
    };
    let mut database = Database::parse(&data).expect("DataBase.dat parses");

    // Another game version would carry a different type count; the count is the
    // only thing tying a companion to its .dat, so it is checked first.
    let mut foreign = project.clone();
    foreign[0..4].copy_from_slice(&7u32.to_le_bytes());
    assert_eq!(
        database.apply_project_names(&foreign),
        0,
        "wrong type count"
    );
    assert_eq!(database.type_name(0), None, "no label survives a mismatch");
    assert_eq!(database.names.named_fields(), 0);

    assert_eq!(database.apply_project_names(&[]), 0, "empty companion");

    // The SysDatabase companion has the same shape but not the same type list.
    if let Some(other) = load("SysDatabase.project") {
        assert_eq!(database.apply_project_names(&other), 0, "wrong database");
        assert_eq!(database.type_name(0), None);
    }

    // And a truncated record stops the walk instead of inventing labels.
    let cut = &project[..project.len() / 2];
    let mut database = Database::parse(&data).expect("DataBase.dat parses");
    let partial = database.apply_project_names(cut);
    assert!(
        partial < 40,
        "a truncated companion claims fewer types: {partial}"
    );
    assert_eq!(
        database.type_name(0),
        Some("技能"),
        "the first record still reads"
    );
}
