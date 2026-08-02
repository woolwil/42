#!/usr/bin/env python3

from ex0 import FlameFactory, AquaFactory
from ex0.factories import CreatureFactory


def test_factory(factory: CreatureFactory) -> None:
    print("Testing factory")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(f"{evolved.attack()}\n")


def test_battle(factory1: CreatureFactory, factory2: CreatureFactory) -> None:
    c1 = factory1.create_base()
    c2 = factory2.create_base()
    print("Testing battle")
    print(c1.describe())
    print("vs.")
    print(c2.describe())
    print("fight!")
    print(c1.attack())
    print(c2.attack())


def main() -> None:
    ff = FlameFactory()
    af = AquaFactory()
    test_factory(ff)
    test_factory(af)
    test_battle(ff, af)


if __name__ == "__main__":
    main()
