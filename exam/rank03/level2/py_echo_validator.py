def echo_validator(text: str) -> bool:
    half = len(text) // 2
    first_half = text[:half]
    second_half = text[half:]
    is_double_char = True
    half_split = (text[:half] == text[half:])
    if not text:
        return True
    if len(text) % 2 != 0:
        return False
    for i in range(0, len(text), 2):
        if text[i] != text[i + 1]:
            is_double_char = False
            break
    
    return half_split or is_double_char


def main() -> None:
    print(echo_validator("abcabc"))      # True  (Half-split)
    print(echo_validator("aabbcc"))      # True  (Double-char)
    print(echo_validator("hellohello"))  # True  (Half-split)
    print(echo_validator("abcd"))        # False (Neither)
    print(echo_validator("racecar"))     # False (Odd length)
    print(echo_validator(""))


if __name__ == "__main__":
    main()
