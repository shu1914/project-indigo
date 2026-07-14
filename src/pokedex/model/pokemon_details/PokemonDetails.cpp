/**
 * @file PokemonDetails.cpp
 * @brief Implementation of pokemon details model
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-14
 * 
 * @copyright Copyright (c) 2026
 */

#include "PokemonDetails.h"

namespace indigo
{

PokemonDetails::PokemonDetails(
    const Pokemon& pokemon,
    const std::vector<Evolution>& evolutions)
    : _pokemon(pokemon)
    , _evolutions(evolutions)
{
}

const Pokemon&
PokemonDetails::pokemon() const
{
    return _pokemon;
}

const std::vector<Evolution>&
PokemonDetails::evolutions() const
{
    return _evolutions;
}

}
