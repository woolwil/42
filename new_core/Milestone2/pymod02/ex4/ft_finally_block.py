#!/usr/bin/env python3

class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


def water_plant(plant_name) -> None:
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")


def test_watering_system() -> None:
    print("Testing valid plants...")
    print("Opening watering system")
    for plant in ["Tomato", "Lettuce", "Carrots"]:
        water_plant(plant)
    print("Closing watering system")
    print()

    print("Testing invalid plants...")
    print("Opening watering system")
    try:
        for j in ["Tomato", "lettuce"]:
            water_plant(j)
    except PlantError as error:
        print(f"Caught PlantError: {error}")
    finally:
        print(".. ending tests and returning to main")
        print("Closing watering system")


def main() -> None:
    print("=== Garden Watering System ===")
    print()
    test_watering_system()
    print()
    print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    main()
