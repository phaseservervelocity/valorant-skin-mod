"""Tests for SkinManager."""

import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "src"))

from skin_manager import SkinManager


def test_skins_exist():
    mgr = SkinManager()
    all_skins = mgr.list_all()
    assert isinstance(all_skins, dict)


def test_apply_nonexistent_skin():
    mgr = SkinManager()
    result = mgr.apply_skin("Vandal", "NonexistentSkin")
    assert result is False


def test_get_available_skins():
    mgr = SkinManager()
    # If no data file, should be empty
    skins = mgr.get_available_skins("Phantom")
    assert isinstance(skins, list)