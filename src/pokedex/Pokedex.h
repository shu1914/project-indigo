/**
 * @file Pokedex.h
 * @brief Implements the IPokedex interface.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef POKEDEX_H
#define POKEDEX_H

#include "IPokedex.h"

namespace indigo
{

class Pokedex : public IPokedex
{

public:

    bool initialize() override;

    std::string getPokemonName(
        uint16_t pokemonId) override;

    std::vector<Evolution> getNextEvolutions(
        uint16_t pokemonId) const override;

}; // end class Pokedex

} // end namespace indigo

#endif // end POKEDEX_H
