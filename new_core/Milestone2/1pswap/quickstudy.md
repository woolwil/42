# Quick Study: Checker + Makefile (push_swap)

## 1) Checker in 20 seconds
Checker validates input, builds stack A, then reads operations from stdin line by line.
Each line must be a valid push_swap instruction; valid ones are executed with print disabled.
If an instruction is invalid, checker prints `Error` and exits after cleanup.
At end of input, it prints `OK` only if A is sorted and B is empty, otherwise `KO`.

## 2) Checker flow (correct order)
1. Parse argv mode (`argc == 2` split, else `argv + 1`).
2. Build and validate stack A (`init_stack_a`).
3. Initialize stack B as `NULL` in main.
4. Read stdin instructions (`get_next_line_lite`).
5. Validate and dispatch (`apply_instruction`).
6. On invalid instruction: `Error` + cleanup + exit.
7. On EOF: if A sorted and B empty -> `OK`, else `KO`.
8. Free all owned memory before return.

## 3) Checker trap fixes
- Wrong: checker parses push_swap output internally.
  - Correct: checker reads stdin only (pipe is just one input source).
- Wrong: `KO` is an error path.
  - Correct: `KO` is a valid final result path.
- Wrong: stack B is initialized in instruction loop.
  - Correct: B is set to `NULL` in main before reading instructions.

## 4) Makefile in 20 seconds
- `all`: build libft, then mandatory `push_swap`.
- `bonus`: build libft, then `checker`.
- `clean`: remove object files and run `libft` clean.
- `fclean`: clean + remove binaries + run `libft` fclean.
- `re`: `fclean` then `all`.

## 5) Why libft is built first
Final linking needs `libft.a`. If it is missing or stale, linking fails or uses outdated symbols.

## 6) Pattern rule explanation
- Maps each `srcs/*.c` to mirrored `objs/*.o`.
- Uses compile-only step (`-c`) and explicit output (`-o`).
- Uses `mkdir -p $(dir $@)` so nested object directories exist before compile.

## 7) Why source lists are grouped
Split sources into common, push_swap-only, checker-only to:
1. Reuse shared logic in both binaries.
2. Avoid linking target-specific files into wrong binary.
3. Make maintenance safer when adding/removing source files.

## 8) One-liners for evaluator
- Why call `make -C libft clean/fclean` too?
  - Because libft has its own objects and archive, and its own Makefile owns their cleanup.
- Why print flag exists in ops?
  - Reuse same operation logic in both programs while controlling output behavior.

## 9) 15-second fallback script
Checker validates args, builds A, executes only valid stdin instructions with silent ops, prints `Error` on invalid instruction, then prints `OK` if A sorted and B empty, else `KO`.
Makefile builds libft before linking, separates shared/target-specific sources for correctness, and uses `clean`/`fclean`/`re` for reliable cleanup and rebuild.

## 10) Whole push_swap quick one-liners
- Big picture: validate input, build stack A, sort with tiny cases or Turk, then rotate min to top.
- Tiny cases: 2 numbers -> maybe `sa`; 3 numbers -> `sort_three`; already sorted -> print nothing.
- Why two stacks: B is a helper buffer to reduce A and reinsert values in controlled order.
- `current_index` role: refresh `index` and `above_median` so rotate direction stays optimal.
- `set_target_a` rule: for each A node, target is largest value in B smaller than A value; fallback is `max(B)`.
- `set_target_b` rule: for each B node, target is smallest value in A bigger than B value; fallback is `min(A)`.
- Cost rule: same direction => `max(rot_a, rot_b)`; mixed direction => `rot_a + rot_b`.
- Why `rr/rrr`: when both nodes need same direction, shared rotations cut total operations.
- `set_cheapest` guarantee: best move now (local optimum), not guaranteed best total sequence (global optimum).
- Why reindex after rotations: positions changed, stale metadata can make `prep_for_push` rotate wrong way.
- Why `sort_three`: deterministic and cheaper than running full target/cost pipeline on 3 nodes.
- Circularly sorted means order is correct as a cycle but head may start in the middle.
- Final normalization: `prep_for_push(a, find_min(*a), 'a')` puts minimum on top.
- Input firewall: reject bad syntax, duplicates, and out-of-int range values before sorting.
- Memory safety: free owned resources on both success and error paths (`free_stack`, `free_split`, `error_free`).

## 11) 30-second full oral script
I validate input first (syntax, duplicates, int bounds), then build stack A as a doubly linked list. For small sizes I use direct logic (`sa` for 2, `sort_three` for 3). For larger sets I use Turk: push two nodes to B, compute index/median, targets, and `push_cost` for A nodes, pick the current cheapest, align both stacks with `rr`/`rrr` when possible, then `pb`. After A is reduced to three nodes, I sort them, then reinsert from B to A using targets in A and `pa`. At the end A is circularly sorted, so I rotate until minimum is on top. Cleanup is handled on both normal and error exits.
