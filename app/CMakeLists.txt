
add_executable(tyhylge-app main.c)
target_link_libraries(tyhylge-app tyhylge)

include(GNUInstallDirs)
install(TARGETS tyhylge-app
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

