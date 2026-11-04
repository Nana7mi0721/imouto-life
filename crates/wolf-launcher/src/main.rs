#![cfg_attr(target_os = "windows", windows_subsystem = "windows")]

//! Double-click launcher for a packaged copy of the game.
//!
//! The package looks like this:
//!
//!   Imouto Life.exe        (this launcher)
//!   runtime\wolf-cli.exe   (the actual engine + front end)
//!   Data\                  (unpacked game data, including BasicData)
//!
//! Keeping the launcher separate from wolf-cli lets the release keep a normal
//! console-free GUI executable while the engine remains a regular CLI binary.
//! Additional play flags are forwarded, so a shortcut may use e.g.
//!   Imouto Life.exe --load-save "Data\Save\SaveData01.sav"

use std::fs::OpenOptions;
use std::path::{Path, PathBuf};
use std::process::{Command, Stdio};

fn main() {
    let dir = executable_dir();
    let game = locate_engine(&dir);
    let data = dir.join("Data");

    let Some(game) = game else {
        fail(
            &dir,
            "找不到游戏引擎 runtime\\wolf-cli.exe。\n请确认发布包完整，不要只复制启动器。",
        );
        return;
    };
    if !data.join("BasicData").is_dir() {
        fail(
            &dir,
            "找不到游戏数据目录 Data\\BasicData。\n请确认发布包完整（Data 文件夹需与启动器放在同一目录）。",
        );
        return;
    }

    let log_path = dir.join("game-log.txt");
    let log = OpenOptions::new()
        .create(true)
        .truncate(true)
        .write(true)
        .open(&log_path)
        .ok();

    let mut cmd = Command::new(&game);
    cmd.current_dir(&dir)
        .arg("play")
        .arg("--root")
        .arg(&data)
        .arg("--audio");
    for arg in std::env::args().skip(1) {
        cmd.arg(arg);
    }

    if let Some(file) = log {
        match file.try_clone() {
            Ok(copy) => {
                cmd.stdout(Stdio::from(copy));
                cmd.stderr(Stdio::from(file));
            }
            Err(_) => {
                cmd.stdout(Stdio::null());
                cmd.stderr(Stdio::null());
            }
        }
    } else {
        cmd.stdout(Stdio::null());
        cmd.stderr(Stdio::null());
    }

    #[cfg(windows)]
    {
        use std::os::windows::process::CommandExt;
        // CREATE_NO_WINDOW: the engine is a console program, but a normal game
        // launch should not flash a black terminal window.
        cmd.creation_flags(0x0800_0000);
    }

    match cmd.status() {
        Ok(status) if status.success() => {}
        Ok(status) => {
            let code = status
                .code()
                .map(|c| c.to_string())
                .unwrap_or_else(|| "unknown".to_string());
            fail(
                &dir,
                &format!(
                    "游戏进程异常退出（代码 {code}）。\n详细信息见：{}",
                    log_path.display()
                ),
            );
        }
        Err(err) => fail(
            &dir,
            &format!("无法启动游戏引擎：{err}\n引擎路径：{}", game.display()),
        ),
    }
}

fn executable_dir() -> PathBuf {
    std::env::current_exe()
        .ok()
        .and_then(|p| p.parent().map(Path::to_path_buf))
        .or_else(|| std::env::current_dir().ok())
        .unwrap_or_else(|| PathBuf::from("."))
}

fn locate_engine(dir: &Path) -> Option<PathBuf> {
    let nested = dir.join("runtime").join("wolf-cli.exe");
    if nested.is_file() {
        return Some(nested);
    }
    let flat = dir.join("wolf-cli.exe");
    flat.is_file().then_some(flat)
}

fn fail(dir: &Path, message: &str) {
    let path = dir.join("launcher-error.log");
    let _ = std::fs::write(&path, message);
    let full = format!("{message}\n\n记录文件：{}", path.display());
    message_box("妹！生活 - 启动失败", &full);
}

#[cfg(windows)]
fn message_box(title: &str, message: &str) {
    use std::ffi::OsStr;
    use std::os::windows::ffi::OsStrExt;

    fn wide(value: &str) -> Vec<u16> {
        OsStr::new(value)
            .encode_wide()
            .chain(std::iter::once(0))
            .collect()
    }

    #[link(name = "user32")]
    extern "system" {
        fn MessageBoxW(
            hwnd: *mut core::ffi::c_void,
            text: *const u16,
            caption: *const u16,
            utype: u32,
        ) -> i32;
    }

    let text = wide(message);
    let caption = wide(title);
    const MB_ICONERROR: u32 = 0x10;
    unsafe {
        MessageBoxW(
            std::ptr::null_mut(),
            text.as_ptr(),
            caption.as_ptr(),
            MB_ICONERROR,
        );
    }
}

#[cfg(not(windows))]
fn message_box(_title: &str, message: &str) {
    eprintln!("{message}");
}
