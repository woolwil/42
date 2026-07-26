#!/usr/bin/env python3

import sys
from typing import IO


def main() -> None:
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return

    filename: str = sys.argv[1]
    file_obj: IO[str] | None = None

    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")

    try:
        file_obj = open(filename, "r")
        content: str = file_obj.read()
        print(f"--{content}", end="")
        if content and not content.endswith("\n"):
            print()
    except OSError as e:
        sys.stderr.write(f"[STDERR] Error opening file '{filename}': {e}\n")
        return
    finally:
        if file_obj is not None:
            file_obj.close()
            print(f"--File '{filename}' closed.")

    print("Transform data:")
    lines: list[str] = content.splitlines()
    new_content: str = (
        "\n".join([line + "#" for line in lines]) + "\n" if lines else ""
    )
    print(f"--{new_content}", end="")
    if new_content and not new_content.endswith("\n"):
        print()

    sys.stdout.write("--Enter new file name (or empty): ")
    sys.stdout.flush()
    new_file: str = sys.stdin.readline().rstrip("\r\n")

    if not new_file.strip():
        print("Not saving data.")
        return

    print(f"Saving data to '{new_file}'")
    out_obj: IO[str] | None = None
    try:
        out_obj = open(new_file, "w")
        out_obj.write(new_content)
        print(f"Data saved in file '{new_file}'.")
    except OSError as e:
        sys.stderr.write(f"[STDERR] Error opening file '{new_file}': {e}\n")
        print("Data not saved.")
    finally:
        if out_obj is not None:
            out_obj.close()


if __name__ == "__main__":
    main()
