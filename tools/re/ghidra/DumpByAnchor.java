// DumpByAnchor.java -- Ghidra 12.2 headless helper (Imouto Life RE)
//
// Locate string literals (or explicit virtual addresses), follow their
// cross references (including one/two levels of pointer-table indirection),
// find the containing functions, decompile them and write the C pseudocode
// to <outdir>/<funcEntry>_<sanitized-anchor>.c.
//
// Invoked by tools/re/ghidra/run_ghidra.sh, which already supplies the
// output directory as the first script argument.
//
// Script args:
//   <outdir>                     first positional argument, REQUIRED (Windows path)
//   "anchor text"                any number of string anchors
//   --va=0x401000                an anchor given as a VA (no literal search)
//   --max-depth=N                pointer-indirection depth (default 2)
//   --max-xref=N                 cap on collected xref sites per anchor (default 200)
//   --ref-window=N               if an anchor has no xref, also look for references
//                                within +/-N bytes (default 64); catches strings that
//                                live inside a bigger concatenated literal blob
//   --timeout=SEC                per-function decompile timeout (default 60)
//   --enc=cp932|utf-8|...        charset used to encode the anchor bytes
//                                (default: UTF-8, falling back to UTF-16LE)
//   --no-scan-ptr                disable raw 4-byte pointer scanning
//   --skip-existing              do not overwrite an existing non-empty .c file
//   --argsfile=PATH              read the argument list (one per line, UTF-8)
//                                from PATH; used by run_ghidra.sh so that
//                                "%", "!" and non-ASCII never pass through cmd
//
// Exit behaviour: never throws on a single anchor/function failure; prints the
// reason and keeps going. The final summary is also written to
// <outdir>/anchor_summary.tsv.

import java.io.File;
import java.io.PrintWriter;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.time.OffsetDateTime;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.DecompiledFunction;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

public class DumpByAnchor extends GhidraScript {

	private static final String USAGE =
		"usage: DumpByAnchor.java <outdir> <anchor>... [--va=0x...] "
		+ "[--max-depth=N] [--max-xref=N] [--timeout=SEC] [--enc=CHARSET] "
		+ "[--no-scan-ptr] [--skip-existing]";

	private static final int MAX_POINTER_HITS_PER_ADDRESS = 24;

	private File outDir;
	private int maxDepth = 2;
	private int maxXref = 200;
	private int timeoutSec = 60;
	private int refWindow = 64;
	private boolean scanPtr = true;
	private boolean skipExisting = false;
	private String encName = null;

	private final List<Anchor> anchors = new ArrayList<>();

	private DecompInterface decompiler;

	// ------------------------------------------------------------------
	// small value types
	// ------------------------------------------------------------------

	private static final class Anchor {
		final String label;
		final String raw;
		final Address va;

		Anchor(String raw) {
			this.raw = raw;
			this.label = raw;
			this.va = null;
		}

		Anchor(String raw, Address va) {
			this.raw = raw;
			this.va = va;
			this.label = "va_" + Long.toHexString(va.getOffset());
		}
	}

	private static final class RefSite {
		final Address site;
		final String kind;
		final int depth;

		RefSite(Address site, String kind, int depth) {
			this.site = site;
			this.kind = kind;
			this.depth = depth;
		}
	}

	// ------------------------------------------------------------------
	// entry point
	// ------------------------------------------------------------------

	@Override
	protected void run() throws Exception {
		List<String> args = expandArgs(getScriptArgs());
		if (args.size() < 2) {
			printerr(USAGE);
			return;
		}
		outDir = new File(args.get(0));

		for (int i = 1; i < args.size(); i++) {
			String a = args.get(i);
			if (a == null || a.isEmpty()) {
				continue;
			}
			if (a.startsWith("--va=")) {
				String v = a.substring("--va=".length()).trim();
				try {
					long value = parseAddressValue(v);
					Address addr = toAddr(value);
					if (addr == null) {
						printerr("[warn] cannot build address for " + v);
						continue;
					}
					anchors.add(new Anchor(v, addr));
				}
				catch (Exception e) {
					printerr("[warn] bad --va value '" + v + "': " + e.getMessage());
				}
			}
			else if (a.startsWith("--max-depth=")) {
				maxDepth = parseInt(a.substring("--max-depth=".length()), maxDepth);
			}
			else if (a.startsWith("--max-xref=")) {
				maxXref = parseInt(a.substring("--max-xref=".length()), maxXref);
			}
			else if (a.startsWith("--timeout=")) {
				timeoutSec = parseInt(a.substring("--timeout=".length()), timeoutSec);
			}
			else if (a.startsWith("--ref-window=")) {
				refWindow = parseInt(a.substring("--ref-window=".length()), refWindow);
			}
			else if (a.startsWith("--enc=")) {
				encName = a.substring("--enc=".length()).trim();
			}
			else if (a.equals("--no-scan-ptr")) {
				scanPtr = false;
			}
			else if (a.equals("--skip-existing")) {
				skipExisting = true;
			}
			else if (a.startsWith("--")) {
				printerr("[warn] unknown option ignored: " + a);
			}
			else {
				anchors.add(new Anchor(a));
			}
		}

		if (anchors.isEmpty()) {
			printerr("no anchors given. " + USAGE);
			return;
		}
		if (!outDir.isDirectory() && !outDir.mkdirs()) {
			printerr("cannot create output directory: " + outDir);
			return;
		}

		println("=== DumpByAnchor ===");
		println("program : " + currentProgram.getName());
		println("outdir  : " + outDir.getAbsolutePath());
		println("anchors : " + anchors.size() + " (maxDepth=" + maxDepth + ", maxXref=" + maxXref
			+ ", pointerScan=" + scanPtr + ")");

		decompiler = new DecompInterface();
		DecompileOptions options = new DecompileOptions();
		try {
			options.grabFromProgram(currentProgram);
		}
		catch (Exception e) {
			printerr("[warn] DecompileOptions.grabFromProgram failed: " + e.getMessage());
		}
		decompiler.setOptions(options);
		decompiler.toggleCCode(true);
		decompiler.toggleSyntaxTree(true);
		if (!decompiler.openProgram(currentProgram)) {
			printerr("decompiler failed to open program: " + decompiler.getLastMessage());
			return;
		}

		PrintWriter summary = null;
		try {
			summary = new PrintWriter(new File(outDir, "anchor_summary.tsv"), "UTF-8");
			summary.println("anchor\tstring_addr\tall_xrefs\tcode_xrefs\tfunction_entries\telapsed_ms");
			summary.flush();

			for (Anchor anchor : anchors) {
				if (monitor.isCancelled()) {
					println("[cancel] stopped before anchor: " + anchor.label);
					break;
				}
				try {
					processAnchor(anchor, summary);
				}
				catch (Exception e) {
					printerr("[error] anchor '" + anchor.label + "' failed: " + e);
				}
				summary.flush();
			}
		}
		finally {
			if (summary != null) {
				summary.close();
			}
			decompiler.dispose();
		}
		println("=== DumpByAnchor done: " + outDir.getAbsolutePath() + " ===");
	}

	// ------------------------------------------------------------------
	// one anchor
	// ------------------------------------------------------------------

	private void processAnchor(Anchor anchor, PrintWriter summary) throws Exception {
		long t0 = System.currentTimeMillis();
		List<Address> found = (anchor.va != null) ? single(anchor.va) : findLiteral(anchor.raw);
		if (found.isEmpty()) {
			println("[miss] '" + anchor.raw + "' : literal not found in memory");
			summary.println(escape(anchor.label) + "\t-\t0\t0\t-\t"
				+ (System.currentTimeMillis() - t0));
			return;
		}
		println("");
		println("[anchor] '" + anchor.raw + "' -> " + found.size() + " address(es)");
		Set<String> writtenThisAnchor = new LinkedHashSet<>();
		for (Address addr : found) {
			if (monitor.isCancelled()) {
				return;
			}
			List<RefSite> refs = collectRefs(addr);
			Address viaBase = addr;
			if (refs.isEmpty() && refWindow > 0) {
				Address base = findNearbyReferencedAddress(addr, refWindow);
				if (base != null) {
					refs = collectRefs(base);
					viaBase = base;
					println("  [window] no xref at " + hex(addr) + ", using base " + hex(base));
				}
			}
			Map<Address, Function> functions = new LinkedHashMap<>();
			int codeRefs = 0;
			StringBuilder siteList = new StringBuilder();
			for (RefSite rs : refs) {
				Function f = getFunctionContaining(rs.site);
				if (f != null) {
					codeRefs++;
					functions.putIfAbsent(f.getEntryPoint(), f);
					if (siteList.length() > 0) {
						siteList.append(',');
					}
					siteList.append(hex(rs.site)).append('(').append(rs.kind).append(')');
				}
			}
			println("  addr " + hex(addr)
				+ (viaBase.equals(addr) ? "" : " (base " + hex(viaBase) + ")")
				+ " : " + refs.size() + " xref site(s), "
				+ codeRefs + " inside functions, " + functions.size() + " function(s)");
			if (!functions.isEmpty()) {
				for (Function f : functions.values()) {
					long size = 0;
					try {
						size = f.getBody().getNumAddresses();
					}
					catch (Exception e) {
						// body may be unavailable on exotic programs; keep size 0
					}
					println("    func " + hex(f.getEntryPoint()) + "  " + f.getName()
						+ "  size=" + size + " bytes");
					String key = hex(f.getEntryPoint()) + "_" + safeName(anchor.label);
					if (writtenThisAnchor.add(key)) {
						writeFunction(anchor, viaBase, refs, f, size);
					}
				}
			}
			summary.println(escape(anchor.label) + "\t" + hex(addr) + "\t" + refs.size() + "\t"
				+ codeRefs + "\t" + escape(siteList.toString()) + "\t"
				+ (System.currentTimeMillis() - t0));
		}
	}

	// ------------------------------------------------------------------
	// literal lookup
	// ------------------------------------------------------------------

	private List<Address> findLiteral(String text) throws Exception {
		List<Address> hits = new ArrayList<>();
		Charset cs = (encName != null) ? Charset.forName(encName) : StandardCharsets.UTF_8;
		searchBytes(text.getBytes(cs), hits);
		if (hits.isEmpty() && encName == null) {
			println("  [info] no UTF-8/ANSI hit, retrying as UTF-16LE");
			searchBytes(text.getBytes(StandardCharsets.UTF_16LE), hits);
		}
		return hits;
	}

	private void searchBytes(byte[] needle, List<Address> hits) {
		if (needle == null || needle.length == 0) {
			return;
		}
		Memory memory = currentProgram.getMemory();
		for (MemoryBlock block : memory.getBlocks()) {
			if (!block.isInitialized() || block.getSize() == 0) {
				continue;
			}
			Address cur = block.getStart();
			Address end = block.getEnd();
			while (cur != null && cur.compareTo(end) <= 0) {
				if (monitor.isCancelled()) {
					return;
				}
				Address hit;
				try {
					hit = memory.findBytes(cur, end, needle, null, true, monitor);
				}
				catch (Exception e) {
					printerr("  [warn] findBytes failed in block " + block.getName() + ": " + e.getMessage());
					break;
				}
				if (hit == null) {
					break;
				}
				if (!hits.contains(hit)) {
					hits.add(hit);
				}
				cur = hit.add(1);
			}
		}
	}

	// ------------------------------------------------------------------
	// xref collection (direct refs + pointer indirection + raw ptr scan)
	// ------------------------------------------------------------------

	private List<RefSite> collectRefs(Address target) {
		Map<Address, RefSite> result = new LinkedHashMap<>();
		Set<Address> seen = new LinkedHashSet<>();
		List<Address> frontier = new ArrayList<>();
		frontier.add(target);
		seen.add(target);

		int depth = 1;
		while (!frontier.isEmpty() && depth <= maxDepth && result.size() < maxXref) {
			List<Address> next = new ArrayList<>();
			for (Address from : frontier) {
				if (result.size() >= maxXref || monitor.isCancelled()) {
					break;
				}
				ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(from);
				while (it.hasNext()) {
					Reference ref = it.next();
					Address site = ref.getFromAddress();
					if (site == null || seen.contains(site)) {
						continue;
					}
					MemoryBlock mb = currentProgram.getMemory().getBlock(site);
					boolean executable = (mb != null) && mb.isExecute();
					seen.add(site);
					if (executable) {
						result.putIfAbsent(site, new RefSite(site, ref.getReferenceType().toString(), depth));
					}
					else if (depth < maxDepth) {
						result.putIfAbsent(site, new RefSite(site, "PTR", depth));
						next.add(site);
					}
					if (result.size() >= maxXref) {
						break;
					}
				}
			}

			if (scanPtr && depth < maxDepth && result.size() < maxXref && !monitor.isCancelled()) {
				for (Address from : frontier) {
					List<Address> slots = scanPointerSlots(from);
					for (Address slot : slots) {
						if (seen.contains(slot)) {
							continue;
						}
						seen.add(slot);
						result.putIfAbsent(slot, new RefSite(slot, "PTR-SCAN", depth));
						next.add(slot);
						if (result.size() >= maxXref) {
							break;
						}
					}
				}
			}

			frontier = next;
			depth++;
		}
		return new ArrayList<>(result.values());
	}

	/**
	 * Returns the closest address within +/-window bytes that has at least one
	 * reference. Used when a literal anchor matched a substring in the middle of
	 * a larger concatenated string blob (only the blob base is referenced).
	 */
	private Address findNearbyReferencedAddress(Address addr, int window) {
		for (int d = 1; d <= window; d++) {
			for (int sign = -1; sign <= 1; sign += 2) {
				Address cand;
				try {
					cand = addr.add((long) sign * (long) d);
				}
				catch (Exception e) {
					continue;
				}
				if (cand == null || currentProgram.getMemory().getBlock(cand) == null) {
					continue;
				}
				if (currentProgram.getReferenceManager().getReferenceCountTo(cand) > 0) {
					return cand;
				}
			}
			if (monitor.isCancelled()) {
				return null;
			}
		}
		return null;
	}

	private List<Address> scanPointerSlots(Address target) {
		List<Address> hits = new ArrayList<>();
		if (target == null) {
			return hits;
		}
		AddressSpace space = target.getAddressSpace();
		if (space == null || space.getSize() > 32) {
			return hits; // 4-byte scan only makes sense for 32-bit address spaces
		}
		long value = target.getOffset();
		byte[] needle = new byte[] {
			(byte) (value & 0xffL),
			(byte) ((value >>> 8) & 0xffL),
			(byte) ((value >>> 16) & 0xffL),
			(byte) ((value >>> 24) & 0xffL)
		};
		Memory memory = currentProgram.getMemory();
		for (MemoryBlock block : memory.getBlocks()) {
			if (!block.isInitialized() || block.getSize() == 0) {
				continue;
			}
			if (block.getSize() > 512L * 1024L * 1024L) {
				continue;
			}
			Address cur = block.getStart();
			Address end = block.getEnd();
			while (hits.size() < MAX_POINTER_HITS_PER_ADDRESS && cur != null && cur.compareTo(end) <= 0) {
				if (monitor.isCancelled()) {
					return hits;
				}
				Address hit;
				try {
					hit = memory.findBytes(cur, end, needle, null, true, monitor);
				}
				catch (Exception e) {
					break;
				}
				if (hit == null) {
					break;
				}
				hits.add(hit);
				cur = hit.add(1);
			}
			if (hits.size() >= MAX_POINTER_HITS_PER_ADDRESS) {
				break;
			}
		}
		return hits;
	}

	// ------------------------------------------------------------------
	// decompile + write
	// ------------------------------------------------------------------

	private void writeFunction(Anchor anchor, Address stringAddr, List<RefSite> refs, Function f, long size) {
		try {
			Address entry = f.getEntryPoint();
			File target = new File(outDir, hex(entry) + "_" + safeName(anchor.label) + ".c");
			if (skipExisting && target.isFile() && target.length() > 0) {
				println("    [skip] " + target.getName());
				return;
			}

			DecompileResults res = decompiler.decompileFunction(f, timeoutSec, monitor);
			String body;
			String status;
			if (res == null) {
				status = "FAILED: decompiler returned null";
				body = "/* " + status + " */\n";
			}
			else if (!res.decompileCompleted() || res.getDecompiledFunction() == null) {
				status = "FAILED: " + (res.getErrorMessage() == null ? "no result" : res.getErrorMessage());
				body = "/* " + status + " */\n";
				printerr("    [decompile-fail] " + hex(entry) + " " + f.getName() + " : "
					+ res.getErrorMessage());
			}
			else {
				DecompiledFunction df = res.getDecompiledFunction();
				body = df.getC();
				status = "OK";
				if (body == null) {
					body = "/* FAILED: empty C */\n";
					status = "FAILED: empty C";
				}
			}

			StringBuilder sb = new StringBuilder();
			sb.append("// Ghidra 12.2 headless decompile (DumpByAnchor)\n");
			sb.append("// program   : ").append(currentProgram.getName()).append('\n');
			sb.append("// function  : ").append(f.getName()).append('\n');
			sb.append("// entry     : ").append(hex(entry)).append('\n');
			sb.append("// size      : ").append(size).append(" bytes\n");
			sb.append("// status    : ").append(status).append('\n');
			sb.append("// anchor    : \"").append(anchor.raw.replace("*/", "* /")).append("\"\n");
			sb.append("// string_va : ").append(hex(stringAddr)).append('\n');
			sb.append("// xrefs     : ");
			boolean first = true;
			for (RefSite rs : refs) {
				if (!first) {
					sb.append(", ");
				}
				first = false;
				sb.append(hex(rs.site)).append('(').append(rs.kind).append(",d").append(rs.depth).append(')');
			}
			sb.append('\n');
			sb.append("// generated : ").append(OffsetDateTime.now()).append('\n');
			sb.append('\n');
			sb.append(body);
			if (!body.endsWith("\n")) {
				sb.append('\n');
			}

			try (PrintWriter out = new PrintWriter(target, "UTF-8")) {
				out.print(sb.toString());
			}
			println("    wrote " + target.getName() + " (" + sb.length() + " chars)");
		}
		catch (Exception e) {
			printerr("    [error] decompile/write failed for " + hex(f.getEntryPoint()) + " : " + e);
		}
	}

	// ------------------------------------------------------------------
	// helpers
	// ------------------------------------------------------------------

	/**
	 * Expands --argsfile=PATH entries (one UTF-8 argument per line) in place.
	 * run_ghidra.sh uses this so that cmd.exe never sees the actual arguments.
	 */
	private static List<String> expandArgs(String[] raw) throws Exception {
		List<String> out = new ArrayList<>();
		if (raw == null) {
			return out;
		}
		for (String a : raw) {
			if (a == null) {
				continue;
			}
			if (a.startsWith("--argsfile=")) {
				File f = new File(a.substring("--argsfile=".length()));
				if (!f.isFile()) {
					throw new IllegalArgumentException("args file not found: " + f.getAbsolutePath());
				}
				for (String line : Files.readAllLines(f.toPath(), StandardCharsets.UTF_8)) {
					if (line == null) {
						continue;
					}
					String s = line;
					if (s.endsWith("\r")) {
						s = s.substring(0, s.length() - 1);
					}
					if (!s.isEmpty()) {
						out.add(s);
					}
				}
			}
			else {
				out.add(a);
			}
		}
		return out;
	}

	private static List<Address> single(Address a) {
		List<Address> l = new ArrayList<>();
		l.add(a);
		return l;
	}

	private static long parseAddressValue(String v) {
		String s = v.trim();
		if (s.startsWith("0x") || s.startsWith("0X")) {
			s = s.substring(2);
		}
		return Long.parseUnsignedLong(s, 16);
	}

	private static int parseInt(String v, int fallback) {
		try {
			return Integer.parseInt(v.trim());
		}
		catch (Exception e) {
			return fallback;
		}
	}

	private static String hex(Address a) {
		return String.format("0x%08x", a.getOffset());
	}

	private static String escape(String s) {
		return s.replace('\t', ' ').replace('\n', ' ').replace('\r', ' ');
	}

	private static String safeName(String s) {
		StringBuilder b = new StringBuilder();
		boolean lastUnderscore = false;
		for (int i = 0; i < s.length() && b.length() < 72; i++) {
			char c = s.charAt(i);
			boolean ok = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
				|| (c >= '0' && c <= '9') || c == '.' || c == '-' || c == '_';
			if (ok) {
				b.append(c);
				lastUnderscore = false;
			}
			else if (!lastUnderscore) {
				b.append('_');
				lastUnderscore = true;
			}
		}
		String r = b.toString();
		while (r.endsWith("_")) {
			r = r.substring(0, r.length() - 1);
		}
		return r.isEmpty() ? "anchor" : r;
	}
}
