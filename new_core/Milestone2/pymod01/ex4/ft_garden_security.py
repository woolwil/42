#!/usr/bin/env python3

class Plant:
    def __init__(self, n: str, cm: float, age: int) -> None:
        self.n = n
        self.cm = cm
        self.age = age

    def show(self) -> None:
        print(f"Plant created: {self.n}: {self.cm:.1f}cm, {self.age} days old")
        print("")

    def set_height(self, set_height: float) -> None:
        if set_height > 0:
            self.cm = set_height
            print(f"Height updated: {self.cm}cm")
        else:
            print(f"{self.n}: Error, height can't be negative")
            print("Height update rejected")

    def set_age(self, set_age: int) -> None:
        if set_age > 0:
            self.age = set_age
            print(f"Age updated: {self.age} days")
        else:
            print(f"{self.n}: Error, age can't be negative")
            print("Age update rejected")

    def get_height(self) -> float:
        return self.cm

    def get_age(self) -> int:
        return self.age


def main() -> None:
    plants = [
        Plant("Rose", 15, 10),
    ]

    print("\n=== Garden Security System ===")

    for plant in plants:
        plant.show()

    plant.set_height(25)
    plant.set_age(30)
    print("")
    plant.set_height(-1)
    plant.set_age(-1)
    new_height = plant.get_height()
    new_age = plant.get_age()
    print("")
    print(f"Current status: {plant.n}: {new_height:.1f}cm, {new_age} days old")
    print("")


if __name__ == "__main__":
    main()
