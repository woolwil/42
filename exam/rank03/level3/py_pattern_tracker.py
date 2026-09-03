def pattern_tracker(text: str) -> int:
    count = 0
    for i in range(len(text) - 1):
        c1, c2 = text[i], text[i + 1]
        if c1.isdigit() and c2.isdigit():
            if int(c2) == int(c1) + 1:
                count += 1
    return count


def main() -> None:
    print(pattern_tracker("123"))        # Expected: 2 ('12', '23')
    print(pattern_tracker("9012"))       # Expected: 2 ('01', '12')
    print(pattern_tracker("a12b34c56"))  # Expected: 3 ('12', '34', '56')
    print(pattern_tracker("890"))        # Expected: 1 ('89')
    print(pattern_tracker(""))           # Expected: 0
    print(pattern_tracker("9"))          # Expected: 0


if __name__ == "__main__":
    main()
