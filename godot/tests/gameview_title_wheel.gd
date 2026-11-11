extends SceneTree

## End-to-end input test through the real GameView scene script.
##
##   godot --headless --path godot --script res://tests/gameview_title_wheel.gd -- \
##       --data-root=/absolute/path/to/work/Data
##
## Unlike title_wheel.gd (which calls WolfGame directly), this adds GameView to the
## tree, lets its 60 Hz loop run, then feeds a wheel event and an arrow key through
## `_input`. It proves that `_physics_process` forwards the wheel and the physical
## key set into `WolfGame`, which is where the user's "no cursor movement" report
## lives. Exits 0 when both move the title cursor.

func _init() -> void:
	var root_dir := ""
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--data-root="):
			root_dir = arg.substr("--data-root=".length())
	if root_dir.is_empty():
		push_error("gameview_title_wheel: pass --data-root=<unpacked Data dir>")
		quit(1)
		return

	var view: Control = load("res://scripts/GameView.gd").new()
	view.set_anchors_preset(Control.PRESET_FULL_RECT)
	root.add_child(view)

	var packet: Dictionary = {}
	for _i in range(180):
		await physics_frame
		packet = view.packet
		if packet.get("choices", []).size() == 3:
			break
	if packet.get("choices", []).size() != 3:
		push_error("gameview_title_wheel: title menu never appeared")
		view.free()
		quit(1)
		return

	var start := int(packet.get("choice_cursor", -1))

	# One wheel-down notch: GameView accumulates it and set_wheel feeds the next frame.
	view._handle_mouse_button(_wheel(MOUSE_BUTTON_WHEEL_DOWN))
	await physics_frame
	await physics_frame
	packet = view.packet
	var after_wheel := int(packet.get("choice_cursor", -1))

	# One arrow Down: GameView tracks the physical key and the game moves the cursor.
	view._input(_key(KEY_DOWN, true))
	await physics_frame
	view._input(_key(KEY_DOWN, false))
	await physics_frame
	await physics_frame
	packet = view.packet
	var after_arrow := int(packet.get("choice_cursor", -1))

	print(
		"gameview_title_wheel: start=", start,
		" after_wheel=", after_wheel,
		" after_arrow=", after_arrow,
		" choices=", packet.get("choices", [])
	)
	view.free()
	if after_wheel != (start + 1) % 3:
		push_error("gameview_title_wheel: wheel-down did not advance the title cursor")
		quit(1)
		return
	if after_arrow != (after_wheel + 1) % 3:
		push_error("gameview_title_wheel: arrow Down did not advance the title cursor")
		quit(1)
		return
	quit(0)


func _wheel(index: int) -> InputEventMouseButton:
	var event := InputEventMouseButton.new()
	event.button_index = index
	event.pressed = true
	event.factor = 1.0
	return event


func _key(code: int, pressed: bool) -> InputEventKey:
	var event := InputEventKey.new()
	event.physical_keycode = code
	event.keycode = code
	event.pressed = pressed
	return event
