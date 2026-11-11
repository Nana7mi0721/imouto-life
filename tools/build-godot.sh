#!/usr/bin/env bash
# Build the Godot GDExtension library and copy it next to the project.
#
#   tools/build-godot.sh              # optimised, no debug info (profile "godot")
#   tools/build-godot.sh --debug      # normal cargo dev profile
#   tools/build-godot.sh --release    # release (thin LTO)
#
# The DLL is gitignored; the Godot project loads it from godot/bin/ through
# godot/bin/wolf_gdext.gdextension.
set -euo pipefail

cd "$(dirname "$0")/.."
source tools/env.sh >/dev/null 2>&1

profile_dir="godot"
cargo_args=("--profile" "godot")
for arg in "$@"; do
    case "$arg" in
        --release)
            profile_dir="release"
            cargo_args=("--release")
            ;;
        --debug)
            profile_dir="debug"
            cargo_args=()
            ;;
        *)
            cargo_args+=("$arg")
            ;;
    esac
done

cargo build -p wolf-gdext "${cargo_args[@]}"

mkdir -p godot/bin
cp -f "target/${profile_dir}/wolf_gdext.dll" godot/bin/wolf_gdext.dll
echo "built target/${profile_dir}/wolf_gdext.dll -> godot/bin/wolf_gdext.dll"