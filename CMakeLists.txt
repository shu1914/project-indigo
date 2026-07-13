cmake_minimum_required(VERSION 3.10)

project(project_indigo LANGUAGES C CXX)

cmake_policy(SET CMP0079 NEW)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY
    ${CMAKE_SOURCE_DIR}/config
    DESTINATION ${CMAKE_BINARY_DIR}
)

# Third-party libraries

# Project Libraries
add_subdirectory(src)