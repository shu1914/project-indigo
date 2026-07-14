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

bool
Pokedex::initialize()
{
    TRACE("Initializing `Pokedex` module." );

    return true;
}

std::string
Pokedex::getPokemonName(
    uint16_t pokemonId)
{
    return "Bulbasaur";
}

std::vector<indigo::Evolution>
indigo::Pokedex::getNextEvolutions(
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

} // end namespace indigo
