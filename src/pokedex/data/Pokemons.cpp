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
        []()
        {
            Pokemon pokemon(
                1,
                "Bulbasaur");

            pokemon.addType(types::GRASS);
            pokemon.addType(types::POISON);

            pokemon.addAbility(abilities::OVERGROW);

            return pokemon;
        }(),

        []()
        {
            Pokemon pokemon(
                2,
                "Ivysaur");

            pokemon.addType(types::GRASS);
            pokemon.addType(types::POISON);

            pokemon.addAbility(abilities::OVERGROW);

            return pokemon;
        }(),

        []()
        {
            Pokemon pokemon(
                3,
                "Venusaur");

            pokemon.addType(types::GRASS);
            pokemon.addType(types::POISON);

            pokemon.addAbility(abilities::OVERGROW);

            return pokemon;
        }()
    };

    return pokemons;
}

} // end namespace indigo
