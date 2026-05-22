#!/usr/bin/env python3

import random

ach_pool = [
        "Crafting Genius", "World Savior", "Master Explorer",
        "Collector Supreme", "Untouchable", "Boss Slayer",
        "Strategist", "Unstoppable", "Speed Runner",
        "Survivor", "Treasure Hunter", "First Steps",
        "Sharp Mind", "Hidden Path Finder",
    ]


def gen_player_achievements() -> set[str]:
    count = random.randint(1, len(ach_pool))
    picked = random.sample(ach_pool, count)
    return set(picked)


def main() -> None:
    print("=== Achievement Tracker System ===")
    print()

    players = {  # Key: Value
        "Alice": gen_player_achievements(),
        "Bob": gen_player_achievements(),
        "Charlie": gen_player_achievements(),
        "Dylan": gen_player_achievements()
    }

    for name, ach_set in players.items():
        print(f"Player: {name}: {ach_set}")
        print()

    common_ach = set.intersection(*players.values())
    distinct_ach = set.union(*players.values())
    # diff_ach = set.difference(*players.values())

    print(f"All distinct achievements: {distinct_ach}")
    print()
    print(f"Common achievements: {common_ach}")
    print()
    for player, ach_set in players.items():
        others = set.union(*(val for key, val in players.items()
                             if key != player))
        only_player = ach_set.difference(others)
        # only_player = ach_set - others
        print(f"Only {player} has: {only_player}")
        print()

    pool_set = set(ach_pool)
    for player, ach_set in players.items():
        missing = pool_set.difference(ach_set)
        # missing = pool_set - ach_set
        print(f"{player} is missing: {missing}")
        print()

if __name__ == "__main__":
    main()
