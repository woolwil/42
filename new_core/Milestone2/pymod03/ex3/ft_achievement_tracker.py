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
    players = {
        "Alice": gen_player_achievements(),
        "Bob": gen_player_achievements(),
        "Charlie": gen_player_achievements(),
        "Dylan": gen_player_achievements()
    }
    distinct_achievements = set.union(*players.values())
    common_achievements = set.intersection(*players.values())

    for key, value in players.items():
        print(f"Player {key}: {value}")

    print()
    print(f"All distinct achievements: {distinct_achievements}")
    print()
    print(f"Common achievements: {common_achievements}")
    print()
    for current_player, current_achievements in players.items():
        # others_achievements: set[str] = set()
        # for compared_player, compared_achievements in players.items():
        #     if compared_player != current_player:
        #         others_achievements = set.union(others_achievements,
        #                                         compared_achievements)
        others_achievements = set.union(*(value for key, value in
                                        players.items()
                                        if key != current_player))

        only_this_player = set.difference(current_achievements,
                                          others_achievements)
        print(f"Only {current_player} has: {only_this_player}")
    print()
    for key, value in players.items():
        print(f"{key} is missing: {set.difference(set(ach_pool), value)}")


if __name__ == "__main__":
    main()
