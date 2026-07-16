find_package(Catch2 3 REQUIRED)

file(GLOB_RECURSE TEST_SOURCES
    CONFIGURE_DEPENDS
    *.cpp
)

add_executable(project_indigo_tests
    ${TEST_SOURCES}
)

target_link_libraries(project_indigo_tests PRIVATE
    Catch2::Catch2WithMain

    pokedex
    logger
    config
)

include(Catch)

catch_discover_tests(project_indigo_tests)
