/**
 * @file Application.cpp
 * @brief Application lifecycle implementation.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-12
 * 
 * @copyright Copyright (c) 2026
 */

#include <iostream>

#include "Application.h"

namespace indigo
{

Application::Application(
    IPlatform& platform)
    : _platform(platform)
{
}

int
Application::run()
{
    std::cout << "Hello Project Indigo." << std::endl;

    _platform.initialize();

    std::cout << "Application initialized." << std::endl;

    return 0;
}

} // end namespace indigo
