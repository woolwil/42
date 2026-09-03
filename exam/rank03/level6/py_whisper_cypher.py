def whisper_cipher(text: str, shift: int) -> str:
    result = []
    for char in text:
        if "a" <= char <= "z":
            result.append(chr((ord(char) - ord("a") + shift) % 26 + ord("a")))
        elif "A" <= char <= "Z":
            result.append(chr((ord(char) - ord("A") + shift) % 26 + ord("A")))
        else:
            result.append(char)
    return "".join(result)


def main() -> None:
    print(whisper_cipher("Hello, World!", 3))   # "Khoor, Zruog!"
    print(whisper_cipher("Khoor, Zruog!", -3))  # "Hello, World!"
    print(whisper_cipher("xyz", 1))             # "yza"
    print(whisper_cipher("XYZ", 1))             # "YZA"
    print(whisper_cipher("42 Python!", 13))     # "42 Clguba!"
    print(whisper_cipher("", 5))                # ""


if __name__ == "__main__":
    main()
