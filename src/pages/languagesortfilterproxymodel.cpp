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

#include "languagesortfilterproxymodel.h"
#include "languagemodel.h"

LanguageSortFilterProxyModel::LanguageSortFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
    , m_filter(true)
{
    m_commonLanguages.append(QLocale::English);
    m_commonLanguages.append(QLocale::German);
    m_commonLanguages.append(QLocale::French);
    m_commonLanguages.append(QLocale::Spanish);
    m_commonLanguages.append(QLocale::Italian);
    m_commonLanguages.append(QLocale::Chinese);
}

bool LanguageSortFilterProxyModel::isFilterEnabled() const
{
    return m_filter;
}

void LanguageSortFilterProxyModel::setFilterEnabled(bool flag)
{
    m_filter = flag;
    invalidateFilter();
}

bool LanguageSortFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    // If we're not filtering it means that we're going to show all languages
    if (!m_filter)
        return true;

    QModelIndex index = sourceModel()->index(source_row, 0, source_parent);

    QLocale::Language lang = (QLocale::Language)sourceModel()->data(index, LanguageModel::LanguageRole).toInt();
    return m_commonLanguages.contains(lang);
}

#include "moc_languagesortfilterproxymodel.cpp"
