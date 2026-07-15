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
#include "../ability/Ability.h"

namespace indigo
{

class Pokemon
{
public:
    Pokemon(
        uint32_t id,
        const std::string& name);

    Pokemon(
        uint32_t id,
        const std::string& name,
        std::initializer_list<Type> types,
        std::initializer_list<Ability> abilities);

    uint32_t id() const;
    const std::string& name() const;

    void addType(const Type& type);
    void addAbility(const Ability& type);

    const std::vector<Type>& types() const;
    const std::vector<Ability>& abilities() const;

private:
    uint32_t _id;
    std::string _name;

    std::vector<Type> _types;
    std::vector<Ability> _abilities;

}; // end class Pokemon

} // end namespace indigo

#endif // end POKEMON_H
