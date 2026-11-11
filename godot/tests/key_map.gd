extends SceneTree

## Headless unit test for scripts/WolfKeys.gd (no game data needed).
##
##   godot --headless --path godot --script res://tests/key_map.gd
##
## Pins the numeric WOLF codes and the App::bits() rules copied from
## crates/wolf-cli/src/play.rs, so a drift in either table fails loudly before the
## interactive front-end silently stops accepting a key.

const WolfKeys := preload("res://scripts/WolfKeys.gd")

var checks := 0
var failures := 0


func _init() -> void:
	# --- Godot physical key -> WOLF code (scancode + 100), play.rs raw_key_code.
	_expect_code("Z", KEY_Z, 144)
	_expect_code("X", KEY_X, 145)
	_expect_code("C", KEY_C, 146)
	_expect_code("Enter", KEY_ENTER, 128)
	_expect_code("KP Enter", KEY_KP_ENTER, 128)
	_expect_code("Backspace", KEY_BACKSPACE, 114)
	_expect_code("Escape", KEY_ESCAPE, 101)
	_expect_code("Space", KEY_SPACE, 157)
	_expect_code("Tab", KEY_TAB, 115)
	_expect_code("Up", KEY_UP, 172)
	_expect_code("Down", KEY_DOWN, 180)
	_expect_code("Left", KEY_LEFT, 175)
	_expect_code("Right", KEY_RIGHT, 177)
	_expect_code("Shift", KEY_SHIFT, 142)
	_expect_code("Ctrl", KEY_CTRL, 129)
	_expect_code("Alt", KEY_ALT, 156)
	_expect_code("F1", KEY_F1, 159)
	_expect_code("F12", KEY_F12, 188)
	_expect_code("KP Multiply", KEY_KP_MULTIPLY, 155)
	_expect_code("KP 0", KEY_KP_0, 182)
	_expect_code("KP Period", KEY_KP_PERIOD, 183)
	_expect_code("Minus", KEY_MINUS, 112)
	_expect_code("Equal", KEY_EQUAL, 113)
	_expect_code("Semicolon", KEY_SEMICOLON, 139)
	_expect_code("Quote", KEY_APOSTROPHE, 140)
	_expect_code("Backquote", KEY_QUOTELEFT, 141)
	_expect_code("Bracket left", KEY_BRACKETLEFT, 126)
	_expect_code("Bracket right", KEY_BRACKETRIGHT, 127)
	_expect_code("Backslash", KEY_BACKSLASH, 143)
	_expect_code("Comma", KEY_COMMA, 151)
	_expect_code("Period", KEY_PERIOD, 152)
	_expect_code("Slash", KEY_SLASH, 153)

	# Every digit, 1 = 0x02 (code 102) .. 9 = 0x0A (code 110), 0 = 0x0B (code 111).
	for digit in range(10):
		var expected := 101 + digit if digit > 0 else 111
		var constant: int = KEY_1 + (digit - 1) if digit > 0 else KEY_0
		_expect_code("Digit %d" % digit, constant, expected)

	_expect_code("A", KEY_A, 130)
	_expect_code("Q", KEY_Q, 116)
	_expect_code("M", KEY_M, 150)
	_expect_code("P", KEY_P, 125)
	# KEY_A..KEY_Z are contiguous, so this catches a missing letter in the table.
	for letter in range(KEY_A, KEY_Z + 1):
		_expect_true(WolfKeys.wolf_code(letter) >= 100, "letter keycode %d has no WOLF code" % letter)

	# Keys outside play.rs's table have no WOLF code.
	_expect_code("Pause (unmapped)", KEY_PAUSE, -1)
	_expect_code("Meta (unmapped)", KEY_META, -1)
	_expect_code("KP Divide (unmapped)", KEY_KP_DIVIDE, -1)

	# --- bits_for: shipped System.sav bindings 144/145/146 (Z/X/C).
	var defaults := PackedInt32Array()
	_expect_bits("Z confirms (default)", [144], defaults, WolfKeys.OK)
	_expect_bits("Enter confirms (default)", [128], defaults, WolfKeys.OK)
	_expect_bits("X cancels (default)", [145], defaults, WolfKeys.CANCEL)
	_expect_bits("Backspace cancels (default)", [114], defaults, WolfKeys.CANCEL)
	_expect_bits("Escape aliases cancel", [101], defaults, WolfKeys.CANCEL)
	_expect_bits("C is sub (default)", [146], defaults, WolfKeys.SUB)
	_expect_bits("Up", [172], defaults, WolfKeys.UP)
	_expect_bits("Down", [180], defaults, WolfKeys.DOWN)
	_expect_bits("Left", [175], defaults, WolfKeys.LEFT)
	_expect_bits("Right", [177], defaults, WolfKeys.RIGHT)
	_expect_bits("Z + Down combines", [144, 180], defaults, WolfKeys.OK | WolfKeys.DOWN)
	_expect_bits("all three actions combine", [144, 145, 146], defaults, 7)
	# play.rs has no Space alias; the old hard-coded front-end was wrong here.
	_expect_bits("Space alone is not confirm", [157], defaults, 0)

	var explicit_defaults := PackedInt32Array([144, 16, 145, 32, 146, 64])
	_expect_bits("Z with explicit defaults", [144], explicit_defaults, WolfKeys.OK)
	_expect_bits("X with explicit defaults", [145], explicit_defaults, WolfKeys.CANCEL)

	# --- bits_for: rebinding in CE132 is live (config [145,_,144,_,146,_]).
	var swapped := PackedInt32Array([145, 16, 144, 32, 146, 64])
	_expect_bits("Z is cancel after rebinding", [144], swapped, WolfKeys.CANCEL)
	_expect_bits("X is confirm after rebinding", [145], swapped, WolfKeys.OK)
	_expect_bits("Enter stays confirm after rebinding", [128], swapped, WolfKeys.OK)
	_expect_bits("Backspace stays cancel after rebinding", [114], swapped, WolfKeys.CANCEL)
	_expect_bits("C stays sub after rebinding", [146], swapped, WolfKeys.SUB)
	_expect_bits("Down stays down after rebinding", [180], swapped, WolfKeys.DOWN)

	# A short/empty config falls back to the shipped defaults.
	_expect_bits("short config uses defaults", [144], PackedInt32Array([145]), WolfKeys.OK)
	_expect_bits("empty config uses defaults", [145], PackedInt32Array(), WolfKeys.CANCEL)

	print("key_map: checks=", checks, " failures=", failures)
	if failures > 0:
		push_error("key_map: %d check(s) failed" % failures)
		quit(1)
		return
	quit(0)


func _expect_code(label: String, godot_keycode: int, expected: int) -> void:
	var actual := WolfKeys.wolf_code(godot_keycode)
	_expect_true(actual == expected, "%s: expected WOLF code %d, got %d" % [label, expected, actual])


func _expect_bits(label: String, raw_codes: Array, config: PackedInt32Array, expected: int) -> void:
	var actual := WolfKeys.bits_for(raw_codes, config)
	_expect_true(actual == expected, "%s: expected bits %d, got %d" % [label, expected, actual])


func _expect_true(condition: bool, message: String) -> void:
	checks += 1
	if condition:
		return
	failures += 1
	push_error("key_map: " + message)
