extends SceneTree

## Input smoke: the title's image rows must answer a left click.
##
##   godot --headless --path godot --script res://tests/mouse_title.gd -- \
##       --data-root=/absolute/Data
##
## Exits 0 when clicking row 0 leaves the title menu and reaches Map003.

func _init() -> void:
	var root := ""
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--data-root="):
			root = arg.substr("--data-root=".length())
	if root.is_empty():
		push_error("mouse_title: pass --data-root=<unpacked Data dir>")
		quit(1)
		return

	var wolf := WolfGame.new()
	if not wolf.open(root):
		push_error("mouse_title: open failed")
		quit(1)
		return
	if not wolf.start_title():
		push_error("mouse_title: start_title failed")
		quit(1)
		return

	# Let the three menu images and the hit layout settle.
	for _i in range(90):
		wolf.frame()
	# Row 0 is the fixed title hit box (10, 400, 240, 52); click its middle.
	wolf.set_input(0, PackedInt32Array(), Vector2i(100, 420), 1)
	wolf.frame()
	wolf.set_input(0, PackedInt32Array(), Vector2i(100, 420), 0)
	var packet: Dictionary = {}
	for _i in range(180):
		packet = wolf.frame()

	var diagnostics: Array = packet.get("diagnostics", [])
	var reached := false
	for line in diagnostics:
		if "130 Teleport: MapData/Map003.mps" in str(line):
			reached = true
	print("mouse_title: pictures=", packet.get("pictures", 0), " choices=", packet.get("choices", []), " reached_map003=", reached)
	if not reached:
		push_error("mouse_title: the click did not leave the title menu")
		quit(1)
		return
	quit(0)
