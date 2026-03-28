#!/usr/bin/env python3

class Plant:
    def __init__(self, n: str, cm: float, age_days: int) -> None:
        self.n = n
        self.cm = cm
        self.age_days = age_days

    def show(self) -> None:
        print(f"{self.n}: {self.cm:.1f}cm, {self.age_days} days old")


class Flower(Plant):
    def __init__(self, n: str, cm: float, age_days: int,
                 color: str, bloomed: bool = False) -> None:
        super().__init__(n, cm, age_days)
        self.color = color
        self.bloomed = bloomed

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if self.bloomed:
            print(f" {self.n} is blooming beautifully!")
        else:
            print(f" {self.n} has not bloomed yet")

    def bloom(self) -> None:
        self.bloomed = True
        self.show()


class Tree(Plant):
    def __init__(self, n: str, cm: float, age_days: int,
                 trunk_diameter: float) -> None:
        super().__init__(n, cm, age_days)
        self.trunk_diameter = trunk_diameter

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter:.1f}cm")

    def produce_shade(self) -> None:
        print(f"Tree {self.n} now produces a shade of ", end='')
        print(f"{self.cm:.1f}cm long and {self.trunk_diameter:.1f}cm wide.")


class Vegetable(Plant):
    def __init__(self, n: str, cm: float, age_days: int,
                 harvest_season: str, nutritional_value: int) -> None:
        super().__init__(n, cm, age_days)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")

    def grow(self) -> None:
        self.cm += 2.1

    def age(self) -> None:
        self.age_days += 1
        self.grow()
        self.inc_nutrition()

    def inc_nutrition(self) -> None:
        self.nutritional_value += 1


def main() -> None:
    flower = Flower("Rose", 15, 10, "red")
    tree = Tree("Oak", 200, 365, 5)
    vegetable = Vegetable("Tomato", 5, 10, "April", 0)

    print("=== Garden Plant Types ===")
    print("=== Flower")
    flower.show()
    print("[asking the rose to bloom]")
    flower.bloom()

    print("\n=== Tree")
    tree.show()
    print("[asking the oak to produce shade]")
    tree.produce_shade()

    print("\n=== Vegetable")
    vegetable.show()
    print("[make tomato grow and age for 20 days]")
    for _ in range(0, 20):
        vegetable.age()
    vegetable.show()


if __name__ == "__main__":
    main()
