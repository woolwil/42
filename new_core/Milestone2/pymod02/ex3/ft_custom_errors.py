#!/usr/bin/env python3


class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


def test_custom_errors(sample: str) -> None:
    if sample == "plant":
        raise PlantError("The tomato plant is wilting!")
    if sample == "water":
        raise WaterError("Not enough water in the tank!")


def main() -> None:
    print("=== Custom Garden Errors Demo ===")
    print()

    print("Testing PlantError...")
    try:
        test_custom_errors("plant")
    except PlantError as error:
        print(f"Caught PlantError: {error}")
    print()

    print("Testing WaterError...")
    try:
        test_custom_errors("water")
    except WaterError as error:
        print(f"Caught WaterError: {error}")
    print()

    print("Testing catching all garden errors...")
    for sample in ["plant", "water"]:
        try:
            test_custom_errors(sample)
        except GardenError as error:
            print(f"Caught GardenError: {error}")
    print()

    print("All custom error types work correctly!")


if __name__ == "__main__":
    main()
