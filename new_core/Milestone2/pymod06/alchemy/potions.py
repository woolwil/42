"""alchemy/potions.py"""

import alchemy.elements as elements
import elements as root_el


def healing_potion() -> str:
    """Brew healing potion."""
    earth = elements.create_earth()
    air = elements.create_air()
    return f"Healing potion brewed with '{earth}' and '{air}'"


def strength_potion() -> str:
    """Brew strength potion."""
    fire = root_el.create_fire()
    water = root_el.create_water()
    return f"Strength potion brewed with '{fire}' and '{water}'"
