add_subdirectory(model)
add_subdirectory(data)

add_library(pokedex
    Pokedex.cpp
)

target_include_directories(pokedex PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(pokedex PUBLIC
    data

    ## models
    pokemon
    type
    ability
)