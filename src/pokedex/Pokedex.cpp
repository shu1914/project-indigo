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
    int id)
{
    return "Bulbasaur";
}

} // end namespace indigo
