//! Loading a WOLF save file into the live game state.
//!
//! The save layout facts this module relies on were measured against the nine retail
//! saves shipped with this game (see docs/SAVE_SPEC.md §10):
//!
//! * \`SavePart3.row_words\` row 0 is the 800 normal variables (\`2000000+n\`).
//! * \`SavePart2.vars3_21[0]\` is the playtime in frames.
//! * \`SavePart2.vars3_21[9]/[10]\` are Sys3/Sys4, the choice-window anchor.
//! * \`SavePart5.events\` is the PICTURE table: \`var1\` is the picture number and every
//!   field needed to redraw the slot is present. That is what makes a loaded save look
//!   like the frame the player saved on instead of an empty screen.
//!
//! The one part that is not a plain copy is the text of a text picture: \`md1\` stores
//! it as a byte stream where \`01 <len> <len-1 bytes>\` is a style escape. Only the
//! escapes this game's save files actually contain are decoded (see [decode_picture_text]).

use std::path::Path;

use wolf_format::mps::Map;
use wolf_format::tileset::TileSet;
use wolf_save::part1::SavePart1_1_1;
use wolf_save::part5::{SavePart5, SavePart5_1};
use wolf_save::{SaveFile, SavePart1, SavePart1_1};

use crate::game::Game;
use crate::picture::{Picture, PictureKind, Screen};

/// What a load restored, for the CLI to print and tests to assert.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct LoadedSave {
    /// Pictures rebuilt from \`SavePart5\`.
    pub pictures: usize,
    /// Normal variables copied out of \`SavePart3\` row 0.
    pub normal_vars: usize,
    /// Normal string variables copied out of \`SavePart3.mds1\`.
    pub normal_strings: usize,
    /// Playtime in frames, from \`SavePart2.vars3_21[0]\`.
    pub playtime_frames: u32,
    /// Choice-window anchor from \`SavePart2.vars3_21[9]/[10]\`.
    pub choice_anchor: (i32, i32),
}

/// Reads and decrypts one save file.
pub fn read_save(path: &Path) -> Result<SaveFile, String> {
    let bytes =
        std::fs::read(path).map_err(|err| format!("cannot read {}: {err}", path.display()))?;
    SaveFile::parse(&bytes).map_err(|err| format!("cannot parse {}: {err}", path.display()))
}

/// Encrypts and writes one save file, creating `Save/` when needed.
pub fn write_save(path: &Path, save: &SaveFile) -> Result<(), String> {
    if let Some(parent) = path.parent() {
        std::fs::create_dir_all(parent)
            .map_err(|err| format!("cannot create {}: {err}", parent.display()))?;
    }
    let bytes = save
        .to_bytes()
        .map_err(|err| format!("cannot encode {}: {err}", path.display()))?;
    std::fs::write(path, bytes).map_err(|err| format!("cannot write {}: {err}", path.display()))
}

/// A `220` request that needs the whole `Game`, not just its picture layer.
///
/// The interpreter borrows `Game` field by field while it runs, so a full save
/// load is queued here and applied by [`crate::game::Game::frame`] immediately
/// after the VM step that asked for it.
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum SaveRequest {
    /// Load the given file into the live game.
    Load(std::path::PathBuf),
    /// Write the live game state to the given file.
    Save(std::path::PathBuf),
}

/// Parses \`path\` and applies it to \`game\`.
pub fn load_into(game: &mut Game, path: &Path) -> Result<LoadedSave, String> {
    let bytes =
        std::fs::read(path).map_err(|err| format!("cannot read {}: {err}", path.display()))?;
    let save =
        SaveFile::parse(&bytes).map_err(|err| format!("cannot parse {}: {err}", path.display()))?;
    // A load starts a different conversation; the M5-F transcript belongs to the scene
    // the player was in, not to the variables the save replaces.
    game.clear_message_history();
    Ok(apply(game, &save))
}

/// Applies an already parsed save. Kept separate so tests can build a \`SaveFile\` in memory.
pub fn apply(game: &mut Game, save: &SaveFile) -> LoadedSave {
    let mut loaded = LoadedSave::default();

    // Keep the save we loaded from as the template for the next save_to: it carries the
    // full runtime variable database (vardb, ~84 KB in SaveData01) plus the current map
    // snapshot / object tables. Without this, save_to would rebuild from System.sav and
    // drop the whole vardb overlay, drifting every runtime-250 database cell on reload.
    game.base_save = Some(save.clone());

    // Normal variables: Part3 row 0 is the block for 2000000+n. Use the row-span API
    // (SavePart3::normal_var) rather than the flattened row_words run: row_words packs
    // every row back to back, so walking it would spill the first words of rows 1..N
    // into variable indices past row 0's length. The engine's Variables bank stores
    // normal variables at index 0, not at the 2_000_000 magic base.
    let mut index = 0;
    while let Some(value) = save.part3.normal_var(index) {
        game.vm.vars.set(index, value);
        index += 1;
    }
    loaded.normal_vars = index;

    // Normal string variables live in SavePart3.mds1: the retail saves carry ten of
    // them (the first is the hero's display name after character creation, the last
    // the save-thumbnail path). They were never loaded, so a saved name reverted to
    // whatever the live variable happened to hold.
    for (index, body) in save.part3.mds1.iter().enumerate() {
        let (text, _bad) = wolf_format::gbk::decode(strip_nul(body));
        game.vm.vars.set_str(index, &text);
    }
    loaded.normal_strings = save.part3.mds1.len();

    // Common-event self variables are owned by the event, not by a coroutine. Every
    // shipped save stores 100 numeric slots and 5 string slots for all 350 events.
    game.vm.vars.common_self.clear();
    let events = save
        .part3
        .list_counts
        .len()
        .max(save.part3.slot_counts.len());
    for event in 0..events {
        let event = event as u32;
        let mut bank = wolf_vm::vars::EventSelfVars::new();
        for slot in 0..wolf_vm::vars::EVENT_SELF_SLOTS {
            if let Some(value) = save.part3.self_var(event, slot) {
                bank.set(slot, value);
            }
        }
        for slot in 0..wolf_vm::vars::EVENT_SELF_STRINGS {
            if let Some(body) = save.part3.self_string_bytes(event, slot) {
                let (text, _bad) = wolf_format::gbk::decode(strip_nul(body));
                bank.set_str(slot, &text);
            }
        }
        game.vm.vars.common_self.insert(event, bank);
    }
    // Running engine/menu coroutines predate the load; give them the restored banks
    // too, so their eventual end cannot write stale values back over the save.
    game.vm.restore_common_self();

    // The variable database travels inside the save. Character creation writes the
    // player name into CDataBase type 0 row 12, and the HUD reads it back through
    // opcode 250, so a load must overlay it before the first frame is drawn.
    game.databases.apply_saved_database(&save.vardb);

    // Choice-window anchor. Sys3/Sys4 are absolute screen pixels (docs/OPCODE_102.md §4.2).
    let sys3 = save.part2.vars3_21.get(9).copied().unwrap_or(512) as i32;
    let sys4 = save.part2.vars3_21.get(10).copied().unwrap_or(240) as i32;
    game.vm.vars.set_sys(3, sys3);
    game.vm.vars.set_sys(4, sys4);
    loaded.choice_anchor = (sys3, sys4);

    // Playtime is the first word of SavePart2's variable tail.
    loaded.playtime_frames = save.part2.vars3_21.first().copied().unwrap_or(0);
    game.set_playtime_frames(loaded.playtime_frames);
    // The static-random cursor has no field in the shipped .sav. Restarting it at
    // entry 0 on every load made every replay of a save draw the same sequence
    // (report II.1); derive the position from playtime instead, which is stable
    // for one save and different across saves without changing the save layout.
    game.vm.rng.set_cursor(loaded.playtime_frames as usize);

    // The running BGM is part of the save. Restore it before the picture layer so the
    // first frame after a load already has the right track (and so a script that only
    // tweaks the volume keeps playing instead of restarting silence).
    game.current_bgm = save.part2.bgm.as_ref().and_then(|bgm| {
        let (path, _bad) = wolf_format::gbk::decode(strip_nul(&bgm.path1));
        if path.is_empty() {
            None
        } else {
            Some((path, bgm.vars75_77[0] as i32))
        }
    });
    if let Some((file, volume)) = game.current_bgm.clone() {
        if let Some(audio) = game.audio.as_mut() {
            let gain = (volume.clamp(0, 100) as f32) / 100.0;
            let _ = audio.play_bgm_with_fade(&file, true, gain, 0);
        }
        game.pending_sounds.push(wolf_vm::SoundCmd {
            channel: wolf_vm::SoundChannel::Bgm,
            action: wolf_vm::SoundAction::Play,
            file,
            volume,
            frames: 0,
            pitch: 100,
        });
    } else {
        if let Some(audio) = game.audio.as_mut() {
            audio.stop_bgm(0);
        }
        game.pending_sounds.push(wolf_vm::SoundCmd {
            channel: wolf_vm::SoundChannel::Bgm,
            action: wolf_vm::SoundAction::Stop,
            file: String::new(),
            volume: 0,
            frames: 0,
            pitch: 100,
        });
    }

    // Rebuild the picture layer. The save stores every live slot, including hidden ones
    // and whole-screen layers with negative numbers, so a wholesale replacement is right.
    game.screen.clear();
    for record in &save.part5.events {
        if let Some(picture) = picture_from_record(record) {
            game.screen.insert(picture);
        }
    }
    loaded.pictures = game.screen.len();

    loaded
}

/// Rebuilds one picture from its \`SavePart5_1\` record, or \`None\` for an empty slot.
#[must_use]
pub fn picture_from_record(record: &SavePart5_1) -> Option<Picture> {
    let number = record.var1 as i32;
    let name = {
        // File / window names are ASCII paths in every shipped save, but the Chinese
        // fan translation stores display strings in GBK, so decode defensively.
        let (decoded, _bad) = wolf_format::gbk::decode(strip_nul(&record.md1));
        decoded
    };
    let mut picture = Picture::new(number);

    // var5 is the text flag and var6 the window flag in every record of all nine saves.
    if record.var5 == 1 {
        picture.kind = PictureKind::Text;
        picture.text = decode_picture_text(&record.md1);
        // Keep the stream the text came from. Retail saves contain escape spellings
        // the canonical encoder does not emit (`01 02 20`, two spellings of a font
        // size), so an untouched picture must be written back verbatim; see
        // picture_to_record.
        picture.retained_text = Some((picture.text.clone(), record.md1.clone()));
    } else {
        // A FileString / WindowString picture takes its name from a string variable;
        // when that variable is empty the record carries an empty name. Keep the
        // record anyway: it is an invisible slot, but dropping it would change the
        // live picture count on a save/load round trip. The renderer skips an empty
        // file, and a window with an empty name falls back to the engine skin.
        picture.kind = if record.var6 == 1 {
            PictureKind::WindowFile
        } else {
            PictureKind::File
        };
        picture.file = name;
    }

    let v = &record.vars7_18;
    picture.x = v[0] as i32;
    picture.y = v[1] as i32;
    picture.opacity = v[5] as i32;
    picture.blend = v[6] as i32;
    // [8] is how long the last fade-in took, not a fade still in progress. A loaded
    // picture must appear at full strength on the first frame (retail Save/save1.jpg
    // shows the policy panel at 100%, while its record still carries fade = 10).
    picture.fade = 0;
    // [9]/[10] are the horizontal/vertical scale in percent. They are equal for a
    // uniform draw, but the HUD action-bar fill stores (62, 100): the width follows
    // the percentage while the height stays full. A zero scale is a real hidden
    // picture (the fill is stored as 0 when empty), not a missing field.
    picture.scale = v[9] as i32;
    picture.scale_y = v[10] as i32;
    let w = v[2] as i32;
    let h = v[3] as i32;
    if record.var6 == 1 {
        if w > 1 && h > 1 {
            picture.window = Some((w, h));
        }
    } else if record.var5 != 1 {
        // For a file picture the same two words are the sprite-sheet grid: a standing
        // character is one PNG holding a whole wardrobe (6 x 2 for stand_imouto_paja2),
        // and [4] is the one-based cell to show. Retail save 92's 7 x 1 eye strip with
        // pattern 7 is what proves the count starts at one.
        let columns = u32::try_from(w).unwrap_or(1).max(1);
        let rows = u32::try_from(h).unwrap_or(1).max(1);
        picture.split = (columns, rows);
        picture.pattern_index = u32::try_from(v[4]).unwrap_or(1).max(1);
    }
    picture.anchor = record.var4 as u8;

    // Keep the whole record as well as the decoded fields. `Picture` cannot represent
    // var2/var3, vals1, vars19_36, the trailing tables and the unused scale words, so an
    // untouched picture has to be written back from the original record; see
    // picture_to_record.
    picture.retained_record = Some(record.clone());

    Some(picture)
}

/// Builds the save record for one live picture.
///
/// This is the inverse of [`picture_from_record`]. It only has to cover the fields the
/// save format actually stores: the picture number, kind flags, name/text, position,
/// sprite-sheet grid, scale, opacity, blend, anchor and the last fade length.
///
/// A picture that came from a save and has not been repainted is written back from the
/// record it was decoded from (see [`Picture::retained_record`]). The canonical encoder
/// below only knows the geometry the renderer uses, while a retail record also carries
/// script state - `var2`/`var3`, `vals1`, `vars19_36`, the per-kind trailing tables,
/// `vars55_60`, `vars61_63`, the unused `vars7_18[7]`, the last fade length in
/// `vars7_18[8]`, the second scale word `vars7_18[10]` and the reserved word `[11]`.
/// Those cannot be reconstructed, so an unchanged picture hands the original record
/// back verbatim. Reuse is decided by comparing canonical records, so as soon as any
/// field the encoder owns changes, the canonical record differs and the encoder below
/// is used instead: an edited picture never inherits stale numeric state.
#[must_use]
pub fn picture_to_record(picture: &Picture) -> SavePart5_1 {
    if let Some(retained) = &picture.retained_record {
        let canonical = canonical_record(picture);
        // The baseline is what the canonical encoder would have written for the picture
        // this record decoded to. Recomputing it (rather than storing it beside the
        // record) keeps `Picture` compact and guarantees both sides use one encoder.
        if let Some(loaded) = picture_from_record(retained) {
            if canonical_record(&loaded) == canonical {
                return retained.clone();
            }
        }
        return canonical;
    }
    canonical_record(picture)
}

/// The record the canonical encoder produces from the live fields alone.
fn canonical_record(picture: &Picture) -> SavePart5_1 {
    let mut record = SavePart5_1::default();
    record.var1 = picture.number as u32;
    record.var4 = u16::from(picture.anchor);
    record.var5 = u8::from(picture.kind.is_text());
    record.var6 = u8::from(picture.kind.is_window());
    record.md1 = if picture.kind.is_text() {
        // A picture loaded from a save keeps its original byte stream while the text is
        // untouched. The encoder below only covers the canonical spellings; the shipped
        // saves also use `01 02 20` control escapes and a second font-size form, and a
        // load -> save must not rewrite them.
        match &picture.retained_text {
            Some((text, raw)) if *text == picture.text => raw.clone(),
            _ => encode_picture_text(&picture.text),
        }
    } else {
        let mut bytes = picture.file.as_bytes().to_vec();
        bytes.push(0);
        bytes
    };

    let v = &mut record.vars7_18;
    v[0] = picture.x as u32;
    v[1] = picture.y as u32;
    let (columns, rows) = match picture.window {
        Some((width, height)) => (width, height),
        None => (
            i32::try_from(picture.split.0).unwrap_or(1),
            i32::try_from(picture.split.1).unwrap_or(1),
        ),
    };
    v[2] = columns.max(0) as u32;
    v[3] = rows.max(0) as u32;
    v[4] = picture.pattern_index;
    v[5] = picture.opacity as u32;
    v[6] = picture.blend as u32;
    v[7] = u32::MAX;
    v[8] = picture.fade;
    // Keep the sign: retail SaveData08 stores window pictures 1996/1998 with a
    // horizontal scale of -100 (a sentinel the renderer clamps, but the save must
    // reproduce byte-for-byte on a load -> save round trip). Clamping to 0 here used
    // to silently rewrite -100 as 0.
    v[9] = picture.scale as u32;
    v[10] = picture.scale_y as u32;
    v[11] = 0;
    record
}

/// Builds a whole `SavePart5` from the live picture layer, in draw order.
#[must_use]
pub fn part5_from_screen(screen: &Screen) -> SavePart5 {
    let events: Vec<SavePart5_1> = screen.iter().map(picture_to_record).collect();
    SavePart5 {
        var1: u16::try_from(events.len()).unwrap_or(0x7fff),
        events,
    }
}

/// Encodes a text picture back into the `md1` style stream.
///
/// The inverse of [`decode_picture_text`] for the escapes the retail saves use:
/// `\E` (outline), `\f[n]` (font size) and `\c[n]` (palette index). Other escapes are
/// left literal, which is harmless: the save is a snapshot of already-expanded text.
/// Plain text is written as GBK, matching how the Chinese fan translation stores it.
#[must_use]
pub fn encode_picture_text(text: &str) -> Vec<u8> {
    let chars: Vec<char> = text.chars().collect();
    let mut out = Vec::new();
    let mut pending = String::new();
    let mut index = 0;
    while index < chars.len() {
        if chars[index] == '\\' {
            if let Some((consumed, bytes)) = encode_escape(&chars[index..]) {
                if !pending.is_empty() {
                    // The Chinese fan translation stores display strings in GBK.
                    out.extend_from_slice(&wolf_format::gbk::encode(&pending));
                    pending.clear();
                }
                out.extend_from_slice(&bytes);
                index += consumed;
                continue;
            }
        }
        pending.push(chars[index]);
        index += 1;
    }
    if !pending.is_empty() {
        out.extend_from_slice(&wolf_format::gbk::encode(&pending));
    }
    out.push(0);
    out
}

fn encode_escape(chars: &[char]) -> Option<(usize, Vec<u8>)> {
    if chars.get(1) == Some(&'E') {
        return Some((2, vec![1, 2, 5]));
    }
    let kind = *chars.get(1)?;
    if (kind == 'f' || kind == 'c') && chars.get(2) == Some(&'[') {
        let mut end = 3;
        let mut value: i32 = 0;
        while let Some(digit) = chars.get(end).and_then(|ch| ch.to_digit(10)) {
            value = value.saturating_mul(10).saturating_add(digit as i32);
            end += 1;
        }
        if end == 3 || chars.get(end) != Some(&']') {
            return None;
        }
        let code = if kind == 'c' && value == 0 {
            0x0f
        } else {
            value + 14
        };
        if !(1..=255).contains(&code) {
            return None;
        }
        let bytes = if kind == 'f' {
            vec![1, 5, 3, 0x0e, code as u8, 1]
        } else {
            vec![1, 6, 2, 0x0e, 0x0e, code as u8, 1]
        };
        return Some((end + 1, bytes));
    }
    None
}

/// Decodes the picture-string byte stream stored in \`SavePart5_1::md1\`.
///
/// The stream is GBK text interleaved with \`0x01 <total_len> <payload>\` escapes.
/// The four escapes that occur in the retail saves decode as:
///
/// * \`01 02 05\` - \`\E\` (outline on).
/// * \`01 04 12 1d 36\` - a combined font/spacing escape; only the font part is kept.
/// * \`01 05 03 0e 26 01\` - font, where byte 3 is \`size + 14\` (\`0x26 = 38 -> 24 px\`).
/// * \`01 06 02 0e 0e 17 01\` - colour; byte 4 is \`index + 14\` (\`0x17 = 23 -> \c[9]\`).
#[must_use]
pub fn decode_picture_text(bytes: &[u8]) -> String {
    let mut out = String::new();
    let mut i = 0;
    while i < bytes.len() {
        let byte = bytes[i];
        if byte == 0 {
            break;
        }
        if byte != 1 {
            // The Chinese fan translation stores display strings in GBK, so gather
            // the whole text run up to the next 0x01 escape / 0x00 terminator and
            // decode it as GBK. GBK trailing bytes never fall in 0x00..=0x01, so the
            // delimiters are unambiguous.
            let start = i;
            while i < bytes.len() && bytes[i] != 0 && bytes[i] != 1 {
                i += 1;
            }
            let (text, _bad) = wolf_format::gbk::decode(&bytes[start..i]);
            out.push_str(&text);
            continue;
        }
        if i + 2 > bytes.len() {
            break;
        }
        let total = bytes[i + 1] as usize;
        if total < 2 || i + 1 + total > bytes.len() {
            i += 2;
            continue;
        }
        let payload = &bytes[i + 2..i + 1 + total];
        match total {
            2 => {
                if payload.first() == Some(&5) {
                    out.push_str("\\E");
                }
            }
            4 => {
                if let Some(code) = payload.first() {
                    let size = *code as i32 - 10;
                    if (1..=96).contains(&size) {
                        out.push_str(&format!("\\f[{size}]"));
                    }
                }
            }
            5 => {
                if let Some(code) = payload.get(2) {
                    let size = *code as i32 - 14;
                    if (1..=96).contains(&size) {
                        out.push_str(&format!("\\f[{size}]"));
                    }
                }
            }
            6 => {
                if payload.first() == Some(&2) {
                    if let Some(code) = payload.get(3) {
                        let index = if *code == 0x0f { 0 } else { *code as i32 - 14 };
                        if (0..=30).contains(&index) {
                            out.push_str(&format!("\\c[{index}]"));
                        }
                    }
                }
            }
            _ => {}
        }
        i += 1 + total;
    }
    out
}

pub(crate) fn strip_nul(bytes: &[u8]) -> &[u8] {
    match bytes.last() {
        Some(0) => &bytes[..bytes.len() - 1],
        _ => bytes,
    }
}

/// Builds the `SavePart1` map snapshot for a session that has no retail map template.
///
/// The template `Save/System.sav` carries no map, so a save written before the player
/// loads an existing file used to store zero objects and `resume_loaded_map` rejected it
/// with "the save carries no map event objects". This fills the snapshot from the map
/// currently installed by [`crate::game::Game::install_map`]: the three tile layers, the
/// tileset's chip image and automatic tile names, and one object per map event.
///
/// `var1` (event id) is the load-bearing field for this port's resume path:
/// `resume_loaded_map` matches the object ids against the map and `start_pages_loaded`
/// re-selects pages from the restored variables. The object does **not** store the
/// current page: retail saves carry `var2 = event.x * 2`, `var3 = event.y * 2`, an empty
/// page table and only the event's page-0 direction/opacity. Measured against
/// SaveData01/SaveData02: all 35 objects match the map's 35 events and coordinates
/// (2x tiles), `map_tiles` matches all 6,912 words, and `vars2_new` is the tileset's
/// passability word list (2,360 entries), not a switch table.
#[must_use]
pub fn part1_from_map(map: &Map, tileset: Option<&TileSet>, file_version: u16) -> SavePart1 {
    let auto_count = match file_version {
        value if value >= 0x8A => 31,
        value if value >= 0x73 => 15,
        _ => 7,
    };
    let mut auto_tiles: Vec<Vec<u8>> = tileset
        .map(|set| {
            set.raw_autotile_bytes
                .iter()
                .map(|raw| {
                    let mut bytes = raw.clone();
                    bytes.push(0);
                    bytes
                })
                .collect()
        })
        .unwrap_or_default();
    auto_tiles.resize(auto_count, vec![0]);
    auto_tiles.truncate(auto_count);

    let chip_image = tileset.map_or_else(Vec::new, |set| {
        let mut bytes = set.base_image.as_bytes().to_vec();
        if !bytes.ends_with(&[0]) {
            bytes.push(0);
        }
        bytes
    });

    let map_tiles = if map.has_tile_data {
        map.layers
            .iter()
            .flat_map(|layer| layer.iter().copied())
            .collect()
    } else {
        Vec::new()
    };

    let vars2_new = tileset.map_or_else(Vec::new, |set| {
        set.passability.iter().map(|word| word.raw).collect()
    });

    let objects = map
        .events
        .iter()
        .map(|event| {
            let first_page = event.pages.first();
            let chip_id = first_page.map_or(u32::MAX, |page| page.graphic_chip_id);
            let mut graphic =
                first_page.map_or_else(Vec::new, |page| page.graphic.as_bytes().to_vec());
            if !graphic.ends_with(&[0]) {
                graphic.push(0);
            }
            SavePart1_1 {
                var1: event.id,
                // Retail stores the position in half-tile units.
                var2: event.x.saturating_mul(2),
                var3: event.y.saturating_mul(2),
                var4: 0,
                var5: 0,
                var6: chip_id,
                md1: graphic,
                var7: u16::from(first_page.map_or(255, |page| page.opacity)),
                var8: 0,
                var9: u16::from(first_page.map_or(0, |page| page.direction)),
                var10: 1,
                var11: 0,
                var12: 1,
                sp1: empty_page_table(),
                sp2: empty_page_table(),
                var13: 0,
                var14: 3,
                var15: 3,
                var16: 3,
                var17: 0,
                var18: 0,
                var19: 0,
                var20: 0,
                var21: 0,
                vars1: Vec::new(),
                var23: 1,
                var24: 1,
                var25: 0,
                var26: 0,
                var27: 0,
                var28: 0,
                var29: 1,
                var30: 0,
                var31: 0,
                var32: 0,
                mds1: Vec::new(),
                var34: 0,
                var35: 0,
                var36: 0,
                var37: 0,
                var38: 0,
                var39: 0,
            }
        })
        .collect();

    SavePart1 {
        var1: 1,
        var2: 0,
        var3: 0,
        map_width: map.width,
        map_height: map.height,
        map_tiles,
        chip_image,
        auto_tiles,
        vars2_new,
        vars2_old: Vec::new(),
        objects,
        tail_vars: vec![0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 100],
        vars3: Vec::new(),
    }
}

fn empty_page_table() -> SavePart1_1_1 {
    SavePart1_1_1 {
        head: [3, 3, 3, 0, 3, 2],
        count: 0,
        items: Vec::new(),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn a_text_picture_round_trips_through_its_save_record() {
        let mut picture = Picture::new(6200);
        picture.kind = PictureKind::Text;
        picture.text = "\\E\\f[24]\\c[9]21:40".to_owned();
        picture.x = 140;
        picture.y = 7;
        picture.anchor = 3;
        picture.opacity = 255;
        let record = picture_to_record(&picture);
        assert_eq!(decode_picture_text(&record.md1), picture.text);
        assert_eq!(record.var5, 1);
        assert_eq!(record.var4, 3);
        let restored = picture_from_record(&record).expect("text record");
        assert_eq!(restored.text, picture.text);
        assert_eq!(restored.x, 140);
        assert_eq!(restored.y, 7);
        assert_eq!(restored.anchor, 3);
    }

    #[test]
    fn a_file_picture_keeps_its_sprite_grid_in_the_record() {
        let mut picture = Picture::new(90);
        picture.file = "Picture/stand_imouto_paja2.png".to_owned();
        picture.split = (6, 2);
        picture.pattern_index = 2;
        picture.window = None;
        let record = picture_to_record(&picture);
        assert_eq!(record.vars7_18[2], 6);
        assert_eq!(record.vars7_18[3], 2);
        assert_eq!(record.vars7_18[4], 2);
        let restored = picture_from_record(&record).expect("file record");
        assert_eq!(restored.file, picture.file);
        assert_eq!(restored.split, (6, 2));
        assert_eq!(restored.pattern_index, 2);
    }

    #[test]
    fn a_saved_text_picture_decodes_its_font_sizes() {
        // The exact bytes SaveData01 stores for picture 6200, whose live text is \f[24]21:40.
        let bytes = [
            0x01, 0x05, 0x03, 0x0e, 0x26, 0x01, b'2', b'1', b':', b'4', b'0', 0x00,
        ];
        assert_eq!(decode_picture_text(&bytes), "\\f[24]21:40");
    }

    #[test]
    fn a_saved_text_picture_decodes_colour_outline_and_multiple_runs() {
        // SaveData01 picture 6210: \c[0] \f[18] 周六 (stored as GBK D6DC D2BB).
        let bytes = [
            0x01, 0x06, 0x02, 0x0e, 0x0e, 0x0f, 0x01, 0x01, 0x05, 0x03, 0x0e, 0x20, 0x01, 0xd6,
            0xdc, 0xc1, 0xf9, 0x00,
        ];
        assert_eq!(decode_picture_text(&bytes), "\\c[0]\\f[18]周六");
    }

    #[test]
    fn every_retail_text_picture_survives_re_encoding() {
        let mut path = std::path::PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        path.pop();
        path.pop();
        path.push("work");
        path.push("Data");
        path.push("Save");
        path.push("SaveData01.sav");
        let Ok(save) = read_save(&path) else { return };
        let mut checked = 0;
        for record in &save.part5.events {
            if record.var5 != 1 {
                continue;
            }
            let text = decode_picture_text(&record.md1);
            let reencoded = encode_picture_text(&text);
            // Escape 04 is a font-plus-letter-spacing variant; it decodes to the same
            // [n] text and re-encodes as the plain 05 font, so compare decoded text.
            assert_eq!(
                decode_picture_text(&reencoded),
                text,
                "picture {}",
                record.var1
            );
            checked += 1;
        }
        assert!(checked > 20, "checked {checked} text records");
    }

    #[test]
    fn a_negative_horizontal_scale_survives_a_save_round_trip() {
        // Retail SaveData08 pictures 1996/1998 store scale[0] = -100 as u32. The renderer
        // clamps it to 0, but the record must be reproduced exactly on save.
        let record = SavePart5_1 {
            var1: 1996,
            var4: 0,
            var5: 0,
            var6: 1,
            vars7_18: [
                492,
                57,
                215,
                6,
                1,
                128,
                0,
                u32::MAX,
                1,
                (-100i32) as u32,
                100,
                0,
            ],
            md1: b"<SQUARE>\0".to_vec(),
            ..SavePart5_1::default()
        };
        let picture = picture_from_record(&record).expect("a window picture");
        assert_eq!(picture.scale, -100);
        let written = picture_to_record(&picture);
        assert_eq!(
            written.vars7_18[9],
            (-100i32) as u32,
            "negative scale must be kept"
        );
    }

    #[test]
    fn a_saved_picture_keeps_its_window_box_scale_and_anchor() {
        let record = SavePart5_1 {
            var1: 6233,
            var4: 0,
            var5: 0,
            var6: 1,
            vars7_18: [480, 15, 150, 14, 1, 255, 0, u32::MAX, 1, 62, 100, 0],
            md1: b"<SQUARE>\0".to_vec(),
            ..SavePart5_1::default()
        };
        let picture = picture_from_record(&record).expect("a window picture");
        assert_eq!(picture.kind, PictureKind::WindowFile);
        assert_eq!(picture.file, "<SQUARE>");
        assert_eq!(picture.window, Some((150, 14)));
        assert_eq!(picture.scale, 62);
    }
}
