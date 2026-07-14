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
#include "repository/pokemon/IPokemonRepository.h"

namespace indigo
{

class Pokedex : public IPokedex
{

public:

    explicit Pokedex(
        IPokemonRepository& pokemonRepository);

    bool initialize() override;

    Pokemon getPokemon(
        uint32_t  pokemonId) const override;

    std::vector<Evolution> getNextEvolutions(
        uint32_t  pokemonId) const override;

    PokemonDetails getPokemonDetails(
        uint32_t  pokemonId) const override;

private:
    
    IPokemonRepository& _pokemonRepository;

}; // end class Pokedex

} // end namespace indigo

#endif // end POKEDEX_H
