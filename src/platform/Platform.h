/**
 * @file Platform.h
 * @brief Implements the IPlatform interface.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-12
 * 
 * Platform coordinates the platform subsystem by managing the underlying
 * platform components (e.g. backend, display, input, and event loop) while
 * exposing a unified API through IPlatform.
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef PLATFORM_H
#define PLATFORM_H

#include "IPlatform.h"

namespace indigo
{

class Platform : public IPlatform
{

public:

    Result initialize() override;

    void shutdown() override;

    void run() override;

}; // end class Platform

} // end namespace indigo

#endif // end PLATFORM_H
