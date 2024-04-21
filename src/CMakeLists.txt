message("Building Albikar Editor")

# Qt Setup
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
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

# Link Qt libraries
target_link_libraries(AlbikarEditor PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2)

# Link libraries
target_link_libraries(AlbikarEditor PRIVATE
    fmt)

# Set the location of QML files in the build directory
set(QML_IMPORT_PATH "${CMAKE_CURRENT_BINARY_DIR}" CACHE STRING "" FORCE)