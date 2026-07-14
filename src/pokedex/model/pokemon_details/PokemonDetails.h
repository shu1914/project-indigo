/**
 * @file PokemonDetails.h
 * @brief Pokemon detail model class header
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-14
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef POKEMON_DETAILS_H
#define POKEMON_DETAILS_H

#include <vector>

#include "../pokemon/Pokemon.h"
#include "../evolution/Evolution.h"

namespace indigo
{

class PokemonDetails
{

public:
    PokemonDetails(
        const Pokemon& pokemon,
        const std::vector<Evolution>& evolutions);

    const Pokemon& pokemon() const;

    const std::vector<Evolution>& evolutions() const;

private:
    Pokemon _pokemon;
    std::vector<Evolution> _evolutions;
};

}

#endif // end POKEMON_DETAILS_H
