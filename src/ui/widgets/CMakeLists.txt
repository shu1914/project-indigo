add_library(widget
    label/Label.cpp
)

target_include_directories(widget PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(widget
    PUBLIC
        lvgl
        fmt::fmt
)
