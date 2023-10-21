cmake_minimum_required(VERSION 3.26)
project(OOPCurses)

## Curses
if(WIN32)
    include_directories(${PDCURSES_DIR})
    file(GLOB PDCURSES_SRC ${PDCURSES_DIR}/pdcurses/*.c)
    file(GLOB PDCURSES_SRC_WINCON ${PDCURSES_DIR}/wincon/*.c)
    add_library(pdcurses ${PDCURSES_SRC} ${PDCURSES_SRC_WINCON})
    target_compile_options(pdcurses PRIVATE -DPDC_WIDE -DPDC_FORCE_UTF8)
    set(PD_OR_N_CURSES pdcurses)
else()
    set(CURSES_NEED_NCURSES ON)
    find_package(Curses REQUIRED)
    include_directories(${CURSES_INCLUDE_DIR})
    set(PD_OR_N_CURSES ${CURSES_LIBRARIES})
endif()

include_directories(includes)
set(SRC_ROOT 
    src/MainWindow.cpp 
    src/MainWindow.cpp
    src/ConverterTypeData.cpp
)

## building project
add_library(${PROJECT_NAME} ${SRC_ROOT})
target_include_directories(${PROJECT_NAME} PUBLIC includes)
target_link_libraries(${PROJECT_NAME} ${PD_OR_N_CURSES})
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

## ABI version
set_property(TARGET ${PROJECT_NAME} PROPERTY SOVERSION 1)
