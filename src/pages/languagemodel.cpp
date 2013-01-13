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

#include "languagemodel.h"

LanguageModel::LanguageModel(QObject *parent)
    : QAbstractListModel(parent)
{
    for (int lang = (int)QLocale::AnyLanguage; lang <= (int)QLocale::LastLanguage; lang++) {
        if (lang == (int)QLocale::C)
            continue;

        beginInsertRows(QModelIndex(), m_list.count(), m_list.count());
        m_list << (QLocale::Language)lang;
        endInsertRows();
    }
}

int LanguageModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_list.size();
}

QVariant LanguageModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    QLocale::Language lang = m_list.toList().at(index.row());
    QLocale locale(lang);

    switch (role) {
        case Qt::DisplayRole:
            if (locale.nativeLanguageName().isEmpty())
                return locale.name();
            return locale.nativeLanguageName();
        case LanguageRole:
            return lang;
        default:
            break;
    }

    return QVariant();
}

#include "moc_languagemodel.cpp"
