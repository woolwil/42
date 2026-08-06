#!/usr/bin/env python3

def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(
        artifacts, key=lambda artifact: artifact['power'],
        reverse=True
        )


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda mage: mage['power'] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda spell: f"* {spell} *", spells))


def mage_stats(mages: list[dict]) -> dict:
    powers = list(map(lambda m: m['power'], mages))
    max_power = max(powers)
    min_power = min(powers)
    avg_power = round(sum(powers) / len(powers), 2)
    return {
        'max_power': max_power,
        'min_power': min_power,
        'avg_power': avg_power,
    }


def main() -> None:
    print("Testing artifact sorter...")
    artifacts = [
        {'name': 'Lightning Rod', 'power': 69, 'type': 'weapon'},
        {'name': 'Ice Wand', 'power': 100, 'type': 'accessory'},
        {'name': 'Storm Crown', 'power': 113, 'type': 'relic'},
        {'name': 'Lightning Rod', 'power': 85, 'type': 'armor'},
        ]
    print(f"{artifact_sorter(artifacts)}\n")
    mages = [
        {'name': 'Ash', 'power': 78, 'element': 'ice'},
        {'name': 'River', 'power': 57, 'element': 'water'},
        {'name': 'Sage', 'power': 95, 'element': 'light'},
        {'name': 'Kai', 'power': 63, 'element': 'earth'},
        {'name': 'Phoenix', 'power': 100, 'element': 'ice'},
        ]
    print("Testing mage power filter...")
    print(f"{power_filter(mages, 75)}\n")
    spells = ['tornado', 'shield', 'meteor', 'earthquake']
    print("Testing spell transformer...")
    print(f"{" ".join(spell_transformer(spells))}\n")
    print("Testing mage stats...")
    print(f"{mage_stats(mages)}\n")


if __name__ == "__main__":
    main()
