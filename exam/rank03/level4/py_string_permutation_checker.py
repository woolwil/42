def string_permutation_checker(s1: str, s2: str) -> bool:
    if len(s1) != len(s2):
        return False
    return sorted(s1) == sorted(s2)


def main() -> None:
    print(string_permutation_checker("abc", "bca"))       # True
    print(string_permutation_checker("a b!", "!b a"))     # True (whitespace and punctuation count)
    print(string_permutation_checker("", ""))             # True (empty strings)
    print(string_permutation_checker("abc", "Abc"))       # False (case sensitive)
    print(string_permutation_checker("abc", "abcd"))      # False


if __name__ == "__main__":
    main()
