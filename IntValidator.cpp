#include "IntValidator.h"

BEGIN_EVENT_TABLE(IntValidator, wxValidator)
EVT_CHAR(IntValidator::OnChar)
END_EVENT_TABLE()

IntValidator::IntValidator(wxString *v, long min, long max) {
    if (!v)
        throw new invalid_argument("");
    if (min>max)
        throw new range_error("");
    valore=v;
    this->min=min;
    this->max=max;
}

IntValidator::IntValidator(const IntValidator& val) {
    Copy(val);
    min = val.min;
    max = val.max;
    valore = val.valore;
}

void IntValidator::OnChar(wxKeyEvent& event) {
    bool skip = true; //se l'evento dev'essere ignorato dalla funzione di gestione di default
    wxChar codice = event.GetUnicodeKey(); //codice del tasto
	bool controlla=wxIsalnum(codice) || codice =='-';
    if(controlla) {
        wxString vecchio, nuovo; //valore contenuto nella textbox e valore che diventera' quello della textbox
        if(!wxIsdigit(codice) && codice != '-')
            skip = false;
        else {
            wxTextCtrl *txt = wxDynamicCast(m_validatorWindow, wxTextCtrl);
            vecchio << txt->GetValue();
            long inizio, fine; //inizio e fine dell'eventuale selezione
            txt->GetSelection(&inizio, &fine); //prendiamo l'eventuale selezione dei caratteri
            nuovo=vecchio.Mid(0, (size_t) inizio); //trasformiamo il vecchio valore nel nuovo
            nuovo.Append((wxChar) codice);
            nuovo.Append(vecchio.Mid((size_t) fine));
            skip = controllaValore(nuovo, false); //verifichiamo che sia accettabile
        }
    }
    if(skip)
        event.Skip();
    else
         wxBell();
}

bool IntValidator::controllaValore(const wxString& v, bool valida) {
    if(!valida && v.Cmp(_("-")) == 0) { //se stiamo effettuando la validazione in real time ed il carattere e' solo un "-"
        if(min >= 0)
            return false;
        else
            return true;
    }
    long numero = 0;
    if(!v.ToLong(&numero)) //se il valore non e' convertibile
        return false;
    if(numero > max)
        return false;
    if(valida) { //se non stiamo effettuando la validazione in real time
        if(numero < min)
            return false;
        return true;
    }
    if(numero < min) { //se stiamo effettuando la validazione in real time dobbiamo verificare che il valore
        //inserito possa diventare con l'aggiunta di ulteriori caratteri il minimo
        wxString minStr;
        minStr.Printf(_("%ld"), min);
        minStr.Truncate(v.Length());
        long tmpMin;
        if(minStr.ToLong(&tmpMin)) {
            if(numero < tmpMin)
                return false;
            return true;
        } else
            return false;
    }
    return true;
}


bool IntValidator::Validate(wxWindow *parent) {
    wxTextCtrl *txt;
    if (!(txt=wxDynamicCast(m_validatorWindow, wxTextCtrl)))
        return false;
    wxString value = txt->GetValue();
    int i = controllaValore(value, true);
    if (i!=0)
        wxBell();
    return true;
}

bool IntValidator::TransferToWindow() {
    wxTextCtrl *txt;
    if (!(txt=wxDynamicCast(m_validatorWindow, wxTextCtrl)))
        return false;
    txt->SetValue(*valore);
    return true;
}

bool IntValidator::TransferFromWindow() {
    wxTextCtrl *txt;
    if (!(txt=wxDynamicCast(m_validatorWindow, wxTextCtrl)))
        return false;
    *valore=txt->GetValue();
    return true;
}
