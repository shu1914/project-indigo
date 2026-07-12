add_library(platform
    Platform.cpp
)

target_include_directories(platform PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)
