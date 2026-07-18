/**
 * @file Platform.cpp
 * @brief Implements the UserInterface class.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include <lvgl.h>

#include "UserInterface.h"
#include "common/logger/LogMacro.h"

#include "widgets/WidgetBuilder.h"

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

    WidgetBuilder builder;

    _pokedex.initialize();

    // TODO: Data testing. Move this later to unit tests
    std::optional<PokemonDetails> details = _pokedex.getPokemonDetails(1);

    if (details.has_value())
    {
        const auto& pokemon = details.value().pokemon();

        if (!pokemon.types().empty())
        {
            DEBUG("Pokemon #1 is {} with a typing of {}.",
                pokemon.name(),
                pokemon.types().front().name());

            // TODO: Remove this along with other debug logs. This is just for verification.
            builder.label(lv_scr_act())
                    .pos(0,0)
                    .align(LV_ALIGN_CENTER)
                    .text("Pokemon #1 is {} with a typing of {}.",
                        pokemon.name(),
                        pokemon.types().front().name())
                    .build();
        }
        else
        {
            DEBUG("Pokemon #1 is {} with no typing.",
                pokemon.name());
        }

        if (!details.value().evolutions().empty())
        {
            const auto& evolution = details.value().evolutions().front();
            const auto method = evolution.method();

            // TODO: For now, print the pokemon ID value rather than name. Refactor later
            switch (method.type())
            {
                case EvolutionMethodType::LEVEL:
                {
                    DEBUG("It will evolve to {} at level {}.",
                        evolution.to(),
                        evolution.method().level());
                }
                break;
                case EvolutionMethodType::ITEM:
                {
                    DEBUG("It will evolve to {} with {}.",
                        evolution.to(),
                        // TODO: Print the actual item name later. For now, just print the num value.
                        static_cast<uint32_t>(evolution.method().item()));
                }
                break;
                case EvolutionMethodType::TRADE:
                {
                    DEBUG("It will evolve to {} with trade.",
                        evolution.to());
                }
                break;
                case EvolutionMethodType::FRIENDSHIP:
                {
                    DEBUG("It will evolve to {} through friendship.",
                        evolution.to());
                }
                break;
                default:
                {
                    DEBUG("It will evolve to {} with unknown method.",
                        evolution.to());
                }
                break;
            }
        }
        else
        {
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
