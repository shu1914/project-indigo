/**
 * @file Logger.h
 * @brief Logger
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef LOG_H
#define LOG_H

#include <fmt/format.h>

#include "ILogger.h"

namespace indigo
{

class Log
{
public:

    static void initialize(
        ILogger& logger);

    template<typename... Args>
    static void trace(
        const char* file,
        int line,
        fmt::format_string<Args...> format,
        Args&&... args)
    {
        _logger->log(
            LogLevel::Trace,
            fmt::format(
                format,
                std::forward<Args>(args)...),
            file,
            line);
    }

    template<typename... Args>
    static void debug(
        const char* file,
        int line,
        fmt::format_string<Args...> format,
        Args&&... args)
    {
        _logger->log(
            LogLevel::Debug,
            fmt::format(
                format,
                std::forward<Args>(args)...),
            file,
            line);
    }

    template<typename... Args>
    static void info(
        const char* file,
        int line,
        fmt::format_string<Args...> format,
        Args&&... args)
    {
        _logger->log(
            LogLevel::Info,
            fmt::format(
                format,
                std::forward<Args>(args)...),
            file,
            line);
    }

    template<typename... Args>
    static void user(
        const char* file,
        int line,
        fmt::format_string<Args...> format,
        Args&&... args)
    {
        _logger->log(
            LogLevel::User,
            fmt::format(
                format,
                std::forward<Args>(args)...),
            file,
            line);
    }

    template<typename... Args>
    static void warning(
        const char* file,
        int line,
        fmt::format_string<Args...> format,
        Args&&... args)
    {
        _logger->log(
            LogLevel::Warning,
            fmt::format(
                format,
                std::forward<Args>(args)...),
            file,
            line);
    }

    template<typename... Args>
    static void error(
        const char* file,
        int line,
        fmt::format_string<Args...> format,
        Args&&... args)
    {
        _logger->log(
            LogLevel::Error,
            fmt::format(
                format,
                std::forward<Args>(args)...),
            file,
            line);
    }

    template<typename... Args>
    static void fatal(
        const char* file,
        int line,
        fmt::format_string<Args...> format,
        Args&&... args)
    {
        _logger->log(
            LogLevel::Fatal,
            fmt::format(
                format,
                std::forward<Args>(args)...),
            file,
            line);
    }


private:

    static ILogger* _logger;

}; // end class Logger

} // end namespace indigo

#endif // end LOG_H
