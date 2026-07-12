/**
 * @file Log.cpp
 * @brief Log source
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include "Log.h"

namespace indigo
{

ILogger* Log::_logger = nullptr;

void Log::initialize(
    ILogger& logger)
{
    _logger = &logger;
}

} // namespace indigo
