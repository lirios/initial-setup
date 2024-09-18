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

## ECM:
find_package(ECM 5.245.0 REQUIRED NO_MODULE)
list(APPEND CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

## Installation directories:
include(KDEInstallDirs)

## Compiler settings:
set(KDE_SKIP_NULLPTR_WARNINGS_SETTINGS TRUE)
include(KDECompilerSettings NO_POLICY_SCOPE)

## CMake settings:
include(KDECMakeSettings)

## Disable use of C++ API deprecated in Qt 5.15
add_compile_definitions(QT_DISABLE_DEPRECATED_UP_TO=0x050F00)

## Enable C++17:
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Treat warnings as errors:
add_compile_options(-Wall -Wextra -Werror)

## Features:
include(features.cmake)

## Add subdirectories:
add_subdirectory(src)
