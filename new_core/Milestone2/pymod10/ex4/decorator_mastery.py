#!/usr/bin/env python3

import time
import functools
from typing import Any
from collections.abc import Callable


def spell_timer(func: Callable) -> Callable:
    @functools.wraps(func)
    def wrapper(*args: Any, **kwargs: Any) -> Any:
        print(f"Casting {func.__name__}...")
        start = time.time()
        result = func(*args, **kwargs)
        time.sleep(1.4159)
        elapsed = time.time() - start
        print(f"Spell completed in {elapsed:.3f} seconds")
        return result
    return wrapper


def power_validator(min_power: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            power = kwargs.get("power")
            if power is None:
                for arg in args:
                    if isinstance(arg, int):
                        power = arg
                        break
            if power is not None and power < min_power:
                return "Insufficient power for this spell"
            return func(*args, **kwargs)
        return wrapper
    return decorator


def retry_spell(max_attempts: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if attempt <= max_attempts:
                        print(
                            f"Spell failed, retrying... (attempt "
                            f"{attempt}/{max_attempts})")
                        time.sleep(0.75)
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return decorator


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        return len(name) > 2 and all(c.isalpha() or c.isspace() for c in name)

    @power_validator(min_power=10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


def main() -> None:
    print("Testing spell timer...")

    @spell_timer
    def fireball() -> str:
        return "Fireball cast!"

    print(f"Result: {fireball()}\n")
    time.sleep(0.75)

    @retry_spell(max_attempts=3)
    def failing_spell() -> None:
        raise ValueError("Magic overflow!")

    @retry_spell(max_attempts=3)
    def working_spell() -> str:
        return "Waaaaaaagh spelled !"

    print("Testing retrying spell...")
    time.sleep(0.75)
    print(f"{failing_spell()}\n")
    time.sleep(0.75)
    print("Testing working spell...")
    time.sleep(0.75)

    print(working_spell())
    print("")

    time.sleep(0.75)

    print("Testing MageGuild...")
    print("Valid Name 'Dumbledore': ", end="", flush=True)
    time.sleep(0.75)
    print(MageGuild.validate_mage_name("Dumbledore"))
    time.sleep(0.75)
    print("Invalid Name 'A': ", end="", flush=True)
    time.sleep(0.75)
    print(MageGuild.validate_mage_name("A"))
    time.sleep(0.75)
    mage = MageGuild()
    print("Attempting to cast 'Cure' with power 40...")
    time.sleep(0.75)
    print(mage.cast_spell("Cure", 40))
    print()
    time.sleep(0.75)
    print("Attempting to cast 'Tickle' with power 0...")
    time.sleep(0.75)
    print(mage.cast_spell("Tickle", 0))
    time.sleep(0.75)
    print()

    print("Testing standalone spell with no target...")
    time.sleep(0.75)

    @power_validator(min_power=10)
    def simple_spell(power: int) -> str:
        return "Cast!"

    print(simple_spell(5))
    print(simple_spell(10))


if __name__ == "__main__":
    main()
