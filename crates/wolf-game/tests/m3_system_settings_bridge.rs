//! M3-AC：系统设置（Save/System.sav）运行时桥接测试补强。
//!
//! F12 重启与系统设置在 HEAD 已落地：play.rs 启动时 apply_settings（:56）、退出时
//! settings_dirty→save_system_settings（:130）、F12 重建 Game 再 boot（:193/:214）。
//! 本文件只做纯测试补强，覆盖设置的「落盘桥接」与「重启等价性」，不改任何 src。
//!
//! 安全：直接写真实 Save/System.sav 的用例都先备份原始字节（长度 + FNV），并持有一个
//! Drop guard，测试体显式 restore，panic 时 Drop 也会恢复，最终断言字节与长度一致。
//! 缺数据（work/Data 不存在 / System.sav 读不到）时各用例 eprintln skipping 后 return，
//! 默认 workspace 运行 exit 0。

use std::path::PathBuf;

use wolf_game::Game;
use wolf_save::SaveFile;

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let path = PathBuf::from(raw);
    if path.is_absolute() {
        return path;
    }
    let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    base.pop();
    base.pop();
    base.join(path)
}

fn repo_root() -> PathBuf {
    let mut root = data_root();
    root.pop();
    root.pop();
    root
}

fn fnv(bytes: &[u8]) -> u64 {
    let mut h: u64 = 0xcbf2_9ce4_8422_2325;
    for &b in bytes {
        h ^= b as u64;
        h = h.wrapping_mul(0x1_0000_0001_b3);
    }
    h
}

/// 备份 Save/System.sav；Drop 时务必恢复原字节，保证真实数据目录干净。
struct SystemSaveGuard {
    path: PathBuf,
    original: Vec<u8>,
    original_sha: u64,
}

impl SystemSaveGuard {
    fn install() -> Option<Self> {
        let path = data_root().join("Save").join("System.sav");
        let original = match std::fs::read(&path) {
            Ok(bytes) => bytes,
            Err(err) => {
                eprintln!("skipping: cannot read {}: {err}", path.display());
                return None;
            }
        };
        let sha = fnv(&original);
        let backup_dir = repo_root()
            .join("work")
            .join("out")
            .join("m3_system_settings_backup");
        if std::fs::create_dir_all(&backup_dir).is_ok() {
            let _ = std::fs::write(backup_dir.join("System.sav"), &original);
        }
        eprintln!(
            "System.sav backed up: {} bytes sha={sha:016x}",
            original.len()
        );
        Some(Self {
            path,
            original,
            original_sha: sha,
        })
    }

    fn restore(&self) {
        let _ = std::fs::write(&self.path, &self.original);
    }

    fn assert_untouched(&self, context: &str) {
        let after = std::fs::read(&self.path).expect("re-read System.sav");
        assert_eq!(
            after.len(),
            self.original.len(),
            "{context}: System.sav 长度变了"
        );
        assert_eq!(
            fnv(&after),
            self.original_sha,
            "{context}: System.sav 字节变了"
        );
        assert_eq!(after, self.original, "{context}: System.sav 未恢复原样");
    }
}

impl Drop for SystemSaveGuard {
    fn drop(&mut self) {
        match std::fs::read(&self.path) {
            Ok(current) if current == self.original => {}
            _ => {
                let _ = std::fs::write(&self.path, &self.original);
            }
        }
    }
}

fn open_game() -> Option<Game> {
    match Game::new(data_root()) {
        Ok(game) => Some(game),
        Err(err) => {
            eprintln!(
                "skipping: cannot open data root {}: {err}",
                data_root().display()
            );
            None
        }
    }
}

// ---------------------------------------------------------------------------
// 1) + 2) Sys100/101/102 -> save_system_settings -> 真实 System.sav 落盘桥接
// ---------------------------------------------------------------------------

/// 把 Sys100/101/102 设成不同值，走真实 save_system_settings 写盘，再重新 parse
/// System.sav：断言 vars72_74、checksum 有效，且邻近字段与原始文件逐项不变。
///
/// 关键映射：持久化的 BGM 音量取 Sys100（Sys101 只是屏幕镜像、不参与落盘），
/// SE 取 Sys102，ambient 来自模板不变。
#[test]
fn sys_volumes_persist_to_system_sav_with_checksum_and_intact_neighbours() {
    let Some(guard) = SystemSaveGuard::install() else {
        return;
    };
    let Some(mut game) = open_game() else {
        return;
    };
    let original = SaveFile::parse(&guard.original).expect("parse pristine System.sav");
    assert!(original.checksum_ok(), "原始 System.sav checksum 应有效");

    // Sys101 故意设成与 Sys100 不同的值，证明落盘只认 Sys100 而非镜像变量。
    game.vm.vars.set_sys(100, 70);
    game.vm.vars.set_sys(101, 111);
    game.vm.vars.set_sys(102, 35);

    game.save_system_settings().expect("save_system_settings");

    let bytes = std::fs::read(&guard.path).expect("re-read written System.sav");
    assert_eq!(
        bytes.len(),
        guard.original.len(),
        "写回后 System.sav 长度应不变"
    );
    let written = SaveFile::parse(&bytes).expect("parse written System.sav");
    assert!(written.checksum_ok(), "写回的 System.sav checksum 应有效");

    let p2 = &written.part2;
    assert_eq!(
        p2.vars72_74,
        [70, 35, original.part2.vars72_74[2]],
        "vars72_74 = [Sys100 BGM, Sys102 SE, 模板 ambient]；Sys101 不应参与落盘"
    );
    // 邻近字段（含 key config、窗口颜色、其余系统段）必须与原始文件逐项相同。
    assert_eq!(
        p2.vars64_69, original.part2.vars64_69,
        "key-config words 不应变"
    );
    assert_eq!(p2.vars42_45, original.part2.vars42_45, "窗口颜色不应变");
    assert_eq!(p2.vars40_41, original.part2.vars40_41);
    assert_eq!(p2.vars46_48, original.part2.vars46_48);
    assert_eq!(p2.block100, original.part2.block100);
    assert_eq!(p2.bgm, original.part2.bgm);
    assert_eq!(p2.block109, original.part2.block109);
    assert_eq!(p2.var82, original.part2.var82);
    assert_eq!(written.file_version, original.file_version);

    // Drop guard 之外显式恢复并复核（assert 失败时 Drop 仍会兜底）。
    guard.restore();
    guard.assert_untouched("after real save_system_settings");
}

// ---------------------------------------------------------------------------
// 3) apply_settings -> Engine 可读的 BGM / SE 音量（无设备安全降级）
// ---------------------------------------------------------------------------

/// apply_settings 把 Sys100/Sys102 映射为 mixer 增益；用 null 引擎离线渲染读回。
/// null 后端是「无输出设备」时的确定性降级，渲染不依赖声卡。
#[test]
fn apply_settings_moves_engine_bgm_and_se_gain_independently() {
    let Some(mut game) = open_game() else {
        return;
    };
    game.audio = Some(wolf_audio::Engine::null());
    assert!(
        game.audio.as_ref().expect("audio").is_silent(),
        "null 引擎应标记为静默降级后端"
    );

    let tone = wolf_audio::DecodedAudio {
        sample_rate: 48_000,
        channels: 1,
        samples: vec![1.0; 48_000],
        loop_start: None,
        loop_end: None,
    };

    // 只放 BGM：Sys100=80、Sys102=0 -> 0.80。
    game.audio
        .as_mut()
        .expect("audio")
        .play_bgm_audio(tone.clone(), true, 1.0);
    game.vm.vars.set_sys(100, 80);
    game.vm.vars.set_sys(102, 0);
    game.apply_settings();
    let bgm = game.audio.as_ref().expect("audio").render_offline(64);
    assert!(
        (bgm[0] - 0.80).abs() < 1e-4,
        "BGM 80% 应渲染为 0.80，实际 {}",
        bgm[0]
    );

    // 只放 SE：Sys100=0、Sys102=60 -> 0.60，证明 SE 增益独立跟随 Sys102。
    game.audio.as_mut().expect("audio").stop_bgm(0);
    game.audio.as_mut().expect("audio").play_se_audio(tone, 1.0);
    game.vm.vars.set_sys(100, 0);
    game.vm.vars.set_sys(102, 60);
    game.apply_settings();
    let se = game.audio.as_ref().expect("audio").render_offline(64);
    assert!(
        (se[0] - 0.60).abs() < 1e-4,
        "SE 60% 应渲染为 0.60，实际 {}",
        se[0]
    );

    // 静音边界：SE 也关掉后应完全静默。
    game.audio.as_mut().expect("audio").stop_all_se();
    game.vm.vars.set_sys(102, 0);
    game.apply_settings();
    let silent = game.audio.as_ref().expect("audio").render_offline(64);
    assert!(silent[0].abs() < 1e-4, "0% 应完全静音，实际 {}", silent[0]);
    assert_eq!(game.stats.warnings, 0);
}

// ---------------------------------------------------------------------------
// 4) F12 重启（等价性验证）
// ---------------------------------------------------------------------------

/// F12 的按键处理在 wolf-cli 的私有 App::restart（play.rs:202）：Game::new(root) ->
/// apply_settings -> install_font_metrics -> boot -> step 一帧。wolf-game 侧没有
/// 单独暴露 "restart" 公有钩子，因此这里用同一套公有重建原语复现其语义并验证状态确实
/// 回到初始：F12 不做进程级重启，而是新建 Game 再 boot，故一次全新 boot 即重启目标态。
///
/// 缺口记录：F12 键位本身（App::restart / winit 键处理 / 窗口与 atlas 复用）无法从
/// wolf-game 集成测试直接驱动；那部分留在 wolf-cli，未在此覆盖，也不改 src。
#[test]
fn restart_rebuilds_game_fresh_and_resets_vars_clock_and_playtime() {
    let Some(fresh) = open_game() else {
        return;
    };
    // 基线：一次干净 boot（+1 帧，与 App::restart 末尾 self.step() 对齐）。
    let mut fresh = fresh;
    if let Err(err) = fresh.boot() {
        eprintln!("skipping: boot failed ({err})");
        return;
    }
    fresh.frame();
    assert_eq!(fresh.stats.warnings, 0, "全新 boot 不应告警");

    // 记录的初始值样本（正常变量 + 系统变量 + 时钟/日计数）。
    let baseline_normal: Vec<i32> = (0..800).map(|i| fresh.vm.vars.get(i)).collect();
    let baseline_sys: Vec<i32> = (0..300).map(|i| fresh.vm.vars.get_sys(i)).collect();
    let baseline_playtime = fresh.playtime_frames();
    let baseline_clock = [
        fresh.vm.vars.get(4),
        fresh.vm.vars.get(5),
        fresh.vm.vars.get(6),
    ];

    // 制造一个「玩了一阵」的会话：改一堆变量、时钟、日计数、播放时长。
    let Some(mut game) = open_game() else {
        return;
    };
    game.boot().expect("victim boot");
    game.frame();
    for (index, value) in [(4, 21), (5, 45), (6, 3), (7, 54321), (20, 77), (99, 42)] {
        game.vm.vars.set(index, value);
    }
    game.vm.vars.set_sys(100, 33);
    game.set_playtime_frames(baseline_playtime + 12_345);
    assert_ne!(
        game.vm.vars.get(7),
        fresh.vm.vars.get(7),
        "victim 变量应已改动"
    );
    assert_ne!(
        game.playtime_frames(),
        baseline_playtime,
        "victim 播放时长应已改动"
    );

    // F12 等价重建：与 App::restart 一样，新 Game + boot + step 一帧。
    let mut restarted = open_game().expect("rebuild game");
    restarted.boot().expect("restart boot");
    restarted.frame();
    assert_eq!(restarted.stats.warnings, 0, "重启后不应告警");

    let after_normal: Vec<i32> = (0..800).map(|i| restarted.vm.vars.get(i)).collect();
    let after_sys: Vec<i32> = (0..300).map(|i| restarted.vm.vars.get_sys(i)).collect();
    assert_eq!(after_normal, baseline_normal, "重启后普通变量应回到初始值");
    assert_eq!(
        after_sys, baseline_sys,
        "重启后系统变量应回到初始值（含 Sys100 音量）"
    );
    assert_eq!(
        restarted.playtime_frames(),
        baseline_playtime,
        "重启后播放时长（日计数）应归零"
    );
    assert_eq!(
        [
            restarted.vm.vars.get(4),
            restarted.vm.vars.get(5),
            restarted.vm.vars.get(6)
        ],
        baseline_clock,
        "重启后时钟/星期应回到初始"
    );
}
