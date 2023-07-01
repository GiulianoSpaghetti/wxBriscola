#ifndef GIOCATOREHELPERCPU1_H
#define GIOCATOREHELPERCPU1_H

#include "giocatoreHelperCpu.h"


class giocatoreHelperCpu1 : public giocatoreHelperCpu
{
    public:
        giocatoreHelperCpu1(size_t b):giocatoreHelperCpu(b) {}
        virtual ~giocatoreHelperCpu1() {}
        virtual size_t getLivello() {return 2;}
		virtual size_t gioca(const vector<carta *> &mano, carta *c, size_t iCarta);
    protected:

    private:
};

#endif // GIOCATOREHELPERCPU0_H
