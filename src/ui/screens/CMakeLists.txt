add_library(screen
    home_screen/HomeScreen.cpp
    temp_screen/TempScreen.cpp
)

target_include_directories(screen PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(screen
    PUBLIC
        lvgl
        widget
        logger
        pokedex
)
