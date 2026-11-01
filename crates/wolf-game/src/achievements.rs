//! M5-C: a lightweight play-statistics and milestone layer.
//!
//! The retail game already has a `プレイ傾向` screen (common event 296) but its
//! text is baked into the event script. This module reads the same authoritative
//! variables and exposes a typed snapshot plus a small, deliberately conservative
//! milestone list. It is presentation-neutral: `play` renders it as an F2 overlay
//! and `wolf-cli` can print the same snapshot in a terminal.
//!
//! Nothing here writes state. Every field is a read of an ordinary variable, so a
//! loaded retail save and a freshly started game both work without translation.

use wolf_vm::Variables;

/// A snapshot of the player-visible progress variables.
///
/// The slot numbers are the ones the shipped scripts use (see
/// docs/HANDOFF_M0.md §3.7 and crates/wolf-game/tests/m3_stats_collection.rs):
/// 99 elapsed days, 20 trust, 21 interest, 22 sensitivity, 23 mood, 154 alert,
/// 187 interaction count, and the completion flags 199/201/202.
#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
pub struct PlayStats {
    pub days: i32,
    pub trust: i32,
    pub interest: i32,
    pub sensitivity: i32,
    pub mood: i32,
    pub alert: i32,
    pub interactions: i32,
    pub cleared: bool,
    pub hundred_days: bool,
    pub pants_complete: bool,
}

impl PlayStats {
    /// Read the snapshot from the live variable bank.
    #[must_use]
    pub fn from_vars(vars: &Variables) -> Self {
        Self {
            days: vars.get(99),
            trust: vars.get(20),
            interest: vars.get(21),
            sensitivity: vars.get(22),
            mood: vars.get(23),
            alert: vars.get(154),
            interactions: vars.get(187),
            // v199 クリア / v201 100日到達 / v202 パンツコンプリート. They are
            // ending/collection flags, not counters, so any non-zero value is true.
            cleared: vars.get(199) != 0,
            hundred_days: vars.get(201) != 0,
            pants_complete: vars.get(202) != 0,
        }
    }
}

/// One local milestone rendered by the statistics overlay.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub struct Milestone {
    pub id: &'static str,
    pub title: &'static str,
    pub detail: &'static str,
    pub unlocked: bool,
}

/// The conservative first-slice milestone list.
///
/// Thresholds mirror the branches CE296 itself uses for trust (100/200/350) and
/// interest (100/200), plus day-count and completion flags. They are presentation
/// milestones, not extra save data: unlocking is recomputed from the same variables
/// on every frame.
#[must_use]
pub fn milestones(stats: &PlayStats) -> Vec<Milestone> {
    vec![
        Milestone {
            id: "days_10",
            title: "十日同行",
            detail: "在一起生活满 10 天",
            unlocked: stats.days >= 10,
        },
        Milestone {
            id: "days_30",
            title: "一月相伴",
            detail: "在一起生活满 30 天",
            unlocked: stats.days >= 30,
        },
        Milestone {
            id: "days_100",
            title: "百日纪念",
            detail: "在一起生活满 100 天",
            unlocked: stats.days >= 100 || stats.hundred_days,
        },
        Milestone {
            id: "trust_100",
            title: "信赖加深",
            detail: "信赖达到 100",
            unlocked: stats.trust >= 100,
        },
        Milestone {
            id: "trust_350",
            title: "深深信赖",
            detail: "信赖达到 350",
            unlocked: stats.trust >= 350,
        },
        Milestone {
            id: "interest_100",
            title: "兴趣萌芽",
            detail: "兴致达到 100",
            unlocked: stats.interest >= 100,
        },
        Milestone {
            id: "interactions_10",
            title: "默契渐生",
            detail: "共同经历达到 10 次",
            unlocked: stats.interactions >= 10,
        },
        Milestone {
            id: "pants_complete",
            title: "衣柜完成",
            detail: "收集全部服饰",
            unlocked: stats.pants_complete,
        },
        Milestone {
            id: "cleared",
            title: "旅途完成",
            detail: "完成一次游戏流程",
            unlocked: stats.cleared,
        },
    ]
}

#[cfg(test)]
mod tests {
    use super::{milestones, PlayStats};
    use wolf_vm::Variables;

    #[test]
    fn play_stats_reads_the_authoritative_slots() {
        let mut vars = Variables::new();
        for (slot, value) in [
            (99usize, 31i32),
            (20, 210),
            (21, 45),
            (22, 3),
            (23, 2),
            (154, 6),
            (187, 12),
        ] {
            vars.set(slot, value);
        }
        vars.set(199, 1);
        vars.set(201, 0);
        vars.set(202, 1);

        let stats = PlayStats::from_vars(&vars);
        assert_eq!(stats.days, 31);
        assert_eq!(stats.trust, 210);
        assert_eq!(stats.interest, 45);
        assert_eq!(stats.sensitivity, 3);
        assert_eq!(stats.mood, 2);
        assert_eq!(stats.alert, 6);
        assert_eq!(stats.interactions, 12);
        assert!(stats.cleared);
        assert!(!stats.hundred_days);
        assert!(stats.pants_complete);
    }

    #[test]
    fn milestones_unlock_from_thresholds_and_flags() {
        let stats = PlayStats {
            days: 30,
            trust: 350,
            interest: 100,
            interactions: 10,
            hundred_days: true,
            pants_complete: true,
            ..PlayStats::default()
        };
        let unlocked: Vec<&str> = milestones(&stats)
            .into_iter()
            .filter(|m| m.unlocked)
            .map(|m| m.id)
            .collect();
        assert_eq!(
            unlocked,
            vec![
                "days_10",
                "days_30",
                "days_100",
                "trust_100",
                "trust_350",
                "interest_100",
                "interactions_10",
                "pants_complete",
            ]
        );
    }

    #[test]
    fn a_fresh_game_has_no_milestones() {
        let stats = PlayStats::from_vars(&Variables::new());
        assert!(milestones(&stats).iter().all(|m| !m.unlocked));
    }
}
