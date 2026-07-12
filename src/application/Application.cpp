/**
 * @file Application.cpp
 * @brief Application lifecycle implementation.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-12
 * 
 * @copyright Copyright (c) 2026
 */

#include "Application.h"
#include "common/logger/LogMacro.h"

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
    DEBUG("Hello Project Indigo.");

    _platform.initialize();
    _ui.initialize();

    TRACE("Application initialized.");

    return 0;
}

void
Application::shutdown()
{
    DEBUG("Goodbye Project Indigo.");

    _platform.shutdown();
    _ui.shutdown();

    TRACE("Application shutdown");
}

} // end namespace indigo
