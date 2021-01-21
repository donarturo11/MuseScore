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
#include "languagesstubmodule.h"

#include "modularity/ioc.h"
#include "ui/iuiengine.h"

#include "languagesconfigurationstub.h"
#include "languagesservicestub.h"
#include "languageunpackerstub.h"

using namespace mu::languages;
using namespace mu::framework;

static void languages_init_qrc()
{
    Q_INIT_RESOURCE(languages);
}

std::string LanguagesStubModule::moduleName() const
{
    return "languages_stub";
}

void LanguagesStubModule::registerExports()
{
    ioc()->registerExport<ILanguagesConfiguration>(moduleName(), new LanguagesConfigurationStub());
    ioc()->registerExport<ILanguagesService>(moduleName(), new LanguagesServiceStub());
    ioc()->registerExport<ILanguageUnpacker>(moduleName(), new LanguageUnpackerStub());
}

void LanguagesStubModule::registerResources()
{
    languages_init_qrc();
}

void LanguagesStubModule::registerUiTypes()
{
    ioc()->resolve<ui::IUiEngine>(moduleName())->addSourceImportPath(languages_QML_IMPORT);
}
