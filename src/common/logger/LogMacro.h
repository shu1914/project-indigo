/**
 * @file LogMacro.h
 * @brief Log macros
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef LOG_MACRO_H
#define LOG_MACRO_H

#include "Log.h"

#define TRACE(...) \
    indigo::Log::trace(__FILE__, __LINE__, __VA_ARGS__)

#define DEBUG(...) \
    indigo::Log::debug(__FILE__, __LINE__, __VA_ARGS__)

#define INFO(...) \
    indigo::Log::info(__FILE__, __LINE__, __VA_ARGS__)

#define USER(...) \
    indigo::Log::user(__FILE__, __LINE__, __VA_ARGS__)

#define WARN(...) \
    indigo::Log::warning(__FILE__, __LINE__, __VA_ARGS__)

#define ERROR(...) \
    indigo::Log::error(__FILE__, __LINE__, __VA_ARGS__)

#define FATAL(...) \
    indigo::Log::fatal(__FILE__, __LINE__, __VA_ARGS__)

#endif // end LOG_MACRO_H
