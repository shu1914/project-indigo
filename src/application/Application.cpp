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
#include "common/error/Result.h"

namespace indigo
{

Application::Application(
    IConfiguration& config,
    IPlatform& platform,
    IUserInterface& ui)
    : _config(config)
    , _platform(platform)
    , _ui(ui)
{
}

bool
Application::initialize()
{
    Result result = _config.load();

    if (!result.success())
    {
        ERROR(result.message);
        return false;
    }

    _platform.initialize();
    _ui.initialize();

    TRACE("Application initialized.");

    return true;
}

int
Application::run()
{
    DEBUG("Hello Project Indigo.");

    TRACE("Starting thread");
    _platform.run();

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
