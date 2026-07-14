add_library(pokemon_details
    PokemonDetails.cpp
)

target_include_directories(pokemon_details PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(pokemon_details PUBLIC
)
