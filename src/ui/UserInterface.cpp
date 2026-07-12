/**
 * @file Platform.cpp
 * @brief Implements the UserInterface class.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include <iostream>

#include "UserInterface.h"

namespace indigo
{

UserInterface::UserInterface(
    IPokedex& pokedex)
    : _pokedex(pokedex)
{
}

bool
UserInterface::initialize()
{
    std::cout << "Initializing `UserInterface` module." << std::endl;

    _pokedex.initialize();

    std::cout << "Pokemon #1 is " << _pokedex.getPokemonName(1) << std::endl;

    return true;
}

void
UserInterface::shutdown()
{
    std::cout << "Shutting `UserInterface` module down." << std::endl;
}

} // end namespace indigo
