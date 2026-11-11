extends SceneTree

## Headless load smoke: load a retail .sav, resume its map and run frames.
##
##   godot --headless --path godot --script res://tests/load_save.gd -- \
##       --data-root=/absolute/Data --save=path/to/SaveData01.sav

func _init() -> void:
	var root := ""
	var save_path := ""
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--data-root="):
			root = arg.substr("--data-root=".length())
		elif arg.begins_with("--save="):
			save_path = arg.substr("--save=".length())
	if root.is_empty() or save_path.is_empty():
		push_error("load_save: pass --data-root=<Data> --save=<file.sav>")
		quit(1)
		return
	var wolf := WolfGame.new()
	if not wolf.open(root):
		push_error("load_save: open failed")
		quit(1)
		return
	wolf.prime_engine()
	if not wolf.load_save(save_path):
		push_error("load_save: load failed: " + save_path)
		quit(1)
		return
	var max_pictures := 0
	var max_texts := 0
	for _i in range(120):
		var packet: Dictionary = wolf.frame()
		max_pictures = maxi(max_pictures, int(packet.get("pictures", 0)))
		max_texts = maxi(max_texts, packet.get("texts", []).size())
	print("load_save: pictures=", max_pictures, " texts=", max_texts)
	if max_pictures <= 0:
		push_error("load_save: loaded session produced no pictures")
		quit(1)
		return
	quit(0)
