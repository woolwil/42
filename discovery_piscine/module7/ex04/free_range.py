#!/usr/bin/env python3
import sys


def noparams():
    if len(sys.argv) != 3:
        print("none")
        exit()


def main():
    noparams()
    args = (sys.argv[1:])
    if int(args[0]) >= int(args[1]):
        print("param1 must be less than param2")
        exit()
    else:
        args = range(int(args[0]), int(args[1]) + 1)
        print(list(args))


if __name__ == "__main__":
    main()
