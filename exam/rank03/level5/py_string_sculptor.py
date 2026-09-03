def string_sculptor(text: str) -> str:
    result = []
    to_lower = True

    for char in text:
        if char == " ":
            to_lower = True
            result.append(char)
        elif char.isalpha():
            result.append(char.lower() if to_lower else char.upper())
            to_lower = not to_lower
        else:
            result.append(char)

    return "".join(result)


def main() -> None:
    print(string_sculptor("Hello World"))        # "hElLo wOrLd"
    print(string_sculptor("42 is cool!"))        # "42 iS cOoL!"
    print(string_sculptor("a!b?c d"))            # "a!B?c d"
    print(string_sculptor("HELLO"))              # "hElLo"
    print(string_sculptor("   hello   world   "))# "   hElLo   wOrLd   "
    print(string_sculptor(""))                   # ""


if __name__ == "__main__":
    main()
