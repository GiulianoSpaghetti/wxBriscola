#ifndef GIOCATOREHELPERCPU0_H
#define GIOCATOREHELPERCPU0_H

#include "giocatoreHelperCpu.h"


class giocatoreHelperCpu0 : public giocatoreHelperCpu
{
    public:
        giocatoreHelperCpu0(size_t b):giocatoreHelperCpu(b) {}
        virtual ~giocatoreHelperCpu0() {}
        virtual size_t getLivello() {return 1;}
		virtual size_t gioca(const vector<carta *> &mano, carta *c, size_t iCarta);
    protected:

    private:
};

#endif // GIOCATOREHELPERCPU0_H
