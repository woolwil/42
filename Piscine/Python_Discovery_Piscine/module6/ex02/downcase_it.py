#!/usr/bin/env python3
import sys

if len(sys.argv) == 1:
	print("none")
else:
	downcase = ' '.join(sys.argv[1:])
	print(downcase.lower())