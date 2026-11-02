// DumpAll.java -- Ghidra 12.2 headless helper (Imouto Life RE)
//
// Decompile every user-defined function (thunks / externals excluded) and write
// one .c file per function plus a machine-readable index:
//
//   <outdir>/all/<entry>_<name>.c
//   <outdir>/all/index.tsv     (header: entry  name  size  file)
//
// Script args:
//   <outdir>                first positional argument, REQUIRED
//   --min-size=N            skip functions smaller than N bytes (default 0)
//   --max-size=N            skip functions larger than N bytes (default unlimited)
//   --filter=REGEX          only functions whose name matches the Java regex
//   --include-thunks        also dump thunks
//   --include-external      also dump external functions (normally no body)
//   --limit=N               stop after N written functions (debugging)
//   --timeout=SEC           per-function decompile timeout (default 60)
//   --skip-existing         do not overwrite existing non-empty .c files
//   --dir=NAME              output subdirectory name (default "all")
//   --quiet                 only print the final summary
//   --argsfile=PATH         read the argument list (one per line, UTF-8) from PATH;
//                           run_ghidra.sh uses this so cmd.exe never mangles args
//
// Progress is printed every 25 functions; the script honours the Ghidra
// TaskMonitor, so a cancelled headless job stops cleanly after the current
// function and the index still contains everything written so far.

import java.io.File;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.time.OffsetDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.DecompiledFunction;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DumpAll extends GhidraScript {

	private static final String USAGE =
		"usage: DumpAll.java <outdir> [--min-size=N] [--max-size=N] [--filter=REGEX] "
		+ "[--include-thunks] [--include-external] [--limit=N] [--timeout=SEC] "
		+ "[--skip-existing] [--dir=NAME] [--quiet]";

	private File outDir;
	private File funcDir;
	private long minSize = 0;
	private long maxSize = Long.MAX_VALUE;
	private Pattern nameFilter = null;
	private boolean includeThunks = false;
	private boolean includeExternal = false;
	private boolean skipExisting = false;
	private boolean quiet = false;
	private int limit = Integer.MAX_VALUE;
	private int timeoutSec = 60;
	private String subDirName = "all";

	private DecompInterface decompiler;

	@Override
	protected void run() throws Exception {
		List<String> args = expandArgs(getScriptArgs());
		if (args.isEmpty()) {
			printerr(USAGE);
			return;
		}
		outDir = new File(args.get(0));

		for (int i = 1; i < args.size(); i++) {
			String a = args.get(i);
			if (a == null || a.isEmpty()) {
				continue;
			}
			if (a.startsWith("--min-size=")) {
				minSize = parseLong(a.substring("--min-size=".length()), minSize);
			}
			else if (a.startsWith("--max-size=")) {
				maxSize = parseLong(a.substring("--max-size=".length()), maxSize);
			}
			else if (a.startsWith("--filter=")) {
				try {
					nameFilter = Pattern.compile(a.substring("--filter=".length()));
				}
				catch (Exception e) {
					printerr("[warn] bad --filter regex, ignoring: " + e.getMessage());
				}
			}
			else if (a.equals("--include-thunks")) {
				includeThunks = true;
			}
			else if (a.equals("--include-external")) {
				includeExternal = true;
			}
			else if (a.equals("--skip-existing")) {
				skipExisting = true;
			}
			else if (a.equals("--quiet")) {
				quiet = true;
			}
			else if (a.startsWith("--limit=")) {
				limit = parseInt(a.substring("--limit=".length()), limit);
			}
			else if (a.startsWith("--timeout=")) {
				timeoutSec = parseInt(a.substring("--timeout=".length()), timeoutSec);
			}
			else if (a.startsWith("--dir=")) {
				subDirName = a.substring("--dir=".length()).trim();
			}
			else {
				printerr("[warn] unknown argument ignored: " + a);
			}
		}
		if (subDirName.isEmpty()) {
			subDirName = "all";
		}

		funcDir = new File(outDir, subDirName);
		if (!funcDir.isDirectory() && !funcDir.mkdirs()) {
			printerr("cannot create output directory: " + funcDir);
			return;
		}

		println("=== DumpAll ===");
		println("program : " + currentProgram.getName());
		println("outdir  : " + funcDir.getAbsolutePath());
		println("filter  : minSize=" + minSize + " maxSize=" + maxSize
			+ " name=" + (nameFilter == null ? "*" : nameFilter.pattern())
			+ " thunks=" + includeThunks + " externals=" + includeExternal
			+ " limit=" + (limit == Integer.MAX_VALUE ? "none" : Integer.toString(limit)));

		List<Function> functions = new ArrayList<>();
		java.util.Set<ghidra.program.model.address.Address> seenEntries = new java.util.LinkedHashSet<>();
		for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
			if (monitor.isCancelled()) {
				break;
			}
			if (!accept(f)) {
				continue;
			}
			seenEntries.add(f.getEntryPoint());
			functions.add(f);
		}
		// getFunctions() does not walk the EXTERNAL address space; add those
		// separately when the caller explicitly asked for them.
		if (includeExternal && !monitor.isCancelled()) {
			for (Function f : currentProgram.getFunctionManager().getExternalFunctions()) {
				if (!accept(f) || seenEntries.contains(f.getEntryPoint())) {
					continue;
				}
				seenEntries.add(f.getEntryPoint());
				functions.add(f);
			}
		}
		println("functions to dump: " + functions.size() + " (of "
			+ currentProgram.getFunctionManager().getFunctionCount() + " total)");

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

		int total = functions.size();
		int written = 0;
		int skipped = 0;
		int failed = 0;
		long startMs = System.currentTimeMillis();

		PrintWriter index = null;
		try {
			index = new PrintWriter(new File(funcDir, "index.tsv"), "UTF-8");
			index.println("entry\tname\tsize\tfile");
			index.flush();

			int i = 0;
			for (Function f : functions) {
				if (monitor.isCancelled()) {
					println("[cancel] stopped at " + i + "/" + total);
					break;
				}
				i++;
				Address entry = f.getEntryPoint();
				long size = bodySize(f);
				String fileName = hex(entry) + "_" + safeName(f.getName()) + ".c";
				File target = new File(funcDir, fileName);

				if (skipExisting && target.isFile() && target.length() > 0) {
					skipped++;
					index.println(hex(entry) + "\t" + tab(f.getName()) + "\t" + size + "\t" + fileName);
					continue;
				}

				String status;
				try {
					DecompileResults res = decompiler.decompileFunction(f, timeoutSec, monitor);
					String body;
					if (res == null) {
						status = "FAILED: decompiler returned null";
						body = "/* " + status + " */\n";
					}
					else if (!res.decompileCompleted() || res.getDecompiledFunction() == null) {
						status = "FAILED: " + (res.getErrorMessage() == null ? "no result" : res.getErrorMessage());
						body = "/* " + status + " */\n";
						failed++;
					}
					else {
						DecompiledFunction df = res.getDecompiledFunction();
						body = df.getC();
						if (body == null || body.isEmpty()) {
							status = "FAILED: empty C";
							body = "/* " + status + " */\n";
							failed++;
						}
						else {
							status = "OK";
						}
					}
					writeFile(target, f, entry, size, status, body);
					written++;
				}
				catch (Exception e) {
					failed++;
					printerr("[error] " + hex(entry) + " " + f.getName() + " : " + e);
				}

				index.println(hex(entry) + "\t" + tab(f.getName()) + "\t" + size + "\t" + fileName);

				if (i % 25 == 0 || i == total) {
					index.flush();
					long elapsed = System.currentTimeMillis() - startMs;
					double rate = (elapsed > 0) ? (i * 1000.0 / elapsed) : 0.0;
					println(String.format("[%d/%d] written=%d failed=%d elapsed=%.1fs (%.2f fn/s)",
						i, total, written, failed, elapsed / 1000.0, rate));
				}
				if (written >= limit) {
					println("[limit] reached --limit=" + limit);
					break;
				}
			}
		}
		finally {
			if (index != null) {
				index.flush();
				index.close();
			}
			decompiler.dispose();
		}

		long elapsed = System.currentTimeMillis() - startMs;
		println("=== DumpAll done ===");
		println("total=" + total + " written=" + written + " skipped=" + skipped
			+ " failed=" + failed + " elapsed=" + String.format("%.1fs", elapsed / 1000.0));
		println("index: " + new File(funcDir, "index.tsv").getAbsolutePath());
	}

	/**
	 * Expands --argsfile=PATH entries (one UTF-8 argument per line) in place.
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

	private void writeFile(File target, Function f, Address entry, long size, String status, String body)
			throws Exception {
		StringBuilder sb = new StringBuilder();
		sb.append("// Ghidra 12.2 headless decompile (DumpAll)\n");
		sb.append("// program   : ").append(currentProgram.getName()).append('\n');
		sb.append("// function  : ").append(f.getName()).append('\n');
		sb.append("// entry     : ").append(hex(entry)).append('\n');
		sb.append("// size      : ").append(size).append(" bytes\n");
		if (f.isThunk()) {
			sb.append("// thunk     : yes\n");
		}
		if (f.isExternal()) {
			sb.append("// external  : yes\n");
		}
		sb.append("// status    : ").append(status).append('\n');
		sb.append("// generated : ").append(OffsetDateTime.now()).append('\n');
		sb.append('\n');
		sb.append(body);
		if (!body.endsWith("\n")) {
			sb.append('\n');
		}
		try (PrintWriter out = new PrintWriter(target, "UTF-8")) {
			out.print(sb.toString());
		}
	}

	private boolean accept(Function f) {
		if (f == null || f.isDeleted()) {
			return false;
		}
		if (!includeThunks && f.isThunk()) {
			return false;
		}
		if (!includeExternal && f.isExternal()) {
			return false;
		}
		if (nameFilter != null && !nameFilter.matcher(f.getName()).find()) {
			return false;
		}
		long size = bodySize(f);
		return size >= minSize && size <= maxSize;
	}

	private static long bodySize(Function f) {
		try {
			return f.getBody().getNumAddresses();
		}
		catch (Exception e) {
			return 0;
		}
	}

	private static long parseLong(String v, long fallback) {
		try {
			return Long.parseLong(v.trim());
		}
		catch (Exception e) {
			return fallback;
		}
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

	private static String tab(String s) {
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
		return r.isEmpty() ? "fun" : r;
	}
}
