add_library(application
    Application.cpp
)

target_link_libraries(application PUBLIC
    platform
)

target_include_directories(application PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)
