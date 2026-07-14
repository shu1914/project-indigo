/**
 * @file IPokedex.h
 * @brief Defines the pokedex abstraction.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef I_POKEDEX_H
#define I_POKEDEX_H

#include <string>
#include <vector>

#include "model/pokemon/Pokemon.h"
#include "model/evolution/Evolution.h"
#include "model/pokemon_details/PokemonDetails.h"

namespace indigo
{

class IPokedex
{

public:

    virtual ~IPokedex() {}

    virtual bool initialize() = 0;

    virtual Pokemon getPokemon(
        uint16_t pokemonId) const = 0;

    virtual std::vector<Evolution> getNextEvolutions(
        uint16_t pokemonId) const = 0;

    virtual PokemonDetails getPokemonDetails(
        uint16_t pokemonId) const = 0;

}; // end class IPokedex

} // end namespace indigo

#endif // end I_POKEDEX_H
