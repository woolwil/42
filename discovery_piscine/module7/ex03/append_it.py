#!/usr/bin/env python3
import sys


def error():
    if len(sys.argv) < 2:
        print("none")
        exit()


def main():
    error()
    args = sys.argv[1:]
    for arg in args:
        if arg.find("ism") == len(arg) - 3:
            # print(arg)
            continue
        else:
            print(f"{arg}ism")


if __name__ == "__main__":
    main()
