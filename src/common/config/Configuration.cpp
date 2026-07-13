/**
 * @file Configuration.cpp
 * @brief Configuration class implementation
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-13
 * 
 * @copyright Copyright (c) 2026
 */

#include "Configuration.h"

#include <fstream>
#include <stdexcept>

using json = nlohmann::json;

namespace indigo
{

Configuration::Configuration(
    std::string path)
    : _path(std::move(path))
{
}

void
Configuration::load()
{
    std::ifstream file(_path);

    if (!file.is_open())
    {
        throw std::runtime_error(
            "Failed to open configuration file: " + _path);
    }

    json root;
    file >> root;

    _values.clear();

    flatten(root, "");
}

std::string
Configuration::getString(
    const std::string& key) const
{
    auto it = _values.find(key);

    if (it == _values.end())
    {
        throw std::runtime_error(
            "Missing configuration key: " + key);
    }

    return it->second;
}

int
Configuration::getInt(
    const std::string& key) const
{
    return std::stoi(getString(key));
}

bool
Configuration::getBool(
    const std::string& key) const
{
    const auto value = getString(key);

    if (value == "true")
    {
        return true;
    }

    if (value == "false")
    {
        return false;
    }

    throw std::runtime_error(
        "Invalid boolean value for key: " + key);
}

void
Configuration::flatten(
    const json& node,
    const std::string& prefix)
{
    if (node.is_object())
    {
        for (const auto& [key, value] : node.items())
        {
            const std::string fullKey =
                prefix.empty()
                    ? key
                    : prefix + "." + key;

            flatten(value, fullKey);
        }

        return;
    }

    if (node.is_string())
    {
        _values[prefix] = node.get<std::string>();
    }
    else
    {
        _values[prefix] = node.dump();
    }
}

} // end namespace indigo
