
add_library(tyhylge tyhylge.c)
target_compile_definitions(tyhylge PRIVATE TYHYLGE_BUILD)

set_target_properties(tyhylge
    PROPERTIES
        PUBLIC_HEADER tyhylge.h
        POSITION_INDEPENDENT_CODE ON
        C_VISIBILITY_PRESET hidden)

if(BUILD_SHARED_LIBS)
    target_compile_definitions(tyhylge PRIVATE TYHYLGE_SHARED)
endif()

if(TYHYLGE_USE_FREETYPE)
    find_package(Freetype REQUIRED)
    target_compile_definitions(tyhylge PRIVATE TYHYLGE_USE_FREETYPE)
    target_link_libraries(tyhylge PRIVATE Freetype::Freetype)
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS tyhylge
    EXPORT tyhylge-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT tyhylge-targets
    NAMESPACE tyhylge::
    FILE tyhylge-targets.cmake
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/tyhylge")

configure_package_config_file(
    "${CMAKE_SOURCE_DIR}/cmake/config.cmake.in"
    "${CMAKE_BINARY_DIR}/tyhylge-config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/tyhylge"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO)

write_basic_package_version_file(
    "${CMAKE_BINARY_DIR}/tyhylge-config-version.cmake"
    VERSION "0.1.0"
    COMPATIBILITY SameMajorVersion)

install(FILES
    "${CMAKE_BINARY_DIR}/tyhylge-config.cmake"
    "${CMAKE_BINARY_DIR}/tyhylge-config-version.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/tyhylge")

