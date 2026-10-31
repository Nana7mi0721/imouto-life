//! M3-AL HUD picture-button click routing probe (task-42).

use std::path::PathBuf;

use wolf_game::{savegame, Game};

fn data_root() -> PathBuf {
    let raw = std::env::var("WOLF_DATA_ROOT").unwrap_or_else(|_| "work/Data".to_owned());
    let p = PathBuf::from(raw);
    if p.is_absolute() { return p; }
    let mut base = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    base.pop(); base.pop();
    base.join(p)
}

fn visible(raw: &str) -> String {
    let mut out = String::new();
    let mut it = raw.chars().peekable();
    while let Some(c) = it.next() {
        if (c as u32) != 92 { out.push(c); continue; }
        while let Some(&ch) = it.peek() { if ch.is_ascii_alphabetic() { it.next(); } else { break; } }
        if it.peek() == Some(&'[') { for ch in it.by_ref() { if ch == ']' { break; } } }
    }
    out
}

fn load_bedroom() -> Option<Game> {
    if !data_root().join("Save/SaveData01.sav").is_file() {
        eprintln!("skipping: no SaveData01 under {}", data_root().display());
        return None;
    }
    let mut game = Game::new(data_root()).ok()?;
    game.auto_advance = true;
    game.set_choice_cursor(1); // title menu menu2 = load
    game.auto_choice = true;
    game.auto_choice_delay = 2;
    if game.boot().is_err() { eprintln!("skipping: boot failed"); return None; }
    for _ in 0..1600 { game.frame(); }
    if !game.screen.iter().any(|p| visible(&p.text).contains("行动力")) {
        eprintln!("skipping: bedroom HUD not reached");
        return None;
    }
    Some(game)
}

fn dump_all(game: &Game) {
    eprintln!("screen.len={} messages={} choices={}", game.screen.len(), game.messages.len(), game.choices.is_some());
    for p in game.screen.iter() {
        eprintln!(
            "slot={:>7} kind={:?} file={:?} text={:?} x={} y={} win={:?} op={} scale={} hidden={}",
            p.number, p.kind, p.file, visible(&p.text), p.x, p.y, p.window, p.opacity, p.scale, p.hidden
        );
    }
}

#[test]
fn probe_hud() {
    let Some(game) = load_bedroom() else { return };
    dump_all(&game);
    eprintln!("--- ALL SLOTS ---");
    for p in game.screen.iter() {
        eprintln!("slot={:>7} kind={:?} file={:?} text={:?} x={} y={} win={:?} op={} scale={} hidden={}", p.number, p.kind, p.file, visible(&p.text), p.x, p.y, p.window, p.opacity, p.scale, p.hidden);
    }
    eprintln!("--- runtime slots ({} events, {} active) ---", game.runtime.event_count(), game.runtime.len());
    for slot in game.runtime.slots() {
        let inst = slot.instance().is_some();
        eprintln!("ev={:>4} page={} trig={:?} starts={} running={} name={:?}", slot.event, slot.page, slot.trigger, slot.starts, inst, slot.name);
    }
    eprintln!("--- active pages --- {:?}", game.runtime.active_pages(&game.vm));
    eprintln!("--- vm instances ---");
    for inst in game.vm.instances().iter() {
        eprintln!("vm instance event={}", inst.event);
    }
}
