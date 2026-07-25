#!/usr/bin/env python3

import math


# First, write a function get_player_pos() that:
# • Asks the user for the new player coordinates in the format x,y,z
# • Handles improper inputs
# • Retries until a valid set of coordinates is provided
# • Returns a tuple containing the player’s current 3D coordinates
# Then your code will:
# • Get a first set of coordinates
# • Display the tuple then display each coordinate separately
# • Calculate the distance to the 3D center (0, 0, 0) (see below)
# • Get a new set of coordinates
# • Calculate the distance between the second and the first sets of coordinates

def get_player_pos() -> tuple[float, float, float]:
    while True:
        values = []
        has_error = False
        raw_data = input("Enter new coordinates as floats in format 'x,y,z': ")
        split_data = raw_data.split(",")

        if len(split_data) != 3:
            print("Invalid syntax")
            continue

        for token in split_data:
            token = token.strip()
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
    distance_to_center = math.sqrt((first_pos[0] - origin[0]) ** 2 +
                                   (first_pos[1] - origin[1]) ** 2 +
                                   (first_pos[2] - origin[2]) ** 2)
    print(f"Distance to center: {distance_to_center:.5}")
    print()
    print("Get a second set of coordinates")
    second_pos = get_player_pos()
    print(f"Got a second tuple: {second_pos}")
    print(f"It includes: X={second_pos[0]}, Y={second_pos[1]},"
          f" Z={second_pos[2]}")
    distance_to_first = math.sqrt((second_pos[0] - first_pos[0]) ** 2 +
                                  (second_pos[1] - first_pos[1]) ** 2 +
                                  (second_pos[2] - first_pos[2]) ** 2)
    print(f"Distance between the 2 sets of coordinates: "
          f"{distance_to_first:.4f}")


if __name__ == "__main__":
    main()
