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

#include <QDebug>

#include <QtConnman/Agent>

#include "network.h"
#include "ui_network.h"
#include "connman.h"

Network::Network(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::Network)
    , m_agent(0)
    , m_curTechnology(0)
{
    ui->setupUi(this);

    m_manager = new ConnMan(this);

    ui->technologies->setModel(m_manager);

    connect(ui->technologies, SIGNAL(currentIndexChanged(int)),
            this, SLOT(technologySelected(int)));
    connect(ui->technologyEnabled, SIGNAL(toggled(bool)),
            this, SLOT(technologyEnabled(bool)));
}

Network::~Network()
{
    delete ui;
}

void Network::technologySelected(int index)
{
    QModelIndex current = m_manager->index(index, 0);

    ManagerNode *node = static_cast<ManagerNode *>(current.internalPointer());
    if (!node || !node->isTechnology()) {
        qDebug() << "Invalid technology item selected!";
        return;
    }

    m_curTechnology = node->object<Technology *>();
    ui->technologyEnabled->setChecked(m_curTechnology->isPowered());

    ui->networks->setModel(m_manager);
    ui->networks->setRootIndex(current);
}

void Network::technologyEnabled(bool enabled)
{
    m_curTechnology->setPowered(enabled);
}

#include "moc_network.cpp"
