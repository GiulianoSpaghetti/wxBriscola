/**********************************************************************************
 *   Copyright (C) 2020 by Giulio Sorrentino                                      *
 *   gsorre84@gmail.com                                                           *
 *                                                                                *
 *   This program is free software; you can redistribute it and/or modify         *
 *   it under the terms of the GNU Lesser General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or            *
 *   (at your option) any later version.                                          *
 *                                                                                *
 *   This program is distributed in the hope that it will be useful,              *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of               *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                *
 *   GNU General Public License for more details.                                 *
 *                                                                                *
 *   You should have received a copy of the GNU General Public License            *
 *   along with this program; if not, write to the                                *
 *   Free Software Foundation, Inc.,                                              *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.                    *
 **********************************************************************************/

#include "BriscoApp.h"

bool BriscoApp::OnInit() {
    if (!wxApp::OnInit())
        return false;
    int loc;
    wxString s=wxFileName::GetPathSeparator();
    wxString pathTraduzioni=wxPathOnly(argv[0])+s+"locale";
    wxConfig *config=new wxConfig(GetAppName()); //lettura delle opzioni

    if (!config->Read("locale", &loc))
        loc=wxLANGUAGE_ITALIAN;

    wxLocale *m_locale;
    m_locale=new wxLocale( loc, wxLOCALE_DONT_LOAD_DEFAULT );
    m_locale->AddCatalog("fileutils");
    wxLocale::AddCatalogLookupPathPrefix(pathTraduzioni);
    if (!m_locale->AddCatalog("wxBriscola"))
       wxMessageBox(_("Impossibile trovare il catalogo del programma. Il programma si avviera' in italiano."), _("Attenzione"), wxICON_EXCLAMATION);
     m_locale->AddCatalog("wxstd");
     m_locale->AddCatalog("wxmsw");

    try {
        f=new BriscoFrame(loc, config, pathTraduzioni);
    } catch (invalid_argument &e) {
        return false;
    }
	SetTopWindow(f);
	f->Show(true);
	return true;
}
