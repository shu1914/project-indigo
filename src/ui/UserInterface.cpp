/**
 * @file Platform.cpp
 * @brief Implements the UserInterface class.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include <iostream>

#include "UserInterface.h"

namespace indigo
{

bool
UserInterface::initialize()
{
    std::cout << "Initializing `UserInterface` module." << std::endl;

    return true;
}

void
UserInterface::shutdown()
{
    std::cout << "Shutting `UserInterface` module down." << std::endl;
}

} // end namespace indigo
