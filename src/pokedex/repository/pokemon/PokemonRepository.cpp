/**
 * @file PokemonRepository.cpp
 * @brief Pokemon repository class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-14
 * 
 * @copyright Copyright (c) 2026
 */

#include "PokemonRepository.h"

namespace indigo
{

Pokemon
PokemonRepository::get(
    uint16_t pokemonId) const
{
    // TODO: Remove once data are populated
    return Pokemon(
        1,
        "Bulbasaur");
}

} // end namespace indigo
