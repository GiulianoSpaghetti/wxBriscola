#ifndef GIOCATOREHELPERCPU2_H
#define GIOCATOREHELPERCPU2_H

#include "giocatoreHelperCpu.h"


class giocatoreHelperCpu2 : public giocatoreHelperCpu
{
    public:
        giocatoreHelperCpu2(size_t b):giocatoreHelperCpu(b) {}
        virtual ~giocatoreHelperCpu2() {}
        virtual size_t getLivello() {return 3;}
		virtual size_t gioca(const vector<carta *> &mano, carta *c, size_t iCarta);
    protected:

    private:
};

#endif // GIOCATOREHELPERCPU0_H
