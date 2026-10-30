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
//! What the mask argument of `123` selects is NOT understood yet: one poll can
//! return any of six codes (event 108, mask 177 -> 10/11/2 in the first branch and
//! 8/4/6 in the else branch), which rules out "one bit per key". The port takes the
//! mask but answers with the code of whatever is held, which is forward compatible
//! with every comparison the game performs: `!= 0` still means "any key", `== 10`
//! still means decide.
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
    fn the_masks_the_game_actually_polls_are_all_within_our_bitset() {
        for mask in [
            1u32, 7, 16, 17, 32, 33, 48, 49, 64, 144, 145, 160, 176, 177, 183, 184, 241, 257, 771,
            784,
        ] {
            assert_eq!(mask & !ALL_KEYS, 0, "mask {mask} has bits we do not model");
        }
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
