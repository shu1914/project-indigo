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

const std::vector<Type>&
Pokemon::types() const
{
    return _types;
}

} // end namespace indigo
