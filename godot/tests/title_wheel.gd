extends SceneTree

## Mouse-wheel navigation through the Godot extension at the title menu.
##
##   godot --headless --path godot --script res://tests/title_wheel.gd -- \
##       --data-root=/absolute/path/to/work/Data
##
## The title is an opcode-102 choice (menu1/menu2/menu3); Game::frame turns wheel
## notches into cursor steps, and WolfGame.frame reports the resulting cursor.
## Exits 0 when one down-notch advances and one up-notch returns/wraps.

func _init() -> void:
	var root := ""
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--data-root="):
			root = arg.substr("--data-root=".length())
	if root.is_empty():
		push_error("title_wheel: pass --data-root=<unpacked Data dir>")
		quit(1)
		return

	var wolf := WolfGame.new()
	if not wolf.open(root):
		push_error("title_wheel: open failed")
		quit(1)
		return
	wolf.set_auto_advance(true)
	if not wolf.start_title():
		push_error("title_wheel: start_title failed")
		quit(1)
		return

	var packet: Dictionary = {}
	for _i in range(120):
		packet = wolf.frame()
		if packet.get("choices", []).size() == 3:
			break
	if packet.get("choices", []).size() != 3:
		push_error("title_wheel: title menu did not appear")
		quit(1)
		return
	# Let the one-shot title renderer run once for the initial cursor.
	for _i in range(3):
		packet = wolf.frame()
	var start := int(packet.get("choice_cursor", -1))

	wolf.set_wheel(-1)
	packet = wolf.frame()
	for _i in range(3):
		packet = wolf.frame()
	var after_down := int(packet.get("choice_cursor", -1))

	wolf.set_wheel(1)
	packet = wolf.frame()
	for _i in range(3):
		packet = wolf.frame()
	var after_up := int(packet.get("choice_cursor", -1))

	print(
		"title_wheel: start=", start,
		" after_down=", after_down,
		" after_up=", after_up,
		" choices=", packet.get("choices", [])
	)
	if after_down != (start + 1) % 3:
		push_error("title_wheel: one down notch must advance one row")
		quit(1)
		return
	if after_up != start:
		push_error("title_wheel: one up notch must return to the previous row")
		quit(1)
		return
	quit(0)
