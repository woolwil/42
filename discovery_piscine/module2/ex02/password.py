#!/usr/bin/env python3

password = "python"
pw = input("enter a password: ")
if	pw != password:
	print("akses denied")
elif pw == password:
	print("akses granted")