add_library(pokemon_repository
    PokemonRepository.cpp
)

target_include_directories(pokemon_repository PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(pokemon_repository PUBLIC
)
