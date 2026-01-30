#!/usr/bin/env python3
import sys


if len(sys.argv) == 1:
	print("none")
else:
	for arg in reversed(sys.argv[1:]):
		print(arg)

	# args = sys.argv[1:]
	# i = len(args) - 1
	# while i >= 0:
	# 	print(args[i])
	# 	i -= 1