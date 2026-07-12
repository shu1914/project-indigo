# Versioning Workflow

## Overview

This project follows Semantic Versioning.

Format:

MAJOR.MINOR.PATCH

Example:

v1.2.3

---

## Milestone Mapping

| Milestone | Version |
|-----------|---------|
| Milestone 0 | v0.1.0 |
| Milestone 1 | v0.2.0 |
| Milestone 2 | v0.3.0 |
| ... | ... |
| Milestone 9 | v1.0.0 |

---

## Release Process

A version tag is created only after completing a milestone.

Process:

1. Complete milestone checklist
2. Update CHANGELOG.md
3. Commit changelog
4. Create git tag
5. Push tag

Example:

```bash
git tag -a v0.1.0 -m "Milestone 0: Project Setup"
```

---

## Commit vs Tag

Commits:
- Development history
- Small changes
- Bug fixes
- Refactoring

Tags:
- Milestone completion
- Release points
- Stable checkpoints