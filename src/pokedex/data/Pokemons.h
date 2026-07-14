/**
 * @file Pokemons.h
 * @brief Pokemon data
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-15
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef POKEMONS_H
#define POKEMONS_H

#include <vector>

#include "../model/pokemon/Pokemon.h"

namespace indigo
{

class Pokemons
{

public:

    static const std::vector<Pokemon>& all();

}; // end class Pokemons

} // end namespace indigo

#endif // end POKEMONS_H
