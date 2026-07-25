#!/usr/bin/env python3

import sys
from typing import IO


def print_content(content) -> None:
    print("---\n")
    print(content, end="")
    print("\n---")


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_stream_management.py <file>")
        return
    try:
        filename: str = sys.argv[1]
        file_obj: IO[str] | None = None

        print("=== Cyber Archives Recovery & Preservation ===")
        print(f"Accessing file '{filename}'")
        file_obj = open(filename, "r")
        content = file_obj.read()
        print_content(content)
        file_obj.close()
        print(f"File '{filename}' closed.\n")

        lines: list[str] = content.splitlines()
        new_content: str = "\n".join([line + "#" for line in lines]) + "\n"
        print("Transform data:")
        print_content(new_content)

        new_file = input("Enter new file name (or empty): ")
        if not new_file.strip():
            print("Not saving data.")
        else:
            print(f"Saving data to '{new_file}'")
            new_obj = open(new_file, "w")
            new_obj.write(new_content)
            new_obj.close()
            print(f"Data saved in file '{new_file}'.")
    except OSError as e:
        print(f"[STDERR] Error opening file '{filename}': "
              f"{e}", file=sys.stderr)
        # sys.stderr.write(f"[STDERR] Error opening file '{filename}': {e}\n")
        return


if __name__ == "__main__":
    main()
