/**
 * @file main.cpp
 * @brief Main entry point of the app.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-12
 * 
 * @copyright Copyright (c) 2026
 */

#include "platform/Platform.h"
#include "ui/UserInterface.h"
#include "application/Application.h"

int
main(
    int argc,
    char** argv)
{

    indigo::Platform platform;

    indigo::UserInterface ui;

    indigo::Application app(
        platform,
        ui);

    return app.run();
}
