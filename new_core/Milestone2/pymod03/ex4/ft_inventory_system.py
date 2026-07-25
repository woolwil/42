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
        except ValueError as error:
            print(f"Quantity error for '{item}': {error}")
            continue

        inventory[item] = qty

    if not inventory:
        print("Error: No valid inventory items provided.")
        return

    print(f"Got inventory: {inventory}")

    item_list = list(inventory.keys())
    print(f"Item list: {item_list}")

    total_qty = sum(inventory.values())
    print(f"Total quantity of the {len(inventory)} items: {total_qty}")

    for item, quantity in inventory.items():
        print(f"Item {item} represents "
              f"{round(quantity / total_qty * 100, 1)}%")

    max_item = max(inventory, key=inventory.__getitem__)
    max_qty = inventory[max_item]
    min_item = min(inventory, key=inventory.__getitem__)
    min_qty = inventory[min_item]

    print(f"Item most abundant: {max_item} with quantity {max_qty}")
    print(f"Item least abundant: {min_item} with quantity {min_qty}")

    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    main()
