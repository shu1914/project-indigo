/**
 * @file TempScreen.cpp
 * @brief Temp screen class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-19
 *
 * @copyright Copyright (c) 2026
 */

#include "TempScreen.h"
#include "common/logger/LogMacro.h"
#include "../../widgets/WidgetBuilder.h"

namespace indigo
{

TempScreen::TempScreen(
    IPokedex& pokedex)
    :_pokedex(pokedex)
{
}

void
TempScreen::onCreate()
{
    _screenObj = lv_obj_create(nullptr);
    lv_obj_set_style_bg_color(_screenObj, lv_color_hex(0xFF8888), 0);


    // Logic below copied from UserInterface::initialize
    // These are just verification and not actual implementation.
    // This may contain incorrect codes but please ignore.
    // TODO: Remove this once actual screen is implemented

    WidgetBuilder builder;

    // Screen or dialog owns WidgetStyle so its their responsibility
    // to cleanup WidgetStyle. For now, this is just for verification. 
    _textStyle.textColor(lv_color_hex(0xFF0000));

    // TODO: Data testing. Move this later to unit tests
    std::optional<PokemonDetails> details = _pokedex.getPokemonDetails(1);

    if (details.has_value())
    {
        const auto& pokemon = details.value().pokemon();

        std::string pokemonStr = fmt::format("Pokemon #1 is {} with no typing.",
            pokemon.name());
        if (!pokemon.types().empty())
        {
            pokemonStr = fmt::format("Pokemon #1 is {} with a typing of {}.",
                pokemon.name(),
                pokemon.types().front().name());
        }

        builder.label(_screenObj)
                .pos(0, 0)
                .align(LV_ALIGN_CENTER)
                .text(pokemonStr)
                .style(_textStyle)
                .build();

        std::string evolutionStr = "It has no evolutions.";

        if (!details.value().evolutions().empty())
        {
            const auto& evolution = details.value().evolutions().front();
            const auto method = evolution.method();

            // TODO: For now, print the pokemon ID value rather than name. Refactor later
            switch (method.type())
            {
                case EvolutionMethodType::LEVEL:
                {
                    evolutionStr = fmt::format("It will evolve to {} at level {}.",
                        evolution.to(),
                        evolution.method().level());
                }
                break;
                case EvolutionMethodType::ITEM:
                {
                    evolutionStr = fmt::format("It will evolve to {} with {}.",
                        evolution.to(),
                        // TODO: Print the actual item name later. For now, just print the num value.
                        static_cast<uint32_t>(evolution.method().item()));
                }
                break;
                case EvolutionMethodType::TRADE:
                {
                    evolutionStr = fmt::format("It will evolve to {} with trade.",
                        evolution.to());
                }
                break;
                case EvolutionMethodType::FRIENDSHIP:
                {
                    evolutionStr = fmt::format("It will evolve to {} through friendship.",
                        evolution.to());
                }
                break;
                default:
                {
                    evolutionStr = fmt::format("It will evolve to {} with unknown method.",
                        evolution.to());
                }
                break;
            }
        }
        builder.label(_screenObj)
                .pos(0, 20)
                .align(LV_ALIGN_CENTER)
                .text(evolutionStr)
                .style(_textStyle)
                .build();
    }
    else
    {
        DEBUG("Pokemon #1 not found.");
    }
}

}
