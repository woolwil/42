## Pseudo code
#### Declare pointers to two data structures/linked lists, one for stack `a` and annother for `b`
- Set both pointers to `NULL` to avoid undefined behaviour and indicate we're starting with empty stacks
#### Handle input count errors. Argument count must be 2 or more, and the second input must not be empty
- If input errors, return error
#### Handle both cases of input, whether a variable number of command line arguments, or as a string
- If the input of numbers is a string, call `split()` to split the substrings
#### Initialize stack `a` by appending each input number as a node to stack `b`
- Handle integer overflow, duplicates, and syntax errors, e.g. input must only contain digits, or `-` or `+` signs
	- If errors found, free stack `a` and return error
- Check for each input, if it is a `long` integer
	- If the input is a string, convert it to a `long` integer
- Append the nodes to stack `a`

#### Check if stack `a` is sorted
- If not sorted, implement our sorting algorithm
	- Check for 2 numbers
		- If so, simply swap the numbers
	- Check for 3 numbers
		- If so, implemet simple `sort three` algorithm
	- Check if stack has more than 3 numbers
		- If so, implement the `Turk Algorithm`

#### Clean up the stack 