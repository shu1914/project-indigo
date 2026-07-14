add_library(data
    Types.cpp
    Abilities.cpp
    Evolutions.cpp
    Pokemons.cpp
)

target_include_directories(data PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(data PUBLIC
    pokemon
    type
    ability
    evolution
)
