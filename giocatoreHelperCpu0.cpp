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

#include "giocatoreHelperCpu0.h"
size_t giocatoreHelperCpu0::gioca(const vector<carta *> &mano, carta *c, size_t iCarta) {
	if (mano.size()==0)
		throw range_error("Chiamata a giocatoreHelperCpu::gioca(mano, c) con mano.size()==0");
	if (c==NULL)
		throw range_error("Chiamata a giocatoreHelperUtente::gioca(vector<carta *>, carta *) con carta==NULL");

	size_t i=0; //aggiunge un comportamento un po' piu' casuale
	i=getBriscola(mano);
	if (i==mano.size())
	    i=0; //se non si puo' fare niente si gioca la carta piu' piccola
	return i;
}
