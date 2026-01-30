#!/usr/bin/env python3
import sys


def main():
    if len(sys.argv) != 2:
        print("usage: ./parameter_matching.py <argument>")
        return
    else:
        param1 = sys.argv[1]
        match = input("What was the paramaeter? ")
        if param1 == match:
            print("Good job!")
        else:
            print("Nope, sorry...")


if __name__ == "__main__":
    main()
