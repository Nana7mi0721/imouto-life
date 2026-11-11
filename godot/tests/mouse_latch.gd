extends SceneTree

## Input-state unit test for GameView's mouse latch and wheel accumulator.
##
##   godot --headless --path godot --script res://tests/mouse_latch.gd
##
## A click can be pressed and released between two 60 Hz physics ticks; WOLF reads
## mouse buttons edge-triggered, so sampling `Input.is_mouse_button_pressed` alone
## would lose the whole action. GameView latches the press for one tick and keeps
## the press position for the hotspot hit test. The script is instantiated without
## entering the tree, so `_ready` (which loads the game data) does not run.

func _init() -> void:
	var view: Control = load("res://scripts/GameView.gd").new()
	var failures := 0

	# A fast left click: press and release before the next physics tick.
	var press := _button(MOUSE_BUTTON_LEFT, true)
	var release := _button(MOUSE_BUTTON_LEFT, false)
	view._handle_mouse_button(press)
	view._handle_mouse_button(release)
	failures += _check((int(view.get("mouse_latch")) & 1) != 0, "left press is latched")
	failures += _check((int(view.get("mouse_down")) & 1) == 0, "left release clears the held level")
	failures += _check((view._mouse_buttons() & 1) != 0, "latched left click reaches the runtime")
	failures += _check(
		view.get("mouse_latch_pos") == Vector2i(100, 420),
		"the click position is kept for the hotspot test"
	)

	# Right click: the cancel path uses the same edge latch.
	view._handle_mouse_button(_button(MOUSE_BUTTON_RIGHT, true))
	view._handle_mouse_button(_button(MOUSE_BUTTON_RIGHT, false))
	failures += _check((int(view.get("mouse_latch")) & 2) != 0, "right press is latched")
	failures += _check((view._mouse_buttons() & 2) != 0, "latched right click reaches the runtime")

	# The latch is one-shot: once the physics frame consumes it, the held level is
	# what remains (zero after the release above).
	view.set("mouse_latch", 0)
	failures += _check((view._mouse_buttons() & 3) == 0, "a consumed latch does not repeat")

	# Wheel notches accumulate between physics ticks and follow the scroll direction.
	view._handle_mouse_button(_wheel(MOUSE_BUTTON_WHEEL_UP))
	view._handle_mouse_button(_wheel(MOUSE_BUTTON_WHEEL_UP))
	view._handle_mouse_button(_wheel(MOUSE_BUTTON_WHEEL_DOWN))
	failures += _check(int(view.get("wheel_notches")) == 1, "wheel up/up/down nets one notch up")

	# Arrow keys must reach the raw-key set through `_input`; this is the path the
	# title cursor and the save grid use for up/down/left/right.
	var down := InputEventKey.new()
	down.physical_keycode = KEY_DOWN
	down.keycode = KEY_DOWN
	down.pressed = true
	view._input(down)
	failures += _check(
		view._raw_key_codes() == PackedInt32Array([180]),
		"physical KEY_DOWN maps to WOLF 180"
	)
	down.pressed = false
	view._input(down)
	failures += _check(view._raw_key_codes().is_empty(), "key release clears the held arrow")

	# Some platforms report only the logical code; `_input` falls back to it.
	var left := InputEventKey.new()
	left.physical_keycode = 0
	left.keycode = KEY_LEFT
	left.pressed = true
	view._input(left)
	failures += _check(
		view._raw_key_codes() == PackedInt32Array([175]),
		"logical KEY_LEFT falls back to WOLF 175"
	)
	left.pressed = false
	view._input(left)

	# Focus loss must not leave a button or wheel notch stuck.
	view._notification(NOTIFICATION_APPLICATION_FOCUS_OUT)
	failures += _check(int(view.get("mouse_down")) == 0, "focus loss clears held buttons")
	failures += _check(int(view.get("mouse_latch")) == 0, "focus loss clears the latch")
	failures += _check(int(view.get("wheel_notches")) == 0, "focus loss clears wheel notches")

	view.free()
	print("mouse_latch: failures=", failures)
	quit(0 if failures == 0 else 1)


func _button(index: int, pressed: bool) -> InputEventMouseButton:
	var event := InputEventMouseButton.new()
	event.button_index = index
	event.pressed = pressed
	event.position = Vector2(100, 420)
	return event


func _wheel(index: int) -> InputEventMouseButton:
	var event := InputEventMouseButton.new()
	event.button_index = index
	event.pressed = true
	event.factor = 1.0
	return event


func _check(condition: bool, what: String) -> int:
	if condition:
		return 0
	push_error("mouse_latch: " + what)
	return 1
