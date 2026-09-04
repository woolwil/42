def hidenp(small: str, big: str) -> bool:
    it = iter(big)
    return all(c in it for c in small)


def main() -> None:
    print(hidenp('abc', 'pojebseabc'))
    print(hidenp('zabijse', 'zabijusezabijmeprosimprosim'))
    print(hidenp('xd', ':d'))
    

if __name__ == "__main__":
    main()
