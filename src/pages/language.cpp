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

#include <QApplication>
#include <QDebug>

#include "language.h"
#include "ui_language.h"
#include "languagemodel.h"
#include "languagesortfilterproxymodel.h"

Language::Language(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::Language)
    , m_lang(QLocale::C)
{
    ui->setupUi(this);

    m_proxyModel = new LanguageSortFilterProxyModel(this);
    m_model = new LanguageModel(this);
    m_proxyModel->setSourceModel(m_model);
    m_proxyModel->setSortRole(Qt::DisplayRole);
    m_proxyModel->setSortLocaleAware(true);
    m_proxyModel->setSortCaseSensitivity(Qt::CaseSensitive);
    ui->languages->setModel(m_proxyModel);

    connect(ui->languages->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this, SLOT(languageSelected(QModelIndex, QModelIndex)));
    connect(ui->showAll, SIGNAL(toggled(bool)),
            this, SLOT(toggleShowAll(bool)));
}

Language::~Language()
{
    delete ui;
}

QLocale::Language Language::language() const
{
    return m_lang;
}

bool Language::isComplete() const
{
    // A language must be selected to consider this page complete
    return m_lang != QLocale::C;
}

void Language::changeEvent(QEvent *event)
{
    switch (event->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }

    QWizardPage::changeEvent(event);
}

void Language::languageSelected(const QModelIndex &current, const QModelIndex &previous)
{
    // Turns out that when the page starts a spurious selection event
    // is trigger with an invalid previous index
    if (!previous.isValid())
        return;

    if (current.isValid()) {
        // Save the language before going to the next page
        m_lang = (QLocale::Language)m_model->data(current, LanguageModel::LanguageRole).toInt();
        QApplication::postEvent(this, new QEvent(QEvent::LanguageChange));
        emit completeChanged();
    }
}

void Language::toggleShowAll(bool toggle)
{
    m_proxyModel->setFilterEnabled(!toggle);
}
