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

namespace indigo
{

class Application
{

public:

    Application(
        IPlatform& platform);

    /**
     * @brief Runs the application lifecycle.
     * 
     * @return int Exit status code.
     */
    int run();

private:

    IPlatform& _platform;

}; // end class Application

} // end namespace indigo

#endif // end APPLICATION_H
