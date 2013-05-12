/****************************************************************************
 * This file is part of Maui Initial Setup.
 *
 * Copyright (C) 2013 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * Author(s):
 *    Pier Luigi Fiorini
 *
 * $BEGIN_LICENSE:GPL2+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#include <QIcon>

#include <QtConnman/Service>

#include "connman.h"

ConnMan::ConnMan(QObject *parent)
    : Manager(false, parent)
{
    initialize();
}

QString ConnMan::technologyName(Technology *technology) const
{
    if (technology->type() == QStringLiteral("wifi"))
        return tr("Wireless");
    else if (technology->type() == QStringLiteral("ethernet"))
        return tr("Wired");
    return Manager::technologyName(technology);
}

QIcon ConnMan::serviceIcon(Service *service) const
{
    if (service->type().toLower() == QStringLiteral("wifi")) {
        quint8 strength = service->strength();

        if (strength > 80)
            return QIcon::fromTheme("network-wireless-signal-excellent-symbolic");
        else if (strength > 55)
            return QIcon::fromTheme("network-wireless-signal-good-symbolic");
        else if (strength > 30)
            return QIcon::fromTheme("network-wireless-signal-ok-symbolic");
        else if (strength > 5)
            return QIcon::fromTheme("network-wireless-signal-weak-symbolic");
        else
            return QIcon::fromTheme("network-wireless-signal-none-symbolic");
    }

    return Manager::serviceIcon(service);
}

#include "moc_connman.cpp"
