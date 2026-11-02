#!/usr/bin/env bash
# Source this in git-bash:  source "/e/Study/github program/Imouto Life/tools/env.sh"
# NOTE: use msys paths (/c/..., /e/...). Windows-style paths (C:/...) DO NOT work in git-bash PATH.
T="/e/Study/github program/Imouto Life/tools"
export IMO="/e/Study/github program/Imouto Life"
export PATH="$T/bin:$T/cmake/bin:$T/ffmpeg/bin:/c/Users/REISEN/.cargo/bin:$PATH"
export RUSTUP_DIST_SERVER="https://mirrors.ustc.edu.cn/rust-static"
export RUSTUP_UPDATE_ROOT="https://mirrors.ustc.edu.cn/rust-static/rustup"
export CARGO_NET_GIT_FETCH_WITH_CLI=true
# Static RE toolchain for the original Game.exe (installed 2026-11-02, D:\Program per user policy).
# Ghidra 12.2 requires JDK 25+; JDK 21 is kept alongside for javac/other tools.
# Always drive Ghidra through tools/re/ghidra/run_ghidra.sh (it calls analyzeHeadless.bat via
# cmd.exe): the msys support/analyzeHeadless cannot probe JAVA_HOME correctly under Git-Bash.
export GHIDRA_INSTALL_DIR='/d/Program/ghidra_12.2_PUBLIC'
export GHIDRA_JAVA_HOME='D:\Program\Java\jdk-25.0.5+8'
export JAVA21_HOME='D:\Program\Java\jdk-21.0.13+9'
echo "[env] rustc $(rustc --version 2>/dev/null | cut -d' ' -f2) | rg $(rg --version 2>/dev/null | head -1 | cut -d' ' -f2)"
