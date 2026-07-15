/**
 * @file Pokemons.cpp
 * @brief Pokemons data class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-15
 * 
 * @copyright Copyright (c) 2026
 */

#include "Pokemons.h"

#include "Abilities.h"
#include "Types.h"

namespace indigo
{

const std::vector<Pokemon>&
Pokemons::all()
{
    static const std::vector<Pokemon> pokemons =
    {
        Pokemon(
            1,
            "Bulbasaur",
            {types::GRASS, types::POISON},
            {abilities::OVERGROW}),

        Pokemon(
            2,
            "Ivysaur",
            {types::GRASS, types::POISON},
            {abilities::OVERGROW}),

        Pokemon(
            3,
            "Venusaur",
            {types::GRASS, types::POISON},
            {abilities::OVERGROW})
    };

    return pokemons;
}

} // end namespace indigo
