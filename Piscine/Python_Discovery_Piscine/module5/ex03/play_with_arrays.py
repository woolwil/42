#!/usr/bin/env python3

arr = [2, 8, 9, 48, 8, 22, -12, 2]
result = []
for i in arr:
	if i > 5:
		result.append(i + 2)
print(arr)
print((set(result)))