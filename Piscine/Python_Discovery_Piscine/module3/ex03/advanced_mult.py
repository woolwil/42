#!/usr/bin/env python3

i = 0
while i < 11:
	print("Table of " + str(i) + ": ", end=" ")
	j = 0
	while j < 11:
		print(i * j, end=" ")
		j += 1
	print()
	i += 1