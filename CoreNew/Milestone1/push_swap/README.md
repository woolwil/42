*This project has been created as part of the 42 curriculum by ngvo.*
# push_swap

## Description

`push_swap` is a project for sorting a stack of integers using a restricted set of stack operations. The program uses two stacks, `a` and `b`, and outputs the minimal sequence of operations to sort the input. The project emphasizes efficient input handling, error checking, and algorithmic sorting strategies.

**Error Handling:**
- Handles invalid argument counts, empty input, integer overflows, duplicates, and invalid characters.
- If any error is detected during input or stack population, the program frees all allocated memory and exits gracefully with an error message.

### How it works

1. **Initialization:**
   - Declares pointers to two linked lists (stacks `a` and `b`), both set to `NULL` to start with empty stacks.

2. **Input Handling:**
   - Ensures at least two arguments are provided and the second argument is not empty.
   - Supports both multiple command line arguments and a single string (split as needed).

3. **Stack Population & Validation:**
   - For each input, checks for integer overflow, duplicates, and syntax errors (only digits, `+`, or `-` allowed).
   - Converts valid strings to long integers and appends as nodes to stack `a`.
   - If any error is found, frees stack `a` and returns an error.

4. **Sorting:**
   - Checks if stack `a` is already sorted.
   - If not sorted:
     - For 2 numbers: swaps if needed.
     - For 3 numbers: uses a simple sort-three algorithm.
     - For more than 3 numbers: uses the "Turk Algorithm" for efficient sorting.

5. **Cleanup:**
   - Frees all allocated memory and cleans up both stacks before exiting.

## Instructions

To build the project, use the provided Makefile:

```
make
```

To run the program, provide a list of integers as arguments:

```
./push_swap 3 2 1 6 5
```

Or as a single quoted string:

```
./push_swap "3 2 1 6 5"
```

The program will output the sequence of operations required to sort the stack.

## Resources

- push_swap subject PDF
- [Linked list basics](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [push_swap TUTORIAL!](https://www.youtube.com/watch?v=wRvipSG4Mmk)

## Additional Info

**Error Handling:**
- Handles invalid argument counts, empty input, integer overflows, duplicates, and invalid characters.
- If any error is detected during input or stack population, the program frees all allocated memory and exits gracefully with an error message.