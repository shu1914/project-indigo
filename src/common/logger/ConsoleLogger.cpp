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
#include <cstring>
#include <iomanip>

namespace indigo
{

static const char*
getFilename(const char* path)
{
    const char* filename = std::strrchr(path, '/');

    return filename
        ? filename + 1
        : path;
}

const char*
color(
    indigo::LogLevel level)
{
    using indigo::LogLevel;

    switch (level)
    {
    case LogLevel::Trace:
        return "\033[90m"; // Gray

    case LogLevel::Debug:
        return "\033[36m"; // Cyan

    case LogLevel::Info:
        return "\033[32m"; // Green

    case LogLevel::User:
        return "\033[97m"; // White

    case LogLevel::Warning:
        return "\033[33m"; // Yellow

    case LogLevel::Error:
        return "\033[31m"; // Red

    case LogLevel::Fatal:
        return "\033[35m"; // Magenta
    }

    return "\033[0m";
}

constexpr const char* RESET = "\033[0m";

void
ConsoleLogger::log(
    LogLevel level,
    std::string_view message,
    const char* file,
    int line)
{
    std::cout
        << color(level)
        << '['
        << std::left
        << std::setw(5)
        << logLevelToString(level)
        << "] "
        << RESET
        << std::setw(20)
        << getFilename(file)
        << ':'
        << std::setw(4)
        << line
        << " "
        << message
        << '\n';
}

} // end namespace indigo
