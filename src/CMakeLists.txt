add_subdirectory(application)
add_subdirectory(platform)
add_subdirectory(ui)

add_executable(project_indigo
    main.cpp
)

set_target_properties(project_indigo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_include_directories(project_indigo PRIVATE
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(project_indigo PRIVATE
    application
    platform
    ui
)
