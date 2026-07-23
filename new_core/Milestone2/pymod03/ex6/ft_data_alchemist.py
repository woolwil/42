#!/usr/bin/env python3

import random


def main():
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

    score_average = round(sum(score_dict.values()) / len
                          (score_dict.values()), 2)
    print(f"Score average is {score_average}")

    highscores = {
        name: score for name, score in score_dict.items()
        if score > score_average
        }
    print(f"High scores: {highscores}")


if __name__ == "__main__":
    main()
