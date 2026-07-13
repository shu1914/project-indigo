/**
 * @file Ability.cpp
 * @brief Ability implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include "Ability.h"

namespace indigo
{

Ability::Ability(
    uint32_t id,
    const std::string& name)
    : _id(id),
      _name(name)
{
}

uint32_t
Ability::id() const
{
    return _id;
}

const std::string&
Ability::name() const
{
    return _name;
}

} // end namespace indigo
