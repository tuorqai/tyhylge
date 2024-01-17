
/**
 * Icciteq, tuoq da tuhanü ongorbot bibliotieka.
 */

#ifdef TYHYLGE_USE_FREETYPE
    #include <ft2build.h>
    #include <freetype/freetype.h>
#endif

#include "tyhylge.h"

int tyhylge_hello(char const *name)
{
#ifdef TYHYLGE_USE_FREETYPE
    FT_Error ftError;
    FT_Library ftLibrary;
    int majVer, minVer, patchVer;
#endif

    printf("Hello from library, %s!\n", name);

#ifdef TYHYLGE_USE_FREETYPE
    ftError = FT_Init_FreeType(&ftLibrary);

    if (ftError == 0) {
        FT_Library_Version(ftLibrary, &majVer, &minVer, &patchVer);
        printf("FreeType version: %d.%d.%d\n", majVer, minVer, patchVer);
        FT_Done_FreeType(ftLibrary);
    }
#endif

    return 42;
}

