/**
 * @file SDLPlatform.h
 * @brief SDL platform class header
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-17
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef SDL_PLATFORM_H
#define SDL_PLATFORM_H

#include "IPlatform.h"

namespace indigo
{

class SDLPlatform : public IPlatform
{

public:

    SDLPlatform();

    Result initialize() override;

    void shutdown() override;

    void run() override;

    void stop() { _isRunning = false; }

private:
    
    bool _isRunning;
    bool _initialized;

}; // end class SDLPlatform

} // end namespace indigo

#endif // end SDL_PLATFORM_H