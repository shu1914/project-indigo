find_package(SDL2 REQUIRED)

add_library(platform
    Platform.cpp
    SDLPlatform.cpp
)

target_include_directories(platform PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(platform
    PRIVATE
        lvgl
        SDL2::SDL2
)