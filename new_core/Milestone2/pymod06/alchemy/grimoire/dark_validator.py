"""alchemy/grimoire/dark_validator.py"""

from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    """Validate ingredients for dark magic."""
    allowed = dark_spell_allowed_ingredients()
    ingredients_lower = ingredients.lower()
    is_valid = any(item.lower() in ingredients_lower for item in allowed)
    status = "VALID" if is_valid else "INVALID"
    return f"{ingredients} - {status}"
