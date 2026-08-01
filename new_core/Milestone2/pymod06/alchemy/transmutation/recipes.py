"""alchemy/transmutation/recipes.py"""

from alchemy.elements import create_air
from ..potions import strength_potion
from elements import create_fire


def lead_to_gold() -> str:
    """Transmute lead into gold."""
    air = create_air()
    potion = strength_potion()
    fire = create_fire()

    return (
        f"Recipe transmuting Lead to Gold: brew '{air}' "
        f"and '{potion}' mixed with '{fire}'"
    )
