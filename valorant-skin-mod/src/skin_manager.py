"""Manages weapon skin data and local modifications."""

import json
import os
from typing import Dict, List, Optional

SKIN_DB_PATH = os.path.join(os.path.dirname(__file__), "..", "data", "skins.json")


class SkinManager:
    """Handles loading and applying skin configurations."""

    def __init__(self):
        self._skins: Dict[str, Dict] = {}
        self._load_skins()

    def _load_skins(self):
        if os.path.exists(SKIN_DB_PATH):
            with open(SKIN_DB_PATH, "r") as f:
                self._skins = json.load(f)
        else:
            self._skins = {}

    def get_available_skins(self, weapon: str) -> List[str]:
        """Return list of skin names for a given weapon."""
        return list(self._skins.get(weapon, {}).keys())

    def apply_skin(self, weapon: str, skin_name: str) -> bool:
        """Apply a skin (placeholder — would modify game files)."""
        if weapon in self._skins and skin_name in self._skins[weapon]:
            print(f"Skin '{skin_name}' applied to {weapon}.")
            return True
        print(f"Skin '{skin_name}' not found for {weapon}.")
        return False

    def list_all(self) -> Dict[str, List[str]]:
        """Return all weapons and their skins."""
        return {w: list(s.keys()) for w, s in self._skins.items()}