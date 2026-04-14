#!/usr/bin/env python3

import sys


def main() -> None:
    print("=== Player Score Analytics ===")

    args = sys.argv[1:]
    if not args:
        print("No scores provided. Usage: python3 ", end="")
        print("ft_score_analytics.py<score1> <score2> ...")
        return

    scores = []
    for arg in args:
        try:
            scores.append(int(arg))
        except ValueError:
            print(f"Invalid parameter; '{arg}'")

    if not scores:
        print("No scores provided. Usage: python3 ", end="")
        print("ft_score_analytics.py<score1> <score2> ...")
        return

    total_players = len(sys.argv) - 1
    total_score = sum(scores)
    average_score = sum(scores) / len(scores)
    score_range = max(scores) - min(scores)

    print("Scores processed:", scores)
    print("Total players:", total_players)
    print("Total score:", total_score)
    print("Average score:", average_score)
    print("High score:", max(scores))
    print("Low score:", min(scores))
    print("Score range:", score_range)


if __name__ == "__main__":
    main()
