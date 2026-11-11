extends SceneTree

## Headless save round-trip: boot the title, walk 600 game frames with auto-play,
## write a .sav, then load it into a fresh session and confirm the map resumes.
##
##   godot --headless --path godot --script res://tests/save_roundtrip.gd -- \
##       --data-root=/absolute/path/to/work/Data
##
## Exits 0 when both the save and the load produce pictures; 1 otherwise.
##
## Regression for the SavePart1 gap: a fresh session used to write a save with no map
## objects, which `resume_loaded_map` rejected. `savegame::part1_from_map` now fills the
## snapshot from the installed map; this harness drives the full Godot path.

func _init() -> void:
	var root := ""
	var save_path := ""
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--data-root="):
			root = arg.substr("--data-root=".length())
		elif arg.begins_with("--save-path="):
			save_path = arg.substr("--save-path=".length())
	if root.is_empty():
		push_error("roundtrip: pass --data-root=<unpacked Data dir>")
		quit(1)
		return
	if save_path.is_empty():
		save_path = ProjectSettings.globalize_path("res://../work/out/godot_roundtrip.sav")

	var first := WolfGame.new()
	if not first.open(root):
		push_error("roundtrip: open failed")
		quit(1)
		return
	first.set_auto_play(true, 0)
	if not first.start_title():
		push_error("roundtrip: start_title failed")
		quit(1)
		return
	var pictures := 0
	for _i in range(600):
		pictures = maxi(pictures, int(first.frame().get("pictures", 0)))
	if pictures <= 0:
		push_error("roundtrip: no pictures before save")
		quit(1)
		return
	if not first.save_to(save_path):
		push_error("roundtrip: save_to failed: " + save_path)
		quit(1)
		return

	var second := WolfGame.new()
	if not second.open(root):
		push_error("roundtrip: second open failed")
		quit(1)
		return
	second.prime_engine()
	if not second.load_save(save_path):
		push_error("roundtrip: load_save failed: " + save_path)
		quit(1)
		return
	var resumed := 0
	for _i in range(120):
		resumed = maxi(resumed, int(second.frame().get("pictures", 0)))
	print("roundtrip: saved=", save_path, " pictures=", pictures, " resumed_pictures=", resumed)
	if resumed <= 0:
		push_error("roundtrip: the loaded session produced no pictures")
		quit(1)
		return
	quit(0)
