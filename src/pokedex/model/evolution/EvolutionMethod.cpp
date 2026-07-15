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

EvolutionMethod
EvolutionMethod::level(uint32_t level)
{
    EvolutionMethod method;

    method._type = EvolutionMethodType::LEVEL;
    method._level = level;

    return method;
}

EvolutionMethod
EvolutionMethod::item(Item item)
{
    EvolutionMethod method;

    method._type = EvolutionMethodType::ITEM;
    method._item = item;

    return method;
}

EvolutionMethod
EvolutionMethod::trade()
{
    EvolutionMethod method;

    method._type = EvolutionMethodType::TRADE;

    return method;
}

EvolutionMethod
EvolutionMethod::friendship()
{
    EvolutionMethod method;

    method._type = EvolutionMethodType::FRIENDSHIP;

    return method;
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

Item
EvolutionMethod::item() const
{
    return _item;
}

}
