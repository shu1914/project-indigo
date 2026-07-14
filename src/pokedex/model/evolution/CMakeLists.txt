add_library(evolution
    Evolution.cpp
    EvolutionMethod.cpp
)

target_include_directories(evolution PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(evolution PUBLIC
)
