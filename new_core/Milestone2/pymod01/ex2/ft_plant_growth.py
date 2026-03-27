#!/usr/bin/env python3

class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age_days = age

    def grow(self):
        self.height += 0.8

    def age(self):
        self.age_days += 1


def main():
    plant = Plant("Rose", 25, 30)
    start_height = plant.height

    print("=== Garden Plant Growth ===")

    for day in range(1, 8):
        print(f"=== Day {day} ===")
        print(f"{plant.name}: {plant.height:.1f}cm, {plant.age_days} days old")

        if day < 7:
            plant.grow()
            plant.age()

    total_growth = plant.height - start_height
    print(f"Growth this week: {total_growth:.1f}cm")


if __name__ == "__main__":
    main()
