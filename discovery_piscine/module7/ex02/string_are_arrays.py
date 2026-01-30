#!/usr/bin/env python3
import sys


def error():
    if len(sys.argv) < 2:
        print("none")
        exit()


def main():
    error()
    for _ in range(sys.argv[1].count('z')):
        print('z', end='')
        print()
    if sys.argv[1].count('z') == 0:
        print("none")


if __name__ == "__main__":
    main()
