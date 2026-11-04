#!/usr/bin/env python
"""Capture the five m14 visual-regression scenes and print a Rust BASELINES snippet.

Usage:
    python tools/re/capture_scenes.py [--root work/Data] [--out work/out/m14_visual]

Runs the same CLI invocations as crates/wolf-cli/tests/m14_visual_regression.rs,
parses the report lines, and prints ready-to-paste "Baseline { .. }" entries.
Two passes are taken so the PNG sha256 of each scene can be compared (the test
relies on byte-identical output for a given binary + tree).
"""
import argparse
import hashlib
import json
import os
import re
import subprocess
import sys

sys.stdout.reconfigure(encoding="utf-8")

SCENES = [
    ("title", ["--frames", "240"], False),
    ("map_idle", ["--map", "SampleMapA", "--frames", "600"], False),
    ("saveui", ["--map", "SampleMapA", "--event", "5", "--frames", "40"], False),
    ("day_command", ["--event", "245", "--frames", "240"], True),
    ("hud", ["--frames", "60"], True),
]

NUM = r"([0-9][0-9,]*)"


def num(text):
    return int(text.replace(",", ""))


def field(stdout, name):
    for line in stdout.splitlines():
        stripped = line.strip()
        if stripped.startswith(name) and ":" in stripped:
            return stripped
    raise SystemExit(f"missing line: {name}")


def before(line, marker):
    head = line.split(marker, 1)[0]
    found = re.findall(NUM + r"\s*$", head.strip())
    if not found:
        found = re.findall(NUM, head)
    return num(found[-1])


def parse(stdout):
    frames_line = field(stdout, "frames")
    frames = before(frames_line, "(")
    peak = int(re.search(r"peak\s+(\d+)", frames_line).group(1))
    pic = field(stdout, "pictures")
    live = before(pic, "live")
    quads = before(pic, "textured")
    text_pics = num(re.search(r"([0-9,]+)\s+text picture", pic).group(1))
    choice_line = field(stdout, "choice")
    choice_open = "none open" not in choice_line
    choice_options = before(choice_line, "option(s)") if choice_open else 0
    atlas = before(field(stdout, "atlas"), "image(s)")
    text = re.search(r"^ +text +: ([0-9,]+) item\(s\), ([0-9,]+) glyph\(s\), ([0-9,]+) line\(s\)",
                     stdout, re.M)
    if text is None:
        raise SystemExit("missing text summary line")
    items, glyphs, lines = (num(x) for x in text.groups())
    rendered = field(stdout, "rendered")
    lit, total = [num(x) for x in re.search(r"1024x576,\s*" + NUM + "/" + NUM, rendered).groups()]
    stats = field(stdout, "stats")
    messages = before(stats, "message(s)")
    choices = before(stats, "choice(s)")
    warnings = before(stats, "warning(s)")
    return dict(frames=frames, peak_coroutines=peak, pictures_live=live,
                textured_quads=quads, text_pictures=text_pics,
                choice_open=choice_open, choice_options=choice_options,
                atlas_images=atlas, text_items=items, text_glyphs=glyphs,
                text_lines=lines, nonblack=lit, messages=messages,
                choices=choices, warnings=warnings), total


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default="work/Data")
    ap.add_argument("--out", default="work/out/m14_visual")
    ap.add_argument("--cli", default="target/debug/wolf-cli.exe")
    args = ap.parse_args()
    os.makedirs(args.out, exist_ok=True)
    save = os.path.join(args.root, "Save", "SaveData01.sav")

    report = {}
    for name, extra, load_save in SCENES:
        seeds = []
        for run in (1, 2):
            png = os.path.join(args.out, f"{name}_{run}.png")
            command = [args.cli, "capture", "--root", args.root]
            if load_save:
                command += ["--load-save", save]
            command += extra + ["--out", png]
            proc = subprocess.run(command, capture_output=True, text=True,
                                  encoding="utf-8", errors="replace")
            if proc.returncode != 0:
                raise SystemExit(f"{name}: capture failed\n{proc.stdout}\n{proc.stderr}")
            metrics, total = parse(proc.stdout)
            with open(png, "rb") as handle:
                seeds.append(hashlib.sha256(handle.read()).hexdigest())
            if run == 1:
                report[name] = dict(metrics=metrics, total=total)
        report[name]["png_sha256"] = seeds[0]
        report[name]["deterministic"] = seeds[0] == seeds[1]
        print(f"{name:12} {report[name]['metrics']}  sha256 {seeds[0][:16]}"
              f"  {'stable' if seeds[0] == seeds[1] else 'DIFFERS ON RERUN'}", file=sys.stderr)

    print()
    for name, *_ in SCENES:
        m = report[name]["metrics"]
        print("    Baseline {")
        print(f'        name: "{name}",')
        print(f"        // recorded {report[name]['png_sha256'][:16]} on the current worktree")
        print("        args: &[], // keep the scene arguments from the test")
        print(f"        frames: {m['frames']},")
        print(f"        peak_coroutines: {m['peak_coroutines']},")
        print(f"        pictures_live: {m['pictures_live']},")
        print(f"        textured_quads: {m['textured_quads']},")
        print(f"        text_pictures: {m['text_pictures']},")
        print(f"        choice_open: {'true' if m['choice_open'] else 'false'},")
        print(f"        choice_options: {m['choice_options']},")
        print(f"        atlas_images: {m['atlas_images']},")
        print(f"        text_items: {m['text_items']},")
        print(f"        text_glyphs: {m['text_glyphs']},")
        print(f"        text_lines: {m['text_lines']},")
        print(f"        nonblack: {m['nonblack']},")
        print(f"        messages: {m['messages']},")
        print(f"        choices: {m['choices']},")
        print("    },")
    print()
    print(json.dumps(report, indent=1, ensure_ascii=False))


if __name__ == "__main__":
    main()
