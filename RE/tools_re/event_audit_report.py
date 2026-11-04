#!/usr/bin/env python3
"""Render work/out/event_reach/report.tsv (from m14_event_reachability) as markdown.

Usage:
    python tools/re/event_audit_report.py [report.tsv] > reachability_tables.md

The tables are pasted into docs/re/EVENT_REACHABILITY.md; the script exists so the
document can be regenerated from a fresh run instead of hand-edited.
"""
import sys
from collections import Counter
from pathlib import Path

DEFAULT = Path(__file__).resolve().parents[2] / "work/out/event_reach/report.tsv"

# Windows consoles default to cp936, which cannot encode the Japanese event names.
if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8")


def load(path):
    rows = []
    with path.open(encoding="utf-8") as handle:
        header = handle.readline().rstrip("\n").split("\t")
        for line in handle:
            parts = line.rstrip("\n").split("\t")
            if len(parts) != len(header):
                continue
            rows.append(dict(zip(header, parts)))
    return rows


def bank(row):
    if row["kind"] == "map":
        return "map " + row["source"].split("/")[-1]
    ident = int(row["id"])
    if ident <= 211:
        return "common 0-211 (WOLF template)"
    if ident <= 303:
        return "common 212-303 (game)"
    return "common 304-349 (unused slots)"


def table(header, rows):
    out = ["| " + " | ".join(header) + " |", "|" + "|".join(["---"] * len(header)) + "|"]
    for line in rows:
        out.append("| " + " | ".join(md(value) for value in line) + " |")
    return "\n".join(out)


def md(text):
    return str(text).replace("|", "\\|").replace("\n", " ")


def main():
    path = Path(sys.argv[1]) if len(sys.argv) > 1 else DEFAULT
    rows = load(path)
    print("### Totals\n")
    statuses = Counter(row["status"] for row in rows)
    print(table(["status", "events"], [[k, v] for k, v in sorted(statuses.items())]))
    print("\n### Per bank\n")
    banks = Counter(bank(row) for row in rows)
    print(table(["bank", "events"], [[k, v] for k, v in sorted(banks.items())]))

    print("\n### Spinning events (deadlock candidates)\n")
    spin = [row for row in rows if row["status"] == "spin"]
    print(table(["kind", "id", "name", "frames", "messages", "choices"],
                [[r["kind"], r["id"], r["name"], r["frames"], r["messages"], r["choices"]]
                 for r in spin]) if spin else "none")

    print("\n### Events that log interpreter warnings\n")
    warn = [row for row in rows if int(row["warnings"]) > 0]
    print(table(["kind", "id", "name", "status", "warnings"],
                [[r["kind"], r["id"], r["name"], r["status"], r["warnings"]] for r in warn])
          if warn else "none")

    print("\n### Events still running after the frame budget\n")
    running = [row for row in rows if row["status"] == "running"]
    print(table(["kind", "id", "name", "frames", "messages", "choices", "pictures"],
                [[r["kind"], r["id"], r["name"], r["frames"], r["messages"], r["choices"],
                  r["pictures"]] for r in running]))

    print("\n### Map events with no active page in the bedroom save\n")
    pages = [row for row in rows if row["status"] == "no_active_page"]
    print(table(["source", "id", "name", "pages", "conditions"],
                [[r["source"], r["id"], r["name"], r["pages"], r["conditions"]] for r in pages]))

    print("\n### Diagnostics by opcode family\n")
    families = {}
    for row in rows:
        for entry in filter(None, (part.strip() for part in row["diagnostics"].split(";"))):
            family = entry.split(":", 1)[0].strip()
            family = " ".join(family.split()[:2])
            slot = families.setdefault(family, {"events": 0, "variants": set()})
            slot["events"] += 1
            slot["variants"].add(entry.rsplit(" x", 1)[0])
    print(table(["diagnostic family", "occurrences", "distinct texts"],
                [[k, v["events"], len(v["variants"])]
                 for k, v in sorted(families.items(), key=lambda kv: -kv[1]["events"])]))


if __name__ == "__main__":
    main()
