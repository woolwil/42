def whisper_cipher(text: str, shift: int) -> str:
    res = ""
    for c in text:
        if c.isalpha():
            base = ord('a' if c.islower() else 'A')
            c = chr((ord(c) - base + shift) % 26 + base)
        res += c
    return res


def main() -> None:
    print(whisper_cipher("Hello, World!", 3))   # "Khoor, Zruog!"
    print(whisper_cipher("Khoor, Zruog!", -3))  # "Hello, World!"
    print(whisper_cipher("xyz", 1))             # "yza"
    print(whisper_cipher("XYZ", 1))             # "YZA"
    print(whisper_cipher("42 Python!", 13))     # "42 Clguba!"
    print(whisper_cipher("", 5))                # ""


if __name__ == "__main__":
    main()
