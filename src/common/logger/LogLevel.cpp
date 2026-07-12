/**
 * @file LogLevel.cpp
 * @brief Loglevel
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include "LogLevel.h"

namespace indigo
{

const char*
logLevelToString(
    LogLevel level)
{
    switch (level)
    {
    case LogLevel::Trace:
        return "TRACE";

    case LogLevel::Debug:
        return "DEBUG";

    case LogLevel::Info:
        return "INFO";

    case LogLevel::User:
        return "USER";

    case LogLevel::Warning:
        return "WARN";

    case LogLevel::Error:
        return "ERROR";

    case LogLevel::Fatal:
        return "FATAL";
    }

    return "UNKNOWN";
}

} // namespace indigo
