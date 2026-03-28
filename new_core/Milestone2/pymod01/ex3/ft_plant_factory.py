#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, hght: float, age: int) -> None:
        self.name = name
        self.hght = hght
        self.age = age

    def show(self) -> None:
        print(f"Created: {self.name}: {self.hght:.1f}cm, {self.age} days old")

    def grow(self) -> None:
        self.hght += 0.6

    def advance_age(self) -> None:
        self.age += 10


def main() -> None:
    plants = [
        Plant("Rose", 25, 30),
        Plant("Oak", 200, 365),
        Plant("Cactus", 5, 90),
        Plant("Sunflower", 80, 45),
        Plant("Fern", 15, 120),
    ]

    print("\n=== Plant Factory Output ===")
    for plant in plants:
        plant.show()

    print("\n=== Plant Factory 30 Day Growth ===")
    for _ in range(1, 4):
        for plant in plants:
            plant.grow()
            plant.advance_age()

    for plant in plants:
        plant.show()


if __name__ == "__main__":
    main()
