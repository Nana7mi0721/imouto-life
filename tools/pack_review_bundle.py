#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
tools/pack_review_bundle.py — 云端沙箱审查用源码打包器

按 AGENTS.md 的仓库约定：
  * 只打包源码与必要资产，绝不包含 target/ 构建产物；
  * 绝不包含 work/Data 的用户私有存档以外的玩家数据与本地私有目录；
  * 产物写入 work/out/（Windows 下 bash 子进程写 /tmp 会 PermissionDenied）。

产出两个包：
  1. imouto_life_sandbox.zip    —— 逻辑可运行包（含 Godot 工程、Rust 全量源码、
                                   全量字节码 JSON、核心数据与事件背景图）
  2. imouto_life_media.zip      —— 音频与特效资产（BGM/SE/BattleEffect/气泡底图）
"""

import io
import os
import shutil
import subprocess
import sys
import tarfile
import zipfile

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
OUT_DIR = os.path.join(REPO_ROOT, "work", "out")

LOGIC_ZIP = os.path.join(OUT_DIR, "imouto_life_sandbox.zip")
MEDIA_ZIP = os.path.join(OUT_DIR, "imouto_life_media.zip")

# --- 顶层文件：构建与工程约定 ---
TOP_FILES = [
    "Cargo.toml",
    "Cargo.lock",
    "rust-toolchain.toml",
    "AGENTS.md",
    "README.md",
    ".gitignore",
    # --- Godot 工程根文件（必须随包提供，沙箱才能直接开工程）---
    "godot/project.godot",
    "godot/main.tscn",
    "godot/bin/wolf_gdext.gdextension",
    "godot/bin/wolf_gdext.gdextension.uid",
]

# --- 目录：源码与工具链 ---
SRC_DIRS = [
    "crates",
    "tools",
    "godot/scripts",
    "godot/tests",
]

# --- 目录：文档（排除 gitignore 的本地私有内容）---
DOC_DIRS = ["docs"]

# --- 目录：审查产物与字节码数据 ---
REVIEW_DIRS = [
    "work/out/review",
]

REVIEW_FILES = [
    "work/out/_ce_full.json",
    "work/out/map_full.json",
    "work/out/BYTECODE_AUDIT_REPORT.md",
    "work/out/A_event_map_audit.md",
    "work/out/B_daily_events_audit.md",
    "work/out/C_ending_album_audit.md",
    "work/out/D_opening_time_audit.md",
    "work/out/E_shop_items_audit.md",
    "work/out/F_decoder_repro_audit.md",
]

# --- 目录：核心数据元数据（驱动状态机/事件图/文本解析）---
CORE_DATA_DIRS = [
    "work/Data/BasicData",
    "work/Data/MapData",
    "work/Data/Save",
    "work/Data/SystemFile",
    "work/Data/SystemGraphic",
    "work/Data/MapChip",
    "work/Data/CharaChip",
    "work/Data/FIcon",
    "work/Data/Fog_BackGround",
    "work/Data/Picture",
    # Event backgrounds. These are full-screen pictures referenced by the save
    # picture table, so without them every rendered scene comes out black and
    # the pixel-level visual regression baselines cannot run at all (measured:
    # the `hud` baseline drops from 554,890 to 11,294 non-black pixels).
    "work/Data/cg",
    # The balloon base plates are UI assets the message library draws; the
    # wolf-format Data.wolf reference check also expects them present.
    "work/Data/BalloonBase_CafeLatte",
]

CORE_DATA_FILES = [
    "work/Data/07やさしさゴシックボールド.ttf",
    "work/Data/◆GenJyuuGothicX-P-Bold.ttf",
]

# --- 可选：音频与战斗特效（audio-only 组）---
# BGM/SE are needed for an end-to-end play run; the audio *logic* (channel
# routing, retrigger suppression) is testable without the files themselves.
FULL_DATA_DIRS = [
    "work/Data/BGM",
    "work/Data/SE",
    "work/Data/BattleEffect",
]

# --- 排除规则 ---
EXCLUDE_DIR_NAMES = {
    ".git", "target", ".godot", ".recon", "_wolfref", "node_modules",
    ".import", "__pycache__", ".pytest_cache", "dist", "build",
}
EXCLUDE_FILE_EXTS = {
    ".dll", ".exe", ".pdb", ".o", ".a", ".rlib", ".pyc", ".so", ".dylib",
}
EXCLUDE_FILE_NAMES = {
    "相关链接.txt",
}
# 玩家在游戏内覆盖的存档不是源码资产，但属于 review 需要的“正规存档样本”，保留。


def should_skip_dir(name: str) -> bool:
    return name in EXCLUDE_DIR_NAMES


def should_skip_file(rel_path: str, name: str) -> bool:
    if name in EXCLUDE_FILE_NAMES:
        return True
    ext = os.path.splitext(name)[1].lower()
    if ext in EXCLUDE_FILE_EXTS:
        return True
    # work/out 下的探针产物、构建脚本与日志不属于审查资产
    parts = rel_path.replace("\\", "/").split("/")
    if len(parts) >= 2 and parts[0] == "work" and parts[1] == "out":
        if parts[2] not in {"review"} and not parts[2].endswith(".json") \
                and not parts[2].endswith(".md"):
            return True
    return False


def snapshot_head():
    """导出 HEAD 的一个自洽快照。

    工作区可能正被其它 agent 并发修改（例如 Opcode 140 新增 pitch 字段、
    PictureCmd 新增 owner_event 字段，而构造点还没同步），此时直接打包工作区
    会得到**编译不过**的中间态，交付给沙箱只会浪费对方时间。`git archive HEAD`
    永远给出一个已知可编译的快照。
    """
    tmp = os.path.join(OUT_DIR, "_snapshot")
    shutil.rmtree(tmp, ignore_errors=True)
    os.makedirs(tmp, exist_ok=True)
    archive = subprocess.run(
        ["git", "archive", "HEAD"], cwd=REPO_ROOT, capture_output=True
    )
    if archive.returncode != 0:
        raise SystemExit(f"git archive failed: {archive.stderr[:400]!r}")
    with tarfile.open(fileobj=io.BytesIO(archive.stdout), mode="r|") as tf:
        tf.extractall(tmp)
    print(f"  snapshot of HEAD -> {tmp}")
    return tmp


def collect(top_files, src_dirs, doc_dirs, review_dirs, review_files,
            data_dirs, data_files, src_root=None):
    """返回 [(绝对路径, 归档内相对路径)]。

    src_root 给定时，源码与构建文件从该快照读取（保证可编译）；
    文档与数据始终取工作区（文档不参与编译，且可能包含尚未入库的新报告）。
    """
    root = src_root or REPO_ROOT
    items = []

    for rel in top_files:
        full = os.path.join(root, rel)
        if os.path.isfile(full):
            items.append((full, rel))
        else:
            print(f"  [skip] missing top file: {rel}")

    for rel in review_files:
        full = os.path.join(REPO_ROOT, rel)
        if os.path.isfile(full):
            items.append((full, rel))
        else:
            print(f"  [skip] missing review file: {rel}")

    for group, base in ((src_dirs, root), (doc_dirs, REPO_ROOT),
                        (review_dirs, REPO_ROOT), (data_dirs, REPO_ROOT)):
        for rel_dir in group:
            full_dir = os.path.join(base, rel_dir)
            if not os.path.isdir(full_dir):
                print(f"  [skip] missing dir: {rel_dir}")
                continue
            for r, dirs, files in os.walk(full_dir):
                dirs[:] = [d for d in dirs if d not in {".git", "target", ".godot"}]
                for name in files:
                    full = os.path.join(r, name)
                    rel = os.path.relpath(full, base).replace("\\", "/")
                    if should_skip_file(rel, name):
                        continue
                    items.append((full, rel))

    for rel in data_files:
        full = os.path.join(REPO_ROOT, rel)
        if os.path.isfile(full):
            items.append((full, rel))
        else:
            print(f"  [skip] missing data file: {rel}")

    return items


def build_zip(out_path, items, extra_note=None):
    print(f"\nPacking -> {out_path}")
    total_raw = 0
    with zipfile.ZipFile(out_path, "w", zipfile.ZIP_DEFLATED, compresslevel=6) as zf:
        if extra_note:
            zf.writestr("SANDBOX_README.txt", extra_note)
        for full, rel in items:
            zf.write(full, arcname=rel)
            total_raw += os.path.getsize(full)
    size = os.path.getsize(out_path)
    print(f"  files : {len(items)}")
    print(f"  raw   : {total_raw / (1024 * 1024):.2f} MB")
    print(f"  zip   : {size / (1024 * 1024):.2f} MB")
    return size


BASE_NOTE = """Imouto! Life ~Monochrome~ — Rust core + Godot 4.7.2 frontend
Source bundle for cloud-sandbox code review and bug hunting.

LAYOUT
  crates/            8 Rust crates (wolf-format / wolf-save / wolf-vm / wolf-render /
                     wolf-audio / wolf-game / wolf-cli / wolf-gdext)
  godot/             Godot project (scripts/, tests/, project.godot, main.tscn)
  tools/             audit_bytecode.py + build-godot.sh + smoke-godot.sh +
                     parity-godot.sh + reverse-engineering helpers
  docs/              architecture, handoff and review documentation
  work/Data/         unpacked WOLF game data: logic metadata, sprites, fonts and
                     the event backgrounds (work/Data/cg). The backgrounds are
                     full-screen pictures referenced by the save picture table,
                     so they are required for any pixel-level rendering check.
  work/out/          full bytecode dumps (JSON) and review reports
  work/out/review/   24-item defect ledger (BUG-01 .. BUG-24)

HOW TO BUILD AND TEST IN THE SANDBOX
  # 0. unpack the offline dependency bundle into this directory first
  #    (it provides vendor/ and .cargo/config.toml) — the sandbox has no network
  unzip -o ../imouto_life_offline_deps.zip -d .

  # 1. Rust workspace
  cargo check --offline --workspace --all-targets
  cargo test  --offline --workspace

  # 2. Full static bytecode audit over all 63,506 instructions
  python tools/audit_bytecode.py     # writes work/out/BYTECODE_AUDIT_REPORT.md

  # 3. Real-data test suite (needs an absolute WOLF_DATA_ROOT)
  WOLF_DATA_ROOT="$PWD/work/Data" cargo test --offline -p wolf-game --no-fail-fast

NOTES
  * godot/bin/*.dll is intentionally NOT included (Windows-only binary).
  * No target/ build artifacts are included.
  * The Godot editor binary is not included either: it is a 173 MB Windows-only
    executable. The Rust side renders the same frames (`wolf-cli capture`).
"""


def main():
    os.makedirs(OUT_DIR, exist_ok=True)

    snapshot = snapshot_head()

    base_items = collect(TOP_FILES, SRC_DIRS, DOC_DIRS, REVIEW_DIRS,
                          REVIEW_FILES, CORE_DATA_DIRS, CORE_DATA_FILES,
                          src_root=snapshot)
    build_zip(LOGIC_ZIP, base_items, BASE_NOTE)

    # 音频组：只装 BGM/SE/BattleEffect/气泡底图，不重复源码与数据。
    media_items = []
    for rel_dir in FULL_DATA_DIRS:
        full_dir = os.path.join(REPO_ROOT, rel_dir)
        if not os.path.isdir(full_dir):
            print(f"  [skip] missing dir: {rel_dir}")
            continue
        for root, dirs, files in os.walk(full_dir):
            dirs[:] = [d for d in dirs if d not in {".git", "target"}]
            for name in files:
                full = os.path.join(root, name)
                rel = os.path.relpath(full, REPO_ROOT).replace("\\", "/")
                media_items.append((full, rel))
    build_zip(MEDIA_ZIP, media_items,
              "Imouto! Life ~Monochrome~ — audio & effect assets.\n"
              "Unzip into the project root so that work/Data/BGM, work/Data/SE,\n"
              "work/Data/BattleEffect and work/Data/BalloonBase_CafeLatte appear.\n")

    print("\nDone.")


if __name__ == "__main__":
    main()
