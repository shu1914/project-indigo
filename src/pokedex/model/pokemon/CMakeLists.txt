add_library(pokemon
    Pokemon.cpp
)

target_include_directories(pokemon PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(pokemon PUBLIC
)
