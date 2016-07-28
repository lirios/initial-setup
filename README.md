Initial Setup
=============

[![ZenHub.io](https://img.shields.io/badge/supercharged%20by-zenhub.io-blue.svg)](https://zenhub.io)

[![License](https://img.shields.io/badge/license-GPLv3.0%2B-blue.svg)](https://www.gnu.org/licenses/gpl-3.0.html)
[![GitHub release](https://img.shields.io/github/release/qmlos/initial-setup.svg)](https://github.com/qmlos/initial-setup)
[![Build Status](https://travis-ci.org/qmlos/initial-setup.svg?branch=develop)](https://travis-ci.org/qmlos/initial-setup)
[![GitHub issues](https://img.shields.io/github/issues/qmlos/initial-setup.svg)](https://github.com/qmlos/initial-setup/issues)
[![Maintained](https://img.shields.io/maintenance/yes/2016.svg)](https://github.com/qmlos/initial-setup/commits/develop)

Initial setup for qmlOS.

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

Qt >= 5.7.0 with at least the following modules is required:

 * [qtbase](http://code.qt.io/cgit/qt/qtbase.git)
 * [qtdeclarative](http://code.qt.io/cgit/qt/qtdeclarative.git)
 * [qtquickcontrols2](http://code.qt.io/cgit/qt/qtquickcontrols2.git)
 * [qttools](http://code.qt.io/cgit/qt/qttools.git/)

The following modules and their dependencies are required:

 * [qtaccountsservice](https://github.com/hawaii-desktop/qtaccountsservice)

## Installation

From the root of the repository, run:

```sh
mkdir build; cd build
cmake .. -DKDE_INSTALL_USE_QT_SYS_PATHS=ON
make
make install # use sudo if necessary
```

On the `cmake` line, you can specify additional configuration parameters:

 * `-DCMAKE_INSTALL_PREFIX=/path/to/install` (for example, `/opt/qmlos` or `/usr`)
 * `-DCMAKE_BUILD_TYPE=<build_type>`, where `<build_type>` is one of:
   * **Debug:** debug build
   * **Release:** release build
   * **RelWithDebInfo:** release build with debugging information
