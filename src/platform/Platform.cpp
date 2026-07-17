/**
 * @file Platform.cpp
 * @brief Implements the Platform class.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-12
 * 
 * @copyright Copyright (c) 2026
 */

#include "Platform.h"
#include "common/logger/LogMacro.h"

namespace indigo
{

Result
Platform::initialize()
{
    TRACE("Initializing `Platform` module.");

    return Result::ok();
}

void
Platform::shutdown()
{
    TRACE("Shutting `Platform` module down.");
}

void
Platform::run()
{
    TRACE("Starting `Platform`.");
}

} // end namespace indigo
