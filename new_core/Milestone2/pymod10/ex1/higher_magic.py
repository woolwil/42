#!/usr/bin/env python3

from collections.abc import Callable


def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target} for {power} damage"


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def combined_spell(target: str, power: int) -> tuple[str, str]:
        res1 = spell1(target, power)
        res2 = spell2(target, power)
        return (res1, res2)
    return combined_spell


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def amplified_spell(target: str, power: int) -> str:
        new_power = power * multiplier
        return base_spell(target, new_power)
    return amplified_spell


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def conditional_spell(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell Fizzled"
    return conditional_spell


def spell_sequence(spells: list[Callable]) -> Callable:
    def sequence_spell(target: str, power: int) -> list[str]:
        return [spell(target, power) for spell in spells]
    return sequence_spell


def main() -> None:
    print("Testing spell combiner...")
    combo = spell_combiner(fireball, heal)
    res1, res2 = combo("Dragon", 10)
    print(f"Combined spell result: {res1}, {res2}")
    print()

    print("Testing power amplifier...")
    base_res = fireball("Dragon", 10)
    mega_fireball = power_amplifier(fireball, 3)
    amp_res = mega_fireball("Dragon", 10)
    print(f"Original: {base_res}")
    print(f"Amplified: {amp_res}")
    print()

    print("Testing conditional caster...")
    mega_fireball_on_dragon = conditional_caster(
        lambda target, power: target.lower() == "dragon",
        mega_fireball
    )
    print(mega_fireball_on_dragon("Dragon", 20))
    print(mega_fireball_on_dragon("Python", 20))
    print()

    print("Testing spell sequence...")
    sequencer = spell_sequence([fireball, heal, mega_fireball])
    print(sequencer("Dragon", 20))


if __name__ == "__main__":
    main()
