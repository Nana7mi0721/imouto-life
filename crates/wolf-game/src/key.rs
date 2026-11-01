//! WOLF key input as opcode 123 sees it.
//!
//! HISTORY. The first model here (H-KEY-1) assumed `123` stored `key_bits & mask`,
//! a bitmask of the held keys, with bits 0..3 as the action keys and 4..7 as the
//! directions. That model is wrong - it can never match the constants the game
//! compares against - and it was replaced by a KEY CODE model (H-KEY-2). The
//! evidence comes from the developers' own 103 debug comments inside this game:
//!
//! * Common event 108 pc27 polls and tests `== 10`, `== 11`, `== 2`; the three
//!   branch bodies are commented 決定キー (decide), キャンセルキー (cancel) and
//!   下キー (down key), and the else branch re-tests `== 8` under 上キー (up key).
//! * Event 65 pc83 polls and tests `== 4` / `== 6` inside a body commented
//!   左右キーを押したら終了する場合 (ends when left or right is pressed).
//! * Event 65 pc101 polls with mask 241 inside サブキーを押したら終了する場合 (ends
//!   when the sub key is pressed); event 108 names the same family
//!   サブキー（装備解除）.
//! * Event 118 pc110 polls right after 決定かキャンセルか、だけ受付する (accept
//!   only decide or cancel) and then tests `== 10` and `== 11`.
//! * Event 510 pc975 polls with mask 32 under the picture `EXIT "长按右键"`
//!   (hold the right button to exit) and tests the result against 11.
//!
//! So the destination variable receives a KEY CODE - 10 decide, 11 cancel, 12 sub,
//! and the numpad direction codes (2 down, 4 left, 6 right, 8 up) - not a bit
//! pattern. Codes 20, 13, 14, 100 and 300 also occur in comparisons and are still
//! unnamed (H-KEY-2 stays open in docs/UNVERIFIED.md).
//!
//! What the mask argument of `123` selects is now decoded. The second argument is
//! not a bitmask: it packs a one-byte option field and a one-byte device field
//! (`wolfrpg-map-parser`'s `BasicOptions` / `InputType`), and the game's own debug
//! comments confirm every field:
//!
//! * `0xB0` (bit 7 wait + 0x20 cancel + 0x10 decide) is polled under event 118's
//!   "決定かキャンセルか、だけ受付する" (accept only decide or cancel).
//! * `0xB8` (wait + cancel + decide + direction 8 = left/right) is polled by event
//!   84, which tests nothing but 4 (left) and 6 (right).
//! * `0xB7` is the same with direction 7 (up/down).
//! * `0xF1` adds the sub key, and event 65 polls it under "サブキーを押したら終了する場合".
//! * event 59 polls `0x10`, `0x20` and `0x40` as three separate single-key checks.
//!
//! The direction nibble is 0 none / 1 four / 2 eight / 3 up / 4 down / 5 left /
//! 6 right / 7 up+down / 8 left+right. Bits 8..11 name the device: 0 the logical
//! key set, 1 keyboard, 2 pad, 3 mouse. A device poll returns that device's raw key
//! code instead: the key-config screen (CE132) polls `0x101` (keyboard) and `0x200`
//! (pad) and compares the captured value with `>= 100` / `>= 300`, which is why the
//! port stores keyboard codes as scancode + 100 and pad codes as button + 300.
//!
//! Bit 7 (`wait`) is the "入力を待つ" checkbox: the poll blocks until one of the
//! accepted keys arrives. Event 249's pause overlay polls `0x91` and never reads the
//! result, so the command exists purely to hold the scene for a key press.
//!
//! The bit layout below is therefore the PORT's own, used only to talk to the host;
//! the numbers handed to scripts are the codes.

/// Confirm / "decide" key (Enter, Z, Space in the original).
pub const OK: u32 = 1;
/// Cancel / back (Escape, X).
pub const CANCEL: u32 = 2;
/// Sub key, WOLF's third action button (C, Shift).
pub const SUB: u32 = 4;
/// Pause key.
pub const PAUSE: u32 = 8;
/// Up.
pub const UP: u32 = 16;
/// Down.
pub const DOWN: u32 = 32;
/// Left.
pub const LEFT: u32 = 64;
/// Right.
pub const RIGHT: u32 = 128;
/// Bit 8 - meaning unverified, only ever seen inside the 771/784/257 masks.
pub const UNKNOWN_8: u32 = 256;
/// Bit 9 - meaning unverified, same masks as UNKNOWN_8.
pub const UNKNOWN_9: u32 = 512;

/// All four directions.
pub const DIRECTIONS: u32 = UP | DOWN | LEFT | RIGHT;
/// Every bit a keyboard can plausibly set in this game.
pub const ALL_KEYS: u32 = 0x3FF;

/// Code a script sees when nothing is held.
pub const CODE_NONE: i32 = 0;
/// 決定 / decide (event 108 comment 決定キー).
pub const CODE_OK: i32 = 10;
/// キャンセル / cancel (event 108 comment キャンセルキー).
pub const CODE_CANCEL: i32 = 11;
/// サブ / sub (event 65 comment サブキー押したら終了する場合).
pub const CODE_SUB: i32 = 12;
/// 下 / down (event 108 comment 下キー).
pub const CODE_DOWN: i32 = 2;
/// 左 / left (event 65 comment 左右キー).
pub const CODE_LEFT: i32 = 4;
/// 右 / right (event 65 comment 左右キー).
pub const CODE_RIGHT: i32 = 6;
/// 上 / up (event 108 comment 上キー).
pub const CODE_UP: i32 = 8;
/// Diagonal, numpad 1 - inferred from the numpad numbering, never compared.
pub const CODE_DOWN_LEFT: i32 = 1;
/// Diagonal, numpad 3 - inferred, never compared.
pub const CODE_DOWN_RIGHT: i32 = 3;
/// Diagonal, numpad 7 - inferred, never compared.
pub const CODE_UP_LEFT: i32 = 7;
/// Diagonal, numpad 9 - inferred, never compared.
pub const CODE_UP_RIGHT: i32 = 9;

/// The host bit a script key code corresponds to.
///
/// `--key-frame` names a WOLF key code (10 decide, 11 cancel, ...), because those are
/// the numbers the scripts compare against; the host needs the port bit instead.
#[must_use]
pub fn bits_for_code(code: i32) -> u32 {
    match code {
        CODE_OK => OK,
        CODE_CANCEL => CANCEL,
        CODE_SUB => SUB,
        CODE_DOWN => DOWN,
        CODE_LEFT => LEFT,
        CODE_RIGHT => RIGHT,
        CODE_UP => UP,
        CODE_DOWN_LEFT => DOWN | LEFT,
        CODE_DOWN_RIGHT => DOWN | RIGHT,
        CODE_UP_LEFT => UP | LEFT,
        CODE_UP_RIGHT => UP | RIGHT,
        // 13 is the pause code above; no script compares it, but a caller may still
        // name it and the mapping is the only one that makes the poll see 13.
        13 => PAUSE,
        _ => 0,
    }
}

/// The key code a script reads for the currently held keys.
///
/// Action keys win over directions because that is the order every menu in this
/// game expects: a player holding a direction and then pressing decide must be
/// reported as a decide. The mask is deliberately ignored - see the module docs -
/// and a diagonal is reported when two perpendicular directions are held.
pub fn code(held: u32) -> i32 {
    if held & OK != 0 {
        return CODE_OK;
    }
    if held & CANCEL != 0 {
        return CODE_CANCEL;
    }
    if held & SUB != 0 {
        return CODE_SUB;
    }
    if held & PAUSE != 0 {
        // 13 is the only pause-ish code left in the corpus (event 523/525), but
        // nothing in the game compares a poll to it, so this is a best guess.
        return 13;
    }
    let up = held & UP != 0;
    let down = held & DOWN != 0;
    let left = held & LEFT != 0;
    let right = held & RIGHT != 0;
    match (up, down, left, right) {
        (true, _, true, _) => CODE_UP_LEFT,
        (true, _, _, true) => CODE_UP_RIGHT,
        (_, true, true, _) => CODE_DOWN_LEFT,
        (_, true, _, true) => CODE_DOWN_RIGHT,
        (true, _, _, _) => CODE_UP,
        (_, true, _, _) => CODE_DOWN,
        (_, _, true, _) => CODE_LEFT,
        (_, _, _, true) => CODE_RIGHT,
        _ => CODE_NONE,
    }
}

/// The host key bits an opcode-123 poll accepts.
///
/// `query.directions` is the editor's direction *selector*, not a bit set: 0 accepts
/// no direction at all, 1 the four cardinals, 2 eight directions (the port's
/// diagonals), 3..8 a single direction or one axis.
#[must_use]
pub fn accepts(query: wolf_vm::KeyQuery) -> u32 {
    let directions = match query.directions {
        0 => 0,
        1 | 2 => DIRECTIONS,
        3 => UP,
        4 => DOWN,
        5 => LEFT,
        6 => RIGHT,
        7 => UP | DOWN,
        8 => LEFT | RIGHT,
        _ => 0,
    };
    directions
        | if query.ok { OK } else { 0 }
        | if query.cancel { CANCEL } else { 0 }
        | if query.sub { SUB } else { 0 }
}

/// The code a `123` poll reads, or 0 when the held keys are outside its request.
///
/// A poll that only accepts decide (event 59's `0x10`) must report 0 while the
/// player holds a direction, which is what the original engine does and what the
/// three separate single-key polls in that event rely on.
#[must_use]
pub fn code_for(held: u32, query: wolf_vm::KeyQuery, banned: u32) -> i32 {
    code(held & accepts(query) & !banned)
}

/// Translate WOLF's key layout into the port's bit layout.
///
/// Opcodes 125 (automatic input) and 126 (input toggle) name keys in the editor's
/// own layout: decide 1, cancel 2, sub 4, **down 0x10, left 0x20, right 0x40,
/// up 0x80**. The port keeps a different order for directions, so the two must be
/// translated instead of reused: without this, CE223's automatic input pressed the
/// opposite directions (it names `0x10` for "move down", which the port read as up).
#[must_use]
pub fn from_wolf_bits(bits: u32) -> u32 {
    let mut out = 0;
    if bits & 0x01 != 0 {
        out |= OK;
    }
    if bits & 0x02 != 0 {
        out |= CANCEL;
    }
    if bits & 0x04 != 0 {
        out |= SUB;
    }
    if bits & 0x10 != 0 {
        out |= DOWN;
    }
    if bits & 0x20 != 0 {
        out |= LEFT;
    }
    if bits & 0x40 != 0 {
        out |= RIGHT;
    }
    if bits & 0x80 != 0 {
        out |= UP;
    }
    out
}

/// WOLF keyboard key codes start at 100: the DirectInput scancode plus 100.
///
/// CE132 resets the decide/cancel/sub keys to 144/145/146 (Z/X/C, scancodes
/// 44/45/46) and its capture loop accepts any value `>= 100`, so the encoding is
/// pinned by the shipped data.
pub const KEYBOARD_CODE_BASE: i32 = 100;
/// Pad key codes start at 300; CE132 writes 301..303 for the three pad buttons.
pub const PAD_CODE_BASE: i32 = 300;

/// Device selector of a basic (logical key) poll.
pub const DEVICE_BASIC: u8 = 0;
/// Device selector of a raw-keyboard poll (CE132's key-config rows).
pub const DEVICE_KEYBOARD: u8 = 1;
/// Device selector of a raw-pad poll.
pub const DEVICE_PAD: u8 = 2;
/// Device selector of a mouse poll (unused by this game's 123 sites).
pub const DEVICE_MOUSE: u8 = 3;

/// The WOLF key code for a PC scancode (set 1).
#[must_use]
pub const fn keyboard_code(scancode: u8) -> i32 {
    KEYBOARD_CODE_BASE + scancode as i32
}

/// The host key bits a change in the mouse buttons represents.
///
/// The command menus poll their key state with opcode 123 every frame while a
/// picture is hovered, so a click has to look like a fresh key press and only on
/// the frame the button goes down. Holding the button must not repeat, which is
/// why this compares the current state against the previous frame's state instead
/// of reporting whatever is held.
///
/// Left press -> [`OK`] (the decide code 10), right press -> [`CANCEL`] (code 11).
/// The middle button is left out: nothing in this game's menus reads it as a key,
/// and opcode 124-style reads still see it through the engine state.
#[must_use]
pub fn mouse_bits(buttons: u32, previous: u32) -> u32 {
    let mut bits = 0;
    if buttons & 1 != 0 && previous & 1 == 0 {
        bits |= OK;
    }
    if buttons & 2 != 0 && previous & 2 == 0 {
        bits |= CANCEL;
    }
    bits
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn the_codes_are_the_numbers_the_developers_compare_against() {
        // Sources are listed in the module docs; each pair is (held bit, code in
        // the comment next to the comparison).
        assert_eq!(code(OK), 10, "決定キー in common event 108");
        assert_eq!(code(CANCEL), 11, "キャンセルキー in common event 108");
        assert_eq!(code(DOWN), 2, "下キー in common event 108");
        assert_eq!(code(UP), 8, "上キー in common event 108");
        assert_eq!(code(LEFT), 4, "左右キー in common event 65");
        assert_eq!(code(RIGHT), 6, "左右キー in common event 65");
        assert_eq!(code(SUB), 12, "サブキー in common event 65");
        assert_eq!(code(0), 0);
    }

    #[test]
    fn action_keys_win_over_directions() {
        assert_eq!(code(OK | UP), CODE_OK);
        assert_eq!(code(CANCEL | LEFT), CODE_CANCEL);
        assert_eq!(code(SUB | DOWN | RIGHT), CODE_SUB);
    }

    #[test]
    fn perpendicular_directions_become_numpad_diagonals() {
        assert_eq!(code(UP | LEFT), CODE_UP_LEFT);
        assert_eq!(code(UP | RIGHT), CODE_UP_RIGHT);
        assert_eq!(code(DOWN | LEFT), CODE_DOWN_LEFT);
        assert_eq!(code(DOWN | RIGHT), CODE_DOWN_RIGHT);
    }

    #[test]
    fn injected_codes_round_trip_through_the_host_bits() {
        for code in [
            CODE_OK,
            CODE_CANCEL,
            CODE_SUB,
            CODE_DOWN,
            CODE_LEFT,
            CODE_RIGHT,
            CODE_UP,
            CODE_DOWN_LEFT,
            CODE_DOWN_RIGHT,
            CODE_UP_LEFT,
            CODE_UP_RIGHT,
            13,
        ] {
            assert_eq!(super::code(bits_for_code(code)), code, "code {code}");
        }
        assert_eq!(bits_for_code(-1), 0);
        assert_eq!(bits_for_code(99), 0);
    }

    #[test]
    fn every_poll_in_the_shipped_data_decodes_into_known_fields() {
        // The 93 opcode-123 sites of CommonEvent.dat, as the words the editor wrote.
        // Values above 0xFF carry the device byte: 257 = keyboard, 512 = pad.
        for word in [
            1u32, 7, 16, 17, 32, 33, 48, 49, 64, 100, 144, 145, 160, 176, 177, 183, 184, 241, 257,
            512,
        ] {
            let query = wolf_vm::KeyQuery::decode(word);
            assert!(
                query.directions <= 8,
                "word {word:#x} names an unknown direction selector {}",
                query.directions
            );
            assert!(
                query.device <= 3,
                "word {word:#x} names an unknown device {}",
                query.device
            );
            assert!(
                query.ok || query.cancel || query.sub || query.directions != 0 || query.device != 0,
                "word {word:#x} accepts nothing at all"
            );
        }
    }

    #[test]
    fn the_option_word_decodes_into_the_fields_the_scripts_expect() {
        // 0xB0: event 118's "決定かキャンセルか、だけ受付する" — wait, decide, cancel.
        let decide_or_cancel = wolf_vm::KeyQuery::decode(0xB0);
        assert_eq!(decide_or_cancel.directions, 0);
        assert!(decide_or_cancel.ok && decide_or_cancel.cancel);
        assert!(!decide_or_cancel.sub && decide_or_cancel.wait);

        // 0xB8: event 84 tests nothing but left and right.
        let left_right = wolf_vm::KeyQuery::decode(0xB8);
        assert_eq!(left_right.directions, 8);
        assert!(left_right.ok && left_right.cancel);

        // 0x11: the common "four directions + decide, do not wait" poll.
        let movement = wolf_vm::KeyQuery::decode(0x11);
        assert_eq!(movement.directions, 1);
        assert!(movement.ok && !movement.cancel && !movement.wait);

        // 0x101: CE132's keyboard capture; 0x200 is the pad one.
        assert_eq!(wolf_vm::KeyQuery::decode(0x101).device, DEVICE_KEYBOARD);
        assert_eq!(wolf_vm::KeyQuery::decode(0x200).device, DEVICE_PAD);
    }

    #[test]
    fn a_poll_only_reports_the_keys_it_asked_for() {
        let decide_only = wolf_vm::KeyQuery::decode(0x10);
        assert_eq!(code_for(DOWN, decide_only, 0), CODE_NONE);
        assert_eq!(code_for(OK, decide_only, 0), CODE_OK);
        assert_eq!(code_for(OK | DOWN, decide_only, 0), CODE_OK);

        let cancel_only = wolf_vm::KeyQuery::decode(0x20);
        assert_eq!(code_for(OK, cancel_only, 0), CODE_NONE);
        assert_eq!(code_for(CANCEL, cancel_only, 0), CODE_CANCEL);

        let sub_only = wolf_vm::KeyQuery::decode(0x40);
        assert_eq!(code_for(SUB, sub_only, 0), CODE_SUB);

        let left_right = wolf_vm::KeyQuery::decode(0xB8);
        assert_eq!(code_for(LEFT, left_right, 0), CODE_LEFT);
        assert_eq!(code_for(RIGHT, left_right, 0), CODE_RIGHT);
        assert_eq!(code_for(UP, left_right, 0), CODE_NONE);

        let up_down = wolf_vm::KeyQuery::decode(0xB7);
        assert_eq!(code_for(UP, up_down, 0), CODE_UP);
        assert_eq!(code_for(DOWN, up_down, 0), CODE_DOWN);
        assert_eq!(code_for(LEFT, up_down, 0), CODE_NONE);

        // A key the script switched off with 126 reads as not pressed.
        let any = wolf_vm::KeyQuery::decode(0xB1);
        assert_eq!(code_for(OK, any, from_wolf_bits(0x01)), CODE_NONE);
        assert_eq!(code_for(DOWN, any, from_wolf_bits(0x10)), CODE_NONE);
        assert_eq!(code_for(DOWN, any, 0), CODE_DOWN);
    }

    #[test]
    fn wolf_key_layout_maps_onto_the_ports_direction_bits() {
        // WOLF: decide 1, cancel 2, sub 4, down 0x10, left 0x20, right 0x40, up 0x80.
        assert_eq!(from_wolf_bits(0x01), OK);
        assert_eq!(from_wolf_bits(0x02), CANCEL);
        assert_eq!(from_wolf_bits(0x04), SUB);
        assert_eq!(from_wolf_bits(0x10), DOWN);
        assert_eq!(from_wolf_bits(0x20), LEFT);
        assert_eq!(from_wolf_bits(0x40), RIGHT);
        assert_eq!(from_wolf_bits(0x80), UP);
        assert_eq!(from_wolf_bits(0xF0), DIRECTIONS);
        assert_eq!(from_wolf_bits(0), 0);
    }

    #[test]
    fn the_title_wait_loop_breaks_on_the_decide_code() {
        // TitleMap event 2 pc97 compares its poll against 20, 11 and 10 - the
        // decide code is the one a keyboard can produce.
        let decide = code(OK);
        assert!(decide == 10 || decide == 11 || decide == 20);
    }

    #[test]
    fn a_left_press_is_the_decide_code_and_holding_it_does_not_repeat() {
        assert_eq!(mouse_bits(1, 0), OK);
        assert_eq!(code(mouse_bits(1, 0)), CODE_OK);
        // Held on the next frame: no fresh bit, so the menu does not re-fire.
        assert_eq!(mouse_bits(1, 1), 0);
        // Released.
        assert_eq!(mouse_bits(0, 1), 0);
    }

    #[test]
    fn a_right_press_is_the_cancel_code() {
        assert_eq!(mouse_bits(2, 0), CANCEL);
        assert_eq!(code(mouse_bits(2, 0)), CODE_CANCEL);
        assert_eq!(mouse_bits(2, 2), 0);
    }

    #[test]
    fn the_middle_button_is_not_a_menu_key() {
        assert_eq!(mouse_bits(4, 0), 0);
        // Left+middle press still only maps the left button.
        assert_eq!(mouse_bits(5, 0), OK);
    }
}
