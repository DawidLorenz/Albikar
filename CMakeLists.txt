cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
message("##################################")
message("######## PROJECT ALBIKAR #########")

# Project
project(Albikar LANGUAGES CXX)

# Project Setup
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_GNUtoMS ON CACHE INTERNAL "")

# QT Setup
find_package(Qt6 COMPONENTS 
    Core
    Widgets
    Qml
    Quick
    QuickControls2
    REQUIRED)

# Add submodules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(AddGitSubmodule)
add_git_submodule(${CMAKE_SOURCE_DIR}/thirtParts/CMake-GitVersion)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/thirtParts/CMake-GitVersion/cmake")

# source
add_subdirectory(src)

# test
add_subdirectory(test EXCLUDE_FROM_ALL)

message("#### CONFIGURATION FINISHED ######")
message("##################################")