#!/usr/bin/env python3

import sys
from typing import IO


def main() -> None:
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return

    filename: str = sys.argv[1]
    file_obj: IO[str] | None = None

    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    try:
        file_obj = open(filename, "r")
        content: str = file_obj.read()
        print(f"--{content}", end="")
        if content and not content.endswith("\n"):
            print()
    except OSError as e:
        print(f"Error opening file '{filename}': {e}")
        return
    finally:
        if file_obj is not None:
            file_obj.close()
            print(f"--File '{filename}' closed.")


if __name__ == "__main__":
    main()
