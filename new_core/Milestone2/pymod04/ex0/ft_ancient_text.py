#!/usr/bin/env python3

import sys
from typing import IO


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        return

    filename: str = sys.argv[1]
    file_obj: IO[str] | None = None

    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    try:
        file_obj = open(filename, "r")
        content: str = file_obj.read()

        print("---\n")
        print(content)
        print("\n---\n")
    except OSError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")
        return
    finally:
        if file_obj is not None:
            file_obj.close()
            print(f"File '{filename}' closed.")


if __name__ == "__main__":
    main()
