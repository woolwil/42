#!/usr/bin/env python3
import sys

if len(sys.argv) != 3:
	print("none")
	exit()
search = sys.argv[1]
string = sys.argv[2]
count = string.count(search)
print(count)