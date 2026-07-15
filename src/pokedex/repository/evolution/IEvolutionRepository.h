/**
 * @file IEvolutionRepository.h
 * @brief Evolution repository interface
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-15
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef I_EVOLUTION_REPOSITORY_H
#define I_EVOLUTION_REPOSITORY_H

#include <vector>
#include "../../model/evolution/Evolution.h"

namespace indigo
{

class IEvolutionRepository
{

public:

    virtual ~IEvolutionRepository() = default;

    virtual std::vector<Evolution> get(
        uint32_t pokemonId) const = 0;

};

}

#endif // end I_EVOLUTION_REPOSITORY_H