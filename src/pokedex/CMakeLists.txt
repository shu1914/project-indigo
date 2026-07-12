add_library(pokedex
    Pokedex.cpp
)

target_include_directories(pokedex PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)
