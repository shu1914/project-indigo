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

    std::optional<PokemonDetails> details = _pokedex.getPokemonDetails(1);

    if (details.has_value())
    {
        const auto& pokemon = details.value().pokemon();

        if (!pokemon.types().empty()) {
            DEBUG("Pokemon #1 is {} with a typing of {}.",
                pokemon.name(),
                pokemon.types().front().name());
        } else {
            DEBUG("Pokemon #1 is {} with no typing.",
                pokemon.name());
        }

        if (!details.value().evolutions().empty()) {
            const auto& evolution = details.value().evolutions().front();

            DEBUG("It will evolve to {} at level {}.",
                evolution.to(),
                evolution.method().level());
        } else {
            DEBUG("It has no evolutions.");
        }
    }
    else
    {
        DEBUG("Pokemon #1 not found.");
    }

    return true;
}

void
UserInterface::shutdown()
{
    TRACE("Shutting `UserInterface` module down.");
}

} // end namespace indigo
