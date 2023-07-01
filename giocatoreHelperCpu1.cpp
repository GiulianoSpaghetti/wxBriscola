/**********************************************************************************
 *   Copyright (C) 2022 by Giulio Sorrentino                                      *
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

#include "giocatoreHelperCpu1.h"
size_t giocatoreHelperCpu1::gioca(const vector<carta *> &mano, carta *c, size_t iCarta) {
	size_t i=0; //aggiunge un comportamento un po' piu' casuale
	if (mano.size()==0)
		throw range_error("Chiamata a giocatoreHelperCpu::gioca(mano, c) con mano.size()==0");
	if (c==NULL)
		throw range_error("Chiamata a giocatoreHelperUtente::gioca(vector<carta *>, carta *) con carta==NULL");

    if (!briscola->stessoSeme(c)) { //se la carta giocata non e' dello stesso seme di briscola
        if ((i=getSoprataglio(mano, c, true))<mano.size()) //se si puo' sopratagliare
            return i; //soprataglia
        if (c->getPunteggio()>0 && (i=getBriscola(mano))<mano.size()) {//se non si puo' sopratagliare e la carta ha un punteggio e si ha una carta di briscola
            if (c->getPunteggio()>4) //se la carta giocata e' un carico
                return i; //si gioca la briscola
            if (mano[i]->getPunteggio()>0) //se la carta che si vuole giocare e' briscola ed ha un punteggio
                    return i;
        }
    }
    i=0; //se non si puo' fare niente si gioca la carta piu' piccola
    return i;

}
