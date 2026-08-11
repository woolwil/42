#!/usr/bin/env python3

from typing import Any
from collections.abc import Callable
import functools
import operator


def spell_reducer(spells: list[int], operation: str) -> int:
    operations: dict[str, Callable[[int, int], int]] = {
        "add": operator.add,
        "multiply": operator.mul,
        "max": max,
        "min": min,
    }
    if not spells:
        return 0
    if operation not in operations:
        raise ValueError("Unknown operation")
    return functools.reduce(operations[operation], spells)


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    return {
            "fire_enchant": functools.partial(base_enchantment, power=50,
                                              element="fire"),
            "ice_enchant": functools.partial(base_enchantment, power=50,
                                             element="ice"),
            "lightning_enchant": functools.partial(base_enchantment, power=50,
                                                   element="lightning"),
        }


@functools.lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable:
    @functools.singledispatch
    def dispatch(spell: Any) -> str:
        return "Unknown spell type"

    @dispatch.register(int)
    def _(spell: int) -> str:
        return f"Damage spell: {spell} damage"

    @dispatch.register(str)
    def _(spell: str) -> str:
        return f"Enchantment: {spell}"

    @dispatch.register(list)
    def _(spell: list) -> str:
        return f"Multi-cast: {len(spell)} spells"

    return dispatch


def main() -> None:
    print("Testing spell reducer...")
    total_sum = spell_reducer([val for val in range(1, 15)], 'add')
    print(f"Sum: {total_sum}")
    total_multiply = spell_reducer([val for val in range(1, 6)], 'multiply')
    print(f"Multiply: {total_multiply}")
    find_max = spell_reducer([val for val in range(1, 51)], 'max')
    print(f"Max: {find_max}")
    find_min = spell_reducer(list(range(1, 300)), 'min')
    print(f"Min: {find_min}")
    try:
        spell_reducer(list(range(1, 5)), 'idk')
    except ValueError as e:
        print(e)
    print()

    print("Testing partial enchanter...")

    def base_enchant(power: int, element: str, target: str) -> str:
        return f"{element.capitalize()} {target} (Power: {power})"
    enchants = partial_enchanter(base_enchant)
    print(enchants["fire_enchant"](target="Sword"))
    print(enchants["ice_enchant"](target="Shield"))
    print(enchants["lightning_enchant"](target="Staff"))
    print()
    print("Testing memoized fibonacci...")
    fib0 = memoized_fibonacci(0)
    fib1 = memoized_fibonacci(1)
    fib10 = memoized_fibonacci(10)
    fib15 = memoized_fibonacci(15)
    print(f"Fib(0): {fib0}")
    print(f"Fib(1): {fib1}")
    print(f"Fib(10): {fib10}")
    print(f"Fib(15): {fib15}")
    print(f"Memoized Fibonacci Cache: {memoized_fibonacci.cache_info()}")
    print("Calling Fib(15) again...")
    fib15 = memoized_fibonacci(15)
    print(f"Fib(15): {fib15}")
    print(f"Memoized Fibonacci Cache: {memoized_fibonacci.cache_info()}")
    print()
    print("Testing spell dispatcher...")
    dispatcher = spell_dispatcher()
    print(dispatcher(42))
    print(dispatcher('Firaga'))
    print(dispatcher(['Blizzaga', 'Firaga', 'Cure']))
    print(dispatcher(3.14159))


if __name__ == "__main__":
    main()
