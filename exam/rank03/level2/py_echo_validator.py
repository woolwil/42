def echo_validator(text: str) -> bool:
    s = [c.lower() for c in text if c.isalpha()]
    return s == s[::-1]


def main() -> None:
    print(echo_validator("racecar"))                            # True
    print(echo_validator("Madam, I'm Adam"))                    # True
    print(echo_validator("A man, a plan, a canal: Panama!"))    # True
    print(echo_validator("Never odd or even"))                  # True
    print(echo_validator("hello"))                              # False
    print(echo_validator("abcde"))                              # False


if __name__ == "__main__":
    main()
