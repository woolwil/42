#!/usr/bin/env python3

from typing import Any
from collections.abc import Callable
import functools
import operator

OPERATIONS = {
    "add": operator.add,
    "multiply": operator.mul,
    "max": operator.max,
    "min": operator.min,
}


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0
    if operation not in OPERATIONS:
        raise ValueError("Unknown operation")
    return functools.reduce(OPERATIONS[operation], spells)

def partial_enchanter(base_enchantment: Callable):
    return {
            "fire_enchant": functools.partial(base_enchantment, power=50,
            element="fire"),
            "ice_enchant": functools.partial(base_enchantment, power=50,
            element="ice"),
            "lightning_enchant": functools.partial(base_enchantment, power=50,
            element="lightning"),
        }



def memoized_fibonacci(n: int) -> int:
    pass


def spell_dispatcher() -> Callable[[Any], str]:
    pass

