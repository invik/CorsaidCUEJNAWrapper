#pragma once

#ifndef _LIB
#   if defined(_WIN32) || defined(WIN32)
#       if defined(CORSAIR_LIGHTING_SDK_DLL) || defined(CUESDK_EXPORTS)
#           define CORSAIRCUEJNAWRAPPER_API __declspec(dllexport)
#       else
#           define CORSAIRCUEJNAWRAPPER_API __declspec(dllimport)
#       endif
#   else
#       define CORSAIRCUEJNAWRAPPER_API __attribute__((visibility("default")))
#   endif // WIN32
#else
#   define CORSAIRCUEJNAWRAPPER_API
#endif // !_LIB
