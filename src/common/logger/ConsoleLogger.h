/**
 * @file ConsoleLogger.h
 * @brief Console logger header file
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H

#include "ILogger.h"

namespace indigo
{

class ConsoleLogger : public ILogger
{
public:
    void log(
        LogLevel level,
        std::string_view message,
        const char* file,
        int line) override;

}; // end class ConsoleLogger

} // namespace indigo

#endif // end CONSOLE_LOGGER_H
