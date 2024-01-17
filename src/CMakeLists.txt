
add_library(tyhylge tyhylge.c)
target_compile_definitions(tyhylge PRIVATE TYHYLGE_BUILD)

if(BUILD_SHARED_LIBS)
    target_compile_definitions(tyhylge PRIVATE TYHYLGE_SHARED)
endif()

