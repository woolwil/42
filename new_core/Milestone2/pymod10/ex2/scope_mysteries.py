#!/usr/bin/env python3

from typing import Any
from collections.abc import Callable


def mage_counter() -> Callable:
    count = 0

    def counter() -> int:
        nonlocal count
        count += 1
        return count
    return counter


def spell_accumulator(initial_power: int) -> Callable:
    def accumulator(amount: int) -> int:
        nonlocal initial_power
        initial_power += amount
        return initial_power
    return accumulator


def enchantment_factory(enchantment_type: str) -> Callable:
    def return_enchanted(item_name: str) -> str:
        return f"{enchantment_type} {item_name}"
    return return_enchanted


def memory_vault() -> dict[str, Callable]:
    vault = {}

    def store(key: str, value: Any) -> None:
        vault[key] = value

    def recall(key: str) -> None:
        return vault.get(key, "Memory not found")
    return {
        "store": store,
        "recall": recall,
        }


def main() -> None:
    print("Testing mage counter...")
    a_counter = mage_counter()
    print(f"counter_a call 1: {a_counter()}")
    print(f"counter_a call 2: {a_counter()}")
    b_counter = mage_counter()
    print(f"counter_b call 1: {b_counter()}")
    print()
    print("Testing spell accumulator...")
    base1 = spell_accumulator(100)
    print(f"Base 100, add 20: {base1(20)}")
    print(f"Base 100+20 = 120, add 30: {base1(30)}")
    print()
    print("Testing enchantment factory...")
    sword_enchanter = enchantment_factory("Flaming")
    shield_enchanter = enchantment_factory("Frozen")
    print(sword_enchanter("Sword"))
    print(shield_enchanter("Shield"))
    print()
    print("Testing memory vault...")
    vault_actions = memory_vault()
    store = vault_actions["store"]
    recall = vault_actions["recall"]
    print("Store 'secret' = 42")
    store("secret", 42)
    print(f"Recall 'secret: {recall("secret")}")
    print(f"Recall 'unknown: {recall("unknown")}")


if __name__ == '__main__':
    main()
