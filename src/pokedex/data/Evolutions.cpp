/**
 * @file Evolutions.cpp
 * @brief Evolutions data
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include "Evolutions.h"

namespace indigo
{

const std::vector<Evolution>&
Evolutions::all()
{
    // TODO: Refactor this later to something better
    static const std::vector<Evolution> evolutions =
    {
        Evolution(
            1,
            2,
            EvolutionMethod::level(16)),

        Evolution(
            2,
            3,
            EvolutionMethod::level(32)),

        Evolution(
            4,
            5,
            EvolutionMethod::level(16)),

        Evolution(
            5,
            6,
            EvolutionMethod::level(36)),

        Evolution(
            7,
            8,
            EvolutionMethod::level(16)),

        Evolution(
            8,
            9,
            EvolutionMethod::level(36)),

        Evolution(
            10,
            11,
            EvolutionMethod::level(7)),

        Evolution(
            11,
            12,
            EvolutionMethod::level(10)),

        Evolution(
            13,
            14,
            EvolutionMethod::level(7)),

        Evolution(
            14,
            15,
            EvolutionMethod::level(10)),

        Evolution(
            16,
            17,
            EvolutionMethod::level(18)),

        Evolution(
            17,
            18,
            EvolutionMethod::level(36)),

        Evolution(
            19,
            20,
            EvolutionMethod::level(20)),

        Evolution(
            21,
            22,
            EvolutionMethod::level(20)),

        Evolution(
            23,
            24,
            EvolutionMethod::level(22)),

        Evolution(
            25,
            26,
            EvolutionMethod::item(Item::THUNDER_STONE)),

        Evolution(
            27,
            28,
            EvolutionMethod::level(22)),

        Evolution(
            29,
            30,
            EvolutionMethod::level(16)),

        Evolution(
            30,
            31,
            EvolutionMethod::item(Item::MOON_STONE)),

        Evolution(
            32,
            33,
            EvolutionMethod::level(16)),

        Evolution(
            33,
            34,
            EvolutionMethod::item(Item::MOON_STONE))
    };

    return evolutions;
}

} // end namespace indigo