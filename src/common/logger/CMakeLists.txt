add_library(logger
    ConsoleLogger.cpp
    Log.cpp
    LogLevel.cpp
)

target_include_directories(logger PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(logger PUBLIC
    fmt::fmt
)
