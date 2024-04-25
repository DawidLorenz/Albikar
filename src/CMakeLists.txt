message("Building Albikar Editor")

# Qt Setup
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Executable
add_executable(AlbikarEditor
    main.cpp
)

# All files
add_subdirectory(core)
add_subdirectory(events)
add_subdirectory(gui)
add_subdirectory(logger)
add_subdirectory(platform)
add_subdirectory(profiler)
add_subdirectory(system)
add_subdirectory(utils)

# Include
target_include_directories(AlbikarEditor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Code
target_sources(AlbikarEditor PUBLIC
    resource.qrc
)

# Link Qt libraries
target_link_libraries(AlbikarEditor PRIVATE
    Qt5::Core
    Qt5::Widgets
    Qt5::Qml
    Qt5::Quick
    Qt5::QuickControls2
)

# Link C++ libraries
target_link_libraries(AlbikarEditor PRIVATE
    fmt
)