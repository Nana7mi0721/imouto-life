========================================================================
 Imouto! Life ~Monochrome~ — Rust rewrite launcher package  v{{VERSION}}
 Build date (UTC): {{BUILT}}
========================================================================

This is a from-source diagnostic/runtime front end (wolf-cli.exe), NOT a drop-in
replacement for the retail game executable. It needs an UNPACKED game data folder
(the "Data" directory that contains BasicData\ and MapData\).

1) Prepare the data
   Put the unpacked Data folder next to this launcher and name it Data
   (so this folder\Data\BasicData\... exists), OR set the environment variable
   WOLF_DATA_ROOT to that folder, OR pass the path as the first argument.

2) Start the game window
   Double-click Play-ImoutoLife.cmd
   or from a command prompt:
     Play-ImoutoLife.cmd "D:\path\to\Data"
   The window is 1024x576. Arrow keys move, Enter/Z or the mouse confirms, F12
   restarts. Add --audio as a later argument to play BGM/SE (silent if no device).

3) Diagnostics (call wolf-cli.exe directly)
     wolf-cli.exe verify  --root "D:\path\to\Data"
     wolf-cli.exe verify  --root "D:\path\to\Data" --wolf "D:\...\Data.wolf"
     wolf-cli.exe capture --root "D:\path\to\Data" --menu-only --frames 120 --out shot.png
     wolf-cli.exe --help

4) Integrity
   checksums.txt lists the SHA-256 of every file in this package. Verify with:
     sha256sum -c checksums.txt              (msys / git-bash)
     Get-FileHash <file> -Algorithm SHA256    (PowerShell)

Notes
 - No game data is bundled (images, BGM/SE, fonts: about 175 MB). Bring your own.
 - 64-bit Windows is required. The UI font is the system "Microsoft Yahei UI Bold"
   (msyhbd.ttc); if it is missing the loader falls back to fonts bundled in the
   data root or next to the install.
 - This project does not promise binary compatibility with the retail .exe and
   must not be resold.
