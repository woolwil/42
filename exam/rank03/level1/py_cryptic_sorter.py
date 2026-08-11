def count_vowels(s: str) -> int:
    return sum(1 for char in s.lower() if char in "aeiou")


def cryptic_sorter(strings: list[str]) -> list[str]:
    return sorted(strings, key=lambda s: (len(s), -count_vowels(s), s.lower()))


def main() -> None:
    print(cryptic_sorter(["apple","cat","banana","dog","elephant"]))
    print(cryptic_sorter(["aaa","bbb","AAA","BBB"]))
    print(cryptic_sorter(["hello","world","hi","test"]))
    print(cryptic_sorter([]))
    print(cryptic_sorter(""))
    

if __name__ == "__main__":
    main()
