/**
 * @file IPokemonRepository.h
 * @brief Pokemon repository interface
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-14
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef I_POKEMON_REPOSITORY_H
#define I_POKEMON_REPOSITORY_H

#include "../../model/pokemon/Pokemon.h"

namespace indigo
{

class IPokemonRepository
{

public:

    virtual ~IPokemonRepository() = default;

    virtual Pokemon get(
        uint16_t pokemonId) const = 0;
};

}

#endif // end I_POKEMON_REPOSITORY_H