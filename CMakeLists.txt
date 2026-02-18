cmake_minimum_required(VERSION 3.25)

project(Albikar
    VERSION 0.1.0
    DESCRIPTION "Albikar - Vulkan game engine + editor"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ALBIKAR_BUILD_EDITOR "Build editor application" ON)
option(ALBIKAR_ENABLE_VULKAN "Enable Vulkan backend if SDK is available" ON)
option(ALBIKAR_ENABLE_CLANG_TIDY "Enable clang-tidy diagnostics when available" ON)
option(ALBIKAR_BUILD_TESTS "Build unit tests" ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(CompilerWarnings)

if(ALBIKAR_ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES clang-tidy)
    if(CLANG_TIDY_EXE)
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
        message(STATUS "clang-tidy enabled: ${CLANG_TIDY_EXE}")
    else()
        message(STATUS "clang-tidy not found - continuing without it.")
    endif()
endif()

if(ALBIKAR_ENABLE_VULKAN)
    find_package(Vulkan QUIET)
    if(Vulkan_FOUND)
        message(STATUS "Vulkan SDK found: ${Vulkan_INCLUDE_DIRS}")
    else()
        message(WARNING "Vulkan SDK not found. Engine will compile in stub mode.")
    endif()
endif()

add_library(albikar_engine SHARED
    engine/src/Engine.cpp)

add_library(Albikar::Engine ALIAS albikar_engine)

target_include_directories(albikar_engine
    PUBLIC
        engine/include)

target_compile_features(albikar_engine PUBLIC cxx_std_23)
target_compile_definitions(albikar_engine PRIVATE ALBIKAR_ENGINE_BUILD_DLL=1)
albikar_set_project_warnings(albikar_engine)
set_target_properties(albikar_engine PROPERTIES OUTPUT_NAME "AlbikarEngine")

if(ALBIKAR_ENABLE_VULKAN AND Vulkan_FOUND)
    target_link_libraries(albikar_engine PUBLIC Vulkan::Vulkan)
    target_compile_definitions(albikar_engine PUBLIC ALBIKAR_HAS_VULKAN=1)
endif()

if(ALBIKAR_BUILD_EDITOR)
    add_executable(albikar_editor
        editor/src/main.cpp
        editor/src/gui/EditorApplication.cpp
        editor/src/gui/EditorPanels.cpp)

    target_include_directories(albikar_editor PRIVATE editor/include)
    target_link_libraries(albikar_editor PRIVATE Albikar::Engine)
    target_compile_features(albikar_editor PRIVATE cxx_std_23)
    albikar_set_project_warnings(albikar_editor)
    set_target_properties(albikar_editor PROPERTIES OUTPUT_NAME "AlbikarEditor")

    find_package(glfw3 CONFIG QUIET)
    find_package(imgui CONFIG QUIET)
    find_package(OpenGL QUIET)

    if(glfw3_FOUND AND imgui_FOUND AND OpenGL_FOUND)
        target_compile_definitions(albikar_editor PRIVATE ALBIKAR_EDITOR_HAS_GUI=1)
        target_link_libraries(albikar_editor PRIVATE glfw imgui::imgui OpenGL::GL)
        message(STATUS "GUI editor enabled (GLFW + Dear ImGui + OpenGL).")
    else()
        message(WARNING "GUI dependencies not found. Building AlbikarEditor in console fallback mode.")
    endif()
endif()

enable_testing()

if(ALBIKAR_BUILD_EDITOR)
    add_test(NAME AlbikarEditorRuns COMMAND albikar_editor)
endif()

if(ALBIKAR_BUILD_TESTS)
    find_package(GTest CONFIG QUIET)
    if(GTest_FOUND)
        include(GoogleTest)
        add_executable(albikar_engine_tests tests/engine/EngineTests.cpp)
        target_link_libraries(albikar_engine_tests PRIVATE Albikar::Engine GTest::gtest_main)
        target_compile_features(albikar_engine_tests PRIVATE cxx_std_23)
        albikar_set_project_warnings(albikar_engine_tests)
        gtest_discover_tests(albikar_engine_tests)
    else()
        message(WARNING "GTest not found. Unit tests are disabled.")
    endif()
endif()
