//! A save written by a fresh session must carry the SavePart1 map snapshot.
//!
//! Regression for the gap found while wiring the Godot front-end: `System.sav` has no
//! map, so `save_to` used to write zero objects and `resume_loaded_map` rejected the
//! file with "the save carries no map event objects". The writer now fills Part1 from
//! the installed map; this test pins the object table and the resume path.

use std::path::PathBuf;

use wolf_format::tileset::TileSetData;
use wolf_game::Game;

fn data_root() -> Option<PathBuf> {
    let root = PathBuf::from(std::env::var_os("WOLF_DATA_ROOT")?);
    root.join("BasicData").is_dir().then_some(root)
}

#[test]
fn a_new_game_save_carries_the_map_snapshot_and_resumes() {
    let Some(root) = data_root() else {
        eprintln!("skipping: WOLF_DATA_ROOT is not set to an unpacked data root");
        return;
    };

    let mut game = Game::new(&root).expect("open the data root");
    game.auto_advance = true;
    game.auto_choice = true;
    game.auto_choice_delay = 0;
    game.start_title().expect("start common event 42");
    for _ in 0..600 {
        game.frame();
    }
    let map = game
        .current_map
        .as_ref()
        .expect("the new-game path installed SampleMapA")
        .clone();
    assert_eq!(
        map.width, 64,
        "the new-game path should end on SampleMapA (64x36)"
    );

    let out_dir = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../work/out");
    std::fs::create_dir_all(&out_dir).expect("create work/out");
    let out = out_dir.join("m3_save_newgame_part1.sav");
    game.save_to(&out).expect("save the new game");
    let save = wolf_game::savegame::read_save(&out).expect("read the save back");

    assert_eq!(save.part1.map_width, map.width);
    assert_eq!(save.part1.map_height, map.height);
    assert_eq!(
        save.part1.map_tiles.len(),
        (map.width * map.height * 3) as usize,
        "three tile layers must be stored"
    );
    assert_eq!(
        save.part1.objects.len(),
        map.events.len(),
        "one Part1 object per map event"
    );
    let mut saved_ids: Vec<u32> = save
        .part1
        .objects
        .iter()
        .map(|object| object.var1)
        .collect();
    let mut map_ids: Vec<u32> = map.events.iter().map(|event| event.id).collect();
    saved_ids.sort_unstable();
    map_ids.sort_unstable();
    assert_eq!(saved_ids, map_ids, "Part1 object ids must match the map");

    // Retail evidence (SaveData01/02): var2/var3 are the event position in half-tile
    // units, not a page index; page state is not stored in Part1 at all.
    for event in &map.events {
        let object = save
            .part1
            .objects
            .iter()
            .find(|object| object.var1 == event.id)
            .expect("one object per event");
        assert_eq!(object.var2, event.x * 2, "event {id} x*2", id = event.id);
        assert_eq!(object.var3, event.y * 2, "event {id} y*2", id = event.id);
    }

    // The tileset fields are a straight copy of the installed tileset, not defaults.
    let tileset_bytes = std::fs::read(root.join("BasicData").join("TileSetData.dat"))
        .expect("read TileSetData.dat");
    let tilesets = TileSetData::parse(&tileset_bytes).expect("parse TileSetData.dat");
    let tileset = tilesets.get(map.tileset_index).expect("map tileset");
    assert_eq!(
        save.part1.vars2_new,
        tileset
            .passability
            .iter()
            .map(|word| word.raw)
            .collect::<Vec<_>>(),
        "vars2_new is the tileset passability table"
    );
    let expected_auto_tiles = if save.file_version >= 0x8A { 31 } else { 15 };
    assert_eq!(save.part1.auto_tiles.len(), expected_auto_tiles);
    for (stored, raw) in save
        .part1
        .auto_tiles
        .iter()
        .zip(&tileset.raw_autotile_bytes)
    {
        let mut expected = raw.clone();
        expected.push(0);
        assert_eq!(*stored, expected);
    }
    let mut expected_chip = tileset.base_image.as_bytes().to_vec();
    expected_chip.push(0);
    assert_eq!(save.part1.chip_image, expected_chip);

    // Static-field diff against the shipped SampleMapA save. Runtime fields
    // (var10/12/15/16/19/21/23/24 and the page-table head noise) are deliberately
    // excluded: retail saves differ there from frame to frame.
    let retail_path = root.join("Save").join("SaveData01.sav");
    if retail_path.is_file() {
        let retail = wolf_game::savegame::read_save(&retail_path).expect("read retail save");
        if retail.part1.map_width == map.width
            && retail.part1.map_height == map.height
            && retail.part1.objects.len() == map.events.len()
        {
            assert_eq!(save.part1.map_tiles, retail.part1.map_tiles);
            assert_eq!(save.part1.chip_image, retail.part1.chip_image);
            assert_eq!(save.part1.auto_tiles, retail.part1.auto_tiles);
            assert_eq!(save.part1.vars2_new, retail.part1.vars2_new);
            assert_eq!(save.part1.tail_vars, retail.part1.tail_vars);
            for ours in &save.part1.objects {
                let theirs = retail
                    .part1
                    .objects
                    .iter()
                    .find(|object| object.var1 == ours.var1)
                    .expect("the retail save has the same event");
                assert_eq!(ours.var1, theirs.var1);
                assert_eq!(ours.var2, theirs.var2);
                assert_eq!(ours.var3, theirs.var3);
                assert_eq!(ours.var4, theirs.var4);
                assert_eq!(ours.var5, theirs.var5);
                assert_eq!(ours.var6, theirs.var6);
                assert_eq!(ours.md1, theirs.md1);
                assert_eq!(ours.var7, theirs.var7);
                assert_eq!(ours.var8, theirs.var8);
                assert_eq!(ours.var9, theirs.var9);
                assert_eq!(ours.var11, theirs.var11);
                assert_eq!(ours.var13, theirs.var13);
                assert_eq!(ours.var14, theirs.var14);
                assert_eq!(ours.var17, theirs.var17);
                assert_eq!(ours.var18, theirs.var18);
                assert_eq!(ours.var20, theirs.var20);
                assert_eq!(ours.vars1, theirs.vars1);
                assert_eq!(ours.var25, theirs.var25);
                assert_eq!(ours.var26, theirs.var26);
                assert_eq!(ours.var27, theirs.var27);
                assert_eq!(ours.var28, theirs.var28);
                assert_eq!(ours.var29, theirs.var29);
                assert_eq!(ours.var30, theirs.var30);
                assert_eq!(ours.var31, theirs.var31);
                assert_eq!(ours.var32, theirs.var32);
            }
        } else {
            eprintln!("skip retail Part1 diff: SaveData01 is not SampleMapA");
        }
    }

    let mut loaded = Game::new(&root).expect("open a second session");
    loaded.prime_engine();
    loaded.load_save(&out).expect("load the written save");
    let resumed = loaded.resume_loaded_map().expect("resume the saved map");
    assert_eq!(resumed, "SampleMapA");
    for _ in 0..10 {
        loaded.frame();
    }
    assert!(
        !loaded.screen.is_empty(),
        "the resumed session must restore the picture layer"
    );

    let _ = std::fs::remove_file(&out);
}
