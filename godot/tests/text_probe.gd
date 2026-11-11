extends SceneTree

## Text-metric probe for the Godot front-end.
##
## Modes (after `--`):
##   --mode=api      dump TextParagraph / TextServer / Font method lists
##   --mode=metrics  print FontFile ascent/descent/height, shaped-text and
##                   TextParagraph line metrics (headless, no pixels)
##   --mode=ruler    windowed: draw a ruler sheet (single/two-line text, outline,
##                   integer and fractional baselines) and capture it
##   --mode=items    run the game headless and dump packet["texts"] as JSON
##   --mode=check    verify WolfText.gd's baseline/line-spacing constants
##                   against the ruler measurement table (headless)
##   --mode=pair     windowed: run the game to a frame, draw the packet with the
##                   old GameView logic and with scripts/WolfText.gd, capture both
##
## Common args: --out=<png> --data-root=<dir> --entry=menu --auto-new-game
##              --hold-message --load-save=<sav> --frames=<n>
## Ruler args:  --sizes=14,16,18,20 --cols=1

const FONT_BOLD := "C:/Windows/Fonts/msyhbd.ttc"
const FONT_REGULAR := "C:/Windows/Fonts/msyh.ttc"
const LOGICAL := Vector2(1024.0, 576.0)

var mode := "metrics"
var out_path := ""
var data_root := ""
var entry := "menu"
var auto_new_game := false
var hold_message := false
var load_save := ""
var frames := 600
var sizes: Array = [14, 16, 18, 20, 24, 30]
var cols := 1
var hinting := -1
var subpixel := -1
var antialias := -1
var canvas: Control
var bold_font: FontFile
var regular_font: FontFile
var packet: Dictionary = {}
var atlas_texture: ImageTexture
var draw_mode := "old"


class Ruler:
	extends Control
	var ops: Array = []

	func _draw() -> void:
		draw_rect(Rect2(Vector2.ZERO, Vector2(1024.0, 576.0)), Color.BLACK)
		for op in ops:
			if op["kind"] == "line":
				draw_line(op["a"], op["b"], op["colour"], 1.0)
			elif op["kind"] == "text":
				var paragraph := TextParagraph.new()
				paragraph.width = op["width"]
				paragraph.line_spacing = op["spacing"]
				paragraph.add_string(op["text"], op["font"], int(op["size"]))
				if op["outline"] > 0:
					paragraph.draw_outline(
						get_canvas_item(), Vector2(op["x"], op["y"]), op["outline"], op["outline_colour"]
					)
				paragraph.draw(get_canvas_item(), Vector2(op["x"], op["y"]), op["colour"])


func _init() -> void:
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--mode="):
			mode = arg.substr("--mode=".length())
		elif arg.begins_with("--out="):
			out_path = arg.substr("--out=".length())
		elif arg.begins_with("--data-root="):
			data_root = arg.substr("--data-root=".length())
		elif arg.begins_with("--entry="):
			entry = arg.substr("--entry=".length())
		elif arg.begins_with("--load-save="):
			load_save = arg.substr("--load-save=".length())
		elif arg == "--auto-new-game":
			auto_new_game = true
		elif arg == "--hold-message":
			hold_message = true
		elif arg.begins_with("--frames="):
			frames = int(arg.substr("--frames=".length()))
		elif arg.begins_with("--sizes="):
			sizes = []
			for part in arg.substr("--sizes=".length()).split(","):
				sizes.append(int(part))
		elif arg.begins_with("--cols="):
			cols = int(arg.substr("--cols=".length()))
		elif arg.begins_with("--hinting="):
			hinting = int(arg.substr("--hinting=".length()))
		elif arg.begins_with("--subpixel="):
			subpixel = int(arg.substr("--subpixel=".length()))
		elif arg.begins_with("--antialias="):
			antialias = int(arg.substr("--antialias=".length()))
	bold_font = _load_font(FONT_BOLD)
	regular_font = _load_font(FONT_REGULAR)
	for font in [bold_font, regular_font]:
		if font == null:
			continue
		if hinting >= 0:
			font.hinting = hinting
		if subpixel >= 0:
			font.subpixel_positioning = subpixel
		if antialias >= 0:
			font.antialiasing = antialias
	if mode == "api":
		_dump_api()
		quit(0)
		return
	if mode == "metrics":
		_run_metrics()
		quit(0)
		return
	if mode == "items":
		_run_items()
		quit(0)
		return
	if mode == "check":
		quit(0 if _run_check() else 1)
		return
	canvas = Control.new()
	canvas.name = "ProbeCanvas"
	root.add_child(canvas)
	_run_async.call_deferred()


func _load_font(path: String) -> FontFile:
	var font := FontFile.new()
	if font.load_dynamic_font(path) != OK:
		push_error("text_probe: cannot load " + path)
		return null
	return font


func _dump_api() -> void:
	for cls in ["TextParagraph"]:
		var methods: Array = []
		for m in ClassDB.class_get_method_list(cls):
			methods.append(m["name"])
		print("== ", cls, ": ", " ".join(methods))


func _run_metrics() -> void:
	print("font bold: ", bold_font.get_font_name(), " / ", bold_font.get_font_style_name())
	print("font regular: ", regular_font.get_font_name(), " / ", regular_font.get_font_style_name())
	print(
		"font props: hinting=", bold_font.hinting,
		" subpixel=", bold_font.subpixel_positioning,
		" antialias=", bold_font.antialiasing,
		" oversampling=", bold_font.oversampling
	)
	for size in sizes:
		print(
			"font  size=", size,
			" bold ascent=", bold_font.get_ascent(size),
			" descent=", bold_font.get_descent(size),
			" height=", bold_font.get_height(size),
			" regular ascent=", regular_font.get_ascent(size),
			" descent=", regular_font.get_descent(size),
			" height=", regular_font.get_height(size)
		)
	for size in sizes:
		for spacing in [0.0, float(size) * 0.25, float(size) + 3.0 - bold_font.get_height(size)]:
			for body in ["H", "H\nH"]:
				var p := TextParagraph.new()
				p.width = 400.0
				p.line_spacing = spacing
				p.add_string(body, bold_font, size)
				var lines: Array = []
				for line in range(p.get_line_count()):
					lines.append(
						[line, p.get_line_ascent(line), p.get_line_descent(line), p.get_line_size(line)]
					)
				print(
					"para size=", size, " spacing=", spacing, " body=", body.length(),
					" count=", p.get_line_count(), " size=", p.get_size(),
					" nonwrapped=", p.get_non_wrapped_size(), " lines=", lines
				)


func _run_items() -> void:
	var wolf := _make_game()
	if wolf == null:
		quit(1)
		return
	for _i in range(frames):
		packet = wolf.frame()
	_dump_packet_texts()


## Cross-check WolfText.gd's constants against the measured values.
func _run_check() -> bool:
	var script: GDScript = load("res://scripts/WolfText.gd")
	if script == null:
		push_error("check: cannot load WolfText.gd")
		return false
	var ok := true
	var table: Dictionary = script.BASELINE_SHIFT
	for size in range(4, 65):
		var expect: int = table.get(size, 2147483647)
		var bold: int = script.baseline_shift(bold_font, float(size))
		var regular: int = script.baseline_shift(regular_font, float(size))
		if bold != expect or regular != expect:
			push_error(
				"check: size %d shift bold=%d regular=%d expected=%d" % [size, bold, regular, expect]
			)
			ok = false
	var pitch: float = script.line_pitch(20.0)
	var spacing: float = script.line_spacing(bold_font, 20.0)
	if not is_equal_approx(pitch, 25.0) or not is_equal_approx(spacing, -3.0):
		push_error("check: size 20 pitch=%.3f spacing=%.3f expected 25/-3" % [pitch, spacing])
		ok = false
	print(
		"check: baseline table sizes 4..64 ",
		("PASS" if ok else "FAIL"),
		" | size20 shift=", script.baseline_shift(bold_font, 20.0),
		" pitch=", pitch, " spacing=", spacing,
		" | size14 shift=", script.baseline_shift(bold_font, 14.0),
		" size16=", script.baseline_shift(bold_font, 16.0),
		" size24=", script.baseline_shift(bold_font, 24.0),
		" size32=", script.baseline_shift(bold_font, 32.0)
	)
	return ok


func _make_game() -> WolfGame:
	if data_root.is_empty():
		push_error("text_probe: pass --data-root=<unpacked Data dir>")
		return null
	var wolf := WolfGame.new()
	if not wolf.open(data_root):
		push_error("text_probe: WolfGame.open failed: " + data_root)
		return null
	if auto_new_game:
		wolf.set_auto_play(true, 0)
		if hold_message:
			wolf.set_auto_advance(false)
	if not load_save.is_empty():
		wolf.prime_engine()
		if not wolf.load_save(load_save):
			push_error("text_probe: load_save failed: " + load_save)
			return null
	elif entry == "menu":
		if not wolf.start_title():
			push_error("text_probe: start_title failed")
			return null
	elif not wolf.boot():
		push_error("text_probe: boot failed")
		return null
	return wolf


func _dump_packet_texts() -> void:
	print("texts: ", packet.get("texts", []).size())
	for item in packet.get("texts", []):
		var colour: Color = item.get("colour", Color.WHITE)
		var rect: Rect2 = item.get("rect", Rect2())
		print(
			"item|text=", JSON.stringify(str(item.get("text", ""))),
			"|rect=", rect.position.x, ",", rect.position.y, ",", rect.size.x, ",", rect.size.y,
			"|font_px=", item.get("font_px", 0.0),
			"|weight=", item.get("weight", 700),
			"|outline=", item.get("outline", false),
			"|alpha=", item.get("alpha", 1.0),
			"|colour=", colour.to_html(false)
		)


func _run_async() -> void:
	await process_frame
	if mode == "ruler":
		_draw_ruler()
		await process_frame
		await _capture(out_path)
		quit(0)
		return
	if mode == "pair":
		await _run_pair()
		quit(0)
		return
	push_error("text_probe: unknown mode " + mode)
	quit(1)


func _draw_ruler() -> void:
	var ruler := Ruler.new()
	ruler.name = "Ruler"
	ruler.size = LOGICAL
	root.add_child(ruler)
	var row := 78
	for index in range(sizes.size()):
		var size: int = sizes[index]
		var y := 20.0 + float(index % 6) * float(row)
		var x := 20.0 + float(index / 6) * 500.0
		if index / 6 >= cols:
			continue
		# Red line marks the paragraph origin (rect top).
		ruler.ops.append({
			"kind": "line", "a": Vector2(x, y), "b": Vector2(x + 200.0, y),
			"colour": Color(1, 0, 0),
		})
		# Single line, spacing 0: baseline probe via 'H' ink bottom.
		ruler.ops.append({
			"kind": "text", "text": "H", "x": x, "y": y, "size": size, "font": bold_font,
			"width": 200.0, "spacing": 0.0, "outline": 0,
			"colour": Color.WHITE, "outline_colour": Color.BLACK,
		})
		# Two lines, spacing 0: pitch probe.
		ruler.ops.append({
			"kind": "text", "text": "H\nH", "x": x + 60.0, "y": y, "size": size, "font": bold_font,
			"width": 200.0, "spacing": 0.0, "outline": 0,
			"colour": Color.WHITE, "outline_colour": Color.BLACK,
		})
		# Two lines with the GameView spacing approximation.
		ruler.ops.append({
			"kind": "text", "text": "H\nH", "x": x + 120.0, "y": y, "size": size, "font": bold_font,
			"width": 200.0, "spacing": float(size) * 0.25, "outline": 0,
			"colour": Color(0.6, 1.0, 0.6), "outline_colour": Color.BLACK,
		})
		# Outline ring: white body / black body with white 2 px ring.
		ruler.ops.append({
			"kind": "text", "text": "H", "x": x + 180.0, "y": y, "size": size, "font": bold_font,
			"width": 100.0, "spacing": 0.0, "outline": 0,
			"colour": Color.WHITE, "outline_colour": Color.BLACK,
		})
		ruler.ops.append({
			"kind": "text", "text": "H", "x": x + 240.0, "y": y, "size": size, "font": bold_font,
			"width": 100.0, "spacing": 0.0, "outline": 2,
			"colour": Color.BLACK, "outline_colour": Color.WHITE,
		})
	# Fractional-origin probes at one size.
	var fy := 500.0
	for frac in [0.0, 0.25, 0.5, 0.75]:
		ruler.ops.append({
			"kind": "text", "text": "H", "x": 20.0 + frac * 180.0, "y": fy + frac, "size": 20,
			"font": bold_font, "width": 100.0, "spacing": 0.0, "outline": 0,
			"colour": Color.WHITE, "outline_colour": Color.BLACK,
		})
	# Outline stroke widths 1..4 at size 20: black body, white ring on black.
	var ox := 560.0
	for stroke in [1, 2, 3, 4]:
		ruler.ops.append({
			"kind": "text", "text": "H", "x": ox, "y": 520.0, "size": 20,
			"font": bold_font, "width": 100.0, "spacing": 0.0, "outline": stroke,
			"colour": Color.BLACK, "outline_colour": Color.WHITE,
		})
		ox += 100.0
	ruler.queue_redraw()


func _capture(path: String) -> void:
	await RenderingServer.frame_post_draw
	if path.is_empty():
		return
	var image := root.get_texture().get_image()
	var target := path
	if not target.is_absolute_path():
		target = ProjectSettings.globalize_path(target)
	var err := image.save_png(target)
	print("text_probe: capture ", target, " err=", err, " size=", image.get_size())


func _run_pair() -> void:
	var wolf := _make_game()
	if wolf == null:
		quit(1)
		return
	for _i in range(frames):
		packet = wolf.frame()
	_sync_atlas(wolf)
	_dump_packet_texts()
	var pair := PairDraw.new()
	pair.name = "PairDraw"
	pair.size = LOGICAL
	pair.packet = packet
	pair.atlas = atlas_texture
	pair.bold = bold_font
	pair.regular = regular_font
	pair.wolf_text = load("res://scripts/WolfText.gd")
	root.add_child(pair)
	pair.mode = "old"
	pair.queue_redraw()
	await process_frame
	await _capture(out_path.get_basename() + "_old.png")
	pair.mode = "new"
	pair.queue_redraw()
	await process_frame
	await _capture(out_path.get_basename() + "_new.png")
	pair.mode = "none"
	pair.queue_redraw()
	await process_frame
	await _capture(out_path.get_basename() + "_none.png")


func _sync_atlas(wolf: WolfGame) -> void:
	var size: Vector2i = wolf.atlas_size()
	var bytes: PackedByteArray = wolf.atlas_pixels()
	var image := Image.create_from_data(size.x, size.y, false, Image.FORMAT_RGBA8, bytes)
	atlas_texture = ImageTexture.create_from_image(image)


class PairDraw:
	extends Control
	var packet: Dictionary = {}
	var atlas: ImageTexture
	var bold: FontFile
	var regular: FontFile
	var wolf_text
	var mode := "old"

	func _draw() -> void:
		draw_rect(Rect2(Vector2.ZERO, Vector2(1024.0, 576.0)), Color.BLACK)
		if atlas == null:
			return
		texture_filter = CanvasItem.TEXTURE_FILTER_NEAREST
		for sprite in packet.get("sprites", []):
			var tint: Color = sprite["tint"]
			tint.a *= float(sprite["alpha"])
			if tint.a <= 0.0:
				continue
			draw_texture_rect_region(atlas, sprite["rect"], sprite["src"], tint)
		if mode == "none":
			return
		for item in packet.get("texts", []):
			if mode == "new" and wolf_text != null:
				wolf_text.draw_text(self, item, bold, regular)
			else:
				_draw_old(item)

	func _draw_old(item: Dictionary) -> void:
		var text: String = item.get("text", "")
		if text.is_empty():
			return
		var font: FontFile = bold
		if int(item.get("weight", 700)) < 600:
			font = regular
		if font == null:
			return
		var size := float(item.get("font_px", 0.0))
		if size <= 0.0:
			size = 20.0
		var colour: Color = item.get("colour", Color.WHITE)
		colour.a *= float(item.get("alpha", 1.0))
		if colour.a <= 0.0:
			return
		var rect: Rect2 = item["rect"]
		if rect.size.x <= 0.0 or rect.size.y <= 0.0:
			return
		var paragraph := TextParagraph.new()
		paragraph.width = rect.size.x
		paragraph.alignment = HORIZONTAL_ALIGNMENT_LEFT
		paragraph.line_spacing = size * 0.25
		paragraph.add_string(text, font, int(round(size)))
		if bool(item.get("outline", false)):
			paragraph.draw_outline(get_canvas_item(), rect.position, 2, Color.BLACK)
		paragraph.draw(get_canvas_item(), rect.position, colour)
