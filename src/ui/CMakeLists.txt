add_library(ui
    UserInterface.cpp
)

target_include_directories(ui PUBLIC
    ${PROJECT_SOURCE_DIR}/src
)
