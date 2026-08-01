"""alchemy/grimoire/light_spellbook.py"""

from .light_validator import validate_ingredients


def light_spell_allowed_ingredients() -> list[str]:
    """Return allowed ingredients for light magic."""
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    """Record a light magic spell if ingredients are valid."""
    validation = validate_ingredients(ingredients)
    return f"Spell recorded: {spell_name} ({validation})"
