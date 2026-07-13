/**
 * @file Type.cpp
 * @brief Type implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include "Type.h"

namespace indigo
{

Type::Type(
    uint32_t id,
    const std::string& name)
    : _id(id),
      _name(name)
{
}

uint32_t
Type::id() const
{
    return _id;
}

const std::string&
Type::name() const
{
    return _name;
}

} // end namespace indigo
