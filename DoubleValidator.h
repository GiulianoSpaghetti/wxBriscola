#ifndef _DOUBLE_VALIDATOR_H_
#define _DOUBLE_VALIDATOR_H_

#include <stdexcept>
#include <wx/validate.h>
#include <wx/textctrl.h>
#include <wx/wxchar.h>
using namespace std;

class DoubleValidator : public wxValidator {
    private:
        double min, max; //minimo e masimo valore accettabile
        wxString* valore; //valore attualmente contenuto
        void OnChar(wxKeyEvent& event); //valida il valore alla pressione del tasto
        /* Verifica che il valore sia accettabile
            PARAMETRI:
                INPUT: v: nuovo valore da validare
                       valida: true se si sta effettuando la validazione non in real time
                restituisce true se il valore è accettabile, false altrimenti
        */
        virtual bool controllaValore(const wxString& v, bool valida);
        DECLARE_EVENT_TABLE()
    public:
        /*Parameri:
           INPUT v: stringa che conterrà il valore dopo la validazione
                 min: minimo valore accettabile
                 max: massimo valore accettabile
            Lancia un range error se min>max
            Lancia un invalid argument se v e' null
        */
        DoubleValidator(wxString* v, double min, double max) throw (range_error*, invalid_argument*);
        DoubleValidator(const DoubleValidator& val);
        virtual DoubleValidator* Clone(void) const {return (new DoubleValidator(*this));};
        virtual bool TransferToWindow(void);
        virtual bool TransferFromWindow(void);
        virtual bool Validate(wxWindow *parent);
};

#endif
