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
        Pokemon(1, "Bulbasaur",
            {types::GRASS, types::POISON},
            {abilities::OVERGROW}),

        Pokemon(2, "Ivysaur",
            {types::GRASS, types::POISON},
            {abilities::OVERGROW}),

        Pokemon(3, "Venusaur",
            {types::GRASS, types::POISON},
            {abilities::OVERGROW}),

        Pokemon(4, "Charmander",
            {types::FIRE},
            {abilities::BLAZE}),

        Pokemon(5, "Charmeleon",
            {types::FIRE},
            {abilities::BLAZE}),

        Pokemon(6, "Charizard",
            {types::FIRE, types::FLYING},
            {abilities::BLAZE}),

        Pokemon(7, "Squirtle",
            {types::WATER},
            {abilities::TORRENT}),

        Pokemon(8, "Wartortle",
            {types::WATER},
            {abilities::TORRENT}),

        Pokemon(9, "Blastoise",
            {types::WATER},
            {abilities::TORRENT}),

        Pokemon(10, "Caterpie",
            {types::BUG},
            {abilities::SHIELD_DUST}),

        Pokemon(11, "Metapod",
            {types::BUG},
            {abilities::SHED_SKIN}),

        Pokemon(12, "Butterfree",
            {types::BUG, types::FLYING},
            {abilities::COMPOUND_EYES}),

        Pokemon(13, "Weedle",
            {types::BUG, types::POISON},
            {abilities::SHIELD_DUST}),

        Pokemon(14, "Kakuna",
            {types::BUG, types::POISON},
            {abilities::SHED_SKIN}),

        Pokemon(15, "Beedrill",
            {types::BUG, types::POISON},
            {abilities::SWARM}),

        Pokemon(16, "Pidgey",
            {types::NORMAL, types::FLYING},
            {abilities::KEEN_EYE}),

        Pokemon(17, "Pidgeotto",
            {types::NORMAL, types::FLYING},
            {abilities::KEEN_EYE}),

        Pokemon(18, "Pidgeot",
            {types::NORMAL, types::FLYING},
            {abilities::KEEN_EYE}),

        Pokemon(19, "Rattata",
            {types::NORMAL},
            {abilities::RUN_AWAY}),

        Pokemon(20, "Raticate",
            {types::NORMAL},
            {abilities::RUN_AWAY}),

        Pokemon(21, "Spearow",
            {types::NORMAL, types::FLYING},
            {abilities::KEEN_EYE}),

        Pokemon(22, "Fearow",
            {types::NORMAL, types::FLYING},
            {abilities::KEEN_EYE}),

        Pokemon(23, "Ekans",
            {types::POISON},
            {abilities::INTIMIDATE}),

        Pokemon(24, "Arbok",
            {types::POISON},
            {abilities::INTIMIDATE}),

        Pokemon(25, "Pikachu",
            {types::ELECTRIC},
            {abilities::STATIC}),

        Pokemon(26, "Raichu",
            {types::ELECTRIC},
            {abilities::STATIC}),

        Pokemon(27, "Sandshrew",
            {types::GROUND},
            {abilities::SAND_VEIL}),

        Pokemon(28, "Sandslash",
            {types::GROUND},
            {abilities::SAND_VEIL}),

        Pokemon(29, "Nidoran♀",
            {types::POISON},
            {abilities::POISON_POINT}),

        Pokemon(30, "Nidorina",
            {types::POISON},
            {abilities::POISON_POINT}),

        Pokemon(31, "Nidoqueen",
            {types::POISON, types::GROUND},
            {abilities::POISON_POINT}),

        Pokemon(32, "Nidoran♂",
            {types::POISON},
            {abilities::POISON_POINT}),

        Pokemon(33, "Nidorino",
            {types::POISON},
            {abilities::POISON_POINT}),

        Pokemon(34, "Nidoking",
            {types::POISON, types::GROUND},
            {abilities::POISON_POINT}),
    };

    return pokemons;
}

} // end namespace indigo
