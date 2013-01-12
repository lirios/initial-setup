include_directories(${CMAKE_CURRENT_SOURCE_DIR}/pages)

set(SOURCES
    main.cpp
    pages/language.cpp
)

set(UI_SOURCES
    pages/language.ui
)

qt5_wrap_ui(UI_FILES ${UI_SOURCES})

add_executable(maui-initial-setup ${SOURCES} ${UI_FILES})
qt5_use_modules(maui-initial-setup Widgets)
