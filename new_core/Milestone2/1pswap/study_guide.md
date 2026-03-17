# push_swap Study Guide (42 Evaluation Prep)

This guide is based on your current `1pswap` folder implementation.
It is organized by `.c` file so you can quickly review each function during evaluation.

---

## 1) Big Picture: What your program does

Your `push_swap` flow is:
1. Parse and validate input numbers.
2. Build stack A as a doubly linked list (`t_stack`).
3. If needed, sort using:
   - tiny sort (`sa` / `sort_three`) for very small stacks,
   - Turk-style cost-based moves for larger stacks.
4. Finish by rotating A so the minimum number is on top.
5. Print operations as they happen.

---

## 2) Roadmap Rewritten (No Diagram, Just Story)

Think of this as 6 scenes in a movie.

### Scene 1 — Setup
- Read numbers from input.
- Reject bad input (letters, duplicates, out-of-range ints).
- Build stack A.

### Scene 2 — Quick exits
- If already sorted: stop.
- If 2 numbers: maybe do one `sa`.
- If 3 numbers: run `sort_three`.

### Scene 3 — Start big sort
- Move 2 numbers from A to B.
- Why: gives space in A and creates a helper stack B.

### Scene 4 — Main loop (A -> B)
- While A has more than 3 numbers:
   1. Compute info for each node in A (`index`, `target`, `cost`).
   2. Mark the cheapest node.
   3. Rotate A and B so that node and its target are on top.
   4. Push it from A to B (`pb`).

### Scene 5 — Bring back (B -> A)
- Sort the remaining 3 numbers in A.
- While B is not empty:
   1. Compute each B node’s target in A.
   2. Rotate A so target position is ready.
   3. Push top of B into A (`pa`).

### Scene 6 — Final alignment
- A is basically sorted but may start in the middle.
- Rotate A until the smallest number is at the top.
- Done.

---

### One-line roadmap

`Validate -> Build A -> Tiny-case? -> (If big) A->B cheapest loop -> sort_three -> B->A loop -> rotate min to top`

---

### Function map by phase (easy lookup)

| Phase | Main functions used |
|---|---|
| Setup | `init_stack_a`, `is_syntax_error`, `is_duplicate`, `error_free` |
| Quick exits | `stack_sorted`, `sa`, `sort_three` |
| Big sort start | `sort_stacks`, `pb` |
| A -> B loop | `init_nodes_a`, `set_target_a`, `cost_analysis`, `set_cheapest`, `move_a2b`, `prep_for_push`, `rr`, `rrr` |
| B -> A loop | `init_nodes_b`, `set_target_b`, `move_b2a`, `prep_for_push`, `pa` |
| Final alignment | `find_min`, `prep_for_push` |

---

### 10-second memory hook

`Check input -> reduce A to 3 -> rebuild A -> place min on top.`

---

## 3) Data Structure Reminder (`t_stack`)

Each node stores:
- `nbr`: integer value.
- `index`: current position from top.
- `above_median`: true if index is in first half.
- `target_node`: destination reference in the other stack.
- `push_cost`: estimated operation cost.
- `cheapest`: marks best candidate in A.
- `next` / `prev`: doubly linked list pointers.

---

## 4) File-by-File Function Guide

## `srcs/push_swap.c`

### `static void sort_if_needed(t_stack **a, t_stack **b)`
Step by step:
1. Check if A is already sorted (`stack_sorted`).
2. If 2 elements: swap top two (`sa`).
3. If 3 elements: call `sort_three`.
4. Otherwise: call full algorithm `sort_stacks`.

Why it exists:
- Fast path for tiny inputs, avoids unnecessary complex logic.

### `int main(int argc, char **argv)`
Step by step:
1. Initialize stacks `a` and `b` to `NULL`.
2. Handle empty input cases and return.
3. If single quoted arg: split with `ft_split`; otherwise use `argv + 1`.
4. Build and validate stack A via `init_stack_a`.
5. Sort using `sort_if_needed`.
6. Free memory (`free_stack`, optionally `free_split`).

Evaluation focus:
- Proper parsing mode (`argc == 2` vs many args).
- No leaks on normal exit.

---

## `srcs/error_handling.c`

### `void free_split(char **args)`
Step by step:
1. Guard against null/empty pointers.
2. Free each split token.
3. Free outer array.

### `void free_stack(t_stack **stack)`
Step by step:
1. Guard null.
2. Iterate node-by-node.
3. Free each node and move forward.
4. Set stack pointer to `NULL`.

### `void error_free(t_stack **stack, char **argv, int is_split)`
Step by step:
1. Free existing stack A.
2. Free split array if this parse mode used `ft_split`.
3. Print `Error` to stderr.
4. Exit with failure.

### `bool is_syntax_error(char *str)`
Step by step:
1. Accept optional `+` or `-` at start.
2. Reject sign-only strings.
3. Ensure every remaining char is a digit.
4. Return true on invalid token.

Evaluation focus:
- Robust invalid input handling and clean error path.

---

## `srcs/stack_init.c`

### `static long ft_atol(const char *s)`
Step by step:
1. Skip leading whitespace.
2. Parse optional sign.
3. Convert digit sequence into `long`.
4. Stop after too many digits (safety guard).
5. Return signed result.

### `bool is_duplicate(t_stack *stack, int n)`
Step by step:
1. Traverse stack.
2. Compare each `nbr` with `n`.
3. Return true on first match.
4. Return false if not found.

### `static bool append_node(t_stack **stack, int n)`
Step by step:
1. Allocate new node and fill value.
2. If stack empty: set as head.
3. Else find last node and append.
4. Wire `prev`/`next` pointers.
5. Return success/failure.

### `void init_stack_a(t_stack **a, char **argv, int is_split)`
Step by step:
1. Iterate each numeric token.
2. Validate syntax (`is_syntax_error`).
3. Convert and range-check (`INT_MIN..INT_MAX`).
4. Check duplicate values.
5. Append node to A.
6. On any failure, call `error_free`.

Evaluation focus:
- This is your input firewall: syntax, overflow, duplicates, malloc failure.

---

## `srcs/stack_utils.c`

### `int stack_len(t_stack *stack)`
Step by step:
1. Traverse list.
2. Count nodes.
3. Return count.

### `t_stack *find_last(t_stack *stack)`
Step by step:
1. Traverse until `next == NULL`.
2. Return tail node.

### `void current_index(t_stack *stack)`
Step by step:
1. Compute median index (`len / 2`).
2. Walk from head and assign sequential `index`.
3. Set `above_median` depending on index.

### `t_stack *find_min(t_stack *stack)`
Step by step:
1. Track smallest `nbr` seen.
2. Keep pointer to min node.
3. Return min node.

### `t_stack *find_max(t_stack *stack)`
Step by step:
1. Track largest `nbr` seen.
2. Keep pointer to max node.
3. Return max node.

Evaluation focus:
- These utilities drive all target/cost decisions.

---

## `srcs/stack_utils2.c`

### `static int max(int a, int b)`
Step by step:
1. Compare two ints.
2. Return larger one.

### `void cost_analysis(t_stack *a, t_stack *b)`
Step by step:
1. Compute lengths of A and B.
2. For each node in A, inspect its target in B.
3. If both nodes are in upper halves: cost is max of forward rotations.
4. If both are in lower halves: cost is max of reverse rotations.
5. Otherwise: sum separate rotations for each stack.
6. Store result in `a->push_cost`.

Why important:
- This function makes simultaneous `rr/rrr` optimization possible.

---

## `srcs/init_a2b.c`

### `void prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)`
Step by step:
1. Rotate until `top_node` becomes stack head.
2. If node in top half: use forward rotate (`ra`/`rb`).
3. If node in bottom half: use reverse rotate (`rra`/`rrb`).

### `void set_cheapest(t_stack *stack)`
Step by step:
1. Reset all `cheapest` flags.
2. Find node with minimum `push_cost`.
3. Mark only that node as `cheapest = true`.

### `void set_target_a(t_stack *a, t_stack *b)`
Step by step:
1. For each node in A, scan B.
2. Find the biggest value in B that is still smaller than `a->nbr`.
3. If found, assign as target.
4. If not found, target is max node in B.

Interpretation:
- Chooses where A-node should land in B to keep B in useful order.

### `void init_nodes_a(t_stack *a, t_stack *b)`
Step by step:
1. Refresh indexes/median flags for both stacks.
2. Compute A targets inside B.
3. Compute push costs.
4. Mark cheapest node in A.

---

## `srcs/init_b2a.c`

### `void init_nodes_b(t_stack *a, t_stack *b)`
Step by step:
1. Refresh indexes on both stacks.
2. Assign target in A for each node in B.

### `void set_target_b(t_stack *a, t_stack *b)`
Step by step:
1. For each node in B, scan A.
2. Find the smallest value in A that is still bigger than `b->nbr`.
3. If found, assign it as target.
4. If none found, fallback target is min node in A.

Interpretation:
- Places each B-node back into the correct ascending slot in A.

---

## `srcs/turk_alg.c`

### `void sort_stacks(t_stack **a, t_stack **b)`
Step by step:
1. Push two nodes from A to B (when possible) to bootstrap.
2. While A has more than 3 and is unsorted:
   - initialize A-node metadata (`init_nodes_a`),
   - move one best candidate A -> B (`move_a2b`).
3. Sort remaining 3 in A using `sort_three`.
4. While B not empty:
   - initialize B-node metadata (`init_nodes_b`),
   - move top candidate B -> A (`move_b2a`).
5. Re-index A and rotate minimum to top.

### `bool stack_sorted(t_stack *stack)`
Step by step:
1. Walk adjacent pairs in stack.
2. If any pair is descending, return false.
3. If no inversion exists, return true.

Evaluation focus:
- Explain this as your “main algorithm loop”.

---

## `srcs/sort_three.c`

### `void sort_three(t_stack **a)`
Step by step:
1. Find max node among 3.
2. If max is on top: `ra`.
3. Else if max is second: `rra`.
4. If top two still inverted: `sa`.

Why this works:
- Maximum is moved to bottom, then remaining two are fixed.

---

## `srcs/cmds/move.c`

### `t_stack *get_cheapest(t_stack *stack)`
Step by step:
1. Traverse nodes.
2. Return first node marked `cheapest`.
3. Return `NULL` if none.

### `void move_a2b(t_stack **a, t_stack **b)`
Step by step:
1. Fetch current cheapest node in A.
2. If cheapest and its target are both in top halves: co-rotate with `rr`.
3. If both in bottom halves: co-reverse-rotate with `rrr`.
4. Recompute indexes for both stacks.
5. Rotate A so cheapest is on top (`prep_for_push`).
6. Rotate B so target is on top (`prep_for_push`).
7. Execute `pb`.

### `void move_b2a(t_stack **a, t_stack **b)`
Step by step:
1. Rotate A so top of B can be inserted before its target.
2. Execute `pa`.

Evaluation focus:
- This file is where computed metadata becomes actual operations.

---

## `srcs/cmds/push.c`

### `static void push(t_stack **dest, t_stack **src)`
Step by step:
1. If source empty, return.
2. Detach source head node.
3. Fix new source head `prev`.
4. Insert detached node at destination head.
5. Fix destination pointers.

### `void pa(t_stack **a, t_stack **b, bool print)`
Step by step:
1. Push top of B to A.
2. Print `pa` if requested.

### `void pb(t_stack **b, t_stack **a, bool print)`
Step by step:
1. Push top of A to B.
2. Print `pb` if requested.

---

## `srcs/cmds/swap.c`

### `static void swap(t_stack **head)`
Step by step:
1. Check at least two nodes exist.
2. Keep pointers to first and second.
3. Rewire links so second becomes head.
4. Fix `prev` on affected nodes.

### `void sa(t_stack **a, bool print)`
Step by step:
1. Swap top two of A.
2. Print `sa` if requested.

### `void sb(t_stack **b, bool print)`
Step by step:
1. Swap top two of B.
2. Print `sb` if requested.

### `void ss(t_stack **a, t_stack **b, bool print)`
Step by step:
1. Swap top two of A and B.
2. Print `ss` if requested.

---

## `srcs/cmds/rotate.c`

### `static void rotate(t_stack **head)`
Step by step:
1. Ensure at least two nodes.
2. Save old head and tail.
3. Move head to second node.
4. Attach old head after old tail.
5. Update pointers (`prev`/`next`).

### `void ra(t_stack **a, bool print)`
Step by step:
1. Rotate A upward.
2. Print `ra` if requested.

### `void rb(t_stack **b, bool print)`
Step by step:
1. Rotate B upward.
2. Print `rb` if requested.

### `void rr(t_stack **a, t_stack **b, bool print)`
Step by step:
1. Ensure both stacks can rotate.
2. Rotate both.
3. Print `rr` if requested.

---

## `srcs/cmds/rev_rot.c`

### `static void reverse_rotate(t_stack **head)`
Step by step:
1. Ensure at least two nodes.
2. Take tail node.
3. Detach tail from previous node.
4. Insert tail as new head.
5. Fix pointers.

### `void rra(t_stack **a, bool print)`
Step by step:
1. Reverse rotate A.
2. Print `rra` if requested.

### `void rrb(t_stack **b, bool print)`
Step by step:
1. Reverse rotate B.
2. Print `rrb` if requested.

### `void rrr(t_stack **a, t_stack **b, bool print)`
Step by step:
1. Reverse rotate both stacks.
2. Print `rrr` if requested.

---

## `srcs/checker_bonus.c` (bonus)

### `static void free_error(t_stack **a, t_stack **b, char **args, int is_split)`
Step by step:
1. Free both stacks.
2. Free split args if used.
3. Print `Error` and exit.

### `static int apply_instruction(char *line, t_stack **a, t_stack **b)`
Step by step:
1. Compare input line with valid op names.
2. Execute matching command with `print=false`.
3. Return 1 on success.
4. Return 0 on invalid instruction.

### `static char *get_next_line_lite(int fd)`
Step by step:
1. Allocate short buffer (up to 4 chars + `\0`).
2. Read char by char until newline/EOF/limit.
3. Return `NULL` at clean EOF.
4. Return `"INVALID"` marker if command too long.

### `static void read_instructions(...)`
Step by step:
1. Loop reading instructions from stdin.
2. Validate and apply each instruction.
3. On invalid command: free and exit via `free_error`.

### `int main(int argc, char **argv)`
Step by step:
1. Parse args like `push_swap`.
2. Build and validate stack A.
3. Read and execute stdin instructions.
4. Print `OK` if A sorted and B empty, else `KO`.
5. Free all allocations.

---

## 5) Evaluation Talking Points (Quick Drill)

Use these points when the evaluator asks “why this design?”

- You use a doubly linked list because operations at the top and pointer rewiring are efficient.
- `current_index` + `above_median` lets you choose shortest rotation direction.
- `set_target_a/b` defines where each value should go in the opposite stack.
- `cost_analysis` estimates operation count and enables combined rotations (`rr`/`rrr`).
- `set_cheapest` ensures each loop moves the currently best candidate.
- Final `prep_for_push(find_min)` normalizes stack A so smallest value is on top.

---

## 6) Self-Check Questions Before Evaluation

1. Can you explain why fallback target in A->B is `find_max(b)`?
2. Can you justify fallback target in B->A as `find_min(a)`?
3. Why is re-indexing needed after combined rotations in `move_a2b`?
4. What guarantees no duplicates and no out-of-int-range values?
5. Why do we sort 3 elements separately?
6. What is the role of `print` flags in command functions?

If you can answer these confidently from memory, you’re in a strong position for the 42 push_swap evaluation.

---

## 7) Makefile Explanation (How your build works)

Your root `Makefile` builds two binaries:
- `push_swap` (mandatory)
- `checker` (bonus)

### Variables you should know

- `NAME = push_swap` and `CHECKER = checker`: output executable names.
- `CC = cc` and `CFLAGS = -Wall -Wextra -Werror`: compiler and strict flags required at 42.
- `LIBFT_DIR = libft` and `LIBFT_A = libft/libft.a`: static library path.
- `SRCS_DIR = srcs`, `OBJS_DIR = objs`: source and object directories.
- `CMDS_SRCS`, `COMMON_SRCS`, `PUSH_SWAP_SRCS`, `CHECKER_SRCS`: grouped source files.

### Main targets

#### `all`
Step by step:
1. Runs `libft` target first.
2. Builds `push_swap` target.

#### `bonus`
Step by step:
1. Runs `libft` target first.
2. Builds `checker` target.

#### `libft`
Step by step:
1. Calls `make -C libft`.
2. Delegates libft compilation to its own Makefile.

#### `$(NAME)` (push_swap link step)
Step by step:
1. Requires all `PUSH_SWAP_OBJS` and `libft.a`.
2. Links objects with `-Llibft -lft`.
3. Produces executable `push_swap`.

#### `$(CHECKER)` (checker link step)
Step by step:
1. Requires all `CHECKER_OBJS` and `libft.a`.
2. Links objects with `-Llibft -lft`.
3. Produces executable `checker`.

#### Pattern rule: `$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c`
Step by step:
1. Creates object subdirectory (`mkdir -p $(dir $@)`), including `objs/cmds/`.
2. Compiles each `.c` into matching `.o` with include flags.

Why it matters:
- This keeps object files mirrored by folder structure and avoids manual object rules.

#### `clean`
Step by step:
1. Removes `objs/` tree.
2. Calls `make clean` inside `libft`.

#### `fclean`
Step by step:
1. Runs `clean`.
2. Removes binaries (`push_swap` and `checker`).
3. Calls `make fclean` inside `libft`.

#### `re`
Step by step:
1. Runs `fclean`.
2. Runs `all`.

### Commands you can say during evaluation

- Build mandatory: `make`
- Build bonus checker: `make bonus`
- Clean objects only: `make clean`
- Full rebuild: `make re`

---

## 8) 60-Second Oral Cheat Script

If the evaluator asks “Explain your algorithm quickly”, you can say:

1. I parse and validate input in `init_stack_a`: syntax, int range, duplicates, malloc safety.
2. For small inputs, I do direct handling: `sa` for 2 values, `sort_three` for 3.
3. For larger inputs, `sort_stacks` pushes two values to B, then repeatedly computes metadata for A.
4. `init_nodes_a` computes indices, targets in B, push costs, and marks cheapest node.
5. `move_a2b` executes the cheapest move, using `rr`/`rrr` when both stacks rotate in same direction.
6. When A has 3 nodes left, I sort them with `sort_three`.
7. Then I reinsert from B to A using `init_nodes_b` + `move_b2a`.
8. Final step rotates A so minimum is on top, giving normalized sorted output.

---

## 9) Mock Evaluator Q&A (10 prompts + ideal short answers)

### 1) Q: Why did you choose a doubly linked list for stacks?
Ideal answer:
- Operations mostly modify top/tail and node links.
- `prev` + `next` makes swap/push/rotate pointer updates straightforward and efficient.

### 2) Q: What does `current_index` do and why is it necessary?
Ideal answer:
- It refreshes each node index and marks if it is in upper or lower half (`above_median`).
- This lets rotation direction decisions stay optimal after every move.

### 3) Q: Explain target selection from A to B (`set_target_a`).
Ideal answer:
- For each A node, I choose the biggest B value that is still smaller.
- If none exists, I target max(B) as fallback.
- This keeps B in a structure that is easy to rebuild back into A.

### 4) Q: Explain target selection from B to A (`set_target_b`).
Ideal answer:
- For each B node, I choose the smallest A value that is still bigger.
- If none exists, I target min(A) as fallback.
- This reinserts nodes into the correct ascending slot in A.

### 5) Q: What is `push_cost` and how do you compute it?
Ideal answer:
- It estimates operations needed to push one A node to B near its target.
- If both nodes rotate in same direction, cost uses max (shared rotations via `rr`/`rrr`).
- If directions differ, cost is sum of separate rotations.

### 6) Q: Why do you mark a single cheapest node each loop?
Ideal answer:
- `set_cheapest` picks the lowest-cost candidate in current state.
- Moving one best candidate repeatedly is the greedy strategy of this implementation.

### 7) Q: Why do you handle 2 and 3 elements separately?
Ideal answer:
- Tiny cases have deterministic minimal logic.
- It reduces operation count and avoids overhead of full target/cost pipeline.

### 8) Q: Why do you re-index after combined rotations in `move_a2b`?
Ideal answer:
- Combined rotations change node positions in both stacks.
- Without re-indexing, `prep_for_push` could use stale direction/index info.

### 9) Q: How do you guarantee input validity?
Ideal answer:
- `is_syntax_error` rejects non-numeric tokens and sign-only strings.
- `ft_atol` + bounds check prevents int overflow.
- `is_duplicate` rejects repeated values.
- On any failure, error path frees memory and exits with `Error`.

### 10) Q: How does your program finish in normalized sorted form?
Ideal answer:
- After all B nodes are pushed back to A, A is circularly sorted.
- Final `prep_for_push(a, find_min(a), 'a')` rotates minimum to top.
- Output then matches expected sorted stack orientation.

---

## 10) Glossary of Special Terms (Evaluation-Friendly)

### Doubly linked list
- A chain of nodes where each node points to both next and previous node.
- In your project, each stack is a doubly linked list (`next` + `prev`).

### Node
- One element in the list, storing value and metadata (`nbr`, `index`, `target_node`, etc.).

### Stack top / head
- The first node in the linked list.
- All push_swap operations act primarily near this node.

### Stack tail / last node
- The final node where `next == NULL`.
- Used in rotate/reverse-rotate operations.

### Pointer rewiring
- Updating `next` and `prev` links after operations like swap/push/rotate.
- Core technique that changes order without reallocating all nodes.

### Metadata (in this project)
- Extra per-node info used for decisions: `index`, `above_median`, `target_node`, `push_cost`, `cheapest`.

### Median (index median)
- `stack_len / 2` used as a split between upper and lower half.
- Helps choose `ra/rb` vs `rra/rrb` direction.

### above_median
- Boolean flag meaning a node is in the top half of its stack.
- True generally favors forward rotate; false favors reverse rotate.

### Target node
- The node in the opposite stack where a value should be positioned relative to.
- Computed by `set_target_a` and `set_target_b`.

### Cost analysis (`push_cost`)
- Estimated number of operations to move a node to its target position.
- Enables choosing best next move.

### Combined rotations (`rr`, `rrr`)
- Rotating both stacks together in one command.
- Reduces total operation count when both stacks need same direction.

### Greedy strategy
- At each step, choose the currently cheapest move (`set_cheapest`).
- Does not guarantee global optimum, but performs very well for push_swap scoring.

### Circularly sorted
- Stack is in sorted order if viewed as a cycle, but smallest value may not be at top.
- Happens after re-inserting from B to A.

### Normalization (final alignment)
- Final rotation so minimum value is moved to top of A.
- In your code: `prep_for_push(a, find_min(*a), 'a')`.

### Stable memory cleanup path
- Releasing all allocated memory in both normal and error exits.
- In your code: `free_stack`, `free_split`, `error_free`, and checker’s `free_error`.