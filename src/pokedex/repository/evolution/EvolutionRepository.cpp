/**
 * @file EvolutionRepository.cpp
 * @brief Evolution repository class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-15
 * 
 * @copyright Copyright (c) 2026
 */

#include "EvolutionRepository.h"
#include "../../data/Evolutions.h"

namespace indigo
{

std::vector<Evolution>
EvolutionRepository::get(
    uint32_t pokemonId) const
{
    std::vector<Evolution> evolutions;

    for (const Evolution& evolution : Evolutions::all())
    {
        if (evolution.from() == pokemonId)
        {
            evolutions.push_back(evolution);
        }
    }

    return evolutions;
}

}
