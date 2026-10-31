#!/usr/bin/env bash
# tools/package.sh - msys / git-bash equivalent of tools/package.ps1
#
# Builds wolf-cli in release mode and stages a self-contained folder under
# work/out/dist/<version>/ with wolf-cli.exe, README.txt, Play-ImoutoLife.cmd
# and checksums.txt. The retail game data (~175 MB) is NOT bundled; the
# launcher resolves the data root as argument > WOLF_DATA_ROOT > .\Data.
#
# Usage:
#   tools/package.sh [--version V] [--data-root DIR] [--out-root DIR]
#                     [--verify] [--skip-build]
set -e

REPO="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO"

if ! command -v cargo >/dev/null 2>&1; then
    # shellcheck disable=SC1091
    source tools/env.sh >/dev/null 2>&1 || true
fi

VERSION=""
DATA_ROOT=""
OUT_ROOT="work/out/dist"
VERIFY=0
SKIP_BUILD=0

usage() {
    cat <<'USAGE'
Usage: tools/package.sh [options]

  --version V        set version (default: [workspace.package] in Cargo.toml)
  --data-root DIR    unpacked game data folder (only used with --verify)
  --out-root DIR     output root (default: work/out/dist)
  --verify           run "wolf-cli.exe verify --root DIR" after staging
  --skip-build       reuse target/release/wolf-cli.exe instead of rebuilding
  -h, --help         show this help
USAGE
}

while [ $# -gt 0 ]; do
    case "$1" in
        --version)    VERSION="$2"; shift 2 ;;
        --data-root)  DATA_ROOT="$2"; shift 2 ;;
        --out-root)   OUT_ROOT="$2"; shift 2 ;;
        --verify)     VERIFY=1; shift ;;
        --skip-build) SKIP_BUILD=1; shift ;;
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

EXE="target/release/wolf-cli.exe"
if [ "$SKIP_BUILD" -eq 0 ]; then
    echo "==> cargo build --release -p wolf-cli"
    cargo build --release -p wolf-cli
else
    echo "==> skipping cargo build (--skip-build)"
fi
if [ ! -f "$EXE" ]; then
    echo "release binary missing: $EXE (run without --skip-build)" >&2
    exit 1
fi

DIST="$OUT_ROOT/$VERSION"
echo "==> version $VERSION"
echo "==> staging $DIST"
rm -rf "$DIST"
mkdir -p "$DIST"
cp "$EXE" "$DIST/wolf-cli.exe"

BUILT="$(date -u +%Y-%m-%d)"
render() {
    # msys sed drops CR from CRLF input, so re-append CR to keep Windows CRLF
    sed -e "s/{{VERSION}}/$VERSION/g" -e "s/{{BUILT}}/$BUILT/g" "$1" | sed 's/$/\r/' > "$2"
}
render tools/package/README.txt  "$DIST/README.txt"
render tools/package/launcher.cmd "$DIST/Play-ImoutoLife.cmd"

echo "==> writing checksums.txt"
( cd "$DIST" && sha256sum wolf-cli.exe README.txt Play-ImoutoLife.cmd > checksums.txt )

if [ "$VERIFY" -eq 1 ]; then
    if [ -z "$DATA_ROOT" ]; then echo "--verify requires --data-root" >&2; exit 2; fi
    if [ ! -d "$DATA_ROOT/BasicData" ]; then echo "no BasicData under $DATA_ROOT" >&2; exit 2; fi
    echo "==> verify --root $DATA_ROOT"
    "$REPO/$DIST/wolf-cli.exe" verify --root "$DATA_ROOT"
fi

echo "==> dist contents"
ls -l "$DIST"
echo
echo "Release drop ready: $REPO/$DIST"
echo "Game data is NOT bundled - see README.txt for data-root selection."
