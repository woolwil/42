#!/usr/bin/env python3
import sys

def error():
	if len(sys.argv) < 2:
		print("usage: ./methods_everywhere.py <params> ...")


def shrink(string):
	print(string[:8])


def enlarge(string):
	print(string.ljust(8, 'Z'))

def main():
	error()
	args = sys.argv[1:]
	for arg in args:
		if len(arg) < 8:
			enlarge(arg)
		elif len(arg) > 8:
			shrink(arg)
		else:
			print(arg)

if __name__ == "__main__":
	main()