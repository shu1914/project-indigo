cmake_minimum_required(VERSION 3.10)

project(project_indigo LANGUAGES C CXX)

cmake_policy(SET CMP0079 NEW)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(project_indigo
    src/main.cpp
)

target_include_directories(project_indigo PRIVATE
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(project_indigo PRIVATE)