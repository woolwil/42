#!/usr/bin/env python3

num = int(input("Enter first value\n"))
if (num) > 25:
	print("Error")
for x in range(num, 26):
	print("Inside the loop, my variable is: " + str(x))