#!/usr/bin/env python3

num1 = int(input("Input num1: "))
num2 = int(input("Input num2: "))
mult = (num1 * num2)
print(str(num1) + "x" + str(num2) + " = " + str(mult))
if mult > 0:
	print("The result is positive.")
elif mult < 0:
	print("The result is negative")
elif mult == 0:

	print("The result is zero.")