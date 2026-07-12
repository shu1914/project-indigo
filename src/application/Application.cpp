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
    IPlatform& platform,
    IUserInterface& ui)
    : _platform(platform)
    , _ui(ui)
{
}

int
Application::run()
{
    std::cout << "Hello Project Indigo." << std::endl;

    _platform.initialize();
    _ui.initialize();

    std::cout << "Application initialized." << std::endl;

    return 0;
}

void
Application::shutdown()
{
    std::cout << "Goodbye Project Indigo." << std::endl;

    _platform.shutdown();
    _ui.shutdown();

    std::cout << "Application shutdown." << std::endl;
}

} // end namespace indigo
