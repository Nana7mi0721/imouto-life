extends Control

## Godot shell for the Rust WOLF runtime.
##
## The Rust side (`WolfGame`) owns the event VM, the picture layer and the atlas; this
## script only feeds input, advances one 60 Hz frame and draws the returned quads with
## Godot's CanvasItem API.  Text is shaped by Godot's TextParagraph using the same
## Microsoft YaHei faces the retail data names.

const LOGICAL_SIZE := Vector2(1024.0, 576.0)
const FONT_BOLD := "C:/Windows/Fonts/msyhbd.ttc"
const FONT_REGULAR := "C:/Windows/Fonts/msyh.ttc"
const WolfTextScript := preload("res://scripts/WolfText.gd")
const WolfKeysLib := preload("res://scripts/WolfKeys.gd")

var wolf: WolfGame
var atlas_texture: ImageTexture
var atlas_len: int = -1
var packet: Dictionary = {}
var bold_font: FontFile
var regular_font: FontFile
var data_root := ""
var bgm_player: AudioStreamPlayer
var se_players: Array[AudioStreamPlayer] = []
var audio_cache: Dictionary = {}
var bgm_tween: Tween
var se_cursor := 0
var frozen_texture: ImageTexture
var last_frame_texture: ImageTexture
var snapshot_pending := false
var diagnostics_printed := false

var entry := "boot"
var load_save_path := ""
var auto_new_game := false
var hold_message := false
var auto_new_game_done := false
var max_texts := 0
var sounds_logged := false
var max_sprites := 0
var capture_path := ""
var capture_frames := 0
var game_frames := 0
var captured := false

## Physical keys currently held, tracked through `_input`. The dictionary is the
## membership set; `held_order` keeps press order because the key-config screen
## polls `raw_keys.first()`, exactly like `wolf-cli play`'s `raw_held` vector.
var held_keys: Dictionary = {}
var held_order: Array[int] = []

## Mouse buttons held as seen by `_input` (1 left / 2 right / 4 middle).
var mouse_down: int = 0
## A press that may already have been released between two physics ticks. WOLF's
## input is edge-triggered, so losing a fast click loses the whole action.
var mouse_latch: int = 0
## Where the latched left press happened, in logical pixels. A click must hit the
## hotspot under the pointer at press time, not wherever the pointer drifted to.
var mouse_latch_pos := Vector2i(-1, -1)
## Wheel notches accumulated between physics ticks: positive up, negative down.
var wheel_notches: int = 0

var log_input := false
var log_messages := false
var log_events := false
var messages_seen := 0
var last_choice_cursor := -1
var last_choice_key := ""
var last_running: Array = []
var last_action_event := -1


func _ready() -> void:
	texture_filter = CanvasItem.TEXTURE_FILTER_NEAREST
	# Parse first: the entry point and log switches are needed before the first frame.
	_parse_args()
	bold_font = _load_font(FONT_BOLD)
	regular_font = _load_font(FONT_REGULAR)

	var root := _resolve_data_root()
	data_root = root
	if root.is_empty():
		push_error("data root not found: pass `-- --data-root=<unpacked Data dir>`")
		set_physics_process(false)
		return

	_setup_audio()
	wolf = WolfGame.new()
	if not wolf.open(root):
		push_error("WolfGame.open failed: " + root)
		set_physics_process(false)
		return
	if auto_new_game:
		# Mirrors `wolf-cli capture --answer 0`: advance messages and answer every
		# choice with option 0 so a scripted capture reaches the daily loop.
		wolf.set_auto_play(true, 0)
		if hold_message:
			wolf.set_auto_advance(false)
		print("wolf: auto-play enabled (messages advance, choices answer 0)")
	if not load_save_path.is_empty():
		wolf.prime_engine()
		if not wolf.load_save(load_save_path):
			push_error("WolfGame.load_save failed: " + load_save_path)
			set_physics_process(false)
			return
	elif entry == "menu":
		# CE48/CE63 are engine coroutines, not part of CE42. Starting the title event
		# directly skips their one-time initialisation: Sys1/Sys2 stay at zero (so a
		# message renders at the top-left instead of (64,410)), the message-window
		# frame never appears, and a new game started from this menu runs without the
		# HUD/UI setup. Prime the engine exactly like the load path above.
		var primed := wolf.prime_engine()
		print("wolf: prime_engine frames=", primed)
		if not wolf.start_title():
			push_error("WolfGame.start_title failed")
			set_physics_process(false)
			return
	elif not wolf.boot():
		push_error("WolfGame.boot failed")
		set_physics_process(false)
		return

	set_physics_process(true)
	queue_redraw()


func _physics_process(_delta: float) -> void:
	if wolf == null:
		return
	var mouse := get_local_mouse_position()
	var mouse_pos := Vector2i(int(mouse.x), int(mouse.y))
	# A fresh left press must hit the hotspot where it went down, even if the
	# pointer moved before this physics tick.
	if mouse_latch & 1 != 0 and mouse_latch_pos.x >= 0 and mouse_latch_pos.y >= 0:
		mouse_pos = mouse_latch_pos
	var raw_keys := _raw_key_codes()
	var buttons := _mouse_buttons()
	mouse_latch = 0
	wolf.set_wheel(wheel_notches)
	wheel_notches = 0
	wolf.set_input(_key_bits(raw_keys), raw_keys, mouse_pos, buttons)
	packet = wolf.frame()
	if packet.get("freeze", false):
		print("wolf: freeze at game frame ", game_frames)
		# The viewport still holds the frame 161 is replacing; copy it before _draw.
		if last_frame_texture == null:
			var previous := get_viewport().get_texture().get_image()
			last_frame_texture = ImageTexture.create_from_image(previous)
		frozen_texture = last_frame_texture
		snapshot_pending = true
	elif packet.get("transition_active", false):
		snapshot_pending = true
	_apply_sounds(packet.get("sounds", []))
	game_frames += 1
	_log_frame()
	max_sprites = maxi(max_sprites, packet.get("sprites", []).size())
	max_texts = maxi(max_texts, packet.get("texts", []).size())
	if not sounds_logged and packet.get("sounds", []).size() > 0:
		sounds_logged = true
		print("wolf: first sound commands ", packet.get("sounds", []))

	_sync_atlas()
	if not packet.get("transition_active", false) and not packet.get("freeze", false) and not _has_frozen_overlay(packet):
		frozen_texture = null
		last_frame_texture = null
	if not diagnostics_printed:
		diagnostics_printed = true
		print("wolf: frame sprites=", packet.get("sprites", []).size(), " texts=", packet.get("texts", []).size(), " pictures=", packet.get("pictures", 0))
		for line in packet.get("diagnostics", []):
			print("wolf: ", line)
		for sprite in packet.get("sprites", []):
			var rect: Rect2 = sprite["rect"]
			if rect.size.x * rect.size.y > 200000.0:
				print("wolf:   large sprite #", sprite.get("number", 0), " rect=", rect, " src=", sprite["src"], " alpha=", sprite["alpha"], " tint=", sprite["tint"])
	queue_redraw()


func _input(event: InputEvent) -> void:
	if event is InputEventMouseButton:
		_handle_mouse_button(event as InputEventMouseButton)
		return
	if not (event is InputEventKey):
		return
	var key_event := event as InputEventKey
	# Physical codes survive keyboard-layout changes and match play.rs's use of
	# winit's PhysicalKey. Fall back to the logical code when the platform (or a
	# synthetic event) does not provide one.
	var identity := key_event.physical_keycode
	if identity == 0:
		identity = key_event.keycode
	if identity == 0:
		return
	if log_input:
		print("input: key=", identity, " pressed=", key_event.pressed, " echo=", key_event.echo, " frame=", game_frames)
	if key_event.pressed:
		# OS auto-repeat echoes the key; the held set already has it.
		if key_event.echo or held_keys.has(identity):
			return
		# F11 is a presentation hotkey consumed in `_unhandled_input`, and play.rs
		# consumes its hotkeys before recording raw keys.
		if identity == KEY_F11:
			return
		held_keys[identity] = true
		held_order.append(identity)
	else:
		_release_held(identity)
		# Some platforms report only the logical code on key-up.
		if key_event.keycode != 0:
			_release_held(key_event.keycode)


## Tracks mouse buttons and wheel notches between physics ticks.
func _handle_mouse_button(event: InputEventMouseButton) -> void:
	var bit := 0
	match event.button_index:
		MOUSE_BUTTON_LEFT:
			bit = 1
		MOUSE_BUTTON_RIGHT:
			bit = 2
		MOUSE_BUTTON_MIDDLE:
			bit = 4
		MOUSE_BUTTON_WHEEL_UP:
			if event.pressed:
				wheel_notches += maxi(1, int(round(event.factor)))
				if log_input:
					print("input: wheel up frame=", game_frames, " notches=", wheel_notches)
			return
		MOUSE_BUTTON_WHEEL_DOWN:
			if event.pressed:
				wheel_notches -= maxi(1, int(round(event.factor)))
				if log_input:
					print("input: wheel down frame=", game_frames, " notches=", wheel_notches)
			return
		_:
			return
	if event.pressed:
		mouse_down |= bit
		mouse_latch |= bit
		if bit == 1:
			# Control-local coordinates, so the hit test uses the same 1024x576
			# space as `get_local_mouse_position` even under stretch.
			var local := get_global_transform_with_canvas().affine_inverse() * event.position
			mouse_latch_pos = Vector2i(int(local.x), int(local.y))
		if log_input:
			print("input: mouse down bit=", bit, " at ", mouse_latch_pos, " frame=", game_frames)
	else:
		mouse_down &= ~bit
		if log_input:
			print("input: mouse up bit=", bit, " frame=", game_frames)


func _notification(what: int) -> void:
	if what == NOTIFICATION_WM_WINDOW_FOCUS_OUT or what == NOTIFICATION_APPLICATION_FOCUS_OUT:
		# Without focus the key-up events never arrive; a stale held key would
		# otherwise look pressed forever.
		held_keys.clear()
		held_order.clear()
		mouse_down = 0
		mouse_latch = 0
		mouse_latch_pos = Vector2i(-1, -1)
		wheel_notches = 0


func _unhandled_input(event: InputEvent) -> void:
	if event is InputEventKey and event.pressed and not event.echo and event.keycode == KEY_F11:
		if DisplayServer.window_get_mode() == DisplayServer.WINDOW_MODE_FULLSCREEN:
			DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_WINDOWED)
		else:
			DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_FULLSCREEN)


func _process(_delta: float) -> void:
	if snapshot_pending:
		snapshot_pending = false
		await RenderingServer.frame_post_draw
		var snapshot := get_viewport().get_texture().get_image()
		last_frame_texture = ImageTexture.create_from_image(snapshot)
	if capture_path.is_empty() or captured or wolf == null:
		return
	if game_frames < capture_frames:
		return
	captured = true
	# Freeze the 60 Hz clock: otherwise a physics tick can advance `packet` to frame
	# N+1 while we await the draw, making captures differ by one animation step.
	set_physics_process(false)
	await RenderingServer.frame_post_draw
	var image := get_viewport().get_texture().get_image()
	var target := capture_path
	if not target.is_absolute_path():
		target = ProjectSettings.globalize_path(target)
	var err := image.save_png(target)
	var stats: Dictionary = packet.get("stats", {})
	print("capture: ", target, " err=", err, " size=", image.get_size(), " game_frames=", game_frames, " max_sprites=", max_sprites, " max_texts=", max_texts)
	print("wolf: last pictures=", packet.get("pictures", 0), " choices=", packet.get("choices", []), " stats=", stats)
	for line in packet.get("diagnostics", []):
		print("wolf-diag: ", line)
	get_tree().quit()


func _draw() -> void:
	draw_rect(Rect2(Vector2.ZERO, LOGICAL_SIZE), Color.BLACK)
	if atlas_texture == null:
		return

	for sprite in packet.get("sprites", []):
		var tint: Color = sprite["tint"]
		tint.a *= float(sprite["alpha"])
		if tint.a <= 0.0:
			continue
		draw_texture_rect_region(atlas_texture, sprite["rect"], sprite["src"], tint)

	for text in packet.get("texts", []):
		_draw_text(text)

	for overlay in packet.get("overlays", []):
		var colour: Color = overlay["color"]
		colour.a *= float(overlay["alpha"])
		if overlay["kind"] == "colour" and colour.a > 0.0:
			draw_rect(Rect2(Vector2.ZERO, LOGICAL_SIZE), colour)
		elif overlay["kind"] == "frozen" and frozen_texture != null and colour.a > 0.0:
			draw_texture_rect(frozen_texture, Rect2(Vector2.ZERO, LOGICAL_SIZE), false, colour)


func _draw_text(item: Dictionary) -> void:
	WolfTextScript.draw_text(self, item, bold_font, regular_font)


func _setup_audio() -> void:
	bgm_player = AudioStreamPlayer.new()
	bgm_player.name = "Bgm"
	add_child(bgm_player)
	for i in range(8):
		var player := AudioStreamPlayer.new()
		player.name = "Se%d" % i
		add_child(player)
		se_players.append(player)


func _apply_sounds(sounds: Array) -> void:
	for cmd in sounds:
		var channel: String = cmd.get("channel", "")
		var action: String = cmd.get("action", "")
		var file: String = cmd.get("file", "")
		var volume := clampf(float(cmd.get("volume", 100)) / 100.0, 0.0, 1.0)
		var frames := int(cmd.get("frames", 0))
		if channel == "bgm":
			if action == "play":
				var stream := _load_audio(file)
				if stream == null:
					continue
				_mark_bgm_loop(stream)
				if bgm_tween != null and bgm_tween.is_valid():
					bgm_tween.kill()
				bgm_player.stream = stream
				bgm_player.volume_db = -80.0 if frames > 0 else linear_to_db(volume)
				bgm_player.play()
				if frames > 0:
					bgm_tween = create_tween()
					bgm_tween.tween_property(bgm_player, "volume_db", linear_to_db(volume), float(frames) / 60.0)
			elif action == "stop":
				if bgm_tween != null and bgm_tween.is_valid():
					bgm_tween.kill()
				if frames > 0:
					bgm_tween = create_tween()
					bgm_tween.tween_property(bgm_player, "volume_db", -80.0, float(frames) / 60.0)
					bgm_tween.tween_callback(bgm_player.stop)
				else:
					bgm_player.stop()
		elif channel == "se":
			if action == "play":
				var stream := _load_audio(file)
				if stream == null:
					continue
				var player := _free_se_player()
				player.stream = stream
				player.volume_db = linear_to_db(volume)
				if frames > 0:
					get_tree().create_timer(float(frames) / 60.0).timeout.connect(player.play)
				else:
					player.play()
			elif action == "stop":
				for player in se_players:
					player.stop()


func _mark_bgm_loop(stream: AudioStream) -> void:
	if stream is AudioStreamOggVorbis:
		(stream as AudioStreamOggVorbis).loop = true
	elif stream is AudioStreamMP3:
		(stream as AudioStreamMP3).loop = true


func _load_audio(file: String) -> AudioStream:
	if file.is_empty() or data_root.is_empty():
		return null
	var path := data_root.path_join(file)
	if audio_cache.has(path):
		return audio_cache[path]
	var stream: AudioStream = null
	match path.get_extension().to_lower():
		"ogg":
			stream = AudioStreamOggVorbis.load_from_file(path)
		"mp3":
			stream = AudioStreamMP3.load_from_file(path)
		"wav":
			stream = AudioStreamWAV.load_from_file(path)
		_:
			push_warning("audio: unsupported extension " + path)
	if stream == null:
		push_warning("audio: cannot load " + path)
		return null
	audio_cache[path] = stream
	return stream


func _free_se_player() -> AudioStreamPlayer:
	for player in se_players:
		if not player.playing:
			return player
	var player := se_players[se_cursor % se_players.size()]
	se_cursor += 1
	return player


func _has_frozen_overlay(packet: Dictionary) -> bool:
	for overlay in packet.get("overlays", []):
		if overlay["kind"] == "frozen":
			return true
	return false


func _sync_atlas() -> void:
	var generation := wolf.atlas_len()
	if generation == atlas_len and atlas_texture != null:
		return
	atlas_len = generation
	var size := wolf.atlas_size()
	var bytes := wolf.atlas_pixels()
	var image := Image.create_from_data(size.x, size.y, false, Image.FORMAT_RGBA8, bytes)
	atlas_texture = ImageTexture.create_from_image(image)


func _resolve_data_root() -> String:
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--data-root="):
			return arg.substr("--data-root=".length())

	var project_root := ProjectSettings.globalize_path("res://")
	var candidates := [
		project_root.path_join("../work/Data"),
		project_root.path_join("Data"),
		OS.get_executable_path().get_base_dir().path_join("Data"),
	]
	for path in candidates:
		if DirAccess.dir_exists_absolute(path.path_join("BasicData")):
			return path.simplify_path()
	return ""


func _parse_args() -> void:
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--entry="):
			entry = arg.substr("--entry=".length())
		elif arg.begins_with("--load-save="):
			load_save_path = arg.substr("--load-save=".length())
		elif arg == "--auto-new-game":
			auto_new_game = true
		elif arg == "--hold-message":
			hold_message = true
		elif arg.begins_with("--capture="):
			capture_path = arg.substr("--capture=".length())
		elif arg.begins_with("--frames="):
			capture_frames = int(arg.substr("--frames=".length()))
		elif arg == "--log-input":
			log_input = true
		elif arg == "--log-messages":
			log_messages = true
		elif arg == "--log-events":
			log_events = true


func _load_font(path: String) -> FontFile:
	var font := FontFile.new()
	if font.load_dynamic_font(path) != OK:
		push_warning("font not loaded: " + path)
		return null
	return font


func _release_held(godot_keycode: int) -> void:
	held_keys.erase(godot_keycode)
	held_order.erase(godot_keycode)


## The WOLF keyboard codes (scancode + 100) held this frame, in press order.
func _raw_key_codes() -> PackedInt32Array:
	var codes := PackedInt32Array()
	for godot_keycode in held_order:
		var code := WolfKeysLib.wolf_code(godot_keycode)
		if code >= 0 and not codes.has(code):
			codes.append(code)
	return codes


func _key_bits(raw_keys: PackedInt32Array) -> int:
	# Same rules as `App::bits()` in wolf-cli play: Sys52/54/56 are read live from
	# the game, so rebinding in CE132 takes effect without a restart.
	return WolfKeysLib.bits_for(Array(raw_keys), wolf.key_config())


func _mouse_buttons() -> int:
	# Event-tracked state plus a latch for a click that was pressed and released
	# entirely between two physics ticks; the level query is a fallback for a
	# button that was already held when the window gained focus.
	var buttons := mouse_down | mouse_latch
	if Input.is_mouse_button_pressed(MOUSE_BUTTON_LEFT):
		buttons |= 1
	if Input.is_mouse_button_pressed(MOUSE_BUTTON_RIGHT):
		buttons |= 2
	if Input.is_mouse_button_pressed(MOUSE_BUTTON_MIDDLE):
		buttons |= 4
	return buttons


## Optional diagnostics (`--log-input`, `--log-events`, `--log-messages`).
##
## Input logging answers "did the click/key reach the runtime?"; event logging
## answers "which event was running?"; message logging gives the dialogue
## transcript with the frame number, so a missing line can be compared against
## the same scripted run in Rust.
func _log_frame() -> void:
	if log_input:
		var cursor := int(packet.get("choice_cursor", 0))
		var options: Array = packet.get("choices", [])
		var key := str(options)
		if cursor != last_choice_cursor or key != last_choice_key:
			last_choice_cursor = cursor
			last_choice_key = key
			print(
				"input: frame=", game_frames, " choices=", options,
				" cursor=", cursor, " mouse=", get_local_mouse_position()
			)
	if log_events:
		var running: Array = []
		for id in wolf.running_events():
			running.append(id)
		# running_events() walks a hash map; sort or the list order changes between
		# frames and every frame counts as a change (gigabytes of log).
		running.sort()
		var action := int(packet.get("last_action_event", -1))
		if running != last_running or action != last_action_event:
			last_running = running
			last_action_event = action
			print(
				"events: frame=", game_frames, " running=", running,
				" last_action=", action, " diagnostics=", packet.get("diagnostics", [])
			)
	if log_messages:
		var stats: Dictionary = packet.get("stats", {})
		var total := int(stats.get("messages", 0))
		if total < messages_seen:
			messages_seen = total
		if total > messages_seen:
			var lines: Array = wolf.transcript()
			var fresh := mini(total - messages_seen, lines.size())
			for index in range(lines.size() - fresh, lines.size()):
				print("msg: frame=", game_frames, " text=", lines[index])
			messages_seen = total