# Valorant Skin Mod

A proof-of-concept skin modification tool for Valorant.

## Installation

```bash
pip install -r requirements.txt
```

## Usage

```python
from src.skin_manager import SkinManager

mgr = SkinManager()
print(mgr.list_all())
mgr.apply_skin("Vandal", "Prime")
```

## Testing

```bash
pytest tests/
```

**Disclaimer:** This is for educational purposes only. Modifying game files may violate terms of service.