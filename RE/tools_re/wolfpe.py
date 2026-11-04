#!/usr/bin/env python3
"""wolfpe.py — minimal static PE32 analysis toolkit for the original Game.exe.

Purpose: reproducible, engine-free reconnaissance of the WOLF RPG Editor runtime
binary (PE32, x86, statically linked DxLib) used to verify engine-behaviour
constants documented in docs/ENGINE_BEHAVIOR.md.

Requires: pefile, capstone  (both present in the local python env).

Commands:
  facts                       PE identity, sections, imports, version strings
  strings --filter RE         list ascii strings (offset, VA, text)
  xref --string "TEXT"        find code that references an ascii string literal
  xref --va 0x7c6ec8          find code that references an absolute VA
  disasm --va 0x46a21d        linear-disassemble forward from an instruction addr

Never executes the target; read-only.
"""
import argparse, json, re, struct, sys

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32


class Target:
    def __init__(self, path):
        self.path = path
        with open(path, "rb") as f:
            self.data = f.read()
        self.pe = pefile.PE(path, fast_load=True)
        self.base = self.pe.OPTIONAL_HEADER.ImageBase
        self.sections = []
        for s in self.pe.sections:
            self.sections.append({
                "name": s.Name.rstrip(b"\x00").decode("latin1", "replace"),
                "va": self.base + s.VirtualAddress,
                "vsize": s.Misc_VirtualSize,
                "raw": s.PointerToRawData,
                "rawsize": s.SizeOfRawData,
            })
        self.md = Cs(CS_ARCH_X86, CS_MODE_32)
        self.md.skipdata = True

    def off_of(self, va):
        rva = va - self.base
        for s in self.sections:
            if s["va"] <= va < s["va"] + max(s["vsize"], s["rawsize"]):
                off = s["raw"] + (rva - (s["va"] - self.base))
                if 0 <= off < len(self.data):
                    return off
        return None

    def va_of(self, off):
        for s in self.sections:
            if s["raw"] <= off < s["raw"] + s["rawsize"]:
                return s["va"] + (off - s["raw"])
        return None

    def text_span(self):
        for s in self.sections:
            if s["name"] == ".text":
                return self.data[s["raw"]:s["raw"] + s["rawsize"]], s["va"]
        raise RuntimeError("no .text")

    def strings(self, min_len=4, ascii_only=True):
        pat = rb"[\x20-\x7e]{%d,}" % min_len
        out = []
        for m in re.finditer(pat, self.data):
            out.append({"off": m.start(), "va": self.va_of(m.start()),
                        "text": m.group().decode("latin1")})
        if not ascii_only:
            for m in re.finditer(rb"(?:[\x20-\x7e][\x00]){%d,}" % min_len, self.data):
                try:
                    t = m.group().decode("utf-16le")
                except Exception:
                    continue
                out.append({"off": m.start(), "va": self.va_of(m.start()),
                            "text": t, "enc": "utf16"})
        out.sort(key=lambda x: x["off"])
        return out

    def resolve_string(self, text):
        b = text.encode("latin1")
        hits = []
        i = 0
        while True:
            j = self.data.find(b, i)
            if j < 0:
                break
            hits.append(j)
            i = j + 1
        return [{"off": o, "va": self.va_of(o)} for o in hits]

    def find_xrefs(self, target_va):
        tb, tbase = self.text_span()
        pat = struct.pack("<I", target_va & 0xFFFFFFFF)
        res = []
        i = 0
        while True:
            j = tb.find(pat, i)
            if j < 0:
                break
            addr = tbase + j
            off = self.off_of(addr)
            prev = self.data[off - 1] if off else None
            kind = "imm32"
            instr = addr
            if prev == 0x68:
                kind, instr = "push", addr - 1
            elif prev is not None and 0xB8 <= prev <= 0xBF:
                kind, instr = "mov-reg", addr - 1
            res.append({"hit_va": addr, "instr_va": instr, "kind": kind})
            i = j + 1
        return res

    def disasm(self, va, length=96):
        off = self.off_of(va)
        if off is None:
            return []
        code = self.data[off:off + length]
        out = []
        for ins in self.md.disasm(code, va):
            out.append({"addr": ins.address, "bytes": ins.bytes.hex(),
                        "mnemonic": ins.mnemonic, "op_str": ins.op_str})
            if ins.address - va > length:
                break
        return out


def cmd_facts(t, args):
    pe = t.pe
    # full import parse
    try:
        pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_IMPORT"]])
    except Exception:
        pass
    imports = {}
    if hasattr(pe, "DIRECTORY_ENTRY_IMPORT"):
        for d in pe.DIRECTORY_ENTRY_IMPORT:
            names = [i.name.decode("latin1") for i in d.imports if i.name]
            imports[d.dll.decode("latin1")] = names
    strs = t.strings(6)
    ver = sorted({s["text"].strip() for s in strs
                  if re.search(r"(ver\d|Ver2\.|WOLF RPG EDITOR|WOLF RPG$)", s["text"])})
    facts = {
        "path": t.path,
        "size": len(t.data),
        "sha256": __import__("hashlib").sha256(t.data).hexdigest(),
        "machine": hex(pe.FILE_HEADER.Machine),
        "subsystem": pe.OPTIONAL_HEADER.Subsystem,
        "image_base": hex(t.base),
        "timestamp": pe.FILE_HEADER.TimeDateStamp,
        "sections": [{"name": s["name"], "va": hex(s["va"]), "vsize": hex(s["vsize"]),
                      "raw": hex(s["raw"]), "rawsize": hex(s["rawsize"])} for s in t.sections],
        "imports": imports,
        "version_strings": ver[:40],
    }
    print(json.dumps(facts, ensure_ascii=False, indent=2))


def cmd_strings(t, args):
    rx = re.compile(args.filter) if args.filter else None
    out = []
    for s in t.strings(args.min, ascii_only=not args.utf16):
        if rx and not rx.search(s["text"]):
            continue
        out.append(s)
    for s in out[: args.limit]:
        print("@%-9d %-10s %s" % (s["off"], hex(s["va"]) if s["va"] else "-", s["text"][:140]))
    if len(out) > args.limit:
        print("... (%d more)" % (len(out) - args.limit))


def cmd_xref(t, args):
    if args.string:
        locs = t.resolve_string(args.string)
        if not locs:
            print("string not found:", args.string)
            return
        for loc in locs:
            if loc["va"] is None:
                continue
            xs = t.find_xrefs(loc["va"])
            print("string %r off=%d va=%s xrefs=%d" % (args.string, loc["off"], hex(loc["va"]), len(xs)))
            for x in xs[: args.max]:
                print("  xref hit=%s instr=%s kind=%s" % (hex(x["hit_va"]), hex(x["instr_va"]), x["kind"]))
                if args.disasm:
                    for ins in t.disasm(x["instr_va"], args.length):
                        mark = " <=" if ins["addr"] == x["instr_va"] else ""
                        print("     %08x: %-18s %s %s%s" % (ins["addr"], ins["bytes"], ins["mnemonic"], ins["op_str"], mark))
    else:
        va = int(args.va, 16)
        xs = t.find_xrefs(va)
        print("va %s xrefs=%d" % (hex(va), len(xs)))
        for x in xs[: args.max]:
            print("  hit=%s instr=%s kind=%s" % (hex(x["hit_va"]), hex(x["instr_va"]), x["kind"]))
            if args.disasm:
                for ins in t.disasm(x["instr_va"], args.length):
                    print("     %08x: %-18s %s %s" % (ins["addr"], ins["bytes"], ins["mnemonic"], ins["op_str"]))


def cmd_disasm(t, args):
    for ins in t.disasm(int(args.va, 16), args.length):
        print("%08x: %-18s %s %s" % (ins["addr"], ins["bytes"], ins["mnemonic"], ins["op_str"]))


def main(argv=None):
    ap = argparse.ArgumentParser(description="Static PE32 toolkit for the WOLF RPG Editor Game.exe")
    ap.add_argument("exe", help="path to Game.exe")
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("facts"); p.set_defaults(fn=cmd_facts)

    p = sub.add_parser("strings")
    p.add_argument("--filter"); p.add_argument("--min", type=int, default=5)
    p.add_argument("--limit", type=int, default=200); p.add_argument("--utf16", action="store_true")
    p.set_defaults(fn=cmd_strings)

    p = sub.add_parser("xref")
    g = p.add_mutually_exclusive_group(required=True)
    g.add_argument("--string"); g.add_argument("--va")
    p.add_argument("--disasm", action="store_true"); p.add_argument("--length", type=int, default=96)
    p.add_argument("--max", type=int, default=8)
    p.set_defaults(fn=cmd_xref)

    p = sub.add_parser("disasm")
    p.add_argument("--va", required=True); p.add_argument("--length", type=int, default=128)
    p.set_defaults(fn=cmd_disasm)

    args = ap.parse_args(argv)
    t = Target(args.exe)
    args.fn(t, args)


if __name__ == "__main__":
    main()
