/**
 * @file EvolutionMethod.cpp
 * @brief Evolution method implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include <stdexcept>

#include "EvolutionMethod.h"

namespace indigo
{

EvolutionMethod
EvolutionMethod::level(uint32_t level)
{
    EvolutionMethod method(EvolutionMethodType::LEVEL);
    method._level = level;

    return method;
}

EvolutionMethod
EvolutionMethod::item(Item item)
{
    if (item == Item::NONE)
    {
        throw std::invalid_argument("Item evolution requires a valid item.");
    }

    EvolutionMethod method(EvolutionMethodType::ITEM);
    method._item = item;

    return method;
}

EvolutionMethod
EvolutionMethod::trade()
{
    return EvolutionMethod(EvolutionMethodType::TRADE);
}

EvolutionMethod
EvolutionMethod::friendship()
{
    return EvolutionMethod(EvolutionMethodType::FRIENDSHIP);
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
