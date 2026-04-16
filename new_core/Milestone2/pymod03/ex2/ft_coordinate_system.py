#!/usr/bin/env python3

import math


def get_player_pos() -> tuple[float, float, float]:
    while True:
        raw = input("Enter new coordinates as floats in format 'x,y,z': ")
        parts = raw.split(",")

        if len(parts) != 3:
            print("Invalid syntax")
            continue

        values = []
        has_error = False
        for part in parts:
            token = part.strip()
            try:
                values.append(float(token))
            except ValueError as error:
                print(f"Error on parameter '{token}': {error}")
                has_error = True
                break

        if has_error:
            continue

        return (values[0], values[1], values[2])


def main() -> None:
    origin = (0.0, 0.0, 0.0)
    print("=== Game Coordinate System ===")
    print()
    print("Get a first set of coordinates")
    first_pos = get_player_pos()
    print(f"Got a first tuple: {first_pos}")
    print(f"It includes: X={first_pos[0]}, Y={first_pos[1]},"
          f" Z={first_pos[2]}")
    d11 = (first_pos[0] - origin[0])**2
    d12 = (first_pos[1] - origin[1])**2
    d13 = (first_pos[2] - origin[2])**2
    distance = math.sqrt(d11 + d12 + d13)
    print(f"Distance to center: {distance:.4f}")
    print()

    print("Get a second set of coordinates")
    second_pos = get_player_pos()
    d21 = (second_pos[0] - first_pos[0])**2
    d22 = (second_pos[1] - first_pos[1])**2
    d23 = (second_pos[2] - first_pos[2])**2
    distance2 = math.sqrt(d21 + d22 + d23)
    print(f"Distance between the 2 sets of coordinates: {distance2:.4f}")


if __name__ == "__main__":
    main()
