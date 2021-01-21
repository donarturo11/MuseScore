//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2020 MuseScore BVBA and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//=============================================================================
#ifndef MU_LANGUAGES_LANGUAGESCONFIGURATIONSTUB_H
#define MU_LANGUAGES_LANGUAGESCONFIGURATIONSTUB_H

#include "languages/ilanguagesconfiguration.h"

namespace mu::languages {
class LanguagesConfigurationStub : public ILanguagesConfiguration
{
public:
    QString currentLanguageCode() const override;
    Ret setCurrentLanguageCode(const QString& languageCode) const override;

    QUrl languagesUpdateUrl() const override;
    QUrl languageFileServerUrl(const QString& languageCode) const override;

    ValCh<LanguagesHash> languages() const override;
    Ret setLanguages(const LanguagesHash& languages) const override;

    io::path languagesSharePath() const override;
    io::path languagesDataPath() const override;

    io::paths languageFilePaths(const QString& languageCode) const override;
    io::path languageArchivePath(const QString& languageCode) const override;
};
}

#endif // MU_LANGUAGES_LANGUAGESCONFIGURATIONSTUB_H
