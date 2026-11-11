extends RefCounted

## Static translation between Godot physical keys and the WOLF input encoding.
##
## Table source: `crates/wolf-cli/src/play.rs` in this repository --
## `raw_key_code()` for the scancode table, `fixed_bit()` for the fixed aliases
## (arrows / Enter / Backspace / Escape) and `App::bits()` for how the live
## `Sys52..57` bindings turn held keys into the host key-bit mask. Keep this file
## in sync with play.rs whenever the Rust mapping changes; key_map.gd pins the
## numeric values the retail game ships with.
##
## WOLF keyboard code = DirectInput set-1 scan code + 100 (Z = 0x2C -> 144,
## X = 0x2D -> 145, C = 0x2E -> 146, Enter = 0x1C -> 128, Backspace = 0x0E -> 114).

## Host key bits, in the port's internal order (crates/wolf-game/src/key.rs).
const OK := 1
const CANCEL := 2
const SUB := 4
const UP := 16
const DOWN := 32
const LEFT := 64
const RIGHT := 128

const WOLF_CODE_BASE := 100
const WOLF_ESCAPE := 101
const WOLF_BACKSPACE := 114
const WOLF_ENTER := 128
const WOLF_SPACE := 157
const WOLF_UP := 172
const WOLF_DOWN := 180
const WOLF_LEFT := 175
const WOLF_RIGHT := 177

## Shipped defaults from System.sav: Sys52..57. Only the even entries are keyboard
## decide/cancel/sub; the odd ones are the file's flag words, kept so the array
## shape matches `WolfGame.key_config()`.
const DEFAULT_CONFIG := [144, 16, 145, 32, 146, 64]


## The DirectInput set-1 scan code Godot's physical key corresponds to, or -1.
##
## Extended (E0-prefixed) keys share the set-1 make code with their keypad
## counterparts, exactly like play.rs documents: Up/KP_8 = 0x48, Insert/KP_0 =
## 0x52, etc. Godot exposes one KEY_SHIFT / KEY_CTRL / KEY_ALT constant, so only
## the left-hand codes of play.rs can be produced here.
static func scancode_for(godot_keycode: int) -> int:
	match godot_keycode:
		KEY_ESCAPE:
			return 0x01
		KEY_1:
			return 0x02
		KEY_2:
			return 0x03
		KEY_3:
			return 0x04
		KEY_4:
			return 0x05
		KEY_5:
			return 0x06
		KEY_6:
			return 0x07
		KEY_7:
			return 0x08
		KEY_8:
			return 0x09
		KEY_9:
			return 0x0A
		KEY_0:
			return 0x0B
		KEY_MINUS:
			return 0x0C
		KEY_EQUAL:
			return 0x0D
		KEY_BACKSPACE:
			return 0x0E
		KEY_TAB:
			return 0x0F
		KEY_Q:
			return 0x10
		KEY_W:
			return 0x11
		KEY_E:
			return 0x12
		KEY_R:
			return 0x13
		KEY_T:
			return 0x14
		KEY_Y:
			return 0x15
		KEY_U:
			return 0x16
		KEY_I:
			return 0x17
		KEY_O:
			return 0x18
		KEY_P:
			return 0x19
		KEY_BRACKETLEFT:
			return 0x1A
		KEY_BRACKETRIGHT:
			return 0x1B
		KEY_ENTER:
			return 0x1C
		# The numeric keypad Enter shares the main Return scancode. Godot reports it as
		# KEY_KP_ENTER/physical 4194310, which used to fall through to -1: the player
		# pressed Enter and nothing happened.
		KEY_KP_ENTER:
			return 0x1C
		KEY_CTRL:
			return 0x1D
		KEY_A:
			return 0x1E
		KEY_S:
			return 0x1F
		KEY_D:
			return 0x20
		KEY_F:
			return 0x21
		KEY_G:
			return 0x22
		KEY_H:
			return 0x23
		KEY_J:
			return 0x24
		KEY_K:
			return 0x25
		KEY_L:
			return 0x26
		KEY_SEMICOLON:
			return 0x27
		KEY_APOSTROPHE:
			return 0x28
		KEY_QUOTELEFT:
			return 0x29
		KEY_SHIFT:
			return 0x2A
		KEY_BACKSLASH:
			return 0x2B
		KEY_Z:
			return 0x2C
		KEY_X:
			return 0x2D
		KEY_C:
			return 0x2E
		KEY_V:
			return 0x2F
		KEY_B:
			return 0x30
		KEY_N:
			return 0x31
		KEY_M:
			return 0x32
		KEY_COMMA:
			return 0x33
		KEY_PERIOD:
			return 0x34
		KEY_SLASH:
			return 0x35
		# Godot has no separate right-hand modifier constants; KEY_SHIFT covers
		# both physical keys, which play.rs maps to 0x2A / 0x36.
		KEY_KP_MULTIPLY:
			return 0x37
		KEY_ALT:
			return 0x38
		KEY_SPACE:
			return 0x39
		KEY_CAPSLOCK:
			return 0x3A
		KEY_F1:
			return 0x3B
		KEY_F2:
			return 0x3C
		KEY_F3:
			return 0x3D
		KEY_F4:
			return 0x3E
		KEY_F5:
			return 0x3F
		KEY_F6:
			return 0x40
		KEY_F7:
			return 0x41
		KEY_F8:
			return 0x42
		KEY_F9:
			return 0x43
		KEY_F10:
			return 0x44
		KEY_NUMLOCK:
			return 0x45
		KEY_SCROLLLOCK:
			return 0x46
		KEY_KP_7:
			return 0x47
		KEY_KP_8:
			return 0x48
		KEY_KP_9:
			return 0x49
		KEY_KP_SUBTRACT:
			return 0x4A
		KEY_KP_4:
			return 0x4B
		KEY_KP_5:
			return 0x4C
		KEY_KP_6:
			return 0x4D
		KEY_KP_ADD:
			return 0x4E
		KEY_KP_1:
			return 0x4F
		KEY_KP_2:
			return 0x50
		KEY_KP_3:
			return 0x51
		KEY_KP_0:
			return 0x52
		KEY_KP_PERIOD:
			return 0x53
		KEY_F11:
			return 0x57
		KEY_F12:
			return 0x58
		# Extended keys use their set-1 make code (play.rs "Extended keys" block).
		KEY_UP:
			return 0x48
		KEY_DOWN:
			return 0x50
		KEY_LEFT:
			return 0x4B
		KEY_RIGHT:
			return 0x4D
		KEY_INSERT:
			return 0x52
		KEY_DELETE:
			return 0x53
		KEY_HOME:
			return 0x47
		KEY_END:
			return 0x4F
		KEY_PAGEUP:
			return 0x49
		KEY_PAGEDOWN:
			return 0x51
		_:
			return -1


## WOLF keyboard code (scancode + 100) for a Godot physical keycode, or -1.
static func wolf_code(godot_keycode: int) -> int:
	var scancode := scancode_for(godot_keycode)
	if scancode < 0:
		return -1
	return WOLF_CODE_BASE + scancode


## Host key bits for the WOLF raw codes held this frame.
##
## Mirrors `App::bits()` in play.rs: the configured decide/cancel/sub codes come
## from `Sys52/54/56` (even indices of WolfGame.key_config()), Enter and Backspace
## stay fixed aliases from the manual, Escape aliases Backspace, and the arrows
## always carry 16/32/64/128. A binding whose value is an arrow therefore yields
## both the direction bit and the action bit, as in play.rs. Space on its own is
## not an alias (play.rs `fixed_bit` has no Space entry).
##
## `config` shorter than six words falls back to the shipped defaults.
static func bits_for(raw_codes: Array, config: PackedInt32Array) -> int:
	var bindings: Array = DEFAULT_CONFIG
	if config.size() >= 6:
		bindings = [config[0], config[1], config[2], config[3], config[4], config[5]]
	var decide: int = bindings[0]
	var cancel: int = bindings[2]
	var sub: int = bindings[4]

	var bits := 0
	for raw in raw_codes:
		var code := int(raw)
		match code:
			WOLF_UP:
				bits |= UP
			WOLF_DOWN:
				bits |= DOWN
			WOLF_LEFT:
				bits |= LEFT
			WOLF_RIGHT:
				bits |= RIGHT
			WOLF_ENTER:
				bits |= OK
			WOLF_BACKSPACE, WOLF_ESCAPE:
				bits |= CANCEL
		if code == decide:
			bits |= OK
		if code == cancel:
			bits |= CANCEL
		if code == sub:
			bits |= SUB
	return bits
