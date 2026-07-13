add_library(ability
    Ability.cpp
)

target_include_directories(ability PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(ability PUBLIC
)
