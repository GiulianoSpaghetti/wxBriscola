#ifndef _DOUBLE_VALIDATOR_H_
#define _DOUBLE_VALIDATOR_H_

#include <wx/wxprec.h>
#include <stdexcept>
#include <wx/validate.h>
#include <wx/textctrl.h>
#include <wx/wxchar.h>
using namespace std;

// Questa classe rappresenta un validatore che accetta solo numeri interi in un range ben determinati

class IntValidator : public wxValidator {
    private:
        long min, max; //minimo e masimo valore accettabile
        wxString* valore; //valore attualmente contenuto
        void OnChar(wxKeyEvent& event); //valida il valore alla pressione del tasto
        /* Verifica che il valore sia accettabile
            PARAMETRI:
                INPUT: v: nuovo valore da validare
                       valida: true se si sta effettuando la validazione non in real time
                restituisce true se il valore Ë accettabile, false altrimenti
        */
        virtual bool controllaValore(const wxString& v, bool valida);
        DECLARE_EVENT_TABLE()
    public:
        /*Parameri:
           INPUT v: stringa che conterra' il valore dopo la validazione
                 min: minimo valore accettabile
                 max: massimo valore accettabile
            Lancia un range error se min>max
            Lancia un invalid argument se v e' null
        */
        IntValidator(wxString* v, long min, long max);
        IntValidator(const IntValidator& val);
        virtual IntValidator* Clone(void) const {return (new IntValidator(*this));};
        virtual bool TransferToWindow(void);
        virtual bool TransferFromWindow(void);
        virtual bool Validate(wxWindow *parent);
};

#endif
