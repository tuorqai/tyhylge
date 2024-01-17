
/**
 * Icciteq, tuoq da tuhanü ongorbot bibliotieka.
 */

#ifdef TYHYLGE_USE_PYTHON
    #define PY_SSIZE_T_CLEAN
    #include <Python.h>
#endif

#ifdef TYHYLGE_USE_FREETYPE
    #include <ft2build.h>
    #include <freetype/freetype.h>
#endif

#include "tyhylge.h"

#ifdef TYHYLGE_USE_PYTHON
static void _python(void)
{
    PyConfig config;
    PyStatus status;

    PyConfig_InitIsolatedConfig(&config);
    status = Py_InitializeFromConfig(&config);

    if (PyStatus_Exception(status)) {
        fprintf(stderr, "Failed to initialize Python.\n");
        return;
    }

    PyRun_SimpleString("import sys\nprint(sys.version)");
    Py_FinalizeEx();
}
#endif // TYHYLGE_USE_PYTHON

#ifdef TYHYLGE_USE_FREETYPE
static void _freetype(void)
{
    FT_Error ftError;
    FT_Library ftLibrary;
    int majVer, minVer, patchVer;

    ftError = FT_Init_FreeType(&ftLibrary);

    if (ftError != 0) {
        fprintf(stderr, "Failed to initialize FreeType.\n");
        return;
    }

    FT_Library_Version(ftLibrary, &majVer, &minVer, &patchVer);
    printf("FreeType version: %d.%d.%d\n", majVer, minVer, patchVer);
    FT_Done_FreeType(ftLibrary);
}
#endif // TYHYLGE_USE_FREETYPE

int tyhylge_hello(char const *name)
{
    printf("Hello from library, %s!\n", name);

#ifdef TYHYLGE_USE_PYTHON
    _python();
#endif

#ifdef TYHYLGE_USE_FREETYPE
    _freetype();
#endif

    return 42;
}

