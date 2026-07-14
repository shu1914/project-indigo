/**
 * @file EvolutionMethod.cpp
 * @brief Evolution method implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include "EvolutionMethod.h"

namespace indigo
{

EvolutionMethod::EvolutionMethod(
    EvolutionMethodType type,
    uint32_t  level)
    : _type(type)
    , _level(level)
{
}

EvolutionMethodType
EvolutionMethod::type() const
{
    return _type;
}

uint32_t 
EvolutionMethod::level() const
{
    return _level;
}

}
