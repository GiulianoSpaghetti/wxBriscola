/**********************************************************************************
 *   Copyright (C) 2019 by Giulio Sorrentino                                      *
 *   gsorre84@gmail.com                                                           *
 *                                                                                *
 *   This program is free software; you can redistribute it and/or modify         *
 *   it under the terms of the GNU General Public License as published by         *
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
    wxLocale *m_locale;
    int loc;
    wxString s=wxFileName::GetPathSeparator();
    wxString pathTraduzioni=wxPathOnly(argv[0])+s+"locale";
    wxConfig *config=new wxConfig(GetAppName()); //lettura delle opzioni

    if (!config->Read("locale", &loc))
        loc=wxLANGUAGE_ITALIAN;

   if(wxLocale::IsAvailable(loc)) {
        m_locale=new wxLocale( loc, wxLOCALE_DONT_LOAD_DEFAULT );

        #ifdef __WXGTK__
            m_locale->AddCatalogLookupPathPrefix(wxT("/usr"));
            m_locale->AddCatalogLookupPathPrefix(wxT("/usr/local"));
            wxStandardPaths* paths = (wxStandardPaths*) &wxStandardPaths::Get();
            wxString prefix = paths->GetInstallPrefix();
            m_locale->AddCatalogLookupPathPrefix( prefix );
        #endif

        m_locale->AddCatalogLookupPathPrefix(pathTraduzioni);
        m_locale->AddCatalog("wxBriscola");
        m_locale->AddCatalog("wxstd");

        if(!m_locale->IsOk()) {
            wxMessageBox(_("Si e' verificato un errore nella selezione del linguaggio."), _("Errore"), wxICON_ERROR);
            delete m_locale;
            loc = wxLANGUAGE_ITALIAN;
            m_locale = new wxLocale(loc);
        }
    } else {
        wxMessageBox(_("Il linguaggio selezionato non e' supportato dal sistema. Verra' usato l'italiano."), _("Errore"), wxICON_ERROR);
        loc = wxLANGUAGE_ITALIAN;
        m_locale = new wxLocale(loc);
    }

    try {
        f=new BriscoFrame(loc, config, pathTraduzioni);
    } catch (invalid_argument &e) {
        return false;
    }
	SetTopWindow(f);
	f->Show(true);
	return true;
}
