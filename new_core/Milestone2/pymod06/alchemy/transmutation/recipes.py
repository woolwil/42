"""alchemy/transmutation/recipes.py"""

from alchemy.elements import create_air
from ..potions import strength_potion
from elements import create_fire


def lead_to_gold() -> str:
    air = create_air()
    fire = create_fire()
    str_pot = strength_potion()

    return (f"Recipe transmuting Lead to Gold: brew '[{air}]"
            f" and '[{str_pot}]' mixed with '[{fire}]'")
