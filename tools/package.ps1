#Requires -Version 5.1
<#
.SYNOPSIS
  Build a reproducible release drop for the Imouto! Life Rust rewrite.

.DESCRIPTION
  Builds wolf-cli in release mode and stages a self-contained folder under
  work/out/dist/<version>/ containing wolf-cli.exe, README.txt,
  Play-ImoutoLife.cmd and checksums.txt. The retail game data (~175 MB) is NOT
  bundled; the launcher finds it via argument > WOLF_DATA_ROOT > .\Data.

  This is the PowerShell equivalent of tools/package.sh. Run either one.

.PARAMETER Version
  Override the version (default: [workspace.package] version from Cargo.toml).

.PARAMETER DataRoot
  Unpacked game data folder; only used with -Verify.

.PARAMETER OutRoot
  Output root (default: work/out/dist). The final drop is <OutRoot>/<version>.

.PARAMETER SkipBuild
  Reuse an existing target/release/wolf-cli.exe instead of rebuilding.

.PARAMETER Verify
  After staging, run "wolf-cli.exe verify --root <DataRoot>" as a smoke test.

.EXAMPLE
  powershell -ExecutionPolicy Bypass -File tools/package.ps1

.EXAMPLE
  powershell -ExecutionPolicy Bypass -File tools/package.ps1 -Verify -DataRoot work/Data
#>
[CmdletBinding()]
param(
    [string]$Version,
    [string]$DataRoot,
    [string]$OutRoot = 'work/out/dist',
    [switch]$SkipBuild,
    [switch]$Verify
)

$ErrorActionPreference = 'Stop'
$Repo = Split-Path -Parent $PSScriptRoot
Set-Location $Repo

function Write-Step([string]$m) { Write-Host "==> $m" -ForegroundColor Cyan }

# --- make cargo available (fall back to tools/env.ps1) ---
if (-not (Get-Command cargo -ErrorAction SilentlyContinue)) {
    $envPs1 = Join-Path $PSScriptRoot 'env.ps1'
    if (Test-Path $envPs1) {
        . $envPs1
    } else {
        throw 'cargo not found on PATH and tools/env.ps1 is missing'
    }
}

# --- resolve version ---
if (-not $Version) {
    $cargoToml = [System.IO.File]::ReadAllText((Join-Path $Repo 'Cargo.toml'), [System.Text.Encoding]::UTF8)
    $m = [regex]::Match($cargoToml, '(?ms)^\[workspace\.package\].*?^\s*version\s*=\s*"([^"]+)"')
    if (-not $m.Success) { throw 'could not read [workspace.package] version from Cargo.toml' }
    $Version = $m.Groups[1].Value
}

$Dist = Join-Path $Repo (Join-Path $OutRoot $Version)
Write-Step "version $Version"
Write-Step "staging $Dist"

# --- release build ---
$Exe = Join-Path $Repo 'target/release/wolf-cli.exe'
if ($SkipBuild) {
    Write-Step 'skipping cargo build (-SkipBuild)'
    if (-not (Test-Path $Exe)) { throw "release binary missing: $Exe (run without -SkipBuild)" }
} else {
    Write-Step 'cargo build --release -p wolf-cli'
    & cargo build --release -p wolf-cli
    if ($LASTEXITCODE -ne 0) { throw "cargo build failed (exit $LASTEXITCODE)" }
}

# --- fresh dist dir ---
if (Test-Path $Dist) { Remove-Item -LiteralPath $Dist -Recurse -Force }
New-Item -ItemType Directory -Path $Dist -Force | Out-Null

# --- copy exe ---
Copy-Item -LiteralPath $Exe -Destination (Join-Path $Dist 'wolf-cli.exe') -Force

# --- render templates (token substitution; write UTF-8, no BOM) ---
$built = (Get-Date).ToUniversalTime().ToString('yyyy-MM-dd')
$tok = @{ '{{VERSION}}' = $Version; '{{BUILT}}' = $built }
function Expand-Template([string]$src, [string]$dst) {
    $text = [System.IO.File]::ReadAllText($src, [System.Text.Encoding]::UTF8)
    foreach ($k in $tok.Keys) { $text = $text.Replace($k, $tok[$k]) }
    # normalise to CRLF (idempotent) so rendered Windows files are consistent
    $lf = [string][char]10
    $crlf = [string][char]13 + $lf
    $text = $text.Replace($crlf, $lf).Replace($lf, $crlf)
    $noBom = New-Object System.Text.UTF8Encoding($false)
    [System.IO.File]::WriteAllText($dst, $text, $noBom)
}
Expand-Template (Join-Path $PSScriptRoot 'package/README.txt')  (Join-Path $Dist 'README.txt')
Expand-Template (Join-Path $PSScriptRoot 'package/launcher.cmd') (Join-Path $Dist 'Play-ImoutoLife.cmd')

# --- checksums.txt (SHA-256, "<hash>  <name>", CRLF) ---
Write-Step 'writing checksums.txt'
$files = Get-ChildItem -LiteralPath $Dist -File | Where-Object { $_.Name -ne 'checksums.txt' } | Sort-Object Name
$lines = foreach ($f in $files) {
    $h = (Get-FileHash -LiteralPath $f.FullName -Algorithm SHA256).Hash.ToLowerInvariant()
    "$h  $($f.Name)"
}
$nl = [Environment]::NewLine
[System.IO.File]::WriteAllText((Join-Path $Dist 'checksums.txt'), (($lines -join $nl) + $nl), (New-Object System.Text.UTF8Encoding($false)))

# --- optional smoke verify ---
if ($Verify) {
    if (-not $DataRoot) { throw '-Verify requires -DataRoot <unpacked Data dir>' }
    $resolved = (Resolve-Path $DataRoot).Path
    if (-not (Test-Path (Join-Path $resolved 'BasicData'))) { throw "data root has no BasicData: $resolved" }
    Write-Step "verify --root $resolved"
    & (Join-Path $Dist 'wolf-cli.exe') verify --root $resolved
    if ($LASTEXITCODE -ne 0) { throw "wolf-cli verify failed (exit $LASTEXITCODE)" }
}

# --- summary ---
Write-Step 'dist contents'
Get-ChildItem -LiteralPath $Dist -File | Sort-Object Name | ForEach-Object {
    Write-Host ("  {0,12:N0}  {1}" -f $_.Length, $_.Name)
}
Write-Host ''
Write-Host "Release drop ready: $Dist" -ForegroundColor Green
Write-Host 'Game data is NOT bundled - see README.txt for data-root selection.'
