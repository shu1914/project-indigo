/**
 * @file LogLevel.h
 * @brief Log level enum
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef LOG_LEVEL_H
#define LOG_LEVEL_H

namespace indigo
{

enum class LogLevel
{
    Trace,
    Debug,
    Info,
    User,
    Warning,
    Error,
    Fatal,

}; // end enum class LogLevel

const char*
logLevelToString(LogLevel level);

} // end namespace indigo

#endif // end LOG_LEVEL_H
