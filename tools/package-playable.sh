#!/usr/bin/env bash
# tools/package-playable.sh - build a double-clickable, self-contained Windows game package.
#
# Unlike tools/package.sh (diagnostic wolf-cli drop without game data), this script
# builds the GUI launcher and bundles the unpacked game data, producing:
#
#   <out-dir>/
#     Imouto Life.exe       double-click this
#     runtime/wolf-cli.exe  engine
#     Data/                 full unpacked game data
#     README.txt
#     checksums.txt
#
# Usage:
#   tools/package-playable.sh [--version V] [--data-root DIR] [--out-dir DIR]
#                             [--zip-dir DIR] [--no-zip] [--skip-build] [--force]
set -e

REPO="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO"

VERSION=""
DATA_ROOT="work/Data"
OUT_DIR=""
ZIP_DIR="work/out/dist"
MAKE_ZIP=1
SKIP_BUILD=0
FORCE=0

usage() {
    cat <<'USAGE'
Usage: tools/package-playable.sh [options]

  --version V        set version (default: [workspace.package] in Cargo.toml)
  --data-root DIR    unpacked game data folder (default: work/Data)
  --out-dir DIR      package folder (default: work/out/dist/<version>-playable)
  --zip-dir DIR      where to write the zip (default: work/out/dist)
  --no-zip           do not create a zip archive
  --skip-build       reuse target/release binaries instead of rebuilding
  --force            replace an existing --out-dir
  -h, --help         show this help
USAGE
}

while [ $# -gt 0 ]; do
    case "$1" in
        --version)    VERSION="$2"; shift 2 ;;
        --data-root)  DATA_ROOT="$2"; shift 2 ;;
        --out-dir)    OUT_DIR="$2"; shift 2 ;;
        --zip-dir)    ZIP_DIR="$2"; shift 2 ;;
        --no-zip)     MAKE_ZIP=0; shift ;;
        --skip-build) SKIP_BUILD=1; shift ;;
        --force)      FORCE=1; shift ;;
        -h|--help)    usage; exit 0 ;;
        *) echo "unknown option: $1" >&2; usage >&2; exit 2 ;;
    esac
done

if [ -z "$VERSION" ]; then
    VERSION="$(sed -n '/^\[workspace\.package\]/,/^\[/p' Cargo.toml \
        | sed -n 's/^version[[:space:]]*=[[:space:]]*"\([^"]*\)".*/\1/p' \
        | head -n1)"
fi
if [ -z "$VERSION" ]; then
    echo "cannot read [workspace.package] version from Cargo.toml" >&2
    exit 1
fi

case "$DATA_ROOT" in
    /*) ;;
    *) DATA_ROOT="$REPO/$DATA_ROOT" ;;
esac
if [ ! -d "$DATA_ROOT/BasicData" ]; then
    echo "data root has no BasicData: $DATA_ROOT" >&2
    exit 2
fi

if [ -z "$OUT_DIR" ]; then
    OUT_DIR="$REPO/work/out/dist/$VERSION-playable"
fi
case "$OUT_DIR" in
    /*) ;;
    *) OUT_DIR="$REPO/$OUT_DIR" ;;
esac
case "$ZIP_DIR" in
    /*) ;;
    *) ZIP_DIR="$REPO/$ZIP_DIR" ;;
esac

ENGINE="$REPO/target/release/wolf-cli.exe"
LAUNCHER="$REPO/target/release/imouto-life.exe"

if [ "$SKIP_BUILD" -eq 0 ]; then
    echo "==> cargo build --release -p wolf-cli -p imouto-launcher"
    cargo build --release -p wolf-cli -p imouto-launcher
fi
if [ ! -f "$ENGINE" ]; then
    echo "release engine missing: $ENGINE (run without --skip-build)" >&2
    exit 1
fi
if [ ! -f "$LAUNCHER" ]; then
    echo "release launcher missing: $LAUNCHER (run without --skip-build)" >&2
    exit 1
fi

if [ -e "$OUT_DIR" ]; then
    if [ "$FORCE" -ne 1 ]; then
        echo "output folder already exists: $OUT_DIR" >&2
        echo "pass --force to replace it" >&2
        exit 2
    fi
    case "$OUT_DIR" in
        "$REPO/work/out/"*) ;;
        /d/program/*|/D/program/*) ;;
        *)
            echo "refusing to delete unexpected output folder: $OUT_DIR" >&2
            exit 2
            ;;
    esac
    echo "==> replacing $OUT_DIR"
    rm -rf -- "$OUT_DIR"
fi

echo "==> version $VERSION"
echo "==> staging $OUT_DIR"
mkdir -p "$OUT_DIR/runtime" "$OUT_DIR/Data"
cp "$ENGINE" "$OUT_DIR/runtime/wolf-cli.exe"
cp "$LAUNCHER" "$OUT_DIR/Imouto Life.exe"

echo "==> copying game data (about 176 MB)"
cp -a "$DATA_ROOT/." "$OUT_DIR/Data/"

BUILT="$(date -u +%Y-%m-%d)"
sed -e "s/{{VERSION}}/$VERSION/g" -e "s/{{BUILT}}/$BUILT/g" \
    tools/package/PLAYABLE_README.txt | sed 's/$/\r/' > "$OUT_DIR/README.txt"

echo "==> writing checksums.txt"
(
    cd "$OUT_DIR"
    sha256sum "Imouto Life.exe" runtime/wolf-cli.exe README.txt > checksums.txt
)

if [ "$MAKE_ZIP" -eq 1 ]; then
    mkdir -p "$ZIP_DIR"
    ZIP_PATH="$ZIP_DIR/Imouto Life-$VERSION-playable.zip"
    echo "==> creating $ZIP_PATH"
    rm -f "$ZIP_PATH"
    PARENT="$(dirname "$OUT_DIR")"
    BASE="$(basename "$OUT_DIR")"
    ZIP_WIN="$(cygpath -w "$ZIP_PATH")"
    (
        cd "$PARENT"
        /c/Windows/System32/tar.exe -a -c -f "$ZIP_WIN" "$BASE"
    )
fi

echo "==> package contents"
find "$OUT_DIR" -maxdepth 2 -type f -printf '%12s  %P\n' | sort -k2
du -sh "$OUT_DIR"
echo
echo "Playable package ready: $OUT_DIR"
echo "Double-click: $OUT_DIR/Imouto Life.exe"
