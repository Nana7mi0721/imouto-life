#!/usr/bin/env bash
# Source this in git-bash:  source "/e/Study/github program/Imouto Life/tools/env.sh"
# NOTE: use msys paths (/c/..., /e/...). Windows-style paths (C:/...) DO NOT work in git-bash PATH.
T="/e/Study/github program/Imouto Life/tools"
export IMO="/e/Study/github program/Imouto Life"
export PATH="$T/bin:$T/cmake/bin:$T/ffmpeg/bin:/c/Users/REISEN/.cargo/bin:$PATH"
export RUSTUP_DIST_SERVER="https://mirrors.ustc.edu.cn/rust-static"
export RUSTUP_UPDATE_ROOT="https://mirrors.ustc.edu.cn/rust-static/rustup"
export CARGO_NET_GIT_FETCH_WITH_CLI=true
echo "[env] rustc $(rustc --version 2>/dev/null | cut -d' ' -f2) | rg $(rg --version 2>/dev/null | head -1 | cut -d' ' -f2)"
