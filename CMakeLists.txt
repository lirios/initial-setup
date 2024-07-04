cmake_minimum_required(VERSION 3.19)

project("Initial Setup"
    VERSION "0.0.0"
    DESCRIPTION "Initial setup for Liri OS"
    LANGUAGES CXX C
)

## Only build on the appropriate platforms.
if(NOT UNIX OR ANDROID)
    message(NOTICE "Skipping the build as the condition \"UNIX OR ANDROID\" is not met.")
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

## Add subdirectories:
add_subdirectory(src)
