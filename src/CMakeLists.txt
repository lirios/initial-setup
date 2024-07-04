qt_add_executable(InitialSetup
    WIN32 MACOSX_BUNDLE
    MANUAL_FINALIZATION
    main.cpp
)

set_target_properties(InitialSetup PROPERTIES
    OUTPUT_NAME
        "liri-initial-setup"
)

qt_finalize_executable(InitialSetup)

target_compile_definitions(InitialSetup PRIVATE
    QT_NO_CAST_FROM_ASCII
    QT_NO_FOREACH
    INITIAL_SETUP_VERSION="${PROJECT_VERSION}"
)

target_link_libraries(InitialSetup PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
    Qt::QuickControls2
)

install(TARGETS InitialSetup
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
