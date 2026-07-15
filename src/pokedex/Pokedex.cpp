/**
 * @file Pokedex.cpp
 * @brief Implements the Pokedex class.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include "Pokedex.h"
#include "common/logger/LogMacro.h"
#include "model/pokemon/Pokemon.h"
#include "data/Evolutions.h"

namespace indigo
{

Pokedex::Pokedex(
    IPokemonRepository& pokemonRepository,
    IEvolutionRepository& evolutionRepository)
    : _pokemonRepository(pokemonRepository)
    , _evolutionRepository(evolutionRepository)
{
}

bool
Pokedex::initialize()
{
    TRACE("Initializing `Pokedex` module." );

    return true;
}

std::optional<PokemonDetails>
Pokedex::getPokemonDetails(
    uint32_t  pokemonId) const
{
    std::optional<Pokemon> pokemon = _pokemonRepository.get(pokemonId);

    if (!pokemon.has_value())
    {
        return std::nullopt;
    }

    // can return pokemon with 0 evolution
    // must be handled where `getPokemonDetails` is called
    return PokemonDetails(
        pokemon.value(),
        _evolutionRepository.get(pokemonId));
}

} // end namespace indigo
