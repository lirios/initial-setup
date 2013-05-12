project(MauiInitialSetup)

cmake_minimum_required(VERSION 2.8.9)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Set version
set(MIS_VERSION_MAJOR 0)
set(MIS_VERSION_MINOR 0)
set(MIS_VERSION_PATCH 0)
set(MIS_VERSION_STRING "${MIS_VERSION_MAJOR}.${MIS_VERSION_MINOR}.${MIS_VERSION_PATCH}")

# Installation directories
include(HawaiiInstallDirs)

# Log features
include(MacroLogFeature)

# Add custom uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)
add_custom_target(uninstall "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

# Set up packaging
set(CPACK_PACKAGE_NAME maui-initial-setup)
set(CPACK_PACKAGE_VERSION ${MIS_VERSION_STRING})
set(CPACK_SYSTEM_NAME "generic")
set(CPACK_GENERATOR "TGZ")
set(CPACK_SET_DESTDIR FALSE)
include(CPack)

# Build flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden -fvisibility-inlines-hidden -Wall -std=c++0x")

# Assume release build by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "" FORCE)
endif()

# Disable debug output for release builds
if(CMAKE_BUILD_TYPE MATCHES "^[Rr]elease$")
    add_definitions(-DQT_NO_DEBUG_OUTPUT)
endif()

# Include important features
include(GenerateExportHeader)

# Find Qt
find_package(Qt5Connman REQUIRED)
if(NOT Qt5Connman_FOUND)
    message(FATAL_ERROR "Qt5Connman module is required!")
endif()
find_package(Qt5AccountsService REQUIRED)
if(NOT Qt5AccountsService_FOUND)
    message(FATAL_ERROR "Qt5AccountsService module is required!")
endif()
find_package(Qt5LinguistTools REQUIRED)
if(NOT Qt5LinguistTools_FOUND)
    message(FATAL_ERROR "Qt5LinguistTools module is required!")
endif()
macro_log_feature(Qt5Connman_FOUND "Qt5Connman" "Support for Qt5Connman" "https://bitbucket.org/devonit/qconnman" "")
macro_log_feature(Qt5AccountsService_FOUND "Qt5AccountsService" "Support for Qt5AccountsService" "http://qt-project.org" "")
macro_log_feature(Qt5LinguistTools_FOUND "Qt5LinguistTools" "Support for Qt5LinguistTools" "http://qt-project.org" "")

# Find Vibe libraries
find_package(VibeCore REQUIRED)
if(NOT VibeCore_FOUND)
    message(FATAL_ERROR "VibeCore module is required!")
endif()
find_package(VibeWidgets REQUIRED)
if(NOT VibeWidgets_FOUND)
    message(FATAL_ERROR "VibeWidgets module is required!")
endif()
macro_log_feature(VibeCore_FOUND "VibeCore" "Support for VibeCore" "http://www.maui-project.org" "")
macro_log_feature(VibeWidgets_FOUND "VibeWidgets" "Support for VibeWidgets" "http://www.maui-project.org" "")

# Subdirectories
#add_subdirectory(data)
add_subdirectory(src)

# Display featute log
macro_display_feature_log()
