import alchemy.elements as elements
import elements as root_el


def healing_potion() -> str:
    return (f"Healing potion brewed with '[{elements.create_earth()}] and "
            f"'[{elements.create_air()}]'")


def strength_potion() -> str:
    return (f"Strength potion brewed with '[{root_el.create_fire()}]'"
            f" and '[{root_el.create_water()}]'")
