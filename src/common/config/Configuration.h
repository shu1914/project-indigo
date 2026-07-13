/**
 * @file Configuration.h
 * @brief Configuration class
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>

#include "IConfiguration.h"

namespace indigo
{

class Configuration : public IConfiguration
{
public:

    explicit Configuration(
        std::string path);

    void load() override;

    std::string getString(
        const std::string& key) const override;

    int getInt(
        const std::string& key) const override;

    bool getBool(
        const std::string& key) const override;

private:

    void flatten(
        const nlohmann::json& node,
        const std::string& prefix);

    std::string _path;

    std::unordered_map<std::string, std::string> _values;
};

} // end namespace indigo

#endif // end CONFIGURATION_H
