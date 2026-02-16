#!/usr/bin/env python3
import sys


def main():
    lenarg = len(sys.argv)
    if lenarg < 3:
        print("none")
        return
    else:
        print(f"parameters: {lenarg - 1}")
        args = sys.argv[1:]
        for i in args:
            print(f"{i}: {len(i)}")


if __name__ == "__main__":
    main()
