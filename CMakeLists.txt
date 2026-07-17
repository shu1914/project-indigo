cmake_minimum_required(VERSION 3.13)

project(project_indigo LANGUAGES C CXX)

cmake_policy(SET CMP0077 NEW)
cmake_policy(SET CMP0079 NEW)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY
    ${CMAKE_SOURCE_DIR}/config
    DESTINATION ${CMAKE_BINARY_DIR}
)

# Third-party libraries
set(LV_BUILD_CONF_PATH
    ${CMAKE_SOURCE_DIR}/config/lv_conf.h
    CACHE STRING "Path to lv_conf.h"
)

# Disable demo builds
set(CONFIG_LV_BUILD_DEMOS OFF CACHE BOOL "" FORCE)
set(CONFIG_LV_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(CONFIG_LV_USE_THORVG_INTERNAL OFF CACHE BOOL "" FORCE)

add_subdirectory(external)

# Project Libraries
add_subdirectory(src)

# Tests
option(BUILD_TESTING "Build unit tests" ON)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
