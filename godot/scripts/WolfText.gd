class_name WolfText
extends RefCounted

## Faithful text drawing for the Godot front-end.
##
## The Rust capture path (`wolf-cli capture`) is the reference: it shapes each
## packet text item with cosmic-text/glyphon at the *float* `font_px`, on a
## `Metrics::new(size, size * 1.25)` buffer, and places the buffer at the
## rounded item origin.  Godot's `TextParagraph` uses FreeType metrics and
## truncates the draw origin, so a naive `paragraph.draw(pos)` lands one or two
## pixels away and draws a much thinner outline.  This helper re-applies the
## reference geometry.
##
## Vertical geometry
## -----------------
## Rust first baseline (measured against the captures):
##
##     baseline_rust = round(rect.y) + round(size * 1.023193)
##
## The constant is derived from cosmic-text's line box, not from a fitted
## offset.  cosmic-text 0.19 computes a line's baseline as
##
##     line_y = (line_height - (ascent + descent)) / 2 + ascent
##
## with `line_height = 1.25 * size` (`wolf-render::text::LINE_HEIGHT_FACTOR`)
## and the primary face's hhea ratios (`C:/Windows/Fonts/msyhbd.ttc`, face 0,
## upem 2048: ascender 2167, descender -536, so A = 1.058105, D = 0.261719):
##
##     (1.25 - (A + D)) / 2 + A = 1.023193
##
## glyphon rounds `line_y` per line, so the reference baseline is the rounded
## product.  Godot instead puts the first baseline at `FontFile.get_ascent()`,
## which is `ceil(A * size)` for this face (`MSYH` hhea ascent 2167/2048):
##
##     size 14 -> ascent 15, 16 -> 17, 18 -> 20, 20 -> 22, 24 -> 26, 32 -> 34
##
## The difference `round(size * 1.023193) - ascent` is -1 for most sizes, -2 for
## 18-21 px and 35-51 px, and -3 above 51 px (the complete table is in
## `BASELINE_SHIFT`).
## Godot truncates a fractional draw y (verified with a ruler capture: y, y+0.25,
## y+0.5 and y+0.75 produce identical glyph rows), so the shift is applied to
## the rounded origin and stays an integer.
##
## Horizontal geometry
## -------------------
## Rust rounds the item origin (`wolf-render::text::layout_box`: `x.round()`,
## `y.round()`); Godot truncates it.  For `19:30` at rect.x = 33.94 the reference
## draws at 34 while a plain `paragraph.draw` starts at 33 (measured -1 px), so
## the origin x is rounded here too.
##
## Outline
## -------
## WOLF `\E` is drawn by `wolf-render` as four copies of the same shaped text at
## (+2, 0), (-2, 0), (0, +2), (0, -2) behind the body, so the ring is 2 px wide.
## Godot's `TextParagraph.draw_outline(pos, 2)` strokes the contour with a
## 2 px pen centred on it, which leaves only a 1 px ring (ruler capture: a
## 13x15 'H' becomes 14x17 at stroke 2; even strokes 3-4 only reach 15x17, about
## 1 px per side).  The four copies are therefore recreated explicitly.
##
## Line spacing
## ------------
## Every packet text item is a single WOLF row: `wolf-game` emits one `TextQuad`
## per row/chunk and one `MessageRun` per message row, each with its own y.  The
## only multi-line case is a paragraph that *wraps* inside one item, and there
## cosmic-text uses the same `1.25 * size` pitch.  `TextParagraph` pitch is
## `ascent + descent + line_spacing`, so the spacing is set to
## `round(1.25 * size) - height`, not the old `size * 0.25` (which produced
## 1.65 * size).  The value is irrelevant for the single-line items the game
## actually sends but keeps wrapped items on the reference pitch.
##
## Width
## -----
## Both packet producers already add one em of slack to the layout width; an
## extra 2 px covers FreeType's rounding of the last glyph advance without
## moving left-aligned text (TextParagraph width only affects wrapping and
## alignment, and the reference always draws left-aligned).
##
## Font size
## ---------
## `font_px` is a float but the game only writes integer sizes (Sys8, `\f[n]`).
## Both the Godot font request and the ascent lookup use `round(font_px)`.

## cosmic-text line-height factor used by `wolf-render::text`.
const LINE_HEIGHT_FACTOR := 1.25
## Face ratios of the reference UI face (`msyhbd.ttc` face 0 / `msyh.ttc` face 0,
## both upem 2048: hhea ascender 2167, descender -536).  Both the bold and the
## regular face of Microsoft YaHei share these vertical metrics.
const FACE_ASCENT := 2167.0 / 2048.0
const FACE_DESCENT := 536.0 / 2048.0
## `(LINE_HEIGHT_FACTOR - (FACE_ASCENT + FACE_DESCENT)) / 2 + FACE_ASCENT`
## = 1.023193... : Rust baseline offset per font pixel.
const RUST_BASELINE_RATIO := (
	LINE_HEIGHT_FACTOR * 0.5 + (FACE_ASCENT - FACE_DESCENT) * 0.5
)
## WOLF `\E` outline: four copies at this offset (Rust `expand` / `prepare`).
const OUTLINE_PX := 2
## Extra paragraph width so FreeType advance rounding cannot wrap the last glyph.
const WIDTH_SLACK_PX := 2.0
## Fallback font size for an item without `font_px`, matching GameView.
const DEFAULT_FONT_PX := 20.0

## Measured shift `round(size * RUST_BASELINE_RATIO) - FontFile.get_ascent(size)`
## for every size this game uses.  Kept as data so the formula can be audited
## against the ruler capture; `baseline_shift()` recomputes it at runtime and
## agrees with this table for all entries.
const BASELINE_SHIFT := {
	4: -1, 5: -1, 6: -1, 7: -1, 8: -1, 9: -1, 10: -1, 11: -1, 12: -1,
	13: -1, 14: -1, 15: -1, 16: -1, 17: -1, 18: -2, 19: -2, 20: -2, 21: -2,
	22: -1, 23: -1, 24: -1, 25: -1, 26: -1, 27: -1, 28: -1, 29: -1, 30: -1,
	31: -1, 32: -1, 33: -1, 34: -1, 35: -2, 36: -2, 37: -2, 38: -2, 39: -2,
	40: -2, 41: -2, 42: -2, 43: -2, 44: -2, 45: -2, 46: -2, 47: -2, 48: -2,
	49: -2, 50: -2, 51: -2, 52: -3, 53: -3, 54: -3, 55: -3, 56: -3, 57: -3,
	58: -3, 59: -3, 60: -3, 61: -3, 62: -3, 63: -3, 64: -3,
}


## Integer y offset to add to `round(rect.y)` so the first baseline matches the
## Rust reference.  `size` is the item's float `font_px`; the ascent is looked up
## at the same integer size the paragraph is shaped with.
static func baseline_shift(font: FontFile, size: float) -> int:
	var px := maxi(1, int(round(size)))
	var ascent := int(round(font.get_ascent(px)))
	return int(round(float(px) * RUST_BASELINE_RATIO)) - ascent


## Paragraph pitch the Rust text pass uses inside one item, in pixels.
static func line_pitch(size: float) -> float:
	return roundf(maxf(1.0, size) * LINE_HEIGHT_FACTOR)


## `line_spacing` that turns Godot's `ascent + descent` line height into
## [`line_pitch`].  Negative values are valid and used: at 20 px the face is
## 22 + 6 = 28 px tall, while cosmic-text's pitch is 25 px.
static func line_spacing(font: FontFile, size: float) -> float:
	var px := maxi(1, int(round(size)))
	return line_pitch(size) - font.get_height(px)


## Draw one packet text item.  Mirrors the item semantics of
## `GameView._draw_text` (text / rect / alpha / colour / outline / weight) and
## returns false when the item cannot produce pixels.
static func draw_text(
	canvas: CanvasItem, item: Dictionary, bold_font: FontFile, regular_font: FontFile
) -> bool:
	var text: String = item.get("text", "")
	if text.is_empty():
		return false
	var font: FontFile = bold_font
	if int(item.get("weight", 700)) < 600:
		font = regular_font
	if font == null:
		return false
	var size := float(item.get("font_px", 0.0))
	if size <= 0.0:
		size = DEFAULT_FONT_PX
	var colour: Color = item.get("colour", Color.WHITE)
	colour.a *= float(item.get("alpha", 1.0))
	if colour.a <= 0.0:
		return false
	var rect: Rect2 = item["rect"]
	if rect.size.x <= 0.0 or rect.size.y <= 0.0:
		return false

	var px := maxi(1, int(round(size)))
	var paragraph := TextParagraph.new()
	paragraph.width = rect.size.x + WIDTH_SLACK_PX
	paragraph.alignment = HORIZONTAL_ALIGNMENT_LEFT
	paragraph.line_spacing = line_spacing(font, size)
	paragraph.add_string(text, font, px)

	# Rust rounds the item origin; Godot truncates it, so round explicitly.
	var origin := Vector2(
		roundf(rect.position.x),
		roundf(rect.position.y) + float(baseline_shift(font, size))
	)
	if bool(item.get("outline", false)):
		var ring := Color(0.0, 0.0, 0.0, colour.a)
		for offset in [
			Vector2(-float(OUTLINE_PX), 0.0),
			Vector2(float(OUTLINE_PX), 0.0),
			Vector2(0.0, -float(OUTLINE_PX)),
			Vector2(0.0, float(OUTLINE_PX)),
		]:
			paragraph.draw(canvas.get_canvas_item(), origin + offset, ring)
	paragraph.draw(canvas.get_canvas_item(), origin, colour)
	return true
