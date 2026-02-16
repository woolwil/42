#!/usr/bin/env python3


def add_one(param):
	return param + 1


def main():
	num = 1
	print(num)
	add_one(num)
	# num = add_one(num)
	print(num)


if __name__ == "__main__":
	main()