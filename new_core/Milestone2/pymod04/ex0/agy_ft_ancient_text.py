import sys
from typing import IO


def main() -> None:
    """Recover and display digital text fragments from a specified file."""
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        return

    filename: str = sys.argv[1]
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    file_obj: IO[str] | None = None
    try:
        file_obj = open(filename, "r")
        content: str = file_obj.read()
        print("---")
        if content.endswith("\n"):
            print(content, end="")
        else:
            print(content)
        print("---")
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
        return
    finally:
        if file_obj is not None:
            file_obj.close()
            print(f"File '{filename}' closed.")


if __name__ == "__main__":
    main()
