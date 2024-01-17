
#ifndef TYHYLGE_H
#define TYHYLGE_H

#include <stdio.h>

#ifdef TYHYLGE_SHARED
    #ifdef _WIN32
        #ifdef TYHYLGE_BUILD
            #define TYHYLGE_API     __declspec(dllexport)
        #else
            #define TYHYLGE_API     __declspec(dllimport)
        #endif
        #define TYHYLGE_CALL        __cdecl
    #else
        #ifdef __GNUC__
            #define TYHYLGE_API     __attribute__((visibility("default")))
        #endif
    #endif
#endif

#ifndef TYHYLGE_API
    #define TYHYLGE_API
#endif

#ifndef TYHYLGE_CALL
    #define TYHYLGE_CALL
#endif

TYHYLGE_API int TYHYLGE_CALL tyhylge_hello(char const *);

#endif /* TYHYLGE_H */

