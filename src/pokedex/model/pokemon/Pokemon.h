/**
 * @file Pokemon.h
 * @brief Pokemon model header
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef POKEMON_H
#define POKEMON_H

#include <vector>

#include "../type/Type.h"

namespace indigo
{

class Pokemon
{
public:
    Pokemon(
        uint32_t id,
        const std::string& name);

    uint32_t id() const;
    const std::string& name() const;

    void addType(const Type& type);

    const std::vector<Type>& types() const;

private:
    uint32_t _id;
    std::string _name;

    std::vector<Type> _types;

}; // end class Pokemon

} // end namespace indigo

#endif // end POKEMON_H
