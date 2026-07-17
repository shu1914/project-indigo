/**
 * @file Application.h
 * @brief Application lifecycle interface.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-12
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

#include "platform/IPlatform.h"
#include "ui/IUserInterface.h"
#include "common/config/IConfiguration.h"
#include "common/error/Result.h"

namespace indigo
{

class Application
{

public:

    Application(
        IConfiguration& config,
        IPlatform& platform,
        IUserInterface& ui);

    bool initialize();

    /**
     * @brief Runs the application lifecycle.
     * 
     * @return int Exit status code.
     */
    int run();

    /**
     * @brief Exits the application
     * 
     */
    void shutdown();

private:

    IConfiguration& _config;
    IPlatform& _platform;
    IUserInterface& _ui;

}; // end class Application

} // end namespace indigo

#endif // end APPLICATION_H
