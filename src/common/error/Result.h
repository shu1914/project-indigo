/**
 * @file Result.h
 * @brief Result struct
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef RESULT_H
#define RESULT_H

#include <string>

#include "Error.h"

namespace indigo
{

struct Result
{
    Error error = Error::None;

    std::string message;

    bool success() const
    {
        return error == Error::None;
    }

    static Result ok()
    {
        return {};
    }

    static Result fail(
        Error error,
        std::string message)
    {
        return { error, std::move(message) };
    }
};

} // end namespace indigo

#endif // end RESULT_H
