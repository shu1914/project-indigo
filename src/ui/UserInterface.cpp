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

    // TODO: Remove this later. For verification only
    PokemonDetails details = _pokedex.getPokemonDetails(1);
    
    DEBUG("Pokemon #1 is {} with a typing of {}.",
        details.pokemon().name(),
        details.pokemon().types()[0].name());

    DEBUG("It will evolve to {} at level {}",
        details.evolutions()[0].to(),
        details.evolutions()[0].method().level());

    return true;
}

void
UserInterface::shutdown()
{
    TRACE("Shutting `UserInterface` module down.");
}

} // end namespace indigo
