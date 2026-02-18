#pragma once

#if defined(_WIN32) || defined(_WIN64)
    #if defined(ALBIKAR_ENGINE_BUILD_DLL)
        #define ALBIKAR_ENGINE_API __declspec(dllexport)
    #else
        #define ALBIKAR_ENGINE_API __declspec(dllimport)
    #endif
#else
    #define ALBIKAR_ENGINE_API
#endif
