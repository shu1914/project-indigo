/**
 * @file Evolutions.h
 * @brief Evolutions data
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef EVOLUTIONS_H
#define EVOLUTIONS_H

#include <vector>

#include "../model/evolution/Evolution.h"

namespace indigo
{

class Evolutions
{

public:

    /**
     * @brief Returns all evolution edges.
     *
     * @return Constant reference to the evolution graph.
     */
    static const std::vector<Evolution>& all();

}; // end class Evolutions

} // end namespace indigo

#endif // end EVOLUTIONS_H