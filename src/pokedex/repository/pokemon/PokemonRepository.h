/**
 * @file PokemonRepository.h
 * @brief Pokemon repository class
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-14
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef POKEMON_REPOSITORY_H
#define POKEMON_REPOSITORY_H

#include "IPokemonRepository.h"

namespace indigo
{

class PokemonRepository : public IPokemonRepository
{

public:

    Pokemon get(
        uint16_t pokemonId) const override;

};

}

#endif // end POKEMON_REPOSITORY_H
