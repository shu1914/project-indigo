/**
 * @file Evolution.cpp
 * @brief Evolution implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include "Evolution.h"

namespace indigo
{

Evolution::Evolution(
    uint16_t from,
    uint16_t to,
    const EvolutionMethod& method)
    : _from(from)
    , _to(to)
    , _method(method)
{
}

uint16_t
Evolution::from() const
{
    return _from;
}

uint16_t
Evolution::to() const
{
    return _to;
}

const EvolutionMethod
Evolution::method() const
{
    return _method;
}

} // end namespace indigo
