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

std::optional<Pokemon>
Pokedex::getPokemon(
    uint32_t  pokemonId) const
{
    return _pokemonRepository.get(pokemonId);
}

std::vector<indigo::Evolution>
Pokedex::getNextEvolutions(
    uint32_t  pokemonId) const
{
    std::vector<Evolution> evolutions;

    for (const Evolution& evolution : Evolutions::all())
    {
        if (evolution.from() == pokemonId)
        {
            evolutions.push_back(evolution);
        }
    }

    return evolutions;
}

std::optional<PokemonDetails>
Pokedex::getPokemonDetails(
    uint32_t  pokemonId) const
{
    std::optional<Pokemon> pokemon = getPokemon(pokemonId);

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
