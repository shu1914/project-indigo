/**
 * @file Ability.h
 * @brief Pokemon Type model
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */
#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <cstdint>

namespace indigo
{

class Ability
{
public:
    Ability(
        uint32_t id,
        const std::string& name);

    uint32_t id() const;
    const std::string& name() const;

private:
    uint32_t _id;
    std::string _name;
};

}

#endif //end ABILITY_H
