/**
 * @file Platform.cpp
 * @brief Implements the Platform class.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-12
 * 
 * @copyright Copyright (c) 2026
 */

#include <iostream>

#include "Platform.h"

namespace indigo
{

bool
Platform::initialize()
{
    std::cout << "Initializing `Platform` module." << std::endl;

    return true;
}

void
Platform::shutdown()
{
    std::cout << "Shutting `Platform` module down." << std::endl;
}

} // end namespace indigo
