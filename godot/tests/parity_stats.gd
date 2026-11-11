extends SceneTree

## Headless long-range parity harness: drive the Rust runtime through the Godot
## extension in a tight loop and print the VM statistic snapshot at each checkpoint.
##
##   godot --headless --path godot --script res://tests/parity_stats.gd -- \
##       --data-root=<unpacked Data dir> [--frames=600,1200,1800] [--save=<file.sav>]
##
## Without `--save` the run starts at common event 42 (`start_title`, the same entry
## as `wolf-cli capture --menu-only`); with `--save` it primes the engine and loads a
## retail save first (the same sequence as `wolf-cli capture --load-save`).
## Auto-play is enabled exactly like `wolf-cli capture --answer 0`: messages dismiss
## themselves and every prompt answers option 0, so both runtimes see the same inputs.
##
## Output (one machine-parseable line per checkpoint):
##   PARITY frames=600 instructions=16038 pictures=4526 messages=15 choices=3 \
##          warnings=0 unmodelled=0 sounds=0 ... max_sprites=.. max_texts=..
## Every stats dictionary field is cumulative in the game, so the snapshot is the
## runtime's totals at that frame.
##
## Warnings and diagnostics are printed but never abort the run: the shell decides.
## Exit codes: 0 = the run completed; 1 = bad arguments or open/start failure.

const DEFAULT_FRAMES := "600"


func _init() -> void:
	var root := ""
	var save_path := ""
	var frames_arg := ""
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--data-root="):
			root = arg.substr("--data-root=".length())
		elif arg.begins_with("--save="):
			save_path = arg.substr("--save=".length())
		elif arg.begins_with("--frames="):
			frames_arg = arg.substr("--frames=".length())

	if root.is_empty():
		push_error("parity_stats: pass --data-root=<unpacked Data dir>")
		quit(1)
		return

	if frames_arg.is_empty():
		frames_arg = DEFAULT_FRAMES
	var checkpoints: Array[int] = []
	for part in frames_arg.split(",", false):
		var text := part.strip_edges()
		if text.is_empty():
			continue
		var value := int(text)
		if value <= 0:
			push_error("parity_stats: bad --frames entry: " + text)
			quit(1)
			return
		if not checkpoints.has(value):
			checkpoints.append(value)
	checkpoints.sort()
	if checkpoints.is_empty():
		push_error("parity_stats: no checkpoints given")
		quit(1)
		return

	var wolf := WolfGame.new()
	if not wolf.open(root):
		push_error("parity_stats: open failed: " + root)
		quit(1)
		return
	# Set the scripted-capture behaviour before the entry point, mirroring
	# wolf-cli's run_capture (auto_advance/auto_choice are set before load_save).
	wolf.set_auto_play(true, 0)
	if not save_path.is_empty():
		# CE48 has to finish before the load or its first pass overwrites the restored
		# status cells; wolf-cli capture --load-save does prime_engine first too.
		wolf.prime_engine()
		if not wolf.load_save(save_path):
			push_error("parity_stats: load_save failed: " + save_path)
			quit(1)
			return
	elif not wolf.start_title():
		push_error("parity_stats: start_title failed")
		quit(1)
		return

	var sound_counts := {"bgm_play": 0, "bgm_stop": 0, "se_play": 0, "se_stop": 0}
	var max_sprites := 0
	var max_texts := 0
	var choice_frames := 0
	var max_choice_options := 0
	var next := 0
	var driven := 0

	for i in range(checkpoints[checkpoints.size() - 1]):
		var packet: Dictionary = wolf.frame()
		driven = i + 1
		max_sprites = maxi(max_sprites, packet.get("sprites", []).size())
		max_texts = maxi(max_texts, packet.get("texts", []).size())
		for cmd in packet.get("sounds", []):
			var key := str(cmd.get("channel", "?")) + "_" + str(cmd.get("action", "?"))
			sound_counts[key] = int(sound_counts.get(key, 0)) + 1
		var options: Array = packet.get("choices", [])
		if options.size() > 0:
			choice_frames += 1
			max_choice_options = maxi(max_choice_options, options.size())
		while next < checkpoints.size() and driven >= checkpoints[next]:
			_snapshot(driven, checkpoints[next], packet, sound_counts, max_sprites, max_texts, choice_frames, max_choice_options)
			next += 1

	print("PARITY_DONE frames=%d checkpoints=%d" % [driven, checkpoints.size()])
	quit(0)


func _snapshot(driven: int, checkpoint: int, packet: Dictionary, sound_counts: Dictionary, max_sprites: int, max_texts: int, choice_frames: int, max_choice_options: int) -> void:
	var stats: Dictionary = packet.get("stats", {})
	var instructions: int = int(stats.get("instructions", 0))
	var pictures: int = int(stats.get("pictures", 0))
	var messages: int = int(stats.get("messages", 0))
	var choices: int = int(stats.get("choices", 0))
	var warnings: int = int(stats.get("warnings", 0))
	var unmodelled: int = int(stats.get("unmodelled", 0))
	var stat_frames: int = int(stats.get("frames", 0))
	var sounds: int = int(sound_counts["bgm_play"]) + int(sound_counts["bgm_stop"]) + int(sound_counts["se_play"]) + int(sound_counts["se_stop"])
	print(
		"PARITY frames=%d instructions=%d pictures=%d messages=%d choices=%d warnings=%d unmodelled=%d sounds=%d bgm_play=%d bgm_stop=%d se_play=%d se_stop=%d max_sprites=%d max_texts=%d choice_frames=%d max_choice_options=%d stat_frames=%d driven=%d"
		% [
			checkpoint, instructions, pictures, messages, choices, warnings, unmodelled,
			sounds,
			int(sound_counts["bgm_play"]), int(sound_counts["bgm_stop"]),
			int(sound_counts["se_play"]), int(sound_counts["se_stop"]),
			max_sprites, max_texts, choice_frames, max_choice_options,
			stat_frames, driven,
		]
	)
	if warnings > 0:
		print("PARITY_WARN frames=%d warnings=%d" % [checkpoint, warnings])
	if unmodelled > 0:
		print("PARITY_WARN frames=%d unmodelled=%d" % [checkpoint, unmodelled])
	for line in packet.get("diagnostics", []):
		print("PARITY_DIAG frames=%d %s" % [checkpoint, str(line)])
