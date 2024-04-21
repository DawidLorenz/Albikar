target_sources(AlbikarEditor PUBLIC
    ConsoleLogger.cpp
    ConsoleLogger.h
    ILogger.h
    Logger.cpp
    Logger.h
)

target_include_directories(AlbikarEditor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)