# Changelog

> [!NOTE]
> All notable changes to this project will be documented in this file.
>
> This changelog follows the principles of [Keep a Changelog](https://keepachangelog.com/en/1.1.0/) and [Semantic Versioning](https://semver.org/).

## [0.3.0] 2026-07-17

### Added
- Added domain models
  - `Pokemon`
  - `Type`
  - `Ability`
  - `Evolution`
  - `PokemonDetails`
- Added repositories
  - `PokemonRepository`
  - `EvolutionRepository`
- Added sample data to the domain models added.
- Added unit tests

### Changed
- Modified `Pokedex` to be injected with the repositories added

### Fixed
- N/A

## [0.2.0] 2026-07-13

### Added
- Base platform module (skeleton)
- Base ui module (skeleton)
- Based pokdex module (skeleton)
- Configuration handling
- Basic logger
- Basic error handling

### Changed
- `Application` module now depends on the following modules:
  - `Configuration`
  - `Platform`
  - `UserInterface`
- Updated source code to use new log macros

### Fixed
- N/A

## [0.1.0] 2026-07-12

### Added
- Initial project structure
- CMake build system
- Application module
- Basic application entry point
- Project documentation
- Initial versioning workflow

### Changed
- N/A

### Fixed
- N/A