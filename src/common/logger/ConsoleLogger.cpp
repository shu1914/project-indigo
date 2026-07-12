/**
 * @file ConsoleLogger.cpp
 * @brief Console logger source
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include <iostream>

#include "ConsoleLogger.h"

namespace indigo
{

void
ConsoleLogger::log(
        LogLevel level,
        std::string_view message,
        const char* file,
        int line)
{
    std::cout
        << '[' << logLevelToString(level) << "] "
        << message
        << '\n';
}

} // end namespace indigo
