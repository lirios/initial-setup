include_directories(${CMAKE_CURRENT_SOURCE_DIR}/pages)

set(SOURCES
    main.cpp
    createlocalaccountdialog.cpp
    pages/language.cpp
    pages/languagemodel.cpp
    pages/languagesortfilterproxymodel.cpp
    pages/network.cpp
    pages/login.cpp
    pages/final.cpp
)

set(UI_SOURCES
    createlocalaccountdialog.ui
    pages/language.ui
    pages/network.ui
    pages/login.ui
    pages/final.ui
)

qt5_wrap_ui(UI_FILES ${UI_SOURCES})

add_executable(maui-initial-setup ${SOURCES} ${UI_FILES})
qt5_use_modules(maui-initial-setup Widgets)
