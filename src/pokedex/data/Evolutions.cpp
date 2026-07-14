/**
 * @file Evolutions.cpp
 * @brief Evolutions data
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include "Evolutions.h"

namespace
{

// temporary
constexpr uint32_t  BULBASAUR = 1;
constexpr uint32_t  IVYSAUR   = 2;
constexpr uint32_t  VENUSAUR  = 3;

} // anonymous namespace

namespace indigo
{

const std::vector<Evolution>&
Evolutions::all()
{
    static const std::vector<Evolution> evolutions =
    {
        Evolution(
            BULBASAUR,
            IVYSAUR,
            EvolutionMethod(
                EvolutionMethodType::LEVEL,
                16)),

        Evolution(
            IVYSAUR,
            VENUSAUR,
            EvolutionMethod(
                EvolutionMethodType::LEVEL,
                32))
    };

    return evolutions;
}

} // end namespace indigo