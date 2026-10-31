@echo off
setlocal EnableExtensions
rem ---------------------------------------------------------------------------
rem  Imouto! Life ~Monochrome~ (Rust rewrite) launcher  v{{VERSION}}
rem  Usage: Play-ImoutoLife.cmd ["<path to unpacked Data folder>"] [extra args]
rem  Data root: 1st argument > WOLF_DATA_ROOT > .\Data next to this file
rem ---------------------------------------------------------------------------
set "HERE=%~dp0"
set "EXE=%HERE%wolf-cli.exe"
if not exist "%EXE%" (
  echo [error] wolf-cli.exe not found next to this launcher:
  echo         %EXE%
  pause
  exit /b 1
)
set "ROOT=%~1"
if not "%ROOT%"=="" goto have_root
if not "%WOLF_DATA_ROOT%"=="" set "ROOT=%WOLF_DATA_ROOT%"
if not "%ROOT%"=="" goto have_root
if exist "%HERE%Data\BasicData" set "ROOT=%HERE%Data"
:have_root
if "%ROOT%"=="" (
  echo [error] No game data root found.
  echo.
  echo Put the unpacked game Data folder here as:  %HERE%Data
  echo (it must contain BasicData\ and MapData\), or set WOLF_DATA_ROOT,
  echo or pass the path:  Play-ImoutoLife.cmd "D:\path\to\Data"
  echo.
  pause
  exit /b 2
)
if not exist "%ROOT%\BasicData" echo [warn] "%ROOT%\BasicData" not found - the game may fail to load data.
echo [run] "%EXE%" play --root "%ROOT%" %2 %3 %4 %5 %6 %7 %8 %9
"%EXE%" play --root "%ROOT%" %2 %3 %4 %5 %6 %7 %8 %9
set "CODE=%ERRORLEVEL%"
if not "%CODE%"=="0" pause
exit /b %CODE%
