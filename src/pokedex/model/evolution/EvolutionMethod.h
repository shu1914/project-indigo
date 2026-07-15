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
    LEVEL,
    ITEM,
    TRADE,
    FRIENDSHIP
};

enum class Item
{
    NONE,

    MOON_STONE,
    THUNDER_STONE,
    FIRE_STONE,
    WATER_STONE,
    LEAF_STONE
};

class EvolutionMethod
{
public:
    static EvolutionMethod level(uint32_t level);
    static EvolutionMethod item(Item item);
    static EvolutionMethod trade();
    static EvolutionMethod friendship();

    EvolutionMethodType type() const;
    uint32_t level() const;
    Item item() const;

private:
    explicit EvolutionMethod(EvolutionMethodType type)
        : _type(type)
    {
    }

    EvolutionMethodType _type;

    uint32_t _level = 0;
    Item _item = Item::NONE;
};

}

#endif // end EVOLUTION_METHOD_H
