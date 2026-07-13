add_library(type
    Type.cpp
)

target_include_directories(type PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(type PUBLIC
)
