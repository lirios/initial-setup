cmake_minimum_required(VERSION 3.19)

project("Initial Setup"
    VERSION "0.0.0"
    DESCRIPTION "Initial setup for Liri OS"
    LANGUAGES CXX C
)

## Only build on the appropriate platforms.
if(NOT UNIX OR ANDROID)
    message(NOTICE "\"${CMAKE_PROJECT_NAME}\" can be build only on UNIX-like systems, Android excluded")
    return()
endif()

## Enable C++17:
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Find Qt:
find_package(Qt6
    REQUIRED
    COMPONENTS
        Core
        Gui
        Qml
        Quick
        QuickControls2
        LinguistTools
)
qt_standard_project_setup()

## Add subdirectories:
add_subdirectory(src)
