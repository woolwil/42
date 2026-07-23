#!/usr/bin/env python3

import sys


def main() -> None:
    print("=== Inventory System Analysis ===")

    inventory: dict[str, int] = {}

    for arg in sys.argv[1:]:
        parts = arg.split(':')
        if len(parts) != 2 or not parts[0]:
            print(f"Error - invalid parameter '{arg}'")
            continue

        item = parts[0]
        qty_str = parts[1]

        if item in inventory.keys():
            print(f"Redundant item '{item}' - discarding")
            continue

        try:
            qty = int(qty_str)
        except ValueError as e:
            print(f"Quantity error for '{item}': {e}")
            continue

        inventory[item] = qty

    if not inventory:
        print("Error: No valid inventory items provided.")
        return

    print(f"Got inventory: {inventory}")

    items_list = list(inventory.keys())
    print(f"Item list: {items_list}")

    total_qty = sum(inventory.values())
    print(f"Total quantity of the {len(inventory)} items: {total_qty}")

    for item in inventory.keys():
        qty = inventory[item]
        if total_qty > 0:
            percentage = round((qty / total_qty) * 100, 1)
        else:
            percentage = 0.0
        print(f"Item {item} represents {percentage}%")

    max_item = items_list[0]
    max_qty = inventory[max_item]
    min_item = items_list[0]
    min_qty = inventory[min_item]

    for item in items_list[1:]:
        qty = inventory[item]
        if qty > max_qty:
            max_qty = qty
            max_item = item
        if qty < min_qty:
            min_qty = qty
            min_item = item

    print(f"Item most abundant: {max_item} with quantity {max_qty}")
    print(f"Item least abundant: {min_item} with quantity {min_qty}")

    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    main()