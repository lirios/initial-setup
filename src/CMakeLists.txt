liri_add_executable(InitialSetup
    OUTPUT_NAME
        "liri-initial-setup"
    SOURCES
        main.cpp
    DEFINES
        QT_NO_CAST_FROM_ASCII
        QT_NO_FOREACH
        INITIAL_SETUP_VERSION="${PROJECT_VERSION}"
    LIBRARIES
        Qt5::Core
        Qt5::Gui
        Qt5::Qml
)

liri_finalize_executable(InitialSetup)
