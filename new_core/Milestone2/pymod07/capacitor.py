#!/usr/bin/env python3

from ex1.capabilities import HealCapability, TransformCapability
from ex1 import HealingCreatureFactory, TransformCreatureFactory


def test_heal() -> None:
    print("Testing Creature with healing capability")
    print(" base:")
    hcf = HealingCreatureFactory()
    hc = hcf.create_base()
    assert isinstance(hc, HealCapability)
    print(hc.describe())
    print(hc.attack())
    print(hc.heal())
    print(" evolved:")
    hc = hcf.create_evolved()
    assert isinstance(hc, HealCapability)
    print(hc.describe())
    print(hc.attack())
    print(hc.heal())


def test_transform() -> None:
    print("Testing Creature with transform capability")
    print(" base:")
    tcf = TransformCreatureFactory()
    tc = tcf.create_base()
    assert isinstance(tc, TransformCapability)
    print(tc.describe())
    print(tc.attack())
    print(tc.transform())
    print(tc.attack())
    print(tc.revert())
    print(" evolved:")
    tc = tcf.create_evolved()
    assert isinstance(tc, TransformCapability)
    print(tc.describe())
    print(tc.attack())
    print(tc.transform())
    print(tc.attack())
    print(tc.revert())


def main() -> None:
    test_heal()
    print()
    test_transform()


if __name__ == "__main__":
    main()
