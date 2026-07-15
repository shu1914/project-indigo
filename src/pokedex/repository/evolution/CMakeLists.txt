add_library(evolution_repository
    EvolutionRepository.cpp
)

target_include_directories(evolution_repository PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(evolution_repository
    PUBLIC
        evolution
    PRIVATE
        data
)
