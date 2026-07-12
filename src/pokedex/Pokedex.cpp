/**
 * @file Pokedex.cpp
 * @brief Implements the Pokedex class.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include <iostream>

#include "Pokedex.h"

namespace indigo
{

bool
Pokedex::initialize()
{
    std::cout << "Initializing `Pokedex` module." << std::endl;

    return true;
}

std::string
Pokedex::getPokemonName(
    int id)
{
    return "Bulbasaur";
}

} // end namespace indigo
