#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
tools/pack_offline_deps.py — 打包 crates.io 离线依赖集（vendor）

为什么需要它
------------
云端沙箱是**严格离���**的（无外网出站权限），而本工程有 **337 个 crates.io 依赖**
（wgpu / winit / gdext / symphonia / image / cosmic-text …）。没有本地 registry
缓存时，`cargo build` / `cargo test` 会在依赖解析阶段直接失败，Argon 连一行
代码都编译不了。

`cargo vendor` 把整棵依赖树落盘，配合 `.cargo/config.toml` 的 source 替换，
cargo 就能完全离线地构建。实测：整仓 `cargo check --offline --workspace
--all-targets` 55 秒通过，`cargo test --offline --workspace` 全绿。

产物
----
  work/out/imouto_life_offline_deps.zip
    vendor/            337 个 crate 的完整源码树
    .cargo/config.toml crates.io -> vendored-sources 的 source 替换
    rust-toolchain.toml 去掉 components，避免 rustup 联网装 rustfmt/clippy
    OFFLINE_BUILD.md   沙箱内的构建/测试步骤

用法
----
  python -I tools/pack_offline_deps.py
"""

import os
import shutil
import subprocess
import sys
import time
import zipfile

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
WORK = os.path.join(REPO_ROOT, "work", "out")
VENDOR_TMP = os.path.join(WORK, "_vendor_pack")
OUT_ZIP = os.path.join(WORK, "imouto_life_offline_deps.zip")

BS = chr(92)

CARGO_CONFIG = """# Offline build: replace the crates.io source with the vendored copy
# shipped next to this file.  The sandbox has no outbound network, so without
# this every `cargo build` would fail at dependency resolution.
[source.crates-io]
replace-with = "vendored-sources"

[source.vendored-sources]
directory = "vendor"
"""

# The upstream rust-toolchain.toml asks for the rustfmt/clippy components.
# rustup would try to download them, which the sandbox cannot do, so the
# offline bundle ships a component-free variant.
RUST_TOOLCHAIN = """[toolchain]
channel = "stable"
"""

OFFLINE_MD = """# Offline build & test in a network-isolated sandbox
=================================================

This directory carries the vendored crates.io dependency tree (337 crates) so
the workspace can be built and tested **without any network access**.

INSTALL
  Unzip this archive INTO the restored project root, so that the project
  directory contains both the sources and `vendor/`:

      unzip imouto_life_offline_deps.zip -d <restored-project-root>

  Resulting layout:

      <project>/Cargo.toml
      <project>/crates/...
      <project>/vendor/            <- from this archive
      <project>/.cargo/config.toml <- from this archive (source replacement)
      <project>/rust-toolchain.toml<- from this archive (component-free)

BUILD & TEST
  cd <project>
  cargo check --offline --workspace --all-targets
  cargo test  --offline --workspace

  The `--offline` flag is belt-and-braces: the source replacement already
  keeps cargo from touching the network.

RUN THE STATIC BYTECODE AUDIT (pure python, no rust needed)
  python tools/audit_bytecode.py
  # rewrites work/out/BYTECODE_AUDIT_REPORT.md

RUN THE REAL-DATA SUITE
  WOLF_DATA_ROOT="$PWD/work/Data" cargo test --offline -p wolf-game --no-fail-fast
  # ~7 known sister-game expectation differences are pre-existing; they are
  #  recorded in docs/HANDOFF_PROGRESS.md and are not regressions.

TOOLCHAIN NOTES
  * A stable Rust toolchain must already exist in the sandbox (rustup cannot
    download one offline). If `rustc` is missing, everything that does not
    require compilation still works: the bytecode audit, the JSON dumps and
    the full source review.
  * `rust-toolchain.toml` here drops `components = ["rustfmt", "clippy"]`
    because installing those components requires network access.
  * `vendor/` keeps the Windows crates (`windows-0.62.2` is 111 MB raw).
    They are large but compress well, and pruning them breaks cargo's
    dependency resolution, so the bundle stays cross-platform.

GODOT
  The Godot 4.7.2 editor binary is intentionally NOT part of this bundle:
  it is a 173 MB Windows-only executable, useless on a Linux sandbox, and
  the frontend additionally needs a native GDExtension built for the host
  platform. The Rust side already covers the same ground:
  `wolf-cli capture` renders the 1024x576 frame without Godot.
"""


def run_vendor():
    if os.path.isdir(VENDOR_TMP):
        shutil.rmtree(VENDOR_TMP, ignore_errors=True)
    print("vendoring crates.io dependencies ...")
    proc = subprocess.run(
        ["cargo", "vendor", "--versioned-dirs", VENDOR_TMP],
        cwd=REPO_ROOT, capture_output=True, text=True,
    )
    if proc.returncode != 0:
        sys.stderr.write(proc.stderr[-3000:])
        raise SystemExit("cargo vendor failed")
    crates = len([n for n in os.listdir(VENDOR_TMP)
                  if os.path.isdir(os.path.join(VENDOR_TMP, n))])
    print(f"  vendored {crates} crates")


def pack():
    if os.path.exists(OUT_ZIP):
        os.remove(OUT_ZIP)
    started = time.time()
    count = 0
    with zipfile.ZipFile(OUT_ZIP, "w", zipfile.ZIP_DEFLATED, compresslevel=6) as zf:
        def add(rel, data):
            nonlocal count
            zi = zipfile.ZipInfo(rel, date_time=(2024, 1, 1, 0, 0, 0))
            zi.compress_type = zipfile.ZIP_DEFLATED
            zi.external_attr = (0o755 if rel.endswith(".sh") else 0o644) << 16
            zf.writestr(zi, data)
            count += 1

        add(".cargo/config.toml", CARGO_CONFIG.encode("utf-8"))
        add("rust-toolchain.toml", RUST_TOOLCHAIN.encode("utf-8"))
        add("OFFLINE_BUILD.md", OFFLINE_MD.encode("utf-8"))

        for name in sorted(os.listdir(VENDOR_TMP)):
            root = os.path.join(VENDOR_TMP, name)
            if not os.path.isdir(root):
                continue
            for r, _, files in os.walk(root):
                for fn in files:
                    fp = os.path.join(r, fn)
                    rel = os.path.relpath(fp, VENDOR_TMP).replace(BS, "/")
                    with open(fp, "rb") as fh:
                        add(f"vendor/{rel}", fh.read())

    size = os.path.getsize(OUT_ZIP)
    print(f"packed {count} files -> {size / 1024 / 1024:.1f} MB "
          f"({time.time() - started:.0f}s)")
    print(f"  {OUT_ZIP}")


def main():
    os.makedirs(WORK, exist_ok=True)
    run_vendor()
    pack()
    shutil.rmtree(VENDOR_TMP, ignore_errors=True)


if __name__ == "__main__":
    main()
