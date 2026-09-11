# def cryptic_sorter(strings: list[str]) -> list[str]:
    # return sorted(strings, key=lambda s: (len(s), -sum(1 for char in s.lower() if char in "aeiou"), s.lower()))

def cryptic_sorter(strings: list[str]) -> list[str]:
    def sort_key(s: str):
        vowels = sum(1 for c in s if c in "aeiouAEIOU")
        return (len(s), s.lower(), vowels)

    res = list(strings)
    length = len(res)
    for i in range(length):
        for j in range(0, length - 1 - i):
            if sort_key(res[j]) > sort_key(res[j + 1]):
                res[j], res[j + 1] = res[j + 1], res[j]

    return res


def main() -> None:
    print(cryptic_sorter(["apple","cat","banana","dog","elephant"]))
    print(cryptic_sorter(["aaa","bbb","AAA","BBB"]))
    print(cryptic_sorter(["hello","world","hi","test"]))
    print(cryptic_sorter([]))
    print(cryptic_sorter(""))
    

if __name__ == "__main__":
    main()
