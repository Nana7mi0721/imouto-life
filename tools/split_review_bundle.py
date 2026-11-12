#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
tools/split_review_bundle.py — 把云端沙箱审查包切成不超过 10 MB 的分片

沙箱上传通道有单文件 10 MB 上限，因此这里不再直接投递大 zip，而是把每个 zip
按**原始字节顺序**切成若干片（每片 ≤ PART_SIZE 字节），并在目录内附带：

  * 00_README_FIRST.txt   还原说明
  * 00_restore.sh         一键还原脚本（cat 分片 -> 解压）
  * 00_MANIFEST.sha256    每片与还原后 zip 的 sha256

还原方式：`cat <prefix>.partNN.bin > <name>.zip`，因为分片是同一 zip 的原始字节
切分，拼接后仍是完全合法的 zip 文件（中央目录在末尾，恢复时由 cat 拼回原位）。

用法：
  python -I tools/split_review_bundle.py
产物：
  work/out/sandbox_bundle/          全量包分片（含音视频）
  work/out/sandbox_bundle_lite/     精简包分片（不含音视频）
"""

import hashlib
import os
import shutil
import zipfile

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
OUT_DIR = os.path.join(REPO_ROOT, "work", "out")
# 单一上传目录：两个分片组（logic / full）平铺其中，前缀区分。
UPLOAD_DIR = os.path.join(OUT_DIR, "review_bundle_upload")

# 沙箱单文件上限 10 MB；取 9 MB 留出协议层余量。
PART_SIZE = 9 * 1024 * 1024

LOGIC_ZIP = os.path.join(OUT_DIR, "imouto_life_sandbox.zip")
MEDIA_ZIP = os.path.join(OUT_DIR, "imouto_life_media.zip")
DEPS_ZIP = os.path.join(OUT_DIR, "imouto_life_offline_deps.zip")

RESTORE_SH = """#!/usr/bin/env bash
# 一键还原云端沙箱审查包。
# 用法: bash 00_restore.sh            # 在本目录执行，还原到 ./restored/
set -euo pipefail

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
OUT="$DIR/restored"
mkdir -p "$OUT"

# 解压优先用 python 的 zipfile：它严格按 UTF-8 标志还原文件名，
# 而某些环境下自带 unzip 会用本地代码页把中文路径解码成乱码。
# 只有在 python 不可用时才回落到 unzip -O UTF-8。
unzip_to() {
  local zip="$1" dest="$2"
  mkdir -p "$dest"
  if command -v python3 >/dev/null 2>&1; then
    python3 -c "import zipfile,sys; zipfile.ZipFile(sys.argv[1]).extractall(sys.argv[2])" "$zip" "$dest"
  elif command -v python >/dev/null 2>&1; then
    python -c "import zipfile,sys; zipfile.ZipFile(sys.argv[1]).extractall(sys.argv[2])" "$zip" "$dest"
  elif command -v unzip >/dev/null 2>&1; then
    unzip -q -O UTF-8 -o "$zip" -d "$dest"
  else
    echo "!!! no python3/python/unzip available to extract $zip" >&2
    return 1
  fi
}

restore() {
  local prefix="$1" zip_name="$2"
  # 只有该组分片确实在本地时才还原（可能只上传了其中一组）。
  # 分片与本脚本同目录存放；同时兼容 “子目录/” 布局。
  shopt -s nullglob
  local parts=("$DIR/$prefix".part*.bin "$DIR/$prefix"/"$prefix".part*.bin)
  shopt -u nullglob
  if [ ${#parts[@]} -eq 0 ]; then
    echo "==> skip $zip_name (no parts found for group '$prefix')"
    return 0
  fi
  echo "==> restoring $zip_name from ${#parts[@]} part(s)"
  rm -rf "$OUT/${zip_name%.zip}" "$OUT/$zip_name"
  cat "${parts[@]}" > "$OUT/$zip_name"
  unzip_to "$OUT/$zip_name" "$OUT/${zip_name%.zip}"
  echo "    -> $OUT/${zip_name%.zip}"
}

restore logic imouto_life_sandbox.zip
restore media imouto_life_media.zip
restore deps imouto_life_offline_deps.zip
echo "==> done: $OUT"
"""

README_TXT = """Imouto! Life ~Monochrome~ — cloud sandbox review bundle (split parts)
=========================================================================

WHY SPLIT
  The sandbox upload channel caps a single file at 10 MB, so each bundle is
  cut into ordered byte slices of at most 9 MB. A slice is NOT a zip by
  itself: it is a raw slice of one zip file.

GROUPS (upload what you need)
  logic/  logic.partNN.bin   7 slices   source + docs + bytecode + game data
                                    (incl. work/Data/cg event backgrounds)
  deps/   deps.partNN.bin    9 slices   vendored crates.io tree (offline build)
  media/  media.partNN.bin  11 slices   BGM / SE / BattleEffect audio assets

  RECOMMENDED: upload logic.* + deps.*  (16 slices + this README) and you get
  a fully buildable, fully testable project with the complete bytecode audit
  and the pixel-level visual regression baselines.
  Upload media.* only if you also want an end-to-end play run with audio.

HOW TO RESTORE (inside the sandbox)
  # 1. upload every part of one group into the same directory
  # 2. concatenate the parts in ascending part-number order:
  cat logic.part*.bin > imouto_life_sandbox.zip
  cat deps.part*.bin  > imouto_life_offline_deps.zip
  cat media.part*.bin > imouto_life_media.zip
  #    (the names are zero padded, so lexical order equals numeric order)
  # 3. extract:
  #    recommended: python's zipfile always restores UTF-8 file names;
  #    some unzip builds decode CJK paths with the local code page.
  python3 -c "import zipfile; zipfile.ZipFile('imouto_life_sandbox.zip').extractall('imouto_life_sandbox')"

  OR simply run:   bash 00_restore.sh
  which restores whichever groups are present into ./restored/ using
  python's zipfile (falls back to `unzip -O UTF-8` only when python is absent).

VERIFY
  sha256sum -c 00_MANIFEST.sha256     # checks every uploaded slice

AFTER RESTORE
  # source tree
  cd restored/imouto_life_sandbox/
  python tools/audit_bytecode.py     # 63,506 instructions, pure python

  # offline build (deps group only)
  unzip -o ../imouto_life_offline_deps.zip -d .
  cargo check --offline --workspace --all-targets
  cargo test  --offline --workspace

  # real-data suite
  WOLF_DATA_ROOT="$PWD/work/Data" cargo test --offline -p wolf-game --no-fail-fast

  # pixel-level baselines (work/Data/cg is part of the logic group)
  WOLF_DATA_ROOT="$PWD/work/Data" cargo test --offline -p wolf-cli --test m14_visual_regression

KNOWN ENVIRONMENTAL FAILURE
  wolf-format's `ver6_data_wolf_extracts_every_entry` only runs when the
  original Data.wolf archive is reachable (WOLF_DATA_WOLF / WOLF_GAME_DIR /
  the hard-coded install path). In an offline sandbox it skips and the suite
  stays green. If you do point it at a Data.wolf, it byte-compares every
  entry against work/Data, so the BGM/SE/BattleEffect files must be present
  too — unpack the media group first or expect "文件不存在" on those paths.

GODOT
  The Godot 4.7.2 editor binary is deliberately NOT bundled: it is a 173 MB
  Windows-only executable, useless on a Linux sandbox, and the frontend needs
  a native GDExtension built for the host platform anyway. The Rust side
  covers the same ground (`wolf-cli capture` renders 1024x576 without Godot).
  See docs/GODOT_MIGRATION.md if you want to drive the frontend locally.
"""


def sha256_of(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def split_zip(zip_path, out_dir, prefix):
    """把 zip 按原始字节切成 <= PART_SIZE 的分片。"""
    total = os.path.getsize(zip_path)
    part_count = (total + PART_SIZE - 1) // PART_SIZE
    width = max(2, len(str(part_count)))

    parts = []
    with open(zip_path, "rb") as src:
        for index in range(part_count):
            chunk = src.read(PART_SIZE)
            name = f"{prefix}.part{index + 1:0{width}d}.bin"
            path = os.path.join(out_dir, name)
            with open(path, "wb") as dst:
                dst.write(chunk)
            parts.append(name)

    return parts, total, part_count


def verify_split(zip_path, out_dir, prefix, parts):
    """把分片拼回去，确认与原 zip 字节一致。"""
    merged = os.path.join(out_dir, "_verify.bin")
    with open(merged, "wb") as dst:
        for name in parts:
            with open(os.path.join(out_dir, name), "rb") as src:
                shutil.copyfileobj(src, dst)
    same = sha256_of(merged) == sha256_of(zip_path)
    valid_zip = zipfile.is_zipfile(merged)
    os.remove(merged)
    return same, valid_zip


def clear_dir(path):
    """清空目录内容。目录本身可能被某个进程占用（Windows 上 cwd 锁），
    因此逐个删除文件，删除目录失败时忽略。"""
    if not os.path.isdir(path):
        os.makedirs(path)
        return
    for name in os.listdir(path):
        target = os.path.join(path, name)
        try:
            if os.path.isdir(target):
                shutil.rmtree(target, ignore_errors=True)
            else:
                os.remove(target)
        except OSError:
            pass


def main():
    for path in (LOGIC_ZIP, MEDIA_ZIP, DEPS_ZIP):
        if not os.path.isfile(path):
            raise SystemExit(f"missing bundle: {path} "
                             f"(run tools/pack_review_bundle.py and tools/pack_offline_deps.py first)")

    clear_dir(UPLOAD_DIR)
    os.makedirs(UPLOAD_DIR, exist_ok=True)

    manifest_lines = []
    zip_hashes = []

    for zip_path, prefix, label in (
        (LOGIC_ZIP, "logic", "logic"),
        (MEDIA_ZIP, "media", "media"),
        (DEPS_ZIP, "deps", "deps"),
    ):
        parts, total, count = split_zip(zip_path, UPLOAD_DIR, prefix)
        same, valid = verify_split(zip_path, UPLOAD_DIR, prefix, parts)
        print(f"{label}: {total / (1024*1024):.2f} MB -> {count} part(s) "
              f"(max {os.path.getsize(os.path.join(UPLOAD_DIR, parts[0])) / (1024*1024):.2f} MB) "
              f"byte-identical={same} valid_zip={valid}")
        if not (same and valid):
            raise SystemExit(f"split verification failed for {prefix}")

        for name in parts:
            path = os.path.join(UPLOAD_DIR, name)
            manifest_lines.append(f"{sha256_of(path)}  {name}")
        # 还原后 zip 的哈希单独记录：manifest 只列真正会被上传的分片，
        # 否则 `sha256sum -c` 会因为 zip 不在目录里而报 FAILED。
        zip_hashes.append(f"{sha256_of(zip_path)}  {os.path.basename(zip_path)}")

    with open(os.path.join(UPLOAD_DIR, "00_README_FIRST.txt"), "w",
              encoding="utf-8", newline="\n") as f:
        f.write(README_TXT)
    restore_path = os.path.join(UPLOAD_DIR, "00_restore.sh")
    with open(restore_path, "w", encoding="utf-8", newline="\n") as f:
        f.write(RESTORE_SH)
    os.chmod(restore_path, 0o755)

    manifest_path = os.path.join(UPLOAD_DIR, "00_MANIFEST.sha256")
    with open(manifest_path, "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(manifest_lines) + "\n")

    # 还原后 zip 的哈希写进 README，方便还原后核对整包。
    readme_path = os.path.join(UPLOAD_DIR, "00_README_FIRST.txt")
    with open(readme_path, "w", encoding="utf-8", newline="\n") as f:
        f.write(README_TXT)
        f.write("\nRESTORED ARCHIVE CHECKSUMS (verify after `cat`)\n")
        f.write("-" * 60 + "\n")
        for line in zip_hashes:
            f.write(line + "\n")

    print(f"\nupload dir: {UPLOAD_DIR}")
    print(f"manifest  : {manifest_path}")


if __name__ == "__main__":
    main()
