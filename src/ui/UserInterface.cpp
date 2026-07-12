/**
 * @file Platform.cpp
 * @brief Implements the UserInterface class.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include "UserInterface.h"
#include "common/logger/LogMacro.h"

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
    TRACE("Initializing `UserInterface` module." );

    _pokedex.initialize();

    DEBUG("Pokemon #1 is {}", _pokedex.getPokemonName(1));

    return true;
}

void
UserInterface::shutdown()
{
    TRACE("Shutting `UserInterface` module down.");
}

} // end namespace indigo
