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
#include "data/Types.h"
#include "data/Abilities.h"
#include "data/Evolutions.h"

namespace indigo
{

Pokedex::Pokedex(
    IPokemonRepository& pokemonRepository)
    : _pokemonRepository(pokemonRepository)
{
}

bool
Pokedex::initialize()
{
    TRACE("Initializing `Pokedex` module." );

    return true;
}

Pokemon
Pokedex::getPokemon(
    uint16_t pokemonId) const
{
    Pokemon pokemon = _pokemonRepository.get(pokemonId);

    return pokemon;
}

std::vector<indigo::Evolution>
Pokedex::getNextEvolutions(
    uint16_t pokemonId) const
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

PokemonDetails
Pokedex::getPokemonDetails(
    uint16_t pokemonId) const
{
    return PokemonDetails(
        getPokemon(pokemonId),
        getNextEvolutions(pokemonId));
}

} // end namespace indigo
