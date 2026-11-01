//! Mod manifests and dependency checks (M5-E second slice).
//!
//! An overlay directory itself already defines load order (`--mod` order, later wins)
//! and per-file fallback. This module adds an optional `mod.ini` so a mod can declare
//! its identity and the other mods it expects:
//!
//! ```text
//! # mods/example/mod.ini
//! name=Example Mod
//! version=1.0
//! requires=base-ui, extra-maps
//! ```
//!
//! The file is deliberately a tiny `key=value` format instead of JSON: the project has
//! no serialization dependency, the parser is a dozen lines, and a broken line can be
//! reported with its physical number. Missing manifests are fine: the directory name
//! becomes the mod name, and version/requires stay empty.
//!
//! `requires` entries must name a mod loaded in the same `--mod` set; the reserved
//! name `base` means the unmodified game data and is always satisfied. Dependencies are
//! checked, not used to reorder: the command line order remains the layering order, so
//! a user can always see and change precedence. A mod cannot require itself, two mods
//! cannot share a name, and `base` cannot be used as a mod name.

use std::collections::HashMap;
use std::fmt;
use std::fs;
use std::io;
use std::path::{Path, PathBuf};

/// The manifest file a mod directory may contain.
pub const MANIFEST_FILE: &str = "mod.ini";

/// Reserved dependency name for the unmodified game data.
pub const BASE_NAME: &str = "base";

/// A failed manifest read, parse, or dependency check.
#[derive(Debug)]
pub enum ModError {
    /// The manifest file could not be read.
    Io {
        /// Path that failed.
        path: PathBuf,
        /// Underlying error.
        source: io::Error,
    },
    /// A non-comment line was not `key=value`, had an unknown key, or an invalid value.
    Syntax {
        /// Manifest path.
        path: PathBuf,
        /// 1-based physical line number.
        line: usize,
        /// Why the line was rejected.
        reason: String,
    },
    /// Two overlay directories declare the same mod name.
    DuplicateName {
        /// The shared name.
        name: String,
        /// First directory that used it.
        first: PathBuf,
        /// Second directory that used it.
        second: PathBuf,
    },
    /// A mod requires a name that is not loaded.
    MissingRequirement {
        /// The requiring mod.
        name: String,
        /// The unresolved requirement.
        requires: String,
    },
    /// A mod lists itself in `requires`.
    SelfRequirement {
        /// The mod that requires itself.
        name: String,
    },
    /// A directory tries to use the reserved base name.
    ReservedName {
        /// Directory that used it.
        dir: PathBuf,
    },
}

impl fmt::Display for ModError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            Self::Io { path, source } => write!(f, "cannot read {}: {source}", path.display()),
            Self::Syntax { path, line, reason } => {
                write!(f, "{} line {line}: {reason}", path.display())
            }
            Self::DuplicateName {
                name,
                first,
                second,
            } => write!(
                f,
                "mod name '{name}' is declared by both {} and {}",
                first.display(),
                second.display()
            ),
            Self::MissingRequirement { name, requires } => write!(
                f,
                "mod '{name}' requires '{requires}', which is not in the --mod list"
            ),
            Self::SelfRequirement { name } => {
                write!(f, "mod '{name}' requires itself")
            }
            Self::ReservedName { dir } => write!(
                f,
                "{} uses the reserved mod name '{BASE_NAME}'",
                dir.display()
            ),
        }
    }
}

impl std::error::Error for ModError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self {
            Self::Io { source, .. } => Some(source),
            _ => None,
        }
    }
}

/// The declared identity of one overlay directory.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct ModManifest {
    /// Unique name, also usable in another mod's `requires`.
    pub name: String,
    /// Free-form version string; empty when not declared.
    pub version: String,
    /// Names this mod expects to be loaded alongside it.
    pub requires: Vec<String>,
}

impl ModManifest {
    /// Parses manifest text for a directory, filling the name from the directory when
    /// the file does not declare one.
    ///
    /// # Errors
    ///
    /// Returns ModError::Syntax for a malformed or unknown line.
    pub fn parse(dir: &Path, text: &str) -> Result<Self, ModError> {
        let mut manifest = Self {
            name: default_name(dir),
            version: String::new(),
            requires: Vec::new(),
        };
        for (index, raw) in text.lines().enumerate() {
            let line = raw.strip_suffix('\r').unwrap_or(raw);
            let trimmed = line.trim();
            if trimmed.is_empty() || trimmed.starts_with('#') || trimmed.starts_with(';') {
                continue;
            }
            let Some((key, value)) = trimmed.split_once('=') else {
                return Err(ModError::Syntax {
                    path: dir.join(MANIFEST_FILE),
                    line: index + 1,
                    reason: "expected key=value".to_owned(),
                });
            };
            let key = key.trim().to_ascii_lowercase();
            let value = value.trim();
            match key.as_str() {
                "name" => {
                    if !value.is_empty() {
                        manifest.name = value.to_owned();
                    }
                }
                "version" => manifest.version = value.to_owned(),
                "requires" => {
                    manifest.requires = value
                        .split(|ch: char| ch == ',' || ch.is_whitespace())
                        .filter(|entry| !entry.is_empty())
                        .map(str::to_owned)
                        .collect();
                }
                _ => {
                    return Err(ModError::Syntax {
                        path: dir.join(MANIFEST_FILE),
                        line: index + 1,
                        reason: format!("unknown key '{key}' (expected name, version, requires)"),
                    });
                }
            }
        }
        Ok(manifest)
    }

    /// Reads `mod.ini` from a directory.
    ///
    /// Returns None when the directory has no manifest; that is not an error.
    ///
    /// # Errors
    ///
    /// Returns ModError::Io when the file exists but cannot be read, and
    /// ModError::Syntax for malformed lines.
    pub fn read(dir: &Path) -> Result<Option<Self>, ModError> {
        let path = dir.join(MANIFEST_FILE);
        if !path.is_file() {
            return Ok(None);
        }
        let text = fs::read_to_string(&path).map_err(|source| ModError::Io {
            path: path.clone(),
            source,
        })?;
        Self::parse(dir, &text).map(Some)
    }
}

/// One validated overlay directory.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct ModInfo {
    /// The directory passed to `--mod`.
    pub dir: PathBuf,
    /// Its manifest, with defaults filled in.
    pub manifest: ModManifest,
}

impl ModInfo {
    /// A one-line description for startup output.
    #[must_use]
    pub fn label(&self) -> String {
        if self.manifest.version.is_empty() {
            self.manifest.name.clone()
        } else {
            format!("{} {}", self.manifest.name, self.manifest.version)
        }
    }
}

/// Reads every overlay's manifest and checks name uniqueness and dependencies.
///
/// Order is preserved: it is the layering order, later mods winning. See the module
/// docs for the exact contract.
///
/// # Errors
///
/// Returns the first manifest read/parse error, duplicate name, reserved name,
/// self-requirement, or missing requirement.
pub fn validate(overlays: &[PathBuf]) -> Result<Vec<ModInfo>, ModError> {
    let mut infos = Vec::with_capacity(overlays.len());
    let mut seen: HashMap<String, PathBuf> = HashMap::new();
    for dir in overlays {
        let manifest = ModManifest::read(dir)?.unwrap_or_else(|| ModManifest {
            name: default_name(dir),
            version: String::new(),
            requires: Vec::new(),
        });
        if manifest.name == BASE_NAME {
            return Err(ModError::ReservedName { dir: dir.clone() });
        }
        if let Some(first) = seen.get(&manifest.name) {
            return Err(ModError::DuplicateName {
                name: manifest.name,
                first: first.clone(),
                second: dir.clone(),
            });
        }
        seen.insert(manifest.name.clone(), dir.clone());
        infos.push(ModInfo {
            dir: dir.clone(),
            manifest,
        });
    }
    for info in &infos {
        for requires in &info.manifest.requires {
            if requires == &info.manifest.name {
                return Err(ModError::SelfRequirement {
                    name: info.manifest.name.clone(),
                });
            }
            if requires != BASE_NAME && !seen.contains_key(requires) {
                return Err(ModError::MissingRequirement {
                    name: info.manifest.name.clone(),
                    requires: requires.clone(),
                });
            }
        }
    }
    Ok(infos)
}

/// The directory name as the fallback mod name.
fn default_name(dir: &Path) -> String {
    dir.file_name().map_or_else(
        || dir.display().to_string(),
        |name| name.to_string_lossy().into_owned(),
    )
}

#[cfg(test)]
mod tests {
    use super::{validate, ModError, ModManifest};
    use std::path::{Path, PathBuf};
    use std::sync::atomic::{AtomicUsize, Ordering};

    fn scratch_dir(tag: &str) -> PathBuf {
        static SEQ: AtomicUsize = AtomicUsize::new(0);
        let mut path = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        path.pop(); // crates/
        path.pop(); // workspace root
        path.push("target");
        path.push("test-scratch");
        path.push(format!(
            "mods-{tag}-{}-{}",
            std::process::id(),
            SEQ.fetch_add(1, Ordering::Relaxed)
        ));
        let _ = std::fs::remove_dir_all(&path);
        std::fs::create_dir_all(&path).expect("scratch dir");
        path
    }

    fn mod_dir(root: &Path, name: &str, manifest: &str) -> PathBuf {
        let dir = root.join(name);
        std::fs::create_dir_all(&dir).expect("mod dir");
        std::fs::write(dir.join("mod.ini"), manifest).expect("manifest");
        dir
    }

    #[test]
    fn a_manifest_parses_its_three_keys_and_ignores_comments() {
        let manifest = ModManifest::parse(
            Path::new("mods/example"),
            "# comment\n; also a comment\nname=Example Mod\nversion=1.2\nrequires=base-ui, extra-maps\n",
        )
        .expect("manifest");
        assert_eq!(manifest.name, "Example Mod");
        assert_eq!(manifest.version, "1.2");
        assert_eq!(manifest.requires, ["base-ui", "extra-maps"]);
    }

    #[test]
    fn a_missing_name_falls_back_to_the_directory_and_an_unknown_key_is_reported() {
        let manifest = ModManifest::parse(Path::new("mods/example"), "version=1\n").expect("ok");
        assert_eq!(manifest.name, "example");
        assert!(manifest.requires.is_empty());

        let error = ModManifest::parse(Path::new("mods/example"), "name=x\ncolour=blue\n")
            .expect_err("unknown key");
        let text = error.to_string();
        assert!(text.contains("mod.ini line 2: unknown key 'colour'"), "{text}");
    }

    #[test]
    fn validate_fills_defaults_for_manifestless_directories() {
        let root = scratch_dir("defaults");
        let infos = validate(&[root.join("a"), root.join("b")]).expect("valid");
        assert_eq!(infos[0].manifest.name, "a");
        assert_eq!(infos[1].manifest.name, "b");
        assert_eq!(infos[0].label(), "a");
    }

    #[test]
    fn validate_rejects_duplicate_names() {
        let root = scratch_dir("duplicate");
        let first = mod_dir(&root, "one", "name=same\n");
        let second = mod_dir(&root, "two", "name=same\nversion=2\n");
        let error = validate(&[first, second]).expect_err("duplicate");
        assert!(matches!(error, ModError::DuplicateName { .. }));
        assert!(error.to_string().contains("'same'"));
    }

    #[test]
    fn validate_rejects_a_self_requirement() {
        let root = scratch_dir("self");
        let dir = mod_dir(&root, "one", "name=one\nrequires=one\n");
        let error = validate(&[dir]).expect_err("self requirement");
        assert_eq!(error.to_string(), "mod 'one' requires itself");
    }

    #[test]
    fn validate_accepts_base_and_reports_missing_requirements() {
        let root = scratch_dir("requires");
        let base_ok = mod_dir(&root, "a", "name=a\nrequires=base\n");
        assert!(validate(&[base_ok]).is_ok());

        let missing = mod_dir(&root, "b", "name=b\nrequires=absent\n");
        let error = validate(&[missing]).expect_err("missing requirement");
        assert_eq!(
            error.to_string(),
            "mod 'b' requires 'absent', which is not in the --mod list"
        );
    }

    #[test]
    fn validate_respects_a_dependency_that_is_present() {
        let root = scratch_dir("present");
        let a = mod_dir(&root, "a", "name=a\nrequires=b\n");
        let b = mod_dir(&root, "b", "name=b\n");
        let infos = validate(&[a, b]).expect("dependency present");
        assert_eq!(infos.len(), 2);
    }

    #[test]
    fn the_reserved_base_name_is_rejected() {
        let root = scratch_dir("reserved");
        let dir = mod_dir(&root, "x", "name=base\n");
        let error = validate(&[dir]).expect_err("reserved");
        assert!(error.to_string().contains("reserved mod name 'base'"));
    }
}