extends SceneTree

## Headless P0 smoke test: load the GDExtension, start the title menu, run frames.
##
##   godot --headless --path godot --script res://tests/smoke.gd -- \
##       --data-root=/absolute/path/to/work/Data
##
## Exits 0 when the runtime produced pictures; 1 otherwise. This catches extension
## load failures, data-root mistakes and a VM that never reaches the title menu.

func _init() -> void:
	var root := ""
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--data-root="):
			root = arg.substr("--data-root=".length())
	if root.is_empty():
		push_error("smoke: pass --data-root=<unpacked Data dir>")
		quit(1)
		return

	var wolf := WolfGame.new()
	if not wolf.open(root):
		push_error("smoke: open failed: " + root)
		quit(1)
		return
	if not wolf.start_title():
		push_error("smoke: start_title failed")
		quit(1)
		return

	var max_pictures := 0
	var max_sprites := 0
	var max_texts := 0
	for _i in range(240):
		var packet: Dictionary = wolf.frame()
		max_pictures = maxi(max_pictures, int(packet.get("pictures", 0)))
		max_sprites = maxi(max_sprites, packet.get("sprites", []).size())
		max_texts = maxi(max_texts, packet.get("texts", []).size())
	print("smoke: pictures=", max_pictures, " sprites=", max_sprites, " texts=", max_texts)
	if max_pictures <= 0 or max_sprites <= 0:
		push_error("smoke: the title menu produced no drawable pictures")
		quit(1)
		return
	quit(0)