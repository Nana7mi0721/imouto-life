extends Control

## Godot shell for the Rust WOLF runtime.
##
## The Rust side (`WolfGame`) owns the event VM, the picture layer and the atlas; this
## script only feeds input, advances one 60 Hz frame and draws the returned quads with
## Godot's CanvasItem API.  Text is shaped by Godot's TextParagraph using the same
## Microsoft YaHei faces the retail data names when they exist; other hosts fall back
## to the faces bundled in the data root and finally to a system font.

const LOGICAL_SIZE := Vector2(1024.0, 576.0)
## Preferred UI faces on Windows.  Missing files are skipped, never assumed.
const WINDOWS_FONT_BOLD := "C:/Windows/Fonts/msyhbd.ttc"
const WINDOWS_FONT_REGULAR := "C:/Windows/Fonts/msyh.ttc"
## Faces shipped in the retail data root, tried in this order on any host.
const BUNDLED_FONT_NAMES: Array[String] = [
	"◆GenJyuuGothicX-P-Bold.ttf",
	"07やさしさゴシックボールド.ttf",
]
## Last-resort primary faces.  A SystemFont always exists, so text never vanishes.
const SYSTEM_FONT_NAMES: Array[String] = [
	"Microsoft YaHei UI",
	"Microsoft YaHei",
	"Noto Sans CJK SC",
	"Source Han Sans SC",
	"WenQuanYi Micro Hei",
	"sans-serif",
]
## Symbol-only fallback attached to both primary faces.  Microsoft YaHei has no
## U+266A (the message "♪" glyph), so the shaper must be able to reach a face that
## does.  The list is probed by the platform, not assumed to exist.
const SYMBOL_FONT_NAMES: Array[String] = [
	"Segoe UI Symbol",
	"Noto Sans Symbols 2",
	"Noto Sans Symbols",
	"DejaVu Sans",
	"sans-serif",
]
const WolfTextScript := preload("res://scripts/WolfText.gd")
const WolfKeysLib := preload("res://scripts/WolfKeys.gd")

class _BlendBatch extends Node2D:
	const LOGICAL_SIZE := Vector2(1024.0, 576.0)

	var items: Array = []
	var overlays: Array = []
	var atlas: Texture2D
	var bold_font: Font
	var regular_font: Font
	var frozen_texture: Texture2D
	var ap: Dictionary = {}

	func _draw() -> void:
		for item in items:
			if item.has("sprite"):
				if atlas == null:
					continue
				var sprite: Dictionary = item["sprite"]
				var tint: Color = sprite["tint"]
				var blend := int(sprite.get("blend", 0))
				if blend == 3:
					# WOLF manual: Multiply blend ignores picture opacity (alpha = 1.0).
					tint.a = float(sprite["tint"].a)
				else:
					tint.a *= float(sprite["alpha"])
				if tint.a <= 0.0:
					continue
				draw_texture_rect_region(atlas, sprite["rect"], sprite["src"], tint)
			elif item.has("text"):
				WolfTextScript.draw_text(self, item["text"], bold_font, regular_font)

		_draw_action_points()
		for overlay in overlays:
			var colour: Color = overlay["color"]
			colour.a *= float(overlay["alpha"])
			if overlay["kind"] == "colour" and colour.a > 0.0:
				draw_rect(Rect2(Vector2.ZERO, LOGICAL_SIZE), colour)
			elif overlay["kind"] == "frozen" and frozen_texture != null and colour.a > 0.0:
				draw_texture_rect(frozen_texture, Rect2(Vector2.ZERO, LOGICAL_SIZE), false, colour)

	func _draw_action_points() -> void:
		if ap.is_empty():
			return
		var maximum := maxi(1, int(ap.get("max", 0)))
		var current := clampi(int(ap.get("current", 0)), 0, maximum)
		var box: Rect2 = ap.get("bar", Rect2(Vector2(593.0, 18.0), Vector2(100.0, 12.0)))
		# Reference (`参照图仅参考行动力条.png`): a dark trough with a thin light
		# border and a 1 px-inset soft grey fill, not the old 2 px-inset white slab.
		draw_rect(box, Color(0.16, 0.16, 0.16, 0.92), true)
		draw_rect(box, Color(0.78, 0.78, 0.78, 1.0), false, 1.0)
		var ratio := float(current) / float(maximum)
		if ratio > 0.0:
			draw_rect(
				Rect2(
					box.position + Vector2(1.0, 1.0),
					Vector2((box.size.x - 2.0) * ratio, box.size.y - 2.0)
				),
				Color(0.82, 0.82, 0.82, 0.95),
				true
			)

var wolf: WolfGame
var atlas_texture: ImageTexture
var atlas_len: int = -1
var atlas_pixel_size := Vector2i.ZERO
var packet: Dictionary = {}
var bold_font: Font
var regular_font: Font
var data_root := ""
var bgm_player: AudioStreamPlayer
## WOLF's BGS (background sound / ambience) is a second looping bus; rain or wind
## must not stop the music (report BUG-17).
var bgs_player: AudioStreamPlayer
var se_players: Array[AudioStreamPlayer] = []
var audio_cache: Dictionary = {}
## Insertion order for [member audio_cache]. The cache used to grow forever; 64
## streams is enough for the current scene plus recent voices, and the oldest
## entry that no player still references is dropped first (report II.P2).
const AUDIO_CACHE_LIMIT := 64
var audio_cache_order: Array[String] = []
var bgm_tween: Tween
var bgs_tween: Tween
var master_bgm_vol: float = 1.0
var master_se_vol: float = 1.0
var bgm_track_vol: float = 1.0
var bgs_track_vol: float = 1.0

var _mat_add: CanvasItemMaterial
var _mat_sub: CanvasItemMaterial
var _mat_mul: CanvasItemMaterial
var _batch_pool: Array[_BlendBatch] = []
## WOLF reissues the same BGM/BGS command from several events; restarting the same
## track from 0 s every time produced an audible stutter. Remember the file so a
## repeated play request only adjusts volume.
var bgm_file := ""
var bgs_file := ""
var se_cursor := 0
var frozen_texture: ImageTexture
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
## `key_config()` crosses the GDExtension boundary with a fresh PackedInt32Array
## every call; the six words only move when CE132 writes Sys52..57, so keep the
## converted array and refresh it from `key_config_revision()` (report II.P2).
var key_config_cache: Array = []
var key_config_revision_cache := -2

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
## Set by a window/application focus-in notification and consumed by the next
## physics tick.  That tick must not treat a button the OS already reports as
## held as a fresh edge, or regaining focus fakes a click on a map hotspot.
var focus_gained := false

var log_input := false
var log_messages := false
var log_events := false
var log_perf := false
var messages_seen := 0
var last_choice_cursor := -1
var last_choice_key := ""
var last_running: Array = []
var last_action_event := -1
var perf_frame_us_total: int = 0
var perf_wolf_us_total: int = 0
var perf_wolf_us_max: int = 0
var perf_sync_us_total: int = 0
var perf_sync_us_max: int = 0
var perf_sync_calls: int = 0
var perf_sync_uploads: int = 0
var perf_sync_bytes: int = 0
var perf_upload_us_total: int = 0
var perf_upload_us_max: int = 0
var perf_freeze_captures: int = 0
var perf_freeze_us_total: int = 0
var perf_freeze_us_max: int = 0
var perf_draw_calls: int = 0
var perf_draw_us_total: int = 0
var perf_draw_us_max: int = 0
var perf_atlas_revision: int = -1
var perf_atlas_revision_changes: int = 0
var perf_last_report_frame: int = 0


func _ready() -> void:
	var startup_started := Time.get_ticks_usec()
	texture_filter = CanvasItem.TEXTURE_FILTER_NEAREST
	_mat_add = CanvasItemMaterial.new()
	_mat_add.blend_mode = CanvasItemMaterial.BLEND_MODE_ADD
	_mat_sub = CanvasItemMaterial.new()
	_mat_sub.blend_mode = CanvasItemMaterial.BLEND_MODE_SUB
	_mat_mul = CanvasItemMaterial.new()
	_mat_mul.blend_mode = CanvasItemMaterial.BLEND_MODE_MUL
	# Parse first: the entry point and log switches are needed before the first frame.
	_parse_args()
	# The bundled font candidates live under the data root, so resolve it before
	# loading text faces.
	var root := _resolve_data_root()
	data_root = root
	var fonts_started := Time.get_ticks_usec()
	bold_font = _load_font(true)
	regular_font = _load_font(false)
	# U+266A and other symbols missing from the primary faces are shaped through
	# Font.fallbacks; TextParagraph passes the whole chain to the shaper.
	var symbol_fallback := _make_symbol_font()
	_attach_fallback(bold_font, symbol_fallback)
	_attach_fallback(regular_font, symbol_fallback)
	print("startup: godot_fonts_ms=", "%.1f" % ((Time.get_ticks_usec() - fonts_started) / 1000.0))

	if root.is_empty():
		push_error("data root not found: pass `-- --data-root=<unpacked Data dir>`")
		set_physics_process(false)
		return

	_setup_audio()
	wolf = WolfGame.new()
	var open_started := Time.get_ticks_usec()
	if not wolf.open(root):
		push_error("WolfGame.open failed: " + root)
		set_physics_process(false)
		return
	print("startup: wolf_open_ms=", "%.1f" % ((Time.get_ticks_usec() - open_started) / 1000.0))
	if auto_new_game:
		# Mirrors `wolf-cli capture --answer 0`: advance messages and answer every
		# choice with option 0 so a scripted capture reaches the daily loop.
		wolf.set_auto_play(true, 0)
		if hold_message:
			wolf.set_auto_advance(false)
		print("wolf: auto-play enabled (messages advance, choices answer 0)")
	if not load_save_path.is_empty():
		var prime_started := Time.get_ticks_usec()
		wolf.prime_engine()
		print("startup: prime_engine_ms=", "%.1f" % ((Time.get_ticks_usec() - prime_started) / 1000.0))
		var load_started := Time.get_ticks_usec()
		if not wolf.load_save(load_save_path):
			push_error("WolfGame.load_save failed: " + load_save_path)
			set_physics_process(false)
			return
		print("startup: load_save_ms=", "%.1f" % ((Time.get_ticks_usec() - load_started) / 1000.0))
	elif entry == "menu":
		# CE48/CE63 are engine coroutines, not part of CE42. Starting the title event
		# directly skips their one-time initialisation: Sys1/Sys2 stay at zero (so a
		# message renders at the top-left instead of (64,410)), the message-window
		# frame never appears, and a new game started from this menu runs without the
		# HUD/UI setup. Prime the engine exactly like the load path above.
		var prime_started := Time.get_ticks_usec()
		var primed := wolf.prime_engine()
		print("startup: prime_engine_ms=", "%.1f" % ((Time.get_ticks_usec() - prime_started) / 1000.0))
		print("wolf: prime_engine frames=", primed)
		if not wolf.start_title():
			push_error("WolfGame.start_title failed")
			set_physics_process(false)
			return
	elif not wolf.boot():
		push_error("WolfGame.boot failed")
		set_physics_process(false)
		return

	# Move first-use picture decoding and the initial atlas upload out of the
	# first visible physics frame. `prewarm_draw` is render-only; it does not
	# advance VM time or change the saved state.
	var prewarm_started := Time.get_ticks_usec()
	wolf.prewarm_draw()
	print("startup: prewarm_draw_ms=", "%.1f" % ((Time.get_ticks_usec() - prewarm_started) / 1000.0))
	var prewarm_upload_started := Time.get_ticks_usec()
	_sync_atlas()
	print("startup: prewarm_upload_ms=", "%.1f" % ((Time.get_ticks_usec() - prewarm_upload_started) / 1000.0))

	set_physics_process(true)
	print("startup: ready_ms=", "%.1f" % ((Time.get_ticks_usec() - startup_started) / 1000.0))
	queue_redraw()


func _physics_process(_delta: float) -> void:
	if wolf == null:
		return
	var frame_started := Time.get_ticks_usec()
	var mouse := get_local_mouse_position()
	var mouse_pos := Vector2i(int(mouse.x), int(mouse.y))
	# A fresh left press must hit the hotspot where it went down, even if the
	# pointer moved before this physics tick.
	if mouse_latch & 1 != 0 and mouse_latch_pos.x >= 0 and mouse_latch_pos.y >= 0:
		mouse_pos = mouse_latch_pos
	var raw_keys := _raw_key_codes()
	# Consume the focus-in marker: only the first tick after a focus-in skips the
	# level query; later ticks trust it again for genuinely held buttons.
	var skip_level := focus_gained
	focus_gained = false
	var buttons := _mouse_buttons(skip_level)
	mouse_latch = 0
	wolf.set_wheel(wheel_notches)
	wheel_notches = 0
	wolf.set_input(_key_bits(raw_keys), raw_keys, mouse_pos, buttons)
	var wolf_started := Time.get_ticks_usec()
	packet = wolf.frame()
	var wolf_us := Time.get_ticks_usec() - wolf_started
	perf_wolf_us_total += wolf_us
	perf_wolf_us_max = maxi(perf_wolf_us_max, wolf_us)
	_update_master_volumes()
	if packet.get("quit", false):
		# Opcode 175: the title's おわる option asked to exit.
		get_tree().quit()
		return
	if packet.get("freeze", false):
		print("wolf: freeze at game frame ", game_frames)
	_update_frozen_frame(packet)
	_apply_sounds(packet.get("sounds", []))
	game_frames += 1
	_log_frame()
	max_sprites = maxi(max_sprites, packet.get("sprites", []).size())
	max_texts = maxi(max_texts, packet.get("texts", []).size())
	if not sounds_logged and packet.get("sounds", []).size() > 0:
		sounds_logged = true
		print("wolf: first sound commands ", packet.get("sounds", []))

	var sync_started := Time.get_ticks_usec()
	_sync_atlas()
	var sync_us := Time.get_ticks_usec() - sync_started
	perf_sync_us_total += sync_us
	perf_sync_us_max = maxi(perf_sync_us_max, sync_us)
	perf_sync_calls += 1
	var atlas_revision := wolf.atlas_len()
	if atlas_revision != perf_atlas_revision:
		perf_atlas_revision = atlas_revision
		perf_atlas_revision_changes += 1
	if not diagnostics_printed:
		diagnostics_printed = true
		print(
			"wolf: frame sprites=", packet.get("sprites", []).size(),
			" texts=", packet.get("texts", []).size(),
			" pictures=", packet.get("pictures", 0),
		)
		for line in packet.get("diagnostics", []):
			print("wolf: ", line)
		for sprite in packet.get("sprites", []):
			var rect: Rect2 = sprite["rect"]
			if rect.size.x * rect.size.y > 200000.0:
				print("wolf:   large sprite #", sprite.get("number", 0), " rect=", rect, " src=", sprite["src"], " alpha=", sprite["alpha"], " tint=", sprite["tint"])
	queue_redraw()
	perf_frame_us_total += Time.get_ticks_usec() - frame_started
	if log_perf and game_frames - perf_last_report_frame >= 60:
		perf_last_report_frame = game_frames
		_print_perf_window()


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
	if what == NOTIFICATION_WM_WINDOW_FOCUS_IN or what == NOTIFICATION_APPLICATION_FOCUS_IN:
		# The OS may report a button as already held on the frame the window comes
		# back; let the next physics tick ignore that level so it cannot become a
		# synthetic edge press on a hotspot.
		focus_gained = true
	elif what == NOTIFICATION_WM_WINDOW_FOCUS_OUT or what == NOTIFICATION_APPLICATION_FOCUS_OUT:
		# Without focus the key-up events never arrive; a stale held key would
		# otherwise look pressed forever.
		held_keys.clear()
		held_order.clear()
		mouse_down = 0
		mouse_latch = 0
		mouse_latch_pos = Vector2i(-1, -1)
		wheel_notches = 0
		focus_gained = false
	elif what == NOTIFICATION_WM_CLOSE_REQUEST:
		_save_settings_on_exit()


func _exit_tree() -> void:
	_save_settings_on_exit()


func _save_settings_on_exit() -> void:
	if wolf != null:
		wolf.save_settings()


func _unhandled_input(event: InputEvent) -> void:
	if event is InputEventKey and event.pressed and not event.echo and event.keycode == KEY_F11:
		if DisplayServer.window_get_mode() == DisplayServer.WINDOW_MODE_FULLSCREEN:
			DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_WINDOWED)
		else:
			DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_FULLSCREEN)


func _process(_delta: float) -> void:
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
	if log_perf:
		print(
			"capture-layers: overlays=", packet.get("overlays", []),
			" sprites=", packet.get("sprites", []).size(),
		)
		for sprite in packet.get("sprites", []):
			print(
				"capture-sprite: number=", sprite.get("number", 0),
				" z=", sprite.get("z", sprite.get("number", 0)),
				" rect=", sprite.get("rect", Rect2()),
				" src=", sprite.get("src", Rect2()),
				" alpha=", sprite.get("alpha", 0.0),
				" tint=", sprite.get("tint", Color.WHITE),
				" blend=", sprite.get("blend", 0),
			)
		for text in packet.get("texts", []):
			print(
				"capture-text: number=", text.get("number", 0),
				" z=", text.get("z", text.get("number", 0)),
				" rect=", text.get("rect", Rect2()),
				" text=", text.get("text", ""),
			)
		if atlas_texture != null:
			var atlas_err := atlas_texture.get_image().save_png(target + ".atlas.png")
			print("capture-atlas: err=", atlas_err, " path=", target + ".atlas.png")
	for line in packet.get("diagnostics", []):
		print("wolf-diag: ", line)
	get_tree().quit()


func _draw() -> void:
	var draw_started := Time.get_ticks_usec()
	perf_draw_calls += 1
	draw_rect(Rect2(Vector2.ZERO, LOGICAL_SIZE), Color.BLACK)
	if atlas_texture == null:
		_record_draw_time(draw_started)
		return

	# Pictures and text share ONE layer stack keyed by WOLF picture slot. Drawing all
	# sprites and then all texts put the HUD (slots 200..252) over the save window
	# (12000+), which is the "top-bar values bleed through the save menu" bug. Entries
	# of the engine's own menu chrome carry z = 1_000_000 so they stay above pictures.
	var sprites: Array = packet.get("sprites", [])
	var texts: Array = packet.get("texts", [])
	var overlays: Array = packet.get("overlays", [])
	var items: Array = []
	var seq := 0
	var has_blends := false
	for sprite in sprites:
		if int(sprite.get("blend", 0)) != 0:
			has_blends = true
		items.append({"sprite": sprite, "z": int(sprite.get("z", sprite.get("number", 0))), "seq": seq})
		seq += 1
	for text in texts:
		items.append({"text": text, "z": int(text.get("z", text.get("number", 0))), "seq": seq})
		seq += 1
	items.sort_custom(_draw_item_before)

	if not has_blends:
		for batch in _batch_pool:
			batch.items.clear()
			batch.overlays.clear()
			batch.ap = {}
			batch.frozen_texture = null
			batch.visible = false
		for item in items:
			if item.has("sprite"):
				var sprite: Dictionary = item["sprite"]
				var tint: Color = sprite["tint"]
				tint.a *= float(sprite["alpha"])
				if tint.a <= 0.0:
					continue
				draw_texture_rect_region(atlas_texture, sprite["rect"], sprite["src"], tint)
			else:
				_draw_text(item["text"])

		_draw_action_points(packet.get("ap", {}))
		for overlay in overlays:
			var colour: Color = overlay["color"]
			colour.a *= float(overlay["alpha"])
			if overlay["kind"] == "colour" and colour.a > 0.0:
				draw_rect(Rect2(Vector2.ZERO, LOGICAL_SIZE), colour)
			elif overlay["kind"] == "frozen" and frozen_texture != null and colour.a > 0.0:
				draw_texture_rect(frozen_texture, Rect2(Vector2.ZERO, LOGICAL_SIZE), false, colour)
		_record_draw_time(draw_started)
		return

	# Mixed-blend path (whenever ANY sprite has blend in 1, 2, 3)
	# GameView._draw() draws ONLY the black background.
	# Group items into contiguous batches where all items in a batch share the same blend.
	var batches: Array[Dictionary] = []
	var current_blend := -1
	var current_items: Array = []
	for item in items:
		var item_blend := 0
		if item.has("sprite"):
			item_blend = int(item["sprite"].get("blend", 0))
		if item_blend != current_blend:
			if not current_items.is_empty():
				batches.append({
					"blend": current_blend,
					"items": current_items,
					"overlays": [],
					"ap": {},
				})
				current_items = []
			current_blend = item_blend
		current_items.append(item)
	if not current_items.is_empty():
		batches.append({
			"blend": current_blend,
			"items": current_items,
			"overlays": [],
			"ap": {},
		})

	_append_action_bar_and_overlays(batches, overlays, packet.get("ap", {}))

	# Acquire / reuse _BlendBatch child nodes from _batch_pool
	while _batch_pool.size() < batches.size():
		var new_batch := _BlendBatch.new()
		new_batch.name = "BatchLayer%d" % _batch_pool.size()
		add_child(new_batch)
		_batch_pool.append(new_batch)

	for i in range(batches.size()):
		var b_info: Dictionary = batches[i]
		var batch := _batch_pool[i]
		if i > 0 and batch.get_index() < _batch_pool[i - 1].get_index():
			move_child(batch, _batch_pool[i - 1].get_index() + 1)
		batch.material = _material_for_blend(b_info["blend"])
		batch.items = b_info["items"]
		batch.overlays = b_info["overlays"]
		batch.atlas = atlas_texture
		batch.bold_font = bold_font
		batch.regular_font = regular_font
		batch.frozen_texture = frozen_texture
		batch.ap = b_info["ap"]
		batch.visible = true
		batch.queue_redraw()

	for i in range(batches.size(), _batch_pool.size()):
		var unused := _batch_pool[i]
		unused.items.clear()
		unused.overlays.clear()
		unused.ap = {}
		unused.frozen_texture = null
		unused.visible = false
	_record_draw_time(draw_started)


func _record_draw_time(started: int) -> void:
	var draw_us := Time.get_ticks_usec() - started
	perf_draw_us_total += draw_us
	perf_draw_us_max = maxi(perf_draw_us_max, draw_us)


## Energy and screen overlays must use normal blending even when the last sprite
## batch is ADD/SUB/MUL. Otherwise the white stamina bar inherits the preceding
## material and can disappear behind an effect.
func _append_action_bar_and_overlays(
	batches: Array[Dictionary],
	overlays: Array,
	ap: Dictionary
) -> void:
	if overlays.is_empty() and ap.is_empty():
		return
	if not batches.is_empty() and batches[-1]["blend"] == 0:
		batches[-1]["overlays"] = overlays
		batches[-1]["ap"] = ap
		return
	batches.append({
		"blend": 0,
		"items": [],
		"overlays": overlays,
		"ap": ap,
	})


func _draw_text(item: Dictionary) -> void:
	WolfTextScript.draw_text(self, item, bold_font, regular_font)


func _draw_item_before(a: Dictionary, b: Dictionary) -> bool:
	if a["z"] == b["z"]:
		return a["seq"] < b["seq"]
	return a["z"] < b["z"]


func _draw_action_points(ap: Dictionary) -> void:
	if ap.is_empty():
		return
	var maximum := maxi(1, int(ap.get("max", 0)))
	var current := clampi(int(ap.get("current", 0)), 0, maximum)
	var box: Rect2 = ap.get("bar", Rect2(Vector2(593.0, 18.0), Vector2(100.0, 12.0)))
	# Reference (`参照图仅参考行动力条.png`): a dark trough with a thin light
	# border and a 1 px-inset soft grey fill, not the old 2 px-inset white slab.
	draw_rect(box, Color(0.16, 0.16, 0.16, 0.92), true)
	draw_rect(box, Color(0.78, 0.78, 0.78, 1.0), false, 1.0)
	var ratio := float(current) / float(maximum)
	if ratio > 0.0:
		draw_rect(
			Rect2(
				box.position + Vector2(1.0, 1.0),
				Vector2((box.size.x - 2.0) * ratio, box.size.y - 2.0)
			),
			Color(0.82, 0.82, 0.82, 0.95),
			true
		)


func _gain_to_db(gain: float) -> float:
	if gain <= 0.0001:
		return -80.0
	return linear_to_db(gain)


func _update_master_volumes() -> void:
	var new_bgm_vol := clampf(float(packet.get("bgm_volume", 100)) / 100.0, 0.0, 1.2)
	var new_se_vol := clampf(float(packet.get("se_volume", 100)) / 100.0, 0.0, 1.2)
	var bgm_vol_changed := not is_equal_approx(new_bgm_vol, master_bgm_vol)
	var se_vol_changed := not is_equal_approx(new_se_vol, master_se_vol)
	master_bgm_vol = new_bgm_vol
	master_se_vol = new_se_vol
	if bgm_vol_changed and bgm_player != null and bgm_player.playing and (bgm_tween == null or not bgm_tween.is_valid()):
		bgm_player.volume_db = _gain_to_db(bgm_track_vol * master_bgm_vol)
	# In WOLF RPG Editor and wolf-audio mixer.rs (line 392), BGS ambience is mixed on the BGM volume bus.
	if bgm_vol_changed and bgs_player != null and bgs_player.playing and (bgs_tween == null or not bgs_tween.is_valid()):
		bgs_player.volume_db = _gain_to_db(bgs_track_vol * master_bgm_vol)


func _material_for_blend(blend: int) -> CanvasItemMaterial:
	match blend:
		1:
			return _mat_add
		2:
			return _mat_sub
		3:
			return _mat_mul
		_:
			return null


func _setup_audio() -> void:
	bgm_player = AudioStreamPlayer.new()
	bgm_player.name = "Bgm"
	add_child(bgm_player)
	bgs_player = AudioStreamPlayer.new()
	bgs_player.name = "Bgs"
	add_child(bgs_player)
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
		var track_vol := clampf(float(cmd.get("volume", 100)) / 100.0, 0.0, 1.0)
		var pitch := clampf(float(cmd.get("pitch", 100)) / 100.0, 0.1, 4.0)
		var frames := int(cmd.get("frames", 0))
		if channel == "bgm":
			if action == "play":
				if file.is_empty():
					continue
				bgm_track_vol = track_vol
				var effective := bgm_track_vol * master_bgm_vol
				bgm_player.pitch_scale = pitch
				# Several events reissue the current track. Restarting it from 0 s was
				# the audible stutter; keep the running voice and only refresh volume.
				if file == bgm_file and bgm_player.playing:
					if bgm_tween != null and bgm_tween.is_valid():
						bgm_tween.kill()
					bgm_player.volume_db = _gain_to_db(effective)
					continue
				var stream := _load_audio(file)
				if stream == null:
					continue
				_mark_bgm_loop(stream)
				if bgm_tween != null and bgm_tween.is_valid():
					bgm_tween.kill()
				bgm_player.stream = stream
				bgm_player.volume_db = -80.0 if frames > 0 else _gain_to_db(effective)
				bgm_player.play()
				bgm_file = file
				if frames > 0:
					bgm_tween = create_tween()
					bgm_tween.tween_property(bgm_player, "volume_db", _gain_to_db(effective), float(frames) / 60.0)
			elif action == "stop":
				bgm_file = ""
				if bgm_tween != null and bgm_tween.is_valid():
					bgm_tween.kill()
				if frames > 0:
					bgm_tween = create_tween()
					bgm_tween.tween_property(bgm_player, "volume_db", -80.0, float(frames) / 60.0)
					bgm_tween.tween_callback(bgm_player.stop)
				else:
					bgm_player.stop()
		elif channel == "bgs":
			if action == "play":
				if file.is_empty():
					continue
				bgs_track_vol = track_vol
				var effective := bgs_track_vol * master_bgm_vol
				bgs_player.pitch_scale = pitch
				if file == bgs_file and bgs_player.playing:
					if bgs_tween != null and bgs_tween.is_valid():
						bgs_tween.kill()
					bgs_player.volume_db = _gain_to_db(effective)
					continue
				var stream := _load_audio(file)
				if stream == null:
					continue
				_mark_bgm_loop(stream)
				if bgs_tween != null and bgs_tween.is_valid():
					bgs_tween.kill()
				bgs_player.stream = stream
				bgs_player.volume_db = -80.0 if frames > 0 else _gain_to_db(effective)
				bgs_player.play()
				bgs_file = file
				if frames > 0:
					bgs_tween = create_tween()
					bgs_tween.tween_property(bgs_player, "volume_db", _gain_to_db(effective), float(frames) / 60.0)
			elif action == "stop":
				bgs_file = ""
				if bgs_tween != null and bgs_tween.is_valid():
					bgs_tween.kill()
				if frames > 0:
					bgs_tween = create_tween()
					bgs_tween.tween_property(bgs_player, "volume_db", -80.0, float(frames) / 60.0)
					bgs_tween.tween_callback(bgs_player.stop)
				else:
					bgs_player.stop()
		elif channel == "se":
			if action == "play":
				var stream := _load_audio(file)
				if stream == null:
					continue
				var player := _free_se_player()
				player.stream = stream
				player.pitch_scale = pitch
				var effective := track_vol * master_se_vol
				player.volume_db = _gain_to_db(effective)
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
	audio_cache_order.append(path)
	_prune_audio_cache()
	return stream


func _audio_in_use(stream: AudioStream) -> bool:
	if bgm_player != null and bgm_player.stream == stream:
		return true
	if bgs_player != null and bgs_player.stream == stream:
		return true
	for player in se_players:
		if player.stream == stream:
			return true
	return false


func _prune_audio_cache() -> void:
	if audio_cache.size() <= AUDIO_CACHE_LIMIT:
		return
	var index := 0
	while audio_cache.size() > AUDIO_CACHE_LIMIT and index < audio_cache_order.size():
		var path: String = audio_cache_order[index]
		var stream: AudioStream = audio_cache.get(path)
		if stream != null and _audio_in_use(stream):
			index += 1
			continue
		audio_cache.erase(path)
		audio_cache_order.remove_at(index)


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


## 161 freezes the frame already on screen.  Capture it once and keep that texture
## for the whole 162 dissolve; re-reading the viewport on every active frame is a
## full-screen GPU sync and turns a ten-frame fade into ten stalls.
func _update_frozen_frame(packet: Dictionary) -> void:
	if packet.get("freeze", false):
		_capture_frozen_frame()
	if (
		not packet.get("transition_active", false)
		and not packet.get("freeze", false)
		and not _has_frozen_overlay(packet)
	):
		_clear_frozen_frame()


func _capture_frozen_frame() -> void:
	var started := Time.get_ticks_usec()
	var previous := get_viewport().get_texture().get_image()
	# A second 161 can arrive before the first dissolve has fully cleared the
	# snapshot. Refresh it rather than keeping the old scene; reuse the GPU
	# texture when the viewport size is unchanged.
	if frozen_texture != null and Vector2i(frozen_texture.get_size()) == previous.get_size():
		frozen_texture.update(previous)
	else:
		frozen_texture = ImageTexture.create_from_image(previous)
	perf_freeze_captures += 1
	var freeze_us := Time.get_ticks_usec() - started
	perf_freeze_us_total += freeze_us
	perf_freeze_us_max = maxi(perf_freeze_us_max, freeze_us)


func _clear_frozen_frame() -> void:
	frozen_texture = null


func _sync_atlas() -> void:
	var generation := wolf.atlas_len()
	if generation == atlas_len and atlas_texture != null:
		return
	var upload_started := Time.get_ticks_usec()
	atlas_len = generation
	var size := wolf.atlas_size()
	if size.x <= 0 or size.y <= 0:
		atlas_texture = null
		atlas_pixel_size = Vector2i.ZERO
		return
	var bytes := wolf.atlas_pixels()
	var expected := size.x * size.y * 4
	if bytes.size() != expected:
		push_error(
			"atlas byte count %d does not match %dx%d RGBA (%d)"
			% [bytes.size(), size.x, size.y, expected]
		)
		atlas_texture = null
		atlas_pixel_size = Vector2i.ZERO
		return
	var image := Image.create_from_data(size.x, size.y, false, Image.FORMAT_RGBA8, bytes)
	if atlas_texture == null or atlas_pixel_size != size:
		atlas_texture = ImageTexture.create_from_image(image)
		atlas_pixel_size = size
	else:
		# Reuse the GPU texture: interaction-heavy screens add many UI entries, and a
		# fresh 64 MiB allocation for each one is a visible hitch.
		atlas_texture.update(image)
	perf_sync_uploads += 1
	perf_sync_bytes += bytes.size()
	var upload_us := Time.get_ticks_usec() - upload_started
	perf_upload_us_total += upload_us
	perf_upload_us_max = maxi(perf_upload_us_max, upload_us)


func _print_perf_window() -> void:
	var denominator := maxi(1, game_frames)
	print(
		"perf: frames=", game_frames,
		" wolf_avg_ms=", "%.3f" % (float(perf_wolf_us_total) / 1000.0 / denominator),
		" wolf_max_ms=", "%.3f" % (float(perf_wolf_us_max) / 1000.0),
		" sync_calls=", perf_sync_calls,
		" sync_uploads=", perf_sync_uploads,
		" sync_MiB=", "%.1f" % (float(perf_sync_bytes) / 1048576.0),
		" sync_avg_ms=", "%.3f" % (float(perf_sync_us_total) / 1000.0 / maxi(1, perf_sync_calls)),
		" sync_max_ms=", "%.3f" % (float(perf_sync_us_max) / 1000.0),
		" upload_avg_ms=", "%.3f" % (float(perf_upload_us_total) / 1000.0 / maxi(1, perf_sync_uploads)),
		" upload_max_ms=", "%.3f" % (float(perf_upload_us_max) / 1000.0),
		" freeze_captures=", perf_freeze_captures,
		" freeze_avg_ms=", "%.3f" % (float(perf_freeze_us_total) / 1000.0 / maxi(1, perf_freeze_captures)),
		" freeze_max_ms=", "%.3f" % (float(perf_freeze_us_max) / 1000.0),
		" atlas_revision_changes=", perf_atlas_revision_changes,
		" draw_calls=", perf_draw_calls,
		" draw_avg_ms=", "%.3f" % (float(perf_draw_us_total) / 1000.0 / maxi(1, perf_draw_calls)),
		" draw_max_ms=", "%.3f" % (float(perf_draw_us_max) / 1000.0),
		" physics_avg_ms=", "%.3f" % (float(perf_frame_us_total) / 1000.0 / denominator),
	)


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
		elif arg == "--log-perf":
			log_perf = true


## Load the bold or regular UI face.
##
## Candidate order: the Windows Microsoft YaHei file, the faces bundled in the
## data root, then a SystemFont lookup.  A SystemFont is always constructible, so
## this never returns null and text never disappears on a host without YaHei.
## Every departure from the first choice is logged, including which candidate won.
func _load_font(is_bold: bool) -> Font:
	var kind := "bold" if is_bold else "regular"
	var candidates: Array[String] = []
	candidates.append(WINDOWS_FONT_BOLD if is_bold else WINDOWS_FONT_REGULAR)
	if not data_root.is_empty():
		for name in BUNDLED_FONT_NAMES:
			candidates.append(data_root.path_join(name))
	for path in candidates:
		if not FileAccess.file_exists(path):
			continue
		var font := FontFile.new()
		if font.load_dynamic_font(path) != OK:
			push_warning("font: cannot load %s" % path)
			continue
		print("font: %s <- %s" % [kind, path])
		return font
	var system := SystemFont.new()
	system.font_names = PackedStringArray(SYSTEM_FONT_NAMES)
	system.font_weight = 700 if is_bold else 400
	system.allow_system_fallback = true
	push_warning(
		"font: no font file for %s, using SystemFont %s" % [kind, str(SYSTEM_FONT_NAMES)]
	)
	return system


## Symbol-only face used through `Font.fallbacks`.  It only contributes glyphs the
## primary face lacks (U+266A in Microsoft YaHei), so its metrics do not replace
## the primary face's line metrics.
func _make_symbol_font() -> Font:
	var symbol := SystemFont.new()
	symbol.font_names = PackedStringArray(SYMBOL_FONT_NAMES)
	symbol.allow_system_fallback = true
	return symbol


## Append `fallback` to `font`'s existing chain instead of replacing it.
func _attach_fallback(font: Font, fallback: Font) -> void:
	if font == null or fallback == null:
		return
	var chain: Array[Font] = []
	for existing in font.fallbacks:
		chain.append(existing)
	if not chain.has(fallback):
		chain.append(fallback)
	font.fallbacks = chain


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
	var revision := wolf.key_config_revision()
	if revision != key_config_revision_cache:
		key_config_revision_cache = revision
		key_config_cache = Array(wolf.key_config())
	return WolfKeysLib.bits_for(Array(raw_keys), key_config_cache)


func _mouse_buttons(skip_level: bool = false) -> int:
	# Event-tracked state plus a latch for a click that was pressed and released
	# entirely between two physics ticks; the level query is a fallback for a
	# button that was already held when the window gained focus.  That fallback is
	# suppressed for the first tick after focus-in, where a held button would
	# otherwise look like a brand-new click.
	var buttons := mouse_down | mouse_latch
	if skip_level:
		return buttons
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
