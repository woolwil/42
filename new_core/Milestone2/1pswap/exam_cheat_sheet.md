# push_swap Exam Cheat Sheet (42)

## 1) Build / Run Fast

- Build mandatory: `make`
- Build bonus checker: `make bonus`
- Rebuild clean: `make re`
- Run: `./push_swap "3 2 1"`
- Verify with checker: `ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG`

---

## 2) One-Minute Algorithm Pitch

1. Parse input and validate (`init_stack_a`): syntax, int range, duplicates.
2. Small cases:
   - 2 numbers -> `sa`
   - 3 numbers -> `sort_three`
3. Big cases (`sort_stacks`):
   - push two to B,
   - loop: compute metadata (`init_nodes_a`) then move cheapest A->B (`move_a2b`),
   - sort remaining 3 in A,
   - loop B->A with `init_nodes_b` + `move_b2a`,
   - rotate A so minimum is at top.

---

## 3) Core Ideas to Explain Clearly

- `current_index`: updates each node index + `above_median`.
- `set_target_a`: for each A node, choose insertion target in B.
- `set_target_b`: for each B node, choose insertion target in A.
- `cost_analysis`: estimates operation cost and enables `rr`/`rrr` optimization.
- `set_cheapest`: marks one best node to move next.
- `prep_for_push`: rotates chosen stack until target node reaches top.

---

## 4) Operation Semantics (must be fluent)

- `sa/sb/ss`: swap top 2.
- `pa/pb`: push top from one stack to the other.
- `ra/rb/rr`: rotate up (top goes bottom).
- `rra/rrb/rrr`: reverse rotate (bottom goes top).

---

## 5) Why your data structure works

- Doubly linked list (`next` + `prev`) makes rewiring for swap/push/rotate efficient.
- Useful metadata stored per node: `index`, `above_median`, `target_node`, `push_cost`, `cheapest`.

---

## 6) Common Evaluator Questions (quick answers)

- Why `find_max(b)` fallback in A->B?
  - If no smaller element exists in B, placing relative to max preserves intended B ordering.

- Why `find_min(a)` fallback in B->A?
  - If no bigger element exists in A, insert around min to keep circular sorted order.

- Why recompute indexes after rotations?
  - Rotations change positions, so costs/directions must be refreshed.

- Why separate `sort_three`?
  - Minimal deterministic operations for 3 nodes; avoids overhead of full algorithm.

---

## 7) Makefile Oral Notes

- `all` -> builds `libft`, then `push_swap`.
- `bonus` -> builds `libft`, then `checker`.
- Pattern rule creates `objs/...` mirrors automatically with `mkdir -p $(dir $@)`.
- `clean` removes object files + libft objects.
- `fclean` also removes executables.
- `re` = `fclean` + `all`.

---

## 8) Last 2-Minute Checklist Before Defense

- Can explain every field in `t_stack`.
- Can trace one full iteration of `move_a2b`.
- Can justify target selection rules in both directions.
- Can describe memory cleanup on normal and error paths.
- Can run and verify with `checker` confidently.

---

## 9) Rapid-Fire Flashcards (Q -> A)

1. Q: What does `push_swap` output?
  A: A sequence of valid stack operations that sorts A in ascending order.

2. Q: Why keep `index` in each node?
  A: To know current position and choose shortest rotation direction.

3. Q: Meaning of `above_median`?
  A: True if node is in top half of stack; guides rotate vs reverse rotate.

4. Q: `set_target_a` in one sentence?
  A: For each A node, pick the best insertion reference in B.

5. Q: `set_target_b` in one sentence?
  A: For each B node, pick where it should be inserted back into A.

6. Q: Why use `rr` / `rrr`?
  A: They combine two rotations into one operation when both stacks move same way.

7. Q: What is `push_cost`?
  A: Estimated total operations to place one A node into B at its target.

8. Q: Why call `set_cheapest` every loop?
  A: The cheapest node changes after each move due to new stack positions.

9. Q: Why sort 3 separately with `sort_three`?
  A: It is deterministic and minimal, faster than full metadata pipeline.

10. Q: Why final rotate to `find_min(a)`?
   A: To normalize A so smallest value is on top (expected final orientation).

11. Q: Where are invalid args handled?
   A: In `init_stack_a` using syntax, range, duplicate, and allocation checks.

12. Q: What prints `Error`?
   A: `error_free` in mandatory and `free_error` in checker bonus.

13. Q: Why pass `print=false` in checker?
   A: Checker executes operations silently; it should only output `OK` or `KO`.

14. Q: Build mandatory vs bonus?
   A: `make` builds `push_swap`, `make bonus` builds `checker`.

15. Q: What does `re` do in Makefile?
   A: Full rebuild: `fclean` then `all`.

---

## 10) Hard-Mode Flashcards (Tricky Evaluator Style)

1. Q: In `move_a2b`, why do you run `current_index` again after `rr/rrr`?
  A: Combined rotations shift both stacks; old indexes/median flags become stale before `prep_for_push`.

2. Q: If `get_cheapest` returns `NULL`, what happens?
  A: In this flow it should not happen because `set_cheapest` runs first; if asked, I’d mention adding a guard for defensive robustness.

3. Q: Why is fallback in `set_target_a` equal to max(B), not min(B)?
  A: If no smaller value exists, wrapping around max(B) preserves the intended circular ordering strategy for B.

4. Q: Why is fallback in `set_target_b` equal to min(A), not max(A)?
  A: If no bigger value exists, insertion wraps around at min(A), which maintains A’s circular sorted structure.

5. Q: Does your parser accept spaces like `"   +42"`?
  A: Yes for `ft_atol` conversion, but each token comes from argv/split; syntax validity is enforced by `is_syntax_error`.

6. Q: Why store metadata in nodes instead of computing every time?
  A: It avoids repeated scans inside move decisions and makes each loop deterministic: index/target/cost/cheapest are explicit state.

7. Q: What is the complexity intuition of your approach?
  A: It is greedy and practical for push_swap scoring; each iteration evaluates candidates and applies low-cost moves rather than brute force.

8. Q: Why not always rotate stacks separately instead of `rr/rrr`?
  A: Separate rotations increase operation count; combined ops compress two rotations into one command.

9. Q: How do you ensure checker rejects invalid instructions safely?
  A: `apply_instruction` returns 0 on unknown op, then `read_instructions` frees memory and exits with `Error`.

10. Q: What memory is freed in normal `push_swap` path vs error path?
   A: Normal path frees stack A and split args if used; error path frees built stack and split args before exit.

11. Q: Why does `rr` guard for both stacks, but `rrr` does not?
   A: In your code `rr` explicitly guards; `rrr` delegates guards to `reverse_rotate` per stack. Behavior is safe, but style can be unified.

12. Q: Why are command functions parameterized by `print`?
   A: Same operation logic is reused by `push_swap` (print ops) and `checker` (silent execution).