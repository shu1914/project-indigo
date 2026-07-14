/**
 * @file PokemonRepository.cpp
 * @brief Pokemon repository class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-14
 * 
 * @copyright Copyright (c) 2026
 */

#include "PokemonRepository.h"
#include "../../data/Pokemons.h"

namespace indigo
{

Pokemon
PokemonRepository::get(
    uint16_t pokemonId) const
{
    for (const Pokemon& pokemon : Pokemons::all())
    {
        if (pokemon.id() == pokemonId)
        {
            return pokemon;
        }
    }

    return Pokemon(
        0,
        "None");
}

} // end namespace indigo
