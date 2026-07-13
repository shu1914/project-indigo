/**
 * @file IConfiguration.h
 * @brief Configuration interface file
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef I_CONFIGURATION_H
#define I_CONFIGURATION_H

#include <string>

#include "common/error/Result.h"

namespace indigo
{

/**
 * @brief Provides access to application configuration values.
 *
 * Implementations are responsible for loading configuration from
 * a backing store (e.g. JSON file) and exposing typed accessors.
 */
class IConfiguration
{
public:

    virtual ~IConfiguration() = default;

    /**
     * @brief Loads the configuration.
     *
     * @throw std::runtime_error if loading fails.
     */
    virtual Result load() = 0;

    virtual std::string getString(
        const std::string& key) const = 0;

    virtual int getInt(
        const std::string& key) const = 0;

    virtual bool getBool(
        const std::string& key) const = 0;
};

} // end namespace indigo

#endif // end I_CONFIGURATION_H
