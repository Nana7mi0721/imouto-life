//! Simulator function-hotkey configuration (`play --hotkeys <FILE>`).
//!
//! The port reserves a handful of function keys for things the retail engine does
//! not ship as in-game bindings: pausing to inspect statistics, toggling a debug
//! overlay, opening the message transcript, cycling the presentation scale,
//! toggling fullscreen, quitting the window and restarting the session. In the
//! original these were read straight from the keyboard on every event; here they
//! are pulled into a single [`HotkeyConfig`] so a user can rebind them without a
//! rebuild.
//!
//! Only the *simulator* keys live here. The in-game gamepad/keyboard bits the
//! script itself polls (WASD, the arrow keys, Enter/Backspace, and the configurable
//! Z/X/C codes) are data-driven and must stay put, so they are deliberately not
//! part of this table.
//!
//! ## File format
//!
//! A plain UTF-8 text file of `action = key` lines. Blank lines and lines that
//! begin with `#` or `;` are ignored; action names and key names are matched
//! case-insensitively. A file may set any subset of the actions; anything it
//! omits keeps its default binding. See `docs/M7_HOTKEYS.md` for a full example.
//!
//! If a line names an unknown action or an unknown key, the parser records a
//! clear error and *leaves that action's default in place* rather than dropping
//! the whole file, so one typo cannot silently disable the other rebinds.

use std::path::Path;

use winit::keyboard::{Key, NamedKey};

/// The simulator's rebindable function keys.
///
/// The [`Default`] implementation reproduces the historical hard-coded mapping
/// exactly, so a build with no `--hotkeys` file behaves as before.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct HotkeyConfig {
    /// Toggle the play-statistics / milestone overlay.
    pub stats: NamedKey,
    /// Toggle the runtime debug overlay.
    pub debug: NamedKey,
    /// Toggle the message-transcript overlay.
    pub backlog: NamedKey,
    /// Cycle the presentation scale mode.
    pub scale: NamedKey,
    /// Toggle borderless fullscreen.
    pub fullscreen: NamedKey,
    /// Close the window.
    pub quit: NamedKey,
    /// Rebuild and reboot the session in place.
    pub restart: NamedKey,
}

impl Default for HotkeyConfig {
    fn default() -> Self {
        Self {
            stats: NamedKey::F2,
            debug: NamedKey::F3,
            backlog: NamedKey::F4,
            scale: NamedKey::F9,
            fullscreen: NamedKey::F11,
            quit: NamedKey::F10,
            restart: NamedKey::F12,
        }
    }
}

/// One rebindable action, used to dispatch a parsed `action = key` line.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum Action {
    Stats,
    Debug,
    Backlog,
    Scale,
    Fullscreen,
    Quit,
    Restart,
}

impl Action {
    /// Resolve the request side of a line. Accepts a few common synonyms.
    fn from_name(name: &str) -> Option<Self> {
        match name.trim().to_ascii_lowercase().as_str() {
            "stats" | "statistics" => Some(Action::Stats),
            "debug" => Some(Action::Debug),
            "backlog" | "transcript" | "log" => Some(Action::Backlog),
            "scale" | "zoom" => Some(Action::Scale),
            "fullscreen" | "full-screen" | "full_screen" => Some(Action::Fullscreen),
            "quit" | "exit" | "close" => Some(Action::Quit),
            "restart" | "reset" => Some(Action::Restart),
            _ => None,
        }
    }

    /// Store `key` into the matching field of `config`.
    fn apply(self, config: &mut HotkeyConfig, key: NamedKey) {
        match self {
            Action::Stats => config.stats = key,
            Action::Debug => config.debug = key,
            Action::Backlog => config.backlog = key,
            Action::Scale => config.scale = key,
            Action::Fullscreen => config.fullscreen = key,
            Action::Quit => config.quit = key,
            Action::Restart => config.restart = key,
        }
    }
}

impl HotkeyConfig {
    /// The built-in mapping, identical to the pre-configuration behaviour.
    pub fn builtin() -> Self {
        Self::default()
    }

    /// Parse a configuration document.
    ///
    /// Returns the resolved configuration together with one human-readable message
    /// per rejected line. Rejected lines do not clear their action: it keeps the
    /// default (or an earlier valid assignment), which is the "fall back to the
    /// default table" contract.
    pub fn parse(text: &str) -> (Self, Vec<String>) {
        let mut config = Self::default();
        let mut errors = Vec::new();
        for (index, raw) in text.lines().enumerate() {
            let number = index + 1;
            let line = raw.trim();
            if line.is_empty() || line.starts_with('#') || line.starts_with(';') {
                continue;
            }
            let Some((name, value)) = split_assignment(line) else {
                errors.push(format!(
                    "line {number}: expected `action = key`, found `{line}`"
                ));
                continue;
            };
            let Some(action) = Action::from_name(&name) else {
                errors.push(format!(
                    "line {number}: unknown hotkey action `{name}` (known: stats, debug, backlog, scale, fullscreen, quit, restart)"
                ));
                continue;
            };
            let Some(key) = parse_named_key(&value) else {
                errors.push(format!(
                    "line {number}: unknown key name `{value}` for action `{name}`"
                ));
                continue;
            };
            action.apply(&mut config, key);
        }
        (config, errors)
    }

    /// Read and parse a configuration file.
    ///
    /// A missing or unreadable file is an [`std::io::Error`]; malformed lines are
    /// returned in the second tuple element so the caller can warn and carry on
    /// with the defaults.
    pub fn load(path: &Path) -> std::io::Result<(Self, Vec<String>)> {
        let text = std::fs::read_to_string(path)?;
        Ok(Self::parse(&text))
    }

    fn matches(key: &Key, target: NamedKey) -> bool {
        matches!(key, Key::Named(found) if *found == target)
    }

    /// True when `key` is the statistics-overlay toggle.
    pub fn is_stats(&self, key: &Key) -> bool {
        Self::matches(key, self.stats)
    }

    /// True when `key` is the debug-overlay toggle.
    pub fn is_debug(&self, key: &Key) -> bool {
        Self::matches(key, self.debug)
    }

    /// True when `key` opens/closes the message transcript.
    pub fn is_backlog(&self, key: &Key) -> bool {
        Self::matches(key, self.backlog)
    }

    /// True when `key` cycles the scale mode.
    pub fn is_scale(&self, key: &Key) -> bool {
        Self::matches(key, self.scale)
    }

    /// True when `key` toggles fullscreen.
    pub fn is_fullscreen(&self, key: &Key) -> bool {
        Self::matches(key, self.fullscreen)
    }

    /// True when `key` closes the window.
    pub fn is_quit(&self, key: &Key) -> bool {
        Self::matches(key, self.quit)
    }

    /// True when `key` restarts the session.
    pub fn is_restart(&self, key: &Key) -> bool {
        Self::matches(key, self.restart)
    }
}

/// Split `action = key` (or `action: key`) on the first assignment separator.
fn split_assignment(line: &str) -> Option<(String, String)> {
    // Both separators are accepted; whichever appears first wins so a stray
    // colon in a comment is not mistaken for the assignment.
    let eq = line.find('=');
    let colon = line.find(':');
    let index = match (eq, colon) {
        (Some(a), Some(b)) => a.min(b),
        (Some(a), None) => a,
        (None, Some(b)) => b,
        (None, None) => return None,
    };
    let name = line[..index].trim();
    let value = line[index + 1..].trim();
    if name.is_empty() || value.is_empty() {
        return None;
    }
    Some((name.to_owned(), value.to_owned()))
}

/// Resolve a key name (case-insensitive) to a [`NamedKey`].
///
/// Supports the function keys F1..F12 plus the common non-character keys a user
/// might reasonably bind (Enter, Escape, arrows, navigation). Character keys
/// (letters and digits) are not supported because winit reports them as
/// `Key::Character`, not `NamedKey`, and they belong to the game's own input
/// bindings rather than the simulator controls.
pub fn parse_named_key(name: &str) -> Option<NamedKey> {
    let name = name.trim().to_ascii_uppercase();
    match name.as_str() {
        "F1" => Some(NamedKey::F1),
        "F2" => Some(NamedKey::F2),
        "F3" => Some(NamedKey::F3),
        "F4" => Some(NamedKey::F4),
        "F5" => Some(NamedKey::F5),
        "F6" => Some(NamedKey::F6),
        "F7" => Some(NamedKey::F7),
        "F8" => Some(NamedKey::F8),
        "F9" => Some(NamedKey::F9),
        "F10" => Some(NamedKey::F10),
        "F11" => Some(NamedKey::F11),
        "F12" => Some(NamedKey::F12),
        "ENTER" | "RETURN" => Some(NamedKey::Enter),
        "TAB" => Some(NamedKey::Tab),
        "SPACE" | "SPACEBAR" => Some(NamedKey::Space),
        "BACKSPACE" => Some(NamedKey::Backspace),
        "ESC" | "ESCAPE" => Some(NamedKey::Escape),
        "DELETE" | "DEL" => Some(NamedKey::Delete),
        "INSERT" | "INS" => Some(NamedKey::Insert),
        "HOME" => Some(NamedKey::Home),
        "END" => Some(NamedKey::End),
        "PAGEUP" | "PGUP" => Some(NamedKey::PageUp),
        "PAGEDOWN" | "PGDN" => Some(NamedKey::PageDown),
        "UP" | "ARROWUP" => Some(NamedKey::ArrowUp),
        "DOWN" | "ARROWDOWN" => Some(NamedKey::ArrowDown),
        "LEFT" | "ARROWLEFT" => Some(NamedKey::ArrowLeft),
        "RIGHT" | "ARROWRIGHT" => Some(NamedKey::ArrowRight),
        _ => None,
    }
}

#[cfg(test)]
mod tests {
    use super::{parse_named_key, HotkeyConfig};
    use winit::keyboard::{Key, NamedKey};

    #[test]
    fn defaults_match_the_historical_mapping() {
        let config = HotkeyConfig::default();
        assert_eq!(config.stats, NamedKey::F2);
        assert_eq!(config.debug, NamedKey::F3);
        assert_eq!(config.backlog, NamedKey::F4);
        assert_eq!(config.scale, NamedKey::F9);
        assert_eq!(config.fullscreen, NamedKey::F11);
        assert_eq!(config.quit, NamedKey::F10);
        assert_eq!(config.restart, NamedKey::F12);
    }

    #[test]
    fn a_full_overrides_file_is_applied() {
        let text = "\
# simulator controls
stats = F5
debug = F6
backlog = F7
scale = F8
fullscreen = F1
quit = Escape
restart = F12
";
        let (config, errors) = HotkeyConfig::parse(text);
        assert!(errors.is_empty(), "unexpected errors: {errors:?}");
        assert_eq!(config.stats, NamedKey::F5);
        assert_eq!(config.debug, NamedKey::F6);
        assert_eq!(config.backlog, NamedKey::F7);
        assert_eq!(config.scale, NamedKey::F8);
        assert_eq!(config.fullscreen, NamedKey::F1);
        assert_eq!(config.quit, NamedKey::Escape);
        assert_eq!(config.restart, NamedKey::F12);
    }

    #[test]
    fn a_partial_file_keeps_the_untouched_defaults() {
        let (config, errors) = HotkeyConfig::parse("restart = F5\n");
        assert!(errors.is_empty(), "unexpected errors: {errors:?}");
        assert_eq!(config.restart, NamedKey::F5);
        // Everything the file did not mention stays at its built-in value.
        assert_eq!(
            config,
            HotkeyConfig {
                restart: NamedKey::F5,
                ..HotkeyConfig::default()
            }
        );
    }

    #[test]
    fn an_invalid_key_name_is_reported_and_falls_back_to_default() {
        let (config, errors) = HotkeyConfig::parse("restart = F99\nstats = F7\n");
        assert_eq!(
            errors.len(),
            1,
            "one bad key should be reported: {errors:?}"
        );
        assert!(
            errors[0].contains("F99"),
            "error names the bad key: {errors:?}"
        );
        // The bad line keeps the default; the valid one is still applied.
        assert_eq!(config.restart, NamedKey::F12);
        assert_eq!(config.stats, NamedKey::F7);
    }

    #[test]
    fn an_unknown_action_is_reported() {
        let (config, errors) = HotkeyConfig::parse("volume = F5\n");
        assert_eq!(errors.len(), 1);
        assert!(errors[0].contains("volume"));
        assert_eq!(config, HotkeyConfig::default());
    }

    #[test]
    fn a_blank_or_malformed_line_is_handled() {
        let (config, errors) =
            HotkeyConfig::parse("\n   \n# comment\n; also a comment\nnonsense-line\n");
        assert_eq!(errors.len(), 1, "only the malformed line is an error");
        assert_eq!(config, HotkeyConfig::default());
    }

    #[test]
    fn assignment_accepts_equals_or_colon_and_ignores_case() {
        let (config, errors) = HotkeyConfig::parse("  STATS:  f5  \n");
        assert!(errors.is_empty(), "{errors:?}");
        assert_eq!(config.stats, NamedKey::F5);
    }

    #[test]
    fn default_config_recognises_the_default_keys() {
        let config = HotkeyConfig::default();
        assert!(config.is_quit(&Key::Named(NamedKey::F10)));
        assert!(config.is_stats(&Key::Named(NamedKey::F2)));
        assert!(config.is_restart(&Key::Named(NamedKey::F12)));
        assert!(!config.is_restart(&Key::Named(NamedKey::F5)));
    }

    #[test]
    fn the_restart_key_tracks_the_configuration() {
        let (config, errors) = HotkeyConfig::parse("restart = F5\n");
        assert!(errors.is_empty(), "{errors:?}");
        assert!(config.is_restart(&Key::Named(NamedKey::F5)));
        assert!(!config.is_restart(&Key::Named(NamedKey::F12)));
        // A non-named key never matches.
        assert!(!config.is_restart(&Key::Character("z".into())));
    }

    #[test]
    fn parse_named_key_covers_function_and_navigation_keys() {
        assert_eq!(parse_named_key("f2"), Some(NamedKey::F2));
        assert_eq!(parse_named_key("F12"), Some(NamedKey::F12));
        assert_eq!(parse_named_key("esc"), Some(NamedKey::Escape));
        assert_eq!(parse_named_key("PgDn"), Some(NamedKey::PageDown));
        assert_eq!(parse_named_key("return"), Some(NamedKey::Enter));
        assert_eq!(parse_named_key("f13"), None);
        assert_eq!(parse_named_key("q"), None);
    }
}
