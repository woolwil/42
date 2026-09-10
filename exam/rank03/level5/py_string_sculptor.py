def string_sculptor(text: str) -> str:
    res = ""
    lower = True

    for c in text:
        if c == " ":
            lower = True
        elif c.isalpha():
            c = c.lower() if lower else c.upper()
            lower = not lower
        res += c

    return res


def main() -> None:
    print(string_sculptor("Hello World"))        # "hElLo wOrLd"
    print(string_sculptor("42 is cool!"))        # "42 iS cOoL!"
    print(string_sculptor("a!b?c d"))            # "a!B?c d"
    print(string_sculptor("HELLO"))              # "hElLo"
    print(string_sculptor("   hello   world   "))# "   hElLo   wOrLd   "
    print(string_sculptor(""))                   # ""


if __name__ == "__main__":
    main()
