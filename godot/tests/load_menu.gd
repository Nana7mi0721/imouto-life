extends SceneTree

## Headless end-to-end load-menu test through the Godot extension.
##
##   godot --headless --path godot --script res://tests/load_menu.gd -- \
##       --data-root=/absolute/path/to/work/Data
##
## Boots the retail title event, enters the load screen (CE14 -> CE131), moves the
## grid cursor to slot 3, confirms, and asserts the bedroom from SaveData01 is
## restored. Input goes through WolfGame.set_input + wolf.frame() exactly like
## GameView.gd: raw WOLF codes are turned into key bits by WolfKeys.bits_for().
##
## Mirrors crates/wolf-game/tests/m3_save_ui_roundtrip.rs's LOAD phase. Exits 0 on
## success, 0 with a "skip" when SaveData01.sav is absent, 1 on failure.

const WolfKeys := preload("res://scripts/WolfKeys.gd")
const TITLE_CHOICES := ["menu1", "menu2", "menu3"]
const TAP_FRAMES := 2

var wolf: WolfGame
var frames := 0


func _init() -> void:
	var root := ""
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--data-root="):
			root = arg.substr("--data-root=".length())
	if root.is_empty():
		push_error("load_menu: pass --data-root=<unpacked Data dir>")
		quit(1)
		return

	var save_path := root.path_join("Save/SaveData01.sav")
	if not FileAccess.file_exists(save_path):
		print("load_menu: skip (no ", save_path, ")")
		quit(0)
		return

	wolf = WolfGame.new()
	if not wolf.open(root):
		push_error("load_menu: open failed: " + root)
		quit(1)
		return
	# Messages dismiss themselves; choices must still be answered by input.
	wolf.set_auto_advance(true)
	print("load_menu: key_config=", wolf.key_config())
	if not wolf.boot():
		push_error("load_menu: boot failed")
		quit(1)
		return

	# ---- Title event (splash) -> title menu. --------------------------------
	var packet: Dictionary = {}
	var options: Array = []
	for _i in range(240):
		packet = _idle_frame()
		options = _options(packet)
		if options == TITLE_CHOICES:
			break
	if options != TITLE_CHOICES:
		push_error("load_menu: title menu never appeared, choices=%s" % str(options))
		quit(1)
		return
	print("load_menu: title menu after ", frames, " frames, cursor=", packet.get("choice_cursor", 0))

	# ---- Choose row 1 ("load game"). ---------------------------------------
	# Try a real Down tap first; fall back to a mouse click on row 1, then to the
	# scripted cursor used by the Rust round-trip test.
	if int(packet.get("choice_cursor", 0)) != 1:
		packet = _tap([WolfKeys.wolf_code(KEY_DOWN)], 12)
	if int(packet.get("choice_cursor", 0)) != 1:
		print("load_menu: keyboard Down did not move the title cursor; trying a mouse click")
		packet = _click(Vector2i(100, 455))
	if int(packet.get("choice_cursor", 0)) != 1:
		print("load_menu: mouse click did not move the title cursor; setting it directly")
		wolf.set_choice_cursor(1)
		packet = _idle_frame()
	if int(packet.get("choice_cursor", 0)) != 1:
		push_error("load_menu: could not select title row 1")
		quit(1)
		return

	packet = _tap([WolfKeys.wolf_code(KEY_ENTER)], 8)

	# ---- Load screen: CE14 opens CE131 and prints its header. --------------
	var load_text := ""
	for _i in range(60):
		packet = _idle_frame()
		load_text = _joined_texts(packet)
		if "读取" in load_text and int(packet.get("pictures", 0)) > 0:
			break
	if not ("读取" in load_text):
		push_error("load_menu: load screen header missing, texts=%s" % load_text)
		quit(1)
		return
	if int(packet.get("pictures", 0)) <= 0:
		push_error("load_menu: load screen has no pictures")
		quit(1)
		return
	print("load_menu: load screen after ", frames, " frames, pictures=", packet.get("pictures", 0))

	# Let CE131 finish its own setup before the first key tap; otherwise the tap can
	# land before the grid starts polling input and be swallowed.
	for _i in range(30):
		packet = _idle_frame()

	# ---- Walk the grid, then confirm slot 1 (SaveData01). -------------------
	# CE131 indexes grid rows by save file: row 0 = SaveData01 (the retail save),
	# row 1 = SaveData02, rows 2-3 empty. The Rust round-trip test moves to row 2
	# because its SAVE phase wrote SaveData03; with the shipped Save folder that
	# row is empty.
	# One tap = 2 frames. The engine's key repeat (Sys15) makes longer holds step
	# more than one row, so release and let the screen settle between taps.
	for _i in range(2):
		packet = _tap([WolfKeys.wolf_code(KEY_DOWN)], 12)

	# Confirming the empty slot must NOT load anything. This is the observable
	# proof that both Down taps reached the grid (one Down alone would land on
	# SaveData02 and load it). If a SaveData03 is left over from another test the
	# slot is a real save, so skip the probe rather than load it here.
	if FileAccess.file_exists(root.path_join("Save/SaveData03.sav")):
		print("load_menu: SaveData03 exists; skipping the empty-slot probe")
	else:
		packet = _tap([WolfKeys.wolf_code(KEY_ENTER)], 8)
		for _i in range(60):
			packet = _idle_frame()
		if _loaded(_diagnostics(packet)):
			push_error("load_menu: two Down taps should have reached the empty slot 3")
			quit(1)
			return
		if not ("读取" in _joined_texts(packet)):
			push_error("load_menu: left the load screen after confirming an empty slot")
			quit(1)
			return
		print("load_menu: slot 3 is empty as expected after two Down taps")

	# Back up to the retail save and confirm it.
	for _i in range(2):
		packet = _tap([WolfKeys.wolf_code(KEY_UP)], 12)
	packet = _tap([WolfKeys.wolf_code(KEY_ENTER)], 8)

	var max_pictures := 0
	var max_texts := 0
	for _i in range(150):
		packet = _idle_frame()
		max_pictures = maxi(max_pictures, int(packet.get("pictures", 0)))
		max_texts = maxi(max_texts, packet.get("texts", []).size())

	var diagnostics := _diagnostics(packet)
	var loaded := _loaded(diagnostics)
	if not loaded:
		push_error("load_menu: the 220 SaveLoad path never reported a load, diagnostics=%s" % str(diagnostics))
		quit(1)
		return
	if max_pictures <= 0 or max_texts < 10:
		push_error("load_menu: the loaded scene did not draw (pictures=%d texts=%d)" % [max_pictures, max_texts])
		quit(1)
		return

	# The grid stays on screen after a successful load; CE131 closes it on cancel
	# and the menu chain unwinds to the bedroom (same sequence as the Rust test).
	packet = _tap([WolfKeys.wolf_code(KEY_BACKSPACE)], 12)
	var bedroom_text := _joined_texts(packet)
	for _i in range(60):
		packet = _idle_frame()
		bedroom_text = _joined_texts(packet)

	var choices := _options(packet)
	var pictures := int(packet.get("pictures", 0))
	var texts: int = packet.get("texts", []).size()
	print("load_menu: choices=", choices, " pictures=", pictures, " texts=", texts)
	if "读取" in bedroom_text:
		push_error("load_menu: the load screen is still on screen after cancel")
		quit(1)
		return
	if pictures <= 0 or texts < 10:
		push_error("load_menu: the bedroom did not draw after closing the load screen (pictures=%d texts=%d)" % [pictures, texts])
		quit(1)
		return
	quit(0)


func _idle_frame() -> Dictionary:
	wolf.set_input(0, PackedInt32Array(), Vector2i.ZERO, 0)
	frames += 1
	return wolf.frame()


## Press `raw_codes` for TAP_FRAMES, then release and settle for `settle` frames.
## Returns the packet of the last released frame.
func _tap(raw_codes: Array, settle: int) -> Dictionary:
	var config := wolf.key_config()
	var bits := WolfKeys.bits_for(raw_codes, config)
	var packed := PackedInt32Array(raw_codes)
	var packet: Dictionary = {}
	for _i in range(TAP_FRAMES):
		wolf.set_input(bits, packed, Vector2i.ZERO, 0)
		frames += 1
		packet = wolf.frame()
	for _i in range(settle):
		packet = _idle_frame()
	return packet


## Left-click `at` for two frames, like the title screen's mouse path.
func _click(at: Vector2i) -> Dictionary:
	var packet: Dictionary = {}
	for _i in range(TAP_FRAMES):
		wolf.set_input(0, PackedInt32Array(), at, 1)
		frames += 1
		packet = wolf.frame()
	for _i in range(12):
		packet = _idle_frame()
	return packet


func _options(packet: Dictionary) -> Array:
	var out: Array = []
	for option in packet.get("choices", []):
		out.append(str(option))
	return out


func _joined_texts(packet: Dictionary) -> String:
	var parts: Array[String] = []
	for item in packet.get("texts", []):
		parts.append(str(item.get("text", "")))
	return "".join(parts)


func _diagnostics(packet: Dictionary) -> Array:
	var out: Array = []
	for line in packet.get("diagnostics", []):
		out.append(str(line))
	return out


func _loaded(diagnostics: Array) -> bool:
	for line in diagnostics:
		if "220 SaveLoad: loaded" in line:
			return true
	return false
