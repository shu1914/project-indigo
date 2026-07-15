/**
 * @file EvolutionRepository.h
 * @brief Evolution repository class header
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-15
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef EVOLUTION_REPOSITORY_H
#define EVOLUTION_REPOSITORY_H

#include "IEvolutionRepository.h"

namespace indigo
{

class EvolutionRepository : public IEvolutionRepository
{

public:

    std::vector<Evolution> get(
        uint32_t pokemonId) const override;

};

}


#endif // end EVOLUTION_REPOSITORY_H