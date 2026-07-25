#!/usr/bin/env python3

import sys
from typing import IO


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_archive_creation.py <file>")
        return

    filename: str = sys.argv[1]
    file_obj: IO[str] | None = None

    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")

    try:
        file_obj = open(filename, 'r')
        content: str = file_obj.read()
        file_obj.close()

        print("---\n")
        print(content, end="")
        print("\n---")
        print(f"File '{filename}' closed.\n")

        lines: list[str] = content.splitlines()
        new_content: str = "\n".join([line + '#' for line in lines]) + "\n"

        print("Transform data:")
        print("---\n")
        print(new_content, end="")
        print("\n---")

        new_file: str = input("Enter new file name (or empty): ")
        if not new_file.strip():
            print("Not saving data.")
        else:
            print(f"Saving data to '{new_file}'")
            out_obj = open(new_file, 'w')
            out_obj.write(new_content)
            out_obj.close()
            print(f"Data saved in file '{new_file}'.")
    except OSError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")
        return


if __name__ == "__main__":
    main()
