find_package(Catch2 3 REQUIRED)

add_executable(project_indigo_tests
    repository/PokemonRepositoryTests.cpp
)

target_include_directories(project_indigo_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(project_indigo_tests PRIVATE
    Catch2::Catch2WithMain

    pokedex
    logger
    config
)

include(Catch)

catch_discover_tests(project_indigo_tests)
