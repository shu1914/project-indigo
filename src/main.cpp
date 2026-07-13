/**
 * @file main.cpp
 * @brief Main entry point of the app.
 * @author As-Harrie Dianalan (asharrie.dianalan@gmail.com)
 * @date 2026-07-12
 * 
 * @copyright Copyright (c) 2026
 */

#include "common/config/Configuration.h"
#include "common/logger/ConsoleLogger.h"
#include "common/logger/Log.h"
#include "platform/Platform.h"
#include "ui/UserInterface.h"
#include "pokedex/Pokedex.h"
#include "application/Application.h"

int
main(
    int argc,
    char** argv)
{

    indigo::Configuration config("config/config.json");
    config.load();

    indigo::ConsoleLogger console;

    indigo::Log::initialize(console);

    indigo::Platform platform;

    indigo::Pokedex pokedex;

    indigo::UserInterface ui(
        pokedex);

    indigo::Application app(
        config,
        platform,
        ui);

    app.run();

    app.shutdown();

    return 0;
}
