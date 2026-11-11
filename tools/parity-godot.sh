#!/usr/bin/env bash
# Long-range Rust <-> Godot parity checks.
#
#   tools/parity-godot.sh [FRAMES ...] [--frames=600,1200,1800] [--pixel-check=N|0] [--save=PATH]
#
# For every checkpoint N it:
#   1. runs `wolf-cli capture --menu-only --answer 0 --frames N` and parses the
#      `stats :` summary line;
#   2. drives the Godot extension headlessly (godot/tests/parity_stats.gd) once up to
#      max(N), collecting the `PARITY frames=N ...` snapshot lines;
#   3. compares frames/instructions/pictures/messages/choices/warnings (plus sound
#      command counts) and exits 1 on the first mismatch, printing both sides.
#
# Environment:
#   PARITY_FRAMES       space-separated checkpoints (default: 600 1200 1800)
#   PARITY_PIXEL_CHECK  checkpoint to pixel-compare with the Rust PNG, 0 = skip
#                       (default: 600, or the first checkpoint in save mode; the
#                       Godot main scene window capture is realtime)
#   PARITY_SAVE         retail .sav to compare instead of a new game; checkpoints then
#                       default to 120 (bonus `--load-save` mode)
#   WOLF_DATA_ROOT      unpacked data root (default: <repo>/work/Data)
#   WOLF_CLI            wolf-cli binary (default: <repo>/target/debug/wolf-cli.exe)
#   GODOT_BIN           Godot console executable
#
# All temporary files go to work/out/parity/. Re-runnable; safe to run from Git Bash.
set -euo pipefail

cd "$(dirname "$0")/.."
source tools/env.sh >/dev/null 2>&1

GODOT="${GODOT_BIN:-/e/Study/github program/Godot_v4.7.2-stable/Godot_v4.7.2-stable_win64_console.exe}"
CLI="${WOLF_CLI:-$PWD/target/debug/wolf-cli.exe}"
DATA_ROOT="${WOLF_DATA_ROOT:-$PWD/work/Data}"
OUT="$PWD/work/out/parity"
PIXEL_CHECK="${PARITY_PIXEL_CHECK:-}"
SAVE="${PARITY_SAVE:-}"
FRAMES=()

for arg in "$@"; do
    case "$arg" in
        --pixel-check=*)
            PIXEL_CHECK="${arg#--pixel-check=}"
            ;;
        --save=*)
            SAVE="${arg#--save=}"
            ;;
        --frames=*)
            list="${arg#--frames=}"
            list="${list//,/ }"
            read -r -a FRAMES <<<"$list"
            ;;
        --help|-h)
            sed -n '2,24p' "$0"
            exit 0
            ;;
        -*)
            echo "parity: unknown option '$arg'" >&2
            exit 1
            ;;
        *)
            FRAMES+=("$arg")
            ;;
    esac
done

if [ "${#FRAMES[@]}" -eq 0 ]; then
    if [ -n "$SAVE" ]; then
        read -r -a FRAMES <<<"${PARITY_FRAMES:-120}"
    else
        read -r -a FRAMES <<<"${PARITY_FRAMES:-600 1200 1800}"
    fi
fi
if [ -z "$PIXEL_CHECK" ]; then
    if [ -n "$SAVE" ]; then
        PIXEL_CHECK="${FRAMES[0]}"
    else
        PIXEL_CHECK=600
    fi
fi

if [ ! -x "$CLI" ]; then
    echo "parity: no wolf-cli at $CLI (run: cargo build -q --workspace)" >&2
    exit 1
fi
if [ ! -d "$DATA_ROOT" ]; then
    echo "parity: data root not found: $DATA_ROOT" >&2
    exit 1
fi
if [ ! -f "$GODOT" ]; then
    echo "parity: Godot not found: $GODOT" >&2
    exit 1
fi
if [ -n "$SAVE" ] && [ ! -f "$SAVE" ]; then
    echo "parity: save not found: $SAVE" >&2
    exit 1
fi

mkdir -p "$OUT"

DATA_WIN=$(cygpath -m "$DATA_ROOT")
OUT_WIN=$(cygpath -m "$OUT")
SAVE_WIN=""
if [ -n "$SAVE" ]; then
    SAVE=$(cd "$(dirname "$SAVE")" && pwd)/$(basename "$SAVE")
    SAVE_WIN=$(cygpath -m "$SAVE")
fi

MAX_FRAMES=0
for n in "${FRAMES[@]}"; do
    if ! [[ "$n" =~ ^[0-9]+$ ]] || [ "$n" -le 0 ]; then
        echo "parity: bad checkpoint '$n'" >&2
        exit 1
    fi
    if [ "$n" -gt "$MAX_FRAMES" ]; then
        MAX_FRAMES=$n
    fi
done

echo "parity: data=$DATA_WIN"
if [ -n "$SAVE_WIN" ]; then
    echo "parity: save=$SAVE_WIN"
else
    echo "parity: entry=menu (new game via CE42)"
fi
echo "parity: checkpoints=${FRAMES[*]} pixel-check=$PIXEL_CHECK"

# --- 1. Rust captures -------------------------------------------------------

parse_rust_stats() {
    local log=$1
    local line
    R_FRAMES=$(grep -m1 '^  frames[[:space:]]*:' "$log" | sed -n 's/.*: \([0-9][0-9]*\) (peak.*/\1/p')
    line=$(grep -m1 '^  stats[[:space:]]*:' "$log" || true)
    if [ -z "$line" ]; then
        echo "parity: no 'stats :' line in $log" >&2
        return 1
    fi
    R_INSTRUCTIONS=$(printf '%s\n' "$line" | sed -n 's/.*: \([0-9][0-9]*\) instruction(s).*/\1/p')
    R_PICTURES=$(printf '%s\n' "$line" | sed -n 's/.*, \([0-9][0-9]*\) picture op(s).*/\1/p')
    R_SOUNDS=$(printf '%s\n' "$line" | sed -n 's/.*, \([0-9][0-9]*\) sound(s).*/\1/p')
    R_MESSAGES=$(printf '%s\n' "$line" | sed -n 's/.*, \([0-9][0-9]*\) message(s).*/\1/p')
    R_CHOICES=$(printf '%s\n' "$line" | sed -n 's/.*, \([0-9][0-9]*\) choice(s).*/\1/p')
    R_WARNINGS=$(printf '%s\n' "$line" | sed -n 's/.*, \([0-9][0-9]*\) warning(s).*/\1/p')
    R_DB=$(printf '%s\n' "$line" | sed -n 's/.*, \([0-9][0-9]*\) db access(es).*/\1/p')
    if [ -z "$R_INSTRUCTIONS" ] || [ -z "$R_PICTURES" ] || [ -z "$R_MESSAGES" ] || [ -z "$R_CHOICES" ] || [ -z "$R_WARNINGS" ]; then
        echo "parity: cannot parse stats line: $line" >&2
        return 1
    fi
    return 0
}

for n in "${FRAMES[@]}"; do
    log="$OUT/rust_$n.log"
    png="$OUT/rust_$n.png"
    echo "parity: rust capture frames=$n -> $png"
    if [ -n "$SAVE_WIN" ]; then
        "$CLI" --root "$DATA_ROOT" capture --load-save "$SAVE" --answer 0 \
            --frames "$n" --out "$png" >"$log" 2>&1 || {
            echo "parity: wolf-cli capture failed (frames=$n), see $log" >&2
            tail -n 20 "$log" >&2 || true
            exit 1
        }
    else
        "$CLI" --root "$DATA_ROOT" capture --menu-only --answer 0 \
            --frames "$n" --out "$png" >"$log" 2>&1 || {
            echo "parity: wolf-cli capture failed (frames=$n), see $log" >&2
            tail -n 20 "$log" >&2 || true
            exit 1
        }
    fi
    parse_rust_stats "$log" || exit 1
done

# --- 2. Godot headless run --------------------------------------------------
GODOT_LOG="$OUT/godot.log"
echo "parity: godot headless frames=$MAX_FRAMES"
GODOT_ARGS=(--headless --path godot --script res://tests/parity_stats.gd --
    "--data-root=$DATA_WIN" "--frames=$(IFS=,; echo "${FRAMES[*]}")")
if [ -n "$SAVE_WIN" ]; then
    GODOT_ARGS+=("--save=$SAVE_WIN")
fi
if ! "$GODOT" "${GODOT_ARGS[@]}" >"$GODOT_LOG" 2>&1; then
    echo "parity: godot parity run failed, see $GODOT_LOG" >&2
    tail -n 30 "$GODOT_LOG" >&2 || true
    exit 1
fi


parse_godot_line() {
    local line=$1
    local kv key value
    for kv in $line; do
        case "$kv" in
            *=*)
                key="${kv%%=*}"
                value="${kv#*=}"
                case "$key" in
                    instructions) G_INSTRUCTIONS=$value ;;
                    pictures) G_PICTURES=$value ;;
                    sounds) G_SOUNDS=$value ;;
                    messages) G_MESSAGES=$value ;;
                    choices) G_CHOICES=$value ;;
                    warnings) G_WARNINGS=$value ;;
                    unmodelled) G_UNMODELLED=$value ;;
                    max_sprites) G_MAX_SPRITES=$value ;;
                    max_texts) G_MAX_TEXTS=$value ;;
                    choice_frames) G_CHOICE_FRAMES=$value ;;
                    stat_frames) G_STAT_FRAMES=$value ;;
                    driven) G_DRIVEN=$value ;;
                esac
                ;;
        esac
    done
}

# --- 3. Compare -------------------------------------------------------------
status=0
printf '%-7s %-12s %-12s %-12s %-10s %-10s %-9s %-8s\n' \
    "frames" "instructions" "pictures" "messages" "choices" "warnings" "sounds" "result"
for n in "${FRAMES[@]}"; do
    line=$(grep -E "^PARITY frames=$n " "$GODOT_LOG" | head -n1 || true)
    line="${line%$'\r'}"
    if [ -z "$line" ]; then
        echo "parity: no PARITY line for frames=$n (Godot run may have stopped early)" >&2
        tail -n 20 "$GODOT_LOG" >&2 || true
        exit 1
    fi
    G_INSTRUCTIONS=""; G_PICTURES=""; G_SOUNDS=""; G_MESSAGES=""; G_CHOICES=""; G_WARNINGS=""; G_UNMODELLED=""; G_MAX_SPRITES=""; G_MAX_TEXTS=""; G_CHOICE_FRAMES=""; G_STAT_FRAMES=""; G_DRIVEN=""
    parse_godot_line "$line"

    parse_rust_stats "$OUT/rust_$n.log" || exit 1
    frames_ok=1
    if [ "$R_FRAMES" != "$n" ] || [ "$G_DRIVEN" != "$n" ]; then
        frames_ok=0
    fi
    # New games have no priming frames, so the runtime's own frame counter must equal N.
    if [ -z "$SAVE_WIN" ] && [ "$G_STAT_FRAMES" != "$n" ]; then
        frames_ok=0
    fi
    rust="${R_INSTRUCTIONS}/${R_PICTURES}/${R_MESSAGES}/${R_CHOICES}/${R_WARNINGS}/${R_SOUNDS}"
    godot="${G_INSTRUCTIONS}/${G_PICTURES}/${G_MESSAGES}/${G_CHOICES}/${G_WARNINGS}/${G_SOUNDS}"
    if [ "$rust" = "$godot" ] && [ "$frames_ok" -eq 1 ]; then
        printf '%-7s %-12s %-12s %-12s %-10s %-10s %-9s %-8s\n' \
            "$n" "$R_INSTRUCTIONS" "$R_PICTURES" "$R_MESSAGES" "$R_CHOICES" "$R_WARNINGS" "$R_SOUNDS" "OK"
    else
        status=1
        printf '%-7s %-12s %-12s %-12s %-10s %-10s %-9s %-8s\n' \
            "$n" "$R_INSTRUCTIONS" "$R_PICTURES" "$R_MESSAGES" "$R_CHOICES" "$R_WARNINGS" "$R_SOUNDS" "MISMATCH"
        echo "parity: first divergence at frames=$n" >&2
        echo "  rust : frames=$R_FRAMES instructions=$R_INSTRUCTIONS pictures=$R_PICTURES sounds=$R_SOUNDS db=$R_DB messages=$R_MESSAGES choices=$R_CHOICES warnings=$R_WARNINGS" >&2
        echo "  godot: frames=$G_DRIVEN stat_frames=$G_STAT_FRAMES instructions=$G_INSTRUCTIONS pictures=$G_PICTURES sounds=$G_SOUNDS messages=$G_MESSAGES choices=$G_CHOICES warnings=$G_WARNINGS unmodelled=$G_UNMODELLED max_sprites=$G_MAX_SPRITES max_texts=$G_MAX_TEXTS choice_frames=$G_CHOICE_FRAMES" >&2
        echo "  godot line: $line" >&2
        echo "  godot diagnostics:" >&2
        grep -E "^PARITY_(DIAG|WARN) frames=$n " "$GODOT_LOG" >&2 || true
        break
    fi
    echo "parity: frames=$n godot unmodelled=$G_UNMODELLED max_sprites=$G_MAX_SPRITES max_texts=$G_MAX_TEXTS choice_frames=$G_CHOICE_FRAMES stat_frames=$G_STAT_FRAMES"
done

if [ "$status" -ne 0 ]; then
    echo "parity: FAILED (see $GODOT_LOG)" >&2
    exit 1
fi

# --- 4. Pixel check ---------------------------------------------------------
if [ "$PIXEL_CHECK" != "0" ]; then
    case " ${FRAMES[*]} " in
        *" $PIXEL_CHECK "*) ;;
        *)
            echo "parity: pixel-check=$PIXEL_CHECK is not a checkpoint; skipping pixel check"
            PIXEL_CHECK=0
            ;;
    esac
fi

if [ "$PIXEL_CHECK" != "0" ]; then
    GODOT_PNG="$OUT/godot_$PIXEL_CHECK.png"
    GODOT_PIXEL_LOG="$OUT/godot_${PIXEL_CHECK}_pixel.log"
    echo "parity: godot window capture frames=$PIXEL_CHECK (realtime, ~$((PIXEL_CHECK / 60))s) -> $GODOT_PNG"
    PIXEL_ARGS=(--path godot -- "--entry=menu" --auto-new-game
        "--frames=$PIXEL_CHECK" "--capture=$OUT_WIN/godot_$PIXEL_CHECK.png"
        "--data-root=$DATA_WIN")
    if [ -n "$SAVE_WIN" ]; then
        PIXEL_ARGS=(--path godot -- "--load-save=$SAVE_WIN" --auto-new-game
            "--frames=$PIXEL_CHECK" "--capture=$OUT_WIN/godot_$PIXEL_CHECK.png"
            "--data-root=$DATA_WIN")
    fi
    if ! "$GODOT" "${PIXEL_ARGS[@]}" >"$GODOT_PIXEL_LOG" 2>&1; then
        echo "parity: godot window capture failed, see $GODOT_PIXEL_LOG" >&2
        tail -n 30 "$GODOT_PIXEL_LOG" >&2 || true
        exit 1
    fi
    if [ ! -f "$GODOT_PNG" ]; then
        echo "parity: godot window capture wrote no PNG: $GODOT_PNG" >&2
        tail -n 30 "$GODOT_PIXEL_LOG" >&2 || true
        exit 1
    fi
    if [ -n "$SAVE_WIN" ]; then
        RUST_PNG="$OUT/rust_$PIXEL_CHECK.png"
    else
        # The Godot window primes CE48/CE63 before the title, so the pixel pair
        # must use the same history. The stats capture above is the unprimed
        # menu entry; reusing it would compare two different RNG sequences and
        # message-window states (the new-game money is a random draw).
        RUST_PNG="$OUT/rust_prime_$PIXEL_CHECK.png"
        RUST_PIXEL_LOG="$OUT/rust_${PIXEL_CHECK}_prime.log"
        echo "parity: rust primed capture frames=$PIXEL_CHECK -> $RUST_PNG"
        if ! "$CLI" --root "$DATA_ROOT" capture --menu-only --prime --answer 0 \
            --frames "$PIXEL_CHECK" --out "$RUST_PNG" >"$RUST_PIXEL_LOG" 2>&1; then
            echo "parity: primed wolf-cli capture failed (frames=$PIXEL_CHECK), see $RUST_PIXEL_LOG" >&2
            tail -n 20 "$RUST_PIXEL_LOG" >&2 || true
            exit 1
        fi
    fi
    if [ ! -f "$RUST_PNG" ]; then
        echo "parity: no rust PNG for pixel check: $RUST_PNG" >&2
        exit 1
    fi
    python - "$RUST_PNG" "$GODOT_PNG" "$PIXEL_CHECK" <<'PY'
import sys
from PIL import Image, ImageChops

rust_path, godot_path, frames = sys.argv[1], sys.argv[2], sys.argv[3]
a = Image.open(rust_path).convert("RGB")
b = Image.open(godot_path).convert("RGB")
if a.size != b.size:
    print(f"PIXEL frames={frames} skip=size-mismatch rust={a.size} godot={b.size}")
    sys.exit(1)
diff = ImageChops.difference(a, b)
hist = diff.histogram()
channels = a.size[0] * a.size[1] * 3
# A histogram bin is (channel * 256 + value); use the value, not the bin index.
mae = sum((i % 256) * n for i, n in enumerate(hist)) / channels
within8 = sum(n for i, n in enumerate(hist) if i % 256 <= 8) / channels
within32 = sum(n for i, n in enumerate(hist) if i % 256 <= 32) / channels
max_diff = max(i % 256 for i, n in enumerate(hist) if n)
# Per-pixel: a pixel counts as changed when any channel differs.
pixels = a.size[0] * a.size[1]
raw = diff.tobytes()
changed = sum(1 for i in range(0, len(raw), 3) if raw[i] or raw[i + 1] or raw[i + 2])
# Bounding boxes of pixels whose worst channel difference exceeds the tolerance.
mask8 = diff.point(lambda v: 255 if v > 8 else 0).convert("L")
mask32 = diff.point(lambda v: 255 if v > 32 else 0).convert("L")
print(
    f"PIXEL frames={frames} size={a.size[0]}x{a.size[1]} mae={mae:.4f} "
    f"within8={within8 * 100:.2f}% within32={within32 * 100:.2f}% "
    f"max_channel_diff={max_diff} changed_pixels={changed}/{pixels} "
    f"({changed * 100.0 / pixels:.2f}%) bbox={diff.getbbox()} "
    f"bbox_gt8={mask8.getbbox()} bbox_gt32={mask32.getbbox()} "
    f"(ratios are per channel)"
)
PY
fi

echo "parity: PASS (checkpoints=${FRAMES[*]})"
