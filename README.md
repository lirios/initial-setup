Initial Setup
=============

[![License](https://img.shields.io/badge/license-GPLv3.0%2B-blue.svg)](https://www.gnu.org/licenses/gpl-3.0.html)
[![GitHub release](https://img.shields.io/github/release/lirios/initial-setup.svg)](https://github.com/lirios/initial-setup)
[![GitHub issues](https://img.shields.io/github/issues/lirios/initial-setup.svg)](https://github.com/lirios/initial-setup/issues)
[![CI](https://github.com/lirios/initial-setup/workflows/CI/badge.svg?branch=develop)](https://github.com/lirios/initial-setup/actions?query=workflow%3ACI)

Initial setup for Liri OS.

## Introduction

The first time a freshly installed system is booted is a special situation.
There is no user account yet and a few basic configuration steps need to be
performed before it can be considered fully usable.

The initial setup mode is an attempt to solve these problems for the
following kind of systems:

 * Device and mobile images
 * Test disk images

OS copies installed by the installer won't need the initial setup mode
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

Qt >= 5.10.0 with at least the following modules is required:

 * [qtbase](http://code.qt.io/cgit/qt/qtbase.git)
 * [qtdeclarative](http://code.qt.io/cgit/qt/qtdeclarative.git)
 * [qtquickcontrols2](http://code.qt.io/cgit/qt/qtquickcontrols2.git)
 * [qttools](http://code.qt.io/cgit/qt/qttools.git/)

The following modules and their dependencies are required:

 * [cmake](https://gitlab.kitware.com/cmake/cmake) >= 3.10.0
 * [cmake-shared](https://github.com/lirios/cmake-shared.git) >= 1.0.0
 * [fluid](https://github.com/lirios/fluid) >= 1.0.0
 * [qtaccountsservice](https://github.com/lirios/qtaccountsservice) >= 1.0.0

## Installation

```sh
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/path/to/prefix ..
make
make install # use sudo if necessary
```

Replace `/path/to/prefix` to your installation prefix.
Default is `/usr/local`.

## Licensing

Licensed under the terms of the GNU General Public License version 3 or,
at your option, any later version.
