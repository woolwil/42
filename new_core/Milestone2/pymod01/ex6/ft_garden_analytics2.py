#!/usr/bin/env python3


class Plant:
    class _Stats:
        def __init__(self) -> None:
            self.__grow_calls = 0
            self.__age_calls = 0
            self.__show_calls = 0

        def inc_grow(self) -> None:
            self.__grow_calls += 1

        def inc_age(self) -> None:
            self.__age_calls += 1

        def inc_show(self) -> None:
            self.__show_calls += 1

        def summary(self) -> str:
            return (
                f"Stats: {self.__grow_calls} grow, "
                f"{self.__age_calls} age, {self.__show_calls} show"
            )

    def __init__(self, name: str, cm: float, age_days: int) -> None:
        self.name = name
        self.cm = cm
        self.age_days = age_days
        self.__stats = self._Stats()

    @staticmethod
    def is_older_than_year(age_days: int) -> bool:
        return age_days > 365

    @classmethod
    def anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)

    def _inc_grow(self) -> None:
        self.__stats.inc_grow()

    def _inc_age(self) -> None:
        self.__stats.inc_age()

    def _inc_show(self) -> None:
        self.__stats.inc_show()

    def grow(self, cm: float = 1.0) -> None:
        self.cm += cm
        self._inc_grow()

    def age(self, days: int = 1) -> None:
        self.age_days += days
        self._inc_age()

    def show(self) -> None:
        self._inc_show()
        print(f"{self.name}: {self.cm:.1f}cm, {self.age_days} days old")

    def display_stats(self) -> None:
        print(f"[statistics for {self.name}]]")
        print(self.__stats.summary())


class Flower(Plant):
    def __init__(self, name: str, cm: float, age_days: int,
                 color: str, bloomed: bool = False) -> None:
        super().__init__(name, cm, age_days)
        self.color = color
        self.bloomed = bloomed

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if self.bloomed:
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")

    def bloom(self) -> None:
        self.bloomed = True


class Tree(Plant):
    class _TreeStats(Plant._Stats):
        def __init__(self) -> None:
            super().__init__()
            self.__shade_calls = 0

        def inc_shade(self) -> None:
            self.__shade_calls += 1

        def shade_summary(self) -> str:
            return f" {self.__shade_calls} shade"

    def __init__(self, name: str, cm: float, age_days: int,
                 trunk_diameter: float) -> None:
        super().__init__(name, cm, age_days)
        self.trunk_diameter = trunk_diameter
        self._Plant__stats = self._TreeStats()

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter:.1f}cm")

    def produce_shade(self) -> None:
        self._Plant__stats.inc_shade()
        print(
            f" Tree {self.name} now produces a shade of {self.cm:.1f}cm "
            f"long and {self.trunk_diameter:.1f}cm wide."
        )

    def display_stats(self) -> None:
        super().display_stats()
        print(self._Plant__stats.shade_summary())


class Seed(Flower):
    def __init__(
            self, name: str, cm: float, age_days: int,
            color: str, bloomed: bool = False, seed_count: int = 0,
    ) -> None:
        super().__init__(name, cm, age_days, color, bloomed)
        self.seed_count = seed_count

    def bloom(self, seeds: int = 0) -> None:
        super().bloom()
        self.seed_count = seeds

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self.seed_count}")


def display_plant_statistics(plant: Plant) -> None:
    plant.display_stats()


def main() -> None:
    flower = Flower("Rose", 15.0, 10, "red")
    tree = Tree("Oak", 200.0, 365, 5.0)
    seed = Seed("Sunflower", 80.0, 45, "yellow")
    unknown = Plant.anonymous()

    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_older_than_year(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_older_than_year(400)}")

    print("\n=== Flower")
    flower.show()
    display_plant_statistics(flower)
    print("[asking the rose to grow and bloom]")
    flower.grow(8.0)
    flower.bloom()
    flower.show()
    display_plant_statistics(flower)

    print("\n=== Tree")
    tree.show()
    display_plant_statistics(tree)
    print("[asking the oak to produce shade]")
    tree.produce_shade()
    display_plant_statistics(tree)

    print("\n=== Seed")
    seed.show()
    print("[make sunflower grow, age and bloom]")
    seed.grow(30.0)
    seed.age(20)
    seed.bloom(42)
    seed.show()
    display_plant_statistics(seed)

    print("\n=== Anonymous")
    unknown.show()
    display_plant_statistics(unknown)


if __name__ == "__main__":
    main()
