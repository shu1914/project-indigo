find_package(nlohmann_json REQUIRED)

add_library(config
    Configuration.cpp
)

target_include_directories(config PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(config PUBLIC
    nlohmann_json::nlohmann_json
)
