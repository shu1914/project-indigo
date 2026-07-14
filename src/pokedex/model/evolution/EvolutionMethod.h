/**
 * @file EvolutionMethod.h
 * @brief Evolution Method
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef EVOLUTION_METHOD_H
#define EVOLUTION_METHOD_H

#include <cstdint>

namespace indigo
{

enum class EvolutionMethodType
{
    LEVEL
};

class EvolutionMethod
{
public:
    EvolutionMethod(
        EvolutionMethodType type,
        uint16_t level);

    EvolutionMethodType type() const;
    uint16_t level() const;

private:
    EvolutionMethodType _type;
    uint16_t _level;
};

}

#endif // end EVOLUTION_METHOD_H
