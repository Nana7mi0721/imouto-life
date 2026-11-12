extends SceneTree

## Headless P0 smoke test: load the GDExtension, start the title menu, run frames.
##
##   godot --headless --path godot --script res://tests/smoke.gd -- \
##       --data-root=/absolute/path/to/work/Data
##
## Exits 0 when the runtime produced pictures; 1 otherwise. This catches extension
## load failures, data-root mistakes and a VM that never reaches the title menu.

class _FrozenSnapshotProbe extends "res://scripts/GameView.gd":
	var capture_count := 0

	func _capture_frozen_frame() -> void:
		capture_count += 1
		var image := Image.create(1, 1, false, Image.FORMAT_RGBA8)
		frozen_texture = ImageTexture.create_from_image(image)


func _init() -> void:
	if _check_energy_batch() != 0:
		quit(1)
		return
	if _check_transition_snapshot_once() != 0:
		quit(1)
		return

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


func _check_energy_batch() -> int:
	var view := _FrozenSnapshotProbe.new()
	var batches: Array[Dictionary] = [{
		"blend": 3,
		"items": [],
		"overlays": [],
		"energy": {},
	}]
	var energy := {"current": 3, "max": 3}
	view._append_energy_and_overlays(batches, [], energy)
	if (
		batches.size() != 2
		or int(batches[-1]["blend"]) != 0
		or batches[-1]["energy"] != energy
	):
		push_error("smoke: energy must get a normal-blend batch after a mixed sprite")
		view.free()
		return 1

	var normal: Array[Dictionary] = [{
		"blend": 0,
		"items": [],
		"overlays": [],
		"energy": {},
	}]
	view._append_energy_and_overlays(normal, [], energy)
	if normal.size() != 1 or normal[0]["energy"] != energy:
		push_error("smoke: energy should reuse a final normal-blend batch")
		view.free()
		return 1

	print("smoke: energy_normal_batch=ok")
	view.free()
	return 0


func _check_transition_snapshot_once() -> int:
	var view := _FrozenSnapshotProbe.new()
	var frozen_overlay := [{"kind": "frozen"}]
	view._update_frozen_frame({
		"freeze": true,
		"transition_active": true,
		"overlays": frozen_overlay,
	})
	if view.capture_count != 1 or view.frozen_texture == null:
		push_error("smoke: the first freeze must capture exactly once")
		view.free()
		return 1

	var frozen := view.frozen_texture
	for _i in range(600):
		view._update_frozen_frame({
			"transition_active": true,
			"overlays": frozen_overlay,
		})
	if view.capture_count != 1 or view.frozen_texture != frozen:
		push_error("smoke: transition_active frames must reuse the frozen texture")
		view.free()
		return 1

	view._update_frozen_frame({"transition_active": false, "overlays": []})
	if view.frozen_texture != null:
		push_error("smoke: the frozen texture must be released after the transition")
		view.free()
		return 1

	view._update_frozen_frame({
		"freeze": true,
		"transition_active": true,
		"overlays": frozen_overlay,
	})
	if view.capture_count != 2:
		push_error("smoke: a new transition must be allowed one new freeze capture")
		view.free()
		return 1

	print("smoke: transition_freeze_captures=", view.capture_count)
	view.free()
	return 0
