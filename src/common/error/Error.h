/**
 * @file Error.h
 * @brief Error code
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef ERROR_H
#define ERROR_H

namespace indigo
{

enum class Error
{
    None = 0,

    // Config
    ConfigFileNotFound,
    ConfigParseFailed,

    // LVGL
    LvglDisplayInitFailed,

    // LVGL Backend
    LvglBackendNotEnabled,

    Unknown,
};

} // error namespace indigo

#endif // end ERROR_H
