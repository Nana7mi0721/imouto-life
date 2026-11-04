#!/usr/bin/env bash
# run_ghidra.sh -- wrapper around Ghidra 12.2 analyzeHeadless for Imouto Life RE.
#
# Why a .bat and not support/analyzeHeadless directly?
#   Git-Bash/MSYS cannot run the POSIX launch script reliably here: Ghidra's
#   launch.sh JDK probing fails under MSYS and the repo path contains spaces and
#   "!". So we always generate a small Windows .bat file and run it through
#   cmd //c. JAVA_HOME is passed in Windows form, exactly like the working
#   work/out/ghidra/import.bat does.
#
# Why an arguments file?
#   analyzeHeadless.bat re-parses its command line with EnableDelayedExpansion
#   (and each .bat line gets a percent-expansion pass), so anchors such as
#   "WindowModeFlag=%d" or anything with "!" get silently mangled. Therefore the
#   real script arguments are written to a UTF-8 file (one per line) and only
#   "--argsfile=<path>" goes through cmd; DumpByAnchor/DumpAll expand it.
#
# Usage:
#   tools/re/ghidra/run_ghidra.sh [wrapper options] <Script.java> [script args...]
#
# Wrapper options (before the script name):
#   --out-dir=DIR        where the script writes its output (default work/out/re_dump)
#   --max-cpu=N          pass -max-cpu N to analyzeHeadless
#   --analyze            run full auto-analysis (default: -noanalysis, reuse the
#                        already analyzed project)
#   --project=DIR        project directory (default <repo>/work/out/ghidra/proj)
#   --project-name=NAME  project name (default ImoutoLife)
#   --program=NAME       program name inside the project (default Game.exe)
#   --keep-bat           keep the generated .bat and .args.txt (paths printed)
#   --print-only         print the generated .bat / args file and exit
#   -h | --help          show this help
#
# The output directory is always injected as the FIRST script argument.
#
# Environment overrides: GHIDRA_HOME, GHIDRA_JAVA_HOME (Windows path),
#   PROJECT_DIR, PROJECT_NAME, PROGRAM_NAME, OUTDIR.
#
# Notes:
#   * Do not run this against work/out/ghidra/proj while another analyzeHeadless
#     or the Ghidra GUI has the project open (Ghidra locks <project>.lock).
#   * The scripts only write to the output directory; the project is opened with
#     -noanalysis and is never modified.

set -u

SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
REPO_ROOT=$(cd "$SCRIPT_DIR/../../.." && pwd)

GHIDRA_HOME=${GHIDRA_HOME:-/d/Program/ghidra_12.2_PUBLIC}
GHIDRA_JAVA_HOME=${GHIDRA_JAVA_HOME:-'D:\Program\Java\jdk-25.0.5+8'}
PROJECT_DIR=${PROJECT_DIR:-$REPO_ROOT/work/out/ghidra/proj}
PROJECT_NAME=${PROJECT_NAME:-ImoutoLife}
PROGRAM_NAME=${PROGRAM_NAME:-Game.exe}
OUTDIR=${OUTDIR:-$REPO_ROOT/work/out/re_dump}

MAX_CPU=""
DO_ANALYSIS=0
KEEP_BAT=0
PRINT_ONLY=0
BAT_DIR="$REPO_ROOT/work/out/ghidra_run"

usage() {
	sed -n '/^# run_ghidra.sh/,/^set -u/p' "${BASH_SOURCE[0]}" | sed -n 's/^# \{0,1\}//p'
}

die() {
	echo "[run_ghidra] ERROR: $*" >&2
	exit 2
}

# ---- parse wrapper options -------------------------------------------------
while [ $# -gt 0 ]; do
	case "$1" in
		--out-dir=*)      OUTDIR=${1#--out-dir=}; shift ;;
		--max-cpu=*)      MAX_CPU=${1#--max-cpu=}; shift ;;
		--analyze)        DO_ANALYSIS=1; shift ;;
		--project=*)      PROJECT_DIR=${1#--project=}; shift ;;
		--project-name=*) PROJECT_NAME=${1#--project-name=}; shift ;;
		--program=*)      PROGRAM_NAME=${1#--program=}; shift ;;
		--keep-bat)       KEEP_BAT=1; shift ;;
		--print-only)     PRINT_ONLY=1; shift ;;
		-h|--help)        usage; exit 0 ;;
		--)               shift; break ;;
		-*)               die "unknown wrapper option: $1 (script args go after the script name; try --help)" ;;
		*)                break ;;
	esac
done

[ $# -ge 1 ] || die "missing script name (try --help)"

SCRIPT_ARG=$1
shift
SCRIPT_ARGS=("$@")

# Accept both "DumpByAnchor" and "DumpByAnchor.java"
case "$SCRIPT_ARG" in
	*.java) : ;;
	*)      SCRIPT_ARG="$SCRIPT_ARG.java" ;;
esac

# ---- validate inputs -------------------------------------------------------
command -v cygpath >/dev/null 2>&1 || die "cygpath not found; this wrapper must run in Git-Bash/MSYS"
[ -d "$GHIDRA_HOME" ] || die "GHIDRA_HOME not found: $GHIDRA_HOME"
[ -f "$GHIDRA_HOME/support/analyzeHeadless.bat" ] || die "analyzeHeadless.bat not found under $GHIDRA_HOME"
[ -d "$PROJECT_DIR" ] || die "project directory not found: $PROJECT_DIR"
[ -f "$SCRIPT_DIR/$SCRIPT_ARG" ] || die "script not found: $SCRIPT_DIR/$SCRIPT_ARG"

for a in "${SCRIPT_ARGS[@]}"; do
	case "$a" in
		*$'\n'*|*$'\r'*) die "script argument contains a newline: $a" ;;
	esac
done

mkdir -p "$OUTDIR" "$BAT_DIR" || die "cannot create output/bat directory"

# ---- MSYS -> Windows paths -------------------------------------------------
w_ghidra=$(cygpath -w "$GHIDRA_HOME")
w_proj=$(cygpath -w "$PROJECT_DIR")
w_scripts=$(cygpath -w "$SCRIPT_DIR")
w_out=$(cygpath -w "$OUTDIR")

# Quote one token for cmd.exe. Percent signs are doubled because the .bat does
# one percent-expansion pass; double quotes cannot be represented.
bat_quote() {
	local s=$1
	case "$s" in
		*'"'*) echo "[run_ghidra] ERROR: double quote in argument is not supported: $s" >&2; exit 2 ;;
	esac
	s=${s//%/%%}
	printf '"%s"' "$s"
}

base_name=$(basename "${SCRIPT_ARG%.java}")
stamp=$$
bat_file="$BAT_DIR/_run_${base_name}_${stamp}.bat"
args_file="$BAT_DIR/_args_${base_name}_${stamp}.txt"

# ---- arguments file (UTF-8, one argument per line) -------------------------
{
	printf '%s\n' "$w_out"
	for a in "${SCRIPT_ARGS[@]}"; do
		printf '%s\n' "$a"
	done
} > "$args_file" || die "cannot write $args_file"

# ---- generate the .bat -----------------------------------------------------
{
	echo '@echo off'
	echo 'setlocal'
	echo "set \"JAVA_HOME=$GHIDRA_JAVA_HOME\""
	echo 'set "PATH=%JAVA_HOME%\bin;%PATH%"'
	extra_opts=''
	if [ "$DO_ANALYSIS" -eq 0 ]; then
		extra_opts="$extra_opts -noanalysis"
	fi
	if [ -n "$MAX_CPU" ]; then
		extra_opts="$extra_opts -max-cpu $MAX_CPU"
	fi
	printf 'call %s %s %s -process %s%s -scriptPath %s -postScript %s %s' \
		"$(bat_quote "$w_ghidra/support/analyzeHeadless.bat")" \
		"$(bat_quote "$w_proj")" \
		"$(bat_quote "$PROJECT_NAME")" \
		"$(bat_quote "$PROGRAM_NAME")" \
		"$extra_opts" \
		"$(bat_quote "$w_scripts")" \
		"$(bat_quote "$SCRIPT_ARG")" \
		"$(bat_quote "--argsfile=$(cygpath -w "$args_file")")"
	printf '\r\n'
	echo 'exit /b %ERRORLEVEL%'
} > "$bat_file" || die "cannot write $bat_file"

if [ "$PRINT_ONLY" -eq 1 ]; then
	echo "--- generated bat: $bat_file"
	cat "$bat_file"
	echo "--- script args file: $args_file"
	cat "$args_file"
	echo "--- output dir: $OUTDIR"
	exit 0
fi

echo "[run_ghidra] script   : $SCRIPT_DIR/$SCRIPT_ARG"
echo "[run_ghidra] project  : $PROJECT_DIR ($PROJECT_NAME/$PROGRAM_NAME)"
echo "[run_ghidra] outdir   : $OUTDIR"
echo "[run_ghidra] bat      : $bat_file"
echo "[run_ghidra] argsfile : $args_file"
echo "[run_ghidra] running analyzeHeadless (this can take a while) ..."

cmd.exe //c "$(cygpath -w "$bat_file")" < /dev/null
rc=$?

if [ "$KEEP_BAT" -eq 0 ]; then
	rm -f "$bat_file" "$args_file"
else
	echo "[run_ghidra] kept: $bat_file , $args_file"
fi

if [ "$rc" -ne 0 ]; then
	echo "[run_ghidra] analyzeHeadless exited with code $rc" >&2
fi
exit "$rc"
