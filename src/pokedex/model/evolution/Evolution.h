/**
 * @file Evolution.h
 * @brief Evolution model
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef EVOLUTION_H
#define EVOLUTION_H

#include <cstdint>

#include "EvolutionMethod.h"

namespace indigo
{

class Evolution
{
public:
    Evolution(
        uint32_t  from,
        uint32_t  to,
        const EvolutionMethod& method);

    uint32_t  from() const;
    
    uint32_t  to() const;

    const EvolutionMethod method() const;

private:
    uint32_t  _from;
    uint32_t  _to;
    const EvolutionMethod _method;

};

}

#endif //end EVOLUTION_H
