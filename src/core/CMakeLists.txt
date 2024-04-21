include(GitVersion)
add_version_info(TARGET AlbikarEditor TEMPLATES Version.cc.in)

target_sources(AlbikarEditor PUBLIC
    Application.cpp
    Application.h
    Version.h)

target_include_directories(AlbikarEditor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)