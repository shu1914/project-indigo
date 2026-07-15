/**
 * @file Pokemon.cpp
 * @brief Implementation of the Pokemon model class
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include "Pokemon.h"

namespace indigo
{

Pokemon::Pokemon(
    uint32_t id,
    const std::string& name)
    : _id(id)
    , _name(name)
{
}

Pokemon::Pokemon(
    uint32_t id,
    const std::string& name,
    std::initializer_list<Type> types,
    std::initializer_list<Ability> abilities)
    : Pokemon(id, name)
{
    _types.insert(_types.end(), types.begin(), types.end());
    _abilities.insert(_abilities.end(), abilities.begin(), abilities.end());
}

uint32_t
Pokemon::id() const
{
    return _id;
}

const std::string&
Pokemon::name() const
{
    return _name;
}

void
Pokemon::addType(
    const Type& type)
{
    _types.push_back(type);
}

void
Pokemon::addAbility(
    const Ability& type)
{
    _abilities.push_back(type);
}

const std::vector<Type>&
Pokemon::types() const
{
    return _types;
}

const std::vector<Ability>&
Pokemon::abilities() const
{
    return _abilities;
}

} // end namespace indigo
