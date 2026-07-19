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

Result
Application::initialize()
{
    Result result = _config.load();

    if (!result.success())
    {
        return result;
    }

    result = _platform.initialize();

    if (!result.success())
    {
        return result;
    }

    _ui.initialize();

    TRACE("Application initialized.");

    return Result::ok();
}

int
Application::run()
{
    Result result = initialize();
    if(!result.success())
    {
        ERROR(result.message);
        return static_cast<int>(result.error);;
    }

    DEBUG("Hello Project Indigo.");

    TRACE("Starting platform event loop");
    _platform.run();

    shutdown();

    return 0;
}

void
Application::shutdown()
{
    DEBUG("Goodbye Project Indigo.");

    _ui.shutdown();
    _platform.shutdown();

    TRACE("Application shutdown");
}

} // end namespace indigo
