/**********************************************************************************
 *   Copyright (C) 2015 by Giulio Sorrentino                                      *
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

#include "BriscoFrame.h"

BEGIN_EVENT_TABLE(BriscoFrame, wxFrame)
EVT_MENU(wxID_EXIT, BriscoFrame::onEsci)
EVT_MENU(ID_NUOVA_PARTITA, BriscoFrame::onNuovaPartita)
EVT_MENU(ID_OPZIONI, BriscoFrame::onOpzioni)
EVT_MENU(ID_FONT, BriscoFrame::onFont)
EVT_MENU(wxID_ABOUT, BriscoFrame::onInfo)
EVT_MENU(ID_SITOWEB, BriscoFrame::onSitoWeb)
//EVT_MENU(ID_AGGIORNAMENTO, BriscoFrame::onAggiornamenti)
END_EVENT_TABLE()


BriscoFrame::BriscoFrame(int l, wxConfig *c, wxString path) : wxFrame(NULL, wxID_ANY, wxT("wxBriscola"), wxDefaultPosition,wxSize(600,450),wxMINIMIZE_BOX | wxRESIZE_BORDER | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN) {
    wxString nomeUtente, nomeCpu;
	config=c; //lettura delle opzioni
    bool briscolaDaPunti, ordinaCarte, avvisaFineTallone;
    int millisecondi;
	if (!config->Read(wxT("faiGiocoCartaAlta"), &cartaAlta))
		cartaAlta=true;
	if (!config->Read(wxT("nomeMazzo"), &nomeMazzo))
		nomeMazzo=wxT("Napoletano");
    if (!config->Read(wxT("aggiornamenti"), &aggiornamenti))
        aggiornamenti=false;
    if (!config->Read(wxT("abilitaBriscolaAlta"), &briscolaDaPunti))
		briscolaDaPunti=true;
	if (!config->Read(wxT("ordinaCarteUmano"), &ordinaCarte))
		ordinaCarte=true;
	if (!config->Read(wxT("millisecondi"), &millisecondi))
		millisecondi=1000;
	if (!config->Read(wxT("avvisaFineTallone"), &avvisaFineTallone))
		avvisaFineTallone=true;
	if (!config->Read(wxT("nomeMazzo"), &nomeMazzo))
		nomeMazzo=wxT("Napoletano");
	if (!config->Read(wxT("avvisaFineTallone"), &avvisaFineTallone))
        avvisaFineTallone=true;
    if (!config->Read(wxT("nomeCpu"), &nomeCpu))
        nomeCpu=wxT("Cpu");
    if (!config->Read(wxT("nomeUtente"), &nomeUtente))
        nomeUtente=wxT("Utente");
    loc=l;
	paginaWeb=wxT("http://numerone.altervista.org/blog/2013/06/wxbriscola/");
	versione=wxT("0.3.1");
    leggiFont();
    pathTraduzioni=path;
	client.SetHeader(_T("Content-type"), _T("text/html; charset=utf-8"));
    client.SetTimeout(10);
/*    if (aggiornamenti) {
        wxString s;
	try {
        	if (Aggiornamenti(s)) {
            	wxMessageBox(_("Sono presenti aggiornamenti, il programma aprira' la pagina per il download."), _("Informazioni"), wxICON_INFORMATION);
            	wxLaunchDefaultBrowser(paginaWeb);
            }
        } catch (domain_error e) {
            wxMessageBox(e.what(), _("Errore"), wxOK|wxICON_ERROR);
        }
    */
	el=new elaboratoreCarteBriscola(true);
	br=new cartaHelperBriscola(el);
	try {
		carta::inizializza(40, br, nomeMazzo);
	} catch (invalid_argument &e) {
		wxMessageBox(wxString(e.what(), wxConvUTF8)+_(" Il programma verra' chiuso."), _("Errore"), wxOK | wxICON_ERROR);
		delete config;
		throw;
		return;
	}
	giocoCartaAlta();
	p=new BriscoPanel(this, el, br, primaUtente,briscolaDaPunti, ordinaCarte, millisecondi, avvisaFineTallone, nomeMazzo, nomeUtente, nomeCpu, font);
	p->SetFocus();
	aggiungiMenu();
	p->getDimensioni(dim.x, dim.y);
	SetClientSize(dim.x, dim.y);
}


void BriscoFrame::aggiungiMenu() {
    wxMenuBar *m=new wxMenuBar();
    wxMenu *menu=new wxMenu(), *menu1=new wxMenu();
	menuMazzi=new wxMenu();
	menuTraduzioni=new wxMenu();
    menu->Append(ID_NUOVA_PARTITA, _("&Nuova Partita")+wxT("\tALT+N"), _("Inizia una nuova partita senza concludere l'attuale"));
    menu->Append(ID_OPZIONI, _("&Opzioni")+wxT("\tALT+O"), _("Imposta le opzioni del programma"));
	menu->Append(ID_FONT, _("&Font")+wxT("\tALT+F"), _("Imposta il font utilizzato"));
    menu->Append(wxID_EXIT, _("&Esci")+wxT("\tALT+Q"), _("Chiudi il programma"));
    m->Append(menu, _("&File"));
	getMenuMazzi(menuMazzi);
	m->Append(menuMazzi, _("Mazzi"));
	getMenuTraduzioni(menuTraduzioni);
	m->Append(menuTraduzioni, _("Traduzioni"));
    //menu1->Append(ID_AGGIORNAMENTO, _("&Verifica aggiornamenti")+wxT("\tALT+A"), _("Verifica aggiornamenti per il programma"));
    menu1->Append(ID_SITOWEB, _("&Sito web del gioco")+wxT("\tALT+S"), _("Apre il sito web ufficiale"));
    menu1->Append(wxID_ABOUT, _("&Informazioni")+wxT("\tALT+I"), _("Per segnalare un bug o contattare l'autore"));
    m->Append(menu1, wxT("?"));
    SetMenuBar(m);
}

void BriscoFrame::onEsci(wxCommandEvent& WXUNUSED(evt)) {
    Close();
}

void BriscoFrame::onInfo(wxCommandEvent& WXUNUSED(evt)) {
	wxAboutDialogInfo info;
	info.AddDeveloper(wxT("Giulio Sorrentino <gsorre84@gmail.com>"));
	info.SetCopyright(wxT("\u00a9 2019 Giulio Sorrentino"));
	info.SetLicense(_("GPL v3 o (a tua discrezione) qualsiasi versione successiva.\nLe immagini delle carte sono di proprieta' della Modiano"));
	info.SetName(wxT("wxBriscola"));
	info.SetVersion(versione);
	info.SetWebSite(wxT("http://numerone.altervista.org"));
	wxAboutBox(info);
}

void BriscoFrame::onNuovaPartita(wxCommandEvent& WXUNUSED(evt)) {
	p->nuovaPartita(true, true);
}

void BriscoFrame::onOpzioni(wxCommandEvent& WXUNUSED(evt)) {
	OpzioniFrame *f=new OpzioniFrame(this, p->getNomeUtente(), p->getNomeCpu(), p->getFlagBriscola(), p->getFlagOrdina(), p->getFlagAvvisa(), cartaAlta, p->getIntervallo(), aggiornamenti);
    if (f->ShowModal()==wxID_OK) {
		p->setNomeUtente(f->getNomeUtente());
		p->setNomeCpu(f->getNomeCpu());
		p->setFlagBriscola(f->getBriscolaAlta());
		p->setFlagOrdina(f->getOrdinaCarte());
		p->setFlagAvvisa(f->getAbilitaAvviso());
		p->setIntervallo(f->getSecondi());
		aggiornamenti=f->getFlagAggiornamenti();
		cartaAlta=f->getFlagCartaAlta();

    }
    delete f;
}

void BriscoFrame::onFont(wxCommandEvent& WXUNUSED(evt)) {
	wxFontData fd=wxFontData();
	wxPoint dim;
	fd.SetInitialFont(p->GetFont());
	wxFontDialog *d=new wxFontDialog(this, fd);
	if (d->ShowModal()==wxID_OK) {
		p->SetFont(d->GetFontData().GetChosenFont());
		p->getDimensioni(dim.x, dim.y);
		SetClientSize(dim.x, dim.y);
		p->Refresh();
	}
	delete d;
}

void BriscoFrame::onSitoWeb(wxCommandEvent& WXUNUSED(evt)) {
    wxLaunchDefaultBrowser(wxT("http://numerone.altervista.org"));
}

/*bool BriscoFrame::Aggiornamenti(wxString &nuovaVersione) throw (std::domain_error) {
    bool aggiornamenti=false;
    wxString errore=wxEmptyString;
    if (client.Connect(wxT("numerone.altervista.org"))) {
        if (client.GetError() == wxPROTO_NOERR)
        {
            wxInputStream *stream = client.GetInputStream(_T("/wxbriscola.html"));
            if (stream==wxNullPtr) {
                errore=_("Si e' verificato un errore nel recuperare le informazioni");

            }
	    else {
            	wxStringOutputStream out_stream(&nuovaVersione);
            	stream->Read(out_stream);
            	nuovaVersione=nuovaVersione.RemoveLast();
            	aggiornamenti=!nuovaVersione.IsSameAs(versione);
            	delete stream;
		}
        }
        client.Close();
    } else {
        errore=_("Si e' verificato un errore nello stabilire la connessione");
    }
    if (errore!=wxEmptyString)
        throw std::domain_error(std::string(errore.mb_str()));
    return aggiornamenti;
}

void BriscoFrame::onAggiornamenti(wxCommandEvent& WXUNUSED(evt)) {
    wxString versioneOttenuta;
    try {
    	if (!Aggiornamenti(versioneOttenuta))
        	wxMessageBox(_("Stai usando l'ultima versione di wxBriscola"), _("Complimenti"), wxICON_INFORMATION);
    	else if (wxMessageBox(_("La versione che stai usando e' la ")+versione+_(". Sul sito e' presente la ")+versioneOttenuta+wxT(".\n")+_("Vuoi aprire il browser per scaricarlo ora?"), _("Aggiornamento disponibile"), wxICON_INFORMATION | wxYES_NO)==wxYES)
            wxLaunchDefaultBrowser(paginaWeb);
	} catch (std::domain_error e) {
	        wxMessageBox(wxString(e.what())+wxT(". ")+_("Riprovare piu' tardi"), _("Errore"), wxOK|wxICON_ERROR);
	}
}*/

void BriscoFrame::getMenuMazzi(wxMenu *menu) {
	wxDir dir(carta::getPathMazzi());
    wxString nome;
    if ( !dir.IsOpened() ) {
        return;
    }


    bool continua = dir.GetFirst(&nome, wxEmptyString, wxDIR_DIRS);
	int id;
    while (continua) {
		id=wxNewId();
		menu->AppendRadioItem(id, nome, _("Carica il mazzo corrispondente"));
        menu->Check(id, nome.IsSameAs(nomeMazzo));
        continua = dir.GetNext(&nome);
		Connect(id, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(BriscoFrame::onMenuMazzi));

    }
}


void BriscoFrame::getMenuTraduzioni(wxMenu *menu) {
    wxString nome;
    wxDir dir(pathTraduzioni);
    const wxLanguageInfo *lang;
	if (!dir.IsOpened())
        return;
    bool continua=dir.GetFirst(&nome, wxEmptyString, wxDIR_DIRS);
	while (continua) {
        lang=wxLocale::FindLanguageInfo(nome);
        if (lang!=NULL && wxFileExists(dir.GetName()+wxFileName::GetPathSeparator()+nome+wxFileName::GetPathSeparator()+wxT("LC_MESSAGES")+wxFileName::GetPathSeparator()+wxT("wxBriscola.mo")))
        {
            idMenuTraduzioni.Add(wxNewId());
            menu->AppendRadioItem(idMenuTraduzioni.Last(), lang->Description, _("Carica il file del linguaggio corrispondente"));
            menu->Check(idMenuTraduzioni.Last(), lang->Language==loc);
            idTraduzioni.Add(lang->Language);
            Connect(idMenuTraduzioni.Last(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(BriscoFrame::OnMenuTraduzioni));
        }
        continua=dir.GetNext(&nome);
    }
}

void BriscoFrame::onMenuMazzi(wxCommandEvent& evt) {
	wxMenuItem *m=menuMazzi->FindItem(evt.GetId());
	wxPoint dim;
	if (m==NULL)
		wxMessageBox(_("Impossibile portare a termine l'operazione"), _("Errore"), wxOK|wxICON_ERROR);
	else {
        nomeMazzo=m->GetItemLabel();
		p->caricaImmagini(nomeMazzo);
		p->getDimensioni(dim.x, dim.y);
		SetClientSize(dim.x,dim.y);
	}
}

void BriscoFrame::OnMenuTraduzioni(wxCommandEvent &evt) {
    loc=idTraduzioni[idMenuTraduzioni.Index(evt.GetId())];
    wxMessageBox(_("Il programma si chiudera'. Riaprirlo di nuovo per cambiare il linguaggio."), _("Attenzione"), wxICON_INFORMATION | wxOK);
    Close();
}


void BriscoFrame::giocoCartaAlta() {
	if (cartaAlta) { //se si deve giocare alla carta alta
		CartaAltaFrame f(this, nomeMazzo, font);
		f.ShowModal();
		primaUtente=f.giocaPrimaUtente();
	} else
		primaUtente=true;
}

void BriscoFrame::leggiFont() {
    wxString f;
	bool defaultFont=true;
		if (config->Read(wxT("font"), &f)) {
		font=new wxFont();
		defaultFont=!font->SetNativeFontInfo(f);
	}
	if (defaultFont)
		font=new wxFont(16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
}

BriscoFrame::~BriscoFrame() {
	config->Write(wxT("faiGiocoCartaAlta"), cartaAlta);
	config->Write(wxT("nomeMazzo"), nomeMazzo);
    config->Write(wxT("aggiornamenti"), aggiornamenti);
    config->Write(wxT("nomeCpu"), p->getNomeCpu());//salvataggio delle opzioni
    config->Write(wxT("nomeUtente"), p->getNomeUtente());
    config->Write(wxT("abilitaBriscolaAlta"), p->getFlagBriscola());
    config->Write(wxT("ordinaCarteUmano"), p->getFlagOrdina());
    config->Write(wxT("millisecondi"), p->getMilliSecondi());
	config->Write(wxT("avvisaFineTallone"), p->getFlagAvvisa());
	config->Write(wxT("nomeMazzo"), nomeMazzo);
	config->Write(wxT("font"), p->GetFont().GetNativeFontInfoDesc());
	config->Write(wxT("locale"), loc);
    delete config;
	delete font;
}
