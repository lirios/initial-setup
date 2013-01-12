Maui Initial Setup
==================

The first time a freshly installed system is booted is a special situation.
There is no user account yet and a few basic configuration steps need to be
performed before it can be considered fully usable.

The initial setup mode is an attempt to solve these problems for the
following kind of systems:

 * Live medias
 * Test disk images

Maui copies installed by the installer won't need the initial setup mode
because users will configure whatever they need during the installation.

This application will offers a series of steps to:

 1. Select your language
 2. Connect to the network
 3. Create a new user account
 4. Set the right location and timezone

In terms of user experience, we want the initial setup to seamlessly switch
to the regular user session. In particular, we don't want to make the user
enter his credentials again on the login screen.

## Dependencies

In order to build and install this application you will need:
 * Qt 5.x (http://qt-project.org/wiki/Building-Qt-5-from-Git)
 * AccountsService Qt AddOn (https://github.com/hawaii-desktop/qt-accountsservice-addon)

## Build

Building this application is a piece of cake.

Assuming you are in the source directory, just create a build directory
and run cmake:

    mkdir build
    cd build
    cmake -DCMAKE_INSTALL_PREFIX=/usr ..

To do a debug build the last command can be:

    cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Debug ..

To do a release build instead it can be:

    cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release ..

If not passed, the CMAKE_INSTALL_PREFIX parameter defaults to /usr/local.
You have to specify a path that fits your needs, /usr is just the most
common path for packagers.

The CMAKE_BUILD_TYPE parameter allows the following values:

    Debug: debug build
    Release: release build
    RelWithDebInfo: release build with debugging information

## Installation

It's easy really, it's just a matter of typing:

    make install

from the build directory.
