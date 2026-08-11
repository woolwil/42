def hidenp(s1: str, s2: str) -> bool:
    it = iter(s2)
    return all(char in it for char in s1)


def main() -> None:
    print(hidenp('abc', 'pojebseabc'))
    

if __name__ == "__main__":
    main()
