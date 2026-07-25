#!/usr/bin/env python3

import random


def main() -> None:
    print("=== Game Data Alchemist ===")

    players = [
        "Alice",
        "bob",
        "Charlie",
        "dylan",
        "Emma",
        "Gregory",
        "john",
        "kevin",
        "Liam",
        ]

    print(f"Initial list of players: {players}")

    players_capitalized = [name.capitalize() for name in players]
    print(f"New list with all names capitalized: {players_capitalized}")

    only_capitalized = [name for name in players if name == name.capitalize()]
    print(f"New list of capitalized names only: {only_capitalized}")

    score_dict = {name: random.randrange(1000) for name in players_capitalized}
    print(f"Score dict: {score_dict}")

    score_av = round(sum(score_dict.values()) / len(score_dict), 2)
    print(f"Score average is {score_av}")

    hs = {n: sc for n, sc in score_dict.items() if sc > score_av}
    print(f"High scores: {hs}")


if __name__ == "__main__":
    main()
