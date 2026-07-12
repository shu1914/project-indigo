/**
 * @file ILogger.h
 * @brief Logger interface
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef I_LOGGER_H
#define I_LOGGER_H

#include "LogLevel.h"
#include <string_view>

namespace indigo
{

class ILogger
{
public:
    virtual ~ILogger() = default;

    virtual void log(
        LogLevel level,
        std::string_view message,
        const char* file,
        int line) = 0;

}; // end class ILogger

} // end namespace indigo

#endif // end I_LOGGER_H
