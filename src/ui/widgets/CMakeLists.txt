add_library(widget
    WidgetBehavior.cpp

    label/Label.cpp
    container/Container.cpp
    line/Line.cpp
    button/Button.cpp
)

target_include_directories(widget PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(widget
    PUBLIC
        lvgl
        fmt::fmt
)
