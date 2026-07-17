/**
 * @file SDLPlatform.cpp
 * @brief SDL platform class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-17
 * 
 * @copyright Copyright (c) 2026
 */

#include <lvgl.h>

#if LV_USE_SDL
#include <SDL2/SDL.h>
#endif

#include "SDLPlatform.h"
#include "common/logger/LogMacro.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

namespace indigo
{

SDLPlatform::SDLPlatform()
    : _isRunning(false)
{
}

Result
SDLPlatform::initialize()
{
    lv_init();
#if LV_USE_SDL
    lv_display_t* disp = lv_sdl_window_create(
        SCREEN_WIDTH,
        SCREEN_HEIGHT);

    if(!disp)
    {
        return Result::fail(
            Error::LvglDisplayInitFailed,
            "Display initialize failed.");
    }

#else
    return Result::fail(
        Error::LvglBackendNotEnabled,
        "SDL not enabled in lv_conf.h. Please enable and rebuild");
#endif

    TRACE("Initializing SDL platform module.");
    _isRunning = true;
    return Result::ok();
}

void
SDLPlatform::shutdown()
{
    TRACE("Shutting SDL platform module down.");
}

void
SDLPlatform::run()
{
#if LV_USE_SDL
    while(_isRunning)
    {
        uint32_t time_till_next = lv_timer_handler();
        SDL_Delay(time_till_next);

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {    
            if (event.type == SDL_QUIT)
            {
                _isRunning = false;
                break;
            }
        }
    }
#endif
}

} // end namespace indigo
