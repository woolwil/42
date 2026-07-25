#!/usr/bin/env python3

import sys
from typing import IO


def print_content(content: str) -> None:
    print("---")
    print(content, end="")
    print("---")


def create_new_file(new_content: str) -> None:
    sys.stdout.write("Enter new file name (or empty): ")
    sys.stdout.flush()
    new_file = sys.stdin.readline().rstrip('\n')
    if not new_file.strip():
        print("Not saving data.")
    else:
        print(f"Saving data to '{new_file}'")
        try:
            new_obj = open(new_file, "w")
            new_obj.write(new_content)
            new_obj.close()
            print(f"Data saved in file '{new_file}'.")
        except OSError as e:
            sys.stderr.write(
                f"[STDERR] Error opening file '{new_file}': {e}\n"
            )
            print("Data not saved.")


def main() -> None:
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
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

        print("Transform data:")
        lines: list[str] = content.splitlines()
        new_content: str = "\n".join([line + "#" for line in lines]) + "\n"
        print_content(new_content)
        create_new_file(new_content)
    except OSError as e:
        print(f"[STDERR] Error opening file '{filename}': "
              f"{e}", file=sys.stderr)
        # sys.stderr.write(f"[STDERR] Error opening file '{filename}': {e}\n")
        return


if __name__ == "__main__":
    main()
