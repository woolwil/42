*This project has been created as part of the 42 curriculum by ngvo.*

# push_swap

`push_swap` sorts integers with two stacks (`a`, `b`) and a limited set of operations.
The mandatory program prints the operation list, and the bonus program (`checker`) verifies
whether a provided operation list correctly sorts the input.

## Features

- Supports both input styles:
   - `./push_swap 3 2 1 6 5`
   - `./push_swap "3 2 1 6 5"`
- Strong input validation:
   - invalid characters / malformed numbers
   - integer overflow (`INT_MIN` / `INT_MAX` bounds)
   - duplicates
   - empty argument edge cases
- Sorting strategy:
   - `2` numbers: `sa` if needed
   - `3` numbers: dedicated `sort_three`
   - `>3` numbers: Turk-based cost/target approach (`sort_stacks`)
- Bonus checker:
   - reads instructions from `stdin`
   - applies only valid push_swap operations
   - prints `OK` or `KO`, prints `Error` on invalid instruction/input

## Project Layout

- `srcs/push_swap.c`: main entry for mandatory program
- `srcs/checker_bonus.c`: main entry for bonus checker
- `srcs/turk_alg.c`: high-level sorting loop (`sort_stacks`)
- `srcs/init_a2b.c`, `srcs/init_b2a.c`: target/cost initialization logic
- `srcs/cmds/`: stack operations (`sa`, `pb`, `ra`, `rra`, ...)
- `srcs/stack_init.c`: parsing, duplicate checks, and stack construction
- `srcs/error_handling.c`: centralized free/error utilities
- `libft/`: project dependency

## Build

```bash
make
```

Builds mandatory executable:
- `./push_swap`

Build bonus checker:

```bash
make bonus
```

Builds:
- `./checker`

## Usage

### Mandatory

```bash
./push_swap 3 2 1 6 5
./push_swap "3 2 1 6 5"
```

### Bonus Checker

```bash
ARG="3 2 1 6 5"
./push_swap $ARG | ./checker $ARG
```

Expected output:
- `OK` if sorted and stack `b` is empty
- `KO` otherwise

Invalid instruction example:

```bash
printf "sa\nxx\n" | ./checker 2 1
```

Expected output:
- `Error`

## Quick Evaluation Helpers

Count number of operations:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

Check correctness quickly:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```
Check for multiple random values with number of moves
```bash
for i in {1..10}; do
ARG=$(seq 1 500 | shuf | xargs); ./push_swap $ARG | wc -l;
done

```

Check for multiple random values with checker
```bash
for i in {1..10}; do
ARG=$(seq 1 500 | shuf | xargs); ./push_swap $ARG | ./checker $ARG;
done

```

## Clean Targets

```bash
make clean
make fclean
make re
```

## Resources and useful tools

- push_swap subject PDF
- [Linked list basics](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [push_swap TUTORIAL!](https://www.youtube.com/watch?v=wRvipSG4Mmk)
- [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Push_swap_tester](https://github.com/gemartin99/Push-Swap-Tester)