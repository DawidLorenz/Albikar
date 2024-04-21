target_sources(AlbikarEditor PUBLIC
    Instrumentor.cpp
    Instrumentor.h
    Profiler.h
)

target_include_directories(AlbikarEditor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)