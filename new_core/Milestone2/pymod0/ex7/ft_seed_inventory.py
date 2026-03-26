def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    if seed_type == "tomato" and unit == "packets":
        print(f"Tomato seeds: {quantity} {unit} available")
    elif seed_type == "carrot" and unit == "grams":
        print(f"Carrot seeds: {quantity} {unit} total")
    elif seed_type == "lettuce" and unit == "area":
        print(f"Lettuce seeds: covers {quantity} square meters")
    else:
        print("Unknown unit type")
