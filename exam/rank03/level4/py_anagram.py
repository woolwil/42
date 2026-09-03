def anagram(s1: str, s2: str) -> bool:
    """
    Checks if two strings are anagrams, ignoring case and spaces.
    """
    clean_s1 = sorted(c.lower() for c in s1 if c != " ")
    clean_s2 = sorted(c.lower() for c in s2 if c != " ")
    return clean_s1 == clean_s2


def main() -> None:
    print(anagram("listen", "silent"))            # True
    print(anagram("Listen", "Silent"))            # True
    print(anagram("rail safety", "fairy tales"))  # True
    print(anagram("hello", "world"))              # False


if __name__ == "__main__":
    main()
